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
 * Last modified for version 1.1.0.0
 */

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "Mp4Recorder.h"
#include <d3d11.h>
#include <mfapi.h>
#include <mferror.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <wrl/client.h>
#include <algorithm>
#include <atomic>
#include <array>
#include <condition_variable>
#include <cstdint>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <string>
#include <thread>

#pragma comment(lib, "mfplat.lib")
#pragma comment(lib, "mfreadwrite.lib")
#pragma comment(lib, "mfuuid.lib")

using Microsoft::WRL::ComPtr;
using CopyImageFunction = HRESULT(WINAPI*)(BYTE*, LONG, const BYTE*, LONG, DWORD, DWORD);

/// Media Foundation time-base constant
constexpr LONGLONG MEDIA_FOUNDATION_UNITS_PER_SECOND = 10000000;

/// Windows libraries providing image copying on current and older systems
constexpr wchar_t MEDIA_FOUNDATION_LIBRARY[] = L"mfplat.dll";
constexpr wchar_t VIDEO_RENDERER_LIBRARY[] = L"evr.dll";
constexpr char COPY_IMAGE_FUNCTION[] = "MFCopyImage";
constexpr wchar_t RECORDING_TEST_PREFIX[] = L"FSP";

/// Preserves Emulators' no-blending exception for NTSC output on a 60 Hz monitor.
void RecordingFormat::SetMonitorRate(unsigned rate, unsigned divisor) {
    temporalBlend = !(std::uint64_t(rate) * denominator % (std::uint64_t(numerator) * divisor) == 0
        || std::uint64_t(rate) == std::uint64_t(60) * divisor && denominator == 1001 && (numerator == 60000
            || numerator == 30000));
}

/// Derives each boundary directly from its frame index without accumulating rounding errors.
std::uint64_t RecordingFormat::Boundary(std::uint64_t frame, std::uint64_t units) const {
    return frame / numerator * denominator * units + frame % numerator * denominator * units / numerator;
}

/// Returns a sample boundary in Media Foundation's 100-nanosecond units.
std::uint64_t RecordingFormat::Time(std::uint64_t frame) const {
    return Boundary(frame, 10000000);
}

/// Returns the last output slot reached by the recording clock.
std::uint64_t RecordingFormat::FramesAt(std::uint64_t units) const {
    const std::uint64_t period = 10000000ULL * denominator;
    return units / period * numerator + units % period * numerator / period;
}

/// Fits the complete source image into the output while preserving its displayed aspect ratio.
RECT RecordingFormat::Viewport(POINT base) const {
    const double pixelWidth = double(base.x) * aspectY / aspectX;
    const double scale = std::min(width / pixelWidth, double(height) / base.y);
    const LONG viewportWidth = std::clamp(LONG(std::lround(pixelWidth * scale)), 1L, LONG(width));
    const LONG viewportHeight = std::clamp(LONG(std::lround(base.y * scale)), 1L, LONG(height));
    const LONG left = (LONG(width) - viewportWidth) / 2;
    const LONG top = (LONG(height) - viewportHeight) / 2;
    return RECT{
        left,
        top,
        left + viewportWidth,
        top + viewportHeight
    };
}

/// Selects Emulators' TV presets or the unchanged viewport and monitor-rate recording format.
RecordingFormat RecordingOptions::Format(unsigned nativeWidth, unsigned nativeHeight, unsigned nativeRate) const {
    RecordingFormat format;
    format.width = nativeWidth;
    format.height = nativeHeight;
    format.numerator = std::clamp(nativeRate, 1U, 60U);
    if (!television) {
        return format;
    }
    format.television = true;
    constexpr unsigned widths[]{
        1920,
        1440,
        1280
    };
    constexpr unsigned heights[]{
        1080,
        1080,
        720
    };
    const int selectedResolution = std::clamp(resolution, 0, 2);
    format.width = widths[selectedResolution];
    format.height = heights[selectedResolution];
    if (selectedResolution == 1) {
        format.aspectX = 4;
        format.aspectY = 3;
    }
    constexpr unsigned numerators[]{
        50,
        25,
        60000,
        30000
    };
    constexpr unsigned denominators[]{
        1,
        1,
        1001,
        1001
    };
    const int selectedRate = std::clamp(rate, 0, 3);
    format.numerator = numerators[selectedRate];
    format.denominator = denominators[selectedRate];
    format.SetMonitorRate(nativeRate, 1);
    return format;
}

/// Packed source image and its destination viewport, matching Emulators' recording resampler.
struct RecordingImage {
    std::vector<std::uint32_t> pixels;
    unsigned width = 0;
    unsigned height = 0;
    RECT area{};
};

/// Blends RGB channels independently with the same fixed-point rounding as Emulators.
static std::uint32_t BlendRecordingPixel(std::uint32_t first, std::uint32_t second, unsigned weight) {
    std::uint32_t result = 0;
    for (int shift = 0; shift <= 16; shift += 8) {
        const std::uint32_t mixed = (first >> shift & 255) * (65536 - weight) + (second >> shift & 255) * weight + 32768;
        result |= mixed >> 16 << shift;
    }
    return result;
}

/// Returns a temporally blended source frame without altering either retained image.
static RecordingImage BlendRecordingImages(const RecordingImage& first, const RecordingImage& second, unsigned weight) {
    RecordingImage result = first;
    for (std::size_t index = 0; index < result.pixels.size(); index++) {
        result.pixels[index] = BlendRecordingPixel(first.pixels[index], second.pixels[index], weight);
    }
    return result;
}

/// Samples pixel centers with the same edge clamping as Emulators' bilinear scaler.
static constexpr double RecordingCoordinate(int pixel, int origin, int extent, unsigned source) {
    return std::clamp((double(pixel) - origin + 0.5) * source / extent - 0.5, 0.0, double(source - 1));
}

/// Mixes packed RGB channels using an eight-bit interpolation weight.
static constexpr std::uint32_t MixRecordingPixel(std::uint32_t first, std::uint32_t second, unsigned weight) {
    const std::uint32_t redBlueMixed = (first & 0xff00ff) * (256 - weight) + (second & 0xff00ff) * weight + 0x800080;
    const std::uint32_t greenMixed = (first & 0xff00) * (256 - weight) + (second & 0xff00) * weight + 0x8000;
    const std::uint32_t redBlue = redBlueMixed >> 8 & 0xff00ff;
    const std::uint32_t green = greenMixed >> 8 & 0xff00;
    return redBlue | green;
}

