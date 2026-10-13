# FlyingSolids

**Čeština** · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids je nativní aplikace Win32/x86 a spořič obrazovky pro Windows, který prostřednictvím Direct3D vykresluje osvětlená plná prostorová geometrická tělesa. Tělesa se nezávisle pohybují, otáčejí a odrážejí, aniž by se vzájemně prolínala.

## Funkce

- Dva režimy kamery: **Pozorování prostoru** a přímý **Průlet prostorem**
- Nezávislé ovládání hlavního a doplňkového světla, základního jasu a přisvětlení obrysů
- Samostatný animační prostor pro každý vybraný monitor
- Jedna až deset kopií každého zapnutého tělesa
- Rychlost objektů a kamery 0–1600 %, velikost objektů 50–200 %
- Lesklé osvětlené povrchy a vlastní barva každého typu tělesa
- Kolize mezi tělesy, hranicemi scény a dráhou kamery
- Vykreslování přizpůsobené obnovovací frekvenci jednotlivých monitorů
- Snímky PNG a záznam MP4 v samostatné aplikaci
- Oddělené nastavení aplikace a spořiče
- Uživatelské rozhraní v 17 jazycích

## Geometrická tělesa

Lze zvolit 30 těles: krychli; pravidelný čtyřboký jehlan; komolý čtyřboký jehlan; čtyřboké jehlany se šikmým řezem a s řezem kolmým k podstavě; pravidelné trojboké, pětiboké a šestiboké hranoly; pravidelný osmistěn; pětiboký dvojjehlan; rotační kužel; komolý rotační kužel; rotační kužely se šikmým řezem a s řezem kolmým k podstavě; válec; dutý válec; dutý válec s toroidálními čely; rotační paraboloid uzavřený rovinou; kouli; polokouli; kulovou úseč; velkou kulovou úseč; kulovou vrstvu; trojosý elipsoid; protáhlý rotační elipsoid; zploštělý rotační elipsoid; ovoid; kapsli (sferocylindr); zaoblený disk (spheroplatelet) a anuloid (torus).

## Osvětlení

Zatržítka `Hlavní světlo`, `Doplňkové světlo`, `Základní jas` a `Přisvětlení obrysů` pod jezdci nezávisle ovládají osvětlení celé scény. Základní jas přisvětluje povrch těles, přisvětlení obrysů zvýrazňuje jejich okraje. Výchozí stav: hlavní světlo, základní jas a přisvětlení obrysů zapnuté, doplňkové světlo vypnuté. Nastavení osvětlení se ukládá zvlášť pro aplikaci a spořič obrazovky.

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

Otevřete `DispSavers.slnx` ve Visual Studiu s nástroji MSVC v145 a Windows SDK. Zvolte `Release | x86` a znovu sestavte celé řešení; vzniknou `Release\FlyingSolids.exe` a `Release\FlyingSolids.scr`. Konfigurace x64 není k dispozici. Podepisování je ve výchozím stavu zapnuté pro Release i Debug. Ve vlastnostech projektu `FlyingSolids` na stránce `Signing` zadejte jméno nebo otisk platného certifikátu pro podepisování kódu se soukromým klíčem v úložišti aktuálního uživatele `Personal (My)`. Nastavení je společné pro EXE a SCR a ukládá se do souboru `FlyingSolids.vcxproj.user`, který Git ignoruje. SignTool se vyhledá automaticky v PATH nebo ve Windows SDK. Používáte-li SimplySign, před sestavením se přihlaste v SimplySign Desktop. Sestavení nejprve podepíše SCR, přidá povinné časové razítko RFC 3161 se SHA-256 z nastaveného serveru časových razítek a teprve potom jej vloží do EXE, které také podepíše a opatří razítkem. Do pole `Timestamp server` zadejte adresu serveru časových razítek RFC 3161. Chyba podpisu, razítka nebo jejich ověření sestavení zastaví; již platné podepsané soubory s razítkem se znovu nepodepisují.

Takto sestavené soubory zabalte spuštěním `PackageRelease.ps1` bez parametrů podpisu. Skript pracuje s dočasnými kopiemi, nemění soubory v `Release` a existující platné podpisy pouze ověří. Vytvoří jediný archiv `DispSavers-<version>-win32.zip`, který obsahuje `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr` a `FlyingSolids\license.txt`. Předchozí ZIP se odstraní na začátku spuštění; chyba ověření zabrání vytvoření nového archivu.

## Licence

FlyingSolids je dostupný pod [licencí MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026
