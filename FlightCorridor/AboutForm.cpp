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
#include "AboutForm.h"
#include "AppSettings.h"
#include "main.h"
#include "ProgramIcons.h"
#include "resource.h"
#include "SelectionEdit.h"
#include "SystemDialogTemplate.h"
#include <algorithm>
#include <commctrl.h>
#include <uxtheme.h>
#include <windowsx.h>
#include <winver.h>
#include <shellapi.h>
#include <climits>
#include <vector>

const UINT_PTR ABOUT_CONTROL_SUBCLASS_ID = 0xCC03;
const UINT_PTR ABOUT_LICENSE_SUBCLASS_ID = 0xCC06;
const int ABOUT_ICON_SIZE = 32;
const int ABOUT_LARGE_ICON_SIZE = 48;
const int ABOUT_LARGE_ICON_DPI = 130;

/// Creates the About license font using Consolas at the reference 8-point size.
/// The caller owns the returned GDI font, which may be null on failure.
static HFONT CreateAboutFont(HWND window) {
    LOGFONTW font = {};
    font.lfHeight = -MulDiv(8, GetSystemDialogDpi(window), 72);
    font.lfWeight = FW_NORMAL;
    font.lfCharSet = ANSI_CHARSET;
    font.lfPitchAndFamily = FIXED_PITCH | FF_MODERN;
    wcsncpy_s(font.lfFaceName, L"Consolas", _TRUNCATE);
    return CreateFontIndirectW(&font);
}

/// Returns a dialog child's window rectangle mapped to its parent's client coordinates.
static RECT InformationControlRect(HWND window, int id) {
    RECT rect = {};
    GetWindowRect(GetDlgItem(window, id), &rect);
    MapWindowPoints(HWND_DESKTOP, window, reinterpret_cast<POINT*>(&rect), 2);
    return rect;
}

/// Measures unwrapped information text using the control's current font.
static SIZE InformationTextSize(HWND control) {
    SIZE size = {};
    HDC dc = GetDC(control);
    if (dc != nullptr) {
        HFONT font = reinterpret_cast<HFONT>(SendMessageW(control, WM_GETFONT, 0, 0));
        HGDIOBJ previous = font == nullptr ? nullptr : SelectObject(dc, font);
        std::wstring text = GetControlText(control);
        GetTextExtentPoint32W(dc, text.c_str(), static_cast<int>(text.size()), &size);
        if (previous != nullptr) {
            SelectObject(dc, previous);
        }
        ReleaseDC(control, dc);
    }
    return size;
}

/// Measures unwrapped license text in the edit's current font and toggles the horizontal scrollbar only when
/// needed. Restores horizontal position to the start before hiding the bar; measurement also works while the
/// bar is hidden.
static void UpdateAboutLicenseScrollBar(HWND window) {
    HDC dc = GetDC(window);
    if (dc == nullptr) {
        return;
    }
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(window, WM_GETFONT, 0, 0));
    HGDIOBJ previousFont = font == nullptr ? nullptr : SelectObject(dc, font);
    std::wstring text = GetControlText(window);
    RECT textBounds = {};
    DrawTextW(dc, text.c_str(), static_cast<int>(text.size()), &textBounds,
        DT_CALCRECT | DT_NOPREFIX | DT_EXPANDTABS);
    if (previousFont != nullptr) {
        SelectObject(dc, previousFont);
    }
    ReleaseDC(window, dc);
    RECT format = {};
    SendMessageW(window, EM_GETRECT, 0, reinterpret_cast<LPARAM>(&format));
    bool needed = textBounds.right - textBounds.left > format.right - format.left;
    bool visible = (GetWindowLongPtrW(window, GWL_STYLE) & WS_HSCROLL) != 0;
    if (needed != visible) {
        if (!needed) {
            SendMessageW(window, WM_HSCROLL, SB_LEFT, 0);
        }
        ShowScrollBar(window, SB_HORZ, needed);
    }
}

