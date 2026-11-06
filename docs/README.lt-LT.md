# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · **Lietuvių** · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Aparatine įranga spartinama erdvinių kūnų animacija.

FlyingSolids rodo judančius, besisukančius ir susiduriančius erdvinius kūnus. Pasirinkite erdvės stebėjimą arba skrydį erdve ir norimus kūnus. Kiekvienam monitoriui atskirai galima nustatyti objektų bei kameros greitį 0–1600%, objektų dydį 50–200% ir 1–10 kiekvieno kūno kopijų. Pagrindinė, užpildanti, aplinkos ir kontūrinė šviesa įjungiamos nepriklausomai.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Aparatine įranga spartinamas skrydis tarp kintančių paviršių.

Aparatine įranga spartinamas skrydis tarp kintančių paviršių. Skrydis tarp keturių kintančių paviršių; Skrydis kintančiu piltuvu. Kiekvienam monitoriui pasirinkite vieną animaciją. Tekstūros langelis perjungia tekstūruotą paviršių ir vielinį modelį. Laisvas kameros sukimasis lėtai keičia žiūrėjimo kryptį visose trijose dimensijose. Pauzės ir apsisukimai prideda atsitiktinį lėtėjimą, pauzes ir sukimosi krypties keitimą; skrydis pirmyn tęsiasi. Galimas 0–1600% greitis. Kiekvienas monitorius turi nepriklausomą atsitiktinę sceną, atvaizduojamą jo atnaujinimo dažniu. Pagrindinę, užpildančią, aplinkos ir kontūrinę šviesą galima atskirai įjungti pasirinktiems ekranams. Apšvietimas taikomas tik tekstūruotiems paviršiams.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Aparatine įranga spartinamas skrydis virš banguojančio paviršiaus.

SpaceFlight: Begalinis banguojantis paviršius; Tolimas skrydis — kintantis paviršius; Skrydis per gravitacijos iškreiptą erdvę. Kiekvienam monitoriui pasirinkite vieną animaciją. Tekstūros langelis perjungia tekstūruotą paviršių ir vielinį modelį. Laisvas kameros sukimasis lėtai keičia žiūrėjimo kryptį visose trijose dimensijose. Pauzės ir apsisukimai prideda atsitiktinį lėtėjimą, pauzes ir sukimosi krypties keitimą; skrydis pirmyn tęsiasi. Galimas 0–1600% greitis. Kiekvienas monitorius turi nepriklausomą atsitiktinę sceną, atvaizduojamą jo atnaujinimo dažniu. Pagrindinę, užpildančią, aplinkos ir kontūrinę šviesą galima atskirai įjungti pasirinktiems ekranams. Apšvietimas taikomas tik tekstūruotiems paviršiams. Abiejose paviršių animacijose galima pasirinkti plokštumą, bangas arba piltuvą. Piltuvas traukia kamerą į vidų žemyn besisukančia spirale. Skrydis per gravitacijos iškreiptą erdvę rodo trimatį karkasinį tinklą. Tekstūros, paviršiaus formos ir apšvietimo parinktys taikomos tik dviem paviršių animacijoms.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Conway gyvybės žaidimas bendrame kelių ekranų pasaulyje.

### Taisyklės

Conway gyvybės žaidimas naudoja B3/S23. Negyvas langelis atgyja turėdamas tiksliai tris gyvus kaimynus; gyvas išlieka su dviem arba trimis. Aštuoni kaimynai apima įstrižaines. Visi langeliai keičiasi vienu metu. Priešingi kraštai sujungti: kairė su dešine, viršus su apačia.

### Ekranai ir bendras pasaulis

EXE žymimieji langeliai įjungia ekranus; nuostatos taikomos bendram pasauliui. Viename įjungtame ekrane telpa visas pasaulis. Pasirinkus dalį ekranų, visiškai tuščios eilutės ir stulpeliai pašalinami: išjungus vidurinį, kairysis ir dešinysis susijungia. Nepašalinamos vidinės skylės lieka simuliacijoje. Pasirinkus visus ekranus arba naudojant SCR išlaikomas darbalaukį apimantis stačiakampis su nematomais tarpais. Kiekvienas ekranas rodo savo tos pačios simuliacijos dalį.

