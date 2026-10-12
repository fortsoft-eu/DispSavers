# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · **Slovenčina** · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids je natívna aplikácia Win32/x86 využívajúca Direct3D a šetrič obrazovky Windows. Zobrazuje osvetlené plné priestorové geometrické telesá. Telesá sa nezávisle pohybujú, otáčajú a odrážajú bez vzájomného prenikania. Počiatočné stavy a opätovne použité polohy pri prelete pochádzajú z kryptografického generátora Windows; bloková medzipamäť udržiava nízku záťaž CPU.

## Funkcie

- **Pozorovanie priestoru** a priamy **Prelet priestorom**
- Nezávislé zapínanie hlavného a doplnkového svetla
- Nezávislá scéna na každom vybranom monitore
- Jedna až desať kópií každého zapnutého telesa
- Rýchlosť objektov a kamery 0–1600 %, veľkosť 50–200 %
- Lesklé osvetlenie, samostatné farby a riešenie kolízií
- Vykresľovanie prispôsobené obnovovacej frekvencii monitorov
- Snímky PNG a záznam MP4 v samostatnej aplikácii
- Oddelené nastavenia aplikácie a šetriča
- 30 typov telies a rozhranie v 17 jazykoch

## Telesá

Katalóg obsahuje mnohosteny, pravidelné hranoly, ihlany a ich rovinné rezy, kužele a valce a ich rezy, rotačný paraboloid uzavretý rovinou, telesá odvodené od gule, elipsoidy, ovoid, sferocylinder a anuloid. Rozhranie používa zaužívanú slovenskú geometrickú terminológiu.

- Predĺžený rotačný elipsoid má jednu dlhšiu a dve zhodné kratšie poloosi.
- Zaoblený disk (spheroplatelet) má dve rovinné kruhové plochy a plynulo zaoblený obvod; jeho priemer je mierne väčší než pri guľovej vrstve a hrúbka polovičná.
- Dutý valec s toroidálnymi čelami má vonkajšiu a vnútornú valcovú plochu spojené polovicami torusu, ktoré v osovom reze tvoria presné polkruhy.

## Osvetlenie

Začiarkavacie políčka `Hlavné svetlo` a `Doplnkové svetlo` pod pravými jazdcami nezávisle zapínajú alebo vypínajú obe svetlá pre celú scénu. Predvolene je `Hlavné svetlo` zapnuté a `Doplnkové svetlo` vypnuté. Nastavenia svetiel sa ukladajú zvlášť pre aplikáciu a šetrič obrazovky.

## Aplikácia a šetrič

`FlyingSolids.exe` ponechá počas animácie dostupné jediné ovládacie okno. Možno vybrať viac monitorov, dvojklikom jeden prepnúť alebo odpojiť všetky. PNG sa predvolene ukladajú do **Obrázky**, MP4 do **Videá** a náhradou sú **Dokumenty**. EXE dokáže nainštalovať aj odinštalovať vložený šetrič.

Aplikácia beží iba v jednej inštancii. Ďalšie spustenie obnoví minimalizované ovládacie okno, prekreslí ho a prenesie do popredia.

Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a príslušného písmena. Esc zavrie aktívne okno Pomocníka alebo O aplikácii; v ovládacom okne ukončí aplikáciu.

Snímky a záznamy zachytávajú prvý aktívny animačný monitor, nie spoločnú plochu všetkých monitorov. PNG používa Obrázky, MP4 Videá; ak tieto priečinky neexistujú, použijú sa Dokumenty. Záznam MP4 zodpovedá obnovovacej frekvencii monitora, najviac však 60 snímkam za sekundu.

`FlyingSolids.scr` má vlastné nastavenia bez záznamu. Celoobrazovkový režim vytvorí nezávislú scénu na každom monitore.

Tlačidlo Zapnúť náhľad v nastaveniach spustí samostatný celoobrazovkový náhľad na všetkých monitoroch. Používa aktuálne nastavenia, umožňuje úpravy za behu a možno ho opäť vypnúť. Celoobrazovkový šetrič ukončí ľubovoľný kláves, pohyb myši alebo kliknutie.

Esc v nastaveniach zodpovedá tlačidlu Zrušiť; v Pomocníkovi alebo okne O aplikácii zavrie iba toto okno.

## Uloženie nastavení

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Systémové požiadavky

Windows 7 až Windows 11 podporujú všetky funkcie vrátane snímok PNG a záznamu MP4.

Na spustenie aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať aktualizácie KB971512 a KB2117917. Záznam MP4 na Viste v súčasnej verzii nefunguje.

Vykresľovanie vyžaduje Direct3D 11, nie iba starší DirectX runtime. Záznam MP4 vyžaduje dostupné súčasti Media Foundation a kodér H.264.

## Zostavenie

Otvorte `DispSavers.slnx`, zvoľte `Release | x86` a znova zostavte riešenie pomocou MSVC v145 a Windows SDK. Vzniknú EXE aj SCR. `PackageRelease.ps1` vytvorí jediný balíček riešenia `DispSavers-<version>-win32.zip`, v ktorom sú súbory a `license.txt` v podadresári `FlyingSolids`. Konfigurácia x64 nie je dostupná.

## Licencia

FlyingSolids je dostupný pod [licenciou MIT](../license.txt).

Copyright © Petr Červinka — FortSoft 2026
