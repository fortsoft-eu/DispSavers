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

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "AppSettings.h"
#include "Localization.h"
#include "MixedControls.h"
#include "ProgramIcons.h"
#include "PersistWindowState.h"
#include "Renderer.h"
#include "SelectionEdit.h"
#include "Wow64Redirection.h"
#include "WindowRedrawScope.h"
#include "resource.h"
#include "MonitorInfo.h"
#include <windows.h>
#include <avrt.h>
#include <commctrl.h>
#include <commdlg.h>
#include <dwmapi.h>
#include <RestartManager.h>
#include <shlobj.h>
#include <shellapi.h>
#include <uxtheme.h>
#include <vssym32.h>
#include <winver.h>
#include <windowsx.h>
#include <algorithm>
#include <array>
#include <atomic>
#include <cmath>
#include <cwchar>
#include <cwctype>
#include <limits>
#include <memory>
#include <mutex>
#include <optional>
#include <string>
#include <thread>
#include <vector>

#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "comdlg32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "avrt.lib")
#pragma comment(lib, "dwmapi.lib")
#pragma comment(lib, "uxtheme.lib")
#pragma comment(lib, "Version.lib")

/// Window classes and product constants
constexpr wchar_t PRODUCT_NAME[] = L"FlyingSolids";
constexpr wchar_t RENDER_CLASS[] = L"FortSoft.FlyingSolids.Render";
constexpr wchar_t SETTINGS_CLASS[] = L"FortSoft.FlyingSolids.Settings";
constexpr wchar_t INSTANCE_MUTEX[] = L"Local\\FortSoft.FlyingSolids.Standalone";
constexpr wchar_t INSTANCE_WINDOW_PROPERTY[] = L"FortSoft.FlyingSolids.Standalone.Window";
constexpr wchar_t WEBSITE_URL[] = L"https://fortsoft.cz/dispsavers/";
constexpr wchar_t SCREEN_SAVER_PATH_SUFFIX[] = L"\\FlyingSolids.scr";
constexpr wchar_t SCREEN_SAVER_EXTENSION[] = L".scr";
constexpr wchar_t STAGING_FILE_SUFFIX[] = L".installing";
constexpr wchar_t PNG_EXTENSION[] = L"png";
constexpr wchar_t MP4_EXTENSION[] = L"mp4";
constexpr wchar_t SHELL_OPEN_VERB[] = L"open";
constexpr wchar_t INSTALL_ELEVATED_ARGUMENT[] = L"/install-elevated";
constexpr wchar_t UNINSTALL_ELEVATED_ARGUMENT[] = L"/uninstall-elevated";
constexpr wchar_t KERNEL_LIBRARY[] = L"kernel32.dll";

/// Windows screen-saver registry constants
constexpr wchar_t DESKTOP_REGISTRY_PATH[] = L"Control Panel\\Desktop";
constexpr wchar_t SCREEN_SAVER_PATH_VALUE_NAME[] = L"SCRNSAVE.EXE";
constexpr wchar_t SCREEN_SAVER_ACTIVE_VALUE_NAME[] = L"ScreenSaveActive";

/// Settings-window layout and animation constants
constexpr int SETTINGS_WIDTH = 945;
constexpr int SCREEN_SAVER_SETTINGS_HEIGHT = 685;
constexpr int APPLICATION_SETTINGS_HEIGHT = 705;
constexpr int PUSH_BUTTON_HEIGHT = 28;
constexpr int ABOUT_ICON_SIZE = 32;
constexpr int ABOUT_LARGE_ICON_SIZE = 48;
constexpr int ABOUT_LARGE_ICON_DPI = 130;
constexpr int ABOUT_WEB_GAP_DLU = 8;
constexpr int RECORDING_COMBO_WIDTH_DLU = 130;
constexpr int COMBO_BOX_MAX_VISIBLE_ITEMS = 13;
constexpr int MONITOR_COLUMN_COUNT = 8;
constexpr double SYSTEM_PREVIEW_SPEED_MULTIPLIER = 64.0;
constexpr wchar_t NO_ANIMATION_MONITORS[] = L"{none}";

/// Private messages, timers and subclass identifiers
constexpr UINT ENSURE_SETTINGS_CONTROL_VISIBLE = WM_APP + 1;
constexpr UINT RESTORE_SETTINGS_FOCUS = WM_APP + 2;
constexpr UINT ACTIVATE_APPLICATION_WINDOW = WM_APP + 3;
constexpr UINT UPDATE_SETTINGS_ACTION_BUTTONS = WM_APP + 4;
constexpr UINT UPDATE_SETTINGS_CONTROL_METRICS = WM_APP + 5;
constexpr UINT UPDATE_MONITOR_ANIMATION_CONTROLS = WM_APP + 6;
constexpr UINT_PTR ABOUT_CONTROL_SUBCLASS = 0xF503;
constexpr UINT_PTR INFORMATION_TEXT_SUBCLASS_ID = 0xF504;
constexpr UINT_PTR COMBO_BOX_DROPDOWN_SUBCLASS_ID = 0xF505;
constexpr UINT SCREEN_SAVER_CHECK_INTERVAL = 1000;

/// Optional Windows 7 power-request entry points, resolved without raising the minimum supported system.
using CreatePowerRequest = HANDLE(WINAPI*)(PREASON_CONTEXT);
using SetPowerRequest = BOOL(WINAPI*)(HANDLE, POWER_REQUEST_TYPE);
using GetSystemWow64DirectoryWFunction = UINT(WINAPI*)(LPWSTR, UINT);
using StartSession = DWORD(WINAPI*)(DWORD*, DWORD, WCHAR[]);
using EndSession = DWORD(WINAPI*)(DWORD);
using RegisterResources = DWORD(WINAPI*)(DWORD, UINT, LPCWSTR[], UINT, RM_UNIQUE_PROCESS[], UINT, LPCWSTR[]);
using GetList = DWORD(WINAPI*)(DWORD, UINT*, UINT*, RM_PROCESS_INFO[], LPDWORD);

/// Supported executable and screen-saver invocation modes.
enum class RunMode {
    Application,
    SettingsPreview,
    ScreenSaver,
    Preview,
    SelfTest,
    SelfTestAllMonitors
};

/// User-facing reason that prevents replacement of the installed saver file.
enum class ScreenSaverFileUse {
    None,
    Other,
    RunningSaver,
    SystemPreview,
    Settings
};

/// Z-order layers used to preserve clipped, full-width label controls.
enum class SettingsControlLayer {
    Foreground,
    Checkbox,
    Label
};

/// Stable identifiers used by settings and information-window controls.
enum ControlId {
    ID_RECORD_TOGGLE = 1001,
    ID_PAUSE,
    ID_INSTALL,
    ID_RECORDING_SETTINGS,
    ID_SNAPSHOT,
    ID_HELP,
    ID_ABOUT,
    ID_STATUS,
    ID_LANGUAGE,
    ID_OBJECT_SPEED,
    ID_CAMERA_SPEED,
    ID_COPY_COUNT,
    ID_OBJECT_SIZE,
    ID_CAMERA_STATIC,
    ID_CAMERA_FLIGHT,
    ID_OK = IDOK,
    ID_CANCEL = IDCANCEL,
    ID_PREVIEW_TOGGLE = 1018,
    ID_SOLIDS_GROUP,
    ID_MONITOR_GROUP,
    ID_LANGUAGE_LABEL = 1101,
    ID_OBJECT_SPEED_LABEL,
    ID_CAMERA_SPEED_LABEL,
    ID_COPY_COUNT_LABEL,
    ID_OBJECT_SIZE_LABEL,
    ID_ALL_SOLIDS = 1150,
    ID_NO_SOLIDS,
    ID_MONITOR_LIST,
    ID_MAIN_LIGHT = 1160,
    ID_FILL_LIGHT,
    ID_PREVENT_SCREEN_SAVER,
    ID_AMBIENT_LIGHT,
    ID_RIM_LIGHT,
    ID_SOLID_FIRST = 1200,
    ID_INSTALL_POLL_TIMER = 1400,
    ID_STATUS_RESET_TIMER,
    ID_SCREEN_SAVER_CHECK_TIMER,
    ID_MENU_ABOUT_OPEN = 1600,
    ID_MENU_ABOUT_COPY_URL,
    ID_MENU_ABOUT_COPY_INFORMATION
};

/// Controls describing one independent animation property.
struct AnimationControl {
    int id;
    AnimationProperty property;
    AnimationProperty dependency = AnimationProperty::Count;
};

/// Slider and label identifiers associated with one numeric animation property.
struct AnimationSliderControl {
    int id;
    int labelId;
    AnimationProperty property;
};

/// Text-bearing controls that share one rendered baseline.
struct SettingsControlAlignment {
    int control;
    int reference;
};

constexpr int ID_ANIMATION_PRIMARY = ID_CAMERA_STATIC;
constexpr int ID_ANIMATION_SECONDARY = ID_CAMERA_FLIGHT;
constexpr int ID_ANIMATION_GROUP = ID_SOLIDS_GROUP;
constexpr int ID_ALL_ANIMATIONS = ID_ALL_SOLIDS;
constexpr int ID_NO_ANIMATIONS = ID_NO_SOLIDS;
constexpr AnimationProperty ANIMATION_RADIO_PROPERTY = AnimationProperty::CameraFlight;
constexpr AnimationProperty ANIMATION_ENABLED_PROPERTY = AnimationProperty::EnabledSolids;
constexpr std::uint32_t ALL_ANIMATION_MASK = ALL_SOLID_MASK;
constexpr int ANIMATION_RADIO_IDS[]{ ID_CAMERA_STATIC, ID_CAMERA_FLIGHT };
constexpr int ANIMATION_TAB_CHECKBOX_IDS[]{ ID_AMBIENT_LIGHT, ID_RIM_LIGHT, ID_MAIN_LIGHT, ID_FILL_LIGHT };
constexpr AnimationSliderControl ANIMATION_SLIDERS[]{
    { ID_OBJECT_SPEED, ID_OBJECT_SPEED_LABEL, AnimationProperty::ObjectSpeed },
    { ID_CAMERA_SPEED, ID_CAMERA_SPEED_LABEL, AnimationProperty::CameraSpeed },
    { ID_COPY_COUNT, ID_COPY_COUNT_LABEL, AnimationProperty::CopyCount },
    { ID_OBJECT_SIZE, ID_OBJECT_SIZE_LABEL, AnimationProperty::ObjectSize }
};
constexpr int OPAQUE_SETTINGS_LABEL_IDS[]{ ID_MONITOR_GROUP };
constexpr AnimationControl ANIMATION_CHECKBOXES[]{
    { ID_AMBIENT_LIGHT, AnimationProperty::AmbientLight },
    { ID_RIM_LIGHT, AnimationProperty::RimLight },
    { ID_MAIN_LIGHT, AnimationProperty::MainLight },
    { ID_FILL_LIGHT, AnimationProperty::FillLight }
};
constexpr SettingsControlAlignment ANIMATION_CONTROL_ALIGNMENTS[]{
    { ID_AMBIENT_LIGHT, ID_CAMERA_STATIC },
    { ID_RIM_LIGHT, ID_CAMERA_FLIGHT },
    { ID_MAIN_LIGHT, ID_CAMERA_STATIC },
    { ID_FILL_LIGHT, ID_CAMERA_FLIGHT }
};

/// Stable source metadata and displayed values of one monitor-list item.
struct MonitorListEntry {
    MonitorDetails details;
    std::array<std::wstring, MONITOR_COLUMN_COUNT> text;
};

/// Window categories belonging to processes that lock the saver file.
struct LockedScreenSaverWindows {
    std::vector<DWORD> processIds;
    bool settings = false;
    bool systemPreview = false;
    bool runningSaver = false;
};

/// Per-monitor animation window, simulation, renderer and worker thread.
struct RenderSurface {
    /// Initializes this monitor's independent simulation with the supplied seed.
    explicit RenderSurface(unsigned seed) : simulation(seed) {}

    /// Window and rendering state
    HWND window = nullptr;
    std::wstring monitorDevice;
    RECT bounds{};
    Simulation simulation;
    std::unique_ptr<Renderer> renderer;
    unsigned refreshRate = 60;
    double refreshFrequency = 60.0;

    /// Render-thread state
    std::thread renderThread;
    std::mutex rendererMutex;
    std::atomic_bool stopRequested = false;
    std::atomic_uint renderedFrames = 0;
    std::mutex settingsMutex;
    MonitorAnimation runtimeSettings;
};

/// Process-wide state shared by the UI thread and all rendering threads.
struct Application {
    /// Instance, windows and operating-system handles
    HINSTANCE instance = nullptr;
    HWND controlWindow = nullptr;
    HWND previewParent = nullptr;
    HWND status = nullptr;
    HANDLE installProcess = nullptr;
    HANDLE screenSaverInhibition = nullptr;
    ProgramIcons programIcons;

    /// Invocation mode and owned model state
    RunMode mode = RunMode::Application;
    AppSettings settings{};
    std::vector<std::unique_ptr<RenderSurface>> surfaces;

    /// Application and screen-saver lifecycle
    std::atomic_bool paused = false;
    std::atomic_bool closing = false;
    bool confirmingClose = false;
    POINT initialMouse{};
    ULONGLONG saverStarted = 0;
    unsigned refreshRate = 60;

    /// Self-test state
    bool selfTestFailed = false;
    bool selfTestFlight = false;
    bool selfTestSnapshot = false;

    /// Screen-saver installation state
    bool uninstallingScreenSaver = false;
};

/// Prepared native control values applied together after the complete monitor selection is known.
struct SettingsControlState {
    HWND window = nullptr;
    std::optional<bool> enabled;
    std::optional<UINT> check;
    std::optional<LONG> position;
    std::optional<std::wstring> caption;
    std::optional<bool> mixed;
};

/// Mutable state owned by one settings window.
struct SettingsWindowData {
    /// Settings model and monitor topology
    AppSettings original;
    AppSettings* settings = nullptr;
    std::vector<DisplayMonitor> monitors;
    std::vector<MonitorListEntry> monitorListEntries;
    std::vector<std::wstring> selectedAnimationDevices;
    int monitorSortColumn = -1;
    bool monitorSortAscending = true;
    bool monitorColumnsInitialized = false;
    bool monitorSelectionInitialized = false;
    bool monitorSelectionUpdatePending = false;

    /// Window resources
    HFONT systemDialogFont = nullptr;
    HWND lastFocusedControl = nullptr;
    HWND defaultButton = nullptr;
    HWND contentWindow = nullptr;
    DWORD scrollStyle = 0;

    /// Window mode and interaction state
    bool completed = false;
    bool appMode = false;
    bool screenSaverSettings = false;
    bool previewActive = false;
    AppLanguage language = AppLanguage::EnglishUs;
    bool updating = false;

    /// Virtual content dimensions used by the scrollable layout
    int contentWidth = 0;
    int contentHeight = 0;
};

/// Settings reference and native font owned by one recording-settings dialog.
struct RecordingWindowData {
    AppSettings* settings = nullptr;
    HWND owner = nullptr;
    AppLanguage language = AppLanguage::EnglishUs;
    HFONT font = nullptr;
    bool initialized = false;
};

/// Initial control geometry used by the anchored Help and About layout.
struct InformationWindowLayout {
    SIZE client = {};
    RECT text = {};
    RECT close = {};
    RECT product = {};
    RECT website = {};
    RECT link = {};
    bool initialized = false;
};

/// Presentation state and resources owned by a Help or About window.
struct InformationWindowData {
    AppSettings* settings = nullptr;
    HFONT licenseFont = nullptr;
    bool initialized = false;
    bool help = false;
    bool appMode = false;
    AppLanguage language = AppLanguage::EnglishUs;
};

/// Window and virtual-client dimensions selected for the current work area.
struct SettingsWindowLayout {
    DWORD style = 0;
    DWORD scrollStyle = 0;
    int width = 0;
    int height = 0;
    int contentWidth = 0;
    int contentHeight = 0;
};

/// Scroll-bar identifier, virtual extent and visible page size.
struct ScrollBarData {
    int bar;
    int extent;
    UINT page;
};

/// Child window paired with client-relative geometry for stable Z-order sorting.
struct PositionedControl {
    HWND window = nullptr;
    RECT rect{};
};

/// Font metrics used by the copied CalClock information-text renderer.
struct UiTextLine {
    LONG ascent;
    LONG descent;
    LONG gap;
};

/// Application instance
static Application* app = nullptr;

/// Information windows
static HWND helpWindow = nullptr;
static HWND aboutWindow = nullptr;
static HWND aboutTooltip = nullptr;
static PersistWindowState helpWindowState;
static PersistWindowState aboutWindowState;
static HWND recordingSettingsWindow = nullptr;

/// Initial information-window control rectangles
static InformationWindowLayout helpWindowLayout;
static InformationWindowLayout aboutWindowLayout;

/// Cross-section forward declarations

/// Aligns native text-bearing controls using their current fonts and theme content rectangles.
static void AlignSettingsControl(HWND control, HWND reference, LONG baselineDistance = 0);

/// Applies the selected animation monitors, creating or removing their render surfaces as needed.
static void ApplyAnimationMonitors();

/// Creates an animation window and initializes its independent simulation and renderer.
static bool AddRenderSurface(Application& app, const RECT& bounds, HWND parent, unsigned seed,
    const std::wstring& monitorDevice = std::wstring());

/// Starts installation or uninstallation according to the current screen-saver state.
static void RequestScreenSaverChange(HWND owner);

/// Extends settings text controls to the content edge and restores their clipping Z-order.
static void UpdateSettingsTextControlLayout(HWND parent);

/// Aligns settings text baselines using CalClock's native control-metric calculation.
static void UpdateSettingsControlMetrics(HWND window);

static void UpdateComboBoxDropDownSize(HWND combo);

/// Updates the language and presentation mode of all open information windows.
static void RefreshInformationWindows(AppLanguage language, bool appMode);

/// Refreshes localized recording captions and metrics without replacing unconfirmed choices.
static void RefreshRecordingSettingsWindow(HWND window, RecordingWindowData& data);

/// Resolves an explicit language preference or falls back to the operating system.
static AppLanguage ResolvedLanguage(const AppSettings& settings) {
    if (settings.language >= 0 && settings.language < static_cast<int>(AppLanguage::Count)) {
        return static_cast<AppLanguage>(settings.language);
    }
    return DetectSystemLanguage();
}

/// Returns the language currently visible in application-owned windows.
static AppLanguage ActiveLanguage() {
    if (app) {
        return ResolvedLanguage(app->settings);
    }
    return DetectSystemLanguage();
}

/// Appends one monitor reported by EnumDisplayMonitors to the caller's collection.
static BOOL CALLBACK CollectDisplayMonitor(HMONITOR monitor, HDC, LPRECT, LPARAM parameter) {
    MONITORINFOEXW info{};
    info.cbSize = sizeof(info);
    if (!GetMonitorInfoW(monitor, &info)) {
        return TRUE;
    }
    std::vector<DisplayMonitor>* monitors = reinterpret_cast<std::vector<DisplayMonitor>*>(parameter);
    monitors->push_back(DisplayMonitor{
        info.rcMonitor,
        info.rcWork,
        info.szDevice,
        (info.dwFlags & MONITORINFOF_PRIMARY) != 0
    });
    return TRUE;
}

/// Enumerates displays with the primary monitor first and stable geometric ordering.
static std::vector<DisplayMonitor> AvailableMonitors() {
    std::vector<DisplayMonitor> monitors;
    EnumDisplayMonitors(nullptr, nullptr, CollectDisplayMonitor, reinterpret_cast<LPARAM>(&monitors));
    std::stable_sort(monitors.begin(), monitors.end(), [](const DisplayMonitor& left, const DisplayMonitor& right) {
        if (left.primary != right.primary) {
            return left.primary;
        }
        if (left.rect.top != right.rect.top) {
            return left.rect.top < right.rect.top;
        }
        return left.rect.left < right.rect.left;
    });
    return monitors;
}

/// Initializes stable per-monitor camera defaults from the current topology.
static void InitializeMonitorAnimations(AppSettings& settings, const std::vector<DisplayMonitor>& monitors) {
    std::vector<std::wstring> devices;
    devices.reserve(monitors.size());
    for (const DisplayMonitor& monitor : monitors) {
        devices.push_back(monitor.device);
    }
    settings.InitializeMonitorAnimations(devices);
}

/// Chooses the saved monitor, otherwise the first available secondary display.
static std::size_t PreferredMonitorIndex(const std::vector<DisplayMonitor>& monitors, const std::wstring& device) {
    for (std::size_t index = 0; index < monitors.size(); index++) {
        if (!device.empty() && _wcsicmp(monitors[index].device.c_str(), device.c_str()) == 0) {
            return index;
        }
    }
    for (std::size_t index = 0; index < monitors.size(); index++) {
        if (!monitors[index].primary) {
            return index;
        }
    }
    return 0;
}

/// Tests membership in the semicolon-delimited monitor-device setting.
static bool MonitorDeviceSelected(const std::wstring& devices, const std::wstring& device) {
    std::size_t begin = 0;
    while (begin <= devices.size()) {
        const std::size_t end = devices.find(L';', begin);
        const std::wstring token = devices.substr(begin, end == std::wstring::npos ? std::wstring::npos : end - begin);
        if (!token.empty() && _wcsicmp(token.c_str(), device.c_str()) == 0) {
            return true;
        }
        if (end == std::wstring::npos) {
            break;
        }
        begin = end + 1;
    }
    return false;
}

/// Serializes selected monitor device names for registry storage.
static std::wstring JoinMonitorDevices(const std::vector<DisplayMonitor>& monitors,
        const std::vector<std::size_t>& indices) {
    std::wstring result;
    for (const std::size_t index : indices) {
        if (index >= monitors.size()) {
            continue;
        }
        if (!result.empty()) {
            result += L';';
        }
        result += monitors[index].device;
    }
    return result;
}

/// Resolves persisted device names to indices in the current monitor topology.
static std::vector<std::size_t> SelectedMonitorIndices(const std::vector<DisplayMonitor>& monitors,
        const std::wstring& devices) {
    std::vector<std::size_t> result;
    for (std::size_t index = 0; index < monitors.size(); index++) {
        if (MonitorDeviceSelected(devices, monitors[index].device)) {
            result.push_back(index);
        }
    }
    return result;
}

/// Reports whether standalone animation is explicitly disabled on every monitor.
static bool NoAnimationMonitorsSelected(const std::wstring& devices) {
    return _wcsicmp(devices.c_str(), NO_ANIMATION_MONITORS) == 0;
}

/// Finds a device in the current monitor topology without depending on ListView row order.
static std::size_t MonitorIndexForDevice(const std::vector<DisplayMonitor>& monitors, const std::wstring& device) {
    for (std::size_t index = 0; index < monitors.size(); index++) {
        if (_wcsicmp(monitors[index].device.c_str(), device.c_str()) == 0) {
            return index;
        }
    }
    return monitors.size();
}

/// Finds an existing animation surface by its persistent monitor device name.
static RenderSurface* MonitorSurface(const std::wstring& device) {
    if (app) {
        for (const std::unique_ptr<RenderSurface>& surface : app->surfaces) {
            if (_wcsicmp(surface->monitorDevice.c_str(), device.c_str()) == 0) {
                return surface.get();
            }
        }
    }
    return nullptr;
}

/// Finds the active recording source even when the selected monitor order changes.
static RenderSurface* RecordingSurface() {
    if (app) {
        for (const std::unique_ptr<RenderSurface>& surface : app->surfaces) {
            if (surface->renderer && surface->renderer->IsRecording()) {
                return surface.get();
            }
        }
    }
    return nullptr;
}

/// Keeps capture and status commands on the recording source, otherwise using the first active surface.
static RenderSurface* PrimarySurface() {
    RenderSurface* recording = RecordingSurface();
    if (recording) {
        return recording;
    }
    if (app && !app->surfaces.empty()) {
        return app->surfaces.front().get();
    }
    return nullptr;
}

/// Reports whether the primary surface has a rendered frame and can accept capture commands.
static bool HasReadyPrimarySurface() {
    RenderSurface* surface = PrimarySurface();
    return surface && surface->renderer && surface->renderedFrames.load(std::memory_order_relaxed) != 0
        && !surface->stopRequested.load(std::memory_order_relaxed);
}

/// Reports whether any animation surface can accept a global pause or resume command.
static bool HasReadyAnimationSurface() {
    if (!app) {
        return false;
    }
    for (const std::unique_ptr<RenderSurface>& surface : app->surfaces) {
        if (surface->renderer && surface->renderedFrames.load(std::memory_order_relaxed) != 0
                && !surface->stopRequested.load(std::memory_order_relaxed)) {
            return true;
        }
    }
    return false;
}

/// Reports whether a top-level window is shown on the current virtual desktop and is not minimized.
static bool IsUncloakedWindowVisible(HWND window) {
    if (!IsWindowVisible(window) || IsIconic(window)) {
        return false;
    }
    DWORD cloaked = 0;
    DwmGetWindowAttribute(window, DWMWA_CLOAKED, &cloaked, sizeof(cloaked));
    return cloaked == 0;
}

/// Reports whether the animation's desktop is currently displayed rather than locked or switched away.
static bool IsAnimationDesktopVisible() {
    HDESK inputDesktop = OpenInputDesktop(0, FALSE, DESKTOP_READOBJECTS);
    if (!inputDesktop) {
        return false;
    }
    wchar_t inputName[256]{};
    wchar_t threadName[256]{};
    DWORD required = 0;
    const bool visible = GetUserObjectInformationW(inputDesktop, UOI_NAME, inputName, sizeof(inputName), &required)
        && GetUserObjectInformationW(GetThreadDesktop(GetCurrentThreadId()), UOI_NAME, threadName, sizeof(threadName),
            &required)
        && _wcsicmp(inputName, threadName) == 0;
    CloseDesktop(inputDesktop);
    return visible;
}

/// Reports whether a covering window can be treated as opaque when checking animation visibility.
static bool IsOpaqueWindow(HWND window) {
    if ((GetWindowLongPtrW(window, GWL_EXSTYLE) & WS_EX_LAYERED) == 0) {
        return true;
    }
    COLORREF colorKey = 0;
    BYTE alpha = 0;
    DWORD flags = 0;
    return GetLayeredWindowAttributes(window, &colorKey, &alpha, &flags)
        && (flags & LWA_COLORKEY) == 0
        && ((flags & LWA_ALPHA) == 0 || alpha == 255);
}

/// Removes one opaque window's shape from the remaining visible animation region.
static void SubtractCoveringWindow(HRGN visible, HWND window) {
    RECT bounds{};
    if (!GetWindowRect(window, &bounds)) {
        return;
    }
    HRGN covering = CreateRectRgn(0, 0, 0, 0);
    if (!covering) {
        return;
    }
    if (GetWindowRgn(window, covering) != ERROR) {
        OffsetRgn(covering, bounds.left, bounds.top);
    } else {
        SetRectRgn(covering, bounds.left, bounds.top, bounds.right, bounds.bottom);
    }
    CombineRgn(visible, visible, covering, RGN_DIFF);
    DeleteObject(covering);
}

/// Reports whether any on-screen part of an animation client area remains uncovered by opaque windows.
static bool IsAnimationWindowVisible(HWND window) {
    if (!IsUncloakedWindowVisible(window)) {
        return false;
    }
    RECT bounds{};
    MONITORINFO monitor{};
    monitor.cbSize = sizeof(monitor);
    if (!GetClientRect(window, &bounds) || !GetMonitorInfoW(MonitorFromWindow(window, MONITOR_DEFAULTTONULL), &monitor)) {
        return false;
    }
    MapWindowPoints(window, HWND_DESKTOP, reinterpret_cast<POINT*>(&bounds), 2);
    if (!IntersectRect(&bounds, &bounds, &monitor.rcMonitor)) {
        return false;
    }
    HRGN visible = CreateRectRgn(bounds.left, bounds.top, bounds.right, bounds.bottom);
    if (!visible) {
        return false;
    }
    for (HWND covering = GetWindow(window, GW_HWNDPREV); covering; covering = GetWindow(covering, GW_HWNDPREV)) {
        if (IsUncloakedWindowVisible(covering) && IsOpaqueWindow(covering)) {
            SubtractCoveringWindow(visible, covering);
        }
        if (GetRgnBox(visible, &bounds) == NULLREGION) {
            break;
        }
    }
    const bool uncovered = GetRgnBox(visible, &bounds) > NULLREGION;
    DeleteObject(visible);
    return uncovered;
}

/// Enables screen-saver inhibition only for an opted-in, unpaused standalone animation that is actually visible.
static bool ShouldInhibitScreenSaver() {
    if (!app
            || app->mode != RunMode::Application
            || !app->settings.preventScreenSaver
            || app->paused.load(std::memory_order_relaxed)
            || app->closing.load(std::memory_order_relaxed)
            || !IsAnimationDesktopVisible()) {
        return false;
    }
    for (const std::unique_ptr<RenderSurface>& surface : app->surfaces) {
        const MonitorAnimation& animation = app->settings.AnimationForMonitor(surface->monitorDevice);
        if (animation.Value(ANIMATION_ENABLED_PROPERTY) != 0 && surface->renderer
                && surface->renderedFrames.load(std::memory_order_relaxed) != 0
                && !surface->stopRequested.load(std::memory_order_relaxed)
                && IsAnimationWindowVisible(surface->window)) {
            return true;
        }
    }
    return false;
}

/// Releases the process-owned display request without changing the user's screen-saver configuration.
static void ReleaseScreenSaverInhibition(Application& application) {
    if (application.screenSaverInhibition) {
        CloseHandle(application.screenSaverInhibition);
        application.screenSaverInhibition = nullptr;
    }
}

/// Uses a Windows 7 display request while animation is visible; older systems retain native SC_SCREENSAVE handling.
static void UpdateScreenSaverInhibition() {
    if (!app) {
        return;
    }
    if (!ShouldInhibitScreenSaver()) {
        ReleaseScreenSaverInhibition(*app);
        return;
    }
    if (app->screenSaverInhibition) {
        return;
    }
    HMODULE kernel = GetModuleHandleW(KERNEL_LIBRARY);
    if (!kernel) {
        return;
    }
    const CreatePowerRequest createRequest =
        reinterpret_cast<CreatePowerRequest>(GetProcAddress(kernel, "PowerCreateRequest"));
    const SetPowerRequest setRequest = reinterpret_cast<SetPowerRequest>(GetProcAddress(kernel, "PowerSetRequest"));
    if (!createRequest || !setRequest) {
        return;
    }
    REASON_CONTEXT reason{};
    reason.Version = POWER_REQUEST_CONTEXT_VERSION;
    reason.Flags = POWER_REQUEST_CONTEXT_SIMPLE_STRING;
    reason.Reason.SimpleReasonString = const_cast<wchar_t*>(PreventScreenSaverText(ActiveLanguage()));
    HANDLE request = createRequest(&reason);
    if (request == INVALID_HANDLE_VALUE) {
        return;
    }
    if (!setRequest(request, PowerRequestDisplayRequired)) {
        CloseHandle(request);
        return;
    }
    app->screenSaverInhibition = request;
}

/// Returns the renderer owned by the primary animation surface.
static Renderer* PrimaryRenderer() {
    RenderSurface* surface = PrimarySurface();
    if (surface) {
        return surface->renderer.get();
    }
    return nullptr;
}

/// Publishes UI settings atomically to every render thread.
static void SyncRuntimeSettings(Application& app) {
    for (const std::unique_ptr<RenderSurface>& surface : app.surfaces) {
        const std::lock_guard lock(surface->settingsMutex);
        surface->runtimeSettings = app.settings.AnimationForMonitor(surface->monitorDevice);
    }
}

/// Takes one coherent snapshot without holding a lock during simulation, rendering or presentation.
static MonitorAnimation SurfaceAnimationSettings(RenderSurface& surface) {
    const std::lock_guard lock(surface.settingsMutex);
    return surface.runtimeSettings;
}

/// Removes leading and trailing Unicode whitespace.
static std::wstring Trim(std::wstring value) {
    while (!value.empty() && iswspace(value.front())) {
        value.erase(value.begin());
    }
    while (!value.empty() && iswspace(value.back())) {
        value.pop_back();
    }
    return value;
}

/// Returns the fully qualified path of the running module.
static std::wstring ExecutablePath() {
    std::wstring path(32768, L'\0');
    const DWORD length = GetModuleFileNameW(nullptr, path.data(), static_cast<DWORD>(path.size()));
    path.resize(length);
    return path;
}

/// Chooses the first existing shell folder from a preferred and fallback pair.
static std::wstring ExistingKnownFolder(int primaryFolder, int fallbackFolder) {
    wchar_t path[MAX_PATH]{};
    if (SUCCEEDED(SHGetFolderPathW(nullptr, primaryFolder, nullptr, SHGFP_TYPE_CURRENT, path))) {
        const DWORD attributes = GetFileAttributesW(path);
        if (attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0) {
            return path;
        }
    }
    path[0] = L'\0';
    if (SUCCEEDED(SHGetFolderPathW(nullptr, fallbackFolder, nullptr, SHGFP_TYPE_CURRENT, path))) {
        const DWORD attributes = GetFileAttributesW(path);
        if (attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0) {
            return path;
        }
    }
    return std::wstring{};
}

/// Creates a collision-resistant local file name from the current wall-clock time.
static std::wstring TimestampedFileName(const wchar_t* extension) {
    SYSTEMTIME localTime{};
    GetLocalTime(&localTime);
    wchar_t name[96]{};
    swprintf_s(name, L"FlyingSolids-%04u-%02u-%02u-%02u-%02u-%02u.%s", localTime.wYear, localTime.wMonth,
        localTime.wDay, localTime.wHour, localTime.wMinute, localTime.wSecond, extension);
    return name;
}

/// Reports whether the running image uses the screen-saver file extension.
static bool IsScrExecutable() {
    const std::wstring path = ExecutablePath();
    const std::size_t dot = path.find_last_of(L'.');
    return dot != std::wstring::npos && _wcsicmp(path.c_str() + dot, SCREEN_SAVER_EXTENSION) == 0;
}

/// Returns the canonical native-system-directory path of the installed saver.
static std::wstring ScreenSaverDestinationPath() {
    wchar_t systemDirectory[MAX_PATH]{};
    const UINT length = GetSystemDirectoryW(systemDirectory, MAX_PATH);
    if (length > 0 && length < MAX_PATH) {
        return std::wstring(systemDirectory) + SCREEN_SAVER_PATH_SUFFIX;
    }
    return std::wstring{};
}

/// Enumerates historical installation paths that may require cleanup.
static std::vector<std::wstring> LegacyScreenSaverPaths() {
    std::vector<std::wstring> paths;
    wchar_t windowsDirectory[MAX_PATH]{};
    const UINT windowsLength = GetWindowsDirectoryW(windowsDirectory, MAX_PATH);
    if (windowsLength > 0 && windowsLength < MAX_PATH) {
        paths.emplace_back(std::wstring(windowsDirectory) + SCREEN_SAVER_PATH_SUFFIX);
    }
    wchar_t wow64Directory[MAX_PATH]{};
    const HMODULE kernel = GetModuleHandleW(L"kernel32.dll");
    const GetSystemWow64DirectoryWFunction getSystemWow64Directory =
        reinterpret_cast<GetSystemWow64DirectoryWFunction>(kernel
            ? GetProcAddress(kernel, "GetSystemWow64DirectoryW")
            : nullptr);
    const UINT wow64Length = getSystemWow64Directory ? getSystemWow64Directory(wow64Directory, MAX_PATH) : 0;
    if (wow64Length > 0 && wow64Length < MAX_PATH) {
        paths.emplace_back(std::wstring(wow64Directory) + SCREEN_SAVER_PATH_SUFFIX);
    }
    return paths;
}

/// Compares two nonempty Windows paths case-insensitively.
static bool SamePath(const std::wstring& first, const std::wstring& second) {
    return !first.empty() && !second.empty() && _wcsicmp(first.c_str(), second.c_str()) == 0;
}

