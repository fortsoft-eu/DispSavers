# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · **Slovenčina** · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Hardvérovo akcelerovaná animácia plných 3D objektov.

V zozname označte jeden alebo viac monitorov. Režim kamery, výber telies, svetlá, rýchlosti, veľkosť a počet kópií sa nastavujú len pre označené monitory a každý monitor si pamätá vlastné nastavenia. FlyingSolids zobrazuje osvetlené plné 3D telesá. Jazdce nastavujú rýchlosť objektov a kamery 0–1600 %, jednu až desať kópií a veľkosť 50–200 %. Vyberte Pozorovanie priestoru alebo priamy Prelet priestorom a zapnite požadované telesá. Začiarkavacie políčka Hlavné svetlo, Doplnkové svetlo, Základný jas a Prisvetlenie obrysov pod jazdcami nezávisle ovládajú osvetlenie scén na označených monitoroch. Základný jas prisvetľuje povrchy telies a prisvetlenie obrysov zvýrazňuje ich okraje. Nastavenia osvetlenia sa ukladajú zvlášť pre aplikáciu a šetrič obrazovky.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Hardvérovo akcelerovaný prelet premenlivým koridorom a lievikom.

FlightCorridor: Prelet medzi štyrmi premenlivými plochami; Prelet premenlivým lievikom. Každému monitoru priraďte práve jednu animáciu. Textúra prepína medzi textúrovanými plochami a drôteným modelom. Voľná rotácia kamery pomaly mení smer pohľadu vo všetkých troch rozmeroch. Voľba „Pauzy a obraty“ pridáva náhodné spomaľovanie, prestávky a zmeny smeru otáčania; dopredný pohyb pokračuje. Rýchlosť je 0–1600 %. Každý monitor má nezávislú náhodnú scénu vykresľovanú podľa vlastnej obnovovacej frekvencie. Hlavné svetlo, doplnkové svetlo, základný jas a prisvetlenie obrysov možno pre označené monitory zapínať nezávisle. Osvetlenie sa používa len pri textúrovaných plochách.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Hardvérovo akcelerovaný let nad vlniacimi sa a premenlivými plochami.

SpaceFlight: Nekonečná vlniaca sa plocha; Diaľkový let — premenlivá plocha; Prelet gravitačne deformovaným priestorom. Každému monitoru priraďte práve jednu animáciu. Textúra prepína medzi textúrovanými plochami a drôteným modelom. Voľná rotácia kamery pomaly mení smer pohľadu vo všetkých troch rozmeroch. Voľba „Pauzy a obraty“ pridáva náhodné spomaľovanie, prestávky a zmeny smeru otáčania; dopredný pohyb pokračuje. Rýchlosť je 0–1600 %. Každý monitor má nezávislú náhodnú scénu vykresľovanú podľa vlastnej obnovovacej frekvencie. Hlavné svetlo, doplnkové svetlo, základný jas a prisvetlenie obrysov možno pre označené monitory zapínať nezávisle. Osvetlenie sa používa len pri textúrovaných plochách. Pri oboch animáciách plôch možno zvoliť rovinu, vlnenie alebo lievik. Lievik vťahuje kameru dovnútra po zostupnej špirále. Gravitačne deformovaný priestor sa zobrazuje trojrozmernou drôtovou mriežkou. Textúra, tvar plochy a osvetlenie platia len pre obe animácie plôch.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Conwayova hra života na jednej spoločnej ploche monitorov.

### Pravidlá

Conwayova hra života používa pravidlá B3/S23. Mŕtva bunka ožije pri práve troch živých susedoch; živá prežije s dvoma alebo troma. Osem susedov zahŕňa aj uhlopriečky. Všetky bunky sa menia súčasne. Protiľahlé okraje nadväzujú: ľavý na pravý a horný na dolný.

### Monitory a spoločná plocha

Začiarkavacie políčka v EXE zapínajú monitory; nastavenia platia pre spoločnú hru. Jediný zapnutý monitor obsahuje celú plochu. Pri výbere časti zostavy sa úplne prázdne riadky a stĺpce odstránia: ľavý a pravý monitor po vypnutí prostredného nadviažu. Neodstrániteľné vnútorné diery zostávajú súčasťou simulácie. Výber všetkých monitorov a režim SCR zachovávajú obdĺžnik celej zostavy vrátane neviditeľných medzier. Každý monitor zobrazuje vlastný výrez tej istej hry.

