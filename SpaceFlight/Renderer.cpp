/**
 * This is open-source software licensed under the terms of the MIT License.
 *
 * Copyright (c) 2026 Petr Červinka - FortSoft <cervinka@fortsoft.eu>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **
 * Last modified for version 1.2.2.0
 */

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "Renderer.h"
#include "Mp4Recorder.h"
#include "resource.h"
#include <algorithm>
#include <array>
#include <atomic>
#include <exception>
#include <thread>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <d3d11.h>
#include <dxgi1_3.h>
#include <avrt.h>
#include <wincodec.h>
#include <wrl/client.h>
#include "SpaceFlightFunnelVS.h"
#include "SpaceFlightPS.h"
#include "SpaceFlightSurfaceVS.h"
#include "SpaceFlightSurfacePS.h"
#include "SpaceFlightVS.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "avrt.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "windowscodecs.lib")

using Microsoft::WRL::ComPtr;

static constexpr DXGI_FORMAT RENDER_TARGET_FORMAT = DXGI_FORMAT_B8G8R8A8_UNORM;

/// Original frame constants followed by this monitor's independent motion parameters.
struct alignas(16) FrameConstants {
    float width;
    float height;
    float time;
    unsigned surfaceShape;
    MotionParameters motion;
    std::array<float, 4> cameraRotation;
    std::array<float, 4> lightSettings;
    std::array<float, 4> funnelMotion;
    std::array<float, 4> funnelCycle;
    std::array<float, 4> funnelCapture;
    unsigned funnelEntry;
    float surfaceActivation;
    float funnelHeading;
    float funnelAngularCorrection;
    std::array<float, 4> funnelView;
    std::array<float, 4> funnelPath;
};

static_assert(offsetof(FrameConstants, motion) == 16);
static_assert(offsetof(FrameConstants, cameraRotation) == 80);
static_assert(offsetof(FrameConstants, lightSettings) == 96);
static_assert(offsetof(FrameConstants, funnelMotion) == 112);
static_assert(offsetof(FrameConstants, funnelCycle) == 128);
static_assert(offsetof(FrameConstants, funnelCapture) == 144);
static_assert(offsetof(FrameConstants, funnelEntry) == 160);
static_assert(offsetof(FrameConstants, surfaceActivation) == 164);
static_assert(offsetof(FrameConstants, funnelHeading) == 168);
static_assert(offsetof(FrameConstants, funnelAngularCorrection) == 172);
static_assert(offsetof(FrameConstants, funnelView) == 176);
static_assert(offsetof(FrameConstants, funnelPath) == 192);
static_assert(sizeof(FrameConstants) == 208);

/// Shader constants selecting a flight effect and its grid layout.
struct alignas(16) DrawConstants {
    unsigned effect;
    unsigned columns;
    unsigned rows;
    unsigned patches;
};

/// Original filled-grid indices for one flight effect.
struct GpuMesh {
    ComPtr<ID3D11Buffer> indices;
    unsigned indexCount = 0;
};

/// Creates triangle indices for a patch-based surface grid.
static std::vector<unsigned> CreateSurfaceIndices(const SurfaceMesh& mesh);

/// Keeps one pending physical refresh independently of rendering and blocking Present calls.
/// Auto-reset notification coalesces old ticks instead of accumulating a catch-up frame queue.
struct OutputFramePacer {
    /// Stops the output-clock worker and releases its synchronization resources.
    ~OutputFramePacer() {
        Stop();
    }

    /// Starts one clock worker for this exact output; unsupported clocks retain the caller's timer path.
    bool Start(IDXGIOutput* value) {
        Stop();
        if (!value) {
            return false;
        }
        readyEvent = CreateEventW(nullptr, FALSE, FALSE, nullptr);
        if (!readyEvent) {
            return false;
        }
        output = value;
        result.store(S_OK, std::memory_order_release);
        stopping.store(false, std::memory_order_release);
        try {
            worker = std::thread(&OutputFramePacer::Run, this);
        } catch (const std::exception&) {
            Stop();
            return false;
        }
        return true;
    }

    /// Reports initialization, including a failed worker whose error must still reach its consumer.
    bool Started() const {
        return readyEvent != nullptr;
    }

    /// Wakes a waiting render worker and lets the native output wait finish without closing live handles.
    void RequestStop(HRESULT reason = E_ABORT) {
        result.store(reason, std::memory_order_release);
        stopping.store(true, std::memory_order_release);
        if (readyEvent) {
            SetEvent(readyEvent);
        }
    }

