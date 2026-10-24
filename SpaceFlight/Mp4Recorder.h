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
 * Last modified for version 1.2.1.0
 */

#pragma once

#include <windows.h>
#include <cstdint>

/// Output geometry and exact rational timing shared by Viewport and TV recording.
struct RecordingFormat {
    bool television = false;
    bool temporalBlend = true;
    unsigned width = 0;
    unsigned height = 0;
    unsigned numerator = 50;
    unsigned denominator = 1;
    unsigned aspectX = 1;
    unsigned aspectY = 1;

    /// Disables temporal blending for integral rate ratios and for NTSC output on a 60 Hz monitor.
    void SetMonitorRate(unsigned rate, unsigned divisor);

    /// Derives each boundary directly from its frame index without accumulating rounding errors.
    std::uint64_t Boundary(std::uint64_t frame, std::uint64_t units) const;

    /// Returns a sample boundary in Media Foundation's 100-nanosecond units.
    std::uint64_t Time(std::uint64_t frame) const;

    /// Returns the last output slot reached by the recording clock.
    std::uint64_t FramesAt(std::uint64_t units) const;

    /// Fits the complete source image into the output while preserving its displayed aspect ratio.
    RECT Viewport(POINT base) const;
};

/// Persistent recording-output settings.
struct RecordingOptions {
    bool television = false;
    int resolution = 0;
    int rate = 0;

    /// Selects TV presets or the native viewport recording format.
    RecordingFormat Format(unsigned nativeWidth, unsigned nativeHeight, unsigned nativeRate) const;
};

/// Direct3D device interface used to create recording resources.
struct ID3D11Device;
/// Direct3D context interface used to copy and convert captured frames.
struct ID3D11DeviceContext;
/// Direct3D texture interface representing a captured render target.
struct ID3D11Texture2D;

/// Encodes Direct3D texture frames into an H.264 MP4 file through Media Foundation.
class Mp4Recorder final {

public:
    /// Creates an idle recorder.
    Mp4Recorder();

    /// Finalizes recording and releases the recorder implementation.
    ~Mp4Recorder();

    /// Prevents copying ownership of recording resources.
    Mp4Recorder(const Mp4Recorder&) = delete;

    /// Prevents copying ownership of recording resources.
    Mp4Recorder& operator=(const Mp4Recorder&) = delete;

    /// Opens an output file and prepares resources for the supplied GPU device.
    bool Start(ID3D11Device* device, const wchar_t* filePath, UINT width, UINT height, const RecordingFormat& format);

    /// Tests the complete recording pipeline with one frame in a disposable temporary file.
    static HRESULT CheckSupport(ID3D11Device* device, ID3D11DeviceContext* context, ID3D11Texture2D* source,
        UINT width, UINT height, const RecordingFormat& format);

    /// Drains final GPU copies when a context is supplied and joins the worker after MP4 finalization.
    HRESULT Stop(ID3D11DeviceContext* context = nullptr);

    /// Drains final GPU copies and stops accepting captures without waiting for encoder finalization.
    void PrepareStop(ID3D11DeviceContext* context = nullptr);

    /// Joins a previously stopped recording worker and releases its completed capture resources.
    HRESULT FinishStop();

    /// Schedules nonblocking GPU readback and submits completed pixels to the recording worker.
    bool CaptureFrame(ID3D11DeviceContext* context, ID3D11Texture2D* source);

    /// Recording state and diagnostics

    /// Reports whether the encoder is accepting frames.
    bool IsRecording() const;

    /// Returns the nearest whole-number approximation of the selected recording frame rate.
    UINT FrameRate() const;

    /// Returns the most recent Media Foundation or frame-capture error.
    HRESULT LastError() const;

private:
    /// Media Foundation implementation hidden from clients of this header.
    struct Impl;
    Impl* impl = nullptr;
};
