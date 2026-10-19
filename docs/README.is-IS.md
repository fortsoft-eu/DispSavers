# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · **Íslenska** · [Türkçe](README.tr-TR.md)

FlyingSolids er innbyggt Win32/x86 Direct3D-forrit og Windows-skjáhvíla sem sýnir upplýsta heila þrívíddarfræðilega hluti. Hlutirnir hreyfast og snúast sjálfstætt og rekast saman án þess að fara hver í gegnum annan.

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
- 30 tegundir hluta og viðmót á 17 tungumálum

## Rúmfræðilegir hlutir

Úrvalið nær yfir margflötunga, reglulega strendinga, pýramída og planskurði, keilur og sívalninga og planskurði þeirra, snúningsfleygbreiðu lokaða með plani, kúluafleidda hluti, sporvölur, egglaga kropp, kúluhylki og tórus. Viðmótið notar viðurkennd íslensk rúmfræðiheiti.

## Lýsing

Gátreitirnir `Aðalljós`, `Fylliljós`, `Umhverfislýsing` og `Útlínulýsing` undir rennistikunum stýra lýsingu allrar senunnar óháð hver öðrum. Umhverfislýsing gefur yfirborðunum grunnbirtu og útlínulýsing dregur fram jaðrana. Sjálfgefið er kveikt á aðalljósi, umhverfislýsingu og útlínulýsingu en slökkt á fylliljósi. Stillingarnar eru vistaðar sérstaklega fyrir forritið og skjáhvíluna.

## Forrit og skjáhvíla

`FlyingSolids.exe` heldur einum stjórnglugga tiltækum meðan hreyfimyndin keyrir. Velja má marga skjái, tvísmella á línu til að skipta um stöðu hennar eða aftengja alla. EXE-skráin getur sett upp og fjarlægt innbyggðu skjáhvíluna. Aðeins eitt eintak af forritinu getur verið í gangi í einu. Ný ræsing endurheimtir lágmarkaðan stjórngluggann og færir hann fremst. Notaðu Tab og Shift+Tab til að færa þig milli stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc lokar virka Hjálp- eða Um-glugganum; í stjórnglugganum lokar það forritinu. Skjámyndir og upptökur nota fyrsta virka hreyfimyndaskjáinn, ekki sameinaða mynd af öllum skjám. PNG notar Myndir, MP4 Myndbönd; ef þær möppur eru ekki til er Skjöl notuð. Hnappurinn Upptökustillingar velur Viewport eða TV. Viewport varðveitir stærð og endurnýjunartíðni hreyfimyndaskjásins, þó mest 60 ramma á sekúndu. TV býður upp á 1920 × 1080, 1440 × 1080 eða 1280 × 720 í hlutfallinu 16:9 með 50, 25, 59.94 (60000/1001) eða 29.97 (30000/1001) römmum á sekúndu. Hlutföll myndarinnar haldast; TV notar stigvaxandi BT.709-myndband með takmörkuðu sviði og 4:2:0-sýnatöku. Upplausn og rammatíðni eru aðeins valanleg í TV-ham. Hægt er að lágmarka gluggann Upptökustillingar og hann hindrar ekki notkun annarra glugga forritsins. Í lagi vistar valið fyrir næstu MP4-upptöku; Hætta við eða Esc hendir óstaðfestum breytingum. Ekki er hægt að afvelja skjáinn sem er tekinn upp meðan upptaka stendur yfir; breytingar á öðrum skjám stöðva ekki upptökuna. Staðfesta þarf lokun forritsins meðan upptaka stendur yfir, því hún stöðvar líka upptökuna. Hindra skjáhvílu meðan hreyfimynd er í gangi kemur aðeins í veg fyrir að skjáhvíla Windows fari í gang meðan hreyfimyndin er í raun sýnileg og ekki í pásu. `FlyingSolids.scr` hefur eigin stillingar án upptöku. Heilskjár keyrir sjálfstæða senu á hverjum skjá. Virkja forskoðun í stillingum ræsir sérstaka heilskjásforskoðun á öllum skjám. Hún notar núverandi stillingar, leyfir breytingar í rauntíma og má stöðva aftur. Ýttu á hvaða takka sem er, hreyfðu músina eða smelltu með músinni til að loka skjáhvílunni á öllum skjánum. Esc í stillingum jafngildir Hætta við; í Hjálp eða Um lokar það aðeins þeim glugga.

