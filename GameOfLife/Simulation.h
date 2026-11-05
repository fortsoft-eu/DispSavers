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

#include <cstddef>
#include <cstdint>
#include <vector>

/// CPU board used for scene seeding and wrapped Conway generation updates.
class Simulation final {

private:
    unsigned width = 0;
    unsigned height = 0;
    std::uint64_t generation = 0;
    std::size_t aliveCount = 0;
    std::vector<std::uint8_t> cells;
    std::vector<std::uint8_t> next;

public:
    /// Initializes an empty CPU board with zero generation and population counters.
    Simulation();

    /// Allocates cleared current and next boards and resets generation and population counters.
    void Resize(unsigned width, unsigned height);

    /// Seeds the board at the requested density using the system random generator.
    void Randomize(unsigned densityPercent = 25);

    /// Seeds a named pattern or a spaced mixture, repeating only patterns marked repeatable.
    bool SeedPatterns(unsigned selection = 0);

    /// Clears every cell and resets generation and population counters.
    void Clear();

    /// Applies Conway rules to one generation with wrapped horizontal and vertical neighbors.
    void Step();

    /// Changes an in-bounds cell and updates the population count only when its state changes.
    void SetCell(unsigned x, unsigned y, bool alive);

    /// Returns the state of an in-bounds cell, treating out-of-bounds coordinates as dead.
    bool Cell(unsigned x, unsigned y) const;

    /// Returns the board width in cells.
    unsigned Width() const;

    /// Returns the board height in cells.
    unsigned Height() const;

    /// Returns the number of CPU generations since the board was last seeded or cleared.
    std::uint64_t Generation() const;

    /// Returns the current number of live CPU cells.
    std::size_t AliveCount() const;

    /// Returns the row-major cell buffer without copying it.
    const std::vector<std::uint8_t>& Cells() const;
};
