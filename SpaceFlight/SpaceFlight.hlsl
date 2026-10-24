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

/// Per-frame camera, lighting and scene parameters shared with the CPU renderer.
cbuffer FrameConstants : register(b0) {
    float2 resolution;
    float time;
    uint surfaceShape;
    float4 animationPhases;
    float4 surfaceVariations;
    float4 cameraVariations;
    float4 pathPhases;
    float4 cameraRotation;
    float4 lightSettings;
    float4 funnelMotion;
    float4 funnelCycle;
    float4 funnelCapture;
    uint funnelEntry;
    float surfaceActivation;
    float funnelHeading;
    float4 funnelGrid;
    float4 funnelView;
    float4 funnelPath;
};

/// Effect identity and procedural surface mesh dimensions for the current draw call.
cbuffer EffectConstants : register(b1) {
    uint effect;
    uint surfaceColumns;
    uint surfaceRows;
    uint surfacePatches;
};

/// Projected position and color passed from the wireframe vertex shader to the pixel shader.
struct VSOutput {
    float4 position : SV_POSITION;
    float4 color : COLOR0;
};

/// Projected and view-space surface data used for lighting and funnel clipping.
struct SolidSurfaceOutput {
    float4 position : SV_POSITION;
    centroid float3 viewPosition : TEXCOORD0;
    centroid float3 normal : TEXCOORD1;
    centroid float4 material : COLOR0;
    float2 funnelLocal : TEXCOORD2;
};

static const float FUNNEL_NECK_VISIBILITY_DEPTH = 24.0;
static const float FUNNEL_DEPTH_FACTOR = 3562.5;
static const float FUNNEL_CENTER_SQUARED = 0.00390625;
static const float FUNNEL_FAR_PLANE = 32768.0;
static const float FUNNEL_CUTOFF_RADIUS = 6.0;
static const float FUNNEL_ENTRY_RADIUS = 11.25;
static const float FUNNEL_FORMATION_DURATION = 12.0;
static const float FUNNEL_RIM_FADE_DURATION = 2.0;
static const float FUNNEL_VIEW_PITCH_RELAXATION = 4.0;
static const float FUNNEL_TILT_RATE = 0.4;
static const float FUNNEL_TILT_DELAY = 0.75;
static const uint FUNNEL_CIRCLE_SEGMENTS = 128;

/// Interpolates deformation progress with zero velocity and acceleration at both endpoints.
float SurfaceEase(float progress) {
    progress = saturate(progress);
    return progress * progress * progress * (progress * (progress * 6.0 - 15.0) + 10.0);
}

/// Returns the eased depth progression after the current cycle's capture begins.
float FunnelFormation() {
    float elapsed = funnelMotion.x * funnelCycle.y;
    return SurfaceEase((elapsed - funnelCycle.w) / FUNNEL_FORMATION_DURATION);
}

/// Applies the inverse unit-quaternion camera rotation; identity preserves the original view.
float3 TumblingView(float3 view) {
    float3 axis = -cameraRotation.xyz;
    float3 turn = 2.0 * cross(axis, view);
    return view + cameraRotation.w * turn + cross(axis, turn);
}

/// Spreads grid offsets progressively farther from the camera.
float InfiniteGridOffset(float index) {
    float direction = index < 0 ? -1.0 : 1.0;
    float distance = abs((float) index);
    return direction * (1.5 * distance + 0.045 * distance * distance);
}

/// Blends grid coordinates between adjacent camera cells.
float InfiniteGridCoordinate(float cameraCoordinate, float index) {
    static const float spacing = 1.5;
    float cameraCell = cameraCoordinate / spacing;
    float baseCell = floor(cameraCell);
    float blend = smoothstep(0.0, 1.0, frac(cameraCell));
    float currentCoordinate = baseCell * spacing + InfiniteGridOffset(index);
    float nextCoordinate = (baseCell + 1.0) * spacing + InfiniteGridOffset(index - 1);
    return lerp(currentCoordinate, nextCoordinate, blend);
}

/// Retains the original infinite-surface grid anchor from the beginning of the current funnel cycle.
float2 FunnelGridAnchor() {
    return float2(funnelCycle.x * 1.15 + 4.0 * sin(funnelCycle.x * 0.071 + funnelGrid.y) * funnelGrid.x,
        funnelCycle.x * 0.82 + 3.2 * cos(funnelCycle.x * 0.053 + funnelGrid.z) * funnelGrid.x);
}

/// Finds the material-grid index immediately below a world coordinate at the frozen anchor.
float FrozenGridFloor(float anchor, float coordinate) {
    float distance = coordinate - InfiniteGridCoordinate(anchor, 0.0);
    float radius = abs(distance);
    float estimate = 2.0 * radius / (1.5 + sqrt(2.25 + 0.18 * radius));
    float index = floor(distance < 0.0 ? -estimate : estimate);
    if (InfiniteGridCoordinate(anchor, index) > coordinate) {
        index -= 1.0;
    }
    if (InfiniteGridCoordinate(anchor, index + 1.0) <= coordinate) {
        index += 1.0;
    }
    return index;
}

/// Recycles the visible grid window using fixed material coordinates while the camera moves.
float FrozenGridCoordinate(float anchor, float cameraCoordinate, float index) {
    float extent = min(160.0, min(anchor - InfiniteGridCoordinate(anchor, -46.0),
        InfiniteGridCoordinate(anchor, 46.0) - anchor));
    float upperCoordinate = cameraCoordinate + extent;
    float upperIndex = FrozenGridFloor(anchor, upperCoordinate);
    if (InfiniteGridCoordinate(anchor, upperIndex) < upperCoordinate) {
        upperIndex += 1.0;
    }
    float lowerIndex = FrozenGridFloor(anchor, cameraCoordinate - extent);
    float window = clamp(0.0, upperIndex - 46.0, lowerIndex + 46.0);
    return InfiniteGridCoordinate(anchor, index + window);
}