/// Letterboxes and bilinearly scales TV frames with Emulators' pixel-center mapping.
static void ScaleRecordingImage(const RecordingImage& image, unsigned width, unsigned height,
        std::vector<std::uint32_t>& result) {
    struct Column {
        unsigned first;
        unsigned second;
        unsigned weight;
    };
    result.assign(std::size_t(width) * height, 0);
    const int left = std::max(0L, image.area.left);
    const int right = std::min(LONG(width), image.area.right);
    std::vector<Column> columns(std::size_t(right - left));
    for (int x = left; x < right; x++) {
        const double source = RecordingCoordinate(x, image.area.left, image.area.right - image.area.left, image.width);
        const unsigned first = unsigned(source);
        const Column column{
            first,
            std::min(first + 1, image.width - 1),
            unsigned(std::lround((source - first) * 256))
        };
        columns[x - left] = column;
    }
    for (int y = std::max(0L, image.area.top); y < std::min(LONG(height), image.area.bottom); y++) {
        const double source = RecordingCoordinate(y, image.area.top, image.area.bottom - image.area.top, image.height);
        const unsigned first = unsigned(source);
        const unsigned second = std::min(first + 1, image.height - 1);
        const unsigned weight = unsigned(std::lround((source - first) * 256));
        const std::uint32_t* firstRow = image.pixels.data() + std::size_t(first) * image.width;
        const std::uint32_t* secondRow = image.pixels.data() + std::size_t(second) * image.width;
        std::uint32_t* output = result.data() + std::size_t(y) * width;
        for (int x = left; x < right; x++) {
            const Column column = columns[x - left];
            output[x] = MixRecordingPixel(
                MixRecordingPixel(firstRow[column.first], firstRow[column.second], column.weight),
                MixRecordingPixel(secondRow[column.first], secondRow[column.second], column.weight), weight);
        }
    }
}

/// Extracts one display-encoded RGB component.
static constexpr int RecordingComponent(std::uint32_t pixel, int shift) {
    return int(pixel >> shift & 255);
}

/// Rounds signed chroma coefficients with Emulators' exact fixed-point convention.
static int RoundRecordingChroma(int value) {
    return int(std::floor(double(value) / (8.0 * 65536.0) + 0.5));
}

/// Converts RGB to progressive BT.709 limited-range NV12 with MPEG-2 chroma siting, as in Emulators.
static void ConvertRecordingNv12(const std::vector<std::uint32_t>& rgb, unsigned width, unsigned height,
        std::vector<std::uint8_t>& result) {
    result.resize(std::size_t(width) * height * 3 / 2);
    std::uint8_t* luminance = result.data();
    std::uint8_t* chroma = luminance + std::size_t(width) * height;
    for (std::size_t index = 0; index < rgb.size(); index++) {
        const std::uint32_t pixel = rgb[index];
        const int mixed = 11966 * RecordingComponent(pixel, 16) + 40254 * RecordingComponent(pixel, 8) + 4064
            * RecordingComponent(pixel, 0) + 32768;
        luminance[index] = std::uint8_t(std::clamp(16 + (mixed >> 16), 16, 235));
    }
    for (unsigned y = 0; y < height; y += 2) {
        for (unsigned x = 0; x < width; x += 2) {
            int red = 0;
            int green = 0;
            int blue = 0;
            for (unsigned row = y; row < y + 2; row++) {
                for (int offset = -1; offset <= 1; offset++) {
                    const std::uint32_t pixel =
                        rgb[std::size_t(row) * width + std::clamp(int(x) + offset, 0, int(width) - 1)];
                    const int weight = offset == 0 ? 2 : 1;
                    red += weight * RecordingComponent(pixel, 16);
                    green += weight * RecordingComponent(pixel, 8);
                    blue += weight * RecordingComponent(pixel, 0);
                }
            }
            const std::size_t index = std::size_t(y / 2) * width + x;
            chroma[index] =
                std::uint8_t(std::clamp(128 + RoundRecordingChroma(-6596 * red - 22189 * green + 28784 * blue), 16, 240));
            chroma[index + 1] =
                std::uint8_t(std::clamp(128 + RoundRecordingChroma(28784 * red - 26145 * green - 2639 * blue), 16, 240));
        }
    }
}

/// Byte ranges of a validated MP4 box, following Emulators' metadata normalizer.
struct RecordingBox {
    std::size_t begin;
    std::size_t data;
    std::size_t end;
    std::uint32_t type;
};

/// Builds an MP4 box identifier in network byte order.
static constexpr std::uint32_t RecordingTag(char first, char second, char third, char fourth) {
    return std::uint32_t(first) << 24 | std::uint32_t(second) << 16 | std::uint32_t(third) << 8 | std::uint32_t(fourth);
}

/// Validates and edits the retained movie metadata without touching encoded media.
struct RecordingTable {
    std::vector<std::uint8_t> bytes;

    /// Reads a bounded big-endian metadata value.
    std::uint64_t Read(std::size_t position, std::size_t count = 4) const {
        if (position > bytes.size() || count > bytes.size() - position) {
            throw std::runtime_error("Invalid MP4 timing table.");
        }
        std::uint64_t value = 0;
        for (std::size_t index = 0; index < count; index++) {
            value = value << 8 | bytes[position + index];
        }
        return value;
    }

    /// Writes a bounded big-endian value without changing the box length.
    void Write(std::size_t position, std::uint64_t value, std::size_t count = 4) {
        if (position > bytes.size() || count > bytes.size() - position || count == 4 && value > UINT32_MAX) {
            throw std::runtime_error("MP4 timing value is out of range.");
        }
        for (std::size_t index = count; index > 0; index--) {
            bytes[position + index - 1] = std::uint8_t(value);
            value >>= 8;
        }
    }

    /// Enumerates children while rejecting truncated or overflowing box extents.
    std::vector<RecordingBox> Children(std::size_t start, std::size_t end) const {
        std::vector<RecordingBox> result;
        while (start < end) {
            if (end - start < 8) {
                throw std::runtime_error("Truncated MP4 box.");
            }
            std::uint64_t size = Read(start);
            std::size_t header = 8;
            if (size == 1) {
                size = Read(start + 8, 8);
                header = 16;
            } else if (size == 0) {
                size = std::uint64_t(end) - start;
            }
            if (size < header || size > std::uint64_t(end) - start) {
                throw std::runtime_error("Invalid MP4 box size.");
            }
            const RecordingBox box{
                start,
                start + header,
                start + std::size_t(size),
                std::uint32_t(Read(start + 4))
            };
            result.push_back(box);
            start += std::size_t(size);
        }
        return result;
    }

    /// Finds the required child box or rejects incomplete movie metadata.
    RecordingBox Child(RecordingBox parent, std::uint32_t type) const {
        for (const RecordingBox& box : Children(parent.data, parent.end)) {
            if (box.type == type) {
                return box;
            }
        }
        throw std::runtime_error("Missing MP4 timing table.");
    }

    /// Returns the clock-field position for either supported header version.
    std::size_t ScaleOffset(RecordingBox header) const {
        return header.data + (Read(header.data, 1) != 0 ? 20 : 12);
    }

    /// Returns the duration-field width for either supported header version.
    std::size_t DurationSize(RecordingBox header) const {
        return Read(header.data, 1) != 0 ? 8 : 4;
    }
};

/// Reads a big-endian value from one already bounded top-level box header.
static std::uint64_t RecordingHeaderValue(const std::uint8_t* header, unsigned position, unsigned count) {
    std::uint64_t value = 0;
    for (unsigned index = 0; index < count; index++) {
        value = value << 8 | header[position + index];
    }
    return value;
}

