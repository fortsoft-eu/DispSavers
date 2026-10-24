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

#pragma once

#include "Effects.h"
#include <array>

/// Supported user-interface languages in combo-box display order.
enum class AppLanguage : int {
    Czech,
    EnglishUs,
    EnglishUk,
    EnglishAu,
    German,
    French,
    Spanish,
    Italian,
    Portuguese,
    Polish,
    Slovak,
    Danish,
    Finnish,
    Icelandic,
    Norwegian,
    Swedish,
    Turkish,
    Estonian,
    Irish,
    Lithuanian,
    Latvian,
    Hungarian,
    Maltese,
    Dutch,
    Romanian,
    Greek,
    Bosnian,
    Croatian,
    Slovenian,
    Montenegrin,
    Belarusian,
    Bulgarian,
    Macedonian,
    Serbian,
    Ukrainian,
    Russian,
    Count
};

/// Core localized strings displayed by both settings-window variants.
struct LocalizedText {
    const wchar_t* languageName;
    const wchar_t* controlTitle;
    const wchar_t* settingsTitle;
    const wchar_t* language;
    const wchar_t* objectSpeed;
    const wchar_t* flightEffects;
    const wchar_t* enableAll;
    const wchar_t* disableAll;
    const wchar_t* animationMonitor;
    const wchar_t* monitor;
    const wchar_t* resolution;
    const wchar_t* position;
    const wchar_t* primary;
    const wchar_t* ok;
    const wchar_t* cancel;
    const wchar_t* startRecording;
    const wchar_t* stopRecording;
    const wchar_t* pause;
    const wchar_t* resume;
    const wchar_t* installScreenSaver;
    const wchar_t* exit;
    const wchar_t* ready;
    const wchar_t* recording;
    const wchar_t* recordingSaved;
    const wchar_t* recordingFailed;
    const wchar_t* installationFailed;
    const wchar_t* installationSucceeded;
    const wchar_t* rendererFailed;
    std::array<const wchar_t*, EFFECT_COUNT> effects;
};

/// Number of selectable user-interface languages.
inline constexpr std::size_t LANGUAGE_COUNT = static_cast<std::size_t>(AppLanguage::Count);

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

/// Captions and usage note displayed by the recording-settings dialog.
struct RecordingText {
    const wchar_t* title;
    const wchar_t* viewport;
    const wchar_t* television;
    const wchar_t* resolution;
    const wchar_t* frameRate;
    const wchar_t* note;
};

/// Returns localized recording-settings captions.
const RecordingText& RecordingSettingsText(AppLanguage language);

/// Returns the warning displayed before closing an application with an active recording.
const wchar_t* RecordingCloseWarningText(AppLanguage language);

/// Returns one of the three TV resolution captions.
const wchar_t* RecordingResolutionText(unsigned index);

/// Returns one of the four exact TV frame-rate captions.
const wchar_t* RecordingRateText(unsigned index);

/// Core language-table access and conversion

/// Returns the core text record, normalizing unsupported language values to US English.
const LocalizedText& Text(AppLanguage language);

/// Returns localized monitor-detail column captions and bit-depth formats.
const MonitorColumnText& MonitorColumnsText(AppLanguage language);

/// Maps the current user's Windows UI language to the nearest supported language.
AppLanguage DetectSystemLanguage();

/// Maps unsupported persisted language values to US English.
AppLanguage NormalizeLanguage(int language);

/// Returns a supported language's position in the language selector.
int LanguageIndex(AppLanguage language);

/// Resolves a language-selector index, using US English for an invalid index.
AppLanguage LanguageAtIndex(int index);

/// Supplementary settings-window strings

/// Returns the localized option that inhibits the screen saver during visible animation.
const wchar_t* PreventScreenSaverText(AppLanguage language);

/// Returns the localized command that starts the settings preview.
const wchar_t* EnablePreviewText(AppLanguage language);

/// Returns the localized command that stops the settings preview.
const wchar_t* DisablePreviewText(AppLanguage language);

/// Returns the localized status text for paused animation.
const wchar_t* PausedStatusText(AppLanguage language);

/// Returns the localized ready status when no animation surface is rendering.
const wchar_t* ReadyStatusText(AppLanguage language);

/// Returns the localized Help button caption.
const wchar_t* HelpButtonText(AppLanguage language);

/// Returns the localized About button caption.
const wchar_t* AboutButtonText(AppLanguage language);

/// Returns the localized Close button caption.
const wchar_t* CloseButtonText(AppLanguage language);

/// Returns the localized snapshot button caption.
const wchar_t* SnapshotButtonText(AppLanguage language);

/// Returns the localized status text for a successfully saved snapshot.
const wchar_t* SnapshotSavedText(AppLanguage language);

/// Returns the localized status text for a failed snapshot.
const wchar_t* SnapshotFailedText(AppLanguage language);

/// Screen-saver installation strings

/// Returns the localized command that uninstalls the screen saver.
const wchar_t* UninstallScreenSaverText(AppLanguage language);

/// Returns the localized status text for successful screen-saver uninstallation.
const wchar_t* UninstallationSucceededText(AppLanguage language);

/// Returns the generic localized screen-saver uninstallation failure text.
const wchar_t* UninstallationFailedText(AppLanguage language);

/// Returns the instruction to close settings that prevent screen-saver uninstallation.
const wchar_t* UninstallationBlockedBySettingsText(AppLanguage language);

/// Returns the instruction to close the Windows preview that prevents screen-saver uninstallation.
const wchar_t* UninstallationBlockedBySystemPreviewText(AppLanguage language);

/// Returns the instruction to stop an active screen saver before uninstalling it.
const wchar_t* UninstallationBlockedByRunningSaverText(AppLanguage language);

/// Help and About dialog strings

/// Returns localized Help content for standalone or screen-saver settings.
const wchar_t* HelpBodyText(AppLanguage language, bool appMode);

/// Returns the localized one-line product description.
const wchar_t* AboutDescriptionText(AppLanguage language);

/// Returns the localized product-version label.
const wchar_t* AboutVersionLabel(AppLanguage language);

/// Returns the localized target-platform label.
const wchar_t* AboutPlatformLabel(AppLanguage language);

/// Returns the localized website label.
const wchar_t* AboutWebsiteLabel(AppLanguage language);

/// Returns the localized About website tooltip.
const wchar_t* AboutVisitTooltipText(AppLanguage language);

/// Returns the localized context command that opens the product website.
const wchar_t* OpenInBrowserText(AppLanguage language);

/// Returns the localized context command that copies the website URL.
const wchar_t* CopyUrlText(AppLanguage language);

/// Returns the localized context command that copies product information.
const wchar_t* CopyInformationText(AppLanguage language);

/// Returns the selected monitors' texture checkbox caption.
const wchar_t* FilledSurfaceText(AppLanguage language);

/// Returns the localized caption for the selected surface deformation mode.
const wchar_t* SurfaceShapeText(AppLanguage language, SurfaceShape shape);

/// Returns the selected monitors' free camera-tumbling option.
const wchar_t* CameraTumblingText(AppLanguage language);

/// Returns the selected monitors’ optional camera stops and reversals caption.
const wchar_t* CameraReversalsText(AppLanguage language);

/// Returns the selected monitors' main-light checkbox caption.
const wchar_t* MainLightText(AppLanguage language);

/// Returns the selected monitors' fill-light checkbox caption.
const wchar_t* FillLightText(AppLanguage language);

/// Returns the localized ambient-light checkbox caption.
const wchar_t* AmbientLightText(AppLanguage language);

/// Returns the localized rim-light checkbox caption.
const wchar_t* RimLightText(AppLanguage language);
