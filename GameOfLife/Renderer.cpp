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
 * Last modified for version 1.3.0.0
 */

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "Renderer.h"
#include "LifeBoard.h"
#include <algorithm>
#include <atomic>
#include <exception>
#include <memory>
#include <thread>
#include <dxgi1_3.h>
#include <avrt.h>
#include <wincodec.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "avrt.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "windowscodecs.lib")

using Microsoft::WRL::ComPtr;

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

/// Private output presentation, pacing and capture state with a shared Life board.
struct Renderer::Impl {
    std::shared_ptr<LifeBoard> board = std::make_shared<LifeBoard>();
    ComPtr<ID3D11DeviceContext> context;
    HANDLE frameLatencyWaitableObject = nullptr;
    ComPtr<IDXGISwapChain> swapChain;
    ComPtr<IDXGIOutput> pacingOutput;
    OutputFramePacer outputPacer;
    ComPtr<ID3D11Texture2D> backBuffer;
    ComPtr<ID3D11RenderTargetView> renderTarget;
    Mp4Recorder recorder;
    UINT swapChainFlags = 0;
    UINT presentFlags = 0;
    bool outputFrameReady = false;
    bool hasSnapshotScene = false;
    RECT worldBounds{ 0, 0, 1, 1 };
    RECT viewBounds{ 0, 0, 1, 1 };
    unsigned width = 0;
    unsigned height = 0;

    /// Stops output pacing before releasing presentation resources.
    ~Impl() {
        outputPacer.Stop();
        if (frameLatencyWaitableObject) {
            CloseHandle(frameLatencyWaitableObject);
        }
    }