/// Retains Emulators' exact NTSC timing and anamorphic pixel-aspect metadata after Media Foundation finalization.
static void NormalizeRecordingTiming(const std::filesystem::path& path, const RecordingFormat& format) {
    if (!format.television) {
        return;
    }
    std::fstream file(path, std::ios::binary | std::ios::in | std::ios::out);
    if (!file) {
        throw std::runtime_error("Cannot reopen MP4 timing metadata.");
    }
    file.seekg(0, std::ios::end);
    const std::uint64_t length = std::uint64_t(file.tellg());
    std::uint64_t position = 0;
    RecordingTable table;
    std::uint64_t dataOffset = 0;
    std::uint64_t moviePosition = 0;
    std::uint64_t movieSize = 0;
    std::size_t movieHeader = 0;
    while (position + 8 <= length) {
        std::uint8_t header[16]{};
        file.seekg(std::streamoff(position));
        file.read(reinterpret_cast<char*>(header), 8);
        if (!file) {
            throw std::runtime_error("Cannot read MP4 box.");
        }
        std::uint64_t size = RecordingHeaderValue(header, 0, 4);
        std::size_t headerSize = 8;
        if (size == 1) {
            file.read(reinterpret_cast<char*>(header) + 8, 8);
            if (!file) {
                throw std::runtime_error("Cannot read MP4 box size.");
            }
            size = RecordingHeaderValue(header, 8, 8);
            headerSize = 16;
        } else if (size == 0) {
            size = length - position;
        }
        if (size < headerSize || size > length - position) {
            throw std::runtime_error("Invalid finalized MP4.");
        }
        if (RecordingHeaderValue(header, 4, 4) == RecordingTag('m', 'o', 'o', 'v')) {
            if (size - headerSize > 256 * 1024 * 1024) {
                throw std::runtime_error("MP4 metadata is too large.");
            }
            table.bytes.resize(std::size_t(size - headerSize));
            file.read(reinterpret_cast<char*>(table.bytes.data()), std::streamsize(table.bytes.size()));
            if (!file) {
                throw std::runtime_error("Cannot read MP4 metadata.");
            }
            dataOffset = position + headerSize;
            moviePosition = position;
            movieSize = size;
            movieHeader = headerSize;
            break;
        }
        position += size;
    }
    if (table.bytes.empty()) {
        throw std::runtime_error("Missing MP4 movie metadata.");
    }
    const RecordingBox root{
        0,
        0,
        table.bytes.size(),
        0
    };
    const RecordingBox movie = table.Child(root, RecordingTag('m', 'v', 'h', 'd'));
    const std::size_t movieScaleOffset = table.ScaleOffset(movie);
    const std::uint64_t movieScale = table.Read(movieScaleOffset);
    std::uint64_t movieDuration = 0;
    bool found = false;
    std::size_t aspectInsert = 0;
    std::vector<RecordingBox> aspectParents;
    for (const RecordingBox& track : table.Children(0, table.bytes.size())) {
        if (track.type != RecordingTag('t', 'r', 'a', 'k')) {
            continue;
        }
        const RecordingBox trackHeader = table.Child(track, RecordingTag('t', 'k', 'h', 'd'));
        const std::size_t trackDurationOffset = trackHeader.data + (table.Read(trackHeader.data, 1) != 0 ? 28 : 20);
        const std::size_t trackDurationSize = table.DurationSize(trackHeader);
        const RecordingBox media = table.Child(track, RecordingTag('m', 'd', 'i', 'a'));
        const RecordingBox handler = table.Child(media, RecordingTag('h', 'd', 'l', 'r'));
        if (table.Read(handler.data + 8) == RecordingTag('v', 'i', 'd', 'e')) {
            found = true;
            const RecordingBox header = table.Child(media, RecordingTag('m', 'd', 'h', 'd'));
            const std::size_t scaleOffset = table.ScaleOffset(header);
            const std::uint64_t oldScale = table.Read(scaleOffset);
            if (oldScale == 0) {
                throw std::runtime_error("Invalid MP4 video clock.");
            }
            const RecordingBox info = table.Child(media, RecordingTag('m', 'i', 'n', 'f'));
            const RecordingBox samples = table.Child(info, RecordingTag('s', 't', 'b', 'l'));
            const RecordingBox times = table.Child(samples, RecordingTag('s', 't', 't', 's'));
            const RecordingBox description = table.Child(samples, RecordingTag('s', 't', 's', 'd'));
            for (const RecordingBox& entry : table.Children(description.data + 8, description.end)) {
                if (entry.type != RecordingTag('a', 'v', 'c', '1')) {
                    continue;
                }
                bool hasAspect = false;
                for (const RecordingBox& box : table.Children(entry.data + 78, entry.end)) {
                    if (box.type == RecordingTag('p', 'a', 's', 'p')) {
                        table.Write(box.data, format.aspectX);
                        table.Write(box.data + 4, format.aspectY);
                        hasAspect = true;
                    }
                }
                if (!hasAspect) {
                    aspectInsert = entry.end;
                    aspectParents = std::vector<RecordingBox>{
                        track,
                        media,
                        info,
                        samples,
                        description,
                        entry
                    };
                }
            }
            table.Write(trackHeader.end - 8, (std::uint64_t(format.width) * format.aspectX << 16) / format.aspectY);
            const std::uint64_t count = table.Read(times.data + 4);
            std::uint64_t duration = 0;
            if (count > (std::uint64_t(times.end) - times.data - 8) / 8) {
                throw std::runtime_error("Invalid MP4 sample times.");
            }
            for (std::uint64_t index = 0; index < count; index++) {
                const std::size_t entry = times.data + 8 + std::size_t(index) * 8;
                const std::uint64_t runs = table.Read(entry);
                const std::uint64_t old = table.Read(entry + 4);
                const std::uint64_t frames = (old * format.numerator + oldScale * format.denominator / 2)
                    / (oldScale * format.denominator);
                if (frames == 0) {
                    throw std::runtime_error("Invalid MP4 frame duration.");
                }
                const std::uint64_t delta = frames * format.denominator;
                table.Write(entry + 4, delta);
                duration += runs * delta;
            }
            for (const RecordingBox& box : table.Children(samples.data, samples.end)) {
                if (box.type != RecordingTag('c', 't', 't', 's')) {
                    continue;
                }
                const std::uint64_t offsetCount = table.Read(box.data + 4);
                if (offsetCount > (std::uint64_t(box.end) - box.data - 8) / 8) {
                    throw std::runtime_error("Invalid MP4 composition offsets.");
                }
                for (std::uint64_t index = 0; index < offsetCount; index++) {
                    const std::size_t entry = box.data + 12 + std::size_t(index) * 8;
                    const std::int64_t old = table.Read(box.data, 1) != 0
                        ? std::int32_t(table.Read(entry)) : std::int64_t(table.Read(entry));
                    const std::int64_t frames = std::int64_t(std::llround(double(old) * format.numerator
                        / (double(oldScale) * format.denominator)));
                    const std::int64_t offset = frames * format.denominator;
                    if (table.Read(box.data, 1) != 0) {
                        if (offset < INT32_MIN || offset > INT32_MAX) {
                            throw std::runtime_error("MP4 composition offset overflow.");
                        }
                        table.Write(entry, std::uint32_t(std::int32_t(offset)));
                    } else {
                        table.Write(entry, std::uint64_t(offset));
                    }
                }
            }
            table.Write(scaleOffset, format.numerator);
            table.Write(scaleOffset + 4, duration, table.DurationSize(header));
            table.Write(trackDurationOffset, (duration * movieScale + format.numerator - 1) / format.numerator,
                trackDurationSize);
        }
        movieDuration = std::max(movieDuration, table.Read(trackDurationOffset, trackDurationSize));
    }
    if (!found) {
        throw std::runtime_error("Missing MP4 video track.");
    }
    table.Write(movieScaleOffset + 4, movieDuration, table.DurationSize(movie));
    if (aspectInsert != 0) {
        if (moviePosition + movieSize != length) {
            throw std::runtime_error("Cannot add pixel aspect metadata before MP4 media data.");
        }
        for (const RecordingBox& box : aspectParents) {
            if (table.Read(box.begin) == 1) {
                table.Write(box.begin + 8, std::uint64_t(box.end) - box.begin + 16, 8);
            } else {
                table.Write(box.begin, std::uint64_t(box.end) - box.begin + 16);
            }
        }
        std::uint8_t aspect[16]{ 0, 0, 0, 16, 'p', 'a', 's', 'p' };
        for (int index = 0; index < 4; index++) {
            const int shift = 24 - 8 * index;
            aspect[8 + index] = std::uint8_t(format.aspectX >> shift);
            aspect[12 + index] = std::uint8_t(format.aspectY >> shift);
        }
        table.bytes.insert(table.bytes.begin() + aspectInsert, std::begin(aspect), std::end(aspect));
        std::uint64_t size = movieSize + 16;
        const std::size_t count = movieHeader == 16 ? 8 : 4;
        std::uint8_t value[8]{};
        for (std::size_t index = count; index > 0; index--) {
            value[index - 1] = std::uint8_t(size);
            size >>= 8;
        }
        file.seekp(std::streamoff(moviePosition + (movieHeader == 16 ? 8 : 0)));
        file.write(reinterpret_cast<char*>(value), std::streamsize(count));
    }
    file.seekp(std::streamoff(dataOffset));
    file.write(reinterpret_cast<const char*>(table.bytes.data()), std::streamsize(table.bytes.size()));
    file.flush();
    if (!file) {
        throw std::runtime_error("Cannot write exact MP4 timestamps.");
    }
}

