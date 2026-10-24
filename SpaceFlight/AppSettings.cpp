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

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "AppSettings.h"
#include <windows.h>
#include <algorithm>
#include <stdexcept>

/// Registry branches kept deliberately independent between executable modes.
constexpr wchar_t STANDALONE_REGISTRY_PATH[] = L"SOFTWARE\\FortSoft\\SpaceFlight\\Standalone";
constexpr wchar_t SCREEN_SAVER_REGISTRY_PATH[] = L"SOFTWARE\\FortSoft\\SpaceFlight\\ScreenSaver";

/// Registry value names shared by settings loading and saving.
constexpr wchar_t MONITOR_ANIMATIONS_KEY[] = L"Monitors";
constexpr wchar_t MONITOR_SPEEDS_KEY[] = L"MonitorSpeeds";
constexpr wchar_t ANIMATION_MONITOR_VALUE_NAME[] = L"AnimationMonitor";
constexpr wchar_t SELECTED_MONITORS_VALUE_NAME[] = L"SelectedAnimationMonitors";
constexpr wchar_t ALL_MONITORS_SELECTED_VALUE_NAME[] = L"AllAnimationMonitorsSelected";
constexpr wchar_t CONTROL_WINDOW_X_VALUE_NAME[] = L"ControlWindowX";
constexpr wchar_t CONTROL_WINDOW_Y_VALUE_NAME[] = L"ControlWindowY";
constexpr wchar_t HELP_X_VALUE_NAME[] = L"HelpX";
constexpr wchar_t HELP_Y_VALUE_NAME[] = L"HelpY";
constexpr wchar_t HELP_WIDTH_VALUE_NAME[] = L"HelpWidth";
constexpr wchar_t HELP_HEIGHT_VALUE_NAME[] = L"HelpHeight";
constexpr wchar_t HELP_MAXIMIZED_VALUE_NAME[] = L"HelpMaximized";
constexpr wchar_t ABOUT_X_VALUE_NAME[] = L"AboutX";
constexpr wchar_t ABOUT_Y_VALUE_NAME[] = L"AboutY";
constexpr wchar_t ABOUT_WIDTH_VALUE_NAME[] = L"AboutWidth";
constexpr wchar_t ABOUT_HEIGHT_VALUE_NAME[] = L"AboutHeight";
constexpr wchar_t ABOUT_MAXIMIZED_VALUE_NAME[] = L"AboutMaximized";
constexpr wchar_t RECORDING_SETTINGS_X_VALUE_NAME[] = L"RecordingSettingsX";
constexpr wchar_t RECORDING_SETTINGS_Y_VALUE_NAME[] = L"RecordingSettingsY";
constexpr wchar_t LANGUAGE_VALUE_NAME[] = L"Language";
constexpr wchar_t RECORDING_TV_VALUE_NAME[] = L"RecordingTV";
constexpr wchar_t RECORDING_RESOLUTION_VALUE_NAME[] = L"RecordingResolution";
constexpr wchar_t RECORDING_RATE_VALUE_NAME[] = L"RecordingRate";
constexpr wchar_t PREVENT_SCREEN_SAVER_VALUE_NAME[] = L"PreventScreenSaver";

/// Numeric monitor preferences represented by the animation sliders.
constexpr AnimationProperty NUMERIC_ANIMATION_PROPERTIES[]{ AnimationProperty::ObjectSpeed };

/// Returns the registry branch assigned to a settings profile.
static const wchar_t* RegistryPath(SettingsProfile profile) {
    return profile == SettingsProfile::ScreenSaver ? SCREEN_SAVER_REGISTRY_PATH : STANDALONE_REGISTRY_PATH;
}

/// Reads a DWORD value and preserves the supplied default on type or access failure.
static int ReadValue(HKEY key, const wchar_t* name, int defaultValue) {
    DWORD value = 0;
    DWORD type = 0;
    DWORD size = sizeof(value);
    const LSTATUS queryResult =
        RegQueryValueExW(key, name, nullptr, &type, reinterpret_cast<BYTE*>(&value), &size);
    if (queryResult == ERROR_SUCCESS && type == REG_DWORD && size == sizeof(value)) {
        return static_cast<int>(value);
    }
    return defaultValue;
}

