# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · **Norsk (bokmål)** · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlyingSolids er et Win32/x86 Direct3D-program og en Windows-skjermsparer som viser belyste, solide tredimensjonale geometriske legemer. Legemene beveger seg og roterer uavhengig og kolliderer uten å trenge gjennom hverandre.

Markeringen av rader bestemmer hvilke skjermer du redigerer, og er atskilt fra avkrysningsboksene som aktiverer animasjonsutgangen. Ctrl+A markerer alle skjermer; Ctrl og Skift endrer markeringen. Alle animasjonsvalg og glidebrytere gjelder de markerte skjermene. Markeringen huskes separat for EXE og SCR. Hvis alle skjermer var markert, inkluderes også nye skjermer. Ulike verdier på de markerte skjermene vises med ubestemte avkrysningsbokser og prikkmønster på alternativknapper, glidebryterhåndtak og knappene «Slå på alle» og «Slå av alle». Glidebryteretiketter viser en tankestrek i stedet for en felles verdi. Endring av et valg eller klikk på en glidebryter bruker denne verdien på alle markerte skjermer.

## Funksjoner

- **Romobservasjon** og rett **Flyging gjennom rommet**. Velg én eller flere skjermer i listen. Kameramodus, objekter, belysning, hastigheter, størrelse og antall kopier gjelder bare de valgte skjermene. Hver skjerm husker sine egne innstillinger.
- Uavhengig styring av hovedlys, utfyllingslys, omgivelseslys og konturlys
- Uavhengig scene på hver skjerm
- Én til ti kopier av hvert aktivert legeme
- Objekt- og kamerahastighet 0–1600 %, størrelse 50–200 %
- Blank belysning, egne farger og kollisjonsbehandling
- Gjengivelse tilpasset oppdateringsfrekvensen til hver skjerm
- PNG-skjermbilder og MP4-opptak i det selvstendige programmet
- Separate innstillinger for programmet og skjermspareren
- 30 typer legemer og grensesnitt på 36 språk

## Geometriske legemer

Kube; Regelmessig firkantet pyramide; Avkortet firkantet pyramide; Firkantet pyramide skåret med skråplan; Firkantpyramide, snitt normalt på basen; Regelmessig trekantprisme; Regelmessig femkantprisme; Regelmessig sekskantprisme; Regelmessig oktaeder; Femkantet bipyramide; Rett sirkelkjegle; Avkortet kjegle; Kjegle skåret med skråplan; Kjegle med snitt normalt på grunnflaten; Rett sirkelsylinder; Hul sylinder; Hul sylinder med toroidale ender; Rotasjonsparaboloide lukket av et plan; Kule; Halvkule; Kulesegment; Stort kulesegment; Kulelag; Treakset ellipsoide; Prolat sfæroide; Flattrykt sfæroide; Ovoide; Sfærosylinder; Avrundet skive (spheroplatelet); Torus.

## Belysning

Avmerkingsboksene `Hovedlys`, `Utfyllingslys`, `Omgivelseslys` og `Konturlys` under glidebryterne styrer belysningen på de valgte skjermene uavhengig av hverandre. Omgivelseslys gir grunnbelysning på overflatene, og konturlys fremhever kantene. Innstillingene lagres separat for programmet og skjermspareren.

## Program og skjermsparer

