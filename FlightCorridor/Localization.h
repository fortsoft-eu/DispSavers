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
 * Last modified for version 1.2.2.1
 */

#pragma once

#include "Effects.h"
#include <array>
#include <initializer_list>

/// Append new languages before LANG_COUNT to preserve existing stored identifiers.
enum AppLanguage {
    LANG_CS,
    LANG_EN_US,
    LANG_EN_GB,
    LANG_EN_AU,
    LANG_DE,
    LANG_FR,
    LANG_ES,
    LANG_IT,
    LANG_PT,
    LANG_PL,
    LANG_SK,
    LANG_DA,
    LANG_FI,
    LANG_IS,
    LANG_NB,
    LANG_SV,
    LANG_TR,
    LANG_ET,
    LANG_GA,
    LANG_LT,
    LANG_LV,
    LANG_HU,
    LANG_MT,
    LANG_NL,
    LANG_RO,
    LANG_EL,
    LANG_BS,
    LANG_HR,
    LANG_SL,
    LANG_CNR,
    LANG_BE,
    LANG_BG,
    LANG_MK,
    LANG_SR,
    LANG_UK,
    LANG_RU,
    LANG_COUNT
};

/// Named translation keys used by this application.
enum TextId {
    TXT_LANGUAGE_NAME,
    TXT_CONTROL_TITLE,
    TXT_SETTINGS_TITLE,
    TXT_LANGUAGE,
    TXT_OBJECT_SPEED,
    TXT_FLIGHT_EFFECTS,
    TXT_ENABLE_ALL,
    TXT_DISABLE_ALL,
    TXT_ANIMATION_MONITOR,
    TXT_MONITOR,
    TXT_RESOLUTION,
    TXT_POSITION,
    TXT_PRIMARY,
    TXT_OK,
    TXT_CANCEL,
    TXT_START_RECORDING,
    TXT_STOP_RECORDING,
    TXT_PAUSE,
    TXT_RESUME,
    TXT_INSTALL_SCREEN_SAVER,
    TXT_EXIT,
    TXT_ANIMATION_RUNNING,
    TXT_RECORDING,
    TXT_RECORDING_SAVED,
    TXT_RECORDING_FAILED,
    TXT_INSTALLATION_FAILED,
    TXT_INSTALLATION_SUCCEEDED,
    TXT_RENDERER_FAILED,
    TXT_EFFECT_CORRIDOR,
    TXT_EFFECT_FUNNEL,
    TXT_RECORDING_CLOSE_WARNING,
    TXT_ABOUT_VISIT_TOOLTIP,
    TXT_ABOUT_WEBSITE_FAILED,
    TXT_ABOUT_COPY_URL_FAILED,
    TXT_ABOUT_COPY_INFORMATION_FAILED,
    TXT_ENABLE_PREVIEW,
    TXT_DISABLE_PREVIEW,
    TXT_PAUSED_STATUS,
    TXT_PREVENT_SCREEN_SAVER,
    TXT_READY_STATUS,
    TXT_HELP,
    TXT_ABOUT,
    TXT_CLOSE,
    TXT_SNAPSHOT,
    TXT_SNAPSHOT_SAVED,
    TXT_SNAPSHOT_FAILED,
    TXT_UNINSTALL_SCREEN_SAVER,
    TXT_UNINSTALLATION_SUCCEEDED,
    TXT_UNINSTALLATION_FAILED,
    TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
    TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
    TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
    TXT_ABOUT_DESCRIPTION,
    TXT_ABOUT_VERSION_LABEL,
    TXT_ABOUT_PLATFORM_LABEL,
    TXT_ABOUT_WEBSITE_LABEL,
    TXT_OPEN_IN_BROWSER,
    TXT_COPY_URL,
    TXT_COPY_INFORMATION,
    TXT_MAIN_LIGHT,
    TXT_FILL_LIGHT,
    TXT_AMBIENT_LIGHT,
    TXT_RIM_LIGHT,
    TXT_FILLED_SURFACE,
    TXT_CAMERA_TUMBLING,
    TXT_CAMERA_REVERSALS,
    TXT_ABOUT_LICENSE_UNAVAILABLE,
    TXT_MONITOR_COLUMN_MODEL,
    TXT_MONITOR_COLUMN_REFRESH_RATE,
    TXT_MONITOR_COLUMN_BIT_DEPTH,
    TXT_MONITOR_COLUMN_COLOR_FORMAT,
    TXT_MONITOR_COLUMN_COLOR_SPACE,
    TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
    TXT_MONITOR_PIXEL_DEPTH_FORMAT,
    TXT_RECORDING_SETTINGS_TITLE,
    TXT_RECORDING_SETTINGS_VIEWPORT,
    TXT_RECORDING_SETTINGS_TELEVISION,
    TXT_RECORDING_SETTINGS_RESOLUTION,
    TXT_RECORDING_SETTINGS_FRAME_RATE,
    TXT_RECORDING_SETTINGS_NOTE,
    TXT_APPLICATION_HELP,
    TXT_SCREEN_SAVER_HELP,
    TXT_COUNT
};

