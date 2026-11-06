# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · **Svenska** · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Maskinvaruaccelererad animering av solida 3D-objekt.

Markera en eller flera skärmar i listan. Kameraläge, objekt, belysning, hastigheter, storlek och antal kopior gäller bara de markerade skärmarna. Varje skärm sparar sina egna inställningar. FlyingSolids visar belysta solida 3D-kroppar. Reglagen ställer in objekt- och kamerahastighet 0–1600 %, en till tio kopior och storlek 50–200 %. Välj Rymdobservation eller Flygning genom rymden i rak linje och aktivera önskade kroppar. Kryssrutorna Huvudljus, Upplättningsljus, Omgivningsljus och Konturljus under reglagen styr belysningen på de markerade skärmarna oberoende av varandra. Omgivningsljus ger grundbelysning på ytorna och konturljus framhäver kanterna. Inställningarna sparas separat för programmet och skärmsläckaren.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Maskinvaruaccelererad flygtur genom en formföränderlig korridor och tratt.

FlightCorridor: Flygtur mellan fyra formföränderliga ytor; Flygtur genom en formföränderlig tratt. Tilldela varje skärm exakt en animering. Textur växlar mellan texturerade ytor och trådmodell. Fritt roterande kamera ändrar långsamt blickriktningen i alla tre dimensioner. Pauser och vändningar lägger till slumpmässiga inbromsningar, pauser och byten av rotationsriktning; flygningen framåt fortsätter. Hastigheten är 0–1600 %. Varje skärm har en oberoende slumpmässig scen som återges med dess egen uppdateringsfrekvens. Huvudljus, upplättningsljus, omgivningsljus och konturljus kan slås på och av oberoende för de valda skärmarna. Belysningen gäller bara texturerade ytor.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Maskinvaruaccelererad flygtur över böljande och formföränderliga ytor.

SpaceFlight: Oändlig böljande yta; Långdistansflygtur — formföränderlig yta; Flygtur genom gravitationellt krökt rum. Tilldela varje skärm exakt en animering. Textur växlar mellan texturerade ytor och trådmodell. Fritt roterande kamera ändrar långsamt blickriktningen i alla tre dimensioner. Pauser och vändningar lägger till slumpmässiga inbromsningar, pauser och byten av rotationsriktning; flygningen framåt fortsätter. Hastigheten är 0–1600 %. Varje skärm har en oberoende slumpmässig scen som återges med dess egen uppdateringsfrekvens. Huvudljus, upplättningsljus, omgivningsljus och konturljus kan slås på och av oberoende för de valda skärmarna. Belysningen gäller bara texturerade ytor. De två ytanimeringarna erbjuder Plan, Vågor eller Tratt. Tratten drar kameran inåt längs en nedåtgående spiral. Flygturen genom gravitationellt krökt rum visar ett tredimensionellt trådnät. Inställningarna för textur, ytform och belysning gäller bara de två ytanimeringarna.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Conways Game of Life i en gemensam värld över flera skärmar.

### Regler

Conways Game of Life använder B3/S23. En död cell föds med exakt tre levande grannar; en levande överlever med två eller tre. De åtta grannarna inkluderar diagonaler. Alla celler ändras samtidigt. Motsatta kanter förbinds: vänster med höger, överkant med underkant.

### Skärmar och gemensam värld

Kryssrutorna i EXE aktiverar skärmar; inställningarna gäller den gemensamma världen. En enda aktiv skärm innehåller hela världen. Vid delvis val tas helt tomma rader och kolumner bort: vänster och höger skärm möts när den mittersta stängs av. Inre hål som inte kan tas bort finns kvar i simuleringen. Alla skärmar valda, eller SCR, bevarar skrivbordets omslutande rektangel med osynliga mellanrum. Varje skärm visar sin del av samma simulering.

### Startläge och mönster

Standardstarten är slumpbrus med 25 % levande celler. Starttäthet 0–100 % används vid nästa omstart. Endast kända mönster använder 4 106 medföljande mönster utan brus och inaktiverar täthet. Välj en blandning eller ett namn; mått anges i celler. Skriv ett namn för att söka. Alla mönster i katalogen är alltid tillgängliga. Små kontrollerade mönster upprepas i separata kopior, stora eller komplicerade en gång i mitten. Ett för stort mönster centreras och beskärs; ändrad världs- eller cellstorlek bevarar valet. Ändrat läge eller mönster skapar en ny scen. Omstart behåller valet; katalogen fungerar utan nät.

### Celler, rutnät och färger

Utan rutnät är cellstorleken 1–64 px. Visa rutnät lägger till en kant på 1 px inom befintligt avstånd: visat värde och reglage minskar med ett, med 1–63 användbara värden. Avstängning återställer värdet. Reglaget behåller intervallet och hoppar tillbaka från den otillgängliga ändpunkten; kryssrutan förblir aktiv. Växling bevarar scenen, utom aktivering vid 1 px: avståndet blir 2 px och scenen börjar om. Ändrad storlek eller skärmuppsättning börjar också om. Mycket stora världar kan kräva ett högre minimum. Cell-, bakgrunds- och rutnätsfärger ändras separat utan omstart. Slumpmässig färg på levande celler väljer en ny färg vid varje manuell eller automatisk omstart av scenen. Den sparade färgen bevaras och återställs när alternativet stängs av. Samma beteende kan aktiveras separat för bakgrund och rutnät; båda nya alternativen är av som standard.

