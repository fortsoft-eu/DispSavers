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

/// Neutral defaults reproduce the original flight; each simulation supplies independent random variations.
struct MotionParameters {
    std::array<float, 4> phases{};
    std::array<float, 4> waves{ 1.0f, 1.0f, 1.0f, 1.0f };
    std::array<float, 4> camera{ 1.0f, 1.0f, 1.0f, 1.0f };
    std::array<float, 4> pathPhases{};
};

/// A complete frame of one independently randomized procedural flight animation.
struct SceneState {
    float animationTime = 0.0f;
    MotionParameters motion;
    std::array<float, 4> cameraRotation{ 0.0f, 0.0f, 0.0f, 1.0f };
    std::uint32_t enabledEffects = 1U;
    bool infiniteSurfaceFilled = false;
    bool morphingSurfaceFilled = false;
    SurfaceShape surfaceShape = SurfaceShape::Waves;
    float surfaceActivation = 1.0f;
    std::array<float, 4> funnelMotion{};
    std::array<float, 4> funnelCycle{};
    std::array<float, 4> funnelCapture{};
    std::array<float, 4> funnelGrid{};
    std::array<float, 4> funnelView{};
    std::array<float, 4> funnelPath{};
    float funnelHeading = 0.0f;
    bool funnelEntry = false;
    bool mainLight = true;
    bool fillLight = false;
    bool ambientLight = true;
    bool rimLight = true;
};

/// Owns this monitor's flight clock, cryptographic entropy and smoothly changing scene parameters.
class Simulation final {

public:
    /// Initializes an independent scene from system entropy, optionally mixed with the monitor seed.
    explicit Simulation(unsigned initialSeed = 0);

    /// Starts a fresh independently randomized scene.
    void Reset(unsigned initialSeed = 0);

    /// Advances the common flight clock by the monitor-paced step and applies the selected effects.
    void Step(double seconds, float speed, std::uint32_t selectedEffects, bool cameraTumbling = false,
        bool cameraReversals = false);

    void SetSurfaceShape(SurfaceShape shape, EffectKind effect);

    /// Returns the snapshot for rendering.
    const SceneState& State() const;

private:
    /// Refills this simulation's random cache using the Windows system CSPRNG.
    void RefillRandomBuffer();

    /// Returns one cryptographically generated 32-bit value from the local cache.
    std::uint32_t NextCryptographicRandom();

    /// Scales one cryptographic value between the supplied bounds.
    float CryptographicRandom(float low, float high);

    /// Reserves independent cryptographic funnel values from the other end of the same cache.
    float CryptographicFunnelRandom(float low, float high);

    /// Creates bounded variations for phases, waves, camera motion and path curvature.
    MotionParameters CreateRandomParameters();

    /// Publishes a continuous transition and draws new cryptographic targets as the flight advances.
    void UpdateMotionParameters();

    /// Draws a new slow rotation vector from this monitor's cryptographic RNG.
    std::array<double, 3> CreateAngularVelocity();

    /// Resets the camera orientation and the optional stop-and-reverse cycle.
    void ResetCameraRotation();

    /// Enables random stops or smoothly resumes continuous tumbling without an orientation jump.
    void ConfigureCameraReversals(bool enabled);

    /// Chooses the next braking, stopped, accelerating or cruising interval.
    void AdvanceTumblingPhase();

    /// Returns the signed speed multiplier at the supplied time within the current interval.
    double TumblingSpeedFactor(double phaseTime) const;

    /// Advances a unit quaternion about a smoothly and independently changing rotation axis.
    void UpdateCameraRotation(double seconds, bool enabled, bool reversals);

    /// Evaluates the unmodified absolute world camera for the selected flight.
    std::array<double, 3> NativeCameraPosition(double sampleTime) const;

    std::array<double, 3> NativeCameraVelocity(double sampleTime) const;

    std::array<double, 3> NativeViewMotion(double sampleTime, double height, double heightVelocity) const;

    std::array<double, 3> FunnelRadialMotion(double pathTime) const;

    void ResetFunnel(bool entering);

    /// Freezes the native capture position and solves the exact finite-body exit once per cycle.
    void PrepareFunnelCapture();

    void UpdateFunnel(double seconds, SurfaceShape shape);

    enum class TumblingPhase {
        Cruising,
        Braking,
        Stopped,
        Accelerating
    };

    TumblingPhase tumblingPhase = TumblingPhase::Cruising;
    double reversalTime = 0.0;
    double reversalDuration = 0.0;
    double tumblingDirection = 1.0;
    double tumblingResumeFrom = 0.0;
    bool cameraReversalsEnabled = false;
    std::array<double, 4> cameraOrientation{ 0.0, 0.0, 0.0, 1.0 };
    std::array<double, 3> tumblingFrom{};
    std::array<double, 3> tumblingTo{};
    double tumblingTime = 0.0;
    double tumblingStart = 0.0;
    double tumblingDuration = 1.0;

    static constexpr std::size_t RANDOM_BUFFER_SIZE = 65536;
    std::array<std::uint32_t, RANDOM_BUFFER_SIZE> randomBuffer{};
    std::size_t randomBufferPosition = RANDOM_BUFFER_SIZE;
    std::size_t funnelRandomBufferPosition = RANDOM_BUFFER_SIZE;
    double timeOrigin = 0.0;
    double transitionStart = 0.0;
    double transitionDuration = 1.0;
    MotionParameters transitionFrom;
    MotionParameters transitionTo;
    double elapsed = 0.0;
    double surfaceActivationStart = 0.0;
    double funnelStart = 0.0;
    double funnelElapsed = 0.0;
    double funnelDuration = 1.0;
    EffectKind funnelEffect = EffectKind::InfiniteSurface;
    bool funnelCaptured = false;
    SceneState state{};
};