/// Resolves image copying from Media Foundation, or from the system EVR library used before Windows 7.
/// Retains a successfully loaded EVR module for the lifetime of the cached function pointer.
static CopyImageFunction ResolveCopyImageFunction() {
    const HMODULE mediaFoundation = GetModuleHandleW(MEDIA_FOUNDATION_LIBRARY);
    if (mediaFoundation) {
        const CopyImageFunction copyImage =
            reinterpret_cast<CopyImageFunction>(GetProcAddress(mediaFoundation, COPY_IMAGE_FUNCTION));
        if (copyImage) {
            return copyImage;
        }
    }
    wchar_t systemDirectory[MAX_PATH]{};
    const UINT length = GetSystemDirectoryW(systemDirectory, MAX_PATH);
    if (length == 0 || length >= static_cast<UINT>(MAX_PATH)) {
        return nullptr;
    }
    std::wstring libraryPath(systemDirectory, length);
    libraryPath += L"\\";
    libraryPath += VIDEO_RENDERER_LIBRARY;
    const HMODULE videoRenderer = LoadLibraryW(libraryPath.c_str());
    if (!videoRenderer) {
        return nullptr;
    }
    const CopyImageFunction copyImage =
        reinterpret_cast<CopyImageFunction>(GetProcAddress(videoRenderer, COPY_IMAGE_FUNCTION));
    if (!copyImage) {
        FreeLibrary(videoRenderer);
    }
    return copyImage;
}

/// Copies pixel rows without requiring a Media Foundation export, preserving padding and signed strides.
static HRESULT CopyImageRows(BYTE* destination, LONG destinationStride, const BYTE* source, LONG sourceStride,
        DWORD rowBytes, DWORD rowCount) {
    if (rowBytes == 0 || rowCount == 0) {
        return S_OK;
    }
    if (!destination || !source) {
        return E_POINTER;
    }
    for (DWORD row = 0; row < rowCount; row++) {
        std::memcpy(destination, source, rowBytes);
        if (row + 1 < rowCount) {
            destination += destinationStride;
            source += sourceStride;
        }
    }
    return S_OK;
}

/// Uses the available system image-copy function, falling back to row copying only when neither export exists.
static HRESULT CopyImageCompatible(BYTE* destination, LONG destinationStride, const BYTE* source, LONG sourceStride,
        DWORD rowBytes, DWORD rowCount) {
    static const CopyImageFunction copyImage = ResolveCopyImageFunction();
    if (copyImage) {
        return copyImage(destination, destinationStride, source, sourceStride, rowBytes, rowCount);
    }
    return CopyImageRows(destination, destinationStride, source, sourceStride, rowBytes, rowCount);
}

/// Initializes the attributes common to the encoder input and output video types.
static HRESULT ConfigureVideoType(IMFMediaType* type, const GUID& subtype, const RecordingFormat& format) {
    HRESULT result = type->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Video);
    if (SUCCEEDED(result)) {
        result = type->SetGUID(MF_MT_SUBTYPE, subtype);
    }
    if (SUCCEEDED(result)) {
        result = type->SetUINT32(MF_MT_INTERLACE_MODE, MFVideoInterlace_Progressive);
    }
    if (SUCCEEDED(result)) {
        result = MFSetAttributeSize(type, MF_MT_FRAME_SIZE, format.width, format.height);
    }
    if (SUCCEEDED(result)) {
        result = MFSetAttributeRatio(type, MF_MT_FRAME_RATE, format.numerator, format.denominator);
    }
    if (SUCCEEDED(result)) {
        result = MFSetAttributeRatio(type, MF_MT_PIXEL_ASPECT_RATIO, format.aspectX, format.aspectY);
    }
    if (SUCCEEDED(result) && format.television) {
        result = type->SetUINT32(MF_MT_VIDEO_PRIMARIES, MFVideoPrimaries_BT709);
    }
    if (SUCCEEDED(result) && format.television) {
        result = type->SetUINT32(MF_MT_TRANSFER_FUNCTION, MFVideoTransFunc_709);
    }
    if (SUCCEEDED(result) && format.television) {
        result = type->SetUINT32(MF_MT_YUV_MATRIX, MFVideoTransferMatrix_BT709);
    }
    if (SUCCEEDED(result) && format.television) {
        result = type->SetUINT32(MF_MT_VIDEO_NOMINAL_RANGE, MFNominalRange_16_235);
    }
    if (SUCCEEDED(result) && format.television) {
        result = type->SetUINT32(MF_MT_VIDEO_CHROMA_SITING,
            MFVideoChromaSubsampling_MPEG2 | MFVideoChromaSubsampling_ProgressiveChroma);
    }
    return result;
}

