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
 * Last modified for version 1.3.2.0
 */

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "ImageExport.h"
#include "PackedResource.h"
#include "resource.h"
#include <algorithm>
#include <cstring>
#include <cwchar>
#include <exception>
#include <vector>
#include <shlobj.h>
#include <shobjidl.h>
#include <wincodec.h>
#include <wrl/client.h>

#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "windowscodecs.lib")

using Microsoft::WRL::ComPtr;

typedef SIZE_T(__cdecl* EncodeFunction)(const BYTE*, int, int, int, BYTE**);
typedef void(__cdecl* FreeFunction)(void*);

/// Maps one exact RGB color to its GIF palette index.
struct GifColor {
    DWORD color;
    BYTE index;
};

/// Retains the heap-backed exact-color lookup table and the WIC palette entries.
struct GifPalette {
    GifColor* colors;
    WICColor entries[256];
    UINT count;
};

static const COMDLG_FILTERSPEC IMAGE_FILTERS[] = {
    { L"Windows Bitmap BMP (*.bmp)", L"*.bmp" },
    { L"CompuServe GIF 89a (*.gif)", L"*.gif" },
    { L"JPEG File Interchange Format (*.jpg)", L"*.jpg" },
    { L"Portable Network Graphics PNG (*.png)", L"*.png" },
    { L"Tagged Image File Format TIFF (*.tif)", L"*.tif" },
    { L"Google WebP (*.webp)", L"*.webp" }
};

static const GUID* const IMAGE_CONTAINERS[] = {
    &GUID_ContainerFormatBmp,
    &GUID_ContainerFormatGif,
    &GUID_ContainerFormatJpeg,
    &GUID_ContainerFormatPng,
    &GUID_ContainerFormatTiff
};

static constexpr wchar_t CACHE_MUTEX[] = L"Local\\FortSoft.WebP.LibraryCache";
static constexpr wchar_t CACHE_FOLDER[] = L"\\FortSoft\\Libraries\\WebP\\x86\\";
static constexpr wchar_t LIBRARY_NAME[] = L"libwebp.dll";

/// Compares every cached byte with the validated bundled library before loading it.
static bool CachedLibraryMatches(const wchar_t* path, const BYTE* bytes, DWORD size) {
    HANDLE file = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_DELETE,
        nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE) {
        return false;
    }
    LARGE_INTEGER length{};
    bool matches = GetFileSizeEx(file, &length) && length.QuadPart == size;
    BYTE buffer[4096]{};
    DWORD offset = 0;
    while (matches && offset < size) {
        const DWORD requested = std::min<DWORD>(sizeof(buffer), size - offset);
        DWORD received = 0;
        matches = ReadFile(file, buffer, requested, &received, nullptr)
            && received == requested
            && std::memcmp(buffer, bytes + offset, received) == 0;
        offset += received;
    }
    CloseHandle(file);
    return matches;
}

/// Publishes complete library bytes through a temporary file while the cache mutex is held.
static bool WriteCachedLibrary(const wchar_t* folder, const wchar_t* path, const BYTE* bytes, DWORD size) {
    wchar_t temporary[MAX_PATH]{};
    if (!GetTempFileNameW(folder, L"WPL", 0, temporary)) {
        return false;
    }
    HANDLE file = CreateFileW(temporary, GENERIC_WRITE, 0, nullptr, TRUNCATE_EXISTING,
        FILE_ATTRIBUTE_NORMAL, nullptr);
    bool success = file != INVALID_HANDLE_VALUE;
    DWORD offset = 0;
    while (success && offset < size) {
        DWORD written = 0;
        success = WriteFile(file, bytes + offset, size - offset, &written, nullptr) && written != 0;
        offset += written;
    }
    if (file != INVALID_HANDLE_VALUE) {
        success = FlushFileBuffers(file) && success;
        if (!CloseHandle(file)) {
            success = false;
        }
    }
    if (success) {
        success = MoveFileExW(temporary, path, MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH) != FALSE;
    }
    if (!success) {
        DeleteFileW(temporary);
    }
    return success;
}

