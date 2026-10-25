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
 * Last modified for version 1.2.2.0
 */

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "MixedControls.h"
#include <windowsx.h>
#include <uxtheme.h>
#include <vssym32.h>
#include <algorithm>
#include <memory>
#include <new>
#include <string>

#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "uxtheme.lib")

/// Native control categories that support mixed-value feedback.
enum class MixedControlKind {
    Trackbar,
    RadioButton,
    PushButton
};

/// Control-specific state retained by the mixed-value subclass.
struct MixedControlsState {
    MixedControlKind kind = MixedControlKind::Trackbar;
    bool mixed = false;
};

constexpr UINT_PTR MIXED_CONTROL_SUBCLASS = 0xF506;
constexpr WORD MIXED_DITHER_BITS[]{ 0x0055, 0x00AA, 0x0055, 0x00AA, 0x0055, 0x00AA, 0x0055, 0x00AA };

/// Adds mixed-state feedback without replacing native mouse capture, focus, keyboard handling or painting.
static LRESULT CALLBACK MixedControlsProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam, UINT_PTR subclassId,
    DWORD_PTR referenceData);

/// Finds state owned by this control subclass without changing the native window data.
static MixedControlsState* ControlState(HWND window) {
    DWORD_PTR referenceData = 0;
    return window && GetWindowSubclass(window, MixedControlsProc, MIXED_CONTROL_SUBCLASS, &referenceData)
        ? reinterpret_cast<MixedControlsState*>(referenceData)
        : nullptr;
}

/// Reports whether visual styles are active for Windows and the current application.
static bool AreVisualStylesActive() {
    return IsThemeActive() && IsAppThemed();
}

/// Tests the native raster's RGB value without depending on its unused alpha byte.
static bool IsPaintedPixel(const DWORD* pixels, LONG width, LONG x, LONG y, DWORD background) {
    const std::size_t index = static_cast<std::size_t>(y) * static_cast<std::size_t>(width) + static_cast<std::size_t>(x);
    return (pixels[index] & 0x00FFFFFF) != background;
}

/// Locates the first painted pixels at the native glyph side of the control.
static bool IsPaintedColumn(const DWORD* pixels, LONG width, LONG height, LONG x, DWORD background) {
    for (LONG y = 0; y < height; y++) {
        if (IsPaintedPixel(pixels, width, x, y, background)) {
            return true;
        }
    }
    return false;
}

/// Measures the native circle on its outer half so caption and focus pixels cannot extend its bounds.
static RECT RadioPixelBounds(const DWORD* pixels, LONG width, LONG height, DWORD background, bool rightAligned) {
    RECT glyph{ 0, height, width, 0 };
    if (rightAligned) {
        while (glyph.right > 0 && !IsPaintedColumn(pixels, width, height, glyph.right - 1, background)) {
            glyph.right--;
        }
    } else {
        while (glyph.left < width && !IsPaintedColumn(pixels, width, height, glyph.left, background)) {
            glyph.left++;
        }
    }
    const LONG first = rightAligned ? glyph.right / 2 : glyph.left;
    const LONG last = rightAligned ? glyph.right : glyph.left + (width - glyph.left + 1) / 2;
    for (LONG y = 0; y < height; y++) {
        for (LONG x = first; x < last; x++) {
            if (IsPaintedPixel(pixels, width, x, y, background)) {
                glyph.top = std::min(glyph.top, y);
                glyph.bottom = std::max(glyph.bottom, y + 1);
                break;
            }
        }
    }
    const LONG diameter = std::max(0L, glyph.bottom - glyph.top);
    if (rightAligned) {
        glyph.left = std::max(0L, glyph.right - diameter);
    } else {
        glyph.right = std::min(width, glyph.left + diameter);
    }
    return glyph;
}