    /// Joins before releasing the output or notification handle. Repeated cleanup is harmless.
    void Stop() {
        if (!readyEvent && !worker.joinable()) {
            return;
        }
        RequestStop();
        if (worker.joinable()) {
            worker.join();
        }
        if (readyEvent) {
            CloseHandle(readyEvent);
            readyEvent = nullptr;
        }
        output.Reset();
    }

    /// Consumes the latest refresh, coalescing delayed notifications instead of waiting another full period.
    HRESULT Wait(DWORD timeoutMilliseconds, HANDLE frameReady = nullptr) {
        HRESULT status = result.load(std::memory_order_acquire);
        if (FAILED(status)) {
            return status;
        }
        if (!readyEvent) {
            return E_FAIL;
        }
        const HANDLE handles[]{ readyEvent, frameReady };
        const DWORD waited = WaitForMultipleObjects(frameReady ? 2 : 1, handles, TRUE, timeoutMilliseconds);
        status = result.load(std::memory_order_acquire);
        if (FAILED(status)) {
            return status;
        }
        if (waited != WAIT_OBJECT_0) {
            status = waited == WAIT_TIMEOUT ? DXGI_ERROR_WAIT_TIMEOUT : HRESULT_FROM_WIN32(GetLastError());
            if (SUCCEEDED(status)) {
                status = E_FAIL;
            }
            RequestStop(status);
            return status;
        }
        status = result.load(std::memory_order_acquire);
        if (FAILED(status)) {
            return status;
        }
        return stopping.load(std::memory_order_acquire) ? E_ABORT : S_OK;
    }

    /// Samples native refresh continuously, without accessing the immediate context or presenting frames.
    void Run() {
        SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_ABOVE_NORMAL);
        DWORD multimediaTaskIndex = 0;
        HANDLE multimediaTask = AvSetMmThreadCharacteristicsW(L"Games", &multimediaTaskIndex);
        if (multimediaTask) {
            AvSetMmThreadPriority(multimediaTask, AVRT_PRIORITY_HIGH);
        }
        while (!stopping.load(std::memory_order_acquire)) {
            const HRESULT status = output->WaitForVBlank();
            if (FAILED(status)) {
                RequestStop(status);
                break;
            }
            if (!stopping.load(std::memory_order_acquire)) {
                SetEvent(readyEvent);
            }
        }
        if (multimediaTask) {
            AvRevertMmThreadCharacteristics(multimediaTask);
        }
    }

    ComPtr<IDXGIOutput> output;
    HANDLE readyEvent = nullptr;
    std::thread worker;
    std::atomic_bool stopping{ true };
    std::atomic<HRESULT> result{ E_ABORT };
};

/// Private Direct3D pipeline and capture state.
struct Renderer::Impl {
    /// Stops output pacing before releasing presentation resources.
    ~Impl() {
        outputPacer.Stop();
        if (frameLatencyWaitableObject) {
            CloseHandle(frameLatencyWaitableObject);
        }
    }

