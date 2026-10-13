# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · **Slovenčina** · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids je natívna aplikácia Win32/x86 využívajúca Direct3D a šetrič obrazovky Windows. Zobrazuje osvetlené plné priestorové geometrické telesá. Telesá sa nezávisle pohybujú, otáčajú a odrážajú bez vzájomného prenikania.

## Funkcie

- **Pozorovanie priestoru** a priamy **Prelet priestorom**
- Nezávislé ovládanie hlavného a doplnkového svetla, základného jasu a prisvetlenia obrysov
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

## Osvetlenie

Začiarkavacie políčka `Hlavné svetlo`, `Doplnkové svetlo`, `Základný jas` a `Prisvetlenie obrysov` pod jazdcami nezávisle ovládajú osvetlenie celej scény. Základný jas prisvetľuje povrchy telies a prisvetlenie obrysov zvýrazňuje ich okraje. Predvolene sú hlavné svetlo, základný jas a prisvetlenie obrysov zapnuté a doplnkové svetlo vypnuté. Nastavenia osvetlenia sa ukladajú zvlášť pre aplikáciu a šetrič obrazovky.

## Aplikácia a šetrič

`FlyingSolids.exe` ponechá počas animácie dostupné jediné ovládacie okno. Možno vybrať viac monitorov, dvojklikom jeden prepnúť alebo odpojiť všetky. EXE dokáže nainštalovať aj odinštalovať vložený šetrič. Aplikácia beží iba v jednej inštancii. Ďalšie spustenie obnoví minimalizované ovládacie okno a prenesie do popredia. Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a príslušného písmena. Esc zavrie aktívne okno Pomocníka alebo O aplikácii; v ovládacom okne ukončí aplikáciu. Snímky a záznamy zachytávajú prvý aktívny animačný monitor, nie spoločnú plochu všetkých monitorov. PNG používa Obrázky, MP4 Videá; ak tieto priečinky neexistujú, použijú sa Dokumenty. Tlačidlo Nastavenie záznamu vyberá Viewport alebo TV. Viewport zachováva rozmery animačného monitora a jeho obnovovaciu frekvenciu, najviac 60 snímok za sekundu. TV ponúka rozlíšenie 1920 × 1080, 1440 × 1080 alebo 1280 × 720 v pomere 16:9 a frekvenciu 50, 25, 59.94 (60000/1001) alebo 29.97 (30000/1001) snímok za sekundu. Obraz zachováva pomer strán; TV používa progresívne video BT.709 s obmedzeným rozsahom a vzorkovaním 4:2:0. Rozlíšenie a snímkovú frekvenciu možno vybrať iba v režime TV. Okno Nastavenie záznamu možno minimalizovať a neblokuje ostatné okná aplikácie. OK uloží voľby pre nasledujúci záznam MP4; Zrušiť alebo Esc zahodí nepotvrdené zmeny. Nahrávaný monitor nemožno počas záznamu odpojiť; zmeny ostatných monitorov záznam nezastavia. Ukončenie aplikácie počas záznamu vyžaduje potvrdenie, pretože ukončí aj záznam. Voľba Blokovať šetrič pri animácii bráni spusteniu šetriča Windows iba vtedy, keď je animácia skutočne viditeľná a nie je pozastavená. `FlyingSolids.scr` má vlastné nastavenia bez záznamu. Celoobrazovkový režim vytvorí nezávislú scénu na každom monitore. Tlačidlo Zapnúť náhľad v nastaveniach spustí samostatný celoobrazovkový náhľad na všetkých monitoroch. Používa aktuálne nastavenia, umožňuje úpravy za behu a možno ho opäť vypnúť. Celoobrazovkový šetrič ukončí ľubovoľný kláves, pohyb myši alebo kliknutie. Esc v nastaveniach zodpovedá tlačidlu Zrušiť; v Pomocníkovi alebo okne O aplikácii zavrie iba toto okno.

## Uloženie nastavení

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Systémové požiadavky

Windows 7 až Windows 11 podporujú všetky funkcie vrátane snímok PNG a záznamu MP4. Na spustenie aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať aktualizácie KB971512 a KB2117917. Záznam MP4 na Viste v súčasnej verzii nefunguje. Vykresľovanie vyžaduje Direct3D 11, nie iba starší DirectX runtime. Záznam MP4 vyžaduje dostupné súčasti Media Foundation a kodér H.264.

## Zostavenie

Otvorte `DispSavers.slnx` vo Visual Studiu s nástrojmi MSVC v145 a Windows SDK. Zvoľte `Release | x86` a znova zostavte riešenie; vzniknú `Release\FlyingSolids.exe` a `Release\FlyingSolids.scr`. Konfigurácia x64 nie je dostupná. Podpisovanie je predvolene zapnuté pre Release aj Debug. Vo vlastnostiach projektu `FlyingSolids` na stránke `Signing` zadajte meno alebo odtlačok platného certifikátu na podpisovanie kódu so súkromným kľúčom v úložisku aktuálneho používateľa `Personal (My)`. Nastavenia sú spoločné pre EXE a SCR a ukladajú sa do súboru `FlyingSolids.vcxproj.user`, ktorý Git ignoruje. SignTool sa automaticky vyhľadá v PATH alebo vo Windows SDK. Ak používate SimplySign, pred zostavením sa prihláste do SimplySign Desktop. Najprv sa podpíše SCR a pridá sa povinná časová pečiatka RFC 3161 so SHA-256 z nastaveného servera časových pečiatok; potom sa vloží do EXE, ktoré tiež dostane podpis a pečiatku. Do poľa `Timestamp server` zadajte adresu servera časových pečiatok RFC 3161. Chyba podpisu, pečiatky alebo overenia zastaví zostavenie; súbory s platným podpisom a pečiatkou sa znovu nepodpisujú.

Takto zostavené súbory zabaľte spustením `PackageRelease.ps1` bez parametrov podpisu. Skript pracuje s dočasnými kópiami, nemení súbory v `Release` a iba overí existujúce platné podpisy. Vytvorí jediný archív `DispSavers-<version>-win32.zip` obsahujúci `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr` a `FlyingSolids\license.txt`. Predchádzajúci ZIP sa odstráni na začiatku spustenia; chyba overenia zabráni vytvoreniu nového archívu.

## Licencia

FlyingSolids je dostupný pod [licenciou MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026
