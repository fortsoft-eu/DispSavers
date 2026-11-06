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
 * Last modified for version 1.3.1.0
 */

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "Localization.h"
#include <windows.h>
#include <array>
#include <initializer_list>

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

/// Builds one language at compile time and rejects missing, duplicate, empty, or invalid text entries.
static consteval LocalizedLanguage DefineLanguage(AppLanguage language,
        std::initializer_list<LocalizedText> entries) {
    if (entries.size() != TXT_COUNT) {
        throw "Every language must define every TextId exactly once.";
    }
    LocalizedLanguage result = { language, {} };
    for (const LocalizedText& entry : entries) {
        int id = static_cast<int>(entry.id);
        if (id < 0 || id >= TXT_COUNT) {
            throw "Invalid translation TextId.";
        }
        if (entry.text == nullptr || entry.text[0] == L'\0') {
            throw "A translation cannot be null or empty.";
        }
        if (result.texts[id] != nullptr) {
            throw "Duplicate translation TextId.";
        }
        result.texts[id] = entry.text;
    }
    return result;
}

/// Indexes complete languages by AppLanguage at compile time, independently of their source order.
/// Rejects missing, duplicate, or invalid language identifiers before any executable can be produced.
static consteval std::array<LocalizedLanguage, LANG_COUNT> DefineLocalization(
        std::initializer_list<LocalizedLanguage> languages) {
    if (languages.size() != LANG_COUNT) {
        throw "Every AppLanguage must have a complete translation table.";
    }
    std::array<LocalizedLanguage, LANG_COUNT> result = {};
    std::array<bool, LANG_COUNT> included = {};
    for (const LocalizedLanguage& language : languages) {
        int id = static_cast<int>(language.id);
        if (id < 0 || id >= LANG_COUNT) {
            throw "Invalid localization AppLanguage.";
        }
        if (included[id]) {
            throw "Duplicate localization AppLanguage.";
        }
        for (const wchar_t* text : language.texts) {
            if (text == nullptr || text[0] == L'\0') {
                throw "Every language must contain a nonempty translation for every TextId.";
            }
        }
        result[id] = language;
        included[id] = true;
    }
    return result;
}

constexpr std::initializer_list<LocalizedLanguage> languageDefinitions{
    DefineLanguage(LANG_CS, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Náhodná barva pozadí při každém restartu scény" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Náhodná barva mřížky při každém restartu scény" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Spořič Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Nastavení spořiče obrazovky ve Windows nelze otevřít."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Reset hodnot" },
        LocalizedText{ TXT_SNAPSHOT, L"Snímek…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Snímek byl uložen." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Snímek se nepodařilo uložit." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blokovat spořič při animaci" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Náhodná barva živých buněk při každém restartu scény"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Probíhá instalace spořiče…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Probíhá odinstalace spořiče…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Nainstalovat spořič" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Odinstalovat spořič" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Instalace spořiče nebyla provedena." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Spořič byl nainstalován." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Spořič byl odinstalován." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Odinstalace se nezdařila. Pokud je spořič nebo jeho náhled spuštěný, zavřete jej a odinstalaci "
            L"zopakujte."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Odinstalace se nezdařila, protože je otevřené nastavení GameOfLife. Zavřete je a odinstalaci "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Čeština"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — ovládání"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Nastavení GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Jazyk:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Storno"
        },
        LocalizedText{ TXT_EXIT,
            L"Konec"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pozastavit"
        },
        LocalizedText{ TXT_RESUME,
            L"Pokračovat"
        },
        LocalizedText{ TXT_HELP,
            L"Nápověda"
        },
        LocalizedText{ TXT_ABOUT,
            L"O programu"
        },
        LocalizedText{ TXT_CLOSE,
            L"Zavřít"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Navštívit web %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Web nelze otevřít ve výchozím prohlížeči."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Adresu URL nelze zkopírovat do schránky."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Informace nelze zkopírovat do schránky."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conwayova hra života na jedné společné ploše monitorů."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Verze:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Cílová platforma:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Web:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Otevřít ve výchozím prohlížeči"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Kopírovat &adresu"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Kopírovat &informace"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Prostředek s licencí není k dispozici."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nPRAVIDLA\r\nConwayova hra života používá pravidla B3/S23. Mrtvá buňka "
            L"ožije při právě třech živých sousedech; živá přežije se dvěma nebo třemi. Osm sousedů "
            L"zahrnuje i úhlopříčky. Všechny buňky se mění současně. Protilehlé okraje navazují: levý na "
            L"pravý a horní na dolní.\r\n\r\nMONITORY A SPOLEČNÁ PLOCHA\r\nZatržítka v EXE zapínají "
            L"monitory; nastavení platí pro společnou hru. Jediný zapnutý monitor obsahuje celou plochu. "
            L"Při zapnutí části sestavy se úplně prázdné řady a sloupce odstraní: levý a pravý monitor po "
            L"vypnutí prostředního navážou. Neodstranitelné vnitřní díry zůstávají součástí simulace. "
            L"Zapnutí všech monitorů a režim SCR zachovávají obdélník celé sestavy včetně neviditelných "
            L"mezer. Každý monitor zobrazuje vlastní výřez téže hry.\r\n\r\nPOČÁTEČNÍ STAV A "
            L"OBRAZCE\r\nVýchozí začátek je náhodný šum s 25 % živých buněk. Počáteční hustota 0–100 % se "
            L"použije při příštím restartu. Pouze známé obrazce používá 4 106 přiložených obrazců bez šumu "
            L"a vypne hustotu. Zvolte směs nebo pojmenovaný obrazec; rozměry jsou v buňkách. Psaním názvu "
            L"hledejte v seznamu. Nabízejí se jen obrazce, které se celé vejdou. Malé ověřené obrazce se "
            L"opakují v oddělených kopiích, velké a složité začínají jednou uprostřed. Zmenšení plochy "
            L"může nevyhovující výběr nahradit směsí. Změna režimu nebo obrazce vytvoří novou scénu. "
            L"Restarty výběr zachovají; katalog funguje bez internetu.\r\n\r\nVELIKOST BUNĚK, MŘÍŽKA A "
            L"BARVY\r\nBez mřížky je velikost buňky 1–64 px. Zobrazit mřížku přidá okraj 1 px uvnitř "
            L"stávající rozteče: zobrazená velikost a jezdec se sníží o jednu, použitelné hodnoty jsou "
            L"1–63. Vypnutí hodnotu vrátí. Jezdec zachová celý rozsah a z nedostupného konce se vrátí; "
            L"zatržítko zůstává dostupné. Přepínání zachová scénu kromě zapnutí při 1 px, kdy se rozteč "
            L"zvýší na 2 px a vznikne nová scéna. Také změna velikosti nebo monitorů začne znovu. U "
            L"mimořádně velké plochy může být minimum vyšší. Barvy živých buněk, pozadí a mřížky lze "
            L"nezávisle měnit bez restartu. Náhodná barva živých buněk vybírá novou barvu při každém "
            L"ručním i automatickém restartu scény. Uložená barva se nepřepisuje; vypnutí této volby ji "
            L"obnoví. Stejné chování lze samostatně zapnout pro pozadí a mřížku; obě nové volby jsou "
            L"zpočátku vypnuté.\r\n\r\nRYCHLOST, POZASTAVENÍ A AUTOMATICKÝ RESTART\r\nRychlost je 0–240 "
            L"generací/s nezávisle na obnovování monitoru; 0 zastaví vývoj. Pozastavit a Pokračovat "
            L"zachovávají plochu. Restart vytvoří nový začátek ve zvoleném režimu. Volitelný automatický "
            L"restart rozpoznává statické i přesně se opakující zobrazené fáze včetně oscilátorů. "
            L"Porovnává generace simulace, nikoli uplynulé sekundy; nezobrazené oblasti vynechává. "
            L"Výsledky se čtou asynchronně, proto může restart přijít o něco později. Výchozí rozteč je 8 "
            L"px, rychlost 20 generací/s, náhodná barva živých buněk a automatický restart jsou zapnuté. "
            L"Mřížka je ve výchozím stavu vypnutá. Dosažená rychlost závisí na výkonu a počtu buněk. "
            L"Automatický restart posuzuje oblasti zapnutých monitorů; mezery mezi nimi se mohou dále "
            L"vyvíjet, ale do porovnání se nezahrnují.\r\n\r\nReset hodnot\r\nReset obnoví velikost buňky "
            L"8 px s mřížkou i bez ní (rozteč 9 nebo 8 px), rychlost 20 generací/s, hustotu 25 % a tři "
            L"výchozí barvy. Ostatní volby zachová; obrazec, který se nevejde, nahradí směsí. Nová scéna "
            L"vznikne jen při změně rozteče nebo hustoty v režimu šumu.\r\n\r\nSAMOSTATNÁ APLIKACE A "
            L"ZÁZNAM MP4\r\nEXE ukládá nastavení průběžně a nahrává první aktivní monitor do MP4, nikoli "
            L"celou společnou plochu. Nabízí složku Videa, případně Dokumenty. Viewport použije rozměry a "
            L"obnovovací frekvenci monitoru do 60 snímků/s. TV nabízí 1920 × 1080, 1440 × 1080 nebo 1280 × "
            L"720 v poměru 16:9 při 50, 25, 59,94 (60000/1001) nebo 29,97 (30000/1001) snímcích/s. Poměr "
            L"stran se zachovává; TV používá progresivní BT.709 s omezeným rozsahem a vzorkováním 4:2:0. "
            L"Samostatné Nastavení záznamu lze minimalizovat. OK uloží volby pro další záznam, Storno nebo "
            L"Esc nepotvrzené změny zahodí. Nahrávaný monitor nelze vypnout; ostatní výstupy lze měnit. "
            L"Ukončení při záznamu vyžaduje potvrzení. Má-li fokus animace, mezerník pozastaví či obnoví "
            L"vývoj, F9: Spustit záznam; F10: Ukončit záznam. Kurzor se po 1 sekundě nečinnosti skryje a "
            L"pohybem se objeví. Tab/Shift+Tab přechází mezi prvky, Alt vyvolá podtržené volby. Esc zavře "
            L"nápovědu či O programu, v hlavním okně aplikaci ukončí.\r\n\r\nSNÍMEK A SPRÁVA SPOŘIČE V "
            L"EXE\r\nSnímek uloží BMP/GIF/JPEG/PNG/TIFF/WebP aktuálně nahrávaného monitoru, jinak prvního "
            L"aktivního, v jeho "
            L"rozlišení; scénu nerestartuje. Nabízí složku Obrázky, případně Dokumenty. Blokovat spořič "
            L"při animaci brání spuštění spořiče Windows při viditelné, nepozastavené animaci. Nulová "
            L"rychlost není pozastavení. Instalace z EXE rozbalí přiložený SCR a vybere jej jako spořič "
            L"Windows. Instalace i odinstalace mohou vyžadovat souhlas správce; stavový řádek ukazuje "
            L"průběh až do dokončení. Při blokované odinstalaci zavřete běžící spořič, jeho nastavení a "
            L"náhled Windows.\r\n\r\nSPOŘIČ OBRAZOVKY WINDOWS\r\nGameOfLife.scr používá všechny monitory a "
            L"ukládá nastavení odděleně od EXE. Zapnout náhled spustí celoobrazovkovou animaci při "
            L"otevřeném nastavení. Malý náhled Windows zmenší celou společnou plochu. OK nastavení uloží, "
            L"Storno nebo Esc změny zahodí. Pohyb myši nebo klávesa ukončí celoobrazovkový spořič. Záznam "
            L"MP4 je dostupný v EXE.\r\n\r\nPOLOHA A STAV OKEN\r\nPři zavření se samostatně ukládá poloha "
            L"hlavního okna a okna O programu; u nápovědy také velikost a normální či maximalizovaný stav "
            L"před případnou minimalizací. To nezávisí na potvrzení nastavení aplikace. Ukončení aplikace "
            L"zavře také nápovědu a O programu.\r\n\r\nVYKRESLOVÁNÍ A LICENCE OBRAZCŮ\r\nVývoj a "
            L"porovnávání zobrazených stavů provádějí shadery Direct3D 11 na GPU; při selhání hardwarové "
            L"inicializace je dostupné softwarové vykreslování. Každý monitor používá převzatý framepacer "
            L"podle vlastní obnovovací frekvence. MP4 vyžaduje Media Foundation a kodér H.264. Obrazce "
            L"pocházejí z LifeWiki (GFDL 1.2 nebo novější) a volně šiřitelných sbírek Alana Hensela v "
            L"režimu public domain. Kód programu má licenci MIT; oznámení a licence katalogu jsou "
            L"samostatné.\r\n\r\nTlačítko Spořič Windows… otevře systémové nastavení spořiče obrazovky."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nPRAVIDLA\r\nConwayova hra života používá pravidla B3/S23. Mrtvá buňka "
            L"ožije při právě třech živých sousedech; živá přežije se dvěma nebo třemi. Osm sousedů "
            L"zahrnuje i úhlopříčky. Všechny buňky se mění současně. Protilehlé okraje navazují: levý na "
            L"pravý a horní na dolní.\r\n\r\nMONITORY A SPOLEČNÁ PLOCHA\r\nZatržítka v EXE zapínají "
            L"monitory; nastavení platí pro společnou hru. Jediný zapnutý monitor obsahuje celou plochu. "
            L"Při zapnutí části sestavy se úplně prázdné řady a sloupce odstraní: levý a pravý monitor po "
            L"vypnutí prostředního navážou. Neodstranitelné vnitřní díry zůstávají součástí simulace. "
            L"Zapnutí všech monitorů a režim SCR zachovávají obdélník celé sestavy včetně neviditelných "
            L"mezer. Každý monitor zobrazuje vlastní výřez téže hry.\r\n\r\nPOČÁTEČNÍ STAV A "
            L"OBRAZCE\r\nVýchozí začátek je náhodný šum s 25 % živých buněk. Počáteční hustota 0–100 % se "
            L"použije při příštím restartu. Pouze známé obrazce používá 4 106 přiložených obrazců bez šumu "
            L"a vypne hustotu. Zvolte směs nebo pojmenovaný obrazec; rozměry jsou v buňkách. Psaním názvu "
            L"hledejte v seznamu. Nabízejí se jen obrazce, které se celé vejdou. Malé ověřené obrazce se "
            L"opakují v oddělených kopiích, velké a složité začínají jednou uprostřed. Zmenšení plochy "
            L"může nevyhovující výběr nahradit směsí. Změna režimu nebo obrazce vytvoří novou scénu. "
            L"Restarty výběr zachovají; katalog funguje bez internetu.\r\n\r\nVELIKOST BUNĚK, MŘÍŽKA A "
            L"BARVY\r\nBez mřížky je velikost buňky 1–64 px. Zobrazit mřížku přidá okraj 1 px uvnitř "
            L"stávající rozteče: zobrazená velikost a jezdec se sníží o jednu, použitelné hodnoty jsou "
            L"1–63. Vypnutí hodnotu vrátí. Jezdec zachová celý rozsah a z nedostupného konce se vrátí; "
            L"zatržítko zůstává dostupné. Přepínání zachová scénu kromě zapnutí při 1 px, kdy se rozteč "
            L"zvýší na 2 px a vznikne nová scéna. Také změna velikosti nebo monitorů začne znovu. U "
            L"mimořádně velké plochy může být minimum vyšší. Barvy živých buněk, pozadí a mřížky lze "
            L"nezávisle měnit bez restartu. Náhodná barva živých buněk vybírá novou barvu při každém "
            L"ručním i automatickém restartu scény. Uložená barva se nepřepisuje; vypnutí této volby ji "
            L"obnoví. Stejné chování lze samostatně zapnout pro pozadí a mřížku; obě nové volby jsou "
            L"zpočátku vypnuté.\r\n\r\nRYCHLOST, POZASTAVENÍ A AUTOMATICKÝ RESTART\r\nRychlost je 0–240 "
            L"generací/s nezávisle na obnovování monitoru; 0 zastaví vývoj. Pozastavit a Pokračovat "
            L"zachovávají plochu. Restart vytvoří nový začátek ve zvoleném režimu. Volitelný automatický "
            L"restart rozpoznává statické i přesně se opakující zobrazené fáze včetně oscilátorů. "
            L"Porovnává generace simulace, nikoli uplynulé sekundy; nezobrazené oblasti vynechává. "
            L"Výsledky se čtou asynchronně, proto může restart přijít o něco později. Výchozí rozteč je 8 "
            L"px, rychlost 20 generací/s, náhodná barva živých buněk a automatický restart jsou zapnuté. "
            L"Mřížka je ve výchozím stavu vypnutá. Dosažená rychlost závisí na výkonu a počtu buněk. "
            L"Automatický restart posuzuje oblasti zapnutých monitorů; mezery mezi nimi se mohou dále "
            L"vyvíjet, ale do porovnání se nezahrnují.\r\n\r\nReset hodnot\r\nReset obnoví velikost buňky "
            L"8 px s mřížkou i bez ní (rozteč 9 nebo 8 px), rychlost 20 generací/s, hustotu 25 % a tři "
            L"výchozí barvy. Ostatní volby zachová; obrazec, který se nevejde, nahradí směsí. Nová scéna "
            L"vznikne jen při změně rozteče nebo hustoty v režimu šumu.\r\n\r\nSPOŘIČ OBRAZOVKY "
            L"WINDOWS\r\nGameOfLife.scr používá všechny monitory a ukládá nastavení odděleně od EXE. "
            L"Zapnout náhled spustí celoobrazovkovou animaci při otevřeném nastavení. Malý náhled Windows "
            L"zmenší celou společnou plochu. OK nastavení uloží, Storno nebo Esc změny zahodí. Pohyb myši "
            L"nebo klávesa ukončí celoobrazovkový spořič. Záznam MP4 je dostupný v EXE.\r\n\r\nPOLOHA A "
            L"STAV OKEN\r\nPři zavření se samostatně ukládá poloha hlavního okna a okna O programu; u "
            L"nápovědy také velikost a normální či maximalizovaný stav před případnou minimalizací. To "
            L"nezávisí na potvrzení nastavení aplikace. Ukončení aplikace zavře také nápovědu a O "
            L"programu.\r\n\r\nVYKRESLOVÁNÍ A LICENCE OBRAZCŮ\r\nVývoj a porovnávání zobrazených stavů "
            L"provádějí shadery Direct3D 11 na GPU; při selhání hardwarové inicializace je dostupné "
            L"softwarové vykreslování. Každý monitor používá převzatý framepacer podle vlastní obnovovací "
            L"frekvence. MP4 vyžaduje Media Foundation a kodér H.264. Obrazce pocházejí z LifeWiki (GFDL "
            L"1.2 nebo novější) a volně šiřitelných sbírek Alana Hensela v režimu public domain. Kód "
            L"programu má licenci MIT; oznámení a licence katalogu jsou samostatné."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Velikost buňky: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Rychlost: %u generací/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Počáteční hustota: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Restart scény" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Barva živých buněk…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Barva pozadí…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Vybrané monitory tvoří jednu hru. Prázdné pásy se sloučí, vnitřní díry zůstávají."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animace běží…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animace je pozastavena."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Direct3D renderer se nepodařilo inicializovat."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Zapnout náhled"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Vypnout náhled"
        },
        LocalizedText{ TXT_MONITOR,
            L"Monitor"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Rozlišení"
        },
        LocalizedText{ TXT_POSITION,
            L"Poloha"
        },
        LocalizedText{ TXT_PRIMARY,
            L"hlavní"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Model monitoru"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Obnovovací frekvence"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bitová hloubka"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Formát barvy"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Barevný prostor"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bitů/kanál"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bitů/pixel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Monitor animace"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Připraven"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Zobrazit mřížku"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Barva mřížky…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Automaticky restartovat ustálenou nebo opakující se zobrazenou scénu"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Pouze známé obrazce"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Spustit záznam…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Ukončit záznam"
        },
        LocalizedText{ TXT_RECORDING,
            L"Probíhá záznam MP4…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Záznam byl uložen."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Záznam MP4 se nepodařilo spustit."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Ukončení aplikace ukončí právě probíhající záznam."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Nastavení záznamu"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Rozlišení:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Snímková frekvence:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Změny se použijí při příštím záznamu MP4."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Směs vhodných obrazců"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Vybraný obrazec se již nevejde na plochu. Byla zvolena směs vhodných obrazců."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Katalog známých obrazců se nepodařilo načíst."
        },
    }),
    DefineLanguage(LANG_EN_US, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Random background color at every scene restart" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Random grid color at every scene restart" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Windows screen saver…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED, L"Unable to open Windows Screen Saver Settings." },
        LocalizedText{ TXT_RESET_SETTINGS, L"Reset values" },
        LocalizedText{ TXT_SNAPSHOT, L"Snapshot…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Snapshot was saved." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Could not save the snapshot." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Prevent screen saver during animation" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Random live-cell color on every scene reset"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Installing screen saver…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Uninstalling screen saver…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Install screen saver" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Uninstall screen saver" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"The screen saver was not installed." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"The screen saver was installed." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"The screen saver was uninstalled." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"The screen saver could not be uninstalled. If the screen saver or its preview is running, "
            L"close it and try again."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Uninstallation failed because GameOfLife settings are open. Close the settings window and "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"English (US)"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Controls"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"GameOfLife Settings"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Language:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Cancel"
        },
        LocalizedText{ TXT_EXIT,
            L"Exit"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pause"
        },
        LocalizedText{ TXT_RESUME,
            L"Resume"
        },
        LocalizedText{ TXT_HELP,
            L"Help"
        },
        LocalizedText{ TXT_ABOUT,
            L"About"
        },
        LocalizedText{ TXT_CLOSE,
            L"Close"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Visit %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"The website could not be opened in the default browser."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"The URL could not be copied to the clipboard."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"The information could not be copied to the clipboard."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conway's Game of Life on one shared world across displays."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Version:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Target platform:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Website:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Open in default browser"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Copy &URL"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Copy &information"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"License resource unavailable."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nRULES\r\nConway's Game of Life uses B3/S23 rules. A dead cell is born with "
            L"exactly three live neighbors; a live cell survives with two or three. The eight neighbors "
            L"include diagonals. All cells advance together. Opposite edges wrap: left joins right, top "
            L"joins bottom.\r\n\r\nDISPLAYS AND SHARED WORLD\r\nEXE checkboxes enable displays; settings "
            L"apply to the shared world. One enabled display contains the entire world. With part of an "
            L"arrangement enabled, completely empty rows and columns collapse: left and right displays "
            L"join when the middle one is disabled. Interior holes that cannot collapse remain in the "
            L"simulation. Selecting all displays, or running SCR, preserves the enclosing desktop "
            L"rectangle and invisible gaps. Each display shows its own region of the same "
            L"simulation.\r\n\r\nSTARTING STATE AND PATTERNS\r\nThe default is random noise with 25% live "
            L"cells. Initial density ranges from 0–100% and applies at the next restart. Known patterns "
            L"only uses 4,106 bundled patterns without noise and disables density. Choose a mixture or a "
            L"named pattern; dimensions are in cells. Type a name to search. Only patterns fitting the "
            L"world are listed. Small verified patterns repeat in separate copies; large or complex ones "
            L"start once in the center. Shrinking the world can replace an unavailable selection with a "
            L"mixture. Changing the mode or pattern starts a new scene. Restarts retain the choice; the "
            L"catalog works offline.\r\n\r\nCELL SIZE, GRID, AND COLORS\r\nWithout the grid, cell size is "
            L"1–64 px. Show grid adds a 1 px edge inside the existing spacing: the displayed size and "
            L"slider decrease by one, with usable values 1–63. Turning it off restores the value. The "
            L"slider retains its full range and snaps back at the unavailable endpoint; the checkbox stays "
            L"enabled. These toggles preserve the scene, except enabling the grid at 1 px changes spacing "
            L"to 2 px and starts anew. Changing cell size or displays also starts anew. Very large worlds "
            L"may require a larger minimum. Live-cell, background, and grid colors change independently "
            L"without restarting. Random live-cell color chooses a new color at every manual or automatic "
            L"scene restart. Your saved color is preserved and restored when this option is disabled. The "
            L"same behavior can be enabled separately for background and grid colors; both new options are "
            L"off by default.\r\n\r\nSPEED, PAUSE, AND AUTOMATIC RESTART\r\nSpeed is 0–240 generations/s, "
            L"independent of display refresh; 0 stops evolution. Pause and Resume preserve the world. "
            L"Restart creates a fresh start in the chosen mode. Optional automatic restart detects static "
            L"and exactly repeating visible phases, including oscillators. It compares simulation "
            L"generations, not elapsed seconds; invisible regions are excluded. Checking results is "
            L"asynchronous, so restart can occur slightly later. Defaults are 8 px spacing, 20 "
            L"generations/s, random live-cell colors, and automatic restart enabled. The grid is off by "
            L"default. Achieved speed depends on performance and cell count. Automatic restart checks "
            L"regions of enabled displays; gaps between them can keep evolving but are excluded from "
            L"comparisons.\r\n\r\nReset values\r\nReset restores a displayed cell size of 8 px with or "
            L"without the grid (spacing 9 or 8 px), speed 20 generations/s, density 25%, and the three "
            L"default colors. Other choices are preserved; a pattern that no longer fits is replaced by "
            L"the mixture. A new scene is created only if spacing changes, or density changes in noise "
            L"mode.\r\n\r\nSTANDALONE APPLICATION AND MP4 RECORDING\r\nEXE saves settings continuously and "
            L"records the first active display to MP4, not the combined world. Videos is suggested, with "
            L"Documents as fallback. Viewport uses display dimensions and refresh rate up to 60 fps. TV "
            L"offers 1920 × 1080, 1440 × 1080, or 1280 × 720 in 16:9 at 50, 25, 59.94 (60000/1001), or "
            L"29.97 (30000/1001) fps. Aspect ratio is preserved; TV uses progressive BT.709 limited-range "
            L"4:2:0. Recording settings is independent and can be minimized. OK saves options for the next "
            L"recording; Cancel or Esc discards pending changes. The recorded display cannot be disabled; "
            L"other outputs can change. Closing during recording requires confirmation. With animation "
            L"focused, Space pauses/resumes, F9: Start recording; F10: Stop recording. The cursor hides "
            L"after 1 second of inactivity and reappears on movement. Tab/Shift+Tab navigates controls; "
            L"Alt activates underlined commands. Esc closes Help/About, or exits the main "
            L"window.\r\n\r\nSNAPSHOT AND SCREEN SAVER MANAGEMENT IN EXE\r\nSnapshot saves a "
            L"BMP/GIF/JPEG/PNG/TIFF/WebP of the "
            L"recorded display, or otherwise the first active display, at its resolution without "
            L"restarting the scene. Pictures is suggested, with Documents as fallback. Prevent screen "
            L"saver during animation inhibits the Windows screen saver while animation is visible and not "
            L"paused. Zero speed is not pause. Installation from EXE unpacks the bundled SCR and selects "
            L"it as the Windows screen saver. Installation and uninstallation may require administrator "
            L"approval; the status bar shows progress until completion. If removal is blocked, close the "
            L"running saver, its settings, and Windows preview.\r\n\r\nWINDOWS SCREEN "
            L"SAVER\r\nGameOfLife.scr uses all displays and stores settings separately from EXE. Enable "
            L"preview runs full-screen animation while settings remain open. The small Windows preview "
            L"scales the whole world down. OK saves settings; Cancel or Esc discards changes. Mouse "
            L"movement or a key exits the full-screen saver. MP4 recording is available in "
            L"EXE.\r\n\r\nWINDOW POSITIONS AND STATE\r\nClosing saves main and About window positions "
            L"separately; Help also saves its size and normal or maximized state before any minimization. "
            L"This is independent of confirming application settings. Exiting the application closes Help "
            L"and About as well.\r\n\r\nRENDERING AND PATTERN LICENSES\r\nEvolution and visible-state "
            L"comparisons use Direct3D 11 shaders on the GPU; a software renderer is available when "
            L"hardware initialization fails. Each display uses the established framepacer at its own "
            L"refresh rate. MP4 requires Media Foundation and an H.264 encoder. Patterns come from "
            L"LifeWiki (GFDL 1.2 or later) and Alan Hensel's public-domain collections. Program code is "
            L"MIT-licensed; catalog notices and source licenses are separate.\r\n\r\nWindows screen saver… "
            L"opens the system Screen Saver Settings panel."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nRULES\r\nConway's Game of Life uses B3/S23 rules. A dead cell is born with "
            L"exactly three live neighbors; a live cell survives with two or three. The eight neighbors "
            L"include diagonals. All cells advance together. Opposite edges wrap: left joins right, top "
            L"joins bottom.\r\n\r\nDISPLAYS AND SHARED WORLD\r\nEXE checkboxes enable displays; settings "
            L"apply to the shared world. One enabled display contains the entire world. With part of an "
            L"arrangement enabled, completely empty rows and columns collapse: left and right displays "
            L"join when the middle one is disabled. Interior holes that cannot collapse remain in the "
            L"simulation. Selecting all displays, or running SCR, preserves the enclosing desktop "
            L"rectangle and invisible gaps. Each display shows its own region of the same "
            L"simulation.\r\n\r\nSTARTING STATE AND PATTERNS\r\nThe default is random noise with 25% live "
            L"cells. Initial density ranges from 0–100% and applies at the next restart. Known patterns "
            L"only uses 4,106 bundled patterns without noise and disables density. Choose a mixture or a "
            L"named pattern; dimensions are in cells. Type a name to search. Only patterns fitting the "
            L"world are listed. Small verified patterns repeat in separate copies; large or complex ones "
            L"start once in the center. Shrinking the world can replace an unavailable selection with a "
            L"mixture. Changing the mode or pattern starts a new scene. Restarts retain the choice; the "
            L"catalog works offline.\r\n\r\nCELL SIZE, GRID, AND COLORS\r\nWithout the grid, cell size is "
            L"1–64 px. Show grid adds a 1 px edge inside the existing spacing: the displayed size and "
            L"slider decrease by one, with usable values 1–63. Turning it off restores the value. The "
            L"slider retains its full range and snaps back at the unavailable endpoint; the checkbox stays "
            L"enabled. These toggles preserve the scene, except enabling the grid at 1 px changes spacing "
            L"to 2 px and starts anew. Changing cell size or displays also starts anew. Very large worlds "
            L"may require a larger minimum. Live-cell, background, and grid colors change independently "
            L"without restarting. Random live-cell color chooses a new color at every manual or automatic "
            L"scene restart. Your saved color is preserved and restored when this option is disabled. The "
            L"same behavior can be enabled separately for background and grid colors; both new options are "
            L"off by default.\r\n\r\nSPEED, PAUSE, AND AUTOMATIC RESTART\r\nSpeed is 0–240 generations/s, "
            L"independent of display refresh; 0 stops evolution. Pause and Resume preserve the world. "
            L"Restart creates a fresh start in the chosen mode. Optional automatic restart detects static "
            L"and exactly repeating visible phases, including oscillators. It compares simulation "
            L"generations, not elapsed seconds; invisible regions are excluded. Checking results is "
            L"asynchronous, so restart can occur slightly later. Defaults are 8 px spacing, 20 "
            L"generations/s, random live-cell colors, and automatic restart enabled. The grid is off by "
            L"default. Achieved speed depends on performance and cell count. Automatic restart checks "
            L"regions of enabled displays; gaps between them can keep evolving but are excluded from "
            L"comparisons.\r\n\r\nReset values\r\nReset restores a displayed cell size of 8 px with or "
            L"without the grid (spacing 9 or 8 px), speed 20 generations/s, density 25%, and the three "
            L"default colors. Other choices are preserved; a pattern that no longer fits is replaced by "
            L"the mixture. A new scene is created only if spacing changes, or density changes in noise "
            L"mode.\r\n\r\nWINDOWS SCREEN SAVER\r\nGameOfLife.scr uses all displays and stores settings "
            L"separately from EXE. Enable preview runs full-screen animation while settings remain open. "
            L"The small Windows preview scales the whole world down. OK saves settings; Cancel or Esc "
            L"discards changes. Mouse movement or a key exits the full-screen saver. MP4 recording is "
            L"available in EXE.\r\n\r\nWINDOW POSITIONS AND STATE\r\nClosing saves main and About window "
            L"positions separately; Help also saves its size and normal or maximized state before any "
            L"minimization. This is independent of confirming application settings. Exiting the "
            L"application closes Help and About as well.\r\n\r\nRENDERING AND PATTERN "
            L"LICENSES\r\nEvolution and visible-state comparisons use Direct3D 11 shaders on the GPU; a "
            L"software renderer is available when hardware initialization fails. Each display uses the "
            L"established framepacer at its own refresh rate. MP4 requires Media Foundation and an H.264 "
            L"encoder. Patterns come from LifeWiki (GFDL 1.2 or later) and Alan Hensel's public-domain "
            L"collections. Program code is MIT-licensed; catalog notices and source licenses are separate."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Cell size: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Speed: %u generations/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Initial density: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Restart scene" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Live cell color…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Background color…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Selected displays share one world. Empty bands collapse; interior holes remain."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animation is running…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animation is paused."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Could not initialize the Direct3D renderer."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Enable preview"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Disable preview"
        },
        LocalizedText{ TXT_MONITOR,
            L"Display"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Resolution"
        },
        LocalizedText{ TXT_POSITION,
            L"Position"
        },
        LocalizedText{ TXT_PRIMARY,
            L"primary"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Monitor model"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Refresh rate"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bit depth"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Color format"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Color space"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bits/channel"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bits/pixel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Animation display"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Ready"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Show grid"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Grid color…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Automatically restart a settled or repeating visible scene"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Known patterns only"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Start recording…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Stop recording"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4 recording in progress…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Recording was saved."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Could not start MP4 recording."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Closing the application will stop the recording currently in progress."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Recording settings"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Resolution:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Frame rate:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Changes apply to the next MP4 recording."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Mixture of suitable patterns"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"The selected pattern no longer fits this world. A suitable mixture was selected."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Could not load the known pattern catalog."
        },
    }),
    DefineLanguage(LANG_EN_GB, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Random background colour at every scene restart" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Random grid colour at every scene restart" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Windows screen saver…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED, L"Unable to open Windows Screen Saver Settings." },
        LocalizedText{ TXT_RESET_SETTINGS, L"Reset values" },
        LocalizedText{ TXT_SNAPSHOT, L"Snapshot…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Snapshot was saved." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Could not save the snapshot." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Prevent screen saver during animation" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Random live-cell colour on every scene reset"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Installing screen saver…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Uninstalling screen saver…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Install screen saver" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Uninstall screen saver" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"The screen saver was not installed." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"The screen saver was installed." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"The screen saver was uninstalled." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"The screen saver could not be uninstalled. If the screen saver or its preview is running, "
            L"close it and try again."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Uninstallation failed because GameOfLife settings are open. Close the settings window and "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"English (UK)"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Controls"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"GameOfLife Settings"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Language:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Cancel"
        },
        LocalizedText{ TXT_EXIT,
            L"Exit"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pause"
        },
        LocalizedText{ TXT_RESUME,
            L"Resume"
        },
        LocalizedText{ TXT_HELP,
            L"Help"
        },
        LocalizedText{ TXT_ABOUT,
            L"About"
        },
        LocalizedText{ TXT_CLOSE,
            L"Close"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Visit %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"The website could not be opened in the default browser."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"The URL could not be copied to the clipboard."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"The information could not be copied to the clipboard."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conway's Game of Life on one shared world across displays."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Version:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Target platform:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Website:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Open in default browser"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Copy &URL"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Copy &information"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"License resource unavailable."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nRULES\r\nConway's Game of Life uses B3/S23 rules. A dead cell is born with "
            L"exactly three live neighbours; a live cell survives with two or three. The eight neighbours "
            L"include diagonals. All cells advance together. Opposite edges wrap: left joins right, top "
            L"joins bottom.\r\n\r\nDISPLAYS AND SHARED WORLD\r\nEXE checkboxes enable displays; settings "
            L"apply to the shared world. One enabled display contains the entire world. With part of an "
            L"arrangement enabled, completely empty rows and columns collapse: left and right displays "
            L"join when the middle one is disabled. Interior holes that cannot collapse remain in the "
            L"simulation. Selecting all displays, or running SCR, preserves the enclosing desktop "
            L"rectangle and invisible gaps. Each display shows its own region of the same "
            L"simulation.\r\n\r\nSTARTING STATE AND PATTERNS\r\nThe default is random noise with 25% live "
            L"cells. Initial density ranges from 0–100% and applies at the next restart. Known patterns "
            L"only uses 4,106 bundled patterns without noise and disables density. Choose a mixture or a "
            L"named pattern; dimensions are in cells. Type a name to search. Only patterns fitting the "
            L"world are listed. Small verified patterns repeat in separate copies; large or complex ones "
            L"start once in the centre. Shrinking the world can replace an unavailable selection with a "
            L"mixture. Changing the mode or pattern starts a new scene. Restarts retain the choice; the "
            L"catalogue works offline.\r\n\r\nCELL SIZE, GRID, AND COLOURS\r\nWithout the grid, cell size "
            L"is 1–64 px. Show grid adds a 1 px edge inside the existing spacing: the displayed size and "
            L"slider decrease by one, with usable values 1–63. Turning it off restores the value. The "
            L"slider retains its full range and snaps back at the unavailable endpoint; the checkbox stays "
            L"enabled. These toggles preserve the scene, except enabling the grid at 1 px changes spacing "
            L"to 2 px and starts anew. Changing cell size or displays also starts anew. Very large worlds "
            L"may require a larger minimum. Live-cell, background, and grid colours change independently "
            L"without restarting. Random live-cell colour chooses a new colour at every manual or "
            L"automatic scene restart. Your saved colour is preserved and restored when this option is "
            L"disabled. The same behaviour can be enabled separately for background and grid colours; both "
            L"new options are off by default.\r\n\r\nSPEED, PAUSE, AND AUTOMATIC RESTART\r\nSpeed is 0–240 "
            L"generations/s, independent of display refresh; 0 stops evolution. Pause and Resume preserve "
            L"the world. Restart creates a fresh start in the chosen mode. Optional automatic restart "
            L"detects static and exactly repeating visible phases, including oscillators. It compares "
            L"simulation generations, not elapsed seconds; invisible regions are excluded. Checking "
            L"results is asynchronous, so restart can occur slightly later. Defaults are 8 px spacing, 20 "
            L"generations/s, random live-cell colours, and automatic restart enabled. The grid is off by "
            L"default. Achieved speed depends on performance and cell count. Automatic restart checks "
            L"regions of enabled displays; gaps between them can keep evolving but are excluded from "
            L"comparisons.\r\n\r\nReset values\r\nReset restores a displayed cell size of 8 px with or "
            L"without the grid (spacing 9 or 8 px), speed 20 generations/s, density 25%, and the three "
            L"default colours. Other choices are preserved; a pattern that no longer fits is replaced by "
            L"the mixture. A new scene is created only if spacing changes, or density changes in noise "
            L"mode.\r\n\r\nSTANDALONE APPLICATION AND MP4 RECORDING\r\nEXE saves settings continuously and "
            L"records the first active display to MP4, not the combined world. Videos is suggested, with "
            L"Documents as fallback. Viewport uses display dimensions and refresh rate up to 60 fps. TV "
            L"offers 1920 × 1080, 1440 × 1080, or 1280 × 720 in 16:9 at 50, 25, 59.94 (60000/1001), or "
            L"29.97 (30000/1001) fps. Aspect ratio is preserved; TV uses progressive BT.709 limited-range "
            L"4:2:0. Recording settings is independent and can be minimised. OK saves options for the next "
            L"recording; Cancel or Esc discards pending changes. The recorded display cannot be disabled; "
            L"other outputs can change. Closing during recording requires confirmation. With animation "
            L"focused, Space pauses/resumes, F9: Start recording; F10: Stop recording. The cursor hides "
            L"after 1 second of inactivity and reappears on movement. Tab/Shift+Tab navigates controls; "
            L"Alt activates underlined commands. Esc closes Help/About, or exits the main "
            L"window.\r\n\r\nSNAPSHOT AND SCREEN SAVER MANAGEMENT IN EXE\r\nSnapshot saves a "
            L"BMP/GIF/JPEG/PNG/TIFF/WebP of the "
            L"recorded display, or otherwise the first active display, at its resolution without "
            L"restarting the scene. Pictures is suggested, with Documents as fallback. Prevent screen "
            L"saver during animation inhibits the Windows screen saver while animation is visible and not "
            L"paused. Zero speed is not pause. Installation from EXE unpacks the bundled SCR and selects "
            L"it as the Windows screen saver. Installation and uninstallation may require administrator "
            L"approval; the status bar shows progress until completion. If removal is blocked, close the "
            L"running saver, its settings, and Windows preview.\r\n\r\nWINDOWS SCREEN "
            L"SAVER\r\nGameOfLife.scr uses all displays and stores settings separately from EXE. Enable "
            L"preview runs full-screen animation while settings remain open. The small Windows preview "
            L"scales the whole world down. OK saves settings; Cancel or Esc discards changes. Mouse "
            L"movement or a key exits the full-screen saver. MP4 recording is available in "
            L"EXE.\r\n\r\nWINDOW POSITIONS AND STATE\r\nClosing saves main and About window positions "
            L"separately; Help also saves its size and normal or maximised state before any minimisation. "
            L"This is independent of confirming application settings. Exiting the application closes Help "
            L"and About as well.\r\n\r\nRENDERING AND PATTERN LICENSES\r\nEvolution and visible-state "
            L"comparisons use Direct3D 11 shaders on the GPU; a software renderer is available when "
            L"hardware initialization fails. Each display uses the established framepacer at its own "
            L"refresh rate. MP4 requires Media Foundation and an H.264 encoder. Patterns come from "
            L"LifeWiki (GFDL 1.2 or later) and Alan Hensel's public-domain collections. Program code is "
            L"MIT-licensed; catalogue notices and source licenses are separate.\r\n\r\nWindows screen "
            L"saver… opens the system Screen Saver Settings panel."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nRULES\r\nConway's Game of Life uses B3/S23 rules. A dead cell is born with "
            L"exactly three live neighbours; a live cell survives with two or three. The eight neighbours "
            L"include diagonals. All cells advance together. Opposite edges wrap: left joins right, top "
            L"joins bottom.\r\n\r\nDISPLAYS AND SHARED WORLD\r\nEXE checkboxes enable displays; settings "
            L"apply to the shared world. One enabled display contains the entire world. With part of an "
            L"arrangement enabled, completely empty rows and columns collapse: left and right displays "
            L"join when the middle one is disabled. Interior holes that cannot collapse remain in the "
            L"simulation. Selecting all displays, or running SCR, preserves the enclosing desktop "
            L"rectangle and invisible gaps. Each display shows its own region of the same "
            L"simulation.\r\n\r\nSTARTING STATE AND PATTERNS\r\nThe default is random noise with 25% live "
            L"cells. Initial density ranges from 0–100% and applies at the next restart. Known patterns "
            L"only uses 4,106 bundled patterns without noise and disables density. Choose a mixture or a "
            L"named pattern; dimensions are in cells. Type a name to search. Only patterns fitting the "
            L"world are listed. Small verified patterns repeat in separate copies; large or complex ones "
            L"start once in the centre. Shrinking the world can replace an unavailable selection with a "
            L"mixture. Changing the mode or pattern starts a new scene. Restarts retain the choice; the "
            L"catalogue works offline.\r\n\r\nCELL SIZE, GRID, AND COLOURS\r\nWithout the grid, cell size "
            L"is 1–64 px. Show grid adds a 1 px edge inside the existing spacing: the displayed size and "
            L"slider decrease by one, with usable values 1–63. Turning it off restores the value. The "
            L"slider retains its full range and snaps back at the unavailable endpoint; the checkbox stays "
            L"enabled. These toggles preserve the scene, except enabling the grid at 1 px changes spacing "
            L"to 2 px and starts anew. Changing cell size or displays also starts anew. Very large worlds "
            L"may require a larger minimum. Live-cell, background, and grid colours change independently "
            L"without restarting. Random live-cell colour chooses a new colour at every manual or "
            L"automatic scene restart. Your saved colour is preserved and restored when this option is "
            L"disabled. The same behaviour can be enabled separately for background and grid colours; both "
            L"new options are off by default.\r\n\r\nSPEED, PAUSE, AND AUTOMATIC RESTART\r\nSpeed is 0–240 "
            L"generations/s, independent of display refresh; 0 stops evolution. Pause and Resume preserve "
            L"the world. Restart creates a fresh start in the chosen mode. Optional automatic restart "
            L"detects static and exactly repeating visible phases, including oscillators. It compares "
            L"simulation generations, not elapsed seconds; invisible regions are excluded. Checking "
            L"results is asynchronous, so restart can occur slightly later. Defaults are 8 px spacing, 20 "
            L"generations/s, random live-cell colours, and automatic restart enabled. The grid is off by "
            L"default. Achieved speed depends on performance and cell count. Automatic restart checks "
            L"regions of enabled displays; gaps between them can keep evolving but are excluded from "
            L"comparisons.\r\n\r\nReset values\r\nReset restores a displayed cell size of 8 px with or "
            L"without the grid (spacing 9 or 8 px), speed 20 generations/s, density 25%, and the three "
            L"default colours. Other choices are preserved; a pattern that no longer fits is replaced by "
            L"the mixture. A new scene is created only if spacing changes, or density changes in noise "
            L"mode.\r\n\r\nWINDOWS SCREEN SAVER\r\nGameOfLife.scr uses all displays and stores settings "
            L"separately from EXE. Enable preview runs full-screen animation while settings remain open. "
            L"The small Windows preview scales the whole world down. OK saves settings; Cancel or Esc "
            L"discards changes. Mouse movement or a key exits the full-screen saver. MP4 recording is "
            L"available in EXE.\r\n\r\nWINDOW POSITIONS AND STATE\r\nClosing saves main and About window "
            L"positions separately; Help also saves its size and normal or maximised state before any "
            L"minimisation. This is independent of confirming application settings. Exiting the "
            L"application closes Help and About as well.\r\n\r\nRENDERING AND PATTERN "
            L"LICENSES\r\nEvolution and visible-state comparisons use Direct3D 11 shaders on the GPU; a "
            L"software renderer is available when hardware initialization fails. Each display uses the "
            L"established framepacer at its own refresh rate. MP4 requires Media Foundation and an H.264 "
            L"encoder. Patterns come from LifeWiki (GFDL 1.2 or later) and Alan Hensel's public-domain "
            L"collections. Program code is MIT-licensed; catalogue notices and source licenses are "
            L"separate."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Cell size: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Speed: %u generations/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Initial density: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Restart scene" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Live cell colour…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Background colour…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Selected displays share one world. Empty bands collapse; interior holes remain."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animation is running…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animation is paused."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Could not initialise the Direct3D renderer."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Enable preview"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Disable preview"
        },
        LocalizedText{ TXT_MONITOR,
            L"Display"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Resolution"
        },
        LocalizedText{ TXT_POSITION,
            L"Position"
        },
        LocalizedText{ TXT_PRIMARY,
            L"primary"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Monitor model"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Refresh rate"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bit depth"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Colour format"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Colour space"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bits/channel"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bits/pixel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Animation display"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Ready"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Show grid"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Grid colour…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Automatically restart a settled or repeating visible scene"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Known patterns only"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Start recording…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Stop recording"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4 recording in progress…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Recording was saved."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Could not start MP4 recording."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Closing the application will stop the recording currently in progress."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Recording settings"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Resolution:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Frame rate:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Changes apply to the next MP4 recording."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Mixture of suitable patterns"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"The selected pattern no longer fits this world. A suitable mixture was selected."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Could not load the known pattern catalog."
        },
    }),
    DefineLanguage(LANG_EN_AU, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Random background colour at every scene restart" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Random grid colour at every scene restart" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Windows screen saver…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED, L"Unable to open Windows Screen Saver Settings." },
        LocalizedText{ TXT_RESET_SETTINGS, L"Reset values" },
        LocalizedText{ TXT_SNAPSHOT, L"Snapshot…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Snapshot was saved." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Could not save the snapshot." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Prevent screen saver during animation" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Random live-cell colour on every scene reset"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Installing screen saver…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Uninstalling screen saver…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Install screen saver" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Uninstall screen saver" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"The screen saver was not installed." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"The screen saver was installed." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"The screen saver was uninstalled." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"The screen saver could not be uninstalled. If the screen saver or its preview is running, "
            L"close it and try again."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Uninstallation failed because GameOfLife settings are open. Close the settings window and "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"English (Australia)"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Controls"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"GameOfLife Settings"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Language:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Cancel"
        },
        LocalizedText{ TXT_EXIT,
            L"Exit"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pause"
        },
        LocalizedText{ TXT_RESUME,
            L"Resume"
        },
        LocalizedText{ TXT_HELP,
            L"Help"
        },
        LocalizedText{ TXT_ABOUT,
            L"About"
        },
        LocalizedText{ TXT_CLOSE,
            L"Close"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Visit %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"The website could not be opened in the default browser."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"The URL could not be copied to the clipboard."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"The information could not be copied to the clipboard."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conway's Game of Life on one shared world across displays."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Version:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Target platform:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Website:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Open in default browser"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Copy &URL"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Copy &information"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"License resource unavailable."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nRULES\r\nConway's Game of Life uses B3/S23 rules. A dead cell is born with "
            L"exactly three live neighbours; a live cell survives with two or three. The eight neighbours "
            L"include diagonals. All cells advance together. Opposite edges wrap: left joins right, top "
            L"joins bottom.\r\n\r\nDISPLAYS AND SHARED WORLD\r\nEXE checkboxes enable displays; settings "
            L"apply to the shared world. One enabled display contains the entire world. With part of an "
            L"arrangement enabled, completely empty rows and columns collapse: left and right displays "
            L"join when the middle one is disabled. Interior holes that cannot collapse remain in the "
            L"simulation. Selecting all displays, or running SCR, preserves the enclosing desktop "
            L"rectangle and invisible gaps. Each display shows its own region of the same "
            L"simulation.\r\n\r\nSTARTING STATE AND PATTERNS\r\nThe default is random noise with 25% live "
            L"cells. Initial density ranges from 0–100% and applies at the next restart. Known patterns "
            L"only uses 4,106 bundled patterns without noise and disables density. Choose a mixture or a "
            L"named pattern; dimensions are in cells. Type a name to search. Only patterns fitting the "
            L"world are listed. Small verified patterns repeat in separate copies; large or complex ones "
            L"start once in the centre. Shrinking the world can replace an unavailable selection with a "
            L"mixture. Changing the mode or pattern starts a new scene. Restarts retain the choice; the "
            L"catalogue works offline.\r\n\r\nCELL SIZE, GRID, AND COLOURS\r\nWithout the grid, cell size "
            L"is 1–64 px. Show grid adds a 1 px edge inside the existing spacing: the displayed size and "
            L"slider decrease by one, with usable values 1–63. Turning it off restores the value. The "
            L"slider retains its full range and snaps back at the unavailable endpoint; the checkbox stays "
            L"enabled. These toggles preserve the scene, except enabling the grid at 1 px changes spacing "
            L"to 2 px and starts anew. Changing cell size or displays also starts anew. Very large worlds "
            L"may require a larger minimum. Live-cell, background, and grid colours change independently "
            L"without restarting. Random live-cell colour chooses a new colour at every manual or "
            L"automatic scene restart. Your saved colour is preserved and restored when this option is "
            L"disabled. The same behaviour can be enabled separately for background and grid colours; both "
            L"new options are off by default.\r\n\r\nSPEED, PAUSE, AND AUTOMATIC RESTART\r\nSpeed is 0–240 "
            L"generations/s, independent of display refresh; 0 stops evolution. Pause and Resume preserve "
            L"the world. Restart creates a fresh start in the chosen mode. Optional automatic restart "
            L"detects static and exactly repeating visible phases, including oscillators. It compares "
            L"simulation generations, not elapsed seconds; invisible regions are excluded. Checking "
            L"results is asynchronous, so restart can occur slightly later. Defaults are 8 px spacing, 20 "
            L"generations/s, random live-cell colours, and automatic restart enabled. The grid is off by "
            L"default. Achieved speed depends on performance and cell count. Automatic restart checks "
            L"regions of enabled displays; gaps between them can keep evolving but are excluded from "
            L"comparisons.\r\n\r\nReset values\r\nReset restores a displayed cell size of 8 px with or "
            L"without the grid (spacing 9 or 8 px), speed 20 generations/s, density 25%, and the three "
            L"default colours. Other choices are preserved; a pattern that no longer fits is replaced by "
            L"the mixture. A new scene is created only if spacing changes, or density changes in noise "
            L"mode.\r\n\r\nSTANDALONE APPLICATION AND MP4 RECORDING\r\nEXE saves settings continuously and "
            L"records the first active display to MP4, not the combined world. Videos is suggested, with "
            L"Documents as fallback. Viewport uses display dimensions and refresh rate up to 60 fps. TV "
            L"offers 1920 × 1080, 1440 × 1080, or 1280 × 720 in 16:9 at 50, 25, 59.94 (60000/1001), or "
            L"29.97 (30000/1001) fps. Aspect ratio is preserved; TV uses progressive BT.709 limited-range "
            L"4:2:0. Recording settings is independent and can be minimised. OK saves options for the next "
            L"recording; Cancel or Esc discards pending changes. The recorded display cannot be disabled; "
            L"other outputs can change. Closing during recording requires confirmation. With animation "
            L"focused, Space pauses/resumes, F9: Start recording; F10: Stop recording. The cursor hides "
            L"after 1 second of inactivity and reappears on movement. Tab/Shift+Tab navigates controls; "
            L"Alt activates underlined commands. Esc closes Help/About, or exits the main "
            L"window.\r\n\r\nSNAPSHOT AND SCREEN SAVER MANAGEMENT IN EXE\r\nSnapshot saves a "
            L"BMP/GIF/JPEG/PNG/TIFF/WebP of the "
            L"recorded display, or otherwise the first active display, at its resolution without "
            L"restarting the scene. Pictures is suggested, with Documents as fallback. Prevent screen "
            L"saver during animation inhibits the Windows screen saver while animation is visible and not "
            L"paused. Zero speed is not pause. Installation from EXE unpacks the bundled SCR and selects "
            L"it as the Windows screen saver. Installation and uninstallation may require administrator "
            L"approval; the status bar shows progress until completion. If removal is blocked, close the "
            L"running saver, its settings, and Windows preview.\r\n\r\nWINDOWS SCREEN "
            L"SAVER\r\nGameOfLife.scr uses all displays and stores settings separately from EXE. Enable "
            L"preview runs full-screen animation while settings remain open. The small Windows preview "
            L"scales the whole world down. OK saves settings; Cancel or Esc discards changes. Mouse "
            L"movement or a key exits the full-screen saver. MP4 recording is available in "
            L"EXE.\r\n\r\nWINDOW POSITIONS AND STATE\r\nClosing saves main and About window positions "
            L"separately; Help also saves its size and normal or maximised state before any minimisation. "
            L"This is independent of confirming application settings. Exiting the application closes Help "
            L"and About as well.\r\n\r\nRENDERING AND PATTERN LICENSES\r\nEvolution and visible-state "
            L"comparisons use Direct3D 11 shaders on the GPU; a software renderer is available when "
            L"hardware initialization fails. Each display uses the established framepacer at its own "
            L"refresh rate. MP4 requires Media Foundation and an H.264 encoder. Patterns come from "
            L"LifeWiki (GFDL 1.2 or later) and Alan Hensel's public-domain collections. Program code is "
            L"MIT-licensed; catalogue notices and source licenses are separate.\r\n\r\nWindows screen "
            L"saver… opens the system Screen Saver Settings panel."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nRULES\r\nConway's Game of Life uses B3/S23 rules. A dead cell is born with "
            L"exactly three live neighbours; a live cell survives with two or three. The eight neighbours "
            L"include diagonals. All cells advance together. Opposite edges wrap: left joins right, top "
            L"joins bottom.\r\n\r\nDISPLAYS AND SHARED WORLD\r\nEXE checkboxes enable displays; settings "
            L"apply to the shared world. One enabled display contains the entire world. With part of an "
            L"arrangement enabled, completely empty rows and columns collapse: left and right displays "
            L"join when the middle one is disabled. Interior holes that cannot collapse remain in the "
            L"simulation. Selecting all displays, or running SCR, preserves the enclosing desktop "
            L"rectangle and invisible gaps. Each display shows its own region of the same "
            L"simulation.\r\n\r\nSTARTING STATE AND PATTERNS\r\nThe default is random noise with 25% live "
            L"cells. Initial density ranges from 0–100% and applies at the next restart. Known patterns "
            L"only uses 4,106 bundled patterns without noise and disables density. Choose a mixture or a "
            L"named pattern; dimensions are in cells. Type a name to search. Only patterns fitting the "
            L"world are listed. Small verified patterns repeat in separate copies; large or complex ones "
            L"start once in the centre. Shrinking the world can replace an unavailable selection with a "
            L"mixture. Changing the mode or pattern starts a new scene. Restarts retain the choice; the "
            L"catalogue works offline.\r\n\r\nCELL SIZE, GRID, AND COLOURS\r\nWithout the grid, cell size "
            L"is 1–64 px. Show grid adds a 1 px edge inside the existing spacing: the displayed size and "
            L"slider decrease by one, with usable values 1–63. Turning it off restores the value. The "
            L"slider retains its full range and snaps back at the unavailable endpoint; the checkbox stays "
            L"enabled. These toggles preserve the scene, except enabling the grid at 1 px changes spacing "
            L"to 2 px and starts anew. Changing cell size or displays also starts anew. Very large worlds "
            L"may require a larger minimum. Live-cell, background, and grid colours change independently "
            L"without restarting. Random live-cell colour chooses a new colour at every manual or "
            L"automatic scene restart. Your saved colour is preserved and restored when this option is "
            L"disabled. The same behaviour can be enabled separately for background and grid colours; both "
            L"new options are off by default.\r\n\r\nSPEED, PAUSE, AND AUTOMATIC RESTART\r\nSpeed is 0–240 "
            L"generations/s, independent of display refresh; 0 stops evolution. Pause and Resume preserve "
            L"the world. Restart creates a fresh start in the chosen mode. Optional automatic restart "
            L"detects static and exactly repeating visible phases, including oscillators. It compares "
            L"simulation generations, not elapsed seconds; invisible regions are excluded. Checking "
            L"results is asynchronous, so restart can occur slightly later. Defaults are 8 px spacing, 20 "
            L"generations/s, random live-cell colours, and automatic restart enabled. The grid is off by "
            L"default. Achieved speed depends on performance and cell count. Automatic restart checks "
            L"regions of enabled displays; gaps between them can keep evolving but are excluded from "
            L"comparisons.\r\n\r\nReset values\r\nReset restores a displayed cell size of 8 px with or "
            L"without the grid (spacing 9 or 8 px), speed 20 generations/s, density 25%, and the three "
            L"default colours. Other choices are preserved; a pattern that no longer fits is replaced by "
            L"the mixture. A new scene is created only if spacing changes, or density changes in noise "
            L"mode.\r\n\r\nWINDOWS SCREEN SAVER\r\nGameOfLife.scr uses all displays and stores settings "
            L"separately from EXE. Enable preview runs full-screen animation while settings remain open. "
            L"The small Windows preview scales the whole world down. OK saves settings; Cancel or Esc "
            L"discards changes. Mouse movement or a key exits the full-screen saver. MP4 recording is "
            L"available in EXE.\r\n\r\nWINDOW POSITIONS AND STATE\r\nClosing saves main and About window "
            L"positions separately; Help also saves its size and normal or maximised state before any "
            L"minimisation. This is independent of confirming application settings. Exiting the "
            L"application closes Help and About as well.\r\n\r\nRENDERING AND PATTERN "
            L"LICENSES\r\nEvolution and visible-state comparisons use Direct3D 11 shaders on the GPU; a "
            L"software renderer is available when hardware initialization fails. Each display uses the "
            L"established framepacer at its own refresh rate. MP4 requires Media Foundation and an H.264 "
            L"encoder. Patterns come from LifeWiki (GFDL 1.2 or later) and Alan Hensel's public-domain "
            L"collections. Program code is MIT-licensed; catalogue notices and source licenses are "
            L"separate."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Cell size: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Speed: %u generations/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Initial density: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Restart scene" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Live cell colour…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Background colour…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Selected displays share one world. Empty bands collapse; interior holes remain."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animation is running…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animation is paused."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Could not initialise the Direct3D renderer."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Enable preview"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Disable preview"
        },
        LocalizedText{ TXT_MONITOR,
            L"Display"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Resolution"
        },
        LocalizedText{ TXT_POSITION,
            L"Position"
        },
        LocalizedText{ TXT_PRIMARY,
            L"primary"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Monitor model"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Refresh rate"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bit depth"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Colour format"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Colour space"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bits/channel"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bits/pixel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Animation display"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Ready"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Show grid"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Grid colour…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Automatically restart a settled or repeating visible scene"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Known patterns only"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Start recording…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Stop recording"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4 recording in progress…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Recording was saved."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Could not start MP4 recording."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Closing the application will stop the recording currently in progress."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Recording settings"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Resolution:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Frame rate:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Changes apply to the next MP4 recording."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Mixture of suitable patterns"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"The selected pattern no longer fits this world. A suitable mixture was selected."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Could not load the known pattern catalog."
        },
    }),
    DefineLanguage(LANG_DE, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Zufällige Hintergrundfarbe bei jedem Szenenneustart" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Zufällige Rasterfarbe bei jedem Szenenneustart" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Windows-Bildschirmschoner…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Die Windows-Bildschirmschonereinstellungen konnten nicht geöffnet werden."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Werte zurücksetzen" },
        LocalizedText{ TXT_SNAPSHOT, L"Schnappschuss…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Schnappschuss wurde gespeichert." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Der Schnappschuss konnte nicht gespeichert werden." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Bildschirmschoner bei Animation sperren" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Zufällige Farbe lebender Zellen bei jedem Neustart der Szene"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Bildschirmschoner wird installiert…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Bildschirmschoner wird deinstalliert…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Bildschirmschoner installieren" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Bildschirmschoner deinstallieren" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Der Bildschirmschoner wurde nicht installiert." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Der Bildschirmschoner wurde installiert." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Der Bildschirmschoner wurde deinstalliert." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Der Bildschirmschoner konnte nicht deinstalliert werden. Falls der Bildschirmschoner oder "
            L"seine Vorschau läuft, schließen Sie ihn und versuchen Sie es erneut."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Die Deinstallation ist fehlgeschlagen, weil die GameOfLife-Einstellungen geöffnet sind. "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Deutsch"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Steuerung"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"GameOfLife-Einstellungen"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Sprache:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Abbrechen"
        },
        LocalizedText{ TXT_EXIT,
            L"Beenden"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pause"
        },
        LocalizedText{ TXT_RESUME,
            L"Fortsetzen"
        },
        LocalizedText{ TXT_HELP,
            L"Hilfe"
        },
        LocalizedText{ TXT_ABOUT,
            L"Info"
        },
        LocalizedText{ TXT_CLOSE,
            L"Schließen"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Website %ls besuchen"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Die Website kann nicht im Standardbrowser geöffnet werden."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Die URL konnte nicht in die Zwischenablage kopiert werden."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Die Informationen konnten nicht in die Zwischenablage kopiert werden."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conways Spiel des Lebens auf einer gemeinsamen Fläche mehrerer Bildschirme."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Version:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Zielplattform:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Website:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"Im Standardbrowser &öffnen"
        },
        LocalizedText{ TXT_COPY_URL,
            L"&URL kopieren"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"&Informationen kopieren"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Die Lizenzressource ist nicht verfügbar."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nREGELN\r\nConways Spiel des Lebens verwendet B3/S23. Eine tote Zelle wird "
            L"bei genau drei lebenden Nachbarn geboren; eine lebende überlebt bei zwei oder drei. Die acht "
            L"Nachbarn schließen Diagonalen ein. Alle Zellen ändern sich gleichzeitig. Gegenüberliegende "
            L"Ränder sind verbunden: links mit rechts, oben mit unten.\r\n\r\nBILDSCHIRME UND GEMEINSAME "
            L"WELT\r\nDie Kontrollkästchen in EXE aktivieren Bildschirme; Einstellungen gelten für die "
            L"gemeinsame Welt. Ein einziger aktiver Bildschirm enthält die gesamte Welt. Bei einer "
            L"Teilauswahl entfallen vollständig leere Zeilen und Spalten: Nach Abschalten des mittleren "
            L"schließen der linke und rechte Bildschirm aneinander an. Nicht entfernbare innere Lücken "
            L"bleiben Teil der Simulation. Alle ausgewählten Bildschirme sowie SCR bewahren das "
            L"umschließende Desktop-Rechteck einschließlich unsichtbarer Lücken. Jeder Bildschirm zeigt "
            L"seinen Ausschnitt derselben Simulation.\r\n\r\nANFANGSZUSTAND UND MUSTER\r\nStandard ist "
            L"Zufallsrauschen mit 25 % lebenden Zellen. Die Anfangsdichte von 0–100 % gilt beim nächsten "
            L"Neustart. Nur bekannte Muster verwendet 4.106 mitgelieferte Muster ohne Rauschen und "
            L"deaktiviert die Dichte. Wählen Sie eine Mischung oder einen Namen; Maße sind in Zellen "
            L"angegeben. Tippen sucht im Verzeichnis. Nur vollständig passende Muster erscheinen. Kleine "
            L"geprüfte Muster werden in getrennten Kopien verteilt, große oder komplexe einmal mittig. "
            L"Nach Verkleinern kann eine unpassende Auswahl durch eine Mischung ersetzt werden. Modus- "
            L"oder Musterwechsel erzeugen eine neue Szene. Neustarts behalten die Auswahl; der Katalog "
            L"funktioniert offline.\r\n\r\nZELLGRÖSSE, RASTER UND FARBEN\r\nOhne Raster beträgt die "
            L"Zellgröße 1–64 px. Raster anzeigen fügt innerhalb des bisherigen Abstands einen Rand von 1 "
            L"px ein: Anzeige und Schieber sinken um eins, nutzbar sind 1–63. Ausschalten stellt den Wert "
            L"wieder her. Der Schieber behält seinen Bereich und springt vom unzulässigen Ende zurück; das "
            L"Kästchen bleibt bedienbar. Umschalten bewahrt die Szene, außer beim Einschalten bei 1 px: "
            L"Dann entstehen 2 px Abstand und eine neue Szene. Änderungen an Zellgröße oder Bildschirmen "
            L"beginnen ebenfalls neu. Sehr große Welten können einen höheren Mindestwert erfordern. Zell-, "
            L"Hintergrund- und Rasterfarbe ändern sich unabhängig ohne Neustart. Die zufällige Farbe "
            L"lebender Zellen wird bei jedem manuellen oder automatischen Szenenneustart neu gewählt. Die "
            L"gespeicherte Farbe bleibt erhalten und wird beim Ausschalten dieser Option "
            L"wiederhergestellt. Dasselbe Verhalten lässt sich getrennt für Hintergrund und Raster "
            L"aktivieren; beide neuen Optionen sind standardmäßig aus.\r\n\r\nTEMPO, PAUSE UND "
            L"AUTOMATISCHER NEUSTART\r\nDas Tempo beträgt 0–240 Generationen/s unabhängig von der "
            L"Bildwiederholrate; 0 hält die Entwicklung an. Pause und Fortsetzen bewahren die Welt. "
            L"Neustart beginnt im gewählten Modus neu. Der optionale automatische Neustart erkennt "
            L"statische und exakt wiederkehrende sichtbare Phasen einschließlich Oszillatoren. Verglichen "
            L"werden Generationen statt Sekunden; unsichtbare Bereiche bleiben unberücksichtigt. "
            L"Asynchrone Ergebnisse können den Neustart etwas verzögern. Vorgaben: 8 px Abstand, 20 "
            L"Generationen/s, zufällige Farben lebender Zellen und automatischer Neustart ein. Das Raster "
            L"ist standardmäßig ausgeschaltet. Die erreichte Geschwindigkeit hängt von Leistung und "
            L"Zellzahl ab. Der automatische Neustart prüft die Bereiche aktivierter Bildschirme; Lücken "
            L"entwickeln sich weiter, werden aber nicht verglichen.\r\n\r\nWerte "
            L"zurücksetzen\r\nZurücksetzen stellt die angezeigte Zellgröße mit und ohne Raster auf 8 px "
            L"(Abstand 9 bzw. 8 px), das Tempo auf 20 Generationen/s, die Dichte auf 25 % und die drei "
            L"Standardfarben wieder her. Andere Einstellungen bleiben erhalten; ein nicht mehr passendes "
            L"Muster wird durch die Mischung ersetzt. Nur ein geänderter Abstand oder eine geänderte "
            L"Dichte im Rauschmodus erzeugt eine neue Szene.\r\n\r\nEIGENSTÄNDIGE ANWENDUNG UND "
            L"MP4-AUFNAHME\r\nEXE speichert Einstellungen laufend und nimmt den ersten aktiven Bildschirm "
            L"als MP4 auf. Angeboten wird Videos, ersatzweise Dokumente. Viewport nutzt Bildschirmmaße und "
            L"Bildwiederholrate bis 60 Bilder/s. TV bietet 1920 × 1080, 1440 × 1080 oder 1280 × 720 in "
            L"16:9 bei 50, 25, 59,94 (60000/1001) oder 29,97 (30000/1001) Bildern/s. Das Seitenverhältnis "
            L"bleibt erhalten; TV nutzt progressives BT.709 mit begrenztem Wertebereich und 4:2:0. Das "
            L"unabhängige Aufnahmefenster lässt sich minimieren. OK speichert für die nächste Aufnahme; "
            L"Abbrechen oder Esc verwirft unbestätigte Änderungen. Der aufgezeichnete Bildschirm bleibt "
            L"aktiviert; andere Ausgänge lassen sich ändern. Beenden während der Aufnahme erfordert "
            L"Bestätigung. Bei fokussierter Animation schaltet Leertaste die Pause um, F9: Aufnahme "
            L"starten; F10: Aufnahme beenden. Der Zeiger verschwindet nach 1 Sekunde Inaktivität und "
            L"erscheint bei Bewegung. Tab/Shift+Tab wechselt Steuerelemente, Alt aktiviert unterstrichene "
            L"Befehle. Esc schließt Hilfe/Info beziehungsweise die Anwendung im "
            L"Hauptfenster.\r\n\r\nSCHNAPPSCHUSS UND BILDSCHIRMSCHONERVERWALTUNG IN EXE\r\nSchnappschuss "
            L"speichert den aufgenommenen, sonst den ersten aktiven Bildschirm als "
            L"BMP/GIF/JPEG/PNG/TIFF/WebP in seiner Auflösung "
            L"ohne Szenenneustart. Vorgeschlagen wird Bilder, ersatzweise Dokumente. Das Sperren des "
            L"Bildschirmschoners während der Animation verhindert dessen Start, solange die Animation "
            L"sichtbar und nicht pausiert ist. Tempo null ist keine Pause. Die Installation aus EXE "
            L"entpackt den mitgelieferten SCR und wählt ihn als Windows-Bildschirmschoner aus. "
            L"Installation und Deinstallation können Administratorrechte erfordern; die Statusleiste zeigt "
            L"den Vorgang bis zum Abschluss an. Bei blockierter Entfernung den laufenden Schoner, seine "
            L"Einstellungen und die Windows-Vorschau "
            L"schließen.\r\n\r\nWINDOWS-BILDSCHIRMSCHONER\r\nGameOfLife.scr nutzt alle Bildschirme mit "
            L"getrennten Einstellungen von EXE. Vorschau aktivieren startet die Vollbildanimation bei "
            L"geöffneten Einstellungen. Die kleine Windows-Vorschau verkleinert die ganze Welt. OK "
            L"speichert; Abbrechen oder Esc verwirft Änderungen. Mausbewegung oder eine Taste beendet den "
            L"Vollbildschoner. MP4-Aufnahme steht in EXE bereit.\r\n\r\nFENSTERPOSITIONEN UND "
            L"ZUSTAND\r\nBeim Schließen werden die Positionen von Haupt- und Infofenster getrennt "
            L"gespeichert; bei der Hilfe auch Größe und normaler oder maximierter Zustand vor einer "
            L"Minimierung. Dies ist unabhängig vom Bestätigen der Anwendungseinstellungen. Das Beenden der "
            L"Anwendung schließt auch Hilfe und Info.\r\n\r\nDARSTELLUNG UND MUSTERLIZENZEN\r\nEntwicklung "
            L"und Vergleiche sichtbarer Zustände laufen über Direct3D-11-Shader auf der GPU; bei "
            L"fehlgeschlagener Hardwareinitialisierung steht Softwaredarstellung bereit. Jeder Bildschirm "
            L"nutzt den bewährten Framepacer bei seiner Bildwiederholrate. MP4 benötigt Media Foundation "
            L"und einen H.264-Encoder. Muster stammen aus LifeWiki (GFDL 1.2 oder neuer) und Alan Hensels "
            L"gemeinfreien Sammlungen. Der Programmcode steht unter MIT; Hinweise und Lizenzen des "
            L"Katalogs gelten gesondert.\r\n\r\nWindows-Bildschirmschoner… öffnet die "
            L"Bildschirmschonereinstellungen des Systems."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nREGELN\r\nConways Spiel des Lebens verwendet B3/S23. Eine tote Zelle wird "
            L"bei genau drei lebenden Nachbarn geboren; eine lebende überlebt bei zwei oder drei. Die acht "
            L"Nachbarn schließen Diagonalen ein. Alle Zellen ändern sich gleichzeitig. Gegenüberliegende "
            L"Ränder sind verbunden: links mit rechts, oben mit unten.\r\n\r\nBILDSCHIRME UND GEMEINSAME "
            L"WELT\r\nDie Kontrollkästchen in EXE aktivieren Bildschirme; Einstellungen gelten für die "
            L"gemeinsame Welt. Ein einziger aktiver Bildschirm enthält die gesamte Welt. Bei einer "
            L"Teilauswahl entfallen vollständig leere Zeilen und Spalten: Nach Abschalten des mittleren "
            L"schließen der linke und rechte Bildschirm aneinander an. Nicht entfernbare innere Lücken "
            L"bleiben Teil der Simulation. Alle ausgewählten Bildschirme sowie SCR bewahren das "
            L"umschließende Desktop-Rechteck einschließlich unsichtbarer Lücken. Jeder Bildschirm zeigt "
            L"seinen Ausschnitt derselben Simulation.\r\n\r\nANFANGSZUSTAND UND MUSTER\r\nStandard ist "
            L"Zufallsrauschen mit 25 % lebenden Zellen. Die Anfangsdichte von 0–100 % gilt beim nächsten "
            L"Neustart. Nur bekannte Muster verwendet 4.106 mitgelieferte Muster ohne Rauschen und "
            L"deaktiviert die Dichte. Wählen Sie eine Mischung oder einen Namen; Maße sind in Zellen "
            L"angegeben. Tippen sucht im Verzeichnis. Nur vollständig passende Muster erscheinen. Kleine "
            L"geprüfte Muster werden in getrennten Kopien verteilt, große oder komplexe einmal mittig. "
            L"Nach Verkleinern kann eine unpassende Auswahl durch eine Mischung ersetzt werden. Modus- "
            L"oder Musterwechsel erzeugen eine neue Szene. Neustarts behalten die Auswahl; der Katalog "
            L"funktioniert offline.\r\n\r\nZELLGRÖSSE, RASTER UND FARBEN\r\nOhne Raster beträgt die "
            L"Zellgröße 1–64 px. Raster anzeigen fügt innerhalb des bisherigen Abstands einen Rand von 1 "
            L"px ein: Anzeige und Schieber sinken um eins, nutzbar sind 1–63. Ausschalten stellt den Wert "
            L"wieder her. Der Schieber behält seinen Bereich und springt vom unzulässigen Ende zurück; das "
            L"Kästchen bleibt bedienbar. Umschalten bewahrt die Szene, außer beim Einschalten bei 1 px: "
            L"Dann entstehen 2 px Abstand und eine neue Szene. Änderungen an Zellgröße oder Bildschirmen "
            L"beginnen ebenfalls neu. Sehr große Welten können einen höheren Mindestwert erfordern. Zell-, "
            L"Hintergrund- und Rasterfarbe ändern sich unabhängig ohne Neustart. Die zufällige Farbe "
            L"lebender Zellen wird bei jedem manuellen oder automatischen Szenenneustart neu gewählt. Die "
            L"gespeicherte Farbe bleibt erhalten und wird beim Ausschalten dieser Option "
            L"wiederhergestellt. Dasselbe Verhalten lässt sich getrennt für Hintergrund und Raster "
            L"aktivieren; beide neuen Optionen sind standardmäßig aus.\r\n\r\nTEMPO, PAUSE UND "
            L"AUTOMATISCHER NEUSTART\r\nDas Tempo beträgt 0–240 Generationen/s unabhängig von der "
            L"Bildwiederholrate; 0 hält die Entwicklung an. Pause und Fortsetzen bewahren die Welt. "
            L"Neustart beginnt im gewählten Modus neu. Der optionale automatische Neustart erkennt "
            L"statische und exakt wiederkehrende sichtbare Phasen einschließlich Oszillatoren. Verglichen "
            L"werden Generationen statt Sekunden; unsichtbare Bereiche bleiben unberücksichtigt. "
            L"Asynchrone Ergebnisse können den Neustart etwas verzögern. Vorgaben: 8 px Abstand, 20 "
            L"Generationen/s, zufällige Farben lebender Zellen und automatischer Neustart ein. Das Raster "
            L"ist standardmäßig ausgeschaltet. Die erreichte Geschwindigkeit hängt von Leistung und "
            L"Zellzahl ab. Der automatische Neustart prüft die Bereiche aktivierter Bildschirme; Lücken "
            L"entwickeln sich weiter, werden aber nicht verglichen.\r\n\r\nWerte "
            L"zurücksetzen\r\nZurücksetzen stellt die angezeigte Zellgröße mit und ohne Raster auf 8 px "
            L"(Abstand 9 bzw. 8 px), das Tempo auf 20 Generationen/s, die Dichte auf 25 % und die drei "
            L"Standardfarben wieder her. Andere Einstellungen bleiben erhalten; ein nicht mehr passendes "
            L"Muster wird durch die Mischung ersetzt. Nur ein geänderter Abstand oder eine geänderte "
            L"Dichte im Rauschmodus erzeugt eine neue "
            L"Szene.\r\n\r\nWINDOWS-BILDSCHIRMSCHONER\r\nGameOfLife.scr nutzt alle Bildschirme mit "
            L"getrennten Einstellungen von EXE. Vorschau aktivieren startet die Vollbildanimation bei "
            L"geöffneten Einstellungen. Die kleine Windows-Vorschau verkleinert die ganze Welt. OK "
            L"speichert; Abbrechen oder Esc verwirft Änderungen. Mausbewegung oder eine Taste beendet den "
            L"Vollbildschoner. MP4-Aufnahme steht in EXE bereit.\r\n\r\nFENSTERPOSITIONEN UND "
            L"ZUSTAND\r\nBeim Schließen werden die Positionen von Haupt- und Infofenster getrennt "
            L"gespeichert; bei der Hilfe auch Größe und normaler oder maximierter Zustand vor einer "
            L"Minimierung. Dies ist unabhängig vom Bestätigen der Anwendungseinstellungen. Das Beenden der "
            L"Anwendung schließt auch Hilfe und Info.\r\n\r\nDARSTELLUNG UND MUSTERLIZENZEN\r\nEntwicklung "
            L"und Vergleiche sichtbarer Zustände laufen über Direct3D-11-Shader auf der GPU; bei "
            L"fehlgeschlagener Hardwareinitialisierung steht Softwaredarstellung bereit. Jeder Bildschirm "
            L"nutzt den bewährten Framepacer bei seiner Bildwiederholrate. MP4 benötigt Media Foundation "
            L"und einen H.264-Encoder. Muster stammen aus LifeWiki (GFDL 1.2 oder neuer) und Alan Hensels "
            L"gemeinfreien Sammlungen. Der Programmcode steht unter MIT; Hinweise und Lizenzen des "
            L"Katalogs gelten gesondert."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Zellgröße: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Tempo: %u Generationen/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Anfangsdichte: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Szene neu starten" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Farbe lebender Zellen…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Hintergrundfarbe…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Ausgewählte Bildschirme teilen eine Welt. Leere Streifen entfallen, innere Lücken bleiben."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animation läuft…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animation ist angehalten."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Direct3D-Renderer konnte nicht initialisiert werden."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Vorschau einschalten"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Vorschau ausschalten"
        },
        LocalizedText{ TXT_MONITOR,
            L"Monitor"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Auflösung"
        },
        LocalizedText{ TXT_POSITION,
            L"Position"
        },
        LocalizedText{ TXT_PRIMARY,
            L"primär"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Monitormodell"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Bildwiederholfrequenz"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bittiefe"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Farbformat"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Farbraum"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u Bit/Kanal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u Bit/Pixel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Animationsmonitor"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Bereit"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Raster anzeigen"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Rasterfarbe…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Statische oder wiederkehrende sichtbare Szene automatisch neu starten"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Nur bekannte Muster"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Aufnahme starten…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Aufnahme beenden"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4-Aufnahme läuft…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Aufnahme wurde gespeichert."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"MP4-Aufnahme konnte nicht gestartet werden."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Beim Beenden der Anwendung wird die laufende Aufnahme beendet."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Aufnahmeeinstellungen"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Auflösung:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Bildfrequenz:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Änderungen gelten für die nächste MP4-Aufnahme."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Mischung geeigneter Muster"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Das gewählte Muster passt nicht mehr. Eine geeignete Mischung wurde ausgewählt."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Der Katalog bekannter Muster konnte nicht geladen werden."
        },
    }),
    DefineLanguage(LANG_FR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Couleur de fond aléatoire à chaque redémarrage de la scène"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR,
            L"Couleur de grille aléatoire à chaque redémarrage de la scène"
        },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Écran de veille Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Impossible d’ouvrir les paramètres de l’écran de veille Windows."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Réinitialiser les valeurs" },
        LocalizedText{ TXT_SNAPSHOT, L"Capture…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"La capture a été enregistrée." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Impossible d’enregistrer la capture." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Bloquer l’écran de veille pendant l’animation" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Couleur aléatoire des cellules vivantes à chaque réinitialisation de la scène"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Installation de l’économiseur d’écran en cours…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Désinstallation de l’économiseur d’écran en cours…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Installer l’économiseur" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Désinstaller l’économiseur" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"L’économiseur n’a pas été installé." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"L’économiseur a été installé." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"L’économiseur a été désinstallé." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Impossible de désinstaller l’économiseur. S’il est en cours d’exécution ou si son aperçu est "
            L"ouvert, fermez-le puis réessayez."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"La désinstallation a échoué car les paramètres de GameOfLife sont ouverts. Fermez cette "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Français"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Commandes"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Paramètres de GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Langue :"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Annuler"
        },
        LocalizedText{ TXT_EXIT,
            L"Quitter"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pause"
        },
        LocalizedText{ TXT_RESUME,
            L"Reprendre"
        },
        LocalizedText{ TXT_HELP,
            L"Aide"
        },
        LocalizedText{ TXT_ABOUT,
            L"À propos"
        },
        LocalizedText{ TXT_CLOSE,
            L"Fermer"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Visiter le site web %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Impossible d’ouvrir le site dans le navigateur par défaut."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Impossible de copier l’URL dans le presse-papiers."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Impossible de copier les informations dans le presse-papiers."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Le jeu de la vie de Conway dans un monde commun à plusieurs écrans."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Version :"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Plateforme cible :"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Site web :"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Ouvrir dans le navigateur par défaut"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Copier l’&URL"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Copier les &informations"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"La ressource de licence est indisponible."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nRÈGLES\r\nLe jeu de la vie de Conway suit B3/S23. Une cellule morte naît "
            L"avec exactement trois voisines vivantes ; une cellule vivante survit avec deux ou trois. Les "
            L"huit voisines incluent les diagonales. Toutes évoluent simultanément. Les bords opposés se "
            L"rejoignent : gauche et droite, haut et bas.\r\n\r\nÉCRANS ET MONDE COMMUN\r\nLes cases de "
            L"EXE activent les écrans ; les réglages concernent le monde commun. Un seul écran actif "
            L"contient le monde entier. Avec une partie des écrans, les lignes et colonnes entièrement "
            L"vides sont retirées : les écrans gauche et droit se rejoignent si celui du milieu est "
            L"désactivé. Les trous intérieurs impossibles à supprimer restent simulés. Tous les écrans "
            L"sélectionnés, ou SCR, conservent le rectangle du bureau avec ses espaces invisibles. Chaque "
            L"écran montre sa région de la même simulation.\r\n\r\nÉTAT INITIAL ET MOTIFS\r\nLe départ par "
            L"défaut est un bruit aléatoire à 25 % de cellules vivantes. La densité initiale, de 0–100 %, "
            L"agit au prochain redémarrage. Motifs connus uniquement utilise 4 106 motifs intégrés sans "
            L"bruit et désactive la densité. Choisissez un mélange ou un motif nommé ; les dimensions sont "
            L"en cellules. Saisissez un nom pour chercher. Seuls les motifs tenant entièrement sont "
            L"proposés. Les petits motifs vérifiés sont répartis en copies séparées, les grands ou "
            L"complexes une fois au centre. Réduire le monde peut remplacer une sélection devenue trop "
            L"grande par un mélange. Changer de mode ou de motif recrée la scène. Les redémarrages "
            L"conservent le choix ; le catalogue fonctionne hors ligne.\r\n\r\nCELLULES, GRILLE ET "
            L"COULEURS\r\nSans grille, la taille est de 1–64 px. Afficher la grille ajoute un bord de 1 px "
            L"dans l'espacement existant : la valeur affichée et le curseur diminuent de un, avec 1–63 "
            L"utilisables. Désactiver rétablit la valeur. Le curseur conserve toute sa plage et revient "
            L"depuis l'extrémité indisponible ; la case reste active. La scène est conservée, sauf en "
            L"activant à 1 px : l'espacement passe à 2 px et une nouvelle scène commence. Changer la "
            L"taille ou les écrans recrée aussi la scène. Un très grand monde peut imposer un minimum "
            L"supérieur. Les couleurs des cellules, du fond et de la grille changent séparément sans "
            L"redémarrage. La couleur aléatoire des cellules vivantes change à chaque redémarrage manuel "
            L"ou automatique de la scène. Votre couleur enregistrée reste intacte et revient lorsque cette "
            L"option est désactivée. Le même comportement peut être activé séparément pour le fond et la "
            L"grille ; ces deux nouvelles options sont désactivées par défaut.\r\n\r\nVITESSE, PAUSE ET "
            L"REDÉMARRAGE AUTOMATIQUE\r\nLa vitesse est de 0–240 générations/s indépendamment du "
            L"rafraîchissement ; 0 arrête l'évolution. Pause et Reprendre conservent le monde. Recommencer "
            L"réinitialise le mode choisi. Le redémarrage automatique facultatif détecte les phases "
            L"visibles fixes ou exactement répétitives, dont les oscillateurs. Il compare les générations, "
            L"pas les secondes ; les zones invisibles sont exclues. Les résultats asynchrones peuvent "
            L"retarder légèrement le redémarrage. Valeurs par défaut : espacement 8 px, 20 générations/s, "
            L"couleur aléatoire des cellules vivantes et redémarrage automatique activés. La grille est "
            L"désactivée par défaut. La vitesse atteinte dépend des performances et du nombre de cellules. "
            L"Le redémarrage automatique compare les régions des écrans activés ; les espaces entre eux "
            L"continuent d’évoluer mais sont exclus des comparaisons.\r\n\r\nRéinitialiser les "
            L"valeurs\r\nLa réinitialisation rétablit une taille affichée de 8 px avec ou sans grille "
            L"(espacement de 9 ou 8 px), 20 générations/s, une densité de 25 % et les trois couleurs par "
            L"défaut. Les autres choix sont conservés ; un motif devenu trop grand est remplacé par le "
            L"mélange. Une nouvelle scène apparaît seulement si l’espacement change ou si la densité "
            L"change en mode bruit.\r\n\r\nAPPLICATION AUTONOME ET ENREGISTREMENT MP4\r\nEXE enregistre "
            L"les réglages en continu et le premier écran actif en MP4. Le dossier proposé est Vidéos, "
            L"sinon Documents. Viewport utilise les dimensions et la fréquence de l'écran jusqu'à 60 "
            L"images/s. TV propose 1920 × 1080, 1440 × 1080 ou 1280 × 720 en 16:9 à 50, 25, 59,94 "
            L"(60000/1001) ou 29,97 (30000/1001) images/s. Les proportions sont conservées ; TV utilise "
            L"BT.709 progressif à plage limitée en 4:2:0. La fenêtre indépendante des réglages peut être "
            L"réduite. OK valide pour le prochain enregistrement ; Annuler ou Esc abandonne les "
            L"modifications non validées. L'écran enregistré ne peut être désactivé ; les autres sorties "
            L"peuvent changer. Quitter pendant l'enregistrement demande confirmation. Avec l'animation "
            L"active, Espace bascule la pause, F9 : Démarrer l’enregistrement ; F10 : Arrêter "
            L"l’enregistrement. Le pointeur disparaît après 1 seconde d'inactivité et réapparaît en "
            L"bougeant. Tab/Shift+Tab parcourt les commandes ; Alt active les lettres soulignées. Esc "
            L"ferme Aide/À propos, ou quitte depuis la fenêtre principale.\r\n\r\nCAPTURE ET GESTION DE "
            L"L’ÉCRAN DE VEILLE DANS EXE\r\nLa capture sauvegarde en BMP/GIF/JPEG/PNG/TIFF/WebP l’écran en "
            L"cours "
            L"d’enregistrement, sinon le premier écran actif, à sa résolution et sans redémarrer la scène. "
            L"Le dossier proposé est Images, sinon Documents. Bloquer l’écran de veille pendant "
            L"l’animation empêche son lancement tant que l’animation est visible et non suspendue. Une "
            L"vitesse nulle n’est pas une pause. L’installation depuis EXE extrait le SCR intégré et le "
            L"sélectionne comme écran de veille Windows. Installation et désinstallation peuvent "
            L"nécessiter l’accord d’un administrateur ; la barre d’état indique l’opération jusqu’à sa "
            L"fin. Si la suppression est bloquée, fermez l’écran de veille en cours, ses réglages et "
            L"l’aperçu Windows.\r\n\r\nÉCRAN DE VEILLE WINDOWS\r\nGameOfLife.scr utilise tous les écrans "
            L"avec des réglages distincts de EXE. Activer l'aperçu lance l'animation plein écran en "
            L"gardant les réglages ouverts. Le petit aperçu Windows réduit le monde entier. OK enregistre "
            L"; Annuler ou Esc abandonne les changements. Un mouvement de souris ou une touche quitte "
            L"l'écran de veille plein écran. L'enregistrement MP4 est disponible dans EXE.\r\n\r\nPOSITION "
            L"ET ÉTAT DES FENÊTRES\r\nLa fermeture enregistre séparément la position de la fenêtre "
            L"principale et d’À propos ; l’aide conserve aussi sa taille et son état normal ou agrandi "
            L"avant une éventuelle réduction. Cela ne dépend pas de la validation des réglages de "
            L"l’application. Quitter l’application ferme aussi l’aide et À propos.\r\n\r\nRENDU ET "
            L"LICENCES DES MOTIFS\r\nL'évolution et les comparaisons visibles utilisent les shaders "
            L"Direct3D 11 sur GPU ; un rendu logiciel est disponible si l'initialisation matérielle "
            L"échoue. Chaque écran utilise le même régulateur de trames éprouvé à sa fréquence. MP4 "
            L"nécessite Media Foundation et un encodeur H.264. Les motifs proviennent de LifeWiki (GFDL "
            L"1.2 ou ultérieure) et des collections du domaine public d'Alan Hensel. Le code est sous "
            L"licence MIT ; les mentions et licences du catalogue sont distinctes.\r\n\r\nÉcran de veille "
            L"Windows… ouvre les paramètres système de l’écran de veille."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nRÈGLES\r\nLe jeu de la vie de Conway suit B3/S23. Une cellule morte naît "
            L"avec exactement trois voisines vivantes ; une cellule vivante survit avec deux ou trois. Les "
            L"huit voisines incluent les diagonales. Toutes évoluent simultanément. Les bords opposés se "
            L"rejoignent : gauche et droite, haut et bas.\r\n\r\nÉCRANS ET MONDE COMMUN\r\nLes cases de "
            L"EXE activent les écrans ; les réglages concernent le monde commun. Un seul écran actif "
            L"contient le monde entier. Avec une partie des écrans, les lignes et colonnes entièrement "
            L"vides sont retirées : les écrans gauche et droit se rejoignent si celui du milieu est "
            L"désactivé. Les trous intérieurs impossibles à supprimer restent simulés. Tous les écrans "
            L"sélectionnés, ou SCR, conservent le rectangle du bureau avec ses espaces invisibles. Chaque "
            L"écran montre sa région de la même simulation.\r\n\r\nÉTAT INITIAL ET MOTIFS\r\nLe départ par "
            L"défaut est un bruit aléatoire à 25 % de cellules vivantes. La densité initiale, de 0–100 %, "
            L"agit au prochain redémarrage. Motifs connus uniquement utilise 4 106 motifs intégrés sans "
            L"bruit et désactive la densité. Choisissez un mélange ou un motif nommé ; les dimensions sont "
            L"en cellules. Saisissez un nom pour chercher. Seuls les motifs tenant entièrement sont "
            L"proposés. Les petits motifs vérifiés sont répartis en copies séparées, les grands ou "
            L"complexes une fois au centre. Réduire le monde peut remplacer une sélection devenue trop "
            L"grande par un mélange. Changer de mode ou de motif recrée la scène. Les redémarrages "
            L"conservent le choix ; le catalogue fonctionne hors ligne.\r\n\r\nCELLULES, GRILLE ET "
            L"COULEURS\r\nSans grille, la taille est de 1–64 px. Afficher la grille ajoute un bord de 1 px "
            L"dans l'espacement existant : la valeur affichée et le curseur diminuent de un, avec 1–63 "
            L"utilisables. Désactiver rétablit la valeur. Le curseur conserve toute sa plage et revient "
            L"depuis l'extrémité indisponible ; la case reste active. La scène est conservée, sauf en "
            L"activant à 1 px : l'espacement passe à 2 px et une nouvelle scène commence. Changer la "
            L"taille ou les écrans recrée aussi la scène. Un très grand monde peut imposer un minimum "
            L"supérieur. Les couleurs des cellules, du fond et de la grille changent séparément sans "
            L"redémarrage. La couleur aléatoire des cellules vivantes change à chaque redémarrage manuel "
            L"ou automatique de la scène. Votre couleur enregistrée reste intacte et revient lorsque cette "
            L"option est désactivée. Le même comportement peut être activé séparément pour le fond et la "
            L"grille ; ces deux nouvelles options sont désactivées par défaut.\r\n\r\nVITESSE, PAUSE ET "
            L"REDÉMARRAGE AUTOMATIQUE\r\nLa vitesse est de 0–240 générations/s indépendamment du "
            L"rafraîchissement ; 0 arrête l'évolution. Pause et Reprendre conservent le monde. Recommencer "
            L"réinitialise le mode choisi. Le redémarrage automatique facultatif détecte les phases "
            L"visibles fixes ou exactement répétitives, dont les oscillateurs. Il compare les générations, "
            L"pas les secondes ; les zones invisibles sont exclues. Les résultats asynchrones peuvent "
            L"retarder légèrement le redémarrage. Valeurs par défaut : espacement 8 px, 20 générations/s, "
            L"couleur aléatoire des cellules vivantes et redémarrage automatique activés. La grille est "
            L"désactivée par défaut. La vitesse atteinte dépend des performances et du nombre de cellules. "
            L"Le redémarrage automatique compare les régions des écrans activés ; les espaces entre eux "
            L"continuent d’évoluer mais sont exclus des comparaisons.\r\n\r\nRéinitialiser les "
            L"valeurs\r\nLa réinitialisation rétablit une taille affichée de 8 px avec ou sans grille "
            L"(espacement de 9 ou 8 px), 20 générations/s, une densité de 25 % et les trois couleurs par "
            L"défaut. Les autres choix sont conservés ; un motif devenu trop grand est remplacé par le "
            L"mélange. Une nouvelle scène apparaît seulement si l’espacement change ou si la densité "
            L"change en mode bruit.\r\n\r\nÉCRAN DE VEILLE WINDOWS\r\nGameOfLife.scr utilise tous les "
            L"écrans avec des réglages distincts de EXE. Activer l'aperçu lance l'animation plein écran en "
            L"gardant les réglages ouverts. Le petit aperçu Windows réduit le monde entier. OK enregistre "
            L"; Annuler ou Esc abandonne les changements. Un mouvement de souris ou une touche quitte "
            L"l'écran de veille plein écran. L'enregistrement MP4 est disponible dans EXE.\r\n\r\nPOSITION "
            L"ET ÉTAT DES FENÊTRES\r\nLa fermeture enregistre séparément la position de la fenêtre "
            L"principale et d’À propos ; l’aide conserve aussi sa taille et son état normal ou agrandi "
            L"avant une éventuelle réduction. Cela ne dépend pas de la validation des réglages de "
            L"l’application. Quitter l’application ferme aussi l’aide et À propos.\r\n\r\nRENDU ET "
            L"LICENCES DES MOTIFS\r\nL'évolution et les comparaisons visibles utilisent les shaders "
            L"Direct3D 11 sur GPU ; un rendu logiciel est disponible si l'initialisation matérielle "
            L"échoue. Chaque écran utilise le même régulateur de trames éprouvé à sa fréquence. MP4 "
            L"nécessite Media Foundation et un encodeur H.264. Les motifs proviennent de LifeWiki (GFDL "
            L"1.2 ou ultérieure) et des collections du domaine public d'Alan Hensel. Le code est sous "
            L"licence MIT ; les mentions et licences du catalogue sont distinctes."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Taille des cellules : %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Vitesse : %u générations/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Densité initiale : %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Redémarrer la scène" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Couleur des cellules vivantes…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Couleur du fond…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Les écrans choisis partagent un monde. Les bandes vides disparaissent, les trous intérieurs "
            L"restent."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"L’animation est en cours…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"L’animation est en pause."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Impossible d’initialiser le moteur Direct3D."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Activer l’aperçu"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Désactiver l’aperçu"
        },
        LocalizedText{ TXT_MONITOR,
            L"Moniteur"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Résolution"
        },
        LocalizedText{ TXT_POSITION,
            L"Position"
        },
        LocalizedText{ TXT_PRIMARY,
            L"principal"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Modèle du moniteur"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Fréquence de rafraîchissement"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Profondeur de bits"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Format de couleur"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Espace colorimétrique"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bits/canal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bits/pixel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Moniteur d’animation"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Prêt"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Afficher la grille"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Couleur de la grille…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Recommencer automatiquement une scène visible stable ou répétitive"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Motifs connus uniquement"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Démarrer l’enregistrement…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Arrêter l’enregistrement"
        },
        LocalizedText{ TXT_RECORDING,
            L"Enregistrement MP4 en cours…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"L’enregistrement a été sauvegardé."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Impossible de démarrer l’enregistrement MP4."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"La fermeture de l’application arrêtera l’enregistrement en cours."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Réglages vidéo"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Résolution :"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Fréquence d’images :"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Les modifications s’appliquent au prochain enregistrement MP4."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Mélange de motifs adaptés"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Le motif choisi ne tient plus dans le monde. Un mélange adapté a été sélectionné."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Impossible de charger le catalogue de motifs connus."
        },
    }),
    DefineLanguage(LANG_ES, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Color de fondo aleatorio en cada reinicio de la escena"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR,
            L"Color de cuadrícula aleatorio en cada reinicio de la escena"
        },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Salvapantallas de Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"No se puede abrir la configuración del salvapantallas de Windows."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Restablecer valores" },
        LocalizedText{ TXT_SNAPSHOT, L"Captura…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"La captura se guardó." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"No se pudo guardar la captura." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Bloquear salvapantallas durante la animación" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Color aleatorio de las células vivas al reiniciar la escena"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Instalando el salvapantallas…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Desinstalando el salvapantallas…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Instalar salvapantallas" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Desinstalar salvapantallas" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"No se instaló el salvapantallas." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"El salvapantallas se instaló." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"El salvapantallas se desinstaló." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"No se pudo desinstalar el salvapantallas. Si el salvapantallas o su vista previa están en "
            L"ejecución, ciérrelos e inténtelo de nuevo."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"La desinstalación falló porque la configuración de GameOfLife está abierta. Cierre esa "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Español"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Control"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Configuración de GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Idioma:"
        },
        LocalizedText{ TXT_OK,
            L"Aceptar"
        },
        LocalizedText{ TXT_CANCEL,
            L"Cancelar"
        },
        LocalizedText{ TXT_EXIT,
            L"Salir"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pausar"
        },
        LocalizedText{ TXT_RESUME,
            L"Continuar"
        },
        LocalizedText{ TXT_HELP,
            L"Ayuda"
        },
        LocalizedText{ TXT_ABOUT,
            L"Acerca de"
        },
        LocalizedText{ TXT_CLOSE,
            L"Cerrar"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Visitar el sitio web %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"No se puede abrir el sitio en el navegador predeterminado."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"No se pudo copiar la URL al portapapeles."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"No se pudo copiar la información al portapapeles."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"El juego de la vida de Conway en un mundo compartido entre pantallas."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Versión:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Plataforma de destino:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Sitio web:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Abrir en el navegador predeterminado"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Copiar &URL"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Copiar &información"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"El recurso de licencia no está disponible."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nREGLAS\r\nEl juego de la vida de Conway usa B3/S23. Una celda muerta nace "
            L"con exactamente tres vecinas vivas; una viva sobrevive con dos o tres. Las ocho vecinas "
            L"incluyen las diagonales. Todas evolucionan simultáneamente. Los bordes opuestos se conectan: "
            L"izquierda con derecha, arriba con abajo.\r\n\r\nPANTALLAS Y MUNDO COMPARTIDO\r\nLas casillas "
            L"de EXE activan pantallas; los ajustes se aplican al mundo compartido. Una sola pantalla "
            L"activa contiene todo el mundo. Al elegir parte de la disposición se eliminan filas y "
            L"columnas totalmente vacías: izquierda y derecha se unen al desactivar la central. Los huecos "
            L"interiores que no puedan eliminarse siguen en la simulación. Todas las pantallas "
            L"seleccionadas, o SCR, conservan el rectángulo del escritorio y sus huecos invisibles. Cada "
            L"pantalla muestra su región de la misma simulación.\r\n\r\nESTADO INICIAL Y PATRONES\r\nEl "
            L"inicio predeterminado es ruido aleatorio con un 25 % de celdas vivas. La densidad inicial de "
            L"0–100 % se aplica al próximo reinicio. Solo patrones conocidos usa 4.106 patrones incluidos "
            L"sin ruido y desactiva la densidad. Elija una mezcla o un nombre; las dimensiones se expresan "
            L"en celdas. Escriba para buscar. Solo se ofrecen patrones que caben completos. Los pequeños "
            L"verificados se repiten en copias separadas; los grandes o complejos aparecen una vez "
            L"centrados. Reducir el mundo puede sustituir una selección que ya no cabe por una mezcla. "
            L"Cambiar modo o patrón crea otra escena. Los reinicios conservan la elección; el catálogo "
            L"funciona sin conexión.\r\n\r\nCELDAS, CUADRÍCULA Y COLORES\r\nSin cuadrícula, el tamaño es "
            L"1–64 px. Mostrar cuadrícula añade un borde de 1 px dentro del espaciado existente: el valor "
            L"mostrado y el deslizador bajan uno, con 1–63 utilizables. Desactivarla restaura el valor. El "
            L"deslizador conserva su rango y retrocede desde el extremo no disponible; la casilla "
            L"permanece habilitada. Se conserva la escena salvo al activarla con 1 px: el espaciado pasa a "
            L"2 px y se crea otra escena. Cambiar tamaño o pantallas también reinicia. Un mundo muy grande "
            L"puede exigir un mínimo mayor. Los colores de celdas, fondo y cuadrícula cambian por separado "
            L"sin reiniciar. El color aleatorio de las celdas vivas cambia en cada reinicio manual o "
            L"automático de la escena. El color guardado se conserva y vuelve al desactivar esta opción. "
            L"El mismo comportamiento puede activarse por separado para el fondo y la cuadrícula; ambas "
            L"opciones nuevas están desactivadas inicialmente.\r\n\r\nVELOCIDAD, PAUSA Y REINICIO "
            L"AUTOMÁTICO\r\nLa velocidad es 0–240 generaciones/s, independiente del refresco; 0 detiene la "
            L"evolución. Pausa y Reanudar conservan el mundo. Reiniciar vuelve a empezar en el modo "
            L"elegido. El reinicio automático opcional detecta fases visibles estáticas o exactamente "
            L"repetidas, incluidos osciladores. Compara generaciones y no segundos; excluye áreas "
            L"invisibles. Los resultados asíncronos pueden retrasar ligeramente el reinicio. Valores "
            L"iniciales: espaciado 8 px, 20 generaciones/s, color aleatorio de células vivas y reinicio "
            L"automático activados. La cuadrícula está desactivada de forma predeterminada. La velocidad "
            L"alcanzada depende del rendimiento y del número de celdas. El reinicio automático compara las "
            L"regiones de las pantallas activadas; los huecos siguen evolucionando, pero no se incluyen en "
            L"la comparación.\r\n\r\nRestablecer valores\r\nEl restablecimiento fija el tamaño mostrado en "
            L"8 px con o sin cuadrícula (espaciado de 9 u 8 px), la velocidad en 20 generaciones/s, la "
            L"densidad en el 25 % y los tres colores predeterminados. Conserva las demás opciones; un "
            L"patrón que ya no quepa se sustituye por la mezcla. Solo se crea otra escena si cambia el "
            L"espaciado o la densidad en modo de ruido.\r\n\r\nAPLICACIÓN INDEPENDIENTE Y GRABACIÓN "
            L"MP4\r\nEXE guarda ajustes continuamente y graba la primera pantalla activa en MP4. Propone "
            L"Vídeos o, en su defecto, Documentos. Viewport usa dimensiones y refresco de pantalla hasta "
            L"60 fotogramas/s. TV ofrece 1920 × 1080, 1440 × 1080 o 1280 × 720 en 16:9 a 50, 25, 59,94 "
            L"(60000/1001) o 29,97 (30000/1001) fotogramas/s. Se conserva la proporción; TV usa BT.709 "
            L"progresivo de rango limitado y 4:2:0. La ventana independiente de ajustes puede minimizarse. "
            L"Aceptar guarda para la próxima grabación; Cancelar o Esc descarta cambios pendientes. No "
            L"puede desactivarse la pantalla grabada; las demás salidas sí pueden cambiar. Salir durante "
            L"una grabación requiere confirmación. Con la animación enfocada, Espacio alterna la pausa, "
            L"F9: Iniciar grabación; F10: Detener grabación. El cursor se oculta tras 1 segundo inactivo y "
            L"reaparece al moverlo. Tab/Shift+Tab recorre controles; Alt activa comandos subrayados. Esc "
            L"cierra Ayuda/Acerca de, o sale desde la ventana principal.\r\n\r\nCAPTURA Y GESTIÓN DEL "
            L"PROTECTOR EN EXE\r\nLa captura guarda en BMP/GIF/JPEG/PNG/TIFF/WebP la pantalla que se está "
            L"grabando o, en su "
            L"defecto, la primera activa, a su resolución y sin reiniciar la escena. Se propone Imágenes, "
            L"o Documentos como alternativa. Bloquear el protector durante la animación impide que se "
            L"inicie mientras la animación esté visible y no pausada. Velocidad cero no equivale a pausa. "
            L"La instalación desde EXE extrae el SCR incluido y lo selecciona como protector de Windows. "
            L"Instalar y desinstalar puede requerir autorización de administrador; la barra de estado "
            L"muestra la operación hasta que termine. Si la eliminación está bloqueada, cierre el "
            L"protector en ejecución, sus ajustes y la vista previa de Windows.\r\n\r\nPROTECTOR DE "
            L"PANTALLA DE WINDOWS\r\nGameOfLife.scr usa todas las pantallas y ajustes separados de EXE. "
            L"Activar vista previa inicia la animación completa con ajustes abiertos. La vista pequeña de "
            L"Windows reduce todo el mundo. Aceptar guarda; Cancelar o Esc descarta cambios. Mover el "
            L"ratón o pulsar una tecla cierra el protector completo. La grabación MP4 está disponible en "
            L"EXE.\r\n\r\nPOSICIÓN Y ESTADO DE LAS VENTANAS\r\nAl cerrar se guardan por separado las "
            L"posiciones de la ventana principal y Acerca de; Ayuda conserva además su tamaño y el estado "
            L"normal o maximizado anterior a la minimización. Esto es independiente de confirmar los "
            L"ajustes de la aplicación. Salir de la aplicación también cierra Ayuda y Acerca "
            L"de.\r\n\r\nRENDERIZADO Y LICENCIAS DE PATRONES\r\nLa evolución y comparación visible usan "
            L"sombreadores Direct3D 11 en GPU; hay renderizado por software si falla la inicialización del "
            L"hardware. Cada pantalla usa el regulador de fotogramas probado a su propio refresco. MP4 "
            L"necesita Media Foundation y un codificador H.264. Los patrones proceden de LifeWiki (GFDL "
            L"1.2 o posterior) y de las colecciones de dominio público de Alan Hensel. El código usa MIT; "
            L"los avisos y licencias del catálogo son independientes.\r\n\r\nSalvapantallas de Windows… "
            L"abre la configuración del salvapantallas del sistema."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nREGLAS\r\nEl juego de la vida de Conway usa B3/S23. Una celda muerta nace "
            L"con exactamente tres vecinas vivas; una viva sobrevive con dos o tres. Las ocho vecinas "
            L"incluyen las diagonales. Todas evolucionan simultáneamente. Los bordes opuestos se conectan: "
            L"izquierda con derecha, arriba con abajo.\r\n\r\nPANTALLAS Y MUNDO COMPARTIDO\r\nLas casillas "
            L"de EXE activan pantallas; los ajustes se aplican al mundo compartido. Una sola pantalla "
            L"activa contiene todo el mundo. Al elegir parte de la disposición se eliminan filas y "
            L"columnas totalmente vacías: izquierda y derecha se unen al desactivar la central. Los huecos "
            L"interiores que no puedan eliminarse siguen en la simulación. Todas las pantallas "
            L"seleccionadas, o SCR, conservan el rectángulo del escritorio y sus huecos invisibles. Cada "
            L"pantalla muestra su región de la misma simulación.\r\n\r\nESTADO INICIAL Y PATRONES\r\nEl "
            L"inicio predeterminado es ruido aleatorio con un 25 % de celdas vivas. La densidad inicial de "
            L"0–100 % se aplica al próximo reinicio. Solo patrones conocidos usa 4.106 patrones incluidos "
            L"sin ruido y desactiva la densidad. Elija una mezcla o un nombre; las dimensiones se expresan "
            L"en celdas. Escriba para buscar. Solo se ofrecen patrones que caben completos. Los pequeños "
            L"verificados se repiten en copias separadas; los grandes o complejos aparecen una vez "
            L"centrados. Reducir el mundo puede sustituir una selección que ya no cabe por una mezcla. "
            L"Cambiar modo o patrón crea otra escena. Los reinicios conservan la elección; el catálogo "
            L"funciona sin conexión.\r\n\r\nCELDAS, CUADRÍCULA Y COLORES\r\nSin cuadrícula, el tamaño es "
            L"1–64 px. Mostrar cuadrícula añade un borde de 1 px dentro del espaciado existente: el valor "
            L"mostrado y el deslizador bajan uno, con 1–63 utilizables. Desactivarla restaura el valor. El "
            L"deslizador conserva su rango y retrocede desde el extremo no disponible; la casilla "
            L"permanece habilitada. Se conserva la escena salvo al activarla con 1 px: el espaciado pasa a "
            L"2 px y se crea otra escena. Cambiar tamaño o pantallas también reinicia. Un mundo muy grande "
            L"puede exigir un mínimo mayor. Los colores de celdas, fondo y cuadrícula cambian por separado "
            L"sin reiniciar. El color aleatorio de las celdas vivas cambia en cada reinicio manual o "
            L"automático de la escena. El color guardado se conserva y vuelve al desactivar esta opción. "
            L"El mismo comportamiento puede activarse por separado para el fondo y la cuadrícula; ambas "
            L"opciones nuevas están desactivadas inicialmente.\r\n\r\nVELOCIDAD, PAUSA Y REINICIO "
            L"AUTOMÁTICO\r\nLa velocidad es 0–240 generaciones/s, independiente del refresco; 0 detiene la "
            L"evolución. Pausa y Reanudar conservan el mundo. Reiniciar vuelve a empezar en el modo "
            L"elegido. El reinicio automático opcional detecta fases visibles estáticas o exactamente "
            L"repetidas, incluidos osciladores. Compara generaciones y no segundos; excluye áreas "
            L"invisibles. Los resultados asíncronos pueden retrasar ligeramente el reinicio. Valores "
            L"iniciales: espaciado 8 px, 20 generaciones/s, color aleatorio de células vivas y reinicio "
            L"automático activados. La cuadrícula está desactivada de forma predeterminada. La velocidad "
            L"alcanzada depende del rendimiento y del número de celdas. El reinicio automático compara las "
            L"regiones de las pantallas activadas; los huecos siguen evolucionando, pero no se incluyen en "
            L"la comparación.\r\n\r\nRestablecer valores\r\nEl restablecimiento fija el tamaño mostrado en "
            L"8 px con o sin cuadrícula (espaciado de 9 u 8 px), la velocidad en 20 generaciones/s, la "
            L"densidad en el 25 % y los tres colores predeterminados. Conserva las demás opciones; un "
            L"patrón que ya no quepa se sustituye por la mezcla. Solo se crea otra escena si cambia el "
            L"espaciado o la densidad en modo de ruido.\r\n\r\nPROTECTOR DE PANTALLA DE "
            L"WINDOWS\r\nGameOfLife.scr usa todas las pantallas y ajustes separados de EXE. Activar vista "
            L"previa inicia la animación completa con ajustes abiertos. La vista pequeña de Windows reduce "
            L"todo el mundo. Aceptar guarda; Cancelar o Esc descarta cambios. Mover el ratón o pulsar una "
            L"tecla cierra el protector completo. La grabación MP4 está disponible en EXE.\r\n\r\nPOSICIÓN "
            L"Y ESTADO DE LAS VENTANAS\r\nAl cerrar se guardan por separado las posiciones de la ventana "
            L"principal y Acerca de; Ayuda conserva además su tamaño y el estado normal o maximizado "
            L"anterior a la minimización. Esto es independiente de confirmar los ajustes de la aplicación. "
            L"Salir de la aplicación también cierra Ayuda y Acerca de.\r\n\r\nRENDERIZADO Y LICENCIAS DE "
            L"PATRONES\r\nLa evolución y comparación visible usan sombreadores Direct3D 11 en GPU; hay "
            L"renderizado por software si falla la inicialización del hardware. Cada pantalla usa el "
            L"regulador de fotogramas probado a su propio refresco. MP4 necesita Media Foundation y un "
            L"codificador H.264. Los patrones proceden de LifeWiki (GFDL 1.2 o posterior) y de las "
            L"colecciones de dominio público de Alan Hensel. El código usa MIT; los avisos y licencias del "
            L"catálogo son independientes."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Tamaño de celda: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Velocidad: %u generaciones/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Densidad inicial: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Reiniciar escena" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Color de celdas vivas…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Color del fondo…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Las pantallas elegidas comparten un mundo. Se eliminan bandas vacías; permanecen huecos "
            L"interiores."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"La animación está activa…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"La animación está en pausa."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"No se pudo inicializar Direct3D."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Activar vista previa"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Desactivar vista previa"
        },
        LocalizedText{ TXT_MONITOR,
            L"Monitor"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Resolución"
        },
        LocalizedText{ TXT_POSITION,
            L"Posición"
        },
        LocalizedText{ TXT_PRIMARY,
            L"principal"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Modelo del monitor"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Frecuencia de actualización"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Profundidad de bits"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Formato de color"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Espacio de color"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bits/canal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bits/píxel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Monitor de animación"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Listo"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Mostrar cuadrícula"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Color de cuadrícula…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Reiniciar automáticamente una escena visible estable o repetitiva"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Solo patrones conocidos"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Iniciar grabación…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Detener grabación"
        },
        LocalizedText{ TXT_RECORDING,
            L"Grabando MP4…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"La grabación se guardó."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"No se pudo iniciar la grabación MP4."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Al cerrar la aplicación se detendrá la grabación en curso."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Ajustes de grabación"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Resolución:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Frecuencia de imagen:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Los cambios se aplican a la próxima grabación MP4."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Mezcla de patrones adecuados"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"El patrón elegido ya no cabe. Se ha seleccionado una mezcla adecuada."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"No se pudo cargar el catálogo de patrones conocidos."
        },
    }),
    DefineLanguage(LANG_IT, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Colore di sfondo casuale a ogni riavvio della scena" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Colore della griglia casuale a ogni riavvio della scena" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Salvaschermo di Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Impossibile aprire le impostazioni del salvaschermo di Windows."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Ripristina valori" },
        LocalizedText{ TXT_SNAPSHOT, L"Istantanea…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"L’istantanea è stata salvata." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Impossibile salvare l’istantanea." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blocca salvaschermo durante l’animazione" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Colore casuale delle cellule vive a ogni riavvio della scena"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Installazione del salvaschermo in corso…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Disinstallazione del salvaschermo in corso…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Installa salvaschermo" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Disinstalla salvaschermo" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Il salvaschermo non è stato installato." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Il salvaschermo è stato installato." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Il salvaschermo è stato disinstallato." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Impossibile disinstallare il salvaschermo. Se il salvaschermo o la relativa anteprima sono in "
            L"esecuzione, chiuderli e riprovare."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"La disinstallazione non è riuscita perché le impostazioni di GameOfLife sono aperte. "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Italiano"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Controlli"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Impostazioni di GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Lingua:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Annulla"
        },
        LocalizedText{ TXT_EXIT,
            L"Esci"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pausa"
        },
        LocalizedText{ TXT_RESUME,
            L"Riprendi"
        },
        LocalizedText{ TXT_HELP,
            L"Guida"
        },
        LocalizedText{ TXT_ABOUT,
            L"Informazioni"
        },
        LocalizedText{ TXT_CLOSE,
            L"Chiudi"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Visita il sito web %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Impossibile aprire il sito nel browser predefinito."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Impossibile copiare l’URL negli Appunti."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Impossibile copiare le informazioni negli Appunti."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Il gioco della vita di Conway in un mondo condiviso tra gli schermi."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Versione:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Piattaforma di destinazione:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Sito web:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Apri nel browser predefinito"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Copia &URL"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Copia &informazioni"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"La risorsa della licenza non è disponibile."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nREGOLE\r\nIl gioco della vita di Conway segue B3/S23. Una cella morta "
            L"nasce con esattamente tre vicine vive; una viva sopravvive con due o tre. Le otto vicine "
            L"includono le diagonali. Tutte cambiano simultaneamente. I bordi opposti si collegano: "
            L"sinistra con destra, alto con basso.\r\n\r\nSCHERMI E MONDO CONDIVISO\r\nLe caselle in EXE "
            L"attivano gli schermi; le impostazioni valgono per il mondo condiviso. Un solo schermo attivo "
            L"contiene l'intero mondo. Scegliendo parte degli schermi, righe e colonne completamente vuote "
            L"vengono eliminate: sinistro e destro si uniscono disattivando quello centrale. I vuoti "
            L"interni non eliminabili restano nella simulazione. Tutti gli schermi selezionati, oppure "
            L"SCR, mantengono il rettangolo del desktop con gli spazi invisibili. Ogni schermo mostra la "
            L"propria regione della stessa simulazione.\r\n\r\nSTATO INIZIALE E CONFIGURAZIONI\r\nL'avvio "
            L"predefinito è rumore casuale con il 25 % di celle vive. La densità iniziale 0–100 % si "
            L"applica al prossimo riavvio. Solo configurazioni note usa 4.106 configurazioni incluse senza "
            L"rumore e disattiva la densità. Scegliere una miscela o un nome; le dimensioni sono in celle. "
            L"Digitare per cercare. Sono elencate solo configurazioni che entrano interamente. Quelle "
            L"piccole verificate si ripetono in copie separate, quelle grandi o complesse una volta al "
            L"centro. Ridurre il mondo può sostituire una scelta troppo grande con una miscela. Cambiare "
            L"modalità o configurazione crea una nuova scena. I riavvii conservano la scelta; il catalogo "
            L"funziona offline.\r\n\r\nCELLE, GRIGLIA E COLORI\r\nSenza griglia la dimensione è 1–64 px. "
            L"Mostra griglia aggiunge un bordo di 1 px nella spaziatura esistente: valore e cursore "
            L"diminuiscono di uno, con 1–63 utilizzabili. Disattivandola il valore torna. Il cursore "
            L"mantiene l'intervallo e torna indietro dall'estremo non disponibile; la casella resta "
            L"attiva. La scena rimane, salvo attivazione a 1 px: la spaziatura diventa 2 px e la scena "
            L"riparte. Anche cambiare dimensione o schermi crea una nuova scena. Mondi molto grandi "
            L"possono richiedere un minimo superiore. I colori di celle, sfondo e griglia cambiano "
            L"separatamente senza riavvio. Il colore casuale delle celle vive cambia a ogni riavvio "
            L"manuale o automatico della scena. Il colore salvato rimane invariato e viene ripristinato "
            L"disattivando questa opzione. Lo stesso comportamento può essere attivato separatamente per "
            L"sfondo e griglia; entrambe le nuove opzioni sono inizialmente disattivate.\r\n\r\nVELOCITÀ, "
            L"PAUSA E RIAVVIO AUTOMATICO\r\nLa velocità è 0–240 generazioni/s, indipendente dal refresh; 0 "
            L"arresta l'evoluzione. Pausa e Riprendi conservano il mondo. Riavvia ricomincia nella "
            L"modalità scelta. Il riavvio automatico facoltativo riconosce fasi visibili statiche o "
            L"identiche che si ripetono, inclusi gli oscillatori. Confronta generazioni, non secondi; "
            L"esclude le zone invisibili. I risultati asincroni possono ritardare leggermente il riavvio. "
            L"Valori iniziali: spaziatura 8 px, 20 generazioni/s, colore casuale delle celle vive e "
            L"riavvio automatico attivati. La griglia è disattivata per impostazione predefinita. La "
            L"velocità raggiunta dipende dalle prestazioni e dal numero di celle. Il riavvio automatico "
            L"confronta le regioni degli schermi attivi; gli spazi intermedi continuano a evolvere ma sono "
            L"esclusi dal confronto.\r\n\r\nRipristina valori\r\nIl ripristino imposta la dimensione "
            L"visualizzata a 8 px con o senza griglia (spaziatura di 9 o 8 px), la velocità a 20 "
            L"generazioni/s, la densità al 25 % e i tre colori predefiniti. Le altre scelte sono "
            L"conservate; una configurazione che non entra più viene sostituita dalla miscela. Una nuova "
            L"scena viene creata solo se cambia la spaziatura o se cambia la densità in modalità "
            L"rumore.\r\n\r\nAPPLICAZIONE AUTONOMA E REGISTRAZIONE MP4\r\nEXE salva continuamente le "
            L"impostazioni e registra il primo schermo attivo in MP4. Propone Video, altrimenti Documenti. "
            L"Viewport usa dimensioni e refresh dello schermo fino a 60 fotogrammi/s. TV offre 1920 × "
            L"1080, 1440 × 1080 o 1280 × 720 in 16:9 a 50, 25, 59,94 (60000/1001) o 29,97 (30000/1001) "
            L"fotogrammi/s. Le proporzioni restano invariate; TV usa BT.709 progressivo a intervallo "
            L"limitato e 4:2:0. La finestra indipendente delle impostazioni può essere ridotta a icona. OK "
            L"salva per la prossima registrazione; Annulla o Esc scarta le modifiche pendenti. Lo schermo "
            L"registrato non può essere disattivato; le altre uscite possono cambiare. Uscire durante la "
            L"registrazione richiede conferma. Con l'animazione attiva, Spazio alterna la pausa, F9: Avvia "
            L"registrazione; F10: Ferma registrazione. Il puntatore scompare dopo 1 secondo inattivo e "
            L"ritorna muovendolo. Tab/Shift+Tab passa tra i controlli; Alt attiva i comandi sottolineati. "
            L"Esc chiude Guida/Informazioni, oppure esce dalla finestra principale.\r\n\r\nISTANTANEA E "
            L"GESTIONE DEL SALVASCHERMO IN EXE\r\nL’istantanea salva in BMP/GIF/JPEG/PNG/TIFF/WebP lo "
            L"schermo in registrazione, "
            L"altrimenti il primo attivo, alla sua risoluzione senza riavviare la scena. La cartella "
            L"proposta è Immagini, altrimenti Documenti. Bloccare il salvaschermo durante l’animazione ne "
            L"impedisce l’avvio finché l’animazione è visibile e non in pausa. Velocità zero non significa "
            L"pausa. L’installazione da EXE estrae il file SCR incluso e lo seleziona come salvaschermo "
            L"Windows. Installazione e disinstallazione possono richiedere l’approvazione "
            L"dell’amministratore; la barra di stato mostra l’operazione fino al termine. Se la rimozione "
            L"è bloccata, chiudere il salvaschermo in esecuzione, le sue impostazioni e l’anteprima "
            L"Windows.\r\n\r\nSALVASCHERMO WINDOWS\r\nGameOfLife.scr usa tutti gli schermi con "
            L"impostazioni separate da EXE. Attiva anteprima avvia l'animazione a schermo intero "
            L"mantenendo aperte le impostazioni. La piccola anteprima Windows riduce l'intero mondo. OK "
            L"salva; Annulla o Esc scarta le modifiche. Muovere il mouse o premere un tasto termina il "
            L"salvaschermo intero. La registrazione MP4 è disponibile in EXE.\r\n\r\nPOSIZIONE E STATO "
            L"DELLE FINESTRE\r\nAlla chiusura vengono salvate separatamente le posizioni della finestra "
            L"principale e di Informazioni; per la Guida anche dimensioni e stato normale o ingrandito "
            L"precedente alla riduzione a icona. Ciò è indipendente dalla conferma delle impostazioni. "
            L"Uscire dall’applicazione chiude anche Guida e Informazioni.\r\n\r\nRENDERING E LICENZE DELLE "
            L"CONFIGURAZIONI\r\nEvoluzione e confronti visibili usano shader Direct3D 11 sulla GPU; è "
            L"disponibile un renderer software se l'inizializzazione hardware fallisce. Ogni schermo usa "
            L"il regolatore di fotogrammi collaudato al proprio refresh. MP4 richiede Media Foundation e "
            L"un codificatore H.264. Le configurazioni provengono da LifeWiki (GFDL 1.2 o successiva) e "
            L"dalle raccolte di pubblico dominio di Alan Hensel. Il codice è MIT; avvisi e licenze del "
            L"catalogo sono separati.\r\n\r\nSalvaschermo di Windows… apre le impostazioni del "
            L"salvaschermo del sistema."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nREGOLE\r\nIl gioco della vita di Conway segue B3/S23. Una cella morta "
            L"nasce con esattamente tre vicine vive; una viva sopravvive con due o tre. Le otto vicine "
            L"includono le diagonali. Tutte cambiano simultaneamente. I bordi opposti si collegano: "
            L"sinistra con destra, alto con basso.\r\n\r\nSCHERMI E MONDO CONDIVISO\r\nLe caselle in EXE "
            L"attivano gli schermi; le impostazioni valgono per il mondo condiviso. Un solo schermo attivo "
            L"contiene l'intero mondo. Scegliendo parte degli schermi, righe e colonne completamente vuote "
            L"vengono eliminate: sinistro e destro si uniscono disattivando quello centrale. I vuoti "
            L"interni non eliminabili restano nella simulazione. Tutti gli schermi selezionati, oppure "
            L"SCR, mantengono il rettangolo del desktop con gli spazi invisibili. Ogni schermo mostra la "
            L"propria regione della stessa simulazione.\r\n\r\nSTATO INIZIALE E CONFIGURAZIONI\r\nL'avvio "
            L"predefinito è rumore casuale con il 25 % di celle vive. La densità iniziale 0–100 % si "
            L"applica al prossimo riavvio. Solo configurazioni note usa 4.106 configurazioni incluse senza "
            L"rumore e disattiva la densità. Scegliere una miscela o un nome; le dimensioni sono in celle. "
            L"Digitare per cercare. Sono elencate solo configurazioni che entrano interamente. Quelle "
            L"piccole verificate si ripetono in copie separate, quelle grandi o complesse una volta al "
            L"centro. Ridurre il mondo può sostituire una scelta troppo grande con una miscela. Cambiare "
            L"modalità o configurazione crea una nuova scena. I riavvii conservano la scelta; il catalogo "
            L"funziona offline.\r\n\r\nCELLE, GRIGLIA E COLORI\r\nSenza griglia la dimensione è 1–64 px. "
            L"Mostra griglia aggiunge un bordo di 1 px nella spaziatura esistente: valore e cursore "
            L"diminuiscono di uno, con 1–63 utilizzabili. Disattivandola il valore torna. Il cursore "
            L"mantiene l'intervallo e torna indietro dall'estremo non disponibile; la casella resta "
            L"attiva. La scena rimane, salvo attivazione a 1 px: la spaziatura diventa 2 px e la scena "
            L"riparte. Anche cambiare dimensione o schermi crea una nuova scena. Mondi molto grandi "
            L"possono richiedere un minimo superiore. I colori di celle, sfondo e griglia cambiano "
            L"separatamente senza riavvio. Il colore casuale delle celle vive cambia a ogni riavvio "
            L"manuale o automatico della scena. Il colore salvato rimane invariato e viene ripristinato "
            L"disattivando questa opzione. Lo stesso comportamento può essere attivato separatamente per "
            L"sfondo e griglia; entrambe le nuove opzioni sono inizialmente disattivate.\r\n\r\nVELOCITÀ, "
            L"PAUSA E RIAVVIO AUTOMATICO\r\nLa velocità è 0–240 generazioni/s, indipendente dal refresh; 0 "
            L"arresta l'evoluzione. Pausa e Riprendi conservano il mondo. Riavvia ricomincia nella "
            L"modalità scelta. Il riavvio automatico facoltativo riconosce fasi visibili statiche o "
            L"identiche che si ripetono, inclusi gli oscillatori. Confronta generazioni, non secondi; "
            L"esclude le zone invisibili. I risultati asincroni possono ritardare leggermente il riavvio. "
            L"Valori iniziali: spaziatura 8 px, 20 generazioni/s, colore casuale delle celle vive e "
            L"riavvio automatico attivati. La griglia è disattivata per impostazione predefinita. La "
            L"velocità raggiunta dipende dalle prestazioni e dal numero di celle. Il riavvio automatico "
            L"confronta le regioni degli schermi attivi; gli spazi intermedi continuano a evolvere ma sono "
            L"esclusi dal confronto.\r\n\r\nRipristina valori\r\nIl ripristino imposta la dimensione "
            L"visualizzata a 8 px con o senza griglia (spaziatura di 9 o 8 px), la velocità a 20 "
            L"generazioni/s, la densità al 25 % e i tre colori predefiniti. Le altre scelte sono "
            L"conservate; una configurazione che non entra più viene sostituita dalla miscela. Una nuova "
            L"scena viene creata solo se cambia la spaziatura o se cambia la densità in modalità "
            L"rumore.\r\n\r\nSALVASCHERMO WINDOWS\r\nGameOfLife.scr usa tutti gli schermi con impostazioni "
            L"separate da EXE. Attiva anteprima avvia l'animazione a schermo intero mantenendo aperte le "
            L"impostazioni. La piccola anteprima Windows riduce l'intero mondo. OK salva; Annulla o Esc "
            L"scarta le modifiche. Muovere il mouse o premere un tasto termina il salvaschermo intero. La "
            L"registrazione MP4 è disponibile in EXE.\r\n\r\nPOSIZIONE E STATO DELLE FINESTRE\r\nAlla "
            L"chiusura vengono salvate separatamente le posizioni della finestra principale e di "
            L"Informazioni; per la Guida anche dimensioni e stato normale o ingrandito precedente alla "
            L"riduzione a icona. Ciò è indipendente dalla conferma delle impostazioni. Uscire "
            L"dall’applicazione chiude anche Guida e Informazioni.\r\n\r\nRENDERING E LICENZE DELLE "
            L"CONFIGURAZIONI\r\nEvoluzione e confronti visibili usano shader Direct3D 11 sulla GPU; è "
            L"disponibile un renderer software se l'inizializzazione hardware fallisce. Ogni schermo usa "
            L"il regolatore di fotogrammi collaudato al proprio refresh. MP4 richiede Media Foundation e "
            L"un codificatore H.264. Le configurazioni provengono da LifeWiki (GFDL 1.2 o successiva) e "
            L"dalle raccolte di pubblico dominio di Alan Hensel. Il codice è MIT; avvisi e licenze del "
            L"catalogo sono separati."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Dimensione cella: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Velocità: %u generazioni/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Densità iniziale: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Riavvia scena" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Colore celle vive…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Colore sfondo…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Gli schermi scelti condividono un mondo. Le fasce vuote scompaiono; i vuoti interni restano."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animazione in esecuzione…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"L’animazione è in pausa."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Impossibile inizializzare Direct3D."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Attiva anteprima"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Disattiva anteprima"
        },
        LocalizedText{ TXT_MONITOR,
            L"Monitor"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Risoluzione"
        },
        LocalizedText{ TXT_POSITION,
            L"Posizione"
        },
        LocalizedText{ TXT_PRIMARY,
            L"principale"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Modello del monitor"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Frequenza di aggiornamento"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Profondità di bit"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Formato colore"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Spazio colore"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bit/canale"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bit/pixel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Monitor animazione"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Pronto"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Mostra griglia"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Colore griglia…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Riavvia automaticamente una scena visibile stabile o ripetitiva"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Solo configurazioni note"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Avvia registrazione…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Ferma registrazione"
        },
        LocalizedText{ TXT_RECORDING,
            L"Registrazione MP4 in corso…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Registrazione salvata."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Impossibile avviare la registrazione MP4."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"La chiusura dell’applicazione interromperà la registrazione in corso."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Impostazioni video"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Risoluzione:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Frequenza fotogrammi:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Le modifiche si applicano alla prossima registrazione MP4."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Miscela di configurazioni adatte"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"La configurazione scelta non entra più nel mondo. È stata scelta una miscela adatta."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Impossibile caricare il catalogo delle configurazioni note."
        },
    }),
    DefineLanguage(LANG_PT, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Cor de fundo aleatória em cada reinício da cena" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Cor da grelha aleatória em cada reinício da cena" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Proteção de ecrã do Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Não foi possível abrir as definições da proteção de ecrã do Windows."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Repor valores" },
        LocalizedText{ TXT_SNAPSHOT, L"Captura…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"A captura foi guardada." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Não foi possível guardar a captura." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Bloquear proteção de ecrã durante a animação" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Cor aleatória das células vivas ao reiniciar a cena"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"A instalar a proteção de ecrã…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"A desinstalar a proteção de ecrã…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Instalar proteção de ecrã" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Desinstalar proteção de ecrã" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"A proteção de ecrã não foi instalada." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"A proteção de ecrã foi instalada." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"A proteção de ecrã foi desinstalada." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Não foi possível desinstalar a proteção de ecrã. Se a proteção ou a pré-visualização estiver "
            L"em execução, feche-a e tente novamente."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"A desinstalação falhou porque as definições do GameOfLife estão abertas. Feche a janela e "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Português"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Controlo"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Definições do GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Idioma:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Cancelar"
        },
        LocalizedText{ TXT_EXIT,
            L"Sair"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pausar"
        },
        LocalizedText{ TXT_RESUME,
            L"Continuar"
        },
        LocalizedText{ TXT_HELP,
            L"Ajuda"
        },
        LocalizedText{ TXT_ABOUT,
            L"Acerca de"
        },
        LocalizedText{ TXT_CLOSE,
            L"Fechar"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Visitar o site %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Não é possível abrir o sítio no navegador predefinido."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Não foi possível copiar o URL para a área de transferência."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Não foi possível copiar as informações para a área de transferência."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"O Jogo da Vida de Conway num mundo partilhado entre ecrãs."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Versão:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Plataforma de destino:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Site:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Abrir no navegador predefinido"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Copiar &URL"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Copiar &informações"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"O recurso da licença não está disponível."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nREGRAS\r\nO Jogo da Vida de Conway usa B3/S23. Uma célula morta nasce com "
            L"exatamente três vizinhas vivas; uma viva sobrevive com duas ou três. As oito vizinhas "
            L"incluem diagonais. Todas mudam em simultâneo. As margens opostas ligam-se: esquerda à "
            L"direita, superior à inferior.\r\n\r\nECRÃS E MUNDO PARTILHADO\r\nAs caixas no EXE ativam "
            L"ecrãs; as definições aplicam-se ao mundo partilhado. Um único ecrã ativo contém o mundo "
            L"inteiro. Ao escolher parte da disposição, eliminam-se linhas e colunas completamente vazias: "
            L"os ecrãs esquerdo e direito unem-se ao desligar o central. As lacunas interiores que não "
            L"podem ser eliminadas continuam na simulação. Selecionar todos os ecrãs, ou executar SCR, "
            L"mantém o retângulo do ambiente de trabalho e os intervalos invisíveis. Cada ecrã mostra a "
            L"sua região da mesma simulação.\r\n\r\nESTADO INICIAL E PADRÕES\r\nO início predefinido é "
            L"ruído aleatório com 25 % de células vivas. A densidade inicial 0–100 % aplica-se no próximo "
            L"reinício. Apenas padrões conhecidos usa 4 106 padrões incluídos sem ruído e desativa a "
            L"densidade. Escolha uma mistura ou um nome; as dimensões são em células. Escreva para "
            L"procurar. Só são apresentados padrões que cabem inteiros. Os pequenos verificados repetem-se "
            L"em cópias separadas; os grandes ou complexos surgem uma vez ao centro. Reduzir o mundo pode "
            L"substituir uma escolha demasiado grande por uma mistura. Alterar modo ou padrão cria outra "
            L"cena. Os reinícios mantêm a escolha; o catálogo funciona sem ligação.\r\n\r\nCÉLULAS, GRELHA "
            L"E CORES\r\nSem grelha, o tamanho é 1–64 px. Mostrar grelha acrescenta uma margem de 1 px no "
            L"espaçamento existente: o valor e o cursor diminuem um, ficando 1–63 utilizáveis. Desativar "
            L"repõe o valor. O cursor mantém o intervalo e recua da extremidade indisponível; a caixa "
            L"continua ativa. A cena mantém-se, exceto ao ativar a 1 px: o espaçamento passa a 2 px e a "
            L"cena reinicia. Alterar tamanho ou ecrãs também recomeça. Mundos muito grandes podem exigir "
            L"um mínimo superior. As cores das células, fundo e grelha mudam separadamente sem reinício. A "
            L"cor aleatória das células vivas muda em cada reinício manual ou automático da cena. A cor "
            L"guardada é preservada e regressa ao desativar esta opção. O mesmo comportamento pode ser "
            L"ativado separadamente para o fundo e a grelha; ambas as novas opções estão inicialmente "
            L"desativadas.\r\n\r\nVELOCIDADE, PAUSA E REINÍCIO AUTOMÁTICO\r\nA velocidade é 0–240 "
            L"gerações/s, independente do refrescamento; 0 para a evolução. Pausa e Retomar mantêm o "
            L"mundo. Reiniciar recomeça no modo escolhido. O reinício automático opcional deteta fases "
            L"visíveis estáticas ou exatamente repetidas, incluindo osciladores. Compara gerações, não "
            L"segundos; exclui zonas invisíveis. Os resultados assíncronos podem atrasar ligeiramente o "
            L"reinício. Predefinições: espaçamento 8 px, 20 gerações/s, cor aleatória das células vivas e "
            L"reinício automático ligados. A grelha está desativada por predefinição. A velocidade "
            L"atingida depende do desempenho e do número de células. O reinício automático compara as "
            L"regiões dos ecrãs ativos; os intervalos continuam a evoluir, mas não entram na "
            L"comparação.\r\n\r\nRepor valores\r\nA reposição define o tamanho apresentado como 8 px com "
            L"ou sem grelha (espaçamento de 9 ou 8 px), a velocidade como 20 gerações/s, a densidade como "
            L"25 % e as três cores predefinidas. As outras escolhas são mantidas; um padrão que deixe de "
            L"caber é substituído pela mistura. Só é criada uma nova cena se mudar o espaçamento ou a "
            L"densidade no modo de ruído.\r\n\r\nAPLICAÇÃO AUTÓNOMA E GRAVAÇÃO MP4\r\nO EXE guarda "
            L"definições continuamente e grava o primeiro ecrã ativo em MP4. Sugere Vídeos, ou Documentos "
            L"como alternativa. Viewport usa dimensões e frequência do ecrã até 60 fotogramas/s. TV "
            L"oferece 1920 × 1080, 1440 × 1080 ou 1280 × 720 em 16:9 a 50, 25, 59,94 (60000/1001) ou 29,97 "
            L"(30000/1001) fotogramas/s. A proporção mantém-se; TV usa BT.709 progressivo de gama limitada "
            L"e 4:2:0. A janela independente de definições pode ser minimizada. OK guarda para a próxima "
            L"gravação; Cancelar ou Esc descarta alterações pendentes. O ecrã gravado não pode ser "
            L"desligado; as outras saídas podem mudar. Sair durante a gravação exige confirmação. Com foco "
            L"na animação, Espaço alterna a pausa, F9: Iniciar gravação; F10: Parar gravação. O cursor "
            L"oculta-se após 1 segundo inativo e reaparece ao mover-se. Tab/Shift+Tab percorre controlos; "
            L"Alt ativa comandos sublinhados. Esc fecha Ajuda/Acerca de ou sai na janela "
            L"principal.\r\n\r\nINSTANTÂNEO E GESTÃO DA PROTEÇÃO DE ECRÃ NO EXE\r\nO instantâneo guarda um "
            L"BMP/GIF/JPEG/PNG/TIFF/WebP do ecrã em gravação ou, caso contrário, do primeiro ativo, à sua "
            L"resolução e sem "
            L"reiniciar a cena. Sugere Imagens, ou Documentos como alternativa. Bloquear a proteção de "
            L"ecrã durante a animação impede a sua ativação enquanto a animação estiver visível e sem "
            L"pausa. Velocidade zero não é pausa. A instalação a partir do EXE extrai o SCR incluído e "
            L"seleciona-o como proteção de ecrã do Windows. Instalar e desinstalar pode exigir autorização "
            L"de administrador; a barra de estado indica a operação até ao fim. Se a remoção estiver "
            L"bloqueada, feche a proteção em execução, as suas definições e a pré-visualização do "
            L"Windows.\r\n\r\nPROTEÇÃO DE ECRÃ DO WINDOWS\r\nGameOfLife.scr usa todos os ecrãs com "
            L"definições separadas do EXE. Ativar pré-visualização inicia a animação de ecrã inteiro "
            L"mantendo as definições abertas. A pequena pré-visualização Windows reduz o mundo completo. "
            L"OK guarda; Cancelar ou Esc descarta alterações. Mover o rato ou premir uma tecla termina a "
            L"proteção de ecrã inteiro. A gravação MP4 está disponível no EXE.\r\n\r\nPOSIÇÃO E ESTADO DAS "
            L"JANELAS\r\nAo fechar, são guardadas separadamente as posições das janelas principal e Acerca "
            L"de; a Ajuda guarda também o tamanho e o estado normal ou maximizado anterior à minimização. "
            L"Isto é independente da confirmação das definições da aplicação. Sair da aplicação fecha "
            L"também Ajuda e Acerca de.\r\n\r\nRENDERIZAÇÃO E LICENÇAS DOS PADRÕES\r\nA evolução e as "
            L"comparações visíveis usam shaders Direct3D 11 na GPU; existe renderização por software se "
            L"falhar a inicialização do hardware. Cada ecrã usa o regulador de fotogramas testado à sua "
            L"frequência. MP4 requer Media Foundation e um codificador H.264. Os padrões vêm de LifeWiki "
            L"(GFDL 1.2 ou posterior) e das coleções de domínio público de Alan Hensel. O código é MIT; "
            L"avisos e licenças do catálogo são separados.\r\n\r\nProteção de ecrã do Windows… abre as "
            L"definições da proteção de ecrã do sistema."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nREGRAS\r\nO Jogo da Vida de Conway usa B3/S23. Uma célula morta nasce com "
            L"exatamente três vizinhas vivas; uma viva sobrevive com duas ou três. As oito vizinhas "
            L"incluem diagonais. Todas mudam em simultâneo. As margens opostas ligam-se: esquerda à "
            L"direita, superior à inferior.\r\n\r\nECRÃS E MUNDO PARTILHADO\r\nAs caixas no EXE ativam "
            L"ecrãs; as definições aplicam-se ao mundo partilhado. Um único ecrã ativo contém o mundo "
            L"inteiro. Ao escolher parte da disposição, eliminam-se linhas e colunas completamente vazias: "
            L"os ecrãs esquerdo e direito unem-se ao desligar o central. As lacunas interiores que não "
            L"podem ser eliminadas continuam na simulação. Selecionar todos os ecrãs, ou executar SCR, "
            L"mantém o retângulo do ambiente de trabalho e os intervalos invisíveis. Cada ecrã mostra a "
            L"sua região da mesma simulação.\r\n\r\nESTADO INICIAL E PADRÕES\r\nO início predefinido é "
            L"ruído aleatório com 25 % de células vivas. A densidade inicial 0–100 % aplica-se no próximo "
            L"reinício. Apenas padrões conhecidos usa 4 106 padrões incluídos sem ruído e desativa a "
            L"densidade. Escolha uma mistura ou um nome; as dimensões são em células. Escreva para "
            L"procurar. Só são apresentados padrões que cabem inteiros. Os pequenos verificados repetem-se "
            L"em cópias separadas; os grandes ou complexos surgem uma vez ao centro. Reduzir o mundo pode "
            L"substituir uma escolha demasiado grande por uma mistura. Alterar modo ou padrão cria outra "
            L"cena. Os reinícios mantêm a escolha; o catálogo funciona sem ligação.\r\n\r\nCÉLULAS, GRELHA "
            L"E CORES\r\nSem grelha, o tamanho é 1–64 px. Mostrar grelha acrescenta uma margem de 1 px no "
            L"espaçamento existente: o valor e o cursor diminuem um, ficando 1–63 utilizáveis. Desativar "
            L"repõe o valor. O cursor mantém o intervalo e recua da extremidade indisponível; a caixa "
            L"continua ativa. A cena mantém-se, exceto ao ativar a 1 px: o espaçamento passa a 2 px e a "
            L"cena reinicia. Alterar tamanho ou ecrãs também recomeça. Mundos muito grandes podem exigir "
            L"um mínimo superior. As cores das células, fundo e grelha mudam separadamente sem reinício. A "
            L"cor aleatória das células vivas muda em cada reinício manual ou automático da cena. A cor "
            L"guardada é preservada e regressa ao desativar esta opção. O mesmo comportamento pode ser "
            L"ativado separadamente para o fundo e a grelha; ambas as novas opções estão inicialmente "
            L"desativadas.\r\n\r\nVELOCIDADE, PAUSA E REINÍCIO AUTOMÁTICO\r\nA velocidade é 0–240 "
            L"gerações/s, independente do refrescamento; 0 para a evolução. Pausa e Retomar mantêm o "
            L"mundo. Reiniciar recomeça no modo escolhido. O reinício automático opcional deteta fases "
            L"visíveis estáticas ou exatamente repetidas, incluindo osciladores. Compara gerações, não "
            L"segundos; exclui zonas invisíveis. Os resultados assíncronos podem atrasar ligeiramente o "
            L"reinício. Predefinições: espaçamento 8 px, 20 gerações/s, cor aleatória das células vivas e "
            L"reinício automático ligados. A grelha está desativada por predefinição. A velocidade "
            L"atingida depende do desempenho e do número de células. O reinício automático compara as "
            L"regiões dos ecrãs ativos; os intervalos continuam a evoluir, mas não entram na "
            L"comparação.\r\n\r\nRepor valores\r\nA reposição define o tamanho apresentado como 8 px com "
            L"ou sem grelha (espaçamento de 9 ou 8 px), a velocidade como 20 gerações/s, a densidade como "
            L"25 % e as três cores predefinidas. As outras escolhas são mantidas; um padrão que deixe de "
            L"caber é substituído pela mistura. Só é criada uma nova cena se mudar o espaçamento ou a "
            L"densidade no modo de ruído.\r\n\r\nPROTEÇÃO DE ECRÃ DO WINDOWS\r\nGameOfLife.scr usa todos "
            L"os ecrãs com definições separadas do EXE. Ativar pré-visualização inicia a animação de ecrã "
            L"inteiro mantendo as definições abertas. A pequena pré-visualização Windows reduz o mundo "
            L"completo. OK guarda; Cancelar ou Esc descarta alterações. Mover o rato ou premir uma tecla "
            L"termina a proteção de ecrã inteiro. A gravação MP4 está disponível no EXE.\r\n\r\nPOSIÇÃO E "
            L"ESTADO DAS JANELAS\r\nAo fechar, são guardadas separadamente as posições das janelas "
            L"principal e Acerca de; a Ajuda guarda também o tamanho e o estado normal ou maximizado "
            L"anterior à minimização. Isto é independente da confirmação das definições da aplicação. Sair "
            L"da aplicação fecha também Ajuda e Acerca de.\r\n\r\nRENDERIZAÇÃO E LICENÇAS DOS PADRÕES\r\nA "
            L"evolução e as comparações visíveis usam shaders Direct3D 11 na GPU; existe renderização por "
            L"software se falhar a inicialização do hardware. Cada ecrã usa o regulador de fotogramas "
            L"testado à sua frequência. MP4 requer Media Foundation e um codificador H.264. Os padrões vêm "
            L"de LifeWiki (GFDL 1.2 ou posterior) e das coleções de domínio público de Alan Hensel. O "
            L"código é MIT; avisos e licenças do catálogo são separados."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Tamanho da célula: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Velocidade: %u gerações/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Densidade inicial: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Reiniciar cena" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Cor das células vivas…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Cor de fundo…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Os ecrãs escolhidos partilham um mundo. As faixas vazias desaparecem; as lacunas interiores "
            L"ficam."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"A animação está em execução…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"A animação está em pausa."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Não foi possível inicializar o Direct3D."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Pré-visualizar" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Parar pré-visualização" },
        LocalizedText{ TXT_MONITOR,
            L"Monitor"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Resolução"
        },
        LocalizedText{ TXT_POSITION,
            L"Posição"
        },
        LocalizedText{ TXT_PRIMARY,
            L"principal"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Modelo do monitor"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Taxa de atualização"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Profundidade de bits"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Formato de cor"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Espaço de cor"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bits/canal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bits/píxel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Monitor da animação"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Pronto"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Mostrar grelha"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Cor da grelha…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Reiniciar automaticamente uma cena visível estável ou repetitiva"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Apenas padrões conhecidos"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Iniciar gravação…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Parar gravação"
        },
        LocalizedText{ TXT_RECORDING,
            L"Gravação MP4 em curso…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"A gravação foi guardada."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Não foi possível iniciar a gravação MP4."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Fechar a aplicação irá terminar a gravação em curso."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Definições de gravação"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Resolução:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Frequência de imagens:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"As alterações aplicam-se à próxima gravação MP4."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Mistura de padrões adequados"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"O padrão escolhido já não cabe. Foi selecionada uma mistura adequada."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Não foi possível carregar o catálogo de padrões conhecidos."
        },
    }),
    DefineLanguage(LANG_PL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Losowy kolor tła przy każdym restarcie sceny" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Losowy kolor siatki przy każdym restarcie sceny" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Wygaszacz ekranu Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Nie można otworzyć ustawień wygaszacza ekranu systemu Windows."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Przywróć wartości" },
        LocalizedText{ TXT_SNAPSHOT, L"Zrzut…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Zrzut został zapisany." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Nie udało się zapisać zrzutu." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blokuj wygaszacz podczas animacji" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Losowy kolor żywych komórek przy każdym restarcie sceny"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Trwa instalacja wygaszacza ekranu…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Trwa odinstalowywanie wygaszacza ekranu…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Zainstaluj wygaszacz" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Odinstaluj wygaszacz" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Wygaszacz nie został zainstalowany." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Wygaszacz został zainstalowany." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Wygaszacz został odinstalowany." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Nie udało się odinstalować wygaszacza. Jeśli wygaszacz lub jego podgląd jest uruchomiony, "
            L"zamknij go i spróbuj ponownie."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Odinstalowanie nie powiodło się, ponieważ ustawienia GameOfLife są otwarte. Zamknij okno i "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Polski"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Sterowanie"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Ustawienia GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Język:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Anuluj"
        },
        LocalizedText{ TXT_EXIT,
            L"Zakończ"
        },
        LocalizedText{ TXT_PAUSE,
            L"Wstrzymaj"
        },
        LocalizedText{ TXT_RESUME,
            L"Wznów"
        },
        LocalizedText{ TXT_HELP,
            L"Pomoc"
        },
        LocalizedText{ TXT_ABOUT,
            L"O programie"
        },
        LocalizedText{ TXT_CLOSE,
            L"Zamknij"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Odwiedź witrynę %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Nie można otworzyć witryny w domyślnej przeglądarce."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Nie można skopiować adresu URL do schowka."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Nie można skopiować informacji do schowka."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Gra w życie Conwaya we wspólnym świecie na wielu monitorach."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Wersja:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Platforma docelowa:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Witryna:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Otwórz w domyślnej przeglądarce"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Kopiuj &adres URL"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Kopiuj &informacje"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Zasób licencji jest niedostępny."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nZASADY\r\nGra w życie Conwaya używa B3/S23. Martwa komórka ożywa przy "
            L"dokładnie trzech żywych sąsiadach; żywa przeżywa przy dwóch lub trzech. Ośmiu sąsiadów "
            L"obejmuje przekątne. Wszystkie komórki zmieniają się jednocześnie. Przeciwległe krawędzie "
            L"łączą się: lewa z prawą, górna z dolną.\r\n\r\nMONITORY I WSPÓLNY ŚWIAT\r\nPola w EXE "
            L"włączają monitory; ustawienia dotyczą wspólnego świata. Jeden włączony monitor zawiera cały "
            L"świat. Przy częściowym wyborze usuwane są całkowicie puste wiersze i kolumny: lewy i prawy "
            L"monitor łączą się po wyłączeniu środkowego. Niemożliwe do usunięcia wewnętrzne luki nadal "
            L"uczestniczą w symulacji. Wybranie wszystkich monitorów lub uruchomienie SCR zachowuje "
            L"prostokąt pulpitu z niewidocznymi przerwami. Każdy monitor pokazuje swój fragment tej samej "
            L"gry.\r\n\r\nSTAN POCZĄTKOWY I WZORCE\r\nDomyślny początek to losowy szum z 25 % żywych "
            L"komórek. Gęstość początkowa 0–100 % działa przy następnym restarcie. Tylko znane wzorce "
            L"używa 4 106 dołączonych wzorców bez szumu i wyłącza gęstość. Wybierz mieszankę lub nazwany "
            L"wzorzec; wymiary podano w komórkach. Wpisuj nazwę, aby szukać. Lista zawiera tylko wzorce "
            L"mieszczące się w całości. Małe sprawdzone wzorce powtarzają się w oddzielnych kopiach, duże "
            L"lub złożone pojawiają się raz na środku. Zmniejszenie świata może zastąpić zbyt duży wybór "
            L"mieszanką. Zmiana trybu lub wzorca tworzy nową scenę. Restarty zachowują wybór; katalog "
            L"działa bez internetu.\r\n\r\nKOMÓRKI, SIATKA I KOLORY\r\nBez siatki rozmiar wynosi 1–64 px. "
            L"Pokaż siatkę dodaje krawędź 1 px wewnątrz obecnego odstępu: wskazanie i suwak zmniejszają "
            L"się o jeden, dostępne jest 1–63. Wyłączenie przywraca wartość. Suwak zachowuje zakres i cofa "
            L"się z niedostępnego końca; pole pozostaje aktywne. Przełączanie zachowuje scenę, poza "
            L"włączeniem przy 1 px: odstęp rośnie do 2 px i scena zaczyna się od nowa. Zmiana rozmiaru lub "
            L"monitorów także tworzy nową scenę. Bardzo duży świat może wymagać większego minimum. Kolory "
            L"komórek, tła i siatki zmieniają się osobno bez restartu. Losowy kolor żywych komórek zmienia "
            L"się przy każdym ręcznym lub automatycznym restarcie sceny. Zapisany kolor pozostaje "
            L"zachowany i wraca po wyłączeniu tej opcji. To samo działanie można włączyć osobno dla tła i "
            L"siatki; obie nowe opcje są domyślnie wyłączone.\r\n\r\nPRĘDKOŚĆ, PAUZA I AUTOMATYCZNY "
            L"RESTART\r\nPrędkość wynosi 0–240 pokoleń/s, niezależnie od odświeżania; 0 zatrzymuje rozwój. "
            L"Pauza i Wznów zachowują świat. Restart rozpoczyna wybrany tryb od nowa. Opcjonalny "
            L"automatyczny restart wykrywa nieruchome lub dokładnie powtarzające się widoczne fazy, także "
            L"oscylatory. Porównuje pokolenia, nie sekundy; pomija niewidoczne obszary. Wyniki "
            L"asynchroniczne mogą nieco opóźnić restart. Domyślnie: odstęp 8 px, 20 pokoleń/s, losowy "
            L"kolor żywych komórek i automatyczny restart włączone. Siatka jest domyślnie wyłączona. "
            L"Osiągana prędkość zależy od wydajności i liczby komórek. Automatyczny restart porównuje "
            L"obszary włączonych monitorów; luki między nimi nadal ewoluują, lecz nie są "
            L"porównywane.\r\n\r\nPrzywróć wartości\r\nPrzywracanie ustawia wyświetlany rozmiar komórki na "
            L"8 px z siatką lub bez niej (odstęp 9 lub 8 px), prędkość na 20 pokoleń/s, gęstość na 25 % i "
            L"trzy domyślne kolory. Pozostałe opcje są zachowane; wzorzec, który się nie mieści, zastępuje "
            L"mieszanka. Nowa scena powstaje tylko po zmianie odstępu lub gęstości w trybie "
            L"szumu.\r\n\r\nSAMODZIELNA APLIKACJA I NAGRYWANIE MP4\r\nEXE zapisuje ustawienia na bieżąco i "
            L"nagrywa pierwszy aktywny monitor do MP4. Proponuje folder Wideo, zastępczo Dokumenty. "
            L"Viewport używa wymiarów i odświeżania monitora do 60 klatek/s. TV oferuje 1920 × 1080, 1440 "
            L"× 1080 lub 1280 × 720 w 16:9 przy 50, 25, 59,94 (60000/1001) lub 29,97 (30000/1001) "
            L"klatkach/s. Proporcje są zachowane; TV używa progresywnego BT.709, ograniczonego zakresu i "
            L"4:2:0. Niezależne okno ustawień można zminimalizować. OK zapisuje opcje dla następnego "
            L"nagrania; Anuluj lub Esc odrzuca niezatwierdzone zmiany. Nagrywanego monitora nie można "
            L"wyłączyć; pozostałe wyjścia można zmieniać. Zakończenie podczas nagrywania wymaga "
            L"potwierdzenia. Przy aktywnej animacji Spacja przełącza pauzę, F9: Rozpocznij nagrywanie; "
            L"F10: Zatrzymaj nagrywanie. Kursor znika po 1 sekundzie bezruchu i wraca po poruszeniu. "
            L"Tab/Shift+Tab przechodzi między kontrolkami, Alt wybiera podkreślone polecenia. Esc zamyka "
            L"Pomoc/Informacje lub kończy aplikację z głównego okna.\r\n\r\nZDJĘCIE I ZARZĄDZANIE "
            L"WYGASZACZEM W EXE\r\nZdjęcie zapisuje BMP/GIF/JPEG/PNG/TIFF/WebP nagrywanego monitora, a w "
            L"pozostałych przypadkach "
            L"pierwszego aktywnego, w jego rozdzielczości i bez restartu sceny. Proponowany jest folder "
            L"Obrazy, zastępczo Dokumenty. Blokowanie wygaszacza podczas animacji zapobiega jego "
            L"uruchomieniu, gdy animacja jest widoczna i nie jest wstrzymana. Prędkość zero nie oznacza "
            L"pauzy. Instalacja z EXE rozpakowuje dołączony SCR i wybiera go jako wygaszacz Windows. "
            L"Instalacja i odinstalowanie mogą wymagać zgody administratora; pasek stanu pokazuje operację "
            L"aż do zakończenia. Jeśli usuwanie jest zablokowane, zamknij działający wygaszacz, jego "
            L"ustawienia i podgląd Windows.\r\n\r\nWYGASZACZ EKRANU WINDOWS\r\nGameOfLife.scr używa "
            L"wszystkich monitorów i ustawień oddzielnych od EXE. Włącz podgląd uruchamia pełny ekran przy "
            L"otwartych ustawieniach. Mały podgląd Windows skaluje cały świat. OK zapisuje; Anuluj lub Esc "
            L"odrzuca zmiany. Ruch myszy lub klawisz kończy pełnoekranowy wygaszacz. Nagrywanie MP4 jest "
            L"dostępne w EXE.\r\n\r\nPOŁOŻENIE I STAN OKIEN\r\nPrzy zamykaniu osobno zapisywane są pozycje "
            L"okna głównego i Informacje; dla Pomocy także rozmiar oraz stan normalny lub zmaksymalizowany "
            L"sprzed minimalizacji. Nie zależy to od zatwierdzania ustawień aplikacji. Zakończenie "
            L"aplikacji zamyka też Pomoc i Informacje.\r\n\r\nRENDEROWANIE I LICENCJE WZORCÓW\r\nRozwój i "
            L"porównania widocznych stanów wykonują shadery Direct3D 11 na GPU; po nieudanej inicjalizacji "
            L"sprzętowej dostępne jest renderowanie programowe. Każdy monitor używa sprawdzonego "
            L"regulatora klatek przy własnym odświeżaniu. MP4 wymaga Media Foundation i kodera H.264. "
            L"Wzorce pochodzą z LifeWiki (GFDL 1.2 lub nowsza) i publicznych zbiorów Alana Hensela w "
            L"domenie publicznej. Kod ma licencję MIT; informacje i licencje katalogu są "
            L"oddzielne.\r\n\r\nWygaszacz ekranu Windows… otwiera systemowe ustawienia wygaszacza ekranu."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nZASADY\r\nGra w życie Conwaya używa B3/S23. Martwa komórka ożywa przy "
            L"dokładnie trzech żywych sąsiadach; żywa przeżywa przy dwóch lub trzech. Ośmiu sąsiadów "
            L"obejmuje przekątne. Wszystkie komórki zmieniają się jednocześnie. Przeciwległe krawędzie "
            L"łączą się: lewa z prawą, górna z dolną.\r\n\r\nMONITORY I WSPÓLNY ŚWIAT\r\nPola w EXE "
            L"włączają monitory; ustawienia dotyczą wspólnego świata. Jeden włączony monitor zawiera cały "
            L"świat. Przy częściowym wyborze usuwane są całkowicie puste wiersze i kolumny: lewy i prawy "
            L"monitor łączą się po wyłączeniu środkowego. Niemożliwe do usunięcia wewnętrzne luki nadal "
            L"uczestniczą w symulacji. Wybranie wszystkich monitorów lub uruchomienie SCR zachowuje "
            L"prostokąt pulpitu z niewidocznymi przerwami. Każdy monitor pokazuje swój fragment tej samej "
            L"gry.\r\n\r\nSTAN POCZĄTKOWY I WZORCE\r\nDomyślny początek to losowy szum z 25 % żywych "
            L"komórek. Gęstość początkowa 0–100 % działa przy następnym restarcie. Tylko znane wzorce "
            L"używa 4 106 dołączonych wzorców bez szumu i wyłącza gęstość. Wybierz mieszankę lub nazwany "
            L"wzorzec; wymiary podano w komórkach. Wpisuj nazwę, aby szukać. Lista zawiera tylko wzorce "
            L"mieszczące się w całości. Małe sprawdzone wzorce powtarzają się w oddzielnych kopiach, duże "
            L"lub złożone pojawiają się raz na środku. Zmniejszenie świata może zastąpić zbyt duży wybór "
            L"mieszanką. Zmiana trybu lub wzorca tworzy nową scenę. Restarty zachowują wybór; katalog "
            L"działa bez internetu.\r\n\r\nKOMÓRKI, SIATKA I KOLORY\r\nBez siatki rozmiar wynosi 1–64 px. "
            L"Pokaż siatkę dodaje krawędź 1 px wewnątrz obecnego odstępu: wskazanie i suwak zmniejszają "
            L"się o jeden, dostępne jest 1–63. Wyłączenie przywraca wartość. Suwak zachowuje zakres i cofa "
            L"się z niedostępnego końca; pole pozostaje aktywne. Przełączanie zachowuje scenę, poza "
            L"włączeniem przy 1 px: odstęp rośnie do 2 px i scena zaczyna się od nowa. Zmiana rozmiaru lub "
            L"monitorów także tworzy nową scenę. Bardzo duży świat może wymagać większego minimum. Kolory "
            L"komórek, tła i siatki zmieniają się osobno bez restartu. Losowy kolor żywych komórek zmienia "
            L"się przy każdym ręcznym lub automatycznym restarcie sceny. Zapisany kolor pozostaje "
            L"zachowany i wraca po wyłączeniu tej opcji. To samo działanie można włączyć osobno dla tła i "
            L"siatki; obie nowe opcje są domyślnie wyłączone.\r\n\r\nPRĘDKOŚĆ, PAUZA I AUTOMATYCZNY "
            L"RESTART\r\nPrędkość wynosi 0–240 pokoleń/s, niezależnie od odświeżania; 0 zatrzymuje rozwój. "
            L"Pauza i Wznów zachowują świat. Restart rozpoczyna wybrany tryb od nowa. Opcjonalny "
            L"automatyczny restart wykrywa nieruchome lub dokładnie powtarzające się widoczne fazy, także "
            L"oscylatory. Porównuje pokolenia, nie sekundy; pomija niewidoczne obszary. Wyniki "
            L"asynchroniczne mogą nieco opóźnić restart. Domyślnie: odstęp 8 px, 20 pokoleń/s, losowy "
            L"kolor żywych komórek i automatyczny restart włączone. Siatka jest domyślnie wyłączona. "
            L"Osiągana prędkość zależy od wydajności i liczby komórek. Automatyczny restart porównuje "
            L"obszary włączonych monitorów; luki między nimi nadal ewoluują, lecz nie są "
            L"porównywane.\r\n\r\nPrzywróć wartości\r\nPrzywracanie ustawia wyświetlany rozmiar komórki na "
            L"8 px z siatką lub bez niej (odstęp 9 lub 8 px), prędkość na 20 pokoleń/s, gęstość na 25 % i "
            L"trzy domyślne kolory. Pozostałe opcje są zachowane; wzorzec, który się nie mieści, zastępuje "
            L"mieszanka. Nowa scena powstaje tylko po zmianie odstępu lub gęstości w trybie "
            L"szumu.\r\n\r\nWYGASZACZ EKRANU WINDOWS\r\nGameOfLife.scr używa wszystkich monitorów i "
            L"ustawień oddzielnych od EXE. Włącz podgląd uruchamia pełny ekran przy otwartych "
            L"ustawieniach. Mały podgląd Windows skaluje cały świat. OK zapisuje; Anuluj lub Esc odrzuca "
            L"zmiany. Ruch myszy lub klawisz kończy pełnoekranowy wygaszacz. Nagrywanie MP4 jest dostępne "
            L"w EXE.\r\n\r\nPOŁOŻENIE I STAN OKIEN\r\nPrzy zamykaniu osobno zapisywane są pozycje okna "
            L"głównego i Informacje; dla Pomocy także rozmiar oraz stan normalny lub zmaksymalizowany "
            L"sprzed minimalizacji. Nie zależy to od zatwierdzania ustawień aplikacji. Zakończenie "
            L"aplikacji zamyka też Pomoc i Informacje.\r\n\r\nRENDEROWANIE I LICENCJE WZORCÓW\r\nRozwój i "
            L"porównania widocznych stanów wykonują shadery Direct3D 11 na GPU; po nieudanej inicjalizacji "
            L"sprzętowej dostępne jest renderowanie programowe. Każdy monitor używa sprawdzonego "
            L"regulatora klatek przy własnym odświeżaniu. MP4 wymaga Media Foundation i kodera H.264. "
            L"Wzorce pochodzą z LifeWiki (GFDL 1.2 lub nowsza) i publicznych zbiorów Alana Hensela w "
            L"domenie publicznej. Kod ma licencję MIT; informacje i licencje katalogu są oddzielne."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Rozmiar komórki: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Prędkość: %u pokoleń/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Gęstość początkowa: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Uruchom scenę ponownie" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Kolor żywych komórek…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Kolor tła…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Wybrane monitory współdzielą świat. Puste pasy są usuwane; wewnętrzne luki pozostają."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animacja działa…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animacja jest wstrzymana."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Nie udało się uruchomić renderera Direct3D."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Włącz podgląd"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Wyłącz podgląd"
        },
        LocalizedText{ TXT_MONITOR,
            L"Monitor"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Rozdzielczość"
        },
        LocalizedText{ TXT_POSITION,
            L"Położenie"
        },
        LocalizedText{ TXT_PRIMARY,
            L"główny"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Model monitora"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Częstotliwość odświeżania"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Głębia bitowa"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Format koloru"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Przestrzeń barw"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bitów/kanał"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bitów/piksel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Monitor animacji"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Gotowy"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Pokaż siatkę"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Kolor siatki…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Automatycznie restartuj ustaloną lub powtarzalną widoczną scenę"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Tylko znane wzorce"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Rozpocznij nagrywanie…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Zatrzymaj nagrywanie"
        },
        LocalizedText{ TXT_RECORDING,
            L"Trwa nagrywanie MP4…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Nagranie zapisano."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Nie udało się rozpocząć nagrywania MP4."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Zamknięcie aplikacji zakończy trwające nagrywanie."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Ustawienia nagrywania"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Rozdzielczość:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Liczba klatek/s:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Zmiany dotyczą następnego nagrania MP4."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Mieszanka pasujących wzorców"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Wybrany wzorzec nie mieści się już w świecie. Wybrano pasującą mieszankę."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Nie można wczytać katalogu znanych wzorców."
        },
    }),
    DefineLanguage(LANG_SK, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Náhodná farba pozadia pri každom reštarte scény" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Náhodná farba mriežky pri každom reštarte scény" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Šetrič Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Nastavenie šetriča obrazovky vo Windowse sa nedá otvoriť."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Obnoviť hodnoty" },
        LocalizedText{ TXT_SNAPSHOT, L"Snímka…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Snímka bola uložená." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Snímku sa nepodarilo uložiť." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blokovať šetrič pri animácii" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Náhodná farba živých buniek pri každom reštarte scény"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Prebieha inštalácia šetriča…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Prebieha odinštalácia šetriča…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Nainštalovať šetrič" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Odinštalovať šetrič" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Šetrič nebol nainštalovaný." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Šetrič bol nainštalovaný." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Šetrič bol odinštalovaný." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Šetrič sa nepodarilo odinštalovať. Ak je šetrič alebo jeho náhľad spustený, zatvorte ho a "
            L"skúste to znova."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Odinštalovanie zlyhalo, pretože sú otvorené nastavenia GameOfLife. Zatvorte ich a skúste to "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Slovenčina"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Ovládanie"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Nastavenia GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Jazyk:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Zrušiť"
        },
        LocalizedText{ TXT_EXIT,
            L"Koniec"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pozastaviť"
        },
        LocalizedText{ TXT_RESUME,
            L"Pokračovať"
        },
        LocalizedText{ TXT_HELP,
            L"Pomoc"
        },
        LocalizedText{ TXT_ABOUT,
            L"O programe"
        },
        LocalizedText{ TXT_CLOSE,
            L"Zavrieť"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Navštíviť web %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Web nemožno otvoriť v predvolenom prehliadači."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Adresu URL nemožno skopírovať do schránky."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Informácie nemožno skopírovať do schránky."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conwayova hra života na jednej spoločnej ploche monitorov."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Verzia:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Cieľová platforma:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Web:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Otvoriť v predvolenom prehliadači"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Kopírovať &adresu"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Kopírovať &informácie"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Prostriedok s licenciou nie je k dispozícii."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nPRAVIDLÁ\r\nConwayova hra života používa pravidlá B3/S23. Mŕtva bunka "
            L"ožije pri práve troch živých susedoch; živá prežije s dvoma alebo troma. Osem susedov zahŕňa "
            L"aj uhlopriečky. Všetky bunky sa menia súčasne. Protiľahlé okraje nadväzujú: ľavý na pravý a "
            L"horný na dolný.\r\n\r\nMONITORY A SPOLOČNÁ PLOCHA\r\nZačiarkavacie políčka v EXE zapínajú "
            L"monitory; nastavenia platia pre spoločnú hru. Jediný zapnutý monitor obsahuje celú plochu. "
            L"Pri výbere časti zostavy sa úplne prázdne riadky a stĺpce odstránia: ľavý a pravý monitor po "
            L"vypnutí prostredného nadviažu. Neodstrániteľné vnútorné diery zostávajú súčasťou simulácie. "
            L"Výber všetkých monitorov a režim SCR zachovávajú obdĺžnik celej zostavy vrátane "
            L"neviditeľných medzier. Každý monitor zobrazuje vlastný výrez tej istej "
            L"hry.\r\n\r\nPOČIATOČNÝ STAV A OBRAZCE\r\nPredvolený začiatok je náhodný šum s 25 % živých "
            L"buniek. Počiatočná hustota 0–100 % sa použije pri ďalšom reštarte. Iba známe obrazce používa "
            L"4 106 priložených obrazcov bez šumu a vypne hustotu. Vyberte zmes alebo pomenovaný obrazec; "
            L"rozmery sú v bunkách. Písaním názvu hľadajte v zozname. Ponúkajú sa len obrazce, ktoré sa "
            L"celé zmestia. Malé overené obrazce sa opakujú v oddelených kópiách, veľké a zložité začínajú "
            L"raz uprostred. Zmenšenie plochy môže nevhodný výber nahradiť zmesou. Zmena režimu alebo "
            L"obrazca vytvorí novú scénu. Reštarty výber zachovajú; katalóg funguje bez "
            L"internetu.\r\n\r\nVEĽKOSŤ BUNIEK, MRIEŽKA A FARBY\r\nBez mriežky je veľkosť bunky 1–64 px. "
            L"Zobraziť mriežku pridá okraj 1 px vnútri existujúceho rozstupu: zobrazená veľkosť a posúvač "
            L"sa znížia o jednu, použiteľné hodnoty sú 1–63. Vypnutie hodnotu vráti. Posúvač zachová celý "
            L"rozsah a z nedostupného konca sa vráti; políčko zostáva dostupné. Prepínanie zachová scénu "
            L"okrem zapnutia pri 1 px, keď sa rozstup zvýši na 2 px a vznikne nová scéna. Aj zmena "
            L"veľkosti alebo monitorov začne znova. Mimoriadne veľká plocha môže vyžadovať vyššie minimum. "
            L"Farby buniek, pozadia a mriežky sa menia nezávisle bez reštartu. Náhodná farba živých buniek "
            L"sa vyberá pri každom ručnom aj automatickom reštarte scény. Uložená farba sa neprepíše; "
            L"vypnutie tejto voľby ju obnoví. Rovnaké správanie možno samostatne zapnúť pre pozadie a "
            L"mriežku; obe nové voľby sú spočiatku vypnuté.\r\n\r\nRÝCHLOSŤ, POZASTAVENIE A AUTOMATICKÝ "
            L"REŠTART\r\nRýchlosť je 0–240 generácií/s nezávisle od obnovovania monitora; 0 zastaví vývoj. "
            L"Pozastaviť a Pokračovať zachovávajú plochu. Reštart vytvorí nový začiatok vo vybranom "
            L"režime. Voliteľný automatický reštart rozpoznáva statické aj presne sa opakujúce zobrazené "
            L"fázy vrátane oscilátorov. Porovnáva generácie, nie uplynulé sekundy; nezobrazené oblasti "
            L"vynecháva. Asynchrónne výsledky môžu reštart trochu oneskoriť. Predvolené hodnoty: rozstup 8 "
            L"px, 20 generácií/s, náhodná farba živých buniek a automatický reštart zapnuté. Mriežka je "
            L"predvolene vypnutá. Dosiahnutá rýchlosť závisí od výkonu a počtu buniek. Automatický reštart "
            L"porovnáva oblasti zapnutých monitorov; medzery medzi nimi sa ďalej vyvíjajú, ale do "
            L"porovnania sa nezahŕňajú.\r\n\r\nObnoviť hodnoty\r\nObnovenie nastaví zobrazenú veľkosť "
            L"bunky na 8 px s mriežkou aj bez nej (rozstup 9 alebo 8 px), rýchlosť na 20 generácií/s, "
            L"hustotu na 25 % a tri predvolené farby. Ostatné voľby zachová; obrazec, ktorý sa nezmestí, "
            L"nahradí zmesou. Nová scéna vznikne len pri zmene rozstupu alebo hustoty v režime "
            L"šumu.\r\n\r\nSAMOSTATNÁ APLIKÁCIA A ZÁZNAM MP4\r\nEXE ukladá nastavenia priebežne a "
            L"zaznamenáva prvý aktívny monitor do MP4. Ponúka Videá, prípadne Dokumenty. Viewport používa "
            L"rozmery a obnovovaciu frekvenciu monitora do 60 snímok/s. TV ponúka 1920 × 1080, 1440 × 1080 "
            L"alebo 1280 × 720 v pomere 16:9 pri 50, 25, 59,94 (60000/1001) alebo 29,97 (30000/1001) "
            L"snímkach/s. Pomer strán sa zachováva; TV používa progresívne BT.709 s obmedzeným rozsahom a "
            L"4:2:0. Samostatné nastavenia záznamu možno minimalizovať. OK uloží voľby pre ďalší záznam, "
            L"Zrušiť alebo Esc zahodí nepotvrdené zmeny. Zaznamenávaný monitor nemožno vypnúť; ostatné "
            L"výstupy možno meniť. Ukončenie počas záznamu vyžaduje potvrdenie. Pri aktívnej animácii "
            L"medzerník prepína pozastavenie, F9: Spustiť záznam; F10: Ukončiť záznam. Kurzor po 1 sekunde "
            L"nečinnosti zmizne a pohybom sa objaví. Tab/Shift+Tab prechádza prvky, Alt vyvolá "
            L"podčiarknuté voľby. Esc zavrie Pomoc/O programe alebo ukončí hlavné okno.\r\n\r\nSNÍMKA A "
            L"SPRÁVA ŠETRIČA V EXE\r\nSnímka uloží BMP/GIF/JPEG/PNG/TIFF/WebP zaznamenávaného monitora, inak "
            L"prvého aktívneho, v "
            L"jeho rozlíšení bez reštartu scény. Ponúka priečinok Obrázky, prípadne Dokumenty. Blokovanie "
            L"šetriča pri animácii bráni jeho spusteniu, kým je animácia viditeľná a nepozastavená. Nulová "
            L"rýchlosť nie je pozastavenie. Inštalácia z EXE rozbalí priložený SCR a vyberie ho ako šetrič "
            L"Windows. Inštalácia aj odinštalovanie môžu vyžadovať súhlas správcu; stavový riadok ukazuje "
            L"priebeh až do dokončenia. Pri blokovanom odstránení zavrite spustený šetrič, jeho nastavenia "
            L"a náhľad Windows.\r\n\r\nŠETRIČ OBRAZOVKY WINDOWS\r\nGameOfLife.scr používa všetky monitory "
            L"a nastavenia oddelené od EXE. Zapnúť náhľad spustí celú obrazovku pri otvorených "
            L"nastaveniach. Malý náhľad Windows zmenší celú spoločnú plochu. OK uloží nastavenia, Zrušiť "
            L"alebo Esc zmeny zahodí. Pohyb myši alebo kláves ukončí celoobrazovkový šetrič. Záznam MP4 je "
            L"dostupný v EXE.\r\n\r\nPOLOHA A STAV OKIEN\r\nPri zavretí sa samostatne ukladá poloha "
            L"hlavného okna a okna O programe; pri Pomoci aj veľkosť a normálny či maximalizovaný stav "
            L"pred prípadnou minimalizáciou. To nezávisí od potvrdenia nastavení aplikácie. Ukončenie "
            L"aplikácie zavrie aj Pomoc a O programe.\r\n\r\nVYKRESĽOVANIE A LICENCIE OBRAZCOV\r\nVývoj a "
            L"porovnávanie zobrazených stavov vykonávajú shadery Direct3D 11 na GPU; pri zlyhaní "
            L"hardvérovej inicializácie je dostupné softvérové vykresľovanie. Každý monitor používa "
            L"prevzatý framepacer podľa vlastnej obnovovacej frekvencie. MP4 vyžaduje Media Foundation a "
            L"kodér H.264. Obrazce sú z LifeWiki (GFDL 1.2 alebo novšia) a zo zbierok Alana Hensela vo "
            L"verejnej doméne. Kód má licenciu MIT; oznámenia a licencie katalógu sú "
            L"samostatné.\r\n\r\nŠetrič Windows… otvorí systémové nastavenie šetriča obrazovky."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nPRAVIDLÁ\r\nConwayova hra života používa pravidlá B3/S23. Mŕtva bunka "
            L"ožije pri práve troch živých susedoch; živá prežije s dvoma alebo troma. Osem susedov zahŕňa "
            L"aj uhlopriečky. Všetky bunky sa menia súčasne. Protiľahlé okraje nadväzujú: ľavý na pravý a "
            L"horný na dolný.\r\n\r\nMONITORY A SPOLOČNÁ PLOCHA\r\nZačiarkavacie políčka v EXE zapínajú "
            L"monitory; nastavenia platia pre spoločnú hru. Jediný zapnutý monitor obsahuje celú plochu. "
            L"Pri výbere časti zostavy sa úplne prázdne riadky a stĺpce odstránia: ľavý a pravý monitor po "
            L"vypnutí prostredného nadviažu. Neodstrániteľné vnútorné diery zostávajú súčasťou simulácie. "
            L"Výber všetkých monitorov a režim SCR zachovávajú obdĺžnik celej zostavy vrátane "
            L"neviditeľných medzier. Každý monitor zobrazuje vlastný výrez tej istej "
            L"hry.\r\n\r\nPOČIATOČNÝ STAV A OBRAZCE\r\nPredvolený začiatok je náhodný šum s 25 % živých "
            L"buniek. Počiatočná hustota 0–100 % sa použije pri ďalšom reštarte. Iba známe obrazce používa "
            L"4 106 priložených obrazcov bez šumu a vypne hustotu. Vyberte zmes alebo pomenovaný obrazec; "
            L"rozmery sú v bunkách. Písaním názvu hľadajte v zozname. Ponúkajú sa len obrazce, ktoré sa "
            L"celé zmestia. Malé overené obrazce sa opakujú v oddelených kópiách, veľké a zložité začínajú "
            L"raz uprostred. Zmenšenie plochy môže nevhodný výber nahradiť zmesou. Zmena režimu alebo "
            L"obrazca vytvorí novú scénu. Reštarty výber zachovajú; katalóg funguje bez "
            L"internetu.\r\n\r\nVEĽKOSŤ BUNIEK, MRIEŽKA A FARBY\r\nBez mriežky je veľkosť bunky 1–64 px. "
            L"Zobraziť mriežku pridá okraj 1 px vnútri existujúceho rozstupu: zobrazená veľkosť a posúvač "
            L"sa znížia o jednu, použiteľné hodnoty sú 1–63. Vypnutie hodnotu vráti. Posúvač zachová celý "
            L"rozsah a z nedostupného konca sa vráti; políčko zostáva dostupné. Prepínanie zachová scénu "
            L"okrem zapnutia pri 1 px, keď sa rozstup zvýši na 2 px a vznikne nová scéna. Aj zmena "
            L"veľkosti alebo monitorov začne znova. Mimoriadne veľká plocha môže vyžadovať vyššie minimum. "
            L"Farby buniek, pozadia a mriežky sa menia nezávisle bez reštartu. Náhodná farba živých buniek "
            L"sa vyberá pri každom ručnom aj automatickom reštarte scény. Uložená farba sa neprepíše; "
            L"vypnutie tejto voľby ju obnoví. Rovnaké správanie možno samostatne zapnúť pre pozadie a "
            L"mriežku; obe nové voľby sú spočiatku vypnuté.\r\n\r\nRÝCHLOSŤ, POZASTAVENIE A AUTOMATICKÝ "
            L"REŠTART\r\nRýchlosť je 0–240 generácií/s nezávisle od obnovovania monitora; 0 zastaví vývoj. "
            L"Pozastaviť a Pokračovať zachovávajú plochu. Reštart vytvorí nový začiatok vo vybranom "
            L"režime. Voliteľný automatický reštart rozpoznáva statické aj presne sa opakujúce zobrazené "
            L"fázy vrátane oscilátorov. Porovnáva generácie, nie uplynulé sekundy; nezobrazené oblasti "
            L"vynecháva. Asynchrónne výsledky môžu reštart trochu oneskoriť. Predvolené hodnoty: rozstup 8 "
            L"px, 20 generácií/s, náhodná farba živých buniek a automatický reštart zapnuté. Mriežka je "
            L"predvolene vypnutá. Dosiahnutá rýchlosť závisí od výkonu a počtu buniek. Automatický reštart "
            L"porovnáva oblasti zapnutých monitorov; medzery medzi nimi sa ďalej vyvíjajú, ale do "
            L"porovnania sa nezahŕňajú.\r\n\r\nObnoviť hodnoty\r\nObnovenie nastaví zobrazenú veľkosť "
            L"bunky na 8 px s mriežkou aj bez nej (rozstup 9 alebo 8 px), rýchlosť na 20 generácií/s, "
            L"hustotu na 25 % a tri predvolené farby. Ostatné voľby zachová; obrazec, ktorý sa nezmestí, "
            L"nahradí zmesou. Nová scéna vznikne len pri zmene rozstupu alebo hustoty v režime "
            L"šumu.\r\n\r\nŠETRIČ OBRAZOVKY WINDOWS\r\nGameOfLife.scr používa všetky monitory a nastavenia "
            L"oddelené od EXE. Zapnúť náhľad spustí celú obrazovku pri otvorených nastaveniach. Malý "
            L"náhľad Windows zmenší celú spoločnú plochu. OK uloží nastavenia, Zrušiť alebo Esc zmeny "
            L"zahodí. Pohyb myši alebo kláves ukončí celoobrazovkový šetrič. Záznam MP4 je dostupný v "
            L"EXE.\r\n\r\nPOLOHA A STAV OKIEN\r\nPri zavretí sa samostatne ukladá poloha hlavného okna a "
            L"okna O programe; pri Pomoci aj veľkosť a normálny či maximalizovaný stav pred prípadnou "
            L"minimalizáciou. To nezávisí od potvrdenia nastavení aplikácie. Ukončenie aplikácie zavrie aj "
            L"Pomoc a O programe.\r\n\r\nVYKRESĽOVANIE A LICENCIE OBRAZCOV\r\nVývoj a porovnávanie "
            L"zobrazených stavov vykonávajú shadery Direct3D 11 na GPU; pri zlyhaní hardvérovej "
            L"inicializácie je dostupné softvérové vykresľovanie. Každý monitor používa prevzatý "
            L"framepacer podľa vlastnej obnovovacej frekvencie. MP4 vyžaduje Media Foundation a kodér "
            L"H.264. Obrazce sú z LifeWiki (GFDL 1.2 alebo novšia) a zo zbierok Alana Hensela vo verejnej "
            L"doméne. Kód má licenciu MIT; oznámenia a licencie katalógu sú samostatné."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Veľkosť bunky: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Rýchlosť: %u generácií/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Počiatočná hustota: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Reštart scény" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Farba živých buniek…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Farba pozadia…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Vybrané monitory tvoria jednu hru. Prázdne pásy sa zlúčia, vnútorné diery zostávajú."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animácia beží…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animácia je pozastavená."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Renderer Direct3D sa nepodarilo inicializovať."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Zapnúť náhľad"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Vypnúť náhľad"
        },
        LocalizedText{ TXT_MONITOR,
            L"Monitor"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Rozlíšenie"
        },
        LocalizedText{ TXT_POSITION,
            L"Poloha"
        },
        LocalizedText{ TXT_PRIMARY,
            L"hlavný"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Model monitora"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Obnovovacia frekvencia"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bitová hĺbka"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Formát farby"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Farebný priestor"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bitov/kanál"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bitov/pixel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Monitor animácie"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Pripravený"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Zobraziť mriežku"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Farba mriežky…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Automaticky reštartovať ustálenú alebo opakujúcu sa zobrazenú scénu"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Iba známe obrazce"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Spustiť záznam…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Ukončiť záznam"
        },
        LocalizedText{ TXT_RECORDING,
            L"Prebieha záznam MP4…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Záznam bol uložený."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Záznam MP4 sa nepodarilo spustiť."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Ukončenie aplikácie ukončí práve prebiehajúci záznam."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Nastavenie záznamu"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Rozlíšenie:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Snímková frekvencia:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Zmeny sa použijú pri nasledujúcom zázname MP4."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Zmes vhodných obrazcov"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Vybraný obrazec sa už nezmestí na plochu. Bola zvolená zmes vhodných obrazcov."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Katalóg známych obrazcov sa nepodarilo načítať."
        },
    }),
    DefineLanguage(LANG_DA, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Tilfældig baggrundsfarve ved hver genstart af scenen" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Tilfældig gitterfarve ved hver genstart af scenen" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Windows-pauseskærm…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Indstillingerne for Windows-pauseskærmen kunne ikke åbnes."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Nulstil værdier" },
        LocalizedText{ TXT_SNAPSHOT, L"Skærmbillede…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Skærmbilledet blev gemt." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Skærmbilledet kunne ikke gemmes." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blokér pauseskærm under animation" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Tilfældig farve på levende celler ved hver genstart af scenen"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Installerer pauseskærm…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Afinstallerer pauseskærm…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Installer pauseskærm" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Afinstaller pauseskærm" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Pauseskærmen blev ikke installeret." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Pauseskærmen blev installeret." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Pauseskærmen blev afinstalleret." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Pauseskærmen kunne ikke afinstalleres. Hvis pauseskærmen eller forhåndsvisningen kører, skal "
            L"du lukke den og prøve igen."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Afinstallationen mislykkedes, fordi indstillingerne for GameOfLife er åbne. Luk vinduet, og "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Dansk"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Styring"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Indstillinger for GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Sprog:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Annuller"
        },
        LocalizedText{ TXT_EXIT,
            L"Afslut"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pause"
        },
        LocalizedText{ TXT_RESUME,
            L"Fortsæt"
        },
        LocalizedText{ TXT_HELP,
            L"Hjælp"
        },
        LocalizedText{ TXT_ABOUT,
            L"Om"
        },
        LocalizedText{ TXT_CLOSE,
            L"Luk"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Besøg webstedet %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Webstedet kan ikke åbnes i standardbrowseren."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"URL-adressen kunne ikke kopieres til udklipsholderen."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Oplysningerne kunne ikke kopieres til udklipsholderen."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conways Game of Life i én fælles verden på flere skærme."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Version:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Målplatform:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Websted:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Åbn i standardbrowseren"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Kopiér &URL"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Kopiér &oplysninger"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Licensressourcen er ikke tilgængelig."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nREGLER\r\nConways Game of Life bruger B3/S23. En død celle fødes med "
            L"præcis tre levende naboer; en levende overlever med to eller tre. De otte naboer omfatter "
            L"diagonaler. Alle celler ændres samtidig. Modsatte kanter forbindes: venstre med højre, "
            L"øverst med nederst.\r\n\r\nSKÆRME OG FÆLLES VERDEN\r\nAfkrydsningsfelter i EXE aktiverer "
            L"skærme; indstillinger gælder den fælles verden. Én aktiv skærm indeholder hele verden. Ved "
            L"delvist valg fjernes helt tomme rækker og kolonner: venstre og højre skærm mødes, når den "
            L"midterste slås fra. Indre huller, der ikke kan fjernes, forbliver i simuleringen. Valg af "
            L"alle skærme eller brug af SCR bevarer skrivebordets omsluttende rektangel med usynlige "
            L"mellemrum. Hver skærm viser sin del af samme simulering.\r\n\r\nSTARTTILSTAND OG "
            L"MØNSTRE\r\nStandardstarten er tilfældig støj med 25 % levende celler. Starttæthed på 0–100 % "
            L"bruges ved næste genstart. Kun kendte mønstre bruger 4.106 medfølgende mønstre uden støj og "
            L"deaktiverer tæthed. Vælg en blanding eller et navn; mål er i celler. Skriv et navn for at "
            L"søge. Kun mønstre, der kan være der i deres helhed, vises. Små kontrollerede mønstre "
            L"gentages i adskilte kopier, store eller komplekse én gang i midten. En mindre verden kan "
            L"erstatte et for stort valg med en blanding. Ændret tilstand eller mønster opretter en ny "
            L"scene. Genstart bevarer valget; kataloget virker offline.\r\n\r\nCELLER, GITTER OG "
            L"FARVER\r\nUden gitter er cellestørrelsen 1–64 px. Vis gitter tilføjer en kant på 1 px inden "
            L"for den nuværende afstand: vist værdi og skyder falder med én, med 1–63 som brugbare "
            L"værdier. Fravalg gendanner værdien. Skyderen beholder sit område og springer tilbage fra det "
            L"utilgængelige endepunkt; feltet forbliver aktivt. Skift bevarer scenen, undtagen tilvalg ved "
            L"1 px: afstanden bliver 2 px, og scenen begynder forfra. Ændring af størrelse eller skærme "
            L"starter også forfra. Meget store verdener kan kræve et større minimum. Celle-, baggrunds- og "
            L"gitterfarver ændres hver for sig uden genstart. Tilfældig farve på levende celler vælger en "
            L"ny farve ved hver manuel eller automatisk genstart af scenen. Den gemte farve bevares og "
            L"gendannes, når denne indstilling slås fra. Samme adfærd kan aktiveres særskilt for baggrund "
            L"og gitter; begge nye indstillinger er som standard slået fra.\r\n\r\nHASTIGHED, PAUSE OG "
            L"AUTOMATISK GENSTART\r\nHastigheden er 0–240 generationer/s uafhængigt af skærmens "
            L"opdatering; 0 standser udviklingen. Pause og Fortsæt bevarer verden. Genstart begynder i den "
            L"valgte tilstand. Valgfri automatisk genstart finder statiske og nøjagtigt gentagne synlige "
            L"faser, også oscillatorer. Den sammenligner generationer, ikke sekunder; usynlige områder "
            L"udelades. Asynkrone resultater kan forsinke genstart lidt. Standard: 8 px afstand, 20 "
            L"generationer/s, tilfældig farve på levende celler og automatisk genstart slået til. Gitteret "
            L"er slået fra som standard. Den opnåede hastighed afhænger af ydeevne og antal celler. "
            L"Automatisk genstart sammenligner områderne på aktiverede skærme; mellemrum udvikler sig "
            L"stadig, men udelades fra sammenligningen.\r\n\r\nNulstil værdier\r\nNulstilling gendanner "
            L"den viste cellestørrelse til 8 px med eller uden gitter (afstand 9 eller 8 px), hastighed 20 "
            L"generationer/s, tæthed 25 % og de tre standardfarver. Andre valg bevares; et mønster, der "
            L"ikke længere passer, erstattes af blandingen. En ny scene oprettes kun ved ændret afstand "
            L"eller ændret tæthed i støjtilstand.\r\n\r\nSELVSTÆNDIGT PROGRAM OG MP4-OPTAGELSE\r\nEXE "
            L"gemmer indstillinger løbende og optager den første aktive skærm som MP4. Videoer foreslås, "
            L"ellers Dokumenter. Viewport bruger skærmens mål og opdatering op til 60 billeder/s. TV "
            L"tilbyder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i 16:9 ved 50, 25, 59,94 (60000/1001) "
            L"eller 29,97 (30000/1001) billeder/s. Billedforholdet bevares; TV bruger progressiv BT.709 "
            L"med begrænset område og 4:2:0. Det uafhængige indstillingsvindue kan minimeres. OK gemmer "
            L"til næste optagelse; Annuller eller Esc forkaster ubekræftede ændringer. Den optagne skærm "
            L"kan ikke deaktiveres; andre udgange kan ændres. Afslutning under optagelse kræver "
            L"bekræftelse. Med fokus på animationen skifter Mellemrum pause, F9: Start optagelse; F10: "
            L"Stop optagelse. Markøren skjules efter 1 sekund uden aktivitet og vises ved bevægelse. "
            L"Tab/Shift+Tab skifter kontrol, Alt aktiverer understregede kommandoer. Esc lukker Hjælp/Om "
            L"eller afslutter fra hovedvinduet.\r\n\r\nØJEBLIKSBILLEDE OG PAUSESKÆRM I "
            L"EXE\r\nØjebliksbillede gemmer en BMP/GIF/JPEG/PNG/TIFF/WebP af den skærm, der optages, ellers "
            L"den første aktive, i "
            L"dens opløsning uden at genstarte scenen. Billeder foreslås, ellers Dokumenter. Blokering af "
            L"pauseskærmen under animation forhindrer dens start, mens animationen er synlig og ikke på "
            L"pause. Hastighed nul er ikke pause. Installation fra EXE pakker den medfølgende SCR ud og "
            L"vælger den som Windows-pauseskærm. Installation og afinstallation kan kræve "
            L"administratorgodkendelse; statuslinjen viser handlingen, indtil den er færdig. Hvis "
            L"fjernelse er blokeret, skal den kørende pauseskærm, dens indstillinger og Windows-eksemplet "
            L"lukkes.\r\n\r\nWINDOWS-PAUSESKÆRM\r\nGameOfLife.scr bruger alle skærme med indstillinger "
            L"adskilt fra EXE. Aktivér eksempel starter fuldskærmsanimation med indstillingerne åbne. Det "
            L"lille Windows-eksempel formindsker hele verden. OK gemmer; Annuller eller Esc forkaster "
            L"ændringer. Musebevægelse eller en tast afslutter fuldskærmspauseskærmen. MP4-optagelse "
            L"findes i EXE.\r\n\r\nVINDUERNES PLACERING OG TILSTAND\r\nVed lukning gemmes placeringen af "
            L"hovedvinduet og Om-vinduet separat; for Hjælp også størrelse og normal eller maksimeret "
            L"tilstand før en eventuel minimering. Dette er uafhængigt af bekræftelse af "
            L"programindstillinger. Afslutning af programmet lukker også Hjælp og Om.\r\n\r\nGENGIVELSE OG "
            L"MØNSTERLICENSER\r\nUdvikling og synlige sammenligninger bruger Direct3D 11-shadere på "
            L"GPU'en; softwaregengivelse findes, hvis hardwareinitialisering mislykkes. Hver skærm bruger "
            L"den gennemprøvede billedtaktstyring ved sin egen opdateringsfrekvens. MP4 kræver Media "
            L"Foundation og en H.264-koder. Mønstre kommer fra LifeWiki (GFDL 1.2 eller nyere) og Alan "
            L"Hensels samlinger i public domain. Programkoden bruger MIT; katalogets meddelelser og "
            L"licenser er særskilte.\r\n\r\nWindows-pauseskærm… åbner systemets indstillinger for "
            L"pauseskærmen."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nREGLER\r\nConways Game of Life bruger B3/S23. En død celle fødes med "
            L"præcis tre levende naboer; en levende overlever med to eller tre. De otte naboer omfatter "
            L"diagonaler. Alle celler ændres samtidig. Modsatte kanter forbindes: venstre med højre, "
            L"øverst med nederst.\r\n\r\nSKÆRME OG FÆLLES VERDEN\r\nAfkrydsningsfelter i EXE aktiverer "
            L"skærme; indstillinger gælder den fælles verden. Én aktiv skærm indeholder hele verden. Ved "
            L"delvist valg fjernes helt tomme rækker og kolonner: venstre og højre skærm mødes, når den "
            L"midterste slås fra. Indre huller, der ikke kan fjernes, forbliver i simuleringen. Valg af "
            L"alle skærme eller brug af SCR bevarer skrivebordets omsluttende rektangel med usynlige "
            L"mellemrum. Hver skærm viser sin del af samme simulering.\r\n\r\nSTARTTILSTAND OG "
            L"MØNSTRE\r\nStandardstarten er tilfældig støj med 25 % levende celler. Starttæthed på 0–100 % "
            L"bruges ved næste genstart. Kun kendte mønstre bruger 4.106 medfølgende mønstre uden støj og "
            L"deaktiverer tæthed. Vælg en blanding eller et navn; mål er i celler. Skriv et navn for at "
            L"søge. Kun mønstre, der kan være der i deres helhed, vises. Små kontrollerede mønstre "
            L"gentages i adskilte kopier, store eller komplekse én gang i midten. En mindre verden kan "
            L"erstatte et for stort valg med en blanding. Ændret tilstand eller mønster opretter en ny "
            L"scene. Genstart bevarer valget; kataloget virker offline.\r\n\r\nCELLER, GITTER OG "
            L"FARVER\r\nUden gitter er cellestørrelsen 1–64 px. Vis gitter tilføjer en kant på 1 px inden "
            L"for den nuværende afstand: vist værdi og skyder falder med én, med 1–63 som brugbare "
            L"værdier. Fravalg gendanner værdien. Skyderen beholder sit område og springer tilbage fra det "
            L"utilgængelige endepunkt; feltet forbliver aktivt. Skift bevarer scenen, undtagen tilvalg ved "
            L"1 px: afstanden bliver 2 px, og scenen begynder forfra. Ændring af størrelse eller skærme "
            L"starter også forfra. Meget store verdener kan kræve et større minimum. Celle-, baggrunds- og "
            L"gitterfarver ændres hver for sig uden genstart. Tilfældig farve på levende celler vælger en "
            L"ny farve ved hver manuel eller automatisk genstart af scenen. Den gemte farve bevares og "
            L"gendannes, når denne indstilling slås fra. Samme adfærd kan aktiveres særskilt for baggrund "
            L"og gitter; begge nye indstillinger er som standard slået fra.\r\n\r\nHASTIGHED, PAUSE OG "
            L"AUTOMATISK GENSTART\r\nHastigheden er 0–240 generationer/s uafhængigt af skærmens "
            L"opdatering; 0 standser udviklingen. Pause og Fortsæt bevarer verden. Genstart begynder i den "
            L"valgte tilstand. Valgfri automatisk genstart finder statiske og nøjagtigt gentagne synlige "
            L"faser, også oscillatorer. Den sammenligner generationer, ikke sekunder; usynlige områder "
            L"udelades. Asynkrone resultater kan forsinke genstart lidt. Standard: 8 px afstand, 20 "
            L"generationer/s, tilfældig farve på levende celler og automatisk genstart slået til. Gitteret "
            L"er slået fra som standard. Den opnåede hastighed afhænger af ydeevne og antal celler. "
            L"Automatisk genstart sammenligner områderne på aktiverede skærme; mellemrum udvikler sig "
            L"stadig, men udelades fra sammenligningen.\r\n\r\nNulstil værdier\r\nNulstilling gendanner "
            L"den viste cellestørrelse til 8 px med eller uden gitter (afstand 9 eller 8 px), hastighed 20 "
            L"generationer/s, tæthed 25 % og de tre standardfarver. Andre valg bevares; et mønster, der "
            L"ikke længere passer, erstattes af blandingen. En ny scene oprettes kun ved ændret afstand "
            L"eller ændret tæthed i støjtilstand.\r\n\r\nWINDOWS-PAUSESKÆRM\r\nGameOfLife.scr bruger alle "
            L"skærme med indstillinger adskilt fra EXE. Aktivér eksempel starter fuldskærmsanimation med "
            L"indstillingerne åbne. Det lille Windows-eksempel formindsker hele verden. OK gemmer; "
            L"Annuller eller Esc forkaster ændringer. Musebevægelse eller en tast afslutter "
            L"fuldskærmspauseskærmen. MP4-optagelse findes i EXE.\r\n\r\nVINDUERNES PLACERING OG "
            L"TILSTAND\r\nVed lukning gemmes placeringen af hovedvinduet og Om-vinduet separat; for Hjælp "
            L"også størrelse og normal eller maksimeret tilstand før en eventuel minimering. Dette er "
            L"uafhængigt af bekræftelse af programindstillinger. Afslutning af programmet lukker også "
            L"Hjælp og Om.\r\n\r\nGENGIVELSE OG MØNSTERLICENSER\r\nUdvikling og synlige sammenligninger "
            L"bruger Direct3D 11-shadere på GPU'en; softwaregengivelse findes, hvis hardwareinitialisering "
            L"mislykkes. Hver skærm bruger den gennemprøvede billedtaktstyring ved sin egen "
            L"opdateringsfrekvens. MP4 kræver Media Foundation og en H.264-koder. Mønstre kommer fra "
            L"LifeWiki (GFDL 1.2 eller nyere) og Alan Hensels samlinger i public domain. Programkoden "
            L"bruger MIT; katalogets meddelelser og licenser er særskilte."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Cellestørrelse: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Hastighed: %u generationer/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Starttæthed: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Genstart scenen" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Farve på levende celler…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Baggrundsfarve…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Valgte skærme deler én verden. Tomme bånd fjernes; indre huller bevares."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animationen kører…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animationen er sat på pause."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Direct3D kunne ikke initialiseres."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Forhåndsvisning" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Stop forhåndsvisning" },
        LocalizedText{ TXT_MONITOR,
            L"Skærm"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Opløsning"
        },
        LocalizedText{ TXT_POSITION,
            L"Placering"
        },
        LocalizedText{ TXT_PRIMARY,
            L"primær"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Skærmmodel"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Opdateringsfrekvens"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bitdybde"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Farveformat"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Farverum"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bit/kanal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bit/pixel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Animationsskærm"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Klar"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Vis gitter"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Gitterfarve…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Genstart automatisk en stabil eller gentaget synlig scene"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Kun kendte mønstre"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Start optagelse…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Stop optagelse"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4-optagelse i gang…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Optagelsen blev gemt."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"MP4-optagelsen kunne ikke startes."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Hvis du lukker programmet, stoppes den igangværende optagelse."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Optagelsesindstillinger"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Opløsning:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Billedfrekvens:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Ændringerne gælder næste MP4-optagelse."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Blanding af passende mønstre"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Det valgte mønster passer ikke længere. En passende blanding er valgt."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Kataloget med kendte mønstre kunne ikke indlæses."
        },
    }),
    DefineLanguage(LANG_FI, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Satunnainen taustaväri aina näkymän alkaessa uudelleen"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Satunnainen ruudukon väri aina näkymän alkaessa uudelleen" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Windowsin näytönsäästäjä…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED, L"Windowsin näytönsäästäjän asetuksia ei voi avata." },
        LocalizedText{ TXT_RESET_SETTINGS, L"Palauta arvot" },
        LocalizedText{ TXT_SNAPSHOT, L"Tilannekuva…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Tilannekuva tallennettiin." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Tilannekuvaa ei voitu tallentaa." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Estä näytönsäästäjä animaation aikana" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Elävien solujen satunnainen väri aina näkymän alkaessa uudelleen"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Näytönsäästäjää asennetaan…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Näytönsäästäjää poistetaan…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Asenna näytönsäästäjä" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Poista näytönsäästäjä" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Näytönsäästäjää ei asennettu." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Näytönsäästäjä asennettiin." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Näytönsäästäjä poistettiin." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Näytönsäästäjän poistaminen epäonnistui. Jos näytönsäästäjä tai sen esikatselu on käynnissä, "
            L"sulje se ja yritä uudelleen."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Asennuksen poisto epäonnistui, koska GameOfLife-asetukset ovat avoinna. Sulje ikkuna ja "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Suomi"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Ohjaus"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"GameOfLife-asetukset"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Kieli:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Peruuta"
        },
        LocalizedText{ TXT_EXIT,
            L"Lopeta"
        },
        LocalizedText{ TXT_PAUSE,
            L"Keskeytä"
        },
        LocalizedText{ TXT_RESUME,
            L"Jatka"
        },
        LocalizedText{ TXT_HELP,
            L"Ohje"
        },
        LocalizedText{ TXT_ABOUT,
            L"Tietoja"
        },
        LocalizedText{ TXT_CLOSE,
            L"Sulje"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Käy verkkosivustolla %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Sivustoa ei voi avata oletusselaimessa."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"URL-osoitetta ei voitu kopioida leikepöydälle."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Tietoja ei voitu kopioida leikepöydälle."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conwayn Game of Life näyttöjen yhteisessä maailmassa."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Versio:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Kohdealusta:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Verkkosivusto:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Avaa oletusselaimessa"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Kopioi &URL"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Kopioi &tiedot"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Lisenssiresurssi ei ole käytettävissä."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nSÄÄNNÖT\r\nConwayn Game of Life käyttää sääntöä B3/S23. Kuollut solu "
            L"syntyy, kun sillä on täsmälleen kolme elävää naapuria; elävä säilyy kahdella tai kolmella. "
            L"Kahdeksaan naapuriin kuuluvat vinottaiset. Kaikki solut muuttuvat yhtä aikaa. Vastakkaiset "
            L"reunat liittyvät toisiinsa: vasen oikeaan, yläreuna alareunaan.\r\n\r\nNÄYTÖT JA YHTEINEN "
            L"MAAILMA\r\nEXE:n valintaruudut kytkevät näytöt käyttöön; asetukset koskevat yhteistä "
            L"maailmaa. Yksi käytössä oleva näyttö sisältää koko maailman. Osittaisessa valinnassa täysin "
            L"tyhjät rivit ja sarakkeet poistetaan: vasen ja oikea näyttö yhdistyvät, kun keskimmäinen "
            L"poistetaan käytöstä. Poistamattomat sisäaukot pysyvät simulaatiossa. Kaikkien näyttöjen "
            L"valinta tai SCR säilyttää työpöydän rajaavan suorakulmion näkymättömine väleineen. Jokainen "
            L"näyttö näyttää oman osansa samasta simulaatiosta.\r\n\r\nALKUTILA JA KUVIOT\r\nOletusalku on "
            L"satunnainen kohina, jossa on 25 % eläviä soluja. Alkutiheys 0–100 % vaikuttaa seuraavaan "
            L"uudelleenaloitukseen. Vain tunnetut kuviot käyttää 4 106 mukana tulevaa kuviota ilman "
            L"kohinaa ja poistaa tiheyden käytöstä. Valitse sekoitus tai nimetty kuvio; mitat ovat "
            L"soluina. Kirjoita nimi hakeaksesi. Vain kokonaan mahtuvat kuviot näytetään. Pienet "
            L"tarkistetut kuviot toistuvat erillisinä kopioina, suuret tai monimutkaiset kerran keskellä. "
            L"Pienentäminen voi korvata liian suuren valinnan sekoituksella. Tilan tai kuvion vaihtaminen "
            L"luo uuden tilanteen. Uudelleenaloitus säilyttää valinnan; luettelo toimii ilman "
            L"verkkoa.\r\n\r\nSOLUKOKO, RUUDUKKO JA VÄRIT\r\nIlman ruudukkoa solukoko on 1–64 px. Ruudukko "
            L"lisää 1 px reunan nykyisen jaon sisään: näytetty arvo ja liukusäädin pienenevät yhdellä, "
            L"käytettävissä on 1–63. Poiskytkentä palauttaa arvon. Liukusäätimen asteikko säilyy ja säädin "
            L"palautuu estetystä päätepisteestä; valintaruutu pysyy käytössä. Vaihtaminen säilyttää "
            L"tilanteen, paitsi päällekytkentä koossa 1 px: jako kasvaa 2 px:iin ja tilanne alkaa "
            L"uudelleen. Myös solukoon tai näyttöjen muutos aloittaa uudelleen. Erittäin suuri maailma voi "
            L"vaatia suuremman vähimmäiskoon. Solujen, taustan ja ruudukon värit vaihtuvat erikseen ilman "
            L"uudelleenaloitusta. Elävien solujen satunnaisväri valitsee uuden värin jokaisella "
            L"manuaalisella tai automaattisella uudelleenaloituksella. Tallennettu väri säilyy ja "
            L"palautuu, kun valinta poistetaan käytöstä. Saman toiminnan voi ottaa erikseen käyttöön "
            L"taustalle ja ruudukolle; molemmat uudet valinnat ovat oletuksena pois "
            L"käytöstä.\r\n\r\nNOPEUS, TAUKO JA AUTOMAATTINEN UUDELLEENALOITUS\r\nNopeus on 0–240 "
            L"sukupolvea/s näytön virkistyksestä riippumatta; 0 pysäyttää kehityksen. Tauko ja Jatka "
            L"säilyttävät maailman. Uudelleenaloitus aloittaa valitussa tilassa. Valinnainen automaattinen "
            L"uudelleenaloitus tunnistaa pysyvät ja täsmälleen toistuvat näkyvät vaiheet, myös "
            L"oskillaattorit. Se vertaa sukupolvia, ei sekunteja, ja jättää näkymättömät alueet pois. "
            L"Asynkroniset tulokset voivat viivästyttää aloitusta hieman. Oletukset: jako 8 px, 20 "
            L"sukupolvea/s, elävien solujen satunnaisväri ja automaattinen uudelleenaloitus käytössä. "
            L"Ruudukko on oletuksena pois käytöstä. Saavutettu nopeus riippuu suorituskyvystä ja "
            L"solumäärästä. Automaattinen uudelleenaloitus vertaa käytössä olevien näyttöjen alueita; "
            L"välit kehittyvät edelleen mutta jäävät vertailun ulkopuolelle.\r\n\r\nPalauta "
            L"arvot\r\nPalautus asettaa näytetyksi solukooksi 8 px ruudukolla tai ilman (jako 9 tai 8 px), "
            L"nopeudeksi 20 sukupolvea/s, tiheydeksi 25 % ja kolme oletusväriä. Muut valinnat säilyvät; "
            L"kuvio, joka ei enää mahdu, korvataan sekoituksella. Uusi tilanne luodaan vain, jos jako "
            L"muuttuu tai tiheys muuttuu kohinatilassa.\r\n\r\nERILLISSOVELLUS JA MP4-TALLENNUS\r\nEXE "
            L"tallentaa asetukset jatkuvasti ja ensimmäisen aktiivisen näytön MP4:ksi. Ehdotettu kansio on "
            L"Videot, varalla Tiedostot. Viewport käyttää näytön kokoa ja virkistystä enintään 60 kuvaa/s. "
            L"TV tarjoaa 1920 × 1080, 1440 × 1080 tai 1280 × 720, 16:9, nopeudella 50, 25, 59,94 "
            L"(60000/1001) tai 29,97 (30000/1001) kuvaa/s. Kuvasuhde säilyy; TV käyttää progressiivista, "
            L"rajatun alueen BT.709-videota ja 4:2:0-näytteistystä. Erillisen asetusikkunan voi pienentää. "
            L"OK tallentaa seuraavaa tallennusta varten; Peruuta tai Esc hylkää vahvistamattomat "
            L"muutokset. Tallennettavaa näyttöä ei voi poistaa käytöstä; muita lähtöjä voi muuttaa. "
            L"Lopetus tallennuksen aikana vaatii vahvistuksen. Animaation ollessa aktiivinen Välilyönti "
            L"vaihtaa tauon, F9: Aloita tallennus; F10: Lopeta tallennus. Osoitin katoaa 1 sekunnin "
            L"toimettomuuden jälkeen ja palaa liikkeestä. Tab/Shift+Tab siirtyy säätimissä, Alt valitsee "
            L"alleviivatut komennot. Esc sulkee Ohje/Tietoja-ikkunan tai poistuu "
            L"pääikkunasta.\r\n\r\nTILANNEKUVA JA NÄYTÖNSÄÄSTÄJÄN HALLINTA EXE:SSÄ\r\nTilannekuva "
            L"tallentaa BMP/GIF/JPEG/PNG/TIFF/WebP:n tallennettavasta näytöstä tai muuten ensimmäisestä "
            L"aktiivisesta näytöstä sen "
            L"tarkkuudella aloittamatta tilannetta uudelleen. Ehdotettu kansio on Kuvat, varalla "
            L"Tiedostot. Näytönsäästäjän esto animaation aikana estää sen käynnistymisen, kun animaatio "
            L"näkyy eikä ole tauolla. Nollanopeus ei ole tauko. Asennus EXE:stä purkaa mukana tulevan "
            L"SCR:n ja valitsee sen Windowsin näytönsäästäjäksi. Asennus ja poisto voivat vaatia "
            L"järjestelmänvalvojan hyväksynnän; tilarivi näyttää toiminnon sen valmistumiseen asti. Jos "
            L"poisto estyy, sulje käynnissä oleva säästäjä, sen asetukset ja Windowsin "
            L"esikatselu.\r\n\r\nWINDOWSIN NÄYTÖNSÄÄSTÄJÄ\r\nGameOfLife.scr käyttää kaikkia näyttöjä ja "
            L"EXE:stä erillisiä asetuksia. Esikatselu käynnistää koko näytön animaation asetusten pysyessä "
            L"auki. Windowsin pieni esikatselu pienentää koko maailman. OK tallentaa, Peruuta tai Esc "
            L"hylkää muutokset. Hiiren liike tai näppäin sulkee koko näytön säästäjän. MP4-tallennus on "
            L"käytettävissä EXE:ssä.\r\n\r\nIKKUNOIDEN SIJAINTI JA TILA\r\nSulkeminen tallentaa pääikkunan "
            L"ja Tietoja-ikkunan sijainnit erikseen; Ohjeesta myös koon ja normaalin tai suurennetun tilan "
            L"ennen mahdollista pienentämistä. Tämä ei riipu sovellusasetusten vahvistamisesta. "
            L"Sovelluksen lopettaminen sulkee myös Ohje- ja Tietoja-ikkunat.\r\n\r\nPIIRTÄMINEN JA "
            L"KUVIOIDEN LISENSSIT\r\nKehitys ja näkyvien tilojen vertailu käyttävät GPU:n Direct3D 11 "
            L"-varjostimia; ohjelmistopiirto on käytettävissä, jos laitteistoalustus epäonnistuu. Jokainen "
            L"näyttö käyttää samaa koeteltua ruudunajoitusta omalla virkistystaajuudellaan. MP4 vaatii "
            L"Media Foundationin ja H.264-kooderin. Kuviot ovat LifeWikistä (GFDL 1.2 tai uudempi) ja Alan "
            L"Henselin vapaista public domain -kokoelmista. Ohjelmakoodi on MIT-lisensoitu; luettelon "
            L"ilmoitukset ja lisenssit ovat erilliset.\r\n\r\nWindowsin näytönsäästäjä… avaa järjestelmän "
            L"näytönsäästäjän asetukset."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nSÄÄNNÖT\r\nConwayn Game of Life käyttää sääntöä B3/S23. Kuollut solu "
            L"syntyy, kun sillä on täsmälleen kolme elävää naapuria; elävä säilyy kahdella tai kolmella. "
            L"Kahdeksaan naapuriin kuuluvat vinottaiset. Kaikki solut muuttuvat yhtä aikaa. Vastakkaiset "
            L"reunat liittyvät toisiinsa: vasen oikeaan, yläreuna alareunaan.\r\n\r\nNÄYTÖT JA YHTEINEN "
            L"MAAILMA\r\nEXE:n valintaruudut kytkevät näytöt käyttöön; asetukset koskevat yhteistä "
            L"maailmaa. Yksi käytössä oleva näyttö sisältää koko maailman. Osittaisessa valinnassa täysin "
            L"tyhjät rivit ja sarakkeet poistetaan: vasen ja oikea näyttö yhdistyvät, kun keskimmäinen "
            L"poistetaan käytöstä. Poistamattomat sisäaukot pysyvät simulaatiossa. Kaikkien näyttöjen "
            L"valinta tai SCR säilyttää työpöydän rajaavan suorakulmion näkymättömine väleineen. Jokainen "
            L"näyttö näyttää oman osansa samasta simulaatiosta.\r\n\r\nALKUTILA JA KUVIOT\r\nOletusalku on "
            L"satunnainen kohina, jossa on 25 % eläviä soluja. Alkutiheys 0–100 % vaikuttaa seuraavaan "
            L"uudelleenaloitukseen. Vain tunnetut kuviot käyttää 4 106 mukana tulevaa kuviota ilman "
            L"kohinaa ja poistaa tiheyden käytöstä. Valitse sekoitus tai nimetty kuvio; mitat ovat "
            L"soluina. Kirjoita nimi hakeaksesi. Vain kokonaan mahtuvat kuviot näytetään. Pienet "
            L"tarkistetut kuviot toistuvat erillisinä kopioina, suuret tai monimutkaiset kerran keskellä. "
            L"Pienentäminen voi korvata liian suuren valinnan sekoituksella. Tilan tai kuvion vaihtaminen "
            L"luo uuden tilanteen. Uudelleenaloitus säilyttää valinnan; luettelo toimii ilman "
            L"verkkoa.\r\n\r\nSOLUKOKO, RUUDUKKO JA VÄRIT\r\nIlman ruudukkoa solukoko on 1–64 px. Ruudukko "
            L"lisää 1 px reunan nykyisen jaon sisään: näytetty arvo ja liukusäädin pienenevät yhdellä, "
            L"käytettävissä on 1–63. Poiskytkentä palauttaa arvon. Liukusäätimen asteikko säilyy ja säädin "
            L"palautuu estetystä päätepisteestä; valintaruutu pysyy käytössä. Vaihtaminen säilyttää "
            L"tilanteen, paitsi päällekytkentä koossa 1 px: jako kasvaa 2 px:iin ja tilanne alkaa "
            L"uudelleen. Myös solukoon tai näyttöjen muutos aloittaa uudelleen. Erittäin suuri maailma voi "
            L"vaatia suuremman vähimmäiskoon. Solujen, taustan ja ruudukon värit vaihtuvat erikseen ilman "
            L"uudelleenaloitusta. Elävien solujen satunnaisväri valitsee uuden värin jokaisella "
            L"manuaalisella tai automaattisella uudelleenaloituksella. Tallennettu väri säilyy ja "
            L"palautuu, kun valinta poistetaan käytöstä. Saman toiminnan voi ottaa erikseen käyttöön "
            L"taustalle ja ruudukolle; molemmat uudet valinnat ovat oletuksena pois "
            L"käytöstä.\r\n\r\nNOPEUS, TAUKO JA AUTOMAATTINEN UUDELLEENALOITUS\r\nNopeus on 0–240 "
            L"sukupolvea/s näytön virkistyksestä riippumatta; 0 pysäyttää kehityksen. Tauko ja Jatka "
            L"säilyttävät maailman. Uudelleenaloitus aloittaa valitussa tilassa. Valinnainen automaattinen "
            L"uudelleenaloitus tunnistaa pysyvät ja täsmälleen toistuvat näkyvät vaiheet, myös "
            L"oskillaattorit. Se vertaa sukupolvia, ei sekunteja, ja jättää näkymättömät alueet pois. "
            L"Asynkroniset tulokset voivat viivästyttää aloitusta hieman. Oletukset: jako 8 px, 20 "
            L"sukupolvea/s, elävien solujen satunnaisväri ja automaattinen uudelleenaloitus käytössä. "
            L"Ruudukko on oletuksena pois käytöstä. Saavutettu nopeus riippuu suorituskyvystä ja "
            L"solumäärästä. Automaattinen uudelleenaloitus vertaa käytössä olevien näyttöjen alueita; "
            L"välit kehittyvät edelleen mutta jäävät vertailun ulkopuolelle.\r\n\r\nPalauta "
            L"arvot\r\nPalautus asettaa näytetyksi solukooksi 8 px ruudukolla tai ilman (jako 9 tai 8 px), "
            L"nopeudeksi 20 sukupolvea/s, tiheydeksi 25 % ja kolme oletusväriä. Muut valinnat säilyvät; "
            L"kuvio, joka ei enää mahdu, korvataan sekoituksella. Uusi tilanne luodaan vain, jos jako "
            L"muuttuu tai tiheys muuttuu kohinatilassa.\r\n\r\nWINDOWSIN NÄYTÖNSÄÄSTÄJÄ\r\nGameOfLife.scr "
            L"käyttää kaikkia näyttöjä ja EXE:stä erillisiä asetuksia. Esikatselu käynnistää koko näytön "
            L"animaation asetusten pysyessä auki. Windowsin pieni esikatselu pienentää koko maailman. OK "
            L"tallentaa, Peruuta tai Esc hylkää muutokset. Hiiren liike tai näppäin sulkee koko näytön "
            L"säästäjän. MP4-tallennus on käytettävissä EXE:ssä.\r\n\r\nIKKUNOIDEN SIJAINTI JA "
            L"TILA\r\nSulkeminen tallentaa pääikkunan ja Tietoja-ikkunan sijainnit erikseen; Ohjeesta myös "
            L"koon ja normaalin tai suurennetun tilan ennen mahdollista pienentämistä. Tämä ei riipu "
            L"sovellusasetusten vahvistamisesta. Sovelluksen lopettaminen sulkee myös Ohje- ja "
            L"Tietoja-ikkunat.\r\n\r\nPIIRTÄMINEN JA KUVIOIDEN LISENSSIT\r\nKehitys ja näkyvien tilojen "
            L"vertailu käyttävät GPU:n Direct3D 11 -varjostimia; ohjelmistopiirto on käytettävissä, jos "
            L"laitteistoalustus epäonnistuu. Jokainen näyttö käyttää samaa koeteltua ruudunajoitusta "
            L"omalla virkistystaajuudellaan. MP4 vaatii Media Foundationin ja H.264-kooderin. Kuviot ovat "
            L"LifeWikistä (GFDL 1.2 tai uudempi) ja Alan Henselin vapaista public domain -kokoelmista. "
            L"Ohjelmakoodi on MIT-lisensoitu; luettelon ilmoitukset ja lisenssit ovat erilliset."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Solukoko: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Nopeus: %u sukupolvea/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Alkutiheys: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Aloita näkymä uudelleen" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Elävien solujen väri…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Taustaväri…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Valitut näytöt jakavat maailman. Tyhjät kaistat poistetaan; sisäiset aukot jäävät."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animaatio on käynnissä…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animaatio on keskeytetty."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Direct3D-renderöintiä ei voitu alustaa."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Esikatselu" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Lopeta esikatselu" },
        LocalizedText{ TXT_MONITOR,
            L"Näyttö"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Tarkkuus"
        },
        LocalizedText{ TXT_POSITION,
            L"Sijainti"
        },
        LocalizedText{ TXT_PRIMARY,
            L"ensisijainen"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Näytön malli"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Virkistystaajuus"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bittisyvyys"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Värimuoto"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Väriavaruus"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bittiä/kanava"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bittiä/pikseli"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Animaation näyttö"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Valmis"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Näytä ruudukko"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Ruudukon väri…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Aloita vakaa tai toistuva näkyvä tilanne automaattisesti uudelleen"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Vain tunnetut kuviot"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Aloita tallennus…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Lopeta tallennus"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4-tallennus käynnissä…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Tallenne tallennettiin."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"MP4-tallennusta ei voitu aloittaa."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Sovelluksen sulkeminen lopettaa käynnissä olevan tallennuksen."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Tallennusasetukset"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Tarkkuus:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Kuvataajuus:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Muutokset koskevat seuraavaa MP4-tallennusta."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Sopivien kuvioiden sekoitus"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Valittu kuvio ei enää mahdu. Sopiva sekoitus valittiin."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Tunnettujen kuvioiden luetteloa ei voitu ladata."
        },
    }),
    DefineLanguage(LANG_IS, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Slembinn bakgrunnslitur við hverja endurræsingu senunnar"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Slembinn litur hnitanets við hverja endurræsingu senunnar" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Skjáhvíla Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED, L"Ekki tókst að opna stillingar skjáhvílu Windows." },
        LocalizedText{ TXT_RESET_SETTINGS, L"Endurstilla gildi" },
        LocalizedText{ TXT_SNAPSHOT, L"Skjámynd…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Skjámyndin var vistuð." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Ekki tókst að vista skjámyndina." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Hindra skjáhvílu meðan hreyfimynd er í gangi" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Slembilitur lifandi reita við hverja endurræsingu senunnar"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Verið er að setja upp skjáhvílu…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Verið er að fjarlægja skjáhvílu…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Setja upp skjáhvílu" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Fjarlægja skjáhvílu" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Skjáhvílan var ekki sett upp." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Skjáhvílan var sett upp." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Skjáhvílan var fjarlægð." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Ekki tókst að fjarlægja skjáhvíluna. Ef skjáhvílan eða forskoðun hennar er í gangi skaltu loka "
            L"henni og reyna aftur."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Fjarlæging mistókst vegna þess að stillingar GameOfLife eru opnar. Lokaðu glugganum og "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Íslenska"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Stjórnun"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Stillingar GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Tungumál:"
        },
        LocalizedText{ TXT_OK,
            L"Í lagi"
        },
        LocalizedText{ TXT_CANCEL,
            L"Hætta við"
        },
        LocalizedText{ TXT_EXIT,
            L"Hætta"
        },
        LocalizedText{ TXT_PAUSE,
            L"Gera hlé"
        },
        LocalizedText{ TXT_RESUME,
            L"Halda áfram"
        },
        LocalizedText{ TXT_HELP,
            L"Hjálp"
        },
        LocalizedText{ TXT_ABOUT,
            L"Um"
        },
        LocalizedText{ TXT_CLOSE,
            L"Loka"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Heimsækja vefsvæði %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Ekki er hægt að opna vefsvæðið í sjálfgefnum vafra."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Ekki tókst að afrita vefslóðina á klippispjaldið."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Ekki tókst að afrita upplýsingarnar á klippispjaldið."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Lífsleikur Conways í einum sameiginlegum heimi á mörgum skjám."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Útgáfa:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Markvettvangur:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Vefsvæði:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Opna í sjálfgefnum vafra"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Afrita &vefslóð"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Afrita &upplýsingar"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Leyfistilfangið er ekki tiltækt."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nREGLUR\r\nLífsleikur Conways notar B3/S23. Dauður reitur lifnar með "
            L"nákvæmlega þremur lifandi nágrönnum; lifandi reitur lifir áfram með tveimur eða þremur. "
            L"Nágrannarnir átta innihalda hornalínur. Allir reitir breytast samtímis. Gagnstæðar brúnir "
            L"tengjast: vinstri við hægri, efri við neðri.\r\n\r\nSKJÁIR OG SAMEIGINLEGUR "
            L"HEIMUR\r\nGátreitir í EXE virkja skjái; stillingar gilda fyrir sameiginlega heiminn. Einn "
            L"virkur skjár inniheldur allan heiminn. Þegar hluti skjáa er valinn hverfa alveg auðar raðir "
            L"og dálkar: vinstri og hægri skjár tengjast þegar slökkt er á miðjuskjánum. Innri eyður sem "
            L"ekki er hægt að fjarlægja haldast í hermuninni. Allir skjáir valdir, eða SCR, varðveita "
            L"rétthyrning skjáborðsins með ósýnilegum bilum. Hver skjár sýnir sinn hluta sömu "
            L"hermunar.\r\n\r\nUPPHAFSSTAÐA OG MYNSTUR\r\nSjálfgefin byrjun er slembisuð með 25 % lifandi "
            L"reitum. Upphafsþéttleiki 0–100 % gildir við næstu endurræsingu. Aðeins þekkt mynstur notar "
            L"4.106 innbyggð mynstur án suðs og slekkur á þéttleika. Veldu blöndu eða heiti; mál eru í "
            L"reitum. Sláðu inn nafn til að leita. Aðeins mynstur sem rúmast heil birtast. Lítil staðfest "
            L"mynstur endurtaka sig í aðskildum eintökum, stór eða flókin birtast einu sinni í miðju. "
            L"Minni heimur getur skipt of stóru vali út fyrir blöndu. Breyttur hamur eða mynstur býr til "
            L"nýja senu. Endurræsing varðveitir valið; skráin virkar án nets.\r\n\r\nREITASTÆRÐ, HNITANET "
            L"OG LITIR\r\nÁn hnitanets er reitastærð 1–64 px. Hnitanet bætir 1 px brún innan núverandi "
            L"bils: birt stærð og sleði lækka um einn, með 1–63 nýtanlegt. Þegar slökkt er færist gildið "
            L"til baka. Sleðinn heldur öllu sviðinu og stekkur til baka frá ótiltæka endanum; gátreiturinn "
            L"helst virkur. Skipting varðveitir senuna nema þegar kveikt er við 1 px: bilið verður 2 px og "
            L"ný sena byrjar. Breytt stærð eða skjával endurræsir einnig. Mjög stórir heimar geta þurft "
            L"hærra lágmark. Litir reita, bakgrunns og hnitanets breytast sjálfstætt án endurræsingar. "
            L"Tilviljanakenndur litur lifandi reita velur nýjan lit við hverja handvirka eða sjálfvirka "
            L"endurræsingu senunnar. Vistaði liturinn varðveitist og kemur aftur þegar slökkt er á þessum "
            L"valkosti. Hægt er að virkja sömu hegðun sérstaklega fyrir bakgrunn og hnitanet; sjálfgefið "
            L"er slökkt á báðum nýju valkostunum.\r\n\r\nHRAÐI, HLÉ OG SJÁLFVIRK ENDURRÆSING\r\nHraði er "
            L"0–240 kynslóðir/s, óháður endurnýjun skjás; 0 stöðvar þróun. Hlé og Halda áfram varðveita "
            L"heiminn. Endurræsa byrjar í völdum ham. Valfrjáls sjálfvirk endurræsing greinir kyrrstæð og "
            L"nákvæmlega endurtekin sýnileg stig, einnig sveiflumynstur. Hún ber saman kynslóðir, ekki "
            L"sekúndur, og hunsar ósýnileg svæði. Ósamstilltar niðurstöður geta tafið endurræsingu "
            L"lítillega. Sjálfgefið: 8 px bil, 20 kynslóðir/s, tilviljanakenndur litur lifandi reita og "
            L"sjálfvirk endurræsing virk. Sjálfgefið er slökkt á hnitanetinu. Hraðinn sem næst fer eftir "
            L"afköstum og fjölda reita. Sjálfvirk endurræsing ber saman svæði virkra skjáa; bil á milli "
            L"þeirra þróast áfram en eru ekki tekin með í samanburðinn.\r\n\r\nEndurstilla "
            L"gildi\r\nEndurstilling setur sýnda reitastærð í 8 px með eða án hnitanets (bil 9 eða 8 px), "
            L"hraða í 20 kynslóðir/s, þéttleika í 25 % og litina þrjá í sjálfgefin gildi. Aðrir valkostir "
            L"haldast; mynstur sem rúmast ekki lengur er skipt út fyrir blönduna. Ný sena verður aðeins "
            L"til ef bilið breytist eða þéttleikinn breytist í suðham.\r\n\r\nSJÁLFSTÆTT FORRIT OG "
            L"MP4-UPPTAKA\r\nEXE vistar stillingar jafnóðum og tekur upp fyrsta virka skjáinn í MP4. "
            L"Mappan Myndskeið er lögð til, annars Skjöl. Viewport notar skjástærð og tíðni að 60 "
            L"römmum/s. TV býður 1920 × 1080, 1440 × 1080 eða 1280 × 720 í 16:9 við 50, 25, 59,94 "
            L"(60000/1001) eða 29,97 (30000/1001) ramma/s. Hlutföll haldast; TV notar ófléttað BT.709 með "
            L"takmörkuðu sviði og 4:2:0. Hægt er að minnka sjálfstæðan stillingaglugga. Í lagi vistar "
            L"fyrir næstu upptöku; Hætta við eða Esc hendir óstaðfestum breytingum. Ekki er hægt að "
            L"slökkva á skjánum í upptöku; breyta má öðrum úttökum. Lokun meðan tekið er upp krefst "
            L"staðfestingar. Með áherslu á hreyfimynd skiptir bilslá hléi, F9: Hefja upptöku; F10: Stöðva "
            L"upptöku. Bendill felst eftir 1 sekúndu án hreyfingar og birtist við hreyfingu. Tab/Shift+Tab "
            L"færist milli stjórna; Alt virkjar undirstrikaðar skipanir. Esc lokar Hjálp/Um eða hættir úr "
            L"aðalglugga.\r\n\r\nSKJÁMYND OG STJÓRNUN SKJÁHVÍLU Í EXE\r\nSkjámynd vistar "
            L"BMP/GIF/JPEG/PNG/TIFF/WebP af skjánum "
            L"sem er í upptöku, annars fyrsta virka skjánum, í upplausn hans án þess að endurræsa senuna. "
            L"Mappan Myndir er lögð til, annars Skjöl. Lokun á skjáhvílu meðan hreyfimynd er í gangi kemur "
            L"í veg fyrir ræsingu hennar meðan hreyfimyndin er sýnileg og ekki í hléi. Núllhraði er ekki "
            L"hlé. Uppsetning úr EXE afþjappar meðfylgjandi SCR og velur það sem skjáhvílu Windows. "
            L"Uppsetning og fjarlæging geta krafist samþykkis stjórnanda; stöðustikan sýnir aðgerðina þar "
            L"til henni lýkur. Ef fjarlæging er hindruð skal loka skjáhvílunni sem er í gangi, stillingum "
            L"hennar og forskoðun Windows.\r\n\r\nWINDOWS-SKJÁHVÍLA\r\nGameOfLife.scr notar alla skjái með "
            L"stillingum aðskildum frá EXE. Forskoðun ræsir hreyfimynd á öllum skjánum með stillingar "
            L"opnar. Litla Windows-forskoðunin minnkar allan heiminn. Í lagi vistar; Hætta við eða Esc "
            L"hendir breytingum. Músarhreyfing eða takki lokar skjáhvílu á öllum skjánum. MP4-upptaka er í "
            L"EXE.\r\n\r\nSTAÐSETNING OG STAÐA GLUGGA\r\nVið lokun vistast staðsetningar aðalglugga og "
            L"Um-glugga sérstaklega; Hjálp vistar einnig stærð og venjulega eða hámarkaða stöðu áður en "
            L"glugginn var minnkaður. Þetta er óháð staðfestingu forritsstillinga. Þegar forritinu er "
            L"lokað lokast Hjálp og Um einnig.\r\n\r\nTEIKNING OG LEYFI MYNSTRA\r\nÞróun og samanburður "
            L"sýnilegra staða nota Direct3D 11-skyggni á GPU; hugbúnaðarteikning er tiltæk ef "
            L"vélbúnaðarfrumstilling mistekst. Hver skjár notar sannreynda rammatímasetningu við eigin "
            L"tíðni. MP4 þarf Media Foundation og H.264-kóðara. Mynstur koma frá LifeWiki (GFDL 1.2 eða "
            L"nýrra) og söfnum Alans Hensels sem eru í almenningseigu. Forritskóðinn er með MIT-leyfi; "
            L"tilkynningar og leyfi skrárinnar eru aðskilin.\r\n\r\nSkjáhvíla Windows… opnar "
            L"kerfisstillingar skjáhvílunnar."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nREGLUR\r\nLífsleikur Conways notar B3/S23. Dauður reitur lifnar með "
            L"nákvæmlega þremur lifandi nágrönnum; lifandi reitur lifir áfram með tveimur eða þremur. "
            L"Nágrannarnir átta innihalda hornalínur. Allir reitir breytast samtímis. Gagnstæðar brúnir "
            L"tengjast: vinstri við hægri, efri við neðri.\r\n\r\nSKJÁIR OG SAMEIGINLEGUR "
            L"HEIMUR\r\nGátreitir í EXE virkja skjái; stillingar gilda fyrir sameiginlega heiminn. Einn "
            L"virkur skjár inniheldur allan heiminn. Þegar hluti skjáa er valinn hverfa alveg auðar raðir "
            L"og dálkar: vinstri og hægri skjár tengjast þegar slökkt er á miðjuskjánum. Innri eyður sem "
            L"ekki er hægt að fjarlægja haldast í hermuninni. Allir skjáir valdir, eða SCR, varðveita "
            L"rétthyrning skjáborðsins með ósýnilegum bilum. Hver skjár sýnir sinn hluta sömu "
            L"hermunar.\r\n\r\nUPPHAFSSTAÐA OG MYNSTUR\r\nSjálfgefin byrjun er slembisuð með 25 % lifandi "
            L"reitum. Upphafsþéttleiki 0–100 % gildir við næstu endurræsingu. Aðeins þekkt mynstur notar "
            L"4.106 innbyggð mynstur án suðs og slekkur á þéttleika. Veldu blöndu eða heiti; mál eru í "
            L"reitum. Sláðu inn nafn til að leita. Aðeins mynstur sem rúmast heil birtast. Lítil staðfest "
            L"mynstur endurtaka sig í aðskildum eintökum, stór eða flókin birtast einu sinni í miðju. "
            L"Minni heimur getur skipt of stóru vali út fyrir blöndu. Breyttur hamur eða mynstur býr til "
            L"nýja senu. Endurræsing varðveitir valið; skráin virkar án nets.\r\n\r\nREITASTÆRÐ, HNITANET "
            L"OG LITIR\r\nÁn hnitanets er reitastærð 1–64 px. Hnitanet bætir 1 px brún innan núverandi "
            L"bils: birt stærð og sleði lækka um einn, með 1–63 nýtanlegt. Þegar slökkt er færist gildið "
            L"til baka. Sleðinn heldur öllu sviðinu og stekkur til baka frá ótiltæka endanum; gátreiturinn "
            L"helst virkur. Skipting varðveitir senuna nema þegar kveikt er við 1 px: bilið verður 2 px og "
            L"ný sena byrjar. Breytt stærð eða skjával endurræsir einnig. Mjög stórir heimar geta þurft "
            L"hærra lágmark. Litir reita, bakgrunns og hnitanets breytast sjálfstætt án endurræsingar. "
            L"Tilviljanakenndur litur lifandi reita velur nýjan lit við hverja handvirka eða sjálfvirka "
            L"endurræsingu senunnar. Vistaði liturinn varðveitist og kemur aftur þegar slökkt er á þessum "
            L"valkosti. Hægt er að virkja sömu hegðun sérstaklega fyrir bakgrunn og hnitanet; sjálfgefið "
            L"er slökkt á báðum nýju valkostunum.\r\n\r\nHRAÐI, HLÉ OG SJÁLFVIRK ENDURRÆSING\r\nHraði er "
            L"0–240 kynslóðir/s, óháður endurnýjun skjás; 0 stöðvar þróun. Hlé og Halda áfram varðveita "
            L"heiminn. Endurræsa byrjar í völdum ham. Valfrjáls sjálfvirk endurræsing greinir kyrrstæð og "
            L"nákvæmlega endurtekin sýnileg stig, einnig sveiflumynstur. Hún ber saman kynslóðir, ekki "
            L"sekúndur, og hunsar ósýnileg svæði. Ósamstilltar niðurstöður geta tafið endurræsingu "
            L"lítillega. Sjálfgefið: 8 px bil, 20 kynslóðir/s, tilviljanakenndur litur lifandi reita og "
            L"sjálfvirk endurræsing virk. Sjálfgefið er slökkt á hnitanetinu. Hraðinn sem næst fer eftir "
            L"afköstum og fjölda reita. Sjálfvirk endurræsing ber saman svæði virkra skjáa; bil á milli "
            L"þeirra þróast áfram en eru ekki tekin með í samanburðinn.\r\n\r\nEndurstilla "
            L"gildi\r\nEndurstilling setur sýnda reitastærð í 8 px með eða án hnitanets (bil 9 eða 8 px), "
            L"hraða í 20 kynslóðir/s, þéttleika í 25 % og litina þrjá í sjálfgefin gildi. Aðrir valkostir "
            L"haldast; mynstur sem rúmast ekki lengur er skipt út fyrir blönduna. Ný sena verður aðeins "
            L"til ef bilið breytist eða þéttleikinn breytist í "
            L"suðham.\r\n\r\nWINDOWS-SKJÁHVÍLA\r\nGameOfLife.scr notar alla skjái með stillingum aðskildum "
            L"frá EXE. Forskoðun ræsir hreyfimynd á öllum skjánum með stillingar opnar. Litla "
            L"Windows-forskoðunin minnkar allan heiminn. Í lagi vistar; Hætta við eða Esc hendir "
            L"breytingum. Músarhreyfing eða takki lokar skjáhvílu á öllum skjánum. MP4-upptaka er í "
            L"EXE.\r\n\r\nSTAÐSETNING OG STAÐA GLUGGA\r\nVið lokun vistast staðsetningar aðalglugga og "
            L"Um-glugga sérstaklega; Hjálp vistar einnig stærð og venjulega eða hámarkaða stöðu áður en "
            L"glugginn var minnkaður. Þetta er óháð staðfestingu forritsstillinga. Þegar forritinu er "
            L"lokað lokast Hjálp og Um einnig.\r\n\r\nTEIKNING OG LEYFI MYNSTRA\r\nÞróun og samanburður "
            L"sýnilegra staða nota Direct3D 11-skyggni á GPU; hugbúnaðarteikning er tiltæk ef "
            L"vélbúnaðarfrumstilling mistekst. Hver skjár notar sannreynda rammatímasetningu við eigin "
            L"tíðni. MP4 þarf Media Foundation og H.264-kóðara. Mynstur koma frá LifeWiki (GFDL 1.2 eða "
            L"nýrra) og söfnum Alans Hensels sem eru í almenningseigu. Forritskóðinn er með MIT-leyfi; "
            L"tilkynningar og leyfi skrárinnar eru aðskilin."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Stærð reita: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Hraði: %u kynslóðir/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Upphafsþéttleiki: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Endurræsa senuna" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Litur lifandi reita…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Bakgrunnslitur…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Valdir skjáir deila heimi. Auðar ræmur hverfa; innri eyður haldast."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Hreyfimyndin er í gangi…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Hlé hefur verið gert á hreyfimyndinni."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Ekki tókst að ræsa Direct3D."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Virkja forskoðun"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Slökkva á forskoðun"
        },
        LocalizedText{ TXT_MONITOR,
            L"Skjár"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Upplausn"
        },
        LocalizedText{ TXT_POSITION,
            L"Staðsetning"
        },
        LocalizedText{ TXT_PRIMARY,
            L"aðal"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Gerð skjás"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Endurnýjunartíðni"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bitadýpt"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Litasnið"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Litarými"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bitar/rás"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bitar/myndpunktur"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Hreyfimyndaskjár"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Tilbúið"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Sýna hnitanet"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Litur hnitanets…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Endurræsa sjálfkrafa stöðuga eða endurtekna sýnilega senu"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Aðeins þekkt mynstur"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Hefja upptöku…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Stöðva upptöku"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4-upptaka í gangi…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Upptakan var vistuð."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Ekki tókst að hefja MP4-upptöku."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Ef forritinu er lokað stöðvast upptakan sem er í gangi."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Upptökustillingar"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Upplausn:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Rammatíðni:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Breytingarnar gilda fyrir næstu MP4-upptöku."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Blanda hentugra mynstra"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Valið mynstur rúmast ekki lengur. Hentug blanda var valin."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Ekki tókst að hlaða skrá yfir þekkt mynstur."
        },
    }),
    DefineLanguage(LANG_NB, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Tilfeldig bakgrunnsfarge ved hver omstart av scenen" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Tilfeldig rutenettfarge ved hver omstart av scenen" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Windows-skjermsparer…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Kan ikke åpne innstillingene for Windows-skjermspareren."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Tilbakestill verdier" },
        LocalizedText{ TXT_SNAPSHOT, L"Skjermbilde…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Skjermbildet ble lagret." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Kunne ikke lagre skjermbildet." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Hindre skjermsparer under animasjon" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Tilfeldig farge på levende celler ved hver omstart av scenen"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Installerer skjermsparer …" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Avinstallerer skjermsparer …" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Installer skjermsparer" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Avinstaller skjermsparer" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Skjermspareren ble ikke installert." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Skjermspareren ble installert." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Skjermspareren ble avinstallert." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Skjermspareren kunne ikke avinstalleres. Hvis skjermspareren eller forhåndsvisningen kjører, "
            L"lukk den og prøv på nytt."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Avinstalleringen mislyktes fordi innstillingene for GameOfLife er åpne. Lukk vinduet og prøv "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Norsk (bokmål)"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Kontroll"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Innstillinger for GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Språk:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Avbryt"
        },
        LocalizedText{ TXT_EXIT,
            L"Avslutt"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pause"
        },
        LocalizedText{ TXT_RESUME,
            L"Fortsett"
        },
        LocalizedText{ TXT_HELP,
            L"Hjelp"
        },
        LocalizedText{ TXT_ABOUT,
            L"Om"
        },
        LocalizedText{ TXT_CLOSE,
            L"Lukk"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Besøk nettstedet %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Nettstedet kan ikke åpnes i standardnettleseren."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"URL-adressen kunne ikke kopieres til utklippstavlen."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Informasjonen kunne ikke kopieres til utklippstavlen."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conways Game of Life i én felles verden på flere skjermer."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Versjon:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Målplattform:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Nettsted:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Åpne i standardnettleseren"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Kopier &URL"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Kopier &informasjon"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Lisensressursen er ikke tilgjengelig."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nREGLER\r\nConways Game of Life bruker B3/S23. En død celle fødes med "
            L"nøyaktig tre levende naboer; en levende overlever med to eller tre. De åtte naboene "
            L"inkluderer diagonaler. Alle celler endres samtidig. Motstående kanter forbindes: venstre med "
            L"høyre, øverst med nederst.\r\n\r\nSKJERMER OG FELLES VERDEN\r\nAvkrysningsboksene i EXE "
            L"aktiverer skjermer; innstillingene gjelder den felles verdenen. Én aktiv skjerm inneholder "
            L"hele verdenen. Ved delvis valg fjernes helt tomme rader og kolonner: venstre og høyre skjerm "
            L"møtes når den midterste slås av. Indre hull som ikke kan fjernes, forblir i simuleringen. "
            L"Valg av alle skjermer eller bruk av SCR bevarer skrivebordets omsluttende rektangel med "
            L"usynlige mellomrom. Hver skjerm viser sin del av samme simulering.\r\n\r\nSTARTTILSTAND OG "
            L"MØNSTRE\r\nStandardstarten er tilfeldig støy med 25 % levende celler. Starttetthet på 0–100 "
            L"% brukes ved neste omstart. Bare kjente mønstre bruker 4 106 medfølgende mønstre uten støy "
            L"og deaktiverer tetthet. Velg en blanding eller et navn; mål oppgis i celler. Skriv et navn "
            L"for å søke. Bare mønstre som får plass i sin helhet vises. Små kontrollerte mønstre gjentas "
            L"i separate kopier, store eller komplekse én gang i midten. En mindre verden kan erstatte et "
            L"for stort valg med en blanding. Endret modus eller mønster lager en ny scene. Omstart "
            L"beholder valget; katalogen virker uten nett.\r\n\r\nCELLER, RUTENETT OG FARGER\r\nUten "
            L"rutenett er cellestørrelsen 1–64 px. Vis rutenett legger til en kant på 1 px innenfor "
            L"eksisterende avstand: vist verdi og glidebryter går ned én, med 1–63 som brukbare verdier. "
            L"Avslåing gjenoppretter verdien. Glidebryteren beholder området og hopper tilbake fra det "
            L"utilgjengelige endepunktet; boksen forblir aktiv. Bytte bevarer scenen, unntatt aktivering "
            L"ved 1 px: avstanden blir 2 px og scenen starter på nytt. Endring av størrelse eller skjermer "
            L"starter også på nytt. Svært store verdener kan kreve et høyere minimum. Celle-, bakgrunns- "
            L"og rutenettfarger endres hver for seg uten omstart. Tilfeldig farge på levende celler velger "
            L"en ny farge ved hver manuelle eller automatiske omstart av scenen. Den lagrede fargen "
            L"bevares og gjenopprettes når valget slås av. Samme virkemåte kan aktiveres separat for "
            L"bakgrunn og rutenett; begge nye valg er av som standard.\r\n\r\nHASTIGHET, PAUSE OG "
            L"AUTOMATISK OMSTART\r\nHastigheten er 0–240 generasjoner/s uavhengig av oppdateringsfrekvens; "
            L"0 stopper utviklingen. Pause og Fortsett bevarer verdenen. Start på nytt begynner i valgt "
            L"modus. Valgfri automatisk omstart finner statiske og nøyaktig gjentatte synlige faser, også "
            L"oscillatorer. Den sammenligner generasjoner, ikke sekunder; usynlige områder utelates. "
            L"Asynkrone resultater kan forsinke omstart litt. Standard: 8 px avstand, 20 generasjoner/s, "
            L"tilfeldig farge på levende celler og automatisk omstart på. Rutenettet er slått av som "
            L"standard. Oppnådd hastighet avhenger av ytelse og antall celler. Automatisk omstart "
            L"sammenligner områdene på aktiverte skjermer; mellomrom utvikler seg fortsatt, men tas ikke "
            L"med i sammenligningen.\r\n\r\nTilbakestill verdier\r\nTilbakestilling setter vist "
            L"cellestørrelse til 8 px med eller uten rutenett (avstand 9 eller 8 px), hastighet til 20 "
            L"generasjoner/s, tetthet til 25 % og de tre standardfargene. Andre valg beholdes; et mønster "
            L"som ikke lenger passer, erstattes med blandingen. En ny scene opprettes bare hvis avstanden "
            L"endres, eller hvis tettheten endres i støymodus.\r\n\r\nSELVSTENDIG PROGRAM OG "
            L"MP4-OPPTAK\r\nEXE lagrer innstillinger fortløpende og tar opp den første aktive skjermen som "
            L"MP4. Videoer foreslås, ellers Dokumenter. Viewport bruker skjermens mål og frekvens opptil "
            L"60 bilder/s. TV tilbyr 1920 × 1080, 1440 × 1080 eller 1280 × 720 i 16:9 ved 50, 25, 59,94 "
            L"(60000/1001) eller 29,97 (30000/1001) bilder/s. Sideforholdet bevares; TV bruker progressiv "
            L"BT.709 med begrenset område og 4:2:0. Det uavhengige innstillingsvinduet kan minimeres. OK "
            L"lagrer for neste opptak; Avbryt eller Esc forkaster ubekreftede endringer. Skjermen som tas "
            L"opp kan ikke deaktiveres; andre utganger kan endres. Avslutning under opptak krever "
            L"bekreftelse. Med fokus på animasjonen veksler Mellomrom pause, F9: Start opptak; F10: Stopp "
            L"opptak. Pekeren skjules etter 1 sekund uten aktivitet og vises ved bevegelse. Tab/Shift+Tab "
            L"flytter mellom kontroller; Alt aktiverer understrekede kommandoer. Esc lukker Hjelp/Om eller "
            L"avslutter fra hovedvinduet.\r\n\r\nØYEBLIKKSBILDE OG SKJERMSPARER I EXE\r\nØyeblikksbilde "
            L"lagrer en BMP/GIF/JPEG/PNG/TIFF/WebP av skjermen som tas opp, ellers den første aktive, i dens "
            L"oppløsning uten å "
            L"starte scenen på nytt. Bilder foreslås, ellers Dokumenter. Blokkering av skjermspareren "
            L"under animasjon hindrer at den starter mens animasjonen er synlig og ikke satt på pause. "
            L"Hastighet null er ikke pause. Installasjon fra EXE pakker ut den medfølgende SCR-en og "
            L"velger den som Windows-skjermsparer. Installasjon og avinstallasjon kan kreve "
            L"administratorgodkjenning; statuslinjen viser handlingen til den er ferdig. Hvis fjerning er "
            L"blokkert, lukk den kjørende skjermspareren, innstillingene og "
            L"Windows-forhåndsvisningen.\r\n\r\nWINDOWS-SKJERMSPARER\r\nGameOfLife.scr bruker alle "
            L"skjermer med innstillinger atskilt fra EXE. Forhåndsvisning starter fullskjermsanimasjon "
            L"mens innstillingene er åpne. Den lille Windows-forhåndsvisningen forminsker hele verdenen. "
            L"OK lagrer; Avbryt eller Esc forkaster endringer. Musebevegelse eller en tast avslutter "
            L"skjermspareren i fullskjerm. MP4-opptak finnes i EXE.\r\n\r\nVINDUSPLASSERING OG "
            L"TILSTAND\r\nVed lukking lagres plasseringen av hovedvinduet og Om-vinduet separat; for Hjelp "
            L"også størrelse og normal eller maksimert tilstand før eventuell minimering. Dette er "
            L"uavhengig av bekreftelse av programinnstillinger. Avslutning av programmet lukker også Hjelp "
            L"og Om.\r\n\r\nGJENGIVELSE OG MØNSTERLISENSER\r\nUtvikling og synlige sammenligninger bruker "
            L"Direct3D 11-skyggeprogrammer på GPU-en; programvaregjengivelse finnes hvis "
            L"maskinvareinitialisering mislykkes. Hver skjerm bruker den gjennomprøvde rammetidsstyringen "
            L"ved sin egen frekvens. MP4 krever Media Foundation og en H.264-koder. Mønstre kommer fra "
            L"LifeWiki (GFDL 1.2 eller nyere) og Alan Hensels samlinger i det fri. Programkoden bruker "
            L"MIT; katalogens merknader og lisenser er separate.\r\n\r\nWindows-skjermsparer… åpner "
            L"systemets skjermsparerinnstillinger."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nREGLER\r\nConways Game of Life bruker B3/S23. En død celle fødes med "
            L"nøyaktig tre levende naboer; en levende overlever med to eller tre. De åtte naboene "
            L"inkluderer diagonaler. Alle celler endres samtidig. Motstående kanter forbindes: venstre med "
            L"høyre, øverst med nederst.\r\n\r\nSKJERMER OG FELLES VERDEN\r\nAvkrysningsboksene i EXE "
            L"aktiverer skjermer; innstillingene gjelder den felles verdenen. Én aktiv skjerm inneholder "
            L"hele verdenen. Ved delvis valg fjernes helt tomme rader og kolonner: venstre og høyre skjerm "
            L"møtes når den midterste slås av. Indre hull som ikke kan fjernes, forblir i simuleringen. "
            L"Valg av alle skjermer eller bruk av SCR bevarer skrivebordets omsluttende rektangel med "
            L"usynlige mellomrom. Hver skjerm viser sin del av samme simulering.\r\n\r\nSTARTTILSTAND OG "
            L"MØNSTRE\r\nStandardstarten er tilfeldig støy med 25 % levende celler. Starttetthet på 0–100 "
            L"% brukes ved neste omstart. Bare kjente mønstre bruker 4 106 medfølgende mønstre uten støy "
            L"og deaktiverer tetthet. Velg en blanding eller et navn; mål oppgis i celler. Skriv et navn "
            L"for å søke. Bare mønstre som får plass i sin helhet vises. Små kontrollerte mønstre gjentas "
            L"i separate kopier, store eller komplekse én gang i midten. En mindre verden kan erstatte et "
            L"for stort valg med en blanding. Endret modus eller mønster lager en ny scene. Omstart "
            L"beholder valget; katalogen virker uten nett.\r\n\r\nCELLER, RUTENETT OG FARGER\r\nUten "
            L"rutenett er cellestørrelsen 1–64 px. Vis rutenett legger til en kant på 1 px innenfor "
            L"eksisterende avstand: vist verdi og glidebryter går ned én, med 1–63 som brukbare verdier. "
            L"Avslåing gjenoppretter verdien. Glidebryteren beholder området og hopper tilbake fra det "
            L"utilgjengelige endepunktet; boksen forblir aktiv. Bytte bevarer scenen, unntatt aktivering "
            L"ved 1 px: avstanden blir 2 px og scenen starter på nytt. Endring av størrelse eller skjermer "
            L"starter også på nytt. Svært store verdener kan kreve et høyere minimum. Celle-, bakgrunns- "
            L"og rutenettfarger endres hver for seg uten omstart. Tilfeldig farge på levende celler velger "
            L"en ny farge ved hver manuelle eller automatiske omstart av scenen. Den lagrede fargen "
            L"bevares og gjenopprettes når valget slås av. Samme virkemåte kan aktiveres separat for "
            L"bakgrunn og rutenett; begge nye valg er av som standard.\r\n\r\nHASTIGHET, PAUSE OG "
            L"AUTOMATISK OMSTART\r\nHastigheten er 0–240 generasjoner/s uavhengig av oppdateringsfrekvens; "
            L"0 stopper utviklingen. Pause og Fortsett bevarer verdenen. Start på nytt begynner i valgt "
            L"modus. Valgfri automatisk omstart finner statiske og nøyaktig gjentatte synlige faser, også "
            L"oscillatorer. Den sammenligner generasjoner, ikke sekunder; usynlige områder utelates. "
            L"Asynkrone resultater kan forsinke omstart litt. Standard: 8 px avstand, 20 generasjoner/s, "
            L"tilfeldig farge på levende celler og automatisk omstart på. Rutenettet er slått av som "
            L"standard. Oppnådd hastighet avhenger av ytelse og antall celler. Automatisk omstart "
            L"sammenligner områdene på aktiverte skjermer; mellomrom utvikler seg fortsatt, men tas ikke "
            L"med i sammenligningen.\r\n\r\nTilbakestill verdier\r\nTilbakestilling setter vist "
            L"cellestørrelse til 8 px med eller uten rutenett (avstand 9 eller 8 px), hastighet til 20 "
            L"generasjoner/s, tetthet til 25 % og de tre standardfargene. Andre valg beholdes; et mønster "
            L"som ikke lenger passer, erstattes med blandingen. En ny scene opprettes bare hvis avstanden "
            L"endres, eller hvis tettheten endres i "
            L"støymodus.\r\n\r\nWINDOWS-SKJERMSPARER\r\nGameOfLife.scr bruker alle skjermer med "
            L"innstillinger atskilt fra EXE. Forhåndsvisning starter fullskjermsanimasjon mens "
            L"innstillingene er åpne. Den lille Windows-forhåndsvisningen forminsker hele verdenen. OK "
            L"lagrer; Avbryt eller Esc forkaster endringer. Musebevegelse eller en tast avslutter "
            L"skjermspareren i fullskjerm. MP4-opptak finnes i EXE.\r\n\r\nVINDUSPLASSERING OG "
            L"TILSTAND\r\nVed lukking lagres plasseringen av hovedvinduet og Om-vinduet separat; for Hjelp "
            L"også størrelse og normal eller maksimert tilstand før eventuell minimering. Dette er "
            L"uavhengig av bekreftelse av programinnstillinger. Avslutning av programmet lukker også Hjelp "
            L"og Om.\r\n\r\nGJENGIVELSE OG MØNSTERLISENSER\r\nUtvikling og synlige sammenligninger bruker "
            L"Direct3D 11-skyggeprogrammer på GPU-en; programvaregjengivelse finnes hvis "
            L"maskinvareinitialisering mislykkes. Hver skjerm bruker den gjennomprøvde rammetidsstyringen "
            L"ved sin egen frekvens. MP4 krever Media Foundation og en H.264-koder. Mønstre kommer fra "
            L"LifeWiki (GFDL 1.2 eller nyere) og Alan Hensels samlinger i det fri. Programkoden bruker "
            L"MIT; katalogens merknader og lisenser er separate."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Cellestørrelse: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Hastighet: %u generasjoner/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Starttetthet: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Start scenen på nytt" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Farge på levende celler…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Bakgrunnsfarge…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Valgte skjermer deler én verden. Tomme bånd fjernes; indre hull beholdes."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animasjonen kjører…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animasjonen er satt på pause."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Kunne ikke initialisere Direct3D."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Slå på forhåndsvisning"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Slå av forhåndsvisning"
        },
        LocalizedText{ TXT_MONITOR,
            L"Skjerm"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Oppløsning"
        },
        LocalizedText{ TXT_POSITION,
            L"Posisjon"
        },
        LocalizedText{ TXT_PRIMARY,
            L"primær"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Skjermmodell"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Oppdateringsfrekvens"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bitdybde"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Fargeformat"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Fargerom"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bit/kanal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bit/piksel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Animasjonsskjerm"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Klar"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Vis rutenett"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Rutenettfarge…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Start en stabil eller gjentakende synlig scene automatisk på nytt"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Bare kjente mønstre"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Start opptak…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Stopp opptak"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4-opptak pågår…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Opptaket ble lagret."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Kunne ikke starte MP4-opptak."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Hvis du avslutter programmet, avsluttes opptaket som pågår."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Opptaksinnstillinger"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Oppløsning:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Bildefrekvens:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Endringene gjelder neste MP4-opptak."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Blanding av passende mønstre"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Det valgte mønsteret passer ikke lenger. En passende blanding er valgt."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Kunne ikke laste katalogen med kjente mønstre."
        },
    }),
    DefineLanguage(LANG_SV, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Slumpmässig bakgrundsfärg vid varje omstart av scenen"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Slumpmässig rutnätsfärg vid varje omstart av scenen" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Windows-skärmsläckare…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Det går inte att öppna inställningarna för Windows-skärmsläckaren."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Återställ värden" },
        LocalizedText{ TXT_SNAPSHOT, L"Skärmbild…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Skärmbilden sparades." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Det gick inte att spara skärmbilden." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blockera skärmsläckare under animering" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Slumpmässig färg på levande celler vid varje omstart av scenen"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Installerar skärmsläckare…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Avinstallerar skärmsläckare…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Installera skärmsläckare" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Avinstallera skärmsläckare" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Skärmsläckaren installerades inte." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Skärmsläckaren installerades." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Skärmsläckaren avinstallerades." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Skärmsläckaren kunde inte avinstalleras. Om skärmsläckaren eller förhandsvisningen körs, stäng "
            L"den och försök igen."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Avinstallationen misslyckades eftersom inställningarna för GameOfLife är öppna. Stäng "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Svenska"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Styrning"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Inställningar för GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Språk:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Avbryt"
        },
        LocalizedText{ TXT_EXIT,
            L"Avsluta"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pausa"
        },
        LocalizedText{ TXT_RESUME,
            L"Fortsätt"
        },
        LocalizedText{ TXT_HELP,
            L"Hjälp"
        },
        LocalizedText{ TXT_ABOUT,
            L"Om"
        },
        LocalizedText{ TXT_CLOSE,
            L"Stäng"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Besök webbplatsen %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Webbplatsen kan inte öppnas i standardwebbläsaren."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"URL-adressen kunde inte kopieras till Urklipp."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Informationen kunde inte kopieras till Urklipp."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conways Game of Life i en gemensam värld över flera skärmar."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Version:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Målplattform:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Webbplats:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Öppna i standardwebbläsaren"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Kopiera &URL"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Kopiera &information"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Licensresursen är inte tillgänglig."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nREGLER\r\nConways Game of Life använder B3/S23. En död cell föds med exakt "
            L"tre levande grannar; en levande överlever med två eller tre. De åtta grannarna inkluderar "
            L"diagonaler. Alla celler ändras samtidigt. Motsatta kanter förbinds: vänster med höger, "
            L"överkant med underkant.\r\n\r\nSKÄRMAR OCH GEMENSAM VÄRLD\r\nKryssrutorna i EXE aktiverar "
            L"skärmar; inställningarna gäller den gemensamma världen. En enda aktiv skärm innehåller hela "
            L"världen. Vid delvis val tas helt tomma rader och kolumner bort: vänster och höger skärm möts "
            L"när den mittersta stängs av. Inre hål som inte kan tas bort finns kvar i simuleringen. Alla "
            L"skärmar valda, eller SCR, bevarar skrivbordets omslutande rektangel med osynliga mellanrum. "
            L"Varje skärm visar sin del av samma simulering.\r\n\r\nSTARTLÄGE OCH "
            L"MÖNSTER\r\nStandardstarten är slumpbrus med 25 % levande celler. Starttäthet 0–100 % används "
            L"vid nästa omstart. Endast kända mönster använder 4 106 medföljande mönster utan brus och "
            L"inaktiverar täthet. Välj en blandning eller ett namn; mått anges i celler. Skriv ett namn "
            L"för att söka. Bara mönster som ryms helt visas. Små kontrollerade mönster upprepas i "
            L"separata kopior, stora eller komplicerade en gång i mitten. En mindre värld kan ersätta ett "
            L"för stort val med en blandning. Ändrat läge eller mönster skapar en ny scen. Omstart "
            L"behåller valet; katalogen fungerar utan nät.\r\n\r\nCELLER, RUTNÄT OCH FÄRGER\r\nUtan rutnät "
            L"är cellstorleken 1–64 px. Visa rutnät lägger till en kant på 1 px inom befintligt avstånd: "
            L"visat värde och reglage minskar med ett, med 1–63 användbara värden. Avstängning återställer "
            L"värdet. Reglaget behåller intervallet och hoppar tillbaka från den otillgängliga ändpunkten; "
            L"kryssrutan förblir aktiv. Växling bevarar scenen, utom aktivering vid 1 px: avståndet blir 2 "
            L"px och scenen börjar om. Ändrad storlek eller skärmuppsättning börjar också om. Mycket stora "
            L"världar kan kräva ett högre minimum. Cell-, bakgrunds- och rutnätsfärger ändras separat utan "
            L"omstart. Slumpmässig färg på levande celler väljer en ny färg vid varje manuell eller "
            L"automatisk omstart av scenen. Den sparade färgen bevaras och återställs när alternativet "
            L"stängs av. Samma beteende kan aktiveras separat för bakgrund och rutnät; båda nya "
            L"alternativen är av som standard.\r\n\r\nHASTIGHET, PAUS OCH AUTOMATISK "
            L"OMSTART\r\nHastigheten är 0–240 generationer/s oberoende av skärmens uppdatering; 0 stoppar "
            L"utvecklingen. Paus och Fortsätt bevarar världen. Starta om börjar i valt läge. Valfri "
            L"automatisk omstart identifierar stilla och exakt upprepade synliga faser, även oscillatorer. "
            L"Den jämför generationer, inte sekunder; osynliga områden räknas inte. Asynkrona resultat kan "
            L"fördröja omstarten lite. Standard: 8 px avstånd, 20 generationer/s, slumpmässig färg på "
            L"levande celler och automatisk omstart på. Rutnätet är avstängt som standard. Uppnådd "
            L"hastighet beror på prestanda och antal celler. Automatisk omstart jämför områdena på "
            L"aktiverade skärmar; mellanrummen utvecklas fortfarande men ingår inte i "
            L"jämförelsen.\r\n\r\nÅterställ värden\r\nÅterställning sätter visad cellstorlek till 8 px med "
            L"eller utan rutnät (avstånd 9 eller 8 px), hastighet till 20 generationer/s, täthet till 25 % "
            L"och de tre standardfärgerna. Andra val bevaras; ett mönster som inte längre ryms ersätts av "
            L"blandningen. En ny scen skapas bara om avståndet ändras eller tätheten ändras i "
            L"brusläge.\r\n\r\nFRISTÅENDE PROGRAM OCH MP4-INSPELNING\r\nEXE sparar inställningar löpande "
            L"och spelar in den första aktiva skärmen som MP4. Videor föreslås, annars Dokument. Viewport "
            L"använder skärmens mått och uppdatering upp till 60 bilder/s. TV erbjuder 1920 × 1080, 1440 × "
            L"1080 eller 1280 × 720 i 16:9 vid 50, 25, 59,94 (60000/1001) eller 29,97 (30000/1001) "
            L"bilder/s. Bildförhållandet bevaras; TV använder progressiv BT.709 med begränsat omfång och "
            L"4:2:0. Det fristående inställningsfönstret kan minimeras. OK sparar för nästa inspelning; "
            L"Avbryt eller Esc förkastar obekräftade ändringar. Den inspelade skärmen kan inte stängas av; "
            L"andra utgångar kan ändras. Avslut under inspelning kräver bekräftelse. Med fokus på "
            L"animationen växlar Blanksteg paus, F9: Starta inspelning; F10: Stoppa inspelning. Pekaren "
            L"döljs efter 1 sekund utan aktivitet och visas vid rörelse. Tab/Shift+Tab flyttar mellan "
            L"kontroller; Alt aktiverar understrukna kommandon. Esc stänger Hjälp/Om eller avslutar i "
            L"huvudfönstret.\r\n\r\nÖGONBLICKSBILD OCH SKÄRMSLÄCKARE I EXE\r\nÖgonblicksbild sparar en "
            L"BMP/GIF/JPEG/PNG/TIFF/WebP "
            L"av skärmen som spelas in, annars den första aktiva, i dess upplösning utan att starta om "
            L"scenen. Bilder föreslås, annars Dokument. Blockering av skärmsläckaren under animation "
            L"hindrar den från att starta när animationen är synlig och inte pausad. Hastighet noll är "
            L"inte paus. Installation från EXE packar upp den medföljande SCR-filen och väljer den som "
            L"Windows-skärmsläckare. Installation och avinstallation kan kräva administratörsgodkännande; "
            L"statusfältet visar åtgärden tills den är klar. Om borttagning blockeras, stäng den körande "
            L"skärmsläckaren, dess inställningar och "
            L"Windows-förhandsvisningen.\r\n\r\nWINDOWS-SKÄRMSLÄCKARE\r\nGameOfLife.scr använder alla "
            L"skärmar med inställningar åtskilda från EXE. Förhandsvisning startar fullskärmsanimation med "
            L"inställningarna öppna. Den lilla Windows-förhandsvisningen förminskar hela världen. OK "
            L"sparar; Avbryt eller Esc förkastar ändringar. Musrörelse eller en tangent avslutar "
            L"skärmsläckaren i helskärm. MP4-inspelning finns i EXE.\r\n\r\nFÖNSTERPLACERING OCH "
            L"TILLSTÅND\r\nVid stängning sparas huvudfönstrets och Om-fönstrets placering separat; för "
            L"Hjälp även storlek och normalt eller maximerat tillstånd före eventuell minimering. Detta är "
            L"oberoende av att programinställningar bekräftas. När programmet avslutas stängs även Hjälp "
            L"och Om.\r\n\r\nRENDERING OCH MÖNSTERLICENSER\r\nUtveckling och synliga jämförelser använder "
            L"Direct3D 11-skuggningsprogram på GPU:n; programvarurendering finns om maskinvaruinitieringen "
            L"misslyckas. Varje skärm använder den beprövade bildtaktsstyrningen vid sin egen frekvens. "
            L"MP4 kräver Media Foundation och en H.264-kodare. Mönster kommer från LifeWiki (GFDL 1.2 "
            L"eller senare) och Alan Hensels samlingar i public domain. Programkoden använder MIT; "
            L"katalogens meddelanden och licenser är separata.\r\n\r\nWindows-skärmsläckare… öppnar "
            L"systemets inställningar för skärmsläckaren."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nREGLER\r\nConways Game of Life använder B3/S23. En död cell föds med exakt "
            L"tre levande grannar; en levande överlever med två eller tre. De åtta grannarna inkluderar "
            L"diagonaler. Alla celler ändras samtidigt. Motsatta kanter förbinds: vänster med höger, "
            L"överkant med underkant.\r\n\r\nSKÄRMAR OCH GEMENSAM VÄRLD\r\nKryssrutorna i EXE aktiverar "
            L"skärmar; inställningarna gäller den gemensamma världen. En enda aktiv skärm innehåller hela "
            L"världen. Vid delvis val tas helt tomma rader och kolumner bort: vänster och höger skärm möts "
            L"när den mittersta stängs av. Inre hål som inte kan tas bort finns kvar i simuleringen. Alla "
            L"skärmar valda, eller SCR, bevarar skrivbordets omslutande rektangel med osynliga mellanrum. "
            L"Varje skärm visar sin del av samma simulering.\r\n\r\nSTARTLÄGE OCH "
            L"MÖNSTER\r\nStandardstarten är slumpbrus med 25 % levande celler. Starttäthet 0–100 % används "
            L"vid nästa omstart. Endast kända mönster använder 4 106 medföljande mönster utan brus och "
            L"inaktiverar täthet. Välj en blandning eller ett namn; mått anges i celler. Skriv ett namn "
            L"för att söka. Bara mönster som ryms helt visas. Små kontrollerade mönster upprepas i "
            L"separata kopior, stora eller komplicerade en gång i mitten. En mindre värld kan ersätta ett "
            L"för stort val med en blandning. Ändrat läge eller mönster skapar en ny scen. Omstart "
            L"behåller valet; katalogen fungerar utan nät.\r\n\r\nCELLER, RUTNÄT OCH FÄRGER\r\nUtan rutnät "
            L"är cellstorleken 1–64 px. Visa rutnät lägger till en kant på 1 px inom befintligt avstånd: "
            L"visat värde och reglage minskar med ett, med 1–63 användbara värden. Avstängning återställer "
            L"värdet. Reglaget behåller intervallet och hoppar tillbaka från den otillgängliga ändpunkten; "
            L"kryssrutan förblir aktiv. Växling bevarar scenen, utom aktivering vid 1 px: avståndet blir 2 "
            L"px och scenen börjar om. Ändrad storlek eller skärmuppsättning börjar också om. Mycket stora "
            L"världar kan kräva ett högre minimum. Cell-, bakgrunds- och rutnätsfärger ändras separat utan "
            L"omstart. Slumpmässig färg på levande celler väljer en ny färg vid varje manuell eller "
            L"automatisk omstart av scenen. Den sparade färgen bevaras och återställs när alternativet "
            L"stängs av. Samma beteende kan aktiveras separat för bakgrund och rutnät; båda nya "
            L"alternativen är av som standard.\r\n\r\nHASTIGHET, PAUS OCH AUTOMATISK "
            L"OMSTART\r\nHastigheten är 0–240 generationer/s oberoende av skärmens uppdatering; 0 stoppar "
            L"utvecklingen. Paus och Fortsätt bevarar världen. Starta om börjar i valt läge. Valfri "
            L"automatisk omstart identifierar stilla och exakt upprepade synliga faser, även oscillatorer. "
            L"Den jämför generationer, inte sekunder; osynliga områden räknas inte. Asynkrona resultat kan "
            L"fördröja omstarten lite. Standard: 8 px avstånd, 20 generationer/s, slumpmässig färg på "
            L"levande celler och automatisk omstart på. Rutnätet är avstängt som standard. Uppnådd "
            L"hastighet beror på prestanda och antal celler. Automatisk omstart jämför områdena på "
            L"aktiverade skärmar; mellanrummen utvecklas fortfarande men ingår inte i "
            L"jämförelsen.\r\n\r\nÅterställ värden\r\nÅterställning sätter visad cellstorlek till 8 px med "
            L"eller utan rutnät (avstånd 9 eller 8 px), hastighet till 20 generationer/s, täthet till 25 % "
            L"och de tre standardfärgerna. Andra val bevaras; ett mönster som inte längre ryms ersätts av "
            L"blandningen. En ny scen skapas bara om avståndet ändras eller tätheten ändras i "
            L"brusläge.\r\n\r\nWINDOWS-SKÄRMSLÄCKARE\r\nGameOfLife.scr använder alla skärmar med "
            L"inställningar åtskilda från EXE. Förhandsvisning startar fullskärmsanimation med "
            L"inställningarna öppna. Den lilla Windows-förhandsvisningen förminskar hela världen. OK "
            L"sparar; Avbryt eller Esc förkastar ändringar. Musrörelse eller en tangent avslutar "
            L"skärmsläckaren i helskärm. MP4-inspelning finns i EXE.\r\n\r\nFÖNSTERPLACERING OCH "
            L"TILLSTÅND\r\nVid stängning sparas huvudfönstrets och Om-fönstrets placering separat; för "
            L"Hjälp även storlek och normalt eller maximerat tillstånd före eventuell minimering. Detta är "
            L"oberoende av att programinställningar bekräftas. När programmet avslutas stängs även Hjälp "
            L"och Om.\r\n\r\nRENDERING OCH MÖNSTERLICENSER\r\nUtveckling och synliga jämförelser använder "
            L"Direct3D 11-skuggningsprogram på GPU:n; programvarurendering finns om maskinvaruinitieringen "
            L"misslyckas. Varje skärm använder den beprövade bildtaktsstyrningen vid sin egen frekvens. "
            L"MP4 kräver Media Foundation och en H.264-kodare. Mönster kommer från LifeWiki (GFDL 1.2 "
            L"eller senare) och Alan Hensels samlingar i public domain. Programkoden använder MIT; "
            L"katalogens meddelanden och licenser är separata."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Cellstorlek: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Hastighet: %u generationer/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Starttäthet: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Starta om scenen" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Färg på levande celler…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Bakgrundsfärg…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Valda skärmar delar en värld. Tomma band tas bort; inre hål finns kvar."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animeringen körs…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animeringen är pausad."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Det gick inte att initiera Direct3D."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Förhandsvisning" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Stoppa förhandsvisning" },
        LocalizedText{ TXT_MONITOR,
            L"Bildskärm"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Upplösning"
        },
        LocalizedText{ TXT_POSITION,
            L"Position"
        },
        LocalizedText{ TXT_PRIMARY,
            L"primär"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Skärmmodell"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Uppdateringsfrekvens"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bitdjup"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Färgformat"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Färgrymd"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bitar/kanal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bitar/pixel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Animationsskärm"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Redo"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Visa rutnät"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Rutnätsfärg…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Starta automatiskt om en stilla eller upprepad synlig scen"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Endast kända mönster"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Starta inspelning…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Stoppa inspelning"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4-inspelning pågår…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Inspelningen sparades."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Det gick inte att starta MP4-inspelningen."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Om du avslutar programmet stoppas den pågående inspelningen."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Inspelningsinställningar"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Upplösning:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Bildfrekvens:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Ändringarna gäller nästa MP4-inspelning."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Blandning av lämpliga mönster"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Det valda mönstret ryms inte längre. En lämplig blandning har valts."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Katalogen med kända mönster kunde inte läsas in."
        },
    }),
    DefineLanguage(LANG_TR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Sahne her yeniden başlatıldığında rastgele arka plan rengi"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Sahne her yeniden başlatıldığında rastgele ızgara rengi" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Windows ekran koruyucusu…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED, L"Windows ekran koruyucusu ayarları açılamadı." },
        LocalizedText{ TXT_RESET_SETTINGS, L"Değerleri sıfırla" },
        LocalizedText{ TXT_SNAPSHOT, L"Anlık görüntü…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Anlık görüntü kaydedildi." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Anlık görüntü kaydedilemedi." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Animasyon sırasında ekran koruyucuyu engelle" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Sahne her sıfırlandığında canlı hücreler için rastgele renk"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Ekran koruyucu yükleniyor…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Ekran koruyucu kaldırılıyor…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Ekran koruyucuyu yükle" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Ekran koruyucuyu kaldır" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Ekran koruyucu yüklenmedi." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Ekran koruyucu yüklendi." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Ekran koruyucu kaldırıldı." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Ekran koruyucu kaldırılamadı. Ekran koruyucu veya önizlemesi çalışıyorsa kapatıp yeniden "
            L"deneyin."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"GameOfLife ayarları açık olduğu için kaldırma başarısız oldu. Ayarlar penceresini kapatıp "
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
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Türkçe"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — Denetim"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"GameOfLife Ayarları"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Dil:"
        },
        LocalizedText{ TXT_OK,
            L"Tamam"
        },
        LocalizedText{ TXT_CANCEL,
            L"İptal"
        },
        LocalizedText{ TXT_EXIT,
            L"Çıkış"
        },
        LocalizedText{ TXT_PAUSE,
            L"Duraklat"
        },
        LocalizedText{ TXT_RESUME,
            L"Sürdür"
        },
        LocalizedText{ TXT_HELP,
            L"Yardım"
        },
        LocalizedText{ TXT_ABOUT,
            L"Hakkında"
        },
        LocalizedText{ TXT_CLOSE,
            L"Kapat"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"%ls web sitesini ziyaret et"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Web sitesi varsayılan tarayıcıda açılamıyor."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"URL panoya kopyalanamadı."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Bilgiler panoya kopyalanamadı."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Ekranlar arasında paylaşılan bir dünyada Conway'in Hayat Oyunu."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Sürüm:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Hedef platform:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Web sitesi:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"Varsayılan tarayıcıda &aç"
        },
        LocalizedText{ TXT_COPY_URL,
            L"&URL'yi kopyala"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"&Bilgileri kopyala"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Lisans kaynağı kullanılamıyor."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nKURALLAR\r\nConway'in Hayat Oyunu B3/S23 kurallarını kullanır. Ölü hücre "
            L"tam üç canlı komşuyla doğar; canlı hücre iki veya üç komşuyla yaşar. Sekiz komşuya çaprazlar "
            L"da dahildir. Tüm hücreler aynı anda değişir. Karşılıklı kenarlar birleşir: sol sağa, üst "
            L"alta bağlanır.\r\n\r\nEKRANLAR VE PAYLAŞILAN DÜNYA\r\nEXE'deki kutular ekranları "
            L"etkinleştirir; ayarlar paylaşılan dünyaya uygulanır. Tek etkin ekran tüm dünyayı içerir. "
            L"Ekran düzeninin bir bölümü seçilirse tamamen boş satır ve sütunlar kaldırılır: ortadaki "
            L"kapatılınca sol ve sağ ekran birleşir. Kaldırılamayan iç boşluklar simülasyonda kalır. Tüm "
            L"ekranların seçilmesi veya SCR kullanılması görünmez aralıklarla birlikte masaüstünü "
            L"çevreleyen dikdörtgeni korur. Her ekran aynı simülasyonun kendi bölgesini "
            L"gösterir.\r\n\r\nBAŞLANGIÇ DURUMU VE DESENLER\r\nVarsayılan başlangıç, %25 canlı hücreli "
            L"rastgele gürültüdür. %0–100 başlangıç yoğunluğu sonraki yeniden başlatmada kullanılır. "
            L"Yalnızca bilinen desenler, gürültüsüz 4.106 yerleşik desen kullanır ve yoğunluğu kapatır. "
            L"Karışım veya bir ad seçin; boyutlar hücre cinsindendir. Aramak için ad yazın. Yalnızca "
            L"tamamen sığan desenler listelenir. Doğrulanmış küçük desenler ayrı kopyalarda tekrarlanır; "
            L"büyük veya karmaşık desenler ortada bir kez başlar. Dünyayı küçültmek, sığmayan seçimi "
            L"karışımla değiştirebilir. Modu veya deseni değiştirmek yeni sahne başlatır. Yeniden "
            L"başlatmalar seçimi korur; katalog çevrimdışı çalışır.\r\n\r\nHÜCRE BOYUTU, IZGARA VE "
            L"RENKLER\r\nIzgarasız hücre boyutu 1–64 px'tir. Izgarayı göster, mevcut aralığın içine 1 px "
            L"kenar ekler: gösterilen değer ve kaydırıcı bir azalır, kullanılabilir değerler 1–63 olur. "
            L"Kapatmak değeri geri getirir. Kaydırıcı tam aralığını korur ve kullanılamayan uçtan geri "
            L"döner; kutu etkin kalır. Geçiş sahneyi korur; 1 px'te açılırsa aralık 2 px olur ve yeni "
            L"sahne başlar. Boyut veya ekran değişimi de yeniden başlatır. Çok büyük dünyalar daha yüksek "
            L"alt sınır gerektirebilir. Hücre, arka plan ve ızgara renkleri yeniden başlatmadan ayrı ayrı "
            L"değişir. Canlı hücrelerin rastgele rengi, sahnenin her elle veya otomatik yeniden "
            L"başlatılmasında yeniden seçilir. Kayıtlı renginiz korunur ve seçenek kapatıldığında geri "
            L"gelir. Aynı davranış arka plan ve ızgara için ayrı ayrı etkinleştirilebilir; iki yeni "
            L"seçenek de başlangıçta kapalıdır.\r\n\r\nHIZ, DURAKLATMA VE OTOMATIK YENIDEN "
            L"BAŞLATMA\r\nHız, ekran yenilemesinden bağımsız 0–240 nesil/sn'dir; 0 gelişimi durdurur. "
            L"Duraklat ve Sürdür dünyayı korur. Yeniden başlat seçilen modda yeni başlangıç yapar. İsteğe "
            L"bağlı otomatik yeniden başlatma, salınımcılar dahil durağan ve tam yinelenen görünür "
            L"evreleri algılar. Saniyeleri değil nesilleri karşılaştırır; görünmez bölgeler dışlanır. "
            L"Eşzamansız sonuçlar yeniden başlatmayı biraz geciktirebilir. Varsayılanlar: 8 px aralık, 20 "
            L"nesil/sn, canlı hücrelerin rastgele rengi ve otomatik yeniden başlatma açık. Izgara "
            L"varsayılan olarak kapalıdır. Ulaşılan hız performansa ve hücre sayısına bağlıdır. Otomatik "
            L"yeniden başlatma etkin ekranların bölgelerini karşılaştırır; aradaki boşluklar gelişmeye "
            L"devam eder ancak karşılaştırmaya katılmaz.\r\n\r\nDeğerleri sıfırla\r\nSıfırlama, ızgara "
            L"açık veya kapalıyken gösterilen hücre boyutunu 8 px yapar (aralık 9 veya 8 px); hızı 20 "
            L"nesil/sn, yoğunluğu %25 ve üç rengi varsayılan değerlerine döndürür. Diğer seçimler korunur; "
            L"artık sığmayan desenin yerini karışım alır. Yalnızca aralık değişirse veya gürültü modunda "
            L"yoğunluk değişirse yeni sahne oluşturulur.\r\n\r\nBAĞIMSIZ UYGULAMA VE MP4 KAYDI\r\nEXE "
            L"ayarları sürekli kaydeder ve ilk etkin ekranı MP4 olarak kaydeder. Videolar klasörü, yoksa "
            L"Belgeler önerilir. Viewport ekran boyutlarını ve en çok 60 kare/sn yenilemesini kullanır. "
            L"TV, 16:9 oranında 1920 × 1080, 1440 × 1080 veya 1280 × 720; 50, 25, 59,94 (60000/1001) veya "
            L"29,97 (30000/1001) kare/sn sunar. En-boy oranı korunur; TV aşamalı, sınırlı aralıklı BT.709 "
            L"ve 4:2:0 kullanır. Bağımsız kayıt ayarları penceresi küçültülebilir. Tamam sonraki kayıt "
            L"için saklar; İptal veya Esc onaylanmamış değişiklikleri atar. Kaydedilen ekran kapatılamaz; "
            L"diğer çıkışlar değişebilir. Kayıt sırasında çıkış onay ister. Animasyona odaklanıldığında "
            L"Boşluk duraklatmayı değiştirir, F9: Kaydı başlat; F10: Kaydı durdur. İmleç 1 saniye "
            L"hareketsizlikten sonra gizlenir, hareketle görünür. Tab/Shift+Tab denetimler arasında gezer; "
            L"Alt altı çizili komutları çalıştırır. Esc Yardım/Hakkında'yı kapatır veya ana pencerede "
            L"uygulamadan çıkar.\r\n\r\nEXE’DE ANLIK GÖRÜNTÜ VE EKRAN KORUYUCU YÖNETİMİ\r\nAnlık görüntü, "
            L"kayıt yapılan ekranı veya kayıt yoksa ilk etkin ekranı kendi çözünürlüğünde "
            L"BMP/GIF/JPEG/PNG/TIFF/WebP olarak "
            L"saklar; sahneyi yeniden başlatmaz. Resimler klasörü, yoksa Belgeler önerilir. Animasyon "
            L"sırasında ekran koruyucuyu engelleme, animasyon görünür ve duraklatılmamışken koruyucunun "
            L"başlamasını önler. Sıfır hız duraklatma değildir. EXE’den kurulum, içerilen SCR’yi açar ve "
            L"Windows ekran koruyucusu olarak seçer. Kurulum ve kaldırma yönetici onayı gerektirebilir; "
            L"durum çubuğu işlemi tamamlanana kadar gösterir. Kaldırma engellenirse çalışan koruyucuyu, "
            L"ayarlarını ve Windows önizlemesini kapatın.\r\n\r\nWINDOWS EKRAN "
            L"KORUYUCUSU\r\nGameOfLife.scr tüm ekranları, EXE'den ayrı ayarlarla kullanır. Önizlemeyi aç, "
            L"ayarlar açıkken tam ekran animasyonu başlatır. Küçük Windows önizlemesi tüm dünyayı "
            L"küçültür. Tamam kaydeder; İptal veya Esc değişiklikleri atar. Fare hareketi veya bir tuş tam "
            L"ekran koruyucudan çıkar. MP4 kaydı EXE'de kullanılabilir.\r\n\r\nPENCERE KONUMLARI VE "
            L"DURUMU\r\nKapanışta ana pencere ve Hakkında penceresinin konumları ayrı kaydedilir; Yardım "
            L"için boyut ve küçültmeden önceki normal veya büyütülmüş durum da saklanır. Bu işlem uygulama "
            L"ayarlarının onaylanmasından bağımsızdır. Uygulamadan çıkış Yardım ve Hakkında pencerelerini "
            L"de kapatır.\r\n\r\nGÖRÜNTÜLEME VE DESEN LISANSLARI\r\nGelişim ve görünür durum "
            L"karşılaştırmaları GPU üzerinde Direct3D 11 gölgelendiricileri kullanır; donanım "
            L"başlatılamazsa yazılımsal görüntüleme kullanılabilir. Her ekran kendi yenileme hızında aynı "
            L"denenmiş kare zamanlayıcısını kullanır. MP4, Media Foundation ve H.264 kodlayıcı gerektirir. "
            L"Desenler LifeWiki'den (GFDL 1.2 veya sonrası) ve Alan Hensel'in kamu malı koleksiyonlarından "
            L"gelir. Program kodu MIT lisanslıdır; katalog bildirimleri ve lisansları "
            L"ayrıdır.\r\n\r\nWindows ekran koruyucusu… sistemin ekran koruyucusu ayarlarını açar."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nKURALLAR\r\nConway'in Hayat Oyunu B3/S23 kurallarını kullanır. Ölü hücre "
            L"tam üç canlı komşuyla doğar; canlı hücre iki veya üç komşuyla yaşar. Sekiz komşuya çaprazlar "
            L"da dahildir. Tüm hücreler aynı anda değişir. Karşılıklı kenarlar birleşir: sol sağa, üst "
            L"alta bağlanır.\r\n\r\nEKRANLAR VE PAYLAŞILAN DÜNYA\r\nEXE'deki kutular ekranları "
            L"etkinleştirir; ayarlar paylaşılan dünyaya uygulanır. Tek etkin ekran tüm dünyayı içerir. "
            L"Ekran düzeninin bir bölümü seçilirse tamamen boş satır ve sütunlar kaldırılır: ortadaki "
            L"kapatılınca sol ve sağ ekran birleşir. Kaldırılamayan iç boşluklar simülasyonda kalır. Tüm "
            L"ekranların seçilmesi veya SCR kullanılması görünmez aralıklarla birlikte masaüstünü "
            L"çevreleyen dikdörtgeni korur. Her ekran aynı simülasyonun kendi bölgesini "
            L"gösterir.\r\n\r\nBAŞLANGIÇ DURUMU VE DESENLER\r\nVarsayılan başlangıç, %25 canlı hücreli "
            L"rastgele gürültüdür. %0–100 başlangıç yoğunluğu sonraki yeniden başlatmada kullanılır. "
            L"Yalnızca bilinen desenler, gürültüsüz 4.106 yerleşik desen kullanır ve yoğunluğu kapatır. "
            L"Karışım veya bir ad seçin; boyutlar hücre cinsindendir. Aramak için ad yazın. Yalnızca "
            L"tamamen sığan desenler listelenir. Doğrulanmış küçük desenler ayrı kopyalarda tekrarlanır; "
            L"büyük veya karmaşık desenler ortada bir kez başlar. Dünyayı küçültmek, sığmayan seçimi "
            L"karışımla değiştirebilir. Modu veya deseni değiştirmek yeni sahne başlatır. Yeniden "
            L"başlatmalar seçimi korur; katalog çevrimdışı çalışır.\r\n\r\nHÜCRE BOYUTU, IZGARA VE "
            L"RENKLER\r\nIzgarasız hücre boyutu 1–64 px'tir. Izgarayı göster, mevcut aralığın içine 1 px "
            L"kenar ekler: gösterilen değer ve kaydırıcı bir azalır, kullanılabilir değerler 1–63 olur. "
            L"Kapatmak değeri geri getirir. Kaydırıcı tam aralığını korur ve kullanılamayan uçtan geri "
            L"döner; kutu etkin kalır. Geçiş sahneyi korur; 1 px'te açılırsa aralık 2 px olur ve yeni "
            L"sahne başlar. Boyut veya ekran değişimi de yeniden başlatır. Çok büyük dünyalar daha yüksek "
            L"alt sınır gerektirebilir. Hücre, arka plan ve ızgara renkleri yeniden başlatmadan ayrı ayrı "
            L"değişir. Canlı hücrelerin rastgele rengi, sahnenin her elle veya otomatik yeniden "
            L"başlatılmasında yeniden seçilir. Kayıtlı renginiz korunur ve seçenek kapatıldığında geri "
            L"gelir. Aynı davranış arka plan ve ızgara için ayrı ayrı etkinleştirilebilir; iki yeni "
            L"seçenek de başlangıçta kapalıdır.\r\n\r\nHIZ, DURAKLATMA VE OTOMATIK YENIDEN "
            L"BAŞLATMA\r\nHız, ekran yenilemesinden bağımsız 0–240 nesil/sn'dir; 0 gelişimi durdurur. "
            L"Duraklat ve Sürdür dünyayı korur. Yeniden başlat seçilen modda yeni başlangıç yapar. İsteğe "
            L"bağlı otomatik yeniden başlatma, salınımcılar dahil durağan ve tam yinelenen görünür "
            L"evreleri algılar. Saniyeleri değil nesilleri karşılaştırır; görünmez bölgeler dışlanır. "
            L"Eşzamansız sonuçlar yeniden başlatmayı biraz geciktirebilir. Varsayılanlar: 8 px aralık, 20 "
            L"nesil/sn, canlı hücrelerin rastgele rengi ve otomatik yeniden başlatma açık. Izgara "
            L"varsayılan olarak kapalıdır. Ulaşılan hız performansa ve hücre sayısına bağlıdır. Otomatik "
            L"yeniden başlatma etkin ekranların bölgelerini karşılaştırır; aradaki boşluklar gelişmeye "
            L"devam eder ancak karşılaştırmaya katılmaz.\r\n\r\nDeğerleri sıfırla\r\nSıfırlama, ızgara "
            L"açık veya kapalıyken gösterilen hücre boyutunu 8 px yapar (aralık 9 veya 8 px); hızı 20 "
            L"nesil/sn, yoğunluğu %25 ve üç rengi varsayılan değerlerine döndürür. Diğer seçimler korunur; "
            L"artık sığmayan desenin yerini karışım alır. Yalnızca aralık değişirse veya gürültü modunda "
            L"yoğunluk değişirse yeni sahne oluşturulur.\r\n\r\nWINDOWS EKRAN KORUYUCUSU\r\nGameOfLife.scr "
            L"tüm ekranları, EXE'den ayrı ayarlarla kullanır. Önizlemeyi aç, ayarlar açıkken tam ekran "
            L"animasyonu başlatır. Küçük Windows önizlemesi tüm dünyayı küçültür. Tamam kaydeder; İptal "
            L"veya Esc değişiklikleri atar. Fare hareketi veya bir tuş tam ekran koruyucudan çıkar. MP4 "
            L"kaydı EXE'de kullanılabilir.\r\n\r\nPENCERE KONUMLARI VE DURUMU\r\nKapanışta ana pencere ve "
            L"Hakkında penceresinin konumları ayrı kaydedilir; Yardım için boyut ve küçültmeden önceki "
            L"normal veya büyütülmüş durum da saklanır. Bu işlem uygulama ayarlarının onaylanmasından "
            L"bağımsızdır. Uygulamadan çıkış Yardım ve Hakkında pencerelerini de "
            L"kapatır.\r\n\r\nGÖRÜNTÜLEME VE DESEN LISANSLARI\r\nGelişim ve görünür durum "
            L"karşılaştırmaları GPU üzerinde Direct3D 11 gölgelendiricileri kullanır; donanım "
            L"başlatılamazsa yazılımsal görüntüleme kullanılabilir. Her ekran kendi yenileme hızında aynı "
            L"denenmiş kare zamanlayıcısını kullanır. MP4, Media Foundation ve H.264 kodlayıcı gerektirir. "
            L"Desenler LifeWiki'den (GFDL 1.2 veya sonrası) ve Alan Hensel'in kamu malı koleksiyonlarından "
            L"gelir. Program kodu MIT lisanslıdır; katalog bildirimleri ve lisansları ayrıdır."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Hücre boyutu: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Hız: %u nesil/sn"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Başlangıç yoğunluğu: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Sahneyi yeniden başlat" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Canlı hücre rengi…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Arka plan rengi…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Seçili ekranlar bir dünyayı paylaşır. Boş şeritler kaldırılır; iç boşluklar kalır."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animasyon çalışıyor…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animasyon duraklatıldı."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Direct3D başlatılamadı."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Önizlemeyi aç"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Önizlemeyi kapat"
        },
        LocalizedText{ TXT_MONITOR,
            L"Monitör"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Çözünürlük"
        },
        LocalizedText{ TXT_POSITION,
            L"Konum"
        },
        LocalizedText{ TXT_PRIMARY,
            L"birincil"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Monitör modeli"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Yenileme hızı"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bit derinliği"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Renk biçimi"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Renk uzayı"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bit/kanal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bit/piksel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Animasyon monitörü"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Hazır"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Izgarayı göster"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Izgara rengi…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Durağan veya yinelenen görünür sahneyi otomatik yeniden başlat"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Yalnızca bilinen desenler"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Kaydı başlat…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Kaydı durdur"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4 kaydı sürüyor…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Kayıt kaydedildi."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"MP4 kaydı başlatılamadı."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Uygulamayı kapatmak devam eden kaydı durduracaktır."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Kayıt ayarları"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Çözünürlük:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Kare hızı:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Değişiklikler bir sonraki MP4 kaydına uygulanır."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Uygun desen karışımı"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Seçilen desen artık dünyaya sığmıyor. Uygun bir karışım seçildi."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Bilinen desen kataloğu yüklenemedi."
        },
    }),
    DefineLanguage(LANG_ET, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Juhuslik taustavärv stseeni igal taaskäivitamisel" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Juhuslik ruudustiku värv stseeni igal taaskäivitamisel" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Windowsi ekraanisäästja…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED, L"Windowsi ekraanisäästja sätteid ei saa avada." },
        LocalizedText{ TXT_RESET_SETTINGS, L"Lähtesta väärtused" },
        LocalizedText{ TXT_SNAPSHOT, L"Hetktõmmis…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"BMP/GIF/JPEG/PNG/TIFF/WebP-pilt on salvestatud." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"BMP/GIF/JPEG/PNG/TIFF/WebP-pilti ei saanud salvestada." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Tõkesta animatsiooni ajal ekraanisäästja" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Elusrakkude juhuslik värv stseeni igal taaskäivitamisel"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Ekraanisäästja paigaldamine…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Ekraanisäästja eemaldamine…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Paigalda ekraanisäästja" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Eemalda ekraanisäästja" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Ekraanisäästjat ei paigaldatud." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Ekraanisäästja on paigaldatud." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Ekraanisäästja on eemaldatud." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Ekraanisäästjat ei saanud eemaldada. Sulgege ekraanisäästja ja selle eelvaade ning proovige "
            L"uuesti."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Sulgege GameOfLife sätete aken ja proovige eemaldamist uuesti."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Sulgege Windowsi ekraanisäästja sätete aken ja proovige eemaldamist uuesti."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Sulgege ekraanisäästja või täisekraanieelvaade klahviga Esc või hiire liigutamisega ja "
            L"proovige eemaldamist uuesti."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Eesti"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — juhtimine"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"GameOfLife sätted"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Keel:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Loobu"
        },
        LocalizedText{ TXT_EXIT,
            L"Välju"
        },
        LocalizedText{ TXT_PAUSE,
            L"Peata"
        },
        LocalizedText{ TXT_RESUME,
            L"Jätka"
        },
        LocalizedText{ TXT_HELP,
            L"Spikker"
        },
        LocalizedText{ TXT_ABOUT,
            L"Teave"
        },
        LocalizedText{ TXT_CLOSE,
            L"Sule"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Ava veebisait %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Veebisaiti ei saa vaikebrauseris avada."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"URL-i ei saanud lõikelauale kopeerida."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Teavet ei saanud lõikelauale kopeerida."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conway elumäng ühes kuvarite ühises maailmas."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Versioon:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Sihtplatvorm:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Veebisait:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Ava vaikebrauseris"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Kopeeri &aadress"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Kopeeri &teave"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Litsentsiressurss pole saadaval."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nREEGLID\r\nConway elumäng kasutab B3/S23 reegleid. Surnud lahter sünnib "
            L"täpselt kolme elusa naabriga; elus lahter jääb ellu kahe või kolmega. Kaheksa naabri hulka "
            L"kuuluvad diagonaalsed. Kõik lahtrid muutuvad korraga. Vastasservad liituvad: vasak paremaga, "
            L"ülemine alumisega.\r\n\r\nKUVARID JA ÜHINE MAAILM\r\nEXE märkeruudud lülitavad kuvarid "
            L"sisse; sätted kehtivad ühisele maailmale. Üks sisselülitatud kuvar sisaldab tervet maailma. "
            L"Osalise valiku korral eemaldatakse täiesti tühjad read ja veerud: keskmise väljalülitamisel "
            L"liituvad vasak ja parem kuvar. Eemaldamatud sisemised augud jäävad simulatsiooni. Kõigi "
            L"kuvarite valimine või SCR säilitab töölauda ümbritseva ristküliku koos nähtamatute vahedega. "
            L"Iga kuvar näitab sama simulatsiooni oma piirkonda.\r\n\r\nALGOLEK JA MUSTRID\r\nVaikimisi "
            L"algus on juhumüra 25 % elusate lahtritega. Algtihedus 0–100 % rakendub järgmisel "
            L"taasalustusel. Ainult tuntud mustrid kasutab 4 106 kaasasolevat mustrit ilma mürata ja "
            L"keelab tiheduse. Valige segu või nimi; mõõtmed on lahtrites. Otsimiseks tippige nimi. "
            L"Näidatakse ainult täielikult mahtuvaid mustreid. Väikesed kontrollitud mustrid korduvad "
            L"eraldi koopiatena, suured või keerukad ilmuvad üks kord keskele. Väiksem maailm võib liiga "
            L"suure valiku asendada seguga. Režiimi või mustri muutmine loob uue stseeni. Taasalustused "
            L"säilitavad valiku; kataloog töötab võrguta.\r\n\r\nLAHTRI SUURUS, RUUDUSTIK JA "
            L"VÄRVID\r\nRuudustikuta on lahtri suurus 1–64 px. Ruudustik lisab olemasoleva sammu sisse 1 "
            L"px serva: näidatav väärtus ja liugur vähenevad ühe võrra, kasutatav on 1–63. Väljalülitamine "
            L"taastab väärtuse. Liugur säilitab kogu vahemiku ja hüppab keelatud otspunktist tagasi; "
            L"märkeruut jääb aktiivseks. Lülitamine säilitab stseeni, välja arvatud sisselülitamine 1 px "
            L"juures: samm kasvab 2 px-ni ja stseen algab uuesti. Suuruse või kuvarite muutmine alustab "
            L"samuti uuesti. Väga suur maailm võib vajada kõrgemat alampiiri. Lahtrite, tausta ja "
            L"ruudustiku värvid muutuvad eraldi ilma taasalustuseta. Elusate lahtrite juhuslik värv "
            L"valitakse igal käsitsi või automaatsel stseeni taasalustamisel uuesti. Salvestatud värv "
            L"säilib ja taastub valiku väljalülitamisel. Sama käitumise saab eraldi lubada taustale ja "
            L"ruudustikule; mõlemad uued valikud on vaikimisi väljas.\r\n\r\nKIIRUS, PAUS JA AUTOMAATNE "
            L"TAASALUSTUS\r\nKiirus on 0–240 põlvkonda/s kuvari värskendusest sõltumatult; 0 peatab "
            L"arengu. Paus ja Jätka säilitavad maailma. Alusta uuesti teeb uue alguse valitud režiimis. "
            L"Valikuline automaatne taasalustus tuvastab püsivad ja täpselt korduvad nähtavad faasid, ka "
            L"ostsillaatorid. Võrreldakse põlvkondi, mitte sekundeid; nähtamatud alad jäetakse välja. "
            L"Asünkroonsed tulemused võivad algust veidi viivitada. Vaikimisi: samm 8 px, 20 põlvkonda/s, "
            L"elusrakkude juhuslik värv ja automaatne taasalustus sees. Ruudustik on vaikimisi välja "
            L"lülitatud. Saavutatud kiirus sõltub jõudlusest ja lahtrite arvust. Automaatne taasalustus "
            L"võrdleb sisselülitatud kuvarite piirkondi; nendevahelised tühimikud arenevad edasi, kuid "
            L"võrdluses ei osale.\r\n\r\nLähtesta väärtused\r\nLähtestamine seab kuvatava lahtri suuruseks "
            L"8 px ruudustikuga või ilma (samm 9 või 8 px), kiiruseks 20 põlvkonda/s, tiheduseks 25 % ja "
            L"taastab kolm vaikevärvi. Muud valikud säilivad; muster, mis enam ei mahu, asendatakse "
            L"seguga. Uus stseen tekib ainult sammu muutumisel või tiheduse muutumisel "
            L"mürarežiimis.\r\n\r\nERALDI RAKENDUS JA MP4-SALVESTUS\r\nEXE salvestab sätted jooksvalt ja "
            L"esimese aktiivse kuvari MP4-ks. Pakutakse kausta Videod, selle puudumisel Dokumendid. "
            L"Viewport kasutab kuvari mõõtmeid ja kuni 60 kaadrit/s värskendust. TV pakub 1920 × 1080, "
            L"1440 × 1080 või 1280 × 720 kuvasuhtega 16:9 ning 50, 25, 59,94 (60000/1001) või 29,97 "
            L"(30000/1001) kaadrit/s. Kuvasuhe säilib; TV kasutab progressiivset piiratud vahemikuga "
            L"BT.709 ja 4:2:0. Eraldi sätete akna saab minimeerida. OK salvestab järgmise salvestuse "
            L"jaoks; Loobu või Esc tühistab kinnitamata muudatused. Salvestatavat kuvarit ei saa välja "
            L"lülitada; muid väljundeid saab muuta. Väljumine salvestuse ajal nõuab kinnitust. Aktiivses "
            L"animatsioonis lülitab tühik pausi, F9: Alusta salvestamist; F10: Peata salvestamine. Kursor "
            L"kaob 1 sekundi tegevusetuse järel ning ilmub liigutamisel. Tab/Shift+Tab liigub "
            L"juhtelementide vahel, Alt aktiveerib allajoonitud käsud. Esc sulgeb Abi/Teave või väljub "
            L"peaaknast.\r\n\r\nHETKTÕMMIS JA EKRAANISÄÄSTJA HALDUS EXE-S\r\nHetktõmmis salvestab "
            L"BMP/GIF/JPEG/PNG/TIFF/WebP "
            L"salvestatavast kuvarist või muul juhul esimesest aktiivsest kuvarist selle eraldusvõimega, "
            L"stseeni taasalustamata. Pakutakse kausta Pildid, selle puudumisel Dokumendid. Ekraanisäästja "
            L"blokeerimine animatsiooni ajal takistab selle käivitumist, kui animatsioon on nähtav ega ole "
            L"pausil. Nullkiirus ei ole paus. EXE-st paigaldamine pakib kaasasoleva SCR-i lahti ja valib "
            L"selle Windowsi ekraanisäästjaks. Paigaldamine ja eemaldamine võivad vajada administraatori "
            L"kinnitust; olekuriba näitab toimingut selle lõpuni. Kui eemaldamine on blokeeritud, sulgege "
            L"töötav säästja, selle sätted ja Windowsi eelvaade.\r\n\r\nWINDOWSI "
            L"EKRAANISÄÄSTJA\r\nGameOfLife.scr kasutab kõiki kuvareid ja EXE-st eraldi sätteid. Eelvaate "
            L"lubamine käivitab täisekraananimatsiooni avatud sätetega. Väike Windowsi eelvaade vähendab "
            L"tervet maailma. OK salvestab, Loobu või Esc tühistab muudatused. Hiire liigutamine või klahv "
            L"sulgeb täisekraanisäästja. MP4-salvestus on saadaval EXE-s.\r\n\r\nAKENDE ASUKOHT JA "
            L"OLEK\r\nSulgemisel salvestatakse peaakna ja Teabe akna asukohad eraldi; Abi puhul ka suurus "
            L"ja minimeerimisele eelnenud tavaline või maksimeeritud olek. See ei sõltu rakenduse sätete "
            L"kinnitamisest. Rakenduse lõpetamine sulgeb ka Abi ja Teabe aknad.\r\n\r\nRENDERDUS JA "
            L"MUSTRITE LITSENTSID\r\nAreng ja nähtavate olekute võrdlus kasutavad GPU Direct3D 11 "
            L"varjutajaid; riistvara lähtestamise nurjumisel saab kasutada tarkvaralist renderdust. Iga "
            L"kuvar kasutab kontrollitud kaadriajastust oma värskendussagedusel. MP4 vajab Media "
            L"Foundationit ja H.264-kodeerijat. Mustrid pärinevad LifeWikist (GFDL 1.2 või uuem) ja Alan "
            L"Henseli avaliku omandi kogudest. Programmi kood on MIT-litsentsiga; kataloogi teated ja "
            L"litsentsid on eraldi.\r\n\r\nWindowsi ekraanisäästja… avab süsteemi ekraanisäästja sätted."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nREEGLID\r\nConway elumäng kasutab B3/S23 reegleid. Surnud lahter sünnib "
            L"täpselt kolme elusa naabriga; elus lahter jääb ellu kahe või kolmega. Kaheksa naabri hulka "
            L"kuuluvad diagonaalsed. Kõik lahtrid muutuvad korraga. Vastasservad liituvad: vasak paremaga, "
            L"ülemine alumisega.\r\n\r\nKUVARID JA ÜHINE MAAILM\r\nEXE märkeruudud lülitavad kuvarid "
            L"sisse; sätted kehtivad ühisele maailmale. Üks sisselülitatud kuvar sisaldab tervet maailma. "
            L"Osalise valiku korral eemaldatakse täiesti tühjad read ja veerud: keskmise väljalülitamisel "
            L"liituvad vasak ja parem kuvar. Eemaldamatud sisemised augud jäävad simulatsiooni. Kõigi "
            L"kuvarite valimine või SCR säilitab töölauda ümbritseva ristküliku koos nähtamatute vahedega. "
            L"Iga kuvar näitab sama simulatsiooni oma piirkonda.\r\n\r\nALGOLEK JA MUSTRID\r\nVaikimisi "
            L"algus on juhumüra 25 % elusate lahtritega. Algtihedus 0–100 % rakendub järgmisel "
            L"taasalustusel. Ainult tuntud mustrid kasutab 4 106 kaasasolevat mustrit ilma mürata ja "
            L"keelab tiheduse. Valige segu või nimi; mõõtmed on lahtrites. Otsimiseks tippige nimi. "
            L"Näidatakse ainult täielikult mahtuvaid mustreid. Väikesed kontrollitud mustrid korduvad "
            L"eraldi koopiatena, suured või keerukad ilmuvad üks kord keskele. Väiksem maailm võib liiga "
            L"suure valiku asendada seguga. Režiimi või mustri muutmine loob uue stseeni. Taasalustused "
            L"säilitavad valiku; kataloog töötab võrguta.\r\n\r\nLAHTRI SUURUS, RUUDUSTIK JA "
            L"VÄRVID\r\nRuudustikuta on lahtri suurus 1–64 px. Ruudustik lisab olemasoleva sammu sisse 1 "
            L"px serva: näidatav väärtus ja liugur vähenevad ühe võrra, kasutatav on 1–63. Väljalülitamine "
            L"taastab väärtuse. Liugur säilitab kogu vahemiku ja hüppab keelatud otspunktist tagasi; "
            L"märkeruut jääb aktiivseks. Lülitamine säilitab stseeni, välja arvatud sisselülitamine 1 px "
            L"juures: samm kasvab 2 px-ni ja stseen algab uuesti. Suuruse või kuvarite muutmine alustab "
            L"samuti uuesti. Väga suur maailm võib vajada kõrgemat alampiiri. Lahtrite, tausta ja "
            L"ruudustiku värvid muutuvad eraldi ilma taasalustuseta. Elusate lahtrite juhuslik värv "
            L"valitakse igal käsitsi või automaatsel stseeni taasalustamisel uuesti. Salvestatud värv "
            L"säilib ja taastub valiku väljalülitamisel. Sama käitumise saab eraldi lubada taustale ja "
            L"ruudustikule; mõlemad uued valikud on vaikimisi väljas.\r\n\r\nKIIRUS, PAUS JA AUTOMAATNE "
            L"TAASALUSTUS\r\nKiirus on 0–240 põlvkonda/s kuvari värskendusest sõltumatult; 0 peatab "
            L"arengu. Paus ja Jätka säilitavad maailma. Alusta uuesti teeb uue alguse valitud režiimis. "
            L"Valikuline automaatne taasalustus tuvastab püsivad ja täpselt korduvad nähtavad faasid, ka "
            L"ostsillaatorid. Võrreldakse põlvkondi, mitte sekundeid; nähtamatud alad jäetakse välja. "
            L"Asünkroonsed tulemused võivad algust veidi viivitada. Vaikimisi: samm 8 px, 20 põlvkonda/s, "
            L"elusrakkude juhuslik värv ja automaatne taasalustus sees. Ruudustik on vaikimisi välja "
            L"lülitatud. Saavutatud kiirus sõltub jõudlusest ja lahtrite arvust. Automaatne taasalustus "
            L"võrdleb sisselülitatud kuvarite piirkondi; nendevahelised tühimikud arenevad edasi, kuid "
            L"võrdluses ei osale.\r\n\r\nLähtesta väärtused\r\nLähtestamine seab kuvatava lahtri suuruseks "
            L"8 px ruudustikuga või ilma (samm 9 või 8 px), kiiruseks 20 põlvkonda/s, tiheduseks 25 % ja "
            L"taastab kolm vaikevärvi. Muud valikud säilivad; muster, mis enam ei mahu, asendatakse "
            L"seguga. Uus stseen tekib ainult sammu muutumisel või tiheduse muutumisel "
            L"mürarežiimis.\r\n\r\nWINDOWSI EKRAANISÄÄSTJA\r\nGameOfLife.scr kasutab kõiki kuvareid ja "
            L"EXE-st eraldi sätteid. Eelvaate lubamine käivitab täisekraananimatsiooni avatud sätetega. "
            L"Väike Windowsi eelvaade vähendab tervet maailma. OK salvestab, Loobu või Esc tühistab "
            L"muudatused. Hiire liigutamine või klahv sulgeb täisekraanisäästja. MP4-salvestus on saadaval "
            L"EXE-s.\r\n\r\nAKENDE ASUKOHT JA OLEK\r\nSulgemisel salvestatakse peaakna ja Teabe akna "
            L"asukohad eraldi; Abi puhul ka suurus ja minimeerimisele eelnenud tavaline või maksimeeritud "
            L"olek. See ei sõltu rakenduse sätete kinnitamisest. Rakenduse lõpetamine sulgeb ka Abi ja "
            L"Teabe aknad.\r\n\r\nRENDERDUS JA MUSTRITE LITSENTSID\r\nAreng ja nähtavate olekute võrdlus "
            L"kasutavad GPU Direct3D 11 varjutajaid; riistvara lähtestamise nurjumisel saab kasutada "
            L"tarkvaralist renderdust. Iga kuvar kasutab kontrollitud kaadriajastust oma "
            L"värskendussagedusel. MP4 vajab Media Foundationit ja H.264-kodeerijat. Mustrid pärinevad "
            L"LifeWikist (GFDL 1.2 või uuem) ja Alan Henseli avaliku omandi kogudest. Programmi kood on "
            L"MIT-litsentsiga; kataloogi teated ja litsentsid on eraldi."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Lahtri suurus: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Kiirus: %u põlvkonda/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Algtihedus: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Käivita stseen uuesti" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Elusate lahtrite värv…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Taustavärv…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Valitud kuvarid jagavad maailma. Tühjad ribad eemaldatakse; sisemised augud jäävad."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animatsioon töötab…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animatsioon on peatatud."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Direct3D renderdajat ei saanud käivitada."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Luba eelvaade"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Keela eelvaade"
        },
        LocalizedText{ TXT_MONITOR,
            L"Kuvar"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Eraldusvõime"
        },
        LocalizedText{ TXT_POSITION,
            L"Asukoht"
        },
        LocalizedText{ TXT_PRIMARY,
            L"peamine"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Kuvari mudel"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Värskendussagedus"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bitisügavus"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Värvivorming"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Värviruum"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bitti/kanal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bitti/piksel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Animatsioonikuvar"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Valmis"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Näita ruudustikku"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Ruudustiku värv…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Alusta paigalseisvat või korduvat nähtavat stseeni automaatselt uuesti"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Ainult tuntud mustrid"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Alusta salvestamist…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Peata salvestamine"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4 salvestamine…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Salvestis on salvestatud."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"MP4 salvestamist ei saanud alustada."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Rakenduse sulgemine lõpetab käimasoleva salvestamise."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Salvestussätted"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Eraldusvõime:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Kaadrisagedus:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Muudatused rakenduvad järgmisele MP4 salvestusele."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Sobivate mustrite segu"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Valitud muster ei mahu enam maailma. Valiti sobiv segu."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Tuntud mustrite kataloogi ei saanud laadida."
        },
    }),
    DefineLanguage(LANG_GA, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Dath randamach cúlra gach uair a atosaítear an radharc"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Dath randamach eangaí gach uair a atosaítear an radharc" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Spárálaí scáileáin Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Ní féidir socruithe spárálaí scáileáin Windows a oscailt."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Athshocraigh luachanna" },
        LocalizedText{ TXT_SNAPSHOT, L"Seat scáileáin…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Sábháladh an íomhá BMP/GIF/JPEG/PNG/TIFF/WebP." },
        LocalizedText{ TXT_SNAPSHOT_FAILED,
            L"Níorbh fhéidir an íomhá BMP/GIF/JPEG/PNG/TIFF/WebP a shábháil."
        },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Cosc ar spárálaí scáileáin le linn beochana" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Dath randamach do chealla beo gach uair a athshocraítear an radharc"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Spárálaí scáileáin á shuiteáil…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Spárálaí scáileáin á dhíshuiteáil…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Suiteáil spárálaí scáileáin" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Díshuiteáil spárálaí scáileáin" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Níor suiteáladh an spárálaí scáileáin." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Suiteáladh an spárálaí scáileáin." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Díshuiteáladh an spárálaí scáileáin." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Níorbh fhéidir an spárálaí scáileáin a dhíshuiteáil. Dún é agus a réamhamharc agus bain triail "
            L"eile as."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Dún fuinneog socruithe GameOfLife agus bain triail eile as an díshuiteáil."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Dún fuinneog socruithe spárálaí scáileáin Windows agus bain triail eile as an díshuiteáil."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Dún an spárálaí scáileáin nó an réamhamharc lánscáileáin le Esc nó trí an luch a bhogadh agus "
            L"bain triail eile as."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Gaeilge"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — rialuithe"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Socruithe GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Teanga:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Cealaigh"
        },
        LocalizedText{ TXT_EXIT,
            L"Scoir"
        },
        LocalizedText{ TXT_PAUSE,
            L"Cuir ar sos"
        },
        LocalizedText{ TXT_RESUME,
            L"Lean ar aghaidh"
        },
        LocalizedText{ TXT_HELP,
            L"Cabhair"
        },
        LocalizedText{ TXT_ABOUT,
            L"Maidir leis"
        },
        LocalizedText{ TXT_CLOSE,
            L"Dún"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Oscail an suíomh gréasáin %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Ní féidir an suíomh a oscailt sa bhrabhsálaí réamhshocraithe."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Níorbh fhéidir an URL a chóipeáil go dtí an ghearrthaisce."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Níorbh fhéidir an fhaisnéis a chóipeáil go dtí an ghearrthaisce."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Cluiche na Beatha de chuid Conway i ndomhan comhroinnte ar roinnt scáileán."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Leagan:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Sprioc-ardán:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Suíomh gréasáin:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Oscail sa bhrabhsálaí réamhshocraithe"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Cóipeáil an &seoladh"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Cóipeáil an &fhaisnéis"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Níl acmhainn an cheadúnais ar fáil."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nRIALACHA\r\nÚsáideann Cluiche na Beatha de chuid Conway B3/S23. Tagann "
            L"cill mharbh ar an saol le trí chomharsa bheo go díreach; maireann cill bheo le dhá nó trí "
            L"chomharsa bheo. Áirítear na trasnáin sna hocht gcomharsa. Athraíonn gach cill ag an am "
            L"céanna. Ceanglaítear na himill urchomhaireacha: clé le deas, barr le bun.\r\n\r\nSCÁILEÁIN "
            L"AGUS DOMHAN COMHROINNTE\r\nCumasaíonn ticbhoscaí EXE na scáileáin; baineann na socruithe "
            L"leis an domhan comhroinnte. Cuimsíonn scáileán amháin cumasaithe an domhan ar fad. Má "
            L"roghnaítear cuid den leagan amach, baintear sraitheanna agus colúin atá go hiomlán folamh: "
            L"ceanglaítear an scáileán clé agus deas nuair a dhíchumasaítear an ceann láir. Fanann poill "
            L"inmheánacha nach féidir a bhaint san ionsamhlúchán. Coinníonn roghnú gach scáileáin, nó SCR, "
            L"dronuilleog na deisce agus na bearnaí dofheicthe. Taispeánann gach scáileán a chuid den "
            L"ionsamhlúchán céanna.\r\n\r\nSTAID TOSAIGH AGUS PATRÚIN\r\nIs torann randamach le 25 % de "
            L"chealla beo an tús réamhshocraithe. Bíonn dlús tosaigh 0–100 % i bhfeidhm ag an gcéad atosú "
            L"eile. Úsáideann Patrúin aitheanta amháin 4,106 patrún cuachta gan torann agus díchumasaíonn "
            L"sé dlús. Roghnaigh meascán nó ainm; tugtar toisí i gcealla. Clóscríobh ainm chun cuardach. "
            L"Ní thairgtear ach patrúin a luíonn ina n-iomláine. Déantar cóipeanna ar leith de phatrúin "
            L"bheaga fhíoraithe; tosaíonn cinn mhóra nó chasta uair amháin sa lár. D'fhéadfadh domhan níos "
            L"lú meascán a chur in ionad rogha nach luíonn. Cruthaíonn athrú mód nó patrúin radharc nua. "
            L"Coinníonn atosú an rogha; oibríonn an chatalóg as líne.\r\n\r\nMÉID CILLE, EANGACH AGUS "
            L"DATHANNA\r\nGan eangach, is é 1–64 px méid na cille. Cuireann an eangach imeall 1 px "
            L"laistigh den spásáil reatha: laghdaíonn an luach agus an sleamhnán faoi aon, le 1–63 "
            L"inúsáidte. Cuireann múchadh an luach ar ais. Coinníonn an sleamhnán a raon agus filleann sé "
            L"ón bhfoirceann nach bhfuil ar fáil; fanann an ticbhosca cumasaithe. Caomhnaítear an radharc "
            L"agus an eangach á scoránú, ach ag 1 px méadaíonn cumasú an spásáil go 2 px agus tosaíonn "
            L"radharc nua. Tosaíonn athrú méide nó scáileán as an nua freisin. D'fhéadfadh domhan an-mhór "
            L"íosmhéid níos airde a éileamh. Athraítear dathanna ceall, cúlra agus eangaí ar leith gan "
            L"atosú. Roghnaíonn dath randamach na gceall beo dath nua ag gach atosú láimhe nó uathoibríoch "
            L"den radharc. Caomhnaítear do dhath sábháilte agus cuirtear ar ais é nuair a dhíchumasaítear "
            L"an rogha seo. Is féidir an t-iompar céanna a chumasú ar leithligh don chúlra agus don "
            L"eangach; tá an dá rogha nua múchta de réir réamhshocraithe.\r\n\r\nLUAS, SOS AGUS ATOSÚ "
            L"UATHOIBRÍOCH\r\nIs é an luas 0–240 glúin/s, neamhspleách ar athnuachan an scáileáin; stopann "
            L"0 an fhorbairt. Coinníonn Sos agus Lean ar aghaidh an domhan. Tosaíonn Atosaigh sa mhód "
            L"roghnaithe. Aimsíonn atosú uathoibríoch roghnach céimeanna infheicthe seasta nó "
            L"athfhillteacha beachta, ascalaitheoirí san áireamh. Déantar comparáid idir glúnta, ní "
            L"soicindí; fágtar limistéir dhofheicthe as. D'fhéadfadh torthaí aisioncrónacha moill bheag a "
            L"chur ar atosú. Réamhshocruithe: spásáil 8 px, 20 glúin/s, dath randamach na gceall beo agus "
            L"atosú uathoibríoch ar siúl. Tá an eangach múchta de réir réamhshocraithe. Braitheann an luas "
            L"a bhaintear amach ar fheidhmíocht agus ar líon na gceall. Seiceálann atosú uathoibríoch "
            L"réigiúin na scáileán cumasaithe; leanann bearnaí eatarthu ag forbairt ach ní chuirtear san "
            L"áireamh iad sa chomparáid.\r\n\r\nAthshocraigh luachanna\r\nSocraíonn athshocrú an méid "
            L"cille ar taispeáint go 8 px leis an eangach nó gan í (spásáil 9 nó 8 px), an luas go 20 "
            L"glúin/s, an dlús go 25 % agus na trí dhath réamhshocraithe. Coinnítear na roghanna eile; "
            L"cuirtear an meascán in áit patrúin nach n-oireann a thuilleadh. Ní chruthaítear radharc nua "
            L"ach má athraíonn an spásáil nó má athraíonn an dlús sa mhód torainn.\r\n\r\nFEIDHMCHLÁR "
            L"NEAMHSPLEÁCH AGUS TAIFEADADH MP4\r\nSábhálann EXE socruithe go leanúnach agus taifeadann sé "
            L"an chéad scáileán gníomhach mar MP4. Moltar Físeáin, nó Doiciméid mar rogha eile. Úsáideann "
            L"Viewport toisí agus athnuachan an scáileáin suas le 60 fráma/s. Cuireann TV 1920 × 1080, "
            L"1440 × 1080 nó 1280 × 720 ar fáil i 16:9 ag 50, 25, 59.94 (60000/1001) nó 29.97 (30000/1001) "
            L"fráma/s. Coinnítear an cóimheas gné; úsáideann TV BT.709 forásach le raon teoranta agus "
            L"4:2:0. Is féidir an fhuinneog neamhspleách socruithe a íoslaghdú. Sábhálann OK don chéad "
            L"taifeadadh eile; caitheann Cealaigh nó Esc athruithe neamhdheimhnithe amach. Ní féidir an "
            L"scáileán taifeadta a dhíchumasú; is féidir aschuir eile a athrú. Teastaíonn deimhniú chun "
            L"imeacht le linn taifeadta. Le fócas ar an mbeochan, scoránaíonn Spás an sos, F9: Tosaigh "
            L"taifeadadh; F10: Stop taifeadadh. Imíonn an cúrsóir tar éis 1 soicind neamhghníomhaíochta "
            L"agus filleann sé le gluaiseacht. Bogann Tab/Shift+Tab idir rialtáin; gníomhaíonn Alt "
            L"orduithe a bhfuil líne fúthu. Dúnann Esc Cabhair/Maidir leis, nó scoireann sé sa "
            L"phríomhfhuinneog.\r\n\r\nGABHÁIL ÍOMHÁ AGUS BAINISTIÚ AN SPÁRÁLAÍ IN EXE\r\nSábhálann "
            L"gabháil íomhá BMP/GIF/JPEG/PNG/TIFF/WebP den scáileán atá á thaifeadadh, nó den chéad scáileán "
            L"gníomhach murach "
            L"sin, ag a thaifeach féin gan an radharc a atosú. Moltar Pictiúir, nó Doiciméid mar rogha "
            L"eile. Cuireann bac ar an spárálaí le linn beochana cosc ar a thosú fad atá an bheochan "
            L"infheicthe agus gan sos. Ní hionann luas nialasach agus sos. Díphacálann suiteáil ó EXE an "
            L"SCR cuachta agus roghnaíonn sí é mar spárálaí Windows. D’fhéadfadh cead riarthóra a bheith "
            L"de dhíth ar shuiteáil agus díshuiteáil; taispeánann an barra stádais an oibríocht go dtí go "
            L"gcríochnaíonn sí. Má chuirtear bac ar bhaint, dún an spárálaí reatha, a shocruithe agus "
            L"réamhamharc Windows.\r\n\r\nSPÁRÁLAÍ SCÁILEÁIN WINDOWS\r\nÚsáideann GameOfLife.scr gach "
            L"scáileán agus socruithe ar leith ó EXE. Tosaíonn réamhamharc beochan lánscáileáin agus na "
            L"socruithe ar oscailt. Laghdaíonn réamhamharc beag Windows an domhan iomlán. Sábhálann OK; "
            L"caitheann Cealaigh nó Esc athruithe amach. Dúnann gluaiseacht luiche nó eochair an spárálaí "
            L"lánscáileáin. Tá taifeadadh MP4 ar fáil in EXE.\r\n\r\nSUÍOMH AGUS STAID NA "
            L"bhFUINNEOG\r\nSábháiltear suíomhanna na príomhfhuinneoige agus Maidir leis ar leith nuair a "
            L"dhúntar iad; sábhálann Cabhair a méid agus a staid ghnáthach nó uasmhéadaithe roimh "
            L"íoslaghdú freisin. Tá sé seo neamhspleách ar dheimhniú socruithe an fheidhmchláir. Dúnann "
            L"imeacht ón bhfeidhmchlár Cabhair agus Maidir leis freisin.\r\n\r\nRINDREÁIL AGUS CEADÚNAIS "
            L"NA BPATRÚN\r\nÚsáideann forbairt agus comparáidí infheicthe scáthóirí Direct3D 11 ar an GPU; "
            L"tá rindreáil bhogearraí ar fáil má theipeann ar thúsú crua-earraí. Úsáideann gach scáileán "
            L"an rialtóir ama frámaí cruthaithe ag a mhinicíocht féin. Teastaíonn Media Foundation agus "
            L"ionchódóir H.264 ó MP4. Tagann patrúin ó LifeWiki (GFDL 1.2 nó níos déanaí) agus bailiúcháin "
            L"fearainn phoiblí Alan Hensel. Tá cód an chláir faoi MIT; tá fógraí agus ceadúnais na "
            L"catalóige ar leith.\r\n\r\nOsclaíonn Spárálaí scáileáin Windows… socruithe spárálaí "
            L"scáileáin an chórais."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nRIALACHA\r\nÚsáideann Cluiche na Beatha de chuid Conway B3/S23. Tagann "
            L"cill mharbh ar an saol le trí chomharsa bheo go díreach; maireann cill bheo le dhá nó trí "
            L"chomharsa bheo. Áirítear na trasnáin sna hocht gcomharsa. Athraíonn gach cill ag an am "
            L"céanna. Ceanglaítear na himill urchomhaireacha: clé le deas, barr le bun.\r\n\r\nSCÁILEÁIN "
            L"AGUS DOMHAN COMHROINNTE\r\nCumasaíonn ticbhoscaí EXE na scáileáin; baineann na socruithe "
            L"leis an domhan comhroinnte. Cuimsíonn scáileán amháin cumasaithe an domhan ar fad. Má "
            L"roghnaítear cuid den leagan amach, baintear sraitheanna agus colúin atá go hiomlán folamh: "
            L"ceanglaítear an scáileán clé agus deas nuair a dhíchumasaítear an ceann láir. Fanann poill "
            L"inmheánacha nach féidir a bhaint san ionsamhlúchán. Coinníonn roghnú gach scáileáin, nó SCR, "
            L"dronuilleog na deisce agus na bearnaí dofheicthe. Taispeánann gach scáileán a chuid den "
            L"ionsamhlúchán céanna.\r\n\r\nSTAID TOSAIGH AGUS PATRÚIN\r\nIs torann randamach le 25 % de "
            L"chealla beo an tús réamhshocraithe. Bíonn dlús tosaigh 0–100 % i bhfeidhm ag an gcéad atosú "
            L"eile. Úsáideann Patrúin aitheanta amháin 4,106 patrún cuachta gan torann agus díchumasaíonn "
            L"sé dlús. Roghnaigh meascán nó ainm; tugtar toisí i gcealla. Clóscríobh ainm chun cuardach. "
            L"Ní thairgtear ach patrúin a luíonn ina n-iomláine. Déantar cóipeanna ar leith de phatrúin "
            L"bheaga fhíoraithe; tosaíonn cinn mhóra nó chasta uair amháin sa lár. D'fhéadfadh domhan níos "
            L"lú meascán a chur in ionad rogha nach luíonn. Cruthaíonn athrú mód nó patrúin radharc nua. "
            L"Coinníonn atosú an rogha; oibríonn an chatalóg as líne.\r\n\r\nMÉID CILLE, EANGACH AGUS "
            L"DATHANNA\r\nGan eangach, is é 1–64 px méid na cille. Cuireann an eangach imeall 1 px "
            L"laistigh den spásáil reatha: laghdaíonn an luach agus an sleamhnán faoi aon, le 1–63 "
            L"inúsáidte. Cuireann múchadh an luach ar ais. Coinníonn an sleamhnán a raon agus filleann sé "
            L"ón bhfoirceann nach bhfuil ar fáil; fanann an ticbhosca cumasaithe. Caomhnaítear an radharc "
            L"agus an eangach á scoránú, ach ag 1 px méadaíonn cumasú an spásáil go 2 px agus tosaíonn "
            L"radharc nua. Tosaíonn athrú méide nó scáileán as an nua freisin. D'fhéadfadh domhan an-mhór "
            L"íosmhéid níos airde a éileamh. Athraítear dathanna ceall, cúlra agus eangaí ar leith gan "
            L"atosú. Roghnaíonn dath randamach na gceall beo dath nua ag gach atosú láimhe nó uathoibríoch "
            L"den radharc. Caomhnaítear do dhath sábháilte agus cuirtear ar ais é nuair a dhíchumasaítear "
            L"an rogha seo. Is féidir an t-iompar céanna a chumasú ar leithligh don chúlra agus don "
            L"eangach; tá an dá rogha nua múchta de réir réamhshocraithe.\r\n\r\nLUAS, SOS AGUS ATOSÚ "
            L"UATHOIBRÍOCH\r\nIs é an luas 0–240 glúin/s, neamhspleách ar athnuachan an scáileáin; stopann "
            L"0 an fhorbairt. Coinníonn Sos agus Lean ar aghaidh an domhan. Tosaíonn Atosaigh sa mhód "
            L"roghnaithe. Aimsíonn atosú uathoibríoch roghnach céimeanna infheicthe seasta nó "
            L"athfhillteacha beachta, ascalaitheoirí san áireamh. Déantar comparáid idir glúnta, ní "
            L"soicindí; fágtar limistéir dhofheicthe as. D'fhéadfadh torthaí aisioncrónacha moill bheag a "
            L"chur ar atosú. Réamhshocruithe: spásáil 8 px, 20 glúin/s, dath randamach na gceall beo agus "
            L"atosú uathoibríoch ar siúl. Tá an eangach múchta de réir réamhshocraithe. Braitheann an luas "
            L"a bhaintear amach ar fheidhmíocht agus ar líon na gceall. Seiceálann atosú uathoibríoch "
            L"réigiúin na scáileán cumasaithe; leanann bearnaí eatarthu ag forbairt ach ní chuirtear san "
            L"áireamh iad sa chomparáid.\r\n\r\nAthshocraigh luachanna\r\nSocraíonn athshocrú an méid "
            L"cille ar taispeáint go 8 px leis an eangach nó gan í (spásáil 9 nó 8 px), an luas go 20 "
            L"glúin/s, an dlús go 25 % agus na trí dhath réamhshocraithe. Coinnítear na roghanna eile; "
            L"cuirtear an meascán in áit patrúin nach n-oireann a thuilleadh. Ní chruthaítear radharc nua "
            L"ach má athraíonn an spásáil nó má athraíonn an dlús sa mhód torainn.\r\n\r\nSPÁRÁLAÍ "
            L"SCÁILEÁIN WINDOWS\r\nÚsáideann GameOfLife.scr gach scáileán agus socruithe ar leith ó EXE. "
            L"Tosaíonn réamhamharc beochan lánscáileáin agus na socruithe ar oscailt. Laghdaíonn "
            L"réamhamharc beag Windows an domhan iomlán. Sábhálann OK; caitheann Cealaigh nó Esc athruithe "
            L"amach. Dúnann gluaiseacht luiche nó eochair an spárálaí lánscáileáin. Tá taifeadadh MP4 ar "
            L"fáil in EXE.\r\n\r\nSUÍOMH AGUS STAID NA bhFUINNEOG\r\nSábháiltear suíomhanna na "
            L"príomhfhuinneoige agus Maidir leis ar leith nuair a dhúntar iad; sábhálann Cabhair a méid "
            L"agus a staid ghnáthach nó uasmhéadaithe roimh íoslaghdú freisin. Tá sé seo neamhspleách ar "
            L"dheimhniú socruithe an fheidhmchláir. Dúnann imeacht ón bhfeidhmchlár Cabhair agus Maidir "
            L"leis freisin.\r\n\r\nRINDREÁIL AGUS CEADÚNAIS NA BPATRÚN\r\nÚsáideann forbairt agus "
            L"comparáidí infheicthe scáthóirí Direct3D 11 ar an GPU; tá rindreáil bhogearraí ar fáil má "
            L"theipeann ar thúsú crua-earraí. Úsáideann gach scáileán an rialtóir ama frámaí cruthaithe ag "
            L"a mhinicíocht féin. Teastaíonn Media Foundation agus ionchódóir H.264 ó MP4. Tagann patrúin "
            L"ó LifeWiki (GFDL 1.2 nó níos déanaí) agus bailiúcháin fearainn phoiblí Alan Hensel. Tá cód "
            L"an chláir faoi MIT; tá fógraí agus ceadúnais na catalóige ar leith."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Méid cille: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Luas: %u glúin/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Dlús tosaigh: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Atosaigh an radharc" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Dath na gceall beo…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Dath an chúlra…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Roinneann na scáileáin domhan amháin. Baintear bandaí folmha; fanann poill inmheánacha."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Tá an bheochan ar siúl…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Tá an bheochan ar sos."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Níorbh fhéidir an rindreálaí Direct3D a thúsú."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Réamhamharc" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Stop réamhamharc" },
        LocalizedText{ TXT_MONITOR,
            L"Monatóir"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Taifeach"
        },
        LocalizedText{ TXT_POSITION,
            L"Suíomh"
        },
        LocalizedText{ TXT_PRIMARY,
            L"príomhúil"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Samhail an mhonatóra"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Ráta athnuachana"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Doimhneacht ghiotán"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Formáid datha"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Spás datha"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u giotán/cainéal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u giotán/picteilín"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Monatóir beochana"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Réidh"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Taispeáin an eangach"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Dath na heangaí…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Atosaigh radharc infheicthe socair nó athfhillteach go huathoibríoch"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Patrúin aitheanta amháin"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Tosaigh taifeadadh…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Stop taifeadadh"
        },
        LocalizedText{ TXT_RECORDING,
            L"Tá taifeadadh MP4 ar siúl…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Sábháladh an taifeadadh."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Níorbh fhéidir taifeadadh MP4 a thosú."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Stopfar an taifeadadh atá ar siúl má dhúntar an feidhmchlár."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Socruithe taifeadta"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Taifeach:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Ráta frámaí:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Cuirfear na hathruithe i bhfeidhm ar an gcéad taifeadadh MP4 eile."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Meascán de phatrúin oiriúnacha"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Ní luíonn an patrún roghnaithe sa domhan a thuilleadh. Roghnaíodh meascán oiriúnach."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Níorbh fhéidir catalóg na bpatrún aitheanta a lódáil."
        },
    }),
    DefineLanguage(LANG_LT, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Atsitiktinė fono spalva kiekvieną kartą paleidus sceną iš naujo"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR,
            L"Atsitiktinė tinklelio spalva kiekvieną kartą paleidus sceną iš naujo"
        },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"„Windows“ ekrano užsklanda…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Nepavyko atverti „Windows“ ekrano užsklandos parametrų."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Atkurti reikšmes" },
        LocalizedText{ TXT_SNAPSHOT, L"Momentinė kopija…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"BMP/GIF/JPEG/PNG/TIFF/WebP vaizdas išsaugotas." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Nepavyko išsaugoti BMP/GIF/JPEG/PNG/TIFF/WebP vaizdo." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Animacijos metu neleisti ekrano užsklandos" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Atsitiktinė gyvų langelių spalva kiekvieną kartą paleidus sceną iš naujo"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Diegiama ekrano užsklanda…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Šalinama ekrano užsklanda…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Įdiegti ekrano užsklandą" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Pašalinti ekrano užsklandą" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Ekrano užsklanda neįdiegta." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Ekrano užsklanda įdiegta." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Ekrano užsklanda pašalinta." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Nepavyko pašalinti ekrano užsklandos. Uždarykite ją bei jos peržiūrą ir bandykite dar kartą."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Uždarykite GameOfLife nuostatų langą ir bandykite pašalinti dar kartą."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Uždarykite Windows ekrano užsklandos nuostatų langą ir bandykite pašalinti dar kartą."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Užbaikite užsklandą arba viso ekrano peržiūrą klavišu Esc ar pajudindami pelę ir bandykite "
            L"pašalinti dar kartą."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Lietuvių"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — valdymas"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"GameOfLife nuostatos"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Kalba:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Atšaukti"
        },
        LocalizedText{ TXT_EXIT,
            L"Išeiti"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pristabdyti"
        },
        LocalizedText{ TXT_RESUME,
            L"Tęsti"
        },
        LocalizedText{ TXT_HELP,
            L"Žinynas"
        },
        LocalizedText{ TXT_ABOUT,
            L"Apie"
        },
        LocalizedText{ TXT_CLOSE,
            L"Uždaryti"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Atidaryti svetainę %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Nepavyko atverti svetainės numatytojoje naršyklėje."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Nepavyko nukopijuoti URL į iškarpinę."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Nepavyko nukopijuoti informacijos į iškarpinę."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conway gyvybės žaidimas bendrame kelių ekranų pasaulyje."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Versija:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Tikslinė platforma:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Svetainė:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Atidaryti numatytojoje naršyklėje"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Kopijuoti &adresą"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Kopijuoti &informaciją"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Licencijos išteklius nepasiekiamas."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nTAISYKLĖS\r\nConway gyvybės žaidimas naudoja B3/S23. Negyvas langelis "
            L"atgyja turėdamas tiksliai tris gyvus kaimynus; gyvas išlieka su dviem arba trimis. Aštuoni "
            L"kaimynai apima įstrižaines. Visi langeliai keičiasi vienu metu. Priešingi kraštai sujungti: "
            L"kairė su dešine, viršus su apačia.\r\n\r\nEKRANAI IR BENDRAS PASAULIS\r\nEXE žymimieji "
            L"langeliai įjungia ekranus; nuostatos taikomos bendram pasauliui. Viename įjungtame ekrane "
            L"telpa visas pasaulis. Pasirinkus dalį ekranų, visiškai tuščios eilutės ir stulpeliai "
            L"pašalinami: išjungus vidurinį, kairysis ir dešinysis susijungia. Nepašalinamos vidinės "
            L"skylės lieka simuliacijoje. Pasirinkus visus ekranus arba naudojant SCR išlaikomas "
            L"darbalaukį apimantis stačiakampis su nematomais tarpais. Kiekvienas ekranas rodo savo tos "
            L"pačios simuliacijos dalį.\r\n\r\nPRADINĖ BŪSENA IR KONFIGŪRACIJOS\r\nNumatytoji pradžia – "
            L"atsitiktinis triukšmas su 25 % gyvų langelių. Pradinis tankis 0–100 % taikomas kitą kartą "
            L"pradedant iš naujo. Tik žinomos konfigūracijos naudoja 4 106 įtrauktas konfigūracijas be "
            L"triukšmo ir išjungia tankį. Pasirinkite mišinį arba pavadinimą; matmenys pateikti "
            L"langeliais. Ieškokite įvesdami pavadinimą. Siūlomos tik visiškai telpančios konfigūracijos. "
            L"Mažos patikrintos kartojamos atskiromis kopijomis, didelės ar sudėtingos rodomos vieną kartą "
            L"centre. Sumažinus pasaulį nebetelpantis pasirinkimas gali būti pakeistas mišiniu. Pakeitus "
            L"režimą ar konfigūraciją sukuriama nauja scena. Paleidimas iš naujo išlaiko pasirinkimą; "
            L"katalogas veikia be interneto.\r\n\r\nLANGELIAI, TINKLELIS IR SPALVOS\r\nBe tinklelio dydis "
            L"yra 1–64 px. Tinklelis prideda 1 px kraštą esamame žingsnyje: rodoma vertė ir slankiklis "
            L"sumažėja vienetu, naudojama 1–63. Išjungus vertė grąžinama. Slankiklis išlaiko visą "
            L"diapazoną ir grįžta iš neprieinamo galo; žymimasis langelis lieka aktyvus. Perjungimas "
            L"išlaiko sceną, išskyrus įjungimą ties 1 px: žingsnis tampa 2 px ir scena pradedama iš naujo. "
            L"Dydžio ar ekranų keitimas taip pat pradeda iš naujo. Labai didelis pasaulis gali reikalauti "
            L"didesnio minimumo. Langelių, fono ir tinklelio spalvos keičiamos atskirai nepaleidžiant iš "
            L"naujo. Atsitiktinė gyvų langelių spalva parenkama per kiekvieną rankinį ar automatinį scenos "
            L"paleidimą iš naujo. Išsaugota spalva nekeičiama ir atkuriama išjungus šią parinktį. Tokį pat "
            L"veikimą galima atskirai įjungti fonui ir tinkleliui; abi naujos parinktys iš pradžių "
            L"išjungtos.\r\n\r\nGREITIS, PAUZĖ IR AUTOMATINIS PALEIDIMAS IŠ NAUJO\r\nGreitis yra 0–240 "
            L"kartų/s ir nepriklauso nuo ekrano atnaujinimo; 0 sustabdo raidą. Pauzė ir Tęsti išlaiko "
            L"pasaulį. Pradėti iš naujo pradeda pasirinktą režimą. Pasirenkamas automatinis paleidimas iš "
            L"naujo atpažįsta nekintamas ir tiksliai pasikartojančias matomas fazes, taip pat "
            L"osciliatorius. Lyginamos kartos, ne sekundės; nematomos sritys neįtraukiamos. Asinchroniniai "
            L"rezultatai gali šiek tiek uždelsti paleidimą. Numatyta: 8 px žingsnis, 20 kartų/s, "
            L"atsitiktinė gyvų ląstelių spalva ir automatinis paleidimas iš naujo įjungti. Tinklelis pagal "
            L"numatytuosius nustatymus išjungtas. Pasiekiamas greitis priklauso nuo našumo ir langelių "
            L"skaičiaus. Automatinis paleidimas iš naujo lygina įjungtų ekranų sritis; tarpai tarp jų "
            L"vystosi toliau, bet į palyginimą neįtraukiami.\r\n\r\nAtkurti reikšmes\r\nAtkūrimas nustato "
            L"rodomą langelio dydį į 8 px su tinkleliu arba be jo (žingsnis 9 arba 8 px), greitį į 20 "
            L"kartų/s, tankį į 25 % ir tris numatytąsias spalvas. Kitos parinktys išsaugomos; nebetelpanti "
            L"konfigūracija pakeičiama mišiniu. Nauja scena sukuriama tik pasikeitus žingsniui arba "
            L"tankiui triukšmo režimu.\r\n\r\nATSKIRA PROGRAMA IR MP4 ĮRAŠYMAS\r\nEXE nuolat išsaugo "
            L"nuostatas ir įrašo pirmą aktyvų ekraną į MP4. Siūlomas aplankas Vaizdo įrašai, kitu atveju "
            L"Dokumentai. Viewport naudoja ekrano matmenis ir dažnį iki 60 kadrų/s. TV siūlo 1920 × 1080, "
            L"1440 × 1080 arba 1280 × 720, 16:9, 50, 25, 59,94 (60000/1001) arba 29,97 (30000/1001) "
            L"kadrų/s. Proporcijos išlaikomos; TV naudoja progresinį riboto diapazono BT.709 ir 4:2:0. "
            L"Atskirą nuostatų langą galima sumažinti. Gerai išsaugo kitam įrašymui; Atšaukti arba Esc "
            L"atmeta nepatvirtintus pakeitimus. Įrašomo ekrano išjungti negalima; kitus išėjimus keisti "
            L"galima. Išėjimas įrašymo metu prašo patvirtinimo. Kai aktyvi animacija, tarpas perjungia "
            L"pauzę, F9: Pradėti įrašymą; F10: Baigti įrašymą. Žymeklis pasislepia po 1 sekundės neveiklos "
            L"ir grįžta pajudinus. Tab/Shift+Tab keičia valdiklį, Alt vykdo pabrauktas komandas. Esc "
            L"uždaro Žinyną/Apie arba išeina pagrindiniame lange.\r\n\r\nMOMENTINĖ KOPIJA IR UŽSKLANDOS "
            L"VALDYMAS EXE\r\nMomentinė kopija išsaugo įrašomo arba, jei neįrašoma, pirmojo aktyvaus "
            L"ekrano BMP/GIF/JPEG/PNG/TIFF/WebP jo raiška nepaleidžiant scenos iš naujo. Siūlomas aplankas "
            L"Paveikslėliai, kitu "
            L"atveju Dokumentai. Užsklandos blokavimas animacijos metu neleidžia jai įsijungti, kol "
            L"animacija matoma ir nepristabdyta. Nulinis greitis nėra pauzė. Diegimas iš EXE išpakuoja "
            L"pridėtą SCR ir parenka jį kaip Windows užsklandą. Diegiant ir šalinant gali reikėti "
            L"administratoriaus leidimo; būsenos juosta rodo veiksmą iki jo pabaigos. Jei šalinimas "
            L"blokuojamas, uždarykite veikiančią užsklandą, jos nuostatas ir Windows "
            L"peržiūrą.\r\n\r\nWINDOWS EKRANO UŽSKLANDA\r\nGameOfLife.scr naudoja visus ekranus ir "
            L"atskiras nuo EXE nuostatas. Peržiūra paleidžia viso ekrano animaciją palikdama nuostatas "
            L"atviras. Maža Windows peržiūra sumažina visą pasaulį. Gerai išsaugo; Atšaukti arba Esc "
            L"atmeta pakeitimus. Pelės judesys ar klavišas uždaro viso ekrano užsklandą. MP4 įrašymas "
            L"galimas EXE.\r\n\r\nLANGŲ PADĖTIS IR BŪSENA\r\nUždarant atskirai išsaugomos pagrindinio ir "
            L"Apie langų padėtys; Žinyno atveju taip pat dydis ir įprasta arba išdidinta būsena prieš "
            L"sumažinimą. Tai nepriklauso nuo programos nuostatų patvirtinimo. Baigiant programą uždaromi "
            L"ir Žinyno bei Apie langai.\r\n\r\nATVAIZDAVIMAS IR KONFIGŪRACIJŲ LICENCIJOS\r\nRaidą ir "
            L"matomų būsenų palyginimą atlieka GPU Direct3D 11 šešėliavimo programos; nepavykus aparatinei "
            L"inicijacijai galima programinė atvaizdavimo priemonė. Kiekvienas ekranas naudoja patikrintą "
            L"kadrų laiko valdymą savo dažniu. MP4 reikia Media Foundation ir H.264 koduotuvo. "
            L"Konfigūracijos yra iš LifeWiki (GFDL 1.2 ar naujesnė) ir Alan Hensel viešojo naudojimo "
            L"rinkinių. Programos kodas yra MIT; katalogo pranešimai ir licencijos "
            L"atskiri.\r\n\r\n„Windows“ ekrano užsklanda… atveria sistemos ekrano užsklandos parametrus."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nTAISYKLĖS\r\nConway gyvybės žaidimas naudoja B3/S23. Negyvas langelis "
            L"atgyja turėdamas tiksliai tris gyvus kaimynus; gyvas išlieka su dviem arba trimis. Aštuoni "
            L"kaimynai apima įstrižaines. Visi langeliai keičiasi vienu metu. Priešingi kraštai sujungti: "
            L"kairė su dešine, viršus su apačia.\r\n\r\nEKRANAI IR BENDRAS PASAULIS\r\nEXE žymimieji "
            L"langeliai įjungia ekranus; nuostatos taikomos bendram pasauliui. Viename įjungtame ekrane "
            L"telpa visas pasaulis. Pasirinkus dalį ekranų, visiškai tuščios eilutės ir stulpeliai "
            L"pašalinami: išjungus vidurinį, kairysis ir dešinysis susijungia. Nepašalinamos vidinės "
            L"skylės lieka simuliacijoje. Pasirinkus visus ekranus arba naudojant SCR išlaikomas "
            L"darbalaukį apimantis stačiakampis su nematomais tarpais. Kiekvienas ekranas rodo savo tos "
            L"pačios simuliacijos dalį.\r\n\r\nPRADINĖ BŪSENA IR KONFIGŪRACIJOS\r\nNumatytoji pradžia – "
            L"atsitiktinis triukšmas su 25 % gyvų langelių. Pradinis tankis 0–100 % taikomas kitą kartą "
            L"pradedant iš naujo. Tik žinomos konfigūracijos naudoja 4 106 įtrauktas konfigūracijas be "
            L"triukšmo ir išjungia tankį. Pasirinkite mišinį arba pavadinimą; matmenys pateikti "
            L"langeliais. Ieškokite įvesdami pavadinimą. Siūlomos tik visiškai telpančios konfigūracijos. "
            L"Mažos patikrintos kartojamos atskiromis kopijomis, didelės ar sudėtingos rodomos vieną kartą "
            L"centre. Sumažinus pasaulį nebetelpantis pasirinkimas gali būti pakeistas mišiniu. Pakeitus "
            L"režimą ar konfigūraciją sukuriama nauja scena. Paleidimas iš naujo išlaiko pasirinkimą; "
            L"katalogas veikia be interneto.\r\n\r\nLANGELIAI, TINKLELIS IR SPALVOS\r\nBe tinklelio dydis "
            L"yra 1–64 px. Tinklelis prideda 1 px kraštą esamame žingsnyje: rodoma vertė ir slankiklis "
            L"sumažėja vienetu, naudojama 1–63. Išjungus vertė grąžinama. Slankiklis išlaiko visą "
            L"diapazoną ir grįžta iš neprieinamo galo; žymimasis langelis lieka aktyvus. Perjungimas "
            L"išlaiko sceną, išskyrus įjungimą ties 1 px: žingsnis tampa 2 px ir scena pradedama iš naujo. "
            L"Dydžio ar ekranų keitimas taip pat pradeda iš naujo. Labai didelis pasaulis gali reikalauti "
            L"didesnio minimumo. Langelių, fono ir tinklelio spalvos keičiamos atskirai nepaleidžiant iš "
            L"naujo. Atsitiktinė gyvų langelių spalva parenkama per kiekvieną rankinį ar automatinį scenos "
            L"paleidimą iš naujo. Išsaugota spalva nekeičiama ir atkuriama išjungus šią parinktį. Tokį pat "
            L"veikimą galima atskirai įjungti fonui ir tinkleliui; abi naujos parinktys iš pradžių "
            L"išjungtos.\r\n\r\nGREITIS, PAUZĖ IR AUTOMATINIS PALEIDIMAS IŠ NAUJO\r\nGreitis yra 0–240 "
            L"kartų/s ir nepriklauso nuo ekrano atnaujinimo; 0 sustabdo raidą. Pauzė ir Tęsti išlaiko "
            L"pasaulį. Pradėti iš naujo pradeda pasirinktą režimą. Pasirenkamas automatinis paleidimas iš "
            L"naujo atpažįsta nekintamas ir tiksliai pasikartojančias matomas fazes, taip pat "
            L"osciliatorius. Lyginamos kartos, ne sekundės; nematomos sritys neįtraukiamos. Asinchroniniai "
            L"rezultatai gali šiek tiek uždelsti paleidimą. Numatyta: 8 px žingsnis, 20 kartų/s, "
            L"atsitiktinė gyvų ląstelių spalva ir automatinis paleidimas iš naujo įjungti. Tinklelis pagal "
            L"numatytuosius nustatymus išjungtas. Pasiekiamas greitis priklauso nuo našumo ir langelių "
            L"skaičiaus. Automatinis paleidimas iš naujo lygina įjungtų ekranų sritis; tarpai tarp jų "
            L"vystosi toliau, bet į palyginimą neįtraukiami.\r\n\r\nAtkurti reikšmes\r\nAtkūrimas nustato "
            L"rodomą langelio dydį į 8 px su tinkleliu arba be jo (žingsnis 9 arba 8 px), greitį į 20 "
            L"kartų/s, tankį į 25 % ir tris numatytąsias spalvas. Kitos parinktys išsaugomos; nebetelpanti "
            L"konfigūracija pakeičiama mišiniu. Nauja scena sukuriama tik pasikeitus žingsniui arba "
            L"tankiui triukšmo režimu.\r\n\r\nWINDOWS EKRANO UŽSKLANDA\r\nGameOfLife.scr naudoja visus "
            L"ekranus ir atskiras nuo EXE nuostatas. Peržiūra paleidžia viso ekrano animaciją palikdama "
            L"nuostatas atviras. Maža Windows peržiūra sumažina visą pasaulį. Gerai išsaugo; Atšaukti arba "
            L"Esc atmeta pakeitimus. Pelės judesys ar klavišas uždaro viso ekrano užsklandą. MP4 įrašymas "
            L"galimas EXE.\r\n\r\nLANGŲ PADĖTIS IR BŪSENA\r\nUždarant atskirai išsaugomos pagrindinio ir "
            L"Apie langų padėtys; Žinyno atveju taip pat dydis ir įprasta arba išdidinta būsena prieš "
            L"sumažinimą. Tai nepriklauso nuo programos nuostatų patvirtinimo. Baigiant programą uždaromi "
            L"ir Žinyno bei Apie langai.\r\n\r\nATVAIZDAVIMAS IR KONFIGŪRACIJŲ LICENCIJOS\r\nRaidą ir "
            L"matomų būsenų palyginimą atlieka GPU Direct3D 11 šešėliavimo programos; nepavykus aparatinei "
            L"inicijacijai galima programinė atvaizdavimo priemonė. Kiekvienas ekranas naudoja patikrintą "
            L"kadrų laiko valdymą savo dažniu. MP4 reikia Media Foundation ir H.264 koduotuvo. "
            L"Konfigūracijos yra iš LifeWiki (GFDL 1.2 ar naujesnė) ir Alan Hensel viešojo naudojimo "
            L"rinkinių. Programos kodas yra MIT; katalogo pranešimai ir licencijos atskiri."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Langelio dydis: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Greitis: %u kartų/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Pradinis tankis: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Paleisti sceną iš naujo" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Gyvų langelių spalva…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Fono spalva…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Pasirinkti ekranai turi bendrą pasaulį. Tuščios juostos pašalinamos; vidinės skylės lieka."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animacija vyksta…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animacija pristabdyta."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Nepavyko inicijuoti Direct3D atvaizdavimo modulio."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Įjungti peržiūrą"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Išjungti peržiūrą"
        },
        LocalizedText{ TXT_MONITOR,
            L"Monitorius"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Skiriamoji geba"
        },
        LocalizedText{ TXT_POSITION,
            L"Padėtis"
        },
        LocalizedText{ TXT_PRIMARY,
            L"pagrindinis"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Monitoriaus modelis"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Atnaujinimo dažnis"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bitų gylis"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Spalvų formatas"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Spalvų erdvė"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bitų/kanalą"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bitų/pikselį"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Animacijos monitorius"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Parengta"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Rodyti tinklelį"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Tinklelio spalva…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Automatiškai pradėti iš naujo nusistovėjusią ar pasikartojančią matomą sceną"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Tik žinomos konfigūracijos"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Pradėti įrašymą…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Baigti įrašymą"
        },
        LocalizedText{ TXT_RECORDING,
            L"Vyksta MP4 įrašymas…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Įrašas išsaugotas."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Nepavyko pradėti MP4 įrašymo."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Uždarius programą bus sustabdytas vykstantis įrašymas."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Įrašymo nuostatos"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Skiriamoji geba:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Kadrų dažnis:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Pakeitimai bus taikomi kitam MP4 įrašui."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Tinkamų konfigūracijų mišinys"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Pasirinkta konfigūracija nebetelpa. Pasirinktas tinkamas mišinys."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Nepavyko įkelti žinomų konfigūracijų katalogo."
        },
    }),
    DefineLanguage(LANG_LV, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Nejauša fona krāsa katrā ainas pārstartēšanā" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Nejauša režģa krāsa katrā ainas pārstartēšanā" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Windows ekrānsaudzētājs…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Nevar atvērt Windows ekrānsaudzētāja iestatījumus."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Atiestatīt vērtības" },
        LocalizedText{ TXT_SNAPSHOT, L"Momentuzņēmums…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"BMP/GIF/JPEG/PNG/TIFF/WebP attēls ir saglabāts." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Neizdevās saglabāt BMP/GIF/JPEG/PNG/TIFF/WebP attēlu." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Animācijas laikā bloķēt ekrānsaudzētāju" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Nejauša dzīvo šūnu krāsa katrā ainas restartēšanā"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Notiek ekrānsaudzētāja instalēšana…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Notiek ekrānsaudzētāja atinstalēšana…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Instalēt ekrānsaudzētāju" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Atinstalēt ekrānsaudzētāju" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Ekrānsaudzētājs netika instalēts." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Ekrānsaudzētājs ir instalēts." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Ekrānsaudzētājs ir atinstalēts." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Neizdevās atinstalēt ekrānsaudzētāju. Aizveriet to un tā priekšskatījumu un mēģiniet vēlreiz."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Aizveriet GameOfLife iestatījumu logu un atkārtojiet atinstalēšanu."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Aizveriet Windows ekrānsaudzētāja iestatījumu logu un atkārtojiet atinstalēšanu."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Aizveriet ekrānsaudzētāju vai pilnekrāna priekšskatījumu ar Esc vai peles kustību un "
            L"atkārtojiet atinstalēšanu."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Latviešu"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — vadība"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"GameOfLife iestatījumi"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Valoda:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Atcelt"
        },
        LocalizedText{ TXT_EXIT,
            L"Iziet"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pauzēt"
        },
        LocalizedText{ TXT_RESUME,
            L"Turpināt"
        },
        LocalizedText{ TXT_HELP,
            L"Palīdzība"
        },
        LocalizedText{ TXT_ABOUT,
            L"Par programmu"
        },
        LocalizedText{ TXT_CLOSE,
            L"Aizvērt"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Atvērt tīmekļa vietni %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Nevar atvērt vietni noklusējuma pārlūkā."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Neizdevās kopēt URL starpliktuvē."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Neizdevās kopēt informāciju starpliktuvē."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Konveja dzīvības spēle kopīgā pasaulē vairākos ekrānos."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Versija:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Mērķa platforma:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Tīmekļa vietne:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Atvērt noklusējuma pārlūkprogrammā"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Kopēt &adresi"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Kopēt &informāciju"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Licences resurss nav pieejams."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nNOTEIKUMI\r\nKonveja dzīvības spēle izmanto B3/S23. Mirusi šūna atdzīvojas "
            L"ar tieši trim dzīviem kaimiņiem; dzīva izdzīvo ar diviem vai trim. Astoņi kaimiņi ietver "
            L"diagonāles. Visas šūnas mainās vienlaikus. Pretējās malas savienojas: kreisā ar labo, "
            L"augšējā ar apakšējo.\r\n\r\nEKRĀNI UN KOPĪGĀ PASAULE\r\nEXE izvēles rūtiņas ieslēdz ekrānus; "
            L"iestatījumi attiecas uz kopīgo pasauli. Viens ieslēgts ekrāns satur visu pasauli. Daļējā "
            L"atlasē pilnībā tukšas rindas un kolonnas tiek izņemtas: kreisais un labais ekrāns "
            L"savienojas, izslēdzot vidējo. Neizņemamie iekšējie caurumi paliek simulācijā. Visu ekrānu "
            L"izvēle vai SCR saglabā darbvirsmu aptverošo taisnstūri ar neredzamām atstarpēm. Katrs ekrāns "
            L"rāda savu tās pašas simulācijas daļu.\r\n\r\nSĀKUMSTĀVOKLIS UN RAKSTI\r\nNoklusējuma sākums "
            L"ir nejaušs troksnis ar 25 % dzīvu šūnu. Sākuma blīvums 0–100 % tiek lietots nākamajā "
            L"atsākšanā. Tikai zināmi raksti izmanto 4 106 iekļautus rakstus bez trokšņa un atspējo "
            L"blīvumu. Izvēlieties sajaukumu vai nosaukumu; izmēri norādīti šūnās. Meklēšanai rakstiet "
            L"nosaukumu. Tiek piedāvāti tikai pilnībā ietilpstoši raksti. Mazi pārbaudīti raksti "
            L"atkārtojas atsevišķās kopijās, lieli vai sarežģīti sākas vienreiz centrā. Samazinot pasauli, "
            L"pārāk lielu izvēli var aizstāt ar sajaukumu. Režīma vai raksta maiņa izveido jaunu ainu. "
            L"Atsākšana saglabā izvēli; katalogs darbojas bezsaistē.\r\n\r\nŠŪNAS, REŽĢIS UN KRĀSAS\r\nBez "
            L"režģa šūnas izmērs ir 1–64 px. Režģis esošajā solī pievieno 1 px malu: rādītā vērtība un "
            L"slīdnis samazinās par vienu, izmantojams ir 1–63. Izslēgšana atjauno vērtību. Slīdnis "
            L"saglabā pilnu diapazonu un atlec no nepieejamā gala; rūtiņa paliek aktīva. Pārslēgšana "
            L"saglabā ainu, izņemot ieslēgšanu pie 1 px: solis kļūst 2 px un sākas jauna aina. Izmēra vai "
            L"ekrānu maiņa arī sāk no jauna. Ļoti lielai pasaulei var vajadzēt lielāku minimumu. Šūnu, "
            L"fona un režģa krāsas mainās atsevišķi bez atsākšanas. Dzīvo šūnu nejaušā krāsa tiek izvēlēta "
            L"katrā manuālā vai automātiskā ainas atsākšanā. Saglabātā krāsa netiek pārrakstīta un "
            L"atgriežas, izslēdzot šo opciju. To pašu darbību var atsevišķi ieslēgt fonam un režģim; abas "
            L"jaunās opcijas sākotnēji ir izslēgtas.\r\n\r\nĀTRUMS, PAUZE UN AUTOMĀTISKA "
            L"ATSĀKŠANA\r\nĀtrums ir 0–240 paaudzes/s neatkarīgi no atsvaidzes; 0 aptur attīstību. Pauze "
            L"un Turpināt saglabā pasauli. Sākt no jauna atsāk izvēlētajā režīmā. Izvēles automātiskā "
            L"atsākšana atpazīst statiskas un precīzi atkārtotas redzamās fāzes, arī oscilatorus. Tā "
            L"salīdzina paaudzes, nevis sekundes; neredzamās vietas netiek ieskaitītas. Asinhroni "
            L"rezultāti var nedaudz aizkavēt atsākšanu. Noklusējums: 8 px solis, 20 paaudzes/s, dzīvo šūnu "
            L"nejauša krāsa un automātiska atsākšana ieslēgta. Režģis pēc noklusējuma ir izslēgts. "
            L"Sasniegtais ātrums ir atkarīgs no veiktspējas un šūnu skaita. Automātiskā atsākšana "
            L"salīdzina ieslēgto ekrānu apgabalus; atstarpes turpina attīstīties, bet salīdzinājumā netiek "
            L"iekļautas.\r\n\r\nAtiestatīt vērtības\r\nAtiestatīšana nosaka parādīto šūnas izmēru 8 px ar "
            L"režģi vai bez tā (solis 9 vai 8 px), ātrumu 20 paaudzes/s, blīvumu 25 % un atjauno trīs "
            L"noklusējuma krāsas. Pārējās izvēles saglabājas; rakstu, kas vairs neietilpst, aizstāj "
            L"sajaukums. Jauna aina tiek izveidota tikai tad, ja mainās solis vai blīvums trokšņa "
            L"režīmā.\r\n\r\nATSEVIŠĶA LIETOTNE UN MP4 IERAKSTS\r\nEXE pastāvīgi saglabā iestatījumus un "
            L"ieraksta pirmo aktīvo ekrānu MP4. Ieteiktā mape ir Video, citādi Dokumenti. Viewport lieto "
            L"ekrāna izmērus un atsvaidzi līdz 60 kadriem/s. TV piedāvā 1920 × 1080, 1440 × 1080 vai 1280 "
            L"× 720, 16:9, ar 50, 25, 59,94 (60000/1001) vai 29,97 (30000/1001) kadriem/s. Proporcijas "
            L"saglabājas; TV lieto progresīvu ierobežota diapazona BT.709 un 4:2:0. Atsevišķo iestatījumu "
            L"logu var minimizēt. Labi saglabā nākamajam ierakstam; Atcelt vai Esc atmet neapstiprinātās "
            L"izmaiņas. Ierakstāmo ekrānu nevar izslēgt; pārējās izvades var mainīt. Iziešanai ieraksta "
            L"laikā vajadzīgs apstiprinājums. Aktīvā animācijā atstarpe pārslēdz pauzi, F9: Sākt "
            L"ierakstīšanu; F10: Beigt ierakstīšanu. Kursors pazūd pēc 1 sekundes bezdarbības un parādās "
            L"kustoties. Tab/Shift+Tab pāriet starp vadīklām, Alt aktivizē pasvītrotās komandas. Esc "
            L"aizver Palīdzība/Par vai iziet galvenajā logā.\r\n\r\nMOMENTUZŅĒMUMS UN EKRĀNSAUDZĒTĀJA "
            L"PĀRVALDĪBA EXE\r\nMomentuzņēmums saglabā BMP/GIF/JPEG/PNG/TIFF/WebP no ierakstāmā ekrāna vai "
            L"citādi no pirmā aktīvā "
            L"ekrāna tā izšķirtspējā, neatsākot ainu. Tiek piedāvāta mape Attēli, citādi Dokumenti. "
            L"Ekrānsaudzētāja bloķēšana animācijas laikā neļauj tam ieslēgties, kamēr animācija ir redzama "
            L"un nav pauzē. Nulles ātrums nav pauze. Instalēšana no EXE izpako pievienoto SCR un izvēlas "
            L"to kā Windows ekrānsaudzētāju. Instalēšanai un atinstalēšanai var būt vajadzīga "
            L"administratora atļauja; statusa josla rāda darbību līdz tās beigām. Ja noņemšana ir bloķēta, "
            L"aizveriet darbojošos ekrānsaudzētāju, tā iestatījumus un Windows "
            L"priekšskatījumu.\r\n\r\nWINDOWS EKRĀNSAUDZĒTĀJS\r\nGameOfLife.scr izmanto visus ekrānus ar "
            L"no EXE nodalītiem iestatījumiem. Priekšskatījums sāk pilnekrāna animāciju ar atvērtiem "
            L"iestatījumiem. Mazais Windows priekšskatījums samazina visu pasauli. Labi saglabā; Atcelt "
            L"vai Esc atmet izmaiņas. Peles kustība vai taustiņš aizver pilnekrāna ekrānsaudzētāju. MP4 "
            L"ieraksts pieejams EXE.\r\n\r\nLOGU NOVIETOJUMS UN STĀVOKLIS\r\nAizverot atsevišķi saglabājas "
            L"galvenā loga un Par loga novietojums; Palīdzībai arī izmērs un parastais vai maksimizētais "
            L"stāvoklis pirms minimizēšanas. Tas nav atkarīgs no lietotnes iestatījumu apstiprināšanas. "
            L"Lietotnes aizvēršana aizver arī Palīdzību un Par.\r\n\r\nATVEIDOŠANA UN RAKSTU "
            L"LICENCES\r\nAttīstība un redzamo stāvokļu salīdzināšana izmanto Direct3D 11 ēnotājus GPU; ja "
            L"aparatūras inicializācija neizdodas, pieejama programmatūras atveidošana. Katrs ekrāns lieto "
            L"pārbaudīto kadru laika vadību savā frekvencē. MP4 vajag Media Foundation un H.264 kodētāju. "
            L"Raksti nāk no LifeWiki (GFDL 1.2 vai jaunāka) un Alana Hensela publiskā īpašuma kolekcijām. "
            L"Programmas kods ir MIT; kataloga paziņojumi un licences ir atsevišķi.\r\n\r\nWindows "
            L"ekrānsaudzētājs… atver sistēmas ekrānsaudzētāja iestatījumus."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nNOTEIKUMI\r\nKonveja dzīvības spēle izmanto B3/S23. Mirusi šūna atdzīvojas "
            L"ar tieši trim dzīviem kaimiņiem; dzīva izdzīvo ar diviem vai trim. Astoņi kaimiņi ietver "
            L"diagonāles. Visas šūnas mainās vienlaikus. Pretējās malas savienojas: kreisā ar labo, "
            L"augšējā ar apakšējo.\r\n\r\nEKRĀNI UN KOPĪGĀ PASAULE\r\nEXE izvēles rūtiņas ieslēdz ekrānus; "
            L"iestatījumi attiecas uz kopīgo pasauli. Viens ieslēgts ekrāns satur visu pasauli. Daļējā "
            L"atlasē pilnībā tukšas rindas un kolonnas tiek izņemtas: kreisais un labais ekrāns "
            L"savienojas, izslēdzot vidējo. Neizņemamie iekšējie caurumi paliek simulācijā. Visu ekrānu "
            L"izvēle vai SCR saglabā darbvirsmu aptverošo taisnstūri ar neredzamām atstarpēm. Katrs ekrāns "
            L"rāda savu tās pašas simulācijas daļu.\r\n\r\nSĀKUMSTĀVOKLIS UN RAKSTI\r\nNoklusējuma sākums "
            L"ir nejaušs troksnis ar 25 % dzīvu šūnu. Sākuma blīvums 0–100 % tiek lietots nākamajā "
            L"atsākšanā. Tikai zināmi raksti izmanto 4 106 iekļautus rakstus bez trokšņa un atspējo "
            L"blīvumu. Izvēlieties sajaukumu vai nosaukumu; izmēri norādīti šūnās. Meklēšanai rakstiet "
            L"nosaukumu. Tiek piedāvāti tikai pilnībā ietilpstoši raksti. Mazi pārbaudīti raksti "
            L"atkārtojas atsevišķās kopijās, lieli vai sarežģīti sākas vienreiz centrā. Samazinot pasauli, "
            L"pārāk lielu izvēli var aizstāt ar sajaukumu. Režīma vai raksta maiņa izveido jaunu ainu. "
            L"Atsākšana saglabā izvēli; katalogs darbojas bezsaistē.\r\n\r\nŠŪNAS, REŽĢIS UN KRĀSAS\r\nBez "
            L"režģa šūnas izmērs ir 1–64 px. Režģis esošajā solī pievieno 1 px malu: rādītā vērtība un "
            L"slīdnis samazinās par vienu, izmantojams ir 1–63. Izslēgšana atjauno vērtību. Slīdnis "
            L"saglabā pilnu diapazonu un atlec no nepieejamā gala; rūtiņa paliek aktīva. Pārslēgšana "
            L"saglabā ainu, izņemot ieslēgšanu pie 1 px: solis kļūst 2 px un sākas jauna aina. Izmēra vai "
            L"ekrānu maiņa arī sāk no jauna. Ļoti lielai pasaulei var vajadzēt lielāku minimumu. Šūnu, "
            L"fona un režģa krāsas mainās atsevišķi bez atsākšanas. Dzīvo šūnu nejaušā krāsa tiek izvēlēta "
            L"katrā manuālā vai automātiskā ainas atsākšanā. Saglabātā krāsa netiek pārrakstīta un "
            L"atgriežas, izslēdzot šo opciju. To pašu darbību var atsevišķi ieslēgt fonam un režģim; abas "
            L"jaunās opcijas sākotnēji ir izslēgtas.\r\n\r\nĀTRUMS, PAUZE UN AUTOMĀTISKA "
            L"ATSĀKŠANA\r\nĀtrums ir 0–240 paaudzes/s neatkarīgi no atsvaidzes; 0 aptur attīstību. Pauze "
            L"un Turpināt saglabā pasauli. Sākt no jauna atsāk izvēlētajā režīmā. Izvēles automātiskā "
            L"atsākšana atpazīst statiskas un precīzi atkārtotas redzamās fāzes, arī oscilatorus. Tā "
            L"salīdzina paaudzes, nevis sekundes; neredzamās vietas netiek ieskaitītas. Asinhroni "
            L"rezultāti var nedaudz aizkavēt atsākšanu. Noklusējums: 8 px solis, 20 paaudzes/s, dzīvo šūnu "
            L"nejauša krāsa un automātiska atsākšana ieslēgta. Režģis pēc noklusējuma ir izslēgts. "
            L"Sasniegtais ātrums ir atkarīgs no veiktspējas un šūnu skaita. Automātiskā atsākšana "
            L"salīdzina ieslēgto ekrānu apgabalus; atstarpes turpina attīstīties, bet salīdzinājumā netiek "
            L"iekļautas.\r\n\r\nAtiestatīt vērtības\r\nAtiestatīšana nosaka parādīto šūnas izmēru 8 px ar "
            L"režģi vai bez tā (solis 9 vai 8 px), ātrumu 20 paaudzes/s, blīvumu 25 % un atjauno trīs "
            L"noklusējuma krāsas. Pārējās izvēles saglabājas; rakstu, kas vairs neietilpst, aizstāj "
            L"sajaukums. Jauna aina tiek izveidota tikai tad, ja mainās solis vai blīvums trokšņa "
            L"režīmā.\r\n\r\nWINDOWS EKRĀNSAUDZĒTĀJS\r\nGameOfLife.scr izmanto visus ekrānus ar no EXE "
            L"nodalītiem iestatījumiem. Priekšskatījums sāk pilnekrāna animāciju ar atvērtiem "
            L"iestatījumiem. Mazais Windows priekšskatījums samazina visu pasauli. Labi saglabā; Atcelt "
            L"vai Esc atmet izmaiņas. Peles kustība vai taustiņš aizver pilnekrāna ekrānsaudzētāju. MP4 "
            L"ieraksts pieejams EXE.\r\n\r\nLOGU NOVIETOJUMS UN STĀVOKLIS\r\nAizverot atsevišķi saglabājas "
            L"galvenā loga un Par loga novietojums; Palīdzībai arī izmērs un parastais vai maksimizētais "
            L"stāvoklis pirms minimizēšanas. Tas nav atkarīgs no lietotnes iestatījumu apstiprināšanas. "
            L"Lietotnes aizvēršana aizver arī Palīdzību un Par.\r\n\r\nATVEIDOŠANA UN RAKSTU "
            L"LICENCES\r\nAttīstība un redzamo stāvokļu salīdzināšana izmanto Direct3D 11 ēnotājus GPU; ja "
            L"aparatūras inicializācija neizdodas, pieejama programmatūras atveidošana. Katrs ekrāns lieto "
            L"pārbaudīto kadru laika vadību savā frekvencē. MP4 vajag Media Foundation un H.264 kodētāju. "
            L"Raksti nāk no LifeWiki (GFDL 1.2 vai jaunāka) un Alana Hensela publiskā īpašuma kolekcijām. "
            L"Programmas kods ir MIT; kataloga paziņojumi un licences ir atsevišķi."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Šūnas izmērs: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Ātrums: %u paaudzes/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Sākuma blīvums: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Sākt ainu no jauna" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Dzīvo šūnu krāsa…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Fona krāsa…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Atlasītie ekrāni koplieto pasauli. Tukšās joslas tiek noņemtas; iekšējie caurumi paliek."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animācija darbojas…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animācija ir pauzēta."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Neizdevās inicializēt Direct3D renderētāju."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Ieslēgt priekšskatījumu"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Izslēgt priekšskatījumu"
        },
        LocalizedText{ TXT_MONITOR,
            L"Monitors"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Izšķirtspēja"
        },
        LocalizedText{ TXT_POSITION,
            L"Pozīcija"
        },
        LocalizedText{ TXT_PRIMARY,
            L"galvenais"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Monitora modelis"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Atsvaidzināšanas frekvence"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bitu dziļums"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Krāsu formāts"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Krāstelpa"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u biti/kanālā"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u biti/pikselī"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Animācijas monitors"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Gatavs"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Rādīt režģi"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Režģa krāsa…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Automātiski atsākt nemainīgu vai atkārtotu redzamo ainu"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Tikai zināmi raksti"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Sākt ierakstīšanu…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Beigt ierakstīšanu"
        },
        LocalizedText{ TXT_RECORDING,
            L"Notiek MP4 ierakstīšana…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Ieraksts ir saglabāts."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Neizdevās sākt MP4 ierakstīšanu."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Aizverot lietotni, tiks pārtraukts pašreizējais ieraksts."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Ieraksta iestatījumi"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Izšķirtspēja:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Kadru ātrums:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Izmaiņas attieksies uz nākamo MP4 ierakstu."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Piemērotu rakstu sajaukums"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Atlasītais raksts vairs neietilpst. Izvēlēts piemērots sajaukums."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Neizdevās ielādēt zināmo rakstu katalogu."
        },
    }),
    DefineLanguage(LANG_HU, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Véletlen háttérszín a jelenet minden újraindításakor" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Véletlen rácsszín a jelenet minden újraindításakor" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Windows-képernyőkímélő…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Nem sikerült megnyitni a Windows képernyőkímélő beállításait."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Értékek visszaállítása" },
        LocalizedText{ TXT_SNAPSHOT, L"Pillanatkép…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"A BMP/GIF/JPEG/PNG/TIFF/WebP-kép mentve." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"A BMP/GIF/JPEG/PNG/TIFF/WebP-kép mentése sikertelen." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Képernyőkímélő tiltása animáció közben" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Élő cellák véletlen színe a jelenet minden újraindításakor"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"A képernyőkímélő telepítése folyamatban…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"A képernyőkímélő eltávolítása folyamatban…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Képernyőkímélő telepítése" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Képernyőkímélő eltávolítása" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"A képernyőkímélő nem lett telepítve." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"A képernyőkímélő telepítve." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"A képernyőkímélő eltávolítva." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"A képernyőkímélő nem távolítható el. Zárja be a képernyőkímélőt és az előnézetét, majd "
            L"próbálja újra."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Zárja be a GameOfLife beállítási ablakát, majd próbálja újra az eltávolítást."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zárja be a Windows képernyőkímélő-beállításait, majd próbálja újra az eltávolítást."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Lépjen ki a képernyőkímélőből vagy a teljes képernyős előnézetből az Esc billentyűvel vagy az "
            L"egér mozgatásával, majd próbálja újra."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Magyar"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — vezérlés"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"GameOfLife beállításai"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Nyelv:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Mégse"
        },
        LocalizedText{ TXT_EXIT,
            L"Kilépés"
        },
        LocalizedText{ TXT_PAUSE,
            L"Szünet"
        },
        LocalizedText{ TXT_RESUME,
            L"Folytatás"
        },
        LocalizedText{ TXT_HELP,
            L"Súgó"
        },
        LocalizedText{ TXT_ABOUT,
            L"Névjegy"
        },
        LocalizedText{ TXT_CLOSE,
            L"Bezárás"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Webhely megnyitása: %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"A webhely nem nyitható meg az alapértelmezett böngészőben."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Az URL nem másolható a vágólapra."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Az információ nem másolható a vágólapra."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conway életjátéka a kijelzők közös világában."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Verzió:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Célplatform:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Webhely:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Megnyitás az alapértelmezett böngészőben"
        },
        LocalizedText{ TXT_COPY_URL,
            L"&Cím másolása"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"&Információ másolása"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"A licenc erőforrása nem érhető el."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nSZABÁLYOK\r\nConway életjátéka a B3/S23 szabályt követi. A halott cella "
            L"pontosan három élő szomszédnál születik meg; az élő kettőnél vagy háromnál marad életben. A "
            L"nyolc szomszéd az átlósakat is tartalmazza. Minden cella egyszerre változik. A szemközti "
            L"szélek összekapcsolódnak: bal a jobbal, felső az alsóval.\r\n\r\nKIJELZŐK ÉS KÖZÖS "
            L"VILÁG\r\nAz EXE jelölőnégyzetei engedélyezik a kijelzőket; a beállítások a közös világra "
            L"vonatkoznak. Egyetlen aktív kijelző az egész világot tartalmazza. Részleges kijelölésnél a "
            L"teljesen üres sorok és oszlopok eltűnnek: a középső kikapcsolásakor a bal és jobb kijelző "
            L"összeér. Az el nem távolítható belső lyukak a szimuláció részei maradnak. Az összes kijelző "
            L"kiválasztása és az SCR megőrzi az asztal körülíró téglalapját a láthatatlan hézagokkal "
            L"együtt. Minden kijelző ugyanazon játék saját részét mutatja.\r\n\r\nKEZDŐÁLLAPOT ÉS "
            L"MINTÁK\r\nAz alapállapot véletlen zaj 25 % élő cellával. A 0–100 % kezdeti sűrűség a "
            L"következő újraindításkor érvényesül. A Csak ismert minták 4 106 beépített mintát használ zaj "
            L"nélkül, és letiltja a sűrűséget. Válasszon keveréket vagy nevet; a méret cellákban értendő. "
            L"Gépeléssel kereshet. Csak a teljesen elférő minták szerepelnek. A kis ellenőrzött minták "
            L"külön másolatokban ismétlődnek, a nagyok vagy összetettek egyszer középen jelennek meg. "
            L"Kisebb világban a már nem férő választást keverék válthatja fel. Mód- vagy mintaváltás új "
            L"jelenetet indít. Az újraindítás megőrzi a választást; a katalógus internet nélkül "
            L"működik.\r\n\r\nCELLAMÉRET, RÁCS ÉS SZÍNEK\r\nRács nélkül a cellaméret 1–64 px. A rács 1 px "
            L"szegélyt ad a meglévő térközön belül: a kijelzett érték és a csúszka eggyel csökken, 1–63 "
            L"használható. Kikapcsolva az érték visszaáll. A csúszka teljes tartománya megmarad, a tiltott "
            L"végpontról visszaugrik; a jelölőnégyzet aktív marad. A kapcsolás megőrzi a jelenetet, kivéve "
            L"1 px-nél bekapcsolva: a térköz 2 px lesz és új jelenet indul. Cellaméret vagy kijelzők "
            L"változtatása is újrakezd. Nagyon nagy világ magasabb minimumot igényelhet. A cellák, háttér "
            L"és rács színe külön, újraindítás nélkül állítható. Az élő cellák véletlen színe a jelenet "
            L"minden kézi vagy automatikus újraindításakor új színt választ. A mentett szín megmarad, és a "
            L"lehetőség kikapcsolásakor visszaáll. Ugyanez a működés külön engedélyezhető a háttérhez és a "
            L"rácshoz; mindkét új lehetőség alapértelmezetten ki van kapcsolva.\r\n\r\nSEBESSÉG, SZÜNET ÉS "
            L"AUTOMATIKUS ÚJRAINDÍTÁS\r\nA sebesség 0–240 generáció/s, a képfrissítéstől függetlenül; 0 "
            L"megállítja a fejlődést. Szünet és Folytatás megőrzi a világot. Az Újraindítás a kiválasztott "
            L"módban kezd újra. Az opcionális automatikus újraindítás állandó és pontosan ismétlődő "
            L"látható fázisokat, így oszcillátorokat is felismer. Generációkat hasonlít, nem "
            L"másodperceket; a láthatatlan részek kimaradnak. Az aszinkron eredmények kissé késleltethetik "
            L"az újraindítást. Alapértékek: 8 px térköz, 20 generáció/s, az élő sejtek véletlen színe és "
            L"automatikus újraindítás bekapcsolva. A rács alapértelmezés szerint ki van kapcsolva. Az "
            L"elért sebesség a teljesítménytől és a cellák számától függ. Az automatikus újraindítás az "
            L"engedélyezett kijelzők területét hasonlítja össze; a köztük levő hézagok tovább fejlődnek, "
            L"de kimaradnak az összehasonlításból.\r\n\r\nÉrtékek visszaállítása\r\nA visszaállítás a "
            L"kijelzett cellaméretet ráccsal és anélkül is 8 px-re állítja (térköz 9 vagy 8 px), a "
            L"sebességet 20 generáció/s-ra, a sűrűséget 25 %-ra, és visszaállítja a három alapértelmezett "
            L"színt. A többi választás megmarad; a már nem elférő mintát keverék váltja fel. Új jelenet "
            L"csak a térköz változásakor vagy zajmódban a sűrűség változásakor indul.\r\n\r\nÖNÁLLÓ "
            L"ALKALMAZÁS ÉS MP4-FELVÉTEL\r\nAz EXE folyamatosan menti a beállításokat, és az első aktív "
            L"kijelzőt rögzíti MP4-be. A javasolt mappa Videók, ennek hiányában Dokumentumok. Viewport a "
            L"kijelző méretét és legfeljebb 60 képkocka/s frissítését használja. TV: 1920 × 1080, 1440 × "
            L"1080 vagy 1280 × 720, 16:9, 50, 25, 59,94 (60000/1001) vagy 29,97 (30000/1001) képkocka/s. A "
            L"képarány megmarad; TV progresszív, korlátozott tartományú BT.709 és 4:2:0. A külön "
            L"beállítóablak kis méretűre állítható. OK a következő felvételhez ment; Mégse vagy Esc elveti "
            L"a függő módosításokat. A rögzített kijelző nem kapcsolható ki, a többi változtatható. "
            L"Felvétel közbeni kilépés megerősítést kér. Aktív animációnál Szóköz váltja a szünetet, F9: "
            L"Felvétel indítása; F10: Felvétel leállítása. A mutató 1 másodperc tétlenség után eltűnik, "
            L"mozgásra visszatér. Tab/Shift+Tab léptet, Alt az aláhúzott parancsot indítja. Esc bezárja a "
            L"Súgó/Névjegy ablakot, a főablakban kilép.\r\n\r\nPILLANATKÉP ÉS A KÉPERNYŐKÍMÉLŐ KEZELÉSE AZ "
            L"EXE-BEN\r\nA pillanatkép a rögzített kijelzőt, egyébként az első aktív kijelzőt menti "
            L"BMP/GIF/JPEG/PNG/TIFF/WebP-be "
            L"annak felbontásával, a jelenet újraindítása nélkül. A javasolt mappa Képek, ennek hiányában "
            L"Dokumentumok. A képernyőkímélő tiltása animáció közben megakadályozza az indulását, amíg az "
            L"animáció látható és nincs szüneteltetve. A nulla sebesség nem szünet. Az EXE-ből történő "
            L"telepítés kibontja a mellékelt SCR-t és Windows képernyőkímélőként választja ki. A telepítés "
            L"és eltávolítás rendszergazdai jóváhagyást igényelhet; az állapotsor a befejezésig jelzi a "
            L"műveletet. Ha az eltávolítás blokkolva van, zárja be a futó képernyőkímélőt, a beállításait "
            L"és a Windows előnézetét.\r\n\r\nWINDOWS-KÉPERNYŐKÍMÉLŐ\r\nA GameOfLife.scr minden kijelzőt "
            L"használ, az EXE-től külön tárolt beállításokkal. Az előnézet teljes képernyőn fut nyitott "
            L"beállítások mellett. A kis Windows-előnézet az egész világot lekicsinyíti. OK ment, Mégse "
            L"vagy Esc elveti a változtatásokat. Egérmozgás vagy billentyű kilép a teljes képernyős "
            L"képernyőkímélőből. MP4-felvétel az EXE-ben érhető el.\r\n\r\nAZ ABLAKOK HELYE ÉS "
            L"ÁLLAPOTA\r\nBezáráskor külön mentődik a főablak és a Névjegy helye; a Súgónál a méret és a "
            L"kis méretre állítás előtti normál vagy teljes méretű állapot is. Ez független az "
            L"alkalmazásbeállítások jóváhagyásától. Az alkalmazás bezárása a Súgót és a Névjegyet is "
            L"bezárja.\r\n\r\nMEGJELENÍTÉS ÉS MINTALICENCEK\r\nA fejlődés és a látható állapotok "
            L"összehasonlítása Direct3D 11 shaderekkel a GPU-n fut; hardveres inicializálási hiba esetén "
            L"szoftveres megjelenítés használható. Minden kijelző a bevált képkocka-ütemezőt használja "
            L"saját frissítésével. MP4-hez Media Foundation és H.264 kódoló kell. A minták a LifeWikiről "
            L"(GFDL 1.2 vagy újabb) és Alan Hensel közkincs gyűjteményeiből származnak. A programkód "
            L"MIT-licencű; a katalógus külön jogi közleményekkel és licencekkel rendelkezik.\r\n\r\nA "
            L"Windows-képernyőkímélő… megnyitja a rendszer képernyőkímélő-beállításait."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nSZABÁLYOK\r\nConway életjátéka a B3/S23 szabályt követi. A halott cella "
            L"pontosan három élő szomszédnál születik meg; az élő kettőnél vagy háromnál marad életben. A "
            L"nyolc szomszéd az átlósakat is tartalmazza. Minden cella egyszerre változik. A szemközti "
            L"szélek összekapcsolódnak: bal a jobbal, felső az alsóval.\r\n\r\nKIJELZŐK ÉS KÖZÖS "
            L"VILÁG\r\nAz EXE jelölőnégyzetei engedélyezik a kijelzőket; a beállítások a közös világra "
            L"vonatkoznak. Egyetlen aktív kijelző az egész világot tartalmazza. Részleges kijelölésnél a "
            L"teljesen üres sorok és oszlopok eltűnnek: a középső kikapcsolásakor a bal és jobb kijelző "
            L"összeér. Az el nem távolítható belső lyukak a szimuláció részei maradnak. Az összes kijelző "
            L"kiválasztása és az SCR megőrzi az asztal körülíró téglalapját a láthatatlan hézagokkal "
            L"együtt. Minden kijelző ugyanazon játék saját részét mutatja.\r\n\r\nKEZDŐÁLLAPOT ÉS "
            L"MINTÁK\r\nAz alapállapot véletlen zaj 25 % élő cellával. A 0–100 % kezdeti sűrűség a "
            L"következő újraindításkor érvényesül. A Csak ismert minták 4 106 beépített mintát használ zaj "
            L"nélkül, és letiltja a sűrűséget. Válasszon keveréket vagy nevet; a méret cellákban értendő. "
            L"Gépeléssel kereshet. Csak a teljesen elférő minták szerepelnek. A kis ellenőrzött minták "
            L"külön másolatokban ismétlődnek, a nagyok vagy összetettek egyszer középen jelennek meg. "
            L"Kisebb világban a már nem férő választást keverék válthatja fel. Mód- vagy mintaváltás új "
            L"jelenetet indít. Az újraindítás megőrzi a választást; a katalógus internet nélkül "
            L"működik.\r\n\r\nCELLAMÉRET, RÁCS ÉS SZÍNEK\r\nRács nélkül a cellaméret 1–64 px. A rács 1 px "
            L"szegélyt ad a meglévő térközön belül: a kijelzett érték és a csúszka eggyel csökken, 1–63 "
            L"használható. Kikapcsolva az érték visszaáll. A csúszka teljes tartománya megmarad, a tiltott "
            L"végpontról visszaugrik; a jelölőnégyzet aktív marad. A kapcsolás megőrzi a jelenetet, kivéve "
            L"1 px-nél bekapcsolva: a térköz 2 px lesz és új jelenet indul. Cellaméret vagy kijelzők "
            L"változtatása is újrakezd. Nagyon nagy világ magasabb minimumot igényelhet. A cellák, háttér "
            L"és rács színe külön, újraindítás nélkül állítható. Az élő cellák véletlen színe a jelenet "
            L"minden kézi vagy automatikus újraindításakor új színt választ. A mentett szín megmarad, és a "
            L"lehetőség kikapcsolásakor visszaáll. Ugyanez a működés külön engedélyezhető a háttérhez és a "
            L"rácshoz; mindkét új lehetőség alapértelmezetten ki van kapcsolva.\r\n\r\nSEBESSÉG, SZÜNET ÉS "
            L"AUTOMATIKUS ÚJRAINDÍTÁS\r\nA sebesség 0–240 generáció/s, a képfrissítéstől függetlenül; 0 "
            L"megállítja a fejlődést. Szünet és Folytatás megőrzi a világot. Az Újraindítás a kiválasztott "
            L"módban kezd újra. Az opcionális automatikus újraindítás állandó és pontosan ismétlődő "
            L"látható fázisokat, így oszcillátorokat is felismer. Generációkat hasonlít, nem "
            L"másodperceket; a láthatatlan részek kimaradnak. Az aszinkron eredmények kissé késleltethetik "
            L"az újraindítást. Alapértékek: 8 px térköz, 20 generáció/s, az élő sejtek véletlen színe és "
            L"automatikus újraindítás bekapcsolva. A rács alapértelmezés szerint ki van kapcsolva. Az "
            L"elért sebesség a teljesítménytől és a cellák számától függ. Az automatikus újraindítás az "
            L"engedélyezett kijelzők területét hasonlítja össze; a köztük levő hézagok tovább fejlődnek, "
            L"de kimaradnak az összehasonlításból.\r\n\r\nÉrtékek visszaállítása\r\nA visszaállítás a "
            L"kijelzett cellaméretet ráccsal és anélkül is 8 px-re állítja (térköz 9 vagy 8 px), a "
            L"sebességet 20 generáció/s-ra, a sűrűséget 25 %-ra, és visszaállítja a három alapértelmezett "
            L"színt. A többi választás megmarad; a már nem elférő mintát keverék váltja fel. Új jelenet "
            L"csak a térköz változásakor vagy zajmódban a sűrűség változásakor "
            L"indul.\r\n\r\nWINDOWS-KÉPERNYŐKÍMÉLŐ\r\nA GameOfLife.scr minden kijelzőt használ, az EXE-től "
            L"külön tárolt beállításokkal. Az előnézet teljes képernyőn fut nyitott beállítások mellett. A "
            L"kis Windows-előnézet az egész világot lekicsinyíti. OK ment, Mégse vagy Esc elveti a "
            L"változtatásokat. Egérmozgás vagy billentyű kilép a teljes képernyős képernyőkímélőből. "
            L"MP4-felvétel az EXE-ben érhető el.\r\n\r\nAZ ABLAKOK HELYE ÉS ÁLLAPOTA\r\nBezáráskor külön "
            L"mentődik a főablak és a Névjegy helye; a Súgónál a méret és a kis méretre állítás előtti "
            L"normál vagy teljes méretű állapot is. Ez független az alkalmazásbeállítások jóváhagyásától. "
            L"Az alkalmazás bezárása a Súgót és a Névjegyet is bezárja.\r\n\r\nMEGJELENÍTÉS ÉS "
            L"MINTALICENCEK\r\nA fejlődés és a látható állapotok összehasonlítása Direct3D 11 shaderekkel "
            L"a GPU-n fut; hardveres inicializálási hiba esetén szoftveres megjelenítés használható. "
            L"Minden kijelző a bevált képkocka-ütemezőt használja saját frissítésével. MP4-hez Media "
            L"Foundation és H.264 kódoló kell. A minták a LifeWikiről (GFDL 1.2 vagy újabb) és Alan Hensel "
            L"közkincs gyűjteményeiből származnak. A programkód MIT-licencű; a katalógus külön jogi "
            L"közleményekkel és licencekkel rendelkezik."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Cellaméret: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Sebesség: %u generáció/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Kezdeti sűrűség: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Jelenet újraindítása" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Élő cellák színe…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Háttérszín…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"A kijelzők közös világot mutatnak. Az üres sávok eltűnnek, a belső lyukak megmaradnak."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Az animáció fut…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Az animáció szünetel."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"A Direct3D megjelenítő inicializálása sikertelen."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Előnézet bekapcsolása"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Előnézet kikapcsolása"
        },
        LocalizedText{ TXT_MONITOR,
            L"Monitor"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Felbontás"
        },
        LocalizedText{ TXT_POSITION,
            L"Pozíció"
        },
        LocalizedText{ TXT_PRIMARY,
            L"elsődleges"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Monitor típusa"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Frissítési gyakoriság"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bitmélység"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Színformátum"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Színtér"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bit/csatorna"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bit/képpont"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Animációs monitor"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Kész"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Rács megjelenítése"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Rácsszín…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Állandó vagy ismétlődő látható jelenet automatikus újraindítása"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Csak ismert minták"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Felvétel indítása…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Felvétel leállítása"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4-felvétel folyamatban…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"A felvétel mentve."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Az MP4-felvétel nem indítható."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Az alkalmazás bezárása leállítja a folyamatban lévő felvételt."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Felvételi beállítások"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Felbontás:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Képkockasebesség:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"A módosítások a következő MP4-felvételre érvényesek."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Megfelelő minták keveréke"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"A kiválasztott minta már nem fér el. Megfelelő keverék lett kiválasztva."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Nem sikerült betölteni az ismert minták katalógusát."
        },
    }),
    DefineLanguage(LANG_MT, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Kulur każwali tal-isfond ma’ kull bidu mill-ġdid tax-xena"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR,
            L"Kulur każwali tal-gradilja ma’ kull bidu mill-ġdid tax-xena" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Screensaver tal-Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Ma setgħux jinfetħu s-settings tal-iscreensaver tal-Windows."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Irrisettja l-valuri" },
        LocalizedText{ TXT_SNAPSHOT, L"Stampa…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"L-immaġni BMP/GIF/JPEG/PNG/TIFF/WebP ġiet issejvjata." },
        LocalizedText{ TXT_SNAPSHOT_FAILED,
            L"Ma setgħetx tiġi ssejvjata l-immaġni BMP/GIF/JPEG/PNG/TIFF/WebP."
        },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Imblokka l-iscreen saver waqt l-animazzjoni" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Kulur każwali għaċ-ċelloli ħajjin kull darba li terġa’ tibda x-xena"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"L-iscreen saver qed jiġi installat…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"L-iscreen saver qed jitneħħa…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Installa l-iscreen saver" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Neħħi l-iscreen saver" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"L-iscreen saver ma ġiex installat." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"L-iscreen saver ġie installat." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"L-iscreen saver tneħħa." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Ma setax jitneħħa l-iscreen saver. Agħlaq l-iscreen saver u l-previżjoni tiegħu u erġa’ pprova."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Agħlaq it-tieqa tal-issettjar ta’ GameOfLife u erġa’ pprova tneħħih."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Agħlaq it-tieqa tal-issettjar tal-iscreen saver ta’ Windows u erġa’ pprova tneħħih."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Agħlaq l-iscreen saver jew il-previżjoni fuq skrin sħiħ b’Esc jew billi ċċaqlaq il-maws u "
            L"erġa’ pprova."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Malti"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — kontrolli"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Issettjar ta’ GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Lingwa:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Ikkanċella"
        },
        LocalizedText{ TXT_EXIT,
            L"Oħroġ"
        },
        LocalizedText{ TXT_PAUSE,
            L"Issospendi"
        },
        LocalizedText{ TXT_RESUME,
            L"Kompli"
        },
        LocalizedText{ TXT_HELP,
            L"Għajnuna"
        },
        LocalizedText{ TXT_ABOUT,
            L"Dwar"
        },
        LocalizedText{ TXT_CLOSE,
            L"Agħlaq"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Iftaħ is-sit web %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Is-sit ma jistax jinfetaħ fil-brawżer predefinit."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Il-URL ma setax jiġi kkupjat fil-clipboard."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"L-informazzjoni ma setgħetx tiġi kkupjata fil-clipboard."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Il-Logħba tal-Ħajja ta' Conway f'dinja waħda maqsuma bejn l-iskrins."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Verżjoni:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Pjattaforma fil-mira:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Sit web:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Iftaħ fil-brawżer default"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Ikkopja l-&indirizz"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Ikkopja l-&informazzjoni"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Ir-riżorsa tal-liċenzja mhijiex disponibbli."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nREGOLI\r\nIl-Logħba tal-Ħajja ta' Conway tuża B3/S23. Ċellola mejta "
            L"titwieled bi eżatt tliet ġirien ħajjin; waħda ħajja tibqa' ħajja b'żewġ jew tliet ġirien. "
            L"It-tmien ġirien jinkludu d-djagonali. Iċ-ċelloli kollha jinbidlu flimkien. It-truf opposti "
            L"jingħaqdu: xellug mal-lemin, fuq ma' isfel.\r\n\r\nSKRINS U DINJA KOMUNI\r\nIl-kaxxi fl-EXE "
            L"jattivaw l-iskrins; is-settings japplikaw għad-dinja komuni. Skrin wieħed attiv fih id-dinja "
            L"kollha. Meta tintgħażel parti mill-arranġament, jitneħħew ringieli u kolonni kompletament "
            L"vojta: ix-xellug u l-lemin jingħaqdu meta jintefa dak tan-nofs. Toqob interni li ma jistgħux "
            L"jitneħħew jibqgħu fis-simulazzjoni. L-għażla tal-iskrins kollha, jew SCR, iżżomm "
            L"ir-rettangolu tad-desktop u l-vojt inviżibbli. Kull skrin juri r-reġjun tiegħu tal-istess "
            L"simulazzjoni.\r\n\r\nSTAT INIZJALI U FOROM\r\nIl-bidu standard huwa storbju każwali b'25 % "
            L"ċelloli ħajjin. Id-densità inizjali 0–100 % tintuża fil-bidu mill-ġdid li jmiss. Forom "
            L"magħrufa biss tuża 4 106 forom inklużi mingħajr storbju u tiddiżattiva d-densità. Agħżel "
            L"taħlita jew isem; id-dimensjonijiet huma f'ċelloli. Ittajpja isem biex tfittex. Jidhru biss "
            L"forom li jidħlu sħaħ. Forom żgħar ivverifikati jirrepetu f'kopji separati, kbar jew "
            L"kumplessi darba fiċ-ċentru. Dinja iżgħar tista' tissostitwixxi għażla kbira wisq b'taħlita. "
            L"Bidla tal-mod jew forma toħloq xena ġdida. Bidu mill-ġdid iżomm l-għażla; il-katalgu jaħdem "
            L"mingħajr internet.\r\n\r\nĊELLOLI, GRADILJA U KULURI\r\nMingħajr gradilja d-daqs huwa 1–64 "
            L"px. Il-gradilja żżid tarf ta' 1 px fl-ispazjar eżistenti: il-valur muri u s-slajder jonqsu "
            L"b'wieħed, b'1–63 disponibbli. Meta tintefa jerġa' lura l-valur. Is-slajder iżomm il-firxa u "
            L"jerġa' lura mit-tarf mhux disponibbli; il-kaxxa tibqa' attiva. Il-bidla żżomm ix-xena ħlief "
            L"meta tixgħel f'1 px: l-ispazjar isir 2 px u tibda xena ġdida. Bidla fid-daqs jew fl-iskrins "
            L"terġa' tibda wkoll. Dinja kbira ħafna tista' teħtieġ minimu ogħla. Il-kuluri taċ-ċelloli, "
            L"sfond u gradilja jinbidlu separatament mingħajr bidu mill-ġdid. Il-kulur każwali taċ-ċelloli "
            L"ħajjin jagħżel kulur ġdid f’kull bidu mill-ġdid manwali jew awtomatiku tax-xena. Il-kulur "
            L"salvat jinżamm u jerġa’ jidher meta tiddiżattiva din l-għażla. L-istess imġiba tista’ "
            L"tinxtegħel separatament għall-isfond u l-gradilja; iż-żewġ għażliet ġodda huma mitfija "
            L"awtomatikament.\r\n\r\nVELOĊITÀ, PAWŻA U BIDU MILL-ĠDID AWTOMATIKU\r\nIl-veloċità hija 0–240 "
            L"ġenerazzjonijiet/s, indipendenti mir-rata tal-iskrin; 0 iwaqqaf l-evoluzzjoni. Pawża u "
            L"Kompli jżommu d-dinja. Ibda mill-ġdid jerġa' jibda fil-mod magħżul. Il-bidu mill-ġdid "
            L"awtomatiku fakultattiv isib fażijiet viżibbli statiċi jew ripetuti eżatt, inklużi "
            L"oxxillaturi. Iqabbel ġenerazzjonijiet, mhux sekondi; jeskludi żoni inviżibbli. Riżultati "
            L"asinkroni jistgħu jdewmu ftit il-bidu. Valuri standard: spazjar 8 px, 20 ġenerazzjonijiet/s, "
            L"kulur każwali taċ-ċelloli ħajjin u bidu awtomatiku mixgħula. Il-gradilja hija mitfija b’mod "
            L"awtomatiku. Il-veloċità milħuqa tiddependi mill-prestazzjoni u mill-għadd taċ-ċelloli. "
            L"Il-bidu mill-ġdid awtomatiku jqabbel iż-żoni tal-iskrins attivi; il-vojt bejniethom jibqa’ "
            L"jevolvi iżda ma jidħolx fil-paragun.\r\n\r\nIrrisettja l-valuri\r\nIr-reset jistabbilixxi "
            L"d-daqs muri taċ-ċellola għal 8 px bil-gradilja jew mingħajrha (spazjar ta’ 9 jew 8 px), "
            L"il-veloċità għal 20 ġenerazzjonijiet/s, id-densità għal 25 % u t-tliet kuluri standard. "
            L"L-għażliet l-oħra jinżammu; forma li ma tibqax toqgħod tiġi sostitwita bit-taħlita. Tinħoloq "
            L"xena ġdida biss jekk jinbidel l-ispazjar jew id-densità fil-mod "
            L"tal-istorbju.\r\n\r\nAPPLIKAZZJONI INDIPENDENTI U REĠISTRAZZJONI MP4\r\nEXE isalva "
            L"s-settings kontinwament u jirreġistra l-ewwel skrin attiv f'MP4. Jissuġġerixxi Vidjows, "
            L"inkella Dokumenti. Viewport juża d-dimensjonijiet u r-rata tal-iskrin sa 60 frejm/s. TV "
            L"joffri 1920 × 1080, 1440 × 1080 jew 1280 × 720 f'16:9 b'50, 25, 59.94 (60000/1001) jew 29.97 "
            L"(30000/1001) frejm/s. Il-proporzjon jinżamm; TV juża BT.709 progressiv b'firxa limitata u "
            L"4:2:0. It-tieqa indipendenti tas-settings tista' tiġi minimizzata. OK isalva "
            L"għar-reġistrazzjoni li jmiss; Ikkanċella jew Esc jarmi bidliet mhux ikkonfermati. L-iskrin "
            L"irreġistrat ma jistax jintefa; l-oħrajn jistgħu jinbidlu. Ħruġ waqt reġistrazzjoni jitlob "
            L"konferma. Bl-animazzjoni attiva, Spazju jaqleb il-pawża, F9: Ibda r-reġistrazzjoni; F10: "
            L"Waqqaf ir-reġistrazzjoni. Il-kerser jinħeba wara 1 sekonda inattiva u jidher meta jiċċaqlaq. "
            L"Tab/Shift+Tab jgħaddi bejn il-kontrolli; Alt jattiva kmandi sottolinjati. Esc jagħlaq "
            L"Għajnuna/Dwar jew joħroġ mit-tieqa prinċipali.\r\n\r\nSTAMPA U ĠESTJONI TAL-ISCREENSAVER "
            L"FL-EXE\r\nL-istampa ssalva BMP/GIF/JPEG/PNG/TIFF/WebP tal-iskrin li qed jiġi rreġistrat, "
            L"inkella tal-ewwel skrin "
            L"attiv, bir-riżoluzzjoni tiegħu mingħajr ma terġa’ tibda x-xena. Jiġi ssuġġerit il-folder "
            L"Stampi, inkella Dokumenti. L-imblukkar tal-iscreensaver waqt l-animazzjoni ma jħallihx jibda "
            L"sakemm l-animazzjoni tkun viżibbli u mhux f’pawża. Veloċità żero mhijiex pawża. "
            L"L-installazzjoni mill-EXE testratta l-SCR inkluż u tagħżlu bħala screensaver tal-Windows. "
            L"L-installazzjoni u t-tneħħija jistgħu jeħtieġu approvazzjoni tal-amministratur; l-istrixxa "
            L"tal-istatus turi l-operazzjoni sa tmiemha. Jekk it-tneħħija tkun imblukkata, agħlaq "
            L"l-iscreensaver li qed jaħdem, is-settings tiegħu u l-previżjoni "
            L"tal-Windows.\r\n\r\nSCREENSAVER TAL-WINDOWS\r\nGameOfLife.scr juża l-iskrins kollha "
            L"b'settings separati mill-EXE. Il-previżjoni tibda animazzjoni fuq skrin sħiħ bis-settings "
            L"miftuħa. Il-previżjoni żgħira tal-Windows iċċekken id-dinja kollha. OK isalva; Ikkanċella "
            L"jew Esc jarmi l-bidliet. Moviment tal-maws jew tast joħroġ mill-iscreensaver sħiħ. "
            L"Ir-reġistrazzjoni MP4 tinsab fl-EXE.\r\n\r\nPOŻIZZJONI U STAT TAT-TWIEQI\r\nMeta jingħalqu, "
            L"il-pożizzjonijiet tat-tieqa prinċipali u ta’ Dwar jiġu salvati separatament; l-Għajnuna "
            L"ssalva wkoll id-daqs u l-istat normali jew massimizzat ta’ qabel il-minimizzazzjoni. Dan ma "
            L"jiddependix mill-konferma tas-settings tal-applikazzjoni. Il-ħruġ mill-applikazzjoni jagħlaq "
            L"ukoll Għajnuna u Dwar.\r\n\r\nRENDIMENT U LIĊENZJI TAL-FOROM\r\nL-evoluzzjoni u l-paraguni "
            L"viżibbli jużaw shaders Direct3D 11 fuq il-GPU; hemm rendiment bis-software jekk il-bidu "
            L"tal-ħardwer ifalli. Kull skrin juża l-kontroll tal-ħin tal-frejms ippruvat bir-rata tiegħu. "
            L"MP4 jeħtieġ Media Foundation u encoder H.264. Il-forom ġejjin minn LifeWiki (GFDL 1.2 jew "
            L"aktar tard) u kollezzjonijiet fid-dominju pubbliku ta' Alan Hensel. Il-kodiċi għandu "
            L"liċenzja MIT; l-avviżi u l-liċenzji tal-katalgu huma separati.\r\n\r\nScreensaver "
            L"tal-Windows… jiftaħ is-settings tas-sistema għall-iscreensaver."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nREGOLI\r\nIl-Logħba tal-Ħajja ta' Conway tuża B3/S23. Ċellola mejta "
            L"titwieled bi eżatt tliet ġirien ħajjin; waħda ħajja tibqa' ħajja b'żewġ jew tliet ġirien. "
            L"It-tmien ġirien jinkludu d-djagonali. Iċ-ċelloli kollha jinbidlu flimkien. It-truf opposti "
            L"jingħaqdu: xellug mal-lemin, fuq ma' isfel.\r\n\r\nSKRINS U DINJA KOMUNI\r\nIl-kaxxi fl-EXE "
            L"jattivaw l-iskrins; is-settings japplikaw għad-dinja komuni. Skrin wieħed attiv fih id-dinja "
            L"kollha. Meta tintgħażel parti mill-arranġament, jitneħħew ringieli u kolonni kompletament "
            L"vojta: ix-xellug u l-lemin jingħaqdu meta jintefa dak tan-nofs. Toqob interni li ma jistgħux "
            L"jitneħħew jibqgħu fis-simulazzjoni. L-għażla tal-iskrins kollha, jew SCR, iżżomm "
            L"ir-rettangolu tad-desktop u l-vojt inviżibbli. Kull skrin juri r-reġjun tiegħu tal-istess "
            L"simulazzjoni.\r\n\r\nSTAT INIZJALI U FOROM\r\nIl-bidu standard huwa storbju każwali b'25 % "
            L"ċelloli ħajjin. Id-densità inizjali 0–100 % tintuża fil-bidu mill-ġdid li jmiss. Forom "
            L"magħrufa biss tuża 4 106 forom inklużi mingħajr storbju u tiddiżattiva d-densità. Agħżel "
            L"taħlita jew isem; id-dimensjonijiet huma f'ċelloli. Ittajpja isem biex tfittex. Jidhru biss "
            L"forom li jidħlu sħaħ. Forom żgħar ivverifikati jirrepetu f'kopji separati, kbar jew "
            L"kumplessi darba fiċ-ċentru. Dinja iżgħar tista' tissostitwixxi għażla kbira wisq b'taħlita. "
            L"Bidla tal-mod jew forma toħloq xena ġdida. Bidu mill-ġdid iżomm l-għażla; il-katalgu jaħdem "
            L"mingħajr internet.\r\n\r\nĊELLOLI, GRADILJA U KULURI\r\nMingħajr gradilja d-daqs huwa 1–64 "
            L"px. Il-gradilja żżid tarf ta' 1 px fl-ispazjar eżistenti: il-valur muri u s-slajder jonqsu "
            L"b'wieħed, b'1–63 disponibbli. Meta tintefa jerġa' lura l-valur. Is-slajder iżomm il-firxa u "
            L"jerġa' lura mit-tarf mhux disponibbli; il-kaxxa tibqa' attiva. Il-bidla żżomm ix-xena ħlief "
            L"meta tixgħel f'1 px: l-ispazjar isir 2 px u tibda xena ġdida. Bidla fid-daqs jew fl-iskrins "
            L"terġa' tibda wkoll. Dinja kbira ħafna tista' teħtieġ minimu ogħla. Il-kuluri taċ-ċelloli, "
            L"sfond u gradilja jinbidlu separatament mingħajr bidu mill-ġdid. Il-kulur każwali taċ-ċelloli "
            L"ħajjin jagħżel kulur ġdid f’kull bidu mill-ġdid manwali jew awtomatiku tax-xena. Il-kulur "
            L"salvat jinżamm u jerġa’ jidher meta tiddiżattiva din l-għażla. L-istess imġiba tista’ "
            L"tinxtegħel separatament għall-isfond u l-gradilja; iż-żewġ għażliet ġodda huma mitfija "
            L"awtomatikament.\r\n\r\nVELOĊITÀ, PAWŻA U BIDU MILL-ĠDID AWTOMATIKU\r\nIl-veloċità hija 0–240 "
            L"ġenerazzjonijiet/s, indipendenti mir-rata tal-iskrin; 0 iwaqqaf l-evoluzzjoni. Pawża u "
            L"Kompli jżommu d-dinja. Ibda mill-ġdid jerġa' jibda fil-mod magħżul. Il-bidu mill-ġdid "
            L"awtomatiku fakultattiv isib fażijiet viżibbli statiċi jew ripetuti eżatt, inklużi "
            L"oxxillaturi. Iqabbel ġenerazzjonijiet, mhux sekondi; jeskludi żoni inviżibbli. Riżultati "
            L"asinkroni jistgħu jdewmu ftit il-bidu. Valuri standard: spazjar 8 px, 20 ġenerazzjonijiet/s, "
            L"kulur każwali taċ-ċelloli ħajjin u bidu awtomatiku mixgħula. Il-gradilja hija mitfija b’mod "
            L"awtomatiku. Il-veloċità milħuqa tiddependi mill-prestazzjoni u mill-għadd taċ-ċelloli. "
            L"Il-bidu mill-ġdid awtomatiku jqabbel iż-żoni tal-iskrins attivi; il-vojt bejniethom jibqa’ "
            L"jevolvi iżda ma jidħolx fil-paragun.\r\n\r\nIrrisettja l-valuri\r\nIr-reset jistabbilixxi "
            L"d-daqs muri taċ-ċellola għal 8 px bil-gradilja jew mingħajrha (spazjar ta’ 9 jew 8 px), "
            L"il-veloċità għal 20 ġenerazzjonijiet/s, id-densità għal 25 % u t-tliet kuluri standard. "
            L"L-għażliet l-oħra jinżammu; forma li ma tibqax toqgħod tiġi sostitwita bit-taħlita. Tinħoloq "
            L"xena ġdida biss jekk jinbidel l-ispazjar jew id-densità fil-mod "
            L"tal-istorbju.\r\n\r\nSCREENSAVER TAL-WINDOWS\r\nGameOfLife.scr juża l-iskrins kollha "
            L"b'settings separati mill-EXE. Il-previżjoni tibda animazzjoni fuq skrin sħiħ bis-settings "
            L"miftuħa. Il-previżjoni żgħira tal-Windows iċċekken id-dinja kollha. OK isalva; Ikkanċella "
            L"jew Esc jarmi l-bidliet. Moviment tal-maws jew tast joħroġ mill-iscreensaver sħiħ. "
            L"Ir-reġistrazzjoni MP4 tinsab fl-EXE.\r\n\r\nPOŻIZZJONI U STAT TAT-TWIEQI\r\nMeta jingħalqu, "
            L"il-pożizzjonijiet tat-tieqa prinċipali u ta’ Dwar jiġu salvati separatament; l-Għajnuna "
            L"ssalva wkoll id-daqs u l-istat normali jew massimizzat ta’ qabel il-minimizzazzjoni. Dan ma "
            L"jiddependix mill-konferma tas-settings tal-applikazzjoni. Il-ħruġ mill-applikazzjoni jagħlaq "
            L"ukoll Għajnuna u Dwar.\r\n\r\nRENDIMENT U LIĊENZJI TAL-FOROM\r\nL-evoluzzjoni u l-paraguni "
            L"viżibbli jużaw shaders Direct3D 11 fuq il-GPU; hemm rendiment bis-software jekk il-bidu "
            L"tal-ħardwer ifalli. Kull skrin juża l-kontroll tal-ħin tal-frejms ippruvat bir-rata tiegħu. "
            L"MP4 jeħtieġ Media Foundation u encoder H.264. Il-forom ġejjin minn LifeWiki (GFDL 1.2 jew "
            L"aktar tard) u kollezzjonijiet fid-dominju pubbliku ta' Alan Hensel. Il-kodiċi għandu "
            L"liċenzja MIT; l-avviżi u l-liċenzji tal-katalgu huma separati."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Daqs taċ-ċellola: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Veloċità: %u ġenerazzjonijiet/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Densità inizjali: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Ibda x-xena mill-ġdid" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Kulur taċ-ċelloli ħajjin…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Kulur tal-isfond…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"L-iskrins magħżula jaqsmu dinja waħda. Jitneħħew strixxi vojta; jibqgħu toqob interni."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"L-animazzjoni għaddejja…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"L-animazzjoni tinsab sospiża."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Ma setax jiġi inizjalizzat ir-renderer Direct3D."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Attiva l-previżjoni"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Iddiżattiva l-previżjoni"
        },
        LocalizedText{ TXT_MONITOR,
            L"Moniter"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Riżoluzzjoni"
        },
        LocalizedText{ TXT_POSITION,
            L"Pożizzjoni"
        },
        LocalizedText{ TXT_PRIMARY,
            L"primarju"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Mudell tal-moniter"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Rata ta’ aġġornament"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Fond tal-bits"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Format tal-kulur"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Spazju tal-kulur"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bits/kanal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bits/pixel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Moniter tal-animazzjoni"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Lest"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Uri l-gradilja"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Kulur tal-gradilja…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Ibda mill-ġdid awtomatikament xena viżibbli stabbli jew ripetuta"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Forom magħrufa biss"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Ibda r-reġistrazzjoni…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Waqqaf ir-reġistrazzjoni"
        },
        LocalizedText{ TXT_RECORDING,
            L"Reġistrazzjoni MP4 għaddejja…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Ir-reġistrazzjoni ġiet issejvjata."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Ma setgħetx tinbeda r-reġistrazzjoni MP4."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"L-għeluq tal-applikazzjoni jwaqqaf ir-reġistrazzjoni li tkun għaddejja."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Issettjar tar-reġistrazzjoni"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Riżoluzzjoni:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Rata tal-frejms:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Il-bidliet japplikaw għar-reġistrazzjoni MP4 li jmiss."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Taħlita ta' forom adattati"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Il-forma magħżula m'għadhiex tidħol fid-dinja. Intgħażlet taħlita adattata."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Ma setax jitgħabba l-katalgu tal-forom magħrufa."
        },
    }),
    DefineLanguage(LANG_NL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Willekeurige achtergrondkleur bij elke herstart van de scène"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Willekeurige rasterkleur bij elke herstart van de scène" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Windows-schermbeveiliging…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"De instellingen voor de Windows-schermbeveiliging kunnen niet worden geopend."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Waarden herstellen" },
        LocalizedText{ TXT_SNAPSHOT, L"Momentopname…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"De BMP/GIF/JPEG/PNG/TIFF/WebP-afbeelding is opgeslagen." },
        LocalizedText{ TXT_SNAPSHOT_FAILED,
            L"De BMP/GIF/JPEG/PNG/TIFF/WebP-afbeelding kon niet worden opgeslagen."
        },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Schermbeveiliging blokkeren tijdens animatie" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Willekeurige kleur van levende cellen bij elke herstart van de scène"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Schermbeveiliging wordt geïnstalleerd…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Schermbeveiliging wordt verwijderd…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Schermbeveiliging installeren" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Schermbeveiliging verwijderen" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"De schermbeveiliging is niet geïnstalleerd." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"De schermbeveiliging is geïnstalleerd." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"De schermbeveiliging is verwijderd." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"De schermbeveiliging kon niet worden verwijderd. Sluit de schermbeveiliging en het voorbeeld "
            L"en probeer het opnieuw."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Sluit de instellingen van GameOfLife en probeer het verwijderen opnieuw."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Sluit de instellingen voor schermbeveiliging van Windows en probeer het verwijderen opnieuw."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Sluit de schermbeveiliging of het schermvullende voorbeeld met Esc of door de muis te bewegen "
            L"en probeer het opnieuw."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Nederlands"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — bediening"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Instellingen van GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Taal:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Annuleren"
        },
        LocalizedText{ TXT_EXIT,
            L"Afsluiten"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pauzeren"
        },
        LocalizedText{ TXT_RESUME,
            L"Hervatten"
        },
        LocalizedText{ TXT_HELP,
            L"Help"
        },
        LocalizedText{ TXT_ABOUT,
            L"Info"
        },
        LocalizedText{ TXT_CLOSE,
            L"Sluiten"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Website %ls openen"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Kan de website niet in de standaardbrowser openen."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"De URL kon niet naar het klembord worden gekopieerd."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"De informatie kon niet naar het klembord worden gekopieerd."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conways Game of Life in één gedeelde wereld over meerdere schermen."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Versie:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Doelplatform:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Website:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Openen in standaardbrowser"
        },
        LocalizedText{ TXT_COPY_URL,
            L"&Adres kopiëren"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"&Informatie kopiëren"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"De licentiebron is niet beschikbaar."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nREGELS\r\nConways Game of Life gebruikt B3/S23. Een dode cel wordt levend "
            L"bij precies drie levende buren; een levende overleeft bij twee of drie. De acht buren "
            L"omvatten diagonalen. Alle cellen veranderen tegelijk. Tegenoverliggende randen sluiten aan: "
            L"links op rechts, boven op onder.\r\n\r\nSCHERMEN EN GEDEELDE WERELD\r\nVinkjes in EXE "
            L"schakelen schermen in; instellingen gelden voor de gedeelde wereld. Eén ingeschakeld scherm "
            L"bevat de hele wereld. Bij een gedeeltelijke keuze vervallen volledig lege rijen en kolommen: "
            L"links en rechts sluiten aan als het middelste scherm uitstaat. Niet verwijderbare binnenste "
            L"gaten blijven in de simulatie. Alle schermen selecteren, of SCR gebruiken, behoudt de "
            L"bureaubladrechthoek inclusief onzichtbare gaten. Elk scherm toont zijn eigen gebied van "
            L"dezelfde simulatie.\r\n\r\nBEGINSTAND EN PATRONEN\r\nStandaard start willekeurige ruis met "
            L"25 % levende cellen. Begindichtheid van 0–100 % geldt bij de volgende herstart. Alleen "
            L"bekende patronen gebruikt 4.106 meegeleverde patronen zonder ruis en schakelt dichtheid uit. "
            L"Kies een mengsel of een patroon op naam; afmetingen zijn in cellen. Typ een naam om te "
            L"zoeken. Alleen volledig passende patronen staan in de lijst. Kleine gecontroleerde patronen "
            L"verschijnen in losse kopieën, grote of complexe één keer in het midden. Verkleinen kan een "
            L"te grote keuze vervangen door een mengsel. Een andere modus of patroon maakt een nieuwe "
            L"scène. Herstarts behouden de keuze; de catalogus werkt offline.\r\n\r\nCELGROOTTE, RASTER EN "
            L"KLEUREN\r\nZonder raster is de celgrootte 1–64 px. Raster tonen voegt binnen de bestaande "
            L"afstand een rand van 1 px toe: waarde en schuif dalen met één, bruikbaar is 1–63. "
            L"Uitschakelen herstelt de waarde. De schuif behoudt zijn bereik en springt terug vanaf het "
            L"onbeschikbare uiteinde; het vinkje blijft bruikbaar. Omschakelen behoudt de scène, behalve "
            L"inschakelen bij 1 px: de afstand wordt 2 px en er begint een nieuwe scène. Celgrootte of "
            L"schermen wijzigen begint ook opnieuw. Zeer grote werelden kunnen een hoger minimum vragen. "
            L"Cel-, achtergrond- en rasterkleuren veranderen afzonderlijk zonder herstart. Willekeurige "
            L"kleur van levende cellen kiest bij elke handmatige of automatische herstart van de scène een "
            L"nieuwe kleur. De opgeslagen kleur blijft behouden en keert terug als deze optie uitstaat. "
            L"Hetzelfde gedrag kan afzonderlijk voor achtergrond en raster worden ingeschakeld; beide "
            L"nieuwe opties staan standaard uit.\r\n\r\nSNELHEID, PAUZE EN AUTOMATISCH HERSTARTEN\r\nDe "
            L"snelheid is 0–240 generaties/s, los van de verversingssnelheid; 0 stopt de evolutie. Pauze "
            L"en Hervatten behouden de wereld. Opnieuw starten begint in de gekozen modus. Optioneel "
            L"automatisch herstarten herkent vaste en exact herhalende zichtbare fasen, ook oscillatoren. "
            L"Het vergelijkt generaties in plaats van seconden en negeert onzichtbare gebieden. Asynchrone "
            L"resultaten kunnen de herstart iets vertragen. Standaard: afstand 8 px, 20 generaties/s, "
            L"willekeurige kleur van levende cellen en automatisch herstarten aan. Het raster staat "
            L"standaard uit. De bereikte snelheid hangt af van prestaties en celaantal. Automatisch "
            L"herstarten vergelijkt de gebieden van ingeschakelde schermen; tussenliggende gaten "
            L"ontwikkelen zich verder maar tellen niet mee in de vergelijking.\r\n\r\nWaarden "
            L"herstellen\r\nHerstellen zet de getoonde celgrootte op 8 px met of zonder raster (afstand 9 "
            L"of 8 px), de snelheid op 20 generaties/s, de dichtheid op 25 % en herstelt de drie "
            L"standaardkleuren. Andere keuzes blijven behouden; een patroon dat niet meer past, wordt "
            L"vervangen door het mengsel. Een nieuwe scène ontstaat alleen bij gewijzigde afstand of "
            L"gewijzigde dichtheid in ruismodus.\r\n\r\nZELFSTANDIGE TOEPASSING EN MP4-OPNAME\r\nEXE "
            L"bewaart instellingen doorlopend en neemt het eerste actieve scherm op als MP4. Video's wordt "
            L"voorgesteld, anders Documenten. Viewport gebruikt schermafmetingen en verversingssnelheid "
            L"tot 60 beelden/s. TV biedt 1920 × 1080, 1440 × 1080 of 1280 × 720 in 16:9 bij 50, 25, 59,94 "
            L"(60000/1001) of 29,97 (30000/1001) beelden/s. De beeldverhouding blijft behouden; TV "
            L"gebruikt progressief BT.709 met beperkt bereik en 4:2:0. Het onafhankelijke "
            L"instellingenvenster kan worden geminimaliseerd. OK bewaart voor de volgende opname; "
            L"Annuleren of Esc verwerpt onbevestigde wijzigingen. Het opgenomen scherm kan niet uit; "
            L"andere uitgangen mogen veranderen. Afsluiten tijdens opname vraagt bevestiging. Met focus op "
            L"de animatie wisselt Spatie de pauze, F9: Opname starten; F10: Opname stoppen. De aanwijzer "
            L"verdwijnt na 1 seconde stilstand en keert bij beweging terug. Tab/Shift+Tab doorloopt "
            L"bediening, Alt activeert onderstreepte opdrachten. Esc sluit Help/Info of verlaat het "
            L"hoofdvenster.\r\n\r\nMOMENTOPNAME EN SCHERMBEVEILIGINGSBEHEER IN EXE\r\nMomentopname bewaart "
            L"een BMP/GIF/JPEG/PNG/TIFF/WebP van het opgenomen scherm, anders het eerste actieve, op zijn "
            L"resolutie zonder de "
            L"scène te herstarten. Afbeeldingen wordt voorgesteld, anders Documenten. Schermbeveiliging "
            L"blokkeren tijdens animatie voorkomt de start ervan zolang de animatie zichtbaar en niet "
            L"gepauzeerd is. Snelheid nul is geen pauze. Installatie vanuit EXE pakt de meegeleverde SCR "
            L"uit en selecteert deze als Windows-schermbeveiliging. Installeren en verwijderen kunnen "
            L"beheerderstoestemming vereisen; de statusbalk toont de bewerking tot deze klaar is. Sluit "
            L"bij geblokkeerde verwijdering de actieve schermbeveiliging, de instellingen en het "
            L"Windows-voorbeeld.\r\n\r\nWINDOWS-SCHERMBEVEILIGING\r\nGameOfLife.scr gebruikt alle schermen "
            L"en bewaart instellingen apart van EXE. Voorbeeld inschakelen start volledig scherm terwijl "
            L"instellingen openblijven. Het kleine Windows-voorbeeld verkleint de hele wereld. OK bewaart; "
            L"Annuleren of Esc verwerpt wijzigingen. Muisbeweging of een toets sluit de schermbeveiliging "
            L"op volledig scherm. MP4-opname is beschikbaar in EXE.\r\n\r\nVENSTERPOSITIES EN "
            L"TOESTAND\r\nBij sluiten worden de posities van het hoofdvenster en Info afzonderlijk "
            L"opgeslagen; voor Help ook de grootte en normale of gemaximaliseerde toestand van vóór "
            L"minimalisatie. Dit staat los van het bevestigen van toepassingsinstellingen. Afsluiten van "
            L"de toepassing sluit ook Help en Info.\r\n\r\nWEERGAVE EN PATROONLICENTIES\r\nEvolutie en "
            L"zichtbare vergelijkingen gebruiken Direct3D 11-shaders op de GPU; softwareweergave is "
            L"beschikbaar als hardware-initialisatie mislukt. Elk scherm gebruikt de beproefde framepacer "
            L"op zijn eigen frequentie. MP4 vereist Media Foundation en een H.264-encoder. Patronen komen "
            L"van LifeWiki (GFDL 1.2 of hoger) en Alan Hensels verzamelingen in het publieke domein. De "
            L"programmacode is MIT; catalogusvermeldingen en -licenties zijn "
            L"afzonderlijk.\r\n\r\nWindows-schermbeveiliging… opent de systeeminstellingen voor "
            L"schermbeveiliging."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nREGELS\r\nConways Game of Life gebruikt B3/S23. Een dode cel wordt levend "
            L"bij precies drie levende buren; een levende overleeft bij twee of drie. De acht buren "
            L"omvatten diagonalen. Alle cellen veranderen tegelijk. Tegenoverliggende randen sluiten aan: "
            L"links op rechts, boven op onder.\r\n\r\nSCHERMEN EN GEDEELDE WERELD\r\nVinkjes in EXE "
            L"schakelen schermen in; instellingen gelden voor de gedeelde wereld. Eén ingeschakeld scherm "
            L"bevat de hele wereld. Bij een gedeeltelijke keuze vervallen volledig lege rijen en kolommen: "
            L"links en rechts sluiten aan als het middelste scherm uitstaat. Niet verwijderbare binnenste "
            L"gaten blijven in de simulatie. Alle schermen selecteren, of SCR gebruiken, behoudt de "
            L"bureaubladrechthoek inclusief onzichtbare gaten. Elk scherm toont zijn eigen gebied van "
            L"dezelfde simulatie.\r\n\r\nBEGINSTAND EN PATRONEN\r\nStandaard start willekeurige ruis met "
            L"25 % levende cellen. Begindichtheid van 0–100 % geldt bij de volgende herstart. Alleen "
            L"bekende patronen gebruikt 4.106 meegeleverde patronen zonder ruis en schakelt dichtheid uit. "
            L"Kies een mengsel of een patroon op naam; afmetingen zijn in cellen. Typ een naam om te "
            L"zoeken. Alleen volledig passende patronen staan in de lijst. Kleine gecontroleerde patronen "
            L"verschijnen in losse kopieën, grote of complexe één keer in het midden. Verkleinen kan een "
            L"te grote keuze vervangen door een mengsel. Een andere modus of patroon maakt een nieuwe "
            L"scène. Herstarts behouden de keuze; de catalogus werkt offline.\r\n\r\nCELGROOTTE, RASTER EN "
            L"KLEUREN\r\nZonder raster is de celgrootte 1–64 px. Raster tonen voegt binnen de bestaande "
            L"afstand een rand van 1 px toe: waarde en schuif dalen met één, bruikbaar is 1–63. "
            L"Uitschakelen herstelt de waarde. De schuif behoudt zijn bereik en springt terug vanaf het "
            L"onbeschikbare uiteinde; het vinkje blijft bruikbaar. Omschakelen behoudt de scène, behalve "
            L"inschakelen bij 1 px: de afstand wordt 2 px en er begint een nieuwe scène. Celgrootte of "
            L"schermen wijzigen begint ook opnieuw. Zeer grote werelden kunnen een hoger minimum vragen. "
            L"Cel-, achtergrond- en rasterkleuren veranderen afzonderlijk zonder herstart. Willekeurige "
            L"kleur van levende cellen kiest bij elke handmatige of automatische herstart van de scène een "
            L"nieuwe kleur. De opgeslagen kleur blijft behouden en keert terug als deze optie uitstaat. "
            L"Hetzelfde gedrag kan afzonderlijk voor achtergrond en raster worden ingeschakeld; beide "
            L"nieuwe opties staan standaard uit.\r\n\r\nSNELHEID, PAUZE EN AUTOMATISCH HERSTARTEN\r\nDe "
            L"snelheid is 0–240 generaties/s, los van de verversingssnelheid; 0 stopt de evolutie. Pauze "
            L"en Hervatten behouden de wereld. Opnieuw starten begint in de gekozen modus. Optioneel "
            L"automatisch herstarten herkent vaste en exact herhalende zichtbare fasen, ook oscillatoren. "
            L"Het vergelijkt generaties in plaats van seconden en negeert onzichtbare gebieden. Asynchrone "
            L"resultaten kunnen de herstart iets vertragen. Standaard: afstand 8 px, 20 generaties/s, "
            L"willekeurige kleur van levende cellen en automatisch herstarten aan. Het raster staat "
            L"standaard uit. De bereikte snelheid hangt af van prestaties en celaantal. Automatisch "
            L"herstarten vergelijkt de gebieden van ingeschakelde schermen; tussenliggende gaten "
            L"ontwikkelen zich verder maar tellen niet mee in de vergelijking.\r\n\r\nWaarden "
            L"herstellen\r\nHerstellen zet de getoonde celgrootte op 8 px met of zonder raster (afstand 9 "
            L"of 8 px), de snelheid op 20 generaties/s, de dichtheid op 25 % en herstelt de drie "
            L"standaardkleuren. Andere keuzes blijven behouden; een patroon dat niet meer past, wordt "
            L"vervangen door het mengsel. Een nieuwe scène ontstaat alleen bij gewijzigde afstand of "
            L"gewijzigde dichtheid in ruismodus.\r\n\r\nWINDOWS-SCHERMBEVEILIGING\r\nGameOfLife.scr "
            L"gebruikt alle schermen en bewaart instellingen apart van EXE. Voorbeeld inschakelen start "
            L"volledig scherm terwijl instellingen openblijven. Het kleine Windows-voorbeeld verkleint de "
            L"hele wereld. OK bewaart; Annuleren of Esc verwerpt wijzigingen. Muisbeweging of een toets "
            L"sluit de schermbeveiliging op volledig scherm. MP4-opname is beschikbaar in "
            L"EXE.\r\n\r\nVENSTERPOSITIES EN TOESTAND\r\nBij sluiten worden de posities van het "
            L"hoofdvenster en Info afzonderlijk opgeslagen; voor Help ook de grootte en normale of "
            L"gemaximaliseerde toestand van vóór minimalisatie. Dit staat los van het bevestigen van "
            L"toepassingsinstellingen. Afsluiten van de toepassing sluit ook Help en Info.\r\n\r\nWEERGAVE "
            L"EN PATROONLICENTIES\r\nEvolutie en zichtbare vergelijkingen gebruiken Direct3D 11-shaders op "
            L"de GPU; softwareweergave is beschikbaar als hardware-initialisatie mislukt. Elk scherm "
            L"gebruikt de beproefde framepacer op zijn eigen frequentie. MP4 vereist Media Foundation en "
            L"een H.264-encoder. Patronen komen van LifeWiki (GFDL 1.2 of hoger) en Alan Hensels "
            L"verzamelingen in het publieke domein. De programmacode is MIT; catalogusvermeldingen en "
            L"-licenties zijn afzonderlijk."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Celgrootte: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Snelheid: %u generaties/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Begindichtheid: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Scène opnieuw starten" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Kleur levende cellen…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Achtergrondkleur…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Gekozen schermen delen één wereld. Lege stroken vervallen; binnenste gaten blijven."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animatie wordt uitgevoerd…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animatie is gepauzeerd."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"De Direct3D-renderer kon niet worden geïnitialiseerd."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Voorbeeld inschakelen"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Voorbeeld uitschakelen"
        },
        LocalizedText{ TXT_MONITOR,
            L"Beeldscherm"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Resolutie"
        },
        LocalizedText{ TXT_POSITION,
            L"Positie"
        },
        LocalizedText{ TXT_PRIMARY,
            L"primair"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Beeldschermmodel"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Vernieuwingsfrequentie"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bitdiepte"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Kleurindeling"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Kleurruimte"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bits/kanaal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bits/pixel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Animatiebeeldscherm"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Gereed"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Raster tonen"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Rasterkleur…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Een vaste of herhalende zichtbare scène automatisch opnieuw starten"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Alleen bekende patronen"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Opname starten…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Opname stoppen"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4-opname wordt gemaakt…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"De opname is opgeslagen."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"De MP4-opname kon niet worden gestart."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Als u de toepassing sluit, wordt de huidige opname gestopt."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Opname-instellingen"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Resolutie:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Framesnelheid:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Wijzigingen gelden voor de volgende MP4-opname."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Mengsel van passende patronen"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Het gekozen patroon past niet meer. Een passend mengsel is geselecteerd."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"De catalogus met bekende patronen kon niet worden geladen."
        },
    }),
    DefineLanguage(LANG_RO, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Culoare aleatorie a fundalului la fiecare repornire a scenei"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Culoare aleatorie a grilei la fiecare repornire a scenei" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Economizor de ecran Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Nu se pot deschide setările economizorului de ecran Windows."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Resetează valorile" },
        LocalizedText{ TXT_SNAPSHOT, L"Instantaneu…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Imaginea BMP/GIF/JPEG/PNG/TIFF/WebP a fost salvată." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Imaginea BMP/GIF/JPEG/PNG/TIFF/WebP nu a putut fi salvată." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Blocare economizor în timpul animației" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Culoare aleatorie a celulelor vii la fiecare repornire a scenei"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Se instalează economizorul de ecran…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Se dezinstalează economizorul de ecran…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Instalare economizor de ecran" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Dezinstalare economizor de ecran" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Economizorul de ecran nu a fost instalat." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Economizorul de ecran a fost instalat." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Economizorul de ecran a fost dezinstalat." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Economizorul de ecran nu a putut fi dezinstalat. Închideți-l împreună cu previzualizarea și "
            L"încercați din nou."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Închideți fereastra de setări GameOfLife și încercați din nou dezinstalarea."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Închideți setările economizorului de ecran Windows și încercați din nou dezinstalarea."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Închideți economizorul sau previzualizarea pe tot ecranul cu Esc ori mișcând mouse-ul și "
            L"încercați din nou."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Română"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — comenzi"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Setări GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Limbă:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Anulare"
        },
        LocalizedText{ TXT_EXIT,
            L"Ieșire"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pauză"
        },
        LocalizedText{ TXT_RESUME,
            L"Reluare"
        },
        LocalizedText{ TXT_HELP,
            L"Ajutor"
        },
        LocalizedText{ TXT_ABOUT,
            L"Despre"
        },
        LocalizedText{ TXT_CLOSE,
            L"Închidere"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Deschidere site web %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Site-ul nu poate fi deschis în browserul implicit."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"URL-ul nu a putut fi copiat în clipboard."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Informațiile nu au putut fi copiate în clipboard."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Jocul vieții al lui Conway într-o lume comună mai multor ecrane."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Versiune:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Platformă țintă:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Site web:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Deschidere în browserul implicit"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Copiere &adresă"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Copiere &informații"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Resursa licenței nu este disponibilă."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nREGULI\r\nJocul vieții al lui Conway folosește B3/S23. O celulă moartă se "
            L"naște cu exact trei vecine vii; una vie supraviețuiește cu două sau trei. Cele opt vecine "
            L"includ diagonalele. Toate se schimbă simultan. Marginile opuse se unesc: stânga cu dreapta, "
            L"sus cu jos.\r\n\r\nECRANE ȘI LUME COMUNĂ\r\nBifele din EXE activează ecranele; setările se "
            L"aplică lumii comune. Un singur ecran activ cuprinde întreaga lume. La alegerea unei părți a "
            L"configurației, rândurile și coloanele complet goale sunt eliminate: ecranele stâng și drept "
            L"se unesc când cel central este oprit. Golurile interioare imposibil de eliminat rămân în "
            L"simulare. Alegerea tuturor ecranelor sau folosirea SCR păstrează dreptunghiul desktopului și "
            L"spațiile invizibile. Fiecare ecran arată regiunea sa din aceeași simulare.\r\n\r\nSTARE "
            L"INIȚIALĂ ȘI MODELE\r\nPornirea implicită este zgomot aleatoriu cu 25 % celule vii. "
            L"Densitatea inițială 0–100 % se aplică la următoarea repornire. Doar modele cunoscute "
            L"folosește 4 106 modele incluse fără zgomot și dezactivează densitatea. Alegeți un amestec "
            L"sau un nume; dimensiunile sunt în celule. Tastați pentru căutare. Sunt oferite numai "
            L"modelele care încap complet. Cele mici verificate se repetă în copii separate; cele mari sau "
            L"complexe apar o dată în centru. Micșorarea lumii poate înlocui alegerea prea mare cu un "
            L"amestec. Schimbarea modului sau modelului creează altă scenă. Repornirile păstrează "
            L"alegerea; catalogul funcționează offline.\r\n\r\nCELULE, GRILĂ ȘI CULORI\r\nFără grilă, "
            L"dimensiunea este 1–64 px. Grila adaugă o margine de 1 px în spațierea existentă: valoarea "
            L"afișată și glisorul scad cu unu, cu 1–63 utilizabili. Dezactivarea restabilește valoarea. "
            L"Glisorul păstrează intervalul și revine din capătul indisponibil; bifa rămâne activă. "
            L"Comutarea păstrează scena, exceptând activarea la 1 px: spațierea devine 2 px și scena "
            L"reîncepe. Schimbarea dimensiunii sau ecranelor reîncepe de asemenea. Lumile foarte mari pot "
            L"impune un minim mai mare. Culorile celulelor, fundalului și grilei se schimbă separat fără "
            L"repornire. Culoarea aleatorie a celulelor vii se schimbă la fiecare repornire manuală sau "
            L"automată a scenei. Culoarea salvată se păstrează și revine la dezactivarea opțiunii. Același "
            L"comportament poate fi activat separat pentru fundal și grilă; ambele opțiuni noi sunt "
            L"inițial dezactivate.\r\n\r\nVITEZĂ, PAUZĂ ȘI REPORNIRE AUTOMATĂ\r\nViteza este 0–240 "
            L"generații/s, independent de reîmprospătare; 0 oprește evoluția. Pauză și Reluare păstrează "
            L"lumea. Repornire începe din nou în modul ales. Repornirea automată opțională recunoaște faze "
            L"vizibile statice sau exact repetate, inclusiv oscilatori. Compară generații, nu secunde; "
            L"exclude zonele invizibile. Rezultatele asincrone pot întârzia puțin repornirea. Implicit: "
            L"spațiere 8 px, 20 generații/s, culoare aleatorie a celulelor vii și repornire automată "
            L"activate. Grila este dezactivată implicit. Viteza atinsă depinde de performanță și de "
            L"numărul celulelor. Repornirea automată compară regiunile ecranelor activate; spațiile dintre "
            L"ele continuă să evolueze, dar sunt excluse din comparație.\r\n\r\nResetează "
            L"valorile\r\nResetarea stabilește dimensiunea afișată a celulei la 8 px cu sau fără grilă "
            L"(spațiere de 9 sau 8 px), viteza la 20 generații/s, densitatea la 25 % și cele trei culori "
            L"implicite. Celelalte alegeri se păstrează; un model care nu mai încape este înlocuit cu "
            L"amestecul. O scenă nouă apare numai dacă se schimbă spațierea sau densitatea în modul "
            L"zgomot.\r\n\r\nAPLICAȚIE INDEPENDENTĂ ȘI ÎNREGISTRARE MP4\r\nEXE salvează setările continuu "
            L"și înregistrează primul ecran activ în MP4. Propune Videoclipuri, alternativ Documente. "
            L"Viewport folosește dimensiunile și rata ecranului până la 60 cadre/s. TV oferă 1920 × 1080, "
            L"1440 × 1080 sau 1280 × 720 în 16:9 la 50, 25, 59,94 (60000/1001) sau 29,97 (30000/1001) "
            L"cadre/s. Proporțiile rămân; TV folosește BT.709 progresiv cu interval limitat și 4:2:0. "
            L"Fereastra independentă de setări poate fi minimizată. OK salvează pentru următoarea "
            L"înregistrare; Anulare sau Esc renunță la modificările neconfirmate. Ecranul înregistrat nu "
            L"poate fi dezactivat; celelalte ieșiri pot fi schimbate. Ieșirea în timpul înregistrării cere "
            L"confirmare. Cu focalizarea pe animație, Spațiu comută pauza, F9: Pornire înregistrare; F10: "
            L"Oprire înregistrare. Cursorul dispare după 1 secundă inactivă și revine la mișcare. "
            L"Tab/Shift+Tab parcurge controalele; Alt activează comenzile subliniate. Esc închide "
            L"Ajutor/Despre sau iese din fereastra principală.\r\n\r\nCAPTURĂ ȘI ADMINISTRAREA "
            L"ECONOMIZORULUI ÎN EXE\r\nCaptura salvează un BMP/GIF/JPEG/PNG/TIFF/WebP al ecranului "
            L"înregistrat sau, în lipsa "
            L"înregistrării, al primului ecran activ, la rezoluția sa și fără repornirea scenei. Se "
            L"propune folderul Imagini, alternativ Documente. Blocarea economizorului în timpul animației "
            L"împiedică pornirea sa cât timp animația este vizibilă și nu este în pauză. Viteza zero nu "
            L"înseamnă pauză. Instalarea din EXE extrage SCR-ul inclus și îl selectează drept economizor "
            L"Windows. Instalarea și dezinstalarea pot necesita aprobarea administratorului; bara de stare "
            L"indică operația până la încheiere. Dacă eliminarea este blocată, închideți economizorul "
            L"activ, setările sale și previzualizarea Windows.\r\n\r\nECONOMIZOR DE ECRAN "
            L"WINDOWS\r\nGameOfLife.scr folosește toate ecranele, cu setări separate de EXE. Activarea "
            L"previzualizării pornește animația pe tot ecranul cu setările deschise. Mica previzualizare "
            L"Windows micșorează lumea întreagă. OK salvează; Anulare sau Esc renunță la schimbări. "
            L"Mișcarea mouse-ului sau o tastă închide economizorul pe tot ecranul. Înregistrarea MP4 este "
            L"disponibilă în EXE.\r\n\r\nPOZIȚIA ȘI STAREA FERESTRELOR\r\nLa închidere se salvează separat "
            L"pozițiile ferestrelor principală și Despre; pentru Ajutor, și dimensiunea și starea normală "
            L"sau maximizată dinaintea minimizării. Acest lucru este independent de confirmarea setărilor "
            L"aplicației. Ieșirea din aplicație închide și Ajutor și Despre.\r\n\r\nRANDARE ȘI LICENȚELE "
            L"MODELELOR\r\nEvoluția și comparațiile vizibile folosesc shadere Direct3D 11 pe GPU; randarea "
            L"software este disponibilă dacă inițializarea hardware eșuează. Fiecare ecran folosește "
            L"regulatorul de cadre verificat la rata sa. MP4 necesită Media Foundation și un codor H.264. "
            L"Modelele provin din LifeWiki (GFDL 1.2 sau ulterioară) și colecțiile din domeniul public ale "
            L"lui Alan Hensel. Codul are licență MIT; notificările și licențele catalogului sunt "
            L"separate.\r\n\r\nEconomizor de ecran Windows… deschide setările economizorului de ecran al "
            L"sistemului."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nREGULI\r\nJocul vieții al lui Conway folosește B3/S23. O celulă moartă se "
            L"naște cu exact trei vecine vii; una vie supraviețuiește cu două sau trei. Cele opt vecine "
            L"includ diagonalele. Toate se schimbă simultan. Marginile opuse se unesc: stânga cu dreapta, "
            L"sus cu jos.\r\n\r\nECRANE ȘI LUME COMUNĂ\r\nBifele din EXE activează ecranele; setările se "
            L"aplică lumii comune. Un singur ecran activ cuprinde întreaga lume. La alegerea unei părți a "
            L"configurației, rândurile și coloanele complet goale sunt eliminate: ecranele stâng și drept "
            L"se unesc când cel central este oprit. Golurile interioare imposibil de eliminat rămân în "
            L"simulare. Alegerea tuturor ecranelor sau folosirea SCR păstrează dreptunghiul desktopului și "
            L"spațiile invizibile. Fiecare ecran arată regiunea sa din aceeași simulare.\r\n\r\nSTARE "
            L"INIȚIALĂ ȘI MODELE\r\nPornirea implicită este zgomot aleatoriu cu 25 % celule vii. "
            L"Densitatea inițială 0–100 % se aplică la următoarea repornire. Doar modele cunoscute "
            L"folosește 4 106 modele incluse fără zgomot și dezactivează densitatea. Alegeți un amestec "
            L"sau un nume; dimensiunile sunt în celule. Tastați pentru căutare. Sunt oferite numai "
            L"modelele care încap complet. Cele mici verificate se repetă în copii separate; cele mari sau "
            L"complexe apar o dată în centru. Micșorarea lumii poate înlocui alegerea prea mare cu un "
            L"amestec. Schimbarea modului sau modelului creează altă scenă. Repornirile păstrează "
            L"alegerea; catalogul funcționează offline.\r\n\r\nCELULE, GRILĂ ȘI CULORI\r\nFără grilă, "
            L"dimensiunea este 1–64 px. Grila adaugă o margine de 1 px în spațierea existentă: valoarea "
            L"afișată și glisorul scad cu unu, cu 1–63 utilizabili. Dezactivarea restabilește valoarea. "
            L"Glisorul păstrează intervalul și revine din capătul indisponibil; bifa rămâne activă. "
            L"Comutarea păstrează scena, exceptând activarea la 1 px: spațierea devine 2 px și scena "
            L"reîncepe. Schimbarea dimensiunii sau ecranelor reîncepe de asemenea. Lumile foarte mari pot "
            L"impune un minim mai mare. Culorile celulelor, fundalului și grilei se schimbă separat fără "
            L"repornire. Culoarea aleatorie a celulelor vii se schimbă la fiecare repornire manuală sau "
            L"automată a scenei. Culoarea salvată se păstrează și revine la dezactivarea opțiunii. Același "
            L"comportament poate fi activat separat pentru fundal și grilă; ambele opțiuni noi sunt "
            L"inițial dezactivate.\r\n\r\nVITEZĂ, PAUZĂ ȘI REPORNIRE AUTOMATĂ\r\nViteza este 0–240 "
            L"generații/s, independent de reîmprospătare; 0 oprește evoluția. Pauză și Reluare păstrează "
            L"lumea. Repornire începe din nou în modul ales. Repornirea automată opțională recunoaște faze "
            L"vizibile statice sau exact repetate, inclusiv oscilatori. Compară generații, nu secunde; "
            L"exclude zonele invizibile. Rezultatele asincrone pot întârzia puțin repornirea. Implicit: "
            L"spațiere 8 px, 20 generații/s, culoare aleatorie a celulelor vii și repornire automată "
            L"activate. Grila este dezactivată implicit. Viteza atinsă depinde de performanță și de "
            L"numărul celulelor. Repornirea automată compară regiunile ecranelor activate; spațiile dintre "
            L"ele continuă să evolueze, dar sunt excluse din comparație.\r\n\r\nResetează "
            L"valorile\r\nResetarea stabilește dimensiunea afișată a celulei la 8 px cu sau fără grilă "
            L"(spațiere de 9 sau 8 px), viteza la 20 generații/s, densitatea la 25 % și cele trei culori "
            L"implicite. Celelalte alegeri se păstrează; un model care nu mai încape este înlocuit cu "
            L"amestecul. O scenă nouă apare numai dacă se schimbă spațierea sau densitatea în modul "
            L"zgomot.\r\n\r\nECONOMIZOR DE ECRAN WINDOWS\r\nGameOfLife.scr folosește toate ecranele, cu "
            L"setări separate de EXE. Activarea previzualizării pornește animația pe tot ecranul cu "
            L"setările deschise. Mica previzualizare Windows micșorează lumea întreagă. OK salvează; "
            L"Anulare sau Esc renunță la schimbări. Mișcarea mouse-ului sau o tastă închide economizorul "
            L"pe tot ecranul. Înregistrarea MP4 este disponibilă în EXE.\r\n\r\nPOZIȚIA ȘI STAREA "
            L"FERESTRELOR\r\nLa închidere se salvează separat pozițiile ferestrelor principală și Despre; "
            L"pentru Ajutor, și dimensiunea și starea normală sau maximizată dinaintea minimizării. Acest "
            L"lucru este independent de confirmarea setărilor aplicației. Ieșirea din aplicație închide și "
            L"Ajutor și Despre.\r\n\r\nRANDARE ȘI LICENȚELE MODELELOR\r\nEvoluția și comparațiile vizibile "
            L"folosesc shadere Direct3D 11 pe GPU; randarea software este disponibilă dacă inițializarea "
            L"hardware eșuează. Fiecare ecran folosește regulatorul de cadre verificat la rata sa. MP4 "
            L"necesită Media Foundation și un codor H.264. Modelele provin din LifeWiki (GFDL 1.2 sau "
            L"ulterioară) și colecțiile din domeniul public ale lui Alan Hensel. Codul are licență MIT; "
            L"notificările și licențele catalogului sunt separate."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Dimensiune celulă: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Viteză: %u generații/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Densitate inițială: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Repornește scena" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Culoarea celulelor vii…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Culoarea fundalului…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Ecranele alese împart o lume. Benzile goale dispar; golurile interioare rămân."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animația rulează…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animația este în pauză."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Modulul de randare Direct3D nu a putut fi inițializat."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Previzualizare" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Oprire previzualizare" },
        LocalizedText{ TXT_MONITOR,
            L"Monitor"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Rezoluție"
        },
        LocalizedText{ TXT_POSITION,
            L"Poziție"
        },
        LocalizedText{ TXT_PRIMARY,
            L"principal"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Model monitor"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Rată de reîmprospătare"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Adâncime de biți"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Format de culoare"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Spațiu de culoare"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u biți/canal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u biți/pixel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Monitor de animație"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Pregătit"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Afișare grilă"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Culoarea grilei…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Repornire automată a scenei vizibile stabile sau repetitive"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Doar modele cunoscute"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Pornire înregistrare…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Oprire înregistrare"
        },
        LocalizedText{ TXT_RECORDING,
            L"Înregistrare MP4 în curs…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Înregistrarea a fost salvată."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Înregistrarea MP4 nu a putut fi pornită."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Închiderea aplicației va opri înregistrarea în curs."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Setări de înregistrare"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Rezoluție:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Frecvența cadrelor:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Modificările se aplică următoarei înregistrări MP4."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Amestec de modele potrivite"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Modelul ales nu mai încape. A fost selectat un amestec potrivit."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Catalogul de modele cunoscute nu a putut fi încărcat."
        },
    }),
    DefineLanguage(LANG_EL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Τυχαίο χρώμα φόντου σε κάθε επανεκκίνηση της σκηνής" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Τυχαίο χρώμα πλέγματος σε κάθε επανεκκίνηση της σκηνής" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Προφύλαξη οθόνης Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Δεν είναι δυνατό το άνοιγμα των ρυθμίσεων προφύλαξης οθόνης των Windows."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Επαναφορά τιμών" },
        LocalizedText{ TXT_SNAPSHOT, L"Στιγμιότυπο…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Η εικόνα BMP/GIF/JPEG/PNG/TIFF/WebP αποθηκεύτηκε." },
        LocalizedText{ TXT_SNAPSHOT_FAILED,
            L"Δεν ήταν δυνατή η αποθήκευση της εικόνας BMP/GIF/JPEG/PNG/TIFF/WebP."
        },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Αναστολή προφύλαξης οθόνης κατά την κίνηση" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Τυχαίο χρώμα ζωντανών κελιών σε κάθε επανεκκίνηση της σκηνής"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Εγκατάσταση της προφύλαξης οθόνης σε εξέλιξη…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Κατάργηση της προφύλαξης οθόνης σε εξέλιξη…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Εγκατάσταση προφύλαξης οθόνης" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Κατάργηση προφύλαξης οθόνης" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Η προφύλαξη οθόνης δεν εγκαταστάθηκε." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Η προφύλαξη οθόνης εγκαταστάθηκε." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Η προφύλαξη οθόνης καταργήθηκε." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Δεν ήταν δυνατή η κατάργηση της προφύλαξης οθόνης. Κλείστε την και την προεπισκόπησή της και "
            L"δοκιμάστε ξανά."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Κλείστε το παράθυρο ρυθμίσεων του GameOfLife και δοκιμάστε ξανά την κατάργηση."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Κλείστε τις ρυθμίσεις προφύλαξης οθόνης των Windows και δοκιμάστε ξανά την κατάργηση."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Κλείστε την προφύλαξη ή την προεπισκόπηση πλήρους οθόνης με Esc ή κίνηση του ποντικιού και "
            L"δοκιμάστε ξανά."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Ελληνικά"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — χειρισμός"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Ρυθμίσεις GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Γλώσσα:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Άκυρο"
        },
        LocalizedText{ TXT_EXIT,
            L"Έξοδος"
        },
        LocalizedText{ TXT_PAUSE,
            L"Παύση"
        },
        LocalizedText{ TXT_RESUME,
            L"Συνέχιση"
        },
        LocalizedText{ TXT_HELP,
            L"Βοήθεια"
        },
        LocalizedText{ TXT_ABOUT,
            L"Πληροφορίες"
        },
        LocalizedText{ TXT_CLOSE,
            L"Κλείσιμο"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Άνοιγμα τοποθεσίας web %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Αδυναμία ανοίγματος του ιστοτόπου στον προεπιλεγμένο περιηγητή."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Δεν ήταν δυνατή η αντιγραφή του URL στο πρόχειρο."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Δεν ήταν δυνατή η αντιγραφή των πληροφοριών στο πρόχειρο."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Το Παιχνίδι της Ζωής του Conway σε κοινό κόσμο πολλών οθονών."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Έκδοση:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Πλατφόρμα προορισμού:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Τοποθεσία web:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Άνοιγμα στο προεπιλεγμένο πρόγραμμα περιήγησης"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Αντιγραφή &διεύθυνσης"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Αντιγραφή &πληροφοριών"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Ο πόρος άδειας χρήσης δεν είναι διαθέσιμος."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nΚΑΝΌΝΕΣ\r\nΤο Παιχνίδι της Ζωής του Conway χρησιμοποιεί B3/S23. Ένα νεκρό "
            L"κελί γεννιέται με ακριβώς τρεις ζωντανούς γείτονες· ένα ζωντανό επιβιώνει με δύο ή τρεις. Οι "
            L"οκτώ γείτονες περιλαμβάνουν τις διαγωνίους. Όλα αλλάζουν ταυτόχρονα. Οι απέναντι ακμές "
            L"ενώνονται: αριστερά με δεξιά, επάνω με κάτω.\r\n\r\nΟΘΌΝΕΣ ΚΑΙ ΚΟΙΝΌΣ ΚΌΣΜΟΣ\r\nΤα πλαίσια "
            L"στο EXE ενεργοποιούν οθόνες· οι ρυθμίσεις αφορούν τον κοινό κόσμο. Μία ενεργή οθόνη περιέχει "
            L"ολόκληρο τον κόσμο. Σε μερική επιλογή αφαιρούνται εντελώς κενές γραμμές και στήλες: αριστερή "
            L"και δεξιά οθόνη ενώνονται όταν απενεργοποιείται η μεσαία. Εσωτερικά κενά που δεν αφαιρούνται "
            L"παραμένουν στην προσομοίωση. Η επιλογή όλων των οθονών ή το SCR διατηρεί το ορθογώνιο της "
            L"επιφάνειας εργασίας μαζί με τα αόρατα κενά. Κάθε οθόνη δείχνει τη δική της περιοχή της ίδιας "
            L"προσομοίωσης.\r\n\r\nΑΡΧΙΚΉ ΚΑΤΆΣΤΑΣΗ ΚΑΙ ΜΟΤΊΒΑ\r\nΗ προεπιλεγμένη αρχή είναι τυχαίος "
            L"θόρυβος με 25 % ζωντανά κελιά. Η αρχική πυκνότητα 0–100 % εφαρμόζεται στην επόμενη "
            L"επανεκκίνηση. Μόνο γνωστά μοτίβα χρησιμοποιεί 4.106 ενσωματωμένα μοτίβα χωρίς θόρυβο και "
            L"απενεργοποιεί την πυκνότητα. Επιλέξτε μείγμα ή όνομα· οι διαστάσεις είναι σε κελιά. "
            L"Πληκτρολογήστε για αναζήτηση. Προσφέρονται μόνο όσα χωρούν ολόκληρα. Μικρά ελεγμένα μοτίβα "
            L"επαναλαμβάνονται σε χωριστά αντίγραφα, μεγάλα ή σύνθετα μία φορά στο κέντρο. Η σμίκρυνση "
            L"μπορεί να αντικαταστήσει υπερβολικά μεγάλη επιλογή με μείγμα. Αλλαγή λειτουργίας ή μοτίβου "
            L"δημιουργεί νέα σκηνή. Οι επανεκκινήσεις κρατούν την επιλογή· ο κατάλογος λειτουργεί εκτός "
            L"σύνδεσης.\r\n\r\nΚΕΛΙΆ, ΠΛΈΓΜΑ ΚΑΙ ΧΡΏΜΑΤΑ\r\nΧωρίς πλέγμα το μέγεθος είναι 1–64 px. Το "
            L"πλέγμα προσθέτει ακμή 1 px μέσα στην υπάρχουσα απόσταση: η ένδειξη και το ρυθμιστικό "
            L"μειώνονται κατά ένα, με διαθέσιμα 1–63. Η απενεργοποίηση επαναφέρει την τιμή. Το ρυθμιστικό "
            L"κρατά το εύρος του και επιστρέφει από το μη διαθέσιμο άκρο· το πλαίσιο παραμένει ενεργό. Η "
            L"εναλλαγή κρατά τη σκηνή, εκτός ενεργοποίησης στο 1 px: η απόσταση γίνεται 2 px και αρχίζει "
            L"νέα σκηνή. Αλλαγή μεγέθους ή οθονών επίσης ξεκινά ξανά. Πολύ μεγάλοι κόσμοι ίσως απαιτούν "
            L"υψηλότερο ελάχιστο. Τα χρώματα κελιών, φόντου και πλέγματος αλλάζουν χωριστά χωρίς "
            L"επανεκκίνηση. Το τυχαίο χρώμα ζωντανών κελιών αλλάζει σε κάθε χειροκίνητη ή αυτόματη "
            L"επανεκκίνηση της σκηνής. Το αποθηκευμένο χρώμα διατηρείται και επανέρχεται όταν "
            L"απενεργοποιηθεί η επιλογή. Η ίδια συμπεριφορά μπορεί να ενεργοποιηθεί χωριστά για φόντο και "
            L"πλέγμα· οι δύο νέες επιλογές είναι αρχικά απενεργοποιημένες.\r\n\r\nΤΑΧΎΤΗΤΑ, ΠΑΎΣΗ ΚΑΙ "
            L"ΑΥΤΌΜΑΤΗ ΕΠΑΝΕΚΚΊΝΗΣΗ\r\nΗ ταχύτητα είναι 0–240 γενιές/δευτερόλεπτο, ανεξάρτητα από την "
            L"ανανέωση· το 0 σταματά την εξέλιξη. Παύση και Συνέχιση κρατούν τον κόσμο. Επανεκκίνηση "
            L"ξεκινά στην επιλεγμένη λειτουργία. Η προαιρετική αυτόματη επανεκκίνηση αναγνωρίζει στατικές "
            L"ή ακριβώς επαναλαμβανόμενες ορατές φάσεις, μαζί με ταλαντωτές. Συγκρίνει γενιές, όχι "
            L"δευτερόλεπτα· εξαιρεί αόρατες περιοχές. Τα ασύγχρονα αποτελέσματα ίσως καθυστερήσουν λίγο "
            L"την επανεκκίνηση. Προεπιλογές: απόσταση 8 px, 20 γενιές/δ, τυχαίο χρώμα ζωντανών κελιών και "
            L"αυτόματη επανεκκίνηση ενεργά. Το πλέγμα είναι απενεργοποιημένο από προεπιλογή. Η ταχύτητα "
            L"που επιτυγχάνεται εξαρτάται από την απόδοση και τον αριθμό κελιών. Η αυτόματη επανεκκίνηση "
            L"συγκρίνει τις περιοχές των ενεργών οθονών· τα κενά ανάμεσά τους εξελίσσονται αλλά "
            L"εξαιρούνται από τη σύγκριση.\r\n\r\nΕπαναφορά τιμών\r\nΗ επαναφορά ορίζει το εμφανιζόμενο "
            L"μέγεθος κελιού σε 8 px με ή χωρίς πλέγμα (απόσταση 9 ή 8 px), την ταχύτητα σε 20 γενιές/δ, "
            L"την πυκνότητα σε 25 % και τα τρία προεπιλεγμένα χρώματα. Οι άλλες επιλογές διατηρούνται· ένα "
            L"μοτίβο που δεν χωρά πλέον αντικαθίσταται από το μείγμα. Νέα σκηνή δημιουργείται μόνο αν "
            L"αλλάξει η απόσταση ή η πυκνότητα στη λειτουργία θορύβου.\r\n\r\nΑΥΤΌΝΟΜΗ ΕΦΑΡΜΟΓΉ ΚΑΙ "
            L"ΕΓΓΡΑΦΉ MP4\r\nΤο EXE αποθηκεύει συνεχώς ρυθμίσεις και γράφει την πρώτη ενεργή οθόνη σε MP4. "
            L"Προτείνει Βίντεο, εναλλακτικά Έγγραφα. Το Viewport χρησιμοποιεί διαστάσεις και ανανέωση "
            L"οθόνης έως 60 καρέ/δ. Το TV προσφέρει 1920 × 1080, 1440 × 1080 ή 1280 × 720 σε 16:9 με 50, "
            L"25, 59,94 (60000/1001) ή 29,97 (30000/1001) καρέ/δ. Η αναλογία διατηρείται· το TV "
            L"χρησιμοποιεί προοδευτικό BT.709 περιορισμένου εύρους και 4:2:0. Το ανεξάρτητο παράθυρο "
            L"ρυθμίσεων ελαχιστοποιείται. OK αποθηκεύει για την επόμενη εγγραφή· Άκυρο ή Esc απορρίπτει μη "
            L"επιβεβαιωμένες αλλαγές. Η εγγραφόμενη οθόνη δεν απενεργοποιείται· οι άλλες έξοδοι αλλάζουν. "
            L"Η έξοδος κατά την εγγραφή απαιτεί επιβεβαίωση. Με ενεργή την κινούμενη εικόνα, Διάστημα "
            L"αλλάζει την παύση, F9: Έναρξη εγγραφής; F10: Διακοπή εγγραφής. Ο δείκτης κρύβεται μετά από 1 "
            L"δευτερόλεπτο αδράνειας και επανέρχεται με κίνηση. Tab/Shift+Tab αλλάζει στοιχείο· Alt "
            L"ενεργοποιεί υπογραμμισμένες εντολές. Esc κλείνει Βοήθεια/Πληροφορίες ή τερματίζει στο κύριο "
            L"παράθυρο.\r\n\r\nΣΤΙΓΜΙΟΤΥΠΟ ΚΑΙ ΔΙΑΧΕΙΡΙΣΗ ΠΡΟΦΥΛΑΞΗΣ ΟΘΟΝΗΣ ΣΤΟ EXE\r\nΤο στιγμιότυπο "
            L"αποθηκεύει BMP/GIF/JPEG/PNG/TIFF/WebP της οθόνης που καταγράφεται ή αλλιώς της πρώτης ενεργής, "
            L"στην ανάλυσή της "
            L"χωρίς επανεκκίνηση της σκηνής. Προτείνεται ο φάκελος Εικόνες, εναλλακτικά Έγγραφα. Ο "
            L"αποκλεισμός προφύλαξης κατά την κινούμενη εικόνα αποτρέπει την εκκίνησή της όσο η εικόνα "
            L"είναι ορατή και δεν είναι σε παύση. Μηδενική ταχύτητα δεν σημαίνει παύση. Η εγκατάσταση από "
            L"το EXE αποσυμπιέζει το ενσωματωμένο SCR και το επιλέγει ως προφύλαξη οθόνης Windows. "
            L"Εγκατάσταση και απεγκατάσταση μπορεί να απαιτούν έγκριση διαχειριστή· η γραμμή κατάστασης "
            L"δείχνει την εργασία έως την ολοκλήρωσή της. Αν η αφαίρεση εμποδίζεται, κλείστε την ενεργή "
            L"προφύλαξη, τις ρυθμίσεις της και την προεπισκόπηση Windows.\r\n\r\nΠΡΟΦΎΛΑΞΗ ΟΘΌΝΗΣ "
            L"WINDOWS\r\nΤο GameOfLife.scr χρησιμοποιεί όλες τις οθόνες και ξεχωριστές ρυθμίσεις από το "
            L"EXE. Η προεπισκόπηση ξεκινά πλήρη οθόνη με ανοιχτές ρυθμίσεις. Η μικρή προεπισκόπηση Windows "
            L"μικραίνει ολόκληρο τον κόσμο. OK αποθηκεύει· Άκυρο ή Esc απορρίπτει αλλαγές. Κίνηση "
            L"ποντικιού ή πλήκτρο κλείνει την προφύλαξη πλήρους οθόνης. Η εγγραφή MP4 είναι διαθέσιμη στο "
            L"EXE.\r\n\r\nΘΕΣΗ ΚΑΙ ΚΑΤΑΣΤΑΣΗ ΠΑΡΑΘΥΡΩΝ\r\nΣτο κλείσιμο αποθηκεύονται χωριστά οι θέσεις του "
            L"κύριου παραθύρου και των Πληροφοριών· για τη Βοήθεια επίσης το μέγεθος και η κανονική ή "
            L"μεγιστοποιημένη κατάσταση πριν από ελαχιστοποίηση. Αυτό είναι ανεξάρτητο από την επιβεβαίωση "
            L"ρυθμίσεων εφαρμογής. Η έξοδος κλείνει επίσης Βοήθεια και Πληροφορίες.\r\n\r\nΑΠΌΔΟΣΗ ΚΑΙ "
            L"ΆΔΕΙΕΣ ΜΟΤΊΒΩΝ\r\nΗ εξέλιξη και οι ορατές συγκρίσεις χρησιμοποιούν shaders Direct3D 11 στη "
            L"GPU· υπάρχει απόδοση λογισμικού αν αποτύχει η αρχικοποίηση υλικού. Κάθε οθόνη χρησιμοποιεί "
            L"τον δοκιμασμένο χρονισμό καρέ στη συχνότητά της. Το MP4 απαιτεί Media Foundation και "
            L"κωδικοποιητή H.264. Τα μοτίβα προέρχονται από LifeWiki (GFDL 1.2 ή νεότερη) και τις συλλογές "
            L"δημόσιου τομέα του Alan Hensel. Ο κώδικας έχει άδεια MIT· οι γνωστοποιήσεις και άδειες του "
            L"καταλόγου είναι ξεχωριστές.\r\n\r\nΤο Προφύλαξη οθόνης Windows… ανοίγει τις ρυθμίσεις "
            L"προφύλαξης οθόνης του συστήματος."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nΚΑΝΌΝΕΣ\r\nΤο Παιχνίδι της Ζωής του Conway χρησιμοποιεί B3/S23. Ένα νεκρό "
            L"κελί γεννιέται με ακριβώς τρεις ζωντανούς γείτονες· ένα ζωντανό επιβιώνει με δύο ή τρεις. Οι "
            L"οκτώ γείτονες περιλαμβάνουν τις διαγωνίους. Όλα αλλάζουν ταυτόχρονα. Οι απέναντι ακμές "
            L"ενώνονται: αριστερά με δεξιά, επάνω με κάτω.\r\n\r\nΟΘΌΝΕΣ ΚΑΙ ΚΟΙΝΌΣ ΚΌΣΜΟΣ\r\nΤα πλαίσια "
            L"στο EXE ενεργοποιούν οθόνες· οι ρυθμίσεις αφορούν τον κοινό κόσμο. Μία ενεργή οθόνη περιέχει "
            L"ολόκληρο τον κόσμο. Σε μερική επιλογή αφαιρούνται εντελώς κενές γραμμές και στήλες: αριστερή "
            L"και δεξιά οθόνη ενώνονται όταν απενεργοποιείται η μεσαία. Εσωτερικά κενά που δεν αφαιρούνται "
            L"παραμένουν στην προσομοίωση. Η επιλογή όλων των οθονών ή το SCR διατηρεί το ορθογώνιο της "
            L"επιφάνειας εργασίας μαζί με τα αόρατα κενά. Κάθε οθόνη δείχνει τη δική της περιοχή της ίδιας "
            L"προσομοίωσης.\r\n\r\nΑΡΧΙΚΉ ΚΑΤΆΣΤΑΣΗ ΚΑΙ ΜΟΤΊΒΑ\r\nΗ προεπιλεγμένη αρχή είναι τυχαίος "
            L"θόρυβος με 25 % ζωντανά κελιά. Η αρχική πυκνότητα 0–100 % εφαρμόζεται στην επόμενη "
            L"επανεκκίνηση. Μόνο γνωστά μοτίβα χρησιμοποιεί 4.106 ενσωματωμένα μοτίβα χωρίς θόρυβο και "
            L"απενεργοποιεί την πυκνότητα. Επιλέξτε μείγμα ή όνομα· οι διαστάσεις είναι σε κελιά. "
            L"Πληκτρολογήστε για αναζήτηση. Προσφέρονται μόνο όσα χωρούν ολόκληρα. Μικρά ελεγμένα μοτίβα "
            L"επαναλαμβάνονται σε χωριστά αντίγραφα, μεγάλα ή σύνθετα μία φορά στο κέντρο. Η σμίκρυνση "
            L"μπορεί να αντικαταστήσει υπερβολικά μεγάλη επιλογή με μείγμα. Αλλαγή λειτουργίας ή μοτίβου "
            L"δημιουργεί νέα σκηνή. Οι επανεκκινήσεις κρατούν την επιλογή· ο κατάλογος λειτουργεί εκτός "
            L"σύνδεσης.\r\n\r\nΚΕΛΙΆ, ΠΛΈΓΜΑ ΚΑΙ ΧΡΏΜΑΤΑ\r\nΧωρίς πλέγμα το μέγεθος είναι 1–64 px. Το "
            L"πλέγμα προσθέτει ακμή 1 px μέσα στην υπάρχουσα απόσταση: η ένδειξη και το ρυθμιστικό "
            L"μειώνονται κατά ένα, με διαθέσιμα 1–63. Η απενεργοποίηση επαναφέρει την τιμή. Το ρυθμιστικό "
            L"κρατά το εύρος του και επιστρέφει από το μη διαθέσιμο άκρο· το πλαίσιο παραμένει ενεργό. Η "
            L"εναλλαγή κρατά τη σκηνή, εκτός ενεργοποίησης στο 1 px: η απόσταση γίνεται 2 px και αρχίζει "
            L"νέα σκηνή. Αλλαγή μεγέθους ή οθονών επίσης ξεκινά ξανά. Πολύ μεγάλοι κόσμοι ίσως απαιτούν "
            L"υψηλότερο ελάχιστο. Τα χρώματα κελιών, φόντου και πλέγματος αλλάζουν χωριστά χωρίς "
            L"επανεκκίνηση. Το τυχαίο χρώμα ζωντανών κελιών αλλάζει σε κάθε χειροκίνητη ή αυτόματη "
            L"επανεκκίνηση της σκηνής. Το αποθηκευμένο χρώμα διατηρείται και επανέρχεται όταν "
            L"απενεργοποιηθεί η επιλογή. Η ίδια συμπεριφορά μπορεί να ενεργοποιηθεί χωριστά για φόντο και "
            L"πλέγμα· οι δύο νέες επιλογές είναι αρχικά απενεργοποιημένες.\r\n\r\nΤΑΧΎΤΗΤΑ, ΠΑΎΣΗ ΚΑΙ "
            L"ΑΥΤΌΜΑΤΗ ΕΠΑΝΕΚΚΊΝΗΣΗ\r\nΗ ταχύτητα είναι 0–240 γενιές/δευτερόλεπτο, ανεξάρτητα από την "
            L"ανανέωση· το 0 σταματά την εξέλιξη. Παύση και Συνέχιση κρατούν τον κόσμο. Επανεκκίνηση "
            L"ξεκινά στην επιλεγμένη λειτουργία. Η προαιρετική αυτόματη επανεκκίνηση αναγνωρίζει στατικές "
            L"ή ακριβώς επαναλαμβανόμενες ορατές φάσεις, μαζί με ταλαντωτές. Συγκρίνει γενιές, όχι "
            L"δευτερόλεπτα· εξαιρεί αόρατες περιοχές. Τα ασύγχρονα αποτελέσματα ίσως καθυστερήσουν λίγο "
            L"την επανεκκίνηση. Προεπιλογές: απόσταση 8 px, 20 γενιές/δ, τυχαίο χρώμα ζωντανών κελιών και "
            L"αυτόματη επανεκκίνηση ενεργά. Το πλέγμα είναι απενεργοποιημένο από προεπιλογή. Η ταχύτητα "
            L"που επιτυγχάνεται εξαρτάται από την απόδοση και τον αριθμό κελιών. Η αυτόματη επανεκκίνηση "
            L"συγκρίνει τις περιοχές των ενεργών οθονών· τα κενά ανάμεσά τους εξελίσσονται αλλά "
            L"εξαιρούνται από τη σύγκριση.\r\n\r\nΕπαναφορά τιμών\r\nΗ επαναφορά ορίζει το εμφανιζόμενο "
            L"μέγεθος κελιού σε 8 px με ή χωρίς πλέγμα (απόσταση 9 ή 8 px), την ταχύτητα σε 20 γενιές/δ, "
            L"την πυκνότητα σε 25 % και τα τρία προεπιλεγμένα χρώματα. Οι άλλες επιλογές διατηρούνται· ένα "
            L"μοτίβο που δεν χωρά πλέον αντικαθίσταται από το μείγμα. Νέα σκηνή δημιουργείται μόνο αν "
            L"αλλάξει η απόσταση ή η πυκνότητα στη λειτουργία θορύβου.\r\n\r\nΠΡΟΦΎΛΑΞΗ ΟΘΌΝΗΣ "
            L"WINDOWS\r\nΤο GameOfLife.scr χρησιμοποιεί όλες τις οθόνες και ξεχωριστές ρυθμίσεις από το "
            L"EXE. Η προεπισκόπηση ξεκινά πλήρη οθόνη με ανοιχτές ρυθμίσεις. Η μικρή προεπισκόπηση Windows "
            L"μικραίνει ολόκληρο τον κόσμο. OK αποθηκεύει· Άκυρο ή Esc απορρίπτει αλλαγές. Κίνηση "
            L"ποντικιού ή πλήκτρο κλείνει την προφύλαξη πλήρους οθόνης. Η εγγραφή MP4 είναι διαθέσιμη στο "
            L"EXE.\r\n\r\nΘΕΣΗ ΚΑΙ ΚΑΤΑΣΤΑΣΗ ΠΑΡΑΘΥΡΩΝ\r\nΣτο κλείσιμο αποθηκεύονται χωριστά οι θέσεις του "
            L"κύριου παραθύρου και των Πληροφοριών· για τη Βοήθεια επίσης το μέγεθος και η κανονική ή "
            L"μεγιστοποιημένη κατάσταση πριν από ελαχιστοποίηση. Αυτό είναι ανεξάρτητο από την επιβεβαίωση "
            L"ρυθμίσεων εφαρμογής. Η έξοδος κλείνει επίσης Βοήθεια και Πληροφορίες.\r\n\r\nΑΠΌΔΟΣΗ ΚΑΙ "
            L"ΆΔΕΙΕΣ ΜΟΤΊΒΩΝ\r\nΗ εξέλιξη και οι ορατές συγκρίσεις χρησιμοποιούν shaders Direct3D 11 στη "
            L"GPU· υπάρχει απόδοση λογισμικού αν αποτύχει η αρχικοποίηση υλικού. Κάθε οθόνη χρησιμοποιεί "
            L"τον δοκιμασμένο χρονισμό καρέ στη συχνότητά της. Το MP4 απαιτεί Media Foundation και "
            L"κωδικοποιητή H.264. Τα μοτίβα προέρχονται από LifeWiki (GFDL 1.2 ή νεότερη) και τις συλλογές "
            L"δημόσιου τομέα του Alan Hensel. Ο κώδικας έχει άδεια MIT· οι γνωστοποιήσεις και άδειες του "
            L"καταλόγου είναι ξεχωριστές."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Μέγεθος κελιού: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Ταχύτητα: %u γενιές/δ"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Αρχική πυκνότητα: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Επανεκκίνηση σκηνής" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Χρώμα ζωντανών κελιών…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Χρώμα φόντου…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Οι επιλεγμένες οθόνες μοιράζονται έναν κόσμο. Οι κενές λωρίδες αφαιρούνται, τα εσωτερικά κενά "
            L"μένουν."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Η κίνηση εκτελείται…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Η κίνηση έχει παύσει."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Δεν ήταν δυνατή η αρχικοποίηση του αποδότη Direct3D."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Προεπισκόπηση"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Τέλος προεπισκόπησης"
        },
        LocalizedText{ TXT_MONITOR,
            L"Οθόνη"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Ανάλυση"
        },
        LocalizedText{ TXT_POSITION,
            L"Θέση"
        },
        LocalizedText{ TXT_PRIMARY,
            L"κύρια"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Μοντέλο οθόνης"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Ρυθμός ανανέωσης"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Βάθος bit"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Μορφή χρώματος"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Χρωματικός χώρος"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bit/κανάλι"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bit/pixel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Οθόνη κίνησης"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Έτοιμο"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Εμφάνιση πλέγματος"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Χρώμα πλέγματος…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Αυτόματη επανεκκίνηση σταθερής ή επαναλαμβανόμενης ορατής σκηνής"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Μόνο γνωστά μοτίβα"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Έναρξη εγγραφής…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Διακοπή εγγραφής"
        },
        LocalizedText{ TXT_RECORDING,
            L"Εγγραφή MP4 σε εξέλιξη…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Η εγγραφή αποθηκεύτηκε."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Δεν ήταν δυνατή η έναρξη εγγραφής MP4."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Το κλείσιμο της εφαρμογής θα διακόψει την εγγραφή που βρίσκεται σε εξέλιξη."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Ρυθμίσεις εγγραφής"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Ανάλυση:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Ρυθμός καρέ:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Οι αλλαγές ισχύουν για την επόμενη εγγραφή MP4."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Μείγμα κατάλληλων μοτίβων"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Το επιλεγμένο μοτίβο δεν χωρά πλέον. Επιλέχθηκε κατάλληλο μείγμα."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Δεν ήταν δυνατή η φόρτωση του καταλόγου γνωστών μοτίβων."
        },
    }),
    DefineLanguage(LANG_BS, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Nasumična boja pozadine pri svakom ponovnom pokretanju scene"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Nasumična boja mreže pri svakom ponovnom pokretanju scene" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Čuvar ekrana u Windowsu…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Nije moguće otvoriti postavke čuvara ekrana u Windowsu."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Vrati vrijednosti" },
        LocalizedText{ TXT_SNAPSHOT, L"Snimak…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"BMP/GIF/JPEG/PNG/TIFF/WebP slika je sačuvana." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Nije moguće sačuvati BMP/GIF/JPEG/PNG/TIFF/WebP sliku." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Spriječi čuvar ekrana tokom animacije" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Nasumična boja živih ćelija pri svakom ponovnom pokretanju scene"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Instalacija čuvara ekrana je u toku…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Deinstalacija čuvara ekrana je u toku…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Instaliraj čuvar ekrana" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Deinstaliraj čuvar ekrana" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Čuvar ekrana nije instaliran." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Čuvar ekrana je instaliran." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Čuvar ekrana je deinstaliran." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Nije moguće deinstalirati čuvar ekrana. Zatvorite čuvar i njegov pregled pa pokušajte ponovo."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Zatvorite postavke programa GameOfLife pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zatvorite Windows postavke čuvara ekrana pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zatvorite čuvar ili pregled preko cijelog ekrana tipkom Esc ili pomjeranjem miša pa ponovite "
            L"deinstalaciju."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Bosanski"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — kontrole"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Postavke programa GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Jezik:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Otkaži"
        },
        LocalizedText{ TXT_EXIT,
            L"Izlaz"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pauziraj"
        },
        LocalizedText{ TXT_RESUME,
            L"Nastavi"
        },
        LocalizedText{ TXT_HELP,
            L"Pomoć"
        },
        LocalizedText{ TXT_ABOUT,
            L"O programu"
        },
        LocalizedText{ TXT_CLOSE,
            L"Zatvori"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Posjeti web-mjesto %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Nije moguće otvoriti stranicu u podrazumijevanom pregledniku."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Nije moguće kopirati URL u međuspremnik."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Nije moguće kopirati informacije u međuspremnik."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conwayjeva Igra života u zajedničkom svijetu na više monitora."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Verzija:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Ciljna platforma:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Web-mjesto:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Otvori u podrazumijevanom pregledniku"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Kopiraj &adresu"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Kopiraj &informacije"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Resurs licence nije dostupan."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nPRAVILA\r\nConwayjeva Igra života koristi B3/S23. Mrtva ćelija oživi uz "
            L"tačno tri živa susjeda; živa preživi uz dva ili tri. Osam susjeda uključuje dijagonale. Sve "
            L"ćelije mijenjaju se istovremeno. Suprotne ivice se spajaju: lijeva s desnom, gornja s "
            L"donjom.\r\n\r\nMONITORI I ZAJEDNIČKI SVIJET\r\nKućice u EXE uključuju monitore; postavke "
            L"važe za zajednički svijet. Jedan uključen monitor sadrži cijeli svijet. Pri odabiru dijela "
            L"rasporeda potpuno prazni redovi i kolone se uklanjaju: lijevi i desni monitor spoje se nakon "
            L"isključivanja srednjeg. Unutrašnje rupe koje se ne mogu ukloniti ostaju u simulaciji. Odabir "
            L"svih monitora ili SCR zadržava pravougaonik radne površine s nevidljivim prazninama. Svaki "
            L"monitor prikazuje svoj dio iste simulacije.\r\n\r\nPOČETNO STANJE I "
            L"OBRASCI\r\nPodrazumijevani početak je nasumični šum s 25 % živih ćelija. Početna gustoća "
            L"0–100 % primjenjuje se pri sljedećem ponovnom pokretanju. Samo poznati obrasci koristi 4.106 "
            L"priloženih obrazaca bez šuma i isključuje gustoću. Odaberite mješavinu ili naziv; dimenzije "
            L"su u ćelijama. Kucajte naziv za pretragu. Nude se samo obrasci koji stanu cijeli. Mali "
            L"provjereni obrasci ponavljaju se u odvojenim kopijama, veliki ili složeni jednom u sredini. "
            L"Smanjenje svijeta može prevelik izbor zamijeniti mješavinom. Promjena režima ili obrasca "
            L"stvara novu scenu. Ponovna pokretanja čuvaju izbor; katalog radi bez "
            L"interneta.\r\n\r\nĆELIJE, MREŽA I BOJE\r\nBez mreže veličina ćelije je 1–64 px. Mreža dodaje "
            L"ivicu od 1 px unutar postojećeg razmaka: prikaz i klizač smanjuju se za jedan, dostupno je "
            L"1–63. Isključivanje vraća vrijednost. Klizač zadržava raspon i vraća se s nedostupnog kraja; "
            L"kućica ostaje aktivna. Prebacivanje čuva scenu, osim uključivanja na 1 px: razmak postaje 2 "
            L"px i scena počinje iznova. Promjena veličine ili monitora također počinje iznova. Vrlo velik "
            L"svijet može zahtijevati veći minimum. Boje ćelija, pozadine i mreže mijenjaju se zasebno bez "
            L"ponovnog pokretanja. Nasumična boja živih ćelija bira novu boju pri svakom ručnom ili "
            L"automatskom ponovnom pokretanju scene. Sačuvana boja ostaje i vraća se nakon isključivanja "
            L"ove opcije. Isto ponašanje može se zasebno uključiti za pozadinu i mrežu; obje nove opcije "
            L"su podrazumijevano isključene.\r\n\r\nBRZINA, PAUZA I AUTOMATSKO PONOVNO "
            L"POKRETANJE\r\nBrzina je 0–240 generacija/s nezavisno od osvježavanja; 0 zaustavlja razvoj. "
            L"Pauza i Nastavi čuvaju svijet. Pokreni ponovo počinje u odabranom režimu. Neobavezno "
            L"automatsko ponovno pokretanje prepoznaje statične i tačno ponovljene vidljive faze, "
            L"uključujući oscilatore. Poredi generacije, ne sekunde; nevidljiva područja se izostavljaju. "
            L"Asinhroni rezultati mogu malo odgoditi ponovno pokretanje. Podrazumijevano: razmak 8 px, 20 "
            L"generacija/s, nasumična boja živih ćelija i automatsko ponovno pokretanje uključeni. Mreža "
            L"je podrazumijevano isključena. Postignuta brzina zavisi od performansi i broja ćelija. "
            L"Automatsko ponovno pokretanje poredi područja uključenih monitora; praznine se i dalje "
            L"razvijaju, ali se ne uključuju u poređenje.\r\n\r\nVrati vrijednosti\r\nVraćanje postavlja "
            L"prikazanu veličinu ćelije na 8 px s mrežom ili bez nje (razmak 9 ili 8 px), brzinu na 20 "
            L"generacija/s, gustoću na 25 % i tri podrazumijevane boje. Ostali izbori ostaju; obrazac koji "
            L"više ne staje zamjenjuje se mješavinom. Nova scena nastaje samo pri promjeni razmaka ili "
            L"gustoće u režimu šuma.\r\n\r\nSAMOSTALNA APLIKACIJA I MP4 SNIMANJE\r\nEXE stalno čuva "
            L"postavke i snima prvi aktivni monitor u MP4. Predlaže Videozapise, inače Dokumente. Viewport "
            L"koristi dimenzije i osvježavanje monitora do 60 kadrova/s. TV nudi 1920 × 1080, 1440 × 1080 "
            L"ili 1280 × 720 u 16:9 pri 50, 25, 59,94 (60000/1001) ili 29,97 (30000/1001) kadrova/s. Omjer "
            L"se čuva; TV koristi progresivni BT.709 s ograničenim rasponom i 4:2:0. Zaseban prozor "
            L"postavki može se minimizirati. U redu čuva za sljedeće snimanje; Odustani ili Esc odbacuje "
            L"nepotvrđene izmjene. Snimani monitor ne može se isključiti; ostali izlazi mogu se mijenjati. "
            L"Izlaz tokom snimanja traži potvrdu. Kada je animacija u fokusu, Razmak mijenja pauzu, F9: "
            L"Pokreni snimanje; F10: Zaustavi snimanje. Pokazivač nestaje nakon 1 sekunde mirovanja i "
            L"vraća se pomjeranjem. Tab/Shift+Tab prelazi između kontrola; Alt aktivira podvučene naredbe. "
            L"Esc zatvara Pomoć/O programu ili izlazi iz glavnog prozora.\r\n\r\nSNIMAK SLIKE I "
            L"UPRAVLJANJE ČUVAROM U EXE\r\nSnimak slike čuva BMP/GIF/JPEG/PNG/TIFF/WebP monitora koji se "
            L"snima, inače prvog "
            L"aktivnog, u njegovoj rezoluciji bez ponovnog pokretanja scene. Predlaže mapu Slike, inače "
            L"Dokumenti. Blokiranje čuvara tokom animacije sprečava njegovo pokretanje dok je animacija "
            L"vidljiva i nije pauzirana. Nulta brzina nije pauza. Instalacija iz EXE raspakuje priloženi "
            L"SCR i bira ga kao Windows čuvar ekrana. Instalacija i deinstalacija mogu tražiti odobrenje "
            L"administratora; statusna traka prikazuje radnju do završetka. Ako je uklanjanje blokirano, "
            L"zatvorite pokrenuti čuvar, njegove postavke i Windows pregled.\r\n\r\nWINDOWS ČUVAR "
            L"EKRANA\r\nGameOfLife.scr koristi sve monitore i postavke odvojene od EXE. Pregled pokreće "
            L"animaciju preko cijelog ekrana uz otvorene postavke. Mali Windows pregled smanjuje cijeli "
            L"svijet. U redu čuva; Odustani ili Esc odbacuje izmjene. Pomjeranje miša ili tipka zatvara "
            L"čuvar preko cijelog ekrana. MP4 snimanje je dostupno u EXE.\r\n\r\nPOLOŽAJ I STANJE "
            L"PROZORA\r\nPri zatvaranju se zasebno čuvaju položaji glavnog prozora i prozora O programu; "
            L"za Pomoć i veličina te normalno ili maksimizirano stanje prije minimiziranja. To ne zavisi "
            L"od potvrđivanja postavki aplikacije. Zatvaranje aplikacije zatvara i Pomoć i O "
            L"programu.\r\n\r\nISCRTAVANJE I LICENCE OBRAZACA\r\nRazvoj i poređenje vidljivih stanja "
            L"koriste Direct3D 11 shadere na GPU-u; softversko iscrtavanje je dostupno ako hardverska "
            L"inicijalizacija ne uspije. Svaki monitor koristi provjereni regulator kadrova pri vlastitom "
            L"osvježavanju. MP4 zahtijeva Media Foundation i H.264 koder. Obrasci dolaze s LifeWiki (GFDL "
            L"1.2 ili novija) i iz zbirki Alana Hensela u javnom vlasništvu. Programski kod ima MIT "
            L"licencu; obavještenja i licence kataloga su odvojeni.\r\n\r\nČuvar ekrana u Windowsu… otvara "
            L"sistemske postavke čuvara ekrana."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nPRAVILA\r\nConwayjeva Igra života koristi B3/S23. Mrtva ćelija oživi uz "
            L"tačno tri živa susjeda; živa preživi uz dva ili tri. Osam susjeda uključuje dijagonale. Sve "
            L"ćelije mijenjaju se istovremeno. Suprotne ivice se spajaju: lijeva s desnom, gornja s "
            L"donjom.\r\n\r\nMONITORI I ZAJEDNIČKI SVIJET\r\nKućice u EXE uključuju monitore; postavke "
            L"važe za zajednički svijet. Jedan uključen monitor sadrži cijeli svijet. Pri odabiru dijela "
            L"rasporeda potpuno prazni redovi i kolone se uklanjaju: lijevi i desni monitor spoje se nakon "
            L"isključivanja srednjeg. Unutrašnje rupe koje se ne mogu ukloniti ostaju u simulaciji. Odabir "
            L"svih monitora ili SCR zadržava pravougaonik radne površine s nevidljivim prazninama. Svaki "
            L"monitor prikazuje svoj dio iste simulacije.\r\n\r\nPOČETNO STANJE I "
            L"OBRASCI\r\nPodrazumijevani početak je nasumični šum s 25 % živih ćelija. Početna gustoća "
            L"0–100 % primjenjuje se pri sljedećem ponovnom pokretanju. Samo poznati obrasci koristi 4.106 "
            L"priloženih obrazaca bez šuma i isključuje gustoću. Odaberite mješavinu ili naziv; dimenzije "
            L"su u ćelijama. Kucajte naziv za pretragu. Nude se samo obrasci koji stanu cijeli. Mali "
            L"provjereni obrasci ponavljaju se u odvojenim kopijama, veliki ili složeni jednom u sredini. "
            L"Smanjenje svijeta može prevelik izbor zamijeniti mješavinom. Promjena režima ili obrasca "
            L"stvara novu scenu. Ponovna pokretanja čuvaju izbor; katalog radi bez "
            L"interneta.\r\n\r\nĆELIJE, MREŽA I BOJE\r\nBez mreže veličina ćelije je 1–64 px. Mreža dodaje "
            L"ivicu od 1 px unutar postojećeg razmaka: prikaz i klizač smanjuju se za jedan, dostupno je "
            L"1–63. Isključivanje vraća vrijednost. Klizač zadržava raspon i vraća se s nedostupnog kraja; "
            L"kućica ostaje aktivna. Prebacivanje čuva scenu, osim uključivanja na 1 px: razmak postaje 2 "
            L"px i scena počinje iznova. Promjena veličine ili monitora također počinje iznova. Vrlo velik "
            L"svijet može zahtijevati veći minimum. Boje ćelija, pozadine i mreže mijenjaju se zasebno bez "
            L"ponovnog pokretanja. Nasumična boja živih ćelija bira novu boju pri svakom ručnom ili "
            L"automatskom ponovnom pokretanju scene. Sačuvana boja ostaje i vraća se nakon isključivanja "
            L"ove opcije. Isto ponašanje može se zasebno uključiti za pozadinu i mrežu; obje nove opcije "
            L"su podrazumijevano isključene.\r\n\r\nBRZINA, PAUZA I AUTOMATSKO PONOVNO "
            L"POKRETANJE\r\nBrzina je 0–240 generacija/s nezavisno od osvježavanja; 0 zaustavlja razvoj. "
            L"Pauza i Nastavi čuvaju svijet. Pokreni ponovo počinje u odabranom režimu. Neobavezno "
            L"automatsko ponovno pokretanje prepoznaje statične i tačno ponovljene vidljive faze, "
            L"uključujući oscilatore. Poredi generacije, ne sekunde; nevidljiva područja se izostavljaju. "
            L"Asinhroni rezultati mogu malo odgoditi ponovno pokretanje. Podrazumijevano: razmak 8 px, 20 "
            L"generacija/s, nasumična boja živih ćelija i automatsko ponovno pokretanje uključeni. Mreža "
            L"je podrazumijevano isključena. Postignuta brzina zavisi od performansi i broja ćelija. "
            L"Automatsko ponovno pokretanje poredi područja uključenih monitora; praznine se i dalje "
            L"razvijaju, ali se ne uključuju u poređenje.\r\n\r\nVrati vrijednosti\r\nVraćanje postavlja "
            L"prikazanu veličinu ćelije na 8 px s mrežom ili bez nje (razmak 9 ili 8 px), brzinu na 20 "
            L"generacija/s, gustoću na 25 % i tri podrazumijevane boje. Ostali izbori ostaju; obrazac koji "
            L"više ne staje zamjenjuje se mješavinom. Nova scena nastaje samo pri promjeni razmaka ili "
            L"gustoće u režimu šuma.\r\n\r\nWINDOWS ČUVAR EKRANA\r\nGameOfLife.scr koristi sve monitore i "
            L"postavke odvojene od EXE. Pregled pokreće animaciju preko cijelog ekrana uz otvorene "
            L"postavke. Mali Windows pregled smanjuje cijeli svijet. U redu čuva; Odustani ili Esc "
            L"odbacuje izmjene. Pomjeranje miša ili tipka zatvara čuvar preko cijelog ekrana. MP4 snimanje "
            L"je dostupno u EXE.\r\n\r\nPOLOŽAJ I STANJE PROZORA\r\nPri zatvaranju se zasebno čuvaju "
            L"položaji glavnog prozora i prozora O programu; za Pomoć i veličina te normalno ili "
            L"maksimizirano stanje prije minimiziranja. To ne zavisi od potvrđivanja postavki aplikacije. "
            L"Zatvaranje aplikacije zatvara i Pomoć i O programu.\r\n\r\nISCRTAVANJE I LICENCE "
            L"OBRAZACA\r\nRazvoj i poređenje vidljivih stanja koriste Direct3D 11 shadere na GPU-u; "
            L"softversko iscrtavanje je dostupno ako hardverska inicijalizacija ne uspije. Svaki monitor "
            L"koristi provjereni regulator kadrova pri vlastitom osvježavanju. MP4 zahtijeva Media "
            L"Foundation i H.264 koder. Obrasci dolaze s LifeWiki (GFDL 1.2 ili novija) i iz zbirki Alana "
            L"Hensela u javnom vlasništvu. Programski kod ima MIT licencu; obavještenja i licence kataloga "
            L"su odvojeni."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Veličina ćelije: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Brzina: %u generacija/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Početna gustoća: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Ponovo pokreni scenu" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Boja živih ćelija…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Boja pozadine…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Odabrani monitori dijele svijet. Prazne trake se uklanjaju; unutrašnje rupe ostaju."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animacija je pokrenuta…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animacija je pauzirana."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Nije moguće inicijalizirati Direct3D prikazivač."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Uključi pregled"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Isključi pregled"
        },
        LocalizedText{ TXT_MONITOR,
            L"Monitor"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Rezolucija"
        },
        LocalizedText{ TXT_POSITION,
            L"Položaj"
        },
        LocalizedText{ TXT_PRIMARY,
            L"primarni"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Model monitora"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Frekvencija osvježavanja"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Dubina bita"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Format boje"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Prostor boja"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bita/kanal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bita/piksel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Monitor animacije"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Spreman"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Prikaži mrežu"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Boja mreže…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Automatski ponovo pokreni mirnu ili ponavljajuću vidljivu scenu"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Samo poznati obrasci"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Pokreni snimanje…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Zaustavi snimanje"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4 snimanje je u toku…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Snimak je sačuvan."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Nije moguće pokrenuti MP4 snimanje."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Zatvaranje aplikacije zaustavit će snimanje koje je u toku."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Postavke snimanja"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Rezolucija:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Broj kadrova u sekundi:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Promjene se primjenjuju na sljedeće MP4 snimanje."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Mješavina odgovarajućih obrazaca"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Odabrani obrazac više ne stane. Odabrana je odgovarajuća mješavina."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Nije moguće učitati katalog poznatih obrazaca."
        },
    }),
    DefineLanguage(LANG_HR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Nasumična boja pozadine pri svakom ponovnom pokretanju scene"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Nasumična boja mreže pri svakom ponovnom pokretanju scene" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Čuvar zaslona u Windowsu…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Nije moguće otvoriti postavke čuvara zaslona u Windowsu."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Vrati vrijednosti" },
        LocalizedText{ TXT_SNAPSHOT, L"Snimka…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"BMP/GIF/JPEG/PNG/TIFF/WebP slika je spremljena." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Nije moguće spremiti BMP/GIF/JPEG/PNG/TIFF/WebP sliku." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Spriječi čuvar zaslona tijekom animacije" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Nasumična boja živih ćelija pri svakom ponovnom pokretanju scene"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Instalacija čuvara zaslona je u tijeku…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Deinstalacija čuvara zaslona je u tijeku…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Instaliraj čuvar zaslona" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Deinstaliraj čuvar zaslona" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Čuvar zaslona nije instaliran." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Čuvar zaslona je instaliran." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Čuvar zaslona je deinstaliran." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Nije moguće deinstalirati čuvar zaslona. Zatvorite čuvar i njegov pretpregled pa pokušajte "
            L"ponovno."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Zatvorite postavke programa GameOfLife pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zatvorite Windows postavke čuvara zaslona pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zatvorite čuvar ili pretpregled preko cijelog zaslona tipkom Esc ili pomicanjem miša pa "
            L"ponovite deinstalaciju."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Hrvatski"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — upravljanje"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Postavke programa GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Jezik:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Odustani"
        },
        LocalizedText{ TXT_EXIT,
            L"Izlaz"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pauziraj"
        },
        LocalizedText{ TXT_RESUME,
            L"Nastavi"
        },
        LocalizedText{ TXT_HELP,
            L"Pomoć"
        },
        LocalizedText{ TXT_ABOUT,
            L"O programu"
        },
        LocalizedText{ TXT_CLOSE,
            L"Zatvori"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Posjeti web-mjesto %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Nije moguće otvoriti stranicu u zadanom pregledniku."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Nije moguće kopirati URL u međuspremnik."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Nije moguće kopirati informacije u međuspremnik."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conwayeva Igra života u zajedničkom svijetu na više monitora."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Verzija:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Ciljna platforma:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Web-mjesto:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Otvori u zadanom pregledniku"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Kopiraj &adresu"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Kopiraj &informacije"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Resurs licence nije dostupan."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nPRAVILA\r\nConwayeva Igra života koristi B3/S23. Mrtva ćelija oživi uz "
            L"točno tri živa susjeda; živa preživi uz dva ili tri. Osam susjeda uključuje dijagonale. Sve "
            L"se ćelije mijenjaju istodobno. Suprotni se rubovi spajaju: lijevi s desnim, gornji s "
            L"donjim.\r\n\r\nMONITORI I ZAJEDNIČKI SVIJET\r\nPotvrdni okviri u EXE uključuju monitore; "
            L"postavke vrijede za zajednički svijet. Jedan uključen monitor sadrži cijeli svijet. Pri "
            L"odabiru dijela rasporeda potpuno prazni redci i stupci uklanjaju se: lijevi i desni monitor "
            L"spoje se nakon isključivanja srednjeg. Unutarnje rupe koje se ne mogu ukloniti ostaju u "
            L"simulaciji. Odabir svih monitora ili SCR zadržava pravokutnik radne površine s nevidljivim "
            L"prazninama. Svaki monitor prikazuje svoj dio iste simulacije.\r\n\r\nPOČETNO STANJE I "
            L"UZORCI\r\nZadani početak je nasumični šum s 25 % živih ćelija. Početna gustoća 0–100 % "
            L"primjenjuje se pri sljedećem ponovnom pokretanju. Samo poznati uzorci koristi 4.106 "
            L"priloženih uzoraka bez šuma i isključuje gustoću. Odaberite mješavinu ili naziv; dimenzije "
            L"su u ćelijama. Tipkajte naziv za pretraživanje. Nude se samo uzorci koji stanu cijeli. Mali "
            L"provjereni uzorci ponavljaju se u odvojenim kopijama, veliki ili složeni jednom u sredini. "
            L"Smanjenje svijeta može prevelik odabir zamijeniti mješavinom. Promjena načina ili uzorka "
            L"stvara novu scenu. Ponovna pokretanja čuvaju odabir; katalog radi izvan "
            L"mreže.\r\n\r\nĆELIJE, MREŽA I BOJE\r\nBez mreže veličina ćelije je 1–64 px. Mreža dodaje rub "
            L"od 1 px unutar postojećeg razmaka: prikaz i klizač smanjuju se za jedan, dostupno je 1–63. "
            L"Isključivanje vraća vrijednost. Klizač zadržava raspon i vraća se s nedostupnog kraja; okvir "
            L"ostaje aktivan. Prebacivanje čuva scenu, osim uključivanja na 1 px: razmak postaje 2 px i "
            L"scena počinje iznova. Promjena veličine ili monitora također počinje iznova. Vrlo velik "
            L"svijet može zahtijevati veći minimum. Boje ćelija, pozadine i mreže mijenjaju se zasebno bez "
            L"ponovnog pokretanja. Nasumična boja živih ćelija bira novu boju pri svakom ručnom ili "
            L"automatskom ponovnom pokretanju scene. Spremljena boja ostaje i vraća se nakon isključivanja "
            L"ove mogućnosti. Isto ponašanje može se zasebno uključiti za pozadinu i mrežu; obje nove "
            L"mogućnosti početno su isključene.\r\n\r\nBRZINA, STANKA I AUTOMATSKO PONOVNO "
            L"POKRETANJE\r\nBrzina je 0–240 generacija/s neovisno o osvježavanju; 0 zaustavlja razvoj. "
            L"Stanka i Nastavi čuvaju svijet. Pokreni ponovno počinje u odabranom načinu. Neobavezno "
            L"automatsko ponovno pokretanje prepoznaje statične i točno ponovljene vidljive faze, "
            L"uključujući oscilatore. Uspoređuje generacije, ne sekunde; nevidljiva područja izostavlja. "
            L"Asinkroni rezultati mogu malo odgoditi ponovno pokretanje. Zadano: razmak 8 px, 20 "
            L"generacija/s, nasumična boja živih stanica i automatsko ponovno pokretanje uključeni. Mreža "
            L"je prema zadanim postavkama isključena. Postignuta brzina ovisi o performansama i broju "
            L"ćelija. Automatsko ponovno pokretanje uspoređuje područja uključenih monitora; praznine se i "
            L"dalje razvijaju, ali ne ulaze u usporedbu.\r\n\r\nVrati vrijednosti\r\nVraćanje postavlja "
            L"prikazanu veličinu ćelije na 8 px s mrežom ili bez nje (razmak 9 ili 8 px), brzinu na 20 "
            L"generacija/s, gustoću na 25 % i tri zadane boje. Ostali izbori ostaju; uzorak koji više ne "
            L"stane zamjenjuje se mješavinom. Nova scena nastaje samo pri promjeni razmaka ili gustoće u "
            L"načinu sa šumom.\r\n\r\nSAMOSTALNA APLIKACIJA I MP4 SNIMANJE\r\nEXE stalno sprema postavke i "
            L"snima prvi aktivni monitor u MP4. Predlaže Videozapise, inače Dokumente. Viewport koristi "
            L"dimenzije i osvježavanje monitora do 60 sličica/s. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 "
            L"× 720 u 16:9 pri 50, 25, 59,94 (60000/1001) ili 29,97 (30000/1001) sličica/s. Omjer se čuva; "
            L"TV koristi progresivni BT.709 s ograničenim rasponom i 4:2:0. Zaseban prozor postavki može "
            L"se minimizirati. U redu sprema za sljedeće snimanje; Odustani ili Esc odbacuje nepotvrđene "
            L"izmjene. Snimani monitor ne može se isključiti; ostali se izlazi mogu mijenjati. Izlaz "
            L"tijekom snimanja traži potvrdu. Kada je animacija u fokusu, Razmak mijenja stanku, F9: "
            L"Pokreni snimanje; F10: Zaustavi snimanje. Pokazivač nestaje nakon 1 sekunde mirovanja i "
            L"vraća se pomicanjem. Tab/Shift+Tab prelazi između kontrola; Alt aktivira podcrtane naredbe. "
            L"Esc zatvara Pomoć/O programu ili izlazi iz glavnog prozora.\r\n\r\nSNIMKA SLIKE I "
            L"UPRAVLJANJE ČUVAROM U EXE\r\nSnimka slike sprema BMP/GIF/JPEG/PNG/TIFF/WebP monitora koji se "
            L"snima, inače prvog "
            L"aktivnog, u njegovoj razlučivosti bez ponovnog pokretanja scene. Predlaže mapu Slike, inače "
            L"Dokumenti. Blokiranje čuvara tijekom animacije sprječava njegovo pokretanje dok je animacija "
            L"vidljiva i nije zaustavljena stankom. Nulta brzina nije stanka. Instalacija iz EXE raspakira "
            L"priloženi SCR i odabire ga kao Windows čuvar zaslona. Instalacija i deinstalacija mogu "
            L"tražiti odobrenje administratora; statusna traka prikazuje radnju do završetka. Ako je "
            L"uklanjanje blokirano, zatvorite pokrenuti čuvar, njegove postavke i pretpregled sustava "
            L"Windows.\r\n\r\nČUVAR ZASLONA WINDOWS\r\nGameOfLife.scr koristi sve monitore i postavke "
            L"odvojene od EXE. Pretpregled pokreće animaciju preko cijelog zaslona uz otvorene postavke. "
            L"Mali pretpregled Windows smanjuje cijeli svijet. U redu sprema; Odustani ili Esc odbacuje "
            L"izmjene. Pomicanje miša ili tipka zatvara čuvar preko cijelog zaslona. MP4 snimanje dostupno "
            L"je u EXE.\r\n\r\nPOLOŽAJ I STANJE PROZORA\r\nPri zatvaranju se zasebno spremaju položaji "
            L"glavnog prozora i prozora O programu; za Pomoć i veličina te normalno ili maksimizirano "
            L"stanje prije minimiziranja. To ne ovisi o potvrđivanju postavki aplikacije. Zatvaranje "
            L"aplikacije zatvara i Pomoć i O programu.\r\n\r\nISCRTAVANJE I LICENCE UZORAKA\r\nRazvoj i "
            L"usporedba vidljivih stanja koriste Direct3D 11 sjenčare na GPU-u; softversko iscrtavanje "
            L"dostupno je ako hardverska inicijalizacija ne uspije. Svaki monitor koristi provjereni "
            L"regulator sličica pri vlastitom osvježavanju. MP4 zahtijeva Media Foundation i H.264 koder. "
            L"Uzorci dolaze s LifeWiki (GFDL 1.2 ili novija) i iz zbirki Alana Hensela u javnom "
            L"vlasništvu. Programski kod ima MIT licencu; obavijesti i licence kataloga su "
            L"odvojene.\r\n\r\nČuvar zaslona u Windowsu… otvara sistemske postavke čuvara zaslona."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nPRAVILA\r\nConwayeva Igra života koristi B3/S23. Mrtva ćelija oživi uz "
            L"točno tri živa susjeda; živa preživi uz dva ili tri. Osam susjeda uključuje dijagonale. Sve "
            L"se ćelije mijenjaju istodobno. Suprotni se rubovi spajaju: lijevi s desnim, gornji s "
            L"donjim.\r\n\r\nMONITORI I ZAJEDNIČKI SVIJET\r\nPotvrdni okviri u EXE uključuju monitore; "
            L"postavke vrijede za zajednički svijet. Jedan uključen monitor sadrži cijeli svijet. Pri "
            L"odabiru dijela rasporeda potpuno prazni redci i stupci uklanjaju se: lijevi i desni monitor "
            L"spoje se nakon isključivanja srednjeg. Unutarnje rupe koje se ne mogu ukloniti ostaju u "
            L"simulaciji. Odabir svih monitora ili SCR zadržava pravokutnik radne površine s nevidljivim "
            L"prazninama. Svaki monitor prikazuje svoj dio iste simulacije.\r\n\r\nPOČETNO STANJE I "
            L"UZORCI\r\nZadani početak je nasumični šum s 25 % živih ćelija. Početna gustoća 0–100 % "
            L"primjenjuje se pri sljedećem ponovnom pokretanju. Samo poznati uzorci koristi 4.106 "
            L"priloženih uzoraka bez šuma i isključuje gustoću. Odaberite mješavinu ili naziv; dimenzije "
            L"su u ćelijama. Tipkajte naziv za pretraživanje. Nude se samo uzorci koji stanu cijeli. Mali "
            L"provjereni uzorci ponavljaju se u odvojenim kopijama, veliki ili složeni jednom u sredini. "
            L"Smanjenje svijeta može prevelik odabir zamijeniti mješavinom. Promjena načina ili uzorka "
            L"stvara novu scenu. Ponovna pokretanja čuvaju odabir; katalog radi izvan "
            L"mreže.\r\n\r\nĆELIJE, MREŽA I BOJE\r\nBez mreže veličina ćelije je 1–64 px. Mreža dodaje rub "
            L"od 1 px unutar postojećeg razmaka: prikaz i klizač smanjuju se za jedan, dostupno je 1–63. "
            L"Isključivanje vraća vrijednost. Klizač zadržava raspon i vraća se s nedostupnog kraja; okvir "
            L"ostaje aktivan. Prebacivanje čuva scenu, osim uključivanja na 1 px: razmak postaje 2 px i "
            L"scena počinje iznova. Promjena veličine ili monitora također počinje iznova. Vrlo velik "
            L"svijet može zahtijevati veći minimum. Boje ćelija, pozadine i mreže mijenjaju se zasebno bez "
            L"ponovnog pokretanja. Nasumična boja živih ćelija bira novu boju pri svakom ručnom ili "
            L"automatskom ponovnom pokretanju scene. Spremljena boja ostaje i vraća se nakon isključivanja "
            L"ove mogućnosti. Isto ponašanje može se zasebno uključiti za pozadinu i mrežu; obje nove "
            L"mogućnosti početno su isključene.\r\n\r\nBRZINA, STANKA I AUTOMATSKO PONOVNO "
            L"POKRETANJE\r\nBrzina je 0–240 generacija/s neovisno o osvježavanju; 0 zaustavlja razvoj. "
            L"Stanka i Nastavi čuvaju svijet. Pokreni ponovno počinje u odabranom načinu. Neobavezno "
            L"automatsko ponovno pokretanje prepoznaje statične i točno ponovljene vidljive faze, "
            L"uključujući oscilatore. Uspoređuje generacije, ne sekunde; nevidljiva područja izostavlja. "
            L"Asinkroni rezultati mogu malo odgoditi ponovno pokretanje. Zadano: razmak 8 px, 20 "
            L"generacija/s, nasumična boja živih stanica i automatsko ponovno pokretanje uključeni. Mreža "
            L"je prema zadanim postavkama isključena. Postignuta brzina ovisi o performansama i broju "
            L"ćelija. Automatsko ponovno pokretanje uspoređuje područja uključenih monitora; praznine se i "
            L"dalje razvijaju, ali ne ulaze u usporedbu.\r\n\r\nVrati vrijednosti\r\nVraćanje postavlja "
            L"prikazanu veličinu ćelije na 8 px s mrežom ili bez nje (razmak 9 ili 8 px), brzinu na 20 "
            L"generacija/s, gustoću na 25 % i tri zadane boje. Ostali izbori ostaju; uzorak koji više ne "
            L"stane zamjenjuje se mješavinom. Nova scena nastaje samo pri promjeni razmaka ili gustoće u "
            L"načinu sa šumom.\r\n\r\nČUVAR ZASLONA WINDOWS\r\nGameOfLife.scr koristi sve monitore i "
            L"postavke odvojene od EXE. Pretpregled pokreće animaciju preko cijelog zaslona uz otvorene "
            L"postavke. Mali pretpregled Windows smanjuje cijeli svijet. U redu sprema; Odustani ili Esc "
            L"odbacuje izmjene. Pomicanje miša ili tipka zatvara čuvar preko cijelog zaslona. MP4 snimanje "
            L"dostupno je u EXE.\r\n\r\nPOLOŽAJ I STANJE PROZORA\r\nPri zatvaranju se zasebno spremaju "
            L"položaji glavnog prozora i prozora O programu; za Pomoć i veličina te normalno ili "
            L"maksimizirano stanje prije minimiziranja. To ne ovisi o potvrđivanju postavki aplikacije. "
            L"Zatvaranje aplikacije zatvara i Pomoć i O programu.\r\n\r\nISCRTAVANJE I LICENCE "
            L"UZORAKA\r\nRazvoj i usporedba vidljivih stanja koriste Direct3D 11 sjenčare na GPU-u; "
            L"softversko iscrtavanje dostupno je ako hardverska inicijalizacija ne uspije. Svaki monitor "
            L"koristi provjereni regulator sličica pri vlastitom osvježavanju. MP4 zahtijeva Media "
            L"Foundation i H.264 koder. Uzorci dolaze s LifeWiki (GFDL 1.2 ili novija) i iz zbirki Alana "
            L"Hensela u javnom vlasništvu. Programski kod ima MIT licencu; obavijesti i licence kataloga "
            L"su odvojene."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Veličina ćelije: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Brzina: %u generacija/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Početna gustoća: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Ponovno pokreni scenu" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Boja živih ćelija…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Boja pozadine…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Odabrani monitori dijele svijet. Prazne se trake uklanjaju; unutarnje rupe ostaju."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animacija je pokrenuta…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animacija je pauzirana."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Nije moguće inicijalizirati Direct3D prikazivač."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Uključi pretpregled"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Isključi pretpregled"
        },
        LocalizedText{ TXT_MONITOR,
            L"Zaslon"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Razlučivost"
        },
        LocalizedText{ TXT_POSITION,
            L"Položaj"
        },
        LocalizedText{ TXT_PRIMARY,
            L"primarni"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Model zaslona"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Frekvencija osvježavanja"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Dubina bita"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Oblik boje"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Prostor boja"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bita/kanal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bita/piksel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Zaslon animacije"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Spreman"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Prikaži mrežu"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Boja mreže…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Automatski ponovno pokreni mirnu ili ponavljajuću vidljivu scenu"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Samo poznati uzorci"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Pokreni snimanje…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Zaustavi snimanje"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4 snimanje je u tijeku…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Snimka je spremljena."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Nije moguće pokrenuti MP4 snimanje."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Zatvaranje aplikacije zaustavit će snimanje koje je u tijeku."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Postavke snimanja"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Razlučivost:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Broj sličica u sekundi:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Promjene se primjenjuju na sljedeće MP4 snimanje."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Mješavina prikladnih uzoraka"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Odabrani uzorak više ne stane. Odabrana je prikladna mješavina."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Nije moguće učitati katalog poznatih uzoraka."
        },
    }),
    DefineLanguage(LANG_SL, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Naključna barva ozadja ob vsakem ponovnem zagonu prizora"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Naključna barva mreže ob vsakem ponovnem zagonu prizora" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Ohranjevalnik zaslona Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Nastavitev ohranjevalnika zaslona Windows ni mogoče odpreti."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Ponastavi vrednosti" },
        LocalizedText{ TXT_SNAPSHOT, L"Posnetek…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Slika BMP/GIF/JPEG/PNG/TIFF/WebP je shranjena." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Slike BMP/GIF/JPEG/PNG/TIFF/WebP ni bilo mogoče shraniti." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Prepreči ohranjevalnik med animacijo" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Naključna barva živih celic ob vsakem ponovnem zagonu prizora"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Poteka namestitev ohranjevalnika zaslona …" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Poteka odstranjevanje ohranjevalnika zaslona …" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Namesti ohranjevalnik zaslona" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Odstrani ohranjevalnik zaslona" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Ohranjevalnik zaslona ni nameščen." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Ohranjevalnik zaslona je nameščen." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Ohranjevalnik zaslona je odstranjen." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Ohranjevalnika zaslona ni bilo mogoče odstraniti. Zaprite ga in njegov predogled ter poskusite "
            L"znova."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Zaprite nastavitve GameOfLife in znova poskusite odstranitev."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zaprite nastavitve ohranjevalnika zaslona Windows in znova poskusite odstranitev."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zaprite ohranjevalnik ali celozaslonski predogled s tipko Esc ali premikom miške in znova "
            L"poskusite odstranitev."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Slovenščina"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — upravljanje"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Nastavitve GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Jezik:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Prekliči"
        },
        LocalizedText{ TXT_EXIT,
            L"Izhod"
        },
        LocalizedText{ TXT_PAUSE,
            L"Premor"
        },
        LocalizedText{ TXT_RESUME,
            L"Nadaljuj"
        },
        LocalizedText{ TXT_HELP,
            L"Pomoč"
        },
        LocalizedText{ TXT_ABOUT,
            L"O programu"
        },
        LocalizedText{ TXT_CLOSE,
            L"Zapri"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Obišči spletno mesto %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Spletnega mesta ni mogoče odpreti v privzetem brskalniku."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"URL-ja ni bilo mogoče kopirati v odložišče."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Podatkov ni bilo mogoče kopirati v odložišče."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Conwayeva igra življenja v skupnem svetu več zaslonov."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Različica:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Ciljna platforma:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Spletno mesto:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Odpri v privzetem brskalniku"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Kopiraj &naslov"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Kopiraj &podatke"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Vir licence ni na voljo."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nPRAVILA\r\nConwayeva igra življenja uporablja B3/S23. Mrtva celica oživi "
            L"ob natanko treh živih sosedih; živa preživi ob dveh ali treh. Osem sosedov vključuje "
            L"diagonale. Vse celice se spremenijo hkrati. Nasprotni robovi so povezani: levi z desnim, "
            L"zgornji s spodnjim.\r\n\r\nZASLONI IN SKUPNI SVET\r\nPotrditvena polja v EXE vključijo "
            L"zaslone; nastavitve veljajo za skupni svet. En sam vključen zaslon vsebuje ves svet. Pri "
            L"delni izbiri se povsem prazne vrstice in stolpci odstranijo: levi in desni zaslon se "
            L"združita, ko izključite srednjega. Neodstranljive notranje luknje ostanejo v simulaciji. "
            L"Izbira vseh zaslonov ali SCR ohrani pravokotnik namizja z nevidnimi vrzelmi. Vsak zaslon "
            L"kaže svoj del iste simulacije.\r\n\r\nZAČETNO STANJE IN VZORCI\r\nPrivzeti začetek je "
            L"naključni šum s 25 % živih celic. Začetna gostota 0–100 % velja ob naslednjem ponovnem "
            L"začetku. Samo znani vzorci uporabi 4.106 priloženih vzorcev brez šuma in onemogoči gostoto. "
            L"Izberite mešanico ali ime; mere so v celicah. Za iskanje tipkajte ime. Prikazani so samo "
            L"vzorci, ki se v celoti prilegajo. Majhni preverjeni vzorci se ponovijo v ločenih kopijah, "
            L"veliki ali zapleteni enkrat na sredini. Manjši svet lahko preveliko izbiro nadomesti z "
            L"mešanico. Sprememba načina ali vzorca ustvari nov prizor. Ponovni začetki ohranijo izbiro; "
            L"katalog deluje brez interneta.\r\n\r\nCELICE, MREŽA IN BARVE\r\nBrez mreže je velikost 1–64 "
            L"px. Mreža doda rob 1 px znotraj obstoječega razmika: prikazana vrednost in drsnik se "
            L"zmanjšata za ena, na voljo je 1–63. Izklop vrne vrednost. Drsnik ohrani ves razpon in se "
            L"vrne z nedostopnega konca; polje ostane aktivno. Preklop ohrani prizor, razen vklopa pri 1 "
            L"px: razmik postane 2 px in začne se nov prizor. Tudi sprememba velikosti ali zaslonov začne "
            L"znova. Zelo velik svet lahko zahteva višjo najmanjšo vrednost. Barve celic, ozadja in mreže "
            L"se spreminjajo ločeno brez ponovnega začetka. Naključna barva živih celic izbere novo barvo "
            L"ob vsakem ročnem ali samodejnem ponovnem začetku prizora. Shranjena barva ostane in se vrne "
            L"ob izklopu možnosti. Enako delovanje lahko ločeno vključite za ozadje in mrežo; obe novi "
            L"možnosti sta privzeto izključeni.\r\n\r\nHITROST, PREMOR IN SAMODEJNI PONOVNI "
            L"ZAČETEK\r\nHitrost je 0–240 generacij/s neodvisno od osveževanja; 0 ustavi razvoj. Premor in "
            L"Nadaljuj ohranita svet. Začni znova začne v izbranem načinu. Izbirni samodejni ponovni "
            L"začetek zazna statične in natanko ponavljajoče se vidne faze, tudi oscilatorje. Primerja "
            L"generacije, ne sekund; nevidna območja izpusti. Asinhroni rezultati lahko začetek nekoliko "
            L"zakasnijo. Privzeto: razmik 8 px, 20 generacij/s, naključna barva živih celic in samodejni "
            L"ponovni začetek vključeni. Mreža je privzeto izključena. Dosežena hitrost je odvisna od "
            L"zmogljivosti in števila celic. Samodejni ponovni začetek primerja območja vključenih "
            L"zaslonov; vrzeli se razvijajo naprej, vendar niso vključene v primerjavo.\r\n\r\nPonastavi "
            L"vrednosti\r\nPonastavitev nastavi prikazano velikost celice na 8 px z mrežo ali brez nje "
            L"(razmik 9 ali 8 px), hitrost na 20 generacij/s, gostoto na 25 % in tri privzete barve. Druge "
            L"izbire ostanejo; vzorec, ki se ne prilega več, nadomesti mešanica. Nov prizor nastane le ob "
            L"spremembi razmika ali gostote v načinu šuma.\r\n\r\nSAMOSTOJNI PROGRAM IN SNEMANJE "
            L"MP4\r\nEXE sproti shranjuje nastavitve in snema prvi aktivni zaslon v MP4. Predlaga "
            L"Videoposnetke, sicer Dokumente. Viewport uporabi mere in osveževanje zaslona do 60 sličic/s. "
            L"TV ponuja 1920 × 1080, 1440 × 1080 ali 1280 × 720 v 16:9 pri 50, 25, 59,94 (60000/1001) ali "
            L"29,97 (30000/1001) sličicah/s. Razmerje ostane; TV uporablja progresivni BT.709 z omejenim "
            L"razponom in 4:2:0. Ločeno okno nastavitev lahko pomanjšate. V redu shrani za naslednje "
            L"snemanje; Prekliči ali Esc zavrže nepotrjene spremembe. Snemanega zaslona ni mogoče "
            L"izključiti; druge izhode lahko spreminjate. Izhod med snemanjem zahteva potrditev. Ko ima "
            L"animacija fokus, preslednica preklopi premor, F9: Začni snemanje; F10: Ustavi snemanje. "
            L"Kazalec se skrije po 1 sekundi nedejavnosti in vrne ob premiku. Tab/Shift+Tab prehaja med "
            L"kontrolniki; Alt sproži podčrtane ukaze. Esc zapre Pomoč/O programu ali konča v glavnem "
            L"oknu.\r\n\r\nPOSNETEK SLIKE IN UPRAVLJANJE OHRANJEVALNIKA V EXE\r\nPosnetek slike shrani "
            L"BMP/GIF/JPEG/PNG/TIFF/WebP "
            L"snemanega zaslona, sicer prvega aktivnega, v njegovi ločljivosti brez ponovnega začetka "
            L"prizora. Predlaga mapo Slike, sicer Dokumenti. Blokiranje ohranjevalnika med animacijo "
            L"prepreči njegov zagon, dokler je animacija vidna in ni začasno ustavljena. Ničelna hitrost "
            L"ni premor. Namestitev iz EXE razpakira priloženi SCR in ga izbere kot ohranjevalnik zaslona "
            L"Windows. Namestitev in odstranitev lahko zahtevata skrbniško dovoljenje; vrstica stanja "
            L"prikazuje postopek do konca. Če je odstranitev blokirana, zaprite delujoči ohranjevalnik, "
            L"njegove nastavitve in predogled Windows.\r\n\r\nOHRANJEVALNIK ZASLONA "
            L"WINDOWS\r\nGameOfLife.scr uporablja vse zaslone in nastavitve ločeno od EXE. Predogled "
            L"zažene celozaslonsko animacijo ob odprtih nastavitvah. Mali predogled Windows pomanjša ves "
            L"svet. V redu shrani; Prekliči ali Esc zavrže spremembe. Premik miške ali tipka zapre "
            L"celozaslonski ohranjevalnik. Snemanje MP4 je na voljo v EXE.\r\n\r\nPOLOŽAJ IN STANJE "
            L"OKEN\r\nOb zapiranju se ločeno shranita položaja glavnega okna in okna O programu; pri "
            L"Pomoči tudi velikost in običajno ali povečano stanje pred pomanjšanjem. To ni odvisno od "
            L"potrjevanja nastavitev programa. Izhod iz programa zapre tudi Pomoč in O "
            L"programu.\r\n\r\nIZRIS IN LICENCE VZORCEV\r\nRazvoj in primerjave vidnih stanj uporabljajo "
            L"senčilnike Direct3D 11 na GPU; če strojna inicializacija ne uspe, je na voljo programski "
            L"izris. Vsak zaslon uporablja preverjeno časovno uravnavanje sličic pri lastni frekvenci. MP4 "
            L"zahteva Media Foundation in kodirnik H.264. Vzorci so iz LifeWiki (GFDL 1.2 ali novejša) in "
            L"javno dostopnih zbirk Alana Hensela v javni domeni. Koda ima licenco MIT; obvestila in "
            L"licence kataloga so ločeni.\r\n\r\nOhranjevalnik zaslona Windows… odpre sistemske nastavitve "
            L"ohranjevalnika zaslona."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nPRAVILA\r\nConwayeva igra življenja uporablja B3/S23. Mrtva celica oživi "
            L"ob natanko treh živih sosedih; živa preživi ob dveh ali treh. Osem sosedov vključuje "
            L"diagonale. Vse celice se spremenijo hkrati. Nasprotni robovi so povezani: levi z desnim, "
            L"zgornji s spodnjim.\r\n\r\nZASLONI IN SKUPNI SVET\r\nPotrditvena polja v EXE vključijo "
            L"zaslone; nastavitve veljajo za skupni svet. En sam vključen zaslon vsebuje ves svet. Pri "
            L"delni izbiri se povsem prazne vrstice in stolpci odstranijo: levi in desni zaslon se "
            L"združita, ko izključite srednjega. Neodstranljive notranje luknje ostanejo v simulaciji. "
            L"Izbira vseh zaslonov ali SCR ohrani pravokotnik namizja z nevidnimi vrzelmi. Vsak zaslon "
            L"kaže svoj del iste simulacije.\r\n\r\nZAČETNO STANJE IN VZORCI\r\nPrivzeti začetek je "
            L"naključni šum s 25 % živih celic. Začetna gostota 0–100 % velja ob naslednjem ponovnem "
            L"začetku. Samo znani vzorci uporabi 4.106 priloženih vzorcev brez šuma in onemogoči gostoto. "
            L"Izberite mešanico ali ime; mere so v celicah. Za iskanje tipkajte ime. Prikazani so samo "
            L"vzorci, ki se v celoti prilegajo. Majhni preverjeni vzorci se ponovijo v ločenih kopijah, "
            L"veliki ali zapleteni enkrat na sredini. Manjši svet lahko preveliko izbiro nadomesti z "
            L"mešanico. Sprememba načina ali vzorca ustvari nov prizor. Ponovni začetki ohranijo izbiro; "
            L"katalog deluje brez interneta.\r\n\r\nCELICE, MREŽA IN BARVE\r\nBrez mreže je velikost 1–64 "
            L"px. Mreža doda rob 1 px znotraj obstoječega razmika: prikazana vrednost in drsnik se "
            L"zmanjšata za ena, na voljo je 1–63. Izklop vrne vrednost. Drsnik ohrani ves razpon in se "
            L"vrne z nedostopnega konca; polje ostane aktivno. Preklop ohrani prizor, razen vklopa pri 1 "
            L"px: razmik postane 2 px in začne se nov prizor. Tudi sprememba velikosti ali zaslonov začne "
            L"znova. Zelo velik svet lahko zahteva višjo najmanjšo vrednost. Barve celic, ozadja in mreže "
            L"se spreminjajo ločeno brez ponovnega začetka. Naključna barva živih celic izbere novo barvo "
            L"ob vsakem ročnem ali samodejnem ponovnem začetku prizora. Shranjena barva ostane in se vrne "
            L"ob izklopu možnosti. Enako delovanje lahko ločeno vključite za ozadje in mrežo; obe novi "
            L"možnosti sta privzeto izključeni.\r\n\r\nHITROST, PREMOR IN SAMODEJNI PONOVNI "
            L"ZAČETEK\r\nHitrost je 0–240 generacij/s neodvisno od osveževanja; 0 ustavi razvoj. Premor in "
            L"Nadaljuj ohranita svet. Začni znova začne v izbranem načinu. Izbirni samodejni ponovni "
            L"začetek zazna statične in natanko ponavljajoče se vidne faze, tudi oscilatorje. Primerja "
            L"generacije, ne sekund; nevidna območja izpusti. Asinhroni rezultati lahko začetek nekoliko "
            L"zakasnijo. Privzeto: razmik 8 px, 20 generacij/s, naključna barva živih celic in samodejni "
            L"ponovni začetek vključeni. Mreža je privzeto izključena. Dosežena hitrost je odvisna od "
            L"zmogljivosti in števila celic. Samodejni ponovni začetek primerja območja vključenih "
            L"zaslonov; vrzeli se razvijajo naprej, vendar niso vključene v primerjavo.\r\n\r\nPonastavi "
            L"vrednosti\r\nPonastavitev nastavi prikazano velikost celice na 8 px z mrežo ali brez nje "
            L"(razmik 9 ali 8 px), hitrost na 20 generacij/s, gostoto na 25 % in tri privzete barve. Druge "
            L"izbire ostanejo; vzorec, ki se ne prilega več, nadomesti mešanica. Nov prizor nastane le ob "
            L"spremembi razmika ali gostote v načinu šuma.\r\n\r\nOHRANJEVALNIK ZASLONA "
            L"WINDOWS\r\nGameOfLife.scr uporablja vse zaslone in nastavitve ločeno od EXE. Predogled "
            L"zažene celozaslonsko animacijo ob odprtih nastavitvah. Mali predogled Windows pomanjša ves "
            L"svet. V redu shrani; Prekliči ali Esc zavrže spremembe. Premik miške ali tipka zapre "
            L"celozaslonski ohranjevalnik. Snemanje MP4 je na voljo v EXE.\r\n\r\nPOLOŽAJ IN STANJE "
            L"OKEN\r\nOb zapiranju se ločeno shranita položaja glavnega okna in okna O programu; pri "
            L"Pomoči tudi velikost in običajno ali povečano stanje pred pomanjšanjem. To ni odvisno od "
            L"potrjevanja nastavitev programa. Izhod iz programa zapre tudi Pomoč in O "
            L"programu.\r\n\r\nIZRIS IN LICENCE VZORCEV\r\nRazvoj in primerjave vidnih stanj uporabljajo "
            L"senčilnike Direct3D 11 na GPU; če strojna inicializacija ne uspe, je na voljo programski "
            L"izris. Vsak zaslon uporablja preverjeno časovno uravnavanje sličic pri lastni frekvenci. MP4 "
            L"zahteva Media Foundation in kodirnik H.264. Vzorci so iz LifeWiki (GFDL 1.2 ali novejša) in "
            L"javno dostopnih zbirk Alana Hensela v javni domeni. Koda ima licenco MIT; obvestila in "
            L"licence kataloga so ločeni."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Velikost celice: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Hitrost: %u generacij/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Začetna gostota: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Znova zaženi prizor" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Barva živih celic…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Barva ozadja…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Izbrani zasloni si delijo svet. Prazni pasovi se odstranijo; notranje luknje ostanejo."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animacija se izvaja…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animacija je začasno ustavljena."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Upodabljalnika Direct3D ni bilo mogoče inicializirati."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Vklopi predogled"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Izklopi predogled"
        },
        LocalizedText{ TXT_MONITOR,
            L"Zaslon"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Ločljivost"
        },
        LocalizedText{ TXT_POSITION,
            L"Položaj"
        },
        LocalizedText{ TXT_PRIMARY,
            L"glavni"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Model zaslona"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Hitrost osveževanja"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Bitna globina"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Oblika barv"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Barvni prostor"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bitov/kanal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bitov/slikovno piko"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Zaslon animacije"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Pripravljen"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Prikaži mrežo"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Barva mreže…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Samodejno znova začni mirujoč ali ponavljajoč se vidni prizor"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Samo znani vzorci"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Začni snemanje…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Ustavi snemanje"
        },
        LocalizedText{ TXT_RECORDING,
            L"Snemanje MP4 poteka…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Posnetek je shranjen."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Snemanja MP4 ni bilo mogoče začeti."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Zapiranje programa bo ustavilo trenutno snemanje."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Nastavitve snemanja"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Ločljivost:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Hitrost sličic:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Spremembe veljajo za naslednje snemanje MP4."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Mešanica ustreznih vzorcev"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Izbrani vzorec ne gre več v svet. Izbrana je bila ustrezna mešanica."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Kataloga znanih vzorcev ni bilo mogoče naložiti."
        },
    }),
    DefineLanguage(LANG_CNR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Nasumična boja pozadine pri svakom ponovnom pokretanju scene"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Nasumična boja mreže pri svakom ponovnom pokretanju scene" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Čuvar ekrana u Windowsu…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Nije moguće otvoriti podešavanja čuvara ekrana u Windowsu."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Vrati vrijednosti" },
        LocalizedText{ TXT_SNAPSHOT, L"Snimak…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"BMP/GIF/JPEG/PNG/TIFF/WebP slika je sačuvana." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Nije moguće sačuvati BMP/GIF/JPEG/PNG/TIFF/WebP sliku." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Spriječi čuvar ekrana tokom animacije" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Nasumična boja živih ćelija pri svakom ponovnom pokretanju scene"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Instalacija čuvara ekrana je u toku…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Deinstalacija čuvara ekrana je u toku…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Instaliraj čuvar ekrana" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Deinstaliraj čuvar ekrana" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Čuvar ekrana nije instaliran." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Čuvar ekrana je instaliran." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Čuvar ekrana je deinstaliran." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Nije moguće deinstalirati čuvar ekrana. Zatvorite čuvar i njegov pregled pa pokušajte ponovo."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Zatvorite podešavanja programa GameOfLife pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Zatvorite Windows podešavanja čuvara ekrana pa ponovite deinstalaciju."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Zatvorite čuvar ili pregled preko cijelog ekrana tasterom Esc ili pomjeranjem miša pa ponovite "
            L"deinstalaciju."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Crnogorski"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — kontrole"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Podešavanja programa GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Jezik:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Otkaži"
        },
        LocalizedText{ TXT_EXIT,
            L"Izlaz"
        },
        LocalizedText{ TXT_PAUSE,
            L"Pauziraj"
        },
        LocalizedText{ TXT_RESUME,
            L"Nastavi"
        },
        LocalizedText{ TXT_HELP,
            L"Pomoć"
        },
        LocalizedText{ TXT_ABOUT,
            L"O programu"
        },
        LocalizedText{ TXT_CLOSE,
            L"Zatvori"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Otvori veb-sajt %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Nije moguće otvoriti stranicu u podrazumijevanom pregledaču."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Nije moguće kopirati URL u međuspremnik."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Nije moguće kopirati podatke u međuspremnik."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Konvejeva Igra života u zajedničkom svijetu na više monitora."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Verzija:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Ciljna platforma:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Veb-sajt:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Otvori u podrazumijevanom pregledaču"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Kopiraj &adresu"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Kopiraj &podatke"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Resurs licence nije dostupan."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nPRAVILA\r\nKonvejeva Igra života koristi B3/S23. Mrtva ćelija oživi uz "
            L"tačno tri živa susjeda; živa preživi uz dva ili tri. Osam susjeda uključuje dijagonale. Sve "
            L"ćelije mijenjaju se istovremeno. Suprotne ivice se spajaju: lijeva s desnom, gornja s "
            L"donjom.\r\n\r\nMONITORI I ZAJEDNIČKI SVIJET\r\nPolja u EXE uključuju monitore; podešavanja "
            L"važe za zajednički svijet. Jedan uključen monitor sadrži cijeli svijet. Pri izboru dijela "
            L"rasporeda potpuno prazni redovi i kolone se uklanjaju: lijevi i desni monitor spoje se "
            L"poslije isključivanja srednjeg. Unutrašnje rupe koje se ne mogu ukloniti ostaju u "
            L"simulaciji. Izbor svih monitora ili SCR zadržava pravougaonik radne površine s nevidljivim "
            L"prazninama. Svaki monitor prikazuje svoj dio iste simulacije.\r\n\r\nPOČETNO STANJE I "
            L"OBRASCI\r\nPodrazumijevani početak je nasumični šum s 25 % živih ćelija. Početna gustina "
            L"0–100 % primjenjuje se pri sljedećem ponovnom pokretanju. Samo poznati obrasci koristi 4.106 "
            L"priloženih obrazaca bez šuma i isključuje gustinu. Izaberite mješavinu ili naziv; dimenzije "
            L"su u ćelijama. Kucajte naziv za pretragu. Nude se samo obrasci koji staju cijeli. Mali "
            L"provjereni obrasci ponavljaju se u odvojenim kopijama, veliki ili složeni jednom u sredini. "
            L"Smanjenje svijeta može prevelik izbor zamijeniti mješavinom. Promjena režima ili obrasca "
            L"stvara novu scenu. Ponovna pokretanja čuvaju izbor; katalog radi bez "
            L"interneta.\r\n\r\nĆELIJE, MREŽA I BOJE\r\nBez mreže veličina ćelije je 1–64 px. Mreža dodaje "
            L"ivicu od 1 px unutar postojećeg razmaka: prikaz i klizač smanjuju se za jedan, dostupno je "
            L"1–63. Isključivanje vraća vrijednost. Klizač zadržava raspon i vraća se s nedostupnog kraja; "
            L"polje ostaje aktivno. Prebacivanje čuva scenu, osim uključivanja na 1 px: razmak postaje 2 "
            L"px i scena počinje iznova. Promjena veličine ili monitora takođe počinje iznova. Veoma velik "
            L"svijet može zahtijevati veći minimum. Boje ćelija, pozadine i mreže mijenjaju se zasebno bez "
            L"ponovnog pokretanja. Nasumična boja živih ćelija bira novu boju pri svakom ručnom ili "
            L"automatskom ponovnom pokretanju scene. Sačuvana boja ostaje i vraća se nakon isključivanja "
            L"ove opcije. Isto ponašanje može se zasebno uključiti za pozadinu i mrežu; obje nove opcije "
            L"su podrazumijevano isključene.\r\n\r\nBRZINA, PAUZA I AUTOMATSKO PONOVNO "
            L"POKRETANJE\r\nBrzina je 0–240 generacija/s nezavisno od osvježavanja; 0 zaustavlja razvoj. "
            L"Pauza i Nastavi čuvaju svijet. Pokreni ponovo počinje u izabranom režimu. Neobavezno "
            L"automatsko ponovno pokretanje prepoznaje statične i tačno ponovljene vidljive faze, "
            L"uključujući oscilatore. Poredi generacije, ne sekunde; nevidljiva područja izostavlja. "
            L"Asinhroni rezultati mogu malo odložiti ponovno pokretanje. Podrazumijevano: razmak 8 px, 20 "
            L"generacija/s, nasumična boja živih ćelija i automatsko ponovno pokretanje uključeni. Mreža "
            L"je podrazumijevano isključena. Postignuta brzina zavisi od performansi i broja ćelija. "
            L"Automatsko ponovno pokretanje poredi područja uključenih monitora; praznine se i dalje "
            L"razvijaju, ali se ne uključuju u poređenje.\r\n\r\nVrati vrijednosti\r\nVraćanje postavlja "
            L"prikazanu veličinu ćelije na 8 px s mrežom ili bez nje (razmak 9 ili 8 px), brzinu na 20 "
            L"generacija/s, gustinu na 25 % i tri podrazumijevane boje. Ostali izbori ostaju; obrazac koji "
            L"više ne staje zamjenjuje se mješavinom. Nova scena nastaje samo pri promjeni razmaka ili "
            L"gustine u režimu šuma.\r\n\r\nSAMOSTALNA APLIKACIJA I MP4 SNIMANJE\r\nEXE stalno čuva "
            L"podešavanja i snima prvi aktivni monitor u MP4. Predlaže Video-zapise, inače Dokumente. "
            L"Viewport koristi dimenzije i osvježavanje monitora do 60 kadrova/s. TV nudi 1920 × 1080, "
            L"1440 × 1080 ili 1280 × 720 u 16:9 pri 50, 25, 59,94 (60000/1001) ili 29,97 (30000/1001) "
            L"kadrova/s. Odnos se čuva; TV koristi progresivni BT.709 s ograničenim rasponom i 4:2:0. "
            L"Zaseban prozor podešavanja može se minimizovati. U redu čuva za sljedeće snimanje; Otkaži "
            L"ili Esc odbacuje nepotvrđene izmjene. Snimani monitor ne može se isključiti; ostali izlazi "
            L"mogu se mijenjati. Izlaz tokom snimanja traži potvrdu. Kada je animacija u fokusu, Razmak "
            L"mijenja pauzu, F9: Pokreni snimanje; F10: Zaustavi snimanje. Pokazivač nestaje poslije 1 "
            L"sekunde mirovanja i vraća se pomjeranjem. Tab/Shift+Tab prelazi između kontrola; Alt "
            L"aktivira podvučene naredbe. Esc zatvara Pomoć/O programu ili izlazi iz glavnog "
            L"prozora.\r\n\r\nSNIMAK SLIKE I UPRAVLJANJE ČUVAROM U EXE\r\nSnimak slike čuva "
            L"BMP/GIF/JPEG/PNG/TIFF/WebP monitora "
            L"koji se snima, inače prvog aktivnog, u njegovoj rezoluciji bez ponovnog pokretanja scene. "
            L"Predlaže fasciklu Slike, inače Dokumenti. Blokiranje čuvara tokom animacije sprečava njegovo "
            L"pokretanje dok je animacija vidljiva i nije pauzirana. Nulta brzina nije pauza. Instalacija "
            L"iz EXE raspakuje priloženi SCR i bira ga kao Windows čuvar ekrana. Instalacija i "
            L"deinstalacija mogu tražiti odobrenje administratora; statusna traka prikazuje radnju do "
            L"završetka. Ako je uklanjanje blokirano, zatvorite pokrenuti čuvar, njegova podešavanja i "
            L"Windows pregled.\r\n\r\nWINDOWS ČUVAR EKRANA\r\nGameOfLife.scr koristi sve monitore i "
            L"podešavanja odvojena od EXE. Pregled pokreće animaciju preko cijelog ekrana uz otvorena "
            L"podešavanja. Mali Windows pregled smanjuje cijeli svijet. U redu čuva; Otkaži ili Esc "
            L"odbacuje izmjene. Pomjeranje miša ili taster zatvara čuvar preko cijelog ekrana. MP4 "
            L"snimanje je dostupno u EXE.\r\n\r\nPOLOŽAJ I STANJE PROZORA\r\nPri zatvaranju se zasebno "
            L"čuvaju položaji glavnog prozora i prozora O programu; za Pomoć i veličina te normalno ili "
            L"maksimizovano stanje prije minimizovanja. To ne zavisi od potvrđivanja podešavanja "
            L"aplikacije. Zatvaranje aplikacije zatvara i Pomoć i O programu.\r\n\r\nISCRTAVANJE I LICENCE "
            L"OBRAZACA\r\nRazvoj i poređenje vidljivih stanja koriste Direct3D 11 shadere na GPU-u; "
            L"softversko iscrtavanje je dostupno ako hardverska inicijalizacija ne uspije. Svaki monitor "
            L"koristi provjereni regulator kadrova pri vlastitom osvježavanju. MP4 zahtijeva Media "
            L"Foundation i H.264 koder. Obrasci dolaze s LifeWiki (GFDL 1.2 ili novija) i iz zbirki Alana "
            L"Hensela u javnom vlasništvu. Programski kod ima MIT licencu; obavještenja i licence kataloga "
            L"su odvojeni.\r\n\r\nČuvar ekrana u Windowsu… otvara sistemska podešavanja čuvara ekrana."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nPRAVILA\r\nKonvejeva Igra života koristi B3/S23. Mrtva ćelija oživi uz "
            L"tačno tri živa susjeda; živa preživi uz dva ili tri. Osam susjeda uključuje dijagonale. Sve "
            L"ćelije mijenjaju se istovremeno. Suprotne ivice se spajaju: lijeva s desnom, gornja s "
            L"donjom.\r\n\r\nMONITORI I ZAJEDNIČKI SVIJET\r\nPolja u EXE uključuju monitore; podešavanja "
            L"važe za zajednički svijet. Jedan uključen monitor sadrži cijeli svijet. Pri izboru dijela "
            L"rasporeda potpuno prazni redovi i kolone se uklanjaju: lijevi i desni monitor spoje se "
            L"poslije isključivanja srednjeg. Unutrašnje rupe koje se ne mogu ukloniti ostaju u "
            L"simulaciji. Izbor svih monitora ili SCR zadržava pravougaonik radne površine s nevidljivim "
            L"prazninama. Svaki monitor prikazuje svoj dio iste simulacije.\r\n\r\nPOČETNO STANJE I "
            L"OBRASCI\r\nPodrazumijevani početak je nasumični šum s 25 % živih ćelija. Početna gustina "
            L"0–100 % primjenjuje se pri sljedećem ponovnom pokretanju. Samo poznati obrasci koristi 4.106 "
            L"priloženih obrazaca bez šuma i isključuje gustinu. Izaberite mješavinu ili naziv; dimenzije "
            L"su u ćelijama. Kucajte naziv za pretragu. Nude se samo obrasci koji staju cijeli. Mali "
            L"provjereni obrasci ponavljaju se u odvojenim kopijama, veliki ili složeni jednom u sredini. "
            L"Smanjenje svijeta može prevelik izbor zamijeniti mješavinom. Promjena režima ili obrasca "
            L"stvara novu scenu. Ponovna pokretanja čuvaju izbor; katalog radi bez "
            L"interneta.\r\n\r\nĆELIJE, MREŽA I BOJE\r\nBez mreže veličina ćelije je 1–64 px. Mreža dodaje "
            L"ivicu od 1 px unutar postojećeg razmaka: prikaz i klizač smanjuju se za jedan, dostupno je "
            L"1–63. Isključivanje vraća vrijednost. Klizač zadržava raspon i vraća se s nedostupnog kraja; "
            L"polje ostaje aktivno. Prebacivanje čuva scenu, osim uključivanja na 1 px: razmak postaje 2 "
            L"px i scena počinje iznova. Promjena veličine ili monitora takođe počinje iznova. Veoma velik "
            L"svijet može zahtijevati veći minimum. Boje ćelija, pozadine i mreže mijenjaju se zasebno bez "
            L"ponovnog pokretanja. Nasumična boja živih ćelija bira novu boju pri svakom ručnom ili "
            L"automatskom ponovnom pokretanju scene. Sačuvana boja ostaje i vraća se nakon isključivanja "
            L"ove opcije. Isto ponašanje može se zasebno uključiti za pozadinu i mrežu; obje nove opcije "
            L"su podrazumijevano isključene.\r\n\r\nBRZINA, PAUZA I AUTOMATSKO PONOVNO "
            L"POKRETANJE\r\nBrzina je 0–240 generacija/s nezavisno od osvježavanja; 0 zaustavlja razvoj. "
            L"Pauza i Nastavi čuvaju svijet. Pokreni ponovo počinje u izabranom režimu. Neobavezno "
            L"automatsko ponovno pokretanje prepoznaje statične i tačno ponovljene vidljive faze, "
            L"uključujući oscilatore. Poredi generacije, ne sekunde; nevidljiva područja izostavlja. "
            L"Asinhroni rezultati mogu malo odložiti ponovno pokretanje. Podrazumijevano: razmak 8 px, 20 "
            L"generacija/s, nasumična boja živih ćelija i automatsko ponovno pokretanje uključeni. Mreža "
            L"je podrazumijevano isključena. Postignuta brzina zavisi od performansi i broja ćelija. "
            L"Automatsko ponovno pokretanje poredi područja uključenih monitora; praznine se i dalje "
            L"razvijaju, ali se ne uključuju u poređenje.\r\n\r\nVrati vrijednosti\r\nVraćanje postavlja "
            L"prikazanu veličinu ćelije na 8 px s mrežom ili bez nje (razmak 9 ili 8 px), brzinu na 20 "
            L"generacija/s, gustinu na 25 % i tri podrazumijevane boje. Ostali izbori ostaju; obrazac koji "
            L"više ne staje zamjenjuje se mješavinom. Nova scena nastaje samo pri promjeni razmaka ili "
            L"gustine u režimu šuma.\r\n\r\nWINDOWS ČUVAR EKRANA\r\nGameOfLife.scr koristi sve monitore i "
            L"podešavanja odvojena od EXE. Pregled pokreće animaciju preko cijelog ekrana uz otvorena "
            L"podešavanja. Mali Windows pregled smanjuje cijeli svijet. U redu čuva; Otkaži ili Esc "
            L"odbacuje izmjene. Pomjeranje miša ili taster zatvara čuvar preko cijelog ekrana. MP4 "
            L"snimanje je dostupno u EXE.\r\n\r\nPOLOŽAJ I STANJE PROZORA\r\nPri zatvaranju se zasebno "
            L"čuvaju položaji glavnog prozora i prozora O programu; za Pomoć i veličina te normalno ili "
            L"maksimizovano stanje prije minimizovanja. To ne zavisi od potvrđivanja podešavanja "
            L"aplikacije. Zatvaranje aplikacije zatvara i Pomoć i O programu.\r\n\r\nISCRTAVANJE I LICENCE "
            L"OBRAZACA\r\nRazvoj i poređenje vidljivih stanja koriste Direct3D 11 shadere na GPU-u; "
            L"softversko iscrtavanje je dostupno ako hardverska inicijalizacija ne uspije. Svaki monitor "
            L"koristi provjereni regulator kadrova pri vlastitom osvježavanju. MP4 zahtijeva Media "
            L"Foundation i H.264 koder. Obrasci dolaze s LifeWiki (GFDL 1.2 ili novija) i iz zbirki Alana "
            L"Hensela u javnom vlasništvu. Programski kod ima MIT licencu; obavještenja i licence kataloga "
            L"su odvojeni."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Veličina ćelije: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Brzina: %u generacija/s"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Početna gustina: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Ponovo pokreni scenu" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Boja živih ćelija…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Boja pozadine…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Izabrani monitori dijele svijet. Prazne trake se uklanjaju; unutrašnje rupe ostaju."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Animacija je pokrenuta…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Animacija je pauzirana."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Nije moguće inicijalizovati Direct3D prikazivač."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Uključi pregled"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Isključi pregled"
        },
        LocalizedText{ TXT_MONITOR,
            L"Monitor"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Rezolucija"
        },
        LocalizedText{ TXT_POSITION,
            L"Položaj"
        },
        LocalizedText{ TXT_PRIMARY,
            L"primarni"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Model monitora"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Frekvencija osvježavanja"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Dubina bita"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Format boje"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Prostor boja"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u bita/kanal"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u bita/piksel"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Monitor animacije"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Spreman"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Prikaži mrežu"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Boja mreže…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Automatski ponovo pokreni mirnu ili ponavljajuću vidljivu scenu"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Samo poznati obrasci"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Pokreni snimanje…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Zaustavi snimanje"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4 snimanje je u toku…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Snimak je sačuvan."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Nije moguće pokrenuti MP4 snimanje."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Zatvaranje aplikacije zaustaviće snimanje koje je u toku."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Podešavanja snimanja"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Rezolucija:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Broj kadrova u sekundi:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Promjene se primjenjuju na sljedeće MP4 snimanje."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Mješavina odgovarajućih obrazaca"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Izabrani obrazac više ne staje. Izabrana je odgovarajuća mješavina."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Nije moguće učitati katalog poznatih obrazaca."
        },
    }),
    DefineLanguage(LANG_BE, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Выпадковы колер фону пры кожным перазапуску сцэны" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Выпадковы колер сеткі пры кожным перазапуску сцэны" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Застаўка Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED, L"Не ўдалося адкрыць параметры застаўкі Windows." },
        LocalizedText{ TXT_RESET_SETTINGS, L"Скінуць значэнні" },
        LocalizedText{ TXT_SNAPSHOT, L"Здымак…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Відарыс BMP/GIF/JPEG/PNG/TIFF/WebP захаваны." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Не ўдалося захаваць відарыс BMP/GIF/JPEG/PNG/TIFF/WebP." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Блакаваць застаўку падчас анімацыі" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Выпадковы колер жывых клетак пры кожным перазапуску сцэны"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Ідзе ўсталяванне застаўкі…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Ідзе выдаленне застаўкі…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Усталяваць застаўку" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Выдаліць застаўку" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Застаўка не ўсталявана." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Застаўка ўсталявана." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Застаўка выдалена." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Не ўдалося выдаліць застаўку. Закрыйце яе і перадпрагляд ды паўтарыце спробу."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Закрыйце налады GameOfLife ды паўтарыце выдаленне."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Закрыйце акно налад застаўкі Windows ды паўтарыце выдаленне."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Завяршыце застаўку або поўнаэкранны перадпрагляд клавішай Esc ці рухам мышы ды паўтарыце "
            L"выдаленне."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Беларуская"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — кіраванне"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Налады GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Мова:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Скасаваць"
        },
        LocalizedText{ TXT_EXIT,
            L"Выйсці"
        },
        LocalizedText{ TXT_PAUSE,
            L"Прыпыніць"
        },
        LocalizedText{ TXT_RESUME,
            L"Працягнуць"
        },
        LocalizedText{ TXT_HELP,
            L"Даведка"
        },
        LocalizedText{ TXT_ABOUT,
            L"Пра праграму"
        },
        LocalizedText{ TXT_CLOSE,
            L"Закрыць"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Адкрыць вэб-сайт %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Немагчыма адкрыць сайт у прадвызначаным браўзеры."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Не ўдалося скапіяваць URL у буфер абмену."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Не ўдалося скапіяваць звесткі ў буфер абмену."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Гульня жыцця Конвея ў агульным свеце на некалькіх маніторах."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Версія:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Мэтавая платформа:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Вэб-сайт:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Адкрыць у прадвызначаным браўзеры"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Капіяваць &адрас"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Капіяваць &звесткі"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Рэсурс ліцэнзіі недаступны."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nПРАВІЛЫ\r\nГульня жыцця Конвея выкарыстоўвае B3/S23. Мёртвая клетка ажывае "
            L"пры дакладна трох жывых суседзях; жывая выжывае пры двух або трох. Восем суседзяў уключаюць "
            L"дыяганалі. Усе клеткі змяняюцца адначасова. Процілеглыя краі злучаныя: левы з правым, верхні "
            L"з ніжнім.\r\n\r\nМАНІТОРЫ І АГУЛЬНЫ СВЕТ\r\nСцяжкі ў EXE ўключаюць маніторы; налады "
            L"дзейнічаюць для агульнага свету. Адзін уключаны манітор змяшчае ўвесь свет. Пры выбары "
            L"часткі размяшчэння цалкам пустыя радкі і слупкі выдаляюцца: левы і правы маніторы злучаюцца "
            L"пасля выключэння сярэдняга. Унутраныя дзіркі, якія нельга выдаліць, застаюцца ў сімуляцыі. "
            L"Выбар усіх манітораў або SCR захоўвае прамавугольнік працоўнага стала з нябачнымі "
            L"прамежкамі. Кожны манітор паказвае сваю частку той жа сімуляцыі.\r\n\r\nПАЧАТКОВЫ СТАН І "
            L"ЎЗОРЫ\r\nЗвычайны пачатак — выпадковы шум з 25 % жывых клетак. Пачатковая шчыльнасць 0–100 % "
            L"ужываецца пры наступным перазапуску. Толькі вядомыя ўзоры выкарыстоўвае 4 106 убудаваных "
            L"узораў без шуму і адключае шчыльнасць. Выберыце сумесь або назву; памеры пададзены ў "
            L"клетках. Уводзьце назву для пошуку. Прапануюцца толькі ўзоры, якія змяшчаюцца цалкам. Малыя "
            L"правераныя ўзоры паўтараюцца асобнымі копіямі, вялікія або складаныя з'яўляюцца адзін раз у "
            L"цэнтры. Змяншэнне свету можа замяніць завялікі выбар сумессю. Змена рэжыму або ўзору стварае "
            L"новую сцэну. Перазапускі захоўваюць выбар; каталог працуе без інтэрнэту.\r\n\r\nКЛЕТКІ, "
            L"СЕТКА І КОЛЕРЫ\r\nБез сеткі памер клеткі 1–64 px. Сетка дадае край 1 px унутры існага кроку: "
            L"паказанае значэнне і паўзунок змяншаюцца на адзін, даступна 1–63. Выключэнне вяртае "
            L"значэнне. Паўзунок захоўвае дыяпазон і вяртаецца з недаступнага канца; сцяжок застаецца "
            L"актыўным. Пераключэнне захоўвае сцэну, акрамя ўключэння пры 1 px: крок павялічваецца да 2 px "
            L"і пачынаецца новая сцэна. Змена памеру або манітораў таксама пачынае нанова. Вельмі вялікі "
            L"свет можа патрабаваць большага мінімуму. Колеры клетак, фону і сеткі змяняюцца асобна без "
            L"перазапуску. Выпадковы колер жывых клетак выбіраецца нанова пры кожным ручным або "
            L"аўтаматычным перазапуску сцэны. Захаваны колер не перапісваецца і вяртаецца пасля выключэння "
            L"гэтай опцыі. Такія ж паводзіны можна асобна ўключыць для фону і сеткі; абедзве новыя опцыі "
            L"спачатку выключаныя.\r\n\r\nХУТКАСЦЬ, ПАЎЗА І АЎТАМАТЫЧНЫ ПЕРАЗАПУСК\r\nХуткасць 0–240 "
            L"пакаленняў/с не залежыць ад абнаўлення манітора; 0 спыняе развіццё. Паўза і Працягнуць "
            L"захоўваюць свет. Пачаць нанова запускае выбраны рэжым. Неабавязковы аўтаматычны перазапуск "
            L"распазнае статычныя і дакладна паўторныя бачныя фазы, уключаючы асцылятары. Ён параўноўвае "
            L"пакаленні, не секунды; нябачныя вобласці выключаюцца. Асінхронныя вынікі могуць крыху "
            L"затрымаць перазапуск. Звычайна: крок 8 px, 20 пакаленняў/с, выпадковы колер жывых клетак і "
            L"аўтаматычны перазапуск уключаныя. Сетка па змаўчанні выключаная. Дасягнутая хуткасць "
            L"залежыць ад прадукцыйнасці і колькасці клетак. Аўтаматычны перазапуск параўноўвае вобласці "
            L"ўключаных манітораў; прамежкі працягваюць развівацца, але не ўключаюцца ў "
            L"параўнанне.\r\n\r\nСкінуць значэнні\r\nСкід задае паказаны памер клеткі 8 px з сеткай або "
            L"без яе (крок 9 або 8 px), хуткасць 20 пакаленняў/с, шчыльнасць 25 % і тры стандартныя "
            L"колеры. Іншыя выбары захоўваюцца; узор, які больш не змяшчаецца, замяняецца сумессю. Новая "
            L"сцэна ствараецца толькі пры змене кроку або шчыльнасці ў рэжыме шуму.\r\n\r\nАСОБНАЯ "
            L"ПРАГРАМА І ЗАПІС MP4\r\nEXE пастаянна захоўвае налады і запісвае першы актыўны манітор у "
            L"MP4. Прапануецца папка Відэа, інакш Дакументы. Viewport выкарыстоўвае памеры і абнаўленне "
            L"манітора да 60 кадраў/с. TV прапануе 1920 × 1080, 1440 × 1080 або 1280 × 720 у 16:9 пры 50, "
            L"25, 59,94 (60000/1001) або 29,97 (30000/1001) кадрах/с. Прапорцыі захоўваюцца; TV "
            L"выкарыстоўвае прагрэсіўны BT.709 з абмежаваным дыяпазонам і 4:2:0. Асобнае акно налад можна "
            L"згарнуць. OK захоўвае для наступнага запісу; Скасаваць або Esc адхіляе непацверджаныя змены. "
            L"Манітор запісу нельга выключыць; астатнія выхады можна змяняць. Выхад падчас запісу патрабуе "
            L"пацверджання. Калі анімацыя ў фокусе, Прабел пераключае паўзу, F9: Пачаць запіс; F10: "
            L"Спыніць запіс. Курсор знікае пасля 1 секунды бяздзейнасці і вяртаецца пры руху. "
            L"Tab/Shift+Tab пераходзіць паміж элементамі, Alt запускае падкрэсленыя каманды. Esc закрывае "
            L"Даведку/Пра праграму або завяршае праграму ў галоўным акне.\r\n\r\nЗДЫМАК І КІРАВАННЕ "
            L"ЗАСТАЎКАЙ У EXE\r\nЗдымак захоўвае BMP/GIF/JPEG/PNG/TIFF/WebP манітора, які запісваецца, інакш "
            L"першага актыўнага, у "
            L"яго раздзяляльнасці без перазапуску сцэны. Прапануецца папка Выявы, інакш Дакументы. "
            L"Блакаванне застаўкі падчас анімацыі не дазваляе ёй запускацца, пакуль анімацыя бачная і не "
            L"прыпыненая. Нулявая хуткасць не з’яўляецца паўзай. Усталяванне з EXE распакоўвае ўбудаваны "
            L"SCR і выбірае яго як застаўку Windows. Усталяванне і выдаленне могуць патрабаваць згоды "
            L"адміністратара; радок стану паказвае аперацыю да яе завяршэння. Калі выдаленне заблакаванае, "
            L"закрыйце запушчаную застаўку, яе налады і прагляд Windows.\r\n\r\nЗАСТАЎКА "
            L"WINDOWS\r\nGameOfLife.scr выкарыстоўвае ўсе маніторы і асобныя ад EXE налады. Прагляд "
            L"запускае поўнаэкранную анімацыю з адкрытымі наладамі. Малы прагляд Windows памяншае ўвесь "
            L"свет. OK захоўвае; Скасаваць або Esc адхіляе змены. Рух мышы або клавіша закрывае "
            L"поўнаэкранную застаўку. Запіс MP4 даступны ў EXE.\r\n\r\nСТАНОВІШЧА І СТАН ВОКНАЎ\r\nПры "
            L"закрыцці асобна захоўваюцца становішчы галоўнага акна і акна Пра праграму; для Даведкі "
            L"таксама памер і звычайны або разгорнуты стан перад згортваннем. Гэта не залежыць ад "
            L"пацверджання налад праграмы. Выхад з праграмы закрывае таксама Даведку і Пра "
            L"праграму.\r\n\r\nАДЛЮСТРАВАННЕ І ЛІЦЭНЗІІ ЎЗОРАЎ\r\nРазвіццё і параўнанне бачных станаў "
            L"выкарыстоўваюць шэйдары Direct3D 11 на GPU; пры няўдалай апаратнай ініцыялізацыі даступнае "
            L"праграмнае адлюстраванне. Кожны манітор выкарыстоўвае праверанае рэгуляванне кадраў на сваёй "
            L"частаце. MP4 патрабуе Media Foundation і кадавальнік H.264. Узоры паходзяць з LifeWiki (GFDL "
            L"1.2 або навейшая) і калекцый Алана Хенсела ў грамадскім набытку. Код мае ліцэнзію MIT; "
            L"паведамленні і ліцэнзіі каталога асобныя.\r\n\r\nЗастаўка Windows… адкрывае сістэмныя "
            L"параметры застаўкі."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nПРАВІЛЫ\r\nГульня жыцця Конвея выкарыстоўвае B3/S23. Мёртвая клетка ажывае "
            L"пры дакладна трох жывых суседзях; жывая выжывае пры двух або трох. Восем суседзяў уключаюць "
            L"дыяганалі. Усе клеткі змяняюцца адначасова. Процілеглыя краі злучаныя: левы з правым, верхні "
            L"з ніжнім.\r\n\r\nМАНІТОРЫ І АГУЛЬНЫ СВЕТ\r\nСцяжкі ў EXE ўключаюць маніторы; налады "
            L"дзейнічаюць для агульнага свету. Адзін уключаны манітор змяшчае ўвесь свет. Пры выбары "
            L"часткі размяшчэння цалкам пустыя радкі і слупкі выдаляюцца: левы і правы маніторы злучаюцца "
            L"пасля выключэння сярэдняга. Унутраныя дзіркі, якія нельга выдаліць, застаюцца ў сімуляцыі. "
            L"Выбар усіх манітораў або SCR захоўвае прамавугольнік працоўнага стала з нябачнымі "
            L"прамежкамі. Кожны манітор паказвае сваю частку той жа сімуляцыі.\r\n\r\nПАЧАТКОВЫ СТАН І "
            L"ЎЗОРЫ\r\nЗвычайны пачатак — выпадковы шум з 25 % жывых клетак. Пачатковая шчыльнасць 0–100 % "
            L"ужываецца пры наступным перазапуску. Толькі вядомыя ўзоры выкарыстоўвае 4 106 убудаваных "
            L"узораў без шуму і адключае шчыльнасць. Выберыце сумесь або назву; памеры пададзены ў "
            L"клетках. Уводзьце назву для пошуку. Прапануюцца толькі ўзоры, якія змяшчаюцца цалкам. Малыя "
            L"правераныя ўзоры паўтараюцца асобнымі копіямі, вялікія або складаныя з'яўляюцца адзін раз у "
            L"цэнтры. Змяншэнне свету можа замяніць завялікі выбар сумессю. Змена рэжыму або ўзору стварае "
            L"новую сцэну. Перазапускі захоўваюць выбар; каталог працуе без інтэрнэту.\r\n\r\nКЛЕТКІ, "
            L"СЕТКА І КОЛЕРЫ\r\nБез сеткі памер клеткі 1–64 px. Сетка дадае край 1 px унутры існага кроку: "
            L"паказанае значэнне і паўзунок змяншаюцца на адзін, даступна 1–63. Выключэнне вяртае "
            L"значэнне. Паўзунок захоўвае дыяпазон і вяртаецца з недаступнага канца; сцяжок застаецца "
            L"актыўным. Пераключэнне захоўвае сцэну, акрамя ўключэння пры 1 px: крок павялічваецца да 2 px "
            L"і пачынаецца новая сцэна. Змена памеру або манітораў таксама пачынае нанова. Вельмі вялікі "
            L"свет можа патрабаваць большага мінімуму. Колеры клетак, фону і сеткі змяняюцца асобна без "
            L"перазапуску. Выпадковы колер жывых клетак выбіраецца нанова пры кожным ручным або "
            L"аўтаматычным перазапуску сцэны. Захаваны колер не перапісваецца і вяртаецца пасля выключэння "
            L"гэтай опцыі. Такія ж паводзіны можна асобна ўключыць для фону і сеткі; абедзве новыя опцыі "
            L"спачатку выключаныя.\r\n\r\nХУТКАСЦЬ, ПАЎЗА І АЎТАМАТЫЧНЫ ПЕРАЗАПУСК\r\nХуткасць 0–240 "
            L"пакаленняў/с не залежыць ад абнаўлення манітора; 0 спыняе развіццё. Паўза і Працягнуць "
            L"захоўваюць свет. Пачаць нанова запускае выбраны рэжым. Неабавязковы аўтаматычны перазапуск "
            L"распазнае статычныя і дакладна паўторныя бачныя фазы, уключаючы асцылятары. Ён параўноўвае "
            L"пакаленні, не секунды; нябачныя вобласці выключаюцца. Асінхронныя вынікі могуць крыху "
            L"затрымаць перазапуск. Звычайна: крок 8 px, 20 пакаленняў/с, выпадковы колер жывых клетак і "
            L"аўтаматычны перазапуск уключаныя. Сетка па змаўчанні выключаная. Дасягнутая хуткасць "
            L"залежыць ад прадукцыйнасці і колькасці клетак. Аўтаматычны перазапуск параўноўвае вобласці "
            L"ўключаных манітораў; прамежкі працягваюць развівацца, але не ўключаюцца ў "
            L"параўнанне.\r\n\r\nСкінуць значэнні\r\nСкід задае паказаны памер клеткі 8 px з сеткай або "
            L"без яе (крок 9 або 8 px), хуткасць 20 пакаленняў/с, шчыльнасць 25 % і тры стандартныя "
            L"колеры. Іншыя выбары захоўваюцца; узор, які больш не змяшчаецца, замяняецца сумессю. Новая "
            L"сцэна ствараецца толькі пры змене кроку або шчыльнасці ў рэжыме шуму.\r\n\r\nЗАСТАЎКА "
            L"WINDOWS\r\nGameOfLife.scr выкарыстоўвае ўсе маніторы і асобныя ад EXE налады. Прагляд "
            L"запускае поўнаэкранную анімацыю з адкрытымі наладамі. Малы прагляд Windows памяншае ўвесь "
            L"свет. OK захоўвае; Скасаваць або Esc адхіляе змены. Рух мышы або клавіша закрывае "
            L"поўнаэкранную застаўку. Запіс MP4 даступны ў EXE.\r\n\r\nСТАНОВІШЧА І СТАН ВОКНАЎ\r\nПры "
            L"закрыцці асобна захоўваюцца становішчы галоўнага акна і акна Пра праграму; для Даведкі "
            L"таксама памер і звычайны або разгорнуты стан перад згортваннем. Гэта не залежыць ад "
            L"пацверджання налад праграмы. Выхад з праграмы закрывае таксама Даведку і Пра "
            L"праграму.\r\n\r\nАДЛЮСТРАВАННЕ І ЛІЦЭНЗІІ ЎЗОРАЎ\r\nРазвіццё і параўнанне бачных станаў "
            L"выкарыстоўваюць шэйдары Direct3D 11 на GPU; пры няўдалай апаратнай ініцыялізацыі даступнае "
            L"праграмнае адлюстраванне. Кожны манітор выкарыстоўвае праверанае рэгуляванне кадраў на сваёй "
            L"частаце. MP4 патрабуе Media Foundation і кадавальнік H.264. Узоры паходзяць з LifeWiki (GFDL "
            L"1.2 або навейшая) і калекцый Алана Хенсела ў грамадскім набытку. Код мае ліцэнзію MIT; "
            L"паведамленні і ліцэнзіі каталога асобныя."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Памер клеткі: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Хуткасць: %u пакаленняў/с"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Пачатковая шчыльнасць: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Перазапусціць сцэну" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Колер жывых клетак…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Колер фону…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Выбраныя маніторы маюць агульны свет. Пустыя палосы выдаляюцца; унутраныя дзіркі застаюцца."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Анімацыя працуе…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Анімацыя прыпынена."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Не ўдалося ініцыялізаваць візуалізатар Direct3D."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Перадпрагляд" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Спыніць прагляд" },
        LocalizedText{ TXT_MONITOR,
            L"Манітор"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Раздзяляльнасць"
        },
        LocalizedText{ TXT_POSITION,
            L"Пазіцыя"
        },
        LocalizedText{ TXT_PRIMARY,
            L"асноўны"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Мадэль манітора"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Частата абнаўлення"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Бітавая глыбіня"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Фармат колеру"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Каляровая прастора"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u біт/канал"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u біт/піксель"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Манітор анімацыі"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Гатовы"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Паказваць сетку"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Колер сеткі…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Аўтаматычна пачынаць нанова сталую або паўторную бачную сцэну"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Толькі вядомыя ўзоры"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Пачаць запіс…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Спыніць запіс"
        },
        LocalizedText{ TXT_RECORDING,
            L"Ідзе запіс MP4…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Запіс захаваны."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Не ўдалося пачаць запіс MP4."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Закрыццё праграмы спыніць бягучы запіс."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Налады запісу"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Раздзяляльнасць:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Частата кадраў:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Змены будуць ужытыя да наступнага запісу MP4."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Сумесь прыдатных узораў"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Выбраны ўзор больш не змяшчаецца. Выбрана прыдатная сумесь."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Не ўдалося загрузіць каталог вядомых узораў."
        },
    }),
    DefineLanguage(LANG_BG, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Случаен цвят на фона при всяко рестартиране на сцената"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Случаен цвят на мрежата при всяко рестартиране на сцената" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Скрийнсейвър на Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Настройките на скрийнсейвъра на Windows не могат да се отворят."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Нулиране на стойностите" },
        LocalizedText{ TXT_SNAPSHOT, L"Снимка…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"BMP/GIF/JPEG/PNG/TIFF/WebP изображението е запазено." },
        LocalizedText{ TXT_SNAPSHOT_FAILED,
            L"BMP/GIF/JPEG/PNG/TIFF/WebP изображението не може да се запази."
        },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Блокиране на скрийнсейвъра при анимация" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Случаен цвят на живите клетки при всяко рестартиране на сцената"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Инсталира се скрийнсейвърът…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Деинсталира се скрийнсейвърът…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Инсталиране на скрийнсейвъра" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Деинсталиране на скрийнсейвъра" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Скрийнсейвърът не е инсталиран." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Скрийнсейвърът е инсталиран." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Скрийнсейвърът е деинсталиран." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Скрийнсейвърът не може да се деинсталира. Затворете го и неговия преглед и опитайте отново."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Затворете настройките на GameOfLife и опитайте деинсталирането отново."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Затворете настройките на скрийнсейвъра на Windows и опитайте деинсталирането отново."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Спрете скрийнсейвъра или прегледа на цял екран с Esc или движение на мишката и опитайте отново."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Български"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — управление"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Настройки на GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Език:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Отказ"
        },
        LocalizedText{ TXT_EXIT,
            L"Изход"
        },
        LocalizedText{ TXT_PAUSE,
            L"Пауза"
        },
        LocalizedText{ TXT_RESUME,
            L"Продължаване"
        },
        LocalizedText{ TXT_HELP,
            L"Помощ"
        },
        LocalizedText{ TXT_ABOUT,
            L"За програмата"
        },
        LocalizedText{ TXT_CLOSE,
            L"Затвори"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Отвори уебсайта %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Сайтът не може да се отвори в браузъра по подразбиране."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"URL адресът не можа да се копира в клипборда."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Информацията не можа да се копира в клипборда."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Играта на живота на Конуей в общ свят на няколко монитора."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Версия:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Целева платформа:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Уебсайт:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Отвори в браузъра по подразбиране"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Копирай &адреса"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Копирай &информацията"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Ресурсът на лиценза не е наличен."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nПРАВИЛА\r\nИграта на живота на Конуей използва B3/S23. Мъртва клетка се "
            L"ражда при точно три живи съседа; жива оцелява при два или три. Осемте съседа включват "
            L"диагоналите. Всички клетки се променят едновременно. Противоположните краища са свързани: "
            L"ляв с десен, горен с долен.\r\n\r\nМОНИТОРИ И ОБЩ СВЯТ\r\nОтметките в EXE включват монитори; "
            L"настройките важат за общия свят. Един включен монитор съдържа целия свят. При частичен избор "
            L"напълно празните редове и колони се премахват: левият и десният монитор се свързват след "
            L"изключване на средния. Непремахваемите вътрешни дупки остават в симулацията. Изборът на "
            L"всички монитори или SCR запазва правоъгълника на работния плот с невидимите празнини. Всеки "
            L"монитор показва своята част от същата симулация.\r\n\r\nНАЧАЛНО СЪСТОЯНИЕ И "
            L"ФИГУРИ\r\nНачалото по подразбиране е случаен шум с 25 % живи клетки. Началната плътност "
            L"0–100 % се прилага при следващото рестартиране. Само известни фигури използва 4 106 включени "
            L"фигури без шум и изключва плътността. Изберете смес или име; размерите са в клетки. Пишете "
            L"име за търсене. Предлагат се само фигури, които се побират цели. Малките проверени фигури се "
            L"повтарят в отделни копия, големите или сложните започват веднъж в центъра. Намаляването на "
            L"света може да замени прекалено голям избор със смес. Промяната на режима или фигурата "
            L"създава нова сцена. Рестартиранията пазят избора; каталогът работи без "
            L"интернет.\r\n\r\nКЛЕТКИ, МРЕЖА И ЦВЕТОВЕ\r\nБез мрежа размерът е 1–64 px. Мрежата добавя ръб "
            L"от 1 px в съществуващата стъпка: показаната стойност и плъзгачът намаляват с едно, "
            L"използваеми са 1–63. Изключването връща стойността. Плъзгачът запазва диапазона и се връща "
            L"от недостъпния край; отметката остава активна. Превключването запазва сцената, освен "
            L"включване при 1 px: стъпката става 2 px и започва нова сцена. Промяна на размера или "
            L"мониторите също започва отначало. Много голям свят може да изисква по-висок минимум. "
            L"Цветовете на клетките, фона и мрежата се променят независимо без рестартиране. Случайният "
            L"цвят на живите клетки се избира наново при всяко ръчно или автоматично рестартиране на "
            L"сцената. Запазеният цвят не се презаписва и се връща при изключване на опцията. Същото "
            L"поведение може да се включи отделно за фона и мрежата; двете нови опции първоначално са "
            L"изключени.\r\n\r\nСКОРОСТ, ПАУЗА И АВТОМАТИЧНО РЕСТАРТИРАНЕ\r\nСкоростта е 0–240 поколения/с "
            L"независимо от опресняването; 0 спира развитието. Пауза и Продължаване запазват света. "
            L"Рестартиране започва в избрания режим. Незадължителното автоматично рестартиране разпознава "
            L"статични и точно повтарящи се видими фази, включително осцилатори. Сравнява поколения, не "
            L"секунди; невидимите области се изключват. Асинхронните резултати могат леко да забавят "
            L"рестартирането. По подразбиране: стъпка 8 px, 20 поколения/с, случаен цвят на живите клетки "
            L"и автоматично рестартиране включени. Мрежата е изключена по подразбиране. Достигнатата "
            L"скорост зависи от производителността и броя клетки. Автоматичното рестартиране сравнява "
            L"областите на включените монитори; празнините продължават да се развиват, но не участват в "
            L"сравнението.\r\n\r\nНулиране на стойностите\r\nНулирането задава показван размер на клетката "
            L"8 px с или без мрежа (стъпка 9 или 8 px), скорост 20 поколения/с, плътност 25 % и трите "
            L"цвята по подразбиране. Другите избори се запазват; фигура, която вече не се побира, се "
            L"заменя със сместа. Нова сцена се създава само при промяна на стъпката или на плътността в "
            L"режим шум.\r\n\r\nСАМОСТОЯТЕЛНО ПРИЛОЖЕНИЕ И MP4 ЗАПИС\r\nEXE постоянно запазва настройките "
            L"и записва първия активен монитор в MP4. Предлага папка Видеоклипове, иначе Документи. "
            L"Viewport използва размерите и опресняването на монитора до 60 кадъра/с. TV предлага 1920 × "
            L"1080, 1440 × 1080 или 1280 × 720 в 16:9 при 50, 25, 59,94 (60000/1001) или 29,97 "
            L"(30000/1001) кадъра/с. Пропорциите се запазват; TV използва прогресивен BT.709 с ограничен "
            L"диапазон и 4:2:0. Отделният прозорец за настройки може да се минимизира. OK запазва за "
            L"следващия запис; Отказ или Esc отхвърля непотвърдените промени. Записваният монитор не може "
            L"да се изключи; другите изходи могат да се променят. Изходът по време на запис иска "
            L"потвърждение. При фокус върху анимацията Интервал превключва паузата, F9: Начало на запис; "
            L"F10: Спиране на записа. Курсорът изчезва след 1 секунда бездействие и се връща при движение. "
            L"Tab/Shift+Tab сменя контролата; Alt активира подчертаните команди. Esc затваря Помощ/Относно "
            L"или излиза от главния прозорец.\r\n\r\nСНИМКА И УПРАВЛЕНИЕ НА СКРИЙНСЕЙВЪРА В "
            L"EXE\r\nСнимката запазва BMP/GIF/JPEG/PNG/TIFF/WebP на записвания монитор, иначе на първия "
            L"активен, с неговата "
            L"резолюция без рестартиране на сцената. Предлага се папка Картини, иначе Документи. "
            L"Блокирането на скрийнсейвъра по време на анимация не позволява да се стартира, докато "
            L"анимацията е видима и не е на пауза. Нулева скорост не означава пауза. Инсталирането от EXE "
            L"разопакова включения SCR и го избира като скрийнсейвър на Windows. Инсталирането и "
            L"деинсталирането може да изискват разрешение от администратор; лентата на състоянието показва "
            L"операцията до края ѝ. Ако премахването е блокирано, затворете работещия скрийнсейвър, "
            L"настройките му и прегледа на Windows.\r\n\r\nСКРИЙНСЕЙВЪР НА WINDOWS\r\nGameOfLife.scr "
            L"използва всички монитори с настройки отделно от EXE. Прегледът стартира цял екран с отворени "
            L"настройки. Малкият преглед на Windows смалява целия свят. OK запазва; Отказ или Esc отхвърля "
            L"промените. Движение на мишката или клавиш затваря скрийнсейвъра на цял екран. MP4 записът е "
            L"в EXE.\r\n\r\nПОЗИЦИЯ И СЪСТОЯНИЕ НА ПРОЗОРЦИТЕ\r\nПри затваряне отделно се запазват "
            L"позициите на главния прозорец и Относно; за Помощ също размерът и нормалното или "
            L"максимизираното състояние преди минимизиране. Това не зависи от потвърждаването на "
            L"настройките на приложението. Изходът от приложението затваря и Помощ и "
            L"Относно.\r\n\r\nИЗОБРАЗЯВАНЕ И ЛИЦЕНЗИ НА ФИГУРИТЕ\r\nРазвитието и сравненията на видими "
            L"състояния използват Direct3D 11 шейдъри на GPU; при неуспешно хардуерно инициализиране има "
            L"софтуерно изобразяване. Всеки монитор използва проверения регулатор на кадрите със своята "
            L"честота. MP4 изисква Media Foundation и H.264 кодер. Фигурите са от LifeWiki (GFDL 1.2 или "
            L"по-нова) и колекциите на Алън Хенсел в обществено достояние. Кодът е с MIT лиценз; "
            L"известията и лицензите на каталога са отделни.\r\n\r\nСкрийнсейвър на Windows… отваря "
            L"системните настройки на скрийнсейвъра."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nПРАВИЛА\r\nИграта на живота на Конуей използва B3/S23. Мъртва клетка се "
            L"ражда при точно три живи съседа; жива оцелява при два или три. Осемте съседа включват "
            L"диагоналите. Всички клетки се променят едновременно. Противоположните краища са свързани: "
            L"ляв с десен, горен с долен.\r\n\r\nМОНИТОРИ И ОБЩ СВЯТ\r\nОтметките в EXE включват монитори; "
            L"настройките важат за общия свят. Един включен монитор съдържа целия свят. При частичен избор "
            L"напълно празните редове и колони се премахват: левият и десният монитор се свързват след "
            L"изключване на средния. Непремахваемите вътрешни дупки остават в симулацията. Изборът на "
            L"всички монитори или SCR запазва правоъгълника на работния плот с невидимите празнини. Всеки "
            L"монитор показва своята част от същата симулация.\r\n\r\nНАЧАЛНО СЪСТОЯНИЕ И "
            L"ФИГУРИ\r\nНачалото по подразбиране е случаен шум с 25 % живи клетки. Началната плътност "
            L"0–100 % се прилага при следващото рестартиране. Само известни фигури използва 4 106 включени "
            L"фигури без шум и изключва плътността. Изберете смес или име; размерите са в клетки. Пишете "
            L"име за търсене. Предлагат се само фигури, които се побират цели. Малките проверени фигури се "
            L"повтарят в отделни копия, големите или сложните започват веднъж в центъра. Намаляването на "
            L"света може да замени прекалено голям избор със смес. Промяната на режима или фигурата "
            L"създава нова сцена. Рестартиранията пазят избора; каталогът работи без "
            L"интернет.\r\n\r\nКЛЕТКИ, МРЕЖА И ЦВЕТОВЕ\r\nБез мрежа размерът е 1–64 px. Мрежата добавя ръб "
            L"от 1 px в съществуващата стъпка: показаната стойност и плъзгачът намаляват с едно, "
            L"използваеми са 1–63. Изключването връща стойността. Плъзгачът запазва диапазона и се връща "
            L"от недостъпния край; отметката остава активна. Превключването запазва сцената, освен "
            L"включване при 1 px: стъпката става 2 px и започва нова сцена. Промяна на размера или "
            L"мониторите също започва отначало. Много голям свят може да изисква по-висок минимум. "
            L"Цветовете на клетките, фона и мрежата се променят независимо без рестартиране. Случайният "
            L"цвят на живите клетки се избира наново при всяко ръчно или автоматично рестартиране на "
            L"сцената. Запазеният цвят не се презаписва и се връща при изключване на опцията. Същото "
            L"поведение може да се включи отделно за фона и мрежата; двете нови опции първоначално са "
            L"изключени.\r\n\r\nСКОРОСТ, ПАУЗА И АВТОМАТИЧНО РЕСТАРТИРАНЕ\r\nСкоростта е 0–240 поколения/с "
            L"независимо от опресняването; 0 спира развитието. Пауза и Продължаване запазват света. "
            L"Рестартиране започва в избрания режим. Незадължителното автоматично рестартиране разпознава "
            L"статични и точно повтарящи се видими фази, включително осцилатори. Сравнява поколения, не "
            L"секунди; невидимите области се изключват. Асинхронните резултати могат леко да забавят "
            L"рестартирането. По подразбиране: стъпка 8 px, 20 поколения/с, случаен цвят на живите клетки "
            L"и автоматично рестартиране включени. Мрежата е изключена по подразбиране. Достигнатата "
            L"скорост зависи от производителността и броя клетки. Автоматичното рестартиране сравнява "
            L"областите на включените монитори; празнините продължават да се развиват, но не участват в "
            L"сравнението.\r\n\r\nНулиране на стойностите\r\nНулирането задава показван размер на клетката "
            L"8 px с или без мрежа (стъпка 9 или 8 px), скорост 20 поколения/с, плътност 25 % и трите "
            L"цвята по подразбиране. Другите избори се запазват; фигура, която вече не се побира, се "
            L"заменя със сместа. Нова сцена се създава само при промяна на стъпката или на плътността в "
            L"режим шум.\r\n\r\nСКРИЙНСЕЙВЪР НА WINDOWS\r\nGameOfLife.scr използва всички монитори с "
            L"настройки отделно от EXE. Прегледът стартира цял екран с отворени настройки. Малкият преглед "
            L"на Windows смалява целия свят. OK запазва; Отказ или Esc отхвърля промените. Движение на "
            L"мишката или клавиш затваря скрийнсейвъра на цял екран. MP4 записът е в EXE.\r\n\r\nПОЗИЦИЯ И "
            L"СЪСТОЯНИЕ НА ПРОЗОРЦИТЕ\r\nПри затваряне отделно се запазват позициите на главния прозорец и "
            L"Относно; за Помощ също размерът и нормалното или максимизираното състояние преди "
            L"минимизиране. Това не зависи от потвърждаването на настройките на приложението. Изходът от "
            L"приложението затваря и Помощ и Относно.\r\n\r\nИЗОБРАЗЯВАНЕ И ЛИЦЕНЗИ НА "
            L"ФИГУРИТЕ\r\nРазвитието и сравненията на видими състояния използват Direct3D 11 шейдъри на "
            L"GPU; при неуспешно хардуерно инициализиране има софтуерно изобразяване. Всеки монитор "
            L"използва проверения регулатор на кадрите със своята честота. MP4 изисква Media Foundation и "
            L"H.264 кодер. Фигурите са от LifeWiki (GFDL 1.2 или по-нова) и колекциите на Алън Хенсел в "
            L"обществено достояние. Кодът е с MIT лиценз; известията и лицензите на каталога са отделни."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Размер на клетката: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Скорост: %u поколения/с"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Начална плътност: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Рестартиране на сцената" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Цвят на живите клетки…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Цвят на фона…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Избраните монитори споделят свят. Празните ивици се премахват; вътрешните дупки остават."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Анимацията се изпълнява…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Анимацията е на пауза."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Неуспешно инициализиране на Direct3D визуализатора."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Преглед" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Спиране на прегледа" },
        LocalizedText{ TXT_MONITOR,
            L"Монитор"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Разделителна способност"
        },
        LocalizedText{ TXT_POSITION,
            L"Позиция"
        },
        LocalizedText{ TXT_PRIMARY,
            L"основен"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Модел на монитора"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Честота на опресняване"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Битова дълбочина"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Формат на цветовете"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Цветово пространство"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u бита/канал"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u бита/пиксел"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Монитор за анимацията"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Готов"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Показване на мрежата"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Цвят на мрежата…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Автоматично рестартиране на неподвижна или повтаряща се видима сцена"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Само известни фигури"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Начало на запис…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Спиране на записа"
        },
        LocalizedText{ TXT_RECORDING,
            L"Извършва се MP4 запис…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Записът е запазен."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Неуспешно стартиране на MP4 запис."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Затварянето на приложението ще спре текущия запис."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Настройки на записа"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Разделителна способност:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Кадрова честота:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Промените се прилагат към следващия MP4 запис."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Смес от подходящи фигури"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Избраната фигура вече не се побира. Избрана е подходяща смес."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Каталогът с известни фигури не можа да се зареди."
        },
    }),
    DefineLanguage(LANG_MK, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Случајна боја на заднината при секое рестартирање на сцената"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Случајна боја на мрежата при секое рестартирање на сцената" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Заштитник на екран Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Не може да се отворат поставките за заштитникот на екран на Windows."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Ресетирај вредности" },
        LocalizedText{ TXT_SNAPSHOT, L"Снимка…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"BMP/GIF/JPEG/PNG/TIFF/WebP сликата е зачувана." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"BMP/GIF/JPEG/PNG/TIFF/WebP сликата не може да се зачува." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Блокирај го чуварот за време на анимацијата" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Случајна боја на живите клетки при секое рестартирање на сцената"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Во тек е инсталација на чуварот на екранот…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Во тек е деинсталација на чуварот на екранот…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Инсталирај чувар на екранот" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Деинсталирај чувар на екранот" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Чуварот на екранот не е инсталиран." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Чуварот на екранот е инсталиран." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Чуварот на екранот е деинсталиран." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Чуварот на екранот не може да се деинсталира. Затворете го него и неговиот преглед и обидете "
            L"се повторно."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Затворете ги поставките за GameOfLife и обидете се повторно да деинсталирате."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Затворете ги поставките за чуварот на екранот на Windows и обидете се повторно."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Затворете го чуварот или прегледот на цел екран со Esc или со движење на глувчето и обидете се "
            L"повторно."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Македонски"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — контроли"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Поставки за GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Јазик:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Откажи"
        },
        LocalizedText{ TXT_EXIT,
            L"Излез"
        },
        LocalizedText{ TXT_PAUSE,
            L"Паузирај"
        },
        LocalizedText{ TXT_RESUME,
            L"Продолжи"
        },
        LocalizedText{ TXT_HELP,
            L"Помош"
        },
        LocalizedText{ TXT_ABOUT,
            L"За програмата"
        },
        LocalizedText{ TXT_CLOSE,
            L"Затвори"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Отвори ја веб-страницата %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Веб-страницата не може да се отвори во стандардниот прелистувач."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"URL-адресата не можеше да се копира во таблата со исечоци."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Информациите не можеа да се копираат во таблата со исечоци."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Конвеевата Игра на животот во заеднички свет на повеќе монитори."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Верзија:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Целна платформа:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Веб-страница:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Отвори во стандардниот прелистувач"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Копирај ја &адресата"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Копирај ги &информациите"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Ресурсот за лиценцата не е достапен."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nПРАВИЛА\r\nКонвеевата Игра на животот користи B3/S23. Мртва ќелија оживува "
            L"со точно три живи соседи; жива преживува со два или три. Осумте соседи ги вклучуваат "
            L"дијагоналите. Сите ќелии се менуваат истовремено. Спротивните рабови се споени: левиот со "
            L"десниот, горниот со долниот.\r\n\r\nМОНИТОРИ И ЗАЕДНИЧКИ СВЕТ\r\nПолињата во EXE ги "
            L"вклучуваат мониторите; поставките важат за заедничкиот свет. Еден вклучен монитор го содржи "
            L"целиот свет. При делумен избор се отстрануваат целосно празните редови и колони: левиот и "
            L"десниот монитор се спојуваат по исклучување на средниот. Внатрешните дупки што не може да се "
            L"отстранат остануваат во симулацијата. Изборот на сите монитори или SCR го задржува "
            L"правоаголникот на работната површина со невидливите празнини. Секој монитор го прикажува "
            L"својот дел од истата симулација.\r\n\r\nПОЧЕТНА СОСТОЈБА И ОБРАСЦИ\r\nСтандардниот почеток е "
            L"случаен шум со 25 % живи ќелии. Почетната густина 0–100 % важи при следното повторно "
            L"почнување. Само познати обрасци користи 4 106 вклучени обрасци без шум и ја исклучува "
            L"густината. Изберете мешавина или име; димензиите се во ќелии. Пишувајте име за пребарување. "
            L"Се нудат само обрасци што се собираат целосно. Малите проверени обрасци се повторуваат во "
            L"одделни копии, големите или сложените почнуваат еднаш во средината. Намалувањето на светот "
            L"може преголем избор да замени со мешавина. Менување режим или образец создава нова сцена. "
            L"Повторното почнување го чува изборот; каталогот работи без интернет.\r\n\r\nЌЕЛИИ, МРЕЖА И "
            L"БОИ\r\nБез мрежа големината е 1–64 px. Мрежата додава раб од 1 px во постојниот чекор: "
            L"приказот и лизгачот се намалуваат за еден, достапни се 1–63. Исклучувањето ја враќа "
            L"вредноста. Лизгачот го задржува опсегот и се враќа од недостапниот крај; полето останува "
            L"активно. Префрлувањето ја чува сцената, освен вклучување при 1 px: чекорот станува 2 px и "
            L"почнува нова сцена. Менување големина или монитори исто почнува одново. Многу голем свет "
            L"може да бара повисок минимум. Боите на ќелиите, заднината и мрежата се менуваат одделно без "
            L"повторно почнување. Случајната боја на живите ќелии се избира одново при секое рачно или "
            L"автоматско повторно почнување на сцената. Зачуваната боја останува и се враќа по исклучување "
            L"на опцијата. Истото однесување може одделно да се вклучи за заднината и мрежата; двете нови "
            L"опции првично се исклучени.\r\n\r\nБРЗИНА, ПАУЗА И АВТОМАТСКО ПОВТОРНО ПОЧНУВАЊЕ\r\nБрзината "
            L"е 0–240 генерации/с независно од освежувањето; 0 го запира развојот. Пауза и Продолжи го "
            L"чуваат светот. Почни одново почнува во избраниот режим. Незадолжителното автоматско повторно "
            L"почнување препознава статични и точно повторени видливи фази, вклучувајќи осцилатори. "
            L"Споредува генерации, не секунди; невидливите области се изоставуваат. Асинхроните резултати "
            L"може малку да го одложат почетокот. Стандардно: чекор 8 px, 20 генерации/с, случајна боја на "
            L"живите клетки и автоматско повторно почнување вклучени. Мрежата е стандардно исклучена. "
            L"Постигнатата брзина зависи од перформансите и бројот на ќелии. Автоматското повторно "
            L"почнување ги споредува областите на вклучените монитори; празнините продолжуваат да се "
            L"развиваат, но не се вклучуваат во споредбата.\r\n\r\nРесетирај вредности\r\nРесетирањето ја "
            L"поставува прикажаната големина на клетката на 8 px со или без мрежа (чекор 9 или 8 px), "
            L"брзината на 20 генерации/с, густината на 25 % и трите стандардни бои. Другите избори "
            L"остануваат; образец што веќе не се собира се заменува со мешавината. Нова сцена се создава "
            L"само при промена на чекорот или густината во режимот на шум.\r\n\r\nСАМОСТОЈНА АПЛИКАЦИЈА И "
            L"MP4 СНИМАЊЕ\r\nEXE постојано зачувува поставки и го снима првиот активен монитор во MP4. "
            L"Предлага Видеа, инаку Документи. Viewport користи димензии и освежување на мониторот до 60 "
            L"кадри/с. TV нуди 1920 × 1080, 1440 × 1080 или 1280 × 720 во 16:9 при 50, 25, 59,94 "
            L"(60000/1001) или 29,97 (30000/1001) кадри/с. Соодносот се задржува; TV користи прогресивен "
            L"BT.709 со ограничен опсег и 4:2:0. Одделниот прозорец за поставки може да се минимизира. Во "
            L"ред зачувува за следното снимање; Откажи или Esc ги отфрла непотврдените измени. Мониторот "
            L"што се снима не може да се исклучи; другите излези може да се менуваат. Излегување при "
            L"снимање бара потврда. Кога анимацијата е во фокус, Празно место менува пауза, F9: Започни "
            L"снимање; F10: Запри снимање. Покажувачот исчезнува по 1 секунда неактивност и се враќа со "
            L"движење. Tab/Shift+Tab преминува меѓу контролите; Alt ги активира подвлечените наредби. Esc "
            L"затвора Помош/За програмата или излегува во главниот прозорец.\r\n\r\nСНИМКА НА СЛИКА И "
            L"УПРАВУВАЊЕ СО ЧУВАРОТ ВО EXE\r\nСнимката на слика зачувува BMP/GIF/JPEG/PNG/TIFF/WebP од "
            L"мониторот што се снима, "
            L"инаку од првиот активен, во неговата резолуција без повторно почнување на сцената. Се "
            L"предлага папката Слики, инаку Документи. Блокирањето на чуварот за време на анимацијата го "
            L"спречува неговото стартување додека анимацијата е видлива и не е паузирана. Нулта брзина не "
            L"е пауза. Инсталацијата од EXE го распакува приложениот SCR и го избира како чувар на екран "
            L"во Windows. Инсталацијата и деинсталацијата може да бараат одобрение од администратор; "
            L"статусната лента ја покажува постапката до крајот. Ако отстранувањето е блокирано, затворете "
            L"го активниот чувар, неговите поставки и прегледот на Windows.\r\n\r\nЧУВАР НА ЕКРАН "
            L"WINDOWS\r\nGameOfLife.scr ги користи сите монитори и поставки одделни од EXE. Прегледот "
            L"почнува анимација на цел екран со отворени поставки. Малиот Windows преглед го намалува "
            L"целиот свет. Во ред зачувува; Откажи или Esc ги отфрла измените. Движење на глушецот или "
            L"копче го затвора чуварот на цел екран. MP4 снимањето е во EXE.\r\n\r\nПОЛОЖБА И СОСТОЈБА НА "
            L"ПРОЗОРЦИТЕ\r\nПри затворање одделно се зачувуваат положбите на главниот прозорец и За "
            L"програмата; за Помош и големината и нормалната или максимизираната состојба пред "
            L"минимизирање. Ова не зависи од потврдувањето на поставките на апликацијата. Излегувањето ги "
            L"затвора и Помош и За програмата.\r\n\r\nИСЦРТУВАЊЕ И ЛИЦЕНЦИ НА ОБРАСЦИТЕ\r\nРазвојот и "
            L"споредбите на видливи состојби користат Direct3D 11 шејдери на GPU; достапно е софтверско "
            L"исцртување ако хардверската иницијализација не успее. Секој монитор го користи проверениот "
            L"регулатор на кадри со својата фреквенција. MP4 бара Media Foundation и H.264 кодер. "
            L"Обрасците се од LifeWiki (GFDL 1.2 или понова) и збирките на Алан Хенсел во јавна "
            L"сопственост. Кодот е со MIT лиценца; известувањата и лиценците на каталогот се "
            L"одделни.\r\n\r\nЗаштитник на екран Windows… ги отвора системските поставки за заштитникот на "
            L"екран."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nПРАВИЛА\r\nКонвеевата Игра на животот користи B3/S23. Мртва ќелија оживува "
            L"со точно три живи соседи; жива преживува со два или три. Осумте соседи ги вклучуваат "
            L"дијагоналите. Сите ќелии се менуваат истовремено. Спротивните рабови се споени: левиот со "
            L"десниот, горниот со долниот.\r\n\r\nМОНИТОРИ И ЗАЕДНИЧКИ СВЕТ\r\nПолињата во EXE ги "
            L"вклучуваат мониторите; поставките важат за заедничкиот свет. Еден вклучен монитор го содржи "
            L"целиот свет. При делумен избор се отстрануваат целосно празните редови и колони: левиот и "
            L"десниот монитор се спојуваат по исклучување на средниот. Внатрешните дупки што не може да се "
            L"отстранат остануваат во симулацијата. Изборот на сите монитори или SCR го задржува "
            L"правоаголникот на работната површина со невидливите празнини. Секој монитор го прикажува "
            L"својот дел од истата симулација.\r\n\r\nПОЧЕТНА СОСТОЈБА И ОБРАСЦИ\r\nСтандардниот почеток е "
            L"случаен шум со 25 % живи ќелии. Почетната густина 0–100 % важи при следното повторно "
            L"почнување. Само познати обрасци користи 4 106 вклучени обрасци без шум и ја исклучува "
            L"густината. Изберете мешавина или име; димензиите се во ќелии. Пишувајте име за пребарување. "
            L"Се нудат само обрасци што се собираат целосно. Малите проверени обрасци се повторуваат во "
            L"одделни копии, големите или сложените почнуваат еднаш во средината. Намалувањето на светот "
            L"може преголем избор да замени со мешавина. Менување режим или образец создава нова сцена. "
            L"Повторното почнување го чува изборот; каталогот работи без интернет.\r\n\r\nЌЕЛИИ, МРЕЖА И "
            L"БОИ\r\nБез мрежа големината е 1–64 px. Мрежата додава раб од 1 px во постојниот чекор: "
            L"приказот и лизгачот се намалуваат за еден, достапни се 1–63. Исклучувањето ја враќа "
            L"вредноста. Лизгачот го задржува опсегот и се враќа од недостапниот крај; полето останува "
            L"активно. Префрлувањето ја чува сцената, освен вклучување при 1 px: чекорот станува 2 px и "
            L"почнува нова сцена. Менување големина или монитори исто почнува одново. Многу голем свет "
            L"може да бара повисок минимум. Боите на ќелиите, заднината и мрежата се менуваат одделно без "
            L"повторно почнување. Случајната боја на живите ќелии се избира одново при секое рачно или "
            L"автоматско повторно почнување на сцената. Зачуваната боја останува и се враќа по исклучување "
            L"на опцијата. Истото однесување може одделно да се вклучи за заднината и мрежата; двете нови "
            L"опции првично се исклучени.\r\n\r\nБРЗИНА, ПАУЗА И АВТОМАТСКО ПОВТОРНО ПОЧНУВАЊЕ\r\nБрзината "
            L"е 0–240 генерации/с независно од освежувањето; 0 го запира развојот. Пауза и Продолжи го "
            L"чуваат светот. Почни одново почнува во избраниот режим. Незадолжителното автоматско повторно "
            L"почнување препознава статични и точно повторени видливи фази, вклучувајќи осцилатори. "
            L"Споредува генерации, не секунди; невидливите области се изоставуваат. Асинхроните резултати "
            L"може малку да го одложат почетокот. Стандардно: чекор 8 px, 20 генерации/с, случајна боја на "
            L"живите клетки и автоматско повторно почнување вклучени. Мрежата е стандардно исклучена. "
            L"Постигнатата брзина зависи од перформансите и бројот на ќелии. Автоматското повторно "
            L"почнување ги споредува областите на вклучените монитори; празнините продолжуваат да се "
            L"развиваат, но не се вклучуваат во споредбата.\r\n\r\nРесетирај вредности\r\nРесетирањето ја "
            L"поставува прикажаната големина на клетката на 8 px со или без мрежа (чекор 9 или 8 px), "
            L"брзината на 20 генерации/с, густината на 25 % и трите стандардни бои. Другите избори "
            L"остануваат; образец што веќе не се собира се заменува со мешавината. Нова сцена се создава "
            L"само при промена на чекорот или густината во режимот на шум.\r\n\r\nЧУВАР НА ЕКРАН "
            L"WINDOWS\r\nGameOfLife.scr ги користи сите монитори и поставки одделни од EXE. Прегледот "
            L"почнува анимација на цел екран со отворени поставки. Малиот Windows преглед го намалува "
            L"целиот свет. Во ред зачувува; Откажи или Esc ги отфрла измените. Движење на глушецот или "
            L"копче го затвора чуварот на цел екран. MP4 снимањето е во EXE.\r\n\r\nПОЛОЖБА И СОСТОЈБА НА "
            L"ПРОЗОРЦИТЕ\r\nПри затворање одделно се зачувуваат положбите на главниот прозорец и За "
            L"програмата; за Помош и големината и нормалната или максимизираната состојба пред "
            L"минимизирање. Ова не зависи од потврдувањето на поставките на апликацијата. Излегувањето ги "
            L"затвора и Помош и За програмата.\r\n\r\nИСЦРТУВАЊЕ И ЛИЦЕНЦИ НА ОБРАСЦИТЕ\r\nРазвојот и "
            L"споредбите на видливи состојби користат Direct3D 11 шејдери на GPU; достапно е софтверско "
            L"исцртување ако хардверската иницијализација не успее. Секој монитор го користи проверениот "
            L"регулатор на кадри со својата фреквенција. MP4 бара Media Foundation и H.264 кодер. "
            L"Обрасците се од LifeWiki (GFDL 1.2 или понова) и збирките на Алан Хенсел во јавна "
            L"сопственост. Кодот е со MIT лиценца; известувањата и лиценците на каталогот се одделни."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Големина на ќелија: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Брзина: %u генерации/с"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Почетна густина: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Рестартирај ја сцената" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Боја на живите ќелии…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Боја на заднината…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Избраните монитори делат свет. Празните ленти се отстрануваат; внатрешните дупки остануваат."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Анимацијата се извршува…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Анимацијата е паузирана."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Не може да се иницијализира Direct3D прикажувачот."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Вклучи преглед"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Исклучи преглед"
        },
        LocalizedText{ TXT_MONITOR,
            L"Монитор"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Резолуција"
        },
        LocalizedText{ TXT_POSITION,
            L"Положба"
        },
        LocalizedText{ TXT_PRIMARY,
            L"примарен"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Модел на мониторот"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Стапка на освежување"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Битна длабочина"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Формат на боја"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Простор на бои"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u бита/канал"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u бита/пиксел"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Монитор за анимација"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Подготвен"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Прикажи мрежа"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Боја на мрежата…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Автоматски почни одново мирна или повторлива видлива сцена"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Само познати обрасци"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Започни снимање…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Запри снимање"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4 снимање е во тек…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Снимката е зачувана."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Не може да започне MP4 снимање."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Затворањето на апликацијата ќе го запре снимањето што е во тек."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Поставки за снимање"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Резолуција:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Број кадри во секунда:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Промените важат за следното MP4 снимање."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Мешавина од соодветни обрасци"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Избраниот образец веќе не собира. Избрана е соодветна мешавина."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Не може да се вчита каталогот на познати обрасци."
        },
    }),
    DefineLanguage(LANG_SR, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Насумична боја позадине при сваком поновном покретању сцене"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Насумична боја мреже при сваком поновном покретању сцене" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Чувар екрана у Windows-у…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED,
            L"Није могуће отворити подешавања чувара екрана у Windows-у."
        },
        LocalizedText{ TXT_RESET_SETTINGS, L"Врати вредности" },
        LocalizedText{ TXT_SNAPSHOT, L"Снимак…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"BMP/GIF/JPEG/PNG/TIFF/WebP слика је сачувана." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Није могуће сачувати BMP/GIF/JPEG/PNG/TIFF/WebP слику." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Спречи чувар екрана током анимације" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Насумична боја живих ћелија при сваком поновном покретању сцене"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Инсталација чувара екрана је у току…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Деинсталација чувара екрана је у току…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Инсталирај чувар екрана" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Деинсталирај чувар екрана" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Чувар екрана није инсталиран." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Чувар екрана је инсталиран." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Чувар екрана је деинсталиран." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Није могуће деинсталирати чувар екрана. Затворите чувар и његов преглед па покушајте поново."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Затворите подешавања програма GameOfLife па поновите деинсталацију."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Затворите Windows подешавања чувара екрана па поновите деинсталацију."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Затворите чувар или преглед преко целог екрана тастером Esc или померањем миша па поновите "
            L"деинсталацију."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Српски"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — контроле"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Подешавања програма GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Језик:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Откажи"
        },
        LocalizedText{ TXT_EXIT,
            L"Излаз"
        },
        LocalizedText{ TXT_PAUSE,
            L"Паузирај"
        },
        LocalizedText{ TXT_RESUME,
            L"Настави"
        },
        LocalizedText{ TXT_HELP,
            L"Помоћ"
        },
        LocalizedText{ TXT_ABOUT,
            L"О програму"
        },
        LocalizedText{ TXT_CLOSE,
            L"Затвори"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Отвори веб-сајт %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Није могуће отворити страницу у подразумеваном прегледачу."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Није могуће копирати URL у оставу."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Није могуће копирати податке у оставу."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Конвејева Игра живота у заједничком свету на више монитора."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Верзија:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Циљна платформа:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Веб-сајт:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Отвори у подразумеваном прегледачу"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Копирај &адресу"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Копирај &податке"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Ресурс лиценце није доступан."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nПРАВИЛА\r\nКонвејева Игра живота користи B3/S23. Мртва ћелија оживи уз "
            L"тачно три жива суседа; жива преживи уз два или три. Осам суседа укључује дијагонале. Све "
            L"ћелије мењају се истовремено. Супротне ивице се спајају: лева с десном, горња с "
            L"доњом.\r\n\r\nМОНИТОРИ И ЗАЈЕДНИЧКИ СВЕТ\r\nПоља у EXE укључују мониторе; подешавања важе за "
            L"заједнички свет. Један укључен монитор садржи цео свет. При избору дела распореда потпуно "
            L"празни редови и колоне се уклањају: леви и десни монитор споје се после искључивања средњег. "
            L"Унутрашње рупе које се не могу уклонити остају у симулацији. Избор свих монитора или SCR "
            L"задржава правоугаоник радне површине с невидљивим празнинама. Сваки монитор приказује свој "
            L"део исте симулације.\r\n\r\nПОЧЕТНО СТАЊЕ И ОБРАСЦИ\r\nПодразумевани почетак је насумични "
            L"шум с 25 % живих ћелија. Почетна густина 0–100 % примењује се при следећем поновном "
            L"покретању. Само познати обрасци користи 4.106 приложених образаца без шума и искључује "
            L"густину. Изаберите мешавину или назив; димензије су у ћелијама. Куцајте назив за претрагу. "
            L"Нуде се само обрасци који стају цели. Мали проверени обрасци понављају се у одвојеним "
            L"копијама, велики или сложени једном у средини. Смањење света може превелик избор заменити "
            L"мешавином. Промена режима или обрасца ствара нову сцену. Поновна покретања чувају избор; "
            L"каталог ради без интернета.\r\n\r\nЋЕЛИЈЕ, МРЕЖА И БОЈЕ\r\nБез мреже величина ћелије је 1–64 "
            L"px. Мрежа додаје ивицу од 1 px унутар постојећег размака: приказ и клизач смањују се за "
            L"један, доступно је 1–63. Искључивање враћа вредност. Клизач задржава распон и враћа се с "
            L"недоступног краја; поље остаје активно. Пребацивање чува сцену, осим укључивања на 1 px: "
            L"размак постаје 2 px и сцена почиње изнова. Промена величине или монитора такође почиње "
            L"изнова. Веома велик свет може захтевати већи минимум. Боје ћелија, позадине и мреже мењају "
            L"се засебно без поновног покретања. Насумична боја живих ћелија бира нову боју при сваком "
            L"ручном или аутоматском поновном покретању сцене. Сачувана боја остаје и враћа се након "
            L"искључивања ове опције. Исто понашање може се засебно укључити за позадину и мрежу; обе нове "
            L"опције су подразумевано искључене.\r\n\r\nБРЗИНА, ПАУЗА И АУТОМАТСКО ПОНОВНО "
            L"ПОКРЕТАЊЕ\r\nБрзина је 0–240 генерација/с независно од освежавања; 0 зауставља развој. Пауза "
            L"и Настави чувају свет. Покрени поново почиње у изабраном режиму. Необавезно аутоматско "
            L"поновно покретање препознаје статичне и тачно поновљене видљиве фазе, укључујући осцилаторе. "
            L"Пореди генерације, не секунде; невидљива подручја изоставља. Асинхрони резултати могу мало "
            L"одложити поновно покретање. Подразумевано: размак 8 px, 20 генерација/с, насумична боја "
            L"живих ћелија и аутоматско поновно покретање укључени. Мрежа је подразумевано искључена. "
            L"Постигнута брзина зависи од перформанси и броја ћелија. Аутоматско поновно покретање пореди "
            L"подручја укључених монитора; празнине се и даље развијају, али се не укључују у "
            L"поређење.\r\n\r\nВрати вредности\r\nВраћање поставља приказану величину ћелије на 8 px с "
            L"мрежом или без ње (размак 9 или 8 px), брзину на 20 генерација/с, густину на 25 % и три "
            L"подразумеване боје. Остали избори остају; образац који више не стаје замењује се мешавином. "
            L"Нова сцена настаје само при промени размака или густине у режиму шума.\r\n\r\nСАМОСТАЛНА "
            L"АПЛИКАЦИЈА И MP4 СНИМАЊЕ\r\nEXE стално чува подешавања и снима први активни монитор у MP4. "
            L"Предлаже Видео-записе, иначе Документе. Viewport користи димензије и освежавање монитора до "
            L"60 кадрова/с. TV нуди 1920 × 1080, 1440 × 1080 или 1280 × 720 у 16:9 при 50, 25, 59,94 "
            L"(60000/1001) или 29,97 (30000/1001) кадрова/с. Однос се чува; TV користи прогресивни BT.709 "
            L"с ограниченим распоном и 4:2:0. Засебан прозор подешавања може се минимизовати. У реду чува "
            L"за следеће снимање; Откажи или Esc одбацује непотврђене измене. Снимани монитор не може се "
            L"искључити; остали излази могу се мењати. Излаз током снимања тражи потврду. Када је "
            L"анимација у фокусу, Размак мења паузу, F9: Покрени снимање; F10: Заустави снимање. Показивач "
            L"нестаје после 1 секунде мировања и враћа се померањем. Tab/Shift+Tab прелази између "
            L"контрола; Alt активира подвучене наредбе. Esc затвара Помоћ/О програму или излази из главног "
            L"прозора.\r\n\r\nСНИМАК СЛИКЕ И УПРАВЉАЊЕ ЧУВАРОМ У EXE\r\nСнимак слике чува "
            L"BMP/GIF/JPEG/PNG/TIFF/WebP монитора "
            L"који се снима, иначе првог активног, у његовој резолуцији без поновног покретања сцене. "
            L"Предлаже фасциклу Слике, иначе Документи. Блокирање чувара током анимације спречава његово "
            L"покретање док је анимација видљива и није паузирана. Нулта брзина није пауза. Инсталација из "
            L"EXE распакује приложени SCR и бира га као Windows чувар екрана. Инсталација и деинсталација "
            L"могу тражити одобрење администратора; статусна трака приказује радњу до завршетка. Ако је "
            L"уклањање блокирано, затворите покренути чувар, његова подешавања и Windows "
            L"преглед.\r\n\r\nWINDOWS ЧУВАР ЕКРАНА\r\nGameOfLife.scr користи све мониторе и подешавања "
            L"одвојена од EXE. Преглед покреће анимацију преко целог екрана уз отворена подешавања. Мали "
            L"Windows преглед смањује цео свет. У реду чува; Откажи или Esc одбацује измене. Померање миша "
            L"или тастер затвара чувар преко целог екрана. MP4 снимање је доступно у EXE.\r\n\r\nПОЛОЖАЈ И "
            L"СТАЊЕ ПРОЗОРА\r\nПри затварању се засебно чувају положаји главног прозора и прозора О "
            L"програму; за Помоћ и величина те нормално или максимизовано стање пре минимизовања. То не "
            L"зависи од потврђивања подешавања апликације. Затварање апликације затвара и Помоћ и О "
            L"програму.\r\n\r\nИСЦРТАВАЊЕ И ЛИЦЕНЦЕ ОБРАЗАЦА\r\nРазвој и поређење видљивих стања користе "
            L"Direct3D 11 шејдере на GPU-у; софтверско исцртавање је доступно ако хардверска "
            L"иницијализација не успе. Сваки монитор користи проверени регулатор кадрова при сопственом "
            L"освежавању. MP4 захтева Media Foundation и H.264 кодер. Обрасци долазе с LifeWiki (GFDL 1.2 "
            L"или новија) и из збирки Алана Хенсела у јавном власништву. Програмски код има MIT лиценцу; "
            L"обавештења и лиценце каталога су одвојени.\r\n\r\nЧувар екрана у Windows-у… отвара системска "
            L"подешавања чувара екрана."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nПРАВИЛА\r\nКонвејева Игра живота користи B3/S23. Мртва ћелија оживи уз "
            L"тачно три жива суседа; жива преживи уз два или три. Осам суседа укључује дијагонале. Све "
            L"ћелије мењају се истовремено. Супротне ивице се спајају: лева с десном, горња с "
            L"доњом.\r\n\r\nМОНИТОРИ И ЗАЈЕДНИЧКИ СВЕТ\r\nПоља у EXE укључују мониторе; подешавања важе за "
            L"заједнички свет. Један укључен монитор садржи цео свет. При избору дела распореда потпуно "
            L"празни редови и колоне се уклањају: леви и десни монитор споје се после искључивања средњег. "
            L"Унутрашње рупе које се не могу уклонити остају у симулацији. Избор свих монитора или SCR "
            L"задржава правоугаоник радне површине с невидљивим празнинама. Сваки монитор приказује свој "
            L"део исте симулације.\r\n\r\nПОЧЕТНО СТАЊЕ И ОБРАСЦИ\r\nПодразумевани почетак је насумични "
            L"шум с 25 % живих ћелија. Почетна густина 0–100 % примењује се при следећем поновном "
            L"покретању. Само познати обрасци користи 4.106 приложених образаца без шума и искључује "
            L"густину. Изаберите мешавину или назив; димензије су у ћелијама. Куцајте назив за претрагу. "
            L"Нуде се само обрасци који стају цели. Мали проверени обрасци понављају се у одвојеним "
            L"копијама, велики или сложени једном у средини. Смањење света може превелик избор заменити "
            L"мешавином. Промена режима или обрасца ствара нову сцену. Поновна покретања чувају избор; "
            L"каталог ради без интернета.\r\n\r\nЋЕЛИЈЕ, МРЕЖА И БОЈЕ\r\nБез мреже величина ћелије је 1–64 "
            L"px. Мрежа додаје ивицу од 1 px унутар постојећег размака: приказ и клизач смањују се за "
            L"један, доступно је 1–63. Искључивање враћа вредност. Клизач задржава распон и враћа се с "
            L"недоступног краја; поље остаје активно. Пребацивање чува сцену, осим укључивања на 1 px: "
            L"размак постаје 2 px и сцена почиње изнова. Промена величине или монитора такође почиње "
            L"изнова. Веома велик свет може захтевати већи минимум. Боје ћелија, позадине и мреже мењају "
            L"се засебно без поновног покретања. Насумична боја живих ћелија бира нову боју при сваком "
            L"ручном или аутоматском поновном покретању сцене. Сачувана боја остаје и враћа се након "
            L"искључивања ове опције. Исто понашање може се засебно укључити за позадину и мрежу; обе нове "
            L"опције су подразумевано искључене.\r\n\r\nБРЗИНА, ПАУЗА И АУТОМАТСКО ПОНОВНО "
            L"ПОКРЕТАЊЕ\r\nБрзина је 0–240 генерација/с независно од освежавања; 0 зауставља развој. Пауза "
            L"и Настави чувају свет. Покрени поново почиње у изабраном режиму. Необавезно аутоматско "
            L"поновно покретање препознаје статичне и тачно поновљене видљиве фазе, укључујући осцилаторе. "
            L"Пореди генерације, не секунде; невидљива подручја изоставља. Асинхрони резултати могу мало "
            L"одложити поновно покретање. Подразумевано: размак 8 px, 20 генерација/с, насумична боја "
            L"живих ћелија и аутоматско поновно покретање укључени. Мрежа је подразумевано искључена. "
            L"Постигнута брзина зависи од перформанси и броја ћелија. Аутоматско поновно покретање пореди "
            L"подручја укључених монитора; празнине се и даље развијају, али се не укључују у "
            L"поређење.\r\n\r\nВрати вредности\r\nВраћање поставља приказану величину ћелије на 8 px с "
            L"мрежом или без ње (размак 9 или 8 px), брзину на 20 генерација/с, густину на 25 % и три "
            L"подразумеване боје. Остали избори остају; образац који више не стаје замењује се мешавином. "
            L"Нова сцена настаје само при промени размака или густине у режиму шума.\r\n\r\nWINDOWS ЧУВАР "
            L"ЕКРАНА\r\nGameOfLife.scr користи све мониторе и подешавања одвојена од EXE. Преглед покреће "
            L"анимацију преко целог екрана уз отворена подешавања. Мали Windows преглед смањује цео свет. "
            L"У реду чува; Откажи или Esc одбацује измене. Померање миша или тастер затвара чувар преко "
            L"целог екрана. MP4 снимање је доступно у EXE.\r\n\r\nПОЛОЖАЈ И СТАЊЕ ПРОЗОРА\r\nПри затварању "
            L"се засебно чувају положаји главног прозора и прозора О програму; за Помоћ и величина те "
            L"нормално или максимизовано стање пре минимизовања. То не зависи од потврђивања подешавања "
            L"апликације. Затварање апликације затвара и Помоћ и О програму.\r\n\r\nИСЦРТАВАЊЕ И ЛИЦЕНЦЕ "
            L"ОБРАЗАЦА\r\nРазвој и поређење видљивих стања користе Direct3D 11 шејдере на GPU-у; "
            L"софтверско исцртавање је доступно ако хардверска иницијализација не успе. Сваки монитор "
            L"користи проверени регулатор кадрова при сопственом освежавању. MP4 захтева Media Foundation "
            L"и H.264 кодер. Обрасци долазе с LifeWiki (GFDL 1.2 или новија) и из збирки Алана Хенсела у "
            L"јавном власништву. Програмски код има MIT лиценцу; обавештења и лиценце каталога су "
            L"одвојени."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Величина ћелије: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Брзина: %u генерација/с"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Почетна густина: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Поново покрени сцену" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Боја живих ћелија…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Боја позадине…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Изабрани монитори деле свет. Празне траке се уклањају; унутрашње рупе остају."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Анимација је покренута…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Анимација је паузирана."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Није могуће иницијализовати Direct3D приказивач."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW,
            L"Укључи преглед"
        },
        LocalizedText{ TXT_DISABLE_PREVIEW,
            L"Искључи преглед"
        },
        LocalizedText{ TXT_MONITOR,
            L"Монитор"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Резолуција"
        },
        LocalizedText{ TXT_POSITION,
            L"Положај"
        },
        LocalizedText{ TXT_PRIMARY,
            L"примарни"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Модел монитора"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Учестаност освежавања"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Дубина бита"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Формат боје"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Простор боја"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u бита/канал"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u бита/пиксел"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Монитор анимације"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Спреман"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Прикажи мрежу"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Боја мреже…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Аутоматски поново покрени мирну или понављајућу видљиву сцену"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Само познати обрасци"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Покрени снимање…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Заустави снимање"
        },
        LocalizedText{ TXT_RECORDING,
            L"MP4 снимање је у току…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Снимак је сачуван."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Није могуће покренути MP4 снимање."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Затварање апликације зауставиће снимање које је у току."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Подешавања снимања"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Резолуција:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Број кадрова у секунди:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Промене се примењују на следеће MP4 снимање."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Мешавина одговарајућих образаца"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Изабрани образац више не стаје. Изабрана је одговарајућа мешавина."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Није могуће учитати каталог познатих образаца."
        },
    }),
    DefineLanguage(LANG_UK, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR,
            L"Випадковий колір тла під час кожного перезапуску сцени"
        },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Випадковий колір сітки під час кожного перезапуску сцени" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Заставка Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED, L"Не вдалося відкрити параметри заставки Windows." },
        LocalizedText{ TXT_RESET_SETTINGS, L"Скинути значення" },
        LocalizedText{ TXT_SNAPSHOT, L"Знімок…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Зображення BMP/GIF/JPEG/PNG/TIFF/WebP збережено." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Не вдалося зберегти зображення BMP/GIF/JPEG/PNG/TIFF/WebP." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Блокувати заставку під час анімації" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Випадковий колір живих клітин під час кожного перезапуску сцени"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Триває встановлення заставки…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Триває видалення заставки…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Установити заставку" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Видалити заставку" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Заставку не встановлено." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Заставку встановлено." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Заставку видалено." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Не вдалося видалити заставку. Закрийте заставку та її попередній перегляд і спробуйте ще раз."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Закрийте налаштування GameOfLife та повторіть видалення."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Закрийте налаштування заставки Windows та повторіть видалення."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Завершіть заставку або повноекранний попередній перегляд клавішею Esc чи рухом миші та "
            L"повторіть видалення."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Українська"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — керування"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Налаштування GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Мова:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Скасувати"
        },
        LocalizedText{ TXT_EXIT,
            L"Вийти"
        },
        LocalizedText{ TXT_PAUSE,
            L"Призупинити"
        },
        LocalizedText{ TXT_RESUME,
            L"Продовжити"
        },
        LocalizedText{ TXT_HELP,
            L"Довідка"
        },
        LocalizedText{ TXT_ABOUT,
            L"Про програму"
        },
        LocalizedText{ TXT_CLOSE,
            L"Закрити"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Відкрити вебсайт %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Не вдається відкрити сайт у типовому браузері."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Не вдалося скопіювати URL у буфер обміну."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Не вдалося скопіювати відомості в буфер обміну."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Гра «Життя» Конвея у спільному світі на кількох моніторах."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Версія:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Цільова платформа:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Вебсайт:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Відкрити в типовому браузері"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Копіювати &адресу"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Копіювати &відомості"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Ресурс ліцензії недоступний."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nПРАВИЛА\r\nГра «Життя» Конвея використовує B3/S23. Мертва клітина оживає "
            L"за рівно трьох живих сусідів; жива виживає за двох або трьох. Вісім сусідів охоплюють "
            L"діагоналі. Усі клітини змінюються одночасно. Протилежні краї з'єднані: лівий із правим, "
            L"верхній із нижнім.\r\n\r\nМОНІТОРИ ТА СПІЛЬНИЙ СВІТ\r\nПрапорці в EXE вмикають монітори; "
            L"налаштування стосуються спільного світу. Один увімкнений монітор містить увесь світ. При "
            L"частковому виборі цілком порожні рядки й стовпці прибираються: лівий і правий монітори "
            L"з'єднуються після вимкнення середнього. Внутрішні отвори, які не можна прибрати, залишаються "
            L"в симуляції. Вибір усіх моніторів або SCR зберігає прямокутник робочого стола з невидимими "
            L"проміжками. Кожен монітор показує свою частину тієї самої симуляції.\r\n\r\nПОЧАТКОВИЙ СТАН "
            L"І ВІЗЕРУНКИ\r\nТиповий початок — випадковий шум із 25 % живих клітин. Початкова щільність "
            L"0–100 % застосовується при наступному перезапуску. Лише відомі візерунки використовує 4 106 "
            L"вбудованих візерунків без шуму й вимикає щільність. Виберіть суміш або назву; розміри "
            L"вказані у клітинах. Для пошуку вводьте назву. Пропонуються лише візерунки, що вміщуються "
            L"повністю. Малі перевірені візерунки повторюються окремими копіями, великі або складні "
            L"з'являються один раз у центрі. Зменшення світу може замінити завеликий вибір сумішшю. Зміна "
            L"режиму чи візерунка створює нову сцену. Перезапуски зберігають вибір; каталог працює без "
            L"інтернету.\r\n\r\nКЛІТИНИ, СІТКА ТА КОЛЬОРИ\r\nБез сітки розмір клітини 1–64 px. Сітка додає "
            L"край 1 px усередині наявного кроку: показане значення й повзунок зменшуються на один, "
            L"доступно 1–63. Вимкнення повертає значення. Повзунок зберігає діапазон і повертається з "
            L"недоступного кінця; прапорець залишається активним. Перемикання зберігає сцену, крім "
            L"увімкнення при 1 px: крок стає 2 px і починається нова сцена. Зміна розміру чи моніторів "
            L"також починає заново. Дуже великий світ може вимагати вищого мінімуму. Кольори клітин, тла й "
            L"сітки змінюються окремо без перезапуску. Випадковий колір живих клітин обирається заново при "
            L"кожному ручному або автоматичному перезапуску сцени. Збережений колір не перезаписується й "
            L"повертається після вимкнення цієї опції. Таку саму поведінку можна окремо ввімкнути для тла "
            L"й сітки; обидва нові параметри спочатку вимкнені.\r\n\r\nШВИДКІСТЬ, ПАУЗА Й АВТОМАТИЧНИЙ "
            L"ПЕРЕЗАПУСК\r\nШвидкість 0–240 поколінь/с не залежить від оновлення монітора; 0 зупиняє "
            L"розвиток. Пауза та Продовжити зберігають світ. Почати заново запускає вибраний режим. "
            L"Необов'язковий автоматичний перезапуск розпізнає статичні й точно повторювані видимі фази, "
            L"включно з осциляторами. Він порівнює покоління, не секунди; невидимі ділянки виключаються. "
            L"Асинхронні результати можуть трохи затримати перезапуск. Типово: крок 8 px, 20 поколінь/с, "
            L"випадковий колір живих клітин і автоматичний перезапуск увімкнені. Сітка типово вимкнена. "
            L"Досягнута швидкість залежить від продуктивності й кількості клітин. Автоматичний перезапуск "
            L"порівнює ділянки ввімкнених моніторів; проміжки продовжують розвиватися, але не беруть "
            L"участі в порівнянні.\r\n\r\nСкинути значення\r\nСкидання задає відображуваний розмір "
            L"клітинки 8 px із сіткою або без неї (крок 9 або 8 px), швидкість 20 поколінь/с, щільність 25 "
            L"% і три типові кольори. Інші вибори зберігаються; візерунок, що більше не вміщується, "
            L"замінюється сумішшю. Нова сцена створюється лише за зміни кроку або щільності в режимі "
            L"шуму.\r\n\r\nОКРЕМА ПРОГРАМА ТА ЗАПИС MP4\r\nEXE постійно зберігає налаштування й записує "
            L"перший активний монітор у MP4. Пропонується папка Відео, інакше Документи. Viewport "
            L"використовує розміри й оновлення монітора до 60 кадрів/с. TV пропонує 1920 × 1080, 1440 × "
            L"1080 або 1280 × 720 у 16:9 при 50, 25, 59,94 (60000/1001) або 29,97 (30000/1001) кадрах/с. "
            L"Пропорції зберігаються; TV використовує прогресивний BT.709 з обмеженим діапазоном і 4:2:0. "
            L"Окреме вікно налаштувань можна згорнути. OK зберігає для наступного запису; Скасувати чи Esc "
            L"відхиляє непідтверджені зміни. Монітор запису не можна вимкнути; інші виходи можна "
            L"змінювати. Вихід під час запису потребує підтвердження. Коли анімація у фокусі, Пробіл "
            L"перемикає паузу, F9: Почати запис; F10: Зупинити запис. Курсор зникає після 1 секунди "
            L"бездіяльності й повертається при русі. Tab/Shift+Tab переходить між елементами, Alt запускає "
            L"підкреслені команди. Esc закриває Довідку/Про програму або завершує програму в головному "
            L"вікні.\r\n\r\nЗНІМОК І КЕРУВАННЯ ЗАСТАВКОЮ В EXE\r\nЗнімок зберігає BMP/GIF/JPEG/PNG/TIFF/WebP "
            L"монітора, що "
            L"записується, інакше першого активного, з його роздільністю без перезапуску сцени. "
            L"Пропонується папка Зображення, інакше Документи. Блокування заставки під час анімації "
            L"запобігає її запуску, поки анімація видима й не призупинена. Нульова швидкість не є паузою. "
            L"Встановлення з EXE розпаковує вбудований SCR і вибирає його як заставку Windows. "
            L"Встановлення й видалення можуть потребувати дозволу адміністратора; рядок стану показує "
            L"операцію до її завершення. Якщо видалення заблоковане, закрийте запущену заставку, її "
            L"налаштування й перегляд Windows.\r\n\r\nЗАСТАВКА WINDOWS\r\nGameOfLife.scr використовує всі "
            L"монітори й окремі від EXE налаштування. Перегляд запускає повноекранну анімацію з відкритими "
            L"налаштуваннями. Малий перегляд Windows зменшує увесь світ. OK зберігає; Скасувати чи Esc "
            L"відхиляє зміни. Рух миші або клавіша закриває повноекранну заставку. Запис MP4 доступний в "
            L"EXE.\r\n\r\nРОЗТАШУВАННЯ Й СТАН ВІКОН\r\nПри закритті окремо зберігаються розташування "
            L"головного вікна й вікна Про програму; для Довідки також розмір і звичайний або розгорнутий "
            L"стан перед згортанням. Це не залежить від підтвердження налаштувань програми. Вихід із "
            L"програми закриває також Довідку й Про програму.\r\n\r\nВІДТВОРЕННЯ ТА ЛІЦЕНЗІЇ "
            L"ВІЗЕРУНКІВ\r\nРозвиток і порівняння видимих станів використовують шейдери Direct3D 11 на "
            L"GPU; при невдалій апаратній ініціалізації доступне програмне відтворення. Кожен монітор "
            L"використовує перевірене регулювання кадрів зі своєю частотою. MP4 потребує Media Foundation "
            L"і кодувальника H.264. Візерунки походять із LifeWiki (GFDL 1.2 або новіша) і колекцій Алана "
            L"Генсела в суспільному надбанні. Код має ліцензію MIT; повідомлення й ліцензії каталогу "
            L"окремі.\r\n\r\nЗаставка Windows… відкриває системні параметри заставки."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nПРАВИЛА\r\nГра «Життя» Конвея використовує B3/S23. Мертва клітина оживає "
            L"за рівно трьох живих сусідів; жива виживає за двох або трьох. Вісім сусідів охоплюють "
            L"діагоналі. Усі клітини змінюються одночасно. Протилежні краї з'єднані: лівий із правим, "
            L"верхній із нижнім.\r\n\r\nМОНІТОРИ ТА СПІЛЬНИЙ СВІТ\r\nПрапорці в EXE вмикають монітори; "
            L"налаштування стосуються спільного світу. Один увімкнений монітор містить увесь світ. При "
            L"частковому виборі цілком порожні рядки й стовпці прибираються: лівий і правий монітори "
            L"з'єднуються після вимкнення середнього. Внутрішні отвори, які не можна прибрати, залишаються "
            L"в симуляції. Вибір усіх моніторів або SCR зберігає прямокутник робочого стола з невидимими "
            L"проміжками. Кожен монітор показує свою частину тієї самої симуляції.\r\n\r\nПОЧАТКОВИЙ СТАН "
            L"І ВІЗЕРУНКИ\r\nТиповий початок — випадковий шум із 25 % живих клітин. Початкова щільність "
            L"0–100 % застосовується при наступному перезапуску. Лише відомі візерунки використовує 4 106 "
            L"вбудованих візерунків без шуму й вимикає щільність. Виберіть суміш або назву; розміри "
            L"вказані у клітинах. Для пошуку вводьте назву. Пропонуються лише візерунки, що вміщуються "
            L"повністю. Малі перевірені візерунки повторюються окремими копіями, великі або складні "
            L"з'являються один раз у центрі. Зменшення світу може замінити завеликий вибір сумішшю. Зміна "
            L"режиму чи візерунка створює нову сцену. Перезапуски зберігають вибір; каталог працює без "
            L"інтернету.\r\n\r\nКЛІТИНИ, СІТКА ТА КОЛЬОРИ\r\nБез сітки розмір клітини 1–64 px. Сітка додає "
            L"край 1 px усередині наявного кроку: показане значення й повзунок зменшуються на один, "
            L"доступно 1–63. Вимкнення повертає значення. Повзунок зберігає діапазон і повертається з "
            L"недоступного кінця; прапорець залишається активним. Перемикання зберігає сцену, крім "
            L"увімкнення при 1 px: крок стає 2 px і починається нова сцена. Зміна розміру чи моніторів "
            L"також починає заново. Дуже великий світ може вимагати вищого мінімуму. Кольори клітин, тла й "
            L"сітки змінюються окремо без перезапуску. Випадковий колір живих клітин обирається заново при "
            L"кожному ручному або автоматичному перезапуску сцени. Збережений колір не перезаписується й "
            L"повертається після вимкнення цієї опції. Таку саму поведінку можна окремо ввімкнути для тла "
            L"й сітки; обидва нові параметри спочатку вимкнені.\r\n\r\nШВИДКІСТЬ, ПАУЗА Й АВТОМАТИЧНИЙ "
            L"ПЕРЕЗАПУСК\r\nШвидкість 0–240 поколінь/с не залежить від оновлення монітора; 0 зупиняє "
            L"розвиток. Пауза та Продовжити зберігають світ. Почати заново запускає вибраний режим. "
            L"Необов'язковий автоматичний перезапуск розпізнає статичні й точно повторювані видимі фази, "
            L"включно з осциляторами. Він порівнює покоління, не секунди; невидимі ділянки виключаються. "
            L"Асинхронні результати можуть трохи затримати перезапуск. Типово: крок 8 px, 20 поколінь/с, "
            L"випадковий колір живих клітин і автоматичний перезапуск увімкнені. Сітка типово вимкнена. "
            L"Досягнута швидкість залежить від продуктивності й кількості клітин. Автоматичний перезапуск "
            L"порівнює ділянки ввімкнених моніторів; проміжки продовжують розвиватися, але не беруть "
            L"участі в порівнянні.\r\n\r\nСкинути значення\r\nСкидання задає відображуваний розмір "
            L"клітинки 8 px із сіткою або без неї (крок 9 або 8 px), швидкість 20 поколінь/с, щільність 25 "
            L"% і три типові кольори. Інші вибори зберігаються; візерунок, що більше не вміщується, "
            L"замінюється сумішшю. Нова сцена створюється лише за зміни кроку або щільності в режимі "
            L"шуму.\r\n\r\nЗАСТАВКА WINDOWS\r\nGameOfLife.scr використовує всі монітори й окремі від EXE "
            L"налаштування. Перегляд запускає повноекранну анімацію з відкритими налаштуваннями. Малий "
            L"перегляд Windows зменшує увесь світ. OK зберігає; Скасувати чи Esc відхиляє зміни. Рух миші "
            L"або клавіша закриває повноекранну заставку. Запис MP4 доступний в EXE.\r\n\r\nРОЗТАШУВАННЯ Й "
            L"СТАН ВІКОН\r\nПри закритті окремо зберігаються розташування головного вікна й вікна Про "
            L"програму; для Довідки також розмір і звичайний або розгорнутий стан перед згортанням. Це не "
            L"залежить від підтвердження налаштувань програми. Вихід із програми закриває також Довідку й "
            L"Про програму.\r\n\r\nВІДТВОРЕННЯ ТА ЛІЦЕНЗІЇ ВІЗЕРУНКІВ\r\nРозвиток і порівняння видимих "
            L"станів використовують шейдери Direct3D 11 на GPU; при невдалій апаратній ініціалізації "
            L"доступне програмне відтворення. Кожен монітор використовує перевірене регулювання кадрів зі "
            L"своєю частотою. MP4 потребує Media Foundation і кодувальника H.264. Візерунки походять із "
            L"LifeWiki (GFDL 1.2 або новіша) і колекцій Алана Генсела в суспільному надбанні. Код має "
            L"ліцензію MIT; повідомлення й ліцензії каталогу окремі."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Розмір клітини: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Швидкість: %u поколінь/с"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Початкова щільність: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Перезапустити сцену" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Колір живих клітин…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Колір тла…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Вибрані монітори мають спільний світ. Порожні смуги прибираються; внутрішні отвори залишаються."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Анімація працює…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Анімацію призупинено."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Не вдалося ініціалізувати візуалізатор Direct3D."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Перегляд" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Зупинити перегляд" },
        LocalizedText{ TXT_MONITOR,
            L"Монітор"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Роздільна здатність"
        },
        LocalizedText{ TXT_POSITION,
            L"Розташування"
        },
        LocalizedText{ TXT_PRIMARY,
            L"основний"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Модель монітора"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Частота оновлення"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Бітова глибина"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Формат кольору"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Колірний простір"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u біт/канал"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u біт/піксель"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Монітор анімації"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Готовий"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Показувати сітку"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Колір сітки…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Автоматично починати заново сталу або повторювану видиму сцену"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Лише відомі візерунки"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Почати запис…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Зупинити запис"
        },
        LocalizedText{ TXT_RECORDING,
            L"Триває запис MP4…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Запис збережено."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Не вдалося почати запис MP4."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Закриття програми зупинить поточний запис."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Налаштування запису"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Роздільна здатність:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Частота кадрів:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Зміни буде застосовано до наступного запису MP4."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Суміш відповідних візерунків"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Вибраний візерунок більше не вміщується. Вибрано відповідну суміш."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Не вдалося завантажити каталог відомих візерунків."
        },
    }),
    DefineLanguage(LANG_RU, std::initializer_list<LocalizedText>{
        LocalizedText{ TXT_RANDOM_BACKGROUND_COLOR, L"Случайный цвет фона при каждом перезапуске сцены" },
        LocalizedText{ TXT_RANDOM_GRID_COLOR, L"Случайный цвет сетки при каждом перезапуске сцены" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER, L"Заставка Windows…" },
        LocalizedText{ TXT_SYSTEM_SCREEN_SAVER_FAILED, L"Не удалось открыть параметры заставки Windows." },
        LocalizedText{ TXT_RESET_SETTINGS, L"Сбросить значения" },
        LocalizedText{ TXT_SNAPSHOT, L"Снимок…" },
        LocalizedText{ TXT_SNAPSHOT_SAVED, L"Изображение BMP/GIF/JPEG/PNG/TIFF/WebP сохранено." },
        LocalizedText{ TXT_SNAPSHOT_FAILED, L"Не удалось сохранить изображение BMP/GIF/JPEG/PNG/TIFF/WebP." },
        LocalizedText{ TXT_PREVENT_SCREEN_SAVER, L"Блокировать заставку во время анимации" },
        LocalizedText{ TXT_RANDOM_ALIVE_COLOR,
            L"Случайный цвет живых клеток при каждом перезапуске сцены"
        },
        LocalizedText{ TXT_INSTALLING_SCREEN_SAVER, L"Выполняется установка заставки…" },
        LocalizedText{ TXT_UNINSTALLING_SCREEN_SAVER, L"Выполняется удаление заставки…" },
        LocalizedText{ TXT_INSTALL_SCREEN_SAVER, L"Установить заставку" },
        LocalizedText{ TXT_UNINSTALL_SCREEN_SAVER, L"Удалить заставку" },
        LocalizedText{ TXT_INSTALLATION_FAILED, L"Заставка не установлена." },
        LocalizedText{ TXT_INSTALLATION_SUCCEEDED, L"Заставка установлена." },
        LocalizedText{ TXT_UNINSTALLATION_SUCCEEDED, L"Заставка удалена." },
        LocalizedText{ TXT_UNINSTALLATION_FAILED,
            L"Не удалось удалить заставку. Закройте заставку и её предпросмотр и повторите попытку."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SETTINGS,
            L"Закройте настройки GameOfLife и повторите удаление."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW,
            L"Закройте настройки заставки Windows и повторите удаление."
        },
        LocalizedText{ TXT_UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER,
            L"Завершите заставку или полноэкранный предпросмотр клавишей Esc либо движением мыши и повторите "
            L"удаление."
        },
        LocalizedText{ TXT_LANGUAGE_NAME,
            L"Русский"
        },
        LocalizedText{ TXT_CONTROL_TITLE,
            L"GameOfLife — управление"
        },
        LocalizedText{ TXT_SETTINGS_TITLE,
            L"Настройки GameOfLife"
        },
        LocalizedText{ TXT_LANGUAGE,
            L"Язык:"
        },
        LocalizedText{ TXT_OK,
            L"OK"
        },
        LocalizedText{ TXT_CANCEL,
            L"Отмена"
        },
        LocalizedText{ TXT_EXIT,
            L"Выход"
        },
        LocalizedText{ TXT_PAUSE,
            L"Приостановить"
        },
        LocalizedText{ TXT_RESUME,
            L"Продолжить"
        },
        LocalizedText{ TXT_HELP,
            L"Справка"
        },
        LocalizedText{ TXT_ABOUT,
            L"О программе"
        },
        LocalizedText{ TXT_CLOSE,
            L"Закрыть"
        },
        LocalizedText{ TXT_ABOUT_VISIT_TOOLTIP,
            L"Открыть веб-сайт %ls"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_FAILED,
            L"Не удаётся открыть сайт в браузере по умолчанию."
        },
        LocalizedText{ TXT_ABOUT_COPY_URL_FAILED,
            L"Не удалось скопировать URL в буфер обмена."
        },
        LocalizedText{ TXT_ABOUT_COPY_INFORMATION_FAILED,
            L"Не удалось скопировать сведения в буфер обмена."
        },
        LocalizedText{ TXT_ABOUT_DESCRIPTION,
            L"Игра «Жизнь» Конвея в общем мире на нескольких мониторах."
        },
        LocalizedText{ TXT_ABOUT_VERSION_LABEL,
            L"Версия:"
        },
        LocalizedText{ TXT_ABOUT_PLATFORM_LABEL,
            L"Целевая платформа:"
        },
        LocalizedText{ TXT_ABOUT_WEBSITE_LABEL,
            L"Веб-сайт:"
        },
        LocalizedText{ TXT_OPEN_IN_BROWSER,
            L"&Открыть в браузере по умолчанию"
        },
        LocalizedText{ TXT_COPY_URL,
            L"Копировать &адрес"
        },
        LocalizedText{ TXT_COPY_INFORMATION,
            L"Копировать &сведения"
        },
        LocalizedText{ TXT_ABOUT_LICENSE_UNAVAILABLE,
            L"Ресурс лицензии недоступен."
        },
        LocalizedText{ TXT_APPLICATION_HELP,
            L"GameOfLife\r\n\r\nПРАВИЛА\r\nИгра «Жизнь» Конвея использует B3/S23. Мёртвая клетка рождается "
            L"при ровно трёх живых соседях; живая выживает при двух или трёх. Восемь соседей включают "
            L"диагонали. Все клетки меняются одновременно. Противоположные края соединены: левый с правым, "
            L"верхний с нижним.\r\n\r\nМОНИТОРЫ И ОБЩИЙ МИР\r\nФлажки в EXE включают мониторы; настройки "
            L"относятся к общему миру. Один включённый монитор содержит весь мир. При частичном выборе "
            L"полностью пустые строки и столбцы удаляются: левый и правый мониторы соединяются после "
            L"отключения среднего. Неудаляемые внутренние отверстия остаются в симуляции. Выбор всех "
            L"мониторов или SCR сохраняет прямоугольник рабочего стола с невидимыми промежутками. Каждый "
            L"монитор показывает свою часть той же симуляции.\r\n\r\nНАЧАЛЬНОЕ СОСТОЯНИЕ И "
            L"УЗОРЫ\r\nНачальное состояние по умолчанию — случайный шум с 25 % живых клеток. Начальная "
            L"плотность 0–100 % применяется при следующем перезапуске. Только известные узоры использует 4 "
            L"106 встроенных узоров без шума и отключает плотность. Выберите смесь или название; размеры "
            L"указаны в клетках. Для поиска вводите название. Предлагаются только узоры, помещающиеся "
            L"целиком. Маленькие проверенные узоры повторяются отдельными копиями, большие или сложные "
            L"появляются один раз в центре. Уменьшение мира может заменить слишком большой выбор смесью. "
            L"Смена режима или узора создаёт новую сцену. Перезапуски сохраняют выбор; каталог работает "
            L"без интернета.\r\n\r\nКЛЕТКИ, СЕТКА И ЦВЕТА\r\nБез сетки размер клетки 1–64 px. Сетка "
            L"добавляет край 1 px внутри существующего шага: показанное значение и ползунок уменьшаются на "
            L"один, доступны 1–63. Отключение возвращает значение. Ползунок сохраняет диапазон и "
            L"возвращается с недоступного конца; флажок остаётся активным. Переключение сохраняет сцену, "
            L"кроме включения при 1 px: шаг становится 2 px и начинается новая сцена. Смена размера или "
            L"мониторов тоже начинает заново. Очень большой мир может требовать большего минимума. Цвета "
            L"клеток, фона и сетки меняются отдельно без перезапуска. Случайный цвет живых клеток "
            L"выбирается заново при каждом ручном или автоматическом перезапуске сцены. Сохранённый цвет "
            L"не перезаписывается и возвращается после отключения этой опции. Такое же поведение можно "
            L"отдельно включить для фона и сетки; обе новые опции изначально выключены.\r\n\r\nСКОРОСТЬ, "
            L"ПАУЗА И АВТОМАТИЧЕСКИЙ ПЕРЕЗАПУСК\r\nСкорость 0–240 поколений/с не зависит от обновления "
            L"монитора; 0 останавливает развитие. Пауза и Продолжить сохраняют мир. Начать заново "
            L"запускает выбранный режим. Необязательный автоматический перезапуск распознаёт статические и "
            L"точно повторяющиеся видимые фазы, включая осцилляторы. Он сравнивает поколения, не секунды; "
            L"невидимые области исключаются. Асинхронные результаты могут немного задержать перезапуск. По "
            L"умолчанию: шаг 8 px, 20 поколений/с, случайный цвет живых клеток и автоматический перезапуск "
            L"включены. Сетка по умолчанию выключена. Достигнутая скорость зависит от производительности и "
            L"числа клеток. Автоматический перезапуск сравнивает области включённых мониторов; промежутки "
            L"продолжают развиваться, но не участвуют в сравнении.\r\n\r\nСбросить значения\r\nСброс "
            L"задаёт отображаемый размер клетки 8 px с сеткой или без неё (шаг 9 или 8 px), скорость 20 "
            L"поколений/с, плотность 25 % и три цвета по умолчанию. Другие настройки сохраняются; узор, "
            L"который больше не помещается, заменяется смесью. Новая сцена создаётся только при изменении "
            L"шага или плотности в режиме шума.\r\n\r\nОТДЕЛЬНОЕ ПРИЛОЖЕНИЕ И ЗАПИСЬ MP4\r\nEXE постоянно "
            L"сохраняет настройки и записывает первый активный монитор в MP4. Предлагается папка Видео, "
            L"иначе Документы. Viewport использует размеры и обновление монитора до 60 кадров/с. TV "
            L"предлагает 1920 × 1080, 1440 × 1080 или 1280 × 720 в 16:9 при 50, 25, 59,94 (60000/1001) или "
            L"29,97 (30000/1001) кадрах/с. Пропорции сохраняются; TV использует прогрессивный BT.709 с "
            L"ограниченным диапазоном и 4:2:0. Отдельное окно настроек можно свернуть. OK сохраняет для "
            L"следующей записи; Отмена или Esc отклоняет неподтверждённые изменения. Записываемый монитор "
            L"нельзя отключить; другие выходы можно менять. Выход во время записи требует подтверждения. "
            L"Когда анимация в фокусе, Пробел переключает паузу, F9: Начать запись; F10: Остановить "
            L"запись. Курсор исчезает после 1 секунды бездействия и возвращается при движении. "
            L"Tab/Shift+Tab перемещается между элементами, Alt запускает подчёркнутые команды. Esc "
            L"закрывает Справку/О программе или завершает приложение в главном окне.\r\n\r\nСНИМОК И "
            L"УПРАВЛЕНИЕ ЗАСТАВКОЙ В EXE\r\nСнимок сохраняет BMP/GIF/JPEG/PNG/TIFF/WebP записываемого "
            L"монитора, иначе первого "
            L"активного, в его разрешении без перезапуска сцены. Предлагается папка Изображения, иначе "
            L"Документы. Блокировка заставки во время анимации предотвращает её запуск, пока анимация "
            L"видима и не приостановлена. Нулевая скорость не является паузой. Установка из EXE "
            L"распаковывает встроенный SCR и выбирает его как заставку Windows. Установка и удаление могут "
            L"требовать разрешения администратора; строка состояния показывает операцию до завершения. "
            L"Если удаление заблокировано, закройте работающую заставку, её настройки и предпросмотр "
            L"Windows.\r\n\r\nЗАСТАВКА WINDOWS\r\nGameOfLife.scr использует все мониторы и отдельные от "
            L"EXE настройки. Предпросмотр запускает полноэкранную анимацию с открытыми настройками. "
            L"Маленький предпросмотр Windows уменьшает весь мир. OK сохраняет; Отмена или Esc отклоняет "
            L"изменения. Движение мыши или клавиша закрывает полноэкранную заставку. Запись MP4 доступна в "
            L"EXE.\r\n\r\nПОЛОЖЕНИЕ И СОСТОЯНИЕ ОКОН\r\nПри закрытии отдельно сохраняются положения "
            L"главного окна и окна О программе; для Справки также размер и обычное или развёрнутое "
            L"состояние до сворачивания. Это не зависит от подтверждения настроек приложения. Выход из "
            L"приложения закрывает также Справку и О программе.\r\n\r\nОТРИСОВКА И ЛИЦЕНЗИИ "
            L"УЗОРОВ\r\nРазвитие и сравнения видимых состояний используют шейдеры Direct3D 11 на GPU; при "
            L"неудачной аппаратной инициализации доступна программная отрисовка. Каждый монитор использует "
            L"проверенное регулирование кадров со своей частотой. MP4 требует Media Foundation и "
            L"кодировщика H.264. Узоры взяты из LifeWiki (GFDL 1.2 или новее) и коллекций Алана Хенсела в "
            L"общественном достоянии. Код имеет лицензию MIT; уведомления и лицензии каталога "
            L"отдельные.\r\n\r\nЗаставка Windows… открывает системные параметры заставки."
        },
        LocalizedText{ TXT_SCREEN_SAVER_HELP,
            L"GameOfLife\r\n\r\nПРАВИЛА\r\nИгра «Жизнь» Конвея использует B3/S23. Мёртвая клетка рождается "
            L"при ровно трёх живых соседях; живая выживает при двух или трёх. Восемь соседей включают "
            L"диагонали. Все клетки меняются одновременно. Противоположные края соединены: левый с правым, "
            L"верхний с нижним.\r\n\r\nМОНИТОРЫ И ОБЩИЙ МИР\r\nФлажки в EXE включают мониторы; настройки "
            L"относятся к общему миру. Один включённый монитор содержит весь мир. При частичном выборе "
            L"полностью пустые строки и столбцы удаляются: левый и правый мониторы соединяются после "
            L"отключения среднего. Неудаляемые внутренние отверстия остаются в симуляции. Выбор всех "
            L"мониторов или SCR сохраняет прямоугольник рабочего стола с невидимыми промежутками. Каждый "
            L"монитор показывает свою часть той же симуляции.\r\n\r\nНАЧАЛЬНОЕ СОСТОЯНИЕ И "
            L"УЗОРЫ\r\nНачальное состояние по умолчанию — случайный шум с 25 % живых клеток. Начальная "
            L"плотность 0–100 % применяется при следующем перезапуске. Только известные узоры использует 4 "
            L"106 встроенных узоров без шума и отключает плотность. Выберите смесь или название; размеры "
            L"указаны в клетках. Для поиска вводите название. Предлагаются только узоры, помещающиеся "
            L"целиком. Маленькие проверенные узоры повторяются отдельными копиями, большие или сложные "
            L"появляются один раз в центре. Уменьшение мира может заменить слишком большой выбор смесью. "
            L"Смена режима или узора создаёт новую сцену. Перезапуски сохраняют выбор; каталог работает "
            L"без интернета.\r\n\r\nКЛЕТКИ, СЕТКА И ЦВЕТА\r\nБез сетки размер клетки 1–64 px. Сетка "
            L"добавляет край 1 px внутри существующего шага: показанное значение и ползунок уменьшаются на "
            L"один, доступны 1–63. Отключение возвращает значение. Ползунок сохраняет диапазон и "
            L"возвращается с недоступного конца; флажок остаётся активным. Переключение сохраняет сцену, "
            L"кроме включения при 1 px: шаг становится 2 px и начинается новая сцена. Смена размера или "
            L"мониторов тоже начинает заново. Очень большой мир может требовать большего минимума. Цвета "
            L"клеток, фона и сетки меняются отдельно без перезапуска. Случайный цвет живых клеток "
            L"выбирается заново при каждом ручном или автоматическом перезапуске сцены. Сохранённый цвет "
            L"не перезаписывается и возвращается после отключения этой опции. Такое же поведение можно "
            L"отдельно включить для фона и сетки; обе новые опции изначально выключены.\r\n\r\nСКОРОСТЬ, "
            L"ПАУЗА И АВТОМАТИЧЕСКИЙ ПЕРЕЗАПУСК\r\nСкорость 0–240 поколений/с не зависит от обновления "
            L"монитора; 0 останавливает развитие. Пауза и Продолжить сохраняют мир. Начать заново "
            L"запускает выбранный режим. Необязательный автоматический перезапуск распознаёт статические и "
            L"точно повторяющиеся видимые фазы, включая осцилляторы. Он сравнивает поколения, не секунды; "
            L"невидимые области исключаются. Асинхронные результаты могут немного задержать перезапуск. По "
            L"умолчанию: шаг 8 px, 20 поколений/с, случайный цвет живых клеток и автоматический перезапуск "
            L"включены. Сетка по умолчанию выключена. Достигнутая скорость зависит от производительности и "
            L"числа клеток. Автоматический перезапуск сравнивает области включённых мониторов; промежутки "
            L"продолжают развиваться, но не участвуют в сравнении.\r\n\r\nСбросить значения\r\nСброс "
            L"задаёт отображаемый размер клетки 8 px с сеткой или без неё (шаг 9 или 8 px), скорость 20 "
            L"поколений/с, плотность 25 % и три цвета по умолчанию. Другие настройки сохраняются; узор, "
            L"который больше не помещается, заменяется смесью. Новая сцена создаётся только при изменении "
            L"шага или плотности в режиме шума.\r\n\r\nЗАСТАВКА WINDOWS\r\nGameOfLife.scr использует все "
            L"мониторы и отдельные от EXE настройки. Предпросмотр запускает полноэкранную анимацию с "
            L"открытыми настройками. Маленький предпросмотр Windows уменьшает весь мир. OK сохраняет; "
            L"Отмена или Esc отклоняет изменения. Движение мыши или клавиша закрывает полноэкранную "
            L"заставку. Запись MP4 доступна в EXE.\r\n\r\nПОЛОЖЕНИЕ И СОСТОЯНИЕ ОКОН\r\nПри закрытии "
            L"отдельно сохраняются положения главного окна и окна О программе; для Справки также размер и "
            L"обычное или развёрнутое состояние до сворачивания. Это не зависит от подтверждения настроек "
            L"приложения. Выход из приложения закрывает также Справку и О программе.\r\n\r\nОТРИСОВКА И "
            L"ЛИЦЕНЗИИ УЗОРОВ\r\nРазвитие и сравнения видимых состояний используют шейдеры Direct3D 11 на "
            L"GPU; при неудачной аппаратной инициализации доступна программная отрисовка. Каждый монитор "
            L"использует проверенное регулирование кадров со своей частотой. MP4 требует Media Foundation "
            L"и кодировщика H.264. Узоры взяты из LifeWiki (GFDL 1.2 или новее) и коллекций Алана Хенсела "
            L"в общественном достоянии. Код имеет лицензию MIT; уведомления и лицензии каталога отдельные."
        },
        LocalizedText{ TXT_CELL_SIZE,
            L"Размер клетки: %u px"
        },
        LocalizedText{ TXT_GENERATION_RATE,
            L"Скорость: %u поколений/с"
        },
        LocalizedText{ TXT_INITIAL_DENSITY,
            L"Начальная плотность: %u %%"
        },
        LocalizedText{ TXT_RESTART, L"Перезапустить сцену" },
        LocalizedText{ TXT_ALIVE_COLOR,
            L"Цвет живых клеток…"
        },
        LocalizedText{ TXT_BACKGROUND_COLOR,
            L"Цвет фона…"
        },
        LocalizedText{ TXT_TOPOLOGY_NOTE,
            L"Выбранные мониторы образуют общий мир. Пустые полосы удаляются; внутренние отверстия остаются."
        },
        LocalizedText{ TXT_ANIMATION_RUNNING,
            L"Анимация работает…"
        },
        LocalizedText{ TXT_PAUSED_STATUS,
            L"Анимация приостановлена."
        },
        LocalizedText{ TXT_RENDERER_FAILED,
            L"Не удалось инициализировать визуализатор Direct3D."
        },
        LocalizedText{ TXT_ENABLE_PREVIEW, L"Предпросмотр" },
        LocalizedText{ TXT_DISABLE_PREVIEW, L"Остановить просмотр" },
        LocalizedText{ TXT_MONITOR,
            L"Монитор"
        },
        LocalizedText{ TXT_RESOLUTION,
            L"Разрешение"
        },
        LocalizedText{ TXT_POSITION,
            L"Расположение"
        },
        LocalizedText{ TXT_PRIMARY,
            L"основной"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_MODEL,
            L"Модель монитора"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_REFRESH_RATE,
            L"Частота обновления"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_BIT_DEPTH,
            L"Глубина цвета"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_FORMAT,
            L"Формат цвета"
        },
        LocalizedText{ TXT_MONITOR_COLUMN_COLOR_SPACE,
            L"Цветовое пространство"
        },
        LocalizedText{ TXT_MONITOR_CHANNEL_DEPTH_FORMAT,
            L"%u бит/канал"
        },
        LocalizedText{ TXT_MONITOR_PIXEL_DEPTH_FORMAT,
            L"%u бит/пиксель"
        },
        LocalizedText{ TXT_ANIMATION_MONITOR,
            L"Монитор анимации"
        },
        LocalizedText{ TXT_READY_STATUS,
            L"Готов"
        },
        LocalizedText{ TXT_SHOW_GRID,
            L"Показывать сетку"
        },
        LocalizedText{ TXT_GRID_COLOR,
            L"Цвет сетки…"
        },
        LocalizedText{ TXT_AUTO_RESET,
            L"Автоматически перезапускать неподвижную или повторяющуюся видимую сцену"
        },
        LocalizedText{ TXT_PATTERNS_ONLY,
            L"Только известные узоры"
        },
        LocalizedText{ TXT_START_RECORDING,
            L"Начать запись…"
        },
        LocalizedText{ TXT_STOP_RECORDING,
            L"Остановить запись"
        },
        LocalizedText{ TXT_RECORDING,
            L"Идёт запись MP4…"
        },
        LocalizedText{ TXT_RECORDING_SAVED,
            L"Запись сохранена."
        },
        LocalizedText{ TXT_RECORDING_FAILED,
            L"Не удалось начать запись MP4."
        },
        LocalizedText{ TXT_RECORDING_CLOSE_WARNING,
            L"Закрытие приложения остановит текущую запись."
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TITLE,
            L"Настройки записи"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_VIEWPORT,
            L"Viewport"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_TELEVISION,
            L"TV (BT.709, 4:2:0)"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_RESOLUTION,
            L"Разрешение:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_FRAME_RATE,
            L"Частота кадров:"
        },
        LocalizedText{ TXT_RECORDING_SETTINGS_NOTE,
            L"Изменения применяются к следующей записи MP4."
        },
        LocalizedText{ TXT_PATTERN_MIX,
            L"Смесь подходящих узоров"
        },
        LocalizedText{ TXT_PATTERN_FALLBACK,
            L"Выбранный узор больше не помещается. Выбрана подходящая смесь."
        },
        LocalizedText{ TXT_PATTERN_CATALOG_FAILED,
            L"Не удалось загрузить каталог известных узоров."
        },
    }),
};

constexpr std::array<LocalizedLanguage, LANG_COUNT> localizedLanguages =
    DefineLocalization(languageDefinitions);

/// Returns the compile-time checked translation for a valid language and named text key.
const wchar_t* GetLocalizedText(AppLanguage language, TextId id) {
    return localizedLanguages[language].texts[id];
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

/// Returns a TV resolution caption at the supplied preset index.
const wchar_t* RecordingResolutionText(unsigned index) {
    return RECORDING_RESOLUTION_TEXTS[index];
}

/// Returns an exact TV frame-rate caption at the supplied preset index.
const wchar_t* RecordingRateText(unsigned index) {
    return RECORDING_RATE_TEXTS[index];
}
