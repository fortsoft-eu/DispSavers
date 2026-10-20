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

#include "Effects.h"
#include "Mp4Recorder.h"
#include "PersistWindowState.h"
#include <cstdint>
#include <limits>
#include <map>
#include <string>
#include <vector>

/// Identifies the independent registry branch used by one application mode.
enum class SettingsProfile {
    Standalone,
    ScreenSaver
};

/// Stable property identifiers used for selection summaries and per-monitor persistence.
enum class AnimationProperty {
    ObjectSpeed,
    CameraSpeed,
    CopyCount,
    ObjectSize,
    CameraFlight,
    MainLight,
    FillLight,
    AmbientLight,
    RimLight,
    EnabledSolids,
    Count
};

/// Complete animation preferences for one Windows display device.
struct MonitorAnimation {
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

    /// Reads or validates one animation property without changing other properties.
    std::uint32_t Value(AnimationProperty property) const;
    void SetValue(AnimationProperty property, std::uint32_t value);
};

/// Values shared by selected monitors, with separate masks for differing properties and solids.
struct MonitorSelection {
    MonitorAnimation values;
    std::uint32_t mixedProperties = 0;
    std::uint32_t mixedSolids = 0;
    bool available = false;

    bool IsMixed(AnimationProperty property) const;
};

/// Persistent user preferences shared by the settings window and animation.
struct AppSettings {
    /// Independent animation preferences keyed by Windows display device identity.
    std::map<std::wstring, MonitorAnimation> monitorAnimations;

    /// User-interface state
    RecordingOptions recording;
    std::wstring animationMonitorDevice;
    std::wstring selectedAnimationMonitors;
    bool allAnimationMonitorsSelected = true;
    bool preventScreenSaver = false;
    int controlWindowX = std::numeric_limits<int>::min();
    int controlWindowY = std::numeric_limits<int>::min();
    PersistWindowStateData helpWindowState;
    PersistWindowStateData aboutWindowState;
    int recordingSettingsX = std::numeric_limits<int>::min();
    int recordingSettingsY = std::numeric_limits<int>::min();
    int language = -1;
    SettingsProfile profile = SettingsProfile::Standalone;

    /// Initializes new display identities without changing existing preferences.
    void InitializeMonitorAnimations(const std::vector<std::wstring>& devices);

    /// Returns this device's own settings, creating a built-in initial record when it is new.
    MonitorAnimation& AnimationForMonitor(const std::wstring& device);

    /// Summarizes common and differing values without changing settings.
    MonitorSelection SelectionForMonitors(const std::vector<std::wstring>& devices);

    /// Changes only the requested property or solid on the selected display identities.
    void SetMonitorValue(const std::vector<std::wstring>& devices, AnimationProperty property, std::uint32_t value);
    void SetMonitorSolid(const std::vector<std::wstring>& devices, unsigned index, bool enabled);

    /// Loads the selected profile from the current user's registry hive.
    void Load(SettingsProfile selectedProfile);

    /// Saves the current values to the registry branch of the loaded profile.
    void Save() const;

    /// Saves window positions and selected monitor rows without committing pending animation preferences.
    void SaveWindowPositions() const;
};
