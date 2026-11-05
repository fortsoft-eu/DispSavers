# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · **Magyar** · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Térbeli testek hardveresen gyorsított animációja.

A FlyingSolids mozgó, forgó és ütköző térbeli testeket jelenít meg. Válassza a tér megfigyelését vagy a térben repülést, és kapcsolja be a kívánt testeket. Monitoronként állítható az objektumok és a kamera sebessége 0–1600%, az objektumok mérete 50–200%, valamint testenként 1–10 példány. A főfény, derítőfény, környezeti fény és peremfény egymástól függetlenül kapcsolható.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Hardveresen gyorsított repülés változó felületek között.

Hardveresen gyorsított repülés változó felületek között. Repülés négy változó felület között; Repülés változó tölcsérben. Monitoronként pontosan egy animáció választható. A Textúra jelölőnégyzet a textúrázott felület és a drótváz között vált. A kamera szabad forgása lassan változtatja a nézetet mindhárom dimenzióban. A Szünetek és irányváltás véletlenszerű lassításokat, szüneteket és forgásirányváltásokat ad hozzá; az előrehaladás folytatódik. A sebesség 0–1600%. Minden monitor önálló véletlenszerű jelenetet kap, saját frissítési gyakoriságához igazodó megjelenítéssel. A főfény, a derítőfény, a környezeti fény és a peremfény külön kapcsolható a kijelölt monitorokon. A világítás csak a textúrázott felületekre vonatkozik.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Hardveresen gyorsított repülés hullámzó felület felett.

SpaceFlight: Végtelen hullámzó felület; Távolsági repülés — változó felület; Repülés gravitációsan görbült térben. Monitoronként pontosan egy animáció választható. A Textúra jelölőnégyzet a textúrázott felület és a drótváz között vált. A kamera szabad forgása lassan változtatja a nézetet mindhárom dimenzióban. A Szünetek és irányváltás véletlenszerű lassításokat, szüneteket és forgásirányváltásokat ad hozzá; az előrehaladás folytatódik. A sebesség 0–1600%. Minden monitor önálló véletlenszerű jelenetet kap, saját frissítési gyakoriságához igazodó megjelenítéssel. A főfény, a derítőfény, a környezeti fény és a peremfény külön kapcsolható a kijelölt monitorokon. A világítás csak a textúrázott felületekre vonatkozik. Mindkét felületanimációnál sík, hullámzás vagy tölcsér választható. A tölcsér lefelé haladó spirál mentén húzza befelé a kamerát. A gravitációsan görbült térben végzett repülés háromdimenziós drótvázrácsot jelenít meg. A textúra, a felület alakja és a világítás beállításai csak a két felületanimációra vonatkoznak.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Conway életjátéka a kijelzők közös világában.

### Szabályok

Conway életjátéka a B3/S23 szabályt követi. A halott cella pontosan három élő szomszédnál születik meg; az élő kettőnél vagy háromnál marad életben. A nyolc szomszéd az átlósakat is tartalmazza. Minden cella egyszerre változik. A szemközti szélek összekapcsolódnak: bal a jobbal, felső az alsóval.

### Kijelzők és közös világ

Az EXE jelölőnégyzetei engedélyezik a kijelzőket; a beállítások a közös világra vonatkoznak. Egyetlen aktív kijelző az egész világot tartalmazza. Részleges kijelölésnél a teljesen üres sorok és oszlopok eltűnnek: a középső kikapcsolásakor a bal és jobb kijelző összeér. Az el nem távolítható belső lyukak a szimuláció részei maradnak. Az összes kijelző kiválasztása és az SCR megőrzi az asztal körülíró téglalapját a láthatatlan hézagokkal együtt. Minden kijelző ugyanazon játék saját részét mutatja.

### Kezdőállapot és minták

