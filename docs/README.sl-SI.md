# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · **Slovenščina** · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Strojno pospešena animacija prostorskih teles.

FlyingSolids prikazuje prostorska telesa, ki se premikajo, vrtijo in trkajo. Izberite opazovanje prostora ali let skozi prostor in želena telesa. Za vsak zaslon so ločeno nastavljivi hitrost predmetov in kamere 0–1600%, velikost 50–200% ter 1–10 kopij vsakega telesa. Glavna, dopolnilna, okoljska in obrobna svetloba se vklapljajo neodvisno.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Strojno pospešen let med spreminjajočimi se ploskvami.

Strojno pospešen let med spreminjajočimi se ploskvami. Let med štirimi spreminjajočimi se ploskvami; Let skozi spreminjajoči se lijak. Za vsak zaslon izberite natanko eno animacijo. Tekstura preklaplja med teksturirano ploskvijo in žičnim modelom. Prosto vrtenje kamere počasi spreminja smer pogleda v vseh treh razsežnostih. Premori in obrati dodajo naključne upočasnitve, premore in obrate smeri vrtenja; let naprej se nadaljuje. Hitrost je 0–1600%. Vsak zaslon ima neodvisen naključen prizor, ki se izrisuje z njegovo hitrostjo osveževanja. Glavno svetlobo, dopolnilno svetlobo, okoljsko svetlobo in obrobno svetlobo je mogoče neodvisno vklapljati za izbrane zaslone. Osvetlitev velja samo za teksturirane površine.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Strojno pospešen let nad valovito ploskvijo.

SpaceFlight: Neskončna valovita ploskev; Oddaljeni let — spreminjajoča se ploskev; Let skozi gravitacijsko ukrivljen prostor. Za vsak zaslon izberite natanko eno animacijo. Tekstura preklaplja med teksturirano ploskvijo in žičnim modelom. Prosto vrtenje kamere počasi spreminja smer pogleda v vseh treh razsežnostih. Premori in obrati dodajo naključne upočasnitve, premore in obrate smeri vrtenja; let naprej se nadaljuje. Hitrost je 0–1600%. Vsak zaslon ima neodvisen naključen prizor, ki se izrisuje z njegovo hitrostjo osveževanja. Glavno svetlobo, dopolnilno svetlobo, okoljsko svetlobo in obrobno svetlobo je mogoče neodvisno vklapljati za izbrane zaslone. Osvetlitev velja samo za teksturirane površine. Pri obeh animacijah ploskev lahko izberete ravnino, valovanje ali lijak. Lijak vleče kamero navznoter po padajoči spirali. Let skozi gravitacijsko ukrivljen prostor prikazuje tridimenzionalno žično mrežo. Možnosti teksture, oblike ploskve in osvetlitve veljajo samo za obe animaciji ploskev.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Conwayeva igra življenja v skupnem svetu več zaslonov.

### Pravila

Conwayeva igra življenja uporablja B3/S23. Mrtva celica oživi ob natanko treh živih sosedih; živa preživi ob dveh ali treh. Osem sosedov vključuje diagonale. Vse celice se spremenijo hkrati. Nasprotni robovi so povezani: levi z desnim, zgornji s spodnjim.

### Zasloni in skupni svet

Potrditvena polja v EXE vključijo zaslone; nastavitve veljajo za skupni svet. En sam vključen zaslon vsebuje ves svet. Pri delni izbiri se povsem prazne vrstice in stolpci odstranijo: levi in desni zaslon se združita, ko izključite srednjega. Neodstranljive notranje luknje ostanejo v simulaciji. Izbira vseh zaslonov ali SCR ohrani pravokotnik namizja z nevidnimi vrzelmi. Vsak zaslon kaže svoj del iste simulacije.

### Začetno stanje in vzorci

Privzeti začetek je naključni šum s 25 % živih celic. Začetna gostota 0–100 % velja ob naslednjem ponovnem začetku. Samo znani vzorci uporabi 4.106 priloženih vzorcev brez šuma in onemogoči gostoto. Izberite mešanico ali ime; mere so v celicah. Za iskanje tipkajte ime. Vsi vzorci iz kataloga so vedno na voljo. Majhni preverjeni vzorci se ponovijo v ločenih kopijah, veliki ali zapleteni enkrat na sredini. Prevelik vzorec se postavi na sredino in obreže; sprememba velikosti sveta ali celic ohrani izbiro. Sprememba načina ali vzorca ustvari nov prizor. Ponovni začetki ohranijo izbiro; katalog deluje brez interneta.

### Celice, mreža in barve

