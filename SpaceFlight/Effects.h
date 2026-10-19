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
    InfiniteSurface,
    MorphingSurface,
    Count
};

inline constexpr std::size_t EFFECT_COUNT = static_cast<std::size_t>(EffectKind::Count);
inline constexpr std::uint32_t ALL_EFFECT_MASK = (1U << EFFECT_COUNT) - 1U;

/// Original wire-grid segment counts for the two surface flights.
inline constexpr std::array<unsigned, EFFECT_COUNT> SEGMENT_COUNTS{ 15664, 25312 };

/// Filled-grid dimensions for the two surface flights.
struct SurfaceMesh {
    unsigned columns;
    unsigned rows;
    unsigned patches;
};
inline constexpr std::array<SurfaceMesh, EFFECT_COUNT> SURFACE_MESHES{
    SurfaceMesh{ 176, 176, 1 },
    SurfaceMesh{ 224, 224, 1 }
};
