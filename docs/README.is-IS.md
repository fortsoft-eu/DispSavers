# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · **Íslenska** · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlyingSolids er innbyggt Win32/x86 Direct3D-forrit og Windows-skjáhvíla sem sýnir upplýsta heila þrívíddarfræðilega hluti. Hlutirnir hreyfast og snúast sjálfstætt og rekast saman án þess að fara hver í gegnum annan.

Val lína ákvarðar hvaða skjám er verið að breyta og er óháð gátreitunum sem kveikja á hreyfimyndaúttaki. Ctrl+A velur alla skjái; Ctrl og Shift breyta valinu. Allir valkostir og sleðar hreyfimynda gilda fyrir valda skjái. Valið er munað sérstaklega fyrir EXE og SCR. Ef allir skjáir voru valdir bætast nýir skjáir einnig við valið. Mismunandi gildi á völdum skjám eru sýnd með óákveðnu ástandi gátreita og punktamynstri á valhnöppum, handföngum sleða og hnöppum sem kveikja eða slökkva á öllum valkostum. Merking sleða sýnir strik í stað sameiginlegs gildis. Að breyta valkosti eða smella á sleða setur það gildi á alla valda skjái.

## Eiginleikar

- **Athugun rýmis** og beint **Flug um rýmið**. Veldu einn eða fleiri skjái á listanum. Myndavélarhamur, hlutir, lýsing, hraði, stærð og fjöldi eintaka eiga aðeins við um valda skjái. Hver skjár geymir sínar eigin stillingar.
- Óháð stýring á aðalljósi, fylliljósi, umhverfislýsingu og útlínulýsingu
- Sjálfstæð sena á hverjum völdum skjá
- Eitt til tíu eintök af hverjum virkum hlut
- Hraði hluta og myndavélar 0–1600%, stærð 50–200%
- Gljáandi lýsing, sérlitir og árekstrameðferð
- Myndgerð löguð að endurnýjunartíðni hvers skjás
- PNG-skjámyndir og MP4-upptaka í sjálfstæða forritinu
- Aðskildar stillingar forrits og skjáhvílu
- 30 tegundir hluta og viðmót á 36 tungumálum

## Rúmfræðilegir hlutir

Teningur; Reglulegur ferstrendur pýramídi; Stýfður ferstrendur pýramídi; Ferstrendur pýramídi skorinn með skáplani; Pýramídi, skurðplan hornrétt á grunnflöt; Reglulegur þrístrendingur; Reglulegur fimmstrendingur; Reglulegur sexstrendingur; Reglulegur áttflötungur; Fimmhyrndur tvípýramídi; Rétt hringkeila; Stýfð keila; Keila skorin með skáplani; Keila, skurður hornréttur á grunnflöt; Réttur hringsívalningur; Holur sívalningur; Holur sívalningur með tórusendum; Lokaður snúningsfleygbogaflötur; Kúla; Hálfkúla; Kúluhluti; Stór kúluhluti; Kúlulag; Þríása sporvala; Ílöng snúningssporvala; Flöt snúningssporvala; Egglaga rúmhlutur; Kúluhylki; Rúnaður diskur (spheroplatelet); Tórus.

## Lýsing

Gátreitirnir `Aðalljós`, `Fylliljós`, `Umhverfislýsing` og `Útlínulýsing` undir rennistikunum stýra lýsingu allrar senunnar óháð hver öðrum. Umhverfislýsing gefur yfirborðunum grunnbirtu og útlínulýsing dregur fram jaðrana. Stillingarnar eru vistaðar sérstaklega fyrir forritið og skjáhvíluna.

## Forrit og skjáhvíla

