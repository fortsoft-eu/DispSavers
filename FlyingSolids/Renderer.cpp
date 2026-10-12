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
 * Last modified for version 1.0.0.0
 */

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "Renderer.h"
#include "MeshBuilder.h"
#include "Mp4Recorder.h"
#include "resource.h"
#include <algorithm>
#include <array>
#include <cstdint>
#include <d3d11.h>
#include <dxgi1_3.h>
#include <wincodec.h>
#include <wrl/client.h>
#include "FlyingSolidsPS.h"
#include "FlyingSolidsCapsulePS.h"
#include "FlyingSolidsVS.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "windowscodecs.lib")

using Microsoft::WRL::ComPtr;

/// HLSL-compatible four-component value aligned for constant buffers.
struct alignas(16) Float4 {
    float x;
    float y;
    float z;
    float w;
};

/// Per-frame constants shared by vertex and pixel shaders.
struct alignas(16) FrameConstants {
    Float4 screen;
    Float4 cameraPosition;
    Float4 cameraRight;
    Float4 cameraUp;
    Float4 cameraForward;
    Float4 lightDirection;
    Float4 lightSettings;
};

/// Per-instance transforms uploaded once for each rendered frame.
struct alignas(16) ObjectConstants {
    std::array<Float4, MAX_SOLID_INSTANCES> positionAndScale;
    std::array<Float4, MAX_SOLID_INSTANCES> rotationAndKind;
};

/// Parameters that identify one instanced mesh draw call.
struct alignas(16) DrawConstants {
    unsigned kind;
    float zOffset;
    float capsuleRadius;
    float capsuleHalfLength;
};

/// Immutable GPU buffers belonging to one solid kind.
struct GpuMesh {
    ComPtr<ID3D11Buffer> vertices;
    ComPtr<ID3D11Buffer> indices;
    unsigned indexCount = 0;
};

/// Converts simulation vectors to constant-buffer values.
static Float4 ToFloat4(Vec3 value, float w = 0.0f) {
    return Float4{
        value.x,
        value.y,
        value.z,
        w
    };
}

/// Returns the visual scale assigned to a valid solid kind.
static float MeshScale(std::size_t kind) {
    return SOLID_RENDER_SCALES[kind];
}

/// Private Direct3D pipeline and capture state.
struct Renderer::Impl {
    /// Releases the frame-latency wait handle owned by the swap chain.
    ~Impl() {
        if (frameLatencyWaitableObject) {
            CloseHandle(frameLatencyWaitableObject);
        }
    }