## Stillingar

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Kerfiskröfur

Windows 7 til Windows 11 styðja alla eiginleika, þar á meðal PNG-skjámyndir og MP4-upptöku. Til að keyra forritið á Windows Vista SP2 þarf að setja upp uppfærslurnar KB971512 og KB2117917. MP4-upptaka virkar ekki í Vista í núverandi útgáfu. Birting krefst Direct3D 11, ekki aðeins eldri DirectX-keyrsluumhverfis. MP4-upptaka krefst tiltækra Media Foundation-íhluta og H.264-kóðara.

## Smíði

Opnaðu `DispSavers.slnx` í Visual Studio með MSVC v145 og Windows SDK. Veldu `Release | x86` og endursmíðaðu lausnina til að búa til `Release\FlyingSolids.exe` og `Release\FlyingSolids.scr`. Engin x64-stilling er til. Undirritun er sjálfgefið virk fyrir bæði Release og Debug. Á síðunni `Signing` í eiginleikum verkefnisins `FlyingSolids` skaltu gefa upp nafn eða fingrafar gilds vottorðs fyrir undirritun forritskóða með einkalykli í vottorðageymslunni `Personal (My)` fyrir núverandi notanda. Stillingarnar gilda fyrir EXE og SCR og eru vistaðar í `FlyingSolids.vcxproj.user`, sem Git hunsar. SignTool finnst sjálfkrafa í PATH eða Windows SDK. Ef þú notar SimplySign skaltu skrá þig inn í SimplySign Desktop fyrir smíðina. Fyrst er SCR undirritað og fær skyldubundinn RFC 3161 SHA-256-tímastimpil frá stillta tímastimpilsþjóninum; síðan er það fellt inn í EXE, sem einnig er undirritað og tímastimplað. Sláðu inn URL-slóð RFC 3161-tímastimpilsþjónsins í reitinn `Timestamp server`. Villa við undirritun, tímastimplun eða sannprófun stöðvar smíðina; skrár með gildum undirritunum og tímastimpli eru ekki undirritaðar aftur.

Pakkaðu þessum smíðaskrám með því að keyra `PackageRelease.ps1` án undirritunarfæribreyta. Forskriftin notar tímabundin afrit, breytir ekki skrám í `Release` og sannprófar aðeins gildar undirritanir sem þegar eru til. Hún býr til eitt safn, `DispSavers-<version>-win32.zip`, með `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` og `SpaceFlight\license.txt`. Fyrra ZIP-safnið er fjarlægt í upphafi keyrslu; sannprófunarvilla kemur í veg fyrir að nýtt safn verði búið til.

## Leyfi

FlyingSolids er gefið út samkvæmt [MIT-leyfinu](../license.txt). Copyright © Petr Červinka — FortSoft 2026


## FlightCorridor

FlightCorridor býður upp á Flug milli fjögurra breytilegra flata og Flug í gegnum breytilega trekt. Veldu nákvæmlega eitt flug fyrir hvern skjá: veldu röð skjásins og viðeigandi valhnapp. Fyrsta hreyfimyndin er sjálfgefið valin á öllum skjám.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](../FlightCorridor/README.is-IS.md)

## SpaceFlight

SpaceFlight býður upp á „Óendanleg bylgjandi flötur“ og „Langflug — breytilegur flötur“. Veldu nákvæmlega eitt flug fyrir hvern skjá: veldu röð skjásins og viðeigandi valhnapp. Fyrsta hreyfimyndin er sjálfgefið valin á öllum skjám.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](../SpaceFlight/README.is-IS.md)
