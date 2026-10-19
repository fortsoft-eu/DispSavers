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

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "Simulation.h"
#include <windows.h>
#include <bcrypt.h>
#include <algorithm>
#include <cmath>
#include <stdexcept>

#pragma comment(lib, "bcrypt.lib")

/// Initializes an independently randomized monitor scene.
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

/// Rejection sampling avoids bias and never converts a rounded floating-point endpoint to an array index.
std::uint32_t Simulation::CryptographicIndex(std::uint32_t count) {
    if (count == 0) {
        throw std::invalid_argument("The random-index bound must be nonzero.");
    }
    const std::uint32_t threshold = (0U - count) % count;
    std::uint32_t value = 0;
    do {
        value = NextCryptographicRandom();
    } while (value < threshold);
    return value % count;
}

/// Scales one cached random value between the supplied bounds using double-precision arithmetic.
/// The final conversion to float can round the result to either endpoint.
float Simulation::CryptographicRandom(float low, float high) {
    constexpr double inverseRange = 1.0 / 4294967296.0;
    const double unit = static_cast<double>(NextCryptographicRandom()) * inverseRange;
    return static_cast<float>(static_cast<double>(low) + (static_cast<double>(high) - static_cast<double>(low)) * unit);
}

/// Draws independent bounded variations without replacing the original surfaces or palettes.
MotionParameters Simulation::CreateRandomParameters() {
    MotionParameters parameters;
    constexpr float pi = 3.14159265358979323846f;
    for (std::size_t index = 0; index < parameters.phases.size(); index++) {
        parameters.phases[index] = CryptographicRandom(-pi, pi);
        parameters.pathPhases[index] = CryptographicRandom(-pi, pi);
    }
    parameters.waves[0] = CryptographicRandom(0.75f, 1.25f);
    parameters.waves[1] = CryptographicRandom(0.70f, 1.30f);
    parameters.waves[2] = CryptographicRandom(0.85f, 1.15f);
    parameters.waves[3] = CryptographicRandom(0.90f, 1.10f);
    parameters.camera[0] = CryptographicRandom(0.65f, 1.35f);
    parameters.camera[1] = CryptographicRandom(0.85f, 1.15f);
    parameters.camera[2] = CryptographicRandom(0.60f, 1.40f);
    parameters.camera[3] = CryptographicRandom(0.85f, 1.15f);
    return parameters;
}

/// Blends one parameter vector without altering the flight clock or introducing frame-to-frame randomness.
static void BlendMotionValues(std::array<float, 4>& destination, const std::array<float, 4>& from,
        const std::array<float, 4>& to, float amount) {
    for (std::size_t index = 0; index < destination.size(); index++) {
        destination[index] = from[index] + (to[index] - from[index]) * amount;
    }
}

/// Uses a quintic transition with zero velocity and acceleration at each random-target boundary.
void Simulation::UpdateMotionParameters() {
    while (elapsed >= transitionStart + transitionDuration) {
        transitionFrom = transitionTo;
        transitionStart += transitionDuration;
        transitionTo = CreateRandomParameters();
        transitionTo.pathPhases = transitionFrom.pathPhases;
        transitionDuration = CryptographicRandom(45.0f, 90.0f);
    }
    const float progress = static_cast<float>(std::clamp(
        (elapsed - transitionStart) / transitionDuration, 0.0, 1.0));
    const float amount = progress * progress * progress * (progress * (progress * 6.0f - 15.0f) + 10.0f);
    BlendMotionValues(state.motion.phases, transitionFrom.phases, transitionTo.phases, amount);
    BlendMotionValues(state.motion.waves, transitionFrom.waves, transitionTo.waves, amount);
    BlendMotionValues(state.motion.camera, transitionFrom.camera, transitionTo.camera, amount);
    BlendMotionValues(state.motion.pathPhases, transitionFrom.pathPhases, transitionTo.pathPhases, amount);
}