/// Returns the fully formed funnel height at the supplied radial distance.
float FunnelHeight(float radius) {
    return -FUNNEL_DEPTH_FACTOR / (radius * radius + FUNNEL_CENTER_SQUARED);
}

/// Returns the radial derivative of the fully formed funnel height.
float FunnelSlope(float radius) {
    float denominator = radius * radius + FUNNEL_CENTER_SQUARED;
    return 2.0 * FUNNEL_DEPTH_FACTOR * radius / (denominator * denominator);
}

/// Returns the depth of the circle where the square mesh ends.
float FunnelRimDepth() {
    return -FunnelHeight(FUNNEL_CUTOFF_RADIUS);
}

/// Returns the mesh cutoff radius scaled by the current funnel formation.
float FunnelCutRadius() {
    return FUNNEL_CUTOFF_RADIUS * sqrt(FunnelFormation());
}

/// Deforms the original plane continuously and clamps the square mesh at the funnel rim.
float FunnelDeformedHeight(float radius) {
    float formation = FunnelFormation();
    float depth = FunnelRimDepth();
    float strength = formation * (formation * FUNNEL_DEPTH_FACTOR + (1.0 - formation) * depth
        * FUNNEL_CENTER_SQUARED);
    return max(-formation * depth, -strength / (radius * radius + FUNNEL_CENTER_SQUARED));
}

/// Fades out the surface mesh immediately after the camera crosses its terminal rim.
float FunnelBodyVisibility() {
    float plungeTime = funnelView.w - funnelMotion.y;
    return 1.0 - smoothstep(funnelCapture.w, funnelCapture.w + 0.08, plungeTime);
}

/// Maps a world-plane coordinate to its currently deformed funnel surface position.
float3 FunnelSurface(float2 position) {
    float2 local = position - funnelMotion.zw;
    return float3(position.x, FunnelDeformedHeight(length(local)), position.y);
}

/// Clips a grid segment at the cutoff circle and rejects segments lying entirely inside it.
bool FunnelClipSegment(inout float2 first, inout float2 second) {
    float radius = FunnelCutRadius();
    float squaredRadius = radius * radius;
    bool firstInside = dot(first, first) < squaredRadius;
    bool secondInside = dot(second, second) < squaredRadius;
    if (firstInside != secondInside) {
        float2 outer = firstInside ? second : first;
        float2 inner = firstInside ? first : second;
        float2 delta = inner - outer;
        float a = dot(delta, delta);
        float b = dot(outer, delta);
        float c = dot(outer, outer) - squaredRadius;
        float amount = (-b - sqrt(max(0.0, b * b - a * c))) / a;
        float2 intersection = outer + delta * saturate(amount);
        if (firstInside) {
            first = intersection;
        } else {
            second = intersection;
        }
    }
    return !firstInside || !secondInside;
}

/// Evaluates radius, inward speed and acceleration along the accelerating approach and plunge.
float3 FunnelApproachMotion(float initialRadius, float orbitTime) {
    float decay = exp(-orbitTime / 0.75);
    float distance = 0.5 * orbitTime * orbitTime - 0.75 * orbitTime + 0.5625 * (1.0 - decay);
    float rate = orbitTime - 0.75 * (1.0 - decay);
    float plungeTime = max(0.0, orbitTime - funnelMotion.y);
    float squared = plungeTime * plungeTime;
    float radius = initialRadius - funnelPath.x * orbitTime - funnelPath.y * distance - 0.03 * squared * squared;
    float inwardSpeed = funnelPath.x + funnelPath.y * rate + 0.12 * squared * plungeTime;
    float acceleration = funnelPath.y * (1.0 - decay) + 0.36 * squared;
    return float3(radius, inwardSpeed, acceleration);
}

/// Continues radial motion smoothly from the finite funnel body into the trailing circles.
float3 FunnelRadialMotion(float initialRadius, float orbitTime) {
    float exitTime = funnelMotion.y + funnelCapture.w;
    float3 motion;
    if (orbitTime <= exitTime) {
        motion = FunnelApproachMotion(initialRadius, orbitTime);
    } else {
        float3 exitMotion = FunnelApproachMotion(initialRadius, exitTime);
        float circlesTime = orbitTime - exitTime;
        float initialRate = exitMotion.y / exitMotion.x;
        float curvature = exitMotion.z / exitMotion.x + initialRate * initialRate;
        float exponent = initialRate * circlesTime + 0.5 * curvature * circlesTime * circlesTime;
        float rate = initialRate + curvature * circlesTime;
        float radius = exitMotion.x * exp(-exponent);
        motion = float3(radius, radius * rate, radius * (curvature - rate * rate));
    }
    return motion;
}

/// Evaluates altitude, downward speed and acceleration while preserving the initial vertical velocity.
float3 FunnelVerticalMotion(float initialRadius, float orbitTime, float3 radial) {
    float decay = exp(-orbitTime / funnelPath.w);
    float denominator = radial.x * radial.x + FUNNEL_CENTER_SQUARED;
    float curvature = 2.0 * FUNNEL_DEPTH_FACTOR * (FUNNEL_CENTER_SQUARED - 3.0 * radial.x * radial.x)
        / (denominator * denominator * denominator);
    float slope = FunnelSlope(radial.x);
    float altitude = funnelCapture.y + FunnelHeight(radial.x) - FunnelHeight(initialRadius)
        + funnelPath.z * (2.0 * funnelPath.w - (orbitTime + 2.0 * funnelPath.w) * decay);
    float downwardSpeed = slope * radial.y - funnelPath.z * (1.0 + orbitTime / funnelPath.w) * decay;
    float acceleration = slope * radial.z - curvature * radial.y * radial.y
        + funnelPath.z * orbitTime * decay / (funnelPath.w * funnelPath.w);
    return float3(altitude, downwardSpeed, acceleration);
}

