# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · **Suomi** · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids on natiivi Win32/x86 Direct3D -sovellus ja Windowsin näytönsäästäjä, joka näyttää valaistuja kiinteitä kolmiulotteisia geometrisia kappaleita. Kappaleet liikkuvat ja pyörivät itsenäisesti ja törmäävät läpäisemättä toisiaan. Alkutilat ja uudet lentosijainnit saadaan Windowsin kryptografisesta generaattorista ja puskuroidaan vähäistä suoritinkuormaa varten.

## Ominaisuudet

- **Avaruuden tarkkailu** ja suora **Lento avaruuden halki**
- Päävalo ja täytevalo voidaan kytkeä toisistaan riippumatta
- Itsenäinen näkymä jokaisella valitulla näytöllä
- Yhdestä kymmeneen kopiota jokaisesta käytössä olevasta kappaleesta
- Kohteiden ja kameran nopeus 0–1600 %, koko 50–200 %
- Kiiltävä valaistus, omat värit ja törmäysten käsittely
- Kunkin näytön virkistystaajuuteen mukautuva piirto
- PNG-kuvat ja MP4-tallennus erillisessä sovelluksessa
- Erilliset asetukset sovellukselle ja näytönsäästäjälle
- 27 kappaletyyppiä ja käyttöliittymä 17 kielellä

## Geometriset kappaleet

Valikoimaan kuuluu monitahokkaita, säännöllisiä prismoja, pyramideja ja tasoleikkauksia, kartioita ja lieriöitä leikkauksineen, tasolla suljettu pyörähdysparaboloidi, pallosta johdettuja kappaleita, ellipsoideja, ovoidi, sferosylinteri ja torus. Käyttöliittymä käyttää vakiintunutta suomenkielistä geometrian sanastoa.

## Valaistus

Oikeanpuoleisten liukusäätimien alla olevat `Päävalo`- ja `Täytevalo`-valintaruudut kytkevät koko näkymän kaksi valoa päälle tai pois toisistaan riippumatta. Oletuksena `Päävalo` on päällä ja `Täytevalo` pois päältä. Valaistusasetukset tallennetaan erikseen sovellukselle ja näytönsäästäjälle.

## Sovellus ja näytönsäästäjä

`FlyingSolids.exe` pitää yhden ohjausikkunan käytettävissä animaation aikana. Useita näyttöjä voi valita, rivi vaihdetaan kaksoisnapsautuksella ja kaikki näytöt voi irrottaa. PNG tallennetaan oletuksena kansioon **Kuvat**, MP4 kansioon **Videot**, varalla **Tiedostot**. EXE voi asentaa ja poistaa sisäisen näytönsäästäjän.

Sovelluksesta voi olla käynnissä vain yksi instanssi. Uusi käynnistys palauttaa pienennetyn ohjausikkunan, piirtää sen uudelleen ja tuo sen etualalle.

Siirry säätimien välillä Tab- ja Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat komennon. Esc sulkee aktiivisen Ohje- tai Tietoja-ikkunan; ohjausikkunassa se sulkee sovelluksen.

Tilannekuvat ja tallenteet käyttävät ensimmäistä aktiivista animaationäyttöä, eivät kaikkien näyttöjen yhdistettyä kuvaa. PNG käyttää Kuvat-kansiota ja MP4 Videot-kansiota; jos niitä ei ole, käytetään Tiedostot-kansiota. MP4-tallennus seuraa näytön virkistystaajuutta, enintään 60 kuvaa sekunnissa.

`FlyingSolids.scr` käyttää omia asetuksia ilman tallennusta. Koko näytön tila avaa itsenäisen näkymän jokaiselle näytölle.

Ota esikatselu käyttöön asetuksissa käynnistää erillisen koko näytön esikatselun kaikilla näytöillä. Se käyttää nykyisiä asetuksia, sallii muutokset esikatselun aikana ja voidaan pysäyttää. Mikä tahansa näppäin, hiiren liike tai napsautus lopettaa koko näytön säästäjän.

Esc asetuksissa vastaa Peruuta-painiketta; Ohje- tai Tietoja-ikkunassa se sulkee vain kyseisen ikkunan.

## Asetukset

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Järjestelmävaatimukset

Windows 7–Windows 11 tukevat kaikkia toimintoja, myös PNG-tilannekuvia ja MP4-tallennusta.

Windows Vista SP2: KB971512, KB2117917. MP4-tallennus ei toimi Vistassa nykyisessä versiossa.

Näyttäminen vaatii Direct3D 11:n, ei pelkästään vanhempaa DirectX-ajoympäristöä. MP4-tallennus vaatii käytettävissä olevat Media Foundation -komponentit ja H.264-enkooderin.

## Koonti

Avaa `DispSavers.slnx`, valitse `Release | x86` ja kokoa ratkaisu uudelleen MSVC v145:llä ja Windows SDK:lla. EXE ja SCR syntyvät yhdessä. `PackageRelease.ps1` luo ratkaisun yhteisen `DispSavers-<version>-win32.zip`-paketin, jossa tiedostot ja `license.txt` ovat `FlyingSolids`-alihakemistossa. x64-kokoonpanoa ei ole.

## Lisenssi

FlyingSolids on saatavana [MIT-lisenssillä](../license.txt).

Copyright © Petr Červinka — FortSoft 2026
