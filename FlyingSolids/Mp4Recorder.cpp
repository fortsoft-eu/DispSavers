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
#include "Mp4Recorder.h"
#include <d3d11.h>
#include <mfapi.h>
#include <mferror.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <wrl/client.h>
#include <algorithm>
#include <atomic>
#include <cstdint>
#include <cstring>
#include <string>

#pragma comment(lib, "mfplat.lib")
#pragma comment(lib, "mfreadwrite.lib")
#pragma comment(lib, "mfuuid.lib")

using Microsoft::WRL::ComPtr;
using CopyImageFunction = HRESULT(WINAPI*)(BYTE*, LONG, const BYTE*, LONG, DWORD, DWORD);

/// Media Foundation time-base constant
constexpr LONGLONG MEDIA_FOUNDATION_UNITS_PER_SECOND = 10000000;

/// Windows libraries providing image copying on current and older systems
constexpr wchar_t MEDIA_FOUNDATION_LIBRARY[] = L"mfplat.dll";
constexpr wchar_t VIDEO_RENDERER_LIBRARY[] = L"evr.dll";
constexpr char COPY_IMAGE_FUNCTION[] = "MFCopyImage";

/// Resolves image copying from Media Foundation, or from the system EVR library used before Windows 7.
/// Retains a successfully loaded EVR module for the lifetime of the cached function pointer.
static CopyImageFunction ResolveCopyImageFunction() {
    const HMODULE mediaFoundation = GetModuleHandleW(MEDIA_FOUNDATION_LIBRARY);
    if (mediaFoundation) {
        const CopyImageFunction copyImage = reinterpret_cast<CopyImageFunction>(
            GetProcAddress(mediaFoundation, COPY_IMAGE_FUNCTION));
        if (copyImage) {
            return copyImage;
        }
    }
    wchar_t systemDirectory[MAX_PATH]{};
    const UINT length = GetSystemDirectoryW(systemDirectory, MAX_PATH);
    if (length == 0 || length >= static_cast<UINT>(MAX_PATH)) {
        return nullptr;
    }
    std::wstring libraryPath(systemDirectory, length);
    libraryPath += L"\\";
    libraryPath += VIDEO_RENDERER_LIBRARY;
    const HMODULE videoRenderer = LoadLibraryW(libraryPath.c_str());
    if (!videoRenderer) {
        return nullptr;
    }
    const CopyImageFunction copyImage = reinterpret_cast<CopyImageFunction>(
        GetProcAddress(videoRenderer, COPY_IMAGE_FUNCTION));
    if (!copyImage) {
        FreeLibrary(videoRenderer);
    }
    return copyImage;
}

/// Copies pixel rows without requiring a Media Foundation export, preserving padding and signed strides.
static HRESULT CopyImageRows(BYTE* destination, LONG destinationStride, const BYTE* source, LONG sourceStride,
        DWORD rowBytes, DWORD rowCount) {
    if (rowBytes == 0 || rowCount == 0) {
        return S_OK;
    }
    if (!destination || !source) {
        return E_POINTER;
    }
    for (DWORD row = 0; row < rowCount; row++) {
        std::memcpy(destination, source, rowBytes);
        if (row + 1 < rowCount) {
            destination += destinationStride;
            source += sourceStride;
        }
    }
    return S_OK;
}

/// Uses the available system image-copy function, falling back to row copying only when neither export exists.
static HRESULT CopyImageCompatible(BYTE* destination, LONG destinationStride, const BYTE* source, LONG sourceStride,
        DWORD rowBytes, DWORD rowCount) {
    static const CopyImageFunction copyImage = ResolveCopyImageFunction();
    if (copyImage) {
        return copyImage(destination, destinationStride, source, sourceStride, rowBytes, rowCount);
    }
    return CopyImageRows(destination, destinationStride, source, sourceStride, rowBytes, rowCount);
}

/// Initializes the attributes common to the encoder input and output video types.
static HRESULT ConfigureVideoType(IMFMediaType* type, const GUID& subtype, UINT width, UINT height, UINT frameRate) {
    HRESULT result = type->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Video);
    if (SUCCEEDED(result)) {
        result = type->SetGUID(MF_MT_SUBTYPE, subtype);
    }
    if (SUCCEEDED(result)) {
        result = type->SetUINT32(MF_MT_INTERLACE_MODE, MFVideoInterlace_Progressive);
    }
    if (SUCCEEDED(result)) {
        result = MFSetAttributeSize(type, MF_MT_FRAME_SIZE, width, height);
    }
    if (SUCCEEDED(result)) {
        result = MFSetAttributeRatio(type, MF_MT_FRAME_RATE, frameRate, 1);
    }
    if (SUCCEEDED(result)) {
        result = MFSetAttributeRatio(type, MF_MT_PIXEL_ASPECT_RATIO, 1, 1);
    }
    return result;
}

