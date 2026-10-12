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

#include "Effects.h"
#include <vector>

/// Shared dimensions of the analytically rendered spherocylinder
inline constexpr float CAPSULE_RADIUS = .7f;
inline constexpr float CAPSULE_HALF_LENGTH = .75f;

/// Shared spherical-layer thickness and dimensions of the rounded circular spheroplatelet.
inline constexpr float SPHERICAL_LAYER_HALF_THICKNESS = .55f;
inline constexpr float SPHEROPLATELET_OUTER_RADIUS = 1.1f;
inline constexpr float SPHEROPLATELET_ROUNDING_RADIUS = .25f;
inline constexpr float SPHEROPLATELET_DISC_RADIUS = SPHEROPLATELET_OUTER_RADIUS - SPHEROPLATELET_ROUNDING_RADIUS;

/// Shared cylinder and half-torus dimensions of the rounded hollow cylinder.
inline constexpr float ROUNDED_HOLLOW_CYLINDER_OUTER_RADIUS = 1.0f;
inline constexpr float ROUNDED_HOLLOW_CYLINDER_INNER_RADIUS = .6f;
inline constexpr float ROUNDED_HOLLOW_CYLINDER_HALF_LENGTH = 1.0f;
inline constexpr float ROUNDED_HOLLOW_CYLINDER_TORUS_RADIUS =
    (ROUNDED_HOLLOW_CYLINDER_OUTER_RADIUS + ROUNDED_HOLLOW_CYLINDER_INNER_RADIUS) * .5f;
inline constexpr float ROUNDED_HOLLOW_CYLINDER_ROUNDING_RADIUS =
    (ROUNDED_HOLLOW_CYLINDER_OUTER_RADIUS - ROUNDED_HOLLOW_CYLINDER_INNER_RADIUS) * .5f;

/// Position and unit normal of one triangle-mesh vertex.
struct Vertex {
    float x;
    float y;
    float z;
    float nx;
    float ny;
    float nz;
};

/// Indexed triangle list stored in CPU memory before GPU upload.
struct MeshData {
    std::vector<Vertex> vertices;
    std::vector<unsigned> indices;
};

/// Builds a closed mesh, or conservative bounds when the requested solid is rendered analytically.
MeshData BuildSolidMesh(SolidKind kind);