/// Removes one known file and treats an already absent file as success.
static bool RemoveFileIfPresent(const std::wstring& path) {
    const DWORD attributes = GetFileAttributesW(path.c_str());
    if (attributes == INVALID_FILE_ATTRIBUTES) {
        return GetLastError() == ERROR_FILE_NOT_FOUND || GetLastError() == ERROR_PATH_NOT_FOUND;
    }
    if ((attributes & FILE_ATTRIBUTE_DIRECTORY) != 0) {
        return false;
    }
    if ((attributes & FILE_ATTRIBUTE_READONLY) != 0
            && !SetFileAttributesW(path.c_str(), attributes & ~FILE_ATTRIBUTE_READONLY)) {
        return false;
    }
    return DeleteFileW(path.c_str()) != FALSE;
}

/// Removes only known legacy copies outside the canonical destination.
static bool RemoveLegacyScreenSaverCopies() {
    const std::wstring destination = ScreenSaverDestinationPath();
    for (const std::wstring& path : LegacyScreenSaverPaths()) {
        if (!SamePath(path, destination) && !RemoveFileIfPresent(path)) {
            return false;
        }
    }
    return true;
}

/// Recognizes canonical and historical FlyingSolids installation paths.
static bool IsFlyingSolidsScreenSaverPath(const std::wstring& path) {
    if (SamePath(path, ScreenSaverDestinationPath())) {
        return true;
    }
    for (const std::wstring& legacy : LegacyScreenSaverPaths()) {
        if (SamePath(path, legacy)) {
            return true;
        }
    }
    return false;
}

/// Tests whether the canonical screen-saver file currently exists.
static bool IsScreenSaverInstalled() {
    const std::wstring destination = ScreenSaverDestinationPath();
    if (destination.empty()) {
        return false;
    }
    const Wow64Redirection wow64Redirection;
    const DWORD attributes = GetFileAttributesW(destination.c_str());
    return attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY) == 0;
}

/// Classifies a Restart Manager process by inspecting its top-level windows.
static BOOL CALLBACK InspectLockedScreenSaverWindow(HWND window, LPARAM parameter) {
    LockedScreenSaverWindows& state = *reinterpret_cast<LockedScreenSaverWindows*>(parameter);
    DWORD processId = 0;
    GetWindowThreadProcessId(window, &processId);
    if (std::find(state.processIds.begin(), state.processIds.end(), processId) == state.processIds.end()) {
        return TRUE;
    }
    wchar_t className[96]{};
    GetClassNameW(window, className, static_cast<int>(std::size(className)));
    if (_wcsicmp(className, SETTINGS_CLASS) == 0) {
        state.settings = true;
    } else if (_wcsicmp(className, RENDER_CLASS) == 0) {
        if ((GetWindowLongPtrW(window, GWL_STYLE) & WS_CHILD) != 0) {
            state.systemPreview = true;
        } else {
            state.runningSaver = true;
        }
    }
    return TRUE;
}

/// Uses Restart Manager to identify how the installed saver is currently used.
static ScreenSaverFileUse CurrentScreenSaverFileUse() {
    const std::wstring path = ScreenSaverDestinationPath();
    if (path.empty()) {
        return ScreenSaverFileUse::None;
    }
    const HMODULE restartManager = LoadLibraryW(L"rstrtmgr.dll");
    if (!restartManager) {
        return ScreenSaverFileUse::None;
    }
    const StartSession startSession = reinterpret_cast<StartSession>(GetProcAddress(restartManager, "RmStartSession"));
    const EndSession endSession = reinterpret_cast<EndSession>(GetProcAddress(restartManager, "RmEndSession"));
    const RegisterResources registerResources =
        reinterpret_cast<RegisterResources>(GetProcAddress(restartManager, "RmRegisterResources"));
    const GetList getList = reinterpret_cast<GetList>(GetProcAddress(restartManager, "RmGetList"));
    if (!startSession || !endSession || !registerResources || !getList) {
        FreeLibrary(restartManager);
        return ScreenSaverFileUse::None;
    }
    DWORD session = 0;
    WCHAR sessionKey[CCH_RM_SESSION_KEY + 1]{};
    LockedScreenSaverWindows windows;
    if (startSession(&session, 0, sessionKey) == ERROR_SUCCESS) {
        LPCWSTR files[]{ path.c_str() };
        if (registerResources(session, 1, files, 0, nullptr, 0, nullptr) == ERROR_SUCCESS) {
            UINT needed = 0;
            UINT count = 0;
            DWORD rebootReasons = 0;
            DWORD status = getList(session, &needed, &count, nullptr, &rebootReasons);
            if (status == ERROR_MORE_DATA && needed > 0) {
                std::vector<RM_PROCESS_INFO> processes(needed);
                count = needed;
                status = getList(session, &needed, &count, processes.data(), &rebootReasons);
                if (status == ERROR_SUCCESS) {
                    for (UINT index = 0; index < count; index++) {
                        windows.processIds.push_back(processes[index].Process.dwProcessId);
                    }
                }
            }
        }
        endSession(session);
    }
    FreeLibrary(restartManager);
    if (windows.processIds.empty()) {
        return ScreenSaverFileUse::None;
    }
    EnumChildWindows(GetDesktopWindow(), InspectLockedScreenSaverWindow, reinterpret_cast<LPARAM>(&windows));
    if (windows.settings) {
        return ScreenSaverFileUse::Settings;
    }
    if (windows.systemPreview) {
        return ScreenSaverFileUse::SystemPreview;
    }
    if (windows.runningSaver) {
        return ScreenSaverFileUse::RunningSaver;
    }
    return ScreenSaverFileUse::Other;
}

/// Produces a precise localized recovery instruction after uninstall failure.
static std::wstring UninstallationFailureStatus(AppLanguage language) {
    switch (CurrentScreenSaverFileUse()) {
        case ScreenSaverFileUse::Settings:
            return UninstallationBlockedBySettingsText(language);
        case ScreenSaverFileUse::SystemPreview:
            return UninstallationBlockedBySystemPreviewText(language);
        case ScreenSaverFileUse::RunningSaver:
            return UninstallationBlockedByRunningSaverText(language);
        default:
            return UninstallationFailedText(language);
    }
}

/// Extracts the preview-parent handle from the conventional /p argument.
static HWND ParseParentHandle(const std::wstring& commandLine) {
    const wchar_t* text = commandLine.c_str();
    while (*text && !iswdigit(*text)) {
        ++text;
    }
    return reinterpret_cast<HWND>(static_cast<ULONG_PTR>(_wcstoui64(text, nullptr, 0)));
}

/// Reads the rational monitor refresh rate through the existing modern API and Vista display-mode path.
static double CurrentRefreshRate(HWND window) {
    const HMONITOR monitor = MonitorFromWindow(window, MONITOR_DEFAULTTOPRIMARY);
    MONITORINFOEXW info{};
    info.cbSize = sizeof(info);
    if (!GetMonitorInfoW(monitor, &info)) {
        return 60.0;
    }
    DisplayMonitor display;
    display.device = info.szDevice;
    const std::vector<DisplayMonitor> displays{ display };
    const std::vector<MonitorDetails> details = ReadMonitorDetails(displays);
    if (!details.empty() && details.front().refreshRate.Denominator != 0) {
        const DISPLAYCONFIG_RATIONAL rate = details.front().refreshRate;
        const double frequency = static_cast<double>(rate.Numerator) / rate.Denominator;
        if (frequency >= 24.0 && frequency <= 360.0) {
            return frequency;
        }
    }
    return 60.0;
}

/// Acquires the standalone-instance mutex without waiting for another running instance.
static HANDLE AcquireApplicationInstance(bool& primary, const wchar_t* name = INSTANCE_MUTEX) {
    primary = false;
    HANDLE mutex = CreateMutexW(nullptr, FALSE, name);
    if (!mutex) {
        return nullptr;
    }
    const DWORD result = WaitForSingleObject(mutex, 0);
    primary = result == WAIT_OBJECT_0 || result == WAIT_ABANDONED;
    if (!primary && result != WAIT_TIMEOUT) {
        CloseHandle(mutex);
        return nullptr;
    }
    return mutex;
}

/// Releases and closes the mutex owned by the primary standalone instance.
static void ReleaseApplicationInstance(HANDLE mutex) {
    ReleaseMutex(mutex);
    CloseHandle(mutex);
}

/// Finds the standalone settings window without matching screen-saver settings windows.
static BOOL CALLBACK FindApplicationWindow(HWND window, LPARAM parameter) {
    if (GetPropW(window, INSTANCE_WINDOW_PROPERTY)) {
        HWND& found = *reinterpret_cast<HWND*>(parameter);
        found = window;
        return FALSE;
    }
    return TRUE;
}

/// Restores and raises the existing standalone window, then refreshes it and its controls.
static void ActivateApplicationWindow(HWND window) {
    ShowWindow(window, IsIconic(window) ? SW_RESTORE : SW_SHOW);
    SetWindowPos(window, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
    SetForegroundWindow(window);
    RedrawWindow(window, nullptr, nullptr, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ALLCHILDREN);
}

/// Hands foreground permission to the primary instance and posts an activation request after startup.
static bool ActivateExistingApplication() {
    for (int attempt = 0; attempt < 200; attempt++) {
        HWND window = nullptr;
        EnumWindows(FindApplicationWindow, reinterpret_cast<LPARAM>(&window));
        if (window) {
            DWORD process = 0;
            GetWindowThreadProcessId(window, &process);
            AllowSetForegroundWindow(process);
            return PostMessageW(window, ACTIVATE_APPLICATION_WINDOW, 0, 0) != FALSE;
        }
        Sleep(25);
    }
    return false;
}

/// Returns the settings panel, or the settings window when no separate panel is used.
static HWND SettingsContentWindow(HWND window) {
    SettingsWindowData* data = reinterpret_cast<SettingsWindowData*>(GetWindowLongPtrW(window, GWLP_USERDATA));
    return data && data->contentWindow ? data->contentWindow : window;
}

/// Replaces the single status-bar part without changing application state.
static void SetStatus(const wchar_t* text) {
    if (app && app->status) {
        SendMessageW(app->status, SB_SETTEXTW, 0, reinterpret_cast<LPARAM>(text));
    }
}

/// Reads recording state without waiting for the primary render thread.
static bool PrimaryIsRecording() {
    RenderSurface* surface = PrimarySurface();
    if (!surface || !surface->renderer) {
        return false;
    }
    return surface->renderer->IsRecording();
}

/// Chooses the persistent status text implied by current runtime state.
static const wchar_t* CurrentStatusText() {
    const LocalizedText& strings = Text(ActiveLanguage());
    if (!HasReadyPrimarySurface()) {
        return ReadyStatusText(ActiveLanguage());
    }
    if (PrimaryIsRecording()) {
        return strings.recording;
    }
    if (app && app->paused.load(std::memory_order_relaxed)) {
        return PausedStatusText(ActiveLanguage());
    }
    return strings.ready;
}

/// Restores persistent status after a transient notification expires.
static void RestoreCurrentStatus() {
    UpdateScreenSaverInhibition();
    SetStatus(CurrentStatusText());
}

/// Shows a notification for ten seconds before restoring persistent status.
static void ShowTransientStatus(const wchar_t* text) {
    SetStatus(text);
    if (!app || !app->controlWindow) {
        return;
    }
    KillTimer(app->controlWindow, ID_STATUS_RESET_TIMER);
    SetTimer(app->controlWindow, ID_STATUS_RESET_TIMER, 10000, nullptr);
}

/// Applies only changed values while keeping every affected control unpainted until the batch is complete.
static void ApplySettingsControlStates(std::vector<SettingsControlState> states) {
    std::vector<std::unique_ptr<WindowRedrawScope>> redraw;
    redraw.reserve(states.size());
    for (SettingsControlState& state : states) {
        if (!state.window) {
            continue;
        }
        if (state.enabled && static_cast<bool>(IsWindowEnabled(state.window)) == *state.enabled) {
            state.enabled.reset();
        }
        if (state.check && static_cast<UINT>(SendMessageW(state.window, BM_GETCHECK, 0, 0)) == *state.check) {
            state.check.reset();
        }
        if (state.position && static_cast<LONG>(SendMessageW(state.window, TBM_GETPOS, 0, 0)) == *state.position) {
            state.position.reset();
        }
        if (state.mixed && MixedControls::IsMixed(state.window) == *state.mixed) {
            state.mixed.reset();
        }
        if (state.caption) {
            const int length = GetWindowTextLengthW(state.window);
            std::wstring current(static_cast<std::size_t>(length) + 1, L'\0');
            if (length > 0) {
                GetWindowTextW(state.window, current.data(), length + 1);
            }
            current.resize(static_cast<std::size_t>(length));
            if (current == *state.caption) {
                state.caption.reset();
            }
        }
        if (!state.enabled && !state.check && !state.position && !state.caption && !state.mixed) {
            state.window = nullptr;
            continue;
        }
        redraw.push_back(std::make_unique<WindowRedrawScope>(state.window));
    }
    for (const SettingsControlState& state : states) {
        if (!state.window) {
            continue;
        }
        if (state.mixed) {
            MixedControls::SetMixed(state.window, *state.mixed);
        }
        if (state.enabled) {
            EnableWindow(state.window, *state.enabled);
        }
        if (state.check) {
            SendMessageW(state.window, BM_SETCHECK, *state.check, 0);
        }
        if (state.position) {
            SendMessageW(state.window, TBM_SETPOS, TRUE, *state.position);
        }
        if (state.caption) {
            SetWindowTextW(state.window, state.caption->c_str());
        }
    }
}

/// Prepares action-button availability without changing or painting any native controls.
static void AppendSettingsActionButtonStates(HWND window, const SettingsWindowData& data,
        const MonitorSelection& selection, std::vector<SettingsControlState>& states) {
    const bool mixed = selection.IsMixed(ANIMATION_ENABLED_PROPERTY);
    const std::uint32_t enabled = selection.values.Value(ANIMATION_ENABLED_PROPERTY);
    states.push_back(SettingsControlState{
        GetDlgItem(window, ID_ALL_ANIMATIONS),
        selection.available && (enabled != ALL_ANIMATION_MASK || mixed),
        std::nullopt,
        std::nullopt,
        std::nullopt,
        selection.available && mixed
    });
    states.push_back(SettingsControlState{
        GetDlgItem(window, ID_NO_ANIMATIONS),
        selection.available && (enabled != 0 || mixed),
        std::nullopt,
        std::nullopt,
        std::nullopt,
        selection.available && mixed
    });
    if (data.appMode) {
        const bool animationReady = HasReadyPrimarySurface();
        states.push_back(SettingsControlState{ GetDlgItem(window, ID_RECORD_TOGGLE), animationReady });
        states.push_back(SettingsControlState{ GetDlgItem(window, ID_SNAPSHOT), animationReady });
        states.push_back(SettingsControlState{ GetDlgItem(window, ID_PAUSE), HasReadyAnimationSurface() });
    }
}

/// Enables only settings actions that can change the current state or operate on a rendered animation.
static void UpdateSettingsActionButtons(HWND window) {
    UpdateScreenSaverInhibition();
    window = GetAncestor(window, GA_ROOT);
    const SettingsWindowData* data =
        reinterpret_cast<const SettingsWindowData*>(GetWindowLongPtrW(window, GWLP_USERDATA));
    if (!data || !data->settings) {
        return;
    }
    const MonitorSelection selection = data->settings->SelectionForMonitors(data->selectedAnimationDevices);
    std::vector<SettingsControlState> states;
    AppendSettingsActionButtonStates(SettingsContentWindow(window), *data, selection, states);
    ApplySettingsControlStates(std::move(states));
}

/// Synchronizes the record button caption and enabled settings actions with the current animation state.
static void UpdateRecordingButton() {
    if (!app || !app->controlWindow) {
        return;
    }
    const LocalizedText& strings = Text(ActiveLanguage());
    SetDlgItemTextW(SettingsContentWindow(app->controlWindow), ID_RECORD_TOGGLE, PrimaryIsRecording()
        ? strings.stopRecording
        : strings.startRecording);
    UpdateSettingsActionButtons(app->controlWindow);
}

/// Stops active capture under the renderer lock and releases the lock when this helper returns.
static bool PrepareSurfaceRecordingStop(RenderSurface& surface) {
    const std::lock_guard lock(surface.rendererMutex);
    if (!surface.renderer->IsRecording()) {
        return false;
    }
    surface.renderer->PrepareRecordingStop();
    return true;
}

/// Stops capture under the renderer lock, then finalizes the MP4 without blocking the surface's animation thread.
static bool StopSurfaceRecording(RenderSurface& surface) {
    if (!PrepareSurfaceRecordingStop(surface)) {
        return false;
    }
    surface.renderer->FinishRecordingStop();
    return true;
}

/// Starts recording one animation surface while holding its renderer lock.
static bool StartSurfaceRecording(RenderSurface& surface, const wchar_t* file, unsigned recordingRate) {
    const std::lock_guard lock(surface.rendererMutex);
    return surface.renderer->StartRecording(file, recordingRate, app->settings.recording);
}

/// Tests recording support while holding the renderer lock, without retaining the lock during a dialog.
static bool CheckSurfaceRecordingSupport(RenderSurface& surface, unsigned recordingRate) {
    const std::lock_guard lock(surface.rendererMutex);
    return surface.renderer->CheckRecordingSupport(recordingRate, app->settings.recording);
}

/// Tests PNG capture support while holding the renderer lock, without retaining the lock during a dialog.
static bool CheckSurfaceSnapshotSupport(RenderSurface& surface) {
    const std::lock_guard lock(surface.rendererMutex);
    return surface.renderer->CheckSnapshotSupport();
}

/// Saves one animation surface while holding its renderer lock.
static bool SaveSurfaceSnapshot(RenderSurface& surface, const wchar_t* file) {
    const std::lock_guard lock(surface.rendererMutex);
    return surface.renderer->SaveSnapshot(file);
}

/// Finalizes recording on the primary animation surface.
static void StopRecording() {
    RenderSurface* surface = PrimarySurface();
    if (!surface || !surface->renderer || !StopSurfaceRecording(*surface)) {
        return;
    }
    ShowTransientStatus(Text(ActiveLanguage()).recordingSaved);
    UpdateRecordingButton();
}

/// Prompts for an MP4 path and starts recording at the monitor refresh rate.
static void StartRecording(HWND owner) {
    RenderSurface* surface = PrimarySurface();
    if (!app || app->mode != RunMode::Application || !surface || !surface->renderer) {
        return;
    }
    if (PrimaryIsRecording()) {
        StopRecording();
    }
    const unsigned recordingRate = surface->refreshRate;
    if (!CheckSurfaceRecordingSupport(*surface, recordingRate)) {
        MessageBoxW(owner, Text(ActiveLanguage()).recordingFailed, PRODUCT_NAME, MB_OK | MB_ICONERROR);
        return;
    }
    wchar_t file[MAX_PATH]{};
    wcscpy_s(file, TimestampedFileName(MP4_EXTENSION).c_str());
    const std::wstring initialDirectory = ExistingKnownFolder(CSIDL_MYVIDEO, CSIDL_PERSONAL);
    OPENFILENAMEW dialog{};
    dialog.lStructSize = sizeof(dialog);
    dialog.hwndOwner = owner;
    dialog.lpstrFilter = L"MPEG-4 (*.mp4)\0*.mp4\0\0";
    dialog.lpstrFile = file;
    dialog.nMaxFile = MAX_PATH;
    dialog.lpstrDefExt = MP4_EXTENSION;
    dialog.lpstrInitialDir = initialDirectory.empty() ? nullptr : initialDirectory.c_str();
    dialog.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST;
    if (!GetSaveFileNameW(&dialog)) {
        return;
    }
    const bool started = StartSurfaceRecording(*surface, file, recordingRate);
    if (started) {
        SetStatus(Text(ActiveLanguage()).recording);
    } else {
        ShowTransientStatus(Text(ActiveLanguage()).recordingFailed);
    }
    UpdateRecordingButton();
}

/// Prompts for a PNG path and captures the current primary surface.
static void SaveSnapshot(HWND owner) {
    RenderSurface* surface = PrimarySurface();
    if (!app || app->mode != RunMode::Application || !surface || !surface->renderer) {
        return;
    }
    if (!CheckSurfaceSnapshotSupport(*surface)) {
        MessageBoxW(owner, SnapshotFailedText(ActiveLanguage()), PRODUCT_NAME, MB_OK | MB_ICONERROR);
        return;
    }
    wchar_t file[MAX_PATH]{};
    wcscpy_s(file, TimestampedFileName(PNG_EXTENSION).c_str());
    const std::wstring initialDirectory = ExistingKnownFolder(CSIDL_MYPICTURES, CSIDL_PERSONAL);
    OPENFILENAMEW dialog{};
    dialog.lStructSize = sizeof(dialog);
    dialog.hwndOwner = owner;
    dialog.lpstrFilter = L"PNG (*.png)\0*.png\0\0";
    dialog.lpstrFile = file;
    dialog.nMaxFile = MAX_PATH;
    dialog.lpstrDefExt = PNG_EXTENSION;
    dialog.lpstrInitialDir = initialDirectory.empty() ? nullptr : initialDirectory.c_str();
    dialog.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST;
    if (!GetSaveFileNameW(&dialog)) {
        return;
    }
    const bool saved = SaveSurfaceSnapshot(*surface, file);
    if (saved) {
        ShowTransientStatus(SnapshotSavedText(ActiveLanguage()));
    } else {
        ShowTransientStatus(SnapshotFailedText(ActiveLanguage()));
    }
}

/// Confirms every user-requested application close before finalizing an active recording.
static void CloseApplication() {
    if (!app || app->closing.load(std::memory_order_relaxed) || app->confirmingClose) {
        return;
    }
    RenderSurface* recording = RecordingSurface();
    if (recording) {
        app->confirmingClose = true;
        HWND owner = GetActiveWindow();
        if (!owner || IsIconic(owner)) {
            owner = recording->window ? recording->window : app->controlWindow;
        }
        const int result = MessageBoxW(owner, RecordingCloseWarningText(ActiveLanguage()), PRODUCT_NAME,
            MB_OKCANCEL | MB_ICONWARNING | MB_DEFBUTTON2);
        app->confirmingClose = false;
        if (result != IDOK) {
            return;
        }
    }
    if (app->closing.exchange(true, std::memory_order_relaxed)) {
        return;
    }
    ReleaseScreenSaverInhibition(*app);
    StopRecording();
    PostQuitMessage(0);
}

/// Normalizes a prospective mnemonic key for case-insensitive comparison.
static wchar_t MnemonicKey(wchar_t character) {
    CharUpperBuffW(&character, 1);
    return character;
}

/// Assigns the preferred or first available single-character mnemonic to a caption.
static std::wstring UniqueMnemonic(const wchar_t* text, std::vector<wchar_t>& usedMnemonics) {
    std::wstring plainText;
    std::size_t preferredPosition = std::wstring::npos;
    for (std::size_t index = 0; text[index] != L'\0'; index++) {
        if (text[index] == L'&' && text[index + 1] != L'\0') {
            if (text[index + 1] == L'&') {
                plainText += L'&';
                ++index;
            } else if (preferredPosition == std::wstring::npos) {
                preferredPosition = plainText.size();
            }
            continue;
        }
        plainText += text[index];
    }
    std::size_t mnemonicPosition = std::wstring::npos;
    if (preferredPosition < plainText.size()) {
        const wchar_t key = MnemonicKey(plainText[preferredPosition]);
        if (iswalnum(plainText[preferredPosition])
                && std::find(usedMnemonics.begin(), usedMnemonics.end(), key) == usedMnemonics.end()) {
            mnemonicPosition = preferredPosition;
        }
    }
    if (mnemonicPosition == std::wstring::npos) {
        for (std::size_t index = 0; index < plainText.size(); index++) {
            const wchar_t key = MnemonicKey(plainText[index]);
            if (iswalnum(plainText[index])
                    && std::find(usedMnemonics.begin(), usedMnemonics.end(), key) == usedMnemonics.end()) {
                mnemonicPosition = index;
                break;
            }
        }
    }
    std::wstring result;
    for (std::size_t index = 0; index < plainText.size(); index++) {
        if (index == mnemonicPosition) {
            result += L'&';
        }
        if (plainText[index] == L'&') {
            result += L'&';
        }
        result += plainText[index];
    }
    if (mnemonicPosition != std::wstring::npos) {
        usedMnemonics.push_back(MnemonicKey(plainText[mnemonicPosition]));
    }
    return result;
}

/// Assigns unique mnemonics to visible settings labels and tab-stop buttons.
static void AssignSettingsMnemonics(HWND parent) {
    parent = SettingsContentWindow(parent);
    std::vector<wchar_t> usedMnemonics;
    for (HWND control = GetWindow(parent, GW_CHILD); control; control = GetWindow(control, GW_HWNDNEXT)) {
        const LONG_PTR style = GetWindowLongPtrW(control, GWL_STYLE);
        if ((style & WS_VISIBLE) == 0) {
            continue;
        }
        wchar_t className[32]{};
        GetClassNameW(control, className, static_cast<int>(std::size(className)));
        const int length = GetWindowTextLengthW(control);
        std::wstring text(static_cast<std::size_t>(length) + 1, L'\0');
        if (length > 0) {
            GetWindowTextW(control, text.data(), length + 1);
        }
        text.resize(static_cast<std::size_t>(length));
        const bool button = _wcsicmp(className, L"BUTTON") == 0 && (style & WS_TABSTOP) != 0;
        const bool label = _wcsicmp(className, L"STATIC") == 0 && text.find(L':') != std::wstring::npos;
        if (!button && !label) {
            continue;
        }
        const std::wstring caption = UniqueMnemonic(text.c_str(), usedMnemonics);
        SetWindowTextW(control, caption.c_str());
    }
}

/// Avoids invalidation when a control already displays the requested text.
static void SetWindowTextIfChanged(HWND control, const std::wstring& text) {
    if (!control) {
        return;
    }
    const int length = GetWindowTextLengthW(control);
    std::wstring current(static_cast<std::size_t>(length) + 1, L'\0');
    if (length > 0) {
        GetWindowTextW(control, current.data(), length + 1);
    }
    current.resize(static_cast<std::size_t>(length));
    if (current != text) {
        SetWindowTextW(control, text.c_str());
    }
}

/// Reapplies a control's assigned mnemonic after a dynamic caption update.
static std::wstring PreserveControlMnemonic(HWND control, const wchar_t* newText) {
    std::wstring result = newText ? newText : L"";
    if (!control) {
        return result;
    }
    const int length = GetWindowTextLengthW(control);
    std::wstring current(static_cast<std::size_t>(length) + 1, L'\0');
    if (length > 0) {
        GetWindowTextW(control, current.data(), length + 1);
    }
    current.resize(static_cast<std::size_t>(length));
    const std::size_t marker = current.find(L'&');
    if (marker == std::wstring::npos || marker + 1 >= current.size()) {
        return result;
    }
    const wchar_t mnemonic = static_cast<wchar_t>(towlower(current[marker + 1]));
    const std::wstring::iterator position = std::find_if(result.begin(), result.end(), [=](wchar_t value) {
        return towlower(value) == mnemonic;
    });
    if (position != result.end()) {
        result.insert(position - result.begin(), 1, L'&');
    }
    return result;
}

/// Returns the caption format of one project-specific animation slider.
static const wchar_t* AnimationSliderFormat(AnimationProperty property, AppLanguage language) {
    switch (property) {
        case AnimationProperty::ObjectSpeed: return Text(language).objectSpeed;
        case AnimationProperty::CameraSpeed: return Text(language).cameraSpeed;
        case AnimationProperty::CopyCount: return CopyCountText(language);
        case AnimationProperty::ObjectSize: return ObjectSizeText(language);
        default: return L"";
    }
}

/// Formats one slider caption without changing or painting its native label.
static std::wstring AnimationSliderCaption(HWND label, const SettingsWindowData& data, const MonitorSelection& selection,
        const AnimationSliderControl& control) {
    std::wstring caption = AnimationSliderFormat(control.property, data.language);
    if (!selection.available || selection.IsMixed(control.property)) {
        const std::size_t number = caption.find(L"%d");
        if (number != std::wstring::npos) {
            caption.replace(number, 2, L"—");
        }
    }
    wchar_t text[96]{};
    swprintf_s(text, caption.c_str(), static_cast<int>(selection.values.Value(control.property)));
    return PreserveControlMnemonic(label, text);
}

/// Updates one slider caption with its current localized numeric value.
static void UpdateSliderLabel(HWND window, const SettingsWindowData& data, int sliderId) {
    window = SettingsContentWindow(window);
    for (const AnimationSliderControl& control : ANIMATION_SLIDERS) {
        if (control.id != sliderId) {
            continue;
        }
        const MonitorSelection selection = data.settings->SelectionForMonitors(data.selectedAnimationDevices);
        HWND label = GetDlgItem(window, control.labelId);
        SetWindowTextIfChanged(label, AnimationSliderCaption(label, data, selection, control));
        return;
    }
}

/// Refreshes every slider caption in the settings window.
static void UpdateSliderLabels(HWND window, const SettingsWindowData& data) {
    for (const AnimationSliderControl& control : ANIMATION_SLIDERS) {
        UpdateSliderLabel(window, data, control.id);
    }
}

/// Fits monitor columns once on first display, reserving space for every heading's sort arrow.
static void InitializeMonitorColumnWidths(HWND list, SettingsWindowData& data) {
    if (data.monitorColumnsInitialized || list == nullptr) {
        return;
    }
    HWND header = ListView_GetHeader(list);
    if (header == nullptr || Header_GetItemCount(header) != MONITOR_COLUMN_COUNT) {
        return;
    }
    HDC dc = GetDC(header);
    if (dc == nullptr) {
        return;
    }
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(header, WM_GETFONT, 0, 0));
    HGDIOBJ previousFont = font == nullptr ? nullptr : SelectObject(dc, font);
    for (int column = 0; column < MONITOR_COLUMN_COUNT; column++) {
        wchar_t caption[256]{};
        HDITEMW item{};
        item.mask = HDI_TEXT;
        item.pszText = caption;
        item.cchTextMax = static_cast<int>(std::size(caption));
        if (!Header_GetItem(header, column, &item)) {
            continue;
        }
        SIZE extent{};
        GetTextExtentPoint32W(dc, caption, static_cast<int>(wcslen(caption)), &extent);
        int headerWidth = static_cast<int>(extent.cx) + 2 * GetSystemMetrics(SM_CXEDGE) + 8
            + GetSystemMetrics(SM_CXVSCROLL);
        ListView_SetColumnWidth(list, column, LVSCW_AUTOSIZE);
        int contentWidth = ListView_GetColumnWidth(list, column);
        ListView_SetColumnWidth(list, column, std::max(headerWidth, contentWidth));
    }
    if (previousFont != nullptr && previousFont != HGDI_ERROR) {
        SelectObject(dc, previousFont);
    }
    ReleaseDC(header, dc);
    data.monitorColumnsInitialized = true;
}

/// Compares one numeric monitor value without converting it to displayed text.
template<typename Value>
static int CompareMonitorValues(Value left, Value right) {
    if (left < right) {
        return -1;
    }
    if (left > right) {
        return 1;
    }
    return 0;
}

/// Compares exact fractional refresh rates, placing unavailable values before known values in ascending order.
static int CompareMonitorRefreshRates(const DISPLAYCONFIG_RATIONAL& left, const DISPLAYCONFIG_RATIONAL& right) {
    const bool leftKnown = left.Numerator != 0 && left.Denominator != 0;
    const bool rightKnown = right.Numerator != 0 && right.Denominator != 0;
    const int availability = CompareMonitorValues(leftKnown, rightKnown);
    if (availability != 0 || !leftKnown) {
        return availability;
    }
    const std::uint64_t leftValue = static_cast<std::uint64_t>(left.Numerator) * right.Denominator;
    const std::uint64_t rightValue = static_cast<std::uint64_t>(right.Numerator) * left.Denominator;
    return CompareMonitorValues(leftValue, rightValue);
}

/// Compares stable monitor indices by the chosen column, retaining source order for equal values as in CalClock.
static int CALLBACK CompareMonitorListEntries(LPARAM left, LPARAM right, LPARAM sortData) {
    const SettingsWindowData* data = reinterpret_cast<const SettingsWindowData*>(sortData);
    const std::size_t leftIndex = static_cast<std::size_t>(left);
    const std::size_t rightIndex = static_cast<std::size_t>(right);
    if (!data
            || leftIndex >= data->monitorListEntries.size()
            || rightIndex >= data->monitorListEntries.size()
            || data->monitorSortColumn < 0
            || data->monitorSortColumn >= MONITOR_COLUMN_COUNT) {
        return 0;
    }
    const MonitorListEntry& leftEntry = data->monitorListEntries[leftIndex];
    const MonitorListEntry& rightEntry = data->monitorListEntries[rightIndex];
    int comparison = 0;
    if (data->monitorSortColumn == 3) {
        comparison = CompareMonitorRefreshRates(leftEntry.details.refreshRate, rightEntry.details.refreshRate);
    } else if (data->monitorSortColumn == 4) {
        const UINT leftDepth =
            leftEntry.details.bitsPerColor != 0 ? leftEntry.details.bitsPerColor : leftEntry.details.bitsPerPixel;
        const UINT rightDepth =
            rightEntry.details.bitsPerColor != 0 ? rightEntry.details.bitsPerColor : rightEntry.details.bitsPerPixel;
        comparison = CompareMonitorValues(leftDepth, rightDepth);
        if (comparison == 0) {
            comparison = _wcsicmp(leftEntry.text[4].c_str(), rightEntry.text[4].c_str());
        }
    } else {
        comparison =
            _wcsicmp(leftEntry.text[data->monitorSortColumn].c_str(), rightEntry.text[data->monitorSortColumn].c_str());
    }
    if (comparison != 0) {
        return data->monitorSortAscending ? comparison : -comparison;
    }
    if (leftIndex < rightIndex) {
        return -1;
    }
    return leftIndex > rightIndex ? 1 : 0;
}

/// Applies the chosen monitor order and heading arrow without changing source monitor identities.
static void ApplyMonitorListSort(HWND list, const SettingsWindowData& data) {
    if (list == nullptr || data.monitorSortColumn < 0 || data.monitorSortColumn >= MONITOR_COLUMN_COUNT) {
        return;
    }
    ListView_SortItems(list, CompareMonitorListEntries, reinterpret_cast<LPARAM>(&data));
    HWND header = ListView_GetHeader(list);
    if (header == nullptr) {
        return;
    }
    for (int column = 0; column < MONITOR_COLUMN_COUNT; column++) {
        HDITEMW item{};
        item.mask = HDI_FORMAT;
        if (!Header_GetItem(header, column, &item)) {
            continue;
        }
        item.fmt &= ~(HDF_SORTUP | HDF_SORTDOWN);
        if (column == data.monitorSortColumn) {
            item.fmt |= data.monitorSortAscending ? HDF_SORTUP : HDF_SORTDOWN;
        }
        Header_SetItem(header, column, &item);
    }
}

/// Selects or reverses monitor sorting after a heading click without changing column widths.
static void SortMonitorListByColumn(HWND list, SettingsWindowData& data, int column) {
    if (list == nullptr || column < 0 || column >= MONITOR_COLUMN_COUNT) {
        return;
    }
    if (data.monitorSortColumn == column) {
        data.monitorSortAscending = !data.monitorSortAscending;
    } else {
        data.monitorSortColumn = column;
        data.monitorSortAscending = true;
    }
    const bool updating = data.updating;
    data.updating = true;
    WindowRedrawScope redraw(list);
    ApplyMonitorListSort(list, data);
    data.updating = updating;
}

/// Reads checked source monitor indices from stable item data, independent of the displayed row order.
static std::vector<std::size_t> CheckedMonitorIndices(HWND list, const SettingsWindowData& data) {
    std::vector<std::size_t> selected;
    const int rowCount = ListView_GetItemCount(list);
    for (int row = 0; row < rowCount; row++) {
        if (!ListView_GetCheckState(list, row)) {
            continue;
        }
        LVITEMW item{};
        item.mask = LVIF_PARAM;
        item.iItem = row;
        if (!ListView_GetItem(list, &item)) {
            continue;
        }
        const std::size_t index = static_cast<std::size_t>(item.lParam);
        if (index < data.monitors.size()) {
            selected.push_back(index);
        }
    }
    std::sort(selected.begin(), selected.end());
    return selected;
}

