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
 * Last modified for version 1.3.0.0
 */

/// Board dimensions, cell spacing and colors matching LifeBoard::ShaderConstants.
/// The view contains the monitor origin and size in pixels relative to the shared world.
cbuffer BoardConstants : register(b0) {
    uint columns;
    uint rows;
    uint cellSize;
    uint gridVisible;
    float4 aliveColor;
    float4 backgroundColor;
    float4 view;
    float4 gridColor;
};

/// Current generation stored as normalized cell values: zero for dead and one for alive.
Texture2D<float> board : register(t0);
/// Saved generation used as the reference for an asynchronous cycle comparison.
Texture2D<float> checkpoint : register(t1);
/// Marks cells intersecting displayed monitor regions for cycle comparisons only.
Texture2D<float> visibleMask : register(t2);

/// Full-screen triangle position and coordinates interpolated across the output viewport.
struct VertexOutput {
    float4 position : SV_POSITION;
    float2 uv : TEXCOORD0;
};

/// Generates a full-screen triangle from vertex IDs without a vertex buffer.
VertexOutput VSMain(uint vertexId : SV_VertexID) {
    VertexOutput output;
    output.uv = float2(vertexId << 1 & 2, vertexId & 2);
    output.position = float4(output.uv * float2(2.0f, -2.0f) + float2(-1.0f, 1.0f), 0.0f, 1.0f);
    return output;
}

/// Reads a cell or its immediate neighbor, wrapping across the joined edges of the board.
uint AliveAt(int2 cell) {
    const int x = cell.x < 0 ? int(columns) - 1 : cell.x >= int(columns) ? 0 : cell.x;
    const int y = cell.y < 0 ? int(rows) - 1 : cell.y >= int(rows) ? 0 : cell.y;
    return board.Load(int3(x, y, 0)) > 0.5f ? 1 : 0;
}

/// Advances one generation: three neighbors cause birth, and two or three keep a live cell alive.
float StepPS(VertexOutput input) : SV_TARGET {
    const int2 cell = int2(input.position.xy);
    const uint neighbors = AliveAt(cell + int2(-1, -1)) + AliveAt(cell + int2(0, -1))
        + AliveAt(cell + int2(1, -1)) + AliveAt(cell + int2(-1, 0)) + AliveAt(cell + int2(1, 0))
        + AliveAt(cell + int2(-1, 1)) + AliveAt(cell + int2(0, 1)) + AliveAt(cell + int2(1, 1));
    return neighbors == 3 || neighbors == 2 && AliveAt(cell) != 0 ? 1.0f : 0.0f;
}

/// Draws the monitor view using live-cell and background colors, with an optional one-pixel grid.
float4 PSMain(VertexOutput input) : SV_TARGET {
    const float2 worldPosition = view.xy + input.uv * view.zw;
    const uint2 cell = min(uint2(worldPosition / float(cellSize)), uint2(columns - 1, rows - 1));
    const float2 cellPosition = worldPosition - float2(cell) * float(cellSize);
    if (gridVisible != 0 && cellSize > 1 && (cellPosition.x < 1.0f || cellPosition.y < 1.0f)) {
        return gridColor;
    }
    const float alive = board.Load(int3(cell, 0));
    return lerp(backgroundColor, aliveColor, alive);
}

/// Discards hidden and unchanged cells so an occlusion query counts differences from the saved phase.
float ComparePS(VertexOutput input) : SV_TARGET {
    const int3 cell = int3(int2(input.position.xy), 0);
    if (visibleMask.Load(cell) < 0.5f || board.Load(cell) == checkpoint.Load(cell)) {
        discard;
    }
    return 0.0f;
}