/// Unpacks the checked resource and reuses or atomically replaces its checksum-specific cached DLL.
static bool ExtractWebpLibrary(wchar_t* path) {
    HMODULE instance = GetModuleHandleW(nullptr);
    HRSRC resource = FindResourceW(instance, MAKEINTRESOURCEW(IDR_LIBRARY_WEBP), RT_RCDATA);
    HGLOBAL loaded = resource ? LoadResource(instance, resource) : nullptr;
    const BYTE* packed = loaded ? static_cast<const BYTE*>(LockResource(loaded)) : nullptr;
    const DWORD packedSize = resource ? SizeofResource(instance, resource) : 0;
    BYTE* bytes = nullptr;
    DWORD size = 0;
    if (!packed || packedSize <= 12 || !UnpackLibraryBytes(packed, packedSize, &bytes, &size)) {
        return false;
    }
    HANDLE mutex = CreateMutexW(nullptr, FALSE, CACHE_MUTEX);
    const DWORD waited = mutex ? WaitForSingleObject(mutex, INFINITE) : WAIT_FAILED;
    bool success = false;
    if (waited == WAIT_OBJECT_0 || waited == WAIT_ABANDONED) {
        wchar_t folder[MAX_PATH]{};
        DWORD checksum = 0;
        std::memcpy(&checksum, packed + 8, sizeof(checksum));
        if (SUCCEEDED(SHGetFolderPathW(nullptr, CSIDL_LOCAL_APPDATA | CSIDL_FLAG_CREATE, nullptr,
            SHGFP_TYPE_CURRENT, folder))) {
            wchar_t suffix[16]{};
            swprintf_s(suffix, L"%08lX", checksum);
            const std::size_t length = wcslen(folder) + wcslen(CACHE_FOLDER) + wcslen(suffix);
            if (length + 1 + wcslen(LIBRARY_NAME) < MAX_PATH) {
                wcscat_s(folder, CACHE_FOLDER);
                wcscat_s(folder, suffix);
                wcscpy_s(path, MAX_PATH, folder);
                wcscat_s(path, MAX_PATH, L"\\");
                wcscat_s(path, MAX_PATH, LIBRARY_NAME);
                const int created = SHCreateDirectoryExW(nullptr, folder, nullptr);
                if (created == ERROR_SUCCESS || created == ERROR_ALREADY_EXISTS) {
                    success = CachedLibraryMatches(path, bytes, size)
                        || WriteCachedLibrary(folder, path, bytes, size);
                }
            }
        }
        ReleaseMutex(mutex);
    }
    if (mutex) {
        CloseHandle(mutex);
    }
    HeapFree(GetProcessHeap(), 0, bytes);
    return success;
}

