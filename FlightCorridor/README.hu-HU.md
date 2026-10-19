# FlightCorridor

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · **Magyar** · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

Hardveresen gyorsított repülés változó felületek között. Repülés négy változó felület között; Repülés változó tölcsérben. Monitoronként pontosan egy animáció választható. A Textúra jelölőnégyzet a textúrázott felület és a drótváz között vált. A kamera szabad forgása lassan változtatja a nézetet mindhárom dimenzióban. A Megállások és irányváltások véletlenszerű lassításokat, szüneteket és forgásirányváltásokat ad hozzá; az előrehaladás folytatódik. A sebesség 0–1600%. Minden monitor önálló véletlenszerű jelenetet kap, saját frissítési gyakoriságához igazodó megjelenítéssel.

## Vezérlés

Jelöljön ki egy vagy több sort a monitorok listájában. A Ctrl+A mindet kijelöli; a Ctrl és a Shift módosítja a kijelölést. Az animáció vezérlői és csúszkái csak a kijelölt monitorok beállításait változtatják. A sor kijelölése és az animációs kimenet jelölőnégyzetes engedélyezése külön művelet. A kijelölést az alkalmazás és a képernyőkímélő külön megjegyzi. Ha korábban minden monitor ki volt jelölve, az újonnan csatlakoztatott monitorok is bekerülnek a kijelölésbe.

## Alkalmazás

Indítsa el a FlightCorridor.exe fájlt. A beállítások folyamatosan mentődnek, és csak egy alkalmazáspéldány fut. A monitor jelölőnégyzete vagy a sorra történő dupla kattintás kapcsolja az animációs kimenetet. Az animáció szüneteltethető és folytatható. A PNG és az MP4 az első aktív animációs monitort rögzíti, nem az összes monitor egyesített képét. A rögzített monitor felvétel közben nem kapcsolható ki; az alkalmazás bezárásához ekkor megerősítés szükséges. A képernyőkímélő tiltása közös, és csak akkor aktív, ha egy ezt kérő monitoron látható, nem szünetelő animáció fut. Az alkalmazás telepítheti és eltávolíthatja a beágyazott képernyőkímélőt.

A felvételi beállításoknál Viewport vagy TV választható. A Viewport megőrzi a monitor képméretét és frissítési gyakoriságát, legfeljebb 60 képkocka/másodpercig. A TV felbontása 1920 × 1080, 1440 × 1080 vagy 1280 × 720, képaránya 16:9; sebessége 50, 25, 59.94 (60000/1001) vagy 29.97 (30000/1001) képkocka/másodperc. A TV videó progresszív BT.709, korlátozott tartománnyal és 4:2:0 színmintavételezéssel. A kép arányai megmaradnak, a kitöltősávok feketék. Az OK a következő felvételhez menti a választást; a Mégse vagy Esc elveti a nem jóváhagyott módosításokat. A felvételi beállítások, a Súgó és a Névjegy nem blokkolja a többi ablakot és kis méretűre állítható. A Tab és Shift+Tab mozgatja a fókuszt, az Enter aktiválja a fókuszban levő gombot, az Esc bezárja az aktív kiegészítő ablakot.

## Képernyőkímélő

A FlightCorridor.scr Windows-képernyőkímélőként használható, az alkalmazástól külön beállításokkal. A teljes képernyős előnézetben élőben módosíthatók a beállítások. Az OK ment, a Mégse vagy Esc elveti a módosításokat. A teljes képernyős képernyőkímélő billentyűvel vagy egérmozgással zárható be.

## Rendszerkövetelmények

A Windows 7–11 minden funkciót támogat. Windows Vista SP2 alatt telepíteni kell a KB971512 és KB2117917 frissítést; az MP4-felvétel Vistán nem működik. Direct3D 11 támogatás szükséges, az MP4-hez Media Foundation és H.264-kódoló is kell. A kezelőfelület és a dokumentáció 36 nyelven érhető el.

## Fordítás és csomagolás

Nyissa meg a DispSavers.slnx fájlt Visual Studióban, és fordítsa a Release | x86 konfigurációt MSVC v145 és Windows SDK használatával. A Signing oldalon adja meg a tanúsítványt és a kötelező RFC 3161 időbélyeg-kiszolgálót; a személyes adatok az ignorált .vcxproj.user fájlban maradnak. Az aláírt, időbélyegzett SCR az EXE-be kerül, majd az EXE is aláírást kap. A PackageRelease.ps1 közös `DispSavers-<version>-win32.zip` csomagot készít a Release binárisainak módosítása nélkül.

## Licenc

[MIT](license.txt) — Copyright © Petr Červinka — FortSoft 2026
