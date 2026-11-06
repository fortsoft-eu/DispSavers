# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · **Hrvatski** · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Hardverski ubrzana animacija prostornih tijela.

FlyingSolids prikazuje prostorna tijela koja se kreću, okreću i sudaraju. Odaberite promatranje prostora ili let kroz prostor te željena tijela. Za svaki zaslon zasebno se podešavaju brzina objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija svakog tijela. Glavno, dopunsko, ambijentalno i konturno svjetlo uključuju se neovisno.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Hardverski ubrzan let između promjenjivih ploha.

Hardverski ubrzan let između promjenjivih ploha. Let između četiriju promjenjivih ploha; Let kroz promjenjivi lijevak. Za svaki zaslon odaberite točno jednu animaciju. Tekstura mijenja prikaz između teksturirane plohe i žičanog modela. Slobodno okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, stanke i promjene smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki zaslon ima neovisnu nasumičnu scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje samo na teksturirane površine.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Hardverski ubrzan let iznad valovite plohe.

SpaceFlight: Beskonačna valovita ploha; Daleki let — promjenjiva ploha; Let kroz gravitacijski zakrivljen prostor. Za svaki zaslon odaberite točno jednu animaciju. Tekstura mijenja prikaz između teksturirane plohe i žičanog modela. Slobodno okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, stanke i promjene smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki zaslon ima neovisnu nasumičnu scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje samo na teksturirane površine. Obje animacije površina nude ravninu, valove ili lijevak. Lijevak uvlači kameru prema unutra duž silazne spirale. Let kroz gravitacijski zakrivljen prostor prikazuje trodimenzionalnu žičanu mrežu. Opcije teksture, oblika površine i osvjetljenja odnose se samo na dvije animacije površina.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Conwayeva Igra života u zajedničkom svijetu na više monitora.

### Pravila

Conwayeva Igra života koristi B3/S23. Mrtva ćelija oživi uz točno tri živa susjeda; živa preživi uz dva ili tri. Osam susjeda uključuje dijagonale. Sve se ćelije mijenjaju istodobno. Suprotni se rubovi spajaju: lijevi s desnim, gornji s donjim.

### Monitori i zajednički svijet

Potvrdni okviri u EXE uključuju monitore; postavke vrijede za zajednički svijet. Jedan uključen monitor sadrži cijeli svijet. Pri odabiru dijela rasporeda potpuno prazni redci i stupci uklanjaju se: lijevi i desni monitor spoje se nakon isključivanja srednjeg. Unutarnje rupe koje se ne mogu ukloniti ostaju u simulaciji. Odabir svih monitora ili SCR zadržava pravokutnik radne površine s nevidljivim prazninama. Svaki monitor prikazuje svoj dio iste simulacije.

### Početno stanje i uzorci

Zadani početak je nasumični šum s 25 % živih ćelija. Početna gustoća 0–100 % primjenjuje se pri sljedećem ponovnom pokretanju. Samo poznati uzorci koristi 4.106 priloženih uzoraka bez šuma i isključuje gustoću. Odaberite mješavinu ili naziv; dimenzije su u ćelijama. Tipkajte naziv za pretraživanje. Svi uzorci iz kataloga uvijek su dostupni. Mali provjereni uzorci ponavljaju se u odvojenim kopijama, veliki ili složeni jednom u sredini. Prevelik uzorak centrira se i odrezuje na rubovima; promjena veličine svijeta ili ćelija čuva odabir. Promjena načina ili uzorka stvara novu scenu. Ponovna pokretanja čuvaju odabir; katalog radi izvan mreže.

### Ćelije, mreža i boje

Bez mreže veličina ćelije je 1–64 px. Mreža dodaje rub od 1 px unutar postojećeg razmaka: prikaz i klizač smanjuju se za jedan, dostupno je 1–63. Isključivanje vraća vrijednost. Klizač zadržava raspon i vraća se s nedostupnog kraja; okvir ostaje aktivan. Prebacivanje čuva scenu, osim uključivanja na 1 px: razmak postaje 2 px i scena počinje iznova. Promjena veličine ili monitora također počinje iznova. Vrlo velik svijet može zahtijevati veći minimum. Boje ćelija, pozadine i mreže mijenjaju se zasebno bez ponovnog pokretanja. Nasumična boja živih ćelija bira novu boju pri svakom ručnom ili automatskom ponovnom pokretanju scene. Spremljena boja ostaje i vraća se nakon isključivanja ove mogućnosti. Isto ponašanje može se zasebno uključiti za pozadinu i mrežu; obje nove mogućnosti početno su isključene.

