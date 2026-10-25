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
 * Last modified for version 1.2.2.0
 */

#pragma once

#include <array>
#include <cstdint>

/// The flight effects in display order.
enum class EffectKind : std::uint32_t {
    InfiniteSurface,
    MorphingSurface,
    GravityWarpedSpaceFlight,
    Count
};

/// Plane, wave and funnel deformation modes shared by both surface animations.
enum class SurfaceShape : std::uint32_t {
    Plane,
    Waves,
    Funnel
};

inline constexpr std::size_t EFFECT_COUNT = static_cast<std::size_t>(EffectKind::Count);
inline constexpr std::uint32_t ALL_EFFECT_MASK = (1U << EFFECT_COUNT) - 1U;

/// Wire-grid dimensions and segment counts for the flight effects.
inline constexpr unsigned INFINITE_GRID_CELLS = 220;
inline constexpr std::array<unsigned, EFFECT_COUNT> SEGMENT_COUNTS{
    (INFINITE_GRID_CELLS + 1) * INFINITE_GRID_CELLS * 2,
    25312,
    16224
};

inline constexpr unsigned FUNNEL_CIRCLE_SEGMENTS = 128;
inline constexpr unsigned FUNNEL_CIRCLE_COUNT = 2;
inline constexpr std::array<unsigned, EFFECT_COUNT> FUNNEL_BODY_CIRCLE_COUNTS{ 4, 2, 0 };

/// Filled-grid dimensions for the two surface flights.
struct SurfaceMesh {
    unsigned columns;
    unsigned rows;
    unsigned patches;
};

inline constexpr std::array<SurfaceMesh, EFFECT_COUNT> SURFACE_MESHES{
    SurfaceMesh{ INFINITE_GRID_CELLS * 2, INFINITE_GRID_CELLS * 2, 1 },
    SurfaceMesh{ 224, 224, 1 },
    SurfaceMesh{ 0, 0, 0 }
};
