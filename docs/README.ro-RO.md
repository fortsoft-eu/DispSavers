# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · **Română** · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Animație de corpuri tridimensionale accelerată hardware.

FlyingSolids afișează corpuri tridimensionale care se deplasează, se rotesc și se ciocnesc. Alegeți observarea spațiului sau zborul prin spațiu și activați corpurile dorite. Pentru fiecare monitor puteți seta separat viteza obiectelor și a camerei între 0–1600%, dimensiunea între 50–200% și 1–10 copii ale fiecărui corp. Lumina principală, de umplere, ambiantă și de contur se controlează independent.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Zbor între suprafețe deformabile accelerat hardware.

Zbor între suprafețe deformabile accelerat hardware. Zbor între patru suprafețe deformabile; Zbor printr-o pâlnie deformabilă. Alegeți exact o animație pentru fiecare monitor. Textură comută între suprafața texturată și modelul de sârmă. Rotirea liberă a camerei schimbă lent direcția privirii în toate cele trei dimensiuni. Pauze și inversări adaugă încetiniri, pauze și inversări ale rotației la intervale aleatorii; zborul înainte continuă. Viteza este 0–1600%. Fiecare monitor are o scenă aleatorie independentă, randată la propria rată de reîmprospătare. Lumina principală, lumina de umplere, lumina ambiantă și lumina de contur pot fi comutate separat pentru ecranele selectate. Iluminarea se aplică doar suprafețelor texturate.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Zbor deasupra unei suprafețe ondulate accelerat hardware.

SpaceFlight: Suprafață ondulată infinită; Zbor la distanță — suprafață variabilă; Zbor prin spațiul curbat gravitațional. Alegeți exact o animație pentru fiecare monitor. Textură comută între suprafața texturată și modelul de sârmă. Rotirea liberă a camerei schimbă lent direcția privirii în toate cele trei dimensiuni. Pauze și inversări adaugă încetiniri, pauze și inversări ale rotației la intervale aleatorii; zborul înainte continuă. Viteza este 0–1600%. Fiecare monitor are o scenă aleatorie independentă, randată la propria rată de reîmprospătare. Lumina principală, lumina de umplere, lumina ambiantă și lumina de contur pot fi comutate separat pentru ecranele selectate. Iluminarea se aplică doar suprafețelor texturate. Cele două animații de suprafețe oferă Plan, Ondulații sau Pâlnie. Pâlnia atrage camera spre interior de-a lungul unei spirale descendente. Zborul prin spațiul curbat gravitațional afișează o rețea tridimensională de linii. Opțiunile pentru textură, forma suprafeței și iluminare se aplică numai celor două animații de suprafețe.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Jocul vieții al lui Conway într-o lume comună mai multor ecrane.

### Reguli

Jocul vieții al lui Conway folosește B3/S23. O celulă moartă se naște cu exact trei vecine vii; una vie supraviețuiește cu două sau trei. Cele opt vecine includ diagonalele. Toate se schimbă simultan. Marginile opuse se unesc: stânga cu dreapta, sus cu jos.

### Ecrane și lume comună

Bifele din EXE activează ecranele; setările se aplică lumii comune. Un singur ecran activ cuprinde întreaga lume. La alegerea unei părți a configurației, rândurile și coloanele complet goale sunt eliminate: ecranele stâng și drept se unesc când cel central este oprit. Golurile interioare imposibil de eliminat rămân în simulare. Alegerea tuturor ecranelor sau folosirea SCR păstrează dreptunghiul desktopului și spațiile invizibile. Fiecare ecran arată regiunea sa din aceeași simulare.

### Stare inițială și modele

Pornirea implicită este zgomot aleatoriu cu 25 % celule vii. Densitatea inițială 0–100 % se aplică la următoarea repornire. Doar modele cunoscute folosește 4 106 modele incluse fără zgomot și dezactivează densitatea. Alegeți un amestec sau un nume; dimensiunile sunt în celule. Tastați pentru căutare. Sunt oferite numai modelele care încap complet. Cele mici verificate se repetă în copii separate; cele mari sau complexe apar o dată în centru. Micșorarea lumii poate înlocui alegerea prea mare cu un amestec. Schimbarea modului sau modelului creează altă scenă. Repornirile păstrează alegerea; catalogul funcționează offline.

### Celule, grilă și culori

