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
 * Last modified for version 1.2.0.1
 */

static const float PI = 3.14159265358979323846;
static const uint FLIGHT_WIRE_ROWS = 116;
static const float FLIGHT_HALF_DEPTH_INDEX = 57.6;

cbuffer FrameConstants : register(b0) {
    float2 resolution;
    float time;
    uint copyCount;
    float4 animationPhases;
    float4 surfaceVariations;
    float4 cameraVariations;
    float4 pathPhases;
    float4 cameraRotation;
    float4 corridorShape;
    uint4 wallPalettes;
    float4 lightSettings;
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

/// Anchors a uniformly spaced grid to the camera's current grid cell.
float AnchoredFlightGridCoordinate(float cameraCoordinate, float index, float spacing) {
    float gridOrigin = floor(cameraCoordinate / spacing) * spacing;
    return gridOrigin + index * spacing;
}

/// Calculates the corridor's smoothly varying horizontal center.
float CorridorCenterX(float z) {
    return (13.0 * sin(z * 0.028 + pathPhases.x) + 6.0 * sin(z * 0.011 + 1.2 + pathPhases.y)) * surfaceVariations.y;
}

/// Calculates the corridor's smoothly varying base height.
float CorridorBaseHeight(float z) {
    return (6.0 * sin(z * 0.022 + 0.4 + pathPhases.z) + 3.0 * sin(z * 0.047 + 1.1 + pathPhases.w)) * surfaceVariations.x;
}

/// Blends the corridor's waves, banking, saddle and arch shapes.
float CorridorMidHeight(float x, float z, float2 cameraXZ) {
    float lateral = clamp((x - CorridorCenterX(z)) * 0.032, -2.6, 2.6);
    float longitudinal = clamp((z - cameraXZ.y) * 0.026, -2.6, 2.6);
    float waves = (1.6 * sin(x * 0.095 + z * 0.041 - time * 0.34 + animationPhases.x) + 0.9
        * cos(z * 0.083 + time * 0.21 + animationPhases.y)) * surfaceVariations.x;
    float bank = 4.2 * lateral * sin(z * 0.019 + time * 0.047 + animationPhases.x) * surfaceVariations.y;
    float saddle = 2.0 * (lateral * lateral - 0.58 * longitudinal * longitudinal) * surfaceVariations.y;
    float arch = (-3.1 * cos(lateral * 0.92) + 1.5 * sin(longitudinal * 1.25 + time * 0.16 + animationPhases.x))
        * surfaceVariations.x;
    float cycle = frac(time * 0.014 + animationPhases.y / (2.0 * PI)) * 4.0;
    uint shape = (uint) floor(cycle);
    float blend = smoothstep(0.15, 0.85, frac(cycle));
    float currentShape;
    float nextShape;
    if (shape == 0) {
        currentShape = waves;
        nextShape = bank;
    } else if (shape == 1) {
        currentShape = bank;
        nextShape = saddle;
    } else if (shape == 2) {
        currentShape = saddle;
        nextShape = arch;
    } else {
        currentShape = arch;
        nextShape = waves;
    }
    return CorridorBaseHeight(z) + lerp(currentShape, nextShape, blend);
}

/// Calculates the corridor's animated vertical half-opening.
float CorridorHalfHeight(float z) {
    float opening = (7.6 + 1.5 * sin(z * 0.032 - time * 0.19 + animationPhases.x) + 1.1
        * sin(time * 0.073 + 0.8 + animationPhases.y)) * surfaceVariations.z / surfaceVariations.w;
    return clamp(opening, 4.8, 11.5);
}

/// Calculates the corridor's animated horizontal half-opening.
float CorridorHalfWidth(float z) {
    float opening = (10.2 + 2.2 * sin(z * 0.025 + time * 0.15 + 1.4 + animationPhases.x) + 1.4
        * cos(time * 0.061 - 0.6 + animationPhases.y)) * surfaceVariations.z * surfaceVariations.w;
    return clamp(opening, 6.5, 14.0);
}

/// Bends the local flight into a circular arc and transports cross-sections along its tangent.
/// Zero curvature is the exact original route; axial rotation changes wall orientation independently of tumbling.
float3 BendCorridor(float3 relative) {
    float squaredAngle = dot(corridorShape.xy, corridorShape.xy) * relative.z * relative.z;
    float sinc;
    float cosc;
    if (squaredAngle < 0.01) {
        sinc = 1.0 - squaredAngle / 6.0 + squaredAngle * squaredAngle / 120.0;
        cosc = 0.5 - squaredAngle / 24.0 + squaredAngle * squaredAngle / 720.0;
    } else {
        float angle = sqrt(squaredAngle);
        sinc = sin(angle) / angle;
        float halfSinc = sin(angle * 0.5) / angle;
        cosc = 2.0 * halfSinc * halfSinc;
    }
    float crossSection = 1.0 - dot(corridorShape.xy, relative.xy);
    relative = float3(relative.xy + corridorShape.xy * (relative.z * relative.z * cosc * crossSection),
        relative.z * sinc * crossSection);
    float rollSine, rollCosine;
    sincos(corridorShape.z, rollSine, rollCosine);
    return float3(relative.x * rollCosine - relative.y * rollSine,
        relative.x * rollSine + relative.y * rollCosine, relative.z);
}

/// Projects a corridor-wall grid sample and computes distance fading and color variation.
float4 CorridorSurfaceSample(float u, float zIndex, uint surface, out float fade, out float colorPhase) {
    float cameraZ = time * 4.6;
    float cameraX = CorridorCenterX(cameraZ);
    float2 cameraXZ = float2(cameraX, cameraZ);
    float cameraY = CorridorMidHeight(cameraX, cameraZ, cameraXZ) + 0.35 * sin(time * 0.13 + animationPhases.w)
        * cameraVariations.y;
    float3 camera = float3(cameraX, cameraY, cameraZ);
    float z = AnchoredFlightGridCoordinate(cameraZ, zIndex, 3.0);
    float centerX = CorridorCenterX(z);
    float centerY = CorridorMidHeight(centerX, z, cameraXZ);
    float halfHeight = CorridorHalfHeight(z);
    float halfWidth = CorridorHalfWidth(z);
    float3 world;
    if (surface < 2) {
        float side = surface == 0 ? -1.0 : 1.0;
        float x = centerX + u * halfWidth;
        float sharedVerticalBend = (1.35 * sin(u * PI + z * 0.031 - time * 0.17 + animationPhases.x) + 1.05 * u * u
            * sin(z * 0.017 + time * 0.083 + animationPhases.y)) * surfaceVariations.x;
        float middle = CorridorMidHeight(x, z, cameraXZ);
        world = float3(x, middle + side * halfHeight + sharedVerticalBend, z);
    } else {
        float side = surface == 2 ? -1.0 : 1.0;
        float y = centerY + u * halfHeight;
        float sharedHorizontalBend = (1.75 * sin(u * PI - z * 0.027 + time * 0.14 + animationPhases.x) + 1.20 * u * u
            * cos(z * 0.015 - time * 0.091 + animationPhases.y)) * surfaceVariations.y;
        world = float3(centerX + side * halfWidth + sharedHorizontalBend, y, z);
    }
    float targetZ = cameraZ + 34.0 * cameraVariations.w + 5.0 * sin(time * 0.061 + animationPhases.w) * cameraVariations.w;
    float targetX = CorridorCenterX(targetZ);
    float targetY = CorridorMidHeight(targetX, targetZ, cameraXZ);
    float3 forward = normalize(BendCorridor(float3(targetX, targetY, targetZ) - camera));
    float3 right = normalize(cross(float3(0.0, 1.0, 0.0), forward));
    float3 cameraUp = normalize(cross(forward, right));
    float turnRoll = clamp((targetX - cameraX) * -0.018, -0.28, 0.28);
    float roll = (turnRoll + 0.10 * sin(time * 0.077 + animationPhases.w)) * cameraVariations.z;
    float rollSine, rollCosine;
    sincos(roll, rollSine, rollCosine);
    float3 rolledRight = right * rollCosine + cameraUp * rollSine;
    float3 rolledUp = cameraUp * rollCosine - right * rollSine;
    float3 relative = BendCorridor(world - camera);
    float3 view = float3(dot(relative, rolledRight), dot(relative, rolledUp), dot(relative, forward));
    view = TumblingView(view);
    float focalLength = 1.0 / tan(0.62);
    float aspect = resolution.x / resolution.y;
    static const float nearPlane = 0.14;
    static const float farPlane = 240.0;
    float distantFade = smoothstep(165.0, farPlane, view.z);
    float nearFade = smoothstep(0.35, 4.0, view.z);
    fade = lerp(1.0, 0.20, distantFade) * nearFade;
    colorPhase = 0.5 + 0.5 * sin(time * 0.18 + world.x * 0.052 + z * 0.061 + wallPalettes[surface] * 1.1
        + animationPhases.z);
    return float4(view.x * focalLength / aspect, view.y * focalLength,
        view.z * farPlane / (farPlane - nearPlane) - nearPlane * farPlane / (farPlane - nearPlane), view.z);
}

/// Calculates the funnel's smoothly varying centerline.
float3 FunnelCenter(float pathPosition) {
    return float3((14.0 * sin(pathPosition * 0.022 + pathPhases.x) + 4.0 * sin(pathPosition * 0.061 + 0.7 + pathPhases.y))
        * surfaceVariations.y, (9.0 * sin(pathPosition * 0.017 + 0.8 + pathPhases.z) + 3.0 * cos(pathPosition * 0.051
        + pathPhases.w)) * surfaceVariations.x, pathPosition);
}

/// Calculates the tangent along the funnel's centerline.
float3 FunnelTangent(float pathPosition) {
    return normalize(float3((0.308 * cos(pathPosition * 0.022 + pathPhases.x) + 0.244 * cos(pathPosition * 0.061 + 0.7
        + pathPhases.y)) * surfaceVariations.y, (0.153 * cos(pathPosition * 0.017 + 0.8 + pathPhases.z) - 0.153
        * sin(pathPosition * 0.051 + pathPhases.w)) * surfaceVariations.x, 1.0));
}

/// Calculates the smoothly varying chamber expansion along the funnel.
float FunnelChamberAmount(float pathPosition) {
    float chamberWave = 0.5 + 0.5 * cos(pathPosition * 0.038 + PI + pathPhases.z);
    return chamberWave * chamberWave * chamberWave;
}

/// Calculates the funnel radius, including its chamber expansion.
float FunnelRadius(float pathPosition) {
    float chamber = FunnelChamberAmount(pathPosition);
    float narrowVariation = (1.15 * sin(pathPosition * 0.11 + animationPhases.x) + 0.65
        * sin(pathPosition * 0.043 + time * 0.08 + animationPhases.y)) * surfaceVariations.x;
    return max(4.2, 5.8 + narrowVariation + 36.0 * chamber * surfaceVariations.z);
}

/// Calculates a point on a funnel cross-section along its centerline.
float3 FunnelPoint(float pathPosition, float angle, out float chamberAmount) {
    float3 center = FunnelCenter(pathPosition);
    float3 tangent = FunnelTangent(pathPosition);
    float3 right = normalize(cross(float3(0.0, 1.0, 0.0), tangent));
    float3 localUp = normalize(cross(tangent, right));
    float twist = pathPosition * 0.013 + 0.32 * sin(pathPosition * 0.027 - time * 0.10 + animationPhases.x)
        * surfaceVariations.y;
    float twistedAngle = angle + twist;
    float angleSine, angleCosine;
    sincos(twistedAngle, angleSine, angleCosine);
    chamberAmount = FunnelChamberAmount(pathPosition);
    float radius = FunnelRadius(pathPosition);
    float lobes = 1.0 + (0.18 * sin(3.0 * angle + pathPosition * 0.031 - time * 0.16 + animationPhases.x) + 0.09
        * sin(5.0 * angle - pathPosition * 0.019 + time * 0.11 + animationPhases.y)) * surfaceVariations.y;
    float horizontalScale = (1.0 + 0.28 * sin(pathPosition * 0.024 + time * 0.047 + animationPhases.x))
        * surfaceVariations.w;
    float verticalScale = (1.0 - 0.22 * sin(pathPosition * 0.024 + time * 0.047 + animationPhases.x))
        / surfaceVariations.w;
    return center + right * (radius * lobes * horizontalScale * angleCosine) + localUp * (radius * lobes * verticalScale
        * angleSine);
}

/// Projects a funnel grid sample and computes distance fading, color variation and chamber expansion.
float4 FunnelSurfaceSample(float angle, float pathIndex, out float fade, out float colorPhase, out float chamberAmount) {
    float cameraPath = time * 4.5;
    float cameraRadius = FunnelRadius(cameraPath);
    float3 cameraCenter = FunnelCenter(cameraPath);
    float3 cameraTangent = FunnelTangent(cameraPath);
    float3 cameraRight = normalize(cross(float3(0.0, 1.0, 0.0), cameraTangent));
    float3 cameraUp = normalize(cross(cameraTangent, cameraRight));
    float cameraOffset = min(cameraRadius * 0.10 * cameraVariations.x, 2.4);
    float3 camera = cameraCenter + cameraRight * (cameraOffset * sin(time * 0.083 + animationPhases.w)) + cameraUp
        * (cameraOffset * 0.65 * cos(time * 0.071 + animationPhases.w) * cameraVariations.y);
    float pathPosition = AnchoredFlightGridCoordinate(cameraPath, pathIndex, 3.0);
    float3 world = FunnelPoint(pathPosition, angle, chamberAmount);
    float targetPath = cameraPath + 36.0 * cameraVariations.w + 6.0 * sin(time * 0.057 + animationPhases.w)
        * cameraVariations.w;
    float3 target = FunnelCenter(targetPath);
    float3 forward = normalize(target - camera);
    float3 right = normalize(cross(float3(0.0, 1.0, 0.0), forward));
    float3 viewUp = normalize(cross(forward, right));
    float roll = (0.22 * sin(time * 0.061 + animationPhases.w) + 0.12 * sin(cameraPath * 0.027 + pathPhases.w))
        * cameraVariations.z;
    float rollSine, rollCosine;
    sincos(roll, rollSine, rollCosine);
    float3 rolledRight = right * rollCosine + viewUp * rollSine;
    float3 rolledUp = viewUp * rollCosine - right * rollSine;
    float3 relative = world - camera;
    float3 view = float3(dot(relative, rolledRight), dot(relative, rolledUp), dot(relative, forward));
    view = TumblingView(view);
    float focalLength = 1.0 / tan(0.66);
    float aspect = resolution.x / resolution.y;
    static const float nearPlane = 0.14;
    static const float farPlane = 260.0;
    float distantFade = smoothstep(185.0, farPlane, view.z);
    float nearFade = smoothstep(0.35, 4.5, view.z);
    fade = lerp(1.0, 0.16, distantFade) * nearFade;
    colorPhase = 0.5 + 0.5 * sin(angle * 2.0 + pathPosition * 0.046 - time * 0.22 + animationPhases.z);
    return float4(view.x * focalLength / aspect, view.y * focalLength, view.z * farPlane / (farPlane - nearPlane)
        - nearPlane * farPlane / (farPlane - nearPlane), view.z);
}

/// Builds corridor wire segments over the extended longitudinal grid.
float4 BetweenMorphingSurfacesPosition(uint segment, uint endpoint, out float fade, out float colorPhase,
        out float surfaceKind) {
    const uint longitudinalSegments = 25 * FLIGHT_WIRE_ROWS;
    const uint segmentsPerSurface = longitudinalSegments + 24 * (FLIGHT_WIRE_ROWS + 1);
    uint surface = segment / segmentsPerSurface;
    uint part = segment % segmentsPerSurface;
    float u;
    float zIndex;
    if (part < longitudinalSegments) {
        u = -1.0 + 2.0 * (part / FLIGHT_WIRE_ROWS) / 24.0;
        zIndex = float(part % FLIGHT_WIRE_ROWS + endpoint) - 0.5 * FLIGHT_WIRE_ROWS;
    } else {
        part -= longitudinalSegments;
        u = -1.0 + 2.0 * (part % 24 + endpoint) / 24.0;
        zIndex = float(part / 24) - 0.5 * FLIGHT_WIRE_ROWS;
    }
    zIndex = clamp(zIndex, -FLIGHT_HALF_DEPTH_INDEX, FLIGHT_HALF_DEPTH_INDEX);
    surfaceKind = float(surface);
    return CorridorSurfaceSample(u, zIndex, surface, fade, colorPhase);
}

/// Builds funnel wire segments over the extended longitudinal grid.
float4 ExpandingFunnelPosition(uint segment, uint endpoint, out float fade, out float colorPhase,
        out float chamberAmount) {
    const uint circumferentialSegments = 40 * (FLIGHT_WIRE_ROWS + 1);
    float angle;
    float pathIndex;
    if (segment < circumferentialSegments) {
        angle = 2.0 * PI * (segment % 40 + endpoint) / 40.0;
        pathIndex = float(segment / 40) - 0.5 * FLIGHT_WIRE_ROWS;
    } else {
        uint part = segment - circumferentialSegments;
        angle = 2.0 * PI * (part / FLIGHT_WIRE_ROWS) / 40.0;
        pathIndex = float(part % FLIGHT_WIRE_ROWS + endpoint) - 0.5 * FLIGHT_WIRE_ROWS;
    }
    pathIndex = clamp(pathIndex, -FLIGHT_HALF_DEPTH_INDEX, FLIGHT_HALF_DEPTH_INDEX);
    return FunnelSurfaceSample(angle, pathIndex, fade, colorPhase, chamberAmount);
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

/// Original material colours of the four walls and the funnel.
float3 FlightMaterialColor(float phase, uint patch, float chamber) {
    float3 color = float3(0.0, 0.0, 0.0);
    if (effect == 22) {
        uint palette = wallPalettes[patch];
        if (palette == 0) {
            color = lerp(float3(0.08, 0.78, 1.0), float3(0.38, 0.28, 1.0), phase);
        } else if (palette == 1) {
            color = lerp(float3(1.0, 0.25, 0.62), float3(1.0, 0.76, 0.18), phase);
        } else if (palette == 2) {
            color = lerp(float3(0.12, 1.0, 0.50), float3(0.10, 0.52, 1.0), phase);
        } else {
            color = lerp(float3(1.0, 0.64, 0.10), float3(1.0, 0.20, 0.36), phase);
        }
    } else {
        float3 tunnel = lerp(float3(0.12, 0.82, 1.0), float3(0.72, 0.20, 1.0), phase);
        float3 room = lerp(float3(1.0, 0.26, 0.18), float3(1.0, 0.82, 0.22), phase);
        color = lerp(tunnel, room, chamber);
    }
    return color;
}

/// Uses the original wire density, camera trajectories, fading and colours.
VSOutput VSMain(uint vertexId : SV_VertexID) {
    uint segment = vertexId / 2;
    uint endpoint = vertexId & 1;
    float fade = 1.0;
    float colorPhase = 0.0;
    float surfaceKind = 0.0;
    float chamberAmount = 0.0;
    VSOutput output;
    if (effect == 22) {
        output.position = BetweenMorphingSurfacesPosition(segment, endpoint, fade, colorPhase, surfaceKind);
    } else {
        output.position = ExpandingFunnelPosition(segment, endpoint, fade, colorPhase, chamberAmount);
    }
    float3 color = FlightMaterialColor(colorPhase, uint(surfaceKind), chamberAmount);
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
    float halfFov;
    if (effect == 22) {
        position = CorridorSurfaceSample(uv.x * 2.0 - 1.0, uv.y * 2.0 * FLIGHT_HALF_DEPTH_INDEX - FLIGHT_HALF_DEPTH_INDEX,
            patch, fade, phase);
        halfFov = 0.62;
    } else {
        position = FunnelSurfaceSample(uv.x * 2.0 * PI, uv.y * 2.0 * FLIGHT_HALF_DEPTH_INDEX - FLIGHT_HALF_DEPTH_INDEX,
            fade, phase, chamber);
        halfFov = 0.66;
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
