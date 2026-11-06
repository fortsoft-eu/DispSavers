# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · **Eesti** · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Riistvarakiirendusega ruumiliste kehade animatsioon.

FlyingSolids kuvab liikuvaid, pöörlevaid ja põrkuvaid ruumilisi kehi. Valige ruumi vaatlemine või lend läbi ruumi ning soovitud kehad. Iga kuvari jaoks saab eraldi määrata objektide ja kaamera kiiruse 0–1600%, objektide suuruse 50–200% ning iga keha koopiate arvu 1–10. Põhi-, täite-, ümbritsev ja kontuurivalgus on sõltumatult lülitatavad.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Riistvarakiirendusega lend muutuvate pindade vahel.

Riistvarakiirendusega lend muutuvate pindade vahel. Lend nelja muutuva pinna vahel; Lend läbi muutuva lehtri. Valige igale kuvarile täpselt üks animatsioon. Tekstuuri märkeruut vahetab tekstuuriga pinna ja traatmudeli vahel. Kaamera vaba pöörlemine muudab vaatesuunda aeglaselt kõigis kolmes mõõtmes. Pausid ja pöördumised lisavad sellele juhuslikke aeglustusi, pause ja pöörlemissuuna muutusi; edasilend jätkub. Kiirus on seatav vahemikus 0–1600%. Igal kuvaril on oma sõltumatu juhuslik stseen ja värskendussagedusele vastav renderdus. Põhivalgust, täitevalgust, ümbritsevat valgust ja kontuurivalgust saab valitud kuvaritel eraldi sisse ja välja lülitada. Valgustus kehtib ainult tekstuuriga pindadele.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Riistvarakiirendusega lend lainetava pinna kohal.

SpaceFlight: Lõputu lainetav pind; Kauglend — muutuv pind; Lend läbi gravitatsiooniliselt kõverdunud ruumi. Valige igale kuvarile täpselt üks animatsioon. Tekstuuri märkeruut vahetab tekstuuriga pinna ja traatmudeli vahel. Kaamera vaba pöörlemine muudab vaatesuunda aeglaselt kõigis kolmes mõõtmes. Pausid ja pöördumised lisavad sellele juhuslikke aeglustusi, pause ja pöörlemissuuna muutusi; edasilend jätkub. Kiirus on seatav vahemikus 0–1600%. Igal kuvaril on oma sõltumatu juhuslik stseen ja värskendussagedusele vastav renderdus. Põhivalgust, täitevalgust, ümbritsevat valgust ja kontuurivalgust saab valitud kuvaritel eraldi sisse ja välja lülitada. Valgustus kehtib ainult tekstuuriga pindadele. Mõlemas pinnaanimatsioonis saab valida tasandi, lained või lehtri. Lehter tõmbab kaamera mööda laskuvat spiraali sissepoole. Lend läbi gravitatsiooniliselt kõverdunud ruumi näitab kolmemõõtmelist traatvõrku. Tekstuuri, pinna kuju ja valgustuse valikud kehtivad ainult kahe pinnaanimatsiooni jaoks.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Conway elumäng ühes kuvarite ühises maailmas.

### Reeglid

Conway elumäng kasutab B3/S23 reegleid. Surnud lahter sünnib täpselt kolme elusa naabriga; elus lahter jääb ellu kahe või kolmega. Kaheksa naabri hulka kuuluvad diagonaalsed. Kõik lahtrid muutuvad korraga. Vastasservad liituvad: vasak paremaga, ülemine alumisega.

### Kuvarid ja ühine maailm

EXE märkeruudud lülitavad kuvarid sisse; sätted kehtivad ühisele maailmale. Üks sisselülitatud kuvar sisaldab tervet maailma. Osalise valiku korral eemaldatakse täiesti tühjad read ja veerud: keskmise väljalülitamisel liituvad vasak ja parem kuvar. Eemaldamatud sisemised augud jäävad simulatsiooni. Kõigi kuvarite valimine või SCR säilitab töölauda ümbritseva ristküliku koos nähtamatute vahedega. Iga kuvar näitab sama simulatsiooni oma piirkonda.

