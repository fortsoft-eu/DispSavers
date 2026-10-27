# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · **Norsk (bokmål)** · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Maskinvareakselerert animasjon av solide 3D-objekter.

Velg én eller flere skjermer i listen. Kameramodus, objekter, belysning, hastigheter, størrelse og antall kopier gjelder bare de valgte skjermene. Hver skjerm husker sine egne innstillinger. FlyingSolids viser belyste solide 3D-legemer. Glidebryterne angir objekt- og kamerahastighet fra 0–1600 %, én til ti kopier og størrelse fra 50–200 %. Velg Romobservasjon eller Flyging gjennom rommet i rett linje og aktiver ønskede legemer. Avmerkingsboksene Hovedlys, Utfyllingslys, Omgivelseslys og Konturlys under glidebryterne styrer belysningen på de valgte skjermene uavhengig av hverandre. Omgivelseslys gir grunnbelysning på overflatene, og konturlys fremhever kantene. Innstillingene lagres separat for programmet og skjermspareren.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Maskinvareakselerert flytur gjennom en formendrende korridor og trakt.

FlightCorridor: Flytur mellom fire formendrende flater; Flytur gjennom en formendrende trakt. Tilordne nøyaktig én animasjon til hver skjerm. Tekstur veksler mellom teksturerte flater og trådmodell. Fritt roterende kamera endrer synsretningen langsomt i alle tre dimensjoner. Pauser og vendinger legger til tilfeldige oppbremsinger, pauser og endringer i rotasjonsretningen; flyvningen fremover fortsetter. Hastigheten er 0–1600 %. Hver skjerm har en uavhengig tilfeldig scene som gjengis ved dens egen oppdateringsfrekvens. Hovedlys, utfyllingslys, omgivelseslys og konturlys kan slås av og på uavhengig for de valgte skjermene. Belysningen gjelder bare teksturerte flater.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Maskinvareakselerert flytur over bølgende og formendrende flater.

SpaceFlight: Uendelig bølgende flate; Langdistanseflytur — formendrende flate; Flytur gjennom gravitasjonskrummet rom. Tilordne nøyaktig én animasjon til hver skjerm. Tekstur veksler mellom teksturerte flater og trådmodell. Fritt roterende kamera endrer synsretningen langsomt i alle tre dimensjoner. Pauser og vendinger legger til tilfeldige oppbremsinger, pauser og endringer i rotasjonsretningen; flyvningen fremover fortsetter. Hastigheten er 0–1600 %. Hver skjerm har en uavhengig tilfeldig scene som gjengis ved dens egen oppdateringsfrekvens. Hovedlys, utfyllingslys, omgivelseslys og konturlys kan slås av og på uavhengig for de valgte skjermene. Belysningen gjelder bare teksturerte flater. De to flateanimasjonene tilbyr Plan, Bølger eller Trakt. Trakten trekker kameraet innover langs en nedadgående spiral. Flyturen gjennom gravitasjonskrummet rom viser et tredimensjonalt trådgitter. Valgene for tekstur, flateform og belysning gjelder bare de to flateanimasjonene.

`SpaceFlight.exe` · `SpaceFlight.scr`

## SKJERMER

Markeringen av rader bestemmer hvilke skjermer du redigerer, og er atskilt fra avkrysningsboksene som aktiverer animasjonsutgangen. Ctrl+A markerer alle skjermer; Ctrl og Skift endrer markeringen. Alle animasjonsvalg og glidebrytere gjelder de markerte skjermene. Markeringen huskes separat for EXE og SCR. Hvis alle skjermer var markert, inkluderes også nye skjermer. Ulike verdier på de markerte skjermene vises med ubestemte avkrysningsbokser og prikkmønster på alternativknapper, glidebryterhåndtak og knappene «Slå på alle» og «Slå av alle». Glidebryteretiketter viser en tankestrek i stedet for en felles verdi. Endring av et valg eller klikk på en glidebryter bruker denne verdien på alle markerte skjermer.

## BETJENING

