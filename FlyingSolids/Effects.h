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
 * Last modified for version 1.0.0.0
 */

#pragma once

#include <array>
#include <cstdint>

/// Closed solid meshes available to the simulation and renderer.
enum class SolidKind : std::uint32_t {
    Cube,
    Pyramid,
    PyramidalFrustum,
    ObliquePyramidalCut,
    PerpendicularPyramidalCut,
    TriangularPrism,
    PentagonalPrism,
    HexagonalPrism,
    Octahedron,
    PentagonalBipyramid,
    Cone,
    ConicalFrustum,
    ObliqueConicalCut,
    PerpendicularConicalCut,
    Cylinder,
    HollowCylinder,
    RoundedHollowCylinder,
    Paraboloid,
    Sphere,
    Hemisphere,
    SphericalCap,
    SphereWithoutOneCap,
    SphereWithoutCaps,
    Ellipsoid,
    ProlateEllipsoid,
    OblateEllipsoid,
    Egg,
    Capsule,
    Spheroplatelet,
    Torus,
    Count
};

/// Object-count limits
inline constexpr std::size_t SOLID_COUNT = static_cast<std::size_t>(SolidKind::Count);
inline constexpr std::size_t MAX_COPIES_PER_SOLID = 10;
inline constexpr std::size_t MAX_SOLID_INSTANCES = SOLID_COUNT * MAX_COPIES_PER_SOLID;

/// Bit mask enabling every available solid.
inline constexpr std::uint32_t ALL_SOLID_MASK = (1U << SOLID_COUNT) - 1U;

/// Per-mesh visual scale factors applied by the renderer.
inline constexpr std::array<float, SOLID_COUNT> SOLID_RENDER_SCALES{
    0.64f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    0.80f,
    1.14f
};

/// Rotation-independent mesh bounds after applying SOLID_RENDER_SCALES.
/// The small clearance prevents clipping without causing premature rebounds.
inline constexpr std::array<float, SOLID_COUNT> COLLISION_RADII{
    1.124f,
    1.315f,
    1.401f,
    1.401f,
    1.401f,
    1.146f,
    1.146f,
    1.146f,
    0.815f,
    1.015f,
    1.175f,
    1.146f,
    1.146f,
    1.146f,
    1.146f,
    1.146f,
    1.200f,
    1.265f,
    0.815f,
    0.909f,
    0.919f,
    0.815f,
    0.815f,
    1.055f,
    0.935f,
    0.935f,
    1.039f,
    1.175f,
    0.855f,
    1.166f
};