/// Identifies the recording monitor through stable item data, including bulk ListView changes.
static bool IsRecordingMonitorRow(HWND list, const SettingsWindowData& data, int row) {
    RenderSurface* recording = RecordingSurface();
    if (!data.appMode || !recording) {
        return false;
    }
    if (row == -1) {
        return true;
    }
    LVITEMW item{};
    item.mask = LVIF_PARAM;
    item.iItem = row;
    if (row < 0 || !ListView_GetItem(list, &item)) {
        return false;
    }
    const std::size_t index = static_cast<std::size_t>(item.lParam);
    return index < data.monitors.size()
        && _wcsicmp(data.monitors[index].device.c_str(), recording->monitorDevice.c_str()) == 0;
}

/// Rejects only attempts to uncheck the recording monitor, preserving all other ListView interaction.
static bool ShouldPreventMonitorUncheck(const NMLISTVIEW& change, const SettingsWindowData& data) {
    return !data.updating
        && data.appMode
        && (change.uChanged & LVIF_STATE) != 0
        && ((change.uOldState ^ change.uNewState) & LVIS_STATEIMAGEMASK) != 0
        && (change.uNewState & LVIS_STATEIMAGEMASK) == INDEXTOSTATEIMAGEMASK(1)
        && IsRecordingMonitorRow(change.hdr.hwndFrom, data, change.iItem);
}

/// Restores the protected checkbox if a programmatic ListView update bypassed its change notification.
static void RestoreRecordingMonitorCheckState(HWND list, SettingsWindowData& data) {
    const bool updating = data.updating;
    data.updating = true;
    const int count = ListView_GetItemCount(list);
    for (int row = 0; row < count; row++) {
        if (IsRecordingMonitorRow(list, data, row) && !ListView_GetCheckState(list, row)) {
            ListView_SetCheckState(list, row, TRUE);
        }
    }
    data.updating = updating;
}

/// Selects all monitor rows with Ctrl+A, as in CalClock's log, without changing checkbox states.
static LRESULT CALLBACK MonitorListSubclassProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam, UINT_PTR subclassId,
        DWORD_PTR referenceData) {
    UNREFERENCED_PARAMETER(referenceData);
    bool selectAll = msg == WM_KEYDOWN && wParam == L'A' && GetKeyState(VK_CONTROL) < 0 && GetKeyState(VK_MENU) >= 0;
    if (selectAll) {
        ListView_SetItemState(window, -1, LVIS_SELECTED, LVIS_SELECTED);
        return 0;
    }
    if (msg == WM_NCDESTROY) {
        RemoveWindowSubclass(window, MonitorListSubclassProc, subclassId);
    }
    return DefSubclassProc(window, msg, wParam, lParam);
}

/// Returns selected monitor identities through stable item data, never sorted row positions.
static std::vector<std::size_t> SelectedAnimationMonitorIndices(HWND list, const SettingsWindowData& data) {
    std::vector<std::size_t> selected;
    for (int row = ListView_GetNextItem(list, -1, LVNI_SELECTED);
            row >= 0;
            row = ListView_GetNextItem(list, row, LVNI_SELECTED)) {
        LVITEMW item{};
        item.mask = LVIF_PARAM;
        item.iItem = row;
        if (ListView_GetItem(list, &item)) {
            const std::size_t index = static_cast<std::size_t>(item.lParam);
            if (index < data.monitors.size()) {
                selected.push_back(index);
            }
        }
    }
    return selected;
}

/// Reads the current row selection without repainting controls or persisting transient intermediate selections.
static std::vector<std::size_t> UpdateSelectedAnimationDevices(HWND window, SettingsWindowData& data) {
    window = SettingsContentWindow(window);
    const std::vector<std::size_t> selected = SelectedAnimationMonitorIndices(GetDlgItem(window, ID_MONITOR_LIST), data);
    data.selectedAnimationDevices.clear();
    for (const std::size_t index : selected) {
        data.selectedAnimationDevices.push_back(data.monitors[index].device);
    }
    return selected;
}

/// Prepares only the object switches belonging to this project's animation.
static void AppendAnimationObjectControlStates(HWND window, const MonitorSelection& selection,
        std::vector<SettingsControlState>& states) {
    for (unsigned index = 0; index < SOLID_COUNT; index++) {
        HWND checkbox = GetDlgItem(window, ID_SOLID_FIRST + index);
        const UINT state = selection.available && (selection.mixedSolids & 1U << index) != 0
            ? BST_INDETERMINATE
            : selection.available && (selection.values.enabledSolids & 1U << index) != 0 ? BST_CHECKED : BST_UNCHECKED;
        states.push_back(SettingsControlState{
            checkbox,
            selection.available,
            state,
            std::nullopt,
            std::nullopt
        });
    }
}

/// Persists row selection independently of pending animation settings and output checkboxes.
static void RememberSelectedAnimationMonitors(SettingsWindowData& data, const std::vector<std::size_t>& selected) {
    if (data.updating || !data.monitorSelectionInitialized || !data.settings) {
        return;
    }
    const std::wstring devices = selected.empty()
        ? NO_ANIMATION_MONITORS
        : JoinMonitorDevices(data.monitors, selected);
    const bool allSelected = data.monitors.empty()
        ? data.settings->allAnimationMonitorsSelected
        : selected.size() == data.monitors.size();
    if (devices == data.settings->selectedAnimationMonitors
            && allSelected == data.settings->allAnimationMonitorsSelected) {
        return;
    }
    data.settings->selectedAnimationMonitors = devices;
    data.settings->allAnimationMonitorsSelected = allSelected;
    data.settings->SaveWindowPositions();
}

/// Appends selected monitor row names to the localized settings title without changing output checkboxes.
static void UpdateSettingsWindowCaption(HWND window, const SettingsWindowData& data,
        const std::vector<std::size_t>& selected) {
    const LocalizedText& strings = Text(data.language);
    std::wstring caption = data.appMode ? strings.controlTitle : strings.settingsTitle;
    bool first = true;
    for (const std::size_t index : selected) {
        if (index >= data.monitorListEntries.size() || data.monitorListEntries[index].text[0].empty()) {
            continue;
        }
        caption += first ? L" — " : L", ";
        caption += data.monitorListEntries[index].text[0];
        first = false;
    }
    SetWindowTextIfChanged(GetAncestor(window, GA_ROOT), caption);
}

/// Prepares the complete selected-monitor state before changing or repainting any controls.
static void UpdateMonitorAnimationControls(HWND window, SettingsWindowData& data) {
    data.monitorSelectionUpdatePending = false;
    window = SettingsContentWindow(window);
    const std::vector<std::size_t> selected = UpdateSelectedAnimationDevices(window, data);
    RememberSelectedAnimationMonitors(data, selected);
    const MonitorSelection selection = data.settings->SelectionForMonitors(data.selectedAnimationDevices);
    std::vector<SettingsControlState> states;
    states.push_back(SettingsControlState{ GetDlgItem(window, ID_ANIMATION_GROUP), selection.available });
    for (std::size_t index = 0; index < std::size(ANIMATION_RADIO_IDS); index++) {
        HWND radio = GetDlgItem(window, ANIMATION_RADIO_IDS[index]);
        const bool checked = selection.available
            && !selection.IsMixed(ANIMATION_RADIO_PROPERTY)
            && selection.values.Value(ANIMATION_RADIO_PROPERTY) == index;
        states.push_back(SettingsControlState{
            radio,
            selection.available,
            checked ? BST_CHECKED : BST_UNCHECKED,
            std::nullopt,
            std::nullopt,
            selection.available && selection.IsMixed(ANIMATION_RADIO_PROPERTY)
        });
    }
    for (const AnimationControl& control : ANIMATION_CHECKBOXES) {
        HWND checkbox = GetDlgItem(window, control.id);
        if (checkbox) {
            const bool enabled = selection.available
                && (control.dependency == AnimationProperty::Count
                    || selection.IsMixed(control.dependency)
                    || selection.values.Value(control.dependency) != 0);
            const UINT state = selection.available && selection.IsMixed(control.property)
                ? BST_INDETERMINATE
                : selection.available && selection.values.Value(control.property) != 0 ? BST_CHECKED : BST_UNCHECKED;
            states.push_back(SettingsControlState{
                checkbox,
                enabled,
                state,
                std::nullopt,
                std::nullopt
            });
        }
    }
    AppendAnimationObjectControlStates(window, selection, states);
    for (const AnimationSliderControl& control : ANIMATION_SLIDERS) {
        HWND slider = GetDlgItem(window, control.id);
        states.push_back(SettingsControlState{
            slider,
            selection.available,
            std::nullopt,
            static_cast<LONG>(selection.values.Value(control.property)),
            std::nullopt,
            selection.available && selection.IsMixed(control.property)
        });
        HWND label = GetDlgItem(window, control.labelId);
        states.push_back(SettingsControlState{
            label,
            selection.available,
            std::nullopt,
            std::nullopt,
            AnimationSliderCaption(label, data, selection, control)
        });
    }
    AppendSettingsActionButtonStates(window, data, selection, states);
    const bool updating = data.updating;
    data.updating = true;
    ApplySettingsControlStates(std::move(states));
    data.updating = updating;
    UpdateSettingsWindowCaption(window, data, selected);
    UpdateScreenSaverInhibition();
}

/// Coalesces native row notifications and paints only the final selection after the current input is processed.
static void ScheduleMonitorAnimationControlsUpdate(HWND window, SettingsWindowData& data) {
    UpdateSelectedAnimationDevices(window, data);
    if (!data.monitorSelectionUpdatePending) {
        data.monitorSelectionUpdatePending =
            PostMessageW(GetAncestor(window, GA_ROOT), UPDATE_MONITOR_ANIMATION_CONTROLS, 0, 0) != FALSE;
        if (!data.monitorSelectionUpdatePending) {
            UpdateMonitorAnimationControls(window, data);
        }
    }
}

/// Publishes selected-monitor edits using the existing live-preview and save policy.
static void CommitMonitorAnimation(HWND window, SettingsWindowData& data, bool save = true) {
    if ((data.appMode || data.previewActive) && app) {
        SyncRuntimeSettings(*app);
    }
    if (data.appMode && save) {
        data.settings->Save();
    }
    UpdateMonitorAnimationControls(window, data);
}

/// Changes one property only; other properties and unselected display identities remain untouched.
static void SetSelectedMonitorValue(HWND window, SettingsWindowData& data, AnimationProperty property,
        std::uint32_t value, bool save = true) {
    data.settings->SetMonitorValue(data.selectedAnimationDevices, property, value);
    CommitMonitorAnimation(window, data, save);
}

/// Rebuilds monitor rows while keeping output checkboxes separate from persistent row selection.
static void PopulateMonitorList(HWND window, SettingsWindowData& data) {
    window = SettingsContentWindow(window);
    HWND list = GetDlgItem(window, ID_MONITOR_LIST);
    if (!list) {
        return;
    }
    std::vector<std::wstring> editedDevices = data.selectedAnimationDevices;
    if (!data.monitorSelectionInitialized && !data.settings->allAnimationMonitorsSelected) {
        for (const DisplayMonitor& monitor : data.monitors) {
            if (MonitorDeviceSelected(data.settings->selectedAnimationMonitors, monitor.device)) {
                editedDevices.push_back(monitor.device);
            }
        }
    }
    InitializeMonitorAnimations(*data.settings, data.monitors);
    const bool updating = data.updating;
    data.updating = true;
    WindowRedrawScope redraw(list);
    const LocalizedText& strings = Text(data.language);
    const MonitorColumnText& monitorStrings = MonitorColumnsText(data.language);
    const wchar_t* columnTitles[]{
        strings.monitor,
        monitorStrings.model,
        strings.resolution,
        monitorStrings.refreshRate,
        monitorStrings.bitDepth,
        monitorStrings.colorFormat,
        monitorStrings.colorSpace,
        strings.position
    };
    LVCOLUMNW column{};
    column.mask = LVCF_TEXT;
    for (int index = 0; index < static_cast<int>(std::size(columnTitles)); index++) {
        column.pszText = const_cast<LPWSTR>(columnTitles[index]);
        ListView_SetColumn(list, index, &column);
    }
    ListView_DeleteAllItems(list);
    const std::vector<MonitorDetails> monitorDetails = ReadMonitorDetails(data.monitors);
    data.monitorListEntries.resize(data.monitors.size());
    std::vector<std::size_t> selected = SelectedMonitorIndices(data.monitors, data.settings->animationMonitorDevice);
    bool selEmpty = selected.empty();
    if (selEmpty && !data.monitors.empty() && !NoAnimationMonitorsSelected(data.settings->animationMonitorDevice)) {
        selected.push_back(PreferredMonitorIndex(data.monitors, data.settings->animationMonitorDevice));
        selEmpty = false;
    }
    if (data.appMode) {
        data.settings->animationMonitorDevice = selEmpty
            ? NO_ANIMATION_MONITORS
            : JoinMonitorDevices(data.monitors, selected);
    }
    for (std::size_t index = 0; index < data.monitors.size(); index++) {
        const DisplayMonitor& monitor = data.monitors[index];
        MonitorListEntry& entry = data.monitorListEntries[index];
        entry.details = monitorDetails[index];
        const MonitorDetails& details = entry.details;
        entry.text[0] = MonitorDisplayName(monitor.device);
        if (monitor.primary) {
            entry.text[0] += std::wstring(L" (") + strings.primary + L")";
        }
        LVITEMW item{};
        item.mask = LVIF_TEXT | LVIF_PARAM;
        item.iItem = static_cast<int>(index);
        item.pszText = entry.text[0].data();
        item.lParam = static_cast<LPARAM>(index);
        const int row = ListView_InsertItem(list, &item);
        entry.text[1] = details.model.empty() ? L"—" : details.model;
        wchar_t value[96]{};
        swprintf_s(value, L"%ld × %ld", monitor.rect.right - monitor.rect.left, monitor.rect.bottom - monitor.rect.top);
        entry.text[2] = value;
        entry.text[3] = MonitorRefreshRateText(details);
        entry.text[4] = MonitorBitDepthText(details, data.language);
        entry.text[5] = MonitorColorFormatText(details.colorEncoding);
        entry.text[6] = MonitorColorSpaceText(details.colorSpace);
        swprintf_s(value, L"x=%ld, y=%ld", monitor.rect.left, monitor.rect.top);
        entry.text[7] = value;
        for (int columnIndex = 1; columnIndex < MONITOR_COLUMN_COUNT; columnIndex++) {
            ListView_SetItemText(list, row, columnIndex, entry.text[columnIndex].data());
        }
        if (data.appMode) {
            ListView_SetCheckState(list, row, std::find(selected.begin(), selected.end(), index) != selected.end());
        }
        if (data.settings->allAnimationMonitorsSelected
                || std::find(editedDevices.begin(), editedDevices.end(), monitor.device) != editedDevices.end()) {
            ListView_SetItemState(list, row, LVIS_SELECTED, LVIS_SELECTED);
        }
    }
    if (ListView_GetNextItem(list, -1, LVNI_FOCUSED) < 0 && !data.monitors.empty()) {
        const int initial = data.appMode && !selEmpty ? static_cast<int>(selected.front()) : 0;
        ListView_SetItemState(list, initial, LVIS_FOCUSED, LVIS_FOCUSED);
    }
    ApplyMonitorListSort(list, data);
    const int focusedRow = ListView_GetNextItem(list, -1, LVNI_FOCUSED);
    if (focusedRow >= 0) {
        ListView_EnsureVisible(list, focusedRow, FALSE);
    }
    data.monitorSelectionInitialized = true;
    data.updating = updating;
    UpdateMonitorAnimationControls(window, data);
}

/// Applies localized captions only to this project's animation controls.
static void ApplyAnimationCaptions(HWND window, const SettingsWindowData& data) {
    const LocalizedText& strings = Text(data.language);
    SetDlgItemTextW(window, ID_CAMERA_STATIC, strings.observeSpace);
    SetDlgItemTextW(window, ID_CAMERA_FLIGHT, strings.flyThroughSpace);
    SetDlgItemTextW(window, ID_AMBIENT_LIGHT, AmbientLightText(data.language));
    SetDlgItemTextW(window, ID_RIM_LIGHT, RimLightText(data.language));
    SetDlgItemTextW(window, ID_MAIN_LIGHT, strings.mainLight);
    SetDlgItemTextW(window, ID_FILL_LIGHT, strings.fillLight);
    SetDlgItemTextW(window, ID_SOLIDS_GROUP, strings.solidObjects);
    for (std::size_t index = 0; index < SOLID_COUNT; index++) {
        SetDlgItemTextW(window, ID_SOLID_FIRST + static_cast<int>(index), strings.solids[index]);
    }
}

/// Applies one language atomically to all settings and information windows.
static void ApplyLocalizedCaptions(HWND window, SettingsWindowData& data) {
    const LocalizedText& strings = Text(data.language);
    data.updating = true;
    window = SettingsContentWindow(window);
    SetDlgItemTextW(window, ID_LANGUAGE_LABEL, strings.language);
    if (data.appMode) {
        SetDlgItemTextW(window, ID_PREVENT_SCREEN_SAVER, PreventScreenSaverText(data.language));
        if (data.settings) {
            SendDlgItemMessageW(window, ID_PREVENT_SCREEN_SAVER, BM_SETCHECK,
                data.settings->preventScreenSaver ? BST_CHECKED : BST_UNCHECKED, 0);
        }
    }
    ApplyAnimationCaptions(window, data);
    SetDlgItemTextW(window, ID_ALL_ANIMATIONS, strings.enableAll);
    SetDlgItemTextW(window, ID_NO_ANIMATIONS, strings.disableAll);
    SetDlgItemTextW(window, ID_OK, strings.ok);
    SetDlgItemTextW(window, ID_CANCEL, strings.cancel);
    SetDlgItemTextW(window, ID_PREVIEW_TOGGLE, data.previewActive
        ? DisablePreviewText(data.language)
        : EnablePreviewText(data.language));
    SetDlgItemTextW(window, ID_RECORD_TOGGLE, PrimaryIsRecording()
        ? strings.stopRecording
        : strings.startRecording);
    SetDlgItemTextW(window, ID_PAUSE, app && app->paused
        ? strings.resume
        : strings.pause);
    SetDlgItemTextW(window, ID_INSTALL, IsScreenSaverInstalled()
        ? UninstallScreenSaverText(data.language)
        : strings.installScreenSaver);
    SetDlgItemTextW(window, ID_RECORDING_SETTINGS, RecordingSettingsText(data.language).title);
    SetDlgItemTextW(window, ID_SNAPSHOT, SnapshotButtonText(data.language));
    SetDlgItemTextW(window, ID_HELP, HelpButtonText(data.language));
    SetDlgItemTextW(window, ID_ABOUT, AboutButtonText(data.language));
    if (data.appMode) {
        RestoreCurrentStatus();
    }
    SetDlgItemTextW(window, ID_MONITOR_GROUP, strings.animationMonitor);
    UpdateSliderLabels(window, data);
    PopulateMonitorList(window, data);
    AssignSettingsMnemonics(window);
    UpdateSettingsTextControlLayout(window);
    RefreshInformationWindows(data.language, data.appMode);
    data.updating = false;
    UpdateSettingsActionButtons(window);
}

/// Reports whether one production surface can use its own output's vertical-blank clock.
/// Self-tests retain their timer path without depending on a display being available.
static bool UsesPresentationPacing(RenderSurface& surface, bool inspect) {
    const std::lock_guard lock(surface.rendererMutex);
    return !inspect && surface.renderer->UsesVerticalBlankWait();
}

/// Returns one animation surface's current render dimensions.
static void GetSurfaceDimensions(RenderSurface& surface, unsigned& width, unsigned& height) {
    const std::lock_guard lock(surface.rendererMutex);
    width = surface.renderer->Width();
    height = surface.renderer->Height();
}

/// Draws one animation surface while holding its renderer lock.
static void DrawSurface(RenderSurface& surface, const SceneState& scene, bool inspect) {
    const std::lock_guard lock(surface.rendererMutex);
    surface.renderer->Draw(scene, inspect, 1);
}

/// Counts one completed frame and asks the UI thread to enable animation actions after the first frame.
static void CompleteSurfaceFrame(Application& application, RenderSurface& surface) {
    const unsigned previousFrames = surface.renderedFrames.fetch_add(1, std::memory_order_relaxed);
    if (previousFrames == 0 && application.mode == RunMode::Application && application.controlWindow) {
        PostMessageW(application.controlWindow, UPDATE_SETTINGS_ACTION_BUTTONS, 0, 0);
    }
}

/// Waits only for the part of a monitor period not already consumed by rendering and Present.
static void WaitForRenderDeadline(HANDLE timer, double deadline, LONGLONG frequency) {
    LARGE_INTEGER now{};
    QueryPerformanceCounter(&now);
    const double remaining = deadline - static_cast<double>(now.QuadPart);
    if (remaining <= 0.0 || frequency <= 0) {
        return;
    }
    if (timer) {
        LARGE_INTEGER due{};
        due.QuadPart = -std::max(1LL, static_cast<LONGLONG>(std::ceil(remaining * 10000000.0 / frequency)));
        if (SetWaitableTimer(timer, &due, 0, nullptr, nullptr, FALSE)) {
            if (WaitForSingleObject(timer, INFINITE) == WAIT_OBJECT_0) {
                return;
            }
        }
    }
    Sleep(static_cast<DWORD>(std::max(1.0, std::floor(remaining * 1000.0 / frequency))));
}

/// Creates the same high-resolution timer for legacy presentation and a lost output clock.
static HANDLE CreateRenderFrameTimer() {
    constexpr DWORD HIGH_RESOLUTION_TIMER = 0x00000002;
    HANDLE timer = CreateWaitableTimerExW(nullptr, nullptr, HIGH_RESOLUTION_TIMER, TIMER_ALL_ACCESS);
    if (!timer) {
        timer = CreateWaitableTimerW(nullptr, FALSE, nullptr);
    }
    return timer;
}

/// Advances the unchanged solid simulation on this monitor's independent refresh-paced worker.
/// Flip presentation waits for the output itself; legacy timing waits only after a fast Present.
static void RenderSurfaceLoop(Application* app, RenderSurface* surface) {
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_ABOVE_NORMAL);
    DWORD multimediaTaskIndex = 0;
    HANDLE multimediaTask = AvSetMmThreadCharacteristicsW(L"Games", &multimediaTaskIndex);
    if (multimediaTask) {
        AvSetMmThreadPriority(multimediaTask, AVRT_PRIORITY_HIGH);
    }
    LARGE_INTEGER frequency{};
    QueryPerformanceFrequency(&frequency);
    const double rate = std::clamp(surface->refreshFrequency, 24.0, 360.0);
    const double frameSeconds = 1.0 / rate;
    const double periodTicks = static_cast<double>(frequency.QuadPart) / rate;
    const bool inspect = app->mode == RunMode::SelfTest || app->mode == RunMode::SelfTestAllMonitors;
    bool presentationPaced = UsesPresentationPacing(*surface, inspect);
    HANDLE timer = nullptr;
    if (!presentationPaced) {
        timer = CreateRenderFrameTimer();
    }
    while (!app->closing.load(std::memory_order_relaxed) && !surface->stopRequested.load(std::memory_order_relaxed)) {
        const HRESULT waitResult = presentationPaced ? surface->renderer->WaitForNextFrame() : S_OK;
        if (app->closing.load(std::memory_order_relaxed) || surface->stopRequested.load(std::memory_order_relaxed)) {
            break;
        }
        if (FAILED(waitResult)) {
            timer = CreateRenderFrameTimer();
            presentationPaced = false;
            continue;
        }
        LARGE_INTEGER frameStarted{};
        QueryPerformanceCounter(&frameStarted);
        unsigned width = 0;
        unsigned height = 0;
        GetSurfaceDimensions(*surface, width, height);
        const MonitorAnimation animation = SurfaceAnimationSettings(*surface);
        if (!app->paused.load(std::memory_order_relaxed)) {
            surface->simulation.SetViewport(width, height);
            const double simulationSeconds =
                frameSeconds * (app->mode == RunMode::Preview ? SYSTEM_PREVIEW_SPEED_MULTIPLIER : 1.0);
            surface->simulation.Step(simulationSeconds,
                animation.objectSpeedPercent / 100.0f,
                animation.cameraSpeedPercent / 100.0f,
                animation.cameraFlight,
                animation.enabledSolids,
                animation.copyCount,
                animation.objectSizePercent / 100.0f,
                app->mode == RunMode::Preview ? 16 : 1);
        }
        SceneState scene = surface->simulation.State();
        scene.mainLight = animation.mainLight;
        scene.fillLight = animation.fillLight;
        scene.ambientLight = animation.ambientLight;
        scene.rimLight = animation.rimLight;
        DrawSurface(*surface, scene, inspect);
        CompleteSurfaceFrame(*app, *surface);
        if (!presentationPaced) {
            WaitForRenderDeadline(timer, static_cast<double>(frameStarted.QuadPart) + periodTicks,
                frequency.QuadPart);
        }
    }
    if (timer) {
        CloseHandle(timer);
    }
    if (multimediaTask) {
        AvRevertMmThreadCharacteristics(multimediaTask);
    }
}

/// Starts the worker thread owned by a fully initialized render surface.
static void StartRenderSurface(Application& app, RenderSurface& surface) {
    surface.stopRequested.store(false, std::memory_order_relaxed);
    surface.renderedFrames.store(0, std::memory_order_relaxed);
    surface.renderThread = std::thread(RenderSurfaceLoop, &app, &surface);
}

/// Requests and joins one render thread.
static void StopRenderSurface(RenderSurface& surface) {
    surface.stopRequested.store(true, std::memory_order_relaxed);
    if (surface.renderThread.joinable()) {
        surface.renderThread.join();
    }
}

/// Stops every render worker before windows or shared state are destroyed.
static void StopAllRenderSurfaces(Application& app) {
    for (std::unique_ptr<RenderSurface>& surface : app.surfaces) {
        StopRenderSurface(*surface);
    }
}

/// Applies the current system message font to one descendant control.
static BOOL CALLBACK ApplySystemDialogFont(HWND child, LPARAM fontParameter) {
    SendMessageW(child, WM_SETFONT, fontParameter, TRUE);
    return TRUE;
}

/// Creates the font conventionally used by native Windows dialog controls.
static HFONT CreateSystemDialogFont() {
    NONCLIENTMETRICSW metrics{};
    metrics.cbSize = sizeof(metrics);
    if (SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, sizeof(metrics), &metrics, 0)) {
        return CreateFontIndirectW(&metrics.lfMessageFont);
    }
    return nullptr;
}

/// Marks the requested font family as found and stops font enumeration.
static int CALLBACK FindFontCallback(const LOGFONTW*, const TEXTMETRICW*, DWORD, LPARAM parameter) {
    *reinterpret_cast<bool*>(parameter) = true;
    return 0;
}

/// Checks whether the requested font family is installed on the system.
static bool IsFontAvailable(const wchar_t* face) {
    HDC screen = GetDC(nullptr);
    if (screen == nullptr) {
        return false;
    }
    LOGFONTW font = {};
    font.lfCharSet = DEFAULT_CHARSET;
    wcsncpy_s(font.lfFaceName, face, _TRUNCATE);
    bool found = false;
    EnumFontFamiliesExW(screen, &font, FindFontCallback, reinterpret_cast<LPARAM>(&found), 0);
    ReleaseDC(nullptr, screen);
    return found;
}

/// Creates the regular 8.25-point license font with a Courier New fallback; the information window owns it.
static HFONT CreateAboutFont() {
    NONCLIENTMETRICSW metrics = {};
    metrics.cbSize = sizeof(metrics);
    LOGFONTW font = {};
    if (SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, sizeof(metrics), &metrics, 0)) {
        font = metrics.lfMessageFont;
    } else {
        font.lfHeight = -12;
        font.lfCharSet = DEFAULT_CHARSET;
    }
    HDC screen = GetDC(nullptr);
    int dpi = screen == nullptr ? 96 : GetDeviceCaps(screen, LOGPIXELSY);
    if (screen != nullptr) {
        ReleaseDC(nullptr, screen);
    }
    font.lfHeight = -MulDiv(825, dpi > 0 ? dpi : 96, 7200);
    font.lfWidth = 0;
    font.lfWeight = FW_NORMAL;
    font.lfItalic = FALSE;
    font.lfUnderline = FALSE;
    font.lfStrikeOut = FALSE;
    font.lfPitchAndFamily = FIXED_PITCH | FF_MODERN;
    const wchar_t* face = IsFontAvailable(L"Consolas") ? L"Consolas" : L"Courier New";
    wcsncpy_s(font.lfFaceName, face, _TRUNCATE);
    HFONT result = CreateFontIndirectW(&font);
    if (result == nullptr && wcscmp(face, L"Courier New") != 0) {
        wcsncpy_s(font.lfFaceName, L"Courier New", _TRUNCATE);
        result = CreateFontIndirectW(&font);
    }
    return result;
}

/// Creates, owns and applies a system dialog font to all settings controls.
static void ApplySystemDialogFont(HWND window, SettingsWindowData& data) {
    data.systemDialogFont = CreateSystemDialogFont();
    if (data.systemDialogFont) {
        EnumChildWindows(window, ApplySystemDialogFont, reinterpret_cast<LPARAM>(data.systemDialogFont));
    }
    UpdateSettingsControlMetrics(window);
}

/// Aligns a settings push button or checkbox with adjacent text using their shared application font.
/// Accounts for classic buttons' inclusive text rectangles and preserves size, horizontal position, and Z order.
static void AlignSettingsButton(HWND button, HWND reference) {
    AlignSettingsControl(button, reference);
}

/// Aligns a label with the native combo text origin used by CalClock's button alignment.
static void AlignSettingsLabel(HWND label, HWND reference) {
    AlignSettingsControl(label, reference);
}

/// Aligns mixed settings rows after the shared font, theme, DPI or native control metrics change.
static void UpdateSettingsControlMetrics(HWND window) {
    window = SettingsContentWindow(window);
    UpdateComboBoxDropDownSize(GetDlgItem(window, ID_LANGUAGE));
    AlignSettingsControl(GetDlgItem(window, ID_LANGUAGE_LABEL), GetDlgItem(window, ID_LANGUAGE));
    AlignSettingsControl(GetDlgItem(window, ID_PREVENT_SCREEN_SAVER), GetDlgItem(window, ID_LANGUAGE));
    for (const SettingsControlAlignment& alignment : ANIMATION_CONTROL_ALIGNMENTS) {
        AlignSettingsControl(GetDlgItem(window, alignment.control), GetDlgItem(window, alignment.reference));
    }
}

/// Calculates a scrollable fixed-content window that fits the monitor work area.
static SettingsWindowLayout GetSettingsWindowLayout(bool appMode, DWORD extendedStyle, const RECT& workArea) {
    SettingsWindowLayout layout{};
    const DWORD baseStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_CLIPCHILDREN | (appMode ? WS_MINIMIZEBOX : 0);
    const int desiredWidth = SETTINGS_WIDTH;
    const int desiredHeight = appMode ? APPLICATION_SETTINGS_HEIGHT : SCREEN_SAVER_SETTINGS_HEIGHT;
    RECT frame{};
    AdjustWindowRectEx(&frame, baseStyle, FALSE, extendedStyle);
    layout.contentWidth = desiredWidth - (frame.right - frame.left);
    const int totalClientHeight = desiredHeight - (frame.bottom - frame.top);
    layout.contentHeight = totalClientHeight - (appMode ? 22 : 0);
    const int workWidth = std::max(1L, workArea.right - workArea.left);
    const int workHeight = std::max(1L, workArea.bottom - workArea.top);
    const int horizontalScrollHeight = GetSystemMetrics(SM_CYHSCROLL);
    const int verticalScrollWidth = GetSystemMetrics(SM_CXVSCROLL);
    bool horizontalScroll = desiredWidth > workWidth;
    bool verticalScroll = desiredHeight > workHeight;
    for (int pass = 0; pass < 2; pass++) {
        layout.width = std::min(workWidth, desiredWidth + (verticalScroll ? verticalScrollWidth : 0));
        layout.height = std::min(workHeight, desiredHeight + (horizontalScroll ? horizontalScrollHeight : 0));
        if (layout.width - (verticalScroll ? verticalScrollWidth : 0) < desiredWidth) {
            horizontalScroll = true;
        }
        if (layout.height - (horizontalScroll ? horizontalScrollHeight : 0) < desiredHeight) {
            verticalScroll = true;
        }
    }
    layout.width = std::min(workWidth, desiredWidth + (verticalScroll ? verticalScrollWidth : 0));
    layout.height = std::min(workHeight, desiredHeight + (horizontalScroll ? horizontalScrollHeight : 0));
    layout.style = baseStyle;
    if (horizontalScroll) {
        layout.scrollStyle |= WS_HSCROLL;
    }
    if (verticalScroll) {
        layout.scrollStyle |= WS_VSCROLL;
    }
    if (!appMode) {
        layout.style |= layout.scrollStyle;
    }
    return layout;
}

/// Returns the visible client height of the scrollable settings content.
static int SettingsViewportHeight(HWND window, const SettingsWindowData& data) {
    RECT client{};
    GetClientRect(data.contentWindow ? data.contentWindow : window, &client);
    return std::max(0L, client.bottom - client.top);
}

/// Sizes the settings panel above the fixed status bar without changing control geometry.
static void LayoutSettingsContent(HWND window, const SettingsWindowData& data) {
    if (!data.contentWindow || !app || !app->status) {
        return;
    }
    SendMessageW(app->status, WM_SIZE, 0, 0);
    RECT client{};
    RECT status{};
    GetClientRect(window, &client);
    GetWindowRect(app->status, &status);
    const int height = std::max(0L, client.bottom - client.top - (status.bottom - status.top));
    SetWindowPos(data.contentWindow, nullptr, 0, 0, client.right - client.left, height,
        SWP_NOZORDER | SWP_NOACTIVATE | SWP_SHOWWINDOW);
}

