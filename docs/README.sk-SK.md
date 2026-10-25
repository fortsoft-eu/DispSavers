# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · **Slovenčina** · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlyingSolids je natívna aplikácia Win32/x86 využívajúca Direct3D a šetrič obrazovky Windows. Zobrazuje osvetlené plné priestorové geometrické telesá. Telesá sa nezávisle pohybujú, otáčajú a odrážajú bez vzájomného prenikania.

Označenie riadkov určuje, ktoré monitory práve nastavujete; je nezávislé od políčok zapínajúcich animačné výstupy. Ctrl+A označí všetky monitory, Ctrl a Shift upravujú označenie. Všetky animačné voľby a posuvníky platia pre označené monitory. Označenie sa pamätá zvlášť pre EXE a SCR. Ak boli označené všetky monitory, označia sa aj novopripojené. Rozdielne hodnoty na označených monitoroch ukazuje neurčitý stav políčok a bodkovanie prepínačov, úchytov posuvníkov a tlačidiel „Všetko zapnúť“ a „Všetko vypnúť“. Popis posuvníka namiesto spoločnej hodnoty zobrazuje pomlčku. Zmena voľby alebo kliknutie na posuvník zjednotí príslušnú hodnotu na označených monitoroch.

## Funkcie

- **Pozorovanie priestoru** a priamy **Prelet priestorom**. V zozname označte jeden alebo viac monitorov. Režim kamery, výber telies, svetlá, rýchlosti, veľkosť a počet kópií sa nastavujú len pre označené monitory a každý monitor si pamätá vlastné nastavenia.
- Nezávislé ovládanie hlavného a doplnkového svetla, základného jasu a prisvetlenia obrysov
- Nezávislá scéna na každom monitore
- Jedna až desať kópií každého zapnutého telesa
- Rýchlosť objektov a kamery 0–1600 %, veľkosť 50–200 %
- Lesklé osvetlenie, samostatné farby a riešenie kolízií
- Vykresľovanie prispôsobené obnovovacej frekvencii monitorov
- Snímky PNG a záznam MP4 v samostatnej aplikácii
- Oddelené nastavenia aplikácie a šetriča
- 30 typov telies a rozhranie v 36 jazykoch

## Telesá

Kocka; Pravidelný štvorboký ihlan; Komolý štvorboký ihlan; Štvorboký ihlan so šikmým rezom; Štvorboký ihlan, rez kolmý na podstavu; Pravidelný trojboký hranol; Pravidelný päťboký hranol; Pravidelný šesťboký hranol; Pravidelný osemsten; Päťboký dvojihlan; Rotačný kužeľ; Komolý rotačný kužeľ; Rotačný kužeľ so šikmým rezom; Rotačný kužeľ s rezom kolmým na podstavu; Rotačný valec; Dutý rotačný valec; Dutý valec s toroidálnymi čelami; Rotačný paraboloid uzavretý rovinou; Guľa; Pologuľa; Guľový odsek; Veľký guľový odsek; Guľová vrstva; Trojosový elipsoid; Predĺžený rotačný elipsoid; Sploštený rotačný elipsoid; Ovoid; Sferocylinder; Zaoblený disk (spheroplatelet); Anuloid (torus).

## Osvetlenie

Začiarkavacie políčka `Hlavné svetlo`, `Doplnkové svetlo`, `Základný jas` a `Prisvetlenie obrysov` pod jazdcami nezávisle ovládajú osvetlenie scén na označených monitoroch. Základný jas prisvetľuje povrchy telies a prisvetlenie obrysov zvýrazňuje ich okraje. Nastavenia osvetlenia sa ukladajú zvlášť pre aplikáciu a šetrič obrazovky.

## Aplikácia a šetrič