`FlyingSolids.exe` beholder ett kontrollvindu mens animasjonen kjører. Slå animasjonsutgangene av eller på med skjermenes avkrysningsbokser eller ved å dobbeltklikke på radene deres. EXE-filen kan installere og avinstallere den innebygde skjermspareren. Bare én instans av programmet kan kjøre om gangen. En ny start gjenoppretter det minimerte kontrollvinduet og bringer det fremst. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc lukker det aktive Hjelp- eller Om-vinduet; i kontrollvinduet avslutter det programmet. Skjermbilder og opptak bruker den første aktive animasjonsskjermen, ikke et samlet bilde av alle skjermene. PNG bruker Bilder, MP4 Videoer; hvis disse mappene ikke finnes, brukes Dokumenter. Knappen Opptaksinnstillinger velger Viewport eller TV. Viewport beholder animasjonsskjermens størrelse og oppdateringsfrekvens, opptil 60 bilder per sekund. TV tilbyr 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9, med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) bilder per sekund. Bildets proporsjoner beholdes; TV bruker progressiv BT.709-video med begrenset område og 4:2:0-sampling. Oppløsning og bildefrekvens er bare tilgjengelige i TV-modus. Vinduet Opptaksinnstillinger kan minimeres og blokkerer ikke de andre programvinduene. OK lagrer valgene for neste MP4-opptak; Avbryt eller Esc forkaster ubekreftede endringer. Animasjonsutgangen på skjermen som tas opp, kan ikke slås av under opptaket; endringer på andre skjermer stopper ikke opptaket. Å avslutte programmet under et opptak krever bekreftelse, fordi det også avslutter opptaket. Pause og blokkering av skjermspareren gjelder hele programmet uavhengig av skjermmarkeringen. Når blokkering er slått på, hindres Windows-skjermspareren bare mens en synlig animasjon som ikke er satt på pause, vises på minst én skjerm. `FlyingSolids.scr` har egne innstillinger uten opptak. Fullskjerm kjører en uavhengig scene på hver skjerm. Slå på forhåndsvisning i innstillingene starter en egen fullskjermsvisning på alle skjermer. Den bruker gjeldende innstillinger, tillater endringer underveis og kan stoppes igjen. En hvilken som helst tast, musebevegelse eller et museklikk avslutter skjermspareren i fullskjerm. Esc i innstillingene tilsvarer Avbryt; i Hjelp eller Om lukker det bare dette vinduet.

## Innstillinger

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Systemkrav

Windows 7 til Windows 11 støtter alle funksjoner, inkludert PNG-skjermbilder og MP4-opptak. For å kjøre programmet på Windows Vista SP2 må oppdateringene KB971512 og KB2117917 installeres. MP4-opptak fungerer ikke på Vista i den gjeldende versjonen. Visningen krever Direct3D 11, ikke bare en eldre DirectX-kjøretid. MP4-opptak krever tilgjengelige Media Foundation-komponenter og en H.264-koder. Det frittstående programmet kan også kjøre på Linux via Wine; integrasjon som skjermsparer er bare tilgjengelig på Windows.

## Bygging

Åpne `DispSavers.slnx` i Visual Studio med MSVC v145 og Windows SDK. Velg `Release | x86` og bygg løsningen på nytt for å lage `Release\FlyingSolids.exe` og `Release\FlyingSolids.scr`. Det finnes ingen x64-konfigurasjon. På siden `Signing` i egenskapene til prosjektet `FlyingSolids` angir du navnet eller fingeravtrykket til et gyldig kodesigneringssertifikat med privat nøkkel i den gjeldende brukerens `Personal (My)`-lager. Innstillingene gjelder både EXE og SCR og lagres i `FlyingSolids.vcxproj.user`, som ignoreres av Git. SignTool finnes automatisk i PATH eller Windows SDK. Hvis du bruker SimplySign, logger du på SimplySign Desktop før byggingen. Først signeres SCR og får et obligatorisk RFC 3161 SHA-256-tidsstempel fra den konfigurerte tidsstempelserveren; deretter bygges det inn i EXE, som også signeres og tidsstemples. Angi URL-en til RFC 3161-tidsstempelserveren i feltet `Timestamp server`. Feil ved signering, tidsstempling eller kontroll stopper byggingen; filer med gyldige tidsstemplede signaturer signeres ikke på nytt.

Pakk disse byggeutdataene ved å kjøre `PackageRelease.ps1` uten signeringsparametere. Skriptet bruker midlertidige kopier, endrer ikke filer i `Release` og kontrollerer bare eksisterende gyldige signaturer. Det oppretter ett arkiv, `DispSavers-<version>-win32.zip`, med `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` og `SpaceFlight\license.txt`. Den forrige ZIP-filen fjernes ved starten av kjøringen; en kontrollfeil hindrer opprettelse av et nytt arkiv.

## Lisens

FlyingSolids er tilgjengelig under [MIT-lisensen](../license.txt). Copyright © Petr Červinka — FortSoft 2026

## FlightCorridor

FlightCorridor tilbyr Flytur mellom fire formendrende flater og Flytur gjennom en formendrende trakt. Tilordne nøyaktig én flytur til hver skjerm: velg raden og den tilsvarende alternativknappen.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](../FlightCorridor/README.nb-NO.md)

## SpaceFlight

SpaceFlight: Uendelig bølgende flate; Langdistanseflytur — formendrende flate; Flytur gjennom gravitasjonskrummet rom. Tilordne nøyaktig én flytur til hver skjerm: velg raden og den tilsvarende alternativknappen.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](../SpaceFlight/README.nb-NO.md)
