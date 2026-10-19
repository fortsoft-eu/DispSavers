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

cbuffer FrameConstants : register(b0) {
    float2 resolution;
    float time;
    uint copyCount;
    float4 animationPhases;
    float4 surfaceVariations;
    float4 cameraVariations;
    float4 pathPhases;
    float4 cameraRotation;
};

cbuffer EffectConstants : register(b1) {
    uint effect;
    uint surfaceColumns;
    uint surfaceRows;
    uint surfacePatches;
};

struct VSOutput {
    float4 position : SV_POSITION;
    float4 color : COLOR0;
};

struct SolidSurfaceOutput {
    float4 position : SV_POSITION;
    centroid float3 viewPosition : TEXCOORD0;
    centroid float3 normal : TEXCOORD1;
    centroid float4 material : COLOR0;
};

/// Applies the inverse unit-quaternion camera rotation; identity preserves the original view.
float3 TumblingView(float3 view) {
    float3 axis = -cameraRotation.xyz;
    float3 turn = 2.0 * cross(axis, view);
    return view + cameraRotation.w * turn + cross(axis, turn);
}

/// Original FSSaver InfiniteGridOffset calculation.
float InfiniteGridOffset(float index) {
    float direction = index < 0 ? -1.0 : 1.0;
    float distance = abs((float) index);
    return direction * (1.5 * distance + 0.045 * distance * distance);
}

/// Original FSSaver InfiniteGridCoordinate calculation.
float InfiniteGridCoordinate(float cameraCoordinate, float index) {
    static const float spacing = 1.5;
    float cameraCell = cameraCoordinate / spacing;
    float baseCell = floor(cameraCell);
    float blend = smoothstep(0.0, 1.0, frac(cameraCell));
    float currentCoordinate = baseCell * spacing + InfiniteGridOffset(index);
    float nextCoordinate = (baseCell + 1.0) * spacing + InfiniteGridOffset(index - 1);
    return lerp(currentCoordinate, nextCoordinate, blend);
}

/// FSSaver WaveHeight calculation with independent, smoothly varying scene parameters.
float WaveHeight(float x, float z, float2 cameraXZ) {
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
    return waveAmount * fineWaves + 0.62 * curvatureAmount * broadCurvature;
}

/// Original FSSaver AnchoredFlightGridCoordinate calculation.
float AnchoredFlightGridCoordinate(float cameraCoordinate, float index, float spacing) {
    float gridOrigin = floor(cameraCoordinate / spacing) * spacing;
    return gridOrigin + index * spacing;
}

/// FSSaver InfiniteSurfaceSample calculation with independent, smoothly varying scene parameters.
float4 InfiniteSurfaceSample(float2 gridIndex, out float fade, out float colorPhase) {
    float2 cameraXZ = float2(time * 1.15 + 4.0 * sin(time * 0.071 + pathPhases.x)
        * cameraVariations.x, time * 0.82 + 3.2 * cos(time * 0.053 + pathPhases.y) * cameraVariations.x);
    float surfaceAtCamera = WaveHeight(cameraXZ.x, cameraXZ.y, cameraXZ);
    float sidePhase = sin(time * 0.115 + 0.65 + pathPhases.z);
    float distancePhase = 0.5 + 0.5 * sin(time * 0.17 + 0.8 + pathPhases.w);
    float surfaceDistance = lerp(3.0, 12.0, distancePhase);
    float signedHeight = surfaceDistance * sidePhase * cameraVariations.y;
    float3 camera = float3(cameraXZ.x, surfaceAtCamera + signedHeight, cameraXZ.y);
    float x = InfiniteGridCoordinate(cameraXZ.x, gridIndex.x);
    float z = InfiniteGridCoordinate(cameraXZ.y, gridIndex.y);
    float3 world = float3(x, WaveHeight(x, z, cameraXZ), z);
    colorPhase = 0.5 + 0.5 * sin(time * 0.24 + x * 0.11 + z * 0.09 + animationPhases.z);
    float yaw = time * 0.13 + 0.70 * sin(time * 0.047 + pathPhases.y) * cameraVariations.x + pathPhases.z;
    float surfaceViewPhase = 0.5 + 0.5 * sin(time * 0.23 + 2.0 + animationPhases.y);
    float surfaceViewAmount = lerp(0.12, 1.0, surfaceViewPhase);
    float pitchTowardSurface = clamp(-signedHeight / 7.0, -1.35, 1.35);
    float pitch = pitchTowardSurface * surfaceViewAmount;
    float3 forward = normalize(float3(cos(yaw), pitch, sin(yaw)));
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
    float focalLength = 1.0 / tan(0.61);
    float aspect = resolution.x / resolution.y;
    static const float nearPlane = 0.12;
    static const float farPlane = 150.0;
    float distantFade = smoothstep(100.0, farPlane, view.z);
    fade = lerp(1.0, 0.30, distantFade);
    return float4(view.x * focalLength / aspect, view.y * focalLength,
        view.z * farPlane / (farPlane - nearPlane) - nearPlane * farPlane / (farPlane - nearPlane), view.z);
}