/// Returns downward speed and acceleration at the terminal rim for the following circle flight.
float2 FunnelExitMotion(float3 capturePosition) {
    float initialRadius = length(capturePosition.xz - funnelMotion.zw);
    float exitTime = funnelMotion.y + funnelCapture.w;
    float3 radial = FunnelApproachMotion(initialRadius, exitTime);
    return FunnelVerticalMotion(initialRadius, exitTime, radial).yz;
}

/// Returns the spiral coefficient that completes three turns before the final plunge.
float FunnelOrbitCoefficient(float initialRadius) {
    return 18.84955592153876 / log(initialRadius / FUNNEL_ENTRY_RADIUS);
}

/// Returns radius, inward speed, accumulated orbit angle and angular speed.
float4 FunnelOrbitMotion(float initialRadius, float orbitTime) {
    float coefficient = FunnelOrbitCoefficient(initialRadius);
    float3 radial = FunnelRadialMotion(initialRadius, orbitTime);
    float angle = coefficient * log(initialRadius / radial.x);
    float angularSpeed = coefficient * radial.y / radial.x;
    return float4(radial.x, radial.y, angle, angularSpeed);
}

/// Continues the native camera trajectory into the accelerating spiral and the trailing circle flight.
float3 FunnelCamera(float3 camera, out float3 velocity) {
    float orbitTime = funnelView.w;
    velocity = 0.0;
    if (!(orbitTime <= 0.0)) {
        float3 capturePosition = funnelCapture.xyz;
        float2 offset = capturePosition.xz - funnelMotion.zw;
        float initialRadius = length(offset);
        float4 orbit = FunnelOrbitMotion(initialRadius, orbitTime);
        float3 radialMotion = FunnelRadialMotion(initialRadius, orbitTime);
        float3 vertical = FunnelVerticalMotion(initialRadius, orbitTime, radialMotion);
        float circlesTime = orbitTime - funnelMotion.y - funnelCapture.w;
        if (circlesTime > 0.0) {
            float2 exitMotion = FunnelExitMotion(capturePosition);
            float denominator = 1.0 + circlesTime / 0.5;
            vertical.x = -FunnelRimDepth() - exitMotion.x * circlesTime
                - 0.5 * exitMotion.y * circlesTime * circlesTime / denominator;
            vertical.y = exitMotion.x
                + 0.5 * exitMotion.y * circlesTime * (denominator + 1.0) / (denominator * denominator);
        }
        float angle = atan2(offset.y, offset.x) + funnelCycle.z * orbit.z;
        float2 radial = float2(cos(angle), sin(angle));
        float2 tangent = float2(-radial.y, radial.x);
        float2 horizontalVelocity = -radial * orbit.y + tangent * (funnelCycle.z * orbit.x * orbit.w);
        velocity = float3(horizontalVelocity.x, -vertical.y, horizontalVelocity.y);
        camera = float3(funnelMotion.z + radial.x * orbit.x, vertical.x, funnelMotion.w + radial.y * orbit.x);
    }
    return camera;
}

/// Preserves initial viewing rates while accelerating the orbit and gradually tilting into the funnel.
float3 FunnelView(float3 forward) {
    float orbitTime = funnelView.w;
    if (!(orbitTime <= 0.0)) {
        float2 offset = funnelCapture.xz - funnelMotion.zw;
        float initialRadius = length(offset);
        float4 orbit = FunnelOrbitMotion(initialRadius, orbitTime);
        float initialAngularRate = FunnelOrbitCoefficient(initialRadius) * funnelPath.x / initialRadius;
        float yaw = funnelHeading + funnelView.x * orbitTime + funnelCycle.z
            * (orbit.z - initialAngularRate * orbitTime);
        float initialTilt = exp(-FUNNEL_TILT_RATE * (funnelMotion.y + FUNNEL_TILT_DELAY));
        float initialTargetPitch = -atan(initialTilt);
        float initialPitchRate = -FUNNEL_TILT_RATE * initialTilt / (1.0 + initialTilt * initialTilt);
        float pitchError = funnelView.y - initialTargetPitch;
        float pitchRateError = funnelView.z - initialPitchRate;
        float pitchRelaxation = FUNNEL_VIEW_PITCH_RELAXATION;
        if (pitchRateError > 0.0) {
            pitchRelaxation = min(pitchRelaxation, -pitchError / pitchRateError);
        }
        float tiltTime = orbitTime - funnelMotion.y - FUNNEL_TILT_DELAY;
        float targetPitch = -atan(exp(FUNNEL_TILT_RATE * tiltTime));
        float pitch = targetPitch + (pitchError + (pitchRateError + pitchError / pitchRelaxation) * orbitTime)
            * exp(-orbitTime / pitchRelaxation);
        forward = float3(cos(yaw) * cos(pitch), sin(pitch), sin(yaw) * cos(pitch));
    }
    return forward;
}

/// Rotates the returning plane into view gradually at the beginning of a subsequent cycle.
float3 FunnelEntryView(float3 view, float3 planeNormal, float side) {
    if (funnelEntry != 0) {
        float elapsed = funnelMotion.x * funnelCycle.y;
        float amount = 1.0 - smoothstep(0.0, 3.0, elapsed);
        if (amount != 0.0) {
            float3 facing = planeNormal * side;
            float cosine = clamp(facing.z, -1.0, 1.0);
            float3 axis = cross(facing, float3(0.0, 0.0, 1.0));
            float axisLength = length(axis);
            if (!(axisLength < 0.00001 && cosine >= 0.0)) {
                if (axisLength < 0.00001) {
                    axis = float3(1.0, 0.0, 0.0);
                } else {
                    axis /= axisLength;
                }
                float angle = acos(cosine) * amount;
                float sine, turnCosine;
                sincos(angle, sine, turnCosine);
                view = view * turnCosine + cross(axis, view) * sine + axis * dot(axis, view)
                    * (1.0 - turnCosine);
            }
        }
    }
    return view;
}