### Pradinė būsena ir konfigūracijos

Numatytoji pradžia – atsitiktinis triukšmas su 25 % gyvų langelių. Pradinis tankis 0–100 % taikomas kitą kartą pradedant iš naujo. Tik žinomos konfigūracijos naudoja 4 106 įtrauktas konfigūracijas be triukšmo ir išjungia tankį. Pasirinkite mišinį arba pavadinimą; matmenys pateikti langeliais. Ieškokite įvesdami pavadinimą. Visos katalogo konfigūracijos visada prieinamos. Mažos patikrintos kartojamos atskiromis kopijomis, didelės ar sudėtingos rodomos vieną kartą centre. Per didelė konfigūracija centruojama ir apkerpama; pakeitus pasaulio ar langelių dydį pasirinkimas išsaugomas. Pakeitus režimą ar konfigūraciją sukuriama nauja scena. Paleidimas iš naujo išlaiko pasirinkimą; katalogas veikia be interneto.

### Langeliai, tinklelis ir spalvos

Be tinklelio dydis yra 1–64 px. Tinklelis prideda 1 px kraštą esamame žingsnyje: rodoma vertė ir slankiklis sumažėja vienetu, naudojama 1–63. Išjungus vertė grąžinama. Slankiklis išlaiko visą diapazoną ir grįžta iš neprieinamo galo; žymimasis langelis lieka aktyvus. Perjungimas išlaiko sceną, išskyrus įjungimą ties 1 px: žingsnis tampa 2 px ir scena pradedama iš naujo. Dydžio ar ekranų keitimas taip pat pradeda iš naujo. Labai didelis pasaulis gali reikalauti didesnio minimumo. Langelių, fono ir tinklelio spalvos keičiamos atskirai nepaleidžiant iš naujo. Atsitiktinė gyvų langelių spalva parenkama per kiekvieną rankinį ar automatinį scenos paleidimą iš naujo. Išsaugota spalva nekeičiama ir atkuriama išjungus šią parinktį. Tokį pat veikimą galima atskirai įjungti fonui ir tinkleliui; abi naujos parinktys iš pradžių išjungtos.

### Greitis, pauzė ir automatinis paleidimas iš naujo

Greitis yra 0–240 kartų/s ir nepriklauso nuo ekrano atnaujinimo; 0 sustabdo raidą. Pauzė ir Tęsti išlaiko pasaulį. Pradėti iš naujo pradeda pasirinktą režimą. Pasirenkamas automatinis paleidimas iš naujo atpažįsta nekintamas ir tiksliai pasikartojančias matomas fazes, taip pat osciliatorius. Lyginamos kartos, ne sekundės; nematomos sritys neįtraukiamos. Asinchroniniai rezultatai gali šiek tiek uždelsti paleidimą. Numatyta: 8 px žingsnis, 20 kartų/s, atsitiktinė gyvų ląstelių spalva ir automatinis paleidimas iš naujo įjungti. Tinklelis pagal numatytuosius nustatymus išjungtas. Pasiekiamas greitis priklauso nuo našumo ir langelių skaičiaus. Automatinis paleidimas iš naujo lygina įjungtų ekranų sritis; tarpai tarp jų vystosi toliau, bet į palyginimą neįtraukiami.

### Atkurti reikšmes

Atkūrimas nustato rodomą langelio dydį į 8 px su tinkleliu arba be jo (žingsnis 9 arba 8 px), greitį į 20 kartų/s, tankį į 25 % ir tris numatytąsias spalvas. Kitos parinktys, įskaitant pasirinktą konfigūraciją, išsaugomos. Nauja scena sukuriama tik pasikeitus žingsniui arba tankiui triukšmo režimu.

### Atskira programa ir MP4 įrašymas