    /// Creates the device, swap chain, shaders, buffers, meshes and pipeline states.
    /// Clocks flip presentation only from this window's output; other swap models retain their timed path.
    bool Initialize(HWND window) {
        RECT client{};
        GetClientRect(window, &client);
        const UINT initialWidth = static_cast<UINT>(std::max(1L, client.right - client.left));
        const UINT initialHeight = static_cast<UINT>(std::max(1L, client.bottom - client.top));
        constexpr D3D_FEATURE_LEVEL levels[]{ D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_10_0 };
        D3D_FEATURE_LEVEL created{};
        HRESULT result = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, D3D11_CREATE_DEVICE_BGRA_SUPPORT,
            levels, static_cast<UINT>(std::size(levels)), D3D11_SDK_VERSION, &device, &created, &context);
        if (FAILED(result)) {
            device.Reset();
            context.Reset();
            result = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_WARP, nullptr, D3D11_CREATE_DEVICE_BGRA_SUPPORT, levels,
                static_cast<UINT>(std::size(levels)), D3D11_SDK_VERSION, &device, &created, &context);
        }
        if (FAILED(result)) {
            return false;
        }
        ComPtr<IDXGIDevice> dxgiDevice;
        ComPtr<IDXGIAdapter> adapter;
        ComPtr<IDXGIFactory> factory;
        if (FAILED(device.As(&dxgiDevice))
                || FAILED(dxgiDevice->GetAdapter(&adapter))
                || FAILED(adapter->GetParent(IID_PPV_ARGS(&factory)))) {
            return false;
        }
        bool flipPresentation = false;
        ComPtr<IDXGIFactory2> factory2;
        if (SUCCEEDED(factory.As(&factory2))) {
            DXGI_SWAP_CHAIN_DESC1 flip{};
            flip.Width = initialWidth;
            flip.Height = initialHeight;
            flip.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
            flip.SampleDesc.Count = 1;
            flip.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
            flip.BufferCount = 3;
            flip.Scaling = DXGI_SCALING_STRETCH;
            flip.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
            flip.AlphaMode = DXGI_ALPHA_MODE_IGNORE;
            flip.Flags = DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT;
            ComPtr<IDXGISwapChain1> flipChain;
            result = factory2->CreateSwapChainForHwnd(device.Get(), window, &flip, nullptr, nullptr, &flipChain);
            if (FAILED(result)) {
                flip.Flags = 0;
                result = factory2->CreateSwapChainForHwnd(device.Get(), window, &flip, nullptr, nullptr, &flipChain);
            }
            if (SUCCEEDED(result) && SUCCEEDED(flipChain.As(&swapChain))) {
                flipPresentation = true;
                swapChainFlags = flip.Flags;
                if (flip.Flags & DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT) {
                    ComPtr<IDXGISwapChain2> swapChain2;
                    if (SUCCEEDED(swapChain.As(&swapChain2)) && SUCCEEDED(swapChain2->SetMaximumFrameLatency(2))) {
                        frameLatencyWaitableObject = swapChain2->GetFrameLatencyWaitableObject();
                    }
                }
            }
        }
        if (!swapChain) {
            DXGI_SWAP_CHAIN_DESC legacy{};
            legacy.BufferDesc.Width = initialWidth;
            legacy.BufferDesc.Height = initialHeight;
            legacy.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
            legacy.SampleDesc.Count = 1;
            legacy.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
            legacy.BufferCount = 2;
            legacy.OutputWindow = window;
            legacy.Windowed = TRUE;
            legacy.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
            if (FAILED(factory->CreateSwapChain(device.Get(), &legacy, &swapChain))) {
                return false;
            }
        }
        factory->MakeWindowAssociation(window, DXGI_MWA_NO_ALT_ENTER);
        ComPtr<IDXGIDevice1> latencyDevice;
        if (!frameLatencyWaitableObject && SUCCEEDED(device.As(&latencyDevice))) {
            latencyDevice->SetMaximumFrameLatency(2);
        }
        if (flipPresentation) {
            ComPtr<IDXGIOutput> output;
            DXGI_OUTPUT_DESC description{};
            if (SUCCEEDED(swapChain->GetContainingOutput(&output))
                    && output
                    && SUCCEEDED(output->GetDesc(&description))
                    && description.AttachedToDesktop
                    && description.Monitor == MonitorFromWindow(window, MONITOR_DEFAULTTONEAREST)) {
                pacingOutput = output;
            }
        }
        const bool shaderCreationFailed =
            FAILED(device->CreateVertexShader(SpaceFlightVertexShader,
                sizeof(SpaceFlightVertexShader), nullptr, &vertexShader))
            || FAILED(device->CreatePixelShader(SpaceFlightPixelShader,
                sizeof(SpaceFlightPixelShader), nullptr, &pixelShader))
            || FAILED(device->CreateVertexShader(SpaceFlightFunnelVertexShader,
                sizeof(SpaceFlightFunnelVertexShader), nullptr, &funnelVertexShader));
        if (shaderCreationFailed) {
            return false;
        }
        const bool surfaceShaderCreationFailed =
            FAILED(device->CreateVertexShader(SpaceFlightSurfaceVertexShader,
                sizeof(SpaceFlightSurfaceVertexShader), nullptr, &surfaceVertexShader))
            || FAILED(device->CreatePixelShader(SpaceFlightSurfacePixelShader,
                sizeof(SpaceFlightSurfacePixelShader), nullptr, &surfacePixelShader));
        if (surfaceShaderCreationFailed) {
            return false;
        }
        D3D11_BUFFER_DESC constants{};
        constants.Usage = D3D11_USAGE_DEFAULT;
        constants.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
        constants.ByteWidth = sizeof(FrameConstants);
        if (FAILED(device->CreateBuffer(&constants, nullptr, &frameBuffer))) {
            return false;
        }
        constants.ByteWidth = sizeof(DrawConstants);
        if (FAILED(device->CreateBuffer(&constants, nullptr, &drawBuffer))) {
            return false;
        }
        for (std::size_t kind = 0; kind < EFFECT_COUNT; kind++) {
            const std::vector<unsigned> indices = CreateSurfaceIndices(SURFACE_MESHES[kind]);
            if (indices.empty()) {
                continue;
            }
            GpuMesh& mesh = meshes[kind];
            D3D11_BUFFER_DESC description{};
            description.Usage = D3D11_USAGE_IMMUTABLE;
            description.BindFlags = D3D11_BIND_INDEX_BUFFER;
            description.ByteWidth = static_cast<UINT>(indices.size() * sizeof(unsigned));
            D3D11_SUBRESOURCE_DATA initial{};
            initial.pSysMem = indices.data();
            if (FAILED(device->CreateBuffer(&description, &initial, &mesh.indices))) {
                return false;
            }
            mesh.indexCount = static_cast<unsigned>(indices.size());
        }
        D3D11_RASTERIZER_DESC rasterizer{};
        rasterizer.FillMode = D3D11_FILL_SOLID;
        rasterizer.CullMode = D3D11_CULL_NONE;
        rasterizer.DepthClipEnable = TRUE;
        rasterizer.MultisampleEnable = TRUE;
        rasterizer.AntialiasedLineEnable = FALSE;
        if (FAILED(device->CreateRasterizerState(&rasterizer, &rasterizerState))) {
            return false;
        }
        D3D11_DEPTH_STENCIL_DESC depth{};
        depth.DepthEnable = TRUE;
        depth.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
        depth.DepthFunc = D3D11_COMPARISON_LESS;
        if (FAILED(device->CreateDepthStencilState(&depth, &depthState))) {
            return false;
        }
        UINT colorQuality = 0;
        UINT depthQuality = 0;
        if (SUCCEEDED(device->CheckMultisampleQualityLevels(DXGI_FORMAT_B8G8R8A8_UNORM, 4, &colorQuality))
                && SUCCEEDED(device->CheckMultisampleQualityLevels(DXGI_FORMAT_D32_FLOAT, 4, &depthQuality))
                && colorQuality != 0
                && depthQuality != 0) {
            renderSamples = 4;
        }
        return CreateTargets();
    }

    /// Recreates the shared offscreen color and depth targets at the native back-buffer size.
    bool CreateTargets() {
        ComPtr<ID3D11Texture2D> depthTexture;
        backBuffer.Reset();
        sceneColor.Reset();
        renderTarget.Reset();
        depthView.Reset();
        if (FAILED(swapChain->GetBuffer(0, IID_PPV_ARGS(&backBuffer)))) {
            return false;
        }
        D3D11_TEXTURE2D_DESC colorDescription{};
        backBuffer->GetDesc(&colorDescription);
        width = colorDescription.Width;
        height = colorDescription.Height;
        colorDescription.Format = DXGI_FORMAT_B8G8R8A8_TYPELESS;
        colorDescription.SampleDesc.Count = renderSamples;
        colorDescription.SampleDesc.Quality = 0;
        colorDescription.BindFlags = D3D11_BIND_RENDER_TARGET;
        colorDescription.MiscFlags = 0;
        D3D11_RENDER_TARGET_VIEW_DESC targetDescription{};
        targetDescription.Format = RENDER_TARGET_FORMAT;
        targetDescription.ViewDimension = renderSamples > 1
            ? D3D11_RTV_DIMENSION_TEXTURE2DMS : D3D11_RTV_DIMENSION_TEXTURE2D;
        if (FAILED(device->CreateTexture2D(&colorDescription, nullptr, &sceneColor))
                || FAILED(device->CreateRenderTargetView(sceneColor.Get(), &targetDescription, &renderTarget))) {
            return false;
        }
        D3D11_TEXTURE2D_DESC depthDescription{};
        depthDescription.Width = width;
        depthDescription.Height = height;
        depthDescription.MipLevels = 1;
        depthDescription.ArraySize = 1;
        depthDescription.Format = DXGI_FORMAT_D32_FLOAT;
        depthDescription.SampleDesc.Count = renderSamples;
        depthDescription.BindFlags = D3D11_BIND_DEPTH_STENCIL;
        return SUCCEEDED(device->CreateTexture2D(&depthDescription, nullptr, &depthTexture))
            && SUCCEEDED(device->CreateDepthStencilView(depthTexture.Get(), nullptr, &depthView));
    }

    /// Reallocates size-dependent resources after a nonzero client-area change.
    void Resize(unsigned newWidth, unsigned newHeight) {
        if (!swapChain || newWidth == 0 || newHeight == 0 || newWidth == width && newHeight == height) {
            return;
        }
        if (recorder.IsRecording()) {
            recorder.Stop(context.Get());
        }
        context->OMSetRenderTargets(0, nullptr, nullptr);
        renderTarget.Reset();
        sceneColor.Reset();
        depthView.Reset();
        backBuffer.Reset();
        if (SUCCEEDED(swapChain->ResizeBuffers(0, newWidth, newHeight, DXGI_FORMAT_UNKNOWN, swapChainFlags))) {
            CreateTargets();
        }
    }

    /// Completes every frame through the same offscreen-to-presentation path, independent of scene or draw mode.
    void CompleteFrame() const {
        context->OMSetRenderTargets(0, nullptr, nullptr);
        if (renderSamples > 1) {
            context->ResolveSubresource(backBuffer.Get(), 0, sceneColor.Get(), 0, DXGI_FORMAT_B8G8R8A8_UNORM);
        } else {
            context->CopyResource(backBuffer.Get(), sceneColor.Get());
        }
    }

    /// Draws and retains a scene for capture; presents clock-paced frames without a second wait or tearing.
    void Draw(const SceneState& scene, bool inspectPixels, unsigned syncInterval, bool presentFrame = true) {
        if (!renderTarget || width == 0 || height == 0) {
            return;
        }
        if (presentFrame) {
            snapshotScene = scene;
            hasSnapshotScene = true;
        }
        constexpr float background[]{ 0.0f, 0.0f, 0.0f, 1.0f };
        context->ClearRenderTargetView(renderTarget.Get(), background);
        context->ClearDepthStencilView(depthView.Get(), D3D11_CLEAR_DEPTH, 1.0f, 0);
        ID3D11RenderTargetView* target = renderTarget.Get();
        context->OMSetRenderTargets(1, &target, depthView.Get());
        D3D11_VIEWPORT viewport{};
        viewport.Width = static_cast<float>(width);
        viewport.Height = static_cast<float>(height);
        viewport.MaxDepth = 1.0f;
        context->RSSetViewports(1, &viewport);
        context->RSSetState(rasterizerState.Get());
        context->IASetInputLayout(nullptr);
        const std::array<float, 4> lightSettings{
            scene.mainLight ? 1.0f : 0.0f,
            scene.fillLight ? 0.35f : 0.0f,
            scene.ambientLight ? 0.12f : 0.0f,
            scene.rimLight ? 0.12f : 0.0f
        };
        const FrameConstants frame{
            static_cast<float>(width),
            static_cast<float>(height),
            scene.animationTime,
            static_cast<unsigned>(scene.surfaceShape),
            scene.motion,
            scene.cameraRotation,
            lightSettings,
            scene.funnelMotion,
            scene.funnelCycle,
            scene.funnelCapture,
            scene.funnelEntry ? 1U : 0U,
            scene.surfaceActivation,
            scene.funnelHeading,
            scene.funnelAngularCorrection,
            scene.funnelView,
            scene.funnelPath
        };
        context->UpdateSubresource(frameBuffer.Get(), 0, nullptr, &frame, 0, 0);
        ID3D11Buffer* frameConstant = frameBuffer.Get();
        ID3D11Buffer* drawConstant = drawBuffer.Get();
        context->VSSetConstantBuffers(0, 1, &frameConstant);
        context->VSSetConstantBuffers(1, 1, &drawConstant);
        context->PSSetConstantBuffers(0, 1, &frameConstant);
        context->PSSetConstantBuffers(1, 1, &drawConstant);
        for (std::size_t kind = 0; kind < EFFECT_COUNT; kind++) {
            if ((scene.enabledEffects & 1U << kind) == 0) {
                continue;
            }
            const SurfaceMesh& mesh = SURFACE_MESHES[kind];
            const bool filled =
                mesh.patches != 0 && (kind == 0 ? scene.infiniteSurfaceFilled : scene.morphingSurfaceFilled);
            const DrawConstants draw{ 19U + static_cast<unsigned>(kind), mesh.columns, mesh.rows, mesh.patches };
            context->UpdateSubresource(drawBuffer.Get(), 0, nullptr, &draw, 0, 0);
            context->VSSetShader(filled ? surfaceVertexShader.Get() : vertexShader.Get(), nullptr, 0);
            context->PSSetShader(filled ? surfacePixelShader.Get() : pixelShader.Get(), nullptr, 0);
            context->IASetPrimitiveTopology(filled
                ? D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST
                : D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
            context->OMSetDepthStencilState(filled ? depthState.Get() : nullptr, 0);
            if (filled) {
                context->IASetIndexBuffer(meshes[kind].indices.Get(), DXGI_FORMAT_R32_UINT, 0);
                context->DrawIndexedInstanced(meshes[kind].indexCount, 1, 0, 0, 0);
            } else {
                context->IASetIndexBuffer(nullptr, DXGI_FORMAT_R32_UINT, 0);
                context->DrawInstanced(SEGMENT_COUNTS[kind] * 2, 1, 0, 0);
            }
            if (mesh.patches != 0 && scene.surfaceShape == SurfaceShape::Funnel) {
                context->VSSetShader(funnelVertexShader.Get(), nullptr, 0);
                context->PSSetShader(pixelShader.Get(), nullptr, 0);
                context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
                context->OMSetDepthStencilState(filled ? depthState.Get() : nullptr, 0);
                context->IASetIndexBuffer(nullptr, DXGI_FORMAT_R32_UINT, 0);
                const unsigned circleCount = FUNNEL_CIRCLE_COUNT + (filled ? 0U : FUNNEL_BODY_CIRCLE_COUNTS[kind]);
                context->DrawInstanced(circleCount * FUNNEL_CIRCLE_SEGMENTS * 2, 1, 0, 0);
            }
        }
        CompleteFrame();
        if (presentFrame && recorder.IsRecording()) {
            recorder.CaptureFrame(context.Get(), backBuffer.Get());
        }
        if (inspectPixels) {
            InspectPixels();
        }
        if (presentFrame) {
            const unsigned interval = (!outputFrameReady || frameLatencyWaitableObject) && syncInterval != 0 ? 1U : 0U;
            outputFrameReady = false;
            swapChain->Present(interval, 0);
        }
    }

    /// Counts nonblack pixels for automated renderer self-tests.
    void InspectPixels() {
        lastVisiblePixels = 0;
        D3D11_TEXTURE2D_DESC description{};
        backBuffer->GetDesc(&description);
        description.BindFlags = 0;
        description.MiscFlags = 0;
        description.Usage = D3D11_USAGE_STAGING;
        description.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
        ComPtr<ID3D11Texture2D> staging;
        if (FAILED(device->CreateTexture2D(&description, nullptr, &staging))) {
            return;
        }
        context->CopyResource(staging.Get(), backBuffer.Get());
        D3D11_MAPPED_SUBRESOURCE mapped{};
        if (FAILED(context->Map(staging.Get(), 0, D3D11_MAP_READ, 0, &mapped))) {
            return;
        }
        for (unsigned y = 0; y < height; y++) {
            const std::uint8_t* row = static_cast<const std::uint8_t*>(mapped.pData) + y * mapped.RowPitch;
            for (unsigned x = 0; x < width; x++) {
                const std::uint8_t* pixel = row + x * 4;
                if (static_cast<unsigned>(pixel[0]) + pixel[1] + pixel[2] > 32U) {
                    ++lastVisiblePixels;
                }
            }
        }
        context->Unmap(staging.Get(), 0);
    }

    /// Encodes the last scene as a PNG without presentation, using memory when no output path is supplied.
    bool SaveSnapshot(const wchar_t* path) {
        if (path && !*path || !device || !context || !backBuffer || width == 0 || height == 0 || !hasSnapshotScene) {
            return false;
        }
        Draw(snapshotScene, false, 0, false);
        D3D11_TEXTURE2D_DESC description{};
        backBuffer->GetDesc(&description);
        description.BindFlags = 0;
        description.MiscFlags = 0;
        description.Usage = D3D11_USAGE_STAGING;
        description.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
        ComPtr<ID3D11Texture2D> staging;
        if (FAILED(device->CreateTexture2D(&description, nullptr, &staging))) {
            return false;
        }
        context->CopyResource(staging.Get(), backBuffer.Get());
        D3D11_MAPPED_SUBRESOURCE mapped{};
        if (FAILED(context->Map(staging.Get(), 0, D3D11_MAP_READ, 0, &mapped))) {
            return false;
        }
        const HRESULT comResult = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
        if (FAILED(comResult) && comResult != RPC_E_CHANGED_MODE) {
            context->Unmap(staging.Get(), 0);
            return false;
        }
        ComPtr<IWICImagingFactory> factory;
        ComPtr<IWICStream> stream;
        ComPtr<IWICBitmapEncoder> encoder;
        ComPtr<IWICBitmapFrameEncode> frame;
        ComPtr<IPropertyBag2> properties;
        ComPtr<IStream> memory;
        HRESULT result = CoCreateInstance(CLSID_WICImagingFactory2, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory));
        if (result == REGDB_E_CLASSNOTREG) {
            result = CoCreateInstance(CLSID_WICImagingFactory1, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory));
        }
        if (SUCCEEDED(result)) {
            result = factory->CreateStream(&stream);
        }
        if (SUCCEEDED(result)) {
            if (path) {
                result = stream->InitializeFromFilename(path, GENERIC_WRITE);
            } else {
                result = CreateStreamOnHGlobal(nullptr, TRUE, &memory);
                if (SUCCEEDED(result)) {
                    result = stream->InitializeFromIStream(memory.Get());
                }
            }
        }
        if (SUCCEEDED(result)) {
            result = factory->CreateEncoder(GUID_ContainerFormatPng, nullptr, &encoder);
        }
        if (SUCCEEDED(result)) {
            result = encoder->Initialize(stream.Get(), WICBitmapEncoderNoCache);
        }
        if (SUCCEEDED(result)) {
            result = encoder->CreateNewFrame(&frame, &properties);
        }
        if (SUCCEEDED(result)) {
            result = frame->Initialize(properties.Get());
        }
        if (SUCCEEDED(result)) {
            result = frame->SetSize(width, height);
        }
        WICPixelFormatGUID format = GUID_WICPixelFormat32bppBGRA;
        if (SUCCEEDED(result)) {
            result = frame->SetPixelFormat(&format);
        }
        if (SUCCEEDED(result) && format != GUID_WICPixelFormat32bppBGRA) {
            result = WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT;
        }
        if (SUCCEEDED(result)) {
            result = frame->WritePixels(height, mapped.RowPitch, mapped.RowPitch * height,
                static_cast<BYTE*>(mapped.pData));
        }
        if (SUCCEEDED(result)) {
            result = frame->Commit();
        }
        if (SUCCEEDED(result)) {
            result = encoder->Commit();
        }
        context->Unmap(staging.Get(), 0);
        properties.Reset();
        frame.Reset();
        encoder.Reset();
        stream.Reset();
        memory.Reset();
        factory.Reset();
        if (SUCCEEDED(comResult)) {
            CoUninitialize();
        }
        if (FAILED(result) && path) {
            DeleteFileW(path);
        }
        return SUCCEEDED(result);
    }

    /// Device and presentation resources
    ComPtr<ID3D11Device> device;
    ComPtr<ID3D11DeviceContext> context;
    HANDLE frameLatencyWaitableObject = nullptr;
    ComPtr<IDXGISwapChain> swapChain;
    ComPtr<IDXGIOutput> pacingOutput;
    OutputFramePacer outputPacer;
    UINT swapChainFlags = 0;
    bool outputFrameReady = false;

    /// Size-dependent render targets
    ComPtr<ID3D11Texture2D> backBuffer;
    ComPtr<ID3D11Texture2D> sceneColor;
    ComPtr<ID3D11RenderTargetView> renderTarget;
    ComPtr<ID3D11DepthStencilView> depthView;
    UINT renderSamples = 1;

    /// Shader pipeline and constant buffers
    ComPtr<ID3D11VertexShader> vertexShader;
    ComPtr<ID3D11VertexShader> funnelVertexShader;
    ComPtr<ID3D11PixelShader> pixelShader;
    ComPtr<ID3D11VertexShader> surfaceVertexShader;
    ComPtr<ID3D11PixelShader> surfacePixelShader;
    ComPtr<ID3D11Buffer> frameBuffer;
    ComPtr<ID3D11Buffer> drawBuffer;
    ComPtr<ID3D11RasterizerState> rasterizerState;
    ComPtr<ID3D11DepthStencilState> depthState;

    /// Meshes and capture services
    std::array<GpuMesh, EFFECT_COUNT> meshes{};
    Mp4Recorder recorder;

    /// Last complete scene retained for capture without reading a discarded back buffer
    SceneState snapshotScene{};
    bool hasSnapshotScene = false;

    /// Current target size and self-test result
    unsigned width = 0;
    unsigned height = 0;
    unsigned lastVisiblePixels = 0;
};