Az alapállapot véletlen zaj 25 % élő cellával. A 0–100 % kezdeti sűrűség a következő újraindításkor érvényesül. A Csak ismert minták 4 106 beépített mintát használ zaj nélkül, és letiltja a sűrűséget. Válasszon keveréket vagy nevet; a méret cellákban értendő. Gépeléssel kereshet. Csak a teljesen elférő minták szerepelnek. A kis ellenőrzött minták külön másolatokban ismétlődnek, a nagyok vagy összetettek egyszer középen jelennek meg. Kisebb világban a már nem férő választást keverék válthatja fel. Mód- vagy mintaváltás új jelenetet indít. Az újraindítás megőrzi a választást; a katalógus internet nélkül működik.

### Cellaméret, rács és színek

Rács nélkül a cellaméret 1–64 px. A rács 1 px szegélyt ad a meglévő térközön belül: a kijelzett érték és a csúszka eggyel csökken, 1–63 használható. Kikapcsolva az érték visszaáll. A csúszka teljes tartománya megmarad, a tiltott végpontról visszaugrik; a jelölőnégyzet aktív marad. A kapcsolás megőrzi a jelenetet, kivéve 1 px-nél bekapcsolva: a térköz 2 px lesz és új jelenet indul. Cellaméret vagy kijelzők változtatása is újrakezd. Nagyon nagy világ magasabb minimumot igényelhet. A cellák, háttér és rács színe külön, újraindítás nélkül állítható. Az élő cellák véletlen színe a jelenet minden kézi vagy automatikus újraindításakor új színt választ. A mentett szín megmarad, és a lehetőség kikapcsolásakor visszaáll. Ugyanez a működés külön engedélyezhető a háttérhez és a rácshoz; mindkét új lehetőség alapértelmezetten ki van kapcsolva.

### Sebesség, szünet és automatikus újraindítás

A sebesség 0–240 generáció/s, a képfrissítéstől függetlenül; 0 megállítja a fejlődést. Szünet és Folytatás megőrzi a világot. Az Újraindítás a kiválasztott módban kezd újra. Az opcionális automatikus újraindítás állandó és pontosan ismétlődő látható fázisokat, így oszcillátorokat is felismer. Generációkat hasonlít, nem másodperceket; a láthatatlan részek kimaradnak. Az aszinkron eredmények kissé késleltethetik az újraindítást. Alapértékek: 8 px térköz, 20 generáció/s, az élő sejtek véletlen színe és automatikus újraindítás bekapcsolva. A rács alapértelmezés szerint ki van kapcsolva. Az elért sebesség a teljesítménytől és a cellák számától függ. Az automatikus újraindítás az engedélyezett kijelzők területét hasonlítja össze; a köztük levő hézagok tovább fejlődnek, de kimaradnak az összehasonlításból.

### Értékek visszaállítása

A visszaállítás a kijelzett cellaméretet ráccsal és anélkül is 8 px-re állítja (térköz 9 vagy 8 px), a sebességet 20 generáció/s-ra, a sűrűséget 25 %-ra, és visszaállítja a három alapértelmezett színt. A többi választás megmarad; a már nem elférő mintát keverék váltja fel. Új jelenet csak a térköz változásakor vagy zajmódban a sűrűség változásakor indul.

### Önálló alkalmazás és MP4-felvétel

Az EXE folyamatosan menti a beállításokat, és az első aktív kijelzőt rögzíti MP4-be. A javasolt mappa Videók, ennek hiányában Dokumentumok. Viewport a kijelző méretét és legfeljebb 60 képkocka/s frissítését használja. TV: 1920 × 1080, 1440 × 1080 vagy 1280 × 720, 16:9, 50, 25, 59,94 (60000/1001) vagy 29,97 (30000/1001) képkocka/s. A képarány megmarad; TV progresszív, korlátozott tartományú BT.709 és 4:2:0. A külön beállítóablak kis méretűre állítható. OK a következő felvételhez ment; Mégse vagy Esc elveti a függő módosításokat. A rögzített kijelző nem kapcsolható ki, a többi változtatható. Felvétel közbeni kilépés megerősítést kér. Aktív animációnál Szóköz váltja a szünetet, F9: Felvétel indítása; F10: Felvétel leállítása. A mutató 1 másodperc tétlenség után eltűnik, mozgásra visszatér. Tab/Shift+Tab léptet, Alt az aláhúzott parancsot indítja. Esc bezárja a Súgó/Névjegy ablakot, a főablakban kilép. A Windows-képernyőkímélő… megnyitja a rendszer képernyőkímélő-beállításait.