/// Follows the painted outer edges row by row, including antialiased pixels and filling the glyph's interior.
static HRGN CreatePaintedPixelRegion(const DWORD* pixels, const RECT& bounds, bool radio, bool rightAligned) {
    const LONG width = bounds.right - bounds.left;
    const LONG height = bounds.bottom - bounds.top;
    const COLORREF color = GetSysColor(COLOR_BTNFACE);
    const DWORD background =
        static_cast<DWORD>(GetRValue(color)) << 16 | static_cast<DWORD>(GetGValue(color)) << 8 | GetBValue(color);
    const RECT glyph = radio
        ? RadioPixelBounds(pixels, width, height, background, rightAligned)
        : RECT{ 0, 0, width, height };
    HRGN region = CreateRectRgn(0, 0, 0, 0);
    if (!region) {
        return nullptr;
    }
    for (LONG y = glyph.top; y < glyph.bottom; y++) {
        LONG first = glyph.left;
        LONG last = glyph.right;
        while (first < last && !IsPaintedPixel(pixels, width, first, y, background)) {
            first++;
        }
        while (last > first && !IsPaintedPixel(pixels, width, last - 1, y, background)) {
            last--;
        }
        if (first == last) {
            continue;
        }
        HRGN row = CreateRectRgn(bounds.left + first, bounds.top + y, bounds.left + last, bounds.top + y + 1);
        const bool added = row && CombineRgn(region, region, row, RGN_OR) != ERROR;
        if (row) {
            DeleteObject(row);
        }
        if (!added) {
            DeleteObject(region);
            return nullptr;
        }
    }
    return region;
}

/// Reads the image Windows has just painted rather than predicting the control's glyph position or silhouette.
static HRGN CreatePaintedControlRegion(HDC source, const RECT& bounds, bool radio, bool rightAligned) {
    const LONG width = bounds.right - bounds.left;
    const LONG height = bounds.bottom - bounds.top;
    if (width <= 0 || height <= 0) {
        return nullptr;
    }
    HDC capture = CreateCompatibleDC(source);
    if (!capture) {
        return nullptr;
    }
    BITMAPINFO information{};
    information.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    information.bmiHeader.biWidth = width;
    information.bmiHeader.biHeight = -height;
    information.bmiHeader.biPlanes = 1;
    information.bmiHeader.biBitCount = 32;
    information.bmiHeader.biCompression = BI_RGB;
    void* pixels = nullptr;
    HBITMAP bitmap = CreateDIBSection(capture, &information, DIB_RGB_COLORS, &pixels, nullptr, 0);
    if (!bitmap) {
        DeleteDC(capture);
        return nullptr;
    }
    HGDIOBJ previous = SelectObject(capture, bitmap);
    HRGN region = nullptr;
    if (previous && previous != HGDI_ERROR) {
        if (BitBlt(capture, 0, 0, width, height, source, bounds.left, bounds.top, SRCCOPY)) {
            GdiFlush();
            region = CreatePaintedPixelRegion(static_cast<const DWORD*>(pixels), bounds, radio, rightAligned);
        }
        SelectObject(capture, previous);
    }
    DeleteObject(bitmap);
    DeleteDC(capture);
    return region;
}

/// Creates the classic alternating-dot pattern without relying on the active theme's brush cache.
static HBRUSH CreateMixedDitherBrush() {
    HBITMAP bitmap = CreateBitmap(8, 8, 1, 1, MIXED_DITHER_BITS);
    if (!bitmap) {
        return nullptr;
    }
    HBRUSH brush = CreatePatternBrush(bitmap);
    DeleteObject(bitmap);
    return brush;
}

/// Fills only the requested interior with the same system-color dot pattern under every visual style.
static void FillMixedSurface(HDC dc, const RECT& interior) {
    SetTextColor(dc, GetSysColor(COLOR_BTNSHADOW));
    SetBkColor(dc, GetSysColor(COLOR_BTNHIGHLIGHT));
    SetBkMode(dc, OPAQUE);
    HBRUSH brush = CreateMixedDitherBrush();
    if (brush) {
        FillRect(dc, &interior, brush);
        DeleteObject(brush);
    }
}

