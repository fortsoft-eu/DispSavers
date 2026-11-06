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

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "Simulation.h"
#include "PatternCatalog.h"
#include <windows.h>
#include <bcrypt.h>
#include <algorithm>
#include <limits>
#include <random>
#include <span>
#include <stdexcept>

#pragma comment(lib, "bcrypt.lib")

constexpr unsigned PATTERN_TILE_SIZE = 44;
constexpr unsigned PATTERN_SPACING = 12;
constexpr unsigned MIXED_PATTERN_MAXIMUM_SIZE = 32;

/// Decodes a rotated RLE pattern at signed coordinates, clipping cells outside the board.
static void PlacePattern(Simulation& simulation, const LifePattern& pattern, std::int64_t left, std::int64_t top,
        unsigned turns) {
    unsigned x = 0;
    unsigned y = 0;
    unsigned count = 0;
    for (const char token : pattern.rle) {
        if (token >= '0' && token <= '9') {
            count = count * 10 + static_cast<unsigned>(token - '0');
            continue;
        }
        if (token == '!') {
            return;
        }
        if (token != 'b' && token != 'o' && token != '$') {
            continue;
        }
        const unsigned amount = count == 0 ? 1 : count;
        count = 0;
        if (token == '$') {
            y += amount;
            x = 0;
            continue;
        }
        if (token == 'o') {
            for (unsigned index = 0; index < amount; ++index) {
                const unsigned sourceX = x + index;
                unsigned placedX = sourceX;
                unsigned placedY = y;
                if (turns == 1) {
                    placedX = pattern.height - y - 1;
                    placedY = sourceX;
                } else if (turns == 2) {
                    placedX = pattern.width - sourceX - 1;
                    placedY = pattern.height - y - 1;
                } else if (turns == 3) {
                    placedX = y;
                    placedY = pattern.width - sourceX - 1;
                }
                const std::int64_t targetX = left + placedX;
                const std::int64_t targetY = top + placedY;
                if (targetX >= 0 && targetX < simulation.Width() && targetY >= 0 && targetY < simulation.Height()) {
                    simulation.SetCell(static_cast<unsigned>(targetX), static_cast<unsigned>(targetY), true);
                }
            }
        }
        x += amount;
    }
}

/// Initializes an empty CPU board with zero generation and population counters.
Simulation::Simulation() = default;

/// Allocates cleared current and next boards and resets generation and population counters.
void Simulation::Resize(unsigned requestedWidth, unsigned requestedHeight) {
    if (requestedWidth == 0 || requestedHeight == 0) {
        requestedWidth = 0;
        requestedHeight = 0;
    }
    if (requestedHeight != 0 && requestedWidth > cells.max_size() / requestedHeight) {
        throw std::length_error("Game of Life grid is too large");
    }
    const std::size_t size = static_cast<std::size_t>(requestedWidth) * requestedHeight;
    std::vector<std::uint8_t> resized(size);
    std::vector<std::uint8_t> resizedNext(size);
    cells.swap(resized);
    next.swap(resizedNext);
    width = requestedWidth;
    height = requestedHeight;
    generation = 0;
    aliveCount = 0;
}

/// Seeds the board at the requested density using the system random generator.
void Simulation::Randomize(unsigned densityPercent) {
    densityPercent = std::min(densityPercent, 100U);
    generation = 0;
    aliveCount = 0;
    if (densityPercent == 0 || densityPercent == 100) {
        const std::uint8_t value = densityPercent == 100 ? 1 : 0;
        std::fill(cells.begin(), cells.end(), value);
        aliveCount = value != 0 ? cells.size() : 0;
        return;
    }
    std::vector<std::uint32_t> random(4096);
    constexpr std::uint64_t range = std::uint64_t{ std::numeric_limits<std::uint32_t>::max() } + 1;
    const std::uint64_t threshold = range * densityPercent / 100;
    for (std::size_t offset = 0; offset < cells.size();) {
        const std::size_t count = std::min(random.size(), cells.size() - offset);
        const NTSTATUS status = BCryptGenRandom(nullptr, reinterpret_cast<PUCHAR>(random.data()),
            static_cast<ULONG>(count * sizeof(random[0])), BCRYPT_USE_SYSTEM_PREFERRED_RNG);
        if (!BCRYPT_SUCCESS(status)) {
            throw std::runtime_error("Cannot initialize Game of Life from the system random generator");
        }
        for (std::size_t index = 0; index < count; ++index) {
            const bool alive = random[index] < threshold;
            cells[offset + index] = static_cast<std::uint8_t>(alive);
            aliveCount += static_cast<std::size_t>(alive);
        }
        offset += count;
    }
}

