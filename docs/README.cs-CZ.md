# DispSavers

**Čeština** · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Hardwarově akcelerovaná animace plných prostorových objektů.

V seznamu označte jeden nebo více monitorů. Režim kamery, výběr těles, světla, rychlosti, velikost a počet kopií se nastavují jen pro označené monitory a každý monitor si pamatuje vlastní nastavení. FlyingSolids zobrazuje osvětlená plná prostorová tělesa. Jezdci nastavují rychlost objektů a kamery v rozsahu 0–1600 %, jednu až deset kopií každého tělesa a velikost 50–200 %. Vyberte Pozorování prostoru nebo přímý Průlet prostorem a zaškrtněte požadované druhy těles. Zatržítka Hlavní světlo, Doplňkové světlo, Základní jas a Přisvětlení obrysů pod jezdci nezávisle ovládají osvětlení scén na označených monitorech. Základní jas přisvětluje povrch těles, přisvětlení obrysů zvýrazňuje jejich okraje. Nastavení osvětlení se ukládá zvlášť pro aplikaci a spořič obrazovky.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Hardwarově akcelerovaný průlet proměnlivým koridorem a trychtýřem.

FlightCorridor: Průlet mezi čtyřmi proměnlivými plochami; Průlet proměnlivým trychtýřem. Každému monitoru přiřaďte právě jednu animaci. Textura přepíná mezi texturovanými plochami a drátěným modelem. Volná rotace kamery pomalu mění směr pohledu ve všech třech rozměrech. Volba „Pauzy a obraty“ přidává náhodné zpomalování, pauzy a změny směru otáčení; dopředný pohyb pokračuje. Rychlost animace je 0–1600 %. Každý monitor má nezávislou náhodnou scénu a vykreslování podle své obnovovací frekvence. Hlavní světlo, doplňkové světlo, základní jas a přisvětlení obrysů lze pro označené monitory zapínat nezávisle. Osvětlení se používá jen u texturovaných ploch.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Hardwarově akcelerovaný let nad vlnícími se a proměnlivými plochami.

SpaceFlight: Nekonečná vlnící se plocha; Dálkový let — proměnlivá plocha; Průlet gravitačně deformovaným prostorem. Každému monitoru přiřaďte právě jednu animaci. Textura přepíná mezi texturovanými plochami a drátěným modelem. Volná rotace kamery pomalu mění směr pohledu ve všech třech rozměrech. Volba „Pauzy a obraty“ přidává náhodné zpomalování, pauzy a změny směru otáčení; dopředný pohyb pokračuje. Rychlost animace je 0–1600 %. Každý monitor má nezávislou náhodnou scénu a vykreslování podle své obnovovací frekvence. Hlavní světlo, doplňkové světlo, základní jas a přisvětlení obrysů lze pro označené monitory zapínat nezávisle. Osvětlení se používá jen u texturovaných ploch. U obou animací ploch lze zvolit rovinu, zvlnění nebo trychtýř. Trychtýř vtahuje kameru dovnitř po sestupné spirále. Gravitačně deformovaný prostor je zobrazen trojrozměrnou drátěnou mříží. Textura, tvar plochy a osvětlení platí jen pro obě animace ploch.

`SpaceFlight.exe` · `SpaceFlight.scr`

## MONITORY

Označení řádků určuje, které monitory právě nastavujete; není totožné se zatržítky zapínajícími animační výstupy. Ctrl+A označí všechny monitory, Ctrl a Shift umožňují upravit označení. Všechny animační volby a jezdce platí pro označené monitory. Označení se pamatuje zvlášť pro EXE a SCR. Pokud byly označené všechny monitory, označí se i nově připojené. Různé hodnoty na označených monitorech ukazuje neurčitý stav zatržítek a tečkování přepínačů, úchytů jezdců a tlačítek „Vše zapnout“ a „Vše vypnout“. Popisek jezdce místo společné hodnoty zobrazuje pomlčku. Změna volby nebo kliknutí na jezdec sjednotí příslušnou hodnotu na označených monitorech.

## OVLÁDÁNÍ

