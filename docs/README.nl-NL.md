# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · **Nederlands** · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Hardwareversnelde animatie van massieve 3D-objecten.

FlyingSolids toont bewegende, draaiende en botsende driedimensionale lichamen. Kies ruimte observeren of door de ruimte vliegen en schakel de gewenste lichamen in. Stel per beeldscherm de object- en camerasnelheid in op 0–1600%, de objectgrootte op 50–200% en het aantal kopieën op 1–10 per lichaam. Hoofdlicht, invullicht, omgevingslicht en randlicht zijn onafhankelijk schakelbaar.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Hardwareversnelde vlucht tussen vervormende oppervlakken.

Hardwareversnelde vlucht tussen vervormende oppervlakken. Vlucht tussen vier vervormende oppervlakken; Vlucht door een vervormende trechter. Kies precies één animatie per beeldscherm. Textuur schakelt tussen een getextureerd oppervlak en een draadmodel. Vrije camerarotatie verandert de kijkrichting langzaam in alle drie dimensies. De optie Pauzes en omkeren voegt willekeurige vertragingen, pauzes en omkeringen van de rotatie toe; de voorwaartse vlucht gaat door. De snelheid is instelbaar op 0–1600%. Elk beeldscherm heeft een onafhankelijke willekeurige scène en wordt op zijn eigen vernieuwingsfrequentie aangestuurd. Hoofdlicht, invullicht, omgevingslicht en randlicht kunnen onafhankelijk worden geschakeld voor de geselecteerde beeldschermen. De verlichting geldt alleen voor oppervlakken met textuur.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Hardwareversnelde vlucht boven een golvend oppervlak.

SpaceFlight: Oneindig golvend oppervlak; Langeafstandsvlucht — veranderend oppervlak; Vlucht door gravitatiegekromde ruimte. Kies precies één animatie per beeldscherm. Textuur schakelt tussen een getextureerd oppervlak en een draadmodel. Vrije camerarotatie verandert de kijkrichting langzaam in alle drie dimensies. De optie Pauzes en omkeren voegt willekeurige vertragingen, pauzes en omkeringen van de rotatie toe; de voorwaartse vlucht gaat door. De snelheid is instelbaar op 0–1600%. Elk beeldscherm heeft een onafhankelijke willekeurige scène en wordt op zijn eigen vernieuwingsfrequentie aangestuurd. Hoofdlicht, invullicht, omgevingslicht en randlicht kunnen onafhankelijk worden geschakeld voor de geselecteerde beeldschermen. De verlichting geldt alleen voor oppervlakken met textuur. De twee oppervlakteanimaties bieden Vlak, Golven of Trechter. De trechter trekt de camera langs een dalende spiraal naar binnen. De vlucht door gravitatiegekromde ruimte toont een driedimensionaal draadrooster. De opties voor textuur, oppervlaktevorm en verlichting gelden alleen voor de twee oppervlakteanimaties.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Conways Game of Life in één gedeelde wereld over meerdere schermen.

### Regels

Conways Game of Life gebruikt B3/S23. Een dode cel wordt levend bij precies drie levende buren; een levende overleeft bij twee of drie. De acht buren omvatten diagonalen. Alle cellen veranderen tegelijk. Tegenoverliggende randen sluiten aan: links op rechts, boven op onder.

### Schermen en gedeelde wereld

Vinkjes in EXE schakelen schermen in; instellingen gelden voor de gedeelde wereld. Eén ingeschakeld scherm bevat de hele wereld. Bij een gedeeltelijke keuze vervallen volledig lege rijen en kolommen: links en rechts sluiten aan als het middelste scherm uitstaat. Niet verwijderbare binnenste gaten blijven in de simulatie. Alle schermen selecteren, of SCR gebruiken, behoudt de bureaubladrechthoek inclusief onzichtbare gaten. Elk scherm toont zijn eigen gebied van dezelfde simulatie.

### Beginstand en patronen

Standaard start willekeurige ruis met 25 % levende cellen. Begindichtheid van 0–100 % geldt bij de volgende herstart. Alleen bekende patronen gebruikt 4.106 meegeleverde patronen zonder ruis en schakelt dichtheid uit. Kies een mengsel of een patroon op naam; afmetingen zijn in cellen. Typ een naam om te zoeken. Alle patronen in de catalogus zijn altijd beschikbaar. Kleine gecontroleerde patronen verschijnen in losse kopieën, grote of complexe één keer in het midden. Een te groot patroon wordt gecentreerd en bijgesneden; een andere wereld- of celgrootte behoudt de keuze. Een andere modus of patroon maakt een nieuwe scène. Herstarts behouden de keuze; de catalogus werkt offline.

### Celgrootte, raster en kleuren

