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
 * Last modified for version 1.2.1.0
 */

#pragma once

#include "Effects.h"
#include <array>

/// Minimal three-dimensional vector used by the simulation state.
struct Vec3 {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

/// Renderable transform of one solid instance.
struct SolidState {
    Vec3 position;
    Vec3 rotation;
};

/// Camera position and orthonormal view basis.
struct CameraState {
    Vec3 position;
    Vec3 right;
    Vec3 up;
    Vec3 forward;
};

/// Immutable render snapshot published after each simulation step.
struct SceneState {
    std::array<SolidState, MAX_SOLID_INSTANCES> solids{};
    std::size_t solidCount = SOLID_COUNT;
    float objectScale = 1.0f;
    CameraState camera{};
    std::uint32_t enabledSolids = ALL_SOLID_MASK;
    bool cameraFlight = false;
    bool mainLight = true;
    bool fillLight = false;
    bool ambientLight = true;
    bool rimLight = true;
};

/// Advances object motion, collisions and the optional forward flight camera.
class Simulation final {

public:
    /// Initializes an independent scene from system entropy, optionally mixed with the monitor seed.
    explicit Simulation(unsigned initialSeed = 0);

    /// Starts a fresh independently randomized scene.
    void Reset(unsigned initialSeed = 0);

    /// Updates the aspect ratio used to keep visible bounds monitor-independent.
    void SetViewport(unsigned width, unsigned height);

    /// Advances the scene by a measured interval and applies current settings.
    void Step(double seconds, float objectSpeed, float cameraSpeed, bool cameraFlight,
        std::uint32_t selectedEnabledSolids, int selectedCopyCount, float selectedObjectScale, int maximumSubsteps = 0);

    /// Returns the most recently published render snapshot.
    const SceneState& State() const {
        return state;
    }

private:
    /// Cryptographic random-number cache
    static constexpr std::size_t RANDOM_BUFFER_SIZE = 65536;

    /// Dynamic state retained for each simulated rigid body.
    struct Body {
        Vec3 position;
        Vec3 velocity;
        Vec3 rotation;
        Vec3 angularVelocity;
        float radius = 1.0f;
        float targetSpeed = 1.0f;
    };

    /// Simulation stages

    /// Integrates one interval, restores body speeds and resolves scene collisions.
    void Substep(float seconds, float objectSpeed, float cameraSpeed, bool cameraFlight);

    /// Separates enabled intersecting bodies and applies equal-mass elastic impulses.
    void ResolveSolidCollisions(std::uint32_t selectedEnabledSolids);

    /// Reflects bodies from the viewing frustum or the moving flight volume.
    void ResolveRoomBounds(bool cameraFlight);

    /// Smoothly steers approaching bodies away from the straight camera corridor.
    void ResolveCameraPathCollisions(float seconds, float objectSpeed, float cameraSpeed);

    /// Gradually restores collision-modified velocities to each body's target speed.
    void RestoreBodySpeeds(float seconds);

    /// Distributes newly activated bodies throughout the flight volume.
    void InitializeFlightBodies(std::size_t firstBody);

    /// Advances the camera along its fixed forward rail.
    void UpdateCamera(float seconds, float cameraSpeed);

    /// Copies the current transforms and camera basis into the renderer-facing snapshot.
    void PublishState();

    /// Returns one cached cryptographic random value, refilling the cache when exhausted.
    std::uint32_t NextCryptographicRandom();

    /// Returns a random float scaled between the supplied bounds.
    float CryptographicRandom(float low, float high);

    /// Refills the cache from the Windows system RNG and throws if generation fails.
    void RefillRandomBuffer();

    /// Object and published scene state
    std::array<Body, MAX_SOLID_INSTANCES> bodies{};
    SceneState state{};

    /// Camera integration state
    Vec3 cameraPosition{};
    Vec3 cameraVelocity{};
    float yaw = 0.0f;
    float pitch = 0.0f;
    float roll = 0.0f;
    double elapsed = 0.0;

    /// Random-number state
    unsigned seed = 0;
    std::array<std::uint32_t, RANDOM_BUFFER_SIZE> randomBuffer{};
    std::size_t randomBufferPosition = RANDOM_BUFFER_SIZE;

    /// Active settings and viewport geometry
    bool cameraFlightEnabled = false;
    std::uint32_t enabledSolids = ALL_SOLID_MASK;
    std::size_t activeBodyCount = SOLID_COUNT;
    int copyCount = 1;
    float objectScale = 1.0f;
    float viewportAspect = 16.0f / 9.0f;
};
