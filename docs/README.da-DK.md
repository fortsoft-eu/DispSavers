# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · **Dansk** · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids er et integreret Win32/x86 Direct3D-program og en Windows-pauseskærm, som viser belyste, solide tredimensionale geometriske legemer. Legemerne bevæger og roterer sig uafhængigt og kolliderer uden at trænge gennem hinanden.

## Funktioner

- **Rumobservation** og lige **Flyvning gennem rummet**. Vælg en eller flere skærme på listen. Kameratilstand, objekter, belysning, hastigheder, størrelse og antal kopier gælder kun de valgte skærme. Hver skærm husker sine egne indstillinger.
- Uafhængig styring af hovedlys, udfyldningslys, omgivende lys og konturlys
- Uafhængig scene på hver valgt skærm
- En til ti kopier af hvert aktiveret legeme
- Objekt- og kamerahastighed 0–1600 %, størrelse 50–200 %
- Blank belysning, egne farver og kollisionsbehandling
- Gengivelse tilpasset hver skærms opdateringsfrekvens
- PNG-skærmbilleder og MP4-optagelse i det selvstændige program
- Separate indstillinger for program og pauseskærm
- 30 typer legemer og brugerflade på 17 sprog

## Geometriske legemer

Udvalget omfatter polyedre, regulære prismer, pyramider og plansnit, kegler og cylindre og deres plansnit, en rotationsparaboloide lukket af et plan, kugleafledte legemer, ellipsoider, ovoide, sfærocylinder og torus. Brugerfladen anvender etablerede danske geometriske fagudtryk.

## Belysning

Afkrydsningsfelterne `Hovedlys`, `Udfyldningslys`, `Omgivende lys` og `Konturlys` under skyderne styrer belysningen af hele scenen uafhængigt af hinanden. Omgivende lys giver overfladerne en grundbelysning, og konturlys fremhæver kanterne. Som standard er hovedlys, omgivende lys og konturlys slået til og udfyldningslys slået fra. Indstillingerne gemmes separat for programmet og pauseskærmen.

## Program og pauseskærm

`FlyingSolids.exe` beholder ét kontrolvindue under animationen. Flere skærme kan vælges, en række skiftes med dobbeltklik, og alle kan frakobles. EXE-filen kan installere og afinstallere den indbyggede pauseskærm. Programmet kan kun køre i én instans ad gangen. En ny start gendanner det minimerede kontrolvindue og bringer det forrest. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det understregede bogstav aktiverer en kommando. Esc lukker det aktive Hjælp- eller Om-vindue; i kontrolvinduet afslutter det programmet. Skærmbilleder og optagelser bruger den første aktive animationsskærm, ikke et samlet billede af alle skærme. PNG bruger Billeder, MP4 Videoer; hvis disse mapper ikke findes, bruges Dokumenter. Knappen Optagelsesindstillinger vælger Viewport eller TV. Viewport bevarer animationsskærmens størrelse og opdateringsfrekvens, højst 60 billeder i sekundet. TV tilbyder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9 med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) billeder i sekundet. Billedets proportioner bevares; TV bruger progressiv BT.709-video med begrænset område og 4:2:0-sampling. Opløsning og billedfrekvens kan kun vælges i TV-tilstand. Vinduet Optagelsesindstillinger kan minimeres og blokerer ikke de andre programvinduer. OK gemmer valgene til den næste MP4-optagelse; Annuller eller Esc kasserer ubekræftede ændringer. Den skærm, der optages, kan ikke fravælges under optagelsen; ændringer af andre skærme stopper ikke optagelsen. Hvis programmet lukkes under en optagelse, kræves en bekræftelse, fordi optagelsen også afsluttes. Blokér pauseskærm under animation forhindrer Windows-pauseskærmen i at starte, men kun når animationen faktisk er synlig og ikke er sat på pause. `FlyingSolids.scr` har egne indstillinger uden optagelse. Fuldskærm kører en uafhængig scene på hver skærm. Aktivér forhåndsvisning i indstillingerne starter en separat fuldskærmsvisning på alle skærme. Den bruger de aktuelle indstillinger, tillader ændringer under visningen og kan stoppes igen. En vilkårlig tast, en musebevægelse eller et museklik afslutter pauseskærmen i fuld skærm. Esc i indstillingerne svarer til Annuller; i Hjælp eller Om lukker det kun dette vindue.

## Indstillinger

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Systemkrav

Windows 7 til Windows 11 understøtter alle funktioner, herunder PNG-skærmbilleder og MP4-optagelse. For at køre programmet på Windows Vista SP2 skal opdateringerne KB971512 og KB2117917 installeres. MP4-optagelse fungerer ikke på Vista i den aktuelle version. Visningen kræver Direct3D 11, ikke kun en ældre DirectX-kørselsmiljø. MP4-optagelse kræver tilgængelige Media Foundation-komponenter og en H.264-koder.

## Kompilering

Åbn `DispSavers.slnx` i Visual Studio med MSVC v145 og Windows SDK. Vælg `Release | x86`, og genopbyg løsningen for at oprette `Release\FlyingSolids.exe` og `Release\FlyingSolids.scr`. Der findes ingen x64-konfiguration. Signering er som standard slået til for både Release og Debug. Angiv navnet eller fingeraftrykket for et gyldigt certifikat til kodesignering med en privat nøgle i den aktuelle brugers `Personal (My)`-lager på siden `Signing` i egenskaberne for projektet `FlyingSolids`. Indstillingerne gælder EXE og SCR og gemmes i `FlyingSolids.vcxproj.user`, som Git ignorerer. SignTool findes automatisk i PATH eller Windows SDK. Hvis du bruger SimplySign, skal du logge på SimplySign Desktop før bygget. Først signeres SCR og får et obligatorisk RFC 3161 SHA-256-tidsstempel fra den konfigurerede tidsstempelserver; derefter indlejres det i EXE, som også signeres og tidsstemples. Angiv URL-adressen til RFC 3161-tidsstempelserveren i feltet `Timestamp server`. Fejl ved signering, tidsstempling eller kontrol stopper bygget; filer med gyldige tidsstemplede signaturer signeres ikke igen.

Pak disse byggeoutput ved at køre `PackageRelease.ps1` uden signeringsparametre. Scriptet bruger midlertidige kopier, ændrer ikke filer i `Release` og kontrollerer kun eksisterende gyldige signaturer. Det opretter ét arkiv, `DispSavers-<version>-win32.zip`, med `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` og `SpaceFlight\license.txt`. Den tidligere ZIP-fil fjernes ved starten af kørslen; en kontrolfejl forhindrer oprettelsen af et nyt arkiv.

## Licens

FlyingSolids udgives under [MIT-licensen](../license.txt). Copyright © Petr Červinka — FortSoft 2026


## FlightCorridor

FlightCorridor tilbyder Flyvetur mellem fire formskiftende flader og Flyvetur gennem en formskiftende tragt. Tildel præcis én flyvetur til hver skærm: vælg dens række og den tilsvarende alternativknap. Den første animation er valgt på alle skærme som standard.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](../FlightCorridor/README.da-DK.md)

## SpaceFlight

SpaceFlight tilbyder „Uendelig bølgende flade“ og „Langdistanceflyvetur — formskiftende flade“. Tildel præcis én flyvetur til hver skærm: vælg dens række og den tilsvarende alternativknap. Den første animation er valgt på alle skærme som standard.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](../SpaceFlight/README.da-DK.md)
