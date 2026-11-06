# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · **Suomi** · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Laitteistokiihdytetty kiinteiden 3D-kohteiden animaatio.

Valitse luettelosta yksi tai useampi näyttö. Kameratila, kappaleet, valaistus, nopeudet, koko ja kopioiden määrä koskevat vain valittuja näyttöjä. Jokainen näyttö muistaa omat asetuksensa. FlyingSolids näyttää valaistuja kiinteitä 3D-kappaleita. Liukusäätimillä asetetaan kohteiden ja kameran nopeus 0–1600 %, yhdestä kymmeneen kopiota ja koko 50–200 %. Valitse Avaruuden tarkkailu tai Lento avaruuden halki suoraan eteenpäin ja ota halutut kappaleet käyttöön. Liukusäätimien alla olevat Päävalo-, Täytevalo-, Ympäristövalo- ja Reunavalo-valintaruudut ohjaavat valittujen näyttöjen valaistusta toisistaan riippumatta. Ympäristövalo antaa pinnoille perusvalaistuksen ja reunavalo korostaa reunoja. Asetukset tallennetaan erikseen sovellukselle ja näytönsäästäjälle.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Laitteistokiihdytetty lento muuntuvan käytävän ja suppilon läpi.

FlightCorridor: Lento neljän muuntuvan pinnan välissä; Lento muuntuvan suppilon läpi. Valitse kullekin näytölle yksi animaatio. Tekstuuri vaihtaa teksturoitujen pintojen ja rautalankamallin välillä. Kameran vapaa pyörintä muuttaa katselusuuntaa hitaasti kaikissa kolmessa ulottuvuudessa. Tauot ja suunnanvaihdot lisäävät satunnaisia hidastuksia, taukoja ja pyörimissuunnan vaihtoja; lento eteenpäin jatkuu. Nopeus on 0–1600%. Jokaisella näytöllä on itsenäinen satunnainen näkymä, joka piirretään sen omalla virkistystaajuudella. Päävalo, täytevalo, ympäristövalo ja reunavalo voidaan kytkeä erikseen valituille näytöille. Valaistus koskee vain teksturoituja pintoja.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Laitteistokiihdytetty lento aaltoilevien ja muuntuvien pintojen yllä.

SpaceFlight: Ääretön aaltoileva pinta; Pitkän matkan lento — muuntuva pinta; Lento painovoiman kaareuttamassa avaruudessa. Valitse kullekin näytölle yksi animaatio. Tekstuuri vaihtaa teksturoitujen pintojen ja rautalankamallin välillä. Kameran vapaa pyörintä muuttaa katselusuuntaa hitaasti kaikissa kolmessa ulottuvuudessa. Tauot ja suunnanvaihdot lisäävät satunnaisia hidastuksia, taukoja ja pyörimissuunnan vaihtoja; lento eteenpäin jatkuu. Nopeus on 0–1600%. Jokaisella näytöllä on itsenäinen satunnainen näkymä, joka piirretään sen omalla virkistystaajuudella. Päävalo, täytevalo, ympäristövalo ja reunavalo voidaan kytkeä erikseen valituille näytöille. Valaistus koskee vain teksturoituja pintoja. Molemmissa pinta-animaatioissa voi valita tason, aallot tai suppilon. Suppilo vetää kameran sisään alaspäin kiertyvää spiraalia pitkin. Lento painovoiman kaareuttamassa avaruudessa näyttää kolmiulotteisen rautalankaruudukon. Tekstuurin, pinnan muodon ja valaistuksen asetukset koskevat vain kahta pinta-animaatiota.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Conwayn Game of Life näyttöjen yhteisessä maailmassa.

### Säännöt

Conwayn Game of Life käyttää sääntöä B3/S23. Kuollut solu syntyy, kun sillä on täsmälleen kolme elävää naapuria; elävä säilyy kahdella tai kolmella. Kahdeksaan naapuriin kuuluvat vinottaiset. Kaikki solut muuttuvat yhtä aikaa. Vastakkaiset reunat liittyvät toisiinsa: vasen oikeaan, yläreuna alareunaan.

### Näytöt ja yhteinen maailma

EXE:n valintaruudut kytkevät näytöt käyttöön; asetukset koskevat yhteistä maailmaa. Yksi käytössä oleva näyttö sisältää koko maailman. Osittaisessa valinnassa täysin tyhjät rivit ja sarakkeet poistetaan: vasen ja oikea näyttö yhdistyvät, kun keskimmäinen poistetaan käytöstä. Poistamattomat sisäaukot pysyvät simulaatiossa. Kaikkien näyttöjen valinta tai SCR säilyttää työpöydän rajaavan suorakulmion näkymättömine väleineen. Jokainen näyttö näyttää oman osansa samasta simulaatiosta.

### Alkutila ja kuviot

