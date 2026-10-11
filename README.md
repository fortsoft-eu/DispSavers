# FlyingSolids

[Čeština](docs/README.cs-CZ.md) · **English (US)** · [Deutsch](docs/README.de-DE.md) · [Français](docs/README.fr-FR.md) · [Español](docs/README.es-ES.md) · [Italiano](docs/README.it-IT.md) · [Polski](docs/README.pl-PL.md) · [Slovenčina](docs/README.sk-SK.md) · [English (UK)](docs/README.en-GB.md) · [English (Australia)](docs/README.en-AU.md) · [Português](docs/README.pt-PT.md) · [Norsk](docs/README.nb-NO.md) · [Svenska](docs/README.sv-SE.md) · [Suomi](docs/README.fi-FI.md) · [Dansk](docs/README.da-DK.md) · [Íslenska](docs/README.is-IS.md) · [Türkçe](docs/README.tr-TR.md)

FlyingSolids is a native Win32/x86 Direct3D application and Windows screen saver that displays illuminated, solid three-dimensional geometric objects. Objects move independently, rotate, and collide without passing through one another. Random initial conditions and recycled flight positions come from the Windows cryptographic random-number generator and are buffered to keep CPU overhead low.

## Features

- Two camera modes: **Space observation** and a straight **Fly through space** mode
- Independently switchable main and fill lights
- Independent animation space for every selected display
- Up to ten copies of each enabled object
- Object and camera speed from 0% to 1600%; object size from 50% to 200%
- Glossy, illuminated surfaces with a distinct retained color for every object type
- Collision handling between objects, scene boundaries, and the camera flight path
- Refresh-aware rendering on displays with different refresh rates
- PNG snapshots and MP4 recording in the standalone application
- Separate standalone and screen-saver settings
- Interfaces in 17 languages

## Geometric objects

The 27 selectable solids are: cube; regular square pyramid; square pyramidal frustum; square pyramids cut by an oblique plane or by a plane perpendicular to the base; regular triangular, pentagonal and hexagonal prisms; regular octahedron; pentagonal bipyramid; right circular cone; conical frustum; cones cut by an oblique plane or by a plane perpendicular to the base; right circular cylinder; hollow right circular cylinder; paraboloid of revolution closed by a plane; sphere; hemisphere; spherical segment; major spherical segment; spherical layer; triaxial ellipsoid; oblate spheroid; ovoid; spherocylinder; and torus.

## Lighting

The `Main light` and `Fill light` checkboxes below the right-hand sliders independently enable or disable the two lights for the entire scene. By default, `Main light` is on and `Fill light` is off. Light settings are stored separately for the application and screen saver.

## Standalone application

Run `FlyingSolids.exe`. Its single control window remains usable while animation is running. Select one or more animation displays in the list; double-clicking a row toggles that display. All displays may also be detached. Changes are saved continuously. Snapshot output defaults to **Pictures** and falls back to **Documents**. MP4 output defaults to **Videos** and falls back to **Documents**.

Only one instance of the application runs at a time. Launching it again restores its minimized control window, redraws it, and brings it to the foreground.

Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a command. Esc closes the active Help or About window; in the control window, it exits the application.

Snapshots and recordings capture the first active animation display, not a combined image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if those folders do not exist. MP4 recording follows the display refresh rate, up to 60 frames per second.

The application can install or uninstall the embedded screen saver, so a separate `.scr` file is not required for installation.

## Screen saver

`FlyingSolids.scr` has its own settings dialog and no recording controls. Full-screen mode starts an independent scene on every display.

Enable preview in the settings dialog starts a separate full-screen preview on every display. It uses the current settings, allows live adjustments, and can be stopped again. Exit the full-screen saver with any key, mouse movement, or a mouse click.

Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes only that window.

## Settings storage

The two programs do not overwrite each other's settings:

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## System requirements

Windows 7 through Windows 11 support all features, including PNG snapshots and MP4 recording.

Windows Vista SP2: KB971512, KB2117917. MP4 recording does not work on Vista in the current version.

Rendering requires Direct3D 11, not just an older DirectX runtime. MP4 recording requires available Media Foundation components and an H.264 encoder.

## Building and packaging

Open `DispSavers.slnx` in Microsoft Visual Studio with the MSVC v145 toolset and a Windows SDK. Select `Release | x86` and rebuild the solution. This creates both `Release\FlyingSolids.exe` and `Release\FlyingSolids.scr`. No x64 configuration is provided.

Run `PackageRelease.ps1` to create the single solution package `DispSavers-<version>-win32.zip`. Each screen saver occupies its own subdirectory; the current archive contains `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, and `FlyingSolids\license.txt`. Signing parameters contain no personal data in the repository and are supplied only at run time, for example: `PackageRelease.ps1 -SignerName "Certificate name" -SignToolPath "C:\Path\To\signtool.exe" -TimestampServer "https://timestamp.example"`. A binary with an existing valid Authenticode signature is verified and never signed again. The old ZIP is removed at the beginning of every run, and a signing or verification failure stops the script before a new archive is created.

## License

FlyingSolids is available under the [MIT License](license.txt).

Copyright © Petr Červinka — FortSoft 2026