Slå animasjonsutgangene av eller på med skjermenes avkrysningsbokser eller ved å dobbeltklikke på radene deres. Hver skjerm bruker en uavhengig scene. Skjermbilde lagrer PNG, og opptaksknappen starter eller stopper MP4. Pause stanser animasjonen. Programmet installerer eller avinstallerer også den innebygde skjermspareren. Innstillingene lagres fortløpende. Bare én instans av programmet kan kjøre om gangen. En ny start gjenoppretter det minimerte kontrollvinduet og bringer det fremst. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc lukker det aktive Hjelp- eller Om-vinduet; i kontrollvinduet avslutter det programmet. Pause og blokkering av skjermspareren gjelder hele programmet uavhengig av skjermmarkeringen. Når blokkering er slått på, hindres Windows-skjermspareren bare mens en synlig animasjon som ikke er satt på pause, vises på minst én skjerm.

## SKJERMBILDER OG OPPTAK

Skjermbilder og opptak bruker den første aktive animasjonsskjermen, ikke et samlet bilde av alle skjermene. PNG bruker Bilder, MP4 Videoer; hvis disse mappene ikke finnes, brukes Dokumenter. Knappen Opptaksinnstillinger velger Viewport eller TV. Viewport beholder animasjonsskjermens størrelse og oppdateringsfrekvens, opptil 60 bilder per sekund. TV tilbyr 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9, med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) bilder per sekund. Bildets proporsjoner beholdes; TV bruker progressiv BT.709-video med begrenset område og 4:2:0-sampling. Oppløsning og bildefrekvens er bare tilgjengelige i TV-modus. Vinduet Opptaksinnstillinger kan minimeres og blokkerer ikke de andre programvinduene. OK lagrer valgene for neste MP4-opptak; Avbryt eller Esc forkaster ubekreftede endringer. Animasjonsutgangen på skjermen som tas opp, kan ikke slås av under opptaket; endringer på andre skjermer stopper ikke opptaket. Å avslutte programmet under et opptak krever bekreftelse, fordi det også avslutter opptaket.

## FORHÅNDSVISNING OG BETJENING

Slå på forhåndsvisning starter en fullskjermsvisning på alle skjermer. Innstillingene forblir åpne, og endringene vises fortløpende. OK lagrer innstillingene og Avbryt forkaster dem. Esc eller musebevegelse avslutter fullskjermsvisningen. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc i innstillingene tilsvarer Avbryt; i Hjelp eller Om lukker det bare dette vinduet.

## Systemkrav

Windows 7 til Windows 11 støtter alle funksjoner, inkludert PNG-skjermbilder og MP4-opptak. For å kjøre programmet på Windows Vista SP2 må oppdateringene KB971512 og KB2117917 installeres. MP4-opptak fungerer ikke på Vista i den gjeldende versjonen. Visningen krever Direct3D 11, ikke bare en eldre DirectX-kjøretid. MP4-opptak krever tilgjengelige Media Foundation-komponenter og en H.264-koder. Det frittstående programmet kan også kjøre på Linux via Wine; integrasjon som skjermsparer er bare tilgjengelig på Windows.

## Bygging

Åpne `DispSavers.slnx` i Visual Studio med MSVC v145 og Windows SDK. Velg `Release | x86` og bygg løsningen på nytt for å lage `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\SpaceFlight.exe` og `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr`. Det finnes ingen x64-konfigurasjon.

Pakk disse byggeutdataene ved å kjøre `PackageRelease.ps1` uten signeringsparametere. Skriptet bruker midlertidige kopier, endrer ikke filer i `Release` og kontrollerer bare eksisterende gyldige signaturer. Det oppretter ett arkiv, `DispSavers-<version>-win32.zip`, med `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` og `SpaceFlight\license.txt`. Den forrige ZIP-filen fjernes ved starten av kjøringen; en kontrollfeil hindrer opprettelse av et nytt arkiv.

## Lisens

DispSavers er tilgjengelig under [MIT-lisensen](../license.txt). Copyright © Petr Červinka — FortSoft 2026
