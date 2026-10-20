# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · **Suomi** · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlyingSolids on natiivi Win32/x86 Direct3D -sovellus ja Windowsin näytönsäästäjä, joka näyttää valaistuja kiinteitä kolmiulotteisia geometrisia kappaleita. Kappaleet liikkuvat ja pyörivät itsenäisesti ja törmäävät läpäisemättä toisiaan.

Rivien valinta määrää muokattavat näytöt ja on erillinen animaatioulostulon valintaruuduista. Ctrl+A valitsee kaikki näytöt; Ctrl ja Vaihto muuttavat valintaa. Kaikki animaatioasetukset ja liukusäätimet koskevat valittuja näyttöjä. Valinta muistetaan erikseen EXE- ja SCR-tiloissa. Jos kaikki näytöt olivat valittuina, myös uudet näytöt valitaan. Valittujen näyttöjen eri arvot ilmaistaan valintaruutujen määrittämättömällä tilalla sekä valintanappien, liukusäätimien kahvojen ja kaikkien asetusten kytkentäpainikkeiden pistekuviolla. Liukusäätimen selitteessä näkyy viiva yhteisen arvon sijasta. Asetuksen muuttaminen tai liukusäätimen napsauttaminen asettaa kyseisen arvon kaikille valituille näytöille.

## Ominaisuudet

- **Avaruuden tarkkailu** ja suora **Lento avaruuden halki**. Valitse luettelosta yksi tai useampi näyttö. Kameratila, kappaleet, valaistus, nopeudet, koko ja kopioiden määrä koskevat vain valittuja näyttöjä. Jokainen näyttö muistaa omat asetuksensa.
- Päävalon, täytevalon, ympäristövalon ja reunavalon riippumaton ohjaus
- Itsenäinen näkymä jokaisella valitulla näytöllä
- Yhdestä kymmeneen kopiota jokaisesta käytössä olevasta kappaleesta
- Kohteiden ja kameran nopeus 0–1600 %, koko 50–200 %
- Kiiltävä valaistus, omat värit ja törmäysten käsittely
- Kunkin näytön virkistystaajuuteen mukautuva piirto
- PNG-kuvat ja MP4-tallennus erillisessä sovelluksessa
- Erilliset asetukset sovellukselle ja näytönsäästäjälle
- 30 kappaletyyppiä ja käyttöliittymä 36 kielellä

## Geometriset kappaleet

Kuutio; Säännöllinen neliöpyramidi; Katkaistu neliöpyramidi; Neliöpyramidi, vino leikkaus; Pyramidi, leikkaus kohtisuoraan pohjaan; Säännöllinen kolmioprisma; Säännöllinen viisikulmainen prisma; Säännöllinen kuusikulmainen prisma; Säännöllinen oktaedri; Viisikulmainen kaksoispyramidi; Suora ympyräkartio; Katkaistu kartio; Kartio vinolla tasolla leikattuna; Kartio, pohjaan nähden kohtisuora leikkaus; Suora ympyrälieriö; Ontto lieriö; Ontto lieriö, toroidiset päädyt; Tasolla suljettu pyörähdysparaboloidi; Pallo; Puolipallo; Pallosegmentti; Suuri pallosegmentti; Katkaistu pallosegmentti; Kolmiakselinen ellipsoidi; Prolaatti sferoidi; Litteä sferoidi; Ovoidi; Sferosylinteri; Pyöristetty kiekko (spheroplatelet); Torus.

## Valaistus

Liukusäätimien alla olevat `Päävalo`-, `Täytevalo`-, `Ympäristövalo`- ja `Reunavalo`-valintaruudut ohjaavat koko näkymän valaistusta toisistaan riippumatta. Ympäristövalo antaa pinnoille perusvalaistuksen ja reunavalo korostaa reunoja. Asetukset tallennetaan erikseen sovellukselle ja näytönsäästäjälle.

## Sovellus ja näytönsäästäjä