/// Configures the native Save dialog and copies its selected filesystem path and image format.
static HRESULT ShowImageSaveDialog(HWND owner, const wchar_t* folder, wchar_t* path, SnapshotFormat& format) {
    ComPtr<IFileSaveDialog> dialog;
    ComPtr<IShellItem> directory;
    ComPtr<IShellItem> selected;
    HRESULT result = CoCreateInstance(__uuidof(FileSaveDialog), nullptr, CLSCTX_INPROC_SERVER,
        IID_PPV_ARGS(&dialog));
    FILEOPENDIALOGOPTIONS options = 0;
    if (SUCCEEDED(result)) {
        result = dialog->GetOptions(&options);
    }
    if (SUCCEEDED(result)) {
        result = dialog->SetOptions(options
            | FOS_FORCEFILESYSTEM
            | FOS_PATHMUSTEXIST
            | FOS_NOCHANGEDIR
            | FOS_OVERWRITEPROMPT);
    }
    if (SUCCEEDED(result)) {
        result = dialog->SetFileTypes(ARRAYSIZE(IMAGE_FILTERS), IMAGE_FILTERS);
    }
    if (SUCCEEDED(result)) {
        result = dialog->SetFileTypeIndex(static_cast<UINT>(SnapshotFormat::Png));
    }
    if (SUCCEEDED(result)) {
        result = dialog->SetDefaultExtension(L"png");
    }
    if (SUCCEEDED(result)) {
        result = dialog->SetFileName(path);
    }
    if (SUCCEEDED(result)
            && folder
            && *folder
            && SUCCEEDED(SHCreateItemFromParsingName(folder, nullptr, IID_PPV_ARGS(&directory)))) {
        result = dialog->SetFolder(directory.Get());
    }
    if (SUCCEEDED(result)) {
        result = dialog->Show(owner);
    }
    UINT type = 0;
    if (SUCCEEDED(result)) {
        result = dialog->GetFileTypeIndex(&type);
    }
    if (SUCCEEDED(result) && (type < 1 || type > ARRAYSIZE(IMAGE_FILTERS))) {
        result = E_UNEXPECTED;
    }
    if (SUCCEEDED(result)) {
        result = dialog->GetResult(&selected);
    }
    wchar_t* filename = nullptr;
    if (SUCCEEDED(result)) {
        result = selected->GetDisplayName(SIGDN_FILESYSPATH, &filename);
    }
    if (SUCCEEDED(result)) {
        if (wcslen(filename) >= MAX_PATH) {
            result = HRESULT_FROM_WIN32(ERROR_FILENAME_EXCED_RANGE);
        } else {
            wcscpy_s(path, MAX_PATH, filename);
            format = static_cast<SnapshotFormat>(type);
        }
    }
    CoTaskMemFree(filename);
    return result;
}

/// Uses the native Windows Vista Save dialog with the exact format names from MediaInfo.
HRESULT ImageExport::ChoosePath(HWND owner, const wchar_t* folder, wchar_t* path, SnapshotFormat& format) {
    const HRESULT initialized = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    if (FAILED(initialized) && initialized != RPC_E_CHANGED_MODE) {
        return initialized;
    }
    const HRESULT result = ShowImageSaveDialog(owner, folder, path, format);
    if (SUCCEEDED(initialized)) {
        CoUninitialize();
    }
    return result;
}

/// Encodes opaque top-down BGRA pixels losslessly, honoring the GPU row pitch and WebP dimensions.
static bool EncodeWebp(IStream* stream, const BYTE* pixels, unsigned width, unsigned height,
        unsigned stride) {
    if (width > 16383 || height > 16383) {
        return false;
    }
    const unsigned rowBytes = width * 4;
    std::vector<BYTE> opaque(static_cast<std::size_t>(rowBytes) * height);
    for (unsigned y = 0; y < height; ++y) {
        BYTE* row = opaque.data() + static_cast<std::size_t>(y) * rowBytes;
        std::memcpy(row, pixels + static_cast<std::size_t>(y) * stride, rowBytes);
        for (unsigned x = 0; x < width; ++x) {
            row[x * 4 + 3] = 255;
        }
    }
    wchar_t path[MAX_PATH]{};
    if (!ExtractWebpLibrary(path)) {
        return false;
    }
    const UINT previousMode = SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOOPENFILEERRORBOX);
    HMODULE module = LoadLibraryExW(path, nullptr, LOAD_WITH_ALTERED_SEARCH_PATH);
    SetErrorMode(previousMode);
    if (!module) {
        return false;
    }
    EncodeFunction encode = reinterpret_cast<EncodeFunction>(GetProcAddress(module,
        "WebPEncodeLosslessBGRA"));
    FreeFunction freeMemory = reinterpret_cast<FreeFunction>(GetProcAddress(module,
        "WebPFree"));
    if (!encode || !freeMemory) {
        FreeLibrary(module);
        return false;
    }
    BYTE* encoded = nullptr;
    const SIZE_T size = encode(opaque.data(), static_cast<int>(width), static_cast<int>(height),
        static_cast<int>(rowBytes), &encoded);
    bool success = encoded && size != 0 && size <= MAXDWORD;
    SIZE_T offset = 0;
    while (success && offset < size) {
        ULONG written = 0;
        success = SUCCEEDED(stream->Write(encoded + offset, static_cast<ULONG>(size - offset), &written))
            && written != 0;
        offset += written;
    }
    if (encoded) {
        freeMemory(encoded);
    }
    FreeLibrary(module);
    return success;
}

