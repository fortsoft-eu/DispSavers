# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · **English (Australia)** · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlyingSolids is a native Win32/x86 Direct3D application and Windows screen saver that displays illuminated solid three-dimensional geometric objects. The objects move independently, rotate and collide without passing through one another.

Row selection determines which displays you are editing; it is separate from the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation options and sliders apply to the selected displays. The selection is remembered separately for EXE and SCR. If all displays were selected, newly connected displays join the selection. Different values across selected displays are indicated by indeterminate checkboxes and dotted radio buttons, slider thumbs and the “Enable all” and “Disable all” buttons. Slider labels show a dash instead of a shared value. Changing an option or clicking a slider applies that value to all selected displays.

## Features

- **Space observation** and a straight **Fly through space** camera mode. Select one or more displays in the list. Camera mode, object selection, lighting, speeds, size and copy count apply only to the selected displays, and each display remembers its own settings.
- Independently switchable main, fill, ambient and rim lighting
- An independent scene on every display
- One to ten copies of every enabled object
- Object and camera speed from 0% to 1600%; object size from 50% to 200%
- Glossy lighting, individual colours and solid-to-solid collision handling
- Refresh-aware rendering on displays with different refresh rates
- PNG snapshots and MP4 recording in the standalone application
- Separate standalone and screen-saver settings
- 30 solid types and a user interface in 36 languages

## Objects

Cube; Regular square pyramid; Square pyramidal frustum; Obliquely truncated square pyramid; Square pyramid cut perpendicular to base; Regular triangular prism; Regular pentagonal prism; Regular hexagonal prism; Regular octahedron; Pentagonal bipyramid; Right circular cone; Conical frustum; Obliquely truncated cone; Cone cut perpendicular to base; Right circular cylinder; Hollow right circular cylinder; Hollow cylinder with toroidal ends; Paraboloid of revolution closed by a plane; Sphere; Hemisphere; Spherical cap; Major spherical cap; Spherical segment (two bases); Triaxial ellipsoid; Prolate spheroid; Oblate spheroid; Ovoid; Spherocylinder; Rounded disc (spheroplatelet); Torus.

## Lighting

The `Main light`, `Fill light`, `Ambient light`, and `Rim light` checkboxes below the sliders independently control lighting on the selected displays. Ambient light provides base illumination of object surfaces; rim light highlights their edges. Lighting settings are stored separately for the application and screen saver.

## Standalone application and screen saver

Run `FlyingSolids.exe` to keep one control window available while the animation runs. Enable or disable animation outputs using the display checkboxes or by double-clicking their rows. The EXE can install or uninstall its embedded screen saver. Only one instance of the application runs at a time. Launching it again restores its minimised control window and brings it to the foreground. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a command. Esc closes the active Help or About window; in the control window, it exits the application. Snapshots and recordings capture the first active animation display, not a combined image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if those folders do not exist. The Recording settings button selects Viewport or TV. Viewport preserves the animation display’s dimensions and refresh rate, up to 60 frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 (60000/1001) or 29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV uses progressive BT.709 limited-range 4:2:0 video. Resolution and frame rate are available only in TV mode. The Recording settings window can be minimised and does not block the other application windows. OK saves choices for the next MP4 recording; Cancel or Esc discards unconfirmed changes. The recorded display’s animation output cannot be disabled during recording; changes to other displays do not stop the recording. Closing the application while recording requires confirmation because it also stops the recording. Pause and screen-saver blocking apply to the whole application, regardless of display selection. When blocking is enabled, the Windows screen saver is prevented only while unpaused animation is visible on at least one display. `FlyingSolids.scr` has a separate settings dialogue and no recording controls. Full-screen mode creates an independent scene on every display. Enable preview in the settings dialog starts a separate full-screen preview on every display. It uses the current settings, allows live adjustments and can be stopped again. Exit the full-screen screen saver with any key, mouse movement or a mouse click. Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes only that window.

## Settings storage

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## System requirements

Windows 7 through Windows 11 support all features, including PNG snapshots and MP4 recording. To run the application on Windows Vista SP2, you must install updates KB971512 and KB2117917. MP4 recording does not work on Vista in the current version. Rendering requires Direct3D 11, not just an older DirectX runtime. MP4 recording requires available Media Foundation components and an H.264 encoder. The standalone application can also run on Linux through Wine; screen saver integration is available only on Windows.

## Building and packaging

Open `DispSavers.slnx` in Visual Studio with MSVC v145 and a Windows SDK. Select `Release | x86` and rebuild the solution to produce `Release\FlyingSolids.exe` and `Release\FlyingSolids.scr`. No x64 configuration is provided. In the `FlyingSolids` project properties, on the `Signing` page, enter the name or thumbprint of a valid code-signing certificate with a private key in the current user's `Personal (My)` store. The settings apply to both EXE and SCR and are saved in the Git-ignored `FlyingSolids.vcxproj.user` file. SignTool is located automatically in PATH or the Windows SDK. If you use SimplySign, sign in to SimplySign Desktop before building. The build first signs SCR and adds a mandatory RFC 3161 SHA-256 timestamp from the configured timestamp server, then embeds it in EXE, which is also signed and timestamped. Enter the RFC 3161 timestamp server URL in the `Timestamp server` field. Signing, timestamping, or verification failure stops the build; binaries with existing valid timestamped signatures are not signed again.

Package these build outputs by running `PackageRelease.ps1` without signing parameters. The script uses temporary copies, leaves files in `Release` unchanged, and only verifies existing valid signatures. It creates the single `DispSavers-<version>-win32.zip` archive containing `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr`, and `SpaceFlight\license.txt`. The previous ZIP is removed at the start of a run; verification failure prevents creation of a new archive.

## Licence

FlyingSolids is available under the [MIT Licence](../license.txt). Copyright © Petr Červinka — FortSoft 2026

## FlightCorridor

FlightCorridor offers Flight between four morphing surfaces and Flight through a morphing funnel. Assign exactly one flight to each display: select its row in the list and choose the corresponding radio button.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](../FlightCorridor/README.en-AU.md)

## SpaceFlight

SpaceFlight: Infinite undulating surface; Long-distance flight — morphing surface; Flight through gravitationally warped space. Assign exactly one flight to each display: select its row in the list and choose the corresponding radio button.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](../SpaceFlight/README.en-AU.md)
