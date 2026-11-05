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
#include "AboutForm.h"
#include "AppSettings.h"
#include "HelpForm.h"
#include "main.h"
#include "Localization.h"
#include "MonitorInfo.h"
#include "MonitorLayout.h"
#include "PackedResource.h"
#include "PatternCatalog.h"
#include "PersistWindowState.h"
#include "ProgramIcons.h"
#include "Renderer.h"
#include "SelectionEdit.h"
#include "Simulation.h"
#include "SystemDialogTemplate.h"
#include "Wow64Redirection.h"
#include "WindowRedrawScope.h"
#include "resource.h"
#include <windows.h>
#include <windowsx.h>
#include <avrt.h>
#include <bcrypt.h>
#include <commctrl.h>
#include <commdlg.h>
#include <dwmapi.h>
#include <RestartManager.h>
#include <shellapi.h>
#include <shlobj.h>
#include <usp10.h>
#include <uxtheme.h>
#include <vssym32.h>
#include <winver.h>
#include <algorithm>
#include <array>
#include <atomic>
#include <cmath>
#include <cwchar>
#include <cwctype>
#include <limits>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "comdlg32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "avrt.lib")
#pragma comment(lib, "uxtheme.lib")
#pragma comment(lib, "Version.lib")
#pragma comment(lib, "Usp10.lib")
#pragma comment(lib, "dwmapi.lib")

constexpr wchar_t PRODUCT_NAME[] = L"GameOfLife";
constexpr wchar_t SETTINGS_CLASS[] = L"FortSoft.GameOfLife.Settings";
constexpr wchar_t SCREEN_SAVER_PATH_SUFFIX[] = L"\\GameOfLife.scr";
constexpr wchar_t SCREEN_SAVER_EXTENSION[] = L".scr";
constexpr wchar_t STAGING_FILE_SUFFIX[] = L".installing";
constexpr wchar_t INSTALL_ELEVATED_ARGUMENT[] = L"/install-elevated";
constexpr wchar_t UNINSTALL_ELEVATED_ARGUMENT[] = L"/uninstall-elevated";
constexpr wchar_t DESKTOP_REGISTRY_PATH[] = L"Control Panel\\Desktop";
constexpr wchar_t SCREEN_SAVER_PATH_VALUE_NAME[] = L"SCRNSAVE.EXE";
constexpr wchar_t SCREEN_SAVER_ACTIVE_VALUE_NAME[] = L"ScreenSaveActive";
constexpr wchar_t RENDER_CLASS[] = L"FortSoft.GameOfLife.Render";
constexpr wchar_t INSTANCE_MUTEX[] = L"Local\\FortSoft.GameOfLife.Standalone";
constexpr wchar_t INSTANCE_WINDOW_PROPERTY[] = L"FortSoft.GameOfLife.Standalone.Window";
constexpr wchar_t WEBSITE_URL[] = L"https://fortsoft.eu/dispsavers/";
constexpr wchar_t SHELL_OPEN_VERB[] = L"open";
constexpr int COMBO_BOX_MAX_VISIBLE_ITEMS = 13;
constexpr int RECORDING_COMBO_WIDTH_DLU = 130;
constexpr int MONITOR_COLUMN_COUNT = 8;
constexpr wchar_t NO_ANIMATION_MONITORS[] = L"{none}";
constexpr UINT_PTR INFORMATION_TEXT_SUBCLASS_ID = 0xF504;
constexpr UINT_PTR COMBO_BOX_DROPDOWN_SUBCLASS_ID = 0xF505;
constexpr UINT ANIMATION_CURSOR_HIDE_DELAY = 1000;
constexpr UINT ACTIVATE_APPLICATION_WINDOW = WM_APP + 3;
constexpr UINT RENDERER_FAILED = WM_APP + 4;
constexpr UINT UPDATE_SETTINGS_ACTION_BUTTONS = WM_APP + 5;
constexpr UINT UPDATE_OUTPUTS = WM_APP + 6;
constexpr UINT ENSURE_SETTINGS_CONTROL_VISIBLE = WM_APP + 7;
constexpr UINT UPDATE_SETTINGS_CONTROL_METRICS = WM_APP + 8;
constexpr UINT RESTORE_SETTINGS_FOCUS = WM_APP + 9;
constexpr UINT PATTERN_CATALOG_LOADED = WM_APP + 10;
constexpr std::size_t PATTERN_ITEMS_PER_BATCH = 128;
constexpr int ID_OK = IDOK;
constexpr int ID_ANIMATION_PRIMARY = 0;
constexpr std::array<int, 0> ANIMATION_RADIO_IDS{};
constexpr wchar_t MP4_EXTENSION[] = L"mp4";
constexpr wchar_t PNG_EXTENSION[] = L"png";
constexpr wchar_t SETTINGS_COLOR_PREVIEW_PROPERTY[] = L"CalClock.SettingsColorPreview";
constexpr wchar_t SETTINGS_COLOR_BUTTON_PROPERTY[] = L"CalClock.SettingsColorButton";
constexpr UINT_PTR SETTINGS_COLOR_PREVIEW_SUBCLASS_ID = 0xF508;
constexpr bool themesDisabled = false;
constexpr wchar_t KERNEL_LIBRARY[] = L"kernel32.dll";
constexpr UINT SCREEN_SAVER_CHECK_INTERVAL = 1000;

using CreatePowerRequest = HANDLE(WINAPI*)(PREASON_CONTEXT);
using SetPowerRequest = BOOL(WINAPI*)(HANDLE, POWER_REQUEST_TYPE);

using GetSystemWow64DirectoryWFunction = UINT(WINAPI*)(LPWSTR, UINT);
using StartSession = DWORD(WINAPI*)(DWORD*, DWORD, WCHAR[]);
using EndSession = DWORD(WINAPI*)(DWORD);
using RegisterResources = DWORD(WINAPI*)(DWORD, UINT, LPCWSTR[], UINT, RM_UNIQUE_PROCESS[], UINT, LPCWSTR[]);
using GetList = DWORD(WINAPI*)(DWORD, UINT*, UINT*, RM_PROCESS_INFO[], LPDWORD);

/// User-facing reason that prevents replacement of the installed saver file.
enum class ScreenSaverFileUse {
    None,
    Other,
    RunningSaver,
    SystemPreview,
    Settings
};

/// Window categories belonging to processes that lock the saver file.
struct LockedScreenSaverWindows {
    std::vector<DWORD> processIds;
    bool settings = false;
    bool systemPreview = false;
    bool runningSaver = false;
};

/// Startup mode selected from the executable and command-line arguments.
enum class RunMode {
    Application,
    Settings,
    ScreenSaver,
    Preview
};

/// One display window, renderer, worker and animation cursor state.
struct RenderSurface {
    HWND window = nullptr;
    RECT bounds{};
    std::wstring monitorDevice;
    unsigned refreshRate = 60;
    double refreshFrequency = 60.0;
    std::unique_ptr<Renderer> renderer;
    std::thread renderThread;
    std::atomic_bool stopRequested = false;
    std::atomic_uint64_t renderedFrames = 0;
    POINT mousePosition{};
    ULONGLONG mouseMoved = 0;
    bool trackingMouse = false;
    bool cursorHidden = false;
};

/// Application lifetime, shared scene options and synchronized monitor renderers.
struct Application {
    HWND controlWindow = nullptr;
    HWND previewParent = nullptr;
    HWND status = nullptr;
    HINSTANCE instance = nullptr;
    HANDLE installProcess = nullptr;
    HANDLE screenSaverInhibition = nullptr;
    ProgramIcons programIcons;
    RunMode mode = RunMode::Application;
    AppSettings settings;
    RECT worldBounds{};
    std::vector<std::unique_ptr<RenderSurface>> surfaces;
    std::mutex rendererMutex;
    std::atomic_bool closing = false;
    std::atomic_bool patternCatalogReady = false;
    std::atomic_bool paused = false;
    std::atomic_bool resetRequested = true;
    std::atomic_bool patternsOnly = false;
    std::atomic_uint patternSelection = 0;
    std::atomic_uint cellSize = 8;
    std::atomic_uint densityPercent = 25;
    std::atomic_uint generationsPerSecond = 20;
    POINT initialMouse{};
    ULONGLONG saverStarted = 0;
    unsigned minimumCellSize = 1;
    COLORREF configuredAliveColor = RGB(64, 224, 112);
    COLORREF configuredBackgroundColor = RGB(0, 0, 0);
    COLORREF configuredGridColor = RGB(48, 48, 48);
    COLORREF sceneAliveColor = RGB(64, 224, 112);
    COLORREF sceneBackgroundColor = RGB(0, 0, 0);
    COLORREF sceneGridColor = RGB(48, 48, 48);
    bool showGrid = false;
    bool randomAliveColor = false;
    bool randomBackgroundColor = false;
    bool randomGridColor = false;
    bool previewActive = false;
    bool confirmingClose = false;
    bool changingScreenSaver = false;
    bool uninstallingScreenSaver = false;
    bool startupFailed = false;
    bool saverCursorHidden = false;
    RenderSurface* recordingSource = nullptr;
    std::jthread patternCatalogThread;
};

/// One display and its cached localized monitor-list texts.
struct MonitorListEntry {
    MonitorDetails details;
    std::array<std::wstring, MONITOR_COLUMN_COUNT> text;
};

/// Z-order layers used to preserve clipped, full-width label controls.
enum class SettingsControlLayer {
    Foreground,
    Checkbox,
    Label
};

/// Child window paired with client-relative geometry for stable Z-order sorting.
struct PositionedControl {
    HWND window = nullptr;
    RECT rect{};
};

/// Resource identifiers pairing a scene slider with its value label.
struct AnimationSliderControl {
    int id;
    int labelId;
};

constexpr AnimationSliderControl ANIMATION_SLIDERS[]{
    { ID_CELL_SIZE, ID_CELL_SIZE_LABEL },
    { ID_GENERATION_RATE, ID_GENERATION_RATE_LABEL },
    { ID_INITIAL_DENSITY, ID_INITIAL_DENSITY_LABEL }
};

constexpr int OPAQUE_SETTINGS_LABEL_IDS[]{ ID_MONITOR_GROUP, ID_TOPOLOGY_NOTE };

/// Settings controls, monitor-list state, scrolling and pattern-dropdown metrics.
struct SettingsWindowData {
    HWND contentWindow = nullptr;
    HWND defaultButton = nullptr;
    HWND lastFocusedControl = nullptr;
    AppSettings* settings = nullptr;
    HFONT systemDialogFont = nullptr;
    AppLanguage language = LANG_EN_US;
    bool appMode = false;
    bool updating = false;
    std::vector<DisplayMonitor> monitors;
    std::vector<MonitorListEntry> monitorListEntries;
    bool monitorColumnsInitialized = false;
    int monitorSortColumn = -1;
    bool monitorSortAscending = true;
    bool outputsUpdatePending = false;
    bool monitorListInitialized = false;
    LONG_PTR scrollStyle = 0;
    int contentWidth = 0;
    int contentHeight = 0;
    unsigned patternColumns = std::numeric_limits<unsigned>::max();
    unsigned patternRows = std::numeric_limits<unsigned>::max();
    AppLanguage patternLanguage = LANG_COUNT;
    std::size_t patternCount = 0;
    std::size_t patternItemsAdded = 0;
    std::vector<unsigned> patternItems;
    std::wstring patternIdleId;
};

/// Scroll-bar identifier, virtual extent and visible page size.
struct ScrollBarData {
    int bar;
    int extent;
    UINT page;
};

/// Recording preferences dialog state and its owner, language and system font.
struct RecordingWindowData {
    AppSettings* settings = nullptr;
    HWND owner = nullptr;
    AppLanguage language = LANG_EN_US;
    HFONT font = nullptr;
    bool initialized = false;
};

/// Retains native Unicode line-break analysis for the last information-edit text.
struct InformationWordBreakState {
    SCRIPT_STRING_ANALYSIS analysis = nullptr;
    std::wstring text;
};

/// Font metrics used by the information-text renderer.
struct UiTextLine {
    LONG ascent;
    LONG descent;
    LONG gap;
};

/// Application instance
static Application* app = nullptr;

/// Information windows
static HelpForm helpForm;
static AboutForm aboutForm;
static PersistWindowState settingsWindowState;
static PersistWindowState helpWindowState;
static PersistWindowState aboutWindowState;
static HWND recordingSettingsWindow = nullptr;

/// Native Unicode line-break analysis
static InformationWordBreakState informationWordBreakState;

/// Custom colors retained between native color-dialog invocations.
static COLORREF customColors[16]{};

/// Restores native clipping styles and Z-order without changing resource control geometry.
static void UpdateSettingsTextControlLayout(HWND window);

/// Aligns settings rows after the shared font, theme, DPI or native control metrics change.
static void UpdateSettingsControlMetrics(HWND window);

/// Returns the next available control in the declared settings tab sequence, retaining a disabled source as
/// its anchor.
static HWND FindSettingsTabTarget(HWND parent, const SettingsWindowData& data, HWND focused, bool backwards);

/// Enables recording, snapshots, pause and scene restart according to available outputs.
static void UpdateSettingsActionButtons(HWND window);

/// Assigns unique mnemonics to visible settings labels and tab-stop buttons.
static void AssignSettingsMnemonics(HWND parent);

/// Applies one language atomically to all settings and information windows.
static void ApplyLocalizedCaptions(HWND window, SettingsWindowData& data);

/// Releases saver inhibition, stops recording and workers, then destroys the animation windows.
static void StopRenderSurfaces();

/// Creates a separate system preview or selected-monitor outputs and starts their render workers.
static bool StartRenderSurfaces();

/// Returns the output whose recording remains active across monitor-selection changes.
static RenderSurface* RecordingSurface();

/// Stops capture under the shared GPU lock, finalizes the file and updates the recording result.
static void StopRecording();

/// Creates or restores independent modeless recording settings, matching Help and About activation and
/// topmost policy.
static void ShowRecordingSettings(HWND owner, SettingsWindowData& settingsData);

/// Refreshes localized recording captions and metrics without replacing unconfirmed choices.
static void RefreshRecordingSettingsWindow(HWND window, RecordingWindowData& data);

/// Shows a notification for ten seconds before restoring persistent status.
static void ShowTransientStatus(const wchar_t* text);

/// Publishes a loaded catalog on the UI thread and starts the requested animation.
static void CompletePatternCatalogLoad(bool succeeded, SettingsWindowData* data);

/// Returns the settings panel, or the settings window when no separate panel is used.
static HWND SettingsContentWindow(HWND window) {
    SettingsWindowData* data =
        reinterpret_cast<SettingsWindowData*>(GetWindowLongPtrW(window, GWLP_USERDATA));
    return data && data->contentWindow ? data->contentWindow : window;
}

