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

#pragma once

#include <windows.h>

struct ID3D11Device;
struct ID3D11DeviceContext;
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
    bool Start(ID3D11Device* device, const wchar_t* filePath, UINT width, UINT height, UINT frameRate);

    /// Tests the complete recording pipeline with one frame in a disposable temporary file.
    static HRESULT CheckSupport(ID3D11Device* device, ID3D11DeviceContext* context, ID3D11Texture2D* source,
        UINT width, UINT height, UINT frameRate);

    /// Finalizes the file and releases all recording resources.
    HRESULT Stop();

    /// Copies and encodes one frame from a Direct3D texture.
    bool CaptureFrame(ID3D11DeviceContext* context, ID3D11Texture2D* source);

    /// Recording state and diagnostics

    /// Reports whether the encoder is accepting frames.
    bool IsRecording() const;

    /// Returns the recording frame rate selected when the session started.
    UINT FrameRate() const;

    /// Returns the most recent Media Foundation or frame-capture error.
    HRESULT LastError() const;

private:
    /// Rolls back a partially initialized recording session.
    bool FailStart(HRESULT error);

    /// Media Foundation implementation hidden from clients of this header.
    struct Impl;
    Impl* impl = nullptr;
};