/// Moves all virtual-content controls together after a scroll-position change.
static void MoveSettingsChildren(HWND window, int deltaX, int deltaY) {
    window = SettingsContentWindow(window);
    HDWP positions = BeginDeferWindowPos(24);
    for (HWND child = GetWindow(window, GW_CHILD); child != nullptr;) {
        HWND next = GetWindow(child, GW_HWNDNEXT);
        if (!app || child != app->status) {
            RECT rect{};
            GetWindowRect(child, &rect);
            MapWindowPoints(HWND_DESKTOP, window, reinterpret_cast<POINT*>(&rect), 2);
            positions = DeferWindowPos(positions, child, nullptr, rect.left + deltaX, rect.top + deltaY, 0, 0,
                SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
        }
        child = next;
    }
    if (positions) {
        EndDeferWindowPos(positions);
    }
    InvalidateRect(window, nullptr, TRUE);
}

/// Recomputes scroll ranges and preserves current virtual-content position.
static void UpdateSettingsScrollBars(HWND window, SettingsWindowData& data, bool initialize) {
    window = SettingsContentWindow(window);
    RECT client{};
    GetClientRect(window, &client);
    const LONG_PTR style = GetWindowLongPtrW(window, GWL_STYLE);
    const ScrollBarData bars[]{
        ScrollBarData{ SB_HORZ, data.contentWidth, static_cast<UINT>(std::max(0L, client.right - client.left)) },
        ScrollBarData{ SB_VERT, data.contentHeight, static_cast<UINT>(SettingsViewportHeight(window, data)) }
    };
    for (const ScrollBarData& bar : bars) {
        const LONG_PTR flag = bar.bar == SB_HORZ ? WS_HSCROLL : WS_VSCROLL;
        if ((style & flag) == 0) {
            continue;
        }
        SCROLLINFO current{};
        current.cbSize = sizeof(current);
        current.fMask = SIF_POS;
        GetScrollInfo(window, bar.bar, &current);
        const int oldPosition = current.nPos;
        SCROLLINFO information{};
        information.cbSize = sizeof(information);
        information.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
        information.nMin = 0;
        information.nMax = std::max(0, bar.extent - 1);
        information.nPage = bar.page;
        information.nPos = initialize ? 0 : oldPosition;
        SetScrollInfo(window, bar.bar, &information, TRUE);
        information.fMask = SIF_POS;
        GetScrollInfo(window, bar.bar, &information);
        if (!initialize && information.nPos != oldPosition) {
            MoveSettingsChildren(window,
                bar.bar == SB_HORZ ? oldPosition - information.nPos : 0,
                bar.bar == SB_VERT ? oldPosition - information.nPos : 0);
        }
    }
}

/// Applies one horizontal or vertical scroll-bar request.
static bool ScrollSettingsWindow(HWND window, SettingsWindowData& data, int bar, int request) {
    window = SettingsContentWindow(window);
    const LONG_PTR style = GetWindowLongPtrW(window, GWL_STYLE);
    const LONG_PTR flag = bar == SB_HORZ ? WS_HSCROLL : WS_VSCROLL;
    if ((style & flag) == 0) {
        return false;
    }
    SCROLLINFO information{};
    information.cbSize = sizeof(information);
    information.fMask = SIF_ALL;
    if (!GetScrollInfo(window, bar, &information)) {
        return false;
    }
    const int oldPosition = information.nPos;
    int position = oldPosition;
    constexpr int lineSize = 24;
    switch (request) {
        case SB_LINELEFT:
            position -= lineSize;
            break;
        case SB_LINERIGHT:
            position += lineSize;
            break;
        case SB_PAGELEFT:
            position -= static_cast<int>(information.nPage);
            break;
        case SB_PAGERIGHT:
            position += static_cast<int>(information.nPage);
            break;
        case SB_THUMBPOSITION:
        case SB_THUMBTRACK:
            position = information.nTrackPos;
            break;
        case SB_LEFT:
            position = information.nMin;
            break;
        case SB_RIGHT:
            position = information.nMax;
            break;
        default:
            return true;
    }
    const int maximum = information.nMax - std::max(0, static_cast<int>(information.nPage) - 1);
    position = std::clamp(position, information.nMin, std::max(information.nMin, maximum));
    information.fMask = SIF_POS;
    information.nPos = position;
    SetScrollInfo(window, bar, &information, TRUE);
    information.fMask = SIF_POS;
    GetScrollInfo(window, bar, &information);
    position = information.nPos;
    if (position != oldPosition) {
        MoveSettingsChildren(window,
            bar == SB_HORZ ? oldPosition - position : 0,
            bar == SB_VERT ? oldPosition - position : 0);
    }
    return true;
}

/// Converts a mouse-wheel gesture into virtual-content scrolling.
static bool ScrollSettingsWheel(HWND window, SettingsWindowData& data, WPARAM wParam) {
    window = SettingsContentWindow(window);
    const LONG_PTR style = GetWindowLongPtrW(window, GWL_STYLE);
    const bool horizontal = (GET_KEYSTATE_WPARAM(wParam) & MK_SHIFT) != 0 && (style & WS_HSCROLL) != 0;
    const int bar = horizontal ? SB_HORZ : SB_VERT;
    if (bar == SB_VERT && (style & WS_VSCROLL) == 0) {
        return false;
    }
    const int steps = GET_WHEEL_DELTA_WPARAM(wParam) / WHEEL_DELTA;
    const int request = steps > 0 ? SB_LINELEFT : SB_LINERIGHT;
    for (int index = 0; index < std::abs(steps) * 3; index++) {
        ScrollSettingsWindow(window, data, bar, request);
    }
    return true;
}

/// Clamps and applies an absolute settings scroll position.
static void SetSettingsScrollPosition(HWND window, int bar, int requestedPosition) {
    window = SettingsContentWindow(window);
    SCROLLINFO information{};
    information.cbSize = sizeof(information);
    information.fMask = SIF_ALL;
    if (!GetScrollInfo(window, bar, &information)) {
        return;
    }
    const int oldPosition = information.nPos;
    const int maximum = information.nMax - std::max(0, static_cast<int>(information.nPage) - 1);
    information.fMask = SIF_POS;
    information.nPos = std::clamp(requestedPosition, information.nMin, std::max(information.nMin, maximum));
    SetScrollInfo(window, bar, &information, TRUE);
    information.fMask = SIF_POS;
    GetScrollInfo(window, bar, &information);
    if (information.nPos != oldPosition) {
        MoveSettingsChildren(window,
            bar == SB_HORZ ? oldPosition - information.nPos : 0,
            bar == SB_VERT ? oldPosition - information.nPos : 0);
    }
}

/// Scrolls the virtual client just enough to expose the newly focused control.
static void EnsureSettingsControlVisible(HWND window, SettingsWindowData& data, HWND control) {
    window = SettingsContentWindow(window);
    if (!control || GetParent(control) != window) {
        return;
    }
    RECT rect{};
    GetWindowRect(control, &rect);
    MapWindowPoints(HWND_DESKTOP, window, reinterpret_cast<POINT*>(&rect), 2);
    RECT client{};
    GetClientRect(window, &client);
    constexpr int margin = 8;
    SCROLLINFO horizontal{};
    horizontal.cbSize = sizeof(horizontal);
    horizontal.fMask = SIF_POS;
    if (GetScrollInfo(window, SB_HORZ, &horizontal)) {
        const int viewportWidth = static_cast<int>(client.right - client.left);
        const int controlWidth = static_cast<int>(rect.right - rect.left);
        int requested = horizontal.nPos;
        if (rect.left < margin) {
            requested += rect.left - margin;
        } else if (controlWidth <= viewportWidth - 2 * margin && rect.right > viewportWidth - margin) {
            requested += rect.right - (viewportWidth - margin);
        }
        SetSettingsScrollPosition(window, SB_HORZ, requested);
    }
    SCROLLINFO vertical{};
    vertical.cbSize = sizeof(vertical);
    vertical.fMask = SIF_POS;
    if (GetScrollInfo(window, SB_VERT, &vertical)) {
        const int viewportHeight = SettingsViewportHeight(window, data);
        const int controlHeight = static_cast<int>(rect.bottom - rect.top);
        int requested = vertical.nPos;
        if (rect.top < margin) {
            requested += rect.top - margin;
        } else if (controlHeight <= viewportHeight - 2 * margin && rect.bottom > viewportHeight - margin) {
            requested += rect.bottom - (viewportHeight - margin);
        }
        SetSettingsScrollPosition(window, SB_VERT, requested);
    }
}

/// Selects the focused native pushbutton as the Enter default, otherwise restoring the form's original default.
static void UpdateSettingsDefaultButton(HWND window, SettingsWindowData& data, HWND focused) {
    HWND button = nullptr;
    if (!data.appMode) {
        button = GetDlgItem(SettingsContentWindow(window), ID_OK);
    }
    if (data.defaultButton == nullptr) {
        data.defaultButton = button;
    }
    if (IsChild(window, focused) && IsWindowVisible(focused) && IsWindowEnabled(focused)) {
        LRESULT dialogCode = SendMessageW(focused, WM_GETDLGCODE, 0, 0);
        bool pushButton = (dialogCode & (DLGC_DEFPUSHBUTTON | DLGC_UNDEFPUSHBUTTON)) != 0;
        if (pushButton) {
            button = focused;
        }
    }
    if (button == data.defaultButton) {
        return;
    }
    if (data.defaultButton != nullptr && IsWindow(data.defaultButton)) {
        SendMessageW(data.defaultButton, BM_SETSTYLE, BS_PUSHBUTTON, TRUE);
    }
    data.defaultButton = button;
    if (button != nullptr) {
        SendMessageW(button, BM_SETSTYLE, BS_DEFPUSHBUTTON, TRUE);
    }
}

/// Tracks native default-button state and requests visibility after tab-stop focus changes.
static LRESULT CALLBACK SettingsTabStopSubclass(HWND control, UINT msg, WPARAM wParam, LPARAM lParam, UINT_PTR subclassId,
        DWORD_PTR) {
    HWND parent = GetParent(control);
    SettingsWindowData* data = reinterpret_cast<SettingsWindowData*>(GetWindowLongPtrW(parent, GWLP_USERDATA));
    if (msg == WM_SETFONT || msg == WM_THEMECHANGED || msg == WM_DPICHANGED_AFTERPARENT) {
        PostMessageW(GetAncestor(control, GA_ROOT), UPDATE_SETTINGS_CONTROL_METRICS, 0, 0);
    }
    if (msg == WM_SETFOCUS) {
        if (data) {
            data->lastFocusedControl = control;
            UpdateSettingsDefaultButton(GetAncestor(control, GA_ROOT), *data, control);
        }
        PostMessageW(parent, ENSURE_SETTINGS_CONTROL_VISIBLE, reinterpret_cast<WPARAM>(control), 0);
    } else if (msg == WM_KILLFOCUS) {
        if (data) {
            UpdateSettingsDefaultButton(GetAncestor(control, GA_ROOT), *data, reinterpret_cast<HWND>(wParam));
        }
    } else if (msg == WM_NCDESTROY) {
        if (data && control == data->defaultButton) {
            data->defaultButton = nullptr;
        }
        RemoveWindowSubclass(control, SettingsTabStopSubclass, subclassId);
    }
    return DefSubclassProc(control, msg, wParam, lParam);
}

/// Subclasses every tab stop that participates in explicit focus navigation.
static void InstallSettingsTabNavigation(HWND window) {
    window = SettingsContentWindow(window);
    for (HWND control = GetWindow(window, GW_CHILD); control; control = GetWindow(control, GW_HWNDNEXT)) {
        if ((GetWindowLongPtrW(control, GWL_STYLE) & WS_TABSTOP) != 0) {
            SetWindowSubclass(control, SettingsTabStopSubclass, 1, 0);
        }
    }
}

/// Classifies one settings control for Z-order reconstruction.
static SettingsControlLayer GetSettingsControlLayer(HWND control) {
    wchar_t className[32]{};
    GetClassNameW(control, className, static_cast<int>(std::size(className)));
    if (_wcsicmp(className, L"STATIC") == 0) {
        if ((GetWindowLongPtrW(control, GWL_STYLE) & SS_TYPEMASK) == SS_ETCHEDHORZ
                || (GetWindowLongPtrW(control, GWL_EXSTYLE) & WS_EX_STATICEDGE) != 0) {
            return SettingsControlLayer::Foreground;
        }
        return SettingsControlLayer::Label;
    }
    if (_wcsicmp(className, L"BUTTON") == 0) {
        const UINT type = static_cast<UINT>(GetWindowLongPtrW(control, GWL_STYLE) & BS_TYPEMASK);
        if (type == BS_CHECKBOX
                || type == BS_AUTOCHECKBOX
                || type == BS_3STATE
                || type == BS_AUTO3STATE
                || type == BS_RADIOBUTTON
                || type == BS_AUTORADIOBUTTON) {
            return SettingsControlLayer::Checkbox;
        }
    }
    return SettingsControlLayer::Foreground;
}

/// Orders settings controls by layer and position while preserving foreground order.
static bool CompareSettingsControls(const PositionedControl& left,
    const PositionedControl& rightControl) {
    const SettingsControlLayer leftLayer = GetSettingsControlLayer(left.window);
    const SettingsControlLayer rightLayer = GetSettingsControlLayer(rightControl.window);
    if (leftLayer != rightLayer) {
        return static_cast<int>(leftLayer) < static_cast<int>(rightLayer);
    }
    if (leftLayer == SettingsControlLayer::Foreground) {
        return false;
    }
    if (left.rect.left == rightControl.rect.left) {
        return left.rect.top < rightControl.rect.top;
    }
    return left.rect.left > rightControl.rect.left;
}

/// Appends the project-specific object controls to the shared tab sequence.
static void AppendAnimationObjectTabOrder(std::vector<int>& order) {
    for (std::size_t index = 0; index < SOLID_COUNT; index++) {
        order.push_back(ID_SOLID_FIRST + static_cast<int>(index));
    }
}

/// Returns the explicit tab sequence for standalone or screen-saver settings.
static std::vector<int> SettingsTabOrder(const SettingsWindowData& data) {
    std::vector<int> order{ ID_LANGUAGE };
    if (data.appMode) {
        order.push_back(ID_PREVENT_SCREEN_SAVER);
    }
    for (const AnimationSliderControl& control : ANIMATION_SLIDERS) {
        order.push_back(control.id);
    }
    order.push_back(ID_ANIMATION_PRIMARY);
    for (const int id : ANIMATION_TAB_CHECKBOX_IDS) {
        order.push_back(id);
    }
    AppendAnimationObjectTabOrder(order);
    order.push_back(ID_ALL_ANIMATIONS);
    order.push_back(ID_NO_ANIMATIONS);
    if (data.appMode) {
        order.push_back(ID_PAUSE);
        order.push_back(ID_HELP);
        order.push_back(ID_ABOUT);
        order.push_back(ID_MONITOR_LIST);
        order.push_back(ID_RECORDING_SETTINGS);
        order.push_back(ID_RECORD_TOGGLE);
        order.push_back(ID_SNAPSHOT);
        order.push_back(ID_INSTALL);
    } else {
        if (data.screenSaverSettings) {
            order.push_back(ID_PREVIEW_TOGGLE);
        }
        order.push_back(ID_HELP);
        order.push_back(ID_ABOUT);
        order.push_back(ID_MONITOR_LIST);
        order.push_back(ID_OK);
        order.push_back(ID_CANCEL);
    }
    return order;
}

/// Moves settings page controls through their declared tab order and exposes keyboard focus cues.
/// Leaves ordinary pushbutton transitions to native dialog processing, as in CalClock.
static bool MoveSettingsTabFocus(HWND parent, const SettingsWindowData& data, bool backwards) {
    parent = SettingsContentWindow(parent);
    std::vector<HWND> controls;
    for (const int id : SettingsTabOrder(data)) {
        HWND control = GetDlgItem(parent, id);
        const bool radioGroup = id == ID_ANIMATION_PRIMARY;
        if (radioGroup) {
            for (const int radioId : ANIMATION_RADIO_IDS) {
                if (SendDlgItemMessageW(parent, radioId, BM_GETCHECK, 0, 0) == BST_CHECKED) {
                    control = GetDlgItem(parent, radioId);
                    break;
                }
            }
        }
        if (control) {
            if (IsWindowVisible(control)
                    && IsWindowEnabled(control)
                    && (radioGroup || (GetWindowLongPtrW(control, GWL_STYLE) & WS_TABSTOP) != 0)) {
                controls.push_back(control);
            }
        }
    }
    if (controls.empty()) {
        return false;
    }
    HWND focused = GetFocus();
    std::vector<HWND>::iterator current = controls.begin();
    for (; current != controls.end(); current++) {
        if (focused == *current || IsChild(*current, focused)) {
            break;
        }
    }
    std::size_t next = 0;
    if (current == controls.end()) {
        return false;
    } else {
        const std::size_t index = static_cast<std::size_t>(current - controls.begin());
        next = backwards ? (index + controls.size() - 1) % controls.size() : (index + 1) % controls.size();
    }
    HWND target = controls[next];
    wchar_t className[32]{};
    GetClassNameW(focused, className, static_cast<int>(std::size(className)));
    const LONG_PTR buttonType = GetWindowLongPtrW(focused, GWL_STYLE) & BS_TYPEMASK;
    const bool nativeNavigation = _wcsicmp(className, L"BUTTON") == 0
        && (buttonType == BS_PUSHBUTTON || buttonType == BS_DEFPUSHBUTTON)
        && GetNextDlgTabItem(parent, focused, backwards) == target;
    if (!nativeNavigation) {
        SetFocus(target);
    }
    const WPARAM showKeyboardCues = MAKEWPARAM(UIS_CLEAR, UISF_HIDEFOCUS | UISF_HIDEACCEL);
    SendMessageW(parent, WM_CHANGEUISTATE, showKeyboardCues, 0);
    SendMessageW(target, WM_UPDATEUISTATE, showKeyboardCues, 0);
    if (target == GetDlgItem(parent, ID_MONITOR_LIST) && ListView_GetItemCount(target) > 0) {
        int item = ListView_GetNextItem(target, -1, LVNI_FOCUSED);
        if (item < 0) {
            item = ListView_GetNextItem(target, -1, LVNI_SELECTED);
        }
        if (item < 0) {
            item = 0;
        }
        ListView_SetItemState(target, item, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
        ListView_EnsureVisible(target, item, FALSE);
        RedrawWindow(target, nullptr, nullptr, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ALLCHILDREN);
    }
    return !nativeNavigation;
}

/// Extends text controls to the content edge and restores their clipping Z-order.
static void UpdateSettingsTextControlLayout(HWND parent) {
    parent = SettingsContentWindow(parent);
    RECT client{};
    if (!parent || !GetClientRect(parent, &client)) {
        return;
    }
    int right = std::max(18L, client.right - 17);
    SettingsWindowData* data = reinterpret_cast<SettingsWindowData*>(GetWindowLongPtrW(parent, GWLP_USERDATA));
    if (data && data->contentWidth > 0) {
        SCROLLINFO horizontal{};
        horizontal.cbSize = sizeof(horizontal);
        horizontal.fMask = SIF_POS;
        GetScrollInfo(parent, SB_HORZ, &horizontal);
        right = std::max(18, data->contentWidth - 17 - horizontal.nPos);
    }
    std::vector<PositionedControl> controls;
    for (HWND control = GetWindow(parent, GW_CHILD); control; control = GetWindow(control, GW_HWNDNEXT)) {
        RECT rect{};
        if (!GetWindowRect(control, &rect)) {
            continue;
        }
        MapWindowPoints(HWND_DESKTOP, parent, reinterpret_cast<POINT*>(&rect), 2);
        const SettingsControlLayer layer = GetSettingsControlLayer(control);
        if (layer != SettingsControlLayer::Foreground) {
            const int id = GetDlgCtrlID(control);
            const bool sliderLabel = std::any_of(std::begin(ANIMATION_SLIDERS), std::end(ANIMATION_SLIDERS),
                [id](const AnimationSliderControl& control) { return control.labelId == id; });
            const bool opaqueLabel = sliderLabel
                || std::find(std::begin(OPAQUE_SETTINGS_LABEL_IDS), std::end(OPAQUE_SETTINGS_LABEL_IDS), id)
                    != std::end(OPAQUE_SETTINGS_LABEL_IDS);
            LONG_PTR style = GetWindowLongPtrW(control, GWL_STYLE);
            style |= WS_CLIPSIBLINGS;
            if (layer == SettingsControlLayer::Label) {
                style |= SS_LEFTNOWORDWRAP;
                const LONG_PTR extended = GetWindowLongPtrW(control, GWL_EXSTYLE);
                SetWindowLongPtrW(control, GWL_EXSTYLE, opaqueLabel
                    ? extended & ~WS_EX_TRANSPARENT
                    : extended | WS_EX_TRANSPARENT);
            }
            SetWindowLongPtrW(control, GWL_STYLE, style);
            if (!sliderLabel) {
                rect.right = std::max(rect.left + 1, static_cast<LONG>(right));
            }
            SetWindowPos(control, nullptr, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
                SWP_NOZORDER | SWP_NOACTIVATE | SWP_NOCOPYBITS);
        }
        controls.push_back(PositionedControl{ control, rect });
    }
    std::stable_sort(controls.begin(), controls.end(), CompareSettingsControls);
    HWND previous = nullptr;
    for (const PositionedControl& control : controls) {
        SetWindowPos(control.window, previous, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | SWP_NOCOPYBITS);
        previous = control.window;
    }
}

/// Decodes the embedded UTF-8 license, removes an optional BOM and a case-insensitive MIT License heading, and trims
/// outer whitespace. Accepts whitespace between heading words, preserves the license body, and normalizes line endings
/// for the edit control.
static std::wstring LoadLicenseText() {
    const HMODULE module = GetModuleHandleW(nullptr);
    HRSRC resource = FindResourceW(module, MAKEINTRESOURCEW(IDR_LICENSE), RT_RCDATA);
    if (resource == nullptr) {
        return std::wstring();
    }
    HGLOBAL loadedResource = LoadResource(module, resource);
    if (loadedResource == nullptr) {
        return std::wstring();
    }
    DWORD byteCount = SizeofResource(module, resource);
    const char* bytes = static_cast<const char*>(LockResource(loadedResource));
    if (bytes == nullptr || byteCount == 0 || byteCount > static_cast<DWORD>(INT_MAX)) {
        return std::wstring();
    }
    int characterCount = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, bytes, static_cast<int>(byteCount),
        nullptr, 0);
    if (characterCount <= 0) {
        return std::wstring();
    }
    std::wstring decoded(characterCount, L'\0');
    const int convertedCount = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, bytes, static_cast<int>(byteCount),
        decoded.data(), characterCount);
    if (convertedCount != characterCount) {
        return std::wstring();
    }
    size_t headingStart = !decoded.empty() && decoded.front() == L'\uFEFF' ? 1 : 0;
    while (headingStart < decoded.size() && iswspace(decoded[headingStart])) {
        headingStart++;
    }
    size_t headingEnd = decoded.find_first_of(L"\r\n", headingStart);
    std::wstring heading = decoded.substr(headingStart, headingEnd - headingStart);
    std::wstring normalizedHeading;
    bool whitespace = false;
    for (wchar_t character : heading) {
        if (iswspace(character)) {
            whitespace = true;
        } else {
            if (whitespace && !normalizedHeading.empty()) {
                normalizedHeading += L' ';
            }
            normalizedHeading += character;
            whitespace = false;
        }
    }
    size_t bodyStart = headingStart;
    if (_wcsicmp(normalizedHeading.c_str(), L"MIT License") == 0) {
        bodyStart = headingEnd == std::wstring::npos ? decoded.size() : headingEnd;
        while (bodyStart < decoded.size() && iswspace(decoded[bodyStart])) {
            bodyStart++;
        }
    }
    decoded.erase(0, bodyStart);
    while (!decoded.empty() && iswspace(decoded.back())) {
        decoded.pop_back();
    }
    std::wstring result;
    result.reserve(decoded.size() + 32);
    for (size_t index = 0; index < decoded.size(); index++) {
        if (decoded[index] == L'\n' && (index == 0 || decoded[index - 1] != L'\r')) {
            result += L'\r';
        }
        result += decoded[index];
    }
    return result;
}

/// Retrieves the complete Unicode text of an information-window control.
static std::wstring InformationControlText(HWND control) {
    const int length = GetWindowTextLengthW(control);
    if (length <= 0) {
        return std::wstring{};
    }
    std::wstring text(static_cast<std::size_t>(length) + 1U, L'\0');
    GetWindowTextW(control, text.data(), length + 1);
    text.resize(static_cast<std::size_t>(length));
    return text;
}

/// Places Unicode information text on the clipboard with correct ownership transfer.
static bool CopyInformationTextToClipboard(HWND owner, const std::wstring& text) {
    if (text.empty() || !OpenClipboard(owner)) {
        return false;
    }
    EmptyClipboard();
    const SIZE_T size = (text.size() + 1U) * sizeof(wchar_t);
    HGLOBAL memory = GlobalAlloc(GMEM_MOVEABLE, size);
    if (!memory) {
        CloseClipboard();
        return false;
    }
    void* destination = GlobalLock(memory);
    if (!destination) {
        GlobalFree(memory);
        CloseClipboard();
        return false;
    }
    CopyMemory(destination, text.c_str(), size);
    GlobalUnlock(memory);
    if (!SetClipboardData(CF_UNICODETEXT, memory)) {
        GlobalFree(memory);
        CloseClipboard();
        return false;
    }
    CloseClipboard();
    return true;
}

/// Returns the executable's four-part product version, or a question mark if version information cannot be read.
static std::wstring GetApplicationVersion() {
    wchar_t path[MAX_PATH] = {};
    if (GetModuleFileNameW(nullptr, path, ARRAYSIZE(path)) == 0) {
        return L"?";
    }
    DWORD ignored = 0;
    DWORD size = GetFileVersionInfoSizeW(path, &ignored);
    if (size == 0) {
        return L"?";
    }
    std::vector<BYTE> data(size);
    if (!GetFileVersionInfoW(path, 0, size, data.data())) {
        return L"?";
    }
    VS_FIXEDFILEINFO* information = nullptr;
    UINT informationSize = 0;
    bool invalidVersionInfo =
        !VerQueryValueW(data.data(), L"\\", reinterpret_cast<void**>(&information), &informationSize)
        || information == nullptr
        || informationSize < sizeof(VS_FIXEDFILEINFO)
        || information->dwSignature != VS_FFI_SIGNATURE;
    if (invalidVersionInfo) {
        return L"?";
    }
    wchar_t version[48] = {};
    swprintf_s(version, L"%u.%u.%u.%u",
        HIWORD(information->dwProductVersionMS),
        LOWORD(information->dwProductVersionMS),
        HIWORD(information->dwProductVersionLS),
        LOWORD(information->dwProductVersionLS));
    return version;
}

/// Builds localized product information including description, version, copyright, and target platform.
static std::wstring AboutProductText(AppLanguage language) {
    std::wstring product = L"FlyingSolids\r\n";
    product += AboutDescriptionText(language);
    product += L"\r\n\r\n";
    product += AboutVersionLabel(language);
    product += L" ";
    product += GetApplicationVersion();
    product += L"\r\nCopyright © Petr Červinka – FortSoft 2026\r\n";
    product += AboutPlatformLabel(language);
    product += L" Win32 (x86)";
    return product;
}

/// Builds the SysLink markup for the product website.
static std::wstring AboutLinkText() {
    std::wstring link = L"<a href=\"";
    link += WEBSITE_URL;
    link += L"\">";
    link += WEBSITE_URL;
    link += L"</a>";
    return link;
}

/// Builds the plain-text About representation used by the copy command.
static std::wstring AboutClipboardText(AppLanguage language) {
    std::wstring text = AboutProductText(language);
    text += L"\r\n";
    text += AboutWebsiteLabel(language);
    text += L" ";
    text += WEBSITE_URL;
    return text;
}

/// Chooses a screen coordinate for pointer- or keyboard-invoked context menus.
static POINT InformationMenuPoint(HWND control, LPARAM lParam) {
    POINT point = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
    if (lParam == -1) {
        RECT rectangle = {};
        GetWindowRect(control, &rectangle);
        point.x = rectangle.left;
        point.y = rectangle.bottom;
    }
    return point;
}

/// Displays the localized context menu for About labels and website link.
static void ShowAboutContextMenu(HWND control, LPARAM lParam) {
    HWND parent = GetParent(control);
    InformationWindowData* data = reinterpret_cast<InformationWindowData*>(GetWindowLongPtrW(parent, DWLP_USER));
    if (!data) {
        return;
    }
    const int controlId = GetDlgCtrlID(control);
    HMENU menu = CreatePopupMenu();
    if (!menu) {
        return;
    }
    if (controlId == ID_INFORMATION_LINK) {
        AppendMenuW(menu, MF_STRING, ID_MENU_ABOUT_OPEN, OpenInBrowserText(data->language));
        AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
        AppendMenuW(menu, MF_STRING, ID_MENU_ABOUT_COPY_URL, CopyUrlText(data->language));
        AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    }
    AppendMenuW(menu, MF_STRING, ID_MENU_ABOUT_COPY_INFORMATION, CopyInformationText(data->language));
    const POINT point = InformationMenuPoint(control, lParam);
    const UINT command = TrackPopupMenu(menu, TPM_RETURNCMD | TPM_RIGHTBUTTON, point.x, point.y, 0, parent, nullptr);
    DestroyMenu(menu);
    if (command == ID_MENU_ABOUT_OPEN) {
        ShellExecuteW(parent, SHELL_OPEN_VERB, WEBSITE_URL, nullptr, nullptr, SW_SHOWNORMAL);
    } else if (command == ID_MENU_ABOUT_COPY_URL) {
        CopyInformationTextToClipboard(parent, WEBSITE_URL);
    } else if (command == ID_MENU_ABOUT_COPY_INFORMATION) {
        CopyInformationTextToClipboard(parent, AboutClipboardText(data->language));
    }
}

/// Adds a context menu to otherwise passive About controls.
static LRESULT CALLBACK AboutControlSubclass(HWND control, UINT msg, WPARAM wParam, LPARAM lParam, UINT_PTR, DWORD_PTR) {
    if (msg == WM_CONTEXTMENU) {
        ShowAboutContextMenu(control, lParam);
        return 0;
    }
    if (msg == WM_NCDESTROY) {
        RemoveWindowSubclass(control, AboutControlSubclass, ABOUT_CONTROL_SUBCLASS);
    }
    return DefSubclassProc(control, msg, wParam, lParam);
}

/// Measures unwrapped license text in the edit's current font and toggles the horizontal scrollbar only when needed.
/// Restores horizontal position to the start before hiding the bar; measurement also works while the bar is hidden.
static void UpdateAboutLicenseScrollBar(HWND window) {
    HDC dc = GetDC(window);
    if (dc == nullptr) {
        return;
    }
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(window, WM_GETFONT, 0, 0));
    HGDIOBJ previousFont = font == nullptr ? nullptr : SelectObject(dc, font);
    std::wstring text = InformationControlText(window);
    RECT textBounds = {};
    DrawTextW(dc, text.c_str(), static_cast<int>(text.size()), &textBounds, DT_CALCRECT | DT_NOPREFIX | DT_EXPANDTABS);
    if (previousFont != nullptr) {
        SelectObject(dc, previousFont);
    }
    ReleaseDC(window, dc);
    RECT format = {};
    SendMessageW(window, EM_GETRECT, 0, reinterpret_cast<LPARAM>(&format));
    bool needed = textBounds.right - textBounds.left > format.right - format.left;
    bool visible = (GetWindowLongPtrW(window, GWL_STYLE) & WS_HSCROLL) != 0;
    if (needed != visible) {
        if (!needed) {
            SendMessageW(window, WM_HSCROLL, SB_LEFT, 0);
        }
        ShowScrollBar(window, SB_HORZ, needed);
    }
}

/// Lets the information window handle Enter, Escape and Tab from its read-only text field. Updates the About license
/// horizontal scrollbar after native content or layout changes and removes the subclass on destruction.
static LRESULT CALLBACK InformationTextSubclassProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam,
        UINT_PTR subclassId, DWORD_PTR referenceData) {
    UNREFERENCED_PARAMETER(referenceData);
    if (msg == WM_GETDLGCODE) {
        LRESULT result = DefSubclassProc(window, msg, wParam, lParam);
        if (wParam == VK_RETURN || wParam == VK_ESCAPE || wParam == VK_TAB) {
            result &= ~DLGC_WANTALLKEYS;
        }
        return result;
    }
    bool updateLicenseScroll = GetParent(window) == aboutWindow
        && (msg == WM_SIZE || msg == WM_SETFONT || msg == WM_SETTEXT || msg == WM_THEMECHANGED);
    if (updateLicenseScroll) {
        LRESULT result = DefSubclassProc(window, msg, wParam, lParam);
        UpdateAboutLicenseScrollBar(window);
        return result;
    }
    if (msg == WM_NCDESTROY) {
        RemoveWindowSubclass(window, InformationTextSubclassProc, subclassId);
    }
    return DefSubclassProc(window, msg, wParam, lParam);
}

/// Returns the native combo box contained in a ComboBoxEx control, or the supplied window otherwise.
static HWND GetSettingsComboBox(HWND window) {
    wchar_t className[32] = {};
    GetClassNameW(window, className, ARRAYSIZE(className));
    if (_wcsicmp(className, WC_COMBOBOXEXW) == 0) {
        return reinterpret_cast<HWND>(SendMessageW(window, CBEM_GETCOMBOCONTROL, 0, 0));
    }
    return window;
}

/// Calculates the button text's client-relative top using native theme, glyph and font metrics.
static LONG GetSettingsButtonTextTop(HWND button, const WINDOWINFO& information, const TEXTMETRICW& metrics) {
    RECT content = {
        0,
        0,
        information.rcClient.right - information.rcClient.left,
        information.rcClient.bottom - information.rcClient.top
    };
    LONG textHeight = metrics.tmHeight;
    HTHEME theme = GetWindowTheme(button);
    if (theme == nullptr) {
        content.bottom -= GetSystemMetrics(SM_CYBORDER);
    } else {
        LONG_PTR type = GetWindowLongPtrW(button, GWL_STYLE) & BS_TYPEMASK;
        if (type == BS_PUSHBUTTON || type == BS_DEFPUSHBUTTON) {
            RECT themedContent = {};
            if (SUCCEEDED(GetThemeBackgroundContentRect(theme, nullptr, BP_PUSHBUTTON, PBS_NORMAL,
                &content, &themedContent))) {
                content = themedContent;
            }
        } else if (type == BS_CHECKBOX || type == BS_AUTOCHECKBOX || type == BS_3STATE || type == BS_AUTO3STATE) {
            SIZE glyph = {};
            if (SUCCEEDED(GetThemePartSize(theme, nullptr, BP_CHECKBOX, CBS_UNCHECKEDNORMAL, nullptr,
                TS_TRUE, &glyph))) {
                textHeight = std::max(textHeight, glyph.cy);
            }
        }
    }
    return content.top + (content.bottom - content.top - textHeight) / 2;
}

/// Calculates the vertical displacement needed to align control text with the reference baseline.
static LONG GetSettingsControlBaselineAdjustment(HWND control, HWND reference, LONG baselineDistance) {
    WINDOWINFO controlInfo = {};
    controlInfo.cbSize = sizeof(controlInfo);
    WINDOWINFO referenceInfo = {};
    referenceInfo.cbSize = sizeof(referenceInfo);
    if (control == nullptr
            || reference == nullptr
            || !GetWindowInfo(control, &controlInfo)
            || !GetWindowInfo(reference, &referenceInfo)) {
        return 0;
    }
    HDC dc = GetDC(control);
    if (dc == nullptr) {
        return 0;
    }
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(control, WM_GETFONT, 0, 0));
    HGDIOBJ previousFont = font == nullptr ? nullptr : SelectObject(dc, font);
    TEXTMETRICW metrics = {};
    bool measured = GetTextMetricsW(dc, &metrics) != FALSE;
    if (previousFont != nullptr && previousFont != HGDI_ERROR) {
        SelectObject(dc, previousFont);
    }
    ReleaseDC(control, dc);
    if (!measured) {
        return 0;
    }
    wchar_t className[32] = {};
    GetClassNameW(reference, className, ARRAYSIZE(className));
    LONG textTop = referenceInfo.rcClient.top;
    if (_wcsicmp(className, WC_COMBOBOXW) == 0 || _wcsicmp(className, WC_COMBOBOXEXW) == 0) {
        COMBOBOXINFO combo = {};
        combo.cbSize = sizeof(combo);
        if (!GetComboBoxInfo(GetSettingsComboBox(reference), &combo)) {
            return 0;
        }
        textTop += combo.rcItem.top + (combo.rcItem.bottom - combo.rcItem.top - metrics.tmHeight) / 2;
    } else if (_wcsicmp(className, L"EDIT") == 0) {
        RECT text = {};
        SendMessageW(reference, EM_GETRECT, 0, reinterpret_cast<LPARAM>(&text));
        textTop += text.top;
    } else if (_wcsicmp(className, L"BUTTON") == 0) {
        textTop += GetSettingsButtonTextTop(reference, referenceInfo, metrics);
    } else if (_wcsicmp(className, L"STATIC") == 0
            && (GetWindowLongPtrW(reference, GWL_STYLE) & SS_CENTERIMAGE) != 0) {
        textTop += (referenceInfo.rcClient.bottom - referenceInfo.rcClient.top - metrics.tmHeight) / 2;
    }
    wchar_t controlClass[32] = {};
    GetClassNameW(control, controlClass, ARRAYSIZE(controlClass));
    LONG controlTextTop = controlInfo.rcClient.top - controlInfo.rcWindow.top;
    if (_wcsicmp(controlClass, WC_COMBOBOXW) == 0 || _wcsicmp(controlClass, WC_COMBOBOXEXW) == 0) {
        COMBOBOXINFO combo = {};
        combo.cbSize = sizeof(combo);
        if (!GetComboBoxInfo(GetSettingsComboBox(control), &combo)) {
            return 0;
        }
        controlTextTop += combo.rcItem.top + (combo.rcItem.bottom - combo.rcItem.top - metrics.tmHeight) / 2;
    } else if (_wcsicmp(controlClass, L"EDIT") == 0) {
        RECT text = {};
        SendMessageW(control, EM_GETRECT, 0, reinterpret_cast<LPARAM>(&text));
        controlTextTop += text.top;
    } else if (_wcsicmp(controlClass, L"BUTTON") == 0) {
        controlTextTop += GetSettingsButtonTextTop(control, controlInfo, metrics);
    } else if (_wcsicmp(controlClass, L"STATIC") == 0 && (GetWindowLongPtrW(control, GWL_STYLE) & SS_CENTERIMAGE) != 0) {
        controlTextTop += (controlInfo.rcClient.bottom - controlInfo.rcClient.top - metrics.tmHeight) / 2;
    }
    return textTop + baselineDistance - controlTextTop - controlInfo.rcWindow.top;
}

