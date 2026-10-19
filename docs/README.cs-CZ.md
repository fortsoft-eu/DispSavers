# FlyingSolids

**Čeština** · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlyingSolids je nativní aplikace Win32/x86 a spořič obrazovky pro Windows, který prostřednictvím Direct3D vykresluje osvětlená plná prostorová geometrická tělesa. Tělesa se nezávisle pohybují, otáčejí a odrážejí, aniž by se vzájemně prolínala.

Označení řádků určuje, které monitory právě nastavujete; není totožné se zatržítky zapínajícími animační výstupy. Ctrl+A označí všechny monitory, Ctrl a Shift umožňují upravit označení. Všechny animační volby a jezdce platí pro označené monitory. Označení se pamatuje zvlášť pro EXE a SCR. Pokud byly označené všechny monitory, označí se i nově připojené.

## Funkce

- Dva režimy kamery: **Pozorování prostoru** a přímý **Průlet prostorem**. V seznamu označte jeden nebo více monitorů. Režim kamery, výběr těles, světla, rychlosti, velikost a počet kopií se nastavují jen pro označené monitory a každý monitor si pamatuje vlastní nastavení.
- Nezávislé ovládání hlavního a doplňkového světla, základního jasu a přisvětlení obrysů
- Samostatný animační prostor pro každý vybraný monitor
- Jedna až deset kopií každého zapnutého tělesa
- Rychlost objektů a kamery 0–1600 %, velikost objektů 50–200 %
- Lesklé osvětlené povrchy a vlastní barva každého typu tělesa
- Kolize mezi tělesy, hranicemi scény a dráhou kamery
- Vykreslování přizpůsobené obnovovací frekvenci jednotlivých monitorů
- Snímky PNG a záznam MP4 v samostatné aplikaci
- Oddělené nastavení aplikace a spořiče
- Uživatelské rozhraní v 36 jazycích

## Geometrická tělesa

Krychle; Pravidelný čtyřboký jehlan; Komolý čtyřboký jehlan; Čtyřboký jehlan se šikmým řezem; Čtyřboký jehlan s řezem kolmým k podstavě; Pravidelný trojboký hranol; Pravidelný pětiboký hranol; Pravidelný šestiboký hranol; Pravidelný osmistěn; Pětiboký dvojjehlan; Rotační kužel; Komolý rotační kužel; Rotační kužel se šikmým řezem; Rotační kužel s řezem kolmým k podstavě; Válec; Dutý válec; Dutý válec s toroidálními čely; Rotační paraboloid uzavřený rovinou; Koule; Polokoule; Kulová úseč; Velká kulová úseč; Kulová vrstva; Trojosý elipsoid; Protáhlý rotační elipsoid; Zploštělý rotační elipsoid; Ovoid; Kapsle (sferocylindr); Zaoblený disk (spheroplatelet); Anuloid (torus).

## Osvětlení

Zatržítka `Hlavní světlo`, `Doplňkové světlo`, `Základní jas` a `Přisvětlení obrysů` pod jezdci nezávisle ovládají osvětlení celé scény. Základní jas přisvětluje povrch těles, přisvětlení obrysů zvýrazňuje jejich okraje. Nastavení osvětlení se ukládá zvlášť pro aplikaci a spořič obrazovky.

## Samostatná aplikace

Spusťte `FlyingSolids.exe`. Její jediné ovládací okno zůstává použitelné i za běhu animace. V seznamu vyberte jeden nebo více monitorů; dvojklikem na řádek příslušný monitor zapnete nebo vypnete. Lze také odepnout všechny monitory. Změny se průběžně ukládají. Aplikace běží pouze v jedné instanci. Další spuštění obnoví minimalizované ovládací okno a přenese do popředí. Mezi ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a příslušného písmene. Esc zavře aktivní nápovědu či okno O aplikaci; v ovládacím okně ukončí aplikaci. Snímek a záznam zachycují první aktivní animační monitor, nikoli společnou plochu všech monitorů. PNG používá složku Obrázky, MP4 složku Videa; při jejich neexistenci se použijí Dokumenty. Tlačítko Nastavení záznamu vybírá Viewport nebo TV. Viewport zachovává rozměry animačního monitoru a jeho obnovovací frekvenci, nejvýše 60 snímků za sekundu. TV nabízí rozlišení 1920 × 1080, 1440 × 1080 nebo 1280 × 720 v poměru 16:9 a frekvenci 50, 25, 59.94 (60000/1001) nebo 29.97 (30000/1001) snímků za sekundu. Obraz zachovává poměr stran; TV používá progresivní video BT.709 s omezeným rozsahem a vzorkováním 4:2:0. Rozlišení a snímkovou frekvenci lze vybrat pouze v režimu TV. Okno Nastavení záznamu lze minimalizovat a neblokuje ostatní okna aplikace. OK uloží volby pro příští záznam MP4; Storno nebo Esc nepotvrzené změny zahodí. Nahrávaný monitor nelze během záznamu odepnout; změny ostatních monitorů záznam nezastaví. Ukončení aplikace při probíhajícím záznamu vyžaduje potvrzení, protože současně ukončí záznam. Volba Blokovat spořič při animaci brání spuštění spořiče Windows pouze tehdy, když je animace skutečně viditelná a není pozastavená. Aplikace umí nainstalovat nebo odinstalovat spořič zabalený přímo v EXE, takže pro instalaci není samostatný soubor `.scr` nutný.