### Algolek ja mustrid

Vaikimisi algus on juhumüra 25 % elusate lahtritega. Algtihedus 0–100 % rakendub järgmisel taasalustusel. Ainult tuntud mustrid kasutab 4 106 kaasasolevat mustrit ilma mürata ja keelab tiheduse. Valige segu või nimi; mõõtmed on lahtrites. Otsimiseks tippige nimi. Kõik kataloogi mustrid on alati saadaval. Väikesed kontrollitud mustrid korduvad eraldi koopiatena, suured või keerukad ilmuvad üks kord keskele. Liiga suur muster keskendatakse ja kärbitakse; maailma või lahtri suuruse muutmine säilitab valiku. Režiimi või mustri muutmine loob uue stseeni. Taasalustused säilitavad valiku; kataloog töötab võrguta.

### Lahtri suurus, ruudustik ja värvid

Ruudustikuta on lahtri suurus 1–64 px. Ruudustik lisab olemasoleva sammu sisse 1 px serva: näidatav väärtus ja liugur vähenevad ühe võrra, kasutatav on 1–63. Väljalülitamine taastab väärtuse. Liugur säilitab kogu vahemiku ja hüppab keelatud otspunktist tagasi; märkeruut jääb aktiivseks. Lülitamine säilitab stseeni, välja arvatud sisselülitamine 1 px juures: samm kasvab 2 px-ni ja stseen algab uuesti. Suuruse või kuvarite muutmine alustab samuti uuesti. Väga suur maailm võib vajada kõrgemat alampiiri. Lahtrite, tausta ja ruudustiku värvid muutuvad eraldi ilma taasalustuseta. Elusate lahtrite juhuslik värv valitakse igal käsitsi või automaatsel stseeni taasalustamisel uuesti. Salvestatud värv säilib ja taastub valiku väljalülitamisel. Sama käitumise saab eraldi lubada taustale ja ruudustikule; mõlemad uued valikud on vaikimisi väljas.

### Kiirus, paus ja automaatne taasalustus

Kiirus on 0–240 põlvkonda/s kuvari värskendusest sõltumatult; 0 peatab arengu. Paus ja Jätka säilitavad maailma. Alusta uuesti teeb uue alguse valitud režiimis. Valikuline automaatne taasalustus tuvastab püsivad ja täpselt korduvad nähtavad faasid, ka ostsillaatorid. Võrreldakse põlvkondi, mitte sekundeid; nähtamatud alad jäetakse välja. Asünkroonsed tulemused võivad algust veidi viivitada. Vaikimisi: samm 8 px, 20 põlvkonda/s, elusrakkude juhuslik värv ja automaatne taasalustus sees. Ruudustik on vaikimisi välja lülitatud. Saavutatud kiirus sõltub jõudlusest ja lahtrite arvust. Automaatne taasalustus võrdleb sisselülitatud kuvarite piirkondi; nendevahelised tühimikud arenevad edasi, kuid võrdluses ei osale.

### Lähtesta väärtused

Lähtestamine seab kuvatava lahtri suuruseks 8 px ruudustikuga või ilma (samm 9 või 8 px), kiiruseks 20 põlvkonda/s, tiheduseks 25 % ja taastab kolm vaikevärvi. Muud valikud, sealhulgas valitud muster, säilivad. Uus stseen tekib ainult sammu muutumisel või tiheduse muutumisel mürarežiimis.

### Eraldi rakendus ja MP4-salvestus

