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

#pragma once

#include <windows.h>
#include <d3d11.h>
#include <wrl/client.h>
#include <array>
#include <cstdint>
#include <vector>

 /// Shared GPU cellular world with wrapped edges and visible-phase cycle detection.
class LifeBoard final {

private:
    static constexpr unsigned CYCLE_QUERY_COUNT = 16;
    static constexpr unsigned CYCLE_COMPARISONS_PER_GENERATION = 2;
    static constexpr unsigned RECENT_CYCLE_LENGTH = 32;

    /// Board dimensions, cell appearance and view bounds shared with HLSL shaders.
    struct ShaderConstants {
        unsigned columns = 0;
        unsigned rows = 0;
        unsigned cellSize = 1;
        unsigned gridVisible = 0;
        std::array<float, 4> alive{ 0.18f, 0.9f, 0.35f, 1.0f };
        std::array<float, 4> background{ 0.0f, 0.0f, 0.0f, 1.0f };
        std::array<float, 4> view{ 0.0f, 0.0f, 1.0f, 1.0f };
        std::array<float, 4> grid{ 48.0f / 255.0f, 48.0f / 255.0f, 48.0f / 255.0f, 1.0f };
    };

    static_assert(sizeof(ShaderConstants) == 80);

    Microsoft::WRL::ComPtr<ID3D11Device> device;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> context;
    Microsoft::WRL::ComPtr<ID3D11VertexShader> vertexShader;
    Microsoft::WRL::ComPtr<ID3D11PixelShader> pixelShader;
    Microsoft::WRL::ComPtr<ID3D11PixelShader> stepShader;
    Microsoft::WRL::ComPtr<ID3D11PixelShader> compareShader;
    Microsoft::WRL::ComPtr<ID3D11Buffer> constants;
    Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizer;
    std::array<Microsoft::WRL::ComPtr<ID3D11Texture2D>, 2> boards;
    std::array<Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>, 2> boardViews;
    std::array<Microsoft::WRL::ComPtr<ID3D11RenderTargetView>, 2> boardTargets;
    Microsoft::WRL::ComPtr<ID3D11Texture2D> cycleCheckpoint;
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> cycleCheckpointView;
    Microsoft::WRL::ComPtr<ID3D11Texture2D> recentCheckpoint;
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> recentCheckpointView;
    Microsoft::WRL::ComPtr<ID3D11Texture2D> visibleMask;
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> visibleMaskView;
    std::array<Microsoft::WRL::ComPtr<ID3D11Query>, CYCLE_QUERY_COUNT> cycleQueries;
    RECT visibleWorld{};
    std::vector<RECT> visibleRegions;
    std::uint64_t cyclePower = 1;
    std::uint64_t cycleLength = 0;
    HRESULT cycleError = S_OK;
    unsigned cycleReadIndex = 0;
    unsigned cyclePending = 0;
    unsigned recentCycleLength = 0;
    bool autoReset = false;
    bool resetRequested = false;
    bool visibleRegionsConfigured = false;
    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_10_0;
    ShaderConstants shaderConstants;
    bool hardwareAccelerated = false;
    unsigned currentBoard = 0;
    unsigned columns = 0;
    unsigned rows = 0;

    /// Creates the display and generation shaders, constant buffer and rasterizer state.
    bool CreatePipeline();

    /// Binds board constants, viewport, rasterizer and the full-screen triangle vertex shader.
    void SetPipeline(unsigned outputWidth, unsigned outputHeight);

    /// Creates visible-cell masks, phase checkpoints and asynchronous difference queries.
    HRESULT InitializeCycleDetection();

    /// Consumes completed GPU comparisons without forcing a flush and flags repeated phases.
    HRESULT PollCycleQueries();

    /// Counts visible-cell differences from one checkpoint using an occlusion query.
    void QueueCycleComparison(ID3D11ShaderResourceView* reference);

    /// Queues recent and expanding-checkpoint comparisons and advances their generation counters.
    void CompareCycleState();

public:
    /// Creates the Direct3D device and shaders, using WARP if hardware initialization fails.
    bool Initialize(D3D_DRIVER_TYPE driverType = D3D_DRIVER_TYPE_HARDWARE);

    /// Returns the borrowed Direct3D device used by every view of this world.
    ID3D11Device* Device() const;

    /// Unbinds render targets before an output releases or resizes its back buffer.
    void UnbindTargets();

    /// Validates and uploads cells into both GPU buffers, then restarts cycle detection.
    bool SetBoard(unsigned newColumns, unsigned newRows, const std::vector<std::uint8_t>& cells);

    /// Advances GPU generations and submits visible-phase comparisons when automatic reset is enabled.
    /// Returns S_FALSE when no board exists, a reset is pending or comparison queries have filled the queue.
    HRESULT Advance(unsigned generations = 1);

    /// Draws one monitor view of the shared world into the supplied render target.
    void DrawTo(ID3D11RenderTargetView* target, unsigned width, unsigned height,
        const RECT& worldBounds, const RECT& viewBounds);

    /// Updates cell spacing and rebuilds the visible-cell mask when cycle detection is enabled.
    void SetCellSize(unsigned size);

    /// Updates live-cell and background shader colors without changing the simulation.
    void SetColors(COLORREF aliveColor, COLORREF backgroundColor);

    /// Updates grid visibility and color without changing cell contents or board dimensions.
    void SetGrid(bool visible, COLORREF color);

    /// Enables cycle tracking or releases its GPU resources, clearing any previous reset request.
    bool SetAutoReset(bool enabled);

    /// Updates the displayed monitor regions used to exclude invisible cells from comparisons.
    bool SetVisibleRegions(const RECT& worldBounds, const std::vector<RECT>& regions);

    /// Reports whether an asynchronous comparison detected a repeated visible phase.
    bool ResetRequested() const;

    /// Copies the current GPU board into normalized CPU cells through a staging texture.
    bool ReadCells(std::vector<std::uint8_t>& cells) const;

    /// Returns the texture-dimension limit of the initialized Direct3D feature level.
    unsigned MaximumBoardDimension() const;

    /// Reports whether the board device uses the hardware Direct3D driver.
    bool IsHardwareAccelerated() const;
};
