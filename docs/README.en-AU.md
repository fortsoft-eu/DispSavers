# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · **English (Australia)** · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids is a native Win32/x86 Direct3D application and Windows screen saver that displays illuminated solid three-dimensional geometric objects. The objects move independently, rotate and collide without passing through one another. Initial conditions and recycled flight positions use the Windows cryptographic random-number generator, buffered to minimise CPU overhead.

## Features

- **Space observation** and a straight **Fly through space** camera mode
- Independently switchable main and fill lights
- An independent scene on every selected display
- One to ten copies of every enabled object
- Object and camera speed from 0% to 1600%; object size from 50% to 200%
- Glossy lighting, retained individual colours and solid-to-solid collision handling
- Refresh-aware rendering on displays with different refresh rates
- PNG snapshots and MP4 recording in the standalone application
- Separate standalone and screen-saver settings
- 27 solid types and a user interface in 17 languages

## Objects

The catalogue comprises polyhedra, prisms, pyramids and their planar cuts, cones and cylinders and their planar cuts, a closed paraboloid of revolution, sphere-derived solids, ellipsoids, an ovoid, a spherocylinder and a torus. The names shown by the program use the established geometric terminology of the selected language.

## Lighting

The `Main light` and `Fill light` checkboxes below the right-hand sliders independently enable or disable the two lights for the entire scene. By default, `Main light` is on and `Fill light` is off. Light settings are stored separately for the application and screen saver.

## Standalone application and screen saver

Run `FlyingSolids.exe` to keep one control window available while the animation runs. Select several displays, toggle one by double-clicking its row, or detach them all. Snapshots default to **Pictures** and MP4 recordings to **Videos**; **Documents** is the fallback for either folder. The EXE can install or uninstall its embedded screen saver.

Only one instance of the application runs at a time. Launching it again restores its minimised control window, redraws it and brings it to the foreground.

Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a command. Esc closes the active Help or About window; in the control window, it exits the application.

Snapshots and recordings capture the first active animation display, not a combined image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if those folders do not exist. MP4 recording follows the display refresh rate, up to 60 frames per second.

`FlyingSolids.scr` has a separate settings dialogue and no recording controls. Full-screen mode creates an independent scene on every display.

Enable preview in the settings dialog starts a separate full-screen preview on every display. It uses the current settings, allows live adjustments and can be stopped again. Exit the full-screen screen saver with any key, mouse movement or a mouse click.

Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes only that window.

## Settings storage

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## System requirements

Windows 7 through Windows 11 support all features, including PNG snapshots and MP4 recording.

Windows Vista SP2: KB971512, KB2117917. MP4 recording does not work on Vista in the current version.

Rendering requires Direct3D 11, not just an older DirectX runtime. MP4 recording requires available Media Foundation components and an H.264 encoder.

## Building and packaging

Open `DispSavers.slnx`, select `Release | x86`, and rebuild the solution with MSVC v145 and a Windows SDK. Both `Release\FlyingSolids.exe` and `Release\FlyingSolids.scr` are produced. `PackageRelease.ps1` creates the single `DispSavers-<version>-win32.zip` solution package, with the binaries and `license.txt` in the `FlyingSolids` subdirectory. No x64 configuration is provided.

## Licence

FlyingSolids is available under the [MIT Licence](../license.txt).

Copyright © Petr Červinka — FortSoft 2026
