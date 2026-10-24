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
    funnelRandomBufferPosition = randomBuffer.size();
}

/// Returns one cryptographically generated 32-bit value from the local cache.
std::uint32_t Simulation::NextCryptographicRandom() {
    if (randomBufferPosition >= funnelRandomBufferPosition) {
        RefillRandomBuffer();
    }
    if (randomBufferPosition >= funnelRandomBufferPosition) {
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

/// Keeps funnel entropy independent of the order in which motion and capture boundaries occur within a frame.
float Simulation::CryptographicFunnelRandom(float low, float high) {
    if (funnelRandomBufferPosition <= randomBufferPosition) {
        RefillRandomBuffer();
    }
    if (funnelRandomBufferPosition <= randomBufferPosition) {
        throw std::runtime_error("The cryptographic random-number buffer is invalid.");
    }
    constexpr double inverseRange = 1.0 / 4294967296.0;
    const double unit = static_cast<double>(randomBuffer[--funnelRandomBufferPosition]) * inverseRange;
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
    const float progress = static_cast<float>(std::clamp((elapsed - transitionStart) / transitionDuration, 0.0, 1.0));
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
    return { radial * std::cos(azimuth) * speed, radial * std::sin(azimuth) * speed, axial * speed };
}

/// Evaluates quintic easing on the CPU for continuous motion targets.
static double MotionEase(double progress) {
    progress = std::clamp(progress, 0.0, 1.0);
    return progress * progress * progress * (progress * (progress * 6.0 - 15.0) + 10.0);
}

/// Integrates a local angular velocity without changing orientation when the rotation axis changes.
static void RotateCamera(std::array<double, 4>& rotation, const std::array<double, 3>& velocity, double seconds) {
    const double length = std::sqrt(velocity[0] * velocity[0] + velocity[1] * velocity[1] + velocity[2] * velocity[2]);
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
    const double inverseLength =
        1.0 / std::sqrt(next[0] * next[0] + next[1] * next[1] + next[2] * next[2] + next[3] * next[3]);
    for (std::size_t index = 0; index < rotation.size(); index++) {
        rotation[index] = next[index] * inverseLength;
    }
}

/// Resets camera state without advancing the flight or consuming random values.
void Simulation::ResetCameraRotation() {
    cameraOrientation = { 0.0, 0.0, 0.0, 1.0 };
    state.cameraRotation = { 0.0f, 0.0f, 0.0f, 1.0f };
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

/// Evaluates the original free-flight position without changing world origin, clock or camera orientation.
std::array<double, 3> Simulation::NativeCameraPosition(double sampleTime) const {
    const MotionParameters& motion = state.motion;
    std::array<double, 3> position{};
    if (funnelEffect == EffectKind::InfiniteSurface) {
        position[0] = sampleTime * 1.15 + 4.0 * std::sin(sampleTime * 0.071 + motion.pathPhases[0]) * motion.camera[0];
        position[2] = sampleTime * 0.82 + 3.2 * std::cos(sampleTime * 0.053 + motion.pathPhases[1]) * motion.camera[0];
        const double side = std::sin(sampleTime * 0.115 + 0.65 + motion.pathPhases[2]);
        const double distance = 0.5 + 0.5 * std::sin(sampleTime * 0.17 + 0.8 + motion.pathPhases[3]);
        position[1] = (3.0 + 9.0 * distance) * side * motion.camera[1];
    } else {
        position[0] = sampleTime * 3.20 + 18.0 * std::sin(sampleTime * 0.031 + motion.pathPhases[0]) * motion.camera[0];
        position[2] = sampleTime * 2.15 + 14.0 * std::cos(sampleTime * 0.027 + motion.pathPhases[1]) * motion.camera[0];
        const double altitude = 0.5 + 0.5 * std::sin(sampleTime * 0.087 + 0.6 + motion.phases[3]);
        position[1] = (7.0 + 11.0 * altitude) * motion.camera[1];
    }
    return position;
}

std::array<double, 3> Simulation::NativeCameraVelocity(double sampleTime) const {
    const double progress = std::clamp((elapsed - transitionStart) / transitionDuration, 0.0, 1.0);
    const double first = 30.0 * progress * progress * (progress - 1.0) * (progress - 1.0) / transitionDuration;
    const MotionParameters& motion = state.motion;
    const double amplitude = motion.camera[0];
    const double amplitudeRate = (transitionTo.camera[0] - transitionFrom.camera[0]) * first;
    const double heightScale = motion.camera[1];
    const double heightRate = (transitionTo.camera[1] - transitionFrom.camera[1]) * first;
    const bool infinite = funnelEffect == EffectKind::InfiniteSurface;
    const double xFrequency = infinite ? 0.071 : 0.031;
    const double zFrequency = infinite ? 0.053 : 0.027;
    const double xAmplitude = infinite ? 4.0 : 18.0;
    const double zAmplitude = infinite ? 3.2 : 14.0;
    const double xPhase = sampleTime * xFrequency + motion.pathPhases[0];
    const double zPhase = sampleTime * zFrequency + motion.pathPhases[1];
    std::array<double, 3> velocity{};
    velocity[0] = (infinite ? 1.15 : 3.20) + xAmplitude * (xFrequency * std::cos(xPhase) * amplitude + std::sin(xPhase) * amplitudeRate);
    velocity[2] = (infinite ? 0.82 : 2.15) + zAmplitude * (-zFrequency * std::sin(zPhase) * amplitude + std::cos(zPhase) * amplitudeRate);
    double height;
    double heightVelocity;
    if (infinite) {
        const double distancePhase = sampleTime * 0.17 + 0.8 + motion.pathPhases[3];
        const double sidePhase = sampleTime * 0.115 + 0.65 + motion.pathPhases[2];
        const double distance = 7.5 + 4.5 * std::sin(distancePhase);
        const double distanceRate = 0.765 * std::cos(distancePhase);
        const double side = std::sin(sidePhase);
        const double sideRate = 0.115 * std::cos(sidePhase);
        height = distance * side;
        heightVelocity = distanceRate * side + distance * sideRate;
    } else {
        const double phase = sampleTime * 0.087 + 0.6 + motion.phases[3];
        const double phaseRate = 0.087 + (transitionTo.phases[3] - transitionFrom.phases[3]) * first;
        height = 12.5 + 5.5 * std::sin(phase);
        heightVelocity = 5.5 * std::cos(phase) * phaseRate;
    }
    velocity[1] = heightVelocity * heightScale + height * heightRate;
    return velocity;
}

std::array<double, 3> Simulation::NativeViewMotion(double sampleTime, double height, double heightVelocity) const {
    const double progress = std::clamp((elapsed - transitionStart) / transitionDuration, 0.0, 1.0);
    const double first = 30.0 * progress * progress * (progress - 1.0) * (progress - 1.0) / transitionDuration;
    const MotionParameters& motion = state.motion;
    const double amplitude = motion.camera[0];
    const double amplitudeRate = (transitionTo.camera[0] - transitionFrom.camera[0]) * first;
    if (funnelEffect == EffectKind::InfiniteSurface) {
        const double yawPhase = sampleTime * 0.047 + motion.pathPhases[1];
        const double yawRate = 0.13 + 0.70 * (0.047 * std::cos(yawPhase) * amplitude + std::sin(yawPhase) * amplitudeRate);
        const double viewPhase = sampleTime * 0.23 + 2.0 + motion.phases[1];
        const double phaseRate = 0.23 + (transitionTo.phases[1] - transitionFrom.phases[1]) * first;
        const double viewAmount = 0.56 + 0.44 * std::sin(viewPhase);
        const double viewRate = 0.44 * std::cos(viewPhase) * phaseRate;
        const double towardSurface = std::clamp(-height / 7.0, -1.35, 1.35);
        const double towardRate = std::abs(height / 7.0) < 1.35 ? -heightVelocity / 7.0 : 0.0;
        const double tangent = towardSurface * viewAmount;
        const double tangentRate = towardRate * viewAmount + towardSurface * viewRate;
        return std::array<double, 3>{ yawRate, std::atan(tangent), tangentRate / (1.0 + tangent * tangent) };
    }
    const double xPhase = sampleTime * 0.031 + motion.pathPhases[0];
    const double zPhase = sampleTime * 0.027 + motion.pathPhases[1];
    const double velocityX = 3.20 + 0.558 * std::cos(xPhase) * amplitude;
    const double velocityZ = 2.15 - 0.378 * std::sin(zPhase) * amplitude;
    const double velocityXRate = 0.558 * (-0.031 * std::sin(xPhase) * amplitude + std::cos(xPhase) * amplitudeRate);
    const double velocityZRate = -0.378 * (0.027 * std::cos(zPhase) * amplitude + std::sin(zPhase) * amplitudeRate);
    const double headingRate = (velocityX * velocityZRate - velocityZ * velocityXRate)
        / (velocityX * velocityX + velocityZ * velocityZ);
    const double trackingPhase = sampleTime * 0.079 + 1.7 + motion.pathPhases[2];
    const double distance = (28.0 + 16.0 * std::sin(trackingPhase)) * motion.camera[3];
    const double distanceRate = 1.264 * std::cos(trackingPhase) * motion.camera[3]
        + (28.0 + 16.0 * std::sin(trackingPhase)) * (transitionTo.camera[3] - transitionFrom.camera[3]) * first;
    const double lateralPhase = sampleTime * 0.041 + 0.9 + motion.pathPhases[3];
    const double lateral = 7.0 * std::sin(lateralPhase) * amplitude;
    const double lateralRate = 0.287 * std::cos(lateralPhase) * amplitude + 7.0 * std::sin(lateralPhase) * amplitudeRate;
    const double squaredLength = distance * distance + lateral * lateral;
    const double length = std::sqrt(squaredLength);
    const double lengthRate = (distance * distanceRate + lateral * lateralRate) / length;
    const double yawRate = headingRate + (distance * lateralRate - lateral * distanceRate) / squaredLength;
    const double pitch = std::atan2(-height, length);
    const double pitchRate = (height * lengthRate - length * heightVelocity) / (squaredLength + height * height);
    return std::array<double, 3>{ yawRate, pitch, pitchRate };
}

std::array<double, 3> Simulation::FunnelRadialMotion(double pathTime) const {
    constexpr double relaxation = 0.75;
    const double offsetX = static_cast<double>(state.funnelCapture[0]) - state.funnelMotion[2];
    const double offsetZ = static_cast<double>(state.funnelCapture[2]) - state.funnelMotion[3];
    const double initialRadius = std::hypot(offsetX, offsetZ);
    const double decay = std::exp(-pathTime / relaxation);
    const double ramp = pathTime - relaxation * (1.0 - decay);
    const double distance = 0.5 * pathTime * pathTime - relaxation * pathTime + relaxation * relaxation * (1.0 - decay);
    const double plunge = std::max(0.0, pathTime - state.funnelMotion[1]);
    const double radius = initialRadius - state.funnelPath[0] * pathTime - state.funnelPath[1] * distance
        - 0.03 * plunge * plunge * plunge * plunge;
    const double velocity = state.funnelPath[0] + state.funnelPath[1] * ramp + 0.12 * plunge * plunge * plunge;
    const double acceleration = state.funnelPath[1] * (1.0 - decay) + 0.36 * plunge * plunge;
    return std::array<double, 3>{ radius, velocity, acceleration };
}

void Simulation::ResetFunnel(bool entering) {
    double captureStart = CryptographicFunnelRandom(6.0f, 8.0f);
    const float approach = CryptographicFunnelRandom(42.0f, 48.0f);
    funnelStart = elapsed - funnelElapsed;
    const double cycleStart = timeOrigin + funnelStart;
    if (funnelEffect == EffectKind::InfiniteSurface) {
        constexpr double twoPi = 6.28318530717958647692;
        const double safeStart = std::asin(0.35);
        const double safeEnd = twoPi * 0.5 - safeStart - 8.0 * 0.115;
        double phase = std::fmod((cycleStart + captureStart) * 0.115 + 0.65 + state.motion.pathPhases[2], twoPi);
        if (phase < 0.0) {
            phase += twoPi;
        }
        if (phase < safeStart || phase > safeEnd) {
            double shift = safeStart - phase;
            if (shift < 0.0) {
                shift += twoPi;
            }
            captureStart += shift / 0.115;
        }
    }
    funnelDuration = captureStart + approach + 6.9;
    state.funnelMotion = std::array<float, 4>{ 0.0f, approach, 0.0f, 0.0f };
    state.funnelCycle = std::array<float, 4>{
        static_cast<float>(cycleStart),
        static_cast<float>(funnelDuration),
        1.0f,
        static_cast<float>(captureStart)
    };
    state.funnelCapture = std::array<float, 4>{};
    state.funnelView = std::array<float, 4>{};
    state.funnelPath = std::array<float, 4>{ 0.0f, 0.0f, 0.0f, 3.0f };
    state.funnelGrid = std::array<float, 4>{
        state.motion.camera[0],
        state.motion.pathPhases[0],
        state.motion.pathPhases[1],
        0.0f
    };
    state.funnelHeading = 0.0f;
    state.funnelEntry = entering;
    funnelCaptured = false;
}

/// Freezes the unmodified free-flight camera at capture and solves its crossing of the finite mesh rim.
void Simulation::PrepareFunnelCapture() {
    if (funnelCaptured || funnelElapsed < state.funnelCycle[3]) {
        return;
    }
    const double captureTime = static_cast<double>(state.funnelCycle[0]) + state.funnelCycle[3];
    const std::array<double, 3> position = NativeCameraPosition(captureTime);
    const MotionParameters& motion = state.motion;
    if (funnelEffect == EffectKind::InfiniteSurface) {
        state.funnelHeading = static_cast<float>(captureTime * 0.13
            + 0.70 * std::sin(captureTime * 0.047 + motion.pathPhases[1]) * motion.camera[0] + motion.pathPhases[2]);
    } else {
        const double velocityX = 3.20 + 0.558 * std::cos(captureTime * 0.031 + motion.pathPhases[0]) * motion.camera[0];
        const double velocityZ = 2.15 - 0.378 * std::sin(captureTime * 0.027 + motion.pathPhases[1]) * motion.camera[0];
        const double length = std::hypot(velocityX, velocityZ);
        const double headingX = velocityX / length;
        const double headingZ = velocityZ / length;
        const double trackingPhase = 0.5 + 0.5 * std::sin(captureTime * 0.079 + 1.7 + motion.pathPhases[2]);
        const double trackingDistance = (12.0 + 32.0 * trackingPhase) * motion.camera[3];
        const double lateral = 7.0 * std::sin(captureTime * 0.041 + 0.9 + motion.pathPhases[3]) * motion.camera[0];
        const double targetX = headingX * trackingDistance - headingZ * lateral;
        const double targetZ = headingZ * trackingDistance + headingX * lateral;
        state.funnelHeading = static_cast<float>(std::atan2(targetZ, targetX));
    }
    state.funnelCapture = std::array<float, 4>{
        static_cast<float>(position[0]),
        static_cast<float>(position[1]),
        static_cast<float>(position[2]),
        0.0f
    };
    const std::array<double, 3> nativeVelocity = NativeCameraVelocity(captureTime);
    const std::array<float, 3> capturedVelocity{
        static_cast<float>(nativeVelocity[0]),
        static_cast<float>(nativeVelocity[1]),
        static_cast<float>(nativeVelocity[2])
    };
    const std::array<double, 3> view = NativeViewMotion(captureTime, state.funnelCapture[1], capturedVelocity[1]);
    state.funnelView = std::array<float, 4>{
        static_cast<float>(view[0]),
        static_cast<float>(view[1]),
        static_cast<float>(view[2]),
        0.0f
    };
    const double sampledRadius = CryptographicFunnelRandom(60.0f, 80.0f);
    const double sampledCoefficient = 18.84955592153876 / std::log(sampledRadius / 11.25);
    const double direction = state.funnelView[0] < 0.0f ? -1.0 : 1.0;
    const double velocityX = capturedVelocity[0];
    const double velocityZ = capturedVelocity[2];
    const double horizontalSpeed = std::hypot(velocityX, velocityZ);
    const double factor = sampledRadius / (horizontalSpeed * std::sqrt(1.0 + sampledCoefficient * sampledCoefficient));
    state.funnelMotion[2] =
        static_cast<float>(state.funnelCapture[0] + factor * (velocityX - direction * sampledCoefficient * velocityZ));
    state.funnelMotion[3] =
        static_cast<float>(state.funnelCapture[2] + factor * (velocityZ + direction * sampledCoefficient * velocityX));
    state.funnelCycle[2] = static_cast<float>(direction);
    const double offsetX = static_cast<double>(state.funnelCapture[0]) - state.funnelMotion[2];
    const double offsetZ = static_cast<double>(state.funnelCapture[2]) - state.funnelMotion[3];
    const double radius = std::hypot(offsetX, offsetZ);
    const double coefficient = 18.84955592153876 / std::log(radius / 11.25);
    const double radialSpeed = horizontalSpeed / std::sqrt(1.0 + coefficient * coefficient);
    constexpr double relaxation = 0.75;
    const double duration = state.funnelMotion[1];
    const double distance = 0.5 * duration * duration - relaxation * duration
        + relaxation * relaxation * (1.0 - std::exp(-duration / relaxation));
    const double radialAcceleration = (radius - 11.25 - radialSpeed * duration) / distance;
    const double denominator = radius * radius + 0.00390625;
    const double slope = 7125.0 * radius / (denominator * denominator);
    const double heightDelta = capturedVelocity[1] + slope * radialSpeed;
    const double heightRelaxation =
        heightDelta < 0.0 ? std::min(3.0, state.funnelCapture[1] / (-4.0 * heightDelta)) : 3.0;
    state.funnelPath = std::array<float, 4>{
        static_cast<float>(radialSpeed),
        static_cast<float>(radialAcceleration),
        static_cast<float>(heightDelta),
        static_cast<float>(heightRelaxation)
    };
    const double verticalOffset = state.funnelCapture[1] + 3562.5 / denominator;
    const double rimHeight = -3562.5 / (6.0 * 6.0 + 0.00390625);
    double lower = 0.0;
    double upper = 4.0;
    for (unsigned iteration = 0; iteration < 24; iteration++) {
        const double time = (lower + upper) * 0.5;
        const double orbitTime = duration + time;
        const double orbitRadius = FunnelRadialMotion(orbitTime)[0];
        const double height = verticalOffset - 3562.5 / (orbitRadius * orbitRadius + 0.00390625)
            + state.funnelPath[2] * (2.0 * state.funnelPath[3]
            - (orbitTime + 2.0 * state.funnelPath[3]) * std::exp(-orbitTime / state.funnelPath[3]));
        if (orbitRadius <= 0.0 || height <= rimHeight) {
            upper = time;
        } else {
            lower = time;
        }
    }
    const double exitTime = (lower + upper) * 0.5;
    state.funnelCapture[3] = static_cast<float>(exitTime);
    funnelDuration = state.funnelCycle[3] + state.funnelMotion[1] + exitTime + 2.9;
    state.funnelCycle[1] = static_cast<float>(funnelDuration);
    funnelCaptured = true;
}

void Simulation::UpdateFunnel(double seconds, SurfaceShape shape) {
    if (shape == SurfaceShape::Funnel) {
        if (state.surfaceShape != shape) {
            funnelElapsed = 0.0;
            ResetFunnel(false);
        }
        funnelElapsed += seconds;
        while (true) {
            PrepareFunnelCapture();
            if (funnelElapsed < funnelDuration) {
                break;
            }
            funnelElapsed -= funnelDuration;
            ResetFunnel(true);
        }
        state.funnelMotion[0] = std::min(static_cast<float>(funnelElapsed / funnelDuration), std::nextafter(1.0f, 0.0f));
        state.funnelView[3] =
            funnelCaptured ? static_cast<float>(std::max(0.0, funnelElapsed - state.funnelCycle[3])) : 0.0f;
    }
    state.surfaceShape = shape;
}

void Simulation::SetSurfaceShape(SurfaceShape shape, EffectKind effect) {
    if (state.surfaceShape != shape) {
        surfaceActivationStart = elapsed;
        state.surfaceActivation = shape == SurfaceShape::Funnel ? 1.0f : 0.0f;
    }
    const bool restart = shape == SurfaceShape::Funnel && state.surfaceShape == shape && funnelEffect != effect;
    funnelEffect = effect;
    if (restart) {
        funnelElapsed = 0.0;
        ResetFunnel(false);
    }
    UpdateFunnel(0.0, shape);
}

/// Restarts with fresh cryptographic entropy even when multiple monitors supply the same seed.
void Simulation::Reset(unsigned initialSeed) {
    randomBufferPosition = randomBuffer.size();
    funnelRandomBufferPosition = randomBuffer.size();
    const std::uint32_t origin = NextCryptographicRandom() ^ initialSeed * 1009U;
    constexpr double inverseRange = 1.0 / 4294967296.0;
    timeOrigin = static_cast<double>(origin) * inverseRange * 512.0;
    elapsed = 0.0;
    surfaceActivationStart = 0.0;
    funnelStart = 0.0;
    funnelElapsed = 0.0;
    funnelEffect = EffectKind::InfiniteSurface;
    funnelCaptured = false;
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
}

/// Retains the original monitor-paced flight speed while advancing independent scene variations.
void Simulation::Step(double seconds, float speed, std::uint32_t selectedEffects, bool cameraTumbling,
        bool cameraReversals) {
    if (state.surfaceShape != SurfaceShape::Funnel || seconds * speed <= 0.0) {
        elapsed += seconds * speed;
        state.animationTime = static_cast<float>(timeOrigin + elapsed);
        state.enabledEffects = selectedEffects & ALL_EFFECT_MASK;
        UpdateMotionParameters();
        if (state.surfaceShape == SurfaceShape::Waves && state.surfaceActivation < 1.0f) {
            state.surfaceActivation = static_cast<float>(MotionEase((elapsed - surfaceActivationStart) / 4.0));
        }
        UpdateCameraRotation(seconds * speed, cameraTumbling, cameraReversals);
        UpdateFunnel(seconds * speed, state.surfaceShape);
        return;
    }
    state.enabledEffects = selectedEffects & ALL_EFFECT_MASK;
    double remaining = seconds * speed;
    while (remaining > 0.0) {
        const double boundary = funnelCaptured ? funnelDuration : state.funnelCycle[3];
        const double untilBoundary = std::max(0.0, boundary - funnelElapsed);
        const bool reachedBoundary = remaining >= untilBoundary;
        const double step = reachedBoundary ? untilBoundary : remaining;
        if (reachedBoundary) {
            elapsed = funnelStart + boundary;
            funnelElapsed = boundary;
        } else {
            elapsed += step;
            funnelElapsed += step;
        }
        state.animationTime = static_cast<float>(timeOrigin + elapsed);
        UpdateMotionParameters();
        UpdateCameraRotation(step, cameraTumbling, cameraReversals);
        UpdateFunnel(0.0, state.surfaceShape);
        remaining -= step;
    }
}

/// Returns the immutable frame snapshot for this monitor only.
const SceneState& Simulation::State() const {
    return state;
}