### Počiatočný stav a obrazce

Predvolený začiatok je náhodný šum s 25 % živých buniek. Počiatočná hustota 0–100 % sa použije pri ďalšom reštarte. Iba známe obrazce používa 4 106 priložených obrazcov bez šumu a vypne hustotu. Vyberte zmes alebo pomenovaný obrazec; rozmery sú v bunkách. Písaním názvu hľadajte v zozname. Vždy sú dostupné všetky obrazce katalógu. Malé overené obrazce sa opakujú v oddelených kópiách, veľké a zložité začínajú raz uprostred. Príliš veľký obrazec sa vycentruje a oreže; zmena veľkosti plochy alebo buniek výber nezmení. Zmena režimu alebo obrazca vytvorí novú scénu. Reštarty výber zachovajú; katalóg funguje bez internetu.

### Veľkosť buniek, mriežka a farby

Bez mriežky je veľkosť bunky 1–64 px. Zobraziť mriežku pridá okraj 1 px vnútri existujúceho rozstupu: zobrazená veľkosť a posúvač sa znížia o jednu, použiteľné hodnoty sú 1–63. Vypnutie hodnotu vráti. Posúvač zachová celý rozsah a z nedostupného konca sa vráti; políčko zostáva dostupné. Prepínanie zachová scénu okrem zapnutia pri 1 px, keď sa rozstup zvýši na 2 px a vznikne nová scéna. Aj zmena veľkosti alebo monitorov začne znova. Mimoriadne veľká plocha môže vyžadovať vyššie minimum. Farby buniek, pozadia a mriežky sa menia nezávisle bez reštartu. Náhodná farba živých buniek sa vyberá pri každom ručnom aj automatickom reštarte scény. Uložená farba sa neprepíše; vypnutie tejto voľby ju obnoví. Rovnaké správanie možno samostatne zapnúť pre pozadie a mriežku; obe nové voľby sú spočiatku vypnuté.

### Rýchlosť, pozastavenie a automatický reštart

Rýchlosť je 0–240 generácií/s nezávisle od obnovovania monitora; 0 zastaví vývoj. Pozastaviť a Pokračovať zachovávajú plochu. Reštart vytvorí nový začiatok vo vybranom režime. Voliteľný automatický reštart rozpoznáva statické aj presne sa opakujúce zobrazené fázy vrátane oscilátorov. Porovnáva generácie, nie uplynulé sekundy; nezobrazené oblasti vynecháva. Asynchrónne výsledky môžu reštart trochu oneskoriť. Predvolené hodnoty: rozstup 8 px, 20 generácií/s, náhodná farba živých buniek a automatický reštart zapnuté. Mriežka je predvolene vypnutá. Dosiahnutá rýchlosť závisí od výkonu a počtu buniek. Automatický reštart porovnáva oblasti zapnutých monitorov; medzery medzi nimi sa ďalej vyvíjajú, ale do porovnania sa nezahŕňajú.

### Obnoviť hodnoty

Obnovenie nastaví zobrazenú veľkosť bunky na 8 px s mriežkou aj bez nej (rozstup 9 alebo 8 px), rýchlosť na 20 generácií/s, hustotu na 25 % a tri predvolené farby. Ostatné voľby vrátane vybraného obrazca zachová. Nová scéna vznikne len pri zmene rozstupu alebo hustoty v režime šumu.

### Samostatná aplikácia a záznam MP4

EXE ukladá nastavenia priebežne a zaznamenáva prvý aktívny monitor do MP4. Ponúka Videá, prípadne Dokumenty. Viewport používa rozmery a obnovovaciu frekvenciu monitora do 60 snímok/s. TV ponúka 1920 × 1080, 1440 × 1080 alebo 1280 × 720 v pomere 16:9 pri 50, 25, 59,94 (60000/1001) alebo 29,97 (30000/1001) snímkach/s. Pomer strán sa zachováva; TV používa progresívne BT.709 s obmedzeným rozsahom a 4:2:0. Samostatné nastavenia záznamu možno minimalizovať. OK uloží voľby pre ďalší záznam, Zrušiť alebo Esc zahodí nepotvrdené zmeny. Zaznamenávaný monitor nemožno vypnúť; ostatné výstupy možno meniť. Ukončenie počas záznamu vyžaduje potvrdenie. Pri aktívnej animácii medzerník prepína pozastavenie, F9: Spustiť záznam; F10: Ukončiť záznam. Kurzor po 1 sekunde nečinnosti zmizne a pohybom sa objaví. Tab/Shift+Tab prechádza prvky, Alt vyvolá podčiarknuté voľby. Esc zavrie Pomoc/O programe alebo ukončí hlavné okno. Šetrič Windows… otvorí systémové nastavenie šetriča obrazovky.

