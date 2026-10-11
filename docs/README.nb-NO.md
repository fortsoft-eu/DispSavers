# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · **Norsk** · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids er et integrert Win32/x86 Direct3D-program og en Windows-skjermsparer som viser belyste, solide tredimensjonale geometriske legemer. Legemene beveger og roterer seg uavhengig og kolliderer uten å trenge gjennom hverandre. Starttilstander og nye flyposisjoner kommer fra Windows’ kryptografiske generator og bufres for lav CPU-belastning.

## Funksjoner

- **Romobservasjon** og rett **Flyging gjennom rommet**
- Hovedlys og utfyllingslys kan slås av og på uavhengig av hverandre
- Uavhengig scene på hver valgt skjerm
- Én til ti kopier av hvert aktivert legeme
- Objekt- og kamerahastighet 0–1600 %, størrelse 50–200 %
- Blank belysning, egne farger og kollisjonsbehandling
- Gjengivelse tilpasset oppdateringsfrekvensen til hver skjerm
- PNG-skjermbilder og MP4-opptak i det selvstendige programmet
- Separate innstillinger for programmet og skjermspareren
- 27 typer legemer og grensesnitt på 17 språk

## Geometriske legemer

Utvalget omfatter polyedre, regelmessige prismer, pyramider og plansnitt, kjegler og sylindre og deres plansnitt, en rotasjonsparaboloide lukket av et plan, kuleavledede legemer, ellipsoider, ovoide, sfærosylinder og torus. Grensesnittet bruker etablerte norske fagtermer.

## Belysning

Avmerkingsboksene `Hovedlys` og `Utfyllingslys` under glidebryterne til høyre slår de to lysene av eller på uavhengig av hverandre for hele scenen. Som standard er `Hovedlys` på og `Utfyllingslys` av. Lysinnstillingene lagres separat for programmet og skjermspareren.

## Program og skjermsparer

`FlyingSolids.exe` beholder ett kontrollvindu mens animasjonen kjører. Flere skjermer kan velges, en rad kan slås av eller på med dobbeltklikk, og alle kan kobles fra. PNG lagres som standard i **Bilder**, MP4 i **Videoer**, med **Dokumenter** som reserve. EXE-filen kan installere og avinstallere den innebygde skjermspareren.

Bare én instans av programmet kan kjøre om gangen. En ny start gjenoppretter det minimerte kontrollvinduet, tegner det på nytt og bringer det fremst.

Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc lukker det aktive Hjelp- eller Om-vinduet; i kontrollvinduet avslutter det programmet.

Skjermbilder og opptak bruker den første aktive animasjonsskjermen, ikke et samlet bilde av alle skjermene. PNG bruker Bilder, MP4 Videoer; hvis disse mappene ikke finnes, brukes Dokumenter. MP4-opptak følger skjermens oppdateringsfrekvens, opptil 60 bilder per sekund.

`FlyingSolids.scr` har egne innstillinger uten opptak. Fullskjerm kjører en uavhengig scene på hver skjerm.

Slå på forhåndsvisning i innstillingene starter en egen fullskjermsvisning på alle skjermer. Den bruker gjeldende innstillinger, tillater endringer underveis og kan stoppes igjen. En hvilken som helst tast, musebevegelse eller et museklikk avslutter skjermspareren i fullskjerm.

Esc i innstillingene tilsvarer Avbryt; i Hjelp eller Om lukker det bare dette vinduet.

## Innstillinger

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Systemkrav

Windows 7 til Windows 11 støtter alle funksjoner, inkludert PNG-skjermbilder og MP4-opptak.

Windows Vista SP2: KB971512, KB2117917. MP4-opptak fungerer ikke på Vista i den gjeldende versjonen.

Visningen krever Direct3D 11, ikke bare en eldre DirectX-kjøretid. MP4-opptak krever tilgjengelige Media Foundation-komponenter og en H.264-koder.

## Bygging

Åpne `DispSavers.slnx`, velg `Release | x86` og bygg løsningen på nytt med MSVC v145 og Windows SDK. EXE og SCR bygges sammen. `PackageRelease.ps1` oppretter løsningens ene pakke `DispSavers-<version>-win32.zip`, med filene og `license.txt` i undermappen `FlyingSolids`. Det finnes ingen x64-konfigurasjon.

## Lisens

FlyingSolids er tilgjengelig under [MIT-lisensen](../license.txt).

Copyright © Petr Červinka — FortSoft 2026
