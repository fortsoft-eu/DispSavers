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
 * Last modified for version 1.2.2.1
 */

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "Localization.h"
#include <windows.h>

constexpr auto localizedLanguages = DefineLocalization(std::initializer_list<LocalizedLanguage>{
    DefineLanguage(LANG_CS, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Čeština" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — ovládání" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Nastavení FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Jazyk:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Rychlost animace: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Průlet na vybraných monitorech" },
        LocalizedText{ TXT_ENABLE_ALL, L"Vše zapnout" },
        LocalizedText{ TXT_DISABLE_ALL, L"Vše vypnout" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Monitor animace" },
        LocalizedText{ TXT_MONITOR, L"Monitor" },
        LocalizedText{ TXT_RESOLUTION, L"Rozlišení" },
        LocalizedText{ TXT_POSITION, L"Poloha" },
        LocalizedText{ TXT_PRIMARY, L"hlavní" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Storno" },
        LocalizedText{ TXT_START_RECORDING, L"Spustit záznam…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Ukončit záznam" },
        LocalizedText{ TXT_PAUSE, L"Pozastavit" },
        LocalizedText{ TXT_RESUME, L"Pokračovat" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Nainstalovat spořič" },
        LocalizedText{ TXT_EXIT, L"Konec" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animace běží…" },
        LocalizedText{ TXT_RECORDING, L"Probíhá záznam MP4…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Záznam byl uložen." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Záznam MP4 se nepodařilo spustit." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Instalace spořiče nebyla provedena." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Spořič byl nainstalován." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Direct3D renderer se nepodařilo inicializovat." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Průlet mezi čtyřmi proměnlivými plochami" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Průlet proměnlivým trychtýřem" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Ukončení aplikace ukončí právě probíhající záznam." },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Navštívit web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Web nelze otevřít ve výchozím prohlížeči." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Adresu URL nelze zkopírovat do schránky." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Informace nelze zkopírovat do schránky." },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Zapnout náhled" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Vypnout náhled" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animace je pozastavena." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blokovat spořič při animaci" },
        LocalizedText{ TXT_READY_STATUS, L"Připraven." },
        LocalizedText{ TXT_HELP, L"Nápověda" },
        LocalizedText{ TXT_ABOUT, L"O aplikaci" },
        LocalizedText{ TXT_CLOSE, L"Zavřít" },
        LocalizedText{ TXT_SNAPSHOT, L"Snímek…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Snímek byl uložen." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Snímek se nepodařilo uložit." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Odinstalovat spořič" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Spořič byl odinstalován." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Odinstalace se nezdařila. Pokud je spořič nebo jeho náhled spuštěný, zavřete jej a odinstalaci "
            L"zopakujte."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Odinstalace se nezdařila, protože je otevřené nastavení FlightCorridor. Zavřete je a "
            L"odinstalaci zopakujte."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Odinstalace se nezdařila, protože běží systémový náhled. Zavřete okno Nastavení spořiče "
            L"obrazovky a odinstalaci zopakujte."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Odinstalace se nezdařila, protože je spuštěný spořič nebo celoobrazovkový náhled. Ukončete jej "
            L"klávesou Esc nebo pohybem myši a odinstalaci zopakujte."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Hardwarově akcelerovaný průlet proměnlivým koridorem a trychtýřem."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Verze:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Cílová platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Web:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Otevřít ve výchozím prohlížeči" },
        LocalizedText{ TXT_COPY_URL, L"Kopírovat &adresu" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopírovat &informace" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Hlavní světlo" },
        LocalizedText{ TXT_FILL_LIGHT, L"Doplňkové světlo" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Základní jas" },
        LocalizedText{ TXT_RIM_LIGHT, L"Přisvětlení obrysů" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Textura" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Volná rotace kamery" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauzy a obraty" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Prostředek s licencí není k dispozici." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Model monitoru" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Obnovovací frekvence" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bitová hloubka" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Formát barvy" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Barevný prostor" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bitů/kanál" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bitů/pixel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Nastavení záznamu" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Rozlišení:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Snímková frekvence:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Změny se použijí při příštím záznamu MP4." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMACE A NASTAVENÍ\r\nFlightCorridor: Průlet mezi čtyřmi proměnlivými plochami; Průlet "
            L"proměnlivým trychtýřem. Každému monitoru přiřaďte právě jednu animaci. Textura přepíná mezi "
            L"texturovanými plochami a drátěným modelem. Volná rotace kamery pomalu mění směr pohledu ve "
            L"všech třech rozměrech. Volba „Pauzy a obraty“ přidává náhodné zpomalování, pauzy a změny směru "
            L"otáčení; dopředný pohyb pokračuje. Rychlost animace je 0–1600 %. Každý monitor má nezávislou "
            L"náhodnou scénu a vykreslování podle své obnovovací frekvence. Hlavní světlo, doplňkové světlo, "
            L"základní jas a přisvětlení obrysů lze pro označené monitory zapínat nezávisle. Osvětlení se "
            L"používá jen u texturovaných ploch.\r\n\r\nMONITORY\r\nOznačení řádků určuje, které monitory "
            L"právě nastavujete; není totožné se zatržítky zapínajícími animační výstupy. Ctrl+A označí "
            L"všechny monitory, Ctrl a Shift umožňují upravit označení. Všechny animační volby a jezdce "
            L"platí pro označené monitory. Označení se pamatuje zvlášť pro EXE a SCR. Pokud byly označené "
            L"všechny monitory, označí se i nově připojené. Různé hodnoty na označených monitorech ukazuje "
            L"neurčitý stav zatržítek a tečkování přepínačů, úchytů jezdců a tlačítek „Vše zapnout“ a „Vše "
            L"vypnout“. Popisek jezdce místo společné hodnoty zobrazuje pomlčku. Změna volby nebo kliknutí "
            L"na jezdec sjednotí příslušnou hodnotu na označených monitorech.\r\n\r\nOVLÁDÁNÍ\r\nAnimační "
            L"výstupy zapnete nebo vypnete zatržítky u monitorů nebo dvojklikem na jejich řádky. Každý "
            L"monitor používá nezávislou scénu. Snímek ukládá PNG, tlačítko záznamu spouští a ukončuje MP4. "
            L"Pozastavení zastaví animaci. Aplikace také instaluje nebo odinstaluje zabalený spořič. "
            L"Nastavení se ukládá průběžně. Aplikace běží pouze v jedné instanci. Další spuštění obnoví "
            L"minimalizované ovládací okno a přenese je do popředí. Mezi ovládacími prvky přecházejte "
            L"klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a příslušného písmene. Esc "
            L"zavře aktivní nápovědu či okno O aplikaci; v ovládacím okně ukončí aplikaci. Pozastavení a "
            L"blokování spořiče platí pro celou aplikaci bez ohledu na označené monitory. Je-li blokování "
            L"zapnuté, brání spuštění spořiče Windows pouze tehdy, když je alespoň na jednom monitoru "
            L"viditelná nepozastavená animace.\r\n\r\nSNÍMKY A ZÁZNAM\r\nSnímek a záznam zachycují první "
            L"aktivní animační monitor, nikoli společnou plochu všech monitorů. PNG používá složku Obrázky, "
            L"MP4 složku Videa; při jejich neexistenci se použijí Dokumenty. Tlačítko Nastavení záznamu "
            L"vybírá Viewport nebo TV. Viewport zachovává rozměry animačního monitoru a jeho obnovovací "
            L"frekvenci, nejvýše 60 snímků za sekundu. TV nabízí rozlišení 1920 × 1080, 1440 × 1080 nebo "
            L"1280 × 720 v poměru 16:9 a frekvenci 50, 25, 59.94 (60000/1001) nebo 29.97 (30000/1001) snímků "
            L"za sekundu. Obraz zachovává poměr stran; TV používá progresivní video BT.709 s omezeným "
            L"rozsahem a vzorkováním 4:2:0. Rozlišení a snímkovou frekvenci lze vybrat pouze v režimu TV. "
            L"Okno Nastavení záznamu lze minimalizovat a neblokuje ostatní okna aplikace. OK uloží volby pro "
            L"příští záznam MP4; Storno nebo Esc nepotvrzené změny zahodí. Animační výstup nahrávaného "
            L"monitoru nelze během záznamu vypnout; změny ostatních monitorů záznam nezastaví. Ukončení "
            L"aplikace při probíhajícím záznamu vyžaduje potvrzení, protože současně ukončí záznam.\r\n\r\n"
            L"SYSTÉMOVÉ POŽADAVKY\r\nWindows 7 až Windows 11 podporují všechny funkce včetně snímků PNG a "
            L"záznamu MP4. Pro spuštění aplikace ve Windows Vista SP2 je nutné nainstalovat aktualizace "
            L"KB971512 a KB2117917. Záznam MP4 na Vistě v současné verzi nefunguje. Vykreslování vyžaduje "
            L"Direct3D 11, nikoli jen starší DirectX runtime. Záznam MP4 vyžaduje dostupné součásti Media "
            L"Foundation a kodér H.264."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACE A NASTAVENÍ\r\nFlightCorridor: Průlet mezi čtyřmi proměnlivými plochami; Průlet "
            L"proměnlivým trychtýřem. Každému monitoru přiřaďte právě jednu animaci. Textura přepíná mezi "
            L"texturovanými plochami a drátěným modelem. Volná rotace kamery pomalu mění směr pohledu ve "
            L"všech třech rozměrech. Volba „Pauzy a obraty“ přidává náhodné zpomalování, pauzy a změny směru "
            L"otáčení; dopředný pohyb pokračuje. Rychlost animace je 0–1600 %. Každý monitor má nezávislou "
            L"náhodnou scénu a vykreslování podle své obnovovací frekvence. Hlavní světlo, doplňkové světlo, "
            L"základní jas a přisvětlení obrysů lze pro označené monitory zapínat nezávisle. Osvětlení se "
            L"používá jen u texturovaných ploch.\r\n\r\nMONITORY\r\nOznačení řádků určuje, které monitory "
            L"právě nastavujete; není totožné se zatržítky zapínajícími animační výstupy. Ctrl+A označí "
            L"všechny monitory, Ctrl a Shift umožňují upravit označení. Všechny animační volby a jezdce "
            L"platí pro označené monitory. Označení se pamatuje zvlášť pro EXE a SCR. Pokud byly označené "
            L"všechny monitory, označí se i nově připojené. Různé hodnoty na označených monitorech ukazuje "
            L"neurčitý stav zatržítek a tečkování přepínačů, úchytů jezdců a tlačítek „Vše zapnout“ a „Vše "
            L"vypnout“. Popisek jezdce místo společné hodnoty zobrazuje pomlčku. Změna volby nebo kliknutí "
            L"na jezdec sjednotí příslušnou hodnotu na označených monitorech.\r\n\r\nNÁHLED A OVLÁDÁNÍ\r\n"
            L"Zapnout náhled spustí celoobrazovkový náhled na všech monitorech; změny lze zkoušet za "
            L"otevřeného nastavení. OK nastavení uloží, Storno je zahodí. Celoobrazovkový spořič ukončíte "
            L"klávesou Esc nebo pohybem myši. Mezi ovládacími prvky přecházejte klávesami Tab a Shift+Tab; "
            L"podtržené volby lze vyvolat pomocí Alt a příslušného písmene. Esc v nastavení odpovídá "
            L"tlačítku Storno; v nápovědě nebo okně O aplikaci zavře pouze toto okno.\r\n\r\nSYSTÉMOVÉ "
            L"POŽADAVKY\r\nPodporovány jsou systémy Windows 7 až Windows 11. Pro spuštění aplikace ve "
            L"Windows Vista SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917. Vykreslování "
            L"vyžaduje Direct3D 11, nikoli jen starší DirectX runtime."
        },
    }),
    DefineLanguage(LANG_EN_US, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"English (US)" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Controls" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlightCorridor Settings" },
        LocalizedText{ TXT_LANGUAGE, L"Language:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Animation speed: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Flight for selected displays" },
        LocalizedText{ TXT_ENABLE_ALL, L"Enable all" },
        LocalizedText{ TXT_DISABLE_ALL, L"Disable all" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Animation display" },
        LocalizedText{ TXT_MONITOR, L"Display" },
        LocalizedText{ TXT_RESOLUTION, L"Resolution" },
        LocalizedText{ TXT_POSITION, L"Position" },
        LocalizedText{ TXT_PRIMARY, L"primary" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Cancel" },
        LocalizedText{ TXT_START_RECORDING, L"Start recording…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Stop recording" },
        LocalizedText{ TXT_PAUSE, L"Pause" },
        LocalizedText{ TXT_RESUME, L"Resume" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Install screen saver" },
        LocalizedText{ TXT_EXIT, L"Exit" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animation is running…" },
        LocalizedText{ TXT_RECORDING, L"MP4 recording in progress…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Recording was saved." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Could not start MP4 recording." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"The screen saver was not installed." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"The screen saver was installed." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Could not initialize the Direct3D renderer." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Flight between four morphing surfaces" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Flight through a morphing funnel" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Closing the application will stop the recording currently in progress."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Visit %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"The website could not be opened in the default browser." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"The URL could not be copied to the clipboard." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"The information could not be copied to the clipboard."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Enable preview" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Disable preview" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animation is paused." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Prevent screen saver during animation" },
        LocalizedText{ TXT_READY_STATUS, L"Ready." },
        LocalizedText{ TXT_HELP, L"Help" },
        LocalizedText{ TXT_ABOUT, L"About" },
        LocalizedText{ TXT_CLOSE, L"Close" },
        LocalizedText{ TXT_SNAPSHOT, L"Snapshot…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Snapshot was saved." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Could not save the snapshot." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Uninstall screen saver" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"The screen saver was uninstalled." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"The screen saver could not be uninstalled. If the screen saver or its preview is running, "
            L"close it and try again."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Uninstallation failed because FlightCorridor settings are open. Close the settings window and "
            L"try again."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Uninstallation failed because the system preview is running. Close the Screen Saver Settings "
            L"window and try again."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Uninstallation failed because the screen saver or full-screen preview is running. Exit it with "
            L"Esc or by moving the mouse, then try again."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Hardware-accelerated flight through a morphing corridor and funnel."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Version:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Target platform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Website:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Open in default browser" },
        LocalizedText{ TXT_COPY_URL, L"Copy &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copy &information" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Main light" },
        LocalizedText{ TXT_FILL_LIGHT, L"Fill light" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ambient light" },
        LocalizedText{ TXT_RIM_LIGHT, L"Rim light" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Texture" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Free camera rotation" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauses and reversals" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"License resource unavailable." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Monitor model" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Refresh rate" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bit depth" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Color format" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Color space" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bits/channel" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bits/pixel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Recording settings" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Resolution:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Frame rate:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Changes apply to the next MP4 recording." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMATION AND SETTINGS\r\nFlightCorridor: Flight between four morphing surfaces; Flight "
            L"through a morphing funnel. Assign exactly one animation to each display. Texture switches "
            L"between textured surfaces and wireframe. Free camera rotation slowly changes the viewing "
            L"direction in all three dimensions. The Pauses and reversals option adds randomized braking, "
            L"pauses, and reversals of the rotation; forward flight continues. Animation speed ranges from "
            L"0–1600%. Every display has an independent randomized scene rendered at its own refresh rate. "
            L"Main light, fill light, ambient light, and rim light can be switched independently for the "
            L"selected displays. Lighting applies only to textured surfaces.\r\n\r\nDISPLAYS\r\nRow "
            L"selection determines which displays you are editing; it is separate from the checkboxes that "
            L"enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. "
            L"All animation options and sliders apply to the selected displays. The selection is remembered "
            L"separately for EXE and SCR. If all displays were selected, newly connected displays join the "
            L"selection. Different values across selected displays are indicated by indeterminate checkboxes "
            L"and dotted radio buttons, slider thumbs, and the “Enable all” and “Disable all” buttons. "
            L"Slider labels show a dash instead of a shared value. Changing an option or clicking a slider "
            L"applies that value to all selected displays.\r\n\r\nCONTROLS\r\nEnable or disable animation "
            L"outputs using the display checkboxes or by double-clicking their rows. Every display uses an "
            L"independent scene. Snapshot saves a PNG and the recording button starts or stops an MP4. Pause "
            L"stops the animation. The application also installs or uninstalls its embedded screen saver. "
            L"Settings are saved continuously. Only one instance of the application runs at a time. "
            L"Launching it again restores its minimized control window and brings it to the foreground. Use "
            L"Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a "
            L"command. Esc closes the active Help or About window; in the control window, it exits the "
            L"application. Pause and screen-saver blocking apply to the whole application, regardless of "
            L"display selection. When blocking is enabled, the Windows screen saver is prevented only while "
            L"unpaused animation is visible on at least one display.\r\n\r\nSNAPSHOTS AND RECORDING\r\n"
            L"Snapshots and recordings capture the first active animation display, not a combined image of "
            L"all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if those "
            L"folders do not exist. The Recording settings button selects Viewport or TV. Viewport preserves "
            L"the animation display’s dimensions and refresh rate, up to 60 frames per second. TV offers "
            L"1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 (60000/1001) or "
            L"29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV uses progressive "
            L"BT.709 limited-range 4:2:0 video. Resolution and frame rate are available only in TV mode. The "
            L"Recording settings window can be minimized and does not block the other application windows. "
            L"OK saves choices for the next MP4 recording; Cancel or Esc discards unconfirmed changes. The "
            L"recorded display’s animation output cannot be disabled during recording; changes to other "
            L"displays do not stop the recording. Closing the application while recording requires "
            L"confirmation because it also stops the recording.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows 7 "
            L"through Windows 11 support all features, including PNG snapshots and MP4 recording. To run the "
            L"application on Windows Vista SP2, you must install updates KB971512 and KB2117917. MP4 "
            L"recording does not work on Vista in the current version. Rendering requires Direct3D 11, not "
            L"just an older DirectX runtime. MP4 recording requires available Media Foundation components "
            L"and an H.264 encoder."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATION AND SETTINGS\r\nFlightCorridor: Flight between four morphing surfaces; Flight "
            L"through a morphing funnel. Assign exactly one animation to each display. Texture switches "
            L"between textured surfaces and wireframe. Free camera rotation slowly changes the viewing "
            L"direction in all three dimensions. The Pauses and reversals option adds randomized braking, "
            L"pauses, and reversals of the rotation; forward flight continues. Animation speed ranges from "
            L"0–1600%. Every display has an independent randomized scene rendered at its own refresh rate. "
            L"Main light, fill light, ambient light, and rim light can be switched independently for the "
            L"selected displays. Lighting applies only to textured surfaces.\r\n\r\nDISPLAYS\r\nRow "
            L"selection determines which displays you are editing; it is separate from the checkboxes that "
            L"enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. "
            L"All animation options and sliders apply to the selected displays. The selection is remembered "
            L"separately for EXE and SCR. If all displays were selected, newly connected displays join the "
            L"selection. Different values across selected displays are indicated by indeterminate checkboxes "
            L"and dotted radio buttons, slider thumbs, and the “Enable all” and “Disable all” buttons. "
            L"Slider labels show a dash instead of a shared value. Changing an option or clicking a slider "
            L"applies that value to all selected displays.\r\n\r\nPREVIEW AND CONTROLS\r\nEnable preview "
            L"starts a full-screen preview on every display while the settings dialog remains open for live "
            L"adjustments. OK saves the settings and Cancel discards them. Exit the full-screen saver with "
            L"Esc or mouse movement. Use Tab and Shift+Tab to move between controls; use Alt and the "
            L"underlined letter to activate a command. Esc in the settings dialog is equivalent to Cancel; "
            L"in Help or About, it closes only that window.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows 7 through "
            L"Windows 11 are supported. To run the application on Windows Vista SP2, you must install "
            L"updates KB971512 and KB2117917. Rendering requires Direct3D 11, not just an older DirectX "
            L"runtime."
        },
    }),
    DefineLanguage(LANG_EN_GB, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"English (UK)" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Controls" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlightCorridor Settings" },
        LocalizedText{ TXT_LANGUAGE, L"Language:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Animation speed: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Flight for selected displays" },
        LocalizedText{ TXT_ENABLE_ALL, L"Enable all" },
        LocalizedText{ TXT_DISABLE_ALL, L"Disable all" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Animation display" },
        LocalizedText{ TXT_MONITOR, L"Display" },
        LocalizedText{ TXT_RESOLUTION, L"Resolution" },
        LocalizedText{ TXT_POSITION, L"Position" },
        LocalizedText{ TXT_PRIMARY, L"primary" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Cancel" },
        LocalizedText{ TXT_START_RECORDING, L"Start recording…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Stop recording" },
        LocalizedText{ TXT_PAUSE, L"Pause" },
        LocalizedText{ TXT_RESUME, L"Resume" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Install screen saver" },
        LocalizedText{ TXT_EXIT, L"Exit" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animation is running…" },
        LocalizedText{ TXT_RECORDING, L"MP4 recording in progress…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Recording was saved." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Could not start MP4 recording." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"The screen saver was not installed." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"The screen saver was installed." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Could not initialise the Direct3D renderer." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Flight between four morphing surfaces" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Flight through a morphing funnel" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Closing the application will stop the recording currently in progress."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Visit %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"The website could not be opened in the default browser." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"The URL could not be copied to the clipboard." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"The information could not be copied to the clipboard."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Enable preview" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Disable preview" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animation is paused." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Prevent screen saver during animation" },
        LocalizedText{ TXT_READY_STATUS, L"Ready." },
        LocalizedText{ TXT_HELP, L"Help" },
        LocalizedText{ TXT_ABOUT, L"About" },
        LocalizedText{ TXT_CLOSE, L"Close" },
        LocalizedText{ TXT_SNAPSHOT, L"Snapshot…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Snapshot was saved." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Could not save the snapshot." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Uninstall screen saver" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"The screen saver was uninstalled." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"The screen saver could not be uninstalled. If the screen saver or its preview is running, "
            L"close it and try again."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Uninstallation failed because FlightCorridor settings are open. Close the settings window and "
            L"try again."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Uninstallation failed because the system preview is running. Close the Screen Saver Settings "
            L"window and try again."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Uninstallation failed because the screen saver or full-screen preview is running. Exit it with "
            L"Esc or by moving the mouse, then try again."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Hardware-accelerated flight through a morphing corridor and funnel."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Version:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Target platform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Website:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Open in default browser" },
        LocalizedText{ TXT_COPY_URL, L"Copy &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copy &information" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Main light" },
        LocalizedText{ TXT_FILL_LIGHT, L"Fill light" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ambient light" },
        LocalizedText{ TXT_RIM_LIGHT, L"Rim light" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Texture" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Free camera rotation" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauses and reversals" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"License resource unavailable." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Monitor model" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Refresh rate" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bit depth" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Colour format" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Colour space" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bits/channel" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bits/pixel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Recording settings" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Resolution:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Frame rate:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Changes apply to the next MP4 recording." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMATION AND SETTINGS\r\nFlightCorridor: Flight between four morphing surfaces; Flight "
            L"through a morphing funnel. Assign exactly one animation to each display. Texture switches "
            L"between textured surfaces and wireframe. Free camera rotation slowly changes the viewing "
            L"direction in all three dimensions. The Pauses and reversals option adds randomised braking, "
            L"pauses and reversals of the rotation; forward flight continues. Animation speed ranges from "
            L"0–1600%. Every display has an independent randomised scene rendered at its own refresh rate. "
            L"Main light, fill light, ambient light and rim light can be switched independently for the "
            L"selected displays. Lighting applies only to textured surfaces.\r\n\r\nDISPLAYS\r\nRow "
            L"selection determines which displays you are editing; it is separate from the checkboxes that "
            L"enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. "
            L"All animation options and sliders apply to the selected displays. The selection is remembered "
            L"separately for EXE and SCR. If all displays were selected, newly connected displays join the "
            L"selection. Different values across selected displays are indicated by indeterminate checkboxes "
            L"and dotted radio buttons, slider thumbs and the “Enable all” and “Disable all” buttons. Slider "
            L"labels show a dash instead of a shared value. Changing an option or clicking a slider applies "
            L"that value to all selected displays.\r\n\r\nCONTROLS\r\nEnable or disable animation outputs "
            L"using the display checkboxes or by double-clicking their rows. Each display uses an "
            L"independent scene. Snapshot saves PNG and the recording button starts or stops MP4. Pause "
            L"stops the animation. The application also installs or uninstalls its embedded screen saver. "
            L"Settings are saved continuously. Only one instance of the application runs at a time. "
            L"Launching it again restores its minimised control window and brings it to the foreground. Use "
            L"Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a "
            L"command. Esc closes the active Help or About window; in the control window, it exits the "
            L"application. Pause and screen-saver blocking apply to the whole application, regardless of "
            L"display selection. When blocking is enabled, the Windows screen saver is prevented only while "
            L"unpaused animation is visible on at least one display.\r\n\r\nSNAPSHOTS AND RECORDING\r\n"
            L"Snapshots and recordings capture the first active animation display, not a combined image of "
            L"all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if those "
            L"folders do not exist. The Recording settings button selects Viewport or TV. Viewport preserves "
            L"the animation display’s dimensions and refresh rate, up to 60 frames per second. TV offers "
            L"1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 (60000/1001) or "
            L"29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV uses progressive "
            L"BT.709 limited-range 4:2:0 video. Resolution and frame rate are available only in TV mode. The "
            L"Recording settings window can be minimised and does not block the other application windows. "
            L"OK saves choices for the next MP4 recording; Cancel or Esc discards unconfirmed changes. The "
            L"recorded display’s animation output cannot be disabled during recording; changes to other "
            L"displays do not stop the recording. Closing the application while recording requires "
            L"confirmation because it also stops the recording.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows 7 "
            L"through Windows 11 support all features, including PNG snapshots and MP4 recording. To run the "
            L"application on Windows Vista SP2, you must install updates KB971512 and KB2117917. MP4 "
            L"recording does not work on Vista in the current version. Rendering requires Direct3D 11, not "
            L"just an older DirectX runtime. MP4 recording requires available Media Foundation components "
            L"and an H.264 encoder."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATION AND SETTINGS\r\nFlightCorridor: Flight between four morphing surfaces; Flight "
            L"through a morphing funnel. Assign exactly one animation to each display. Texture switches "
            L"between textured surfaces and wireframe. Free camera rotation slowly changes the viewing "
            L"direction in all three dimensions. The Pauses and reversals option adds randomised braking, "
            L"pauses and reversals of the rotation; forward flight continues. Animation speed ranges from "
            L"0–1600%. Every display has an independent randomised scene rendered at its own refresh rate. "
            L"Main light, fill light, ambient light and rim light can be switched independently for the "
            L"selected displays. Lighting applies only to textured surfaces.\r\n\r\nDISPLAYS\r\nRow "
            L"selection determines which displays you are editing; it is separate from the checkboxes that "
            L"enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. "
            L"All animation options and sliders apply to the selected displays. The selection is remembered "
            L"separately for EXE and SCR. If all displays were selected, newly connected displays join the "
            L"selection. Different values across selected displays are indicated by indeterminate checkboxes "
            L"and dotted radio buttons, slider thumbs and the “Enable all” and “Disable all” buttons. Slider "
            L"labels show a dash instead of a shared value. Changing an option or clicking a slider applies "
            L"that value to all selected displays.\r\n\r\nPREVIEW AND CONTROLS\r\nEnable preview starts a "
            L"full-screen preview on every display and allows live adjustments while the settings dialog "
            L"remains open. OK saves the settings and Cancel discards them. Exit the full-screen screen "
            L"saver with Esc or mouse movement. Use Tab and Shift+Tab to move between controls; use Alt and "
            L"the underlined letter to activate a command. Esc in the settings dialog is equivalent to "
            L"Cancel; in Help or About, it closes only that window.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows 7 "
            L"through Windows 11 are supported. To run the application on Windows Vista SP2, you must "
            L"install updates KB971512 and KB2117917. Rendering requires Direct3D 11, not just an older "
            L"DirectX runtime."
        },
    }),
    DefineLanguage(LANG_EN_AU, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"English (Australia)" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Controls" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlightCorridor Settings" },
        LocalizedText{ TXT_LANGUAGE, L"Language:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Animation speed: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Flight for selected displays" },
        LocalizedText{ TXT_ENABLE_ALL, L"Enable all" },
        LocalizedText{ TXT_DISABLE_ALL, L"Disable all" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Animation display" },
        LocalizedText{ TXT_MONITOR, L"Display" },
        LocalizedText{ TXT_RESOLUTION, L"Resolution" },
        LocalizedText{ TXT_POSITION, L"Position" },
        LocalizedText{ TXT_PRIMARY, L"primary" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Cancel" },
        LocalizedText{ TXT_START_RECORDING, L"Start recording…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Stop recording" },
        LocalizedText{ TXT_PAUSE, L"Pause" },
        LocalizedText{ TXT_RESUME, L"Resume" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Install screen saver" },
        LocalizedText{ TXT_EXIT, L"Exit" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animation is running…" },
        LocalizedText{ TXT_RECORDING, L"MP4 recording in progress…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Recording was saved." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Could not start MP4 recording." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"The screen saver was not installed." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"The screen saver was installed." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Could not initialise the Direct3D renderer." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Flight between four morphing surfaces" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Flight through a morphing funnel" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Closing the application will stop the recording currently in progress."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Visit %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"The website could not be opened in the default browser." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"The URL could not be copied to the clipboard." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"The information could not be copied to the clipboard."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Enable preview" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Disable preview" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animation is paused." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Prevent screen saver during animation" },
        LocalizedText{ TXT_READY_STATUS, L"Ready." },
        LocalizedText{ TXT_HELP, L"Help" },
        LocalizedText{ TXT_ABOUT, L"About" },
        LocalizedText{ TXT_CLOSE, L"Close" },
        LocalizedText{ TXT_SNAPSHOT, L"Snapshot…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Snapshot was saved." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Could not save the snapshot." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Uninstall screen saver" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"The screen saver was uninstalled." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"The screen saver could not be uninstalled. If the screen saver or its preview is running, "
            L"close it and try again."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Uninstallation failed because FlightCorridor settings are open. Close the settings window and "
            L"try again."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Uninstallation failed because the system preview is running. Close the Screen Saver Settings "
            L"window and try again."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Uninstallation failed because the screen saver or full-screen preview is running. Exit it with "
            L"Esc or by moving the mouse, then try again."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Hardware-accelerated flight through a morphing corridor and funnel."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Version:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Target platform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Website:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Open in default browser" },
        LocalizedText{ TXT_COPY_URL, L"Copy &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copy &information" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Main light" },
        LocalizedText{ TXT_FILL_LIGHT, L"Fill light" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ambient light" },
        LocalizedText{ TXT_RIM_LIGHT, L"Rim light" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Texture" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Free camera rotation" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauses and reversals" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"License resource unavailable." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Monitor model" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Refresh rate" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bit depth" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Colour format" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Colour space" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bits/channel" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bits/pixel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Recording settings" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Resolution:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Frame rate:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Changes apply to the next MP4 recording." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMATION AND SETTINGS\r\nFlightCorridor: Flight between four morphing surfaces; Flight "
            L"through a morphing funnel. Assign exactly one animation to each display. Texture switches "
            L"between textured surfaces and wireframe. Free camera rotation slowly changes the viewing "
            L"direction in all three dimensions. The Pauses and reversals option adds randomised braking, "
            L"pauses and reversals of the rotation; forward flight continues. Animation speed ranges from "
            L"0–1600%. Every display has an independent randomised scene rendered at its own refresh rate. "
            L"Main light, fill light, ambient light and rim light can be switched independently for the "
            L"selected displays. Lighting applies only to textured surfaces.\r\n\r\nDISPLAYS\r\nRow "
            L"selection determines which displays you are editing; it is separate from the checkboxes that "
            L"enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. "
            L"All animation options and sliders apply to the selected displays. The selection is remembered "
            L"separately for EXE and SCR. If all displays were selected, newly connected displays join the "
            L"selection. Different values across selected displays are indicated by indeterminate checkboxes "
            L"and dotted radio buttons, slider thumbs and the “Enable all” and “Disable all” buttons. Slider "
            L"labels show a dash instead of a shared value. Changing an option or clicking a slider applies "
            L"that value to all selected displays.\r\n\r\nCONTROLS\r\nEnable or disable animation outputs "
            L"using the display checkboxes or by double-clicking their rows. Each display uses an "
            L"independent scene. Snapshot saves PNG and the recording button starts or stops MP4. Pause "
            L"stops the animation. The application also installs or uninstalls its embedded screen saver. "
            L"Settings are saved continuously. Only one instance of the application runs at a time. "
            L"Launching it again restores its minimised control window and brings it to the foreground. Use "
            L"Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a "
            L"command. Esc closes the active Help or About window; in the control window, it exits the "
            L"application. Pause and screen-saver blocking apply to the whole application, regardless of "
            L"display selection. When blocking is enabled, the Windows screen saver is prevented only while "
            L"unpaused animation is visible on at least one display.\r\n\r\nSNAPSHOTS AND RECORDING\r\n"
            L"Snapshots and recordings capture the first active animation display, not a combined image of "
            L"all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if those "
            L"folders do not exist. The Recording settings button selects Viewport or TV. Viewport preserves "
            L"the animation display’s dimensions and refresh rate, up to 60 frames per second. TV offers "
            L"1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 (60000/1001) or "
            L"29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV uses progressive "
            L"BT.709 limited-range 4:2:0 video. Resolution and frame rate are available only in TV mode. The "
            L"Recording settings window can be minimised and does not block the other application windows. "
            L"OK saves choices for the next MP4 recording; Cancel or Esc discards unconfirmed changes. The "
            L"recorded display’s animation output cannot be disabled during recording; changes to other "
            L"displays do not stop the recording. Closing the application while recording requires "
            L"confirmation because it also stops the recording.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows 7 "
            L"through Windows 11 support all features, including PNG snapshots and MP4 recording. To run the "
            L"application on Windows Vista SP2, you must install updates KB971512 and KB2117917. MP4 "
            L"recording does not work on Vista in the current version. Rendering requires Direct3D 11, not "
            L"just an older DirectX runtime. MP4 recording requires available Media Foundation components "
            L"and an H.264 encoder."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATION AND SETTINGS\r\nFlightCorridor: Flight between four morphing surfaces; Flight "
            L"through a morphing funnel. Assign exactly one animation to each display. Texture switches "
            L"between textured surfaces and wireframe. Free camera rotation slowly changes the viewing "
            L"direction in all three dimensions. The Pauses and reversals option adds randomised braking, "
            L"pauses and reversals of the rotation; forward flight continues. Animation speed ranges from "
            L"0–1600%. Every display has an independent randomised scene rendered at its own refresh rate. "
            L"Main light, fill light, ambient light and rim light can be switched independently for the "
            L"selected displays. Lighting applies only to textured surfaces.\r\n\r\nDISPLAYS\r\nRow "
            L"selection determines which displays you are editing; it is separate from the checkboxes that "
            L"enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. "
            L"All animation options and sliders apply to the selected displays. The selection is remembered "
            L"separately for EXE and SCR. If all displays were selected, newly connected displays join the "
            L"selection. Different values across selected displays are indicated by indeterminate checkboxes "
            L"and dotted radio buttons, slider thumbs and the “Enable all” and “Disable all” buttons. Slider "
            L"labels show a dash instead of a shared value. Changing an option or clicking a slider applies "
            L"that value to all selected displays.\r\n\r\nPREVIEW AND CONTROLS\r\nEnable preview starts a "
            L"full-screen preview on every display and allows live adjustments while the settings dialog "
            L"remains open. OK saves the settings and Cancel discards them. Exit the full-screen screen "
            L"saver with Esc or mouse movement. Use Tab and Shift+Tab to move between controls; use Alt and "
            L"the underlined letter to activate a command. Esc in the settings dialog is equivalent to "
            L"Cancel; in Help or About, it closes only that window.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows 7 "
            L"through Windows 11 are supported. To run the application on Windows Vista SP2, you must "
            L"install updates KB971512 and KB2117917. Rendering requires Direct3D 11, not just an older "
            L"DirectX runtime."
        },
    }),
    DefineLanguage(LANG_DE, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Deutsch" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Steuerung" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlightCorridor-Einstellungen" },
        LocalizedText{ TXT_LANGUAGE, L"Sprache:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Animationsgeschwindigkeit: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Flug für ausgewählte Monitore" },
        LocalizedText{ TXT_ENABLE_ALL, L"Alle aktivieren" },
        LocalizedText{ TXT_DISABLE_ALL, L"Alle deaktivieren" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Animationsmonitor" },
        LocalizedText{ TXT_MONITOR, L"Monitor" },
        LocalizedText{ TXT_RESOLUTION, L"Auflösung" },
        LocalizedText{ TXT_POSITION, L"Position" },
        LocalizedText{ TXT_PRIMARY, L"primär" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Abbrechen" },
        LocalizedText{ TXT_START_RECORDING, L"Aufnahme starten…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Aufnahme beenden" },
        LocalizedText{ TXT_PAUSE, L"Pause" },
        LocalizedText{ TXT_RESUME, L"Fortsetzen" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Bildschirmschoner installieren" },
        LocalizedText{ TXT_EXIT, L"Beenden" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animation läuft…" },
        LocalizedText{ TXT_RECORDING, L"MP4-Aufnahme läuft…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Aufnahme wurde gespeichert." },
        LocalizedText{ TXT_RECORDING_FAILED, L"MP4-Aufnahme konnte nicht gestartet werden." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Der Bildschirmschoner wurde nicht installiert." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Der Bildschirmschoner wurde installiert." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Direct3D-Renderer konnte nicht initialisiert werden." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Flug zwischen vier veränderlichen Flächen" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Flug durch einen veränderlichen Trichter" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Beim Beenden der Anwendung wird die laufende Aufnahme beendet."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Website %ls besuchen" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Die Website kann nicht im Standardbrowser geöffnet werden."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Die URL konnte nicht in die Zwischenablage kopiert werden."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Die Informationen konnten nicht in die Zwischenablage kopiert werden."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Vorschau einschalten" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Vorschau ausschalten" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animation ist angehalten." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Bildschirmschoner bei Animation sperren" },
        LocalizedText{ TXT_READY_STATUS, L"Bereit." },
        LocalizedText{ TXT_HELP, L"Hilfe" },
        LocalizedText{ TXT_ABOUT, L"Info" },
        LocalizedText{ TXT_CLOSE, L"Schließen" },
        LocalizedText{ TXT_SNAPSHOT, L"Schnappschuss…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Schnappschuss wurde gespeichert." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Der Schnappschuss konnte nicht gespeichert werden." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Bildschirmschoner deinstallieren" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Der Bildschirmschoner wurde deinstalliert." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Der Bildschirmschoner konnte nicht deinstalliert werden. Falls der Bildschirmschoner oder "
            L"seine Vorschau läuft, schließen Sie ihn und versuchen Sie es erneut."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Die Deinstallation ist fehlgeschlagen, weil die FlightCorridor-Einstellungen geöffnet sind. "
            L"Schließen Sie das Fenster und versuchen Sie es erneut."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Die Deinstallation ist fehlgeschlagen, weil die Systemvorschau läuft. Schließen Sie das "
            L"Fenster Bildschirmschonereinstellungen und versuchen Sie es erneut."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Die Deinstallation ist fehlgeschlagen, weil der Bildschirmschoner oder die Vollbildvorschau "
            L"läuft. Beenden Sie ihn mit Esc oder durch Bewegen der Maus und versuchen Sie es erneut."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Hardwarebeschleunigter Flug durch einen veränderlichen Korridor und Trichter."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Version:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Zielplattform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Website:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"Im Standardbrowser &öffnen" },
        LocalizedText{ TXT_COPY_URL, L"&URL kopieren" },
        LocalizedText{ TXT_COPY_INFORMATION, L"&Informationen kopieren" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Hauptlicht" },
        LocalizedText{ TXT_FILL_LIGHT, L"Aufhelllicht" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Umgebungslicht" },
        LocalizedText{ TXT_RIM_LIGHT, L"Konturlicht" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Textur" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Freie Kameradrehung" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pausen und Umkehr" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Die Lizenzressource ist nicht verfügbar." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Monitormodell" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Bildwiederholfrequenz" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bittiefe" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Farbformat" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Farbraum" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u Bit/Kanal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u Bit/Pixel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Aufnahmeeinstellungen" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Auflösung:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Bildfrequenz:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Änderungen gelten für die nächste MP4-Aufnahme." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMATION UND EINSTELLUNGEN\r\nFlightCorridor: Flug zwischen vier veränderlichen Flächen; Flug "
            L"durch einen veränderlichen Trichter. Weisen Sie jedem Monitor genau eine Animation zu. Textur "
            L"wechselt zwischen texturierten Flächen und Drahtgittermodell. Die freie Kameradrehung "
            L"verändert die Blickrichtung langsam in allen drei Dimensionen. Die Option „Pausen und Umkehr“ "
            L"ergänzt zufälliges Abbremsen, Pausen und Wechsel der Drehrichtung; der Vorwärtsflug läuft "
            L"weiter. Die Animationsgeschwindigkeit beträgt 0–1600 %. Jeder Monitor besitzt eine unabhängige "
            L"zufällige Szene und wird mit seiner eigenen Bildwiederholrate angesteuert. Hauptlicht, "
            L"Aufhelllicht, Umgebungslicht und Konturlicht lassen sich für die ausgewählten Monitore "
            L"unabhängig schalten. Die Beleuchtung gilt nur für texturierte Flächen.\r\n\r\nMONITORE\r\nDie "
            L"Zeilenauswahl bestimmt, welche Monitore Sie bearbeiten; sie ist von den Kontrollkästchen zum "
            L"Einschalten der Animationsausgabe getrennt. Strg+A wählt alle Monitore, Strg und Umschalt "
            L"ändern die Auswahl. Alle Animationsoptionen und Regler gelten für die ausgewählten Monitore. "
            L"Die Auswahl wird für EXE und SCR getrennt gespeichert. Waren alle Monitore ausgewählt, werden "
            L"auch neu angeschlossene ausgewählt. Unterschiedliche Werte der ausgewählten Monitore werden "
            L"durch unbestimmte Kontrollkästchen und gepunktete Optionsfelder, Reglergriffe sowie "
            L"Schaltflächen „Alle aktivieren“ und „Alle deaktivieren“ angezeigt. Reglerbeschriftungen zeigen "
            L"statt eines gemeinsamen Werts einen Gedankenstrich. Das Ändern einer Option oder Anklicken "
            L"eines Reglers übernimmt diesen Wert für alle ausgewählten Monitore.\r\n\r\nBEDIENUNG\r\nDie "
            L"Animationsausgabe schalten Sie mit den Kontrollkästchen der Monitore oder per Doppelklick auf "
            L"deren Zeilen ein oder aus. Jeder Monitor besitzt eine unabhängige Szene. Schnappschuss "
            L"speichert PNG, die Aufnahmetaste startet oder beendet MP4. Pause hält die Animation an. Die "
            L"Anwendung installiert oder deinstalliert außerdem den eingebetteten Bildschirmschoner. "
            L"Einstellungen werden laufend gespeichert. Die Anwendung läuft nur in einer Instanz. Ein "
            L"erneuter Start stellt das minimierte Steuerfenster wieder her und bringt es in den "
            L"Vordergrund. Mit Tab und Umschalt+Tab wechseln Sie zwischen den Steuerelementen; mit Alt und "
            L"dem unterstrichenen Buchstaben rufen Sie einen Befehl auf. Esc schließt das aktive Hilfe- oder "
            L"Infofenster; im Steuerfenster beendet es die Anwendung. Pause und Bildschirmschonersperre "
            L"gelten für die gesamte Anwendung, unabhängig von der Monitorauswahl. Bei eingeschalteter "
            L"Sperre wird der Windows-Bildschirmschoner nur verhindert, solange auf mindestens einem Monitor "
            L"eine sichtbare, nicht angehaltene Animation läuft.\r\n\r\nBILDSCHIRMFOTOS UND AUFNAHME\r\n"
            L"Schnappschüsse und Aufnahmen erfassen den ersten aktiven Animationsmonitor, nicht die "
            L"gemeinsame Fläche aller Monitore. PNG verwendet Bilder, MP4 Videos; fehlen diese Ordner, wird "
            L"Dokumente verwendet. Die Schaltfläche Aufnahmeeinstellungen wählt Viewport oder TV. Viewport "
            L"erhält die Abmessungen und Bildwiederholfrequenz des Animationsmonitors bis höchstens 60 "
            L"Bilder pro Sekunde. TV bietet 1920 × 1080, 1440 × 1080 oder 1280 × 720 im Format 16:9 mit 50, "
            L"25, 59.94 (60000/1001) oder 29.97 (30000/1001) Bildern pro Sekunde. Das Seitenverhältnis "
            L"bleibt erhalten; TV verwendet progressives BT.709-Video mit begrenztem Wertebereich und "
            L"4:2:0-Abtastung. Auflösung und Bildfrequenz sind nur im TV-Modus wählbar. Das Fenster "
            L"Aufnahmeeinstellungen lässt sich minimieren und blockiert die anderen Anwendungsfenster nicht. "
            L"OK speichert die Auswahl für die nächste MP4-Aufnahme; Abbrechen oder Esc verwirft "
            L"unbestätigte Änderungen. Die Animationsausgabe des aufgezeichneten Monitors kann während der "
            L"Aufnahme nicht ausgeschaltet werden; Änderungen an anderen Monitoren beenden die Aufnahme "
            L"nicht. Das Beenden der Anwendung während einer Aufnahme muss bestätigt werden, da es auch die "
            L"Aufnahme beendet.\r\n\r\nSYSTEMANFORDERUNGEN\r\nWindows 7 bis Windows 11 unterstützen alle "
            L"Funktionen einschließlich PNG-Schnappschüssen und MP4-Aufnahmen. Zum Ausführen der Anwendung "
            L"unter Windows Vista SP2 müssen die Updates KB971512 und KB2117917 installiert werden. "
            L"MP4-Aufnahmen funktionieren unter Vista in der aktuellen Version nicht. Die Darstellung "
            L"erfordert Direct3D 11, nicht nur eine ältere DirectX-Laufzeitumgebung. MP4-Aufnahmen benötigen "
            L"verfügbare Media-Foundation-Komponenten und einen H.264-Encoder."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATION UND EINSTELLUNGEN\r\nFlightCorridor: Flug zwischen vier veränderlichen Flächen; Flug "
            L"durch einen veränderlichen Trichter. Weisen Sie jedem Monitor genau eine Animation zu. Textur "
            L"wechselt zwischen texturierten Flächen und Drahtgittermodell. Die freie Kameradrehung "
            L"verändert die Blickrichtung langsam in allen drei Dimensionen. Die Option „Pausen und Umkehr“ "
            L"ergänzt zufälliges Abbremsen, Pausen und Wechsel der Drehrichtung; der Vorwärtsflug läuft "
            L"weiter. Die Animationsgeschwindigkeit beträgt 0–1600 %. Jeder Monitor besitzt eine unabhängige "
            L"zufällige Szene und wird mit seiner eigenen Bildwiederholrate angesteuert. Hauptlicht, "
            L"Aufhelllicht, Umgebungslicht und Konturlicht lassen sich für die ausgewählten Monitore "
            L"unabhängig schalten. Die Beleuchtung gilt nur für texturierte Flächen.\r\n\r\nMONITORE\r\nDie "
            L"Zeilenauswahl bestimmt, welche Monitore Sie bearbeiten; sie ist von den Kontrollkästchen zum "
            L"Einschalten der Animationsausgabe getrennt. Strg+A wählt alle Monitore, Strg und Umschalt "
            L"ändern die Auswahl. Alle Animationsoptionen und Regler gelten für die ausgewählten Monitore. "
            L"Die Auswahl wird für EXE und SCR getrennt gespeichert. Waren alle Monitore ausgewählt, werden "
            L"auch neu angeschlossene ausgewählt. Unterschiedliche Werte der ausgewählten Monitore werden "
            L"durch unbestimmte Kontrollkästchen und gepunktete Optionsfelder, Reglergriffe sowie "
            L"Schaltflächen „Alle aktivieren“ und „Alle deaktivieren“ angezeigt. Reglerbeschriftungen zeigen "
            L"statt eines gemeinsamen Werts einen Gedankenstrich. Das Ändern einer Option oder Anklicken "
            L"eines Reglers übernimmt diesen Wert für alle ausgewählten Monitore.\r\n\r\nVORSCHAU UND "
            L"BEDIENUNG\r\nVorschau einschalten startet eine Vollbildvorschau auf allen Monitoren. Der "
            L"Einstellungsdialog bleibt für Änderungen geöffnet. OK speichert, Abbrechen verwirft. Esc oder "
            L"eine Mausbewegung beendet den Vollbildschoner. Mit Tab und Umschalt+Tab wechseln Sie zwischen "
            L"den Steuerelementen; mit Alt und dem unterstrichenen Buchstaben rufen Sie einen Befehl auf. "
            L"Esc im Einstellungsdialog entspricht Abbrechen; in der Hilfe oder im Infofenster schließt es "
            L"nur dieses Fenster.\r\n\r\nSYSTEMANFORDERUNGEN\r\nUnterstützt werden Windows 7 bis Windows 11. "
            L"Zum Ausführen der Anwendung unter Windows Vista SP2 müssen die Updates KB971512 und KB2117917 "
            L"installiert werden. Die Darstellung erfordert Direct3D 11, nicht nur eine ältere "
            L"DirectX-Laufzeitumgebung."
        },
    }),
    DefineLanguage(LANG_FR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Français" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Commandes" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Paramètres de FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Langue :" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Vitesse de l’animation : %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Vol pour les moniteurs sélectionnés" },
        LocalizedText{ TXT_ENABLE_ALL, L"Tout activer" },
        LocalizedText{ TXT_DISABLE_ALL, L"Tout désactiver" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Moniteur d’animation" },
        LocalizedText{ TXT_MONITOR, L"Moniteur" },
        LocalizedText{ TXT_RESOLUTION, L"Résolution" },
        LocalizedText{ TXT_POSITION, L"Position" },
        LocalizedText{ TXT_PRIMARY, L"principal" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Annuler" },
        LocalizedText{ TXT_START_RECORDING, L"Démarrer l’enregistrement…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Arrêter l’enregistrement" },
        LocalizedText{ TXT_PAUSE, L"Pause" },
        LocalizedText{ TXT_RESUME, L"Reprendre" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Installer l’économiseur" },
        LocalizedText{ TXT_EXIT, L"Quitter" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"L’animation est en cours…" },
        LocalizedText{ TXT_RECORDING, L"Enregistrement MP4 en cours…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"L’enregistrement a été sauvegardé." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Impossible de démarrer l’enregistrement MP4." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"L’économiseur n’a pas été installé." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"L’économiseur a été installé." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Impossible d’initialiser le moteur Direct3D." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Vol entre quatre surfaces déformables" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Vol dans un entonnoir déformable" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"La fermeture de l’application arrêtera l’enregistrement en cours."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Visiter le site web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Impossible d’ouvrir le site dans le navigateur par défaut."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Impossible de copier l’URL dans le presse-papiers." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Impossible de copier les informations dans le presse-papiers."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Activer l’aperçu" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Désactiver l’aperçu" },
        LocalizedText{ TXT_PAUSED_STATUS, L"L’animation est en pause." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Bloquer l’écran de veille pendant l’animation" },
        LocalizedText{ TXT_READY_STATUS, L"Prêt." },
        LocalizedText{ TXT_HELP, L"Aide" },
        LocalizedText{ TXT_ABOUT, L"À propos" },
        LocalizedText{ TXT_CLOSE, L"Fermer" },
        LocalizedText{ TXT_SNAPSHOT, L"Capture…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"La capture a été enregistrée." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Impossible d’enregistrer la capture." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Désinstaller l’économiseur" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"L’économiseur a été désinstallé." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Impossible de désinstaller l’économiseur. S’il est en cours d’exécution ou si son aperçu est "
            L"ouvert, fermez-le puis réessayez."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"La désinstallation a échoué car les paramètres de FlightCorridor sont ouverts. Fermez cette "
            L"fenêtre puis réessayez."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"La désinstallation a échoué car l’aperçu système est actif. Fermez la fenêtre Paramètres de "
            L"l’économiseur d’écran puis réessayez."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"La désinstallation a échoué car l’économiseur ou l’aperçu plein écran est actif. Quittez-le "
            L"avec Échap ou en déplaçant la souris, puis réessayez."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Vol accéléré par le matériel dans un couloir et un entonnoir déformables."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Version :" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Plateforme cible :" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Site web :" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Ouvrir dans le navigateur par défaut" },
        LocalizedText{ TXT_COPY_URL, L"Copier l’&URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copier les &informations" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Éclairage principal" },
        LocalizedText{ TXT_FILL_LIGHT, L"Éclairage d’appoint" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Éclairage ambiant" },
        LocalizedText{ TXT_RIM_LIGHT, L"Éclairage des contours" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Texture" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Rotation libre de la caméra" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauses et inversions" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"La ressource de licence est indisponible." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Modèle du moniteur" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Fréquence de rafraîchissement" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Profondeur de bits" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Format de couleur" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Espace colorimétrique" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bits/canal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bits/pixel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Réglages vidéo" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Résolution :" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Fréquence d’images :" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Les modifications s’appliquent au prochain enregistrement MP4."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMATION ET PARAMÈTRES\r\nFlightCorridor: Vol entre quatre surfaces déformables; Vol dans un "
            L"entonnoir déformable. Attribuez une seule animation à chaque écran. Texture alterne entre "
            L"surfaces texturées et modèle filaire. La rotation libre de la caméra change lentement la "
            L"direction du regard dans les trois dimensions. L’option « Pauses et inversions » ajoute des "
            L"ralentissements, pauses et inversions aléatoires de la rotation ; le vol vers l’avant "
            L"continue. La vitesse va de 0 à 1600 %. Chaque écran possède une scène aléatoire indépendante, "
            L"rendue à sa propre fréquence de rafraîchissement. La lumière principale, la lumière d’appoint, "
            L"l’éclairage ambiant et l’éclairage des contours se règlent indépendamment pour les écrans "
            L"sélectionnés. L’éclairage ne concerne que les surfaces texturées.\r\n\r\nÉCRANS\r\nLa "
            L"sélection des lignes détermine les écrans à configurer ; elle est distincte des cases qui "
            L"activent les sorties d’animation. Ctrl+A sélectionne tous les écrans ; Ctrl et Maj modifient "
            L"la sélection. Toutes les options et tous les curseurs d’animation concernent les écrans "
            L"sélectionnés. La sélection est mémorisée séparément pour EXE et SCR. Si tous les écrans "
            L"étaient sélectionnés, les nouveaux le sont également. Des valeurs différentes entre les écrans "
            L"sélectionnés sont indiquées par des cases à cocher indéterminées et des pointillés sur les "
            L"boutons radio, les poignées des curseurs et les boutons « Tout activer » et « Tout désactiver "
            L"». Les libellés des curseurs affichent un tiret au lieu d’une valeur commune. Modifier une "
            L"option ou cliquer sur un curseur applique cette valeur à tous les écrans sélectionnés.\r\n\r\n"
            L"COMMANDES\r\nActivez ou désactivez les sorties d’animation avec les cases des écrans ou en "
            L"double-cliquant sur leurs lignes. Chaque moniteur utilise une scène indépendante. Capture "
            L"enregistre un PNG et le bouton d’enregistrement démarre ou arrête un MP4. Pause arrête "
            L"l’animation. L’application installe ou désinstalle aussi son économiseur intégré. Les réglages "
            L"sont enregistrés en continu. Une seule instance de l’application peut fonctionner à la fois. "
            L"Un nouveau lancement restaure la fenêtre de contrôle réduite et la place au premier plan. "
            L"Utilisez Tab et Maj+Tab pour passer d’un contrôle à l’autre ; Alt et la lettre soulignée "
            L"activent une commande. Échap ferme la fenêtre d’aide ou À propos active ; dans la fenêtre de "
            L"contrôle, cette touche quitte l’application. La pause et le blocage de l’écran de veille "
            L"s’appliquent à toute l’application, indépendamment des écrans sélectionnés. Lorsque le blocage "
            L"est activé, l’écran de veille Windows est empêché uniquement tant qu’une animation visible et "
            L"non suspendue s’affiche sur au moins un écran.\r\n\r\nCAPTURES ET ENREGISTREMENT\r\nLes "
            L"captures et les enregistrements utilisent le premier moniteur d’animation actif, et non une "
            L"image combinant tous les moniteurs. PNG utilise Images, MP4 Vidéos ; Documents sert de repli "
            L"si ces dossiers n’existent pas. Le bouton Réglages vidéo permet de choisir Viewport ou TV. "
            L"Viewport conserve les dimensions et la fréquence de rafraîchissement du moniteur d’animation, "
            L"jusqu’à 60 images par seconde. TV propose 1920 × 1080, 1440 × 1080 ou 1280 × 720 au format "
            L"16:9, à 50, 25, 59.94 (60000/1001) ou 29.97 (30000/1001) images par seconde. Le rapport "
            L"d’aspect est conservé ; TV utilise une vidéo progressive BT.709 à plage limitée et "
            L"sous-échantillonnage 4:2:0. La résolution et la fréquence d’images ne sont disponibles qu’en "
            L"mode TV. La fenêtre Réglages vidéo peut être réduite et ne bloque pas les autres fenêtres de "
            L"l’application. OK enregistre les choix pour le prochain enregistrement MP4 ; Annuler ou Échap "
            L"abandonne les modifications non confirmées. La sortie d’animation du moniteur enregistré ne "
            L"peut pas être désactivée pendant l’enregistrement ; les changements concernant les autres "
            L"moniteurs ne l’arrêtent pas. Fermer l’application pendant un enregistrement nécessite une "
            L"confirmation, car cela arrête aussi l’enregistrement.\r\n\r\nCONFIGURATION REQUISE\r\nWindows "
            L"7 à Windows 11 prennent en charge toutes les fonctions, y compris les captures PNG et "
            L"l’enregistrement MP4. Pour exécuter l’application sous Windows Vista SP2, il est nécessaire "
            L"d’installer les mises à jour KB971512 et KB2117917. L’enregistrement MP4 ne fonctionne pas "
            L"sous Vista dans la version actuelle. L’affichage nécessite Direct3D 11, et pas seulement un "
            L"ancien environnement d’exécution DirectX. L’enregistrement MP4 nécessite les composants Media "
            L"Foundation et un encodeur H.264 disponibles."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATION ET PARAMÈTRES\r\nFlightCorridor: Vol entre quatre surfaces déformables; Vol dans un "
            L"entonnoir déformable. Attribuez une seule animation à chaque écran. Texture alterne entre "
            L"surfaces texturées et modèle filaire. La rotation libre de la caméra change lentement la "
            L"direction du regard dans les trois dimensions. L’option « Pauses et inversions » ajoute des "
            L"ralentissements, pauses et inversions aléatoires de la rotation ; le vol vers l’avant "
            L"continue. La vitesse va de 0 à 1600 %. Chaque écran possède une scène aléatoire indépendante, "
            L"rendue à sa propre fréquence de rafraîchissement. La lumière principale, la lumière d’appoint, "
            L"l’éclairage ambiant et l’éclairage des contours se règlent indépendamment pour les écrans "
            L"sélectionnés. L’éclairage ne concerne que les surfaces texturées.\r\n\r\nÉCRANS\r\nLa "
            L"sélection des lignes détermine les écrans à configurer ; elle est distincte des cases qui "
            L"activent les sorties d’animation. Ctrl+A sélectionne tous les écrans ; Ctrl et Maj modifient "
            L"la sélection. Toutes les options et tous les curseurs d’animation concernent les écrans "
            L"sélectionnés. La sélection est mémorisée séparément pour EXE et SCR. Si tous les écrans "
            L"étaient sélectionnés, les nouveaux le sont également. Des valeurs différentes entre les écrans "
            L"sélectionnés sont indiquées par des cases à cocher indéterminées et des pointillés sur les "
            L"boutons radio, les poignées des curseurs et les boutons « Tout activer » et « Tout désactiver "
            L"». Les libellés des curseurs affichent un tiret au lieu d’une valeur commune. Modifier une "
            L"option ou cliquer sur un curseur applique cette valeur à tous les écrans sélectionnés.\r\n\r\n"
            L"APERÇU ET COMMANDES\r\nActiver l’aperçu lance un aperçu plein écran sur tous les moniteurs ; "
            L"la boîte de dialogue reste ouverte pour les réglages en direct. OK enregistre les réglages, "
            L"Annuler les abandonne. Échap ou un mouvement de souris quitte le plein écran. Utilisez Tab et "
            L"Maj+Tab pour passer d’un contrôle à l’autre ; Alt et la lettre soulignée activent une "
            L"commande. Échap dans les réglages équivaut à Annuler ; dans l’aide ou À propos, cette touche "
            L"ferme uniquement cette fenêtre.\r\n\r\nCONFIGURATION REQUISE\r\nWindows 7 à Windows 11 sont "
            L"pris en charge. Pour exécuter l’application sous Windows Vista SP2, il est nécessaire "
            L"d’installer les mises à jour KB971512 et KB2117917. L’affichage nécessite Direct3D 11, et pas "
            L"seulement un ancien environnement d’exécution DirectX."
        },
    }),
    DefineLanguage(LANG_ES, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Español" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Control" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Configuración de FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Idioma:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Velocidad de animación: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Vuelo en los monitores seleccionados" },
        LocalizedText{ TXT_ENABLE_ALL, L"Activar todo" },
        LocalizedText{ TXT_DISABLE_ALL, L"Desactivar todo" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Monitor de animación" },
        LocalizedText{ TXT_MONITOR, L"Monitor" },
        LocalizedText{ TXT_RESOLUTION, L"Resolución" },
        LocalizedText{ TXT_POSITION, L"Posición" },
        LocalizedText{ TXT_PRIMARY, L"principal" },
        LocalizedText{ TXT_OK, L"Aceptar" },
        LocalizedText{ TXT_CANCEL, L"Cancelar" },
        LocalizedText{ TXT_START_RECORDING, L"Iniciar grabación…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Detener grabación" },
        LocalizedText{ TXT_PAUSE, L"Pausar" },
        LocalizedText{ TXT_RESUME, L"Continuar" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Instalar salvapantallas" },
        LocalizedText{ TXT_EXIT, L"Salir" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"La animación está activa…" },
        LocalizedText{ TXT_RECORDING, L"Grabando MP4…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"La grabación se guardó." },
        LocalizedText{ TXT_RECORDING_FAILED, L"No se pudo iniciar la grabación MP4." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"No se instaló el salvapantallas." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"El salvapantallas se instaló." },
        LocalizedText{ TXT_RENDERER_FAILED, L"No se pudo inicializar Direct3D." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Vuelo entre cuatro superficies deformables" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Vuelo por un embudo deformable" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Al cerrar la aplicación se detendrá la grabación en curso."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Visitar el sitio web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"No se puede abrir el sitio en el navegador predeterminado."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"No se pudo copiar la URL al portapapeles." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"No se pudo copiar la información al portapapeles."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Activar vista previa" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Desactivar vista previa" },
        LocalizedText{ TXT_PAUSED_STATUS, L"La animación está en pausa." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Bloquear salvapantallas durante la animación" },
        LocalizedText{ TXT_READY_STATUS, L"Listo." },
        LocalizedText{ TXT_HELP, L"Ayuda" },
        LocalizedText{ TXT_ABOUT, L"Acerca de" },
        LocalizedText{ TXT_CLOSE, L"Cerrar" },
        LocalizedText{ TXT_SNAPSHOT, L"Captura…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"La captura se guardó." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"No se pudo guardar la captura." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Desinstalar salvapantallas" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"El salvapantallas se desinstaló." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"No se pudo desinstalar el salvapantallas. Si el salvapantallas o su vista previa están en "
            L"ejecución, ciérrelos e inténtelo de nuevo."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"La desinstalación falló porque la configuración de FlightCorridor está abierta. Cierre esa "
            L"ventana e inténtelo de nuevo."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"La desinstalación falló porque se está ejecutando la vista previa del sistema. Cierre "
            L"Configuración del protector de pantalla e inténtelo de nuevo."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"La desinstalación falló porque está activo el salvapantallas o la vista previa a pantalla "
            L"completa. Salga con Esc o moviendo el ratón e inténtelo de nuevo."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Vuelo acelerado por hardware por un corredor y un embudo deformables."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versión:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Plataforma de destino:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Sitio web:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Abrir en el navegador predeterminado" },
        LocalizedText{ TXT_COPY_URL, L"Copiar &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copiar &información" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Luz principal" },
        LocalizedText{ TXT_FILL_LIGHT, L"Luz de relleno" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Luz ambiental" },
        LocalizedText{ TXT_RIM_LIGHT, L"Iluminación de contornos" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Textura" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Giro libre de la cámara" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pausas e inversiones" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"El recurso de licencia no está disponible." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Modelo del monitor" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Frecuencia de actualización" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Profundidad de bits" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Formato de color" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Espacio de color" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bits/canal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bits/píxel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Ajustes de grabación" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Resolución:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Frecuencia de imagen:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Los cambios se aplican a la próxima grabación MP4." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMACIÓN Y AJUSTES\r\nFlightCorridor: Vuelo entre cuatro superficies deformables; Vuelo por "
            L"un embudo deformable. Asigne una sola animación a cada pantalla. Textura alterna entre "
            L"superficies texturizadas y modelo de alambre. El giro libre de la cámara cambia lentamente la "
            L"dirección de la vista en las tres dimensiones. La opción «Pausas e inversiones» añade "
            L"frenadas, pausas e inversiones aleatorias del giro; el vuelo hacia delante continúa. La "
            L"velocidad va del 0 al 1600 %. Cada pantalla tiene una escena aleatoria independiente y se "
            L"renderiza a su propia frecuencia de actualización. La luz principal, la luz de relleno, la luz "
            L"ambiental y la iluminación de contornos se activan por separado para las pantallas "
            L"seleccionadas. La iluminación solo se aplica a las superficies texturizadas.\r\n\r\nMONITORES\r"
            L"\nLa selección de filas determina qué pantallas se están configurando; es independiente de las "
            L"casillas que activan las salidas de animación. Ctrl+A selecciona todas; Ctrl y Mayús modifican "
            L"la selección. Todas las opciones y los controles deslizantes de animación se aplican a las "
            L"pantallas seleccionadas. La selección se recuerda por separado para EXE y SCR. Si estaban "
            L"seleccionadas todas, se incluyen también las nuevas. Los valores distintos entre las pantallas "
            L"seleccionadas se indican mediante casillas indeterminadas y un punteado en los botones de "
            L"opción, los tiradores de los controles deslizantes y los botones «Activar todo» y «Desactivar "
            L"todo». Las etiquetas de los controles deslizantes muestran una raya en lugar de un valor "
            L"común. Cambiar una opción o hacer clic en un control deslizante aplica ese valor a todas las "
            L"pantallas seleccionadas.\r\n\r\nCONTROLES\r\nActive o desactive las salidas de animación "
            L"mediante las casillas de las pantallas o haciendo doble clic en sus filas. Cada monitor usa "
            L"una escena independiente. Captura guarda un PNG y el botón de grabación inicia o detiene un "
            L"MP4. Pausar detiene la animación. La aplicación instala o desinstala además el salvapantallas "
            L"incorporado. Los ajustes se guardan continuamente. La aplicación solo permite una instancia. "
            L"Al volver a iniciarla, restaura la ventana de control minimizada y la trae al primer plano. "
            L"Use Tab y Mayús+Tab para desplazarse entre controles; Alt y la letra subrayada activan una "
            L"opción. Esc cierra la ventana activa de Ayuda o Acerca de; en la ventana de control, sale de "
            L"la aplicación. La pausa y el bloqueo del salvapantallas se aplican a toda la aplicación, "
            L"independientemente de las pantallas seleccionadas. Si el bloqueo está activado, solo se impide "
            L"el salvapantallas de Windows mientras haya animación visible y no pausada en al menos una "
            L"pantalla.\r\n\r\nCAPTURAS Y GRABACIÓN\r\nLas capturas y grabaciones usan el primer monitor de "
            L"animación activo, no una imagen conjunta de todos los monitores. PNG usa Imágenes y MP4 "
            L"Vídeos; si no existen esas carpetas, se usa Documentos. El botón Ajustes de grabación permite "
            L"elegir Viewport o TV. Viewport conserva las dimensiones y la frecuencia de actualización del "
            L"monitor de animación, hasta 60 fotogramas por segundo. TV ofrece 1920 × 1080, 1440 × 1080 o "
            L"1280 × 720 en formato 16:9, a 50, 25, 59.94 (60000/1001) o 29.97 (30000/1001) fotogramas por "
            L"segundo. Se conserva la relación de aspecto; TV usa vídeo progresivo BT.709 de rango limitado "
            L"y submuestreo 4:2:0. La resolución y la frecuencia solo están disponibles en modo TV. La "
            L"ventana Ajustes de grabación se puede minimizar y no bloquea las demás ventanas de la "
            L"aplicación. Aceptar guarda las opciones para la próxima grabación MP4; Cancelar o Esc descarta "
            L"los cambios sin confirmar. La salida de animación del monitor grabado no se puede desactivar "
            L"durante la grabación; cambiar otros monitores no la detiene. Cerrar la aplicación durante una "
            L"grabación requiere confirmación porque también detiene la grabación.\r\n\r\nREQUISITOS DEL "
            L"SISTEMA\r\nWindows 7 a Windows 11 admiten todas las funciones, incluidas las capturas PNG y la "
            L"grabación MP4. Para ejecutar la aplicación en Windows Vista SP2, es necesario instalar las "
            L"actualizaciones KB971512 y KB2117917. La grabación MP4 no funciona en Vista en la versión "
            L"actual. La representación requiere Direct3D 11, no solo un entorno de ejecución antiguo de "
            L"DirectX. La grabación MP4 requiere componentes de Media Foundation y un codificador H.264 "
            L"disponibles."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACIÓN Y AJUSTES\r\nFlightCorridor: Vuelo entre cuatro superficies deformables; Vuelo por "
            L"un embudo deformable. Asigne una sola animación a cada pantalla. Textura alterna entre "
            L"superficies texturizadas y modelo de alambre. El giro libre de la cámara cambia lentamente la "
            L"dirección de la vista en las tres dimensiones. La opción «Pausas e inversiones» añade "
            L"frenadas, pausas e inversiones aleatorias del giro; el vuelo hacia delante continúa. La "
            L"velocidad va del 0 al 1600 %. Cada pantalla tiene una escena aleatoria independiente y se "
            L"renderiza a su propia frecuencia de actualización. La luz principal, la luz de relleno, la luz "
            L"ambiental y la iluminación de contornos se activan por separado para las pantallas "
            L"seleccionadas. La iluminación solo se aplica a las superficies texturizadas.\r\n\r\nMONITORES\r"
            L"\nLa selección de filas determina qué pantallas se están configurando; es independiente de las "
            L"casillas que activan las salidas de animación. Ctrl+A selecciona todas; Ctrl y Mayús modifican "
            L"la selección. Todas las opciones y los controles deslizantes de animación se aplican a las "
            L"pantallas seleccionadas. La selección se recuerda por separado para EXE y SCR. Si estaban "
            L"seleccionadas todas, se incluyen también las nuevas. Los valores distintos entre las pantallas "
            L"seleccionadas se indican mediante casillas indeterminadas y un punteado en los botones de "
            L"opción, los tiradores de los controles deslizantes y los botones «Activar todo» y «Desactivar "
            L"todo». Las etiquetas de los controles deslizantes muestran una raya en lugar de un valor "
            L"común. Cambiar una opción o hacer clic en un control deslizante aplica ese valor a todas las "
            L"pantallas seleccionadas.\r\n\r\nVISTA PREVIA Y CONTROLES\r\nActivar vista previa inicia una "
            L"vista previa a pantalla completa en todos los monitores; el cuadro de configuración permanece "
            L"abierto para realizar ajustes en tiempo real. Aceptar guarda y Cancelar descarta. Esc o mover "
            L"el ratón cierra el salvapantallas completo. Use Tab y Mayús+Tab para desplazarse entre "
            L"controles; Alt y la letra subrayada activan una opción. Esc en la configuración equivale a "
            L"Cancelar; en Ayuda o Acerca de, cierra únicamente esa ventana.\r\n\r\nREQUISITOS DEL SISTEMA\r"
            L"\nSe admiten Windows 7 a Windows 11. Para ejecutar la aplicación en Windows Vista SP2, es "
            L"necesario instalar las actualizaciones KB971512 y KB2117917. La representación requiere "
            L"Direct3D 11, no solo un entorno de ejecución antiguo de DirectX."
        },
    }),
    DefineLanguage(LANG_IT, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Italiano" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Controlli" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Impostazioni di FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Lingua:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Velocità animazione: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Volo per i monitor selezionati" },
        LocalizedText{ TXT_ENABLE_ALL, L"Attiva tutto" },
        LocalizedText{ TXT_DISABLE_ALL, L"Disattiva tutto" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Monitor animazione" },
        LocalizedText{ TXT_MONITOR, L"Monitor" },
        LocalizedText{ TXT_RESOLUTION, L"Risoluzione" },
        LocalizedText{ TXT_POSITION, L"Posizione" },
        LocalizedText{ TXT_PRIMARY, L"principale" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Annulla" },
        LocalizedText{ TXT_START_RECORDING, L"Avvia registrazione…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Ferma registrazione" },
        LocalizedText{ TXT_PAUSE, L"Pausa" },
        LocalizedText{ TXT_RESUME, L"Riprendi" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Installa salvaschermo" },
        LocalizedText{ TXT_EXIT, L"Esci" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animazione in esecuzione…" },
        LocalizedText{ TXT_RECORDING, L"Registrazione MP4 in corso…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Registrazione salvata." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Impossibile avviare la registrazione MP4." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Il salvaschermo non è stato installato." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Il salvaschermo è stato installato." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Impossibile inizializzare Direct3D." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Volo tra quattro superfici deformabili" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Volo attraverso un imbuto deformabile" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"La chiusura dell’applicazione interromperà la registrazione in corso."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Visita il sito web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Impossibile aprire il sito nel browser predefinito." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Impossibile copiare l’URL negli Appunti." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Impossibile copiare le informazioni negli Appunti."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Attiva anteprima" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Disattiva anteprima" },
        LocalizedText{ TXT_PAUSED_STATUS, L"L’animazione è in pausa." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blocca salvaschermo durante l’animazione" },
        LocalizedText{ TXT_READY_STATUS, L"Pronto." },
        LocalizedText{ TXT_HELP, L"Guida" },
        LocalizedText{ TXT_ABOUT, L"Informazioni" },
        LocalizedText{ TXT_CLOSE, L"Chiudi" },
        LocalizedText{ TXT_SNAPSHOT, L"Istantanea…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"L’istantanea è stata salvata." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Impossibile salvare l’istantanea." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Disinstalla salvaschermo" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Il salvaschermo è stato disinstallato." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Impossibile disinstallare il salvaschermo. Se il salvaschermo o la relativa anteprima sono in "
            L"esecuzione, chiuderli e riprovare."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"La disinstallazione non è riuscita perché le impostazioni di FlightCorridor sono aperte. "
            L"Chiudere la finestra e riprovare."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"La disinstallazione non è riuscita perché è attiva l’anteprima di sistema. Chiudere "
            L"Impostazioni salvaschermo e riprovare."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"La disinstallazione non è riuscita perché è attivo il salvaschermo o l’anteprima a schermo "
            L"intero. Uscire con Esc o muovendo il mouse e riprovare."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Volo con accelerazione hardware attraverso un corridoio e un imbuto deformabili."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versione:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Piattaforma di destinazione:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Sito web:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Apri nel browser predefinito" },
        LocalizedText{ TXT_COPY_URL, L"Copia &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copia &informazioni" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Luce principale" },
        LocalizedText{ TXT_FILL_LIGHT, L"Luce di riempimento" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Luce ambientale" },
        LocalizedText{ TXT_RIM_LIGHT, L"Illuminazione dei contorni" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Texture" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Rotazione libera della telecamera" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pause e inversioni" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"La risorsa della licenza non è disponibile." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Modello del monitor" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Frequenza di aggiornamento" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Profondità di bit" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Formato colore" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Spazio colore" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bit/canale" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bit/pixel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Impostazioni video" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Risoluzione:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Frequenza fotogrammi:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Le modifiche si applicano alla prossima registrazione MP4."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMAZIONE E IMPOSTAZIONI\r\nFlightCorridor: Volo tra quattro superfici deformabili; Volo "
            L"attraverso un imbuto deformabile. Assegnare una sola animazione a ogni schermo. Texture "
            L"alterna superfici con texture e modello a reticolo. La rotazione libera della telecamera "
            L"cambia lentamente la direzione dello sguardo nelle tre dimensioni. L’opzione «Pause e "
            L"inversioni» aggiunge rallentamenti, pause e inversioni casuali della rotazione; il volo in "
            L"avanti continua. La velocità va da 0 a 1600%. Ogni schermo ha una scena casuale indipendente, "
            L"renderizzata alla propria frequenza di aggiornamento. La luce principale, la luce di "
            L"riempimento, la luce ambientale e l’illuminazione dei contorni si attivano separatamente per "
            L"gli schermi selezionati. L’illuminazione si applica solo alle superfici con texture.\r\n\r\n"
            L"MONITOR\r\nLa selezione delle righe determina quali schermi si stanno configurando ed è "
            L"distinta dalle caselle che attivano le uscite di animazione. Ctrl+A seleziona tutti gli "
            L"schermi; Ctrl e Maiusc modificano la selezione. Tutte le opzioni e i cursori dell’animazione "
            L"riguardano gli schermi selezionati. La selezione viene memorizzata separatamente per EXE e "
            L"SCR. Se erano selezionati tutti gli schermi, vengono inclusi anche quelli nuovi. Valori "
            L"diversi tra gli schermi selezionati sono indicati da caselle di controllo indeterminate e da "
            L"una trama a punti sui pulsanti di opzione, sulle maniglie dei cursori e sui pulsanti «Attiva "
            L"tutto» e «Disattiva tutto». Le etichette dei cursori mostrano un trattino al posto di un "
            L"valore comune. Modificare un’opzione o fare clic su un cursore applica quel valore a tutti gli "
            L"schermi selezionati.\r\n\r\nCOMANDI\r\nAttivare o disattivare le uscite di animazione con le "
            L"caselle degli schermi o facendo doppio clic sulle rispettive righe. Ogni monitor usa una scena "
            L"indipendente. Istantanea salva un PNG e il pulsante di registrazione avvia o arresta un MP4. "
            L"Pausa ferma l’animazione. L’applicazione installa o disinstalla anche il salvaschermo "
            L"incorporato. Le impostazioni vengono salvate continuamente. L’applicazione può essere eseguita "
            L"in una sola istanza. Un nuovo avvio ripristina la finestra di controllo ridotta a icona e la "
            L"porta in primo piano. Usare Tab e Maiusc+Tab per passare tra i controlli; Alt e la lettera "
            L"sottolineata attivano un comando. Esc chiude la finestra attiva di Guida o Informazioni; nella "
            L"finestra di controllo, termina l’applicazione. La pausa e il blocco del salvaschermo si "
            L"applicano all’intera applicazione, indipendentemente dagli schermi selezionati. Quando il "
            L"blocco è attivo, il salvaschermo di Windows viene impedito solo finché almeno uno schermo "
            L"mostra un’animazione visibile e non in pausa.\r\n\r\nISTANTANEE E REGISTRAZIONE\r\nIstantanee "
            L"e registrazioni usano il primo monitor di animazione attivo, non un’immagine combinata di "
            L"tutti i monitor. PNG usa Immagini, MP4 Video; se tali cartelle non esistono, viene usata "
            L"Documenti. Il pulsante Impostazioni video permette di scegliere Viewport o TV. Viewport "
            L"mantiene le dimensioni e la frequenza di aggiornamento del monitor di animazione, fino a 60 "
            L"fotogrammi al secondo. TV offre 1920 × 1080, 1440 × 1080 o 1280 × 720 in formato 16:9, a 50, "
            L"25, 59.94 (60000/1001) o 29.97 (30000/1001) fotogrammi al secondo. Le proporzioni sono "
            L"mantenute; TV usa video progressivo BT.709 con intervallo limitato e campionamento 4:2:0. "
            L"Risoluzione e frequenza sono disponibili solo in modalità TV. La finestra Impostazioni video "
            L"può essere ridotta a icona e non blocca le altre finestre dell’applicazione. OK salva le "
            L"opzioni per la prossima registrazione MP4; Annulla o Esc scarta le modifiche non confermate. "
            L"L’uscita di animazione del monitor registrato non può essere disattivata durante la "
            L"registrazione; le modifiche agli altri monitor non la interrompono. Chiudere l’applicazione "
            L"durante una registrazione richiede conferma, perché interrompe anche la registrazione.\r\n\r\n"
            L"REQUISITI DI SISTEMA\r\nI sistemi da Windows 7 a Windows 11 supportano tutte le funzioni, "
            L"comprese le istantanee PNG e la registrazione MP4. Per eseguire l’applicazione su Windows "
            L"Vista SP2, è necessario installare gli aggiornamenti KB971512 e KB2117917. La registrazione "
            L"MP4 non funziona in Vista nella versione attuale. La visualizzazione richiede Direct3D 11, non "
            L"soltanto un vecchio runtime DirectX. La registrazione MP4 richiede componenti Media Foundation "
            L"e un codificatore H.264 disponibili."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMAZIONE E IMPOSTAZIONI\r\nFlightCorridor: Volo tra quattro superfici deformabili; Volo "
            L"attraverso un imbuto deformabile. Assegnare una sola animazione a ogni schermo. Texture "
            L"alterna superfici con texture e modello a reticolo. La rotazione libera della telecamera "
            L"cambia lentamente la direzione dello sguardo nelle tre dimensioni. L’opzione «Pause e "
            L"inversioni» aggiunge rallentamenti, pause e inversioni casuali della rotazione; il volo in "
            L"avanti continua. La velocità va da 0 a 1600%. Ogni schermo ha una scena casuale indipendente, "
            L"renderizzata alla propria frequenza di aggiornamento. La luce principale, la luce di "
            L"riempimento, la luce ambientale e l’illuminazione dei contorni si attivano separatamente per "
            L"gli schermi selezionati. L’illuminazione si applica solo alle superfici con texture.\r\n\r\n"
            L"MONITOR\r\nLa selezione delle righe determina quali schermi si stanno configurando ed è "
            L"distinta dalle caselle che attivano le uscite di animazione. Ctrl+A seleziona tutti gli "
            L"schermi; Ctrl e Maiusc modificano la selezione. Tutte le opzioni e i cursori dell’animazione "
            L"riguardano gli schermi selezionati. La selezione viene memorizzata separatamente per EXE e "
            L"SCR. Se erano selezionati tutti gli schermi, vengono inclusi anche quelli nuovi. Valori "
            L"diversi tra gli schermi selezionati sono indicati da caselle di controllo indeterminate e da "
            L"una trama a punti sui pulsanti di opzione, sulle maniglie dei cursori e sui pulsanti «Attiva "
            L"tutto» e «Disattiva tutto». Le etichette dei cursori mostrano un trattino al posto di un "
            L"valore comune. Modificare un’opzione o fare clic su un cursore applica quel valore a tutti gli "
            L"schermi selezionati.\r\n\r\nANTEPRIMA E COMANDI\r\nAttiva anteprima avvia un’anteprima a "
            L"schermo intero su tutti i monitor; le impostazioni rimangono aperte per le modifiche in tempo "
            L"reale. OK salva e Annulla scarta. Esc o il movimento del mouse chiude il salvaschermo a "
            L"schermo intero. Usare Tab e Maiusc+Tab per passare tra i controlli; Alt e la lettera "
            L"sottolineata attivano un comando. Esc nelle impostazioni equivale ad Annulla; nella Guida o "
            L"nelle Informazioni, chiude solo quella finestra.\r\n\r\nREQUISITI DI SISTEMA\r\nSono "
            L"supportati i sistemi da Windows 7 a Windows 11. Per eseguire l’applicazione su Windows Vista "
            L"SP2, è necessario installare gli aggiornamenti KB971512 e KB2117917. La visualizzazione "
            L"richiede Direct3D 11, non soltanto un vecchio runtime DirectX."
        },
    }),
    DefineLanguage(LANG_PT, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Português" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Controlo" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Definições do FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Idioma:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Velocidade da animação: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Voo nos monitores selecionados" },
        LocalizedText{ TXT_ENABLE_ALL, L"Ativar tudo" },
        LocalizedText{ TXT_DISABLE_ALL, L"Desativar tudo" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Monitor da animação" },
        LocalizedText{ TXT_MONITOR, L"Monitor" },
        LocalizedText{ TXT_RESOLUTION, L"Resolução" },
        LocalizedText{ TXT_POSITION, L"Posição" },
        LocalizedText{ TXT_PRIMARY, L"principal" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Cancelar" },
        LocalizedText{ TXT_START_RECORDING, L"Iniciar gravação…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Parar gravação" },
        LocalizedText{ TXT_PAUSE, L"Pausar" },
        LocalizedText{ TXT_RESUME, L"Continuar" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Instalar proteção de ecrã" },
        LocalizedText{ TXT_EXIT, L"Sair" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"A animação está em execução…" },
        LocalizedText{ TXT_RECORDING, L"Gravação MP4 em curso…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"A gravação foi guardada." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Não foi possível iniciar a gravação MP4." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"A proteção de ecrã não foi instalada." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"A proteção de ecrã foi instalada." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Não foi possível inicializar o Direct3D." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Voo entre quatro superfícies deformáveis" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Voo através de um funil deformável" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Fechar a aplicação irá terminar a gravação em curso." },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Visitar o site %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Não é possível abrir o sítio no navegador predefinido." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Não foi possível copiar o URL para a área de transferência."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Não foi possível copiar as informações para a área de transferência."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Ativar pré-visualização" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Desativar pré-visualização" },
        LocalizedText{ TXT_PAUSED_STATUS, L"A animação está em pausa." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Bloquear proteção de ecrã durante a animação" },
        LocalizedText{ TXT_READY_STATUS, L"Pronto." },
        LocalizedText{ TXT_HELP, L"Ajuda" },
        LocalizedText{ TXT_ABOUT, L"Acerca de" },
        LocalizedText{ TXT_CLOSE, L"Fechar" },
        LocalizedText{ TXT_SNAPSHOT, L"Captura…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"A captura foi guardada." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Não foi possível guardar a captura." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Desinstalar proteção de ecrã" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"A proteção de ecrã foi desinstalada." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Não foi possível desinstalar a proteção de ecrã. Se a proteção ou a pré-visualização estiver "
            L"em execução, feche-a e tente novamente."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"A desinstalação falhou porque as definições do FlightCorridor estão abertas. Feche a janela e "
            L"tente novamente."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"A desinstalação falhou porque a pré-visualização do sistema está em execução. Feche as "
            L"Definições da proteção de ecrã e tente novamente."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"A desinstalação falhou porque a proteção ou a pré-visualização em ecrã inteiro está em "
            L"execução. Saia com Esc ou movendo o rato e tente novamente."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Voo acelerado por hardware através de um corredor e de um funil deformáveis."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versão:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Plataforma de destino:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Site:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Abrir no navegador predefinido" },
        LocalizedText{ TXT_COPY_URL, L"Copiar &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copiar &informações" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Luz principal" },
        LocalizedText{ TXT_FILL_LIGHT, L"Luz de preenchimento" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Luz ambiente" },
        LocalizedText{ TXT_RIM_LIGHT, L"Iluminação dos contornos" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Textura" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Rotação livre da câmara" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pausas e inversões" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"O recurso da licença não está disponível." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Modelo do monitor" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Taxa de atualização" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Profundidade de bits" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Formato de cor" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Espaço de cor" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bits/canal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bits/píxel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Definições de gravação" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Resolução:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Frequência de imagens:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"As alterações aplicam-se à próxima gravação MP4." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMAÇÃO E DEFINIÇÕES\r\nFlightCorridor: Voo entre quatro superfícies deformáveis; Voo através "
            L"de um funil deformável. Atribua uma única animação a cada ecrã. Textura alterna entre "
            L"superfícies texturadas e modelo em arame. A rotação livre da câmara muda lentamente a direção "
            L"da vista nas três dimensões. A opção «Pausas e inversões» acrescenta desacelerações, pausas e "
            L"inversões aleatórias da rotação; o voo para a frente continua. A velocidade vai de 0 a 1600%. "
            L"Cada ecrã tem uma cena aleatória independente, apresentada à sua própria frequência de "
            L"atualização. A luz principal, a luz de preenchimento, a luz ambiente e a iluminação dos "
            L"contornos podem ser ativadas separadamente nos monitores selecionados. A iluminação aplica-se "
            L"apenas às superfícies com textura.\r\n\r\nMONITORES\r\nA seleção das linhas determina os ecrãs "
            L"a configurar e é independente das caixas que ativam as saídas de animação. Ctrl+A seleciona "
            L"todos os ecrãs; Ctrl e Shift alteram a seleção. Todas as opções e controlos deslizantes da "
            L"animação aplicam-se aos ecrãs selecionados. A seleção é guardada separadamente para EXE e SCR. "
            L"Se todos estavam selecionados, os novos ecrãs também são incluídos. Valores diferentes entre "
            L"os ecrãs selecionados são indicados por caixas de verificação indeterminadas e por um padrão "
            L"pontilhado nos botões de opção, nas pegas dos controlos deslizantes e nos botões «Ativar tudo» "
            L"e «Desativar tudo». As etiquetas dos controlos deslizantes apresentam um travessão em vez de "
            L"um valor comum. Alterar uma opção ou clicar num controlo deslizante aplica esse valor a todos "
            L"os ecrãs selecionados.\r\n\r\nCONTROLOS\r\nAtive ou desative as saídas de animação através das "
            L"caixas dos ecrãs ou com um duplo clique nas respetivas linhas. Cada monitor usa uma cena "
            L"independente. Captura guarda PNG e o botão de gravação inicia ou termina MP4. Pausa para a "
            L"animação. A aplicação também instala ou desinstala a proteção de ecrã incorporada. As "
            L"definições são guardadas continuamente. A aplicação só pode ter uma instância em execução. Um "
            L"novo arranque restaura a janela de controlo minimizada e coloca-a em primeiro plano. Use Tab e "
            L"Shift+Tab para passar entre controlos; Alt e a letra sublinhada ativam um comando. Esc fecha a "
            L"janela ativa de Ajuda ou Acerca de; na janela de controlo, termina a aplicação. A pausa e o "
            L"bloqueio da proteção de ecrã aplicam-se a toda a aplicação, independentemente dos ecrãs "
            L"selecionados. Com o bloqueio ativo, a proteção de ecrã do Windows só é impedida enquanto "
            L"existir animação visível e não pausada em pelo menos um ecrã.\r\n\r\nCAPTURAS E GRAVAÇÃO\r\nAs "
            L"capturas e gravações usam o primeiro monitor de animação ativo, não uma imagem conjunta de "
            L"todos os monitores. PNG usa Imagens, MP4 Vídeos; se essas pastas não existirem, usa-se "
            L"Documentos. O botão Definições de gravação permite escolher Viewport ou TV. Viewport conserva "
            L"as dimensões e a frequência de atualização do monitor de animação, até 60 fotogramas por "
            L"segundo. TV oferece 1920 × 1080, 1440 × 1080 ou 1280 × 720 no formato 16:9, a 50, 25, 59.94 "
            L"(60000/1001) ou 29.97 (30000/1001) fotogramas por segundo. A proporção da imagem é mantida; TV "
            L"usa vídeo progressivo BT.709 com intervalo limitado e amostragem 4:2:0. A resolução e a "
            L"frequência só estão disponíveis no modo TV. A janela Definições de gravação pode ser "
            L"minimizada e não bloqueia as outras janelas da aplicação. OK guarda as escolhas para a próxima "
            L"gravação MP4; Cancelar ou Esc descarta as alterações não confirmadas. A saída de animação do "
            L"monitor gravado não pode ser desativada durante a gravação; as alterações aos outros monitores "
            L"não a interrompem. Fechar a aplicação durante uma gravação exige confirmação, pois também "
            L"termina a gravação.\r\n\r\nREQUISITOS DO SISTEMA\r\nOs sistemas Windows 7 a Windows 11 "
            L"suportam todas as funcionalidades, incluindo capturas PNG e gravação MP4. Para executar a "
            L"aplicação no Windows Vista SP2, é necessário instalar as atualizações KB971512 e KB2117917. A "
            L"gravação MP4 não funciona no Vista na versão atual. A apresentação requer Direct3D 11, não "
            L"apenas um runtime DirectX mais antigo. A gravação MP4 requer componentes Media Foundation e um "
            L"codificador H.264 disponíveis."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMAÇÃO E DEFINIÇÕES\r\nFlightCorridor: Voo entre quatro superfícies deformáveis; Voo através "
            L"de um funil deformável. Atribua uma única animação a cada ecrã. Textura alterna entre "
            L"superfícies texturadas e modelo em arame. A rotação livre da câmara muda lentamente a direção "
            L"da vista nas três dimensões. A opção «Pausas e inversões» acrescenta desacelerações, pausas e "
            L"inversões aleatórias da rotação; o voo para a frente continua. A velocidade vai de 0 a 1600%. "
            L"Cada ecrã tem uma cena aleatória independente, apresentada à sua própria frequência de "
            L"atualização. A luz principal, a luz de preenchimento, a luz ambiente e a iluminação dos "
            L"contornos podem ser ativadas separadamente nos monitores selecionados. A iluminação aplica-se "
            L"apenas às superfícies com textura.\r\n\r\nMONITORES\r\nA seleção das linhas determina os ecrãs "
            L"a configurar e é independente das caixas que ativam as saídas de animação. Ctrl+A seleciona "
            L"todos os ecrãs; Ctrl e Shift alteram a seleção. Todas as opções e controlos deslizantes da "
            L"animação aplicam-se aos ecrãs selecionados. A seleção é guardada separadamente para EXE e SCR. "
            L"Se todos estavam selecionados, os novos ecrãs também são incluídos. Valores diferentes entre "
            L"os ecrãs selecionados são indicados por caixas de verificação indeterminadas e por um padrão "
            L"pontilhado nos botões de opção, nas pegas dos controlos deslizantes e nos botões «Ativar tudo» "
            L"e «Desativar tudo». As etiquetas dos controlos deslizantes apresentam um travessão em vez de "
            L"um valor comum. Alterar uma opção ou clicar num controlo deslizante aplica esse valor a todos "
            L"os ecrãs selecionados.\r\n\r\nPRÉ-VISUALIZAÇÃO E CONTROLOS\r\nAtivar pré-visualização inicia "
            L"uma pré-visualização em ecrã inteiro em todos os monitores e permite ajustes em tempo real. OK "
            L"guarda as definições e Cancelar descarta-as. Esc ou o movimento do rato termina a proteção em "
            L"ecrã inteiro. Use Tab e Shift+Tab para passar entre controlos; Alt e a letra sublinhada ativam "
            L"um comando. Esc nas definições equivale a Cancelar; na Ajuda ou em Acerca de, fecha apenas "
            L"essa janela.\r\n\r\nREQUISITOS DO SISTEMA\r\nSão suportados os sistemas Windows 7 a Windows "
            L"11. Para executar a aplicação no Windows Vista SP2, é necessário instalar as atualizações "
            L"KB971512 e KB2117917. A apresentação requer Direct3D 11, não apenas um runtime DirectX mais "
            L"antigo."
        },
    }),
    DefineLanguage(LANG_PL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Polski" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Sterowanie" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Ustawienia FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Język:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Prędkość animacji: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Przelot na wybranych monitorach" },
        LocalizedText{ TXT_ENABLE_ALL, L"Włącz wszystko" },
        LocalizedText{ TXT_DISABLE_ALL, L"Wyłącz wszystko" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Monitor animacji" },
        LocalizedText{ TXT_MONITOR, L"Monitor" },
        LocalizedText{ TXT_RESOLUTION, L"Rozdzielczość" },
        LocalizedText{ TXT_POSITION, L"Położenie" },
        LocalizedText{ TXT_PRIMARY, L"główny" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Anuluj" },
        LocalizedText{ TXT_START_RECORDING, L"Rozpocznij nagrywanie…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Zatrzymaj nagrywanie" },
        LocalizedText{ TXT_PAUSE, L"Wstrzymaj" },
        LocalizedText{ TXT_RESUME, L"Wznów" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Zainstaluj wygaszacz" },
        LocalizedText{ TXT_EXIT, L"Zakończ" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animacja działa…" },
        LocalizedText{ TXT_RECORDING, L"Trwa nagrywanie MP4…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Nagranie zapisano." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Nie udało się rozpocząć nagrywania MP4." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Wygaszacz nie został zainstalowany." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Wygaszacz został zainstalowany." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Nie udało się uruchomić renderera Direct3D." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Przelot między czterema zmiennymi powierzchniami" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Przelot przez zmienny lejek" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Zamknięcie aplikacji zakończy trwające nagrywanie." },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Odwiedź witrynę %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Nie można otworzyć witryny w domyślnej przeglądarce." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Nie można skopiować adresu URL do schowka." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Nie można skopiować informacji do schowka." },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Włącz podgląd" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Wyłącz podgląd" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animacja jest wstrzymana." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blokuj wygaszacz podczas animacji" },
        LocalizedText{ TXT_READY_STATUS, L"Gotowy." },
        LocalizedText{ TXT_HELP, L"Pomoc" },
        LocalizedText{ TXT_ABOUT, L"O programie" },
        LocalizedText{ TXT_CLOSE, L"Zamknij" },
        LocalizedText{ TXT_SNAPSHOT, L"Zrzut…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Zrzut został zapisany." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Nie udało się zapisać zrzutu." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Odinstaluj wygaszacz" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Wygaszacz został odinstalowany." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Nie udało się odinstalować wygaszacza. Jeśli wygaszacz lub jego podgląd jest uruchomiony, "
            L"zamknij go i spróbuj ponownie."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Odinstalowanie nie powiodło się, ponieważ ustawienia FlightCorridor są otwarte. Zamknij okno i "
            L"spróbuj ponownie."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Odinstalowanie nie powiodło się, ponieważ działa podgląd systemowy. Zamknij okno Ustawienia "
            L"wygaszacza ekranu i spróbuj ponownie."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Odinstalowanie nie powiodło się, ponieważ działa wygaszacz lub podgląd pełnoekranowy. Zakończ "
            L"go klawiszem Esc albo ruchem myszy i spróbuj ponownie."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Sprzętowo przyspieszany przelot przez zmienny korytarz i lejek."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Wersja:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Platforma docelowa:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Witryna:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Otwórz w domyślnej przeglądarce" },
        LocalizedText{ TXT_COPY_URL, L"Kopiuj &adres URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopiuj &informacje" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Światło główne" },
        LocalizedText{ TXT_FILL_LIGHT, L"Światło wypełniające" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Światło otoczenia" },
        LocalizedText{ TXT_RIM_LIGHT, L"Oświetlenie konturów" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Tekstura" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Swobodne obracanie kamery" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Przerwy i nawroty" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Zasób licencji jest niedostępny." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Model monitora" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Częstotliwość odświeżania" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Głębia bitowa" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Format koloru" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Przestrzeń barw" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bitów/kanał" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bitów/piksel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Ustawienia nagrywania" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Rozdzielczość:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Liczba klatek/s:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Zmiany dotyczą następnego nagrania MP4." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMACJA I USTAWIENIA\r\nFlightCorridor: Przelot między czterema zmiennymi powierzchniami; "
            L"Przelot przez zmienny lejek. Każdemu monitorowi przypisz dokładnie jedną animację. Tekstura "
            L"przełącza powierzchnie z teksturą i model szkieletowy. Swobodne obracanie kamery powoli "
            L"zmienia kierunek widoku we wszystkich trzech wymiarach. Przerwy i nawroty dodają losowe "
            L"zwalnianie, pauzy i odwracanie obrotu; lot do przodu trwa nadal. Prędkość wynosi 0–1600%. "
            L"Każdy monitor ma niezależną losową scenę wyświetlaną z własną częstotliwością odświeżania. "
            L"Światło główne, światło wypełniające, światło otoczenia i oświetlenie konturów można "
            L"przełączać niezależnie dla zaznaczonych monitorów. Oświetlenie dotyczy tylko powierzchni z "
            L"teksturą.\r\n\r\nMONITORY\r\nZaznaczenie wierszy określa konfigurowane monitory i jest "
            L"niezależne od pól wyboru włączających wyjścia animacji. Ctrl+A zaznacza wszystkie monitory; "
            L"Ctrl i Shift zmieniają zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą zaznaczonych "
            L"monitorów. Zaznaczenie jest zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były "
            L"wszystkie monitory, nowe również zostaną zaznaczone. Różne wartości na zaznaczonych monitorach "
            L"są sygnalizowane nieokreślonym stanem pól wyboru i kropkowaniem przycisków opcji, uchwytów "
            L"suwaków oraz przycisków „Włącz wszystko” i „Wyłącz wszystko”. Etykiety suwaków pokazują kreskę "
            L"zamiast wspólnej wartości. Zmiana opcji lub kliknięcie suwaka ustawia tę wartość na wszystkich "
            L"zaznaczonych monitorach.\r\n\r\nOBSŁUGA\r\nWyjścia animacji można włączać i wyłączać polami "
            L"wyboru przy monitorach lub podwójnym kliknięciem ich wierszy. Każdy monitor ma niezależną "
            L"scenę. Zrzut zapisuje PNG, a przycisk nagrywania rozpoczyna lub kończy MP4. Wstrzymaj "
            L"zatrzymuje animację. Aplikacja instaluje i odinstalowuje również wbudowany wygaszacz. "
            L"Ustawienia są zapisywane na bieżąco. Aplikacja działa tylko w jednej instancji. Kolejne "
            L"uruchomienie przywraca zminimalizowane okno sterowania i przenosi je na pierwszy plan. "
            L"Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera wywołują "
            L"polecenie. Esc zamyka aktywne okno Pomocy lub O programie; w oknie sterowania kończy działanie "
            L"aplikacji. Wstrzymanie i blokowanie wygaszacza dotyczą całej aplikacji, niezależnie od "
            L"zaznaczenia monitorów. Gdy blokowanie jest włączone, wygaszacz Windows jest powstrzymywany "
            L"tylko wtedy, gdy na co najmniej jednym monitorze jest widoczna niewstrzymana animacja.\r\n\r\n"
            L"ZRZUTY EKRANU I NAGRYWANIE\r\nZrzuty i nagrania obejmują pierwszy aktywny monitor animacji, a "
            L"nie wspólny obraz wszystkich monitorów. PNG używa folderu Obrazy, MP4 folderu Wideo; jeśli ich "
            L"nie ma, używane są Dokumenty. Przycisk Ustawienia nagrywania pozwala wybrać Viewport lub TV. "
            L"Viewport zachowuje rozmiar i częstotliwość odświeżania monitora animacji, do 60 klatek na "
            L"sekundę. TV oferuje 1920 × 1080, 1440 × 1080 lub 1280 × 720 w formacie 16:9, z 50, 25, 59.94 "
            L"(60000/1001) lub 29.97 (30000/1001) klatkami na sekundę. Proporcje obrazu są zachowane; TV "
            L"używa progresywnego obrazu BT.709 z ograniczonym zakresem i próbkowaniem 4:2:0. Rozdzielczość "
            L"i liczba klatek są dostępne tylko w trybie TV. Okno Ustawienia nagrywania można zminimalizować "
            L"i nie blokuje ono innych okien aplikacji. OK zapisuje wybór dla następnego nagrania MP4; "
            L"Anuluj lub Esc odrzuca niepotwierdzone zmiany. Podczas nagrywania nie można wyłączyć wyjścia "
            L"animacji nagrywanego monitora; zmiany pozostałych monitorów nie przerywają nagrania. "
            L"Zamknięcie aplikacji podczas nagrywania wymaga potwierdzenia, ponieważ kończy również "
            L"nagranie.\r\n\r\nWYMAGANIA SYSTEMOWE\r\nSystemy od Windows 7 do Windows 11 obsługują wszystkie "
            L"funkcje, w tym zrzuty PNG i nagrywanie MP4. Do uruchomienia aplikacji w systemie Windows Vista "
            L"SP2 konieczne jest zainstalowanie aktualizacji KB971512 i KB2117917. Nagrywanie MP4 nie działa "
            L"w Vista w obecnej wersji. Wyświetlanie wymaga Direct3D 11, a nie tylko starszego środowiska "
            L"DirectX. Nagrywanie MP4 wymaga dostępnych składników Media Foundation i kodera H.264."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACJA I USTAWIENIA\r\nFlightCorridor: Przelot między czterema zmiennymi powierzchniami; "
            L"Przelot przez zmienny lejek. Każdemu monitorowi przypisz dokładnie jedną animację. Tekstura "
            L"przełącza powierzchnie z teksturą i model szkieletowy. Swobodne obracanie kamery powoli "
            L"zmienia kierunek widoku we wszystkich trzech wymiarach. Przerwy i nawroty dodają losowe "
            L"zwalnianie, pauzy i odwracanie obrotu; lot do przodu trwa nadal. Prędkość wynosi 0–1600%. "
            L"Każdy monitor ma niezależną losową scenę wyświetlaną z własną częstotliwością odświeżania. "
            L"Światło główne, światło wypełniające, światło otoczenia i oświetlenie konturów można "
            L"przełączać niezależnie dla zaznaczonych monitorów. Oświetlenie dotyczy tylko powierzchni z "
            L"teksturą.\r\n\r\nMONITORY\r\nZaznaczenie wierszy określa konfigurowane monitory i jest "
            L"niezależne od pól wyboru włączających wyjścia animacji. Ctrl+A zaznacza wszystkie monitory; "
            L"Ctrl i Shift zmieniają zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą zaznaczonych "
            L"monitorów. Zaznaczenie jest zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były "
            L"wszystkie monitory, nowe również zostaną zaznaczone. Różne wartości na zaznaczonych monitorach "
            L"są sygnalizowane nieokreślonym stanem pól wyboru i kropkowaniem przycisków opcji, uchwytów "
            L"suwaków oraz przycisków „Włącz wszystko” i „Wyłącz wszystko”. Etykiety suwaków pokazują kreskę "
            L"zamiast wspólnej wartości. Zmiana opcji lub kliknięcie suwaka ustawia tę wartość na wszystkich "
            L"zaznaczonych monitorach.\r\n\r\nPODGLĄD I OBSŁUGA\r\nWłącz podgląd uruchamia podgląd "
            L"pełnoekranowy na wszystkich monitorach. Okno ustawień pozostaje otwarte, umożliwiając zmiany "
            L"na bieżąco. OK zapisuje ustawienia, a Anuluj je odrzuca. Esc lub ruch myszy kończy tryb "
            L"pełnoekranowy. Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona "
            L"litera wywołują polecenie. Esc w ustawieniach odpowiada przyciskowi Anuluj; w Pomocy lub O "
            L"programie zamyka tylko to okno.\r\n\r\nWYMAGANIA SYSTEMOWE\r\nObsługiwane są systemy od "
            L"Windows 7 do Windows 11. Do uruchomienia aplikacji w systemie Windows Vista SP2 konieczne jest "
            L"zainstalowanie aktualizacji KB971512 i KB2117917. Wyświetlanie wymaga Direct3D 11, a nie tylko "
            L"starszego środowiska DirectX."
        },
    }),
    DefineLanguage(LANG_SK, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Slovenčina" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Ovládanie" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Nastavenia FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Jazyk:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Rýchlosť animácie: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Prelet na vybraných monitoroch" },
        LocalizedText{ TXT_ENABLE_ALL, L"Všetko zapnúť" },
        LocalizedText{ TXT_DISABLE_ALL, L"Všetko vypnúť" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Monitor animácie" },
        LocalizedText{ TXT_MONITOR, L"Monitor" },
        LocalizedText{ TXT_RESOLUTION, L"Rozlíšenie" },
        LocalizedText{ TXT_POSITION, L"Poloha" },
        LocalizedText{ TXT_PRIMARY, L"hlavný" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Zrušiť" },
        LocalizedText{ TXT_START_RECORDING, L"Spustiť záznam…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Ukončiť záznam" },
        LocalizedText{ TXT_PAUSE, L"Pozastaviť" },
        LocalizedText{ TXT_RESUME, L"Pokračovať" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Nainštalovať šetrič" },
        LocalizedText{ TXT_EXIT, L"Koniec" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animácia beží…" },
        LocalizedText{ TXT_RECORDING, L"Prebieha záznam MP4…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Záznam bol uložený." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Záznam MP4 sa nepodarilo spustiť." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Šetrič nebol nainštalovaný." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Šetrič bol nainštalovaný." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Renderer Direct3D sa nepodarilo inicializovať." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Prelet medzi štyrmi premenlivými plochami" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Prelet premenlivým lievikom" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Ukončenie aplikácie ukončí práve prebiehajúci záznam."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Navštíviť web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Web nemožno otvoriť v predvolenom prehliadači." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Adresu URL nemožno skopírovať do schránky." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Informácie nemožno skopírovať do schránky." },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Zapnúť náhľad" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Vypnúť náhľad" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animácia je pozastavená." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blokovať šetrič pri animácii" },
        LocalizedText{ TXT_READY_STATUS, L"Pripravený." },
        LocalizedText{ TXT_HELP, L"Pomoc" },
        LocalizedText{ TXT_ABOUT, L"O aplikácii" },
        LocalizedText{ TXT_CLOSE, L"Zavrieť" },
        LocalizedText{ TXT_SNAPSHOT, L"Snímka…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Snímka bola uložená." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Snímku sa nepodarilo uložiť." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Odinštalovať šetrič" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Šetrič bol odinštalovaný." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Šetrič sa nepodarilo odinštalovať. Ak je šetrič alebo jeho náhľad spustený, zatvorte ho a "
            L"skúste to znova."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Odinštalovanie zlyhalo, pretože sú otvorené nastavenia FlightCorridor. Zatvorte ich a skúste "
            L"to znova."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Odinštalovanie zlyhalo, pretože beží systémový náhľad. Zatvorte okno Nastavenie šetriča "
            L"obrazovky a skúste to znova."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Odinštalovanie zlyhalo, pretože beží šetrič alebo celoobrazovkový náhľad. Ukončite ho klávesom "
            L"Esc alebo pohybom myši a skúste to znova."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Hardvérovo akcelerovaný prelet premenlivým koridorom a lievikom."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Verzia:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Cieľová platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Web:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Otvoriť v predvolenom prehliadači" },
        LocalizedText{ TXT_COPY_URL, L"Kopírovať &adresu" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopírovať &informácie" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Hlavné svetlo" },
        LocalizedText{ TXT_FILL_LIGHT, L"Doplnkové svetlo" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Základný jas" },
        LocalizedText{ TXT_RIM_LIGHT, L"Prisvetlenie obrysov" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Textúra" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Voľná rotácia kamery" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauzy a obraty" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Prostriedok s licenciou nie je k dispozícii." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Model monitora" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Obnovovacia frekvencia" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bitová hĺbka" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Formát farby" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Farebný priestor" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bitov/kanál" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bitov/pixel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Nastavenie záznamu" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Rozlíšenie:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Snímková frekvencia:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Zmeny sa použijú pri nasledujúcom zázname MP4." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMÁCIA A NASTAVENIA\r\nFlightCorridor: Prelet medzi štyrmi premenlivými plochami; Prelet "
            L"premenlivým lievikom. Každému monitoru priraďte práve jednu animáciu. Textúra prepína medzi "
            L"textúrovanými plochami a drôteným modelom. Voľná rotácia kamery pomaly mení smer pohľadu vo "
            L"všetkých troch rozmeroch. Voľba „Pauzy a obraty“ pridáva náhodné spomaľovanie, prestávky a "
            L"zmeny smeru otáčania; dopredný pohyb pokračuje. Rýchlosť je 0–1600 %. Každý monitor má "
            L"nezávislú náhodnú scénu vykresľovanú podľa vlastnej obnovovacej frekvencie. Hlavné svetlo, "
            L"doplnkové svetlo, základný jas a prisvetlenie obrysov možno pre označené monitory zapínať "
            L"nezávisle. Osvetlenie sa používa len pri textúrovaných plochách.\r\n\r\nMONITORY\r\nOznačenie "
            L"riadkov určuje, ktoré monitory práve nastavujete; je nezávislé od políčok zapínajúcich "
            L"animačné výstupy. Ctrl+A označí všetky monitory, Ctrl a Shift upravujú označenie. Všetky "
            L"animačné voľby a posuvníky platia pre označené monitory. Označenie sa pamätá zvlášť pre EXE a "
            L"SCR. Ak boli označené všetky monitory, označia sa aj novopripojené. Rozdielne hodnoty na "
            L"označených monitoroch ukazuje neurčitý stav políčok a bodkovanie prepínačov, úchytov "
            L"posuvníkov a tlačidiel „Všetko zapnúť“ a „Všetko vypnúť“. Popis posuvníka namiesto spoločnej "
            L"hodnoty zobrazuje pomlčku. Zmena voľby alebo kliknutie na posuvník zjednotí príslušnú hodnotu "
            L"na označených monitoroch.\r\n\r\nOVLÁDANIE\r\nAnimačné výstupy zapnete alebo vypnete políčkami "
            L"pri monitoroch alebo dvojklikom na ich riadky. Každý monitor používa nezávislú scénu. Snímka "
            L"uloží PNG a tlačidlo záznamu spustí alebo ukončí MP4. Pozastavenie zastaví animáciu. Aplikácia "
            L"tiež nainštaluje alebo odinštaluje vložený šetrič. Nastavenia sa ukladajú priebežne. Aplikácia "
            L"beží iba v jednej inštancii. Ďalšie spustenie obnoví minimalizované ovládacie okno a prenesie "
            L"ho do popredia. Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté "
            L"voľby vyvoláte pomocou Alt a príslušného písmena. Esc zavrie aktívne okno Pomoc alebo O "
            L"aplikácii; v ovládacom okne ukončí aplikáciu. Pozastavenie a blokovanie šetriča platia pre "
            L"celú aplikáciu bez ohľadu na označené monitory. Ak je blokovanie zapnuté, bráni spusteniu "
            L"šetriča Windows iba vtedy, keď je aspoň na jednom monitore viditeľná nepozastavená animácia.\r"
            L"\n\r\nSNÍMKY A ZÁZNAM\r\nSnímky a záznamy zachytávajú prvý aktívny animačný monitor, nie "
            L"spoločnú plochu všetkých monitorov. PNG používa Obrázky, MP4 Videá; ak tieto priečinky "
            L"neexistujú, použijú sa Dokumenty. Tlačidlo Nastavenie záznamu vyberá Viewport alebo TV. "
            L"Viewport zachováva rozmery animačného monitora a jeho obnovovaciu frekvenciu, najviac 60 "
            L"snímok za sekundu. TV ponúka rozlíšenie 1920 × 1080, 1440 × 1080 alebo 1280 × 720 v pomere "
            L"16:9 a frekvenciu 50, 25, 59.94 (60000/1001) alebo 29.97 (30000/1001) snímok za sekundu. Obraz "
            L"zachováva pomer strán; TV používa progresívne video BT.709 s obmedzeným rozsahom a vzorkovaním "
            L"4:2:0. Rozlíšenie a snímkovú frekvenciu možno vybrať iba v režime TV. Okno Nastavenie záznamu "
            L"možno minimalizovať a neblokuje ostatné okná aplikácie. OK uloží voľby pre nasledujúci záznam "
            L"MP4; Zrušiť alebo Esc zahodí nepotvrdené zmeny. Animačný výstup nahrávaného monitora nemožno "
            L"počas záznamu vypnúť; zmeny ostatných monitorov záznam nezastavia. Ukončenie aplikácie počas "
            L"záznamu vyžaduje potvrdenie, pretože ukončí aj záznam.\r\n\r\nSYSTÉMOVÉ POŽIADAVKY\r\nWindows "
            L"7 až Windows 11 podporujú všetky funkcie vrátane snímok PNG a záznamu MP4. Na spustenie "
            L"aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať aktualizácie KB971512 a "
            L"KB2117917. Záznam MP4 na Viste v súčasnej verzii nefunguje. Vykresľovanie vyžaduje Direct3D "
            L"11, nie iba starší DirectX runtime. Záznam MP4 vyžaduje dostupné súčasti Media Foundation a "
            L"kodér H.264."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMÁCIA A NASTAVENIA\r\nFlightCorridor: Prelet medzi štyrmi premenlivými plochami; Prelet "
            L"premenlivým lievikom. Každému monitoru priraďte práve jednu animáciu. Textúra prepína medzi "
            L"textúrovanými plochami a drôteným modelom. Voľná rotácia kamery pomaly mení smer pohľadu vo "
            L"všetkých troch rozmeroch. Voľba „Pauzy a obraty“ pridáva náhodné spomaľovanie, prestávky a "
            L"zmeny smeru otáčania; dopredný pohyb pokračuje. Rýchlosť je 0–1600 %. Každý monitor má "
            L"nezávislú náhodnú scénu vykresľovanú podľa vlastnej obnovovacej frekvencie. Hlavné svetlo, "
            L"doplnkové svetlo, základný jas a prisvetlenie obrysov možno pre označené monitory zapínať "
            L"nezávisle. Osvetlenie sa používa len pri textúrovaných plochách.\r\n\r\nMONITORY\r\nOznačenie "
            L"riadkov určuje, ktoré monitory práve nastavujete; je nezávislé od políčok zapínajúcich "
            L"animačné výstupy. Ctrl+A označí všetky monitory, Ctrl a Shift upravujú označenie. Všetky "
            L"animačné voľby a posuvníky platia pre označené monitory. Označenie sa pamätá zvlášť pre EXE a "
            L"SCR. Ak boli označené všetky monitory, označia sa aj novopripojené. Rozdielne hodnoty na "
            L"označených monitoroch ukazuje neurčitý stav políčok a bodkovanie prepínačov, úchytov "
            L"posuvníkov a tlačidiel „Všetko zapnúť“ a „Všetko vypnúť“. Popis posuvníka namiesto spoločnej "
            L"hodnoty zobrazuje pomlčku. Zmena voľby alebo kliknutie na posuvník zjednotí príslušnú hodnotu "
            L"na označených monitoroch.\r\n\r\nNÁHĽAD A OVLÁDANIE\r\nZapnúť náhľad spustí celoobrazovkový "
            L"náhľad na všetkých monitoroch; nastavenia zostávajú otvorené a zmeny sa prejavia ihneď. OK "
            L"uloží nastavenia a Zrušiť ich zahodí. Celoobrazovkový šetrič ukončí Esc alebo pohyb myši. "
            L"Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte "
            L"pomocou Alt a príslušného písmena. Esc v nastaveniach zodpovedá tlačidlu Zrušiť; v okne Pomoc "
            L"alebo O aplikácii zavrie iba toto okno.\r\n\r\nSYSTÉMOVÉ POŽIADAVKY\r\nPodporované sú systémy "
            L"Windows 7 až Windows 11. Na spustenie aplikácie v systéme Windows Vista SP2 je potrebné "
            L"nainštalovať aktualizácie KB971512 a KB2117917. Vykresľovanie vyžaduje Direct3D 11, nie iba "
            L"starší DirectX runtime."
        },
    }),
    DefineLanguage(LANG_DA, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Dansk" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Styring" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Indstillinger for FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Sprog:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Animationshastighed: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Flyvetur for valgte skærme" },
        LocalizedText{ TXT_ENABLE_ALL, L"Aktivér alle" },
        LocalizedText{ TXT_DISABLE_ALL, L"Deaktivér alle" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Animationsskærm" },
        LocalizedText{ TXT_MONITOR, L"Skærm" },
        LocalizedText{ TXT_RESOLUTION, L"Opløsning" },
        LocalizedText{ TXT_POSITION, L"Placering" },
        LocalizedText{ TXT_PRIMARY, L"primær" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Annuller" },
        LocalizedText{ TXT_START_RECORDING, L"Start optagelse…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Stop optagelse" },
        LocalizedText{ TXT_PAUSE, L"Pause" },
        LocalizedText{ TXT_RESUME, L"Fortsæt" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Installer pauseskærm" },
        LocalizedText{ TXT_EXIT, L"Afslut" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animationen kører…" },
        LocalizedText{ TXT_RECORDING, L"MP4-optagelse i gang…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Optagelsen blev gemt." },
        LocalizedText{ TXT_RECORDING_FAILED, L"MP4-optagelsen kunne ikke startes." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Pauseskærmen blev ikke installeret." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Pauseskærmen blev installeret." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Direct3D kunne ikke initialiseres." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Flyvetur mellem fire formskiftende flader" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Flyvetur gennem en formskiftende tragt" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Hvis du lukker programmet, stoppes den igangværende optagelse."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Besøg webstedet %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Webstedet kan ikke åbnes i standardbrowseren." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL-adressen kunne ikke kopieres til udklipsholderen." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Oplysningerne kunne ikke kopieres til udklipsholderen."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Aktivér forhåndsvisning" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Deaktivér forhåndsvisning" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animationen er sat på pause." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blokér pauseskærm under animation" },
        LocalizedText{ TXT_READY_STATUS, L"Klar." },
        LocalizedText{ TXT_HELP, L"Hjælp" },
        LocalizedText{ TXT_ABOUT, L"Om" },
        LocalizedText{ TXT_CLOSE, L"Luk" },
        LocalizedText{ TXT_SNAPSHOT, L"Skærmbillede…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Skærmbilledet blev gemt." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Skærmbilledet kunne ikke gemmes." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Afinstaller pauseskærm" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Pauseskærmen blev afinstalleret." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Pauseskærmen kunne ikke afinstalleres. Hvis pauseskærmen eller forhåndsvisningen kører, skal "
            L"du lukke den og prøve igen."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Afinstallationen mislykkedes, fordi indstillingerne for FlightCorridor er åbne. Luk vinduet, "
            L"og prøv igen."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Afinstallationen mislykkedes, fordi systemforhåndsvisningen kører. Luk vinduet "
            L"Pauseskærmsindstillinger, og prøv igen."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Afinstallationen mislykkedes, fordi pauseskærmen eller forhåndsvisningen i fuld skærm kører. "
            L"Afslut med Esc eller ved at bevæge musen, og prøv igen."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Hardwareaccelereret flyvetur gennem en formskiftende korridor og tragt."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Version:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Målplatform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Websted:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Åbn i standardbrowseren" },
        LocalizedText{ TXT_COPY_URL, L"Kopiér &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopiér &oplysninger" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Hovedlys" },
        LocalizedText{ TXT_FILL_LIGHT, L"Udfyldningslys" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Omgivende lys" },
        LocalizedText{ TXT_RIM_LIGHT, L"Konturlys" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Tekstur" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Frit roterende kamera" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauser og vendinger" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Licensressourcen er ikke tilgængelig." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Skærmmodel" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Opdateringsfrekvens" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bitdybde" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Farveformat" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Farverum" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bit/kanal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bit/pixel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Optagelsesindstillinger" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Opløsning:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Billedfrekvens:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Ændringerne gælder næste MP4-optagelse." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMATION OG INDSTILLINGER\r\nFlightCorridor: Flyvetur mellem fire formskiftende flader; "
            L"Flyvetur gennem en formskiftende tragt. Tildel præcis én animation til hver skærm. Tekstur "
            L"skifter mellem teksturerede flader og trådmodel. Frit roterende kamera ændrer langsomt "
            L"synsretningen i alle tre dimensioner. Pauser og vendinger tilføjer tilfældige opbremsninger, "
            L"pauser og ændringer af rotationsretningen; flyvningen fremad fortsætter. Hastigheden er 0–1600 "
            L"%. Hver skærm har en uafhængig tilfældig scene, der gengives med dens egen "
            L"opdateringsfrekvens. Hovedlys, udfyldningslys, omgivende lys og konturlys kan slås til og fra "
            L"uafhængigt for de valgte skærme. Belysningen gælder kun teksturerede overflader.\r\n\r\n"
            L"SKÆRME\r\nMarkeringen af rækker bestemmer, hvilke skærme du indstiller, og er adskilt fra "
            L"afkrydsningsfelterne, der aktiverer animationsoutput. Ctrl+A markerer alle skærme; Ctrl og "
            L"Skift ændrer markeringen. Alle animationsvalg og skydere gælder de markerede skærme. "
            L"Markeringen huskes separat for EXE og SCR. Hvis alle skærme var markeret, medtages også nye "
            L"skærme. Forskellige værdier på de markerede skærme vises med ubestemte afkrydsningsfelter og "
            L"prikmønstre på alternativknapper, skydergreb og knapperne “Aktivér alle” og “Deaktivér alle”. "
            L"Skydernes etiketter viser en tankestreg i stedet for en fælles værdi. Ændring af et valg eller "
            L"klik på en skyder anvender denne værdi på alle markerede skærme.\r\n\r\nBETJENING\r\nSlå "
            L"animationsoutput til eller fra med skærmenes afkrydsningsfelter eller ved at dobbeltklikke på "
            L"deres rækker. Hver skærm bruger en uafhængig scene. Skærmbillede gemmer PNG, og optageknappen "
            L"starter eller stopper MP4. Pause standser animationen. Programmet installerer eller "
            L"afinstallerer også den indbyggede pauseskærm. Indstillinger gemmes løbende. Programmet kan kun "
            L"køre i én instans ad gangen. En ny start gendanner det minimerede kontrolvindue og bringer det "
            L"forrest. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det understregede "
            L"bogstav aktiverer en kommando. Esc lukker det aktive Hjælp- eller Om-vindue; i kontrolvinduet "
            L"afslutter det programmet. Pause og blokering af pauseskærmen gælder hele programmet uanset "
            L"skærmmarkeringen. Når blokering er slået til, forhindres Windows-pauseskærmen kun, mens der "
            L"vises en synlig animation, som ikke er sat på pause, på mindst én skærm.\r\n\r\nSKÆRMBILLEDER "
            L"OG OPTAGELSE\r\nSkærmbilleder og optagelser bruger den første aktive animationsskærm, ikke et "
            L"samlet billede af alle skærme. PNG bruger Billeder, MP4 Videoer; hvis disse mapper ikke "
            L"findes, bruges Dokumenter. Knappen Optagelsesindstillinger vælger Viewport eller TV. Viewport "
            L"bevarer animationsskærmens størrelse og opdateringsfrekvens, højst 60 billeder i sekundet. TV "
            L"tilbyder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9 med 50, 25, 59.94 "
            L"(60000/1001) eller 29.97 (30000/1001) billeder i sekundet. Billedets proportioner bevares; TV "
            L"bruger progressiv BT.709-video med begrænset område og 4:2:0-sampling. Opløsning og "
            L"billedfrekvens kan kun vælges i TV-tilstand. Vinduet Optagelsesindstillinger kan minimeres og "
            L"blokerer ikke de andre programvinduer. OK gemmer valgene til den næste MP4-optagelse; Annuller "
            L"eller Esc kasserer ubekræftede ændringer. Animationsoutputtet på den skærm, der optages, kan "
            L"ikke slås fra under optagelsen; ændringer af andre skærme stopper ikke optagelsen. Hvis "
            L"programmet lukkes under en optagelse, kræves en bekræftelse, fordi optagelsen også afsluttes.\r"
            L"\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 understøtter alle funktioner, herunder "
            L"PNG-skærmbilleder og MP4-optagelse. For at køre programmet på Windows Vista SP2 skal "
            L"opdateringerne KB971512 og KB2117917 installeres. MP4-optagelse fungerer ikke på Vista i den "
            L"aktuelle version. Visningen kræver Direct3D 11, ikke kun et ældre DirectX-kørselsmiljø. "
            L"MP4-optagelse kræver tilgængelige Media Foundation-komponenter og en H.264-koder."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATION OG INDSTILLINGER\r\nFlightCorridor: Flyvetur mellem fire formskiftende flader; "
            L"Flyvetur gennem en formskiftende tragt. Tildel præcis én animation til hver skærm. Tekstur "
            L"skifter mellem teksturerede flader og trådmodel. Frit roterende kamera ændrer langsomt "
            L"synsretningen i alle tre dimensioner. Pauser og vendinger tilføjer tilfældige opbremsninger, "
            L"pauser og ændringer af rotationsretningen; flyvningen fremad fortsætter. Hastigheden er 0–1600 "
            L"%. Hver skærm har en uafhængig tilfældig scene, der gengives med dens egen "
            L"opdateringsfrekvens. Hovedlys, udfyldningslys, omgivende lys og konturlys kan slås til og fra "
            L"uafhængigt for de valgte skærme. Belysningen gælder kun teksturerede overflader.\r\n\r\n"
            L"SKÆRME\r\nMarkeringen af rækker bestemmer, hvilke skærme du indstiller, og er adskilt fra "
            L"afkrydsningsfelterne, der aktiverer animationsoutput. Ctrl+A markerer alle skærme; Ctrl og "
            L"Skift ændrer markeringen. Alle animationsvalg og skydere gælder de markerede skærme. "
            L"Markeringen huskes separat for EXE og SCR. Hvis alle skærme var markeret, medtages også nye "
            L"skærme. Forskellige værdier på de markerede skærme vises med ubestemte afkrydsningsfelter og "
            L"prikmønstre på alternativknapper, skydergreb og knapperne “Aktivér alle” og “Deaktivér alle”. "
            L"Skydernes etiketter viser en tankestreg i stedet for en fælles værdi. Ændring af et valg eller "
            L"klik på en skyder anvender denne værdi på alle markerede skærme.\r\n\r\nFORHÅNDSVISNING OG "
            L"BETJENING\r\nAktivér forhåndsvisning starter en fuldskærmsvisning på alle skærme. "
            L"Indstillingerne forbliver åbne, og ændringerne vises med det samme. OK gemmer indstillingerne, "
            L"og Annuller forkaster ændringerne. Esc eller musebevægelse afslutter fuldskærmen. Brug Tab og "
            L"Skift+Tab til at flytte mellem kontrollerne; Alt og det understregede bogstav aktiverer en "
            L"kommando. Esc i indstillingerne svarer til Annuller; i Hjælp eller Om lukker det kun dette "
            L"vindue.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 understøttes. For at køre programmet på "
            L"Windows Vista SP2 skal opdateringerne KB971512 og KB2117917 installeres. Visningen kræver "
            L"Direct3D 11, ikke kun et ældre DirectX-kørselsmiljø."
        },
    }),
    DefineLanguage(LANG_FI, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Suomi" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Ohjaus" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlightCorridor-asetukset" },
        LocalizedText{ TXT_LANGUAGE, L"Kieli:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Animaation nopeus: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Lento valituilla näytöillä" },
        LocalizedText{ TXT_ENABLE_ALL, L"Ota kaikki käyttöön" },
        LocalizedText{ TXT_DISABLE_ALL, L"Poista kaikki käytöstä" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Animaation näyttö" },
        LocalizedText{ TXT_MONITOR, L"Näyttö" },
        LocalizedText{ TXT_RESOLUTION, L"Tarkkuus" },
        LocalizedText{ TXT_POSITION, L"Sijainti" },
        LocalizedText{ TXT_PRIMARY, L"ensisijainen" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Peruuta" },
        LocalizedText{ TXT_START_RECORDING, L"Aloita tallennus…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Lopeta tallennus" },
        LocalizedText{ TXT_PAUSE, L"Keskeytä" },
        LocalizedText{ TXT_RESUME, L"Jatka" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Asenna näytönsäästäjä" },
        LocalizedText{ TXT_EXIT, L"Lopeta" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animaatio on käynnissä…" },
        LocalizedText{ TXT_RECORDING, L"MP4-tallennus käynnissä…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Tallenne tallennettiin." },
        LocalizedText{ TXT_RECORDING_FAILED, L"MP4-tallennusta ei voitu aloittaa." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Näytönsäästäjää ei asennettu." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Näytönsäästäjä asennettiin." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Direct3D-renderöintiä ei voitu alustaa." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Lento neljän muuntuvan pinnan välissä" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Lento muuntuvan suppilon läpi" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Sovelluksen sulkeminen lopettaa käynnissä olevan tallennuksen."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Käy verkkosivustolla %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Sivustoa ei voi avata oletusselaimessa." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL-osoitetta ei voitu kopioida leikepöydälle." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Tietoja ei voitu kopioida leikepöydälle." },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Ota esikatselu käyttöön" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Poista esikatselu käytöstä" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animaatio on keskeytetty." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Estä näytönsäästäjä animaation aikana" },
        LocalizedText{ TXT_READY_STATUS, L"Valmis." },
        LocalizedText{ TXT_HELP, L"Ohje" },
        LocalizedText{ TXT_ABOUT, L"Tietoja" },
        LocalizedText{ TXT_CLOSE, L"Sulje" },
        LocalizedText{ TXT_SNAPSHOT, L"Tilannekuva…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Tilannekuva tallennettiin." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Tilannekuvaa ei voitu tallentaa." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Poista näytönsäästäjä" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Näytönsäästäjä poistettiin." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Näytönsäästäjän poistaminen epäonnistui. Jos näytönsäästäjä tai sen esikatselu on käynnissä, "
            L"sulje se ja yritä uudelleen."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Asennuksen poisto epäonnistui, koska FlightCorridor-asetukset ovat avoinna. Sulje ikkuna ja "
            L"yritä uudelleen."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Asennuksen poisto epäonnistui, koska järjestelmän esikatselu on käynnissä. Sulje "
            L"Näytönsäästäjän asetukset ja yritä uudelleen."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Asennuksen poisto epäonnistui, koska näytönsäästäjä tai koko näytön esikatselu on käynnissä. "
            L"Lopeta Esc-näppäimellä tai liikuttamalla hiirtä ja yritä uudelleen."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Laitteistokiihdytetty lento muuntuvan käytävän ja suppilon läpi."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versio:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Kohdealusta:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Verkkosivusto:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Avaa oletusselaimessa" },
        LocalizedText{ TXT_COPY_URL, L"Kopioi &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopioi &tiedot" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Päävalo" },
        LocalizedText{ TXT_FILL_LIGHT, L"Täytevalo" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ympäristövalo" },
        LocalizedText{ TXT_RIM_LIGHT, L"Reunavalo" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Tekstuuri" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Kameran vapaa pyörintä" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Tauot ja suunnanvaihdot" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Lisenssiresurssi ei ole käytettävissä." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Näytön malli" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Virkistystaajuus" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bittisyvyys" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Värimuoto" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Väriavaruus" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bittiä/kanava" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bittiä/pikseli" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Tallennusasetukset" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Tarkkuus:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Kuvataajuus:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Muutokset koskevat seuraavaa MP4-tallennusta." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMAATIO JA ASETUKSET\r\nFlightCorridor: Lento neljän muuntuvan pinnan välissä; Lento "
            L"muuntuvan suppilon läpi. Valitse kullekin näytölle yksi animaatio. Tekstuuri vaihtaa "
            L"teksturoitujen pintojen ja rautalankamallin välillä. Kameran vapaa pyörintä muuttaa "
            L"katselusuuntaa hitaasti kaikissa kolmessa ulottuvuudessa. Tauot ja suunnanvaihdot lisäävät "
            L"satunnaisia hidastuksia, taukoja ja pyörimissuunnan vaihtoja; lento eteenpäin jatkuu. Nopeus "
            L"on 0–1600%. Jokaisella näytöllä on itsenäinen satunnainen näkymä, joka piirretään sen omalla "
            L"virkistystaajuudella. Päävalo, täytevalo, ympäristövalo ja reunavalo voidaan kytkeä erikseen "
            L"valituille näytöille. Valaistus koskee vain teksturoituja pintoja.\r\n\r\nNÄYTÖT\r\nRivien "
            L"valinta määrää muokattavat näytöt ja on erillinen animaatioulostulon valintaruuduista. Ctrl+A "
            L"valitsee kaikki näytöt; Ctrl ja Vaihto muuttavat valintaa. Kaikki animaatioasetukset ja "
            L"liukusäätimet koskevat valittuja näyttöjä. Valinta muistetaan erikseen EXE- ja SCR-tiloissa. "
            L"Jos kaikki näytöt olivat valittuina, myös uudet näytöt valitaan. Valittujen näyttöjen eri "
            L"arvot ilmaistaan valintaruutujen määrittämättömällä tilalla sekä valintanappien, "
            L"liukusäätimien kahvojen ja painikkeiden ”Ota kaikki käyttöön” ja ”Poista kaikki käytöstä” "
            L"pistekuviolla. Liukusäätimen selitteessä näkyy viiva yhteisen arvon sijasta. Asetuksen "
            L"muuttaminen tai liukusäätimen napsauttaminen asettaa kyseisen arvon kaikille valituille "
            L"näytöille.\r\n\r\nKÄYTTÖ\r\nAnimaatioulostulot voi ottaa käyttöön tai poistaa käytöstä "
            L"näyttöjen valintaruuduilla tai kaksoisnapsauttamalla niiden rivejä. Jokaisella näytöllä on "
            L"itsenäinen näkymä. Tilannekuva tallentaa PNG:n ja tallennuspainike käynnistää tai lopettaa "
            L"MP4:n. Keskeytä pysäyttää animaation. Sovellus asentaa tai poistaa myös sisäisen "
            L"näytönsäästäjän. Asetukset tallennetaan jatkuvasti. Sovelluksesta voi olla käynnissä vain yksi "
            L"instanssi. Uusi käynnistys palauttaa pienennetyn ohjausikkunan ja tuo sen etualalle. Siirry "
            L"säätimien välillä Tab- ja Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat "
            L"komennon. Esc sulkee aktiivisen Ohje- tai Tietoja-ikkunan; ohjausikkunassa se sulkee "
            L"sovelluksen. Keskeytys ja näytönsäästäjän esto koskevat koko sovellusta näytön valinnasta "
            L"riippumatta. Kun esto on käytössä, Windowsin näytönsäästäjä estetään vain, kun vähintään "
            L"yhdessä näytössä näkyy animaatio, jota ei ole keskeytetty.\r\n\r\nKUVAKAAPPAUKSET JA "
            L"TALLENNUS\r\nTilannekuvat ja tallenteet käyttävät ensimmäistä aktiivista animaationäyttöä, "
            L"eivät kaikkien näyttöjen yhdistettyä kuvaa. PNG käyttää Kuvat-kansiota ja MP4 Videot-kansiota; "
            L"jos niitä ei ole, käytetään Tiedostot-kansiota. Tallennusasetukset-painikkeella valitaan "
            L"Viewport tai TV. Viewport säilyttää animaationäytön koon ja virkistystaajuuden, enintään 60 "
            L"kuvaa sekunnissa. TV tarjoaa tarkkuudet 1920 × 1080, 1440 × 1080 ja 1280 × 720 kuvasuhteella "
            L"16:9 sekä taajuudet 50, 25, 59.94 (60000/1001) ja 29.97 (30000/1001) kuvaa sekunnissa. "
            L"Kuvasuhde säilyy; TV käyttää progressiivista BT.709-videota rajatulla alueella ja "
            L"4:2:0-näytteistyksellä. Tarkkuus ja kuvataajuus ovat valittavissa vain TV-tilassa. "
            L"Tallennusasetukset-ikkunan voi pienentää, eikä se estä muiden sovellusikkunoiden käyttöä. OK "
            L"tallentaa valinnat seuraavaa MP4-tallennusta varten; Peruuta tai Esc hylkää vahvistamattomat "
            L"muutokset. Tallennettavan näytön animaatioulostuloa ei voi poistaa käytöstä tallennuksen "
            L"aikana; muiden näyttöjen muutokset eivät pysäytä tallennusta. Sovelluksen sulkeminen "
            L"tallennuksen aikana vaatii vahvistuksen, sillä myös tallennus päättyy.\r\n\r\n"
            L"JÄRJESTELMÄVAATIMUKSET\r\nWindows 7–Windows 11 tukevat kaikkia toimintoja, myös "
            L"PNG-tilannekuvia ja MP4-tallennusta. Sovelluksen suorittaminen Windows Vista SP2:ssa "
            L"edellyttää päivitysten KB971512 ja KB2117917 asentamista. MP4-tallennus ei toimi Vistassa "
            L"nykyisessä versiossa. Näyttäminen vaatii Direct3D 11:n, ei pelkästään vanhempaa "
            L"DirectX-ajoympäristöä. MP4-tallennus vaatii käytettävissä olevat Media Foundation -komponentit "
            L"ja H.264-enkooderin."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMAATIO JA ASETUKSET\r\nFlightCorridor: Lento neljän muuntuvan pinnan välissä; Lento "
            L"muuntuvan suppilon läpi. Valitse kullekin näytölle yksi animaatio. Tekstuuri vaihtaa "
            L"teksturoitujen pintojen ja rautalankamallin välillä. Kameran vapaa pyörintä muuttaa "
            L"katselusuuntaa hitaasti kaikissa kolmessa ulottuvuudessa. Tauot ja suunnanvaihdot lisäävät "
            L"satunnaisia hidastuksia, taukoja ja pyörimissuunnan vaihtoja; lento eteenpäin jatkuu. Nopeus "
            L"on 0–1600%. Jokaisella näytöllä on itsenäinen satunnainen näkymä, joka piirretään sen omalla "
            L"virkistystaajuudella. Päävalo, täytevalo, ympäristövalo ja reunavalo voidaan kytkeä erikseen "
            L"valituille näytöille. Valaistus koskee vain teksturoituja pintoja.\r\n\r\nNÄYTÖT\r\nRivien "
            L"valinta määrää muokattavat näytöt ja on erillinen animaatioulostulon valintaruuduista. Ctrl+A "
            L"valitsee kaikki näytöt; Ctrl ja Vaihto muuttavat valintaa. Kaikki animaatioasetukset ja "
            L"liukusäätimet koskevat valittuja näyttöjä. Valinta muistetaan erikseen EXE- ja SCR-tiloissa. "
            L"Jos kaikki näytöt olivat valittuina, myös uudet näytöt valitaan. Valittujen näyttöjen eri "
            L"arvot ilmaistaan valintaruutujen määrittämättömällä tilalla sekä valintanappien, "
            L"liukusäätimien kahvojen ja painikkeiden ”Ota kaikki käyttöön” ja ”Poista kaikki käytöstä” "
            L"pistekuviolla. Liukusäätimen selitteessä näkyy viiva yhteisen arvon sijasta. Asetuksen "
            L"muuttaminen tai liukusäätimen napsauttaminen asettaa kyseisen arvon kaikille valituille "
            L"näytöille.\r\n\r\nESIKATSELU JA KÄYTTÖ\r\nOta esikatselu käyttöön käynnistää koko näytön "
            L"esikatselun kaikilla näytöillä. Asetusikkuna pysyy avoinna, ja muutokset näkyvät heti. OK "
            L"tallentaa asetukset ja Peruuta hylkää muutokset. Esc tai hiiren liike lopettaa koko näytön "
            L"säästäjän. Siirry säätimien välillä Tab- ja Vaihto+Tab-näppäimillä; Alt ja alleviivattu "
            L"kirjain aktivoivat komennon. Esc asetuksissa vastaa Peruuta-painiketta; Ohje- tai "
            L"Tietoja-ikkunassa se sulkee vain kyseisen ikkunan.\r\n\r\nJÄRJESTELMÄVAATIMUKSET\r\nTuettuja "
            L"käyttöjärjestelmiä ovat Windows 7–Windows 11. Sovelluksen suorittaminen Windows Vista SP2:ssa "
            L"edellyttää päivitysten KB971512 ja KB2117917 asentamista. Näyttäminen vaatii Direct3D 11:n, ei "
            L"pelkästään vanhempaa DirectX-ajoympäristöä."
        },
    }),
    DefineLanguage(LANG_IS, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Íslenska" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Stjórnun" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Stillingar FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Tungumál:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Hraði hreyfimyndar: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Flug fyrir valda skjái" },
        LocalizedText{ TXT_ENABLE_ALL, L"Virkja allt" },
        LocalizedText{ TXT_DISABLE_ALL, L"Óvirkja allt" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Hreyfimyndaskjár" },
        LocalizedText{ TXT_MONITOR, L"Skjár" },
        LocalizedText{ TXT_RESOLUTION, L"Upplausn" },
        LocalizedText{ TXT_POSITION, L"Staðsetning" },
        LocalizedText{ TXT_PRIMARY, L"aðal" },
        LocalizedText{ TXT_OK, L"Í lagi" },
        LocalizedText{ TXT_CANCEL, L"Hætta við" },
        LocalizedText{ TXT_START_RECORDING, L"Hefja upptöku…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Stöðva upptöku" },
        LocalizedText{ TXT_PAUSE, L"Gera hlé" },
        LocalizedText{ TXT_RESUME, L"Halda áfram" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Setja upp skjáhvílu" },
        LocalizedText{ TXT_EXIT, L"Hætta" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Hreyfimyndin er í gangi…" },
        LocalizedText{ TXT_RECORDING, L"MP4-upptaka í gangi…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Upptakan var vistuð." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Ekki tókst að hefja MP4-upptöku." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Skjáhvílan var ekki sett upp." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Skjáhvílan var sett upp." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Ekki tókst að ræsa Direct3D." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Flug milli fjögurra breytilegra flata" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Flug í gegnum breytilega trekt" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Ef forritinu er lokað stöðvast upptakan sem er í gangi."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Heimsækja vefsvæði %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Ekki er hægt að opna vefsvæðið í sjálfgefnum vafra." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Ekki tókst að afrita vefslóðina á klippispjaldið." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Ekki tókst að afrita upplýsingarnar á klippispjaldið."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Virkja forskoðun" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Slökkva á forskoðun" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Hlé hefur verið gert á hreyfimyndinni." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Hindra skjáhvílu meðan hreyfimynd er í gangi" },
        LocalizedText{ TXT_READY_STATUS, L"Tilbúið." },
        LocalizedText{ TXT_HELP, L"Hjálp" },
        LocalizedText{ TXT_ABOUT, L"Um" },
        LocalizedText{ TXT_CLOSE, L"Loka" },
        LocalizedText{ TXT_SNAPSHOT, L"Skjámynd…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Skjámyndin var vistuð." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Ekki tókst að vista skjámyndina." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Fjarlægja skjáhvílu" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Skjáhvílan var fjarlægð." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Ekki tókst að fjarlægja skjáhvíluna. Ef skjáhvílan eða forskoðun hennar er í gangi skaltu loka "
            L"henni og reyna aftur."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Fjarlæging mistókst vegna þess að stillingar FlightCorridor eru opnar. Lokaðu glugganum og "
            L"reyndu aftur."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Fjarlæging mistókst vegna þess að kerfisforskoðun er í gangi. Lokaðu stillingaglugga skjáhvílu "
            L"og reyndu aftur."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Fjarlæging mistókst vegna þess að skjáhvílan eða forskoðun á öllum skjánum er í gangi. Lokaðu "
            L"með Esc eða með því að hreyfa músina og reyndu aftur."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Vélbúnaðarhraðað flug um breytilegan gang og trekt." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Útgáfa:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Markvettvangur:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Vefsvæði:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Opna í sjálfgefnum vafra" },
        LocalizedText{ TXT_COPY_URL, L"Afrita &vefslóð" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Afrita &upplýsingar" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Aðalljós" },
        LocalizedText{ TXT_FILL_LIGHT, L"Fylliljós" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Umhverfislýsing" },
        LocalizedText{ TXT_RIM_LIGHT, L"Útlínulýsing" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Áferð" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Frjáls snúningur myndavélar" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Hlé og stefnuskipti" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Leyfistilfangið er ekki tiltækt." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Gerð skjás" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Endurnýjunartíðni" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bitadýpt" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Litasnið" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Litarými" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bitar/rás" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bitar/myndpunktur" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Upptökustillingar" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Upplausn:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Rammatíðni:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Breytingarnar gilda fyrir næstu MP4-upptöku." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"HREYFIMYND OG STILLINGAR\r\nFlightCorridor: Flug milli fjögurra breytilegra flata; Flug í "
            L"gegnum breytilega trekt. Veldu nákvæmlega eina hreyfimynd fyrir hvern skjá. Áferð skiptir "
            L"milli áferðarlagðra flata og víragrindar. Frjáls snúningur myndavélar breytir sjónstefnunni "
            L"hægt í öllum þremur víddum. Valkosturinn „Hlé og stefnuskipti“ bætir við tilviljanakenndri "
            L"hægingu, hléum og breytingum á snúningsstefnu; flug áfram heldur áfram. Hraðinn er 0–1600%. "
            L"Hver skjár hefur sjálfstæða tilviljanakennda senu sem er teiknuð á eigin endurnýjunartíðni. "
            L"Aðalljós, fylliljós, umhverfislýsing og útlínulýsing eru stillt óháð hvert öðru fyrir valda "
            L"skjái. Lýsingin á aðeins við um áferðarfleti.\r\n\r\nSKJÁIR\r\nVal lína ákvarðar hvaða skjám "
            L"er verið að breyta og er óháð gátreitunum sem kveikja á hreyfimyndaúttaki. Ctrl+A velur alla "
            L"skjái; Ctrl og Shift breyta valinu. Allir valkostir og sleðar hreyfimynda gilda fyrir valda "
            L"skjái. Valið er munað sérstaklega fyrir EXE og SCR. Ef allir skjáir voru valdir bætast nýir "
            L"skjáir einnig við valið. Mismunandi gildi á völdum skjám eru sýnd með óákveðnu ástandi "
            L"gátreita og punktamynstri á valhnöppum, handföngum sleða og hnöppunum „Virkja allt“ og "
            L"„Óvirkja allt“. Merking sleða sýnir strik í stað sameiginlegs gildis. Að breyta valkosti eða "
            L"smella á sleða setur það gildi á alla valda skjái.\r\n\r\nNOTKUN\r\nKveiktu eða slökktu á "
            L"hreyfimyndaúttaki með gátreitum skjáanna eða með því að tvísmella á línur þeirra. Hver skjár "
            L"notar sjálfstæða senu. Skjámynd vistar PNG og upptökuhnappurinn ræsir eða stöðvar MP4. "
            L"Hnappurinn Gera hlé stöðvar hreyfimyndina. Forritið setur einnig upp eða fjarlægir innbyggðu "
            L"skjáhvíluna. Stillingar vistast jafnóðum. Aðeins eitt eintak af forritinu getur verið í gangi "
            L"í einu. Ný ræsing endurheimtir lágmarkaða stjórngluggann og færir hann fremst. Notaðu Tab og "
            L"Shift+Tab til að færa þig milli stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc "
            L"lokar virka Hjálp- eða Um-glugganum; í stjórnglugganum lokar það forritinu. Pása og hindrun "
            L"skjáhvílu gilda fyrir allt forritið, óháð völdum skjám. Þegar hindrun er virk er skjáhvíla "
            L"Windows aðeins hindruð meðan sýnileg hreyfimynd sem er ekki í pásu er á að minnsta kosti einum "
            L"skjá.\r\n\r\nSKJÁMYNDIR OG UPPTAKA\r\nSkjámyndir og upptökur nota fyrsta virka "
            L"hreyfimyndaskjáinn, ekki sameinaða mynd af öllum skjám. PNG notar Myndir, MP4 Myndbönd; ef þær "
            L"möppur eru ekki til er Skjöl notuð. Hnappurinn Upptökustillingar velur Viewport eða TV. "
            L"Viewport varðveitir stærð og endurnýjunartíðni hreyfimyndaskjásins, þó mest 60 ramma á "
            L"sekúndu. TV býður upp á 1920 × 1080, 1440 × 1080 eða 1280 × 720 í hlutfallinu 16:9 með 50, 25, "
            L"59.94 (60000/1001) eða 29.97 (30000/1001) römmum á sekúndu. Hlutföll myndarinnar haldast; TV "
            L"notar BT.709-myndband án fléttunar (progressive) með takmörkuðu sviði og 4:2:0-sýnatöku. "
            L"Upplausn og rammatíðni eru aðeins valanleg í TV-ham. Hægt er að lágmarka gluggann "
            L"Upptökustillingar og hann hindrar ekki notkun annarra glugga forritsins. Í lagi vistar valið "
            L"fyrir næstu MP4-upptöku; Hætta við eða Esc hendir óstaðfestum breytingum. Ekki er hægt að "
            L"slökkva á hreyfimyndaúttaki skjásins sem er tekinn upp meðan upptaka stendur yfir; breytingar "
            L"á öðrum skjám stöðva ekki upptökuna. Staðfesta þarf lokun forritsins meðan upptaka stendur "
            L"yfir, því hún stöðvar líka upptökuna.\r\n\r\nKERFISKRÖFUR\r\nWindows 7 til Windows 11 styðja "
            L"alla eiginleika, þar á meðal PNG-skjámyndir og MP4-upptöku. Til að keyra forritið á Windows "
            L"Vista SP2 þarf að setja upp uppfærslurnar KB971512 og KB2117917. MP4-upptaka virkar ekki í "
            L"Vista í núverandi útgáfu. Birting krefst Direct3D 11, ekki aðeins eldri "
            L"DirectX-keyrsluumhverfis. MP4-upptaka krefst tiltækra Media Foundation-íhluta og H.264-kóðara."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"HREYFIMYND OG STILLINGAR\r\nFlightCorridor: Flug milli fjögurra breytilegra flata; Flug í "
            L"gegnum breytilega trekt. Veldu nákvæmlega eina hreyfimynd fyrir hvern skjá. Áferð skiptir "
            L"milli áferðarlagðra flata og víragrindar. Frjáls snúningur myndavélar breytir sjónstefnunni "
            L"hægt í öllum þremur víddum. Valkosturinn „Hlé og stefnuskipti“ bætir við tilviljanakenndri "
            L"hægingu, hléum og breytingum á snúningsstefnu; flug áfram heldur áfram. Hraðinn er 0–1600%. "
            L"Hver skjár hefur sjálfstæða tilviljanakennda senu sem er teiknuð á eigin endurnýjunartíðni. "
            L"Aðalljós, fylliljós, umhverfislýsing og útlínulýsing eru stillt óháð hvert öðru fyrir valda "
            L"skjái. Lýsingin á aðeins við um áferðarfleti.\r\n\r\nSKJÁIR\r\nVal lína ákvarðar hvaða skjám "
            L"er verið að breyta og er óháð gátreitunum sem kveikja á hreyfimyndaúttaki. Ctrl+A velur alla "
            L"skjái; Ctrl og Shift breyta valinu. Allir valkostir og sleðar hreyfimynda gilda fyrir valda "
            L"skjái. Valið er munað sérstaklega fyrir EXE og SCR. Ef allir skjáir voru valdir bætast nýir "
            L"skjáir einnig við valið. Mismunandi gildi á völdum skjám eru sýnd með óákveðnu ástandi "
            L"gátreita og punktamynstri á valhnöppum, handföngum sleða og hnöppunum „Virkja allt“ og "
            L"„Óvirkja allt“. Merking sleða sýnir strik í stað sameiginlegs gildis. Að breyta valkosti eða "
            L"smella á sleða setur það gildi á alla valda skjái.\r\n\r\nFORSKOÐUN OG NOTKUN\r\nVirkja "
            L"forskoðun ræsir forskoðun á öllum skjám. Stillingaglugginn helst opinn og breytingar sjást "
            L"strax. Í lagi vistar stillingar og Hætta við hafnar breytingum. Esc eða músarhreyfing lokar "
            L"skjáhvílu á öllum skjánum. Notaðu Tab og Shift+Tab til að færa þig milli stýrieininga; Alt og "
            L"undirstrikaður stafur virkja skipun. Esc í stillingum jafngildir Hætta við; í Hjálp eða Um "
            L"lokar það aðeins þeim glugga.\r\n\r\nKERFISKRÖFUR\r\nWindows 7 til Windows 11 eru studd. Til "
            L"að keyra forritið á Windows Vista SP2 þarf að setja upp uppfærslurnar KB971512 og KB2117917. "
            L"Birting krefst Direct3D 11, ekki aðeins eldri DirectX-keyrsluumhverfis."
        },
    }),
    DefineLanguage(LANG_NB, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Norsk (bokmål)" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Kontroll" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Innstillinger for FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Språk:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Animasjonshastighet: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Flytur for valgte skjermer" },
        LocalizedText{ TXT_ENABLE_ALL, L"Slå på alle" },
        LocalizedText{ TXT_DISABLE_ALL, L"Slå av alle" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Animasjonsskjerm" },
        LocalizedText{ TXT_MONITOR, L"Skjerm" },
        LocalizedText{ TXT_RESOLUTION, L"Oppløsning" },
        LocalizedText{ TXT_POSITION, L"Posisjon" },
        LocalizedText{ TXT_PRIMARY, L"primær" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Avbryt" },
        LocalizedText{ TXT_START_RECORDING, L"Start opptak…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Stopp opptak" },
        LocalizedText{ TXT_PAUSE, L"Pause" },
        LocalizedText{ TXT_RESUME, L"Fortsett" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Installer skjermsparer" },
        LocalizedText{ TXT_EXIT, L"Avslutt" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animasjonen kjører…" },
        LocalizedText{ TXT_RECORDING, L"MP4-opptak pågår…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Opptaket ble lagret." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Kunne ikke starte MP4-opptak." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Skjermspareren ble ikke installert." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Skjermspareren ble installert." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Kunne ikke initialisere Direct3D." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Flytur mellom fire formendrende flater" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Flytur gjennom en formendrende trakt" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Hvis du avslutter programmet, avsluttes opptaket som pågår."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Besøk nettstedet %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Nettstedet kan ikke åpnes i standardnettleseren." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL-adressen kunne ikke kopieres til utklippstavlen." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Informasjonen kunne ikke kopieres til utklippstavlen."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Slå på forhåndsvisning" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Slå av forhåndsvisning" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animasjonen er satt på pause." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Hindre skjermsparer under animasjon" },
        LocalizedText{ TXT_READY_STATUS, L"Klar." },
        LocalizedText{ TXT_HELP, L"Hjelp" },
        LocalizedText{ TXT_ABOUT, L"Om" },
        LocalizedText{ TXT_CLOSE, L"Lukk" },
        LocalizedText{ TXT_SNAPSHOT, L"Skjermbilde…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Skjermbildet ble lagret." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Kunne ikke lagre skjermbildet." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Avinstaller skjermsparer" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Skjermspareren ble avinstallert." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Skjermspareren kunne ikke avinstalleres. Hvis skjermspareren eller forhåndsvisningen kjører, "
            L"lukk den og prøv på nytt."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Avinstalleringen mislyktes fordi innstillingene for FlightCorridor er åpne. Lukk vinduet og "
            L"prøv på nytt."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Avinstalleringen mislyktes fordi systemforhåndsvisningen kjører. Lukk vinduet "
            L"Skjermsparerinnstillinger og prøv på nytt."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Avinstalleringen mislyktes fordi skjermspareren eller fullskjermvisningen kjører. Avslutt med "
            L"Esc eller ved å bevege musen, og prøv på nytt."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Maskinvareakselerert flytur gjennom en formendrende korridor og trakt."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versjon:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Målplattform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Nettsted:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Åpne i standardnettleseren" },
        LocalizedText{ TXT_COPY_URL, L"Kopier &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopier &informasjon" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Hovedlys" },
        LocalizedText{ TXT_FILL_LIGHT, L"Utfyllingslys" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Omgivelseslys" },
        LocalizedText{ TXT_RIM_LIGHT, L"Konturlys" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Tekstur" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Fritt roterende kamera" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauser og vendinger" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Lisensressursen er ikke tilgjengelig." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Skjermmodell" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Oppdateringsfrekvens" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bitdybde" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Fargeformat" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Fargerom" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bit/kanal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bit/piksel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Opptaksinnstillinger" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Oppløsning:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Bildefrekvens:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Endringene gjelder neste MP4-opptak." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMASJON OG INNSTILLINGER\r\nFlightCorridor: Flytur mellom fire formendrende flater; Flytur "
            L"gjennom en formendrende trakt. Tilordne nøyaktig én animasjon til hver skjerm. Tekstur veksler "
            L"mellom teksturerte flater og trådmodell. Fritt roterende kamera endrer synsretningen langsomt "
            L"i alle tre dimensjoner. Pauser og vendinger legger til tilfeldige oppbremsinger, pauser og "
            L"endringer i rotasjonsretningen; flyvningen fremover fortsetter. Hastigheten er 0–1600 %. Hver "
            L"skjerm har en uavhengig tilfeldig scene som gjengis ved dens egen oppdateringsfrekvens. "
            L"Hovedlys, utfyllingslys, omgivelseslys og konturlys kan slås av og på uavhengig for de valgte "
            L"skjermene. Belysningen gjelder bare teksturerte flater.\r\n\r\nSKJERMER\r\nMarkeringen av "
            L"rader bestemmer hvilke skjermer du redigerer, og er atskilt fra avkrysningsboksene som "
            L"aktiverer animasjonsutgangen. Ctrl+A markerer alle skjermer; Ctrl og Skift endrer markeringen. "
            L"Alle animasjonsvalg og glidebrytere gjelder de markerte skjermene. Markeringen huskes separat "
            L"for EXE og SCR. Hvis alle skjermer var markert, inkluderes også nye skjermer. Ulike verdier på "
            L"de markerte skjermene vises med ubestemte avkrysningsbokser og prikkmønster på "
            L"alternativknapper, glidebryterhåndtak og knappene «Slå på alle» og «Slå av alle». "
            L"Glidebryteretiketter viser en tankestrek i stedet for en felles verdi. Endring av et valg "
            L"eller klikk på en glidebryter bruker denne verdien på alle markerte skjermer.\r\n\r\n"
            L"BETJENING\r\nSlå animasjonsutgangene av eller på med skjermenes avkrysningsbokser eller ved å "
            L"dobbeltklikke på radene deres. Hver skjerm bruker en uavhengig scene. Skjermbilde lagrer PNG, "
            L"og opptaksknappen starter eller stopper MP4. Pause stanser animasjonen. Programmet installerer "
            L"eller avinstallerer også den innebygde skjermspareren. Innstillingene lagres fortløpende. Bare "
            L"én instans av programmet kan kjøre om gangen. En ny start gjenoppretter det minimerte "
            L"kontrollvinduet og bringer det fremst. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; "
            L"Alt og den understrekede bokstaven aktiverer en kommando. Esc lukker det aktive Hjelp- eller "
            L"Om-vinduet; i kontrollvinduet avslutter det programmet. Pause og blokkering av skjermspareren "
            L"gjelder hele programmet uavhengig av skjermmarkeringen. Når blokkering er slått på, hindres "
            L"Windows-skjermspareren bare mens en synlig animasjon som ikke er satt på pause, vises på minst "
            L"én skjerm.\r\n\r\nSKJERMBILDER OG OPPTAK\r\nSkjermbilder og opptak bruker den første aktive "
            L"animasjonsskjermen, ikke et samlet bilde av alle skjermene. PNG bruker Bilder, MP4 Videoer; "
            L"hvis disse mappene ikke finnes, brukes Dokumenter. Knappen Opptaksinnstillinger velger "
            L"Viewport eller TV. Viewport beholder animasjonsskjermens størrelse og oppdateringsfrekvens, "
            L"opptil 60 bilder per sekund. TV tilbyr 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet "
            L"16:9, med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) bilder per sekund. Bildets "
            L"proporsjoner beholdes; TV bruker progressiv BT.709-video med begrenset område og "
            L"4:2:0-sampling. Oppløsning og bildefrekvens er bare tilgjengelige i TV-modus. Vinduet "
            L"Opptaksinnstillinger kan minimeres og blokkerer ikke de andre programvinduene. OK lagrer "
            L"valgene for neste MP4-opptak; Avbryt eller Esc forkaster ubekreftede endringer. "
            L"Animasjonsutgangen på skjermen som tas opp, kan ikke slås av under opptaket; endringer på "
            L"andre skjermer stopper ikke opptaket. Å avslutte programmet under et opptak krever "
            L"bekreftelse, fordi det også avslutter opptaket.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 "
            L"støtter alle funksjoner, inkludert PNG-skjermbilder og MP4-opptak. For å kjøre programmet på "
            L"Windows Vista SP2 må oppdateringene KB971512 og KB2117917 installeres. MP4-opptak fungerer "
            L"ikke på Vista i den gjeldende versjonen. Visningen krever Direct3D 11, ikke bare en eldre "
            L"DirectX-kjøretid. MP4-opptak krever tilgjengelige Media Foundation-komponenter og en "
            L"H.264-koder."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMASJON OG INNSTILLINGER\r\nFlightCorridor: Flytur mellom fire formendrende flater; Flytur "
            L"gjennom en formendrende trakt. Tilordne nøyaktig én animasjon til hver skjerm. Tekstur veksler "
            L"mellom teksturerte flater og trådmodell. Fritt roterende kamera endrer synsretningen langsomt "
            L"i alle tre dimensjoner. Pauser og vendinger legger til tilfeldige oppbremsinger, pauser og "
            L"endringer i rotasjonsretningen; flyvningen fremover fortsetter. Hastigheten er 0–1600 %. Hver "
            L"skjerm har en uavhengig tilfeldig scene som gjengis ved dens egen oppdateringsfrekvens. "
            L"Hovedlys, utfyllingslys, omgivelseslys og konturlys kan slås av og på uavhengig for de valgte "
            L"skjermene. Belysningen gjelder bare teksturerte flater.\r\n\r\nSKJERMER\r\nMarkeringen av "
            L"rader bestemmer hvilke skjermer du redigerer, og er atskilt fra avkrysningsboksene som "
            L"aktiverer animasjonsutgangen. Ctrl+A markerer alle skjermer; Ctrl og Skift endrer markeringen. "
            L"Alle animasjonsvalg og glidebrytere gjelder de markerte skjermene. Markeringen huskes separat "
            L"for EXE og SCR. Hvis alle skjermer var markert, inkluderes også nye skjermer. Ulike verdier på "
            L"de markerte skjermene vises med ubestemte avkrysningsbokser og prikkmønster på "
            L"alternativknapper, glidebryterhåndtak og knappene «Slå på alle» og «Slå av alle». "
            L"Glidebryteretiketter viser en tankestrek i stedet for en felles verdi. Endring av et valg "
            L"eller klikk på en glidebryter bruker denne verdien på alle markerte skjermer.\r\n\r\n"
            L"FORHÅNDSVISNING OG BETJENING\r\nSlå på forhåndsvisning starter en fullskjermsvisning på alle "
            L"skjermer. Innstillingene forblir åpne, og endringene vises fortløpende. OK lagrer "
            L"innstillingene og Avbryt forkaster dem. Esc eller musebevegelse avslutter "
            L"fullskjermsvisningen. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den "
            L"understrekede bokstaven aktiverer en kommando. Esc i innstillingene tilsvarer Avbryt; i Hjelp "
            L"eller Om lukker det bare dette vinduet.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 støttes. "
            L"For å kjøre programmet på Windows Vista SP2 må oppdateringene KB971512 og KB2117917 "
            L"installeres. Visningen krever Direct3D 11, ikke bare en eldre DirectX-kjøretid."
        },
    }),
    DefineLanguage(LANG_SV, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Svenska" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Styrning" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Inställningar för FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Språk:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Animationshastighet: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Flygtur för valda bildskärmar" },
        LocalizedText{ TXT_ENABLE_ALL, L"Aktivera alla" },
        LocalizedText{ TXT_DISABLE_ALL, L"Inaktivera alla" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Animationsskärm" },
        LocalizedText{ TXT_MONITOR, L"Bildskärm" },
        LocalizedText{ TXT_RESOLUTION, L"Upplösning" },
        LocalizedText{ TXT_POSITION, L"Position" },
        LocalizedText{ TXT_PRIMARY, L"primär" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Avbryt" },
        LocalizedText{ TXT_START_RECORDING, L"Starta inspelning…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Stoppa inspelning" },
        LocalizedText{ TXT_PAUSE, L"Pausa" },
        LocalizedText{ TXT_RESUME, L"Fortsätt" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Installera skärmsläckare" },
        LocalizedText{ TXT_EXIT, L"Avsluta" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animeringen körs…" },
        LocalizedText{ TXT_RECORDING, L"MP4-inspelning pågår…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Inspelningen sparades." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Det gick inte att starta MP4-inspelningen." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Skärmsläckaren installerades inte." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Skärmsläckaren installerades." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Det gick inte att initiera Direct3D." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Flygtur mellan fyra formföränderliga ytor" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Flygtur genom en formföränderlig tratt" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Om du avslutar programmet stoppas den pågående inspelningen."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Besök webbplatsen %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Webbplatsen kan inte öppnas i standardwebbläsaren." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL-adressen kunde inte kopieras till Urklipp." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Informationen kunde inte kopieras till Urklipp."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Aktivera förhandsvisning" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Inaktivera förhandsvisning" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animeringen är pausad." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blockera skärmsläckare under animering" },
        LocalizedText{ TXT_READY_STATUS, L"Redo." },
        LocalizedText{ TXT_HELP, L"Hjälp" },
        LocalizedText{ TXT_ABOUT, L"Om" },
        LocalizedText{ TXT_CLOSE, L"Stäng" },
        LocalizedText{ TXT_SNAPSHOT, L"Skärmbild…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Skärmbilden sparades." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Det gick inte att spara skärmbilden." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Avinstallera skärmsläckare" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Skärmsläckaren avinstallerades." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Skärmsläckaren kunde inte avinstalleras. Om skärmsläckaren eller förhandsvisningen körs, stäng "
            L"den och försök igen."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Avinstallationen misslyckades eftersom inställningarna för FlightCorridor är öppna. Stäng "
            L"fönstret och försök igen."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Avinstallationen misslyckades eftersom systemförhandsvisningen körs. Stäng fönstret "
            L"Inställningar för skärmsläckare och försök igen."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Avinstallationen misslyckades eftersom skärmsläckaren eller helskärmsförhandsvisningen körs. "
            L"Avsluta med Esc eller genom att röra musen och försök igen."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Maskinvaruaccelererad flygtur genom en formföränderlig korridor och tratt."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Version:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Målplattform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Webbplats:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Öppna i standardwebbläsaren" },
        LocalizedText{ TXT_COPY_URL, L"Kopiera &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopiera &information" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Huvudljus" },
        LocalizedText{ TXT_FILL_LIGHT, L"Upplättningsljus" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Omgivningsljus" },
        LocalizedText{ TXT_RIM_LIGHT, L"Konturljus" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Textur" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Fritt roterande kamera" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauser och vändningar" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Licensresursen är inte tillgänglig." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Skärmmodell" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Uppdateringsfrekvens" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bitdjup" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Färgformat" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Färgrymd" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bitar/kanal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bitar/pixel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Inspelningsinställningar" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Upplösning:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Bildfrekvens:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Ändringarna gäller nästa MP4-inspelning." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMERING OCH INSTÄLLNINGAR\r\nFlightCorridor: Flygtur mellan fyra formföränderliga ytor; "
            L"Flygtur genom en formföränderlig tratt. Tilldela varje skärm exakt en animering. Textur växlar "
            L"mellan texturerade ytor och trådmodell. Fritt roterande kamera ändrar långsamt blickriktningen "
            L"i alla tre dimensioner. Pauser och vändningar lägger till slumpmässiga inbromsningar, pauser "
            L"och byten av rotationsriktning; flygningen framåt fortsätter. Hastigheten är 0–1600 %. Varje "
            L"skärm har en oberoende slumpmässig scen som återges med dess egen uppdateringsfrekvens. "
            L"Huvudljus, upplättningsljus, omgivningsljus och konturljus kan slås på och av oberoende för de "
            L"valda skärmarna. Belysningen gäller bara texturerade ytor.\r\n\r\nBILDSKÄRMAR\r\nMarkeringen "
            L"av rader avgör vilka skärmar du redigerar och är skild från kryssrutorna som aktiverar "
            L"animationsutgångarna. Ctrl+A markerar alla skärmar; Ctrl och Skift ändrar markeringen. Alla "
            L"animationsalternativ och reglage gäller de markerade skärmarna. Markeringen sparas separat för "
            L"EXE och SCR. Om alla skärmar var markerade inkluderas även nya skärmar. Olika värden på de "
            L"markerade skärmarna visas med obestämda kryssrutor och punktmönster på alternativknappar, "
            L"reglagehandtag och knapparna ”Aktivera alla” och ”Inaktivera alla”. Reglagens etiketter visar "
            L"ett streck i stället för ett gemensamt värde. När du ändrar ett alternativ eller klickar på "
            L"ett reglage används värdet på alla markerade skärmar.\r\n\r\nANVÄNDNING\r\nSlå på eller av "
            L"animationsutgångarna med skärmarnas kryssrutor eller genom att dubbelklicka på deras rader. "
            L"Varje bildskärm använder en oberoende scen. Skärmbild sparar PNG och inspelningsknappen "
            L"startar eller stoppar MP4. Paus stannar animeringen. Programmet installerar eller "
            L"avinstallerar även den inbyggda skärmsläckaren. Inställningarna sparas fortlöpande. Programmet "
            L"kan bara köras i en instans åt gången. En ny start återställer det minimerade kontrollfönstret "
            L"och för det längst fram. Använd Tab och Skift+Tab för att flytta mellan kontrollerna; Alt och "
            L"den understrukna bokstaven aktiverar ett kommando. Esc stänger det aktiva Hjälp- eller "
            L"Om-fönstret; i kontrollfönstret avslutar det programmet. Paus och blockering av skärmsläckaren "
            L"gäller hela programmet oavsett markerade skärmar. När blockeringen är på hindras "
            L"Windows-skärmsläckaren bara medan en synlig animering som inte är pausad visas på minst en "
            L"skärm.\r\n\r\nSKÄRMBILDER OCH INSPELNING\r\nSkärmbilder och inspelningar använder den första "
            L"aktiva animeringsskärmen, inte en sammanslagen bild av alla skärmar. PNG använder Bilder, MP4 "
            L"Videor; om dessa mappar saknas används Dokument. Knappen Inspelningsinställningar väljer "
            L"Viewport eller TV. Viewport behåller animeringsskärmens storlek och uppdateringsfrekvens, upp "
            L"till 60 bilder per sekund. TV erbjuder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet "
            L"16:9, med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) bilder per sekund. Bildens "
            L"proportioner bevaras; TV använder progressiv BT.709-video med begränsat omfång och "
            L"4:2:0-sampling. Upplösning och bildfrekvens kan bara väljas i TV-läge. Fönstret "
            L"Inspelningsinställningar kan minimeras och blockerar inte de andra programfönstren. OK sparar "
            L"valen för nästa MP4-inspelning; Avbryt eller Esc ignorerar obekräftade ändringar. "
            L"Animeringsutgången på den inspelade skärmen kan inte stängas av under inspelningen; ändringar "
            L"av andra skärmar stoppar inte inspelningen. Att avsluta programmet under en inspelning kräver "
            L"bekräftelse eftersom det också avslutar inspelningen.\r\n\r\nSYSTEMKRAV\r\nWindows 7 till "
            L"Windows 11 stöder alla funktioner, inklusive PNG-skärmbilder och MP4-inspelning. För att köra "
            L"programmet på Windows Vista SP2 måste uppdateringarna KB971512 och KB2117917 installeras. "
            L"MP4-inspelning fungerar inte på Vista i den aktuella versionen. Visningen kräver Direct3D 11, "
            L"inte bara en äldre DirectX-körningsmiljö. MP4-inspelning kräver tillgängliga Media "
            L"Foundation-komponenter och en H.264-kodare."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMERING OCH INSTÄLLNINGAR\r\nFlightCorridor: Flygtur mellan fyra formföränderliga ytor; "
            L"Flygtur genom en formföränderlig tratt. Tilldela varje skärm exakt en animering. Textur växlar "
            L"mellan texturerade ytor och trådmodell. Fritt roterande kamera ändrar långsamt blickriktningen "
            L"i alla tre dimensioner. Pauser och vändningar lägger till slumpmässiga inbromsningar, pauser "
            L"och byten av rotationsriktning; flygningen framåt fortsätter. Hastigheten är 0–1600 %. Varje "
            L"skärm har en oberoende slumpmässig scen som återges med dess egen uppdateringsfrekvens. "
            L"Huvudljus, upplättningsljus, omgivningsljus och konturljus kan slås på och av oberoende för de "
            L"valda skärmarna. Belysningen gäller bara texturerade ytor.\r\n\r\nBILDSKÄRMAR\r\nMarkeringen "
            L"av rader avgör vilka skärmar du redigerar och är skild från kryssrutorna som aktiverar "
            L"animationsutgångarna. Ctrl+A markerar alla skärmar; Ctrl och Skift ändrar markeringen. Alla "
            L"animationsalternativ och reglage gäller de markerade skärmarna. Markeringen sparas separat för "
            L"EXE och SCR. Om alla skärmar var markerade inkluderas även nya skärmar. Olika värden på de "
            L"markerade skärmarna visas med obestämda kryssrutor och punktmönster på alternativknappar, "
            L"reglagehandtag och knapparna ”Aktivera alla” och ”Inaktivera alla”. Reglagens etiketter visar "
            L"ett streck i stället för ett gemensamt värde. När du ändrar ett alternativ eller klickar på "
            L"ett reglage används värdet på alla markerade skärmar.\r\n\r\nFÖRHANDSGRANSKNING OCH "
            L"ANVÄNDNING\r\nAktivera förhandsvisning startar en helskärmsvisning på alla bildskärmar. "
            L"Inställningarna förblir öppna och ändringarna visas direkt. OK sparar inställningarna och "
            L"Avbryt förkastar ändringarna. Esc eller musrörelse avslutar helskärmsläget. Använd Tab och "
            L"Skift+Tab för att flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett "
            L"kommando. Esc i inställningarna motsvarar Avbryt; i Hjälp eller Om stänger det bara det "
            L"fönstret.\r\n\r\nSYSTEMKRAV\r\nWindows 7 till Windows 11 stöds. För att köra programmet på "
            L"Windows Vista SP2 måste uppdateringarna KB971512 och KB2117917 installeras. Visningen kräver "
            L"Direct3D 11, inte bara en äldre DirectX-körningsmiljö."
        },
    }),
    DefineLanguage(LANG_TR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Türkçe" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — Denetim" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlightCorridor Ayarları" },
        LocalizedText{ TXT_LANGUAGE, L"Dil:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Animasyon hızı: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Seçili monitörlerdeki uçuş" },
        LocalizedText{ TXT_ENABLE_ALL, L"Tümünü etkinleştir" },
        LocalizedText{ TXT_DISABLE_ALL, L"Tümünü devre dışı bırak" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Animasyon monitörü" },
        LocalizedText{ TXT_MONITOR, L"Monitör" },
        LocalizedText{ TXT_RESOLUTION, L"Çözünürlük" },
        LocalizedText{ TXT_POSITION, L"Konum" },
        LocalizedText{ TXT_PRIMARY, L"birincil" },
        LocalizedText{ TXT_OK, L"Tamam" },
        LocalizedText{ TXT_CANCEL, L"İptal" },
        LocalizedText{ TXT_START_RECORDING, L"Kaydı başlat…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Kaydı durdur" },
        LocalizedText{ TXT_PAUSE, L"Duraklat" },
        LocalizedText{ TXT_RESUME, L"Sürdür" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Ekran koruyucuyu yükle" },
        LocalizedText{ TXT_EXIT, L"Çıkış" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animasyon çalışıyor…" },
        LocalizedText{ TXT_RECORDING, L"MP4 kaydı sürüyor…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Kayıt kaydedildi." },
        LocalizedText{ TXT_RECORDING_FAILED, L"MP4 kaydı başlatılamadı." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Ekran koruyucu yüklenmedi." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Ekran koruyucu yüklendi." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Direct3D başlatılamadı." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Biçim değiştiren dört yüzey arasında uçuş" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Biçim değiştiren bir huninin içinden uçuş" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Uygulamayı kapatmak devam eden kaydı durduracaktır." },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"%ls web sitesini ziyaret et" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Web sitesi varsayılan tarayıcıda açılamıyor." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL panoya kopyalanamadı." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Bilgiler panoya kopyalanamadı." },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Önizlemeyi aç" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Önizlemeyi kapat" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animasyon duraklatıldı." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Animasyon sırasında ekran koruyucuyu engelle" },
        LocalizedText{ TXT_READY_STATUS, L"Hazır." },
        LocalizedText{ TXT_HELP, L"Yardım" },
        LocalizedText{ TXT_ABOUT, L"Hakkında" },
        LocalizedText{ TXT_CLOSE, L"Kapat" },
        LocalizedText{ TXT_SNAPSHOT, L"Anlık görüntü…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Anlık görüntü kaydedildi." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Anlık görüntü kaydedilemedi." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Ekran koruyucuyu kaldır" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Ekran koruyucu kaldırıldı." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Ekran koruyucu kaldırılamadı. Ekran koruyucu veya önizlemesi çalışıyorsa kapatıp yeniden "
            L"deneyin."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"FlightCorridor ayarları açık olduğu için kaldırma başarısız oldu. Ayarlar penceresini kapatıp "
            L"yeniden deneyin."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Sistem önizlemesi çalıştığı için kaldırma başarısız oldu. Ekran Koruyucu Ayarları penceresini "
            L"kapatıp yeniden deneyin."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Ekran koruyucu veya tam ekran önizleme çalıştığı için kaldırma başarısız oldu. Esc ile ya da "
            L"fareyi hareket ettirerek çıkıp yeniden deneyin."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Biçim değiştiren bir koridor ve hunide donanım hızlandırmalı uçuş."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Sürüm:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Hedef platform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Web sitesi:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"Varsayılan tarayıcıda &aç" },
        LocalizedText{ TXT_COPY_URL, L"&URL'yi kopyala" },
        LocalizedText{ TXT_COPY_INFORMATION, L"&Bilgileri kopyala" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Ana ışık" },
        LocalizedText{ TXT_FILL_LIGHT, L"Dolgu ışığı" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ortam ışığı" },
        LocalizedText{ TXT_RIM_LIGHT, L"Kenar aydınlatması" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Doku" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Serbest kamera dönüşü" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Duraklama ve ters dönüş" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Lisans kaynağı kullanılamıyor." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Monitör modeli" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Yenileme hızı" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bit derinliği" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Renk biçimi" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Renk uzayı" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bit/kanal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bit/piksel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Kayıt ayarları" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Çözünürlük:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Kare hızı:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Değişiklikler bir sonraki MP4 kaydına uygulanır." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANİMASYON VE AYARLAR\r\nFlightCorridor: Biçim değiştiren dört yüzey arasında uçuş; Biçim "
            L"değiştiren bir huninin içinden uçuş. Her ekrana tam bir animasyon atayın. Doku, dokulu "
            L"yüzeyler ile tel kafes modeli arasında geçiş yapar. Serbest kamera dönüşü bakış yönünü üç "
            L"boyutta yavaşça değiştirir. Duraklama ve ters dönüş, dönüşe rastgele yavaşlamalar, "
            L"duraklamalar ve ters yön değişimleri ekler; ileri uçuş devam eder. Hız %0–1600 aralığındadır. "
            L"Her ekranın kendi yenileme hızında çizilen bağımsız rastgele bir sahnesi vardır. Ana ışık, "
            L"dolgu ışığı, ortam ışığı ve kenar aydınlatması seçili ekranlar için ayrı ayrı açılıp "
            L"kapatılabilir. Aydınlatma yalnızca dokulu yüzeylere uygulanır.\r\n\r\nEKRANLAR\r\nSatır "
            L"seçimi, hangi ekranların düzenlendiğini belirler; animasyon çıkışlarını açan onay kutularından "
            L"ayrıdır. Ctrl+A tüm ekranları seçer; Ctrl ve Shift seçimi değiştirir. Tüm animasyon "
            L"seçenekleri ve kaydırıcılar seçili ekranlara uygulanır. Seçim EXE ve SCR için ayrı saklanır. "
            L"Tüm ekranlar seçiliyse sonradan bağlanan ekranlar da seçime katılır. Seçili ekranlardaki "
            L"farklı değerler, belirsiz durumdaki onay kutuları ve seçenek düğmelerinde, kaydırıcı "
            L"tutamaçlarında ve “Tümünü etkinleştir” ve “Tümünü devre dışı bırak” düğmelerinde noktalı "
            L"desenle gösterilir. Kaydırıcı etiketleri ortak bir değer yerine çizgi gösterir. Bir seçeneği "
            L"değiştirmek veya kaydırıcıya tıklamak bu değeri tüm seçili ekranlara uygular.\r\n\r\nKULLANIM\r"
            L"\nAnimasyon çıkışlarını ekran onay kutularıyla veya satırlarına çift tıklayarak açıp "
            L"kapatabilirsiniz. Her monitör bağımsız sahne kullanır. Anlık görüntü PNG kaydeder; kayıt "
            L"düğmesi MP4 kaydını başlatır veya bitirir. Duraklat animasyonu durdurur. Uygulama gömülü ekran "
            L"koruyucuyu da kurar veya kaldırır. Ayarlar sürekli kaydedilir. Uygulamanın aynı anda yalnızca "
            L"bir örneği çalışabilir. Yeniden başlatılması, simge durumuna küçültülmüş denetim penceresini "
            L"geri yükler ve ön plana getirir. Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve "
            L"altı çizili harf bir komutu etkinleştirir. Esc, etkin Yardım veya Hakkında penceresini "
            L"kapatır; denetim penceresinde uygulamadan çıkar. Duraklatma ve ekran koruyucuyu engelleme, "
            L"ekran seçiminden bağımsız olarak uygulamanın tamamına uygulanır. Engelleme açıkken Windows "
            L"ekran koruyucusu yalnızca en az bir ekranda görünür ve duraklatılmamış animasyon varken "
            L"engellenir.\r\n\r\nEKRAN GÖRÜNTÜLERİ VE KAYIT\r\nAnlık görüntüler ve kayıtlar, tüm "
            L"monitörlerin birleşik görüntüsünü değil, ilk etkin animasyon monitörünü kullanır. PNG "
            L"Resimler, MP4 Videolar klasörünü kullanır; bu klasörler yoksa Belgeler kullanılır. Kayıt "
            L"ayarları düğmesi Viewport veya TV seçimini açar. Viewport, animasyon monitörünün boyutlarını "
            L"ve yenileme hızını saniyede en fazla 60 kareyle korur. TV, 16:9 oranında 1920 × 1080, 1440 × "
            L"1080 veya 1280 × 720 çözünürlük ile saniyede 50, 25, 59.94 (60000/1001) veya 29.97 "
            L"(30000/1001) kare sunar. Görüntünün en boy oranı korunur; TV, sınırlı aralıklı, 4:2:0 "
            L"örneklemeli ilerlemeli BT.709 video kullanır. Çözünürlük ve kare hızı yalnızca TV modunda "
            L"seçilebilir. Kayıt ayarları penceresi simge durumuna küçültülebilir ve uygulamanın diğer "
            L"pencerelerini engellemez. Tamam, seçenekleri bir sonraki MP4 kaydı için kaydeder; İptal veya "
            L"Esc onaylanmamış değişiklikleri iptal eder. Kayıt sırasında kaydedilen ekranın animasyon "
            L"çıkışı kapatılamaz; diğer ekranlardaki değişiklikler kaydı durdurmaz. Kayıt sırasında "
            L"uygulamayı kapatmak kaydı da durduracağı için onay gerektirir.\r\n\r\nSİSTEM GEREKSİNİMLERİ\r\n"
            L"Windows 7 ile Windows 11 arasındaki sürümler, PNG anlık görüntüler ve MP4 kaydı dâhil tüm "
            L"özellikleri destekler. Uygulamayı Windows Vista SP2'de çalıştırmak için KB971512 ve KB2117917 "
            L"güncellemelerini yüklemeniz gerekir. Geçerli sürümde MP4 kaydı Vista'da çalışmaz. Görüntüleme, "
            L"yalnızca eski bir DirectX çalışma zamanı değil, Direct3D 11 gerektirir. MP4 kaydı, "
            L"kullanılabilir Media Foundation bileşenleri ve bir H.264 kodlayıcı gerektirir."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANİMASYON VE AYARLAR\r\nFlightCorridor: Biçim değiştiren dört yüzey arasında uçuş; Biçim "
            L"değiştiren bir huninin içinden uçuş. Her ekrana tam bir animasyon atayın. Doku, dokulu "
            L"yüzeyler ile tel kafes modeli arasında geçiş yapar. Serbest kamera dönüşü bakış yönünü üç "
            L"boyutta yavaşça değiştirir. Duraklama ve ters dönüş, dönüşe rastgele yavaşlamalar, "
            L"duraklamalar ve ters yön değişimleri ekler; ileri uçuş devam eder. Hız %0–1600 aralığındadır. "
            L"Her ekranın kendi yenileme hızında çizilen bağımsız rastgele bir sahnesi vardır. Ana ışık, "
            L"dolgu ışığı, ortam ışığı ve kenar aydınlatması seçili ekranlar için ayrı ayrı açılıp "
            L"kapatılabilir. Aydınlatma yalnızca dokulu yüzeylere uygulanır.\r\n\r\nEKRANLAR\r\nSatır "
            L"seçimi, hangi ekranların düzenlendiğini belirler; animasyon çıkışlarını açan onay kutularından "
            L"ayrıdır. Ctrl+A tüm ekranları seçer; Ctrl ve Shift seçimi değiştirir. Tüm animasyon "
            L"seçenekleri ve kaydırıcılar seçili ekranlara uygulanır. Seçim EXE ve SCR için ayrı saklanır. "
            L"Tüm ekranlar seçiliyse sonradan bağlanan ekranlar da seçime katılır. Seçili ekranlardaki "
            L"farklı değerler, belirsiz durumdaki onay kutuları ve seçenek düğmelerinde, kaydırıcı "
            L"tutamaçlarında ve “Tümünü etkinleştir” ve “Tümünü devre dışı bırak” düğmelerinde noktalı "
            L"desenle gösterilir. Kaydırıcı etiketleri ortak bir değer yerine çizgi gösterir. Bir seçeneği "
            L"değiştirmek veya kaydırıcıya tıklamak bu değeri tüm seçili ekranlara uygular.\r\n\r\nÖNİZLEME "
            L"VE KULLANIM\r\nÖnizlemeyi aç tüm monitörlerde tam ekran önizleme başlatır. Ayarlar penceresi "
            L"açık kalır ve değişiklikler anında görülür. Tamam ayarları kaydeder, İptal değişiklikleri "
            L"iptal eder. Tam ekran koruyucudan Esc veya fare hareketiyle çıkılır. Denetimler arasında Tab "
            L"ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir komutu etkinleştirir. Ayarlarda Esc, "
            L"İptal ile aynı işlevi görür; Yardım veya Hakkında penceresinde yalnızca o pencereyi kapatır.\r"
            L"\n\r\nSİSTEM GEREKSİNİMLERİ\r\nWindows 7 ile Windows 11 arasındaki sürümler desteklenir. "
            L"Uygulamayı Windows Vista SP2'de çalıştırmak için KB971512 ve KB2117917 güncellemelerini "
            L"yüklemeniz gerekir. Görüntüleme, yalnızca eski bir DirectX çalışma zamanı değil, Direct3D 11 "
            L"gerektirir."
        },
    }),
    DefineLanguage(LANG_ET, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Eesti" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — juhtimine" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlightCorridor sätted" },
        LocalizedText{ TXT_LANGUAGE, L"Keel:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Animatsiooni kiirus: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Valitud kuvarite lennurežiim" },
        LocalizedText{ TXT_ENABLE_ALL, L"Luba kõik" },
        LocalizedText{ TXT_DISABLE_ALL, L"Keela kõik" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Animatsioonikuvar" },
        LocalizedText{ TXT_MONITOR, L"Kuvar" },
        LocalizedText{ TXT_RESOLUTION, L"Eraldusvõime" },
        LocalizedText{ TXT_POSITION, L"Asukoht" },
        LocalizedText{ TXT_PRIMARY, L"peamine" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Loobu" },
        LocalizedText{ TXT_START_RECORDING, L"Alusta salvestamist…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Peata salvestamine" },
        LocalizedText{ TXT_PAUSE, L"Peata" },
        LocalizedText{ TXT_RESUME, L"Jätka" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Paigalda ekraanisäästja" },
        LocalizedText{ TXT_EXIT, L"Välju" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animatsioon töötab…" },
        LocalizedText{ TXT_RECORDING, L"MP4 salvestamine…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Salvestis on salvestatud." },
        LocalizedText{ TXT_RECORDING_FAILED, L"MP4 salvestamist ei saanud alustada." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Ekraanisäästjat ei paigaldatud." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Ekraanisäästja on paigaldatud." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Direct3D renderdajat ei saanud käivitada." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Lend nelja muutuva pinna vahel" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Lend läbi muutuva lehtri" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Rakenduse sulgemine lõpetab käimasoleva salvestamise."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Ava veebisait %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Veebisaiti ei saa vaikebrauseris avada." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL-i ei saanud lõikelauale kopeerida." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Teavet ei saanud lõikelauale kopeerida." },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Luba eelvaade" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Keela eelvaade" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animatsioon on peatatud." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Tõkesta animatsiooni ajal ekraanisäästja" },
        LocalizedText{ TXT_READY_STATUS, L"Valmis." },
        LocalizedText{ TXT_HELP, L"Spikker" },
        LocalizedText{ TXT_ABOUT, L"Teave" },
        LocalizedText{ TXT_CLOSE, L"Sule" },
        LocalizedText{ TXT_SNAPSHOT, L"Salvesta PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"PNG-pilt on salvestatud." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"PNG-pilti ei saanud salvestada." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Eemalda ekraanisäästja" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Ekraanisäästja on eemaldatud." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Ekraanisäästjat ei saanud eemaldada. Sulgege ekraanisäästja ja selle eelvaade ning proovige "
            L"uuesti."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Sulgege FlightCorridor sätete aken ja proovige eemaldamist uuesti."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Sulgege Windowsi ekraanisäästja sätete aken ja proovige eemaldamist uuesti."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Sulgege ekraanisäästja või täisekraanieelvaade klahviga Esc või hiire liigutamisega ja "
            L"proovige eemaldamist uuesti."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Riistvarakiirendusega lend muutuvate pindade vahel." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versioon:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Sihtplatvorm:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Veebisait:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Ava vaikebrauseris" },
        LocalizedText{ TXT_COPY_URL, L"Kopeeri &aadress" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopeeri &teave" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Põhivalgus" },
        LocalizedText{ TXT_FILL_LIGHT, L"Täitevalgus" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ümbritsev valgus" },
        LocalizedText{ TXT_RIM_LIGHT, L"Kontuurivalgus" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Tekstuur" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Kaamera vaba pöörlemine" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pausid ja pöördumised" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Litsentsiressurss pole saadaval." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Kuvari mudel" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Värskendussagedus" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bitisügavus" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Värvivorming" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Värviruum" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bitti/kanal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bitti/piksel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Salvestussätted" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Eraldusvõime:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Kaadrisagedus:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Muudatused rakenduvad järgmisele MP4 salvestusele." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMATSIOON JA SÄTTED\r\nRiistvarakiirendusega lend muutuvate pindade vahel. Lend nelja "
            L"muutuva pinna vahel; Lend läbi muutuva lehtri. Valige igale kuvarile täpselt üks animatsioon. "
            L"Tekstuuri märkeruut vahetab tekstuuriga pinna ja traatmudeli vahel. Kaamera vaba pöörlemine "
            L"muudab vaatesuunda aeglaselt kõigis kolmes mõõtmes. Pausid ja pöördumised lisavad sellele "
            L"juhuslikke aeglustusi, pause ja pöörlemissuuna muutusi; edasilend jätkub. Kiirus on seatav "
            L"vahemikus 0–1600%. Igal kuvaril on oma sõltumatu juhuslik stseen ja värskendussagedusele "
            L"vastav renderdus. Põhivalgust, täitevalgust, ümbritsevat valgust ja kontuurivalgust saab "
            L"valitud kuvaritel eraldi sisse ja välja lülitada. Valgustus kehtib ainult tekstuuriga "
            L"pindadele.\r\n\r\nKUVARID\r\nValige loendis üks või mitu kuvaririda. Ctrl+A valib kõik read; "
            L"Ctrl ja Shift võimaldavad valikut muuta. Animatsiooni juhtnupud ja liugurid mõjutavad ainult "
            L"valitud kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle märkeruuduga väljundi "
            L"lubamine on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja jaoks eraldi meelde. Kui "
            L"varem olid valitud kõik kuvarid, kaasatakse ka lisatud kuvarid. Valitud kuvarite erinevaid "
            L"väärtusi näitavad märkeruutude määramata olek ning raadionuppude, liugurite käepidemete ja "
            L"nuppude „Luba kõik” ja „Keela kõik” punktimuster. Liuguri sildil on ühise väärtuse asemel "
            L"kriips. Valiku muutmine või liuguril klõpsamine määrab selle väärtuse kõigile valitud "
            L"kuvaritele.\r\n\r\nKASUTAMINE\r\nKäivitage FlightCorridor.exe. Sätteid salvestatakse jooksvalt "
            L"ning rakendus töötab ühe eksemplarina. Kuvari märkeruut või topeltklõps real lülitab selle "
            L"animatsiooniväljundi sisse või välja. Animatsiooni saab peatada ja jätkata. PNG-pilt ja "
            L"MP4-video jäädvustavad esimese aktiivse animatsioonikuvari, mitte kõiki kuvareid koos. "
            L"Salvestatava kuvari animatsiooniväljundit ei saa salvestamise ajal välja lülitada; rakenduse "
            L"sulgemine nõuab siis kinnitust. Peatamine ja ekraanisäästja tõkestamine kehtivad kogu "
            L"rakendusele, sõltumata kuvarite valikust. Kui tõkestamine on sisse lülitatud, takistatakse "
            L"Windowsi ekraanisäästjat ainult seni, kuni vähemalt ühel kuvaril on nähtav peatamata "
            L"animatsioon. Rakendus saab paigaldada ja eemaldada sisseehitatud ekraanisäästja.\r\n\r\n"
            L"KUVATÕMMISED JA SALVESTAMINE\r\nSalvestussätetes valige Viewport või TV. Viewport säilitab "
            L"kuvari mõõtmed ja värskendussageduse kuni 60 kaadrit sekundis. TV pakub 1920 × 1080, 1440 × "
            L"1080 või 1280 × 720 väljundit kuvasuhtega 16:9 ning 50, 25, 59.94 (60000/1001) või 29.97 "
            L"(30000/1001) kaadrit sekundis. TV-video on progressiivne BT.709, piiratud vahemikuga ja 4:2:0 "
            L"värvialamdiskreetimisega. Pildi kuvasuhe säilib ja täiteribad on mustad. OK rakendab valikud "
            L"järgmisele salvestusele; Loobu või Esc tühistab kinnitamata muudatused. Salvestussätted, "
            L"spikker ja teave ei blokeeri teisi aknaid ning neid saab minimeerida. Tab ja Shift+Tab "
            L"liigutavad fookust, Enter vajutab fookusega nuppu ning Esc sulgeb aktiivse lisaakna.\r\n\r\n"
            L"SÜSTEEMINÕUDED\r\nWindows 7–11 toetab kõiki funktsioone. Windows Vista SP2 jaoks tuleb "
            L"paigaldada värskendused KB971512 ja KB2117917; MP4 salvestamine Vistas ei tööta. Vaja on "
            L"Direct3D 11 tuge ning MP4 jaoks Media Foundationi ja H.264 kodeerijat. Liides ja "
            L"dokumentatsioon on saadaval 36 keeles."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATSIOON JA SÄTTED\r\nRiistvarakiirendusega lend muutuvate pindade vahel. Lend nelja "
            L"muutuva pinna vahel; Lend läbi muutuva lehtri. Valige igale kuvarile täpselt üks animatsioon. "
            L"Tekstuuri märkeruut vahetab tekstuuriga pinna ja traatmudeli vahel. Kaamera vaba pöörlemine "
            L"muudab vaatesuunda aeglaselt kõigis kolmes mõõtmes. Pausid ja pöördumised lisavad sellele "
            L"juhuslikke aeglustusi, pause ja pöörlemissuuna muutusi; edasilend jätkub. Kiirus on seatav "
            L"vahemikus 0–1600%. Igal kuvaril on oma sõltumatu juhuslik stseen ja värskendussagedusele "
            L"vastav renderdus. Põhivalgust, täitevalgust, ümbritsevat valgust ja kontuurivalgust saab "
            L"valitud kuvaritel eraldi sisse ja välja lülitada. Valgustus kehtib ainult tekstuuriga "
            L"pindadele.\r\n\r\nKUVARID\r\nValige loendis üks või mitu kuvaririda. Ctrl+A valib kõik read; "
            L"Ctrl ja Shift võimaldavad valikut muuta. Animatsiooni juhtnupud ja liugurid mõjutavad ainult "
            L"valitud kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle märkeruuduga väljundi "
            L"lubamine on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja jaoks eraldi meelde. Kui "
            L"varem olid valitud kõik kuvarid, kaasatakse ka lisatud kuvarid. Valitud kuvarite erinevaid "
            L"väärtusi näitavad märkeruutude määramata olek ning raadionuppude, liugurite käepidemete ja "
            L"nuppude „Luba kõik” ja „Keela kõik” punktimuster. Liuguri sildil on ühise väärtuse asemel "
            L"kriips. Valiku muutmine või liuguril klõpsamine määrab selle väärtuse kõigile valitud "
            L"kuvaritele.\r\n\r\nEELVAADE JA KASUTAMINE\r\nKäivitage FlightCorridor.scr Windowsi "
            L"ekraanisäästjana. Selle sätted on rakenduse omadest eraldi. Sätete eelvaade lubab täisekraanil "
            L"animatsiooni jooksvalt muuta. OK salvestab muudatused ning Loobu või Esc tühistab need. "
            L"Täisekraanil ekraanisäästjast väljumiseks vajutage klahvi või liigutage hiirt.\r\n\r\n"
            L"SÜSTEEMINÕUDED\r\nWindows 7–11 toetab kõiki funktsioone. Windows Vista SP2 jaoks tuleb "
            L"paigaldada värskendused KB971512 ja KB2117917. Vaja on Direct3D 11 tuge."
        },
    }),
    DefineLanguage(LANG_GA, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Gaeilge" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — rialuithe" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Socruithe FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Teanga:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Luas na beochana: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Eitilt do na monatóirí roghnaithe" },
        LocalizedText{ TXT_ENABLE_ALL, L"Cumasaigh uile" },
        LocalizedText{ TXT_DISABLE_ALL, L"Díchumasaigh uile" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Monatóir beochana" },
        LocalizedText{ TXT_MONITOR, L"Monatóir" },
        LocalizedText{ TXT_RESOLUTION, L"Taifeach" },
        LocalizedText{ TXT_POSITION, L"Suíomh" },
        LocalizedText{ TXT_PRIMARY, L"príomhúil" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Cealaigh" },
        LocalizedText{ TXT_START_RECORDING, L"Tosaigh taifeadadh…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Stop taifeadadh" },
        LocalizedText{ TXT_PAUSE, L"Cuir ar sos" },
        LocalizedText{ TXT_RESUME, L"Lean ar aghaidh" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Suiteáil spárálaí scáileáin" },
        LocalizedText{ TXT_EXIT, L"Scoir" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Tá an bheochan ar siúl…" },
        LocalizedText{ TXT_RECORDING, L"Tá taifeadadh MP4 ar siúl…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Sábháladh an taifeadadh." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Níorbh fhéidir taifeadadh MP4 a thosú." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Níor suiteáladh an spárálaí scáileáin." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Suiteáladh an spárálaí scáileáin." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Níorbh fhéidir an rindreálaí Direct3D a thúsú." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Eitilt idir ceithre dhromchla athraitheacha" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Eitilt trí thonnadóir athraitheach" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Stopfar an taifeadadh atá ar siúl má dhúntar an feidhmchlár."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Oscail an suíomh gréasáin %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Ní féidir an suíomh a oscailt sa bhrabhsálaí réamhshocraithe."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Níorbh fhéidir an URL a chóipeáil go dtí an ghearrthaisce."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Níorbh fhéidir an fhaisnéis a chóipeáil go dtí an ghearrthaisce."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Cumasaigh réamhamharc" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Díchumasaigh réamhamharc" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Tá an bheochan ar sos." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Cosc ar spárálaí scáileáin le linn beochana" },
        LocalizedText{ TXT_READY_STATUS, L"Réidh." },
        LocalizedText{ TXT_HELP, L"Cabhair" },
        LocalizedText{ TXT_ABOUT, L"Maidir leis" },
        LocalizedText{ TXT_CLOSE, L"Dún" },
        LocalizedText{ TXT_SNAPSHOT, L"Sábháil PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Sábháladh an íomhá PNG." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Níorbh fhéidir an íomhá PNG a shábháil." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Díshuiteáil spárálaí scáileáin" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Díshuiteáladh an spárálaí scáileáin." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Níorbh fhéidir an spárálaí scáileáin a dhíshuiteáil. Dún é agus a réamhamharc agus bain triail "
            L"eile as."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Dún fuinneog socruithe FlightCorridor agus bain triail eile as an díshuiteáil."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Dún fuinneog socruithe spárálaí scáileáin Windows agus bain triail eile as an díshuiteáil."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Dún an spárálaí scáileáin nó an réamhamharc lánscáileáin le Esc nó trí an luch a bhogadh agus "
            L"bain triail eile as."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Eitilt idir dromchlaí athraitheacha le luasghéarú crua-earraí."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Leagan:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Sprioc-ardán:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Suíomh gréasáin:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Oscail sa bhrabhsálaí réamhshocraithe" },
        LocalizedText{ TXT_COPY_URL, L"Cóipeáil an &seoladh" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Cóipeáil an &fhaisnéis" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Príomhsholas" },
        LocalizedText{ TXT_FILL_LIGHT, L"Solas líonta" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Solas comhthimpeallach" },
        LocalizedText{ TXT_RIM_LIGHT, L"Solas imill" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Uigeacht" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Rothlú saor an cheamara" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Sosanna agus aisiompuithe" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Níl acmhainn an cheadúnais ar fáil." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Samhail an mhonatóra" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Ráta athnuachana" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Doimhneacht ghiotán" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Formáid datha" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Spás datha" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u giotán/cainéal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u giotán/picteilín" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Socruithe taifeadta" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Taifeach:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Ráta frámaí:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Cuirfear na hathruithe i bhfeidhm ar an gcéad taifeadadh MP4 eile."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"BEOCHAN AGUS SOCRUITHE\r\nEitilt idir dromchlaí athraitheacha le luasghéarú crua-earraí. "
            L"Eitilt idir ceithre dhromchla athraitheacha; Eitilt trí thonnadóir athraitheach. Roghnaigh "
            L"beochan amháin do gach monatóir. Athraíonn Uigeacht idir dromchla uigeachtaithe agus samhail "
            L"sreangfhráma. Rothlaíonn rothlú saor an cheamara an radharc go mall sna trí thoise. Cuireann "
            L"Sosanna agus aisiompuithe coscánú, sosanna agus athruithe treo randamacha leis an rothlú; "
            L"leanann an eitilt chun tosaigh. Tá luas 0–1600% ar fáil. Tá radharc randamach neamhspleách ag "
            L"gach monatóir agus déantar rindreáil de réir a ráta athnuachana féin. Is féidir an "
            L"príomhsholas, an solas líonta, an solas comhthimpeallach agus an solas imill a athrú go "
            L"neamhspleách do na taispeántais roghnaithe. Ní bhaineann an soilsiú ach le dromchlaí "
            L"uigeachtaithe.\r\n\r\nTAISPEÁNTAIS\r\nRoghnaigh ró amháin nó níos mó sa liosta monatóirí. "
            L"Roghnaíonn Ctrl+A gach ró; úsáid Ctrl agus Shift chun an roghnú a athrú. Ní athraíonn "
            L"rialuithe agus sleamhnáin na beochana ach socruithe na monatóirí roghnaithe. Ní hionann ró a "
            L"roghnú agus aschur an mhonatóra a chumasú lena bhosca seiceála. Cuimhnítear an roghnú ar leith "
            L"don fheidhmchlár agus don spárálaí. Má bhí gach monatóir roghnaithe, cuirtear monatóirí nua "
            L"leis an roghnú freisin. Léirítear luachanna éagsúla ar na monatóirí roghnaithe le boscaí "
            L"seiceála i staid neamhchinnte agus le patrún poncanna ar chnaipí raidió, ar ghreimíní "
            L"sleamhnán agus ar na cnaipí “Cumasaigh uile” agus “Díchumasaigh uile”. Taispeántar dais ar "
            L"lipéad an tsleamhnáin in ionad luach coiteann. Nuair a athraítear rogha nó a chliceáiltear "
            L"sleamhnán, cuirtear an luach sin i bhfeidhm ar gach monatóir roghnaithe.\r\n\r\nRIALÚ\r\nRith "
            L"FlightCorridor.exe. Sábháiltear socruithe go leanúnach agus ní ritheann ach cóip amháin den "
            L"fheidhmchlár. Cumasaíonn nó díchumasaíonn bosca seiceála an mhonatóra nó déchliceáil ar a ró "
            L"an t-aschur beochana. Is féidir an bheochan a chur ar sos agus a atosú. Gabhann PNG agus MP4 "
            L"an chéad mhonatóir beochana gníomhach, ní na monatóirí uile le chéile. Ní féidir aschur "
            L"beochana an mhonatóra atá á thaifeadadh a dhíchumasú le linn taifeadta; teastaíonn deimhniú "
            L"chun an feidhmchlár a dhúnadh agus taifeadadh ar siúl. Baineann sos agus cosc an spárálaí "
            L"scáileáin leis an bhfeidhmchlár iomlán, beag beann ar na monatóirí roghnaithe. Nuair atá an "
            L"cosc cumasaithe, ní choisctear spárálaí scáileáin Windows ach fad a bhíonn beochan infheicthe "
            L"nach bhfuil ar sos ar mhonatóir amháin ar a laghad. Is féidir an spárálaí leabaithe a "
            L"shuiteáil nó a dhíshuiteáil ón bhfeidhmchlár.\r\n\r\nGABHÁLACHA SCÁILEÁIN AGUS TAIFEADADH\r\n"
            L"Roghnaigh Viewport nó TV i socruithe taifeadta. Coinníonn Viewport toisí agus ráta athnuachana "
            L"an mhonatóra, suas le 60 fráma sa soicind. Tairgeann TV 1920 × 1080, 1440 × 1080 nó 1280 × 720 "
            L"i gcóimheas 16:9 ag 50, 25, 59.94 (60000/1001) nó 29.97 (30000/1001) fráma sa soicind. Is "
            L"físeán forásach BT.709 é, le raon teoranta agus foshampláil datha 4:2:0. Coinnítear cóimheas "
            L"an phictiúir agus tá na barraí líonta dubh. Cuireann OK roghanna i bhfeidhm ar an gcéad "
            L"taifeadadh eile; cealaíonn Cealaigh nó Esc athruithe neamhdheimhnithe. Ní chuireann socruithe "
            L"taifeadta, Cabhair ná Maidir leis bac ar fhuinneoga eile agus is féidir iad a íoslaghdú. "
            L"Bogann Tab agus Shift+Tab an fócas; gníomhaíonn Enter an cnaipe faoi fhócas agus dúnann Esc an "
            L"fhuinneog chúnta ghníomhach.\r\n\r\nRIACHTANAIS CHÓRAIS\r\nTacaíonn Windows 7–11 leis na "
            L"gnéithe uile. Ar Windows Vista SP2 ní mór nuashonruithe KB971512 agus KB2117917 a shuiteáil; "
            L"ní oibríonn taifeadadh MP4 ar Vista. Teastaíonn tacaíocht Direct3D 11, agus Media Foundation "
            L"agus ionchódóir H.264 le haghaidh MP4. Tá an comhéadan agus an doiciméadú ar fáil i 36 teanga."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"BEOCHAN AGUS SOCRUITHE\r\nEitilt idir dromchlaí athraitheacha le luasghéarú crua-earraí. "
            L"Eitilt idir ceithre dhromchla athraitheacha; Eitilt trí thonnadóir athraitheach. Roghnaigh "
            L"beochan amháin do gach monatóir. Athraíonn Uigeacht idir dromchla uigeachtaithe agus samhail "
            L"sreangfhráma. Rothlaíonn rothlú saor an cheamara an radharc go mall sna trí thoise. Cuireann "
            L"Sosanna agus aisiompuithe coscánú, sosanna agus athruithe treo randamacha leis an rothlú; "
            L"leanann an eitilt chun tosaigh. Tá luas 0–1600% ar fáil. Tá radharc randamach neamhspleách ag "
            L"gach monatóir agus déantar rindreáil de réir a ráta athnuachana féin. Is féidir an "
            L"príomhsholas, an solas líonta, an solas comhthimpeallach agus an solas imill a athrú go "
            L"neamhspleách do na taispeántais roghnaithe. Ní bhaineann an soilsiú ach le dromchlaí "
            L"uigeachtaithe.\r\n\r\nTAISPEÁNTAIS\r\nRoghnaigh ró amháin nó níos mó sa liosta monatóirí. "
            L"Roghnaíonn Ctrl+A gach ró; úsáid Ctrl agus Shift chun an roghnú a athrú. Ní athraíonn "
            L"rialuithe agus sleamhnáin na beochana ach socruithe na monatóirí roghnaithe. Ní hionann ró a "
            L"roghnú agus aschur an mhonatóra a chumasú lena bhosca seiceála. Cuimhnítear an roghnú ar leith "
            L"don fheidhmchlár agus don spárálaí. Má bhí gach monatóir roghnaithe, cuirtear monatóirí nua "
            L"leis an roghnú freisin. Léirítear luachanna éagsúla ar na monatóirí roghnaithe le boscaí "
            L"seiceála i staid neamhchinnte agus le patrún poncanna ar chnaipí raidió, ar ghreimíní "
            L"sleamhnán agus ar na cnaipí “Cumasaigh uile” agus “Díchumasaigh uile”. Taispeántar dais ar "
            L"lipéad an tsleamhnáin in ionad luach coiteann. Nuair a athraítear rogha nó a chliceáiltear "
            L"sleamhnán, cuirtear an luach sin i bhfeidhm ar gach monatóir roghnaithe.\r\n\r\nRÉAMHAMHARC "
            L"AGUS RIALÚ\r\nÚsáid FlightCorridor.scr mar spárálaí scáileáin Windows. Tá a shocruithe ar "
            L"leith ó shocruithe an fheidhmchláir. Ceadaíonn an réamhamharc lánscáileáin athruithe beo. "
            L"Sábhálann OK agus cealaíonn Cealaigh nó Esc na hathruithe. Fág an spárálaí lánscáileáin le "
            L"heochair ar bith nó le gluaiseacht na luiche.\r\n\r\nRIACHTANAIS CHÓRAIS\r\nTacaíonn Windows "
            L"7–11 leis na gnéithe uile. Ar Windows Vista SP2 ní mór nuashonruithe KB971512 agus KB2117917 a "
            L"shuiteáil. Teastaíonn tacaíocht Direct3D 11."
        },
    }),
    DefineLanguage(LANG_LT, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Lietuvių" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — valdymas" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlightCorridor nuostatos" },
        LocalizedText{ TXT_LANGUAGE, L"Kalba:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Animacijos greitis: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Skrydis pasirinktuose monitoriuose" },
        LocalizedText{ TXT_ENABLE_ALL, L"Įjungti visus" },
        LocalizedText{ TXT_DISABLE_ALL, L"Išjungti visus" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Animacijos monitorius" },
        LocalizedText{ TXT_MONITOR, L"Monitorius" },
        LocalizedText{ TXT_RESOLUTION, L"Skiriamoji geba" },
        LocalizedText{ TXT_POSITION, L"Padėtis" },
        LocalizedText{ TXT_PRIMARY, L"pagrindinis" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Atšaukti" },
        LocalizedText{ TXT_START_RECORDING, L"Pradėti įrašymą…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Baigti įrašymą" },
        LocalizedText{ TXT_PAUSE, L"Pristabdyti" },
        LocalizedText{ TXT_RESUME, L"Tęsti" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Įdiegti ekrano užsklandą" },
        LocalizedText{ TXT_EXIT, L"Išeiti" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animacija vyksta…" },
        LocalizedText{ TXT_RECORDING, L"Vyksta MP4 įrašymas…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Įrašas išsaugotas." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Nepavyko pradėti MP4 įrašymo." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Ekrano užsklanda neįdiegta." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Ekrano užsklanda įdiegta." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Nepavyko inicijuoti Direct3D atvaizdavimo modulio." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Skrydis tarp keturių kintančių paviršių" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Skrydis kintančiu piltuvu" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Uždarius programą bus sustabdytas vykstantis įrašymas."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Atidaryti svetainę %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Nepavyko atverti svetainės numatytojoje naršyklėje." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Nepavyko nukopijuoti URL į iškarpinę." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Nepavyko nukopijuoti informacijos į iškarpinę." },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Įjungti peržiūrą" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Išjungti peržiūrą" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animacija pristabdyta." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Animacijos metu neleisti ekrano užsklandos" },
        LocalizedText{ TXT_READY_STATUS, L"Parengta." },
        LocalizedText{ TXT_HELP, L"Žinynas" },
        LocalizedText{ TXT_ABOUT, L"Apie" },
        LocalizedText{ TXT_CLOSE, L"Uždaryti" },
        LocalizedText{ TXT_SNAPSHOT, L"Išsaugoti PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"PNG vaizdas išsaugotas." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Nepavyko išsaugoti PNG vaizdo." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Pašalinti ekrano užsklandą" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Ekrano užsklanda pašalinta." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Nepavyko pašalinti ekrano užsklandos. Uždarykite ją bei jos peržiūrą ir bandykite dar kartą."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Uždarykite FlightCorridor nuostatų langą ir bandykite pašalinti dar kartą."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Uždarykite Windows ekrano užsklandos nuostatų langą ir bandykite pašalinti dar kartą."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Užbaikite užsklandą arba viso ekrano peržiūrą klavišu Esc ar pajudindami pelę ir bandykite "
            L"pašalinti dar kartą."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Aparatine įranga spartinamas skrydis tarp kintančių paviršių."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versija:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Tikslinė platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Svetainė:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Atidaryti numatytojoje naršyklėje" },
        LocalizedText{ TXT_COPY_URL, L"Kopijuoti &adresą" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopijuoti &informaciją" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Pagrindinė šviesa" },
        LocalizedText{ TXT_FILL_LIGHT, L"Užpildanti šviesa" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Aplinkos šviesa" },
        LocalizedText{ TXT_RIM_LIGHT, L"Kontūrinė šviesa" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Tekstūra" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Laisvas kameros sukimasis" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauzės ir apsisukimai" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Licencijos išteklius nepasiekiamas." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Monitoriaus modelis" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Atnaujinimo dažnis" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bitų gylis" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Spalvų formatas" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Spalvų erdvė" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bitų/kanalą" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bitų/pikselį" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Įrašymo nuostatos" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Skiriamoji geba:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Kadrų dažnis:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Pakeitimai bus taikomi kitam MP4 įrašui." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMACIJA IR NUOSTATOS\r\nAparatine įranga spartinamas skrydis tarp kintančių paviršių. "
            L"Skrydis tarp keturių kintančių paviršių; Skrydis kintančiu piltuvu. Kiekvienam monitoriui "
            L"pasirinkite vieną animaciją. Tekstūros langelis perjungia tekstūruotą paviršių ir vielinį "
            L"modelį. Laisvas kameros sukimasis lėtai keičia žiūrėjimo kryptį visose trijose dimensijose. "
            L"Pauzės ir apsisukimai prideda atsitiktinį lėtėjimą, pauzes ir sukimosi krypties keitimą; "
            L"skrydis pirmyn tęsiasi. Galimas 0–1600% greitis. Kiekvienas monitorius turi nepriklausomą "
            L"atsitiktinę sceną, atvaizduojamą jo atnaujinimo dažniu. Pagrindinę, užpildančią, aplinkos ir "
            L"kontūrinę šviesą galima atskirai įjungti pasirinktiems ekranams. Apšvietimas taikomas tik "
            L"tekstūruotiems paviršiams.\r\n\r\nMONITORIAI\r\nMonitorių sąraše pasirinkite vieną ar kelias "
            L"eilutes. Ctrl+A pasirenka visas, o Ctrl ir Shift leidžia keisti pasirinkimą. Animacijos "
            L"valdikliai ir slankikliai keičia tik pasirinktų monitorių nuostatas. Eilutės pasirinkimas nėra "
            L"tas pats, kas animacijos išvesties įjungimas jos žymimuoju langeliu. Pasirinkimas atskirai "
            L"įsimenamas programai ir užsklandai. Jei buvo pasirinkti visi monitoriai, į pasirinkimą "
            L"įtraukiami ir naujai prijungti monitoriai. Skirtingas pasirinktų monitorių reikšmes rodo "
            L"neapibrėžta žymimųjų langelių būsena ir taškinis raštas ant parinkčių mygtukų, slankiklių "
            L"rankenėlių bei mygtukų „Įjungti visus“ ir „Išjungti visus“. Slankiklių užrašuose vietoj "
            L"bendros reikšmės rodomas brūkšnys. Pakeitus parinktį arba spustelėjus slankiklį, ta reikšmė "
            L"pritaikoma visiems pasirinktiems monitoriams.\r\n\r\nVALDYMAS\r\nPaleiskite "
            L"FlightCorridor.exe. Nuostatos išsaugomos nuolat, veikia tik vienas programos egzempliorius. "
            L"Monitoriaus langelis arba dvigubas eilutės spustelėjimas įjungia ar išjungia animacijos "
            L"išvestį. Animaciją galima pristabdyti ir tęsti. PNG ir MP4 fiksuoja pirmą aktyvų animacijos "
            L"monitorių, o ne bendrą visų monitorių vaizdą. Įrašymo metu negalima išjungti įrašomo "
            L"monitoriaus animacijos išvesties; uždarant programą vykstant įrašymui reikia patvirtinimo. "
            L"Pristabdymas ir užsklandos blokavimas taikomi visai programai, nepriklausomai nuo monitorių "
            L"pasirinkimo. Įjungus blokavimą, Windows užsklanda neleidžiama tik kol bent viename monitoriuje "
            L"matoma nepristabdyta animacija. Programa gali įdiegti ir pašalinti į ją įtrauktą užsklandą.\r\n"
            L"\r\nEKRANO KOPIJOS IR ĮRAŠYMAS\r\nĮrašymo nuostatose pasirinkite Viewport arba TV. Viewport "
            L"išsaugo monitoriaus matmenis ir atnaujinimo dažnį iki 60 kadrų per sekundę. TV siūlo 1920 × "
            L"1080, 1440 × 1080 arba 1280 × 720 išvestį 16:9 santykiu bei 50, 25, 59.94 (60000/1001) arba "
            L"29.97 (30000/1001) kadrų per sekundę. TV vaizdas progresinis, BT.709, riboto diapazono ir "
            L"4:2:0 spalvų diskretizavimo. Vaizdo proporcijos išlieka, užpildymo juostos juodos. OK pritaiko "
            L"nuostatas kitam įrašui, Atšaukti arba Esc atmeta nepatvirtintus pakeitimus. Įrašymo, žinyno ir "
            L"informacijos langai neblokuoja kitų langų ir gali būti sumažinti. Tab ir Shift+Tab keičia "
            L"įvesties vietą, Enter paspaudžia aktyvų mygtuką, Esc uždaro aktyvų papildomą langą.\r\n\r\n"
            L"SISTEMOS REIKALAVIMAI\r\nWindows 7–11 palaiko visas funkcijas. Windows Vista SP2 būtina "
            L"įdiegti naujinimus KB971512 ir KB2117917; MP4 įrašymas Vistoje neveikia. Reikalingas Direct3D "
            L"11 palaikymas, o MP4 įrašymui Media Foundation ir H.264 koduotuvas. Sąsaja ir dokumentacija "
            L"pateikiamos 36 kalbomis."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACIJA IR NUOSTATOS\r\nAparatine įranga spartinamas skrydis tarp kintančių paviršių. "
            L"Skrydis tarp keturių kintančių paviršių; Skrydis kintančiu piltuvu. Kiekvienam monitoriui "
            L"pasirinkite vieną animaciją. Tekstūros langelis perjungia tekstūruotą paviršių ir vielinį "
            L"modelį. Laisvas kameros sukimasis lėtai keičia žiūrėjimo kryptį visose trijose dimensijose. "
            L"Pauzės ir apsisukimai prideda atsitiktinį lėtėjimą, pauzes ir sukimosi krypties keitimą; "
            L"skrydis pirmyn tęsiasi. Galimas 0–1600% greitis. Kiekvienas monitorius turi nepriklausomą "
            L"atsitiktinę sceną, atvaizduojamą jo atnaujinimo dažniu. Pagrindinę, užpildančią, aplinkos ir "
            L"kontūrinę šviesą galima atskirai įjungti pasirinktiems ekranams. Apšvietimas taikomas tik "
            L"tekstūruotiems paviršiams.\r\n\r\nMONITORIAI\r\nMonitorių sąraše pasirinkite vieną ar kelias "
            L"eilutes. Ctrl+A pasirenka visas, o Ctrl ir Shift leidžia keisti pasirinkimą. Animacijos "
            L"valdikliai ir slankikliai keičia tik pasirinktų monitorių nuostatas. Eilutės pasirinkimas nėra "
            L"tas pats, kas animacijos išvesties įjungimas jos žymimuoju langeliu. Pasirinkimas atskirai "
            L"įsimenamas programai ir užsklandai. Jei buvo pasirinkti visi monitoriai, į pasirinkimą "
            L"įtraukiami ir naujai prijungti monitoriai. Skirtingas pasirinktų monitorių reikšmes rodo "
            L"neapibrėžta žymimųjų langelių būsena ir taškinis raštas ant parinkčių mygtukų, slankiklių "
            L"rankenėlių bei mygtukų „Įjungti visus“ ir „Išjungti visus“. Slankiklių užrašuose vietoj "
            L"bendros reikšmės rodomas brūkšnys. Pakeitus parinktį arba spustelėjus slankiklį, ta reikšmė "
            L"pritaikoma visiems pasirinktiems monitoriams.\r\n\r\nPERŽIŪRA IR VALDYMAS\r\nNaudokite "
            L"FlightCorridor.scr kaip Windows ekrano užsklandą. Jos nuostatos atskiros nuo programos. Viso "
            L"ekrano peržiūra leidžia jas keisti vykstant animacijai. OK išsaugo, Atšaukti arba Esc atmeta "
            L"pakeitimus. Užsklandą užbaikite klavišu arba pajudindami pelę.\r\n\r\nSISTEMOS REIKALAVIMAI\r\n"
            L"Windows 7–11 palaiko visas funkcijas. Windows Vista SP2 būtina įdiegti naujinimus KB971512 ir "
            L"KB2117917. Reikalingas Direct3D 11 palaikymas."
        },
    }),
    DefineLanguage(LANG_LV, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Latviešu" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — vadība" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlightCorridor iestatījumi" },
        LocalizedText{ TXT_LANGUAGE, L"Valoda:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Animācijas ātrums: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Lidojums atlasītajos monitoros" },
        LocalizedText{ TXT_ENABLE_ALL, L"Ieslēgt visu" },
        LocalizedText{ TXT_DISABLE_ALL, L"Izslēgt visu" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Animācijas monitors" },
        LocalizedText{ TXT_MONITOR, L"Monitors" },
        LocalizedText{ TXT_RESOLUTION, L"Izšķirtspēja" },
        LocalizedText{ TXT_POSITION, L"Pozīcija" },
        LocalizedText{ TXT_PRIMARY, L"galvenais" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Atcelt" },
        LocalizedText{ TXT_START_RECORDING, L"Sākt ierakstīšanu…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Beigt ierakstīšanu" },
        LocalizedText{ TXT_PAUSE, L"Pauzēt" },
        LocalizedText{ TXT_RESUME, L"Turpināt" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Instalēt ekrānsaudzētāju" },
        LocalizedText{ TXT_EXIT, L"Iziet" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animācija darbojas…" },
        LocalizedText{ TXT_RECORDING, L"Notiek MP4 ierakstīšana…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Ieraksts ir saglabāts." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Neizdevās sākt MP4 ierakstīšanu." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Ekrānsaudzētājs netika instalēts." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Ekrānsaudzētājs ir instalēts." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Neizdevās inicializēt Direct3D renderētāju." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Lidojums starp četrām mainīgām virsmām" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Lidojums caur mainīgu piltuvi" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Aizverot lietotni, tiks pārtraukts pašreizējais ieraksts."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Atvērt tīmekļa vietni %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Nevar atvērt vietni noklusējuma pārlūkā." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Neizdevās kopēt URL starpliktuvē." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Neizdevās kopēt informāciju starpliktuvē." },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Ieslēgt priekšskatījumu" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Izslēgt priekšskatījumu" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animācija ir pauzēta." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Animācijas laikā bloķēt ekrānsaudzētāju" },
        LocalizedText{ TXT_READY_STATUS, L"Gatavs." },
        LocalizedText{ TXT_HELP, L"Palīdzība" },
        LocalizedText{ TXT_ABOUT, L"Par programmu" },
        LocalizedText{ TXT_CLOSE, L"Aizvērt" },
        LocalizedText{ TXT_SNAPSHOT, L"Saglabāt PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"PNG attēls ir saglabāts." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Neizdevās saglabāt PNG attēlu." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Atinstalēt ekrānsaudzētāju" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Ekrānsaudzētājs ir atinstalēts." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Neizdevās atinstalēt ekrānsaudzētāju. Aizveriet to un tā priekšskatījumu un mēģiniet vēlreiz."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Aizveriet FlightCorridor iestatījumu logu un atkārtojiet atinstalēšanu."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Aizveriet Windows ekrānsaudzētāja iestatījumu logu un atkārtojiet atinstalēšanu."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Aizveriet ekrānsaudzētāju vai pilnekrāna priekšskatījumu ar Esc vai peles kustību un "
            L"atkārtojiet atinstalēšanu."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Aparatūras paātrināts lidojums starp mainīgām virsmām." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versija:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Mērķa platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Tīmekļa vietne:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Atvērt noklusējuma pārlūkprogrammā" },
        LocalizedText{ TXT_COPY_URL, L"Kopēt &adresi" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopēt &informāciju" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Galvenā gaisma" },
        LocalizedText{ TXT_FILL_LIGHT, L"Papildu gaisma" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Apkārtējā gaisma" },
        LocalizedText{ TXT_RIM_LIGHT, L"Kontūru gaisma" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Tekstūra" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Brīva kameras rotācija" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauzes un virzienmaiņa" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Licences resurss nav pieejams." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Monitora modelis" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Atsvaidzināšanas frekvence" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bitu dziļums" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Krāsu formāts" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Krāstelpa" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u biti/kanālā" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u biti/pikselī" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Ieraksta iestatījumi" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Izšķirtspēja:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Kadru ātrums:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Izmaiņas attieksies uz nākamo MP4 ierakstu." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMĀCIJA UN IESTATĪJUMI\r\nAparatūras paātrināts lidojums starp mainīgām virsmām. Lidojums "
            L"starp četrām mainīgām virsmām; Lidojums caur mainīgu piltuvi. Katram monitoram izvēlieties "
            L"tieši vienu animāciju. Tekstūras rūtiņa pārslēdz teksturētu virsmu un stiepļu modeli. Brīva "
            L"kameras rotācija lēnām maina skatiena virzienu visās trijās dimensijās. Pauzes un virzienmaiņa "
            L"pievieno nejaušu palēninājumu, pauzes un rotācijas virziena maiņu; lidojums uz priekšu "
            L"turpinās. Pieejams ātrums 0–1600%. Katram monitoram ir neatkarīga nejauša aina, ko renderē tā "
            L"atsvaidzināšanas frekvencē. Pamata, aizpildošo, apkārtējo un kontūru gaismu atlasītajiem "
            L"monitoriem var ieslēgt neatkarīgi. Apgaismojums attiecas tikai uz teksturētām virsmām.\r\n\r\n"
            L"MONITORI\r\nMonitoru sarakstā atlasiet vienu vai vairākas rindas. Ctrl+A atlasa visas, bet "
            L"Ctrl un Shift ļauj mainīt atlasi. Animācijas vadīklas un slīdņi maina tikai atlasīto monitoru "
            L"iestatījumus. Rindas atlasīšana nav tas pats, kas animācijas izvades ieslēgšana ar izvēles "
            L"rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un ekrānsaudzētājam. Ja bija atlasīti visi "
            L"monitori, atlasē iekļauj arī jaunpievienotos monitorus. Atšķirīgas vērtības atlasītajos "
            L"monitoros norāda nenoteikts izvēles rūtiņu stāvoklis un punktots raksts uz radiopogām, slīdņu "
            L"rokturiem un pogām „Ieslēgt visu” un „Izslēgt visu”. Slīdņu etiķetēs kopīgas vērtības vietā "
            L"redzama domuzīme. Mainot iespēju vai noklikšķinot uz slīdņa, šī vērtība tiek piemērota visiem "
            L"atlasītajiem monitoriem.\r\n\r\nLIETOŠANA\r\nPalaidiet FlightCorridor.exe. Iestatījumi tiek "
            L"saglabāti nepārtraukti, un darbojas tikai viena lietotnes instance. Monitora rūtiņa vai "
            L"dubultklikšķis uz rindas ieslēdz vai izslēdz tā animācijas izvadi. Animāciju var pauzēt un "
            L"turpināt. PNG un MP4 uzņem pirmo aktīvo animācijas monitoru, nevis visu monitoru kopējo "
            L"attēlu. Ierakstīšanas laikā nevar izslēgt ierakstāmā monitora animācijas izvadi; aizverot "
            L"lietotni ieraksta laikā, nepieciešams apstiprinājums. Pauze un ekrānsaudzētāja bloķēšana "
            L"attiecas uz visu lietotni neatkarīgi no monitoru atlases. Ja bloķēšana ir ieslēgta, Windows "
            L"ekrānsaudzētājs tiek bloķēts tikai tik ilgi, kamēr vismaz vienā monitorā ir redzama nepauzēta "
            L"animācija. Lietotne var instalēt vai atinstalēt tajā iebūvēto ekrānsaudzētāju.\r\n\r\n"
            L"EKRĀNUZŅĒMUMI UN IERAKSTĪŠANA\r\nIeraksta iestatījumos izvēlieties Viewport vai TV. Viewport "
            L"saglabā monitora izmērus un atsvaidzināšanas frekvenci līdz 60 kadriem sekundē. TV piedāvā "
            L"1920 × 1080, 1440 × 1080 vai 1280 × 720 izvadi ar 16:9 malu attiecību un 50, 25, 59.94 "
            L"(60000/1001) vai 29.97 (30000/1001) kadriem sekundē. TV video ir progresīvs BT.709 ar "
            L"ierobežotu diapazonu un 4:2:0 krāsu apakšiztveršanu. Attēla proporcijas saglabājas, "
            L"aizpildījuma joslas ir melnas. OK piemēro izvēles nākamajam ierakstam, Atcelt vai Esc atmet "
            L"neapstiprinātās izmaiņas. Ieraksta iestatījumu, palīdzības un informācijas logi nebloķē citus "
            L"logus un ir minimizējami. Tab un Shift+Tab pārvieto fokusu, Enter aktivizē fokusēto pogu, Esc "
            L"aizver aktīvo palīglogu.\r\n\r\nSISTĒMAS PRASĪBAS\r\nWindows 7–11 atbalsta visas funkcijas. "
            L"Windows Vista SP2 jāinstalē atjauninājumi KB971512 un KB2117917; MP4 ierakstīšana Vistā "
            L"nedarbojas. Nepieciešams Direct3D 11 atbalsts, bet MP4 vajadzīgi Media Foundation un H.264 "
            L"kodētājs. Saskarne un dokumentācija ir pieejama 36 valodās."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMĀCIJA UN IESTATĪJUMI\r\nAparatūras paātrināts lidojums starp mainīgām virsmām. Lidojums "
            L"starp četrām mainīgām virsmām; Lidojums caur mainīgu piltuvi. Katram monitoram izvēlieties "
            L"tieši vienu animāciju. Tekstūras rūtiņa pārslēdz teksturētu virsmu un stiepļu modeli. Brīva "
            L"kameras rotācija lēnām maina skatiena virzienu visās trijās dimensijās. Pauzes un virzienmaiņa "
            L"pievieno nejaušu palēninājumu, pauzes un rotācijas virziena maiņu; lidojums uz priekšu "
            L"turpinās. Pieejams ātrums 0–1600%. Katram monitoram ir neatkarīga nejauša aina, ko renderē tā "
            L"atsvaidzināšanas frekvencē. Pamata, aizpildošo, apkārtējo un kontūru gaismu atlasītajiem "
            L"monitoriem var ieslēgt neatkarīgi. Apgaismojums attiecas tikai uz teksturētām virsmām.\r\n\r\n"
            L"MONITORI\r\nMonitoru sarakstā atlasiet vienu vai vairākas rindas. Ctrl+A atlasa visas, bet "
            L"Ctrl un Shift ļauj mainīt atlasi. Animācijas vadīklas un slīdņi maina tikai atlasīto monitoru "
            L"iestatījumus. Rindas atlasīšana nav tas pats, kas animācijas izvades ieslēgšana ar izvēles "
            L"rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un ekrānsaudzētājam. Ja bija atlasīti visi "
            L"monitori, atlasē iekļauj arī jaunpievienotos monitorus. Atšķirīgas vērtības atlasītajos "
            L"monitoros norāda nenoteikts izvēles rūtiņu stāvoklis un punktots raksts uz radiopogām, slīdņu "
            L"rokturiem un pogām „Ieslēgt visu” un „Izslēgt visu”. Slīdņu etiķetēs kopīgas vērtības vietā "
            L"redzama domuzīme. Mainot iespēju vai noklikšķinot uz slīdņa, šī vērtība tiek piemērota visiem "
            L"atlasītajiem monitoriem.\r\n\r\nPRIEKŠSKATĪJUMS UN LIETOŠANA\r\nIzmantojiet FlightCorridor.scr "
            L"kā Windows ekrānsaudzētāju. Tā iestatījumi ir atsevišķi no lietotnes. Pilnekrāna "
            L"priekšskatījums ļauj tos mainīt animācijas darbības laikā. OK saglabā, Atcelt vai Esc atmet "
            L"izmaiņas. Pilnekrāna ekrānsaudzētāju aizveriet ar taustiņu vai peles kustību.\r\n\r\nSISTĒMAS "
            L"PRASĪBAS\r\nWindows 7–11 atbalsta visas funkcijas. Windows Vista SP2 jāinstalē atjauninājumi "
            L"KB971512 un KB2117917. Nepieciešams Direct3D 11 atbalsts."
        },
    }),
    DefineLanguage(LANG_HU, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Magyar" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — vezérlés" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlightCorridor beállításai" },
        LocalizedText{ TXT_LANGUAGE, L"Nyelv:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Animáció sebessége: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Kijelölt monitorok repülési módja" },
        LocalizedText{ TXT_ENABLE_ALL, L"Mind bekapcsolása" },
        LocalizedText{ TXT_DISABLE_ALL, L"Mind kikapcsolása" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Animációs monitor" },
        LocalizedText{ TXT_MONITOR, L"Monitor" },
        LocalizedText{ TXT_RESOLUTION, L"Felbontás" },
        LocalizedText{ TXT_POSITION, L"Pozíció" },
        LocalizedText{ TXT_PRIMARY, L"elsődleges" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Mégse" },
        LocalizedText{ TXT_START_RECORDING, L"Felvétel indítása…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Felvétel leállítása" },
        LocalizedText{ TXT_PAUSE, L"Szünet" },
        LocalizedText{ TXT_RESUME, L"Folytatás" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Képernyőkímélő telepítése" },
        LocalizedText{ TXT_EXIT, L"Kilépés" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Az animáció fut…" },
        LocalizedText{ TXT_RECORDING, L"MP4-felvétel folyamatban…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"A felvétel mentve." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Az MP4-felvétel nem indítható." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"A képernyőkímélő nem lett telepítve." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"A képernyőkímélő telepítve." },
        LocalizedText{ TXT_RENDERER_FAILED, L"A Direct3D megjelenítő inicializálása sikertelen." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Repülés négy változó felület között" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Repülés változó tölcsérben" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Az alkalmazás bezárása leállítja a folyamatban lévő felvételt."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Webhely megnyitása: %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"A webhely nem nyitható meg az alapértelmezett böngészőben."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Az URL nem másolható a vágólapra." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Az információ nem másolható a vágólapra." },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Előnézet bekapcsolása" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Előnézet kikapcsolása" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Az animáció szünetel." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Képernyőkímélő tiltása animáció közben" },
        LocalizedText{ TXT_READY_STATUS, L"Kész." },
        LocalizedText{ TXT_HELP, L"Súgó" },
        LocalizedText{ TXT_ABOUT, L"Névjegy" },
        LocalizedText{ TXT_CLOSE, L"Bezárás" },
        LocalizedText{ TXT_SNAPSHOT, L"PNG mentése…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"A PNG-kép mentve." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"A PNG-kép mentése sikertelen." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Képernyőkímélő eltávolítása" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"A képernyőkímélő eltávolítva." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"A képernyőkímélő nem távolítható el. Zárja be a képernyőkímélőt és az előnézetét, majd "
            L"próbálja újra."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Zárja be a FlightCorridor beállítási ablakát, majd próbálja újra az eltávolítást."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zárja be a Windows képernyőkímélő-beállításait, majd próbálja újra az eltávolítást."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Lépjen ki a képernyőkímélőből vagy a teljes képernyős előnézetből az Esc billentyűvel vagy az "
            L"egér mozgatásával, majd próbálja újra."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardveresen gyorsított repülés változó felületek között." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Verzió:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Célplatform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Webhely:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Megnyitás az alapértelmezett böngészőben" },
        LocalizedText{ TXT_COPY_URL, L"&Cím másolása" },
        LocalizedText{ TXT_COPY_INFORMATION, L"&Információ másolása" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Főfény" },
        LocalizedText{ TXT_FILL_LIGHT, L"Derítőfény" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Környezeti fény" },
        LocalizedText{ TXT_RIM_LIGHT, L"Peremfény" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Textúra" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"A kamera szabad forgása" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Szünetek és irányváltás" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"A licenc erőforrása nem érhető el." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Monitor típusa" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Frissítési gyakoriság" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bitmélység" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Színformátum" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Színtér" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bit/csatorna" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bit/képpont" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Felvételi beállítások" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Felbontás:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Képkockasebesség:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"A módosítások a következő MP4-felvételre érvényesek." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMÁCIÓ ÉS BEÁLLÍTÁSOK\r\nHardveresen gyorsított repülés változó felületek között. Repülés "
            L"négy változó felület között; Repülés változó tölcsérben. Monitoronként pontosan egy animáció "
            L"választható. A Textúra jelölőnégyzet a textúrázott felület és a drótváz között vált. A kamera "
            L"szabad forgása lassan változtatja a nézetet mindhárom dimenzióban. A Szünetek és irányváltás "
            L"véletlenszerű lassításokat, szüneteket és forgásirányváltásokat ad hozzá; az előrehaladás "
            L"folytatódik. A sebesség 0–1600%. Minden monitor önálló véletlenszerű jelenetet kap, saját "
            L"frissítési gyakoriságához igazodó megjelenítéssel. A főfény, a derítőfény, a környezeti fény "
            L"és a peremfény külön kapcsolható a kijelölt monitorokon. A világítás csak a textúrázott "
            L"felületekre vonatkozik.\r\n\r\nMONITOROK\r\nJelöljön ki egy vagy több sort a monitorok "
            L"listájában. A Ctrl+A mindet kijelöli; a Ctrl és a Shift módosítja a kijelölést. Az animáció "
            L"vezérlői és csúszkái csak a kijelölt monitorok beállításait változtatják. A sor kijelölése és "
            L"az animációs kimenet jelölőnégyzetes engedélyezése külön művelet. A kijelölést az alkalmazás "
            L"és a képernyőkímélő külön megjegyzi. Ha korábban minden monitor ki volt jelölve, az újonnan "
            L"csatlakoztatott monitorok is bekerülnek a kijelölésbe. A kijelölt monitorok eltérő értékeit a "
            L"jelölőnégyzetek határozatlan állapota, valamint a választógombok, a csúszkafogantyúk és az "
            L"„Mind bekapcsolása” és „Mind kikapcsolása” gombok pontozása jelzi. A csúszkák felirata közös "
            L"érték helyett gondolatjelet mutat. Egy beállítás módosítása vagy a csúszkára kattintás az "
            L"adott értéket minden kijelölt monitorra alkalmazza.\r\n\r\nKEZELÉS\r\nIndítsa el a "
            L"FlightCorridor.exe fájlt. A beállítások folyamatosan mentődnek, és csak egy alkalmazáspéldány "
            L"fut. A monitor jelölőnégyzete vagy a sorra történő dupla kattintás kapcsolja az animációs "
            L"kimenetet. Az animáció szüneteltethető és folytatható. A PNG és az MP4 az első aktív animációs "
            L"monitort rögzíti, nem az összes monitor egyesített képét. A rögzített monitor animációs "
            L"kimenete felvétel közben nem kapcsolható ki; az alkalmazás bezárásához ekkor megerősítés "
            L"szükséges. A szüneteltetés és a képernyőkímélő tiltása a teljes alkalmazásra vonatkozik, a "
            L"monitorok kijelölésétől függetlenül. Bekapcsolt tiltás esetén a Windows képernyőkímélője csak "
            L"addig nem indul el, amíg legalább egy monitoron látható, nem szünetelő animáció fut. Az "
            L"alkalmazás telepítheti és eltávolíthatja a beágyazott képernyőkímélőt.\r\n\r\nKÉPERNYŐKÉPEK ÉS "
            L"FELVÉTEL\r\nA felvételi beállításoknál Viewport vagy TV választható. A Viewport megőrzi a "
            L"monitor képméretét és frissítési gyakoriságát, legfeljebb 60 képkocka/másodpercig. A TV "
            L"felbontása 1920 × 1080, 1440 × 1080 vagy 1280 × 720, képaránya 16:9; sebessége 50, 25, 59.94 "
            L"(60000/1001) vagy 29.97 (30000/1001) képkocka/másodperc. A TV videó progresszív BT.709, "
            L"korlátozott tartománnyal és 4:2:0 színmintavételezéssel. A kép arányai megmaradnak, a "
            L"kitöltősávok feketék. Az OK a következő felvételhez menti a választást; a Mégse vagy Esc "
            L"elveti a nem jóváhagyott módosításokat. A felvételi beállítások, a Súgó és a Névjegy nem "
            L"blokkolja a többi ablakot és kis méretűre állítható. A Tab és Shift+Tab mozgatja a fókuszt, az "
            L"Enter aktiválja a fókuszban levő gombot, az Esc bezárja az aktív kiegészítő ablakot.\r\n\r\n"
            L"RENDSZERKÖVETELMÉNYEK\r\nA Windows 7–11 minden funkciót támogat. Windows Vista SP2 alatt "
            L"telepíteni kell a KB971512 és KB2117917 frissítést; az MP4-felvétel Vistán nem működik. "
            L"Direct3D 11 támogatás szükséges, az MP4-hez Media Foundation és H.264-kódoló is kell. A "
            L"kezelőfelület és a dokumentáció 36 nyelven érhető el."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMÁCIÓ ÉS BEÁLLÍTÁSOK\r\nHardveresen gyorsított repülés változó felületek között. Repülés "
            L"négy változó felület között; Repülés változó tölcsérben. Monitoronként pontosan egy animáció "
            L"választható. A Textúra jelölőnégyzet a textúrázott felület és a drótváz között vált. A kamera "
            L"szabad forgása lassan változtatja a nézetet mindhárom dimenzióban. A Szünetek és irányváltás "
            L"véletlenszerű lassításokat, szüneteket és forgásirányváltásokat ad hozzá; az előrehaladás "
            L"folytatódik. A sebesség 0–1600%. Minden monitor önálló véletlenszerű jelenetet kap, saját "
            L"frissítési gyakoriságához igazodó megjelenítéssel. A főfény, a derítőfény, a környezeti fény "
            L"és a peremfény külön kapcsolható a kijelölt monitorokon. A világítás csak a textúrázott "
            L"felületekre vonatkozik.\r\n\r\nMONITOROK\r\nJelöljön ki egy vagy több sort a monitorok "
            L"listájában. A Ctrl+A mindet kijelöli; a Ctrl és a Shift módosítja a kijelölést. Az animáció "
            L"vezérlői és csúszkái csak a kijelölt monitorok beállításait változtatják. A sor kijelölése és "
            L"az animációs kimenet jelölőnégyzetes engedélyezése külön művelet. A kijelölést az alkalmazás "
            L"és a képernyőkímélő külön megjegyzi. Ha korábban minden monitor ki volt jelölve, az újonnan "
            L"csatlakoztatott monitorok is bekerülnek a kijelölésbe. A kijelölt monitorok eltérő értékeit a "
            L"jelölőnégyzetek határozatlan állapota, valamint a választógombok, a csúszkafogantyúk és az "
            L"„Mind bekapcsolása” és „Mind kikapcsolása” gombok pontozása jelzi. A csúszkák felirata közös "
            L"érték helyett gondolatjelet mutat. Egy beállítás módosítása vagy a csúszkára kattintás az "
            L"adott értéket minden kijelölt monitorra alkalmazza.\r\n\r\nELŐNÉZET ÉS KEZELÉS\r\nA "
            L"FlightCorridor.scr Windows-képernyőkímélőként használható, az alkalmazástól külön "
            L"beállításokkal. A teljes képernyős előnézetben élőben módosíthatók a beállítások. Az OK ment, "
            L"a Mégse vagy Esc elveti a módosításokat. A teljes képernyős képernyőkímélő billentyűvel vagy "
            L"egérmozgással zárható be.\r\n\r\nRENDSZERKÖVETELMÉNYEK\r\nA Windows 7–11 minden funkciót "
            L"támogat. Windows Vista SP2 alatt telepíteni kell a KB971512 és KB2117917 frissítést. Direct3D "
            L"11 támogatás szükséges."
        },
    }),
    DefineLanguage(LANG_MT, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Malti" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — kontrolli" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Issettjar ta’ FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Lingwa:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Veloċità tal-animazzjoni: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Titjira għall-moniters magħżula" },
        LocalizedText{ TXT_ENABLE_ALL, L"Attiva kollox" },
        LocalizedText{ TXT_DISABLE_ALL, L"Iddiżattiva kollox" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Moniter tal-animazzjoni" },
        LocalizedText{ TXT_MONITOR, L"Moniter" },
        LocalizedText{ TXT_RESOLUTION, L"Riżoluzzjoni" },
        LocalizedText{ TXT_POSITION, L"Pożizzjoni" },
        LocalizedText{ TXT_PRIMARY, L"primarju" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Ikkanċella" },
        LocalizedText{ TXT_START_RECORDING, L"Ibda r-reġistrazzjoni…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Waqqaf ir-reġistrazzjoni" },
        LocalizedText{ TXT_PAUSE, L"Issospendi" },
        LocalizedText{ TXT_RESUME, L"Kompli" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Installa l-iscreen saver" },
        LocalizedText{ TXT_EXIT, L"Oħroġ" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"L-animazzjoni għaddejja…" },
        LocalizedText{ TXT_RECORDING, L"Reġistrazzjoni MP4 għaddejja…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Ir-reġistrazzjoni ġiet issejvjata." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Ma setgħetx tinbeda r-reġistrazzjoni MP4." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"L-iscreen saver ma ġiex installat." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"L-iscreen saver ġie installat." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Ma setax jiġi inizjalizzat ir-renderer Direct3D." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Titjira bejn erba’ uċuħ li jinbidlu" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Titjira f’lembut li jinbidel" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"L-għeluq tal-applikazzjoni jwaqqaf ir-reġistrazzjoni li tkun għaddejja."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Iftaħ is-sit web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Is-sit ma jistax jinfetaħ fil-brawżer predefinit." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Il-URL ma setax jiġi kkupjat fil-clipboard." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"L-informazzjoni ma setgħetx tiġi kkupjata fil-clipboard."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Attiva l-previżjoni" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Iddiżattiva l-previżjoni" },
        LocalizedText{ TXT_PAUSED_STATUS, L"L-animazzjoni tinsab sospiża." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Imblokka l-iscreen saver waqt l-animazzjoni" },
        LocalizedText{ TXT_READY_STATUS, L"Lest." },
        LocalizedText{ TXT_HELP, L"Għajnuna" },
        LocalizedText{ TXT_ABOUT, L"Dwar" },
        LocalizedText{ TXT_CLOSE, L"Agħlaq" },
        LocalizedText{ TXT_SNAPSHOT, L"Issejvja PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"L-immaġni PNG ġiet issejvjata." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Ma setgħetx tiġi ssejvjata l-immaġni PNG." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Neħħi l-iscreen saver" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"L-iscreen saver tneħħa." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Ma setax jitneħħa l-iscreen saver. Agħlaq l-iscreen saver u l-previżjoni tiegħu u erġa’ pprova."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Agħlaq it-tieqa tal-issettjar ta’ FlightCorridor u erġa’ pprova tneħħih."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Agħlaq it-tieqa tal-issettjar tal-iscreen saver ta’ Windows u erġa’ pprova tneħħih."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Agħlaq l-iscreen saver jew il-previżjoni fuq skrin sħiħ b’Esc jew billi ċċaqlaq il-maws u "
            L"erġa’ pprova."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Titjira bejn uċuħ li jinbidlu aċċellerata bil-ħardwer." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Verżjoni:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Pjattaforma fil-mira:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Sit web:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Iftaħ fil-brawżer default" },
        LocalizedText{ TXT_COPY_URL, L"Ikkopja l-&indirizz" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Ikkopja l-&informazzjoni" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Dawl ewlieni" },
        LocalizedText{ TXT_FILL_LIGHT, L"Dawl ta’ mili" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Dawl ambjentali" },
        LocalizedText{ TXT_RIM_LIGHT, L"Dawl tal-kontorn" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Nisġa" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Rotazzjoni libera tal-kamera" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pawżi u bidliet fid-direzzjoni" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Ir-riżorsa tal-liċenzja mhijiex disponibbli." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Mudell tal-moniter" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Rata ta’ aġġornament" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Fond tal-bits" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Format tal-kulur" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Spazju tal-kulur" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bits/kanal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bits/pixel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Issettjar tar-reġistrazzjoni" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Riżoluzzjoni:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Rata tal-frejms:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Il-bidliet japplikaw għar-reġistrazzjoni MP4 li jmiss."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMAZZJONI U ISSETTJAR\r\nTitjira bejn uċuħ li jinbidlu aċċellerata bil-ħardwer. Titjira bejn "
            L"erba’ uċuħ li jinbidlu; Titjira f’lembut li jinbidel. Agħżel animazzjoni waħda biss għal kull "
            L"moniter. Nisġa taqleb bejn wiċċ b’nisġa u mudell bil-wireframe. Ir-rotazzjoni libera "
            L"tal-kamera tbiddel id-direzzjoni tal-ħarsa bil-mod fit-tliet dimensjonijiet. L-għażla Pawżi u "
            L"bidliet fid-direzzjoni żżid deċelerazzjonijiet, pawżi u treġġigħ lura tar-rotazzjoni b’mod "
            L"każwali; it-titjira ’l quddiem tkompli. Il-veloċità hija 0–1600%. Kull moniter għandu xena "
            L"każwali indipendenti li tintwera bir-rata ta’ aġġornament tiegħu. Id-dawl prinċipali, id-dawl "
            L"ta’ mili, id-dawl ambjentali u d-dawl tal-kontorn jistgħu jinxtegħlu separatament "
            L"għall-iskrins magħżula. Id-dawl japplika biss għall-uċuħ b’nisġa.\r\n\r\nSKRINS\r\nAgħżel "
            L"ringiela waħda jew aktar fil-lista tal-moniters. Ctrl+A jagħżilhom kollha; Ctrl u Shift "
            L"ibiddlu l-għażla. Il-kontrolli u s-sliders tal-animazzjoni jibdlu biss l-issettjar "
            L"tal-moniters magħżula. L-għażla ta’ ringiela hija differenti mill-attivazzjoni tal-output "
            L"permezz tal-kaxxa tal-marka. L-għażla tinżamm separatament għall-applikazzjoni u għall-iscreen "
            L"saver. Jekk il-moniters kollha kienu magħżula, il-moniters ġodda jiddaħħlu wkoll fl-għażla. "
            L"Valuri differenti fuq il-moniters magħżula jintwerew bi stat indeterminat tal-kaxxi tal-marka "
            L"u b’disinn bit-tikek fuq il-buttuni tar-radju, il-manki tas-sliders u l-buttuni “Attiva "
            L"kollox” u “Iddiżattiva kollox”. It-tikketti tas-sliders juru sing minflok valur komuni. Meta "
            L"tibdel għażla jew tikklikkja slider, dak il-valur jiġi applikat għall-moniters magħżula "
            L"kollha.\r\n\r\nKONTROLLI\r\nĦaddem FlightCorridor.exe. L-issettjar jiġi ssejvjat kontinwament "
            L"u taħdem istanza waħda biss. Il-kaxxa tal-moniter jew klikk doppja fuq ir-ringiela tattiva jew "
            L"tiddiżattiva l-output tal-animazzjoni. Tista’ tissospendi u tkompli l-animazzjoni. PNG u MP4 "
            L"jaqbdu l-ewwel moniter tal-animazzjoni attiv, mhux immaġni magħquda tal-moniters kollha. "
            L"L-output tal-animazzjoni tal-moniter li qed jiġi rreġistrat ma jistax jiġi diżattivat waqt "
            L"ir-reġistrazzjoni; l-għeluq tal-applikazzjoni waqt reġistrazzjoni jeħtieġ konferma. "
            L"Is-sospensjoni u l-imblukkar tal-iscreen saver japplikaw għall-applikazzjoni kollha, "
            L"irrispettivament mill-moniters magħżula. Meta l-imblukkar ikun attiv, l-iscreen saver ta’ "
            L"Windows jiġi mblukkat biss waqt li jkun hemm animazzjoni viżibbli mhux sospiża fuq mill-inqas "
            L"moniter wieħed. L-applikazzjoni tinstalla jew tneħħi l-iscreen saver inkorporat.\r\n\r\n"
            L"RITRATTI TAL-ISKRIN U REĠISTRAZZJONI\r\nFl-issettjar tar-reġistrazzjoni agħżel Viewport jew "
            L"TV. Viewport iżomm id-dimensjonijiet u r-rata ta’ aġġornament tal-moniter, sa 60 frejm kull "
            L"sekonda. TV joffri 1920 × 1080, 1440 × 1080 jew 1280 × 720 f’16:9, b’50, 25, 59.94 "
            L"(60000/1001) jew 29.97 (30000/1001) frejm kull sekonda. Il-vidjo TV huwa progressiv BT.709, "
            L"b’medda limitata u sottokampjunar tal-kulur 4:2:0. Il-proporzjonijiet jinżammu u l-faxex ta’ "
            L"mili huma suwed. OK isalva l-għażliet għar-reġistrazzjoni li jmiss; Ikkanċella jew Esc jarmi "
            L"bidliet mhux ikkonfermati. It-twieqi tar-reġistrazzjoni, Għajnuna u Dwar ma jimblukkawx twieqi "
            L"oħra u jistgħu jiġu minimizzati. Tab u Shift+Tab ibiddlu l-fokus, Enter jattiva l-buttuna "
            L"fil-fokus u Esc jagħlaq it-tieqa awżiljarja attiva.\r\n\r\nREKWIŻITI TAS-SISTEMA\r\nWindows "
            L"7–11 jappoġġja l-funzjonijiet kollha. Fuq Windows Vista SP2 għandhom jiġu installati "
            L"l-aġġornamenti KB971512 u KB2117917; ir-reġistrazzjoni MP4 ma taħdimx fuq Vista. Huwa meħtieġ "
            L"Direct3D 11 u, għall-MP4, Media Foundation u encoder H.264. L-interface u d-dokumentazzjoni "
            L"huma disponibbli f’36 lingwa."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMAZZJONI U ISSETTJAR\r\nTitjira bejn uċuħ li jinbidlu aċċellerata bil-ħardwer. Titjira bejn "
            L"erba’ uċuħ li jinbidlu; Titjira f’lembut li jinbidel. Agħżel animazzjoni waħda biss għal kull "
            L"moniter. Nisġa taqleb bejn wiċċ b’nisġa u mudell bil-wireframe. Ir-rotazzjoni libera "
            L"tal-kamera tbiddel id-direzzjoni tal-ħarsa bil-mod fit-tliet dimensjonijiet. L-għażla Pawżi u "
            L"bidliet fid-direzzjoni żżid deċelerazzjonijiet, pawżi u treġġigħ lura tar-rotazzjoni b’mod "
            L"każwali; it-titjira ’l quddiem tkompli. Il-veloċità hija 0–1600%. Kull moniter għandu xena "
            L"każwali indipendenti li tintwera bir-rata ta’ aġġornament tiegħu. Id-dawl prinċipali, id-dawl "
            L"ta’ mili, id-dawl ambjentali u d-dawl tal-kontorn jistgħu jinxtegħlu separatament "
            L"għall-iskrins magħżula. Id-dawl japplika biss għall-uċuħ b’nisġa.\r\n\r\nSKRINS\r\nAgħżel "
            L"ringiela waħda jew aktar fil-lista tal-moniters. Ctrl+A jagħżilhom kollha; Ctrl u Shift "
            L"ibiddlu l-għażla. Il-kontrolli u s-sliders tal-animazzjoni jibdlu biss l-issettjar "
            L"tal-moniters magħżula. L-għażla ta’ ringiela hija differenti mill-attivazzjoni tal-output "
            L"permezz tal-kaxxa tal-marka. L-għażla tinżamm separatament għall-applikazzjoni u għall-iscreen "
            L"saver. Jekk il-moniters kollha kienu magħżula, il-moniters ġodda jiddaħħlu wkoll fl-għażla. "
            L"Valuri differenti fuq il-moniters magħżula jintwerew bi stat indeterminat tal-kaxxi tal-marka "
            L"u b’disinn bit-tikek fuq il-buttuni tar-radju, il-manki tas-sliders u l-buttuni “Attiva "
            L"kollox” u “Iddiżattiva kollox”. It-tikketti tas-sliders juru sing minflok valur komuni. Meta "
            L"tibdel għażla jew tikklikkja slider, dak il-valur jiġi applikat għall-moniters magħżula "
            L"kollha.\r\n\r\nPREVIŻJONI U KONTROLLI\r\nUża FlightCorridor.scr bħala screen saver ta’ "
            L"Windows. L-issettjar tiegħu huwa separat minn dak tal-applikazzjoni. Il-previżjoni fuq skrin "
            L"sħiħ tippermetti bidliet waqt l-animazzjoni. OK isalva u Ikkanċella jew Esc jarmi l-bidliet. "
            L"Oħroġ mill-iscreen saver bi kwalunkwe tast jew billi ċċaqlaq il-maws.\r\n\r\nREKWIŻITI "
            L"TAS-SISTEMA\r\nWindows 7–11 jappoġġja l-funzjonijiet kollha. Fuq Windows Vista SP2 għandhom "
            L"jiġu installati l-aġġornamenti KB971512 u KB2117917. Huwa meħtieġ Direct3D 11."
        },
    }),
    DefineLanguage(LANG_NL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Nederlands" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — bediening" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Instellingen van FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Taal:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Animatiesnelheid: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Vlucht op geselecteerde beeldschermen" },
        LocalizedText{ TXT_ENABLE_ALL, L"Alles inschakelen" },
        LocalizedText{ TXT_DISABLE_ALL, L"Alles uitschakelen" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Animatiebeeldscherm" },
        LocalizedText{ TXT_MONITOR, L"Beeldscherm" },
        LocalizedText{ TXT_RESOLUTION, L"Resolutie" },
        LocalizedText{ TXT_POSITION, L"Positie" },
        LocalizedText{ TXT_PRIMARY, L"primair" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Annuleren" },
        LocalizedText{ TXT_START_RECORDING, L"Opname starten…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Opname stoppen" },
        LocalizedText{ TXT_PAUSE, L"Pauzeren" },
        LocalizedText{ TXT_RESUME, L"Hervatten" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Schermbeveiliging installeren" },
        LocalizedText{ TXT_EXIT, L"Afsluiten" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animatie wordt uitgevoerd…" },
        LocalizedText{ TXT_RECORDING, L"MP4-opname wordt gemaakt…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"De opname is opgeslagen." },
        LocalizedText{ TXT_RECORDING_FAILED, L"De MP4-opname kon niet worden gestart." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"De schermbeveiliging is niet geïnstalleerd." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"De schermbeveiliging is geïnstalleerd." },
        LocalizedText{ TXT_RENDERER_FAILED, L"De Direct3D-renderer kon niet worden geïnitialiseerd." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Vlucht tussen vier vervormende oppervlakken" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Vlucht door een vervormende trechter" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Als u de toepassing sluit, wordt de huidige opname gestopt."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Website %ls openen" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Kan de website niet in de standaardbrowser openen." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"De URL kon niet naar het klembord worden gekopieerd." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"De informatie kon niet naar het klembord worden gekopieerd."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Voorbeeld inschakelen" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Voorbeeld uitschakelen" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animatie is gepauzeerd." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Schermbeveiliging blokkeren tijdens animatie" },
        LocalizedText{ TXT_READY_STATUS, L"Gereed." },
        LocalizedText{ TXT_HELP, L"Help" },
        LocalizedText{ TXT_ABOUT, L"Info" },
        LocalizedText{ TXT_CLOSE, L"Sluiten" },
        LocalizedText{ TXT_SNAPSHOT, L"PNG opslaan…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"De PNG-afbeelding is opgeslagen." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"De PNG-afbeelding kon niet worden opgeslagen." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Schermbeveiliging verwijderen" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"De schermbeveiliging is verwijderd." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"De schermbeveiliging kon niet worden verwijderd. Sluit de schermbeveiliging en het voorbeeld "
            L"en probeer het opnieuw."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Sluit de instellingen van FlightCorridor en probeer het verwijderen opnieuw."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Sluit de instellingen voor schermbeveiliging van Windows en probeer het verwijderen opnieuw."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Sluit de schermbeveiliging of het schermvullende voorbeeld met Esc of door de muis te bewegen "
            L"en probeer het opnieuw."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardwareversnelde vlucht tussen vervormende oppervlakken." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versie:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Doelplatform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Website:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Openen in standaardbrowser" },
        LocalizedText{ TXT_COPY_URL, L"&Adres kopiëren" },
        LocalizedText{ TXT_COPY_INFORMATION, L"&Informatie kopiëren" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Hoofdlicht" },
        LocalizedText{ TXT_FILL_LIGHT, L"Invullicht" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Omgevingslicht" },
        LocalizedText{ TXT_RIM_LIGHT, L"Randlicht" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Textuur" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Vrije camerarotatie" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauzes en omkeren" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"De licentiebron is niet beschikbaar." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Beeldschermmodel" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Vernieuwingsfrequentie" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bitdiepte" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Kleurindeling" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Kleurruimte" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bits/kanaal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bits/pixel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Opname-instellingen" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Resolutie:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Framesnelheid:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Wijzigingen gelden voor de volgende MP4-opname." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMATIE EN INSTELLINGEN\r\nHardwareversnelde vlucht tussen vervormende oppervlakken. Vlucht "
            L"tussen vier vervormende oppervlakken; Vlucht door een vervormende trechter. Kies precies één "
            L"animatie per beeldscherm. Textuur schakelt tussen een getextureerd oppervlak en een "
            L"draadmodel. Vrije camerarotatie verandert de kijkrichting langzaam in alle drie dimensies. De "
            L"optie Pauzes en omkeren voegt willekeurige vertragingen, pauzes en omkeringen van de rotatie "
            L"toe; de voorwaartse vlucht gaat door. De snelheid is instelbaar op 0–1600%. Elk beeldscherm "
            L"heeft een onafhankelijke willekeurige scène en wordt op zijn eigen vernieuwingsfrequentie "
            L"aangestuurd. Hoofdlicht, invullicht, omgevingslicht en randlicht kunnen onafhankelijk worden "
            L"geschakeld voor de geselecteerde beeldschermen. De verlichting geldt alleen voor oppervlakken "
            L"met textuur.\r\n\r\nBEELDSCHERMEN\r\nSelecteer één of meer beeldschermrijen in de lijst. "
            L"Ctrl+A selecteert alles; met Ctrl en Shift past u de selectie aan. Animatieknoppen en "
            L"schuifregelaars wijzigen alleen de instellingen van de geselecteerde beeldschermen. Een rij "
            L"selecteren is iets anders dan de animatie-uitvoer inschakelen met het selectievakje. De "
            L"selectie wordt apart onthouden voor de toepassing en de schermbeveiliging. Als alle "
            L"beeldschermen waren geselecteerd, worden nieuw aangesloten beeldschermen ook geselecteerd. "
            L"Verschillende waarden op geselecteerde beeldschermen worden aangegeven door selectievakjes in "
            L"onbepaalde toestand en een stippelpatroon op keuzerondjes, schuifknoppen en de knoppen ‘Alles "
            L"inschakelen’ en ‘Alles uitschakelen’. De labels van schuifregelaars tonen een streepje in "
            L"plaats van een gemeenschappelijke waarde. Een optie wijzigen of op een schuifregelaar klikken "
            L"past die waarde toe op alle geselecteerde beeldschermen.\r\n\r\nBEDIENING\r\nStart "
            L"FlightCorridor.exe. Instellingen worden doorlopend opgeslagen en er draait slechts één "
            L"exemplaar van de toepassing. Het selectievakje of een dubbelklik op de beeldschermrij schakelt "
            L"de animatie-uitvoer in of uit. U kunt de animatie pauzeren en hervatten. PNG en MP4 leggen het "
            L"eerste actieve animatiebeeldscherm vast, niet een gecombineerd beeld van alle schermen. De "
            L"animatie-uitvoer van het opgenomen beeldscherm kan tijdens de opname niet worden "
            L"uitgeschakeld; afsluiten tijdens een opname vereist bevestiging. Pauzeren en het blokkeren van "
            L"de schermbeveiliging gelden voor de hele toepassing, ongeacht de beeldschermselectie. Als "
            L"blokkering is ingeschakeld, wordt de Windows-schermbeveiliging alleen tegengehouden zolang op "
            L"minstens één beeldscherm een zichtbare, niet-gepauzeerde animatie draait. De toepassing kan de "
            L"ingebouwde schermbeveiliging installeren of verwijderen.\r\n\r\nSCHERMAFBEELDINGEN EN OPNAMEN\r"
            L"\nKies Viewport of TV in de opname-instellingen. Viewport behoudt de afmetingen en "
            L"vernieuwingsfrequentie van het beeldscherm tot 60 frames per seconde. TV biedt 1920 × 1080, "
            L"1440 × 1080 of 1280 × 720 met beeldverhouding 16:9 en 50, 25, 59.94 (60000/1001) of 29.97 "
            L"(30000/1001) frames per seconde. TV gebruikt progressieve BT.709-video met beperkt bereik en "
            L"4:2:0-kleursubsampling. De beeldverhouding blijft behouden en opvulbalken zijn zwart. OK "
            L"bewaart de opties voor de volgende opname; Annuleren of Esc verwerpt onbevestigde wijzigingen. "
            L"Opname-instellingen, Help en Info blokkeren andere vensters niet en kunnen worden "
            L"geminimaliseerd. Tab en Shift+Tab verplaatsen de focus, Enter activeert de knop met focus en "
            L"Esc sluit het actieve hulpvenster.\r\n\r\nSYSTEEMVEREISTEN\r\nWindows 7–11 ondersteunt alle "
            L"functies. Voor Windows Vista SP2 moet u updates KB971512 en KB2117917 installeren; MP4-opname "
            L"werkt niet op Vista. Direct3D 11-ondersteuning is vereist; voor MP4 zijn ook Media Foundation "
            L"en een H.264-encoder nodig. Interface en documentatie zijn beschikbaar in 36 talen."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATIE EN INSTELLINGEN\r\nHardwareversnelde vlucht tussen vervormende oppervlakken. Vlucht "
            L"tussen vier vervormende oppervlakken; Vlucht door een vervormende trechter. Kies precies één "
            L"animatie per beeldscherm. Textuur schakelt tussen een getextureerd oppervlak en een "
            L"draadmodel. Vrije camerarotatie verandert de kijkrichting langzaam in alle drie dimensies. De "
            L"optie Pauzes en omkeren voegt willekeurige vertragingen, pauzes en omkeringen van de rotatie "
            L"toe; de voorwaartse vlucht gaat door. De snelheid is instelbaar op 0–1600%. Elk beeldscherm "
            L"heeft een onafhankelijke willekeurige scène en wordt op zijn eigen vernieuwingsfrequentie "
            L"aangestuurd. Hoofdlicht, invullicht, omgevingslicht en randlicht kunnen onafhankelijk worden "
            L"geschakeld voor de geselecteerde beeldschermen. De verlichting geldt alleen voor oppervlakken "
            L"met textuur.\r\n\r\nBEELDSCHERMEN\r\nSelecteer één of meer beeldschermrijen in de lijst. "
            L"Ctrl+A selecteert alles; met Ctrl en Shift past u de selectie aan. Animatieknoppen en "
            L"schuifregelaars wijzigen alleen de instellingen van de geselecteerde beeldschermen. Een rij "
            L"selecteren is iets anders dan de animatie-uitvoer inschakelen met het selectievakje. De "
            L"selectie wordt apart onthouden voor de toepassing en de schermbeveiliging. Als alle "
            L"beeldschermen waren geselecteerd, worden nieuw aangesloten beeldschermen ook geselecteerd. "
            L"Verschillende waarden op geselecteerde beeldschermen worden aangegeven door selectievakjes in "
            L"onbepaalde toestand en een stippelpatroon op keuzerondjes, schuifknoppen en de knoppen ‘Alles "
            L"inschakelen’ en ‘Alles uitschakelen’. De labels van schuifregelaars tonen een streepje in "
            L"plaats van een gemeenschappelijke waarde. Een optie wijzigen of op een schuifregelaar klikken "
            L"past die waarde toe op alle geselecteerde beeldschermen.\r\n\r\nVOORBEELD EN BEDIENING\r\n"
            L"Gebruik FlightCorridor.scr als Windows-schermbeveiliging met eigen instellingen. Het "
            L"schermvullende voorbeeld laat live aanpassingen toe. OK slaat wijzigingen op; Annuleren of Esc "
            L"verwerpt ze. Sluit de schermvullende schermbeveiliging met een toets of een muisbeweging.\r\n\r"
            L"\nSYSTEEMVEREISTEN\r\nWindows 7–11 ondersteunt alle functies. Voor Windows Vista SP2 moet u "
            L"updates KB971512 en KB2117917 installeren. Direct3D 11-ondersteuning is vereist."
        },
    }),
    DefineLanguage(LANG_RO, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Română" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — comenzi" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Setări FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Limbă:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Viteza animației: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Zbor pe monitoarele selectate" },
        LocalizedText{ TXT_ENABLE_ALL, L"Activare toate" },
        LocalizedText{ TXT_DISABLE_ALL, L"Dezactivare toate" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Monitor de animație" },
        LocalizedText{ TXT_MONITOR, L"Monitor" },
        LocalizedText{ TXT_RESOLUTION, L"Rezoluție" },
        LocalizedText{ TXT_POSITION, L"Poziție" },
        LocalizedText{ TXT_PRIMARY, L"principal" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Anulare" },
        LocalizedText{ TXT_START_RECORDING, L"Pornire înregistrare…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Oprire înregistrare" },
        LocalizedText{ TXT_PAUSE, L"Pauză" },
        LocalizedText{ TXT_RESUME, L"Reluare" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Instalare economizor de ecran" },
        LocalizedText{ TXT_EXIT, L"Ieșire" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animația rulează…" },
        LocalizedText{ TXT_RECORDING, L"Înregistrare MP4 în curs…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Înregistrarea a fost salvată." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Înregistrarea MP4 nu a putut fi pornită." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Economizorul de ecran nu a fost instalat." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Economizorul de ecran a fost instalat." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Modulul de randare Direct3D nu a putut fi inițializat." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Zbor între patru suprafețe deformabile" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Zbor printr-o pâlnie deformabilă" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Închiderea aplicației va opri înregistrarea în curs." },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Deschidere site web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Site-ul nu poate fi deschis în browserul implicit." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL-ul nu a putut fi copiat în clipboard." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Informațiile nu au putut fi copiate în clipboard."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Activare previzualizare" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Dezactivare previzualizare" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animația este în pauză." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blocare economizor în timpul animației" },
        LocalizedText{ TXT_READY_STATUS, L"Pregătit." },
        LocalizedText{ TXT_HELP, L"Ajutor" },
        LocalizedText{ TXT_ABOUT, L"Despre" },
        LocalizedText{ TXT_CLOSE, L"Închidere" },
        LocalizedText{ TXT_SNAPSHOT, L"Salvare PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Imaginea PNG a fost salvată." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Imaginea PNG nu a putut fi salvată." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Dezinstalare economizor de ecran" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Economizorul de ecran a fost dezinstalat." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Economizorul de ecran nu a putut fi dezinstalat. Închideți-l împreună cu previzualizarea și "
            L"încercați din nou."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Închideți fereastra de setări FlightCorridor și încercați din nou dezinstalarea."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Închideți setările economizorului de ecran Windows și încercați din nou dezinstalarea."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Închideți economizorul sau previzualizarea pe tot ecranul cu Esc ori mișcând mouse-ul și "
            L"încercați din nou."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Zbor între suprafețe deformabile accelerat hardware." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versiune:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Platformă țintă:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Site web:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Deschidere în browserul implicit" },
        LocalizedText{ TXT_COPY_URL, L"Copiere &adresă" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copiere &informații" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Lumină principală" },
        LocalizedText{ TXT_FILL_LIGHT, L"Lumină de umplere" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Lumină ambiantă" },
        LocalizedText{ TXT_RIM_LIGHT, L"Lumină de contur" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Textură" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Rotirea liberă a camerei" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauze și inversări" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Resursa licenței nu este disponibilă." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Model monitor" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Rată de reîmprospătare" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Adâncime de biți" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Format de culoare" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Spațiu de culoare" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u biți/canal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u biți/pixel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Setări de înregistrare" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Rezoluție:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Frecvența cadrelor:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Modificările se aplică următoarei înregistrări MP4." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMAȚIE ȘI SETĂRI\r\nZbor între suprafețe deformabile accelerat hardware. Zbor între patru "
            L"suprafețe deformabile; Zbor printr-o pâlnie deformabilă. Alegeți exact o animație pentru "
            L"fiecare monitor. Textură comută între suprafața texturată și modelul de sârmă. Rotirea liberă "
            L"a camerei schimbă lent direcția privirii în toate cele trei dimensiuni. Pauze și inversări "
            L"adaugă încetiniri, pauze și inversări ale rotației la intervale aleatorii; zborul înainte "
            L"continuă. Viteza este 0–1600%. Fiecare monitor are o scenă aleatorie independentă, randată la "
            L"propria rată de reîmprospătare. Lumina principală, lumina de umplere, lumina ambiantă și "
            L"lumina de contur pot fi comutate separat pentru ecranele selectate. Iluminarea se aplică doar "
            L"suprafețelor texturate.\r\n\r\nMONITOARE\r\nSelectați unul sau mai multe rânduri din lista "
            L"monitoarelor. Ctrl+A le selectează pe toate; Ctrl și Shift modifică selecția. Comenzile și "
            L"glisoarele animației schimbă numai setările monitoarelor selectate. Selectarea unui rând "
            L"diferă de activarea ieșirii prin caseta sa de selectare. Selecția este reținută separat pentru "
            L"aplicație și economizor. Dacă erau selectate toate monitoarele, sunt incluse și cele conectate "
            L"ulterior. Valorile diferite de pe monitoarele selectate sunt indicate prin starea "
            L"nedeterminată a casetelor de selectare și un model punctat pe butoanele radio, mânerele "
            L"glisoarelor și butoanele „Activare toate” și „Dezactivare toate”. Etichetele glisoarelor "
            L"afișează o liniuță în locul unei valori comune. Modificarea unei opțiuni sau clicul pe un "
            L"glisor aplică acea valoare tuturor monitoarelor selectate.\r\n\r\nCOMENZI\r\nRulați "
            L"FlightCorridor.exe. Setările se salvează continuu și rulează o singură instanță. Caseta "
            L"monitorului sau un dublu clic pe rând activează ori dezactivează ieșirea animației. Animația "
            L"poate fi pusă în pauză și reluată. PNG și MP4 capturează primul monitor de animație activ, nu "
            L"imaginea combinată a tuturor monitoarelor. Ieșirea animației pe monitorul înregistrat nu poate "
            L"fi dezactivată în timpul înregistrării; închiderea aplicației în timpul înregistrării necesită "
            L"confirmare. Pauza și blocarea economizorului se aplică întregii aplicații, indiferent de "
            L"selecția monitoarelor. Când blocarea este activată, economizorul Windows este împiedicat numai "
            L"cât timp pe cel puțin un monitor este vizibilă o animație care nu este în pauză. Aplicația "
            L"poate instala sau dezinstala economizorul încorporat.\r\n\r\nCAPTURI ȘI ÎNREGISTRARE\r\nÎn "
            L"setările de înregistrare alegeți Viewport sau TV. Viewport păstrează dimensiunile și rata de "
            L"reîmprospătare a monitorului, până la 60 de cadre pe secundă. TV oferă 1920 × 1080, 1440 × "
            L"1080 sau 1280 × 720 în 16:9, la 50, 25, 59.94 (60000/1001) sau 29.97 (30000/1001) cadre pe "
            L"secundă. Videoul TV este progresiv BT.709, cu interval limitat și subeșantionare cromatică "
            L"4:2:0. Proporțiile imaginii se păstrează, iar benzile de completare sunt negre. OK salvează "
            L"opțiunile pentru următoarea înregistrare; Anulare sau Esc renunță la schimbările neconfirmate. "
            L"Ferestrele de înregistrare, ajutor și informații nu blochează celelalte ferestre și pot fi "
            L"minimizate. Tab și Shift+Tab mută focalizarea, Enter activează butonul focalizat, iar Esc "
            L"închide fereastra auxiliară activă.\r\n\r\nCERINȚE DE SISTEM\r\nWindows 7–11 acceptă toate "
            L"funcțiile. Pentru Windows Vista SP2 trebuie instalate actualizările KB971512 și KB2117917; "
            L"înregistrarea MP4 nu funcționează pe Vista. Este necesar Direct3D 11, iar pentru MP4 și Media "
            L"Foundation și un codificator H.264. Interfața și documentația sunt disponibile în 36 de limbi."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMAȚIE ȘI SETĂRI\r\nZbor între suprafețe deformabile accelerat hardware. Zbor între patru "
            L"suprafețe deformabile; Zbor printr-o pâlnie deformabilă. Alegeți exact o animație pentru "
            L"fiecare monitor. Textură comută între suprafața texturată și modelul de sârmă. Rotirea liberă "
            L"a camerei schimbă lent direcția privirii în toate cele trei dimensiuni. Pauze și inversări "
            L"adaugă încetiniri, pauze și inversări ale rotației la intervale aleatorii; zborul înainte "
            L"continuă. Viteza este 0–1600%. Fiecare monitor are o scenă aleatorie independentă, randată la "
            L"propria rată de reîmprospătare. Lumina principală, lumina de umplere, lumina ambiantă și "
            L"lumina de contur pot fi comutate separat pentru ecranele selectate. Iluminarea se aplică doar "
            L"suprafețelor texturate.\r\n\r\nMONITOARE\r\nSelectați unul sau mai multe rânduri din lista "
            L"monitoarelor. Ctrl+A le selectează pe toate; Ctrl și Shift modifică selecția. Comenzile și "
            L"glisoarele animației schimbă numai setările monitoarelor selectate. Selectarea unui rând "
            L"diferă de activarea ieșirii prin caseta sa de selectare. Selecția este reținută separat pentru "
            L"aplicație și economizor. Dacă erau selectate toate monitoarele, sunt incluse și cele conectate "
            L"ulterior. Valorile diferite de pe monitoarele selectate sunt indicate prin starea "
            L"nedeterminată a casetelor de selectare și un model punctat pe butoanele radio, mânerele "
            L"glisoarelor și butoanele „Activare toate” și „Dezactivare toate”. Etichetele glisoarelor "
            L"afișează o liniuță în locul unei valori comune. Modificarea unei opțiuni sau clicul pe un "
            L"glisor aplică acea valoare tuturor monitoarelor selectate.\r\n\r\nPREVIZUALIZARE ȘI COMENZI\r\n"
            L"Folosiți FlightCorridor.scr drept economizor de ecran Windows, cu setări separate de "
            L"aplicație. Previzualizarea pe tot ecranul permite ajustări în timp real. OK salvează "
            L"modificările; Anulare sau Esc le anulează. Ieșiți din economizor apăsând o tastă sau mișcând "
            L"mouse-ul.\r\n\r\nCERINȚE DE SISTEM\r\nWindows 7–11 acceptă toate funcțiile. Pentru Windows "
            L"Vista SP2 trebuie instalate actualizările KB971512 și KB2117917. Este necesar Direct3D 11."
        },
    }),
    DefineLanguage(LANG_EL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Ελληνικά" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — χειρισμός" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Ρυθμίσεις FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Γλώσσα:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Ταχύτητα κίνησης: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Πτήση στις επιλεγμένες οθόνες" },
        LocalizedText{ TXT_ENABLE_ALL, L"Ενεργοποίηση όλων" },
        LocalizedText{ TXT_DISABLE_ALL, L"Απενεργοποίηση όλων" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Οθόνη κίνησης" },
        LocalizedText{ TXT_MONITOR, L"Οθόνη" },
        LocalizedText{ TXT_RESOLUTION, L"Ανάλυση" },
        LocalizedText{ TXT_POSITION, L"Θέση" },
        LocalizedText{ TXT_PRIMARY, L"κύρια" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Άκυρο" },
        LocalizedText{ TXT_START_RECORDING, L"Έναρξη εγγραφής…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Διακοπή εγγραφής" },
        LocalizedText{ TXT_PAUSE, L"Παύση" },
        LocalizedText{ TXT_RESUME, L"Συνέχιση" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Εγκατάσταση προφύλαξης οθόνης" },
        LocalizedText{ TXT_EXIT, L"Έξοδος" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Η κίνηση εκτελείται…" },
        LocalizedText{ TXT_RECORDING, L"Εγγραφή MP4 σε εξέλιξη…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Η εγγραφή αποθηκεύτηκε." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Δεν ήταν δυνατή η έναρξη εγγραφής MP4." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Η προφύλαξη οθόνης δεν εγκαταστάθηκε." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Η προφύλαξη οθόνης εγκαταστάθηκε." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Δεν ήταν δυνατή η αρχικοποίηση του αποδότη Direct3D." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Πτήση ανάμεσα σε τέσσερις μεταβαλλόμενες επιφάνειες" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Πτήση μέσα από μεταβαλλόμενη χοάνη" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Το κλείσιμο της εφαρμογής θα διακόψει την εγγραφή που βρίσκεται σε εξέλιξη."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Άνοιγμα τοποθεσίας web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Αδυναμία ανοίγματος του ιστοτόπου στον προεπιλεγμένο περιηγητή."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Δεν ήταν δυνατή η αντιγραφή του URL στο πρόχειρο." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Δεν ήταν δυνατή η αντιγραφή των πληροφοριών στο πρόχειρο."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Ενεργοποίηση προεπισκόπησης" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Απενεργοποίηση προεπισκόπησης" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Η κίνηση έχει παύσει." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Αναστολή προφύλαξης οθόνης κατά την κίνηση" },
        LocalizedText{ TXT_READY_STATUS, L"Έτοιμο." },
        LocalizedText{ TXT_HELP, L"Βοήθεια" },
        LocalizedText{ TXT_ABOUT, L"Πληροφορίες" },
        LocalizedText{ TXT_CLOSE, L"Κλείσιμο" },
        LocalizedText{ TXT_SNAPSHOT, L"Αποθήκευση PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Η εικόνα PNG αποθηκεύτηκε." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Δεν ήταν δυνατή η αποθήκευση της εικόνας PNG." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Κατάργηση προφύλαξης οθόνης" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Η προφύλαξη οθόνης καταργήθηκε." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Δεν ήταν δυνατή η κατάργηση της προφύλαξης οθόνης. Κλείστε την και την προεπισκόπησή της και "
            L"δοκιμάστε ξανά."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Κλείστε το παράθυρο ρυθμίσεων του FlightCorridor και δοκιμάστε ξανά την κατάργηση."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Κλείστε τις ρυθμίσεις προφύλαξης οθόνης των Windows και δοκιμάστε ξανά την κατάργηση."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Κλείστε την προφύλαξη ή την προεπισκόπηση πλήρους οθόνης με Esc ή κίνηση του ποντικιού και "
            L"δοκιμάστε ξανά."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Πτήση ανάμεσα σε μεταβαλλόμενες επιφάνειες με επιτάχυνση υλικού."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Έκδοση:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Πλατφόρμα προορισμού:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Τοποθεσία web:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Άνοιγμα στο προεπιλεγμένο πρόγραμμα περιήγησης" },
        LocalizedText{ TXT_COPY_URL, L"Αντιγραφή &διεύθυνσης" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Αντιγραφή &πληροφοριών" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Κύριος φωτισμός" },
        LocalizedText{ TXT_FILL_LIGHT, L"Φωτισμός πλήρωσης" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Περιβάλλων φωτισμός" },
        LocalizedText{ TXT_RIM_LIGHT, L"Φωτισμός περιγράμματος" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Υφή" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Ελεύθερη περιστροφή κάμερας" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Παύσεις και αντιστροφές" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Ο πόρος άδειας χρήσης δεν είναι διαθέσιμος." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Μοντέλο οθόνης" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Ρυθμός ανανέωσης" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Βάθος bit" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Μορφή χρώματος" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Χρωματικός χώρος" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bit/κανάλι" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bit/pixel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Ρυθμίσεις εγγραφής" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Ανάλυση:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Ρυθμός καρέ:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Οι αλλαγές ισχύουν για την επόμενη εγγραφή MP4." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ΚΙΝΗΣΗ ΚΑΙ ΡΥΘΜΙΣΕΙΣ\r\nΠτήση ανάμεσα σε μεταβαλλόμενες επιφάνειες με επιτάχυνση υλικού. Πτήση "
            L"ανάμεσα σε τέσσερις μεταβαλλόμενες επιφάνειες; Πτήση μέσα από μεταβαλλόμενη χοάνη. Επιλέξτε "
            L"ακριβώς μία κίνηση ανά οθόνη. Η Υφή εναλλάσσει επιφάνεια με υφή και συρμάτινο μοντέλο. Η "
            L"ελεύθερη περιστροφή κάμερας αλλάζει αργά την κατεύθυνση θέασης και στις τρεις διαστάσεις. Οι "
            L"Παύσεις και αντιστροφές προσθέτουν τυχαίες επιβραδύνσεις, παύσεις και αντιστροφές περιστροφής, "
            L"ενώ η πτήση προς τα εμπρός συνεχίζεται. Η ταχύτητα είναι 0–1600%. Κάθε οθόνη διαθέτει "
            L"ανεξάρτητη τυχαία σκηνή που αποδίδεται στον δικό της ρυθμό ανανέωσης. Ο κύριος φωτισμός, ο "
            L"φωτισμός πλήρωσης, ο περιβάλλων φωτισμός και ο φωτισμός περιγράμματος ρυθμίζονται ανεξάρτητα "
            L"για τις επιλεγμένες οθόνες. Ο φωτισμός εφαρμόζεται μόνο σε επιφάνειες με υφή.\r\n\r\nΟΘΟΝΕΣ\r\n"
            L"Επιλέξτε μία ή περισσότερες γραμμές στη λίστα οθονών. Το Ctrl+A επιλέγει όλες, ενώ τα Ctrl και "
            L"Shift αλλάζουν την επιλογή. Τα χειριστήρια και τα ρυθμιστικά της κίνησης αλλάζουν μόνο τις "
            L"ρυθμίσεις των επιλεγμένων οθονών. Η επιλογή γραμμής διαφέρει από την ενεργοποίηση εξόδου μέσω "
            L"του πλαισίου ελέγχου της. Η επιλογή αποθηκεύεται χωριστά για την εφαρμογή και την προφύλαξη. "
            L"Αν είχαν επιλεγεί όλες οι οθόνες, περιλαμβάνονται και όσες συνδεθούν αργότερα. Οι διαφορετικές "
            L"τιμές στις επιλεγμένες οθόνες υποδεικνύονται με απροσδιόριστη κατάσταση των πλαισίων ελέγχου "
            L"και μοτίβο κουκκίδων στα κουμπιά επιλογής, στις λαβές των ρυθμιστικών και στα κουμπιά "
            L"«Ενεργοποίηση όλων» και «Απενεργοποίηση όλων». Οι ετικέτες των ρυθμιστικών δείχνουν παύλα αντί "
            L"για κοινή τιμή. Η αλλαγή επιλογής ή το κλικ σε ρυθμιστικό εφαρμόζει την τιμή σε όλες τις "
            L"επιλεγμένες οθόνες.\r\n\r\nΧΕΙΡΙΣΜΟΣ\r\nΕκτελέστε το FlightCorridor.exe. Οι ρυθμίσεις "
            L"αποθηκεύονται συνεχώς και εκτελείται μόνο ένα αντίγραφο της εφαρμογής. Το πλαίσιο της οθόνης ή "
            L"το διπλό κλικ στη γραμμή ενεργοποιεί ή απενεργοποιεί την έξοδο κίνησης. Η κίνηση μπορεί να "
            L"παύσει και να συνεχιστεί. Τα PNG και MP4 καταγράφουν την πρώτη ενεργή οθόνη κίνησης, όχι "
            L"συνδυασμένη εικόνα όλων των οθονών. Η έξοδος κίνησης της καταγραφόμενης οθόνης δεν μπορεί να "
            L"απενεργοποιηθεί κατά την εγγραφή· το κλείσιμο της εφαρμογής κατά την εγγραφή απαιτεί "
            L"επιβεβαίωση. Η παύση και η αναστολή προφύλαξης οθόνης ισχύουν για όλη την εφαρμογή, ανεξάρτητα "
            L"από την επιλογή οθονών. Όταν η αναστολή είναι ενεργή, η προφύλαξη των Windows εμποδίζεται μόνο "
            L"όσο υπάρχει ορατή κίνηση χωρίς παύση σε τουλάχιστον μία οθόνη. Η εφαρμογή εγκαθιστά ή καταργεί "
            L"την ενσωματωμένη προφύλαξη.\r\n\r\nΣΤΙΓΜΙΟΤΥΠΑ ΚΑΙ ΕΓΓΡΑΦΗ\r\nΣτις ρυθμίσεις εγγραφής επιλέξτε "
            L"Viewport ή TV. Το Viewport διατηρεί διαστάσεις και ρυθμό ανανέωσης οθόνης έως 60 καρέ ανά "
            L"δευτερόλεπτο. Το TV προσφέρει 1920 × 1080, 1440 × 1080 ή 1280 × 720 σε 16:9, με 50, 25, 59.94 "
            L"(60000/1001) ή 29.97 (30000/1001) καρέ ανά δευτερόλεπτο. Το βίντεο TV είναι προοδευτικό BT.709 "
            L"περιορισμένου εύρους με υποδειγματοληψία χρώματος 4:2:0. Διατηρούνται οι αναλογίες εικόνας και "
            L"οι συμπληρωματικές λωρίδες είναι μαύρες. Το OK αποθηκεύει επιλογές για την επόμενη εγγραφή· "
            L"Άκυρο ή Esc απορρίπτει ανεπιβεβαίωτες αλλαγές. Οι ρυθμίσεις εγγραφής, η βοήθεια και οι "
            L"πληροφορίες δεν εμποδίζουν άλλα παράθυρα και ελαχιστοποιούνται. Tab και Shift+Tab μετακινούν "
            L"την εστίαση, Enter ενεργοποιεί το εστιασμένο κουμπί και Esc κλείνει το ενεργό βοηθητικό "
            L"παράθυρο.\r\n\r\nΑΠΑΙΤΗΣΕΙΣ ΣΥΣΤΗΜΑΤΟΣ\r\nΤα Windows 7–11 υποστηρίζουν όλες τις λειτουργίες. "
            L"Στα Windows Vista SP2 πρέπει να εγκατασταθούν οι ενημερώσεις KB971512 και KB2117917· η εγγραφή "
            L"MP4 δεν λειτουργεί στα Vista. Απαιτείται υποστήριξη Direct3D 11 και, για MP4, Media Foundation "
            L"και κωδικοποιητής H.264. Η διεπαφή και η τεκμηρίωση διατίθενται σε 36 γλώσσες."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ΚΙΝΗΣΗ ΚΑΙ ΡΥΘΜΙΣΕΙΣ\r\nΠτήση ανάμεσα σε μεταβαλλόμενες επιφάνειες με επιτάχυνση υλικού. Πτήση "
            L"ανάμεσα σε τέσσερις μεταβαλλόμενες επιφάνειες; Πτήση μέσα από μεταβαλλόμενη χοάνη. Επιλέξτε "
            L"ακριβώς μία κίνηση ανά οθόνη. Η Υφή εναλλάσσει επιφάνεια με υφή και συρμάτινο μοντέλο. Η "
            L"ελεύθερη περιστροφή κάμερας αλλάζει αργά την κατεύθυνση θέασης και στις τρεις διαστάσεις. Οι "
            L"Παύσεις και αντιστροφές προσθέτουν τυχαίες επιβραδύνσεις, παύσεις και αντιστροφές περιστροφής, "
            L"ενώ η πτήση προς τα εμπρός συνεχίζεται. Η ταχύτητα είναι 0–1600%. Κάθε οθόνη διαθέτει "
            L"ανεξάρτητη τυχαία σκηνή που αποδίδεται στον δικό της ρυθμό ανανέωσης. Ο κύριος φωτισμός, ο "
            L"φωτισμός πλήρωσης, ο περιβάλλων φωτισμός και ο φωτισμός περιγράμματος ρυθμίζονται ανεξάρτητα "
            L"για τις επιλεγμένες οθόνες. Ο φωτισμός εφαρμόζεται μόνο σε επιφάνειες με υφή.\r\n\r\nΟΘΟΝΕΣ\r\n"
            L"Επιλέξτε μία ή περισσότερες γραμμές στη λίστα οθονών. Το Ctrl+A επιλέγει όλες, ενώ τα Ctrl και "
            L"Shift αλλάζουν την επιλογή. Τα χειριστήρια και τα ρυθμιστικά της κίνησης αλλάζουν μόνο τις "
            L"ρυθμίσεις των επιλεγμένων οθονών. Η επιλογή γραμμής διαφέρει από την ενεργοποίηση εξόδου μέσω "
            L"του πλαισίου ελέγχου της. Η επιλογή αποθηκεύεται χωριστά για την εφαρμογή και την προφύλαξη. "
            L"Αν είχαν επιλεγεί όλες οι οθόνες, περιλαμβάνονται και όσες συνδεθούν αργότερα. Οι διαφορετικές "
            L"τιμές στις επιλεγμένες οθόνες υποδεικνύονται με απροσδιόριστη κατάσταση των πλαισίων ελέγχου "
            L"και μοτίβο κουκκίδων στα κουμπιά επιλογής, στις λαβές των ρυθμιστικών και στα κουμπιά "
            L"«Ενεργοποίηση όλων» και «Απενεργοποίηση όλων». Οι ετικέτες των ρυθμιστικών δείχνουν παύλα αντί "
            L"για κοινή τιμή. Η αλλαγή επιλογής ή το κλικ σε ρυθμιστικό εφαρμόζει την τιμή σε όλες τις "
            L"επιλεγμένες οθόνες.\r\n\r\nΠΡΟΕΠΙΣΚΟΠΗΣΗ ΚΑΙ ΧΕΙΡΙΣΜΟΣ\r\nΧρησιμοποιήστε το FlightCorridor.scr "
            L"ως προφύλαξη οθόνης Windows με χωριστές ρυθμίσεις από την εφαρμογή. Η προεπισκόπηση πλήρους "
            L"οθόνης επιτρέπει ζωντανές αλλαγές. Το OK αποθηκεύει και το Άκυρο ή Esc απορρίπτει τις αλλαγές. "
            L"Τερματίστε την προφύλαξη με πλήκτρο ή κίνηση του ποντικιού.\r\n\r\nΑΠΑΙΤΗΣΕΙΣ ΣΥΣΤΗΜΑΤΟΣ\r\nΤα "
            L"Windows 7–11 υποστηρίζουν όλες τις λειτουργίες. Στα Windows Vista SP2 πρέπει να εγκατασταθούν "
            L"οι ενημερώσεις KB971512 και KB2117917. Απαιτείται υποστήριξη Direct3D 11."
        },
    }),
    DefineLanguage(LANG_BS, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Bosanski" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — kontrole" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Postavke programa FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Jezik:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Brzina animacije: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Let na odabranim monitorima" },
        LocalizedText{ TXT_ENABLE_ALL, L"Uključi sve" },
        LocalizedText{ TXT_DISABLE_ALL, L"Isključi sve" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Monitor animacije" },
        LocalizedText{ TXT_MONITOR, L"Monitor" },
        LocalizedText{ TXT_RESOLUTION, L"Rezolucija" },
        LocalizedText{ TXT_POSITION, L"Položaj" },
        LocalizedText{ TXT_PRIMARY, L"primarni" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Otkaži" },
        LocalizedText{ TXT_START_RECORDING, L"Pokreni snimanje…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Zaustavi snimanje" },
        LocalizedText{ TXT_PAUSE, L"Pauziraj" },
        LocalizedText{ TXT_RESUME, L"Nastavi" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Instaliraj čuvar ekrana" },
        LocalizedText{ TXT_EXIT, L"Izlaz" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animacija je pokrenuta…" },
        LocalizedText{ TXT_RECORDING, L"MP4 snimanje je u toku…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Snimak je sačuvan." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Nije moguće pokrenuti MP4 snimanje." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Čuvar ekrana nije instaliran." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Čuvar ekrana je instaliran." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Nije moguće inicijalizirati Direct3D prikazivač." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Let između četiri promjenjive površine" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Let kroz promjenjivi lijevak" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Zatvaranje aplikacije zaustavit će snimanje koje je u toku."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Posjeti web-mjesto %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Nije moguće otvoriti stranicu u podrazumijevanom pregledniku."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Nije moguće kopirati URL u međuspremnik." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Nije moguće kopirati informacije u međuspremnik."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Uključi pregled" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Isključi pregled" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animacija je pauzirana." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Spriječi čuvar ekrana tokom animacije" },
        LocalizedText{ TXT_READY_STATUS, L"Spreman." },
        LocalizedText{ TXT_HELP, L"Pomoć" },
        LocalizedText{ TXT_ABOUT, L"O programu" },
        LocalizedText{ TXT_CLOSE, L"Zatvori" },
        LocalizedText{ TXT_SNAPSHOT, L"Sačuvaj PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"PNG slika je sačuvana." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Nije moguće sačuvati PNG sliku." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Deinstaliraj čuvar ekrana" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Čuvar ekrana je deinstaliran." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Nije moguće deinstalirati čuvar ekrana. Zatvorite čuvar i njegov pregled pa pokušajte ponovo."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Zatvorite postavke programa FlightCorridor pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zatvorite Windows postavke čuvara ekrana pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zatvorite čuvar ili pregled preko cijelog ekrana tipkom Esc ili pomjeranjem miša pa ponovite "
            L"deinstalaciju."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardverski ubrzan let između promjenjivih površina." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Verzija:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Ciljna platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Web-mjesto:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Otvori u podrazumijevanom pregledniku" },
        LocalizedText{ TXT_COPY_URL, L"Kopiraj &adresu" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopiraj &informacije" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Glavno svjetlo" },
        LocalizedText{ TXT_FILL_LIGHT, L"Dopunsko svjetlo" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ambijentalno svjetlo" },
        LocalizedText{ TXT_RIM_LIGHT, L"Konturno svjetlo" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Tekstura" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Slobodno okretanje kamere" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauze i obrati" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Resurs licence nije dostupan." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Model monitora" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Frekvencija osvježavanja" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Dubina bita" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Format boje" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Prostor boja" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bita/kanal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bita/piksel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Postavke snimanja" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Rezolucija:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Broj kadrova u sekundi:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Promjene se primjenjuju na sljedeće MP4 snimanje." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMACIJA I POSTAVKE\r\nHardverski ubrzan let između promjenjivih površina. Let između četiri "
            L"promjenjive površine; Let kroz promjenjivi lijevak. Za svaki monitor odaberite tačno jednu "
            L"animaciju. Tekstura mijenja prikaz između teksturirane površine i žičanog modela. Slobodno "
            L"okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju "
            L"nasumično usporavanje, pauze i promjene smjera rotacije; let naprijed se nastavlja. Brzina je "
            L"0–1600%. Svaki monitor ima nezavisnu nasumičnu scenu koja se prikazuje prema njegovoj "
            L"frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i konturno "
            L"svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje samo na "
            L"teksturirane površine.\r\n\r\nMONITORI\r\nOdaberite jedan ili više redova u listi monitora. "
            L"Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije mijenjaju samo "
            L"postavke odabranih monitora. Odabir reda nije isto što i uključivanje izlaza njegovom kućicom. "
            L"Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili odabrani svi "
            L"monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na odabranim "
            L"monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, "
            L"ručkama klizača i dugmadima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju crticu "
            L"umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost "
            L"na sve odabrane monitore.\r\n\r\nUPRAVLJANJE\r\nPokrenite FlightCorridor.exe. Postavke se "
            L"stalno čuvaju i radi samo jedna instanca aplikacije. Kućica monitora ili dvostruki klik na red "
            L"uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 "
            L"bilježe prvi aktivni monitor animacije, ne zajedničku sliku svih monitora. Animacijski izlaz "
            L"snimanog monitora ne možete isključiti tokom snimanja; zatvaranje aplikacije tokom snimanja "
            L"zahtijeva potvrdu. Pauza i blokada čuvara ekrana vrijede za cijelu aplikaciju, bez obzira na "
            L"odabir monitora. Kada je blokada uključena, čuvar ekrana Windowsa se sprječava samo dok je na "
            L"barem jednom monitoru vidljiva animacija koja nije pauzirana. Aplikacija može instalirati i "
            L"deinstalirati ugrađeni čuvar ekrana.\r\n\r\nSNIMCI EKRANA I SNIMANJE\r\nU postavkama snimanja "
            L"odaberite Viewport ili TV. Viewport zadržava dimenzije i frekvenciju osvježavanja monitora do "
            L"60 kadrova u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u omjeru 16:9, s 50, 25, "
            L"59.94 (60000/1001) ili 29.97 (30000/1001) kadrova u sekundi. TV video je progresivni BT.709 "
            L"ograničenog raspona s poduzorkovanjem boje 4:2:0. Omjer slike ostaje sačuvan, a dopunske trake "
            L"su crne. OK čuva opcije za sljedeći snimak; Otkaži ili Esc odbacuje nepotvrđene izmjene. "
            L"Prozori snimanja, pomoći i informacija ne blokiraju ostale prozore i mogu se minimizirati. Tab "
            L"i Shift+Tab pomjeraju fokus, Enter aktivira fokusirano dugme, a Esc zatvara aktivni pomoćni "
            L"prozor.\r\n\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 "
            L"morate instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je "
            L"Direct3D 11, a za MP4 i Media Foundation te H.264 koder. Interfejs i dokumentacija dostupni su "
            L"na 36 jezika."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACIJA I POSTAVKE\r\nHardverski ubrzan let između promjenjivih površina. Let između četiri "
            L"promjenjive površine; Let kroz promjenjivi lijevak. Za svaki monitor odaberite tačno jednu "
            L"animaciju. Tekstura mijenja prikaz između teksturirane površine i žičanog modela. Slobodno "
            L"okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju "
            L"nasumično usporavanje, pauze i promjene smjera rotacije; let naprijed se nastavlja. Brzina je "
            L"0–1600%. Svaki monitor ima nezavisnu nasumičnu scenu koja se prikazuje prema njegovoj "
            L"frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i konturno "
            L"svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje samo na "
            L"teksturirane površine.\r\n\r\nMONITORI\r\nOdaberite jedan ili više redova u listi monitora. "
            L"Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije mijenjaju samo "
            L"postavke odabranih monitora. Odabir reda nije isto što i uključivanje izlaza njegovom kućicom. "
            L"Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili odabrani svi "
            L"monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na odabranim "
            L"monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, "
            L"ručkama klizača i dugmadima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju crticu "
            L"umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost "
            L"na sve odabrane monitore.\r\n\r\nPREGLED I UPRAVLJANJE\r\nKoristite FlightCorridor.scr kao "
            L"Windows čuvar ekrana s odvojenim postavkama. Pregled preko cijelog ekrana omogućava izmjene "
            L"uživo. OK čuva, a Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili "
            L"pomjeranjem miša.\r\n\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za Windows "
            L"Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917. Potreban je Direct3D 11."
        },
    }),
    DefineLanguage(LANG_HR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Hrvatski" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — upravljanje" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Postavke programa FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Jezik:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Brzina animacije: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Let na odabranim zaslonima" },
        LocalizedText{ TXT_ENABLE_ALL, L"Uključi sve" },
        LocalizedText{ TXT_DISABLE_ALL, L"Isključi sve" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Zaslon animacije" },
        LocalizedText{ TXT_MONITOR, L"Zaslon" },
        LocalizedText{ TXT_RESOLUTION, L"Razlučivost" },
        LocalizedText{ TXT_POSITION, L"Položaj" },
        LocalizedText{ TXT_PRIMARY, L"primarni" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Odustani" },
        LocalizedText{ TXT_START_RECORDING, L"Pokreni snimanje…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Zaustavi snimanje" },
        LocalizedText{ TXT_PAUSE, L"Pauziraj" },
        LocalizedText{ TXT_RESUME, L"Nastavi" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Instaliraj čuvar zaslona" },
        LocalizedText{ TXT_EXIT, L"Izlaz" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animacija je pokrenuta…" },
        LocalizedText{ TXT_RECORDING, L"MP4 snimanje je u tijeku…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Snimka je spremljena." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Nije moguće pokrenuti MP4 snimanje." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Čuvar zaslona nije instaliran." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Čuvar zaslona je instaliran." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Nije moguće inicijalizirati Direct3D prikazivač." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Let između četiriju promjenjivih ploha" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Let kroz promjenjivi lijevak" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Zatvaranje aplikacije zaustavit će snimanje koje je u tijeku."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Posjeti web-mjesto %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Nije moguće otvoriti stranicu u zadanom pregledniku." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Nije moguće kopirati URL u međuspremnik." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Nije moguće kopirati informacije u međuspremnik."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Uključi pretpregled" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Isključi pretpregled" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animacija je pauzirana." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Spriječi čuvar zaslona tijekom animacije" },
        LocalizedText{ TXT_READY_STATUS, L"Spreman." },
        LocalizedText{ TXT_HELP, L"Pomoć" },
        LocalizedText{ TXT_ABOUT, L"O programu" },
        LocalizedText{ TXT_CLOSE, L"Zatvori" },
        LocalizedText{ TXT_SNAPSHOT, L"Spremi PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"PNG slika je spremljena." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Nije moguće spremiti PNG sliku." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Deinstaliraj čuvar zaslona" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Čuvar zaslona je deinstaliran." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Nije moguće deinstalirati čuvar zaslona. Zatvorite čuvar i njegov pretpregled pa pokušajte "
            L"ponovno."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Zatvorite postavke programa FlightCorridor pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zatvorite Windows postavke čuvara zaslona pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zatvorite čuvar ili pretpregled preko cijelog zaslona tipkom Esc ili pomicanjem miša pa "
            L"ponovite deinstalaciju."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardverski ubrzan let između promjenjivih ploha." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Verzija:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Ciljna platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Web-mjesto:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Otvori u zadanom pregledniku" },
        LocalizedText{ TXT_COPY_URL, L"Kopiraj &adresu" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopiraj &informacije" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Glavno svjetlo" },
        LocalizedText{ TXT_FILL_LIGHT, L"Dopunsko svjetlo" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ambijentalno svjetlo" },
        LocalizedText{ TXT_RIM_LIGHT, L"Konturno svjetlo" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Tekstura" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Slobodno okretanje kamere" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauze i obrati" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Resurs licence nije dostupan." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Model zaslona" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Frekvencija osvježavanja" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Dubina bita" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Oblik boje" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Prostor boja" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bita/kanal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bita/piksel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Postavke snimanja" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Razlučivost:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Broj sličica u sekundi:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Promjene se primjenjuju na sljedeće MP4 snimanje." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMACIJA I POSTAVKE\r\nHardverski ubrzan let između promjenjivih ploha. Let između četiriju "
            L"promjenjivih ploha; Let kroz promjenjivi lijevak. Za svaki zaslon odaberite točno jednu "
            L"animaciju. Tekstura mijenja prikaz između teksturirane plohe i žičanog modela. Slobodno "
            L"okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju "
            L"nasumično usporavanje, stanke i promjene smjera rotacije; let naprijed se nastavlja. Brzina je "
            L"0–1600%. Svaki zaslon ima neovisnu nasumičnu scenu koja se prikazuje prema njegovoj "
            L"frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i konturno "
            L"svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje samo na "
            L"teksturirane površine.\r\n\r\nMONITORI\r\nOdaberite jedan ili više redaka na popisu zaslona. "
            L"Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije mijenjaju samo "
            L"postavke odabranih zaslona. Odabir retka nije isto što i uključivanje izlaza njegovim "
            L"potvrdnim okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar zaslona. Ako su prethodno "
            L"bili odabrani svi zasloni, uključuju se i novopriključeni zasloni. Različite vrijednosti na "
            L"odabranim zaslonima prikazuju se neodređenim stanjem potvrdnih okvira i točkastim uzorkom na "
            L"izbornim gumbima, ručkama klizača i gumbima „Uključi sve“ i „Isključi sve“. Oznake klizača "
            L"prikazuju crticu umjesto zajedničke vrijednosti. Promjena mogućnosti ili klik na klizač "
            L"primjenjuje tu vrijednost na sve odabrane zaslone.\r\n\r\nUPRAVLJANJE\r\nPokrenite "
            L"FlightCorridor.exe. Postavke se neprekidno spremaju i radi samo jedna instanca aplikacije. "
            L"Potvrdni okvir zaslona ili dvostruki klik na redak uključuje ili isključuje animacijski izlaz. "
            L"Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe prvi aktivni zaslon animacije, ne "
            L"zajedničku sliku svih zaslona. Animacijski izlaz snimanog zaslona ne možete isključiti tijekom "
            L"snimanja; zatvaranje aplikacije tijekom snimanja zahtijeva potvrdu. Pauza i blokada čuvara "
            L"zaslona vrijede za cijelu aplikaciju, bez obzira na odabir zaslona. Kada je blokada uključena, "
            L"čuvar zaslona sustava Windows sprječava se samo dok je na barem jednom zaslonu vidljiva "
            L"animacija koja nije pauzirana. Aplikacija može instalirati i deinstalirati ugrađeni čuvar "
            L"zaslona.\r\n\r\nSNIMKE ZASLONA I SNIMANJE\r\nU postavkama snimanja odaberite Viewport ili TV. "
            L"Viewport zadržava dimenzije i frekvenciju osvježavanja zaslona do 60 sličica u sekundi. TV "
            L"nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u omjeru 16:9, s 50, 25, 59.94 (60000/1001) ili "
            L"29.97 (30000/1001) sličica u sekundi. TV video je progresivni BT.709 ograničenog raspona s "
            L"poduzorkovanjem boje 4:2:0. Omjer slike ostaje sačuvan, a dopunske trake su crne. OK sprema "
            L"mogućnosti za sljedeću snimku; Odustani ili Esc odbacuje nepotvrđene izmjene. Prozori "
            L"snimanja, pomoći i informacija ne blokiraju ostale prozore i mogu se minimizirati. Tab i "
            L"Shift+Tab pomiču fokus, Enter aktivira fokusirani gumb, a Esc zatvara aktivni pomoćni prozor.\r"
            L"\n\r\nZAHTJEVI SUSTAVA\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate "
            L"instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je "
            L"Direct3D 11, a za MP4 i Media Foundation te H.264 koder. Sučelje i dokumentacija dostupni su "
            L"na 36 jezika."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACIJA I POSTAVKE\r\nHardverski ubrzan let između promjenjivih ploha. Let između četiriju "
            L"promjenjivih ploha; Let kroz promjenjivi lijevak. Za svaki zaslon odaberite točno jednu "
            L"animaciju. Tekstura mijenja prikaz između teksturirane plohe i žičanog modela. Slobodno "
            L"okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju "
            L"nasumično usporavanje, stanke i promjene smjera rotacije; let naprijed se nastavlja. Brzina je "
            L"0–1600%. Svaki zaslon ima neovisnu nasumičnu scenu koja se prikazuje prema njegovoj "
            L"frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i konturno "
            L"svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje samo na "
            L"teksturirane površine.\r\n\r\nMONITORI\r\nOdaberite jedan ili više redaka na popisu zaslona. "
            L"Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije mijenjaju samo "
            L"postavke odabranih zaslona. Odabir retka nije isto što i uključivanje izlaza njegovim "
            L"potvrdnim okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar zaslona. Ako su prethodno "
            L"bili odabrani svi zasloni, uključuju se i novopriključeni zasloni. Različite vrijednosti na "
            L"odabranim zaslonima prikazuju se neodređenim stanjem potvrdnih okvira i točkastim uzorkom na "
            L"izbornim gumbima, ručkama klizača i gumbima „Uključi sve“ i „Isključi sve“. Oznake klizača "
            L"prikazuju crticu umjesto zajedničke vrijednosti. Promjena mogućnosti ili klik na klizač "
            L"primjenjuje tu vrijednost na sve odabrane zaslone.\r\n\r\nPRETPREGLED I UPRAVLJANJE\r\n"
            L"Koristite FlightCorridor.scr kao Windows čuvar zaslona s odvojenim postavkama. Pretpregled "
            L"preko cijelog zaslona omogućuje izmjene uživo. OK sprema, a Odustani ili Esc odbacuje izmjene. "
            L"Iz čuvara izađite pritiskom tipke ili pomicanjem miša.\r\n\r\nZAHTJEVI SUSTAVA\r\nWindows 7–11 "
            L"podržava sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i "
            L"KB2117917. Potreban je Direct3D 11."
        },
    }),
    DefineLanguage(LANG_SL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Slovenščina" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — upravljanje" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Nastavitve FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Jezik:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Hitrost animacije: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Let na izbranih zaslonih" },
        LocalizedText{ TXT_ENABLE_ALL, L"Vklopi vse" },
        LocalizedText{ TXT_DISABLE_ALL, L"Izklopi vse" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Zaslon animacije" },
        LocalizedText{ TXT_MONITOR, L"Zaslon" },
        LocalizedText{ TXT_RESOLUTION, L"Ločljivost" },
        LocalizedText{ TXT_POSITION, L"Položaj" },
        LocalizedText{ TXT_PRIMARY, L"glavni" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Prekliči" },
        LocalizedText{ TXT_START_RECORDING, L"Začni snemanje…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Ustavi snemanje" },
        LocalizedText{ TXT_PAUSE, L"Premor" },
        LocalizedText{ TXT_RESUME, L"Nadaljuj" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Namesti ohranjevalnik zaslona" },
        LocalizedText{ TXT_EXIT, L"Izhod" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animacija se izvaja…" },
        LocalizedText{ TXT_RECORDING, L"Snemanje MP4 poteka…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Posnetek je shranjen." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Snemanja MP4 ni bilo mogoče začeti." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Ohranjevalnik zaslona ni nameščen." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Ohranjevalnik zaslona je nameščen." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Upodabljalnika Direct3D ni bilo mogoče inicializirati." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Let med štirimi spreminjajočimi se ploskvami" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Let skozi spreminjajoči se lijak" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Zapiranje programa bo ustavilo trenutno snemanje." },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Obišči spletno mesto %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Spletnega mesta ni mogoče odpreti v privzetem brskalniku."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL-ja ni bilo mogoče kopirati v odložišče." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Podatkov ni bilo mogoče kopirati v odložišče." },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Vklopi predogled" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Izklopi predogled" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animacija je začasno ustavljena." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Prepreči ohranjevalnik med animacijo" },
        LocalizedText{ TXT_READY_STATUS, L"Pripravljen." },
        LocalizedText{ TXT_HELP, L"Pomoč" },
        LocalizedText{ TXT_ABOUT, L"O programu" },
        LocalizedText{ TXT_CLOSE, L"Zapri" },
        LocalizedText{ TXT_SNAPSHOT, L"Shrani PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Slika PNG je shranjena." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Slike PNG ni bilo mogoče shraniti." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Odstrani ohranjevalnik zaslona" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Ohranjevalnik zaslona je odstranjen." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Ohranjevalnika zaslona ni bilo mogoče odstraniti. Zaprite ga in njegov predogled ter poskusite "
            L"znova."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Zaprite nastavitve FlightCorridor in znova poskusite odstranitev."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zaprite nastavitve ohranjevalnika zaslona Windows in znova poskusite odstranitev."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zaprite ohranjevalnik ali celozaslonski predogled s tipko Esc ali premikom miške in znova "
            L"poskusite odstranitev."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Strojno pospešen let med spreminjajočimi se ploskvami." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Različica:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Ciljna platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Spletno mesto:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Odpri v privzetem brskalniku" },
        LocalizedText{ TXT_COPY_URL, L"Kopiraj &naslov" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopiraj &podatke" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Glavna svetloba" },
        LocalizedText{ TXT_FILL_LIGHT, L"Dopolnilna svetloba" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Okoljska svetloba" },
        LocalizedText{ TXT_RIM_LIGHT, L"Obrobna svetloba" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Tekstura" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Prosto vrtenje kamere" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Premori in obrati" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Vir licence ni na voljo." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Model zaslona" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Hitrost osveževanja" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Bitna globina" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Oblika barv" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Barvni prostor" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bitov/kanal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bitov/slikovno piko" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Nastavitve snemanja" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Ločljivost:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Hitrost sličic:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Spremembe veljajo za naslednje snemanje MP4." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMACIJA IN NASTAVITVE\r\nStrojno pospešen let med spreminjajočimi se ploskvami. Let med "
            L"štirimi spreminjajočimi se ploskvami; Let skozi spreminjajoči se lijak. Za vsak zaslon "
            L"izberite natanko eno animacijo. Tekstura preklaplja med teksturirano ploskvijo in žičnim "
            L"modelom. Prosto vrtenje kamere počasi spreminja smer pogleda v vseh treh razsežnostih. Premori "
            L"in obrati dodajo naključne upočasnitve, premore in obrate smeri vrtenja; let naprej se "
            L"nadaljuje. Hitrost je 0–1600%. Vsak zaslon ima neodvisen naključen prizor, ki se izrisuje z "
            L"njegovo hitrostjo osveževanja. Glavno svetlobo, dopolnilno svetlobo, okoljsko svetlobo in "
            L"obrobno svetlobo je mogoče neodvisno vklapljati za izbrane zaslone. Osvetlitev velja samo za "
            L"teksturirane površine.\r\n\r\nZASLONI\r\nNa seznamu zaslonov izberite eno ali več vrstic. "
            L"Ctrl+A izbere vse, Ctrl in Shift pa spreminjata izbor. Kontrolniki in drsniki animacije "
            L"spreminjajo samo nastavitve izbranih zaslonov. Izbira vrstice ni isto kot vklop izhoda z "
            L"njenim potrditvenim poljem. Izbor se ločeno shrani za program in ohranjevalnik. Če so bili "
            L"izbrani vsi zasloni, so vključeni tudi na novo priključeni zasloni. Različne vrednosti na "
            L"izbranih zaslonih označujeta nedoločeno stanje potrditvenih polj in pikčast vzorec na izbirnih "
            L"gumbih, ročicah drsnikov ter gumbih »Vklopi vse« in »Izklopi vse«. Oznake drsnikov namesto "
            L"skupne vrednosti prikazujejo pomišljaj. Sprememba možnosti ali klik na drsnik uveljavi to "
            L"vrednost na vseh izbranih zaslonih.\r\n\r\nUPRAVLJANJE\r\nZaženite FlightCorridor.exe. "
            L"Nastavitve se shranjujejo sproti in deluje le en primerek programa. Polje zaslona ali dvojni "
            L"klik na vrstico vklopi ali izklopi izhod animacije. Animacijo lahko začasno ustavite in "
            L"nadaljujete. PNG in MP4 zajameta prvi aktivni zaslon animacije, ne skupne slike vseh zaslonov. "
            L"Izhoda animacije snemanega zaslona med snemanjem ni mogoče izklopiti; zapiranje programa med "
            L"snemanjem zahteva potrditev. Premor in preprečevanje ohranjevalnika veljata za celoten "
            L"program, ne glede na izbor zaslonov. Ko je preprečevanje vključeno, se ohranjevalnik Windows "
            L"prepreči le, dokler je na vsaj enem zaslonu vidna animacija, ki ni ustavljena. Program lahko "
            L"namesti ali odstrani vgrajeni ohranjevalnik.\r\n\r\nPOSNETKI ZASLONA IN SNEMANJE\r\nV "
            L"nastavitvah snemanja izberite Viewport ali TV. Viewport ohrani velikost in hitrost osveževanja "
            L"zaslona do 60 sličic na sekundo. TV ponuja 1920 × 1080, 1440 × 1080 ali 1280 × 720 v razmerju "
            L"16:9 ter 50, 25, 59.94 (60000/1001) ali 29.97 (30000/1001) sličic na sekundo. TV uporablja "
            L"progresivni BT.709 z omejenim obsegom in barvnim podvzorčenjem 4:2:0. Razmerje slike se "
            L"ohrani, dopolnilni pasovi so črni. OK shrani izbiro za naslednje snemanje; Prekliči ali Esc "
            L"zavrže nepotrjene spremembe. Okna snemanja, pomoči in podatkov o programu ne blokirajo drugih "
            L"oken in jih je mogoče minimirati. Tab in Shift+Tab premikata fokus, Enter aktivira izbrani "
            L"gumb, Esc pa zapre aktivno pomožno okno.\r\n\r\nSISTEMSKE ZAHTEVE\r\nWindows 7–11 podpira vse "
            L"funkcije. Za Windows Vista SP2 morate namestiti posodobitvi KB971512 in KB2117917; snemanje "
            L"MP4 v Visti ne deluje. Potrebna je podpora Direct3D 11, za MP4 pa še Media Foundation in "
            L"kodirnik H.264. Vmesnik in dokumentacija sta na voljo v 36 jezikih."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACIJA IN NASTAVITVE\r\nStrojno pospešen let med spreminjajočimi se ploskvami. Let med "
            L"štirimi spreminjajočimi se ploskvami; Let skozi spreminjajoči se lijak. Za vsak zaslon "
            L"izberite natanko eno animacijo. Tekstura preklaplja med teksturirano ploskvijo in žičnim "
            L"modelom. Prosto vrtenje kamere počasi spreminja smer pogleda v vseh treh razsežnostih. Premori "
            L"in obrati dodajo naključne upočasnitve, premore in obrate smeri vrtenja; let naprej se "
            L"nadaljuje. Hitrost je 0–1600%. Vsak zaslon ima neodvisen naključen prizor, ki se izrisuje z "
            L"njegovo hitrostjo osveževanja. Glavno svetlobo, dopolnilno svetlobo, okoljsko svetlobo in "
            L"obrobno svetlobo je mogoče neodvisno vklapljati za izbrane zaslone. Osvetlitev velja samo za "
            L"teksturirane površine.\r\n\r\nZASLONI\r\nNa seznamu zaslonov izberite eno ali več vrstic. "
            L"Ctrl+A izbere vse, Ctrl in Shift pa spreminjata izbor. Kontrolniki in drsniki animacije "
            L"spreminjajo samo nastavitve izbranih zaslonov. Izbira vrstice ni isto kot vklop izhoda z "
            L"njenim potrditvenim poljem. Izbor se ločeno shrani za program in ohranjevalnik. Če so bili "
            L"izbrani vsi zasloni, so vključeni tudi na novo priključeni zasloni. Različne vrednosti na "
            L"izbranih zaslonih označujeta nedoločeno stanje potrditvenih polj in pikčast vzorec na izbirnih "
            L"gumbih, ročicah drsnikov ter gumbih »Vklopi vse« in »Izklopi vse«. Oznake drsnikov namesto "
            L"skupne vrednosti prikazujejo pomišljaj. Sprememba možnosti ali klik na drsnik uveljavi to "
            L"vrednost na vseh izbranih zaslonih.\r\n\r\nPREDOGLED IN UPRAVLJANJE\r\nUporabite "
            L"FlightCorridor.scr kot ohranjevalnik zaslona Windows z ločenimi nastavitvami. Celozaslonski "
            L"predogled omogoča sprotne spremembe. OK jih shrani, Prekliči ali Esc jih zavrže. Ohranjevalnik "
            L"zapustite s tipko ali premikom miške.\r\n\r\nSISTEMSKE ZAHTEVE\r\nWindows 7–11 podpira vse "
            L"funkcije. Za Windows Vista SP2 morate namestiti posodobitvi KB971512 in KB2117917. Potrebna je "
            L"podpora Direct3D 11."
        },
    }),
    DefineLanguage(LANG_CNR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Crnogorski" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — kontrole" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Podešavanja programa FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Jezik:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Brzina animacije: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Let na izabranim monitorima" },
        LocalizedText{ TXT_ENABLE_ALL, L"Uključi sve" },
        LocalizedText{ TXT_DISABLE_ALL, L"Isključi sve" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Monitor animacije" },
        LocalizedText{ TXT_MONITOR, L"Monitor" },
        LocalizedText{ TXT_RESOLUTION, L"Rezolucija" },
        LocalizedText{ TXT_POSITION, L"Položaj" },
        LocalizedText{ TXT_PRIMARY, L"primarni" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Otkaži" },
        LocalizedText{ TXT_START_RECORDING, L"Pokreni snimanje…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Zaustavi snimanje" },
        LocalizedText{ TXT_PAUSE, L"Pauziraj" },
        LocalizedText{ TXT_RESUME, L"Nastavi" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Instaliraj čuvar ekrana" },
        LocalizedText{ TXT_EXIT, L"Izlaz" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Animacija je pokrenuta…" },
        LocalizedText{ TXT_RECORDING, L"MP4 snimanje je u toku…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Snimak je sačuvan." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Nije moguće pokrenuti MP4 snimanje." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Čuvar ekrana nije instaliran." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Čuvar ekrana je instaliran." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Nije moguće inicijalizovati Direct3D prikazivač." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Let između četiri promjenljive površine" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Let kroz promjenljivi lijevak" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Zatvaranje aplikacije zaustaviće snimanje koje je u toku."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Otvori veb-sajt %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Nije moguće otvoriti stranicu u podrazumijevanom pregledaču."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Nije moguće kopirati URL u međuspremnik." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Nije moguće kopirati podatke u međuspremnik." },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Uključi pregled" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Isključi pregled" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animacija je pauzirana." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Spriječi čuvar ekrana tokom animacije" },
        LocalizedText{ TXT_READY_STATUS, L"Spreman." },
        LocalizedText{ TXT_HELP, L"Pomoć" },
        LocalizedText{ TXT_ABOUT, L"O programu" },
        LocalizedText{ TXT_CLOSE, L"Zatvori" },
        LocalizedText{ TXT_SNAPSHOT, L"Sačuvaj PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"PNG slika je sačuvana." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Nije moguće sačuvati PNG sliku." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Deinstaliraj čuvar ekrana" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Čuvar ekrana je deinstaliran." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Nije moguće deinstalirati čuvar ekrana. Zatvorite čuvar i njegov pregled pa pokušajte ponovo."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Zatvorite podešavanja programa FlightCorridor pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zatvorite Windows podešavanja čuvara ekrana pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zatvorite čuvar ili pregled preko cijelog ekrana tasterom Esc ili pomjeranjem miša pa ponovite "
            L"deinstalaciju."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardverski ubrzan let između promjenljivih površina." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Verzija:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Ciljna platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Veb-sajt:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Otvori u podrazumijevanom pregledaču" },
        LocalizedText{ TXT_COPY_URL, L"Kopiraj &adresu" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopiraj &podatke" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Glavno svjetlo" },
        LocalizedText{ TXT_FILL_LIGHT, L"Dopunsko svjetlo" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ambijentalno svjetlo" },
        LocalizedText{ TXT_RIM_LIGHT, L"Konturno svjetlo" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Tekstura" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Slobodno okretanje kamere" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Pauze i obrati" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Resurs licence nije dostupan." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Model monitora" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Frekvencija osvježavanja" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Dubina bita" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Format boje" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Prostor boja" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u bita/kanal" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u bita/piksel" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Podešavanja snimanja" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Rezolucija:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Broj kadrova u sekundi:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Promjene se primjenjuju na sljedeće MP4 snimanje." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"ANIMACIJA I PODEŠAVANJA\r\nHardverski ubrzan let između promjenljivih površina. Let između "
            L"četiri promjenljive površine; Let kroz promjenljivi lijevak. Za svaki monitor izaberite tačno "
            L"jednu animaciju. Tekstura mijenja prikaz između teksturisane površine i žičanog modela. "
            L"Slobodno okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati "
            L"dodaju nasumično usporavanje, pauze i promjene smjera rotacije; let naprijed se nastavlja. "
            L"Brzina je 0–1600%. Svaki monitor ima nezavisnu nasumičnu scenu koja se prikazuje prema "
            L"njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i "
            L"konturno svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje "
            L"samo na teksturirane površine.\r\n\r\nMONITORI\r\nIzaberite jedan ili više redova u listi "
            L"monitora. Ctrl+A bira sve; Ctrl i Shift mijenjaju izbor. Kontrole i klizači animacije "
            L"mijenjaju samo podešavanja izabranih monitora. Izbor reda nije isto što i uključivanje izlaza "
            L"njegovom kućicom. Izbor se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
            L"izabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na "
            L"izabranim monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima "
            L"izbora, ručkama klizača i dugmadima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju "
            L"crticu umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu "
            L"vrijednost na sve izabrane monitore.\r\n\r\nUPRAVLJANJE\r\nPokrenite FlightCorridor.exe. "
            L"Podešavanja se stalno čuvaju i radi samo jedna instanca aplikacije. Kućica monitora ili "
            L"dvostruki klik na red uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i "
            L"nastaviti. PNG i MP4 bilježe prvi aktivni monitor animacije, ne zajedničku sliku svih "
            L"monitora. Animacijski izlaz snimanog monitora ne možete isključiti tokom snimanja; zatvaranje "
            L"aplikacije tokom snimanja zahtijeva potvrdu. Pauza i blokada čuvara ekrana važe za cijelu "
            L"aplikaciju, bez obzira na izbor monitora. Kada je blokada uključena, čuvar ekrana Windowsa se "
            L"sprječava samo dok je na barem jednom monitoru vidljiva animacija koja nije pauzirana. "
            L"Aplikacija može instalirati i deinstalirati ugrađeni čuvar ekrana.\r\n\r\nSNIMCI EKRANA I "
            L"SNIMANJE\r\nU podešavanjima snimanja izaberite Viewport ili TV. Viewport zadržava dimenzije i "
            L"frekvenciju osvježavanja monitora do 60 kadrova u sekundi. TV nudi 1920 × 1080, 1440 × 1080 "
            L"ili 1280 × 720 u odnosu 16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) kadrova u "
            L"sekundi. TV video je progresivni BT.709 ograničenog opsega s poduzorkovanjem boje 4:2:0. Odnos "
            L"slike ostaje sačuvan, a dopunske trake su crne. OK čuva opcije za sljedeći snimak; Otkaži ili "
            L"Esc odbacuje nepotvrđene izmjene. Prozori snimanja, pomoći i informacija ne blokiraju ostale "
            L"prozore i mogu se minimizovati. Tab i Shift+Tab pomjeraju fokus, Enter aktivira fokusirano "
            L"dugme, a Esc zatvara aktivni pomoćni prozor.\r\n\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 "
            L"podržava sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i "
            L"KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media Foundation "
            L"i H.264 koder. Interfejs i dokumentacija dostupni su na 36 jezika."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACIJA I PODEŠAVANJA\r\nHardverski ubrzan let između promjenljivih površina. Let između "
            L"četiri promjenljive površine; Let kroz promjenljivi lijevak. Za svaki monitor izaberite tačno "
            L"jednu animaciju. Tekstura mijenja prikaz između teksturisane površine i žičanog modela. "
            L"Slobodno okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati "
            L"dodaju nasumično usporavanje, pauze i promjene smjera rotacije; let naprijed se nastavlja. "
            L"Brzina je 0–1600%. Svaki monitor ima nezavisnu nasumičnu scenu koja se prikazuje prema "
            L"njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i "
            L"konturno svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje "
            L"samo na teksturirane površine.\r\n\r\nMONITORI\r\nIzaberite jedan ili više redova u listi "
            L"monitora. Ctrl+A bira sve; Ctrl i Shift mijenjaju izbor. Kontrole i klizači animacije "
            L"mijenjaju samo podešavanja izabranih monitora. Izbor reda nije isto što i uključivanje izlaza "
            L"njegovom kućicom. Izbor se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
            L"izabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na "
            L"izabranim monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima "
            L"izbora, ručkama klizača i dugmadima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju "
            L"crticu umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu "
            L"vrijednost na sve izabrane monitore.\r\n\r\nPREGLED I UPRAVLJANJE\r\nKoristite "
            L"FlightCorridor.scr kao Windows čuvar ekrana s odvojenim podešavanjima. Pregled preko cijelog "
            L"ekrana omogućava izmjene uživo. OK čuva, a Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite "
            L"pritiskom tastera ili pomjeranjem miša.\r\n\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve "
            L"funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917. Potreban je "
            L"Direct3D 11."
        },
    }),
    DefineLanguage(LANG_BE, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Беларуская" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — кіраванне" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Налады FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Мова:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Хуткасць анімацыі: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Палёт на выбраных маніторах" },
        LocalizedText{ TXT_ENABLE_ALL, L"Уключыць усё" },
        LocalizedText{ TXT_DISABLE_ALL, L"Выключыць усё" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Манітор анімацыі" },
        LocalizedText{ TXT_MONITOR, L"Манітор" },
        LocalizedText{ TXT_RESOLUTION, L"Раздзяляльнасць" },
        LocalizedText{ TXT_POSITION, L"Пазіцыя" },
        LocalizedText{ TXT_PRIMARY, L"асноўны" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Скасаваць" },
        LocalizedText{ TXT_START_RECORDING, L"Пачаць запіс…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Спыніць запіс" },
        LocalizedText{ TXT_PAUSE, L"Прыпыніць" },
        LocalizedText{ TXT_RESUME, L"Працягнуць" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Усталяваць застаўку" },
        LocalizedText{ TXT_EXIT, L"Выйсці" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Анімацыя працуе…" },
        LocalizedText{ TXT_RECORDING, L"Ідзе запіс MP4…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Запіс захаваны." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Не ўдалося пачаць запіс MP4." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Застаўка не ўсталявана." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Застаўка ўсталявана." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Не ўдалося ініцыялізаваць візуалізатар Direct3D." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Палёт паміж чатырма зменлівымі паверхнямі" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Палёт праз зменлівую варонку" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Закрыццё праграмы спыніць бягучы запіс." },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Адкрыць вэб-сайт %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Немагчыма адкрыць сайт у прадвызначаным браўзеры." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Не ўдалося скапіяваць URL у буфер абмену." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Не ўдалося скапіяваць звесткі ў буфер абмену." },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Уключыць перадпрагляд" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Выключыць перадпрагляд" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Анімацыя прыпынена." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Блакаваць застаўку падчас анімацыі" },
        LocalizedText{ TXT_READY_STATUS, L"Гатовы." },
        LocalizedText{ TXT_HELP, L"Даведка" },
        LocalizedText{ TXT_ABOUT, L"Пра праграму" },
        LocalizedText{ TXT_CLOSE, L"Закрыць" },
        LocalizedText{ TXT_SNAPSHOT, L"Захаваць PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Відарыс PNG захаваны." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Не ўдалося захаваць відарыс PNG." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Выдаліць застаўку" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Застаўка выдалена." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Не ўдалося выдаліць застаўку. Закрыйце яе і перадпрагляд ды паўтарыце спробу."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Закрыйце налады FlightCorridor ды паўтарыце выдаленне."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Закрыйце акно налад застаўкі Windows ды паўтарыце выдаленне."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Завяршыце застаўку або поўнаэкранны перадпрагляд клавішай Esc ці рухам мышы ды паўтарыце "
            L"выдаленне."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Апаратна паскораны палёт паміж зменлівымі паверхнямі." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Версія:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Мэтавая платформа:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Вэб-сайт:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Адкрыць у прадвызначаным браўзеры" },
        LocalizedText{ TXT_COPY_URL, L"Капіяваць &адрас" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Капіяваць &звесткі" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Асноўнае святло" },
        LocalizedText{ TXT_FILL_LIGHT, L"Запаўняльнае святло" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Фонавае святло" },
        LocalizedText{ TXT_RIM_LIGHT, L"Контурнае святло" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Тэкстура" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Свабоднае кручэнне камеры" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Паўзы і развароты" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Рэсурс ліцэнзіі недаступны." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Мадэль манітора" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Частата абнаўлення" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Бітавая глыбіня" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Фармат колеру" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Каляровая прастора" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u біт/канал" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u біт/піксель" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Налады запісу" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Раздзяляльнасць:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Частата кадраў:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Змены будуць ужытыя да наступнага запісу MP4." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"АНІМАЦЫЯ І НАЛАДЫ\r\nАпаратна паскораны палёт паміж зменлівымі паверхнямі. Палёт паміж чатырма "
            L"зменлівымі паверхнямі; Палёт праз зменлівую варонку. Для кожнага манітора выберыце роўна адну "
            L"анімацыю. Тэкстура пераключае тэкстураваную паверхню і каркасную мадэль. Свабоднае кручэнне "
            L"камеры павольна змяняе напрамак погляду ва ўсіх трох вымярэннях. Паўзы і развароты дадаюць "
            L"выпадковыя запаволенні, паўзы і змены напрамку кручэння; палёт наперад працягваецца. Хуткасць "
            L"— 0–1600%. Кожны манітор мае незалежную выпадковую сцэну з вывадам паводле ўласнай частаты "
            L"абнаўлення. Асноўнае, запаўняльнае, фонавае і контурнае святло можна пераключаць незалежна для "
            L"выбраных манітораў. Асвятленне дзейнічае толькі на тэкстураваных паверхнях.\r\n\r\nМАНІТОРЫ\r\n"
            L"Выберыце адзін або некалькі радкоў у спісе манітораў. Ctrl+A выбірае ўсе; Ctrl і Shift "
            L"змяняюць выбар. Элементы кіравання і паўзункі анімацыі змяняюць толькі налады выбраных "
            L"манітораў. Выбар радка і ўключэнне вываду яго сцяжком — розныя дзеянні. Выбар асобна "
            L"захоўваецца для праграмы і застаўкі. Калі раней былі выбраны ўсе маніторы, да выбару "
            L"далучаюцца і новыя маніторы. Розныя значэнні на выбраных маніторах пазначаюцца нявызначаным "
            L"станам сцяжкоў і кропкавым узорам на пераключальніках, ручках паўзункоў і кнопках «Уключыць "
            L"усё» і «Выключыць усё». У подпісах паўзункоў замест агульнага значэння паказваецца працяжнік. "
            L"Змена параметра або націск на паўзунок ужывае гэта значэнне да ўсіх выбраных манітораў.\r\n\r\n"
            L"КІРАВАННЕ\r\nЗапусціце FlightCorridor.exe. Налады захоўваюцца пастаянна, працуе толькі адзін "
            L"асобнік праграмы. Сцяжок манітора або падвойнае націсканне на радок уключае ці выключае вывад "
            L"анімацыі. Анімацыю можна прыпыніць і працягнуць. PNG і MP4 захопліваюць першы актыўны манітор "
            L"анімацыі, а не агульны відарыс усіх манітораў. Падчас запісу нельга выключыць вывад анімацыі "
            L"манітора, які запісваецца; закрыццё праграмы падчас запісу патрабуе пацвярджэння. Прыпыненне і "
            L"блакаванне застаўкі дзейнічаюць на ўсю праграму незалежна ад выбару манітораў. Калі блакаванне "
            L"ўключана, застаўка Windows не запускаецца толькі пакуль хаця б на адным маніторы бачная "
            L"непрыпыненая анімацыя. Праграма можа ўсталяваць або выдаліць убудаваную застаўку.\r\n\r\n"
            L"ЗДЫМКІ ЭКРАНА І ЗАПІС\r\nУ наладах запісу выберыце Viewport або TV. Viewport захоўвае памеры і "
            L"частату абнаўлення манітора да 60 кадраў за секунду. TV прапануе 1920 × 1080, 1440 × 1080 або "
            L"1280 × 720 з суадносінамі 16:9 і частатой 50, 25, 59.94 (60000/1001) або 29.97 (30000/1001) "
            L"кадраў за секунду. Відэа TV прагрэсіўнае, BT.709, з абмежаваным дыяпазонам і субдыскрэтызацыяй "
            L"колеру 4:2:0. Прапорцыі захоўваюцца, палосы запаўнення чорныя. OK захоўвае выбар для "
            L"наступнага запісу; Скасаваць або Esc адхіляе непацверджаныя змены. Вокны запісу, даведкі і "
            L"звестак пра праграму не блакуюць іншыя вокны і могуць згортвацца. Tab і Shift+Tab перамяшчаюць "
            L"фокус, Enter націскае актыўную кнопку, Esc закрывае актыўнае дапаможнае акно.\r\n\r\nСІСТЭМНЫЯ "
            L"ПАТРАБАВАННІ\r\nWindows 7–11 падтрымлівае ўсе функцыі. Для Windows Vista SP2 неабходна "
            L"ўсталяваць абнаўленні KB971512 і KB2117917; запіс MP4 у Vista не працуе. Патрэбна падтрымка "
            L"Direct3D 11, а для MP4 таксама Media Foundation і кадавальнік H.264. Інтэрфейс і дакументацыя "
            L"даступны на 36 мовах."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"АНІМАЦЫЯ І НАЛАДЫ\r\nАпаратна паскораны палёт паміж зменлівымі паверхнямі. Палёт паміж чатырма "
            L"зменлівымі паверхнямі; Палёт праз зменлівую варонку. Для кожнага манітора выберыце роўна адну "
            L"анімацыю. Тэкстура пераключае тэкстураваную паверхню і каркасную мадэль. Свабоднае кручэнне "
            L"камеры павольна змяняе напрамак погляду ва ўсіх трох вымярэннях. Паўзы і развароты дадаюць "
            L"выпадковыя запаволенні, паўзы і змены напрамку кручэння; палёт наперад працягваецца. Хуткасць "
            L"— 0–1600%. Кожны манітор мае незалежную выпадковую сцэну з вывадам паводле ўласнай частаты "
            L"абнаўлення. Асноўнае, запаўняльнае, фонавае і контурнае святло можна пераключаць незалежна для "
            L"выбраных манітораў. Асвятленне дзейнічае толькі на тэкстураваных паверхнях.\r\n\r\nМАНІТОРЫ\r\n"
            L"Выберыце адзін або некалькі радкоў у спісе манітораў. Ctrl+A выбірае ўсе; Ctrl і Shift "
            L"змяняюць выбар. Элементы кіравання і паўзункі анімацыі змяняюць толькі налады выбраных "
            L"манітораў. Выбар радка і ўключэнне вываду яго сцяжком — розныя дзеянні. Выбар асобна "
            L"захоўваецца для праграмы і застаўкі. Калі раней былі выбраны ўсе маніторы, да выбару "
            L"далучаюцца і новыя маніторы. Розныя значэнні на выбраных маніторах пазначаюцца нявызначаным "
            L"станам сцяжкоў і кропкавым узорам на пераключальніках, ручках паўзункоў і кнопках «Уключыць "
            L"усё» і «Выключыць усё». У подпісах паўзункоў замест агульнага значэння паказваецца працяжнік. "
            L"Змена параметра або націск на паўзунок ужывае гэта значэнне да ўсіх выбраных манітораў.\r\n\r\n"
            L"ПЕРАДПРАГЛЯД І КІРАВАННЕ\r\nВыкарыстоўвайце FlightCorridor.scr як застаўку Windows з асобнымі "
            L"наладамі. Поўнаэкранны перадпрагляд дазваляе змяняць іх падчас анімацыі. OK захоўвае змены, "
            L"Скасаваць або Esc адхіляе іх. Для выхаду з застаўкі націсніце клавішу або паварушыце мышшу.\r\n"
            L"\r\nСІСТЭМНЫЯ ПАТРАБАВАННІ\r\nWindows 7–11 падтрымлівае ўсе функцыі. Для Windows Vista SP2 "
            L"неабходна ўсталяваць абнаўленні KB971512 і KB2117917. Патрэбна падтрымка Direct3D 11."
        },
    }),
    DefineLanguage(LANG_BG, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Български" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — управление" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Настройки на FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Език:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Скорост на анимацията: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Полет на избраните монитори" },
        LocalizedText{ TXT_ENABLE_ALL, L"Включване на всички" },
        LocalizedText{ TXT_DISABLE_ALL, L"Изключване на всички" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Монитор за анимацията" },
        LocalizedText{ TXT_MONITOR, L"Монитор" },
        LocalizedText{ TXT_RESOLUTION, L"Разделителна способност" },
        LocalizedText{ TXT_POSITION, L"Позиция" },
        LocalizedText{ TXT_PRIMARY, L"основен" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Отказ" },
        LocalizedText{ TXT_START_RECORDING, L"Начало на запис…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Спиране на записа" },
        LocalizedText{ TXT_PAUSE, L"Пауза" },
        LocalizedText{ TXT_RESUME, L"Продължаване" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Инсталиране на скрийнсейвъра" },
        LocalizedText{ TXT_EXIT, L"Изход" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Анимацията се изпълнява…" },
        LocalizedText{ TXT_RECORDING, L"Извършва се MP4 запис…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Записът е запазен." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Неуспешно стартиране на MP4 запис." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Скрийнсейвърът не е инсталиран." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Скрийнсейвърът е инсталиран." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Неуспешно инициализиране на Direct3D визуализатора." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Полет между четири променящи се повърхнини" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Полет през променяща се фуния" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Затварянето на приложението ще спре текущия запис." },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Отвори уебсайта %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Сайтът не може да се отвори в браузъра по подразбиране." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL адресът не можа да се копира в клипборда." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Информацията не можа да се копира в клипборда." },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Включване на прегледа" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Изключване на прегледа" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Анимацията е на пауза." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Блокиране на скрийнсейвъра при анимация" },
        LocalizedText{ TXT_READY_STATUS, L"Готов." },
        LocalizedText{ TXT_HELP, L"Помощ" },
        LocalizedText{ TXT_ABOUT, L"За програмата" },
        LocalizedText{ TXT_CLOSE, L"Затвори" },
        LocalizedText{ TXT_SNAPSHOT, L"Запис на PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"PNG изображението е запазено." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"PNG изображението не може да се запази." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Деинсталиране на скрийнсейвъра" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Скрийнсейвърът е деинсталиран." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Скрийнсейвърът не може да се деинсталира. Затворете го и неговия преглед и опитайте отново."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Затворете настройките на FlightCorridor и опитайте деинсталирането отново."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Затворете настройките на скрийнсейвъра на Windows и опитайте деинсталирането отново."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Спрете скрийнсейвъра или прегледа на цял екран с Esc или движение на мишката и опитайте отново."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Хардуерно ускорен полет между променящи се повърхнини." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Версия:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Целева платформа:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Уебсайт:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Отвори в браузъра по подразбиране" },
        LocalizedText{ TXT_COPY_URL, L"Копирай &адреса" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Копирай &информацията" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Основна светлина" },
        LocalizedText{ TXT_FILL_LIGHT, L"Запълваща светлина" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Околна светлина" },
        LocalizedText{ TXT_RIM_LIGHT, L"Контурна светлина" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Текстура" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Свободно въртене на камерата" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Паузи и обръщания" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Ресурсът на лиценза не е наличен." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Модел на монитора" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Честота на опресняване" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Битова дълбочина" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Формат на цветовете" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Цветово пространство" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u бита/канал" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u бита/пиксел" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Настройки на записа" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Разделителна способност:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Кадрова честота:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Промените се прилагат към следващия MP4 запис." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"АНИМАЦИЯ И НАСТРОЙКИ\r\nХардуерно ускорен полет между променящи се повърхнини. Полет между "
            L"четири променящи се повърхнини; Полет през променяща се фуния. Изберете точно една анимация за "
            L"всеки монитор. Текстура превключва между текстурирана повърхнина и телен модел. Свободното "
            L"въртене на камерата бавно променя посоката на погледа в трите измерения. Опцията „Паузи и "
            L"обръщания“ добавя случайни забавяния, паузи и обръщания на въртенето; полетът напред "
            L"продължава. Скоростта е 0–1600%. Всеки монитор има независима случайна сцена, изобразявана с "
            L"неговата честота на опресняване. Основната, запълващата, околната и контурната светлина се "
            L"включват независимо за избраните монитори. Осветлението се прилага само към текстурираните "
            L"повърхности.\r\n\r\nМОНИТОРИ\r\nИзберете един или повече редове в списъка с монитори. Ctrl+A "
            L"избира всички; Ctrl и Shift променят избора. Контролите и плъзгачите на анимацията променят "
            L"само настройките на избраните монитори. Избирането на ред и включването на изхода чрез "
            L"отметката му са различни действия. Изборът се запомня отделно за приложението и скрийнсейвъра. "
            L"Ако са били избрани всички монитори, включват се и новосвързаните. Различните стойности на "
            L"избраните монитори се показват с неопределено състояние на отметките и точков шаблон върху "
            L"радиобутоните, дръжките на плъзгачите и бутоните „Включване на всички“ и „Изключване на "
            L"всички“. Надписите на плъзгачите показват тире вместо обща стойност. Промяна на опция или "
            L"щракване върху плъзгач прилага стойността към всички избрани монитори.\r\n\r\nУПРАВЛЕНИЕ\r\n"
            L"Стартирайте FlightCorridor.exe. Настройките се запазват непрекъснато и работи само един "
            L"екземпляр на приложението. Отметката на монитора или двойно щракване върху реда включва или "
            L"изключва анимационния изход. Анимацията може да се поставя на пауза и да продължава. PNG и MP4 "
            L"заснемат първия активен монитор за анимация, не общ образ от всички монитори. По време на "
            L"запис не може да се изключи анимационният изход на записвания монитор; затварянето на "
            L"приложението при запис изисква потвърждение. Паузата и блокирането на скрийнсейвъра важат за "
            L"цялото приложение независимо от избора на монитори. Когато блокирането е включено, "
            L"скрийнсейвърът на Windows се предотвратява само докато на поне един монитор има видима "
            L"анимация без пауза. Приложението може да инсталира и деинсталира вградения скрийнсейвър.\r\n\r"
            L"\nЕКРАННИ СНИМКИ И ЗАПИС\r\nВ настройките за запис изберете Viewport или TV. Viewport запазва "
            L"размерите и честотата на опресняване на монитора до 60 кадъра в секунда. TV предлага 1920 × "
            L"1080, 1440 × 1080 или 1280 × 720 със съотношение 16:9 и 50, 25, 59.94 (60000/1001) или 29.97 "
            L"(30000/1001) кадъра в секунда. TV използва прогресивно видео BT.709 с ограничен диапазон и "
            L"цветова субдискретизация 4:2:0. Пропорциите се запазват, допълващите ленти са черни. OK "
            L"запазва избора за следващия запис; Отказ или Esc отхвърля непотвърдените промени. Прозорците "
            L"за запис, помощ и информация не блокират другите прозорци и могат да се минимизират. Tab и "
            L"Shift+Tab преместват фокуса, Enter активира фокусирания бутон, Esc затваря активния помощен "
            L"прозорец.\r\n\r\nСИСТЕМНИ ИЗИСКВАНИЯ\r\nWindows 7–11 поддържа всички функции. За Windows Vista "
            L"SP2 трябва да се инсталират актуализациите KB971512 и KB2117917; записът на MP4 не работи във "
            L"Vista. Изисква се поддръжка на Direct3D 11, а за MP4 също Media Foundation и H.264 кодер. "
            L"Интерфейсът и документацията са налични на 36 езика."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"АНИМАЦИЯ И НАСТРОЙКИ\r\nХардуерно ускорен полет между променящи се повърхнини. Полет между "
            L"четири променящи се повърхнини; Полет през променяща се фуния. Изберете точно една анимация за "
            L"всеки монитор. Текстура превключва между текстурирана повърхнина и телен модел. Свободното "
            L"въртене на камерата бавно променя посоката на погледа в трите измерения. Опцията „Паузи и "
            L"обръщания“ добавя случайни забавяния, паузи и обръщания на въртенето; полетът напред "
            L"продължава. Скоростта е 0–1600%. Всеки монитор има независима случайна сцена, изобразявана с "
            L"неговата честота на опресняване. Основната, запълващата, околната и контурната светлина се "
            L"включват независимо за избраните монитори. Осветлението се прилага само към текстурираните "
            L"повърхности.\r\n\r\nМОНИТОРИ\r\nИзберете един или повече редове в списъка с монитори. Ctrl+A "
            L"избира всички; Ctrl и Shift променят избора. Контролите и плъзгачите на анимацията променят "
            L"само настройките на избраните монитори. Избирането на ред и включването на изхода чрез "
            L"отметката му са различни действия. Изборът се запомня отделно за приложението и скрийнсейвъра. "
            L"Ако са били избрани всички монитори, включват се и новосвързаните. Различните стойности на "
            L"избраните монитори се показват с неопределено състояние на отметките и точков шаблон върху "
            L"радиобутоните, дръжките на плъзгачите и бутоните „Включване на всички“ и „Изключване на "
            L"всички“. Надписите на плъзгачите показват тире вместо обща стойност. Промяна на опция или "
            L"щракване върху плъзгач прилага стойността към всички избрани монитори.\r\n\r\nПРЕГЛЕД И "
            L"УПРАВЛЕНИЕ\r\nИзползвайте FlightCorridor.scr като скрийнсейвър на Windows с отделни настройки. "
            L"Прегледът на цял екран позволява промени в реално време. OK запазва промените; Отказ или Esc "
            L"ги отхвърля. Излезте от скрийнсейвъра с клавиш или движение на мишката.\r\n\r\nСИСТЕМНИ "
            L"ИЗИСКВАНИЯ\r\nWindows 7–11 поддържа всички функции. За Windows Vista SP2 трябва да се "
            L"инсталират актуализациите KB971512 и KB2117917. Изисква се поддръжка на Direct3D 11."
        },
    }),
    DefineLanguage(LANG_MK, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Македонски" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — контроли" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Поставки за FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Јазик:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Брзина на анимацијата: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Лет на избраните монитори" },
        LocalizedText{ TXT_ENABLE_ALL, L"Вклучи ги сите" },
        LocalizedText{ TXT_DISABLE_ALL, L"Исклучи ги сите" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Монитор за анимација" },
        LocalizedText{ TXT_MONITOR, L"Монитор" },
        LocalizedText{ TXT_RESOLUTION, L"Резолуција" },
        LocalizedText{ TXT_POSITION, L"Положба" },
        LocalizedText{ TXT_PRIMARY, L"примарен" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Откажи" },
        LocalizedText{ TXT_START_RECORDING, L"Започни снимање…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Запри снимање" },
        LocalizedText{ TXT_PAUSE, L"Паузирај" },
        LocalizedText{ TXT_RESUME, L"Продолжи" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Инсталирај чувар на екранот" },
        LocalizedText{ TXT_EXIT, L"Излез" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Анимацијата се извршува…" },
        LocalizedText{ TXT_RECORDING, L"MP4 снимање е во тек…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Снимката е зачувана." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Не може да започне MP4 снимање." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Чуварот на екранот не е инсталиран." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Чуварот на екранот е инсталиран." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Не може да се иницијализира Direct3D прикажувачот." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Лет меѓу четири променливи површини" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Лет низ променлива инка" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Затворањето на апликацијата ќе го запре снимањето што е во тек."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Отвори ја веб-страницата %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Веб-страницата не може да се отвори во стандардниот прелистувач."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"URL-адресата не можеше да се копира во таблата со исечоци."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Информациите не можеа да се копираат во таблата со исечоци."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Вклучи преглед" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Исклучи преглед" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Анимацијата е паузирана." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Блокирај го чуварот за време на анимацијата" },
        LocalizedText{ TXT_READY_STATUS, L"Подготвен." },
        LocalizedText{ TXT_HELP, L"Помош" },
        LocalizedText{ TXT_ABOUT, L"За програмата" },
        LocalizedText{ TXT_CLOSE, L"Затвори" },
        LocalizedText{ TXT_SNAPSHOT, L"Зачувај PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"PNG сликата е зачувана." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"PNG сликата не може да се зачува." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Деинсталирај чувар на екранот" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Чуварот на екранот е деинсталиран." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Чуварот на екранот не може да се деинсталира. Затворете го него и неговиот преглед и обидете "
            L"се повторно."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Затворете ги поставките за FlightCorridor и обидете се повторно да деинсталирате."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Затворете ги поставките за чуварот на екранот на Windows и обидете се повторно."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Затворете го чуварот или прегледот на цел екран со Esc или со движење на глувчето и обидете се "
            L"повторно."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Хардверски забрзан лет меѓу променливи површини." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Верзија:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Целна платформа:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Веб-страница:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Отвори во стандардниот прелистувач" },
        LocalizedText{ TXT_COPY_URL, L"Копирај ја &адресата" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Копирај ги &информациите" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Главно светло" },
        LocalizedText{ TXT_FILL_LIGHT, L"Дополнително светло" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Амбиентално светло" },
        LocalizedText{ TXT_RIM_LIGHT, L"Контурно светло" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Текстура" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Слободно вртење на камерата" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Паузи и пресврти" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Ресурсот за лиценцата не е достапен." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Модел на мониторот" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Стапка на освежување" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Битна длабочина" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Формат на боја" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Простор на бои" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u бита/канал" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u бита/пиксел" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Поставки за снимање" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Резолуција:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Број кадри во секунда:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Промените важат за следното MP4 снимање." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"АНИМАЦИЈА И ПОСТАВКИ\r\nХардверски забрзан лет меѓу променливи површини. Лет меѓу четири "
            L"променливи површини; Лет низ променлива инка. За секој монитор изберете точно една анимација. "
            L"Текстура менува текстурирана површина и жичен модел. Слободното вртење на камерата полека го "
            L"менува погледот во сите три димензии. Опцијата „Паузи и пресврти“ додава случајни забавувања, "
            L"паузи и промени на насоката на вртење; летот напред продолжува. Брзината е 0–1600%. Секој "
            L"монитор има независна случајна сцена што се прикажува со неговата стапка на освежување. "
            L"Главното, дополнителното, амбиенталното и контурното светло може да се вклучуваат одделно за "
            L"избраните монитори. Осветлувањето важи само за текстурираните површини.\r\n\r\nМОНИТОРИ\r\n"
            L"Изберете еден или повеќе редови во списокот на монитори. Ctrl+A ги избира сите; Ctrl и Shift "
            L"го менуваат изборот. Контролите и лизгачите на анимацијата ги менуваат само поставките на "
            L"избраните монитори. Избирањето ред и вклучувањето на излезот преку неговото поле се различни "
            L"дејства. Изборот се памети одделно за апликацијата и чуварот. Ако биле избрани сите монитори, "
            L"се вклучуваат и новоповрзаните монитори. Различните вредности на избраните монитори се "
            L"прикажуваат со неопределена состојба на полињата за избор и точкест образец на "
            L"радио-копчињата, рачките на лизгачите и копчињата „Вклучи ги сите“ и „Исклучи ги сите“. "
            L"Ознаките на лизгачите прикажуваат црта наместо заедничка вредност. Менувањето опција или "
            L"кликнувањето на лизгач ја применува вредноста на сите избрани монитори.\r\n\r\nУПРАВУВАЊЕ\r\n"
            L"Стартувајте FlightCorridor.exe. Поставките се зачувуваат постојано и работи само еден примерок "
            L"на апликацијата. Полето на мониторот или двоен клик на редот го вклучува или исклучува "
            L"анимацискиот излез. Анимацијата може да се паузира и продолжи. PNG и MP4 го снимаат првиот "
            L"активен монитор за анимација, не заедничка слика од сите монитори. Анимацискиот излез на "
            L"мониторот што се снима не може да се исклучи за време на снимањето; затворањето на "
            L"апликацијата при снимање бара потврда. Паузата и блокирањето на чуварот важат за целата "
            L"апликација без оглед на изборот на монитори. Кога блокирањето е вклучено, чуварот на Windows "
            L"се спречува само додека на барем еден монитор е видлива непаузирана анимација. Апликацијата "
            L"може да го инсталира и деинсталира вградениот чувар.\r\n\r\nСНИМКИ ОД ЕКРАН И СНИМАЊЕ\r\nВо "
            L"поставките за снимање изберете Viewport или TV. Viewport ги зачувува димензиите и стапката на "
            L"освежување на мониторот до 60 кадри во секунда. TV нуди 1920 × 1080, 1440 × 1080 или 1280 × "
            L"720 со однос 16:9 и 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) кадри во секунда. TV "
            L"видеото е прогресивно BT.709 со ограничен опсег и подсемплирање на боја 4:2:0. Пропорциите се "
            L"задржуваат, дополнителните ленти се црни. OK ги зачувува опциите за следното снимање; Откажи "
            L"или Esc ги отфрла непотврдените измени. Прозорците за снимање, помош и информации не ги "
            L"блокираат другите прозорци и може да се минимизираат. Tab и Shift+Tab го поместуваат фокусот, "
            L"Enter го активира фокусираното копче, Esc го затвора активниот помошен прозорец.\r\n\r\n"
            L"СИСТЕМСКИ БАРАЊА\r\nWindows 7–11 ги поддржува сите функции. За Windows Vista SP2 мора да се "
            L"инсталираат ажурирањата KB971512 и KB2117917; MP4 снимањето на Vista не работи. Потребна е "
            L"поддршка за Direct3D 11, а за MP4 и Media Foundation и H.264 кодер. Интерфејсот и "
            L"документацијата се достапни на 36 јазици."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"АНИМАЦИЈА И ПОСТАВКИ\r\nХардверски забрзан лет меѓу променливи површини. Лет меѓу четири "
            L"променливи површини; Лет низ променлива инка. За секој монитор изберете точно една анимација. "
            L"Текстура менува текстурирана површина и жичен модел. Слободното вртење на камерата полека го "
            L"менува погледот во сите три димензии. Опцијата „Паузи и пресврти“ додава случајни забавувања, "
            L"паузи и промени на насоката на вртење; летот напред продолжува. Брзината е 0–1600%. Секој "
            L"монитор има независна случајна сцена што се прикажува со неговата стапка на освежување. "
            L"Главното, дополнителното, амбиенталното и контурното светло може да се вклучуваат одделно за "
            L"избраните монитори. Осветлувањето важи само за текстурираните површини.\r\n\r\nМОНИТОРИ\r\n"
            L"Изберете еден или повеќе редови во списокот на монитори. Ctrl+A ги избира сите; Ctrl и Shift "
            L"го менуваат изборот. Контролите и лизгачите на анимацијата ги менуваат само поставките на "
            L"избраните монитори. Избирањето ред и вклучувањето на излезот преку неговото поле се различни "
            L"дејства. Изборот се памети одделно за апликацијата и чуварот. Ако биле избрани сите монитори, "
            L"се вклучуваат и новоповрзаните монитори. Различните вредности на избраните монитори се "
            L"прикажуваат со неопределена состојба на полињата за избор и точкест образец на "
            L"радио-копчињата, рачките на лизгачите и копчињата „Вклучи ги сите“ и „Исклучи ги сите“. "
            L"Ознаките на лизгачите прикажуваат црта наместо заедничка вредност. Менувањето опција или "
            L"кликнувањето на лизгач ја применува вредноста на сите избрани монитори.\r\n\r\nПРЕГЛЕД И "
            L"УПРАВУВАЊЕ\r\nКористете FlightCorridor.scr како Windows чувар на екранот со одделни поставки. "
            L"Прегледот на цел екран овозможува измени во живо. OK ги зачувува, а Откажи или Esc ги отфрла "
            L"измените. Излезете од чуварот со копче или движење на глувчето.\r\n\r\nСИСТЕМСКИ БАРАЊА\r\n"
            L"Windows 7–11 ги поддржува сите функции. За Windows Vista SP2 мора да се инсталираат "
            L"ажурирањата KB971512 и KB2117917. Потребна е поддршка за Direct3D 11."
        },
    }),
    DefineLanguage(LANG_SR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Српски" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — контроле" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Подешавања програма FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Језик:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Брзина анимације: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Лет на изабраним мониторима" },
        LocalizedText{ TXT_ENABLE_ALL, L"Укључи све" },
        LocalizedText{ TXT_DISABLE_ALL, L"Искључи све" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Монитор анимације" },
        LocalizedText{ TXT_MONITOR, L"Монитор" },
        LocalizedText{ TXT_RESOLUTION, L"Резолуција" },
        LocalizedText{ TXT_POSITION, L"Положај" },
        LocalizedText{ TXT_PRIMARY, L"примарни" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Откажи" },
        LocalizedText{ TXT_START_RECORDING, L"Покрени снимање…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Заустави снимање" },
        LocalizedText{ TXT_PAUSE, L"Паузирај" },
        LocalizedText{ TXT_RESUME, L"Настави" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Инсталирај чувар екрана" },
        LocalizedText{ TXT_EXIT, L"Излаз" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Анимација је покренута…" },
        LocalizedText{ TXT_RECORDING, L"MP4 снимање је у току…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Снимак је сачуван." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Није могуће покренути MP4 снимање." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Чувар екрана није инсталиран." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Чувар екрана је инсталиран." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Није могуће иницијализовати Direct3D приказивач." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Лет између четири променљиве површи" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Лет кроз променљиви левак" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Затварање апликације зауставиће снимање које је у току."
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Отвори веб-сајт %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Није могуће отворити страницу у подразумеваном прегледачу."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Није могуће копирати URL у оставу." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Није могуће копирати податке у оставу." },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Укључи преглед" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Искључи преглед" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Анимација је паузирана." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Спречи чувар екрана током анимације" },
        LocalizedText{ TXT_READY_STATUS, L"Спреман." },
        LocalizedText{ TXT_HELP, L"Помоћ" },
        LocalizedText{ TXT_ABOUT, L"О програму" },
        LocalizedText{ TXT_CLOSE, L"Затвори" },
        LocalizedText{ TXT_SNAPSHOT, L"Сачувај PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"PNG слика је сачувана." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Није могуће сачувати PNG слику." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Деинсталирај чувар екрана" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Чувар екрана је деинсталиран." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Није могуће деинсталирати чувар екрана. Затворите чувар и његов преглед па покушајте поново."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Затворите подешавања програма FlightCorridor па поновите деинсталацију."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Затворите Windows подешавања чувара екрана па поновите деинсталацију."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Затворите чувар или преглед преко целог екрана тастером Esc или померањем миша па поновите "
            L"деинсталацију."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Хардверски убрзан лет између променљивих површи." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Верзија:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Циљна платформа:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Веб-сајт:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Отвори у подразумеваном прегледачу" },
        LocalizedText{ TXT_COPY_URL, L"Копирај &адресу" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Копирај &податке" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Главно светло" },
        LocalizedText{ TXT_FILL_LIGHT, L"Допунско светло" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Амбијентално светло" },
        LocalizedText{ TXT_RIM_LIGHT, L"Контурно светло" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Текстура" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Слободно окретање камере" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Паузе и обрти" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Ресурс лиценце није доступан." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Модел монитора" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Учестаност освежавања" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Дубина бита" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Формат боје" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Простор боја" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u бита/канал" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u бита/пиксел" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Подешавања снимања" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Резолуција:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Број кадрова у секунди:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Промене се примењују на следеће MP4 снимање." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"АНИМАЦИЈА И ПОДЕШАВАЊА\r\nХардверски убрзан лет између променљивих површи. Лет између четири "
            L"променљиве површи; Лет кроз променљиви левак. За сваки монитор изаберите тачно једну "
            L"анимацију. Текстура мења приказ између текстурисане површи и жичаног модела. Слободно окретање "
            L"камере полако мења смер погледа у све три димензије. Паузе и обрти додају насумично "
            L"успоравање, паузе и промене смера ротације; лет напред се наставља. Брзина је 0–1600%. Сваки "
            L"монитор има независну насумичну сцену која се приказује према његовој учестаности освежавања. "
            L"Главно, допунско, амбијентално и контурно светло могу се засебно укључивати за изабране "
            L"мониторе. Осветљење важи само за текстуриране површине.\r\n\r\nМОНИТОРИ\r\nИзаберите један или "
            L"више редова у листи монитора. Ctrl+A бира све; Ctrl и Shift мењају избор. Контроле и клизачи "
            L"анимације мењају само подешавања изабраних монитора. Избор реда није исто што и укључивање "
            L"излаза његовим пољем за потврду. Избор се памти одвојено за апликацију и чувар екрана. Ако су "
            L"претходно били изабрани сви монитори, укључују се и новоприкључени монитори. Различите "
            L"вредности на изабраним мониторима приказују се неодређеним стањем поља за потврду и тачкастим "
            L"узорком на дугмадима избора, ручкама клизача и дугмадима „Укључи све“ и „Искључи све“. Ознаке "
            L"клизача приказују црту уместо заједничке вредности. Промена опције или клик на клизач "
            L"примењује ту вредност на све изабране мониторе.\r\n\r\nУПРАВЉАЊЕ\r\nПокрените "
            L"FlightCorridor.exe. Подешавања се стално чувају и ради само једна инстанца апликације. Поље "
            L"монитора или двоструки клик на ред укључује или искључује анимацијски излаз. Анимацију можете "
            L"паузирати и наставити. PNG и MP4 бележе први активни монитор анимације, не заједничку слику "
            L"свих монитора. Анимацијски излаз сниманог монитора не можете искључити током снимања; "
            L"затварање апликације током снимања захтева потврду. Пауза и блокада чувара екрана важе за целу "
            L"апликацију, без обзира на избор монитора. Када је блокада укључена, чувар екрана система "
            L"Windows спречава се само док је на бар једном монитору видљива анимација која није паузирана. "
            L"Апликација може инсталирати и деинсталирати уграђени чувар екрана.\r\n\r\nСНИМЦИ ЕКРАНА И "
            L"СНИМАЊЕ\r\nУ подешавањима снимања изаберите Viewport или TV. Viewport задржава димензије и "
            L"учестаност освежавања монитора до 60 кадрова у секунди. TV нуди 1920 × 1080, 1440 × 1080 или "
            L"1280 × 720 у односу 16:9, са 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) кадрова у "
            L"секунди. TV видео је прогресивни BT.709 ограниченог опсега с подузорковањем боје 4:2:0. Однос "
            L"слике остаје сачуван, а допунске траке су црне. OK чува опције за следећи снимак; Откажи или "
            L"Esc одбацује непотврђене измене. Прозори снимања, помоћи и информација не блокирају остале "
            L"прозоре и могу се минимизовати. Tab и Shift+Tab померају фокус, Enter активира фокусирано "
            L"дугме, а Esc затвара активни помоћни прозор.\r\n\r\nСИСТЕМСКИ ЗАХТЕВИ\r\nWindows 7–11 подржава "
            L"све функције. За Windows Vista SP2 морате инсталирати ажурирања KB971512 и KB2117917; MP4 "
            L"снимање на Висти не ради. Потребан је Direct3D 11, а за MP4 и Media Foundation и H.264 кодер. "
            L"Интерфејс и документација доступни су на 36 језика."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"АНИМАЦИЈА И ПОДЕШАВАЊА\r\nХардверски убрзан лет између променљивих површи. Лет између четири "
            L"променљиве површи; Лет кроз променљиви левак. За сваки монитор изаберите тачно једну "
            L"анимацију. Текстура мења приказ између текстурисане површи и жичаног модела. Слободно окретање "
            L"камере полако мења смер погледа у све три димензије. Паузе и обрти додају насумично "
            L"успоравање, паузе и промене смера ротације; лет напред се наставља. Брзина је 0–1600%. Сваки "
            L"монитор има независну насумичну сцену која се приказује према његовој учестаности освежавања. "
            L"Главно, допунско, амбијентално и контурно светло могу се засебно укључивати за изабране "
            L"мониторе. Осветљење важи само за текстуриране површине.\r\n\r\nМОНИТОРИ\r\nИзаберите један или "
            L"више редова у листи монитора. Ctrl+A бира све; Ctrl и Shift мењају избор. Контроле и клизачи "
            L"анимације мењају само подешавања изабраних монитора. Избор реда није исто што и укључивање "
            L"излаза његовим пољем за потврду. Избор се памти одвојено за апликацију и чувар екрана. Ако су "
            L"претходно били изабрани сви монитори, укључују се и новоприкључени монитори. Различите "
            L"вредности на изабраним мониторима приказују се неодређеним стањем поља за потврду и тачкастим "
            L"узорком на дугмадима избора, ручкама клизача и дугмадима „Укључи све“ и „Искључи све“. Ознаке "
            L"клизача приказују црту уместо заједничке вредности. Промена опције или клик на клизач "
            L"примењује ту вредност на све изабране мониторе.\r\n\r\nПРЕГЛЕД И УПРАВЉАЊЕ\r\nКористите "
            L"FlightCorridor.scr као Windows чувар екрана са одвојеним подешавањима. Преглед преко целог "
            L"екрана омогућава измене уживо. OK чува, а Откажи или Esc одбацује измене. Из чувара изађите "
            L"притиском тастера или померањем миша.\r\n\r\nСИСТЕМСКИ ЗАХТЕВИ\r\nWindows 7–11 подржава све "
            L"функције. За Windows Vista SP2 морате инсталирати ажурирања KB971512 и KB2117917. Потребан је "
            L"Direct3D 11."
        },
    }),
    DefineLanguage(LANG_UK, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Українська" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — керування" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Налаштування FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Мова:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Швидкість анімації: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Політ на вибраних моніторах" },
        LocalizedText{ TXT_ENABLE_ALL, L"Увімкнути все" },
        LocalizedText{ TXT_DISABLE_ALL, L"Вимкнути все" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Монітор анімації" },
        LocalizedText{ TXT_MONITOR, L"Монітор" },
        LocalizedText{ TXT_RESOLUTION, L"Роздільна здатність" },
        LocalizedText{ TXT_POSITION, L"Розташування" },
        LocalizedText{ TXT_PRIMARY, L"основний" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Скасувати" },
        LocalizedText{ TXT_START_RECORDING, L"Почати запис…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Зупинити запис" },
        LocalizedText{ TXT_PAUSE, L"Призупинити" },
        LocalizedText{ TXT_RESUME, L"Продовжити" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Установити заставку" },
        LocalizedText{ TXT_EXIT, L"Вийти" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Анімація працює…" },
        LocalizedText{ TXT_RECORDING, L"Триває запис MP4…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Запис збережено." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Не вдалося почати запис MP4." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Заставку не встановлено." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Заставку встановлено." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Не вдалося ініціалізувати візуалізатор Direct3D." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Політ між чотирма мінливими поверхнями" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Політ крізь мінливу лійку" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Закриття програми зупинить поточний запис." },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Відкрити вебсайт %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Не вдається відкрити сайт у типовому браузері." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Не вдалося скопіювати URL у буфер обміну." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Не вдалося скопіювати відомості в буфер обміну."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Увімкнути попередній перегляд" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Вимкнути попередній перегляд" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Анімацію призупинено." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Блокувати заставку під час анімації" },
        LocalizedText{ TXT_READY_STATUS, L"Готовий." },
        LocalizedText{ TXT_HELP, L"Довідка" },
        LocalizedText{ TXT_ABOUT, L"Про програму" },
        LocalizedText{ TXT_CLOSE, L"Закрити" },
        LocalizedText{ TXT_SNAPSHOT, L"Зберегти PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Зображення PNG збережено." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Не вдалося зберегти зображення PNG." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Видалити заставку" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Заставку видалено." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Не вдалося видалити заставку. Закрийте заставку та її попередній перегляд і спробуйте ще раз."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Закрийте налаштування FlightCorridor та повторіть видалення."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Закрийте налаштування заставки Windows та повторіть видалення."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Завершіть заставку або повноекранний попередній перегляд клавішею Esc чи рухом миші та "
            L"повторіть видалення."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Апаратно прискорений політ між мінливими поверхнями." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Версія:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Цільова платформа:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Вебсайт:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Відкрити в типовому браузері" },
        LocalizedText{ TXT_COPY_URL, L"Копіювати &адресу" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Копіювати &відомості" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Основне світло" },
        LocalizedText{ TXT_FILL_LIGHT, L"Заповнювальне світло" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Фонове світло" },
        LocalizedText{ TXT_RIM_LIGHT, L"Контурне світло" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Текстура" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Вільне обертання камери" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Паузи та зміни напрямку" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Ресурс ліцензії недоступний." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Модель монітора" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Частота оновлення" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Бітова глибина" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Формат кольору" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Колірний простір" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u біт/канал" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u біт/піксель" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Налаштування запису" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Роздільна здатність:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Частота кадрів:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Зміни буде застосовано до наступного запису MP4." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"АНІМАЦІЯ ТА НАЛАШТУВАННЯ\r\nАпаратно прискорений політ між мінливими поверхнями. Політ між "
            L"чотирма мінливими поверхнями; Політ крізь мінливу лійку. Для кожного монітора виберіть рівно "
            L"одну анімацію. Текстура перемикає текстуровану поверхню та каркасну модель. Вільне обертання "
            L"камери повільно змінює напрямок погляду в усіх трьох вимірах. Паузи та зміни напрямку додають "
            L"випадкові уповільнення, паузи та зміни напрямку обертання; політ уперед триває. Швидкість — "
            L"0–1600%. Кожен монітор має незалежну випадкову сцену з виведенням відповідно до власної "
            L"частоти оновлення. Основне, заповнювальне, фонове та контурне світло можна незалежно "
            L"перемикати для вибраних моніторів. Освітлення діє лише на текстурованих поверхнях.\r\n\r\n"
            L"МОНІТОРИ\r\nВиберіть один або кілька рядків у списку моніторів. Ctrl+A вибирає всі; Ctrl і "
            L"Shift змінюють вибір. Елементи керування й повзунки анімації змінюють лише налаштування "
            L"вибраних моніторів. Вибір рядка та ввімкнення виведення його прапорцем — різні дії. Вибір "
            L"зберігається окремо для програми й заставки. Якщо раніше були вибрані всі монітори, до вибору "
            L"долучаються й новопідключені. Різні значення на вибраних моніторах позначаються невизначеним "
            L"станом прапорців і крапковим візерунком на перемикачах, ручках повзунків і кнопках «Увімкнути "
            L"все» і «Вимкнути все». Підписи повзунків показують тире замість спільного значення. Зміна "
            L"параметра або натискання на повзунок застосовує це значення до всіх вибраних моніторів.\r\n\r\n"
            L"КЕРУВАННЯ\r\nЗапустіть FlightCorridor.exe. Налаштування зберігаються постійно, працює лише "
            L"один екземпляр програми. Прапорець монітора або подвійне клацання рядка вмикає чи вимикає "
            L"виведення анімації. Анімацію можна призупинити та продовжити. PNG і MP4 захоплюють перший "
            L"активний монітор анімації, а не спільне зображення всіх моніторів. Під час запису не можна "
            L"вимкнути виведення анімації монітора, який записується; закриття програми під час запису "
            L"потребує підтвердження. Призупинення та блокування заставки діють для всієї програми незалежно "
            L"від вибору моніторів. Якщо блокування ввімкнено, заставка Windows не запускається лише доки "
            L"принаймні на одному моніторі видима непризупинена анімація. Програма може встановити або "
            L"видалити вбудовану заставку.\r\n\r\nЗНІМКИ ЕКРАНА ТА ЗАПИС\r\nУ налаштуваннях запису виберіть "
            L"Viewport або TV. Viewport зберігає розміри та частоту оновлення монітора до 60 кадрів за "
            L"секунду. TV пропонує 1920 × 1080, 1440 × 1080 або 1280 × 720 зі співвідношенням 16:9 і "
            L"частотою 50, 25, 59.94 (60000/1001) або 29.97 (30000/1001) кадрів за секунду. Відео TV "
            L"прогресивне, BT.709, з обмеженим діапазоном і субдискретизацією кольору 4:2:0. Пропорції "
            L"зберігаються, смуги заповнення чорні. OK зберігає вибір для наступного запису; Скасувати або "
            L"Esc відхиляє непідтверджені зміни. Вікна запису, довідки та відомостей не блокують інші вікна "
            L"й можуть згортатися. Tab і Shift+Tab переміщують фокус, Enter активує кнопку з фокусом, Esc "
            L"закриває активне допоміжне вікно.\r\n\r\nСИСТЕМНІ ВИМОГИ\r\nWindows 7–11 підтримує всі "
            L"функції. Для Windows Vista SP2 потрібно встановити оновлення KB971512 і KB2117917; запис MP4 у "
            L"Vista не працює. Потрібна підтримка Direct3D 11, а для MP4 також Media Foundation й "
            L"кодувальник H.264. Інтерфейс і документація доступні 36 мовами."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"АНІМАЦІЯ ТА НАЛАШТУВАННЯ\r\nАпаратно прискорений політ між мінливими поверхнями. Політ між "
            L"чотирма мінливими поверхнями; Політ крізь мінливу лійку. Для кожного монітора виберіть рівно "
            L"одну анімацію. Текстура перемикає текстуровану поверхню та каркасну модель. Вільне обертання "
            L"камери повільно змінює напрямок погляду в усіх трьох вимірах. Паузи та зміни напрямку додають "
            L"випадкові уповільнення, паузи та зміни напрямку обертання; політ уперед триває. Швидкість — "
            L"0–1600%. Кожен монітор має незалежну випадкову сцену з виведенням відповідно до власної "
            L"частоти оновлення. Основне, заповнювальне, фонове та контурне світло можна незалежно "
            L"перемикати для вибраних моніторів. Освітлення діє лише на текстурованих поверхнях.\r\n\r\n"
            L"МОНІТОРИ\r\nВиберіть один або кілька рядків у списку моніторів. Ctrl+A вибирає всі; Ctrl і "
            L"Shift змінюють вибір. Елементи керування й повзунки анімації змінюють лише налаштування "
            L"вибраних моніторів. Вибір рядка та ввімкнення виведення його прапорцем — різні дії. Вибір "
            L"зберігається окремо для програми й заставки. Якщо раніше були вибрані всі монітори, до вибору "
            L"долучаються й новопідключені. Різні значення на вибраних моніторах позначаються невизначеним "
            L"станом прапорців і крапковим візерунком на перемикачах, ручках повзунків і кнопках «Увімкнути "
            L"все» і «Вимкнути все». Підписи повзунків показують тире замість спільного значення. Зміна "
            L"параметра або натискання на повзунок застосовує це значення до всіх вибраних моніторів.\r\n\r\n"
            L"ПОПЕРЕДНІЙ ПЕРЕГЛЯД І КЕРУВАННЯ\r\nВикористовуйте FlightCorridor.scr як заставку Windows з "
            L"окремими налаштуваннями. Повноекранний попередній перегляд дозволяє змінювати їх під час "
            L"анімації. OK зберігає зміни, Скасувати або Esc відхиляє їх. Для виходу із заставки натисніть "
            L"клавішу або порухайте мишею.\r\n\r\nСИСТЕМНІ ВИМОГИ\r\nWindows 7–11 підтримує всі функції. Для "
            L"Windows Vista SP2 потрібно встановити оновлення KB971512 і KB2117917. Потрібна підтримка "
            L"Direct3D 11."
        },
    }),
    DefineLanguage(LANG_RU, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Русский" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlightCorridor — управление" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Настройки FlightCorridor" },
        LocalizedText{ TXT_LANGUAGE, L"Язык:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Скорость анимации: %d %%" },
        LocalizedText{ TXT_FLIGHT_EFFECTS, L"Полёт на выбранных мониторах" },
        LocalizedText{ TXT_ENABLE_ALL, L"Включить всё" },
        LocalizedText{ TXT_DISABLE_ALL, L"Выключить всё" },
        LocalizedText{ TXT_ANIMATION_MONITOR, L"Монитор анимации" },
        LocalizedText{ TXT_MONITOR, L"Монитор" },
        LocalizedText{ TXT_RESOLUTION, L"Разрешение" },
        LocalizedText{ TXT_POSITION, L"Расположение" },
        LocalizedText{ TXT_PRIMARY, L"основной" },
        LocalizedText{ TXT_OK, L"OK" },
        LocalizedText{ TXT_CANCEL, L"Отмена" },
        LocalizedText{ TXT_START_RECORDING, L"Начать запись…" },
        LocalizedText{ TXT_STOP_RECORDING, L"Остановить запись" },
        LocalizedText{ TXT_PAUSE, L"Приостановить" },
        LocalizedText{ TXT_RESUME, L"Продолжить" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Установить заставку" },
        LocalizedText{ TXT_EXIT, L"Выход" },
        LocalizedText{ TXT_ANIMATION_RUNNING, L"Анимация работает…" },
        LocalizedText{ TXT_RECORDING, L"Идёт запись MP4…" },
        LocalizedText{ TXT_RECORDING_SAVED, L"Запись сохранена." },
        LocalizedText{ TXT_RECORDING_FAILED, L"Не удалось начать запись MP4." },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Заставка не установлена." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Заставка установлена." },
        LocalizedText{ TXT_RENDERER_FAILED, L"Не удалось инициализировать визуализатор Direct3D." },
        LocalizedText{ TXT_EFFECT_CORRIDOR, L"Полёт между четырьмя меняющимися поверхностями" },
        LocalizedText{ TXT_EFFECT_FUNNEL, L"Полёт сквозь меняющуюся воронку" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Закрытие приложения остановит текущую запись." },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Открыть веб-сайт %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Не удаётся открыть сайт в браузере по умолчанию." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Не удалось скопировать URL в буфер обмена." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Не удалось скопировать сведения в буфер обмена."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Включить предпросмотр" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Выключить предпросмотр" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Анимация приостановлена." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Блокировать заставку во время анимации" },
        LocalizedText{ TXT_READY_STATUS, L"Готов." },
        LocalizedText{ TXT_HELP, L"Справка" },
        LocalizedText{ TXT_ABOUT, L"О программе" },
        LocalizedText{ TXT_CLOSE, L"Закрыть" },
        LocalizedText{ TXT_SNAPSHOT, L"Сохранить PNG…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Изображение PNG сохранено." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Не удалось сохранить изображение PNG." },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Удалить заставку" },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Заставка удалена." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Не удалось удалить заставку. Закройте заставку и её предпросмотр и повторите попытку."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Закройте настройки FlightCorridor и повторите удаление."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Закройте настройки заставки Windows и повторите удаление."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Завершите заставку или полноэкранный предпросмотр клавишей Esc либо движением мыши и повторите "
            L"удаление."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Аппаратно ускоренный полёт между меняющимися поверхностями."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Версия:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Целевая платформа:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Веб-сайт:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Открыть в браузере по умолчанию" },
        LocalizedText{ TXT_COPY_URL, L"Копировать &адрес" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Копировать &сведения" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Основной свет" },
        LocalizedText{ TXT_FILL_LIGHT, L"Заполняющий свет" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Фоновый свет" },
        LocalizedText{ TXT_RIM_LIGHT, L"Контурный свет" },
        LocalizedText{ TXT_FILLED_SURFACE, L"Текстура" },
        LocalizedText{ TXT_CAMERA_TUMBLING, L"Свободное вращение камеры" },
        LocalizedText{ TXT_CAMERA_REVERSALS, L"Паузы и смены направления" },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE, L"Ресурс лицензии недоступен." },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL, L"Модель монитора" },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE, L"Частота обновления" },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH, L"Глубина цвета" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT, L"Формат цвета" },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE, L"Цветовое пространство" },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT, L"%u бит/канал" },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT, L"%u бит/пиксель" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE, L"Настройки записи" },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT, L"Viewport" },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION, L"TV (BT.709, 4:2:0)" },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION, L"Разрешение:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE, L"Частота кадров:" },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE, L"Изменения применяются к следующей записи MP4." },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"АНИМАЦИЯ И НАСТРОЙКИ\r\nАппаратно ускоренный полёт между меняющимися поверхностями. Полёт "
            L"между четырьмя меняющимися поверхностями; Полёт сквозь меняющуюся воронку. Для каждого "
            L"монитора выберите ровно одну анимацию. Текстура переключает текстурированную поверхность и "
            L"каркасную модель. Свободное вращение камеры медленно меняет направление взгляда во всех трёх "
            L"измерениях. Паузы и смены направления добавляют случайные замедления, паузы и изменения "
            L"направления вращения; полёт вперёд продолжается. Скорость — 0–1600%. Каждый монитор имеет "
            L"независимую случайную сцену с выводом согласно собственной частоте обновления. Основной, "
            L"заполняющий, фоновый и контурный свет можно независимо переключать для выбранных мониторов. "
            L"Освещение применяется только к текстурированным поверхностям.\r\n\r\nМОНИТОРЫ\r\nВыберите одну "
            L"или несколько строк в списке мониторов. Ctrl+A выбирает все; Ctrl и Shift изменяют выбор. "
            L"Элементы управления и ползунки анимации изменяют только настройки выбранных мониторов. Выбор "
            L"строки и включение вывода её флажком — разные действия. Выбор сохраняется отдельно для "
            L"приложения и заставки. Если раньше были выбраны все мониторы, в выбор включаются и вновь "
            L"подключённые. Разные значения на выбранных мониторах обозначаются неопределённым состоянием "
            L"флажков и точечным узором на переключателях, ручках ползунков и кнопках «Включить всё» и "
            L"«Выключить всё». Подписи ползунков показывают тире вместо общего значения. Изменение параметра "
            L"или нажатие на ползунок применяет это значение ко всем выбранным мониторам.\r\n\r\nУПРАВЛЕНИЕ\r"
            L"\nЗапустите FlightCorridor.exe. Настройки сохраняются постоянно, работает только один "
            L"экземпляр приложения. Флажок монитора или двойной щелчок по строке включает либо выключает "
            L"вывод анимации. Анимацию можно приостановить и продолжить. PNG и MP4 захватывают первый "
            L"активный монитор анимации, а не общее изображение всех мониторов. Во время записи нельзя "
            L"отключить вывод анимации записываемого монитора; закрытие приложения во время записи требует "
            L"подтверждения. Пауза и блокировка заставки действуют для всего приложения независимо от выбора "
            L"мониторов. Если блокировка включена, заставка Windows не запускается только пока хотя бы на "
            L"одном мониторе видима неприостановленная анимация. Приложение может установить или удалить "
            L"встроенную заставку.\r\n\r\nСНИМКИ ЭКРАНА И ЗАПИСЬ\r\nВ настройках записи выберите Viewport "
            L"или TV. Viewport сохраняет размеры и частоту обновления монитора до 60 кадров в секунду. TV "
            L"предлагает 1920 × 1080, 1440 × 1080 или 1280 × 720 с соотношением 16:9 и частотой 50, 25, "
            L"59.94 (60000/1001) или 29.97 (30000/1001) кадров в секунду. Видео TV прогрессивное, BT.709, с "
            L"ограниченным диапазоном и субдискретизацией цвета 4:2:0. Пропорции сохраняются, полосы "
            L"заполнения чёрные. OK сохраняет выбор для следующей записи; Отмена или Esc отклоняет "
            L"неподтверждённые изменения. Окна записи, справки и сведений не блокируют другие окна и могут "
            L"сворачиваться. Tab и Shift+Tab перемещают фокус, Enter активирует кнопку с фокусом, Esc "
            L"закрывает активное вспомогательное окно.\r\n\r\nСИСТЕМНЫЕ ТРЕБОВАНИЯ\r\nWindows 7–11 "
            L"поддерживает все функции. Для Windows Vista SP2 необходимо установить обновления KB971512 и "
            L"KB2117917; запись MP4 в Vista не работает. Нужна поддержка Direct3D 11, а для MP4 также Media "
            L"Foundation и кодировщик H.264. Интерфейс и документация доступны на 36 языках."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"АНИМАЦИЯ И НАСТРОЙКИ\r\nАппаратно ускоренный полёт между меняющимися поверхностями. Полёт "
            L"между четырьмя меняющимися поверхностями; Полёт сквозь меняющуюся воронку. Для каждого "
            L"монитора выберите ровно одну анимацию. Текстура переключает текстурированную поверхность и "
            L"каркасную модель. Свободное вращение камеры медленно меняет направление взгляда во всех трёх "
            L"измерениях. Паузы и смены направления добавляют случайные замедления, паузы и изменения "
            L"направления вращения; полёт вперёд продолжается. Скорость — 0–1600%. Каждый монитор имеет "
            L"независимую случайную сцену с выводом согласно собственной частоте обновления. Основной, "
            L"заполняющий, фоновый и контурный свет можно независимо переключать для выбранных мониторов. "
            L"Освещение применяется только к текстурированным поверхностям.\r\n\r\nМОНИТОРЫ\r\nВыберите одну "
            L"или несколько строк в списке мониторов. Ctrl+A выбирает все; Ctrl и Shift изменяют выбор. "
            L"Элементы управления и ползунки анимации изменяют только настройки выбранных мониторов. Выбор "
            L"строки и включение вывода её флажком — разные действия. Выбор сохраняется отдельно для "
            L"приложения и заставки. Если раньше были выбраны все мониторы, в выбор включаются и вновь "
            L"подключённые. Разные значения на выбранных мониторах обозначаются неопределённым состоянием "
            L"флажков и точечным узором на переключателях, ручках ползунков и кнопках «Включить всё» и "
            L"«Выключить всё». Подписи ползунков показывают тире вместо общего значения. Изменение параметра "
            L"или нажатие на ползунок применяет это значение ко всем выбранным мониторам.\r\n\r\n"
            L"ПРЕДПРОСМОТР И УПРАВЛЕНИЕ\r\nИспользуйте FlightCorridor.scr как заставку Windows с отдельными "
            L"настройками. Полноэкранный предпросмотр позволяет изменять их во время анимации. OK сохраняет "
            L"изменения, Отмена или Esc отклоняет их. Для выхода из заставки нажмите клавишу или подвигайте "
            L"мышью.\r\n\r\nСИСТЕМНЫЕ ТРЕБОВАНИЯ\r\nWindows 7–11 поддерживает все функции. Для Windows Vista "
            L"SP2 необходимо установить обновления KB971512 и KB2117917. Нужна поддержка Direct3D 11."
        },
    }),
});

constexpr std::array<const wchar_t*, 3> RECORDING_RESOLUTION_TEXTS = {
    L"1920 × 1080 (16:9)",
    L"1440 × 1080 (16:9)",
    L"1280 × 720 (16:9)",
};

constexpr std::array<const wchar_t*, 4> RECORDING_RATE_TEXTS = {
    L"50 Hz",
    L"25 Hz",
    L"59.94 Hz (60000/1001)",
    L"29.97 Hz (30000/1001)",
};

/// Returns the compile-time checked translation for a valid language and named text key.
const wchar_t* GetLocalizedText(AppLanguage language, TextId id) {
    return localizedLanguages[language].texts[id];
}

/// Returns monitor details by named text keys instead of positional indices into unrelated tables.
MonitorColumnText MonitorColumnsText(AppLanguage language) {
    return MonitorColumnText{
        GetLocalizedText(language, TXT_MONITOR_COLUMN_MODEL),
        GetLocalizedText(language, TXT_MONITOR_COLUMN_REFRESH_RATE),
        GetLocalizedText(language, TXT_MONITOR_COLUMN_BIT_DEPTH),
        GetLocalizedText(language, TXT_MONITOR_COLUMN_COLOR_FORMAT),
        GetLocalizedText(language, TXT_MONITOR_COLUMN_COLOR_SPACE),
        GetLocalizedText(language, TXT_MONITOR_CHANNEL_DEPTH_FORMAT),
        GetLocalizedText(language, TXT_MONITOR_PIXEL_DEPTH_FORMAT)
    };
}

/// Replaces an invalid persisted language value with the application default.
AppLanguage NormalizeLanguage(int language) {
    if (language >= 0 && language < static_cast<int>(LANG_COUNT)) {
        return static_cast<AppLanguage>(language);
    }
    return LANG_EN_US;
}

/// Maps the current user's Windows UI language to a supported language.
AppLanguage DetectSystemLanguage() {
    const LANGID language = GetUserDefaultUILanguage();
    switch (PRIMARYLANGID(language)) {
        case LANG_CZECH:
            return LANG_CS;
        case LANG_ENGLISH:
            if (SUBLANGID(language) == SUBLANG_ENGLISH_UK) {
                return LANG_EN_GB;
            } else if (SUBLANGID(language) == SUBLANG_ENGLISH_AUS) {
                return LANG_EN_AU;
            } else {
                return LANG_EN_US;
            }
        case LANG_GERMAN:
            return LANG_DE;
        case LANG_FRENCH:
            return LANG_FR;
        case LANG_SPANISH:
            return LANG_ES;
        case LANG_ITALIAN:
            return LANG_IT;
        case LANG_POLISH:
            return LANG_PL;
        case LANG_SLOVAK:
            return LANG_SK;
        case LANG_PORTUGUESE:
            return LANG_PT;
        case LANG_NORWEGIAN:
            return LANG_NB;
        case LANG_SWEDISH:
            return LANG_SV;
        case LANG_FINNISH:
            return LANG_FI;
        case LANG_DANISH:
            return LANG_DA;
        case LANG_ICELANDIC:
            return LANG_IS;
        case LANG_TURKISH:
            return LANG_TR;
        case LANG_CROATIAN:
            switch (SUBLANGID(language)) {
                case SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_LATIN:
                case SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_CYRILLIC:
                    return LANG_BS;
                case SUBLANG_SERBIAN_MONTENEGRO_LATIN:
                case SUBLANG_SERBIAN_MONTENEGRO_CYRILLIC:
                    return LANG_CNR;
                case SUBLANG_SERBIAN_LATIN:
                case SUBLANG_SERBIAN_CYRILLIC:
                case SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_LATIN:
                case SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_CYRILLIC:
                case SUBLANG_SERBIAN_SERBIA_LATIN:
                case SUBLANG_SERBIAN_SERBIA_CYRILLIC:
                    return LANG_SR;
                default:
                    return LANG_HR;
            }
        case LANG_ESTONIAN:
            return LANG_ET;
        case LANG_IRISH:
            return LANG_GA;
        case LANG_LITHUANIAN:
            return LANG_LT;
        case LANG_LATVIAN:
            return LANG_LV;
        case LANG_HUNGARIAN:
            return LANG_HU;
        case LANG_MALTESE:
            return LANG_MT;
        case LANG_DUTCH:
            return LANG_NL;
        case LANG_ROMANIAN:
            return LANG_RO;
        case LANG_GREEK:
            return LANG_EL;
        case LANG_SLOVENIAN:
            return LANG_SL;
        case LANG_BELARUSIAN:
            return LANG_BE;
        case LANG_BULGARIAN:
            return LANG_BG;
        case LANG_MACEDONIAN:
            return LANG_MK;
        case LANG_UKRAINIAN:
            return LANG_UK;
        case LANG_RUSSIAN:
            return LANG_RU;
        default:
            return LANG_EN_US;
    }
}

/// Returns a TV resolution caption at the supplied preset index.
const wchar_t* RecordingResolutionText(unsigned index) {
    return RECORDING_RESOLUTION_TEXTS[index];
}

/// Returns an exact TV frame-rate caption at the supplied preset index.
const wchar_t* RecordingRateText(unsigned index) {
    return RECORDING_RATE_TEXTS[index];
}