/// Combines the next-cycle fade-in with the funnel body's exit fade-out.
float FunnelVisibility() {
    float elapsed = funnelMotion.x * funnelCycle.y;
    float entryFade = funnelEntry != 0 ? smoothstep(0.0, 2.0, elapsed) : 1.0;
    return entryFade * FunnelBodyVisibility();
}

/// Evaluates the original horizontal camera position for the infinite-surface flight.
float2 InfiniteCameraXZ(float sampleTime) {
    return float2(sampleTime * 1.15 + 4.0 * sin(sampleTime * 0.071 + pathPhases.x) * cameraVariations.x,
        sampleTime * 0.82 + 3.2 * cos(sampleTime * 0.053 + pathPhases.y) * cameraVariations.x);
}

/// Evaluates the original camera height, including passage above and below the infinite surface.
float InfiniteCameraHeight(float sampleTime) {
    float sidePhase = sin(sampleTime * 0.115 + 0.65 + pathPhases.z);
    float distancePhase = 0.5 + 0.5 * sin(sampleTime * 0.17 + 0.8 + pathPhases.w);
    return lerp(3.0, 12.0, distancePhase) * sidePhase * cameraVariations.y;
}

/// Evaluates the original horizontal camera position for the long-distance surface flight.
float2 MorphingCameraXZ(float sampleTime) {
    return float2(sampleTime * 3.20 + 18.0 * sin(sampleTime * 0.031 + pathPhases.x) * cameraVariations.x,
        sampleTime * 2.15 + 14.0 * cos(sampleTime * 0.027 + pathPhases.y) * cameraVariations.x);
}

/// Evaluates the original camera altitude above the morphing surface.
float MorphingCameraHeight(float sampleTime) {
    float altitudePhase = 0.5 + 0.5 * sin(sampleTime * 0.087 + 0.6 + animationPhases.w);
    return lerp(7.0, 18.0, altitudePhase) * cameraVariations.y;
}

/// Positions a segment endpoint on the mesh rim or the next standalone circle after it.
float3 FunnelCirclePoint(uint circle, uint segment, uint endpoint, out float visibility) {
    float elapsed = funnelMotion.x * funnelCycle.y;
    float plungeTime = funnelView.w - funnelMotion.y;
    float radius = FunnelCutRadius();
    float depth = FunnelRimDepth();
    if (circle == 0) {
        float formationEnd = funnelCycle.w + FUNNEL_FORMATION_DURATION;
        visibility = SurfaceEase((elapsed - formationEnd) / FUNNEL_RIM_FADE_DURATION) * FunnelBodyVisibility();
    } else {
        visibility = smoothstep(funnelCapture.w - 0.04, funnelCapture.w + 0.02, plungeTime)
            * (1.0 - smoothstep(funnelCapture.w + 2.05, funnelCapture.w + 2.2, plungeTime));
        if (visibility > 0.0) {
            float3 velocity;
            float3 camera = FunnelCamera(float3(0.0, 0.0, 0.0), velocity);
            float spacing = FunnelExitMotion(funnelCapture.xyz).x * 0.38;
            float next = floor(max(0.0, -camera.y - depth) / spacing) + 1.0;
            depth += next * spacing;
            radius = sqrt(max(0.0, FUNNEL_DEPTH_FACTOR / depth - FUNNEL_CENTER_SQUARED));
        }
    }
    float angle = float(segment + endpoint) * 6.283185307179586 / float(FUNNEL_CIRCLE_SEGMENTS);
    return float3(funnelMotion.z + radius * cos(angle), -depth, funnelMotion.w + radius * sin(angle));
}

/// Calculates animated wave height with smoothly varying surface curvature.
float WaveHeight(float x, float z, float2 cameraXZ) {
    float height = 0.0;
    if (surfaceShape == 2) {
        height = FunnelDeformedHeight(length(float2(x, z) - funnelMotion.zw));
    } else if (surfaceShape == 1) {
        float surfaceCycle = 0.5 + 0.5 * sin(time * 0.16 - 0.9 + animationPhases.y);
        float surfaceActivity = smoothstep(0.22, 0.72, surfaceCycle);
        float waveAmount = lerp(0.04, 1.0, surfaceActivity);
        float fineWaves = (0.75 * sin(0.38 * x + time * 0.80 + animationPhases.x) + 0.55
            * cos(0.45 * z - time * 0.62 + animationPhases.y) + 0.30
            * sin(0.22 * (x + z) + time * 0.37 + animationPhases.x)) * surfaceVariations.x;
        float2 local = (float2(x, z) - cameraXZ) * 0.025;
        float saddle = (local.x * local.x - local.y * local.y) * surfaceVariations.y;
        float dome = -(local.x * local.x + local.y * local.y) * 0.55 * surfaceVariations.z;
        float curvatureShape = 0.5 + 0.5 * sin(time * 0.071 + 1.3 + animationPhases.y);
        float broadCurvature = lerp(saddle, dome, curvatureShape);
        float curvatureCycle = 0.5 + 0.5 * sin(time * 0.11 + 2.1 + animationPhases.x);
        float curvatureAmount = surfaceActivity * smoothstep(0.48, 0.88, curvatureCycle);
        height = (waveAmount * fineWaves + 0.62 * curvatureAmount * broadCurvature) * surfaceActivation;
    }
    return height;
}