/// Private Media Foundation state retained for one recording session.
struct Mp4Recorder::Impl {
    /// Encoding resources
    ComPtr<IMFSinkWriter> sinkWriter;
    ComPtr<ID3D11Texture2D> stagingTexture;
    DWORD streamIndex = 0;
    UINT width = 0;
    UINT height = 0;
    UINT frameRate = 0;
    LONGLONG frameDuration = 0;
    LONGLONG lastFrameIndex = -1;
    LARGE_INTEGER performanceFrequency{};
    LARGE_INTEGER recordingStartedAt{};

    /// Session state
    HRESULT lastError = S_OK;
    bool comInitialized = false;
    bool mediaFoundationStarted = false;
    std::atomic_bool recording = false;
};

/// Creates an idle recorder with no Media Foundation session.
Mp4Recorder::Mp4Recorder() : impl(new Impl{}) {}

/// Finalizes an active file before releasing the implementation state.
Mp4Recorder::~Mp4Recorder() {
    Stop();
    delete impl;
}

/// Reports whether frames are currently accepted by the sink writer.
bool Mp4Recorder::IsRecording() const {
    return impl->recording.load(std::memory_order_relaxed);
}

/// Returns the frame rate selected when the current session was opened.
UINT Mp4Recorder::FrameRate() const {
    return impl->frameRate;
}

/// Returns the most recent Media Foundation or Direct3D error.
HRESULT Mp4Recorder::LastError() const {
    return impl->lastError;
}

/// Records an initialization failure and unwinds every completed startup stage.
bool Mp4Recorder::FailStart(HRESULT error) {
    impl->lastError = error;
    impl->sinkWriter.Reset();
    impl->stagingTexture.Reset();
    impl->recording.store(false, std::memory_order_relaxed);
    if (impl->mediaFoundationStarted) {
        MFShutdown();
        impl->mediaFoundationStarted = false;
    }
    if (impl->comInitialized) {
        CoUninitialize();
        impl->comInitialized = false;
    }
    return false;
}

/// Configures a hardware-assisted H.264 sink and its CPU-readable staging texture.
bool Mp4Recorder::Start(ID3D11Device* device, const wchar_t* filePath, UINT width, UINT height, UINT frameRate) {
    Stop();
    if (!device || !filePath || !*filePath || width == 0 || height == 0 || frameRate == 0) {
        impl->lastError = E_INVALIDARG;
        return false;
    }
    HRESULT result = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    if (SUCCEEDED(result)) {
        impl->comInitialized = true;
    } else if (result != RPC_E_CHANGED_MODE) {
        return FailStart(result);
    }
    result = MFStartup(MF_VERSION);
    if (FAILED(result)) {
        return FailStart(result);
    }
    impl->mediaFoundationStarted = true;
    impl->width = width;
    impl->height = height;
    impl->frameRate = std::min(frameRate, 60U);
    impl->frameDuration = MEDIA_FOUNDATION_UNITS_PER_SECOND / impl->frameRate;
    impl->lastFrameIndex = -1;
    D3D11_TEXTURE2D_DESC stagingDescription{};
    stagingDescription.Width = impl->width;
    stagingDescription.Height = impl->height;
    stagingDescription.MipLevels = 1;
    stagingDescription.ArraySize = 1;
    stagingDescription.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    stagingDescription.SampleDesc.Count = 1;
    stagingDescription.Usage = D3D11_USAGE_STAGING;
    stagingDescription.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
    result = device->CreateTexture2D(&stagingDescription, nullptr, &impl->stagingTexture);
    if (FAILED(result)) {
        return FailStart(result);
    }
    ComPtr<IMFAttributes> writerAttributes;
    result = MFCreateAttributes(&writerAttributes, 2);
    if (SUCCEEDED(result)) {
        result = writerAttributes->SetUINT32(MF_READWRITE_ENABLE_HARDWARE_TRANSFORMS, TRUE);
    }
    if (SUCCEEDED(result)) {
        result = writerAttributes->SetGUID(MF_TRANSCODE_CONTAINERTYPE, MFTranscodeContainerType_MPEG4);
    }
    if (SUCCEEDED(result)) {
        result = MFCreateSinkWriterFromURL(filePath, nullptr, writerAttributes.Get(), &impl->sinkWriter);
    }
    if (FAILED(result)) {
        return FailStart(result);
    }
    ComPtr<IMFMediaType> outputType;
    result = MFCreateMediaType(&outputType);
    if (SUCCEEDED(result)) {
        result = ConfigureVideoType(outputType.Get(), MFVideoFormat_H264, impl->width, impl->height, impl->frameRate);
    }
    if (SUCCEEDED(result)) {
        const std::uint64_t estimatedBitRate =
            static_cast<std::uint64_t>(impl->width) * impl->height * impl->frameRate / 10;
        const UINT32 bitRate = static_cast<UINT32>(std::clamp<std::uint64_t>(estimatedBitRate, 4'000'000, 80'000'000));
        result = outputType->SetUINT32(MF_MT_AVG_BITRATE, bitRate);
    }
    if (SUCCEEDED(result)) {
        result = impl->sinkWriter->AddStream(outputType.Get(), &impl->streamIndex);
    }
    if (FAILED(result)) {
        return FailStart(result);
    }
    ComPtr<IMFMediaType> inputType;
    result = MFCreateMediaType(&inputType);
    if (SUCCEEDED(result)) {
        result = ConfigureVideoType(inputType.Get(), MFVideoFormat_RGB32, impl->width, impl->height, impl->frameRate);
    }
    const UINT32 imageSize = impl->width * impl->height * 4;
    if (SUCCEEDED(result)) {
        result = inputType->SetUINT32(MF_MT_DEFAULT_STRIDE, impl->width * 4);
    }
    if (SUCCEEDED(result)) {
        result = inputType->SetUINT32(MF_MT_SAMPLE_SIZE, imageSize);
    }
    if (SUCCEEDED(result)) {
        result = inputType->SetUINT32(MF_MT_FIXED_SIZE_SAMPLES, TRUE);
    }
    if (SUCCEEDED(result)) {
        result = inputType->SetUINT32(MF_MT_ALL_SAMPLES_INDEPENDENT, TRUE);
    }
    if (SUCCEEDED(result)) {
        result = impl->sinkWriter->SetInputMediaType(impl->streamIndex, inputType.Get(), nullptr);
    }
    if (SUCCEEDED(result)) {
        result = impl->sinkWriter->BeginWriting();
    }
    if (FAILED(result)) {
        return FailStart(result);
    }
    QueryPerformanceFrequency(&impl->performanceFrequency);
    QueryPerformanceCounter(&impl->recordingStartedAt);
    impl->lastError = S_OK;
    impl->recording.store(true, std::memory_order_relaxed);
    return true;
}