/// Recalculates horizontal scrollbar visibility after native size, font, text, or theme updates and removes
/// the subclass on destruction.
static LRESULT CALLBACK AboutLicenseSubclassProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam,
        UINT_PTR subclassId, DWORD_PTR referenceData) {
    UNREFERENCED_PARAMETER(referenceData);
    if (message == WM_SIZE || message == WM_SETFONT || message == WM_SETTEXT || message == WM_THEMECHANGED) {
        LRESULT result = DefSubclassProc(window, message, wParam, lParam);
        UpdateAboutLicenseScrollBar(window);
        return result;
    }
    if (message == WM_NCDESTROY) {
        RemoveWindowSubclass(window, AboutLicenseSubclassProc, subclassId);
    }
    return DefSubclassProc(window, message, wParam, lParam);
}

/// Returns the executable's four-part product version, or a question mark if version information cannot be
/// read.
static std::wstring GetApplicationVersion() {
    wchar_t path[MAX_PATH] = {};
    if (GetModuleFileNameW(nullptr, path, ARRAYSIZE(path)) == 0) {
        return L"?";
    }
    DWORD ignored = 0;
    DWORD size = GetFileVersionInfoSizeW(path, &ignored);
    if (size == 0) {
        return L"?";
    }
    std::vector<BYTE> data(size);
    if (!GetFileVersionInfoW(path, 0, size, data.data())) {
        return L"?";
    }
    VS_FIXEDFILEINFO* information = nullptr;
    UINT informationSize = 0;
    bool invalidVersionInfo =
        !VerQueryValueW(data.data(), L"\\", reinterpret_cast<void**>(&information), &informationSize)
        || information == nullptr
        || informationSize < sizeof(VS_FIXEDFILEINFO)
        || information->dwSignature != VS_FFI_SIGNATURE;
    if (invalidVersionInfo) {
        return L"?";
    }
    wchar_t version[48] = {};
    swprintf_s(version, L"%u.%u.%u.%u",
        HIWORD(information->dwProductVersionMS),
        LOWORD(information->dwProductVersionMS),
        HIWORD(information->dwProductVersionLS),
        LOWORD(information->dwProductVersionLS));
    return version;
}

/// Builds the About window title from its localized caption and the application name.
static std::wstring BuildAboutTitle(AppLanguage language) {
    return std::wstring(GetLocalizedText(language, TXT_ABOUT)) + L" " + PRODUCT_NAME;
}

/// Builds localized product information including description, version, copyright, and target platform.
static std::wstring BuildAboutProductText(AppLanguage language) {
    std::wstring product = std::wstring(PRODUCT_NAME) + L"\r\n";
    product += GetLocalizedText(language, TXT_ABOUT_DESCRIPTION);
    product += L"\r\n\r\n";
    product += GetLocalizedText(language, TXT_ABOUT_VERSION_LABEL);
    product += L" ";
    product += GetApplicationVersion();
    product += L"\r\nCopyright © Petr Červinka — FortSoft 2026\r\n";
    product += GetLocalizedText(language, TXT_ABOUT_PLATFORM_LABEL);
    product += L" Win32 (x86)";
    return product;
}

/// Builds SysLink markup for the product website URL.
static std::wstring BuildAboutLinkText() {
    return std::wstring(L"<a href=\"") + WEBSITE_URL + L"\">" + WEBSITE_URL + L"</a>";
}

/// Combines product information and the labeled website URL as plain text for copying.
static std::wstring BuildAboutClipboardText(AppLanguage language) {
    return BuildAboutProductText(language) + L"\r\n"
        + GetLocalizedText(language, TXT_ABOUT_WEBSITE_LABEL) + L" " + WEBSITE_URL;
}

