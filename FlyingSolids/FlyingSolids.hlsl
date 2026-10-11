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

/// Camera, projection and lighting values shared by all instances in a frame.
cbuffer FrameConstants : register(b0) {
    float4 screen;
    float4 cameraPosition;
    float4 cameraRight;
    float4 cameraUp;
    float4 cameraForward;
    float4 lightDirection;
    float4 lightSettings;
};

/// Position, scale, rotation and solid kind for every possible instance.
cbuffer ObjectConstants : register(b1) {
    float4 objectPositionAndScale[270];
    float4 objectRotationAndKind[270];
};

/// Parameters that select the mesh and its instance range for one draw call.
cbuffer DrawConstants : register(b2) {
    uint drawKind;
    float drawZOffset;
    float capsuleRadius;
    float capsuleHalfLength;
};

/// Vertex-buffer attributes consumed by the vertex shader.
struct VertexInput {
    float3 position : POSITION;
    float3 normal : NORMAL;
};

/// Interpolated view-space data consumed by the pixel shader.
struct PixelInput {
    float4 position : SV_POSITION;
    float3 normal : NORMAL;
    float3 viewPosition : TEXCOORD0;
    nointerpolation uint kind : TEXCOORD1;
    nointerpolation uint instance : TEXCOORD2;
};

/// Position with a retained rounding residual for capsule intersection calculations.
struct AccuratePoint {
    float3 value;
    float3 error;
};

/// Analytic surface color and its exact projected depth.
struct AnalyticPixelOutput {
    float4 color : SV_TARGET;
    float depth : SV_DEPTH;
};

/// Rotates a vector around the X axis.
float3 RotateX(float3 p, float a) {
    float s, c;
    sincos(a, s, c);
    return float3(p.x, c * p.y - s * p.z, s * p.y + c * p.z);
}

/// Rotates a vector around the Y axis.
float3 RotateY(float3 p, float a) {
    float s, c;
    sincos(a, s, c);
    return float3(c * p.x + s * p.z, p.y, -s * p.x + c * p.z);
}

/// Rotates a vector around the Z axis.
float3 RotateZ(float3 p, float a) {
    float s, c;
    sincos(a, s, c);
    return float3(c * p.x - s * p.y, s * p.x + c * p.y, p.z);
}

/// Applies the simulation's ordered Euler rotations to a vector.
float3 Rotate(float3 value, float3 rotation) {
    return RotateZ(RotateY(RotateX(value, rotation.x), rotation.y), rotation.z);
}

/// Transforms one instanced mesh vertex from object space to clip space.
PixelInput VSMain(VertexInput input, uint copyInstance : SV_InstanceID) {
    PixelInput output;
    const uint instance = min(drawKind + copyInstance * 27u, 269u);
    const uint kind = min(drawKind, 26u);
    float4 placement = objectPositionAndScale[instance];
    float3 rotation = objectRotationAndKind[instance].xyz;
    const float3 world = Rotate(input.position * placement.w, rotation) + placement.xyz + float3(0.0, 0.0, drawZOffset);
    const float3 relative = world - cameraPosition.xyz;
    const float3 view = float3(dot(relative, cameraRight.xyz), dot(relative, cameraUp.xyz), dot(relative, cameraForward.xyz));
    const float nearPlane = 0.08;
    const float farPlane = 180.0;
    const float tangent = 0.64;
    output.position = float4(view.x / (tangent * screen.z), view.y / tangent,
        view.z * farPlane / (farPlane - nearPlane) - nearPlane * farPlane / (farPlane - nearPlane), view.z);
    const float3 worldNormal = Rotate(input.normal, rotation);
    output.normal = normalize(float3(dot(worldNormal, cameraRight.xyz), dot(worldNormal, cameraUp.xyz),
        dot(worldNormal, cameraForward.xyz)));
    output.viewPosition = view;
    output.kind = kind;
    output.instance = instance;
    return output;
}