/// Associates one immutable translation with its named text key during compilation.
struct LocalizedText {
    TextId id;
    const wchar_t* text;
};

/// Associates a complete translation table with one existing application language identifier.
struct LocalizedLanguage {
    AppLanguage id;
    const wchar_t* texts[TXT_COUNT];
};

/// Localized monitor-detail column captions and bit-depth formats.
struct MonitorColumnText {
    const wchar_t* model;
    const wchar_t* refreshRate;
    const wchar_t* bitDepth;
    const wchar_t* colorFormat;
    const wchar_t* colorSpace;
    const wchar_t* channelDepth;
    const wchar_t* pixelDepth;
};

/// Maps animation kinds to their named translation keys.
inline constexpr TextId EFFECT_TEXT_IDS[] = {
    TXT_EFFECT_CORRIDOR,
    TXT_EFFECT_FUNNEL,
};

static_assert(std::size(EFFECT_TEXT_IDS) == EFFECT_COUNT);

/// Returns a borrowed, immutable translation identified by the language enum and a named text key.
const wchar_t* GetLocalizedText(AppLanguage language, TextId id);

/// Returns localized monitor-detail column captions and bit-depth formats.
MonitorColumnText MonitorColumnsText(AppLanguage language);

/// Maps the current user's Windows UI language to a supported language.
AppLanguage DetectSystemLanguage();

/// Replaces an invalid persisted language value with the application default.
AppLanguage NormalizeLanguage(int language);

/// Returns one of the three language-independent TV resolution captions.
const wchar_t* RecordingResolutionText(unsigned index);

/// Returns one of the four language-independent exact TV frame-rate captions.
const wchar_t* RecordingRateText(unsigned index);

/// Builds one language at compile time and rejects missing, duplicate, empty, or invalid text entries.
consteval LocalizedLanguage DefineLanguage(AppLanguage language, std::initializer_list<LocalizedText> entries) {
    if (entries.size() != TXT_COUNT) {
        throw "Every language must define every TextId exactly once.";
    }
    LocalizedLanguage result = { language, {} };
    for (const LocalizedText& entry : entries) {
        int id = static_cast<int>(entry.id);
        if (id < 0 || id >= TXT_COUNT) {
            throw "Invalid translation TextId.";
        }
        if (entry.text == nullptr || entry.text[0] == L'\0') {
            throw "A translation cannot be null or empty.";
        }
        if (result.texts[id] != nullptr) {
            throw "Duplicate translation TextId.";
        }
        result.texts[id] = entry.text;
    }
    return result;
}

/// Indexes complete languages by AppLanguage at compile time, independently of their source order.
/// Rejects missing, duplicate, or invalid language identifiers before any executable can be produced.
consteval std::array<LocalizedLanguage, LANG_COUNT> DefineLocalization(
        std::initializer_list<LocalizedLanguage> languages) {
    if (languages.size() != LANG_COUNT) {
        throw "Every AppLanguage must have a complete translation table.";
    }
    std::array<LocalizedLanguage, LANG_COUNT> result = {};
    std::array<bool, LANG_COUNT> included = {};
    for (const LocalizedLanguage& language : languages) {
        int id = static_cast<int>(language.id);
        if (id < 0 || id >= LANG_COUNT) {
            throw "Invalid localization AppLanguage.";
        }
        if (included[id]) {
            throw "Duplicate localization AppLanguage.";
        }
        for (const wchar_t* text : language.texts) {
            if (text == nullptr || text[0] == L'\0') {
                throw "Every language must contain a nonempty translation for every TextId.";
            }
        }
        result[id] = language;
        included[id] = true;
    }
    return result;
}
