# FlightCorridor

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · **Eesti** · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

Riistvarakiirendusega lend muutuvate pindade vahel. Lend nelja muutuva pinna vahel; Lend läbi muutuva lehtri. Valige igale kuvarile täpselt üks animatsioon. Tekstuuri märkeruut vahetab tekstuuriga pinna ja traatmudeli vahel. Kaamera vaba pöörlemine muudab vaatesuunda aeglaselt kõigis kolmes mõõtmes. Peatumised ja suunavahetused lisab sellele juhuslikke aeglustusi, pause ja pöörlemissuuna muutusi; edasilend jätkub. Kiirus on seatav vahemikus 0–1600%. Igal kuvaril on oma sõltumatu juhuslik stseen ja värskendussagedusele vastav renderdus.

## Juhtimine

Valige loendis üks või mitu kuvaririda. Ctrl+A valib kõik read; Ctrl ja Shift võimaldavad valikut muuta. Animatsiooni juhtnupud ja liugurid mõjutavad ainult valitud kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle märkeruuduga väljundi lubamine on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja jaoks eraldi meelde. Kui varem olid valitud kõik kuvarid, kaasatakse ka lisatud kuvarid.

## Rakendus

Käivitage FlightCorridor.exe. Sätteid salvestatakse jooksvalt ning rakendus töötab ühe eksemplarina. Kuvari märkeruut või topeltklõps real lülitab selle animatsiooniväljundi sisse või välja. Animatsiooni saab peatada ja jätkata. PNG-pilt ja MP4-video jäädvustavad esimese aktiivse animatsioonikuvari, mitte kõiki kuvareid koos. Salvestatavat kuvarit ei saa salvestamise ajal välja lülitada; rakenduse sulgemine nõuab siis kinnitust. Ekraanisäästja tõkestamine kehtib ühiselt ja ainult siis, kui vastava valikuga kuvaril on nähtav peatamata animatsioon. Rakendus saab paigaldada ja eemaldada sisseehitatud ekraanisäästja.

Salvestussätetes valige Viewport või TV. Viewport säilitab kuvari mõõtmed ja värskendussageduse kuni 60 kaadrit sekundis. TV pakub 1920 × 1080, 1440 × 1080 või 1280 × 720 väljundit kuvasuhtega 16:9 ning 50, 25, 59.94 (60000/1001) või 29.97 (30000/1001) kaadrit sekundis. TV-video on progressiivne BT.709, piiratud vahemikuga ja 4:2:0 värvialamdiskreetimisega. Pildi kuvasuhe säilib ja täiteribad on mustad. OK rakendab valikud järgmisele salvestusele; Loobu või Esc tühistab kinnitamata muudatused. Salvestussätted, spikker ja teave ei blokeeri teisi aknaid ning neid saab minimeerida. Tab ja Shift+Tab liigutavad fookust, Enter vajutab fookusega nuppu ning Esc sulgeb aktiivse lisaakna.

## Ekraanisäästja

Käivitage FlightCorridor.scr Windowsi ekraanisäästjana. Selle sätted on rakenduse omadest eraldi. Sätete eelvaade lubab täisekraanil animatsiooni jooksvalt muuta. OK salvestab muudatused ning Loobu või Esc tühistab need. Täisekraanil ekraanisäästjast väljumiseks vajutage klahvi või liigutage hiirt.

## Süsteeminõuded

Windows 7–11 toetab kõiki funktsioone. Windows Vista SP2 jaoks tuleb paigaldada värskendused KB971512 ja KB2117917; MP4 salvestamine Vistas ei tööta. Vaja on Direct3D 11 tuge ning MP4 jaoks Media Foundationi ja H.264 kodeerijat. Liides ja dokumentatsioon on saadaval 36 keeles.

## Koostamine ja pakkimine

Avage DispSavers.slnx Visual Studios ja koostage Release | x86. Vaja on MSVC v145 ja Windows SDK-d. Projekti Signing-lehel määratakse sertifikaat ja kohustuslik RFC 3161 ajatempliserver; isiklikud väärtused jäävad ignoreeritud .vcxproj.user-faili. Allkirjastatud ja ajatempliga SCR lisatakse EXE-sse, seejärel allkirjastatakse ka EXE. PackageRelease.ps1 loob `DispSavers-<version>-win32.zip` arhiivi kõigi kolme ekraanisäästja jaoks ega muuda Release-kausta binaarfaile.

## Litsents

[MIT](license.txt) — Copyright © Petr Červinka — FortSoft 2026
