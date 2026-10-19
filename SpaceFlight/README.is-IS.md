# SpaceFlight

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · **Íslenska** · [Türkçe](README.tr-TR.md)

SpaceFlight býður upp á „Óendanleg bylgjandi flötur“ og „Langflug — breytilegur flötur“. Veldu nákvæmlega eitt flug fyrir hvern skjá: veldu röð skjásins og viðeigandi valhnapp. Fyrsta hreyfimyndin er sjálfgefið valin á öllum skjám. Áferð er sjálfgefið virk; taktu hakið úr Áferð til að sýna valda skjái sem víralíkön. Þegar margar raðir eru valdar gildir valið fyrir alla þá skjái. Sleðinn stillir hraða hreyfimyndarinnar frá 0 til 1600 %. Við sjálfgefna ræsingu virkjar EXE aðeins aðalhreyfimyndaskjáinn en skjávarinn alla skjái. Hver skjár er teiknaður á sínum eigin endurnýjunarhraða. Stillingar eru vistaðar sérstaklega fyrir forritið og skjávarann. Frjáls snúningur myndavélar snýr sjónarhorninu mjúklega í allar áttir á völdum skjám; sjálfgefið er slökkt á þessum valkosti. Stopp og stefnuskipti hægir mjúklega á snúningi myndavélarinnar með slembnu millibili, stöðvar hann stuttlega og byrjar aftur í gagnstæða átt. Valkosturinn er tiltækur þegar frjáls snúningur myndavélar er virkur og er sjálfgefið óvirkur; flugið heldur áfram.

## Forrit

`SpaceFlight.exe`

Velja má marga skjái; tvísmellur virkjar eða slekkur á hreyfimynd á skjá og afvelja má alla skjái. Hver skjár notar sjálfstæða senu. Skjámynd vistar PNG og upptökuhnappurinn ræsir eða stöðvar MP4. Hnappurinn Gera hlé stöðvar hreyfimyndina. Forritið setur einnig upp eða fjarlægir innbyggðu skjáhvíluna. Stillingar vistast jafnóðum. Aðeins eitt eintak af forritinu getur verið í gangi í einu. Ný ræsing endurheimtir lágmarkaðan stjórngluggann og færir hann fremst. Notaðu Tab og Shift+Tab til að færa þig milli stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc lokar virka Hjálp- eða Um-glugganum; í stjórnglugganum lokar það forritinu. Hindra skjáhvílu meðan hreyfimynd er í gangi kemur aðeins í veg fyrir að skjáhvíla Windows fari í gang meðan hreyfimyndin er í raun sýnileg og ekki í pásu.

Skjámyndir og upptökur nota fyrsta virka hreyfimyndaskjáinn, ekki sameinaða mynd af öllum skjám. PNG notar Myndir, MP4 Myndbönd; ef þær möppur eru ekki til er Skjöl notuð. Hnappurinn Upptökustillingar velur Viewport eða TV. Viewport varðveitir stærð og endurnýjunartíðni hreyfimyndaskjásins, þó mest 60 ramma á sekúndu. TV býður upp á 1920 × 1080, 1440 × 1080 eða 1280 × 720 í hlutfallinu 16:9 með 50, 25, 59.94 (60000/1001) eða 29.97 (30000/1001) römmum á sekúndu. Hlutföll myndarinnar haldast; TV notar stigvaxandi BT.709-myndband með takmörkuðu sviði og 4:2:0-sýnatöku. Upplausn og rammatíðni eru aðeins valanleg í TV-ham. Hægt er að lágmarka gluggann Upptökustillingar og hann hindrar ekki notkun annarra glugga forritsins. Í lagi vistar valið fyrir næstu MP4-upptöku; Hætta við eða Esc hendir óstaðfestum breytingum. Ekki er hægt að afvelja skjáinn sem er tekinn upp meðan upptaka stendur yfir; breytingar á öðrum skjám stöðva ekki upptökuna. Staðfesta þarf lokun forritsins meðan upptaka stendur yfir, því hún stöðvar líka upptökuna.

Windows 7 til Windows 11 styðja alla eiginleika, þar á meðal PNG-skjámyndir og MP4-upptöku. Til að keyra forritið á Windows Vista SP2 þarf að setja upp uppfærslurnar KB971512 og KB2117917. MP4-upptaka virkar ekki í Vista í núverandi útgáfu.

## Skjávari

`SpaceFlight.scr`

Virkja forskoðun ræsir forskoðun á öllum skjám. Stillingaglugginn helst opinn og breytingar sjást strax. Í lagi vistar stillingar og Hætta við hafnar breytingum. Esc eða músarhreyfing lokar skjáhvílu á öllum skjánum. Notaðu Tab og Shift+Tab til að færa þig milli stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc í stillingum jafngildir Hætta við; í Hjálp eða Um lokar það aðeins þeim glugga.

Windows 7 til Windows 11 eru studd. Til að keyra forritið á Windows Vista SP2 þarf að setja upp uppfærslurnar KB971512 og KB2117917.

## Bygging

Opnaðu `DispSavers.slnx` í Visual Studio með MSVC v145 og Windows SDK. Veldu `Release | x86` og endursmíðaðu lausnina til að búa til `Release\SpaceFlight.exe` og `Release\SpaceFlight.scr`. Engin x64-stilling er til. Undirritun er sjálfgefið virk fyrir bæði Release og Debug. Á síðunni `Signing` í eiginleikum verkefnisins `SpaceFlight` skaltu gefa upp nafn eða fingrafar gilds vottorðs fyrir undirritun forritskóða með einkalykli í vottorðageymslunni `Personal (My)` fyrir núverandi notanda. Stillingarnar gilda fyrir EXE og SCR og eru vistaðar í `SpaceFlight.vcxproj.user`, sem Git hunsar. SignTool finnst sjálfkrafa í PATH eða Windows SDK. Ef þú notar SimplySign skaltu skrá þig inn í SimplySign Desktop fyrir smíðina. Fyrst er SCR undirritað og fær skyldubundinn RFC 3161 SHA-256-tímastimpil frá stillta tímastimpilsþjóninum; síðan er það fellt inn í EXE, sem einnig er undirritað og tímastimplað. Sláðu inn URL-slóð RFC 3161-tímastimpilsþjónsins í reitinn `Timestamp server`. Villa við undirritun, tímastimplun eða sannprófun stöðvar smíðina; skrár með gildum undirritunum og tímastimpli eru ekki undirritaðar aftur.

[MIT License](license.txt) — Copyright © Petr Červinka — FortSoft 2026