### Hastighet, paus och automatisk omstart

Hastigheten är 0–240 generationer/s oberoende av skärmens uppdatering; 0 stoppar utvecklingen. Paus och Fortsätt bevarar världen. Starta om börjar i valt läge. Valfri automatisk omstart identifierar stilla och exakt upprepade synliga faser, även oscillatorer. Den jämför generationer, inte sekunder; osynliga områden räknas inte. Asynkrona resultat kan fördröja omstarten lite. Standard: 8 px avstånd, 20 generationer/s, slumpmässig färg på levande celler och automatisk omstart på. Rutnätet är avstängt som standard. Uppnådd hastighet beror på prestanda och antal celler. Automatisk omstart jämför områdena på aktiverade skärmar; mellanrummen utvecklas fortfarande men ingår inte i jämförelsen.

### Återställ värden

Återställning sätter visad cellstorlek till 8 px med eller utan rutnät (avstånd 9 eller 8 px), hastighet till 20 generationer/s, täthet till 25 % och de tre standardfärgerna. Andra val, inklusive det valda mönstret, bevaras. En ny scen skapas bara om avståndet ändras eller tätheten ändras i brusläge.

### Fristående program och MP4-inspelning

EXE sparar inställningar löpande och spelar in den första aktiva skärmen som MP4. Videor föreslås, annars Dokument. Viewport använder skärmens mått och uppdatering upp till 60 bilder/s. TV erbjuder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i 16:9 vid 50, 25, 59,94 (60000/1001) eller 29,97 (30000/1001) bilder/s. Bildförhållandet bevaras; TV använder progressiv BT.709 med begränsat omfång och 4:2:0. Det fristående inställningsfönstret kan minimeras. OK sparar för nästa inspelning; Avbryt eller Esc förkastar obekräftade ändringar. Den inspelade skärmen kan inte stängas av; andra utgångar kan ändras. Avslut under inspelning kräver bekräftelse. Med fokus på animationen växlar Blanksteg paus, F9: Starta inspelning; F10: Stoppa inspelning. Pekaren döljs efter 1 sekund utan aktivitet och visas vid rörelse. Tab/Shift+Tab flyttar mellan kontroller; Alt aktiverar understrukna kommandon. Esc stänger Hjälp/Om eller avslutar i huvudfönstret. Windows-skärmsläckare… öppnar systemets inställningar för skärmsläckaren.

### Ögonblicksbild och skärmsläckare i EXE

Ögonblicksbild sparar en BMP/GIF/JPEG/PNG/TIFF/WebP av skärmen som spelas in, annars den första aktiva, i dess upplösning utan att starta om scenen. Bilder föreslås, annars Dokument. Blockering av skärmsläckaren under animation hindrar den från att starta när animationen är synlig och inte pausad. Hastighet noll är inte paus. Installation från EXE packar upp den medföljande SCR-filen och väljer den som Windows-skärmsläckare. Installation och avinstallation kan kräva administratörsgodkännande; statusfältet visar åtgärden tills den är klar. Om borttagning blockeras, stäng den körande skärmsläckaren, dess inställningar och Windows-förhandsvisningen.

### Windows-skärmsläckare

GameOfLife.scr använder alla skärmar med inställningar åtskilda från EXE. Förhandsvisning startar fullskärmsanimation med inställningarna öppna. Den lilla Windows-förhandsvisningen förminskar hela världen. OK sparar; Avbryt eller Esc förkastar ändringar. Musrörelse eller en tangent avslutar skärmsläckaren i helskärm. MP4-inspelning finns i EXE.

### Fönsterplacering och tillstånd

Vid stängning sparas huvudfönstrets och Om-fönstrets placering separat; för Hjälp även storlek och normalt eller maximerat tillstånd före eventuell minimering. Detta är oberoende av att programinställningar bekräftas. När programmet avslutas stängs även Hjälp och Om.

### Rendering och mönsterlicenser

Utveckling och synliga jämförelser använder Direct3D 11-skuggningsprogram på GPU:n; programvarurendering finns om maskinvaruinitieringen misslyckas. Varje skärm använder den beprövade bildtaktsstyrningen vid sin egen frekvens. MP4 kräver Media Foundation och en H.264-kodare. Mönster kommer från LifeWiki (GFDL 1.2 eller senare) och Alan Hensels samlingar i public domain. Programkoden använder MIT; katalogens meddelanden och licenser är separata.

