# SpaceFlight

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · **Lietuvių** · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

Aparatine įranga spartinamas skrydis virš banguojančio paviršiaus. Begalinė banguojanti plokštuma; Tolimas skrydis — kintantis paviršius. Kiekvienam monitoriui pasirinkite vieną animaciją. Tekstūros langelis perjungia tekstūruotą paviršių ir vielinį modelį. Laisvas kameros sukimasis lėtai keičia žiūrėjimo kryptį visose trijose dimensijose. Sustojimai ir krypties keitimai prideda atsitiktinį lėtėjimą, pauzes ir sukimosi krypties keitimą; skrydis pirmyn tęsiasi. Galimas 0–1600% greitis. Kiekvienas monitorius turi nepriklausomą atsitiktinę sceną, atvaizduojamą jo atnaujinimo dažniu.

## Valdymas

Monitorių sąraše pasirinkite vieną ar kelias eilutes. Ctrl+A pasirenka visas, o Ctrl ir Shift leidžia keisti pasirinkimą. Animacijos valdikliai ir slankikliai keičia tik pasirinktų monitorių nuostatas. Eilutės pasirinkimas nėra tas pats, kas animacijos išvesties įjungimas jos žymimuoju langeliu. Pasirinkimas atskirai įsimenamas programai ir užsklandai. Jei buvo pasirinkti visi monitoriai, į pasirinkimą įtraukiami ir naujai prijungti monitoriai.

## Programa

Paleiskite SpaceFlight.exe. Nuostatos išsaugomos nuolat, veikia tik vienas programos egzempliorius. Monitoriaus langelis arba dvigubas eilutės spustelėjimas įjungia ar išjungia animacijos išvestį. Animaciją galima pristabdyti ir tęsti. PNG ir MP4 fiksuoja pirmą aktyvų animacijos monitorių, o ne bendrą visų monitorių vaizdą. Įrašomo monitoriaus išjungti negalima; uždarant programą vykstant įrašymui reikia patvirtinimo. Užsklandos blokavimas yra bendras ir galioja tik kol monitoriuje su įjungta šia nuostata matoma nepristabdyta animacija. Programa gali įdiegti ir pašalinti į ją įtrauktą užsklandą.

Įrašymo nuostatose pasirinkite Viewport arba TV. Viewport išsaugo monitoriaus matmenis ir dažnį iki 60 kadrų per sekundę. TV siūlo 1920 × 1080, 1440 × 1080 arba 1280 × 720 išvestį 16:9 santykiu bei 50, 25, 59.94 (60000/1001) arba 29.97 (30000/1001) kadrų per sekundę. TV vaizdas progresinis, BT.709, riboto diapazono ir 4:2:0 spalvų diskretizavimo. Vaizdo proporcijos išlieka, užpildymo juostos juodos. OK pritaiko nuostatas kitam įrašui, Atšaukti arba Esc atmeta nepatvirtintus pakeitimus. Įrašymo, žinyno ir informacijos langai neblokuoja kitų langų ir gali būti sumažinti. Tab ir Shift+Tab keičia įvesties vietą, Enter paspaudžia aktyvų mygtuką, Esc uždaro aktyvų papildomą langą.

## Ekrano užsklanda

Naudokite SpaceFlight.scr kaip Windows ekrano užsklandą. Jos nuostatos atskiros nuo programos. Viso ekrano peržiūra leidžia jas keisti vykstant animacijai. OK išsaugo, Atšaukti arba Esc atmeta pakeitimus. Užsklandą užbaikite klavišu arba pajudindami pelę.

## Sistemos reikalavimai

Windows 7–11 palaiko visas funkcijas. Windows Vista SP2 būtina įdiegti naujinimus KB971512 ir KB2117917; MP4 įrašymas Vistoje neveikia. Reikalingas Direct3D 11 palaikymas, o MP4 įrašymui Media Foundation ir H.264 koduotuvas. Sąsaja ir dokumentacija pateikiamos 36 kalbomis.

## Kompiliavimas ir pakavimas

Atidarykite DispSavers.slnx Visual Studio ir kompiliuokite Release | x86 su MSVC v145 ir Windows SDK. Projekto Signing puslapyje nurodykite sertifikatą ir privalomą RFC 3161 laiko žymos serverį; asmeninės reikšmės lieka ignoruojamame .vcxproj.user faile. Pasirašytas SCR su laiko žyma įtraukiamas į EXE, tada pasirašomas ir EXE. PackageRelease.ps1 sukuria bendrą `DispSavers-<version>-win32.zip` archyvą nekeisdamas Release dvejetainių failų.

## Licencija

[MIT](license.txt) — Copyright © Petr Červinka — FortSoft 2026
