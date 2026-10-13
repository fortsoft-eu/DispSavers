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

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "AppSettings.h"
#include <windows.h>
#include <algorithm>

/// Registry branches kept deliberately independent between executable modes.
constexpr wchar_t STANDALONE_REGISTRY_PATH[] = L"SOFTWARE\\FortSoft\\FlyingSolids\\Standalone";
constexpr wchar_t SCREEN_SAVER_REGISTRY_PATH[] = L"SOFTWARE\\FortSoft\\FlyingSolids\\ScreenSaver";

/// Registry value names shared by settings loading and saving.
constexpr wchar_t OBJECT_SPEED_VALUE_NAME[] = L"ObjectSpeed";
constexpr wchar_t CAMERA_SPEED_VALUE_NAME[] = L"CameraSpeed";
constexpr wchar_t COPY_COUNT_VALUE_NAME[] = L"CopyCount";
constexpr wchar_t OBJECT_SIZE_VALUE_NAME[] = L"ObjectSize";
constexpr wchar_t CAMERA_FLIGHT_VALUE_NAME[] = L"CameraFlight";
constexpr wchar_t MAIN_LIGHT_VALUE_NAME[] = L"MainLight";
constexpr wchar_t FILL_LIGHT_VALUE_NAME[] = L"FillLight";
constexpr wchar_t AMBIENT_LIGHT_VALUE_NAME[] = L"AmbientLight";
constexpr wchar_t RIM_LIGHT_VALUE_NAME[] = L"RimLight";
constexpr wchar_t ENABLED_SOLIDS_VALUE_NAME[] = L"EnabledSolids";
constexpr wchar_t ANIMATION_MONITOR_VALUE_NAME[] = L"AnimationMonitor";
constexpr wchar_t CONTROL_WINDOW_X_VALUE_NAME[] = L"ControlWindowX";
constexpr wchar_t CONTROL_WINDOW_Y_VALUE_NAME[] = L"ControlWindowY";
constexpr wchar_t HELP_X_VALUE_NAME[] = L"HelpX";
constexpr wchar_t HELP_Y_VALUE_NAME[] = L"HelpY";
constexpr wchar_t ABOUT_X_VALUE_NAME[] = L"AboutX";
constexpr wchar_t ABOUT_Y_VALUE_NAME[] = L"AboutY";
constexpr wchar_t RECORDING_SETTINGS_X_VALUE_NAME[] = L"RecordingSettingsX";
constexpr wchar_t RECORDING_SETTINGS_Y_VALUE_NAME[] = L"RecordingSettingsY";
constexpr wchar_t LANGUAGE_VALUE_NAME[] = L"Language";
constexpr wchar_t PREVENT_SCREEN_SAVER_VALUE_NAME[] = L"PreventScreenSaver";
constexpr wchar_t RECORDING_TV_VALUE_NAME[] = L"RecordingTV";
constexpr wchar_t RECORDING_RESOLUTION_VALUE_NAME[] = L"RecordingResolution";
constexpr wchar_t RECORDING_RATE_VALUE_NAME[] = L"RecordingRate";

/// Returns the registry branch assigned to a settings profile.
static const wchar_t* RegistryPath(SettingsProfile profile) {
    return profile == SettingsProfile::ScreenSaver ? SCREEN_SAVER_REGISTRY_PATH : STANDALONE_REGISTRY_PATH;
}

/// Reads a DWORD value and preserves the supplied default on type or access failure.
static int ReadValue(HKEY key, const wchar_t* name, int fallback) {
    DWORD value = 0;
    DWORD type = 0;
    DWORD size = sizeof(value);
    const LSTATUS queryResult = RegQueryValueExW(key, name, nullptr, &type, reinterpret_cast<BYTE*>(&value), &size);
    if (queryResult == ERROR_SUCCESS && type == REG_DWORD) {
        return static_cast<int>(value);
    }
    return fallback;
}