    /// Creates the device, swap chain, shaders, buffers, meshes and pipeline states.
    /// Uses a three-buffer flip chain to preserve per-monitor cadence and absorb brief DWM stalls; falls back to
    /// flip presentation without a latency handle and then to the legacy swap model when required by the system.
    bool Initialize(HWND window) {
        RECT client{};
        GetClientRect(window, &client);
        const UINT initialWidth = static_cast<UINT>(std::max(1L, client.right - client.left));
        const UINT initialHeight = static_cast<UINT>(std::max(1L, client.bottom - client.top));
        constexpr D3D_FEATURE_LEVEL levels[]{ D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1,                                             D3D_FEATURE_LEVEL_10_0 };
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
                swapChainFlags = flip.Flags;
                if ((flip.Flags & DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT) != 0) {
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
        const bool vertexShaderFailed = FAILED(device->CreateVertexShader(FlyingSolidsVertexShader,
            sizeof(FlyingSolidsVertexShader), nullptr, &vertexShader));
        const bool shaderCreationFailed = vertexShaderFailed || FAILED(device->CreatePixelShader(FlyingSolidsPixelShader,
            sizeof(FlyingSolidsPixelShader), nullptr, &pixelShader));
        if (shaderCreationFailed) {
            return false;
        }
        const bool capsuleShaderFailed = FAILED(device->CreatePixelShader(FlyingSolidsCapsulePixelShader,
            sizeof(FlyingSolidsCapsulePixelShader), nullptr, &capsulePixelShader));
        if (capsuleShaderFailed) {
            return false;
        }
        const D3D11_INPUT_ELEMENT_DESC elements[]{
            D3D11_INPUT_ELEMENT_DESC{
                "POSITION",
                0,
                DXGI_FORMAT_R32G32B32_FLOAT,
                0,
                0,
                D3D11_INPUT_PER_VERTEX_DATA,
                0
            }, D3D11_INPUT_ELEMENT_DESC{
                "NORMAL",
                0,
                DXGI_FORMAT_R32G32B32_FLOAT,
                0,
                12,
                D3D11_INPUT_PER_VERTEX_DATA,
                0
            }
        };
        if (FAILED(device->CreateInputLayout(elements, static_cast<UINT>(std::size(elements)),
            FlyingSolidsVertexShader,
            sizeof(FlyingSolidsVertexShader), &inputLayout))) {
            return false;
        }
        D3D11_BUFFER_DESC constants{};
        constants.Usage = D3D11_USAGE_DEFAULT;
        constants.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
        constants.ByteWidth = sizeof(FrameConstants);
        if (FAILED(device->CreateBuffer(&constants, nullptr, &frameBuffer))) {
            return false;
        }
        constants.ByteWidth = sizeof(ObjectConstants);
        if (FAILED(device->CreateBuffer(&constants, nullptr, &objectBuffer))) {
            return false;
        }
        constants.ByteWidth = sizeof(DrawConstants);
        if (FAILED(device->CreateBuffer(&constants, nullptr, &drawBuffer))) {
            return false;
        }
        for (std::size_t kind = 0; kind < SOLID_COUNT; kind++) {
            const MeshData data = BuildSolidMesh(static_cast<SolidKind>(kind));
            if (data.vertices.empty() || data.indices.empty()) {
                return false;
            }
            GpuMesh& mesh = meshes[kind];
            D3D11_BUFFER_DESC description{};
            description.Usage = D3D11_USAGE_IMMUTABLE;
            description.BindFlags = D3D11_BIND_VERTEX_BUFFER;
            description.ByteWidth = static_cast<UINT>(data.vertices.size() * sizeof(Vertex));
            D3D11_SUBRESOURCE_DATA initial{};
            initial.pSysMem = data.vertices.data();
            if (FAILED(device->CreateBuffer(&description, &initial, &mesh.vertices))) {
                return false;
            }
            description.BindFlags = D3D11_BIND_INDEX_BUFFER;
            description.ByteWidth = static_cast<UINT>(data.indices.size() * sizeof(unsigned));
            initial.pSysMem = data.indices.data();
            if (FAILED(device->CreateBuffer(&description, &initial, &mesh.indices))) {
                return false;
            }
            mesh.indexCount = static_cast<unsigned>(data.indices.size());
        }
        D3D11_RASTERIZER_DESC rasterizer{};
        rasterizer.FillMode = D3D11_FILL_SOLID;
        rasterizer.CullMode = D3D11_CULL_NONE;
        rasterizer.DepthClipEnable = TRUE;
        rasterizer.MultisampleEnable = FALSE;
        rasterizer.AntialiasedLineEnable = FALSE;
        if (FAILED(device->CreateRasterizerState(&rasterizer, &rasterizerState))) {
            return false;
        }
        rasterizer.CullMode = D3D11_CULL_FRONT;
        if (FAILED(device->CreateRasterizerState(&rasterizer, &capsuleRasterizerState))) {
            return false;
        }
        D3D11_DEPTH_STENCIL_DESC depth{};
        depth.DepthEnable = TRUE;
        depth.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
        depth.DepthFunc = D3D11_COMPARISON_LESS;
        if (FAILED(device->CreateDepthStencilState(&depth, &depthState))) {
            return false;
        }
        return CreateTargets();
    }

    /// Recreates render and depth targets from the current swap-chain back buffer.
    bool CreateTargets() {
        ComPtr<ID3D11Texture2D> depthTexture;
        backBuffer.Reset();
        renderTarget.Reset();
        depthView.Reset();
        if (FAILED(swapChain->GetBuffer(0, IID_PPV_ARGS(&backBuffer)))) {
            return false;
        }
        D3D11_TEXTURE2D_DESC backDescription{};
        backBuffer->GetDesc(&backDescription);
        width = backDescription.Width;
        height = backDescription.Height;
        D3D11_RENDER_TARGET_VIEW_DESC targetDescription{};
        targetDescription.Format = DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
        targetDescription.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
        if (FAILED(device->CreateRenderTargetView(backBuffer.Get(), &targetDescription, &renderTarget))) {
            return false;
        }
        D3D11_TEXTURE2D_DESC depthDescription{};
        depthDescription.Width = width;
        depthDescription.Height = height;
        depthDescription.MipLevels = 1;
        depthDescription.ArraySize = 1;
        depthDescription.Format = DXGI_FORMAT_D32_FLOAT;
        depthDescription.SampleDesc.Count = 1;
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
            recorder.Stop();
        }
        context->OMSetRenderTargets(0, nullptr, nullptr);
        renderTarget.Reset();
        depthView.Reset();
        backBuffer.Reset();
        if (SUCCEEDED(swapChain->ResizeBuffers(0, newWidth, newHeight, DXGI_FORMAT_UNKNOWN, swapChainFlags))) {
            CreateTargets();
        }
    }