/// Reads a null-terminated string and removes padding returned by the registry API.
static std::wstring ReadString(HKEY key, const wchar_t* name) {
    DWORD type = 0;
    DWORD size = 0;
    const LSTATUS queryResult = RegQueryValueExW(key, name, nullptr, &type, nullptr, &size);
    constexpr DWORD MAX_SETTINGS_STRING_BYTES = 65536;
    if (queryResult != ERROR_SUCCESS
            || type != REG_SZ
            || size < sizeof(wchar_t)
            || size > MAX_SETTINGS_STRING_BYTES
            || size % sizeof(wchar_t) != 0) {
        return std::wstring{};
    }
    std::wstring value(size / sizeof(wchar_t), L'\0');
    const DWORD capacity = static_cast<DWORD>(value.size() * sizeof(wchar_t));
    const LSTATUS readResult = RegQueryValueExW(key, name, nullptr, &type,
        reinterpret_cast<BYTE*>(value.data()), &size);
    if (readResult != ERROR_SUCCESS
            || type != REG_SZ
            || size > capacity
            || size < sizeof(wchar_t)
            || size % sizeof(wchar_t) != 0) {
        return std::wstring{};
    }
    value.resize(size / sizeof(wchar_t));
    if (value.back() != L'\0') {
        return std::wstring{};
    }
    while (!value.empty() && value.back() == L'\0') {
        value.pop_back();
    }
    if (value.find(L'\0') != std::wstring::npos) {
        return std::wstring{};
    }
    return value;
}

/// Reads one property using the same identifiers as multi-monitor editing.
std::uint32_t MonitorAnimation::Value(AnimationProperty property) const {
    switch (property) {
        case AnimationProperty::ObjectSpeed: return objectSpeedPercent;
        case AnimationProperty::Effect: return static_cast<std::uint32_t>(effect);
        case AnimationProperty::Textured: return textured;
        case AnimationProperty::SurfaceShape: return static_cast<std::uint32_t>(surfaceShape);
        case AnimationProperty::CameraTumbling: return cameraTumbling;
        case AnimationProperty::CameraReversals: return cameraReversals;
        case AnimationProperty::MainLight: return mainLight;
        case AnimationProperty::FillLight: return fillLight;
        case AnimationProperty::AmbientLight: return ambientLight;
        case AnimationProperty::RimLight: return rimLight;
        case AnimationProperty::EnabledEffects: return enabledEffects;
        default: throw std::invalid_argument("Unknown animation property");
    }
}

/// Validates one property without overwriting independent preferences.
void MonitorAnimation::SetValue(AnimationProperty property, std::uint32_t value) {
    switch (property) {
        case AnimationProperty::ObjectSpeed:
            objectSpeedPercent = static_cast<int>(std::min(value, 1600U));
            break;
        case AnimationProperty::Effect:
            effect = static_cast<EffectKind>(std::min(value, static_cast<unsigned>(EFFECT_COUNT) - 1));
            break;
        case AnimationProperty::Textured:
            textured = value != 0;
            break;
        case AnimationProperty::SurfaceShape:
            surfaceShape = static_cast<SurfaceShape>(std::min(value, 2U));
            break;
        case AnimationProperty::CameraTumbling:
            cameraTumbling = value != 0;
            break;
        case AnimationProperty::CameraReversals:
            cameraReversals = value != 0;
            break;
        case AnimationProperty::MainLight:
            mainLight = value != 0;
            break;
        case AnimationProperty::FillLight:
            fillLight = value != 0;
            break;
        case AnimationProperty::AmbientLight:
            ambientLight = value != 0;
            break;
        case AnimationProperty::RimLight:
            rimLight = value != 0;
            break;
        case AnimationProperty::EnabledEffects:
            enabledEffects = (value & ALL_EFFECT_MASK) != 0 ? ALL_EFFECT_MASK : 0U;
            break;
        default:
            throw std::invalid_argument("Unknown animation property");
    }
}

/// Reports differing values of the requested property in the current monitor selection.
bool MonitorSelection::IsMixed(AnimationProperty property) const {
    return (mixedProperties & 1U << static_cast<unsigned>(property)) != 0;
}

