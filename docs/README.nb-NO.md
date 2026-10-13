# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · **Norsk** · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids er et integrert Win32/x86 Direct3D-program og en Windows-skjermsparer som viser belyste, solide tredimensjonale geometriske legemer. Legemene beveger og roterer seg uavhengig og kolliderer uten å trenge gjennom hverandre.

## Funksjoner

- **Romobservasjon** og rett **Flyging gjennom rommet**
- Uavhengig styring av hovedlys, utfyllingslys, omgivelseslys og konturlys
- Uavhengig scene på hver valgt skjerm
- Én til ti kopier av hvert aktivert legeme
- Objekt- og kamerahastighet 0–1600 %, størrelse 50–200 %
- Blank belysning, egne farger og kollisjonsbehandling
- Gjengivelse tilpasset oppdateringsfrekvensen til hver skjerm
- PNG-skjermbilder og MP4-opptak i det selvstendige programmet
- Separate innstillinger for programmet og skjermspareren
- 30 typer legemer og grensesnitt på 17 språk

## Geometriske legemer

Utvalget omfatter polyedre, regelmessige prismer, pyramider og plansnitt, kjegler og sylindre og deres plansnitt, en rotasjonsparaboloide lukket av et plan, kuleavledede legemer, ellipsoider, ovoide, sfærosylinder og torus. Grensesnittet bruker etablerte norske fagtermer.

## Belysning

Avmerkingsboksene `Hovedlys`, `Utfyllingslys`, `Omgivelseslys` og `Konturlys` under glidebryterne styrer belysningen i hele scenen uavhengig av hverandre. Omgivelseslys gir grunnbelysning på overflatene, og konturlys fremhever kantene. Som standard er hovedlys, omgivelseslys og konturlys på, og utfyllingslys av. Innstillingene lagres separat for programmet og skjermspareren.

## Program og skjermsparer

`FlyingSolids.exe` beholder ett kontrollvindu mens animasjonen kjører. Flere skjermer kan velges, en rad kan slås av eller på med dobbeltklikk, og alle kan kobles fra. EXE-filen kan installere og avinstallere den innebygde skjermspareren. Bare én instans av programmet kan kjøre om gangen. En ny start gjenoppretter det minimerte kontrollvinduet og bringer det fremst. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc lukker det aktive Hjelp- eller Om-vinduet; i kontrollvinduet avslutter det programmet. Skjermbilder og opptak bruker den første aktive animasjonsskjermen, ikke et samlet bilde av alle skjermene. PNG bruker Bilder, MP4 Videoer; hvis disse mappene ikke finnes, brukes Dokumenter. Knappen Opptaksinnstillinger velger Viewport eller TV. Viewport beholder animasjonsskjermens størrelse og oppdateringsfrekvens, opptil 60 bilder per sekund. TV tilbyr 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9, med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) bilder per sekund. Bildets proporsjoner beholdes; TV bruker progressiv BT.709-video med begrenset område og 4:2:0-sampling. Oppløsning og bildefrekvens er bare tilgjengelige i TV-modus. Vinduet Opptaksinnstillinger kan minimeres og blokkerer ikke de andre programvinduene. OK lagrer valgene for neste MP4-opptak; Avbryt eller Esc forkaster ubekreftede endringer. Skjermen som tas opp, kan ikke velges bort under opptaket; endringer på andre skjermer stopper ikke opptaket. Å avslutte programmet under et opptak krever bekreftelse, fordi det også avslutter opptaket. Hindre skjermsparer under animasjon hindrer Windows-skjermspareren i å starte bare når animasjonen faktisk er synlig og ikke er satt på pause. `FlyingSolids.scr` har egne innstillinger uten opptak. Fullskjerm kjører en uavhengig scene på hver skjerm. Slå på forhåndsvisning i innstillingene starter en egen fullskjermsvisning på alle skjermer. Den bruker gjeldende innstillinger, tillater endringer underveis og kan stoppes igjen. En hvilken som helst tast, musebevegelse eller et museklikk avslutter skjermspareren i fullskjerm. Esc i innstillingene tilsvarer Avbryt; i Hjelp eller Om lukker det bare dette vinduet.

## Innstillinger

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Systemkrav

Windows 7 til Windows 11 støtter alle funksjoner, inkludert PNG-skjermbilder og MP4-opptak. For å kjøre programmet på Windows Vista SP2 må oppdateringene KB971512 og KB2117917 installeres. MP4-opptak fungerer ikke på Vista i den gjeldende versjonen. Visningen krever Direct3D 11, ikke bare en eldre DirectX-kjøretid. MP4-opptak krever tilgjengelige Media Foundation-komponenter og en H.264-koder.

## Bygging

Åpne `DispSavers.slnx` i Visual Studio med MSVC v145 og Windows SDK. Velg `Release | x86` og bygg løsningen på nytt for å lage `Release\FlyingSolids.exe` og `Release\FlyingSolids.scr`. Det finnes ingen x64-konfigurasjon. Signering er som standard aktivert for både Release og Debug. På siden `Signing` i egenskapene til prosjektet `FlyingSolids` angir du navnet eller fingeravtrykket til et gyldig kodesigneringssertifikat med privat nøkkel i den gjeldende brukerens `Personal (My)`-lager. Innstillingene gjelder både EXE og SCR og lagres i `FlyingSolids.vcxproj.user`, som ignoreres av Git. SignTool finnes automatisk i PATH eller Windows SDK. Hvis du bruker SimplySign, logger du på SimplySign Desktop før byggingen. Først signeres SCR og får et obligatorisk RFC 3161 SHA-256-tidsstempel fra den konfigurerte tidsstempelserveren; deretter bygges det inn i EXE, som også signeres og tidsstemples. Angi URL-en til RFC 3161-tidsstempelserveren i feltet `Timestamp server`. Feil ved signering, tidsstempling eller kontroll stopper byggingen; filer med gyldige tidsstemplede signaturer signeres ikke på nytt.

Pakk disse byggeutdataene ved å kjøre `PackageRelease.ps1` uten signeringsparametere. Skriptet bruker midlertidige kopier, endrer ikke filer i `Release` og kontrollerer bare eksisterende gyldige signaturer. Det oppretter ett arkiv, `DispSavers-<version>-win32.zip`, med `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr` og `FlyingSolids\license.txt`. Den forrige ZIP-filen fjernes ved starten av kjøringen; en kontrollfeil hindrer opprettelse av et nytt arkiv.

## Lisens

FlyingSolids er tilgjengelig under [MIT-lisensen](../license.txt). Copyright © Petr Červinka — FortSoft 2026