/// Seeds a named pattern or a spaced mixture, repeating only patterns marked repeatable.
bool Simulation::SeedPatterns(unsigned selection) {
    const std::span<const LifePattern> patterns = PatternCatalog::All();
    if (cells.empty() || selection > patterns.size()) {
        return false;
    }
    if (selection != 0) {
        const LifePattern& pattern = patterns[selection - 1];
        unsigned columns = 1;
        unsigned rows = 1;
        if (pattern.repeatable && pattern.width <= width && pattern.height <= height) {
            columns = std::max(1U,
                static_cast<unsigned>(width / (std::uint64_t{ pattern.width } + PATTERN_SPACING)));
            rows = std::max(1U,
                static_cast<unsigned>(height / (std::uint64_t{ pattern.height } + PATTERN_SPACING)));
        }
        Clear();
        for (unsigned row = 0; row < rows; ++row) {
            const unsigned top = static_cast<unsigned>(std::uint64_t{ row } * height / rows);
            const unsigned bottom = static_cast<unsigned>(std::uint64_t{ row + 1 } * height / rows);
            for (unsigned column = 0; column < columns; ++column) {
                const unsigned left = static_cast<unsigned>(std::uint64_t{ column } * width / columns);
                const unsigned right = static_cast<unsigned>(std::uint64_t{ column + 1 } * width / columns);
                const std::int64_t patternLeft = left + (std::int64_t{ right - left } - pattern.width) / 2;
                const std::int64_t patternTop = top + (std::int64_t{ bottom - top } - pattern.height) / 2;
                PlacePattern(*this, pattern, patternLeft, patternTop, 0);
            }
        }
        return true;
    }
    std::vector<const LifePattern*> suitable;
    for (const LifePattern& pattern : patterns) {
        const bool fits = pattern.width <= width && pattern.height <= height
            || pattern.height <= width && pattern.width <= height;
        if (pattern.repeatable && pattern.width <= MIXED_PATTERN_MAXIMUM_SIZE
                && pattern.height <= MIXED_PATTERN_MAXIMUM_SIZE && fits) {
            suitable.push_back(&pattern);
        }
    }
    if (suitable.empty()) {
        return false;
    }
    std::uint32_t seed = 0;
    const NTSTATUS status = BCryptGenRandom(nullptr, reinterpret_cast<PUCHAR>(&seed), sizeof(seed),
        BCRYPT_USE_SYSTEM_PREFERRED_RNG);
    if (!BCRYPT_SUCCESS(status)) {
        throw std::runtime_error("Cannot initialize Game of Life patterns from the system random generator");
    }
    std::mt19937 random(seed);
    std::size_t firstPattern = random() % suitable.size();
    const unsigned columns = std::max(1U, width / PATTERN_TILE_SIZE);
    const unsigned rows = std::max(1U, height / PATTERN_TILE_SIZE);
    Clear();
    for (unsigned row = 0; row < rows; ++row) {
        const unsigned top = static_cast<unsigned>(std::uint64_t{ row } * height / rows);
        const unsigned bottom = static_cast<unsigned>(std::uint64_t{ row + 1 } * height / rows);
        const unsigned availableHeight = bottom - top - (rows > 1 ? PATTERN_SPACING : 0);
        for (unsigned column = 0; column < columns; ++column) {
            const unsigned left = static_cast<unsigned>(std::uint64_t{ column } * width / columns);
            const unsigned right = static_cast<unsigned>(std::uint64_t{ column + 1 } * width / columns);
            const unsigned availableWidth = right - left - (columns > 1 ? PATTERN_SPACING : 0);
            for (std::size_t attempt = 0; attempt < suitable.size(); ++attempt) {
                const LifePattern& pattern = *suitable[(firstPattern + attempt) % suitable.size()];
                unsigned turns = random() & 3U;
                unsigned patternWidth = turns % 2 != 0 ? pattern.height : pattern.width;
                unsigned patternHeight = turns % 2 != 0 ? pattern.width : pattern.height;
                if (patternWidth > availableWidth || patternHeight > availableHeight) {
                    std::swap(patternWidth, patternHeight);
                    turns = (turns + 1) % 4;
                }
                if (patternWidth <= availableWidth && patternHeight <= availableHeight) {
                    PlacePattern(*this, pattern, left + (right - left - patternWidth) / 2,
                        top + (bottom - top - patternHeight) / 2, turns);
                    break;
                }
            }
            firstPattern = (firstPattern + 1) % suitable.size();
        }
    }
    return true;
}