`FlyingSolids.exe` heldur einum stjórnglugga tiltækum meðan hreyfimyndin keyrir. Kveiktu eða slökktu á hreyfimyndaúttaki með gátreitum skjáanna eða með því að tvísmella á línur þeirra. EXE-skráin getur sett upp og fjarlægt innbyggðu skjáhvíluna. Aðeins eitt eintak af forritinu getur verið í gangi í einu. Ný ræsing endurheimtir lágmarkaðan stjórngluggann og færir hann fremst. Notaðu Tab og Shift+Tab til að færa þig milli stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc lokar virka Hjálp- eða Um-glugganum; í stjórnglugganum lokar það forritinu. Skjámyndir og upptökur nota fyrsta virka hreyfimyndaskjáinn, ekki sameinaða mynd af öllum skjám. PNG notar Myndir, MP4 Myndbönd; ef þær möppur eru ekki til er Skjöl notuð. Hnappurinn Upptökustillingar velur Viewport eða TV. Viewport varðveitir stærð og endurnýjunartíðni hreyfimyndaskjásins, þó mest 60 ramma á sekúndu. TV býður upp á 1920 × 1080, 1440 × 1080 eða 1280 × 720 í hlutfallinu 16:9 með 50, 25, 59.94 (60000/1001) eða 29.97 (30000/1001) römmum á sekúndu. Hlutföll myndarinnar haldast; TV notar stigvaxandi BT.709-myndband með takmörkuðu sviði og 4:2:0-sýnatöku. Upplausn og rammatíðni eru aðeins valanleg í TV-ham. Hægt er að lágmarka gluggann Upptökustillingar og hann hindrar ekki notkun annarra glugga forritsins. Í lagi vistar valið fyrir næstu MP4-upptöku; Hætta við eða Esc hendir óstaðfestum breytingum. Ekki er hægt að afvelja skjáinn sem er tekinn upp meðan upptaka stendur yfir; breytingar á öðrum skjám stöðva ekki upptökuna. Staðfesta þarf lokun forritsins meðan upptaka stendur yfir, því hún stöðvar líka upptökuna. Pása og hindrun skjáhvílu gilda fyrir allt forritið, óháð völdum skjám. Þegar hindrun er virk er skjáhvíla Windows aðeins hindruð meðan sýnileg hreyfimynd sem er ekki í pásu er á að minnsta kosti einum skjá. `FlyingSolids.scr` hefur eigin stillingar án upptöku. Heilskjár keyrir sjálfstæða senu á hverjum skjá. Virkja forskoðun í stillingum ræsir sérstaka heilskjásforskoðun á öllum skjám. Hún notar núverandi stillingar, leyfir breytingar í rauntíma og má stöðva aftur. Ýttu á hvaða takka sem er, hreyfðu músina eða smelltu með músinni til að loka skjáhvílunni á öllum skjánum. Esc í stillingum jafngildir Hætta við; í Hjálp eða Um lokar það aðeins þeim glugga.

## Stillingar

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Kerfiskröfur

Windows 7 til Windows 11 styðja alla eiginleika, þar á meðal PNG-skjámyndir og MP4-upptöku. Til að keyra forritið á Windows Vista SP2 þarf að setja upp uppfærslurnar KB971512 og KB2117917. MP4-upptaka virkar ekki í Vista í núverandi útgáfu. Birting krefst Direct3D 11, ekki aðeins eldri DirectX-keyrsluumhverfis. MP4-upptaka krefst tiltækra Media Foundation-íhluta og H.264-kóðara.

## Smíði

Opnaðu `DispSavers.slnx` í Visual Studio með MSVC v145 og Windows SDK. Veldu `Release | x86` og endursmíðaðu lausnina til að búa til `Release\FlyingSolids.exe` og `Release\FlyingSolids.scr`. Engin x64-stilling er til. Á síðunni `Signing` í eiginleikum verkefnisins `FlyingSolids` skaltu gefa upp nafn eða fingrafar gilds vottorðs fyrir undirritun forritskóða með einkalykli í vottorðageymslunni `Personal (My)` fyrir núverandi notanda. Stillingarnar gilda fyrir EXE og SCR og eru vistaðar í `FlyingSolids.vcxproj.user`, sem Git hunsar. SignTool finnst sjálfkrafa í PATH eða Windows SDK. Ef þú notar SimplySign skaltu skrá þig inn í SimplySign Desktop fyrir smíðina. Fyrst er SCR undirritað og fær skyldubundinn RFC 3161 SHA-256-tímastimpil frá stillta tímastimpilsþjóninum; síðan er það fellt inn í EXE, sem einnig er undirritað og tímastimplað. Sláðu inn URL-slóð RFC 3161-tímastimpilsþjónsins í reitinn `Timestamp server`. Villa við undirritun, tímastimplun eða sannprófun stöðvar smíðina; skrár með gildum undirritunum og tímastimpli eru ekki undirritaðar aftur.

Pakkaðu þessum smíðaskrám með því að keyra `PackageRelease.ps1` án undirritunarfæribreyta. Forskriftin notar tímabundin afrit, breytir ekki skrám í `Release` og sannprófar aðeins gildar undirritanir sem þegar eru til. Hún býr til eitt safn, `DispSavers-<version>-win32.zip`, með `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` og `SpaceFlight\license.txt`. Fyrra ZIP-safnið er fjarlægt í upphafi keyrslu; sannprófunarvilla kemur í veg fyrir að nýtt safn verði búið til.

## Leyfi

FlyingSolids er gefið út samkvæmt [MIT-leyfinu](../license.txt). Copyright © Petr Červinka — FortSoft 2026

## FlightCorridor

FlightCorridor býður upp á Flug milli fjögurra breytilegra flata og Flug í gegnum breytilega trekt. Veldu nákvæmlega eitt flug fyrir hvern skjá: veldu röð skjásins og viðeigandi valhnapp.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](../FlightCorridor/README.is-IS.md)

## SpaceFlight

SpaceFlight býður upp á „Óendanleg bylgjandi flötur“ og „Langflug — breytilegur flötur“. Veldu nákvæmlega eitt flug fyrir hvern skjá: veldu röð skjásins og viðeigandi valhnapp.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](../SpaceFlight/README.is-IS.md)
