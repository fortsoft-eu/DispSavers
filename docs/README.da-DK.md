# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · **Dansk** · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids er et integreret Win32/x86 Direct3D-program og en Windows-pauseskærm, som viser belyste, solide tredimensionale geometriske legemer. Legemerne bevæger og roterer sig uafhængigt og kolliderer uden at trænge gennem hinanden. Starttilstande og nye flyvepositioner kommer fra Windows’ kryptografiske generator og bufferlagres for lav CPU-belastning.

## Funktioner

- **Rumobservation** og lige **Flyvning gennem rummet**
- Hovedlys og udfyldningslys kan slås til og fra uafhængigt af hinanden
- Uafhængig scene på hver valgt skærm
- En til ti kopier af hvert aktiveret legeme
- Objekt- og kamerahastighed 0–1600 %, størrelse 50–200 %
- Blank belysning, egne farver og kollisionsbehandling
- Gengivelse tilpasset hver skærms opdateringsfrekvens
- PNG-skærmbilleder og MP4-optagelse i det selvstændige program
- Separate indstillinger for program og pauseskærm
- 27 typer legemer og brugerflade på 17 sprog

## Geometriske legemer

Udvalget omfatter polyedre, regulære prismer, pyramider og plansnit, kegler og cylindre og deres plansnit, en rotationsparaboloide lukket af et plan, kugleafledte legemer, ellipsoider, ovoide, sfærocylinder og torus. Brugerfladen anvender etablerede danske geometriske fagudtryk.

## Belysning

Afkrydsningsfelterne `Hovedlys` og `Udfyldningslys` under skyderne til højre slår de to lys til eller fra uafhængigt af hinanden for hele scenen. Som standard er `Hovedlys` slået til og `Udfyldningslys` slået fra. Lysindstillingerne gemmes separat for programmet og pauseskærmen.

## Program og pauseskærm

`FlyingSolids.exe` beholder ét kontrolvindue under animationen. Flere skærme kan vælges, en række skiftes med dobbeltklik, og alle kan frakobles. PNG gemmes normalt i **Billeder**, MP4 i **Videoer**, med **Dokumenter** som reserve. EXE-filen kan installere og afinstallere den indbyggede pauseskærm.

Programmet kan kun køre i én instans ad gangen. En ny start gendanner det minimerede kontrolvindue, tegner det igen og bringer det forrest.

Brug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det understregede bogstav aktiverer en kommando. Esc lukker det aktive Hjælp- eller Om-vindue; i kontrolvinduet afslutter det programmet.

Skærmbilleder og optagelser bruger den første aktive animationsskærm, ikke et samlet billede af alle skærme. PNG bruger Billeder, MP4 Videoer; hvis disse mapper ikke findes, bruges Dokumenter. MP4-optagelse følger skærmens opdateringsfrekvens, dog højst 60 billeder i sekundet.

`FlyingSolids.scr` har egne indstillinger uden optagelse. Fuldskærm kører en uafhængig scene på hver skærm.

Aktivér forhåndsvisning i indstillingerne starter en separat fuldskærmsvisning på alle skærme. Den bruger de aktuelle indstillinger, tillader ændringer under visningen og kan stoppes igen. En vilkårlig tast, en musebevægelse eller et museklik afslutter pauseskærmen i fuld skærm.

Esc i indstillingerne svarer til Annuller; i Hjælp eller Om lukker det kun dette vindue.

## Indstillinger

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Systemkrav

Windows 7 til Windows 11 understøtter alle funktioner, herunder PNG-skærmbilleder og MP4-optagelse.

Windows Vista SP2: KB971512, KB2117917. MP4-optagelse fungerer ikke på Vista i den aktuelle version.

Visningen kræver Direct3D 11, ikke kun en ældre DirectX-kørselsmiljø. MP4-optagelse kræver tilgængelige Media Foundation-komponenter og en H.264-koder.

## Kompilering

Åbn `DispSavers.slnx`, vælg `Release | x86`, og genopbyg løsningen med MSVC v145 og Windows SDK. EXE og SCR oprettes sammen. `PackageRelease.ps1` opretter den fælles `DispSavers-<version>-win32.zip`, hvor filerne og `license.txt` ligger i undermappen `FlyingSolids`. Der findes ingen x64-konfiguration.

## Licens

FlyingSolids udgives under [MIT-licensen](../license.txt).

Copyright © Petr Červinka — FortSoft 2026