/// Packs effect and switch values without changing the separately stored numeric speed.
std::uint32_t MonitorAnimation::Packed() const {
    return static_cast<std::uint32_t>(effect)
        | (textured ? 2U : 0U)
        | (cameraTumbling ? 4U : 0U)
        | (cameraReversals ? 8U : 0U)
        | (enabledEffects == 0 ? 16U : 0U)
        | (mainLight ? 0U : 64U)
        | (fillLight ? 128U : 0U)
        | (ambientLight ? 0U : 256U)
        | (rimLight ? 0U : 512U)
        | (surfaceShape == SurfaceShape::Plane ? 1024U : 0U)
        | (surfaceShape == SurfaceShape::Funnel ? 2048U : 0U);
}

/// Assigns the first textured flight to every device, preserving saved and disconnected-display choices.
void AppSettings::InitializeMonitorAnimations(const std::vector<std::wstring>& devices) {
    for (const std::wstring& device : devices) {
        monitorAnimations.try_emplace(device);
    }
}

/// Looks up a Windows display device without treating a sorted ListView row as its identity.
MonitorAnimation& AppSettings::AnimationForMonitor(const std::wstring& device) {
    return monitorAnimations.try_emplace(device).first->second;
}

/// Chooses the most frequent selected-monitor value, resolving equal counts by the lowest numeric value.
static std::uint32_t MostFrequentMonitorValue(AppSettings& settings, const std::vector<std::wstring>& devices,
        AnimationProperty property) {
    std::map<std::uint32_t, std::size_t> frequencies;
    for (const std::wstring& device : devices) {
        frequencies[settings.AnimationForMonitor(device).Value(property)]++;
    }
    std::uint32_t value = 0;
    std::size_t count = 0;
    for (const auto& entry : frequencies) {
        if (entry.second > count) {
            value = entry.first;
            count = entry.second;
        }
    }
    return value;
}

/// Reports differing values and chooses the most frequent selected value for each numeric property.
MonitorSelection AppSettings::SelectionForMonitors(const std::vector<std::wstring>& devices) {
    MonitorSelection result;
    for (const std::wstring& device : devices) {
        const MonitorAnimation& animation = AnimationForMonitor(device);
        if (!result.available) {
            result.values = animation;
            result.available = true;
            continue;
        }
        for (unsigned index = 0; index < static_cast<unsigned>(AnimationProperty::Count); index++) {
            const AnimationProperty property = static_cast<AnimationProperty>(index);
            if (result.values.Value(property) != animation.Value(property)) {
                result.mixedProperties |= 1U << index;
            }
        }
    }
    if (result.available) {
        for (const AnimationProperty property : NUMERIC_ANIMATION_PROPERTIES) {
            result.values.SetValue(property, MostFrequentMonitorValue(*this, devices, property));
        }
    }
    return result;
}

/// Changes only the requested property on selected monitor identities.
void AppSettings::SetMonitorValue(const std::vector<std::wstring>& devices, AnimationProperty property,
        std::uint32_t value) {
    for (const std::wstring& device : devices) {
        AnimationForMonitor(device).SetValue(property, value);
    }
}

