# SpaceFlight

**Čeština** · [English (US)](README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

SpaceFlight nabízí „Nekonečná vlnící se plocha“ a „Dálkový let — proměnlivá plocha“. Každému monitoru přiřadíte právě jeden průlet: označte jeho řádek v seznamu a zvolte příslušný přepínač. Ve výchozím stavu je na všech monitorech zvolena první animace. Výchozí je zobrazení s texturou; zrušením volby Textura přepnete vybrané monitory na drátěný model. Při označení více řádků se volba použije pro všechny označené monitory. Jezdec nastavuje rychlost animace v rozsahu 0–1600 %. EXE výchozím spuštěním zapne pouze primární animační monitor, spořič všechny monitory. Každý monitor se vykresluje podle vlastní obnovovací frekvence. Nastavení se ukládá zvlášť pro aplikaci a spořič obrazovky. Volba Převalování kamery zapne na označených monitorech plynulé otáčení pohledu do všech směrů; ve výchozím stavu je vypnutá. Volba Zastavování a změny směru přidá v náhodných intervalech plynulé brzdění převalování kamery, krátké zastavení a rozběh opačným směrem. Je dostupná při zapnutém převalování a ve výchozím stavu je vypnutá; samotný průlet pokračuje.

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

Otevřete `DispSavers.slnx` ve Visual Studiu s nástroji MSVC v145 a Windows SDK. Zvolte `Release | x86` a znovu sestavte celé řešení; vzniknou `Release\SpaceFlight.exe` a `Release\SpaceFlight.scr`. Konfigurace x64 není k dispozici. Podepisování je ve výchozím stavu zapnuté pro Release i Debug. Ve vlastnostech projektu `SpaceFlight` na stránce `Signing` zadejte jméno nebo otisk platného certifikátu pro podepisování kódu se soukromým klíčem v úložišti aktuálního uživatele `Personal (My)`. Nastavení je společné pro EXE a SCR a ukládá se do souboru `SpaceFlight.vcxproj.user`, který Git ignoruje. SignTool se vyhledá automaticky v PATH nebo ve Windows SDK. Používáte-li SimplySign, před sestavením se přihlaste v SimplySign Desktop. Sestavení nejprve podepíše SCR, přidá povinné časové razítko RFC 3161 se SHA-256 z nastaveného serveru časových razítek a teprve potom jej vloží do EXE, které také podepíše a opatří razítkem. Do pole `Timestamp server` zadejte adresu serveru časových razítek RFC 3161. Chyba podpisu, razítka nebo jejich ověření sestavení zastaví; již platné podepsané soubory s razítkem se znovu nepodepisují.

[MIT License](license.txt) — Copyright © Petr Červinka — FortSoft 2026
