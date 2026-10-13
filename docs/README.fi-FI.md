# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · **Suomi** · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids on natiivi Win32/x86 Direct3D -sovellus ja Windowsin näytönsäästäjä, joka näyttää valaistuja kiinteitä kolmiulotteisia geometrisia kappaleita. Kappaleet liikkuvat ja pyörivät itsenäisesti ja törmäävät läpäisemättä toisiaan.

## Ominaisuudet

- **Avaruuden tarkkailu** ja suora **Lento avaruuden halki**
- Päävalon, täytevalon, ympäristövalon ja reunavalon riippumaton ohjaus
- Itsenäinen näkymä jokaisella valitulla näytöllä
- Yhdestä kymmeneen kopiota jokaisesta käytössä olevasta kappaleesta
- Kohteiden ja kameran nopeus 0–1600 %, koko 50–200 %
- Kiiltävä valaistus, omat värit ja törmäysten käsittely
- Kunkin näytön virkistystaajuuteen mukautuva piirto
- PNG-kuvat ja MP4-tallennus erillisessä sovelluksessa
- Erilliset asetukset sovellukselle ja näytönsäästäjälle
- 30 kappaletyyppiä ja käyttöliittymä 17 kielellä

## Geometriset kappaleet

Valikoimaan kuuluu monitahokkaita, säännöllisiä prismoja, pyramideja ja tasoleikkauksia, kartioita ja lieriöitä leikkauksineen, tasolla suljettu pyörähdysparaboloidi, pallosta johdettuja kappaleita, ellipsoideja, ovoidi, sferosylinteri ja torus. Käyttöliittymä käyttää vakiintunutta suomenkielistä geometrian sanastoa.

## Valaistus

Liukusäätimien alla olevat `Päävalo`-, `Täytevalo`-, `Ympäristövalo`- ja `Reunavalo`-valintaruudut ohjaavat koko näkymän valaistusta toisistaan riippumatta. Ympäristövalo antaa pinnoille perusvalaistuksen ja reunavalo korostaa reunoja. Oletuksena päävalo, ympäristövalo ja reunavalo ovat päällä ja täytevalo pois päältä. Asetukset tallennetaan erikseen sovellukselle ja näytönsäästäjälle.

## Sovellus ja näytönsäästäjä

`FlyingSolids.exe` pitää yhden ohjausikkunan käytettävissä animaation aikana. Useita näyttöjä voi valita, rivi vaihdetaan kaksoisnapsautuksella ja kaikki näytöt voi irrottaa. EXE voi asentaa ja poistaa sisäisen näytönsäästäjän. Sovelluksesta voi olla käynnissä vain yksi instanssi. Uusi käynnistys palauttaa pienennetyn ohjausikkunan ja tuo sen etualalle. Siirry säätimien välillä Tab- ja Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat komennon. Esc sulkee aktiivisen Ohje- tai Tietoja-ikkunan; ohjausikkunassa se sulkee sovelluksen. Tilannekuvat ja tallenteet käyttävät ensimmäistä aktiivista animaationäyttöä, eivät kaikkien näyttöjen yhdistettyä kuvaa. PNG käyttää Kuvat-kansiota ja MP4 Videot-kansiota; jos niitä ei ole, käytetään Tiedostot-kansiota. Tallennusasetukset-painikkeella valitaan Viewport tai TV. Viewport säilyttää animaationäytön koon ja virkistystaajuuden, enintään 60 kuvaa sekunnissa. TV tarjoaa tarkkuudet 1920 × 1080, 1440 × 1080 ja 1280 × 720 kuvasuhteella 16:9 sekä taajuudet 50, 25, 59.94 (60000/1001) ja 29.97 (30000/1001) kuvaa sekunnissa. Kuvasuhde säilyy; TV käyttää progressiivista BT.709-videota rajatulla alueella ja 4:2:0-näytteistyksellä. Tarkkuus ja kuvataajuus ovat valittavissa vain TV-tilassa. Tallennusasetukset-ikkunan voi pienentää, eikä se estä muiden sovellusikkunoiden käyttöä. OK tallentaa valinnat seuraavaa MP4-tallennusta varten; Peruuta tai Esc hylkää vahvistamattomat muutokset. Tallennettavan näytön valintaa ei voi poistaa tallennuksen aikana; muiden näyttöjen muutokset eivät pysäytä tallennusta. Sovelluksen sulkeminen tallennuksen aikana vaatii vahvistuksen, sillä myös tallennus päättyy. Estä näytönsäästäjä animaation aikana estää Windowsin näytönsäästäjän käynnistymisen vain silloin, kun animaatio on todella näkyvissä eikä sitä ole keskeytetty. `FlyingSolids.scr` käyttää omia asetuksia ilman tallennusta. Koko näytön tila avaa itsenäisen näkymän jokaiselle näytölle. Ota esikatselu käyttöön asetuksissa käynnistää erillisen koko näytön esikatselun kaikilla näytöillä. Se käyttää nykyisiä asetuksia, sallii muutokset esikatselun aikana ja voidaan pysäyttää. Mikä tahansa näppäin, hiiren liike tai napsautus lopettaa koko näytön säästäjän. Esc asetuksissa vastaa Peruuta-painiketta; Ohje- tai Tietoja-ikkunassa se sulkee vain kyseisen ikkunan.