/// Draws an isotropic three-axis angular velocity at the original slow tumbling speed.
std::array<double, 3> Simulation::CreateAngularVelocity() {
    constexpr float twoPi = 6.28318530717958647692f;
    const double azimuth = CryptographicRandom(0.0f, twoPi);
    const double axial = CryptographicRandom(-1.0f, 1.0f);
    const double radial = std::sqrt(1.0 - axial * axial);
    const double speed = CryptographicRandom(0.20f, 0.50f);
    return {radial * std::cos(azimuth) * speed, radial * std::sin(azimuth) * speed, axial * speed};
}

/// The same quintic easing as FSSaver's FlightEase, evaluated on the CPU for continuous motion targets.
static double MotionEase(double progress) {
    progress = std::clamp(progress, 0.0, 1.0);
    return progress * progress * progress * (progress * (progress * 6.0 - 15.0) + 10.0);
}

/// Integrates a local angular velocity without changing orientation when the rotation axis changes.
static void RotateCamera(std::array<double, 4>& rotation, const std::array<double, 3>& velocity, double seconds) {
    const double length = std::sqrt(velocity[0] * velocity[0] + velocity[1] * velocity[1]
        + velocity[2] * velocity[2]);
    if (length == 0.0) {
        return;
    }
    const double halfAngle = length * seconds * 0.5;
    const double factor = std::sin(halfAngle) / length;
    const double x = velocity[0] * factor;
    const double y = velocity[1] * factor;
    const double z = velocity[2] * factor;
    const double w = std::cos(halfAngle);
    const std::array<double, 4> next{
        rotation[3] * x + rotation[0] * w + rotation[1] * z - rotation[2] * y,
        rotation[3] * y - rotation[0] * z + rotation[1] * w + rotation[2] * x,
        rotation[3] * z + rotation[0] * y - rotation[1] * x + rotation[2] * w,
        rotation[3] * w - rotation[0] * x - rotation[1] * y - rotation[2] * z
    };
    const double inverseLength = 1.0 / std::sqrt(next[0] * next[0] + next[1] * next[1]
        + next[2] * next[2] + next[3] * next[3]);
    for (std::size_t index = 0; index < rotation.size(); index++) {
        rotation[index] = next[index] * inverseLength;
    }
}

/// Resets camera state without advancing the flight or consuming random values.
void Simulation::ResetCameraRotation() {
    cameraOrientation = {0.0, 0.0, 0.0, 1.0};
    state.cameraRotation = {0.0f, 0.0f, 0.0f, 1.0f};
    tumblingTime = 0.0;
    tumblingStart = 0.0;
    tumblingPhase = TumblingPhase::Cruising;
    reversalTime = 0.0;
    reversalDuration = 0.0;
    tumblingDirection = 1.0;
    tumblingResumeFrom = 0.0;
    cameraReversalsEnabled = false;
}

/// Keeps the instantaneous speed and orientation continuous when the option changes.
void Simulation::ConfigureCameraReversals(bool enabled) {
    if (enabled == cameraReversalsEnabled) {
        return;
    }
    cameraReversalsEnabled = enabled;
    if (tumblingPhase == TumblingPhase::Cruising) {
        reversalTime = 0.0;
        reversalDuration = enabled ? CryptographicRandom(8.0f, 24.0f) : 0.0;
    } else if (!enabled) {
        tumblingResumeFrom = TumblingSpeedFactor(reversalTime);
        tumblingPhase = TumblingPhase::Accelerating;
        reversalTime = 0.0;
        reversalDuration = 4.0;
    }
}