Zonder raster is de celgrootte 1–64 px. Raster tonen voegt binnen de bestaande afstand een rand van 1 px toe: waarde en schuif dalen met één, bruikbaar is 1–63. Uitschakelen herstelt de waarde. De schuif behoudt zijn bereik en springt terug vanaf het onbeschikbare uiteinde; het vinkje blijft bruikbaar. Omschakelen behoudt de scène, behalve inschakelen bij 1 px: de afstand wordt 2 px en er begint een nieuwe scène. Celgrootte of schermen wijzigen begint ook opnieuw. Zeer grote werelden kunnen een hoger minimum vragen. Cel-, achtergrond- en rasterkleuren veranderen afzonderlijk zonder herstart. Willekeurige kleur van levende cellen kiest bij elke handmatige of automatische herstart van de scène een nieuwe kleur. De opgeslagen kleur blijft behouden en keert terug als deze optie uitstaat. Hetzelfde gedrag kan afzonderlijk voor achtergrond en raster worden ingeschakeld; beide nieuwe opties staan standaard uit.

### Snelheid, pauze en automatisch herstarten

De snelheid is 0–240 generaties/s, los van de verversingssnelheid; 0 stopt de evolutie. Pauze en Hervatten behouden de wereld. Opnieuw starten begint in de gekozen modus. Optioneel automatisch herstarten herkent vaste en exact herhalende zichtbare fasen, ook oscillatoren. Het vergelijkt generaties in plaats van seconden en negeert onzichtbare gebieden. Asynchrone resultaten kunnen de herstart iets vertragen. Standaard: afstand 8 px, 20 generaties/s, willekeurige kleur van levende cellen en automatisch herstarten aan. Het raster staat standaard uit. De bereikte snelheid hangt af van prestaties en celaantal. Automatisch herstarten vergelijkt de gebieden van ingeschakelde schermen; tussenliggende gaten ontwikkelen zich verder maar tellen niet mee in de vergelijking.

### Waarden herstellen

Herstellen zet de getoonde celgrootte op 8 px met of zonder raster (afstand 9 of 8 px), de snelheid op 20 generaties/s, de dichtheid op 25 % en herstelt de drie standaardkleuren. Andere keuzes, inclusief het gekozen patroon, blijven behouden. Een nieuwe scène ontstaat alleen bij gewijzigde afstand of gewijzigde dichtheid in ruismodus.

### Zelfstandige toepassing en MP4-opname

EXE bewaart instellingen doorlopend en neemt het eerste actieve scherm op als MP4. Video's wordt voorgesteld, anders Documenten. Viewport gebruikt schermafmetingen en verversingssnelheid tot 60 beelden/s. TV biedt 1920 × 1080, 1440 × 1080 of 1280 × 720 in 16:9 bij 50, 25, 59,94 (60000/1001) of 29,97 (30000/1001) beelden/s. De beeldverhouding blijft behouden; TV gebruikt progressief BT.709 met beperkt bereik en 4:2:0. Het onafhankelijke instellingenvenster kan worden geminimaliseerd. OK bewaart voor de volgende opname; Annuleren of Esc verwerpt onbevestigde wijzigingen. Het opgenomen scherm kan niet uit; andere uitgangen mogen veranderen. Afsluiten tijdens opname vraagt bevestiging. Met focus op de animatie wisselt Spatie de pauze, F9: Opname starten; F10: Opname stoppen. De aanwijzer verdwijnt na 1 seconde stilstand en keert bij beweging terug. Tab/Shift+Tab doorloopt bediening, Alt activeert onderstreepte opdrachten. Esc sluit Help/Info of verlaat het hoofdvenster. Windows-schermbeveiliging… opent de systeeminstellingen voor schermbeveiliging.

### Momentopname en schermbeveiligingsbeheer in EXE

Momentopname bewaart een BMP/GIF/JPEG/PNG/TIFF/WebP van het opgenomen scherm, anders het eerste actieve, op zijn resolutie zonder de scène te herstarten. Afbeeldingen wordt voorgesteld, anders Documenten. Schermbeveiliging blokkeren tijdens animatie voorkomt de start ervan zolang de animatie zichtbaar en niet gepauzeerd is. Snelheid nul is geen pauze. Installatie vanuit EXE pakt de meegeleverde SCR uit en selecteert deze als Windows-schermbeveiliging. Installeren en verwijderen kunnen beheerderstoestemming vereisen; de statusbalk toont de bewerking tot deze klaar is. Sluit bij geblokkeerde verwijdering de actieve schermbeveiliging, de instellingen en het Windows-voorbeeld.

### Windows-schermbeveiliging

GameOfLife.scr gebruikt alle schermen en bewaart instellingen apart van EXE. Voorbeeld inschakelen start volledig scherm terwijl instellingen openblijven. Het kleine Windows-voorbeeld verkleint de hele wereld. OK bewaart; Annuleren of Esc verwerpt wijzigingen. Muisbeweging of een toets sluit de schermbeveiliging op volledig scherm. MP4-opname is beschikbaar in EXE.

### Vensterposities en toestand

Bij sluiten worden de posities van het hoofdvenster en Info afzonderlijk opgeslagen; voor Help ook de grootte en normale of gemaximaliseerde toestand van vóór minimalisatie. Dit staat los van het bevestigen van toepassingsinstellingen. Afsluiten van de toepassing sluit ook Help en Info.

### Weergave en patroonlicenties

