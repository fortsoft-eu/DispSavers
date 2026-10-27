# DispSavers

[Čeština](docs/README.cs-CZ.md) · **English (US)** · [English (UK)](docs/README.en-GB.md) · [English (Australia)](docs/README.en-AU.md) · [Deutsch](docs/README.de-DE.md) · [Français](docs/README.fr-FR.md) · [Español](docs/README.es-ES.md) · [Italiano](docs/README.it-IT.md) · [Português](docs/README.pt-PT.md) · [Polski](docs/README.pl-PL.md) · [Slovenčina](docs/README.sk-SK.md) · [Dansk](docs/README.da-DK.md) · [Suomi](docs/README.fi-FI.md) · [Íslenska](docs/README.is-IS.md) · [Norsk (bokmål)](docs/README.nb-NO.md) · [Svenska](docs/README.sv-SE.md) · [Türkçe](docs/README.tr-TR.md) · [Eesti](docs/README.et-EE.md) · [Gaeilge](docs/README.ga-IE.md) · [Lietuvių](docs/README.lt-LT.md) · [Latviešu](docs/README.lv-LV.md) · [Magyar](docs/README.hu-HU.md) · [Malti](docs/README.mt-MT.md) · [Nederlands](docs/README.nl-NL.md) · [Română](docs/README.ro-RO.md) · [Ελληνικά](docs/README.el-GR.md) · [Bosanski](docs/README.bs-Latn-BA.md) · [Hrvatski](docs/README.hr-HR.md) · [Slovenščina](docs/README.sl-SI.md) · [Crnogorski](docs/README.cnr-Latn-ME.md) · [Беларуская](docs/README.be-BY.md) · [Български](docs/README.bg-BG.md) · [Македонски](docs/README.mk-MK.md) · [Српски](docs/README.sr-Cyrl-RS.md) · [Українська](docs/README.uk-UA.md) · [Русский](docs/README.ru-RU.md)

## FlyingSolids

Hardware-accelerated animation of solid 3D objects.

Select one or more displays in the list. Camera mode, object selection, lighting, speeds, size and copy count apply only to the selected displays, and each display remembers its own settings. FlyingSolids displays illuminated solid 3D objects. The sliders set object and camera speed from 0–1600%, one to ten copies of each object, and size from 50–200%. Choose Space observation or the straight Fly through space mode and enable the required object types. The Main light, Fill light, Ambient light, and Rim light checkboxes below the sliders independently control lighting on the selected displays. Ambient light provides base illumination of object surfaces; rim light highlights their edges. Lighting settings are stored separately for the application and screen saver.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Hardware-accelerated flight through a morphing corridor and funnel.

FlightCorridor: Flight between four morphing surfaces; Flight through a morphing funnel. Assign exactly one animation to each display. Texture switches between textured surfaces and wireframe. Free camera rotation slowly changes the viewing direction in all three dimensions. The Pauses and reversals option adds randomized braking, pauses, and reversals of the rotation; forward flight continues. Animation speed ranges from 0–1600%. Every display has an independent randomized scene rendered at its own refresh rate. Main light, fill light, ambient light, and rim light can be switched independently for the selected displays. Lighting applies only to textured surfaces.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Hardware-accelerated flight over undulating and morphing surfaces.

SpaceFlight: Infinite undulating surface; Long-distance flight — morphing surface; Flight through gravitationally warped space. Assign exactly one animation to each display. Texture switches between textured surfaces and wireframe. Free camera rotation slowly changes the viewing direction in all three dimensions. The Pauses and reversals option adds randomized braking, pauses, and reversals of the rotation; forward flight continues. Animation speed ranges from 0–1600%. Every display has an independent randomized scene rendered at its own refresh rate. Main light, fill light, ambient light, and rim light can be switched independently for the selected displays. Lighting applies only to textured surfaces. The two surface animations offer Plane, Waves, or Funnel. Funnel draws the camera inward along a descending spiral. The gravitationally warped space flight uses a three-dimensional wireframe lattice. Texture, surface shape, and lighting apply only to the two surface flights.

`SpaceFlight.exe` · `SpaceFlight.scr`

## DISPLAYS

Row selection determines which displays you are editing; it is separate from the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation options and sliders apply to the selected displays. The selection is remembered separately for EXE and SCR. If all displays were selected, newly connected displays join the selection. Different values across selected displays are indicated by indeterminate checkboxes and dotted radio buttons, slider thumbs, and the “Enable all” and “Disable all” buttons. Slider labels show a dash instead of a shared value. Changing an option or clicking a slider applies that value to all selected displays.

## CONTROLS

Enable or disable animation outputs using the display checkboxes or by double-clicking their rows. Every display uses an independent scene. Snapshot saves a PNG and the recording button starts or stops an MP4. Pause stops the animation. The application also installs or uninstalls its embedded screen saver. Settings are saved continuously. Only one instance of the application runs at a time. Launching it again restores its minimized control window and brings it to the foreground. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a command. Esc closes the active Help or About window; in the control window, it exits the application. Pause and screen-saver blocking apply to the whole application, regardless of display selection. When blocking is enabled, the Windows screen saver is prevented only while unpaused animation is visible on at least one display.

## SNAPSHOTS AND RECORDING

Snapshots and recordings capture the first active animation display, not a combined image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if those folders do not exist. The Recording settings button selects Viewport or TV. Viewport preserves the animation display’s dimensions and refresh rate, up to 60 frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 (60000/1001) or 29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV uses progressive BT.709 limited-range 4:2:0 video. Resolution and frame rate are available only in TV mode. The Recording settings window can be minimized and does not block the other application windows. OK saves choices for the next MP4 recording; Cancel or Esc discards unconfirmed changes. The recorded display’s animation output cannot be disabled during recording; changes to other displays do not stop the recording. Closing the application while recording requires confirmation because it also stops the recording.

## PREVIEW AND CONTROLS

Enable preview starts a full-screen preview on every display while the settings dialog remains open for live adjustments. OK saves the settings and Cancel discards them. Exit the full-screen saver with Esc or mouse movement. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a command. Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes only that window.

## System requirements

Windows 7 through Windows 11 support all features, including PNG snapshots and MP4 recording. To run the application on Windows Vista SP2, you must install updates KB971512 and KB2117917. MP4 recording does not work on Vista in the current version. Rendering requires Direct3D 11, not just an older DirectX runtime. MP4 recording requires available Media Foundation components and an H.264 encoder. The standalone application can also run on Linux through Wine; screen saver integration is available only on Windows.

## Building and packaging

Open `DispSavers.slnx` in Visual Studio with MSVC v145 and a Windows SDK. Select `Release | x86` and rebuild the solution to produce `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\SpaceFlight.exe` and `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr`. No x64 configuration is provided.

Package these build outputs by running `PackageRelease.ps1` without signing parameters. The script uses temporary copies, leaves files in `Release` unchanged, and only verifies existing valid signatures. It creates the single `DispSavers-<version>-win32.zip` archive containing `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr`, and `SpaceFlight\license.txt`. The previous ZIP is removed at the start of a run; verification failure prevents creation of a new archive.

## License

DispSavers is available under the [MIT License](license.txt). Copyright © Petr Červinka — FortSoft 2026
