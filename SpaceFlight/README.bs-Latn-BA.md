# SpaceFlight

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · **Bosanski** · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

Hardverski ubrzan let iznad valovite površine. Beskonačna valovita površina; Daleki let — promjenjiva površina. Za svaki monitor odaberite tačno jednu animaciju. Tekstura mijenja prikaz između teksturirane površine i žičanog modela. Slobodno okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, pauze i promjene smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki monitor ima nezavisnu nasumičnu scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje samo na teksturirane površine. Isključivanje opcije Valovi izravnava obje površine bez zaustavljanja leta ili okretanja kamere.

## Kontrole

Odaberite jedan ili više redova u listi monitora. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije mijenjaju samo postavke odabranih monitora. Odabir reda nije isto što i uključivanje izlaza njegovom kućicom. Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili odabrani svi monitori, uključuju se i novopriključeni monitori.

## Aplikacija

Pokrenite SpaceFlight.exe. Postavke se stalno čuvaju i radi samo jedna instanca aplikacije. Kućica monitora ili dvostruki klik na red uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe prvi aktivni monitor animacije, ne zajedničku sliku svih monitora. Snimani monitor ne možete isključiti; zatvaranje aplikacije tokom snimanja zahtijeva potvrdu. Blokada čuvara ekrana vrijedi za cijelu sesiju i samo dok je na monitoru s uključenom tom opcijom vidljiva animacija koja nije pauzirana. Aplikacija može instalirati i deinstalirati ugrađeni čuvar ekrana.

U postavkama snimanja odaberite Viewport ili TV. Viewport zadržava dimenzije i frekvenciju monitora do 60 kadrova u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u omjeru 16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) kadrova u sekundi. TV video je progresivni BT.709 ograničenog raspona s poduzorkovanjem boje 4:2:0. Omjer slike ostaje sačuvan, a dopunske trake su crne. OK čuva opcije za sljedeći snimak; Otkaži ili Esc odbacuje nepotvrđene izmjene. Prozori snimanja, pomoći i informacija ne blokiraju ostale prozore i mogu se minimizirati. Tab i Shift+Tab pomjeraju fokus, Enter aktivira fokusirano dugme, a Esc zatvara aktivni pomoćni prozor.

## Čuvar ekrana

Koristite SpaceFlight.scr kao Windows čuvar ekrana s odvojenim postavkama. Pregled preko cijelog ekrana omogućava izmjene uživo. OK čuva, a Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili pomjeranjem miša.

## Sistemski zahtjevi

Windows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media Foundation te H.264 koder. Interfejs i dokumentacija dostupni su na 36 jezika.

## Prevođenje i pakovanje

Otvorite DispSavers.slnx u Visual Studiju i prevedite Release | x86 pomoću MSVC v145 i Windows SDK-a. Na stranici Signing projekta postavite certifikat i obavezni RFC 3161 server vremenskog žiga; lične vrijednosti ostaju u ignorisanoj datoteci .vcxproj.user. Potpisani SCR s vremenskim žigom ugrađuje se u EXE, a zatim se potpisuje i EXE. PackageRelease.ps1 pravi zajedničku arhivu `DispSavers-<version>-win32.zip` bez izmjena binarnih datoteka u Release.

## Licenca

[MIT](license.txt) — Copyright © Petr Červinka — FortSoft 2026
