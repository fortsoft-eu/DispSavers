# FlightCorridor

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · **Slovenčina** · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlightCorridor ponúka Prelet štyrmi premenlivými plochami a Prelet premenlivým lievikom. Každému monitoru priradíte práve jeden prelet: označte jeho riadok v zozname a zvoľte príslušný prepínač. V predvolenom stave je na všetkých monitoroch zvolená prvá animácia. Predvolené je zobrazenie s textúrou; zrušením voľby Textúra prepnete vybrané monitory na drôtový model. Pri označení viacerých riadkov sa voľba použije pre všetky označené monitory. Jazdec nastavuje rýchlosť animácie v rozsahu 0–1600 %. EXE predvoleným spustením zapne iba primárny animačný monitor, šetrič všetky monitory. Každý monitor sa vykresľuje podľa vlastnej obnovovacej frekvencie. Nastavenia sa ukladajú zvlášť pre aplikáciu a šetrič obrazovky. Voľba Prevaľovanie kamery zapne na označených monitoroch plynulé otáčanie pohľadu do všetkých smerov; predvolene je vypnutá. Voľba Zastavovanie a zmeny smeru pridá v náhodných intervaloch plynulé brzdenie prevaľovania kamery, krátke zastavenie a rozbeh opačným smerom. Je dostupná pri zapnutom prevaľovaní a predvolene je vypnutá; samotný prelet pokračuje.

## Aplikácia

`FlightCorridor.exe`

V zozname možno označiť viac monitorov; dvojklik zapína alebo vypína animáciu na monitore a možno zrušiť aj výber všetkých. Každý monitor používa nezávislú scénu. Snímka uloží PNG a tlačidlo záznamu spustí alebo ukončí MP4. Pozastavenie zastaví animáciu. Aplikácia tiež nainštaluje alebo odinštaluje vložený šetrič. Nastavenia sa ukladajú priebežne. Aplikácia beží iba v jednej inštancii. Ďalšie spustenie obnoví minimalizované ovládacie okno a prenesie do popredia. Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a príslušného písmena. Esc zavrie aktívne okno Pomocníka alebo O aplikácii; v ovládacom okne ukončí aplikáciu. Voľba Blokovať šetrič pri animácii bráni spusteniu šetriča Windows iba vtedy, keď je animácia skutočne viditeľná a nie je pozastavená.

Snímky a záznamy zachytávajú prvý aktívny animačný monitor, nie spoločnú plochu všetkých monitorov. PNG používa Obrázky, MP4 Videá; ak tieto priečinky neexistujú, použijú sa Dokumenty. Tlačidlo Nastavenie záznamu vyberá Viewport alebo TV. Viewport zachováva rozmery animačného monitora a jeho obnovovaciu frekvenciu, najviac 60 snímok za sekundu. TV ponúka rozlíšenie 1920 × 1080, 1440 × 1080 alebo 1280 × 720 v pomere 16:9 a frekvenciu 50, 25, 59.94 (60000/1001) alebo 29.97 (30000/1001) snímok za sekundu. Obraz zachováva pomer strán; TV používa progresívne video BT.709 s obmedzeným rozsahom a vzorkovaním 4:2:0. Rozlíšenie a snímkovú frekvenciu možno vybrať iba v režime TV. Okno Nastavenie záznamu možno minimalizovať a neblokuje ostatné okná aplikácie. OK uloží voľby pre nasledujúci záznam MP4; Zrušiť alebo Esc zahodí nepotvrdené zmeny. Nahrávaný monitor nemožno počas záznamu odpojiť; zmeny ostatných monitorov záznam nezastavia. Ukončenie aplikácie počas záznamu vyžaduje potvrdenie, pretože ukončí aj záznam.

Windows 7 až Windows 11 podporujú všetky funkcie vrátane snímok PNG a záznamu MP4. Na spustenie aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať aktualizácie KB971512 a KB2117917. Záznam MP4 na Viste v súčasnej verzii nefunguje.

## Šetrič obrazovky

`FlightCorridor.scr`

Zapnúť náhľad spustí celoobrazovkový náhľad na všetkých monitoroch; nastavenia zostávajú otvorené a zmeny sa prejavia ihneď. OK uloží nastavenia a Zrušiť ich zahodí. Celoobrazovkový šetrič ukončí Esc alebo pohyb myši. Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a príslušného písmena. Esc v nastaveniach zodpovedá tlačidlu Zrušiť; v Pomocníkovi alebo okne O aplikácii zavrie iba toto okno.

Podporované sú systémy Windows 7 až Windows 11. Na spustenie aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať aktualizácie KB971512 a KB2117917.

## Zostavenie

Otvorte `DispSavers.slnx` vo Visual Studiu s nástrojmi MSVC v145 a Windows SDK. Zvoľte `Release | x86` a znova zostavte riešenie; vzniknú `Release\FlightCorridor.exe` a `Release\FlightCorridor.scr`. Konfigurácia x64 nie je dostupná. Podpisovanie je predvolene zapnuté pre Release aj Debug. Vo vlastnostiach projektu `FlightCorridor` na stránke `Signing` zadajte meno alebo odtlačok platného certifikátu na podpisovanie kódu so súkromným kľúčom v úložisku aktuálneho používateľa `Personal (My)`. Nastavenia sú spoločné pre EXE a SCR a ukladajú sa do súboru `FlightCorridor.vcxproj.user`, ktorý Git ignoruje. SignTool sa automaticky vyhľadá v PATH alebo vo Windows SDK. Ak používate SimplySign, pred zostavením sa prihláste do SimplySign Desktop. Najprv sa podpíše SCR a pridá sa povinná časová pečiatka RFC 3161 so SHA-256 z nastaveného servera časových pečiatok; potom sa vloží do EXE, ktoré tiež dostane podpis a pečiatku. Do poľa `Timestamp server` zadajte adresu servera časových pečiatok RFC 3161. Chyba podpisu, pečiatky alebo overenia zastaví zostavenie; súbory s platným podpisom a pečiatkou sa znovu nepodpisujú.

[MIT License](license.txt) — Copyright © Petr Červinka — FortSoft 2026
