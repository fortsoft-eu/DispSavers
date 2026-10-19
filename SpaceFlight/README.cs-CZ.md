# SpaceFlight

**Čeština** · [English (US)](README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

SpaceFlight: Nekonečná vlnící se plocha; Dálkový let — proměnlivá plocha. Každému monitoru přiřaďte právě jednu animaci. Textura přepíná mezi texturovanými plochami a drátěným modelem. Převalování kamery pomalu mění směr pohledu ve všech třech rozměrech. Zastavování a změny směru přidává náhodné zpomalování, pauzy a změny směru otáčení; dopředný pohyb pokračuje. Rychlost animace je 0–1600 %. Každý monitor má nezávislou náhodnou scénu a vykreslování podle své obnovovací frekvence.

Označení řádků určuje, které monitory právě nastavujete; není totožné se zatržítky zapínajícími animační výstupy. Ctrl+A označí všechny monitory, Ctrl a Shift umožňují upravit označení. Všechny animační volby a jezdce platí pro označené monitory. Označení se pamatuje zvlášť pro EXE a SCR. Pokud byly označené všechny monitory, označí se i nově připojené.

## Aplikace

`SpaceFlight.exe`

V seznamu lze označit více monitorů; dvojklikem na řádek monitor zapnete nebo vypnete a lze zrušit i výběr všech monitorů. Každý monitor používá nezávislou scénu. Snímek ukládá PNG, tlačítko záznamu spouští a ukončuje MP4. Pozastavení zastaví animaci. Aplikace také instaluje nebo odinstaluje zabalený spořič. Nastavení se ukládá průběžně. Aplikace běží pouze v jedné instanci. Další spuštění obnoví minimalizované ovládací okno a přenese do popředí. Mezi ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a příslušného písmene. Esc zavře aktivní nápovědu či okno O aplikaci; v ovládacím okně ukončí aplikaci. Volba Blokovat spořič při animaci brání spuštění spořiče Windows pouze tehdy, když je animace skutečně viditelná a není pozastavená.

Snímek a záznam zachycují první aktivní animační monitor, nikoli společnou plochu všech monitorů. PNG používá složku Obrázky, MP4 složku Videa; při jejich neexistenci se použijí Dokumenty. Tlačítko Nastavení záznamu vybírá Viewport nebo TV. Viewport zachovává rozměry animačního monitoru a jeho obnovovací frekvenci, nejvýše 60 snímků za sekundu. TV nabízí rozlišení 1920 × 1080, 1440 × 1080 nebo 1280 × 720 v poměru 16:9 a frekvenci 50, 25, 59.94 (60000/1001) nebo 29.97 (30000/1001) snímků za sekundu. Obraz zachovává poměr stran; TV používá progresivní video BT.709 s omezeným rozsahem a vzorkováním 4:2:0. Rozlišení a snímkovou frekvenci lze vybrat pouze v režimu TV. Okno Nastavení záznamu lze minimalizovat a neblokuje ostatní okna aplikace. OK uloží volby pro příští záznam MP4; Storno nebo Esc nepotvrzené změny zahodí. Nahrávaný monitor nelze během záznamu odepnout; změny ostatních monitorů záznam nezastaví. Ukončení aplikace při probíhajícím záznamu vyžaduje potvrzení, protože současně ukončí záznam.

Windows 7 až Windows 11 podporují všechny funkce včetně snímků PNG a záznamu MP4. Pro spuštění aplikace ve Windows Vista SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917. Záznam MP4 na Vistě v současné verzi nefunguje.

## Spořič obrazovky

`SpaceFlight.scr`

Zapnout náhled spustí celoobrazovkový náhled na všech monitorech; změny lze zkoušet za otevřeného nastavení. OK nastavení uloží, Storno je zahodí. Celoobrazovkový spořič ukončíte klávesou Esc nebo pohybem myši. Mezi ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a příslušného písmene. Esc v nastavení odpovídá tlačítku Storno; v nápovědě nebo okně O aplikaci zavře pouze toto okno.

Podporovány jsou systémy Windows 7 až Windows 11. Pro spuštění aplikace ve Windows Vista SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917.

## Sestavení

Otevřete `DispSavers.slnx` ve Visual Studiu s nástroji MSVC v145 a Windows SDK. Zvolte `Release | x86` a znovu sestavte celé řešení; vzniknou `Release\SpaceFlight.exe` a `Release\SpaceFlight.scr`. Konfigurace x64 není k dispozici. Ve vlastnostech projektu `SpaceFlight` na stránce `Signing` zadejte jméno nebo otisk platného certifikátu pro podepisování kódu se soukromým klíčem v úložišti aktuálního uživatele `Personal (My)`. Nastavení je společné pro EXE a SCR a ukládá se do souboru `SpaceFlight.vcxproj.user`, který Git ignoruje. SignTool se vyhledá automaticky v PATH nebo ve Windows SDK. Používáte-li SimplySign, před sestavením se přihlaste v SimplySign Desktop. Sestavení nejprve podepíše SCR, přidá povinné časové razítko RFC 3161 se SHA-256 z nastaveného serveru časových razítek a teprve potom jej vloží do EXE, které také podepíše a opatří razítkem. Do pole `Timestamp server` zadejte adresu serveru časových razítek RFC 3161. Chyba podpisu, razítka nebo jejich ověření sestavení zastaví; již platné podepsané soubory s razítkem se znovu nepodepisují.

[MIT License](license.txt) — Copyright © Petr Červinka — FortSoft 2026
