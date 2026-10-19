# SpaceFlight

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · **Dansk** · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

SpaceFlight tilbyder „Uendelig bølgende flade“ og „Langdistanceflyvetur — formskiftende flade“. Tildel præcis én flyvetur til hver skærm: vælg dens række og den tilsvarende alternativknap. Den første animation er valgt på alle skærme som standard. Tekstur er slået til som standard; fjern markeringen ved Tekstur for at vise de valgte skærme som trådmodeller. Når flere rækker er valgt, gælder valget alle disse skærme. Skyderen indstiller animationshastigheden fra 0 til 1600 %. Ved standardstart aktiverer EXE kun den primære animationsskærm, mens pauseskærmen aktiverer alle skærme. Hver skærm gengives med sin egen opdateringsfrekvens. Indstillingerne gemmes separat for programmet og pauseskærmen. Frit roterende kamera giver jævn rotation af visningen i alle retninger på de valgte skærme; indstillingen er som standard slået fra. Stop og retningsskift bremser kamerarotationen jævnt med tilfældige mellemrum, stopper den kort og starter den igen i modsat retning. Valget er tilgængeligt, når frit roterende kamera er aktiveret, og er slået fra som standard; flyvningen fortsætter.

## Program

`SpaceFlight.exe`

Vælg flere skærme i listen; dobbeltklik på en række for at slå animationen til eller fra, eller fravælg alle. Hver skærm bruger en uafhængig scene. Skærmbillede gemmer PNG, og optageknappen starter eller stopper MP4. Pause standser animationen. Programmet installerer eller afinstallerer også den indbyggede pauseskærm. Indstillinger gemmes løbende. Programmet kan kun køre i én instans ad gangen. En ny start gendanner det minimerede kontrolvindue og bringer det forrest. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det understregede bogstav aktiverer en kommando. Esc lukker det aktive Hjælp- eller Om-vindue; i kontrolvinduet afslutter det programmet. Blokér pauseskærm under animation forhindrer Windows-pauseskærmen i at starte, men kun når animationen faktisk er synlig og ikke er sat på pause.

Skærmbilleder og optagelser bruger den første aktive animationsskærm, ikke et samlet billede af alle skærme. PNG bruger Billeder, MP4 Videoer; hvis disse mapper ikke findes, bruges Dokumenter. Knappen Optagelsesindstillinger vælger Viewport eller TV. Viewport bevarer animationsskærmens størrelse og opdateringsfrekvens, højst 60 billeder i sekundet. TV tilbyder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9 med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) billeder i sekundet. Billedets proportioner bevares; TV bruger progressiv BT.709-video med begrænset område og 4:2:0-sampling. Opløsning og billedfrekvens kan kun vælges i TV-tilstand. Vinduet Optagelsesindstillinger kan minimeres og blokerer ikke de andre programvinduer. OK gemmer valgene til den næste MP4-optagelse; Annuller eller Esc kasserer ubekræftede ændringer. Den skærm, der optages, kan ikke fravælges under optagelsen; ændringer af andre skærme stopper ikke optagelsen. Hvis programmet lukkes under en optagelse, kræves en bekræftelse, fordi optagelsen også afsluttes.

Windows 7 til Windows 11 understøtter alle funktioner, herunder PNG-skærmbilleder og MP4-optagelse. For at køre programmet på Windows Vista SP2 skal opdateringerne KB971512 og KB2117917 installeres. MP4-optagelse fungerer ikke på Vista i den aktuelle version.

## Pauseskærm

`SpaceFlight.scr`

Aktivér forhåndsvisning starter en fuldskærmsvisning på alle skærme. Indstillingerne forbliver åbne, og ændringerne vises med det samme. OK gemmer indstillingerne, og Annuller forkaster ændringerne. Esc eller musebevægelse afslutter fuldskærmen. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det understregede bogstav aktiverer en kommando. Esc i indstillingerne svarer til Annuller; i Hjælp eller Om lukker det kun dette vindue.

Windows 7 til Windows 11 understøttes. For at køre programmet på Windows Vista SP2 skal opdateringerne KB971512 og KB2117917 installeres.

## Bygning

Åbn `DispSavers.slnx` i Visual Studio med MSVC v145 og Windows SDK. Vælg `Release | x86`, og genopbyg løsningen for at oprette `Release\SpaceFlight.exe` og `Release\SpaceFlight.scr`. Der findes ingen x64-konfiguration. Signering er som standard slået til for både Release og Debug. Angiv navnet eller fingeraftrykket for et gyldigt certifikat til kodesignering med en privat nøgle i den aktuelle brugers `Personal (My)`-lager på siden `Signing` i egenskaberne for projektet `SpaceFlight`. Indstillingerne gælder EXE og SCR og gemmes i `SpaceFlight.vcxproj.user`, som Git ignorerer. SignTool findes automatisk i PATH eller Windows SDK. Hvis du bruger SimplySign, skal du logge på SimplySign Desktop før bygget. Først signeres SCR og får et obligatorisk RFC 3161 SHA-256-tidsstempel fra den konfigurerede tidsstempelserver; derefter indlejres det i EXE, som også signeres og tidsstemples. Angiv URL-adressen til RFC 3161-tidsstempelserveren i feltet `Timestamp server`. Fejl ved signering, tidsstempling eller kontrol stopper bygget; filer med gyldige tidsstemplede signaturer signeres ikke igen.

[MIT License](license.txt) — Copyright © Petr Červinka — FortSoft 2026