EXE salvestab sätted jooksvalt ja esimese aktiivse kuvari MP4-ks. Pakutakse kausta Videod, selle puudumisel Dokumendid. Viewport kasutab kuvari mõõtmeid ja kuni 60 kaadrit/s värskendust. TV pakub 1920 × 1080, 1440 × 1080 või 1280 × 720 kuvasuhtega 16:9 ning 50, 25, 59,94 (60000/1001) või 29,97 (30000/1001) kaadrit/s. Kuvasuhe säilib; TV kasutab progressiivset piiratud vahemikuga BT.709 ja 4:2:0. Eraldi sätete akna saab minimeerida. OK salvestab järgmise salvestuse jaoks; Loobu või Esc tühistab kinnitamata muudatused. Salvestatavat kuvarit ei saa välja lülitada; muid väljundeid saab muuta. Väljumine salvestuse ajal nõuab kinnitust. Aktiivses animatsioonis lülitab tühik pausi, F9: Alusta salvestamist; F10: Peata salvestamine. Kursor kaob 1 sekundi tegevusetuse järel ning ilmub liigutamisel. Tab/Shift+Tab liigub juhtelementide vahel, Alt aktiveerib allajoonitud käsud. Esc sulgeb Abi/Teave või väljub peaaknast. Windowsi ekraanisäästja… avab süsteemi ekraanisäästja sätted.

### Hetktõmmis ja ekraanisäästja haldus EXE-s

Hetktõmmis salvestab BMP/GIF/JPEG/PNG/TIFF/WebP salvestatavast kuvarist või muul juhul esimesest aktiivsest kuvarist selle eraldusvõimega, stseeni taasalustamata. Pakutakse kausta Pildid, selle puudumisel Dokumendid. Ekraanisäästja blokeerimine animatsiooni ajal takistab selle käivitumist, kui animatsioon on nähtav ega ole pausil. Nullkiirus ei ole paus. EXE-st paigaldamine pakib kaasasoleva SCR-i lahti ja valib selle Windowsi ekraanisäästjaks. Paigaldamine ja eemaldamine võivad vajada administraatori kinnitust; olekuriba näitab toimingut selle lõpuni. Kui eemaldamine on blokeeritud, sulgege töötav säästja, selle sätted ja Windowsi eelvaade.

### Windowsi ekraanisäästja

GameOfLife.scr kasutab kõiki kuvareid ja EXE-st eraldi sätteid. Eelvaate lubamine käivitab täisekraananimatsiooni avatud sätetega. Väike Windowsi eelvaade vähendab tervet maailma. OK salvestab, Loobu või Esc tühistab muudatused. Hiire liigutamine või klahv sulgeb täisekraanisäästja. MP4-salvestus on saadaval EXE-s.

### Akende asukoht ja olek

Sulgemisel salvestatakse peaakna ja Teabe akna asukohad eraldi; Abi puhul ka suurus ja minimeerimisele eelnenud tavaline või maksimeeritud olek. See ei sõltu rakenduse sätete kinnitamisest. Rakenduse lõpetamine sulgeb ka Abi ja Teabe aknad.

### Renderdus ja mustrite litsentsid

Areng ja nähtavate olekute võrdlus kasutavad GPU Direct3D 11 varjutajaid; riistvara lähtestamise nurjumisel saab kasutada tarkvaralist renderdust. Iga kuvar kasutab kontrollitud kaadriajastust oma värskendussagedusel. MP4 vajab Media Foundationit ja H.264-kodeerijat. Mustrid pärinevad LifeWikist (GFDL 1.2 või uuem) ja Alan Henseli avaliku omandi kogudest. Programmi kood on MIT-litsentsiga; kataloogi teated ja litsentsid on eraldi.