/// Clears every cell and resets generation and population counters.
void Simulation::Clear() {
    std::fill(cells.begin(), cells.end(), std::uint8_t{ 0 });
    generation = 0;
    aliveCount = 0;
}

/// Applies Conway rules to one generation with wrapped horizontal and vertical neighbors.
void Simulation::Step() {
    if (cells.empty()) {
        return;
    }
    std::size_t living = 0;
    for (unsigned y = 0; y < height; ++y) {
        const std::size_t row = static_cast<std::size_t>(y) * width;
        const std::size_t upper = static_cast<std::size_t>(y == 0 ? height - 1 : y - 1) * width;
        const std::size_t lower = static_cast<std::size_t>(y + 1 == height ? 0 : y + 1) * width;
        for (unsigned x = 0; x < width; ++x) {
            const unsigned left = x == 0 ? width - 1 : x - 1;
            const unsigned right = x + 1 == width ? 0 : x + 1;
            const unsigned neighbors = static_cast<unsigned>(cells[upper + left]) + cells[upper + x]
                + cells[upper + right] + cells[row + left] + cells[row + right] + cells[lower + left]
                + cells[lower + x] + cells[lower + right];
            const bool alive = neighbors == 3 || cells[row + x] != 0 && neighbors == 2;
            next[row + x] = static_cast<std::uint8_t>(alive);
            living += static_cast<std::size_t>(alive);
        }
    }
    cells.swap(next);
    aliveCount = living;
    ++generation;
}

/// Changes an in-bounds cell and updates the population count only when its state changes.
void Simulation::SetCell(unsigned x, unsigned y, bool alive) {
    if (x >= width || y >= height) {
        return;
    }
    const std::size_t index = static_cast<std::size_t>(y) * width + x;
    const std::uint8_t value = alive ? 1 : 0;
    if (cells[index] != value) {
        cells[index] = value;
        aliveCount = alive ? aliveCount + 1 : aliveCount - 1;
    }
}

/// Returns the state of an in-bounds cell, treating out-of-bounds coordinates as dead.
bool Simulation::Cell(unsigned x, unsigned y) const {
    return x < width && y < height && cells[static_cast<std::size_t>(y) * width + x] != 0;
}

/// Returns the board width in cells.
unsigned Simulation::Width() const {
    return width;
}

/// Returns the board height in cells.
unsigned Simulation::Height() const {
    return height;
}

/// Returns the number of CPU generations since the board was last seeded or cleared.
std::uint64_t Simulation::Generation() const {
    return generation;
}

/// Returns the current number of live CPU cells.
std::size_t Simulation::AliveCount() const {
    return aliveCount;
}

/// Returns the row-major cell buffer without copying it.
const std::vector<std::uint8_t>& Simulation::Cells() const {
    return cells;
}
