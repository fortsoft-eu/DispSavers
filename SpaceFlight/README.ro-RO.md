# SpaceFlight

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · **Română** · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

Zbor deasupra unei suprafețe ondulate accelerat hardware. Suprafață ondulată infinită; Zbor la distanță — suprafață variabilă. Alegeți exact o animație pentru fiecare monitor. Textură comută între suprafața texturată și modelul de sârmă. Rotirea liberă a camerei schimbă lent direcția privirii în toate cele trei dimensiuni. Pauze și inversări adaugă încetiniri, pauze și inversări ale rotației la intervale aleatorii; zborul înainte continuă. Viteza este 0–1600%. Fiecare monitor are o scenă aleatorie independentă, randată la propria rată de reîmprospătare. Lumina principală, lumina de umplere, lumina ambiantă și lumina de contur pot fi comutate separat pentru ecranele selectate. Iluminarea se aplică doar suprafețelor texturate. Ambele animații oferă Plan, Ondulații sau Pâlnie. Pâlnia atrage camera spre interior de-a lungul unei spirale descendente.

## Comenzi

Selectați unul sau mai multe rânduri din lista monitoarelor. Ctrl+A le selectează pe toate; Ctrl și Shift modifică selecția. Comenzile și glisoarele animației schimbă numai setările monitoarelor selectate. Selectarea unui rând diferă de activarea ieșirii prin caseta sa de selectare. Selecția este reținută separat pentru aplicație și economizor. Dacă erau selectate toate monitoarele, sunt incluse și cele conectate ulterior. Valorile diferite de pe monitoarele selectate sunt indicate prin starea nedeterminată a casetelor de selectare și un model punctat pe butoanele radio, mânerele glisoarelor și butoanele de activare sau dezactivare a tuturor opțiunilor. Etichetele glisoarelor afișează o liniuță în locul unei valori comune. Modificarea unei opțiuni sau clicul pe un glisor aplică acea valoare tuturor monitoarelor selectate.

## Aplicație

Rulați SpaceFlight.exe. Setările se salvează continuu și rulează o singură instanță. Caseta monitorului sau un dublu clic pe rând activează ori dezactivează ieșirea animației. Animația poate fi pusă în pauză și reluată. PNG și MP4 capturează primul monitor de animație activ, nu imaginea combinată a tuturor monitoarelor. Monitorul înregistrat nu poate fi dezactivat; închiderea aplicației în timpul înregistrării necesită confirmare. Pauza și blocarea economizorului se aplică întregii aplicații, indiferent de selecția monitoarelor. Când blocarea este activată, economizorul Windows este împiedicat numai cât timp pe cel puțin un monitor este vizibilă o animație care nu este în pauză. Aplicația poate instala sau dezinstala economizorul încorporat.

În setările de înregistrare alegeți Viewport sau TV. Viewport păstrează dimensiunile și rata de reîmprospătare a monitorului, până la 60 de cadre pe secundă. TV oferă 1920 × 1080, 1440 × 1080 sau 1280 × 720 în 16:9, la 50, 25, 59.94 (60000/1001) sau 29.97 (30000/1001) cadre pe secundă. Videoul TV este progresiv BT.709, cu interval limitat și subeșantionare cromatică 4:2:0. Proporțiile imaginii se păstrează, iar benzile de completare sunt negre. OK salvează opțiunile pentru următoarea înregistrare; Anulare sau Esc renunță la schimbările neconfirmate. Ferestrele de înregistrare, ajutor și informații nu blochează celelalte ferestre și pot fi minimizate. Tab și Shift+Tab mută focalizarea, Enter activează butonul focalizat, iar Esc închide fereastra auxiliară activă.

## Economizor de ecran

Folosiți SpaceFlight.scr drept economizor de ecran Windows, cu setări separate de aplicație. Previzualizarea pe tot ecranul permite ajustări în timp real. OK salvează modificările; Anulare sau Esc le anulează. Ieșiți din economizor apăsând o tastă sau mișcând mouse-ul.

## Cerințe de sistem

Windows 7–11 acceptă toate funcțiile. Pentru Windows Vista SP2 trebuie instalate actualizările KB971512 și KB2117917; înregistrarea MP4 nu funcționează pe Vista. Este necesar Direct3D 11, iar pentru MP4 și Media Foundation și un codificator H.264. Interfața și documentația sunt disponibile în 36 de limbi.

## Compilare și împachetare

Deschideți DispSavers.slnx în Visual Studio și compilați Release | x86 cu MSVC v145 și Windows SDK. În pagina Signing a proiectului configurați certificatul și serverul obligatoriu de marcă temporală RFC 3161; datele personale rămân în fișierul ignorat .vcxproj.user. SCR semnat și marcat temporal este încorporat în EXE, apoi este semnat și EXE. PackageRelease.ps1 creează arhiva comună `DispSavers-<version>-win32.zip` fără a modifica fișierele binare din Release.

## Licență

[MIT](license.txt) — Copyright © Petr Červinka — FortSoft 2026