/// Creates an output-side temporary file so encoder failures leave an existing destination untouched.
static bool CreateImageTemporary(const wchar_t* path, wchar_t* temporary) {
    wchar_t folder[MAX_PATH]{};
    wchar_t* filename = nullptr;
    const DWORD length = GetFullPathNameW(path, MAX_PATH, folder, &filename);
    if (length == 0 || length >= MAX_PATH || !filename) {
        return false;
    }
    *filename = L'\0';
    return GetTempFileNameW(folder, L"DSI", 0, temporary) != 0;
}

/// Returns one RGB lookup key without including alpha or row padding.
static DWORD ImagePixelColor(const BYTE* pixel) {
    return pixel[0] | pixel[1] << 8 | pixel[2] << 16;
}

/// Builds the same exact GIF palette as the common writer and rejects images requiring quantization.
static HRESULT BuildGifPalette(const BYTE* pixels, unsigned width, unsigned height, unsigned stride,
        GifPalette& palette) {
    for (unsigned y = 0; y < height; ++y) {
        const BYTE* row = pixels + static_cast<SIZE_T>(y) * stride;
        for (unsigned x = 0; x < width; ++x) {
            DWORD color = ImagePixelColor(row + x * 4);
            DWORD slot = color * 2654435761U >> 20;
            while (palette.colors[slot].color && palette.colors[slot].color != color + 1) {
                slot = slot + 1 & 4095;
            }
            if (!palette.colors[slot].color) {
                if (palette.count == 256) {
                    return WINCODEC_ERR_PALETTEUNAVAILABLE;
                }
                palette.colors[slot].color = color + 1;
                palette.colors[slot].index = static_cast<BYTE>(palette.count);
                palette.entries[palette.count++] = color | 0xFF000000;
            }
        }
    }
    return S_OK;
}

/// Resolves a previously validated exact GIF color without changing its palette.
static BYTE GifPaletteIndex(const BYTE* pixel, const GifPalette& palette) {
    DWORD color = ImagePixelColor(pixel);
    DWORD slot = color * 2654435761U >> 20;
    while (palette.colors[slot].color != color + 1) {
        slot = slot + 1 & 4095;
    }
    return palette.colors[slot].index;
}

/// Detects meaningful alpha so opaque PNG and TIFF images can use the common writer's RGB output.
static bool ImageHasAlpha(const BYTE* pixels, unsigned width, unsigned height, unsigned stride) {
    for (unsigned y = 0; y < height; ++y) {
        const BYTE* row = pixels + static_cast<SIZE_T>(y) * stride;
        for (unsigned x = 0; x < width; ++x) {
            if (row[x * 4 + 3] != 255) {
                return true;
            }
        }
    }
    return false;
}