### Brzina, stanka i automatsko ponovno pokretanje

Brzina je 0–240 generacija/s neovisno o osvježavanju; 0 zaustavlja razvoj. Stanka i Nastavi čuvaju svijet. Pokreni ponovno počinje u odabranom načinu. Neobavezno automatsko ponovno pokretanje prepoznaje statične i točno ponovljene vidljive faze, uključujući oscilatore. Uspoređuje generacije, ne sekunde; nevidljiva područja izostavlja. Asinkroni rezultati mogu malo odgoditi ponovno pokretanje. Zadano: razmak 8 px, 20 generacija/s, nasumična boja živih stanica i automatsko ponovno pokretanje uključeni. Mreža je prema zadanim postavkama isključena. Postignuta brzina ovisi o performansama i broju ćelija. Automatsko ponovno pokretanje uspoređuje područja uključenih monitora; praznine se i dalje razvijaju, ali ne ulaze u usporedbu.

### Vrati vrijednosti

Vraćanje postavlja prikazanu veličinu ćelije na 8 px s mrežom ili bez nje (razmak 9 ili 8 px), brzinu na 20 generacija/s, gustoću na 25 % i tri zadane boje. Ostali izbori, uključujući odabrani uzorak, ostaju. Nova scena nastaje samo pri promjeni razmaka ili gustoće u načinu sa šumom.

### Samostalna aplikacija i MP4 snimanje

EXE stalno sprema postavke i snima prvi aktivni monitor u MP4. Predlaže Videozapise, inače Dokumente. Viewport koristi dimenzije i osvježavanje monitora do 60 sličica/s. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u 16:9 pri 50, 25, 59,94 (60000/1001) ili 29,97 (30000/1001) sličica/s. Omjer se čuva; TV koristi progresivni BT.709 s ograničenim rasponom i 4:2:0. Zaseban prozor postavki može se minimizirati. U redu sprema za sljedeće snimanje; Odustani ili Esc odbacuje nepotvrđene izmjene. Snimani monitor ne može se isključiti; ostali se izlazi mogu mijenjati. Izlaz tijekom snimanja traži potvrdu. Kada je animacija u fokusu, Razmak mijenja stanku, F9: Pokreni snimanje; F10: Zaustavi snimanje. Pokazivač nestaje nakon 1 sekunde mirovanja i vraća se pomicanjem. Tab/Shift+Tab prelazi između kontrola; Alt aktivira podcrtane naredbe. Esc zatvara Pomoć/O programu ili izlazi iz glavnog prozora. Čuvar zaslona u Windowsu… otvara sistemske postavke čuvara zaslona.

### Snimka slike i upravljanje čuvarom u EXE

Snimka slike sprema BMP/GIF/JPEG/PNG/TIFF/WebP monitora koji se snima, inače prvog aktivnog, u njegovoj razlučivosti bez ponovnog pokretanja scene. Predlaže mapu Slike, inače Dokumenti. Blokiranje čuvara tijekom animacije sprječava njegovo pokretanje dok je animacija vidljiva i nije zaustavljena stankom. Nulta brzina nije stanka. Instalacija iz EXE raspakira priloženi SCR i odabire ga kao Windows čuvar zaslona. Instalacija i deinstalacija mogu tražiti odobrenje administratora; statusna traka prikazuje radnju do završetka. Ako je uklanjanje blokirano, zatvorite pokrenuti čuvar, njegove postavke i pretpregled sustava Windows.

### Čuvar zaslona Windows

GameOfLife.scr koristi sve monitore i postavke odvojene od EXE. Pretpregled pokreće animaciju preko cijelog zaslona uz otvorene postavke. Mali pretpregled Windows smanjuje cijeli svijet. U redu sprema; Odustani ili Esc odbacuje izmjene. Pomicanje miša ili tipka zatvara čuvar preko cijelog zaslona. MP4 snimanje dostupno je u EXE.

### Položaj i stanje prozora

Pri zatvaranju se zasebno spremaju položaji glavnog prozora i prozora O programu; za Pomoć i veličina te normalno ili maksimizirano stanje prije minimiziranja. To ne ovisi o potvrđivanju postavki aplikacije. Zatvaranje aplikacije zatvara i Pomoć i O programu.