EXE nuolat išsaugo nuostatas ir įrašo pirmą aktyvų ekraną į MP4. Siūlomas aplankas Vaizdo įrašai, kitu atveju Dokumentai. Viewport naudoja ekrano matmenis ir dažnį iki 60 kadrų/s. TV siūlo 1920 × 1080, 1440 × 1080 arba 1280 × 720, 16:9, 50, 25, 59,94 (60000/1001) arba 29,97 (30000/1001) kadrų/s. Proporcijos išlaikomos; TV naudoja progresinį riboto diapazono BT.709 ir 4:2:0. Atskirą nuostatų langą galima sumažinti. Gerai išsaugo kitam įrašymui; Atšaukti arba Esc atmeta nepatvirtintus pakeitimus. Įrašomo ekrano išjungti negalima; kitus išėjimus keisti galima. Išėjimas įrašymo metu prašo patvirtinimo. Kai aktyvi animacija, tarpas perjungia pauzę, F9: Pradėti įrašymą; F10: Baigti įrašymą. Žymeklis pasislepia po 1 sekundės neveiklos ir grįžta pajudinus. Tab/Shift+Tab keičia valdiklį, Alt vykdo pabrauktas komandas. Esc uždaro Žinyną/Apie arba išeina pagrindiniame lange. „Windows“ ekrano užsklanda… atveria sistemos ekrano užsklandos parametrus.

### Momentinė kopija ir užsklandos valdymas EXE

Momentinė kopija išsaugo įrašomo arba, jei neįrašoma, pirmojo aktyvaus ekrano BMP/GIF/JPEG/PNG/TIFF/WebP jo raiška nepaleidžiant scenos iš naujo. Siūlomas aplankas Paveikslėliai, kitu atveju Dokumentai. Užsklandos blokavimas animacijos metu neleidžia jai įsijungti, kol animacija matoma ir nepristabdyta. Nulinis greitis nėra pauzė. Diegimas iš EXE išpakuoja pridėtą SCR ir parenka jį kaip Windows užsklandą. Diegiant ir šalinant gali reikėti administratoriaus leidimo; būsenos juosta rodo veiksmą iki jo pabaigos. Jei šalinimas blokuojamas, uždarykite veikiančią užsklandą, jos nuostatas ir Windows peržiūrą.

### Windows ekrano užsklanda

GameOfLife.scr naudoja visus ekranus ir atskiras nuo EXE nuostatas. Peržiūra paleidžia viso ekrano animaciją palikdama nuostatas atviras. Maža Windows peržiūra sumažina visą pasaulį. Gerai išsaugo; Atšaukti arba Esc atmeta pakeitimus. Pelės judesys ar klavišas uždaro viso ekrano užsklandą. MP4 įrašymas galimas EXE.

### Langų padėtis ir būsena

Uždarant atskirai išsaugomos pagrindinio ir Apie langų padėtys; Žinyno atveju taip pat dydis ir įprasta arba išdidinta būsena prieš sumažinimą. Tai nepriklauso nuo programos nuostatų patvirtinimo. Baigiant programą uždaromi ir Žinyno bei Apie langai.

### Atvaizdavimas ir konfigūracijų licencijos

Raidą ir matomų būsenų palyginimą atlieka GPU Direct3D 11 šešėliavimo programos; nepavykus aparatinei inicijacijai galima programinė atvaizdavimo priemonė. Kiekvienas ekranas naudoja patikrintą kadrų laiko valdymą savo dažniu. MP4 reikia Media Foundation ir H.264 koduotuvo. Konfigūracijos yra iš LifeWiki (GFDL 1.2 ar naujesnė) ir Alan Hensel viešojo naudojimo rinkinių. Programos kodas yra MIT; katalogo pranešimai ir licencijos atskiri.

