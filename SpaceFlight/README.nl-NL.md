# SpaceFlight

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · **Nederlands** · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

Hardwareversnelde vlucht boven een golvend oppervlak. Oneindig golvend oppervlak; Langeafstandsvlucht — veranderend oppervlak. Kies precies één animatie per beeldscherm. Textuur schakelt tussen een getextureerd oppervlak en een draadmodel. Vrije camerarotatie verandert de kijkrichting langzaam in alle drie dimensies. De optie Pauzes en omkeren voegt willekeurige vertragingen, pauzes en omkeringen van de rotatie toe; de voorwaartse vlucht gaat door. De snelheid is instelbaar op 0–1600%. Elk beeldscherm heeft een onafhankelijke willekeurige scène en wordt op zijn eigen vernieuwingsfrequentie aangestuurd. Hoofdlicht, invullicht, omgevingslicht en randlicht kunnen onafhankelijk worden geschakeld voor de geselecteerde beeldschermen. De verlichting geldt alleen voor oppervlakken met textuur. Beide animaties bieden Vlak, Golven of Trechter. De trechter trekt de camera langs een dalende spiraal naar binnen.

## Bediening

Selecteer één of meer beeldschermrijen in de lijst. Ctrl+A selecteert alles; met Ctrl en Shift past u de selectie aan. Animatieknoppen en schuifregelaars wijzigen alleen de instellingen van de geselecteerde beeldschermen. Een rij selecteren is iets anders dan de animatie-uitvoer inschakelen met het selectievakje. De selectie wordt apart onthouden voor de toepassing en de schermbeveiliging. Als alle beeldschermen waren geselecteerd, worden nieuw aangesloten beeldschermen ook geselecteerd. Verschillende waarden op geselecteerde beeldschermen worden aangegeven door selectievakjes in onbepaalde toestand en een stippelpatroon op keuzerondjes, schuifknoppen en de knoppen ‘Alles inschakelen’ en ‘Alles uitschakelen’. De labels van schuifregelaars tonen een streepje in plaats van een gemeenschappelijke waarde. Een optie wijzigen of op een schuifregelaar klikken past die waarde toe op alle geselecteerde beeldschermen.

## Toepassing

Start SpaceFlight.exe. Instellingen worden doorlopend opgeslagen en er draait slechts één exemplaar van de toepassing. Het selectievakje of een dubbelklik op de beeldschermrij schakelt de animatie-uitvoer in of uit. U kunt de animatie pauzeren en hervatten. PNG en MP4 leggen het eerste actieve animatiebeeldscherm vast, niet een gecombineerd beeld van alle schermen. De animatie-uitvoer van het opgenomen beeldscherm kan tijdens de opname niet worden uitgeschakeld; afsluiten tijdens een opname vereist bevestiging. Pauzeren en het blokkeren van de schermbeveiliging gelden voor de hele toepassing, ongeacht de beeldschermselectie. Als blokkering is ingeschakeld, wordt de Windows-schermbeveiliging alleen tegengehouden zolang op minstens één beeldscherm een zichtbare, niet-gepauzeerde animatie draait. De toepassing kan de ingebouwde schermbeveiliging installeren of verwijderen.

Kies Viewport of TV in de opname-instellingen. Viewport behoudt de afmetingen en vernieuwingsfrequentie van het beeldscherm tot 60 frames per seconde. TV biedt 1920 × 1080, 1440 × 1080 of 1280 × 720 met beeldverhouding 16:9 en 50, 25, 59.94 (60000/1001) of 29.97 (30000/1001) frames per seconde. TV gebruikt progressieve BT.709-video met beperkt bereik en 4:2:0-kleursubsampling. De beeldverhouding blijft behouden en opvulbalken zijn zwart. OK bewaart de opties voor de volgende opname; Annuleren of Esc verwerpt onbevestigde wijzigingen. Opname-instellingen, Help en Info blokkeren andere vensters niet en kunnen worden geminimaliseerd. Tab en Shift+Tab verplaatsen de focus, Enter activeert de knop met focus en Esc sluit het actieve hulpvenster.

## Schermbeveiliging

Gebruik SpaceFlight.scr als Windows-schermbeveiliging met eigen instellingen. Het schermvullende voorbeeld laat live aanpassingen toe. OK slaat wijzigingen op; Annuleren of Esc verwerpt ze. Sluit de schermvullende schermbeveiliging met een toets of een muisbeweging.

## Systeemvereisten

Windows 7–11 ondersteunt alle functies. Voor Windows Vista SP2 moet u updates KB971512 en KB2117917 installeren; MP4-opname werkt niet op Vista. Direct3D 11-ondersteuning is vereist; voor MP4 zijn ook Media Foundation en een H.264-encoder nodig. Interface en documentatie zijn beschikbaar in 36 talen. De zelfstandige toepassing kan ook op Linux draaien via Wine; integratie als schermbeveiliging is alleen beschikbaar op Windows.

## Bouwen en verpakken

Open DispSavers.slnx in Visual Studio en bouw Release | x86 met MSVC v145 en een Windows SDK. Stel het certificaat en de verplichte RFC 3161-tijdstempelserver in op de projectpagina Signing; persoonlijke waarden blijven in het genegeerde .vcxproj.user-bestand. De ondertekende SCR met tijdstempel wordt in de EXE opgenomen, waarna ook de EXE wordt ondertekend. PackageRelease.ps1 maakt één `DispSavers-<version>-win32.zip` voor alle drie schermbeveiligingen zonder de binaire bestanden in Release te wijzigen.

## Licentie

[MIT](license.txt) — Copyright © Petr Červinka — FortSoft 2026