Oletusalku on satunnainen kohina, jossa on 25 % eläviä soluja. Alkutiheys 0–100 % vaikuttaa seuraavaan uudelleenaloitukseen. Vain tunnetut kuviot käyttää 4 106 mukana tulevaa kuviota ilman kohinaa ja poistaa tiheyden käytöstä. Valitse sekoitus tai nimetty kuvio; mitat ovat soluina. Kirjoita nimi hakeaksesi. Vain kokonaan mahtuvat kuviot näytetään. Pienet tarkistetut kuviot toistuvat erillisinä kopioina, suuret tai monimutkaiset kerran keskellä. Pienentäminen voi korvata liian suuren valinnan sekoituksella. Tilan tai kuvion vaihtaminen luo uuden tilanteen. Uudelleenaloitus säilyttää valinnan; luettelo toimii ilman verkkoa.

### Solukoko, ruudukko ja värit

Ilman ruudukkoa solukoko on 1–64 px. Ruudukko lisää 1 px reunan nykyisen jaon sisään: näytetty arvo ja liukusäädin pienenevät yhdellä, käytettävissä on 1–63. Poiskytkentä palauttaa arvon. Liukusäätimen asteikko säilyy ja säädin palautuu estetystä päätepisteestä; valintaruutu pysyy käytössä. Vaihtaminen säilyttää tilanteen, paitsi päällekytkentä koossa 1 px: jako kasvaa 2 px:iin ja tilanne alkaa uudelleen. Myös solukoon tai näyttöjen muutos aloittaa uudelleen. Erittäin suuri maailma voi vaatia suuremman vähimmäiskoon. Solujen, taustan ja ruudukon värit vaihtuvat erikseen ilman uudelleenaloitusta. Elävien solujen satunnaisväri valitsee uuden värin jokaisella manuaalisella tai automaattisella uudelleenaloituksella. Tallennettu väri säilyy ja palautuu, kun valinta poistetaan käytöstä. Saman toiminnan voi ottaa erikseen käyttöön taustalle ja ruudukolle; molemmat uudet valinnat ovat oletuksena pois käytöstä.

### Nopeus, tauko ja automaattinen uudelleenaloitus

Nopeus on 0–240 sukupolvea/s näytön virkistyksestä riippumatta; 0 pysäyttää kehityksen. Tauko ja Jatka säilyttävät maailman. Uudelleenaloitus aloittaa valitussa tilassa. Valinnainen automaattinen uudelleenaloitus tunnistaa pysyvät ja täsmälleen toistuvat näkyvät vaiheet, myös oskillaattorit. Se vertaa sukupolvia, ei sekunteja, ja jättää näkymättömät alueet pois. Asynkroniset tulokset voivat viivästyttää aloitusta hieman. Oletukset: jako 8 px, 20 sukupolvea/s, elävien solujen satunnaisväri ja automaattinen uudelleenaloitus käytössä. Ruudukko on oletuksena pois käytöstä. Saavutettu nopeus riippuu suorituskyvystä ja solumäärästä. Automaattinen uudelleenaloitus vertaa käytössä olevien näyttöjen alueita; välit kehittyvät edelleen mutta jäävät vertailun ulkopuolelle.

### Palauta arvot

Palautus asettaa näytetyksi solukooksi 8 px ruudukolla tai ilman (jako 9 tai 8 px), nopeudeksi 20 sukupolvea/s, tiheydeksi 25 % ja kolme oletusväriä. Muut valinnat säilyvät; kuvio, joka ei enää mahdu, korvataan sekoituksella. Uusi tilanne luodaan vain, jos jako muuttuu tai tiheys muuttuu kohinatilassa.

### Erillissovellus ja MP4-tallennus

EXE tallentaa asetukset jatkuvasti ja ensimmäisen aktiivisen näytön MP4:ksi. Ehdotettu kansio on Videot, varalla Tiedostot. Viewport käyttää näytön kokoa ja virkistystä enintään 60 kuvaa/s. TV tarjoaa 1920 × 1080, 1440 × 1080 tai 1280 × 720, 16:9, nopeudella 50, 25, 59,94 (60000/1001) tai 29,97 (30000/1001) kuvaa/s. Kuvasuhde säilyy; TV käyttää progressiivista, rajatun alueen BT.709-videota ja 4:2:0-näytteistystä. Erillisen asetusikkunan voi pienentää. OK tallentaa seuraavaa tallennusta varten; Peruuta tai Esc hylkää vahvistamattomat muutokset. Tallennettavaa näyttöä ei voi poistaa käytöstä; muita lähtöjä voi muuttaa. Lopetus tallennuksen aikana vaatii vahvistuksen. Animaation ollessa aktiivinen Välilyönti vaihtaa tauon, F9: Aloita tallennus; F10: Lopeta tallennus. Osoitin katoaa 1 sekunnin toimettomuuden jälkeen ja palaa liikkeestä. Tab/Shift+Tab siirtyy säätimissä, Alt valitsee alleviivatut komennot. Esc sulkee Ohje/Tietoja-ikkunan tai poistuu pääikkunasta. Windowsin näytönsäästäjä… avaa järjestelmän näytönsäästäjän asetukset.

