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
 * Last modified for version 1.2.0.0
 */

#pragma once

#include <windows.h>

/// Owns the large and small application icons loaded from a Windows system library.
class ProgramIcons {

public:
    /// Creates an empty icon owner.
    ProgramIcons() = default;

    /// Releases any loaded icons.
    ~ProgramIcons();

    /// Prevents copying ownership of icon handles.
    ProgramIcons(const ProgramIcons&) = delete;

    /// Prevents copying ownership of icon handles.
    ProgramIcons& operator=(const ProgramIcons&) = delete;

    /// Loads the application icons from shell32.dll at index 34.
    bool Load();

    /// Returns the large application icon, or null when loading has failed.
    HICON Large() const;

    /// Returns the small application icon, or null when loading has failed.
    HICON Small() const;

private:
    /// Releases the currently owned icon handles.
    void Reset();

    HICON large = nullptr;
    HICON small = nullptr;
};