/// Decodes the embedded UTF-8 license, removes an optional BOM and a case-insensitive MIT License heading,
/// and trims outer whitespace. Accepts whitespace between heading words, preserves the license body, and
/// normalizes line endings for the edit control.
std::wstring AboutForm::LoadLicenseText() const {
    HRSRC resource = FindResourceW(instance, MAKEINTRESOURCEW(IDR_LICENSE), RT_RCDATA);
    if (resource == nullptr) {
        return std::wstring();
    }
    HGLOBAL loadedResource = LoadResource(instance, resource);
    if (loadedResource == nullptr) {
        return std::wstring();
    }
    DWORD byteCount = SizeofResource(instance, resource);
    const char* bytes = static_cast<const char*>(LockResource(loadedResource));
    if (bytes == nullptr || byteCount == 0 || byteCount > static_cast<DWORD>(INT_MAX)) {
        return std::wstring();
    }
    int characterCount = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, bytes,
        static_cast<int>(byteCount), nullptr, 0);
    if (characterCount <= 0) {
        return std::wstring();
    }
    std::wstring decoded(characterCount, L'\0');
    if (MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, bytes, static_cast<int>(byteCount),
        decoded.data(), characterCount) != characterCount) {
        return std::wstring();
    }
    size_t headingStart = !decoded.empty() && decoded.front() == L'\uFEFF' ? 1 : 0;
    while (headingStart < decoded.size() && IsUnicodeWhitespace(decoded[headingStart])) {
        headingStart++;
    }
    size_t headingEnd = decoded.find_first_of(L"\r\n", headingStart);
    std::wstring heading = decoded.substr(headingStart, headingEnd - headingStart);
    std::wstring normalizedHeading;
    bool whitespace = false;
    for (wchar_t character : heading) {
        if (IsUnicodeWhitespace(character)) {
            whitespace = true;
        } else {
            if (whitespace && !normalizedHeading.empty()) {
                normalizedHeading += L' ';
            }
            normalizedHeading += character;
            whitespace = false;
        }
    }
    size_t bodyStart = headingStart;
    if (_wcsicmp(normalizedHeading.c_str(), L"MIT License") == 0) {
        bodyStart = headingEnd == std::wstring::npos ? decoded.size() : headingEnd;
        while (bodyStart < decoded.size() && IsUnicodeWhitespace(decoded[bodyStart])) {
            bodyStart++;
        }
    }
    decoded.erase(0, bodyStart);
    while (!decoded.empty() && (decoded.back() == L'\0' || IsUnicodeWhitespace(decoded.back()))) {
        decoded.pop_back();
    }
    std::wstring result;
    result.reserve(decoded.size() + 32);
    for (size_t index = 0; index < decoded.size(); index++) {
        if (decoded[index] == L'\n' && (index == 0 || decoded[index - 1] != L'\r')) {
            result += L'\r';
        }
        result += decoded[index];
    }
    return result;
}

/// Opens the About website and reports failures in the selected application language.
void AboutForm::OpenWebsite() const {
    HINSTANCE result = ShellExecuteW(window, L"open", WEBSITE_URL, nullptr, nullptr, SW_SHOWNORMAL);
    if (reinterpret_cast<INT_PTR>(result) <= 32) {
        MessageBoxW(window, GetLocalizedText(language, TXT_ABOUT_WEBSITE_FAILED), PRODUCT_NAME,
            MB_OK | MB_ICONERROR);
    }
}

