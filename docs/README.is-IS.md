# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · **Íslenska** · [Türkçe](README.tr-TR.md)

FlyingSolids er innbyggt Win32/x86 Direct3D-forrit og Windows-skjáhvíla sem sýnir upplýsta heila þrívíddarfræðilega hluti. Hlutirnir hreyfast og snúast sjálfstætt og rekast saman án þess að fara hver í gegnum annan. Upphafsstöður og nýjar flugstöður koma frá dulritunarlega slembigjafa Windows og eru geymdar í biðminni til að halda örgjörvaálagi lágu.

## Eiginleikar

- **Athugun rýmis** og beint **Flug um rýmið**
- Hægt er að kveikja og slökkva á aðalljósi og fylliljósi óháð hvort öðru
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

- Ílöng snúningssporvala hefur einn lengri hálfás og tvo jafn langa styttri hálfása.
- Rúnaður diskur (spheroplatelet) hefur tvo flata hringlaga fleti og samfellt rúnnaðan jaðar; þvermál hans er örlítið stærra en þvermál kúlulags og þykktin helmingur þykktar kúlulags.
- Holur sívalningur með tórusendum hefur ytri og innri sívalningsfleti tengda með hálfum tórusum, sem mynda nákvæma hálfhringi í áslægum þverskurði.

## Lýsing

Gátreitirnir `Aðalljós` og `Fylliljós` undir rennistikunum hægra megin kveikja eða slökkva á ljósunum tveimur óháð hvort öðru fyrir alla senuna. Sjálfgefið er kveikt á `Aðalljós` og slökkt á `Fylliljós`. Ljósastillingar eru vistaðar sérstaklega fyrir forritið og skjáhvíluna.

## Forrit og skjáhvíla

`FlyingSolids.exe` heldur einum stjórnglugga tiltækum meðan hreyfimyndin keyrir. Velja má marga skjái, tvísmella á línu til að skipta um stöðu hennar eða aftengja alla. PNG vistast sjálfgefið í **Myndir**, MP4 í **Myndbönd**, en **Skjöl** eru varamappa. EXE-skráin getur sett upp og fjarlægt innbyggðu skjáhvíluna.

Aðeins eitt eintak af forritinu getur verið í gangi í einu. Ný ræsing endurheimtir lágmarkaðan stjórngluggann, endurteiknar hann og færir hann fremst.

Notaðu Tab og Shift+Tab til að færa þig milli stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc lokar virka Hjálp- eða Um-glugganum; í stjórnglugganum lokar það forritinu.

Skjámyndir og upptökur nota fyrsta virka hreyfimyndaskjáinn, ekki sameinaða mynd af öllum skjám. PNG notar Myndir, MP4 Myndbönd; ef þær möppur eru ekki til er Skjöl notuð. MP4-upptaka fylgir endurnýjunartíðni skjásins, þó mest 60 römmum á sekúndu.

`FlyingSolids.scr` hefur eigin stillingar án upptöku. Heilskjár keyrir sjálfstæða senu á hverjum skjá.

Virkja forskoðun í stillingum ræsir sérstaka heilskjásforskoðun á öllum skjám. Hún notar núverandi stillingar, leyfir breytingar í rauntíma og má stöðva aftur. Ýttu á hvaða takka sem er, hreyfðu músina eða smelltu með músinni til að loka skjáhvílunni á öllum skjánum.

Esc í stillingum jafngildir Hætta við; í Hjálp eða Um lokar það aðeins þeim glugga.

## Stillingar

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Kerfiskröfur

Windows 7 til Windows 11 styðja alla eiginleika, þar á meðal PNG-skjámyndir og MP4-upptöku.

Til að keyra forritið á Windows Vista SP2 þarf að setja upp uppfærslurnar KB971512 og KB2117917. MP4-upptaka virkar ekki í Vista í núverandi útgáfu.

Birting krefst Direct3D 11, ekki aðeins eldri DirectX-keyrsluumhverfis. MP4-upptaka krefst tiltækra Media Foundation-íhluta og H.264-kóðara.

## Smíði

Opnaðu `DispSavers.slnx`, veldu `Release | x86` og endursmíðaðu lausnina með MSVC v145 og Windows SDK. EXE og SCR verða til saman. `PackageRelease.ps1` býr til eina lausnarpakkann `DispSavers-<version>-win32.zip`, þar sem skrárnar og `license.txt` eru í undirmöppunni `FlyingSolids`. Engin x64-stilling er til.

## Leyfi

FlyingSolids er gefið út samkvæmt [MIT-leyfinu](../license.txt).

Copyright © Petr Červinka — FortSoft 2026