Brez mreže je velikost 1–64 px. Mreža doda rob 1 px znotraj obstoječega razmika: prikazana vrednost in drsnik se zmanjšata za ena, na voljo je 1–63. Izklop vrne vrednost. Drsnik ohrani ves razpon in se vrne z nedostopnega konca; polje ostane aktivno. Preklop ohrani prizor, razen vklopa pri 1 px: razmik postane 2 px in začne se nov prizor. Tudi sprememba velikosti ali zaslonov začne znova. Zelo velik svet lahko zahteva višjo najmanjšo vrednost. Barve celic, ozadja in mreže se spreminjajo ločeno brez ponovnega začetka. Naključna barva živih celic izbere novo barvo ob vsakem ročnem ali samodejnem ponovnem začetku prizora. Shranjena barva ostane in se vrne ob izklopu možnosti. Enako delovanje lahko ločeno vključite za ozadje in mrežo; obe novi možnosti sta privzeto izključeni.

### Hitrost, premor in samodejni ponovni začetek

Hitrost je 0–240 generacij/s neodvisno od osveževanja; 0 ustavi razvoj. Premor in Nadaljuj ohranita svet. Začni znova začne v izbranem načinu. Izbirni samodejni ponovni začetek zazna statične in natanko ponavljajoče se vidne faze, tudi oscilatorje. Primerja generacije, ne sekund; nevidna območja izpusti. Asinhroni rezultati lahko začetek nekoliko zakasnijo. Privzeto: razmik 8 px, 20 generacij/s, naključna barva živih celic in samodejni ponovni začetek vključeni. Mreža je privzeto izključena. Dosežena hitrost je odvisna od zmogljivosti in števila celic. Samodejni ponovni začetek primerja območja vključenih zaslonov; vrzeli se razvijajo naprej, vendar niso vključene v primerjavo.

### Ponastavi vrednosti

Ponastavitev nastavi prikazano velikost celice na 8 px z mrežo ali brez nje (razmik 9 ali 8 px), hitrost na 20 generacij/s, gostoto na 25 % in tri privzete barve. Druge izbire, vključno z izbranim vzorcem, ostanejo. Nov prizor nastane le ob spremembi razmika ali gostote v načinu šuma.

### Samostojni program in snemanje MP4

EXE sproti shranjuje nastavitve in snema prvi aktivni zaslon v MP4. Predlaga Videoposnetke, sicer Dokumente. Viewport uporabi mere in osveževanje zaslona do 60 sličic/s. TV ponuja 1920 × 1080, 1440 × 1080 ali 1280 × 720 v 16:9 pri 50, 25, 59,94 (60000/1001) ali 29,97 (30000/1001) sličicah/s. Razmerje ostane; TV uporablja progresivni BT.709 z omejenim razponom in 4:2:0. Ločeno okno nastavitev lahko pomanjšate. V redu shrani za naslednje snemanje; Prekliči ali Esc zavrže nepotrjene spremembe. Snemanega zaslona ni mogoče izključiti; druge izhode lahko spreminjate. Izhod med snemanjem zahteva potrditev. Ko ima animacija fokus, preslednica preklopi premor, F9: Začni snemanje; F10: Ustavi snemanje. Kazalec se skrije po 1 sekundi nedejavnosti in vrne ob premiku. Tab/Shift+Tab prehaja med kontrolniki; Alt sproži podčrtane ukaze. Esc zapre Pomoč/O programu ali konča v glavnem oknu. Ohranjevalnik zaslona Windows… odpre sistemske nastavitve ohranjevalnika zaslona.

### Posnetek slike in upravljanje ohranjevalnika v EXE

Posnetek slike shrani BMP/GIF/JPEG/PNG/TIFF/WebP snemanega zaslona, sicer prvega aktivnega, v njegovi ločljivosti brez ponovnega začetka prizora. Predlaga mapo Slike, sicer Dokumenti. Blokiranje ohranjevalnika med animacijo prepreči njegov zagon, dokler je animacija vidna in ni začasno ustavljena. Ničelna hitrost ni premor. Namestitev iz EXE razpakira priloženi SCR in ga izbere kot ohranjevalnik zaslona Windows. Namestitev in odstranitev lahko zahtevata skrbniško dovoljenje; vrstica stanja prikazuje postopek do konca. Če je odstranitev blokirana, zaprite delujoči ohranjevalnik, njegove nastavitve in predogled Windows.

### Ohranjevalnik zaslona Windows

GameOfLife.scr uporablja vse zaslone in nastavitve ločeno od EXE. Predogled zažene celozaslonsko animacijo ob odprtih nastavitvah. Mali predogled Windows pomanjša ves svet. V redu shrani; Prekliči ali Esc zavrže spremembe. Premik miške ali tipka zapre celozaslonski ohranjevalnik. Snemanje MP4 je na voljo v EXE.

### Položaj in stanje oken

Ob zapiranju se ločeno shranita položaja glavnega okna in okna O programu; pri Pomoči tudi velikost in običajno ali povečano stanje pred pomanjšanjem. To ni odvisno od potrjevanja nastavitev programa. Izhod iz programa zapre tudi Pomoč in O programu.

### Izris in licence vzorcev