/// Resolves an explicit language preference or falls back to the operating system.
static AppLanguage ResolvedLanguage(const AppSettings& settings) {
    if (settings.language >= 0 && settings.language < static_cast<int>(LANG_COUNT)) {
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
    DWORD req = 0;
    bool visible = GetUserObjectInformationW(inputDesktop, UOI_NAME, inputName, sizeof(inputName), &req);
    if (visible) {
        const HDESK threadDesktop = GetThreadDesktop(GetCurrentThreadId());
        visible = GetUserObjectInformationW(threadDesktop, UOI_NAME, threadName, sizeof(threadName), &req)
            && _wcsicmp(inputName, threadName) == 0;
    }
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
    if (!GetClientRect(window, &bounds)
            || !GetMonitorInfoW(MonitorFromWindow(window, MONITOR_DEFAULTTONULL), &monitor)) {
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
    for (HWND covering = GetWindow(window, GW_HWNDPREV);
            covering;
            covering = GetWindow(covering, GW_HWNDPREV)) {
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

/// Checks whether the standalone option and a visible animation require saver inhibition.
bool ShouldInhibitScreenSaver() {
    if (!app
            || app->mode != RunMode::Application
            || !app->settings.preventScreenSaver
            || app->paused.load(std::memory_order_relaxed)
            || app->closing.load(std::memory_order_relaxed)
            || !IsAnimationDesktopVisible()) {
        return false;
    }
    for (const std::unique_ptr<RenderSurface>& surface : app->surfaces) {
        if (surface->renderer
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

/// Uses a Windows 7 display request while animation is visible; older systems retain native SC_SCREENSAVE
/// handling.
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
    const SetPowerRequest setRequest =
        reinterpret_cast<SetPowerRequest>(GetProcAddress(kernel, "PowerSetRequest"));
    if (!createRequest || !setRequest) {
        return;
    }
    REASON_CONTEXT reason{};
    reason.Version = POWER_REQUEST_CONTEXT_VERSION;
    reason.Flags = POWER_REQUEST_CONTEXT_SIMPLE_STRING;
    reason.Reason.SimpleReasonString = const_cast<wchar_t*>(GetLocalizedText(ActiveLanguage(),
        TXT_PREVENT_SCREEN_SAVER));
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

/// Normalizes a prospective mnemonic key for case-insensitive comparison.
static wchar_t MnemonicKey(wchar_t character) {
    CharUpperBuffW(&character, 1);
    return character;
}

/// Assigns the preferred or first available single-character mnemonic to a caption.
std::wstring UniqueMnemonic(const wchar_t* text, std::vector<wchar_t>& usedMnemonics) {
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

/// Replaces clipboard contents with Unicode text, transferring the allocation to Windows only on success.
bool CopyTextToClipboard(HWND owner, const std::wstring& text) {
    SIZE_T bytes = (text.size() + 1) * sizeof(wchar_t);
    HGLOBAL memory = GlobalAlloc(GMEM_MOVEABLE, bytes);
    if (memory == nullptr) {
        return false;
    }
    void* target = GlobalLock(memory);
    if (target == nullptr) {
        GlobalFree(memory);
        return false;
    }
    CopyMemory(target, text.c_str(), bytes);
    GlobalUnlock(memory);
    if (!OpenClipboard(owner)) {
        GlobalFree(memory);
        return false;
    }
    bool copied = EmptyClipboard() && SetClipboardData(CF_UNICODETEXT, memory) != nullptr;
    if (!copied) {
        GlobalFree(memory);
    }
    CloseClipboard();
    return copied;
}

/// Resolves the standalone Close caption through the application's existing mnemonic allocator.
std::wstring Mnemonic(AppLanguage language, TextId id) {
    std::vector<wchar_t> usedMnemonics;
    return UniqueMnemonic(GetLocalizedText(language, id), usedMnemonics);
}

/// Recognizes Unicode whitespace for license text and descriptive-text layout.
bool IsUnicodeWhitespace(wchar_t character) {
    WORD type = 0;
    return GetStringTypeW(CT_CTYPE1, &character, 1, &type) && (type & C1_SPACE) != 0;
}

/// Returns an owned copy of a control's current Unicode text.
std::wstring GetControlText(HWND control) {
    int length = GetWindowTextLengthW(control);
    std::wstring text(static_cast<size_t>(length) + 1, L'\0');
    int copied = GetWindowTextW(control, text.data(), static_cast<int>(text.size()));
    text.resize(copied);
    return text;
}

/// Lets information windows handle Enter, Escape and Tab from their read-only text fields.
LRESULT CALLBACK InformationTextSubclassProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam,
        UINT_PTR subclassId, DWORD_PTR referenceData) {
    UNREFERENCED_PARAMETER(referenceData);
    if (msg == WM_GETDLGCODE) {
        LRESULT result = DefSubclassProc(window, msg, wParam, lParam);
        if (wParam == VK_RETURN || wParam == VK_ESCAPE || wParam == VK_TAB) {
            result &= ~DLGC_WANTALLKEYS;
        }
        return result;
    }
    if (msg == WM_NCDESTROY) {
        RemoveWindowSubclass(window, InformationTextSubclassProc, subclassId);
    }
    return DefSubclassProc(window, msg, wParam, lParam);
}

/// Releases the cached Unicode boundary analysis and its retained text.
void ResetInformationWordBreak() {
    if (informationWordBreakState.analysis != nullptr) {
        if (FAILED(ScriptStringFree(&informationWordBreakState.analysis))) {
            OutputDebugStringW(L"ScriptStringFree failed while clearing Unicode word-break analysis.\r\n");
        }
        informationWordBreakState.analysis = nullptr;
    }
    informationWordBreakState.text.clear();
}

/// Supplies the same native Unicode word and cluster boundaries to the Help and About edits.
int CALLBACK InformationWordBreakProc(wchar_t* text, int position, int length, int code) {
    if (length <= 0) {
        return 0;
    }
    position = std::clamp(position, 0, length);
    if (informationWordBreakState.text.size() != static_cast<size_t>(length)
            || wmemcmp(informationWordBreakState.text.c_str(), text, length) != 0) {
        ResetInformationWordBreak();
        informationWordBreakState.text.assign(text, length);
        HRESULT status = ScriptStringAnalyse(nullptr, informationWordBreakState.text.c_str(), length, 0, -1,
            SSA_BREAK, 0, nullptr, nullptr, nullptr, nullptr, nullptr, &informationWordBreakState.analysis);
        if (FAILED(status)) {
            ResetInformationWordBreak();
            if (code == WB_ISDELIMITER) {
                return position < length && IsUnicodeWhitespace(text[position]);
            }
            return code == WB_LEFT ? 0 : length;
        }
    }
    const SCRIPT_LOGATTR* attributes = ScriptString_pLogAttr(informationWordBreakState.analysis);
    if (code == WB_ISDELIMITER) {
        return position < length && attributes[position].fWhiteSpace;
    }
    if (code == WB_LEFT) {
        if (position == length) {
            position--;
        }
        while (position > 0 && (!attributes[position].fCharStop
                || !attributes[position].fSoftBreak && !attributes[position - 1].fWhiteSpace)) {
            position--;
        }
    } else if (code == WB_RIGHT) {
        if (position < length) {
            position++;
        }
        while (position < length && (!attributes[position].fCharStop
                || !attributes[position].fSoftBreak && !attributes[position - 1].fWhiteSpace)) {
            position++;
        }
    }
    return position;
}

/// Reports whether visual styles are active for Windows and the current application.
static bool AreVisualStylesActive() {
    return IsThemeActive() && IsAppThemed();
}

/// Draws the native button theme in window or client coordinates, clipped to the requested preview area.
/// Uses the associated button's enabled state and leaves classic rendering to the native static control.
static bool DrawSettingsColorPreviewTheme(HWND preview, HDC dc, bool nonClient) {
    HWND button = reinterpret_cast<HWND>(GetPropW(preview, SETTINGS_COLOR_BUTTON_PROPERTY));
    WINDOWINFO information = { sizeof(information) };
    if (button == nullptr
            || dc == nullptr
            || themesDisabled
            || !AreVisualStylesActive()
            || !GetWindowInfo(preview, &information)) {
        return false;
    }
    HTHEME theme = OpenThemeData(button, L"Button");
    if (theme == nullptr) {
        return false;
    }
    const RECT& origin = nonClient ? information.rcWindow : information.rcClient;
    RECT bounds = information.rcWindow;
    RECT client = information.rcClient;
    OffsetRect(&bounds, -origin.left, -origin.top);
    OffsetRect(&client, -origin.left, -origin.top);
    int saved = SaveDC(dc);
    bool drawn = false;
    if (saved != 0) {
        if (nonClient) {
            ExcludeClipRect(dc, client.left, client.top, client.right, client.bottom);
        } else {
            IntersectClipRect(dc, client.left, client.top, client.right, client.bottom);
        }
        int state = IsWindowEnabled(button) ? PBS_NORMAL : PBS_DISABLED;
        if (IsThemeBackgroundPartiallyTransparent(theme, BP_PUSHBUTTON, state)) {
            DrawThemeParentBackground(preview, dc, &bounds);
        }
        drawn = SUCCEEDED(DrawThemeBackground(theme, dc, BP_PUSHBUTTON, state, &bounds, nullptr));
        RestoreDC(dc, saved);
    }
    CloseThemeData(theme);
    return drawn;
}

/// Applies the native button border to themed previews, including printed images, and refreshes state
/// changes.
static LRESULT CALLBACK SettingsColorPreviewSubclassProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam,
        UINT_PTR subclassId, DWORD_PTR referenceData) {
    UNREFERENCED_PARAMETER(referenceData);
    if (msg == WM_NCPAINT) {
        HDC dc = GetWindowDC(window);
        bool drawn = DrawSettingsColorPreviewTheme(window, dc, true);
        if (dc != nullptr) {
            ReleaseDC(window, dc);
        }
        if (drawn) {
            return 0;
        }
    } else if (msg == WM_NCDESTROY) {
        RemoveWindowSubclass(window, SettingsColorPreviewSubclassProc, subclassId);
    }
    LRESULT result = DefSubclassProc(window, msg, wParam, lParam);
    if (msg == WM_PRINT && (lParam & PRF_NONCLIENT) != 0) {
        DrawSettingsColorPreviewTheme(window, reinterpret_cast<HDC>(wParam), true);
    } else if (msg == WM_ENABLE || msg == WM_THEMECHANGED || msg == WM_SYSCOLORCHANGE) {
        RedrawWindow(window, nullptr, nullptr, RDW_INVALIDATE | RDW_ERASE | RDW_FRAME);
    }
    return result;
}

/// Updates a native color button's stored selection and repaints its associated preview when the color
/// changes.
static void SetButtonColor(HWND button, COLORREF color) {
    if (button != nullptr && static_cast<COLORREF>(GetWindowLongPtrW(button, GWLP_USERDATA)) != color) {
        SetWindowLongPtrW(button, GWLP_USERDATA, color);
        HWND preview = reinterpret_cast<HWND>(GetPropW(button, SETTINGS_COLOR_PREVIEW_PROPERTY));
        if (preview != nullptr) {
            InvalidateRect(preview, nullptr, TRUE);
        }
    }
}

/// Associates a native color preview with its button and installs themed border drawing.
static bool AddSettingsColorPreview(HWND button, HWND preview) {
    return SetPropW(button, SETTINGS_COLOR_PREVIEW_PROPERTY, preview)
        && SetPropW(preview, SETTINGS_COLOR_BUTTON_PROPERTY, button)
        && SetWindowSubclass(preview, SettingsColorPreviewSubclassProc,
            SETTINGS_COLOR_PREVIEW_SUBCLASS_ID, 0);
}

/// Paints the preview using the color stored on its associated button.
static INT_PTR GetSettingsColorPreviewBrush(HWND preview, HDC dc) {
    HWND button = reinterpret_cast<HWND>(GetPropW(preview, SETTINGS_COLOR_BUTTON_PROPERTY));
    if (button == nullptr) {
        return FALSE;
    }
    COLORREF color = static_cast<COLORREF>(GetWindowLongPtrW(button, GWLP_USERDATA));
    if (!IsWindowEnabled(button)) {
        if (DrawSettingsColorPreviewTheme(preview, dc, false)) {
            return reinterpret_cast<INT_PTR>(GetStockObject(NULL_BRUSH));
        }
        color = GetSysColor(COLOR_BTNFACE);
    }
    SetBkColor(dc, color);
    SetDCBrushColor(dc, color);
    return reinterpret_cast<INT_PTR>(GetStockObject(DC_BRUSH));
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
    HTHEME theme = OpenThemeData(button, L"Button");
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
        } else if (type == BS_CHECKBOX
                || type == BS_AUTOCHECKBOX
                || type == BS_3STATE
                || type == BS_AUTO3STATE) {
            SIZE glyph = {};
            if (SUCCEEDED(GetThemePartSize(theme, nullptr, BP_CHECKBOX, CBS_UNCHECKEDNORMAL, nullptr,
                    TS_TRUE, &glyph))) {
                textHeight = std::max(textHeight, glyph.cy);
            }
        }
        CloseThemeData(theme);
    }
    return content.top + (content.bottom - content.top - textHeight) / 2;
}

/// Measures one control's rendered text baseline using its own font and native content rectangle.
static bool GetSettingsControlBaseline(HWND control, LONG* baseline) {
    WINDOWINFO information = {};
    information.cbSize = sizeof(information);
    if (control == nullptr || !GetWindowInfo(control, &information)) {
        return false;
    }
    HDC dc = GetDC(control);
    if (dc == nullptr) {
        return false;
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
        return false;
    }
    wchar_t className[32] = {};
    GetClassNameW(control, className, ARRAYSIZE(className));
    LONG textTop = information.rcClient.top;
    if (_wcsicmp(className, WC_COMBOBOXW) == 0 || _wcsicmp(className, WC_COMBOBOXEXW) == 0) {
        COMBOBOXINFO combo = {};
        combo.cbSize = sizeof(combo);
        if (!GetComboBoxInfo(GetSettingsComboBox(control), &combo)) {
            return false;
        }
        textTop += combo.rcItem.top + (combo.rcItem.bottom - combo.rcItem.top - metrics.tmHeight) / 2;
    } else if (_wcsicmp(className, L"EDIT") == 0) {
        RECT text = {};
        SendMessageW(control, EM_GETRECT, 0, reinterpret_cast<LPARAM>(&text));
        textTop += text.top;
    } else if (_wcsicmp(className, L"BUTTON") == 0) {
        textTop += GetSettingsButtonTextTop(control, information, metrics);
    } else if (_wcsicmp(className, L"STATIC") == 0
            && (GetWindowLongPtrW(control, GWL_STYLE) & SS_CENTERIMAGE) != 0) {
        textTop += (information.rcClient.bottom - information.rcClient.top - metrics.tmHeight) / 2;
    }
    *baseline = textTop + metrics.tmAscent;
    return true;
}

/// Calculates the displacement between independently measured control and reference text baselines.
static LONG GetSettingsControlBaselineAdjustment(HWND control, HWND reference, LONG baselineDistance) {
    LONG controlBaseline = 0;
    LONG referenceBaseline = 0;
    if (!GetSettingsControlBaseline(control, &controlBaseline)
            || !GetSettingsControlBaseline(reference, &referenceBaseline)) {
        return 0;
    }
    return referenceBaseline + baselineDistance - controlBaseline;
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

/// Aligns a settings label, edit, combo, push button, or checkbox to adjacent text plus an optional baseline
/// distance. Uses native content rectangles and preserves size, horizontal position, and Z order.
void AlignSettingsControl(HWND control, HWND reference, LONG baselineDistance) {
    OffsetSettingsControl(control,
        GetSettingsControlBaselineAdjustment(control, reference, baselineDistance));
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
        outline->otmAscent,
        std::abs(outline->otmDescent),
        static_cast<LONG>(outline->otmLineGap)
    };
    MAT2 transform = {
        FIXED{ 0, 1 },
        FIXED{ 0, 0 },
        FIXED{ 0, 0 },
        FIXED{ 0, 1 }
    };
    for (wchar_t character : text) {
        if (IsUnicodeWhitespace(character)) {
            continue;
        }
        GLYPHMETRICS glyph = {};
        if (GetGlyphOutlineW(dc, character, GGO_METRICS, &glyph, 0, nullptr, &transform) != GDI_ERROR) {
            typographic.ascent = std::max(typographic.ascent, glyph.gmptGlyphOrigin.y);
            typographic.descent = std::max(typographic.descent,
                static_cast<LONG>(glyph.gmBlackBoxY) - glyph.gmptGlyphOrigin.y);
        }
    }
    if (typographic.ascent + typographic.descent + typographic.gap
            < metrics.tmHeight + metrics.tmExternalLeading) {
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

/// Draws or measures descriptive text using the same word wrapping and current font's line height.
static int DrawWordWrappedText(HDC dc, const std::wstring& text, const RECT& bounds,
        UINT prefix = DT_NOPREFIX) {
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
        while (position < text.size()
                && IsUnicodeWhitespace(text[position])
                && text[position] != L'\r'
                && text[position] != L'\n') {
            position++;
        }
        size_t wordStart = position;
        while (position < text.size() && !IsUnicodeWhitespace(text[position])) {
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
INT_PTR DrawWrappedTextItem(const DRAWITEMSTRUCT* item) {
    int savedState = SaveDC(item->hDC);
    DrawThemeParentBackground(item->hwndItem, item->hDC, nullptr);
    SetBkMode(item->hDC, TRANSPARENT);
    SetTextColor(item->hDC, GetSysColor(IsWindowEnabled(item->hwndItem) ? COLOR_WINDOWTEXT : COLOR_GRAYTEXT));
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(item->hwndItem, WM_GETFONT, 0, 0));
    if (font != nullptr) {
        SelectObject(item->hDC, font);
    }
    std::wstring text = GetControlText(item->hwndItem);
    RECT textRect = item->rcItem;
    UINT prefix = DT_NOPREFIX;
    DrawWordWrappedText(item->hDC, text, textRect, prefix);
    RestoreDC(item->hDC, savedState);
    return TRUE;
}

/// Creates a nonactivating tooltip for a child control, destroying it if registration fails.
HWND CreateControlTooltip(HWND parent, HWND control, const wchar_t* text) {
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

/// Positions an information-window child without activation or Z-order changes, enforcing positive
/// dimensions.
void PlaceInformationControl(HWND window, int id, int x, int y, int width, int height) {
    HWND control = GetDlgItem(window, id);
    int controlWidth = std::max(1, width);
    int controlHeight = std::max(1, height);
    UINT flags = SWP_NOZORDER | SWP_NOACTIVATE;
    SetWindowPos(control, nullptr, x, y, controlWidth, controlHeight, flags);
}

/// Measures a label's wrapped height at the requested width using its actual font, or returns zero if a DC is
/// unavailable.
int InformationLabelHeight(HWND control, int width) {
    HDC dc = GetDC(control);
    if (dc == nullptr) {
        return 0;
    }
    std::wstring text = GetControlText(control);
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

/// Measures native dialog base units from the supplied interface font.
bool GetDialogFontBaseUnits(HFONT font, SIZE* units) {
    HDC dc = GetDC(nullptr);
    if (dc == nullptr) {
        return false;
    }
    HGDIOBJ previous = font == nullptr ? nullptr : SelectObject(dc, font);
    SIZE alphabet = {};
    TEXTMETRICW metrics = {};
    bool measured = GetTextExtentPoint32W(dc, L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",
        52, &alphabet) && GetTextMetricsW(dc, &metrics);
    if (measured) {
        units->cx = (alphabet.cx / 26 + 1) / 2;
        units->cy = metrics.tmHeight;
    }
    if (previous != nullptr) {
        SelectObject(dc, previous);
    }
    ReleaseDC(nullptr, dc);
    return measured;
}

/// Converts current information-dialog font units to native pixel dimensions.
SIZE InformationDialogUnits(HFONT font, int x, int y) {
    SIZE units = {};
    if (!GetDialogFontBaseUnits(font, &units)) {
        return SIZE{};
    }
    return SIZE{ MulDiv(x, units.cx, 4), MulDiv(y, units.cy, 8) };
}

/// Measures the common native Close button using its current font and existing dialog-unit minimum and
/// padding.
SIZE InformationButtonSize(HWND window, HFONT font) {
    SIZE button = InformationDialogUnits(font, DIALOG_BUTTON_WIDTH_DLU, DIALOG_BUTTON_HEIGHT_DLU);
    SIZE ideal = {};
    HWND closeButton = GetDlgItem(window, ID_INFO_CLOSE);
    if (!SendMessageW(closeButton, BCM_GETIDEALSIZE, 0, reinterpret_cast<LPARAM>(&ideal))) {
        HDC dc = GetDC(closeButton);
        if (dc != nullptr) {
            HFONT controlFont = reinterpret_cast<HFONT>(SendMessageW(closeButton, WM_GETFONT, 0, 0));
            HGDIOBJ previous = controlFont == nullptr ? nullptr : SelectObject(dc, controlFont);
            std::wstring text = GetControlText(closeButton);
            RECT bounds = {};
            DrawTextW(dc, text.c_str(), static_cast<int>(text.size()), &bounds, DT_CALCRECT | DT_SINGLELINE);
            SIZE padding = InformationDialogUnits(font, 12, 0);
            ideal.cx = bounds.right + padding.cx + 2 * GetSystemMetrics(SM_CXEDGE);
            if (previous != nullptr) {
                SelectObject(dc, previous);
            }
            ReleaseDC(closeButton, dc);
        }
    }
    button.cx = std::max(button.cx, ideal.cx);
    return button;
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

/// Relocalizes all currently open information and recording-settings windows.
static void RefreshInformationWindows(AppLanguage language, bool appMode) {
    helpForm.Refresh(language, appMode);
    aboutForm.Refresh(language);
    if (recordingSettingsWindow && IsWindow(recordingSettingsWindow)) {
        RecordingWindowData* data =
            reinterpret_cast<RecordingWindowData*>(GetWindowLongPtrW(recordingSettingsWindow, DWLP_USER));
        if (data) {
            data->language = language;
            RefreshRecordingSettingsWindow(recordingSettingsWindow, *data);
        }
    }
}

/// Refreshes both information forms from the owning settings window's current language and mode.
void RefreshInformationWindows(HWND owner) {
    const SettingsWindowData* data =
        reinterpret_cast<const SettingsWindowData*>(GetWindowLongPtrW(owner, GWLP_USERDATA));
    if (data != nullptr) {
        RefreshInformationWindows(data->language, data->appMode);
    }
}

/// Restores and activates a valid window, temporarily attaching input queues when the foreground thread
/// differs.
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
    helpForm.Close();
    aboutForm.Close();
    if (recordingSettingsWindow != nullptr) {
        SendMessageW(recordingSettingsWindow, WM_CLOSE, 0, 0);
    }
}

/// Keeps independent information and recording-settings windows synchronized with the settings form's
/// topmost policy.
void UpdateInformationWindowsTopmost(HWND settingsWindow) {
    HWND position = HWND_NOTOPMOST;
    if ((GetWindowLongPtrW(settingsWindow, GWL_EXSTYLE) & WS_EX_TOPMOST) != 0) {
        position = HWND_TOPMOST;
    }
    const HWND windows[]{ helpForm.GetWindow(), aboutForm.GetWindow(), recordingSettingsWindow };
    for (HWND window : windows) {
        if (window != nullptr) {
            SetWindowPos(window, position, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
        }
    }
}

/// Obtains native CW_USEDEFAULT placement from an invisible overlapped window and moves the hidden dialog
/// there.
bool PositionInformationWindowByWindowsDefault(HWND window) {
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

/// Creates or activates the independent Help or About form using the application's current preferences.
static void ShowInformationWindow(HWND owner, bool help, AppLanguage language, bool appMode) {
    const SettingsWindowData* settingsData =
        reinterpret_cast<const SettingsWindowData*>(GetWindowLongPtrW(owner, GWLP_USERDATA));
    if (settingsData == nullptr || settingsData->settings == nullptr) {
        return;
    }
    if (help) {
        helpForm.Show(owner, app->instance, *settingsData->settings, app->programIcons,
            helpWindowState, language, appMode);
    } else {
        aboutForm.Show(owner, app->instance, *settingsData->settings, app->programIcons,
            aboutWindowState, language);
    }
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
                LONG currentWidth = position->flags & SWP_NOSIZE
                    ? current.right - current.left
                    : position->cx;
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

/// Measures current items in the dropdown font immediately before opening, adding borders, padding, and
/// scrollbar space. Limits the list to 13 visible items and keeps it at least as wide as its combo within
/// the monitor work area.
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
        ReleaseDC(list, dc);
        return;
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

/// Converts dialog units using the supplied font metrics rather than fixed pixel assumptions.
static SIZE DialogUnits(HFONT font, int x, int y) {
    HDC dc = GetDC(nullptr);
    SIZE extent = SIZE{};
    TEXTMETRICW metrics = TEXTMETRICW{};
    if (!dc) {
        return SIZE{ x, y };
    }
    HGDIOBJ old = SelectObject(dc, font);
    GetTextExtentPoint32W(dc, L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", 52, &extent);
    GetTextMetricsW(dc, &metrics);
    SelectObject(dc, old);
    ReleaseDC(nullptr, dc);
    int baseX = (extent.cx / 26 + 1) / 2;
    return SIZE{ MulDiv(x, baseX, 4), MulDiv(y, metrics.tmHeight, 8) };
}

/// Returns the fully qualified path of the running module.
static std::wstring ExecutablePath() {
    std::wstring path(32768, L'\0');
    const DWORD length = GetModuleFileNameW(nullptr, path.data(), static_cast<DWORD>(path.size()));
    path.resize(length);
    return path;
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

/// Recognizes canonical and historical installation paths.
static bool IsProductScreenSaverPath(const std::wstring& path) {
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
    const StartSession startSession =
        reinterpret_cast<StartSession>(GetProcAddress(restartManager, "RmStartSession"));
    const EndSession endSession =
        reinterpret_cast<EndSession>(GetProcAddress(restartManager, "RmEndSession"));
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
            return GetLocalizedText(language, TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS);
        case ScreenSaverFileUse::SystemPreview:
            return GetLocalizedText(language, TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW);
        case ScreenSaverFileUse::RunningSaver:
            return GetLocalizedText(language, TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER);
        default:
            return GetLocalizedText(language, TXT_UNINSTALLATION_FAILED);
    }
}

/// Writes and verifies the embedded screen-saver file in the native system directory.
static bool WriteScreenSaverFile(const std::wstring& destination, const std::wstring& staging,
        const void* bytes, DWORD resourceSize) {
    const Wow64Redirection wow64Redirection;
    DeleteFileW(staging.c_str());
    const HANDLE file = CreateFileW(staging.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL, nullptr);
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
    if (destinationAttributes != INVALID_FILE_ATTRIBUTES
            && (destinationAttributes & FILE_ATTRIBUTE_READONLY) != 0) {
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
    BYTE* unpacked = nullptr;
    DWORD unpackedSize = 0;
    if (!UnpackLibraryBytes(static_cast<const BYTE*>(bytes), resourceSize, &unpacked, &unpackedSize)) {
        return false;
    }
    const bool written = WriteScreenSaverFile(destination, staging, unpacked, unpackedSize);
    HeapFree(GetProcessHeap(), 0, unpacked);
    if (!written) {
        return false;
    }
    HKEY key = nullptr;
    const LSTATUS createResult = RegCreateKeyExW(HKEY_CURRENT_USER, DESKTOP_REGISTRY_PATH, 0, nullptr, 0,
        KEY_WRITE, nullptr, &key, nullptr);
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
        selected = IsProductScreenSaverPath(selectedPath.data());
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
        SendMessageTimeoutW(HWND_BROADCAST, WM_SETTINGCHANGE, 0,
            reinterpret_cast<LPARAM>(DESKTOP_REGISTRY_PATH), SMTO_ABORTIFHUNG, 1000, nullptr);
    }
    return true;
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

/// Moves focus from a disabled control to the next available tab stop without overriding another focused
/// window.
static void RestoreDisabledControlFocus(HWND control, const SettingsWindowData* data = nullptr) {
    if (!IsWindow(control) || IsWindowEnabled(control)) {
        return;
    }
    HWND focused = GetFocus();
    if (focused && focused != control && !IsChild(control, focused)) {
        return;
    }
    if (GetActiveWindow() != GetAncestor(control, GA_ROOT)) {
        return;
    }
    HWND parent = GetParent(control);
    HWND next = data
        ? FindSettingsTabTarget(parent, *data, control, false)
        : GetNextDlgTabItem(parent, control, FALSE);
    if (next && next != control) {
        SetFocus(next);
    }
}

/// Applies a standalone control state change and retains keyboard navigation when the focused control is
/// disabled.
static void EnableSettingsControl(HWND control, bool enabled, const SettingsWindowData* data = nullptr) {
    HWND focused = GetFocus();
    const bool restore = !enabled && focused && (focused == control || IsChild(control, focused));
    EnableWindow(control, enabled);
    if (restore) {
        RestoreDisabledControlFocus(control, data);
    }
}

/// Applies the current system message font to one descendant control.
static BOOL CALLBACK ApplySystemDialogFont(HWND child, LPARAM fontParameter) {
    SendMessageW(child, WM_SETFONT, fontParameter, TRUE);
    return TRUE;
}

/// Aligns a settings push button or checkbox with adjacent text using their shared application font.
/// Accounts for classic buttons' inclusive text rectangles and preserves size, horizontal position,
/// and Z order.
static void AlignSettingsButton(HWND button, HWND reference) {
    AlignSettingsControl(button, reference);
}

/// Aligns a label with the native combo-box text origin.
static void AlignSettingsLabel(HWND label, HWND reference) {
    AlignSettingsControl(label, reference);
}

/// Copies control text into a null-terminated process-heap buffer owned by the caller.
static wchar_t* CopyControlText(HWND control) {
    int length = GetWindowTextLengthW(control);
    wchar_t* text = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), 0,
        (static_cast<SIZE_T>(length) + 1) * sizeof(wchar_t)));
    if (text) {
        GetWindowTextW(control, text, length + 1);
    }
    return text;
}

/// Expands a native button only as needed for its current localized text and native padding.
static SIZE PreferredButtonSize(HWND button, const SIZE& minimum) {
    SIZE size = SIZE{};
    if (!SendMessageW(button, BCM_GETIDEALSIZE, 0, reinterpret_cast<LPARAM>(&size))) {
        wchar_t* text = CopyControlText(button);
        HDC dc = GetDC(button);
        if (text && dc) {
            HFONT font = reinterpret_cast<HFONT>(SendMessageW(button, WM_GETFONT, 0, 0));
            HGDIOBJ previous = font ? SelectObject(dc, font) : nullptr;
            RECT bounds = RECT{};
            DrawTextW(dc, text, -1, &bounds, DT_CALCRECT | DT_SINGLELINE);
            SIZE padding = DialogUnits(font, 12, 0);
            size.cx = bounds.right + padding.cx + 2 * GetSystemMetrics(SM_CXEDGE);
            size.cy = bounds.bottom + 2 * GetSystemMetrics(SM_CYEDGE);
            if (previous) {
                SelectObject(dc, previous);
            }
        }
        if (dc) {
            ReleaseDC(button, dc);
        }
        if (text) {
            HeapFree(GetProcessHeap(), 0, text);
        }
    }
    if (size.cx < minimum.cx) {
        size.cx = minimum.cx;
    }
    if (size.cy < minimum.cy) {
        size.cy = minimum.cy;
    }
    return size;
}

/// Enables the controls specific to TV recording.
static void UpdateRecordingSettingsControls(HWND window) {
    const bool enabled = SendDlgItemMessageW(window, ID_RECORD_TV, BM_GETCHECK, 0, 0) == BST_CHECKED;
    constexpr int controls[]{ ID_RECORD_SIZE, ID_RECORD_RATE, ID_RECORD_SIZE_LABEL, ID_RECORD_RATE_LABEL };
    for (int id : controls) {
        EnableSettingsControl(GetDlgItem(window, id), enabled);
    }
}

/// Uses reference row spacing, native font metrics and 8-DLU margins independently of the owner form.
static SIZE LayoutRecordingSettings(HWND window) {
    const RecordingWindowData* recordingData =
        reinterpret_cast<const RecordingWindowData*>(GetWindowLongPtrW(window, DWLP_USER));
    HFONT font = recordingData == nullptr ? nullptr : recordingData->font;
    const SIZE margins = DialogUnits(font, 8, 8);
    const int margin = margins.cx;
    const int top = margins.cy;
    const SIZE spacing = DialogUnits(font, 2, 5);
    int radioHeight = 21;
    for (int id : { ID_RECORD_VIEWPORT, ID_RECORD_TV }) {
        SIZE preferred{};
        SendDlgItemMessageW(window, id, BCM_GETIDEALSIZE, 0, reinterpret_cast<LPARAM>(&preferred));
        radioHeight = std::max(radioHeight, static_cast<int>(preferred.cy));
    }
    constexpr int radioStep = 20;
    const int rowGap = std::max(9L, spacing.cy);
    SIZE buttonSize = DialogUnits(font, DIALOG_BUTTON_WIDTH_DLU, DIALOG_BUTTON_HEIGHT_DLU);
    constexpr int buttons[]{ IDOK, IDCANCEL };
    for (int id : buttons) {
        const SIZE preferred = PreferredButtonSize(GetDlgItem(window, id), buttonSize);
        buttonSize.cx = preferred.cx;
    }
    const int buttonHeight = buttonSize.cy;
    const int buttonWidth = buttonSize.cx;
    const int buttonGap = DialogUnits(font, 6, 0).cx;
    const int labelGap = std::max(4L, spacing.cx);
    const int bottomMargin = margins.cy;
    const SIZE comboGeometry = DialogUnits(font, RECORDING_COMBO_WIDTH_DLU, 90);
    const int comboWidth = comboGeometry.cx;
    const int width = DialogUnits(font, 249, 0).cx;
    const int comboLeft = width - margin - comboWidth;
    const int labelLeft = margin + DialogUnits(font, 9, 0).cx;
    const int textWidth = width - 2 * margin;
    const int televisionTop = std::max(top + radioStep + 4,
        top + radioHeight + static_cast<int>(DialogUnits(font, 0, 1).cy));
    SetWindowPos(GetDlgItem(window, ID_RECORD_VIEWPORT), nullptr, margin, top, textWidth, radioHeight,
        SWP_NOZORDER | SWP_NOACTIVATE);
    SetWindowPos(GetDlgItem(window, ID_RECORD_TV), nullptr, margin, televisionTop, textWidth, radioHeight,
        SWP_NOZORDER | SWP_NOACTIVATE);
    const int firstComboTop = televisionTop + radioHeight + rowGap;
    SetWindowPos(GetDlgItem(window, ID_RECORD_SIZE), nullptr, comboLeft, firstComboTop, comboWidth,
        comboGeometry.cy, SWP_NOZORDER | SWP_NOACTIVATE);
    RECT comboBounds{};
    GetWindowRect(GetDlgItem(window, ID_RECORD_SIZE), &comboBounds);
    const int comboHeight = comboBounds.bottom - comboBounds.top;
    const int secondComboTop = firstComboTop + comboHeight + rowGap;
    SetWindowPos(GetDlgItem(window, ID_RECORD_RATE), nullptr, comboLeft, secondComboTop, comboWidth,
        comboGeometry.cy, SWP_NOZORDER | SWP_NOACTIVATE);
    const int labelHeight = std::max(22L, DialogUnits(font, 0, 8).cy);
    const int labelWidth = comboLeft - labelLeft - labelGap;
    SetWindowPos(GetDlgItem(window, ID_RECORD_SIZE_LABEL), nullptr, labelLeft, firstComboTop, labelWidth,
        labelHeight, SWP_NOZORDER | SWP_NOACTIVATE);
    SetWindowPos(GetDlgItem(window, ID_RECORD_RATE_LABEL), nullptr, labelLeft, secondComboTop, labelWidth,
        labelHeight, SWP_NOZORDER | SWP_NOACTIVATE);
    const int noteTop = secondComboTop + comboHeight + rowGap;
    const int noteHeight = DialogUnits(font, 0, 8).cy;
    SetWindowPos(GetDlgItem(window, ID_RECORD_NOTE), nullptr, margin, noteTop, textWidth, noteHeight,
        SWP_NOZORDER | SWP_NOACTIVATE);
    const int buttonsTop = noteTop + noteHeight + rowGap;
    const int cancelLeft = width - margin - buttonWidth;
    SetWindowPos(GetDlgItem(window, IDOK), nullptr, cancelLeft - buttonGap - buttonWidth, buttonsTop,
        buttonWidth, buttonHeight, SWP_NOZORDER | SWP_NOACTIVATE);
    SetWindowPos(GetDlgItem(window, IDCANCEL), nullptr, cancelLeft, buttonsTop, buttonWidth, buttonHeight,
        SWP_NOZORDER | SWP_NOACTIVATE);
    AlignSettingsLabel(GetDlgItem(window, ID_RECORD_SIZE_LABEL), GetDlgItem(window, ID_RECORD_SIZE));
    AlignSettingsLabel(GetDlgItem(window, ID_RECORD_RATE_LABEL), GetDlgItem(window, ID_RECORD_RATE));
    AlignSettingsButton(GetDlgItem(window, IDCANCEL), GetDlgItem(window, IDOK));
    UpdateComboBoxDropDownSize(GetDlgItem(window, ID_RECORD_SIZE));
    UpdateComboBoxDropDownSize(GetDlgItem(window, ID_RECORD_RATE));
    const RECT acceptBounds = InformationControlRect(window, IDOK);
    const RECT cancelBounds = InformationControlRect(window, IDCANCEL);
    const SIZE size{ width, std::max(acceptBounds.bottom, cancelBounds.bottom) + bottomMargin };
    return size;
}

/// Recreates the shared system font and recalculates dialog geometry after metric, theme or DPI changes.
static void RefreshRecordingSettingsFont(HWND window, RecordingWindowData& data) {
    app->programIcons.Apply(window);
    const HFONT previous = data.font;
    data.font = CreateSystemDialogFont(window);
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

/// Refreshes localized recording captions and fits the buttons without altering unconfirmed choices.
static void RefreshRecordingSettingsWindow(HWND window, RecordingWindowData& data) {
    app->programIcons.Apply(window);
    const AppLanguage stringsLanguage = data.language;
    const AppLanguage commonLanguage = data.language;
    SetWindowTextW(window,
        GetLocalizedText(stringsLanguage, TXT_RECORDING_SETTINGS_TITLE));
    SetDlgItemTextW(window, ID_RECORD_VIEWPORT,
        GetLocalizedText(stringsLanguage, TXT_RECORDING_SETTINGS_VIEWPORT));
    SetDlgItemTextW(window, ID_RECORD_TV,
        GetLocalizedText(stringsLanguage, TXT_RECORDING_SETTINGS_TELEVISION));
    SetDlgItemTextW(window, ID_RECORD_SIZE_LABEL,
        GetLocalizedText(stringsLanguage, TXT_RECORDING_SETTINGS_RESOLUTION));
    SetDlgItemTextW(window, ID_RECORD_RATE_LABEL,
        GetLocalizedText(stringsLanguage, TXT_RECORDING_SETTINGS_FRAME_RATE));
    SetDlgItemTextW(window, ID_RECORD_NOTE,
        GetLocalizedText(stringsLanguage, TXT_RECORDING_SETTINGS_NOTE));
    SetDlgItemTextW(window, IDOK,
        GetLocalizedText(commonLanguage, TXT_OK));
    SetDlgItemTextW(window, IDCANCEL,
        GetLocalizedText(commonLanguage, TXT_CANCEL));
    LayoutRecordingSettings(window);
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
    selected.resolution =
        std::clamp(int(SendDlgItemMessageW(window, ID_RECORD_SIZE, CB_GETCURSEL, 0, 0)), 0, 2);
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
                SetWindowPos(window, nullptr, suggested->left, suggested->top,
                    suggested->right - suggested->left, suggested->bottom - suggested->top,
                    SWP_NOZORDER | SWP_NOACTIVATE);
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

/// Creates or restores independent modeless recording settings, matching Help and About activation and
/// topmost policy.
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
    DLGTEMPLATE* definition = LoadSystemDialogTemplate(app->instance, IDD_RECORDING_SETTINGS, nullptr);
    if (definition == nullptr) {
        return;
    }
    recordingSettingsWindow = CreateDialogIndirectParamW(app->instance, definition, nullptr,
        RecordingSettingsProc, reinterpret_cast<LPARAM>(data.get()));
    HeapFree(GetProcessHeap(), 0, definition);
    if (!recordingSettingsWindow) {
        return;
    }
    data->initialized = true;
    data.release();
    UpdateInformationWindowsTopmost(owner);
    ShowWindow(recordingSettingsWindow, SW_SHOW);
    SetForegroundWindowEx(recordingSettingsWindow);
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

/// Reports whether the running image uses the screen-saver file extension.
static bool IsScrExecutable() {
    const std::wstring path = ExecutablePath();
    const std::size_t dot = path.find_last_of(L'.');
    return dot != std::wstring::npos && _wcsicmp(path.c_str() + dot, SCREEN_SAVER_EXTENSION) == 0;
}

/// Creates a collision-resistant local file name from the current wall-clock time.
static std::wstring TimestampedFileName(const wchar_t* extension) {
    SYSTEMTIME localTime{};
    GetLocalTime(&localTime);
    wchar_t name[96]{};
    swprintf_s(name, L"%s-%04u-%02u-%02u-%02u-%02u-%02u.%s", PRODUCT_NAME, localTime.wYear, localTime.wMonth,
        localTime.wDay, localTime.wHour, localTime.wMinute, localTime.wSecond, extension);
    return name;
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

/// Orders displays with the primary first, then by their top and left screen coordinates.
static bool CompareDisplayMonitors(const DisplayMonitor& left, const DisplayMonitor& right) {
    if (left.primary != right.primary) {
        return left.primary;
    }
    if (left.rect.top != right.rect.top) {
        return left.rect.top < right.rect.top;
    }
    return left.rect.left < right.rect.left;
}

/// Enumerates displays with the primary monitor first and stable geometric ordering.
static std::vector<DisplayMonitor> AvailableMonitors() {
    std::vector<DisplayMonitor> monitors;
    EnumDisplayMonitors(nullptr, nullptr, CollectDisplayMonitor, reinterpret_cast<LPARAM>(&monitors));
    std::stable_sort(monitors.begin(), monitors.end(), CompareDisplayMonitors);
    return monitors;
}

/// Tests membership in the semicolon-delimited monitor-device setting.
static bool MonitorDeviceSelected(const std::wstring& devices, const std::wstring& device) {
    std::size_t begin = 0;
    while (begin <= devices.size()) {
        const std::size_t end = devices.find(L';', begin);
        const std::wstring token =
            devices.substr(begin, end == std::wstring::npos ? std::wstring::npos : end - begin);
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

/// Returns only enabled displays, retaining the common display order for the shared scene.
static std::vector<DisplayMonitor> SelectedMonitors() {
    std::vector<DisplayMonitor> monitors = AvailableMonitors();
    if (app->mode == RunMode::Application) {
        std::erase_if(monitors, [](const DisplayMonitor& monitor) {
            return !app->settings.animationMonitorDevice.empty()
                && !MonitorDeviceSelected(app->settings.animationMonitorDevice, monitor.device);
        });
    }
    return monitors;
}

/// Replaces an unavailable or oversized named pattern with the mixture selection.
static bool ValidatePatternSelection(AppSettings& settings, unsigned columns, unsigned rows) {
    if (!app->patternCatalogReady || settings.patternId.empty() || columns == 0 || rows == 0) {
        return false;
    }
    const unsigned selection = PatternCatalog::Find(settings.patternId);
    if (selection) {
        const LifePattern& pattern = PatternCatalog::All()[selection - 1];
        if (pattern.width <= columns && pattern.height <= rows) {
            return false;
        }
    }
    settings.patternId.clear();
    ShowTransientStatus(GetLocalizedText(ActiveLanguage(), TXT_PATTERN_FALLBACK));
    if (app->mode == RunMode::Application) {
        settings.Save();
    }
    return true;
}

/// Publishes scene options to the render workers and applies shared-board display settings.
static void SynchronizeRuntimeSettings() {
    const std::lock_guard<std::mutex> lock(app->rendererMutex);
    app->cellSize.store(app->settings.cellSize, std::memory_order_relaxed);
    app->densityPercent.store(app->settings.densityPercent, std::memory_order_relaxed);
    app->generationsPerSecond.store(app->settings.generationsPerSecond, std::memory_order_relaxed);
    app->patternsOnly.store(app->settings.patternsOnly, std::memory_order_relaxed);
    if (app->patternCatalogReady) {
        app->patternSelection.store(PatternCatalog::Find(app->settings.patternId), std::memory_order_relaxed);
    }
    if (!app->settings.randomAliveColor || app->configuredAliveColor != app->settings.aliveColor) {
        app->sceneAliveColor = app->settings.aliveColor;
    }
    if (!app->settings.randomBackgroundColor
            || app->configuredBackgroundColor != app->settings.backgroundColor) {
        app->sceneBackgroundColor = app->settings.backgroundColor;
    }
    if (!app->settings.randomGridColor || app->configuredGridColor != app->settings.gridColor) {
        app->sceneGridColor = app->settings.gridColor;
    }
    app->configuredAliveColor = app->settings.aliveColor;
    app->configuredBackgroundColor = app->settings.backgroundColor;
    app->configuredGridColor = app->settings.gridColor;
    app->showGrid = app->settings.showGrid;
    app->randomAliveColor = app->settings.randomAliveColor;
    app->randomBackgroundColor = app->settings.randomBackgroundColor;
    app->randomGridColor = app->settings.randomGridColor;
    if (!app->surfaces.empty()) {
        app->surfaces.front()->renderer->SetColors(app->sceneAliveColor, app->sceneBackgroundColor);
        app->surfaces.front()->renderer->SetGrid(app->showGrid, app->sceneGridColor);
        if (!app->surfaces.front()->renderer->SetAutoReset(app->settings.autoReset)) {
            PostMessageW(app->controlWindow ? app->controlWindow : app->surfaces.front()->window,
                RENDERER_FAILED, 0, 0);
        }
    }
}

/// Chooses a different scene color distinct from the other two scene colors.
static bool RandomizeSceneColor(COLORREF& sceneColor, COLORREF firstOtherColor, COLORREF secondOtherColor) {
    while (true) {
        COLORREF color = 0;
        const NTSTATUS status = BCryptGenRandom(nullptr, reinterpret_cast<PUCHAR>(&color),
            sizeof(color), BCRYPT_USE_SYSTEM_PREFERRED_RNG);
        if (!BCRYPT_SUCCESS(status)) {
            return false;
        }
        color &= 0xFFFFFF;
        if (color != sceneColor && color != firstOtherColor && color != secondOtherColor) {
            sceneColor = color;
            return true;
        }
    }
}

/// Randomizes enabled scene colors at each restart without overwriting any saved color.
static bool RandomizeSceneColors() {
    if (app->randomAliveColor
            && !RandomizeSceneColor(app->sceneAliveColor, app->sceneBackgroundColor, app->sceneGridColor)) {
        return false;
    }
    if (app->randomBackgroundColor
            && !RandomizeSceneColor(app->sceneBackgroundColor, app->sceneAliveColor, app->sceneGridColor)) {
        return false;
    }
    if (app->randomGridColor
            && !RandomizeSceneColor(app->sceneGridColor, app->sceneAliveColor, app->sceneBackgroundColor)) {
        return false;
    }
    return true;
}

/// Seeds a fresh CPU board, selects its scene colors and uploads it to the shared GPU world.
static bool ResetSimulationBoard() {
    const unsigned width =
        static_cast<unsigned>(std::max(1L, app->worldBounds.right - app->worldBounds.left));
    const unsigned height =
        static_cast<unsigned>(std::max(1L, app->worldBounds.bottom - app->worldBounds.top));
    const unsigned size = app->cellSize.load(std::memory_order_relaxed);
    Simulation initial;
    initial.Resize((width + size - 1) / size, (height + size - 1) / size);
    if (app->patternsOnly.load(std::memory_order_relaxed)) {
        if (!initial.SeedPatterns(app->patternSelection.load(std::memory_order_relaxed))) {
            return false;
        }
    } else {
        initial.Randomize(app->densityPercent.load(std::memory_order_relaxed));
    }
    app->surfaces.front()->renderer->SetCellSize(size);
    if (!app->surfaces.front()->renderer->SetBoard(initial.Width(), initial.Height(), initial.Cells())) {
        return false;
    }
    if (!RandomizeSceneColors()) {
        return false;
    }
    app->surfaces.front()->renderer->SetColors(app->sceneAliveColor, app->sceneBackgroundColor);
    app->surfaces.front()->renderer->SetGrid(app->showGrid, app->sceneGridColor);
    return true;
}

/// Advances or resets the shared world and draws one output while holding the shared GPU lock.
/// Updates generation timing and returns false if simulation or rendering fails.
static bool RenderSurfaceFrame(RenderSurface* surface, bool advancesWorld, double elapsed,
        double& generations, LARGE_INTEGER& previous) {
    bool failed = false;
    const std::lock_guard<std::mutex> lock(app->rendererMutex);
    if (app->patternsOnly.load(std::memory_order_relaxed) && !app->patternCatalogReady.load()) {
        return true;
    }
    if (advancesWorld) {
        bool reset = app->resetRequested.exchange(false, std::memory_order_relaxed);
        if (!reset) {
            failed = FAILED(surface->renderer->Advance(0));
            reset = surface->renderer->ResetRequested();
        }
        if (!failed && !reset) {
            if (!app->paused.load(std::memory_order_relaxed)) {
                generations = std::min(8.0, generations + std::min(elapsed, 0.25)
                    * app->generationsPerSecond.load(std::memory_order_relaxed));
                const unsigned count = static_cast<unsigned>(generations);
                for (unsigned index = 0; index < count; ++index) {
                    const HRESULT advanced = surface->renderer->Advance(1);
                    failed = FAILED(advanced);
                    reset = surface->renderer->ResetRequested();
                    if (failed || reset || advanced == S_FALSE) {
                        break;
                    }
                    generations -= 1.0;
                }
            } else {
                generations = 0.0;
            }
        }
        if (!failed && reset) {
            try {
                failed = !ResetSimulationBoard();
            } catch (const std::exception&) {
                failed = true;
            }
            generations = 0.0;
            QueryPerformanceCounter(&previous);
        }
    }
    if (!failed) {
        failed = FAILED(surface->renderer->Draw());
    }
    return !failed;
}

/// Advances the shared simulation from its primary output and draws this monitor under the shared GPU lock.
/// Uses the output framepacer when available and propagates render failures to the UI thread.
static void RenderSurfaceLoop(RenderSurface* surface) {
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_ABOVE_NORMAL);
    DWORD multimediaTaskIndex = 0;
    HANDLE multimediaTask = AvSetMmThreadCharacteristicsW(L"Games", &multimediaTaskIndex);
    if (multimediaTask) {
        AvSetMmThreadPriority(multimediaTask, AVRT_PRIORITY_HIGH);
    }
    LARGE_INTEGER frequency{};
    LARGE_INTEGER previous{};
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&previous);
    const double rate = std::clamp(surface->refreshFrequency, 24.0, 360.0);
    const double periodTicks = static_cast<double>(frequency.QuadPart) / rate;
    bool presentationPaced = surface->renderer->UsesVerticalBlankWait();
    HANDLE timer = presentationPaced ? nullptr : CreateRenderFrameTimer();
    double generations = 0.0;
    const bool advancesWorld = surface == app->surfaces.front().get();
    while (!app->closing.load(std::memory_order_relaxed)
            && !surface->stopRequested.load(std::memory_order_relaxed)) {
        const HRESULT waited = presentationPaced ? surface->renderer->WaitForNextFrame() : S_OK;
        if (app->closing.load(std::memory_order_relaxed)
                || surface->stopRequested.load(std::memory_order_relaxed)) {
            break;
        }
        if (FAILED(waited)) {
            timer = CreateRenderFrameTimer();
            presentationPaced = false;
            continue;
        }
        LARGE_INTEGER started{};
        QueryPerformanceCounter(&started);
        const double elapsed =
            static_cast<double>(started.QuadPart - previous.QuadPart) / frequency.QuadPart;
        previous = started;
        if (!RenderSurfaceFrame(surface, advancesWorld, elapsed, generations, previous)) {
            PostMessageW(app->controlWindow ? app->controlWindow : surface->window, RENDERER_FAILED, 0, 0);
            break;
        }
        if (surface->renderedFrames.fetch_add(1, std::memory_order_relaxed) == 0 && app->controlWindow) {
            PostMessageW(app->controlWindow, UPDATE_SETTINGS_ACTION_BUTTONS, 0, 0);
        }
        if (!presentationPaced) {
            WaitForRenderDeadline(timer, static_cast<double>(started.QuadPart) + periodTicks,
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
    if (!app || !window || window != app->controlWindow) {
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

/// Returns the output whose recording remains active across monitor-selection changes.
static RenderSurface* RecordingSurface() {
    return app ? app->recordingSource : nullptr;
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

/// Reads recording state without waiting for the primary render thread.
static bool PrimaryIsRecording() {
    RenderSurface* surface = PrimarySurface();
    if (!surface || !surface->renderer) {
        return false;
    }
    return surface->renderer->IsRecording();
}

/// Reports whether the primary surface has a rendered frame and can accept capture commands.
static bool HasReadyPrimarySurface() {
    RenderSurface* surface = PrimarySurface();
    return surface
        && surface->renderer
        && surface->renderedFrames.load(std::memory_order_relaxed) != 0
        && !surface->stopRequested.load(std::memory_order_relaxed);
}

/// Reports whether any animation surface can accept a global pause or resume command.
static bool HasReadyAnimationSurface() {
    if (!app) {
        return false;
    }
    for (const std::unique_ptr<RenderSurface>& surface : app->surfaces) {
        if (surface->renderer
                && surface->renderedFrames.load(std::memory_order_relaxed) != 0
                && !surface->stopRequested.load(std::memory_order_relaxed)) {
            return true;
        }
    }
    return false;
}

/// Replaces the single status-bar part without changing application state.
static void SetStatus(const wchar_t* text) {
    if (app && app->status) {
        if (app->changingScreenSaver) {
            text = GetLocalizedText(ActiveLanguage(), app->uninstallingScreenSaver
                ? TXT_UNINSTALLING_SCREEN_SAVER
                : TXT_INSTALLING_SCREEN_SAVER);
        }
        SendMessageW(app->status, SB_SETTEXTW, 0, reinterpret_cast<LPARAM>(text));
    }
}

/// Chooses the persistent status text implied by current runtime state.
static const wchar_t* CurrentStatusText() {
    const AppLanguage stringsLanguage = ActiveLanguage();
    if (!HasReadyPrimarySurface()) {
        return GetLocalizedText(ActiveLanguage(), TXT_READY_STATUS);
    }
    if (PrimaryIsRecording()) {
        return GetLocalizedText(stringsLanguage, TXT_RECORDING);
    }
    if (app && app->paused.load(std::memory_order_relaxed)) {
        return GetLocalizedText(ActiveLanguage(), TXT_PAUSED_STATUS);
    }
    return GetLocalizedText(stringsLanguage, TXT_ANIMATION_RUNNING);
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

/// Starts the elevated install or uninstall helper and polls it asynchronously.
static void RequestScreenSaverChange(HWND owner) {
    if (!app || app->changingScreenSaver) {
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
    app->changingScreenSaver = true;
    app->uninstallingScreenSaver = uninstall;
    KillTimer(owner, ID_STATUS_RESET_TIMER);
    SetStatus(GetLocalizedText(ActiveLanguage(),
        uninstall ? TXT_UNINSTALLING_SCREEN_SAVER : TXT_INSTALLING_SCREEN_SAVER));
    UpdateWindow(app->status);
    EnableSettingsControl(GetDlgItem(SettingsContentWindow(owner), ID_INSTALL), false,
        reinterpret_cast<const SettingsWindowData*>(GetWindowLongPtrW(owner, GWLP_USERDATA)));
    if (!ShellExecuteExW(&execute) || !execute.hProcess) {
        app->changingScreenSaver = false;
        app->uninstallingScreenSaver = false;
        EnableSettingsControl(GetDlgItem(SettingsContentWindow(owner), ID_INSTALL), true);
        if (uninstall) {
            ShowTransientStatus(GetLocalizedText(ActiveLanguage(), TXT_UNINSTALLATION_FAILED));
        } else {
            ShowTransientStatus(GetLocalizedText(ActiveLanguage(), TXT_INSTALLATION_FAILED));
        }
        return;
    }
    app->installProcess = execute.hProcess;
    SetTimer(owner, ID_INSTALL_POLL_TIMER, 100, nullptr);
}

/// Synchronizes the record button caption and enabled settings actions with the current animation state.
static void UpdateRecordingButton() {
    if (!app || !app->controlWindow) {
        return;
    }
    const AppLanguage stringsLanguage = ActiveLanguage();
    SetDlgItemTextW(SettingsContentWindow(app->controlWindow), ID_RECORD_TOGGLE, PrimaryIsRecording()
        ? GetLocalizedText(stringsLanguage, TXT_STOP_RECORDING)
        : GetLocalizedText(stringsLanguage, TXT_START_RECORDING));
    UpdateSettingsActionButtons(app->controlWindow);
}

/// Stops capture for the retained recording output while holding the shared GPU lock.
static bool PrepareSurfaceRecordingStop(RenderSurface& surface) {
    if (app->recordingSource != &surface) {
        return false;
    }
    const std::lock_guard<std::mutex> lock(app->rendererMutex);
    surface.renderer->PrepareRecordingStop();
    return true;
}

/// Stops capture under the renderer lock, then finalizes the MP4 without blocking the surface's animation
/// thread.
static bool StopSurfaceRecording(RenderSurface& surface) {
    if (!PrepareSurfaceRecordingStop(surface)) {
        return false;
    }
    surface.renderer->FinishRecordingStop();
    return true;
}

/// Finalizes recording and reports encoder failures that occur before or during finalization.
static void StopRecording() {
    RenderSurface* surface = PrimarySurface();
    if (!surface || !surface->renderer) {
        return;
    }
    HRESULT error = surface->renderer->RecordingError();
    if (!StopSurfaceRecording(*surface)) {
        return;
    }
    app->recordingSource = nullptr;
    KillTimer(app->controlWindow, ID_RECORD_CHECK_TIMER);
    if (SUCCEEDED(error)) {
        error = surface->renderer->RecordingError();
    }
    ShowTransientStatus(GetLocalizedText(ActiveLanguage(),
        FAILED(error) ? TXT_RECORDING_FAILED : TXT_RECORDING_SAVED));
    UpdateRecordingButton();
}

/// Starts recording one animation surface while holding its renderer lock.
static bool StartSurfaceRecording(RenderSurface& surface, const wchar_t* file, unsigned recordingRate) {
    const std::lock_guard<std::mutex> lock(app->rendererMutex);
    return surface.renderer->StartRecording(file, recordingRate, app->settings.recording);
}

/// Tests recording support while holding the shared GPU lock, without retaining the lock during a dialog.
static bool CheckSurfaceRecordingSupport(RenderSurface& surface, unsigned recordingRate) {
    const std::lock_guard<std::mutex> lock(app->rendererMutex);
    return surface.renderer->CheckRecordingSupport(recordingRate, app->settings.recording);
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
        MessageBoxW(owner, GetLocalizedText(ActiveLanguage(), TXT_RECORDING_FAILED), PRODUCT_NAME,
            MB_OK | MB_ICONERROR);
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
    surface = PrimarySurface();
    if (!surface || !surface->renderer || app->closing.load(std::memory_order_relaxed)) {
        return;
    }
    const bool started = StartSurfaceRecording(*surface, file, surface->refreshRate);
    if (started) {
        app->recordingSource = surface;
        KillTimer(app->controlWindow, ID_STATUS_RESET_TIMER);
        SetTimer(app->controlWindow, ID_RECORD_CHECK_TIMER, 250, nullptr);
        SetStatus(GetLocalizedText(ActiveLanguage(), TXT_RECORDING));
    } else {
        ShowTransientStatus(GetLocalizedText(ActiveLanguage(), TXT_RECORDING_FAILED));
    }
    UpdateRecordingButton();
}

/// Checks PNG snapshot support while holding the GPU lock shared by all outputs.
static bool CheckSurfaceSnapshotSupport(RenderSurface& surface) {
    const std::lock_guard<std::mutex> lock(app->rendererMutex);
    return surface.renderer->CheckSnapshotSupport();
}

/// Writes a PNG snapshot while holding the GPU lock shared by all outputs.
static bool SaveSurfaceSnapshot(RenderSurface& surface, const wchar_t* file) {
    const std::lock_guard<std::mutex> lock(app->rendererMutex);
    return surface.renderer->SaveSnapshot(file);
}

/// Prompts for a PNG path, reacquires the current output and reports the snapshot result.
static void SaveSnapshot(HWND owner) {
    RenderSurface* surface = PrimarySurface();
    if (!app || app->mode != RunMode::Application || !surface || !surface->renderer) {
        return;
    }
    if (!CheckSurfaceSnapshotSupport(*surface)) {
        MessageBoxW(owner, GetLocalizedText(ActiveLanguage(), TXT_SNAPSHOT_FAILED), PRODUCT_NAME,
            MB_OK | MB_ICONERROR);
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
    surface = PrimarySurface();
    if (!surface || !surface->renderer || app->closing.load(std::memory_order_relaxed)) {
        return;
    }
    const bool saved = SaveSurfaceSnapshot(*surface, file);
    if (saved) {
        ShowTransientStatus(GetLocalizedText(ActiveLanguage(), TXT_SNAPSHOT_SAVED));
    } else {
        ShowTransientStatus(GetLocalizedText(ActiveLanguage(), TXT_SNAPSHOT_FAILED));
    }
}

/// Requests termination of every render worker and joins all running threads.
static void StopRenderWorkers() {
    for (const std::unique_ptr<RenderSurface>& surface : app->surfaces) {
        surface->stopRequested.store(true, std::memory_order_relaxed);
    }
    for (const std::unique_ptr<RenderSurface>& surface : app->surfaces) {
        if (surface->renderThread.joinable()) {
            surface->renderThread.join();
        }
    }
}

/// Releases saver inhibition, stops recording and workers, then destroys the animation windows.
static void StopRenderSurfaces() {
    ReleaseScreenSaverInhibition(*app);
    StopRecording();
    StopRenderWorkers();
    for (const std::unique_ptr<RenderSurface>& surface : app->surfaces) {
        if (surface->window) {
            DestroyWindow(surface->window);
        }
    }
    app->surfaces.clear();
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
        const int result = MessageBoxW(owner, GetLocalizedText(ActiveLanguage(), TXT_RECORDING_CLOSE_WARNING),
            PRODUCT_NAME, MB_OKCANCEL | MB_ICONWARNING | MB_DEFBUTTON2);
        app->confirmingClose = false;
        if (result != IDOK) {
            return;
        }
    }
    if (app->closing.exchange(true, std::memory_order_relaxed)) {
        return;
    }
    app->patternCatalogThread.request_stop();
    ReleaseScreenSaverInhibition(*app);
    StopRecording();
    PostQuitMessage(0);
}

/// Applies the screen-saver startup grace period and mouse-motion threshold.
static bool SaverShouldExitOnMouse() {
    if (!app || app->mode != RunMode::ScreenSaver || GetTickCount64() - app->saverStarted < 900) {
        return false;
    }
    POINT current{};
    GetCursorPos(&current);
    return std::abs(current.x - app->initialMouse.x) > 4 || std::abs(current.y - app->initialMouse.y) > 4;
}

/// Shows the cursor after movement and schedules hiding while an EXE animation is idle.
static void UpdateAnimationCursor(HWND window, RenderSurface& surface) {
    POINT current{};
    if (!GetCursorPos(&current)) {
        return;
    }
    if (!surface.trackingMouse
            || current.x != surface.mousePosition.x
            || current.y != surface.mousePosition.y) {
        surface.mousePosition = current;
        surface.mouseMoved = GetTickCount64();
        surface.cursorHidden = false;
        SetTimer(window, ID_ANIMATION_CURSOR_TIMER, ANIMATION_CURSOR_HIDE_DELAY, nullptr);
        if (!surface.trackingMouse) {
            TRACKMOUSEEVENT tracking{ sizeof(tracking), TME_LEAVE, window, 0 };
            surface.trackingMouse = TrackMouseEvent(&tracking) != FALSE;
        }
    }
    SetCursor(surface.cursorHidden ? nullptr : LoadCursorW(nullptr, IDC_ARROW));
}

/// Reports whether a selected monitor still matches the recording output device and bounds.
static bool IsRecordingMonitorSelected(const std::vector<DisplayMonitor>& monitors,
        const RenderSurface& recording) {
    for (const DisplayMonitor& monitor : monitors) {
        if (monitor.device == recording.monitorDevice && EqualRect(&monitor.rect, &recording.bounds)) {
            return true;
        }
    }
    return false;
}

/// Recreates output windows for the selected layout while retaining an active recording output.
static void RebuildOutputs() {
    RenderSurface* recording = RecordingSurface();
    if (recording) {
        const std::vector<DisplayMonitor> selected = SelectedMonitors();
        if (!IsRecordingMonitorSelected(selected, *recording)) {
            StopRecording();
            recording = nullptr;
        }
    }
    if (recording) {
        StopRenderWorkers();
        std::unique_ptr<RenderSurface> retained;
        for (std::unique_ptr<RenderSurface>& surface : app->surfaces) {
            if (surface.get() == recording) {
                retained = std::move(surface);
            } else if (surface->window) {
                DestroyWindow(surface->window);
            }
        }
        app->surfaces.clear();
        app->surfaces.push_back(std::move(retained));
    } else {
        StopRenderSurfaces();
    }
    if ((app->mode != RunMode::Settings || app->previewActive) && !StartRenderSurfaces()) {
        PostMessageW(app->controlWindow, RENDERER_FAILED, 0, 0);
    }
    UpdateControlWindowTopmost(app->controlWindow);
    if (app->controlWindow) {
        PostMessageW(app->controlWindow, UPDATE_SETTINGS_ACTION_BUTTONS, 0, 0);
    }
}

/// Raises standalone animation surfaces on an explicit click without restoring the control window or forcing
/// TopMost.
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

/// Resizes one output while holding the shared GPU lock.
static void ResizeRenderSurface(RenderSurface& surface, unsigned width, unsigned height) {
    const std::lock_guard<std::mutex> lock(app->rendererMutex);
    surface.renderer->Resize(width, height);
}

/// Handles animation-window lifecycle, resizing, cursor visibility and EXE or SCR input commands.
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
        case WM_SYSCOMMAND:
            if ((wParam & 0xFFF0) == SC_SCREENSAVE && ShouldInhibitScreenSaver()) {
                return 0;
            }
            break;
        case WM_SIZE:
            if (surface && surface->renderer) {
                ResizeRenderSurface(*surface, LOWORD(lParam), HIWORD(lParam));
                if (surface == RecordingSurface() && !surface->renderer->IsRecording()) {
                    StopRecording();
                }
            }
            return 0;
        case WM_SETCURSOR:
            if (app && app->mode == RunMode::Application && surface && LOWORD(lParam) == HTCLIENT) {
                UpdateAnimationCursor(window, *surface);
                return TRUE;
            }
            break;
        case WM_TIMER:
            if (app && app->mode == RunMode::Application && surface && wParam == ID_ANIMATION_CURSOR_TIMER) {
                KillTimer(window, ID_ANIMATION_CURSOR_TIMER);
                const ULONGLONG elapsed = GetTickCount64() - surface->mouseMoved;
                if (elapsed < ANIMATION_CURSOR_HIDE_DELAY) {
                    SetTimer(window, ID_ANIMATION_CURSOR_TIMER,
                        static_cast<UINT>(ANIMATION_CURSOR_HIDE_DELAY - elapsed), nullptr);
                } else {
                    POINT current{};
                    if (GetCursorPos(&current) && WindowFromPoint(current) == window) {
                        surface->cursorHidden = true;
                        SetCursor(nullptr);
                    }
                }
                return 0;
            }
            break;
        case WM_MOUSELEAVE:
            if (app && app->mode == RunMode::Application && surface) {
                KillTimer(window, ID_ANIMATION_CURSOR_TIMER);
                surface->trackingMouse = false;
                surface->cursorHidden = false;
                return 0;
            }
            break;
        case WM_MOUSEMOVE:
            if (app && app->mode == RunMode::Application && surface) {
                UpdateAnimationCursor(window, *surface);
            } else if (SaverShouldExitOnMouse()) {
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
                        app->paused.store(!app->paused.load(std::memory_order_relaxed),
                            std::memory_order_relaxed);
                        PostMessageW(app->controlWindow, UPDATE_SETTINGS_ACTION_BUTTONS, 0, 0);
                    }
                    return 0;
                }
            }
            break;
        case WM_ACTIVATEAPP:
            if (app->mode == RunMode::ScreenSaver
                    && !wParam
                    && surface
                    && !surface->stopRequested.load(std::memory_order_relaxed)
                    && GetTickCount64() - app->saverStarted >= 900) {
                CloseApplication();
            }
            return 0;
        case RENDERER_FAILED:
            MessageBoxW(app->controlWindow, GetLocalizedText(ActiveLanguage(), TXT_RENDERER_FAILED),
                PRODUCT_NAME, MB_OK | MB_ICONERROR);
            CloseApplication();
            return 0;
        case WM_CLOSE:
            CloseApplication();
            return 0;
        case WM_ERASEBKGND:
            return 1;
    }
    return DefWindowProcW(window, msg, wParam, lParam);
}

/// Creates a separate system preview or selected-monitor outputs and starts their render workers.
static bool StartRenderSurfaces() {
    if (!app->surfaces.empty() && app->surfaces.front()->renderThread.joinable()) {
        return true;
    }
    const bool systemPreview = app->mode == RunMode::Preview;
    std::vector<DisplayMonitor> monitors;
    std::vector<MonitorViewport> layout;
    if (systemPreview) {
        GetClientRect(app->previewParent, &app->worldBounds);
    } else {
        monitors = SelectedMonitors();
        if (monitors.empty()) {
            return true;
        }
        std::vector<RECT> rectangles;
        for (const DisplayMonitor& monitor : monitors) {
            rectangles.push_back(monitor.rect);
        }
        const bool compact = app->mode == RunMode::Application
            && monitors.size() != AvailableMonitors().size();
        layout = BuildMonitorLayout(rectangles, compact);
        app->worldBounds = MonitorLayoutBounds(layout);
    }
    Renderer* shared = app->surfaces.empty() ? nullptr : app->surfaces.front()->renderer.get();
    const std::size_t outputCount = systemPreview ? 1 : monitors.size();
    for (std::size_t index = 0; index < outputCount; ++index) {
        RenderSurface* retained = systemPreview ? nullptr : MonitorSurface(monitors[index].device);
        if (retained) {
            retained->renderer->SetView(app->worldBounds, layout[index].logical);
            continue;
        }
        std::unique_ptr<RenderSurface> surface = std::make_unique<RenderSurface>();
        surface->bounds = app->worldBounds;
        if (!systemPreview) {
            surface->bounds = monitors[index].rect;
            surface->monitorDevice = monitors[index].device;
        }
        DWORD style = WS_POPUP | WS_VISIBLE;
        DWORD extended = WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE;
        HWND parent = nullptr;
        const RECT bounds = surface->bounds;
        if (systemPreview) {
            parent = app->previewParent;
            style = WS_CHILD | WS_VISIBLE;
            extended = 0;
        } else if (app->mode == RunMode::ScreenSaver) {
            extended = WS_EX_TOPMOST | WS_EX_TOOLWINDOW;
        }
        surface->window = CreateWindowExW(extended, RENDER_CLASS, PRODUCT_NAME, style, bounds.left,
            bounds.top, bounds.right - bounds.left, bounds.bottom - bounds.top, parent, nullptr,
            app->instance, surface.get());
        if (!surface->window) {
            return false;
        }
        surface->renderer = std::make_unique<Renderer>();
        if (!surface->renderer->Initialize(surface->window, shared)) {
            DestroyWindow(surface->window);
            return false;
        }
        surface->renderer->SetView(app->worldBounds,
            systemPreview ? app->worldBounds : layout[index].logical);
        surface->refreshFrequency = CurrentRefreshRate(surface->window);
        surface->refreshRate = static_cast<unsigned>(std::lround(surface->refreshFrequency));
        shared = shared ? shared : surface->renderer.get();
        app->surfaces.push_back(std::move(surface));
    }
    Renderer& worldRenderer = *app->surfaces.front()->renderer;
    const unsigned maximum = worldRenderer.MaximumBoardDimension();
    const unsigned width = static_cast<unsigned>(app->worldBounds.right - app->worldBounds.left);
    const unsigned height = static_cast<unsigned>(app->worldBounds.bottom - app->worldBounds.top);
    app->minimumCellSize = std::max({
        1U,
        (width + maximum - 1) / maximum,
        (height + maximum - 1) / maximum
    });
    app->settings.cellSize = std::max(app->settings.cellSize, app->minimumCellSize);
    ValidatePatternSelection(app->settings, (width + app->settings.cellSize - 1) / app->settings.cellSize,
        (height + app->settings.cellSize - 1) / app->settings.cellSize);
    std::vector<RECT> visibleRegions;
    if (systemPreview) {
        visibleRegions.push_back(app->worldBounds);
    } else {
        for (const MonitorViewport& viewport : layout) {
            visibleRegions.push_back(viewport.logical);
        }
    }
    if (!worldRenderer.SetVisibleRegions(app->worldBounds, visibleRegions)) {
        return false;
    }
    SynchronizeRuntimeSettings();
    if (app->mode == RunMode::Application) {
        UpdateControlWindowTopmost(app->controlWindow);
    }
    if (app->settings.patternsOnly && !app->patternCatalogReady) {
        return true;
    }
    try {
        if (!ResetSimulationBoard()) {
            return false;
        }
    } catch (const std::exception&) {
        return false;
    }
    app->resetRequested.store(false, std::memory_order_relaxed);
    for (const std::unique_ptr<RenderSurface>& surface : app->surfaces) {
        surface->stopRequested.store(false, std::memory_order_relaxed);
        surface->renderThread = std::thread(RenderSurfaceLoop, surface.get());
    }
    return true;
}

/// Ends settings preview and restores the settings window's normal Z order.
static void StopSettingsPreview(HWND settingsWindow) {
    if (!app || !app->previewActive) {
        return;
    }
    StopRenderSurfaces();
    app->previewActive = false;
    SetWindowPos(settingsWindow, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
    UpdateInformationWindowsTopmost(settingsWindow);
}

/// Starts the shared preview scene and activates settings using the common saver completion sequence.
static bool StartSettingsPreview(HWND settingsWindow, SettingsWindowData& data) {
    if (!app || app->previewActive) {
        return app && app->previewActive;
    }
    StopRenderSurfaces();
    SynchronizeRuntimeSettings();
    const bool created = StartRenderSurfaces();
    if (!created || app->surfaces.empty()) {
        StopRenderSurfaces();
        MessageBoxW(settingsWindow, GetLocalizedText(data.language, TXT_RENDERER_FAILED), PRODUCT_NAME,
            MB_OK | MB_ICONERROR);
        return false;
    }
    app->previewActive = true;
    SetWindowPos(settingsWindow, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
    UpdateInformationWindowsTopmost(settingsWindow);
    SetForegroundWindow(settingsWindow);
    return true;
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

/// Compares exact fractional refresh rates, placing unavailable values before known values in ascending
/// order.
static int CompareMonitorRefreshRates(const DISPLAYCONFIG_RATIONAL& left,
        const DISPLAYCONFIG_RATIONAL& right) {
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

/// Compares stable monitor indices by the chosen column, retaining source order for equal values.
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
        comparison = CompareMonitorRefreshRates(leftEntry.details.refreshRate,
            rightEntry.details.refreshRate);
    } else if (data->monitorSortColumn == 4) {
        const UINT leftDepth = leftEntry.details.bitsPerColor != 0
            ? leftEntry.details.bitsPerColor
            : leftEntry.details.bitsPerPixel;
        const UINT rightDepth = rightEntry.details.bitsPerColor != 0
            ? rightEntry.details.bitsPerColor
            : rightEntry.details.bitsPerPixel;
        comparison = CompareMonitorValues(leftDepth, rightDepth);
        if (comparison == 0) {
            comparison = _wcsicmp(leftEntry.text[4].c_str(), rightEntry.text[4].c_str());
        }
    } else {
        comparison = _wcsicmp(leftEntry.text[data->monitorSortColumn].c_str(),
            rightEntry.text[data->monitorSortColumn].c_str());
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

/// Selects all monitor rows with Ctrl+A without changing checkbox states.
static LRESULT CALLBACK MonitorListSubclassProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam,
        UINT_PTR subclassId, DWORD_PTR referenceData) {
    UNREFERENCED_PARAMETER(referenceData);
    bool selectAll = msg == WM_KEYDOWN
        && wParam == L'A'
        && GetKeyState(VK_CONTROL) < 0
        && GetKeyState(VK_MENU) >= 0;
    if (selectAll) {
        ListView_SetItemState(window, -1, LVIS_SELECTED, LVIS_SELECTED);
        return 0;
    }
    if (msg == WM_NCDESTROY) {
        RemoveWindowSubclass(window, MonitorListSubclassProc, subclassId);
    }
    return DefSubclassProc(window, msg, wParam, lParam);
}

/// Updates the common monitor-column captions without changing column widths or row contents.
static void UpdateMonitorListColumns(HWND list, AppLanguage language) {
    const MonitorColumnText strings = MonitorColumnsText(language);
    const wchar_t* titles[]{
        GetLocalizedText(language, TXT_MONITOR),
        strings.model,
        GetLocalizedText(language, TXT_RESOLUTION),
        strings.refreshRate,
        strings.bitDepth,
        strings.colorFormat,
        strings.colorSpace,
        GetLocalizedText(language, TXT_POSITION)
    };
    LVCOLUMNW column{};
    column.mask = LVCF_TEXT;
    for (int index = 0; index < MONITOR_COLUMN_COUNT; index++) {
        column.pszText = const_cast<LPWSTR>(titles[index]);
        ListView_SetColumn(list, index, &column);
    }
}

/// Formats the shared monitor details once for display and native list sorting.
static void UpdateMonitorListEntry(MonitorListEntry& entry, const DisplayMonitor& monitor,
        const MonitorDetails& details, AppLanguage language) {
    entry.details = details;
    entry.text[0] = MonitorDisplayName(monitor.device);
    if (monitor.primary) {
        entry.text[0] += std::wstring(L" (") + GetLocalizedText(language, TXT_PRIMARY) + L")";
    }
    entry.text[1] = details.model.empty() ? L"—" : details.model;
    wchar_t value[96]{};
    swprintf_s(value, L"%ld × %ld", monitor.rect.right - monitor.rect.left,
        monitor.rect.bottom - monitor.rect.top);
    entry.text[2] = value;
    entry.text[3] = MonitorRefreshRateText(details);
    entry.text[4] = MonitorBitDepthText(details, language);
    entry.text[5] = MonitorColorFormatText(details.colorEncoding);
    entry.text[6] = MonitorColorSpaceText(details.colorSpace);
    swprintf_s(value, L"x=%ld, y=%ld", monitor.rect.left, monitor.rect.top);
    entry.text[7] = value;
}

/// Inserts one monitor row with the stable display index used by sorting and selection handling.
static int InsertMonitorListEntry(HWND list, std::size_t index, MonitorListEntry& entry) {
    LVITEMW item{};
    item.mask = LVIF_TEXT | LVIF_PARAM;
    item.iItem = static_cast<int>(index);
    item.pszText = entry.text[0].data();
    item.lParam = static_cast<LPARAM>(index);
    const int row = ListView_InsertItem(list, &item);
    for (int columnIndex = 1; columnIndex < MONITOR_COLUMN_COUNT; columnIndex++) {
        ListView_SetItemText(list, row, columnIndex, entry.text[columnIndex].data());
    }
    return row;
}

/// Rebuilds monitor rows while preserving device selection, focus, sorting and initialized widths.
static void PopulateMonitorList(HWND window, SettingsWindowData& data) {
    window = SettingsContentWindow(window);
    HWND list = GetDlgItem(window, ID_MONITOR_LIST);
    const bool updating = data.updating;
    data.updating = true;
    WindowRedrawScope redraw(list);
    std::vector<std::wstring> selectedDevices;
    std::wstring focusedDevice;
    for (int row = 0; row < ListView_GetItemCount(list); ++row) {
        LVITEMW item{};
        item.mask = LVIF_PARAM | LVIF_STATE;
        item.stateMask = LVIS_SELECTED | LVIS_FOCUSED;
        item.iItem = row;
        if (ListView_GetItem(list, &item) && static_cast<std::size_t>(item.lParam) < data.monitors.size()) {
            const std::wstring& device = data.monitors[static_cast<std::size_t>(item.lParam)].device;
            if (item.state & LVIS_SELECTED) {
                selectedDevices.push_back(device);
            }
            if (item.state & LVIS_FOCUSED) {
                focusedDevice = device;
            }
        }
    }
    data.monitors = AvailableMonitors();
    UpdateMonitorListColumns(list, data.language);
    ListView_DeleteAllItems(list);
    const std::vector<MonitorDetails> monitorDetails = ReadMonitorDetails(data.monitors);
    data.monitorListEntries.resize(data.monitors.size());
    for (std::size_t index = 0; index < data.monitors.size(); ++index) {
        const DisplayMonitor& monitor = data.monitors[index];
        MonitorListEntry& entry = data.monitorListEntries[index];
        UpdateMonitorListEntry(entry, monitor, monitorDetails[index], data.language);
        const int row = InsertMonitorListEntry(list, index, entry);
        if (data.appMode) {
            ListView_SetCheckState(list, row, data.settings->animationMonitorDevice.empty()
                || MonitorDeviceSelected(data.settings->animationMonitorDevice, monitor.device));
        }
        const bool selected = !data.monitorListInitialized || std::find(selectedDevices.begin(),
            selectedDevices.end(), monitor.device) != selectedDevices.end();
        ListView_SetItemState(list, row, selected ? LVIS_SELECTED : 0, LVIS_SELECTED);
        if (monitor.device == focusedDevice || !data.monitorListInitialized && index == 0) {
            ListView_SetItemState(list, row, LVIS_FOCUSED, LVIS_FOCUSED);
        }
    }
    ApplyMonitorListSort(list, data);
    const int focusedRow = ListView_GetNextItem(list, -1, LVNI_FOCUSED);
    if (focusedRow >= 0) {
        ListView_EnsureVisible(list, focusedRow, FALSE);
    }
    InitializeMonitorColumnWidths(list, data);
    data.monitorListInitialized = true;
    data.updating = updating;
}

/// Returns the selected language; selector indices follow the language enum directly.
static AppLanguage LanguageFromCombo(HWND combo) {
    return static_cast<AppLanguage>(SendMessageW(combo, CB_GETCURSEL, 0, 0));
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

/// Stores checked display identities in source monitor order, independent of ListView sorting.
static void RememberCheckedMonitors(HWND window, SettingsWindowData& data) {
    window = SettingsContentWindow(window);
    HWND list = GetDlgItem(window, ID_MONITOR_LIST);
    const std::vector<std::size_t> selected = CheckedMonitorIndices(list, data);
    data.settings->animationMonitorDevice = selected.empty()
        ? NO_ANIMATION_MONITORS
        : JoinMonitorDevices(data.monitors, selected);
    data.settings->Save();
}

/// Calculates the shared board dimensions used to filter patterns for the selected displays.
static SIZE PatternGridDimensions(const SettingsWindowData& data) {
    std::vector<RECT> rectangles;
    for (const DisplayMonitor& monitor : data.monitors) {
        if (!data.appMode
                || data.settings->animationMonitorDevice.empty()
                || MonitorDeviceSelected(data.settings->animationMonitorDevice, monitor.device)) {
            rectangles.push_back(monitor.rect);
        }
    }
    const bool compact = data.appMode && rectangles.size() != data.monitors.size();
    const RECT bounds = MonitorLayoutBounds(BuildMonitorLayout(rectangles, compact));
    const unsigned width = static_cast<unsigned>(bounds.right - bounds.left);
    const unsigned height = static_cast<unsigned>(bounds.bottom - bounds.top);
    const unsigned size = data.settings->cellSize;
    return SIZE{
        static_cast<LONG>((width + size - 1) / size),
        static_cast<LONG>((height + size - 1) / size)
    };
}

/// Selects the saved pattern and enables the combo only after its current items have been populated.
static void UpdatePatternComboSelection(HWND combo, SettingsWindowData& data) {
    const unsigned selected = PatternCatalog::Find(data.settings->patternId);
    const std::vector<unsigned>::iterator item =
        std::find(data.patternItems.begin(), data.patternItems.end(), selected);
    const LRESULT selection = item == data.patternItems.end() ? 0 : item - data.patternItems.begin();
    if (static_cast<std::size_t>(selection) < data.patternItemsAdded
            && SendMessageW(combo, CB_GETCURSEL, 0, 0) != selection) {
        SendMessageW(combo, CB_SETCURSEL, static_cast<WPARAM>(selection), 0);
    }
    const bool complete = data.patternItemsAdded == data.patternItems.size();
    const bool idle = data.patternColumns == 0 || data.patternRows == 0;
    EnableSettingsControl(combo, complete && data.settings->patternsOnly && !idle, &data);
}

/// Adds a bounded batch of native combo items, allowing input and painting between timer messages.
static void PopulatePatternComboBatch(HWND window, SettingsWindowData& data) {
    if (app->closing.load(std::memory_order_relaxed)) {
        return;
    }
    HWND combo = GetDlgItem(SettingsContentWindow(window), ID_PATTERN);
    const std::span<const LifePattern> patterns = PatternCatalog::All();
    const std::size_t end = std::min(data.patternItems.size(),
        data.patternItemsAdded + PATTERN_ITEMS_PER_BATCH);
    const ULONGLONG started = GetTickCount64();
    WindowRedrawScope redraw(combo);
    while (data.patternItemsAdded < end) {
        const unsigned selection = data.patternItems[data.patternItemsAdded];
        const LRESULT item = SendMessageW(combo, CB_ADDSTRING, 0,
            reinterpret_cast<LPARAM>(patterns[selection - 1].caption.c_str()));
        if (item == CB_ERR || item == CB_ERRSPACE) {
            KillTimer(window, ID_PATTERN_ITEMS_TIMER);
            CompletePatternCatalogLoad(false, &data);
            return;
        }
        SendMessageW(combo, CB_SETITEMDATA, static_cast<WPARAM>(item), selection);
        ++data.patternItemsAdded;
        if (GetTickCount64() - started >= 4) {
            break;
        }
    }
    if (data.patternItemsAdded == data.patternItems.size()) {
        KillTimer(window, ID_PATTERN_ITEMS_TIMER);
        UpdatePatternComboSelection(combo, data);
    }
}

/// Filters the loaded catalog and schedules native list population in separate UI message batches.
static void UpdatePatternCombo(HWND window, SettingsWindowData& data) {
    HWND owner = GetAncestor(window, GA_ROOT);
    window = SettingsContentWindow(window);
    HWND combo = GetDlgItem(window, ID_PATTERN);
    if (!app->patternCatalogReady) {
        if (data.patternLanguage != data.language) {
            WindowRedrawScope redraw(combo);
            SendMessageW(combo, CB_RESETCONTENT, 0, 0);
            SendMessageW(combo, CB_ADDSTRING, 0,
                reinterpret_cast<LPARAM>(GetLocalizedText(data.language, TXT_PATTERN_MIX)));
            SendMessageW(combo, CB_SETCURSEL, 0, 0);
            data.patternLanguage = data.language;
        }
        EnableSettingsControl(combo, false, &data);
        return;
    }
    const std::span<const LifePattern> patterns = PatternCatalog::All();
    const SIZE grid = PatternGridDimensions(data);
    const unsigned columns = static_cast<unsigned>(grid.cx);
    const unsigned rows = static_cast<unsigned>(grid.cy);
    const bool idle = columns == 0 || rows == 0;
    ValidatePatternSelection(*data.settings, columns, rows);
    const unsigned selected = PatternCatalog::Find(data.settings->patternId);
    if (data.patternColumns != columns
            || data.patternRows != rows
            || data.patternCount != patterns.size()
            || idle && data.patternIdleId != data.settings->patternId) {
        KillTimer(owner, ID_PATTERN_ITEMS_TIMER);
        WindowRedrawScope redraw(combo);
        data.patternItems.clear();
        data.patternItems.reserve(patterns.size() + 1);
        data.patternItems.push_back(0);
        std::size_t bytes = 0;
        for (std::size_t index = 0; index < patterns.size(); ++index) {
            const LifePattern& pattern = patterns[index];
            const unsigned selection = static_cast<unsigned>(index + 1);
            const bool include = idle
                ? selection == selected
                : pattern.width <= columns && pattern.height <= rows;
            if (include) {
                data.patternItems.push_back(selection);
                bytes += (pattern.caption.size() + 1) * sizeof(wchar_t);
            }
        }
        const wchar_t* mixture = GetLocalizedText(data.language, TXT_PATTERN_MIX);
        bytes += (wcslen(mixture) + 1) * sizeof(wchar_t);
        SendMessageW(combo, CB_RESETCONTENT, 0, 0);
        SendMessageW(combo, CB_INITSTORAGE, data.patternItems.size(), static_cast<LPARAM>(bytes));
        SendMessageW(combo, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(mixture));
        SendMessageW(combo, CB_SETITEMDATA, 0, 0);
        SendMessageW(combo, CB_SETCURSEL, 0, 0);
        data.patternItemsAdded = 1;
        data.patternColumns = columns;
        data.patternRows = rows;
        data.patternLanguage = data.language;
        data.patternCount = patterns.size();
        data.patternIdleId = idle ? data.settings->patternId : std::wstring();
        if (data.patternItemsAdded < data.patternItems.size()) {
            if (!SetTimer(owner, ID_PATTERN_ITEMS_TIMER, USER_TIMER_MINIMUM, nullptr)) {
                CompletePatternCatalogLoad(false, &data);
                return;
            }
        }
    } else if (data.patternLanguage != data.language) {
        WindowRedrawScope redraw(combo);
        SendMessageW(combo, CB_DELETESTRING, 0, 0);
        const LRESULT item = SendMessageW(combo, CB_INSERTSTRING, 0,
            reinterpret_cast<LPARAM>(GetLocalizedText(data.language, TXT_PATTERN_MIX)));
        SendMessageW(combo, CB_SETITEMDATA, static_cast<WPARAM>(item), 0);
        data.patternLanguage = data.language;
    }
    UpdatePatternComboSelection(combo, data);
}

/// Returns the visible client height of the scrollable settings content.
static int SettingsViewportHeight(HWND window, const SettingsWindowData& data) {
    RECT client{};
    GetClientRect(data.contentWindow ? data.contentWindow : window, &client);
    return std::max(0L, client.bottom - client.top);
}

/// Sizes the settings panel above the fixed status bar without changing control geometry.
static void LayoutSettingsContent(HWND window, const SettingsWindowData& data) {
    if (!data.contentWindow) {
        return;
    }
    RECT client{};
    RECT status{};
    GetClientRect(window, &client);
    if (data.appMode) {
        SendMessageW(app->status, WM_SIZE, 0, 0);
        GetWindowRect(app->status, &status);
    }
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
            positions = DeferWindowPos(positions, child, nullptr, rect.left + deltaX,
                rect.top + deltaY, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
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
        ScrollBarData{
            SB_HORZ,
            data.contentWidth,
            static_cast<UINT>(std::max(0L, client.right - client.left))
        }, ScrollBarData{
            SB_VERT,
            data.contentHeight,
            static_cast<UINT>(SettingsViewportHeight(window, data))
        }
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

/// Fits the native DLU panel and status bar into the current monitor without stretching the resource
/// controls.
static void FitSettingsWindow(HWND window, SettingsWindowData& data) {
    RECT content{
        0,
        0,
        data.appMode ? APPLICATION_CONTENT_WIDTH_DLU : SCREEN_SAVER_CONTENT_WIDTH_DLU,
        data.appMode ? APPLICATION_CONTENT_HEIGHT_DLU : SCREEN_SAVER_CONTENT_HEIGHT_DLU
    };
    MapDialogRect(data.contentWindow, &content);
    data.contentWidth = content.right;
    data.contentHeight = content.bottom;
    RECT status{};
    if (data.appMode) {
        SendMessageW(app->status, WM_SIZE, 0, 0);
        GetWindowRect(app->status, &status);
    }
    RECT client{};
    RECT outer{};
    GetClientRect(window, &client);
    GetWindowRect(window, &outer);
    const int frameWidth = outer.right - outer.left - client.right;
    const int frameHeight = outer.bottom - outer.top - client.bottom;
    const int statusHeight = status.bottom - status.top;
    MONITORINFO monitor{ sizeof(monitor) };
    GetMonitorInfoW(MonitorFromWindow(window, MONITOR_DEFAULTTONEAREST), &monitor);
    const int workWidth = monitor.rcWork.right - monitor.rcWork.left;
    const int workHeight = monitor.rcWork.bottom - monitor.rcWork.top;
    const int desiredWidth = data.contentWidth + frameWidth;
    const int desiredHeight = data.contentHeight + statusHeight + frameHeight;
    const int verticalWidth = GetSystemMetrics(SM_CXVSCROLL);
    const int horizontalHeight = GetSystemMetrics(SM_CYHSCROLL);
    bool horizontal = desiredWidth > workWidth;
    bool vertical = desiredHeight > workHeight;
    int width = 0;
    int height = 0;
    for (int pass = 0; pass < 2; ++pass) {
        width = std::min(workWidth, desiredWidth + (vertical ? verticalWidth : 0));
        height = std::min(workHeight, desiredHeight + (horizontal ? horizontalHeight : 0));
        horizontal = width - (vertical ? verticalWidth : 0) < desiredWidth;
        vertical = height - (horizontal ? horizontalHeight : 0) < desiredHeight;
    }
    width = std::min(workWidth, desiredWidth + (vertical ? verticalWidth : 0));
    height = std::min(workHeight, desiredHeight + (horizontal ? horizontalHeight : 0));
    data.scrollStyle = (horizontal ? WS_HSCROLL : 0) | (vertical ? WS_VSCROLL : 0);
    const LONG_PTR previousStyle = GetWindowLongPtrW(data.contentWindow, GWL_STYLE);
    const LONG_PTR style = previousStyle & ~(WS_HSCROLL | WS_VSCROLL) | data.scrollStyle;
    if (style != previousStyle) {
        SetWindowLongPtrW(data.contentWindow, GWL_STYLE, style);
        SetWindowPos(data.contentWindow, nullptr, 0, 0, 0, 0,
            SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
    }
    const int x = std::clamp(static_cast<int>(outer.left), static_cast<int>(monitor.rcWork.left),
        static_cast<int>(monitor.rcWork.right) - width);
    const int y = std::clamp(static_cast<int>(outer.top), static_cast<int>(monitor.rcWork.top),
        static_cast<int>(monitor.rcWork.bottom) - height);
    SetWindowPos(window, nullptr, x, y, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
    LayoutSettingsContent(window, data);
    UpdateSettingsScrollBars(window, data, false);
    UpdateSettingsTextControlLayout(window);
}

/// Applies one horizontal or vertical scroll-bar request.
static bool ScrollSettingsWindow(HWND window, int bar, int request) {
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
static bool ScrollSettingsWheel(HWND window, WPARAM wParam) {
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
        ScrollSettingsWindow(window, bar, request);
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

/// Refreshes pattern dropdown metrics and removes color-preview associations on destruction.
static LRESULT CALLBACK SettingsControlSubclassProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam,
        UINT_PTR subclassId, DWORD_PTR) {
    if ((message == WM_SETFONT || message == WM_THEMECHANGED || message == WM_DPICHANGED_AFTERPARENT)
            && GetDlgCtrlID(window) == ID_PATTERN) {
        const LRESULT result = DefSubclassProc(window, message, wParam, lParam);
        PostMessageW(GetAncestor(window, GA_ROOT), UPDATE_SETTINGS_CONTROL_METRICS, 0, 0);
        return result;
    }
    if (message == WM_NCDESTROY) {
        RemovePropW(window, SETTINGS_COLOR_PREVIEW_PROPERTY);
        RemovePropW(window, SETTINGS_COLOR_BUTTON_PROPERTY);
        RemoveWindowSubclass(window, SettingsControlSubclassProc, subclassId);
    }
    return DefSubclassProc(window, message, wParam, lParam);
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

/// Opens the Windows screen-saver control panel without changing its current settings.
static bool OpenSystemScreenSaverSettings(HWND owner) {
    BOOL wow64 = FALSE;
    if (!IsWow64Process(GetCurrentProcess(), &wow64)) {
        return false;
    }
    wchar_t directory[MAX_PATH]{};
    const UINT length = GetWindowsDirectoryW(directory, MAX_PATH);
    if (length == 0 || length >= MAX_PATH) {
        return false;
    }
    const std::wstring executable = std::wstring(directory, length)
        + (wow64 ? L"\\Sysnative\\control.exe" : L"\\System32\\control.exe");
    const HINSTANCE result = ShellExecuteW(owner, L"open", executable.c_str(),
        L"desk.cpl,screensaver,@screensaver", nullptr, SW_SHOWNORMAL);
    return reinterpret_cast<INT_PTR>(result) > 32;
}

/// Reuses the first control's RC row height as one rounded pixel distance between every text baseline.
static void AlignSettingsControlRows(HWND window, const int* ids, std::size_t count) {
    HWND reference = GetDlgItem(window, ids[0]);
    RECT bounds{};
    if (!GetWindowRect(reference, &bounds)) {
        return;
    }
    const LONG rowDistance = bounds.bottom - bounds.top;
    for (std::size_t index = 1; index < count; ++index) {
        HWND control = GetDlgItem(window, ids[index]);
        AlignSettingsControl(control, reference, rowDistance);
        reference = control;
    }
}

/// Aligns settings rows after the shared font, theme, DPI or native control metrics change.
static void UpdateSettingsControlMetrics(HWND window) {
    window = SettingsContentWindow(window);
    UpdateComboBoxDropDownSize(GetDlgItem(window, ID_LANGUAGE));
    AlignSettingsControl(GetDlgItem(window, ID_LANGUAGE_LABEL), GetDlgItem(window, ID_LANGUAGE));
    const int sceneCheckboxes[]{
        ID_SHOW_GRID,
        ID_RANDOM_ALIVE_COLOR,
        ID_RANDOM_BACKGROUND_COLOR,
        ID_RANDOM_GRID_COLOR,
        ID_AUTO_RESET,
        ID_PATTERNS_ONLY
    };
    AlignSettingsControlRows(window, sceneCheckboxes, std::size(sceneCheckboxes));
    AlignSettingsControl(GetDlgItem(window, ID_PATTERN), GetDlgItem(window, ID_PATTERNS_ONLY));
    HWND preventScreenSaver = GetDlgItem(window, ID_PREVENT_SCREEN_SAVER);
    if (preventScreenSaver) {
        AlignSettingsControl(preventScreenSaver, GetDlgItem(window, ID_LANGUAGE));
        AlignSettingsControl(GetDlgItem(window, ID_SYSTEM_SCREEN_SAVER), GetDlgItem(window, ID_LANGUAGE));
    }
}

/// Keeps the pattern dropdown as wide as its combo without measuring the catalog captions.
static void UpdatePatternControlMetrics(HWND window) {
    HWND combo = GetDlgItem(SettingsContentWindow(window), ID_PATTERN);
    SendMessageW(combo, CB_SETMINVISIBLE, COMBO_BOX_MAX_VISIBLE_ITEMS, 0);
    COMBOBOXINFO information{};
    information.cbSize = sizeof(information);
    if (GetComboBoxInfo(combo, &information) && information.hwndList != nullptr) {
        SetWindowSubclass(information.hwndList, ComboBoxDropDownSubclassProc, COMBO_BOX_DROPDOWN_SUBCLASS_ID,
            reinterpret_cast<DWORD_PTR>(combo));
    }
    RECT bounds{};
    if (GetWindowRect(combo, &bounds)) {
        SendMessageW(combo, CB_SETDROPPEDWIDTH, bounds.right - bounds.left, 0);
    }
}

/// Selects the focused native pushbutton as the Enter default, otherwise restoring the form's original
/// default.
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
static LRESULT CALLBACK SettingsTabStopSubclass(HWND control, UINT msg, WPARAM wParam, LPARAM lParam,
        UINT_PTR subclassId, DWORD_PTR referenceData) {
    UNREFERENCED_PARAMETER(referenceData);
    HWND parent = GetParent(control);
    SettingsWindowData* data =
        reinterpret_cast<SettingsWindowData*>(GetWindowLongPtrW(parent, GWLP_USERDATA));
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
                || (GetWindowLongPtrW(control, GWL_EXSTYLE) & (WS_EX_STATICEDGE | WS_EX_CLIENTEDGE)) != 0) {
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
static bool CompareSettingsControls(const PositionedControl& left, const PositionedControl& rightControl) {
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

/// Restores native clipping styles and Z-order without changing resource control geometry.
static void UpdateSettingsTextControlLayout(HWND parent) {
    parent = SettingsContentWindow(parent);
    RECT client{};
    if (!parent || !GetClientRect(parent, &client)) {
        return;
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
        }
        controls.push_back(PositionedControl{ control, rect });
    }
    std::stable_sort(controls.begin(), controls.end(), CompareSettingsControls);
    HWND previous = nullptr;
    for (const PositionedControl& control : controls) {
        SetWindowPos(control.window, previous, 0, 0, 0, 0,
            SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | SWP_NOCOPYBITS);
        previous = control.window;
    }
}

/// Returns the tab sequence for scene controls and the actions available in EXE or SCR mode.
static std::vector<int> SettingsTabOrder(const SettingsWindowData& data) {
    std::vector<int> order{ ID_LANGUAGE };
    if (data.appMode) {
        order.push_back(ID_PREVENT_SCREEN_SAVER);
        order.push_back(ID_SYSTEM_SCREEN_SAVER);
    }
    for (const AnimationSliderControl& control : ANIMATION_SLIDERS) {
        order.push_back(control.id);
    }
    const int sceneControls[]{
        ID_ALIVE_COLOR,
        ID_BACKGROUND_COLOR,
        ID_GRID_COLOR,
        ID_RESET_SETTINGS,
        ID_SHOW_GRID,
        ID_RANDOM_ALIVE_COLOR,
        ID_RANDOM_BACKGROUND_COLOR,
        ID_RANDOM_GRID_COLOR,
        ID_AUTO_RESET,
        ID_PATTERNS_ONLY,
        ID_PATTERN,
        ID_RESTART
    };
    for (int id : sceneControls) {
        order.push_back(id);
    }
    order.push_back(data.appMode ? ID_PAUSE : ID_PREVIEW_TOGGLE);
    order.push_back(ID_HELP);
    order.push_back(ID_ABOUT);
    order.push_back(ID_MONITOR_LIST);
    if (data.appMode) {
        order.push_back(ID_RECORD_SETTINGS);
        order.push_back(ID_RECORD_TOGGLE);
        order.push_back(ID_SNAPSHOT);
        order.push_back(ID_INSTALL);
    } else {
        order.push_back(ID_PAUSE);
        order.push_back(IDOK);
        order.push_back(ID_CANCEL);
    }
    return order;
}

/// Returns the next available control in the declared settings tab sequence, retaining a disabled source as
/// its anchor.
static HWND FindSettingsTabTarget(HWND parent, const SettingsWindowData& data, HWND focused, bool backwards) {
    parent = SettingsContentWindow(parent);
    std::vector<HWND> controls;
    for (const int id : SettingsTabOrder(data)) {
        HWND control = GetDlgItem(parent, id);
        const bool radioGroup = id == ID_ANIMATION_PRIMARY;
        if (radioGroup) {
            for (const int radioId : ANIMATION_RADIO_IDS) {
                HWND radio = GetDlgItem(parent, radioId);
                if (focused == radio || IsChild(radio, focused)) {
                    control = radio;
                    break;
                }
                if (SendDlgItemMessageW(parent, radioId, BM_GETCHECK, 0, 0) == BST_CHECKED) {
                    control = radio;
                }
            }
        }
        if (control) {
            const bool anchor = focused == control || IsChild(control, focused);
            if (anchor
                || IsWindowVisible(control)
                    && IsWindowEnabled(control)
                    && (radioGroup || (GetWindowLongPtrW(control, GWL_STYLE) & WS_TABSTOP) != 0)) {
                controls.push_back(control);
            }
        }
    }
    if (controls.empty()) {
        return nullptr;
    }
    std::vector<HWND>::iterator current = controls.begin();
    for (; current != controls.end(); current++) {
        if (focused == *current || IsChild(*current, focused)) {
            break;
        }
    }
    std::size_t next = 0;
    if (current == controls.end()) {
        return nullptr;
    } else {
        const std::size_t index = static_cast<std::size_t>(current - controls.begin());
        next = backwards ? (index + controls.size() - 1) % controls.size() : (index + 1) % controls.size();
    }
    HWND target = controls[next];
    return IsWindowVisible(target) && IsWindowEnabled(target) ? target : nullptr;
}

/// Moves settings page controls through their declared tab order and exposes keyboard focus cues.
/// Leaves ordinary pushbutton transitions to native dialog processing.
static bool MoveSettingsTabFocus(HWND parent, const SettingsWindowData& data, bool backwards) {
    parent = SettingsContentWindow(parent);
    HWND focused = GetFocus();
    HWND target = FindSettingsTabTarget(parent, data, focused, backwards);
    if (!target) {
        return false;
    }
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

/// Tests whether a message belongs to a window or one of its descendants.
static bool MessageTargetsWindow(const MSG& msg, HWND window) {
    return window && (msg.hwnd == window || IsChild(window, msg.hwnd));
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

/// Enables recording, snapshots, pause and scene restart according to available outputs.
static void UpdateSettingsActionButtons(HWND window) {
    UpdateScreenSaverInhibition();
    window = SettingsContentWindow(window);
    const bool animationReady = HasReadyPrimarySurface();
    EnableSettingsControl(GetDlgItem(window, ID_RECORD_TOGGLE), animationReady);
    EnableSettingsControl(GetDlgItem(window, ID_SNAPSHOT), animationReady);
    EnableSettingsControl(GetDlgItem(window, ID_PAUSE), HasReadyAnimationSurface());
    EnableSettingsControl(GetDlgItem(window, ID_RESTART), !app->surfaces.empty());
}

/// Updates the pause caption while retaining its assigned mnemonic and avoiding unchanged text writes.
static void UpdatePauseButton() {
    HWND button = GetDlgItem(SettingsContentWindow(app->controlWindow), ID_PAUSE);
    const TextId text = app->paused.load(std::memory_order_relaxed) ? TXT_RESUME : TXT_PAUSE;
    SetWindowTextIfChanged(button, PreserveControlMnemonic(button, GetLocalizedText(ActiveLanguage(), text)));
}

static void UpdateSettingsSlider(HWND window, const SettingsWindowData& data, int sliderId) {
    window = SettingsContentWindow(window);
    const TextId texts[]{ TXT_CELL_SIZE, TXT_GENERATION_RATE, TXT_INITIAL_DENSITY };
    const unsigned displayedCellSize =
        data.settings->cellSize - static_cast<unsigned>(data.settings->showGrid);
    const unsigned values[]{
        displayedCellSize,
        data.settings->generationsPerSecond,
        data.settings->densityPercent
    };
    for (std::size_t index = 0; index < std::size(ANIMATION_SLIDERS); ++index) {
        const AnimationSliderControl& control = ANIMATION_SLIDERS[index];
        if (control.id != sliderId) {
            continue;
        }
        HWND slider = GetDlgItem(window, control.id);
        if (SendMessageW(slider, TBM_GETPOS, 0, 0) != static_cast<LRESULT>(values[index])) {
            SendMessageW(slider, TBM_SETPOS, TRUE, values[index]);
        }
        wchar_t caption[160]{};
        swprintf_s(caption, GetLocalizedText(data.language, texts[index]), values[index]);
        HWND label = GetDlgItem(window, control.labelId);
        SetWindowTextIfChanged(label, PreserveControlMnemonic(label, caption));
        return;
    }
}

static void UpdateSettingsPatterns(HWND window, SettingsWindowData& data) {
    UpdatePatternCombo(window, data);
    UpdatePatternControlMetrics(window);
    window = SettingsContentWindow(window);
    EnableSettingsControl(GetDlgItem(window, ID_INITIAL_DENSITY), !data.settings->patternsOnly, &data);
    EnableSettingsControl(GetDlgItem(window, ID_INITIAL_DENSITY_LABEL), !data.settings->patternsOnly, &data);
}

static void UpdateSettingsOutputControls(HWND window, SettingsWindowData& data) {
    UpdateSettingsSlider(window, data, ID_CELL_SIZE);
    UpdateSettingsPatterns(window, data);
    UpdateSettingsActionButtons(window);
    HWND preview = GetDlgItem(SettingsContentWindow(window), ID_PREVIEW_TOGGLE);
    SetWindowTextIfChanged(preview, PreserveControlMnemonic(preview, GetLocalizedText(data.language,
        app->previewActive ? TXT_DISABLE_PREVIEW : TXT_ENABLE_PREVIEW)));
    RestoreCurrentStatus();
}

/// Applies localized captions only to this project's animation controls.
static void ApplyAnimationCaptions(HWND window, const SettingsWindowData& data) {
    const int labels[]{ ID_CELL_SIZE_LABEL, ID_GENERATION_RATE_LABEL, ID_INITIAL_DENSITY_LABEL };
    const TextId texts[]{ TXT_CELL_SIZE, TXT_GENERATION_RATE, TXT_INITIAL_DENSITY };
    const unsigned cellSize = data.settings->cellSize;
    const unsigned displayedCellSize = cellSize - static_cast<unsigned>(data.settings->showGrid);
    const unsigned values[]{
        displayedCellSize,
        data.settings->generationsPerSecond,
        data.settings->densityPercent
    };
    wchar_t caption[160]{};
    for (unsigned index = 0; index < 3; ++index) {
        swprintf_s(caption, GetLocalizedText(data.language, texts[index]), values[index]);
        SetDlgItemTextW(window, labels[index], caption);
    }
    SetDlgItemTextW(window, ID_ALIVE_COLOR, GetLocalizedText(data.language, TXT_ALIVE_COLOR));
    SetDlgItemTextW(window, ID_BACKGROUND_COLOR, GetLocalizedText(data.language, TXT_BACKGROUND_COLOR));
    SetDlgItemTextW(window, ID_GRID_COLOR, GetLocalizedText(data.language, TXT_GRID_COLOR));
    SetDlgItemTextW(window, ID_SHOW_GRID, GetLocalizedText(data.language, TXT_SHOW_GRID));
    SetDlgItemTextW(window, ID_RANDOM_ALIVE_COLOR, GetLocalizedText(data.language, TXT_RANDOM_ALIVE_COLOR));
    SetDlgItemTextW(window, ID_RANDOM_BACKGROUND_COLOR,
        GetLocalizedText(data.language, TXT_RANDOM_BACKGROUND_COLOR));
    SetDlgItemTextW(window, ID_RANDOM_GRID_COLOR, GetLocalizedText(data.language, TXT_RANDOM_GRID_COLOR));
    SetDlgItemTextW(window, ID_AUTO_RESET, GetLocalizedText(data.language, TXT_AUTO_RESET));
    SetDlgItemTextW(window, ID_PATTERNS_ONLY, GetLocalizedText(data.language, TXT_PATTERNS_ONLY));
    SetDlgItemTextW(window, ID_RESTART, GetLocalizedText(data.language, TXT_RESTART));
    SetDlgItemTextW(window, ID_RESET_SETTINGS, GetLocalizedText(data.language, TXT_RESET_SETTINGS));
    SetDlgItemTextW(window, ID_TOPOLOGY_NOTE, GetLocalizedText(data.language, TXT_TOPOLOGY_NOTE));
}

/// Applies one language atomically to all settings and information windows.
static void ApplyLocalizedCaptions(HWND window, SettingsWindowData& data) {
    const AppLanguage stringsLanguage = data.language;
    data.updating = true;
    window = SettingsContentWindow(window);
    SetWindowTextW(GetAncestor(window, GA_ROOT),
        GetLocalizedText(stringsLanguage, data.appMode ? TXT_CONTROL_TITLE : TXT_SETTINGS_TITLE));
    SetDlgItemTextW(window, ID_LANGUAGE_LABEL, GetLocalizedText(stringsLanguage, TXT_LANGUAGE));
    if (data.appMode) {
        SetDlgItemTextW(window, ID_SYSTEM_SCREEN_SAVER,
            GetLocalizedText(data.language, TXT_SYSTEM_SCREEN_SAVER));
        SetDlgItemTextW(window, ID_PREVENT_SCREEN_SAVER, GetLocalizedText(data.language,
            TXT_PREVENT_SCREEN_SAVER));
        if (data.settings) {
            SendDlgItemMessageW(window, ID_PREVENT_SCREEN_SAVER, BM_SETCHECK,
                data.settings->preventScreenSaver ? BST_CHECKED : BST_UNCHECKED, 0);
        }
    }
    ApplyAnimationCaptions(window, data);
    UpdatePatternCombo(window, data);
    UpdatePatternControlMetrics(window);
    SetDlgItemTextW(window, ID_OK, GetLocalizedText(stringsLanguage, TXT_OK));
    SetDlgItemTextW(window, ID_CANCEL, GetLocalizedText(stringsLanguage, TXT_CANCEL));
    SetDlgItemTextW(window, ID_PREVIEW_TOGGLE, app->previewActive
        ? GetLocalizedText(data.language, TXT_DISABLE_PREVIEW)
        : GetLocalizedText(data.language, TXT_ENABLE_PREVIEW));
    SetDlgItemTextW(window, ID_RECORD_TOGGLE, PrimaryIsRecording()
        ? GetLocalizedText(stringsLanguage, TXT_STOP_RECORDING)
        : GetLocalizedText(stringsLanguage, TXT_START_RECORDING));
    SetDlgItemTextW(window, ID_PAUSE, app && app->paused
        ? GetLocalizedText(stringsLanguage, TXT_RESUME)
        : GetLocalizedText(stringsLanguage, TXT_PAUSE));
    SetDlgItemTextW(window, ID_INSTALL, IsScreenSaverInstalled()
        ? GetLocalizedText(data.language, TXT_UNINSTALL_SCREEN_SAVER)
        : GetLocalizedText(stringsLanguage, TXT_INSTALL_SCREEN_SAVER));
    SetDlgItemTextW(window, ID_RECORD_SETTINGS, GetLocalizedText(data.language,
        TXT_RECORDING_SETTINGS_TITLE));
    SetDlgItemTextW(window, ID_SNAPSHOT, GetLocalizedText(data.language, TXT_SNAPSHOT));
    SetDlgItemTextW(window, ID_HELP, GetLocalizedText(data.language, TXT_HELP));
    SetDlgItemTextW(window, ID_ABOUT, GetLocalizedText(data.language, TXT_ABOUT));
    if (data.appMode) {
        RestoreCurrentStatus();
    }
    SetDlgItemTextW(window, ID_MONITOR_GROUP, GetLocalizedText(stringsLanguage, TXT_ANIMATION_MONITOR));
    PopulateMonitorList(window, data);
    AssignSettingsMnemonics(window);
    UpdateSettingsTextControlLayout(window);
    RefreshInformationWindows(data.language, data.appMode);
    data.updating = false;
    UpdateSettingsActionButtons(window);
}

/// Opens the native color dialog and changes the supplied color only after confirmation.
static bool ChooseSettingsColor(HWND window, COLORREF& color) {
    CHOOSECOLORW choice{};
    choice.lStructSize = sizeof(choice);
    choice.hwndOwner = window;
    choice.rgbResult = color;
    choice.lpCustColors = customColors;
    choice.Flags = CC_FULLOPEN | CC_RGBINIT;
    if (!ChooseColorW(&choice)) {
        return false;
    }
    color = choice.rgbResult;
    return true;
}

/// Validates the pattern, publishes scene options and saves EXE choices.
static void ApplySettingsChanges(SettingsWindowData& data, bool reset) {
    const SIZE grid = PatternGridDimensions(data);
    ValidatePatternSelection(*data.settings, static_cast<unsigned>(grid.cx), static_cast<unsigned>(grid.cy));
    SynchronizeRuntimeSettings();
    if (reset) {
        app->resetRequested.store(true, std::memory_order_relaxed);
    }
    if (!app->surfaces.empty() && !app->surfaces.front()->renderThread.joinable()
            && !data.settings->patternsOnly && !StartRenderSurfaces()) {
        PostMessageW(app->controlWindow, RENDERER_FAILED, 0, 0);
    }
    if (data.appMode) {
        data.settings->Save();
    }
    UpdateScreenSaverInhibition();
}


/// Restores slider values and colors with a displayed cell size of 8 px in either grid mode.
static void ResetSettings(HWND window, SettingsWindowData& data) {
    const unsigned previousSize = data.settings->cellSize;
    const unsigned previousDensity = data.settings->densityPercent;
    data.settings->ResetValues();
    const bool reset = previousSize != data.settings->cellSize
        || previousDensity != data.settings->densityPercent && !data.settings->patternsOnly;
    ApplySettingsChanges(data, reset);
    for (const AnimationSliderControl& control : ANIMATION_SLIDERS) {
        UpdateSettingsSlider(window, data, control.id);
    }
    if (previousSize != data.settings->cellSize) {
        UpdateSettingsPatterns(window, data);
    }
    window = SettingsContentWindow(window);
    SetButtonColor(GetDlgItem(window, ID_ALIVE_COLOR), data.settings->aliveColor);
    SetButtonColor(GetDlgItem(window, ID_BACKGROUND_COLOR), data.settings->backgroundColor);
    SetButtonColor(GetDlgItem(window, ID_GRID_COLOR), data.settings->gridColor);
}

/// Adds pattern-metric and color-preview cleanup handling to one native control.
static BOOL CALLBACK InstallSettingsControlSubclass(HWND child, LPARAM) {
    SetWindowSubclass(child, SettingsControlSubclassProc, 0xF507, 0);
    return TRUE;
}

/// Forwards a panel notification and preserves its dialog message result.
static INT_PTR ForwardSettingsPanelNotification(HWND window, UINT msg, WPARAM wParam, LPARAM lParam) {
    const LRESULT result = SendMessageW(GetParent(window), msg, wParam, lParam);
    SetWindowLongPtrW(window, DWLP_MSGRESULT, result);
    return TRUE;
}

/// Forwards panel input to settings and supplies the brushes for native color previews.
static INT_PTR CALLBACK SettingsPanelProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam) {
    SettingsWindowData* data =
        reinterpret_cast<SettingsWindowData*>(GetWindowLongPtrW(window, GWLP_USERDATA));
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
        case WM_CTLCOLORSTATIC:
            return GetSettingsColorPreviewBrush(reinterpret_cast<HWND>(lParam),
                reinterpret_cast<HDC>(wParam));
        case WM_SIZE:
            if (data) {
                UpdateSettingsScrollBars(window, *data, false);
            }
            return TRUE;
    }
    return FALSE;
}

/// Initializes the resource monitor list with native columns and the selected invocation mode.
static void InitializeSettingsMonitorList(HWND monitorList, const SettingsWindowData& data) {
    ListView_SetExtendedListViewStyle(monitorList, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES
        | LVS_EX_DOUBLEBUFFER | (data.appMode ? LVS_EX_CHECKBOXES : 0U));
    LVCOLUMNW column{};
    column.mask = LVCF_TEXT | LVCF_SUBITEM;
    column.pszText = const_cast<LPWSTR>(L"");
    for (int index = 0; index < MONITOR_COLUMN_COUNT; index++) {
        column.iSubItem = index;
        ListView_InsertColumn(monitorList, index, &column);
    }
    SetWindowSubclass(monitorList, MonitorListSubclassProc, ID_MONITOR_LIST, 0);
}

/// Adds supported language names in their defined display order.
static void PopulateLanguageCombo(HWND combo) {
    for (int language = 0; language < LANG_COUNT; language++) {
        const wchar_t* name = GetLocalizedText(static_cast<AppLanguage>(language), TXT_LANGUAGE_NAME);
        SendMessageW(combo, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(name));
    }
}

/// Creates the native settings panel and initializes scene controls, monitor rows and navigation.
static LRESULT CreateSettingsControls(HWND window, SettingsWindowData& data) {
    app->controlWindow = window;
    if (data.appMode) {
        if (!SetPropW(window, INSTANCE_WINDOW_PROPERTY, window)) {
            return -1;
        }
        app->status = GetDlgItem(window, ID_STATUS);
        if (!app->status) {
            return -1;
        }
    }
    const int panelId = data.appMode ? IDD_SETTINGS_PANEL : IDD_SCREEN_SAVER_SETTINGS_PANEL;
    DLGTEMPLATE* definition = LoadSystemDialogTemplate(app->instance, panelId, window);
    if (definition == nullptr) {
        return -1;
    }
    data.contentWindow = CreateDialogIndirectParamW(app->instance, definition, window,
        SettingsPanelProc, reinterpret_cast<LPARAM>(&data));
    HeapFree(GetProcessHeap(), 0, definition);
    if (!data.contentWindow) {
        return -1;
    }
    if (data.appMode) {
        SendMessageW(app->status, WM_SETFONT, SendMessageW(window, WM_GETFONT, 0, 0), FALSE);
    }
    window = data.contentWindow;
    PopulateLanguageCombo(GetDlgItem(window, ID_LANGUAGE));
    SendDlgItemMessageW(window, ID_LANGUAGE, CB_SETCURSEL, data.language, 0);
    SendDlgItemMessageW(window, ID_CELL_SIZE, TBM_SETRANGE, FALSE, MAKELPARAM(1, 64));
    SendDlgItemMessageW(window, ID_GENERATION_RATE, TBM_SETRANGE, FALSE, MAKELPARAM(0, 240));
    SendDlgItemMessageW(window, ID_INITIAL_DENSITY, TBM_SETRANGE, FALSE, MAKELPARAM(0, 100));
    InitializeSettingsMonitorList(GetDlgItem(window, ID_MONITOR_LIST), data);
    data.systemDialogFont = reinterpret_cast<HFONT>(SendMessageW(window, WM_GETFONT, 0, 0));
    EnumChildWindows(window, InstallSettingsControlSubclass, 0);
    InstallSettingsTabNavigation(window);
    if (!AddSettingsColorPreview(GetDlgItem(window, ID_ALIVE_COLOR), GetDlgItem(window, ID_ALIVE_SWATCH))
            || !AddSettingsColorPreview(GetDlgItem(window, ID_BACKGROUND_COLOR),
                GetDlgItem(window, ID_BACKGROUND_SWATCH))
            || !AddSettingsColorPreview(GetDlgItem(window, ID_GRID_COLOR),
                GetDlgItem(window, ID_GRID_SWATCH))) {
        return -1;
    }
    const unsigned displayedCellSize =
        data.settings->cellSize - static_cast<unsigned>(data.settings->showGrid);
    SendDlgItemMessageW(window, ID_CELL_SIZE, TBM_SETPOS, TRUE, displayedCellSize);
    SendDlgItemMessageW(window, ID_GENERATION_RATE, TBM_SETPOS, TRUE, data.settings->generationsPerSecond);
    SendDlgItemMessageW(window, ID_INITIAL_DENSITY, TBM_SETPOS, TRUE, data.settings->densityPercent);
    CheckDlgButton(window, ID_SHOW_GRID, data.settings->showGrid ? BST_CHECKED : BST_UNCHECKED);
    CheckDlgButton(window, ID_RANDOM_ALIVE_COLOR,
        data.settings->randomAliveColor ? BST_CHECKED : BST_UNCHECKED);
    CheckDlgButton(window, ID_RANDOM_BACKGROUND_COLOR,
        data.settings->randomBackgroundColor ? BST_CHECKED : BST_UNCHECKED);
    CheckDlgButton(window, ID_RANDOM_GRID_COLOR,
        data.settings->randomGridColor ? BST_CHECKED : BST_UNCHECKED);
    CheckDlgButton(window, ID_AUTO_RESET, data.settings->autoReset ? BST_CHECKED : BST_UNCHECKED);
    CheckDlgButton(window, ID_PATTERNS_ONLY, data.settings->patternsOnly ? BST_CHECKED : BST_UNCHECKED);
    EnableWindow(GetDlgItem(window, ID_INITIAL_DENSITY), !data.settings->patternsOnly);
    EnableWindow(GetDlgItem(window, ID_INITIAL_DENSITY_LABEL), !data.settings->patternsOnly);
    SetButtonColor(GetDlgItem(window, ID_ALIVE_COLOR), data.settings->aliveColor);
    SetButtonColor(GetDlgItem(window, ID_BACKGROUND_COLOR), data.settings->backgroundColor);
    SetButtonColor(GetDlgItem(window, ID_GRID_COLOR), data.settings->gridColor);
    ShowWindow(GetDlgItem(window, IDOK), data.appMode ? SW_HIDE : SW_SHOWNA);
    ShowWindow(GetDlgItem(window, ID_PREVIEW_TOGGLE), data.appMode ? SW_HIDE : SW_SHOWNA);
    ShowWindow(GetDlgItem(window, ID_RECORD_SETTINGS), data.appMode ? SW_SHOWNA : SW_HIDE);
    ShowWindow(GetDlgItem(window, ID_RECORD_TOGGLE), data.appMode ? SW_SHOWNA : SW_HIDE);
    if (data.appMode) {
        SetTimer(GetAncestor(window, GA_ROOT), ID_SCREEN_SAVER_CHECK_TIMER,
            SCREEN_SAVER_CHECK_INTERVAL, nullptr);
    }
    ApplyLocalizedCaptions(window, data);
    UpdateSettingsControlMetrics(window);
    return 0;
}

/// Attaches position-only persistence to the EXE or SCR settings window.
static bool AttachSettingsWindowState(HWND window, bool applicationMode) {
    settingsWindowState.SetDetectionOptions(WindowDetectionOptions::NoDetection);
    settingsWindowState.SetDisableSaveSize(true);
    settingsWindowState.SetDisableSaveWindowState(true);
    settingsWindowState.SetUseWindowsDefaultSize(false);
    return settingsWindowState.Attach(window,
        applicationMode ? "ApplicationSettings" : "ScreenSaverSettings");
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

/// Rejects only attempts to uncheck the recording monitor, preserving all other ListView interaction.
static bool ShouldPreventMonitorUncheck(const NMLISTVIEW& change, const SettingsWindowData& data) {
    return !data.updating
        && data.appMode
        && (change.uChanged & LVIF_STATE) != 0
        && ((change.uOldState ^ change.uNewState) & LVIS_STATEIMAGEMASK) != 0
        && (change.uNewState & LVIS_STATEIMAGEMASK) == INDEXTOSTATEIMAGEMASK(1)
        && IsRecordingMonitorRow(change.hdr.hwndFrom, data, change.iItem);
}

/// Handles monitor sorting, output checkboxes and double-click selection changes.
static bool HandleMonitorNotification(HWND window, SettingsWindowData& data, LPARAM lParam) {
    const NMHDR* notification = reinterpret_cast<const NMHDR*>(lParam);
    if (notification->idFrom != ID_MONITOR_LIST || data.updating) {
        return false;
    }
    HWND list = notification->hwndFrom;
    if (notification->code == LVN_COLUMNCLICK) {
        const NMLISTVIEW* change = reinterpret_cast<const NMLISTVIEW*>(lParam);
        SortMonitorListByColumn(list, data, change->iSubItem);
        return true;
    }
    if (!data.appMode) {
        return false;
    }
    if (notification->code == LVN_ITEMCHANGED) {
        const NMLISTVIEW* change = reinterpret_cast<const NMLISTVIEW*>(lParam);
        if (ShouldPreventMonitorUncheck(*change, data)) {
            RestoreRecordingMonitorCheckState(list, data);
        }
        const bool stateImageChanged = data.appMode
            && !data.updating
            && (change->uChanged & LVIF_STATE) != 0
            && ((change->uOldState ^ change->uNewState) & LVIS_STATEIMAGEMASK) != 0;
        if (stateImageChanged) {
            RememberCheckedMonitors(window, data);
            if (!data.outputsUpdatePending) {
                data.outputsUpdatePending = PostMessageW(window, UPDATE_OUTPUTS, 0, 0) != FALSE;
            }
        }
        return true;
    }
    if (notification->code == NM_DBLCLK) {
        const NMITEMACTIVATE* click = reinterpret_cast<const NMITEMACTIVATE*>(lParam);
        if (click->iItem >= 0) {
            const bool checked = ListView_GetCheckState(list, click->iItem) != FALSE;
            if (!checked || !IsRecordingMonitorRow(list, data, click->iItem)) {
                ListView_SetCheckState(list, click->iItem, !checked);
            }
        }
        return true;
    }
    return false;
}

/// Handles settings actions, system changes, scrolling, installation progress and window shutdown.
static LRESULT CALLBACK SettingsProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam) {
    SettingsWindowData* data =
        reinterpret_cast<SettingsWindowData*>(GetWindowLongPtrW(window, GWLP_USERDATA));
    const HWND controls = SettingsContentWindow(window);
    switch (msg) {
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
            UpdatePauseButton();
            UpdateSettingsActionButtons(window);
            RestoreCurrentStatus();
            return 0;
        case PATTERN_CATALOG_LOADED:
            CompletePatternCatalogLoad(wParam != 0, data);
            return 0;
        case UPDATE_SETTINGS_CONTROL_METRICS:
            if (data) {
                app->programIcons.Apply(window);
                UpdateSettingsControlMetrics(window);
                UpdatePatternControlMetrics(window);
                if (data->contentWindow) {
                    if (data->appMode) {
                        SendMessageW(app->status, WM_SETFONT, SendMessageW(window, WM_GETFONT, 0, 0), FALSE);
                    }
                    FitSettingsWindow(window, *data);
                }
            }
            return 0;
        case WM_SETTINGCHANGE:
        case WM_DPICHANGED:
            if (data) {
                PostMessageW(window, UPDATE_SETTINGS_CONTROL_METRICS, 0, 0);
            }
            break;
        case ENSURE_SETTINGS_CONTROL_VISIBLE:
            if (data) {
                EnsureSettingsControlVisible(window, *data, reinterpret_cast<HWND>(wParam));
            }
            return 0;
        case UPDATE_OUTPUTS:
            data->outputsUpdatePending = false;
            RebuildOutputs();
            UpdateSettingsOutputControls(window, *data);
            return 0;
        case WM_DISPLAYCHANGE:
            if (data) {
                PopulateMonitorList(window, *data);
                if (app && (data->appMode || app->previewActive)) {
                    SynchronizeRuntimeSettings();
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
                        const WPARAM showKeyboardCues =
                            MAKEWPARAM(UIS_CLEAR, UISF_HIDEFOCUS | UISF_HIDEACCEL);
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
            if (data && data->contentWindow && wParam != SIZE_MINIMIZED) {
                LayoutSettingsContent(window, *data);
                UpdateSettingsScrollBars(window, *data, false);
            }
            return 0;
        case WM_TIMER:
            if (wParam == ID_PATTERN_ITEMS_TIMER && data && app->patternCatalogReady) {
                PopulatePatternComboBatch(window, *data);
                return 0;
            }
            if (wParam == ID_SCREEN_SAVER_CHECK_TIMER) {
                UpdateScreenSaverInhibition();
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
                app->changingScreenSaver = false;
                app->uninstallingScreenSaver = false;
                EnableSettingsControl(GetDlgItem(controls, ID_INSTALL), true);
                if (data) {
                    HWND button = GetDlgItem(controls, ID_INSTALL);
                    const TextId text = IsScreenSaverInstalled()
                        ? TXT_UNINSTALL_SCREEN_SAVER
                        : TXT_INSTALL_SCREEN_SAVER;
                    SetWindowTextIfChanged(button,
                        PreserveControlMnemonic(button, GetLocalizedText(data->language, text)));
                }
                if (uninstalling && exitCode != 0) {
                    const std::wstring failure = UninstallationFailureStatus(ActiveLanguage());
                    ShowTransientStatus(failure.c_str());
                } else if (uninstalling) {
                    ShowTransientStatus(GetLocalizedText(ActiveLanguage(), TXT_UNINSTALLATION_SUCCEEDED));
                } else if (exitCode == 0) {
                    ShowTransientStatus(GetLocalizedText(ActiveLanguage(), TXT_INSTALLATION_SUCCEEDED));
                } else {
                    ShowTransientStatus(GetLocalizedText(ActiveLanguage(), TXT_INSTALLATION_FAILED));
                }
                return 0;
            }
            if (wParam == ID_STATUS_RESET_TIMER) {
                KillTimer(window, ID_STATUS_RESET_TIMER);
                RestoreCurrentStatus();
                return 0;
            }
            if (wParam == ID_RECORD_CHECK_TIMER) {
                RenderSurface* source = RecordingSurface();
                if (source
                    && (FAILED(source->renderer->RecordingError())
                        || !source->renderer->IsRecording())) {
                    StopRecording();
                }
                return 0;
            }
            break;
        case WM_HSCROLL:
            if (data && lParam == 0 && ScrollSettingsWindow(window, SB_HORZ, LOWORD(wParam))) {
                return 0;
            }
            if (data && !data->updating && lParam != 0) {
                const unsigned previousSize = data->settings->cellSize;
                const unsigned gridWidth = static_cast<unsigned>(data->settings->showGrid);
                const unsigned sliderSize = static_cast<unsigned>(SendDlgItemMessageW(controls,
                    ID_CELL_SIZE, TBM_GETPOS, 0, 0));
                const unsigned minimumSize = std::max(app->minimumCellSize, 1U + gridWidth);
                data->settings->cellSize = std::clamp(sliderSize + gridWidth, minimumSize, 64U);
                data->settings->generationsPerSecond = static_cast<unsigned>(SendDlgItemMessageW(controls,
                    ID_GENERATION_RATE, TBM_GETPOS, 0, 0));
                data->settings->densityPercent = static_cast<unsigned>(SendDlgItemMessageW(controls,
                    ID_INITIAL_DENSITY, TBM_GETPOS, 0, 0));
                ApplySettingsChanges(*data, previousSize != data->settings->cellSize);
                UpdateSettingsSlider(window, *data, GetDlgCtrlID(reinterpret_cast<HWND>(lParam)));
                if (previousSize != data->settings->cellSize) {
                    UpdateSettingsPatterns(window, *data);
                }
            }
            return 0;
        case WM_VSCROLL:
            if (data) {
                if (lParam == 0 && ScrollSettingsWindow(window, SB_VERT, LOWORD(wParam))) {
                    return 0;
                }
            }
            break;
        case WM_MOUSEWHEEL:
            if (data) {
                if (ScrollSettingsWheel(window, wParam)) {
                    return 0;
                }
            }
            break;
        case WM_NOTIFY:
            if (reinterpret_cast<NMHDR*>(lParam)->idFrom == ID_MONITOR_LIST
                    && reinterpret_cast<NMHDR*>(lParam)->code == NM_CUSTOMDRAW) {
                NMLVCUSTOMDRAW* customDraw = reinterpret_cast<NMLVCUSTOMDRAW*>(lParam);
                if (customDraw->nmcd.dwDrawStage == CDDS_PREPAINT) {
                    return CDRF_NOTIFYPOSTPAINT;
                }
                if (customDraw->nmcd.dwDrawStage == CDDS_POSTPAINT) {
                    HWND list = customDraw->nmcd.hdr.hwndFrom;
                    if (GetFocus() == list
                            && (SendMessageW(list, WM_QUERYUISTATE, 0, 0) & UISF_HIDEFOCUS) == 0) {
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
                const NMHDR* notification = reinterpret_cast<const NMHDR*>(lParam);
                if (notification->idFrom == ID_MONITOR_LIST
                        && notification->code == LVN_ITEMCHANGING
                        && ShouldPreventMonitorUncheck(*reinterpret_cast<const NMLISTVIEW*>(lParam), *data)) {
                    return TRUE;
                }
            }
            if (data && HandleMonitorNotification(window, *data, lParam)) {
                return 0;
            }
            break;
        case WM_COMMAND:
            if (!data) {
                break;
            }
            switch (LOWORD(wParam)) {
                case ID_LANGUAGE:
                    if (HIWORD(wParam) == CBN_DROPDOWN) {
                        UpdateComboBoxDropDownSize(GetDlgItem(controls, ID_LANGUAGE));
                    } else if (HIWORD(wParam) == CBN_SELCHANGE && !data->updating) {
                        data->language = LanguageFromCombo(GetDlgItem(controls, ID_LANGUAGE));
                        data->settings->language = static_cast<int>(data->language);
                        ApplyLocalizedCaptions(window, *data);
                        if (data->appMode) {
                            data->settings->Save();
                        }
                    }
                    return 0;
                case ID_PATTERN:
                    if (HIWORD(wParam) == CBN_DROPDOWN) {
                        UpdatePatternControlMetrics(window);
                    } else if (HIWORD(wParam) == CBN_SELCHANGE && !data->updating && app->patternCatalogReady
                            && data->patternItemsAdded == data->patternItems.size()) {
                        const LRESULT row = SendDlgItemMessageW(controls, ID_PATTERN, CB_GETCURSEL, 0, 0);
                        const LRESULT selection = SendDlgItemMessageW(controls, ID_PATTERN, CB_GETITEMDATA,
                            static_cast<WPARAM>(row), 0);
                        const std::span<const LifePattern> patterns = PatternCatalog::All();
                        if (selection >= 0 && static_cast<std::size_t>(selection) <= patterns.size()) {
                            data->settings->patternId = selection
                                ? patterns[selection - 1].id
                                : std::wstring();
                            ApplySettingsChanges(*data, true);
                            UpdateSettingsPatterns(window, *data);
                        }
                    }
                    return 0;
                case ID_ALIVE_COLOR:
                    if (ChooseSettingsColor(window, data->settings->aliveColor)) {
                        ApplySettingsChanges(*data, false);
                        SetButtonColor(GetDlgItem(controls, ID_ALIVE_COLOR), data->settings->aliveColor);
                    }
                    return 0;
                case ID_BACKGROUND_COLOR:
                    if (ChooseSettingsColor(window, data->settings->backgroundColor)) {
                        ApplySettingsChanges(*data, false);
                        SetButtonColor(GetDlgItem(controls, ID_BACKGROUND_COLOR),
                            data->settings->backgroundColor);
                    }
                    return 0;
                case ID_GRID_COLOR:
                    if (ChooseSettingsColor(window, data->settings->gridColor)) {
                        ApplySettingsChanges(*data, false);
                        SetButtonColor(GetDlgItem(controls, ID_GRID_COLOR), data->settings->gridColor);
                    }
                    return 0;
                case ID_SHOW_GRID:
                {
                    const unsigned previousSize = data->settings->cellSize;
                    data->settings->showGrid = IsDlgButtonChecked(controls, ID_SHOW_GRID) == BST_CHECKED;
                    data->settings->cellSize = std::max(previousSize, data->settings->showGrid ? 2U : 1U);
                    ApplySettingsChanges(*data, previousSize != data->settings->cellSize);
                    UpdateSettingsSlider(window, *data, ID_CELL_SIZE);
                    if (previousSize != data->settings->cellSize) {
                        UpdateSettingsPatterns(window, *data);
                    }
                    return 0;
                }
                case ID_PREVENT_SCREEN_SAVER:
                    data->settings->preventScreenSaver =
                        IsDlgButtonChecked(controls, ID_PREVENT_SCREEN_SAVER) == BST_CHECKED;
                    data->settings->Save();
                    UpdateScreenSaverInhibition();
                    return 0;
                case ID_RANDOM_ALIVE_COLOR:
                    data->settings->randomAliveColor =
                        IsDlgButtonChecked(controls, ID_RANDOM_ALIVE_COLOR) == BST_CHECKED;
                    ApplySettingsChanges(*data, false);
                    return 0;
                case ID_RANDOM_BACKGROUND_COLOR:
                    data->settings->randomBackgroundColor =
                        IsDlgButtonChecked(controls, ID_RANDOM_BACKGROUND_COLOR) == BST_CHECKED;
                    ApplySettingsChanges(*data, false);
                    return 0;
                case ID_RANDOM_GRID_COLOR:
                    data->settings->randomGridColor =
                        IsDlgButtonChecked(controls, ID_RANDOM_GRID_COLOR) == BST_CHECKED;
                    ApplySettingsChanges(*data, false);
                    return 0;
                case ID_SYSTEM_SCREEN_SAVER:
                    if (data->appMode && !OpenSystemScreenSaverSettings(window)) {
                        ShowTransientStatus(GetLocalizedText(data->language, TXT_SYSTEM_SCREEN_SAVER_FAILED));
                    }
                    return 0;
                case ID_AUTO_RESET:
                    data->settings->autoReset =
                        IsDlgButtonChecked(controls, ID_AUTO_RESET) == BST_CHECKED;
                    ApplySettingsChanges(*data, false);
                    return 0;
                case ID_PATTERNS_ONLY:
                    data->settings->patternsOnly =
                        IsDlgButtonChecked(controls, ID_PATTERNS_ONLY) == BST_CHECKED;
                    ApplySettingsChanges(*data, true);
                    UpdateSettingsPatterns(window, *data);
                    return 0;
                case ID_INSTALL:
                    if (data->appMode) {
                        RequestScreenSaverChange(window);
                    }
                    return 0;
                case ID_RECORD_TOGGLE:
                    if (PrimaryIsRecording()) {
                        StopRecording();
                    } else {
                        StartRecording(window);
                    }
                    return 0;
                case ID_RECORD_SETTINGS:
                    ShowRecordingSettings(window, *data);
                    return 0;
                case ID_SNAPSHOT:
                    SaveSnapshot(window);
                    return 0;
                case ID_RESET_SETTINGS:
                    ResetSettings(window, *data);
                    return 0;
                case ID_RESTART:
                    app->resetRequested.store(true, std::memory_order_relaxed);
                    return 0;
                case ID_PAUSE:
                    app->paused.store(!app->paused.load(std::memory_order_relaxed),
                        std::memory_order_relaxed);
                    UpdatePauseButton();
                    RestoreCurrentStatus();
                    return 0;
                case ID_PREVIEW_TOGGLE:
                    if (app->previewActive) {
                        StopSettingsPreview(window);
                    } else {
                        StartSettingsPreview(window, *data);
                    }
                    UpdateSettingsOutputControls(window, *data);
                    return 0;
                case ID_HELP:
                case ID_ABOUT:
                    ShowInformationWindow(window, LOWORD(wParam) == ID_HELP, data->language, data->appMode);
                    return 0;
                case IDOK:
                    if (!data->appMode) {
                        data->settings->Save();
                        CloseApplication();
                    }
                    return 0;
                case ID_CANCEL:
                    SendMessageW(window, WM_CLOSE, 0, 0);
                    return 0;
            }
            break;
        case RENDERER_FAILED:
            MessageBoxW(window, GetLocalizedText(data->language, TXT_RENDERER_FAILED), PRODUCT_NAME,
                MB_OK | MB_ICONERROR);
            CloseApplication();
            return 0;
        case WM_SYSCOMMAND:
            if ((wParam & 0xFFF0) == SC_SCREENSAVE && ShouldInhibitScreenSaver()) {
                return 0;
            }
            break;
        case WM_CLOSE:
            CloseApplication();
            return 0;
        case WM_NCDESTROY:
            RemovePropW(window, INSTANCE_WINDOW_PROPERTY);
            if (data) {
                data->systemDialogFont = nullptr;
            }
            break;
    }
    return DefDlgProcW(window, msg, wParam, lParam);
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
    settings.lpfnWndProc = DefDlgProcW;
    settings.cbWndExtra = DLGWINDOWEXTRA;
    settings.lpszClassName = SETTINGS_CLASS;
    settings.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_BTNFACE + 1);
    return RegisterClassExW(&render) && RegisterClassExW(&settings);
}

/// Installs the existing settings message handler on a native resource dialog.
static INT_PTR CALLBACK SettingsDialogProc(HWND window, UINT msg, WPARAM, LPARAM lParam) {
    if (msg == WM_INITDIALOG) {
        SettingsWindowData* data = reinterpret_cast<SettingsWindowData*>(lParam);
        SetWindowLongPtrW(window, GWLP_USERDATA, lParam);
        SetWindowLongPtrW(window, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(SettingsProc));
        if (CreateSettingsControls(window, *data) != 0) {
            DestroyWindow(window);
        } else {
            app->programIcons.Apply(window);
        }
    }
    return FALSE;
}

/// Creates the EXE or SCR settings dialog and attaches its position persistence.
static bool CreateSettingsWindow(SettingsWindowData& data) {
    data.settings = &app->settings;
    data.appMode = app->mode == RunMode::Application;
    data.language = ActiveLanguage();
    const UINT resource = data.appMode ? IDD_APPLICATION_SETTINGS : IDD_SCREEN_SAVER_SETTINGS;
    DLGTEMPLATE* definition = LoadSystemDialogTemplate(app->instance, resource, nullptr);
    if (definition == nullptr) {
        return false;
    }
    app->controlWindow = CreateDialogIndirectParamW(app->instance, definition, nullptr,
        SettingsDialogProc, reinterpret_cast<LPARAM>(&data));
    HeapFree(GetProcessHeap(), 0, definition);
    if (!app->controlWindow) {
        return false;
    }
    if (!AttachSettingsWindowState(app->controlWindow, data.appMode)) {
        DestroyWindow(app->controlWindow);
        app->controlWindow = nullptr;
        return false;
    }
    FitSettingsWindow(app->controlWindow, data);
    settingsWindowState.Show();
    return true;
}

/// Unpacks, validates, sorts and prepares the catalog without touching controls or the renderer lock.
static void LoadPatternCatalog(std::stop_token stop, HWND window, DWORD threadId) {
    bool succeeded = true;
    try {
        PatternCatalog::All();
    } catch (const std::exception&) {
        succeeded = false;
    }
    if (stop.stop_requested()) {
        return;
    }
    if (window) {
        PostMessageW(window, PATTERN_CATALOG_LOADED, succeeded, 0);
    } else {
        PostThreadMessageW(threadId, PATTERN_CATALOG_LOADED, succeeded, 0);
    }
}

/// Publishes a loaded catalog on the UI thread and starts the requested animation.
static void CompletePatternCatalogLoad(bool succeeded, SettingsWindowData* data) {
    if (app->closing.load(std::memory_order_relaxed)) {
        return;
    }
    if (!succeeded) {
        app->startupFailed = true;
        MessageBoxW(app->controlWindow, GetLocalizedText(ActiveLanguage(), TXT_PATTERN_CATALOG_FAILED),
            PRODUCT_NAME, MB_OK | MB_ICONERROR);
        CloseApplication();
        return;
    }
    app->patternSelection.store(PatternCatalog::Find(app->settings.patternId), std::memory_order_relaxed);
    app->patternCatalogReady.store(true);
    SynchronizeRuntimeSettings();
    if (app->mode != RunMode::Settings || app->previewActive) {
        if (!StartRenderSurfaces()) {
            app->startupFailed = true;
            MessageBoxW(app->controlWindow, GetLocalizedText(ActiveLanguage(), TXT_RENDERER_FAILED),
                PRODUCT_NAME, MB_OK | MB_ICONERROR);
            CloseApplication();
            return;
        }
    }
    if (app->controlWindow && data) {
        UpdateSettingsOutputControls(app->controlWindow, *data);
    }
}

/// Processes independent dialog keys only when that window owns the keyboard focus.
static bool HandleInformationDialogMessage(MSG& msg) {
    HWND focusedWindow = GetAncestor(GetFocus(), GA_ROOT);
    if (helpForm.GetWindow() != nullptr
            && focusedWindow == helpForm.GetWindow()
            && IsDialogMessageW(helpForm.GetWindow(), &msg)) {
        return true;
    }
    if (aboutForm.GetWindow() != nullptr
            && focusedWindow == aboutForm.GetWindow()
            && IsDialogMessageW(aboutForm.GetWindow(), &msg)) {
        return true;
    }
    if (recordingSettingsWindow != nullptr
            && focusedWindow == recordingSettingsWindow
            && IsDialogMessageW(recordingSettingsWindow, &msg)) {
        return true;
    }
    return false;
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

/// Restarts detached standalone animation with the same preferred monitor selection as default startup.
static void StartDefaultApplicationAnimation(Application& application, SettingsWindowData& data) {
    if (!application.surfaces.empty()) {
        return;
    }
    application.settings.animationMonitorDevice.clear();
    RebuildOutputs();
    const bool wasUpdating = data.updating;
    data.updating = true;
    PopulateMonitorList(application.controlWindow, data);
    data.updating = wasUpdating;
    if (application.surfaces.empty()) {
        ShowTransientStatus(GetLocalizedText(data.language, TXT_RENDERER_FAILED));
        return;
    }
    application.paused.store(false, std::memory_order_relaxed);
    HWND controls = SettingsContentWindow(application.controlWindow);
    const std::wstring pauseCaption = PreserveControlMnemonic(GetDlgItem(controls, ID_PAUSE),
        GetLocalizedText(data.language, TXT_PAUSE));
    SetDlgItemTextW(controls, ID_PAUSE, pauseCaption.c_str());
    UpdateSettingsOutputControls(application.controlWindow, data);
    RestoreCurrentStatus();
}

/// Handles standalone Enter with no fixed accept button and explicit Tab order before native dialog
/// processing.
static bool HandleApplicationKeyMessage(Application& application, SettingsWindowData* appSettingsData,
        const MSG& msg) {
    if (msg.message == WM_KEYDOWN
            && msg.wParam == VK_RETURN
            && application.mode == RunMode::Application
            && appSettingsData
            && MessageTargetsWindow(msg, application.controlWindow)
            && GetAncestor(GetFocus(), GA_ROOT) == application.controlWindow) {
        HWND focused = GetFocus();
        const LRESULT dialogCode = SendMessageW(focused, WM_GETDLGCODE, msg.wParam,
            reinterpret_cast<LPARAM>(&msg));
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
static void ProcessApplicationMessages(Application& application, SettingsWindowData* appSettingsData,
        MSG& msg) {
    unsigned dispatchedMessages = 0;
    while (dispatchedMessages < 32 && PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            application.closing.store(true, std::memory_order_relaxed);
            break;
        }
        if (msg.hwnd == nullptr && msg.message == PATTERN_CATALOG_LOADED) {
            CompletePatternCatalogLoad(msg.wParam != 0, appSettingsData);
            ++dispatchedMessages;
            continue;
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

/// Waits for queued input after the current message batch, unless the application is closing.
static void WaitForApplicationMessages(Application& application) {
    if (!application.closing.load(std::memory_order_relaxed)) {
        MsgWaitForMultipleObjectsEx(0, nullptr, INFINITE, QS_ALLINPUT, MWMO_INPUTAVAILABLE);
    }
}

/// Runs message batches and waits for input until the application closes.
static void RunApplicationMessageLoop(Application& application, SettingsWindowData* appSettingsData) {
    MSG msg{};
    while (!application.closing.load(std::memory_order_relaxed)) {
        ProcessApplicationMessages(application, appSettingsData, msg);
        if (application.closing.load(std::memory_order_relaxed)) {
            break;
        }
        WaitForApplicationMessages(application);
    }
}

/// Selects EXE, SCR or installer mode, initializes the application and dispatches native messages.
int APIENTRY wWinMain(_In_ HINSTANCE instance, _In_opt_ HINSTANCE previousInstance,
        _In_ LPWSTR commandLineRaw, _In_ int showCommand) {
    UNREFERENCED_PARAMETER(previousInstance);
    UNREFERENCED_PARAMETER(showCommand);
    INITCOMMONCONTROLSEX controls{
        sizeof(controls),
        ICC_BAR_CLASSES | ICC_STANDARD_CLASSES | ICC_LINK_CLASS | ICC_LISTVIEW_CLASSES
    };
    InitCommonControlsEx(&controls);
    std::wstring command = Trim(commandLineRaw ? commandLineRaw : L"");
    std::transform(command.begin(), command.end(), command.begin(), towlower);
    if (command.rfind(INSTALL_ELEVATED_ARGUMENT, 0) == 0
            || command.rfind(UNINSTALL_ELEVATED_ARGUMENT, 0) == 0) {
        const bool uninstall = command.rfind(UNINSTALL_ELEVATED_ARGUMENT, 0) == 0;
        const bool succeeded = uninstall ? UninstallScreenSaverElevated() : InstallScreenSaverElevated();
        return succeeded ? 0 : 1;
    }
    Application application;
    app = &application;
    application.instance = instance;
    if (!application.programIcons.Load()) {
        return 1;
    }
    const bool screenSaver = IsScrExecutable();
    application.settings.Load(screenSaver ? SettingsProfile::ScreenSaver : SettingsProfile::Standalone);
    if (command.starts_with(L"/p") || command.starts_with(L"-p")) {
        application.mode = RunMode::Preview;
        application.previewParent = ParseParentHandle(command);
        if (!IsWindow(application.previewParent)) {
            return 1;
        }
        const SettingsProfile profile = application.settings.profile;
        application.settings = AppSettings{};
        application.settings.profile = profile;
    } else if (command.starts_with(L"/c") || command.starts_with(L"-c") || screenSaver && command.empty()) {
        application.mode = RunMode::Settings;
    } else if (command.starts_with(L"/s") || command.starts_with(L"-s") || screenSaver) {
        application.mode = RunMode::ScreenSaver;
    }
    std::unique_ptr<void, decltype(&ReleaseApplicationInstance)> mutex(nullptr, ReleaseApplicationInstance);
    if (application.mode == RunMode::Application) {
        bool primary = false;
        HANDLE handle = AcquireApplicationInstance(primary);
        if (!handle) {
            return 1;
        }
        if (!primary) {
            const bool activated = ActivateExistingApplication();
            CloseHandle(handle);
            return activated ? 0 : 1;
        }
        mutex.reset(handle);
    }
    SynchronizeRuntimeSettings();
    if (!RegisterClasses(instance)) {
        return 1;
    }
    SettingsWindowData data;
    if (application.mode == RunMode::Application || application.mode == RunMode::Settings) {
        if (!CreateSettingsWindow(data)) {
            return 1;
        }
        if (application.mode == RunMode::Application) {
            SetForegroundWindow(application.controlWindow);
        }
    }
    if (application.mode != RunMode::Settings && !StartRenderSurfaces()) {
        StopRenderSurfaces();
        MessageBoxW(application.controlWindow, GetLocalizedText(ActiveLanguage(), TXT_RENDERER_FAILED),
            PRODUCT_NAME, MB_OK | MB_ICONERROR);
        CloseInformationWindows();
        if (application.controlWindow) {
            DestroyWindow(application.controlWindow);
        }
        app = nullptr;
        return 1;
    }
    if (application.mode == RunMode::Application) {
        UpdateSettingsOutputControls(application.controlWindow, data);
        SetForegroundWindow(application.controlWindow);
    } else if (application.mode == RunMode::ScreenSaver && !application.surfaces.empty()) {
        GetCursorPos(&application.initialMouse);
        application.saverStarted = GetTickCount64();
        ShowCursor(FALSE);
        application.saverCursorHidden = true;
        SetForegroundWindow(application.surfaces.front()->window);
    }
    MSG message{};
    PeekMessageW(&message, nullptr, 0, 0, PM_NOREMOVE);
    try {
        application.patternCatalogThread =
            std::jthread(LoadPatternCatalog, application.controlWindow, GetCurrentThreadId());
    } catch (const std::exception&) {
        CompletePatternCatalogLoad(false, data.settings ? &data : nullptr);
    }
    RunApplicationMessageLoop(application, data.settings ? &data : nullptr);
    application.closing.store(true, std::memory_order_relaxed);
    application.patternCatalogThread.request_stop();
    StopRenderSurfaces();
    CloseInformationWindows();
    if (application.controlWindow) {
        DestroyWindow(application.controlWindow);
        application.controlWindow = nullptr;
    }
    if (application.saverCursorHidden) {
        ShowCursor(TRUE);
    }
    if (application.installProcess) {
        CloseHandle(application.installProcess);
    }
    app = nullptr;
    return application.startupFailed ? 1 : 0;
}
