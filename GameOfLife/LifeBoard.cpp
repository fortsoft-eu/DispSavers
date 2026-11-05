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

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "LifeBoard.h"
#include <algorithm>
#include <d3d10_1.h>
#include <iterator>
#include <limits>
#include <new>
#include "GameOfLifeVS.h"
#include "GameOfLifePS.h"
#include "GameOfLifeStepPS.h"
#include "GameOfLifeComparePS.h"

#pragma comment(lib, "d3d11.lib")

using Microsoft::WRL::ComPtr;

/// Compares rectangle coordinates for visible-region equality.
static bool RectanglesEqual(const RECT& left, const RECT& right) {
    return EqualRect(&left, &right) != FALSE;
}

/// Creates the Direct3D device and shaders, using WARP if hardware initialization fails.
bool LifeBoard::Initialize(D3D_DRIVER_TYPE driverType) {
    constexpr D3D_FEATURE_LEVEL levels[]{
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0
    };
    HRESULT result = D3D11CreateDevice(nullptr, driverType, nullptr, D3D11_CREATE_DEVICE_BGRA_SUPPORT,
        levels, static_cast<UINT>(std::size(levels)), D3D11_SDK_VERSION, &device, &featureLevel, &context);
    hardwareAccelerated = SUCCEEDED(result) && driverType == D3D_DRIVER_TYPE_HARDWARE;
    if (FAILED(result) && driverType == D3D_DRIVER_TYPE_HARDWARE) {
        device.Reset();
        context.Reset();
        result = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_WARP, nullptr,
            D3D11_CREATE_DEVICE_BGRA_SUPPORT, levels, static_cast<UINT>(std::size(levels)),
            D3D11_SDK_VERSION, &device, &featureLevel, &context);
    }
    return SUCCEEDED(result) && CreatePipeline();
}

/// Returns the borrowed Direct3D device used by every view of this world.
ID3D11Device* LifeBoard::Device() const {
    return device.Get();
}

/// Unbinds render targets before an output releases or resizes its back buffer.
void LifeBoard::UnbindTargets() {
    context->OMSetRenderTargets(0, nullptr, nullptr);
}

/// Creates the display and generation shaders, constant buffer and rasterizer state.
bool LifeBoard::CreatePipeline() {
    if (FAILED(device->CreateVertexShader(GameOfLifeVertexShader,
        sizeof(GameOfLifeVertexShader), nullptr, &vertexShader))
            || FAILED(device->CreatePixelShader(GameOfLifePixelShader,
                sizeof(GameOfLifePixelShader), nullptr, &pixelShader))
            || FAILED(device->CreatePixelShader(GameOfLifeStepPixelShader,
                sizeof(GameOfLifeStepPixelShader), nullptr, &stepShader))) {
        return false;
    }
    D3D11_BUFFER_DESC buffer{};
    buffer.ByteWidth = sizeof(ShaderConstants);
    buffer.Usage = D3D11_USAGE_DEFAULT;
    buffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    D3D11_RASTERIZER_DESC raster{};
    raster.FillMode = D3D11_FILL_SOLID;
    raster.CullMode = D3D11_CULL_NONE;
    raster.DepthClipEnable = TRUE;
    return SUCCEEDED(device->CreateBuffer(&buffer, nullptr, &constants))
        && SUCCEEDED(device->CreateRasterizerState(&raster, &rasterizer));
}

