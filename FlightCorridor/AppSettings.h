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
#include <vector>
#include <string>

/// Identifies the independent registry branch used by one application mode.
enum class SettingsProfile {
    Standalone,
    ScreenSaver
};

/// Stable property identifiers shared by selected-monitor editing and rendering.
enum class AnimationProperty {
    ObjectSpeed,
    Effect,
    Textured,
    CameraTumbling,
    CameraReversals,
    MainLight,
    FillLight,
    AmbientLight,
    RimLight,
    EnabledEffects,
    Count
};

/// Independently configured animation for one Windows display device.
struct MonitorAnimation {
    EffectKind effect = EffectKind::Corridor;
    bool textured = true;
    bool cameraTumbling = true;
    bool cameraReversals = true;
    bool mainLight = true;
    bool fillLight = false;
    bool ambientLight = true;
    bool rimLight = true;
    int objectSpeedPercent = 100;
    std::uint32_t enabledEffects = ALL_EFFECT_MASK;

    /// Reads one animation property without changing the stored preferences.
    std::uint32_t Value(AnimationProperty property) const;

    /// Validates and updates one animation property without modifying other properties.
    void SetValue(AnimationProperty property, std::uint32_t value);

    /// Packs the effect, switches and inhibition flag independently of the numeric speed value.
    std::uint32_t Packed() const;
};

/// Values shared by selected monitors, including explicit mixed-property states.
struct MonitorSelection {
    MonitorAnimation values;
    std::uint32_t mixedProperties = 0;
    bool available = false;

    /// Reports whether selected monitors have different values of the requested property.
    bool IsMixed(AnimationProperty property) const;
};

/// Persistent user preferences shared by the settings window and animation.
struct AppSettings {
    /// Independent animation parameters keyed by Windows display identity.
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

    /// Creates first-animation textured defaults for every monitor without overwriting saved choices.
    void InitializeMonitorAnimations(const std::vector<std::wstring>& devices);

    /// Returns this device's own settings, creating a built-in initial record when it is new.
    MonitorAnimation& AnimationForMonitor(const std::wstring& device);

    /// Summarizes common and differing properties without modifying selected displays.
    MonitorSelection SelectionForMonitors(const std::vector<std::wstring>& devices);

    /// Changes one property only on the selected display identities.
    void SetMonitorValue(const std::vector<std::wstring>& devices, AnimationProperty property, std::uint32_t value);

    /// Loads the selected profile from the current user's registry hive.
    void Load(SettingsProfile selectedProfile);

    /// Saves the current values to the registry branch of the loaded profile.
    void Save() const;

    /// Saves window positions and selected monitor rows without committing pending animation preferences.
    void SaveWindowPositions() const;
};
