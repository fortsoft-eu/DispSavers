# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · **Slovenščina** · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlyingSolids prikazuje prostorska telesa, ki se premikajo, vrtijo in trkajo. Izberite opazovanje prostora ali let skozi prostor in želena telesa. Za vsak zaslon so ločeno nastavljivi hitrost predmetov in kamere 0–1600%, velikost 50–200% ter 1–10 kopij vsakega telesa. Glavna, dopolnilna, okoljska in obrobna svetloba se vklapljajo neodvisno.

## Upravljanje

Na seznamu zaslonov izberite eno ali več vrstic. Ctrl+A izbere vse, Ctrl in Shift pa spreminjata izbor. Kontrolniki in drsniki animacije spreminjajo samo nastavitve izbranih zaslonov. Izbira vrstice ni isto kot vklop izhoda z njenim potrditvenim poljem. Izbor se ločeno shrani za program in ohranjevalnik. Če so bili izbrani vsi zasloni, so vključeni tudi na novo priključeni zasloni.

## Program

Zaženite FlyingSolids.exe. Nastavitve se shranjujejo sproti in deluje le en primerek programa. Polje zaslona ali dvojni klik na vrstico vklopi ali izklopi izhod animacije. Animacijo lahko začasno ustavite in nadaljujete. PNG in MP4 zajameta prvi aktivni zaslon animacije, ne skupne slike vseh zaslonov. Snemanega zaslona ni mogoče izklopiti; zapiranje programa med snemanjem zahteva potrditev. Preprečevanje ohranjevalnika velja za celotno sejo in le, dokler je na zaslonu s to možnostjo vidna neustavljena animacija. Program lahko namesti ali odstrani vgrajeni ohranjevalnik.

V nastavitvah snemanja izberite Viewport ali TV. Viewport ohrani velikost in hitrost osveževanja zaslona do 60 sličic na sekundo. TV ponuja 1920 × 1080, 1440 × 1080 ali 1280 × 720 v razmerju 16:9 ter 50, 25, 59.94 (60000/1001) ali 29.97 (30000/1001) sličic na sekundo. TV uporablja progresivni BT.709 z omejenim obsegom in barvnim podvzorčenjem 4:2:0. Razmerje slike se ohrani, dopolnilni pasovi so črni. OK shrani izbiro za naslednje snemanje; Prekliči ali Esc zavrže nepotrjene spremembe. Okna snemanja, pomoči in podatkov o programu ne blokirajo drugih oken in jih je mogoče minimirati. Tab in Shift+Tab premikata fokus, Enter aktivira izbrani gumb, Esc pa zapre aktivno pomožno okno.

## Ohranjevalnik zaslona

Uporabite FlyingSolids.scr kot ohranjevalnik zaslona Windows z ločenimi nastavitvami. Celozaslonski predogled omogoča sprotne spremembe. OK jih shrani, Prekliči ali Esc jih zavrže. Ohranjevalnik zapustite s tipko ali premikom miške.

## Sistemske zahteve

Windows 7–11 podpira vse funkcije. Za Windows Vista SP2 morate namestiti posodobitvi KB971512 in KB2117917; snemanje MP4 v Visti ne deluje. Potrebna je podpora Direct3D 11, za MP4 pa še Media Foundation in kodirnik H.264. Vmesnik in dokumentacija sta na voljo v 36 jezikih.

## Prevajanje in pakiranje

Odprite DispSavers.slnx v Visual Studiu in prevedite Release | x86 z MSVC v145 in Windows SDK. Na strani Signing določite potrdilo in obvezni strežnik časovnih žigov RFC 3161; osebne vrednosti ostanejo v prezrti datoteki .vcxproj.user. Podpisani SCR s časovnim žigom se vgradi v EXE, nato se podpiše tudi EXE. PackageRelease.ps1 ustvari skupni `DispSavers-<version>-win32.zip` brez spreminjanja binarnih datotek v Release.

## Geometrijska telesa

Kocka; Pravilna štiristrana piramida; Prisekana štiristrana piramida; Poševno prirezana štiristrana piramida; Piramida s prerezom pravokotno na osnovo; Pravilna tristrana prizma; Pravilna petstrana prizma; Pravilna šeststrana prizma; Pravilni oktaeder; Petstrana bipiramida; Pokončni krožni stožec; Prisekani stožec; Poševno prirezani stožec; Stožec s prerezom pravokotno na osnovo; Pokončni krožni valj; Votel krožni valj; Votel valj s toroidnima koncema; Rotacijski paraboloid, zaprt z ravnino; Krogla; Polkrogla; Krogelni odsek; Veliki krogelni odsek; Krogelna plast; Triosni elipsoid; Podolgovati rotacijski elipsoid; Sploščeni rotacijski elipsoid; Ovoid; Sferocilinder; Zaobljena ploščica (spheroplatelet); Torus.

## Licenca

[MIT](../license.txt) — Copyright © Petr Červinka — FortSoft 2026