/// Displays the applicable About context commands and handles opening the website or copying its URL or
/// product information.
void AboutForm::ShowContextMenu(HWND source, LPARAM location) const {
    HMENU menu = CreatePopupMenu();
    if (menu == nullptr) {
        return;
    }
    int controlId = GetDlgCtrlID(source);
    if (controlId == ID_INFO_LINK) {
        AppendMenuW(menu, MF_STRING, ID_MENU_ABOUT_OPEN_LINK, GetLocalizedText(language,
            TXT_OPEN_IN_BROWSER));
        AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
        AppendMenuW(menu, MF_STRING, ID_MENU_ABOUT_COPY_URL, GetLocalizedText(language,
            TXT_COPY_URL));
        AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
        AppendMenuW(menu, MF_STRING, ID_MENU_ABOUT_COPY_INFORMATION, GetLocalizedText(language,
            TXT_COPY_INFORMATION));
    } else {
        AppendMenuW(menu, MF_STRING, ID_MENU_ABOUT_COPY_INFORMATION, GetLocalizedText(language,
            TXT_COPY_INFORMATION));
    }
    POINT point = { GET_X_LPARAM(location), GET_Y_LPARAM(location) };
    if (location == -1) {
        RECT rectangle = {};
        GetWindowRect(source, &rectangle);
        point.x = rectangle.left;
        point.y = rectangle.bottom;
    }
    int command = TrackPopupMenu(menu, TPM_RETURNCMD | TPM_RIGHTBUTTON, point.x, point.y, 0, window, nullptr);
    DestroyMenu(menu);
    if (command == ID_MENU_ABOUT_OPEN_LINK) {
        OpenWebsite();
    } else if (command == ID_MENU_ABOUT_COPY_URL) {
        if (!CopyTextToClipboard(window, WEBSITE_URL)) {
            MessageBoxW(window, GetLocalizedText(language, TXT_ABOUT_COPY_URL_FAILED), PRODUCT_NAME,
                MB_OK | MB_ICONERROR);
        }
    } else if (command == ID_MENU_ABOUT_COPY_INFORMATION) {
        if (!CopyTextToClipboard(window, BuildAboutClipboardText(language))) {
            MessageBoxW(window, GetLocalizedText(language, TXT_ABOUT_COPY_INFORMATION_FAILED), PRODUCT_NAME,
                MB_OK | MB_ICONERROR);
        }
    }
}

/// Adds the About context menu to product and website controls and removes the subclass on destruction.
LRESULT CALLBACK AboutForm::ControlSubclassProc(HWND control, UINT message, WPARAM wParam, LPARAM lParam,
        UINT_PTR subclassId, DWORD_PTR referenceData) {
    AboutForm* form = reinterpret_cast<AboutForm*>(referenceData);
    if (message == WM_CONTEXTMENU) {
        form->ShowContextMenu(control, lParam);
        return 0;
    }
    if (GetDlgCtrlID(control) == ID_INFO_LINK) {
        if (message == WM_SETCURSOR && LOWORD(lParam) == HTCLIENT) {
            SetCursor(LoadCursorW(nullptr, IDC_HAND));
            return TRUE;
        }
        if (message == WM_MBUTTONUP) {
            form->OpenWebsite();
            return 0;
        }
    }
    if (message == WM_NCDESTROY) {
        RemoveWindowSubclass(control, ControlSubclassProc, subclassId);
    }
    return DefSubclassProc(control, message, wParam, lParam);
}

/// Returns this form's native window, or null while it is closed.
HWND AboutForm::GetWindow() const {
    return window;
}

/// Destroys this form and releases its controls and owned fonts.
void AboutForm::Close() const {
    if (window != nullptr) {
        DestroyWindow(window);
    }
}

/// Updates this form's localized captions and content without changing the other form.
void AboutForm::Refresh(AppLanguage selectedLanguage) {
    if (window == nullptr || !IsWindow(window)) {
        return;
    }
    language = selectedLanguage;
    std::wstring title = BuildAboutTitle(language);
    std::wstring productText = BuildAboutProductText(language);
    std::wstring linkText = BuildAboutLinkText();
    SetWindowTextW(window, title.c_str());
    SetDlgItemTextW(window, ID_INFO_PRODUCT, productText.c_str());
    SetDlgItemTextW(window, ID_INFO_WEBSITE, GetLocalizedText(language, TXT_ABOUT_WEBSITE_LABEL));
    SetDlgItemTextW(window, ID_INFO_LINK, linkText.c_str());
    SetDlgItemTextW(window, ID_INFO_CLOSE, Mnemonic(language, TXT_CLOSE).c_str());
    Layout();
    if (tooltip != nullptr) {
        SendMessageW(tooltip, TTM_UPDATE, 0, 0);
    }
}

