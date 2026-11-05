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

#pragma once

#include <span>
#include <string>
#include <string_view>
#include <vector>

/// Named pattern metadata and its RLE view into the retained catalog storage.
struct LifePattern {
    std::wstring id;
    std::wstring name;
    unsigned width = 0;
    unsigned height = 0;
    bool repeatable = false;
    std::string_view rle;
    std::wstring caption;
};

/// Loads and exposes the validated embedded catalog of known Life patterns.
class PatternCatalog final {
    unsigned char* storage = nullptr;
    std::vector<LifePattern> entries;

    /// Unpacks the embedded catalog and retains its bytes for every pattern's RLE view.
    PatternCatalog();

    /// Releases the decompressed catalog when the process-owned instance is destroyed.
    ~PatternCatalog();

    PatternCatalog(const PatternCatalog&) = delete;
    PatternCatalog& operator=(const PatternCatalog&) = delete;

public:
    /// Returns the immutable pattern catalog, loading it once on first use.
    static std::span<const LifePattern> All();

    /// Returns the one-based pattern selection, or zero for an empty or unknown identifier.
    static unsigned Find(std::wstring_view id);
};