[Mönsterkällor, licenser och importdetaljer](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### BILDSKÄRMAR

Markeringen av rader avgör vilka skärmar du redigerar och är skild från kryssrutorna som aktiverar animationsutgångarna. Ctrl+A markerar alla skärmar; Ctrl och Skift ändrar markeringen. Alla animationsalternativ och reglage gäller de markerade skärmarna. Markeringen sparas separat för EXE och SCR. Om alla skärmar var markerade inkluderas även nya skärmar. Olika värden på de markerade skärmarna visas med obestämda kryssrutor och punktmönster på alternativknappar, reglagehandtag och knapparna ”Aktivera alla” och ”Inaktivera alla”. Reglagens etiketter visar ett streck i stället för ett gemensamt värde. När du ändrar ett alternativ eller klickar på ett reglage används värdet på alla markerade skärmar.

### ANVÄNDNING

Slå på eller av animationsutgångarna med skärmarnas kryssrutor eller genom att dubbelklicka på deras rader. Varje bildskärm använder en oberoende scen. Skärmbild sparar BMP/GIF/JPEG/PNG/TIFF/WebP och inspelningsknappen startar eller stoppar MP4. Paus stannar animeringen. Programmet installerar eller avinstallerar även den inbyggda skärmsläckaren. Inställningarna sparas fortlöpande. Programmet kan bara köras i en instans åt gången. En ny start återställer det minimerade kontrollfönstret och för det längst fram. Använd Tab och Skift+Tab för att flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett kommando. Esc stänger det aktiva Hjälp- eller Om-fönstret; i kontrollfönstret avslutar det programmet. Paus och blockering av skärmsläckaren gäller hela programmet oavsett markerade skärmar. När blockeringen är på hindras Windows-skärmsläckaren bara medan en synlig animering som inte är pausad visas på minst en skärm.

### SKÄRMBILDER OCH INSPELNING

Skärmbilder och inspelningar använder den första aktiva animeringsskärmen, inte en sammanslagen bild av alla skärmar. BMP/GIF/JPEG/PNG/TIFF/WebP använder Bilder, MP4 Videor; om dessa mappar saknas används Dokument. Knappen Inspelningsinställningar väljer Viewport eller TV. Viewport behåller animeringsskärmens storlek och uppdateringsfrekvens, upp till 60 bilder per sekund. TV erbjuder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9, med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) bilder per sekund. Bildens proportioner bevaras; TV använder progressiv BT.709-video med begränsat omfång och 4:2:0-sampling. Upplösning och bildfrekvens kan bara väljas i TV-läge. Fönstret Inspelningsinställningar kan minimeras och blockerar inte de andra programfönstren. OK sparar valen för nästa MP4-inspelning; Avbryt eller Esc ignorerar obekräftade ändringar. Animeringsutgången på den inspelade skärmen kan inte stängas av under inspelningen; ändringar av andra skärmar stoppar inte inspelningen. Att avsluta programmet under en inspelning kräver bekräftelse eftersom det också avslutar inspelningen.

### FÖRHANDSGRANSKNING OCH ANVÄNDNING

Aktivera förhandsvisning startar en helskärmsvisning på alla bildskärmar. Inställningarna förblir öppna och ändringarna visas direkt. OK sparar inställningarna och Avbryt förkastar ändringarna. Esc eller musrörelse avslutar helskärmsläget. Använd Tab och Skift+Tab för att flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett kommando. Esc i inställningarna motsvarar Avbryt; i Hjälp eller Om stänger det bara det fönstret.

### Systemkrav

Windows 7 till Windows 11 stöder alla funktioner, inklusive BMP/GIF/JPEG/PNG/TIFF/WebP-skärmbilder och MP4-inspelning. För att köra programmet på Windows Vista SP2 måste uppdateringarna KB971512 och KB2117917 installeras. MP4-inspelning fungerar inte på Vista i den aktuella versionen. Visningen kräver Direct3D 11, inte bara en äldre DirectX-körningsmiljö. MP4-inspelning kräver tillgängliga Media Foundation-komponenter och en H.264-kodare. Det fristående programmet kan även köras på Linux via Wine; integrering som skärmsläckare är endast tillgänglig på Windows.

## Bygge

Öppna `DispSavers.slnx` i Visual Studio med MSVC v145 och Windows SDK. Välj `Release | x86` och bygg om lösningen för att skapa `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\GameOfLife.exe`, `Release\GameOfLife.scr`, `Release\SpaceFlight.exe` och `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr`. Ingen x64-konfiguration finns.

Paketera dessa byggresultat genom att köra `PackageRelease.ps1` utan signeringsparametrar. Skriptet använder tillfälliga kopior, ändrar inte filer i `Release` och verifierar endast befintliga giltiga signaturer. Det skapar ett enda arkiv, `DispSavers-<version>-win32.zip`, med `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `GameOfLife\GameOfLife.exe`, `GameOfLife\GameOfLife.scr`, `GameOfLife\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` och `SpaceFlight\license.txt`. Den tidigare ZIP-filen tas bort vid körningens början; ett verifieringsfel förhindrar att ett nytt arkiv skapas.

## Licens

DispSavers tillhandahålls under [MIT-licensen](../license.txt). Copyright © Petr Červinka — FortSoft 2026