/// Anchors a uniformly spaced grid to the camera's current grid cell.
float AnchoredFlightGridCoordinate(float cameraCoordinate, float index, float spacing) {
    float gridOrigin = floor(cameraCoordinate / spacing) * spacing;
    return gridOrigin + index * spacing;
}

/// Chooses fixed world-grid coordinates for the selected surface flight.
float2 FunnelGridPoint(float2 index) {
    float2 nativeXZ = effect == 19 ? InfiniteCameraXZ(time) : MorphingCameraXZ(time);
    float height = effect == 19 ? InfiniteCameraHeight(time) : MorphingCameraHeight(time);
    float3 velocity;
    float3 camera = FunnelCamera(float3(nativeXZ.x, height, nativeXZ.y), velocity);
    float2 grid = 0.0;
    if (effect == 19) {
        float2 anchor = FunnelGridAnchor();
        grid = float2(FrozenGridCoordinate(anchor.x, camera.x, index.x),
            FrozenGridCoordinate(anchor.y, camera.z, index.y));
    } else {
        grid = float2(AnchoredFlightGridCoordinate(camera.x, index.x, 3.0),
            AnchoredFlightGridCoordinate(camera.z, index.y, 3.0));
    }
    return grid;
}

/// Returns a deformed grid endpoint after clipping its segment to the funnel rim.
float3 FunnelWireEndpoint(float2 firstIndex, float2 secondIndex, out bool visible) {
    float2 world = FunnelGridPoint(firstIndex);
    float2 first = world - funnelMotion.zw;
    float2 second = FunnelGridPoint(secondIndex) - funnelMotion.zw;
    float2 original = first;
    visible = FunnelClipSegment(first, second);
    if (!all(first == original)) {
        world = first + funnelMotion.zw;
    }
    return FunnelSurface(world);
}

/// Projects a wave-surface grid sample and computes distance fading and color variation.
float4 InfiniteSurfaceSample(float2 gridIndex, bool pointSample, bool circleSample, float3 samplePoint,
    out float fade, out float colorPhase, out float3 surfacePoint) {
    fade = 1.0;
    colorPhase = 0.0;
    surfacePoint = 0.0;
    float2 cameraXZ = float2(time * 1.15 + 4.0 * sin(time * 0.071 + pathPhases.x) * cameraVariations.x,
        time * 0.82 + 3.2 * cos(time * 0.053 + pathPhases.y) * cameraVariations.x);
    float surfaceAtCamera = surfaceShape == 2 ? 0.0 : WaveHeight(cameraXZ.x, cameraXZ.y, cameraXZ);
    float sidePhase = sin(time * 0.115 + 0.65 + pathPhases.z);
    float distancePhase = 0.5 + 0.5 * sin(time * 0.17 + 0.8 + pathPhases.w);
    float surfaceDistance = lerp(3.0, 12.0, distancePhase);
    float signedHeight = surfaceDistance * sidePhase * cameraVariations.y;
    float3 camera = float3(cameraXZ.x, surfaceAtCamera + signedHeight, cameraXZ.y);
    float3 funnelVelocity = 0.0;
    if (surfaceShape == 2) {
        camera = FunnelCamera(camera, funnelVelocity);
    }
    float x = InfiniteGridCoordinate(camera.x, gridIndex.x);
    float z = InfiniteGridCoordinate(camera.z, gridIndex.y);
    if (surfaceShape == 2) {
        float2 anchor = FunnelGridAnchor();
        x = FrozenGridCoordinate(anchor.x, camera.x, gridIndex.x);
        z = FrozenGridCoordinate(anchor.y, camera.z, gridIndex.y);
    }
    float3 world = float3(x, WaveHeight(x, z, cameraXZ), z);
    if (pointSample) {
        world = samplePoint;
    }
    surfacePoint = world;
    colorPhase = 0.5 + 0.5 * sin(time * 0.24 + x * 0.11 + z * 0.09 + animationPhases.z);
    float yaw = time * 0.13 + 0.70 * sin(time * 0.047 + pathPhases.y) * cameraVariations.x + pathPhases.z;
    float surfaceViewPhase = 0.5 + 0.5 * sin(time * 0.23 + 2.0 + animationPhases.y);
    float surfaceViewAmount = lerp(0.12, 1.0, surfaceViewPhase);
    float pitchTowardSurface = clamp(-signedHeight / 7.0, -1.35, 1.35);
    float pitch = pitchTowardSurface * surfaceViewAmount;
    float3 forward = normalize(float3(cos(yaw), pitch, sin(yaw)));
    if (surfaceShape == 2) {
        forward = FunnelView(forward);
    }
    float3 right = normalize(cross(float3(0.0, 1.0, 0.0), forward));
    float3 cameraUp = normalize(cross(forward, right));
    float roll = 0.32 * sin(time * 0.083 + animationPhases.w) * cameraVariations.z;
    float rollSine, rollCosine;
    sincos(roll, rollSine, rollCosine);
    float3 rolledRight = right * rollCosine + cameraUp * rollSine;
    float3 rolledUp = cameraUp * rollCosine - right * rollSine;
    float3 relative = world - camera;
    float3 view = float3(dot(relative, rolledRight), dot(relative, rolledUp), dot(relative, forward));
    view = TumblingView(view);
    if (surfaceShape == 2) {
        float3 planeNormal = TumblingView(float3(rolledRight.y, rolledUp.y, forward.y));
        float side = InfiniteCameraHeight(funnelCycle.x) < 0.0 ? -1.0 : 1.0;
        view = FunnelEntryView(view, planeNormal, side);
    }
    float focalLength = 1.0 / tan(0.61);
    float aspect = resolution.x / resolution.y;
    static const float nearPlane = 0.12;
    static const float farPlane = 160.0;
    float projectionFar = farPlane;
    float distantFade = smoothstep(100.0, farPlane, view.z);
    fade = lerp(1.0, 0.30, distantFade);
    if (surfaceShape == 2) {
        if (!circleSample) {
            fade *= FunnelVisibility();
        }
        if (world.y < -4.0) {
            float depth = smoothstep(4.0, FUNNEL_NECK_VISIBILITY_DEPTH, -world.y);
            projectionFar = lerp(farPlane, FUNNEL_FAR_PLANE, depth);
        }
    }
    return float4(view.x * focalLength / aspect, view.y * focalLength, view.z * projectionFar
        / (projectionFar - nearPlane) - nearPlane * projectionFar / (projectionFar - nearPlane), view.z);
}