/// Freezes the rotation axis while braking and restarting so that the next movement really reverses it.
void Simulation::AdvanceTumblingPhase() {
    reversalTime = 0.0;
    switch (tumblingPhase) {
        case TumblingPhase::Cruising:
            tumblingPhase = TumblingPhase::Braking;
            reversalDuration = CryptographicRandom(4.0f, 8.0f);
            break;
        case TumblingPhase::Braking:
            tumblingPhase = TumblingPhase::Stopped;
            reversalDuration = CryptographicRandom(1.0f, 3.0f);
            break;
        case TumblingPhase::Stopped:
            tumblingDirection = -tumblingDirection;
            tumblingResumeFrom = 0.0;
            tumblingPhase = TumblingPhase::Accelerating;
            reversalDuration = CryptographicRandom(4.0f, 8.0f);
            break;
        case TumblingPhase::Accelerating:
            tumblingPhase = TumblingPhase::Cruising;
            reversalDuration = cameraReversalsEnabled ? CryptographicRandom(8.0f, 24.0f) : 0.0;
            break;
    }
}

/// Quintic ramps have zero acceleration at the stationary interval and both ends of the speed change.
double Simulation::TumblingSpeedFactor(double phaseTime) const {
    switch (tumblingPhase) {
        case TumblingPhase::Braking:
            return tumblingDirection * (1.0 - MotionEase(phaseTime / reversalDuration));
        case TumblingPhase::Stopped:
            return 0.0;
        case TumblingPhase::Accelerating:
            return tumblingResumeFrom + (tumblingDirection - tumblingResumeFrom)
                * MotionEase(phaseTime / reversalDuration);
        default:
            return tumblingDirection;
    }
}

/// Changes angular velocity smoothly on all three axes; midpoint substeps preserve monitor-paced motion.
void Simulation::UpdateCameraRotation(double seconds, bool enabled, bool reversals) {
    if (!enabled) {
        ResetCameraRotation();
        return;
    }
    ConfigureCameraReversals(reversals);
    double remaining = seconds;
    while (remaining > 0.0) {
        const bool cruising = tumblingPhase == TumblingPhase::Cruising;
        const bool timedPhase = cameraReversalsEnabled || !cruising;
        if (timedPhase && reversalTime >= reversalDuration) {
            AdvanceTumblingPhase();
            continue;
        }
        const double end = tumblingStart + tumblingDuration;
        if (cruising && tumblingTime >= end) {
            tumblingFrom = tumblingTo;
            tumblingTo = CreateAngularVelocity();
            tumblingStart = end;
            tumblingDuration = CryptographicRandom(18.0f, 40.0f);
            continue;
        }
        double step = std::min(remaining, 1.0 / 120.0);
        if (cruising) {
            step = std::min(step, end - tumblingTime);
        }
        if (timedPhase) {
            step = std::min(step, reversalDuration - reversalTime);
        }
        const double rotationTime = tumblingTime + (cruising ? step * 0.5 : 0.0);
        const double amount = MotionEase((rotationTime - tumblingStart) / tumblingDuration);
        const double factor = TumblingSpeedFactor(reversalTime + step * 0.5);
        std::array<double, 3> velocity{};
        for (std::size_t index = 0; index < velocity.size(); index++) {
            velocity[index] = (tumblingFrom[index] + (tumblingTo[index] - tumblingFrom[index]) * amount) * factor;
        }
        RotateCamera(cameraOrientation, velocity, step);
        if (cruising) {
            tumblingTime += step;
        }
        if (timedPhase) {
            reversalTime += step;
        }
        remaining -= step;
    }
    for (std::size_t index = 0; index < state.cameraRotation.size(); index++) {
        state.cameraRotation[index] = static_cast<float>(cameraOrientation[index]);
    }
}

/// Keeps the original wavy route between occasional sustained turns in any transverse direction.
std::array<double, 3> Simulation::CreateCorridorTurn() {
    constexpr float twoPi = 6.28318530717958647692f;
    const double direction = CryptographicRandom(0.0f, twoPi);
    const double curvature = CryptographicIndex(4) == 0 ? 0.0 : CryptographicRandom(0.002f, 0.008f);
    return {std::cos(direction) * curvature, std::sin(direction) * curvature,
        CryptographicRandom(-0.035f, 0.035f)};
}

