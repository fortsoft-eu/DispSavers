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

/// Named keys indexing the complete translation table for each supported language.
enum TextId {
    TXT_LANGUAGE_NAME,
    TXT_CONTROL_TITLE,
    TXT_SETTINGS_TITLE,
    TXT_LANGUAGE,
    TXT_OK,
    TXT_CANCEL,
    TXT_EXIT,
    TXT_PAUSE,
    TXT_RESUME,
    TXT_HELP,
    TXT_ABOUT,
    TXT_CLOSE,
    TXT_ABOUT_VISIT_TOOLTIP,
    TXT_ABOUT_WEBSITE_FAILED,
    TXT_ABOUT_COPY_URL_FAILED,
    TXT_ABOUT_COPY_INFORMATION_FAILED,
    TXT_ABOUT_DESCRIPTION,
    TXT_ABOUT_VERSION_LABEL,
    TXT_ABOUT_PLATFORM_LABEL,
    TXT_ABOUT_WEBSITE_LABEL,
    TXT_OPEN_IN_BROWSER,
    TXT_COPY_URL,
    TXT_COPY_INFORMATION,
    TXT_ABOUT_LICENSE_UNAVAILABLE,
    TXT_APPLICATION_HELP,
    TXT_SCREEN_SAVER_HELP,
    TXT_CELL_SIZE,
    TXT_GENERATION_RATE,
    TXT_INITIAL_DENSITY,
    TXT_RESTART,
    TXT_ALIVE_COLOR,
    TXT_BACKGROUND_COLOR,
    TXT_TOPOLOGY_NOTE,
    TXT_ANIMATION_RUNNING,
    TXT_PAUSED_STATUS,
    TXT_RENDERER_FAILED,
    TXT_ENABLE_PREVIEW,
    TXT_DISABLE_PREVIEW,
    TXT_MONITOR,
    TXT_RESOLUTION,
    TXT_POSITION,
    TXT_PRIMARY,
    TXT_MONITOR_COLUMN_MODEL,
    TXT_MONITOR_COLUMN_REFRESH_RATE,
    TXT_MONITOR_COLUMN_BIT_DEPTH,
    TXT_MONITOR_COLUMN_COLOR_FORMAT,
    TXT_MONITOR_COLUMN_COLOR_SPACE,
    TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
    TXT_MONITOR_PIXEL_DEPTH_FORMAT,
    TXT_ANIMATION_MONITOR,
    TXT_READY_STATUS,
    TXT_SHOW_GRID,
    TXT_GRID_COLOR,
    TXT_AUTO_RESET,
    TXT_PATTERNS_ONLY,
    TXT_START_RECORDING,
    TXT_STOP_RECORDING,
    TXT_RECORDING,
    TXT_RECORDING_SAVED,
    TXT_RECORDING_FAILED,
    TXT_RECORDING_CLOSE_WARNING,
    TXT_RECORDING_SETTINGS_TITLE,
    TXT_RECORDING_SETTINGS_VIEWPORT,
    TXT_RECORDING_SETTINGS_TELEVISION,
    TXT_RECORDING_SETTINGS_RESOLUTION,
    TXT_RECORDING_SETTINGS_FRAME_RATE,
    TXT_RECORDING_SETTINGS_NOTE,
    TXT_PATTERN_MIX,
    TXT_PATTERN_CATALOG_FAILED,
    TXT_INSTALLING_SCREEN_SAVER,
    TXT_UNINSTALLING_SCREEN_SAVER,
    TXT_INSTALL_SCREEN_SAVER,
    TXT_UNINSTALL_SCREEN_SAVER,
    TXT_INSTALLATION_FAILED,
    TXT_INSTALLATION_SUCCEEDED,
    TXT_UNINSTALLATION_SUCCEEDED,
    TXT_UNINSTALLATION_FAILED,
    TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
    TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
    TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
    TXT_RANDOM_ALIVE_COLOR,
    TXT_RANDOM_BACKGROUND_COLOR,
    TXT_RANDOM_GRID_COLOR,
    TXT_SYSTEM_SCREEN_SAVER,
    TXT_SYSTEM_SCREEN_SAVER_FAILED,
    TXT_PREVENT_SCREEN_SAVER,
    TXT_RESET_SETTINGS,
    TXT_SNAPSHOT,
    TXT_SNAPSHOT_SAVED,
    TXT_SNAPSHOT_FAILED,
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

/// Localized captions for monitor-detail columns.
struct MonitorColumnText {
    const wchar_t* model;
    const wchar_t* refreshRate;
    const wchar_t* bitDepth;
    const wchar_t* colorFormat;
    const wchar_t* colorSpace;
    const wchar_t* channelDepth;
    const wchar_t* pixelDepth;
};

/// Returns the compile-time checked translation for a valid language and named text key.
const wchar_t* GetLocalizedText(AppLanguage language, TextId id);

/// Maps the current user's Windows UI language to a supported language.
AppLanguage DetectSystemLanguage();

/// Returns monitor details by named text keys instead of positional indices into unrelated tables.
MonitorColumnText MonitorColumnsText(AppLanguage language);

/// Returns a TV resolution caption at the supplied preset index.
const wchar_t* RecordingResolutionText(unsigned index);

/// Returns an exact TV frame-rate caption at the supplied preset index.
const wchar_t* RecordingRateText(unsigned index);