/// Blends animated surface shapes around the deformation center.
float MorphingSurfaceHeight(float x, float z, float2 deformationCenter) {
    float height = 0.0;
    if (surfaceShape == 2) {
        height = FunnelDeformedHeight(length(float2(x, z) - funnelMotion.zw));
    } else if (surfaceShape == 1) {
        float2 local = (float2(x, z) - deformationCenter) * 0.035;
        float radius = length(local);
        float waves = (0.85 * sin(0.25 * x + time * 0.58 + animationPhases.x) + 0.60
            * cos(0.31 * z - time * 0.43 + animationPhases.y)) * surfaceVariations.x;
        float hyperbolicParaboloid = 0.72 * (local.x * local.x - local.y * local.y) * surfaceVariations.y;
        float ellipticParaboloid = 0.46 * (local.x * local.x + 0.72 * local.y * local.y) * surfaceVariations.z;
        float coneSurface = 1.35 * radius * surfaceVariations.w;
        float radialSurface = 2.8 * sin(radius * 2.4 - time * 0.72 + animationPhases.x)
            * exp(-0.10 * radius * radius) * surfaceVariations.x;
        float cycle = frac(time * 0.018 + animationPhases.y / 6.283185307179586) * 5.0;
        uint shape = (uint) floor(cycle);
        float blend = smoothstep(0.18, 0.82, frac(cycle));
        float currentShape;
        float nextShape;
        if (shape == 0) {
            currentShape = waves;
            nextShape = hyperbolicParaboloid;
        } else if (shape == 1) {
            currentShape = hyperbolicParaboloid;
            nextShape = ellipticParaboloid;
        } else if (shape == 2) {
            currentShape = ellipticParaboloid;
            nextShape = coneSurface;
        } else if (shape == 3) {
            currentShape = coneSurface;
            nextShape = radialSurface;
        } else {
            currentShape = radialSurface;
            nextShape = waves;
        }
        height = lerp(currentShape, nextShape, blend) * surfaceActivation;
    }
    return height;
}

/// Projects a morphing-surface grid sample and computes distance fading and color variation.
float4 MorphingSurfaceSample(float2 gridIndex, bool pointSample, bool circleSample, float3 samplePoint,
    out float fade, out float colorPhase, out float3 surfacePoint) {
    fade = 1.0;
    colorPhase = 0.0;
    surfacePoint = 0.0;
    float2 cameraXZ = float2(time * 3.20 + 18.0 * sin(time * 0.031 + pathPhases.x) * cameraVariations.x,
        time * 2.15 + 14.0 * cos(time * 0.027 + pathPhases.y) * cameraVariations.x);
    float2 velocity = float2(3.20 + 0.558 * cos(time * 0.031 + pathPhases.x) * cameraVariations.x,
        2.15 - 0.378 * sin(time * 0.027 + pathPhases.y) * cameraVariations.x);
    float2 heading = normalize(velocity);
    float2 lateral = float2(-heading.y, heading.x);
    float deformationDistance = (24.0 + 7.0 * sin(time * 0.063 + 0.4 + pathPhases.z)) * surfaceVariations.z;
    float2 deformationCenter = cameraXZ + heading * deformationDistance + lateral
        * (6.0 * sin(time * 0.049 + pathPhases.w) * surfaceVariations.y);
    float surfaceAtCamera = surfaceShape == 2 ? 0.0 : MorphingSurfaceHeight(cameraXZ.x, cameraXZ.y, deformationCenter);
    float altitudePhase = 0.5 + 0.5 * sin(time * 0.087 + 0.6 + animationPhases.w);
    float altitude = lerp(7.0, 18.0, altitudePhase) * cameraVariations.y;
    float3 camera = float3(cameraXZ.x, surfaceAtCamera + altitude, cameraXZ.y);
    float3 viewCamera = camera;
    float3 funnelVelocity = 0.0;
    if (surfaceShape == 2) {
        camera = FunnelCamera(camera, funnelVelocity);
    }
    float x = AnchoredFlightGridCoordinate(camera.x, gridIndex.x, 3.0);
    float z = AnchoredFlightGridCoordinate(camera.z, gridIndex.y, 3.0);
    float3 world = float3(x, MorphingSurfaceHeight(x, z, deformationCenter), z);
    if (pointSample) {
        world = samplePoint;
    }
    surfacePoint = world;
    float trackingPhase = 0.5 + 0.5 * sin(time * 0.079 + 1.7 + pathPhases.z);
    float trackingDistance = lerp(12.0, 44.0, trackingPhase) * cameraVariations.w;
    float2 targetXZ = cameraXZ + heading * trackingDistance + lateral * (7.0 * sin(time * 0.041 + 0.9
        + pathPhases.w) * cameraVariations.x);
    float targetHeight = surfaceShape == 2 ? 0.0 : MorphingSurfaceHeight(targetXZ.x, targetXZ.y, deformationCenter);
    float3 target = float3(targetXZ.x, targetHeight, targetXZ.y);
    float3 forward = normalize(target - viewCamera);
    if (surfaceShape == 2) {
        forward = FunnelView(forward);
    }
    float3 right = normalize(cross(float3(0.0, 1.0, 0.0), forward));
    float3 cameraUp = normalize(cross(forward, right));
    float roll = 0.18 * sin(time * 0.071 + animationPhases.w) * cameraVariations.z;
    float rollSine, rollCosine;
    sincos(roll, rollSine, rollCosine);
    float3 rolledRight = right * rollCosine + cameraUp * rollSine;
    float3 rolledUp = cameraUp * rollCosine - right * rollSine;
    float3 relative = world - camera;
    float3 view = float3(dot(relative, rolledRight), dot(relative, rolledUp), dot(relative, forward));
    view = TumblingView(view);
    if (surfaceShape == 2) {
        float3 planeNormal = TumblingView(float3(rolledRight.y, rolledUp.y, forward.y));
        view = FunnelEntryView(view, planeNormal, 1.0);
    }
    float focalLength = 1.0 / tan(0.61);
    float aspect = resolution.x / resolution.y;
    static const float nearPlane = 0.12;
    static const float farPlane = 230.0;
    float projectionFar = farPlane;
    float distantFade = smoothstep(155.0, farPlane, view.z);
    fade = lerp(1.0, 0.28, distantFade);
    colorPhase = 0.5 + 0.5 * sin(time * 0.19 + x * 0.075 + z * 0.055 + length(world - camera) * 0.025 + animationPhases.z);
    if (surfaceShape == 2) {
        if (!circleSample) {
            fade *= FunnelVisibility();
        }
        if (world.y < -4.0) {
            float depth = smoothstep(4.0, FUNNEL_NECK_VISIBILITY_DEPTH, -world.y);
            projectionFar = lerp(farPlane, FUNNEL_FAR_PLANE, depth);
        }
    }
    return float4(view.x * focalLength / aspect, view.y * focalLength, view.z * projectionFar
        / (projectionFar - nearPlane) - nearPlane * projectionFar / (projectionFar - nearPlane), view.z);
}

