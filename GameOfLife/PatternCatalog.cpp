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
#include "PatternCatalog.h"
#include "PackedResource.h"
#include "resource.h"
#include <windows.h>
#include <algorithm>
#include <array>
#include <charconv>
#include <cwchar>
#include <limits>
#include <stdexcept>
#include <vector>

constexpr std::string_view CATALOG_HEADER = "LifePatterns";

/// Orders catalog entries by their displayed names before publishing the immutable catalog.
static bool PatternNameLess(const LifePattern& left, const LifePattern& right) {
    return _wcsicmp(left.name.c_str(), right.name.c_str()) < 0;
}

/// Decodes UTF-8 catalog metadata to Unicode and rejects invalid text.
static std::wstring CatalogText(std::string_view value) {
    if (value.empty() || value.size() > static_cast<std::size_t>(std::numeric_limits<int>::max())) {
        throw std::runtime_error("Invalid Game of Life pattern metadata");
    }
    const int length = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, value.data(),
        static_cast<int>(value.size()), nullptr, 0);
    if (length == 0) {
        throw std::runtime_error("Invalid Game of Life pattern text");
    }
    std::wstring text(length, L'\0');
    if (!MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, value.data(), static_cast<int>(value.size()),
        text.data(), length)) {
        throw std::runtime_error("Cannot read Game of Life pattern text");
    }
    return text;
}

/// Parses a positive pattern dimension and rejects malformed or out-of-range values.
static unsigned CatalogDimension(std::string_view value) {
    unsigned dimension = 0;
    const std::from_chars_result parsed =
        std::from_chars(value.data(), value.data() + value.size(), dimension);
    if (parsed.ec != std::errc{} || parsed.ptr != value.data() + value.size() || dimension == 0) {
        throw std::runtime_error("Invalid Game of Life pattern dimensions");
    }
    return dimension;
}

/// Checks run lengths, bounds, termination and the presence of live cells in an RLE pattern.
static bool ValidPatternRle(std::string_view rle, unsigned width, unsigned height) {
    unsigned x = 0;
    unsigned y = 0;
    unsigned count = 0;
    bool digits = false;
    bool living = false;
    for (const char token : rle) {
        if (token >= '0' && token <= '9') {
            const unsigned digit = static_cast<unsigned>(token - '0');
            if (count > (std::numeric_limits<unsigned>::max() - digit) / 10) {
                return false;
            }
            count = count * 10 + digit;
            digits = true;
            continue;
        }
        if (token == ' ' || token == '\t' || token == '\r' || token == '\n') {
            continue;
        }
        if (token == '!') {
            return !digits && living;
        }
        const unsigned amount = digits ? count : 1;
        if (amount == 0) {
            return false;
        }
        if (token == 'b' || token == 'o') {
            if (y >= height || amount > width - x) {
                return false;
            }
            x += amount;
            living = living || token == 'o';
        } else if (token == '$') {
            if (amount > height - y) {
                return false;
            }
            x = 0;
            y += amount;
        } else {
            return false;
        }
        count = 0;
        digits = false;
    }
    return false;
}

/// Consumes one complete catalog line, excluding its line ending.
static std::string_view CatalogLine(std::string_view& bytes) {
    const std::size_t lineEnd = bytes.find('\n');
    if (lineEnd == std::string_view::npos) {
        throw std::runtime_error("Incomplete Game of Life pattern catalogue line");
    }
    std::string_view line = bytes.substr(0, lineEnd);
    bytes.remove_prefix(lineEnd + 1);
    if (!line.empty() && line.back() == '\r') {
        line.remove_suffix(1);
    }
    return line;
}

/// Validates the catalog header, metadata and RLE records before exposing patterns.
static std::vector<LifePattern> ParsePatternCatalog(std::string_view bytes) {
    if (CatalogLine(bytes) != CATALOG_HEADER) {
        throw std::runtime_error("Invalid Game of Life pattern catalogue header");
    }
    std::vector<LifePattern> patterns;
    while (!bytes.empty()) {
        std::string_view metadata = CatalogLine(bytes);
        std::array<std::string_view, 5> fields;
        for (std::size_t index = 0; index + 1 < fields.size(); ++index) {
            const std::size_t separator = metadata.find('\t');
            if (separator == std::string_view::npos) {
                throw std::runtime_error("Incomplete Game of Life pattern metadata");
            }
            fields[index] = metadata.substr(0, separator);
            metadata.remove_prefix(separator + 1);
        }
        fields.back() = metadata;
        if (metadata != "0" && metadata != "1") {
            throw std::runtime_error("Invalid Game of Life pattern repetition flag");
        }
        const unsigned width = CatalogDimension(fields[2]);
        const unsigned height = CatalogDimension(fields[3]);
        const std::size_t terminator = bytes.find('!');
        if (terminator == std::string_view::npos) {
            throw std::runtime_error("Incomplete Game of Life pattern data");
        }
        const std::string_view rle = bytes.substr(0, terminator + 1);
        if (!ValidPatternRle(rle, width, height)) {
            throw std::runtime_error("Invalid Game of Life pattern data");
        }
        bytes.remove_prefix(terminator + 1);
        if (!CatalogLine(bytes).empty()) {
            throw std::runtime_error("Invalid Game of Life pattern record separator");
        }
        const std::wstring name = CatalogText(fields[1]);
        const std::wstring caption = name + L" — " + std::to_wstring(width)
            + L" × " + std::to_wstring(height);
        patterns.push_back(LifePattern{ CatalogText(fields[0]), name,
            width, height, metadata == "1", rle, caption });
    }
    if (patterns.empty()) {
        throw std::runtime_error("Empty Game of Life pattern catalogue");
    }
    return patterns;
}

/// Unpacks the embedded catalog and retains its bytes for every pattern's RLE view.
PatternCatalog::PatternCatalog() {
    const HMODULE module = GetModuleHandleW(nullptr);
    const HRSRC resource = FindResourceW(module, MAKEINTRESOURCEW(IDR_LIFE_PATTERNS), RT_RCDATA);
    const DWORD packedSize = resource ? SizeofResource(module, resource) : 0;
    const HGLOBAL loaded = resource ? LoadResource(module, resource) : nullptr;
    const BYTE* packed = loaded ? static_cast<const BYTE*>(LockResource(loaded)) : nullptr;
    DWORD unpackedSize = 0;
    if (!UnpackLibraryBytes(packed, packedSize, &storage, &unpackedSize)) {
        throw std::runtime_error("Cannot unpack the Game of Life pattern catalogue");
    }
    try {
        entries = ParsePatternCatalog(std::string_view(reinterpret_cast<const char*>(storage), unpackedSize));
        std::stable_sort(entries.begin(), entries.end(), PatternNameLess);
    } catch (...) {
        HeapFree(GetProcessHeap(), 0, storage);
        throw;
    }
}

/// Releases the decompressed catalog when the process-owned instance is destroyed.
PatternCatalog::~PatternCatalog() {
    HeapFree(GetProcessHeap(), 0, storage);
}

/// Returns the immutable pattern catalog, loading it once on first use.
std::span<const LifePattern> PatternCatalog::All() {
    static const PatternCatalog catalog;
    return catalog.entries;
}

/// Returns the one-based pattern selection, or zero for an empty or unknown identifier.
unsigned PatternCatalog::Find(std::wstring_view id) {
    if (id.empty()) {
        return 0;
    }
    const std::span<const LifePattern> patterns = All();
    for (std::size_t index = 0; index < patterns.size(); ++index) {
        if (patterns[index].id == id) {
            return static_cast<unsigned>(index + 1);
        }
    }
    return 0;
}