/// Returns the stable sRGB material color assigned to one solid kind.
float3 ObjectColor(uint kind) {
    static const float3 colors[27] = {
        float3(0.88, 0.92, 1.00),
        float3(1.00, 0.53, 0.24),
        float3(0.91, 0.48, 1.00),
        float3(0.97, 0.36, 0.62),
        float3(0.56, 0.76, 1.00),
        float3(1.00, 0.40, 0.42),
        float3(0.40, 0.65, 1.00),
        float3(0.64, 1.00, 0.32),
        float3(0.87, 0.93, 1.00),
        float3(1.00, 0.40, 0.76),
        float3(0.71, 0.39, 1.00),
        float3(1.00, 0.63, 0.26),
        float3(1.00, 0.58, 0.16),
        float3(0.52, 0.98, 0.45),
        float3(0.28, 0.85, 1.00),
        float3(1.00, 0.70, 0.38),
        float3(1.00, 0.48, 0.32),
        float3(0.24, 0.82, 1.00),
        float3(0.30, 1.00, 0.69),
        float3(1.00, 0.80, 0.32),
        float3(0.30, 1.00, 0.78),
        float3(0.45, 0.88, 1.00),
        float3(0.42, 1.00, 0.62),
        float3(0.78, 0.52, 1.00),
        float3(1.00, 0.78, 0.38),
        float3(0.35, 1.00, 0.92),
        float3(0.39, 0.59, 1.00)
    };
    return colors[min(kind, 26u)];
}

/// Converts one sRGB material channel to linear light.
float LinearChannel(float value) {
    float converted = value / 12.92;
    if (value > 0.04045) {
        converted = pow((value + 0.055) / 1.055, 2.4);
    }
    return converted;
}

/// Converts a displayed material color to linear-light reflectance.
float3 LinearColor(float3 value) {
    return float3(LinearChannel(value.r), LinearChannel(value.g), LinearChannel(value.b));
}

/// Returns diffuse and specular response to one incident light direction.
float2 SurfaceLight(float3 normal, float3 view, float3 light) {
    const float3 halfVector = normalize(light + view);
    const float diffuse = saturate(dot(normal, light));
    const float specular = pow(saturate(dot(normal, halfVector)), 28.0);
    return float2(diffuse, specular);
}

/// Shades every solid in linear light with independently enabled key and fill illumination.
float4 ShadeSolid(float3 surfaceNormal, float3 viewPosition, uint kind) {
    float3 normal = normalize(surfaceNormal);
    if (dot(normal, -viewPosition) < 0.0) {
        normal = -normal;
    }
    const float3 light = normalize(lightDirection.xyz);
    const float3 view = normalize(-viewPosition);
    const float3 fillLight = normalize(float3(-light.x, -light.y, light.z));
    const float2 key = SurfaceLight(normal, view, light);
    const float2 fill = SurfaceLight(normal, view, fillLight);
    const float diffuse = key.x * lightSettings.x + fill.x * lightSettings.y;
    const float specular = key.y * lightSettings.x + fill.y * lightSettings.y;
    const float rim = pow(saturate(1.0 - abs(dot(normal, view))), 2.0);
    const float illumination = 0.16 + 0.78 * diffuse + 0.12 * rim;
    const float3 base = LinearColor(ObjectColor(kind));
    const float3 color = saturate(base * illumination + specular * 0.48);
    return float4(color, 1.0);
}

/// Shades triangle meshes using their interpolated positions and normals.
float4 PSMain(PixelInput input) : SV_TARGET {
    return ShadeSolid(input.normal, input.viewPosition, input.kind);
}

/// Transforms a direction or position from rotated world axes into object axes.
float3 InverseRotate(float3 value, float3 rotation) {
    return RotateX(RotateY(RotateZ(value, -rotation.z), -rotation.y), -rotation.x);
}

/// Adds two floats while retaining the rounding residual.
float2 AccurateSum(float left, float right) {
    precise float value = left + right;
    precise float tail = value - left;
    precise float leftError = left - (value - tail);
    precise float rightError = right - tail;
    precise float error = leftError + rightError;
    return float2(value, error);
}

/// Multiplies two floats while retaining the discarded product bits.
float2 AccurateProduct(float left, float right) {
    const float leftHigh = asfloat(asuint(left) & 0xfffff000u);
    const float rightHigh = asfloat(asuint(right) & 0xfffff000u);
    precise float leftLow = left - leftHigh;
    precise float rightLow = right - rightHigh;
    precise float value = left * right;
    precise float first = leftHigh * rightHigh - value;
    precise float second = first + leftHigh * rightLow;
    precise float third = second + leftLow * rightHigh;
    precise float error = third + leftLow * rightLow;
    return float2(value, error);
}