/// Streams native encoder scanlines with at most one row or 64 KiB of additional pixel storage.
static HRESULT WriteWicPixels(IWICBitmapFrameEncode* frame, REFWICPixelFormatGUID format, unsigned width,
        unsigned height, unsigned stride, const BYTE* pixels, const GifPalette& palette) {
    bool indexed = format == GUID_WICPixelFormat8bppIndexed;
    bool bgra = format == GUID_WICPixelFormat32bppBGRA;
    bool rgba = format == GUID_WICPixelFormat32bppRGBA;
    bool bgr = format == GUID_WICPixelFormat24bppBGR;
    bool rgb = format == GUID_WICPixelFormat24bppRGB;
    if (!indexed && !bgra && !rgba && !bgr && !rgb) {
        return WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT;
    }
    if (indexed && !palette.colors) {
        return WINCODEC_ERR_PALETTEUNAVAILABLE;
    }
    unsigned bytesPerPixel = 3;
    if (indexed) {
        bytesPerPixel = 1;
    } else if (bgra || rgba) {
        bytesPerPixel = 4;
    }
    unsigned rowStride = bgra ? stride : width * bytesPerPixel;
    unsigned batchHeight = std::min(height, std::max(1U, 65536U / rowStride));
    BYTE* buffer = nullptr;
    if (!bgra) {
        buffer = static_cast<BYTE*>(HeapAlloc(GetProcessHeap(), 0,
            static_cast<SIZE_T>(rowStride) * batchHeight));
        if (!buffer) {
            return E_OUTOFMEMORY;
        }
    }
    HRESULT result = S_OK;
    for (unsigned y = 0; y < height;) {
        unsigned rows = std::min(batchHeight, height - y);
        BYTE* output = bgra ? const_cast<BYTE*>(pixels + static_cast<SIZE_T>(y) * stride) : buffer;
        if (!bgra) {
            for (unsigned row = 0; row < rows; ++row) {
                const BYTE* input = pixels + static_cast<SIZE_T>(y + row) * stride;
                BYTE* destination = output + static_cast<SIZE_T>(row) * rowStride;
                for (unsigned x = 0; x < width; ++x) {
                    const BYTE* pixel = input + x * 4;
                    if (indexed) {
                        destination[x] = GifPaletteIndex(pixel, palette);
                    } else {
                        BYTE* encoded = destination + x * bytesPerPixel;
                        encoded[0] = rgb || rgba ? pixel[2] : pixel[0];
                        encoded[1] = pixel[1];
                        encoded[2] = rgb || rgba ? pixel[0] : pixel[2];
                        if (rgba) {
                            encoded[3] = pixel[3];
                        }
                    }
                }
            }
        }
        result = frame->WritePixels(rows, rowStride, rows * rowStride, output);
        if (FAILED(result)) {
            break;
        }
        y += rows;
    }
    if (buffer) {
        HeapFree(GetProcessHeap(), 0, buffer);
    }
    return result;
}

/// Encodes exact-color GIF or native RGB/BGRA scanlines without copying the complete image into WIC.
static HRESULT EncodeWic(IWICImagingFactory* factory, IStream* stream, SnapshotFormat format, unsigned width,
        unsigned height, unsigned stride, const BYTE* pixels) {
    GifPalette colors{};
    HRESULT result = S_OK;
    if (format == SnapshotFormat::Gif) {
        colors.colors = static_cast<GifColor*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
            4096 * sizeof(GifColor)));
        if (!colors.colors) {
            return E_OUTOFMEMORY;
        }
        result = BuildGifPalette(pixels, width, height, stride, colors);
    }
    ComPtr<IWICBitmapEncoder> encoder;
    ComPtr<IWICBitmapFrameEncode> frame;
    ComPtr<IPropertyBag2> properties;
    ComPtr<IWICPalette> palette;
    if (SUCCEEDED(result)) {
        result = factory->CreateEncoder(*IMAGE_CONTAINERS[static_cast<unsigned>(format) - 1],
            nullptr, &encoder);
    }
    if (SUCCEEDED(result)) {
        result = encoder->Initialize(stream, WICBitmapEncoderNoCache);
    }
    if (SUCCEEDED(result)) {
        result = encoder->CreateNewFrame(&frame, &properties);
    }
    if (SUCCEEDED(result)) {
        result = frame->Initialize(properties.Get());
    }
    if (SUCCEEDED(result)) {
        result = frame->SetSize(width, height);
    }
    if (SUCCEEDED(result) && format != SnapshotFormat::Gif) {
        result = frame->SetResolution(96, 96);
    }
    bool alpha = (format == SnapshotFormat::Png || format == SnapshotFormat::Tiff)
        && ImageHasAlpha(pixels, width, height, stride);
    WICPixelFormatGUID target = GUID_WICPixelFormat24bppBGR;
    if (format == SnapshotFormat::Gif) {
        target = GUID_WICPixelFormat8bppIndexed;
    } else if (alpha) {
        target = GUID_WICPixelFormat32bppBGRA;
    }
    if (SUCCEEDED(result)) {
        result = frame->SetPixelFormat(&target);
    }
    if (SUCCEEDED(result)
            && alpha
            && target != GUID_WICPixelFormat32bppBGRA
            && target != GUID_WICPixelFormat32bppRGBA) {
        result = WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT;
    }
    if (SUCCEEDED(result) && format == SnapshotFormat::Gif) {
        if (target != GUID_WICPixelFormat8bppIndexed) {
            result = WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT;
        } else {
            result = factory->CreatePalette(&palette);
        }
        if (SUCCEEDED(result)) {
            result = palette->InitializeCustom(colors.entries, colors.count);
        }
        if (SUCCEEDED(result)) {
            result = frame->SetPalette(palette.Get());
        }
    }
    if (SUCCEEDED(result)) {
        result = WriteWicPixels(frame.Get(), target, width, height, stride, pixels, colors);
    }
    if (SUCCEEDED(result)) {
        result = frame->Commit();
    }
    if (SUCCEEDED(result)) {
        result = encoder->Commit();
    }
    if (colors.colors) {
        HeapFree(GetProcessHeap(), 0, colors.colors);
    }
    return result;
}