/// Holds each turn after easing into it; the bounded local arc stays regular throughout the visible corridor.
void Simulation::UpdateCorridorPath(double seconds) {
    constexpr double twoPi = 6.28318530717958647692;
    double remaining = seconds;
    while (remaining > 0.0) {
        const double end = corridorStart + corridorDuration;
        if (corridorTime >= end) {
            corridorFrom = corridorTo;
            corridorTo = CreateCorridorTurn();
            corridorStart = end;
            corridorDuration = CryptographicRandom(36.0f, 80.0f);
            continue;
        }
        const double step = std::min({remaining, 0.05, end - corridorTime});
        const double amount = MotionEase((corridorTime + step * 0.5 - corridorStart) / (corridorDuration * 0.35));
        const double rollSpeed = corridorFrom[2] + (corridorTo[2] - corridorFrom[2]) * amount;
        corridorRoll = std::remainder(corridorRoll + rollSpeed * step, twoPi);
        corridorTime += step;
        remaining -= step;
    }
    const double amount = MotionEase((corridorTime - corridorStart) / (corridorDuration * 0.35));
    for (std::size_t index = 0; index < 2; index++) {
        state.corridorShape[index] = static_cast<float>(corridorFrom[index]
            + (corridorTo[index] - corridorFrom[index]) * amount);
    }
    state.corridorShape[2] = static_cast<float>(corridorRoll);
}

/// Restarts with fresh cryptographic entropy even when multiple monitors supply the same seed.
void Simulation::Reset(unsigned initialSeed) {
    randomBufferPosition = randomBuffer.size();
    const std::uint32_t origin = NextCryptographicRandom() ^ initialSeed * 1009U;
    constexpr double inverseRange = 1.0 / 4294967296.0;
    timeOrigin = static_cast<double>(origin) * inverseRange * 512.0;
    elapsed = 0.0;
    transitionStart = 0.0;
    transitionDuration = CryptographicRandom(45.0f, 90.0f);
    transitionFrom = CreateRandomParameters();
    transitionTo = CreateRandomParameters();
    transitionTo.pathPhases = transitionFrom.pathPhases;
    state = SceneState{};
    state.animationTime = static_cast<float>(timeOrigin);
    state.motion = transitionFrom;
    ResetCameraRotation();
    tumblingFrom = CreateAngularVelocity();
    tumblingTo = CreateAngularVelocity();
    tumblingDuration = CryptographicRandom(18.0f, 40.0f);
    for (std::uint32_t count = static_cast<std::uint32_t>(state.wallPalettes.size()); count > 1; count--) {
        std::swap(state.wallPalettes[count - 1], state.wallPalettes[CryptographicIndex(count)]);
    }
    corridorFrom = CreateCorridorTurn();
    corridorTo = CreateCorridorTurn();
    corridorTime = 0.0;
    corridorStart = 0.0;
    corridorDuration = CryptographicRandom(36.0f, 80.0f);
    corridorRoll = CryptographicRandom(-3.14159265358979323846f, 3.14159265358979323846f);
    UpdateCorridorPath(0.0);
}

/// Retains the original monitor-paced flight speed while advancing independent scene variations.
void Simulation::Step(double seconds, float speed, std::uint32_t selectedEffects, bool cameraTumbling,
        bool cameraReversals) {
    elapsed += seconds * speed;
    state.animationTime = static_cast<float>(timeOrigin + elapsed);
    state.enabledEffects = selectedEffects & ALL_EFFECT_MASK;
    UpdateMotionParameters();
    UpdateCameraRotation(seconds * speed, cameraTumbling, cameraReversals);
    UpdateCorridorPath(seconds * speed);
}

/// Returns the immutable frame snapshot for this monitor only.
const SceneState& Simulation::State() const {
    return state;
}
