# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · **Bosanski** · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlyingSolids prikazuje prostorna tijela koja se kreću, okreću i sudaraju. Odaberite posmatranje prostora ili let kroz prostor te željena tijela. Za svaki monitor zasebno se podešavaju brzina objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija svakog tijela. Glavno, dopunsko, ambijentalno i konturno svjetlo uključuju se nezavisno.

## Kontrole

Odaberite jedan ili više redova u listi monitora. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije mijenjaju samo postavke odabranih monitora. Odabir reda nije isto što i uključivanje izlaza njegovom kućicom. Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili odabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na odabranim monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, ručkama klizača i dugmadima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju crticu umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost na sve odabrane monitore.

## Aplikacija

Pokrenite FlyingSolids.exe. Postavke se stalno čuvaju i radi samo jedna instanca aplikacije. Kućica monitora ili dvostruki klik na red uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe prvi aktivni monitor animacije, ne zajedničku sliku svih monitora. Animacijski izlaz snimanog monitora ne možete isključiti tokom snimanja; zatvaranje aplikacije tokom snimanja zahtijeva potvrdu. Pauza i blokada čuvara ekrana vrijede za cijelu aplikaciju, bez obzira na odabir monitora. Kada je blokada uključena, čuvar ekrana Windowsa se sprječava samo dok je na barem jednom monitoru vidljiva animacija koja nije pauzirana. Aplikacija može instalirati i deinstalirati ugrađeni čuvar ekrana.

U postavkama snimanja odaberite Viewport ili TV. Viewport zadržava dimenzije i frekvenciju osvježavanja monitora do 60 kadrova u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u omjeru 16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) kadrova u sekundi. TV video je progresivni BT.709 ograničenog raspona s poduzorkovanjem boje 4:2:0. Omjer slike ostaje sačuvan, a dopunske trake su crne. OK čuva opcije za sljedeći snimak; Otkaži ili Esc odbacuje nepotvrđene izmjene. Prozori snimanja, pomoći i informacija ne blokiraju ostale prozore i mogu se minimizirati. Tab i Shift+Tab pomjeraju fokus, Enter aktivira fokusirano dugme, a Esc zatvara aktivni pomoćni prozor.

## Čuvar ekrana

Koristite FlyingSolids.scr kao Windows čuvar ekrana s odvojenim postavkama. Pregled preko cijelog ekrana omogućava izmjene uživo. OK čuva, a Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili pomjeranjem miša.

## Sistemski zahtjevi

Windows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media Foundation te H.264 koder. Interfejs i dokumentacija dostupni su na 36 jezika. Samostalna aplikacija može raditi i na Linuxu putem Winea; integracija kao čuvar ekrana dostupna je samo na Windowsu.

## Prevođenje i pakovanje

Otvorite DispSavers.slnx u Visual Studiju i prevedite Release | x86 pomoću MSVC v145 i Windows SDK-a. Na stranici Signing projekta postavite certifikat i obavezni RFC 3161 server vremenskog žiga; lične vrijednosti ostaju u ignorisanoj datoteci .vcxproj.user. Potpisani SCR s vremenskim žigom ugrađuje se u EXE, a zatim se potpisuje i EXE. PackageRelease.ps1 pravi zajedničku arhivu `DispSavers-<version>-win32.zip` bez izmjena binarnih datoteka u Release.

## Geometrijska tijela

Kocka; Pravilna četverostrana piramida; Zarubljena četverostrana piramida; Četverostrana piramida s kosim presjekom; Piramida s presjekom okomitim na bazu; Pravilna trostrana prizma; Pravilna peterostrana prizma; Pravilna šesterostrana prizma; Pravilni oktaedar; Peterostrana bipiramida; Pravi kružni stožac; Zarubljeni stožac; Stožac s kosim presjekom; Stožac s presjekom okomitim na bazu; Pravi kružni valjak; Šuplji kružni valjak; Šuplji valjak s torusnim krajevima; Rotacijski paraboloid zatvoren ravninom; Kugla; Polukugla; Kuglin odsječak; Veliki kuglin odsječak; Kuglin sloj; Troosni elipsoid; Izduženi rotacijski elipsoid; Spljošteni rotacijski elipsoid; Ovoid; Sferocilindar; Zaobljeni disk (spheroplatelet); Torus.

## Licenca

[MIT](../license.txt) — Copyright © Petr Červinka — FortSoft 2026
