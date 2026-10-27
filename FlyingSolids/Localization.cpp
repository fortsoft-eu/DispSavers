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
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — ovládání" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Nastavení FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Jazyk:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Rychlost objektů: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Rychlost kamery: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Pozorování prostoru" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Průlet prostorem" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Hlavní světlo" },
        LocalizedText{ TXT_FILL_LIGHT, L"Doplňkové světlo" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Plné prostorové objekty" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Krychle" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Pravidelný čtyřboký jehlan" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Komolý čtyřboký jehlan" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Čtyřboký jehlan se šikmým řezem" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Čtyřboký jehlan s řezem kolmým k podstavě" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Pravidelný trojboký hranol" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Pravidelný pětiboký hranol" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Pravidelný šestiboký hranol" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Pravidelný osmistěn" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Pětiboký dvojjehlan" },
        LocalizedText{ TXT_SOLID_CONE, L"Rotační kužel" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Komolý rotační kužel" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Rotační kužel se šikmým řezem" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Rotační kužel s řezem kolmým k podstavě" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Válec" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Dutý válec" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Dutý válec s toroidálními čely" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Rotační paraboloid uzavřený rovinou" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Koule" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Polokoule" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Kulová úseč" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Velká kulová úseč" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Kulová vrstva" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Trojosý elipsoid" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Protáhlý rotační elipsoid" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Zploštělý rotační elipsoid" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoid" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Kapsle (sferocylindr)" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Zaoblený disk (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Anuloid (torus)" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Ukončení aplikace ukončí právě probíhající záznam." },
        LocalizedText{ TXT_COPY_COUNT, L"Počet kopií každého objektu: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Velikost objektů: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Zapnout náhled" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Vypnout náhled" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animace je pozastavena." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blokovat spořič při animaci" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Základní jas" },
        LocalizedText{ TXT_RIM_LIGHT, L"Přisvětlení obrysů" },
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
            L"Odinstalace se nezdařila, protože je otevřené nastavení FlyingSolids. Zavřete je a odinstalaci "
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
            L"Hardwarově akcelerovaná animace plných prostorových objektů."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Verze:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Cílová platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Web:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Otevřít ve výchozím prohlížeči" },
        LocalizedText{ TXT_COPY_URL, L"Kopírovat &adresu" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopírovat &informace" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Navštívit web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Web nelze otevřít ve výchozím prohlížeči." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Adresu URL nelze zkopírovat do schránky." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Informace nelze zkopírovat do schránky." },
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
            L"ANIMACE A NASTAVENÍ\r\nV seznamu označte jeden nebo více monitorů. Režim kamery, výběr těles, "
            L"světla, rychlosti, velikost a počet kopií se nastavují jen pro označené monitory a každý "
            L"monitor si pamatuje vlastní nastavení. FlyingSolids zobrazuje osvětlená plná prostorová "
            L"tělesa. Jezdci nastavují rychlost objektů a kamery v rozsahu 0–1600 %, jednu až deset kopií "
            L"každého tělesa a velikost 50–200 %. Vyberte Pozorování prostoru nebo přímý Průlet prostorem a "
            L"zaškrtněte požadované druhy těles. Zatržítka Hlavní světlo, Doplňkové světlo, Základní jas a "
            L"Přisvětlení obrysů pod jezdci nezávisle ovládají osvětlení scén na označených monitorech. "
            L"Základní jas přisvětluje povrch těles, přisvětlení obrysů zvýrazňuje jejich okraje. Nastavení "
            L"osvětlení se ukládá zvlášť pro aplikaci a spořič obrazovky.\r\n\r\nMONITORY\r\nOznačení řádků "
            L"určuje, které monitory právě nastavujete; není totožné se zatržítky zapínajícími animační "
            L"výstupy. Ctrl+A označí všechny monitory, Ctrl a Shift umožňují upravit označení. Všechny "
            L"animační volby a jezdce platí pro označené monitory. Označení se pamatuje zvlášť pro EXE a "
            L"SCR. Pokud byly označené všechny monitory, označí se i nově připojené. Různé hodnoty na "
            L"označených monitorech ukazuje neurčitý stav zatržítek a tečkování přepínačů, úchytů jezdců a "
            L"tlačítek „Vše zapnout“ a „Vše vypnout“. Popisek jezdce místo společné hodnoty zobrazuje "
            L"pomlčku. Změna volby nebo kliknutí na jezdec sjednotí příslušnou hodnotu na označených "
            L"monitorech.\r\n\r\nOVLÁDÁNÍ\r\nAnimační výstupy zapnete nebo vypnete zatržítky u monitorů nebo "
            L"dvojklikem na jejich řádky. Každý monitor používá nezávislou scénu. Snímek ukládá PNG, "
            L"tlačítko záznamu spouští a ukončuje MP4. Pozastavení zastaví animaci. Aplikace také instaluje "
            L"nebo odinstaluje zabalený spořič. Nastavení se ukládá průběžně. Aplikace běží pouze v jedné "
            L"instanci. Další spuštění obnoví minimalizované ovládací okno a přenese je do popředí. Mezi "
            L"ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt "
            L"a příslušného písmene. Esc zavře aktivní nápovědu či okno O aplikaci; v ovládacím okně ukončí "
            L"aplikaci. Pozastavení a blokování spořiče platí pro celou aplikaci bez ohledu na označené "
            L"monitory. Je-li blokování zapnuté, brání spuštění spořiče Windows pouze tehdy, když je alespoň "
            L"na jednom monitoru viditelná nepozastavená animace.\r\n\r\nSNÍMKY A ZÁZNAM\r\nSnímek a záznam "
            L"zachycují první aktivní animační monitor, nikoli společnou plochu všech monitorů. PNG používá "
            L"složku Obrázky, MP4 složku Videa; při jejich neexistenci se použijí Dokumenty. Tlačítko "
            L"Nastavení záznamu vybírá Viewport nebo TV. Viewport zachovává rozměry animačního monitoru a "
            L"jeho obnovovací frekvenci, nejvýše 60 snímků za sekundu. TV nabízí rozlišení 1920 × 1080, 1440 "
            L"× 1080 nebo 1280 × 720 v poměru 16:9 a frekvenci 50, 25, 59.94 (60000/1001) nebo 29.97 "
            L"(30000/1001) snímků za sekundu. Obraz zachovává poměr stran; TV používá progresivní video "
            L"BT.709 s omezeným rozsahem a vzorkováním 4:2:0. Rozlišení a snímkovou frekvenci lze vybrat "
            L"pouze v režimu TV. Okno Nastavení záznamu lze minimalizovat a neblokuje ostatní okna aplikace. "
            L"OK uloží volby pro příští záznam MP4; Storno nebo Esc nepotvrzené změny zahodí. Animační "
            L"výstup nahrávaného monitoru nelze během záznamu vypnout; změny ostatních monitorů záznam "
            L"nezastaví. Ukončení aplikace při probíhajícím záznamu vyžaduje potvrzení, protože současně "
            L"ukončí záznam.\r\n\r\nSYSTÉMOVÉ POŽADAVKY\r\nWindows 7 až Windows 11 podporují všechny funkce "
            L"včetně snímků PNG a záznamu MP4. Pro spuštění aplikace ve Windows Vista SP2 je nutné "
            L"nainstalovat aktualizace KB971512 a KB2117917. Záznam MP4 na Vistě v současné verzi nefunguje. "
            L"Vykreslování vyžaduje Direct3D 11, nikoli jen starší DirectX runtime. Záznam MP4 vyžaduje "
            L"dostupné součásti Media Foundation a kodér H.264."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACE A NASTAVENÍ\r\nV seznamu označte jeden nebo více monitorů. Režim kamery, výběr těles, "
            L"světla, rychlosti, velikost a počet kopií se nastavují jen pro označené monitory a každý "
            L"monitor si pamatuje vlastní nastavení. Vyberte Pozorování prostoru nebo přímý Průlet "
            L"prostorem. Jezdci nastavují rychlost objektů a kamery 0–1600 %, jednu až deset kopií každého "
            L"zapnutého tělesa a velikost 50–200 %. Zatržítka Hlavní světlo, Doplňkové světlo, Základní jas "
            L"a Přisvětlení obrysů pod jezdci nezávisle ovládají osvětlení scén na označených monitorech. "
            L"Základní jas přisvětluje povrch těles, přisvětlení obrysů zvýrazňuje jejich okraje. Nastavení "
            L"osvětlení se ukládá zvlášť pro aplikaci a spořič obrazovky.\r\n\r\nMONITORY\r\nOznačení řádků "
            L"určuje, které monitory právě nastavujete; není totožné se zatržítky zapínajícími animační "
            L"výstupy. Ctrl+A označí všechny monitory, Ctrl a Shift umožňují upravit označení. Všechny "
            L"animační volby a jezdce platí pro označené monitory. Označení se pamatuje zvlášť pro EXE a "
            L"SCR. Pokud byly označené všechny monitory, označí se i nově připojené. Různé hodnoty na "
            L"označených monitorech ukazuje neurčitý stav zatržítek a tečkování přepínačů, úchytů jezdců a "
            L"tlačítek „Vše zapnout“ a „Vše vypnout“. Popisek jezdce místo společné hodnoty zobrazuje "
            L"pomlčku. Změna volby nebo kliknutí na jezdec sjednotí příslušnou hodnotu na označených "
            L"monitorech.\r\n\r\nNÁHLED A OVLÁDÁNÍ\r\nZapněte požadované druhy těles. Zapnout náhled spustí "
            L"celoobrazovkový náhled na všech monitorech; změny lze zkoušet za otevřeného nastavení. OK "
            L"nastavení uloží, Storno je zahodí. Celoobrazovkový spořič ukončíte klávesou Esc nebo pohybem "
            L"myši. Mezi ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat "
            L"pomocí Alt a příslušného písmene. Esc v nastavení odpovídá tlačítku Storno; v nápovědě nebo "
            L"okně O aplikaci zavře pouze toto okno.\r\n\r\nSYSTÉMOVÉ POŽADAVKY\r\nPodporovány jsou systémy "
            L"Windows 7 až Windows 11. Pro spuštění aplikace ve Windows Vista SP2 je nutné nainstalovat "
            L"aktualizace KB971512 a KB2117917. Vykreslování vyžaduje Direct3D 11, nikoli jen starší DirectX "
            L"runtime."
        },
    }),
    DefineLanguage(LANG_EN_US, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"English (US)" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Controls" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlyingSolids Settings" },
        LocalizedText{ TXT_LANGUAGE, L"Language:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Object speed: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Camera speed: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Space observation" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Fly through space" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Main light" },
        LocalizedText{ TXT_FILL_LIGHT, L"Fill light" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Solid 3D objects" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Cube" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Regular square pyramid" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Square pyramidal frustum" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Obliquely truncated square pyramid" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Square pyramid cut perpendicular to base" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Regular triangular prism" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Regular pentagonal prism" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Regular hexagonal prism" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Regular octahedron" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Pentagonal bipyramid" },
        LocalizedText{ TXT_SOLID_CONE, L"Right circular cone" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Conical frustum" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Obliquely truncated cone" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Cone cut perpendicular to base" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Right circular cylinder" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Hollow right circular cylinder" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Hollow cylinder with toroidal ends" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Paraboloid of revolution closed by a plane" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Sphere" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Hemisphere" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Spherical cap" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Major spherical cap" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Spherical segment (two bases)" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Triaxial ellipsoid" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Prolate spheroid" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Oblate spheroid" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoid" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Spherocylinder" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Rounded disc (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Torus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Closing the application will stop the recording currently in progress."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Copies of each object: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Object size: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Enable preview" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Disable preview" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animation is paused." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Prevent screen saver during animation" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ambient light" },
        LocalizedText{ TXT_RIM_LIGHT, L"Rim light" },
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
            L"Uninstallation failed because FlyingSolids settings are open. Close the settings window and "
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
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardware-accelerated animation of solid 3D objects." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Version:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Target platform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Website:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Open in default browser" },
        LocalizedText{ TXT_COPY_URL, L"Copy &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copy &information" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Visit %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"The website could not be opened in the default browser." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"The URL could not be copied to the clipboard." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"The information could not be copied to the clipboard."
        },
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
            L"ANIMATION AND SETTINGS\r\nSelect one or more displays in the list. Camera mode, object "
            L"selection, lighting, speeds, size and copy count apply only to the selected displays, and each "
            L"display remembers its own settings. FlyingSolids displays illuminated solid 3D objects. The "
            L"sliders set object and camera speed from 0–1600%, one to ten copies of each object, and size "
            L"from 50–200%. Choose Space observation or the straight Fly through space mode and enable the "
            L"required object types. The Main light, Fill light, Ambient light, and Rim light checkboxes "
            L"below the sliders independently control lighting on the selected displays. Ambient light "
            L"provides base illumination of object surfaces; rim light highlights their edges. Lighting "
            L"settings are stored separately for the application and screen saver.\r\n\r\nDISPLAYS\r\nRow "
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
            L"ANIMATION AND SETTINGS\r\nSelect one or more displays in the list. Camera mode, object "
            L"selection, lighting, speeds, size and copy count apply only to the selected displays, and each "
            L"display remembers its own settings. Choose Space observation or the straight Fly through space "
            L"mode. The sliders set object and camera speed from 0–1600%, one to ten copies of each enabled "
            L"object, and size from 50–200%. The Main light, Fill light, Ambient light, and Rim light "
            L"checkboxes below the sliders independently control lighting on the selected displays. Ambient "
            L"light provides base illumination of object surfaces; rim light highlights their edges. "
            L"Lighting settings are stored separately for the application and screen saver.\r\n\r\nDISPLAYS\r"
            L"\nRow selection determines which displays you are editing; it is separate from the checkboxes "
            L"that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the "
            L"selection. All animation options and sliders apply to the selected displays. The selection is "
            L"remembered separately for EXE and SCR. If all displays were selected, newly connected displays "
            L"join the selection. Different values across selected displays are indicated by indeterminate "
            L"checkboxes and dotted radio buttons, slider thumbs, and the “Enable all” and “Disable all” "
            L"buttons. Slider labels show a dash instead of a shared value. Changing an option or clicking a "
            L"slider applies that value to all selected displays.\r\n\r\nPREVIEW AND CONTROLS\r\nEnable the "
            L"required object types. Enable preview starts a full-screen preview on every display while the "
            L"settings dialog remains open for live adjustments. OK saves the settings and Cancel discards "
            L"them. Exit the full-screen saver with Esc or mouse movement. Use Tab and Shift+Tab to move "
            L"between controls; use Alt and the underlined letter to activate a command. Esc in the settings "
            L"dialog is equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\nSYSTEM "
            L"REQUIREMENTS\r\nWindows 7 through Windows 11 are supported. To run the application on Windows "
            L"Vista SP2, you must install updates KB971512 and KB2117917. Rendering requires Direct3D 11, "
            L"not just an older DirectX runtime."
        },
    }),
    DefineLanguage(LANG_EN_GB, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"English (UK)" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Controls" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlyingSolids Settings" },
        LocalizedText{ TXT_LANGUAGE, L"Language:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Object speed: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Camera speed: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Space observation" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Fly through space" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Main light" },
        LocalizedText{ TXT_FILL_LIGHT, L"Fill light" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Solid 3D objects" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Cube" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Regular square pyramid" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Square pyramidal frustum" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Obliquely truncated square pyramid" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Square pyramid cut perpendicular to base" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Regular triangular prism" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Regular pentagonal prism" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Regular hexagonal prism" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Regular octahedron" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Pentagonal bipyramid" },
        LocalizedText{ TXT_SOLID_CONE, L"Right circular cone" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Conical frustum" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Obliquely truncated cone" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Cone cut perpendicular to base" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Right circular cylinder" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Hollow right circular cylinder" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Hollow cylinder with toroidal ends" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Paraboloid of revolution closed by a plane" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Sphere" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Hemisphere" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Spherical cap" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Major spherical cap" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Spherical segment (two bases)" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Triaxial ellipsoid" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Prolate spheroid" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Oblate spheroid" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoid" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Spherocylinder" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Rounded disc (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Torus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Closing the application will stop the recording currently in progress."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Copies of each object: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Object size: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Enable preview" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Disable preview" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animation is paused." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Prevent screen saver during animation" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ambient light" },
        LocalizedText{ TXT_RIM_LIGHT, L"Rim light" },
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
            L"Uninstallation failed because FlyingSolids settings are open. Close the settings window and "
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
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardware-accelerated animation of solid 3D objects." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Version:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Target platform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Website:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Open in default browser" },
        LocalizedText{ TXT_COPY_URL, L"Copy &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copy &information" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Visit %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"The website could not be opened in the default browser." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"The URL could not be copied to the clipboard." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"The information could not be copied to the clipboard."
        },
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
            L"ANIMATION AND SETTINGS\r\nSelect one or more displays in the list. Camera mode, object "
            L"selection, lighting, speeds, size and copy count apply only to the selected displays, and each "
            L"display remembers its own settings. FlyingSolids displays illuminated solid 3D objects. The "
            L"sliders set object and camera speed from 0–1600%, one to ten copies and size from 50–200%. "
            L"Choose Space observation or the straight Fly through space mode and enable the required "
            L"objects. The Main light, Fill light, Ambient light, and Rim light checkboxes below the sliders "
            L"independently control lighting on the selected displays. Ambient light provides base "
            L"illumination of object surfaces; rim light highlights their edges. Lighting settings are "
            L"stored separately for the application and screen saver.\r\n\r\nDISPLAYS\r\nRow selection "
            L"determines which displays you are editing; it is separate from the checkboxes that enable "
            L"animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All "
            L"animation options and sliders apply to the selected displays. The selection is remembered "
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
            L"ANIMATION AND SETTINGS\r\nSelect one or more displays in the list. Camera mode, object "
            L"selection, lighting, speeds, size and copy count apply only to the selected displays, and each "
            L"display remembers its own settings. Choose Space observation or the straight Fly through space "
            L"mode. Set object and camera speed from 0–1600%, one to ten copies and size from 50–200%, then "
            L"enable the required objects. The Main light, Fill light, Ambient light, and Rim light "
            L"checkboxes below the sliders independently control lighting on the selected displays. Ambient "
            L"light provides base illumination of object surfaces; rim light highlights their edges. "
            L"Lighting settings are stored separately for the application and screen saver.\r\n\r\nDISPLAYS\r"
            L"\nRow selection determines which displays you are editing; it is separate from the checkboxes "
            L"that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the "
            L"selection. All animation options and sliders apply to the selected displays. The selection is "
            L"remembered separately for EXE and SCR. If all displays were selected, newly connected displays "
            L"join the selection. Different values across selected displays are indicated by indeterminate "
            L"checkboxes and dotted radio buttons, slider thumbs and the “Enable all” and “Disable all” "
            L"buttons. Slider labels show a dash instead of a shared value. Changing an option or clicking a "
            L"slider applies that value to all selected displays.\r\n\r\nPREVIEW AND CONTROLS\r\nEnable "
            L"preview starts a full-screen preview on every display while the settings dialog remains open "
            L"for live adjustments. OK saves the settings and Cancel discards them. Exit the full-screen "
            L"screen saver with Esc or mouse movement. Use Tab and Shift+Tab to move between controls; use "
            L"Alt and the underlined letter to activate a command. Esc in the settings dialog is equivalent "
            L"to Cancel; in Help or About, it closes only that window.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows "
            L"7 through Windows 11 are supported. To run the application on Windows Vista SP2, you must "
            L"install updates KB971512 and KB2117917. Rendering requires Direct3D 11, not just an older "
            L"DirectX runtime."
        },
    }),
    DefineLanguage(LANG_EN_AU, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"English (Australia)" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Controls" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlyingSolids Settings" },
        LocalizedText{ TXT_LANGUAGE, L"Language:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Object speed: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Camera speed: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Space observation" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Fly through space" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Main light" },
        LocalizedText{ TXT_FILL_LIGHT, L"Fill light" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Solid 3D objects" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Cube" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Regular square pyramid" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Square pyramidal frustum" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Obliquely truncated square pyramid" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Square pyramid cut perpendicular to base" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Regular triangular prism" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Regular pentagonal prism" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Regular hexagonal prism" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Regular octahedron" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Pentagonal bipyramid" },
        LocalizedText{ TXT_SOLID_CONE, L"Right circular cone" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Conical frustum" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Obliquely truncated cone" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Cone cut perpendicular to base" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Right circular cylinder" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Hollow right circular cylinder" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Hollow cylinder with toroidal ends" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Paraboloid of revolution closed by a plane" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Sphere" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Hemisphere" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Spherical cap" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Major spherical cap" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Spherical segment (two bases)" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Triaxial ellipsoid" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Prolate spheroid" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Oblate spheroid" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoid" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Spherocylinder" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Rounded disc (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Torus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Closing the application will stop the recording currently in progress."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Copies of each object: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Object size: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Enable preview" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Disable preview" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animation is paused." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Prevent screen saver during animation" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ambient light" },
        LocalizedText{ TXT_RIM_LIGHT, L"Rim light" },
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
            L"Uninstallation failed because FlyingSolids settings are open. Close the settings window and "
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
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardware-accelerated animation of solid 3D objects." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Version:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Target platform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Website:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Open in default browser" },
        LocalizedText{ TXT_COPY_URL, L"Copy &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copy &information" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Visit %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"The website could not be opened in the default browser." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"The URL could not be copied to the clipboard." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"The information could not be copied to the clipboard."
        },
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
            L"ANIMATION AND SETTINGS\r\nSelect one or more displays in the list. Camera mode, object "
            L"selection, lighting, speeds, size and copy count apply only to the selected displays, and each "
            L"display remembers its own settings. FlyingSolids displays illuminated solid 3D objects. The "
            L"sliders set object and camera speed from 0–1600%, one to ten copies and size from 50–200%. "
            L"Choose Space observation or the straight Fly through space mode and enable the required "
            L"objects. The Main light, Fill light, Ambient light, and Rim light checkboxes below the sliders "
            L"independently control lighting on the selected displays. Ambient light provides base "
            L"illumination of object surfaces; rim light highlights their edges. Lighting settings are "
            L"stored separately for the application and screen saver.\r\n\r\nDISPLAYS\r\nRow selection "
            L"determines which displays you are editing; it is separate from the checkboxes that enable "
            L"animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All "
            L"animation options and sliders apply to the selected displays. The selection is remembered "
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
            L"ANIMATION AND SETTINGS\r\nSelect one or more displays in the list. Camera mode, object "
            L"selection, lighting, speeds, size and copy count apply only to the selected displays, and each "
            L"display remembers its own settings. Choose Space observation or the straight Fly through space "
            L"mode. Set object and camera speed from 0–1600%, one to ten copies and size from 50–200%, then "
            L"enable the required objects. The Main light, Fill light, Ambient light, and Rim light "
            L"checkboxes below the sliders independently control lighting on the selected displays. Ambient "
            L"light provides base illumination of object surfaces; rim light highlights their edges. "
            L"Lighting settings are stored separately for the application and screen saver.\r\n\r\nDISPLAYS\r"
            L"\nRow selection determines which displays you are editing; it is separate from the checkboxes "
            L"that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the "
            L"selection. All animation options and sliders apply to the selected displays. The selection is "
            L"remembered separately for EXE and SCR. If all displays were selected, newly connected displays "
            L"join the selection. Different values across selected displays are indicated by indeterminate "
            L"checkboxes and dotted radio buttons, slider thumbs and the “Enable all” and “Disable all” "
            L"buttons. Slider labels show a dash instead of a shared value. Changing an option or clicking a "
            L"slider applies that value to all selected displays.\r\n\r\nPREVIEW AND CONTROLS\r\nEnable "
            L"preview starts a full-screen preview on every display while the settings dialog remains open "
            L"for live adjustments. OK saves the settings and Cancel discards them. Exit the full-screen "
            L"screen saver with Esc or mouse movement. Use Tab and Shift+Tab to move between controls; use "
            L"Alt and the underlined letter to activate a command. Esc in the settings dialog is equivalent "
            L"to Cancel; in Help or About, it closes only that window.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows "
            L"7 through Windows 11 are supported. To run the application on Windows Vista SP2, you must "
            L"install updates KB971512 and KB2117917. Rendering requires Direct3D 11, not just an older "
            L"DirectX runtime."
        },
    }),
    DefineLanguage(LANG_DE, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Deutsch" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Steuerung" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlyingSolids-Einstellungen" },
        LocalizedText{ TXT_LANGUAGE, L"Sprache:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Objektgeschwindigkeit: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Kamerageschwindigkeit: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Raumbeobachtung" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Flug durch den Raum" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Hauptlicht" },
        LocalizedText{ TXT_FILL_LIGHT, L"Aufhelllicht" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Volumenkörper" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Würfel" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Regelmäßige quadratische Pyramide" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Quadratischer Pyramidenstumpf" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Schräg abgeschnittene Quadratpyramide" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Quadratpyramide, basissenkrechter Schnitt" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Regelmäßiges Dreiecksprisma" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Regelmäßiges Fünfeckprisma" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Regelmäßiges Sechseckprisma" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Regelmäßiges Oktaeder" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Fünfeck-Doppelpyramide" },
        LocalizedText{ TXT_SOLID_CONE, L"Gerader Kreiskegel" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Kegelstumpf" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Schräg abgeschnittener Kreiskegel" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Kreiskegel, Schnitt senkrecht zur Basis" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Gerader Kreiszylinder" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Hohlzylinder" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Hohlzylinder mit toroidalen Enden" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Geschlossener Rotationsparaboloid" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Kugel" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Halbkugel" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Kugelabschnitt" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Großer Kugelabschnitt" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Kugelschicht" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Dreiachsiges Ellipsoid" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Verlängertes Rotationsellipsoid" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Abgeplattetes Rotationsellipsoid" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoid" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sphärozylinder" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Abgerundete Scheibe (Spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Torus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Beim Beenden der Anwendung wird die laufende Aufnahme beendet."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Kopien je Objekt: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Objektgröße: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Vorschau einschalten" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Vorschau ausschalten" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animation ist angehalten." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Bildschirmschoner bei Animation sperren" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Umgebungslicht" },
        LocalizedText{ TXT_RIM_LIGHT, L"Konturlicht" },
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
            L"Die Deinstallation ist fehlgeschlagen, weil die FlyingSolids-Einstellungen geöffnet sind. "
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
            L"Hardwarebeschleunigte Animation dreidimensionaler Volumenkörper."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Version:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Zielplattform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Website:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"Im Standardbrowser &öffnen" },
        LocalizedText{ TXT_COPY_URL, L"&URL kopieren" },
        LocalizedText{ TXT_COPY_INFORMATION, L"&Informationen kopieren" },
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
            L"ANIMATION UND EINSTELLUNGEN\r\nMarkieren Sie einen oder mehrere Monitore in der Liste. "
            L"Kameramodus, Körperauswahl, Beleuchtung, Geschwindigkeiten, Größe und Anzahl der Exemplare "
            L"gelten nur für die markierten Monitore. Jeder Monitor speichert seine eigenen Einstellungen. "
            L"FlyingSolids zeigt beleuchtete dreidimensionale Volumenkörper. Die Regler bestimmen Objekt- "
            L"und Kamerageschwindigkeit von 0–1600 %, ein bis zehn Exemplare je Körper und eine Größe von "
            L"50–200 %. Wählen Sie Raumbeobachtung oder Flug durch den Raum in gerader Linie und aktivieren "
            L"Sie die gewünschten Körper. Die Kontrollkästchen Hauptlicht, Aufhelllicht, Umgebungslicht und "
            L"Konturlicht unter den Reglern steuern die Beleuchtung der ausgewählten Monitore unabhängig "
            L"voneinander. Umgebungslicht sorgt für eine Grundhelligkeit der Körperoberflächen, Konturlicht "
            L"betont ihre Ränder. Die Beleuchtungseinstellungen werden für Anwendung und Bildschirmschoner "
            L"getrennt gespeichert.\r\n\r\nMONITORE\r\nDie Zeilenauswahl bestimmt, welche Monitore Sie "
            L"bearbeiten; sie ist von den Kontrollkästchen zum Einschalten der Animationsausgabe getrennt. "
            L"Strg+A wählt alle Monitore, Strg und Umschalt ändern die Auswahl. Alle Animationsoptionen und "
            L"Regler gelten für die ausgewählten Monitore. Die Auswahl wird für EXE und SCR getrennt "
            L"gespeichert. Waren alle Monitore ausgewählt, werden auch neu angeschlossene ausgewählt. "
            L"Unterschiedliche Werte der ausgewählten Monitore werden durch unbestimmte Kontrollkästchen und "
            L"gepunktete Optionsfelder, Reglergriffe sowie Schaltflächen „Alle aktivieren“ und „Alle "
            L"deaktivieren“ angezeigt. Reglerbeschriftungen zeigen statt eines gemeinsamen Werts einen "
            L"Gedankenstrich. Das Ändern einer Option oder Anklicken eines Reglers übernimmt diesen Wert für "
            L"alle ausgewählten Monitore.\r\n\r\nBEDIENUNG\r\nDie Animationsausgabe schalten Sie mit den "
            L"Kontrollkästchen der Monitore oder per Doppelklick auf deren Zeilen ein oder aus. Jeder "
            L"Monitor besitzt eine unabhängige Szene. Schnappschuss speichert PNG, die Aufnahmetaste startet "
            L"oder beendet MP4. Pause hält die Animation an. Die Anwendung installiert oder deinstalliert "
            L"außerdem den eingebetteten Bildschirmschoner. Einstellungen werden laufend gespeichert. Die "
            L"Anwendung läuft nur in einer Instanz. Ein erneuter Start stellt das minimierte Steuerfenster "
            L"wieder her und bringt es in den Vordergrund. Mit Tab und Umschalt+Tab wechseln Sie zwischen "
            L"den Steuerelementen; mit Alt und dem unterstrichenen Buchstaben rufen Sie einen Befehl auf. "
            L"Esc schließt das aktive Hilfe- oder Infofenster; im Steuerfenster beendet es die Anwendung. "
            L"Pause und Bildschirmschonersperre gelten für die gesamte Anwendung, unabhängig von der "
            L"Monitorauswahl. Bei eingeschalteter Sperre wird der Windows-Bildschirmschoner nur verhindert, "
            L"solange auf mindestens einem Monitor eine sichtbare, nicht angehaltene Animation läuft.\r\n\r\n"
            L"BILDSCHIRMFOTOS UND AUFNAHME\r\nSchnappschüsse und Aufnahmen erfassen den ersten aktiven "
            L"Animationsmonitor, nicht die gemeinsame Fläche aller Monitore. PNG verwendet Bilder, MP4 "
            L"Videos; fehlen diese Ordner, wird Dokumente verwendet. Die Schaltfläche Aufnahmeeinstellungen "
            L"wählt Viewport oder TV. Viewport erhält die Abmessungen und Bildwiederholfrequenz des "
            L"Animationsmonitors bis höchstens 60 Bilder pro Sekunde. TV bietet 1920 × 1080, 1440 × 1080 "
            L"oder 1280 × 720 im Format 16:9 mit 50, 25, 59.94 (60000/1001) oder 29.97 (30000/1001) Bildern "
            L"pro Sekunde. Das Seitenverhältnis bleibt erhalten; TV verwendet progressives BT.709-Video mit "
            L"begrenztem Wertebereich und 4:2:0-Abtastung. Auflösung und Bildfrequenz sind nur im TV-Modus "
            L"wählbar. Das Fenster Aufnahmeeinstellungen lässt sich minimieren und blockiert die anderen "
            L"Anwendungsfenster nicht. OK speichert die Auswahl für die nächste MP4-Aufnahme; Abbrechen oder "
            L"Esc verwirft unbestätigte Änderungen. Die Animationsausgabe des aufgezeichneten Monitors kann "
            L"während der Aufnahme nicht ausgeschaltet werden; Änderungen an anderen Monitoren beenden die "
            L"Aufnahme nicht. Das Beenden der Anwendung während einer Aufnahme muss bestätigt werden, da es "
            L"auch die Aufnahme beendet.\r\n\r\nSYSTEMANFORDERUNGEN\r\nWindows 7 bis Windows 11 unterstützen "
            L"alle Funktionen einschließlich PNG-Schnappschüssen und MP4-Aufnahmen. Zum Ausführen der "
            L"Anwendung unter Windows Vista SP2 müssen die Updates KB971512 und KB2117917 installiert "
            L"werden. MP4-Aufnahmen funktionieren unter Vista in der aktuellen Version nicht. Die "
            L"Darstellung erfordert Direct3D 11, nicht nur eine ältere DirectX-Laufzeitumgebung. "
            L"MP4-Aufnahmen benötigen verfügbare Media-Foundation-Komponenten und einen H.264-Encoder."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATION UND EINSTELLUNGEN\r\nMarkieren Sie einen oder mehrere Monitore in der Liste. "
            L"Kameramodus, Körperauswahl, Beleuchtung, Geschwindigkeiten, Größe und Anzahl der Exemplare "
            L"gelten nur für die markierten Monitore. Jeder Monitor speichert seine eigenen Einstellungen. "
            L"Wählen Sie Raumbeobachtung oder Flug durch den Raum in gerader Linie. Die Regler bestimmen "
            L"Objekt- und Kamerageschwindigkeit von 0–1600 %, ein bis zehn Exemplare je aktivem Körper und "
            L"50–200 % Größe. Die Kontrollkästchen Hauptlicht, Aufhelllicht, Umgebungslicht und Konturlicht "
            L"unter den Reglern steuern die Beleuchtung der ausgewählten Monitore unabhängig voneinander. "
            L"Umgebungslicht sorgt für eine Grundhelligkeit der Körperoberflächen, Konturlicht betont ihre "
            L"Ränder. Die Beleuchtungseinstellungen werden für Anwendung und Bildschirmschoner getrennt "
            L"gespeichert.\r\n\r\nMONITORE\r\nDie Zeilenauswahl bestimmt, welche Monitore Sie bearbeiten; "
            L"sie ist von den Kontrollkästchen zum Einschalten der Animationsausgabe getrennt. Strg+A wählt "
            L"alle Monitore, Strg und Umschalt ändern die Auswahl. Alle Animationsoptionen und Regler gelten "
            L"für die ausgewählten Monitore. Die Auswahl wird für EXE und SCR getrennt gespeichert. Waren "
            L"alle Monitore ausgewählt, werden auch neu angeschlossene ausgewählt. Unterschiedliche Werte "
            L"der ausgewählten Monitore werden durch unbestimmte Kontrollkästchen und gepunktete "
            L"Optionsfelder, Reglergriffe sowie Schaltflächen „Alle aktivieren“ und „Alle deaktivieren“ "
            L"angezeigt. Reglerbeschriftungen zeigen statt eines gemeinsamen Werts einen Gedankenstrich. Das "
            L"Ändern einer Option oder Anklicken eines Reglers übernimmt diesen Wert für alle ausgewählten "
            L"Monitore.\r\n\r\nVORSCHAU UND BEDIENUNG\r\nAktivieren Sie die gewünschten Körper. Vorschau "
            L"einschalten startet eine Vollbildvorschau auf allen Monitoren. Der Einstellungsdialog bleibt "
            L"für Änderungen geöffnet. OK speichert, Abbrechen verwirft. Esc oder eine Mausbewegung beendet "
            L"den Vollbildschoner. Mit Tab und Umschalt+Tab wechseln Sie zwischen den Steuerelementen; mit "
            L"Alt und dem unterstrichenen Buchstaben rufen Sie einen Befehl auf. Esc im Einstellungsdialog "
            L"entspricht Abbrechen; in der Hilfe oder im Infofenster schließt es nur dieses Fenster.\r\n\r\n"
            L"SYSTEMANFORDERUNGEN\r\nUnterstützt werden Windows 7 bis Windows 11. Zum Ausführen der "
            L"Anwendung unter Windows Vista SP2 müssen die Updates KB971512 und KB2117917 installiert "
            L"werden. Die Darstellung erfordert Direct3D 11, nicht nur eine ältere DirectX-Laufzeitumgebung."
        },
    }),
    DefineLanguage(LANG_FR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Français" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Commandes" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Paramètres de FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Langue :" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Vitesse des objets : %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Vitesse de la caméra : %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Observation de l’espace" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Vol dans l’espace" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Éclairage principal" },
        LocalizedText{ TXT_FILL_LIGHT, L"Éclairage d’appoint" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Objets 3D pleins" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Cube" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Pyramide régulière à base carrée" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Tronc de pyramide carrée" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Pyramide carrée tronquée par plan oblique" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Pyramide carrée, coupe normale à la base" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Prisme droit à base triangulaire régulière" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Prisme droit à base pentagonale régulière" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Prisme droit à base hexagonale régulière" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Octaèdre régulier" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Bipyramide pentagonale" },
        LocalizedText{ TXT_SOLID_CONE, L"Cône de révolution" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Tronc de cône" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Cône tronqué par un plan oblique" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Cône coupé perpendiculairement à la base" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Cylindre de révolution" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Cylindre creux" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Cylindre creux à extrémités toriques" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Paraboloïde de révolution fermé par un plan" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Boule" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Demi-boule" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Segment sphérique" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Grand segment sphérique" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Segment sphérique à deux bases" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Ellipsoïde triaxial" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Sphéroïde allongé" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Sphéroïde aplati" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoïde" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sphérocylindre" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Disque arrondi (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Tore" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"La fermeture de l’application arrêtera l’enregistrement en cours."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Copies de chaque objet : %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Taille des objets : %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Activer l’aperçu" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Désactiver l’aperçu" },
        LocalizedText{ TXT_PAUSED_STATUS, L"L’animation est en pause." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Bloquer l’écran de veille pendant l’animation" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Éclairage ambiant" },
        LocalizedText{ TXT_RIM_LIGHT, L"Éclairage des contours" },
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
            L"La désinstallation a échoué car les paramètres de FlyingSolids sont ouverts. Fermez cette "
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
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Animation accélérée par le matériel d’objets 3D pleins." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Version :" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Plateforme cible :" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Site web :" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Ouvrir dans le navigateur par défaut" },
        LocalizedText{ TXT_COPY_URL, L"Copier l’&URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copier les &informations" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Visiter le site web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Impossible d’ouvrir le site dans le navigateur par défaut."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Impossible de copier l’URL dans le presse-papiers." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Impossible de copier les informations dans le presse-papiers."
        },
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
            L"ANIMATION ET PARAMÈTRES\r\nSélectionnez un ou plusieurs écrans dans la liste. Le mode de "
            L"caméra, les objets, l’éclairage, les vitesses, la taille et le nombre de copies ne "
            L"s’appliquent qu’aux écrans sélectionnés. Chaque écran mémorise ses propres réglages. "
            L"FlyingSolids affiche des solides 3D éclairés. Les curseurs règlent la vitesse des objets et de "
            L"la caméra de 0 à 1 600 %, une à dix copies de chaque solide et une taille de 50 à 200 %. "
            L"Choisissez Observation de l’espace ou le Vol dans l’espace rectiligne, puis activez les "
            L"solides voulus. Les cases Éclairage principal, Éclairage d’appoint, Éclairage ambiant et "
            L"Éclairage des contours sous les curseurs contrôlent indépendamment l’éclairage des écrans "
            L"sélectionnés. L’éclairage ambiant fournit une luminosité de base aux surfaces, et l’éclairage "
            L"des contours souligne leurs bords. Les réglages sont enregistrés séparément pour l’application "
            L"et l’économiseur d’écran.\r\n\r\nÉCRANS\r\nLa sélection des lignes détermine les écrans à "
            L"configurer ; elle est distincte des cases qui activent les sorties d’animation. Ctrl+A "
            L"sélectionne tous les écrans ; Ctrl et Maj modifient la sélection. Toutes les options et tous "
            L"les curseurs d’animation concernent les écrans sélectionnés. La sélection est mémorisée "
            L"séparément pour EXE et SCR. Si tous les écrans étaient sélectionnés, les nouveaux le sont "
            L"également. Des valeurs différentes entre les écrans sélectionnés sont indiquées par des cases "
            L"à cocher indéterminées et des pointillés sur les boutons radio, les poignées des curseurs et "
            L"les boutons « Tout activer » et « Tout désactiver ». Les libellés des curseurs affichent un "
            L"tiret au lieu d’une valeur commune. Modifier une option ou cliquer sur un curseur applique "
            L"cette valeur à tous les écrans sélectionnés.\r\n\r\nCOMMANDES\r\nActivez ou désactivez les "
            L"sorties d’animation avec les cases des écrans ou en double-cliquant sur leurs lignes. Chaque "
            L"moniteur utilise une scène indépendante. Capture enregistre un PNG et le bouton "
            L"d’enregistrement démarre ou arrête un MP4. Pause arrête l’animation. L’application installe ou "
            L"désinstalle aussi son économiseur intégré. Les réglages sont enregistrés en continu. Une seule "
            L"instance de l’application peut fonctionner à la fois. Un nouveau lancement restaure la fenêtre "
            L"de contrôle réduite et la place au premier plan. Utilisez Tab et Maj+Tab pour passer d’un "
            L"contrôle à l’autre ; Alt et la lettre soulignée activent une commande. Échap ferme la fenêtre "
            L"d’aide ou À propos active ; dans la fenêtre de contrôle, cette touche quitte l’application. La "
            L"pause et le blocage de l’écran de veille s’appliquent à toute l’application, indépendamment "
            L"des écrans sélectionnés. Lorsque le blocage est activé, l’écran de veille Windows est empêché "
            L"uniquement tant qu’une animation visible et non suspendue s’affiche sur au moins un écran.\r\n"
            L"\r\nCAPTURES ET ENREGISTREMENT\r\nLes captures et les enregistrements utilisent le premier "
            L"moniteur d’animation actif, et non une image combinant tous les moniteurs. PNG utilise Images, "
            L"MP4 Vidéos ; Documents sert de repli si ces dossiers n’existent pas. Le bouton Réglages vidéo "
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
            L"ANIMATION ET PARAMÈTRES\r\nSélectionnez un ou plusieurs écrans dans la liste. Le mode de "
            L"caméra, les objets, l’éclairage, les vitesses, la taille et le nombre de copies ne "
            L"s’appliquent qu’aux écrans sélectionnés. Chaque écran mémorise ses propres réglages. "
            L"Choisissez Observation de l’espace ou le Vol dans l’espace rectiligne. Les curseurs règlent la "
            L"vitesse des objets et de la caméra de 0 à 1 600 %, une à dix copies et une taille de 50 à 200 "
            L"%. Les cases Éclairage principal, Éclairage d’appoint, Éclairage ambiant et Éclairage des "
            L"contours sous les curseurs contrôlent indépendamment l’éclairage des écrans sélectionnés. "
            L"L’éclairage ambiant fournit une luminosité de base aux surfaces, et l’éclairage des contours "
            L"souligne leurs bords. Les réglages sont enregistrés séparément pour l’application et "
            L"l’économiseur d’écran.\r\n\r\nÉCRANS\r\nLa sélection des lignes détermine les écrans à "
            L"configurer ; elle est distincte des cases qui activent les sorties d’animation. Ctrl+A "
            L"sélectionne tous les écrans ; Ctrl et Maj modifient la sélection. Toutes les options et tous "
            L"les curseurs d’animation concernent les écrans sélectionnés. La sélection est mémorisée "
            L"séparément pour EXE et SCR. Si tous les écrans étaient sélectionnés, les nouveaux le sont "
            L"également. Des valeurs différentes entre les écrans sélectionnés sont indiquées par des cases "
            L"à cocher indéterminées et des pointillés sur les boutons radio, les poignées des curseurs et "
            L"les boutons « Tout activer » et « Tout désactiver ». Les libellés des curseurs affichent un "
            L"tiret au lieu d’une valeur commune. Modifier une option ou cliquer sur un curseur applique "
            L"cette valeur à tous les écrans sélectionnés.\r\n\r\nAPERÇU ET COMMANDES\r\nActivez les solides "
            L"voulus. Activer l’aperçu lance un aperçu plein écran sur tous les moniteurs ; la boîte de "
            L"dialogue reste ouverte pour les réglages en direct. OK enregistre les réglages, Annuler les "
            L"abandonne. Échap ou un mouvement de souris quitte le plein écran. Utilisez Tab et Maj+Tab pour "
            L"passer d’un contrôle à l’autre ; Alt et la lettre soulignée activent une commande. Échap dans "
            L"les réglages équivaut à Annuler ; dans l’aide ou À propos, cette touche ferme uniquement cette "
            L"fenêtre.\r\n\r\nCONFIGURATION REQUISE\r\nWindows 7 à Windows 11 sont pris en charge. Pour "
            L"exécuter l’application sous Windows Vista SP2, il est nécessaire d’installer les mises à jour "
            L"KB971512 et KB2117917. L’affichage nécessite Direct3D 11, et pas seulement un ancien "
            L"environnement d’exécution DirectX."
        },
    }),
    DefineLanguage(LANG_ES, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Español" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Control" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Configuración de FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Idioma:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Velocidad de objetos: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Velocidad de cámara: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Observación del espacio" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Vuelo por el espacio" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Luz principal" },
        LocalizedText{ TXT_FILL_LIGHT, L"Luz de relleno" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Objetos 3D sólidos" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Cubo" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Pirámide cuadrangular regular" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Tronco de pirámide cuadrangular" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Pirámide cuadrangular, corte oblicuo" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Pirámide cuadrada, corte normal a la base" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Prisma triangular regular" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Prisma pentagonal regular" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Prisma hexagonal regular" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Octaedro regular" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Bipirámide pentagonal" },
        LocalizedText{ TXT_SOLID_CONE, L"Cono circular recto" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Tronco de cono" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Cono truncado por un plano oblicuo" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Cono, corte perpendicular a la base" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Cilindro circular recto" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Cilindro hueco" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Cilindro hueco con extremos toroidales" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Paraboloide de revolución cerrado por plano" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Esfera" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Hemisferio" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Segmento esférico" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Segmento esférico mayor" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Segmento esférico de dos bases" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Elipsoide triaxial" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Esferoide prolato" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Esferoide oblato" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoide" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Esferocilindro" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Disco redondeado (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Toro" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Al cerrar la aplicación se detendrá la grabación en curso."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Copias de cada objeto: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Tamaño de objetos: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Activar vista previa" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Desactivar vista previa" },
        LocalizedText{ TXT_PAUSED_STATUS, L"La animación está en pausa." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Bloquear salvapantallas durante la animación" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Luz ambiental" },
        LocalizedText{ TXT_RIM_LIGHT, L"Iluminación de contornos" },
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
            L"La desinstalación falló porque la configuración de FlyingSolids está abierta. Cierre esa "
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
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Animación acelerada por hardware de objetos 3D sólidos." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versión:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Plataforma de destino:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Sitio web:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Abrir en el navegador predeterminado" },
        LocalizedText{ TXT_COPY_URL, L"Copiar &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copiar &información" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Visitar el sitio web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"No se puede abrir el sitio en el navegador predeterminado."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"No se pudo copiar la URL al portapapeles." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"No se pudo copiar la información al portapapeles."
        },
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
            L"ANIMACIÓN Y AJUSTES\r\nSeleccione una o varias pantallas en la lista. El modo de cámara, los "
            L"objetos, la iluminación, las velocidades, el tamaño y el número de copias se aplican solo a "
            L"las pantallas seleccionadas. Cada pantalla guarda sus propios ajustes. FlyingSolids muestra "
            L"sólidos 3D iluminados. Los controles ajustan la velocidad de objetos y cámara entre 0 y 1600 "
            L"%, de una a diez copias y el tamaño entre 50 y 200 %. Elija Observación del espacio o el Vuelo "
            L"por el espacio en línea recta y active los sólidos deseados. Las casillas Luz principal, Luz "
            L"de relleno, Luz ambiental e Iluminación de contornos bajo los controles deslizantes controlan "
            L"de forma independiente la iluminación de las pantallas seleccionadas. La luz ambiental aporta "
            L"iluminación básica a las superficies y la iluminación de contornos resalta sus bordes. Los "
            L"ajustes se guardan por separado para la aplicación y el salvapantallas.\r\n\r\nMONITORES\r\nLa "
            L"selección de filas determina qué pantallas se están configurando; es independiente de las "
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
            L"ANIMACIÓN Y AJUSTES\r\nSeleccione una o varias pantallas en la lista. El modo de cámara, los "
            L"objetos, la iluminación, las velocidades, el tamaño y el número de copias se aplican solo a "
            L"las pantallas seleccionadas. Cada pantalla guarda sus propios ajustes. Elija Observación del "
            L"espacio o Vuelo por el espacio en línea recta. Los controles ajustan la velocidad de objetos y "
            L"cámara del 0 al 1600 %, de una a diez copias y el tamaño del 50 al 200 %. Las casillas Luz "
            L"principal, Luz de relleno, Luz ambiental e Iluminación de contornos bajo los controles "
            L"deslizantes controlan de forma independiente la iluminación de las pantallas seleccionadas. La "
            L"luz ambiental aporta iluminación básica a las superficies y la iluminación de contornos "
            L"resalta sus bordes. Los ajustes se guardan por separado para la aplicación y el "
            L"salvapantallas.\r\n\r\nMONITORES\r\nLa selección de filas determina qué pantallas se están "
            L"configurando; es independiente de las casillas que activan las salidas de animación. Ctrl+A "
            L"selecciona todas; Ctrl y Mayús modifican la selección. Todas las opciones y los controles "
            L"deslizantes de animación se aplican a las pantallas seleccionadas. La selección se recuerda "
            L"por separado para EXE y SCR. Si estaban seleccionadas todas, se incluyen también las nuevas. "
            L"Los valores distintos entre las pantallas seleccionadas se indican mediante casillas "
            L"indeterminadas y un punteado en los botones de opción, los tiradores de los controles "
            L"deslizantes y los botones «Activar todo» y «Desactivar todo». Las etiquetas de los controles "
            L"deslizantes muestran una raya en lugar de un valor común. Cambiar una opción o hacer clic en "
            L"un control deslizante aplica ese valor a todas las pantallas seleccionadas.\r\n\r\nVISTA "
            L"PREVIA Y CONTROLES\r\nActive los sólidos deseados. Activar vista previa inicia una vista "
            L"previa a pantalla completa en todos los monitores; el cuadro de configuración permanece "
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
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Controlli" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Impostazioni di FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Lingua:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Velocità oggetti: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Velocità della camera: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Osservazione dello spazio" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Volo nello spazio" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Luce principale" },
        LocalizedText{ TXT_FILL_LIGHT, L"Luce di riempimento" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Oggetti 3D solidi" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Cubo" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Piramide regolare a base quadrata" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Tronco di piramide quadrata" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Piramide quadrata troncata in obliquo" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT,
            L"Piramide quadrata, taglio normale alla base"
        },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Prisma retto a base triangolare regolare" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Prisma retto a base pentagonale regolare" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Prisma retto a base esagonale regolare" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Ottaedro regolare" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Bipiramide pentagonale" },
        LocalizedText{ TXT_SOLID_CONE, L"Cono circolare retto" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Tronco di cono" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Cono troncato da un piano obliquo" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Cono tagliato perpendicolarmente alla base" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Cilindro circolare retto" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Cilindro cavo" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Cilindro cavo con estremità toroidali" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Paraboloide di rotazione chiuso da un piano" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Sfera" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Emisfero" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Segmento sferico a una base" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Segmento sferico maggiore" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Segmento sferico a due basi" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Ellissoide triassiale" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Sferoide prolato" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Sferoide oblato" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoide" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sferocilindro" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Disco arrotondato (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Toro" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"La chiusura dell’applicazione interromperà la registrazione in corso."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Copie di ogni oggetto: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Dimensione oggetti: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Attiva anteprima" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Disattiva anteprima" },
        LocalizedText{ TXT_PAUSED_STATUS, L"L’animazione è in pausa." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blocca salvaschermo durante l’animazione" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Luce ambientale" },
        LocalizedText{ TXT_RIM_LIGHT, L"Illuminazione dei contorni" },
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
            L"La disinstallazione non è riuscita perché le impostazioni di FlyingSolids sono aperte. "
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
            L"Animazione con accelerazione hardware di oggetti 3D solidi."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versione:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Piattaforma di destinazione:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Sito web:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Apri nel browser predefinito" },
        LocalizedText{ TXT_COPY_URL, L"Copia &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copia &informazioni" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Visita il sito web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Impossibile aprire il sito nel browser predefinito." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Impossibile copiare l’URL negli Appunti." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Impossibile copiare le informazioni negli Appunti."
        },
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
            L"ANIMAZIONE E IMPOSTAZIONI\r\nSelezionare uno o più monitor nell’elenco. La modalità della "
            L"telecamera, gli oggetti, le luci, le velocità, le dimensioni e il numero di copie si applicano "
            L"solo ai monitor selezionati. Ogni monitor conserva le proprie impostazioni. FlyingSolids "
            L"mostra solidi 3D illuminati. I cursori regolano la velocità di oggetti e camera tra 0 e 1600 "
            L"%, da una a dieci copie e la dimensione tra 50 e 200 %. Scegliere Osservazione dello spazio o "
            L"il Volo nello spazio rettilineo e attivare i solidi desiderati. Le caselle Luce principale, "
            L"Luce di riempimento, Luce ambientale e Illuminazione dei contorni sotto i cursori controllano "
            L"indipendentemente l’illuminazione dei monitor selezionati. La luce ambientale fornisce "
            L"un’illuminazione di base alle superfici, mentre quella dei contorni ne evidenzia i bordi. Le "
            L"impostazioni vengono salvate separatamente per l’applicazione e il salvaschermo.\r\n\r\n"
            L"MONITOR\r\nLa selezione delle righe determina quali schermi si stanno configurando ed è "
            L"distinta dalle caselle che attivano le uscite di animazione. Ctrl+A seleziona tutti gli "
            L"schermi; Ctrl e Maiusc modificano la selezione. Tutte le opzioni e i cursori dell’animazione "
            L"riguardano gli schermi selezionati. La selezione viene memorizzata separatamente per EXE e "
            L"SCR. Se erano selezionati tutti gli schermi, vengono inclusi anche quelli nuovi. Valori "
            L"diversi tra gli schermi selezionati sono indicati da caselle di controllo indeterminate e da "
            L"una trama a punti sui pulsanti di opzione, sulle maniglie dei cursori e sui pulsanti «Attiva "
            L"tutto» e «Disattiva tutto». Le etichette dei cursori mostrano un trattino al posto di un "
            L"valore comune. Modificare un’opzione o fare clic su un cursore applica quel valore a tutti gli "
            L"schermi selezionati.\r\n\r\nCOMANDI\r\nAttivate o disattivate le uscite di animazione con le "
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
            L"ANIMAZIONE E IMPOSTAZIONI\r\nSelezionare uno o più monitor nell’elenco. La modalità della "
            L"telecamera, gli oggetti, le luci, le velocità, le dimensioni e il numero di copie si applicano "
            L"solo ai monitor selezionati. Ogni monitor conserva le proprie impostazioni. Scegliere "
            L"Osservazione dello spazio o Volo nello spazio rettilineo. I cursori regolano la velocità di "
            L"oggetti e camera da 0 a 1600 %, da una a dieci copie e la dimensione da 50 a 200 %. Le caselle "
            L"Luce principale, Luce di riempimento, Luce ambientale e Illuminazione dei contorni sotto i "
            L"cursori controllano indipendentemente l’illuminazione dei monitor selezionati. La luce "
            L"ambientale fornisce un’illuminazione di base alle superfici, mentre quella dei contorni ne "
            L"evidenzia i bordi. Le impostazioni vengono salvate separatamente per l’applicazione e il "
            L"salvaschermo.\r\n\r\nMONITOR\r\nLa selezione delle righe determina quali schermi si stanno "
            L"configurando ed è distinta dalle caselle che attivano le uscite di animazione. Ctrl+A "
            L"seleziona tutti gli schermi; Ctrl e Maiusc modificano la selezione. Tutte le opzioni e i "
            L"cursori dell’animazione riguardano gli schermi selezionati. La selezione viene memorizzata "
            L"separatamente per EXE e SCR. Se erano selezionati tutti gli schermi, vengono inclusi anche "
            L"quelli nuovi. Valori diversi tra gli schermi selezionati sono indicati da caselle di controllo "
            L"indeterminate e da una trama a punti sui pulsanti di opzione, sulle maniglie dei cursori e sui "
            L"pulsanti «Attiva tutto» e «Disattiva tutto». Le etichette dei cursori mostrano un trattino al "
            L"posto di un valore comune. Modificare un’opzione o fare clic su un cursore applica quel valore "
            L"a tutti gli schermi selezionati.\r\n\r\nANTEPRIMA E COMANDI\r\nAttivare i solidi desiderati. "
            L"Attiva anteprima avvia un’anteprima a schermo intero su tutti i monitor; le impostazioni "
            L"rimangono aperte per le modifiche in tempo reale. OK salva e Annulla scarta. Esc o il "
            L"movimento del mouse chiude il salvaschermo a schermo intero. Usare Tab e Maiusc+Tab per "
            L"passare tra i controlli; Alt e la lettera sottolineata attivano un comando. Esc nelle "
            L"impostazioni equivale ad Annulla; nella Guida o nelle Informazioni, chiude solo quella "
            L"finestra.\r\n\r\nREQUISITI DI SISTEMA\r\nSono supportati i sistemi da Windows 7 a Windows 11. "
            L"Per eseguire l’applicazione su Windows Vista SP2, è necessario installare gli aggiornamenti "
            L"KB971512 e KB2117917. La visualizzazione richiede Direct3D 11, non soltanto un vecchio runtime "
            L"DirectX."
        },
    }),
    DefineLanguage(LANG_PT, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Português" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Controlo" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Definições do FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Idioma:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Velocidade dos objetos: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Velocidade da câmara: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Observação do espaço" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Voo pelo espaço" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Luz principal" },
        LocalizedText{ TXT_FILL_LIGHT, L"Luz de preenchimento" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Objetos 3D sólidos" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Cubo" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Pirâmide quadrangular regular" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Tronco de pirâmide quadrangular" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Pirâmide quadrangular, corte oblíquo" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Pirâmide quadrada, corte normal à base" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Prisma triangular regular" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Prisma pentagonal regular" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Prisma hexagonal regular" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Octaedro regular" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Bipirâmide pentagonal" },
        LocalizedText{ TXT_SOLID_CONE, L"Cone circular reto" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Tronco de cone" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Cone truncado por um plano oblíquo" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Cone, corte perpendicular à base" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Cilindro circular reto" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Cilindro oco" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Cilindro oco com extremidades toroidais" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Paraboloide de revolução fechado por plano" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Esfera" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Hemisfério" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Segmento esférico" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Segmento esférico maior" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Segmento esférico de duas bases" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Elipsoide triaxial" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Esferoide prolato" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Esferoide oblato" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoide" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Esferocilindro" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Disco arredondado (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Toro" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Fechar a aplicação irá terminar a gravação em curso." },
        LocalizedText{ TXT_COPY_COUNT, L"Cópias de cada objeto: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Tamanho dos objetos: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Ativar pré-visualização" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Desativar pré-visualização" },
        LocalizedText{ TXT_PAUSED_STATUS, L"A animação está em pausa." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Bloquear proteção de ecrã durante a animação" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Luz ambiente" },
        LocalizedText{ TXT_RIM_LIGHT, L"Iluminação dos contornos" },
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
            L"A desinstalação falhou porque as definições do FlyingSolids estão abertas. Feche a janela e "
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
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Animação acelerada por hardware de objetos 3D sólidos." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versão:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Plataforma de destino:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Site:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Abrir no navegador predefinido" },
        LocalizedText{ TXT_COPY_URL, L"Copiar &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copiar &informações" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Visitar o site %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Não é possível abrir o sítio no navegador predefinido." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Não foi possível copiar o URL para a área de transferência."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Não foi possível copiar as informações para a área de transferência."
        },
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
            L"ANIMAÇÃO E DEFINIÇÕES\r\nSelecione um ou mais monitores na lista. O modo de câmara, os "
            L"objetos, a iluminação, as velocidades, o tamanho e o número de cópias aplicam-se apenas aos "
            L"monitores selecionados. Cada monitor guarda as suas próprias definições. O FlyingSolids mostra "
            L"sólidos 3D iluminados. Os controlos regulam a velocidade dos objetos e da câmara entre 0 e "
            L"1600%, uma a dez cópias e o tamanho entre 50 e 200%. Escolha Observação do espaço ou o Voo "
            L"pelo espaço em linha reta e ative os sólidos pretendidos. As caixas Luz principal, Luz de "
            L"preenchimento, Luz ambiente e Iluminação dos contornos sob os controlos deslizantes controlam "
            L"a iluminação dos monitores selecionados de forma independente. A luz ambiente fornece "
            L"iluminação de base às superfícies e a iluminação dos contornos realça os seus limites. As "
            L"definições são guardadas separadamente para a aplicação e a proteção de ecrã.\r\n\r\n"
            L"MONITORES\r\nA seleção das linhas determina os ecrãs a configurar e é independente das caixas "
            L"que ativam as saídas de animação. Ctrl+A seleciona todos os ecrãs; Ctrl e Shift alteram a "
            L"seleção. Todas as opções e controlos deslizantes da animação aplicam-se aos ecrãs "
            L"selecionados. A seleção é guardada separadamente para EXE e SCR. Se todos estavam "
            L"selecionados, os novos ecrãs também são incluídos. Valores diferentes entre os ecrãs "
            L"selecionados são indicados por caixas de verificação indeterminadas e por um padrão pontilhado "
            L"nos botões de opção, nas pegas dos controlos deslizantes e nos botões «Ativar tudo» e "
            L"«Desativar tudo». As etiquetas dos controlos deslizantes apresentam um travessão em vez de um "
            L"valor comum. Alterar uma opção ou clicar num controlo deslizante aplica esse valor a todos os "
            L"ecrãs selecionados.\r\n\r\nCONTROLOS\r\nAtive ou desative as saídas de animação através das "
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
            L"ANIMAÇÃO E DEFINIÇÕES\r\nSelecione um ou mais monitores na lista. O modo de câmara, os "
            L"objetos, a iluminação, as velocidades, o tamanho e o número de cópias aplicam-se apenas aos "
            L"monitores selecionados. Cada monitor guarda as suas próprias definições. Escolha Observação do "
            L"espaço ou Voo pelo espaço em linha reta. Regule a velocidade dos objetos e da câmara de 0 a "
            L"1600%, uma a dez cópias e o tamanho de 50 a 200%, e ative os sólidos. As caixas Luz principal, "
            L"Luz de preenchimento, Luz ambiente e Iluminação dos contornos sob os controlos deslizantes "
            L"controlam a iluminação dos monitores selecionados de forma independente. A luz ambiente "
            L"fornece iluminação de base às superfícies e a iluminação dos contornos realça os seus limites. "
            L"As definições são guardadas separadamente para a aplicação e a proteção de ecrã.\r\n\r\n"
            L"MONITORES\r\nA seleção das linhas determina os ecrãs a configurar e é independente das caixas "
            L"que ativam as saídas de animação. Ctrl+A seleciona todos os ecrãs; Ctrl e Shift alteram a "
            L"seleção. Todas as opções e controlos deslizantes da animação aplicam-se aos ecrãs "
            L"selecionados. A seleção é guardada separadamente para EXE e SCR. Se todos estavam "
            L"selecionados, os novos ecrãs também são incluídos. Valores diferentes entre os ecrãs "
            L"selecionados são indicados por caixas de verificação indeterminadas e por um padrão pontilhado "
            L"nos botões de opção, nas pegas dos controlos deslizantes e nos botões «Ativar tudo» e "
            L"«Desativar tudo». As etiquetas dos controlos deslizantes apresentam um travessão em vez de um "
            L"valor comum. Alterar uma opção ou clicar num controlo deslizante aplica esse valor a todos os "
            L"ecrãs selecionados.\r\n\r\nPRÉ-VISUALIZAÇÃO E CONTROLOS\r\nAtivar pré-visualização inicia uma "
            L"pré-visualização em ecrã inteiro em todos os monitores; o diálogo permanece aberto para "
            L"ajustar as definições em tempo real. OK guarda as definições e Cancelar descarta-as. Esc ou o "
            L"movimento do rato termina a proteção em ecrã inteiro. Use Tab e Shift+Tab para passar entre "
            L"controlos; Alt e a letra sublinhada ativam um comando. Esc nas definições equivale a Cancelar; "
            L"na Ajuda ou em Acerca de, fecha apenas essa janela.\r\n\r\nREQUISITOS DO SISTEMA\r\nSão "
            L"suportados os sistemas Windows 7 a Windows 11. Para executar a aplicação no Windows Vista SP2, "
            L"é necessário instalar as atualizações KB971512 e KB2117917. A apresentação requer Direct3D 11, "
            L"não apenas um runtime DirectX mais antigo."
        },
    }),
    DefineLanguage(LANG_PL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Polski" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Sterowanie" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Ustawienia FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Język:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Prędkość obiektów: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Prędkość kamery: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Obserwacja przestrzeni" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Przelot przez przestrzeń" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Światło główne" },
        LocalizedText{ TXT_FILL_LIGHT, L"Światło wypełniające" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Pełne obiekty 3D" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Sześcian" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Ostrosłup prawidłowy czworokątny" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Ostrosłup ścięty prawidłowy czworokątny" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Ostrosłup czworokątny, cięcie ukośne" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Ostrosłup, cięcie prostopadłe do podstawy" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Graniastosłup prawidłowy trójkątny" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Graniastosłup prawidłowy pięciokątny" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Graniastosłup prawidłowy sześciokątny" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Ośmiościan foremny" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Dwupiramida pięciokątna" },
        LocalizedText{ TXT_SOLID_CONE, L"Stożek obrotowy" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Stożek ścięty" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Stożek ścięty płaszczyzną ukośną" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Stożek, cięcie prostopadłe do podstawy" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Walec obrotowy" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Walec pusty" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Walec pusty z toroidalnymi końcami" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Paraboloida obrotowa zamknięta płaszczyzną" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Kula" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Półkula" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Odcinek kuli" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Duży odcinek kuli" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Warstwa kulista" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Elipsoida trójosiowa" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Sferoida wydłużona" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Sferoida spłaszczona" },
        LocalizedText{ TXT_SOLID_EGG, L"Owoida" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sferocylinder" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Zaokrąglony dysk (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Torus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Zamknięcie aplikacji zakończy trwające nagrywanie." },
        LocalizedText{ TXT_COPY_COUNT, L"Liczba kopii każdego obiektu: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Rozmiar obiektów: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Włącz podgląd" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Wyłącz podgląd" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animacja jest wstrzymana." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blokuj wygaszacz podczas animacji" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Światło otoczenia" },
        LocalizedText{ TXT_RIM_LIGHT, L"Oświetlenie konturów" },
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
            L"Odinstalowanie nie powiodło się, ponieważ ustawienia FlyingSolids są otwarte. Zamknij okno i "
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
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Sprzętowo przyspieszana animacja pełnych obiektów 3D." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Wersja:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Platforma docelowa:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Witryna:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Otwórz w domyślnej przeglądarce" },
        LocalizedText{ TXT_COPY_URL, L"Kopiuj &adres URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopiuj &informacje" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Odwiedź witrynę %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Nie można otworzyć witryny w domyślnej przeglądarce." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Nie można skopiować adresu URL do schowka." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Nie można skopiować informacji do schowka." },
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
            L"ANIMACJA I USTAWIENIA\r\nZaznacz jeden lub więcej monitorów na liście. Tryb kamery, wybór "
            L"brył, oświetlenie, prędkości, rozmiar i liczba kopii dotyczą tylko zaznaczonych monitorów. "
            L"Każdy monitor zapamiętuje własne ustawienia. FlyingSolids wyświetla oświetlone pełne bryły 3D. "
            L"Suwaki ustawiają prędkość obiektów i kamery od 0 do 1600%, od jednej do dziesięciu kopii i "
            L"rozmiar od 50 do 200%. Wybierz Obserwację przestrzeni lub prostoliniowy Przelot przez "
            L"przestrzeń i włącz potrzebne bryły. Pola wyboru Światło główne, Światło wypełniające, Światło "
            L"otoczenia i Oświetlenie konturów pod suwakami niezależnie sterują oświetleniem zaznaczonych "
            L"monitorów. Światło otoczenia zapewnia podstawową jasność powierzchni, a oświetlenie konturów "
            L"podkreśla krawędzie. Ustawienia są zapisywane osobno dla aplikacji i wygaszacza ekranu.\r\n\r\n"
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
            L"ANIMACJA I USTAWIENIA\r\nZaznacz jeden lub więcej monitorów na liście. Tryb kamery, wybór "
            L"brył, oświetlenie, prędkości, rozmiar i liczba kopii dotyczą tylko zaznaczonych monitorów. "
            L"Każdy monitor zapamiętuje własne ustawienia. Wybierz Obserwację przestrzeni albo prostoliniowy "
            L"Przelot przez przestrzeń. Suwaki ustawiają prędkość obiektów i kamery 0–1600%, od jednej do "
            L"dziesięciu kopii i rozmiar 50–200%. Pola wyboru Światło główne, Światło wypełniające, Światło "
            L"otoczenia i Oświetlenie konturów pod suwakami niezależnie sterują oświetleniem zaznaczonych "
            L"monitorów. Światło otoczenia zapewnia podstawową jasność powierzchni, a oświetlenie konturów "
            L"podkreśla krawędzie. Ustawienia są zapisywane osobno dla aplikacji i wygaszacza ekranu.\r\n\r\n"
            L"MONITORY\r\nZaznaczenie wierszy określa konfigurowane monitory i jest niezależne od pól wyboru "
            L"włączających wyjścia animacji. Ctrl+A zaznacza wszystkie monitory; Ctrl i Shift zmieniają "
            L"zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą zaznaczonych monitorów. Zaznaczenie "
            L"jest zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były wszystkie monitory, nowe "
            L"również zostaną zaznaczone. Różne wartości na zaznaczonych monitorach są sygnalizowane "
            L"nieokreślonym stanem pól wyboru i kropkowaniem przycisków opcji, uchwytów suwaków oraz "
            L"przycisków „Włącz wszystko” i „Wyłącz wszystko”. Etykiety suwaków pokazują kreskę zamiast "
            L"wspólnej wartości. Zmiana opcji lub kliknięcie suwaka ustawia tę wartość na wszystkich "
            L"zaznaczonych monitorach.\r\n\r\nPODGLĄD I OBSŁUGA\r\nWłącz potrzebne bryły. Włącz podgląd "
            L"uruchamia podgląd pełnoekranowy na wszystkich monitorach. Okno ustawień pozostaje otwarte, "
            L"umożliwiając zmiany na bieżąco. OK zapisuje ustawienia, a Anuluj je odrzuca. Esc lub ruch "
            L"myszy kończy tryb pełnoekranowy. Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt "
            L"i podkreślona litera wywołują polecenie. Esc w ustawieniach odpowiada przyciskowi Anuluj; w "
            L"Pomocy lub O programie zamyka tylko to okno.\r\n\r\nWYMAGANIA SYSTEMOWE\r\nObsługiwane są "
            L"systemy od Windows 7 do Windows 11. Do uruchomienia aplikacji w systemie Windows Vista SP2 "
            L"konieczne jest zainstalowanie aktualizacji KB971512 i KB2117917. Wyświetlanie wymaga Direct3D "
            L"11, a nie tylko starszego środowiska DirectX."
        },
    }),
    DefineLanguage(LANG_SK, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Slovenčina" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Ovládanie" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Nastavenia FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Jazyk:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Rýchlosť objektov: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Rýchlosť kamery: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Pozorovanie priestoru" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Prelet priestorom" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Hlavné svetlo" },
        LocalizedText{ TXT_FILL_LIGHT, L"Doplnkové svetlo" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Plné priestorové objekty" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Kocka" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Pravidelný štvorboký ihlan" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Komolý štvorboký ihlan" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Štvorboký ihlan so šikmým rezom" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Štvorboký ihlan, rez kolmý na podstavu" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Pravidelný trojboký hranol" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Pravidelný päťboký hranol" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Pravidelný šesťboký hranol" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Pravidelný osemsten" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Päťboký dvojihlan" },
        LocalizedText{ TXT_SOLID_CONE, L"Rotačný kužeľ" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Komolý rotačný kužeľ" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Rotačný kužeľ so šikmým rezom" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Rotačný kužeľ s rezom kolmým na podstavu" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Rotačný valec" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Dutý rotačný valec" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Dutý valec s toroidálnymi čelami" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Rotačný paraboloid uzavretý rovinou" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Guľa" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Pologuľa" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Guľový odsek" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Veľký guľový odsek" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Guľová vrstva" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Trojosový elipsoid" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Predĺžený rotačný elipsoid" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Sploštený rotačný elipsoid" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoid" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sferocylinder" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Zaoblený disk (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Anuloid (torus)" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Ukončenie aplikácie ukončí práve prebiehajúci záznam."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Počet kópií každého objektu: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Veľkosť objektov: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Zapnúť náhľad" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Vypnúť náhľad" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animácia je pozastavená." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blokovať šetrič pri animácii" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Základný jas" },
        LocalizedText{ TXT_RIM_LIGHT, L"Prisvetlenie obrysov" },
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
            L"Odinštalovanie zlyhalo, pretože sú otvorené nastavenia FlyingSolids. Zatvorte ich a skúste to "
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
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardvérovo akcelerovaná animácia plných 3D objektov." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Verzia:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Cieľová platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Web:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Otvoriť v predvolenom prehliadači" },
        LocalizedText{ TXT_COPY_URL, L"Kopírovať &adresu" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopírovať &informácie" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Navštíviť web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Web nemožno otvoriť v predvolenom prehliadači." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Adresu URL nemožno skopírovať do schránky." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Informácie nemožno skopírovať do schránky." },
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
            L"ANIMÁCIA A NASTAVENIA\r\nV zozname označte jeden alebo viac monitorov. Režim kamery, výber "
            L"telies, svetlá, rýchlosti, veľkosť a počet kópií sa nastavujú len pre označené monitory a "
            L"každý monitor si pamätá vlastné nastavenia. FlyingSolids zobrazuje osvetlené plné 3D telesá. "
            L"Jazdce nastavujú rýchlosť objektov a kamery 0–1600 %, jednu až desať kópií a veľkosť 50–200 %. "
            L"Vyberte Pozorovanie priestoru alebo priamy Prelet priestorom a zapnite požadované telesá. "
            L"Začiarkavacie políčka Hlavné svetlo, Doplnkové svetlo, Základný jas a Prisvetlenie obrysov pod "
            L"jazdcami nezávisle ovládajú osvetlenie scén na označených monitoroch. Základný jas prisvetľuje "
            L"povrchy telies a prisvetlenie obrysov zvýrazňuje ich okraje. Nastavenia osvetlenia sa ukladajú "
            L"zvlášť pre aplikáciu a šetrič obrazovky.\r\n\r\nMONITORY\r\nOznačenie riadkov určuje, ktoré "
            L"monitory práve nastavujete; je nezávislé od políčok zapínajúcich animačné výstupy. Ctrl+A "
            L"označí všetky monitory, Ctrl a Shift upravujú označenie. Všetky animačné voľby a posuvníky "
            L"platia pre označené monitory. Označenie sa pamätá zvlášť pre EXE a SCR. Ak boli označené "
            L"všetky monitory, označia sa aj novopripojené. Rozdielne hodnoty na označených monitoroch "
            L"ukazuje neurčitý stav políčok a bodkovanie prepínačov, úchytov posuvníkov a tlačidiel „Všetko "
            L"zapnúť“ a „Všetko vypnúť“. Popis posuvníka namiesto spoločnej hodnoty zobrazuje pomlčku. Zmena "
            L"voľby alebo kliknutie na posuvník zjednotí príslušnú hodnotu na označených monitoroch.\r\n\r\n"
            L"OVLÁDANIE\r\nAnimačné výstupy zapnete alebo vypnete políčkami pri monitoroch alebo dvojklikom "
            L"na ich riadky. Každý monitor používa nezávislú scénu. Snímka uloží PNG a tlačidlo záznamu "
            L"spustí alebo ukončí MP4. Pozastavenie zastaví animáciu. Aplikácia tiež nainštaluje alebo "
            L"odinštaluje vložený šetrič. Nastavenia sa ukladajú priebežne. Aplikácia beží iba v jednej "
            L"inštancii. Ďalšie spustenie obnoví minimalizované ovládacie okno a prenesie ho do popredia. "
            L"Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte "
            L"pomocou Alt a príslušného písmena. Esc zavrie aktívne okno Pomoc alebo O aplikácii; v "
            L"ovládacom okne ukončí aplikáciu. Pozastavenie a blokovanie šetriča platia pre celú aplikáciu "
            L"bez ohľadu na označené monitory. Ak je blokovanie zapnuté, bráni spusteniu šetriča Windows iba "
            L"vtedy, keď je aspoň na jednom monitore viditeľná nepozastavená animácia.\r\n\r\nSNÍMKY A "
            L"ZÁZNAM\r\nSnímky a záznamy zachytávajú prvý aktívny animačný monitor, nie spoločnú plochu "
            L"všetkých monitorov. PNG používa Obrázky, MP4 Videá; ak tieto priečinky neexistujú, použijú sa "
            L"Dokumenty. Tlačidlo Nastavenie záznamu vyberá Viewport alebo TV. Viewport zachováva rozmery "
            L"animačného monitora a jeho obnovovaciu frekvenciu, najviac 60 snímok za sekundu. TV ponúka "
            L"rozlíšenie 1920 × 1080, 1440 × 1080 alebo 1280 × 720 v pomere 16:9 a frekvenciu 50, 25, 59.94 "
            L"(60000/1001) alebo 29.97 (30000/1001) snímok za sekundu. Obraz zachováva pomer strán; TV "
            L"používa progresívne video BT.709 s obmedzeným rozsahom a vzorkovaním 4:2:0. Rozlíšenie a "
            L"snímkovú frekvenciu možno vybrať iba v režime TV. Okno Nastavenie záznamu možno minimalizovať "
            L"a neblokuje ostatné okná aplikácie. OK uloží voľby pre nasledujúci záznam MP4; Zrušiť alebo "
            L"Esc zahodí nepotvrdené zmeny. Animačný výstup nahrávaného monitora nemožno počas záznamu "
            L"vypnúť; zmeny ostatných monitorov záznam nezastavia. Ukončenie aplikácie počas záznamu "
            L"vyžaduje potvrdenie, pretože ukončí aj záznam.\r\n\r\nSYSTÉMOVÉ POŽIADAVKY\r\nWindows 7 až "
            L"Windows 11 podporujú všetky funkcie vrátane snímok PNG a záznamu MP4. Na spustenie aplikácie v "
            L"systéme Windows Vista SP2 je potrebné nainštalovať aktualizácie KB971512 a KB2117917. Záznam "
            L"MP4 na Viste v súčasnej verzii nefunguje. Vykresľovanie vyžaduje Direct3D 11, nie iba starší "
            L"DirectX runtime. Záznam MP4 vyžaduje dostupné súčasti Media Foundation a kodér H.264."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMÁCIA A NASTAVENIA\r\nV zozname označte jeden alebo viac monitorov. Režim kamery, výber "
            L"telies, svetlá, rýchlosti, veľkosť a počet kópií sa nastavujú len pre označené monitory a "
            L"každý monitor si pamätá vlastné nastavenia. Vyberte Pozorovanie priestoru alebo priamy Prelet "
            L"priestorom. Jazdce nastavujú rýchlosť objektov a kamery 0–1600 %, jednu až desať kópií a "
            L"veľkosť 50–200 %. Začiarkavacie políčka Hlavné svetlo, Doplnkové svetlo, Základný jas a "
            L"Prisvetlenie obrysov pod jazdcami nezávisle ovládajú osvetlenie scén na označených monitoroch. "
            L"Základný jas prisvetľuje povrchy telies a prisvetlenie obrysov zvýrazňuje ich okraje. "
            L"Nastavenia osvetlenia sa ukladajú zvlášť pre aplikáciu a šetrič obrazovky.\r\n\r\nMONITORY\r\n"
            L"Označenie riadkov určuje, ktoré monitory práve nastavujete; je nezávislé od políčok "
            L"zapínajúcich animačné výstupy. Ctrl+A označí všetky monitory, Ctrl a Shift upravujú označenie. "
            L"Všetky animačné voľby a posuvníky platia pre označené monitory. Označenie sa pamätá zvlášť pre "
            L"EXE a SCR. Ak boli označené všetky monitory, označia sa aj novopripojené. Rozdielne hodnoty na "
            L"označených monitoroch ukazuje neurčitý stav políčok a bodkovanie prepínačov, úchytov "
            L"posuvníkov a tlačidiel „Všetko zapnúť“ a „Všetko vypnúť“. Popis posuvníka namiesto spoločnej "
            L"hodnoty zobrazuje pomlčku. Zmena voľby alebo kliknutie na posuvník zjednotí príslušnú hodnotu "
            L"na označených monitoroch.\r\n\r\nNÁHĽAD A OVLÁDANIE\r\nZapnite požadované telesá. Zapnúť "
            L"náhľad spustí celoobrazovkový náhľad na všetkých monitoroch; nastavenia zostávajú otvorené a "
            L"zmeny sa prejavia ihneď. OK uloží nastavenia a Zrušiť ich zahodí. Celoobrazovkový šetrič "
            L"ukončí Esc alebo pohyb myši. Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; "
            L"podčiarknuté voľby vyvoláte pomocou Alt a príslušného písmena. Esc v nastaveniach zodpovedá "
            L"tlačidlu Zrušiť; v okne Pomoc alebo O aplikácii zavrie iba toto okno.\r\n\r\nSYSTÉMOVÉ "
            L"POŽIADAVKY\r\nPodporované sú systémy Windows 7 až Windows 11. Na spustenie aplikácie v systéme "
            L"Windows Vista SP2 je potrebné nainštalovať aktualizácie KB971512 a KB2117917. Vykresľovanie "
            L"vyžaduje Direct3D 11, nie iba starší DirectX runtime."
        },
    }),
    DefineLanguage(LANG_DA, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Dansk" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Styring" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Indstillinger for FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Sprog:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Objekthastighed: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Kamerahastighed: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Rumobservation" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Flyvning gennem rummet" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Hovedlys" },
        LocalizedText{ TXT_FILL_LIGHT, L"Udfyldningslys" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Solide 3D-objekter" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Terning" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Regulær firsidet pyramide" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Afkortet firsidet pyramide" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Firsidet pyramide skåret med et skråt plan" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Firkantpyramide, snit vinkelret på basen" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Regulært trekantet prisme" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Regulært femkantet prisme" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Regulært sekskantet prisme" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Regulært oktaeder" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Femkantet bipyramide" },
        LocalizedText{ TXT_SOLID_CONE, L"Ret cirkulær kegle" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Afkortet kegle" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Kegle skåret med et skråt plan" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Kegle med snit vinkelret på grundfladen" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Ret cirkulær cylinder" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Hul cylinder" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Hul cylinder med toroidale ender" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Rotationsparaboloide lukket af et plan" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Kugle" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Halvkugle" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Kuglesegment" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Stort kuglesegment" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Kuglelag" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Treakset ellipsoide" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Prolat sfæroide" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Fladtrykt sfæroide" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoide" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sfærocylinder" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Afrundet skive (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Torus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Hvis du lukker programmet, stoppes den igangværende optagelse."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Kopier af hvert objekt: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Objektstørrelse: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Aktivér forhåndsvisning" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Deaktivér forhåndsvisning" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animationen er sat på pause." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blokér pauseskærm under animation" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Omgivende lys" },
        LocalizedText{ TXT_RIM_LIGHT, L"Konturlys" },
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
            L"Afinstallationen mislykkedes, fordi indstillingerne for FlyingSolids er åbne. Luk vinduet, og "
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
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardwareaccelereret animation af solide 3D-objekter." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Version:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Målplatform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Websted:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Åbn i standardbrowseren" },
        LocalizedText{ TXT_COPY_URL, L"Kopiér &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopiér &oplysninger" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Besøg webstedet %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Webstedet kan ikke åbnes i standardbrowseren." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL-adressen kunne ikke kopieres til udklipsholderen." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Oplysningerne kunne ikke kopieres til udklipsholderen."
        },
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
            L"ANIMATION OG INDSTILLINGER\r\nVælg en eller flere skærme på listen. Kameratilstand, objekter, "
            L"belysning, hastigheder, størrelse og antal kopier gælder kun de valgte skærme. Hver skærm "
            L"husker sine egne indstillinger. FlyingSolids viser belyste solide 3D-legemer. Skyderne "
            L"indstiller objekt- og kamerahastighed 0–1600 %, en til ti kopier og størrelse 50–200 %. Vælg "
            L"Rumobservation eller Flyvning gennem rummet i en lige linje og aktivér de ønskede legemer. "
            L"Afkrydsningsfelterne Hovedlys, Udfyldningslys, Omgivende lys og Konturlys under skyderne "
            L"styrer belysningen på de valgte skærme uafhængigt af hinanden. Omgivende lys giver "
            L"overfladerne en grundbelysning, og konturlys fremhæver kanterne. Indstillingerne gemmes "
            L"separat for programmet og pauseskærmen.\r\n\r\nSKÆRME\r\nMarkeringen af rækker bestemmer, "
            L"hvilke skærme du indstiller, og er adskilt fra afkrydsningsfelterne, der aktiverer "
            L"animationsoutput. Ctrl+A markerer alle skærme; Ctrl og Skift ændrer markeringen. Alle "
            L"animationsvalg og skydere gælder de markerede skærme. Markeringen huskes separat for EXE og "
            L"SCR. Hvis alle skærme var markeret, medtages også nye skærme. Forskellige værdier på de "
            L"markerede skærme vises med ubestemte afkrydsningsfelter og prikmønstre på alternativknapper, "
            L"skydergreb og knapperne “Aktivér alle” og “Deaktivér alle”. Skydernes etiketter viser en "
            L"tankestreg i stedet for en fælles værdi. Ændring af et valg eller klik på en skyder anvender "
            L"denne værdi på alle markerede skærme.\r\n\r\nBETJENING\r\nSlå animationsoutput til eller fra "
            L"med skærmenes afkrydsningsfelter eller ved at dobbeltklikke på deres rækker. Hver skærm bruger "
            L"en uafhængig scene. Skærmbillede gemmer PNG, og optageknappen starter eller stopper MP4. Pause "
            L"standser animationen. Programmet installerer eller afinstallerer også den indbyggede "
            L"pauseskærm. Indstillinger gemmes løbende. Programmet kan kun køre i én instans ad gangen. En "
            L"ny start gendanner det minimerede kontrolvindue og bringer det forrest. Brug Tab og Skift+Tab "
            L"til at flytte mellem kontrollerne; Alt og det understregede bogstav aktiverer en kommando. Esc "
            L"lukker det aktive Hjælp- eller Om-vindue; i kontrolvinduet afslutter det programmet. Pause og "
            L"blokering af pauseskærmen gælder hele programmet uanset skærmmarkeringen. Når blokering er "
            L"slået til, forhindres Windows-pauseskærmen kun, mens der vises en synlig animation, som ikke "
            L"er sat på pause, på mindst én skærm.\r\n\r\nSKÆRMBILLEDER OG OPTAGELSE\r\nSkærmbilleder og "
            L"optagelser bruger den første aktive animationsskærm, ikke et samlet billede af alle skærme. "
            L"PNG bruger Billeder, MP4 Videoer; hvis disse mapper ikke findes, bruges Dokumenter. Knappen "
            L"Optagelsesindstillinger vælger Viewport eller TV. Viewport bevarer animationsskærmens "
            L"størrelse og opdateringsfrekvens, højst 60 billeder i sekundet. TV tilbyder 1920 × 1080, 1440 "
            L"× 1080 eller 1280 × 720 i formatet 16:9 med 50, 25, 59.94 (60000/1001) eller 29.97 "
            L"(30000/1001) billeder i sekundet. Billedets proportioner bevares; TV bruger progressiv "
            L"BT.709-video med begrænset område og 4:2:0-sampling. Opløsning og billedfrekvens kan kun "
            L"vælges i TV-tilstand. Vinduet Optagelsesindstillinger kan minimeres og blokerer ikke de andre "
            L"programvinduer. OK gemmer valgene til den næste MP4-optagelse; Annuller eller Esc kasserer "
            L"ubekræftede ændringer. Animationsoutputtet på den skærm, der optages, kan ikke slås fra under "
            L"optagelsen; ændringer af andre skærme stopper ikke optagelsen. Hvis programmet lukkes under en "
            L"optagelse, kræves en bekræftelse, fordi optagelsen også afsluttes.\r\n\r\nSYSTEMKRAV\r\n"
            L"Windows 7 til Windows 11 understøtter alle funktioner, herunder PNG-skærmbilleder og "
            L"MP4-optagelse. For at køre programmet på Windows Vista SP2 skal opdateringerne KB971512 og "
            L"KB2117917 installeres. MP4-optagelse fungerer ikke på Vista i den aktuelle version. Visningen "
            L"kræver Direct3D 11, ikke kun et ældre DirectX-kørselsmiljø. MP4-optagelse kræver tilgængelige "
            L"Media Foundation-komponenter og en H.264-koder."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMATION OG INDSTILLINGER\r\nVælg en eller flere skærme på listen. Kameratilstand, objekter, "
            L"belysning, hastigheder, størrelse og antal kopier gælder kun de valgte skærme. Hver skærm "
            L"husker sine egne indstillinger. Vælg Rumobservation eller Flyvning gennem rummet i en lige "
            L"linje. Indstil objekt- og kamerahastighed 0–1600 %, en til ti kopier og størrelse 50–200 %, og "
            L"aktivér de ønskede legemer. Afkrydsningsfelterne Hovedlys, Udfyldningslys, Omgivende lys og "
            L"Konturlys under skyderne styrer belysningen på de valgte skærme uafhængigt af hinanden. "
            L"Omgivende lys giver overfladerne en grundbelysning, og konturlys fremhæver kanterne. "
            L"Indstillingerne gemmes separat for programmet og pauseskærmen.\r\n\r\nSKÆRME\r\nMarkeringen af "
            L"rækker bestemmer, hvilke skærme du indstiller, og er adskilt fra afkrydsningsfelterne, der "
            L"aktiverer animationsoutput. Ctrl+A markerer alle skærme; Ctrl og Skift ændrer markeringen. "
            L"Alle animationsvalg og skydere gælder de markerede skærme. Markeringen huskes separat for EXE "
            L"og SCR. Hvis alle skærme var markeret, medtages også nye skærme. Forskellige værdier på de "
            L"markerede skærme vises med ubestemte afkrydsningsfelter og prikmønstre på alternativknapper, "
            L"skydergreb og knapperne “Aktivér alle” og “Deaktivér alle”. Skydernes etiketter viser en "
            L"tankestreg i stedet for en fælles værdi. Ændring af et valg eller klik på en skyder anvender "
            L"denne værdi på alle markerede skærme.\r\n\r\nFORHÅNDSVISNING OG BETJENING\r\nAktivér "
            L"forhåndsvisning starter en forhåndsvisning i fuld skærm på alle skærme. Indstillingerne "
            L"forbliver åbne, og ændringerne vises med det samme. OK gemmer indstillingerne, og Annuller "
            L"forkaster ændringerne. Esc eller musebevægelse afslutter fuldskærmen. Brug Tab og Skift+Tab "
            L"til at flytte mellem kontrollerne; Alt og det understregede bogstav aktiverer en kommando. Esc "
            L"i indstillingerne svarer til Annuller; i Hjælp eller Om lukker det kun dette vindue.\r\n\r\n"
            L"SYSTEMKRAV\r\nWindows 7 til Windows 11 understøttes. For at køre programmet på Windows Vista "
            L"SP2 skal opdateringerne KB971512 og KB2117917 installeres. Visningen kræver Direct3D 11, ikke "
            L"kun et ældre DirectX-kørselsmiljø."
        },
    }),
    DefineLanguage(LANG_FI, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Suomi" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Ohjaus" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlyingSolids-asetukset" },
        LocalizedText{ TXT_LANGUAGE, L"Kieli:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Kohteiden nopeus: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Kameran nopeus: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Avaruuden tarkkailu" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Lento avaruuden halki" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Päävalo" },
        LocalizedText{ TXT_FILL_LIGHT, L"Täytevalo" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Kiinteät 3D-kohteet" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Kuutio" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Säännöllinen neliöpyramidi" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Katkaistu neliöpyramidi" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Neliöpyramidi, vino leikkaus" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Pyramidi, leikkaus kohtisuoraan pohjaan" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Säännöllinen kolmioprisma" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Säännöllinen viisikulmainen prisma" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Säännöllinen kuusikulmainen prisma" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Säännöllinen oktaedri" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Viisikulmainen kaksoispyramidi" },
        LocalizedText{ TXT_SOLID_CONE, L"Suora ympyräkartio" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Katkaistu kartio" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Kartio vinolla tasolla leikattuna" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Kartio, pohjaan nähden kohtisuora leikkaus" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Suora ympyrälieriö" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Ontto lieriö" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Ontto lieriö, toroidiset päädyt" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Tasolla suljettu pyörähdysparaboloidi" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Pallo" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Puolipallo" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Pallosegmentti" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Suuri pallosegmentti" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Katkaistu pallosegmentti" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Kolmiakselinen ellipsoidi" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Prolaatti sferoidi" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Litteä sferoidi" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoidi" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sferosylinteri" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Pyöristetty kiekko (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Torus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Sovelluksen sulkeminen lopettaa käynnissä olevan tallennuksen."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Kunkin kohteen kopioita: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Kohteiden koko: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Ota esikatselu käyttöön" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Poista esikatselu käytöstä" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animaatio on keskeytetty." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Estä näytönsäästäjä animaation aikana" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ympäristövalo" },
        LocalizedText{ TXT_RIM_LIGHT, L"Reunavalo" },
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
            L"Asennuksen poisto epäonnistui, koska FlyingSolids-asetukset ovat avoinna. Sulje ikkuna ja "
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
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Laitteistokiihdytetty kiinteiden 3D-kohteiden animaatio." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versio:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Kohdealusta:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Verkkosivusto:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Avaa oletusselaimessa" },
        LocalizedText{ TXT_COPY_URL, L"Kopioi &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopioi &tiedot" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Käy verkkosivustolla %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Sivustoa ei voi avata oletusselaimessa." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL-osoitetta ei voitu kopioida leikepöydälle." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Tietoja ei voitu kopioida leikepöydälle." },
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
            L"ANIMAATIO JA ASETUKSET\r\nValitse luettelosta yksi tai useampi näyttö. Kameratila, kappaleet, "
            L"valaistus, nopeudet, koko ja kopioiden määrä koskevat vain valittuja näyttöjä. Jokainen näyttö "
            L"muistaa omat asetuksensa. FlyingSolids näyttää valaistuja kiinteitä 3D-kappaleita. "
            L"Liukusäätimillä asetetaan kohteiden ja kameran nopeus 0–1600 %, yhdestä kymmeneen kopiota ja "
            L"koko 50–200 %. Valitse Avaruuden tarkkailu tai Lento avaruuden halki suoraan eteenpäin ja ota "
            L"halutut kappaleet käyttöön. Liukusäätimien alla olevat Päävalo-, Täytevalo-, Ympäristövalo- ja "
            L"Reunavalo-valintaruudut ohjaavat valittujen näyttöjen valaistusta toisistaan riippumatta. "
            L"Ympäristövalo antaa pinnoille perusvalaistuksen ja reunavalo korostaa reunoja. Asetukset "
            L"tallennetaan erikseen sovellukselle ja näytönsäästäjälle.\r\n\r\nNÄYTÖT\r\nRivien valinta "
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
            L"ANIMAATIO JA ASETUKSET\r\nValitse luettelosta yksi tai useampi näyttö. Kameratila, kappaleet, "
            L"valaistus, nopeudet, koko ja kopioiden määrä koskevat vain valittuja näyttöjä. Jokainen näyttö "
            L"muistaa omat asetuksensa. Valitse Avaruuden tarkkailu tai Lento avaruuden halki suoraan "
            L"eteenpäin. Aseta kohteiden ja kameran nopeus 0–1600 %, yhdestä kymmeneen kopiota ja koko "
            L"50–200 %, ja ota halutut kappaleet käyttöön. Liukusäätimien alla olevat Päävalo-, Täytevalo-, "
            L"Ympäristövalo- ja Reunavalo-valintaruudut ohjaavat valittujen näyttöjen valaistusta toisistaan "
            L"riippumatta. Ympäristövalo antaa pinnoille perusvalaistuksen ja reunavalo korostaa reunoja. "
            L"Asetukset tallennetaan erikseen sovellukselle ja näytönsäästäjälle.\r\n\r\nNÄYTÖT\r\nRivien "
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
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Stjórnun" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Stillingar FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Tungumál:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Hraði hluta: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Hraði myndavélar: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Athugun rýmis" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Flug um rýmið" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Aðalljós" },
        LocalizedText{ TXT_FILL_LIGHT, L"Fylliljós" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Heilir þrívíddarhlutir" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Teningur" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Reglulegur ferstrendur pýramídi" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Stýfður ferstrendur pýramídi" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Ferstrendur pýramídi skorinn með skáplani" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Pýramídi, skurðplan hornrétt á grunnflöt" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Reglulegur þrístrendingur" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Reglulegur fimmstrendingur" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Reglulegur sexstrendingur" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Reglulegur áttflötungur" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Fimmhyrndur tvípýramídi" },
        LocalizedText{ TXT_SOLID_CONE, L"Rétt hringkeila" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Stýfð keila" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Keila skorin með skáplani" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Keila, skurður hornréttur á grunnflöt" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Réttur hringsívalningur" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Holur sívalningur" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Holur sívalningur með tórusendum" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Lokaður snúningsfleygbogaflötur" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Kúla" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Hálfkúla" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Kúluhluti" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Stór kúluhluti" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Kúlulag" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Þríása sporvala" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Ílöng snúningssporvala" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Flöt snúningssporvala" },
        LocalizedText{ TXT_SOLID_EGG, L"Egglaga rúmhlutur" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Kúluhylki" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Rúnaður diskur (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Tórus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Ef forritinu er lokað stöðvast upptakan sem er í gangi."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Afrit af hverjum hlut: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Stærð hluta: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Virkja forskoðun" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Slökkva á forskoðun" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Hlé hefur verið gert á hreyfimyndinni." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Hindra skjáhvílu meðan hreyfimynd er í gangi" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Umhverfislýsing" },
        LocalizedText{ TXT_RIM_LIGHT, L"Útlínulýsing" },
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
            L"Fjarlæging mistókst vegna þess að stillingar FlyingSolids eru opnar. Lokaðu glugganum og "
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
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Vélbúnaðarhröðuð hreyfimynd heilla þrívíddarhluta." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Útgáfa:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Markvettvangur:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Vefsvæði:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Opna í sjálfgefnum vafra" },
        LocalizedText{ TXT_COPY_URL, L"Afrita &vefslóð" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Afrita &upplýsingar" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Heimsækja vefsvæði %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Ekki er hægt að opna vefsvæðið í sjálfgefnum vafra." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Ekki tókst að afrita vefslóðina á klippispjaldið." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Ekki tókst að afrita upplýsingarnar á klippispjaldið."
        },
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
            L"HREYFIMYND OG STILLINGAR\r\nVeldu einn eða fleiri skjái á listanum. Myndavélarhamur, hlutir, "
            L"lýsing, hraði, stærð og fjöldi eintaka eiga aðeins við um valda skjái. Hver skjár geymir sínar "
            L"eigin stillingar. FlyingSolids sýnir upplýsta heila þrívíddarhluti. Rennistikur stilla hraða "
            L"hluta og myndavélar á 0–1600%, eitt til tíu eintök og stærð á 50–200%. Veldu Athugun rýmis eða "
            L"Flug um rýmið í beinni línu og virkjaðu þá hluti sem óskað er eftir. Gátreitirnir Aðalljós, "
            L"Fylliljós, Umhverfislýsing og Útlínulýsing undir rennistikunum stýra lýsingu á völdum skjám "
            L"óháð hver öðrum. Umhverfislýsing gefur yfirborðunum grunnbirtu og útlínulýsing dregur fram "
            L"jaðrana. Stillingarnar eru vistaðar sérstaklega fyrir forritið og skjáhvíluna.\r\n\r\nSKJÁIR\r"
            L"\nVal lína ákvarðar hvaða skjám er verið að breyta og er óháð gátreitunum sem kveikja á "
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
            L"HREYFIMYND OG STILLINGAR\r\nVeldu einn eða fleiri skjái á listanum. Myndavélarhamur, hlutir, "
            L"lýsing, hraði, stærð og fjöldi eintaka eiga aðeins við um valda skjái. Hver skjár geymir sínar "
            L"eigin stillingar. Veldu Athugun rýmis eða Flug um rýmið í beinni línu. Stilltu hraða hluta og "
            L"myndavélar á 0–1600%, eitt til tíu eintök og stærð á 50–200% og virkjaðu óskaða hluti. "
            L"Gátreitirnir Aðalljós, Fylliljós, Umhverfislýsing og Útlínulýsing undir rennistikunum stýra "
            L"lýsingu á völdum skjám óháð hver öðrum. Umhverfislýsing gefur yfirborðunum grunnbirtu og "
            L"útlínulýsing dregur fram jaðrana. Stillingarnar eru vistaðar sérstaklega fyrir forritið og "
            L"skjáhvíluna.\r\n\r\nSKJÁIR\r\nVal lína ákvarðar hvaða skjám er verið að breyta og er óháð "
            L"gátreitunum sem kveikja á hreyfimyndaúttaki. Ctrl+A velur alla skjái; Ctrl og Shift breyta "
            L"valinu. Allir valkostir og sleðar hreyfimynda gilda fyrir valda skjái. Valið er munað "
            L"sérstaklega fyrir EXE og SCR. Ef allir skjáir voru valdir bætast nýir skjáir einnig við valið. "
            L"Mismunandi gildi á völdum skjám eru sýnd með óákveðnu ástandi gátreita og punktamynstri á "
            L"valhnöppum, handföngum sleða og hnöppunum „Virkja allt“ og „Óvirkja allt“. Merking sleða sýnir "
            L"strik í stað sameiginlegs gildis. Að breyta valkosti eða smella á sleða setur það gildi á alla "
            L"valda skjái.\r\n\r\nFORSKOÐUN OG NOTKUN\r\nVirkja forskoðun ræsir forskoðun á öllum skjánum á "
            L"hverjum skjá. Stillingaglugginn helst opinn og breytingar sjást strax. Í lagi vistar "
            L"stillingar og Hætta við hafnar breytingum. Esc eða músarhreyfing lokar skjáhvílu á öllum "
            L"skjánum. Notaðu Tab og Shift+Tab til að færa þig milli stýrieininga; Alt og undirstrikaður "
            L"stafur virkja skipun. Esc í stillingum jafngildir Hætta við; í Hjálp eða Um lokar það aðeins "
            L"þeim glugga.\r\n\r\nKERFISKRÖFUR\r\nWindows 7 til Windows 11 eru studd. Til að keyra forritið "
            L"á Windows Vista SP2 þarf að setja upp uppfærslurnar KB971512 og KB2117917. Birting krefst "
            L"Direct3D 11, ekki aðeins eldri DirectX-keyrsluumhverfis."
        },
    }),
    DefineLanguage(LANG_NB, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Norsk (bokmål)" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Kontroll" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Innstillinger for FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Språk:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Objekthastighet: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Kamerahastighet: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Romobservasjon" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Flyging gjennom rommet" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Hovedlys" },
        LocalizedText{ TXT_FILL_LIGHT, L"Utfyllingslys" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Solide 3D-objekter" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Kube" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Regelmessig firkantet pyramide" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Avkortet firkantet pyramide" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Firkantet pyramide skåret med skråplan" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Firkantpyramide, snitt normalt på basen" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Regelmessig trekantprisme" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Regelmessig femkantprisme" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Regelmessig sekskantprisme" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Regelmessig oktaeder" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Femkantet bipyramide" },
        LocalizedText{ TXT_SOLID_CONE, L"Rett sirkelkjegle" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Avkortet kjegle" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Kjegle skåret med skråplan" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Kjegle med snitt normalt på grunnflaten" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Rett sirkelsylinder" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Hul sylinder" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Hul sylinder med toroidale ender" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Rotasjonsparaboloide lukket av et plan" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Kule" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Halvkule" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Kulesegment" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Stort kulesegment" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Kulelag" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Treakset ellipsoide" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Prolat sfæroide" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Flattrykt sfæroide" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoide" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sfærosylinder" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Avrundet skive (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Torus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Hvis du avslutter programmet, avsluttes opptaket som pågår."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Kopier av hvert objekt: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Objektstørrelse: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Slå på forhåndsvisning" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Slå av forhåndsvisning" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animasjonen er satt på pause." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Hindre skjermsparer under animasjon" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Omgivelseslys" },
        LocalizedText{ TXT_RIM_LIGHT, L"Konturlys" },
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
            L"Avinstalleringen mislyktes fordi innstillingene for FlyingSolids er åpne. Lukk vinduet og prøv "
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
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Maskinvareakselerert animasjon av solide 3D-objekter." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versjon:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Målplattform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Nettsted:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Åpne i standardnettleseren" },
        LocalizedText{ TXT_COPY_URL, L"Kopier &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopier &informasjon" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Besøk nettstedet %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Nettstedet kan ikke åpnes i standardnettleseren." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL-adressen kunne ikke kopieres til utklippstavlen." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Informasjonen kunne ikke kopieres til utklippstavlen."
        },
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
            L"ANIMASJON OG INNSTILLINGER\r\nVelg én eller flere skjermer i listen. Kameramodus, objekter, "
            L"belysning, hastigheter, størrelse og antall kopier gjelder bare de valgte skjermene. Hver "
            L"skjerm husker sine egne innstillinger. FlyingSolids viser belyste solide 3D-legemer. "
            L"Glidebryterne angir objekt- og kamerahastighet fra 0–1600 %, én til ti kopier og størrelse fra "
            L"50–200 %. Velg Romobservasjon eller Flyging gjennom rommet i rett linje og aktiver ønskede "
            L"legemer. Avmerkingsboksene Hovedlys, Utfyllingslys, Omgivelseslys og Konturlys under "
            L"glidebryterne styrer belysningen på de valgte skjermene uavhengig av hverandre. Omgivelseslys "
            L"gir grunnbelysning på overflatene, og konturlys fremhever kantene. Innstillingene lagres "
            L"separat for programmet og skjermspareren.\r\n\r\nSKJERMER\r\nMarkeringen av rader bestemmer "
            L"hvilke skjermer du redigerer, og er atskilt fra avkrysningsboksene som aktiverer "
            L"animasjonsutgangen. Ctrl+A markerer alle skjermer; Ctrl og Skift endrer markeringen. Alle "
            L"animasjonsvalg og glidebrytere gjelder de markerte skjermene. Markeringen huskes separat for "
            L"EXE og SCR. Hvis alle skjermer var markert, inkluderes også nye skjermer. Ulike verdier på de "
            L"markerte skjermene vises med ubestemte avkrysningsbokser og prikkmønster på alternativknapper, "
            L"glidebryterhåndtak og knappene «Slå på alle» og «Slå av alle». Glidebryteretiketter viser en "
            L"tankestrek i stedet for en felles verdi. Endring av et valg eller klikk på en glidebryter "
            L"bruker denne verdien på alle markerte skjermer.\r\n\r\nBETJENING\r\nSlå animasjonsutgangene av "
            L"eller på med skjermenes avkrysningsbokser eller ved å dobbeltklikke på radene deres. Hver "
            L"skjerm bruker en uavhengig scene. Skjermbilde lagrer PNG, og opptaksknappen starter eller "
            L"stopper MP4. Pause stanser animasjonen. Programmet installerer eller avinstallerer også den "
            L"innebygde skjermspareren. Innstillingene lagres fortløpende. Bare én instans av programmet kan "
            L"kjøre om gangen. En ny start gjenoppretter det minimerte kontrollvinduet og bringer det "
            L"fremst. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede "
            L"bokstaven aktiverer en kommando. Esc lukker det aktive Hjelp- eller Om-vinduet; i "
            L"kontrollvinduet avslutter det programmet. Pause og blokkering av skjermspareren gjelder hele "
            L"programmet uavhengig av skjermmarkeringen. Når blokkering er slått på, hindres "
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
            L"ANIMASJON OG INNSTILLINGER\r\nVelg én eller flere skjermer i listen. Kameramodus, objekter, "
            L"belysning, hastigheter, størrelse og antall kopier gjelder bare de valgte skjermene. Hver "
            L"skjerm husker sine egne innstillinger. Velg Romobservasjon eller Flyging gjennom rommet i rett "
            L"linje. Angi objekt- og kamerahastighet 0–1600 %, én til ti kopier og størrelse 50–200 %, og "
            L"aktiver ønskede legemer. Avmerkingsboksene Hovedlys, Utfyllingslys, Omgivelseslys og Konturlys "
            L"under glidebryterne styrer belysningen på de valgte skjermene uavhengig av hverandre. "
            L"Omgivelseslys gir grunnbelysning på overflatene, og konturlys fremhever kantene. "
            L"Innstillingene lagres separat for programmet og skjermspareren.\r\n\r\nSKJERMER\r\nMarkeringen "
            L"av rader bestemmer hvilke skjermer du redigerer, og er atskilt fra avkrysningsboksene som "
            L"aktiverer animasjonsutgangen. Ctrl+A markerer alle skjermer; Ctrl og Skift endrer markeringen. "
            L"Alle animasjonsvalg og glidebrytere gjelder de markerte skjermene. Markeringen huskes separat "
            L"for EXE og SCR. Hvis alle skjermer var markert, inkluderes også nye skjermer. Ulike verdier på "
            L"de markerte skjermene vises med ubestemte avkrysningsbokser og prikkmønster på "
            L"alternativknapper, glidebryterhåndtak og knappene «Slå på alle» og «Slå av alle». "
            L"Glidebryteretiketter viser en tankestrek i stedet for en felles verdi. Endring av et valg "
            L"eller klikk på en glidebryter bruker denne verdien på alle markerte skjermer.\r\n\r\n"
            L"FORHÅNDSVISNING OG BETJENING\r\nSlå på forhåndsvisning starter en forhåndsvisning i fullskjerm "
            L"på alle skjermer. Innstillingene forblir åpne, og endringene vises fortløpende. OK lagrer "
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
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Styrning" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Inställningar för FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Språk:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Objekthastighet: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Kamerahastighet: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Rymdobservation" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Flygning genom rymden" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Huvudljus" },
        LocalizedText{ TXT_FILL_LIGHT, L"Upplättningsljus" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Solida 3D-objekt" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Kub" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Regelbunden fyrsidig pyramid" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Stympad fyrsidig pyramid" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Fyrsidig pyramid skuren med ett snett plan" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT,
            L"Fyrsidig pyramid, snitt vinkelrätt mot basen"
        },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Regelbundet triangelprisma" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Regelbundet femkantsprisma" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Regelbundet sexkantsprisma" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Regelbunden oktaeder" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Femkantig bipyramid" },
        LocalizedText{ TXT_SOLID_CONE, L"Rät cirkulär kon" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Stympad kon" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Kon skuren med ett snett plan" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Kon med snitt vinkelrätt mot basen" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Rät cirkulär cylinder" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Ihålig cylinder" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Ihålig cylinder med toroidala ändar" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Rotationsparaboloid sluten av ett plan" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Klot" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Halvklot" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Klotsegment" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Stort klotsegment" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Klotsegment med två baser" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Treaxlig ellipsoid" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Prolat sfäroid" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Oblat sfäroid" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoid" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sfärocylinder" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Avrundad skiva (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Torus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Om du avslutar programmet stoppas den pågående inspelningen."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Kopior av varje objekt: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Objektstorlek: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Aktivera förhandsvisning" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Inaktivera förhandsvisning" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animeringen är pausad." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blockera skärmsläckare under animering" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Omgivningsljus" },
        LocalizedText{ TXT_RIM_LIGHT, L"Konturljus" },
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
            L"Avinstallationen misslyckades eftersom inställningarna för FlyingSolids är öppna. Stäng "
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
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Maskinvaruaccelererad animering av solida 3D-objekt." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Version:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Målplattform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Webbplats:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Öppna i standardwebbläsaren" },
        LocalizedText{ TXT_COPY_URL, L"Kopiera &URL" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopiera &information" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Besök webbplatsen %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Webbplatsen kan inte öppnas i standardwebbläsaren." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL-adressen kunde inte kopieras till Urklipp." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Informationen kunde inte kopieras till Urklipp."
        },
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
            L"ANIMERING OCH INSTÄLLNINGAR\r\nMarkera en eller flera skärmar i listan. Kameraläge, objekt, "
            L"belysning, hastigheter, storlek och antal kopior gäller bara de markerade skärmarna. Varje "
            L"skärm sparar sina egna inställningar. FlyingSolids visar belysta solida 3D-kroppar. Reglagen "
            L"ställer in objekt- och kamerahastighet 0–1600 %, en till tio kopior och storlek 50–200 %. Välj "
            L"Rymdobservation eller Flygning genom rymden i rak linje och aktivera önskade kroppar. "
            L"Kryssrutorna Huvudljus, Upplättningsljus, Omgivningsljus och Konturljus under reglagen styr "
            L"belysningen på de markerade skärmarna oberoende av varandra. Omgivningsljus ger grundbelysning "
            L"på ytorna och konturljus framhäver kanterna. Inställningarna sparas separat för programmet och "
            L"skärmsläckaren.\r\n\r\nBILDSKÄRMAR\r\nMarkeringen av rader avgör vilka skärmar du redigerar "
            L"och är skild från kryssrutorna som aktiverar animationsutgångarna. Ctrl+A markerar alla "
            L"skärmar; Ctrl och Skift ändrar markeringen. Alla animationsalternativ och reglage gäller de "
            L"markerade skärmarna. Markeringen sparas separat för EXE och SCR. Om alla skärmar var markerade "
            L"inkluderas även nya skärmar. Olika värden på de markerade skärmarna visas med obestämda "
            L"kryssrutor och punktmönster på alternativknappar, reglagehandtag och knapparna ”Aktivera alla” "
            L"och ”Inaktivera alla”. Reglagens etiketter visar ett streck i stället för ett gemensamt värde. "
            L"När du ändrar ett alternativ eller klickar på ett reglage används värdet på alla markerade "
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
            L"ANIMERING OCH INSTÄLLNINGAR\r\nMarkera en eller flera skärmar i listan. Kameraläge, objekt, "
            L"belysning, hastigheter, storlek och antal kopior gäller bara de markerade skärmarna. Varje "
            L"skärm sparar sina egna inställningar. Välj Rymdobservation eller Flygning genom rymden i rak "
            L"linje. Ställ in objekt- och kamerahastighet 0–1600 %, en till tio kopior och storlek 50–200 %, "
            L"och aktivera önskade kroppar. Kryssrutorna Huvudljus, Upplättningsljus, Omgivningsljus och "
            L"Konturljus under reglagen styr belysningen på de markerade skärmarna oberoende av varandra. "
            L"Omgivningsljus ger grundbelysning på ytorna och konturljus framhäver kanterna. Inställningarna "
            L"sparas separat för programmet och skärmsläckaren.\r\n\r\nBILDSKÄRMAR\r\nMarkeringen av rader "
            L"avgör vilka skärmar du redigerar och är skild från kryssrutorna som aktiverar "
            L"animationsutgångarna. Ctrl+A markerar alla skärmar; Ctrl och Skift ändrar markeringen. Alla "
            L"animationsalternativ och reglage gäller de markerade skärmarna. Markeringen sparas separat för "
            L"EXE och SCR. Om alla skärmar var markerade inkluderas även nya skärmar. Olika värden på de "
            L"markerade skärmarna visas med obestämda kryssrutor och punktmönster på alternativknappar, "
            L"reglagehandtag och knapparna ”Aktivera alla” och ”Inaktivera alla”. Reglagens etiketter visar "
            L"ett streck i stället för ett gemensamt värde. När du ändrar ett alternativ eller klickar på "
            L"ett reglage används värdet på alla markerade skärmar.\r\n\r\nFÖRHANDSGRANSKNING OCH "
            L"ANVÄNDNING\r\nAktivera förhandsvisning startar en förhandsvisning i helskärm på alla "
            L"bildskärmar. Inställningarna förblir öppna och ändringarna visas direkt. OK sparar "
            L"inställningarna och Avbryt förkastar ändringarna. Esc eller musrörelse avslutar "
            L"helskärmsläget. Använd Tab och Skift+Tab för att flytta mellan kontrollerna; Alt och den "
            L"understrukna bokstaven aktiverar ett kommando. Esc i inställningarna motsvarar Avbryt; i Hjälp "
            L"eller Om stänger det bara det fönstret.\r\n\r\nSYSTEMKRAV\r\nWindows 7 till Windows 11 stöds. "
            L"För att köra programmet på Windows Vista SP2 måste uppdateringarna KB971512 och KB2117917 "
            L"installeras. Visningen kräver Direct3D 11, inte bara en äldre DirectX-körningsmiljö."
        },
    }),
    DefineLanguage(LANG_TR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Türkçe" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — Denetim" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlyingSolids Ayarları" },
        LocalizedText{ TXT_LANGUAGE, L"Dil:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Nesne hızı: %%%d" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Kamera hızı: %%%d" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Uzayı gözlemleme" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Uzayda uçuş" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Ana ışık" },
        LocalizedText{ TXT_FILL_LIGHT, L"Dolgu ışığı" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Katı 3B nesneler" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Küp" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Düzgün kare piramit" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Kesik kare piramit" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Eğik düzlemle kesilmiş kare piramit" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Tabana dik düzlemle kesilmiş kare piramit" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Düzgün üçgen prizma" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Düzgün beşgen prizma" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Düzgün altıgen prizma" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Düzgün oktahedron" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Beşgen çift piramit" },
        LocalizedText{ TXT_SOLID_CONE, L"Dik dairesel koni" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Kesik koni" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Eğik düzlemle kesilmiş koni" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Tabana dik düzlemle kesilmiş koni" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Dik dairesel silindir" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"İçi boş silindir" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Toroidal uçlu içi boş silindir" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Düzlemle kapatılmış dönel paraboloit" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Küre" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Yarım küre" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Küre parçası" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Büyük küre parçası" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Küre tabakası" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Üç eksenli elipsoit" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Prolat sferoit" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Basık sferoit" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoit" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sferosilindir" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Yuvarlatılmış disk (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Torus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Uygulamayı kapatmak devam eden kaydı durduracaktır." },
        LocalizedText{ TXT_COPY_COUNT, L"Her nesnenin kopya sayısı: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Nesne boyutu: %%%d" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Önizlemeyi aç" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Önizlemeyi kapat" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animasyon duraklatıldı." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Animasyon sırasında ekran koruyucuyu engelle" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ortam ışığı" },
        LocalizedText{ TXT_RIM_LIGHT, L"Kenar aydınlatması" },
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
            L"FlyingSolids ayarları açık olduğu için kaldırma başarısız oldu. Ayarlar penceresini kapatıp "
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
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Katı 3B nesnelerin donanım hızlandırmalı animasyonu." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Sürüm:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Hedef platform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Web sitesi:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"Varsayılan tarayıcıda &aç" },
        LocalizedText{ TXT_COPY_URL, L"&URL'yi kopyala" },
        LocalizedText{ TXT_COPY_INFORMATION, L"&Bilgileri kopyala" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"%ls web sitesini ziyaret et" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Web sitesi varsayılan tarayıcıda açılamıyor." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL panoya kopyalanamadı." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Bilgiler panoya kopyalanamadı." },
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
            L"ANİMASYON VE AYARLAR\r\nListeden bir veya daha fazla ekran seçin. Kamera modu, nesneler, "
            L"aydınlatma, hızlar, boyut ve kopya sayısı yalnızca seçili ekranlara uygulanır. Her ekran kendi "
            L"ayarlarını hatırlar. FlyingSolids aydınlatılmış katı 3B cisimler gösterir. Kaydırıcılar nesne "
            L"ve kamera hızını %0–1600, kopya sayısını bir ile on ve boyutu %50–200 arasında ayarlar. Uzayı "
            L"gözlemleme veya doğrusal Uzayda uçuş kipini seçip istenen cisimleri etkinleştirin. "
            L"Kaydırıcıların altındaki Ana ışık, Dolgu ışığı, Ortam ışığı ve Kenar aydınlatması onay "
            L"kutuları seçili ekranların aydınlatmasını birbirinden bağımsız olarak kontrol eder. Ortam "
            L"ışığı yüzeylere temel aydınlatma sağlar, kenar aydınlatması ise kenarları vurgular. Ayarlar "
            L"uygulama ve ekran koruyucu için ayrı ayrı kaydedilir.\r\n\r\nEKRANLAR\r\nSatır seçimi, hangi "
            L"ekranların düzenlendiğini belirler; animasyon çıkışlarını açan onay kutularından ayrıdır. "
            L"Ctrl+A tüm ekranları seçer; Ctrl ve Shift seçimi değiştirir. Tüm animasyon seçenekleri ve "
            L"kaydırıcılar seçili ekranlara uygulanır. Seçim EXE ve SCR için ayrı saklanır. Tüm ekranlar "
            L"seçiliyse sonradan bağlanan ekranlar da seçime katılır. Seçili ekranlardaki farklı değerler, "
            L"belirsiz durumdaki onay kutuları ve seçenek düğmelerinde, kaydırıcı tutamaçlarında ve “Tümünü "
            L"etkinleştir” ve “Tümünü devre dışı bırak” düğmelerinde noktalı desenle gösterilir. Kaydırıcı "
            L"etiketleri ortak bir değer yerine çizgi gösterir. Bir seçeneği değiştirmek veya kaydırıcıya "
            L"tıklamak bu değeri tüm seçili ekranlara uygular.\r\n\r\nKULLANIM\r\nAnimasyon çıkışlarını "
            L"ekran onay kutularıyla veya satırlarına çift tıklayarak açıp kapatabilirsiniz. Her monitör "
            L"bağımsız sahne kullanır. Anlık görüntü PNG kaydeder; kayıt düğmesi MP4 kaydını başlatır veya "
            L"bitirir. Duraklat animasyonu durdurur. Uygulama gömülü ekran koruyucuyu da kurar veya "
            L"kaldırır. Ayarlar sürekli kaydedilir. Uygulamanın aynı anda yalnızca bir örneği çalışabilir. "
            L"Yeniden başlatılması, simge durumuna küçültülmüş denetim penceresini geri yükler ve ön plana "
            L"getirir. Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir "
            L"komutu etkinleştirir. Esc, etkin Yardım veya Hakkında penceresini kapatır; denetim "
            L"penceresinde uygulamadan çıkar. Duraklatma ve ekran koruyucuyu engelleme, ekran seçiminden "
            L"bağımsız olarak uygulamanın tamamına uygulanır. Engelleme açıkken Windows ekran koruyucusu "
            L"yalnızca en az bir ekranda görünür ve duraklatılmamış animasyon varken engellenir.\r\n\r\n"
            L"EKRAN GÖRÜNTÜLERİ VE KAYIT\r\nAnlık görüntüler ve kayıtlar, tüm monitörlerin birleşik "
            L"görüntüsünü değil, ilk etkin animasyon monitörünü kullanır. PNG Resimler, MP4 Videolar "
            L"klasörünü kullanır; bu klasörler yoksa Belgeler kullanılır. Kayıt ayarları düğmesi Viewport "
            L"veya TV seçimini açar. Viewport, animasyon monitörünün boyutlarını ve yenileme hızını saniyede "
            L"en fazla 60 kareyle korur. TV, 16:9 oranında 1920 × 1080, 1440 × 1080 veya 1280 × 720 "
            L"çözünürlük ile saniyede 50, 25, 59.94 (60000/1001) veya 29.97 (30000/1001) kare sunar. "
            L"Görüntünün en boy oranı korunur; TV, sınırlı aralıklı, 4:2:0 örneklemeli ilerlemeli BT.709 "
            L"video kullanır. Çözünürlük ve kare hızı yalnızca TV modunda seçilebilir. Kayıt ayarları "
            L"penceresi simge durumuna küçültülebilir ve uygulamanın diğer pencerelerini engellemez. Tamam, "
            L"seçenekleri bir sonraki MP4 kaydı için kaydeder; İptal veya Esc onaylanmamış değişiklikleri "
            L"iptal eder. Kayıt sırasında kaydedilen ekranın animasyon çıkışı kapatılamaz; diğer "
            L"ekranlardaki değişiklikler kaydı durdurmaz. Kayıt sırasında uygulamayı kapatmak kaydı da "
            L"durduracağı için onay gerektirir.\r\n\r\nSİSTEM GEREKSİNİMLERİ\r\nWindows 7 ile Windows 11 "
            L"arasındaki sürümler, PNG anlık görüntüler ve MP4 kaydı dâhil tüm özellikleri destekler. "
            L"Uygulamayı Windows Vista SP2'de çalıştırmak için KB971512 ve KB2117917 güncellemelerini "
            L"yüklemeniz gerekir. Geçerli sürümde MP4 kaydı Vista'da çalışmaz. Görüntüleme, yalnızca eski "
            L"bir DirectX çalışma zamanı değil, Direct3D 11 gerektirir. MP4 kaydı, kullanılabilir Media "
            L"Foundation bileşenleri ve bir H.264 kodlayıcı gerektirir."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANİMASYON VE AYARLAR\r\nListeden bir veya daha fazla ekran seçin. Kamera modu, nesneler, "
            L"aydınlatma, hızlar, boyut ve kopya sayısı yalnızca seçili ekranlara uygulanır. Her ekran kendi "
            L"ayarlarını hatırlar. Uzayı gözlemleme veya doğrusal Uzayda uçuş kipini seçin. Nesne ve kamera "
            L"hızını %0–1600, kopya sayısını bir ile on ve boyutu %50–200 arasında ayarlayıp istenen "
            L"cisimleri etkinleştirin. Kaydırıcıların altındaki Ana ışık, Dolgu ışığı, Ortam ışığı ve Kenar "
            L"aydınlatması onay kutuları seçili ekranların aydınlatmasını birbirinden bağımsız olarak "
            L"kontrol eder. Ortam ışığı yüzeylere temel aydınlatma sağlar, kenar aydınlatması ise kenarları "
            L"vurgular. Ayarlar uygulama ve ekran koruyucu için ayrı ayrı kaydedilir.\r\n\r\nEKRANLAR\r\n"
            L"Satır seçimi, hangi ekranların düzenlendiğini belirler; animasyon çıkışlarını açan onay "
            L"kutularından ayrıdır. Ctrl+A tüm ekranları seçer; Ctrl ve Shift seçimi değiştirir. Tüm "
            L"animasyon seçenekleri ve kaydırıcılar seçili ekranlara uygulanır. Seçim EXE ve SCR için ayrı "
            L"saklanır. Tüm ekranlar seçiliyse sonradan bağlanan ekranlar da seçime katılır. Seçili "
            L"ekranlardaki farklı değerler, belirsiz durumdaki onay kutuları ve seçenek düğmelerinde, "
            L"kaydırıcı tutamaçlarında ve “Tümünü etkinleştir” ve “Tümünü devre dışı bırak” düğmelerinde "
            L"noktalı desenle gösterilir. Kaydırıcı etiketleri ortak bir değer yerine çizgi gösterir. Bir "
            L"seçeneği değiştirmek veya kaydırıcıya tıklamak bu değeri tüm seçili ekranlara uygular.\r\n\r\n"
            L"ÖNİZLEME VE KULLANIM\r\nÖnizlemeyi aç, tüm monitörlerde tam ekran önizleme başlatır. Ayarlar "
            L"penceresi açık kalır ve değişiklikler anında görülür. Tamam ayarları kaydeder, İptal "
            L"değişiklikleri iptal eder. Tam ekran koruyucudan Esc veya fare hareketiyle çıkılır. Denetimler "
            L"arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir komutu etkinleştirir. "
            L"Ayarlarda Esc, İptal ile aynı işlevi görür; Yardım veya Hakkında penceresinde yalnızca o "
            L"pencereyi kapatır.\r\n\r\nSİSTEM GEREKSİNİMLERİ\r\nWindows 7 ile Windows 11 arasındaki "
            L"sürümler desteklenir. Uygulamayı Windows Vista SP2'de çalıştırmak için KB971512 ve KB2117917 "
            L"güncellemelerini yüklemeniz gerekir. Görüntüleme, yalnızca eski bir DirectX çalışma zamanı "
            L"değil, Direct3D 11 gerektirir."
        },
    }),
    DefineLanguage(LANG_ET, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Eesti" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — juhtimine" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlyingSolids sätted" },
        LocalizedText{ TXT_LANGUAGE, L"Keel:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Objektide kiirus: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Kaamera kiirus: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Ruumi vaatlemine" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Lend läbi ruumi" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Põhivalgus" },
        LocalizedText{ TXT_FILL_LIGHT, L"Täitevalgus" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Ruumilised kehad" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Kuup" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Korrapärane nelinurkne püramiid" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Nelinurkne tüvipüramiid" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Kaldlõikega nelinurkne püramiid" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Põhjaga risti lõigatud püramiid" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Korrapärane kolmnurkne prisma" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Korrapärane viisnurkne prisma" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Korrapärane kuusnurkne prisma" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Korrapärane oktaeeder" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Viisnurkne kaksikpüramiid" },
        LocalizedText{ TXT_SOLID_CONE, L"Pöördkoonus" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Tüvikoonus" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Kaldlõikega koonus" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Põhjaga risti lõigatud koonus" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Pöördsilinder" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Õõnes pöördsilinder" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Toroidsete otstega õõnessilinder" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Tasandiga suletud pöördparaboloid" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Kera" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Poolkera" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Kerasegment" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Suur kerasegment" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Kerakiht" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Kolmeteljeline ellipsoid" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Piklik pöördellipsoid" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Lapik pöördellipsoid" },
        LocalizedText{ TXT_SOLID_EGG, L"Munakeha" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sferosilinder" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Ümardatud ketas (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Toor" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Rakenduse sulgemine lõpetab käimasoleva salvestamise."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Iga objekti koopiaid: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Objektide suurus: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Luba eelvaade" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Keela eelvaade" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animatsioon on peatatud." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Tõkesta animatsiooni ajal ekraanisäästja" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ümbritsev valgus" },
        LocalizedText{ TXT_RIM_LIGHT, L"Kontuurivalgus" },
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
            L"Sulgege FlyingSolids sätete aken ja proovige eemaldamist uuesti."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Sulgege Windowsi ekraanisäästja sätete aken ja proovige eemaldamist uuesti."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Sulgege ekraanisäästja või täisekraanieelvaade klahviga Esc või hiire liigutamisega ja "
            L"proovige eemaldamist uuesti."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Riistvarakiirendusega ruumiliste kehade animatsioon." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versioon:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Sihtplatvorm:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Veebisait:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Ava vaikebrauseris" },
        LocalizedText{ TXT_COPY_URL, L"Kopeeri &aadress" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopeeri &teave" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Ava veebisait %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Veebisaiti ei saa vaikebrauseris avada." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL-i ei saanud lõikelauale kopeerida." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Teavet ei saanud lõikelauale kopeerida." },
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
            L"ANIMATSIOON JA SÄTTED\r\nFlyingSolids kuvab liikuvaid, pöörlevaid ja põrkuvaid ruumilisi kehi. "
            L"Valige ruumi vaatlemine või lend läbi ruumi ning soovitud kehad. Iga kuvari jaoks saab eraldi "
            L"määrata objektide ja kaamera kiiruse 0–1600%, objektide suuruse 50–200% ning iga keha koopiate "
            L"arvu 1–10. Põhi-, täite-, ümbritsev ja kontuurivalgus on sõltumatult lülitatavad.\r\n\r\n"
            L"KUVARID\r\nValige loendis üks või mitu kuvaririda. Ctrl+A valib kõik read; Ctrl ja Shift "
            L"võimaldavad valikut muuta. Animatsiooni juhtnupud ja liugurid mõjutavad ainult valitud "
            L"kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle märkeruuduga väljundi lubamine "
            L"on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja jaoks eraldi meelde. Kui varem "
            L"olid valitud kõik kuvarid, kaasatakse ka lisatud kuvarid. Valitud kuvarite erinevaid väärtusi "
            L"näitavad märkeruutude määramata olek ning raadionuppude, liugurite käepidemete ja nuppude "
            L"„Luba kõik” ja „Keela kõik” punktimuster. Liuguri sildil on ühise väärtuse asemel kriips. "
            L"Valiku muutmine või liuguril klõpsamine määrab selle väärtuse kõigile valitud kuvaritele.\r\n\r"
            L"\nKASUTAMINE\r\nKäivitage FlyingSolids.exe. Sätteid salvestatakse jooksvalt ning rakendus "
            L"töötab ühe eksemplarina. Kuvari märkeruut või topeltklõps real lülitab selle "
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
            L"ANIMATSIOON JA SÄTTED\r\nFlyingSolids kuvab liikuvaid, pöörlevaid ja põrkuvaid ruumilisi kehi. "
            L"Valige ruumi vaatlemine või lend läbi ruumi ning soovitud kehad. Iga kuvari jaoks saab eraldi "
            L"määrata objektide ja kaamera kiiruse 0–1600%, objektide suuruse 50–200% ning iga keha koopiate "
            L"arvu 1–10. Põhi-, täite-, ümbritsev ja kontuurivalgus on sõltumatult lülitatavad.\r\n\r\n"
            L"KUVARID\r\nValige loendis üks või mitu kuvaririda. Ctrl+A valib kõik read; Ctrl ja Shift "
            L"võimaldavad valikut muuta. Animatsiooni juhtnupud ja liugurid mõjutavad ainult valitud "
            L"kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle märkeruuduga väljundi lubamine "
            L"on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja jaoks eraldi meelde. Kui varem "
            L"olid valitud kõik kuvarid, kaasatakse ka lisatud kuvarid. Valitud kuvarite erinevaid väärtusi "
            L"näitavad märkeruutude määramata olek ning raadionuppude, liugurite käepidemete ja nuppude "
            L"„Luba kõik” ja „Keela kõik” punktimuster. Liuguri sildil on ühise väärtuse asemel kriips. "
            L"Valiku muutmine või liuguril klõpsamine määrab selle väärtuse kõigile valitud kuvaritele.\r\n\r"
            L"\nEELVAADE JA KASUTAMINE\r\nKäivitage FlyingSolids.scr Windowsi ekraanisäästjana. Selle sätted "
            L"on rakenduse omadest eraldi. Sätete eelvaade lubab täisekraanil animatsiooni jooksvalt muuta. "
            L"OK salvestab muudatused ning Loobu või Esc tühistab need. Täisekraanil ekraanisäästjast "
            L"väljumiseks vajutage klahvi või liigutage hiirt.\r\n\r\nSÜSTEEMINÕUDED\r\nWindows 7–11 toetab "
            L"kõiki funktsioone. Windows Vista SP2 jaoks tuleb paigaldada värskendused KB971512 ja "
            L"KB2117917. Vaja on Direct3D 11 tuge."
        },
    }),
    DefineLanguage(LANG_GA, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Gaeilge" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — rialuithe" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Socruithe FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Teanga:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Luas na réad: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Luas an cheamara: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Breathnú ar an spás" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Eitilt tríd an spás" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Príomhsholas" },
        LocalizedText{ TXT_FILL_LIGHT, L"Solas líonta" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Réada soladacha 3T" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Ciúb" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Pirimid chearnach rialta" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Teascán pirimide cearnaí" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Pirimid chearnach le gearradh claon" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Pirimid gearrtha ingearach leis an mbonn" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Príosma triantánach rialta" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Príosma peinteagánach rialta" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Príosma heicseagánach rialta" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Ochtaihéadrán rialta" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Dépirimid pheinteagánach" },
        LocalizedText{ TXT_SOLID_CONE, L"Cón ciorclach díreach" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Teascán cóin" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Cón le gearradh claon" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Cón gearrtha ingearach leis an mbonn" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Sorcóir ciorclach díreach" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Sorcóir ciorclach toll" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Sorcóir toll le foircinn tórasacha" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Parabalóideach rothlach dúnta" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Sféar" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Leathsféar" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Caipín sféarúil" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Caipín sféarúil mór" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Teascán sféarúil idir dhá phlána" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Éileapsóideach trí-aiseach" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Sféaróideach fadaithe" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Sféaróideach leacaithe" },
        LocalizedText{ TXT_SOLID_EGG, L"Ubhchruthán" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Capsúl (spherocylinder)" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Diosca slánaithe (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Tóras" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Stopfar an taifeadadh atá ar siúl má dhúntar an feidhmchlár."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Cóipeanna de gach réad: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Méid na réad: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Cumasaigh réamhamharc" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Díchumasaigh réamhamharc" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Tá an bheochan ar sos." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Cosc ar spárálaí scáileáin le linn beochana" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Solas comhthimpeallach" },
        LocalizedText{ TXT_RIM_LIGHT, L"Solas imill" },
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
            L"Dún fuinneog socruithe FlyingSolids agus bain triail eile as an díshuiteáil."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Dún fuinneog socruithe spárálaí scáileáin Windows agus bain triail eile as an díshuiteáil."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Dún an spárálaí scáileáin nó an réamhamharc lánscáileáin le Esc nó trí an luch a bhogadh agus "
            L"bain triail eile as."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Beochan réad soladach 3T le luasghéarú crua-earraí." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Leagan:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Sprioc-ardán:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Suíomh gréasáin:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Oscail sa bhrabhsálaí réamhshocraithe" },
        LocalizedText{ TXT_COPY_URL, L"Cóipeáil an &seoladh" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Cóipeáil an &fhaisnéis" },
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
            L"BEOCHAN AGUS SOCRUITHE\r\nTaispeánann FlyingSolids coirp sholadacha a ghluaiseann, a "
            L"rothlaíonn agus a imbhuaileann. Roghnaigh breathnú ar an spás nó eitilt tríd agus na coirp atá "
            L"uait. Tá luas na réad agus an cheamara 0–1600%, méid na réad 50–200% agus 1–10 gcóip de gach "
            L"corp inchoigeartaithe go neamhspleách do gach monatóir. Is féidir an príomhsholas, an solas "
            L"líonta, an solas comhthimpeallach agus an solas imill a athrú ar leith.\r\n\r\nTAISPEÁNTAIS\r\n"
            L"Roghnaigh ró amháin nó níos mó sa liosta monatóirí. Roghnaíonn Ctrl+A gach ró; úsáid Ctrl agus "
            L"Shift chun an roghnú a athrú. Ní athraíonn rialuithe agus sleamhnáin na beochana ach socruithe "
            L"na monatóirí roghnaithe. Ní hionann ró a roghnú agus aschur an mhonatóra a chumasú lena bhosca "
            L"seiceála. Cuimhnítear an roghnú ar leith don fheidhmchlár agus don spárálaí. Má bhí gach "
            L"monatóir roghnaithe, cuirtear monatóirí nua leis an roghnú freisin. Léirítear luachanna "
            L"éagsúla ar na monatóirí roghnaithe le boscaí seiceála i staid neamhchinnte agus le patrún "
            L"poncanna ar chnaipí raidió, ar ghreimíní sleamhnán agus ar na cnaipí “Cumasaigh uile” agus "
            L"“Díchumasaigh uile”. Taispeántar dais ar lipéad an tsleamhnáin in ionad luach coiteann. Nuair "
            L"a athraítear rogha nó a chliceáiltear sleamhnán, cuirtear an luach sin i bhfeidhm ar gach "
            L"monatóir roghnaithe.\r\n\r\nRIALÚ\r\nRith FlyingSolids.exe. Sábháiltear socruithe go leanúnach "
            L"agus ní ritheann ach cóip amháin den fheidhmchlár. Cumasaíonn nó díchumasaíonn bosca seiceála "
            L"an mhonatóra nó déchliceáil ar a ró an t-aschur beochana. Is féidir an bheochan a chur ar sos "
            L"agus a atosú. Gabhann PNG agus MP4 an chéad mhonatóir beochana gníomhach, ní na monatóirí uile "
            L"le chéile. Ní féidir aschur beochana an mhonatóra atá á thaifeadadh a dhíchumasú le linn "
            L"taifeadta; teastaíonn deimhniú chun an feidhmchlár a dhúnadh agus taifeadadh ar siúl. Baineann "
            L"sos agus cosc an spárálaí scáileáin leis an bhfeidhmchlár iomlán, beag beann ar na monatóirí "
            L"roghnaithe. Nuair atá an cosc cumasaithe, ní choisctear spárálaí scáileáin Windows ach fad a "
            L"bhíonn beochan infheicthe nach bhfuil ar sos ar mhonatóir amháin ar a laghad. Is féidir an "
            L"spárálaí leabaithe a shuiteáil nó a dhíshuiteáil ón bhfeidhmchlár.\r\n\r\nGABHÁLACHA SCÁILEÁIN "
            L"AGUS TAIFEADADH\r\nRoghnaigh Viewport nó TV i socruithe taifeadta. Coinníonn Viewport toisí "
            L"agus ráta athnuachana an mhonatóra, suas le 60 fráma sa soicind. Tairgeann TV 1920 × 1080, "
            L"1440 × 1080 nó 1280 × 720 i gcóimheas 16:9 ag 50, 25, 59.94 (60000/1001) nó 29.97 (30000/1001) "
            L"fráma sa soicind. Is físeán forásach BT.709 é, le raon teoranta agus foshampláil datha 4:2:0. "
            L"Coinnítear cóimheas an phictiúir agus tá na barraí líonta dubh. Cuireann OK roghanna i "
            L"bhfeidhm ar an gcéad taifeadadh eile; cealaíonn Cealaigh nó Esc athruithe neamhdheimhnithe. Ní "
            L"chuireann socruithe taifeadta, Cabhair ná Maidir leis bac ar fhuinneoga eile agus is féidir "
            L"iad a íoslaghdú. Bogann Tab agus Shift+Tab an fócas; gníomhaíonn Enter an cnaipe faoi fhócas "
            L"agus dúnann Esc an fhuinneog chúnta ghníomhach.\r\n\r\nRIACHTANAIS CHÓRAIS\r\nTacaíonn Windows "
            L"7–11 leis na gnéithe uile. Ar Windows Vista SP2 ní mór nuashonruithe KB971512 agus KB2117917 a "
            L"shuiteáil; ní oibríonn taifeadadh MP4 ar Vista. Teastaíonn tacaíocht Direct3D 11, agus Media "
            L"Foundation agus ionchódóir H.264 le haghaidh MP4. Tá an comhéadan agus an doiciméadú ar fáil i "
            L"36 teanga."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"BEOCHAN AGUS SOCRUITHE\r\nTaispeánann FlyingSolids coirp sholadacha a ghluaiseann, a "
            L"rothlaíonn agus a imbhuaileann. Roghnaigh breathnú ar an spás nó eitilt tríd agus na coirp atá "
            L"uait. Tá luas na réad agus an cheamara 0–1600%, méid na réad 50–200% agus 1–10 gcóip de gach "
            L"corp inchoigeartaithe go neamhspleách do gach monatóir. Is féidir an príomhsholas, an solas "
            L"líonta, an solas comhthimpeallach agus an solas imill a athrú ar leith.\r\n\r\nTAISPEÁNTAIS\r\n"
            L"Roghnaigh ró amháin nó níos mó sa liosta monatóirí. Roghnaíonn Ctrl+A gach ró; úsáid Ctrl agus "
            L"Shift chun an roghnú a athrú. Ní athraíonn rialuithe agus sleamhnáin na beochana ach socruithe "
            L"na monatóirí roghnaithe. Ní hionann ró a roghnú agus aschur an mhonatóra a chumasú lena bhosca "
            L"seiceála. Cuimhnítear an roghnú ar leith don fheidhmchlár agus don spárálaí. Má bhí gach "
            L"monatóir roghnaithe, cuirtear monatóirí nua leis an roghnú freisin. Léirítear luachanna "
            L"éagsúla ar na monatóirí roghnaithe le boscaí seiceála i staid neamhchinnte agus le patrún "
            L"poncanna ar chnaipí raidió, ar ghreimíní sleamhnán agus ar na cnaipí “Cumasaigh uile” agus "
            L"“Díchumasaigh uile”. Taispeántar dais ar lipéad an tsleamhnáin in ionad luach coiteann. Nuair "
            L"a athraítear rogha nó a chliceáiltear sleamhnán, cuirtear an luach sin i bhfeidhm ar gach "
            L"monatóir roghnaithe.\r\n\r\nRÉAMHAMHARC AGUS RIALÚ\r\nÚsáid FlyingSolids.scr mar spárálaí "
            L"scáileáin Windows. Tá a shocruithe ar leith ó shocruithe an fheidhmchláir. Ceadaíonn an "
            L"réamhamharc lánscáileáin athruithe beo. Sábhálann OK agus cealaíonn Cealaigh nó Esc na "
            L"hathruithe. Fág an spárálaí lánscáileáin le heochair ar bith nó le gluaiseacht na luiche.\r\n\r"
            L"\nRIACHTANAIS CHÓRAIS\r\nTacaíonn Windows 7–11 leis na gnéithe uile. Ar Windows Vista SP2 ní "
            L"mór nuashonruithe KB971512 agus KB2117917 a shuiteáil. Teastaíonn tacaíocht Direct3D 11."
        },
    }),
    DefineLanguage(LANG_LT, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Lietuvių" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — valdymas" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlyingSolids nuostatos" },
        LocalizedText{ TXT_LANGUAGE, L"Kalba:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Objektų greitis: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Kameros greitis: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Erdvės stebėjimas" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Skrydis erdve" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Pagrindinė šviesa" },
        LocalizedText{ TXT_FILL_LIGHT, L"Užpildanti šviesa" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Erdviniai kūnai" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Kubas" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Taisyklingoji keturkampė piramidė" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Nupjautinė keturkampė piramidė" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Įstrižai nupjauta keturkampė piramidė" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Statmenai pagrindui nupjauta piramidė" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Taisyklingoji trikampė prizmė" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Taisyklingoji penkiakampė prizmė" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Taisyklingoji šešiakampė prizmė" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Taisyklingasis oktaedras" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Penkiakampė bipiramidė" },
        LocalizedText{ TXT_SOLID_CONE, L"Statusis apskritasis kūgis" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Nupjautinis kūgis" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Įstrižai nupjautas kūgis" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Statmenai pagrindui nupjautas kūgis" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Statusis apskritasis ritinys" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Tuščiaviduris ritinys" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Tuščiaviduris ritinys su toroidiniais galais" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Plokštuma uždarytas sukimosi paraboloidas" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Rutulys" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Pusrutulis" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Rutulio nuopjova" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Didžioji rutulio nuopjova" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Rutulio sluoksnis" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Triašis elipsoidas" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Ištęstas sukimosi elipsoidas" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Suplotas sukimosi elipsoidas" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoidas" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sferocilindras" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Suapvalintas diskas (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Toras" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Uždarius programą bus sustabdytas vykstantis įrašymas."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Kiekvieno objekto kopijų: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Objektų dydis: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Įjungti peržiūrą" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Išjungti peržiūrą" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animacija pristabdyta." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Animacijos metu neleisti ekrano užsklandos" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Aplinkos šviesa" },
        LocalizedText{ TXT_RIM_LIGHT, L"Kontūrinė šviesa" },
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
            L"Uždarykite FlyingSolids nuostatų langą ir bandykite pašalinti dar kartą."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Uždarykite Windows ekrano užsklandos nuostatų langą ir bandykite pašalinti dar kartą."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Užbaikite užsklandą arba viso ekrano peržiūrą klavišu Esc ar pajudindami pelę ir bandykite "
            L"pašalinti dar kartą."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Aparatine įranga spartinama erdvinių kūnų animacija." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versija:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Tikslinė platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Svetainė:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Atidaryti numatytojoje naršyklėje" },
        LocalizedText{ TXT_COPY_URL, L"Kopijuoti &adresą" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopijuoti &informaciją" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Atidaryti svetainę %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Nepavyko atverti svetainės numatytojoje naršyklėje." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Nepavyko nukopijuoti URL į iškarpinę." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Nepavyko nukopijuoti informacijos į iškarpinę." },
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
            L"ANIMACIJA IR NUOSTATOS\r\nFlyingSolids rodo judančius, besisukančius ir susiduriančius "
            L"erdvinius kūnus. Pasirinkite erdvės stebėjimą arba skrydį erdve ir norimus kūnus. Kiekvienam "
            L"monitoriui atskirai galima nustatyti objektų bei kameros greitį 0–1600%, objektų dydį 50–200% "
            L"ir 1–10 kiekvieno kūno kopijų. Pagrindinė, užpildanti, aplinkos ir kontūrinė šviesa įjungiamos "
            L"nepriklausomai.\r\n\r\nMONITORIAI\r\nMonitorių sąraše pasirinkite vieną ar kelias eilutes. "
            L"Ctrl+A pasirenka visas, o Ctrl ir Shift leidžia keisti pasirinkimą. Animacijos valdikliai ir "
            L"slankikliai keičia tik pasirinktų monitorių nuostatas. Eilutės pasirinkimas nėra tas pats, kas "
            L"animacijos išvesties įjungimas jos žymimuoju langeliu. Pasirinkimas atskirai įsimenamas "
            L"programai ir užsklandai. Jei buvo pasirinkti visi monitoriai, į pasirinkimą įtraukiami ir "
            L"naujai prijungti monitoriai. Skirtingas pasirinktų monitorių reikšmes rodo neapibrėžta "
            L"žymimųjų langelių būsena ir taškinis raštas ant parinkčių mygtukų, slankiklių rankenėlių bei "
            L"mygtukų „Įjungti visus“ ir „Išjungti visus“. Slankiklių užrašuose vietoj bendros reikšmės "
            L"rodomas brūkšnys. Pakeitus parinktį arba spustelėjus slankiklį, ta reikšmė pritaikoma visiems "
            L"pasirinktiems monitoriams.\r\n\r\nVALDYMAS\r\nPaleiskite FlyingSolids.exe. Nuostatos "
            L"išsaugomos nuolat, veikia tik vienas programos egzempliorius. Monitoriaus langelis arba "
            L"dvigubas eilutės spustelėjimas įjungia ar išjungia animacijos išvestį. Animaciją galima "
            L"pristabdyti ir tęsti. PNG ir MP4 fiksuoja pirmą aktyvų animacijos monitorių, o ne bendrą visų "
            L"monitorių vaizdą. Įrašymo metu negalima išjungti įrašomo monitoriaus animacijos išvesties; "
            L"uždarant programą vykstant įrašymui reikia patvirtinimo. Pristabdymas ir užsklandos blokavimas "
            L"taikomi visai programai, nepriklausomai nuo monitorių pasirinkimo. Įjungus blokavimą, Windows "
            L"užsklanda neleidžiama tik kol bent viename monitoriuje matoma nepristabdyta animacija. "
            L"Programa gali įdiegti ir pašalinti į ją įtrauktą užsklandą.\r\n\r\nEKRANO KOPIJOS IR ĮRAŠYMAS\r"
            L"\nĮrašymo nuostatose pasirinkite Viewport arba TV. Viewport išsaugo monitoriaus matmenis ir "
            L"atnaujinimo dažnį iki 60 kadrų per sekundę. TV siūlo 1920 × 1080, 1440 × 1080 arba 1280 × 720 "
            L"išvestį 16:9 santykiu bei 50, 25, 59.94 (60000/1001) arba 29.97 (30000/1001) kadrų per "
            L"sekundę. TV vaizdas progresinis, BT.709, riboto diapazono ir 4:2:0 spalvų diskretizavimo. "
            L"Vaizdo proporcijos išlieka, užpildymo juostos juodos. OK pritaiko nuostatas kitam įrašui, "
            L"Atšaukti arba Esc atmeta nepatvirtintus pakeitimus. Įrašymo, žinyno ir informacijos langai "
            L"neblokuoja kitų langų ir gali būti sumažinti. Tab ir Shift+Tab keičia įvesties vietą, Enter "
            L"paspaudžia aktyvų mygtuką, Esc uždaro aktyvų papildomą langą.\r\n\r\nSISTEMOS REIKALAVIMAI\r\n"
            L"Windows 7–11 palaiko visas funkcijas. Windows Vista SP2 būtina įdiegti naujinimus KB971512 ir "
            L"KB2117917; MP4 įrašymas Vistoje neveikia. Reikalingas Direct3D 11 palaikymas, o MP4 įrašymui "
            L"Media Foundation ir H.264 koduotuvas. Sąsaja ir dokumentacija pateikiamos 36 kalbomis."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACIJA IR NUOSTATOS\r\nFlyingSolids rodo judančius, besisukančius ir susiduriančius "
            L"erdvinius kūnus. Pasirinkite erdvės stebėjimą arba skrydį erdve ir norimus kūnus. Kiekvienam "
            L"monitoriui atskirai galima nustatyti objektų bei kameros greitį 0–1600%, objektų dydį 50–200% "
            L"ir 1–10 kiekvieno kūno kopijų. Pagrindinė, užpildanti, aplinkos ir kontūrinė šviesa įjungiamos "
            L"nepriklausomai.\r\n\r\nMONITORIAI\r\nMonitorių sąraše pasirinkite vieną ar kelias eilutes. "
            L"Ctrl+A pasirenka visas, o Ctrl ir Shift leidžia keisti pasirinkimą. Animacijos valdikliai ir "
            L"slankikliai keičia tik pasirinktų monitorių nuostatas. Eilutės pasirinkimas nėra tas pats, kas "
            L"animacijos išvesties įjungimas jos žymimuoju langeliu. Pasirinkimas atskirai įsimenamas "
            L"programai ir užsklandai. Jei buvo pasirinkti visi monitoriai, į pasirinkimą įtraukiami ir "
            L"naujai prijungti monitoriai. Skirtingas pasirinktų monitorių reikšmes rodo neapibrėžta "
            L"žymimųjų langelių būsena ir taškinis raštas ant parinkčių mygtukų, slankiklių rankenėlių bei "
            L"mygtukų „Įjungti visus“ ir „Išjungti visus“. Slankiklių užrašuose vietoj bendros reikšmės "
            L"rodomas brūkšnys. Pakeitus parinktį arba spustelėjus slankiklį, ta reikšmė pritaikoma visiems "
            L"pasirinktiems monitoriams.\r\n\r\nPERŽIŪRA IR VALDYMAS\r\nNaudokite FlyingSolids.scr kaip "
            L"Windows ekrano užsklandą. Jos nuostatos atskiros nuo programos. Viso ekrano peržiūra leidžia "
            L"jas keisti vykstant animacijai. OK išsaugo, Atšaukti arba Esc atmeta pakeitimus. Užsklandą "
            L"užbaikite klavišu arba pajudindami pelę.\r\n\r\nSISTEMOS REIKALAVIMAI\r\nWindows 7–11 palaiko "
            L"visas funkcijas. Windows Vista SP2 būtina įdiegti naujinimus KB971512 ir KB2117917. "
            L"Reikalingas Direct3D 11 palaikymas."
        },
    }),
    DefineLanguage(LANG_LV, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Latviešu" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — vadība" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlyingSolids iestatījumi" },
        LocalizedText{ TXT_LANGUAGE, L"Valoda:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Objektu ātrums: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Kameras ātrums: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Telpas novērošana" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Lidojums telpā" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Galvenā gaisma" },
        LocalizedText{ TXT_FILL_LIGHT, L"Papildu gaisma" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Telpiski ķermeņi" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Kubs" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Regulāra četrstūra piramīda" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Nošķelta četrstūra piramīda" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Slīpi nošķelta četrstūra piramīda" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT,
            L"Piramīda ar pamatnei perpendikulāru griezumu"
        },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Regulāra trijstūra prizma" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Regulāra piecstūra prizma" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Regulāra sešstūra prizma" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Regulārs oktaedrs" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Piecstūra bipiramīda" },
        LocalizedText{ TXT_SOLID_CONE, L"Taisns riņķa konuss" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Nošķelts konuss" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Slīpi nošķelts konuss" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Konuss ar pamatnei perpendikulāru griezumu" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Taisns riņķa cilindrs" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Dobs cilindrs" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Dobs cilindrs ar toroidāliem galiem" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Ar plakni noslēgts rotācijas paraboloīds" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Lode" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Puslode" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Lodes segments" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Lielais lodes segments" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Lodes slānis" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Trīsasu elipsoīds" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Izstiepts rotācijas elipsoīds" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Saspiests rotācijas elipsoīds" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoīds" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sferocilindrs" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Noapaļots disks (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Tors" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Aizverot lietotni, tiks pārtraukts pašreizējais ieraksts."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Katra objekta kopijas: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Objektu izmērs: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Ieslēgt priekšskatījumu" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Izslēgt priekšskatījumu" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animācija ir pauzēta." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Animācijas laikā bloķēt ekrānsaudzētāju" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Apkārtējā gaisma" },
        LocalizedText{ TXT_RIM_LIGHT, L"Kontūru gaisma" },
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
            L"Aizveriet FlyingSolids iestatījumu logu un atkārtojiet atinstalēšanu."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Aizveriet Windows ekrānsaudzētāja iestatījumu logu un atkārtojiet atinstalēšanu."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Aizveriet ekrānsaudzētāju vai pilnekrāna priekšskatījumu ar Esc vai peles kustību un "
            L"atkārtojiet atinstalēšanu."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Aparatūras paātrināta telpisku ķermeņu animācija." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versija:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Mērķa platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Tīmekļa vietne:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Atvērt noklusējuma pārlūkprogrammā" },
        LocalizedText{ TXT_COPY_URL, L"Kopēt &adresi" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopēt &informāciju" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Atvērt tīmekļa vietni %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Nevar atvērt vietni noklusējuma pārlūkā." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Neizdevās kopēt URL starpliktuvē." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Neizdevās kopēt informāciju starpliktuvē." },
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
            L"ANIMĀCIJA UN IESTATĪJUMI\r\nFlyingSolids rāda kustīgus, rotējošus un savstarpēji sadurošus "
            L"telpiskus ķermeņus. Izvēlieties telpas novērošanu vai lidojumu telpā un vajadzīgos ķermeņus. "
            L"Katram monitoram atsevišķi var iestatīt objektu un kameras ātrumu 0–1600%, objektu izmēru "
            L"50–200% un 1–10 katra ķermeņa kopijas. Galveno, papildu, apkārtējo un kontūru gaismu var "
            L"pārslēgt neatkarīgi.\r\n\r\nMONITORI\r\nMonitoru sarakstā atlasiet vienu vai vairākas rindas. "
            L"Ctrl+A atlasa visas, bet Ctrl un Shift ļauj mainīt atlasi. Animācijas vadīklas un slīdņi maina "
            L"tikai atlasīto monitoru iestatījumus. Rindas atlasīšana nav tas pats, kas animācijas izvades "
            L"ieslēgšana ar izvēles rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un ekrānsaudzētājam. Ja "
            L"bija atlasīti visi monitori, atlasē iekļauj arī jaunpievienotos monitorus. Atšķirīgas vērtības "
            L"atlasītajos monitoros norāda nenoteikts izvēles rūtiņu stāvoklis un punktots raksts uz "
            L"radiopogām, slīdņu rokturiem un pogām „Ieslēgt visu” un „Izslēgt visu”. Slīdņu etiķetēs "
            L"kopīgas vērtības vietā redzama domuzīme. Mainot iespēju vai noklikšķinot uz slīdņa, šī vērtība "
            L"tiek piemērota visiem atlasītajiem monitoriem.\r\n\r\nLIETOŠANA\r\nPalaidiet FlyingSolids.exe. "
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
            L"ANIMĀCIJA UN IESTATĪJUMI\r\nFlyingSolids rāda kustīgus, rotējošus un savstarpēji sadurošus "
            L"telpiskus ķermeņus. Izvēlieties telpas novērošanu vai lidojumu telpā un vajadzīgos ķermeņus. "
            L"Katram monitoram atsevišķi var iestatīt objektu un kameras ātrumu 0–1600%, objektu izmēru "
            L"50–200% un 1–10 katra ķermeņa kopijas. Galveno, papildu, apkārtējo un kontūru gaismu var "
            L"pārslēgt neatkarīgi.\r\n\r\nMONITORI\r\nMonitoru sarakstā atlasiet vienu vai vairākas rindas. "
            L"Ctrl+A atlasa visas, bet Ctrl un Shift ļauj mainīt atlasi. Animācijas vadīklas un slīdņi maina "
            L"tikai atlasīto monitoru iestatījumus. Rindas atlasīšana nav tas pats, kas animācijas izvades "
            L"ieslēgšana ar izvēles rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un ekrānsaudzētājam. Ja "
            L"bija atlasīti visi monitori, atlasē iekļauj arī jaunpievienotos monitorus. Atšķirīgas vērtības "
            L"atlasītajos monitoros norāda nenoteikts izvēles rūtiņu stāvoklis un punktots raksts uz "
            L"radiopogām, slīdņu rokturiem un pogām „Ieslēgt visu” un „Izslēgt visu”. Slīdņu etiķetēs "
            L"kopīgas vērtības vietā redzama domuzīme. Mainot iespēju vai noklikšķinot uz slīdņa, šī vērtība "
            L"tiek piemērota visiem atlasītajiem monitoriem.\r\n\r\nPRIEKŠSKATĪJUMS UN LIETOŠANA\r\n"
            L"Izmantojiet FlyingSolids.scr kā Windows ekrānsaudzētāju. Tā iestatījumi ir atsevišķi no "
            L"lietotnes. Pilnekrāna priekšskatījums ļauj tos mainīt animācijas darbības laikā. OK saglabā, "
            L"Atcelt vai Esc atmet izmaiņas. Pilnekrāna ekrānsaudzētāju aizveriet ar taustiņu vai peles "
            L"kustību.\r\n\r\nSISTĒMAS PRASĪBAS\r\nWindows 7–11 atbalsta visas funkcijas. Windows Vista SP2 "
            L"jāinstalē atjauninājumi KB971512 un KB2117917. Nepieciešams Direct3D 11 atbalsts."
        },
    }),
    DefineLanguage(LANG_HU, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Magyar" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — vezérlés" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"FlyingSolids beállításai" },
        LocalizedText{ TXT_LANGUAGE, L"Nyelv:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Objektumok sebessége: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Kamera sebessége: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"A tér megfigyelése" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Repülés a térben" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Főfény" },
        LocalizedText{ TXT_FILL_LIGHT, L"Derítőfény" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Térbeli testek" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Kocka" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Szabályos négyzet alapú gúla" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Négyzet alapú csonkagúla" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Ferdén metszett négyzet alapú gúla" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Alapra merőlegesen metszett gúla" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Szabályos háromszög alapú hasáb" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Szabályos ötszög alapú hasáb" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Szabályos hatszög alapú hasáb" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Szabályos oktaéder" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Ötszög alapú kettős gúla" },
        LocalizedText{ TXT_SOLID_CONE, L"Egyenes körkúp" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Csonkakúp" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Ferdén metszett kúp" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Alapra merőlegesen metszett kúp" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Egyenes körhenger" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Üreges körhenger" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Üreges henger tóruszos végekkel" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Síkkal lezárt forgási paraboloid" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Gömb" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Félgömb" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Gömbsüveg" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Nagy gömbsüveg" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Gömbszelet" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Háromtengelyű ellipszoid" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Nyújtott forgási ellipszoid" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Lapított forgási ellipszoid" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoid" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Szferocilinder" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Lekerekített korong (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Tórusz" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Az alkalmazás bezárása leállítja a folyamatban lévő felvételt."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Az egyes objektumok példányai: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Objektumok mérete: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Előnézet bekapcsolása" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Előnézet kikapcsolása" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Az animáció szünetel." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Képernyőkímélő tiltása animáció közben" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Környezeti fény" },
        LocalizedText{ TXT_RIM_LIGHT, L"Peremfény" },
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
            L"Zárja be a FlyingSolids beállítási ablakát, majd próbálja újra az eltávolítást."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zárja be a Windows képernyőkímélő-beállításait, majd próbálja újra az eltávolítást."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Lépjen ki a képernyőkímélőből vagy a teljes képernyős előnézetből az Esc billentyűvel vagy az "
            L"egér mozgatásával, majd próbálja újra."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Térbeli testek hardveresen gyorsított animációja." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Verzió:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Célplatform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Webhely:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Megnyitás az alapértelmezett böngészőben" },
        LocalizedText{ TXT_COPY_URL, L"&Cím másolása" },
        LocalizedText{ TXT_COPY_INFORMATION, L"&Információ másolása" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Webhely megnyitása: %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"A webhely nem nyitható meg az alapértelmezett böngészőben."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Az URL nem másolható a vágólapra." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Az információ nem másolható a vágólapra." },
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
            L"ANIMÁCIÓ ÉS BEÁLLÍTÁSOK\r\nA FlyingSolids mozgó, forgó és ütköző térbeli testeket jelenít meg. "
            L"Válassza a tér megfigyelését vagy a térben repülést, és kapcsolja be a kívánt testeket. "
            L"Monitoronként állítható az objektumok és a kamera sebessége 0–1600%, az objektumok mérete "
            L"50–200%, valamint testenként 1–10 példány. A főfény, derítőfény, környezeti fény és peremfény "
            L"egymástól függetlenül kapcsolható.\r\n\r\nMONITOROK\r\nJelöljön ki egy vagy több sort a "
            L"monitorok listájában. A Ctrl+A mindet kijelöli; a Ctrl és a Shift módosítja a kijelölést. Az "
            L"animáció vezérlői és csúszkái csak a kijelölt monitorok beállításait változtatják. A sor "
            L"kijelölése és az animációs kimenet jelölőnégyzetes engedélyezése külön művelet. A kijelölést "
            L"az alkalmazás és a képernyőkímélő külön megjegyzi. Ha korábban minden monitor ki volt jelölve, "
            L"az újonnan csatlakoztatott monitorok is bekerülnek a kijelölésbe. A kijelölt monitorok eltérő "
            L"értékeit a jelölőnégyzetek határozatlan állapota, valamint a választógombok, a "
            L"csúszkafogantyúk és az „Mind bekapcsolása” és „Mind kikapcsolása” gombok pontozása jelzi. A "
            L"csúszkák felirata közös érték helyett gondolatjelet mutat. Egy beállítás módosítása vagy a "
            L"csúszkára kattintás az adott értéket minden kijelölt monitorra alkalmazza.\r\n\r\nKEZELÉS\r\n"
            L"Indítsa el a FlyingSolids.exe fájlt. A beállítások folyamatosan mentődnek, és csak egy "
            L"alkalmazáspéldány fut. A monitor jelölőnégyzete vagy a sorra történő dupla kattintás kapcsolja "
            L"az animációs kimenetet. Az animáció szüneteltethető és folytatható. A PNG és az MP4 az első "
            L"aktív animációs monitort rögzíti, nem az összes monitor egyesített képét. A rögzített monitor "
            L"animációs kimenete felvétel közben nem kapcsolható ki; az alkalmazás bezárásához ekkor "
            L"megerősítés szükséges. A szüneteltetés és a képernyőkímélő tiltása a teljes alkalmazásra "
            L"vonatkozik, a monitorok kijelölésétől függetlenül. Bekapcsolt tiltás esetén a Windows "
            L"képernyőkímélője csak addig nem indul el, amíg legalább egy monitoron látható, nem szünetelő "
            L"animáció fut. Az alkalmazás telepítheti és eltávolíthatja a beágyazott képernyőkímélőt.\r\n\r\n"
            L"KÉPERNYŐKÉPEK ÉS FELVÉTEL\r\nA felvételi beállításoknál Viewport vagy TV választható. A "
            L"Viewport megőrzi a monitor képméretét és frissítési gyakoriságát, legfeljebb 60 "
            L"képkocka/másodpercig. A TV felbontása 1920 × 1080, 1440 × 1080 vagy 1280 × 720, képaránya "
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
            L"ANIMÁCIÓ ÉS BEÁLLÍTÁSOK\r\nA FlyingSolids mozgó, forgó és ütköző térbeli testeket jelenít meg. "
            L"Válassza a tér megfigyelését vagy a térben repülést, és kapcsolja be a kívánt testeket. "
            L"Monitoronként állítható az objektumok és a kamera sebessége 0–1600%, az objektumok mérete "
            L"50–200%, valamint testenként 1–10 példány. A főfény, derítőfény, környezeti fény és peremfény "
            L"egymástól függetlenül kapcsolható.\r\n\r\nMONITOROK\r\nJelöljön ki egy vagy több sort a "
            L"monitorok listájában. A Ctrl+A mindet kijelöli; a Ctrl és a Shift módosítja a kijelölést. Az "
            L"animáció vezérlői és csúszkái csak a kijelölt monitorok beállításait változtatják. A sor "
            L"kijelölése és az animációs kimenet jelölőnégyzetes engedélyezése külön művelet. A kijelölést "
            L"az alkalmazás és a képernyőkímélő külön megjegyzi. Ha korábban minden monitor ki volt jelölve, "
            L"az újonnan csatlakoztatott monitorok is bekerülnek a kijelölésbe. A kijelölt monitorok eltérő "
            L"értékeit a jelölőnégyzetek határozatlan állapota, valamint a választógombok, a "
            L"csúszkafogantyúk és az „Mind bekapcsolása” és „Mind kikapcsolása” gombok pontozása jelzi. A "
            L"csúszkák felirata közös érték helyett gondolatjelet mutat. Egy beállítás módosítása vagy a "
            L"csúszkára kattintás az adott értéket minden kijelölt monitorra alkalmazza.\r\n\r\nELŐNÉZET ÉS "
            L"KEZELÉS\r\nA FlyingSolids.scr Windows-képernyőkímélőként használható, az alkalmazástól külön "
            L"beállításokkal. A teljes képernyős előnézetben élőben módosíthatók a beállítások. Az OK ment, "
            L"a Mégse vagy Esc elveti a módosításokat. A teljes képernyős képernyőkímélő billentyűvel vagy "
            L"egérmozgással zárható be.\r\n\r\nRENDSZERKÖVETELMÉNYEK\r\nA Windows 7–11 minden funkciót "
            L"támogat. Windows Vista SP2 alatt telepíteni kell a KB971512 és KB2117917 frissítést. Direct3D "
            L"11 támogatás szükséges."
        },
    }),
    DefineLanguage(LANG_MT, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Malti" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — kontrolli" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Issettjar ta’ FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Lingwa:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Veloċità tal-oġġetti: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Veloċità tal-kamera: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Osservazzjoni tal-ispazju" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Titjira fl-ispazju" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Dawl ewlieni" },
        LocalizedText{ TXT_FILL_LIGHT, L"Dawl ta’ mili" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Oġġetti solidi 3D" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Kubu" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Piramida kwadra regolari" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Frustum ta’ piramida kwadra" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Piramida kwadra maqtugħa oblikwament" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Piramida maqtugħa perpendikulari mal-bażi" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Priżma trijangolari regolari" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Priżma pentagonali regolari" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Priżma eżagonali regolari" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Ottaedru regolari" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Bipiramida pentagonali" },
        LocalizedText{ TXT_SOLID_CONE, L"Konu ċirkolari rett" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Frustum ta’ konu" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Konu maqtugħ oblikwament" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Konu maqtugħ perpendikulari mal-bażi" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Ċilindru ċirkolari rett" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Ċilindru ċirkolari vojt" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Ċilindru vojt bi truf torojdali" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Parabolojde ta’ rotazzjoni magħluq" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Sfera" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Emisfera" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Kalotta sferika" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Kalotta sferika maġġuri" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Segment sferiku bejn żewġ pjani" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Ellissojde triassjali" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Sferojde mtawwal" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Sferojde ċċattjat" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovojde" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Kapsula (spherocylinder)" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Diska ttondjata (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Toru" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"L-għeluq tal-applikazzjoni jwaqqaf ir-reġistrazzjoni li tkun għaddejja."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Kopji ta’ kull oġġett: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Daqs tal-oġġetti: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Attiva l-previżjoni" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Iddiżattiva l-previżjoni" },
        LocalizedText{ TXT_PAUSED_STATUS, L"L-animazzjoni tinsab sospiża." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Imblokka l-iscreen saver waqt l-animazzjoni" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Dawl ambjentali" },
        LocalizedText{ TXT_RIM_LIGHT, L"Dawl tal-kontorn" },
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
            L"Agħlaq it-tieqa tal-issettjar ta’ FlyingSolids u erġa’ pprova tneħħih."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Agħlaq it-tieqa tal-issettjar tal-iscreen saver ta’ Windows u erġa’ pprova tneħħih."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Agħlaq l-iscreen saver jew il-previżjoni fuq skrin sħiħ b’Esc jew billi ċċaqlaq il-maws u "
            L"erġa’ pprova."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Animazzjoni ta’ oġġetti solidi 3D aċċellerata bil-ħardwer." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Verżjoni:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Pjattaforma fil-mira:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Sit web:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Iftaħ fil-brawżer default" },
        LocalizedText{ TXT_COPY_URL, L"Ikkopja l-&indirizz" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Ikkopja l-&informazzjoni" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Iftaħ is-sit web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Is-sit ma jistax jinfetaħ fil-brawżer predefinit." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Il-URL ma setax jiġi kkupjat fil-clipboard." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"L-informazzjoni ma setgħetx tiġi kkupjata fil-clipboard."
        },
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
            L"ANIMAZZJONI U ISSETTJAR\r\nFlyingSolids juri solidi tridimensjonali li jiċċaqalqu, iduru u "
            L"jaħbtu ma’ xulxin. Agħżel osservazzjoni tal-ispazju jew titjira fl-ispazju u attiva l-forom "
            L"mixtieqa. Għal kull moniter tista’ tissettja separatament il-veloċità tal-oġġetti u l-kamera "
            L"minn 0–1600%, id-daqs minn 50–200% u 1–10 kopji ta’ kull solidu. Id-dawl ewlieni, id-dawl ta’ "
            L"mili, id-dawl ambjentali u d-dawl tal-kontorn jinxtegħlu separatament.\r\n\r\nSKRINS\r\nAgħżel "
            L"ringiela waħda jew aktar fil-lista tal-moniters. Ctrl+A jagħżilhom kollha; Ctrl u Shift "
            L"ibiddlu l-għażla. Il-kontrolli u s-sliders tal-animazzjoni jibdlu biss l-issettjar "
            L"tal-moniters magħżula. L-għażla ta’ ringiela hija differenti mill-attivazzjoni tal-output "
            L"permezz tal-kaxxa tal-marka. L-għażla tinżamm separatament għall-applikazzjoni u għall-iscreen "
            L"saver. Jekk il-moniters kollha kienu magħżula, il-moniters ġodda jiddaħħlu wkoll fl-għażla. "
            L"Valuri differenti fuq il-moniters magħżula jintwerew bi stat indeterminat tal-kaxxi tal-marka "
            L"u b’disinn bit-tikek fuq il-buttuni tar-radju, il-manki tas-sliders u l-buttuni “Attiva "
            L"kollox” u “Iddiżattiva kollox”. It-tikketti tas-sliders juru sing minflok valur komuni. Meta "
            L"tibdel għażla jew tikklikkja slider, dak il-valur jiġi applikat għall-moniters magħżula "
            L"kollha.\r\n\r\nKONTROLLI\r\nĦaddem FlyingSolids.exe. L-issettjar jiġi ssejvjat kontinwament u "
            L"taħdem istanza waħda biss. Il-kaxxa tal-moniter jew klikk doppja fuq ir-ringiela tattiva jew "
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
            L"ANIMAZZJONI U ISSETTJAR\r\nFlyingSolids juri solidi tridimensjonali li jiċċaqalqu, iduru u "
            L"jaħbtu ma’ xulxin. Agħżel osservazzjoni tal-ispazju jew titjira fl-ispazju u attiva l-forom "
            L"mixtieqa. Għal kull moniter tista’ tissettja separatament il-veloċità tal-oġġetti u l-kamera "
            L"minn 0–1600%, id-daqs minn 50–200% u 1–10 kopji ta’ kull solidu. Id-dawl ewlieni, id-dawl ta’ "
            L"mili, id-dawl ambjentali u d-dawl tal-kontorn jinxtegħlu separatament.\r\n\r\nSKRINS\r\nAgħżel "
            L"ringiela waħda jew aktar fil-lista tal-moniters. Ctrl+A jagħżilhom kollha; Ctrl u Shift "
            L"ibiddlu l-għażla. Il-kontrolli u s-sliders tal-animazzjoni jibdlu biss l-issettjar "
            L"tal-moniters magħżula. L-għażla ta’ ringiela hija differenti mill-attivazzjoni tal-output "
            L"permezz tal-kaxxa tal-marka. L-għażla tinżamm separatament għall-applikazzjoni u għall-iscreen "
            L"saver. Jekk il-moniters kollha kienu magħżula, il-moniters ġodda jiddaħħlu wkoll fl-għażla. "
            L"Valuri differenti fuq il-moniters magħżula jintwerew bi stat indeterminat tal-kaxxi tal-marka "
            L"u b’disinn bit-tikek fuq il-buttuni tar-radju, il-manki tas-sliders u l-buttuni “Attiva "
            L"kollox” u “Iddiżattiva kollox”. It-tikketti tas-sliders juru sing minflok valur komuni. Meta "
            L"tibdel għażla jew tikklikkja slider, dak il-valur jiġi applikat għall-moniters magħżula "
            L"kollha.\r\n\r\nPREVIŻJONI U KONTROLLI\r\nUża FlyingSolids.scr bħala screen saver ta’ Windows. "
            L"L-issettjar tiegħu huwa separat minn dak tal-applikazzjoni. Il-previżjoni fuq skrin sħiħ "
            L"tippermetti bidliet waqt l-animazzjoni. OK isalva u Ikkanċella jew Esc jarmi l-bidliet. Oħroġ "
            L"mill-iscreen saver bi kwalunkwe tast jew billi ċċaqlaq il-maws.\r\n\r\nREKWIŻITI TAS-SISTEMA\r"
            L"\nWindows 7–11 jappoġġja l-funzjonijiet kollha. Fuq Windows Vista SP2 għandhom jiġu installati "
            L"l-aġġornamenti KB971512 u KB2117917. Huwa meħtieġ Direct3D 11."
        },
    }),
    DefineLanguage(LANG_NL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Nederlands" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — bediening" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Instellingen van FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Taal:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Objectsnelheid: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Camerasnelheid: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Ruimte observeren" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Door de ruimte vliegen" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Hoofdlicht" },
        LocalizedText{ TXT_FILL_LIGHT, L"Invullicht" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Massieve 3D-objecten" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Kubus" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Regelmatige vierzijdige piramide" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Afgeknotte vierzijdige piramide" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Schuin afgesneden vierzijdige piramide" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Piramide loodrecht op grondvlak gesneden" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Regelmatig driehoekig prisma" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Regelmatig vijfhoekig prisma" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Regelmatig zeshoekig prisma" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Regelmatige octaëder" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Vijfhoekige bipiramide" },
        LocalizedText{ TXT_SOLID_CONE, L"Rechte cirkelkegel" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Afgeknotte kegel" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Schuin afgesneden kegel" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Kegel loodrecht op grondvlak gesneden" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Rechte cirkelcilinder" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Holle cirkelcilinder" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Holle cilinder met torusvormige uiteinden" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Gesloten omwentelingsparaboloïde" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Bol" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Halve bol" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Bolkap" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Grote bolkap" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Bolschijf" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Drieassige ellipsoïde" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Prolate sferoïde" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Oblate sferoïde" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoïde" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sferocilinder" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Afgeronde schijf (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Torus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Als u de toepassing sluit, wordt de huidige opname gestopt."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Kopieën van elk object: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Objectgrootte: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Voorbeeld inschakelen" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Voorbeeld uitschakelen" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animatie is gepauzeerd." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Schermbeveiliging blokkeren tijdens animatie" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Omgevingslicht" },
        LocalizedText{ TXT_RIM_LIGHT, L"Randlicht" },
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
            L"Sluit de instellingen van FlyingSolids en probeer het verwijderen opnieuw."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Sluit de instellingen voor schermbeveiliging van Windows en probeer het verwijderen opnieuw."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Sluit de schermbeveiliging of het schermvullende voorbeeld met Esc of door de muis te bewegen "
            L"en probeer het opnieuw."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardwareversnelde animatie van massieve 3D-objecten." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versie:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Doelplatform:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Website:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Openen in standaardbrowser" },
        LocalizedText{ TXT_COPY_URL, L"&Adres kopiëren" },
        LocalizedText{ TXT_COPY_INFORMATION, L"&Informatie kopiëren" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Website %ls openen" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Kan de website niet in de standaardbrowser openen." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"De URL kon niet naar het klembord worden gekopieerd." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"De informatie kon niet naar het klembord worden gekopieerd."
        },
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
            L"ANIMATIE EN INSTELLINGEN\r\nFlyingSolids toont bewegende, draaiende en botsende "
            L"driedimensionale lichamen. Kies ruimte observeren of door de ruimte vliegen en schakel de "
            L"gewenste lichamen in. Stel per beeldscherm de object- en camerasnelheid in op 0–1600%, de "
            L"objectgrootte op 50–200% en het aantal kopieën op 1–10 per lichaam. Hoofdlicht, invullicht, "
            L"omgevingslicht en randlicht zijn onafhankelijk schakelbaar.\r\n\r\nBEELDSCHERMEN\r\nSelecteer "
            L"één of meer beeldschermrijen in de lijst. Ctrl+A selecteert alles; met Ctrl en Shift past u de "
            L"selectie aan. Animatieknoppen en schuifregelaars wijzigen alleen de instellingen van de "
            L"geselecteerde beeldschermen. Een rij selecteren is iets anders dan de animatie-uitvoer "
            L"inschakelen met het selectievakje. De selectie wordt apart onthouden voor de toepassing en de "
            L"schermbeveiliging. Als alle beeldschermen waren geselecteerd, worden nieuw aangesloten "
            L"beeldschermen ook geselecteerd. Verschillende waarden op geselecteerde beeldschermen worden "
            L"aangegeven door selectievakjes in onbepaalde toestand en een stippelpatroon op keuzerondjes, "
            L"schuifknoppen en de knoppen ‘Alles inschakelen’ en ‘Alles uitschakelen’. De labels van "
            L"schuifregelaars tonen een streepje in plaats van een gemeenschappelijke waarde. Een optie "
            L"wijzigen of op een schuifregelaar klikken past die waarde toe op alle geselecteerde "
            L"beeldschermen.\r\n\r\nBEDIENING\r\nStart FlyingSolids.exe. Instellingen worden doorlopend "
            L"opgeslagen en er draait slechts één exemplaar van de toepassing. Het selectievakje of een "
            L"dubbelklik op de beeldschermrij schakelt de animatie-uitvoer in of uit. U kunt de animatie "
            L"pauzeren en hervatten. PNG en MP4 leggen het eerste actieve animatiebeeldscherm vast, niet een "
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
            L"ANIMATIE EN INSTELLINGEN\r\nFlyingSolids toont bewegende, draaiende en botsende "
            L"driedimensionale lichamen. Kies ruimte observeren of door de ruimte vliegen en schakel de "
            L"gewenste lichamen in. Stel per beeldscherm de object- en camerasnelheid in op 0–1600%, de "
            L"objectgrootte op 50–200% en het aantal kopieën op 1–10 per lichaam. Hoofdlicht, invullicht, "
            L"omgevingslicht en randlicht zijn onafhankelijk schakelbaar.\r\n\r\nBEELDSCHERMEN\r\nSelecteer "
            L"één of meer beeldschermrijen in de lijst. Ctrl+A selecteert alles; met Ctrl en Shift past u de "
            L"selectie aan. Animatieknoppen en schuifregelaars wijzigen alleen de instellingen van de "
            L"geselecteerde beeldschermen. Een rij selecteren is iets anders dan de animatie-uitvoer "
            L"inschakelen met het selectievakje. De selectie wordt apart onthouden voor de toepassing en de "
            L"schermbeveiliging. Als alle beeldschermen waren geselecteerd, worden nieuw aangesloten "
            L"beeldschermen ook geselecteerd. Verschillende waarden op geselecteerde beeldschermen worden "
            L"aangegeven door selectievakjes in onbepaalde toestand en een stippelpatroon op keuzerondjes, "
            L"schuifknoppen en de knoppen ‘Alles inschakelen’ en ‘Alles uitschakelen’. De labels van "
            L"schuifregelaars tonen een streepje in plaats van een gemeenschappelijke waarde. Een optie "
            L"wijzigen of op een schuifregelaar klikken past die waarde toe op alle geselecteerde "
            L"beeldschermen.\r\n\r\nVOORBEELD EN BEDIENING\r\nGebruik FlyingSolids.scr als "
            L"Windows-schermbeveiliging met eigen instellingen. Het schermvullende voorbeeld laat live "
            L"aanpassingen toe. OK slaat wijzigingen op; Annuleren of Esc verwerpt ze. Sluit de "
            L"schermvullende schermbeveiliging met een toets of een muisbeweging.\r\n\r\nSYSTEEMVEREISTEN\r\n"
            L"Windows 7–11 ondersteunt alle functies. Voor Windows Vista SP2 moet u updates KB971512 en "
            L"KB2117917 installeren. Direct3D 11-ondersteuning is vereist."
        },
    }),
    DefineLanguage(LANG_RO, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Română" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — comenzi" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Setări FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Limbă:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Viteza obiectelor: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Viteza camerei: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Observarea spațiului" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Zbor prin spațiu" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Lumină principală" },
        LocalizedText{ TXT_FILL_LIGHT, L"Lumină de umplere" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Corpuri tridimensionale" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Cub" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Piramidă patrulateră regulată" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Trunchi de piramidă patrulateră" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Piramidă patrulateră secționată oblic" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Piramidă secționată perpendicular pe bază" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Prismă triunghiulară regulată" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Prismă pentagonală regulată" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Prismă hexagonală regulată" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Octaedru regulat" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Bipiramidă pentagonală" },
        LocalizedText{ TXT_SOLID_CONE, L"Con circular drept" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Trunchi de con" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Con secționat oblic" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Con secționat perpendicular pe bază" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Cilindru circular drept" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Cilindru circular gol" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Cilindru gol cu capete toroidale" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Paraboloid de rotație închis cu un plan" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Sferă" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Emisferă" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Calotă sferică" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Calotă sferică mare" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Segment sferic cu două baze" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Elipsoid triaxial" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Elipsoid de rotație alungit" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Elipsoid de rotație turtit" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoid" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sferocilindru" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Disc rotunjit (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Tor" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Închiderea aplicației va opri înregistrarea în curs." },
        LocalizedText{ TXT_COPY_COUNT, L"Copii ale fiecărui obiect: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Dimensiunea obiectelor: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Activare previzualizare" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Dezactivare previzualizare" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animația este în pauză." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blocare economizor în timpul animației" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Lumină ambiantă" },
        LocalizedText{ TXT_RIM_LIGHT, L"Lumină de contur" },
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
            L"Închideți fereastra de setări FlyingSolids și încercați din nou dezinstalarea."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Închideți setările economizorului de ecran Windows și încercați din nou dezinstalarea."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Închideți economizorul sau previzualizarea pe tot ecranul cu Esc ori mișcând mouse-ul și "
            L"încercați din nou."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Animație de corpuri tridimensionale accelerată hardware." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Versiune:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Platformă țintă:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Site web:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Deschidere în browserul implicit" },
        LocalizedText{ TXT_COPY_URL, L"Copiere &adresă" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Copiere &informații" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Deschidere site web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Site-ul nu poate fi deschis în browserul implicit." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL-ul nu a putut fi copiat în clipboard." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Informațiile nu au putut fi copiate în clipboard."
        },
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
            L"ANIMAȚIE ȘI SETĂRI\r\nFlyingSolids afișează corpuri tridimensionale care se deplasează, se "
            L"rotesc și se ciocnesc. Alegeți observarea spațiului sau zborul prin spațiu și activați "
            L"corpurile dorite. Pentru fiecare monitor puteți seta separat viteza obiectelor și a camerei "
            L"între 0–1600%, dimensiunea între 50–200% și 1–10 copii ale fiecărui corp. Lumina principală, "
            L"de umplere, ambiantă și de contur se controlează independent.\r\n\r\nMONITOARE\r\nSelectați "
            L"unul sau mai multe rânduri din lista monitoarelor. Ctrl+A le selectează pe toate; Ctrl și "
            L"Shift modifică selecția. Comenzile și glisoarele animației schimbă numai setările monitoarelor "
            L"selectate. Selectarea unui rând diferă de activarea ieșirii prin caseta sa de selectare. "
            L"Selecția este reținută separat pentru aplicație și economizor. Dacă erau selectate toate "
            L"monitoarele, sunt incluse și cele conectate ulterior. Valorile diferite de pe monitoarele "
            L"selectate sunt indicate prin starea nedeterminată a casetelor de selectare și un model punctat "
            L"pe butoanele radio, mânerele glisoarelor și butoanele „Activare toate” și „Dezactivare toate”. "
            L"Etichetele glisoarelor afișează o liniuță în locul unei valori comune. Modificarea unei "
            L"opțiuni sau clicul pe un glisor aplică acea valoare tuturor monitoarelor selectate.\r\n\r\n"
            L"COMENZI\r\nRulați FlyingSolids.exe. Setările se salvează continuu și rulează o singură "
            L"instanță. Caseta monitorului sau un dublu clic pe rând activează ori dezactivează ieșirea "
            L"animației. Animația poate fi pusă în pauză și reluată. PNG și MP4 capturează primul monitor de "
            L"animație activ, nu imaginea combinată a tuturor monitoarelor. Ieșirea animației pe monitorul "
            L"înregistrat nu poate fi dezactivată în timpul înregistrării; închiderea aplicației în timpul "
            L"înregistrării necesită confirmare. Pauza și blocarea economizorului se aplică întregii "
            L"aplicații, indiferent de selecția monitoarelor. Când blocarea este activată, economizorul "
            L"Windows este împiedicat numai cât timp pe cel puțin un monitor este vizibilă o animație care "
            L"nu este în pauză. Aplicația poate instala sau dezinstala economizorul încorporat.\r\n\r\n"
            L"CAPTURI ȘI ÎNREGISTRARE\r\nÎn setările de înregistrare alegeți Viewport sau TV. Viewport "
            L"păstrează dimensiunile și rata de reîmprospătare a monitorului, până la 60 de cadre pe "
            L"secundă. TV oferă 1920 × 1080, 1440 × 1080 sau 1280 × 720 în 16:9, la 50, 25, 59.94 "
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
            L"ANIMAȚIE ȘI SETĂRI\r\nFlyingSolids afișează corpuri tridimensionale care se deplasează, se "
            L"rotesc și se ciocnesc. Alegeți observarea spațiului sau zborul prin spațiu și activați "
            L"corpurile dorite. Pentru fiecare monitor puteți seta separat viteza obiectelor și a camerei "
            L"între 0–1600%, dimensiunea între 50–200% și 1–10 copii ale fiecărui corp. Lumina principală, "
            L"de umplere, ambiantă și de contur se controlează independent.\r\n\r\nMONITOARE\r\nSelectați "
            L"unul sau mai multe rânduri din lista monitoarelor. Ctrl+A le selectează pe toate; Ctrl și "
            L"Shift modifică selecția. Comenzile și glisoarele animației schimbă numai setările monitoarelor "
            L"selectate. Selectarea unui rând diferă de activarea ieșirii prin caseta sa de selectare. "
            L"Selecția este reținută separat pentru aplicație și economizor. Dacă erau selectate toate "
            L"monitoarele, sunt incluse și cele conectate ulterior. Valorile diferite de pe monitoarele "
            L"selectate sunt indicate prin starea nedeterminată a casetelor de selectare și un model punctat "
            L"pe butoanele radio, mânerele glisoarelor și butoanele „Activare toate” și „Dezactivare toate”. "
            L"Etichetele glisoarelor afișează o liniuță în locul unei valori comune. Modificarea unei "
            L"opțiuni sau clicul pe un glisor aplică acea valoare tuturor monitoarelor selectate.\r\n\r\n"
            L"PREVIZUALIZARE ȘI COMENZI\r\nFolosiți FlyingSolids.scr drept economizor de ecran Windows, cu "
            L"setări separate de aplicație. Previzualizarea pe tot ecranul permite ajustări în timp real. OK "
            L"salvează modificările; Anulare sau Esc le anulează. Ieșiți din economizor apăsând o tastă sau "
            L"mișcând mouse-ul.\r\n\r\nCERINȚE DE SISTEM\r\nWindows 7–11 acceptă toate funcțiile. Pentru "
            L"Windows Vista SP2 trebuie instalate actualizările KB971512 și KB2117917. Este necesar Direct3D "
            L"11."
        },
    }),
    DefineLanguage(LANG_EL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Ελληνικά" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — χειρισμός" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Ρυθμίσεις FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Γλώσσα:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Ταχύτητα αντικειμένων: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Ταχύτητα κάμερας: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Παρατήρηση χώρου" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Πτήση στον χώρο" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Κύριος φωτισμός" },
        LocalizedText{ TXT_FILL_LIGHT, L"Φωτισμός πλήρωσης" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Τρισδιάστατα στερεά" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Κύβος" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Κανονική τετραγωνική πυραμίδα" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Κόλουρη τετραγωνική πυραμίδα" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Τετραγωνική πυραμίδα με λοξή τομή" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Πυραμίδα με τομή κάθετη στη βάση" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Κανονικό τριγωνικό πρίσμα" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Κανονικό πενταγωνικό πρίσμα" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Κανονικό εξαγωνικό πρίσμα" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Κανονικό οκτάεδρο" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Πενταγωνική διπυραμίδα" },
        LocalizedText{ TXT_SOLID_CONE, L"Ορθός κυκλικός κώνος" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Κόλουρος κώνος" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Κώνος με λοξή τομή" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Κώνος με τομή κάθετη στη βάση" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Ορθός κυκλικός κύλινδρος" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Κοίλος κυκλικός κύλινδρος" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Κοίλος κύλινδρος με τοροειδή άκρα" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Κλειστό παραβολοειδές εκ περιστροφής" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Σφαίρα" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Ημισφαίριο" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Σφαιρικός θόλος" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Μεγάλος σφαιρικός θόλος" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Σφαιρικό τμήμα δύο βάσεων" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Τριαξονικό ελλειψοειδές" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Επίμηκες σφαιροειδές" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Πεπλατυσμένο σφαιροειδές" },
        LocalizedText{ TXT_SOLID_EGG, L"Ωοειδές" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Σφαιροκύλινδρος" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Στρογγυλεμένος δίσκος (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Τόρος" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Το κλείσιμο της εφαρμογής θα διακόψει την εγγραφή που βρίσκεται σε εξέλιξη."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Αντίγραφα κάθε αντικειμένου: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Μέγεθος αντικειμένων: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Ενεργοποίηση προεπισκόπησης" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Απενεργοποίηση προεπισκόπησης" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Η κίνηση έχει παύσει." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Αναστολή προφύλαξης οθόνης κατά την κίνηση" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Περιβάλλων φωτισμός" },
        LocalizedText{ TXT_RIM_LIGHT, L"Φωτισμός περιγράμματος" },
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
            L"Κλείστε το παράθυρο ρυθμίσεων του FlyingSolids και δοκιμάστε ξανά την κατάργηση."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Κλείστε τις ρυθμίσεις προφύλαξης οθόνης των Windows και δοκιμάστε ξανά την κατάργηση."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Κλείστε την προφύλαξη ή την προεπισκόπηση πλήρους οθόνης με Esc ή κίνηση του ποντικιού και "
            L"δοκιμάστε ξανά."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Κίνηση τρισδιάστατων στερεών με επιτάχυνση υλικού." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Έκδοση:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Πλατφόρμα προορισμού:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Τοποθεσία web:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Άνοιγμα στο προεπιλεγμένο πρόγραμμα περιήγησης" },
        LocalizedText{ TXT_COPY_URL, L"Αντιγραφή &διεύθυνσης" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Αντιγραφή &πληροφοριών" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Άνοιγμα τοποθεσίας web %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Αδυναμία ανοίγματος του ιστοτόπου στον προεπιλεγμένο περιηγητή."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Δεν ήταν δυνατή η αντιγραφή του URL στο πρόχειρο." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Δεν ήταν δυνατή η αντιγραφή των πληροφοριών στο πρόχειρο."
        },
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
            L"ΚΙΝΗΣΗ ΚΑΙ ΡΥΘΜΙΣΕΙΣ\r\nΤο FlyingSolids εμφανίζει τρισδιάστατα στερεά που κινούνται, "
            L"περιστρέφονται και συγκρούονται. Επιλέξτε παρατήρηση χώρου ή πτήση στον χώρο και ενεργοποιήστε "
            L"τα επιθυμητά στερεά. Ανά οθόνη ρυθμίζονται ανεξάρτητα η ταχύτητα αντικειμένων και κάμερας "
            L"0–1600%, το μέγεθος 50–200% και 1–10 αντίγραφα κάθε στερεού. Ο κύριος φωτισμός, ο φωτισμός "
            L"πλήρωσης, ο περιβάλλων φωτισμός και ο φωτισμός περιγράμματος ελέγχονται ανεξάρτητα.\r\n\r\n"
            L"ΟΘΟΝΕΣ\r\nΕπιλέξτε μία ή περισσότερες γραμμές στη λίστα οθονών. Το Ctrl+A επιλέγει όλες, ενώ "
            L"τα Ctrl και Shift αλλάζουν την επιλογή. Τα χειριστήρια και τα ρυθμιστικά της κίνησης αλλάζουν "
            L"μόνο τις ρυθμίσεις των επιλεγμένων οθονών. Η επιλογή γραμμής διαφέρει από την ενεργοποίηση "
            L"εξόδου μέσω του πλαισίου ελέγχου της. Η επιλογή αποθηκεύεται χωριστά για την εφαρμογή και την "
            L"προφύλαξη. Αν είχαν επιλεγεί όλες οι οθόνες, περιλαμβάνονται και όσες συνδεθούν αργότερα. Οι "
            L"διαφορετικές τιμές στις επιλεγμένες οθόνες υποδεικνύονται με απροσδιόριστη κατάσταση των "
            L"πλαισίων ελέγχου και μοτίβο κουκκίδων στα κουμπιά επιλογής, στις λαβές των ρυθμιστικών και στα "
            L"κουμπιά «Ενεργοποίηση όλων» και «Απενεργοποίηση όλων». Οι ετικέτες των ρυθμιστικών δείχνουν "
            L"παύλα αντί για κοινή τιμή. Η αλλαγή επιλογής ή το κλικ σε ρυθμιστικό εφαρμόζει την τιμή σε "
            L"όλες τις επιλεγμένες οθόνες.\r\n\r\nΧΕΙΡΙΣΜΟΣ\r\nΕκτελέστε το FlyingSolids.exe. Οι ρυθμίσεις "
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
            L"ΚΙΝΗΣΗ ΚΑΙ ΡΥΘΜΙΣΕΙΣ\r\nΤο FlyingSolids εμφανίζει τρισδιάστατα στερεά που κινούνται, "
            L"περιστρέφονται και συγκρούονται. Επιλέξτε παρατήρηση χώρου ή πτήση στον χώρο και ενεργοποιήστε "
            L"τα επιθυμητά στερεά. Ανά οθόνη ρυθμίζονται ανεξάρτητα η ταχύτητα αντικειμένων και κάμερας "
            L"0–1600%, το μέγεθος 50–200% και 1–10 αντίγραφα κάθε στερεού. Ο κύριος φωτισμός, ο φωτισμός "
            L"πλήρωσης, ο περιβάλλων φωτισμός και ο φωτισμός περιγράμματος ελέγχονται ανεξάρτητα.\r\n\r\n"
            L"ΟΘΟΝΕΣ\r\nΕπιλέξτε μία ή περισσότερες γραμμές στη λίστα οθονών. Το Ctrl+A επιλέγει όλες, ενώ "
            L"τα Ctrl και Shift αλλάζουν την επιλογή. Τα χειριστήρια και τα ρυθμιστικά της κίνησης αλλάζουν "
            L"μόνο τις ρυθμίσεις των επιλεγμένων οθονών. Η επιλογή γραμμής διαφέρει από την ενεργοποίηση "
            L"εξόδου μέσω του πλαισίου ελέγχου της. Η επιλογή αποθηκεύεται χωριστά για την εφαρμογή και την "
            L"προφύλαξη. Αν είχαν επιλεγεί όλες οι οθόνες, περιλαμβάνονται και όσες συνδεθούν αργότερα. Οι "
            L"διαφορετικές τιμές στις επιλεγμένες οθόνες υποδεικνύονται με απροσδιόριστη κατάσταση των "
            L"πλαισίων ελέγχου και μοτίβο κουκκίδων στα κουμπιά επιλογής, στις λαβές των ρυθμιστικών και στα "
            L"κουμπιά «Ενεργοποίηση όλων» και «Απενεργοποίηση όλων». Οι ετικέτες των ρυθμιστικών δείχνουν "
            L"παύλα αντί για κοινή τιμή. Η αλλαγή επιλογής ή το κλικ σε ρυθμιστικό εφαρμόζει την τιμή σε "
            L"όλες τις επιλεγμένες οθόνες.\r\n\r\nΠΡΟΕΠΙΣΚΟΠΗΣΗ ΚΑΙ ΧΕΙΡΙΣΜΟΣ\r\nΧρησιμοποιήστε το "
            L"FlyingSolids.scr ως προφύλαξη οθόνης Windows με χωριστές ρυθμίσεις από την εφαρμογή. Η "
            L"προεπισκόπηση πλήρους οθόνης επιτρέπει ζωντανές αλλαγές. Το OK αποθηκεύει και το Άκυρο ή Esc "
            L"απορρίπτει τις αλλαγές. Τερματίστε την προφύλαξη με πλήκτρο ή κίνηση του ποντικιού.\r\n\r\n"
            L"ΑΠΑΙΤΗΣΕΙΣ ΣΥΣΤΗΜΑΤΟΣ\r\nΤα Windows 7–11 υποστηρίζουν όλες τις λειτουργίες. Στα Windows Vista "
            L"SP2 πρέπει να εγκατασταθούν οι ενημερώσεις KB971512 και KB2117917. Απαιτείται υποστήριξη "
            L"Direct3D 11."
        },
    }),
    DefineLanguage(LANG_BS, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Bosanski" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — kontrole" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Postavke programa FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Jezik:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Brzina objekata: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Brzina kamere: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Posmatranje prostora" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Let kroz prostor" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Glavno svjetlo" },
        LocalizedText{ TXT_FILL_LIGHT, L"Dopunsko svjetlo" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Prostorna tijela" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Kocka" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Pravilna četverostrana piramida" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Zarubljena četverostrana piramida" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Četverostrana piramida s kosim presjekom" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Piramida s presjekom okomitim na bazu" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Pravilna trostrana prizma" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Pravilna peterostrana prizma" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Pravilna šesterostrana prizma" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Pravilni oktaedar" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Peterostrana bipiramida" },
        LocalizedText{ TXT_SOLID_CONE, L"Pravi kružni stožac" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Zarubljeni stožac" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Stožac s kosim presjekom" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Stožac s presjekom okomitim na bazu" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Pravi kružni valjak" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Šuplji kružni valjak" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Šuplji valjak s torusnim krajevima" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Rotacijski paraboloid zatvoren ravninom" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Kugla" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Polukugla" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Kuglin odsječak" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Veliki kuglin odsječak" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Kuglin sloj" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Troosni elipsoid" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Izduženi rotacijski elipsoid" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Spljošteni rotacijski elipsoid" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoid" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sferocilindar" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Zaobljeni disk (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Torus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Zatvaranje aplikacije zaustavit će snimanje koje je u toku."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Kopije svakog objekta: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Veličina objekata: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Uključi pregled" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Isključi pregled" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animacija je pauzirana." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Spriječi čuvar ekrana tokom animacije" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ambijentalno svjetlo" },
        LocalizedText{ TXT_RIM_LIGHT, L"Konturno svjetlo" },
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
            L"Zatvorite postavke programa FlyingSolids pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zatvorite Windows postavke čuvara ekrana pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zatvorite čuvar ili pregled preko cijelog ekrana tipkom Esc ili pomjeranjem miša pa ponovite "
            L"deinstalaciju."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardverski ubrzana animacija prostornih tijela." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Verzija:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Ciljna platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Web-mjesto:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Otvori u podrazumijevanom pregledniku" },
        LocalizedText{ TXT_COPY_URL, L"Kopiraj &adresu" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopiraj &informacije" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Posjeti web-mjesto %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Nije moguće otvoriti stranicu u podrazumijevanom pregledniku."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Nije moguće kopirati URL u međuspremnik." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Nije moguće kopirati informacije u međuspremnik."
        },
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
            L"ANIMACIJA I POSTAVKE\r\nFlyingSolids prikazuje prostorna tijela koja se kreću, okreću i "
            L"sudaraju. Odaberite posmatranje prostora ili let kroz prostor te željena tijela. Za svaki "
            L"monitor zasebno se podešavaju brzina objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija "
            L"svakog tijela. Glavno, dopunsko, ambijentalno i konturno svjetlo uključuju se nezavisno.\r\n\r"
            L"\nMONITORI\r\nOdaberite jedan ili više redova u listi monitora. Ctrl+A odabire sve; Ctrl i "
            L"Shift mijenjaju odabir. Kontrole i klizači animacije mijenjaju samo postavke odabranih "
            L"monitora. Odabir reda nije isto što i uključivanje izlaza njegovom kućicom. Odabir se pamti "
            L"odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili odabrani svi monitori, uključuju "
            L"se i novopriključeni monitori. Različite vrijednosti na odabranim monitorima prikazuju se "
            L"neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, ručkama klizača i "
            L"dugmadima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju crticu umjesto zajedničke "
            L"vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost na sve odabrane "
            L"monitore.\r\n\r\nUPRAVLJANJE\r\nPokrenite FlyingSolids.exe. Postavke se stalno čuvaju i radi "
            L"samo jedna instanca aplikacije. Kućica monitora ili dvostruki klik na red uključuje ili "
            L"isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe prvi "
            L"aktivni monitor animacije, ne zajedničku sliku svih monitora. Animacijski izlaz snimanog "
            L"monitora ne možete isključiti tokom snimanja; zatvaranje aplikacije tokom snimanja zahtijeva "
            L"potvrdu. Pauza i blokada čuvara ekrana vrijede za cijelu aplikaciju, bez obzira na odabir "
            L"monitora. Kada je blokada uključena, čuvar ekrana Windowsa se sprječava samo dok je na barem "
            L"jednom monitoru vidljiva animacija koja nije pauzirana. Aplikacija može instalirati i "
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
            L"ANIMACIJA I POSTAVKE\r\nFlyingSolids prikazuje prostorna tijela koja se kreću, okreću i "
            L"sudaraju. Odaberite posmatranje prostora ili let kroz prostor te željena tijela. Za svaki "
            L"monitor zasebno se podešavaju brzina objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija "
            L"svakog tijela. Glavno, dopunsko, ambijentalno i konturno svjetlo uključuju se nezavisno.\r\n\r"
            L"\nMONITORI\r\nOdaberite jedan ili više redova u listi monitora. Ctrl+A odabire sve; Ctrl i "
            L"Shift mijenjaju odabir. Kontrole i klizači animacije mijenjaju samo postavke odabranih "
            L"monitora. Odabir reda nije isto što i uključivanje izlaza njegovom kućicom. Odabir se pamti "
            L"odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili odabrani svi monitori, uključuju "
            L"se i novopriključeni monitori. Različite vrijednosti na odabranim monitorima prikazuju se "
            L"neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, ručkama klizača i "
            L"dugmadima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju crticu umjesto zajedničke "
            L"vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost na sve odabrane "
            L"monitore.\r\n\r\nPREGLED I UPRAVLJANJE\r\nKoristite FlyingSolids.scr kao Windows čuvar ekrana "
            L"s odvojenim postavkama. Pregled preko cijelog ekrana omogućava izmjene uživo. OK čuva, a "
            L"Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili pomjeranjem miša.\r\n\r"
            L"\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate "
            L"instalirati ažuriranja KB971512 i KB2117917. Potreban je Direct3D 11."
        },
    }),
    DefineLanguage(LANG_HR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Hrvatski" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — upravljanje" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Postavke programa FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Jezik:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Brzina objekata: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Brzina kamere: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Promatranje prostora" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Let kroz prostor" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Glavno svjetlo" },
        LocalizedText{ TXT_FILL_LIGHT, L"Dopunsko svjetlo" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Prostorna tijela" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Kocka" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Pravilna četverostrana piramida" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Krnja četverostrana piramida" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Četverostrana piramida s kosim presjekom" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Piramida s presjekom okomitim na bazu" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Pravilna trostrana prizma" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Pravilna peterostrana prizma" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Pravilna šesterostrana prizma" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Pravilni oktaedar" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Peterostrana bipiramida" },
        LocalizedText{ TXT_SOLID_CONE, L"Uspravni kružni stožac" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Krnji stožac" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Stožac s kosim presjekom" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Stožac s presjekom okomitim na bazu" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Uspravni kružni valjak" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Šuplji kružni valjak" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Šuplji valjak s torusnim krajevima" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Rotacijski paraboloid zatvoren ravninom" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Kugla" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Polukugla" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Kuglin odsječak" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Veliki kuglin odsječak" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Kuglin sloj" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Troosni elipsoid" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Izduženi rotacijski elipsoid" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Spljošteni rotacijski elipsoid" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoid" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sferocilindar" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Zaobljeni disk (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Torus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Zatvaranje aplikacije zaustavit će snimanje koje je u tijeku."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Kopije svakog objekta: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Veličina objekata: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Uključi pretpregled" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Isključi pretpregled" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animacija je pauzirana." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Spriječi čuvar zaslona tijekom animacije" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ambijentalno svjetlo" },
        LocalizedText{ TXT_RIM_LIGHT, L"Konturno svjetlo" },
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
            L"Zatvorite postavke programa FlyingSolids pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zatvorite Windows postavke čuvara zaslona pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zatvorite čuvar ili pretpregled preko cijelog zaslona tipkom Esc ili pomicanjem miša pa "
            L"ponovite deinstalaciju."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardverski ubrzana animacija prostornih tijela." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Verzija:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Ciljna platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Web-mjesto:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Otvori u zadanom pregledniku" },
        LocalizedText{ TXT_COPY_URL, L"Kopiraj &adresu" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopiraj &informacije" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Posjeti web-mjesto %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Nije moguće otvoriti stranicu u zadanom pregledniku." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Nije moguće kopirati URL u međuspremnik." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Nije moguće kopirati informacije u međuspremnik."
        },
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
            L"ANIMACIJA I POSTAVKE\r\nFlyingSolids prikazuje prostorna tijela koja se kreću, okreću i "
            L"sudaraju. Odaberite promatranje prostora ili let kroz prostor te željena tijela. Za svaki "
            L"zaslon zasebno se podešavaju brzina objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija "
            L"svakog tijela. Glavno, dopunsko, ambijentalno i konturno svjetlo uključuju se neovisno.\r\n\r\n"
            L"MONITORI\r\nOdaberite jedan ili više redaka na popisu zaslona. Ctrl+A odabire sve; Ctrl i "
            L"Shift mijenjaju odabir. Kontrole i klizači animacije mijenjaju samo postavke odabranih "
            L"zaslona. Odabir retka nije isto što i uključivanje izlaza njegovim potvrdnim okvirom. Odabir "
            L"se pamti odvojeno za aplikaciju i čuvar zaslona. Ako su prethodno bili odabrani svi zasloni, "
            L"uključuju se i novopriključeni zasloni. Različite vrijednosti na odabranim zaslonima prikazuju "
            L"se neodređenim stanjem potvrdnih okvira i točkastim uzorkom na izbornim gumbima, ručkama "
            L"klizača i gumbima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju crticu umjesto "
            L"zajedničke vrijednosti. Promjena mogućnosti ili klik na klizač primjenjuje tu vrijednost na "
            L"sve odabrane zaslone.\r\n\r\nUPRAVLJANJE\r\nPokrenite FlyingSolids.exe. Postavke se neprekidno "
            L"spremaju i radi samo jedna instanca aplikacije. Potvrdni okvir zaslona ili dvostruki klik na "
            L"redak uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG "
            L"i MP4 bilježe prvi aktivni zaslon animacije, ne zajedničku sliku svih zaslona. Animacijski "
            L"izlaz snimanog zaslona ne možete isključiti tijekom snimanja; zatvaranje aplikacije tijekom "
            L"snimanja zahtijeva potvrdu. Pauza i blokada čuvara zaslona vrijede za cijelu aplikaciju, bez "
            L"obzira na odabir zaslona. Kada je blokada uključena, čuvar zaslona sustava Windows sprječava "
            L"se samo dok je na barem jednom zaslonu vidljiva animacija koja nije pauzirana. Aplikacija može "
            L"instalirati i deinstalirati ugrađeni čuvar zaslona.\r\n\r\nSNIMKE ZASLONA I SNIMANJE\r\nU "
            L"postavkama snimanja odaberite Viewport ili TV. Viewport zadržava dimenzije i frekvenciju "
            L"osvježavanja zaslona do 60 sličica u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 "
            L"u omjeru 16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) sličica u sekundi. TV video "
            L"je progresivni BT.709 ograničenog raspona s poduzorkovanjem boje 4:2:0. Omjer slike ostaje "
            L"sačuvan, a dopunske trake su crne. OK sprema mogućnosti za sljedeću snimku; Odustani ili Esc "
            L"odbacuje nepotvrđene izmjene. Prozori snimanja, pomoći i informacija ne blokiraju ostale "
            L"prozore i mogu se minimizirati. Tab i Shift+Tab pomiču fokus, Enter aktivira fokusirani gumb, "
            L"a Esc zatvara aktivni pomoćni prozor.\r\n\r\nZAHTJEVI SUSTAVA\r\nWindows 7–11 podržava sve "
            L"funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917; MP4 "
            L"snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media Foundation te H.264 "
            L"koder. Sučelje i dokumentacija dostupni su na 36 jezika."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACIJA I POSTAVKE\r\nFlyingSolids prikazuje prostorna tijela koja se kreću, okreću i "
            L"sudaraju. Odaberite promatranje prostora ili let kroz prostor te željena tijela. Za svaki "
            L"zaslon zasebno se podešavaju brzina objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija "
            L"svakog tijela. Glavno, dopunsko, ambijentalno i konturno svjetlo uključuju se neovisno.\r\n\r\n"
            L"MONITORI\r\nOdaberite jedan ili više redaka na popisu zaslona. Ctrl+A odabire sve; Ctrl i "
            L"Shift mijenjaju odabir. Kontrole i klizači animacije mijenjaju samo postavke odabranih "
            L"zaslona. Odabir retka nije isto što i uključivanje izlaza njegovim potvrdnim okvirom. Odabir "
            L"se pamti odvojeno za aplikaciju i čuvar zaslona. Ako su prethodno bili odabrani svi zasloni, "
            L"uključuju se i novopriključeni zasloni. Različite vrijednosti na odabranim zaslonima prikazuju "
            L"se neodređenim stanjem potvrdnih okvira i točkastim uzorkom na izbornim gumbima, ručkama "
            L"klizača i gumbima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju crticu umjesto "
            L"zajedničke vrijednosti. Promjena mogućnosti ili klik na klizač primjenjuje tu vrijednost na "
            L"sve odabrane zaslone.\r\n\r\nPRETPREGLED I UPRAVLJANJE\r\nKoristite FlyingSolids.scr kao "
            L"Windows čuvar zaslona s odvojenim postavkama. Pretpregled preko cijelog zaslona omogućuje "
            L"izmjene uživo. OK sprema, a Odustani ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom "
            L"tipke ili pomicanjem miša.\r\n\r\nZAHTJEVI SUSTAVA\r\nWindows 7–11 podržava sve funkcije. Za "
            L"Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917. Potreban je Direct3D 11."
        },
    }),
    DefineLanguage(LANG_SL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Slovenščina" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — upravljanje" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Nastavitve FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Jezik:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Hitrost predmetov: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Hitrost kamere: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Opazovanje prostora" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Let skozi prostor" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Glavna svetloba" },
        LocalizedText{ TXT_FILL_LIGHT, L"Dopolnilna svetloba" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Prostorska telesa" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Kocka" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Pravilna štiristrana piramida" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Prisekana štiristrana piramida" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Poševno prirezana štiristrana piramida" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Piramida s prerezom pravokotno na osnovo" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Pravilna tristrana prizma" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Pravilna petstrana prizma" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Pravilna šeststrana prizma" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Pravilni oktaeder" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Petstrana bipiramida" },
        LocalizedText{ TXT_SOLID_CONE, L"Pokončni krožni stožec" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Prisekani stožec" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Poševno prirezani stožec" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Stožec s prerezom pravokotno na osnovo" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Pokončni krožni valj" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Votel krožni valj" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Votel valj s toroidnima koncema" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Rotacijski paraboloid, zaprt z ravnino" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Krogla" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Polkrogla" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Krogelni odsek" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Veliki krogelni odsek" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Krogelna plast" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Triosni elipsoid" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Podolgovati rotacijski elipsoid" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Sploščeni rotacijski elipsoid" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoid" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sferocilinder" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Zaobljena ploščica (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Torus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Zapiranje programa bo ustavilo trenutno snemanje." },
        LocalizedText{ TXT_COPY_COUNT, L"Kopije posameznega predmeta: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Velikost predmetov: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Vklopi predogled" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Izklopi predogled" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animacija je začasno ustavljena." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Prepreči ohranjevalnik med animacijo" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Okoljska svetloba" },
        LocalizedText{ TXT_RIM_LIGHT, L"Obrobna svetloba" },
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
            L"Zaprite nastavitve FlyingSolids in znova poskusite odstranitev."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zaprite nastavitve ohranjevalnika zaslona Windows in znova poskusite odstranitev."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zaprite ohranjevalnik ali celozaslonski predogled s tipko Esc ali premikom miške in znova "
            L"poskusite odstranitev."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Strojno pospešena animacija prostorskih teles." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Različica:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Ciljna platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Spletno mesto:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Odpri v privzetem brskalniku" },
        LocalizedText{ TXT_COPY_URL, L"Kopiraj &naslov" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopiraj &podatke" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Obišči spletno mesto %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Spletnega mesta ni mogoče odpreti v privzetem brskalniku."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL-ja ni bilo mogoče kopirati v odložišče." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Podatkov ni bilo mogoče kopirati v odložišče." },
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
            L"ANIMACIJA IN NASTAVITVE\r\nFlyingSolids prikazuje prostorska telesa, ki se premikajo, vrtijo "
            L"in trkajo. Izberite opazovanje prostora ali let skozi prostor in želena telesa. Za vsak zaslon "
            L"so ločeno nastavljivi hitrost predmetov in kamere 0–1600%, velikost 50–200% ter 1–10 kopij "
            L"vsakega telesa. Glavna, dopolnilna, okoljska in obrobna svetloba se vklapljajo neodvisno.\r\n\r"
            L"\nZASLONI\r\nNa seznamu zaslonov izberite eno ali več vrstic. Ctrl+A izbere vse, Ctrl in Shift "
            L"pa spreminjata izbor. Kontrolniki in drsniki animacije spreminjajo samo nastavitve izbranih "
            L"zaslonov. Izbira vrstice ni isto kot vklop izhoda z njenim potrditvenim poljem. Izbor se "
            L"ločeno shrani za program in ohranjevalnik. Če so bili izbrani vsi zasloni, so vključeni tudi "
            L"na novo priključeni zasloni. Različne vrednosti na izbranih zaslonih označujeta nedoločeno "
            L"stanje potrditvenih polj in pikčast vzorec na izbirnih gumbih, ročicah drsnikov ter gumbih "
            L"»Vklopi vse« in »Izklopi vse«. Oznake drsnikov namesto skupne vrednosti prikazujejo pomišljaj. "
            L"Sprememba možnosti ali klik na drsnik uveljavi to vrednost na vseh izbranih zaslonih.\r\n\r\n"
            L"UPRAVLJANJE\r\nZaženite FlyingSolids.exe. Nastavitve se shranjujejo sproti in deluje le en "
            L"primerek programa. Polje zaslona ali dvojni klik na vrstico vklopi ali izklopi izhod "
            L"animacije. Animacijo lahko začasno ustavite in nadaljujete. PNG in MP4 zajameta prvi aktivni "
            L"zaslon animacije, ne skupne slike vseh zaslonov. Izhoda animacije snemanega zaslona med "
            L"snemanjem ni mogoče izklopiti; zapiranje programa med snemanjem zahteva potrditev. Premor in "
            L"preprečevanje ohranjevalnika veljata za celoten program, ne glede na izbor zaslonov. Ko je "
            L"preprečevanje vključeno, se ohranjevalnik Windows prepreči le, dokler je na vsaj enem zaslonu "
            L"vidna animacija, ki ni ustavljena. Program lahko namesti ali odstrani vgrajeni ohranjevalnik.\r"
            L"\n\r\nPOSNETKI ZASLONA IN SNEMANJE\r\nV nastavitvah snemanja izberite Viewport ali TV. "
            L"Viewport ohrani velikost in hitrost osveževanja zaslona do 60 sličic na sekundo. TV ponuja "
            L"1920 × 1080, 1440 × 1080 ali 1280 × 720 v razmerju 16:9 ter 50, 25, 59.94 (60000/1001) ali "
            L"29.97 (30000/1001) sličic na sekundo. TV uporablja progresivni BT.709 z omejenim obsegom in "
            L"barvnim podvzorčenjem 4:2:0. Razmerje slike se ohrani, dopolnilni pasovi so črni. OK shrani "
            L"izbiro za naslednje snemanje; Prekliči ali Esc zavrže nepotrjene spremembe. Okna snemanja, "
            L"pomoči in podatkov o programu ne blokirajo drugih oken in jih je mogoče minimirati. Tab in "
            L"Shift+Tab premikata fokus, Enter aktivira izbrani gumb, Esc pa zapre aktivno pomožno okno.\r\n"
            L"\r\nSISTEMSKE ZAHTEVE\r\nWindows 7–11 podpira vse funkcije. Za Windows Vista SP2 morate "
            L"namestiti posodobitvi KB971512 in KB2117917; snemanje MP4 v Visti ne deluje. Potrebna je "
            L"podpora Direct3D 11, za MP4 pa še Media Foundation in kodirnik H.264. Vmesnik in dokumentacija "
            L"sta na voljo v 36 jezikih."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACIJA IN NASTAVITVE\r\nFlyingSolids prikazuje prostorska telesa, ki se premikajo, vrtijo "
            L"in trkajo. Izberite opazovanje prostora ali let skozi prostor in želena telesa. Za vsak zaslon "
            L"so ločeno nastavljivi hitrost predmetov in kamere 0–1600%, velikost 50–200% ter 1–10 kopij "
            L"vsakega telesa. Glavna, dopolnilna, okoljska in obrobna svetloba se vklapljajo neodvisno.\r\n\r"
            L"\nZASLONI\r\nNa seznamu zaslonov izberite eno ali več vrstic. Ctrl+A izbere vse, Ctrl in Shift "
            L"pa spreminjata izbor. Kontrolniki in drsniki animacije spreminjajo samo nastavitve izbranih "
            L"zaslonov. Izbira vrstice ni isto kot vklop izhoda z njenim potrditvenim poljem. Izbor se "
            L"ločeno shrani za program in ohranjevalnik. Če so bili izbrani vsi zasloni, so vključeni tudi "
            L"na novo priključeni zasloni. Različne vrednosti na izbranih zaslonih označujeta nedoločeno "
            L"stanje potrditvenih polj in pikčast vzorec na izbirnih gumbih, ročicah drsnikov ter gumbih "
            L"»Vklopi vse« in »Izklopi vse«. Oznake drsnikov namesto skupne vrednosti prikazujejo pomišljaj. "
            L"Sprememba možnosti ali klik na drsnik uveljavi to vrednost na vseh izbranih zaslonih.\r\n\r\n"
            L"PREDOGLED IN UPRAVLJANJE\r\nUporabite FlyingSolids.scr kot ohranjevalnik zaslona Windows z "
            L"ločenimi nastavitvami. Celozaslonski predogled omogoča sprotne spremembe. OK jih shrani, "
            L"Prekliči ali Esc jih zavrže. Ohranjevalnik zapustite s tipko ali premikom miške.\r\n\r\n"
            L"SISTEMSKE ZAHTEVE\r\nWindows 7–11 podpira vse funkcije. Za Windows Vista SP2 morate namestiti "
            L"posodobitvi KB971512 in KB2117917. Potrebna je podpora Direct3D 11."
        },
    }),
    DefineLanguage(LANG_CNR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Crnogorski" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — kontrole" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Podešavanja programa FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Jezik:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Brzina objekata: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Brzina kamere: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Posmatranje prostora" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Let kroz prostor" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Glavno svjetlo" },
        LocalizedText{ TXT_FILL_LIGHT, L"Dopunsko svjetlo" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Prostorna tijela" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Kocka" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Pravilna četvorostrana piramida" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Zarubljena četvorostrana piramida" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Četvorostrana piramida s kosim presjekom" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Piramida s presjekom normalnim na osnovu" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Pravilna trostrana prizma" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Pravilna petostrana prizma" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Pravilna šestostrana prizma" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Pravilni oktaedar" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Petostrana bipiramida" },
        LocalizedText{ TXT_SOLID_CONE, L"Prava kružna kupa" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Zarubljena kupa" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Kupa s kosim presjekom" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Kupa s presjekom normalnim na osnovu" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Pravi kružni valjak" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Šuplji kružni valjak" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Šuplji valjak s torusnim krajevima" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Rotacioni paraboloid zatvoren ravni" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Lopta" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Polulopta" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Loptin odsječak" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Veliki loptin odsječak" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Loptin sloj" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Troosni elipsoid" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Izduženi rotacioni elipsoid" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Spljošteni rotacioni elipsoid" },
        LocalizedText{ TXT_SOLID_EGG, L"Ovoid" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Sferocilindar" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Zaobljeni disk (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Torus" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Zatvaranje aplikacije zaustaviće snimanje koje je u toku."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Kopije svakog objekta: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Veličina objekata: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Uključi pregled" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Isključi pregled" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Animacija je pauzirana." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Spriječi čuvar ekrana tokom animacije" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Ambijentalno svjetlo" },
        LocalizedText{ TXT_RIM_LIGHT, L"Konturno svjetlo" },
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
            L"Zatvorite podešavanja programa FlyingSolids pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zatvorite Windows podešavanja čuvara ekrana pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zatvorite čuvar ili pregled preko cijelog ekrana tasterom Esc ili pomjeranjem miša pa ponovite "
            L"deinstalaciju."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Hardverski ubrzana animacija prostornih tijela." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Verzija:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Ciljna platforma:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Veb-sajt:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Otvori u podrazumijevanom pregledaču" },
        LocalizedText{ TXT_COPY_URL, L"Kopiraj &adresu" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Kopiraj &podatke" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Otvori veb-sajt %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Nije moguće otvoriti stranicu u podrazumijevanom pregledaču."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Nije moguće kopirati URL u međuspremnik." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Nije moguće kopirati podatke u međuspremnik." },
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
            L"ANIMACIJA I PODEŠAVANJA\r\nFlyingSolids prikazuje prostorna tijela koja se kreću, okreću i "
            L"sudaraju. Izaberite posmatranje prostora ili let kroz prostor te željena tijela. Za svaki "
            L"monitor zasebno se podešavaju brzina objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija "
            L"svakog tijela. Glavno, dopunsko, ambijentalno i konturno svjetlo uključuju se nezavisno.\r\n\r"
            L"\nMONITORI\r\nIzaberite jedan ili više redova u listi monitora. Ctrl+A bira sve; Ctrl i Shift "
            L"mijenjaju izbor. Kontrole i klizači animacije mijenjaju samo podešavanja izabranih monitora. "
            L"Izbor reda nije isto što i uključivanje izlaza njegovom kućicom. Izbor se pamti odvojeno za "
            L"aplikaciju i čuvar ekrana. Ako su prethodno bili izabrani svi monitori, uključuju se i "
            L"novopriključeni monitori. Različite vrijednosti na izabranim monitorima prikazuju se "
            L"neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, ručkama klizača i "
            L"dugmadima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju crticu umjesto zajedničke "
            L"vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost na sve izabrane "
            L"monitore.\r\n\r\nUPRAVLJANJE\r\nPokrenite FlyingSolids.exe. Podešavanja se stalno čuvaju i "
            L"radi samo jedna instanca aplikacije. Kućica monitora ili dvostruki klik na red uključuje ili "
            L"isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe prvi "
            L"aktivni monitor animacije, ne zajedničku sliku svih monitora. Animacijski izlaz snimanog "
            L"monitora ne možete isključiti tokom snimanja; zatvaranje aplikacije tokom snimanja zahtijeva "
            L"potvrdu. Pauza i blokada čuvara ekrana važe za cijelu aplikaciju, bez obzira na izbor "
            L"monitora. Kada je blokada uključena, čuvar ekrana Windowsa se sprječava samo dok je na barem "
            L"jednom monitoru vidljiva animacija koja nije pauzirana. Aplikacija može instalirati i "
            L"deinstalirati ugrađeni čuvar ekrana.\r\n\r\nSNIMCI EKRANA I SNIMANJE\r\nU podešavanjima "
            L"snimanja izaberite Viewport ili TV. Viewport zadržava dimenzije i frekvenciju osvježavanja "
            L"monitora do 60 kadrova u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u odnosu "
            L"16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) kadrova u sekundi. TV video je "
            L"progresivni BT.709 ograničenog opsega s poduzorkovanjem boje 4:2:0. Odnos slike ostaje "
            L"sačuvan, a dopunske trake su crne. OK čuva opcije za sljedeći snimak; Otkaži ili Esc odbacuje "
            L"nepotvrđene izmjene. Prozori snimanja, pomoći i informacija ne blokiraju ostale prozore i mogu "
            L"se minimizovati. Tab i Shift+Tab pomjeraju fokus, Enter aktivira fokusirano dugme, a Esc "
            L"zatvara aktivni pomoćni prozor.\r\n\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve "
            L"funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917; MP4 "
            L"snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media Foundation i H.264 koder. "
            L"Interfejs i dokumentacija dostupni su na 36 jezika."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"ANIMACIJA I PODEŠAVANJA\r\nFlyingSolids prikazuje prostorna tijela koja se kreću, okreću i "
            L"sudaraju. Izaberite posmatranje prostora ili let kroz prostor te željena tijela. Za svaki "
            L"monitor zasebno se podešavaju brzina objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija "
            L"svakog tijela. Glavno, dopunsko, ambijentalno i konturno svjetlo uključuju se nezavisno.\r\n\r"
            L"\nMONITORI\r\nIzaberite jedan ili više redova u listi monitora. Ctrl+A bira sve; Ctrl i Shift "
            L"mijenjaju izbor. Kontrole i klizači animacije mijenjaju samo podešavanja izabranih monitora. "
            L"Izbor reda nije isto što i uključivanje izlaza njegovom kućicom. Izbor se pamti odvojeno za "
            L"aplikaciju i čuvar ekrana. Ako su prethodno bili izabrani svi monitori, uključuju se i "
            L"novopriključeni monitori. Različite vrijednosti na izabranim monitorima prikazuju se "
            L"neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, ručkama klizača i "
            L"dugmadima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju crticu umjesto zajedničke "
            L"vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost na sve izabrane "
            L"monitore.\r\n\r\nPREGLED I UPRAVLJANJE\r\nKoristite FlyingSolids.scr kao Windows čuvar ekrana "
            L"s odvojenim podešavanjima. Pregled preko cijelog ekrana omogućava izmjene uživo. OK čuva, a "
            L"Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tastera ili pomjeranjem miša.\r\n"
            L"\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate "
            L"instalirati ažuriranja KB971512 i KB2117917. Potreban je Direct3D 11."
        },
    }),
    DefineLanguage(LANG_BE, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Беларуская" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — кіраванне" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Налады FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Мова:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Хуткасць аб’ектаў: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Хуткасць камеры: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Назіранне за прасторай" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Палёт праз прастору" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Асноўнае святло" },
        LocalizedText{ TXT_FILL_LIGHT, L"Запаўняльнае святло" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Аб’ёмныя целы" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Куб" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Правільная чатырохвугольная піраміда" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Усечаная чатырохвугольная піраміда" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Чатырохвугольная піраміда з косым зрэзам" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT,
            L"Піраміда са зрэзам, перпендыкулярным аснове"
        },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Правільная трохвугольная прызма" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Правільная пяцівугольная прызма" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Правільная шасцівугольная прызма" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Правільны актаэдр" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Пяцівугольная біпіраміда" },
        LocalizedText{ TXT_SOLID_CONE, L"Прамы кругавы конус" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Усечаны конус" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Конус з косым зрэзам" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Конус са зрэзам, перпендыкулярным аснове" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Прамы кругавы цыліндр" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Полы кругавы цыліндр" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Полы цыліндр з тараідальнымі канцамі" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Парабалоід вярчэння, замкнёны плоскасцю" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Шар" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Паўшар" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Шаравы сегмент" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Вялікі шаравы сегмент" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Шаравы слой" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Трохвосевы эліпсоід" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Выцягнуты эліпсоід вярчэння" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Сплюшчаны эліпсоід вярчэння" },
        LocalizedText{ TXT_SOLID_EGG, L"Авоід" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Сферацыліндр" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Скруглены дыск (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Тор" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Закрыццё праграмы спыніць бягучы запіс." },
        LocalizedText{ TXT_COPY_COUNT, L"Копій кожнага аб’екта: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Памер аб’ектаў: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Уключыць перадпрагляд" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Выключыць перадпрагляд" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Анімацыя прыпынена." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Блакаваць застаўку падчас анімацыі" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Фонавае святло" },
        LocalizedText{ TXT_RIM_LIGHT, L"Контурнае святло" },
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
            L"Закрыйце налады FlyingSolids ды паўтарыце выдаленне."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Закрыйце акно налад застаўкі Windows ды паўтарыце выдаленне."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Завяршыце застаўку або поўнаэкранны перадпрагляд клавішай Esc ці рухам мышы ды паўтарыце "
            L"выдаленне."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Апаратна паскораная анімацыя аб’ёмных целаў." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Версія:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Мэтавая платформа:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Вэб-сайт:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Адкрыць у прадвызначаным браўзеры" },
        LocalizedText{ TXT_COPY_URL, L"Капіяваць &адрас" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Капіяваць &звесткі" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Адкрыць вэб-сайт %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Немагчыма адкрыць сайт у прадвызначаным браўзеры." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Не ўдалося скапіяваць URL у буфер абмену." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Не ўдалося скапіяваць звесткі ў буфер абмену." },
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
            L"АНІМАЦЫЯ І НАЛАДЫ\r\nFlyingSolids паказвае аб’ёмныя целы, якія рухаюцца, круцяцца і "
            L"сутыкаюцца. Выберыце назіранне за прасторай або палёт праз яе і патрэбныя целы. Для кожнага "
            L"манітора асобна задаюцца хуткасці аб’ектаў і камеры 0–1600%, памер 50–200% і 1–10 копій "
            L"кожнага цела. Асноўнае, запаўняльнае, фонавае і контурнае святло ўключаюцца незалежна.\r\n\r\n"
            L"МАНІТОРЫ\r\nВыберыце адзін або некалькі радкоў у спісе манітораў. Ctrl+A выбірае ўсе; Ctrl і "
            L"Shift змяняюць выбар. Элементы кіравання і паўзункі анімацыі змяняюць толькі налады выбраных "
            L"манітораў. Выбар радка і ўключэнне вываду яго сцяжком — розныя дзеянні. Выбар асобна "
            L"захоўваецца для праграмы і застаўкі. Калі раней былі выбраны ўсе маніторы, да выбару "
            L"далучаюцца і новыя маніторы. Розныя значэнні на выбраных маніторах пазначаюцца нявызначаным "
            L"станам сцяжкоў і кропкавым узорам на пераключальніках, ручках паўзункоў і кнопках «Уключыць "
            L"усё» і «Выключыць усё». У подпісах паўзункоў замест агульнага значэння паказваецца працяжнік. "
            L"Змена параметра або націск на паўзунок ужывае гэта значэнне да ўсіх выбраных манітораў.\r\n\r\n"
            L"КІРАВАННЕ\r\nЗапусціце FlyingSolids.exe. Налады захоўваюцца пастаянна, працуе толькі адзін "
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
            L"АНІМАЦЫЯ І НАЛАДЫ\r\nFlyingSolids паказвае аб’ёмныя целы, якія рухаюцца, круцяцца і "
            L"сутыкаюцца. Выберыце назіранне за прасторай або палёт праз яе і патрэбныя целы. Для кожнага "
            L"манітора асобна задаюцца хуткасці аб’ектаў і камеры 0–1600%, памер 50–200% і 1–10 копій "
            L"кожнага цела. Асноўнае, запаўняльнае, фонавае і контурнае святло ўключаюцца незалежна.\r\n\r\n"
            L"МАНІТОРЫ\r\nВыберыце адзін або некалькі радкоў у спісе манітораў. Ctrl+A выбірае ўсе; Ctrl і "
            L"Shift змяняюць выбар. Элементы кіравання і паўзункі анімацыі змяняюць толькі налады выбраных "
            L"манітораў. Выбар радка і ўключэнне вываду яго сцяжком — розныя дзеянні. Выбар асобна "
            L"захоўваецца для праграмы і застаўкі. Калі раней былі выбраны ўсе маніторы, да выбару "
            L"далучаюцца і новыя маніторы. Розныя значэнні на выбраных маніторах пазначаюцца нявызначаным "
            L"станам сцяжкоў і кропкавым узорам на пераключальніках, ручках паўзункоў і кнопках «Уключыць "
            L"усё» і «Выключыць усё». У подпісах паўзункоў замест агульнага значэння паказваецца працяжнік. "
            L"Змена параметра або націск на паўзунок ужывае гэта значэнне да ўсіх выбраных манітораў.\r\n\r\n"
            L"ПЕРАДПРАГЛЯД І КІРАВАННЕ\r\nВыкарыстоўвайце FlyingSolids.scr як застаўку Windows з асобнымі "
            L"наладамі. Поўнаэкранны перадпрагляд дазваляе змяняць іх падчас анімацыі. OK захоўвае змены, "
            L"Скасаваць або Esc адхіляе іх. Для выхаду з застаўкі націсніце клавішу або паварушыце мышшу.\r\n"
            L"\r\nСІСТЭМНЫЯ ПАТРАБАВАННІ\r\nWindows 7–11 падтрымлівае ўсе функцыі. Для Windows Vista SP2 "
            L"неабходна ўсталяваць абнаўленні KB971512 і KB2117917. Патрэбна падтрымка Direct3D 11."
        },
    }),
    DefineLanguage(LANG_BG, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Български" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — управление" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Настройки на FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Език:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Скорост на обектите: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Скорост на камерата: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Наблюдение на пространството" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Полет през пространството" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Основна светлина" },
        LocalizedText{ TXT_FILL_LIGHT, L"Запълваща светлина" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Обемни тела" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Куб" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Правилна четириъгълна пирамида" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Пресечена четириъгълна пирамида" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Четириъгълна пирамида с наклонен срез" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT,
            L"Пирамида със срез, перпендикулярен на основата"
        },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Правилна триъгълна призма" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Правилна петоъгълна призма" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Правилна шестоъгълна призма" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Правилен октаедър" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Петоъгълна бипирамида" },
        LocalizedText{ TXT_SOLID_CONE, L"Прав кръгов конус" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Пресечен конус" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Конус с наклонен срез" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Конус със срез, перпендикулярен на основата" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Прав кръгов цилиндър" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Кух кръгов цилиндър" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Кух цилиндър с тороидални краища" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Ротационен параболоид, затворен с равнина" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Кълбо" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Полукълбо" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Кълбов отрез" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Голям кълбов отрез" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Кълбов слой" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Триосен елипсоид" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Удължен ротационен елипсоид" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Сплеснат ротационен елипсоид" },
        LocalizedText{ TXT_SOLID_EGG, L"Овоид" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Сфероцилиндър" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Заоблен диск (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Тор" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Затварянето на приложението ще спре текущия запис." },
        LocalizedText{ TXT_COPY_COUNT, L"Копия на всеки обект: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Размер на обектите: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Включване на прегледа" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Изключване на прегледа" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Анимацията е на пауза." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Блокиране на скрийнсейвъра при анимация" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Околна светлина" },
        LocalizedText{ TXT_RIM_LIGHT, L"Контурна светлина" },
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
            L"Затворете настройките на FlyingSolids и опитайте деинсталирането отново."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Затворете настройките на скрийнсейвъра на Windows и опитайте деинсталирането отново."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Спрете скрийнсейвъра или прегледа на цял екран с Esc или движение на мишката и опитайте отново."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Хардуерно ускорена анимация на обемни тела." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Версия:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Целева платформа:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Уебсайт:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Отвори в браузъра по подразбиране" },
        LocalizedText{ TXT_COPY_URL, L"Копирай &адреса" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Копирай &информацията" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Отвори уебсайта %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Сайтът не може да се отвори в браузъра по подразбиране." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"URL адресът не можа да се копира в клипборда." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Информацията не можа да се копира в клипборда." },
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
            L"АНИМАЦИЯ И НАСТРОЙКИ\r\nFlyingSolids показва обемни тела, които се движат, въртят и сблъскват. "
            L"Изберете наблюдение на пространството или полет през него и желаните тела. За всеки монитор "
            L"отделно се задават скорост на обектите и камерата 0–1600%, размер 50–200% и 1–10 копия на "
            L"всяко тяло. Основната, запълващата, околната и контурната светлина се включват независимо.\r\n"
            L"\r\nМОНИТОРИ\r\nИзберете един или повече редове в списъка с монитори. Ctrl+A избира всички; "
            L"Ctrl и Shift променят избора. Контролите и плъзгачите на анимацията променят само настройките "
            L"на избраните монитори. Избирането на ред и включването на изхода чрез отметката му са различни "
            L"действия. Изборът се запомня отделно за приложението и скрийнсейвъра. Ако са били избрани "
            L"всички монитори, включват се и новосвързаните. Различните стойности на избраните монитори се "
            L"показват с неопределено състояние на отметките и точков шаблон върху радиобутоните, дръжките "
            L"на плъзгачите и бутоните „Включване на всички“ и „Изключване на всички“. Надписите на "
            L"плъзгачите показват тире вместо обща стойност. Промяна на опция или щракване върху плъзгач "
            L"прилага стойността към всички избрани монитори.\r\n\r\nУПРАВЛЕНИЕ\r\nСтартирайте "
            L"FlyingSolids.exe. Настройките се запазват непрекъснато и работи само един екземпляр на "
            L"приложението. Отметката на монитора или двойно щракване върху реда включва или изключва "
            L"анимационния изход. Анимацията може да се поставя на пауза и да продължава. PNG и MP4 заснемат "
            L"първия активен монитор за анимация, не общ образ от всички монитори. По време на запис не може "
            L"да се изключи анимационният изход на записвания монитор; затварянето на приложението при запис "
            L"изисква потвърждение. Паузата и блокирането на скрийнсейвъра важат за цялото приложение "
            L"независимо от избора на монитори. Когато блокирането е включено, скрийнсейвърът на Windows се "
            L"предотвратява само докато на поне един монитор има видима анимация без пауза. Приложението "
            L"може да инсталира и деинсталира вградения скрийнсейвър.\r\n\r\nЕКРАННИ СНИМКИ И ЗАПИС\r\nВ "
            L"настройките за запис изберете Viewport или TV. Viewport запазва размерите и честотата на "
            L"опресняване на монитора до 60 кадъра в секунда. TV предлага 1920 × 1080, 1440 × 1080 или 1280 "
            L"× 720 със съотношение 16:9 и 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) кадъра в "
            L"секунда. TV използва прогресивно видео BT.709 с ограничен диапазон и цветова субдискретизация "
            L"4:2:0. Пропорциите се запазват, допълващите ленти са черни. OK запазва избора за следващия "
            L"запис; Отказ или Esc отхвърля непотвърдените промени. Прозорците за запис, помощ и информация "
            L"не блокират другите прозорци и могат да се минимизират. Tab и Shift+Tab преместват фокуса, "
            L"Enter активира фокусирания бутон, Esc затваря активния помощен прозорец.\r\n\r\nСИСТЕМНИ "
            L"ИЗИСКВАНИЯ\r\nWindows 7–11 поддържа всички функции. За Windows Vista SP2 трябва да се "
            L"инсталират актуализациите KB971512 и KB2117917; записът на MP4 не работи във Vista. Изисква се "
            L"поддръжка на Direct3D 11, а за MP4 също Media Foundation и H.264 кодер. Интерфейсът и "
            L"документацията са налични на 36 езика."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"АНИМАЦИЯ И НАСТРОЙКИ\r\nFlyingSolids показва обемни тела, които се движат, въртят и сблъскват. "
            L"Изберете наблюдение на пространството или полет през него и желаните тела. За всеки монитор "
            L"отделно се задават скорост на обектите и камерата 0–1600%, размер 50–200% и 1–10 копия на "
            L"всяко тяло. Основната, запълващата, околната и контурната светлина се включват независимо.\r\n"
            L"\r\nМОНИТОРИ\r\nИзберете един или повече редове в списъка с монитори. Ctrl+A избира всички; "
            L"Ctrl и Shift променят избора. Контролите и плъзгачите на анимацията променят само настройките "
            L"на избраните монитори. Избирането на ред и включването на изхода чрез отметката му са различни "
            L"действия. Изборът се запомня отделно за приложението и скрийнсейвъра. Ако са били избрани "
            L"всички монитори, включват се и новосвързаните. Различните стойности на избраните монитори се "
            L"показват с неопределено състояние на отметките и точков шаблон върху радиобутоните, дръжките "
            L"на плъзгачите и бутоните „Включване на всички“ и „Изключване на всички“. Надписите на "
            L"плъзгачите показват тире вместо обща стойност. Промяна на опция или щракване върху плъзгач "
            L"прилага стойността към всички избрани монитори.\r\n\r\nПРЕГЛЕД И УПРАВЛЕНИЕ\r\nИзползвайте "
            L"FlyingSolids.scr като скрийнсейвър на Windows с отделни настройки. Прегледът на цял екран "
            L"позволява промени в реално време. OK запазва промените; Отказ или Esc ги отхвърля. Излезте от "
            L"скрийнсейвъра с клавиш или движение на мишката.\r\n\r\nСИСТЕМНИ ИЗИСКВАНИЯ\r\nWindows 7–11 "
            L"поддържа всички функции. За Windows Vista SP2 трябва да се инсталират актуализациите KB971512 "
            L"и KB2117917. Изисква се поддръжка на Direct3D 11."
        },
    }),
    DefineLanguage(LANG_MK, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Македонски" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — контроли" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Поставки за FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Јазик:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Брзина на објектите: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Брзина на камерата: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Набљудување на просторот" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Лет низ просторот" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Главно светло" },
        LocalizedText{ TXT_FILL_LIGHT, L"Дополнително светло" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Просторни тела" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Коцка" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Правилна четириаголна пирамида" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Потсечена четириаголна пирамида" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Четириаголна пирамида со кос пресек" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Пирамида со пресек нормален на основата" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Правилна триаголна призма" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Правилна петаголна призма" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Правилна шестаголна призма" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Правилен октаедар" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Петаголна бипирамида" },
        LocalizedText{ TXT_SOLID_CONE, L"Прав кружен конус" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Потсечен конус" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Конус со кос пресек" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Конус со пресек нормален на основата" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Прав кружен цилиндар" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Шуплив кружен цилиндар" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Шуплив цилиндар со тороидни краеви" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Ротационен параболоид затворен со рамнина" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Топка" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Полутопка" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Топкин отсечок" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Голем топкин отсечок" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Топкин слој" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Триосен елипсоид" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Издолжен ротационен елипсоид" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Сплескан ротационен елипсоид" },
        LocalizedText{ TXT_SOLID_EGG, L"Овоид" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Сфероцилиндар" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Заоблен диск (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Тор" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Затворањето на апликацијата ќе го запре снимањето што е во тек."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Копии од секој објект: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Големина на објектите: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Вклучи преглед" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Исклучи преглед" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Анимацијата е паузирана." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Блокирај го чуварот за време на анимацијата" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Амбиентално светло" },
        LocalizedText{ TXT_RIM_LIGHT, L"Контурно светло" },
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
            L"Затворете ги поставките за FlyingSolids и обидете се повторно да деинсталирате."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Затворете ги поставките за чуварот на екранот на Windows и обидете се повторно."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Затворете го чуварот или прегледот на цел екран со Esc или со движење на глувчето и обидете се "
            L"повторно."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Хардверски забрзана анимација на просторни тела." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Верзија:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Целна платформа:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Веб-страница:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Отвори во стандардниот прелистувач" },
        LocalizedText{ TXT_COPY_URL, L"Копирај ја &адресата" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Копирај ги &информациите" },
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
            L"АНИМАЦИЈА И ПОСТАВКИ\r\nFlyingSolids прикажува просторни тела што се движат, вртат и судираат. "
            L"Изберете набљудување на просторот или лет низ него и саканите тела. За секој монитор одделно "
            L"се поставуваат брзината на објектите и камерата 0–1600%, големината 50–200% и 1–10 копии од "
            L"секое тело. Главното, дополнителното, амбиенталното и контурното светло се вклучуваат "
            L"независно.\r\n\r\nМОНИТОРИ\r\nИзберете еден или повеќе редови во списокот на монитори. Ctrl+A "
            L"ги избира сите; Ctrl и Shift го менуваат изборот. Контролите и лизгачите на анимацијата ги "
            L"менуваат само поставките на избраните монитори. Избирањето ред и вклучувањето на излезот преку "
            L"неговото поле се различни дејства. Изборот се памети одделно за апликацијата и чуварот. Ако "
            L"биле избрани сите монитори, се вклучуваат и новоповрзаните монитори. Различните вредности на "
            L"избраните монитори се прикажуваат со неопределена состојба на полињата за избор и точкест "
            L"образец на радио-копчињата, рачките на лизгачите и копчињата „Вклучи ги сите“ и „Исклучи ги "
            L"сите“. Ознаките на лизгачите прикажуваат црта наместо заедничка вредност. Менувањето опција "
            L"или кликнувањето на лизгач ја применува вредноста на сите избрани монитори.\r\n\r\nУПРАВУВАЊЕ\r"
            L"\nСтартувајте FlyingSolids.exe. Поставките се зачувуваат постојано и работи само еден примерок "
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
            L"АНИМАЦИЈА И ПОСТАВКИ\r\nFlyingSolids прикажува просторни тела што се движат, вртат и судираат. "
            L"Изберете набљудување на просторот или лет низ него и саканите тела. За секој монитор одделно "
            L"се поставуваат брзината на објектите и камерата 0–1600%, големината 50–200% и 1–10 копии од "
            L"секое тело. Главното, дополнителното, амбиенталното и контурното светло се вклучуваат "
            L"независно.\r\n\r\nМОНИТОРИ\r\nИзберете еден или повеќе редови во списокот на монитори. Ctrl+A "
            L"ги избира сите; Ctrl и Shift го менуваат изборот. Контролите и лизгачите на анимацијата ги "
            L"менуваат само поставките на избраните монитори. Избирањето ред и вклучувањето на излезот преку "
            L"неговото поле се различни дејства. Изборот се памети одделно за апликацијата и чуварот. Ако "
            L"биле избрани сите монитори, се вклучуваат и новоповрзаните монитори. Различните вредности на "
            L"избраните монитори се прикажуваат со неопределена состојба на полињата за избор и точкест "
            L"образец на радио-копчињата, рачките на лизгачите и копчињата „Вклучи ги сите“ и „Исклучи ги "
            L"сите“. Ознаките на лизгачите прикажуваат црта наместо заедничка вредност. Менувањето опција "
            L"или кликнувањето на лизгач ја применува вредноста на сите избрани монитори.\r\n\r\nПРЕГЛЕД И "
            L"УПРАВУВАЊЕ\r\nКористете FlyingSolids.scr како Windows чувар на екранот со одделни поставки. "
            L"Прегледот на цел екран овозможува измени во живо. OK ги зачувува, а Откажи или Esc ги отфрла "
            L"измените. Излезете од чуварот со копче или движење на глувчето.\r\n\r\nСИСТЕМСКИ БАРАЊА\r\n"
            L"Windows 7–11 ги поддржува сите функции. За Windows Vista SP2 мора да се инсталираат "
            L"ажурирањата KB971512 и KB2117917. Потребна е поддршка за Direct3D 11."
        },
    }),
    DefineLanguage(LANG_SR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Српски" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — контроле" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Подешавања програма FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Језик:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Брзина објеката: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Брзина камере: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Посматрање простора" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Лет кроз простор" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Главно светло" },
        LocalizedText{ TXT_FILL_LIGHT, L"Допунско светло" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Просторна тела" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Коцка" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Правилна четворострана пирамида" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Зарубљена четворострана пирамида" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Четворострана пирамида с косим пресеком" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT, L"Пирамида с пресеком нормалним на основу" },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Правилна тространа призма" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Правилна петострана призма" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Правилна шестострана призма" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Правилни октаедар" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Петострана бипирамида" },
        LocalizedText{ TXT_SOLID_CONE, L"Права кружна купа" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Зарубљена купа" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Купа с косим пресеком" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Купа с пресеком нормалним на основу" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Прави кружни ваљак" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Шупљи кружни ваљак" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Шупљи ваљак с торусним крајевима" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Ротациони параболоид затворен равни" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Лопта" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Полулопта" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Лоптин одсечак" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Велики лоптин одсечак" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Лоптин слој" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Троосни елипсоид" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Издужени ротациони елипсоид" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Спљоштени ротациони елипсоид" },
        LocalizedText{ TXT_SOLID_EGG, L"Овоид" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Сфероцилиндар" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Заобљени диск (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Торус" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Затварање апликације зауставиће снимање које је у току."
        },
        LocalizedText{ TXT_COPY_COUNT, L"Копије сваког објекта: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Величина објеката: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Укључи преглед" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Искључи преглед" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Анимација је паузирана." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Спречи чувар екрана током анимације" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Амбијентално светло" },
        LocalizedText{ TXT_RIM_LIGHT, L"Контурно светло" },
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
            L"Затворите подешавања програма FlyingSolids па поновите деинсталацију."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Затворите Windows подешавања чувара екрана па поновите деинсталацију."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Затворите чувар или преглед преко целог екрана тастером Esc или померањем миша па поновите "
            L"деинсталацију."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Хардверски убрзана анимација просторних тела." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Верзија:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Циљна платформа:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Веб-сајт:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Отвори у подразумеваном прегледачу" },
        LocalizedText{ TXT_COPY_URL, L"Копирај &адресу" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Копирај &податке" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Отвори веб-сајт %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Није могуће отворити страницу у подразумеваном прегледачу."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Није могуће копирати URL у оставу." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED, L"Није могуће копирати податке у оставу." },
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
            L"АНИМАЦИЈА И ПОДЕШАВАЊА\r\nFlyingSolids приказује просторна тела која се крећу, окрећу и "
            L"сударају. Изаберите посматрање простора или лет кроз простор и жељена тела. За сваки монитор "
            L"посебно се подешавају брзина објеката и камере 0–1600%, величина 50–200% и 1–10 копија сваког "
            L"тела. Главно, допунско, амбијентално и контурно светло укључују се независно.\r\n\r\nМОНИТОРИ\r"
            L"\nИзаберите један или више редова у листи монитора. Ctrl+A бира све; Ctrl и Shift мењају "
            L"избор. Контроле и клизачи анимације мењају само подешавања изабраних монитора. Избор реда није "
            L"исто што и укључивање излаза његовим пољем за потврду. Избор се памти одвојено за апликацију и "
            L"чувар екрана. Ако су претходно били изабрани сви монитори, укључују се и новоприкључени "
            L"монитори. Различите вредности на изабраним мониторима приказују се неодређеним стањем поља за "
            L"потврду и тачкастим узорком на дугмадима избора, ручкама клизача и дугмадима „Укључи све“ и "
            L"„Искључи све“. Ознаке клизача приказују црту уместо заједничке вредности. Промена опције или "
            L"клик на клизач примењује ту вредност на све изабране мониторе.\r\n\r\nУПРАВЉАЊЕ\r\nПокрените "
            L"FlyingSolids.exe. Подешавања се стално чувају и ради само једна инстанца апликације. Поље "
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
            L"АНИМАЦИЈА И ПОДЕШАВАЊА\r\nFlyingSolids приказује просторна тела која се крећу, окрећу и "
            L"сударају. Изаберите посматрање простора или лет кроз простор и жељена тела. За сваки монитор "
            L"посебно се подешавају брзина објеката и камере 0–1600%, величина 50–200% и 1–10 копија сваког "
            L"тела. Главно, допунско, амбијентално и контурно светло укључују се независно.\r\n\r\nМОНИТОРИ\r"
            L"\nИзаберите један или више редова у листи монитора. Ctrl+A бира све; Ctrl и Shift мењају "
            L"избор. Контроле и клизачи анимације мењају само подешавања изабраних монитора. Избор реда није "
            L"исто што и укључивање излаза његовим пољем за потврду. Избор се памти одвојено за апликацију и "
            L"чувар екрана. Ако су претходно били изабрани сви монитори, укључују се и новоприкључени "
            L"монитори. Различите вредности на изабраним мониторима приказују се неодређеним стањем поља за "
            L"потврду и тачкастим узорком на дугмадима избора, ручкама клизача и дугмадима „Укључи све“ и "
            L"„Искључи све“. Ознаке клизача приказују црту уместо заједничке вредности. Промена опције или "
            L"клик на клизач примењује ту вредност на све изабране мониторе.\r\n\r\nПРЕГЛЕД И УПРАВЉАЊЕ\r\n"
            L"Користите FlyingSolids.scr као Windows чувар екрана са одвојеним подешавањима. Преглед преко "
            L"целог екрана омогућава измене уживо. OK чува, а Откажи или Esc одбацује измене. Из чувара "
            L"изађите притиском тастера или померањем миша.\r\n\r\nСИСТЕМСКИ ЗАХТЕВИ\r\nWindows 7–11 "
            L"подржава све функције. За Windows Vista SP2 морате инсталирати ажурирања KB971512 и KB2117917. "
            L"Потребан је Direct3D 11."
        },
    }),
    DefineLanguage(LANG_UK, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Українська" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — керування" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Налаштування FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Мова:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Швидкість об’єктів: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Швидкість камери: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Спостереження за простором" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Політ крізь простір" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Основне світло" },
        LocalizedText{ TXT_FILL_LIGHT, L"Заповнювальне світло" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Об’ємні тіла" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Куб" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Правильна чотирикутна піраміда" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Зрізана чотирикутна піраміда" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Чотирикутна піраміда з похилим зрізом" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT,
            L"Піраміда зі зрізом, перпендикулярним основі"
        },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Правильна трикутна призма" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Правильна п’ятикутна призма" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Правильна шестикутна призма" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Правильний октаедр" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"П’ятикутна біпіраміда" },
        LocalizedText{ TXT_SOLID_CONE, L"Прямий круговий конус" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Зрізаний конус" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Конус із похилим зрізом" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Конус зі зрізом, перпендикулярним основі" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Прямий круговий циліндр" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Порожнистий круговий циліндр" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Порожнистий циліндр із тороїдними торцями" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Параболоїд обертання, замкнений площиною" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Куля" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Півкуля" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Кульовий сегмент" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Великий кульовий сегмент" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Кульовий шар" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Тривісний еліпсоїд" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Витягнутий еліпсоїд обертання" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Сплюснутий еліпсоїд обертання" },
        LocalizedText{ TXT_SOLID_EGG, L"Овоїд" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Сфероциліндр" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Заокруглений диск (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Тор" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Закриття програми зупинить поточний запис." },
        LocalizedText{ TXT_COPY_COUNT, L"Копій кожного об’єкта: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Розмір об’єктів: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Увімкнути попередній перегляд" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Вимкнути попередній перегляд" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Анімацію призупинено." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Блокувати заставку під час анімації" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Фонове світло" },
        LocalizedText{ TXT_RIM_LIGHT, L"Контурне світло" },
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
            L"Закрийте налаштування FlyingSolids та повторіть видалення."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Закрийте налаштування заставки Windows та повторіть видалення."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Завершіть заставку або повноекранний попередній перегляд клавішею Esc чи рухом миші та "
            L"повторіть видалення."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Апаратно прискорена анімація об’ємних тіл." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Версія:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Цільова платформа:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Вебсайт:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Відкрити в типовому браузері" },
        LocalizedText{ TXT_COPY_URL, L"Копіювати &адресу" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Копіювати &відомості" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Відкрити вебсайт %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Не вдається відкрити сайт у типовому браузері." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Не вдалося скопіювати URL у буфер обміну." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Не вдалося скопіювати відомості в буфер обміну."
        },
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
            L"АНІМАЦІЯ ТА НАЛАШТУВАННЯ\r\nFlyingSolids показує об’ємні тіла, які рухаються, обертаються й "
            L"стикаються. Виберіть спостереження за простором або політ крізь нього та потрібні тіла. Для "
            L"кожного монітора окремо задаються швидкості об’єктів і камери 0–1600%, розмір 50–200% та 1–10 "
            L"копій кожного тіла. Основне, заповнювальне, фонове й контурне світло вмикаються незалежно.\r\n"
            L"\r\nМОНІТОРИ\r\nВиберіть один або кілька рядків у списку моніторів. Ctrl+A вибирає всі; Ctrl і "
            L"Shift змінюють вибір. Елементи керування й повзунки анімації змінюють лише налаштування "
            L"вибраних моніторів. Вибір рядка та ввімкнення виведення його прапорцем — різні дії. Вибір "
            L"зберігається окремо для програми й заставки. Якщо раніше були вибрані всі монітори, до вибору "
            L"долучаються й новопідключені. Різні значення на вибраних моніторах позначаються невизначеним "
            L"станом прапорців і крапковим візерунком на перемикачах, ручках повзунків і кнопках «Увімкнути "
            L"все» і «Вимкнути все». Підписи повзунків показують тире замість спільного значення. Зміна "
            L"параметра або натискання на повзунок застосовує це значення до всіх вибраних моніторів.\r\n\r\n"
            L"КЕРУВАННЯ\r\nЗапустіть FlyingSolids.exe. Налаштування зберігаються постійно, працює лише один "
            L"екземпляр програми. Прапорець монітора або подвійне клацання рядка вмикає чи вимикає виведення "
            L"анімації. Анімацію можна призупинити та продовжити. PNG і MP4 захоплюють перший активний "
            L"монітор анімації, а не спільне зображення всіх моніторів. Під час запису не можна вимкнути "
            L"виведення анімації монітора, який записується; закриття програми під час запису потребує "
            L"підтвердження. Призупинення та блокування заставки діють для всієї програми незалежно від "
            L"вибору моніторів. Якщо блокування ввімкнено, заставка Windows не запускається лише доки "
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
            L"АНІМАЦІЯ ТА НАЛАШТУВАННЯ\r\nFlyingSolids показує об’ємні тіла, які рухаються, обертаються й "
            L"стикаються. Виберіть спостереження за простором або політ крізь нього та потрібні тіла. Для "
            L"кожного монітора окремо задаються швидкості об’єктів і камери 0–1600%, розмір 50–200% та 1–10 "
            L"копій кожного тіла. Основне, заповнювальне, фонове й контурне світло вмикаються незалежно.\r\n"
            L"\r\nМОНІТОРИ\r\nВиберіть один або кілька рядків у списку моніторів. Ctrl+A вибирає всі; Ctrl і "
            L"Shift змінюють вибір. Елементи керування й повзунки анімації змінюють лише налаштування "
            L"вибраних моніторів. Вибір рядка та ввімкнення виведення його прапорцем — різні дії. Вибір "
            L"зберігається окремо для програми й заставки. Якщо раніше були вибрані всі монітори, до вибору "
            L"долучаються й новопідключені. Різні значення на вибраних моніторах позначаються невизначеним "
            L"станом прапорців і крапковим візерунком на перемикачах, ручках повзунків і кнопках «Увімкнути "
            L"все» і «Вимкнути все». Підписи повзунків показують тире замість спільного значення. Зміна "
            L"параметра або натискання на повзунок застосовує це значення до всіх вибраних моніторів.\r\n\r\n"
            L"ПОПЕРЕДНІЙ ПЕРЕГЛЯД І КЕРУВАННЯ\r\nВикористовуйте FlyingSolids.scr як заставку Windows з "
            L"окремими налаштуваннями. Повноекранний попередній перегляд дозволяє змінювати їх під час "
            L"анімації. OK зберігає зміни, Скасувати або Esc відхиляє їх. Для виходу із заставки натисніть "
            L"клавішу або порухайте мишею.\r\n\r\nСИСТЕМНІ ВИМОГИ\r\nWindows 7–11 підтримує всі функції. Для "
            L"Windows Vista SP2 потрібно встановити оновлення KB971512 і KB2117917. Потрібна підтримка "
            L"Direct3D 11."
        },
    }),
    DefineLanguage(LANG_RU, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_LANGUAGE_NAME, L"Русский" },
        LocalizedText{ TXT_CONTROL_TITLE, L"FlyingSolids — управление" },
        LocalizedText{ TXT_SETTINGS_TITLE, L"Настройки FlyingSolids" },
        LocalizedText{ TXT_LANGUAGE, L"Язык:" },
        LocalizedText{ TXT_OBJECT_SPEED, L"Скорость объектов: %d %%" },
        LocalizedText{ TXT_CAMERA_SPEED, L"Скорость камеры: %d %%" },
        LocalizedText{ TXT_OBSERVE_SPACE, L"Наблюдение за пространством" },
        LocalizedText{ TXT_FLY_THROUGH_SPACE, L"Полёт сквозь пространство" },
        LocalizedText{ TXT_MAIN_LIGHT, L"Основной свет" },
        LocalizedText{ TXT_FILL_LIGHT, L"Заполняющий свет" },
        LocalizedText{ TXT_SOLID_OBJECTS, L"Объёмные тела" },
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
        LocalizedText{ TXT_SOLID_CUBE, L"Куб" },
        LocalizedText{ TXT_SOLID_PYRAMID, L"Правильная четырёхугольная пирамида" },
        LocalizedText{ TXT_SOLID_PYRAMIDAL_FRUSTUM, L"Усечённая четырёхугольная пирамида" },
        LocalizedText{ TXT_SOLID_OBLIQUE_PYRAMIDAL_CUT, L"Четырёхугольная пирамида с косым срезом" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_PYRAMIDAL_CUT,
            L"Пирамида со срезом, перпендикулярным основанию"
        },
        LocalizedText{ TXT_SOLID_TRIANGULAR_PRISM, L"Правильная треугольная призма" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_PRISM, L"Правильная пятиугольная призма" },
        LocalizedText{ TXT_SOLID_HEXAGONAL_PRISM, L"Правильная шестиугольная призма" },
        LocalizedText{ TXT_SOLID_OCTAHEDRON, L"Правильный октаэдр" },
        LocalizedText{ TXT_SOLID_PENTAGONAL_BIPYRAMID, L"Пятиугольная бипирамида" },
        LocalizedText{ TXT_SOLID_CONE, L"Прямой круговой конус" },
        LocalizedText{ TXT_SOLID_CONICAL_FRUSTUM, L"Усечённый конус" },
        LocalizedText{ TXT_SOLID_OBLIQUE_CONICAL_CUT, L"Конус с косым срезом" },
        LocalizedText{ TXT_SOLID_PERPENDICULAR_CONICAL_CUT, L"Конус со срезом, перпендикулярным основанию" },
        LocalizedText{ TXT_SOLID_CYLINDER, L"Прямой круговой цилиндр" },
        LocalizedText{ TXT_SOLID_HOLLOW_CYLINDER, L"Полый круговой цилиндр" },
        LocalizedText{ TXT_SOLID_ROUNDED_HOLLOW_CYLINDER, L"Полый цилиндр с тороидальными торцами" },
        LocalizedText{ TXT_SOLID_PARABOLOID, L"Параболоид вращения, замкнутый плоскостью" },
        LocalizedText{ TXT_SOLID_SPHERE, L"Шар" },
        LocalizedText{ TXT_SOLID_HEMISPHERE, L"Полушар" },
        LocalizedText{ TXT_SOLID_SPHERICAL_CAP, L"Шаровой сегмент" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_ONE_CAP, L"Большой шаровой сегмент" },
        LocalizedText{ TXT_SOLID_SPHERE_WITHOUT_CAPS, L"Шаровой слой" },
        LocalizedText{ TXT_SOLID_ELLIPSOID, L"Трёхосный эллипсоид" },
        LocalizedText{ TXT_SOLID_PROLATE_ELLIPSOID, L"Вытянутый эллипсоид вращения" },
        LocalizedText{ TXT_SOLID_OBLATE_ELLIPSOID, L"Сплюснутый эллипсоид вращения" },
        LocalizedText{ TXT_SOLID_EGG, L"Овоид" },
        LocalizedText{ TXT_SOLID_CAPSULE, L"Сфероцилиндр" },
        LocalizedText{ TXT_SOLID_SPHEROPLATELET, L"Скруглённый диск (spheroplatelet)" },
        LocalizedText{ TXT_SOLID_TORUS, L"Тор" },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING, L"Закрытие приложения остановит текущую запись." },
        LocalizedText{ TXT_COPY_COUNT, L"Копий каждого объекта: %d" },
        LocalizedText{ TXT_OBJECT_SIZE, L"Размер объектов: %d %%" },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Включить предпросмотр" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Выключить предпросмотр" },
        LocalizedText{ TXT_PAUSED_STATUS, L"Анимация приостановлена." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Блокировать заставку во время анимации" },
        LocalizedText{ TXT_AMBIENT_LIGHT, L"Фоновый свет" },
        LocalizedText{ TXT_RIM_LIGHT, L"Контурный свет" },
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
            L"Закройте настройки FlyingSolids и повторите удаление."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Закройте настройки заставки Windows и повторите удаление."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Завершите заставку или полноэкранный предпросмотр клавишей Esc либо движением мыши и повторите "
            L"удаление."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION, L"Аппаратно ускоренная анимация объёмных тел." },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL, L"Версия:" },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL, L"Целевая платформа:" },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL, L"Веб-сайт:" },
        LocalizedText{ TXT_OPEN_IN_BROWSER, L"&Открыть в браузере по умолчанию" },
        LocalizedText{ TXT_COPY_URL, L"Копировать &адрес" },
        LocalizedText{ TXT_COPY_INFORMATION, L"Копировать &сведения" },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP, L"Открыть веб-сайт %ls" },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED, L"Не удаётся открыть сайт в браузере по умолчанию." },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED, L"Не удалось скопировать URL в буфер обмена." },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Не удалось скопировать сведения в буфер обмена."
        },
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
            L"АНИМАЦИЯ И НАСТРОЙКИ\r\nFlyingSolids показывает объёмные тела, которые движутся, вращаются и "
            L"сталкиваются. Выберите наблюдение за пространством или полёт сквозь него и нужные тела. Для "
            L"каждого монитора отдельно задаются скорости объектов и камеры 0–1600%, размер 50–200% и 1–10 "
            L"копий каждого тела. Основной, заполняющий, фоновый и контурный свет включаются независимо.\r\n"
            L"\r\nМОНИТОРЫ\r\nВыберите одну или несколько строк в списке мониторов. Ctrl+A выбирает все; "
            L"Ctrl и Shift изменяют выбор. Элементы управления и ползунки анимации изменяют только настройки "
            L"выбранных мониторов. Выбор строки и включение вывода её флажком — разные действия. Выбор "
            L"сохраняется отдельно для приложения и заставки. Если раньше были выбраны все мониторы, в выбор "
            L"включаются и вновь подключённые. Разные значения на выбранных мониторах обозначаются "
            L"неопределённым состоянием флажков и точечным узором на переключателях, ручках ползунков и "
            L"кнопках «Включить всё» и «Выключить всё». Подписи ползунков показывают тире вместо общего "
            L"значения. Изменение параметра или нажатие на ползунок применяет это значение ко всем выбранным "
            L"мониторам.\r\n\r\nУПРАВЛЕНИЕ\r\nЗапустите FlyingSolids.exe. Настройки сохраняются постоянно, "
            L"работает только один экземпляр приложения. Флажок монитора или двойной щелчок по строке "
            L"включает либо выключает вывод анимации. Анимацию можно приостановить и продолжить. PNG и MP4 "
            L"захватывают первый активный монитор анимации, а не общее изображение всех мониторов. Во время "
            L"записи нельзя отключить вывод анимации записываемого монитора; закрытие приложения во время "
            L"записи требует подтверждения. Пауза и блокировка заставки действуют для всего приложения "
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
            L"АНИМАЦИЯ И НАСТРОЙКИ\r\nFlyingSolids показывает объёмные тела, которые движутся, вращаются и "
            L"сталкиваются. Выберите наблюдение за пространством или полёт сквозь него и нужные тела. Для "
            L"каждого монитора отдельно задаются скорости объектов и камеры 0–1600%, размер 50–200% и 1–10 "
            L"копий каждого тела. Основной, заполняющий, фоновый и контурный свет включаются независимо.\r\n"
            L"\r\nМОНИТОРЫ\r\nВыберите одну или несколько строк в списке мониторов. Ctrl+A выбирает все; "
            L"Ctrl и Shift изменяют выбор. Элементы управления и ползунки анимации изменяют только настройки "
            L"выбранных мониторов. Выбор строки и включение вывода её флажком — разные действия. Выбор "
            L"сохраняется отдельно для приложения и заставки. Если раньше были выбраны все мониторы, в выбор "
            L"включаются и вновь подключённые. Разные значения на выбранных мониторах обозначаются "
            L"неопределённым состоянием флажков и точечным узором на переключателях, ручках ползунков и "
            L"кнопках «Включить всё» и «Выключить всё». Подписи ползунков показывают тире вместо общего "
            L"значения. Изменение параметра или нажатие на ползунок применяет это значение ко всем выбранным "
            L"мониторам.\r\n\r\nПРЕДПРОСМОТР И УПРАВЛЕНИЕ\r\nИспользуйте FlyingSolids.scr как заставку "
            L"Windows с отдельными настройками. Полноэкранный предпросмотр позволяет изменять их во время "
            L"анимации. OK сохраняет изменения, Отмена или Esc отклоняет их. Для выхода из заставки нажмите "
            L"клавишу или подвигайте мышью.\r\n\r\nСИСТЕМНЫЕ ТРЕБОВАНИЯ\r\nWindows 7–11 поддерживает все "
            L"функции. Для Windows Vista SP2 необходимо установить обновления KB971512 и KB2117917. Нужна "
            L"поддержка Direct3D 11."
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