/// Selects the native button state without replacing its border, hover or keyboard-focus behavior.
static int PushButtonThemeState(const NMCUSTOMDRAW& draw) {
    if (!IsWindowEnabled(draw.hdr.hwndFrom)) {
        return PBS_DISABLED;
    }
    if ((draw.uItemState & CDIS_SELECTED) != 0) {
        return PBS_PRESSED;
    }
    if ((draw.uItemState & CDIS_HOT) != 0) {
        return PBS_HOT;
    }
    return (GetWindowLongPtrW(draw.hdr.hwndFrom, GWL_STYLE) & BS_TYPEMASK) == BS_DEFPUSHBUTTON
        ? PBS_DEFAULTED
        : PBS_NORMAL;
}

/// Resolves the native unchecked-radio state without changing its hover, press or disabled appearance.
static int RadioButtonThemeState(const NMCUSTOMDRAW& draw) {
    if (!IsWindowEnabled(draw.hdr.hwndFrom)) {
        return RBS_UNCHECKEDDISABLED;
    }
    if ((draw.uItemState & CDIS_SELECTED) != 0) {
        return RBS_UNCHECKEDPRESSED;
    }
    return (draw.uItemState & CDIS_HOT) != 0 ? RBS_UNCHECKEDHOT : RBS_UNCHECKEDNORMAL;
}

/// Restricts raster inspection to the glyph side; the painted pixels determine its actual position and shape.
static RECT RadioCaptureRect(const NMCUSTOMDRAW& draw) {
    const HWND window = draw.hdr.hwndFrom;
    RECT bounds{};
    GetClientRect(window, &bounds);
    SIZE glyph{ GetSystemMetrics(SM_CXMENUCHECK), GetSystemMetrics(SM_CYMENUCHECK) };
    HTHEME theme = GetWindowTheme(window);
    if (AreVisualStylesActive() && theme) {
        GetThemePartSize(theme, draw.hdc, BP_RADIOBUTTON, RadioButtonThemeState(draw), &bounds, TS_DRAW, &glyph);
    }
    const LONG width = std::min(bounds.right - bounds.left, glyph.cx);
    const LONG_PTR style = GetWindowLongPtrW(window, GWL_STYLE);
    const LONG_PTR extended = GetWindowLongPtrW(window, GWL_EXSTYLE);
    if ((style & BS_RIGHTBUTTON) != 0 || (extended & WS_EX_RIGHT) != 0) {
        bounds.left = bounds.right - width;
    } else {
        bounds.right = bounds.left + width;
    }
    return bounds;
}

/// Repaints push-button text with its unchanged native font, content rectangle, mnemonic and pressed alignment.
static void DrawMixedPushButtonText(const NMCUSTOMDRAW& draw, RECT content, bool themed) {
    const HWND window = draw.hdr.hwndFrom;
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(window, WM_GETFONT, 0, 0));
    if (font) {
        SelectObject(draw.hdc, font);
    }
    const LONG_PTR style = GetWindowLongPtrW(window, GWL_STYLE);
    if (!themed && (draw.uItemState & CDIS_SELECTED) != 0) {
        OffsetRect(&content, GetSystemMetrics(SM_CXBORDER), GetSystemMetrics(SM_CYBORDER));
    }
    const int length = GetWindowTextLengthW(window);
    std::wstring caption(static_cast<std::size_t>(length) + 1, L'\0');
    GetWindowTextW(window, caption.data(), length + 1);
    caption.resize(static_cast<std::size_t>(length));
    const LRESULT uiState = SendMessageW(window, WM_QUERYUISTATE, 0, 0);
    UINT format = DT_SINGLELINE | DT_END_ELLIPSIS;
    format |= (style & BS_CENTER) == BS_LEFT ? DT_LEFT : (style & BS_CENTER) == BS_RIGHT ? DT_RIGHT : DT_CENTER;
    format |= (style & BS_VCENTER) == BS_TOP ? DT_TOP : (style & BS_VCENTER) == BS_BOTTOM ? DT_BOTTOM : DT_VCENTER;
    if ((uiState & UISF_HIDEACCEL) != 0) {
        format |= DT_HIDEPREFIX;
    }
    SetBkMode(draw.hdc, TRANSPARENT);
    SetTextColor(draw.hdc, GetSysColor(COLOR_BTNTEXT));
    DrawTextW(draw.hdc, caption.c_str(), length, &content, format);
    if ((draw.uItemState & CDIS_FOCUS) != 0 && (uiState & UISF_HIDEFOCUS) == 0) {
        InflateRect(&content, -GetSystemMetrics(SM_CXBORDER), -GetSystemMetrics(SM_CYBORDER));
        DrawFocusRect(draw.hdc, &content);
    }
}