### Pillanatkép és a képernyőkímélő kezelése az EXE-ben

A pillanatkép a rögzített kijelzőt, egyébként az első aktív kijelzőt menti PNG-be annak felbontásával, a jelenet újraindítása nélkül. A javasolt mappa Képek, ennek hiányában Dokumentumok. A képernyőkímélő tiltása animáció közben megakadályozza az indulását, amíg az animáció látható és nincs szüneteltetve. A nulla sebesség nem szünet. Az EXE-ből történő telepítés kibontja a mellékelt SCR-t és Windows képernyőkímélőként választja ki. A telepítés és eltávolítás rendszergazdai jóváhagyást igényelhet; az állapotsor a befejezésig jelzi a műveletet. Ha az eltávolítás blokkolva van, zárja be a futó képernyőkímélőt, a beállításait és a Windows előnézetét.

### Windows-képernyőkímélő

A GameOfLife.scr minden kijelzőt használ, az EXE-től külön tárolt beállításokkal. Az előnézet teljes képernyőn fut nyitott beállítások mellett. A kis Windows-előnézet az egész világot lekicsinyíti. OK ment, Mégse vagy Esc elveti a változtatásokat. Egérmozgás vagy billentyű kilép a teljes képernyős képernyőkímélőből. MP4-felvétel az EXE-ben érhető el.

### Az ablakok helye és állapota

Bezáráskor külön mentődik a főablak és a Névjegy helye; a Súgónál a méret és a kis méretre állítás előtti normál vagy teljes méretű állapot is. Ez független az alkalmazásbeállítások jóváhagyásától. Az alkalmazás bezárása a Súgót és a Névjegyet is bezárja.

### Megjelenítés és mintalicencek

A fejlődés és a látható állapotok összehasonlítása Direct3D 11 shaderekkel a GPU-n fut; hardveres inicializálási hiba esetén szoftveres megjelenítés használható. Minden kijelző a bevált képkocka-ütemezőt használja saját frissítésével. MP4-hez Media Foundation és H.264 kódoló kell. A minták a LifeWikiről (GFDL 1.2 vagy újabb) és Alan Hensel közkincs gyűjteményeiből származnak. A programkód MIT-licencű; a katalógus külön jogi közleményekkel és licencekkel rendelkezik.