/// Reads independently persisted monitor choices from the current application's profile.
static void ReadMonitorAnimations(HKEY profile, AppSettings& settings) {
    HKEY key = nullptr;
    if (RegOpenKeyExW(profile, MONITOR_ANIMATIONS_KEY, 0, KEY_READ, &key) != ERROR_SUCCESS) {
        return;
    }
    HKEY speeds = nullptr;
    RegOpenKeyExW(profile, MONITOR_SPEEDS_KEY, 0, KEY_READ, &speeds);
    DWORD maximumNameLength = 0;
    const LSTATUS infoResult = RegQueryInfoKeyW(key, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
        nullptr, &maximumNameLength, nullptr, nullptr, nullptr);
    if (infoResult == ERROR_SUCCESS && maximumNameLength < 32768U) {
        std::vector<wchar_t> name(static_cast<std::size_t>(maximumNameLength) + 1);
        for (DWORD index = 0; ; index++) {
            DWORD length = static_cast<DWORD>(name.size());
            DWORD type = 0;
            DWORD value = 0;
            DWORD size = sizeof(value);
            const LSTATUS result = RegEnumValueW(key, index, name.data(), &length, nullptr, &type,
                reinterpret_cast<BYTE*>(&value), &size);
            if (result == ERROR_NO_MORE_ITEMS) {
                break;
            }
            if (result == ERROR_SUCCESS
                    && type == REG_DWORD
                    && size == sizeof(value)
                    && value <= 4095U
                    && length != 0
                    && (value & 3072U) != 3072U) {
                const SurfaceShape surfaceShape = (value & 2048U) != 0
                    ? SurfaceShape::Funnel
                    : (value & 1024U) != 0 ? SurfaceShape::Plane : SurfaceShape::Waves;
                MonitorAnimation animation{
                    static_cast<EffectKind>(value & 1U),
                    (value & 2U) != 0,
                    surfaceShape,
                    (value & 4U) != 0,
                    (value & 8U) != 0,
                    (value & 64U) == 0,
                    (value & 128U) != 0,
                    (value & 256U) == 0,
                    (value & 512U) == 0,
                    100,
                    (value & 16U) != 0 ? 0U : ALL_EFFECT_MASK
                };
                const std::wstring device(name.data(), length);
                if (speeds) {
                    const int speed = ReadValue(speeds, device.c_str(), animation.objectSpeedPercent);
                    if (speed >= 0 && speed <= 1600) {
                        animation.objectSpeedPercent = speed;
                    }
                }
                settings.monitorAnimations.emplace(device, animation);
            } else if (result != ERROR_SUCCESS && result != ERROR_MORE_DATA) {
                break;
            }
        }
    }
    if (speeds) {
        RegCloseKey(speeds);
    }
    RegCloseKey(key);
}

/// Persists device-specific animation, texture and camera choices without removing disconnected settings.
static void WriteMonitorAnimations(HKEY profile, const AppSettings& settings) {
    HKEY key = nullptr;
    const LSTATUS createResult = RegCreateKeyExW(profile, MONITOR_ANIMATIONS_KEY, 0, nullptr, 0, KEY_WRITE,
        nullptr, &key, nullptr);
    if (createResult != ERROR_SUCCESS) {
        return;
    }
    HKEY speeds = nullptr;
    RegCreateKeyExW(profile, MONITOR_SPEEDS_KEY, 0, nullptr, 0, KEY_WRITE, nullptr, &speeds, nullptr);
    for (const auto& entry : settings.monitorAnimations) {
        const DWORD value = entry.second.Packed();
        RegSetValueExW(key, entry.first.c_str(), 0, REG_DWORD, reinterpret_cast<const BYTE*>(&value),
            sizeof(value));
        if (speeds) {
            const DWORD speed = static_cast<DWORD>(std::clamp(entry.second.objectSpeedPercent, 0, 1600));
            RegSetValueExW(speeds, entry.first.c_str(), 0, REG_DWORD,
                reinterpret_cast<const BYTE*>(&speed), sizeof(speed));
        }
    }
    if (speeds) {
        RegCloseKey(speeds);
    }
    RegCloseKey(key);
}

