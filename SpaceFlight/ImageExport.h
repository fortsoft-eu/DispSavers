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

#include <windows.h>

/// Uses the same image-format order as the reference export dialog.
enum class SnapshotFormat : unsigned {
    Bmp = 1,
    Gif,
    Jpeg,
    Png,
    Tiff,
    Webp
};

/// Provides one native Save dialog and image-encoding implementation for every saver.
class ImageExport final {

public:
    /// Shows the native Save dialog with the exact image-format names used by MediaInfo.
    static HRESULT ChoosePath(HWND owner, const wchar_t* folder, wchar_t* path, SnapshotFormat& format);

    /// Encodes a BGRA image, preserving the destination on failure and supporting memory-only checks.
    static bool Save(const wchar_t* path, SnapshotFormat format, unsigned width, unsigned height,
        unsigned stride, const BYTE* pixels);
};