`FlyingSolids.exe` pitää yhden ohjausikkunan käytettävissä animaation aikana. Animaatioulostulot voi ottaa käyttöön tai poistaa käytöstä näyttöjen valintaruuduilla tai kaksoisnapsauttamalla niiden rivejä. EXE voi asentaa ja poistaa sisäisen näytönsäästäjän. Sovelluksesta voi olla käynnissä vain yksi instanssi. Uusi käynnistys palauttaa pienennetyn ohjausikkunan ja tuo sen etualalle. Siirry säätimien välillä Tab- ja Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat komennon. Esc sulkee aktiivisen Ohje- tai Tietoja-ikkunan; ohjausikkunassa se sulkee sovelluksen. Tilannekuvat ja tallenteet käyttävät ensimmäistä aktiivista animaationäyttöä, eivät kaikkien näyttöjen yhdistettyä kuvaa. PNG käyttää Kuvat-kansiota ja MP4 Videot-kansiota; jos niitä ei ole, käytetään Tiedostot-kansiota. Tallennusasetukset-painikkeella valitaan Viewport tai TV. Viewport säilyttää animaationäytön koon ja virkistystaajuuden, enintään 60 kuvaa sekunnissa. TV tarjoaa tarkkuudet 1920 × 1080, 1440 × 1080 ja 1280 × 720 kuvasuhteella 16:9 sekä taajuudet 50, 25, 59.94 (60000/1001) ja 29.97 (30000/1001) kuvaa sekunnissa. Kuvasuhde säilyy; TV käyttää progressiivista BT.709-videota rajatulla alueella ja 4:2:0-näytteistyksellä. Tarkkuus ja kuvataajuus ovat valittavissa vain TV-tilassa. Tallennusasetukset-ikkunan voi pienentää, eikä se estä muiden sovellusikkunoiden käyttöä. OK tallentaa valinnat seuraavaa MP4-tallennusta varten; Peruuta tai Esc hylkää vahvistamattomat muutokset. Tallennettavan näytön valintaa ei voi poistaa tallennuksen aikana; muiden näyttöjen muutokset eivät pysäytä tallennusta. Sovelluksen sulkeminen tallennuksen aikana vaatii vahvistuksen, sillä myös tallennus päättyy. Keskeytys ja näytönsäästäjän esto koskevat koko sovellusta näytön valinnasta riippumatta. Kun esto on käytössä, Windowsin näytönsäästäjä estetään vain, kun vähintään yhdessä näytössä näkyy animaatio, jota ei ole keskeytetty. `FlyingSolids.scr` käyttää omia asetuksia ilman tallennusta. Koko näytön tila avaa itsenäisen näkymän jokaiselle näytölle. Ota esikatselu käyttöön asetuksissa käynnistää erillisen koko näytön esikatselun kaikilla näytöillä. Se käyttää nykyisiä asetuksia, sallii muutokset esikatselun aikana ja voidaan pysäyttää. Mikä tahansa näppäin, hiiren liike tai napsautus lopettaa koko näytön säästäjän. Esc asetuksissa vastaa Peruuta-painiketta; Ohje- tai Tietoja-ikkunassa se sulkee vain kyseisen ikkunan.

## Asetukset

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Järjestelmävaatimukset

Windows 7–Windows 11 tukevat kaikkia toimintoja, myös PNG-tilannekuvia ja MP4-tallennusta. Sovelluksen suorittaminen Windows Vista SP2:ssa edellyttää päivitysten KB971512 ja KB2117917 asentamista. MP4-tallennus ei toimi Vistassa nykyisessä versiossa. Näyttäminen vaatii Direct3D 11:n, ei pelkästään vanhempaa DirectX-ajoympäristöä. MP4-tallennus vaatii käytettävissä olevat Media Foundation -komponentit ja H.264-enkooderin.

## Koonti

Avaa `DispSavers.slnx` Visual Studiossa käyttäen MSVC v145:tä ja Windows SDK:ta. Valitse `Release | x86` ja kokoa ratkaisu uudelleen, jolloin syntyvät `Release\FlyingSolids.exe` ja `Release\FlyingSolids.scr`. x64-kokoonpanoa ei ole. Anna `FlyingSolids`-projektin ominaisuuksien `Signing`-sivulla nykyisen käyttäjän `Personal (My)`-varastossa olevan voimassa olevan koodin allekirjoitusvarmenteen nimi tai sormenjälki; varmenteella on oltava yksityinen avain. Asetukset koskevat EXE- ja SCR-tiedostoja, ja ne tallennetaan Gitin ohittamaan `FlyingSolids.vcxproj.user`-tiedostoon. SignTool etsitään automaattisesti PATH-muuttujasta tai Windows SDK:sta. Jos käytät SimplySignia, kirjaudu SimplySign Desktopiin ennen koontia. Ensin SCR allekirjoitetaan ja siihen lisätään pakollinen RFC 3161 SHA-256 -aikaleima määritetyltä aikaleimapalvelimelta; sen jälkeen SCR upotetaan EXE-tiedostoon, joka myös allekirjoitetaan ja aikaleimataan. Anna RFC 3161 -aikaleimapalvelimen URL-osoite `Timestamp server`-kenttään. Allekirjoituksen, aikaleiman tai tarkistuksen virhe keskeyttää koonnin; kelvollisesti allekirjoitettuja ja aikaleimattuja tiedostoja ei allekirjoiteta uudelleen.

Paketoi nämä koontitulokset suorittamalla `PackageRelease.ps1` ilman allekirjoitusparametreja. Skripti käyttää väliaikaisia kopioita, ei muuta `Release`-hakemiston tiedostoja ja ainoastaan tarkistaa olemassa olevat kelvolliset allekirjoitukset. Se luo yhden `DispSavers-<version>-win32.zip`-arkiston, jossa ovat `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` ja `SpaceFlight\license.txt`. Edellinen ZIP poistetaan suorituksen alussa; tarkistusvirhe estää uuden arkiston luomisen.

## Lisenssi

FlyingSolids on saatavana [MIT-lisenssillä](../license.txt). Copyright © Petr Červinka — FortSoft 2026

## FlightCorridor

FlightCorridor tarjoaa Lento neljän muuntuvan pinnan välissä ja Lento muuntuvan suppilon läpi -animaatiot. Määritä kullekin näytölle täsmälleen yksi lento: valitse näytön rivi ja vastaava valintanappi.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](../FlightCorridor/README.fi-FI.md)

## SpaceFlight

SpaceFlight tarjoaa „Ääretön aaltoileva pinta“ ja „Pitkän matkan lento — muuntuva pinta“ -animaatiot. Määritä kullekin näytölle täsmälleen yksi lento: valitse näytön rivi ja vastaava valintanappi.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](../SpaceFlight/README.fi-FI.md)