[Mustrite allikad, litsentsid ja impordi üksikasjad](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### KUVARID

Valige loendis üks või mitu kuvaririda. Ctrl+A valib kõik read; Ctrl ja Shift võimaldavad valikut muuta. Animatsiooni juhtnupud ja liugurid mõjutavad ainult valitud kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle märkeruuduga väljundi lubamine on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja jaoks eraldi meelde. Kui varem olid valitud kõik kuvarid, kaasatakse ka lisatud kuvarid. Valitud kuvarite erinevaid väärtusi näitavad märkeruutude määramata olek ning raadionuppude, liugurite käepidemete ja nuppude „Luba kõik” ja „Keela kõik” punktimuster. Liuguri sildil on ühise väärtuse asemel kriips. Valiku muutmine või liuguril klõpsamine määrab selle väärtuse kõigile valitud kuvaritele.

### KASUTAMINE

Käivitage FlightCorridor.exe. Sätteid salvestatakse jooksvalt ning rakendus töötab ühe eksemplarina. Kuvari märkeruut või topeltklõps real lülitab selle animatsiooniväljundi sisse või välja. Animatsiooni saab peatada ja jätkata. BMP/GIF/JPEG/PNG/TIFF/WebP-pilt ja MP4-video jäädvustavad esimese aktiivse animatsioonikuvari, mitte kõiki kuvareid koos. Salvestatava kuvari animatsiooniväljundit ei saa salvestamise ajal välja lülitada; rakenduse sulgemine nõuab siis kinnitust. Peatamine ja ekraanisäästja tõkestamine kehtivad kogu rakendusele, sõltumata kuvarite valikust. Kui tõkestamine on sisse lülitatud, takistatakse Windowsi ekraanisäästjat ainult seni, kuni vähemalt ühel kuvaril on nähtav peatamata animatsioon. Rakendus saab paigaldada ja eemaldada sisseehitatud ekraanisäästja.

### KUVATÕMMISED JA SALVESTAMINE

Salvestussätetes valige Viewport või TV. Viewport säilitab kuvari mõõtmed ja värskendussageduse kuni 60 kaadrit sekundis. TV pakub 1920 × 1080, 1440 × 1080 või 1280 × 720 väljundit kuvasuhtega 16:9 ning 50, 25, 59.94 (60000/1001) või 29.97 (30000/1001) kaadrit sekundis. TV-video on progressiivne BT.709, piiratud vahemikuga ja 4:2:0 värvialamdiskreetimisega. Pildi kuvasuhe säilib ja täiteribad on mustad. OK rakendab valikud järgmisele salvestusele; Loobu või Esc tühistab kinnitamata muudatused. Salvestussätted, spikker ja teave ei blokeeri teisi aknaid ning neid saab minimeerida. Tab ja Shift+Tab liigutavad fookust, Enter vajutab fookusega nuppu ning Esc sulgeb aktiivse lisaakna.

### EELVAADE JA KASUTAMINE

Käivitage FlightCorridor.scr Windowsi ekraanisäästjana. Selle sätted on rakenduse omadest eraldi. Sätete eelvaade lubab täisekraanil animatsiooni jooksvalt muuta. OK salvestab muudatused ning Loobu või Esc tühistab need. Täisekraanil ekraanisäästjast väljumiseks vajutage klahvi või liigutage hiirt.

### Süsteeminõuded

Windows 7–11 toetab kõiki funktsioone. Windows Vista SP2 jaoks tuleb paigaldada värskendused KB971512 ja KB2117917; MP4 salvestamine Vistas ei tööta. Vaja on Direct3D 11 tuge ning MP4 jaoks Media Foundationi ja H.264 kodeerijat. Liides ja dokumentatsioon on saadaval 36 keeles. Eraldiseisev rakendus võib Wine’i kaudu töötada ka Linuxis; ekraanisäästja integratsioon on saadaval ainult Windowsis.

## Koostamine ja pakkimine

Avage DispSavers.slnx Visual Studios ja koostage Release | x86. Vaja on MSVC v145 ja Windows SDK-d. Projekti Signing-lehel määratakse sertifikaat ja kohustuslik RFC 3161 ajatempliserver; isiklikud väärtused jäävad ignoreeritud .vcxproj.user-faili. Allkirjastatud ja ajatempliga SCR lisatakse EXE-sse, seejärel allkirjastatakse ka EXE. PackageRelease.ps1 loob `DispSavers-<version>-win32.zip` arhiivi kõigi nelja ekraanisäästja jaoks ega muuda Release-kausta binaarfaile.

```text
Release\FlyingSolids.exe
Release\FlyingSolids.scr
Release\FlightCorridor.exe
Release\FlightCorridor.scr
Release\GameOfLife.exe
Release\GameOfLife.scr
Release\SpaceFlight.exe
Release\SpaceFlight.scr
```

`PackageRelease.ps1` → `DispSavers-<version>-win32.zip`:

```text
GameOfLife\GameOfLife.exe
GameOfLife\GameOfLife.scr
GameOfLife\license.txt
```

## Litsents

[MIT](../license.txt) — Copyright © Petr Červinka — FortSoft 2026