### Snímka a správa šetriča v EXE

Snímka uloží BMP/GIF/JPEG/PNG/TIFF/WebP zaznamenávaného monitora, inak prvého aktívneho, v jeho rozlíšení bez reštartu scény. Ponúka priečinok Obrázky, prípadne Dokumenty. Blokovanie šetriča pri animácii bráni jeho spusteniu, kým je animácia viditeľná a nepozastavená. Nulová rýchlosť nie je pozastavenie. Inštalácia z EXE rozbalí priložený SCR a vyberie ho ako šetrič Windows. Inštalácia aj odinštalovanie môžu vyžadovať súhlas správcu; stavový riadok ukazuje priebeh až do dokončenia. Pri blokovanom odstránení zavrite spustený šetrič, jeho nastavenia a náhľad Windows.

### Šetrič obrazovky Windows

GameOfLife.scr používa všetky monitory a nastavenia oddelené od EXE. Zapnúť náhľad spustí celú obrazovku pri otvorených nastaveniach. Malý náhľad Windows zmenší celú spoločnú plochu. OK uloží nastavenia, Zrušiť alebo Esc zmeny zahodí. Pohyb myši alebo kláves ukončí celoobrazovkový šetrič. Záznam MP4 je dostupný v EXE.

### Poloha a stav okien

Pri zavretí sa samostatne ukladá poloha hlavného okna a okna O programe; pri Pomoci aj veľkosť a normálny či maximalizovaný stav pred prípadnou minimalizáciou. To nezávisí od potvrdenia nastavení aplikácie. Ukončenie aplikácie zavrie aj Pomoc a O programe.

### Vykresľovanie a licencie obrazcov

Vývoj a porovnávanie zobrazených stavov vykonávajú shadery Direct3D 11 na GPU; pri zlyhaní hardvérovej inicializácie je dostupné softvérové vykresľovanie. Každý monitor používa prevzatý framepacer podľa vlastnej obnovovacej frekvencie. MP4 vyžaduje Media Foundation a kodér H.264. Obrazce sú z LifeWiki (GFDL 1.2 alebo novšia) a zo zbierok Alana Hensela vo verejnej doméne. Kód má licenciu MIT; oznámenia a licencie katalógu sú samostatné.

