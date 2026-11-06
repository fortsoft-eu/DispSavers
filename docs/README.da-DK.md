# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · **Dansk** · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Hardwareaccelereret animation af solide 3D-objekter.

Vælg en eller flere skærme på listen. Kameratilstand, objekter, belysning, hastigheder, størrelse og antal kopier gælder kun de valgte skærme. Hver skærm husker sine egne indstillinger. FlyingSolids viser belyste solide 3D-legemer. Skyderne indstiller objekt- og kamerahastighed 0–1600 %, en til ti kopier og størrelse 50–200 %. Vælg Rumobservation eller Flyvning gennem rummet i en lige linje og aktivér de ønskede legemer. Afkrydsningsfelterne Hovedlys, Udfyldningslys, Omgivende lys og Konturlys under skyderne styrer belysningen på de valgte skærme uafhængigt af hinanden. Omgivende lys giver overfladerne en grundbelysning, og konturlys fremhæver kanterne. Indstillingerne gemmes separat for programmet og pauseskærmen.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Hardwareaccelereret flyvetur gennem en formskiftende korridor og tragt.

FlightCorridor: Flyvetur mellem fire formskiftende flader; Flyvetur gennem en formskiftende tragt. Tildel præcis én animation til hver skærm. Tekstur skifter mellem teksturerede flader og trådmodel. Frit roterende kamera ændrer langsomt synsretningen i alle tre dimensioner. Pauser og vendinger tilføjer tilfældige opbremsninger, pauser og ændringer af rotationsretningen; flyvningen fremad fortsætter. Hastigheden er 0–1600 %. Hver skærm har en uafhængig tilfældig scene, der gengives med dens egen opdateringsfrekvens. Hovedlys, udfyldningslys, omgivende lys og konturlys kan slås til og fra uafhængigt for de valgte skærme. Belysningen gælder kun teksturerede overflader.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Hardwareaccelereret flyvetur over bølgende og formskiftende flader.

SpaceFlight: Uendelig bølgende flade; Langdistanceflyvetur — formskiftende flade; Flyvetur gennem gravitationelt krummet rum. Tildel præcis én animation til hver skærm. Tekstur skifter mellem teksturerede flader og trådmodel. Frit roterende kamera ændrer langsomt synsretningen i alle tre dimensioner. Pauser og vendinger tilføjer tilfældige opbremsninger, pauser og ændringer af rotationsretningen; flyvningen fremad fortsætter. Hastigheden er 0–1600 %. Hver skærm har en uafhængig tilfældig scene, der gengives med dens egen opdateringsfrekvens. Hovedlys, udfyldningslys, omgivende lys og konturlys kan slås til og fra uafhængigt for de valgte skærme. Belysningen gælder kun teksturerede overflader. De to overfladeanimationer tilbyder Plan, Bølger eller Tragt. Tragten trækker kameraet indad langs en nedadgående spiral. Flyveturen gennem gravitationelt krummet rum viser et tredimensionalt trådgitter. Indstillingerne for tekstur, overfladeform og belysning gælder kun de to overfladeanimationer.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Conways Game of Life i én fælles verden på flere skærme.

### Regler

Conways Game of Life bruger B3/S23. En død celle fødes med præcis tre levende naboer; en levende overlever med to eller tre. De otte naboer omfatter diagonaler. Alle celler ændres samtidig. Modsatte kanter forbindes: venstre med højre, øverst med nederst.

### Skærme og fælles verden

Afkrydsningsfelter i EXE aktiverer skærme; indstillinger gælder den fælles verden. Én aktiv skærm indeholder hele verden. Ved delvist valg fjernes helt tomme rækker og kolonner: venstre og højre skærm mødes, når den midterste slås fra. Indre huller, der ikke kan fjernes, forbliver i simuleringen. Valg af alle skærme eller brug af SCR bevarer skrivebordets omsluttende rektangel med usynlige mellemrum. Hver skærm viser sin del af samme simulering.

### Starttilstand og mønstre

Standardstarten er tilfældig støj med 25 % levende celler. Starttæthed på 0–100 % bruges ved næste genstart. Kun kendte mønstre bruger 4.106 medfølgende mønstre uden støj og deaktiverer tæthed. Vælg en blanding eller et navn; mål er i celler. Skriv et navn for at søge. Alle katalogets mønstre er altid tilgængelige. Små kontrollerede mønstre gentages i adskilte kopier, store eller komplekse én gang i midten. Et for stort mønster centreres og beskæres; ændret verdens- eller cellestørrelse bevarer valget. Ændret tilstand eller mønster opretter en ny scene. Genstart bevarer valget; kataloget virker offline.

### Celler, gitter og farver

