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

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "Simulation.h"
#include <Windows.h>
#include <bcrypt.h>
#include <algorithm>
#include <cmath>
#include <stdexcept>

#pragma comment(lib, "bcrypt.lib")

/// View-frustum and flight-volume geometry
constexpr float PROJECTION_TANGENT = 0.64f;
constexpr float STATIC_NEAR_DISTANCE = 8.0f;
constexpr float STATIC_FAR_DISTANCE = 44.0f;
constexpr float FLIGHT_NEAR_DISTANCE = -5.0f;
constexpr float FLIGHT_FAR_DISTANCE = 174.0f;
constexpr float FLIGHT_DEPTH = FLIGHT_FAR_DISTANCE - FLIGHT_NEAR_DISTANCE;
constexpr float CLOSE_FLIGHT_DEPTH = 92.0f;
constexpr float FLIGHT_HALF_WIDTH = 42.0f;
constexpr float FLIGHT_HALF_HEIGHT = 25.0f;

/// Vector arithmetic used internally by the physics implementation.

/// Adds two vectors component by component.
static Vec3 operator+(Vec3 a, Vec3 b) {
    return Vec3{
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    };
}

/// Subtracts two vectors component by component.
static Vec3 operator-(Vec3 a, Vec3 b) {
    return Vec3{
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    };
}

/// Multiplies every vector component by a scalar.
static Vec3 operator*(Vec3 a, float scalar) {
    return Vec3{
        a.x * scalar,
        a.y * scalar,
        a.z * scalar
    };
}

/// Divides a vector by a scalar through its reciprocal.
static Vec3 operator/(Vec3 a, float scalar) {
    return a * (1.0f / scalar);
}

/// Adds a vector in place and returns the modified left operand.
static Vec3& operator+=(Vec3& a, Vec3 b) {
    a = a + b;
    return a;
}

/// Subtracts a vector in place and returns the modified left operand.
static Vec3& operator-=(Vec3& a, Vec3 b) {
    a = a - b;
    return a;
}

/// Scales a vector in place and returns the modified left operand.
static Vec3& operator*=(Vec3& a, float scalar) {
    a = a * scalar;
    return a;
}