### Tilannekuva ja näytönsäästäjän hallinta EXE:ssä

Tilannekuva tallentaa BMP/GIF/JPEG/PNG/TIFF/WebP:n tallennettavasta näytöstä tai muuten ensimmäisestä aktiivisesta näytöstä sen tarkkuudella aloittamatta tilannetta uudelleen. Ehdotettu kansio on Kuvat, varalla Tiedostot. Näytönsäästäjän esto animaation aikana estää sen käynnistymisen, kun animaatio näkyy eikä ole tauolla. Nollanopeus ei ole tauko. Asennus EXE:stä purkaa mukana tulevan SCR:n ja valitsee sen Windowsin näytönsäästäjäksi. Asennus ja poisto voivat vaatia järjestelmänvalvojan hyväksynnän; tilarivi näyttää toiminnon sen valmistumiseen asti. Jos poisto estyy, sulje käynnissä oleva säästäjä, sen asetukset ja Windowsin esikatselu.

### Windowsin näytönsäästäjä

GameOfLife.scr käyttää kaikkia näyttöjä ja EXE:stä erillisiä asetuksia. Esikatselu käynnistää koko näytön animaation asetusten pysyessä auki. Windowsin pieni esikatselu pienentää koko maailman. OK tallentaa, Peruuta tai Esc hylkää muutokset. Hiiren liike tai näppäin sulkee koko näytön säästäjän. MP4-tallennus on käytettävissä EXE:ssä.

### Ikkunoiden sijainti ja tila

Sulkeminen tallentaa pääikkunan ja Tietoja-ikkunan sijainnit erikseen; Ohjeesta myös koon ja normaalin tai suurennetun tilan ennen mahdollista pienentämistä. Tämä ei riipu sovellusasetusten vahvistamisesta. Sovelluksen lopettaminen sulkee myös Ohje- ja Tietoja-ikkunat.

### Piirtäminen ja kuvioiden lisenssit

Kehitys ja näkyvien tilojen vertailu käyttävät GPU:n Direct3D 11 -varjostimia; ohjelmistopiirto on käytettävissä, jos laitteistoalustus epäonnistuu. Jokainen näyttö käyttää samaa koeteltua ruudunajoitusta omalla virkistystaajuudellaan. MP4 vaatii Media Foundationin ja H.264-kooderin. Kuviot ovat LifeWikistä (GFDL 1.2 tai uudempi) ja Alan Henselin vapaista public domain -kokoelmista. Ohjelmakoodi on MIT-lisensoitu; luettelon ilmoitukset ja lisenssit ovat erilliset.