Razvoj in primerjave vidnih stanj uporabljajo senčilnike Direct3D 11 na GPU; če strojna inicializacija ne uspe, je na voljo programski izris. Vsak zaslon uporablja preverjeno časovno uravnavanje sličic pri lastni frekvenci. MP4 zahteva Media Foundation in kodirnik H.264. Vzorci so iz LifeWiki (GFDL 1.2 ali novejša) in javno dostopnih zbirk Alana Hensela v javni domeni. Koda ima licenco MIT; obvestila in licence kataloga so ločeni.

[Viri vzorcev, licence in podrobnosti uvoza](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### ZASLONI

Na seznamu zaslonov izberite eno ali več vrstic. Ctrl+A izbere vse, Ctrl in Shift pa spreminjata izbor. Kontrolniki in drsniki animacije spreminjajo samo nastavitve izbranih zaslonov. Izbira vrstice ni isto kot vklop izhoda z njenim potrditvenim poljem. Izbor se ločeno shrani za program in ohranjevalnik. Če so bili izbrani vsi zasloni, so vključeni tudi na novo priključeni zasloni. Različne vrednosti na izbranih zaslonih označujeta nedoločeno stanje potrditvenih polj in pikčast vzorec na izbirnih gumbih, ročicah drsnikov ter gumbih »Vklopi vse« in »Izklopi vse«. Oznake drsnikov namesto skupne vrednosti prikazujejo pomišljaj. Sprememba možnosti ali klik na drsnik uveljavi to vrednost na vseh izbranih zaslonih.

### UPRAVLJANJE

Zaženite FlightCorridor.exe. Nastavitve se shranjujejo sproti in deluje le en primerek programa. Polje zaslona ali dvojni klik na vrstico vklopi ali izklopi izhod animacije. Animacijo lahko začasno ustavite in nadaljujete. BMP/GIF/JPEG/PNG/TIFF/WebP in MP4 zajameta prvi aktivni zaslon animacije, ne skupne slike vseh zaslonov. Izhoda animacije snemanega zaslona med snemanjem ni mogoče izklopiti; zapiranje programa med snemanjem zahteva potrditev. Premor in preprečevanje ohranjevalnika veljata za celoten program, ne glede na izbor zaslonov. Ko je preprečevanje vključeno, se ohranjevalnik Windows prepreči le, dokler je na vsaj enem zaslonu vidna animacija, ki ni ustavljena. Program lahko namesti ali odstrani vgrajeni ohranjevalnik.

### POSNETKI ZASLONA IN SNEMANJE

V nastavitvah snemanja izberite Viewport ali TV. Viewport ohrani velikost in hitrost osveževanja zaslona do 60 sličic na sekundo. TV ponuja 1920 × 1080, 1440 × 1080 ali 1280 × 720 v razmerju 16:9 ter 50, 25, 59.94 (60000/1001) ali 29.97 (30000/1001) sličic na sekundo. TV uporablja progresivni BT.709 z omejenim obsegom in barvnim podvzorčenjem 4:2:0. Razmerje slike se ohrani, dopolnilni pasovi so črni. OK shrani izbiro za naslednje snemanje; Prekliči ali Esc zavrže nepotrjene spremembe. Okna snemanja, pomoči in podatkov o programu ne blokirajo drugih oken in jih je mogoče minimirati. Tab in Shift+Tab premikata fokus, Enter aktivira izbrani gumb, Esc pa zapre aktivno pomožno okno.

### PREDOGLED IN UPRAVLJANJE

Uporabite FlightCorridor.scr kot ohranjevalnik zaslona Windows z ločenimi nastavitvami. Celozaslonski predogled omogoča sprotne spremembe. OK jih shrani, Prekliči ali Esc jih zavrže. Ohranjevalnik zapustite s tipko ali premikom miške.

### Sistemske zahteve

Windows 7–11 podpira vse funkcije. Za Windows Vista SP2 morate namestiti posodobitvi KB971512 in KB2117917; snemanje MP4 v Visti ne deluje. Potrebna je podpora Direct3D 11, za MP4 pa še Media Foundation in kodirnik H.264. Vmesnik in dokumentacija sta na voljo v 36 jezikih. Samostojna aplikacija lahko deluje tudi v Linuxu prek Wine; integracija kot ohranjevalnik zaslona je na voljo samo v Windows.

## Prevajanje in pakiranje

Odprite DispSavers.slnx v Visual Studiu in prevedite Release | x86 z MSVC v145 in Windows SDK. Na strani Signing določite potrdilo in obvezni strežnik časovnih žigov RFC 3161; osebne vrednosti ostanejo v prezrti datoteki .vcxproj.user. Podpisani SCR s časovnim žigom se vgradi v EXE, nato se podpiše tudi EXE. PackageRelease.ps1 ustvari skupni `DispSavers-<version>-win32.zip` brez spreminjanja binarnih datotek v Release.

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