[Zdroje obrazcov, licencie a podrobnosti importu](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### MONITORY

Označenie riadkov určuje, ktoré monitory práve nastavujete; je nezávislé od políčok zapínajúcich animačné výstupy. Ctrl+A označí všetky monitory, Ctrl a Shift upravujú označenie. Všetky animačné voľby a posuvníky platia pre označené monitory. Označenie sa pamätá zvlášť pre EXE a SCR. Ak boli označené všetky monitory, označia sa aj novopripojené. Rozdielne hodnoty na označených monitoroch ukazuje neurčitý stav políčok a bodkovanie prepínačov, úchytov posuvníkov a tlačidiel „Všetko zapnúť“ a „Všetko vypnúť“. Popis posuvníka namiesto spoločnej hodnoty zobrazuje pomlčku. Zmena voľby alebo kliknutie na posuvník zjednotí príslušnú hodnotu na označených monitoroch.

### OVLÁDANIE

Animačné výstupy zapnete alebo vypnete políčkami pri monitoroch alebo dvojklikom na ich riadky. Každý monitor používa nezávislú scénu. Snímka uloží BMP/GIF/JPEG/PNG/TIFF/WebP a tlačidlo záznamu spustí alebo ukončí MP4. Pozastavenie zastaví animáciu. Aplikácia tiež nainštaluje alebo odinštaluje vložený šetrič. Nastavenia sa ukladajú priebežne. Aplikácia beží iba v jednej inštancii. Ďalšie spustenie obnoví minimalizované ovládacie okno a prenesie ho do popredia. Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a príslušného písmena. Esc zavrie aktívne okno Pomoc alebo O programe; v ovládacom okne ukončí aplikáciu. Pozastavenie a blokovanie šetriča platia pre celú aplikáciu bez ohľadu na označené monitory. Ak je blokovanie zapnuté, bráni spusteniu šetriča Windows iba vtedy, keď je aspoň na jednom monitore viditeľná nepozastavená animácia.

### SNÍMKY A ZÁZNAM

Snímky a záznamy zachytávajú prvý aktívny animačný monitor, nie spoločnú plochu všetkých monitorov. BMP/GIF/JPEG/PNG/TIFF/WebP používa Obrázky, MP4 Videá; ak tieto priečinky neexistujú, použijú sa Dokumenty. Tlačidlo Nastavenie záznamu vyberá Viewport alebo TV. Viewport zachováva rozmery animačného monitora a jeho obnovovaciu frekvenciu, najviac 60 snímok za sekundu. TV ponúka rozlíšenie 1920 × 1080, 1440 × 1080 alebo 1280 × 720 v pomere 16:9 a frekvenciu 50, 25, 59.94 (60000/1001) alebo 29.97 (30000/1001) snímok za sekundu. Obraz zachováva pomer strán; TV používa progresívne video BT.709 s obmedzeným rozsahom a vzorkovaním 4:2:0. Rozlíšenie a snímkovú frekvenciu možno vybrať iba v režime TV. Okno Nastavenie záznamu možno minimalizovať a neblokuje ostatné okná aplikácie. OK uloží voľby pre nasledujúci záznam MP4; Zrušiť alebo Esc zahodí nepotvrdené zmeny. Animačný výstup nahrávaného monitora nemožno počas záznamu vypnúť; zmeny ostatných monitorov záznam nezastavia. Ukončenie aplikácie počas záznamu vyžaduje potvrdenie, pretože ukončí aj záznam.

### NÁHĽAD A OVLÁDANIE

Zapnúť náhľad spustí celoobrazovkový náhľad na všetkých monitoroch; nastavenia zostávajú otvorené a zmeny sa prejavia ihneď. OK uloží nastavenia a Zrušiť ich zahodí. Celoobrazovkový šetrič ukončí Esc alebo pohyb myši. Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a príslušného písmena. Esc v nastaveniach zodpovedá tlačidlu Zrušiť; v okne Pomoc alebo O programe zavrie iba toto okno.

### Systémové požiadavky

Windows 7 až Windows 11 podporujú všetky funkcie vrátane snímok BMP/GIF/JPEG/PNG/TIFF/WebP a záznamu MP4. Na spustenie aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať aktualizácie KB971512 a KB2117917. Záznam MP4 na Viste v súčasnej verzii nefunguje. Vykresľovanie vyžaduje Direct3D 11, nie iba starší DirectX runtime. Záznam MP4 vyžaduje dostupné súčasti Media Foundation a kodér H.264. Samostatná aplikácia môže bežať aj v Linuxe prostredníctvom Wine; integrácia šetriča obrazovky je dostupná iba vo Windows.

## Zostavenie

Otvorte `DispSavers.slnx` vo Visual Studiu s nástrojmi MSVC v145 a Windows SDK. Zvoľte `Release | x86` a znova zostavte riešenie; vzniknú `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\GameOfLife.exe`, `Release\GameOfLife.scr`, `Release\SpaceFlight.exe` a `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr`. Konfigurácia x64 nie je dostupná.

Takto zostavené súbory zabaľte spustením `PackageRelease.ps1` bez parametrov podpisu. Skript pracuje s dočasnými kópiami, nemení súbory v `Release` a iba overí existujúce platné podpisy. Vytvorí jediný archív `DispSavers-<version>-win32.zip` obsahujúci `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `GameOfLife\GameOfLife.exe`, `GameOfLife\GameOfLife.scr`, `GameOfLife\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` a `SpaceFlight\license.txt`. Predchádzajúci ZIP sa odstráni na začiatku spustenia; chyba overenia zabráni vytvoreniu nového archívu.

## Licencia

DispSavers je dostupný pod [licenciou MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026
