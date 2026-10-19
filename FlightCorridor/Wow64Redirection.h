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

/// Temporarily disables WOW64 file-system redirection and restores it on destruction.
class Wow64Redirection {

public:
    /// Disables redirection when the operating system provides the required functions.
    Wow64Redirection();

    /// Restores the file-system redirection state saved by the constructor.
    ~Wow64Redirection();

    /// Prevents copying responsibility for restoring file-system redirection.
    Wow64Redirection(const Wow64Redirection&) = delete;

    /// Prevents copying responsibility for restoring file-system redirection.
    Wow64Redirection& operator=(const Wow64Redirection&) = delete;

private:
    using DisableFunction = BOOL(WINAPI*)(PVOID*);
    using RevertFunction = BOOL(WINAPI*)(PVOID);

    DisableFunction disableFunction = nullptr;
    RevertFunction revertFunction = nullptr;
    PVOID previousState = nullptr;
    bool disabled = false;
};
