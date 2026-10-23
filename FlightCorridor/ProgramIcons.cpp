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
 * Last modified for version 1.2.0.2
 */

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "ProgramIcons.h"
#include <shlobj.h>
#include <shellapi.h>
#include <string>

/// Resolves the full path to a Windows system icon library.
static std::wstring SystemIconLibraryPath(const wchar_t* libraryName) {
    wchar_t systemDirectory[MAX_PATH]{};
    const UINT length = GetSystemDirectoryW(systemDirectory, MAX_PATH);
    if (length == 0 || length >= static_cast<UINT>(MAX_PATH)) {
        return std::wstring{};
    }
    std::wstring libraryPath(systemDirectory, length);
    libraryPath += L"\\";
    libraryPath += libraryName;
    return libraryPath;
}

/// Loads matching large and small icons from a Windows system library.
static bool ExtractSystemIconPair(const wchar_t* libraryName, int iconIndex, HICON& largeIcon, HICON& smallIcon) {
    const std::wstring libraryPath = SystemIconLibraryPath(libraryName);
    if (libraryPath.empty()) {
        return false;
    }
    largeIcon = nullptr;
    smallIcon = nullptr;
    if (ExtractIconExW(libraryPath.c_str(), iconIndex, &largeIcon, &smallIcon, 1) == 0) {
        return false;
    }
    if (largeIcon == nullptr && smallIcon != nullptr) {
        largeIcon = CopyIcon(smallIcon);
    }
    if (smallIcon == nullptr && largeIcon != nullptr) {
        smallIcon = CopyIcon(largeIcon);
    }
    if (largeIcon == nullptr || smallIcon == nullptr) {
        if (largeIcon != nullptr) {
            DestroyIcon(largeIcon);
        }
        if (smallIcon != nullptr) {
            DestroyIcon(smallIcon);
        }
        largeIcon = nullptr;
        smallIcon = nullptr;
        return false;
    }
    return true;
}

/// Releases any loaded icons.
ProgramIcons::~ProgramIcons() {
    Reset();
}

/// Loads the application icons from shell32.dll at index 34.
bool ProgramIcons::Load() {
    HICON largeIcon = nullptr;
    HICON loadedSmallIcon = nullptr;
    if (!ExtractSystemIconPair(L"shell32.dll", 34, largeIcon, loadedSmallIcon)) {
        return false;
    }
    Reset();
    large = largeIcon;
    smallIcon = loadedSmallIcon;
    return true;
}

/// Loads an icon at the requested pixel size; the caller must release it with DestroyIcon.
HICON ProgramIcons::LoadSized(UINT size) const {
    const std::wstring libraryPath = SystemIconLibraryPath(L"shell32.dll");
    if (libraryPath.empty()) {
        return nullptr;
    }
    HICON icon = nullptr;
    if (SHDefExtractIconW(libraryPath.c_str(), 34, 0, &icon, nullptr, size) != S_OK) {
        if (icon != nullptr) {
            DestroyIcon(icon);
        }
        return nullptr;
    }
    return icon;
}

/// Returns the large application icon, or null when loading has failed.
HICON ProgramIcons::Large() const {
    return large;
}

/// Returns the small application icon, or null when loading has failed.
HICON ProgramIcons::Small() const {
    return smallIcon;
}

/// Releases the currently owned icon handles.
void ProgramIcons::Reset() {
    if (smallIcon != nullptr && smallIcon != large) {
        DestroyIcon(smallIcon);
    }
    if (large != nullptr) {
        DestroyIcon(large);
    }
    large = nullptr;
    smallIcon = nullptr;
}