/// Writes one prepared frame with exact sample boundaries.
static HRESULT WriteRecordingSample(IMFSinkWriter* writer, DWORD stream, const void* pixels, DWORD bytes,
        const RecordingFormat& format, std::uint64_t frame) {
    ComPtr<IMFMediaBuffer> buffer;
    HRESULT result = MFCreateMemoryBuffer(bytes, &buffer);
    BYTE* destination = nullptr;
    if (SUCCEEDED(result)) {
        result = buffer->Lock(&destination, nullptr, nullptr);
    }
    if (SUCCEEDED(result)) {
        std::memcpy(destination, pixels, bytes);
    }
    if (destination) {
        const HRESULT unlockResult = buffer->Unlock();
        if (SUCCEEDED(result)) {
            result = unlockResult;
        }
    }
    if (SUCCEEDED(result)) {
        result = buffer->SetCurrentLength(bytes);
    }
    ComPtr<IMFSample> sample;
    if (SUCCEEDED(result)) {
        result = MFCreateSample(&sample);
    }
    if (SUCCEEDED(result)) {
        result = sample->AddBuffer(buffer.Get());
    }
    if (SUCCEEDED(result)) {
        result = sample->SetSampleTime(LONGLONG(format.Time(frame)));
    }
    if (SUCCEEDED(result)) {
        result = sample->SetSampleDuration(LONGLONG(format.Time(frame + 1) - format.Time(frame)));
    }
    if (SUCCEEDED(result)) {
        result = writer->WriteSample(stream, sample.Get());
    }
    return result;
}

/// Bounds GPU readback storage and CPU work independently of recording duration.
constexpr std::size_t RECORDING_READBACK_COUNT = 3;
constexpr std::size_t RECORDING_QUEUE_CAPACITY = 2;
constexpr std::size_t RECORDING_IMAGE_COUNT = RECORDING_QUEUE_CAPACITY + 3;

/// One completed source image with its original capture timestamp.
struct RecordingFrame {
    RecordingImage image;
    LONGLONG time = 0;
    std::uint64_t sequence = 0;
};

/// One asynchronous GPU copy retained until it can be mapped without waiting.
struct RecordingReadback {
    ComPtr<ID3D11Texture2D> texture;
    LONGLONG time = 0;
    std::uint64_t sequence = 0;
    bool pending = false;
};

/// Keeps capture resources on the rendering thread and Media Foundation resources on its own worker.
struct Mp4Recorder::Impl {
    /// Immutable session format and render-thread capture state
    UINT width = 0;
    UINT height = 0;
    UINT frameRate = 0;
    RecordingFormat format;
    std::wstring filePath;
    LARGE_INTEGER performanceFrequency{};
    LARGE_INTEGER recordingStartedAt{};
    std::array<RecordingReadback, RECORDING_READBACK_COUNT> readbacks;
    LONGLONG lastCapturedFrame = -1;
    std::uint64_t nextCaptureSequence = 0;

    /// Bounded handoff and reusable CPU image storage
    std::thread worker;
    std::mutex queueMutex;
    std::condition_variable queueChanged;
    std::array<RecordingFrame, RECORDING_QUEUE_CAPACITY> frames;
    std::vector<RecordingImage> freeImages;
    std::size_t firstFrame = 0;
    std::size_t frameCount = 0;
    bool workerReady = false;
    bool stopRequested = false;
    LONGLONG stopTime = -1;
    std::atomic_bool recording = false;
    std::atomic<HRESULT> lastError = S_OK;

    /// Encoder state accessed only by the recording worker
    ComPtr<IMFSinkWriter> sinkWriter;
    DWORD streamIndex = 0;
    bool comInitialized = false;
    bool mediaFoundationStarted = false;
    bool writing = false;
    bool hardwareWriter = false;
    RecordingImage previousImage;
    LONGLONG previousImageTime = 0;
    std::uint64_t previousSequence = 0;
    LONGLONG lastFrameIndex = -1;
    std::vector<std::uint32_t> scaled;
    std::vector<std::uint8_t> converted;
    std::vector<std::uint8_t> previousConverted;
    bool previousPrepared = false;

    /// Creates COM and the H.264 sink on the thread that will perform all encoding.
    HRESULT OpenWriter();

    /// Initializes a hardware-permitted or explicitly software-only sink without changing session timing.
    HRESULT CreateWriter(bool hardware);

    /// Finalizes the MP4 stream and releases thread-owned Media Foundation and COM state.
    HRESULT FinishWriter();

    /// Resamples and encodes a source image using capture time rather than worker completion time.
    HRESULT EncodeFrame(RecordingFrame& frame);

    /// Repeats the last encoded image through the requested TV stop time without extending encoding time into playback.
    HRESULT FillUntil(LONGLONG time);

    /// Reads elapsed capture time from the immutable session clock.
    LONGLONG Elapsed() const;

    /// Runs the encoder independently of animation and drains accepted images before normal shutdown.
    void Run();

    /// Publishes completed worker initialization while holding the queue lock.
    void MarkWorkerReady();

    /// Waits for queued input and transfers one frame or the stop deadline under the queue lock.
    bool TakeNextFrame(RecordingFrame& frame, LONGLONG& finishTime);

    /// Preserves the first capture, encoder or finalization failure across threads.
    void SetError(HRESULT error);

    /// Wakes the worker to finish all accepted images and exit.
    void RequestStop(LONGLONG time = -1);

    /// Retains the first stop deadline and disables further waiting while holding the queue lock.
    void SetStopRequest(LONGLONG time);

    /// Acquires reusable pixel storage without waiting during ordinary rendering.
    bool AcquireImage(RecordingImage& image, bool wait);

    /// Returns pixel storage after capture or encoding without reallocating it.
    void RecycleImage(RecordingImage& image);

    /// Queues the newest image, discarding stale queued input rather than blocking animation.
    bool SubmitImage(RecordingImage& image, LONGLONG time, std::uint64_t sequence);

    /// Collects completed GPU copies without waiting, except when explicitly stopping a recording.
    HRESULT CollectReadbacks(ID3D11DeviceContext* context, bool wait);
};

/// Creates an idle recorder with no worker or Media Foundation session.
Mp4Recorder::Mp4Recorder() : impl(new Impl{}) {}

/// Finalizes an active file and joins its recording worker before releasing implementation state.
Mp4Recorder::~Mp4Recorder() {
    Stop();
    delete impl;
}

/// Reports whether captured images are currently accepted by the recording worker.
bool Mp4Recorder::IsRecording() const {
    return impl->recording.load(std::memory_order_acquire);
}

/// Returns the nearest whole-number approximation of the current session's rational frame rate.
UINT Mp4Recorder::FrameRate() const {
    return impl->frameRate;
}

/// Returns the first capture, encoding or finalization failure reported by either thread.
HRESULT Mp4Recorder::LastError() const {
    return impl->lastError.load(std::memory_order_relaxed);
}

/// Retains the first failure without overwriting it during subsequent finalization.
void Mp4Recorder::Impl::SetError(HRESULT error) {
    if (FAILED(error)) {
        HRESULT expected = S_OK;
        lastError.compare_exchange_strong(expected, error, std::memory_order_relaxed);
    }
}

/// Creates the selected input and output media types entirely on the encoder worker.
HRESULT Mp4Recorder::Impl::OpenWriter() {
    HRESULT result = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    if (SUCCEEDED(result)) {
        comInitialized = true;
    } else if (result != RPC_E_CHANGED_MODE) {
        return result;
    }
    result = MFStartup(MF_VERSION);
    if (FAILED(result)) {
        return result;
    }
    mediaFoundationStarted = true;
    result = CreateWriter(true);
    if (FAILED(result)) {
        result = CreateWriter(false);
    }
    return result;
}

