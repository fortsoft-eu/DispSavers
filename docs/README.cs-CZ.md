# FlyingSolids

**Čeština** · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids je nativní aplikace Win32/x86 a spořič obrazovky pro Windows, který prostřednictvím Direct3D vykresluje osvětlená plná prostorová geometrická tělesa. Tělesa se nezávisle pohybují, otáčejí a odrážejí, aniž by se vzájemně prolínala. Počáteční stavy a nové polohy při průletu používají kryptografický generátor náhodných čísel Windows; data se načítají po blocích, aby byla režie CPU malá.

## Funkce

- Dva režimy kamery: **Pozorování prostoru** a přímý **Průlet prostorem**
- Nezávislé zapínání a vypínání hlavního a doplňkového světla
- Samostatný animační prostor pro každý vybraný monitor
- Jedna až deset kopií každého zapnutého tělesa
- Rychlost objektů a kamery 0–1600 %, velikost objektů 50–200 %
- Lesklé osvětlené povrchy a vlastní zachovaná barva každého typu tělesa
- Kolize mezi tělesy, hranicemi scény a dráhou kamery
- Vykreslování přizpůsobené obnovovací frekvenci jednotlivých monitorů
- Snímky PNG a záznam MP4 v samostatné aplikaci
- Oddělené nastavení aplikace a spořiče
- Uživatelské rozhraní v 17 jazycích

## Geometrická tělesa

Lze zvolit 30 těles: krychli; pravidelný čtyřboký jehlan; komolý čtyřboký jehlan; čtyřboké jehlany se šikmým řezem a s řezem kolmým k podstavě; pravidelné trojboké, pětiboké a šestiboké hranoly; pravidelný osmistěn; pětiboký dvojjehlan; rotační kužel; komolý rotační kužel; rotační kužely se šikmým řezem a s řezem kolmým k podstavě; rotační válec; dutý rotační válec; dutý válec s toroidálními čely; rotační paraboloid uzavřený rovinou; kouli; polokouli; kulovou úseč; velkou kulovou úseč; kulovou vrstvu; trojosý elipsoid; protáhlý rotační elipsoid; zploštělý rotační elipsoid; ovoid; kapsli (sferocylindr); zaoblený disk (spheroplatelet) a anuloid (torus).

- Protáhlý rotační elipsoid má jednu delší a dvě shodné kratší poloosy.
- Zaoblený disk (spheroplatelet) má dvě rovinné kruhové plochy a plynule zaoblený obvod; jeho průměr je mírně větší než u kulové vrstvy a tloušťka poloviční.
- Dutý válec s toroidálními čely má vnější a vnitřní válcovou plochu spojené půltorovými čely, která v osovém řezu tvoří přesné půlkruhy.

## Osvětlení

Zatržítka `Hlavní světlo` a `Doplňkové světlo` pod pravými jezdci nezávisle zapínají a vypínají obě světla pro celou scénu. Výchozí stav: `Hlavní světlo` zapnuté, `Doplňkové světlo` vypnuté. Nastavení světel se ukládá zvlášť pro aplikaci a spořič obrazovky.

## Samostatná aplikace

Spusťte `FlyingSolids.exe`. Její jediné ovládací okno zůstává použitelné i za běhu animace. V seznamu vyberte jeden nebo více monitorů; dvojklikem na řádek příslušný monitor zapnete nebo vypnete. Lze také odepnout všechny monitory. Změny se průběžně ukládají. Snímky se ve výchozím stavu ukládají do složky **Obrázky**, při její neexistenci do **Dokumentů**. Záznamy MP4 se ukládají do složky **Videa**, případně do **Dokumentů**.

Aplikace běží pouze v jedné instanci. Další spuštění obnoví minimalizované ovládací okno, překreslí je a přenese do popředí.

Mezi ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a příslušného písmene. Esc zavře aktivní nápovědu či okno O aplikaci; v ovládacím okně ukončí aplikaci.

Snímek a záznam zachycují první aktivní animační monitor, nikoli společnou plochu všech monitorů. PNG používá složku Obrázky, MP4 složku Videa; při jejich neexistenci se použijí Dokumenty. Záznam MP4 odpovídá obnovovací frekvenci monitoru, nejvýše však 60 snímkům za sekundu.

Aplikace umí nainstalovat nebo odinstalovat spořič zabalený přímo v EXE, takže pro instalaci není samostatný soubor `.scr` nutný.

## Spořič obrazovky

`FlyingSolids.scr` má vlastní dialog nastavení a neobsahuje záznam. V celoobrazovkovém režimu spouští na každém monitoru nezávislou scénu.

Tlačítko Zapnout náhled v nastavení spustí samostatný celoobrazovkový náhled na všech monitorech. Používá aktuální nastavení a umožňuje úpravy za běhu; lze jej opět vypnout. Celoobrazovkový spořič ukončíte libovolnou klávesou, pohybem myši nebo kliknutím.

Esc v nastavení odpovídá tlačítku Storno; v nápovědě nebo okně O aplikaci zavře pouze toto okno.

## Uložení nastavení

Nastavení aplikace a spořiče se navzájem nepřepisují:

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Systémové požadavky

Windows 7 až Windows 11 podporují všechny funkce včetně snímků PNG a záznamu MP4.

Pro spuštění aplikace ve Windows Vista SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917. Záznam MP4 na Vistě v současné verzi nefunguje.

Vykreslování vyžaduje Direct3D 11, nikoli jen starší DirectX runtime. Záznam MP4 vyžaduje dostupné součásti Media Foundation a kodér H.264.

## Sestavení a balíček

Otevřete `DispSavers.slnx` v Microsoft Visual Studio s nástroji MSVC v145 a Windows SDK. Zvolte `Release | x86` a sestavte celé řešení. Vzniknou soubory `Release\FlyingSolids.exe` a `Release\FlyingSolids.scr`. Konfigurace x64 není součástí řešení.

Skript `PackageRelease.ps1` vytvoří jediný balíček celého řešení `DispSavers-<version>-win32.zip`. Každý spořič má vlastní podadresář; nynější archiv obsahuje `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr` a `FlyingSolids\license.txt`. Parametry podpisu neukládají osobní údaje do repozitáře a zadávají se až při spuštění, například `PackageRelease.ps1 -SignerName "Název certifikátu" -SignToolPath "C:\Cesta\K\signtool.exe" -TimestampServer "https://timestamp.example"`. Binární soubor s existujícím platným podpisem Authenticode se pouze ověří a znovu se nepodepíše. Starý ZIP se smaže na začátku každého spuštění; chyba podpisu nebo ověření zastaví skript před vytvořením nového archivu.

## Licence

FlyingSolids je dostupný pod [licencí MIT](../license.txt).

Copyright © Petr Červinka — FortSoft 2026
