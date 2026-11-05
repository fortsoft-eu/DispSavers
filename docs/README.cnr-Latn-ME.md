# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · **Crnogorski** · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Hardverski ubrzana animacija prostornih tijela.

FlyingSolids prikazuje prostorna tijela koja se kreću, okreću i sudaraju. Izaberite posmatranje prostora ili let kroz prostor te željena tijela. Za svaki monitor zasebno se podešavaju brzina objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija svakog tijela. Glavno, dopunsko, ambijentalno i konturno svjetlo uključuju se nezavisno.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Hardverski ubrzan let između promjenljivih površina.

Hardverski ubrzan let između promjenljivih površina. Let između četiri promjenljive površine; Let kroz promjenljivi lijevak. Za svaki monitor izaberite tačno jednu animaciju. Tekstura mijenja prikaz između teksturisane površine i žičanog modela. Slobodno okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, pauze i promjene smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki monitor ima nezavisnu nasumičnu scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje samo na teksturirane površine.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Hardverski ubrzan let iznad talasaste površine.

SpaceFlight: Beskonačna talasasta površina; Daleki let — promjenljiva površina; Let kroz gravitaciono zakrivljen prostor. Za svaki monitor izaberite tačno jednu animaciju. Tekstura mijenja prikaz između teksturisane površine i žičanog modela. Slobodno okretanje kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, pauze i promjene smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki monitor ima nezavisnu nasumičnu scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se primjenjuje samo na teksturirane površine. Obje animacije površina nude ravan, talase ili lijevak. Lijevak uvlači kameru prema unutra duž silazne spirale. Let kroz gravitaciono zakrivljen prostor prikazuje trodimenzionalnu žičanu mrežu. Opcije teksture, oblika površine i osvjetljenja odnose se samo na dvije animacije površina.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Konvejeva Igra života u zajedničkom svijetu na više monitora.

### Pravila

Konvejeva Igra života koristi B3/S23. Mrtva ćelija oživi uz tačno tri živa susjeda; živa preživi uz dva ili tri. Osam susjeda uključuje dijagonale. Sve ćelije mijenjaju se istovremeno. Suprotne ivice se spajaju: lijeva s desnom, gornja s donjom.

### Monitori i zajednički svijet

Polja u EXE uključuju monitore; podešavanja važe za zajednički svijet. Jedan uključen monitor sadrži cijeli svijet. Pri izboru dijela rasporeda potpuno prazni redovi i kolone se uklanjaju: lijevi i desni monitor spoje se poslije isključivanja srednjeg. Unutrašnje rupe koje se ne mogu ukloniti ostaju u simulaciji. Izbor svih monitora ili SCR zadržava pravougaonik radne površine s nevidljivim prazninama. Svaki monitor prikazuje svoj dio iste simulacije.

### Početno stanje i obrasci

Podrazumijevani početak je nasumični šum s 25 % živih ćelija. Početna gustina 0–100 % primjenjuje se pri sljedećem ponovnom pokretanju. Samo poznati obrasci koristi 4.106 priloženih obrazaca bez šuma i isključuje gustinu. Izaberite mješavinu ili naziv; dimenzije su u ćelijama. Kucajte naziv za pretragu. Nude se samo obrasci koji staju cijeli. Mali provjereni obrasci ponavljaju se u odvojenim kopijama, veliki ili složeni jednom u sredini. Smanjenje svijeta može prevelik izbor zamijeniti mješavinom. Promjena režima ili obrasca stvara novu scenu. Ponovna pokretanja čuvaju izbor; katalog radi bez interneta.

### Ćelije, mreža i boje

Bez mreže veličina ćelije je 1–64 px. Mreža dodaje ivicu od 1 px unutar postojećeg razmaka: prikaz i klizač smanjuju se za jedan, dostupno je 1–63. Isključivanje vraća vrijednost. Klizač zadržava raspon i vraća se s nedostupnog kraja; polje ostaje aktivno. Prebacivanje čuva scenu, osim uključivanja na 1 px: razmak postaje 2 px i scena počinje iznova. Promjena veličine ili monitora takođe počinje iznova. Veoma velik svijet može zahtijevati veći minimum. Boje ćelija, pozadine i mreže mijenjaju se zasebno bez ponovnog pokretanja. Nasumična boja živih ćelija bira novu boju pri svakom ručnom ili automatskom ponovnom pokretanju scene. Sačuvana boja ostaje i vraća se nakon isključivanja ove opcije. Isto ponašanje može se zasebno uključiti za pozadinu i mrežu; obje nove opcije su podrazumijevano isključene.

