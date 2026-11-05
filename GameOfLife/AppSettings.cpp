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

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "AppSettings.h"
#include "Localization.h"
#include <algorithm>
#include <utility>
#include <cwchar>
#include <string>

#pragma comment(lib, "advapi32.lib")

/// Registry branches kept deliberately independent between executable modes.
constexpr wchar_t STANDALONE_REGISTRY_PATH[] = L"Software\\FortSoft\\GameOfLife\\Standalone";
constexpr wchar_t SCREEN_SAVER_REGISTRY_PATH[] = L"Software\\FortSoft\\GameOfLife\\ScreenSaver";

/// Returns the registry branch assigned to a settings profile.
static const wchar_t* RegistryPath(SettingsProfile profile) {
    return profile == SettingsProfile::ScreenSaver ? SCREEN_SAVER_REGISTRY_PATH : STANDALONE_REGISTRY_PATH;
}

/// Reads a DWORD using the requested value type and preserves the default on type or access failure.
template<typename Value>
static Value ReadValue(HKEY key, const wchar_t* name, Value defaultValue) {
    DWORD value = 0;
    DWORD type = 0;
    DWORD size = sizeof(value);
    const LSTATUS queryResult =
        RegQueryValueExW(key, name, nullptr, &type, reinterpret_cast<BYTE*>(&value), &size);
    if (queryResult == ERROR_SUCCESS && type == REG_DWORD && size == sizeof(value)) {
        return static_cast<Value>(value);
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
    const LSTATUS readResult =
        RegQueryValueExW(key, name, nullptr, &type, reinterpret_cast<BYTE*>(value.data()), &size);
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

/// Writes one preference as a registry DWORD.
static void WriteValue(HKEY key, const wchar_t* name, DWORD value) {
    RegSetValueExW(key, name, 0, REG_DWORD, reinterpret_cast<const BYTE*>(&value), sizeof(value));
}

/// Reads prefixed position, size and maximized values into the supplied window state.
static void ReadWindowState(HKEY key, const wchar_t* prefix, PersistWindowStateData& state) {
    const std::wstring name = prefix;
    state.x = ReadValue<int>(key, (name + L"X").c_str(), state.x);
    state.y = ReadValue<int>(key, (name + L"Y").c_str(), state.y);
    state.width = ReadValue<int>(key, (name + L"Width").c_str(), state.width);
    state.height = ReadValue<int>(key, (name + L"Height").c_str(), state.height);
    state.maximized = ReadValue<int>(key, (name + L"Maximized").c_str(), state.maximized ? 1 : 0) != 0;
}

/// Writes the prefixed position, size and maximized fields of one stored window state.
static void WriteWindowState(HKEY key, const wchar_t* prefix, const PersistWindowStateData& state) {
    const std::wstring name = prefix;
    WriteValue(key, (name + L"X").c_str(), static_cast<DWORD>(state.x));
    WriteValue(key, (name + L"Y").c_str(), static_cast<DWORD>(state.y));
    WriteValue(key, (name + L"Width").c_str(), static_cast<DWORD>(state.width));
    WriteValue(key, (name + L"Height").c_str(), static_cast<DWORD>(state.height));
    WriteValue(key, (name + L"Maximized").c_str(), state.maximized ? 1U : 0U);
}

/// Writes recording, Help and About placement values without writing scene preferences.
static void WriteWindowPositions(HKEY key, const AppSettings& settings) {
    WriteValue(key, L"RecordingSettingsX", static_cast<DWORD>(settings.recordingSettingsX));
    WriteValue(key, L"RecordingSettingsY", static_cast<DWORD>(settings.recordingSettingsY));
    WriteWindowState(key, L"Help", settings.helpWindowState);
    WriteWindowState(key, L"About", settings.aboutWindowState);
}

/// Loads auxiliary-window placement independently of animation preferences.
static void ReadWindowPositions(HKEY key, AppSettings& settings) {
    settings.recordingSettingsX = ReadValue<int>(key, L"RecordingSettingsX", settings.recordingSettingsX);
    settings.recordingSettingsY = ReadValue<int>(key, L"RecordingSettingsY", settings.recordingSettingsY);
    ReadWindowState(key, L"Help", settings.helpWindowState);
    ReadWindowState(key, L"About", settings.aboutWindowState);
}

/// Loads and validates the selected profile while retaining defaults for missing values.
void AppSettings::Load(SettingsProfile selectedProfile) {
    profile = selectedProfile;
    HKEY key = nullptr;
    if (RegOpenKeyExW(HKEY_CURRENT_USER, RegistryPath(profile), 0, KEY_READ, &key) != ERROR_SUCCESS) {
        return;
    }
    animationMonitorDevice = ReadString(key, L"AnimationMonitor");
    std::replace(animationMonitorDevice.begin(), animationMonitorDevice.end(), L'|', L';');
    patternId = ReadString(key, L"PatternId");
    cellSize = std::clamp(ReadValue<DWORD>(key, L"CellSize", cellSize), 1UL, 64UL);
    generationsPerSecond =
        std::min(ReadValue<DWORD>(key, L"GenerationsPerSecond", generationsPerSecond), 240UL);
    densityPercent = std::min(ReadValue<DWORD>(key, L"DensityPercent", densityPercent), 100UL);
    aliveColor = ReadValue<DWORD>(key, L"AliveColor", aliveColor) & 0xFFFFFF;
    backgroundColor = ReadValue<DWORD>(key, L"BackgroundColor", backgroundColor) & 0xFFFFFF;
    gridColor = ReadValue<DWORD>(key, L"GridColor", gridColor) & 0xFFFFFF;
    showGrid = ReadValue<DWORD>(key, L"ShowGrid", showGrid ? 1U : 0U) != 0;
    cellSize = std::max(cellSize, showGrid ? 2U : 1U);
    autoReset = ReadValue<DWORD>(key, L"AutoReset", autoReset ? 1U : 0U) != 0;
    randomAliveColor = ReadValue<DWORD>(key, L"RandomAliveColor", randomAliveColor ? 1U : 0U) != 0;
    randomBackgroundColor =
        ReadValue<DWORD>(key, L"RandomBackgroundColor", randomBackgroundColor ? 1U : 0U) != 0;
    randomGridColor = ReadValue<DWORD>(key, L"RandomGridColor", randomGridColor ? 1U : 0U) != 0;
    if (profile == SettingsProfile::Standalone) {
        preventScreenSaver = ReadValue<DWORD>(key, L"PreventScreenSaver", preventScreenSaver ? 1U : 0U) != 0;
    }
    patternsOnly = ReadValue<DWORD>(key, L"PatternsOnly", patternsOnly ? 1U : 0U) != 0;
    recording.television = ReadValue<DWORD>(key, L"RecordingTV", recording.television ? 1U : 0U) != 0;
    recording.resolution = static_cast<int>(std::min(ReadValue<DWORD>(key, L"RecordingResolution",
        recording.resolution), 2UL));
    recording.rate = static_cast<int>(std::min(ReadValue<DWORD>(key, L"RecordingRate", recording.rate), 3UL));
    language = static_cast<int>(ReadValue<DWORD>(key, L"Language", static_cast<DWORD>(language)));
    if (language < -1 || language >= LANG_COUNT) {
        language = -1;
    }
    ReadWindowPositions(key, *this);
    RegCloseKey(key);
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

/// Writes the current preferences and stored auxiliary-window positions to the selected profile.
void AppSettings::Save() const {
    HKEY key = nullptr;
    const LSTATUS createResult = RegCreateKeyExW(HKEY_CURRENT_USER, RegistryPath(profile), 0, nullptr, 0,
        KEY_WRITE, nullptr, &key, nullptr);
    if (createResult != ERROR_SUCCESS) {
        return;
    }
    RegSetValueExW(key, L"AnimationMonitor", 0, REG_SZ,
        reinterpret_cast<const BYTE*>(animationMonitorDevice.c_str()),
        static_cast<DWORD>((animationMonitorDevice.size() + 1) * sizeof(wchar_t)));
    RegSetValueExW(key, L"PatternId", 0, REG_SZ,
        reinterpret_cast<const BYTE*>(patternId.c_str()),
        static_cast<DWORD>((patternId.size() + 1) * sizeof(wchar_t)));
    WriteValue(key, L"CellSize", cellSize);
    WriteValue(key, L"GenerationsPerSecond", generationsPerSecond);
    WriteValue(key, L"DensityPercent", densityPercent);
    WriteValue(key, L"AliveColor", aliveColor);
    WriteValue(key, L"BackgroundColor", backgroundColor);
    WriteValue(key, L"GridColor", gridColor);
    WriteValue(key, L"ShowGrid", showGrid ? 1U : 0U);
    WriteValue(key, L"AutoReset", autoReset ? 1U : 0U);
    WriteValue(key, L"RandomAliveColor", randomAliveColor ? 1U : 0U);
    WriteValue(key, L"RandomBackgroundColor", randomBackgroundColor ? 1U : 0U);
    WriteValue(key, L"RandomGridColor", randomGridColor ? 1U : 0U);
    if (profile == SettingsProfile::Standalone) {
        WriteValue(key, L"PreventScreenSaver", preventScreenSaver ? 1U : 0U);
    }
    WriteValue(key, L"PatternsOnly", patternsOnly ? 1U : 0U);
    WriteValue(key, L"RecordingTV", recording.television ? 1U : 0U);
    WriteValue(key, L"RecordingResolution", static_cast<DWORD>(recording.resolution));
    WriteValue(key, L"RecordingRate", static_cast<DWORD>(recording.rate));
    WriteValue(key, L"Language", static_cast<DWORD>(language));
    WriteWindowPositions(key, *this);
    RegCloseKey(key);
}

/// Restores only the three slider values and the three configured colors.
void AppSettings::ResetValues() {
    const AppSettings defaults;
    cellSize = defaults.cellSize + static_cast<unsigned>(showGrid);
    generationsPerSecond = defaults.generationsPerSecond;
    densityPercent = defaults.densityPercent;
    aliveColor = defaults.aliveColor;
    backgroundColor = defaults.backgroundColor;
    gridColor = defaults.gridColor;
}