Fără grilă, dimensiunea este 1–64 px. Grila adaugă o margine de 1 px în spațierea existentă: valoarea afișată și glisorul scad cu unu, cu 1–63 utilizabili. Dezactivarea restabilește valoarea. Glisorul păstrează intervalul și revine din capătul indisponibil; bifa rămâne activă. Comutarea păstrează scena, exceptând activarea la 1 px: spațierea devine 2 px și scena reîncepe. Schimbarea dimensiunii sau ecranelor reîncepe de asemenea. Lumile foarte mari pot impune un minim mai mare. Culorile celulelor, fundalului și grilei se schimbă separat fără repornire. Culoarea aleatorie a celulelor vii se schimbă la fiecare repornire manuală sau automată a scenei. Culoarea salvată se păstrează și revine la dezactivarea opțiunii. Același comportament poate fi activat separat pentru fundal și grilă; ambele opțiuni noi sunt inițial dezactivate.

### Viteză, pauză și repornire automată

Viteza este 0–240 generații/s, independent de reîmprospătare; 0 oprește evoluția. Pauză și Reluare păstrează lumea. Repornire începe din nou în modul ales. Repornirea automată opțională recunoaște faze vizibile statice sau exact repetate, inclusiv oscilatori. Compară generații, nu secunde; exclude zonele invizibile. Rezultatele asincrone pot întârzia puțin repornirea. Implicit: spațiere 8 px, 20 generații/s, culoare aleatorie a celulelor vii și repornire automată activate. Grila este dezactivată implicit. Viteza atinsă depinde de performanță și de numărul celulelor. Repornirea automată compară regiunile ecranelor activate; spațiile dintre ele continuă să evolueze, dar sunt excluse din comparație.

### Resetează valorile

Resetarea stabilește dimensiunea afișată a celulei la 8 px cu sau fără grilă (spațiere de 9 sau 8 px), viteza la 20 generații/s, densitatea la 25 % și cele trei culori implicite. Celelalte alegeri se păstrează; un model care nu mai încape este înlocuit cu amestecul. O scenă nouă apare numai dacă se schimbă spațierea sau densitatea în modul zgomot.

### Aplicație independentă și înregistrare MP4

EXE salvează setările continuu și înregistrează primul ecran activ în MP4. Propune Videoclipuri, alternativ Documente. Viewport folosește dimensiunile și rata ecranului până la 60 cadre/s. TV oferă 1920 × 1080, 1440 × 1080 sau 1280 × 720 în 16:9 la 50, 25, 59,94 (60000/1001) sau 29,97 (30000/1001) cadre/s. Proporțiile rămân; TV folosește BT.709 progresiv cu interval limitat și 4:2:0. Fereastra independentă de setări poate fi minimizată. OK salvează pentru următoarea înregistrare; Anulare sau Esc renunță la modificările neconfirmate. Ecranul înregistrat nu poate fi dezactivat; celelalte ieșiri pot fi schimbate. Ieșirea în timpul înregistrării cere confirmare. Cu focalizarea pe animație, Spațiu comută pauza, F9: Pornire înregistrare; F10: Oprire înregistrare. Cursorul dispare după 1 secundă inactivă și revine la mișcare. Tab/Shift+Tab parcurge controalele; Alt activează comenzile subliniate. Esc închide Ajutor/Despre sau iese din fereastra principală. Economizor de ecran Windows… deschide setările economizorului de ecran al sistemului.

### Captură și administrarea economizorului în EXE

Captura salvează un PNG al ecranului înregistrat sau, în lipsa înregistrării, al primului ecran activ, la rezoluția sa și fără repornirea scenei. Se propune folderul Imagini, alternativ Documente. Blocarea economizorului în timpul animației împiedică pornirea sa cât timp animația este vizibilă și nu este în pauză. Viteza zero nu înseamnă pauză. Instalarea din EXE extrage SCR-ul inclus și îl selectează drept economizor Windows. Instalarea și dezinstalarea pot necesita aprobarea administratorului; bara de stare indică operația până la încheiere. Dacă eliminarea este blocată, închideți economizorul activ, setările sale și previzualizarea Windows.

### Economizor de ecran Windows

GameOfLife.scr folosește toate ecranele, cu setări separate de EXE. Activarea previzualizării pornește animația pe tot ecranul cu setările deschise. Mica previzualizare Windows micșorează lumea întreagă. OK salvează; Anulare sau Esc renunță la schimbări. Mișcarea mouse-ului sau o tastă închide economizorul pe tot ecranul. Înregistrarea MP4 este disponibilă în EXE.

### Poziția și starea ferestrelor

La închidere se salvează separat pozițiile ferestrelor principală și Despre; pentru Ajutor, și dimensiunea și starea normală sau maximizată dinaintea minimizării. Acest lucru este independent de confirmarea setărilor aplicației. Ieșirea din aplicație închide și Ajutor și Despre.

### Randare și licențele modelelor