/// FSSaver MorphingSurfaceHeight calculation with independent, smoothly varying scene parameters.
float MorphingSurfaceHeight(float x, float z, float2 deformationCenter) {
    float2 local = (float2(x, z) - deformationCenter) * 0.035;
    float radius = length(local);
    float waves = (0.85 * sin(0.25 * x + time * 0.58 + animationPhases.x) + 0.60
        * cos(0.31 * z - time * 0.43 + animationPhases.y)) * surfaceVariations.x;
    float hyperbolicParaboloid = 0.72 * (local.x * local.x - local.y * local.y) * surfaceVariations.y;
    float ellipticParaboloid = 0.46 * (local.x * local.x + 0.72 * local.y * local.y) * surfaceVariations.z;
    float coneSurface = 1.35 * radius * surfaceVariations.w;
    float radialSurface = 2.8 * sin(radius * 2.4 - time * 0.72 + animationPhases.x) * exp(-0.10 * radius * radius)
        * surfaceVariations.x;
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
    return lerp(currentShape, nextShape, blend);
}

/// FSSaver MorphingSurfaceSample calculation with independent, smoothly varying scene parameters.
float4 MorphingSurfaceSample(float2 gridIndex, out float fade, out float colorPhase) {
    float2 cameraXZ = float2(time * 3.20 + 18.0 * sin(time * 0.031 + pathPhases.x) * cameraVariations.x,
        time * 2.15 + 14.0 * cos(time * 0.027 + pathPhases.y) * cameraVariations.x);
    float2 velocity = float2(3.20 + 0.558 * cos(time * 0.031 + pathPhases.x) * cameraVariations.x, 2.15 - 0.378
        * sin(time * 0.027 + pathPhases.y) * cameraVariations.x);
    float2 heading = normalize(velocity);
    float2 lateral = float2(-heading.y, heading.x);
    float deformationDistance = (24.0 + 7.0 * sin(time * 0.063 + 0.4 + pathPhases.z)) * surfaceVariations.z;
    float2 deformationCenter = cameraXZ + heading * deformationDistance + lateral * (6.0 * sin(time * 0.049 + pathPhases.w)
        * surfaceVariations.y);
    float surfaceAtCamera = MorphingSurfaceHeight(cameraXZ.x, cameraXZ.y, deformationCenter);
    float altitudePhase = 0.5 + 0.5 * sin(time * 0.087 + 0.6 + animationPhases.w);
    float altitude = lerp(7.0, 18.0, altitudePhase) * cameraVariations.y;
    float3 camera = float3(cameraXZ.x, surfaceAtCamera + altitude, cameraXZ.y);
    float x = AnchoredFlightGridCoordinate(cameraXZ.x, gridIndex.x, 3.0);
    float z = AnchoredFlightGridCoordinate(cameraXZ.y, gridIndex.y, 3.0);
    float3 world = float3(x, MorphingSurfaceHeight(x, z, deformationCenter), z);
    float trackingPhase = 0.5 + 0.5 * sin(time * 0.079 + 1.7 + pathPhases.z);
    float trackingDistance = lerp(12.0, 44.0, trackingPhase) * cameraVariations.w;
    float2 targetXZ = cameraXZ + heading * trackingDistance + lateral * (7.0 * sin(time * 0.041 + 0.9 + pathPhases.w)
        * cameraVariations.x);
    float targetHeight = MorphingSurfaceHeight(targetXZ.x, targetXZ.y, deformationCenter);
    float3 target = float3(targetXZ.x, targetHeight, targetXZ.y);
    float3 forward = normalize(target - camera);
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
    float focalLength = 1.0 / tan(0.61);
    float aspect = resolution.x / resolution.y;
    static const float nearPlane = 0.12;
    static const float farPlane = 230.0;
    float distantFade = smoothstep(155.0, farPlane, view.z);
    fade = lerp(1.0, 0.28, distantFade);
    colorPhase = 0.5 + 0.5 * sin(time * 0.19 + x * 0.075 + z * 0.055 + length(world - camera) * 0.025 + animationPhases.z);
    return float4(view.x * focalLength / aspect, view.y * focalLength,
        view.z * farPlane / (farPlane - nearPlane) - nearPlane * farPlane / (farPlane - nearPlane), view.z);
}

