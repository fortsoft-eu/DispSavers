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

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "HelpForm.h"
#include APPLICATION_HEADER
#include "resource.h"
#include "SelectionEdit.h"
#include "SystemDialogTemplate.h"
#include <algorithm>
#include <commctrl.h>
#include <uxtheme.h>

/// Returns this form's native window, or null while it is closed.
HWND HelpForm::GetWindow() const {
    return window;
}

/// Destroys this form and releases its controls and owned fonts.
void HelpForm::Close() const {
    if (window != nullptr) {
        if (modal) {
            EndDialog(window, IDCANCEL);
        } else {
            DestroyWindow(window);
        }
    }
}

/// Updates this form's localized captions and content without changing the other form.
void HelpForm::Refresh(AppLanguage selectedLanguage, bool applicationMode) {
    if (window == nullptr || !IsWindow(window)) {
        return;
    }
    language = selectedLanguage;
    appMode = applicationMode;
    std::wstring title = std::wstring(PRODUCT_NAME) + L" — " + GetLocalizedText(language, TXT_HELP);
    SetWindowTextW(window, title.c_str());
    std::wstring helpText = InformationHelpText(language, appMode);
    SetDlgItemTextW(window, ID_INFO_TEXT, helpText.c_str());
    SetDlgItemTextW(window, ID_INFO_CLOSE, Mnemonic(language, TXT_CLOSE).c_str());
    Layout();
}

/// Applies the effective application font and theme to the Help controls.
bool HelpForm::ApplyStyle(bool updateFont) {
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
    HFONT previousFont = ownsFont ? uiFont : nullptr;
    uiFont = font;
    ownsFont = updateFont;
    SendMessageW(window, WM_SETFONT, reinterpret_cast<WPARAM>(font), FALSE);
    const int ids[] = { ID_INFO_TEXT, ID_INFO_CLOSE, ID_INFO_SIZE_GRIP };
    const wchar_t* theme = nullptr;
    for (int id : ids) {
        HWND control = GetDlgItem(window, id);
        if (control == nullptr) {
            continue;
        }
        SendMessageW(control, WM_SETFONT, reinterpret_cast<WPARAM>(font), FALSE);
        SetWindowTheme(control, theme, theme);
    }
    if (previousFont != nullptr) {
        DeleteObject(previousFont);
    }
    ApplyInformationFormIcons(window, instance);
    Layout();
    RedrawWindow(window, nullptr, nullptr, RDW_INVALIDATE | RDW_ERASE | RDW_FRAME | RDW_ALLCHILDREN);
    return true;
}

/// Anchors the Help edit and Close button to the current client area.
void HelpForm::Layout() const {
    if (!initialized || IsIconic(window)) {
        return;
    }
    RECT client = {};
    GetClientRect(window, &client);
    SIZE margin = InformationDialogUnits(uiFont, 8, 8);
    SIZE gap = InformationDialogUnits(uiFont, 4, 6);
    SIZE button = InformationButtonSize(window, uiFont, IDD_HELP);
    int textTop = margin.cy;
    int buttonY = client.bottom - margin.cy - button.cy;
    PlaceInformationControl(window, ID_INFO_CLOSE, client.right - margin.cx - button.cx, buttonY,
        button.cx, button.cy);
    PlaceInformationControl(window, ID_INFO_TEXT, margin.cx, textTop,
        client.right - 2 * margin.cx, buttonY - gap.cy - textTop);
    HWND grip = GetDlgItem(window, ID_INFO_SIZE_GRIP);
    if (grip != nullptr) {
        int width = GetSystemMetrics(SM_CXVSCROLL);
        int height = GetSystemMetrics(SM_CYHSCROLL);
        UINT flags = SWP_NOACTIVATE | (IsZoomed(window) ? SWP_HIDEWINDOW : SWP_SHOWWINDOW);
        SetWindowPos(grip, HWND_BOTTOM, client.right - width, client.bottom - height, width, height, flags);
    }
}

/// Handles this form's native commands, layout, theme, DPI changes and resource cleanup.
INT_PTR HelpForm::HandleMessage(UINT message, WPARAM wParam, LPARAM lParam) {
    if (message == WM_GETFONT && uiFont != nullptr) {
        SetWindowLongPtrW(window, DWLP_MSGRESULT, reinterpret_cast<LONG_PTR>(uiFont));
        return TRUE;
    }
    if (message == WM_SYSCOMMAND && (wParam & 0xFFF0) == SC_SCREENSAVE && ShouldInhibitScreenSaver()) {
        return TRUE;
    }
    if (message == WM_CLOSE
            || message == WM_COMMAND && (LOWORD(wParam) == ID_INFO_CLOSE || LOWORD(wParam) == IDCANCEL)) {
        Close();
        return TRUE;
    }
    if (message == WM_SIZE) {
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
        if (ownsFont) {
            DeleteObject(uiFont);
        }
        uiFont = nullptr;
        ownsFont = false;
        initialized = false;
        ResetInformationWordBreak();
        placement->SetSavedHandler(nullptr);
        window = nullptr;
    }
    return FALSE;
}