/// Maps a wireframe segment endpoint to a wave-surface grid sample.
float4 InfiniteSurfacePosition(uint segment, uint endpoint, out float fade, out float colorPhase) {
    fade = 1.0;
    colorPhase = 0.0;
    uint direction = segment / (93 * 92);
    uint part = segment % (93 * 92);
    float fixedIndex = float(part / 92) - 46.0;
    float varyingIndex = float(part % 92 + endpoint) - 46.0;
    float2 index = direction == 0 ? float2(fixedIndex, varyingIndex) : float2(varyingIndex, fixedIndex);
    bool visible = true;
    float3 worldPoint = 0.0;
    if (surfaceShape == 2) {
        float step = endpoint == 0 ? 1.0 : -1.0;
        float2 other = index + (direction == 0 ? float2(0.0, step) : float2(step, 0.0));
        worldPoint = FunnelWireEndpoint(index, other, visible);
        visible = visible && FunnelBodyVisibility() > 0.0;
    }
    float3 unusedPoint;
    float4 position = float4(0.0, 0.0, -1.0, 1.0);
    if (visible) {
        position = InfiniteSurfaceSample(index, surfaceShape == 2, false, worldPoint, fade, colorPhase, unusedPoint);
    } else {
        fade = 0.0;
        colorPhase = 0.0;
    }
    return position;
}

/// Maps a wireframe segment endpoint to a morphing-surface grid sample.
float4 MorphingSurfaceFlightPosition(uint segment, uint endpoint, out float fade, out float colorPhase) {
    fade = 1.0;
    colorPhase = 0.0;
    uint direction = segment / (113 * 112);
    uint part = segment % (113 * 112);
    float fixedIndex = float(part / 112) - 56.0;
    float varyingIndex = float(part % 112 + endpoint) - 56.0;
    float2 index = direction == 0 ? float2(fixedIndex, varyingIndex) : float2(varyingIndex, fixedIndex);
    bool visible = true;
    float3 worldPoint = 0.0;
    if (surfaceShape == 2) {
        float step = endpoint == 0 ? 1.0 : -1.0;
        float2 other = index + (direction == 0 ? float2(0.0, step) : float2(step, 0.0));
        worldPoint = FunnelWireEndpoint(index, other, visible);
        visible = visible && FunnelBodyVisibility() > 0.0;
    }
    float3 unusedPoint;
    float4 position = float4(0.0, 0.0, -1.0, 1.0);
    if (visible) {
        position = MorphingSurfaceSample(index, surfaceShape == 2, false, worldPoint, fade, colorPhase, unusedPoint);
    } else {
        fade = 0.0;
        colorPhase = 0.0;
    }
    return position;
}

/// Shades textured surfaces with independently enabled main, fill, ambient and rim illumination.
float3 LitMaterial(float3 baseColor, float3 normal, float3 viewPosition, float materialBrightness) {
    float3 lightDirection = normalize(float3(-0.72, 0.48, -1.0));
    float3 viewDirection = normalize(-viewPosition);
    float diffuse = 0.0;
    float specular = 0.0;
    if (lightSettings.x != 0.0) {
        float3 halfVector = normalize(lightDirection + viewDirection);
        diffuse = saturate(dot(normal, lightDirection)) * lightSettings.x;
        specular = pow(saturate(dot(normal, halfVector)), 28.0) * lightSettings.x;
    }
    if (lightSettings.y != 0.0) {
        float3 fillDirection = normalize(float3(-lightDirection.x, -lightDirection.y, lightDirection.z));
        float3 halfVector = normalize(fillDirection + viewDirection);
        diffuse += saturate(dot(normal, fillDirection)) * lightSettings.y;
        specular += pow(saturate(dot(normal, halfVector)), 28.0) * lightSettings.y;
    }
    float rim = pow(saturate(1.0 - abs(dot(normal, viewDirection))), 2.0);
    float illumination = lightSettings.z + 0.78 * diffuse + lightSettings.w * rim;
    return saturate(baseColor * materialBrightness * illumination + specular * 0.48);
}

