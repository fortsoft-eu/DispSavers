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

#define _USE_MATH_DEFINES
#include "MeshBuilder.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <initializer_list>

/// Lightweight vector used only while constructing CPU meshes.
struct V3 {
    float x;
    float y;
    float z;
};

/// Orders cut-plane points around a fixed center and tangent.
struct CutPointOrder {
    V3 center;
    V3 tangent;

    /// Compares the polar angles of two cut-plane points.
    bool operator()(V3 first, V3 second) const;
};

/// Circumferential subdivision of round meshes
constexpr unsigned ROUND_SIDES = 120;

/// Vector arithmetic and vertex conversion

/// Adds two mesh-construction vectors component by component.
static V3 operator+(V3 a, V3 b) {
    return V3{ a.x + b.x, a.y + b.y, a.z + b.z };
}

/// Subtracts two mesh-construction vectors component by component.
static V3 operator-(V3 a, V3 b) {
    return V3{ a.x - b.x, a.y - b.y, a.z - b.z };
}

/// Multiplies every vector component by a scalar.
static V3 operator*(V3 a, float s) {
    return V3{ a.x * s, a.y * s, a.z * s };
}

/// Returns the scalar product of two vectors.
static float Dot(V3 a, V3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

/// Returns the right-handed vector product of two vectors.
static V3 Cross(V3 a, V3 b) {
    return V3{ a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x };
}

/// Compares cut-plane points by their polar angles around the stored center.
bool CutPointOrder::operator()(V3 first, V3 second) const {
    const V3 firstOffset = first - center;
    const V3 secondOffset = second - center;
    return std::atan2(Dot(firstOffset, tangent), firstOffset.y) < std::atan2(Dot(secondOffset, tangent), secondOffset.y);
}

/// Normalizes a vector using a positive length bound to avoid division by zero.
static V3 Normalized(V3 value) {
    const float length = std::sqrt(std::max(1.0e-20f, Dot(value, value)));
    return value * (1.0f / length);
}

/// Packs a position and normal into one renderable mesh vertex.
static Vertex Make(V3 p, V3 n) {
    return Vertex{ p.x, p.y, p.z, n.x, n.y, n.z };
}

/// Appends a flat-shaded, counter-clockwise triangle.
static void Triangle(MeshData& mesh, V3 a, V3 b, V3 c) {
    const V3 n = Normalized(Cross(b - a, c - a));
    const unsigned base = static_cast<unsigned>(mesh.vertices.size());
    mesh.vertices.push_back(Make(a, n));
    mesh.vertices.push_back(Make(b, n));
    mesh.vertices.push_back(Make(c, n));
    const std::initializer_list<unsigned> indices{ base, base + 1, base + 2 };
    mesh.indices.insert(mesh.indices.end(), indices);
}

/// Appends a quadrilateral as two consistently wound triangles.
static void Quad(MeshData& mesh, V3 a, V3 b, V3 c, V3 d) {
    Triangle(mesh, a, b, c);
    Triangle(mesh, a, c, d);
}

/// Triangulates a planar convex polygon around its centroid.
static void PlanarFace(MeshData& mesh, const std::vector<V3>& points, V3 outward) {
    if (points.size() < 3) {
        return;
    }
    V3 center{};
    for (const V3& point : points) {
        center = center + point;
    }
    center = center * (1.0f / static_cast<float>(points.size()));
    for (std::size_t index = 0; index < points.size(); index++) {
        const V3 current = points[index];
        const V3 next = points[(index + 1) % points.size()];
        if (Dot(Cross(current - center, next - center), outward) >= 0.0f) {
            Triangle(mesh, center, current, next);
        } else {
            Triangle(mesh, center, next, current);
        }
    }
}

/// Adds a cut-plane intersection unless an equivalent point already exists.
static void AddUniquePoint(std::vector<V3>& points, V3 point) {
    for (const V3& existing : points) {
        const V3 difference = existing - point;
        if (Dot(difference, difference) < 1.0e-8f) {
            return;
        }
    }
    points.push_back(point);
}

/// Clips a polygon against a half-space and collects its new boundary points.
static std::vector<V3> ClipPolygonPlaneMax(const std::vector<V3>& polygon, V3 planeNormal, float maximumDistance,
        std::vector<V3>& intersections) {
    std::vector<V3> clipped;
    if (polygon.empty()) {
        return clipped;
    }
    V3 previous = polygon.back();
    float previousDistance = Dot(previous, planeNormal) - maximumDistance;
    bool previousInside = previousDistance <= 0.0f;
    for (const V3& current : polygon) {
        const float currentDistance = Dot(current, planeNormal) - maximumDistance;
        const bool currentInside = currentDistance <= 0.0f;
        if (previousInside != currentInside) {
            const float amount = previousDistance / (previousDistance - currentDistance);
            const V3 intersection = previous + (current - previous) * amount;
            clipped.push_back(intersection);
            AddUniquePoint(intersections, intersection);
        }
        if (currentInside) {
            clipped.push_back(current);
        }
        previous = current;
        previousDistance = currentDistance;
        previousInside = currentInside;
    }
    return clipped;
}

/// Builds an axis-aligned closed box between two Z planes.
static void Box(MeshData& mesh, float lower = -1, float upper = 1) {
    const V3 p000{ -1, -1, lower };
    const V3 p100{ 1, -1, lower };
    const V3 p110{ 1, 1, lower };
    const V3 p010{ -1, 1, lower };
    const V3 p001{ -1, -1, upper };
    const V3 p101{ 1, -1, upper };
    const V3 p111{ 1, 1, upper };
    const V3 p011{ -1, 1, upper };
    Quad(mesh, p000, p010, p110, p100);
    Quad(mesh, p001, p101, p111, p011);
    Quad(mesh, p000, p001, p011, p010);
    Quad(mesh, p100, p110, p111, p101);
    Quad(mesh, p010, p011, p111, p110);
    Quad(mesh, p000, p100, p101, p001);
}

/// Samples a parametric surface with analytically supplied normals.
template<typename... Parameters>
static void GridWithNormals(MeshData& mesh, unsigned columns, unsigned rows,
        V3(*samplePosition)(float, float, Parameters...),
        V3(*sampleNormal)(float, float, Parameters...),
        Parameters... parameters) {
    const unsigned stride = columns + 1;
    const unsigned base = static_cast<unsigned>(mesh.vertices.size());
    for (unsigned row = 0; row <= rows; row++) {
        for (unsigned column = 0; column <= columns; column++) {
            const float u = static_cast<float>(column) / columns;
            const float v = static_cast<float>(row) / rows;
            mesh.vertices.push_back(Make(samplePosition(u, v, parameters...),
                Normalized(sampleNormal(u, v, parameters...))));
        }
    }
    for (unsigned row = 0; row < rows; row++) {
        for (unsigned column = 0; column < columns; column++) {
            const unsigned a = base + row * stride + column;
            const unsigned b = a + 1;
            const unsigned c = a + stride + 1;
            const unsigned d = a + stride;
            const std::initializer_list<unsigned> indices{ a, b, c, a, c, d };
            mesh.indices.insert(mesh.indices.end(), indices);
        }
    }
}

/// Converts cylindrical coordinates around the Y axis to Cartesian coordinates.
static V3 Radial(float angle, float radius, float y) {
    return V3{ radius * std::cos(angle), y, radius * std::sin(angle) };
}

/// Builds a flat circular cap perpendicular to the Y axis.
static void DiscY(MeshData& mesh, unsigned sides, float radius, float y, bool top) {
    for (unsigned index = 0; index < sides; index++) {
        const float a0 = 2.0f * float(M_PI) * index / sides;
        const float a1 = 2.0f * float(M_PI) * (index + 1) / sides;
        const V3 p0 = Radial(a0, radius, y);
        const V3 p1 = Radial(a1, radius, y);
        const V3 center{ 0, y, 0 };
        if (top) {
            Triangle(mesh, center, p1, p0);
        } else {
            Triangle(mesh, center, p0, p1);
        }
    }
}

/// Closes an existing ring with a flat disc, reusing its exact boundary positions and tangent normals.
static void CloseDiscRing(MeshData& mesh, unsigned ringBase, unsigned sides, float y, bool top) {
    const V3 center{ 0, y, 0 };
    V3 normal{ 0, -1, 0 };
    if (top) {
        normal.y = 1;
    }
    const unsigned centerIndex = static_cast<unsigned>(mesh.vertices.size());
    mesh.vertices.push_back(Make(center, normal));
    for (unsigned index = 0; index < sides; index++) {
        unsigned first = ringBase + index;
        unsigned second = first + 1;
        if (top) {
            std::swap(first, second);
        }
        const std::initializer_list<unsigned> indices{ centerIndex, first, second };
        mesh.indices.insert(mesh.indices.end(), indices);
    }
}

/// Builds a flat annular cap perpendicular to the Y axis.
static void AnnulusY(MeshData& mesh, unsigned sides, float outer, float inner, float y, bool top) {
    for (unsigned index = 0; index < sides; index++) {
        const float a0 = 2.0f * float(M_PI) * index / sides;
        const float a1 = 2.0f * float(M_PI) * (index + 1) / sides;
        const V3 o0 = Radial(a0, outer, y), o1 = Radial(a1, outer, y);
        const V3 i0 = Radial(a0, inner, y), i1 = Radial(a1, inner, y);
        if (top) {
            Quad(mesh, i0, i1, o1, o0);
        } else {
            Quad(mesh, i0, o0, o1, i1);
        }
    }
}

/// Samples the analytic position and normal of a sphere, ellipsoid or ovoid.
static void RoundedGeometry(float u, float v, SolidKind kind, V3& position, V3& normal) {
    const float longitude = u * 2.0f * float(M_PI);
    const float latitude = v * float(M_PI);
    const float longitudeSine = std::sin(longitude);
    const float longitudeCosine = std::cos(longitude);
    float latitudeSine = std::sin(latitude);
    const float latitudeCosine = std::cos(latitude);
    if (v <= 0.0f || v >= 1.0f) {
        latitudeSine = 0.0f;
    }
    if (kind == SolidKind::Egg) {
        constexpr float width = 0.88f;
        constexpr float height = 1.28f;
        constexpr float taper = 0.20f;
        const float radius = width * latitudeSine * (1.0f - taper * latitudeCosine);
        position = V3{ radius * longitudeCosine, height * latitudeCosine, radius * longitudeSine };
        const float radiusDerivative = width * (latitudeCosine * (1.0f - taper * latitudeCosine)
            + taper * latitudeSine * latitudeSine);
        normal = V3{ height * latitudeSine * longitudeCosine, radiusDerivative, height * latitudeSine * longitudeSine };
    } else {
        const V3 unit{ latitudeSine * longitudeCosine, latitudeCosine, latitudeSine * longitudeSine };
        V3 axes{ 1.0f, 1.0f, 1.0f };
        if (kind == SolidKind::Ellipsoid) {
            axes = V3{ 0.90f, 1.30f, 0.65f };
        } else if (kind == SolidKind::ProlateEllipsoid) {
            axes = V3{ 0.62f, 1.15f, 0.62f };
        } else if (kind == SolidKind::OblateEllipsoid) {
            axes = V3{ 1.15f, 0.62f, 1.15f };
        }
        position = V3{ unit.x * axes.x, unit.y * axes.y, unit.z * axes.z };
        normal = V3{ unit.x / axes.x, unit.y / axes.y, unit.z / axes.z };
    }
}

/// Returns one sampled position on a sphere, ellipsoid or ovoid.
static V3 RoundedPosition(float u, float v, SolidKind kind) {
    V3 position{}, normal{};
    RoundedGeometry(u, v, kind, position, normal);
    return position;
}

/// Returns one sampled analytic normal on a sphere, ellipsoid or ovoid.
static V3 RoundedNormal(float u, float v, SolidKind kind) {
    V3 position{}, normal{};
    RoundedGeometry(u, v, kind, position, normal);
    return normal;
}

/// Builds sphere-derived objects using analytic ellipsoid or ovoid normals.
static void RoundedObject(MeshData& mesh, SolidKind kind) {
    constexpr unsigned columns = ROUND_SIDES;
    constexpr unsigned rows = 64;
    GridWithNormals(mesh, columns, rows, RoundedPosition, RoundedNormal, kind);
}

/// Builds a closed regular square pyramid with an exact planar apex.
static void ExactPyramid(MeshData& mesh) {
    const std::array<V3, 4> base{
        {
            V3{ -1, .8f, -1 },
            V3{ 1, .8f, -1 },
            V3{ 1, .8f, 1 },
            V3{ -1, .8f, 1 }
        }
    };
    const V3 tip{ 0, -1.35f, 0 };
    Quad(mesh, base[0], base[1], base[2], base[3]);
    for (unsigned index = 0; index < 4; index++) {
        Triangle(mesh, base[index], base[(index + 1) % 4], tip);
    }
}

/// Returns one position on the side of a right circular cone.
static V3 ConePosition(float u, float v) {
    return Radial(u * 2.0f * float(M_PI), 1.0f - v, .85f - 2.3f * v);
}

/// Returns the analytic side normal of a right circular cone.
static V3 ConeNormal(float u, float) {
    const float angle = u * 2.0f * float(M_PI);
    return V3{ std::cos(angle), -1.0f / 2.3f, std::sin(angle) };
}

/// Builds a closed right circular cone with analytic side normals.
static void ExactCone(MeshData& mesh) {
    GridWithNormals(mesh, ROUND_SIDES, 1, ConePosition, ConeNormal);
    DiscY(mesh, ROUND_SIDES, 1.0f, .85f, true);
}

/// Returns one position on a ring torus.
static V3 TorusPosition(float u, float v) {
    const float a = 2.0f * float(M_PI) * u;
    const float b = 2.0f * float(M_PI) * v;
    const float radius = .72f + .29f * std::cos(b);
    return V3{ radius * std::cos(a), radius * std::sin(a), .29f * std::sin(b) };
}

/// Returns the analytic normal of a ring torus.
static V3 TorusNormal(float u, float v) {
    const float a = 2.0f * float(M_PI) * u;
    const float b = 2.0f * float(M_PI) * v;
    return V3{ std::cos(b) * std::cos(a), std::cos(b) * std::sin(a), std::sin(b) };
}

/// Builds a smooth ring torus from its major and minor circles.
static void ExactTorus(MeshData& mesh) {
    GridWithNormals(mesh, ROUND_SIDES, 48, TorusPosition, TorusNormal);
}

/// Returns one position on a circular cylinder or frustum.
static V3 FrustumPosition(float u, float v, float topRadius) {
    return Radial(u * 2.0f * float(M_PI), 1.0f + (topRadius - 1.0f) * v, 2.0f * v - 1.0f);
}

/// Returns the analytic side normal of a circular cylinder or frustum.
static V3 FrustumNormal(float u, float, float topRadius) {
    const float angle = u * 2.0f * float(M_PI);
    return V3{ std::cos(angle), (1.0f - topRadius) * .5f, std::sin(angle) };
}

/// Builds a closed right circular cylinder or frustum.
static void ExactRoundFrustum(MeshData& mesh, float topRadius) {
    GridWithNormals(mesh, ROUND_SIDES, 1, FrustumPosition, FrustumNormal, topRadius);
    DiscY(mesh, ROUND_SIDES, 1.0f, -1.0f, false);
    DiscY(mesh, ROUND_SIDES, topRadius, 1.0f, true);
}

/// Returns one unit-radius corner of a regular polygon in the XZ plane.
static V3 PolygonCorner(unsigned sides, unsigned corner) {
    const float angle = 2.0f * float(M_PI) * (corner % sides) / sides;
    return V3{ std::cos(angle), 0, std::sin(angle) };
}

/// Builds a closed prism with a regular polygonal base.
static void ExactPrism(MeshData& mesh, unsigned sides) {
    for (unsigned index = 0; index < sides; index++) {
        const V3 a = PolygonCorner(sides, index);
        const V3 b = PolygonCorner(sides, index + 1);
        const V3 bottomA{ a.x, -1, a.z };
        const V3 topA{ a.x, 1, a.z };
        const V3 topB{ b.x, 1, b.z };
        const V3 bottomB{ b.x, -1, b.z };
        const V3 bottomCenter{ 0, -1, 0 };
        const V3 topCenter{ 0, 1, 0 };
        Quad(mesh, bottomA, topA, topB, bottomB);
        Triangle(mesh, bottomCenter, bottomB, bottomA);
        Triangle(mesh, topCenter, topA, topB);
    }
}

/// Builds a closed regular square-pyramidal frustum.
static void ExactSquareFrustum(MeshData& mesh) {
    const std::array<V3, 4> bottom{
        {
            V3{ -1, -1, -1 },
            V3{ 1, -1, -1 },
            V3{ 1, -1, 1 },
            V3{ -1, -1, 1 }
        }
    };
    const std::array<V3, 4> top{
        {
            V3{ -.48f, 1, -.48f },
            V3{ .48f, 1, -.48f },
            V3{ .48f, 1, .48f },
            V3{ -.48f, 1, .48f }
        }
    };
    Quad(mesh, bottom[0], bottom[3], bottom[2], bottom[1]);
    Quad(mesh, top[0], top[1], top[2], top[3]);
    for (unsigned index = 0; index < 4; index++) {
        Quad(mesh, bottom[index], top[index], top[(index + 1) % 4], bottom[(index + 1) % 4]);
    }
}

/// Shared geometry of oblique cone and pyramid cuts
constexpr float OBLIQUE_CUT_HEIGHT = .25f;
constexpr float OBLIQUE_CUT_TILT = .50f;

/// Builds a cone truncated by an oblique plane oriented to the base diagonal.
static void ExactObliquelyCutCone(MeshData& mesh) {
    constexpr unsigned sides = ROUND_SIDES;
    constexpr float baseY = -1.0f;
    constexpr float apexY = 1.30f;
    constexpr float height = apexY - baseY;
    constexpr float cutHeight = OBLIQUE_CUT_HEIGHT;
    constexpr float tilt = OBLIQUE_CUT_TILT;
    constexpr float diagonal = .7071067811865475244f;
    const unsigned first = static_cast<unsigned>(mesh.vertices.size());
    std::vector<V3> top;
    top.reserve(sides);
    for (unsigned index = 0; index <= sides; index++) {
        const float angle = 2.0f * float(M_PI) * index / sides;
        const float cosine = std::cos(angle);
        const float sine = std::sin(angle);
        const float diagonalDirection = diagonal * (cosine + sine);
        const float topRadius = (apexY - cutHeight) / (height + tilt * diagonalDirection);
        const V3 bottom{ cosine, baseY, sine };
        const V3 upper{ topRadius * cosine, apexY - height * topRadius, topRadius * sine };
        const V3 sideNormal{ cosine, 1.0f / height, sine };
        const V3 normal = Normalized(sideNormal);
        mesh.vertices.push_back(Make(bottom, normal));
        mesh.vertices.push_back(Make(upper, normal));
        if (index < sides) {
            top.push_back(upper);
        }
    }
    for (unsigned index = 0; index < sides; index++) {
        const unsigned bottom = first + 2 * index;
        const std::initializer_list<unsigned> indices{ bottom, bottom + 2, bottom + 3, bottom, bottom + 3, bottom + 1 };
        mesh.indices.insert(mesh.indices.end(), indices);
    }
    DiscY(mesh, sides, 1.0f, baseY, false);
    const V3 cutNormal{ -tilt * diagonal, 1.0f, -tilt * diagonal };
    PlanarFace(mesh, top, cutNormal);
}

/// Builds a square pyramid truncated by the same oblique plane as the cone.
static void ExactObliquelyCutSquarePyramid(MeshData& mesh) {
    constexpr float baseY = -1.0f;
    constexpr float apexY = 1.30f;
    constexpr float height = apexY - baseY;
    constexpr float cutHeight = OBLIQUE_CUT_HEIGHT;
    constexpr float tilt = OBLIQUE_CUT_TILT;
    constexpr float diagonal = .7071067811865475244f;
    const std::array<V3, 4> bottom{
        {
            V3{ -1, baseY, -1 },
            V3{ 1, baseY, -1 },
            V3{ 1, baseY, 1 },
            V3{ -1, baseY, 1 }
        }
    };
    const V3 apex{ 0, apexY, 0 };
    std::array<V3, 4> top{};
    for (unsigned index = 0; index < top.size(); index++) {
        const float diagonalPosition = diagonal * (bottom[index].x + bottom[index].z);
        const float amount = (cutHeight - baseY + tilt * diagonalPosition) / (height + tilt * diagonalPosition);
        top[index] = bottom[index] + (apex - bottom[index]) * amount;
    }
    Quad(mesh, bottom[0], bottom[3], bottom[2], bottom[1]);
    for (unsigned index = 0; index < bottom.size(); index++) {
        const unsigned next = (index + 1) % static_cast<unsigned>(bottom.size());
        Quad(mesh, bottom[index], top[index], top[next], bottom[next]);
    }
    const std::vector<V3> topPoints(top.begin(), top.end());
    const V3 cutNormal{ -tilt * diagonal, 1.0f, -tilt * diagonal };
    PlanarFace(mesh, topPoints, cutNormal);
}

/// Returns an analytic side normal for a cone of the supplied height.
static V3 CutConeNormal(float angle, float height) {
    return V3{ std::cos(angle), 1.0f / height, std::sin(angle) };
}

/// Samples the intact tip above the vertical cone cut.
static V3 CutConeTipPosition(float u, float v, float cutX, float apexY, float height) {
    const float angle = 2.0f * float(M_PI) * u;
    const float radius = cutX * v;
    return Radial(angle, radius, apexY - height * radius);
}

/// Returns the side normal at the intact cone tip.
static V3 CutConeTipNormal(float u, float, float, float, float height) {
    return CutConeNormal(2.0f * float(M_PI) * u, height);
}

/// Samples the remaining side of a vertically cut cone.
static V3 CutConeSidePosition(float u, float v, float cutX, float apexY, float height, float angleOffset) {
    const float radius = cutX + (1.0f - cutX) * v;
    const float firstAngle = std::acos(cutX / radius);
    const float angle = angleOffset + firstAngle + (2.0f * float(M_PI) - 2.0f * firstAngle) * u;
    return Radial(angle, radius, apexY - height * radius);
}

/// Returns the side normal of a vertically cut cone.
static V3 CutConeSideNormal(float u, float v, float cutX, float, float height, float angleOffset) {
    const float radius = cutX + (1.0f - cutX) * v;
    const float firstAngle = std::acos(cutX / radius);
    return CutConeNormal(angleOffset + firstAngle + (2.0f * float(M_PI) - 2.0f * firstAngle) * u, height);
}

/// Builds a cone cut by a vertical plane rotated 45 degrees to the base axes.
static void ExactPerpendicularlyCutCone(MeshData& mesh) {
    constexpr unsigned sides = ROUND_SIDES;
    constexpr unsigned rows = 32;
    constexpr float cutX = .32f;
    constexpr float baseY = -1.0f;
    constexpr float apexY = 1.30f;
    constexpr float height = apexY - baseY;
    constexpr float diagonal = .7071067811865475244f;
    constexpr float angleOffset = float(M_PI) * .25f;
    GridWithNormals(mesh, sides, 16, CutConeTipPosition, CutConeTipNormal, cutX, apexY, height);
    GridWithNormals(mesh, sides, rows, CutConeSidePosition, CutConeSideNormal, cutX, apexY, height, angleOffset);
    std::vector<V3> base;
    base.reserve(sides + 1);
    const float baseAngle = std::acos(cutX);
    for (unsigned index = 0; index <= sides; index++) {
        const float angle = angleOffset + baseAngle + (2.0f * float(M_PI) - 2.0f * baseAngle) * index / sides;
        base.push_back(Radial(angle, 1.0f, baseY));
    }
    const V3 baseNormal{ 0.0f, -1.0f, 0.0f };
    PlanarFace(mesh, base, baseNormal);
    std::vector<V3> cut;
    cut.reserve(2 * rows + 1);
    const V3 cutNormal{ diagonal, 0.0f, diagonal };
    const V3 cutTangent{ -diagonal, 0.0f, diagonal };
    for (unsigned index = 0; index <= rows; index++) {
        const float radius = 1.0f - (1.0f - cutX) * index / rows;
        const float tangentDistance = -std::sqrt(std::max(0.0f, radius * radius - cutX * cutX));
        const V3 verticalOffset{ 0.0f, apexY - height * radius, 0.0f };
        cut.push_back(cutNormal * cutX + cutTangent * tangentDistance + verticalOffset);
    }
    for (unsigned index = 1; index <= rows; index++) {
        const float radius = cutX + (1.0f - cutX) * index / rows;
        const float tangentDistance = std::sqrt(std::max(0.0f, radius * radius - cutX * cutX));
        const V3 verticalOffset{ 0.0f, apexY - height * radius, 0.0f };
        cut.push_back(cutNormal * cutX + cutTangent * tangentDistance + verticalOffset);
    }
    PlanarFace(mesh, cut, cutNormal);
}

/// Builds a square pyramid cut by a vertical plane rotated 45 degrees to its edges.
static void ExactPerpendicularlyCutSquarePyramid(MeshData& mesh) {
    constexpr float cutX = .32f;
    constexpr float diagonal = .7071067811865475244f;
    constexpr V3 cutNormal{ diagonal, 0.0f, diagonal };
    constexpr V3 cutTangent{ -diagonal, 0.0f, diagonal };
    const std::array<V3, 4> bottom{
        {
            V3{ -1, -1, -1 },
            V3{ 1, -1, -1 },
            V3{ 1, -1, 1 },
            V3{ -1, -1, 1 }
        }
    };
    const V3 apex{ 0, 1.30f, 0 };
    const std::array<std::vector<V3>, 5> faces{
        {
            std::vector<V3>{ bottom[0], bottom[3], bottom[2], bottom[1] },
            std::vector<V3>{ bottom[0], apex, bottom[1] },
            std::vector<V3>{ bottom[1], apex, bottom[2] },
            std::vector<V3>{ bottom[2], apex, bottom[3] },
            std::vector<V3>{ bottom[3], apex, bottom[0] }
        }
    };
    std::vector<V3> intersections;
    for (const std::vector<V3>& face : faces) {
        const V3 outward = Cross(face[1] - face[0], face[2] - face[0]);
        const std::vector<V3> clipped = ClipPolygonPlaneMax(face, cutNormal, cutX, intersections);
        PlanarFace(mesh, clipped, outward);
    }
    V3 center{};
    for (const V3& point : intersections) {
        center = center + point;
    }
    if (!intersections.empty()) {
        center = center * (1.0f / static_cast<float>(intersections.size()));
    }
    const CutPointOrder pointOrder{ center, cutTangent };
    std::sort(intersections.begin(), intersections.end(), pointOrder);
    PlanarFace(mesh, intersections, cutNormal);
}

/// Builds two regular pyramids joined along their common polygonal base.
static void ExactBipyramid(MeshData& mesh, unsigned sides, float height = 1.25f) {
    for (unsigned index = 0; index < sides; index++) {
        const V3 a = PolygonCorner(sides, index);
        const V3 b = PolygonCorner(sides, index + 1);
        const V3 top{ 0, height, 0 };
        const V3 bottom{ 0, -height, 0 };
        Triangle(mesh, a, b, top);
        Triangle(mesh, b, a, bottom);
    }
}

/// Returns the analytic normal of a hemisphere or spherical segment.
static V3 HemisphereNormal(float u, float v, float, float, float maximumLatitude) {
    const float angle = u * 2.0f * float(M_PI);
    const float latitude = v * maximumLatitude;
    return V3{
        std::cos(angle) * std::sin(latitude),
        std::cos(latitude),
        std::sin(angle) * std::sin(latitude)
    };
}

/// Returns one position on a hemisphere or spherical segment.
static V3 HemispherePosition(float u, float v, float radius, float centerY, float maximumLatitude) {
    const V3 normal = HemisphereNormal(u, v, radius, centerY, maximumLatitude);
    const V3 center{ 0, centerY, 0 };
    return normal * radius + center;
}

/// Builds a closed hemisphere or shallow spherical segment.
static void ExactHemisphereOrCap(MeshData& mesh, bool cap) {
    const float radius = cap ? 1.2f : 1.0f;
    const float cut = cap ? .45f : 0.0f;
    const float centerY = -radius * (1.0f + cut) * .5f;
    const float maximumLatitude = std::acos(cut);
    GridWithNormals(mesh, ROUND_SIDES, 32, HemispherePosition, HemisphereNormal, radius, centerY, maximumLatitude);
    DiscY(mesh, ROUND_SIDES, radius * std::sqrt(1.0f - cut * cut), radius * cut + centerY, false);
}

/// Returns a unit-sphere position and normal within a bounded latitude interval.
static V3 SphereBand(float u, float v, float firstLatitude, float latitudeRange) {
    const float longitude = u * 2.0f * float(M_PI);
    const float latitude = firstLatitude + latitudeRange * v;
    return V3{ std::cos(longitude) * std::sin(latitude), std::cos(latitude), std::sin(longitude) * std::sin(latitude) };
}

/// Builds a sphere with both poles removed and both openings closed by planes.
static void ExactSphereWithoutCaps(MeshData& mesh) {
    constexpr float cut = SPHERICAL_LAYER_HALF_THICKNESS;
    const float firstLatitude = std::acos(cut);
    const float latitudeRange = float(M_PI) - 2.0f * firstLatitude;
    GridWithNormals(mesh, ROUND_SIDES, 48, SphereBand, SphereBand, firstLatitude, latitudeRange);
    constexpr float discRadius = .83516465f;
    DiscY(mesh, ROUND_SIDES, discRadius, cut, true);
    DiscY(mesh, ROUND_SIDES, discRadius, -cut, false);
}

/// Builds a sphere with one pole removed and the opening closed by a plane.
static void ExactSphereWithoutOneCap(MeshData& mesh) {
    constexpr float cut = .55f;
    const float firstLatitude = std::acos(cut);
    const float latitudeRange = float(M_PI) - firstLatitude;
    GridWithNormals(mesh, ROUND_SIDES, 64, SphereBand, SphereBand, firstLatitude, latitudeRange);
    DiscY(mesh, ROUND_SIDES, .83516465f, cut, true);
}

/// Samples a paraboloid of revolution uniformly in radius to retain its smooth vertex curvature.
static V3 ParaboloidPosition(float u, float v) {
    const float angle = u * 2.0f * float(M_PI);
    const float radius = v;
    return Radial(angle, radius, -1.2f + 2.2f * radius * radius);
}

/// Returns the analytic normal of a paraboloid of revolution.
static V3 ParaboloidNormal(float u, float v) {
    const float angle = u * 2.0f * float(M_PI);
    const float radius = v;
    return V3{ 4.4f * radius * std::cos(angle), -1.0f, 4.4f * radius * std::sin(angle) };
}

/// Builds a paraboloid of revolution closed by a planar circular face.
static void ExactParaboloid(MeshData& mesh) {
    GridWithNormals(mesh, ROUND_SIDES, 48, ParaboloidPosition, ParaboloidNormal);
    DiscY(mesh, ROUND_SIDES, 1.0f, 1.0f, true);
}

/// Returns the common longitude used by new rounded surfaces, closing the circular seam exactly.
static float RoundedSurfaceLongitude(float u) {
    if (u >= 1.0f) {
        return 0.0f;
    }
    return u * 2.0f * float(M_PI);
}

/// Samples the circular spheroplatelet's exact outer semicircle, sharing tangent normals with its flat faces.
static void SpheroplateletGeometry(float u, float v, V3& position, V3& normal) {
    const float longitude = RoundedSurfaceLongitude(u);
    const float latitude = (0.5f - v) * float(M_PI);
    float radialNormal = std::cos(latitude);
    float verticalNormal = std::sin(latitude);
    if (v <= 0.0f) {
        radialNormal = 0.0f;
        verticalNormal = 1.0f;
    } else if (v >= 1.0f) {
        radialNormal = 0.0f;
        verticalNormal = -1.0f;
    }
    const float radius = SPHEROPLATELET_DISC_RADIUS + SPHEROPLATELET_ROUNDING_RADIUS * radialNormal;
    const float height = SPHEROPLATELET_ROUNDING_RADIUS * verticalNormal;
    position = Radial(longitude, radius, height);
    normal = Radial(longitude, radialNormal, verticalNormal);
}

/// Returns one analytic position on the rounded edge of the circular spheroplatelet.
static V3 SpheroplateletPosition(float u, float v) {
    V3 position{}, normal{};
    SpheroplateletGeometry(u, v, position, normal);
    return position;
}

/// Returns one analytic outward normal on the rounded edge of the circular spheroplatelet.
static V3 SpheroplateletNormal(float u, float v) {
    V3 position{}, normal{};
    SpheroplateletGeometry(u, v, position, normal);
    return normal;
}

/// Builds the Minkowski sum of a circular disc and a sphere, with two flat faces and a tangent toroidal edge.
static void ExactSpheroplatelet(MeshData& mesh) {
    constexpr unsigned rows = 64;
    const unsigned ringBase = static_cast<unsigned>(mesh.vertices.size());
    GridWithNormals(mesh, ROUND_SIDES, rows, SpheroplateletPosition, SpheroplateletNormal);
    CloseDiscRing(mesh, ringBase, ROUND_SIDES, SPHEROPLATELET_ROUNDING_RADIUS, true);
    CloseDiscRing(mesh, ringBase + rows * (ROUND_SIDES + 1), ROUND_SIDES, -SPHEROPLATELET_ROUNDING_RADIUS, false);
}

/// Builds conservative rasterization bounds for the analytically rendered spherocylinder.
static void CapsuleBounds(MeshData& mesh) {
    Box(mesh);
    for (Vertex& vertex : mesh.vertices) {
        vertex.x *= CAPSULE_RADIUS;
        vertex.y *= CAPSULE_HALF_LENGTH + CAPSULE_RADIUS;
        vertex.z *= CAPSULE_RADIUS;
    }
}

/// Returns one position on the outer or inner side of a hollow cylinder.
static V3 HollowCylinderPosition(float u, float v, float radius, float) {
    return Radial(u * 2.0f * float(M_PI), radius, 2.0f * v - 1.0f);
}

/// Returns the outward or inward radial normal of a hollow cylinder.
static V3 HollowCylinderNormal(float u, float, float, float direction) {
    const float angle = u * 2.0f * float(M_PI);
    return V3{ direction * std::cos(angle), 0, direction * std::sin(angle) };
}

/// Builds a closed hollow cylinder with outer, inner and annular surfaces.
static void ExactHollowCylinder(MeshData& mesh) {
    for (int surface = 0; surface < 2; surface++) {
        const float radius = surface == 0 ? 1.0f : .6f;
        const float direction = surface == 0 ? 1.0f : -1.0f;
        GridWithNormals(mesh, ROUND_SIDES, 1, HollowCylinderPosition, HollowCylinderNormal, radius, direction);
    }
    AnnulusY(mesh, ROUND_SIDES, 1.0f, .6f, -1.0f, false);
    AnnulusY(mesh, ROUND_SIDES, 1.0f, .6f, 1.0f, true);
}

/// Samples one straight cylindrical wall with the same endpoint coordinates as its adjoining half-torus.
static V3 RoundedHollowCylinderWallPosition(float u, float v, float radius, float direction) {
    const float height = direction * ROUNDED_HOLLOW_CYLINDER_HALF_LENGTH * (1.0f - 2.0f * v);
    return Radial(RoundedSurfaceLongitude(u), radius, height);
}

/// Returns the outward normal of one straight outer or inner cylindrical wall.
static V3 RoundedHollowCylinderWallNormal(float u, float, float, float direction) {
    return Radial(RoundedSurfaceLongitude(u), direction, 0.0f);
}

/// Samples a precise half-torus, locking its endpoint positions and normals to the two cylindrical walls.
static void RoundedHollowCylinderCapGeometry(float u, float v, float direction, V3& position, V3& normal) {
    float latitude = v * float(M_PI);
    if (direction > 0.0f) {
        latitude = (1.0f - v) * float(M_PI);
    }
    float radialNormal = std::cos(latitude);
    float verticalNormal = std::sin(latitude);
    float radius = ROUNDED_HOLLOW_CYLINDER_TORUS_RADIUS + ROUNDED_HOLLOW_CYLINDER_ROUNDING_RADIUS * radialNormal;
    if (v <= 0.0f || v >= 1.0f) {
        radialNormal = 1.0f;
        radius = ROUNDED_HOLLOW_CYLINDER_OUTER_RADIUS;
        if (v <= 0.0f && direction > 0.0f || v >= 1.0f && direction < 0.0f) {
            radialNormal = -1.0f;
            radius = ROUNDED_HOLLOW_CYLINDER_INNER_RADIUS;
        }
        verticalNormal = 0.0f;
    }
    const float height =
        direction * (ROUNDED_HOLLOW_CYLINDER_HALF_LENGTH + ROUNDED_HOLLOW_CYLINDER_ROUNDING_RADIUS * verticalNormal);
    const float longitude = RoundedSurfaceLongitude(u);
    position = Radial(longitude, radius, height);
    normal = Radial(longitude, radialNormal, direction * verticalNormal);
}

/// Returns one analytic position on an upper or lower half-torus of the rounded hollow cylinder.
static V3 RoundedHollowCylinderCapPosition(float u, float v, float direction) {
    V3 position{};
    V3 normal{};
    RoundedHollowCylinderCapGeometry(u, v, direction, position, normal);
    return position;
}

/// Returns one analytic normal on an upper or lower half-torus of the rounded hollow cylinder.
static V3 RoundedHollowCylinderCapNormal(float u, float v, float direction) {
    V3 position{};
    V3 normal{};
    RoundedHollowCylinderCapGeometry(u, v, direction, position, normal);
    return normal;
}

/// Builds two coaxial cylindrical walls joined tangentially by exact semicircular torus sections.
static void ExactRoundedHollowCylinder(MeshData& mesh) {
    GridWithNormals(mesh, ROUND_SIDES, 1, RoundedHollowCylinderWallPosition, RoundedHollowCylinderWallNormal,
        ROUNDED_HOLLOW_CYLINDER_OUTER_RADIUS, 1.0f);
    GridWithNormals(mesh, ROUND_SIDES, 1, RoundedHollowCylinderWallPosition, RoundedHollowCylinderWallNormal,
        ROUNDED_HOLLOW_CYLINDER_INNER_RADIUS, -1.0f);
    GridWithNormals(mesh, ROUND_SIDES, 64, RoundedHollowCylinderCapPosition, RoundedHollowCylinderCapNormal, 1.0f);
    GridWithNormals(mesh, ROUND_SIDES, 64, RoundedHollowCylinderCapPosition, RoundedHollowCylinderCapNormal, -1.0f);
}

/// Builds a solid mesh or conservative rasterization bounds for an analytic surface.
MeshData BuildSolidMesh(SolidKind kind) {
    MeshData mesh;
    switch (kind) {
        case SolidKind::Cube:
            Box(mesh);
            break;
        case SolidKind::Pyramid:
            ExactPyramid(mesh);
            break;
        case SolidKind::PyramidalFrustum:
            ExactSquareFrustum(mesh);
            break;
        case SolidKind::ObliquePyramidalCut:
            ExactObliquelyCutSquarePyramid(mesh);
            break;
        case SolidKind::PerpendicularPyramidalCut:
            ExactPerpendicularlyCutSquarePyramid(mesh);
            break;
        case SolidKind::TriangularPrism:
            ExactPrism(mesh, 3);
            break;
        case SolidKind::PentagonalPrism:
            ExactPrism(mesh, 5);
            break;
        case SolidKind::HexagonalPrism:
            ExactPrism(mesh, 6);
            break;
        case SolidKind::Octahedron:
            ExactBipyramid(mesh, 4, 1.0f);
            break;
        case SolidKind::PentagonalBipyramid:
            ExactBipyramid(mesh, 5);
            break;
        case SolidKind::Cone:
            ExactCone(mesh);
            break;
        case SolidKind::ConicalFrustum:
            ExactRoundFrustum(mesh, .48f);
            break;
        case SolidKind::ObliqueConicalCut:
            ExactObliquelyCutCone(mesh);
            break;
        case SolidKind::PerpendicularConicalCut:
            ExactPerpendicularlyCutCone(mesh);
            break;
        case SolidKind::Cylinder:
            ExactRoundFrustum(mesh, 1.0f);
            break;
        case SolidKind::HollowCylinder:
            ExactHollowCylinder(mesh);
            break;
        case SolidKind::RoundedHollowCylinder:
            ExactRoundedHollowCylinder(mesh);
            break;
        case SolidKind::Paraboloid:
            ExactParaboloid(mesh);
            break;
        case SolidKind::Sphere:
        case SolidKind::Ellipsoid:
        case SolidKind::ProlateEllipsoid:
        case SolidKind::OblateEllipsoid:
        case SolidKind::Egg:
            RoundedObject(mesh, kind);
            break;
        case SolidKind::Hemisphere:
            ExactHemisphereOrCap(mesh, false);
            break;
        case SolidKind::SphericalCap:
            ExactHemisphereOrCap(mesh, true);
            break;
        case SolidKind::SphereWithoutOneCap:
            ExactSphereWithoutOneCap(mesh);
            break;
        case SolidKind::SphereWithoutCaps:
            ExactSphereWithoutCaps(mesh);
            break;
        case SolidKind::Capsule:
            CapsuleBounds(mesh);
            break;
        case SolidKind::Spheroplatelet:
            ExactSpheroplatelet(mesh);
            break;
        case SolidKind::Torus:
            ExactTorus(mesh);
            break;
        default:
            break;
    }
    return mesh;
}
