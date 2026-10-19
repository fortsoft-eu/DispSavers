# SpaceFlight

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · **English (Australia)** · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

SpaceFlight offers „Infinite undulating surface“ and „Long-distance flight — morphing surface“. Assign exactly one flight to each display: select its row in the list and choose the corresponding radio button. The first animation is selected on every display by default. Textured rendering is the default; clear Texture to switch the selected displays to wireframe. With several rows selected, the choice applies to every selected display. The slider sets animation speed from 0–1600%. On default startup, EXE enables only the primary animation display; the screen saver enables all displays. Each display renders at its own refresh rate. Settings are stored separately for the application and screen saver. Camera tumbling enables smooth rotation of the view in all directions on the selected displays; it is off by default. Stops and reversals adds gradual braking, brief pauses and reversal of camera tumbling at random intervals. It is available when Camera tumbling is enabled and is off by default; forward flight continues.

## Application

`SpaceFlight.exe`

Select several displays; double-click a row to toggle it, or clear the selection for all displays. Each display uses an independent scene. Snapshot saves PNG and the recording button starts or stops MP4. Pause stops the animation. The application also installs or uninstalls its embedded screen saver. Settings are saved continuously. Only one instance of the application runs at a time. Launching it again restores its minimised control window and brings it to the foreground. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a command. Esc closes the active Help or About window; in the control window, it exits the application. Prevent screen saver during animation blocks the Windows screen saver only while the animation is actually visible and not paused.

Snapshots and recordings capture the first active animation display, not a combined image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if those folders do not exist. The Recording settings button selects Viewport or TV. Viewport preserves the animation display’s dimensions and refresh rate, up to 60 frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 (60000/1001) or 29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV uses progressive BT.709 limited-range 4:2:0 video. Resolution and frame rate are available only in TV mode. The Recording settings window can be minimised and does not block the other application windows. OK saves choices for the next MP4 recording; Cancel or Esc discards unconfirmed changes. The recorded display cannot be detached during recording; changes to other displays do not stop the recording. Closing the application while recording requires confirmation because it also stops the recording.

Windows 7 through Windows 11 support all features, including PNG snapshots and MP4 recording. To run the application on Windows Vista SP2, you must install updates KB971512 and KB2117917. MP4 recording does not work on Vista in the current version.

## Screen saver

`SpaceFlight.scr`

Enable preview starts a full-screen preview on every display and allows live adjustments while the settings dialog remains open. OK saves the settings and Cancel discards them. Exit the full-screen screen saver with Esc or mouse movement. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a command. Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes only that window.

Windows 7 through Windows 11 are supported. To run the application on Windows Vista SP2, you must install updates KB971512 and KB2117917.

## Building

Open `DispSavers.slnx` in Visual Studio with MSVC v145 and a Windows SDK. Select `Release | x86` and rebuild the solution to produce `Release\SpaceFlight.exe` and `Release\SpaceFlight.scr`. No x64 configuration is provided. Signing is enabled by default for both Release and Debug. In the `SpaceFlight` project properties, on the `Signing` page, enter the name or thumbprint of a valid code-signing certificate with a private key in the current user's `Personal (My)` store. The settings apply to both EXE and SCR and are saved in the Git-ignored `SpaceFlight.vcxproj.user` file. SignTool is located automatically in PATH or the Windows SDK. If you use SimplySign, sign in to SimplySign Desktop before building. The build first signs SCR and adds a mandatory RFC 3161 SHA-256 timestamp from the configured timestamp server, then embeds it in EXE, which is also signed and timestamped. Enter the RFC 3161 timestamp server URL in the `Timestamp server` field. Signing, timestamping, or verification failure stops the build; binaries with existing valid timestamped signatures are not signed again.

[MIT License](license.txt) — Copyright © Petr Červinka — FortSoft 2026
