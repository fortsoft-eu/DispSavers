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
 * Last modified for version 1.3.2.2
 */

#pragma once

#include "Localization.h"
#include <windows.h>
#include <string>
#include <string_view>
#include <vector>

struct AppSettings;
class ProgramIcons;

/// Application identity and the subclass identifier shared by the information forms.
extern ProgramIcons programIcons;
extern const wchar_t PRODUCT_NAME[];
extern const wchar_t WEBSITE_URL[];
extern const UINT_PTR INFORMATION_TEXT_SUBCLASS_ID;

/// Checks whether the standalone option and a visible animation require saver inhibition.
bool ShouldInhibitScreenSaver();

/// Recognizes Unicode whitespace for license text and descriptive-text layout.
bool IsUnicodeWhitespace(wchar_t character);

/// Assigns the preferred or first available single-character mnemonic to a caption.
std::wstring UniqueMnemonic(const wchar_t* text, std::vector<wchar_t>& usedMnemonics);

/// Returns an owned copy of a control's current Unicode text.
std::wstring GetControlText(HWND control);

/// Prefixes the localized common caption with a mnemonic marker.
std::wstring Mnemonic(AppLanguage language, TextId id);

/// Replaces clipboard contents with Unicode text, transferring the allocation to Windows only on success.
bool CopyTextToClipboard(HWND owner, const std::wstring& text);

/// Measures native dialog base units from the supplied interface font.
bool GetDialogFontBaseUnits(HFONT font, SIZE* units);

/// Converts current information-dialog font units to native pixel dimensions.
SIZE InformationDialogUnits(HFONT font, int x, int y);

/// Uses the template dimensions and widens the Close button for its current text when necessary.
SIZE InformationButtonSize(HWND window, HFONT font, int resourceId);

/// Measures a label's wrapped height at the requested width using its actual font, or returns zero if a DC
/// is unavailable.
int InformationLabelHeight(HWND control, int width);

/// Draws a wrapped label over its parent background using the selected font and native text colors.
INT_PTR DrawWrappedTextItem(const DRAWITEMSTRUCT* item);

/// Positions an information-window child without activation or Z-order changes, enforcing positive
/// dimensions.
void PlaceInformationControl(HWND window, int id, int x, int y, int width, int height);

/// Aligns a settings label, edit, combo, push button, or checkbox to adjacent text plus an optional baseline
/// distance. Uses native content rectangles and preserves size, horizontal position, and Z order.
void AlignSettingsControl(HWND control, HWND reference, LONG baselineDistance = 0);

/// Creates a tooltip attached to a control, destroying it if registration fails. The supplied text must
/// remain valid while the tooltip uses it.
HWND CreateControlTooltip(HWND parent, HWND control, const wchar_t* text);

/// Obtains native CW_USEDEFAULT placement from an invisible overlapped window and moves the hidden dialog
/// there.
bool PositionInformationWindowByWindowsDefault(HWND window);

/// Keeps independent information and recording-settings windows synchronized with the settings form's topmost
/// policy.
void UpdateInformationWindowsTopmost(HWND settingsWindow);

/// Updates each open information form through its own content and layout implementation.
void RefreshInformationWindows(HWND owner);

/// Releases the cached Unicode boundary analysis and its retained text.
void ResetInformationWordBreak();

/// Supplies the same native Unicode word and cluster boundaries to the Help and About edits.
int CALLBACK InformationWordBreakProc(wchar_t* text, int position, int length, int code);

/// Lets information windows handle Enter, Escape and Tab from their read-only text fields.
LRESULT CALLBACK InformationTextSubclassProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam,
    UINT_PTR subclassId, DWORD_PTR referenceData);

struct PrintJob;
class PrintSettings;

static const UINT findVisibilityChangedMessage = WM_APP + 60;
static const UINT findMatchMessage = WM_APP + 61;

UINT WindowDpi(HWND window);
HFONT CreateUiFont(HWND window);
SIZE DialogUnits(HFONT font, int x, int y);
SIZE PreferredButtonSize(HWND button, const SIZE& minimum);
RECT ControlRect(HWND window, HWND parent);
void PlaceControl(HWND window, int x, int y, int width, int height);
bool ReadControlMetrics(HWND control, TEXTMETRICW* metrics);
bool ComboBoxTextRect(HWND combo, RECT* rectangle);
void UpdateComboBoxMetrics(HWND combo);
void UpdateComboBoxDropDownSize(HWND combo);
LONG ControlTextBaseline(HWND control);
void AlignControlBaseline(HWND control, HWND reference);
void UpdateEditMetrics(HWND edit, HWND enclosingCombo = nullptr);
wchar_t* CopyControlText(HWND control);
const wchar_t* T(TextId id);
int GetApplicationLanguage();
const wchar_t* GetLocalizedText(AppLanguage language, std::string_view key);
PrintJob* CapturePrintJob(HWND owner, HWND edit, const wchar_t* title, const RECT& margins);
PrintJob* ChooseReportPrinter(HWND owner, HWND edit, const wchar_t* title, PrintSettings& settings,
    wchar_t* error, int errorCapacity);
bool PrintReportPages(PrintJob* job);
void FreePrintJob(PrintJob* job);

std::wstring InformationHelpText(AppLanguage language, bool applicationMode);
void SaveInformationWindowPositions(const AppSettings& settings);
HICON LoadInformationFormIcon(HINSTANCE instance, int size);
void ApplyInformationFormIcons(HWND window, HINSTANCE instance, int iconIndex = 0);

bool TranslateModalInformationMessage(HWND owner, MSG& message);
INT_PTR ShowModalInformationForm(HINSTANCE instance, const DLGTEMPLATE* definition, HWND owner,
    DLGPROC procedure, LPARAM parameter);
