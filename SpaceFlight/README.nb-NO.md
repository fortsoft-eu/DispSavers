# SpaceFlight

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · **Norsk (bokmål)** · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

SpaceFlight: Uendelig bølgende flate; Langdistanseflytur — formendrende flate. Tilordne nøyaktig én animasjon til hver skjerm. Tekstur veksler mellom teksturerte flater og trådmodell. Fritt roterende kamera endrer synsretningen langsomt i alle tre dimensjoner. Pauser og vendinger legger til tilfeldige oppbremsinger, pauser og endringer i rotasjonsretningen; flyvningen fremover fortsetter. Hastigheten er 0–1600 %. Hver skjerm har en uavhengig tilfeldig scene som gjengis ved dens egen oppdateringsfrekvens. Hovedlys, utfyllingslys, omgivelseslys og konturlys kan slås av og på uavhengig for de valgte skjermene. Belysningen gjelder bare teksturerte flater. Når Bølger slås av, blir begge flatene plane, mens flyvningen og kamerarotasjonen fortsetter.

Markeringen av rader bestemmer hvilke skjermer du redigerer, og er atskilt fra avkrysningsboksene som aktiverer animasjonsutgangen. Ctrl+A markerer alle skjermer; Ctrl og Skift endrer markeringen. Alle animasjonsvalg og glidebrytere gjelder de markerte skjermene. Markeringen huskes separat for EXE og SCR. Hvis alle skjermer var markert, inkluderes også nye skjermer.

## Program

`SpaceFlight.exe`

Velg flere skjermer i listen; dobbeltklikk en rad for å slå animasjonen av eller på, eller fjern valget for alle. Hver skjerm bruker en uavhengig scene. Skjermbilde lagrer PNG, og opptaksknappen starter eller stopper MP4. Pause stanser animasjonen. Programmet installerer eller avinstallerer også den innebygde skjermspareren. Innstillingene lagres fortløpende. Bare én instans av programmet kan kjøre om gangen. En ny start gjenoppretter det minimerte kontrollvinduet og bringer det fremst. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc lukker det aktive Hjelp- eller Om-vinduet; i kontrollvinduet avslutter det programmet. Hindre skjermsparer under animasjon hindrer Windows-skjermspareren i å starte bare når animasjonen faktisk er synlig og ikke er satt på pause.

Skjermbilder og opptak bruker den første aktive animasjonsskjermen, ikke et samlet bilde av alle skjermene. PNG bruker Bilder, MP4 Videoer; hvis disse mappene ikke finnes, brukes Dokumenter. Knappen Opptaksinnstillinger velger Viewport eller TV. Viewport beholder animasjonsskjermens størrelse og oppdateringsfrekvens, opptil 60 bilder per sekund. TV tilbyr 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9, med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) bilder per sekund. Bildets proporsjoner beholdes; TV bruker progressiv BT.709-video med begrenset område og 4:2:0-sampling. Oppløsning og bildefrekvens er bare tilgjengelige i TV-modus. Vinduet Opptaksinnstillinger kan minimeres og blokkerer ikke de andre programvinduene. OK lagrer valgene for neste MP4-opptak; Avbryt eller Esc forkaster ubekreftede endringer. Skjermen som tas opp, kan ikke velges bort under opptaket; endringer på andre skjermer stopper ikke opptaket. Å avslutte programmet under et opptak krever bekreftelse, fordi det også avslutter opptaket.

Windows 7 til Windows 11 støtter alle funksjoner, inkludert PNG-skjermbilder og MP4-opptak. For å kjøre programmet på Windows Vista SP2 må oppdateringene KB971512 og KB2117917 installeres. MP4-opptak fungerer ikke på Vista i den gjeldende versjonen.

## Skjermsparer

`SpaceFlight.scr`

Slå på forhåndsvisning starter en fullskjermsvisning på alle skjermer. Innstillingene forblir åpne, og endringene vises fortløpende. OK lagrer innstillingene og Avbryt forkaster dem. Esc eller musebevegelse avslutter fullskjermsvisningen. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc i innstillingene tilsvarer Avbryt; i Hjelp eller Om lukker det bare dette vinduet.

Windows 7 til Windows 11 støttes. For å kjøre programmet på Windows Vista SP2 må oppdateringene KB971512 og KB2117917 installeres.

## Bygging

Åpne `DispSavers.slnx` i Visual Studio med MSVC v145 og Windows SDK. Velg `Release | x86` og bygg løsningen på nytt for å lage `Release\SpaceFlight.exe` og `Release\SpaceFlight.scr`. Det finnes ingen x64-konfigurasjon. På siden `Signing` i egenskapene til prosjektet `SpaceFlight` angir du navnet eller fingeravtrykket til et gyldig kodesigneringssertifikat med privat nøkkel i den gjeldende brukerens `Personal (My)`-lager. Innstillingene gjelder både EXE og SCR og lagres i `SpaceFlight.vcxproj.user`, som ignoreres av Git. SignTool finnes automatisk i PATH eller Windows SDK. Hvis du bruker SimplySign, logger du på SimplySign Desktop før byggingen. Først signeres SCR og får et obligatorisk RFC 3161 SHA-256-tidsstempel fra den konfigurerte tidsstempelserveren; deretter bygges det inn i EXE, som også signeres og tidsstemples. Angi URL-en til RFC 3161-tidsstempelserveren i feltet `Timestamp server`. Feil ved signering, tidsstempling eller kontroll stopper byggingen; filer med gyldige tidsstemplede signaturer signeres ikke på nytt.

[MIT License](license.txt) — Copyright © Petr Červinka — FortSoft 2026