/// Loads and validates settings from the selected registry profile.
void AppSettings::Load(SettingsProfile selectedProfile) {
    profile = selectedProfile;
    monitorAnimations.clear();
    HKEY key = nullptr;
    if (RegOpenKeyExW(HKEY_CURRENT_USER, RegistryPath(profile), 0, KEY_READ, &key) == ERROR_SUCCESS) {
        ReadMonitorAnimations(key, *this);
        animationMonitorDevice = ReadString(key, ANIMATION_MONITOR_VALUE_NAME);
        selectedAnimationMonitors = ReadString(key, SELECTED_MONITORS_VALUE_NAME);
        const int allSelected = ReadValue(key, ALL_MONITORS_SELECTED_VALUE_NAME, 1);
        allAnimationMonitorsSelected = allSelected != 0;
        controlWindowX = ReadValue(key, CONTROL_WINDOW_X_VALUE_NAME, controlWindowX);
        controlWindowY = ReadValue(key, CONTROL_WINDOW_Y_VALUE_NAME, controlWindowY);
        helpWindowState.x = ReadValue(key, HELP_X_VALUE_NAME, helpWindowState.x);
        helpWindowState.y = ReadValue(key, HELP_Y_VALUE_NAME, helpWindowState.y);
        helpWindowState.width = ReadValue(key, HELP_WIDTH_VALUE_NAME, helpWindowState.width);
        helpWindowState.height = ReadValue(key, HELP_HEIGHT_VALUE_NAME, helpWindowState.height);
        helpWindowState.maximized = ReadValue(key, HELP_MAXIMIZED_VALUE_NAME,
            helpWindowState.maximized ? 1 : 0) != 0;
        aboutWindowState.x = ReadValue(key, ABOUT_X_VALUE_NAME, aboutWindowState.x);
        aboutWindowState.y = ReadValue(key, ABOUT_Y_VALUE_NAME, aboutWindowState.y);
        aboutWindowState.width = ReadValue(key, ABOUT_WIDTH_VALUE_NAME, aboutWindowState.width);
        aboutWindowState.height = ReadValue(key, ABOUT_HEIGHT_VALUE_NAME, aboutWindowState.height);
        aboutWindowState.maximized = ReadValue(key, ABOUT_MAXIMIZED_VALUE_NAME,
            aboutWindowState.maximized ? 1 : 0) != 0;
        recordingSettingsX = ReadValue(key, RECORDING_SETTINGS_X_VALUE_NAME, recordingSettingsX);
        recordingSettingsY = ReadValue(key, RECORDING_SETTINGS_Y_VALUE_NAME, recordingSettingsY);
        language = ReadValue(key, LANGUAGE_VALUE_NAME, language);
        if (profile == SettingsProfile::Standalone) {
            preventScreenSaver =
                ReadValue(key, PREVENT_SCREEN_SAVER_VALUE_NAME, preventScreenSaver ? 1 : 0) == 1;
            recording.television = ReadValue(key, RECORDING_TV_VALUE_NAME, recording.television ? 1 : 0) != 0;
            recording.resolution =
                std::clamp(ReadValue(key, RECORDING_RESOLUTION_VALUE_NAME, recording.resolution), 0, 2);
            recording.rate = std::clamp(ReadValue(key, RECORDING_RATE_VALUE_NAME, recording.rate), 0, 3);
        }
        RegCloseKey(key);
    }
}

/// Writes remembered window positions and selected monitor rows to an already opened settings key.
static void WriteWindowPositions(HKEY key, const AppSettings& settings) {
    const DWORD allSelected = settings.allAnimationMonitorsSelected ? 1U : 0U;
    RegSetValueExW(key, SELECTED_MONITORS_VALUE_NAME, 0, REG_SZ,
        reinterpret_cast<const BYTE*>(settings.selectedAnimationMonitors.c_str()),
        static_cast<DWORD>((settings.selectedAnimationMonitors.size() + 1) * sizeof(wchar_t)));
    RegSetValueExW(key, ALL_MONITORS_SELECTED_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&allSelected), sizeof(allSelected));
    const DWORD windowX = static_cast<DWORD>(settings.controlWindowX);
    const DWORD windowY = static_cast<DWORD>(settings.controlWindowY);
    const DWORD helpX = static_cast<DWORD>(settings.helpWindowState.x);
    const DWORD helpY = static_cast<DWORD>(settings.helpWindowState.y);
    const DWORD helpWidth = static_cast<DWORD>(settings.helpWindowState.width);
    const DWORD helpHeight = static_cast<DWORD>(settings.helpWindowState.height);
    const DWORD helpMaximized = settings.helpWindowState.maximized ? 1U : 0U;
    const DWORD aboutX = static_cast<DWORD>(settings.aboutWindowState.x);
    const DWORD aboutY = static_cast<DWORD>(settings.aboutWindowState.y);
    const DWORD aboutWidth = static_cast<DWORD>(settings.aboutWindowState.width);
    const DWORD aboutHeight = static_cast<DWORD>(settings.aboutWindowState.height);
    const DWORD aboutMaximized = settings.aboutWindowState.maximized ? 1U : 0U;
    const DWORD recordingSettingsX = static_cast<DWORD>(settings.recordingSettingsX);
    const DWORD recordingSettingsY = static_cast<DWORD>(settings.recordingSettingsY);
    RegSetValueExW(key, CONTROL_WINDOW_X_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&windowX), sizeof(windowX));
    RegSetValueExW(key, CONTROL_WINDOW_Y_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&windowY), sizeof(windowY));
    RegSetValueExW(key, HELP_X_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&helpX), sizeof(helpX));
    RegSetValueExW(key, HELP_Y_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&helpY), sizeof(helpY));
    RegSetValueExW(key, HELP_WIDTH_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&helpWidth), sizeof(helpWidth));
    RegSetValueExW(key, HELP_HEIGHT_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&helpHeight), sizeof(helpHeight));
    RegSetValueExW(key, HELP_MAXIMIZED_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&helpMaximized), sizeof(helpMaximized));
    RegSetValueExW(key, ABOUT_X_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&aboutX), sizeof(aboutX));
    RegSetValueExW(key, ABOUT_Y_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&aboutY), sizeof(aboutY));
    RegSetValueExW(key, ABOUT_WIDTH_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&aboutWidth), sizeof(aboutWidth));
    RegSetValueExW(key, ABOUT_HEIGHT_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&aboutHeight), sizeof(aboutHeight));
    RegSetValueExW(key, ABOUT_MAXIMIZED_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&aboutMaximized), sizeof(aboutMaximized));
    RegSetValueExW(key, RECORDING_SETTINGS_X_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&recordingSettingsX), sizeof(recordingSettingsX));
    RegSetValueExW(key, RECORDING_SETTINGS_Y_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&recordingSettingsY), sizeof(recordingSettingsY));
}