/// Returns the scalar product of two vectors.
static float Dot(Vec3 a, Vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

/// Returns the right-handed vector product of two vectors.
static Vec3 Cross(Vec3 a, Vec3 b) {
    return Vec3{
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

/// Returns the squared vector length without a square-root calculation.
static float LengthSquared(Vec3 value) {
    return Dot(value, value);
}

/// Returns the vector length with a positive lower bound for safe normalization.
static float Length(Vec3 value) {
    return std::sqrt(std::max(LengthSquared(value), 1.0e-12f));
}

/// Scales a vector by its bounded reciprocal length; the zero vector remains zero.
static Vec3 Normalized(Vec3 value) {
    return value / Length(value);
}

/// Updates the aspect ratio used by the static-camera collision frustum.
void Simulation::SetViewport(unsigned width, unsigned height) {
    if (width != 0 && height != 0) {
        viewportAspect = static_cast<float>(width) / static_cast<float>(height);
    }
}

/// Creates and initializes a simulation instance.
Simulation::Simulation(unsigned initialSeed) {
    Reset(initialSeed);
}

/// Refills the cached random values from the Windows system RNG in one operation.
void Simulation::RefillRandomBuffer() {
    const NTSTATUS status = BCryptGenRandom(nullptr, reinterpret_cast<PUCHAR>(randomBuffer.data()),
        static_cast<ULONG>(randomBuffer.size() * sizeof(randomBuffer[0])), BCRYPT_USE_SYSTEM_PREFERRED_RNG);
    if (!BCRYPT_SUCCESS(status)) {
        throw std::runtime_error("The Windows cryptographic random-number generator failed.");
    }
    randomBufferPosition = 0;
}

/// Returns one cryptographically generated 32-bit value from the local cache.
std::uint32_t Simulation::NextCryptographicRandom() {
    if (randomBufferPosition >= randomBuffer.size()) {
        RefillRandomBuffer();
    }
    if (randomBufferPosition >= randomBuffer.size()) {
        throw std::runtime_error("The cryptographic random-number buffer is invalid.");
    }
    return randomBuffer[randomBufferPosition++];
}

/// Scales one cached random value between the supplied bounds using double-precision arithmetic.
/// The final conversion to float can round the result to either endpoint.
float Simulation::CryptographicRandom(float low, float high) {
    constexpr double inverseRange = 1.0 / 4294967296.0;
    const double unit = static_cast<double>(NextCryptographicRandom()) * inverseRange;
    return static_cast<float>(static_cast<double>(low) + (static_cast<double>(high) - static_cast<double>(low)) * unit);
}

/// Reinitializes every body and camera state from system entropy and an optional seed.
/// A permuted 9 x 6 x 5 lattice spreads even one copy of every solid throughout the flight depth.
void Simulation::Reset(unsigned initialSeed) {
    randomBufferPosition = randomBuffer.size();
    seed = NextCryptographicRandom() ^ initialSeed * 1009U;
    elapsed = 0.0;
    for (std::size_t i = 0; i < bodies.size(); i++) {
        const std::size_t slot = i * 103U % 270U;
        const int column = static_cast<int>(slot % 9U);
        const int row = static_cast<int>(slot / 9U % 6U);
        const int layer = static_cast<int>(slot / 54U);
        const std::size_t kind = i % SOLID_COUNT;
        Body& body = bodies[i];
        body.radius = COLLISION_RADII[kind];
        body.position = Vec3{
            -12.8f + 3.2f * column,
            -6.0f + 2.4f * row,
            -14.0f + 7.0f * layer + CryptographicRandom(-2.25f, 2.25f)
        };
        Vec3 direction{
            CryptographicRandom(-1.0f, 1.0f),
            CryptographicRandom(-0.75f, 0.75f),
            CryptographicRandom(-1.0f, 1.0f)
        };
        body.targetSpeed = CryptographicRandom(1.15f, 2.05f);
        body.velocity = Normalized(direction) * body.targetSpeed;
        body.rotation = Vec3{
            CryptographicRandom(0.0f, 6.2831853f),
            CryptographicRandom(0.0f, 6.2831853f),
            CryptographicRandom(0.0f, 6.2831853f)
        };
        body.angularVelocity = Vec3{
            CryptographicRandom(-0.7f, 0.7f),
            CryptographicRandom(-0.7f, 0.7f),
            CryptographicRandom(-0.7f, 0.7f)
        };
    }
    cameraFlightEnabled = false;
    activeBodyCount = SOLID_COUNT;
    copyCount = 1;
    objectScale = 1.0f;
    cameraPosition = Vec3{
        0.0f,
        0.0f,
        -26.0f
    };
    cameraVelocity = Vec3{};
    yaw = 0.0f;
    pitch = 0.0f;
    roll = 0.0f;
    PublishState();
}

/// Applies settings, advances the requested interval and publishes a render snapshot. Full-size surfaces use one exact
/// step per presented frame; only the accelerated miniature system preview may cap its physics work with multiple
/// substeps while advancing the full simulated interval.
void Simulation::Step(double seconds, float objectSpeed, float cameraSpeed, bool cameraFlight,
        std::uint32_t selectedEnabledSolids, int selectedCopyCount, float selectedObjectScale, int maximumSubsteps) {
    seconds = std::clamp(seconds, 0.0, 3.0);
    objectSpeed = std::clamp(objectSpeed, 0.0f, 16.0f);
    cameraSpeed = std::clamp(cameraSpeed, 0.0f, 16.0f);
    const std::size_t previousActiveBodyCount = activeBodyCount;
    copyCount = std::clamp(selectedCopyCount, 1, static_cast<int>(MAX_COPIES_PER_SOLID));
    objectScale = std::clamp(selectedObjectScale, 0.5f, 2.0f);
    activeBodyCount = SOLID_COUNT * static_cast<std::size_t>(copyCount);
    for (std::size_t index = 0; index < activeBodyCount; index++) {
        bodies[index].radius = COLLISION_RADII[index % SOLID_COUNT] * objectScale;
    }
    enabledSolids = selectedEnabledSolids & ALL_SOLID_MASK;
    if (cameraFlight && !cameraFlightEnabled) {
        cameraPosition = Vec3{
            0.0f,
            0.0f,
            -26.0f
        };
        cameraVelocity = Vec3{
            0.0f,
            0.0f,
            2.4f * cameraSpeed
        };
        yaw = pitch = roll = 0.0f;
        InitializeFlightBodies(0);
    } else if (cameraFlight && activeBodyCount > previousActiveBodyCount) {
        InitializeFlightBodies(previousActiveBodyCount);
    } else if (!cameraFlight) {
        cameraPosition = Vec3{
            0.0f,
            0.0f,
            -26.0f
        };
        cameraVelocity = Vec3{};
        yaw = pitch = roll = 0.0f;
    }
    cameraFlightEnabled = cameraFlight;
    int steps = 1;
    if (maximumSubsteps > 1) {
        steps = std::min(maximumSubsteps, std::max(1, static_cast<int>(std::ceil(seconds / 0.01))));
    }
    const float step = static_cast<float>(seconds / steps);
    for (int i = 0; i < steps; i++) {
        Substep(step, objectSpeed, cameraSpeed, cameraFlight);
    }
    PublishState();
}

/// Integrates one physics interval and resolves all active constraints. The fixed rail camera retains a clear cylindrical
/// path, after which collision-modified velocities return smoothly to their intrinsic speed so reducing object size
/// cannot leave formerly crowded bodies permanently slow.
void Simulation::Substep(float seconds, float objectSpeed, float cameraSpeed, bool cameraFlight) {
    elapsed += seconds;
    for (std::size_t index = 0; index < activeBodyCount; index++) {
        Body& body = bodies[index];
        body.position += body.velocity * (seconds * objectSpeed);
        body.rotation += body.angularVelocity * (seconds * objectSpeed);
    }
    ResolveRoomBounds(cameraFlight);
    for (int iteration = 0; iteration < 3; iteration++) {
        ResolveSolidCollisions(enabledSolids);
        ResolveRoomBounds(cameraFlight);
    }
    if (cameraFlight) {
        UpdateCamera(seconds, cameraSpeed);
        ResolveCameraPathCollisions(seconds, objectSpeed, cameraSpeed);
        for (int iteration = 0; iteration < 2; iteration++) {
            ResolveSolidCollisions(enabledSolids);
            ResolveCameraPathCollisions(seconds, objectSpeed, cameraSpeed);
        }
    }
    RestoreBodySpeeds(seconds);
}

/// Smoothly returns collision-modified velocities to each body's intrinsic speed with refresh-independent exponential
/// convergence and a 1.5-second time constant. Degenerate opposing corrections recover deterministically without
/// calling the cryptographic generator from the render loop.
void Simulation::RestoreBodySpeeds(float seconds) {
    constexpr float goldenAngle = 2.39996323f;
    const float recovery = 1.0f - std::exp(-seconds / 1.5f);
    for (std::size_t index = 0; index < activeBodyCount; index++) {
        Body& body = bodies[index];
        const float speedSquared = LengthSquared(body.velocity);
        if (speedSquared > 1.0e-8f) {
            const float speed = std::sqrt(speedSquared);
            const float correctedSpeed = speed + (body.targetSpeed - speed) * recovery;
            body.velocity *= correctedSpeed / speed;
            continue;
        }
        const float angle = goldenAngle * static_cast<float>(index + 1U) + static_cast<float>(seed & 0xffffU) * 0.001f;
        body.velocity = Vec3{
            std::cos(angle),
            std::sin(angle * 0.73f) * 0.5f,
            std::sin(angle)
        };
        body.velocity = Normalized(body.velocity) * (body.targetSpeed * recovery);
    }
}

/// Reflects bodies from either the viewing frustum or the moving flight volume.
void Simulation::ResolveRoomBounds(bool cameraFlight) {
    if (cameraFlight) {
        for (std::size_t index = 0; index < activeBodyCount; index++) {
            Body& body = bodies[index];
            const float limits[2]{
                FLIGHT_HALF_WIDTH - body.radius,
                FLIGHT_HALF_HEIGHT - body.radius
            };
            float* position[2]{
                &body.position.x,
                &body.position.y
            };
            float* velocity[2]{
                &body.velocity.x,
                &body.velocity.y
            };
            for (int axis = 0; axis < 2; axis++) {
                if (*position[axis] < -limits[axis]) {
                    *position[axis] = -limits[axis];
                    *velocity[axis] = std::abs(*velocity[axis]);
                } else if (*position[axis] > limits[axis]) {
                    *position[axis] = limits[axis];
                    *velocity[axis] = -std::abs(*velocity[axis]);
                }
            }
            float depth = body.position.z - cameraPosition.z;
            bool recycled = false;
            const bool closePass = index % 4U == 0U;
            const float recycleDepth = closePass ? CLOSE_FLIGHT_DEPTH : FLIGHT_DEPTH;
            while (depth < FLIGHT_NEAR_DISTANCE - body.radius) {
                body.position.z += recycleDepth;
                depth += recycleDepth;
                recycled = true;
            }
            if (recycled) {
                const float halfWidth = closePass ? 8.0f : FLIGHT_HALF_WIDTH;
                const float halfHeight = closePass ? 5.0f : FLIGHT_HALF_HEIGHT;
                body.position.x = CryptographicRandom(-halfWidth + body.radius, halfWidth - body.radius);
                body.position.y = CryptographicRandom(-halfHeight + body.radius, halfHeight - body.radius);
            }
            const float farLimit = FLIGHT_FAR_DISTANCE - body.radius;
            if (depth > farLimit) {
                body.position.z = cameraPosition.z + farLimit;
                body.velocity.z = -std::abs(body.velocity.z);
            }
        }
        return;
    }
    const float horizontalSlope = PROJECTION_TANGENT * viewportAspect;
    const Vec3 leftNormal{
        1.0f,
        0.0f,
        horizontalSlope
    };
    const Vec3 rightNormal{
        -1.0f,
        0.0f,
        horizontalSlope
    };
    const Vec3 bottomNormal{
        0.0f,
        1.0f,
        PROJECTION_TANGENT
    };
    const Vec3 topNormal{
        0.0f,
        -1.0f,
        PROJECTION_TANGENT
    };
    const Vec3 nearNormal{
        0.0f,
        0.0f,
        1.0f
    };
    const Vec3 farNormal{
        0.0f,
        0.0f,
        -1.0f
    };
    const Vec3 planeNormals[]{
        Normalized(leftNormal),
        Normalized(rightNormal),
        Normalized(bottomNormal),
        Normalized(topNormal),
        nearNormal,
        farNormal
    };
    const float offsets[]{
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        STATIC_NEAR_DISTANCE,
        -STATIC_FAR_DISTANCE
    };
    for (std::size_t index = 0; index < activeBodyCount; index++) {
        Body& body = bodies[index];
        Vec3 viewPosition = body.position - cameraPosition;
        for (std::size_t plane = 0; plane < std::size(planeNormals); plane++) {
            const Vec3 normal = planeNormals[plane];
            const float distance = Dot(viewPosition, normal) - offsets[plane];
            if (distance >= body.radius) {
                continue;
            }
            const float correction = body.radius - distance;
            body.position += normal * correction;
            viewPosition += normal * correction;
            const float inwardSpeed = Dot(body.velocity, normal);
            if (inwardSpeed < 0.0f) {
                body.velocity -= normal * (2.0f * inwardSpeed);
            }
        }
    }
}

/// Separates intersecting bodies and applies equal-mass elastic impulses.
void Simulation::ResolveSolidCollisions(std::uint32_t selectedEnabledSolids) {
    for (std::size_t first = 0; first < activeBodyCount; first++) {
        if ((selectedEnabledSolids & 1U << first % SOLID_COUNT) == 0) {
            continue;
        }
        for (std::size_t second = first + 1; second < activeBodyCount; second++) {
            if ((selectedEnabledSolids & 1U << second % SOLID_COUNT) == 0) {
                continue;
            }
            Body& a = bodies[first];
            Body& b = bodies[second];
            Vec3 delta = b.position - a.position;
            float distanceSquared = LengthSquared(delta);
            const float minimumDistance = a.radius + b.radius;
            if (distanceSquared >= minimumDistance * minimumDistance) {
                continue;
            }
            if (distanceSquared < 1.0e-8f) {
                delta = Vec3{
                    1.0f,
                    0.0f,
                    0.0f
                };
                distanceSquared = 1.0f;
            }
            const float distance = std::sqrt(distanceSquared);
            const Vec3 normal = delta / distance;
            const float overlap = minimumDistance - distance;
            a.position -= normal * (overlap * 0.505f);
            b.position += normal * (overlap * 0.505f);
            const float approachingSpeed = Dot(b.velocity - a.velocity, normal);
            if (approachingSpeed < 0.0f) {
                const Vec3 impulse = normal * (-approachingSpeed * 0.98f);
                a.velocity -= impulse;
                b.velocity += impulse;
            }
        }
    }
}

/// Steers approaching bodies continuously away from the straight camera corridor.
/// Exponential steering reaches clearance before contact without teleporting and also works at zero object speed.
void Simulation::ResolveCameraPathCollisions(float seconds, float objectSpeed, float cameraSpeed) {
    constexpr float cameraRadius = 1.15f;
    constexpr float clearance = 0.55f;
    constexpr float lookAhead = 12.0f;
    constexpr float goldenAngle = 2.39996323f;
    for (std::size_t index = 0; index < activeBodyCount; index++) {
        if ((enabledSolids & 1U << index % SOLID_COUNT) == 0) {
            continue;
        }
        Body& body = bodies[index];
        const float minimumRadius = body.radius + cameraRadius;
        const float depthAhead = body.position.z - cameraPosition.z;
        const float closingSpeed = cameraVelocity.z - body.velocity.z * objectSpeed;
        if (depthAhead < -body.radius || depthAhead > lookAhead || closingSpeed <= 0.0f && depthAhead > minimumRadius) {
            continue;
        }
        float radialSquared = body.position.x * body.position.x + body.position.y * body.position.y;
        const float desiredRadius = minimumRadius + clearance;
        if (radialSquared >= desiredRadius * desiredRadius) {
            continue;
        }
        Vec3 normal{};
        if (radialSquared < 1.0e-8f) {
            const float angle = goldenAngle * static_cast<float>(index + 1) + seed * 0.001f;
            normal = Vec3{
                std::cos(angle),
                std::sin(angle), 0.0f
            };
        } else {
            const float inverseRadius = 1.0f / std::sqrt(radialSquared);
            normal = Vec3{
                body.position.x * inverseRadius,
                body.position.y * inverseRadius, 0.0f
            };
        }
        const float radialDistance = std::sqrt(std::max(radialSquared, 0.0f));
        const float remaining = desiredRadius - radialDistance;
        const float safeClosingSpeed = std::max(closingSpeed, 0.25f + cameraSpeed * 0.05f);
        const float timeToContact = std::max((depthAhead - minimumRadius * 0.35f) / safeClosingSpeed, seconds);
        const float fraction = std::clamp(seconds * 2.4f / timeToContact, 0.0f, 1.0f);
        const float displacement = std::min(remaining * fraction, 8.0f * seconds);
        body.position.x += normal.x * displacement;
        body.position.y += normal.y * displacement;
        const float inwardSpeed = body.velocity.x * normal.x + body.velocity.y * normal.y;
        if (inwardSpeed < 0.0f) {
            body.velocity.x -= 1.9f * inwardSpeed * normal.x;
            body.velocity.y -= 1.9f * inwardSpeed * normal.y;
        }
    }
}

/// Redistributes new or reset bodies continuously throughout the flight depth.
void Simulation::InitializeFlightBodies(std::size_t firstBody) {
    constexpr float goldenRatioFraction = 0.61803398875f;
    const float seedOffset = static_cast<float>(seed & 0xffffU) / 65536.0f;
    for (std::size_t index = firstBody; index < activeBodyCount; index++) {
        Body& body = bodies[index];
        const float depthFraction = std::fmod(seedOffset + static_cast<float>(index + 1) * goldenRatioFraction, 1.0f);
        const bool closePass = index % 4U == 0U;
        const float depthRange = closePass ? 82.0f : 169.0f;
        const float depth = 2.5f + std::pow(depthFraction, 1.35f) * depthRange;
        const float spread = depth / FLIGHT_FAR_DISTANCE;
        const float halfWidth = closePass ? 8.0f : 12.0f + (FLIGHT_HALF_WIDTH - 12.0f) * spread;
        const float halfHeight = closePass ? 5.0f : 7.5f + (FLIGHT_HALF_HEIGHT - 7.5f) * spread;
        body.position.x = CryptographicRandom(-halfWidth + body.radius, halfWidth - body.radius);
        body.position.y = CryptographicRandom(-halfHeight + body.radius, halfHeight - body.radius);
        body.position.z = cameraPosition.z + depth;
    }
}

/// Advances the forward-flight camera along one constant central rail without targeting, turning, pitching, rolling
/// or lateral avoidance.
void Simulation::UpdateCamera(float seconds, float cameraSpeed) {
    cameraVelocity = Vec3{
        0.0f,
        0.0f,
        2.4f * cameraSpeed
    };
    cameraPosition += cameraVelocity * seconds;
    cameraPosition.x = 0.0f;
    cameraPosition.y = 0.0f;
    yaw = pitch = roll = 0.0f;
}

/// Copies mutable physics state into the immutable renderer-facing snapshot.
void Simulation::PublishState() {
    for (std::size_t i = 0; i < activeBodyCount; i++) {
        state.solids[i] = SolidState{
            bodies[i].position,
            bodies[i].rotation
        };
    }
    state.solidCount = activeBodyCount;
    state.objectScale = objectScale;
    const float cosPitch = std::cos(pitch);
    Vec3 forward{
        std::sin(yaw) * cosPitch,
        std::sin(pitch),
        std::cos(yaw) * cosPitch
    };
    const Vec3 worldUp{
        0.0f,
        1.0f,
        0.0f
    };
    Vec3 right = Normalized(Cross(worldUp, forward));
    Vec3 up = Normalized(Cross(forward, right));
    const float cosRoll = std::cos(roll);
    const float sinRoll = std::sin(roll);
    const Vec3 rolledRight = right * cosRoll + up * sinRoll;
    const Vec3 rolledUp = up * cosRoll - right * sinRoll;
    state.camera = CameraState{
        cameraPosition,
        rolledRight,
        rolledUp,
        forward
    };
    state.enabledSolids = enabledSolids;
    state.cameraFlight = cameraFlightEnabled;
}