### Iscrtavanje i licence uzoraka

Razvoj i usporedba vidljivih stanja koriste Direct3D 11 sjenčare na GPU-u; softversko iscrtavanje dostupno je ako hardverska inicijalizacija ne uspije. Svaki monitor koristi provjereni regulator sličica pri vlastitom osvježavanju. MP4 zahtijeva Media Foundation i H.264 koder. Uzorci dolaze s LifeWiki (GFDL 1.2 ili novija) i iz zbirki Alana Hensela u javnom vlasništvu. Programski kod ima MIT licencu; obavijesti i licence kataloga su odvojene.

[Izvori uzoraka, licence i pojedinosti uvoza](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### MONITORI

Odaberite jedan ili više redaka na popisu zaslona. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije mijenjaju samo postavke odabranih zaslona. Odabir retka nije isto što i uključivanje izlaza njegovim potvrdnim okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar zaslona. Ako su prethodno bili odabrani svi zasloni, uključuju se i novopriključeni zasloni. Različite vrijednosti na odabranim zaslonima prikazuju se neodređenim stanjem potvrdnih okvira i točkastim uzorkom na izbornim gumbima, ručkama klizača i gumbima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju crticu umjesto zajedničke vrijednosti. Promjena mogućnosti ili klik na klizač primjenjuje tu vrijednost na sve odabrane zaslone.

### UPRAVLJANJE

Pokrenite FlightCorridor.exe. Postavke se neprekidno spremaju i radi samo jedna instanca aplikacije. Potvrdni okvir zaslona ili dvostruki klik na redak uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. BMP/GIF/JPEG/PNG/TIFF/WebP i MP4 bilježe prvi aktivni zaslon animacije, ne zajedničku sliku svih zaslona. Animacijski izlaz snimanog zaslona ne možete isključiti tijekom snimanja; zatvaranje aplikacije tijekom snimanja zahtijeva potvrdu. Pauza i blokada čuvara zaslona vrijede za cijelu aplikaciju, bez obzira na odabir zaslona. Kada je blokada uključena, čuvar zaslona sustava Windows sprječava se samo dok je na barem jednom zaslonu vidljiva animacija koja nije pauzirana. Aplikacija može instalirati i deinstalirati ugrađeni čuvar zaslona.

### SNIMKE ZASLONA I SNIMANJE

U postavkama snimanja odaberite Viewport ili TV. Viewport zadržava dimenzije i frekvenciju osvježavanja zaslona do 60 sličica u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u omjeru 16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) sličica u sekundi. TV video je progresivni BT.709 ograničenog raspona s poduzorkovanjem boje 4:2:0. Omjer slike ostaje sačuvan, a dopunske trake su crne. OK sprema mogućnosti za sljedeću snimku; Odustani ili Esc odbacuje nepotvrđene izmjene. Prozori snimanja, pomoći i informacija ne blokiraju ostale prozore i mogu se minimizirati. Tab i Shift+Tab pomiču fokus, Enter aktivira fokusirani gumb, a Esc zatvara aktivni pomoćni prozor.

### PRETPREGLED I UPRAVLJANJE

Koristite FlightCorridor.scr kao Windows čuvar zaslona s odvojenim postavkama. Pretpregled preko cijelog zaslona omogućuje izmjene uživo. OK sprema, a Odustani ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili pomicanjem miša.

### Sistemski zahtjevi

Windows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media Foundation te H.264 koder. Sučelje i dokumentacija dostupni su na 36 jezika. Samostalna aplikacija može raditi i na Linuxu putem Winea; integracija kao čuvar zaslona dostupna je samo na Windowsu.

## Prevođenje i pakiranje

Otvorite DispSavers.slnx u Visual Studiju i prevedite Release | x86 pomoću MSVC v145 i Windows SDK-a. Na stranici Signing projekta postavite certifikat i obvezni RFC 3161 poslužitelj vremenskog žiga; osobne vrijednosti ostaju u ignoriranoj datoteci .vcxproj.user. Potpisani SCR s vremenskim žigom ugrađuje se u EXE, a zatim se potpisuje i EXE. PackageRelease.ps1 izrađuje zajedničku arhivu `DispSavers-<version>-win32.zip` bez izmjena binarnih datoteka u Release.

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