Evolutie en zichtbare vergelijkingen gebruiken Direct3D 11-shaders op de GPU; softwareweergave is beschikbaar als hardware-initialisatie mislukt. Elk scherm gebruikt de beproefde framepacer op zijn eigen frequentie. MP4 vereist Media Foundation en een H.264-encoder. Patronen komen van LifeWiki (GFDL 1.2 of hoger) en Alan Hensels verzamelingen in het publieke domein. De programmacode is MIT; catalogusvermeldingen en -licenties zijn afzonderlijk.

[Patroonbronnen, licenties en importgegevens](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### BEELDSCHERMEN

Selecteer één of meer beeldschermrijen in de lijst. Ctrl+A selecteert alles; met Ctrl en Shift past u de selectie aan. Animatieknoppen en schuifregelaars wijzigen alleen de instellingen van de geselecteerde beeldschermen. Een rij selecteren is iets anders dan de animatie-uitvoer inschakelen met het selectievakje. De selectie wordt apart onthouden voor de toepassing en de schermbeveiliging. Als alle beeldschermen waren geselecteerd, worden nieuw aangesloten beeldschermen ook geselecteerd. Verschillende waarden op geselecteerde beeldschermen worden aangegeven door selectievakjes in onbepaalde toestand en een stippelpatroon op keuzerondjes, schuifknoppen en de knoppen ‘Alles inschakelen’ en ‘Alles uitschakelen’. De labels van schuifregelaars tonen een streepje in plaats van een gemeenschappelijke waarde. Een optie wijzigen of op een schuifregelaar klikken past die waarde toe op alle geselecteerde beeldschermen.

### BEDIENING

Start FlightCorridor.exe. Instellingen worden doorlopend opgeslagen en er draait slechts één exemplaar van de toepassing. Het selectievakje of een dubbelklik op de beeldschermrij schakelt de animatie-uitvoer in of uit. U kunt de animatie pauzeren en hervatten. BMP/GIF/JPEG/PNG/TIFF/WebP en MP4 leggen het eerste actieve animatiebeeldscherm vast, niet een gecombineerd beeld van alle schermen. De animatie-uitvoer van het opgenomen beeldscherm kan tijdens de opname niet worden uitgeschakeld; afsluiten tijdens een opname vereist bevestiging. Pauzeren en het blokkeren van de schermbeveiliging gelden voor de hele toepassing, ongeacht de beeldschermselectie. Als blokkering is ingeschakeld, wordt de Windows-schermbeveiliging alleen tegengehouden zolang op minstens één beeldscherm een zichtbare, niet-gepauzeerde animatie draait. De toepassing kan de ingebouwde schermbeveiliging installeren of verwijderen.

### SCHERMAFBEELDINGEN EN OPNAMEN

Kies Viewport of TV in de opname-instellingen. Viewport behoudt de afmetingen en vernieuwingsfrequentie van het beeldscherm tot 60 frames per seconde. TV biedt 1920 × 1080, 1440 × 1080 of 1280 × 720 met beeldverhouding 16:9 en 50, 25, 59.94 (60000/1001) of 29.97 (30000/1001) frames per seconde. TV gebruikt progressieve BT.709-video met beperkt bereik en 4:2:0-kleursubsampling. De beeldverhouding blijft behouden en opvulbalken zijn zwart. OK bewaart de opties voor de volgende opname; Annuleren of Esc verwerpt onbevestigde wijzigingen. Opname-instellingen, Help en Info blokkeren andere vensters niet en kunnen worden geminimaliseerd. Tab en Shift+Tab verplaatsen de focus, Enter activeert de knop met focus en Esc sluit het actieve hulpvenster.

### VOORBEELD EN BEDIENING

Gebruik FlightCorridor.scr als Windows-schermbeveiliging met eigen instellingen. Het schermvullende voorbeeld laat live aanpassingen toe. OK slaat wijzigingen op; Annuleren of Esc verwerpt ze. Sluit de schermvullende schermbeveiliging met een toets of een muisbeweging.

### Systeemvereisten

Windows 7–11 ondersteunt alle functies. Voor Windows Vista SP2 moet u updates KB971512 en KB2117917 installeren; MP4-opname werkt niet op Vista. Direct3D 11-ondersteuning is vereist; voor MP4 zijn ook Media Foundation en een H.264-encoder nodig. Interface en documentatie zijn beschikbaar in 36 talen. De zelfstandige toepassing kan ook op Linux draaien via Wine; integratie als schermbeveiliging is alleen beschikbaar op Windows.

## Bouwen en verpakken

Open DispSavers.slnx in Visual Studio en bouw Release | x86 met MSVC v145 en een Windows SDK. Stel het certificaat en de verplichte RFC 3161-tijdstempelserver in op de projectpagina Signing; persoonlijke waarden blijven in het genegeerde .vcxproj.user-bestand. De ondertekende SCR met tijdstempel wordt in de EXE opgenomen, waarna ook de EXE wordt ondertekend. PackageRelease.ps1 maakt één `DispSavers-<version>-win32.zip` voor alle vier schermbeveiligingen zonder de binaire bestanden in Release te wijzigen.

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

## Licentie

[MIT](../license.txt) — Copyright © Petr Červinka — FortSoft 2026