### Brzina, pauza i automatsko ponovno pokretanje

Brzina je 0–240 generacija/s nezavisno od osvježavanja; 0 zaustavlja razvoj. Pauza i Nastavi čuvaju svijet. Pokreni ponovo počinje u izabranom režimu. Neobavezno automatsko ponovno pokretanje prepoznaje statične i tačno ponovljene vidljive faze, uključujući oscilatore. Poredi generacije, ne sekunde; nevidljiva područja izostavlja. Asinhroni rezultati mogu malo odložiti ponovno pokretanje. Podrazumijevano: razmak 8 px, 20 generacija/s, nasumična boja živih ćelija i automatsko ponovno pokretanje uključeni. Mreža je podrazumijevano isključena. Postignuta brzina zavisi od performansi i broja ćelija. Automatsko ponovno pokretanje poredi područja uključenih monitora; praznine se i dalje razvijaju, ali se ne uključuju u poređenje.

### Vrati vrijednosti

Vraćanje postavlja prikazanu veličinu ćelije na 8 px s mrežom ili bez nje (razmak 9 ili 8 px), brzinu na 20 generacija/s, gustinu na 25 % i tri podrazumijevane boje. Ostali izbori ostaju; obrazac koji više ne staje zamjenjuje se mješavinom. Nova scena nastaje samo pri promjeni razmaka ili gustine u režimu šuma.

### Samostalna aplikacija i MP4 snimanje

EXE stalno čuva podešavanja i snima prvi aktivni monitor u MP4. Predlaže Video-zapise, inače Dokumente. Viewport koristi dimenzije i osvježavanje monitora do 60 kadrova/s. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u 16:9 pri 50, 25, 59,94 (60000/1001) ili 29,97 (30000/1001) kadrova/s. Odnos se čuva; TV koristi progresivni BT.709 s ograničenim rasponom i 4:2:0. Zaseban prozor podešavanja može se minimizovati. U redu čuva za sljedeće snimanje; Otkaži ili Esc odbacuje nepotvrđene izmjene. Snimani monitor ne može se isključiti; ostali izlazi mogu se mijenjati. Izlaz tokom snimanja traži potvrdu. Kada je animacija u fokusu, Razmak mijenja pauzu, F9: Pokreni snimanje; F10: Zaustavi snimanje. Pokazivač nestaje poslije 1 sekunde mirovanja i vraća se pomjeranjem. Tab/Shift+Tab prelazi između kontrola; Alt aktivira podvučene naredbe. Esc zatvara Pomoć/O programu ili izlazi iz glavnog prozora. Čuvar ekrana u Windowsu… otvara sistemska podešavanja čuvara ekrana.

### Snimak slike i upravljanje čuvarom u EXE

Snimak slike čuva PNG monitora koji se snima, inače prvog aktivnog, u njegovoj rezoluciji bez ponovnog pokretanja scene. Predlaže fasciklu Slike, inače Dokumenti. Blokiranje čuvara tokom animacije sprečava njegovo pokretanje dok je animacija vidljiva i nije pauzirana. Nulta brzina nije pauza. Instalacija iz EXE raspakuje priloženi SCR i bira ga kao Windows čuvar ekrana. Instalacija i deinstalacija mogu tražiti odobrenje administratora; statusna traka prikazuje radnju do završetka. Ako je uklanjanje blokirano, zatvorite pokrenuti čuvar, njegova podešavanja i Windows pregled.

### Windows čuvar ekrana

GameOfLife.scr koristi sve monitore i podešavanja odvojena od EXE. Pregled pokreće animaciju preko cijelog ekrana uz otvorena podešavanja. Mali Windows pregled smanjuje cijeli svijet. U redu čuva; Otkaži ili Esc odbacuje izmjene. Pomjeranje miša ili taster zatvara čuvar preko cijelog ekrana. MP4 snimanje je dostupno u EXE.

### Položaj i stanje prozora

