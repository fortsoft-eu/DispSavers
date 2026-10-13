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
 * Last modified for version 1.1.0.0
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

/// Per-mesh visual scales equalizing mean orthographic silhouette area to the sphere at 100% size.
inline constexpr std::array<float, SOLID_COUNT> SOLID_RENDER_SCALES{
    0.57888103f,
    0.77227838f,
    0.68469384f,
    0.79414770f,
    0.82630377f,
    0.78683555f,
    0.69792441f,
    0.68387901f,
    1.07741895f,
    0.95861393f,
    0.85426179f,
    0.77259426f,
    0.89491880f,
    0.92154034f,
    0.65319726f,
    0.65622499f,
    0.63279801f,
    0.78739616f,
    0.80000000f,
    0.92376043f,
    0.96793868f,
    0.82105281f,
    0.84386026f,
    0.84972406f,
    1.01923304f,
    0.82440829f,
    0.79058790f,
    0.79406667f,
    0.91914916f,
    1.01771738f
};

/// Rotation-independent mesh bounds after applying SOLID_RENDER_SCALES. The small clearance prevents clipping
/// without causing premature rebounds.
inline constexpr std::array<float, SOLID_COUNT> COLLISION_RADII{
    1.01665980f,
    1.26943259f,
    1.19907008f,
    1.39075115f,
    1.44706447f,
    1.12714192f,
    0.99977672f,
    0.97965668f,
    1.09762055f,
    1.21624142f,
    1.25469700f,
    1.10674128f,
    1.28197118f,
    1.32010654f,
    0.93570508f,
    0.94004230f,
    0.94919701f,
    1.24507017f,
    0.81500000f,
    1.04962279f,
    1.11191956f,
    0.83644755f,
    0.85968264f,
    1.12057360f,
    1.19122861f,
    0.96352718f,
    1.02677603f,
    1.16628542f,
    1.02829812f,
    1.04092848f
};
