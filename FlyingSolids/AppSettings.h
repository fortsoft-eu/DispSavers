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
 * Last modified for version 1.1.0.0
 */

#pragma once

#include "Effects.h"
#include "Mp4Recorder.h"
#include <cstdint>
#include <limits>
#include <string>

/// Identifies the independent registry branch used by one application mode.
enum class SettingsProfile {
    Standalone,
    ScreenSaver
};

/// Persistent user preferences shared by the settings window and animation.
struct AppSettings {
    /// Animation parameters
    int objectSpeedPercent = 100;
    int cameraSpeedPercent = 100;
    int copyCount = 1;
    int objectSizePercent = 100;
    bool cameraFlight = false;
    bool mainLight = true;
    bool fillLight = false;
    bool ambientLight = true;
    bool rimLight = true;
    std::uint32_t enabledSolids = ALL_SOLID_MASK;

    /// User-interface state
    bool preventScreenSaver = false;
    RecordingOptions recording;
    std::wstring animationMonitorDevice;
    int controlWindowX = std::numeric_limits<int>::min();
    int controlWindowY = std::numeric_limits<int>::min();
    int helpX = std::numeric_limits<int>::min();
    int helpY = std::numeric_limits<int>::min();
    int aboutX = std::numeric_limits<int>::min();
    int aboutY = std::numeric_limits<int>::min();
    int recordingSettingsX = std::numeric_limits<int>::min();
    int recordingSettingsY = std::numeric_limits<int>::min();
    int language = -1;
    SettingsProfile profile = SettingsProfile::Standalone;

    /// Loads the selected profile from the current user's registry hive.
    void Load(SettingsProfile selectedProfile);

    /// Saves the current values to the registry branch of the loaded profile.
    void Save() const;

    /// Saves window positions without committing pending animation preferences.
    void SaveWindowPositions() const;
};