Uden gitter er cellestørrelsen 1–64 px. Vis gitter tilføjer en kant på 1 px inden for den nuværende afstand: vist værdi og skyder falder med én, med 1–63 som brugbare værdier. Fravalg gendanner værdien. Skyderen beholder sit område og springer tilbage fra det utilgængelige endepunkt; feltet forbliver aktivt. Skift bevarer scenen, undtagen tilvalg ved 1 px: afstanden bliver 2 px, og scenen begynder forfra. Ændring af størrelse eller skærme starter også forfra. Meget store verdener kan kræve et større minimum. Celle-, baggrunds- og gitterfarver ændres hver for sig uden genstart. Tilfældig farve på levende celler vælger en ny farve ved hver manuel eller automatisk genstart af scenen. Den gemte farve bevares og gendannes, når denne indstilling slås fra. Samme adfærd kan aktiveres særskilt for baggrund og gitter; begge nye indstillinger er som standard slået fra.

### Hastighed, pause og automatisk genstart

Hastigheden er 0–240 generationer/s uafhængigt af skærmens opdatering; 0 standser udviklingen. Pause og Fortsæt bevarer verden. Genstart begynder i den valgte tilstand. Valgfri automatisk genstart finder statiske og nøjagtigt gentagne synlige faser, også oscillatorer. Den sammenligner generationer, ikke sekunder; usynlige områder udelades. Asynkrone resultater kan forsinke genstart lidt. Standard: 8 px afstand, 20 generationer/s, tilfældig farve på levende celler og automatisk genstart slået til. Gitteret er slået fra som standard. Den opnåede hastighed afhænger af ydeevne og antal celler. Automatisk genstart sammenligner områderne på aktiverede skærme; mellemrum udvikler sig stadig, men udelades fra sammenligningen.

### Nulstil værdier

Nulstilling gendanner den viste cellestørrelse til 8 px med eller uden gitter (afstand 9 eller 8 px), hastighed 20 generationer/s, tæthed 25 % og de tre standardfarver. Andre valg, herunder det valgte mønster, bevares. En ny scene oprettes kun ved ændret afstand eller ændret tæthed i støjtilstand.

### Selvstændigt program og MP4-optagelse

EXE gemmer indstillinger løbende og optager den første aktive skærm som MP4. Videoer foreslås, ellers Dokumenter. Viewport bruger skærmens mål og opdatering op til 60 billeder/s. TV tilbyder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i 16:9 ved 50, 25, 59,94 (60000/1001) eller 29,97 (30000/1001) billeder/s. Billedforholdet bevares; TV bruger progressiv BT.709 med begrænset område og 4:2:0. Det uafhængige indstillingsvindue kan minimeres. OK gemmer til næste optagelse; Annuller eller Esc forkaster ubekræftede ændringer. Den optagne skærm kan ikke deaktiveres; andre udgange kan ændres. Afslutning under optagelse kræver bekræftelse. Med fokus på animationen skifter Mellemrum pause, F9: Start optagelse; F10: Stop optagelse. Markøren skjules efter 1 sekund uden aktivitet og vises ved bevægelse. Tab/Shift+Tab skifter kontrol, Alt aktiverer understregede kommandoer. Esc lukker Hjælp/Om eller afslutter fra hovedvinduet. Windows-pauseskærm… åbner systemets indstillinger for pauseskærmen.

### Øjebliksbillede og pauseskærm i EXE

Øjebliksbillede gemmer en BMP/GIF/JPEG/PNG/TIFF/WebP af den skærm, der optages, ellers den første aktive, i dens opløsning uden at genstarte scenen. Billeder foreslås, ellers Dokumenter. Blokering af pauseskærmen under animation forhindrer dens start, mens animationen er synlig og ikke på pause. Hastighed nul er ikke pause. Installation fra EXE pakker den medfølgende SCR ud og vælger den som Windows-pauseskærm. Installation og afinstallation kan kræve administratorgodkendelse; statuslinjen viser handlingen, indtil den er færdig. Hvis fjernelse er blokeret, skal den kørende pauseskærm, dens indstillinger og Windows-eksemplet lukkes.

### Windows-pauseskærm

GameOfLife.scr bruger alle skærme med indstillinger adskilt fra EXE. Aktivér eksempel starter fuldskærmsanimation med indstillingerne åbne. Det lille Windows-eksempel formindsker hele verden. OK gemmer; Annuller eller Esc forkaster ændringer. Musebevægelse eller en tast afslutter fuldskærmspauseskærmen. MP4-optagelse findes i EXE.

### Vinduernes placering og tilstand

Ved lukning gemmes placeringen af hovedvinduet og Om-vinduet separat; for Hjælp også størrelse og normal eller maksimeret tilstand før en eventuel minimering. Dette er uafhængigt af bekræftelse af programindstillinger. Afslutning af programmet lukker også Hjælp og Om.

### Gengivelse og mønsterlicenser

Udvikling og synlige sammenligninger bruger Direct3D 11-shadere på GPU'en; softwaregengivelse findes, hvis hardwareinitialisering mislykkes. Hver skærm bruger den gennemprøvede billedtaktstyring ved sin egen opdateringsfrekvens. MP4 kræver Media Foundation og en H.264-koder. Mønstre kommer fra LifeWiki (GFDL 1.2 eller nyere) og Alan Hensels samlinger i public domain. Programkoden bruger MIT; katalogets meddelelser og licenser er særskilte.