/// Retries unsupported hardware initialization through the same MP4 pipeline with software transforms only.
HRESULT Mp4Recorder::Impl::CreateWriter(bool hardware) {
    writing = false;
    sinkWriter.Reset();
    hardwareWriter = hardware;
    ComPtr<IMFAttributes> writerAttributes;
    HRESULT result = MFCreateAttributes(&writerAttributes, 2);
    if (SUCCEEDED(result)) {
        result = writerAttributes->SetUINT32(MF_READWRITE_ENABLE_HARDWARE_TRANSFORMS, hardware);
    }
    if (SUCCEEDED(result)) {
        result = writerAttributes->SetGUID(MF_TRANSCODE_CONTAINERTYPE, MFTranscodeContainerType_MPEG4);
    }
    if (SUCCEEDED(result)) {
        result = MFCreateSinkWriterFromURL(filePath.c_str(), nullptr, writerAttributes.Get(), &sinkWriter);
    }
    if (FAILED(result)) {
        return result;
    }
    ComPtr<IMFMediaType> outputType;
    result = MFCreateMediaType(&outputType);
    if (SUCCEEDED(result)) {
        result = ConfigureVideoType(outputType.Get(), MFVideoFormat_H264, format);
    }
    if (SUCCEEDED(result)) {
        const std::uint64_t estimatedBitRate =
            static_cast<std::uint64_t>(format.width) * format.height * format.numerator / format.denominator
            / (format.television ? 3 : 10);
        const UINT32 bitRate = static_cast<UINT32>(std::clamp<std::uint64_t>(estimatedBitRate, 4'000'000, 80'000'000));
        result = outputType->SetUINT32(MF_MT_AVG_BITRATE, bitRate);
    }
    if (SUCCEEDED(result)) {
        result = sinkWriter->AddStream(outputType.Get(), &streamIndex);
    }
    if (FAILED(result)) {
        return result;
    }
    ComPtr<IMFMediaType> inputType;
    result = MFCreateMediaType(&inputType);
    if (SUCCEEDED(result)) {
        result =
            ConfigureVideoType(inputType.Get(), format.television ? MFVideoFormat_NV12 : MFVideoFormat_RGB32, format);
    }
    const UINT32 imageSize = format.television ? format.width * format.height * 3 / 2 : format.width * format.height * 4;
    if (SUCCEEDED(result)) {
        result = inputType->SetUINT32(MF_MT_DEFAULT_STRIDE, format.width * (format.television ? 1 : 4));
    }
    if (SUCCEEDED(result)) {
        result = inputType->SetUINT32(MF_MT_SAMPLE_SIZE, imageSize);
    }
    if (SUCCEEDED(result)) {
        result = inputType->SetUINT32(MF_MT_FIXED_SIZE_SAMPLES, TRUE);
    }
    if (SUCCEEDED(result)) {
        result = inputType->SetUINT32(MF_MT_ALL_SAMPLES_INDEPENDENT, TRUE);
    }
    if (SUCCEEDED(result)) {
        result = sinkWriter->SetInputMediaType(streamIndex, inputType.Get(), nullptr);
    }
    if (SUCCEEDED(result)) {
        result = sinkWriter->BeginWriting();
    }
    if (FAILED(result)) {
        return result;
    }
    writing = true;
    return S_OK;
}

/// Finalizes output and balances COM initialization on the same worker thread.
HRESULT Mp4Recorder::Impl::FinishWriter() {
    HRESULT result = S_OK;
    if (writing && sinkWriter) {
        result = sinkWriter->Finalize();
    }
    writing = false;
    sinkWriter.Reset();
    if (SUCCEEDED(result) && lastFrameIndex >= 0 && format.television) {
        try {
            NormalizeRecordingTiming(filePath, format);
        } catch (const std::exception&) {
            result = E_FAIL;
        }
    }
    previousImage = RecordingImage{};
    previousConverted.clear();
    previousPrepared = false;
    scaled.clear();
    converted.clear();
    if (mediaFoundationStarted) {
        const HRESULT shutdownResult = MFShutdown();
        if (SUCCEEDED(result) && FAILED(shutdownResult)) {
            result = shutdownResult;
        }
        mediaFoundationStarted = false;
    }
    if (comInitialized) {
        CoUninitialize();
        comInitialized = false;
    }
    return result;
}

/// Performs resampling, color conversion and sink writes away from the rendering thread.
HRESULT Mp4Recorder::Impl::EncodeFrame(RecordingFrame& source) {
    RecordingImage& image = source.image;
    const LONGLONG frameIndex = LONGLONG(format.FramesAt(std::uint64_t(std::max(0LL, source.time))));
    HRESULT result = S_OK;
    if (!format.television) {
        if (frameIndex > lastFrameIndex) {
            result = WriteRecordingSample(sinkWriter.Get(), streamIndex, image.pixels.data(),
                DWORD(image.pixels.size() * sizeof(std::uint32_t)), format, std::uint64_t(frameIndex));
            if (SUCCEEDED(result)) {
                lastFrameIndex = frameIndex;
            }
        }
        return result;
    }
    const RecordingImage* prepared = nullptr;
    const bool resampleMotion = format.temporalBlend && source.sequence == previousSequence + 1;
    for (LONGLONG frame = lastFrameIndex + 1; frame <= frameIndex; frame++) {
        const LONGLONG sampleTime = LONGLONG(format.Time(std::uint64_t(frame)));
        const bool blend = resampleMotion
            && !previousImage.pixels.empty()
            && sampleTime > previousImageTime
            && sampleTime < source.time;
        const std::vector<std::uint8_t>* pixels = &converted;
        if (blend) {
            const unsigned weight = unsigned((sampleTime - previousImageTime) * 65536
                / (source.time - previousImageTime));
            const RecordingImage blended = BlendRecordingImages(previousImage, image, weight);
            ScaleRecordingImage(blended, format.width, format.height, scaled);
            ConvertRecordingNv12(scaled, format.width, format.height, converted);
            prepared = nullptr;
        } else if (!resampleMotion && frame < frameIndex && previousPrepared) {
            pixels = &previousConverted;
        } else {
            const RecordingImage* selected = !previousImage.pixels.empty() && sampleTime <= previousImageTime
                ? &previousImage : &image;
            if (selected == prepared && previousPrepared) {
                pixels = &previousConverted;
            } else {
                ScaleRecordingImage(*selected, format.width, format.height, scaled);
                ConvertRecordingNv12(scaled, format.width, format.height, converted);
                prepared = selected;
            }
        }
        result = WriteRecordingSample(sinkWriter.Get(), streamIndex, pixels->data(),
            DWORD(pixels->size()), format, std::uint64_t(frame));
        if (FAILED(result)) {
            break;
        }
        if (pixels == &converted) {
            previousConverted.swap(converted);
        }
        previousPrepared = true;
        lastFrameIndex = frame;
    }
    if (SUCCEEDED(result)) {
        std::swap(previousImage, image);
        previousImageTime = source.time;
        previousSequence = source.sequence;
    }
    return result;
}