/// Moves a control vertically without changing its size, activation or Z order.
static void OffsetSettingsControl(HWND control, LONG distance) {
    RECT bounds = {};
    if (distance == 0 || control == nullptr || !GetWindowRect(control, &bounds)) {
        return;
    }
    POINT position = { bounds.left, bounds.top + distance };
    ScreenToClient(GetParent(control), &position);
    SetWindowPos(control, nullptr, position.x, position.y, 0, 0,
        SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_NOCOPYBITS);
}

/// Aligns a control's text baseline with the reference, allowing an explicit baseline distance.
static void AlignSettingsControl(HWND control, HWND reference, LONG baselineDistance) {
    OffsetSettingsControl(control, GetSettingsControlBaselineAdjustment(control, reference, baselineDistance));
}

/// Derives text-line metrics from the selected font and glyph extents without clipping the supplied text.
static UiTextLine GetUiTextLine(HDC dc, const std::wstring& text) {
    TEXTMETRICW metrics = {};
    GetTextMetricsW(dc, &metrics);
    UiTextLine line = { metrics.tmAscent, metrics.tmDescent, metrics.tmExternalLeading };
    UINT size = GetOutlineTextMetricsW(dc, 0, nullptr);
    if (size == 0) {
        return line;
    }
    std::vector<BYTE> data(size);
    OUTLINETEXTMETRICW* outline = reinterpret_cast<OUTLINETEXTMETRICW*>(data.data());
    if (GetOutlineTextMetricsW(dc, size, outline) == 0) {
        return line;
    }
    UiTextLine typographic = {
        outline->otmAscent, std::abs(outline->otmDescent),
        static_cast<LONG>(outline->otmLineGap)
    };
    MAT2 transform = {
        FIXED{ 0, 1 },
        FIXED{ 0, 0 },
        FIXED{ 0, 0 },
        FIXED{ 0, 1 }
    };
    for (wchar_t character : text) {
        if (iswspace(character)) {
            continue;
        }
        GLYPHMETRICS glyph = {};
        if (GetGlyphOutlineW(dc, character, GGO_METRICS, &glyph, 0, nullptr, &transform) != GDI_ERROR) {
            typographic.ascent = std::max(typographic.ascent, glyph.gmptGlyphOrigin.y);
            typographic.descent = std::max(typographic.descent,
                static_cast<LONG>(glyph.gmBlackBoxY) - glyph.gmptGlyphOrigin.y);
        }
    }
    if (typographic.ascent + typographic.descent + typographic.gap < metrics.tmHeight + metrics.tmExternalLeading) {
        line = typographic;
    }
    return line;
}

/// Removes mnemonic markers from a caption while preserving escaped ampersands.
static std::wstring RemoveCaptionMnemonic(const std::wstring& caption) {
    std::wstring text;
    for (size_t index = 0; index < caption.size(); index++) {
        if (caption[index] != L'&') {
            text += caption[index];
        } else if (index + 1 < caption.size() && caption[index + 1] == L'&') {
            text += L'&';
            index++;
        }
    }
    return text;
}

/// Draws or measures word-wrapped text with explicit line breaks and typographic line spacing.
static int DrawWordWrappedText(HDC dc, const std::wstring& text, const RECT& bounds, UINT prefix = DT_NOPREFIX) {
    TEXTMETRICW metrics = {};
    if (!GetTextMetricsW(dc, &metrics)) {
        return 0;
    }
    UiTextLine layout = GetUiTextLine(dc, text);
    int lineHeight = std::max(1L, layout.ascent + layout.descent + layout.gap);
    bool measure = (prefix & DT_CALCRECT) != 0;
    int saved = SaveDC(dc);
    if (!measure) {
        IntersectClipRect(dc, bounds.left, bounds.top, bounds.right, bounds.bottom);
    }
    int maximumWidth = bounds.right - bounds.left;
    int y = bounds.top;
    size_t position = 0;
    std::wstring line;
    while (position < text.size() && (measure || y < bounds.bottom)) {
        if (text[position] == L'\r' || text[position] == L'\n') {
            if (!measure && !line.empty()) {
                RECT lineRect = {
                    bounds.left,
                    y + layout.ascent - metrics.tmAscent,
                    bounds.right,
                    y + layout.ascent + metrics.tmDescent
                };
                DrawTextW(dc, line.c_str(), -1, &lineRect, DT_LEFT | DT_TOP | DT_SINGLELINE | prefix);
            }
            line.clear();
            wchar_t newline = text[position++];
            if (position < text.size() && newline == L'\r' && text[position] == L'\n') {
                position++;
            }
            y += lineHeight;
            continue;
        }
        while (position < text.size() && iswspace(text[position]) && text[position] != L'\r' && text[position] != L'\n') {
            position++;
        }
        size_t wordStart = position;
        while (position < text.size() && !iswspace(text[position])) {
            position++;
        }
        if (wordStart == position) {
            continue;
        }
        std::wstring word = text.substr(wordStart, position - wordStart);
        std::wstring candidate = line.empty() ? word : line + L" " + word;
        SIZE extent = {};
        std::wstring measured = prefix & DT_NOPREFIX ? candidate : RemoveCaptionMnemonic(candidate);
        GetTextExtentPoint32W(dc, measured.c_str(), static_cast<int>(measured.size()), &extent);
        if (!line.empty() && extent.cx > maximumWidth) {
            if (!measure) {
                RECT lineRect = {
                    bounds.left,
                    y + layout.ascent - metrics.tmAscent,
                    bounds.right,
                    y + layout.ascent + metrics.tmDescent
                };
                DrawTextW(dc, line.c_str(), -1, &lineRect, DT_LEFT | DT_TOP | DT_SINGLELINE | prefix);
            }
            y += lineHeight;
            line = word;
        } else {
            line = candidate;
        }
    }
    if (!line.empty() && (measure || y < bounds.bottom)) {
        if (!measure) {
            RECT lineRect = {
                bounds.left,
                y + layout.ascent - metrics.tmAscent,
                bounds.right,
                y + layout.ascent + metrics.tmDescent
            };
            DrawTextW(dc, line.c_str(), -1, &lineRect, DT_LEFT | DT_TOP | DT_SINGLELINE | prefix);
        }
        y += lineHeight;
    }
    RestoreDC(dc, saved);
    return y - bounds.top;
}

/// Paints owner-drawn product text using the control font, enabled-state color and parent background.
static INT_PTR DrawWrappedTextItem(const DRAWITEMSTRUCT* item) {
    int savedState = SaveDC(item->hDC);
    DrawThemeParentBackground(item->hwndItem, item->hDC, nullptr);
    SetBkMode(item->hDC, TRANSPARENT);
    SetTextColor(item->hDC, GetSysColor(IsWindowEnabled(item->hwndItem) ? COLOR_WINDOWTEXT : COLOR_GRAYTEXT));
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(item->hwndItem, WM_GETFONT, 0, 0));
    if (font != nullptr) {
        SelectObject(item->hDC, font);
    }
    std::wstring text = InformationControlText(item->hwndItem);
    RECT textRect = item->rcItem;
    UINT prefix = DT_NOPREFIX;
    DrawWordWrappedText(item->hDC, text, textRect, prefix);
    RestoreDC(item->hDC, savedState);
    return TRUE;
}

/// Creates a nonactivating tooltip for a child control, destroying it if registration fails.
static HWND CreateControlTooltip(HWND parent, HWND control, const wchar_t* text) {
    if (parent == nullptr || control == nullptr || text == nullptr) {
        return nullptr;
    }
    HWND tooltip = CreateWindowExW(WS_EX_TOPMOST | WS_EX_NOACTIVATE, TOOLTIPS_CLASSW,
        nullptr, WS_POPUP | TTS_ALWAYSTIP | TTS_NOPREFIX, CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT, parent, nullptr, app->instance, nullptr);
    if (tooltip == nullptr) {
        return nullptr;
    }
    TOOLINFOW information = {};
    information.cbSize = sizeof(information);
    information.uFlags = TTF_IDISHWND | TTF_SUBCLASS;
    information.hwnd = parent;
    information.uId = reinterpret_cast<UINT_PTR>(control);
    information.lpszText = const_cast<wchar_t*>(text);
    if (!SendMessageW(tooltip, TTM_ADDTOOLW, 0, reinterpret_cast<LPARAM>(&information))) {
        DestroyWindow(tooltip);
        return nullptr;
    }
    return tooltip;
}

/// Returns a dialog child's window rectangle mapped to its parent's client coordinates.
static RECT InformationControlRect(HWND window, int id) {
    RECT rect = {};
    GetWindowRect(GetDlgItem(window, id), &rect);
    MapWindowPoints(HWND_DESKTOP, window, reinterpret_cast<POINT*>(&rect), 2);
    return rect;
}

/// Captures initial Help or About control rectangles for subsequent anchored layout calculations.
static void InitializeInformationWindowLayout(HWND window, bool help) {
    InformationWindowLayout& layout = help ? helpWindowLayout : aboutWindowLayout;
    RECT client = {};
    GetClientRect(window, &client);
    layout.client = SIZE{ client.right, client.bottom };
    layout.text = InformationControlRect(window, ID_INFORMATION_TEXT);
    layout.close = InformationControlRect(window, ID_INFORMATION_CLOSE);
    if (!help) {
        layout.product = InformationControlRect(window, ID_INFORMATION_PRODUCT);
        layout.website = InformationControlRect(window, ID_INFORMATION_WEBSITE);
        layout.link = InformationControlRect(window, ID_INFORMATION_LINK);
    }
    layout.initialized = true;
}

/// Positions an information-window child without activation or Z-order changes, enforcing positive dimensions.
static void PlaceInformationControl(HWND window, int id, int x, int y, int width, int height) {
    HWND control = GetDlgItem(window, id);
    int controlWidth = std::max(1, width);
    int controlHeight = std::max(1, height);
    UINT flags = SWP_NOZORDER | SWP_NOACTIVATE;
    SetWindowPos(control, nullptr, x, y, controlWidth, controlHeight, flags);
}

/// Measures a label's wrapped height at the requested width using its actual font, or returns zero if a DC is
/// unavailable.
static int InformationLabelHeight(HWND control, int width) {
    HDC dc = GetDC(control);
    if (dc == nullptr) {
        return 0;
    }
    std::wstring text = InformationControlText(control);
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(control, WM_GETFONT, 0, 0));
    HGDIOBJ oldFont = font == nullptr ? nullptr : SelectObject(dc, font);
    RECT bounds = { 0, 0, std::max(1, width), 0 };
    int height = DrawWordWrappedText(dc, text, bounds, DT_CALCRECT | DT_NOPREFIX);
    if (oldFont != nullptr) {
        SelectObject(dc, oldFont);
    }
    ReleaseDC(control, dc);
    return height;
}

/// Measures unwrapped control text using its current font, returning zero dimensions if no DC is available.
static SIZE InformationTextSize(HWND control) {
    SIZE size = {};
    HDC dc = GetDC(control);
    if (dc != nullptr) {
        HFONT font = reinterpret_cast<HFONT>(SendMessageW(control, WM_GETFONT, 0, 0));
        HGDIOBJ previous = font == nullptr ? nullptr : SelectObject(dc, font);
        std::wstring text = InformationControlText(control);
        GetTextExtentPoint32W(dc, text.c_str(), static_cast<int>(text.size()), &size);
        if (previous != nullptr) {
            SelectObject(dc, previous);
        }
        ReleaseDC(control, dc);
    }
    return size;
}

/// Lays out About controls with measured product and website text, optionally resizing within the work area.
static void LayoutAboutWindow(HWND window, bool resize) {
    const InformationWindowLayout& layout = aboutWindowLayout;
    HWND website = GetDlgItem(window, ID_INFORMATION_WEBSITE);
    HWND link = GetDlgItem(window, ID_INFORMATION_LINK);
    SIZE websiteSize = InformationTextSize(website);
    SIZE linkSize = {};
    SendMessageW(link, LM_GETIDEALSIZE, 0, reinterpret_cast<LPARAM>(&linkSize));
    RECT spacing = { 0, 0, 4, ABOUT_WEB_GAP_DLU };
    MapDialogRect(window, &spacing);
    int margin = layout.text.left;
    int rightMargin = layout.client.cx - layout.text.right;
    int bottomMargin = layout.client.cy - layout.close.bottom;
    int buttonWidth = layout.close.right - layout.close.left;
    int buttonHeight = layout.close.bottom - layout.close.top;
    int productGap = spacing.bottom;
    int textGap = layout.text.top - std::max(layout.website.bottom, layout.link.bottom);
    int buttonGap = layout.close.top - layout.text.bottom;
    RECT client = {};
    GetClientRect(window, &client);
    if (resize) {
        client.right =
            std::max(layout.client.cx, layout.website.left + websiteSize.cx + spacing.right + linkSize.cx + rightMargin);
        RECT frame = {};
        DWORD style = static_cast<DWORD>(GetWindowLongPtrW(window, GWL_STYLE));
        DWORD extendedStyle = static_cast<DWORD>(GetWindowLongPtrW(window, GWL_EXSTYLE));
        AdjustWindowRectEx(&frame, style, FALSE, extendedStyle);
        MONITORINFO monitor = { sizeof(monitor) };
        GetMonitorInfoW(MonitorFromWindow(window, MONITOR_DEFAULTTONEAREST), &monitor);
        client.right = std::min(client.right, monitor.rcWork.right - monitor.rcWork.left - frame.right + frame.left);
        client.bottom =
            std::min(layout.client.cy, monitor.rcWork.bottom - monitor.rcWork.top - frame.bottom + frame.top);
        RECT bounds = {};
        GetWindowRect(window, &bounds);
        int width = client.right + frame.right - frame.left;
        int height = client.bottom + frame.bottom - frame.top;
        if (width != bounds.right - bounds.left || height != bounds.bottom - bounds.top) {
            SetWindowPos(window, nullptr, 0, 0, width, height, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
        }
        GetClientRect(window, &client);
    }
    int right = client.right - rightMargin;
    int productWidth = right - layout.product.left;
    int productHeight = InformationLabelHeight(GetDlgItem(window, ID_INFORMATION_PRODUCT), productWidth);
    int websiteY = layout.product.top + productHeight + productGap;
    int linkX = layout.website.left + websiteSize.cx + spacing.right;
    PlaceInformationControl(window, ID_INFORMATION_PRODUCT, layout.product.left, layout.product.top, productWidth,
        productHeight);
    PlaceInformationControl(window, ID_INFORMATION_WEBSITE, layout.website.left, websiteY, websiteSize.cx, websiteSize.cy);
    PlaceInformationControl(window, ID_INFORMATION_LINK, linkX, websiteY, right - linkX, linkSize.cy);
    AlignSettingsControl(link, website);
    RECT websiteBounds = InformationControlRect(window, ID_INFORMATION_WEBSITE);
    RECT linkBounds = InformationControlRect(window, ID_INFORMATION_LINK);
    int textTop = std::max(websiteBounds.bottom, linkBounds.bottom) + textGap;
    int buttonY = client.bottom - bottomMargin - buttonHeight;
    PlaceInformationControl(window, ID_INFORMATION_TEXT, margin, textTop, right - margin, buttonY - buttonGap - textTop);
    SetWindowPos(GetDlgItem(window, ID_INFORMATION_CLOSE), HWND_TOP, right - buttonWidth, buttonY, buttonWidth,
        buttonHeight, SWP_NOACTIVATE);
    InvalidateRect(window, nullptr, TRUE);
}

/// Updates the Help or About layout while preserving the original control sizes and edge spacing.
static void LayoutInformationWindow(HWND window, bool resizeAbout = false) {
    InformationWindowLayout& layout = window == helpWindow ? helpWindowLayout : aboutWindowLayout;
    if (!layout.initialized || IsIconic(window)) {
        return;
    }
    if (window == aboutWindow) {
        LayoutAboutWindow(window, resizeAbout);
        return;
    }
    RECT client = {};
    GetClientRect(window, &client);
    int right = client.right - layout.client.cx + layout.text.right;
    int buttonWidth = layout.close.right - layout.close.left;
    int buttonHeight = layout.close.bottom - layout.close.top;
    int buttonX = client.right - layout.client.cx + layout.close.left;
    int buttonY = client.bottom - layout.client.cy + layout.close.top;
    int buttonGap = layout.close.top - layout.text.bottom;
    int textHeight = buttonY - buttonGap - layout.text.top;
    PlaceInformationControl(window, ID_INFORMATION_TEXT, layout.text.left, layout.text.top, right - layout.text.left,
        textHeight);
    SetWindowPos(GetDlgItem(window, ID_INFORMATION_CLOSE), HWND_TOP, buttonX, buttonY, buttonWidth, buttonHeight,
        SWP_NOACTIVATE);
    int gripWidth = GetSystemMetrics(SM_CXVSCROLL);
    int gripHeight = GetSystemMetrics(SM_CYHSCROLL);
    UINT flags = SWP_NOZORDER | SWP_NOACTIVATE;
    if (IsZoomed(window)) {
        flags |= SWP_HIDEWINDOW;
    } else {
        flags |= SWP_SHOWWINDOW;
    }
    SetWindowPos(GetDlgItem(window, ID_INFORMATION_SIZE_GRIP), nullptr, client.right - gripWidth,
        client.bottom - gripHeight, gripWidth, gripHeight, flags);
}

/// Refreshes localized content and geometry of one information window.
static void RefreshInformationWindow(HWND window, InformationWindowData& data) {
    const std::wstring title = data.help
        ? HelpButtonText(data.language)
        : std::wstring(AboutButtonText(data.language)) + L" FlyingSolids";
    SetWindowTextW(window, title.c_str());
    std::vector<wchar_t> usedMnemonics;
    const std::wstring closeCaption = UniqueMnemonic(CloseButtonText(data.language), usedMnemonics);
    SetDlgItemTextW(window, ID_INFORMATION_CLOSE, closeCaption.c_str());
    if (data.help) {
        SetDlgItemTextW(window, ID_INFORMATION_TEXT, HelpBodyText(data.language, data.appMode));
    } else {
        const std::wstring product = AboutProductText(data.language);
        const std::wstring link = AboutLinkText();
        SetDlgItemTextW(window, ID_INFORMATION_PRODUCT, product.c_str());
        SetDlgItemTextW(window, ID_INFORMATION_WEBSITE, AboutWebsiteLabel(data.language));
        SetDlgItemTextW(window, ID_INFORMATION_LINK, link.c_str());
    }
    LayoutInformationWindow(window, !data.help);
    if (!data.help && aboutTooltip != nullptr) {
        SendMessageW(aboutTooltip, TTM_UPDATE, 0, 0);
    }
}

/// Handles mouse or keyboard activation of the website link in an information window.
static bool HandleInformationNotification(HWND window, LPARAM lParam) {
    const NMHDR* header = reinterpret_cast<const NMHDR*>(lParam);
    if (header) {
        if (header->hwndFrom == aboutTooltip && header->code == TTN_GETDISPINFOW) {
            const InformationWindowData* data =
                reinterpret_cast<const InformationWindowData*>(GetWindowLongPtrW(window, DWLP_USER));
            if (data != nullptr) {
                NMTTDISPINFOW* information = reinterpret_cast<NMTTDISPINFOW*>(lParam);
                information->lpszText = const_cast<wchar_t*>(AboutVisitTooltipText(data->language));
            }
            return true;
        }
        if (header->idFrom == ID_INFORMATION_LINK && (header->code == NM_CLICK || header->code == NM_RETURN)) {
            ShellExecuteW(window, SHELL_OPEN_VERB, WEBSITE_URL, nullptr, nullptr, SW_SHOWNORMAL);
            return true;
        }
    }
    return false;
}

/// Positions an information window at the system-selected default location without resizing or activation.
static bool PositionInformationWindowByWindowsDefault(HWND window) {
    RECT bounds = {};
    if (!GetWindowRect(window, &bounds)) {
        return false;
    }
    HWND positionWindow = CreateWindowExW(0, L"STATIC", L"", WS_OVERLAPPED, CW_USEDEFAULT, CW_USEDEFAULT,
        bounds.right - bounds.left, bounds.bottom - bounds.top, nullptr, nullptr, app->instance, nullptr);
    if (positionWindow == nullptr) {
        return false;
    }
    bool positioned = GetWindowRect(positionWindow, &bounds) != FALSE;
    DestroyWindow(positionWindow);
    if (!positioned) {
        return false;
    }
    return SetWindowPos(window, nullptr, bounds.left, bounds.top, 0, 0,
        SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE) != FALSE;
}

/// Captures the form's screen position, using and translating its normal placement when minimized.
static void SaveFormPosition(HWND window, int* x, int* y) {
    if (window == nullptr) {
        return;
    }
    RECT rect{};
    if (IsIconic(window)) {
        WINDOWPLACEMENT placement{};
        placement.length = sizeof(placement);
        if (!GetWindowPlacement(window, &placement)) {
            return;
        }
        rect = placement.rcNormalPosition;
        const bool toolWindow = GetWindowLongPtrW(window, GWL_EXSTYLE) & WS_EX_TOOLWINDOW;
        if (!toolWindow) {
            const HMONITOR monitor = MonitorFromWindow(window, MONITOR_DEFAULTTONEAREST);
            MONITORINFO information{};
            information.cbSize = sizeof(information);
            if (!GetMonitorInfoW(monitor, &information)) {
                return;
            }
            OffsetRect(&rect, information.rcWork.left - information.rcMonitor.left,
                information.rcWork.top - information.rcMonitor.top);
        }
    } else if (!GetWindowRect(window, &rect)) {
        return;
    }
    *x = rect.left;
    *y = rect.top;
}

/// Remembers an initialized information window without committing pending animation preferences.
static void SaveInformationWindowPosition(HWND window, const InformationWindowData* data) {
    if (!data || !data->initialized || !data->settings) {
        return;
    }
    PersistWindowState& placement = data->help ? helpWindowState : aboutWindowState;
    PersistWindowStateData& saved = data->help ? data->settings->helpWindowState : data->settings->aboutWindowState;
    saved = placement.Save();
    data->settings->SaveWindowPositions();
}

/// Releases the fonts owned by one information window and clears their handles.
static void DestroyInformationWindowFonts(InformationWindowData& data) {
    if (data.licenseFont) {
        DeleteObject(data.licenseFont);
        data.licenseFont = nullptr;
    }
}

/// Creates Help or About controls after the parent handle is stored, matching CalClock initialization order.
static bool CreateInformationControls(HWND window, InformationWindowData& data) {
    HWND text = GetDlgItem(window, ID_INFORMATION_TEXT);
    if (!InstallSelectionEditHandler(text)) {
        return false;
    }
    SendMessageW(window, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(app->programIcons.Large()));
    SendMessageW(window, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(app->programIcons.Small()));
    SetWindowSubclass(text, InformationTextSubclassProc, INFORMATION_TEXT_SUBCLASS_ID, 0);
    if (!data.help) {
        HWND icon = GetDlgItem(window, ID_INFORMATION_ICON);
        int iconSize = ABOUT_ICON_SIZE;
        HDC screen = GetDC(window);
        if (screen != nullptr) {
            if (GetDeviceCaps(screen, LOGPIXELSY) >= ABOUT_LARGE_ICON_DPI) {
                iconSize = ABOUT_LARGE_ICON_SIZE;
            }
            ReleaseDC(window, screen);
        }
        SendMessageW(icon, STM_SETICON, reinterpret_cast<WPARAM>(app->programIcons.Large()), 0);
        SetWindowPos(icon, nullptr, 0, 0, iconSize, iconSize, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
        HWND product = GetDlgItem(window, ID_INFORMATION_PRODUCT);
        HWND website = GetDlgItem(window, ID_INFORMATION_WEBSITE);
        HWND link = GetDlgItem(window, ID_INFORMATION_LINK);
        SetWindowSubclass(product, AboutControlSubclass, ABOUT_CONTROL_SUBCLASS, 0);
        SetWindowSubclass(website, AboutControlSubclass, ABOUT_CONTROL_SUBCLASS, 0);
        SetWindowSubclass(link, AboutControlSubclass, ABOUT_CONTROL_SUBCLASS, 0);
        aboutTooltip = CreateControlTooltip(window, link, LPSTR_TEXTCALLBACKW);
        data.licenseFont = CreateAboutFont();
        if (data.licenseFont != nullptr) {
            SendMessageW(text, WM_SETFONT, reinterpret_cast<WPARAM>(data.licenseFont), FALSE);
        }
        SetWindowTextW(text, LoadLicenseText().c_str());
    }
    RefreshInformationWindow(window, data);
    SendMessageW(text, EM_SETSEL, 0, 0);
    return true;
}

/// Handles lifetime, commands and keyboard interaction of Help and About windows.
static LRESULT CALLBACK InformationProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam) {
    InformationWindowData* data = reinterpret_cast<InformationWindowData*>(GetWindowLongPtrW(window, DWLP_USER));
    switch (msg) {
        case WM_SIZE:
            if (wParam != SIZE_MINIMIZED) {
                LayoutInformationWindow(window);
            }
            return 0;
        case WM_DRAWITEM:
            return DrawWrappedTextItem(reinterpret_cast<const DRAWITEMSTRUCT*>(lParam));
        case WM_COMMAND:
            if (LOWORD(wParam) == ID_INFORMATION_CLOSE || LOWORD(wParam) == IDCANCEL) {
                SendMessageW(window, WM_CLOSE, 0, 0);
            }
            return 0;
        case WM_NOTIFY:
            HandleInformationNotification(window, lParam);
            return 0;
        case WM_SYSCOMMAND:
            if ((wParam & 0xFFF0) == SC_SCREENSAVE && ShouldInhibitScreenSaver()) {
                return 0;
            }
            if ((wParam & 0xFFF0) == SC_MINIMIZE) {
                SaveInformationWindowPosition(window, data);
            }
            break;
        case WM_EXITSIZEMOVE:
        case WM_DESTROY:
            SaveInformationWindowPosition(window, data);
            return 0;
        case WM_CLOSE:
            DestroyWindow(window);
            return 0;
        case WM_NCDESTROY:
            if (window == helpWindow) {
                helpWindow = nullptr;
            }
            if (window == aboutWindow) {
                aboutWindow = nullptr;
                if (aboutTooltip != nullptr) {
                    DestroyWindow(aboutTooltip);
                    aboutTooltip = nullptr;
                }
            }
            if (data != nullptr) {
                DestroyInformationWindowFonts(*data);
                if (data->initialized) {
                    delete data;
                }
                SetWindowLongPtrW(window, DWLP_USER, 0);
            }
            return 0;
    }
    return DefWindowProcW(window, msg, wParam, lParam);
}

/// Routes dialog lifecycle, commands, drawing and notifications to the shared information-window handler.
static INT_PTR CALLBACK InformationDialogProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (msg == WM_INITDIALOG) {
        SetWindowLongPtrW(window, DWLP_USER, lParam);
        return TRUE;
    }
    if (msg == WM_DESTROY || msg == WM_NCDESTROY || msg == WM_EXITSIZEMOVE) {
        InformationProc(window, msg, wParam, lParam);
        return FALSE;
    }
    if (msg == WM_SYSCOMMAND && (wParam & 0xFFF0) == SC_SCREENSAVE && ShouldInhibitScreenSaver()) {
        return TRUE;
    }
    if (msg == WM_SYSCOMMAND && (wParam & 0xFFF0) == SC_MINIMIZE) {
        const InformationWindowData* data =
            reinterpret_cast<const InformationWindowData*>(GetWindowLongPtrW(window, DWLP_USER));
        SaveInformationWindowPosition(window, data);
    }
    if (msg == WM_CLOSE
            || msg == WM_COMMAND && (LOWORD(wParam) == ID_INFORMATION_CLOSE || LOWORD(wParam) == IDCANCEL)
            || msg == WM_SIZE && wParam != SIZE_MINIMIZED) {
        InformationProc(window, msg, wParam, lParam);
        return TRUE;
    }
    if (msg == WM_DRAWITEM && wParam == ID_INFORMATION_PRODUCT) {
        return InformationProc(window, msg, wParam, lParam);
    }
    if (msg == WM_NOTIFY) {
        NMHDR* notification = reinterpret_cast<NMHDR*>(lParam);
        bool tooltip = notification->hwndFrom == aboutTooltip && notification->code == TTN_GETDISPINFOW;
        bool website = notification->idFrom == ID_INFORMATION_LINK
            && (notification->code == NM_CLICK || notification->code == NM_RETURN);
        if (tooltip || website) {
            SetWindowLongPtrW(window, DWLP_MSGRESULT, InformationProc(window, msg, wParam, lParam));
            return TRUE;
        }
    }
    if (msg == WM_THEMECHANGED || msg == WM_SETTINGCHANGE) {
        LayoutInformationWindow(window, true);
    }
    return FALSE;
}

/// Relocalizes all currently open information and recording-settings windows.
static void RefreshInformationWindows(AppLanguage language, bool appMode) {
    const HWND windows[]{ helpWindow, aboutWindow };
    for (HWND window : windows) {
        if (!window || !IsWindow(window)) {
            continue;
        }
        InformationWindowData* data = reinterpret_cast<InformationWindowData*>(GetWindowLongPtrW(window, DWLP_USER));
        if (!data) {
            continue;
        }
        data->language = language;
        data->appMode = appMode;
        RefreshInformationWindow(window, *data);
    }
    if (recordingSettingsWindow && IsWindow(recordingSettingsWindow)) {
        RecordingWindowData* data =
            reinterpret_cast<RecordingWindowData*>(GetWindowLongPtrW(recordingSettingsWindow, DWLP_USER));
        if (data) {
            data->language = language;
            RefreshRecordingSettingsWindow(recordingSettingsWindow, *data);
        }
    }
}

/// Restores and activates a valid window, temporarily attaching input queues when the foreground thread differs.
static bool SetForegroundWindowEx(HWND window) {
    if (window == nullptr || !IsWindow(window)) {
        return false;
    }
    DWORD currentThread = GetCurrentThreadId();
    DWORD foregroundThread = GetWindowThreadProcessId(GetForegroundWindow(), nullptr);
    if (foregroundThread != 0 && foregroundThread != currentThread) {
        AttachThreadInput(currentThread, foregroundThread, TRUE);
    }
    ShowWindow(window, SW_SHOWNORMAL);
    BringWindowToTop(window);
    bool result = SetForegroundWindow(window) != FALSE;
    if (foregroundThread != 0 && foregroundThread != currentThread) {
        AttachThreadInput(currentThread, foregroundThread, FALSE);
    }
    return result;
}

/// Keeps a saved form position inside the nearest monitor's work area without changing default placement.
static void ClampFormPosition(int* x, int* y, int width, int height) {
    if (*x == CW_USEDEFAULT || *y == CW_USEDEFAULT) {
        return;
    }
    RECT desired = { *x, *y, *x + width, *y + height };
    HMONITOR monitor = MonitorFromRect(&desired, MONITOR_DEFAULTTONEAREST);
    MONITORINFO information = {};
    information.cbSize = sizeof(information);
    if (monitor == nullptr || !GetMonitorInfoW(monitor, &information)) {
        return;
    }
    int workLeft = static_cast<int>(information.rcWork.left);
    int workTop = static_cast<int>(information.rcWork.top);
    int workRight = static_cast<int>(information.rcWork.right);
    int workBottom = static_cast<int>(information.rcWork.bottom);
    *x = std::clamp(*x, workLeft, std::max(workLeft, workRight - width));
    *y = std::clamp(*y, workTop, std::max(workTop, workBottom - height));
}

/// Closes independent information and recording-settings windows before their settings storage is released.
static void CloseInformationWindows() {
    if (helpWindow != nullptr) {
        SendMessageW(helpWindow, WM_CLOSE, 0, 0);
    }
    if (aboutWindow != nullptr) {
        SendMessageW(aboutWindow, WM_CLOSE, 0, 0);
    }
    if (recordingSettingsWindow != nullptr) {
        SendMessageW(recordingSettingsWindow, WM_CLOSE, 0, 0);
    }
}

