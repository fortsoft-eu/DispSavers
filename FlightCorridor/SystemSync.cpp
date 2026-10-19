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

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

using TryAcquireSRWLockFunction = BOOLEAN(WINAPI*)(PSRWLOCK);

/// Attempts an exclusive SRW acquisition with a dynamically selected implementation.
static BOOLEAN WINAPI TryAcquireSRWLockCompatible(PSRWLOCK lock);

/// Supplies the decorated Win32 import used by the MSVC static runtime.
#pragma warning(push)
#pragma warning(disable : 4483)
extern "C" const TryAcquireSRWLockFunction
    __identifier("_imp__TryAcquireSRWLockExclusive@4") = TryAcquireSRWLockCompatible;
#pragma warning(pop)

/// Resolves the native nonblocking lock operation without making it a load-time dependency.
static TryAcquireSRWLockFunction ResolveTryAcquireSRWLockFunction() {
    const HMODULE kernel = GetModuleHandleW(L"kernel32.dll");
    if (kernel) {
        return reinterpret_cast<TryAcquireSRWLockFunction>(GetProcAddress(kernel, "TryAcquireSRWLockExclusive"));
    }
    return nullptr;
}

/// Acquires only an empty Vista SRW lock by atomically changing its state from zero to the exclusive ownership bit.
/// The Vista SRW representation is required here; contended and shared states are left unchanged.
static BOOLEAN TryAcquireVistaSRWLock(PSRWLOCK lock) {
    return InterlockedCompareExchangePointer(&lock->Ptr, reinterpret_cast<void*>(1), nullptr) == nullptr;
}

/// Uses the native Windows function when present, otherwise performs a nonblocking Vista-compatible acquisition.
static BOOLEAN WINAPI TryAcquireSRWLockCompatible(PSRWLOCK lock) {
    static const TryAcquireSRWLockFunction tryAcquire = ResolveTryAcquireSRWLockFunction();
    if (tryAcquire) {
        return tryAcquire(lock);
    }
    return TryAcquireVistaSRWLock(lock);
}