/// Dithers only a mixed radio glyph or push-button face, preserving native surroundings.
static void DrawMixedButton(const NMCUSTOMDRAW& draw, MixedControlKind kind) {
    const HWND window = draw.hdr.hwndFrom;
    const bool themed = AreVisualStylesActive() && GetWindowTheme(window) != nullptr;
    const int saved = SaveDC(draw.hdc);
    if (saved == 0) {
        return;
    }
    RECT interior{};
    if (kind == MixedControlKind::PushButton) {
        GetClientRect(window, &interior);
        RECT content = interior;
        if (!themed || FAILED(GetThemeBackgroundContentRect(GetWindowTheme(window), draw.hdc, BP_PUSHBUTTON,
            PushButtonThemeState(draw), &interior, &content))) {
            InflateRect(&content, -2 * GetSystemMetrics(SM_CXBORDER), -2 * GetSystemMetrics(SM_CYBORDER));
        }
        interior = content;
    } else {
        interior = RadioCaptureRect(draw);
        const LONG_PTR style = GetWindowLongPtrW(window, GWL_STYLE);
        const LONG_PTR extended = GetWindowLongPtrW(window, GWL_EXSTYLE);
        const bool rightAligned = (style & BS_RIGHTBUTTON) != 0 || (extended & WS_EX_RIGHT) != 0;
        HRGN region = CreatePaintedControlRegion(draw.hdc, interior, true, rightAligned);
        if (!region) {
            RestoreDC(draw.hdc, saved);
            return;
        }
        ExtSelectClipRgn(draw.hdc, region, RGN_AND);
        DeleteObject(region);
    }
    IntersectClipRect(draw.hdc, interior.left, interior.top, interior.right, interior.bottom);
    FillMixedSurface(draw.hdc, interior);
    if (kind == MixedControlKind::PushButton) {
        DrawMixedPushButtonText(draw, interior, themed);
    }
    RestoreDC(draw.hdc, saved);
}

/// Covers the complete native thumb, including its tip, without painting outside its silhouette.
static void DrawMixedThumb(const NMCUSTOMDRAW& draw) {
    const HWND window = draw.hdr.hwndFrom;
    RECT thumb{};
    SendMessageW(window, TBM_GETTHUMBRECT, 0, reinterpret_cast<LPARAM>(&thumb));
    const LONG_PTR style = GetWindowLongPtrW(window, GWL_STYLE);
    if (IsRectEmpty(&thumb) || (style & TBS_NOTHUMB) != 0) {
        return;
    }
    const int saved = SaveDC(draw.hdc);
    if (saved == 0) {
        return;
    }
    HRGN region = CreatePaintedControlRegion(draw.hdc, thumb, false, false);
    if (region) {
        ExtSelectClipRgn(draw.hdc, region, RGN_AND);
        IntersectClipRect(draw.hdc, thumb.left, thumb.top, thumb.right, thumb.bottom);
        FillMixedSurface(draw.hdc, thumb);
        DeleteObject(region);
    }
    RestoreDC(draw.hdc, saved);
}

/// Invalidates only the native control that changed its mixed state or system appearance.
static void InvalidateMixedControl(HWND window) {
    InvalidateRect(window, nullptr, FALSE);
}

/// Commits the displayed representative value on mouse-down, even when the native thumb does not move.
static void NotifyMixedThumbClick(HWND window, LPARAM coordinates) {
    RECT thumb{};
    SendMessageW(window, TBM_GETTHUMBRECT, 0, reinterpret_cast<LPARAM>(&thumb));
    const POINT point{ GET_X_LPARAM(coordinates), GET_Y_LPARAM(coordinates) };
    if (!PtInRect(&thumb, point)) {
        return;
    }
    NMHDR notification{};
    notification.hwndFrom = window;
    notification.idFrom = static_cast<UINT_PTR>(GetDlgCtrlID(window));
    notification.code = NM_CLICK;
    SendMessageW(GetParent(window), WM_NOTIFY, notification.idFrom, reinterpret_cast<LPARAM>(&notification));
}

