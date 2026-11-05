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
#include "MonitorLayout.h"
#include <algorithm>
#include <utility>

using MonitorInterval = std::pair<LONG, LONG>;

/// Merges occupied monitor intervals along one axis, including touching intervals.
static std::vector<MonitorInterval> MonitorIntervals(const std::vector<RECT>& bounds, bool horizontal) {
    std::vector<MonitorInterval> intervals;
    for (const RECT& rect : bounds) {
        intervals.push_back(MonitorInterval{ horizontal ? rect.left : rect.top,
            horizontal ? rect.right : rect.bottom });
    }
    std::sort(intervals.begin(), intervals.end());
    std::vector<MonitorInterval> merged;
    for (const MonitorInterval& interval : intervals) {
        if (!merged.empty() && interval.first <= merged.back().second) {
            merged.back().second = std::max(merged.back().second, interval.second);
        } else {
            merged.push_back(interval);
        }
    }
    return merged;
}

/// Maps a physical coordinate into the layout, optionally removing completely unused axis gaps.
static LONG LogicalCoordinate(LONG coordinate, const std::vector<MonitorInterval>& intervals, bool compact) {
    if (!compact) {
        return coordinate - intervals.front().first;
    }
    LONG logical = 0;
    for (const MonitorInterval& interval : intervals) {
        if (coordinate <= interval.second) {
            return logical + std::max(0L, coordinate - interval.first);
        }
        logical += interval.second - interval.first;
    }
    return logical;
}

/// Maps selected monitor rectangles into one world while retaining holes that cannot be collapsed.
std::vector<MonitorViewport> BuildMonitorLayout(const std::vector<RECT>& bounds, bool compact) {
    std::vector<MonitorViewport> viewports;
    if (bounds.empty()) {
        return viewports;
    }
    const std::vector<MonitorInterval> horizontal = MonitorIntervals(bounds, true);
    const std::vector<MonitorInterval> vertical = MonitorIntervals(bounds, false);
    for (const RECT& physical : bounds) {
        const RECT logical{
            LogicalCoordinate(physical.left, horizontal, compact),
            LogicalCoordinate(physical.top, vertical, compact),
            LogicalCoordinate(physical.right, horizontal, compact),
            LogicalCoordinate(physical.bottom, vertical, compact)
        };
        viewports.push_back(MonitorViewport{ physical, logical });
    }
    return viewports;
}

/// Returns the bounding rectangle of all logical monitor viewports.
RECT MonitorLayoutBounds(const std::vector<MonitorViewport>& viewports) {
    RECT bounds{};
    for (const MonitorViewport& viewport : viewports) {
        bounds.right = std::max(bounds.right, viewport.logical.right);
        bounds.bottom = std::max(bounds.bottom, viewport.logical.bottom);
    }
    return bounds;
}
