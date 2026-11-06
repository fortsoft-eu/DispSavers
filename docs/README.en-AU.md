# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · **English (Australia)** · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Hardware-accelerated animation of solid 3D objects.

Select one or more displays in the list. Camera mode, object selection, lighting, speeds, size and copy count apply only to the selected displays, and each display remembers its own settings. FlyingSolids displays illuminated solid 3D objects. The sliders set object and camera speed from 0–1600%, one to ten copies and size from 50–200%. Choose Space observation or the straight Fly through space mode and enable the required objects. The Main light, Fill light, Ambient light, and Rim light checkboxes below the sliders independently control lighting on the selected displays. Ambient light provides base illumination of object surfaces; rim light highlights their edges. Lighting settings are stored separately for the application and screen saver.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Hardware-accelerated flight through a morphing corridor and funnel.

FlightCorridor: Flight between four morphing surfaces; Flight through a morphing funnel. Assign exactly one animation to each display. Texture switches between textured surfaces and wireframe. Free camera rotation slowly changes the viewing direction in all three dimensions. The Pauses and reversals option adds randomised braking, pauses and reversals of the rotation; forward flight continues. Animation speed ranges from 0–1600%. Every display has an independent randomised scene rendered at its own refresh rate. Main light, fill light, ambient light and rim light can be switched independently for the selected displays. Lighting applies only to textured surfaces.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Hardware-accelerated flight over undulating and morphing surfaces.

SpaceFlight: Infinite undulating surface; Long-distance flight — morphing surface; Flight through gravitationally warped space. Assign exactly one animation to each display. Texture switches between textured surfaces and wireframe. Free camera rotation slowly changes the viewing direction in all three dimensions. The Pauses and reversals option adds randomised braking, pauses and reversals of the rotation; forward flight continues. Animation speed ranges from 0–1600%. Every display has an independent randomised scene rendered at its own refresh rate. Main light, fill light, ambient light and rim light can be switched independently for the selected displays. Lighting applies only to textured surfaces. The two surface animations offer Plane, Waves, or Funnel. Funnel draws the camera inward along a descending spiral. The gravitationally warped space flight uses a three-dimensional wireframe lattice. Texture, surface shape and lighting apply only to the two surface flights.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Conway's Game of Life on one shared world across displays.

### Rules

Conway's Game of Life uses B3/S23 rules. A dead cell is born with exactly three live neighbours; a live cell survives with two or three. The eight neighbours include diagonals. All cells advance together. Opposite edges wrap: left joins right, top joins bottom.

### Displays and shared world

EXE checkboxes enable displays; settings apply to the shared world. One enabled display contains the entire world. With part of an arrangement enabled, completely empty rows and columns collapse: left and right displays join when the middle one is disabled. Interior holes that cannot collapse remain in the simulation. Selecting all displays, or running SCR, preserves the enclosing desktop rectangle and invisible gaps. Each display shows its own region of the same simulation.

### Starting state and patterns

The default is random noise with 25% live cells. Initial density ranges from 0–100% and applies at the next restart. Known patterns only uses 4,106 bundled patterns without noise and disables density. Choose a mixture or a named pattern; dimensions are in cells. Type a name to search. All catalogue patterns are always available. Small verified patterns repeat in separate copies; large or complex ones start once in the centre. An oversized pattern is centred and clipped; changing the world or cell size preserves the selection. Changing the mode or pattern starts a new scene. Restarts retain the choice; the catalogue works offline.

### Cell size, grid, and colours

Without the grid, cell size is 1–64 px. Show grid adds a 1 px edge inside the existing spacing: the displayed size and slider decrease by one, with usable values 1–63. Turning it off restores the value. The slider retains its full range and snaps back at the unavailable endpoint; the checkbox stays enabled. These toggles preserve the scene, except enabling the grid at 1 px changes spacing to 2 px and starts anew. Changing cell size or displays also starts anew. Very large worlds may require a larger minimum. Live-cell, background, and grid colours change independently without restarting. Random live-cell colour chooses a new colour at every manual or automatic scene restart. Your saved colour is preserved and restored when this option is disabled. The same behaviour can be enabled separately for background and grid colours; both new options are off by default.

### Speed, pause, and automatic restart

Speed is 0–240 generations/s, independent of display refresh; 0 stops evolution. Pause and Resume preserve the world. Restart creates a fresh start in the chosen mode. Optional automatic restart detects static and exactly repeating visible phases, including oscillators. It compares simulation generations, not elapsed seconds; invisible regions are excluded. Checking results is asynchronous, so restart can occur slightly later. Defaults are 8 px spacing, 20 generations/s, random live-cell colours, and automatic restart enabled. The grid is off by default. Achieved speed depends on performance and cell count. Automatic restart checks regions of enabled displays; gaps between them can keep evolving but are excluded from comparisons.

### Reset values

Reset restores a displayed cell size of 8 px with or without the grid (spacing 9 or 8 px), speed 20 generations/s, density 25%, and the three default colours. Other choices, including the selected pattern, are preserved. A new scene is created only if spacing changes, or density changes in noise mode.

### Standalone application and MP4 recording

EXE saves settings continuously and records the first active display to MP4, not the combined world. Videos is suggested, with Documents as fallback. Viewport uses display dimensions and refresh rate up to 60 fps. TV offers 1920 × 1080, 1440 × 1080, or 1280 × 720 in 16:9 at 50, 25, 59.94 (60000/1001), or 29.97 (30000/1001) fps. Aspect ratio is preserved; TV uses progressive BT.709 limited-range 4:2:0. Recording settings is independent and can be minimised. OK saves options for the next recording; Cancel or Esc discards pending changes. The recorded display cannot be disabled; other outputs can change. Closing during recording requires confirmation. With animation focused, Space pauses/resumes, F9: Start recording; F10: Stop recording. The cursor hides after 1 second of inactivity and reappears on movement. Tab/Shift+Tab navigates controls; Alt activates underlined commands. Esc closes Help/About, or exits the main window. Windows screen saver… opens the system Screen Saver Settings panel.