[Mønsterkilder, licenser og importoplysninger](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### SKÆRME

Markeringen af rækker bestemmer, hvilke skærme du indstiller, og er adskilt fra afkrydsningsfelterne, der aktiverer animationsoutput. Ctrl+A markerer alle skærme; Ctrl og Skift ændrer markeringen. Alle animationsvalg og skydere gælder de markerede skærme. Markeringen huskes separat for EXE og SCR. Hvis alle skærme var markeret, medtages også nye skærme. Forskellige værdier på de markerede skærme vises med ubestemte afkrydsningsfelter og prikmønstre på alternativknapper, skydergreb og knapperne “Aktivér alle” og “Deaktivér alle”. Skydernes etiketter viser en tankestreg i stedet for en fælles værdi. Ændring af et valg eller klik på en skyder anvender denne værdi på alle markerede skærme.

### BETJENING

Slå animationsoutput til eller fra med skærmenes afkrydsningsfelter eller ved at dobbeltklikke på deres rækker. Hver skærm bruger en uafhængig scene. Skærmbillede gemmer BMP/GIF/JPEG/PNG/TIFF/WebP, og optageknappen starter eller stopper MP4. Pause standser animationen. Programmet installerer eller afinstallerer også den indbyggede pauseskærm. Indstillinger gemmes løbende. Programmet kan kun køre i én instans ad gangen. En ny start gendanner det minimerede kontrolvindue og bringer det forrest. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det understregede bogstav aktiverer en kommando. Esc lukker det aktive Hjælp- eller Om-vindue; i kontrolvinduet afslutter det programmet. Pause og blokering af pauseskærmen gælder hele programmet uanset skærmmarkeringen. Når blokering er slået til, forhindres Windows-pauseskærmen kun, mens der vises en synlig animation, som ikke er sat på pause, på mindst én skærm.

### SKÆRMBILLEDER OG OPTAGELSE

Skærmbilleder og optagelser bruger den første aktive animationsskærm, ikke et samlet billede af alle skærme. BMP/GIF/JPEG/PNG/TIFF/WebP bruger Billeder, MP4 Videoer; hvis disse mapper ikke findes, bruges Dokumenter. Knappen Optagelsesindstillinger vælger Viewport eller TV. Viewport bevarer animationsskærmens størrelse og opdateringsfrekvens, højst 60 billeder i sekundet. TV tilbyder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9 med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) billeder i sekundet. Billedets proportioner bevares; TV bruger progressiv BT.709-video med begrænset område og 4:2:0-sampling. Opløsning og billedfrekvens kan kun vælges i TV-tilstand. Vinduet Optagelsesindstillinger kan minimeres og blokerer ikke de andre programvinduer. OK gemmer valgene til den næste MP4-optagelse; Annuller eller Esc kasserer ubekræftede ændringer. Animationsoutputtet på den skærm, der optages, kan ikke slås fra under optagelsen; ændringer af andre skærme stopper ikke optagelsen. Hvis programmet lukkes under en optagelse, kræves en bekræftelse, fordi optagelsen også afsluttes.

### FORHÅNDSVISNING OG BETJENING

Aktivér forhåndsvisning starter en fuldskærmsvisning på alle skærme. Indstillingerne forbliver åbne, og ændringerne vises med det samme. OK gemmer indstillingerne, og Annuller forkaster ændringerne. Esc eller musebevægelse afslutter fuldskærmen. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det understregede bogstav aktiverer en kommando. Esc i indstillingerne svarer til Annuller; i Hjælp eller Om lukker det kun dette vindue.

### Systemkrav

Windows 7 til Windows 11 understøtter alle funktioner, herunder BMP/GIF/JPEG/PNG/TIFF/WebP-skærmbilleder og MP4-optagelse. For at køre programmet på Windows Vista SP2 skal opdateringerne KB971512 og KB2117917 installeres. MP4-optagelse fungerer ikke på Vista i den aktuelle version. Visningen kræver Direct3D 11, ikke kun et ældre DirectX-kørselsmiljø. MP4-optagelse kræver tilgængelige Media Foundation-komponenter og en H.264-koder. Det selvstændige program kan også køre på Linux via Wine; integration som pauseskærm er kun tilgængelig på Windows.

## Kompilering

Åbn `DispSavers.slnx` i Visual Studio med MSVC v145 og Windows SDK. Vælg `Release | x86`, og genopbyg løsningen for at oprette `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\GameOfLife.exe`, `Release\GameOfLife.scr`, `Release\SpaceFlight.exe` og `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr`. Der findes ingen x64-konfiguration.

Pak disse byggeoutput ved at køre `PackageRelease.ps1` uden signeringsparametre. Scriptet bruger midlertidige kopier, ændrer ikke filer i `Release` og kontrollerer kun eksisterende gyldige signaturer. Det opretter ét arkiv, `DispSavers-<version>-win32.zip`, med `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `GameOfLife\GameOfLife.exe`, `GameOfLife\GameOfLife.scr`, `GameOfLife\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` og `SpaceFlight\license.txt`. Den tidligere ZIP-fil fjernes ved starten af kørslen; en kontrolfejl forhindrer oprettelsen af et nyt arkiv.

## Licens

DispSavers udgives under [MIT-licensen](../license.txt). Copyright © Petr Červinka — FortSoft 2026
