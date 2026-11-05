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

#pragma once

#include "PersistWindowState.h"
#include "Mp4Recorder.h"
#include <limits>
#include <string>
#include <windows.h>

/// Independent preference profiles for the EXE and installed screen saver.
enum class SettingsProfile {
    Standalone,
    ScreenSaver
};

/// Scene preferences, recording options and persisted auxiliary-window placement.
struct AppSettings {
    unsigned cellSize = 8;
    unsigned generationsPerSecond = 20;
    unsigned densityPercent = 25;
    COLORREF aliveColor = RGB(64, 224, 112);
    COLORREF backgroundColor = RGB(0, 0, 0);
    COLORREF gridColor = RGB(48, 48, 48);
    bool showGrid = false;
    bool autoReset = true;
    bool randomAliveColor = true;
    bool randomBackgroundColor = false;
    bool randomGridColor = false;
    bool preventScreenSaver = false;
    bool patternsOnly = false;
    RecordingOptions recording;
    std::wstring patternId;
    std::wstring animationMonitorDevice;
    int language = -1;
    int recordingSettingsX = std::numeric_limits<int>::min();
    int recordingSettingsY = std::numeric_limits<int>::min();
    PersistWindowStateData helpWindowState;
    PersistWindowStateData aboutWindowState;
    SettingsProfile profile = SettingsProfile::Standalone;

    /// Loads and validates the selected profile while retaining defaults for missing values.
    void Load(SettingsProfile selectedProfile);

    /// Writes the current preferences and stored auxiliary-window positions to the selected profile.
    void Save() const;

    /// Restores only the three slider values and the three configured colors.
    void ResetValues();

    /// Writes auxiliary-window placement without committing other preference changes.
    void SaveWindowPositions() const;
};