/// Validates and uploads cells into both GPU buffers, then restarts cycle detection.
bool LifeBoard::SetBoard(unsigned newColumns, unsigned newRows, const std::vector<std::uint8_t>& cells) {
    if (!device
            || newColumns == 0
            || newRows == 0
            || newColumns > MaximumBoardDimension()
            || newRows > MaximumBoardDimension()
            || cells.size() != static_cast<std::size_t>(newColumns) * newRows) {
        return false;
    }
    std::vector<std::uint8_t> normalized(cells.size());
    std::transform(cells.begin(), cells.end(), normalized.begin(), [](std::uint8_t value) {
        return static_cast<std::uint8_t>(value ? 255 : 0);
    });
    D3D11_TEXTURE2D_DESC description{};
    description.Width = newColumns;
    description.Height = newRows;
    description.MipLevels = 1;
    description.ArraySize = 1;
    description.Format = DXGI_FORMAT_R8_UNORM;
    description.SampleDesc.Count = 1;
    description.Usage = D3D11_USAGE_DEFAULT;
    description.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
    D3D11_SUBRESOURCE_DATA data{};
    data.pSysMem = normalized.data();
    data.SysMemPitch = newColumns;
    std::array<ComPtr<ID3D11Texture2D>, 2> newBoards;
    std::array<ComPtr<ID3D11ShaderResourceView>, 2> newViews;
    std::array<ComPtr<ID3D11RenderTargetView>, 2> newTargets;
    for (unsigned index = 0; index < newBoards.size(); ++index) {
        if (FAILED(device->CreateTexture2D(&description, &data, &newBoards[index]))
            || FAILED(device->CreateShaderResourceView(newBoards[index].Get(), nullptr, &newViews[index]))
            || FAILED(device->CreateRenderTargetView(newBoards[index].Get(), nullptr,
                &newTargets[index]))) {
            return false;
        }
    }
    context->OMSetRenderTargets(0, nullptr, nullptr);
    ID3D11ShaderResourceView* empty = nullptr;
    context->PSSetShaderResources(0, 1, &empty);
    boards = std::move(newBoards);
    boardViews = std::move(newViews);
    boardTargets = std::move(newTargets);
    columns = newColumns;
    rows = newRows;
    currentBoard = 0;
    resetRequested = false;
    cycleError = autoReset ? InitializeCycleDetection() : S_OK;
    return SUCCEEDED(cycleError);
}

/// Returns the texture-dimension limit of the initialized Direct3D feature level.
unsigned LifeBoard::MaximumBoardDimension() const {
    return featureLevel >= D3D_FEATURE_LEVEL_11_0
        ? D3D11_REQ_TEXTURE2D_U_OR_V_DIMENSION
        : D3D10_REQ_TEXTURE2D_U_OR_V_DIMENSION;
}

/// Updates cell spacing and rebuilds the visible-cell mask when cycle detection is enabled.
void LifeBoard::SetCellSize(unsigned size) {
    size = std::max(1U, size);
    if (shaderConstants.cellSize == size) {
        return;
    }
    shaderConstants.cellSize = size;
    if (autoReset) {
        cycleError = InitializeCycleDetection();
    }
}

/// Updates live-cell and background shader colors without changing the simulation.
void LifeBoard::SetColors(COLORREF aliveColor, COLORREF backgroundColor) {
    shaderConstants.alive = {
        GetRValue(aliveColor) / 255.0f,
        GetGValue(aliveColor) / 255.0f,
        GetBValue(aliveColor) / 255.0f,
        1.0f
    };
    shaderConstants.background = {
        GetRValue(backgroundColor) / 255.0f,
        GetGValue(backgroundColor) / 255.0f,
        GetBValue(backgroundColor) / 255.0f,
        1.0f
    };
}

/// Updates grid visibility and color without changing cell contents or board dimensions.
void LifeBoard::SetGrid(bool visible, COLORREF color) {
    shaderConstants.gridVisible = visible ? 1U : 0U;
    shaderConstants.grid = {
        GetRValue(color) / 255.0f,
        GetGValue(color) / 255.0f,
        GetBValue(color) / 255.0f,
        1.0f
    };
}

/// Enables cycle tracking or releases its GPU resources, clearing any previous reset request.
bool LifeBoard::SetAutoReset(bool enabled) {
    if (autoReset == enabled) {
        return SUCCEEDED(cycleError);
    }
    autoReset = enabled;
    resetRequested = false;
    cycleError = S_OK;
    if (enabled) {
        cycleError = InitializeCycleDetection();
    } else {
        cycleCheckpointView.Reset();
        cycleCheckpoint.Reset();
        recentCheckpointView.Reset();
        recentCheckpoint.Reset();
        visibleMaskView.Reset();
        visibleMask.Reset();
        compareShader.Reset();
        for (Microsoft::WRL::ComPtr<ID3D11Query>& query : cycleQueries) {
            query.Reset();
        }
        cycleReadIndex = 0;
        cyclePending = 0;
        cyclePower = 1;
        cycleLength = 0;
        recentCycleLength = 0;
    }
    return SUCCEEDED(cycleError);
}