/// Original FSSaver InfiniteSurfacePosition calculation.
float4 InfiniteSurfacePosition(uint segment, uint endpoint, out float fade, out float colorPhase) {
    uint direction = segment / (89 * 88);
    uint part = segment % (89 * 88);
    float fixedIndex = float(part / 88) - 44.0;
    float varyingIndex = float(part % 88 + endpoint) - 44.0;
    return InfiniteSurfaceSample(direction == 0
        ? float2(fixedIndex, varyingIndex)
        : float2(varyingIndex, fixedIndex), fade, colorPhase);
}

/// Original FSSaver MorphingSurfaceFlightPosition calculation.
float4 MorphingSurfaceFlightPosition(uint segment, uint endpoint, out float fade, out float colorPhase) {
    uint direction = segment / (113 * 112);
    uint part = segment % (113 * 112);
    float fixedIndex = float(part / 112) - 56.0;
    float varyingIndex = float(part % 112 + endpoint) - 56.0;
    return MorphingSurfaceSample(direction == 0
        ? float2(fixedIndex, varyingIndex)
        : float2(varyingIndex, fixedIndex), fade, colorPhase);
}

/// Original FSSaver LitMaterial calculation.
float3 LitMaterial(float3 baseColor, float3 normal, float3 viewPosition, float materialBrightness) {
    float3 lightDirection = normalize(float3(-0.72, 0.48, -1.0));
    float3 viewDirection = normalize(-viewPosition);
    float3 halfVector = normalize(lightDirection + viewDirection);
    float diffuse = saturate(dot(normal, lightDirection));
    float specular = pow(saturate(dot(normal, halfVector)), 28.0);
    float rim = pow(saturate(1.0 - abs(dot(normal, viewDirection))), 2.0);
    float illumination = 0.16 + 0.78 * diffuse + 0.12 * rim;
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

/// Outputs the original unlit wireframe colours.
float4 PSMain(VSOutput input) : SV_TARGET {
    return input.color;
}

/// Samples the filled surface and reconstructs view coordinates before perspective division for hardware clipping.
float4 SolidFlightSample(float2 uv, uint patch,
    out float3 view, out float4 material) {
    float fade = 1.0;
    float phase = 0.0;
    float chamber = 0.0;
    float4 position;
    float halfFov = 0.61;
    if (effect == 19) {
        position = InfiniteSurfaceSample(uv * 88.0 - 44.0, fade, phase);
    } else {
        position = MorphingSurfaceSample(uv * 112.0 - 56.0, fade, phase);
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
    const float epsilon = max(0.0002, abs(time) * 0.00000001);
    output.position = SolidFlightSample(uv, patch, output.viewPosition, output.material);
    float3 uView, vView;
    float4 unusedMaterial;
    SolidFlightSample(uv + float2(epsilon, 0), patch, uView, unusedMaterial);
    SolidFlightSample(uv + float2(0, epsilon), patch, vView, unusedMaterial);
    output.normal = normalize(cross(uView - output.viewPosition, vView - output.viewPosition));
    return output;
}

/// Uses the rasterized face for two-sided lighting; smooth normals must not flip inside a triangle.
float4 SolidSurfacePS(SolidSurfaceOutput input, bool frontFace : SV_IsFrontFace) : SV_TARGET {
    float3 normal = normalize(input.normal);
    if (!frontFace) {
        normal = -normal;
    }
    return float4(LitMaterial(input.material.rgb, normal, input.viewPosition, 1.0) * input.material.a, 1.0);
}