/// Adds mixed-state feedback without replacing native mouse capture, focus, keyboard handling or painting.
static LRESULT CALLBACK MixedControlsProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam,
        UINT_PTR subclassId, DWORD_PTR referenceData) {
    MixedControlsState* state = reinterpret_cast<MixedControlsState*>(referenceData);
    if ((message == WM_LBUTTONDOWN || message == WM_LBUTTONDBLCLK)
            && state->mixed
            && state->kind == MixedControlKind::Trackbar
            && IsWindowEnabled(window)) {
        NotifyMixedThumbClick(window, lParam);
        if (!IsWindow(window)) {
            return 0;
        }
    }
    if (message == WM_NCDESTROY) {
        RemoveWindowSubclass(window, MixedControlsProc, subclassId);
        delete state;
        return DefSubclassProc(window, message, wParam, lParam);
    }
    const LRESULT result = DefSubclassProc(window, message, wParam, lParam);
    if (MixedControls::IsMixed(window) && (message == WM_THEMECHANGED
        || message == WM_SYSCOLORCHANGE
        || message == WM_SETTINGCHANGE
        || message == WM_DPICHANGED_AFTERPARENT)) {
        InvalidateMixedControl(window);
    }
    return result;
}

/// Installs mixed-state feedback without changing the native control class or behavior.
bool MixedControls::Attach(HWND window) {
    if (!window) {
        return false;
    }
    if (ControlState(window)) {
        return true;
    }
    std::unique_ptr<MixedControlsState> state(new(std::nothrow) MixedControlsState);
    if (!state) {
        return false;
    }
    wchar_t className[32]{};
    GetClassNameW(window, className, static_cast<int>(std::size(className)));
    if (_wcsicmp(className, TRACKBAR_CLASSW) != 0) {
        if (_wcsicmp(className, L"BUTTON") != 0) {
            return false;
        }
        const LONG_PTR type = GetWindowLongPtrW(window, GWL_STYLE) & BS_TYPEMASK;
        if (type == BS_RADIOBUTTON || type == BS_AUTORADIOBUTTON) {
            state->kind = MixedControlKind::RadioButton;
        } else if (type == BS_PUSHBUTTON || type == BS_DEFPUSHBUTTON) {
            state->kind = MixedControlKind::PushButton;
        } else {
            return false;
        }
    }
    if (!SetWindowSubclass(window, MixedControlsProc, MIXED_CONTROL_SUBCLASS, reinterpret_cast<DWORD_PTR>(state.get()))) {
        return false;
    }
    state.release();
    return true;
}

/// Returns whether this control currently represents different selected-monitor values.
bool MixedControls::IsMixed(HWND window) {
    const MixedControlsState* state = ControlState(window);
    return state && state->mixed;
}

/// Changes only the mixed-value marker and invalidates the affected control when needed.
void MixedControls::SetMixed(HWND window, bool mixed) {
    MixedControlsState* state = ControlState(window);
    if (state && state->mixed != mixed) {
        state->mixed = mixed;
        InvalidateMixedControl(window);
    }
}

/// Leaves equal values entirely native and decorates only the affected mixed-value control surface.
LRESULT MixedControls::CustomDraw(const NMCUSTOMDRAW& draw) {
    const MixedControlsState* state = ControlState(draw.hdr.hwndFrom);
    if (!state || !state->mixed) {
        return CDRF_DODEFAULT;
    }
    if (draw.dwDrawStage == CDDS_PREPAINT) {
        return CDRF_NOTIFYPOSTPAINT;
    }
    if (draw.dwDrawStage == CDDS_POSTPAINT) {
        if (state->kind == MixedControlKind::Trackbar) {
            DrawMixedThumb(draw);
        } else {
            DrawMixedButton(draw, state->kind);
        }
    }
    return CDRF_DODEFAULT;
}