/// Creates triangle indices for a patch-based surface grid.
static std::vector<unsigned> CreateSurfaceIndices(const SurfaceMesh& mesh) {
    std::vector<unsigned> indices;
    indices.reserve(static_cast<std::size_t>(mesh.columns) * mesh.rows * mesh.patches * 6);
    const unsigned stride = mesh.columns + 1;
    const unsigned verticesPerPatch = stride * (mesh.rows + 1);
    for (unsigned patch = 0; patch < mesh.patches; patch++) {
        for (unsigned row = 0; row < mesh.rows; row++) {
            for (unsigned column = 0; column < mesh.columns; column++) {
                const unsigned first = patch * verticesPerPatch + row * stride + column;
                indices.push_back(first);
                indices.push_back(first + 1);
                indices.push_back(first + stride);
                indices.push_back(first + stride);
                indices.push_back(first + 1);
                indices.push_back(first + stride + 1);
            }
        }
    }
    return indices;
}

/// Creates an uninitialized renderer implementation.
Renderer::Renderer() : impl(new Impl{}) {}

/// Releases all Direct3D and capture resources.
Renderer::~Renderer() {
    delete impl;
}

/// Initializes the private rendering implementation.
bool Renderer::Initialize(HWND window) {
    return impl->Initialize(window);
}

