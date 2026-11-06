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
 * Last modified for version 1.3.1.0
 */

#pragma once

#include "Mp4Recorder.h"
#include "ImageExport.h"
#include <windows.h>
#include <cstdint>
#include <vector>

/// One monitor view with its own presentation and capture of a shared GPU world.
class Renderer final {
public:
    /// Creates an uninitialized renderer implementation.
    Renderer();

    /// Releases all Direct3D and capture resources.
    ~Renderer();
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    /// Initializes an output renderer, optionally sharing another renderer's board and device.
    bool Initialize(HWND window, Renderer* sharedWorld = nullptr);

    /// Forwards client-area changes to the private implementation.
    void Resize(unsigned width, unsigned height);

    /// Sets the shared-world bounds and the logical rectangle displayed by this output.
    void SetView(const RECT& worldBounds, const RECT& monitorBounds);

    /// Replaces the shared GPU board with the supplied CPU cells.
    bool SetBoard(unsigned columns, unsigned rows, const std::vector<std::uint8_t>& cells);

    /// Advances the shared GPU simulation and returns its generation or cycle-query status.
    HRESULT Advance(unsigned generations = 1);

    /// Draws and presents this output view using its pacing and recording state.
    HRESULT Draw(unsigned syncInterval = 1);

    /// Updates the shared board cell spacing.
    void SetCellSize(unsigned size);

    /// Updates live-cell and background colors in the shared board.
    void SetColors(COLORREF aliveColor, COLORREF backgroundColor);

    /// Updates the shared board grid appearance without reseeding cells.
    void SetGrid(bool visible, COLORREF color);

    /// Enables or disables repeated-phase detection for the shared board.
    bool SetAutoReset(bool enabled);

    /// Updates the displayed regions considered by shared-board cycle detection.
    bool SetVisibleRegions(const RECT& worldBounds, const std::vector<RECT>& regions);

    /// Reports whether the shared board has detected a repeated visible phase.
    bool ResetRequested() const;

    /// Returns the shared device texture limit for board allocation.
    unsigned MaximumBoardDimension() const;

    /// Reports availability of the actual output's vertical-blank clock.
    bool UsesVerticalBlankWait() const;

    /// Consumes the latest output refresh, including one that occurred while Present was blocking.
    HRESULT WaitForNextFrame();

    /// Copies the shared GPU board into a row-major CPU cell buffer.
    bool ReadCells(std::vector<std::uint8_t>& cells) const;

    /// Reports whether the shared board runs on a hardware Direct3D device.
    bool IsHardwareAccelerated() const;

    /// Starts MP4 capture using this output device and current render dimensions.
    bool StartRecording(const wchar_t* path, unsigned frameRate, const RecordingOptions& options);

    /// Checks whether the current output dimensions and recording options can be encoded.
    bool CheckRecordingSupport(unsigned frameRate, const RecordingOptions& options) const;

    /// Finalizes active MP4 capture.
    void StopRecording();

    /// Drains capture resources before releasing the rendering lock, without waiting for the encoder worker.
    void PrepareRecordingStop();

    /// Joins the recording worker after capture is disabled, allowing animation to continue during
    /// finalization.
    void FinishRecordingStop();

    /// Reports whether the renderer currently records frames.
    bool IsRecording() const;

    /// Returns the recorder's most recent HRESULT.
    HRESULT RecordingError() const;

    /// Saves the current back buffer in the selected image format.
    bool SaveSnapshot(const wchar_t* path, SnapshotFormat format = SnapshotFormat::Png) const;

    /// Tests the complete image capture pipeline with the current scene and an in-memory stream.
    bool CheckSnapshotSupport() const;

    /// Returns the current render-target width.
    unsigned Width() const;

    /// Returns the current render-target height.
    unsigned Height() const;

private:
    struct Impl;
    Impl* impl = nullptr;
};