[Mintaforrások, licencek és importálási részletek](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### MONITOROK

Jelöljön ki egy vagy több sort a monitorok listájában. A Ctrl+A mindet kijelöli; a Ctrl és a Shift módosítja a kijelölést. Az animáció vezérlői és csúszkái csak a kijelölt monitorok beállításait változtatják. A sor kijelölése és az animációs kimenet jelölőnégyzetes engedélyezése külön művelet. A kijelölést az alkalmazás és a képernyőkímélő külön megjegyzi. Ha korábban minden monitor ki volt jelölve, az újonnan csatlakoztatott monitorok is bekerülnek a kijelölésbe. A kijelölt monitorok eltérő értékeit a jelölőnégyzetek határozatlan állapota, valamint a választógombok, a csúszkafogantyúk és az „Mind bekapcsolása” és „Mind kikapcsolása” gombok pontozása jelzi. A csúszkák felirata közös érték helyett gondolatjelet mutat. Egy beállítás módosítása vagy a csúszkára kattintás az adott értéket minden kijelölt monitorra alkalmazza.

### KEZELÉS

Indítsa el a FlightCorridor.exe fájlt. A beállítások folyamatosan mentődnek, és csak egy alkalmazáspéldány fut. A monitor jelölőnégyzete vagy a sorra történő dupla kattintás kapcsolja az animációs kimenetet. Az animáció szüneteltethető és folytatható. A PNG és az MP4 az első aktív animációs monitort rögzíti, nem az összes monitor egyesített képét. A rögzített monitor animációs kimenete felvétel közben nem kapcsolható ki; az alkalmazás bezárásához ekkor megerősítés szükséges. A szüneteltetés és a képernyőkímélő tiltása a teljes alkalmazásra vonatkozik, a monitorok kijelölésétől függetlenül. Bekapcsolt tiltás esetén a Windows képernyőkímélője csak addig nem indul el, amíg legalább egy monitoron látható, nem szünetelő animáció fut. Az alkalmazás telepítheti és eltávolíthatja a beágyazott képernyőkímélőt.

### KÉPERNYŐKÉPEK ÉS FELVÉTEL

A felvételi beállításoknál Viewport vagy TV választható. A Viewport megőrzi a monitor képméretét és frissítési gyakoriságát, legfeljebb 60 képkocka/másodpercig. A TV felbontása 1920 × 1080, 1440 × 1080 vagy 1280 × 720, képaránya 16:9; sebessége 50, 25, 59.94 (60000/1001) vagy 29.97 (30000/1001) képkocka/másodperc. A TV videó progresszív BT.709, korlátozott tartománnyal és 4:2:0 színmintavételezéssel. A kép arányai megmaradnak, a kitöltősávok feketék. Az OK a következő felvételhez menti a választást; a Mégse vagy Esc elveti a nem jóváhagyott módosításokat. A felvételi beállítások, a Súgó és a Névjegy nem blokkolja a többi ablakot és kis méretűre állítható. A Tab és Shift+Tab mozgatja a fókuszt, az Enter aktiválja a fókuszban levő gombot, az Esc bezárja az aktív kiegészítő ablakot.

### ELŐNÉZET ÉS KEZELÉS

A FlightCorridor.scr Windows-képernyőkímélőként használható, az alkalmazástól külön beállításokkal. A teljes képernyős előnézetben élőben módosíthatók a beállítások. Az OK ment, a Mégse vagy Esc elveti a módosításokat. A teljes képernyős képernyőkímélő billentyűvel vagy egérmozgással zárható be.

### Rendszerkövetelmények

A Windows 7–11 minden funkciót támogat. Windows Vista SP2 alatt telepíteni kell a KB971512 és KB2117917 frissítést; az MP4-felvétel Vistán nem működik. Direct3D 11 támogatás szükséges, az MP4-hez Media Foundation és H.264-kódoló is kell. A kezelőfelület és a dokumentáció 36 nyelven érhető el. Az önálló alkalmazás Linuxon is futhat a Wine segítségével; a képernyőkímélőként való integráció csak Windows alatt érhető el.

## Fordítás és csomagolás

Nyissa meg a DispSavers.slnx fájlt Visual Studióban, és fordítsa a Release | x86 konfigurációt MSVC v145 és Windows SDK használatával. A Signing oldalon adja meg a tanúsítványt és a kötelező RFC 3161 időbélyeg-kiszolgálót; a személyes adatok az ignorált .vcxproj.user fájlban maradnak. Az aláírt, időbélyegzett SCR az EXE-be kerül, majd az EXE is aláírást kap. A PackageRelease.ps1 közös `DispSavers-<version>-win32.zip` csomagot készít a Release binárisainak módosítása nélkül.

```text
Release\FlyingSolids.exe
Release\FlyingSolids.scr
Release\FlightCorridor.exe
Release\FlightCorridor.scr
Release\GameOfLife.exe
Release\GameOfLife.scr
Release\SpaceFlight.exe
Release\SpaceFlight.scr
```

`PackageRelease.ps1` → `DispSavers-<version>-win32.zip`:

```text
GameOfLife\GameOfLife.exe
GameOfLife\GameOfLife.scr
GameOfLife\license.txt
```

## Licenc

[MIT](../license.txt) — Copyright © Petr Červinka — FortSoft 2026