    /// Draws one complete scene and optionally presents it while retaining the scene for still-image capture.
    void Draw(const SceneState& scene, bool inspectPixels, unsigned syncInterval, bool presentFrame = true) {
        if (!renderTarget || width == 0 || height == 0) {
            return;
        }
        if (presentFrame) {
            snapshotScene = scene;
            hasSnapshotScene = true;
        }
        constexpr float background[]{
            0.0f,
            0.0f,
            0.0f,
            1.0f
        };
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
        context->OMSetDepthStencilState(depthState.Get(), 0);
        context->IASetInputLayout(inputLayout.Get());
        context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        context->VSSetShader(vertexShader.Get(), nullptr, 0);
        context->PSSetShader(pixelShader.Get(), nullptr, 0);
        const Float4 screen{
            static_cast<float>(width),
            static_cast<float>(height),
            static_cast<float>(width) / static_cast<float>(height),
            0.0f
        };
        const Float4 lightDirection{
            -0.72f,
            0.48f,
            -1.0f,
            0.0f
        };
        const Float4 lightSettings{
            scene.mainLight ? 0.65f : 0.0f,
            scene.fillLight ? 0.35f : 0.0f,
            scene.ambientLight ? 0.12f : 0.0f,
            scene.rimLight ? 0.12f : 0.0f
        };
        const FrameConstants frame{
            screen,
            ToFloat4(scene.camera.position, 1.0f),
            ToFloat4(scene.camera.right),
            ToFloat4(scene.camera.up),
            ToFloat4(scene.camera.forward),
            lightDirection,
            lightSettings
        };
        ObjectConstants objects{};
        const std::size_t instanceCount = std::min(scene.solidCount, MAX_SOLID_INSTANCES);
        for (std::size_t instance = 0; instance < instanceCount; instance++) {
            const std::size_t kind = instance % SOLID_COUNT;
            objects.positionAndScale[instance] =
                ToFloat4(scene.solids[instance].position, MeshScale(kind) * scene.objectScale);
            objects.rotationAndKind[instance] = ToFloat4(scene.solids[instance].rotation, static_cast<float>(kind));
        }
        context->UpdateSubresource(frameBuffer.Get(), 0, nullptr, &frame, 0, 0);
        context->UpdateSubresource(objectBuffer.Get(), 0, nullptr, &objects, 0, 0);
        ID3D11Buffer* frameConstant = frameBuffer.Get();
        ID3D11Buffer* objectConstant = objectBuffer.Get();
        ID3D11Buffer* drawConstant = drawBuffer.Get();
        context->VSSetConstantBuffers(0, 1, &frameConstant);
        context->VSSetConstantBuffers(1, 1, &objectConstant);
        context->VSSetConstantBuffers(2, 1, &drawConstant);
        context->PSSetConstantBuffers(0, 1, &frameConstant);
        context->PSSetConstantBuffers(1, 1, &objectConstant);
        context->PSSetConstantBuffers(2, 1, &drawConstant);
        constexpr UINT stride = sizeof(Vertex);
        constexpr UINT offset = 0;
        const unsigned copiesPerKind = static_cast<unsigned>(instanceCount / SOLID_COUNT);
        for (std::size_t kind = 0; kind < SOLID_COUNT; kind++) {
            if ((scene.enabledSolids & 1U << kind) == 0) {
                continue;
            }
            GpuMesh& mesh = meshes[kind];
            ID3D11Buffer* vertices = mesh.vertices.Get();
            context->IASetVertexBuffers(0, 1, &vertices, &stride, &offset);
            context->IASetIndexBuffer(mesh.indices.Get(), DXGI_FORMAT_R32_UINT, 0);
            const DrawConstants draw{
                static_cast<unsigned>(kind),
                0.0f,
                CAPSULE_RADIUS,
                CAPSULE_HALF_LENGTH
            };
            context->UpdateSubresource(drawBuffer.Get(), 0, nullptr, &draw, 0, 0);
            const bool capsule = kind == static_cast<std::size_t>(SolidKind::Capsule);
            if (capsule) {
                context->PSSetShader(capsulePixelShader.Get(), nullptr, 0);
                context->RSSetState(capsuleRasterizerState.Get());
            }
            context->DrawIndexedInstanced(mesh.indexCount, copiesPerKind, 0, 0, 0);
            if (capsule) {
                context->PSSetShader(pixelShader.Get(), nullptr, 0);
                context->RSSetState(rasterizerState.Get());
            }
        }
        if (presentFrame && recorder.IsRecording() && !recorder.CaptureFrame(context.Get(), backBuffer.Get())) {
            recorder.Stop();
        }
        if (inspectPixels) {
            InspectPixels();
        }
        if (presentFrame) {
            swapChain->Present(syncInterval != 0 ? 1U : 0U, 0);
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
    ComPtr<IDXGISwapChain> swapChain;
    HANDLE frameLatencyWaitableObject = nullptr;
    UINT swapChainFlags = 0;

    /// Size-dependent render targets
    ComPtr<ID3D11Texture2D> backBuffer;
    ComPtr<ID3D11RenderTargetView> renderTarget;
    ComPtr<ID3D11DepthStencilView> depthView;

    /// Shader pipeline and constant buffers
    ComPtr<ID3D11VertexShader> vertexShader;
    ComPtr<ID3D11PixelShader> pixelShader;
    ComPtr<ID3D11PixelShader> capsulePixelShader;
    ComPtr<ID3D11InputLayout> inputLayout;
    ComPtr<ID3D11Buffer> frameBuffer;
    ComPtr<ID3D11Buffer> objectBuffer;
    ComPtr<ID3D11Buffer> drawBuffer;
    ComPtr<ID3D11RasterizerState> rasterizerState;
    ComPtr<ID3D11RasterizerState> capsuleRasterizerState;
    ComPtr<ID3D11DepthStencilState> depthState;

    /// Meshes and capture services
    std::array<GpuMesh, SOLID_COUNT> meshes{};
    Mp4Recorder recorder;

    /// Last complete scene retained for capture without reading a discarded back buffer
    SceneState snapshotScene{};
    bool hasSnapshotScene = false;

    /// Current target size and self-test result
    unsigned width = 0;
    unsigned height = 0;
    unsigned lastVisiblePixels = 0;
};

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

/// Reports availability of swap-chain frame-latency pacing.
bool Renderer::UsesFrameLatencyWait() const {
    return impl->frameLatencyWaitableObject != nullptr;
}

/// Waits on the frame-latency handle when the active swap chain exposes one.
void Renderer::WaitForNextFrame(DWORD timeoutMilliseconds) {
    if (impl->frameLatencyWaitableObject) {
        WaitForSingleObject(impl->frameLatencyWaitableObject, timeoutMilliseconds);
    }
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
bool Renderer::StartRecording(const wchar_t* path, unsigned frameRate) {
    return impl->recorder.Start(impl->device.Get(), path, impl->width, impl->height, frameRate);
}

/// Tests the current GPU target and recording format without changing the active recorder.
bool Renderer::CheckRecordingSupport(unsigned frameRate) const {
    const HRESULT result = Mp4Recorder::CheckSupport(impl->device.Get(), impl->context.Get(), impl->backBuffer.Get(),
        impl->width, impl->height, frameRate);
    return SUCCEEDED(result);
}

/// Finalizes active MP4 capture.
void Renderer::StopRecording() {
    impl->recorder.Stop();
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