/// Advances a ray while retaining coordinate rounding instead of rounding the hit point early.
AccuratePoint AccurateRayPoint(AccuratePoint origin, float3 direction, float distance) {
    const float2 xProduct = AccurateProduct(direction.x, distance);
    const float2 yProduct = AccurateProduct(direction.y, distance);
    const float2 zProduct = AccurateProduct(direction.z, distance);
    const float2 xSum = AccurateSum(origin.value.x, xProduct.x);
    const float2 ySum = AccurateSum(origin.value.y, yProduct.x);
    const float2 zSum = AccurateSum(origin.value.z, zProduct.x);
    const float2 x = AccurateSum(xSum.x, origin.error.x + xProduct.y + xSum.y);
    const float2 y = AccurateSum(ySum.x, origin.error.y + yProduct.y + ySum.y);
    const float2 z = AccurateSum(zSum.x, origin.error.z + zProduct.y + zSum.y);
    AccuratePoint position;
    position.value = float3(x.x, y.x, z.x);
    position.error = float3(x.y, y.y, z.y);
    return position;
}

/// Returns the accurate offset from the capsule's defining segment.
AccuratePoint CapsuleOffset(AccuratePoint position) {
    const float segmentY = clamp(position.value.y, -capsuleHalfLength, capsuleHalfLength);
    const float2 difference = AccurateSum(position.value.y, -segmentY);
    const float2 height = AccurateSum(difference.x, position.error.y + difference.y);
    position.value.y = height.x;
    position.error.y = height.y;
    if (abs(segmentY) < capsuleHalfLength
            || segmentY == capsuleHalfLength && height.x <= 0.0
            || segmentY == -capsuleHalfLength && height.x >= 0.0) {
        position.value.y = 0.0;
        position.error.y = 0.0;
    }
    return position;
}

/// Evaluates squared distance minus squared radius without cancellation of rounded terms.
float AccurateDistanceEquation(AccuratePoint position, float radius) {
    const float2 x = AccurateProduct(position.value.x, position.value.x);
    const float2 y = AccurateProduct(position.value.y, position.value.y);
    const float2 z = AccurateProduct(position.value.z, position.value.z);
    const float2 radiusSquared = AccurateProduct(radius, radius);
    const float2 radial = AccurateSum(x.x, z.x);
    const float2 difference = AccurateSum(radial.x, -radiusSquared.x);
    const float2 total = AccurateSum(difference.x, y.x);
    precise float error = x.y + z.y + radial.y - radiusSquared.y + difference.y + y.y + total.y;
    const float2 corrected = AccurateSum(total.x, error);
    precise float displacement = 2.0 * dot(position.value, position.error) + dot(position.error, position.error);
    const float2 result = AccurateSum(corrected.x, displacement);
    return result.x + corrected.y + result.y;
}

/// Returns the closest ray parameter to the capsule's defining segment.
float CapsuleRayMinimum(AccuratePoint origin, float3 direction, float directionLengthSquared) {
    const float radialLengthSquared = dot(direction.xz, direction.xz);
    float segmentY = 0.0;
    if (radialLengthSquared > 0.0) {
        const float radialDistance = -dot(origin.value.xz, direction.xz) / radialLengthSquared;
        segmentY = clamp(origin.value.y + radialDistance * direction.y, -capsuleHalfLength, capsuleHalfLength);
    }
    return (segmentY * direction.y - dot(origin.value, direction)) / directionLengthSquared;
}

/// Solves the single capsule equation with retained coordinate and product rounding residuals.
float CapsuleBoundary(AccuratePoint origin, float3 direction, float outer, float inner) {
    const float lower = min(outer, inner);
    const float upper = max(outer, inner);
    [loop]
    for (int iteration = 0; iteration < 24; iteration++) {
        const AccuratePoint position = AccurateRayPoint(origin, direction, outer);
        const AccuratePoint offset = CapsuleOffset(position);
        const float value = AccurateDistanceEquation(offset, capsuleRadius);
        if (value <= 0.0) {
            break;
        }
        const float derivative = 2.0 * dot(offset.value + offset.error, direction);
        if (derivative == 0.0) {
            break;
        }
        const float next = clamp(outer - value / derivative, lower, upper);
        if (abs(next - outer) <= 0.000001) {
            outer = next;
            break;
        }
        outer = next;
    }
    return outer;
}