/// Fills missing final TV slots with the last encoded pixels while preserving exact rational sample times.
HRESULT Mp4Recorder::Impl::FillUntil(LONGLONG time) {
    if (!format.television || !previousPrepared || time < 0) {
        return S_OK;
    }
    const LONGLONG finalFrame = LONGLONG(format.FramesAt(std::uint64_t(time)));
    for (LONGLONG frame = lastFrameIndex + 1; frame <= finalFrame; frame++) {
        const HRESULT result = WriteRecordingSample(sinkWriter.Get(), streamIndex, previousConverted.data(),
            DWORD(previousConverted.size()), format, std::uint64_t(frame));
        if (FAILED(result)) {
            return result;
        }
        lastFrameIndex = frame;
    }
    return S_OK;
}

/// Uses capture-clock elapsed time rather than CPU encoding or finalization duration.
LONGLONG Mp4Recorder::Impl::Elapsed() const {
    LARGE_INTEGER now{};
    QueryPerformanceCounter(&now);
    return static_cast<LONGLONG>(static_cast<long double>(now.QuadPart - recordingStartedAt.QuadPart)
        * MEDIA_FOUNDATION_UNITS_PER_SECOND / performanceFrequency.QuadPart);
}

/// Publishes completed worker initialization while holding the queue lock.
void Mp4Recorder::Impl::MarkWorkerReady() {
    const std::lock_guard lock(queueMutex);
    workerReady = true;
}

/// Waits for queued input and transfers one frame or the stop deadline under the queue lock.
bool Mp4Recorder::Impl::TakeNextFrame(RecordingFrame& frame, LONGLONG& finishTime) {
    std::unique_lock lock(queueMutex);
    while (frameCount == 0 && !stopRequested) {
        queueChanged.wait(lock);
    }
    if (frameCount == 0) {
        finishTime = stopTime;
        return false;
    }
    frame = std::move(frames[firstFrame]);
    firstFrame = (firstFrame + 1) % RECORDING_QUEUE_CAPACITY;
    frameCount--;
    return true;
}

/// Initializes, services and finalizes the complete encoder session on one dedicated worker.
void Mp4Recorder::Impl::Run() {
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_BELOW_NORMAL);
    HRESULT result = OpenWriter();
    SetError(result);
    if (SUCCEEDED(result)) {
        QueryPerformanceFrequency(&performanceFrequency);
        QueryPerformanceCounter(&recordingStartedAt);
        recording.store(true, std::memory_order_release);
    }
    MarkWorkerReady();
    queueChanged.notify_all();
    if (SUCCEEDED(result)) {
        LONGLONG finishTime = -1;
        try {
            while (true) {
                RecordingFrame frame;
                if (!TakeNextFrame(frame, finishTime)) {
                    break;
                }
                queueChanged.notify_all();
                result = EncodeFrame(frame);
                if (FAILED(result) && hardwareWriter && lastFrameIndex < 0) {
                    result = CreateWriter(false);
                    if (SUCCEEDED(result)) {
                        result = EncodeFrame(frame);
                    }
                }
                RecycleImage(frame.image);
                if (FAILED(result)) {
                    SetError(result);
                    break;
                }
            }
            if (SUCCEEDED(result) && SUCCEEDED(lastError.load(std::memory_order_relaxed))) {
                SetError(FillUntil(finishTime));
            }
        } catch (const std::bad_alloc&) {
            SetError(E_OUTOFMEMORY);
        } catch (const std::exception&) {
            SetError(E_FAIL);
        }
    }
    recording.store(false, std::memory_order_release);
    queueChanged.notify_all();
    SetError(FinishWriter());
}

/// Retains the first stop deadline and disables further waiting while holding the queue lock.
void Mp4Recorder::Impl::SetStopRequest(LONGLONG time) {
    const std::lock_guard lock(queueMutex);
    if (!stopRequested) {
        stopTime = time;
    }
    stopRequested = true;
}

/// Wakes the recording worker without holding any rendering or encoding operation inside the queue lock.
void Mp4Recorder::Impl::RequestStop(LONGLONG time) {
    SetStopRequest(time);
    queueChanged.notify_all();
}

/// Reuses pixel storage, optionally waiting only for the short queue lock, never for encoder processing.
bool Mp4Recorder::Impl::AcquireImage(RecordingImage& image, bool wait) {
    std::unique_lock lock(queueMutex, std::defer_lock);
    if (wait) {
        lock.lock();
    } else if (!lock.try_lock()) {
        return false;
    }
    if (freeImages.empty() || !recording.load(std::memory_order_acquire)) {
        return false;
    }
    image = std::move(freeImages.back());
    freeImages.pop_back();
    return true;
}

/// Returns used image storage to the fixed-size pool after its pixel data is no longer needed.
void Mp4Recorder::Impl::RecycleImage(RecordingImage& image) {
    if (!image.pixels.empty()) {
        const std::lock_guard lock(queueMutex);
        freeImages.push_back(std::move(image));
    }
    queueChanged.notify_all();
}

/// Keeps the pending queue bounded; overload replaces the oldest waiting source, never the running encoder.
bool Mp4Recorder::Impl::SubmitImage(RecordingImage& image, LONGLONG time, std::uint64_t sequence) {
    std::unique_lock lock(queueMutex);
    if (!recording.load(std::memory_order_acquire)) {
        return false;
    }
    if (frameCount == RECORDING_QUEUE_CAPACITY) {
        freeImages.push_back(std::move(frames[firstFrame].image));
        firstFrame = (firstFrame + 1) % RECORDING_QUEUE_CAPACITY;
        frameCount--;
    }
    const std::size_t slot = (firstFrame + frameCount) % RECORDING_QUEUE_CAPACITY;
    frames[slot].image = std::move(image);
    frames[slot].time = time;
    frames[slot].sequence = sequence;
    frameCount++;
    lock.unlock();
    queueChanged.notify_all();
    return true;
}

/// Reads only completed staging textures during animation and preserves source timestamps across GPU latency.
HRESULT Mp4Recorder::Impl::CollectReadbacks(ID3D11DeviceContext* context, bool wait) {
    for (std::size_t count = 0; count < readbacks.size(); count++) {
        RecordingReadback* oldest = nullptr;
        for (RecordingReadback& readback : readbacks) {
            if (readback.pending && (!oldest || readback.time < oldest->time)) {
                oldest = &readback;
            }
        }
        if (!oldest) {
            return S_OK;
        }
        RecordingImage image;
        if (!AcquireImage(image, wait)) {
            return S_FALSE;
        }
        D3D11_MAPPED_SUBRESOURCE mapped{};
        const HRESULT mapResult = context->Map(oldest->texture.Get(), 0, D3D11_MAP_READ,
            wait ? 0U : D3D11_MAP_FLAG_DO_NOT_WAIT, &mapped);
        if (mapResult == DXGI_ERROR_WAS_STILL_DRAWING) {
            RecycleImage(image);
            return S_FALSE;
        }
        if (FAILED(mapResult)) {
            RecycleImage(image);
            return mapResult;
        }
        const DWORD rowBytes = width * 4;
        const HRESULT copyResult = CopyImageCompatible(reinterpret_cast<BYTE*>(image.pixels.data()), LONG(rowBytes),
            static_cast<const BYTE*>(mapped.pData), LONG(mapped.RowPitch), rowBytes, height);
        context->Unmap(oldest->texture.Get(), 0);
        oldest->pending = false;
        if (FAILED(copyResult)) {
            RecycleImage(image);
            return copyResult;
        }
        if (!SubmitImage(image, oldest->time, oldest->sequence)) {
            RecycleImage(image);
            return S_FALSE;
        }
    }
    return S_OK;
}

