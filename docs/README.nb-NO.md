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

## GameOfLife

Conways Game of Life i én felles verden på flere skjermer.

### Regler

Conways Game of Life bruker B3/S23. En død celle fødes med nøyaktig tre levende naboer; en levende overlever med to eller tre. De åtte naboene inkluderer diagonaler. Alle celler endres samtidig. Motstående kanter forbindes: venstre med høyre, øverst med nederst.

### Skjermer og felles verden

Avkrysningsboksene i EXE aktiverer skjermer; innstillingene gjelder den felles verdenen. Én aktiv skjerm inneholder hele verdenen. Ved delvis valg fjernes helt tomme rader og kolonner: venstre og høyre skjerm møtes når den midterste slås av. Indre hull som ikke kan fjernes, forblir i simuleringen. Valg av alle skjermer eller bruk av SCR bevarer skrivebordets omsluttende rektangel med usynlige mellomrom. Hver skjerm viser sin del av samme simulering.

### Starttilstand og mønstre

Standardstarten er tilfeldig støy med 25 % levende celler. Starttetthet på 0–100 % brukes ved neste omstart. Bare kjente mønstre bruker 4 106 medfølgende mønstre uten støy og deaktiverer tetthet. Velg en blanding eller et navn; mål oppgis i celler. Skriv et navn for å søke. Bare mønstre som får plass i sin helhet vises. Små kontrollerte mønstre gjentas i separate kopier, store eller komplekse én gang i midten. En mindre verden kan erstatte et for stort valg med en blanding. Endret modus eller mønster lager en ny scene. Omstart beholder valget; katalogen virker uten nett.

### Celler, rutenett og farger

Uten rutenett er cellestørrelsen 1–64 px. Vis rutenett legger til en kant på 1 px innenfor eksisterende avstand: vist verdi og glidebryter går ned én, med 1–63 som brukbare verdier. Avslåing gjenoppretter verdien. Glidebryteren beholder området og hopper tilbake fra det utilgjengelige endepunktet; boksen forblir aktiv. Bytte bevarer scenen, unntatt aktivering ved 1 px: avstanden blir 2 px og scenen starter på nytt. Endring av størrelse eller skjermer starter også på nytt. Svært store verdener kan kreve et høyere minimum. Celle-, bakgrunns- og rutenettfarger endres hver for seg uten omstart. Tilfeldig farge på levende celler velger en ny farge ved hver manuelle eller automatiske omstart av scenen. Den lagrede fargen bevares og gjenopprettes når valget slås av. Samme virkemåte kan aktiveres separat for bakgrunn og rutenett; begge nye valg er av som standard.

### Hastighet, pause og automatisk omstart

Hastigheten er 0–240 generasjoner/s uavhengig av oppdateringsfrekvens; 0 stopper utviklingen. Pause og Fortsett bevarer verdenen. Start på nytt begynner i valgt modus. Valgfri automatisk omstart finner statiske og nøyaktig gjentatte synlige faser, også oscillatorer. Den sammenligner generasjoner, ikke sekunder; usynlige områder utelates. Asynkrone resultater kan forsinke omstart litt. Standard: 8 px avstand, 20 generasjoner/s, tilfeldig farge på levende celler og automatisk omstart på. Rutenettet er slått av som standard. Oppnådd hastighet avhenger av ytelse og antall celler. Automatisk omstart sammenligner områdene på aktiverte skjermer; mellomrom utvikler seg fortsatt, men tas ikke med i sammenligningen.

### Tilbakestill verdier

Tilbakestilling setter vist cellestørrelse til 8 px med eller uten rutenett (avstand 9 eller 8 px), hastighet til 20 generasjoner/s, tetthet til 25 % og de tre standardfargene. Andre valg beholdes; et mønster som ikke lenger passer, erstattes med blandingen. En ny scene opprettes bare hvis avstanden endres, eller hvis tettheten endres i støymodus.

### Selvstendig program og MP4-opptak