/// Forwards client-area changes to the private implementation.
void Renderer::Resize(unsigned width, unsigned height) {
    impl->Resize(width, height);
}

/// Reports availability of the actual output's vertical-blank clock.
bool Renderer::UsesVerticalBlankWait() const {
    return impl->pacingOutput != nullptr || impl->frameLatencyWaitableObject != nullptr;
}

/// Consumes the latest output refresh, including one that occurred while Present was blocking.
HRESULT Renderer::WaitForNextFrame() {
    impl->outputFrameReady = false;
    HRESULT result = S_OK;
    if (impl->pacingOutput) {
        if (!impl->outputPacer.Started() && !impl->outputPacer.Start(impl->pacingOutput.Get())) {
            result = E_FAIL;
        } else {
            result = impl->outputPacer.Wait(50, impl->frameLatencyWaitableObject);
        }
    } else if (impl->frameLatencyWaitableObject) {
        const DWORD waited = WaitForSingleObject(impl->frameLatencyWaitableObject, 50);
        if (waited != WAIT_OBJECT_0) {
            result = waited == WAIT_TIMEOUT ? DXGI_ERROR_WAIT_TIMEOUT : HRESULT_FROM_WIN32(GetLastError());
            if (SUCCEEDED(result)) {
                result = E_FAIL;
            }
        }
    }
    impl->outputFrameReady = SUCCEEDED(result) && impl->pacingOutput != nullptr;
    if (FAILED(result)) {
        impl->pacingOutput.Reset();
        impl->outputPacer.RequestStop(result);
    }
    return result;
}