/// Finalizes the encoded stream and shuts down session-owned COM services.
HRESULT Mp4Recorder::Stop() {
    HRESULT result = S_OK;
    if (IsRecording() && impl->sinkWriter) {
        result = impl->sinkWriter->Finalize();
    }
    impl->recording.store(false, std::memory_order_relaxed);
    impl->sinkWriter.Reset();
    impl->stagingTexture.Reset();
    if (impl->mediaFoundationStarted) {
        const HRESULT shutdownResult = MFShutdown();
        if (SUCCEEDED(result) && FAILED(shutdownResult)) {
            result = shutdownResult;
        }
        impl->mediaFoundationStarted = false;
    }
    if (impl->comInitialized) {
        CoUninitialize();
        impl->comInitialized = false;
    }
    impl->lastError = result;
    return result;
}

/// Encodes a frame when its presentation timestamp advances to a new output slot.
bool Mp4Recorder::CaptureFrame(ID3D11DeviceContext* context, ID3D11Texture2D* source) {
    if (!IsRecording() || !context || !source) {
        return false;
    }
    LARGE_INTEGER now{};
    QueryPerformanceCounter(&now);
    const LONGLONG elapsed =
        static_cast<LONGLONG>(static_cast<long double>(now.QuadPart - impl->recordingStartedAt.QuadPart)
            * MEDIA_FOUNDATION_UNITS_PER_SECOND / impl->performanceFrequency.QuadPart);
    const LONGLONG frameIndex = (elapsed + impl->frameDuration / 2) / impl->frameDuration;
    if (frameIndex <= impl->lastFrameIndex) {
        return true;
    }
    context->CopyResource(impl->stagingTexture.Get(), source);
    D3D11_MAPPED_SUBRESOURCE mapped{};
    HRESULT result = context->Map(impl->stagingTexture.Get(), 0, D3D11_MAP_READ, 0, &mapped);
    if (FAILED(result)) {
        impl->lastError = result;
        return false;
    }
    const DWORD rowBytes = impl->width * 4;
    const DWORD bufferSize = rowBytes * impl->height;
    ComPtr<IMFMediaBuffer> buffer;
    result = MFCreateMemoryBuffer(bufferSize, &buffer);
    BYTE* destination = nullptr;
    if (SUCCEEDED(result)) {
        result = buffer->Lock(&destination, nullptr, nullptr);
    }
    if (SUCCEEDED(result)) {
        result = CopyImageCompatible(destination, static_cast<LONG>(rowBytes), static_cast<const BYTE*>(mapped.pData),
            static_cast<LONG>(mapped.RowPitch), rowBytes, impl->height);
    }
    if (destination) {
        buffer->Unlock();
    }
    context->Unmap(impl->stagingTexture.Get(), 0);
    if (SUCCEEDED(result)) {
        result = buffer->SetCurrentLength(bufferSize);
    }
    ComPtr<IMFSample> sample;
    if (SUCCEEDED(result)) {
        result = MFCreateSample(&sample);
    }
    if (SUCCEEDED(result)) {
        result = sample->AddBuffer(buffer.Get());
    }
    if (SUCCEEDED(result)) {
        result = sample->SetSampleTime(frameIndex * impl->frameDuration);
    }
    if (SUCCEEDED(result)) {
        result = sample->SetSampleDuration(impl->frameDuration);
    }
    if (SUCCEEDED(result)) {
        result = impl->sinkWriter->WriteSample(impl->streamIndex, sample.Get());
    }
    if (FAILED(result)) {
        impl->lastError = result;
        return false;
    }
    impl->lastFrameIndex = frameIndex;
    return true;
}