EXE lagrer innstillinger fortløpende og tar opp den første aktive skjermen som MP4. Videoer foreslås, ellers Dokumenter. Viewport bruker skjermens mål og frekvens opptil 60 bilder/s. TV tilbyr 1920 × 1080, 1440 × 1080 eller 1280 × 720 i 16:9 ved 50, 25, 59,94 (60000/1001) eller 29,97 (30000/1001) bilder/s. Sideforholdet bevares; TV bruker progressiv BT.709 med begrenset område og 4:2:0. Det uavhengige innstillingsvinduet kan minimeres. OK lagrer for neste opptak; Avbryt eller Esc forkaster ubekreftede endringer. Skjermen som tas opp kan ikke deaktiveres; andre utganger kan endres. Avslutning under opptak krever bekreftelse. Med fokus på animasjonen veksler Mellomrom pause, F9: Start opptak; F10: Stopp opptak. Pekeren skjules etter 1 sekund uten aktivitet og vises ved bevegelse. Tab/Shift+Tab flytter mellom kontroller; Alt aktiverer understrekede kommandoer. Esc lukker Hjelp/Om eller avslutter fra hovedvinduet. Windows-skjermsparer… åpner systemets skjermsparerinnstillinger.

### Øyeblikksbilde og skjermsparer i EXE

Øyeblikksbilde lagrer en BMP/GIF/JPEG/PNG/TIFF/WebP av skjermen som tas opp, ellers den første aktive, i dens oppløsning uten å starte scenen på nytt. Bilder foreslås, ellers Dokumenter. Blokkering av skjermspareren under animasjon hindrer at den starter mens animasjonen er synlig og ikke satt på pause. Hastighet null er ikke pause. Installasjon fra EXE pakker ut den medfølgende SCR-en og velger den som Windows-skjermsparer. Installasjon og avinstallasjon kan kreve administratorgodkjenning; statuslinjen viser handlingen til den er ferdig. Hvis fjerning er blokkert, lukk den kjørende skjermspareren, innstillingene og Windows-forhåndsvisningen.

### Windows-skjermsparer

GameOfLife.scr bruker alle skjermer med innstillinger atskilt fra EXE. Forhåndsvisning starter fullskjermsanimasjon mens innstillingene er åpne. Den lille Windows-forhåndsvisningen forminsker hele verdenen. OK lagrer; Avbryt eller Esc forkaster endringer. Musebevegelse eller en tast avslutter skjermspareren i fullskjerm. MP4-opptak finnes i EXE.

### Vindusplassering og tilstand

Ved lukking lagres plasseringen av hovedvinduet og Om-vinduet separat; for Hjelp også størrelse og normal eller maksimert tilstand før eventuell minimering. Dette er uavhengig av bekreftelse av programinnstillinger. Avslutning av programmet lukker også Hjelp og Om.

### Gjengivelse og mønsterlisenser

Utvikling og synlige sammenligninger bruker Direct3D 11-skyggeprogrammer på GPU-en; programvaregjengivelse finnes hvis maskinvareinitialisering mislykkes. Hver skjerm bruker den gjennomprøvde rammetidsstyringen ved sin egen frekvens. MP4 krever Media Foundation og en H.264-koder. Mønstre kommer fra LifeWiki (GFDL 1.2 eller nyere) og Alan Hensels samlinger i det fri. Programkoden bruker MIT; katalogens merknader og lisenser er separate.