/// Reads a null-terminated string and removes padding returned by the registry API.
static std::wstring ReadString(HKEY key, const wchar_t* name) {
    DWORD type = 0;
    DWORD size = 0;
    const LSTATUS queryResult = RegQueryValueExW(key, name, nullptr, &type, nullptr, &size);
    if (queryResult != ERROR_SUCCESS || type != REG_SZ && type != REG_EXPAND_SZ || size < sizeof(wchar_t)) {
        return std::wstring{};
    }
    std::wstring value(size / sizeof(wchar_t), L'\0');
    if (RegQueryValueExW(key, name, nullptr, &type, reinterpret_cast<BYTE*>(value.data()), &size) != ERROR_SUCCESS) {
        return std::wstring{};
    }
    while (!value.empty() && value.back() == L'\0') {
        value.pop_back();
    }
    return value;
}

/// Loads and validates settings from the selected registry profile.
void AppSettings::Load(SettingsProfile selectedProfile) {
    profile = selectedProfile;
    HKEY key = nullptr;
    if (RegOpenKeyExW(HKEY_CURRENT_USER, RegistryPath(profile), 0, KEY_READ, &key) == ERROR_SUCCESS) {
        objectSpeedPercent = ReadValue(key, OBJECT_SPEED_VALUE_NAME, objectSpeedPercent);
        cameraSpeedPercent = ReadValue(key, CAMERA_SPEED_VALUE_NAME, cameraSpeedPercent);
        copyCount = ReadValue(key, COPY_COUNT_VALUE_NAME, copyCount);
        objectSizePercent = ReadValue(key, OBJECT_SIZE_VALUE_NAME, objectSizePercent);
        cameraFlight = ReadValue(key, CAMERA_FLIGHT_VALUE_NAME, cameraFlight ? 1 : 0) != 0;
        mainLight = ReadValue(key, MAIN_LIGHT_VALUE_NAME, mainLight ? 1 : 0) != 0;
        fillLight = ReadValue(key, FILL_LIGHT_VALUE_NAME, fillLight ? 1 : 0) != 0;
        ambientLight = ReadValue(key, AMBIENT_LIGHT_VALUE_NAME, ambientLight ? 1 : 0) != 0;
        rimLight = ReadValue(key, RIM_LIGHT_VALUE_NAME, rimLight ? 1 : 0) != 0;
        enabledSolids = static_cast<std::uint32_t>(ReadValue(key, ENABLED_SOLIDS_VALUE_NAME,
            static_cast<int>(enabledSolids))) & ALL_SOLID_MASK;
        animationMonitorDevice = ReadString(key, ANIMATION_MONITOR_VALUE_NAME);
        controlWindowX = ReadValue(key, CONTROL_WINDOW_X_VALUE_NAME, controlWindowX);
        controlWindowY = ReadValue(key, CONTROL_WINDOW_Y_VALUE_NAME, controlWindowY);
        helpX = ReadValue(key, HELP_X_VALUE_NAME, helpX);
        helpY = ReadValue(key, HELP_Y_VALUE_NAME, helpY);
        aboutX = ReadValue(key, ABOUT_X_VALUE_NAME, aboutX);
        aboutY = ReadValue(key, ABOUT_Y_VALUE_NAME, aboutY);
        recordingSettingsX = ReadValue(key, RECORDING_SETTINGS_X_VALUE_NAME, recordingSettingsX);
        recordingSettingsY = ReadValue(key, RECORDING_SETTINGS_Y_VALUE_NAME, recordingSettingsY);
        language = ReadValue(key, LANGUAGE_VALUE_NAME, language);
        if (profile == SettingsProfile::Standalone) {
            preventScreenSaver = ReadValue(key, PREVENT_SCREEN_SAVER_VALUE_NAME, preventScreenSaver ? 1 : 0) != 0;
            recording.television = ReadValue(key, RECORDING_TV_VALUE_NAME, recording.television ? 1 : 0) != 0;
            recording.resolution = std::clamp(ReadValue(key, RECORDING_RESOLUTION_VALUE_NAME, recording.resolution), 0, 2);
            recording.rate = std::clamp(ReadValue(key, RECORDING_RATE_VALUE_NAME, recording.rate), 0, 3);
        }
        RegCloseKey(key);
    }
    objectSpeedPercent = std::clamp(objectSpeedPercent, 0, 1600);
    cameraSpeedPercent = std::clamp(cameraSpeedPercent, 0, 1600);
    copyCount = std::clamp(copyCount, 1, static_cast<int>(MAX_COPIES_PER_SOLID));
    objectSizePercent = std::clamp(objectSizePercent, 50, 200);
}