[Konfigūracijų šaltiniai, licencijos ir importavimo informacija](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### MONITORIAI

Monitorių sąraše pasirinkite vieną ar kelias eilutes. Ctrl+A pasirenka visas, o Ctrl ir Shift leidžia keisti pasirinkimą. Animacijos valdikliai ir slankikliai keičia tik pasirinktų monitorių nuostatas. Eilutės pasirinkimas nėra tas pats, kas animacijos išvesties įjungimas jos žymimuoju langeliu. Pasirinkimas atskirai įsimenamas programai ir užsklandai. Jei buvo pasirinkti visi monitoriai, į pasirinkimą įtraukiami ir naujai prijungti monitoriai. Skirtingas pasirinktų monitorių reikšmes rodo neapibrėžta žymimųjų langelių būsena ir taškinis raštas ant parinkčių mygtukų, slankiklių rankenėlių bei mygtukų „Įjungti visus“ ir „Išjungti visus“. Slankiklių užrašuose vietoj bendros reikšmės rodomas brūkšnys. Pakeitus parinktį arba spustelėjus slankiklį, ta reikšmė pritaikoma visiems pasirinktiems monitoriams.

### VALDYMAS

Paleiskite FlightCorridor.exe. Nuostatos išsaugomos nuolat, veikia tik vienas programos egzempliorius. Monitoriaus langelis arba dvigubas eilutės spustelėjimas įjungia ar išjungia animacijos išvestį. Animaciją galima pristabdyti ir tęsti. BMP/GIF/JPEG/PNG/TIFF/WebP ir MP4 fiksuoja pirmą aktyvų animacijos monitorių, o ne bendrą visų monitorių vaizdą. Įrašymo metu negalima išjungti įrašomo monitoriaus animacijos išvesties; uždarant programą vykstant įrašymui reikia patvirtinimo. Pristabdymas ir užsklandos blokavimas taikomi visai programai, nepriklausomai nuo monitorių pasirinkimo. Įjungus blokavimą, Windows užsklanda neleidžiama tik kol bent viename monitoriuje matoma nepristabdyta animacija. Programa gali įdiegti ir pašalinti į ją įtrauktą užsklandą.

### EKRANO KOPIJOS IR ĮRAŠYMAS

Įrašymo nuostatose pasirinkite Viewport arba TV. Viewport išsaugo monitoriaus matmenis ir atnaujinimo dažnį iki 60 kadrų per sekundę. TV siūlo 1920 × 1080, 1440 × 1080 arba 1280 × 720 išvestį 16:9 santykiu bei 50, 25, 59.94 (60000/1001) arba 29.97 (30000/1001) kadrų per sekundę. TV vaizdas progresinis, BT.709, riboto diapazono ir 4:2:0 spalvų diskretizavimo. Vaizdo proporcijos išlieka, užpildymo juostos juodos. OK pritaiko nuostatas kitam įrašui, Atšaukti arba Esc atmeta nepatvirtintus pakeitimus. Įrašymo, žinyno ir informacijos langai neblokuoja kitų langų ir gali būti sumažinti. Tab ir Shift+Tab keičia įvesties vietą, Enter paspaudžia aktyvų mygtuką, Esc uždaro aktyvų papildomą langą.

### PERŽIŪRA IR VALDYMAS

Naudokite FlightCorridor.scr kaip Windows ekrano užsklandą. Jos nuostatos atskiros nuo programos. Viso ekrano peržiūra leidžia jas keisti vykstant animacijai. OK išsaugo, Atšaukti arba Esc atmeta pakeitimus. Užsklandą užbaikite klavišu arba pajudindami pelę.

### Sistemos reikalavimai

Windows 7–11 palaiko visas funkcijas. Windows Vista SP2 būtina įdiegti naujinimus KB971512 ir KB2117917; MP4 įrašymas Vistoje neveikia. Reikalingas Direct3D 11 palaikymas, o MP4 įrašymui Media Foundation ir H.264 koduotuvas. Sąsaja ir dokumentacija pateikiamos 36 kalbomis. Atskiroji programa taip pat gali veikti Linux sistemoje per Wine; integracija kaip ekrano užsklanda galima tik Windows sistemoje.

## Kompiliavimas ir pakavimas

Atidarykite DispSavers.slnx Visual Studio ir kompiliuokite Release | x86 su MSVC v145 ir Windows SDK. Projekto Signing puslapyje nurodykite sertifikatą ir privalomą RFC 3161 laiko žymos serverį; asmeninės reikšmės lieka ignoruojamame .vcxproj.user faile. Pasirašytas SCR su laiko žyma įtraukiamas į EXE, tada pasirašomas ir EXE. PackageRelease.ps1 sukuria bendrą `DispSavers-<version>-win32.zip` archyvą nekeisdamas Release dvejetainių failų.

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

## Licencija

[MIT](../license.txt) — Copyright © Petr Červinka — FortSoft 2026