/// Tests GPU readback, worker encoding and finalization without opening a window or touching a user file.
HRESULT Mp4Recorder::CheckSupport(ID3D11Device* device, ID3D11DeviceContext* context, ID3D11Texture2D* source,
        UINT width, UINT height, const RecordingFormat& format) {
    if (!device || !context || !source || width == 0 || height == 0 || format.numerator == 0) {
        return E_INVALIDARG;
    }
    wchar_t directory[MAX_PATH]{};
    const DWORD length = GetTempPathW(MAX_PATH, directory);
    if (length == 0) {
        return HRESULT_FROM_WIN32(GetLastError());
    }
    if (length >= MAX_PATH) {
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
    }
    wchar_t file[MAX_PATH]{};
    if (!GetTempFileNameW(directory, RECORDING_TEST_PREFIX, 0, file)) {
        return HRESULT_FROM_WIN32(GetLastError());
    }
    Mp4Recorder recorder;
    HRESULT result = S_OK;
    if (!recorder.Start(device, file, width, height, format)) {
        result = recorder.LastError();
    } else {
        if (!recorder.CaptureFrame(context, source)) {
            result = recorder.LastError();
        }
        const HRESULT stopResult = recorder.Stop(context);
        if (SUCCEEDED(result)) {
            result = stopResult;
        }
    }
    if (!DeleteFileW(file) && SUCCEEDED(result)) {
        result = HRESULT_FROM_WIN32(GetLastError());
    }
    return result;
}

/// Preallocates bounded capture storage and starts the encoder without sharing COM objects across threads.
bool Mp4Recorder::Start(ID3D11Device* device, const wchar_t* filePath, UINT width, UINT height,
        const RecordingFormat& format) {
    Stop();
    impl->lastError.store(S_OK, std::memory_order_relaxed);
    if (!device
            || !filePath
            || !*filePath
            || width == 0
            || height == 0
            || format.width == 0
            || format.height == 0
            || format.numerator == 0
            || format.denominator == 0
            || format.aspectX == 0
            || format.aspectY == 0
            || std::uint64_t(width) * height > MAXDWORD / 4
            || std::uint64_t(format.width) * format.height > MAXDWORD / 4
            || format.television && (format.width % 2 != 0 || format.height % 2 != 0)) {
        impl->SetError(E_INVALIDARG);
        return false;
    }
    impl->width = width;
    impl->height = height;
    impl->format = format;
    impl->frameRate = (format.numerator + format.denominator / 2) / format.denominator;
    impl->lastCapturedFrame = -1;
    impl->nextCaptureSequence = 0;
    impl->lastFrameIndex = -1;
    impl->previousImageTime = 0;
    impl->previousSequence = 0;
    impl->previousPrepared = false;
    impl->firstFrame = 0;
    impl->frameCount = 0;
    impl->workerReady = false;
    impl->stopRequested = false;
    impl->stopTime = -1;
    try {
        impl->filePath = filePath;
        impl->freeImages.reserve(RECORDING_IMAGE_COUNT);
        const POINT base{
            LONG(width),
            LONG(height)
        };
        for (std::size_t index = 0; index < RECORDING_IMAGE_COUNT; index++) {
            RecordingImage image;
            image.width = width;
            image.height = height;
            image.area = format.Viewport(base);
            image.pixels.resize(std::size_t(width) * height);
            impl->freeImages.push_back(std::move(image));
        }
        D3D11_TEXTURE2D_DESC description{};
        description.Width = width;
        description.Height = height;
        description.MipLevels = 1;
        description.ArraySize = 1;
        description.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
        description.SampleDesc.Count = 1;
        description.Usage = D3D11_USAGE_STAGING;
        description.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
        for (RecordingReadback& readback : impl->readbacks) {
            const HRESULT result = device->CreateTexture2D(&description, nullptr, &readback.texture);
            if (FAILED(result)) {
                impl->SetError(result);
                Stop();
                return false;
            }
        }
        impl->worker = std::thread(&Impl::Run, impl);
    } catch (const std::bad_alloc&) {
        impl->SetError(E_OUTOFMEMORY);
        Stop();
        return false;
    } catch (const std::exception&) {
        impl->SetError(E_FAIL);
        Stop();
        return false;
    }
    std::unique_lock lock(impl->queueMutex);
    while (!impl->workerReady) {
        impl->queueChanged.wait(lock);
    }
    const bool started = SUCCEEDED(LastError());
    lock.unlock();
    if (!started) {
        Stop();
    }
    return started;
}

/// Drains final GPU copies on explicit stop, then joins the worker after all accepted frames are finalized.
HRESULT Mp4Recorder::Stop(ID3D11DeviceContext* context) {
    PrepareStop(context);
    return FinishStop();
}

/// Captures the stop deadline and requests encoder shutdown without joining it inside a rendering lock.
void Mp4Recorder::PrepareStop(ID3D11DeviceContext* context) {
    const LONGLONG time = IsRecording() ? impl->Elapsed() : -1;
    if (context && IsRecording()) {
        impl->SetError(impl->CollectReadbacks(context, true));
    }
    if (impl->worker.joinable()) {
        impl->RequestStop(time);
    }
    impl->recording.store(false, std::memory_order_release);
}

/// Waits for accepted TV samples and MP4 metadata to finish after the rendering lock has been released.
HRESULT Mp4Recorder::FinishStop() {
    if (impl->worker.joinable()) {
        impl->worker.join();
    }
    for (RecordingReadback& readback : impl->readbacks) {
        readback.texture.Reset();
        readback.pending = false;
    }
    for (RecordingFrame& frame : impl->frames) {
        frame.image = RecordingImage{};
    }
    impl->freeImages.clear();
    impl->frameCount = 0;
    return LastError();
}

/// Schedules GPU copies and hands completed pixels to the worker without resampling, encoding or waiting for the GPU.
bool Mp4Recorder::CaptureFrame(ID3D11DeviceContext* context, ID3D11Texture2D* source) {
    if (!IsRecording() || !context || !source) {
        return false;
    }
    const HRESULT result = impl->CollectReadbacks(context, false);
    if (FAILED(result)) {
        impl->SetError(result);
        impl->RequestStop();
        return false;
    }
    const LONGLONG elapsed = impl->Elapsed();
    const LONGLONG frameIndex = LONGLONG(impl->format.FramesAt(std::uint64_t(std::max(0LL, elapsed))));
    if ((!impl->format.television || !impl->format.temporalBlend) && frameIndex <= impl->lastCapturedFrame) {
        return true;
    }
    const std::uint64_t sequence = impl->nextCaptureSequence++;
    for (RecordingReadback& readback : impl->readbacks) {
        if (!readback.pending) {
            context->CopyResource(readback.texture.Get(), source);
            readback.time = elapsed;
            readback.sequence = sequence;
            readback.pending = true;
            impl->lastCapturedFrame = frameIndex;
            break;
        }
    }
    return true;
}