[Mønsterkilder, lisenser og importdetaljer](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### SKJERMER

Markeringen av rader bestemmer hvilke skjermer du redigerer, og er atskilt fra avkrysningsboksene som aktiverer animasjonsutgangen. Ctrl+A markerer alle skjermer; Ctrl og Skift endrer markeringen. Alle animasjonsvalg og glidebrytere gjelder de markerte skjermene. Markeringen huskes separat for EXE og SCR. Hvis alle skjermer var markert, inkluderes også nye skjermer. Ulike verdier på de markerte skjermene vises med ubestemte avkrysningsbokser og prikkmønster på alternativknapper, glidebryterhåndtak og knappene «Slå på alle» og «Slå av alle». Glidebryteretiketter viser en tankestrek i stedet for en felles verdi. Endring av et valg eller klikk på en glidebryter bruker denne verdien på alle markerte skjermer.

### BETJENING

Slå animasjonsutgangene av eller på med skjermenes avkrysningsbokser eller ved å dobbeltklikke på radene deres. Hver skjerm bruker en uavhengig scene. Skjermbilde lagrer BMP/GIF/JPEG/PNG/TIFF/WebP, og opptaksknappen starter eller stopper MP4. Pause stanser animasjonen. Programmet installerer eller avinstallerer også den innebygde skjermspareren. Innstillingene lagres fortløpende. Bare én instans av programmet kan kjøre om gangen. En ny start gjenoppretter det minimerte kontrollvinduet og bringer det fremst. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc lukker det aktive Hjelp- eller Om-vinduet; i kontrollvinduet avslutter det programmet. Pause og blokkering av skjermspareren gjelder hele programmet uavhengig av skjermmarkeringen. Når blokkering er slått på, hindres Windows-skjermspareren bare mens en synlig animasjon som ikke er satt på pause, vises på minst én skjerm.

### SKJERMBILDER OG OPPTAK

Skjermbilder og opptak bruker den første aktive animasjonsskjermen, ikke et samlet bilde av alle skjermene. BMP/GIF/JPEG/PNG/TIFF/WebP bruker Bilder, MP4 Videoer; hvis disse mappene ikke finnes, brukes Dokumenter. Knappen Opptaksinnstillinger velger Viewport eller TV. Viewport beholder animasjonsskjermens størrelse og oppdateringsfrekvens, opptil 60 bilder per sekund. TV tilbyr 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9, med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) bilder per sekund. Bildets proporsjoner beholdes; TV bruker progressiv BT.709-video med begrenset område og 4:2:0-sampling. Oppløsning og bildefrekvens er bare tilgjengelige i TV-modus. Vinduet Opptaksinnstillinger kan minimeres og blokkerer ikke de andre programvinduene. OK lagrer valgene for neste MP4-opptak; Avbryt eller Esc forkaster ubekreftede endringer. Animasjonsutgangen på skjermen som tas opp, kan ikke slås av under opptaket; endringer på andre skjermer stopper ikke opptaket. Å avslutte programmet under et opptak krever bekreftelse, fordi det også avslutter opptaket.

### FORHÅNDSVISNING OG BETJENING

Slå på forhåndsvisning starter en fullskjermsvisning på alle skjermer. Innstillingene forblir åpne, og endringene vises fortløpende. OK lagrer innstillingene og Avbryt forkaster dem. Esc eller musebevegelse avslutter fullskjermsvisningen. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc i innstillingene tilsvarer Avbryt; i Hjelp eller Om lukker det bare dette vinduet.

### Systemkrav

Windows 7 til Windows 11 støtter alle funksjoner, inkludert BMP/GIF/JPEG/PNG/TIFF/WebP-skjermbilder og MP4-opptak. For å kjøre programmet på Windows Vista SP2 må oppdateringene KB971512 og KB2117917 installeres. MP4-opptak fungerer ikke på Vista i den gjeldende versjonen. Visningen krever Direct3D 11, ikke bare en eldre DirectX-kjøretid. MP4-opptak krever tilgjengelige Media Foundation-komponenter og en H.264-koder. Det frittstående programmet kan også kjøre på Linux via Wine; integrasjon som skjermsparer er bare tilgjengelig på Windows.

## Bygging

Åpne `DispSavers.slnx` i Visual Studio med MSVC v145 og Windows SDK. Velg `Release | x86` og bygg løsningen på nytt for å lage `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\GameOfLife.exe`, `Release\GameOfLife.scr`, `Release\SpaceFlight.exe` og `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr`. Det finnes ingen x64-konfigurasjon.

Pakk disse byggeutdataene ved å kjøre `PackageRelease.ps1` uten signeringsparametere. Skriptet bruker midlertidige kopier, endrer ikke filer i `Release` og kontrollerer bare eksisterende gyldige signaturer. Det oppretter ett arkiv, `DispSavers-<version>-win32.zip`, med `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `GameOfLife\GameOfLife.exe`, `GameOfLife\GameOfLife.scr`, `GameOfLife\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` og `SpaceFlight\license.txt`. Den forrige ZIP-filen fjernes ved starten av kjøringen; en kontrollfeil hindrer opprettelse av et nytt arkiv.

## Lisens

DispSavers er tilgjengelig under [MIT-lisensen](../license.txt). Copyright © Petr Červinka — FortSoft 2026