`FlyingSolids.exe` ponechá počas animácie dostupné jediné ovládacie okno. Animačné výstupy zapnete alebo vypnete políčkami pri monitoroch alebo dvojklikom na ich riadky. EXE dokáže nainštalovať aj odinštalovať vložený šetrič. Aplikácia beží iba v jednej inštancii. Ďalšie spustenie obnoví minimalizované ovládacie okno a prenesie ho do popredia. Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a príslušného písmena. Esc zavrie aktívne okno Pomoc alebo O aplikácii; v ovládacom okne ukončí aplikáciu. Snímky a záznamy zachytávajú prvý aktívny animačný monitor, nie spoločnú plochu všetkých monitorov. PNG používa Obrázky, MP4 Videá; ak tieto priečinky neexistujú, použijú sa Dokumenty. Tlačidlo Nastavenie záznamu vyberá Viewport alebo TV. Viewport zachováva rozmery animačného monitora a jeho obnovovaciu frekvenciu, najviac 60 snímok za sekundu. TV ponúka rozlíšenie 1920 × 1080, 1440 × 1080 alebo 1280 × 720 v pomere 16:9 a frekvenciu 50, 25, 59.94 (60000/1001) alebo 29.97 (30000/1001) snímok za sekundu. Obraz zachováva pomer strán; TV používa progresívne video BT.709 s obmedzeným rozsahom a vzorkovaním 4:2:0. Rozlíšenie a snímkovú frekvenciu možno vybrať iba v režime TV. Okno Nastavenie záznamu možno minimalizovať a neblokuje ostatné okná aplikácie. OK uloží voľby pre nasledujúci záznam MP4; Zrušiť alebo Esc zahodí nepotvrdené zmeny. Animačný výstup nahrávaného monitora nemožno počas záznamu vypnúť; zmeny ostatných monitorov záznam nezastavia. Ukončenie aplikácie počas záznamu vyžaduje potvrdenie, pretože ukončí aj záznam. Pozastavenie a blokovanie šetriča platia pre celú aplikáciu bez ohľadu na označené monitory. Ak je blokovanie zapnuté, bráni spusteniu šetriča Windows iba vtedy, keď je aspoň na jednom monitore viditeľná nepozastavená animácia. `FlyingSolids.scr` má vlastné nastavenia bez záznamu. Celoobrazovkový režim vytvorí nezávislú scénu na každom monitore. Tlačidlo Zapnúť náhľad v nastaveniach spustí samostatný celoobrazovkový náhľad na všetkých monitoroch. Používa aktuálne nastavenia, umožňuje úpravy za behu a možno ho opäť vypnúť. Celoobrazovkový šetrič ukončí ľubovoľný kláves, pohyb myši alebo kliknutie. Esc v nastaveniach zodpovedá tlačidlu Zrušiť; v okne Pomoc alebo O aplikácii zavrie iba toto okno.

## Uloženie nastavení

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Systémové požiadavky

Windows 7 až Windows 11 podporujú všetky funkcie vrátane snímok PNG a záznamu MP4. Na spustenie aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať aktualizácie KB971512 a KB2117917. Záznam MP4 na Viste v súčasnej verzii nefunguje. Vykresľovanie vyžaduje Direct3D 11, nie iba starší DirectX runtime. Záznam MP4 vyžaduje dostupné súčasti Media Foundation a kodér H.264. Samostatná aplikácia môže bežať aj v Linuxe prostredníctvom Wine; integrácia šetriča obrazovky je dostupná iba vo Windows.

## Zostavenie

Otvorte `DispSavers.slnx` vo Visual Studiu s nástrojmi MSVC v145 a Windows SDK. Zvoľte `Release | x86` a znova zostavte riešenie; vzniknú `Release\FlyingSolids.exe` a `Release\FlyingSolids.scr`. Konfigurácia x64 nie je dostupná. Vo vlastnostiach projektu `FlyingSolids` na stránke `Signing` zadajte meno alebo odtlačok platného certifikátu na podpisovanie kódu so súkromným kľúčom v úložisku aktuálneho používateľa `Personal (My)`. Nastavenia sú spoločné pre EXE a SCR a ukladajú sa do súboru `FlyingSolids.vcxproj.user`, ktorý Git ignoruje. SignTool sa automaticky vyhľadá v PATH alebo vo Windows SDK. Ak používate SimplySign, pred zostavením sa prihláste do SimplySign Desktop. Najprv sa podpíše SCR a pridá sa povinná časová pečiatka RFC 3161 so SHA-256 z nastaveného servera časových pečiatok; potom sa vloží do EXE, ktoré tiež dostane podpis a pečiatku. Do poľa `Timestamp server` zadajte adresu servera časových pečiatok RFC 3161. Chyba podpisu, pečiatky alebo overenia zastaví zostavenie; súbory s platným podpisom a pečiatkou sa znovu nepodpisujú.

Takto zostavené súbory zabaľte spustením `PackageRelease.ps1` bez parametrov podpisu. Skript pracuje s dočasnými kópiami, nemení súbory v `Release` a iba overí existujúce platné podpisy. Vytvorí jediný archív `DispSavers-<version>-win32.zip` obsahujúci `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` a `SpaceFlight\license.txt`. Predchádzajúci ZIP sa odstráni na začiatku spustenia; chyba overenia zabráni vytvoreniu nového archívu.

## Licencia

FlyingSolids je dostupný pod [licenciou MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026

## FlightCorridor

FlightCorridor ponúka Prelet medzi štyrmi premenlivými plochami a Prelet premenlivým lievikom. Každému monitoru priradíte práve jeden prelet: označte jeho riadok v zozname a zvoľte príslušný prepínač.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](../FlightCorridor/README.sk-SK.md)

## SpaceFlight

SpaceFlight: Nekonečná vlniaca sa plocha; Diaľkový let — premenlivá plocha; Prelet gravitačne deformovaným priestorom. Každému monitoru priradíte práve jeden prelet: označte jeho riadok v zozname a zvoľte príslušný prepínač.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](../SpaceFlight/README.sk-SK.md)
