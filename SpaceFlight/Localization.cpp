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
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — ovládání" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Nastavení SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Nekonečná vlnící se plocha" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Dálkový let — proměnlivá plocha" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Průlet gravitačně deformovaným prostorem" },
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
            L"Odinstalace se nezdařila, protože je otevřené nastavení SpaceFlight. Zavřete je a odinstalaci "
            L"zopakujte."
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
            L"Hardwarově akcelerovaný let nad vlnícími se a proměnlivými plochami."
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
            L"ANIMACE A NASTAVENÍ\r\nSpaceFlight: Nekonečná vlnící se plocha; Dálkový let — proměnlivá "
            L"plocha; Průlet gravitačně deformovaným prostorem. Každému monitoru přiřaďte právě jednu "
            L"animaci. Textura přepíná mezi texturovanými plochami a drátěným modelem. Volná rotace kamery "
            L"pomalu mění směr pohledu ve všech třech rozměrech. Volba „Pauzy a obraty“ přidává náhodné "
            L"zpomalování, pauzy a změny směru otáčení; dopředný pohyb pokračuje. Rychlost animace je 0–1600 "
            L"%. Každý monitor má nezávislou náhodnou scénu a vykreslování podle své obnovovací frekvence. "
            L"Hlavní světlo, doplňkové světlo, základní jas a přisvětlení obrysů lze pro označené monitory "
            L"zapínat nezávisle. Osvětlení se používá jen u texturovaných ploch. U obou animací ploch lze "
            L"zvolit rovinu, zvlnění nebo trychtýř. Trychtýř vtahuje kameru dovnitř po sestupné spirále. "
            L"Gravitačně deformovaný prostor je zobrazen trojrozměrnou drátěnou mříží. Textura, tvar plochy "
            L"a osvětlení platí jen pro obě animace ploch.\r\n\r\nMONITORY\r\nOznačení řádků určuje, které "
            L"monitory právě nastavujete; není totožné se zatržítky zapínajícími animační výstupy. Ctrl+A "
            L"označí všechny monitory, Ctrl a Shift umožňují upravit označení. Všechny animační volby a "
            L"jezdce platí pro označené monitory. Označení se pamatuje zvlášť pro EXE a SCR. Pokud byly "
            L"označené všechny monitory, označí se i nově připojené. Různé hodnoty na označených monitorech "
            L"ukazuje neurčitý stav zatržítek a tečkování přepínačů, úchytů jezdců a tlačítek „Vše zapnout“ "
            L"a „Vše vypnout“. Popisek jezdce místo společné hodnoty zobrazuje pomlčku. Změna volby nebo "
            L"kliknutí na jezdec sjednotí příslušnou hodnotu na označených monitorech.\r\n\r\nOVLÁDÁNÍ\r\n"
            L"Animační výstupy zapnete nebo vypnete zatržítky u monitorů nebo dvojklikem na jejich řádky. "
            L"Každý monitor používá nezávislou scénu. Snímek ukládá PNG, tlačítko záznamu spouští a ukončuje "
            L"MP4. Pozastavení zastaví animaci. Aplikace také instaluje nebo odinstaluje zabalený spořič. "
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
            L"ANIMACE A NASTAVENÍ\r\nSpaceFlight: Nekonečná vlnící se plocha; Dálkový let — proměnlivá "
            L"plocha; Průlet gravitačně deformovaným prostorem. Každému monitoru přiřaďte právě jednu "
            L"animaci. Textura přepíná mezi texturovanými plochami a drátěným modelem. Volná rotace kamery "
            L"pomalu mění směr pohledu ve všech třech rozměrech. Volba „Pauzy a obraty“ přidává náhodné "
            L"zpomalování, pauzy a změny směru otáčení; dopředný pohyb pokračuje. Rychlost animace je 0–1600 "
            L"%. Každý monitor má nezávislou náhodnou scénu a vykreslování podle své obnovovací frekvence. "
            L"Hlavní světlo, doplňkové světlo, základní jas a přisvětlení obrysů lze pro označené monitory "
            L"zapínat nezávisle. Osvětlení se používá jen u texturovaných ploch. U obou animací ploch lze "
            L"zvolit rovinu, zvlnění nebo trychtýř. Trychtýř vtahuje kameru dovnitř po sestupné spirále. "
            L"Gravitačně deformovaný prostor je zobrazen trojrozměrnou drátěnou mříží. Textura, tvar plochy "
            L"a osvětlení platí jen pro obě animace ploch.\r\n\r\nMONITORY\r\nOznačení řádků určuje, které "
            L"monitory právě nastavujete; není totožné se zatržítky zapínajícími animační výstupy. Ctrl+A "
            L"označí všechny monitory, Ctrl a Shift umožňují upravit označení. Všechny animační volby a "
            L"jezdce platí pro označené monitory. Označení se pamatuje zvlášť pro EXE a SCR. Pokud byly "
            L"označené všechny monitory, označí se i nově připojené. Různé hodnoty na označených monitorech "
            L"ukazuje neurčitý stav zatržítek a tečkování přepínačů, úchytů jezdců a tlačítek „Vše zapnout“ "
            L"a „Vše vypnout“. Popisek jezdce místo společné hodnoty zobrazuje pomlčku. Změna volby nebo "
            L"kliknutí na jezdec sjednotí příslušnou hodnotu na označených monitorech.\r\n\r\nNÁHLED A "
            L"OVLÁDÁNÍ\r\nZapnout náhled spustí celoobrazovkový náhled na všech monitorech; změny lze "
            L"zkoušet za otevřeného nastavení. OK nastavení uloží, Storno je zahodí. Celoobrazovkový spořič "
            L"ukončíte klávesou Esc nebo pohybem myši. Mezi ovládacími prvky přecházejte klávesami Tab a "
            L"Shift+Tab; podtržené volby lze vyvolat pomocí Alt a příslušného písmene. Esc v nastavení "
            L"odpovídá tlačítku Storno; v nápovědě nebo okně O aplikaci zavře pouze toto okno.\r\n\r\n"
            L"SYSTÉMOVÉ POŽADAVKY\r\nPodporovány jsou systémy Windows 7 až Windows 11. Pro spuštění aplikace "
            L"ve Windows Vista SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917. Vykreslování "
            L"vyžaduje Direct3D 11, nikoli jen starší DirectX runtime."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Rovina" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Zvlnění" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Trychtýř" },
    }),
    DefineLanguage(LANG_EN_US, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"English (US)" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Controls" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"SpaceFlight Settings" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Infinite undulating surface" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Long-distance flight — morphing surface" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT,
            L"Flight through gravitationally warped space"
        },
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
            L"Uninstallation failed because SpaceFlight settings are open. Close the settings window and try "
            L"again."
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
            L"Hardware-accelerated flight over undulating and morphing surfaces."
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
            L"ANIMATION AND SETTINGS\r\nSpaceFlight: Infinite undulating surface; Long-distance flight — "
            L"morphing surface; Flight through gravitationally warped space. Assign exactly one animation to "
            L"each display. Texture switches between textured surfaces and wireframe. Free camera rotation "
            L"slowly changes the viewing direction in all three dimensions. The Pauses and reversals option "
            L"adds randomized braking, pauses, and reversals of the rotation; forward flight continues. "
            L"Animation speed ranges from 0–1600%. Every display has an independent randomized scene "
            L"rendered at its own refresh rate. Main light, fill light, ambient light, and rim light can be "
            L"switched independently for the selected displays. Lighting applies only to textured surfaces. "
            L"The two surface animations offer Plane, Waves, or Funnel. Funnel draws the camera inward along "
            L"a descending spiral. The gravitationally warped space flight uses a three-dimensional "
            L"wireframe lattice. Texture, surface shape, and lighting apply only to the two surface "
            L"flights.\r\n\r\nDISPLAYS\r\nRow selection determines which displays you are editing; it is "
            L"separate from the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl "
            L"and Shift adjust the selection. All animation options and sliders apply to the selected "
            L"displays. The selection is remembered separately for EXE and SCR. If all displays were "
            L"selected, newly connected displays join the selection. Different values across selected "
            L"displays are indicated by indeterminate checkboxes and dotted radio buttons, slider thumbs, "
            L"and the “Enable all” and “Disable all” buttons. Slider labels show a dash instead of a shared "
            L"value. Changing an option or clicking a slider applies that value to all selected displays.\r\n"
            L"\r\nCONTROLS\r\nEnable or disable animation outputs using the display checkboxes or by "
            L"double-clicking their rows. Every display uses an independent scene. Snapshot saves a PNG and "
            L"the recording button starts or stops an MP4. Pause stops the animation. The application also "
            L"installs or uninstalls its embedded screen saver. Settings are saved continuously. Only one "
            L"instance of the application runs at a time. Launching it again restores its minimized control "
            L"window and brings it to the foreground. Use Tab and Shift+Tab to move between controls; use "
            L"Alt and the underlined letter to activate a command. Esc closes the active Help or About "
            L"window; in the control window, it exits the application. Pause and screen-saver blocking apply "
            L"to the whole application, regardless of display selection. When blocking is enabled, the "
            L"Windows screen saver is prevented only while unpaused animation is visible on at least one "
            L"display.\r\n\r\nSNAPSHOTS AND RECORDING\r\nSnapshots and recordings capture the first active "
            L"animation display, not a combined image of all displays. PNG uses Pictures and MP4 uses "
            L"Videos, with Documents as the fallback if those folders do not exist. The Recording settings "
            L"button selects Viewport or TV. Viewport preserves the animation display’s dimensions and "
            L"refresh rate, up to 60 frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × 720 "
            L"output in 16:9, with 50, 25, 59.94 (60000/1001) or 29.97 (30000/1001) frames per second. The "
            L"image keeps its aspect ratio; TV uses progressive BT.709 limited-range 4:2:0 video. Resolution "
            L"and frame rate are available only in TV mode. The Recording settings window can be minimized "
            L"and does not block the other application windows. OK saves choices for the next MP4 recording; "
            L"Cancel or Esc discards unconfirmed changes. The recorded display’s animation output cannot be "
            L"disabled during recording; changes to other displays do not stop the recording. Closing the "
            L"application while recording requires confirmation because it also stops the recording.\r\n\r\n"
            L"SYSTEM REQUIREMENTS\r\nWindows 7 through Windows 11 support all features, including PNG "
            L"snapshots and MP4 recording. To run the application on Windows Vista SP2, you must install "
            L"updates KB971512 and KB2117917. MP4 recording does not work on Vista in the current version. "
            L"Rendering requires Direct3D 11, not just an older DirectX runtime. MP4 recording requires "
            L"available Media Foundation components and an H.264 encoder."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATION AND SETTINGS\r\nSpaceFlight: Infinite undulating surface; Long-distance flight — "
            L"morphing surface; Flight through gravitationally warped space. Assign exactly one animation to "
            L"each display. Texture switches between textured surfaces and wireframe. Free camera rotation "
            L"slowly changes the viewing direction in all three dimensions. The Pauses and reversals option "
            L"adds randomized braking, pauses, and reversals of the rotation; forward flight continues. "
            L"Animation speed ranges from 0–1600%. Every display has an independent randomized scene "
            L"rendered at its own refresh rate. Main light, fill light, ambient light, and rim light can be "
            L"switched independently for the selected displays. Lighting applies only to textured surfaces. "
            L"The two surface animations offer Plane, Waves, or Funnel. Funnel draws the camera inward along "
            L"a descending spiral. The gravitationally warped space flight uses a three-dimensional "
            L"wireframe lattice. Texture, surface shape, and lighting apply only to the two surface "
            L"flights.\r\n\r\nDISPLAYS\r\nRow selection determines which displays you are editing; it is "
            L"separate from the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl "
            L"and Shift adjust the selection. All animation options and sliders apply to the selected "
            L"displays. The selection is remembered separately for EXE and SCR. If all displays were "
            L"selected, newly connected displays join the selection. Different values across selected "
            L"displays are indicated by indeterminate checkboxes and dotted radio buttons, slider thumbs, "
            L"and the “Enable all” and “Disable all” buttons. Slider labels show a dash instead of a shared "
            L"value. Changing an option or clicking a slider applies that value to all selected displays.\r\n"
            L"\r\nPREVIEW AND CONTROLS\r\nEnable preview starts a full-screen preview on every display while "
            L"the settings dialog remains open for live adjustments. OK saves the settings and Cancel "
            L"discards them. Exit the full-screen saver with Esc or mouse movement. Use Tab and Shift+Tab to "
            L"move between controls; use Alt and the underlined letter to activate a command. Esc in the "
            L"settings dialog is equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\n"
            L"SYSTEM REQUIREMENTS\r\nWindows 7 through Windows 11 are supported. To run the application on "
            L"Windows Vista SP2, you must install updates KB971512 and KB2117917. Rendering requires "
            L"Direct3D 11, not just an older DirectX runtime."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Plane" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Waves" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Funnel" },
    }),
    DefineLanguage(LANG_EN_GB, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"English (UK)" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Controls" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"SpaceFlight Settings" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Infinite undulating surface" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Long-distance flight — morphing surface" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT,
            L"Flight through gravitationally warped space"
        },
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
            L"Uninstallation failed because SpaceFlight settings are open. Close the settings window and try "
            L"again."
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
            L"Hardware-accelerated flight over undulating and morphing surfaces."
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
            L"ANIMATION AND SETTINGS\r\nSpaceFlight: Infinite undulating surface; Long-distance flight — "
            L"morphing surface; Flight through gravitationally warped space. Assign exactly one animation to "
            L"each display. Texture switches between textured surfaces and wireframe. Free camera rotation "
            L"slowly changes the viewing direction in all three dimensions. The Pauses and reversals option "
            L"adds randomised braking, pauses and reversals of the rotation; forward flight continues. "
            L"Animation speed ranges from 0–1600%. Every display has an independent randomised scene "
            L"rendered at its own refresh rate. Main light, fill light, ambient light and rim light can be "
            L"switched independently for the selected displays. Lighting applies only to textured surfaces. "
            L"The two surface animations offer Plane, Waves, or Funnel. Funnel draws the camera inward along "
            L"a descending spiral. The gravitationally warped space flight uses a three-dimensional "
            L"wireframe lattice. Texture, surface shape and lighting apply only to the two surface flights.\r"
            L"\n\r\nDISPLAYS\r\nRow selection determines which displays you are editing; it is separate from "
            L"the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift "
            L"adjust the selection. All animation options and sliders apply to the selected displays. The "
            L"selection is remembered separately for EXE and SCR. If all displays were selected, newly "
            L"connected displays join the selection. Different values across selected displays are indicated "
            L"by indeterminate checkboxes and dotted radio buttons, slider thumbs and the “Enable all” and "
            L"“Disable all” buttons. Slider labels show a dash instead of a shared value. Changing an option "
            L"or clicking a slider applies that value to all selected displays.\r\n\r\nCONTROLS\r\nEnable or "
            L"disable animation outputs using the display checkboxes or by double-clicking their rows. Each "
            L"display uses an independent scene. Snapshot saves PNG and the recording button starts or stops "
            L"MP4. Pause stops the animation. The application also installs or uninstalls its embedded "
            L"screen saver. Settings are saved continuously. Only one instance of the application runs at a "
            L"time. Launching it again restores its minimised control window and brings it to the "
            L"foreground. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter "
            L"to activate a command. Esc closes the active Help or About window; in the control window, it "
            L"exits the application. Pause and screen-saver blocking apply to the whole application, "
            L"regardless of display selection. When blocking is enabled, the Windows screen saver is "
            L"prevented only while unpaused animation is visible on at least one display.\r\n\r\nSNAPSHOTS "
            L"AND RECORDING\r\nSnapshots and recordings capture the first active animation display, not a "
            L"combined image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the "
            L"fallback if those folders do not exist. The Recording settings button selects Viewport or TV. "
            L"Viewport preserves the animation display’s dimensions and refresh rate, up to 60 frames per "
            L"second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 "
            L"(60000/1001) or 29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV "
            L"uses progressive BT.709 limited-range 4:2:0 video. Resolution and frame rate are available "
            L"only in TV mode. The Recording settings window can be minimised and does not block the other "
            L"application windows. OK saves choices for the next MP4 recording; Cancel or Esc discards "
            L"unconfirmed changes. The recorded display’s animation output cannot be disabled during "
            L"recording; changes to other displays do not stop the recording. Closing the application while "
            L"recording requires confirmation because it also stops the recording.\r\n\r\nSYSTEM "
            L"REQUIREMENTS\r\nWindows 7 through Windows 11 support all features, including PNG snapshots and "
            L"MP4 recording. To run the application on Windows Vista SP2, you must install updates KB971512 "
            L"and KB2117917. MP4 recording does not work on Vista in the current version. Rendering requires "
            L"Direct3D 11, not just an older DirectX runtime. MP4 recording requires available Media "
            L"Foundation components and an H.264 encoder."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATION AND SETTINGS\r\nSpaceFlight: Infinite undulating surface; Long-distance flight — "
            L"morphing surface; Flight through gravitationally warped space. Assign exactly one animation to "
            L"each display. Texture switches between textured surfaces and wireframe. Free camera rotation "
            L"slowly changes the viewing direction in all three dimensions. The Pauses and reversals option "
            L"adds randomised braking, pauses and reversals of the rotation; forward flight continues. "
            L"Animation speed ranges from 0–1600%. Every display has an independent randomised scene "
            L"rendered at its own refresh rate. Main light, fill light, ambient light and rim light can be "
            L"switched independently for the selected displays. Lighting applies only to textured surfaces. "
            L"The two surface animations offer Plane, Waves, or Funnel. Funnel draws the camera inward along "
            L"a descending spiral. The gravitationally warped space flight uses a three-dimensional "
            L"wireframe lattice. Texture, surface shape and lighting apply only to the two surface flights.\r"
            L"\n\r\nDISPLAYS\r\nRow selection determines which displays you are editing; it is separate from "
            L"the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift "
            L"adjust the selection. All animation options and sliders apply to the selected displays. The "
            L"selection is remembered separately for EXE and SCR. If all displays were selected, newly "
            L"connected displays join the selection. Different values across selected displays are indicated "
            L"by indeterminate checkboxes and dotted radio buttons, slider thumbs and the “Enable all” and "
            L"“Disable all” buttons. Slider labels show a dash instead of a shared value. Changing an option "
            L"or clicking a slider applies that value to all selected displays.\r\n\r\nPREVIEW AND CONTROLS\r"
            L"\nEnable preview starts a full-screen preview on every display and allows live adjustments "
            L"while the settings dialog remains open. OK saves the settings and Cancel discards them. Exit "
            L"the full-screen screen saver with Esc or mouse movement. Use Tab and Shift+Tab to move between "
            L"controls; use Alt and the underlined letter to activate a command. Esc in the settings dialog "
            L"is equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\nSYSTEM "
            L"REQUIREMENTS\r\nWindows 7 through Windows 11 are supported. To run the application on Windows "
            L"Vista SP2, you must install updates KB971512 and KB2117917. Rendering requires Direct3D 11, "
            L"not just an older DirectX runtime."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Plane" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Waves" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Funnel" },
    }),
    DefineLanguage(LANG_EN_AU, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"English (Australia)" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Controls" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"SpaceFlight Settings" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Infinite undulating surface" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Long-distance flight — morphing surface" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT,
            L"Flight through gravitationally warped space"
        },
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
            L"Uninstallation failed because SpaceFlight settings are open. Close the settings window and try "
            L"again."
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
            L"Hardware-accelerated flight over undulating and morphing surfaces."
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
            L"ANIMATION AND SETTINGS\r\nSpaceFlight: Infinite undulating surface; Long-distance flight — "
            L"morphing surface; Flight through gravitationally warped space. Assign exactly one animation to "
            L"each display. Texture switches between textured surfaces and wireframe. Free camera rotation "
            L"slowly changes the viewing direction in all three dimensions. The Pauses and reversals option "
            L"adds randomised braking, pauses and reversals of the rotation; forward flight continues. "
            L"Animation speed ranges from 0–1600%. Every display has an independent randomised scene "
            L"rendered at its own refresh rate. Main light, fill light, ambient light and rim light can be "
            L"switched independently for the selected displays. Lighting applies only to textured surfaces. "
            L"The two surface animations offer Plane, Waves, or Funnel. Funnel draws the camera inward along "
            L"a descending spiral. The gravitationally warped space flight uses a three-dimensional "
            L"wireframe lattice. Texture, surface shape and lighting apply only to the two surface flights.\r"
            L"\n\r\nDISPLAYS\r\nRow selection determines which displays you are editing; it is separate from "
            L"the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift "
            L"adjust the selection. All animation options and sliders apply to the selected displays. The "
            L"selection is remembered separately for EXE and SCR. If all displays were selected, newly "
            L"connected displays join the selection. Different values across selected displays are indicated "
            L"by indeterminate checkboxes and dotted radio buttons, slider thumbs and the “Enable all” and "
            L"“Disable all” buttons. Slider labels show a dash instead of a shared value. Changing an option "
            L"or clicking a slider applies that value to all selected displays.\r\n\r\nCONTROLS\r\nEnable or "
            L"disable animation outputs using the display checkboxes or by double-clicking their rows. Each "
            L"display uses an independent scene. Snapshot saves PNG and the recording button starts or stops "
            L"MP4. Pause stops the animation. The application also installs or uninstalls its embedded "
            L"screen saver. Settings are saved continuously. Only one instance of the application runs at a "
            L"time. Launching it again restores its minimised control window and brings it to the "
            L"foreground. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter "
            L"to activate a command. Esc closes the active Help or About window; in the control window, it "
            L"exits the application. Pause and screen-saver blocking apply to the whole application, "
            L"regardless of display selection. When blocking is enabled, the Windows screen saver is "
            L"prevented only while unpaused animation is visible on at least one display.\r\n\r\nSNAPSHOTS "
            L"AND RECORDING\r\nSnapshots and recordings capture the first active animation display, not a "
            L"combined image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the "
            L"fallback if those folders do not exist. The Recording settings button selects Viewport or TV. "
            L"Viewport preserves the animation display’s dimensions and refresh rate, up to 60 frames per "
            L"second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 "
            L"(60000/1001) or 29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV "
            L"uses progressive BT.709 limited-range 4:2:0 video. Resolution and frame rate are available "
            L"only in TV mode. The Recording settings window can be minimised and does not block the other "
            L"application windows. OK saves choices for the next MP4 recording; Cancel or Esc discards "
            L"unconfirmed changes. The recorded display’s animation output cannot be disabled during "
            L"recording; changes to other displays do not stop the recording. Closing the application while "
            L"recording requires confirmation because it also stops the recording.\r\n\r\nSYSTEM "
            L"REQUIREMENTS\r\nWindows 7 through Windows 11 support all features, including PNG snapshots and "
            L"MP4 recording. To run the application on Windows Vista SP2, you must install updates KB971512 "
            L"and KB2117917. MP4 recording does not work on Vista in the current version. Rendering requires "
            L"Direct3D 11, not just an older DirectX runtime. MP4 recording requires available Media "
            L"Foundation components and an H.264 encoder."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATION AND SETTINGS\r\nSpaceFlight: Infinite undulating surface; Long-distance flight — "
            L"morphing surface; Flight through gravitationally warped space. Assign exactly one animation to "
            L"each display. Texture switches between textured surfaces and wireframe. Free camera rotation "
            L"slowly changes the viewing direction in all three dimensions. The Pauses and reversals option "
            L"adds randomised braking, pauses and reversals of the rotation; forward flight continues. "
            L"Animation speed ranges from 0–1600%. Every display has an independent randomised scene "
            L"rendered at its own refresh rate. Main light, fill light, ambient light and rim light can be "
            L"switched independently for the selected displays. Lighting applies only to textured surfaces. "
            L"The two surface animations offer Plane, Waves, or Funnel. Funnel draws the camera inward along "
            L"a descending spiral. The gravitationally warped space flight uses a three-dimensional "
            L"wireframe lattice. Texture, surface shape and lighting apply only to the two surface flights.\r"
            L"\n\r\nDISPLAYS\r\nRow selection determines which displays you are editing; it is separate from "
            L"the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift "
            L"adjust the selection. All animation options and sliders apply to the selected displays. The "
            L"selection is remembered separately for EXE and SCR. If all displays were selected, newly "
            L"connected displays join the selection. Different values across selected displays are indicated "
            L"by indeterminate checkboxes and dotted radio buttons, slider thumbs and the “Enable all” and "
            L"“Disable all” buttons. Slider labels show a dash instead of a shared value. Changing an option "
            L"or clicking a slider applies that value to all selected displays.\r\n\r\nPREVIEW AND CONTROLS\r"
            L"\nEnable preview starts a full-screen preview on every display and allows live adjustments "
            L"while the settings dialog remains open. OK saves the settings and Cancel discards them. Exit "
            L"the full-screen screen saver with Esc or mouse movement. Use Tab and Shift+Tab to move between "
            L"controls; use Alt and the underlined letter to activate a command. Esc in the settings dialog "
            L"is equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\nSYSTEM "
            L"REQUIREMENTS\r\nWindows 7 through Windows 11 are supported. To run the application on Windows "
            L"Vista SP2, you must install updates KB971512 and KB2117917. Rendering requires Direct3D 11, "
            L"not just an older DirectX runtime."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Plane" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Waves" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Funnel" },
    }),
    DefineLanguage(LANG_DE, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Deutsch" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Steuerung" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"SpaceFlight-Einstellungen" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Unendliche wellenförmige Fläche" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Fernflug — veränderliche Fläche" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Flug durch gravitativ gekrümmten Raum" },
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
            L"Die Deinstallation ist fehlgeschlagen, weil die SpaceFlight-Einstellungen geöffnet sind. "
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
            L"Hardwarebeschleunigter Flug über wellenförmige und veränderliche Flächen."
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
            L"ANIMATION UND EINSTELLUNGEN\r\nSpaceFlight: Unendliche wellenförmige Fläche; Fernflug — "
            L"veränderliche Fläche; Flug durch gravitativ gekrümmten Raum. Weisen Sie jedem Monitor genau "
            L"eine Animation zu. Textur wechselt zwischen texturierten Flächen und Drahtgittermodell. Die "
            L"freie Kameradrehung verändert die Blickrichtung langsam in allen drei Dimensionen. Die Option "
            L"„Pausen und Umkehr“ ergänzt zufälliges Abbremsen, Pausen und Wechsel der Drehrichtung; der "
            L"Vorwärtsflug läuft weiter. Die Animationsgeschwindigkeit beträgt 0–1600 %. Jeder Monitor "
            L"besitzt eine unabhängige zufällige Szene und wird mit seiner eigenen Bildwiederholrate "
            L"angesteuert. Hauptlicht, Aufhelllicht, Umgebungslicht und Konturlicht lassen sich für die "
            L"ausgewählten Monitore unabhängig schalten. Die Beleuchtung gilt nur für texturierte Flächen. "
            L"Die beiden Animationen mit Flächen bieten Ebene, Wellen oder Trichter. Im Trichter bewegt sich "
            L"die Kamera auf einer absteigenden Spirale nach innen. Der Flug durch gravitativ gekrümmten "
            L"Raum zeigt ein dreidimensionales Drahtgitter. Textur, Flächenform und Beleuchtung gelten nur "
            L"für die beiden Animationen mit Flächen.\r\n\r\nMONITORE\r\nDie Zeilenauswahl bestimmt, welche "
            L"Monitore Sie bearbeiten; sie ist von den Kontrollkästchen zum Einschalten der "
            L"Animationsausgabe getrennt. Strg+A wählt alle Monitore, Strg und Umschalt ändern die Auswahl. "
            L"Alle Animationsoptionen und Regler gelten für die ausgewählten Monitore. Die Auswahl wird für "
            L"EXE und SCR getrennt gespeichert. Waren alle Monitore ausgewählt, werden auch neu "
            L"angeschlossene ausgewählt. Unterschiedliche Werte der ausgewählten Monitore werden durch "
            L"unbestimmte Kontrollkästchen und gepunktete Optionsfelder, Reglergriffe sowie Schaltflächen "
            L"„Alle aktivieren“ und „Alle deaktivieren“ angezeigt. Reglerbeschriftungen zeigen statt eines "
            L"gemeinsamen Werts einen Gedankenstrich. Das Ändern einer Option oder Anklicken eines Reglers "
            L"übernimmt diesen Wert für alle ausgewählten Monitore.\r\n\r\nBEDIENUNG\r\nDie "
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
            L"ANIMATION UND EINSTELLUNGEN\r\nSpaceFlight: Unendliche wellenförmige Fläche; Fernflug — "
            L"veränderliche Fläche; Flug durch gravitativ gekrümmten Raum. Weisen Sie jedem Monitor genau "
            L"eine Animation zu. Textur wechselt zwischen texturierten Flächen und Drahtgittermodell. Die "
            L"freie Kameradrehung verändert die Blickrichtung langsam in allen drei Dimensionen. Die Option "
            L"„Pausen und Umkehr“ ergänzt zufälliges Abbremsen, Pausen und Wechsel der Drehrichtung; der "
            L"Vorwärtsflug läuft weiter. Die Animationsgeschwindigkeit beträgt 0–1600 %. Jeder Monitor "
            L"besitzt eine unabhängige zufällige Szene und wird mit seiner eigenen Bildwiederholrate "
            L"angesteuert. Hauptlicht, Aufhelllicht, Umgebungslicht und Konturlicht lassen sich für die "
            L"ausgewählten Monitore unabhängig schalten. Die Beleuchtung gilt nur für texturierte Flächen. "
            L"Die beiden Animationen mit Flächen bieten Ebene, Wellen oder Trichter. Im Trichter bewegt sich "
            L"die Kamera auf einer absteigenden Spirale nach innen. Der Flug durch gravitativ gekrümmten "
            L"Raum zeigt ein dreidimensionales Drahtgitter. Textur, Flächenform und Beleuchtung gelten nur "
            L"für die beiden Animationen mit Flächen.\r\n\r\nMONITORE\r\nDie Zeilenauswahl bestimmt, welche "
            L"Monitore Sie bearbeiten; sie ist von den Kontrollkästchen zum Einschalten der "
            L"Animationsausgabe getrennt. Strg+A wählt alle Monitore, Strg und Umschalt ändern die Auswahl. "
            L"Alle Animationsoptionen und Regler gelten für die ausgewählten Monitore. Die Auswahl wird für "
            L"EXE und SCR getrennt gespeichert. Waren alle Monitore ausgewählt, werden auch neu "
            L"angeschlossene ausgewählt. Unterschiedliche Werte der ausgewählten Monitore werden durch "
            L"unbestimmte Kontrollkästchen und gepunktete Optionsfelder, Reglergriffe sowie Schaltflächen "
            L"„Alle aktivieren“ und „Alle deaktivieren“ angezeigt. Reglerbeschriftungen zeigen statt eines "
            L"gemeinsamen Werts einen Gedankenstrich. Das Ändern einer Option oder Anklicken eines Reglers "
            L"übernimmt diesen Wert für alle ausgewählten Monitore.\r\n\r\nVORSCHAU UND BEDIENUNG\r\n"
            L"Vorschau einschalten startet eine Vollbildvorschau auf allen Monitoren. Der Einstellungsdialog "
            L"bleibt für Änderungen geöffnet. OK speichert, Abbrechen verwirft. Esc oder eine Mausbewegung "
            L"beendet den Vollbildschoner. Mit Tab und Umschalt+Tab wechseln Sie zwischen den "
            L"Steuerelementen; mit Alt und dem unterstrichenen Buchstaben rufen Sie einen Befehl auf. Esc im "
            L"Einstellungsdialog entspricht Abbrechen; in der Hilfe oder im Infofenster schließt es nur "
            L"dieses Fenster.\r\n\r\nSYSTEMANFORDERUNGEN\r\nUnterstützt werden Windows 7 bis Windows 11. Zum "
            L"Ausführen der Anwendung unter Windows Vista SP2 müssen die Updates KB971512 und KB2117917 "
            L"installiert werden. Die Darstellung erfordert Direct3D 11, nicht nur eine ältere "
            L"DirectX-Laufzeitumgebung."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Ebene" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Wellen" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Trichter" },
    }),
    DefineLanguage(LANG_FR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Français" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Commandes" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Paramètres de SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Surface ondulante infinie" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Vol longue distance — surface déformable" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT,
            L"Vol dans un espace déformé par la gravitation"
        },
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
            L"La désinstallation a échoué car les paramètres de SpaceFlight sont ouverts. Fermez cette "
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
            L"Vol accéléré par le matériel au-dessus de surfaces ondulantes et déformables."
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
            L"ANIMATION ET PARAMÈTRES\r\nSpaceFlight: Surface ondulante infinie; Vol longue distance — "
            L"surface déformable; Vol dans un espace déformé par la gravitation. Attribuez une seule "
            L"animation à chaque écran. Texture alterne entre surfaces texturées et modèle filaire. La "
            L"rotation libre de la caméra change lentement la direction du regard dans les trois dimensions. "
            L"L’option « Pauses et inversions » ajoute des ralentissements, pauses et inversions aléatoires "
            L"de la rotation ; le vol vers l’avant continue. La vitesse va de 0 à 1600 %. Chaque écran "
            L"possède une scène aléatoire indépendante, rendue à sa propre fréquence de rafraîchissement. La "
            L"lumière principale, la lumière d’appoint, l’éclairage ambiant et l’éclairage des contours se "
            L"règlent indépendamment pour les écrans sélectionnés. L’éclairage ne concerne que les surfaces "
            L"texturées. Les deux animations de surfaces proposent Plan, Ondulations ou Entonnoir. "
            L"L’entonnoir attire la caméra vers l’intérieur suivant une spirale descendante. Le vol dans un "
            L"espace déformé par la gravitation affiche une grille filaire tridimensionnelle. Les options de "
            L"texture, de forme de surface et d’éclairage ne concernent que les deux animations de "
            L"surfaces.\r\n\r\nÉCRANS\r\nLa sélection des lignes détermine les écrans à configurer ; elle "
            L"est distincte des cases qui activent les sorties d’animation. Ctrl+A sélectionne tous les "
            L"écrans ; Ctrl et Maj modifient la sélection. Toutes les options et tous les curseurs "
            L"d’animation concernent les écrans sélectionnés. La sélection est mémorisée séparément pour EXE "
            L"et SCR. Si tous les écrans étaient sélectionnés, les nouveaux le sont également. Des valeurs "
            L"différentes entre les écrans sélectionnés sont indiquées par des cases à cocher indéterminées "
            L"et des pointillés sur les boutons radio, les poignées des curseurs et les boutons « Tout "
            L"activer » et « Tout désactiver ». Les libellés des curseurs affichent un tiret au lieu d’une "
            L"valeur commune. Modifier une option ou cliquer sur un curseur applique cette valeur à tous les "
            L"écrans sélectionnés.\r\n\r\nCOMMANDES\r\nActivez ou désactivez les sorties d’animation avec "
            L"les cases des écrans ou en double-cliquant sur leurs lignes. Chaque moniteur utilise une scène "
            L"indépendante. Capture enregistre un PNG et le bouton d’enregistrement démarre ou arrête un "
            L"MP4. Pause arrête l’animation. L’application installe ou désinstalle aussi son économiseur "
            L"intégré. Les réglages sont enregistrés en continu. Une seule instance de l’application peut "
            L"fonctionner à la fois. Un nouveau lancement restaure la fenêtre de contrôle réduite et la "
            L"place au premier plan. Utilisez Tab et Maj+Tab pour passer d’un contrôle à l’autre ; Alt et la "
            L"lettre soulignée activent une commande. Échap ferme la fenêtre d’aide ou À propos active ; "
            L"dans la fenêtre de contrôle, cette touche quitte l’application. La pause et le blocage de "
            L"l’écran de veille s’appliquent à toute l’application, indépendamment des écrans sélectionnés. "
            L"Lorsque le blocage est activé, l’écran de veille Windows est empêché uniquement tant qu’une "
            L"animation visible et non suspendue s’affiche sur au moins un écran.\r\n\r\nCAPTURES ET "
            L"ENREGISTREMENT\r\nLes captures et les enregistrements utilisent le premier moniteur "
            L"d’animation actif, et non une image combinant tous les moniteurs. PNG utilise Images, MP4 "
            L"Vidéos ; Documents sert de repli si ces dossiers n’existent pas. Le bouton Réglages vidéo "
            L"permet de choisir Viewport ou TV. Viewport conserve les dimensions et la fréquence de "
            L"rafraîchissement du moniteur d’animation, jusqu’à 60 images par seconde. TV propose 1920 × "
            L"1080, 1440 × 1080 ou 1280 × 720 au format 16:9, à 50, 25, 59.94 (60000/1001) ou 29.97 "
            L"(30000/1001) images par seconde. Le rapport d’aspect est conservé ; TV utilise une vidéo "
            L"progressive BT.709 à plage limitée et sous-échantillonnage 4:2:0. La résolution et la "
            L"fréquence d’images ne sont disponibles qu’en mode TV. La fenêtre Réglages vidéo peut être "
            L"réduite et ne bloque pas les autres fenêtres de l’application. OK enregistre les choix pour le "
            L"prochain enregistrement MP4 ; Annuler ou Échap abandonne les modifications non confirmées. La "
            L"sortie d’animation du moniteur enregistré ne peut pas être désactivée pendant l’enregistrement "
            L"; les changements concernant les autres moniteurs ne l’arrêtent pas. Fermer l’application "
            L"pendant un enregistrement nécessite une confirmation, car cela arrête aussi l’enregistrement.\r"
            L"\n\r\nCONFIGURATION REQUISE\r\nWindows 7 à Windows 11 prennent en charge toutes les fonctions, "
            L"y compris les captures PNG et l’enregistrement MP4. Pour exécuter l’application sous Windows "
            L"Vista SP2, il est nécessaire d’installer les mises à jour KB971512 et KB2117917. "
            L"L’enregistrement MP4 ne fonctionne pas sous Vista dans la version actuelle. L’affichage "
            L"nécessite Direct3D 11, et pas seulement un ancien environnement d’exécution DirectX. "
            L"L’enregistrement MP4 nécessite les composants Media Foundation et un encodeur H.264 "
            L"disponibles."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATION ET PARAMÈTRES\r\nSpaceFlight: Surface ondulante infinie; Vol longue distance — "
            L"surface déformable; Vol dans un espace déformé par la gravitation. Attribuez une seule "
            L"animation à chaque écran. Texture alterne entre surfaces texturées et modèle filaire. La "
            L"rotation libre de la caméra change lentement la direction du regard dans les trois dimensions. "
            L"L’option « Pauses et inversions » ajoute des ralentissements, pauses et inversions aléatoires "
            L"de la rotation ; le vol vers l’avant continue. La vitesse va de 0 à 1600 %. Chaque écran "
            L"possède une scène aléatoire indépendante, rendue à sa propre fréquence de rafraîchissement. La "
            L"lumière principale, la lumière d’appoint, l’éclairage ambiant et l’éclairage des contours se "
            L"règlent indépendamment pour les écrans sélectionnés. L’éclairage ne concerne que les surfaces "
            L"texturées. Les deux animations de surfaces proposent Plan, Ondulations ou Entonnoir. "
            L"L’entonnoir attire la caméra vers l’intérieur suivant une spirale descendante. Le vol dans un "
            L"espace déformé par la gravitation affiche une grille filaire tridimensionnelle. Les options de "
            L"texture, de forme de surface et d’éclairage ne concernent que les deux animations de "
            L"surfaces.\r\n\r\nÉCRANS\r\nLa sélection des lignes détermine les écrans à configurer ; elle "
            L"est distincte des cases qui activent les sorties d’animation. Ctrl+A sélectionne tous les "
            L"écrans ; Ctrl et Maj modifient la sélection. Toutes les options et tous les curseurs "
            L"d’animation concernent les écrans sélectionnés. La sélection est mémorisée séparément pour EXE "
            L"et SCR. Si tous les écrans étaient sélectionnés, les nouveaux le sont également. Des valeurs "
            L"différentes entre les écrans sélectionnés sont indiquées par des cases à cocher indéterminées "
            L"et des pointillés sur les boutons radio, les poignées des curseurs et les boutons « Tout "
            L"activer » et « Tout désactiver ». Les libellés des curseurs affichent un tiret au lieu d’une "
            L"valeur commune. Modifier une option ou cliquer sur un curseur applique cette valeur à tous les "
            L"écrans sélectionnés.\r\n\r\nAPERÇU ET COMMANDES\r\nActiver l’aperçu lance un aperçu plein "
            L"écran sur tous les moniteurs ; la boîte de dialogue reste ouverte pour les réglages en direct. "
            L"OK enregistre les réglages, Annuler les abandonne. Échap ou un mouvement de souris quitte le "
            L"plein écran. Utilisez Tab et Maj+Tab pour passer d’un contrôle à l’autre ; Alt et la lettre "
            L"soulignée activent une commande. Échap dans les réglages équivaut à Annuler ; dans l’aide ou À "
            L"propos, cette touche ferme uniquement cette fenêtre.\r\n\r\nCONFIGURATION REQUISE\r\nWindows 7 "
            L"à Windows 11 sont pris en charge. Pour exécuter l’application sous Windows Vista SP2, il est "
            L"nécessaire d’installer les mises à jour KB971512 et KB2117917. L’affichage nécessite Direct3D "
            L"11, et pas seulement un ancien environnement d’exécution DirectX."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Plan" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Ondulations" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Entonnoir" },
    }),
    DefineLanguage(LANG_ES, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Español" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Control" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Configuración de SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Superficie ondulante infinita" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Vuelo de larga distancia — superficie deformable" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT,
            L"Vuelo por el espacio deformado por la gravedad"
        },
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
            L"La desinstalación falló porque la configuración de SpaceFlight está abierta. Cierre esa "
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
            L"Vuelo acelerado por hardware sobre superficies ondulantes y deformables."
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
            L"ANIMACIÓN Y AJUSTES\r\nSpaceFlight: Superficie ondulante infinita; Vuelo de larga distancia — "
            L"superficie deformable; Vuelo por el espacio deformado por la gravedad. Asigne una sola "
            L"animación a cada pantalla. Textura alterna entre superficies texturizadas y modelo de alambre. "
            L"El giro libre de la cámara cambia lentamente la dirección de la vista en las tres dimensiones. "
            L"La opción «Pausas e inversiones» añade frenadas, pausas e inversiones aleatorias del giro; el "
            L"vuelo hacia delante continúa. La velocidad va del 0 al 1600 %. Cada pantalla tiene una escena "
            L"aleatoria independiente y se renderiza a su propia frecuencia de actualización. La luz "
            L"principal, la luz de relleno, la luz ambiental y la iluminación de contornos se activan por "
            L"separado para las pantallas seleccionadas. La iluminación solo se aplica a las superficies "
            L"texturizadas. Las dos animaciones de superficies ofrecen Plano, Ondulación o Embudo. El embudo "
            L"atrae la cámara hacia el interior siguiendo una espiral descendente. El vuelo por el espacio "
            L"deformado por la gravedad muestra una malla alámbrica tridimensional. Las opciones de textura, "
            L"forma de superficie e iluminación solo se aplican a las dos animaciones de superficies.\r\n\r\n"
            L"MONITORES\r\nLa selección de filas determina qué pantallas se están configurando; es "
            L"independiente de las casillas que activan las salidas de animación. Ctrl+A selecciona todas; "
            L"Ctrl y Mayús modifican la selección. Todas las opciones y los controles deslizantes de "
            L"animación se aplican a las pantallas seleccionadas. La selección se recuerda por separado para "
            L"EXE y SCR. Si estaban seleccionadas todas, se incluyen también las nuevas. Los valores "
            L"distintos entre las pantallas seleccionadas se indican mediante casillas indeterminadas y un "
            L"punteado en los botones de opción, los tiradores de los controles deslizantes y los botones "
            L"«Activar todo» y «Desactivar todo». Las etiquetas de los controles deslizantes muestran una "
            L"raya en lugar de un valor común. Cambiar una opción o hacer clic en un control deslizante "
            L"aplica ese valor a todas las pantallas seleccionadas.\r\n\r\nCONTROLES\r\nActive o desactive "
            L"las salidas de animación mediante las casillas de las pantallas o haciendo doble clic en sus "
            L"filas. Cada monitor usa una escena independiente. Captura guarda un PNG y el botón de "
            L"grabación inicia o detiene un MP4. Pausar detiene la animación. La aplicación instala o "
            L"desinstala además el salvapantallas incorporado. Los ajustes se guardan continuamente. La "
            L"aplicación solo permite una instancia. Al volver a iniciarla, restaura la ventana de control "
            L"minimizada y la trae al primer plano. Use Tab y Mayús+Tab para desplazarse entre controles; "
            L"Alt y la letra subrayada activan una opción. Esc cierra la ventana activa de Ayuda o Acerca "
            L"de; en la ventana de control, sale de la aplicación. La pausa y el bloqueo del salvapantallas "
            L"se aplican a toda la aplicación, independientemente de las pantallas seleccionadas. Si el "
            L"bloqueo está activado, solo se impide el salvapantallas de Windows mientras haya animación "
            L"visible y no pausada en al menos una pantalla.\r\n\r\nCAPTURAS Y GRABACIÓN\r\nLas capturas y "
            L"grabaciones usan el primer monitor de animación activo, no una imagen conjunta de todos los "
            L"monitores. PNG usa Imágenes y MP4 Vídeos; si no existen esas carpetas, se usa Documentos. El "
            L"botón Ajustes de grabación permite elegir Viewport o TV. Viewport conserva las dimensiones y "
            L"la frecuencia de actualización del monitor de animación, hasta 60 fotogramas por segundo. TV "
            L"ofrece 1920 × 1080, 1440 × 1080 o 1280 × 720 en formato 16:9, a 50, 25, 59.94 (60000/1001) o "
            L"29.97 (30000/1001) fotogramas por segundo. Se conserva la relación de aspecto; TV usa vídeo "
            L"progresivo BT.709 de rango limitado y submuestreo 4:2:0. La resolución y la frecuencia solo "
            L"están disponibles en modo TV. La ventana Ajustes de grabación se puede minimizar y no bloquea "
            L"las demás ventanas de la aplicación. Aceptar guarda las opciones para la próxima grabación "
            L"MP4; Cancelar o Esc descarta los cambios sin confirmar. La salida de animación del monitor "
            L"grabado no se puede desactivar durante la grabación; cambiar otros monitores no la detiene. "
            L"Cerrar la aplicación durante una grabación requiere confirmación porque también detiene la "
            L"grabación.\r\n\r\nREQUISITOS DEL SISTEMA\r\nWindows 7 a Windows 11 admiten todas las "
            L"funciones, incluidas las capturas PNG y la grabación MP4. Para ejecutar la aplicación en "
            L"Windows Vista SP2, es necesario instalar las actualizaciones KB971512 y KB2117917. La "
            L"grabación MP4 no funciona en Vista en la versión actual. La representación requiere Direct3D "
            L"11, no solo un entorno de ejecución antiguo de DirectX. La grabación MP4 requiere componentes "
            L"de Media Foundation y un codificador H.264 disponibles."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACIÓN Y AJUSTES\r\nSpaceFlight: Superficie ondulante infinita; Vuelo de larga distancia — "
            L"superficie deformable; Vuelo por el espacio deformado por la gravedad. Asigne una sola "
            L"animación a cada pantalla. Textura alterna entre superficies texturizadas y modelo de alambre. "
            L"El giro libre de la cámara cambia lentamente la dirección de la vista en las tres dimensiones. "
            L"La opción «Pausas e inversiones» añade frenadas, pausas e inversiones aleatorias del giro; el "
            L"vuelo hacia delante continúa. La velocidad va del 0 al 1600 %. Cada pantalla tiene una escena "
            L"aleatoria independiente y se renderiza a su propia frecuencia de actualización. La luz "
            L"principal, la luz de relleno, la luz ambiental y la iluminación de contornos se activan por "
            L"separado para las pantallas seleccionadas. La iluminación solo se aplica a las superficies "
            L"texturizadas. Las dos animaciones de superficies ofrecen Plano, Ondulación o Embudo. El embudo "
            L"atrae la cámara hacia el interior siguiendo una espiral descendente. El vuelo por el espacio "
            L"deformado por la gravedad muestra una malla alámbrica tridimensional. Las opciones de textura, "
            L"forma de superficie e iluminación solo se aplican a las dos animaciones de superficies.\r\n\r\n"
            L"MONITORES\r\nLa selección de filas determina qué pantallas se están configurando; es "
            L"independiente de las casillas que activan las salidas de animación. Ctrl+A selecciona todas; "
            L"Ctrl y Mayús modifican la selección. Todas las opciones y los controles deslizantes de "
            L"animación se aplican a las pantallas seleccionadas. La selección se recuerda por separado para "
            L"EXE y SCR. Si estaban seleccionadas todas, se incluyen también las nuevas. Los valores "
            L"distintos entre las pantallas seleccionadas se indican mediante casillas indeterminadas y un "
            L"punteado en los botones de opción, los tiradores de los controles deslizantes y los botones "
            L"«Activar todo» y «Desactivar todo». Las etiquetas de los controles deslizantes muestran una "
            L"raya en lugar de un valor común. Cambiar una opción o hacer clic en un control deslizante "
            L"aplica ese valor a todas las pantallas seleccionadas.\r\n\r\nVISTA PREVIA Y CONTROLES\r\n"
            L"Activar vista previa inicia una vista previa a pantalla completa en todos los monitores; el "
            L"cuadro de configuración permanece abierto para realizar ajustes en tiempo real. Aceptar guarda "
            L"y Cancelar descarta. Esc o mover el ratón cierra el salvapantallas completo. Use Tab y "
            L"Mayús+Tab para desplazarse entre controles; Alt y la letra subrayada activan una opción. Esc "
            L"en la configuración equivale a Cancelar; en Ayuda o Acerca de, cierra únicamente esa ventana.\r"
            L"\n\r\nREQUISITOS DEL SISTEMA\r\nSe admiten Windows 7 a Windows 11. Para ejecutar la aplicación "
            L"en Windows Vista SP2, es necesario instalar las actualizaciones KB971512 y KB2117917. La "
            L"representación requiere Direct3D 11, no solo un entorno de ejecución antiguo de DirectX."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Plano" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Ondulación" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Embudo" },
    }),
    DefineLanguage(LANG_IT, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Italiano" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Controlli" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Impostazioni di SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Superficie ondulante infinita" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Volo a lunga distanza — superficie deformabile" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Volo nello spazio deformato dalla gravità" },
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
            L"La disinstallazione non è riuscita perché le impostazioni di SpaceFlight sono aperte. Chiudere "
            L"la finestra e riprovare."
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
            L"Volo con accelerazione hardware sopra superfici ondulanti e deformabili."
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
            L"ANIMAZIONE E IMPOSTAZIONI\r\nSpaceFlight: Superficie ondulante infinita; Volo a lunga distanza "
            L"— superficie deformabile; Volo nello spazio deformato dalla gravità. Assegnare una sola "
            L"animazione a ogni schermo. Texture alterna superfici con texture e modello a reticolo. La "
            L"rotazione libera della telecamera cambia lentamente la direzione dello sguardo nelle tre "
            L"dimensioni. L’opzione «Pause e inversioni» aggiunge rallentamenti, pause e inversioni casuali "
            L"della rotazione; il volo in avanti continua. La velocità va da 0 a 1600%. Ogni schermo ha una "
            L"scena casuale indipendente, renderizzata alla propria frequenza di aggiornamento. La luce "
            L"principale, la luce di riempimento, la luce ambientale e l’illuminazione dei contorni si "
            L"attivano separatamente per gli schermi selezionati. L’illuminazione si applica solo alle "
            L"superfici con texture. Le due animazioni di superfici offrono Piano, Ondulazione o Imbuto. "
            L"L’imbuto attira la telecamera verso l’interno lungo una spirale discendente. Il volo nello "
            L"spazio deformato dalla gravità mostra un reticolo tridimensionale a fil di ferro. Le opzioni "
            L"di texture, forma della superficie e illuminazione si applicano solo alle due animazioni di "
            L"superfici.\r\n\r\nMONITOR\r\nLa selezione delle righe determina quali schermi si stanno "
            L"configurando ed è distinta dalle caselle che attivano le uscite di animazione. Ctrl+A "
            L"seleziona tutti gli schermi; Ctrl e Maiusc modificano la selezione. Tutte le opzioni e i "
            L"cursori dell’animazione riguardano gli schermi selezionati. La selezione viene memorizzata "
            L"separatamente per EXE e SCR. Se erano selezionati tutti gli schermi, vengono inclusi anche "
            L"quelli nuovi. Valori diversi tra gli schermi selezionati sono indicati da caselle di controllo "
            L"indeterminate e da una trama a punti sui pulsanti di opzione, sulle maniglie dei cursori e sui "
            L"pulsanti «Attiva tutto» e «Disattiva tutto». Le etichette dei cursori mostrano un trattino al "
            L"posto di un valore comune. Modificare un’opzione o fare clic su un cursore applica quel valore "
            L"a tutti gli schermi selezionati.\r\n\r\nCOMANDI\r\nAttivate o disattivate le uscite di "
            L"animazione con le caselle degli schermi o facendo doppio clic sulle rispettive righe. Ogni "
            L"monitor usa una scena indipendente. Istantanea salva un PNG e il pulsante di registrazione "
            L"avvia o arresta un MP4. Pausa ferma l’animazione. L’applicazione installa o disinstalla anche "
            L"il salvaschermo incorporato. Le impostazioni vengono salvate continuamente. L’applicazione può "
            L"essere eseguita in una sola istanza. Un nuovo avvio ripristina la finestra di controllo "
            L"ridotta a icona e la porta in primo piano. Usare Tab e Maiusc+Tab per passare tra i controlli; "
            L"Alt e la lettera sottolineata attivano un comando. Esc chiude la finestra attiva di Guida o "
            L"Informazioni; nella finestra di controllo, termina l’applicazione. La pausa e il blocco del "
            L"salvaschermo si applicano all’intera applicazione, indipendentemente dagli schermi "
            L"selezionati. Quando il blocco è attivo, il salvaschermo di Windows viene impedito solo finché "
            L"almeno uno schermo mostra un’animazione visibile e non in pausa.\r\n\r\nISTANTANEE E "
            L"REGISTRAZIONE\r\nIstantanee e registrazioni usano il primo monitor di animazione attivo, non "
            L"un’immagine combinata di tutti i monitor. PNG usa Immagini, MP4 Video; se tali cartelle non "
            L"esistono, viene usata Documenti. Il pulsante Impostazioni video permette di scegliere Viewport "
            L"o TV. Viewport mantiene le dimensioni e la frequenza di aggiornamento del monitor di "
            L"animazione, fino a 60 fotogrammi al secondo. TV offre 1920 × 1080, 1440 × 1080 o 1280 × 720 in "
            L"formato 16:9, a 50, 25, 59.94 (60000/1001) o 29.97 (30000/1001) fotogrammi al secondo. Le "
            L"proporzioni sono mantenute; TV usa video progressivo BT.709 con intervallo limitato e "
            L"campionamento 4:2:0. Risoluzione e frequenza sono disponibili solo in modalità TV. La finestra "
            L"Impostazioni video può essere ridotta a icona e non blocca le altre finestre "
            L"dell’applicazione. OK salva le opzioni per la prossima registrazione MP4; Annulla o Esc scarta "
            L"le modifiche non confermate. L’uscita di animazione del monitor registrato non può essere "
            L"disattivata durante la registrazione; le modifiche agli altri monitor non la interrompono. "
            L"Chiudere l’applicazione durante una registrazione richiede conferma, perché interrompe anche "
            L"la registrazione.\r\n\r\nREQUISITI DI SISTEMA\r\nI sistemi da Windows 7 a Windows 11 "
            L"supportano tutte le funzioni, comprese le istantanee PNG e la registrazione MP4. Per eseguire "
            L"l’applicazione su Windows Vista SP2, è necessario installare gli aggiornamenti KB971512 e "
            L"KB2117917. La registrazione MP4 non funziona in Vista nella versione attuale. La "
            L"visualizzazione richiede Direct3D 11, non soltanto un vecchio runtime DirectX. La "
            L"registrazione MP4 richiede componenti Media Foundation e un codificatore H.264 disponibili."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMAZIONE E IMPOSTAZIONI\r\nSpaceFlight: Superficie ondulante infinita; Volo a lunga distanza "
            L"— superficie deformabile; Volo nello spazio deformato dalla gravità. Assegnare una sola "
            L"animazione a ogni schermo. Texture alterna superfici con texture e modello a reticolo. La "
            L"rotazione libera della telecamera cambia lentamente la direzione dello sguardo nelle tre "
            L"dimensioni. L’opzione «Pause e inversioni» aggiunge rallentamenti, pause e inversioni casuali "
            L"della rotazione; il volo in avanti continua. La velocità va da 0 a 1600%. Ogni schermo ha una "
            L"scena casuale indipendente, renderizzata alla propria frequenza di aggiornamento. La luce "
            L"principale, la luce di riempimento, la luce ambientale e l’illuminazione dei contorni si "
            L"attivano separatamente per gli schermi selezionati. L’illuminazione si applica solo alle "
            L"superfici con texture. Le due animazioni di superfici offrono Piano, Ondulazione o Imbuto. "
            L"L’imbuto attira la telecamera verso l’interno lungo una spirale discendente. Il volo nello "
            L"spazio deformato dalla gravità mostra un reticolo tridimensionale a fil di ferro. Le opzioni "
            L"di texture, forma della superficie e illuminazione si applicano solo alle due animazioni di "
            L"superfici.\r\n\r\nMONITOR\r\nLa selezione delle righe determina quali schermi si stanno "
            L"configurando ed è distinta dalle caselle che attivano le uscite di animazione. Ctrl+A "
            L"seleziona tutti gli schermi; Ctrl e Maiusc modificano la selezione. Tutte le opzioni e i "
            L"cursori dell’animazione riguardano gli schermi selezionati. La selezione viene memorizzata "
            L"separatamente per EXE e SCR. Se erano selezionati tutti gli schermi, vengono inclusi anche "
            L"quelli nuovi. Valori diversi tra gli schermi selezionati sono indicati da caselle di controllo "
            L"indeterminate e da una trama a punti sui pulsanti di opzione, sulle maniglie dei cursori e sui "
            L"pulsanti «Attiva tutto» e «Disattiva tutto». Le etichette dei cursori mostrano un trattino al "
            L"posto di un valore comune. Modificare un’opzione o fare clic su un cursore applica quel valore "
            L"a tutti gli schermi selezionati.\r\n\r\nANTEPRIMA E COMANDI\r\nAttiva anteprima avvia "
            L"un’anteprima a schermo intero su tutti i monitor; le impostazioni rimangono aperte per le "
            L"modifiche in tempo reale. OK salva e Annulla scarta. Esc o il movimento del mouse chiude il "
            L"salvaschermo a schermo intero. Usare Tab e Maiusc+Tab per passare tra i controlli; Alt e la "
            L"lettera sottolineata attivano un comando. Esc nelle impostazioni equivale ad Annulla; nella "
            L"Guida o nelle Informazioni, chiude solo quella finestra.\r\n\r\nREQUISITI DI SISTEMA\r\nSono "
            L"supportati i sistemi da Windows 7 a Windows 11. Per eseguire l’applicazione su Windows Vista "
            L"SP2, è necessario installare gli aggiornamenti KB971512 e KB2117917. La visualizzazione "
            L"richiede Direct3D 11, non soltanto un vecchio runtime DirectX."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Piano" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Ondulazione" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Imbuto" },
    }),
    DefineLanguage(LANG_PT, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Português" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Controlo" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Definições do SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Superfície ondulante infinita" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Voo de longa distância — superfície deformável" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Voo pelo espaço deformado pela gravidade" },
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
            L"A desinstalação falhou porque as definições do SpaceFlight estão abertas. Feche a janela e "
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
            L"Voo acelerado por hardware sobre superfícies ondulantes e deformáveis."
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
            L"ANIMAÇÃO E DEFINIÇÕES\r\nSpaceFlight: Superfície ondulante infinita; Voo de longa distância — "
            L"superfície deformável; Voo pelo espaço deformado pela gravidade. Atribua uma única animação a "
            L"cada ecrã. Textura alterna entre superfícies texturadas e modelo em arame. A rotação livre da "
            L"câmara muda lentamente a direção da vista nas três dimensões. A opção «Pausas e inversões» "
            L"acrescenta desacelerações, pausas e inversões aleatórias da rotação; o voo para a frente "
            L"continua. A velocidade vai de 0 a 1600%. Cada ecrã tem uma cena aleatória independente, "
            L"apresentada à sua própria frequência de atualização. A luz principal, a luz de preenchimento, "
            L"a luz ambiente e a iluminação dos contornos podem ser ativadas separadamente nos monitores "
            L"selecionados. A iluminação aplica-se apenas às superfícies com textura. As duas animações de "
            L"superfícies oferecem Plano, Ondulação ou Funil. O funil atrai a câmara para o interior ao "
            L"longo de uma espiral descendente. O voo pelo espaço deformado pela gravidade mostra uma grelha "
            L"tridimensional de linhas. As opções de textura, forma da superfície e iluminação aplicam-se "
            L"apenas às duas animações de superfícies.\r\n\r\nMONITORES\r\nA seleção das linhas determina os "
            L"ecrãs a configurar e é independente das caixas que ativam as saídas de animação. Ctrl+A "
            L"seleciona todos os ecrãs; Ctrl e Shift alteram a seleção. Todas as opções e controlos "
            L"deslizantes da animação aplicam-se aos ecrãs selecionados. A seleção é guardada separadamente "
            L"para EXE e SCR. Se todos estavam selecionados, os novos ecrãs também são incluídos. Valores "
            L"diferentes entre os ecrãs selecionados são indicados por caixas de verificação indeterminadas "
            L"e por um padrão pontilhado nos botões de opção, nas pegas dos controlos deslizantes e nos "
            L"botões «Ativar tudo» e «Desativar tudo». As etiquetas dos controlos deslizantes apresentam um "
            L"travessão em vez de um valor comum. Alterar uma opção ou clicar num controlo deslizante aplica "
            L"esse valor a todos os ecrãs selecionados.\r\n\r\nCONTROLOS\r\nAtive ou desative as saídas de "
            L"animação através das caixas dos ecrãs ou com um duplo clique nas respetivas linhas. Cada "
            L"monitor usa uma cena independente. Captura guarda PNG e o botão de gravação inicia ou termina "
            L"MP4. Pausa para a animação. A aplicação também instala ou desinstala a proteção de ecrã "
            L"incorporada. As definições são guardadas continuamente. A aplicação só pode ter uma instância "
            L"em execução. Um novo arranque restaura a janela de controlo minimizada e coloca-a em primeiro "
            L"plano. Use Tab e Shift+Tab para passar entre controlos; Alt e a letra sublinhada ativam um "
            L"comando. Esc fecha a janela ativa de Ajuda ou Acerca de; na janela de controlo, termina a "
            L"aplicação. A pausa e o bloqueio da proteção de ecrã aplicam-se a toda a aplicação, "
            L"independentemente dos ecrãs selecionados. Com o bloqueio ativo, a proteção de ecrã do Windows "
            L"só é impedida enquanto existir animação visível e não pausada em pelo menos um ecrã.\r\n\r\n"
            L"CAPTURAS E GRAVAÇÃO\r\nAs capturas e gravações usam o primeiro monitor de animação ativo, não "
            L"uma imagem conjunta de todos os monitores. PNG usa Imagens, MP4 Vídeos; se essas pastas não "
            L"existirem, usa-se Documentos. O botão Definições de gravação permite escolher Viewport ou TV. "
            L"Viewport conserva as dimensões e a frequência de atualização do monitor de animação, até 60 "
            L"fotogramas por segundo. TV oferece 1920 × 1080, 1440 × 1080 ou 1280 × 720 no formato 16:9, a "
            L"50, 25, 59.94 (60000/1001) ou 29.97 (30000/1001) fotogramas por segundo. A proporção da imagem "
            L"é mantida; TV usa vídeo progressivo BT.709 com intervalo limitado e amostragem 4:2:0. A "
            L"resolução e a frequência só estão disponíveis no modo TV. A janela Definições de gravação pode "
            L"ser minimizada e não bloqueia as outras janelas da aplicação. OK guarda as escolhas para a "
            L"próxima gravação MP4; Cancelar ou Esc descarta as alterações não confirmadas. A saída de "
            L"animação do monitor gravado não pode ser desativada durante a gravação; as alterações aos "
            L"outros monitores não a interrompem. Fechar a aplicação durante uma gravação exige confirmação, "
            L"pois também termina a gravação.\r\n\r\nREQUISITOS DO SISTEMA\r\nOs sistemas Windows 7 a "
            L"Windows 11 suportam todas as funcionalidades, incluindo capturas PNG e gravação MP4. Para "
            L"executar a aplicação no Windows Vista SP2, é necessário instalar as atualizações KB971512 e "
            L"KB2117917. A gravação MP4 não funciona no Vista na versão atual. A apresentação requer "
            L"Direct3D 11, não apenas um runtime DirectX mais antigo. A gravação MP4 requer componentes "
            L"Media Foundation e um codificador H.264 disponíveis."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMAÇÃO E DEFINIÇÕES\r\nSpaceFlight: Superfície ondulante infinita; Voo de longa distância — "
            L"superfície deformável; Voo pelo espaço deformado pela gravidade. Atribua uma única animação a "
            L"cada ecrã. Textura alterna entre superfícies texturadas e modelo em arame. A rotação livre da "
            L"câmara muda lentamente a direção da vista nas três dimensões. A opção «Pausas e inversões» "
            L"acrescenta desacelerações, pausas e inversões aleatórias da rotação; o voo para a frente "
            L"continua. A velocidade vai de 0 a 1600%. Cada ecrã tem uma cena aleatória independente, "
            L"apresentada à sua própria frequência de atualização. A luz principal, a luz de preenchimento, "
            L"a luz ambiente e a iluminação dos contornos podem ser ativadas separadamente nos monitores "
            L"selecionados. A iluminação aplica-se apenas às superfícies com textura. As duas animações de "
            L"superfícies oferecem Plano, Ondulação ou Funil. O funil atrai a câmara para o interior ao "
            L"longo de uma espiral descendente. O voo pelo espaço deformado pela gravidade mostra uma grelha "
            L"tridimensional de linhas. As opções de textura, forma da superfície e iluminação aplicam-se "
            L"apenas às duas animações de superfícies.\r\n\r\nMONITORES\r\nA seleção das linhas determina os "
            L"ecrãs a configurar e é independente das caixas que ativam as saídas de animação. Ctrl+A "
            L"seleciona todos os ecrãs; Ctrl e Shift alteram a seleção. Todas as opções e controlos "
            L"deslizantes da animação aplicam-se aos ecrãs selecionados. A seleção é guardada separadamente "
            L"para EXE e SCR. Se todos estavam selecionados, os novos ecrãs também são incluídos. Valores "
            L"diferentes entre os ecrãs selecionados são indicados por caixas de verificação indeterminadas "
            L"e por um padrão pontilhado nos botões de opção, nas pegas dos controlos deslizantes e nos "
            L"botões «Ativar tudo» e «Desativar tudo». As etiquetas dos controlos deslizantes apresentam um "
            L"travessão em vez de um valor comum. Alterar uma opção ou clicar num controlo deslizante aplica "
            L"esse valor a todos os ecrãs selecionados.\r\n\r\nPRÉ-VISUALIZAÇÃO E CONTROLOS\r\nAtivar "
            L"pré-visualização inicia uma pré-visualização em ecrã inteiro em todos os monitores e permite "
            L"ajustes em tempo real. OK guarda as definições e Cancelar descarta-as. Esc ou o movimento do "
            L"rato termina a proteção em ecrã inteiro. Use Tab e Shift+Tab para passar entre controlos; Alt "
            L"e a letra sublinhada ativam um comando. Esc nas definições equivale a Cancelar; na Ajuda ou em "
            L"Acerca de, fecha apenas essa janela.\r\n\r\nREQUISITOS DO SISTEMA\r\nSão suportados os "
            L"sistemas Windows 7 a Windows 11. Para executar a aplicação no Windows Vista SP2, é necessário "
            L"instalar as atualizações KB971512 e KB2117917. A apresentação requer Direct3D 11, não apenas "
            L"um runtime DirectX mais antigo."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Plano" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Ondulação" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Funil" },
    }),
    DefineLanguage(LANG_PL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Polski" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Sterowanie" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Ustawienia SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Nieskończona falująca powierzchnia" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Lot dalekodystansowy — zmienna powierzchnia" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT,
            L"Lot przez przestrzeń zakrzywioną grawitacyjnie"
        },
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
            L"Odinstalowanie nie powiodło się, ponieważ ustawienia SpaceFlight są otwarte. Zamknij okno i "
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
            L"Sprzętowo przyspieszany lot nad falującymi i zmiennymi powierzchniami."
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
            L"ANIMACJA I USTAWIENIA\r\nSpaceFlight: Nieskończona falująca powierzchnia; Lot dalekodystansowy "
            L"— zmienna powierzchnia; Lot przez przestrzeń zakrzywioną grawitacyjnie. Każdemu monitorowi "
            L"przypisz dokładnie jedną animację. Tekstura przełącza powierzchnie z teksturą i model "
            L"szkieletowy. Swobodne obracanie kamery powoli zmienia kierunek widoku we wszystkich trzech "
            L"wymiarach. Przerwy i nawroty dodają losowe zwalnianie, pauzy i odwracanie obrotu; lot do "
            L"przodu trwa nadal. Prędkość wynosi 0–1600%. Każdy monitor ma niezależną losową scenę "
            L"wyświetlaną z własną częstotliwością odświeżania. Światło główne, światło wypełniające, "
            L"światło otoczenia i oświetlenie konturów można przełączać niezależnie dla zaznaczonych "
            L"monitorów. Oświetlenie dotyczy tylko powierzchni z teksturą. Obie animacje powierzchni oferują "
            L"płaszczyznę, falowanie lub lej. Lej wciąga kamerę do środka po opadającej spirali. Lot przez "
            L"przestrzeń zakrzywioną grawitacyjnie przedstawia trójwymiarową siatkę szkieletową. Opcje "
            L"tekstury, kształtu powierzchni i oświetlenia dotyczą tylko dwóch animacji powierzchni.\r\n\r\n"
            L"MONITORY\r\nZaznaczenie wierszy określa konfigurowane monitory i jest niezależne od pól wyboru "
            L"włączających wyjścia animacji. Ctrl+A zaznacza wszystkie monitory; Ctrl i Shift zmieniają "
            L"zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą zaznaczonych monitorów. Zaznaczenie "
            L"jest zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były wszystkie monitory, nowe "
            L"również zostaną zaznaczone. Różne wartości na zaznaczonych monitorach są sygnalizowane "
            L"nieokreślonym stanem pól wyboru i kropkowaniem przycisków opcji, uchwytów suwaków oraz "
            L"przycisków „Włącz wszystko” i „Wyłącz wszystko”. Etykiety suwaków pokazują kreskę zamiast "
            L"wspólnej wartości. Zmiana opcji lub kliknięcie suwaka ustawia tę wartość na wszystkich "
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
            L"ANIMACJA I USTAWIENIA\r\nSpaceFlight: Nieskończona falująca powierzchnia; Lot dalekodystansowy "
            L"— zmienna powierzchnia; Lot przez przestrzeń zakrzywioną grawitacyjnie. Każdemu monitorowi "
            L"przypisz dokładnie jedną animację. Tekstura przełącza powierzchnie z teksturą i model "
            L"szkieletowy. Swobodne obracanie kamery powoli zmienia kierunek widoku we wszystkich trzech "
            L"wymiarach. Przerwy i nawroty dodają losowe zwalnianie, pauzy i odwracanie obrotu; lot do "
            L"przodu trwa nadal. Prędkość wynosi 0–1600%. Każdy monitor ma niezależną losową scenę "
            L"wyświetlaną z własną częstotliwością odświeżania. Światło główne, światło wypełniające, "
            L"światło otoczenia i oświetlenie konturów można przełączać niezależnie dla zaznaczonych "
            L"monitorów. Oświetlenie dotyczy tylko powierzchni z teksturą. Obie animacje powierzchni oferują "
            L"płaszczyznę, falowanie lub lej. Lej wciąga kamerę do środka po opadającej spirali. Lot przez "
            L"przestrzeń zakrzywioną grawitacyjnie przedstawia trójwymiarową siatkę szkieletową. Opcje "
            L"tekstury, kształtu powierzchni i oświetlenia dotyczą tylko dwóch animacji powierzchni.\r\n\r\n"
            L"MONITORY\r\nZaznaczenie wierszy określa konfigurowane monitory i jest niezależne od pól wyboru "
            L"włączających wyjścia animacji. Ctrl+A zaznacza wszystkie monitory; Ctrl i Shift zmieniają "
            L"zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą zaznaczonych monitorów. Zaznaczenie "
            L"jest zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były wszystkie monitory, nowe "
            L"również zostaną zaznaczone. Różne wartości na zaznaczonych monitorach są sygnalizowane "
            L"nieokreślonym stanem pól wyboru i kropkowaniem przycisków opcji, uchwytów suwaków oraz "
            L"przycisków „Włącz wszystko” i „Wyłącz wszystko”. Etykiety suwaków pokazują kreskę zamiast "
            L"wspólnej wartości. Zmiana opcji lub kliknięcie suwaka ustawia tę wartość na wszystkich "
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
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Płaszczyzna" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Falowanie" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Lej" },
    }),
    DefineLanguage(LANG_SK, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Slovenčina" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Ovládanie" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Nastavenia SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Nekonečná vlniaca sa plocha" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Diaľkový let — premenlivá plocha" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Prelet gravitačne deformovaným priestorom" },
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
            L"Odinštalovanie zlyhalo, pretože sú otvorené nastavenia SpaceFlight. Zatvorte ich a skúste to "
            L"znova."
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
            L"Hardvérovo akcelerovaný let nad vlniacimi sa a premenlivými plochami."
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
            L"ANIMÁCIA A NASTAVENIA\r\nSpaceFlight: Nekonečná vlniaca sa plocha; Diaľkový let — premenlivá "
            L"plocha; Prelet gravitačne deformovaným priestorom. Každému monitoru priraďte práve jednu "
            L"animáciu. Textúra prepína medzi textúrovanými plochami a drôteným modelom. Voľná rotácia "
            L"kamery pomaly mení smer pohľadu vo všetkých troch rozmeroch. Voľba „Pauzy a obraty“ pridáva "
            L"náhodné spomaľovanie, prestávky a zmeny smeru otáčania; dopredný pohyb pokračuje. Rýchlosť je "
            L"0–1600 %. Každý monitor má nezávislú náhodnú scénu vykresľovanú podľa vlastnej obnovovacej "
            L"frekvencie. Hlavné svetlo, doplnkové svetlo, základný jas a prisvetlenie obrysov možno pre "
            L"označené monitory zapínať nezávisle. Osvetlenie sa používa len pri textúrovaných plochách. Pri "
            L"oboch animáciách plôch možno zvoliť rovinu, vlnenie alebo lievik. Lievik vťahuje kameru "
            L"dovnútra po zostupnej špirále. Gravitačne deformovaný priestor sa zobrazuje trojrozmernou "
            L"drôtovou mriežkou. Textúra, tvar plochy a osvetlenie platia len pre obe animácie plôch.\r\n\r\n"
            L"MONITORY\r\nOznačenie riadkov určuje, ktoré monitory práve nastavujete; je nezávislé od "
            L"políčok zapínajúcich animačné výstupy. Ctrl+A označí všetky monitory, Ctrl a Shift upravujú "
            L"označenie. Všetky animačné voľby a posuvníky platia pre označené monitory. Označenie sa pamätá "
            L"zvlášť pre EXE a SCR. Ak boli označené všetky monitory, označia sa aj novopripojené. Rozdielne "
            L"hodnoty na označených monitoroch ukazuje neurčitý stav políčok a bodkovanie prepínačov, "
            L"úchytov posuvníkov a tlačidiel „Všetko zapnúť“ a „Všetko vypnúť“. Popis posuvníka namiesto "
            L"spoločnej hodnoty zobrazuje pomlčku. Zmena voľby alebo kliknutie na posuvník zjednotí "
            L"príslušnú hodnotu na označených monitoroch.\r\n\r\nOVLÁDANIE\r\nAnimačné výstupy zapnete alebo "
            L"vypnete políčkami pri monitoroch alebo dvojklikom na ich riadky. Každý monitor používa "
            L"nezávislú scénu. Snímka uloží PNG a tlačidlo záznamu spustí alebo ukončí MP4. Pozastavenie "
            L"zastaví animáciu. Aplikácia tiež nainštaluje alebo odinštaluje vložený šetrič. Nastavenia sa "
            L"ukladajú priebežne. Aplikácia beží iba v jednej inštancii. Ďalšie spustenie obnoví "
            L"minimalizované ovládacie okno a prenesie ho do popredia. Medzi ovládacími prvkami prechádzajte "
            L"klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a príslušného písmena. Esc "
            L"zavrie aktívne okno Pomoc alebo O aplikácii; v ovládacom okne ukončí aplikáciu. Pozastavenie a "
            L"blokovanie šetriča platia pre celú aplikáciu bez ohľadu na označené monitory. Ak je blokovanie "
            L"zapnuté, bráni spusteniu šetriča Windows iba vtedy, keď je aspoň na jednom monitore viditeľná "
            L"nepozastavená animácia.\r\n\r\nSNÍMKY A ZÁZNAM\r\nSnímky a záznamy zachytávajú prvý aktívny "
            L"animačný monitor, nie spoločnú plochu všetkých monitorov. PNG používa Obrázky, MP4 Videá; ak "
            L"tieto priečinky neexistujú, použijú sa Dokumenty. Tlačidlo Nastavenie záznamu vyberá Viewport "
            L"alebo TV. Viewport zachováva rozmery animačného monitora a jeho obnovovaciu frekvenciu, "
            L"najviac 60 snímok za sekundu. TV ponúka rozlíšenie 1920 × 1080, 1440 × 1080 alebo 1280 × 720 v "
            L"pomere 16:9 a frekvenciu 50, 25, 59.94 (60000/1001) alebo 29.97 (30000/1001) snímok za "
            L"sekundu. Obraz zachováva pomer strán; TV používa progresívne video BT.709 s obmedzeným "
            L"rozsahom a vzorkovaním 4:2:0. Rozlíšenie a snímkovú frekvenciu možno vybrať iba v režime TV. "
            L"Okno Nastavenie záznamu možno minimalizovať a neblokuje ostatné okná aplikácie. OK uloží voľby "
            L"pre nasledujúci záznam MP4; Zrušiť alebo Esc zahodí nepotvrdené zmeny. Animačný výstup "
            L"nahrávaného monitora nemožno počas záznamu vypnúť; zmeny ostatných monitorov záznam "
            L"nezastavia. Ukončenie aplikácie počas záznamu vyžaduje potvrdenie, pretože ukončí aj záznam.\r"
            L"\n\r\nSYSTÉMOVÉ POŽIADAVKY\r\nWindows 7 až Windows 11 podporujú všetky funkcie vrátane snímok "
            L"PNG a záznamu MP4. Na spustenie aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať "
            L"aktualizácie KB971512 a KB2117917. Záznam MP4 na Viste v súčasnej verzii nefunguje. "
            L"Vykresľovanie vyžaduje Direct3D 11, nie iba starší DirectX runtime. Záznam MP4 vyžaduje "
            L"dostupné súčasti Media Foundation a kodér H.264."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMÁCIA A NASTAVENIA\r\nSpaceFlight: Nekonečná vlniaca sa plocha; Diaľkový let — premenlivá "
            L"plocha; Prelet gravitačne deformovaným priestorom. Každému monitoru priraďte práve jednu "
            L"animáciu. Textúra prepína medzi textúrovanými plochami a drôteným modelom. Voľná rotácia "
            L"kamery pomaly mení smer pohľadu vo všetkých troch rozmeroch. Voľba „Pauzy a obraty“ pridáva "
            L"náhodné spomaľovanie, prestávky a zmeny smeru otáčania; dopredný pohyb pokračuje. Rýchlosť je "
            L"0–1600 %. Každý monitor má nezávislú náhodnú scénu vykresľovanú podľa vlastnej obnovovacej "
            L"frekvencie. Hlavné svetlo, doplnkové svetlo, základný jas a prisvetlenie obrysov možno pre "
            L"označené monitory zapínať nezávisle. Osvetlenie sa používa len pri textúrovaných plochách. Pri "
            L"oboch animáciách plôch možno zvoliť rovinu, vlnenie alebo lievik. Lievik vťahuje kameru "
            L"dovnútra po zostupnej špirále. Gravitačne deformovaný priestor sa zobrazuje trojrozmernou "
            L"drôtovou mriežkou. Textúra, tvar plochy a osvetlenie platia len pre obe animácie plôch.\r\n\r\n"
            L"MONITORY\r\nOznačenie riadkov určuje, ktoré monitory práve nastavujete; je nezávislé od "
            L"políčok zapínajúcich animačné výstupy. Ctrl+A označí všetky monitory, Ctrl a Shift upravujú "
            L"označenie. Všetky animačné voľby a posuvníky platia pre označené monitory. Označenie sa pamätá "
            L"zvlášť pre EXE a SCR. Ak boli označené všetky monitory, označia sa aj novopripojené. Rozdielne "
            L"hodnoty na označených monitoroch ukazuje neurčitý stav políčok a bodkovanie prepínačov, "
            L"úchytov posuvníkov a tlačidiel „Všetko zapnúť“ a „Všetko vypnúť“. Popis posuvníka namiesto "
            L"spoločnej hodnoty zobrazuje pomlčku. Zmena voľby alebo kliknutie na posuvník zjednotí "
            L"príslušnú hodnotu na označených monitoroch.\r\n\r\nNÁHĽAD A OVLÁDANIE\r\nZapnúť náhľad spustí "
            L"celoobrazovkový náhľad na všetkých monitoroch; nastavenia zostávajú otvorené a zmeny sa "
            L"prejavia ihneď. OK uloží nastavenia a Zrušiť ich zahodí. Celoobrazovkový šetrič ukončí Esc "
            L"alebo pohyb myši. Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté "
            L"voľby vyvoláte pomocou Alt a príslušného písmena. Esc v nastaveniach zodpovedá tlačidlu "
            L"Zrušiť; v okne Pomoc alebo O aplikácii zavrie iba toto okno.\r\n\r\nSYSTÉMOVÉ POŽIADAVKY\r\n"
            L"Podporované sú systémy Windows 7 až Windows 11. Na spustenie aplikácie v systéme Windows Vista "
            L"SP2 je potrebné nainštalovať aktualizácie KB971512 a KB2117917. Vykresľovanie vyžaduje "
            L"Direct3D 11, nie iba starší DirectX runtime."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Rovina" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Vlnenie" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Lievik" },
    }),
    DefineLanguage(LANG_DA, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Dansk" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Styring" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Indstillinger for SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Uendelig bølgende flade" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Langdistanceflyvetur — formskiftende flade" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT,
            L"Flyvetur gennem gravitationelt krummet rum"
        },
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
            L"Afinstallationen mislykkedes, fordi indstillingerne for SpaceFlight er åbne. Luk vinduet, og "
            L"prøv igen."
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
            L"Hardwareaccelereret flyvetur over bølgende og formskiftende flader."
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
            L"ANIMATION OG INDSTILLINGER\r\nSpaceFlight: Uendelig bølgende flade; Langdistanceflyvetur — "
            L"formskiftende flade; Flyvetur gennem gravitationelt krummet rum. Tildel præcis én animation "
            L"til hver skærm. Tekstur skifter mellem teksturerede flader og trådmodel. Frit roterende kamera "
            L"ændrer langsomt synsretningen i alle tre dimensioner. Pauser og vendinger tilføjer tilfældige "
            L"opbremsninger, pauser og ændringer af rotationsretningen; flyvningen fremad fortsætter. "
            L"Hastigheden er 0–1600 %. Hver skærm har en uafhængig tilfældig scene, der gengives med dens "
            L"egen opdateringsfrekvens. Hovedlys, udfyldningslys, omgivende lys og konturlys kan slås til og "
            L"fra uafhængigt for de valgte skærme. Belysningen gælder kun teksturerede overflader. De to "
            L"overfladeanimationer tilbyder Plan, Bølger eller Tragt. Tragten trækker kameraet indad langs "
            L"en nedadgående spiral. Flyveturen gennem gravitationelt krummet rum viser et tredimensionalt "
            L"trådgitter. Indstillingerne for tekstur, overfladeform og belysning gælder kun de to "
            L"overfladeanimationer.\r\n\r\nSKÆRME\r\nMarkeringen af rækker bestemmer, hvilke skærme du "
            L"indstiller, og er adskilt fra afkrydsningsfelterne, der aktiverer animationsoutput. Ctrl+A "
            L"markerer alle skærme; Ctrl og Skift ændrer markeringen. Alle animationsvalg og skydere gælder "
            L"de markerede skærme. Markeringen huskes separat for EXE og SCR. Hvis alle skærme var markeret, "
            L"medtages også nye skærme. Forskellige værdier på de markerede skærme vises med ubestemte "
            L"afkrydsningsfelter og prikmønstre på alternativknapper, skydergreb og knapperne “Aktivér alle” "
            L"og “Deaktivér alle”. Skydernes etiketter viser en tankestreg i stedet for en fælles værdi. "
            L"Ændring af et valg eller klik på en skyder anvender denne værdi på alle markerede skærme.\r\n\r"
            L"\nBETJENING\r\nSlå animationsoutput til eller fra med skærmenes afkrydsningsfelter eller ved "
            L"at dobbeltklikke på deres rækker. Hver skærm bruger en uafhængig scene. Skærmbillede gemmer "
            L"PNG, og optageknappen starter eller stopper MP4. Pause standser animationen. Programmet "
            L"installerer eller afinstallerer også den indbyggede pauseskærm. Indstillinger gemmes løbende. "
            L"Programmet kan kun køre i én instans ad gangen. En ny start gendanner det minimerede "
            L"kontrolvindue og bringer det forrest. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; "
            L"Alt og det understregede bogstav aktiverer en kommando. Esc lukker det aktive Hjælp- eller "
            L"Om-vindue; i kontrolvinduet afslutter det programmet. Pause og blokering af pauseskærmen "
            L"gælder hele programmet uanset skærmmarkeringen. Når blokering er slået til, forhindres "
            L"Windows-pauseskærmen kun, mens der vises en synlig animation, som ikke er sat på pause, på "
            L"mindst én skærm.\r\n\r\nSKÆRMBILLEDER OG OPTAGELSE\r\nSkærmbilleder og optagelser bruger den "
            L"første aktive animationsskærm, ikke et samlet billede af alle skærme. PNG bruger Billeder, MP4 "
            L"Videoer; hvis disse mapper ikke findes, bruges Dokumenter. Knappen Optagelsesindstillinger "
            L"vælger Viewport eller TV. Viewport bevarer animationsskærmens størrelse og "
            L"opdateringsfrekvens, højst 60 billeder i sekundet. TV tilbyder 1920 × 1080, 1440 × 1080 eller "
            L"1280 × 720 i formatet 16:9 med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) billeder i "
            L"sekundet. Billedets proportioner bevares; TV bruger progressiv BT.709-video med begrænset "
            L"område og 4:2:0-sampling. Opløsning og billedfrekvens kan kun vælges i TV-tilstand. Vinduet "
            L"Optagelsesindstillinger kan minimeres og blokerer ikke de andre programvinduer. OK gemmer "
            L"valgene til den næste MP4-optagelse; Annuller eller Esc kasserer ubekræftede ændringer. "
            L"Animationsoutputtet på den skærm, der optages, kan ikke slås fra under optagelsen; ændringer "
            L"af andre skærme stopper ikke optagelsen. Hvis programmet lukkes under en optagelse, kræves en "
            L"bekræftelse, fordi optagelsen også afsluttes.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 "
            L"understøtter alle funktioner, herunder PNG-skærmbilleder og MP4-optagelse. For at køre "
            L"programmet på Windows Vista SP2 skal opdateringerne KB971512 og KB2117917 installeres. "
            L"MP4-optagelse fungerer ikke på Vista i den aktuelle version. Visningen kræver Direct3D 11, "
            L"ikke kun et ældre DirectX-kørselsmiljø. MP4-optagelse kræver tilgængelige Media "
            L"Foundation-komponenter og en H.264-koder."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATION OG INDSTILLINGER\r\nSpaceFlight: Uendelig bølgende flade; Langdistanceflyvetur — "
            L"formskiftende flade; Flyvetur gennem gravitationelt krummet rum. Tildel præcis én animation "
            L"til hver skærm. Tekstur skifter mellem teksturerede flader og trådmodel. Frit roterende kamera "
            L"ændrer langsomt synsretningen i alle tre dimensioner. Pauser og vendinger tilføjer tilfældige "
            L"opbremsninger, pauser og ændringer af rotationsretningen; flyvningen fremad fortsætter. "
            L"Hastigheden er 0–1600 %. Hver skærm har en uafhængig tilfældig scene, der gengives med dens "
            L"egen opdateringsfrekvens. Hovedlys, udfyldningslys, omgivende lys og konturlys kan slås til og "
            L"fra uafhængigt for de valgte skærme. Belysningen gælder kun teksturerede overflader. De to "
            L"overfladeanimationer tilbyder Plan, Bølger eller Tragt. Tragten trækker kameraet indad langs "
            L"en nedadgående spiral. Flyveturen gennem gravitationelt krummet rum viser et tredimensionalt "
            L"trådgitter. Indstillingerne for tekstur, overfladeform og belysning gælder kun de to "
            L"overfladeanimationer.\r\n\r\nSKÆRME\r\nMarkeringen af rækker bestemmer, hvilke skærme du "
            L"indstiller, og er adskilt fra afkrydsningsfelterne, der aktiverer animationsoutput. Ctrl+A "
            L"markerer alle skærme; Ctrl og Skift ændrer markeringen. Alle animationsvalg og skydere gælder "
            L"de markerede skærme. Markeringen huskes separat for EXE og SCR. Hvis alle skærme var markeret, "
            L"medtages også nye skærme. Forskellige værdier på de markerede skærme vises med ubestemte "
            L"afkrydsningsfelter og prikmønstre på alternativknapper, skydergreb og knapperne “Aktivér alle” "
            L"og “Deaktivér alle”. Skydernes etiketter viser en tankestreg i stedet for en fælles værdi. "
            L"Ændring af et valg eller klik på en skyder anvender denne værdi på alle markerede skærme.\r\n\r"
            L"\nFORHÅNDSVISNING OG BETJENING\r\nAktivér forhåndsvisning starter en fuldskærmsvisning på alle "
            L"skærme. Indstillingerne forbliver åbne, og ændringerne vises med det samme. OK gemmer "
            L"indstillingerne, og Annuller forkaster ændringerne. Esc eller musebevægelse afslutter "
            L"fuldskærmen. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det understregede "
            L"bogstav aktiverer en kommando. Esc i indstillingerne svarer til Annuller; i Hjælp eller Om "
            L"lukker det kun dette vindue.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 understøttes. For "
            L"at køre programmet på Windows Vista SP2 skal opdateringerne KB971512 og KB2117917 installeres. "
            L"Visningen kræver Direct3D 11, ikke kun et ældre DirectX-kørselsmiljø."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Plan" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Bølger" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Tragt" },
    }),
    DefineLanguage(LANG_FI, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Suomi" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Ohjaus" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"SpaceFlight-asetukset" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Ääretön aaltoileva pinta" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Pitkän matkan lento — muuntuva pinta" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT,
            L"Lento painovoiman kaareuttamassa avaruudessa"
        },
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
            L"Asennuksen poisto epäonnistui, koska SpaceFlight-asetukset ovat avoinna. Sulje ikkuna ja yritä "
            L"uudelleen."
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
            L"Laitteistokiihdytetty lento aaltoilevien ja muuntuvien pintojen yllä."
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
            L"ANIMAATIO JA ASETUKSET\r\nSpaceFlight: Ääretön aaltoileva pinta; Pitkän matkan lento — "
            L"muuntuva pinta; Lento painovoiman kaareuttamassa avaruudessa. Valitse kullekin näytölle yksi "
            L"animaatio. Tekstuuri vaihtaa teksturoitujen pintojen ja rautalankamallin välillä. Kameran "
            L"vapaa pyörintä muuttaa katselusuuntaa hitaasti kaikissa kolmessa ulottuvuudessa. Tauot ja "
            L"suunnanvaihdot lisäävät satunnaisia hidastuksia, taukoja ja pyörimissuunnan vaihtoja; lento "
            L"eteenpäin jatkuu. Nopeus on 0–1600%. Jokaisella näytöllä on itsenäinen satunnainen näkymä, "
            L"joka piirretään sen omalla virkistystaajuudella. Päävalo, täytevalo, ympäristövalo ja "
            L"reunavalo voidaan kytkeä erikseen valituille näytöille. Valaistus koskee vain teksturoituja "
            L"pintoja. Molemmissa pinta-animaatioissa voi valita tason, aallot tai suppilon. Suppilo vetää "
            L"kameran sisään alaspäin kiertyvää spiraalia pitkin. Lento painovoiman kaareuttamassa "
            L"avaruudessa näyttää kolmiulotteisen rautalankaruudukon. Tekstuurin, pinnan muodon ja "
            L"valaistuksen asetukset koskevat vain kahta pinta-animaatiota.\r\n\r\nNÄYTÖT\r\nRivien valinta "
            L"määrää muokattavat näytöt ja on erillinen animaatioulostulon valintaruuduista. Ctrl+A valitsee "
            L"kaikki näytöt; Ctrl ja Vaihto muuttavat valintaa. Kaikki animaatioasetukset ja liukusäätimet "
            L"koskevat valittuja näyttöjä. Valinta muistetaan erikseen EXE- ja SCR-tiloissa. Jos kaikki "
            L"näytöt olivat valittuina, myös uudet näytöt valitaan. Valittujen näyttöjen eri arvot "
            L"ilmaistaan valintaruutujen määrittämättömällä tilalla sekä valintanappien, liukusäätimien "
            L"kahvojen ja painikkeiden ”Ota kaikki käyttöön” ja ”Poista kaikki käytöstä” pistekuviolla. "
            L"Liukusäätimen selitteessä näkyy viiva yhteisen arvon sijasta. Asetuksen muuttaminen tai "
            L"liukusäätimen napsauttaminen asettaa kyseisen arvon kaikille valituille näytöille.\r\n\r\n"
            L"KÄYTTÖ\r\nAnimaatioulostulot voi ottaa käyttöön tai poistaa käytöstä näyttöjen "
            L"valintaruuduilla tai kaksoisnapsauttamalla niiden rivejä. Jokaisella näytöllä on itsenäinen "
            L"näkymä. Tilannekuva tallentaa PNG:n ja tallennuspainike käynnistää tai lopettaa MP4:n. "
            L"Keskeytä pysäyttää animaation. Sovellus asentaa tai poistaa myös sisäisen näytönsäästäjän. "
            L"Asetukset tallennetaan jatkuvasti. Sovelluksesta voi olla käynnissä vain yksi instanssi. Uusi "
            L"käynnistys palauttaa pienennetyn ohjausikkunan ja tuo sen etualalle. Siirry säätimien välillä "
            L"Tab- ja Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat komennon. Esc sulkee "
            L"aktiivisen Ohje- tai Tietoja-ikkunan; ohjausikkunassa se sulkee sovelluksen. Keskeytys ja "
            L"näytönsäästäjän esto koskevat koko sovellusta näytön valinnasta riippumatta. Kun esto on "
            L"käytössä, Windowsin näytönsäästäjä estetään vain, kun vähintään yhdessä näytössä näkyy "
            L"animaatio, jota ei ole keskeytetty.\r\n\r\nKUVAKAAPPAUKSET JA TALLENNUS\r\nTilannekuvat ja "
            L"tallenteet käyttävät ensimmäistä aktiivista animaationäyttöä, eivät kaikkien näyttöjen "
            L"yhdistettyä kuvaa. PNG käyttää Kuvat-kansiota ja MP4 Videot-kansiota; jos niitä ei ole, "
            L"käytetään Tiedostot-kansiota. Tallennusasetukset-painikkeella valitaan Viewport tai TV. "
            L"Viewport säilyttää animaationäytön koon ja virkistystaajuuden, enintään 60 kuvaa sekunnissa. "
            L"TV tarjoaa tarkkuudet 1920 × 1080, 1440 × 1080 ja 1280 × 720 kuvasuhteella 16:9 sekä taajuudet "
            L"50, 25, 59.94 (60000/1001) ja 29.97 (30000/1001) kuvaa sekunnissa. Kuvasuhde säilyy; TV "
            L"käyttää progressiivista BT.709-videota rajatulla alueella ja 4:2:0-näytteistyksellä. Tarkkuus "
            L"ja kuvataajuus ovat valittavissa vain TV-tilassa. Tallennusasetukset-ikkunan voi pienentää, "
            L"eikä se estä muiden sovellusikkunoiden käyttöä. OK tallentaa valinnat seuraavaa "
            L"MP4-tallennusta varten; Peruuta tai Esc hylkää vahvistamattomat muutokset. Tallennettavan "
            L"näytön animaatioulostuloa ei voi poistaa käytöstä tallennuksen aikana; muiden näyttöjen "
            L"muutokset eivät pysäytä tallennusta. Sovelluksen sulkeminen tallennuksen aikana vaatii "
            L"vahvistuksen, sillä myös tallennus päättyy.\r\n\r\nJÄRJESTELMÄVAATIMUKSET\r\nWindows 7–Windows "
            L"11 tukevat kaikkia toimintoja, myös PNG-tilannekuvia ja MP4-tallennusta. Sovelluksen "
            L"suorittaminen Windows Vista SP2:ssa edellyttää päivitysten KB971512 ja KB2117917 asentamista. "
            L"MP4-tallennus ei toimi Vistassa nykyisessä versiossa. Näyttäminen vaatii Direct3D 11:n, ei "
            L"pelkästään vanhempaa DirectX-ajoympäristöä. MP4-tallennus vaatii käytettävissä olevat Media "
            L"Foundation -komponentit ja H.264-enkooderin."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMAATIO JA ASETUKSET\r\nSpaceFlight: Ääretön aaltoileva pinta; Pitkän matkan lento — "
            L"muuntuva pinta; Lento painovoiman kaareuttamassa avaruudessa. Valitse kullekin näytölle yksi "
            L"animaatio. Tekstuuri vaihtaa teksturoitujen pintojen ja rautalankamallin välillä. Kameran "
            L"vapaa pyörintä muuttaa katselusuuntaa hitaasti kaikissa kolmessa ulottuvuudessa. Tauot ja "
            L"suunnanvaihdot lisäävät satunnaisia hidastuksia, taukoja ja pyörimissuunnan vaihtoja; lento "
            L"eteenpäin jatkuu. Nopeus on 0–1600%. Jokaisella näytöllä on itsenäinen satunnainen näkymä, "
            L"joka piirretään sen omalla virkistystaajuudella. Päävalo, täytevalo, ympäristövalo ja "
            L"reunavalo voidaan kytkeä erikseen valituille näytöille. Valaistus koskee vain teksturoituja "
            L"pintoja. Molemmissa pinta-animaatioissa voi valita tason, aallot tai suppilon. Suppilo vetää "
            L"kameran sisään alaspäin kiertyvää spiraalia pitkin. Lento painovoiman kaareuttamassa "
            L"avaruudessa näyttää kolmiulotteisen rautalankaruudukon. Tekstuurin, pinnan muodon ja "
            L"valaistuksen asetukset koskevat vain kahta pinta-animaatiota.\r\n\r\nNÄYTÖT\r\nRivien valinta "
            L"määrää muokattavat näytöt ja on erillinen animaatioulostulon valintaruuduista. Ctrl+A valitsee "
            L"kaikki näytöt; Ctrl ja Vaihto muuttavat valintaa. Kaikki animaatioasetukset ja liukusäätimet "
            L"koskevat valittuja näyttöjä. Valinta muistetaan erikseen EXE- ja SCR-tiloissa. Jos kaikki "
            L"näytöt olivat valittuina, myös uudet näytöt valitaan. Valittujen näyttöjen eri arvot "
            L"ilmaistaan valintaruutujen määrittämättömällä tilalla sekä valintanappien, liukusäätimien "
            L"kahvojen ja painikkeiden ”Ota kaikki käyttöön” ja ”Poista kaikki käytöstä” pistekuviolla. "
            L"Liukusäätimen selitteessä näkyy viiva yhteisen arvon sijasta. Asetuksen muuttaminen tai "
            L"liukusäätimen napsauttaminen asettaa kyseisen arvon kaikille valituille näytöille.\r\n\r\n"
            L"ESIKATSELU JA KÄYTTÖ\r\nOta esikatselu käyttöön käynnistää koko näytön esikatselun kaikilla "
            L"näytöillä. Asetusikkuna pysyy avoinna, ja muutokset näkyvät heti. OK tallentaa asetukset ja "
            L"Peruuta hylkää muutokset. Esc tai hiiren liike lopettaa koko näytön säästäjän. Siirry "
            L"säätimien välillä Tab- ja Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat "
            L"komennon. Esc asetuksissa vastaa Peruuta-painiketta; Ohje- tai Tietoja-ikkunassa se sulkee "
            L"vain kyseisen ikkunan.\r\n\r\nJÄRJESTELMÄVAATIMUKSET\r\nTuettuja käyttöjärjestelmiä ovat "
            L"Windows 7–Windows 11. Sovelluksen suorittaminen Windows Vista SP2:ssa edellyttää päivitysten "
            L"KB971512 ja KB2117917 asentamista. Näyttäminen vaatii Direct3D 11:n, ei pelkästään vanhempaa "
            L"DirectX-ajoympäristöä."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Taso" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Aallot" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Suppilo" },
    }),
    DefineLanguage(LANG_IS, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Íslenska" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Stjórnun" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Stillingar SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Óendanlegur bylgjandi flötur" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Langflug — breytilegur flötur" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Flug um rúm sveigt af þyngdarafli" },
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
            L"Fjarlæging mistókst vegna þess að stillingar SpaceFlight eru opnar. Lokaðu glugganum og reyndu "
            L"aftur."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Fjarlæging mistókst vegna þess að kerfisforskoðun er í gangi. Lokaðu stillingaglugga skjáhvílu "
            L"og reyndu aftur."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Fjarlæging mistókst vegna þess að skjáhvílan eða forskoðun á öllum skjánum er í gangi. Lokaðu "
            L"með Esc eða með því að hreyfa músina og reyndu aftur."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Vélbúnaðarhraðað flug yfir bylgjandi og breytilega fleti." },
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
            L"HREYFIMYND OG STILLINGAR\r\nSpaceFlight: Óendanlegur bylgjandi flötur; Langflug — breytilegur "
            L"flötur; Flug um rúm sveigt af þyngdarafli. Veldu nákvæmlega eina hreyfimynd fyrir hvern skjá. "
            L"Áferð skiptir milli áferðarlagðra flata og víragrindar. Frjáls snúningur myndavélar breytir "
            L"sjónstefnunni hægt í öllum þremur víddum. Valkosturinn „Hlé og stefnuskipti“ bætir við "
            L"tilviljanakenndri hægingu, hléum og breytingum á snúningsstefnu; flug áfram heldur áfram. "
            L"Hraðinn er 0–1600%. Hver skjár hefur sjálfstæða tilviljanakennda senu sem er teiknuð á eigin "
            L"endurnýjunartíðni. Aðalljós, fylliljós, umhverfislýsing og útlínulýsing eru stillt óháð hvert "
            L"öðru fyrir valda skjái. Lýsingin á aðeins við um áferðarfleti. Í báðum hreyfimyndunum með "
            L"flötum má velja sléttu, bylgjur eða trekt. Trektin dregur myndavélina inn eftir spíral sem "
            L"liggur niður á við. Flug um rúm sem þyngdaraflið sveigir sýnir þrívítt víragrindarnet. Áferð, "
            L"lögun flatar og lýsing eiga aðeins við um hreyfimyndirnar tvær með flötum.\r\n\r\nSKJÁIR\r\n"
            L"Val lína ákvarðar hvaða skjám er verið að breyta og er óháð gátreitunum sem kveikja á "
            L"hreyfimyndaúttaki. Ctrl+A velur alla skjái; Ctrl og Shift breyta valinu. Allir valkostir og "
            L"sleðar hreyfimynda gilda fyrir valda skjái. Valið er munað sérstaklega fyrir EXE og SCR. Ef "
            L"allir skjáir voru valdir bætast nýir skjáir einnig við valið. Mismunandi gildi á völdum skjám "
            L"eru sýnd með óákveðnu ástandi gátreita og punktamynstri á valhnöppum, handföngum sleða og "
            L"hnöppunum „Virkja allt“ og „Óvirkja allt“. Merking sleða sýnir strik í stað sameiginlegs "
            L"gildis. Að breyta valkosti eða smella á sleða setur það gildi á alla valda skjái.\r\n\r\n"
            L"NOTKUN\r\nKveiktu eða slökktu á hreyfimyndaúttaki með gátreitum skjáanna eða með því að "
            L"tvísmella á línur þeirra. Hver skjár notar sjálfstæða senu. Skjámynd vistar PNG og "
            L"upptökuhnappurinn ræsir eða stöðvar MP4. Hnappurinn Gera hlé stöðvar hreyfimyndina. Forritið "
            L"setur einnig upp eða fjarlægir innbyggðu skjáhvíluna. Stillingar vistast jafnóðum. Aðeins eitt "
            L"eintak af forritinu getur verið í gangi í einu. Ný ræsing endurheimtir lágmarkaða "
            L"stjórngluggann og færir hann fremst. Notaðu Tab og Shift+Tab til að færa þig milli "
            L"stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc lokar virka Hjálp- eða "
            L"Um-glugganum; í stjórnglugganum lokar það forritinu. Pása og hindrun skjáhvílu gilda fyrir "
            L"allt forritið, óháð völdum skjám. Þegar hindrun er virk er skjáhvíla Windows aðeins hindruð "
            L"meðan sýnileg hreyfimynd sem er ekki í pásu er á að minnsta kosti einum skjá.\r\n\r\n"
            L"SKJÁMYNDIR OG UPPTAKA\r\nSkjámyndir og upptökur nota fyrsta virka hreyfimyndaskjáinn, ekki "
            L"sameinaða mynd af öllum skjám. PNG notar Myndir, MP4 Myndbönd; ef þær möppur eru ekki til er "
            L"Skjöl notuð. Hnappurinn Upptökustillingar velur Viewport eða TV. Viewport varðveitir stærð og "
            L"endurnýjunartíðni hreyfimyndaskjásins, þó mest 60 ramma á sekúndu. TV býður upp á 1920 × 1080, "
            L"1440 × 1080 eða 1280 × 720 í hlutfallinu 16:9 með 50, 25, 59.94 (60000/1001) eða 29.97 "
            L"(30000/1001) römmum á sekúndu. Hlutföll myndarinnar haldast; TV notar BT.709-myndband án "
            L"fléttunar (progressive) með takmörkuðu sviði og 4:2:0-sýnatöku. Upplausn og rammatíðni eru "
            L"aðeins valanleg í TV-ham. Hægt er að lágmarka gluggann Upptökustillingar og hann hindrar ekki "
            L"notkun annarra glugga forritsins. Í lagi vistar valið fyrir næstu MP4-upptöku; Hætta við eða "
            L"Esc hendir óstaðfestum breytingum. Ekki er hægt að slökkva á hreyfimyndaúttaki skjásins sem er "
            L"tekinn upp meðan upptaka stendur yfir; breytingar á öðrum skjám stöðva ekki upptökuna. "
            L"Staðfesta þarf lokun forritsins meðan upptaka stendur yfir, því hún stöðvar líka upptökuna.\r\n"
            L"\r\nKERFISKRÖFUR\r\nWindows 7 til Windows 11 styðja alla eiginleika, þar á meðal "
            L"PNG-skjámyndir og MP4-upptöku. Til að keyra forritið á Windows Vista SP2 þarf að setja upp "
            L"uppfærslurnar KB971512 og KB2117917. MP4-upptaka virkar ekki í Vista í núverandi útgáfu. "
            L"Birting krefst Direct3D 11, ekki aðeins eldri DirectX-keyrsluumhverfis. MP4-upptaka krefst "
            L"tiltækra Media Foundation-íhluta og H.264-kóðara."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"HREYFIMYND OG STILLINGAR\r\nSpaceFlight: Óendanlegur bylgjandi flötur; Langflug — breytilegur "
            L"flötur; Flug um rúm sveigt af þyngdarafli. Veldu nákvæmlega eina hreyfimynd fyrir hvern skjá. "
            L"Áferð skiptir milli áferðarlagðra flata og víragrindar. Frjáls snúningur myndavélar breytir "
            L"sjónstefnunni hægt í öllum þremur víddum. Valkosturinn „Hlé og stefnuskipti“ bætir við "
            L"tilviljanakenndri hægingu, hléum og breytingum á snúningsstefnu; flug áfram heldur áfram. "
            L"Hraðinn er 0–1600%. Hver skjár hefur sjálfstæða tilviljanakennda senu sem er teiknuð á eigin "
            L"endurnýjunartíðni. Aðalljós, fylliljós, umhverfislýsing og útlínulýsing eru stillt óháð hvert "
            L"öðru fyrir valda skjái. Lýsingin á aðeins við um áferðarfleti. Í báðum hreyfimyndunum með "
            L"flötum má velja sléttu, bylgjur eða trekt. Trektin dregur myndavélina inn eftir spíral sem "
            L"liggur niður á við. Flug um rúm sem þyngdaraflið sveigir sýnir þrívítt víragrindarnet. Áferð, "
            L"lögun flatar og lýsing eiga aðeins við um hreyfimyndirnar tvær með flötum.\r\n\r\nSKJÁIR\r\n"
            L"Val lína ákvarðar hvaða skjám er verið að breyta og er óháð gátreitunum sem kveikja á "
            L"hreyfimyndaúttaki. Ctrl+A velur alla skjái; Ctrl og Shift breyta valinu. Allir valkostir og "
            L"sleðar hreyfimynda gilda fyrir valda skjái. Valið er munað sérstaklega fyrir EXE og SCR. Ef "
            L"allir skjáir voru valdir bætast nýir skjáir einnig við valið. Mismunandi gildi á völdum skjám "
            L"eru sýnd með óákveðnu ástandi gátreita og punktamynstri á valhnöppum, handföngum sleða og "
            L"hnöppunum „Virkja allt“ og „Óvirkja allt“. Merking sleða sýnir strik í stað sameiginlegs "
            L"gildis. Að breyta valkosti eða smella á sleða setur það gildi á alla valda skjái.\r\n\r\n"
            L"FORSKOÐUN OG NOTKUN\r\nVirkja forskoðun ræsir forskoðun á öllum skjám. Stillingaglugginn helst "
            L"opinn og breytingar sjást strax. Í lagi vistar stillingar og Hætta við hafnar breytingum. Esc "
            L"eða músarhreyfing lokar skjáhvílu á öllum skjánum. Notaðu Tab og Shift+Tab til að færa þig "
            L"milli stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc í stillingum jafngildir "
            L"Hætta við; í Hjálp eða Um lokar það aðeins þeim glugga.\r\n\r\nKERFISKRÖFUR\r\nWindows 7 til "
            L"Windows 11 eru studd. Til að keyra forritið á Windows Vista SP2 þarf að setja upp "
            L"uppfærslurnar KB971512 og KB2117917. Birting krefst Direct3D 11, ekki aðeins eldri "
            L"DirectX-keyrsluumhverfis."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Slétta" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Bylgjur" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Trekt" },
    }),
    DefineLanguage(LANG_NB, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Norsk (bokmål)" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Kontroll" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Innstillinger for SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Uendelig bølgende flate" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Langdistanseflytur — formendrende flate" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Flytur gjennom gravitasjonskrummet rom" },
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
            L"Avinstalleringen mislyktes fordi innstillingene for SpaceFlight er åpne. Lukk vinduet og prøv "
            L"på nytt."
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
            L"Maskinvareakselerert flytur over bølgende og formendrende flater."
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
            L"ANIMASJON OG INNSTILLINGER\r\nSpaceFlight: Uendelig bølgende flate; Langdistanseflytur — "
            L"formendrende flate; Flytur gjennom gravitasjonskrummet rom. Tilordne nøyaktig én animasjon til "
            L"hver skjerm. Tekstur veksler mellom teksturerte flater og trådmodell. Fritt roterende kamera "
            L"endrer synsretningen langsomt i alle tre dimensjoner. Pauser og vendinger legger til "
            L"tilfeldige oppbremsinger, pauser og endringer i rotasjonsretningen; flyvningen fremover "
            L"fortsetter. Hastigheten er 0–1600 %. Hver skjerm har en uavhengig tilfeldig scene som gjengis "
            L"ved dens egen oppdateringsfrekvens. Hovedlys, utfyllingslys, omgivelseslys og konturlys kan "
            L"slås av og på uavhengig for de valgte skjermene. Belysningen gjelder bare teksturerte flater. "
            L"De to flateanimasjonene tilbyr Plan, Bølger eller Trakt. Trakten trekker kameraet innover "
            L"langs en nedadgående spiral. Flyturen gjennom gravitasjonskrummet rom viser et tredimensjonalt "
            L"trådgitter. Valgene for tekstur, flateform og belysning gjelder bare de to flateanimasjonene.\r"
            L"\n\r\nSKJERMER\r\nMarkeringen av rader bestemmer hvilke skjermer du redigerer, og er atskilt "
            L"fra avkrysningsboksene som aktiverer animasjonsutgangen. Ctrl+A markerer alle skjermer; Ctrl "
            L"og Skift endrer markeringen. Alle animasjonsvalg og glidebrytere gjelder de markerte "
            L"skjermene. Markeringen huskes separat for EXE og SCR. Hvis alle skjermer var markert, "
            L"inkluderes også nye skjermer. Ulike verdier på de markerte skjermene vises med ubestemte "
            L"avkrysningsbokser og prikkmønster på alternativknapper, glidebryterhåndtak og knappene «Slå på "
            L"alle» og «Slå av alle». Glidebryteretiketter viser en tankestrek i stedet for en felles verdi. "
            L"Endring av et valg eller klikk på en glidebryter bruker denne verdien på alle markerte "
            L"skjermer.\r\n\r\nBETJENING\r\nSlå animasjonsutgangene av eller på med skjermenes "
            L"avkrysningsbokser eller ved å dobbeltklikke på radene deres. Hver skjerm bruker en uavhengig "
            L"scene. Skjermbilde lagrer PNG, og opptaksknappen starter eller stopper MP4. Pause stanser "
            L"animasjonen. Programmet installerer eller avinstallerer også den innebygde skjermspareren. "
            L"Innstillingene lagres fortløpende. Bare én instans av programmet kan kjøre om gangen. En ny "
            L"start gjenoppretter det minimerte kontrollvinduet og bringer det fremst. Bruk Tab og Shift+Tab "
            L"for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc "
            L"lukker det aktive Hjelp- eller Om-vinduet; i kontrollvinduet avslutter det programmet. Pause "
            L"og blokkering av skjermspareren gjelder hele programmet uavhengig av skjermmarkeringen. Når "
            L"blokkering er slått på, hindres Windows-skjermspareren bare mens en synlig animasjon som ikke "
            L"er satt på pause, vises på minst én skjerm.\r\n\r\nSKJERMBILDER OG OPPTAK\r\nSkjermbilder og "
            L"opptak bruker den første aktive animasjonsskjermen, ikke et samlet bilde av alle skjermene. "
            L"PNG bruker Bilder, MP4 Videoer; hvis disse mappene ikke finnes, brukes Dokumenter. Knappen "
            L"Opptaksinnstillinger velger Viewport eller TV. Viewport beholder animasjonsskjermens størrelse "
            L"og oppdateringsfrekvens, opptil 60 bilder per sekund. TV tilbyr 1920 × 1080, 1440 × 1080 eller "
            L"1280 × 720 i formatet 16:9, med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) bilder per "
            L"sekund. Bildets proporsjoner beholdes; TV bruker progressiv BT.709-video med begrenset område "
            L"og 4:2:0-sampling. Oppløsning og bildefrekvens er bare tilgjengelige i TV-modus. Vinduet "
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
            L"ANIMASJON OG INNSTILLINGER\r\nSpaceFlight: Uendelig bølgende flate; Langdistanseflytur — "
            L"formendrende flate; Flytur gjennom gravitasjonskrummet rom. Tilordne nøyaktig én animasjon til "
            L"hver skjerm. Tekstur veksler mellom teksturerte flater og trådmodell. Fritt roterende kamera "
            L"endrer synsretningen langsomt i alle tre dimensjoner. Pauser og vendinger legger til "
            L"tilfeldige oppbremsinger, pauser og endringer i rotasjonsretningen; flyvningen fremover "
            L"fortsetter. Hastigheten er 0–1600 %. Hver skjerm har en uavhengig tilfeldig scene som gjengis "
            L"ved dens egen oppdateringsfrekvens. Hovedlys, utfyllingslys, omgivelseslys og konturlys kan "
            L"slås av og på uavhengig for de valgte skjermene. Belysningen gjelder bare teksturerte flater. "
            L"De to flateanimasjonene tilbyr Plan, Bølger eller Trakt. Trakten trekker kameraet innover "
            L"langs en nedadgående spiral. Flyturen gjennom gravitasjonskrummet rom viser et tredimensjonalt "
            L"trådgitter. Valgene for tekstur, flateform og belysning gjelder bare de to flateanimasjonene.\r"
            L"\n\r\nSKJERMER\r\nMarkeringen av rader bestemmer hvilke skjermer du redigerer, og er atskilt "
            L"fra avkrysningsboksene som aktiverer animasjonsutgangen. Ctrl+A markerer alle skjermer; Ctrl "
            L"og Skift endrer markeringen. Alle animasjonsvalg og glidebrytere gjelder de markerte "
            L"skjermene. Markeringen huskes separat for EXE og SCR. Hvis alle skjermer var markert, "
            L"inkluderes også nye skjermer. Ulike verdier på de markerte skjermene vises med ubestemte "
            L"avkrysningsbokser og prikkmønster på alternativknapper, glidebryterhåndtak og knappene «Slå på "
            L"alle» og «Slå av alle». Glidebryteretiketter viser en tankestrek i stedet for en felles verdi. "
            L"Endring av et valg eller klikk på en glidebryter bruker denne verdien på alle markerte "
            L"skjermer.\r\n\r\nFORHÅNDSVISNING OG BETJENING\r\nSlå på forhåndsvisning starter en "
            L"fullskjermsvisning på alle skjermer. Innstillingene forblir åpne, og endringene vises "
            L"fortløpende. OK lagrer innstillingene og Avbryt forkaster dem. Esc eller musebevegelse "
            L"avslutter fullskjermsvisningen. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og "
            L"den understrekede bokstaven aktiverer en kommando. Esc i innstillingene tilsvarer Avbryt; i "
            L"Hjelp eller Om lukker det bare dette vinduet.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 "
            L"støttes. For å kjøre programmet på Windows Vista SP2 må oppdateringene KB971512 og KB2117917 "
            L"installeres. Visningen krever Direct3D 11, ikke bare en eldre DirectX-kjøretid."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Plan" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Bølger" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Trakt" },
    }),
    DefineLanguage(LANG_SV, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Svenska" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Styrning" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Inställningar för SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Oändlig böljande yta" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Långdistansflygtur — formföränderlig yta" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Flygtur genom gravitationellt krökt rum" },
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
            L"Avinstallationen misslyckades eftersom inställningarna för SpaceFlight är öppna. Stäng "
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
            L"Maskinvaruaccelererad flygtur över böljande och formföränderliga ytor."
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
            L"ANIMERING OCH INSTÄLLNINGAR\r\nSpaceFlight: Oändlig böljande yta; Långdistansflygtur — "
            L"formföränderlig yta; Flygtur genom gravitationellt krökt rum. Tilldela varje skärm exakt en "
            L"animering. Textur växlar mellan texturerade ytor och trådmodell. Fritt roterande kamera ändrar "
            L"långsamt blickriktningen i alla tre dimensioner. Pauser och vändningar lägger till "
            L"slumpmässiga inbromsningar, pauser och byten av rotationsriktning; flygningen framåt "
            L"fortsätter. Hastigheten är 0–1600 %. Varje skärm har en oberoende slumpmässig scen som återges "
            L"med dess egen uppdateringsfrekvens. Huvudljus, upplättningsljus, omgivningsljus och konturljus "
            L"kan slås på och av oberoende för de valda skärmarna. Belysningen gäller bara texturerade ytor. "
            L"De två ytanimeringarna erbjuder Plan, Vågor eller Tratt. Tratten drar kameran inåt längs en "
            L"nedåtgående spiral. Flygturen genom gravitationellt krökt rum visar ett tredimensionellt "
            L"trådnät. Inställningarna för textur, ytform och belysning gäller bara de två ytanimeringarna.\r"
            L"\n\r\nBILDSKÄRMAR\r\nMarkeringen av rader avgör vilka skärmar du redigerar och är skild från "
            L"kryssrutorna som aktiverar animationsutgångarna. Ctrl+A markerar alla skärmar; Ctrl och Skift "
            L"ändrar markeringen. Alla animationsalternativ och reglage gäller de markerade skärmarna. "
            L"Markeringen sparas separat för EXE och SCR. Om alla skärmar var markerade inkluderas även nya "
            L"skärmar. Olika värden på de markerade skärmarna visas med obestämda kryssrutor och "
            L"punktmönster på alternativknappar, reglagehandtag och knapparna ”Aktivera alla” och "
            L"”Inaktivera alla”. Reglagens etiketter visar ett streck i stället för ett gemensamt värde. När "
            L"du ändrar ett alternativ eller klickar på ett reglage används värdet på alla markerade "
            L"skärmar.\r\n\r\nANVÄNDNING\r\nSlå på eller av animationsutgångarna med skärmarnas kryssrutor "
            L"eller genom att dubbelklicka på deras rader. Varje bildskärm använder en oberoende scen. "
            L"Skärmbild sparar PNG och inspelningsknappen startar eller stoppar MP4. Paus stannar "
            L"animeringen. Programmet installerar eller avinstallerar även den inbyggda skärmsläckaren. "
            L"Inställningarna sparas fortlöpande. Programmet kan bara köras i en instans åt gången. En ny "
            L"start återställer det minimerade kontrollfönstret och för det längst fram. Använd Tab och "
            L"Skift+Tab för att flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett "
            L"kommando. Esc stänger det aktiva Hjälp- eller Om-fönstret; i kontrollfönstret avslutar det "
            L"programmet. Paus och blockering av skärmsläckaren gäller hela programmet oavsett markerade "
            L"skärmar. När blockeringen är på hindras Windows-skärmsläckaren bara medan en synlig animering "
            L"som inte är pausad visas på minst en skärm.\r\n\r\nSKÄRMBILDER OCH INSPELNING\r\nSkärmbilder "
            L"och inspelningar använder den första aktiva animeringsskärmen, inte en sammanslagen bild av "
            L"alla skärmar. PNG använder Bilder, MP4 Videor; om dessa mappar saknas används Dokument. "
            L"Knappen Inspelningsinställningar väljer Viewport eller TV. Viewport behåller "
            L"animeringsskärmens storlek och uppdateringsfrekvens, upp till 60 bilder per sekund. TV "
            L"erbjuder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9, med 50, 25, 59.94 "
            L"(60000/1001) eller 29.97 (30000/1001) bilder per sekund. Bildens proportioner bevaras; TV "
            L"använder progressiv BT.709-video med begränsat omfång och 4:2:0-sampling. Upplösning och "
            L"bildfrekvens kan bara väljas i TV-läge. Fönstret Inspelningsinställningar kan minimeras och "
            L"blockerar inte de andra programfönstren. OK sparar valen för nästa MP4-inspelning; Avbryt "
            L"eller Esc ignorerar obekräftade ändringar. Animeringsutgången på den inspelade skärmen kan "
            L"inte stängas av under inspelningen; ändringar av andra skärmar stoppar inte inspelningen. Att "
            L"avsluta programmet under en inspelning kräver bekräftelse eftersom det också avslutar "
            L"inspelningen.\r\n\r\nSYSTEMKRAV\r\nWindows 7 till Windows 11 stöder alla funktioner, inklusive "
            L"PNG-skärmbilder och MP4-inspelning. För att köra programmet på Windows Vista SP2 måste "
            L"uppdateringarna KB971512 och KB2117917 installeras. MP4-inspelning fungerar inte på Vista i "
            L"den aktuella versionen. Visningen kräver Direct3D 11, inte bara en äldre "
            L"DirectX-körningsmiljö. MP4-inspelning kräver tillgängliga Media Foundation-komponenter och en "
            L"H.264-kodare."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMERING OCH INSTÄLLNINGAR\r\nSpaceFlight: Oändlig böljande yta; Långdistansflygtur — "
            L"formföränderlig yta; Flygtur genom gravitationellt krökt rum. Tilldela varje skärm exakt en "
            L"animering. Textur växlar mellan texturerade ytor och trådmodell. Fritt roterande kamera ändrar "
            L"långsamt blickriktningen i alla tre dimensioner. Pauser och vändningar lägger till "
            L"slumpmässiga inbromsningar, pauser och byten av rotationsriktning; flygningen framåt "
            L"fortsätter. Hastigheten är 0–1600 %. Varje skärm har en oberoende slumpmässig scen som återges "
            L"med dess egen uppdateringsfrekvens. Huvudljus, upplättningsljus, omgivningsljus och konturljus "
            L"kan slås på och av oberoende för de valda skärmarna. Belysningen gäller bara texturerade ytor. "
            L"De två ytanimeringarna erbjuder Plan, Vågor eller Tratt. Tratten drar kameran inåt längs en "
            L"nedåtgående spiral. Flygturen genom gravitationellt krökt rum visar ett tredimensionellt "
            L"trådnät. Inställningarna för textur, ytform och belysning gäller bara de två ytanimeringarna.\r"
            L"\n\r\nBILDSKÄRMAR\r\nMarkeringen av rader avgör vilka skärmar du redigerar och är skild från "
            L"kryssrutorna som aktiverar animationsutgångarna. Ctrl+A markerar alla skärmar; Ctrl och Skift "
            L"ändrar markeringen. Alla animationsalternativ och reglage gäller de markerade skärmarna. "
            L"Markeringen sparas separat för EXE och SCR. Om alla skärmar var markerade inkluderas även nya "
            L"skärmar. Olika värden på de markerade skärmarna visas med obestämda kryssrutor och "
            L"punktmönster på alternativknappar, reglagehandtag och knapparna ”Aktivera alla” och "
            L"”Inaktivera alla”. Reglagens etiketter visar ett streck i stället för ett gemensamt värde. När "
            L"du ändrar ett alternativ eller klickar på ett reglage används värdet på alla markerade "
            L"skärmar.\r\n\r\nFÖRHANDSGRANSKNING OCH ANVÄNDNING\r\nAktivera förhandsvisning startar en "
            L"helskärmsvisning på alla bildskärmar. Inställningarna förblir öppna och ändringarna visas "
            L"direkt. OK sparar inställningarna och Avbryt förkastar ändringarna. Esc eller musrörelse "
            L"avslutar helskärmsläget. Använd Tab och Skift+Tab för att flytta mellan kontrollerna; Alt och "
            L"den understrukna bokstaven aktiverar ett kommando. Esc i inställningarna motsvarar Avbryt; i "
            L"Hjälp eller Om stänger det bara det fönstret.\r\n\r\nSYSTEMKRAV\r\nWindows 7 till Windows 11 "
            L"stöds. För att köra programmet på Windows Vista SP2 måste uppdateringarna KB971512 och "
            L"KB2117917 installeras. Visningen kräver Direct3D 11, inte bara en äldre DirectX-körningsmiljö."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Plan" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Vågor" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Tratt" },
    }),
    DefineLanguage(LANG_TR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Türkçe" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — Denetim" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"SpaceFlight Ayarları" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Sonsuz dalgalanan yüzey" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Uzun mesafeli uçuş — biçim değiştiren yüzey" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Kütleçekimiyle bükülmüş uzayda uçuş" },
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
            L"SpaceFlight ayarları açık olduğu için kaldırma başarısız oldu. Ayarlar penceresini kapatıp "
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
            L"Dalgalanan ve biçim değiştiren yüzeyler üzerinde donanım hızlandırmalı uçuş."
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
            L"ANİMASYON VE AYARLAR\r\nSpaceFlight: Sonsuz dalgalanan yüzey; Uzun mesafeli uçuş — biçim "
            L"değiştiren yüzey; Kütleçekimiyle bükülmüş uzayda uçuş. Her ekrana tam bir animasyon atayın. "
            L"Doku, dokulu yüzeyler ile tel kafes modeli arasında geçiş yapar. Serbest kamera dönüşü bakış "
            L"yönünü üç boyutta yavaşça değiştirir. Duraklama ve ters dönüş, dönüşe rastgele yavaşlamalar, "
            L"duraklamalar ve ters yön değişimleri ekler; ileri uçuş devam eder. Hız %0–1600 aralığındadır. "
            L"Her ekranın kendi yenileme hızında çizilen bağımsız rastgele bir sahnesi vardır. Ana ışık, "
            L"dolgu ışığı, ortam ışığı ve kenar aydınlatması seçili ekranlar için ayrı ayrı açılıp "
            L"kapatılabilir. Aydınlatma yalnızca dokulu yüzeylere uygulanır. İki yüzey animasyonunda Düzlem, "
            L"Dalgalanma veya Huni seçilebilir. Huni, kamerayı aşağı doğru bir sarmal boyunca içeri çeker. "
            L"Kütleçekimiyle bükülmüş uzayda uçuş, üç boyutlu bir tel kafes gösterir. Doku, yüzey biçimi ve "
            L"aydınlatma seçenekleri yalnızca iki yüzey animasyonuna uygulanır.\r\n\r\nEKRANLAR\r\nSatır "
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
            L"ANİMASYON VE AYARLAR\r\nSpaceFlight: Sonsuz dalgalanan yüzey; Uzun mesafeli uçuş — biçim "
            L"değiştiren yüzey; Kütleçekimiyle bükülmüş uzayda uçuş. Her ekrana tam bir animasyon atayın. "
            L"Doku, dokulu yüzeyler ile tel kafes modeli arasında geçiş yapar. Serbest kamera dönüşü bakış "
            L"yönünü üç boyutta yavaşça değiştirir. Duraklama ve ters dönüş, dönüşe rastgele yavaşlamalar, "
            L"duraklamalar ve ters yön değişimleri ekler; ileri uçuş devam eder. Hız %0–1600 aralığındadır. "
            L"Her ekranın kendi yenileme hızında çizilen bağımsız rastgele bir sahnesi vardır. Ana ışık, "
            L"dolgu ışığı, ortam ışığı ve kenar aydınlatması seçili ekranlar için ayrı ayrı açılıp "
            L"kapatılabilir. Aydınlatma yalnızca dokulu yüzeylere uygulanır. İki yüzey animasyonunda Düzlem, "
            L"Dalgalanma veya Huni seçilebilir. Huni, kamerayı aşağı doğru bir sarmal boyunca içeri çeker. "
            L"Kütleçekimiyle bükülmüş uzayda uçuş, üç boyutlu bir tel kafes gösterir. Doku, yüzey biçimi ve "
            L"aydınlatma seçenekleri yalnızca iki yüzey animasyonuna uygulanır.\r\n\r\nEKRANLAR\r\nSatır "
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
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Düzlem" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Dalgalanma" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Huni" },
    }),
    DefineLanguage(LANG_ET, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Eesti" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — juhtimine" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"SpaceFlight sätted" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Lõputu lainetav pind" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Kauglend — muutuv pind" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT,
            L"Lend läbi gravitatsiooniliselt kõverdunud ruumi"
        },
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
            L"Sulgege SpaceFlight sätete aken ja proovige eemaldamist uuesti."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Sulgege Windowsi ekraanisäästja sätete aken ja proovige eemaldamist uuesti."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Sulgege ekraanisäästja või täisekraanieelvaade klahviga Esc või hiire liigutamisega ja "
            L"proovige eemaldamist uuesti."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Riistvarakiirendusega lend lainetava pinna kohal." },
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
            L"ANIMATSIOON JA SÄTTED\r\nSpaceFlight: Lõputu lainetav pind; Kauglend — muutuv pind; Lend läbi "
            L"gravitatsiooniliselt kõverdunud ruumi. Valige igale kuvarile täpselt üks animatsioon. "
            L"Tekstuuri märkeruut vahetab tekstuuriga pinna ja traatmudeli vahel. Kaamera vaba pöörlemine "
            L"muudab vaatesuunda aeglaselt kõigis kolmes mõõtmes. Pausid ja pöördumised lisavad sellele "
            L"juhuslikke aeglustusi, pause ja pöörlemissuuna muutusi; edasilend jätkub. Kiirus on seatav "
            L"vahemikus 0–1600%. Igal kuvaril on oma sõltumatu juhuslik stseen ja värskendussagedusele "
            L"vastav renderdus. Põhivalgust, täitevalgust, ümbritsevat valgust ja kontuurivalgust saab "
            L"valitud kuvaritel eraldi sisse ja välja lülitada. Valgustus kehtib ainult tekstuuriga "
            L"pindadele. Mõlemas pinnaanimatsioonis saab valida tasandi, lained või lehtri. Lehter tõmbab "
            L"kaamera mööda laskuvat spiraali sissepoole. Lend läbi gravitatsiooniliselt kõverdunud ruumi "
            L"näitab kolmemõõtmelist traatvõrku. Tekstuuri, pinna kuju ja valgustuse valikud kehtivad ainult "
            L"kahe pinnaanimatsiooni jaoks.\r\n\r\nKUVARID\r\nValige loendis üks või mitu kuvaririda. Ctrl+A "
            L"valib kõik read; Ctrl ja Shift võimaldavad valikut muuta. Animatsiooni juhtnupud ja liugurid "
            L"mõjutavad ainult valitud kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle "
            L"märkeruuduga väljundi lubamine on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja "
            L"jaoks eraldi meelde. Kui varem olid valitud kõik kuvarid, kaasatakse ka lisatud kuvarid. "
            L"Valitud kuvarite erinevaid väärtusi näitavad märkeruutude määramata olek ning raadionuppude, "
            L"liugurite käepidemete ja nuppude „Luba kõik” ja „Keela kõik” punktimuster. Liuguri sildil on "
            L"ühise väärtuse asemel kriips. Valiku muutmine või liuguril klõpsamine määrab selle väärtuse "
            L"kõigile valitud kuvaritele.\r\n\r\nKASUTAMINE\r\nKäivitage SpaceFlight.exe. Sätteid "
            L"salvestatakse jooksvalt ning rakendus töötab ühe eksemplarina. Kuvari märkeruut või "
            L"topeltklõps real lülitab selle animatsiooniväljundi sisse või välja. Animatsiooni saab peatada "
            L"ja jätkata. PNG-pilt ja MP4-video jäädvustavad esimese aktiivse animatsioonikuvari, mitte "
            L"kõiki kuvareid koos. Salvestatava kuvari animatsiooniväljundit ei saa salvestamise ajal välja "
            L"lülitada; rakenduse sulgemine nõuab siis kinnitust. Peatamine ja ekraanisäästja tõkestamine "
            L"kehtivad kogu rakendusele, sõltumata kuvarite valikust. Kui tõkestamine on sisse lülitatud, "
            L"takistatakse Windowsi ekraanisäästjat ainult seni, kuni vähemalt ühel kuvaril on nähtav "
            L"peatamata animatsioon. Rakendus saab paigaldada ja eemaldada sisseehitatud ekraanisäästja.\r\n"
            L"\r\nKUVATÕMMISED JA SALVESTAMINE\r\nSalvestussätetes valige Viewport või TV. Viewport säilitab "
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
            L"ANIMATSIOON JA SÄTTED\r\nSpaceFlight: Lõputu lainetav pind; Kauglend — muutuv pind; Lend läbi "
            L"gravitatsiooniliselt kõverdunud ruumi. Valige igale kuvarile täpselt üks animatsioon. "
            L"Tekstuuri märkeruut vahetab tekstuuriga pinna ja traatmudeli vahel. Kaamera vaba pöörlemine "
            L"muudab vaatesuunda aeglaselt kõigis kolmes mõõtmes. Pausid ja pöördumised lisavad sellele "
            L"juhuslikke aeglustusi, pause ja pöörlemissuuna muutusi; edasilend jätkub. Kiirus on seatav "
            L"vahemikus 0–1600%. Igal kuvaril on oma sõltumatu juhuslik stseen ja värskendussagedusele "
            L"vastav renderdus. Põhivalgust, täitevalgust, ümbritsevat valgust ja kontuurivalgust saab "
            L"valitud kuvaritel eraldi sisse ja välja lülitada. Valgustus kehtib ainult tekstuuriga "
            L"pindadele. Mõlemas pinnaanimatsioonis saab valida tasandi, lained või lehtri. Lehter tõmbab "
            L"kaamera mööda laskuvat spiraali sissepoole. Lend läbi gravitatsiooniliselt kõverdunud ruumi "
            L"näitab kolmemõõtmelist traatvõrku. Tekstuuri, pinna kuju ja valgustuse valikud kehtivad ainult "
            L"kahe pinnaanimatsiooni jaoks.\r\n\r\nKUVARID\r\nValige loendis üks või mitu kuvaririda. Ctrl+A "
            L"valib kõik read; Ctrl ja Shift võimaldavad valikut muuta. Animatsiooni juhtnupud ja liugurid "
            L"mõjutavad ainult valitud kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle "
            L"märkeruuduga väljundi lubamine on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja "
            L"jaoks eraldi meelde. Kui varem olid valitud kõik kuvarid, kaasatakse ka lisatud kuvarid. "
            L"Valitud kuvarite erinevaid väärtusi näitavad märkeruutude määramata olek ning raadionuppude, "
            L"liugurite käepidemete ja nuppude „Luba kõik” ja „Keela kõik” punktimuster. Liuguri sildil on "
            L"ühise väärtuse asemel kriips. Valiku muutmine või liuguril klõpsamine määrab selle väärtuse "
            L"kõigile valitud kuvaritele.\r\n\r\nEELVAADE JA KASUTAMINE\r\nKäivitage SpaceFlight.scr "
            L"Windowsi ekraanisäästjana. Selle sätted on rakenduse omadest eraldi. Sätete eelvaade lubab "
            L"täisekraanil animatsiooni jooksvalt muuta. OK salvestab muudatused ning Loobu või Esc tühistab "
            L"need. Täisekraanil ekraanisäästjast väljumiseks vajutage klahvi või liigutage hiirt.\r\n\r\n"
            L"SÜSTEEMINÕUDED\r\nWindows 7–11 toetab kõiki funktsioone. Windows Vista SP2 jaoks tuleb "
            L"paigaldada värskendused KB971512 ja KB2117917. Vaja on Direct3D 11 tuge."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Tasand" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Lained" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Lehter" },
    }),
    DefineLanguage(LANG_GA, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Gaeilge" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — rialuithe" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Socruithe SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Dromchla tonnúil gan teorainn" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Eitilt fhada — dromchla athraitheach" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT,
            L"Eitilt trí spás atá cuartha ag an domhantarraingt"
        },
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
            L"Dún fuinneog socruithe SpaceFlight agus bain triail eile as an díshuiteáil."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Dún fuinneog socruithe spárálaí scáileáin Windows agus bain triail eile as an díshuiteáil."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Dún an spárálaí scáileáin nó an réamhamharc lánscáileáin le Esc nó trí an luch a bhogadh agus "
            L"bain triail eile as."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Eitilt os cionn dromchla tonnúil le luasghéarú crua-earraí."
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
            L"BEOCHAN AGUS SOCRUITHE\r\nSpaceFlight: Dromchla tonnúil gan teorainn; Eitilt fhada — dromchla "
            L"athraitheach; Eitilt trí spás atá cuartha ag an domhantarraingt. Roghnaigh beochan amháin do "
            L"gach monatóir. Athraíonn Uigeacht idir dromchla uigeachtaithe agus samhail sreangfhráma. "
            L"Rothlaíonn rothlú saor an cheamara an radharc go mall sna trí thoise. Cuireann Sosanna agus "
            L"aisiompuithe coscánú, sosanna agus athruithe treo randamacha leis an rothlú; leanann an eitilt "
            L"chun tosaigh. Tá luas 0–1600% ar fáil. Tá radharc randamach neamhspleách ag gach monatóir agus "
            L"déantar rindreáil de réir a ráta athnuachana féin. Is féidir an príomhsholas, an solas líonta, "
            L"an solas comhthimpeallach agus an solas imill a athrú go neamhspleách do na taispeántais "
            L"roghnaithe. Ní bhaineann an soilsiú ach le dromchlaí uigeachtaithe. Tá Plána, Tonnta nó "
            L"Tonnadóir ar fáil don dá bheochan dromchla. Tarraingíonn an tonnadóir an ceamara isteach ar "
            L"bhís a théann síos. Taispeántar an spás cuartha mar shreangfhráma i dtrí thoise. Ní bhaineann "
            L"na roghanna uigeachta, crutha dromchla agus soilsithe ach leis an dá bheochan dromchla.\r\n\r\n"
            L"TAISPEÁNTAIS\r\nRoghnaigh ró amháin nó níos mó sa liosta monatóirí. Roghnaíonn Ctrl+A gach ró; "
            L"úsáid Ctrl agus Shift chun an roghnú a athrú. Ní athraíonn rialuithe agus sleamhnáin na "
            L"beochana ach socruithe na monatóirí roghnaithe. Ní hionann ró a roghnú agus aschur an "
            L"mhonatóra a chumasú lena bhosca seiceála. Cuimhnítear an roghnú ar leith don fheidhmchlár agus "
            L"don spárálaí. Má bhí gach monatóir roghnaithe, cuirtear monatóirí nua leis an roghnú freisin. "
            L"Léirítear luachanna éagsúla ar na monatóirí roghnaithe le boscaí seiceála i staid neamhchinnte "
            L"agus le patrún poncanna ar chnaipí raidió, ar ghreimíní sleamhnán agus ar na cnaipí “Cumasaigh "
            L"uile” agus “Díchumasaigh uile”. Taispeántar dais ar lipéad an tsleamhnáin in ionad luach "
            L"coiteann. Nuair a athraítear rogha nó a chliceáiltear sleamhnán, cuirtear an luach sin i "
            L"bhfeidhm ar gach monatóir roghnaithe.\r\n\r\nRIALÚ\r\nRith SpaceFlight.exe. Sábháiltear "
            L"socruithe go leanúnach agus ní ritheann ach cóip amháin den fheidhmchlár. Cumasaíonn nó "
            L"díchumasaíonn bosca seiceála an mhonatóra nó déchliceáil ar a ró an t-aschur beochana. Is "
            L"féidir an bheochan a chur ar sos agus a atosú. Gabhann PNG agus MP4 an chéad mhonatóir "
            L"beochana gníomhach, ní na monatóirí uile le chéile. Ní féidir aschur beochana an mhonatóra atá "
            L"á thaifeadadh a dhíchumasú le linn taifeadta; teastaíonn deimhniú chun an feidhmchlár a "
            L"dhúnadh agus taifeadadh ar siúl. Baineann sos agus cosc an spárálaí scáileáin leis an "
            L"bhfeidhmchlár iomlán, beag beann ar na monatóirí roghnaithe. Nuair atá an cosc cumasaithe, ní "
            L"choisctear spárálaí scáileáin Windows ach fad a bhíonn beochan infheicthe nach bhfuil ar sos "
            L"ar mhonatóir amháin ar a laghad. Is féidir an spárálaí leabaithe a shuiteáil nó a dhíshuiteáil "
            L"ón bhfeidhmchlár.\r\n\r\nGABHÁLACHA SCÁILEÁIN AGUS TAIFEADADH\r\nRoghnaigh Viewport nó TV i "
            L"socruithe taifeadta. Coinníonn Viewport toisí agus ráta athnuachana an mhonatóra, suas le 60 "
            L"fráma sa soicind. Tairgeann TV 1920 × 1080, 1440 × 1080 nó 1280 × 720 i gcóimheas 16:9 ag 50, "
            L"25, 59.94 (60000/1001) nó 29.97 (30000/1001) fráma sa soicind. Is físeán forásach BT.709 é, le "
            L"raon teoranta agus foshampláil datha 4:2:0. Coinnítear cóimheas an phictiúir agus tá na barraí "
            L"líonta dubh. Cuireann OK roghanna i bhfeidhm ar an gcéad taifeadadh eile; cealaíonn Cealaigh "
            L"nó Esc athruithe neamhdheimhnithe. Ní chuireann socruithe taifeadta, Cabhair ná Maidir leis "
            L"bac ar fhuinneoga eile agus is féidir iad a íoslaghdú. Bogann Tab agus Shift+Tab an fócas; "
            L"gníomhaíonn Enter an cnaipe faoi fhócas agus dúnann Esc an fhuinneog chúnta ghníomhach.\r\n\r\n"
            L"RIACHTANAIS CHÓRAIS\r\nTacaíonn Windows 7–11 leis na gnéithe uile. Ar Windows Vista SP2 ní mór "
            L"nuashonruithe KB971512 agus KB2117917 a shuiteáil; ní oibríonn taifeadadh MP4 ar Vista. "
            L"Teastaíonn tacaíocht Direct3D 11, agus Media Foundation agus ionchódóir H.264 le haghaidh MP4. "
            L"Tá an comhéadan agus an doiciméadú ar fáil i 36 teanga."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"BEOCHAN AGUS SOCRUITHE\r\nSpaceFlight: Dromchla tonnúil gan teorainn; Eitilt fhada — dromchla "
            L"athraitheach; Eitilt trí spás atá cuartha ag an domhantarraingt. Roghnaigh beochan amháin do "
            L"gach monatóir. Athraíonn Uigeacht idir dromchla uigeachtaithe agus samhail sreangfhráma. "
            L"Rothlaíonn rothlú saor an cheamara an radharc go mall sna trí thoise. Cuireann Sosanna agus "
            L"aisiompuithe coscánú, sosanna agus athruithe treo randamacha leis an rothlú; leanann an eitilt "
            L"chun tosaigh. Tá luas 0–1600% ar fáil. Tá radharc randamach neamhspleách ag gach monatóir agus "
            L"déantar rindreáil de réir a ráta athnuachana féin. Is féidir an príomhsholas, an solas líonta, "
            L"an solas comhthimpeallach agus an solas imill a athrú go neamhspleách do na taispeántais "
            L"roghnaithe. Ní bhaineann an soilsiú ach le dromchlaí uigeachtaithe. Tá Plána, Tonnta nó "
            L"Tonnadóir ar fáil don dá bheochan dromchla. Tarraingíonn an tonnadóir an ceamara isteach ar "
            L"bhís a théann síos. Taispeántar an spás cuartha mar shreangfhráma i dtrí thoise. Ní bhaineann "
            L"na roghanna uigeachta, crutha dromchla agus soilsithe ach leis an dá bheochan dromchla.\r\n\r\n"
            L"TAISPEÁNTAIS\r\nRoghnaigh ró amháin nó níos mó sa liosta monatóirí. Roghnaíonn Ctrl+A gach ró; "
            L"úsáid Ctrl agus Shift chun an roghnú a athrú. Ní athraíonn rialuithe agus sleamhnáin na "
            L"beochana ach socruithe na monatóirí roghnaithe. Ní hionann ró a roghnú agus aschur an "
            L"mhonatóra a chumasú lena bhosca seiceála. Cuimhnítear an roghnú ar leith don fheidhmchlár agus "
            L"don spárálaí. Má bhí gach monatóir roghnaithe, cuirtear monatóirí nua leis an roghnú freisin. "
            L"Léirítear luachanna éagsúla ar na monatóirí roghnaithe le boscaí seiceála i staid neamhchinnte "
            L"agus le patrún poncanna ar chnaipí raidió, ar ghreimíní sleamhnán agus ar na cnaipí “Cumasaigh "
            L"uile” agus “Díchumasaigh uile”. Taispeántar dais ar lipéad an tsleamhnáin in ionad luach "
            L"coiteann. Nuair a athraítear rogha nó a chliceáiltear sleamhnán, cuirtear an luach sin i "
            L"bhfeidhm ar gach monatóir roghnaithe.\r\n\r\nRÉAMHAMHARC AGUS RIALÚ\r\nÚsáid SpaceFlight.scr "
            L"mar spárálaí scáileáin Windows. Tá a shocruithe ar leith ó shocruithe an fheidhmchláir. "
            L"Ceadaíonn an réamhamharc lánscáileáin athruithe beo. Sábhálann OK agus cealaíonn Cealaigh nó "
            L"Esc na hathruithe. Fág an spárálaí lánscáileáin le heochair ar bith nó le gluaiseacht na "
            L"luiche.\r\n\r\nRIACHTANAIS CHÓRAIS\r\nTacaíonn Windows 7–11 leis na gnéithe uile. Ar Windows "
            L"Vista SP2 ní mór nuashonruithe KB971512 agus KB2117917 a shuiteáil. Teastaíonn tacaíocht "
            L"Direct3D 11."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Plána" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Tonnta" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Tonnadóir" },
    }),
    DefineLanguage(LANG_LT, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Lietuvių" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — valdymas" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"SpaceFlight nuostatos" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Begalinis banguojantis paviršius" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Tolimas skrydis — kintantis paviršius" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Skrydis per gravitacijos iškreiptą erdvę" },
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
            L"Uždarykite SpaceFlight nuostatų langą ir bandykite pašalinti dar kartą."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Uždarykite Windows ekrano užsklandos nuostatų langą ir bandykite pašalinti dar kartą."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Užbaikite užsklandą arba viso ekrano peržiūrą klavišu Esc ar pajudindami pelę ir bandykite "
            L"pašalinti dar kartą."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Aparatine įranga spartinamas skrydis virš banguojančio paviršiaus."
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
            L"ANIMACIJA IR NUOSTATOS\r\nSpaceFlight: Begalinis banguojantis paviršius; Tolimas skrydis — "
            L"kintantis paviršius; Skrydis per gravitacijos iškreiptą erdvę. Kiekvienam monitoriui "
            L"pasirinkite vieną animaciją. Tekstūros langelis perjungia tekstūruotą paviršių ir vielinį "
            L"modelį. Laisvas kameros sukimasis lėtai keičia žiūrėjimo kryptį visose trijose dimensijose. "
            L"Pauzės ir apsisukimai prideda atsitiktinį lėtėjimą, pauzes ir sukimosi krypties keitimą; "
            L"skrydis pirmyn tęsiasi. Galimas 0–1600% greitis. Kiekvienas monitorius turi nepriklausomą "
            L"atsitiktinę sceną, atvaizduojamą jo atnaujinimo dažniu. Pagrindinę, užpildančią, aplinkos ir "
            L"kontūrinę šviesą galima atskirai įjungti pasirinktiems ekranams. Apšvietimas taikomas tik "
            L"tekstūruotiems paviršiams. Abiejose paviršių animacijose galima pasirinkti plokštumą, bangas "
            L"arba piltuvą. Piltuvas traukia kamerą į vidų žemyn besisukančia spirale. Skrydis per "
            L"gravitacijos iškreiptą erdvę rodo trimatį karkasinį tinklą. Tekstūros, paviršiaus formos ir "
            L"apšvietimo parinktys taikomos tik dviem paviršių animacijoms.\r\n\r\nMONITORIAI\r\nMonitorių "
            L"sąraše pasirinkite vieną ar kelias eilutes. Ctrl+A pasirenka visas, o Ctrl ir Shift leidžia "
            L"keisti pasirinkimą. Animacijos valdikliai ir slankikliai keičia tik pasirinktų monitorių "
            L"nuostatas. Eilutės pasirinkimas nėra tas pats, kas animacijos išvesties įjungimas jos "
            L"žymimuoju langeliu. Pasirinkimas atskirai įsimenamas programai ir užsklandai. Jei buvo "
            L"pasirinkti visi monitoriai, į pasirinkimą įtraukiami ir naujai prijungti monitoriai. "
            L"Skirtingas pasirinktų monitorių reikšmes rodo neapibrėžta žymimųjų langelių būsena ir taškinis "
            L"raštas ant parinkčių mygtukų, slankiklių rankenėlių bei mygtukų „Įjungti visus“ ir „Išjungti "
            L"visus“. Slankiklių užrašuose vietoj bendros reikšmės rodomas brūkšnys. Pakeitus parinktį arba "
            L"spustelėjus slankiklį, ta reikšmė pritaikoma visiems pasirinktiems monitoriams.\r\n\r\n"
            L"VALDYMAS\r\nPaleiskite SpaceFlight.exe. Nuostatos išsaugomos nuolat, veikia tik vienas "
            L"programos egzempliorius. Monitoriaus langelis arba dvigubas eilutės spustelėjimas įjungia ar "
            L"išjungia animacijos išvestį. Animaciją galima pristabdyti ir tęsti. PNG ir MP4 fiksuoja pirmą "
            L"aktyvų animacijos monitorių, o ne bendrą visų monitorių vaizdą. Įrašymo metu negalima išjungti "
            L"įrašomo monitoriaus animacijos išvesties; uždarant programą vykstant įrašymui reikia "
            L"patvirtinimo. Pristabdymas ir užsklandos blokavimas taikomi visai programai, nepriklausomai "
            L"nuo monitorių pasirinkimo. Įjungus blokavimą, Windows užsklanda neleidžiama tik kol bent "
            L"viename monitoriuje matoma nepristabdyta animacija. Programa gali įdiegti ir pašalinti į ją "
            L"įtrauktą užsklandą.\r\n\r\nEKRANO KOPIJOS IR ĮRAŠYMAS\r\nĮrašymo nuostatose pasirinkite "
            L"Viewport arba TV. Viewport išsaugo monitoriaus matmenis ir atnaujinimo dažnį iki 60 kadrų per "
            L"sekundę. TV siūlo 1920 × 1080, 1440 × 1080 arba 1280 × 720 išvestį 16:9 santykiu bei 50, 25, "
            L"59.94 (60000/1001) arba 29.97 (30000/1001) kadrų per sekundę. TV vaizdas progresinis, BT.709, "
            L"riboto diapazono ir 4:2:0 spalvų diskretizavimo. Vaizdo proporcijos išlieka, užpildymo juostos "
            L"juodos. OK pritaiko nuostatas kitam įrašui, Atšaukti arba Esc atmeta nepatvirtintus "
            L"pakeitimus. Įrašymo, žinyno ir informacijos langai neblokuoja kitų langų ir gali būti "
            L"sumažinti. Tab ir Shift+Tab keičia įvesties vietą, Enter paspaudžia aktyvų mygtuką, Esc uždaro "
            L"aktyvų papildomą langą.\r\n\r\nSISTEMOS REIKALAVIMAI\r\nWindows 7–11 palaiko visas funkcijas. "
            L"Windows Vista SP2 būtina įdiegti naujinimus KB971512 ir KB2117917; MP4 įrašymas Vistoje "
            L"neveikia. Reikalingas Direct3D 11 palaikymas, o MP4 įrašymui Media Foundation ir H.264 "
            L"koduotuvas. Sąsaja ir dokumentacija pateikiamos 36 kalbomis."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACIJA IR NUOSTATOS\r\nSpaceFlight: Begalinis banguojantis paviršius; Tolimas skrydis — "
            L"kintantis paviršius; Skrydis per gravitacijos iškreiptą erdvę. Kiekvienam monitoriui "
            L"pasirinkite vieną animaciją. Tekstūros langelis perjungia tekstūruotą paviršių ir vielinį "
            L"modelį. Laisvas kameros sukimasis lėtai keičia žiūrėjimo kryptį visose trijose dimensijose. "
            L"Pauzės ir apsisukimai prideda atsitiktinį lėtėjimą, pauzes ir sukimosi krypties keitimą; "
            L"skrydis pirmyn tęsiasi. Galimas 0–1600% greitis. Kiekvienas monitorius turi nepriklausomą "
            L"atsitiktinę sceną, atvaizduojamą jo atnaujinimo dažniu. Pagrindinę, užpildančią, aplinkos ir "
            L"kontūrinę šviesą galima atskirai įjungti pasirinktiems ekranams. Apšvietimas taikomas tik "
            L"tekstūruotiems paviršiams. Abiejose paviršių animacijose galima pasirinkti plokštumą, bangas "
            L"arba piltuvą. Piltuvas traukia kamerą į vidų žemyn besisukančia spirale. Skrydis per "
            L"gravitacijos iškreiptą erdvę rodo trimatį karkasinį tinklą. Tekstūros, paviršiaus formos ir "
            L"apšvietimo parinktys taikomos tik dviem paviršių animacijoms.\r\n\r\nMONITORIAI\r\nMonitorių "
            L"sąraše pasirinkite vieną ar kelias eilutes. Ctrl+A pasirenka visas, o Ctrl ir Shift leidžia "
            L"keisti pasirinkimą. Animacijos valdikliai ir slankikliai keičia tik pasirinktų monitorių "
            L"nuostatas. Eilutės pasirinkimas nėra tas pats, kas animacijos išvesties įjungimas jos "
            L"žymimuoju langeliu. Pasirinkimas atskirai įsimenamas programai ir užsklandai. Jei buvo "
            L"pasirinkti visi monitoriai, į pasirinkimą įtraukiami ir naujai prijungti monitoriai. "
            L"Skirtingas pasirinktų monitorių reikšmes rodo neapibrėžta žymimųjų langelių būsena ir taškinis "
            L"raštas ant parinkčių mygtukų, slankiklių rankenėlių bei mygtukų „Įjungti visus“ ir „Išjungti "
            L"visus“. Slankiklių užrašuose vietoj bendros reikšmės rodomas brūkšnys. Pakeitus parinktį arba "
            L"spustelėjus slankiklį, ta reikšmė pritaikoma visiems pasirinktiems monitoriams.\r\n\r\n"
            L"PERŽIŪRA IR VALDYMAS\r\nNaudokite SpaceFlight.scr kaip Windows ekrano užsklandą. Jos nuostatos "
            L"atskiros nuo programos. Viso ekrano peržiūra leidžia jas keisti vykstant animacijai. OK "
            L"išsaugo, Atšaukti arba Esc atmeta pakeitimus. Užsklandą užbaikite klavišu arba pajudindami "
            L"pelę.\r\n\r\nSISTEMOS REIKALAVIMAI\r\nWindows 7–11 palaiko visas funkcijas. Windows Vista SP2 "
            L"būtina įdiegti naujinimus KB971512 ir KB2117917. Reikalingas Direct3D 11 palaikymas."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Plokštuma" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Bangos" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Piltuvas" },
    }),
    DefineLanguage(LANG_LV, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Latviešu" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — vadība" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"SpaceFlight iestatījumi" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Bezgalīga viļņojoša virsma" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Tāls lidojums — mainīga virsma" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT,
            L"Lidojums cauri gravitācijas izliektai telpai"
        },
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
            L"Aizveriet SpaceFlight iestatījumu logu un atkārtojiet atinstalēšanu."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Aizveriet Windows ekrānsaudzētāja iestatījumu logu un atkārtojiet atinstalēšanu."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Aizveriet ekrānsaudzētāju vai pilnekrāna priekšskatījumu ar Esc vai peles kustību un "
            L"atkārtojiet atinstalēšanu."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Aparatūras paātrināts lidojums virs viļņojošas virsmas." },
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
            L"ANIMĀCIJA UN IESTATĪJUMI\r\nSpaceFlight: Bezgalīga viļņojoša virsma; Tāls lidojums — mainīga "
            L"virsma; Lidojums cauri gravitācijas izliektai telpai. Katram monitoram izvēlieties tieši vienu "
            L"animāciju. Tekstūras rūtiņa pārslēdz teksturētu virsmu un stiepļu modeli. Brīva kameras "
            L"rotācija lēnām maina skatiena virzienu visās trijās dimensijās. Pauzes un virzienmaiņa "
            L"pievieno nejaušu palēninājumu, pauzes un rotācijas virziena maiņu; lidojums uz priekšu "
            L"turpinās. Pieejams ātrums 0–1600%. Katram monitoram ir neatkarīga nejauša aina, ko renderē tā "
            L"atsvaidzināšanas frekvencē. Pamata, aizpildošo, apkārtējo un kontūru gaismu atlasītajiem "
            L"monitoriem var ieslēgt neatkarīgi. Apgaismojums attiecas tikai uz teksturētām virsmām. Abās "
            L"virsmu animācijās var izvēlēties plakni, viļņus vai piltuvi. Piltuve ievelk kameru iekšup pa "
            L"lejupejošu spirāli. Lidojums cauri gravitācijas izliektai telpai rāda trīsdimensiju stiepļu "
            L"režģi. Tekstūras, virsmas formas un apgaismojuma iestatījumi attiecas tikai uz abām virsmu "
            L"animācijām.\r\n\r\nMONITORI\r\nMonitoru sarakstā atlasiet vienu vai vairākas rindas. Ctrl+A "
            L"atlasa visas, bet Ctrl un Shift ļauj mainīt atlasi. Animācijas vadīklas un slīdņi maina tikai "
            L"atlasīto monitoru iestatījumus. Rindas atlasīšana nav tas pats, kas animācijas izvades "
            L"ieslēgšana ar izvēles rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un ekrānsaudzētājam. Ja "
            L"bija atlasīti visi monitori, atlasē iekļauj arī jaunpievienotos monitorus. Atšķirīgas vērtības "
            L"atlasītajos monitoros norāda nenoteikts izvēles rūtiņu stāvoklis un punktots raksts uz "
            L"radiopogām, slīdņu rokturiem un pogām „Ieslēgt visu” un „Izslēgt visu”. Slīdņu etiķetēs "
            L"kopīgas vērtības vietā redzama domuzīme. Mainot iespēju vai noklikšķinot uz slīdņa, šī vērtība "
            L"tiek piemērota visiem atlasītajiem monitoriem.\r\n\r\nLIETOŠANA\r\nPalaidiet SpaceFlight.exe. "
            L"Iestatījumi tiek saglabāti nepārtraukti, un darbojas tikai viena lietotnes instance. Monitora "
            L"rūtiņa vai dubultklikšķis uz rindas ieslēdz vai izslēdz tā animācijas izvadi. Animāciju var "
            L"pauzēt un turpināt. PNG un MP4 uzņem pirmo aktīvo animācijas monitoru, nevis visu monitoru "
            L"kopējo attēlu. Ierakstīšanas laikā nevar izslēgt ierakstāmā monitora animācijas izvadi; "
            L"aizverot lietotni ieraksta laikā, nepieciešams apstiprinājums. Pauze un ekrānsaudzētāja "
            L"bloķēšana attiecas uz visu lietotni neatkarīgi no monitoru atlases. Ja bloķēšana ir ieslēgta, "
            L"Windows ekrānsaudzētājs tiek bloķēts tikai tik ilgi, kamēr vismaz vienā monitorā ir redzama "
            L"nepauzēta animācija. Lietotne var instalēt vai atinstalēt tajā iebūvēto ekrānsaudzētāju.\r\n\r"
            L"\nEKRĀNUZŅĒMUMI UN IERAKSTĪŠANA\r\nIeraksta iestatījumos izvēlieties Viewport vai TV. Viewport "
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
            L"ANIMĀCIJA UN IESTATĪJUMI\r\nSpaceFlight: Bezgalīga viļņojoša virsma; Tāls lidojums — mainīga "
            L"virsma; Lidojums cauri gravitācijas izliektai telpai. Katram monitoram izvēlieties tieši vienu "
            L"animāciju. Tekstūras rūtiņa pārslēdz teksturētu virsmu un stiepļu modeli. Brīva kameras "
            L"rotācija lēnām maina skatiena virzienu visās trijās dimensijās. Pauzes un virzienmaiņa "
            L"pievieno nejaušu palēninājumu, pauzes un rotācijas virziena maiņu; lidojums uz priekšu "
            L"turpinās. Pieejams ātrums 0–1600%. Katram monitoram ir neatkarīga nejauša aina, ko renderē tā "
            L"atsvaidzināšanas frekvencē. Pamata, aizpildošo, apkārtējo un kontūru gaismu atlasītajiem "
            L"monitoriem var ieslēgt neatkarīgi. Apgaismojums attiecas tikai uz teksturētām virsmām. Abās "
            L"virsmu animācijās var izvēlēties plakni, viļņus vai piltuvi. Piltuve ievelk kameru iekšup pa "
            L"lejupejošu spirāli. Lidojums cauri gravitācijas izliektai telpai rāda trīsdimensiju stiepļu "
            L"režģi. Tekstūras, virsmas formas un apgaismojuma iestatījumi attiecas tikai uz abām virsmu "
            L"animācijām.\r\n\r\nMONITORI\r\nMonitoru sarakstā atlasiet vienu vai vairākas rindas. Ctrl+A "
            L"atlasa visas, bet Ctrl un Shift ļauj mainīt atlasi. Animācijas vadīklas un slīdņi maina tikai "
            L"atlasīto monitoru iestatījumus. Rindas atlasīšana nav tas pats, kas animācijas izvades "
            L"ieslēgšana ar izvēles rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un ekrānsaudzētājam. Ja "
            L"bija atlasīti visi monitori, atlasē iekļauj arī jaunpievienotos monitorus. Atšķirīgas vērtības "
            L"atlasītajos monitoros norāda nenoteikts izvēles rūtiņu stāvoklis un punktots raksts uz "
            L"radiopogām, slīdņu rokturiem un pogām „Ieslēgt visu” un „Izslēgt visu”. Slīdņu etiķetēs "
            L"kopīgas vērtības vietā redzama domuzīme. Mainot iespēju vai noklikšķinot uz slīdņa, šī vērtība "
            L"tiek piemērota visiem atlasītajiem monitoriem.\r\n\r\nPRIEKŠSKATĪJUMS UN LIETOŠANA\r\n"
            L"Izmantojiet SpaceFlight.scr kā Windows ekrānsaudzētāju. Tā iestatījumi ir atsevišķi no "
            L"lietotnes. Pilnekrāna priekšskatījums ļauj tos mainīt animācijas darbības laikā. OK saglabā, "
            L"Atcelt vai Esc atmet izmaiņas. Pilnekrāna ekrānsaudzētāju aizveriet ar taustiņu vai peles "
            L"kustību.\r\n\r\nSISTĒMAS PRASĪBAS\r\nWindows 7–11 atbalsta visas funkcijas. Windows Vista SP2 "
            L"jāinstalē atjauninājumi KB971512 un KB2117917. Nepieciešams Direct3D 11 atbalsts."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Plakne" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Viļņi" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Piltuve" },
    }),
    DefineLanguage(LANG_HU, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Magyar" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — vezérlés" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"SpaceFlight beállításai" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Végtelen hullámzó felület" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Távolsági repülés — változó felület" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Repülés gravitációsan görbült térben" },
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
            L"Zárja be a SpaceFlight beállítási ablakát, majd próbálja újra az eltávolítást."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zárja be a Windows képernyőkímélő-beállításait, majd próbálja újra az eltávolítást."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Lépjen ki a képernyőkímélőből vagy a teljes képernyős előnézetből az Esc billentyűvel vagy az "
            L"egér mozgatásával, majd próbálja újra."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardveresen gyorsított repülés hullámzó felület felett." },
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
            L"ANIMÁCIÓ ÉS BEÁLLÍTÁSOK\r\nSpaceFlight: Végtelen hullámzó felület; Távolsági repülés — változó "
            L"felület; Repülés gravitációsan görbült térben. Monitoronként pontosan egy animáció "
            L"választható. A Textúra jelölőnégyzet a textúrázott felület és a drótváz között vált. A kamera "
            L"szabad forgása lassan változtatja a nézetet mindhárom dimenzióban. A Szünetek és irányváltás "
            L"véletlenszerű lassításokat, szüneteket és forgásirányváltásokat ad hozzá; az előrehaladás "
            L"folytatódik. A sebesség 0–1600%. Minden monitor önálló véletlenszerű jelenetet kap, saját "
            L"frissítési gyakoriságához igazodó megjelenítéssel. A főfény, a derítőfény, a környezeti fény "
            L"és a peremfény külön kapcsolható a kijelölt monitorokon. A világítás csak a textúrázott "
            L"felületekre vonatkozik. Mindkét felületanimációnál sík, hullámzás vagy tölcsér választható. A "
            L"tölcsér lefelé haladó spirál mentén húzza befelé a kamerát. A gravitációsan görbült térben "
            L"végzett repülés háromdimenziós drótvázrácsot jelenít meg. A textúra, a felület alakja és a "
            L"világítás beállításai csak a két felületanimációra vonatkoznak.\r\n\r\nMONITOROK\r\nJelöljön "
            L"ki egy vagy több sort a monitorok listájában. A Ctrl+A mindet kijelöli; a Ctrl és a Shift "
            L"módosítja a kijelölést. Az animáció vezérlői és csúszkái csak a kijelölt monitorok "
            L"beállításait változtatják. A sor kijelölése és az animációs kimenet jelölőnégyzetes "
            L"engedélyezése külön művelet. A kijelölést az alkalmazás és a képernyőkímélő külön megjegyzi. "
            L"Ha korábban minden monitor ki volt jelölve, az újonnan csatlakoztatott monitorok is bekerülnek "
            L"a kijelölésbe. A kijelölt monitorok eltérő értékeit a jelölőnégyzetek határozatlan állapota, "
            L"valamint a választógombok, a csúszkafogantyúk és az „Mind bekapcsolása” és „Mind kikapcsolása” "
            L"gombok pontozása jelzi. A csúszkák felirata közös érték helyett gondolatjelet mutat. Egy "
            L"beállítás módosítása vagy a csúszkára kattintás az adott értéket minden kijelölt monitorra "
            L"alkalmazza.\r\n\r\nKEZELÉS\r\nIndítsa el a SpaceFlight.exe fájlt. A beállítások folyamatosan "
            L"mentődnek, és csak egy alkalmazáspéldány fut. A monitor jelölőnégyzete vagy a sorra történő "
            L"dupla kattintás kapcsolja az animációs kimenetet. Az animáció szüneteltethető és folytatható. "
            L"A PNG és az MP4 az első aktív animációs monitort rögzíti, nem az összes monitor egyesített "
            L"képét. A rögzített monitor animációs kimenete felvétel közben nem kapcsolható ki; az "
            L"alkalmazás bezárásához ekkor megerősítés szükséges. A szüneteltetés és a képernyőkímélő "
            L"tiltása a teljes alkalmazásra vonatkozik, a monitorok kijelölésétől függetlenül. Bekapcsolt "
            L"tiltás esetén a Windows képernyőkímélője csak addig nem indul el, amíg legalább egy monitoron "
            L"látható, nem szünetelő animáció fut. Az alkalmazás telepítheti és eltávolíthatja a beágyazott "
            L"képernyőkímélőt.\r\n\r\nKÉPERNYŐKÉPEK ÉS FELVÉTEL\r\nA felvételi beállításoknál Viewport vagy "
            L"TV választható. A Viewport megőrzi a monitor képméretét és frissítési gyakoriságát, legfeljebb "
            L"60 képkocka/másodpercig. A TV felbontása 1920 × 1080, 1440 × 1080 vagy 1280 × 720, képaránya "
            L"16:9; sebessége 50, 25, 59.94 (60000/1001) vagy 29.97 (30000/1001) képkocka/másodperc. A TV "
            L"videó progresszív BT.709, korlátozott tartománnyal és 4:2:0 színmintavételezéssel. A kép "
            L"arányai megmaradnak, a kitöltősávok feketék. Az OK a következő felvételhez menti a választást; "
            L"a Mégse vagy Esc elveti a nem jóváhagyott módosításokat. A felvételi beállítások, a Súgó és a "
            L"Névjegy nem blokkolja a többi ablakot és kis méretűre állítható. A Tab és Shift+Tab mozgatja a "
            L"fókuszt, az Enter aktiválja a fókuszban levő gombot, az Esc bezárja az aktív kiegészítő "
            L"ablakot.\r\n\r\nRENDSZERKÖVETELMÉNYEK\r\nA Windows 7–11 minden funkciót támogat. Windows Vista "
            L"SP2 alatt telepíteni kell a KB971512 és KB2117917 frissítést; az MP4-felvétel Vistán nem "
            L"működik. Direct3D 11 támogatás szükséges, az MP4-hez Media Foundation és H.264-kódoló is kell. "
            L"A kezelőfelület és a dokumentáció 36 nyelven érhető el."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMÁCIÓ ÉS BEÁLLÍTÁSOK\r\nSpaceFlight: Végtelen hullámzó felület; Távolsági repülés — változó "
            L"felület; Repülés gravitációsan görbült térben. Monitoronként pontosan egy animáció "
            L"választható. A Textúra jelölőnégyzet a textúrázott felület és a drótváz között vált. A kamera "
            L"szabad forgása lassan változtatja a nézetet mindhárom dimenzióban. A Szünetek és irányváltás "
            L"véletlenszerű lassításokat, szüneteket és forgásirányváltásokat ad hozzá; az előrehaladás "
            L"folytatódik. A sebesség 0–1600%. Minden monitor önálló véletlenszerű jelenetet kap, saját "
            L"frissítési gyakoriságához igazodó megjelenítéssel. A főfény, a derítőfény, a környezeti fény "
            L"és a peremfény külön kapcsolható a kijelölt monitorokon. A világítás csak a textúrázott "
            L"felületekre vonatkozik. Mindkét felületanimációnál sík, hullámzás vagy tölcsér választható. A "
            L"tölcsér lefelé haladó spirál mentén húzza befelé a kamerát. A gravitációsan görbült térben "
            L"végzett repülés háromdimenziós drótvázrácsot jelenít meg. A textúra, a felület alakja és a "
            L"világítás beállításai csak a két felületanimációra vonatkoznak.\r\n\r\nMONITOROK\r\nJelöljön "
            L"ki egy vagy több sort a monitorok listájában. A Ctrl+A mindet kijelöli; a Ctrl és a Shift "
            L"módosítja a kijelölést. Az animáció vezérlői és csúszkái csak a kijelölt monitorok "
            L"beállításait változtatják. A sor kijelölése és az animációs kimenet jelölőnégyzetes "
            L"engedélyezése külön művelet. A kijelölést az alkalmazás és a képernyőkímélő külön megjegyzi. "
            L"Ha korábban minden monitor ki volt jelölve, az újonnan csatlakoztatott monitorok is bekerülnek "
            L"a kijelölésbe. A kijelölt monitorok eltérő értékeit a jelölőnégyzetek határozatlan állapota, "
            L"valamint a választógombok, a csúszkafogantyúk és az „Mind bekapcsolása” és „Mind kikapcsolása” "
            L"gombok pontozása jelzi. A csúszkák felirata közös érték helyett gondolatjelet mutat. Egy "
            L"beállítás módosítása vagy a csúszkára kattintás az adott értéket minden kijelölt monitorra "
            L"alkalmazza.\r\n\r\nELŐNÉZET ÉS KEZELÉS\r\nA SpaceFlight.scr Windows-képernyőkímélőként "
            L"használható, az alkalmazástól külön beállításokkal. A teljes képernyős előnézetben élőben "
            L"módosíthatók a beállítások. Az OK ment, a Mégse vagy Esc elveti a módosításokat. A teljes "
            L"képernyős képernyőkímélő billentyűvel vagy egérmozgással zárható be.\r\n\r\n"
            L"RENDSZERKÖVETELMÉNYEK\r\nA Windows 7–11 minden funkciót támogat. Windows Vista SP2 alatt "
            L"telepíteni kell a KB971512 és KB2117917 frissítést. Direct3D 11 támogatás szükséges."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Sík" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Hullámzás" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Tölcsér" },
    }),
    DefineLanguage(LANG_MT, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Malti" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — kontrolli" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Issettjar ta’ SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Wiċċ infinit li jimmewweġ" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Titjira fit-tul — wiċċ li jinbidel" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Titjira fi spazju mgħawweġ mill-gravità" },
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
            L"Agħlaq it-tieqa tal-issettjar ta’ SpaceFlight u erġa’ pprova tneħħih."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Agħlaq it-tieqa tal-issettjar tal-iscreen saver ta’ Windows u erġa’ pprova tneħħih."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Agħlaq l-iscreen saver jew il-previżjoni fuq skrin sħiħ b’Esc jew billi ċċaqlaq il-maws u "
            L"erġa’ pprova."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Titjira fuq wiċċ li jimmewweġ aċċellerata bil-ħardwer." },
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
            L"ANIMAZZJONI U ISSETTJAR\r\nSpaceFlight: Wiċċ infinit li jimmewweġ; Titjira fit-tul — wiċċ li "
            L"jinbidel; Titjira fi spazju mgħawweġ mill-gravità. Agħżel animazzjoni waħda biss għal kull "
            L"moniter. Nisġa taqleb bejn wiċċ b’nisġa u mudell bil-wireframe. Ir-rotazzjoni libera "
            L"tal-kamera tbiddel id-direzzjoni tal-ħarsa bil-mod fit-tliet dimensjonijiet. L-għażla Pawżi u "
            L"bidliet fid-direzzjoni żżid deċelerazzjonijiet, pawżi u treġġigħ lura tar-rotazzjoni b’mod "
            L"każwali; it-titjira ’l quddiem tkompli. Il-veloċità hija 0–1600%. Kull moniter għandu xena "
            L"każwali indipendenti li tintwera bir-rata ta’ aġġornament tiegħu. Id-dawl ewlieni, id-dawl ta’ "
            L"mili, id-dawl ambjentali u d-dawl tal-kontorn jistgħu jinxtegħlu separatament għall-iskrins "
            L"magħżula. Id-dawl japplika biss għall-uċuħ b’nisġa. Iż-żewġ animazzjonijiet tal-uċuħ joffru "
            L"Pjan, Mewġ jew Lembut. Il-lembut jiġbed il-kamera ’l ġewwa tul spirali nieżla. It-titjira fi "
            L"spazju mgħawweġ mill-gravità turi gradilja tridimensjonali ta’ linji. L-għażliet tan-nisġa, "
            L"tal-forma tal-wiċċ u tad-dawl japplikaw biss għaż-żewġ animazzjonijiet tal-uċuħ.\r\n\r\n"
            L"SKRINS\r\nAgħżel ringiela waħda jew aktar fil-lista tal-moniters. Ctrl+A jagħżilhom kollha; "
            L"Ctrl u Shift ibiddlu l-għażla. Il-kontrolli u s-sliders tal-animazzjoni jibdlu biss "
            L"l-issettjar tal-moniters magħżula. L-għażla ta’ ringiela hija differenti mill-attivazzjoni "
            L"tal-output permezz tal-kaxxa tal-marka. L-għażla tinżamm separatament għall-applikazzjoni u "
            L"għall-iscreen saver. Jekk il-moniters kollha kienu magħżula, il-moniters ġodda jiddaħħlu wkoll "
            L"fl-għażla. Valuri differenti fuq il-moniters magħżula jintwerew bi stat indeterminat tal-kaxxi "
            L"tal-marka u b’disinn bit-tikek fuq il-buttuni tar-radju, il-manki tas-sliders u l-buttuni "
            L"“Attiva kollox” u “Iddiżattiva kollox”. It-tikketti tas-sliders juru sing minflok valur "
            L"komuni. Meta tibdel għażla jew tikklikkja slider, dak il-valur jiġi applikat għall-moniters "
            L"magħżula kollha.\r\n\r\nKONTROLLI\r\nĦaddem SpaceFlight.exe. L-issettjar jiġi ssejvjat "
            L"kontinwament u taħdem istanza waħda biss. Il-kaxxa tal-moniter jew klikk doppja fuq "
            L"ir-ringiela tattiva jew tiddiżattiva l-output tal-animazzjoni. Tista’ tissospendi u tkompli "
            L"l-animazzjoni. PNG u MP4 jaqbdu l-ewwel moniter tal-animazzjoni attiv, mhux immaġni magħquda "
            L"tal-moniters kollha. L-output tal-animazzjoni tal-moniter li qed jiġi rreġistrat ma jistax "
            L"jiġi diżattivat waqt ir-reġistrazzjoni; l-għeluq tal-applikazzjoni waqt reġistrazzjoni jeħtieġ "
            L"konferma. Is-sospensjoni u l-imblukkar tal-iscreen saver japplikaw għall-applikazzjoni kollha, "
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
            L"ANIMAZZJONI U ISSETTJAR\r\nSpaceFlight: Wiċċ infinit li jimmewweġ; Titjira fit-tul — wiċċ li "
            L"jinbidel; Titjira fi spazju mgħawweġ mill-gravità. Agħżel animazzjoni waħda biss għal kull "
            L"moniter. Nisġa taqleb bejn wiċċ b’nisġa u mudell bil-wireframe. Ir-rotazzjoni libera "
            L"tal-kamera tbiddel id-direzzjoni tal-ħarsa bil-mod fit-tliet dimensjonijiet. L-għażla Pawżi u "
            L"bidliet fid-direzzjoni żżid deċelerazzjonijiet, pawżi u treġġigħ lura tar-rotazzjoni b’mod "
            L"każwali; it-titjira ’l quddiem tkompli. Il-veloċità hija 0–1600%. Kull moniter għandu xena "
            L"każwali indipendenti li tintwera bir-rata ta’ aġġornament tiegħu. Id-dawl ewlieni, id-dawl ta’ "
            L"mili, id-dawl ambjentali u d-dawl tal-kontorn jistgħu jinxtegħlu separatament għall-iskrins "
            L"magħżula. Id-dawl japplika biss għall-uċuħ b’nisġa. Iż-żewġ animazzjonijiet tal-uċuħ joffru "
            L"Pjan, Mewġ jew Lembut. Il-lembut jiġbed il-kamera ’l ġewwa tul spirali nieżla. It-titjira fi "
            L"spazju mgħawweġ mill-gravità turi gradilja tridimensjonali ta’ linji. L-għażliet tan-nisġa, "
            L"tal-forma tal-wiċċ u tad-dawl japplikaw biss għaż-żewġ animazzjonijiet tal-uċuħ.\r\n\r\n"
            L"SKRINS\r\nAgħżel ringiela waħda jew aktar fil-lista tal-moniters. Ctrl+A jagħżilhom kollha; "
            L"Ctrl u Shift ibiddlu l-għażla. Il-kontrolli u s-sliders tal-animazzjoni jibdlu biss "
            L"l-issettjar tal-moniters magħżula. L-għażla ta’ ringiela hija differenti mill-attivazzjoni "
            L"tal-output permezz tal-kaxxa tal-marka. L-għażla tinżamm separatament għall-applikazzjoni u "
            L"għall-iscreen saver. Jekk il-moniters kollha kienu magħżula, il-moniters ġodda jiddaħħlu wkoll "
            L"fl-għażla. Valuri differenti fuq il-moniters magħżula jintwerew bi stat indeterminat tal-kaxxi "
            L"tal-marka u b’disinn bit-tikek fuq il-buttuni tar-radju, il-manki tas-sliders u l-buttuni "
            L"“Attiva kollox” u “Iddiżattiva kollox”. It-tikketti tas-sliders juru sing minflok valur "
            L"komuni. Meta tibdel għażla jew tikklikkja slider, dak il-valur jiġi applikat għall-moniters "
            L"magħżula kollha.\r\n\r\nPREVIŻJONI U KONTROLLI\r\nUża SpaceFlight.scr bħala screen saver ta’ "
            L"Windows. L-issettjar tiegħu huwa separat minn dak tal-applikazzjoni. Il-previżjoni fuq skrin "
            L"sħiħ tippermetti bidliet waqt l-animazzjoni. OK isalva u Ikkanċella jew Esc jarmi l-bidliet. "
            L"Oħroġ mill-iscreen saver bi kwalunkwe tast jew billi ċċaqlaq il-maws.\r\n\r\nREKWIŻITI "
            L"TAS-SISTEMA\r\nWindows 7–11 jappoġġja l-funzjonijiet kollha. Fuq Windows Vista SP2 għandhom "
            L"jiġu installati l-aġġornamenti KB971512 u KB2117917. Huwa meħtieġ Direct3D 11."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Pjan" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Mewġ" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Lembut" },
    }),
    DefineLanguage(LANG_NL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Nederlands" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — bediening" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Instellingen van SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Oneindig golvend oppervlak" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Langeafstandsvlucht — veranderend oppervlak" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Vlucht door gravitatiegekromde ruimte" },
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
            L"Sluit de instellingen van SpaceFlight en probeer het verwijderen opnieuw."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Sluit de instellingen voor schermbeveiliging van Windows en probeer het verwijderen opnieuw."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Sluit de schermbeveiliging of het schermvullende voorbeeld met Esc of door de muis te bewegen "
            L"en probeer het opnieuw."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardwareversnelde vlucht boven een golvend oppervlak." },
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
            L"ANIMATIE EN INSTELLINGEN\r\nSpaceFlight: Oneindig golvend oppervlak; Langeafstandsvlucht — "
            L"veranderend oppervlak; Vlucht door gravitatiegekromde ruimte. Kies precies één animatie per "
            L"beeldscherm. Textuur schakelt tussen een getextureerd oppervlak en een draadmodel. Vrije "
            L"camerarotatie verandert de kijkrichting langzaam in alle drie dimensies. De optie Pauzes en "
            L"omkeren voegt willekeurige vertragingen, pauzes en omkeringen van de rotatie toe; de "
            L"voorwaartse vlucht gaat door. De snelheid is instelbaar op 0–1600%. Elk beeldscherm heeft een "
            L"onafhankelijke willekeurige scène en wordt op zijn eigen vernieuwingsfrequentie aangestuurd. "
            L"Hoofdlicht, invullicht, omgevingslicht en randlicht kunnen onafhankelijk worden geschakeld "
            L"voor de geselecteerde beeldschermen. De verlichting geldt alleen voor oppervlakken met "
            L"textuur. De twee oppervlakteanimaties bieden Vlak, Golven of Trechter. De trechter trekt de "
            L"camera langs een dalende spiraal naar binnen. De vlucht door gravitatiegekromde ruimte toont "
            L"een driedimensionaal draadrooster. De opties voor textuur, oppervlaktevorm en verlichting "
            L"gelden alleen voor de twee oppervlakteanimaties.\r\n\r\nBEELDSCHERMEN\r\nSelecteer één of meer "
            L"beeldschermrijen in de lijst. Ctrl+A selecteert alles; met Ctrl en Shift past u de selectie "
            L"aan. Animatieknoppen en schuifregelaars wijzigen alleen de instellingen van de geselecteerde "
            L"beeldschermen. Een rij selecteren is iets anders dan de animatie-uitvoer inschakelen met het "
            L"selectievakje. De selectie wordt apart onthouden voor de toepassing en de schermbeveiliging. "
            L"Als alle beeldschermen waren geselecteerd, worden nieuw aangesloten beeldschermen ook "
            L"geselecteerd. Verschillende waarden op geselecteerde beeldschermen worden aangegeven door "
            L"selectievakjes in onbepaalde toestand en een stippelpatroon op keuzerondjes, schuifknoppen en "
            L"de knoppen ‘Alles inschakelen’ en ‘Alles uitschakelen’. De labels van schuifregelaars tonen "
            L"een streepje in plaats van een gemeenschappelijke waarde. Een optie wijzigen of op een "
            L"schuifregelaar klikken past die waarde toe op alle geselecteerde beeldschermen.\r\n\r\n"
            L"BEDIENING\r\nStart SpaceFlight.exe. Instellingen worden doorlopend opgeslagen en er draait "
            L"slechts één exemplaar van de toepassing. Het selectievakje of een dubbelklik op de "
            L"beeldschermrij schakelt de animatie-uitvoer in of uit. U kunt de animatie pauzeren en "
            L"hervatten. PNG en MP4 leggen het eerste actieve animatiebeeldscherm vast, niet een "
            L"gecombineerd beeld van alle schermen. De animatie-uitvoer van het opgenomen beeldscherm kan "
            L"tijdens de opname niet worden uitgeschakeld; afsluiten tijdens een opname vereist bevestiging. "
            L"Pauzeren en het blokkeren van de schermbeveiliging gelden voor de hele toepassing, ongeacht de "
            L"beeldschermselectie. Als blokkering is ingeschakeld, wordt de Windows-schermbeveiliging alleen "
            L"tegengehouden zolang op minstens één beeldscherm een zichtbare, niet-gepauzeerde animatie "
            L"draait. De toepassing kan de ingebouwde schermbeveiliging installeren of verwijderen.\r\n\r\n"
            L"SCHERMAFBEELDINGEN EN OPNAMEN\r\nKies Viewport of TV in de opname-instellingen. Viewport "
            L"behoudt de afmetingen en vernieuwingsfrequentie van het beeldscherm tot 60 frames per seconde. "
            L"TV biedt 1920 × 1080, 1440 × 1080 of 1280 × 720 met beeldverhouding 16:9 en 50, 25, 59.94 "
            L"(60000/1001) of 29.97 (30000/1001) frames per seconde. TV gebruikt progressieve BT.709-video "
            L"met beperkt bereik en 4:2:0-kleursubsampling. De beeldverhouding blijft behouden en "
            L"opvulbalken zijn zwart. OK bewaart de opties voor de volgende opname; Annuleren of Esc "
            L"verwerpt onbevestigde wijzigingen. Opname-instellingen, Help en Info blokkeren andere vensters "
            L"niet en kunnen worden geminimaliseerd. Tab en Shift+Tab verplaatsen de focus, Enter activeert "
            L"de knop met focus en Esc sluit het actieve hulpvenster.\r\n\r\nSYSTEEMVEREISTEN\r\nWindows "
            L"7–11 ondersteunt alle functies. Voor Windows Vista SP2 moet u updates KB971512 en KB2117917 "
            L"installeren; MP4-opname werkt niet op Vista. Direct3D 11-ondersteuning is vereist; voor MP4 "
            L"zijn ook Media Foundation en een H.264-encoder nodig. Interface en documentatie zijn "
            L"beschikbaar in 36 talen."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATIE EN INSTELLINGEN\r\nSpaceFlight: Oneindig golvend oppervlak; Langeafstandsvlucht — "
            L"veranderend oppervlak; Vlucht door gravitatiegekromde ruimte. Kies precies één animatie per "
            L"beeldscherm. Textuur schakelt tussen een getextureerd oppervlak en een draadmodel. Vrije "
            L"camerarotatie verandert de kijkrichting langzaam in alle drie dimensies. De optie Pauzes en "
            L"omkeren voegt willekeurige vertragingen, pauzes en omkeringen van de rotatie toe; de "
            L"voorwaartse vlucht gaat door. De snelheid is instelbaar op 0–1600%. Elk beeldscherm heeft een "
            L"onafhankelijke willekeurige scène en wordt op zijn eigen vernieuwingsfrequentie aangestuurd. "
            L"Hoofdlicht, invullicht, omgevingslicht en randlicht kunnen onafhankelijk worden geschakeld "
            L"voor de geselecteerde beeldschermen. De verlichting geldt alleen voor oppervlakken met "
            L"textuur. De twee oppervlakteanimaties bieden Vlak, Golven of Trechter. De trechter trekt de "
            L"camera langs een dalende spiraal naar binnen. De vlucht door gravitatiegekromde ruimte toont "
            L"een driedimensionaal draadrooster. De opties voor textuur, oppervlaktevorm en verlichting "
            L"gelden alleen voor de twee oppervlakteanimaties.\r\n\r\nBEELDSCHERMEN\r\nSelecteer één of meer "
            L"beeldschermrijen in de lijst. Ctrl+A selecteert alles; met Ctrl en Shift past u de selectie "
            L"aan. Animatieknoppen en schuifregelaars wijzigen alleen de instellingen van de geselecteerde "
            L"beeldschermen. Een rij selecteren is iets anders dan de animatie-uitvoer inschakelen met het "
            L"selectievakje. De selectie wordt apart onthouden voor de toepassing en de schermbeveiliging. "
            L"Als alle beeldschermen waren geselecteerd, worden nieuw aangesloten beeldschermen ook "
            L"geselecteerd. Verschillende waarden op geselecteerde beeldschermen worden aangegeven door "
            L"selectievakjes in onbepaalde toestand en een stippelpatroon op keuzerondjes, schuifknoppen en "
            L"de knoppen ‘Alles inschakelen’ en ‘Alles uitschakelen’. De labels van schuifregelaars tonen "
            L"een streepje in plaats van een gemeenschappelijke waarde. Een optie wijzigen of op een "
            L"schuifregelaar klikken past die waarde toe op alle geselecteerde beeldschermen.\r\n\r\n"
            L"VOORBEELD EN BEDIENING\r\nGebruik SpaceFlight.scr als Windows-schermbeveiliging met eigen "
            L"instellingen. Het schermvullende voorbeeld laat live aanpassingen toe. OK slaat wijzigingen "
            L"op; Annuleren of Esc verwerpt ze. Sluit de schermvullende schermbeveiliging met een toets of "
            L"een muisbeweging.\r\n\r\nSYSTEEMVEREISTEN\r\nWindows 7–11 ondersteunt alle functies. Voor "
            L"Windows Vista SP2 moet u updates KB971512 en KB2117917 installeren. Direct3D 11-ondersteuning "
            L"is vereist."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Vlak" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Golven" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Trechter" },
    }),
    DefineLanguage(LANG_RO, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Română" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — comenzi" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Setări SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Suprafață ondulată infinită" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Zbor la distanță — suprafață variabilă" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Zbor prin spațiul curbat gravitațional" },
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
            L"Închideți fereastra de setări SpaceFlight și încercați din nou dezinstalarea."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Închideți setările economizorului de ecran Windows și încercați din nou dezinstalarea."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Închideți economizorul sau previzualizarea pe tot ecranul cu Esc ori mișcând mouse-ul și "
            L"încercați din nou."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Zbor deasupra unei suprafețe ondulate accelerat hardware." },
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
            L"ANIMAȚIE ȘI SETĂRI\r\nSpaceFlight: Suprafață ondulată infinită; Zbor la distanță — suprafață "
            L"variabilă; Zbor prin spațiul curbat gravitațional. Alegeți exact o animație pentru fiecare "
            L"monitor. Textură comută între suprafața texturată și modelul de sârmă. Rotirea liberă a "
            L"camerei schimbă lent direcția privirii în toate cele trei dimensiuni. Pauze și inversări "
            L"adaugă încetiniri, pauze și inversări ale rotației la intervale aleatorii; zborul înainte "
            L"continuă. Viteza este 0–1600%. Fiecare monitor are o scenă aleatorie independentă, randată la "
            L"propria rată de reîmprospătare. Lumina principală, lumina de umplere, lumina ambiantă și "
            L"lumina de contur pot fi comutate separat pentru ecranele selectate. Iluminarea se aplică doar "
            L"suprafețelor texturate. Cele două animații de suprafețe oferă Plan, Ondulații sau Pâlnie. "
            L"Pâlnia atrage camera spre interior de-a lungul unei spirale descendente. Zborul prin spațiul "
            L"curbat gravitațional afișează o rețea tridimensională de linii. Opțiunile pentru textură, "
            L"forma suprafeței și iluminare se aplică numai celor două animații de suprafețe.\r\n\r\n"
            L"MONITOARE\r\nSelectați unul sau mai multe rânduri din lista monitoarelor. Ctrl+A le selectează "
            L"pe toate; Ctrl și Shift modifică selecția. Comenzile și glisoarele animației schimbă numai "
            L"setările monitoarelor selectate. Selectarea unui rând diferă de activarea ieșirii prin caseta "
            L"sa de selectare. Selecția este reținută separat pentru aplicație și economizor. Dacă erau "
            L"selectate toate monitoarele, sunt incluse și cele conectate ulterior. Valorile diferite de pe "
            L"monitoarele selectate sunt indicate prin starea nedeterminată a casetelor de selectare și un "
            L"model punctat pe butoanele radio, mânerele glisoarelor și butoanele „Activare toate” și "
            L"„Dezactivare toate”. Etichetele glisoarelor afișează o liniuță în locul unei valori comune. "
            L"Modificarea unei opțiuni sau clicul pe un glisor aplică acea valoare tuturor monitoarelor "
            L"selectate.\r\n\r\nCOMENZI\r\nRulați SpaceFlight.exe. Setările se salvează continuu și rulează "
            L"o singură instanță. Caseta monitorului sau un dublu clic pe rând activează ori dezactivează "
            L"ieșirea animației. Animația poate fi pusă în pauză și reluată. PNG și MP4 capturează primul "
            L"monitor de animație activ, nu imaginea combinată a tuturor monitoarelor. Ieșirea animației pe "
            L"monitorul înregistrat nu poate fi dezactivată în timpul înregistrării; închiderea aplicației "
            L"în timpul înregistrării necesită confirmare. Pauza și blocarea economizorului se aplică "
            L"întregii aplicații, indiferent de selecția monitoarelor. Când blocarea este activată, "
            L"economizorul Windows este împiedicat numai cât timp pe cel puțin un monitor este vizibilă o "
            L"animație care nu este în pauză. Aplicația poate instala sau dezinstala economizorul "
            L"încorporat.\r\n\r\nCAPTURI ȘI ÎNREGISTRARE\r\nÎn setările de înregistrare alegeți Viewport sau "
            L"TV. Viewport păstrează dimensiunile și rata de reîmprospătare a monitorului, până la 60 de "
            L"cadre pe secundă. TV oferă 1920 × 1080, 1440 × 1080 sau 1280 × 720 în 16:9, la 50, 25, 59.94 "
            L"(60000/1001) sau 29.97 (30000/1001) cadre pe secundă. Videoul TV este progresiv BT.709, cu "
            L"interval limitat și subeșantionare cromatică 4:2:0. Proporțiile imaginii se păstrează, iar "
            L"benzile de completare sunt negre. OK salvează opțiunile pentru următoarea înregistrare; "
            L"Anulare sau Esc renunță la schimbările neconfirmate. Ferestrele de înregistrare, ajutor și "
            L"informații nu blochează celelalte ferestre și pot fi minimizate. Tab și Shift+Tab mută "
            L"focalizarea, Enter activează butonul focalizat, iar Esc închide fereastra auxiliară activă.\r\n"
            L"\r\nCERINȚE DE SISTEM\r\nWindows 7–11 acceptă toate funcțiile. Pentru Windows Vista SP2 "
            L"trebuie instalate actualizările KB971512 și KB2117917; înregistrarea MP4 nu funcționează pe "
            L"Vista. Este necesar Direct3D 11, iar pentru MP4 și Media Foundation și un codificator H.264. "
            L"Interfața și documentația sunt disponibile în 36 de limbi."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMAȚIE ȘI SETĂRI\r\nSpaceFlight: Suprafață ondulată infinită; Zbor la distanță — suprafață "
            L"variabilă; Zbor prin spațiul curbat gravitațional. Alegeți exact o animație pentru fiecare "
            L"monitor. Textură comută între suprafața texturată și modelul de sârmă. Rotirea liberă a "
            L"camerei schimbă lent direcția privirii în toate cele trei dimensiuni. Pauze și inversări "
            L"adaugă încetiniri, pauze și inversări ale rotației la intervale aleatorii; zborul înainte "
            L"continuă. Viteza este 0–1600%. Fiecare monitor are o scenă aleatorie independentă, randată la "
            L"propria rată de reîmprospătare. Lumina principală, lumina de umplere, lumina ambiantă și "
            L"lumina de contur pot fi comutate separat pentru ecranele selectate. Iluminarea se aplică doar "
            L"suprafețelor texturate. Cele două animații de suprafețe oferă Plan, Ondulații sau Pâlnie. "
            L"Pâlnia atrage camera spre interior de-a lungul unei spirale descendente. Zborul prin spațiul "
            L"curbat gravitațional afișează o rețea tridimensională de linii. Opțiunile pentru textură, "
            L"forma suprafeței și iluminare se aplică numai celor două animații de suprafețe.\r\n\r\n"
            L"MONITOARE\r\nSelectați unul sau mai multe rânduri din lista monitoarelor. Ctrl+A le selectează "
            L"pe toate; Ctrl și Shift modifică selecția. Comenzile și glisoarele animației schimbă numai "
            L"setările monitoarelor selectate. Selectarea unui rând diferă de activarea ieșirii prin caseta "
            L"sa de selectare. Selecția este reținută separat pentru aplicație și economizor. Dacă erau "
            L"selectate toate monitoarele, sunt incluse și cele conectate ulterior. Valorile diferite de pe "
            L"monitoarele selectate sunt indicate prin starea nedeterminată a casetelor de selectare și un "
            L"model punctat pe butoanele radio, mânerele glisoarelor și butoanele „Activare toate” și "
            L"„Dezactivare toate”. Etichetele glisoarelor afișează o liniuță în locul unei valori comune. "
            L"Modificarea unei opțiuni sau clicul pe un glisor aplică acea valoare tuturor monitoarelor "
            L"selectate.\r\n\r\nPREVIZUALIZARE ȘI COMENZI\r\nFolosiți SpaceFlight.scr drept economizor de "
            L"ecran Windows, cu setări separate de aplicație. Previzualizarea pe tot ecranul permite "
            L"ajustări în timp real. OK salvează modificările; Anulare sau Esc le anulează. Ieșiți din "
            L"economizor apăsând o tastă sau mișcând mouse-ul.\r\n\r\nCERINȚE DE SISTEM\r\nWindows 7–11 "
            L"acceptă toate funcțiile. Pentru Windows Vista SP2 trebuie instalate actualizările KB971512 și "
            L"KB2117917. Este necesar Direct3D 11."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Plan" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Ondulații" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Pâlnie" },
    }),
    DefineLanguage(LANG_EL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Ελληνικά" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — χειρισμός" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Ρυθμίσεις SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Απέραντη κυματοειδής επιφάνεια" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Μακρινή πτήση — μεταβαλλόμενη επιφάνεια" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Πτήση σε χώρο καμπυλωμένο από τη βαρύτητα" },
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
            L"Κλείστε το παράθυρο ρυθμίσεων του SpaceFlight και δοκιμάστε ξανά την κατάργηση."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Κλείστε τις ρυθμίσεις προφύλαξης οθόνης των Windows και δοκιμάστε ξανά την κατάργηση."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Κλείστε την προφύλαξη ή την προεπισκόπηση πλήρους οθόνης με Esc ή κίνηση του ποντικιού και "
            L"δοκιμάστε ξανά."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Πτήση πάνω από κυματοειδή επιφάνεια με επιτάχυνση υλικού." },
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
            L"ΚΙΝΗΣΗ ΚΑΙ ΡΥΘΜΙΣΕΙΣ\r\nSpaceFlight: Απέραντη κυματοειδής επιφάνεια; Μακρινή πτήση — "
            L"μεταβαλλόμενη επιφάνεια; Πτήση σε χώρο καμπυλωμένο από τη βαρύτητα. Επιλέξτε ακριβώς μία "
            L"κίνηση ανά οθόνη. Η Υφή εναλλάσσει επιφάνεια με υφή και συρμάτινο μοντέλο. Η ελεύθερη "
            L"περιστροφή κάμερας αλλάζει αργά την κατεύθυνση θέασης και στις τρεις διαστάσεις. Οι Παύσεις "
            L"και αντιστροφές προσθέτουν τυχαίες επιβραδύνσεις, παύσεις και αντιστροφές περιστροφής, ενώ η "
            L"πτήση προς τα εμπρός συνεχίζεται. Η ταχύτητα είναι 0–1600%. Κάθε οθόνη διαθέτει ανεξάρτητη "
            L"τυχαία σκηνή που αποδίδεται στον δικό της ρυθμό ανανέωσης. Ο κύριος φωτισμός, ο φωτισμός "
            L"πλήρωσης, ο περιβάλλων φωτισμός και ο φωτισμός περιγράμματος ρυθμίζονται ανεξάρτητα για τις "
            L"επιλεγμένες οθόνες. Ο φωτισμός εφαρμόζεται μόνο σε επιφάνειες με υφή. Και οι δύο προσομοιώσεις "
            L"επιφανειών προσφέρουν Επίπεδο, Κυματισμό ή Χοάνη. Η χοάνη τραβά την κάμερα προς το εσωτερικό "
            L"ακολουθώντας καθοδική σπείρα. Η πτήση σε χώρο καμπυλωμένο από τη βαρύτητα εμφανίζει ένα "
            L"τρισδιάστατο συρμάτινο πλέγμα. Οι επιλογές υφής, σχήματος επιφάνειας και φωτισμού ισχύουν μόνο "
            L"για τις δύο προσομοιώσεις επιφανειών.\r\n\r\nΟΘΟΝΕΣ\r\nΕπιλέξτε μία ή περισσότερες γραμμές στη "
            L"λίστα οθονών. Το Ctrl+A επιλέγει όλες, ενώ τα Ctrl και Shift αλλάζουν την επιλογή. Τα "
            L"χειριστήρια και τα ρυθμιστικά της κίνησης αλλάζουν μόνο τις ρυθμίσεις των επιλεγμένων οθονών. "
            L"Η επιλογή γραμμής διαφέρει από την ενεργοποίηση εξόδου μέσω του πλαισίου ελέγχου της. Η "
            L"επιλογή αποθηκεύεται χωριστά για την εφαρμογή και την προφύλαξη. Αν είχαν επιλεγεί όλες οι "
            L"οθόνες, περιλαμβάνονται και όσες συνδεθούν αργότερα. Οι διαφορετικές τιμές στις επιλεγμένες "
            L"οθόνες υποδεικνύονται με απροσδιόριστη κατάσταση των πλαισίων ελέγχου και μοτίβο κουκκίδων στα "
            L"κουμπιά επιλογής, στις λαβές των ρυθμιστικών και στα κουμπιά «Ενεργοποίηση όλων» και "
            L"«Απενεργοποίηση όλων». Οι ετικέτες των ρυθμιστικών δείχνουν παύλα αντί για κοινή τιμή. Η "
            L"αλλαγή επιλογής ή το κλικ σε ρυθμιστικό εφαρμόζει την τιμή σε όλες τις επιλεγμένες οθόνες.\r\n"
            L"\r\nΧΕΙΡΙΣΜΟΣ\r\nΕκτελέστε το SpaceFlight.exe. Οι ρυθμίσεις αποθηκεύονται συνεχώς και "
            L"εκτελείται μόνο ένα αντίγραφο της εφαρμογής. Το πλαίσιο της οθόνης ή το διπλό κλικ στη γραμμή "
            L"ενεργοποιεί ή απενεργοποιεί την έξοδο κίνησης. Η κίνηση μπορεί να παύσει και να συνεχιστεί. Τα "
            L"PNG και MP4 καταγράφουν την πρώτη ενεργή οθόνη κίνησης, όχι συνδυασμένη εικόνα όλων των "
            L"οθονών. Η έξοδος κίνησης της καταγραφόμενης οθόνης δεν μπορεί να απενεργοποιηθεί κατά την "
            L"εγγραφή· το κλείσιμο της εφαρμογής κατά την εγγραφή απαιτεί επιβεβαίωση. Η παύση και η "
            L"αναστολή προφύλαξης οθόνης ισχύουν για όλη την εφαρμογή, ανεξάρτητα από την επιλογή οθονών. "
            L"Όταν η αναστολή είναι ενεργή, η προφύλαξη των Windows εμποδίζεται μόνο όσο υπάρχει ορατή "
            L"κίνηση χωρίς παύση σε τουλάχιστον μία οθόνη. Η εφαρμογή εγκαθιστά ή καταργεί την ενσωματωμένη "
            L"προφύλαξη.\r\n\r\nΣΤΙΓΜΙΟΤΥΠΑ ΚΑΙ ΕΓΓΡΑΦΗ\r\nΣτις ρυθμίσεις εγγραφής επιλέξτε Viewport ή TV. "
            L"Το Viewport διατηρεί διαστάσεις και ρυθμό ανανέωσης οθόνης έως 60 καρέ ανά δευτερόλεπτο. Το TV "
            L"προσφέρει 1920 × 1080, 1440 × 1080 ή 1280 × 720 σε 16:9, με 50, 25, 59.94 (60000/1001) ή 29.97 "
            L"(30000/1001) καρέ ανά δευτερόλεπτο. Το βίντεο TV είναι προοδευτικό BT.709 περιορισμένου εύρους "
            L"με υποδειγματοληψία χρώματος 4:2:0. Διατηρούνται οι αναλογίες εικόνας και οι συμπληρωματικές "
            L"λωρίδες είναι μαύρες. Το OK αποθηκεύει επιλογές για την επόμενη εγγραφή· Άκυρο ή Esc "
            L"απορρίπτει ανεπιβεβαίωτες αλλαγές. Οι ρυθμίσεις εγγραφής, η βοήθεια και οι πληροφορίες δεν "
            L"εμποδίζουν άλλα παράθυρα και ελαχιστοποιούνται. Tab και Shift+Tab μετακινούν την εστίαση, "
            L"Enter ενεργοποιεί το εστιασμένο κουμπί και Esc κλείνει το ενεργό βοηθητικό παράθυρο.\r\n\r\n"
            L"ΑΠΑΙΤΗΣΕΙΣ ΣΥΣΤΗΜΑΤΟΣ\r\nΤα Windows 7–11 υποστηρίζουν όλες τις λειτουργίες. Στα Windows Vista "
            L"SP2 πρέπει να εγκατασταθούν οι ενημερώσεις KB971512 και KB2117917· η εγγραφή MP4 δεν "
            L"λειτουργεί στα Vista. Απαιτείται υποστήριξη Direct3D 11 και, για MP4, Media Foundation και "
            L"κωδικοποιητής H.264. Η διεπαφή και η τεκμηρίωση διατίθενται σε 36 γλώσσες."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ΚΙΝΗΣΗ ΚΑΙ ΡΥΘΜΙΣΕΙΣ\r\nSpaceFlight: Απέραντη κυματοειδής επιφάνεια; Μακρινή πτήση — "
            L"μεταβαλλόμενη επιφάνεια; Πτήση σε χώρο καμπυλωμένο από τη βαρύτητα. Επιλέξτε ακριβώς μία "
            L"κίνηση ανά οθόνη. Η Υφή εναλλάσσει επιφάνεια με υφή και συρμάτινο μοντέλο. Η ελεύθερη "
            L"περιστροφή κάμερας αλλάζει αργά την κατεύθυνση θέασης και στις τρεις διαστάσεις. Οι Παύσεις "
            L"και αντιστροφές προσθέτουν τυχαίες επιβραδύνσεις, παύσεις και αντιστροφές περιστροφής, ενώ η "
            L"πτήση προς τα εμπρός συνεχίζεται. Η ταχύτητα είναι 0–1600%. Κάθε οθόνη διαθέτει ανεξάρτητη "
            L"τυχαία σκηνή που αποδίδεται στον δικό της ρυθμό ανανέωσης. Ο κύριος φωτισμός, ο φωτισμός "
            L"πλήρωσης, ο περιβάλλων φωτισμός και ο φωτισμός περιγράμματος ρυθμίζονται ανεξάρτητα για τις "
            L"επιλεγμένες οθόνες. Ο φωτισμός εφαρμόζεται μόνο σε επιφάνειες με υφή. Και οι δύο προσομοιώσεις "
            L"επιφανειών προσφέρουν Επίπεδο, Κυματισμό ή Χοάνη. Η χοάνη τραβά την κάμερα προς το εσωτερικό "
            L"ακολουθώντας καθοδική σπείρα. Η πτήση σε χώρο καμπυλωμένο από τη βαρύτητα εμφανίζει ένα "
            L"τρισδιάστατο συρμάτινο πλέγμα. Οι επιλογές υφής, σχήματος επιφάνειας και φωτισμού ισχύουν μόνο "
            L"για τις δύο προσομοιώσεις επιφανειών.\r\n\r\nΟΘΟΝΕΣ\r\nΕπιλέξτε μία ή περισσότερες γραμμές στη "
            L"λίστα οθονών. Το Ctrl+A επιλέγει όλες, ενώ τα Ctrl και Shift αλλάζουν την επιλογή. Τα "
            L"χειριστήρια και τα ρυθμιστικά της κίνησης αλλάζουν μόνο τις ρυθμίσεις των επιλεγμένων οθονών. "
            L"Η επιλογή γραμμής διαφέρει από την ενεργοποίηση εξόδου μέσω του πλαισίου ελέγχου της. Η "
            L"επιλογή αποθηκεύεται χωριστά για την εφαρμογή και την προφύλαξη. Αν είχαν επιλεγεί όλες οι "
            L"οθόνες, περιλαμβάνονται και όσες συνδεθούν αργότερα. Οι διαφορετικές τιμές στις επιλεγμένες "
            L"οθόνες υποδεικνύονται με απροσδιόριστη κατάσταση των πλαισίων ελέγχου και μοτίβο κουκκίδων στα "
            L"κουμπιά επιλογής, στις λαβές των ρυθμιστικών και στα κουμπιά «Ενεργοποίηση όλων» και "
            L"«Απενεργοποίηση όλων». Οι ετικέτες των ρυθμιστικών δείχνουν παύλα αντί για κοινή τιμή. Η "
            L"αλλαγή επιλογής ή το κλικ σε ρυθμιστικό εφαρμόζει την τιμή σε όλες τις επιλεγμένες οθόνες.\r\n"
            L"\r\nΠΡΟΕΠΙΣΚΟΠΗΣΗ ΚΑΙ ΧΕΙΡΙΣΜΟΣ\r\nΧρησιμοποιήστε το SpaceFlight.scr ως προφύλαξη οθόνης "
            L"Windows με χωριστές ρυθμίσεις από την εφαρμογή. Η προεπισκόπηση πλήρους οθόνης επιτρέπει "
            L"ζωντανές αλλαγές. Το OK αποθηκεύει και το Άκυρο ή Esc απορρίπτει τις αλλαγές. Τερματίστε την "
            L"προφύλαξη με πλήκτρο ή κίνηση του ποντικιού.\r\n\r\nΑΠΑΙΤΗΣΕΙΣ ΣΥΣΤΗΜΑΤΟΣ\r\nΤα Windows 7–11 "
            L"υποστηρίζουν όλες τις λειτουργίες. Στα Windows Vista SP2 πρέπει να εγκατασταθούν οι "
            L"ενημερώσεις KB971512 και KB2117917. Απαιτείται υποστήριξη Direct3D 11."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Επίπεδο" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Κυματισμός" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Χοάνη" },
    }),
    DefineLanguage(LANG_BS, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Bosanski" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — kontrole" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Postavke programa SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Beskonačna valovita površina" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Daleki let — promjenjiva površina" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Let kroz gravitacijski zakrivljen prostor" },
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
            L"Zatvorite postavke programa SpaceFlight pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zatvorite Windows postavke čuvara ekrana pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zatvorite čuvar ili pregled preko cijelog ekrana tipkom Esc ili pomjeranjem miša pa ponovite "
            L"deinstalaciju."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardverski ubrzan let iznad valovite površine." },
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
            L"ANIMACIJA I POSTAVKE\r\nSpaceFlight: Beskonačna valovita površina; Daleki let — promjenjiva "
            L"površina; Let kroz gravitacijski zakrivljen prostor. Za svaki monitor odaberite tačno jednu "
            L"animaciju. Tekstura mijenja prikaz između teksturirane površine i žičanog modela. Slobodno "
            L"okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju "
            L"nasumično usporavanje, pauze i promjene smjera rotacije; let naprijed se nastavlja. Brzina je "
            L"0–1600%. Svaki monitor ima nezavisnu nasumičnu scenu koja se prikazuje prema njegovoj "
            L"frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i konturno "
            L"svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje samo na "
            L"teksturirane površine. Obje animacije površina nude ravan, valove ili lijevak. Lijevak uvlači "
            L"kameru prema unutra duž silazne spirale. Let kroz gravitacijski zakrivljen prostor prikazuje "
            L"trodimenzionalnu žičanu mrežu. Opcije teksture, oblika površine i osvjetljenja odnose se samo "
            L"na dvije animacije površina.\r\n\r\nMONITORI\r\nOdaberite jedan ili više redova u listi "
            L"monitora. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije "
            L"mijenjaju samo postavke odabranih monitora. Odabir reda nije isto što i uključivanje izlaza "
            L"njegovom kućicom. Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
            L"odabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na "
            L"odabranim monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima "
            L"izbora, ručkama klizača i dugmadima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju "
            L"crticu umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu "
            L"vrijednost na sve odabrane monitore.\r\n\r\nUPRAVLJANJE\r\nPokrenite SpaceFlight.exe. Postavke "
            L"se stalno čuvaju i radi samo jedna instanca aplikacije. Kućica monitora ili dvostruki klik na "
            L"red uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i "
            L"MP4 bilježe prvi aktivni monitor animacije, ne zajedničku sliku svih monitora. Animacijski "
            L"izlaz snimanog monitora ne možete isključiti tokom snimanja; zatvaranje aplikacije tokom "
            L"snimanja zahtijeva potvrdu. Pauza i blokada čuvara ekrana vrijede za cijelu aplikaciju, bez "
            L"obzira na odabir monitora. Kada je blokada uključena, čuvar ekrana Windowsa se sprječava samo "
            L"dok je na barem jednom monitoru vidljiva animacija koja nije pauzirana. Aplikacija može "
            L"instalirati i deinstalirati ugrađeni čuvar ekrana.\r\n\r\nSNIMCI EKRANA I SNIMANJE\r\nU "
            L"postavkama snimanja odaberite Viewport ili TV. Viewport zadržava dimenzije i frekvenciju "
            L"osvježavanja monitora do 60 kadrova u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 "
            L"u omjeru 16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) kadrova u sekundi. TV video "
            L"je progresivni BT.709 ograničenog raspona s poduzorkovanjem boje 4:2:0. Omjer slike ostaje "
            L"sačuvan, a dopunske trake su crne. OK čuva opcije za sljedeći snimak; Otkaži ili Esc odbacuje "
            L"nepotvrđene izmjene. Prozori snimanja, pomoći i informacija ne blokiraju ostale prozore i mogu "
            L"se minimizirati. Tab i Shift+Tab pomjeraju fokus, Enter aktivira fokusirano dugme, a Esc "
            L"zatvara aktivni pomoćni prozor.\r\n\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve "
            L"funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917; MP4 "
            L"snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media Foundation te H.264 "
            L"koder. Interfejs i dokumentacija dostupni su na 36 jezika."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACIJA I POSTAVKE\r\nSpaceFlight: Beskonačna valovita površina; Daleki let — promjenjiva "
            L"površina; Let kroz gravitacijski zakrivljen prostor. Za svaki monitor odaberite tačno jednu "
            L"animaciju. Tekstura mijenja prikaz između teksturirane površine i žičanog modela. Slobodno "
            L"okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju "
            L"nasumično usporavanje, pauze i promjene smjera rotacije; let naprijed se nastavlja. Brzina je "
            L"0–1600%. Svaki monitor ima nezavisnu nasumičnu scenu koja se prikazuje prema njegovoj "
            L"frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i konturno "
            L"svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje samo na "
            L"teksturirane površine. Obje animacije površina nude ravan, valove ili lijevak. Lijevak uvlači "
            L"kameru prema unutra duž silazne spirale. Let kroz gravitacijski zakrivljen prostor prikazuje "
            L"trodimenzionalnu žičanu mrežu. Opcije teksture, oblika površine i osvjetljenja odnose se samo "
            L"na dvije animacije površina.\r\n\r\nMONITORI\r\nOdaberite jedan ili više redova u listi "
            L"monitora. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije "
            L"mijenjaju samo postavke odabranih monitora. Odabir reda nije isto što i uključivanje izlaza "
            L"njegovom kućicom. Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
            L"odabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na "
            L"odabranim monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima "
            L"izbora, ručkama klizača i dugmadima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju "
            L"crticu umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu "
            L"vrijednost na sve odabrane monitore.\r\n\r\nPREGLED I UPRAVLJANJE\r\nKoristite SpaceFlight.scr "
            L"kao Windows čuvar ekrana s odvojenim postavkama. Pregled preko cijelog ekrana omogućava "
            L"izmjene uživo. OK čuva, a Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke "
            L"ili pomjeranjem miša.\r\n\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za "
            L"Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917. Potreban je Direct3D 11."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Ravan" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Valovi" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Lijevak" },
    }),
    DefineLanguage(LANG_HR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Hrvatski" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — upravljanje" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Postavke programa SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Beskonačna valovita ploha" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Daleki let — promjenjiva ploha" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Let kroz gravitacijski zakrivljen prostor" },
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
            L"Zatvorite postavke programa SpaceFlight pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zatvorite Windows postavke čuvara zaslona pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zatvorite čuvar ili pretpregled preko cijelog zaslona tipkom Esc ili pomicanjem miša pa "
            L"ponovite deinstalaciju."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardverski ubrzan let iznad valovite plohe." },
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
            L"ANIMACIJA I POSTAVKE\r\nSpaceFlight: Beskonačna valovita ploha; Daleki let — promjenjiva "
            L"ploha; Let kroz gravitacijski zakrivljen prostor. Za svaki zaslon odaberite točno jednu "
            L"animaciju. Tekstura mijenja prikaz između teksturirane plohe i žičanog modela. Slobodno "
            L"okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju "
            L"nasumično usporavanje, stanke i promjene smjera rotacije; let naprijed se nastavlja. Brzina je "
            L"0–1600%. Svaki zaslon ima neovisnu nasumičnu scenu koja se prikazuje prema njegovoj "
            L"frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i konturno "
            L"svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje samo na "
            L"teksturirane površine. Obje animacije površina nude ravninu, valove ili lijevak. Lijevak "
            L"uvlači kameru prema unutra duž silazne spirale. Let kroz gravitacijski zakrivljen prostor "
            L"prikazuje trodimenzionalnu žičanu mrežu. Opcije teksture, oblika površine i osvjetljenja "
            L"odnose se samo na dvije animacije površina.\r\n\r\nMONITORI\r\nOdaberite jedan ili više redaka "
            L"na popisu zaslona. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači "
            L"animacije mijenjaju samo postavke odabranih zaslona. Odabir retka nije isto što i uključivanje "
            L"izlaza njegovim potvrdnim okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar zaslona. Ako "
            L"su prethodno bili odabrani svi zasloni, uključuju se i novopriključeni zasloni. Različite "
            L"vrijednosti na odabranim zaslonima prikazuju se neodređenim stanjem potvrdnih okvira i "
            L"točkastim uzorkom na izbornim gumbima, ručkama klizača i gumbima „Uključi sve“ i „Isključi "
            L"sve“. Oznake klizača prikazuju crticu umjesto zajedničke vrijednosti. Promjena mogućnosti ili "
            L"klik na klizač primjenjuje tu vrijednost na sve odabrane zaslone.\r\n\r\nUPRAVLJANJE\r\n"
            L"Pokrenite SpaceFlight.exe. Postavke se neprekidno spremaju i radi samo jedna instanca "
            L"aplikacije. Potvrdni okvir zaslona ili dvostruki klik na redak uključuje ili isključuje "
            L"animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe prvi aktivni "
            L"zaslon animacije, ne zajedničku sliku svih zaslona. Animacijski izlaz snimanog zaslona ne "
            L"možete isključiti tijekom snimanja; zatvaranje aplikacije tijekom snimanja zahtijeva potvrdu. "
            L"Pauza i blokada čuvara zaslona vrijede za cijelu aplikaciju, bez obzira na odabir zaslona. "
            L"Kada je blokada uključena, čuvar zaslona sustava Windows sprječava se samo dok je na barem "
            L"jednom zaslonu vidljiva animacija koja nije pauzirana. Aplikacija može instalirati i "
            L"deinstalirati ugrađeni čuvar zaslona.\r\n\r\nSNIMKE ZASLONA I SNIMANJE\r\nU postavkama "
            L"snimanja odaberite Viewport ili TV. Viewport zadržava dimenzije i frekvenciju osvježavanja "
            L"zaslona do 60 sličica u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u omjeru "
            L"16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) sličica u sekundi. TV video je "
            L"progresivni BT.709 ograničenog raspona s poduzorkovanjem boje 4:2:0. Omjer slike ostaje "
            L"sačuvan, a dopunske trake su crne. OK sprema mogućnosti za sljedeću snimku; Odustani ili Esc "
            L"odbacuje nepotvrđene izmjene. Prozori snimanja, pomoći i informacija ne blokiraju ostale "
            L"prozore i mogu se minimizirati. Tab i Shift+Tab pomiču fokus, Enter aktivira fokusirani gumb, "
            L"a Esc zatvara aktivni pomoćni prozor.\r\n\r\nZAHTJEVI SUSTAVA\r\nWindows 7–11 podržava sve "
            L"funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917; MP4 "
            L"snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media Foundation te H.264 "
            L"koder. Sučelje i dokumentacija dostupni su na 36 jezika."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACIJA I POSTAVKE\r\nSpaceFlight: Beskonačna valovita ploha; Daleki let — promjenjiva "
            L"ploha; Let kroz gravitacijski zakrivljen prostor. Za svaki zaslon odaberite točno jednu "
            L"animaciju. Tekstura mijenja prikaz između teksturirane plohe i žičanog modela. Slobodno "
            L"okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju "
            L"nasumično usporavanje, stanke i promjene smjera rotacije; let naprijed se nastavlja. Brzina je "
            L"0–1600%. Svaki zaslon ima neovisnu nasumičnu scenu koja se prikazuje prema njegovoj "
            L"frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i konturno "
            L"svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje samo na "
            L"teksturirane površine. Obje animacije površina nude ravninu, valove ili lijevak. Lijevak "
            L"uvlači kameru prema unutra duž silazne spirale. Let kroz gravitacijski zakrivljen prostor "
            L"prikazuje trodimenzionalnu žičanu mrežu. Opcije teksture, oblika površine i osvjetljenja "
            L"odnose se samo na dvije animacije površina.\r\n\r\nMONITORI\r\nOdaberite jedan ili više redaka "
            L"na popisu zaslona. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači "
            L"animacije mijenjaju samo postavke odabranih zaslona. Odabir retka nije isto što i uključivanje "
            L"izlaza njegovim potvrdnim okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar zaslona. Ako "
            L"su prethodno bili odabrani svi zasloni, uključuju se i novopriključeni zasloni. Različite "
            L"vrijednosti na odabranim zaslonima prikazuju se neodređenim stanjem potvrdnih okvira i "
            L"točkastim uzorkom na izbornim gumbima, ručkama klizača i gumbima „Uključi sve“ i „Isključi "
            L"sve“. Oznake klizača prikazuju crticu umjesto zajedničke vrijednosti. Promjena mogućnosti ili "
            L"klik na klizač primjenjuje tu vrijednost na sve odabrane zaslone.\r\n\r\nPRETPREGLED I "
            L"UPRAVLJANJE\r\nKoristite SpaceFlight.scr kao Windows čuvar zaslona s odvojenim postavkama. "
            L"Pretpregled preko cijelog zaslona omogućuje izmjene uživo. OK sprema, a Odustani ili Esc "
            L"odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili pomicanjem miša.\r\n\r\nZAHTJEVI "
            L"SUSTAVA\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati "
            L"ažuriranja KB971512 i KB2117917. Potreban je Direct3D 11."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Ravnina" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Valovi" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Lijevak" },
    }),
    DefineLanguage(LANG_SL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Slovenščina" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — upravljanje" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Nastavitve SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Neskončna valovita ploskev" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Oddaljeni let — spreminjajoča se ploskev" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Let skozi gravitacijsko ukrivljen prostor" },
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
            L"Zaprite nastavitve SpaceFlight in znova poskusite odstranitev."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zaprite nastavitve ohranjevalnika zaslona Windows in znova poskusite odstranitev."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zaprite ohranjevalnik ali celozaslonski predogled s tipko Esc ali premikom miške in znova "
            L"poskusite odstranitev."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Strojno pospešen let nad valovito ploskvijo." },
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
            L"ANIMACIJA IN NASTAVITVE\r\nSpaceFlight: Neskončna valovita ploskev; Oddaljeni let — "
            L"spreminjajoča se ploskev; Let skozi gravitacijsko ukrivljen prostor. Za vsak zaslon izberite "
            L"natanko eno animacijo. Tekstura preklaplja med teksturirano ploskvijo in žičnim modelom. "
            L"Prosto vrtenje kamere počasi spreminja smer pogleda v vseh treh razsežnostih. Premori in "
            L"obrati dodajo naključne upočasnitve, premore in obrate smeri vrtenja; let naprej se nadaljuje. "
            L"Hitrost je 0–1600%. Vsak zaslon ima neodvisen naključen prizor, ki se izrisuje z njegovo "
            L"hitrostjo osveževanja. Glavno svetlobo, dopolnilno svetlobo, okoljsko svetlobo in obrobno "
            L"svetlobo je mogoče neodvisno vklapljati za izbrane zaslone. Osvetlitev velja samo za "
            L"teksturirane površine. Pri obeh animacijah ploskev lahko izberete ravnino, valovanje ali "
            L"lijak. Lijak vleče kamero navznoter po padajoči spirali. Let skozi gravitacijsko ukrivljen "
            L"prostor prikazuje tridimenzionalno žično mrežo. Možnosti teksture, oblike ploskve in "
            L"osvetlitve veljajo samo za obe animaciji ploskev.\r\n\r\nZASLONI\r\nNa seznamu zaslonov "
            L"izberite eno ali več vrstic. Ctrl+A izbere vse, Ctrl in Shift pa spreminjata izbor. "
            L"Kontrolniki in drsniki animacije spreminjajo samo nastavitve izbranih zaslonov. Izbira vrstice "
            L"ni isto kot vklop izhoda z njenim potrditvenim poljem. Izbor se ločeno shrani za program in "
            L"ohranjevalnik. Če so bili izbrani vsi zasloni, so vključeni tudi na novo priključeni zasloni. "
            L"Različne vrednosti na izbranih zaslonih označujeta nedoločeno stanje potrditvenih polj in "
            L"pikčast vzorec na izbirnih gumbih, ročicah drsnikov ter gumbih »Vklopi vse« in »Izklopi vse«. "
            L"Oznake drsnikov namesto skupne vrednosti prikazujejo pomišljaj. Sprememba možnosti ali klik na "
            L"drsnik uveljavi to vrednost na vseh izbranih zaslonih.\r\n\r\nUPRAVLJANJE\r\nZaženite "
            L"SpaceFlight.exe. Nastavitve se shranjujejo sproti in deluje le en primerek programa. Polje "
            L"zaslona ali dvojni klik na vrstico vklopi ali izklopi izhod animacije. Animacijo lahko začasno "
            L"ustavite in nadaljujete. PNG in MP4 zajameta prvi aktivni zaslon animacije, ne skupne slike "
            L"vseh zaslonov. Izhoda animacije snemanega zaslona med snemanjem ni mogoče izklopiti; zapiranje "
            L"programa med snemanjem zahteva potrditev. Premor in preprečevanje ohranjevalnika veljata za "
            L"celoten program, ne glede na izbor zaslonov. Ko je preprečevanje vključeno, se ohranjevalnik "
            L"Windows prepreči le, dokler je na vsaj enem zaslonu vidna animacija, ki ni ustavljena. Program "
            L"lahko namesti ali odstrani vgrajeni ohranjevalnik.\r\n\r\nPOSNETKI ZASLONA IN SNEMANJE\r\nV "
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
            L"ANIMACIJA IN NASTAVITVE\r\nSpaceFlight: Neskončna valovita ploskev; Oddaljeni let — "
            L"spreminjajoča se ploskev; Let skozi gravitacijsko ukrivljen prostor. Za vsak zaslon izberite "
            L"natanko eno animacijo. Tekstura preklaplja med teksturirano ploskvijo in žičnim modelom. "
            L"Prosto vrtenje kamere počasi spreminja smer pogleda v vseh treh razsežnostih. Premori in "
            L"obrati dodajo naključne upočasnitve, premore in obrate smeri vrtenja; let naprej se nadaljuje. "
            L"Hitrost je 0–1600%. Vsak zaslon ima neodvisen naključen prizor, ki se izrisuje z njegovo "
            L"hitrostjo osveževanja. Glavno svetlobo, dopolnilno svetlobo, okoljsko svetlobo in obrobno "
            L"svetlobo je mogoče neodvisno vklapljati za izbrane zaslone. Osvetlitev velja samo za "
            L"teksturirane površine. Pri obeh animacijah ploskev lahko izberete ravnino, valovanje ali "
            L"lijak. Lijak vleče kamero navznoter po padajoči spirali. Let skozi gravitacijsko ukrivljen "
            L"prostor prikazuje tridimenzionalno žično mrežo. Možnosti teksture, oblike ploskve in "
            L"osvetlitve veljajo samo za obe animaciji ploskev.\r\n\r\nZASLONI\r\nNa seznamu zaslonov "
            L"izberite eno ali več vrstic. Ctrl+A izbere vse, Ctrl in Shift pa spreminjata izbor. "
            L"Kontrolniki in drsniki animacije spreminjajo samo nastavitve izbranih zaslonov. Izbira vrstice "
            L"ni isto kot vklop izhoda z njenim potrditvenim poljem. Izbor se ločeno shrani za program in "
            L"ohranjevalnik. Če so bili izbrani vsi zasloni, so vključeni tudi na novo priključeni zasloni. "
            L"Različne vrednosti na izbranih zaslonih označujeta nedoločeno stanje potrditvenih polj in "
            L"pikčast vzorec na izbirnih gumbih, ročicah drsnikov ter gumbih »Vklopi vse« in »Izklopi vse«. "
            L"Oznake drsnikov namesto skupne vrednosti prikazujejo pomišljaj. Sprememba možnosti ali klik na "
            L"drsnik uveljavi to vrednost na vseh izbranih zaslonih.\r\n\r\nPREDOGLED IN UPRAVLJANJE\r\n"
            L"Uporabite SpaceFlight.scr kot ohranjevalnik zaslona Windows z ločenimi nastavitvami. "
            L"Celozaslonski predogled omogoča sprotne spremembe. OK jih shrani, Prekliči ali Esc jih zavrže. "
            L"Ohranjevalnik zapustite s tipko ali premikom miške.\r\n\r\nSISTEMSKE ZAHTEVE\r\nWindows 7–11 "
            L"podpira vse funkcije. Za Windows Vista SP2 morate namestiti posodobitvi KB971512 in KB2117917. "
            L"Potrebna je podpora Direct3D 11."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Ravnina" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Valovanje" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Lijak" },
    }),
    DefineLanguage(LANG_CNR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Crnogorski" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — kontrole" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Podešavanja programa SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Beskonačna talasasta površina" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Daleki let — promjenljiva površina" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Let kroz gravitaciono zakrivljen prostor" },
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
            L"Zatvorite podešavanja programa SpaceFlight pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zatvorite Windows podešavanja čuvara ekrana pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zatvorite čuvar ili pregled preko cijelog ekrana tasterom Esc ili pomjeranjem miša pa ponovite "
            L"deinstalaciju."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardverski ubrzan let iznad talasaste površine." },
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
            L"ANIMACIJA I PODEŠAVANJA\r\nSpaceFlight: Beskonačna talasasta površina; Daleki let — "
            L"promjenljiva površina; Let kroz gravitaciono zakrivljen prostor. Za svaki monitor izaberite "
            L"tačno jednu animaciju. Tekstura mijenja prikaz između teksturisane površine i žičanog modela. "
            L"Slobodno okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati "
            L"dodaju nasumično usporavanje, pauze i promjene smjera rotacije; let naprijed se nastavlja. "
            L"Brzina je 0–1600%. Svaki monitor ima nezavisnu nasumičnu scenu koja se prikazuje prema "
            L"njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i "
            L"konturno svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje "
            L"samo na teksturirane površine. Obje animacije površina nude ravan, talase ili lijevak. Lijevak "
            L"uvlači kameru prema unutra duž silazne spirale. Let kroz gravitaciono zakrivljen prostor "
            L"prikazuje trodimenzionalnu žičanu mrežu. Opcije teksture, oblika površine i osvjetljenja "
            L"odnose se samo na dvije animacije površina.\r\n\r\nMONITORI\r\nIzaberite jedan ili više redova "
            L"u listi monitora. Ctrl+A bira sve; Ctrl i Shift mijenjaju izbor. Kontrole i klizači animacije "
            L"mijenjaju samo podešavanja izabranih monitora. Izbor reda nije isto što i uključivanje izlaza "
            L"njegovom kućicom. Izbor se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
            L"izabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na "
            L"izabranim monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima "
            L"izbora, ručkama klizača i dugmadima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju "
            L"crticu umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu "
            L"vrijednost na sve izabrane monitore.\r\n\r\nUPRAVLJANJE\r\nPokrenite SpaceFlight.exe. "
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
            L"ANIMACIJA I PODEŠAVANJA\r\nSpaceFlight: Beskonačna talasasta površina; Daleki let — "
            L"promjenljiva površina; Let kroz gravitaciono zakrivljen prostor. Za svaki monitor izaberite "
            L"tačno jednu animaciju. Tekstura mijenja prikaz između teksturisane površine i žičanog modela. "
            L"Slobodno okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati "
            L"dodaju nasumično usporavanje, pauze i promjene smjera rotacije; let naprijed se nastavlja. "
            L"Brzina je 0–1600%. Svaki monitor ima nezavisnu nasumičnu scenu koja se prikazuje prema "
            L"njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i "
            L"konturno svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje "
            L"samo na teksturirane površine. Obje animacije površina nude ravan, talase ili lijevak. Lijevak "
            L"uvlači kameru prema unutra duž silazne spirale. Let kroz gravitaciono zakrivljen prostor "
            L"prikazuje trodimenzionalnu žičanu mrežu. Opcije teksture, oblika površine i osvjetljenja "
            L"odnose se samo na dvije animacije površina.\r\n\r\nMONITORI\r\nIzaberite jedan ili više redova "
            L"u listi monitora. Ctrl+A bira sve; Ctrl i Shift mijenjaju izbor. Kontrole i klizači animacije "
            L"mijenjaju samo podešavanja izabranih monitora. Izbor reda nije isto što i uključivanje izlaza "
            L"njegovom kućicom. Izbor se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
            L"izabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na "
            L"izabranim monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima "
            L"izbora, ručkama klizača i dugmadima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju "
            L"crticu umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu "
            L"vrijednost na sve izabrane monitore.\r\n\r\nPREGLED I UPRAVLJANJE\r\nKoristite SpaceFlight.scr "
            L"kao Windows čuvar ekrana s odvojenim podešavanjima. Pregled preko cijelog ekrana omogućava "
            L"izmjene uživo. OK čuva, a Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tastera "
            L"ili pomjeranjem miša.\r\n\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za "
            L"Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917. Potreban je Direct3D 11."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Ravan" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Talasi" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Lijevak" },
    }),
    DefineLanguage(LANG_BE, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Беларуская" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — кіраванне" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Налады SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Бясконцая хвалістая паверхня" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Далёкі палёт — зменлівая паверхня" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT,
            L"Палёт праз гравітацыйна скрыўленую прастору"
        },
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
            L"Закрыйце налады SpaceFlight ды паўтарыце выдаленне."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Закрыйце акно налад застаўкі Windows ды паўтарыце выдаленне."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Завяршыце застаўку або поўнаэкранны перадпрагляд клавішай Esc ці рухам мышы ды паўтарыце "
            L"выдаленне."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Апаратна паскораны палёт над хвалістай паверхняй." },
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
            L"АНІМАЦЫЯ І НАЛАДЫ\r\nSpaceFlight: Бясконцая хвалістая паверхня; Далёкі палёт — зменлівая "
            L"паверхня; Палёт праз гравітацыйна скрыўленую прастору. Для кожнага манітора выберыце роўна "
            L"адну анімацыю. Тэкстура пераключае тэкстураваную паверхню і каркасную мадэль. Свабоднае "
            L"кручэнне камеры павольна змяняе напрамак погляду ва ўсіх трох вымярэннях. Паўзы і развароты "
            L"дадаюць выпадковыя запаволенні, паўзы і змены напрамку кручэння; палёт наперад працягваецца. "
            L"Хуткасць — 0–1600%. Кожны манітор мае незалежную выпадковую сцэну з вывадам паводле ўласнай "
            L"частаты абнаўлення. Асноўнае, запаўняльнае, фонавае і контурнае святло можна пераключаць "
            L"незалежна для выбраных манітораў. Асвятленне дзейнічае толькі на тэкстураваных паверхнях. У "
            L"абедзвюх анімацыях паверхняў можна выбраць плоскасць, хвалі або варонку. Варонка зацягвае "
            L"камеру ўнутр па сыходнай спіралі. Палёт праз гравітацыйна скрыўленую прастору паказвае "
            L"трохмерную каркасную сетку. Параметры тэкстуры, формы паверхні і асвятлення дзейнічаюць толькі "
            L"для дзвюх анімацый паверхняў.\r\n\r\nМАНІТОРЫ\r\nВыберыце адзін або некалькі радкоў у спісе "
            L"манітораў. Ctrl+A выбірае ўсе; Ctrl і Shift змяняюць выбар. Элементы кіравання і паўзункі "
            L"анімацыі змяняюць толькі налады выбраных манітораў. Выбар радка і ўключэнне вываду яго сцяжком "
            L"— розныя дзеянні. Выбар асобна захоўваецца для праграмы і застаўкі. Калі раней былі выбраны "
            L"ўсе маніторы, да выбару далучаюцца і новыя маніторы. Розныя значэнні на выбраных маніторах "
            L"пазначаюцца нявызначаным станам сцяжкоў і кропкавым узорам на пераключальніках, ручках "
            L"паўзункоў і кнопках «Уключыць усё» і «Выключыць усё». У подпісах паўзункоў замест агульнага "
            L"значэння паказваецца працяжнік. Змена параметра або націск на паўзунок ужывае гэта значэнне да "
            L"ўсіх выбраных манітораў.\r\n\r\nКІРАВАННЕ\r\nЗапусціце SpaceFlight.exe. Налады захоўваюцца "
            L"пастаянна, працуе толькі адзін асобнік праграмы. Сцяжок манітора або падвойнае націсканне на "
            L"радок уключае ці выключае вывад анімацыі. Анімацыю можна прыпыніць і працягнуць. PNG і MP4 "
            L"захопліваюць першы актыўны манітор анімацыі, а не агульны відарыс усіх манітораў. Падчас "
            L"запісу нельга выключыць вывад анімацыі манітора, які запісваецца; закрыццё праграмы падчас "
            L"запісу патрабуе пацвярджэння. Прыпыненне і блакаванне застаўкі дзейнічаюць на ўсю праграму "
            L"незалежна ад выбару манітораў. Калі блакаванне ўключана, застаўка Windows не запускаецца "
            L"толькі пакуль хаця б на адным маніторы бачная непрыпыненая анімацыя. Праграма можа ўсталяваць "
            L"або выдаліць убудаваную застаўку.\r\n\r\nЗДЫМКІ ЭКРАНА І ЗАПІС\r\nУ наладах запісу выберыце "
            L"Viewport або TV. Viewport захоўвае памеры і частату абнаўлення манітора да 60 кадраў за "
            L"секунду. TV прапануе 1920 × 1080, 1440 × 1080 або 1280 × 720 з суадносінамі 16:9 і частатой "
            L"50, 25, 59.94 (60000/1001) або 29.97 (30000/1001) кадраў за секунду. Відэа TV прагрэсіўнае, "
            L"BT.709, з абмежаваным дыяпазонам і субдыскрэтызацыяй колеру 4:2:0. Прапорцыі захоўваюцца, "
            L"палосы запаўнення чорныя. OK захоўвае выбар для наступнага запісу; Скасаваць або Esc адхіляе "
            L"непацверджаныя змены. Вокны запісу, даведкі і звестак пра праграму не блакуюць іншыя вокны і "
            L"могуць згортвацца. Tab і Shift+Tab перамяшчаюць фокус, Enter націскае актыўную кнопку, Esc "
            L"закрывае актыўнае дапаможнае акно.\r\n\r\nСІСТЭМНЫЯ ПАТРАБАВАННІ\r\nWindows 7–11 падтрымлівае "
            L"ўсе функцыі. Для Windows Vista SP2 неабходна ўсталяваць абнаўленні KB971512 і KB2117917; запіс "
            L"MP4 у Vista не працуе. Патрэбна падтрымка Direct3D 11, а для MP4 таксама Media Foundation і "
            L"кадавальнік H.264. Інтэрфейс і дакументацыя даступны на 36 мовах."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"АНІМАЦЫЯ І НАЛАДЫ\r\nSpaceFlight: Бясконцая хвалістая паверхня; Далёкі палёт — зменлівая "
            L"паверхня; Палёт праз гравітацыйна скрыўленую прастору. Для кожнага манітора выберыце роўна "
            L"адну анімацыю. Тэкстура пераключае тэкстураваную паверхню і каркасную мадэль. Свабоднае "
            L"кручэнне камеры павольна змяняе напрамак погляду ва ўсіх трох вымярэннях. Паўзы і развароты "
            L"дадаюць выпадковыя запаволенні, паўзы і змены напрамку кручэння; палёт наперад працягваецца. "
            L"Хуткасць — 0–1600%. Кожны манітор мае незалежную выпадковую сцэну з вывадам паводле ўласнай "
            L"частаты абнаўлення. Асноўнае, запаўняльнае, фонавае і контурнае святло можна пераключаць "
            L"незалежна для выбраных манітораў. Асвятленне дзейнічае толькі на тэкстураваных паверхнях. У "
            L"абедзвюх анімацыях паверхняў можна выбраць плоскасць, хвалі або варонку. Варонка зацягвае "
            L"камеру ўнутр па сыходнай спіралі. Палёт праз гравітацыйна скрыўленую прастору паказвае "
            L"трохмерную каркасную сетку. Параметры тэкстуры, формы паверхні і асвятлення дзейнічаюць толькі "
            L"для дзвюх анімацый паверхняў.\r\n\r\nМАНІТОРЫ\r\nВыберыце адзін або некалькі радкоў у спісе "
            L"манітораў. Ctrl+A выбірае ўсе; Ctrl і Shift змяняюць выбар. Элементы кіравання і паўзункі "
            L"анімацыі змяняюць толькі налады выбраных манітораў. Выбар радка і ўключэнне вываду яго сцяжком "
            L"— розныя дзеянні. Выбар асобна захоўваецца для праграмы і застаўкі. Калі раней былі выбраны "
            L"ўсе маніторы, да выбару далучаюцца і новыя маніторы. Розныя значэнні на выбраных маніторах "
            L"пазначаюцца нявызначаным станам сцяжкоў і кропкавым узорам на пераключальніках, ручках "
            L"паўзункоў і кнопках «Уключыць усё» і «Выключыць усё». У подпісах паўзункоў замест агульнага "
            L"значэння паказваецца працяжнік. Змена параметра або націск на паўзунок ужывае гэта значэнне да "
            L"ўсіх выбраных манітораў.\r\n\r\nПЕРАДПРАГЛЯД І КІРАВАННЕ\r\nВыкарыстоўвайце SpaceFlight.scr як "
            L"застаўку Windows з асобнымі наладамі. Поўнаэкранны перадпрагляд дазваляе змяняць іх падчас "
            L"анімацыі. OK захоўвае змены, Скасаваць або Esc адхіляе іх. Для выхаду з застаўкі націсніце "
            L"клавішу або паварушыце мышшу.\r\n\r\nСІСТЭМНЫЯ ПАТРАБАВАННІ\r\nWindows 7–11 падтрымлівае ўсе "
            L"функцыі. Для Windows Vista SP2 неабходна ўсталяваць абнаўленні KB971512 і KB2117917. Патрэбна "
            L"падтрымка Direct3D 11."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Плоскасць" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Хвалі" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Варонка" },
    }),
    DefineLanguage(LANG_BG, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Български" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — управление" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Настройки на SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Безкрайна вълнообразна повърхнина" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Далечен полет — променяща се повърхнина" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT,
            L"Полет през гравитационно изкривено пространство"
        },
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
            L"Затворете настройките на SpaceFlight и опитайте деинсталирането отново."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Затворете настройките на скрийнсейвъра на Windows и опитайте деинсталирането отново."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Спрете скрийнсейвъра или прегледа на цял екран с Esc или движение на мишката и опитайте отново."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Хардуерно ускорен полет над вълнообразна повърхнина." },
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
            L"АНИМАЦИЯ И НАСТРОЙКИ\r\nSpaceFlight: Безкрайна вълнообразна повърхнина; Далечен полет — "
            L"променяща се повърхнина; Полет през гравитационно изкривено пространство. Изберете точно една "
            L"анимация за всеки монитор. Текстура превключва между текстурирана повърхнина и телен модел. "
            L"Свободното въртене на камерата бавно променя посоката на погледа в трите измерения. Опцията "
            L"„Паузи и обръщания“ добавя случайни забавяния, паузи и обръщания на въртенето; полетът напред "
            L"продължава. Скоростта е 0–1600%. Всеки монитор има независима случайна сцена, изобразявана с "
            L"неговата честота на опресняване. Основната, запълващата, околната и контурната светлина се "
            L"включват независимо за избраните монитори. Осветлението се прилага само към текстурираните "
            L"повърхности. И двете анимации на повърхнини предлагат равнина, вълни или фуния. Фунията "
            L"привлича камерата навътре по низходяща спирала. Полетът през гравитационно изкривено "
            L"пространство показва триизмерна телена мрежа. Опциите за текстура, форма на повърхнината и "
            L"осветление важат само за двете анимации на повърхнини.\r\n\r\nМОНИТОРИ\r\nИзберете един или "
            L"повече редове в списъка с монитори. Ctrl+A избира всички; Ctrl и Shift променят избора. "
            L"Контролите и плъзгачите на анимацията променят само настройките на избраните монитори. "
            L"Избирането на ред и включването на изхода чрез отметката му са различни действия. Изборът се "
            L"запомня отделно за приложението и скрийнсейвъра. Ако са били избрани всички монитори, включват "
            L"се и новосвързаните. Различните стойности на избраните монитори се показват с неопределено "
            L"състояние на отметките и точков шаблон върху радиобутоните, дръжките на плъзгачите и бутоните "
            L"„Включване на всички“ и „Изключване на всички“. Надписите на плъзгачите показват тире вместо "
            L"обща стойност. Промяна на опция или щракване върху плъзгач прилага стойността към всички "
            L"избрани монитори.\r\n\r\nУПРАВЛЕНИЕ\r\nСтартирайте SpaceFlight.exe. Настройките се запазват "
            L"непрекъснато и работи само един екземпляр на приложението. Отметката на монитора или двойно "
            L"щракване върху реда включва или изключва анимационния изход. Анимацията може да се поставя на "
            L"пауза и да продължава. PNG и MP4 заснемат първия активен монитор за анимация, не общ образ от "
            L"всички монитори. По време на запис не може да се изключи анимационният изход на записвания "
            L"монитор; затварянето на приложението при запис изисква потвърждение. Паузата и блокирането на "
            L"скрийнсейвъра важат за цялото приложение независимо от избора на монитори. Когато блокирането "
            L"е включено, скрийнсейвърът на Windows се предотвратява само докато на поне един монитор има "
            L"видима анимация без пауза. Приложението може да инсталира и деинсталира вградения "
            L"скрийнсейвър.\r\n\r\nЕКРАННИ СНИМКИ И ЗАПИС\r\nВ настройките за запис изберете Viewport или "
            L"TV. Viewport запазва размерите и честотата на опресняване на монитора до 60 кадъра в секунда. "
            L"TV предлага 1920 × 1080, 1440 × 1080 или 1280 × 720 със съотношение 16:9 и 50, 25, 59.94 "
            L"(60000/1001) или 29.97 (30000/1001) кадъра в секунда. TV използва прогресивно видео BT.709 с "
            L"ограничен диапазон и цветова субдискретизация 4:2:0. Пропорциите се запазват, допълващите "
            L"ленти са черни. OK запазва избора за следващия запис; Отказ или Esc отхвърля непотвърдените "
            L"промени. Прозорците за запис, помощ и информация не блокират другите прозорци и могат да се "
            L"минимизират. Tab и Shift+Tab преместват фокуса, Enter активира фокусирания бутон, Esc затваря "
            L"активния помощен прозорец.\r\n\r\nСИСТЕМНИ ИЗИСКВАНИЯ\r\nWindows 7–11 поддържа всички функции. "
            L"За Windows Vista SP2 трябва да се инсталират актуализациите KB971512 и KB2117917; записът на "
            L"MP4 не работи във Vista. Изисква се поддръжка на Direct3D 11, а за MP4 също Media Foundation и "
            L"H.264 кодер. Интерфейсът и документацията са налични на 36 езика."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"АНИМАЦИЯ И НАСТРОЙКИ\r\nSpaceFlight: Безкрайна вълнообразна повърхнина; Далечен полет — "
            L"променяща се повърхнина; Полет през гравитационно изкривено пространство. Изберете точно една "
            L"анимация за всеки монитор. Текстура превключва между текстурирана повърхнина и телен модел. "
            L"Свободното въртене на камерата бавно променя посоката на погледа в трите измерения. Опцията "
            L"„Паузи и обръщания“ добавя случайни забавяния, паузи и обръщания на въртенето; полетът напред "
            L"продължава. Скоростта е 0–1600%. Всеки монитор има независима случайна сцена, изобразявана с "
            L"неговата честота на опресняване. Основната, запълващата, околната и контурната светлина се "
            L"включват независимо за избраните монитори. Осветлението се прилага само към текстурираните "
            L"повърхности. И двете анимации на повърхнини предлагат равнина, вълни или фуния. Фунията "
            L"привлича камерата навътре по низходяща спирала. Полетът през гравитационно изкривено "
            L"пространство показва триизмерна телена мрежа. Опциите за текстура, форма на повърхнината и "
            L"осветление важат само за двете анимации на повърхнини.\r\n\r\nМОНИТОРИ\r\nИзберете един или "
            L"повече редове в списъка с монитори. Ctrl+A избира всички; Ctrl и Shift променят избора. "
            L"Контролите и плъзгачите на анимацията променят само настройките на избраните монитори. "
            L"Избирането на ред и включването на изхода чрез отметката му са различни действия. Изборът се "
            L"запомня отделно за приложението и скрийнсейвъра. Ако са били избрани всички монитори, включват "
            L"се и новосвързаните. Различните стойности на избраните монитори се показват с неопределено "
            L"състояние на отметките и точков шаблон върху радиобутоните, дръжките на плъзгачите и бутоните "
            L"„Включване на всички“ и „Изключване на всички“. Надписите на плъзгачите показват тире вместо "
            L"обща стойност. Промяна на опция или щракване върху плъзгач прилага стойността към всички "
            L"избрани монитори.\r\n\r\nПРЕГЛЕД И УПРАВЛЕНИЕ\r\nИзползвайте SpaceFlight.scr като скрийнсейвър "
            L"на Windows с отделни настройки. Прегледът на цял екран позволява промени в реално време. OK "
            L"запазва промените; Отказ или Esc ги отхвърля. Излезте от скрийнсейвъра с клавиш или движение "
            L"на мишката.\r\n\r\nСИСТЕМНИ ИЗИСКВАНИЯ\r\nWindows 7–11 поддържа всички функции. За Windows "
            L"Vista SP2 трябва да се инсталират актуализациите KB971512 и KB2117917. Изисква се поддръжка на "
            L"Direct3D 11."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Равнина" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Вълни" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Фуния" },
    }),
    DefineLanguage(LANG_MK, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Македонски" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — контроли" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Поставки за SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Бесконечна брановидна површина" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Далечен лет — променлива површина" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Лет низ гравитациски искривен простор" },
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
            L"Затворете ги поставките за SpaceFlight и обидете се повторно да деинсталирате."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Затворете ги поставките за чуварот на екранот на Windows и обидете се повторно."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Затворете го чуварот или прегледот на цел екран со Esc или со движење на глувчето и обидете се "
            L"повторно."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Хардверски забрзан лет над брановидна површина." },
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
            L"АНИМАЦИЈА И ПОСТАВКИ\r\nSpaceFlight: Бесконечна брановидна површина; Далечен лет — променлива "
            L"површина; Лет низ гравитациски искривен простор. За секој монитор изберете точно една "
            L"анимација. Текстура менува текстурирана површина и жичен модел. Слободното вртење на камерата "
            L"полека го менува погледот во сите три димензии. Опцијата „Паузи и пресврти“ додава случајни "
            L"забавувања, паузи и промени на насоката на вртење; летот напред продолжува. Брзината е "
            L"0–1600%. Секој монитор има независна случајна сцена што се прикажува со неговата стапка на "
            L"освежување. Главното, дополнителното, амбиенталното и контурното светло може да се вклучуваат "
            L"одделно за избраните монитори. Осветлувањето важи само за текстурираните површини. Двете "
            L"анимации на површини нудат рамнина, бранови или инка. Инката ја влече камерата навнатре по "
            L"надолна спирала. Летот низ гравитациски искривен простор прикажува тридимензионална жичена "
            L"мрежа. Опциите за текстура, облик на површината и осветлување важат само за двете анимации на "
            L"површини.\r\n\r\nМОНИТОРИ\r\nИзберете еден или повеќе редови во списокот на монитори. Ctrl+A "
            L"ги избира сите; Ctrl и Shift го менуваат изборот. Контролите и лизгачите на анимацијата ги "
            L"менуваат само поставките на избраните монитори. Избирањето ред и вклучувањето на излезот преку "
            L"неговото поле се различни дејства. Изборот се памети одделно за апликацијата и чуварот. Ако "
            L"биле избрани сите монитори, се вклучуваат и новоповрзаните монитори. Различните вредности на "
            L"избраните монитори се прикажуваат со неопределена состојба на полињата за избор и точкест "
            L"образец на радио-копчињата, рачките на лизгачите и копчињата „Вклучи ги сите“ и „Исклучи ги "
            L"сите“. Ознаките на лизгачите прикажуваат црта наместо заедничка вредност. Менувањето опција "
            L"или кликнувањето на лизгач ја применува вредноста на сите избрани монитори.\r\n\r\nУПРАВУВАЊЕ\r"
            L"\nСтартувајте SpaceFlight.exe. Поставките се зачувуваат постојано и работи само еден примерок "
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
            L"АНИМАЦИЈА И ПОСТАВКИ\r\nSpaceFlight: Бесконечна брановидна површина; Далечен лет — променлива "
            L"површина; Лет низ гравитациски искривен простор. За секој монитор изберете точно една "
            L"анимација. Текстура менува текстурирана површина и жичен модел. Слободното вртење на камерата "
            L"полека го менува погледот во сите три димензии. Опцијата „Паузи и пресврти“ додава случајни "
            L"забавувања, паузи и промени на насоката на вртење; летот напред продолжува. Брзината е "
            L"0–1600%. Секој монитор има независна случајна сцена што се прикажува со неговата стапка на "
            L"освежување. Главното, дополнителното, амбиенталното и контурното светло може да се вклучуваат "
            L"одделно за избраните монитори. Осветлувањето важи само за текстурираните површини. Двете "
            L"анимации на површини нудат рамнина, бранови или инка. Инката ја влече камерата навнатре по "
            L"надолна спирала. Летот низ гравитациски искривен простор прикажува тридимензионална жичена "
            L"мрежа. Опциите за текстура, облик на површината и осветлување важат само за двете анимации на "
            L"површини.\r\n\r\nМОНИТОРИ\r\nИзберете еден или повеќе редови во списокот на монитори. Ctrl+A "
            L"ги избира сите; Ctrl и Shift го менуваат изборот. Контролите и лизгачите на анимацијата ги "
            L"менуваат само поставките на избраните монитори. Избирањето ред и вклучувањето на излезот преку "
            L"неговото поле се различни дејства. Изборот се памети одделно за апликацијата и чуварот. Ако "
            L"биле избрани сите монитори, се вклучуваат и новоповрзаните монитори. Различните вредности на "
            L"избраните монитори се прикажуваат со неопределена состојба на полињата за избор и точкест "
            L"образец на радио-копчињата, рачките на лизгачите и копчињата „Вклучи ги сите“ и „Исклучи ги "
            L"сите“. Ознаките на лизгачите прикажуваат црта наместо заедничка вредност. Менувањето опција "
            L"или кликнувањето на лизгач ја применува вредноста на сите избрани монитори.\r\n\r\nПРЕГЛЕД И "
            L"УПРАВУВАЊЕ\r\nКористете SpaceFlight.scr како Windows чувар на екранот со одделни поставки. "
            L"Прегледот на цел екран овозможува измени во живо. OK ги зачувува, а Откажи или Esc ги отфрла "
            L"измените. Излезете од чуварот со копче или движење на глувчето.\r\n\r\nСИСТЕМСКИ БАРАЊА\r\n"
            L"Windows 7–11 ги поддржува сите функции. За Windows Vista SP2 мора да се инсталираат "
            L"ажурирањата KB971512 и KB2117917. Потребна е поддршка за Direct3D 11."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Рамнина" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Бранови" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Инка" },
    }),
    DefineLanguage(LANG_SR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Српски" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — контроле" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Подешавања програма SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Бесконачна таласаста површ" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Далеки лет — променљива површ" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT, L"Лет кроз гравитационо закривљен простор" },
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
            L"Затворите подешавања програма SpaceFlight па поновите деинсталацију."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Затворите Windows подешавања чувара екрана па поновите деинсталацију."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Затворите чувар или преглед преко целог екрана тастером Esc или померањем миша па поновите "
            L"деинсталацију."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Хардверски убрзан лет изнад таласасте површи." },
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
            L"АНИМАЦИЈА И ПОДЕШАВАЊА\r\nSpaceFlight: Бесконачна таласаста површ; Далеки лет — променљива "
            L"површ; Лет кроз гравитационо закривљен простор. За сваки монитор изаберите тачно једну "
            L"анимацију. Текстура мења приказ између текстурисане површи и жичаног модела. Слободно окретање "
            L"камере полако мења смер погледа у све три димензије. Паузе и обрти додају насумично "
            L"успоравање, паузе и промене смера ротације; лет напред се наставља. Брзина је 0–1600%. Сваки "
            L"монитор има независну насумичну сцену која се приказује према његовој учестаности освежавања. "
            L"Главно, допунско, амбијентално и контурно светло могу се засебно укључивати за изабране "
            L"мониторе. Осветљење важи само за текстуриране површине. Обе анимације површи нуде раван, "
            L"таласе или левак. Левак увлачи камеру ка унутрашњости дуж силазне спирале. Лет кроз "
            L"гравитационо закривљен простор приказује тродимензионалну жичану мрежу. Опције текстуре, "
            L"облика површи и осветљења односе се само на две анимације површи.\r\n\r\nМОНИТОРИ\r\nИзаберите "
            L"један или више редова у листи монитора. Ctrl+A бира све; Ctrl и Shift мењају избор. Контроле и "
            L"клизачи анимације мењају само подешавања изабраних монитора. Избор реда није исто што и "
            L"укључивање излаза његовим пољем за потврду. Избор се памти одвојено за апликацију и чувар "
            L"екрана. Ако су претходно били изабрани сви монитори, укључују се и новоприкључени монитори. "
            L"Различите вредности на изабраним мониторима приказују се неодређеним стањем поља за потврду и "
            L"тачкастим узорком на дугмадима избора, ручкама клизача и дугмадима „Укључи све“ и „Искључи "
            L"све“. Ознаке клизача приказују црту уместо заједничке вредности. Промена опције или клик на "
            L"клизач примењује ту вредност на све изабране мониторе.\r\n\r\nУПРАВЉАЊЕ\r\nПокрените "
            L"SpaceFlight.exe. Подешавања се стално чувају и ради само једна инстанца апликације. Поље "
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
            L"АНИМАЦИЈА И ПОДЕШАВАЊА\r\nSpaceFlight: Бесконачна таласаста површ; Далеки лет — променљива "
            L"површ; Лет кроз гравитационо закривљен простор. За сваки монитор изаберите тачно једну "
            L"анимацију. Текстура мења приказ између текстурисане површи и жичаног модела. Слободно окретање "
            L"камере полако мења смер погледа у све три димензије. Паузе и обрти додају насумично "
            L"успоравање, паузе и промене смера ротације; лет напред се наставља. Брзина је 0–1600%. Сваки "
            L"монитор има независну насумичну сцену која се приказује према његовој учестаности освежавања. "
            L"Главно, допунско, амбијентално и контурно светло могу се засебно укључивати за изабране "
            L"мониторе. Осветљење важи само за текстуриране површине. Обе анимације површи нуде раван, "
            L"таласе или левак. Левак увлачи камеру ка унутрашњости дуж силазне спирале. Лет кроз "
            L"гравитационо закривљен простор приказује тродимензионалну жичану мрежу. Опције текстуре, "
            L"облика површи и осветљења односе се само на две анимације површи.\r\n\r\nМОНИТОРИ\r\nИзаберите "
            L"један или више редова у листи монитора. Ctrl+A бира све; Ctrl и Shift мењају избор. Контроле и "
            L"клизачи анимације мењају само подешавања изабраних монитора. Избор реда није исто што и "
            L"укључивање излаза његовим пољем за потврду. Избор се памти одвојено за апликацију и чувар "
            L"екрана. Ако су претходно били изабрани сви монитори, укључују се и новоприкључени монитори. "
            L"Различите вредности на изабраним мониторима приказују се неодређеним стањем поља за потврду и "
            L"тачкастим узорком на дугмадима избора, ручкама клизача и дугмадима „Укључи све“ и „Искључи "
            L"све“. Ознаке клизача приказују црту уместо заједничке вредности. Промена опције или клик на "
            L"клизач примењује ту вредност на све изабране мониторе.\r\n\r\nПРЕГЛЕД И УПРАВЉАЊЕ\r\nКористите "
            L"SpaceFlight.scr као Windows чувар екрана са одвојеним подешавањима. Преглед преко целог екрана "
            L"омогућава измене уживо. OK чува, а Откажи или Esc одбацује измене. Из чувара изађите притиском "
            L"тастера или померањем миша.\r\n\r\nСИСТЕМСКИ ЗАХТЕВИ\r\nWindows 7–11 подржава све функције. За "
            L"Windows Vista SP2 морате инсталирати ажурирања KB971512 и KB2117917. Потребан је Direct3D 11."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Раван" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Таласи" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Левак" },
    }),
    DefineLanguage(LANG_UK, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Українська" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — керування" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Налаштування SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Нескінченна хвиляста поверхня" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Далекий політ — мінлива поверхня" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT,
            L"Політ крізь гравітаційно викривлений простір"
        },
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
            L"Закрийте налаштування SpaceFlight та повторіть видалення."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Закрийте налаштування заставки Windows та повторіть видалення."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Завершіть заставку або повноекранний попередній перегляд клавішею Esc чи рухом миші та "
            L"повторіть видалення."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Апаратно прискорений політ над хвилястою поверхнею." },
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
            L"АНІМАЦІЯ ТА НАЛАШТУВАННЯ\r\nSpaceFlight: Нескінченна хвиляста поверхня; Далекий політ — "
            L"мінлива поверхня; Політ крізь гравітаційно викривлений простір. Для кожного монітора виберіть "
            L"рівно одну анімацію. Текстура перемикає текстуровану поверхню та каркасну модель. Вільне "
            L"обертання камери повільно змінює напрямок погляду в усіх трьох вимірах. Паузи та зміни "
            L"напрямку додають випадкові уповільнення, паузи та зміни напрямку обертання; політ уперед "
            L"триває. Швидкість — 0–1600%. Кожен монітор має незалежну випадкову сцену з виведенням "
            L"відповідно до власної частоти оновлення. Основне, заповнювальне, фонове та контурне світло "
            L"можна незалежно перемикати для вибраних моніторів. Освітлення діє лише на текстурованих "
            L"поверхнях. В обох анімаціях поверхонь можна вибрати площину, хвилі або лійку. Лійка втягує "
            L"камеру всередину низхідною спіраллю. Політ крізь гравітаційно викривлений простір показує "
            L"тривимірну каркасну сітку. Параметри текстури, форми поверхні й освітлення діють лише для двох "
            L"анімацій поверхонь.\r\n\r\nМОНІТОРИ\r\nВиберіть один або кілька рядків у списку моніторів. "
            L"Ctrl+A вибирає всі; Ctrl і Shift змінюють вибір. Елементи керування й повзунки анімації "
            L"змінюють лише налаштування вибраних моніторів. Вибір рядка та ввімкнення виведення його "
            L"прапорцем — різні дії. Вибір зберігається окремо для програми й заставки. Якщо раніше були "
            L"вибрані всі монітори, до вибору долучаються й новопідключені. Різні значення на вибраних "
            L"моніторах позначаються невизначеним станом прапорців і крапковим візерунком на перемикачах, "
            L"ручках повзунків і кнопках «Увімкнути все» і «Вимкнути все». Підписи повзунків показують тире "
            L"замість спільного значення. Зміна параметра або натискання на повзунок застосовує це значення "
            L"до всіх вибраних моніторів.\r\n\r\nКЕРУВАННЯ\r\nЗапустіть SpaceFlight.exe. Налаштування "
            L"зберігаються постійно, працює лише один екземпляр програми. Прапорець монітора або подвійне "
            L"клацання рядка вмикає чи вимикає виведення анімації. Анімацію можна призупинити та продовжити. "
            L"PNG і MP4 захоплюють перший активний монітор анімації, а не спільне зображення всіх моніторів. "
            L"Під час запису не можна вимкнути виведення анімації монітора, який записується; закриття "
            L"програми під час запису потребує підтвердження. Призупинення та блокування заставки діють для "
            L"всієї програми незалежно від вибору моніторів. Якщо блокування ввімкнено, заставка Windows не "
            L"запускається лише доки принаймні на одному моніторі видима непризупинена анімація. Програма "
            L"може встановити або видалити вбудовану заставку.\r\n\r\nЗНІМКИ ЕКРАНА ТА ЗАПИС\r\nУ "
            L"налаштуваннях запису виберіть Viewport або TV. Viewport зберігає розміри та частоту оновлення "
            L"монітора до 60 кадрів за секунду. TV пропонує 1920 × 1080, 1440 × 1080 або 1280 × 720 зі "
            L"співвідношенням 16:9 і частотою 50, 25, 59.94 (60000/1001) або 29.97 (30000/1001) кадрів за "
            L"секунду. Відео TV прогресивне, BT.709, з обмеженим діапазоном і субдискретизацією кольору "
            L"4:2:0. Пропорції зберігаються, смуги заповнення чорні. OK зберігає вибір для наступного "
            L"запису; Скасувати або Esc відхиляє непідтверджені зміни. Вікна запису, довідки та відомостей "
            L"не блокують інші вікна й можуть згортатися. Tab і Shift+Tab переміщують фокус, Enter активує "
            L"кнопку з фокусом, Esc закриває активне допоміжне вікно.\r\n\r\nСИСТЕМНІ ВИМОГИ\r\nWindows 7–11 "
            L"підтримує всі функції. Для Windows Vista SP2 потрібно встановити оновлення KB971512 і "
            L"KB2117917; запис MP4 у Vista не працює. Потрібна підтримка Direct3D 11, а для MP4 також Media "
            L"Foundation й кодувальник H.264. Інтерфейс і документація доступні 36 мовами."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"АНІМАЦІЯ ТА НАЛАШТУВАННЯ\r\nSpaceFlight: Нескінченна хвиляста поверхня; Далекий політ — "
            L"мінлива поверхня; Політ крізь гравітаційно викривлений простір. Для кожного монітора виберіть "
            L"рівно одну анімацію. Текстура перемикає текстуровану поверхню та каркасну модель. Вільне "
            L"обертання камери повільно змінює напрямок погляду в усіх трьох вимірах. Паузи та зміни "
            L"напрямку додають випадкові уповільнення, паузи та зміни напрямку обертання; політ уперед "
            L"триває. Швидкість — 0–1600%. Кожен монітор має незалежну випадкову сцену з виведенням "
            L"відповідно до власної частоти оновлення. Основне, заповнювальне, фонове та контурне світло "
            L"можна незалежно перемикати для вибраних моніторів. Освітлення діє лише на текстурованих "
            L"поверхнях. В обох анімаціях поверхонь можна вибрати площину, хвилі або лійку. Лійка втягує "
            L"камеру всередину низхідною спіраллю. Політ крізь гравітаційно викривлений простір показує "
            L"тривимірну каркасну сітку. Параметри текстури, форми поверхні й освітлення діють лише для двох "
            L"анімацій поверхонь.\r\n\r\nМОНІТОРИ\r\nВиберіть один або кілька рядків у списку моніторів. "
            L"Ctrl+A вибирає всі; Ctrl і Shift змінюють вибір. Елементи керування й повзунки анімації "
            L"змінюють лише налаштування вибраних моніторів. Вибір рядка та ввімкнення виведення його "
            L"прапорцем — різні дії. Вибір зберігається окремо для програми й заставки. Якщо раніше були "
            L"вибрані всі монітори, до вибору долучаються й новопідключені. Різні значення на вибраних "
            L"моніторах позначаються невизначеним станом прапорців і крапковим візерунком на перемикачах, "
            L"ручках повзунків і кнопках «Увімкнути все» і «Вимкнути все». Підписи повзунків показують тире "
            L"замість спільного значення. Зміна параметра або натискання на повзунок застосовує це значення "
            L"до всіх вибраних моніторів.\r\n\r\nПОПЕРЕДНІЙ ПЕРЕГЛЯД І КЕРУВАННЯ\r\nВикористовуйте "
            L"SpaceFlight.scr як заставку Windows з окремими налаштуваннями. Повноекранний попередній "
            L"перегляд дозволяє змінювати їх під час анімації. OK зберігає зміни, Скасувати або Esc відхиляє "
            L"їх. Для виходу із заставки натисніть клавішу або порухайте мишею.\r\n\r\nСИСТЕМНІ ВИМОГИ\r\n"
            L"Windows 7–11 підтримує всі функції. Для Windows Vista SP2 потрібно встановити оновлення "
            L"KB971512 і KB2117917. Потрібна підтримка Direct3D 11."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Площина" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Хвилі" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Лійка" },
    }),
    DefineLanguage(LANG_RU, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Русский" },
        LocalizedText{ TXT_CONTROL_TITLE, L"SpaceFlight — управление" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Настройки SpaceFlight" },
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
        LocalizedText{ TXT_EFFECT_INFINITE_SURFACE, L"Бесконечная волнообразная поверхность" },
        LocalizedText{ TXT_EFFECT_MORPHING_SURFACE, L"Дальний полёт — меняющаяся поверхность" },
        LocalizedText{ TXT_EFFECT_GRAVITY_WARPED_SPACE_FLIGHT,
            L"Полёт сквозь гравитационно искривлённое пространство"
        },
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
            L"Закройте настройки SpaceFlight и повторите удаление."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Закройте настройки заставки Windows и повторите удаление."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Завершите заставку или полноэкранный предпросмотр клавишей Esc либо движением мыши и повторите "
            L"удаление."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Аппаратно ускоренный полёт над волнообразной поверхностью." },
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
            L"АНИМАЦИЯ И НАСТРОЙКИ\r\nSpaceFlight: Бесконечная волнообразная поверхность; Дальний полёт — "
            L"меняющаяся поверхность; Полёт сквозь гравитационно искривлённое пространство. Для каждого "
            L"монитора выберите ровно одну анимацию. Текстура переключает текстурированную поверхность и "
            L"каркасную модель. Свободное вращение камеры медленно меняет направление взгляда во всех трёх "
            L"измерениях. Паузы и смены направления добавляют случайные замедления, паузы и изменения "
            L"направления вращения; полёт вперёд продолжается. Скорость — 0–1600%. Каждый монитор имеет "
            L"независимую случайную сцену с выводом согласно собственной частоте обновления. Основной, "
            L"заполняющий, фоновый и контурный свет можно независимо переключать для выбранных мониторов. "
            L"Освещение применяется только к текстурированным поверхностям. В обеих анимациях поверхностей "
            L"можно выбрать плоскость, волны или воронку. Воронка втягивает камеру внутрь по нисходящей "
            L"спирали. Полёт сквозь гравитационно искривлённое пространство показывает трёхмерную каркасную "
            L"сетку. Параметры текстуры, формы поверхности и освещения действуют только для двух анимаций "
            L"поверхностей.\r\n\r\nМОНИТОРЫ\r\nВыберите одну или несколько строк в списке мониторов. Ctrl+A "
            L"выбирает все; Ctrl и Shift изменяют выбор. Элементы управления и ползунки анимации изменяют "
            L"только настройки выбранных мониторов. Выбор строки и включение вывода её флажком — разные "
            L"действия. Выбор сохраняется отдельно для приложения и заставки. Если раньше были выбраны все "
            L"мониторы, в выбор включаются и вновь подключённые. Разные значения на выбранных мониторах "
            L"обозначаются неопределённым состоянием флажков и точечным узором на переключателях, ручках "
            L"ползунков и кнопках «Включить всё» и «Выключить всё». Подписи ползунков показывают тире вместо "
            L"общего значения. Изменение параметра или нажатие на ползунок применяет это значение ко всем "
            L"выбранным мониторам.\r\n\r\nУПРАВЛЕНИЕ\r\nЗапустите SpaceFlight.exe. Настройки сохраняются "
            L"постоянно, работает только один экземпляр приложения. Флажок монитора или двойной щелчок по "
            L"строке включает либо выключает вывод анимации. Анимацию можно приостановить и продолжить. PNG "
            L"и MP4 захватывают первый активный монитор анимации, а не общее изображение всех мониторов. Во "
            L"время записи нельзя отключить вывод анимации записываемого монитора; закрытие приложения во "
            L"время записи требует подтверждения. Пауза и блокировка заставки действуют для всего приложения "
            L"независимо от выбора мониторов. Если блокировка включена, заставка Windows не запускается "
            L"только пока хотя бы на одном мониторе видима неприостановленная анимация. Приложение может "
            L"установить или удалить встроенную заставку.\r\n\r\nСНИМКИ ЭКРАНА И ЗАПИСЬ\r\nВ настройках "
            L"записи выберите Viewport или TV. Viewport сохраняет размеры и частоту обновления монитора до "
            L"60 кадров в секунду. TV предлагает 1920 × 1080, 1440 × 1080 или 1280 × 720 с соотношением 16:9 "
            L"и частотой 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) кадров в секунду. Видео TV "
            L"прогрессивное, BT.709, с ограниченным диапазоном и субдискретизацией цвета 4:2:0. Пропорции "
            L"сохраняются, полосы заполнения чёрные. OK сохраняет выбор для следующей записи; Отмена или Esc "
            L"отклоняет неподтверждённые изменения. Окна записи, справки и сведений не блокируют другие окна "
            L"и могут сворачиваться. Tab и Shift+Tab перемещают фокус, Enter активирует кнопку с фокусом, "
            L"Esc закрывает активное вспомогательное окно.\r\n\r\nСИСТЕМНЫЕ ТРЕБОВАНИЯ\r\nWindows 7–11 "
            L"поддерживает все функции. Для Windows Vista SP2 необходимо установить обновления KB971512 и "
            L"KB2117917; запись MP4 в Vista не работает. Нужна поддержка Direct3D 11, а для MP4 также Media "
            L"Foundation и кодировщик H.264. Интерфейс и документация доступны на 36 языках."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"АНИМАЦИЯ И НАСТРОЙКИ\r\nSpaceFlight: Бесконечная волнообразная поверхность; Дальний полёт — "
            L"меняющаяся поверхность; Полёт сквозь гравитационно искривлённое пространство. Для каждого "
            L"монитора выберите ровно одну анимацию. Текстура переключает текстурированную поверхность и "
            L"каркасную модель. Свободное вращение камеры медленно меняет направление взгляда во всех трёх "
            L"измерениях. Паузы и смены направления добавляют случайные замедления, паузы и изменения "
            L"направления вращения; полёт вперёд продолжается. Скорость — 0–1600%. Каждый монитор имеет "
            L"независимую случайную сцену с выводом согласно собственной частоте обновления. Основной, "
            L"заполняющий, фоновый и контурный свет можно независимо переключать для выбранных мониторов. "
            L"Освещение применяется только к текстурированным поверхностям. В обеих анимациях поверхностей "
            L"можно выбрать плоскость, волны или воронку. Воронка втягивает камеру внутрь по нисходящей "
            L"спирали. Полёт сквозь гравитационно искривлённое пространство показывает трёхмерную каркасную "
            L"сетку. Параметры текстуры, формы поверхности и освещения действуют только для двух анимаций "
            L"поверхностей.\r\n\r\nМОНИТОРЫ\r\nВыберите одну или несколько строк в списке мониторов. Ctrl+A "
            L"выбирает все; Ctrl и Shift изменяют выбор. Элементы управления и ползунки анимации изменяют "
            L"только настройки выбранных мониторов. Выбор строки и включение вывода её флажком — разные "
            L"действия. Выбор сохраняется отдельно для приложения и заставки. Если раньше были выбраны все "
            L"мониторы, в выбор включаются и вновь подключённые. Разные значения на выбранных мониторах "
            L"обозначаются неопределённым состоянием флажков и точечным узором на переключателях, ручках "
            L"ползунков и кнопках «Включить всё» и «Выключить всё». Подписи ползунков показывают тире вместо "
            L"общего значения. Изменение параметра или нажатие на ползунок применяет это значение ко всем "
            L"выбранным мониторам.\r\n\r\nПРЕДПРОСМОТР И УПРАВЛЕНИЕ\r\nИспользуйте SpaceFlight.scr как "
            L"заставку Windows с отдельными настройками. Полноэкранный предпросмотр позволяет изменять их во "
            L"время анимации. OK сохраняет изменения, Отмена или Esc отклоняет их. Для выхода из заставки "
            L"нажмите клавишу или подвигайте мышью.\r\n\r\nСИСТЕМНЫЕ ТРЕБОВАНИЯ\r\nWindows 7–11 поддерживает "
            L"все функции. Для Windows Vista SP2 необходимо установить обновления KB971512 и KB2117917. "
            L"Нужна поддержка Direct3D 11."
        },
        LocalizedText{ TXT_SURFACE_SHAPE_PLANE, L"Плоскость" },
        LocalizedText{ TXT_SURFACE_SHAPE_WAVES, L"Волны" },
        LocalizedText{ TXT_SURFACE_SHAPE_FUNNEL, L"Воронка" },
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