/// Keeps independent information and recording-settings windows synchronized with the settings form's topmost policy.
static void UpdateInformationWindowsTopmost(HWND settingsWindow) {
    HWND position = HWND_NOTOPMOST;
    if ((GetWindowLongPtrW(settingsWindow, GWL_EXSTYLE) & WS_EX_TOPMOST) != 0) {
        position = HWND_TOPMOST;
    }
    const HWND windows[]{ helpWindow, aboutWindow, recordingSettingsWindow };
    for (HWND window : windows) {
        if (window != nullptr) {
            SetWindowPos(window, position, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
        }
    }
}

/// Reports whether a visible standalone form overlaps any visible animation surface.
static bool AnimationOverlapsControlWindow(HWND window) {
    if (!app || !IsWindowVisible(window) || IsIconic(window)) {
        return false;
    }
    RECT controlBounds{};
    if (!GetWindowRect(window, &controlBounds)) {
        return false;
    }
    for (const std::unique_ptr<RenderSurface>& surface : app->surfaces) {
        if (!surface->window || !IsWindowVisible(surface->window) || IsIconic(surface->window)) {
            continue;
        }
        RECT animationBounds{};
        RECT overlap{};
        if (GetWindowRect(surface->window, &animationBounds)
                && IntersectRect(&overlap, &controlBounds, &animationBounds)) {
            return true;
        }
    }
    return false;
}

/// Keeps only an animation-overlapped standalone form and its information windows topmost.
static void UpdateControlWindowTopmost(HWND window) {
    if (!app || app->mode != RunMode::Application || !window || window != app->controlWindow) {
        return;
    }
    const bool required = AnimationOverlapsControlWindow(window);
    const bool topmost = (GetWindowLongPtrW(window, GWL_EXSTYLE) & WS_EX_TOPMOST) != 0;
    if (required == topmost) {
        return;
    }
    HWND position = HWND_NOTOPMOST;
    if (required) {
        position = HWND_TOPMOST;
    }
    SetWindowPos(window, position, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
    UpdateInformationWindowsTopmost(window);
}

/// Creates or activates Help or About with saved placement, independent taskbar presence and anchored layout.
static void ShowInformationWindow(HWND owner, bool help, AppLanguage language, bool appMode) {
    HWND& target = help ? helpWindow : aboutWindow;
    PersistWindowState& placement = help ? helpWindowState : aboutWindowState;
    if (target != nullptr && IsWindow(target)) {
        placement.BringToFront();
        return;
    }
    const SettingsWindowData* settingsData =
        reinterpret_cast<const SettingsWindowData*>(GetWindowLongPtrW(owner, GWLP_USERDATA));
    if (settingsData == nullptr || settingsData->settings == nullptr) {
        return;
    }
    InformationWindowLayout& layout = help ? helpWindowLayout : aboutWindowLayout;
    layout = {};
    placement.Load(help ? settingsData->settings->helpWindowState : settingsData->settings->aboutWindowState);
    std::unique_ptr<InformationWindowData> data = std::make_unique<InformationWindowData>();
    data->settings = settingsData->settings;
    data->help = help;
    data->appMode = appMode;
    data->language = language;
    const int resource = help ? IDD_HELP : IDD_ABOUT;
    target = CreateDialogParamW(app->instance, MAKEINTRESOURCEW(resource), nullptr, InformationDialogProc,
        reinterpret_cast<LPARAM>(data.get()));
    if (target == nullptr) {
        return;
    }
    if (!CreateInformationControls(target, *data)) {
        DestroyWindow(target);
        target = nullptr;
        return;
    }
    data->initialized = true;
    data.release();
    InitializeInformationWindowLayout(target, help);
    LayoutInformationWindow(target, true);
    const PersistWindowStateData& savedPlacement = placement.GetState();
    const bool defaultPosition = savedPlacement.x == CW_USEDEFAULT || savedPlacement.y == CW_USEDEFAULT;
    if (defaultPosition && !PositionInformationWindowByWindowsDefault(target) || !placement.Attach(target)) {
        DestroyWindow(target);
        target = nullptr;
        return;
    }
    LayoutInformationWindow(target);
    UpdateInformationWindowsTopmost(owner);
    const int focusId = help ? ID_INFORMATION_TEXT : ID_INFORMATION_CLOSE;
    SetFocus(GetDlgItem(target, focusId));
    placement.Show();
}

/// Enables TV-only controls exactly as the Recording page in Emulators.
static void UpdateRecordingSettingsControls(HWND window) {
    const bool enabled = SendDlgItemMessageW(window, ID_RECORD_TV, BM_GETCHECK, 0, 0) == BST_CHECKED;
    constexpr int controls[]{ ID_RECORD_SIZE, ID_RECORD_RATE, ID_RECORD_SIZE_LABEL, ID_RECORD_RATE_LABEL };
    for (int id : controls) {
        EnableWindow(GetDlgItem(window, id), enabled);
    }
}

/// Reads a main-form control rectangle in unscrolled content coordinates.
static bool RecordingReferenceRect(HWND owner, int id, RECT& bounds) {
    const HWND content = SettingsContentWindow(owner);
    if (!GetWindowRect(GetDlgItem(content, id), &bounds)) {
        return false;
    }
    MapWindowPoints(nullptr, content, reinterpret_cast<POINT*>(&bounds), 2);
    OffsetRect(&bounds, GetScrollPos(content, SB_HORZ), GetScrollPos(content, SB_VERT));
    return true;
}

/// Adjusts a dropdown's pending position and size to the monitor work area before it becomes visible.
/// Removes its subclass when the native list window is destroyed.
static LRESULT CALLBACK ComboBoxDropDownSubclassProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam,
        UINT_PTR subclassId, DWORD_PTR referenceData) {
    if (msg == WM_WINDOWPOSCHANGING) {
        WINDOWPOS* position = reinterpret_cast<WINDOWPOS*>(lParam);
        HWND combo = reinterpret_cast<HWND>(referenceData);
        HMONITOR monitor = MonitorFromWindow(combo, MONITOR_DEFAULTTONEAREST);
        MONITORINFO information = {};
        information.cbSize = sizeof(information);
        RECT current = {};
        RECT comboRect = {};
        if (position != nullptr
                && GetMonitorInfoW(monitor, &information)
                && GetWindowRect(window, &current)
                && GetWindowRect(combo, &comboRect)) {
            LONG workWidth = information.rcWork.right - information.rcWork.left;
            if (workWidth > 0) {
                LONG currentWidth = position->flags & SWP_NOSIZE ? current.right - current.left : position->cx;
                LONG minimumWidth = std::max(1L, comboRect.right - comboRect.left);
                LONG width = std::max(minimumWidth, std::min(currentWidth, workWidth));
                LONG left = position->flags & SWP_NOMOVE ? current.left : position->x;
                LONG maximumLeft = information.rcWork.right - width;
                LONG minimumLeft = std::min(information.rcWork.left, maximumLeft);
                LONG fittedLeft = std::clamp(left, minimumLeft, maximumLeft);
                if (width != currentWidth) {
                    position->cx = width;
                    if (position->flags & SWP_NOSIZE) {
                        position->cy = current.bottom - current.top;
                    }
                    position->flags &= ~SWP_NOSIZE;
                }
                if (fittedLeft != left) {
                    position->x = fittedLeft;
                    if (position->flags & SWP_NOMOVE) {
                        position->y = current.top;
                    }
                    position->flags &= ~SWP_NOMOVE;
                }
            }
        }
    } else if (msg == WM_NCDESTROY) {
        RemoveWindowSubclass(window, ComboBoxDropDownSubclassProc, subclassId);
    }
    return DefSubclassProc(window, msg, wParam, lParam);
}

/// Measures current items in the dropdown font immediately before opening, adding borders, padding, and scrollbar space.
/// Limits the list to 13 visible items and keeps it at least as wide as its combo within the monitor work area.
static void UpdateComboBoxDropDownSize(HWND combo) {
    if (combo == nullptr) {
        return;
    }
    SendMessageW(GetSettingsComboBox(combo), CB_SETMINVISIBLE, COMBO_BOX_MAX_VISIBLE_ITEMS, 0);
    COMBOBOXINFO information = {};
    information.cbSize = sizeof(information);
    HWND list = combo;
    if (GetComboBoxInfo(GetSettingsComboBox(combo), &information) && information.hwndList != nullptr) {
        list = information.hwndList;
        SetWindowSubclass(information.hwndList, ComboBoxDropDownSubclassProc, COMBO_BOX_DROPDOWN_SUBCLASS_ID,
            reinterpret_cast<DWORD_PTR>(combo));
    }
    HDC dc = GetDC(list);
    if (dc == nullptr) {
        return;
    }
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(list, WM_GETFONT, 0, 0));
    if (font == nullptr) {
        font = reinterpret_cast<HFONT>(SendMessageW(combo, WM_GETFONT, 0, 0));
    }
    if (font == nullptr) {
        font = static_cast<HFONT>(GetStockObject(DEFAULT_GUI_FONT));
    }
    HGDIOBJ previousFont = SelectObject(dc, font);
    LONG maximumWidth = 0;
    int count = static_cast<int>(SendMessageW(combo, CB_GETCOUNT, 0, 0));
    for (int index = 0; index < count; index++) {
        int length = static_cast<int>(SendMessageW(combo, CB_GETLBTEXTLEN, index, 0));
        if (length <= 0) {
            continue;
        }
        std::wstring text(length + 1, L'\0');
        if (SendMessageW(combo, CB_GETLBTEXT, index, reinterpret_cast<LPARAM>(text.data())) == CB_ERR) {
            continue;
        }
        SIZE size = {};
        if (GetTextExtentPoint32W(dc, text.c_str(), length, &size)) {
            ABC spacing = {};
            wchar_t lastCharacter = text[length - 1];
            if (GetCharABCWidthsW(dc, lastCharacter, lastCharacter, &spacing)) {
                size.cx += std::max(0, -spacing.abcC);
            }
            maximumWidth = std::max(maximumWidth, size.cx);
        }
    }
    SelectObject(dc, previousFont);
    ReleaseDC(list, dc);
    LONG width = maximumWidth + 2 * GetSystemMetrics(SM_CXEDGE);
    DWORD listStyle = WS_BORDER;
    DWORD listExtendedStyle = 0;
    if (information.hwndList != nullptr) {
        listStyle = static_cast<DWORD>(GetWindowLongPtrW(information.hwndList, GWL_STYLE));
        listExtendedStyle = static_cast<DWORD>(GetWindowLongPtrW(information.hwndList, GWL_EXSTYLE));
    }
    RECT listRect = { 0, 0, width, 1 };
    if (AdjustWindowRectEx(&listRect, listStyle, FALSE, listExtendedStyle)) {
        width = listRect.right - listRect.left;
    } else {
        width += 2 * GetSystemMetrics(SM_CXBORDER);
    }
    width += GetSystemMetrics(SM_CXVSCROLL);
    RECT rect = {};
    if (GetWindowRect(combo, &rect)) {
        width = std::max(width, rect.right - rect.left);
    }
    SendMessageW(combo, CB_SETDROPPEDWIDTH, width, 0);
}

/// Preserves main-form margins and About button sizes, scaling the dialog and combos with its font and DPI.
static SIZE LayoutRecordingSettings(HWND window) {
    const RecordingWindowData* recordingData =
        reinterpret_cast<const RecordingWindowData*>(GetWindowLongPtrW(window, DWLP_USER));
    const HWND owner = recordingData ? recordingData->owner : nullptr;
    const SettingsWindowData* data = owner
        ? reinterpret_cast<const SettingsWindowData*>(GetWindowLongPtrW(owner, GWLP_USERDATA))
        : nullptr;
    RECT languageLabel{};
    RECT languageCombo{};
    RECT firstRadio{};
    RECT secondRadio{};
    RECT monitorLabel{};
    RECT firstButton{};
    RECT secondButton{};
    RECT bottomButton{};
    RecordingReferenceRect(owner, ID_LANGUAGE_LABEL, languageLabel);
    RecordingReferenceRect(owner, ID_LANGUAGE, languageCombo);
    RecordingReferenceRect(owner, ID_ANIMATION_PRIMARY, firstRadio);
    RecordingReferenceRect(owner, ID_ANIMATION_SECONDARY, secondRadio);
    RecordingReferenceRect(owner, ID_MONITOR_GROUP, monitorLabel);
    RecordingReferenceRect(owner, ID_ALL_ANIMATIONS, firstButton);
    RecordingReferenceRect(owner, ID_NO_ANIMATIONS, secondButton);
    RecordingReferenceRect(owner, data && data->appMode ? ID_RECORDING_SETTINGS : ID_OK, bottomButton);
    const int margin = languageLabel.left;
    const int top = std::min(languageLabel.top, languageCombo.top);
    const int radioHeight = firstRadio.bottom - firstRadio.top;
    const int radioStep = secondRadio.top - firstRadio.top;
    const int rowGap = std::max(0L, monitorLabel.top - firstButton.bottom);
    RECT buttonGeometry = { 0, 0, 50, 14 };
    MapDialogRect(window, &buttonGeometry);
    const int buttonHeight = buttonGeometry.bottom;
    const int buttonWidth = buttonGeometry.right;
    const int buttonGap = secondButton.left - firstButton.right;
    const int bottomMargin = data
        ? std::max(0, data->contentHeight - static_cast<int>(bottomButton.bottom))
        : margin;
    RECT horizontal{ 0, 0, 249, 0 };
    MapDialogRect(window, &horizontal);
    RECT comboGeometry{ 0, 0, RECORDING_COMBO_WIDTH_DLU, 90 };
    MapDialogRect(window, &comboGeometry);
    const int comboWidth = comboGeometry.right;
    const int width = horizontal.right;
    const int comboLeft = width - margin - comboWidth;
    RECT indent{ 0, 0, 9, 0 };
    MapDialogRect(window, &indent);
    const int labelLeft = margin + indent.right;
    const int textWidth = width - 2 * margin;
    const int televisionTop = top + radioStep + 4;
    SetWindowPos(GetDlgItem(window, ID_RECORD_VIEWPORT), nullptr, margin, top, textWidth, radioHeight,
        SWP_NOZORDER | SWP_NOACTIVATE);
    SetWindowPos(GetDlgItem(window, ID_RECORD_TV), nullptr, margin, televisionTop, textWidth, radioHeight,
        SWP_NOZORDER | SWP_NOACTIVATE);
    const int firstComboTop = televisionTop + radioHeight + rowGap;
    SetWindowPos(GetDlgItem(window, ID_RECORD_SIZE), nullptr, comboLeft, firstComboTop, comboWidth,
        comboGeometry.bottom, SWP_NOZORDER | SWP_NOACTIVATE);
    RECT comboBounds{};
    GetWindowRect(GetDlgItem(window, ID_RECORD_SIZE), &comboBounds);
    const int comboHeight = comboBounds.bottom - comboBounds.top;
    const int secondComboTop = firstComboTop + comboHeight + rowGap;
    SetWindowPos(GetDlgItem(window, ID_RECORD_RATE), nullptr, comboLeft, secondComboTop, comboWidth,
        comboGeometry.bottom, SWP_NOZORDER | SWP_NOACTIVATE);
    const int labelHeight = languageLabel.bottom - languageLabel.top;
    const int labelWidth = comboLeft - labelLeft - buttonGap;
    SetWindowPos(GetDlgItem(window, ID_RECORD_SIZE_LABEL), nullptr, labelLeft, firstComboTop, labelWidth, labelHeight,
        SWP_NOZORDER | SWP_NOACTIVATE);
    SetWindowPos(GetDlgItem(window, ID_RECORD_RATE_LABEL), nullptr, labelLeft, secondComboTop, labelWidth, labelHeight,
        SWP_NOZORDER | SWP_NOACTIVATE);
    const int noteTop = secondComboTop + comboHeight + rowGap;
    RECT noteGeometry{ 0, 0, 0, 8 };
    MapDialogRect(window, &noteGeometry);
    const int noteHeight = noteGeometry.bottom;
    SetWindowPos(GetDlgItem(window, ID_RECORD_NOTE), nullptr, margin, noteTop, textWidth, noteHeight,
        SWP_NOZORDER | SWP_NOACTIVATE);
    const int buttonsTop = noteTop + noteHeight + rowGap;
    const int cancelLeft = width - margin - buttonWidth;
    SetWindowPos(GetDlgItem(window, IDOK), nullptr, cancelLeft - buttonGap - buttonWidth, buttonsTop, buttonWidth,
        buttonHeight, SWP_NOZORDER | SWP_NOACTIVATE);
    SetWindowPos(GetDlgItem(window, IDCANCEL), nullptr, cancelLeft, buttonsTop, buttonWidth, buttonHeight,
        SWP_NOZORDER | SWP_NOACTIVATE);
    AlignSettingsLabel(GetDlgItem(window, ID_RECORD_SIZE_LABEL), GetDlgItem(window, ID_RECORD_SIZE));
    AlignSettingsLabel(GetDlgItem(window, ID_RECORD_RATE_LABEL), GetDlgItem(window, ID_RECORD_RATE));
    AlignSettingsButton(GetDlgItem(window, IDCANCEL), GetDlgItem(window, IDOK));
    UpdateComboBoxDropDownSize(GetDlgItem(window, ID_RECORD_SIZE));
    UpdateComboBoxDropDownSize(GetDlgItem(window, ID_RECORD_RATE));
    const SIZE size{ width, buttonsTop + buttonHeight + bottomMargin };
    return size;
}

/// Recreates the shared system font and recalculates dialog geometry after metric, theme or DPI changes.
static void RefreshRecordingSettingsFont(HWND window, RecordingWindowData& data) {
    const HFONT previous = data.font;
    data.font = CreateSystemDialogFont();
    if (data.font) {
        SendMessageW(window, WM_SETFONT, reinterpret_cast<WPARAM>(data.font), FALSE);
        EnumChildWindows(window, ApplySystemDialogFont, reinterpret_cast<LPARAM>(data.font));
        if (previous) {
            DeleteObject(previous);
        }
    } else {
        data.font = previous;
    }
    const SIZE size = LayoutRecordingSettings(window);
    RECT bounds{ 0, 0, size.cx, size.cy };
    const DWORD style = static_cast<DWORD>(GetWindowLongPtrW(window, GWL_STYLE));
    const DWORD extendedStyle = static_cast<DWORD>(GetWindowLongPtrW(window, GWL_EXSTYLE));
    AdjustWindowRectEx(&bounds, style, FALSE, extendedStyle);
    SetWindowPos(window, nullptr, 0, 0, bounds.right - bounds.left, bounds.bottom - bounds.top,
        SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
}

/// Refreshes localized recording captions without changing the font, geometry or unconfirmed choices.
static void RefreshRecordingSettingsWindow(HWND window, RecordingWindowData& data) {
    const RecordingText& strings = RecordingSettingsText(data.language);
    const LocalizedText& common = Text(data.language);
    SetWindowTextW(window, strings.title);
    SetDlgItemTextW(window, ID_RECORD_VIEWPORT, strings.viewport);
    SetDlgItemTextW(window, ID_RECORD_TV, strings.television);
    SetDlgItemTextW(window, ID_RECORD_SIZE_LABEL, strings.resolution);
    SetDlgItemTextW(window, ID_RECORD_RATE_LABEL, strings.frameRate);
    SetDlgItemTextW(window, ID_RECORD_NOTE, strings.note);
    SetDlgItemTextW(window, IDOK, common.ok);
    SetDlgItemTextW(window, IDCANCEL, common.cancel);
}

/// Restores saved recording-window coordinates or centers its first opening, using shared work-area clamping.
static void RestoreRecordingSettingsPosition(HWND window, const RecordingWindowData& data) {
    RECT dialogBounds{};
    if (!GetWindowRect(window, &dialogBounds)) {
        return;
    }
    const int width = dialogBounds.right - dialogBounds.left;
    const int height = dialogBounds.bottom - dialogBounds.top;
    int left = data.settings->recordingSettingsX;
    int top = data.settings->recordingSettingsY;
    if (left == std::numeric_limits<int>::min() || top == std::numeric_limits<int>::min()) {
        RECT ownerBounds{};
        if (!GetWindowRect(data.owner, &ownerBounds)) {
            return;
        }
        left = ownerBounds.left + (ownerBounds.right - ownerBounds.left - width) / 2;
        top = ownerBounds.top + (ownerBounds.bottom - ownerBounds.top - height) / 2;
    }
    ClampFormPosition(&left, &top, width, height);
    SetWindowPos(window, nullptr, left, top, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
}

/// Remembers an initialized recording window without committing unconfirmed output choices.
static void SaveRecordingSettingsPosition(HWND window, const RecordingWindowData* data) {
    if (!data || !data->initialized || !data->settings) {
        return;
    }
    SaveFormPosition(window, &data->settings->recordingSettingsX, &data->settings->recordingSettingsY);
    data->settings->SaveWindowPositions();
}

/// Initializes localized captions, TV presets and the currently saved recording choices.
static void InitializeRecordingSettings(HWND window, RecordingWindowData& data) {
    SendMessageW(window, DM_SETDEFID, IDOK, 0);
    CheckRadioButton(window, ID_RECORD_VIEWPORT, ID_RECORD_TV,
        data.settings->recording.television ? ID_RECORD_TV : ID_RECORD_VIEWPORT);
    for (unsigned index = 0; index < 3; index++) {
        SendDlgItemMessageW(window, ID_RECORD_SIZE, CB_ADDSTRING, 0,
            reinterpret_cast<LPARAM>(RecordingResolutionText(index)));
    }
    for (unsigned index = 0; index < 4; index++) {
        SendDlgItemMessageW(window, ID_RECORD_RATE, CB_ADDSTRING, 0,
            reinterpret_cast<LPARAM>(RecordingRateText(index)));
    }
    SendDlgItemMessageW(window, ID_RECORD_SIZE, CB_SETCURSEL, data.settings->recording.resolution, 0);
    SendDlgItemMessageW(window, ID_RECORD_RATE, CB_SETCURSEL, data.settings->recording.rate, 0);
    UpdateRecordingSettingsControls(window);
    RefreshRecordingSettingsWindow(window, data);
    RefreshRecordingSettingsFont(window, data);
    RestoreRecordingSettingsPosition(window, data);
}

/// Saves confirmed output choices without altering an active recording session.
static void SaveRecordingSettings(HWND window, RecordingWindowData& data) {
    RecordingOptions selected;
    selected.television = SendDlgItemMessageW(window, ID_RECORD_TV, BM_GETCHECK, 0, 0) == BST_CHECKED;
    selected.resolution = std::clamp(int(SendDlgItemMessageW(window, ID_RECORD_SIZE, CB_GETCURSEL, 0, 0)), 0, 2);
    selected.rate = std::clamp(int(SendDlgItemMessageW(window, ID_RECORD_RATE, CB_GETCURSEL, 0, 0)), 0, 3);
    data.settings->recording = selected;
    data.settings->Save();
}

/// Uses native modeless dialog keyboard handling and owns recording-settings window resources.
static INT_PTR CALLBACK RecordingSettingsProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam) {
    RecordingWindowData* data = reinterpret_cast<RecordingWindowData*>(GetWindowLongPtrW(window, DWLP_USER));
    if (msg == WM_INITDIALOG) {
        data = reinterpret_cast<RecordingWindowData*>(lParam);
        SetWindowLongPtrW(window, DWLP_USER, lParam);
        if (data) {
            InitializeRecordingSettings(window, *data);
        }
        return TRUE;
    }
    switch (msg) {
        case WM_COMMAND:
            if (!data) {
                break;
            }
            if (HIWORD(wParam) == CBN_DROPDOWN
                    && (LOWORD(wParam) == ID_RECORD_SIZE || LOWORD(wParam) == ID_RECORD_RATE)) {
                UpdateComboBoxDropDownSize(reinterpret_cast<HWND>(lParam));
                return TRUE;
            }
            switch (LOWORD(wParam)) {
                case ID_RECORD_VIEWPORT:
                case ID_RECORD_TV:
                    UpdateRecordingSettingsControls(window);
                    return TRUE;
                case IDOK:
                    SaveRecordingSettings(window, *data);
                    DestroyWindow(window);
                    return TRUE;
                case IDCANCEL:
                    DestroyWindow(window);
                    return TRUE;
            }
            break;
        case WM_CLOSE:
            DestroyWindow(window);
            return TRUE;
        case WM_SYSCOMMAND:
            if ((wParam & 0xFFF0) == SC_SCREENSAVE && ShouldInhibitScreenSaver()) {
                return TRUE;
            }
            if ((wParam & 0xFFF0) == SC_MINIMIZE) {
                SaveRecordingSettingsPosition(window, data);
            }
            break;
        case WM_EXITSIZEMOVE:
            SaveRecordingSettingsPosition(window, data);
            return TRUE;
        case WM_DPICHANGED:
            if (data) {
                const RECT* suggested = reinterpret_cast<const RECT*>(lParam);
                SetWindowPos(window, nullptr, suggested->left, suggested->top, suggested->right - suggested->left,
                    suggested->bottom - suggested->top, SWP_NOZORDER | SWP_NOACTIVATE);
                RefreshRecordingSettingsFont(window, *data);
            }
            return TRUE;
        case WM_SETTINGCHANGE:
        case WM_THEMECHANGED:
            if (data) {
                RefreshRecordingSettingsFont(window, *data);
            }
            break;
        case WM_DESTROY:
            SaveRecordingSettingsPosition(window, data);
            break;
        case WM_NCDESTROY:
            if (window == recordingSettingsWindow) {
                recordingSettingsWindow = nullptr;
            }
            if (data) {
                if (data->font) {
                    DeleteObject(data->font);
                    data->font = nullptr;
                }
                SetWindowLongPtrW(window, DWLP_USER, 0);
                if (data->initialized) {
                    delete data;
                }
            }
            break;
    }
    return FALSE;
}

/// Creates or restores independent modeless recording settings, matching Help and About activation and topmost policy.
static void ShowRecordingSettings(HWND owner, SettingsWindowData& settingsData) {
    if (recordingSettingsWindow && IsWindow(recordingSettingsWindow)) {
        SetForegroundWindowEx(recordingSettingsWindow);
        return;
    }
    if (!settingsData.settings) {
        return;
    }
    std::unique_ptr<RecordingWindowData> data = std::make_unique<RecordingWindowData>();
    data->settings = settingsData.settings;
    data->owner = owner;
    data->language = settingsData.language;
    recordingSettingsWindow = CreateDialogParamW(app->instance, MAKEINTRESOURCEW(IDD_RECORDING_SETTINGS), nullptr,
        RecordingSettingsProc, reinterpret_cast<LPARAM>(data.get()));
    if (!recordingSettingsWindow) {
        return;
    }
    data->initialized = true;
    data.release();
    SendMessageW(recordingSettingsWindow, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(app->programIcons.Large()));
    SendMessageW(recordingSettingsWindow, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(app->programIcons.Small()));
    UpdateInformationWindowsTopmost(owner);
    ShowWindow(recordingSettingsWindow, SW_SHOW);
    SetForegroundWindowEx(recordingSettingsWindow);
}

/// Stops and destroys every full-monitor surface created by settings preview.
static void DestroySettingsPreviewSurfaces(Application& app) {
    StopAllRenderSurfaces(app);
    for (std::unique_ptr<RenderSurface>& surface : app.surfaces) {
        if (surface->window) {
            DestroyWindow(surface->window);
        }
    }
    app.surfaces.clear();
}

/// Ends settings preview and returns the process to standalone UI mode.
static void StopSettingsPreview(HWND settingsWindow, SettingsWindowData& data) {
    if (!data.previewActive || !app) {
        return;
    }
    DestroySettingsPreviewSurfaces(*app);
    app->mode = RunMode::Application;
    data.previewActive = false;
    SetWindowPos(settingsWindow, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
    UpdateInformationWindowsTopmost(settingsWindow);
}

/// Starts an independent preview surface on every available monitor.
static bool StartSettingsPreview(HWND settingsWindow, SettingsWindowData& data) {
    if (!app || data.previewActive) {
        return data.previewActive;
    }
    DestroySettingsPreviewSurfaces(*app);
    app->mode = RunMode::SettingsPreview;
    SyncRuntimeSettings(*app);
    bool created = true;
    const std::vector<DisplayMonitor> monitors = AvailableMonitors();
    if (monitors.empty()) {
        const RECT bounds{ 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };
        created = AddRenderSurface(*app, bounds, nullptr, 0);
    } else {
        for (std::size_t index = 0; index < monitors.size(); index++) {
            if (!AddRenderSurface(*app, monitors[index].rect, nullptr,
                static_cast<unsigned>(index + 1), monitors[index].device)) {
                created = false;
                break;
            }
        }
    }
    if (!created || app->surfaces.empty()) {
        DestroySettingsPreviewSurfaces(*app);
        app->mode = RunMode::Application;
        MessageBoxW(settingsWindow, Text(data.language).rendererFailed, PRODUCT_NAME, MB_OK | MB_ICONERROR);
        return false;
    }
    data.previewActive = true;
    SetWindowPos(settingsWindow, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
    UpdateInformationWindowsTopmost(settingsWindow);
    SetForegroundWindow(settingsWindow);
    return true;
}

/// Persists the non-minimized control-window position for its active profile.
static void SaveControlWindowPosition(HWND window, SettingsWindowData* data) {
    if (!data || !data->settings || IsIconic(window)) {
        return;
    }
    RECT bounds{};
    if (!GetWindowRect(window, &bounds)) {
        return;
    }
    data->settings->controlWindowX = bounds.left;
    data->settings->controlWindowY = bounds.top;
    if (data->appMode) {
        data->settings->Save();
    }
}

/// Restores original preferences while preserving remembered window positions and selected monitor rows.
static void RestoreOriginalSettings(SettingsWindowData& data) {
    data.original.selectedAnimationMonitors = data.settings->selectedAnimationMonitors;
    data.original.allAnimationMonitorsSelected = data.settings->allAnimationMonitorsSelected;
    data.original.controlWindowX = data.settings->controlWindowX;
    data.original.controlWindowY = data.settings->controlWindowY;
    data.original.helpWindowState = data.settings->helpWindowState;
    data.original.aboutWindowState = data.settings->aboutWindowState;
    data.original.recordingSettingsX = data.settings->recordingSettingsX;
    data.original.recordingSettingsY = data.settings->recordingSettingsY;
    *data.settings = data.original;
}

/// Tests whether a message belongs to a window or one of its descendants.
static bool MessageTargetsWindow(const MSG& msg, HWND window) {
    return window && (msg.hwnd == window || IsChild(window, msg.hwnd));
}

/// Forwards a panel notification and preserves its dialog message result.
static INT_PTR ForwardSettingsPanelNotification(HWND window, UINT msg, WPARAM wParam, LPARAM lParam) {
    const LRESULT result = SendMessageW(GetParent(window), msg, wParam, lParam);
    SetWindowLongPtrW(window, DWLP_MSGRESULT, result);
    return TRUE;
}

/// Forwards panel notifications to the settings window and updates the panel's native scroll bars.
static INT_PTR CALLBACK SettingsPanelProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam) {
    SettingsWindowData* data = reinterpret_cast<SettingsWindowData*>(GetWindowLongPtrW(window, GWLP_USERDATA));
    if (msg == WM_INITDIALOG) {
        SetWindowLongPtrW(window, GWLP_USERDATA, lParam);
        return FALSE;
    }
    switch (msg) {
        case WM_COMMAND:
        case WM_HSCROLL:
        case WM_VSCROLL:
        case WM_MOUSEWHEEL:
        case ENSURE_SETTINGS_CONTROL_VISIBLE:
            SendMessageW(GetParent(window), msg, wParam, lParam);
            return TRUE;
        case WM_NOTIFY:
        case DM_GETDEFID:
            return ForwardSettingsPanelNotification(window, msg, wParam, lParam);
        case WM_SIZE:
            if (data) {
                UpdateSettingsScrollBars(window, *data, false);
            }
            return TRUE;
    }
    return FALSE;
}

/// Creates the native monitor list for both profiles; only standalone mode exposes output checkboxes.
static void CreateSettingsMonitorList(HWND window, const SettingsWindowData& data, int monitorTop, int contentMargin,
        int fullControlWidth) {
    CreateWindowExW(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | SS_LEFTNOWORDWRAP, contentMargin,
        monitorTop, fullControlWidth, 22, window, reinterpret_cast<HMENU>(ID_MONITOR_GROUP), nullptr, nullptr);
    HWND monitorList = CreateWindowExW(WS_EX_CLIENTEDGE, WC_LISTVIEWW, L"",
        WS_CHILD | WS_VISIBLE | WS_TABSTOP | LVS_REPORT | LVS_SHOWSELALWAYS, contentMargin, monitorTop + 20,
        fullControlWidth, 108, window, reinterpret_cast<HMENU>(ID_MONITOR_LIST), nullptr, nullptr);
    ListView_SetExtendedListViewStyle(monitorList,
        LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER | (data.appMode ? LVS_EX_CHECKBOXES : 0U));
    LVCOLUMNW column{};
    column.mask = LVCF_TEXT | LVCF_SUBITEM;
    column.pszText = const_cast<LPWSTR>(L"");
    for (int index = 0; index < MONITOR_COLUMN_COUNT; index++) {
        column.iSubItem = index;
        ListView_InsertColumn(monitorList, index, &column);
    }
    SetWindowSubclass(monitorList, MonitorListSubclassProc, ID_MONITOR_LIST, 0);
}

/// Creates this project's animation controls with their established positions and dimensions.
static int CreateAnimationControls(HWND window, int top) {
    constexpr int contentMargin = 18;
    constexpr int sliderWidth = 435;
    constexpr int rightSliderX = 476;
    constexpr int checkboxWidth = 288;
    constexpr int columnX[]{ 24, 320, 617 };
    CreateWindowExW(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE, contentMargin, top + 28, sliderWidth, 22, window,
        reinterpret_cast<HMENU>(ID_OBJECT_SPEED_LABEL), nullptr, nullptr);
    HWND objectSlider = CreateWindowExW(0, TRACKBAR_CLASSW, L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP | TBS_AUTOTICKS,
        contentMargin, top + 50, sliderWidth, 34, window, reinterpret_cast<HMENU>(ID_OBJECT_SPEED), nullptr, nullptr);
    SendMessageW(objectSlider, TBM_SETRANGE, TRUE, MAKELONG(0, 1600));
    SendMessageW(objectSlider, TBM_SETTICFREQ, 100, 0);
    CreateWindowExW(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE, rightSliderX, top + 28, sliderWidth, 22, window,
        reinterpret_cast<HMENU>(ID_CAMERA_SPEED_LABEL), nullptr, nullptr);
    HWND cameraSlider = CreateWindowExW(0, TRACKBAR_CLASSW, L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP | TBS_AUTOTICKS,
        rightSliderX, top + 50, sliderWidth, 34, window, reinterpret_cast<HMENU>(ID_CAMERA_SPEED), nullptr, nullptr);
    SendMessageW(cameraSlider, TBM_SETRANGE, TRUE, MAKELONG(0, 1600));
    SendMessageW(cameraSlider, TBM_SETTICFREQ, 100, 0);
    CreateWindowExW(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE, contentMargin, top + 88, sliderWidth, 22, window,
        reinterpret_cast<HMENU>(ID_COPY_COUNT_LABEL), nullptr, nullptr);
    HWND copySlider = CreateWindowExW(0, TRACKBAR_CLASSW, L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP | TBS_AUTOTICKS,
        contentMargin, top + 110, sliderWidth, 34, window, reinterpret_cast<HMENU>(ID_COPY_COUNT), nullptr, nullptr);
    SendMessageW(copySlider, TBM_SETRANGE, TRUE, MAKELONG(1, 10));
    SendMessageW(copySlider, TBM_SETTICFREQ, 1, 0);
    CreateWindowExW(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE, rightSliderX, top + 88, sliderWidth, 22, window,
        reinterpret_cast<HMENU>(ID_OBJECT_SIZE_LABEL), nullptr, nullptr);
    HWND sizeSlider = CreateWindowExW(0, TRACKBAR_CLASSW, L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP | TBS_AUTOTICKS,
        rightSliderX, top + 110, sliderWidth, 34, window, reinterpret_cast<HMENU>(ID_OBJECT_SIZE), nullptr, nullptr);
    SendMessageW(sizeSlider, TBM_SETRANGE, TRUE, MAKELONG(50, 200));
    SendMessageW(sizeSlider, TBM_SETTICFREQ, 25, 0);
    CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_GROUP | BS_AUTORADIOBUTTON, 24,
        top + 148, 430, 21, window, reinterpret_cast<HMENU>(ID_CAMERA_STATIC), nullptr, nullptr);
    CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 24, top + 168, 430, 21, window,
        reinterpret_cast<HMENU>(ID_CAMERA_FLIGHT), nullptr, nullptr);
    CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_GROUP | BS_3STATE, columnX[1],
        top + 148, checkboxWidth, 21, window, reinterpret_cast<HMENU>(ID_AMBIENT_LIGHT), nullptr, nullptr);
    CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_3STATE, columnX[1], top + 168,
        checkboxWidth, 21, window, reinterpret_cast<HMENU>(ID_RIM_LIGHT), nullptr, nullptr);
    CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_GROUP | BS_3STATE, columnX[2],
        top + 148, checkboxWidth, 21, window, reinterpret_cast<HMENU>(ID_MAIN_LIGHT), nullptr, nullptr);
    CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_3STATE, columnX[2], top + 168,
        checkboxWidth, 21, window, reinterpret_cast<HMENU>(ID_FILL_LIGHT), nullptr, nullptr);
    const int solidsTop = top + 198;
    CreateWindowExW(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE, 18, solidsTop, 330, 22, window,
        reinterpret_cast<HMENU>(ID_SOLIDS_GROUP), nullptr, nullptr);
    constexpr int columns = 3;
    constexpr int rowHeight = 20;
    const int solidRows = static_cast<int>((SOLID_COUNT + columns - 1) / columns);
    const int actionButtonsTop = solidsTop + 22 + solidRows * rowHeight + 7;
    for (std::size_t index = 0; index < SOLID_COUNT; index++) {
        const int column = static_cast<int>(index % columns);
        const int row = static_cast<int>(index / columns);
        CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_3STATE,
            columnX[column], solidsTop + 22 + row * rowHeight, checkboxWidth, 21, window,
            reinterpret_cast<HMENU>(ID_SOLID_FIRST + index), nullptr, nullptr);
    }
    return actionButtonsTop;
}

/// Attaches mixed-value feedback to sliders, radio buttons and per-monitor action buttons only.
static bool AttachMixedSettingsControls(HWND window) {
    std::vector<int> ids{ ID_ALL_ANIMATIONS, ID_NO_ANIMATIONS };
    for (const AnimationSliderControl& control : ANIMATION_SLIDERS) {
        ids.push_back(control.id);
    }
    for (const int id : ANIMATION_RADIO_IDS) {
        ids.push_back(id);
    }
    for (const int id : ids) {
        if (!MixedControls::Attach(GetDlgItem(window, id))) {
            return false;
        }
    }
    return true;
}

