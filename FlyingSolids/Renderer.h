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
 * Last modified for version 1.2.0.0
 */

#pragma once

#include "Simulation.h"
#include "Mp4Recorder.h"
#include <windows.h>

/// Owns the Direct3D rendering pipeline and optional frame capture services.
class Renderer final {

public:
    /// Creates an uninitialized renderer.
    Renderer();

    /// Finalizes recording and releases all rendering resources.
    ~Renderer();

    /// Prevents copying ownership of rendering resources.
    Renderer(const Renderer&) = delete;

    /// Prevents copying ownership of rendering resources.
    Renderer& operator=(const Renderer&) = delete;

    /// Creates Direct3D resources for the supplied animation window.
    bool Initialize(HWND window);

    /// Recreates size-dependent resources for the current client area.
    void Resize(unsigned width, unsigned height);

    /// Reports whether flip presentation can use the containing output's vertical-blank clock.
    bool UsesVerticalBlankWait() const;

    /// Consumes the latest refresh, including one during Present; errors use timed legacy pacing.
    HRESULT WaitForNextFrame();

    /// Renders and presents one complete scene snapshot.
    void Draw(const SceneState& scene, bool inspectPixels = false, unsigned syncInterval = 1);

    /// Returns the diagnostic count produced by the last inspected frame.
    unsigned LastVisiblePixelCount() const;

    /// Recording and still-image capture

    /// Starts MP4 recording using the selected Viewport or TV output format.
    bool StartRecording(const wchar_t* path, unsigned frameRate, const RecordingOptions& options);

    /// Tests MP4 recording of the current render target before a file is selected.
    bool CheckRecordingSupport(unsigned frameRate, const RecordingOptions& options) const;

    /// Finalizes the current recording and releases its resources.
    void StopRecording();

    /// Stops capture while holding the rendering lock, leaving encoder finalization for a separate phase.
    void PrepareRecordingStop();

    /// Finishes a previously stopped recording without holding the surface rendering lock.
    void FinishRecordingStop();

    /// Reports whether a recording session is active.
    bool IsRecording() const;

    /// Returns the most recent recording error.
    HRESULT RecordingError() const;

    /// Saves the current render target as a PNG image.
    bool SaveSnapshot(const wchar_t* path) const;

    /// Tests PNG capture and encoding in memory before a file is selected.
    bool CheckSnapshotSupport() const;

    /// Current render-target dimensions

    /// Returns the render-target width in pixels.
    unsigned Width() const;

    /// Returns the render-target height in pixels.
    unsigned Height() const;

private:
    /// Direct3D implementation hidden from clients of this header.
    struct Impl;
    Impl* impl = nullptr;
};