/// Original material colours of the two surface flights.
float3 FlightMaterialColor(float phase, uint patch, float chamber) {
    float3 color = float3(0.0, 0.0, 0.0);
    if (effect == 19) {
        color = lerp(float3(0.10, 0.72, 1.0), float3(0.72, 0.20, 1.0), phase);
    } else {
        color = lerp(float3(0.18, 1.0, 0.63), float3(1.0, 0.31, 0.72), phase);
    }
    return color;
}

/// Uses the original wire grids, camera trajectories, fading and colours.
VSOutput VSMain(uint vertexId : SV_VertexID) {
    uint segment = vertexId / 2;
    uint endpoint = vertexId & 1;
    float fade = 1.0;
    float colorPhase = 0.0;
    VSOutput output;
    if (effect == 19) {
        output.position = InfiniteSurfacePosition(segment, endpoint, fade, colorPhase);
    } else {
        output.position = MorphingSurfaceFlightPosition(segment, endpoint, fade, colorPhase);
    }
    float3 color = FlightMaterialColor(colorPhase, 0, 0.0);
    output.color = float4(color * fade, 1.0);
    return output;
}

/// Projects the finite mesh rim and the separate circles beyond it.
VSOutput FunnelCircleVS(uint vertexId : SV_VertexID) {
    uint circle = vertexId / (FUNNEL_CIRCLE_SEGMENTS * 2);
    uint segment = vertexId / 2 % FUNNEL_CIRCLE_SEGMENTS;
    uint endpoint = vertexId & 1;
    float visibility;
    float3 world = FunnelCirclePoint(circle, segment, endpoint, visibility);
    float fade = 0.0;
    float colorPhase = 0.0;
    VSOutput output;
    output.position = float4(0.0, 0.0, -1.0, 1.0);
    output.color = float4(0.0, 0.0, 0.0, 1.0);
    if (visibility > 0.0) {
        float3 unusedPoint;
        if (effect == 19) {
            output.position = InfiniteSurfaceSample(float2(0.0, 0.0), true, true, world, fade, colorPhase, unusedPoint);
        } else {
            output.position = MorphingSurfaceSample(float2(0.0, 0.0), true, true, world, fade, colorPhase, unusedPoint);
        }
        output.color = float4(FlightMaterialColor(colorPhase, 0, 0.0) * fade * visibility, 1.0);
    }
    return output;
}

/// Outputs the original unlit wireframe colours.
float4 PSMain(VSOutput input) : SV_TARGET {
    return input.color;
}

/// Samples the filled surface and reconstructs view coordinates before perspective division for hardware
/// clipping.
float4 SolidFlightSample(float2 uv, uint patch, out float3 view, out float4 material, out float3 world) {
    float fade = 1.0;
    float phase = 0.0;
    float chamber = 0.0;
    float4 position = 0.0;
    float halfFov = 0.61;
    if (effect == 19) {
        position = InfiniteSurfaceSample(uv * 92.0 - 46.0, false, false, float3(0.0, 0.0, 0.0), fade, phase, world);
    } else {
        position = MorphingSurfaceSample(uv * 112.0 - 56.0, false, false, float3(0.0, 0.0, 0.0), fade, phase, world);
    }
    view = float3(position.x * (resolution.x / resolution.y) * tan(halfFov), position.y * tan(halfFov), position.w);
    material = float4(FlightMaterialColor(phase, patch, chamber), fade);
    return position;
}

/// Computes filled-grid normals with finite differences large enough to remain stable during long flights.
SolidSurfaceOutput SolidSurfaceVS(uint vertexId : SV_VertexID) {
    uint verticesPerPatch = (surfaceColumns + 1) * (surfaceRows + 1);
    uint patch = vertexId / verticesPerPatch;
    uint vertex = vertexId % verticesPerPatch;
    float2 uv = float2(float(vertex % (surfaceColumns + 1)) / surfaceColumns,
        float(vertex / (surfaceColumns + 1)) / surfaceRows);
    SolidSurfaceOutput output;
    float3 world;
    output.position = SolidFlightSample(uv, patch, output.viewPosition, output.material, world);
    output.funnelLocal = float2(0.0, 0.0);
    if (surfaceShape == 2) {
        output.funnelLocal = world.xz - funnelMotion.zw;
    }
    const float epsilon = max(0.0002, abs(time) * 0.00000001);
    float3 uView, vView;
    float3 unusedPoint;
    float4 unusedMaterial;
    SolidFlightSample(uv + float2(epsilon, 0), patch, uView, unusedMaterial, unusedPoint);
    SolidFlightSample(uv + float2(0, epsilon), patch, vView, unusedMaterial, unusedPoint);
    output.normal = normalize(cross(uView - output.viewPosition, vView - output.viewPosition));
    return output;
}

/// Uses the rasterized face for two-sided lighting; smooth normals must not flip inside a triangle.
float4 SolidSurfacePS(SolidSurfaceOutput input, bool frontFace : SV_IsFrontFace) : SV_TARGET {
    if (surfaceShape == 2) {
        float radius = FunnelCutRadius();
        clip(dot(input.funnelLocal, input.funnelLocal) - radius * radius);
        clip(FunnelBodyVisibility() - 0.00001);
    }
    float3 normal = normalize(input.normal);
    if (!frontFace) {
        normal = -normal;
    }
    return float4(LitMaterial(input.material.rgb, normal, input.viewPosition, 1.0) * input.material.a, 1.0);
}
