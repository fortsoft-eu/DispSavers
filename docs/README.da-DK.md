# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · **Dansk** · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlyingSolids er et Win32/x86 Direct3D-program og en Windows-pauseskærm, som viser belyste, solide tredimensionale geometriske legemer. Legemerne bevæger sig og roterer uafhængigt og kolliderer uden at trænge gennem hinanden.

Markeringen af rækker bestemmer, hvilke skærme du indstiller, og er adskilt fra afkrydsningsfelterne, der aktiverer animationsoutput. Ctrl+A markerer alle skærme; Ctrl og Skift ændrer markeringen. Alle animationsvalg og skydere gælder de markerede skærme. Markeringen huskes separat for EXE og SCR. Hvis alle skærme var markeret, medtages også nye skærme. Forskellige værdier på de markerede skærme vises med ubestemte afkrydsningsfelter og prikmønstre på alternativknapper, skydergreb og knapperne “Aktivér alle” og “Deaktivér alle”. Skydernes etiketter viser en tankestreg i stedet for en fælles værdi. Ændring af et valg eller klik på en skyder anvender denne værdi på alle markerede skærme.

## Funktioner

- **Rumobservation** og lige **Flyvning gennem rummet**. Vælg en eller flere skærme på listen. Kameratilstand, objekter, belysning, hastigheder, størrelse og antal kopier gælder kun de valgte skærme. Hver skærm husker sine egne indstillinger.
- Uafhængig styring af hovedlys, udfyldningslys, omgivende lys og konturlys
- Uafhængig scene på hver skærm
- En til ti kopier af hvert aktiveret legeme
- Objekt- og kamerahastighed 0–1600 %, størrelse 50–200 %
- Blank belysning, egne farver og kollisionsbehandling
- Gengivelse tilpasset hver skærms opdateringsfrekvens
- PNG-skærmbilleder og MP4-optagelse i det selvstændige program
- Separate indstillinger for program og pauseskærm
- 30 typer legemer og brugerflade på 36 sprog

## Geometriske legemer

Terning; Regulær firsidet pyramide; Afkortet firsidet pyramide; Firsidet pyramide skåret med et skråt plan; Firkantpyramide, snit vinkelret på basen; Regulært trekantet prisme; Regulært femkantet prisme; Regulært sekskantet prisme; Regulært oktaeder; Femkantet bipyramide; Ret cirkulær kegle; Afkortet kegle; Kegle skåret med et skråt plan; Kegle med snit vinkelret på grundfladen; Ret cirkulær cylinder; Hul cylinder; Hul cylinder med toroidale ender; Rotationsparaboloide lukket af et plan; Kugle; Halvkugle; Kuglesegment; Stort kuglesegment; Kuglelag; Treakset ellipsoide; Prolat sfæroide; Fladtrykt sfæroide; Ovoide; Sfærocylinder; Afrundet skive (spheroplatelet); Torus.

## Belysning

Afkrydsningsfelterne `Hovedlys`, `Udfyldningslys`, `Omgivende lys` og `Konturlys` under skyderne styrer belysningen på de valgte skærme uafhængigt af hinanden. Omgivende lys giver overfladerne en grundbelysning, og konturlys fremhæver kanterne. Indstillingerne gemmes separat for programmet og pauseskærmen.

## Program og pauseskærm