    /// Creates this output swap chain and pacing resources while reusing an optional shared GPU world.
    bool Initialize(HWND window, Renderer* sharedWorld) {
        if (sharedWorld) {
            board = sharedWorld->impl->board;
            if (!board->Device()) {
                return false;
            }
        } else if (!board->Initialize()) {
            return false;
        }
        ComPtr<ID3D11Device> device = board->Device();
        device->GetImmediateContext(&context);
        RECT client{};
        GetClientRect(window, &client);
        const UINT initialWidth = static_cast<UINT>(std::max(1L, client.right - client.left));
        const UINT initialHeight = static_cast<UINT>(std::max(1L, client.bottom - client.top));
        HRESULT result = S_OK;
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
            result = factory2->CreateSwapChainForHwnd(device.Get(), window, &flip, nullptr, nullptr,
                &flipChain);
            if (FAILED(result)) {
                flip.Flags = 0;
                result = factory2->CreateSwapChainForHwnd(device.Get(), window, &flip, nullptr, nullptr,
                    &flipChain);
            }
            if (SUCCEEDED(result) && SUCCEEDED(flipChain.As(&swapChain))) {
                flipPresentation = true;
                presentFlags = DXGI_PRESENT_DO_NOT_WAIT;
                swapChainFlags = flip.Flags;
                if (flip.Flags & DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT) {
                    ComPtr<IDXGISwapChain2> swapChain2;
                    if (SUCCEEDED(swapChain.As(&swapChain2))
                            && SUCCEEDED(swapChain2->SetMaximumFrameLatency(2))) {
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
        return CreateTargets();
    }

    /// Obtains the swap-chain back buffer, render target and current output dimensions.
    bool CreateTargets() {
        if (FAILED(swapChain->GetBuffer(0, IID_PPV_ARGS(&backBuffer)))
            || FAILED(board->Device()->CreateRenderTargetView(backBuffer.Get(), nullptr,
                &renderTarget))) {
            return false;
        }
        D3D11_TEXTURE2D_DESC description{};
        backBuffer->GetDesc(&description);
        width = description.Width;
        height = description.Height;
        return true;
    }

    /// Releases output targets, resizes the swap chain and rebuilds targets without replacing the shared
    /// world.
    void Resize(unsigned newWidth, unsigned newHeight) {
        if (!swapChain || newWidth == 0 || newHeight == 0 || newWidth == width && newHeight == height) {
            return;
        }
        if (recorder.IsRecording()) {
            recorder.PrepareStop(context.Get());
        }
        board->UnbindTargets();
        renderTarget.Reset();
        backBuffer.Reset();
        if (SUCCEEDED(swapChain->ResizeBuffers(0, newWidth, newHeight, DXGI_FORMAT_UNKNOWN,
                swapChainFlags))) {
            CreateTargets();
        }
    }

    /// Leaves a busy flip queue without retaining the lock shared by all monitor views of this GPU world.
    /// Each output's unchanged framepacer supplies the refresh clock; legacy presentation uses its timer
    /// path.
    HRESULT Draw(unsigned syncInterval) {
        if (!renderTarget || width == 0 || height == 0) {
            return S_FALSE;
        }
        board->DrawTo(renderTarget.Get(), width, height, worldBounds, viewBounds);
        hasSnapshotScene = true;
        if (recorder.IsRecording()) {
            recorder.CaptureFrame(context.Get(), backBuffer.Get());
        }
        const unsigned interval = presentFlags != 0 && (!outputFrameReady || frameLatencyWaitableObject)
            && syncInterval != 0
            ? 1U
            : 0U;
        outputFrameReady = false;
        const HRESULT result = swapChain->Present(interval, presentFlags);
        return result == DXGI_ERROR_WAS_STILL_DRAWING ? S_FALSE : result;
    }

    /// Redraws the current view and encodes PNG pixels through WIC; a null path tests in-memory encoding.
    bool SaveSnapshot(const wchar_t* path) const {
        ComPtr<ID3D11Device> device = board->Device();
        if (path && !*path
                || !device
                || !context
                || !backBuffer
                || width == 0
                || height == 0
                || !hasSnapshotScene) {
            return false;
        }
        board->DrawTo(renderTarget.Get(), width, height, worldBounds, viewBounds);
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
        HRESULT result = CoCreateInstance(CLSID_WICImagingFactory2, nullptr, CLSCTX_INPROC_SERVER,
            IID_PPV_ARGS(&factory));
        if (result == REGDB_E_CLASSNOTREG) {
            result = CoCreateInstance(CLSID_WICImagingFactory1, nullptr, CLSCTX_INPROC_SERVER,
                IID_PPV_ARGS(&factory));
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

};

/// Creates an uninitialized renderer implementation.
Renderer::Renderer() : impl(new Impl{}) {}

/// Releases all Direct3D and capture resources.
Renderer::~Renderer() {
    delete impl;
}

/// Initializes an output renderer, optionally sharing another renderer's board and device.
bool Renderer::Initialize(HWND window, Renderer* sharedWorld) {
    return impl->Initialize(window, sharedWorld);
}

/// Forwards client-area changes to the private implementation.
void Renderer::Resize(unsigned width, unsigned height) {
    impl->Resize(width, height);
}

/// Replaces the shared GPU board with the supplied CPU cells.
bool Renderer::SetBoard(unsigned columns, unsigned rows, const std::vector<std::uint8_t>& cells) {
    return impl->board->SetBoard(columns, rows, cells);
}

/// Advances the shared GPU simulation and returns its generation or cycle-query status.
HRESULT Renderer::Advance(unsigned generations) {
    return impl->board->Advance(generations);
}

/// Draws and presents this output view using its pacing and recording state.
HRESULT Renderer::Draw(unsigned syncInterval) {
    return impl->Draw(syncInterval);
}

/// Sets the shared-world bounds and the logical rectangle displayed by this output.
void Renderer::SetView(const RECT& worldBounds, const RECT& monitorBounds) {
    impl->worldBounds = worldBounds;
    impl->viewBounds = monitorBounds;
}

/// Updates the shared board cell spacing.
void Renderer::SetCellSize(unsigned size) {
    impl->board->SetCellSize(size);
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

/// Updates live-cell and background colors in the shared board.
void Renderer::SetColors(COLORREF aliveColor, COLORREF backgroundColor) {
    impl->board->SetColors(aliveColor, backgroundColor);
}

/// Updates the shared board grid appearance without reseeding cells.
void Renderer::SetGrid(bool visible, COLORREF color) {
    impl->board->SetGrid(visible, color);
}

/// Enables or disables repeated-phase detection for the shared board.
bool Renderer::SetAutoReset(bool enabled) {
    return impl->board->SetAutoReset(enabled);
}

/// Updates the displayed regions considered by shared-board cycle detection.
bool Renderer::SetVisibleRegions(const RECT& worldBounds, const std::vector<RECT>& regions) {
    return impl->board->SetVisibleRegions(worldBounds, regions);
}

/// Reports whether the shared board has detected a repeated visible phase.
bool Renderer::ResetRequested() const {
    return impl->board->ResetRequested();
}

/// Returns the shared device texture limit for board allocation.
unsigned Renderer::MaximumBoardDimension() const {
    return impl->board->MaximumBoardDimension();
}

/// Copies the shared GPU board into a row-major CPU cell buffer.
bool Renderer::ReadCells(std::vector<std::uint8_t>& cells) const {
    return impl->board->ReadCells(cells);
}

/// Reports whether the shared board runs on a hardware Direct3D device.
bool Renderer::IsHardwareAccelerated() const {
    return impl->board->IsHardwareAccelerated();
}

/// Starts MP4 capture using this output device and current render dimensions.
bool Renderer::StartRecording(const wchar_t* path, unsigned frameRate, const RecordingOptions& options) {
    const RecordingFormat format = options.Format(impl->width, impl->height, frameRate);
    return impl->recorder.Start(impl->board->Device(), path, impl->width, impl->height, format);
}

/// Checks whether the current output dimensions and recording options can be encoded.
bool Renderer::CheckRecordingSupport(unsigned frameRate, const RecordingOptions& options) const {
    const RecordingFormat format = options.Format(impl->width, impl->height, frameRate);
    const HRESULT result = Mp4Recorder::CheckSupport(impl->board->Device(), impl->context.Get(),
        impl->backBuffer.Get(), impl->width, impl->height, format);
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

/// Returns the current render-target width.
unsigned Renderer::Width() const {
    return impl->width;
}

/// Returns the current render-target height.
unsigned Renderer::Height() const {
    return impl->height;
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