/// Encodes one native image or a lossless WebP into a file or an in-memory stream.
static bool EncodeSnapshot(const wchar_t* path, SnapshotFormat format, unsigned width, unsigned height,
        unsigned stride, const BYTE* pixels) {
    ComPtr<IWICImagingFactory> factory;
    ComPtr<IWICStream> stream;
    ComPtr<IStream> memory;
    HRESULT result = CoCreateInstance(CLSID_WICImagingFactory1, nullptr, CLSCTX_INPROC_SERVER,
        IID_PPV_ARGS(&factory));
    if (SUCCEEDED(result)) {
        result = factory->CreateStream(&stream);
    }
    if (SUCCEEDED(result)) {
        if (path) {
            result = stream->InitializeFromFilename(path, GENERIC_WRITE);
        } else {
            result = CreateStreamOnHGlobal(nullptr, TRUE, &memory);
            if (SUCCEEDED(result)) {
                result = stream->InitializeFromIStream(memory.Get());
            }
        }
    }
    if (FAILED(result)) {
        return false;
    }
    if (format == SnapshotFormat::Webp) {
        return EncodeWebp(stream.Get(), pixels, width, height, stride);
    }
    return SUCCEEDED(EncodeWic(factory.Get(), stream.Get(), format, width, height, stride, pixels));
}

/// Saves the selected format atomically; a null destination tests the same encoder in memory.
bool ImageExport::Save(const wchar_t* path, SnapshotFormat format, unsigned width, unsigned height,
        unsigned stride, const BYTE* pixels) {
    if (!pixels
            || width == 0
            || height == 0
            || width > MAXUINT / 4
            || stride < width * 4
            || height > MAXUINT / stride
            || static_cast<unsigned>(format) < 1
            || static_cast<unsigned>(format) > 6
            || path && !*path) {
        return false;
    }
    wchar_t temporary[MAX_PATH]{};
    if (path && !CreateImageTemporary(path, temporary)) {
        return false;
    }
    const HRESULT initialized = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    bool saved = false;
    if (SUCCEEDED(initialized) || initialized == RPC_E_CHANGED_MODE) {
        try {
            saved = EncodeSnapshot(path ? temporary : nullptr, format, width, height, stride, pixels);
        } catch (const std::exception&) {
            saved = false;
        }
    }
    if (SUCCEEDED(initialized)) {
        CoUninitialize();
    }
    if (path) {
        if (saved) {
            saved = MoveFileExW(temporary, path, MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH) != FALSE;
        }
        if (!saved) {
            DeleteFileW(temporary);
        }
    }
    return saved;
}