/// Updates the displayed monitor regions used to exclude invisible cells from comparisons.
bool LifeBoard::SetVisibleRegions(const RECT& worldBounds, const std::vector<RECT>& regions) {
    if (visibleRegionsConfigured
        && EqualRect(&visibleWorld, &worldBounds)
        && std::equal(visibleRegions.begin(), visibleRegions.end(), regions.begin(), regions.end(),
            RectanglesEqual)) {
        return SUCCEEDED(cycleError);
    }
    try {
        visibleRegions = regions;
    } catch (const std::bad_alloc&) {
        cycleError = E_OUTOFMEMORY;
        return false;
    }
    visibleWorld = worldBounds;
    visibleRegionsConfigured = true;
    resetRequested = false;
    if (autoReset) {
        cycleError = InitializeCycleDetection();
    }
    return SUCCEEDED(cycleError);
}

/// Reports whether an asynchronous comparison detected a repeated visible phase.
bool LifeBoard::ResetRequested() const {
    return resetRequested;
}

/// Creates visible-cell masks, phase checkpoints and asynchronous difference queries.
HRESULT LifeBoard::InitializeCycleDetection() {
    if (!boards[0]) {
        return S_OK;
    }
    D3D11_TEXTURE2D_DESC description{};
    boards[currentBoard]->GetDesc(&description);
    description.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    cycleCheckpointView.Reset();
    cycleCheckpoint.Reset();
    recentCheckpointView.Reset();
    recentCheckpoint.Reset();
    visibleMaskView.Reset();
    visibleMask.Reset();
    HRESULT result = device->CreateTexture2D(&description, nullptr, &cycleCheckpoint);
    if (SUCCEEDED(result)) {
        result = device->CreateShaderResourceView(cycleCheckpoint.Get(), nullptr, &cycleCheckpointView);
    }
    if (SUCCEEDED(result)) {
        result = device->CreateTexture2D(&description, nullptr, &recentCheckpoint);
    }
    if (SUCCEEDED(result)) {
        result = device->CreateShaderResourceView(recentCheckpoint.Get(), nullptr, &recentCheckpointView);
    }
    std::vector<std::uint8_t> mask;
    try {
        mask.assign(static_cast<std::size_t>(columns) * rows, visibleRegionsConfigured ? 0 : 255);
    } catch (const std::bad_alloc&) {
        return E_OUTOFMEMORY;
    }
    if (visibleRegionsConfigured) {
        const unsigned size = shaderConstants.cellSize;
        for (const RECT& region : visibleRegions) {
            const LONG left = std::max(region.left, visibleWorld.left);
            const LONG top = std::max(region.top, visibleWorld.top);
            const LONG right = std::min(region.right, visibleWorld.right);
            const LONG bottom = std::min(region.bottom, visibleWorld.bottom);
            if (left >= right || top >= bottom) {
                continue;
            }
            const unsigned firstColumn =
                std::min(columns, static_cast<unsigned>(left - visibleWorld.left) / size);
            const unsigned firstRow = std::min(rows, static_cast<unsigned>(top - visibleWorld.top) / size);
            const unsigned lastColumn =
                std::min(columns, (static_cast<unsigned>(right - visibleWorld.left) + size - 1) / size);
            const unsigned lastRow = std::min(rows,
                (static_cast<unsigned>(bottom - visibleWorld.top) + size - 1) / size);
            for (unsigned row = firstRow; row < lastRow; ++row) {
                const std::size_t offset = static_cast<std::size_t>(row) * columns;
                std::fill(mask.begin() + offset + firstColumn, mask.begin() + offset + lastColumn,
                    std::uint8_t{ 255 });
            }
        }
    }
    D3D11_SUBRESOURCE_DATA data{ mask.data(), columns, 0 };
    if (SUCCEEDED(result)) {
        result = device->CreateTexture2D(&description, &data, &visibleMask);
    }
    if (SUCCEEDED(result)) {
        result = device->CreateShaderResourceView(visibleMask.Get(), nullptr, &visibleMaskView);
    }
    if (SUCCEEDED(result) && !compareShader) {
        result = device->CreatePixelShader(GameOfLifeComparePixelShader,
            sizeof(GameOfLifeComparePixelShader), nullptr, &compareShader);
    }
    const D3D11_QUERY_DESC queryDescription{ D3D11_QUERY_OCCLUSION, 0 };
    for (Microsoft::WRL::ComPtr<ID3D11Query>& query : cycleQueries) {
        if (SUCCEEDED(result) && !query) {
            result = device->CreateQuery(&queryDescription, &query);
        }
    }
    if (FAILED(result)) {
        return result;
    }
    context->CopyResource(cycleCheckpoint.Get(), boards[currentBoard].Get());
    context->CopyResource(recentCheckpoint.Get(), boards[currentBoard].Get());
    cycleReadIndex = 0;
    cyclePending = 0;
    cyclePower = 1;
    cycleLength = 0;
    recentCycleLength = 0;
    resetRequested = false;
    return S_OK;
}