/// Intersects the exact distance-to-segment equation with one common geometric normal.
bool IntersectCapsule(float3 origin, float3 direction, out float nearest, out float3 normal) {
    nearest = 0.0;
    normal = float3(0.0, 0.0, 0.0);
    AccuratePoint source;
    source.value = origin;
    source.error = float3(0.0, 0.0, 0.0);
    const float directionLengthSquared = dot(direction, direction);
    const float centerDistance = -dot(origin, direction) / directionLengthSquared;
    const AccuratePoint centeredOrigin = AccurateRayPoint(source, direction, centerDistance);
    const float boundRadius = capsuleHalfLength + capsuleRadius;
    const float boundDiscriminant = -AccurateDistanceEquation(centeredOrigin, boundRadius);
    bool intersects = boundDiscriminant >= 0.0;
    if (intersects) {
        const float boundOffset = sqrt(boundDiscriminant / directionLengthSquared);
        const AccuratePoint originOffset = CapsuleOffset(source);
        const bool inside = AccurateDistanceEquation(originOffset, capsuleRadius) < 0.0;
        const float outer = inside ? boundOffset : max(-boundOffset, -centerDistance);
        float inner = -centerDistance;
        if (!inside) {
            inner = max(CapsuleRayMinimum(centeredOrigin, direction, directionLengthSquared), -centerDistance);
            const AccuratePoint closest = AccurateRayPoint(centeredOrigin, direction, inner);
            const AccuratePoint closestOffset = CapsuleOffset(closest);
            intersects = AccurateDistanceEquation(closestOffset, capsuleRadius) <= 0.0;
        }
        if (intersects) {
            const float boundary = CapsuleBoundary(centeredOrigin, direction, outer, inner);
            const AccuratePoint position = AccurateRayPoint(centeredOrigin, direction, boundary);
            const AccuratePoint offset = CapsuleOffset(position);
            nearest = centerDistance + boundary;
            normal = normalize(offset.value + offset.error);
            intersects = nearest > 0.0;
        }
    }
    return intersects;
}

/// Renders the exact analytic capsule surface and depth using the shared scene lighting.
AnalyticPixelOutput PSCapsuleMain(PixelInput input) {
    const float4 placement = objectPositionAndScale[input.instance];
    const float3 rotation = objectRotationAndKind[input.instance].xyz;
    const float3 center = placement.xyz + float3(0.0, 0.0, drawZOffset);
    const float3 viewRay = normalize(float3((2.0 * input.position.x / screen.x - 1.0) * 0.64 * screen.z,
        (1.0 - 2.0 * input.position.y / screen.y) * 0.64, 1.0));
    const float3 worldRay = normalize(viewRay.x * cameraRight.xyz + viewRay.y * cameraUp.xyz + viewRay.z * cameraForward.xyz);
    const float3 origin = InverseRotate(cameraPosition.xyz - center, rotation) / placement.w;
    const float3 direction = normalize(InverseRotate(worldRay, rotation));
    float distance;
    float3 localNormal;
    if (!IntersectCapsule(origin, direction, distance, localNormal)) {
        discard;
    }
    const float3 viewPosition = viewRay * distance * placement.w;
    const float nearPlane = 0.08;
    const float farPlane = 180.0;
    if (viewPosition.z < nearPlane || viewPosition.z > farPlane) {
        discard;
    }
    const float3 worldNormal = Rotate(localNormal, rotation);
    const float3 viewNormal = float3(dot(worldNormal, cameraRight.xyz), dot(worldNormal, cameraUp.xyz),
        dot(worldNormal, cameraForward.xyz));
    AnalyticPixelOutput output;
    output.color = ShadeSolid(viewNormal, viewPosition, input.kind);
    output.depth = farPlane / (farPlane - nearPlane) - nearPlane * farPlane / ((farPlane - nearPlane) * viewPosition.z);
    return output;
}