Animační výstupy zapnete nebo vypnete zatržítky u monitorů nebo dvojklikem na jejich řádky. Každý monitor používá nezávislou scénu. Snímek ukládá PNG, tlačítko záznamu spouští a ukončuje MP4. Pozastavení zastaví animaci. Aplikace také instaluje nebo odinstaluje zabalený spořič. Nastavení se ukládá průběžně. Aplikace běží pouze v jedné instanci. Další spuštění obnoví minimalizované ovládací okno a přenese je do popředí. Mezi ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a příslušného písmene. Esc zavře aktivní nápovědu či okno O aplikaci; v ovládacím okně ukončí aplikaci. Pozastavení a blokování spořiče platí pro celou aplikaci bez ohledu na označené monitory. Je-li blokování zapnuté, brání spuštění spořiče Windows pouze tehdy, když je alespoň na jednom monitoru viditelná nepozastavená animace.

## SNÍMKY A ZÁZNAM

Snímek a záznam zachycují první aktivní animační monitor, nikoli společnou plochu všech monitorů. PNG používá složku Obrázky, MP4 složku Videa; při jejich neexistenci se použijí Dokumenty. Tlačítko Nastavení záznamu vybírá Viewport nebo TV. Viewport zachovává rozměry animačního monitoru a jeho obnovovací frekvenci, nejvýše 60 snímků za sekundu. TV nabízí rozlišení 1920 × 1080, 1440 × 1080 nebo 1280 × 720 v poměru 16:9 a frekvenci 50, 25, 59.94 (60000/1001) nebo 29.97 (30000/1001) snímků za sekundu. Obraz zachovává poměr stran; TV používá progresivní video BT.709 s omezeným rozsahem a vzorkováním 4:2:0. Rozlišení a snímkovou frekvenci lze vybrat pouze v režimu TV. Okno Nastavení záznamu lze minimalizovat a neblokuje ostatní okna aplikace. OK uloží volby pro příští záznam MP4; Storno nebo Esc nepotvrzené změny zahodí. Animační výstup nahrávaného monitoru nelze během záznamu vypnout; změny ostatních monitorů záznam nezastaví. Ukončení aplikace při probíhajícím záznamu vyžaduje potvrzení, protože současně ukončí záznam.

## NÁHLED A OVLÁDÁNÍ

Zapnout náhled spustí celoobrazovkový náhled na všech monitorech; změny lze zkoušet za otevřeného nastavení. OK nastavení uloží, Storno je zahodí. Celoobrazovkový spořič ukončíte klávesou Esc nebo pohybem myši. Mezi ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a příslušného písmene. Esc v nastavení odpovídá tlačítku Storno; v nápovědě nebo okně O aplikaci zavře pouze toto okno.

## Systémové požadavky

Windows 7 až Windows 11 podporují všechny funkce včetně snímků PNG a záznamu MP4. Pro spuštění aplikace ve Windows Vista SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917. Záznam MP4 na Vistě v současné verzi nefunguje. Vykreslování vyžaduje Direct3D 11, nikoli jen starší DirectX runtime. Záznam MP4 vyžaduje dostupné součásti Media Foundation a kodér H.264. Samostatná aplikace může běžet také na Linuxu prostřednictvím Wine; integrace spořiče obrazovky je dostupná pouze ve Windows.

## Sestavení a balíček

Otevřete `DispSavers.slnx` ve Visual Studiu s nástroji MSVC v145 a Windows SDK. Zvolte `Release | x86` a znovu sestavte celé řešení; vzniknou `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\SpaceFlight.exe` a `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr`. Konfigurace x64 není k dispozici.

Takto sestavené soubory zabalte spuštěním `PackageRelease.ps1` bez parametrů podpisu. Skript pracuje s dočasnými kopiemi, nemění soubory v `Release` a existující platné podpisy pouze ověří. Vytvoří jediný archiv `DispSavers-<version>-win32.zip`, který obsahuje `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` a `SpaceFlight\license.txt`. Předchozí ZIP se odstraní na začátku spuštění; chyba ověření zabrání vytvoření nového archivu.

## Licence

DispSavers je dostupný pod [licencí MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026