/// Consumes completed GPU comparisons without forcing a flush and flags repeated phases.
HRESULT LifeBoard::PollCycleQueries() {
    while (cyclePending != 0) {
        UINT64 differences = 0;
        const HRESULT result = context->GetData(cycleQueries[cycleReadIndex].Get(), &differences,
            sizeof(differences), D3D11_ASYNC_GETDATA_DONOTFLUSH);
        if (result == S_FALSE) {
            break;
        }
        if (FAILED(result)) {
            cycleError = result;
            return result;
        }
        cycleReadIndex = (cycleReadIndex + 1) % CYCLE_QUERY_COUNT;
        --cyclePending;
        if (differences == 0) {
            resetRequested = true;
            break;
        }
    }
    return S_OK;
}

/// Counts visible-cell differences from one checkpoint using an occlusion query.
void LifeBoard::QueueCycleComparison(ID3D11ShaderResourceView* reference) {
    const unsigned queryIndex = (cycleReadIndex + cyclePending) % CYCLE_QUERY_COUNT;
    ID3D11RenderTargetView* target = boardTargets[1 - currentBoard].Get();
    context->OMSetRenderTargets(1, &target, nullptr);
    ID3D11ShaderResourceView* views[]{ boardViews[currentBoard].Get(), reference, visibleMaskView.Get() };
    context->PSSetShaderResources(0, 3, views);
    context->PSSetShader(compareShader.Get(), nullptr, 0);
    context->Begin(cycleQueries[queryIndex].Get());
    context->Draw(3, 0);
    context->End(cycleQueries[queryIndex].Get());
    ID3D11ShaderResourceView* empty[]{ nullptr, nullptr, nullptr };
    context->PSSetShaderResources(0, 3, empty);
    context->OMSetRenderTargets(0, nullptr, nullptr);
    ++cyclePending;
}

/// Queues recent and expanding-checkpoint comparisons and advances their generation counters.
void LifeBoard::CompareCycleState() {
    QueueCycleComparison(cycleCheckpointView.Get());
    QueueCycleComparison(recentCheckpointView.Get());
    ++cycleLength;
    if (cycleLength == cyclePower) {
        context->CopyResource(cycleCheckpoint.Get(), boards[currentBoard].Get());
        constexpr std::uint64_t maximum = std::numeric_limits<std::uint64_t>::max();
        cyclePower = cyclePower <= maximum / 2 ? cyclePower * 2 : maximum;
        cycleLength = 0;
    }
    ++recentCycleLength;
    if (recentCycleLength == RECENT_CYCLE_LENGTH) {
        context->CopyResource(recentCheckpoint.Get(), boards[currentBoard].Get());
        recentCycleLength = 0;
    }
}

/// Binds board constants, viewport, rasterizer and the full-screen triangle vertex shader.
void LifeBoard::SetPipeline(unsigned outputWidth, unsigned outputHeight) {
    shaderConstants.columns = columns;
    shaderConstants.rows = rows;
    context->UpdateSubresource(constants.Get(), 0, nullptr, &shaderConstants, 0, 0);
    ID3D11Buffer* buffer = constants.Get();
    context->PSSetConstantBuffers(0, 1, &buffer);
    D3D11_VIEWPORT viewport{};
    viewport.Width = static_cast<float>(outputWidth);
    viewport.Height = static_cast<float>(outputHeight);
    viewport.MaxDepth = 1.0f;
    context->RSSetViewports(1, &viewport);
    context->RSSetState(rasterizer.Get());
    context->IASetInputLayout(nullptr);
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    context->VSSetShader(vertexShader.Get(), nullptr, 0);
}