Pri zatvaranju se zasebno čuvaju položaji glavnog prozora i prozora O programu; za Pomoć i veličina te normalno ili maksimizovano stanje prije minimizovanja. To ne zavisi od potvrđivanja podešavanja aplikacije. Zatvaranje aplikacije zatvara i Pomoć i O programu.

### Iscrtavanje i licence obrazaca

Razvoj i poređenje vidljivih stanja koriste Direct3D 11 shadere na GPU-u; softversko iscrtavanje je dostupno ako hardverska inicijalizacija ne uspije. Svaki monitor koristi provjereni regulator kadrova pri vlastitom osvježavanju. MP4 zahtijeva Media Foundation i H.264 koder. Obrasci dolaze s LifeWiki (GFDL 1.2 ili novija) i iz zbirki Alana Hensela u javnom vlasništvu. Programski kod ima MIT licencu; obavještenja i licence kataloga su odvojeni.

[Izvori obrazaca, licence i pojedinosti uvoza](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### MONITORI

Izaberite jedan ili više redova u listi monitora. Ctrl+A bira sve; Ctrl i Shift mijenjaju izbor. Kontrole i klizači animacije mijenjaju samo podešavanja izabranih monitora. Izbor reda nije isto što i uključivanje izlaza njegovom kućicom. Izbor se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili izabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na izabranim monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, ručkama klizača i dugmadima „Uključi sve“ i „Isključi sve“. Oznake klizača prikazuju crticu umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost na sve izabrane monitore.

### UPRAVLJANJE

Pokrenite FlightCorridor.exe. Podešavanja se stalno čuvaju i radi samo jedna instanca aplikacije. Kućica monitora ili dvostruki klik na red uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe prvi aktivni monitor animacije, ne zajedničku sliku svih monitora. Animacijski izlaz snimanog monitora ne možete isključiti tokom snimanja; zatvaranje aplikacije tokom snimanja zahtijeva potvrdu. Pauza i blokada čuvara ekrana važe za cijelu aplikaciju, bez obzira na izbor monitora. Kada je blokada uključena, čuvar ekrana Windowsa se sprječava samo dok je na barem jednom monitoru vidljiva animacija koja nije pauzirana. Aplikacija može instalirati i deinstalirati ugrađeni čuvar ekrana.

### SNIMCI EKRANA I SNIMANJE

U podešavanjima snimanja izaberite Viewport ili TV. Viewport zadržava dimenzije i frekvenciju osvježavanja monitora do 60 kadrova u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u odnosu 16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) kadrova u sekundi. TV video je progresivni BT.709 ograničenog opsega s poduzorkovanjem boje 4:2:0. Odnos slike ostaje sačuvan, a dopunske trake su crne. OK čuva opcije za sljedeći snimak; Otkaži ili Esc odbacuje nepotvrđene izmjene. Prozori snimanja, pomoći i informacija ne blokiraju ostale prozore i mogu se minimizovati. Tab i Shift+Tab pomjeraju fokus, Enter aktivira fokusirano dugme, a Esc zatvara aktivni pomoćni prozor.

### PREGLED I UPRAVLJANJE

Koristite FlightCorridor.scr kao Windows čuvar ekrana s odvojenim podešavanjima. Pregled preko cijelog ekrana omogućava izmjene uživo. OK čuva, a Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tastera ili pomjeranjem miša.

### Sistemski zahtjevi

Windows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media Foundation i H.264 koder. Interfejs i dokumentacija dostupni su na 36 jezika. Samostalna aplikacija može raditi i na Linuxu putem Winea; integracija kao čuvar ekrana dostupna je samo na Windowsu.

## Prevođenje i pakovanje

Otvorite DispSavers.slnx u Visual Studiju i prevedite Release | x86 pomoću MSVC v145 i Windows SDK-a. Na stranici Signing projekta postavite sertifikat i obavezni RFC 3161 server vremenskog žiga; lične vrijednosti ostaju u ignorisanoj datoteci .vcxproj.user. Potpisani SCR s vremenskim žigom ugrađuje se u EXE, a zatim se potpisuje i EXE. PackageRelease.ps1 pravi zajedničku arhivu `DispSavers-<version>-win32.zip` bez izmjena binarnih datoteka u Release.

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

## Licenca

[MIT](../license.txt) — Copyright © Petr Červinka — FortSoft 2026
