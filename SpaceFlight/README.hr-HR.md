# SpaceFlight

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · **Hrvatski** · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

SpaceFlight: Beskonačna valovita ploha; Daleki let — promjenjiva ploha; Let kroz gravitacijski zakrivljen prostor. Za svaki zaslon odaberite točno jednu animaciju. Tekstura mijenja prikaz između teksturirane plohe i žičanog modela. Slobodno okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, stanke i promjene smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki zaslon ima neovisnu nasumičnu scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje samo na teksturirane površine. Obje animacije površina nude ravninu, valove ili lijevak. Lijevak uvlači kameru prema unutra duž silazne spirale. Let kroz gravitacijski zakrivljen prostor prikazuje trodimenzionalnu žičanu mrežu. Opcije teksture, oblika površine i osvjetljenja odnose se samo na dvije animacije površina.

## Upravljanje

Odaberite jedan ili više redaka na popisu zaslona. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije mijenjaju samo postavke odabranih zaslona. Odabir retka nije isto što i uključivanje izlaza njegovim potvrdnim okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar zaslona. Ako su prethodno bili odabrani svi zasloni, uključuju se i novopriključeni zasloni. Različite vrijednosti na odabranim zaslonima prikazuju se neodređenim stanjem potvrdnih okvira i točkastim uzorkom na izbornim gumbima, ručkama klizača i gumbima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju crticu umjesto zajedničke vrijednosti. Promjena mogućnosti ili klik na klizač primjenjuje tu vrijednost na sve odabrane zaslone.

## Aplikacija

Pokrenite SpaceFlight.exe. Postavke se neprekidno spremaju i radi samo jedna instanca aplikacije. Potvrdni okvir zaslona ili dvostruki klik na redak uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe prvi aktivni zaslon animacije, ne zajedničku sliku svih zaslona. Animacijski izlaz snimanog zaslona ne možete isključiti tijekom snimanja; zatvaranje aplikacije tijekom snimanja zahtijeva potvrdu. Pauza i blokada čuvara zaslona vrijede za cijelu aplikaciju, bez obzira na odabir zaslona. Kada je blokada uključena, čuvar zaslona sustava Windows sprječava se samo dok je na barem jednom zaslonu vidljiva animacija koja nije pauzirana. Aplikacija može instalirati i deinstalirati ugrađeni čuvar zaslona.

U postavkama snimanja odaberite Viewport ili TV. Viewport zadržava dimenzije i frekvenciju osvježavanja zaslona do 60 sličica u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u omjeru 16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) sličica u sekundi. TV video je progresivni BT.709 ograničenog raspona s poduzorkovanjem boje 4:2:0. Omjer slike ostaje sačuvan, a dopunske trake su crne. OK sprema mogućnosti za sljedeću snimku; Odustani ili Esc odbacuje nepotvrđene izmjene. Prozori snimanja, pomoći i informacija ne blokiraju ostale prozore i mogu se minimizirati. Tab i Shift+Tab pomiču fokus, Enter aktivira fokusirani gumb, a Esc zatvara aktivni pomoćni prozor.

## Čuvar zaslona

Koristite SpaceFlight.scr kao Windows čuvar zaslona s odvojenim postavkama. Pretpregled preko cijelog zaslona omogućuje izmjene uživo. OK sprema, a Odustani ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili pomicanjem miša.

## Sistemski zahtjevi

Windows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media Foundation te H.264 koder. Sučelje i dokumentacija dostupni su na 36 jezika. Samostalna aplikacija može raditi i na Linuxu putem Winea; integracija kao čuvar zaslona dostupna je samo na Windowsu.

## Prevođenje i pakiranje

Otvorite DispSavers.slnx u Visual Studiju i prevedite Release | x86 pomoću MSVC v145 i Windows SDK-a. Na stranici Signing projekta postavite certifikat i obvezni RFC 3161 poslužitelj vremenskog žiga; osobne vrijednosti ostaju u ignoriranoj datoteci .vcxproj.user. Potpisani SCR s vremenskim žigom ugrađuje se u EXE, a zatim se potpisuje i EXE. PackageRelease.ps1 izrađuje zajedničku arhivu `DispSavers-<version>-win32.zip` bez izmjena binarnih datoteka u Release.

## Licencija

[MIT](license.txt) — Copyright © Petr Červinka — FortSoft 2026