/// Advances GPU generations and submits visible-phase comparisons when automatic reset is enabled.
/// Returns S_FALSE when no board exists, a reset is pending or comparison queries have filled the queue.
HRESULT LifeBoard::Advance(unsigned generations) {
    if (FAILED(cycleError)) {
        return cycleError;
    }
    if (!boards[0]) {
        return S_FALSE;
    }
    if (autoReset) {
        const HRESULT result = PollCycleQueries();
        if (FAILED(result)) {
            return result;
        }
        if (resetRequested) {
            return S_FALSE;
        }
    }
    if (generations == 0) {
        return S_OK;
    }
    SetPipeline(columns, rows);
    for (unsigned generation = 0; generation < generations; ++generation) {
        if (autoReset && CYCLE_QUERY_COUNT - cyclePending < CYCLE_COMPARISONS_PER_GENERATION) {
            return S_FALSE;
        }
        context->PSSetShader(stepShader.Get(), nullptr, 0);
        ID3D11ShaderResourceView* empty = nullptr;
        context->PSSetShaderResources(0, 1, &empty);
        ID3D11RenderTargetView* target = boardTargets[1 - currentBoard].Get();
        context->OMSetRenderTargets(1, &target, nullptr);
        ID3D11ShaderResourceView* view = boardViews[currentBoard].Get();
        context->PSSetShaderResources(0, 1, &view);
        context->Draw(3, 0);
        context->PSSetShaderResources(0, 1, &empty);
        context->OMSetRenderTargets(0, nullptr, nullptr);
        currentBoard = 1 - currentBoard;
        if (autoReset) {
            CompareCycleState();
        }
    }
    return S_OK;
}

/// Copies the current GPU board into normalized CPU cells through a staging texture.
bool LifeBoard::ReadCells(std::vector<std::uint8_t>& cells) const {
    if (!boards[currentBoard]) {
        return false;
    }
    D3D11_TEXTURE2D_DESC description{};
    boards[currentBoard]->GetDesc(&description);
    description.BindFlags = 0;
    description.Usage = D3D11_USAGE_STAGING;
    description.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
    ComPtr<ID3D11Texture2D> staging;
    if (FAILED(device->CreateTexture2D(&description, nullptr, &staging))) {
        return false;
    }
    context->CopyResource(staging.Get(), boards[currentBoard].Get());
    D3D11_MAPPED_SUBRESOURCE mapped{};
    if (FAILED(context->Map(staging.Get(), 0, D3D11_MAP_READ, 0, &mapped))) {
        return false;
    }
    cells.resize(static_cast<std::size_t>(columns) * rows);
    for (unsigned row = 0; row < rows; ++row) {
        const std::uint8_t* source = static_cast<const std::uint8_t*>(mapped.pData) + row * mapped.RowPitch;
        for (unsigned column = 0; column < columns; ++column) {
            cells[static_cast<std::size_t>(row) * columns + column] = source[column] != 0;
        }
    }
    context->Unmap(staging.Get(), 0);
    return true;
}

/// Draws one monitor view of the shared world into the supplied render target.
void LifeBoard::DrawTo(ID3D11RenderTargetView* target, unsigned width, unsigned height,
        const RECT& worldBounds, const RECT& viewBounds) {
    if (!target || !boards[0] || width == 0 || height == 0) {
        return;
    }
    const float worldWidth = static_cast<float>(worldBounds.right - worldBounds.left);
    const float worldHeight = static_cast<float>(worldBounds.bottom - worldBounds.top);
    if (worldWidth <= 0.0f || worldHeight <= 0.0f) {
        return;
    }
    shaderConstants.view = {
        static_cast<float>(viewBounds.left - worldBounds.left),
        static_cast<float>(viewBounds.top - worldBounds.top),
        static_cast<float>(viewBounds.right - viewBounds.left),
        static_cast<float>(viewBounds.bottom - viewBounds.top)
    };
    SetPipeline(width, height);
    context->OMSetRenderTargets(1, &target, nullptr);
    ID3D11ShaderResourceView* view = boardViews[currentBoard].Get();
    context->PSSetShaderResources(0, 1, &view);
    context->PSSetShader(pixelShader.Get(), nullptr, 0);
    context->Draw(3, 0);
    ID3D11ShaderResourceView* empty = nullptr;
    context->PSSetShaderResources(0, 1, &empty);
    context->OMSetRenderTargets(0, nullptr, nullptr);
}

/// Reports whether the board device uses the hardware Direct3D driver.
bool LifeBoard::IsHardwareAccelerated() const {
    return hardwareAccelerated;
}
