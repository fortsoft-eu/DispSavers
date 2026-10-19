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

#include <array>
#include <cstdint>

/// The two original FSSaver flight effects in display order.
enum class EffectKind : std::uint32_t {
    Corridor,
    Funnel,
    Count
};

inline constexpr std::size_t EFFECT_COUNT = static_cast<std::size_t>(EffectKind::Count);
inline constexpr std::uint32_t ALL_EFFECT_MASK = (1U << EFFECT_COUNT) - 1U;

/// Extended wire-grid segment counts retain the original interior sampling density.
inline constexpr unsigned FLIGHT_WIRE_ROWS = 116;
inline constexpr std::array<unsigned, EFFECT_COUNT> SEGMENT_COUNTS{
    4 * (25 * FLIGHT_WIRE_ROWS + 24 * (FLIGHT_WIRE_ROWS + 1)),
    40 * (2 * FLIGHT_WIRE_ROWS + 1)
};

/// Filled-grid dimensions; each wall is a separate patch.
struct SurfaceMesh {
    unsigned columns;
    unsigned rows;
    unsigned patches;
};
inline constexpr std::array<SurfaceMesh, EFFECT_COUNT> SURFACE_MESHES{
    SurfaceMesh{ 96, 232, 4 },
    SurfaceMesh{ 192, 232, 1 }
};