/// Writes control, Help, About and recording-settings coordinates to an already opened settings key.
static void WriteWindowPositions(HKEY key, const AppSettings& settings) {
    const DWORD windowX = static_cast<DWORD>(settings.controlWindowX);
    const DWORD windowY = static_cast<DWORD>(settings.controlWindowY);
    const DWORD helpX = static_cast<DWORD>(settings.helpX);
    const DWORD helpY = static_cast<DWORD>(settings.helpY);
    const DWORD aboutX = static_cast<DWORD>(settings.aboutX);
    const DWORD aboutY = static_cast<DWORD>(settings.aboutY);
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
    RegSetValueExW(key, ABOUT_X_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&aboutX), sizeof(aboutX));
    RegSetValueExW(key, ABOUT_Y_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&aboutY), sizeof(aboutY));
    RegSetValueExW(key, RECORDING_SETTINGS_X_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&recordingSettingsX), sizeof(recordingSettingsX));
    RegSetValueExW(key, RECORDING_SETTINGS_Y_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&recordingSettingsY), sizeof(recordingSettingsY));
}

/// Saves remembered form coordinates without applying pending animation changes.
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
    const DWORD objectSpeed = static_cast<DWORD>(objectSpeedPercent);
    const DWORD cameraSpeed = static_cast<DWORD>(cameraSpeedPercent);
    const DWORD copyCountValue = static_cast<DWORD>(copyCount);
    const DWORD objectSizeValue = static_cast<DWORD>(objectSizePercent);
    const DWORD cameraFlightValue = cameraFlight ? 1U : 0U;
    const DWORD mainLightValue = mainLight ? 1U : 0U;
    const DWORD fillLightValue = fillLight ? 1U : 0U;
    const DWORD ambientLightValue = ambientLight ? 1U : 0U;
    const DWORD rimLightValue = rimLight ? 1U : 0U;
    const DWORD enabledSolidsValue = enabledSolids & ALL_SOLID_MASK;
    RegSetValueExW(key, OBJECT_SPEED_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&objectSpeed), sizeof(objectSpeed));
    RegSetValueExW(key, CAMERA_SPEED_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&cameraSpeed), sizeof(cameraSpeed));
    RegSetValueExW(key, COPY_COUNT_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&copyCountValue), sizeof(copyCountValue));
    RegSetValueExW(key, OBJECT_SIZE_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&objectSizeValue), sizeof(objectSizeValue));
    RegSetValueExW(key, CAMERA_FLIGHT_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&cameraFlightValue), sizeof(cameraFlightValue));
    RegSetValueExW(key, MAIN_LIGHT_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&mainLightValue), sizeof(mainLightValue));
    RegSetValueExW(key, FILL_LIGHT_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&fillLightValue), sizeof(fillLightValue));
    RegSetValueExW(key, AMBIENT_LIGHT_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&ambientLightValue), sizeof(ambientLightValue));
    RegSetValueExW(key, RIM_LIGHT_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&rimLightValue), sizeof(rimLightValue));
    RegSetValueExW(key, ENABLED_SOLIDS_VALUE_NAME, 0, REG_DWORD,
        reinterpret_cast<const BYTE*>(&enabledSolidsValue), sizeof(enabledSolidsValue));
    RegSetValueExW(key, ANIMATION_MONITOR_VALUE_NAME, 0, REG_SZ,
        reinterpret_cast<const BYTE*>(animationMonitorDevice.c_str()),
        static_cast<DWORD>((animationMonitorDevice.size() + 1) * sizeof(wchar_t)));
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
