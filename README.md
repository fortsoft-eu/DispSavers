# FlyingSolids

[Čeština](docs/README.cs-CZ.md) · **English (US)** · [English (UK)](docs/README.en-GB.md) · [English (Australia)](docs/README.en-AU.md) · [Deutsch](docs/README.de-DE.md) · [Français](docs/README.fr-FR.md) · [Español](docs/README.es-ES.md) · [Italiano](docs/README.it-IT.md) · [Português](docs/README.pt-PT.md) · [Polski](docs/README.pl-PL.md) · [Slovenčina](docs/README.sk-SK.md) · [Dansk](docs/README.da-DK.md) · [Suomi](docs/README.fi-FI.md) · [Íslenska](docs/README.is-IS.md) · [Norsk (bokmål)](docs/README.nb-NO.md) · [Svenska](docs/README.sv-SE.md) · [Türkçe](docs/README.tr-TR.md) · [Eesti](docs/README.et-EE.md) · [Gaeilge](docs/README.ga-IE.md) · [Lietuvių](docs/README.lt-LT.md) · [Latviešu](docs/README.lv-LV.md) · [Magyar](docs/README.hu-HU.md) · [Malti](docs/README.mt-MT.md) · [Nederlands](docs/README.nl-NL.md) · [Română](docs/README.ro-RO.md) · [Ελληνικά](docs/README.el-GR.md) · [Bosanski](docs/README.bs-Latn-BA.md) · [Hrvatski](docs/README.hr-HR.md) · [Slovenščina](docs/README.sl-SI.md) · [Crnogorski](docs/README.cnr-Latn-ME.md) · [Беларуская](docs/README.be-BY.md) · [Български](docs/README.bg-BG.md) · [Македонски](docs/README.mk-MK.md) · [Српски](docs/README.sr-Cyrl-RS.md) · [Українська](docs/README.uk-UA.md) · [Русский](docs/README.ru-RU.md)

FlyingSolids is a native Win32/x86 Direct3D application and Windows screen saver that displays illuminated, solid three-dimensional geometric objects. Objects move independently, rotate, and collide without passing through one another.

Row selection determines which displays you are editing; it is separate from the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation options and sliders apply to the selected displays. The selection is remembered separately for EXE and SCR. If all displays were selected, newly connected displays join the selection.

## Features

- Two camera modes: **Space observation** and a straight **Fly through space** mode. Select one or more displays in the list. Camera mode, object selection, lighting, speeds, size and copy count apply only to the selected displays, and each display remembers its own settings.
- Independently switchable main, fill, ambient, and rim lighting
- Independent animation space for every selected display
- Up to ten copies of each enabled object
- Object and camera speed from 0% to 1600%; object size from 50% to 200%
- Glossy, illuminated surfaces with a distinct color for every object type
- Collision handling between objects, scene boundaries, and the camera flight path
- Refresh-aware rendering on displays with different refresh rates
- PNG snapshots and MP4 recording in the standalone application
- Separate standalone and screen-saver settings
- Interfaces in 36 languages

## Geometric objects

Cube; Regular square pyramid; Square pyramidal frustum; Obliquely truncated square pyramid; Square pyramid cut perpendicular to base; Regular triangular prism; Regular pentagonal prism; Regular hexagonal prism; Regular octahedron; Pentagonal bipyramid; Right circular cone; Conical frustum; Obliquely truncated cone; Cone cut perpendicular to base; Right circular cylinder; Hollow right circular cylinder; Hollow cylinder with toroidal ends; Paraboloid of revolution closed by a plane; Sphere; Hemisphere; Spherical cap; Major spherical cap; Spherical segment (two bases); Triaxial ellipsoid; Prolate spheroid; Oblate spheroid; Ovoid; Spherocylinder; Rounded disc (spheroplatelet); Torus.

## Lighting

The `Main light`, `Fill light`, `Ambient light`, and `Rim light` checkboxes below the sliders independently control lighting for the whole scene. Ambient light provides base illumination of object surfaces; rim light highlights their edges. Lighting settings are stored separately for the application and screen saver.