Evoluția și comparațiile vizibile folosesc shadere Direct3D 11 pe GPU; randarea software este disponibilă dacă inițializarea hardware eșuează. Fiecare ecran folosește regulatorul de cadre verificat la rata sa. MP4 necesită Media Foundation și un codor H.264. Modelele provin din LifeWiki (GFDL 1.2 sau ulterioară) și colecțiile din domeniul public ale lui Alan Hensel. Codul are licență MIT; notificările și licențele catalogului sunt separate.

[Sursele modelelor, licențe și detalii de import](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### MONITOARE

Selectați unul sau mai multe rânduri din lista monitoarelor. Ctrl+A le selectează pe toate; Ctrl și Shift modifică selecția. Comenzile și glisoarele animației schimbă numai setările monitoarelor selectate. Selectarea unui rând diferă de activarea ieșirii prin caseta sa de selectare. Selecția este reținută separat pentru aplicație și economizor. Dacă erau selectate toate monitoarele, sunt incluse și cele conectate ulterior. Valorile diferite de pe monitoarele selectate sunt indicate prin starea nedeterminată a casetelor de selectare și un model punctat pe butoanele radio, mânerele glisoarelor și butoanele „Activare toate” și „Dezactivare toate”. Etichetele glisoarelor afișează o liniuță în locul unei valori comune. Modificarea unei opțiuni sau clicul pe un glisor aplică acea valoare tuturor monitoarelor selectate.

### COMENZI

Rulați FlightCorridor.exe. Setările se salvează continuu și rulează o singură instanță. Caseta monitorului sau un dublu clic pe rând activează ori dezactivează ieșirea animației. Animația poate fi pusă în pauză și reluată. PNG și MP4 capturează primul monitor de animație activ, nu imaginea combinată a tuturor monitoarelor. Ieșirea animației pe monitorul înregistrat nu poate fi dezactivată în timpul înregistrării; închiderea aplicației în timpul înregistrării necesită confirmare. Pauza și blocarea economizorului se aplică întregii aplicații, indiferent de selecția monitoarelor. Când blocarea este activată, economizorul Windows este împiedicat numai cât timp pe cel puțin un monitor este vizibilă o animație care nu este în pauză. Aplicația poate instala sau dezinstala economizorul încorporat.

### CAPTURI ȘI ÎNREGISTRARE

În setările de înregistrare alegeți Viewport sau TV. Viewport păstrează dimensiunile și rata de reîmprospătare a monitorului, până la 60 de cadre pe secundă. TV oferă 1920 × 1080, 1440 × 1080 sau 1280 × 720 în 16:9, la 50, 25, 59.94 (60000/1001) sau 29.97 (30000/1001) cadre pe secundă. Videoul TV este progresiv BT.709, cu interval limitat și subeșantionare cromatică 4:2:0. Proporțiile imaginii se păstrează, iar benzile de completare sunt negre. OK salvează opțiunile pentru următoarea înregistrare; Anulare sau Esc renunță la schimbările neconfirmate. Ferestrele de înregistrare, ajutor și informații nu blochează celelalte ferestre și pot fi minimizate. Tab și Shift+Tab mută focalizarea, Enter activează butonul focalizat, iar Esc închide fereastra auxiliară activă.

### PREVIZUALIZARE ȘI COMENZI

Folosiți FlightCorridor.scr drept economizor de ecran Windows, cu setări separate de aplicație. Previzualizarea pe tot ecranul permite ajustări în timp real. OK salvează modificările; Anulare sau Esc le anulează. Ieșiți din economizor apăsând o tastă sau mișcând mouse-ul.

### Cerințe de sistem

Windows 7–11 acceptă toate funcțiile. Pentru Windows Vista SP2 trebuie instalate actualizările KB971512 și KB2117917; înregistrarea MP4 nu funcționează pe Vista. Este necesar Direct3D 11, iar pentru MP4 și Media Foundation și un codificator H.264. Interfața și documentația sunt disponibile în 36 de limbi. Aplicația independentă poate rula și pe Linux prin Wine; integrarea ca economizor de ecran este disponibilă numai pe Windows.

## Compilare și împachetare

Deschideți DispSavers.slnx în Visual Studio și compilați Release | x86 cu MSVC v145 și Windows SDK. În pagina Signing a proiectului configurați certificatul și serverul obligatoriu de marcă temporală RFC 3161; datele personale rămân în fișierul ignorat .vcxproj.user. SCR semnat și marcat temporal este încorporat în EXE, apoi este semnat și EXE. PackageRelease.ps1 creează arhiva comună `DispSavers-<version>-win32.zip` fără a modifica fișierele binare din Release.

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

## Licență

[MIT](../license.txt) — Copyright © Petr Červinka — FortSoft 2026