/// Creates and initializes the standalone and screen-saver settings controls.
static LRESULT CreateSettingsControls(HWND window, SettingsWindowData* data) {
    const HWND settingsWindow = window;
    const int top = 10;
    constexpr int contentMargin = 18;
    const int fullControlWidth = data->contentWidth - 2 * contentMargin;
    constexpr int rightSliderX = 476;
    constexpr int checkboxWidth = 288;
    if (data->appMode) {
        if (!SetPropW(window, INSTANCE_WINDOW_PROPERTY, window)) {
            return -1;
        }
        app->status = CreateWindowExW(0, STATUSCLASSNAMEW, L"", WS_CHILD | WS_VISIBLE, 0, 0, 0, 0, window,
            reinterpret_cast<HMENU>(ID_STATUS), nullptr, nullptr);
        data->contentWindow = CreateDialogParamW(app->instance, MAKEINTRESOURCEW(IDD_SETTINGS_PANEL), window,
            SettingsPanelProc, reinterpret_cast<LPARAM>(data));
        if (!app->status || !data->contentWindow) {
            return -1;
        }
        const LONG_PTR style = GetWindowLongPtrW(data->contentWindow, GWL_STYLE);
        SetWindowLongPtrW(data->contentWindow, GWL_STYLE, style | data->scrollStyle);
        SetWindowPos(data->contentWindow, nullptr, 0, 0, 0, 0,
            SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
        LayoutSettingsContent(window, *data);
        window = data->contentWindow;
    }
    CreateWindowExW(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE, 18, top, 196, 22, window,
        reinterpret_cast<HMENU>(ID_LANGUAGE_LABEL), nullptr, nullptr);
    HWND languageCombo = CreateWindowExW(0, WC_COMBOBOXW, L"",
        WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_TABSTOP | CBS_DROPDOWNLIST,
        171, top - 4, 274, 400, window, reinterpret_cast<HMENU>(ID_LANGUAGE), nullptr, nullptr);
    if (data->appMode) {
        CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_AUTOCHECKBOX, rightSliderX, top,
            checkboxWidth, 21, window, reinterpret_cast<HMENU>(ID_PREVENT_SCREEN_SAVER), nullptr, nullptr);
        SetTimer(settingsWindow, ID_SCREEN_SAVER_CHECK_TIMER, SCREEN_SAVER_CHECK_INTERVAL, nullptr);
    }
    for (std::size_t index = 0; index < LANGUAGE_COUNT; index++) {
        const AppLanguage language = LanguageAtIndex(static_cast<int>(index));
        SendMessageW(languageCombo, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(Text(language).languageName));
    }
    SendMessageW(languageCombo, CB_SETCURSEL, LanguageIndex(data->language), 0);
    const int actionButtonsTop = CreateAnimationControls(window, top);

    CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP, data->appMode ? 14 : 24, actionButtonsTop,
        150, PUSH_BUTTON_HEIGHT, window, reinterpret_cast<HMENU>(ID_ALL_ANIMATIONS), nullptr, nullptr);
    CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP, data->appMode ? 171 : 181, actionButtonsTop,
        data->appMode ? 160 : 150, PUSH_BUTTON_HEIGHT, window, reinterpret_cast<HMENU>(ID_NO_ANIMATIONS), nullptr,
        nullptr);
    if (data->appMode) {
        constexpr int firstRowGap = 4;
        const int pauseButtonWidth = 150 + fullControlWidth % 2;
        const int informationButtonWidth = pauseButtonWidth;
        const int firstButtonX = contentMargin;
        const int firstButtonWidth = (fullControlWidth - 3 * informationButtonWidth - 4 * firstRowGap) / 2;
        const int secondButtonWidth = firstButtonWidth;
        const int secondButtonX = firstButtonX + firstButtonWidth + firstRowGap;
        const int pauseButtonX = secondButtonX + secondButtonWidth + firstRowGap;
        const int helpButtonX = pauseButtonX + pauseButtonWidth + firstRowGap;
        const int aboutButtonX = helpButtonX + informationButtonWidth + firstRowGap;
        MoveWindow(GetDlgItem(window, ID_ALL_ANIMATIONS), firstButtonX, actionButtonsTop, firstButtonWidth,
            PUSH_BUTTON_HEIGHT, FALSE);
        MoveWindow(GetDlgItem(window, ID_NO_ANIMATIONS), secondButtonX, actionButtonsTop, secondButtonWidth,
            PUSH_BUTTON_HEIGHT, FALSE);
        CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP, pauseButtonX, actionButtonsTop,
            pauseButtonWidth, PUSH_BUTTON_HEIGHT, window, reinterpret_cast<HMENU>(ID_PAUSE), nullptr, nullptr);
        CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP, helpButtonX, actionButtonsTop,
            informationButtonWidth, PUSH_BUTTON_HEIGHT, window, reinterpret_cast<HMENU>(ID_HELP), nullptr, nullptr);
        CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP, aboutButtonX, actionButtonsTop,
            informationButtonWidth, PUSH_BUTTON_HEIGHT, window, reinterpret_cast<HMENU>(ID_ABOUT), nullptr, nullptr);
        const int monitorTop = actionButtonsTop + 37;
        CreateSettingsMonitorList(window, *data, monitorTop, contentMargin, fullControlWidth);
        constexpr int bottomRowGap = firstRowGap;
        const int narrowButtonWidth = informationButtonWidth;
        const int snapshotButtonWidth = narrowButtonWidth + 12;
        const int recordButtonWidth = 255;
        const int installButtonWidth = recordButtonWidth;
        const int recordingSettingsButtonWidth = fullControlWidth - recordButtonWidth - snapshotButtonWidth
            - installButtonWidth - 3 * bottomRowGap;
        const int recordButtonX = contentMargin + recordingSettingsButtonWidth + bottomRowGap;
        const int snapshotButtonX = recordButtonX + recordButtonWidth + bottomRowGap;
        const int installButtonX = snapshotButtonX + snapshotButtonWidth + bottomRowGap;
        CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP, contentMargin, monitorTop + 136,
            recordingSettingsButtonWidth, PUSH_BUTTON_HEIGHT, window, reinterpret_cast<HMENU>(ID_RECORDING_SETTINGS),
            nullptr, nullptr);
        CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP, recordButtonX, monitorTop + 136,
            recordButtonWidth, PUSH_BUTTON_HEIGHT, window, reinterpret_cast<HMENU>(ID_RECORD_TOGGLE), nullptr, nullptr);
        CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP, snapshotButtonX, monitorTop + 136,
            snapshotButtonWidth, PUSH_BUTTON_HEIGHT, window, reinterpret_cast<HMENU>(ID_SNAPSHOT), nullptr, nullptr);
        CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP, installButtonX, monitorTop + 136,
            installButtonWidth, PUSH_BUTTON_HEIGHT, window, reinterpret_cast<HMENU>(ID_INSTALL), nullptr, nullptr);
    } else {
        constexpr int firstRowGap = 4;
        constexpr int firstButtonWidth = 206;
        constexpr int secondButtonWidth = firstButtonWidth;
        constexpr int previewButtonWidth = 216;
        constexpr int informationButtonWidth = 124;
        const int firstButtonX = contentMargin;
        const int secondButtonX = firstButtonX + firstButtonWidth + firstRowGap;
        const int previewButtonX = secondButtonX + secondButtonWidth + firstRowGap;
        const int helpButtonX = previewButtonX + previewButtonWidth + firstRowGap;
        const int aboutButtonX = helpButtonX + informationButtonWidth + firstRowGap;
        MoveWindow(GetDlgItem(window, ID_ALL_ANIMATIONS), firstButtonX, actionButtonsTop, firstButtonWidth,
            PUSH_BUTTON_HEIGHT, FALSE);
        MoveWindow(GetDlgItem(window, ID_NO_ANIMATIONS), secondButtonX, actionButtonsTop, secondButtonWidth,
            PUSH_BUTTON_HEIGHT, FALSE);
        if (data->screenSaverSettings) {
            CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP, previewButtonX, actionButtonsTop,
                previewButtonWidth, PUSH_BUTTON_HEIGHT, window, reinterpret_cast<HMENU>(ID_PREVIEW_TOGGLE), nullptr,
                nullptr);
        }
        CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP, helpButtonX, actionButtonsTop,
            informationButtonWidth, PUSH_BUTTON_HEIGHT, window, reinterpret_cast<HMENU>(ID_HELP), nullptr, nullptr);
        CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP, aboutButtonX, actionButtonsTop,
            informationButtonWidth, PUSH_BUTTON_HEIGHT, window, reinterpret_cast<HMENU>(ID_ABOUT), nullptr, nullptr);
        constexpr int screenSaverButtonGap = firstRowGap;
        constexpr int confirmationButtonWidth = 124;
        const int monitorTop = actionButtonsTop + 37;
        CreateSettingsMonitorList(window, *data, monitorTop, contentMargin, fullControlWidth);
        const int screenSaverButtonsTop = monitorTop + 136;
        int buttonX = contentMargin + fullControlWidth - 2 * confirmationButtonWidth - screenSaverButtonGap;
        CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON, buttonX,
            screenSaverButtonsTop, confirmationButtonWidth, PUSH_BUTTON_HEIGHT, window, reinterpret_cast<HMENU>(ID_OK),
            nullptr, nullptr);
        buttonX += confirmationButtonWidth + screenSaverButtonGap;
        CreateWindowExW(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP, buttonX, screenSaverButtonsTop,
            confirmationButtonWidth, PUSH_BUTTON_HEIGHT, window, reinterpret_cast<HMENU>(ID_CANCEL), nullptr, nullptr);
    }
    if (!AttachMixedSettingsControls(window)) {
        return -1;
    }
    ApplyLocalizedCaptions(settingsWindow, *data);
    ApplySystemDialogFont(settingsWindow, *data);
    LayoutSettingsContent(settingsWindow, *data);
    InstallSettingsTabNavigation(window);
    UpdateSettingsScrollBars(window, *data, true);
    InitializeMonitorColumnWidths(GetDlgItem(window, ID_MONITOR_LIST), *data);
    return 0;
}

/// Handles only the object switches belonging to this project's animation.
static bool HandleAnimationObjectCommand(HWND window, SettingsWindowData& data, int id) {
    if (id < ID_SOLID_FIRST || id >= ID_SOLID_FIRST + SOLID_COUNT) {
        return false;
    }
    const unsigned index = id - ID_SOLID_FIRST;
    const bool enabled = SendDlgItemMessageW(SettingsContentWindow(window), id, BM_GETCHECK, 0, 0) != BST_CHECKED;
    data.settings->SetMonitorSolid(data.selectedAnimationDevices, index, enabled);
    CommitMonitorAnimation(window, data);
    return true;
}

/// Applies animation-control commands only to the selected display identities.
static bool HandleAnimationSettingsCommand(HWND window, SettingsWindowData& data, int id) {
    if (HandleAnimationObjectCommand(window, data, id)) {
        return true;
    }
    if (id == ID_ALL_ANIMATIONS || id == ID_NO_ANIMATIONS) {
        SetSelectedMonitorValue(window, data, ANIMATION_ENABLED_PROPERTY,
            id == ID_ALL_ANIMATIONS ? ALL_ANIMATION_MASK : 0U);
        return true;
    }
    for (std::size_t index = 0; index < std::size(ANIMATION_RADIO_IDS); index++) {
        if (id == ANIMATION_RADIO_IDS[index]) {
            SetSelectedMonitorValue(window, data, ANIMATION_RADIO_PROPERTY, static_cast<std::uint32_t>(index));
            return true;
        }
    }
    for (const AnimationControl& control : ANIMATION_CHECKBOXES) {
        if (control.id == id) {
            const bool enabled = SendDlgItemMessageW(SettingsContentWindow(window), id, BM_GETCHECK, 0, 0) != BST_CHECKED;
            SetSelectedMonitorValue(window, data, control.property, enabled);
            return true;
        }
    }
    return false;
}