[Kuvioiden lähteet, lisenssit ja tuonnin tiedot](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### NÄYTÖT

Rivien valinta määrää muokattavat näytöt ja on erillinen animaatioulostulon valintaruuduista. Ctrl+A valitsee kaikki näytöt; Ctrl ja Vaihto muuttavat valintaa. Kaikki animaatioasetukset ja liukusäätimet koskevat valittuja näyttöjä. Valinta muistetaan erikseen EXE- ja SCR-tiloissa. Jos kaikki näytöt olivat valittuina, myös uudet näytöt valitaan. Valittujen näyttöjen eri arvot ilmaistaan valintaruutujen määrittämättömällä tilalla sekä valintanappien, liukusäätimien kahvojen ja painikkeiden ”Ota kaikki käyttöön” ja ”Poista kaikki käytöstä” pistekuviolla. Liukusäätimen selitteessä näkyy viiva yhteisen arvon sijasta. Asetuksen muuttaminen tai liukusäätimen napsauttaminen asettaa kyseisen arvon kaikille valituille näytöille.

### KÄYTTÖ

Animaatioulostulot voi ottaa käyttöön tai poistaa käytöstä näyttöjen valintaruuduilla tai kaksoisnapsauttamalla niiden rivejä. Jokaisella näytöllä on itsenäinen näkymä. Tilannekuva tallentaa BMP/GIF/JPEG/PNG/TIFF/WebP:n ja tallennuspainike käynnistää tai lopettaa MP4:n. Keskeytä pysäyttää animaation. Sovellus asentaa tai poistaa myös sisäisen näytönsäästäjän. Asetukset tallennetaan jatkuvasti. Sovelluksesta voi olla käynnissä vain yksi instanssi. Uusi käynnistys palauttaa pienennetyn ohjausikkunan ja tuo sen etualalle. Siirry säätimien välillä Tab- ja Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat komennon. Esc sulkee aktiivisen Ohje- tai Tietoja-ikkunan; ohjausikkunassa se sulkee sovelluksen. Keskeytys ja näytönsäästäjän esto koskevat koko sovellusta näytön valinnasta riippumatta. Kun esto on käytössä, Windowsin näytönsäästäjä estetään vain, kun vähintään yhdessä näytössä näkyy animaatio, jota ei ole keskeytetty.

### KUVAKAAPPAUKSET JA TALLENNUS

Tilannekuvat ja tallenteet käyttävät ensimmäistä aktiivista animaationäyttöä, eivät kaikkien näyttöjen yhdistettyä kuvaa. BMP/GIF/JPEG/PNG/TIFF/WebP käyttää Kuvat-kansiota ja MP4 Videot-kansiota; jos niitä ei ole, käytetään Tiedostot-kansiota. Tallennusasetukset-painikkeella valitaan Viewport tai TV. Viewport säilyttää animaationäytön koon ja virkistystaajuuden, enintään 60 kuvaa sekunnissa. TV tarjoaa tarkkuudet 1920 × 1080, 1440 × 1080 ja 1280 × 720 kuvasuhteella 16:9 sekä taajuudet 50, 25, 59.94 (60000/1001) ja 29.97 (30000/1001) kuvaa sekunnissa. Kuvasuhde säilyy; TV käyttää progressiivista BT.709-videota rajatulla alueella ja 4:2:0-näytteistyksellä. Tarkkuus ja kuvataajuus ovat valittavissa vain TV-tilassa. Tallennusasetukset-ikkunan voi pienentää, eikä se estä muiden sovellusikkunoiden käyttöä. OK tallentaa valinnat seuraavaa MP4-tallennusta varten; Peruuta tai Esc hylkää vahvistamattomat muutokset. Tallennettavan näytön animaatioulostuloa ei voi poistaa käytöstä tallennuksen aikana; muiden näyttöjen muutokset eivät pysäytä tallennusta. Sovelluksen sulkeminen tallennuksen aikana vaatii vahvistuksen, sillä myös tallennus päättyy.

### ESIKATSELU JA KÄYTTÖ

Ota esikatselu käyttöön käynnistää koko näytön esikatselun kaikilla näytöillä. Asetusikkuna pysyy avoinna, ja muutokset näkyvät heti. OK tallentaa asetukset ja Peruuta hylkää muutokset. Esc tai hiiren liike lopettaa koko näytön säästäjän. Siirry säätimien välillä Tab- ja Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat komennon. Esc asetuksissa vastaa Peruuta-painiketta; Ohje- tai Tietoja-ikkunassa se sulkee vain kyseisen ikkunan.

### Järjestelmävaatimukset

Windows 7–Windows 11 tukevat kaikkia toimintoja, myös BMP/GIF/JPEG/PNG/TIFF/WebP-tilannekuvia ja MP4-tallennusta. Sovelluksen suorittaminen Windows Vista SP2:ssa edellyttää päivitysten KB971512 ja KB2117917 asentamista. MP4-tallennus ei toimi Vistassa nykyisessä versiossa. Näyttäminen vaatii Direct3D 11:n, ei pelkästään vanhempaa DirectX-ajoympäristöä. MP4-tallennus vaatii käytettävissä olevat Media Foundation -komponentit ja H.264-enkooderin. Itsenäinen sovellus voi toimia myös Linuxissa Winen kautta; näytönsäästäjäintegraatio on käytettävissä vain Windowsissa.

## Koonti

Avaa `DispSavers.slnx` Visual Studiossa käyttäen MSVC v145:tä ja Windows SDK:ta. Valitse `Release | x86` ja kokoa ratkaisu uudelleen, jolloin syntyvät `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\GameOfLife.exe`, `Release\GameOfLife.scr`, `Release\SpaceFlight.exe` ja `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr`. x64-kokoonpanoa ei ole.

Paketoi nämä koontitulokset suorittamalla `PackageRelease.ps1` ilman allekirjoitusparametreja. Skripti käyttää väliaikaisia kopioita, ei muuta `Release`-hakemiston tiedostoja ja ainoastaan tarkistaa olemassa olevat kelvolliset allekirjoitukset. Se luo yhden `DispSavers-<version>-win32.zip`-arkiston, jossa ovat `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `GameOfLife\GameOfLife.exe`, `GameOfLife\GameOfLife.scr`, `GameOfLife\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` ja `SpaceFlight\license.txt`. Edellinen ZIP poistetaan suorituksen alussa; tarkistusvirhe estää uuden arkiston luomisen.

## Lisenssi

DispSavers on saatavana [MIT-lisenssillä](../license.txt). Copyright © Petr Červinka — FortSoft 2026