`FlyingSolids.exe` beholder ét kontrolvindue under animationen. Slå animationsoutput til eller fra med skærmenes afkrydsningsfelter eller ved at dobbeltklikke på deres rækker. EXE-filen kan installere og afinstallere den indbyggede pauseskærm. Programmet kan kun køre i én instans ad gangen. En ny start gendanner det minimerede kontrolvindue og bringer det forrest. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det understregede bogstav aktiverer en kommando. Esc lukker det aktive Hjælp- eller Om-vindue; i kontrolvinduet afslutter det programmet. Skærmbilleder og optagelser bruger den første aktive animationsskærm, ikke et samlet billede af alle skærme. PNG bruger Billeder, MP4 Videoer; hvis disse mapper ikke findes, bruges Dokumenter. Knappen Optagelsesindstillinger vælger Viewport eller TV. Viewport bevarer animationsskærmens størrelse og opdateringsfrekvens, højst 60 billeder i sekundet. TV tilbyder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9 med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) billeder i sekundet. Billedets proportioner bevares; TV bruger progressiv BT.709-video med begrænset område og 4:2:0-sampling. Opløsning og billedfrekvens kan kun vælges i TV-tilstand. Vinduet Optagelsesindstillinger kan minimeres og blokerer ikke de andre programvinduer. OK gemmer valgene til den næste MP4-optagelse; Annuller eller Esc kasserer ubekræftede ændringer. Animationsoutputtet på den skærm, der optages, kan ikke slås fra under optagelsen; ændringer af andre skærme stopper ikke optagelsen. Hvis programmet lukkes under en optagelse, kræves en bekræftelse, fordi optagelsen også afsluttes. Pause og blokering af pauseskærmen gælder hele programmet uanset skærmmarkeringen. Når blokering er slået til, forhindres Windows-pauseskærmen kun, mens der vises en synlig animation, som ikke er sat på pause, på mindst én skærm. `FlyingSolids.scr` har egne indstillinger uden optagelse. Fuldskærm kører en uafhængig scene på hver skærm. Aktivér forhåndsvisning i indstillingerne starter en separat fuldskærmsvisning på alle skærme. Den bruger de aktuelle indstillinger, tillader ændringer under visningen og kan stoppes igen. En vilkårlig tast, en musebevægelse eller et museklik afslutter pauseskærmen i fuld skærm. Esc i indstillingerne svarer til Annuller; i Hjælp eller Om lukker det kun dette vindue.

## Indstillinger

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Systemkrav

Windows 7 til Windows 11 understøtter alle funktioner, herunder PNG-skærmbilleder og MP4-optagelse. For at køre programmet på Windows Vista SP2 skal opdateringerne KB971512 og KB2117917 installeres. MP4-optagelse fungerer ikke på Vista i den aktuelle version. Visningen kræver Direct3D 11, ikke kun et ældre DirectX-kørselsmiljø. MP4-optagelse kræver tilgængelige Media Foundation-komponenter og en H.264-koder. Det selvstændige program kan også køre på Linux via Wine; integration som pauseskærm er kun tilgængelig på Windows.

## Kompilering

Åbn `DispSavers.slnx` i Visual Studio med MSVC v145 og Windows SDK. Vælg `Release | x86`, og genopbyg løsningen for at oprette `Release\FlyingSolids.exe` og `Release\FlyingSolids.scr`. Der findes ingen x64-konfiguration. Angiv navnet eller fingeraftrykket for et gyldigt certifikat til kodesignering med en privat nøgle i den aktuelle brugers `Personal (My)`-lager på siden `Signing` i egenskaberne for projektet `FlyingSolids`. Indstillingerne gælder EXE og SCR og gemmes i `FlyingSolids.vcxproj.user`, som Git ignorerer. SignTool findes automatisk i PATH eller Windows SDK. Hvis du bruger SimplySign, skal du logge på SimplySign Desktop før bygget. Først signeres SCR og får et obligatorisk RFC 3161 SHA-256-tidsstempel fra den konfigurerede tidsstempelserver; derefter indlejres det i EXE, som også signeres og tidsstemples. Angiv URL-adressen til RFC 3161-tidsstempelserveren i feltet `Timestamp server`. Fejl ved signering, tidsstempling eller kontrol stopper bygget; filer med gyldige tidsstemplede signaturer signeres ikke igen.

Pak disse byggeoutput ved at køre `PackageRelease.ps1` uden signeringsparametre. Scriptet bruger midlertidige kopier, ændrer ikke filer i `Release` og kontrollerer kun eksisterende gyldige signaturer. Det opretter ét arkiv, `DispSavers-<version>-win32.zip`, med `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` og `SpaceFlight\license.txt`. Den tidligere ZIP-fil fjernes ved starten af kørslen; en kontrolfejl forhindrer oprettelsen af et nyt arkiv.

## Licens

FlyingSolids udgives under [MIT-licensen](../license.txt). Copyright © Petr Červinka — FortSoft 2026

## FlightCorridor

FlightCorridor tilbyder Flyvetur mellem fire formskiftende flader og Flyvetur gennem en formskiftende tragt. Tildel præcis én flyvetur til hver skærm: vælg dens række og den tilsvarende alternativknap.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](../FlightCorridor/README.da-DK.md)

## SpaceFlight

SpaceFlight tilbyder »Uendelig bølgende flade« og »Langdistanceflyvetur — formskiftende flade«. Tildel præcis én flyvetur til hver skærm: vælg dens række og den tilsvarende alternativknap.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](../SpaceFlight/README.da-DK.md)