### Snapshot and screen saver management in EXE

Snapshot saves a BMP/GIF/JPEG/PNG/TIFF/WebP of the recorded display, or otherwise the first active display, at its resolution without restarting the scene. Pictures is suggested, with Documents as fallback. Prevent screen saver during animation inhibits the Windows screen saver while animation is visible and not paused. Zero speed is not pause. Installation from EXE unpacks the bundled SCR and selects it as the Windows screen saver. Installation and uninstallation may require administrator approval; the status bar shows progress until completion. If removal is blocked, close the running saver, its settings, and Windows preview.

### Windows screen saver

GameOfLife.scr uses all displays and stores settings separately from EXE. Enable preview runs full-screen animation while settings remain open. The small Windows preview scales the whole world down. OK saves settings; Cancel or Esc discards changes. Mouse movement or a key exits the full-screen saver. MP4 recording is available in EXE.

### Window positions and state

Closing saves main and About window positions separately; Help also saves its size and normal or maximised state before any minimisation. This is independent of confirming application settings. Exiting the application closes Help and About as well.

### Rendering and pattern licenses

Evolution and visible-state comparisons use Direct3D 11 shaders on the GPU; a software renderer is available when hardware initialization fails. Each display uses the established framepacer at its own refresh rate. MP4 requires Media Foundation and an H.264 encoder. Patterns come from LifeWiki (GFDL 1.2 or later) and Alan Hensel's public-domain collections. Program code is MIT-licensed; catalogue notices and source licenses are separate.

[Pattern sources, licenses, and import details](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### DISPLAYS

Row selection determines which displays you are editing; it is separate from the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation options and sliders apply to the selected displays. The selection is remembered separately for EXE and SCR. If all displays were selected, newly connected displays join the selection. Different values across selected displays are indicated by indeterminate checkboxes and dotted radio buttons, slider thumbs and the “Enable all” and “Disable all” buttons. Slider labels show a dash instead of a shared value. Changing an option or clicking a slider applies that value to all selected displays.

### CONTROLS

Enable or disable animation outputs using the display checkboxes or by double-clicking their rows. Each display uses an independent scene. Snapshot saves BMP/GIF/JPEG/PNG/TIFF/WebP and the recording button starts or stops MP4. Pause stops the animation. The application also installs or uninstalls its embedded screen saver. Settings are saved continuously. Only one instance of the application runs at a time. Launching it again restores its minimised control window and brings it to the foreground. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a command. Esc closes the active Help or About window; in the control window, it exits the application. Pause and screen-saver blocking apply to the whole application, regardless of display selection. When blocking is enabled, the Windows screen saver is prevented only while unpaused animation is visible on at least one display.

### SNAPSHOTS AND RECORDING

Snapshots and recordings capture the first active animation display, not a combined image of all displays. BMP/GIF/JPEG/PNG/TIFF/WebP uses Pictures and MP4 uses Videos, with Documents as the fallback if those folders do not exist. The Recording settings button selects Viewport or TV. Viewport preserves the animation display’s dimensions and refresh rate, up to 60 frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 (60000/1001) or 29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV uses progressive BT.709 limited-range 4:2:0 video. Resolution and frame rate are available only in TV mode. The Recording settings window can be minimised and does not block the other application windows. OK saves choices for the next MP4 recording; Cancel or Esc discards unconfirmed changes. The recorded display’s animation output cannot be disabled during recording; changes to other displays do not stop the recording. Closing the application while recording requires confirmation because it also stops the recording.

### PREVIEW AND CONTROLS

Enable preview starts a full-screen preview on every display and allows live adjustments while the settings dialog remains open. OK saves the settings and Cancel discards them. Exit the full-screen screen saver with Esc or mouse movement. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a command. Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes only that window.

### System requirements

Windows 7 through Windows 11 support all features, including BMP/GIF/JPEG/PNG/TIFF/WebP snapshots and MP4 recording. To run the application on Windows Vista SP2, you must install updates KB971512 and KB2117917. MP4 recording does not work on Vista in the current version. Rendering requires Direct3D 11, not just an older DirectX runtime. MP4 recording requires available Media Foundation components and an H.264 encoder. The standalone application can also run on Linux through Wine; screen saver integration is available only on Windows.

## Building and packaging

Open `DispSavers.slnx` in Visual Studio with MSVC v145 and a Windows SDK. Select `Release | x86` and rebuild the solution to produce `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\GameOfLife.exe`, `Release\GameOfLife.scr`, `Release\SpaceFlight.exe` and `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr`. No x64 configuration is provided.

Package these build outputs by running `PackageRelease.ps1` without signing parameters. The script uses temporary copies, leaves files in `Release` unchanged, and only verifies existing valid signatures. It creates the single `DispSavers-<version>-win32.zip` archive containing `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `GameOfLife\GameOfLife.exe`, `GameOfLife\GameOfLife.scr`, `GameOfLife\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr`, and `SpaceFlight\license.txt`. The previous ZIP is removed at the start of a run; verification failure prevents creation of a new archive.

## Licence

DispSavers is available under the [MIT Licence](../license.txt). Copyright © Petr Červinka — FortSoft 2026