## Spořič obrazovky

`FlyingSolids.scr` má vlastní dialog nastavení a neobsahuje záznam. V celoobrazovkovém režimu spouští na každém monitoru nezávislou scénu. Tlačítko Zapnout náhled v nastavení spustí samostatný celoobrazovkový náhled na všech monitorech. Používá aktuální nastavení a umožňuje úpravy za běhu; lze jej opět vypnout. Celoobrazovkový spořič ukončíte libovolnou klávesou, pohybem myši nebo kliknutím. Esc v nastavení odpovídá tlačítku Storno; v nápovědě nebo okně O aplikaci zavře pouze toto okno.

## Uložení nastavení

Nastavení aplikace a spořiče se navzájem nepřepisují:

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Systémové požadavky

Windows 7 až Windows 11 podporují všechny funkce včetně snímků PNG a záznamu MP4. Pro spuštění aplikace ve Windows Vista SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917. Záznam MP4 na Vistě v současné verzi nefunguje. Vykreslování vyžaduje Direct3D 11, nikoli jen starší DirectX runtime. Záznam MP4 vyžaduje dostupné součásti Media Foundation a kodér H.264.

## Sestavení a balíček

Otevřete `DispSavers.slnx` ve Visual Studiu s nástroji MSVC v145 a Windows SDK. Zvolte `Release | x86` a znovu sestavte celé řešení; vzniknou `Release\FlyingSolids.exe` a `Release\FlyingSolids.scr`. Konfigurace x64 není k dispozici. Ve vlastnostech projektu `FlyingSolids` na stránce `Signing` zadejte jméno nebo otisk platného certifikátu pro podepisování kódu se soukromým klíčem v úložišti aktuálního uživatele `Personal (My)`. Nastavení je společné pro EXE a SCR a ukládá se do souboru `FlyingSolids.vcxproj.user`, který Git ignoruje. SignTool se vyhledá automaticky v PATH nebo ve Windows SDK. Používáte-li SimplySign, před sestavením se přihlaste v SimplySign Desktop. Sestavení nejprve podepíše SCR, přidá povinné časové razítko RFC 3161 se SHA-256 z nastaveného serveru časových razítek a teprve potom jej vloží do EXE, které také podepíše a opatří razítkem. Do pole `Timestamp server` zadejte adresu serveru časových razítek RFC 3161. Chyba podpisu, razítka nebo jejich ověření sestavení zastaví; již platné podepsané soubory s razítkem se znovu nepodepisují.

Takto sestavené soubory zabalte spuštěním `PackageRelease.ps1` bez parametrů podpisu. Skript pracuje s dočasnými kopiemi, nemění soubory v `Release` a existující platné podpisy pouze ověří. Vytvoří jediný archiv `DispSavers-<version>-win32.zip`, který obsahuje `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` a `SpaceFlight\license.txt`. Předchozí ZIP se odstraní na začátku spuštění; chyba ověření zabrání vytvoření nového archivu.

## Licence

FlyingSolids je dostupný pod [licencí MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026

## FlightCorridor

FlightCorridor nabízí Průlet čtyřmi proměnlivými plochami a Průlet proměnlivým trychtýřem. Každému monitoru přiřadíte právě jeden průlet: označte jeho řádek v seznamu a zvolte příslušný přepínač.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](../FlightCorridor/README.cs-CZ.md)

## SpaceFlight

SpaceFlight nabízí „Nekonečná vlnící se plocha“ a „Dálkový let — proměnlivá plocha“. Každému monitoru přiřadíte právě jeden průlet: označte jeho řádek v seznamu a zvolte příslušný přepínač.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](../SpaceFlight/README.cs-CZ.md)