/// Renders and presents one scene snapshot.
void Renderer::Draw(const SceneState& scene, bool inspectPixels, unsigned syncInterval) {
    impl->Draw(scene, inspectPixels, syncInterval);
}

/// Returns the last diagnostic visible-pixel count.
unsigned Renderer::LastVisiblePixelCount() const {
    return impl->lastVisiblePixels;
}

/// Starts MP4 capture of the current render target.
bool Renderer::StartRecording(const wchar_t* path, unsigned frameRate, const RecordingOptions& options) {
    const RecordingFormat format = options.Format(impl->width, impl->height, frameRate);
    return impl->recorder.Start(impl->device.Get(), path, impl->width, impl->height, format);
}

/// Tests the current GPU target and recording format without changing the active recorder.
bool Renderer::CheckRecordingSupport(unsigned frameRate, const RecordingOptions& options) const {
    const RecordingFormat format = options.Format(impl->width, impl->height, frameRate);
    const HRESULT result = Mp4Recorder::CheckSupport(impl->device.Get(), impl->context.Get(), impl->backBuffer.Get(),
        impl->width, impl->height, format);
    return SUCCEEDED(result);
}

/// Finalizes active MP4 capture.
void Renderer::StopRecording() {
    impl->recorder.Stop(impl->context.Get());
}

/// Drains capture resources before releasing the rendering lock, without waiting for the encoder worker.
void Renderer::PrepareRecordingStop() {
    impl->recorder.PrepareStop(impl->context.Get());
}

/// Joins the recording worker after capture is disabled, allowing animation to continue during finalization.
void Renderer::FinishRecordingStop() {
    impl->recorder.FinishStop();
}

/// Reports whether the renderer currently records frames.
bool Renderer::IsRecording() const {
    return impl->recorder.IsRecording();
}

/// Returns the recorder's most recent HRESULT.
HRESULT Renderer::RecordingError() const {
    return impl->recorder.LastError();
}

/// Saves the current back buffer as a PNG image.
bool Renderer::SaveSnapshot(const wchar_t* path) const {
    if (!path || !*path) {
        return false;
    }
    return impl->SaveSnapshot(path);
}

/// Tests the complete PNG capture pipeline with the current scene and an in-memory stream.
bool Renderer::CheckSnapshotSupport() const {
    return impl->SaveSnapshot(nullptr);
}

/// Returns the current render-target width.
unsigned Renderer::Width() const {
    return impl->width;
}

/// Returns the current render-target height.
unsigned Renderer::Height() const {
    return impl->height;
}