## Standalone application

Run `FlyingSolids.exe`. Its single control window remains usable while animation is running. Select one or more animation displays in the list; double-clicking a row toggles that display. All displays may also be detached. Changes are saved continuously. Only one instance of the application runs at a time. Launching it again restores its minimized control window and brings it to the foreground. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a command. Esc closes the active Help or About window; in the control window, it exits the application. Snapshots and recordings capture the first active animation display, not a combined image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if those folders do not exist. The Recording settings button selects Viewport or TV. Viewport preserves the animation display’s dimensions and refresh rate, up to 60 frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 (60000/1001) or 29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV uses progressive BT.709 limited-range 4:2:0 video. Resolution and frame rate are available only in TV mode. The Recording settings window can be minimized and does not block the other application windows. OK saves choices for the next MP4 recording; Cancel or Esc discards unconfirmed changes. The recorded display cannot be detached during recording; changes to other displays do not stop the recording. Closing the application while recording requires confirmation because it also stops the recording. Prevent screen saver during animation blocks the Windows screen saver only while the animation is actually visible and not paused. The application can install or uninstall the embedded screen saver, so a separate `.scr` file is not required for installation.

## Screen saver

`FlyingSolids.scr` has its own settings dialog and no recording controls. Full-screen mode starts an independent scene on every display. Enable preview in the settings dialog starts a separate full-screen preview on every display. It uses the current settings, allows live adjustments, and can be stopped again. Exit the full-screen saver with any key, mouse movement, or a mouse click. Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes only that window.

## Settings storage

The two programs do not overwrite each other's settings:

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## System requirements

Windows 7 through Windows 11 support all features, including PNG snapshots and MP4 recording. To run the application on Windows Vista SP2, you must install updates KB971512 and KB2117917. MP4 recording does not work on Vista in the current version. Rendering requires Direct3D 11, not just an older DirectX runtime. MP4 recording requires available Media Foundation components and an H.264 encoder.

## Building and packaging

Open `DispSavers.slnx` in Visual Studio with MSVC v145 and a Windows SDK. Select `Release | x86` and rebuild the solution to produce `Release\FlyingSolids.exe` and `Release\FlyingSolids.scr`. No x64 configuration is provided. In the `FlyingSolids` project properties, on the `Signing` page, enter the name or thumbprint of a valid code-signing certificate with a private key in the current user's `Personal (My)` store. The settings apply to both EXE and SCR and are saved in the Git-ignored `FlyingSolids.vcxproj.user` file. SignTool is located automatically in PATH or the Windows SDK. If you use SimplySign, sign in to SimplySign Desktop before building. The build first signs SCR and adds a mandatory RFC 3161 SHA-256 timestamp from the configured timestamp server, then embeds it in EXE, which is also signed and timestamped. Enter the RFC 3161 timestamp server URL in the `Timestamp server` field. Signing, timestamping, or verification failure stops the build; binaries with existing valid timestamped signatures are not signed again.

Package these build outputs by running `PackageRelease.ps1` without signing parameters. The script uses temporary copies, leaves files in `Release` unchanged, and only verifies existing valid signatures. It creates the single `DispSavers-<version>-win32.zip` archive containing `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr`, and `SpaceFlight\license.txt`. The previous ZIP is removed at the start of a run; verification failure prevents creation of a new archive.

## License

FlyingSolids is available under the [MIT License](license.txt). Copyright © Petr Červinka — FortSoft 2026

## FlightCorridor

FlightCorridor offers Flight between four morphing surfaces and Flight through a morphing funnel. Assign exactly one flight to each display: select its row in the list and choose the corresponding radio button.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](FlightCorridor/README.md)

## SpaceFlight

SpaceFlight offers "Infinite undulating surface" and "Long-distance flight — morphing surface". Assign exactly one flight to each display: select its row in the list and choose the corresponding radio button.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](SpaceFlight/README.md)