/// Owns settings controls, commands, scrolling, focus and persistence.
/// Posted focus restoration never overrides a direct child-control click made while the message was pending.
static LRESULT CALLBACK SettingsProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam) {
    SettingsWindowData* data = reinterpret_cast<SettingsWindowData*>(GetWindowLongPtrW(window, GWLP_USERDATA));
    if (msg == WM_NCCREATE) {
        data = static_cast<SettingsWindowData*>(reinterpret_cast<CREATESTRUCTW*>(lParam)->lpCreateParams);
        SetWindowLongPtrW(window, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(data));
    }
    const HWND controls = SettingsContentWindow(window);
    switch (msg) {
        case WM_CREATE:
            if (data) {
                return CreateSettingsControls(window, data);
            }
            return -1;
        case WM_SHOWWINDOW:
            if (wParam && data) {
                InitializeMonitorColumnWidths(GetDlgItem(controls, ID_MONITOR_LIST), *data);
            }
            break;
        case DM_GETDEFID:
            if (data) {
                if (data->defaultButton && IsWindow(data->defaultButton)) {
                    return MAKELRESULT(GetDlgCtrlID(data->defaultButton), DC_HASDEFID);
                }
                if (data->appMode) {
                    return 0;
                }
                return MAKELRESULT(ID_OK, DC_HASDEFID);
            }
            break;
        case ACTIVATE_APPLICATION_WINDOW:
            if (data) {
                if (data->appMode) {
                    ActivateApplicationWindow(window);
                }
            }
            return 0;
        case UPDATE_SETTINGS_ACTION_BUTTONS:
            UpdateSettingsActionButtons(window);
            RestoreCurrentStatus();
            return 0;
        case UPDATE_MONITOR_ANIMATION_CONTROLS:
            if (data && data->monitorSelectionUpdatePending) {
                UpdateMonitorAnimationControls(window, *data);
            }
            return 0;
        case UPDATE_SETTINGS_CONTROL_METRICS:
            if (data) {
                UpdateSettingsControlMetrics(window);
            }
            return 0;
        case WM_SETTINGCHANGE:
        case WM_DPICHANGED:
            if (data) {
                PostMessageW(window, UPDATE_SETTINGS_CONTROL_METRICS, 0, 0);
            }
            break;
        case WM_DISPLAYCHANGE:
            if (data) {
                data->monitors = AvailableMonitors();
                PopulateMonitorList(window, *data);
                if ((data->appMode || data->previewActive) && app) {
                    SyncRuntimeSettings(*app);
                }
            }
            break;
        case WM_THEMECHANGED:
        case WM_SYSCOLORCHANGE:
            if (data) {
                PostMessageW(window, UPDATE_SETTINGS_CONTROL_METRICS, 0, 0);
                RedrawWindow(window, nullptr, nullptr, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
            }
            break;
        case ENSURE_SETTINGS_CONTROL_VISIBLE:
            if (data) {
                EnsureSettingsControlVisible(window, *data, reinterpret_cast<HWND>(wParam));
            }
            return 0;
        case RESTORE_SETTINGS_FOCUS:
            if (data) {
                if (GetActiveWindow() == window
                        && data->lastFocusedControl
                        && IsWindow(data->lastFocusedControl)
                        && IsChild(window, data->lastFocusedControl)
                        && IsWindowVisible(data->lastFocusedControl)
                        && IsWindowEnabled(data->lastFocusedControl)) {
                    HWND focused = GetFocus();
                    if (!focused || !IsChild(window, focused)) {
                        SetFocus(data->lastFocusedControl);
                        const WPARAM showKeyboardCues = MAKEWPARAM(UIS_CLEAR, UISF_HIDEFOCUS | UISF_HIDEACCEL);
                        SendMessageW(window, WM_CHANGEUISTATE, showKeyboardCues, 0);
                        SendMessageW(data->lastFocusedControl, WM_UPDATEUISTATE, showKeyboardCues, 0);
                        RedrawWindow(data->lastFocusedControl, nullptr, nullptr,
                            RDW_INVALIDATE | RDW_UPDATENOW | RDW_ALLCHILDREN);
                    }
                }
            }
            return 0;
        case WM_ACTIVATE:
            if (data) {
                if (LOWORD(wParam) == WA_INACTIVE) {
                    HWND focused = GetFocus();
                    if (focused && IsChild(window, focused)) {
                        data->lastFocusedControl = focused;
                    }
                } else if (data->lastFocusedControl) {
                    PostMessageW(window, RESTORE_SETTINGS_FOCUS, 0, 0);
                }
            }
            break;
        case WM_WINDOWPOSCHANGED:
            if (data) {
                if (data->appMode) {
                    UpdateControlWindowTopmost(window);
                    UpdateScreenSaverInhibition();
                }
            }
            break;
        case WM_SIZE:
            if (data) {
                if (wParam != SIZE_MINIMIZED) {
                    LayoutSettingsContent(window, *data);
                    UpdateSettingsScrollBars(window, *data, false);
                }
            }
            return 0;
        case WM_TIMER:
            if (wParam == ID_SCREEN_SAVER_CHECK_TIMER) {
                UpdateScreenSaverInhibition();
                return 0;
            }
            if (wParam == ID_STATUS_RESET_TIMER) {
                KillTimer(window, ID_STATUS_RESET_TIMER);
                RestoreCurrentStatus();
                return 0;
            }
            if (wParam == ID_INSTALL_POLL_TIMER && app && app->installProcess) {
                DWORD exitCode = STILL_ACTIVE;
                if (GetExitCodeProcess(app->installProcess, &exitCode) && exitCode == STILL_ACTIVE) {
                    return 0;
                }
                KillTimer(window, ID_INSTALL_POLL_TIMER);
                const bool uninstalling = app->uninstallingScreenSaver;
                CloseHandle(app->installProcess);
                app->installProcess = nullptr;
                app->uninstallingScreenSaver = false;
                EnableWindow(GetDlgItem(controls, ID_INSTALL), TRUE);
                if (data) {
                    SetDlgItemTextW(controls, ID_INSTALL, IsScreenSaverInstalled()
                        ? UninstallScreenSaverText(data->language)
                        : Text(data->language).installScreenSaver);
                    AssignSettingsMnemonics(window);
                    UpdateSettingsTextControlLayout(window);
                }
                if (uninstalling && exitCode != 0) {
                    const std::wstring failure = UninstallationFailureStatus(ActiveLanguage());
                    ShowTransientStatus(failure.c_str());
                } else if (uninstalling) {
                    ShowTransientStatus(UninstallationSucceededText(ActiveLanguage()));
                } else if (exitCode == 0) {
                    ShowTransientStatus(Text(ActiveLanguage()).installationSucceeded);
                } else {
                    ShowTransientStatus(Text(ActiveLanguage()).installationFailed);
                }
                return 0;
            }
            break;
        case WM_HSCROLL:
            if (data) {
                if (lParam == 0 && ScrollSettingsWindow(window, *data, SB_HORZ, LOWORD(wParam))) {
                    return 0;
                }
                if (data->settings && !data->updating && lParam != 0) {
                    const HWND slider = reinterpret_cast<HWND>(lParam);
                    const int id = GetDlgCtrlID(slider);
                    for (const AnimationSliderControl& control : ANIMATION_SLIDERS) {
                        if (control.id == id) {
                            const auto value = static_cast<std::uint32_t>(SendMessageW(slider, TBM_GETPOS, 0, 0));
                            SetSelectedMonitorValue(window, *data, control.property, value,
                                LOWORD(wParam) == TB_ENDTRACK);
                            break;
                        }
                    }
                }
            }
            return 0;
        case WM_VSCROLL:
            if (data) {
                if (lParam == 0 && ScrollSettingsWindow(window, *data, SB_VERT, LOWORD(wParam))) {
                    return 0;
                }
            }
            break;
        case WM_MOUSEWHEEL:
            if (data) {
                if (ScrollSettingsWheel(window, *data, wParam)) {
                    return 0;
                }
            }
            break;
        case WM_COMMAND:
            if (data) {
                if (LOWORD(wParam) == ID_LANGUAGE && HIWORD(wParam) == CBN_DROPDOWN) {
                    UpdateComboBoxDropDownSize(reinterpret_cast<HWND>(lParam));
                    return 0;
                }
                if (LOWORD(wParam) == ID_CANCEL && data->appMode) {
                    SendMessageW(window, WM_CLOSE, 0, 0);
                    return 0;
                }
                if (LOWORD(wParam) == ID_HELP) {
                    ShowInformationWindow(window, true, data->language, data->appMode);
                    return 0;
                }
                if (LOWORD(wParam) == ID_ABOUT) {
                    ShowInformationWindow(window, false, data->language, data->appMode);
                    return 0;
                }
                if (LOWORD(wParam) == ID_PREVIEW_TOGGLE && data->screenSaverSettings) {
                    if (data->previewActive) {
                        StopSettingsPreview(window, *data);
                    } else {
                        StartSettingsPreview(window, *data);
                    }
                    ApplyLocalizedCaptions(window, *data);
                    return 0;
                }
                if (LOWORD(wParam) == ID_LANGUAGE && HIWORD(wParam) == CBN_SELCHANGE && !data->updating) {
                    data->language = LanguageAtIndex(static_cast<int>(SendDlgItemMessageW(controls, ID_LANGUAGE,
                        CB_GETCURSEL, 0, 0)));
                    data->settings->language = static_cast<int>(data->language);
                    ApplyLocalizedCaptions(window, *data);
                    if (data->appMode) {
                        data->settings->Save();
                    }
                    return 0;
                }
                if (data->settings && !data->updating && HIWORD(wParam) == BN_CLICKED
                        && HandleAnimationSettingsCommand(window, *data, LOWORD(wParam))) {
                    return 0;
                }
                if (data->appMode && app) {
                    switch (LOWORD(wParam)) {
                        case ID_PREVENT_SCREEN_SAVER:
                            if (data->settings) {
                                data->settings->preventScreenSaver = SendDlgItemMessageW(controls,
                                    ID_PREVENT_SCREEN_SAVER, BM_GETCHECK, 0, 0) == BST_CHECKED;
                                data->settings->Save();
                                UpdateScreenSaverInhibition();
                            }
                            return 0;
                        case ID_RECORD_TOGGLE:
                            if (PrimaryIsRecording()) {
                                StopRecording();
                            } else {
                                StartRecording(window);
                            }
                            return 0;
                        case ID_PAUSE:
                            app->paused.store(!app->paused.load(std::memory_order_relaxed), std::memory_order_relaxed);
                            SetDlgItemTextW(controls, ID_PAUSE, app->paused.load(std::memory_order_relaxed)
                                ? Text(data->language).resume
                                : Text(data->language).pause);
                            RestoreCurrentStatus();
                            return 0;
                        case ID_INSTALL:
                            RequestScreenSaverChange(window);
                            return 0;
                        case ID_SNAPSHOT:
                            SaveSnapshot(window);
                            return 0;
                        case ID_RECORDING_SETTINGS:
                            ShowRecordingSettings(window, *data);
                            return 0;
                    }
                }
                if (LOWORD(wParam) == ID_OK && data->settings) {
                    SaveControlWindowPosition(window, data);
                    data->settings->Save();
                    data->completed = true;
                    StopSettingsPreview(window, *data);
                    DestroyWindow(window);
                    return 0;
                }
                if (LOWORD(wParam) == ID_CANCEL && data->settings) {
                    SaveControlWindowPosition(window, data);
                    RestoreOriginalSettings(*data);
                    data->settings->Save();
                    StopSettingsPreview(window, *data);
                    DestroyWindow(window);
                    return 0;
                }
            }
            break;
        case WM_NOTIFY:
            if (data) {
                const NMHDR* notification = reinterpret_cast<NMHDR*>(lParam);
                if (notification->code == NM_CUSTOMDRAW && MixedControls::IsMixed(notification->hwndFrom)) {
                    return MixedControls::CustomDraw(*reinterpret_cast<const NMCUSTOMDRAW*>(lParam));
                }
                for (const AnimationSliderControl& control : ANIMATION_SLIDERS) {
                    if (notification->idFrom != static_cast<UINT_PTR>(control.id)) {
                        continue;
                    }
                    if (notification->code == NM_CLICK
                            && data->settings
                            && !data->updating
                            && MixedControls::IsMixed(notification->hwndFrom)) {
                        const auto value =
                            static_cast<std::uint32_t>(SendMessageW(notification->hwndFrom, TBM_GETPOS, 0, 0));
                        SetSelectedMonitorValue(window, *data, control.property, value);
                        return 0;
                    }
                    break;
                }
            }
            if (reinterpret_cast<NMHDR*>(lParam)->idFrom == ID_MONITOR_LIST
                    && reinterpret_cast<NMHDR*>(lParam)->code == NM_CUSTOMDRAW) {
                NMLVCUSTOMDRAW* customDraw = reinterpret_cast<NMLVCUSTOMDRAW*>(lParam);
                if (customDraw->nmcd.dwDrawStage == CDDS_PREPAINT) {
                    return CDRF_NOTIFYPOSTPAINT;
                }
                if (customDraw->nmcd.dwDrawStage == CDDS_POSTPAINT) {
                    HWND list = customDraw->nmcd.hdr.hwndFrom;
                    if (GetFocus() == list && (SendMessageW(list, WM_QUERYUISTATE, 0, 0) & UISF_HIDEFOCUS) == 0) {
                        const int item = ListView_GetNextItem(list, -1, LVNI_FOCUSED);
                        RECT itemRect{};
                        RECT clientRect{};
                        const bool canDrawFocusRect = item >= 0
                            && ListView_GetItemRect(list, item, &itemRect, LVIR_BOUNDS)
                            && GetClientRect(list, &clientRect);
                        if (canDrawFocusRect) {
                            itemRect.left = clientRect.left + 1;
                            itemRect.right = clientRect.right - 1;
                            DrawFocusRect(customDraw->nmcd.hdc, &itemRect);
                        }
                    }
                    return CDRF_DODEFAULT;
                }
            }
            if (data) {
                if (data->settings && reinterpret_cast<NMHDR*>(lParam)->idFrom == ID_MONITOR_LIST) {
                    if (reinterpret_cast<NMHDR*>(lParam)->code == LVN_COLUMNCLICK) {
                        const NMLISTVIEW* click = reinterpret_cast<NMLISTVIEW*>(lParam);
                        SortMonitorListByColumn(click->hdr.hwndFrom, *data, click->iSubItem);
                        return 0;
                    }
                    if (data->appMode && reinterpret_cast<NMHDR*>(lParam)->code == NM_DBLCLK) {
                        const NMITEMACTIVATE* click = reinterpret_cast<NMITEMACTIVATE*>(lParam);
                        if (click->iItem >= 0) {
                            HWND list = GetDlgItem(controls, ID_MONITOR_LIST);
                            const bool checked = ListView_GetCheckState(list, click->iItem) != FALSE;
                            if (!checked || !IsRecordingMonitorRow(list, *data, click->iItem)) {
                                ListView_SetCheckState(list, click->iItem, !checked);
                            }
                        }
                        return 0;
                    }
                    if (reinterpret_cast<NMHDR*>(lParam)->code == LVN_ITEMCHANGING) {
                        const NMLISTVIEW* change = reinterpret_cast<NMLISTVIEW*>(lParam);
                        if (ShouldPreventMonitorUncheck(*change, *data)) {
                            return TRUE;
                        }
                    }
                    if (reinterpret_cast<NMHDR*>(lParam)->code == LVN_ITEMCHANGED) {
                        const NMLISTVIEW* change = reinterpret_cast<NMLISTVIEW*>(lParam);
                        if (ShouldPreventMonitorUncheck(*change, *data)) {
                            RestoreRecordingMonitorCheckState(change->hdr.hwndFrom, *data);
                        }
                        const bool stateImageChanged = data->appMode
                            && !data->updating
                            && (change->uChanged & LVIF_STATE) != 0
                            && ((change->uOldState ^ change->uNewState) & LVIS_STATEIMAGEMASK) != 0;
                        if (stateImageChanged) {
                            HWND list = GetDlgItem(controls, ID_MONITOR_LIST);
                            const std::vector<std::size_t> selected = CheckedMonitorIndices(list, *data);
                            data->settings->animationMonitorDevice = selected.empty()
                                ? NO_ANIMATION_MONITORS
                                : JoinMonitorDevices(data->monitors, selected);
                            if (data->appMode) {
                                data->settings->Save();
                                ApplyAnimationMonitors();
                            }
                        }
                        const bool selectionChanged = !data->updating
                            && (change->uChanged & LVIF_STATE) != 0
                            && ((change->uOldState ^ change->uNewState) & LVIS_SELECTED) != 0;
                        if (selectionChanged) {
                            ScheduleMonitorAnimationControlsUpdate(window, *data);
                        }
                    }
                }
            }
            break;
        case WM_EXITSIZEMOVE:
            SaveControlWindowPosition(window, data);
            return 0;
        case WM_SYSCOMMAND:
            if ((wParam & 0xFFF0) == SC_SCREENSAVE && ShouldInhibitScreenSaver()) {
                return 0;
            }
            break;
        case WM_CLOSE:
            if (data) {
                if (data->appMode) {
                    SaveControlWindowPosition(window, data);
                    data->settings->Save();
                    CloseApplication();
                    return 0;
                }
                if (data->settings) {
                    SaveControlWindowPosition(window, data);
                    RestoreOriginalSettings(*data);
                    data->settings->Save();
                }
                StopSettingsPreview(window, *data);
            }
            DestroyWindow(window);
            return 0;
        case WM_NCDESTROY:
            CloseInformationWindows();
            if (data) {
                if (data->systemDialogFont) {
                    DeleteObject(data->systemDialogFont);
                    data->systemDialogFont = nullptr;
                }
            }
            break;
    }
    return DefWindowProcW(window, msg, wParam, lParam);
}

/// Processes independent dialog keys only when that window owns the keyboard focus.
static bool HandleInformationDialogMessage(MSG& msg) {
    HWND focusedWindow = GetAncestor(GetFocus(), GA_ROOT);
    if (helpWindow != nullptr && focusedWindow == helpWindow && IsDialogMessageW(helpWindow, &msg)) {
        return true;
    }
    if (aboutWindow != nullptr && focusedWindow == aboutWindow && IsDialogMessageW(aboutWindow, &msg)) {
        return true;
    }
    if (recordingSettingsWindow != nullptr
            && focusedWindow == recordingSettingsWindow
            && IsDialogMessageW(recordingSettingsWindow, &msg)) {
        return true;
    }
    return false;
}

/// Runs the modal-style screen-saver settings window and commits on OK.
static bool ShowSettings(HINSTANCE instance, HWND owner, AppSettings& settings) {
    std::unique_ptr<SettingsWindowData> data = std::make_unique<SettingsWindowData>();
    data->monitors = AvailableMonitors();
    InitializeMonitorAnimations(settings, data->monitors);
    data->original = settings;
    data->settings = &settings;
    data->screenSaverSettings = IsScrExecutable();
    data->language = ResolvedLanguage(settings);
    MONITORINFO monitorInfo{};
    monitorInfo.cbSize = sizeof(monitorInfo);
    const POINT origin{ 0, 0 };
    GetMonitorInfoW(owner
        ? MonitorFromWindow(owner, MONITOR_DEFAULTTOPRIMARY)
        : MonitorFromPoint(origin, MONITOR_DEFAULTTOPRIMARY), &monitorInfo);
    RECT area = monitorInfo.rcWork;
    if (settings.controlWindowX != std::numeric_limits<int>::min()
            && settings.controlWindowY != std::numeric_limits<int>::min()) {
        RECT saved{
            settings.controlWindowX,
            settings.controlWindowY,
            settings.controlWindowX + SETTINGS_WIDTH,
            settings.controlWindowY + SCREEN_SAVER_SETTINGS_HEIGHT
        };
        const HMONITOR savedMonitor = MonitorFromRect(&saved, MONITOR_DEFAULTTONULL);
        if (savedMonitor) {
            MONITORINFO savedInfo{};
            savedInfo.cbSize = sizeof(savedInfo);
            if (GetMonitorInfoW(savedMonitor, &savedInfo)) {
                area = savedInfo.rcWork;
            }
        }
    }
    const DWORD extendedStyle = WS_EX_DLGMODALFRAME | WS_EX_CONTROLPARENT;
    const SettingsWindowLayout layout = GetSettingsWindowLayout(false, extendedStyle, area);
    data->contentWidth = layout.contentWidth;
    data->contentHeight = layout.contentHeight;
    data->scrollStyle = layout.scrollStyle;
    if (owner) {
        EnableWindow(owner, FALSE);
    }
    HWND window = CreateWindowExW(extendedStyle, SETTINGS_CLASS, Text(data->language).settingsTitle, layout.style,
        CW_USEDEFAULT, CW_USEDEFAULT, layout.width, layout.height, owner, nullptr, instance, data.get());
    if (!window) {
        if (owner) {
            EnableWindow(owner, TRUE);
        }
        return false;
    }
    RECT bounds{};
    GetWindowRect(window, &bounds);
    const int width = bounds.right - bounds.left;
    const int height = bounds.bottom - bounds.top;
    int x = area.left + (area.right - area.left - width) / 2;
    int y = area.top + (area.bottom - area.top - height) / 2;
    if (settings.controlWindowX != std::numeric_limits<int>::min()
            && settings.controlWindowY != std::numeric_limits<int>::min()) {
        x = std::clamp(settings.controlWindowX, static_cast<int>(area.left), std::max(static_cast<int>(area.left),
            static_cast<int>(area.right) - width));
        y = std::clamp(settings.controlWindowY, static_cast<int>(area.top), std::max(static_cast<int>(area.top),
            static_cast<int>(area.bottom) - height));
    }
    SetWindowPos(window, HWND_TOP, x, y, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);
    MSG msg{};
    while (IsWindow(window) && GetMessageW(&msg, nullptr, 0, 0) > 0) {
        if (HandleInformationDialogMessage(msg)) {
            continue;
        }
        if (msg.message == WM_KEYDOWN
                && msg.wParam == VK_TAB
                && GetKeyState(VK_CONTROL) >= 0
                && MessageTargetsWindow(msg, window)
                && MoveSettingsTabFocus(window, *data, (GetKeyState(VK_SHIFT) & 0x8000) != 0)) {
            continue;
        }
        if (!IsDialogMessageW(window, &msg)) {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }
    if (owner) {
        EnableWindow(owner, TRUE);
    }
    if (owner) {
        SetForegroundWindow(owner);
    }
    return data->completed;
}

/// Reconciles checked monitors without replacing unaffected surfaces or the active recording source.
static void ApplyAnimationMonitors() {
    if (!app || app->mode != RunMode::Application) {
        return;
    }
    const std::vector<DisplayMonitor> monitors = AvailableMonitors();
    if (monitors.empty()) {
        return;
    }
    std::vector<std::size_t> requested = SelectedMonitorIndices(monitors, app->settings.animationMonitorDevice);
    const bool noMonitors = NoAnimationMonitorsSelected(app->settings.animationMonitorDevice);
    if (requested.empty() && !noMonitors) {
        requested.push_back(PreferredMonitorIndex(monitors, app->settings.animationMonitorDevice));
    }
    RenderSurface* recording = RecordingSurface();
    if (recording) {
        const std::size_t index = MonitorIndexForDevice(monitors, recording->monitorDevice);
        if (index < monitors.size() && std::find(requested.begin(), requested.end(), index) == requested.end()) {
            requested.push_back(index);
        }
    }
    std::sort(requested.begin(), requested.end());
    for (std::size_t index = 0; index < app->surfaces.size();) {
        RenderSurface& surface = *app->surfaces[index];
        const std::size_t monitor = MonitorIndexForDevice(monitors, surface.monitorDevice);
        const bool keep = &surface == recording
            || monitor < monitors.size()
            && std::find(requested.begin(), requested.end(), monitor) != requested.end()
            && EqualRect(&surface.bounds, &monitors[monitor].rect);
        if (keep) {
            index++;
            continue;
        }
        StopRenderSurface(surface);
        if (surface.window) {
            DestroyWindow(surface.window);
        }
        app->surfaces.erase(app->surfaces.begin() + static_cast<std::ptrdiff_t>(index));
    }
    std::vector<std::size_t> created;
    for (const std::size_t index : requested) {
        if (index < monitors.size() && (MonitorSurface(monitors[index].device)
            || AddRenderSurface(*app, monitors[index].rect, nullptr, static_cast<unsigned>(index + 1),
                monitors[index].device))) {
            created.push_back(index);
        }
    }
    if (app->surfaces.empty() && !requested.empty()) {
        const std::size_t fallback = PreferredMonitorIndex(monitors, L"");
        if (AddRenderSurface(*app, monitors[fallback].rect, nullptr, static_cast<unsigned>(fallback + 1),
            monitors[fallback].device)) {
            created.push_back(fallback);
        }
    }
    for (std::size_t index = 0; index < created.size(); index++) {
        for (std::size_t surface = index; surface < app->surfaces.size(); surface++) {
            if (_wcsicmp(app->surfaces[surface]->monitorDevice.c_str(), monitors[created[index]].device.c_str()) == 0) {
                std::swap(app->surfaces[index], app->surfaces[surface]);
                break;
            }
        }
    }
    app->settings.animationMonitorDevice = created.empty()
        ? NO_ANIMATION_MONITORS
        : JoinMonitorDevices(monitors, created);
    if (recording && !MonitorDeviceSelected(app->settings.animationMonitorDevice, recording->monitorDevice)) {
        app->settings.animationMonitorDevice = created.empty()
            ? recording->monitorDevice
            : app->settings.animationMonitorDevice + L';' + recording->monitorDevice;
    }
    app->settings.Save();
    app->refreshRate = 0;
    for (const std::unique_ptr<RenderSurface>& surface : app->surfaces) {
        app->refreshRate = std::max(app->refreshRate, surface->refreshRate);
    }
    if (app->refreshRate == 0) {
        app->refreshRate = 60;
    }
    UpdateRecordingButton();
    RestoreCurrentStatus();
    UpdateControlWindowTopmost(app->controlWindow);
    SetForegroundWindow(app->controlWindow);
}

/// Creates the modeless standalone control window and transfers its state ownership.
static HWND CreateApplicationWindow(Application& app, SettingsWindowData*& data) {
    data = new SettingsWindowData{};
    data->original = app.settings;
    data->settings = &app.settings;
    data->monitors = AvailableMonitors();
    data->appMode = true;
    data->language = ResolvedLanguage(app.settings);
    MONITORINFO primary{};
    primary.cbSize = sizeof(primary);
    const POINT origin{ 0, 0 };
    GetMonitorInfoW(MonitorFromPoint(origin, MONITOR_DEFAULTTOPRIMARY), &primary);
    RECT area = primary.rcWork;
    if (app.settings.controlWindowX != std::numeric_limits<int>::min()
            && app.settings.controlWindowY != std::numeric_limits<int>::min()) {
        RECT saved{
            app.settings.controlWindowX,
            app.settings.controlWindowY,
            app.settings.controlWindowX + SETTINGS_WIDTH,
            app.settings.controlWindowY + APPLICATION_SETTINGS_HEIGHT
        };
        const HMONITOR savedMonitor = MonitorFromRect(&saved, MONITOR_DEFAULTTONULL);
        if (savedMonitor) {
            MONITORINFO savedInfo{};
            savedInfo.cbSize = sizeof(savedInfo);
            if (GetMonitorInfoW(savedMonitor, &savedInfo)) {
                area = savedInfo.rcWork;
            }
        }
    }
    const DWORD extendedStyle = WS_EX_CONTROLPARENT;
    const SettingsWindowLayout layout = GetSettingsWindowLayout(true, extendedStyle, area);
    data->contentWidth = layout.contentWidth;
    data->contentHeight = layout.contentHeight;
    data->scrollStyle = layout.scrollStyle;
    int x = std::min(static_cast<int>(area.left) + 24, std::max(static_cast<int>(area.left),
        static_cast<int>(area.right) - layout.width));
    int y = std::min(static_cast<int>(area.top) + 24, std::max(static_cast<int>(area.top),
        static_cast<int>(area.bottom) - layout.height));
    if (app.settings.controlWindowX != std::numeric_limits<int>::min()
            && app.settings.controlWindowY != std::numeric_limits<int>::min()) {
        x = std::clamp(app.settings.controlWindowX, static_cast<int>(area.left), std::max(static_cast<int>(area.left),
            static_cast<int>(area.right) - layout.width));
        y = std::clamp(app.settings.controlWindowY, static_cast<int>(area.top), std::max(static_cast<int>(area.top),
            static_cast<int>(area.bottom) - layout.height));
    }
    HWND window = CreateWindowExW(extendedStyle, SETTINGS_CLASS, Text(data->language).controlTitle,
        layout.style | WS_VISIBLE, x, y, layout.width, layout.height, nullptr, nullptr, app.instance, data);
    if (!window) {
        delete data;
        data = nullptr;
    }
    return window;
}

/// Writes and verifies the embedded screen-saver file in the native system directory.
static bool WriteScreenSaverFile(const std::wstring& destination, const std::wstring& staging, const void* bytes,
        DWORD resourceSize) {
    const Wow64Redirection wow64Redirection;
    DeleteFileW(staging.c_str());
    const HANDLE file = CreateFileW(staging.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL,
        nullptr);
    if (file == INVALID_HANDLE_VALUE) {
        return false;
    }
    DWORD written = 0;
    const bool saved = WriteFile(file, bytes, resourceSize, &written, nullptr)
        && written == resourceSize
        && FlushFileBuffers(file);
    CloseHandle(file);
    if (!saved) {
        DeleteFileW(staging.c_str());
        return false;
    }
    const DWORD destinationAttributes = GetFileAttributesW(destination.c_str());
    if (destinationAttributes != INVALID_FILE_ATTRIBUTES && (destinationAttributes & FILE_ATTRIBUTE_READONLY) != 0) {
        SetFileAttributesW(destination.c_str(), destinationAttributes & ~FILE_ATTRIBUTE_READONLY);
    }
    if (!MoveFileExW(staging.c_str(), destination.c_str(),
        MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH)) {
        DeleteFileW(staging.c_str());
        return false;
    }
    WIN32_FILE_ATTRIBUTE_DATA installedFile{};
    return GetFileAttributesExW(destination.c_str(), GetFileExInfoStandard, &installedFile)
        && installedFile.nFileSizeHigh == 0
        && installedFile.nFileSizeLow == resourceSize;
}

/// Removes the installed screen-saver file from the native system directory.
static bool DeleteScreenSaverFile(const std::wstring& destination) {
    const Wow64Redirection wow64Redirection;
    DeleteFileW((destination + STAGING_FILE_SUFFIX).c_str());
    const DWORD attributes = GetFileAttributesW(destination.c_str());
    if (attributes == INVALID_FILE_ATTRIBUTES) {
        return true;
    }
    if ((attributes & FILE_ATTRIBUTE_DIRECTORY) != 0) {
        return false;
    }
    if ((attributes & FILE_ATTRIBUTE_READONLY) != 0) {
        SetFileAttributesW(destination.c_str(), attributes & ~FILE_ATTRIBUTE_READONLY);
    }
    return DeleteFileW(destination.c_str()) != FALSE;
}

/// Installs the embedded SCR atomically and selects it for the current user.
static bool InstallScreenSaverElevated() {
    const std::wstring destination = ScreenSaverDestinationPath();
    if (destination.empty()) {
        return false;
    }
    const std::wstring staging = destination + STAGING_FILE_SUFFIX;
    const HRSRC resource =
        FindResourceW(GetModuleHandleW(nullptr), MAKEINTRESOURCEW(IDR_EMBEDDED_SCREEN_SAVER), RT_RCDATA);
    if (!resource) {
        return false;
    }
    const DWORD resourceSize = SizeofResource(GetModuleHandleW(nullptr), resource);
    const HGLOBAL loaded = LoadResource(GetModuleHandleW(nullptr), resource);
    const void* bytes = loaded ? LockResource(loaded) : nullptr;
    if (!bytes || resourceSize == 0) {
        return false;
    }
    if (!WriteScreenSaverFile(destination, staging, bytes, resourceSize)) {
        return false;
    }
    HKEY key = nullptr;
    const LSTATUS createResult =
        RegCreateKeyExW(HKEY_CURRENT_USER, DESKTOP_REGISTRY_PATH, 0, nullptr, 0, KEY_WRITE, nullptr, &key, nullptr);
    if (createResult != ERROR_SUCCESS) {
        return false;
    }
    const LONG pathResult = RegSetValueExW(key, SCREEN_SAVER_PATH_VALUE_NAME, 0, REG_SZ,
        reinterpret_cast<const BYTE*>(destination.c_str()),
        static_cast<DWORD>((destination.size() + 1) * sizeof(wchar_t)));
    constexpr wchar_t active[] = L"1";
    const LONG activeResult = RegSetValueExW(key, SCREEN_SAVER_ACTIVE_VALUE_NAME, 0, REG_SZ,
        reinterpret_cast<const BYTE*>(active), sizeof(active));
    RegCloseKey(key);
    if (pathResult != ERROR_SUCCESS || activeResult != ERROR_SUCCESS) {
        return false;
    }
    SystemParametersInfoW(SPI_SETSCREENSAVEACTIVE, TRUE, nullptr, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
    SendMessageTimeoutW(HWND_BROADCAST, WM_SETTINGCHANGE, 0, reinterpret_cast<LPARAM>(DESKTOP_REGISTRY_PATH),
        SMTO_ABORTIFHUNG, 1000, nullptr);
    RemoveLegacyScreenSaverCopies();
    return true;
}

/// Removes the canonical SCR and clears selection only when it points to this product.
static bool UninstallScreenSaverElevated() {
    const std::wstring destination = ScreenSaverDestinationPath();
    if (destination.empty()) {
        return false;
    }
    if (!DeleteScreenSaverFile(destination)) {
        return false;
    }
    HKEY key = nullptr;
    const LONG openResult = RegOpenKeyExW(HKEY_CURRENT_USER, DESKTOP_REGISTRY_PATH, 0,
        KEY_QUERY_VALUE | KEY_SET_VALUE, &key);
    if (openResult == ERROR_FILE_NOT_FOUND) {
        return true;
    }
    if (openResult != ERROR_SUCCESS) {
        return false;
    }
    std::vector<wchar_t> selectedPath(32768, L'\0');
    DWORD type = 0;
    DWORD size = static_cast<DWORD>(selectedPath.size() * sizeof(wchar_t));
    const LONG queryResult = RegQueryValueExW(key, SCREEN_SAVER_PATH_VALUE_NAME, nullptr, &type,
        reinterpret_cast<BYTE*>(selectedPath.data()), &size);
    bool selected = false;
    if (queryResult == ERROR_SUCCESS && (type == REG_SZ || type == REG_EXPAND_SZ)) {
        selectedPath[std::min(size / sizeof(wchar_t), static_cast<DWORD>(selectedPath.size() - 1))] = L'\0';
        selected = IsFlyingSolidsScreenSaverPath(selectedPath.data());
    } else if (queryResult != ERROR_FILE_NOT_FOUND) {
        RegCloseKey(key);
        return false;
    }
    LONG pathResult = ERROR_SUCCESS;
    LONG activeResult = ERROR_SUCCESS;
    if (selected) {
        pathResult = RegDeleteValueW(key, SCREEN_SAVER_PATH_VALUE_NAME);
        if (pathResult == ERROR_FILE_NOT_FOUND) {
            pathResult = ERROR_SUCCESS;
        }
        constexpr wchar_t inactive[] = L"0";
        activeResult = RegSetValueExW(key, SCREEN_SAVER_ACTIVE_VALUE_NAME, 0, REG_SZ,
            reinterpret_cast<const BYTE*>(inactive), sizeof(inactive));
    }
    RegCloseKey(key);
    if (pathResult != ERROR_SUCCESS || activeResult != ERROR_SUCCESS) {
        return false;
    }
    if (selected) {
        SystemParametersInfoW(SPI_SETSCREENSAVEACTIVE, FALSE, nullptr, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
        SendMessageTimeoutW(HWND_BROADCAST, WM_SETTINGCHANGE, 0, reinterpret_cast<LPARAM>(DESKTOP_REGISTRY_PATH),
            SMTO_ABORTIFHUNG, 1000, nullptr);
    }
    return true;
}

/// Starts the elevated install or uninstall helper and polls it asynchronously.
static void RequestScreenSaverChange(HWND owner) {
    if (!app || app->installProcess) {
        return;
    }
    const bool uninstall = IsScreenSaverInstalled();
    const std::wstring executable = ExecutablePath();
    SHELLEXECUTEINFOW execute{};
    execute.cbSize = sizeof(execute);
    execute.fMask = SEE_MASK_NOCLOSEPROCESS;
    execute.hwnd = owner;
    execute.lpVerb = L"runas";
    execute.lpFile = executable.c_str();
    execute.lpParameters = uninstall ? UNINSTALL_ELEVATED_ARGUMENT : INSTALL_ELEVATED_ARGUMENT;
    execute.nShow = SW_SHOWNORMAL;
    if (!ShellExecuteExW(&execute) || !execute.hProcess) {
        if (uninstall) {
            ShowTransientStatus(UninstallationFailedText(ActiveLanguage()));
        } else {
            ShowTransientStatus(Text(ActiveLanguage()).installationFailed);
        }
        return;
    }
    app->uninstallingScreenSaver = uninstall;
    app->installProcess = execute.hProcess;
    EnableWindow(GetDlgItem(SettingsContentWindow(owner), ID_INSTALL), FALSE);
    SetTimer(owner, ID_INSTALL_POLL_TIMER, 100, nullptr);
}

/// Applies the screen-saver startup grace period and mouse-motion threshold.
static bool SaverShouldExitOnMouse() {
    if (!app || app->mode != RunMode::ScreenSaver ||
        GetTickCount64() - app->saverStarted < 900) {
        return false;
    }
    POINT current{};
    GetCursorPos(&current);
    return std::abs(current.x - app->initialMouse.x) > 4 || std::abs(current.y - app->initialMouse.y) > 4;
}

/// Raises standalone animation surfaces on an explicit click without restoring the control window or forcing TopMost.
static void ActivateApplicationAnimation(HWND window) {
    if (!app || app->mode != RunMode::Application || !IsWindowVisible(window) || IsIconic(window)) {
        return;
    }
    for (const std::unique_ptr<RenderSurface>& surface : app->surfaces) {
        if (surface->window
                && surface->window != window
                && IsWindowVisible(surface->window)
                && !IsIconic(surface->window)) {
            SetWindowPos(surface->window, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
        }
    }
    SetWindowPos(window, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
    SetForegroundWindow(window);
}

/// Handles surface resize, explicit standalone activation and mode-specific animation exit controls.
static LRESULT CALLBACK RenderProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (msg == WM_NCCREATE) {
        CREATESTRUCTW* create = reinterpret_cast<CREATESTRUCTW*>(lParam);
        SetWindowLongPtrW(window, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(create->lpCreateParams));
    }
    RenderSurface* surface = reinterpret_cast<RenderSurface*>(GetWindowLongPtrW(window, GWLP_USERDATA));
    switch (msg) {
        case WM_WINDOWPOSCHANGED:
            if (app && app->mode == RunMode::Application) {
                UpdateControlWindowTopmost(app->controlWindow);
                UpdateScreenSaverInhibition();
            }
            break;
        case WM_SIZE:
            if (surface) {
                if (surface->renderer) {
                    const std::lock_guard lock(surface->rendererMutex);
                    surface->renderer->Resize(LOWORD(lParam), HIWORD(lParam));
                }
            }
            return 0;
        case WM_KEYDOWN:
            if (app) {
                if (app->mode == RunMode::ScreenSaver) {
                    CloseApplication();
                    return 0;
                }
                if (app->mode == RunMode::Application) {
                    if (wParam == VK_ESCAPE) {
                        CloseApplication();
                    } else if (wParam == VK_F9) {
                        StartRecording(app->controlWindow);
                    } else if (wParam == VK_F10) {
                        StopRecording();
                    } else if (wParam == VK_SPACE) {
                        app->paused.store(!app->paused.load(std::memory_order_relaxed), std::memory_order_relaxed);
                        RestoreCurrentStatus();
                    }
                    return 0;
                }
            }
            break;
        case WM_MOUSEMOVE:
            if (SaverShouldExitOnMouse()) {
                CloseApplication();
            }
            return 0;
        case WM_LBUTTONDOWN:
        case WM_RBUTTONDOWN:
        case WM_MBUTTONDOWN:
            if (app) {
                if (app->mode == RunMode::ScreenSaver && GetTickCount64() - app->saverStarted >= 900) {
                    CloseApplication();
                } else if (app->mode == RunMode::Application) {
                    ActivateApplicationAnimation(window);
                }
            }
            return 0;
        case WM_ACTIVATEAPP:
            if (app) {
                if (app->mode == RunMode::ScreenSaver && !wParam && GetTickCount64() - app->saverStarted >= 900) {
                    CloseApplication();
                }
            }
            return 0;
        case WM_SYSCOMMAND:
            if ((wParam & 0xFFF0) == SC_SCREENSAVE && ShouldInhibitScreenSaver()) {
                return 0;
            }
            break;
        case WM_CLOSE:
            CloseApplication();
            return 0;
        case WM_ERASEBKGND:
            return 1;
    }
    return DefWindowProcW(window, msg, wParam, lParam);
}

/// Collects raw monitor rectangles for full-screen SCR and diagnostic modes.
static BOOL CALLBACK CollectMonitor(HMONITOR, HDC, LPRECT rectangle, LPARAM parameter) {
    reinterpret_cast<std::vector<RECT>*>(parameter)->push_back(*rectangle);
    return TRUE;
}

/// Registers render, settings and information window classes.
static bool RegisterClasses(HINSTANCE instance) {
    WNDCLASSEXW render{};
    render.cbSize = sizeof(render);
    render.hInstance = instance;
    render.lpfnWndProc = RenderProc;
    render.lpszClassName = RENDER_CLASS;
    render.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    render.hIcon = app->programIcons.Large();
    render.hIconSm = app->programIcons.Small();
    render.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
    WNDCLASSEXW settings = render;
    settings.lpfnWndProc = SettingsProc;
    settings.lpszClassName = SETTINGS_CLASS;
    settings.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_BTNFACE + 1);
    return RegisterClassExW(&render) && RegisterClassExW(&settings);
}

/// Creates a render window with ownership and activation styles appropriate to its mode.
static HWND CreateRenderWindow(Application& app, RenderSurface& surface, const RECT& requestedBounds,
        HWND requestedParent = nullptr) {
    DWORD style = WS_POPUP;
    DWORD extendedStyle = 0;
    HWND parent = requestedParent;
    int x = requestedBounds.left;
    int y = requestedBounds.top;
    int width = requestedBounds.right - requestedBounds.left;
    int height = requestedBounds.bottom - requestedBounds.top;
    if (app.mode == RunMode::Preview) {
        style = WS_CHILD | WS_VISIBLE;
    } else if (app.mode == RunMode::SelfTest) {
        style = WS_POPUP;
        width = 320;
        height = 240;
    } else if (app.mode == RunMode::SelfTestAllMonitors) {
        style = WS_POPUP;
    } else {
        style |= WS_VISIBLE;
        extendedStyle |= WS_EX_TOOLWINDOW;
        if (app.mode == RunMode::ScreenSaver) {
            extendedStyle |= WS_EX_TOPMOST;
        }
        if (app.mode == RunMode::Application || app.mode == RunMode::SettingsPreview) {
            extendedStyle |= WS_EX_NOACTIVATE;
        }
    }
    return CreateWindowExW(extendedStyle, RENDER_CLASS, PRODUCT_NAME, style, x, y, width, height, parent, nullptr,
        app.instance, &surface);
}

/// Creates, initializes and starts one independent animation surface.
static bool AddRenderSurface(Application& app, const RECT& bounds, HWND parent, unsigned seed,
        const std::wstring& monitorDevice) {
    std::unique_ptr<RenderSurface> surface = std::make_unique<RenderSurface>(seed);
    surface->monitorDevice = monitorDevice;
    surface->runtimeSettings = app.settings.AnimationForMonitor(monitorDevice);
    surface->bounds = bounds;
    surface->renderer = std::make_unique<Renderer>();
    surface->window = CreateRenderWindow(app, *surface, bounds, parent);
    if (!surface->window || !surface->renderer->Initialize(surface->window)) {
        if (surface->window) {
            DestroyWindow(surface->window);
        }
        return false;
    }
    surface->refreshFrequency = CurrentRefreshRate(surface->window);
    surface->refreshRate = static_cast<unsigned>(std::lround(surface->refreshFrequency));
    RenderSurface* startedSurface = surface.get();
    app.surfaces.push_back(std::move(surface));
    StartRenderSurface(app, *startedSurface);
    return true;
}

/// Restarts detached standalone animation with the same preferred monitor selection as default startup.
static void StartDefaultApplicationAnimation(Application& application, SettingsWindowData& data) {
    if (!application.surfaces.empty()) {
        return;
    }
    application.settings.animationMonitorDevice.clear();
    ApplyAnimationMonitors();
    const bool wasUpdating = data.updating;
    data.updating = true;
    data.monitors = AvailableMonitors();
    PopulateMonitorList(application.controlWindow, data);
    data.updating = wasUpdating;
    if (application.surfaces.empty()) {
        ShowTransientStatus(Text(data.language).rendererFailed);
        return;
    }
    application.paused.store(false, std::memory_order_relaxed);
    HWND controls = SettingsContentWindow(application.controlWindow);
    const std::wstring pauseCaption = PreserveControlMnemonic(GetDlgItem(controls, ID_PAUSE), Text(data.language).pause);
    SetDlgItemTextW(controls, ID_PAUSE, pauseCaption.c_str());
    UpdateRecordingButton();
    RestoreCurrentStatus();
}

/// Handles standalone Enter with no fixed accept button and explicit Tab order before native dialog processing.
static bool HandleApplicationKeyMessage(Application& application, SettingsWindowData* appSettingsData, const MSG& msg) {
    if (msg.message == WM_KEYDOWN
            && msg.wParam == VK_RETURN
            && appSettingsData
            && MessageTargetsWindow(msg, application.controlWindow)
            && GetAncestor(GetFocus(), GA_ROOT) == application.controlWindow) {
        HWND focused = GetFocus();
        const LRESULT dialogCode = SendMessageW(focused, WM_GETDLGCODE, msg.wParam, reinterpret_cast<LPARAM>(&msg));
        const bool pushButton = (dialogCode & (DLGC_DEFPUSHBUTTON | DLGC_UNDEFPUSHBUTTON)) != 0;
        if (!pushButton && (dialogCode & DLGC_WANTALLKEYS) == 0) {
            StartDefaultApplicationAnimation(application, *appSettingsData);
            return true;
        }
    }
    if (msg.message == WM_KEYDOWN
            && msg.wParam == VK_TAB
            && GetKeyState(VK_CONTROL) >= 0
            && appSettingsData
            && MessageTargetsWindow(msg, application.controlWindow)
            && MoveSettingsTabFocus(application.controlWindow, *appSettingsData, (GetKeyState(VK_SHIFT)
                & 0x8000) != 0)) {
        return true;
    }
    return false;
}

/// Offers a msg to dialogs in order and dispatches it when none handles it.
static void DispatchApplicationMessage(Application& application, MSG& msg) {
    const bool dialogHandled = application.controlWindow && IsDialogMessageW(application.controlWindow, &msg);
    if (!dialogHandled) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
}

/// Processes at most 32 queued messages and preserves WM_QUIT handling.
static void ProcessApplicationMessages(Application& application, SettingsWindowData* appSettingsData, MSG& msg) {
    unsigned dispatchedMessages = 0;
    while (dispatchedMessages < 32 && PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            application.closing.store(true, std::memory_order_relaxed);
            break;
        }
        if (HandleInformationDialogMessage(msg)) {
            ++dispatchedMessages;
            continue;
        }
        if (HandleApplicationKeyMessage(application, appSettingsData, msg)) {
            ++dispatchedMessages;
            continue;
        }
        DispatchApplicationMessage(application, msg);
        ++dispatchedMessages;
    }
}

/// Reports whether a surface has rendered the three frames required by self-tests.
static bool HasSelfTestFrames(const std::unique_ptr<RenderSurface>& surface) {
    return surface->renderedFrames.load(std::memory_order_relaxed) >= 3;
}

/// Checks the visible pixel count while holding the surface renderer lock.
static bool IsSelfTestSurfaceEmpty(const std::unique_ptr<RenderSurface>& surface) {
    const std::lock_guard lock(surface->rendererMutex);
    return surface->renderer->LastVisiblePixelCount() == 0;
}

/// Checks a snapshot's PNG signature and closes its file handle.
static bool HasPngSignature(const wchar_t* path) {
    const HANDLE file =
        CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    unsigned char signature[8]{};
    DWORD read = 0;
    const bool saved = file != INVALID_HANDLE_VALUE
        && ReadFile(file, signature, sizeof(signature), &read, nullptr)
        && read == sizeof(signature)
        && signature[0] == 0x89
        && signature[1] == 'P'
        && signature[2] == 'N'
        && signature[3] == 'G';
    if (file != INVALID_HANDLE_VALUE) {
        CloseHandle(file);
    }
    return saved;
}

/// Saves, validates and removes a temporary snapshot of the primary self-test surface.
static bool SaveSelfTestSnapshot(Application& application) {
    wchar_t directory[MAX_PATH]{};
    wchar_t temporary[MAX_PATH]{};
    bool saved = GetTempPathW(MAX_PATH, directory) != 0 && GetTempFileNameW(directory, L"FSS", 0, temporary) != 0;
    if (saved) {
        DeleteFileW(temporary);
        const std::wstring snapshot = std::wstring(temporary) + L".png";
        saved = SaveSurfaceSnapshot(*application.surfaces.front(), snapshot.c_str());
        if (saved) {
            saved = HasPngSignature(snapshot.c_str());
        }
        DeleteFileW(snapshot.c_str());
    }
    return saved;
}

/// Completes frame and optional snapshot checks when every self-test surface is ready.
static void CompleteSelfTest(Application& application) {
    if (application.mode == RunMode::SelfTest || application.mode == RunMode::SelfTestAllMonitors) {
        const bool enoughFrames =
            std::all_of(application.surfaces.begin(), application.surfaces.end(), HasSelfTestFrames);
        if (enoughFrames) {
            application.selfTestFailed =
                std::any_of(application.surfaces.begin(), application.surfaces.end(), IsSelfTestSurfaceEmpty);
            if (!application.selfTestFailed && application.selfTestSnapshot && !application.surfaces.empty()) {
                application.selfTestFailed = !SaveSelfTestSnapshot(application);
            }
            CloseApplication();
        }
    }
}

/// Waits for queued input, polling only in automatic self-test modes.
static void WaitForApplicationMessages(Application& application) {
    if (!application.closing.load(std::memory_order_relaxed)) {
        const DWORD timeout =
            application.mode == RunMode::SelfTest || application.mode == RunMode::SelfTestAllMonitors ? 10U : INFINITE;
        MsgWaitForMultipleObjectsEx(0, nullptr, timeout, QS_ALLINPUT, MWMO_INPUTAVAILABLE);
    }
}

/// Runs message batches, self-test completion and waiting until the application closes.
static void RunApplicationMessageLoop(Application& application, SettingsWindowData* appSettingsData) {
    MSG msg{};
    while (!application.closing.load(std::memory_order_relaxed)) {
        ProcessApplicationMessages(application, appSettingsData, msg);
        if (application.closing.load(std::memory_order_relaxed)) {
            break;
        }
        CompleteSelfTest(application);
        WaitForApplicationMessages(application);
    }
}

/// Parses the invocation mode, creates requested surfaces and runs the process message loop.
int APIENTRY wWinMain(_In_ HINSTANCE instance, _In_opt_ HINSTANCE previousInstance, _In_ LPWSTR commandLineRaw,
        _In_ int showCommand) {
    UNREFERENCED_PARAMETER(previousInstance);
    UNREFERENCED_PARAMETER(showCommand);
    INITCOMMONCONTROLSEX controls{
        sizeof(controls),
        ICC_BAR_CLASSES | ICC_STANDARD_CLASSES | ICC_LISTVIEW_CLASSES | ICC_LINK_CLASS
    };
    InitCommonControlsEx(&controls);
    const std::wstring commandLine = Trim(commandLineRaw ? commandLineRaw : L"");
    std::wstring lower = commandLine;
    std::transform(lower.begin(), lower.end(), lower.begin(), towlower);
    if (lower.rfind(INSTALL_ELEVATED_ARGUMENT, 0) == 0 || lower.rfind(UNINSTALL_ELEVATED_ARGUMENT, 0) == 0) {
        const bool uninstall = lower.rfind(UNINSTALL_ELEVATED_ARGUMENT, 0) == 0;
        const bool succeeded = uninstall ? UninstallScreenSaverElevated() : InstallScreenSaverElevated();
        return succeeded ? 0 : 1;
    }
    const bool scr = IsScrExecutable();
    Application application{};
    if (!application.programIcons.Load()) {
        return 1;
    }
    application.instance = instance;
    application.settings.Load(scr ? SettingsProfile::ScreenSaver : SettingsProfile::Standalone);
    InitializeMonitorAnimations(application.settings, AvailableMonitors());
    app = &application;
    if (!RegisterClasses(instance)) {
        return 1;
    }
    if (!lower.empty() && lower[0] == L'/' && lower.size() >= 2 && lower[1] == L'c' || scr && commandLine.empty()) {
        ShowSettings(instance, nullptr, application.settings);
        return 0;
    }
    if (!lower.empty() && lower[0] == L'/' && lower.size() >= 2 && lower[1] == L'p') {
        application.mode = RunMode::Preview;
        application.previewParent = ParseParentHandle(commandLine);
        if (!IsWindow(application.previewParent)) {
            return 1;
        }
        const SettingsProfile profile = application.settings.profile;
        application.settings = AppSettings{};
        application.settings.profile = profile;
    } else if (lower == L"/test") {
        application.mode = RunMode::SelfTest;
    } else if (lower == L"/test-snapshot") {
        application.mode = RunMode::SelfTest;
        application.selfTestSnapshot = true;
    } else if (lower == L"/test-flight") {
        application.mode = RunMode::SelfTest;
        application.selfTestFlight = true;
    } else if (lower == L"/test-dense") {
        application.mode = RunMode::SelfTest;
    } else if (lower == L"/test-monitors") {
        application.mode = RunMode::SelfTestAllMonitors;
    } else if (scr || !lower.empty() && lower[0] == L'/' && lower.size() >= 2 && lower[1] == L's') {
        application.mode = RunMode::ScreenSaver;
    }
    std::unique_ptr<void, decltype(&ReleaseApplicationInstance)> instanceMutex(nullptr, ReleaseApplicationInstance);
    if (application.mode == RunMode::Application) {
        bool primary = false;
        HANDLE mutex = AcquireApplicationInstance(primary);
        if (!mutex) {
            return 1;
        }
        if (!primary) {
            const bool activated = ActivateExistingApplication();
            CloseHandle(mutex);
            return activated ? 0 : 1;
        }
        instanceMutex.reset(mutex);
    }
    if (application.mode == RunMode::SelfTest || application.mode == RunMode::SelfTestAllMonitors) {
        application.settings.monitorAnimations.clear();
        InitializeMonitorAnimations(application.settings, AvailableMonitors());
        if (application.mode == RunMode::SelfTest) {
            MonitorAnimation& animation = application.settings.AnimationForMonitor(L"");
            animation.cameraFlight = application.selfTestFlight || lower == L"/test-dense";
            if (lower == L"/test-dense") {
                animation.objectSpeedPercent = 1600;
                animation.cameraSpeedPercent = 1600;
                animation.copyCount = static_cast<int>(MAX_COPIES_PER_SOLID);
            }
        }
    }
    SyncRuntimeSettings(application);
    bool surfacesCreated = true;
    SettingsWindowData* appSettingsData = nullptr;
    if (application.mode == RunMode::Application) {
        application.controlWindow = CreateApplicationWindow(application, appSettingsData);
        if (!application.controlWindow) {
            return 1;
        }
        SetForegroundWindow(application.controlWindow);
        const std::vector<DisplayMonitor> monitors = AvailableMonitors();
        if (monitors.empty()) {
            if (!NoAnimationMonitorsSelected(application.settings.animationMonitorDevice)) {
                const RECT animationBounds{ 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };
                surfacesCreated = AddRenderSurface(application, animationBounds, nullptr, 0);
            }
        } else {
            std::vector<std::size_t> selected =
                SelectedMonitorIndices(monitors, application.settings.animationMonitorDevice);
            if (selected.empty() && !NoAnimationMonitorsSelected(application.settings.animationMonitorDevice)) {
                selected.push_back(PreferredMonitorIndex(monitors, application.settings.animationMonitorDevice));
            }
            application.settings.animationMonitorDevice = selected.empty()
                ? NO_ANIMATION_MONITORS
                : JoinMonitorDevices(monitors, selected);
            for (const std::size_t index : selected) {
                if (!AddRenderSurface(application, monitors[index].rect, nullptr,
                    static_cast<unsigned>(index + 1), monitors[index].device)) {
                    surfacesCreated = false;
                    break;
                }
            }
        }
    } else if (application.mode == RunMode::Preview) {
        RECT bounds{};
        GetClientRect(application.previewParent, &bounds);
        surfacesCreated = AddRenderSurface(application, bounds, application.previewParent, 0);
    } else if (application.mode == RunMode::ScreenSaver || application.mode == RunMode::SelfTestAllMonitors) {
        const std::vector<DisplayMonitor> monitors = AvailableMonitors();
        if (monitors.empty()) {
            const RECT bounds{ 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };
            surfacesCreated = AddRenderSurface(application, bounds, nullptr, 0);
        }
        for (std::size_t index = 0; index < monitors.size(); index++) {
            if (!AddRenderSurface(application, monitors[index].rect, nullptr,
                static_cast<unsigned>(index + 1), monitors[index].device)) {
                surfacesCreated = false;
                break;
            }
        }
    } else if (application.mode == RunMode::SelfTest) {
        surfacesCreated = AddRenderSurface(application, RECT{ 0, 0, 320, 240 }, nullptr, 0);
    }
    if (!surfacesCreated || application.surfaces.empty() && application.mode != RunMode::Application) {
        StopAllRenderSurfaces(application);
        for (std::unique_ptr<RenderSurface>& surface : application.surfaces) {
            if (surface->window) {
                DestroyWindow(surface->window);
            }
        }
        MessageBoxW(nullptr, Text(ActiveLanguage()).rendererFailed, PRODUCT_NAME, MB_OK | MB_ICONERROR);
        delete appSettingsData;
        return 1;
    }
    application.refreshRate = 0;
    for (const std::unique_ptr<RenderSurface>& surface : application.surfaces) {
        application.refreshRate = std::max(application.refreshRate, surface->refreshRate);
    }
    if (application.refreshRate == 0) {
        application.refreshRate = 60;
    }
    if (application.mode == RunMode::Application) {
        UpdateControlWindowTopmost(application.controlWindow);
        SetForegroundWindow(application.controlWindow);
    } else if (application.mode == RunMode::ScreenSaver) {
        GetCursorPos(&application.initialMouse);
        application.saverStarted = GetTickCount64();
        ShowCursor(FALSE);
        SetForegroundWindow(application.surfaces.front()->window);
    }
    RunApplicationMessageLoop(application, appSettingsData);
    ReleaseScreenSaverInhibition(application);
    StopAllRenderSurfaces(application);
    for (std::unique_ptr<RenderSurface>& surface : application.surfaces) {
        const std::lock_guard lock(surface->rendererMutex);
        surface->renderer->StopRecording();
    }
    if (application.installProcess) {
        CloseHandle(application.installProcess);
    }
    if (application.mode == RunMode::ScreenSaver) {
        ShowCursor(TRUE);
    }
    CloseInformationWindows();
    delete appSettingsData;
    app = nullptr;
    return application.selfTestFailed ? 2 : 0;
}