/// Saves window positions and selected monitor rows without applying pending animation changes.
void AppSettings::SaveWindowPositions() const {
    HKEY key = nullptr;
    const LSTATUS createResult = RegCreateKeyExW(HKEY_CURRENT_USER, RegistryPath(profile), 0, nullptr, 0,
        KEY_WRITE, nullptr, &key, nullptr);
    if (createResult != ERROR_SUCCESS) {
        return;
    }
    WriteWindowPositions(key, *this);
    RegCloseKey(key);
}

/// Persists the complete settings record in the active profile branch.
void AppSettings::Save() const {
    HKEY key = nullptr;
    const LSTATUS createResult = RegCreateKeyExW(HKEY_CURRENT_USER, RegistryPath(profile), 0, nullptr, 0,
        KEY_WRITE, nullptr, &key, nullptr);
    if (createResult != ERROR_SUCCESS) {
        return;
    }
    RegSetValueExW(key, ANIMATION_MONITOR_VALUE_NAME, 0, REG_SZ,
        reinterpret_cast<const BYTE*>(animationMonitorDevice.c_str()),
        static_cast<DWORD>((animationMonitorDevice.size() + 1) * sizeof(wchar_t)));
    WriteMonitorAnimations(key, *this);
    WriteWindowPositions(key, *this);
    const DWORD languageValue = static_cast<DWORD>(language);
    RegSetValueExW(key, LANGUAGE_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&languageValue), sizeof(languageValue));
    if (profile == SettingsProfile::Standalone) {
        const DWORD preventScreenSaverValue = preventScreenSaver ? 1U : 0U;
        RegSetValueExW(key, PREVENT_SCREEN_SAVER_VALUE_NAME, 0, REG_DWORD,
            reinterpret_cast<const BYTE*>(&preventScreenSaverValue), sizeof(preventScreenSaverValue));
        const DWORD recordingTvValue = recording.television ? 1U : 0U;
        const DWORD recordingResolutionValue = static_cast<DWORD>(recording.resolution);
        const DWORD recordingRateValue = static_cast<DWORD>(recording.rate);
        RegSetValueExW(key, RECORDING_TV_VALUE_NAME, 0, REG_DWORD,
            reinterpret_cast<const BYTE*>(&recordingTvValue), sizeof(recordingTvValue));
        RegSetValueExW(key, RECORDING_RESOLUTION_VALUE_NAME, 0, REG_DWORD,
            reinterpret_cast<const BYTE*>(&recordingResolutionValue), sizeof(recordingResolutionValue));
        RegSetValueExW(key, RECORDING_RATE_VALUE_NAME, 0, REG_DWORD,
            reinterpret_cast<const BYTE*>(&recordingRateValue), sizeof(recordingRateValue));
    }
    RegCloseKey(key);
}
