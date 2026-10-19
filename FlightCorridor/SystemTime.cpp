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
#include <ctime>

using GetSystemTimeFunction = VOID(WINAPI*)(LPFILETIME);

constexpr long NANOSECONDS_PER_SECOND = 1000000000L;
constexpr long NANOSECONDS_PER_MILLISECOND = 1000000L;
constexpr long long WINDOWS_EPOCH = 0x19DB1DED53E8000LL;

/// Resolves the precise system clock when the running Windows version provides it.
static GetSystemTimeFunction ResolveSystemTimeFunction() {
    const HMODULE kernel = GetModuleHandleW(L"kernel32.dll");
    if (kernel) {
        return reinterpret_cast<GetSystemTimeFunction>(GetProcAddress(kernel, "GetSystemTimePreciseAsFileTime"));
    }
    return nullptr;
}

/// Normalizes nanoseconds into the interval from zero through one second.
static void NormalizeTimespec(_timespec64& value) {
    while (value.tv_nsec < 0) {
        --value.tv_sec;
        value.tv_nsec += NANOSECONDS_PER_SECOND;
    }
    while (value.tv_nsec >= NANOSECONDS_PER_SECOND) {
        ++value.tv_sec;
        value.tv_nsec -= NANOSECONDS_PER_SECOND;
    }
}

/// Returns a nonnegative normalized difference between two absolute times.
static _timespec64 TimespecDifference(const _timespec64& target, const _timespec64& current) {
    _timespec64 difference = target;
    NormalizeTimespec(difference);
    difference.tv_sec -= current.tv_sec;
    difference.tv_nsec -= current.tv_nsec;
    NormalizeTimespec(difference);
    if (difference.tv_sec < 0 || difference.tv_sec == 0 && difference.tv_nsec <= 0) {
        difference.tv_sec = 0;
        difference.tv_nsec = 0;
    }
    return difference;
}

/// Supplies the MSVC static runtime with a system-time implementation compatible with older Windows.
extern "C" long long __cdecl _Xtime_get_ticks() noexcept {
    static const GetSystemTimeFunction getSystemTime = ResolveSystemTimeFunction();
    FILETIME fileTime{};
    if (getSystemTime != nullptr) {
        getSystemTime(&fileTime);
    } else {
        GetSystemTimeAsFileTime(&fileTime);
    }
    return (static_cast<long long>(fileTime.dwHighDateTime) << 32) + static_cast<long long>(fileTime.dwLowDateTime)
        - WINDOWS_EPOCH;
}

/// Returns the current UTC time in the representation expected by the MSVC runtime.
extern "C" void __cdecl _Timespec64_get_sys(_timespec64* value) noexcept {
    constexpr long long ticksPerSecond = NANOSECONDS_PER_SECOND / 100;
    const unsigned long long ticks = _Xtime_get_ticks();
    value->tv_sec = static_cast<__time64_t>(ticks / ticksPerSecond);
    value->tv_nsec = static_cast<long>(ticks % ticksPerSecond) * 100;
}

/// Converts a difference between two absolute times to rounded-up milliseconds.
extern "C" long __cdecl _Xtime_diff_to_millis2(const _timespec64* target, const _timespec64* current) noexcept {
    const _timespec64 difference = TimespecDifference(*target, *current);
    return static_cast<long>(difference.tv_sec * 1000
        + (static_cast<long long>(difference.tv_nsec) + NANOSECONDS_PER_MILLISECOND - 1) / NANOSECONDS_PER_MILLISECOND);
}

/// Converts the interval from the current time to an absolute time into milliseconds.
extern "C" long __cdecl _Xtime_diff_to_millis(const _timespec64* target) noexcept {
    _timespec64 current{};
    _Timespec64_get_sys(&current);
    return _Xtime_diff_to_millis2(target, &current);
}

/// Implements the UTC clock query expected by the MSVC runtime.
extern "C" int __cdecl xtime_get(_timespec64* value, int type) noexcept {
    if (type != TIME_UTC || value == nullptr) {
        return 0;
    }
    _Timespec64_get_sys(value);
    return TIME_UTC;
}

/// Returns the current high-resolution performance-counter value.
extern "C" long long __cdecl _Query_perf_counter() noexcept {
    LARGE_INTEGER value{};
    QueryPerformanceCounter(&value);
    return value.QuadPart;
}

/// Returns the high-resolution performance-counter frequency.
extern "C" long long __cdecl _Query_perf_frequency() noexcept {
    LARGE_INTEGER value{};
    QueryPerformanceFrequency(&value);
    return value.QuadPart;
}