/// Saves captured placement without committing pending animation preferences.
void HelpForm::StateSaved(PersistWindowState* sender, const PersistWindowStateEventArgs&, void* context) {
    const HelpForm* form = static_cast<const HelpForm*>(context);
    if (form == nullptr || !form->initialized || form->settings == nullptr) {
        return;
    }
    form->settings->helpWindowState = sender->GetState();
    SaveInformationWindowPositions(*form->settings);
}

/// Associates the native dialog with its form object and dispatches only this form's messages.
INT_PTR CALLBACK HelpForm::DialogProc(HWND dialog, UINT message, WPARAM wParam, LPARAM lParam) {
    if (message == WM_INITDIALOG) {
        HelpForm* form = reinterpret_cast<HelpForm*>(lParam);
        form->window = dialog;
        SetWindowLongPtrW(dialog, DWLP_USER, reinterpret_cast<LONG_PTR>(form));
        if (!form->Initialize()) {
            form->Close();
        }
        return FALSE;
    }
    HelpForm* form = reinterpret_cast<HelpForm*>(GetWindowLongPtrW(dialog, DWLP_USER));
    return form == nullptr ? FALSE : form->HandleMessage(message, wParam, lParam);
}

/// Initializes the same native Help controls and placement for either creation mode.
bool HelpForm::Initialize() {
    if (modal) {
        LONG_PTR extended = GetWindowLongPtrW(window, GWL_EXSTYLE);
        SetWindowLongPtrW(window, GWL_EXSTYLE, extended & ~WS_EX_APPWINDOW | WS_EX_DLGMODALFRAME);
        SetWindowPos(window, nullptr, 0, 0, 0, 0,
            SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
    }
    uiFont = reinterpret_cast<HFONT>(SendMessageW(window, WM_GETFONT, 0, 0));
    initialized = true;
    if (!InstallSelectionEditHandler(GetDlgItem(window, ID_INFO_TEXT))
            || !ApplyStyle(false)) {
        return false;
    }
    SetWindowTheme(window, nullptr, nullptr);
    SendDlgItemMessageW(window, ID_INFO_TEXT, EM_SETLIMITTEXT, 0x7FFFFFFE, 0);
    HWND text = GetDlgItem(window, ID_INFO_TEXT);
    SendMessageW(text, EM_SETWORDBREAKPROC, 0, reinterpret_cast<LPARAM>(InformationWordBreakProc));
    if (!SetWindowSubclass(text, InformationTextSubclassProc, INFORMATION_TEXT_SUBCLASS_ID, 0)) {
        return false;
    }
    RefreshInformationWindows(ownerWindow);
    SendMessageW(text, EM_SETSEL, 0, 0);
    placement->SetDisableSaveSize(false);
    placement->SetDisableSaveWindowState(false);
    placement->SetSavedHandler(StateSaved, this);
    const PersistWindowStateData& saved = placement->GetState();
    bool defaultPosition = saved.x == CW_USEDEFAULT || saved.y == CW_USEDEFAULT;
    if (defaultPosition && !PositionInformationWindowByWindowsDefault(window)
            || !placement->Attach(window, "Help")) {
        return false;
    }
    Layout();
    UpdateInformationWindowsTopmost(ownerWindow);
    SetFocus(GetDlgItem(window, ID_INFO_CLOSE));
    if (!modal) {
        placement->Show();
    }
    return true;
}

/// Creates or activates the shared Help form, optionally using the native modal dialog loop.
void HelpForm::Show(HWND owner, HINSTANCE module, AppSettings& preferences, PersistWindowState& state,
        AppLanguage selectedLanguage, bool applicationMode, bool modalDialog) {
    if (window != nullptr && IsWindow(window)) {
        placement->BringToFront();
        return;
    }
    instance = module;
    ownerWindow = owner;
    placement = &state;
    settings = &preferences;
    language = selectedLanguage;
    appMode = applicationMode;
    modal = modalDialog;
    initialized = false;
    placement->SetSavingOptions(PersistWindowStateSavingOptions::None);
    placement->SetDetectionOptions(WindowDetectionOptions::NoDetection);
    placement->SetUseWindowsDefaultLocation(false);
    placement->SetUseWindowsDefaultSize(false);
    placement->Load(settings->helpWindowState);
    DLGTEMPLATE* definition = LoadSystemDialogTemplate(instance, IDD_HELP, nullptr);
    if (definition == nullptr) {
        return;
    }
    if (modal) {
        ShowModalInformationForm(instance, definition, ownerWindow, DialogProc,
            reinterpret_cast<LPARAM>(this));
    } else {
        CreateDialogIndirectParamW(instance, definition, nullptr, DialogProc, reinterpret_cast<LPARAM>(this));
    }
    HeapFree(GetProcessHeap(), 0, definition);
}