## Asetukset

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Järjestelmävaatimukset

Windows 7–Windows 11 tukevat kaikkia toimintoja, myös PNG-tilannekuvia ja MP4-tallennusta. Sovelluksen suorittaminen Windows Vista SP2:ssa edellyttää päivitysten KB971512 ja KB2117917 asentamista. MP4-tallennus ei toimi Vistassa nykyisessä versiossa. Näyttäminen vaatii Direct3D 11:n, ei pelkästään vanhempaa DirectX-ajoympäristöä. MP4-tallennus vaatii käytettävissä olevat Media Foundation -komponentit ja H.264-enkooderin.

## Koonti

Avaa `DispSavers.slnx` Visual Studiossa käyttäen MSVC v145:tä ja Windows SDK:ta. Valitse `Release | x86` ja kokoa ratkaisu uudelleen, jolloin syntyvät `Release\FlyingSolids.exe` ja `Release\FlyingSolids.scr`. x64-kokoonpanoa ei ole. Allekirjoitus on oletuksena käytössä sekä Release- että Debug-kokoonpanossa. Anna `FlyingSolids`-projektin ominaisuuksien `Signing`-sivulla nykyisen käyttäjän `Personal (My)`-varastossa olevan voimassa olevan koodin allekirjoitusvarmenteen nimi tai sormenjälki; varmenteella on oltava yksityinen avain. Asetukset koskevat EXE- ja SCR-tiedostoja, ja ne tallennetaan Gitin ohittamaan `FlyingSolids.vcxproj.user`-tiedostoon. SignTool etsitään automaattisesti PATH-muuttujasta tai Windows SDK:sta. Jos käytät SimplySignia, kirjaudu SimplySign Desktopiin ennen koontia. Ensin SCR allekirjoitetaan ja siihen lisätään pakollinen RFC 3161 SHA-256 -aikaleima määritetyltä aikaleimapalvelimelta; sen jälkeen SCR upotetaan EXE-tiedostoon, joka myös allekirjoitetaan ja aikaleimataan. Anna RFC 3161 -aikaleimapalvelimen URL-osoite `Timestamp server`-kenttään. Allekirjoituksen, aikaleiman tai tarkistuksen virhe keskeyttää koonnin; kelvollisesti allekirjoitettuja ja aikaleimattuja tiedostoja ei allekirjoiteta uudelleen.

Paketoi nämä koontitulokset suorittamalla `PackageRelease.ps1` ilman allekirjoitusparametreja. Skripti käyttää väliaikaisia kopioita, ei muuta `Release`-hakemiston tiedostoja ja ainoastaan tarkistaa olemassa olevat kelvolliset allekirjoitukset. Se luo yhden `DispSavers-<version>-win32.zip`-arkiston, jossa ovat `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr` ja `FlyingSolids\license.txt`. Edellinen ZIP poistetaan suorituksen alussa; tarkistusvirhe estää uuden arkiston luomisen.

## Lisenssi

FlyingSolids on saatavana [MIT-lisenssillä](../license.txt). Copyright © Petr Červinka — FortSoft 2026
