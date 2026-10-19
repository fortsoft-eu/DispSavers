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

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "AppSettings.h"
#include <windows.h>
#include <algorithm>
#include <array>
#include <stdexcept>

/// Registry branches kept deliberately independent between executable modes.
constexpr wchar_t STANDALONE_REGISTRY_PATH[] = L"SOFTWARE\\FortSoft\\FlyingSolids\\Standalone";
constexpr wchar_t SCREEN_SAVER_REGISTRY_PATH[] = L"SOFTWARE\\FortSoft\\FlyingSolids\\ScreenSaver";

/// Registry value names shared by settings loading and saving.
constexpr wchar_t MONITOR_SETTINGS_KEY[] = L"Monitors";
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

/// Versioned DWORD sequence, independent of compiler padding and native bool representation.
constexpr DWORD MONITOR_SETTINGS_VERSION = 1;
using MonitorSettingsRecord = std::array<DWORD, 1 + static_cast<std::size_t>(AnimationProperty::Count)>;

/// Returns the registry branch assigned to a settings profile.
static const wchar_t* RegistryPath(SettingsProfile profile) {
    return profile == SettingsProfile::ScreenSaver ? SCREEN_SAVER_REGISTRY_PATH : STANDALONE_REGISTRY_PATH;
}

/// Reads a DWORD value and preserves the supplied default on type or access failure.
static int ReadValue(HKEY key, const wchar_t* name, int defaultValue) {
    DWORD value = 0;
    DWORD type = 0;
    DWORD size = sizeof(value);
    const LSTATUS queryResult = RegQueryValueExW(key, name, nullptr, &type, reinterpret_cast<BYTE*>(&value), &size);
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

/// Reads one property using the same identifiers as persistence and multi-monitor editing.
std::uint32_t MonitorAnimation::Value(AnimationProperty property) const {
    switch (property) {
        case AnimationProperty::ObjectSpeed: return objectSpeedPercent;
        case AnimationProperty::CameraSpeed: return cameraSpeedPercent;
        case AnimationProperty::CopyCount: return copyCount;
        case AnimationProperty::ObjectSize: return objectSizePercent;
        case AnimationProperty::CameraFlight: return cameraFlight;
        case AnimationProperty::MainLight: return mainLight;
        case AnimationProperty::FillLight: return fillLight;
        case AnimationProperty::AmbientLight: return ambientLight;
        case AnimationProperty::RimLight: return rimLight;
        case AnimationProperty::EnabledSolids: return enabledSolids;
        case AnimationProperty::PreventScreenSaver: return preventScreenSaver;
        default: throw std::invalid_argument("Unknown animation property");
    }
}

/// Validates one property without overwriting independent preferences.
void MonitorAnimation::SetValue(AnimationProperty property, std::uint32_t value) {
    switch (property) {
        case AnimationProperty::ObjectSpeed:
            objectSpeedPercent = static_cast<int>(std::min(value, 1600U));
            break;
        case AnimationProperty::CameraSpeed:
            cameraSpeedPercent = static_cast<int>(std::min(value, 1600U));
            break;
        case AnimationProperty::CopyCount:
            copyCount = static_cast<int>(std::clamp(value, 1U, static_cast<unsigned>(MAX_COPIES_PER_SOLID)));
            break;
        case AnimationProperty::ObjectSize:
            objectSizePercent = static_cast<int>(std::clamp(value, 50U, 200U));
            break;
        case AnimationProperty::CameraFlight:
            cameraFlight = value != 0;
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
        case AnimationProperty::EnabledSolids:
            enabledSolids = value & ALL_SOLID_MASK;
            break;
        case AnimationProperty::PreventScreenSaver:
            preventScreenSaver = value != 0;
            break;
        default:
            throw std::invalid_argument("Unknown animation property");
    }
}

/// Reports whether selected monitors have different values of the requested property.
bool MonitorSelection::IsMixed(AnimationProperty property) const {
    return (mixedProperties & 1U << static_cast<unsigned>(property)) != 0;
}

/// Initializes each new display with its own built-in settings, preserving saved records.
void AppSettings::InitializeMonitorAnimations(const std::vector<std::wstring>& devices) {
    for (const std::wstring& device : devices) {
        monitorAnimations.try_emplace(device);
    }
}

/// Looks up all animation preferences by device identity, independent of monitor order or selection.
MonitorAnimation& AppSettings::AnimationForMonitor(const std::wstring& device) {
    return monitorAnimations.try_emplace(device).first->second;
}

/// Reports differing values without substituting values from unselected monitors.
MonitorSelection AppSettings::SelectionForMonitors(const std::vector<std::wstring>& devices) {
    MonitorSelection result;
    for (const std::wstring& device : devices) {
        const MonitorAnimation& animation = AnimationForMonitor(device);
        if (!result.available) {
            result.values = animation;
            result.available = true;
            continue;
        }
        result.mixedSolids |= result.values.enabledSolids ^ animation.enabledSolids;
        for (unsigned index = 0; index < static_cast<unsigned>(AnimationProperty::Count); index++) {
            const AnimationProperty property = static_cast<AnimationProperty>(index);
            if (result.values.Value(property) != animation.Value(property)) {
                result.mixedProperties |= 1U << index;
            }
        }
    }
    return result;
}

void AppSettings::SetMonitorValue(const std::vector<std::wstring>& devices, AnimationProperty property,
        std::uint32_t value) {
    for (const std::wstring& device : devices) {
        AnimationForMonitor(device).SetValue(property, value);
    }
}

void AppSettings::SetMonitorSolid(const std::vector<std::wstring>& devices, unsigned index, bool enabled) {
    if (index >= SOLID_COUNT) {
        return;
    }
    for (const std::wstring& device : devices) {
        MonitorAnimation& animation = AnimationForMonitor(device);
        if (enabled) {
            animation.enabledSolids |= 1U << index;
        } else {
            animation.enabledSolids &= ~(1U << index);
        }
    }
}

/// Rejects the entire record rather than repairing individual values or trying an older format.
static bool ValidMonitorSettingsRecord(const MonitorSettingsRecord& value) {
    if (value[0] != MONITOR_SETTINGS_VERSION) {
        return false;
    }
    for (std::size_t index = 1; index < value.size(); index++) {
        const AnimationProperty property = static_cast<AnimationProperty>(index - 1);
        const DWORD setting = value[index];
        switch (property) {
            case AnimationProperty::ObjectSpeed:
            case AnimationProperty::CameraSpeed:
                if (setting > 1600U) {
                    return false;
                }
                break;
            case AnimationProperty::CopyCount:
                if (setting < 1U || setting > MAX_COPIES_PER_SOLID) {
                    return false;
                }
                break;
            case AnimationProperty::ObjectSize:
                if (setting < 50U || setting > 200U) {
                    return false;
                }
                break;
            case AnimationProperty::EnabledSolids:
                if ((setting & ~ALL_SOLID_MASK) != 0) {
                    return false;
                }
                break;
            default:
                if (setting > 1U) {
                    return false;
                }
                break;
        }
    }
    return true;
}

/// Reads only complete records in the current format; rejects legacy and malformed values.
static void ReadMonitorAnimations(HKEY profile, AppSettings& settings) {
    HKEY key = nullptr;
    if (RegOpenKeyExW(profile, MONITOR_SETTINGS_KEY, 0, KEY_READ, &key) != ERROR_SUCCESS) {
        return;
    }
    DWORD maximumNameLength = 0;
    const LSTATUS infoResult = RegQueryInfoKeyW(key, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
        &maximumNameLength, nullptr, nullptr, nullptr);
    if (infoResult == ERROR_SUCCESS && maximumNameLength < 32768U) {
        std::vector<wchar_t> name(static_cast<std::size_t>(maximumNameLength) + 1);
        for (DWORD index = 0; ; index++) {
            DWORD length = static_cast<DWORD>(name.size());
            DWORD type = 0;
            MonitorSettingsRecord value{};
            DWORD size = sizeof(value);
            const LSTATUS result = RegEnumValueW(key, index, name.data(), &length, nullptr, &type,
                reinterpret_cast<BYTE*>(value.data()), &size);
            if (result == ERROR_NO_MORE_ITEMS) {
                break;
            }
            if (result == ERROR_SUCCESS && length != 0) {
                if (type != REG_BINARY || size != sizeof(value) || !ValidMonitorSettingsRecord(value)) {
                    continue;
                }
                MonitorAnimation animation;
                for (std::size_t property = 0; property < value.size() - 1; property++) {
                    animation.SetValue(static_cast<AnimationProperty>(property), value[property + 1]);
                }
                settings.monitorAnimations.emplace(std::wstring(name.data(), length), animation);
            } else if (result != ERROR_SUCCESS && result != ERROR_MORE_DATA) {
                break;
            }
        }
    }
    RegCloseKey(key);
}

/// Preserves preferences for temporarily disconnected displays when writing complete animation records.
static void WriteMonitorAnimations(HKEY profile, const AppSettings& settings) {
    HKEY key = nullptr;
    const LSTATUS createResult = RegCreateKeyExW(profile, MONITOR_SETTINGS_KEY, 0, nullptr, 0, KEY_WRITE, nullptr,
        &key, nullptr);
    if (createResult != ERROR_SUCCESS) {
        return;
    }
    for (const auto& entry : settings.monitorAnimations) {
        MonitorSettingsRecord value{};
        value[0] = MONITOR_SETTINGS_VERSION;
        for (std::size_t property = 0; property < value.size() - 1; property++) {
            value[property + 1] = entry.second.Value(static_cast<AnimationProperty>(property));
        }
        RegSetValueExW(key, entry.first.c_str(), 0, REG_BINARY, reinterpret_cast<const BYTE*>(value.data()),
            sizeof(value));
    }
    RegCloseKey(key);
}

/// Loads and validates settings from the selected registry profile.
void AppSettings::Load(SettingsProfile selectedProfile) {
    profile = selectedProfile;
    monitorAnimations.clear();
    HKEY key = nullptr;
    if (RegOpenKeyExW(HKEY_CURRENT_USER, RegistryPath(profile), 0, KEY_READ, &key) == ERROR_SUCCESS) {
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
            recording.television = ReadValue(key, RECORDING_TV_VALUE_NAME, recording.television ? 1 : 0) != 0;
            recording.resolution = std::clamp(ReadValue(key, RECORDING_RESOLUTION_VALUE_NAME, recording.resolution), 0, 2);
            recording.rate = std::clamp(ReadValue(key, RECORDING_RATE_VALUE_NAME, recording.rate), 0, 3);
        }
        ReadMonitorAnimations(key, *this);
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
    const LSTATUS createResult =
        RegCreateKeyExW(HKEY_CURRENT_USER, RegistryPath(profile), 0, nullptr, 0, KEY_WRITE, nullptr, &key, nullptr);
    if (createResult != ERROR_SUCCESS) {
        return;
    }
    WriteWindowPositions(key, *this);
    RegCloseKey(key);
}

/// Persists the complete settings record in the active profile branch.
void AppSettings::Save() const {
    HKEY key = nullptr;
    const LSTATUS createResult =
        RegCreateKeyExW(HKEY_CURRENT_USER, RegistryPath(profile), 0, nullptr, 0, KEY_WRITE, nullptr, &key, nullptr);
    if (createResult != ERROR_SUCCESS) {
        return;
    }
    RegSetValueExW(key, ANIMATION_MONITOR_VALUE_NAME, 0, REG_SZ,
        reinterpret_cast<const BYTE*>(animationMonitorDevice.c_str()),
        static_cast<DWORD>((animationMonitorDevice.size() + 1) * sizeof(wchar_t)));
    WriteWindowPositions(key, *this);
    WriteMonitorAnimations(key, *this);
    const DWORD languageValue = static_cast<DWORD>(language);
    RegSetValueExW(key, LANGUAGE_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&languageValue), sizeof(languageValue));
    if (profile == SettingsProfile::Standalone) {
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
