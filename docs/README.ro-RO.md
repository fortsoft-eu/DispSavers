# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · **Română** · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlyingSolids afișează corpuri tridimensionale care se deplasează, se rotesc și se ciocnesc. Alegeți observarea spațiului sau zborul prin spațiu și activați corpurile dorite. Pentru fiecare monitor puteți seta separat viteza obiectelor și a camerei între 0–1600%, dimensiunea între 50–200% și 1–10 copii ale fiecărui corp. Lumina principală, de umplere, ambiantă și de contur se controlează independent.

## Comenzi

Selectați unul sau mai multe rânduri din lista monitoarelor. Ctrl+A le selectează pe toate; Ctrl și Shift modifică selecția. Comenzile și glisoarele animației schimbă numai setările monitoarelor selectate. Selectarea unui rând diferă de activarea ieșirii prin caseta sa de selectare. Selecția este reținută separat pentru aplicație și economizor. Dacă erau selectate toate monitoarele, sunt incluse și cele conectate ulterior.

## Aplicație

Rulați FlyingSolids.exe. Setările se salvează continuu și rulează o singură instanță. Caseta monitorului sau un dublu clic pe rând activează ori dezactivează ieșirea animației. Animația poate fi pusă în pauză și reluată. PNG și MP4 capturează primul monitor de animație activ, nu imaginea combinată a tuturor monitoarelor. Monitorul înregistrat nu poate fi dezactivat; închiderea aplicației în timpul înregistrării necesită confirmare. Blocarea economizorului se aplică întregii sesiuni și numai cât timp pe un monitor cu această opțiune este vizibilă o animație care nu este în pauză. Aplicația poate instala sau dezinstala economizorul încorporat.

În setările de înregistrare alegeți Viewport sau TV. Viewport păstrează dimensiunile și rata de reîmprospătare a monitorului, până la 60 de cadre pe secundă. TV oferă 1920 × 1080, 1440 × 1080 sau 1280 × 720 în 16:9, la 50, 25, 59.94 (60000/1001) sau 29.97 (30000/1001) cadre pe secundă. Videoul TV este progresiv BT.709, cu interval limitat și subeșantionare cromatică 4:2:0. Proporțiile imaginii se păstrează, iar benzile de completare sunt negre. OK salvează opțiunile pentru următoarea înregistrare; Anulare sau Esc renunță la schimbările neconfirmate. Ferestrele de înregistrare, ajutor și informații nu blochează celelalte ferestre și pot fi minimizate. Tab și Shift+Tab mută focalizarea, Enter activează butonul focalizat, iar Esc închide fereastra auxiliară activă.

## Economizor de ecran

Folosiți FlyingSolids.scr drept economizor de ecran Windows, cu setări separate de aplicație. Previzualizarea pe tot ecranul permite ajustări în timp real. OK salvează modificările; Anulare sau Esc le anulează. Ieșiți din economizor apăsând o tastă sau mișcând mouse-ul.

## Cerințe de sistem

Windows 7–11 acceptă toate funcțiile. Pentru Windows Vista SP2 trebuie instalate actualizările KB971512 și KB2117917; înregistrarea MP4 nu funcționează pe Vista. Este necesar Direct3D 11, iar pentru MP4 și Media Foundation și un codificator H.264. Interfața și documentația sunt disponibile în 36 de limbi.

## Compilare și împachetare

Deschideți DispSavers.slnx în Visual Studio și compilați Release | x86 cu MSVC v145 și Windows SDK. În pagina Signing a proiectului configurați certificatul și serverul obligatoriu de marcă temporală RFC 3161; datele personale rămân în fișierul ignorat .vcxproj.user. SCR semnat și marcat temporal este încorporat în EXE, apoi este semnat și EXE. PackageRelease.ps1 creează arhiva comună `DispSavers-<version>-win32.zip` fără a modifica fișierele binare din Release.

## Corpuri geometrice

Cub; Piramidă patrulateră regulată; Trunchi de piramidă patrulateră; Piramidă patrulateră secționată oblic; Piramidă secționată perpendicular pe bază; Prismă triunghiulară regulată; Prismă pentagonală regulată; Prismă hexagonală regulată; Octaedru regulat; Bipiramidă pentagonală; Con circular drept; Trunchi de con; Con secționat oblic; Con secționat perpendicular pe bază; Cilindru circular drept; Cilindru circular gol; Cilindru gol cu capete toroidale; Paraboloid de rotație închis cu un plan; Sferă; Emisferă; Calotă sferică; Calotă sferică mare; Segment sferic cu două baze; Elipsoid triaxial; Elipsoid de rotație alungit; Elipsoid de rotație turtit; Ovoid; Sferocilindru; Disc rotunjit (spheroplatelet); Tor.

## Licență

[MIT](../license.txt) — Copyright © Petr Červinka — FortSoft 2026