/// Applies the effective interface font and current theme while keeping the About license in Consolas.
bool AboutForm::ApplyStyle(bool updateFont) {
    if (window == nullptr) {
        return false;
    }
    HFONT font = uiFont;
    if (updateFont) {
        font = CreateSystemDialogFont(window);
    }
    if (font == nullptr) {
        return false;
    }
    HFONT nextLicenseFont = CreateAboutFont(window);
    if (nextLicenseFont == nullptr) {
        if (updateFont) {
            DeleteObject(font);
        }
        return false;
    }
    HFONT previousFont = ownsFont ? uiFont : nullptr;
    uiFont = font;
    ownsFont = updateFont;
    SendMessageW(window, WM_SETFONT, reinterpret_cast<WPARAM>(font), FALSE);
    const int ids[] = { ID_INFO_PRODUCT, ID_INFO_WEBSITE, ID_INFO_LINK, ID_INFO_TEXT, ID_INFO_CLOSE };
    const wchar_t* theme = nullptr;
    for (int id : ids) {
        HWND control = GetDlgItem(window, id);
        if (control == nullptr) {
            continue;
        }
        HFONT selected = id == ID_INFO_TEXT ? nextLicenseFont : font;
        SendMessageW(control, WM_SETFONT, reinterpret_cast<WPARAM>(selected), FALSE);
        SetWindowTheme(control, theme, theme);
    }
    if (tooltip != nullptr) {
        SendMessageW(tooltip, WM_SETFONT, reinterpret_cast<WPARAM>(font), FALSE);
    }
    if (previousFont != nullptr) {
        DeleteObject(previousFont);
    }
    if (licenseFont != nullptr) {
        DeleteObject(licenseFont);
    }
    licenseFont = nextLicenseFont;
    int size = GetSystemDialogDpi(window) >= ABOUT_LARGE_ICON_DPI ? ABOUT_LARGE_ICON_SIZE : ABOUT_ICON_SIZE;
    HICON icon = programIcons->LoadSized(size);
    if (icon == nullptr) {
        return false;
    }
    SendDlgItemMessageW(window, ID_INFO_ICON, STM_SETICON, reinterpret_cast<WPARAM>(icon), 0);
    if (productIcon != nullptr) {
        DestroyIcon(productIcon);
    }
    productIcon = icon;
    SetWindowPos(GetDlgItem(window, ID_INFO_ICON), nullptr, 0, 0, size, size,
        SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
    programIcons->Apply(window);
    Layout();
    RedrawWindow(window, nullptr, nullptr, RDW_INVALIDATE | RDW_ERASE | RDW_FRAME | RDW_ALLCHILDREN);
    return true;
}

/// Fits the About window to its monitor work area after its natural layout, without saving the adjusted size.
void AboutForm::FitToWorkArea() const {
    RECT bounds = {};
    MONITORINFO monitor = { sizeof(monitor) };
    if (!GetWindowRect(window, &bounds)
            || !GetMonitorInfoW(MonitorFromWindow(window, MONITOR_DEFAULTTONEAREST), &monitor)) {
        return;
    }
    LONG width = std::min(bounds.right - bounds.left, monitor.rcWork.right - monitor.rcWork.left);
    LONG height = std::min(bounds.bottom - bounds.top, monitor.rcWork.bottom - monitor.rcWork.top);
    LONG left = std::clamp(bounds.left, monitor.rcWork.left, monitor.rcWork.right - width);
    LONG top = std::clamp(bounds.top, monitor.rcWork.top, monitor.rcWork.bottom - height);
    if (left != bounds.left
            || top != bounds.top
            || width != bounds.right - bounds.left
            || height != bounds.bottom - bounds.top) {
        SetWindowPos(window, nullptr, left, top, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
    }
}

/// Builds the natural About layout from its fixed license dimensions, then fits it to the monitor work area.
/// Resize notifications anchor the edit to the right and bottom edges and the Close button to the bottom
/// right.
void AboutForm::Layout(bool resize) const {
    if (!initialized || IsIconic(window)) {
        return;
    }
    RECT client = {};
    GetClientRect(window, &client);
    SIZE current = { client.right, client.bottom };
    UINT dpi = GetSystemDialogDpi(window);
    SIZE margin = InformationDialogUnits(uiFont, 8, 8);
    SIZE gap = InformationDialogUnits(uiFont, 4, 6);
    SIZE button = InformationButtonSize(window, uiFont);
    int textTop = margin.cy;
    if (resize) {
        SIZE license = {
            MulDiv(referenceLicense.cx, dpi, referenceDpi),
            MulDiv(referenceLicense.cy, dpi, referenceDpi)
        };
        client.right = license.cx + 2 * InformationDialogUnits(uiFont, 10, 0).cx;
        SetWindowPos(GetDlgItem(window, ID_INFO_ICON), nullptr, margin.cx, margin.cy, 0, 0,
            SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
        RECT icon = InformationControlRect(window, ID_INFO_ICON);
        SIZE productPosition = InformationDialogUnits(uiFont, 0, 4);
        productPosition.cx = icon.right + icon.left;
        int width = client.right - margin.cx - productPosition.cx;
        int productHeight = InformationLabelHeight(GetDlgItem(window, ID_INFO_PRODUCT), width);
        PlaceInformationControl(window, ID_INFO_PRODUCT, productPosition.cx, productPosition.cy, width,
            productHeight);
        SIZE website = InformationTextSize(GetDlgItem(window, ID_INFO_WEBSITE));
        int websiteY = productPosition.cy + productHeight + gap.cy;
        PlaceInformationControl(window, ID_INFO_WEBSITE, productPosition.cx, websiteY, website.cx,
            website.cy);
        int linkX = productPosition.cx + website.cx + gap.cx;
        int linkWidth = client.right - margin.cx - linkX;
        SIZE idealLink = {};
        int linkHeight = website.cy;
        LRESULT height = SendDlgItemMessageW(window, ID_INFO_LINK, LM_GETIDEALSIZE, linkWidth,
            reinterpret_cast<LPARAM>(&idealLink));
        if (height > 0) {
            linkHeight = static_cast<int>(height);
        }
        if (idealLink.cx > 0 && idealLink.cx < linkWidth) {
            linkWidth = idealLink.cx;
        }
        PlaceInformationControl(window, ID_INFO_LINK, linkX, websiteY, linkWidth, linkHeight);
        AlignSettingsControl(GetDlgItem(window, ID_INFO_LINK), GetDlgItem(window, ID_INFO_WEBSITE));
        RECT link = InformationControlRect(window, ID_INFO_LINK);
        textTop = std::max(websiteY + website.cy, link.bottom) + gap.cy;
        client.bottom = textTop + license.cy + gap.cy + button.cy + margin.cy;
        if (client.right != current.cx || client.bottom != current.cy) {
            RECT bounds = {};
            GetWindowRect(window, &bounds);
            SetWindowPos(window, nullptr, 0, 0, bounds.right - bounds.left + client.right - current.cx,
                bounds.bottom - bounds.top + client.bottom - current.cy,
                SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
        }
    }
    if (!resize) {
        textTop = InformationControlRect(window, ID_INFO_TEXT).top;
    }
    int buttonY = client.bottom - margin.cy - button.cy;
    PlaceInformationControl(window, ID_INFO_CLOSE, client.right - margin.cx - button.cx, buttonY, button.cx,
        button.cy);
    PlaceInformationControl(window, ID_INFO_TEXT, margin.cx, textTop,
        client.right - 2 * margin.cx, buttonY - gap.cy - textTop);
    if (resize) {
        FitToWorkArea();
    }
}

/// Handles this form's native commands, layout, theme, DPI changes and resource cleanup.
INT_PTR AboutForm::HandleMessage(UINT message, WPARAM wParam, LPARAM lParam) {
    if (message == WM_GETFONT && uiFont != nullptr) {
        SetWindowLongPtrW(window, DWLP_MSGRESULT, reinterpret_cast<LONG_PTR>(uiFont));
        return TRUE;
    }
    if (message == WM_SYSCOMMAND && (wParam & 0xFFF0) == SC_SCREENSAVE && ShouldInhibitScreenSaver()) {
        return TRUE;
    }
    if (message == WM_CLOSE
            || message == WM_COMMAND && (LOWORD(wParam) == ID_INFO_CLOSE || LOWORD(wParam) == IDCANCEL)) {
        DestroyWindow(window);
        return TRUE;
    }
    if (message == WM_SIZE) {
        Layout(false);
        return TRUE;
    }
    if (message == WM_DRAWITEM && wParam == ID_INFO_PRODUCT) {
        return DrawWrappedTextItem(reinterpret_cast<const DRAWITEMSTRUCT*>(lParam));
    }
    if (message == WM_NOTIFY) {
        NMHDR* notification = reinterpret_cast<NMHDR*>(lParam);
        if (notification->hwndFrom == tooltip
                && notification->code == TTN_GETDISPINFOW) {
            NMTTDISPINFOW* information = reinterpret_cast<NMTTDISPINFOW*>(lParam);
            swprintf_s(tooltipText, GetLocalizedText(language, TXT_ABOUT_VISIT_TOOLTIP), WEBSITE_URL);
            information->lpszText = tooltipText;
            SetWindowLongPtrW(window, DWLP_MSGRESULT, 0);
            return TRUE;
        }
        if (notification->idFrom == ID_INFO_LINK
                && (notification->code == NM_CLICK || notification->code == NM_RETURN)) {
            OpenWebsite();
            SetWindowLongPtrW(window, DWLP_MSGRESULT, 0);
            return TRUE;
        }
    }
    if (message == WM_DISPLAYCHANGE) {
        Layout();
        return TRUE;
    }
    if (message == WM_THEMECHANGED || message == WM_SETTINGCHANGE) {
        ApplyStyle(true);
        return TRUE;
    }
    if (message == WM_DPICHANGED) {
        const RECT* bounds = reinterpret_cast<const RECT*>(lParam);
        SetWindowPos(window, nullptr, bounds->left, bounds->top, bounds->right - bounds->left,
            bounds->bottom - bounds->top, SWP_NOZORDER | SWP_NOACTIVATE);
        ApplyStyle(true);
        return TRUE;
    }
    if (message == WM_NCDESTROY) {
        if (tooltip != nullptr) {
            DestroyWindow(tooltip);
            tooltip = nullptr;
        }
        if (ownsFont) {
            DeleteObject(uiFont);
        }
        uiFont = nullptr;
        ownsFont = false;
        initialized = false;
        ResetInformationWordBreak();
        if (productIcon != nullptr) {
            DestroyIcon(productIcon);
            productIcon = nullptr;
        }
        if (licenseFont != nullptr) {
            DeleteObject(licenseFont);
            licenseFont = nullptr;
        }
        placement->SetSavedHandler(nullptr);
        window = nullptr;
    }
    return FALSE;
}

/// Saves captured placement without committing pending animation preferences.
void AboutForm::StateSaved(PersistWindowState* sender, const PersistWindowStateEventArgs&, void* context) {
    const AboutForm* form = static_cast<const AboutForm*>(context);
    if (form == nullptr || !form->initialized || form->settings == nullptr) {
        return;
    }
    form->settings->aboutWindowState = sender->GetState();
    form->settings->SaveWindowPositions();
}

/// Associates the native dialog with its form object and dispatches only this form's messages.
INT_PTR CALLBACK AboutForm::DialogProc(HWND dialog, UINT message, WPARAM wParam, LPARAM lParam) {
    if (message == WM_INITDIALOG) {
        AboutForm* form = reinterpret_cast<AboutForm*>(lParam);
        form->window = dialog;
        SetWindowLongPtrW(dialog, DWLP_USER, reinterpret_cast<LONG_PTR>(form));
        return FALSE;
    }
    AboutForm* form = reinterpret_cast<AboutForm*>(GetWindowLongPtrW(dialog, DWLP_USER));
    return form == nullptr ? FALSE : form->HandleMessage(message, wParam, lParam);
}

/// Creates or activates this form with its own template, state, controls and saved placement.
void AboutForm::Show(HWND owner, HINSTANCE module, AppSettings& preferences, const ProgramIcons& icons,
        PersistWindowState& state, AppLanguage selectedLanguage) {
    instance = module;
    placement = &state;
    if (window != nullptr && IsWindow(window)) {
        placement->BringToFront();
        return;
    }
    settings = &preferences;
    programIcons = &icons;
    language = selectedLanguage;
    initialized = false;
    placement->SetSavingOptions(PersistWindowStateSavingOptions::None);
    placement->SetDetectionOptions(WindowDetectionOptions::NoDetection);
    placement->SetUseWindowsDefaultLocation(false);
    placement->SetUseWindowsDefaultSize(false);
    placement->Load(settings->aboutWindowState);
    UINT resource = IDD_ABOUT;
    DLGTEMPLATE* definition = LoadSystemDialogTemplate(instance, resource, nullptr);
    if (definition == nullptr) {
        return;
    }
    window = CreateDialogIndirectParamW(instance, definition, nullptr, DialogProc,
        reinterpret_cast<LPARAM>(this));
    HeapFree(GetProcessHeap(), 0, definition);
    if (window == nullptr) {
        return;
    }
    uiFont = reinterpret_cast<HFONT>(SendMessageW(window, WM_GETFONT, 0, 0));
    referenceDpi = GetSystemDialogDpi(window);
    referenceLicense = SIZE{
        MulDiv(ABOUT_LICENSE_WIDTH_96DPI, referenceDpi, 96),
        MulDiv(ABOUT_LICENSE_HEIGHT_96DPI, referenceDpi, 96)
    };
    initialized = true;
    if (!InstallSelectionEditHandler(GetDlgItem(window, ID_INFO_TEXT))
            || !ApplyStyle(false)) {
        DestroyWindow(window);
        return;
    }
    SetWindowTheme(window, nullptr, nullptr);
    SendDlgItemMessageW(window, ID_INFO_TEXT, EM_SETLIMITTEXT, 0x7FFFFFFE, 0);
    HWND text = GetDlgItem(window, ID_INFO_TEXT);
    SendMessageW(text, EM_SETWORDBREAKPROC, 0, reinterpret_cast<LPARAM>(InformationWordBreakProc));
    if (!SetWindowSubclass(text, InformationTextSubclassProc, INFORMATION_TEXT_SUBCLASS_ID, 0)
            || !SetWindowSubclass(text, AboutLicenseSubclassProc, ABOUT_LICENSE_SUBCLASS_ID, 0)) {
        DestroyWindow(window);
        return;
    }
    std::wstring license = LoadLicenseText();
    SetWindowTextW(text, license.empty()
        ? GetLocalizedText(language, TXT_ABOUT_LICENSE_UNAVAILABLE)
        : license.c_str());
    const int controls[] = { ID_INFO_PRODUCT, ID_INFO_WEBSITE, ID_INFO_LINK, ID_INFO_ICON };
    for (int id : controls) {
        if (!SetWindowSubclass(GetDlgItem(window, id), ControlSubclassProc, ABOUT_CONTROL_SUBCLASS_ID,
            reinterpret_cast<DWORD_PTR>(this))) {
            DestroyWindow(window);
            return;
        }
    }
    tooltip = CreateControlTooltip(window, GetDlgItem(window, ID_INFO_LINK), LPSTR_TEXTCALLBACKW);
    if (tooltip == nullptr) {
        DestroyWindow(window);
        return;
    }
    SendMessageW(tooltip, WM_SETFONT, reinterpret_cast<WPARAM>(uiFont), FALSE);
    RefreshInformationWindows(owner);
    SendMessageW(text, EM_SETSEL, 0, 0);
    placement->SetDisableSaveSize(true);
    placement->SetDisableSaveWindowState(true);
    placement->SetSavedHandler(StateSaved, this);
    const PersistWindowStateData& saved = placement->GetState();
    bool defaultPosition = saved.x == CW_USEDEFAULT || saved.y == CW_USEDEFAULT;
    if (defaultPosition && !PositionInformationWindowByWindowsDefault(window)
            || !placement->Attach(window, "About")) {
        DestroyWindow(window);
        return;
    }
    Layout();
    UpdateInformationWindowsTopmost(owner);
    SetFocus(GetDlgItem(window, ID_INFO_CLOSE));
    placement->Show();
}
