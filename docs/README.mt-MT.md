# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · **Malti** · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlyingSolids juri solidi tridimensjonali li jiċċaqalqu, iduru u jaħbtu ma’ xulxin. Agħżel osservazzjoni tal-ispazju jew titjira fl-ispazju u attiva l-forom mixtieqa. Għal kull moniter tista’ tissettja separatament il-veloċità tal-oġġetti u l-kamera minn 0–1600%, id-daqs minn 50–200% u 1–10 kopji ta’ kull solidu. Id-dawl ewlieni, id-dawl ta’ mili, id-dawl ambjentali u d-dawl tal-kontorn jinxtegħlu separatament.

## Kontrolli

Agħżel ringiela waħda jew aktar fil-lista tal-moniters. Ctrl+A jagħżilhom kollha; Ctrl u Shift ibiddlu l-għażla. Il-kontrolli u s-sliders tal-animazzjoni jibdlu biss is-settings tal-moniters magħżula. L-għażla ta’ ringiela hija differenti mill-attivazzjoni tal-output permezz tal-kaxxa tal-marka. L-għażla tinżamm separatament għall-applikazzjoni u għall-iscreen saver. Jekk il-moniters kollha kienu magħżula, il-moniters ġodda jiddaħħlu wkoll fl-għażla.

## Applikazzjoni

Ħaddem FlyingSolids.exe. Is-settings jiġu ssejvjati kontinwament u taħdem istanza waħda biss. Il-kaxxa tal-moniter jew klikk doppja fuq ir-ringiela tattiva jew tiddiżattiva l-output tal-animazzjoni. Tista’ tissospendi u tkompli l-animazzjoni. PNG u MP4 jaqbdu l-ewwel moniter tal-animazzjoni attiv, mhux immaġni magħquda tal-moniters kollha. Il-moniter li qed jiġi rreġistrat ma jistax jiġi diżattivat; l-għeluq tal-applikazzjoni waqt reġistrazzjoni jeħtieġ konferma. L-imblukkar tal-iscreen saver japplika għas-sessjoni kollha u biss waqt animazzjoni viżibbli mhux sospiża fuq moniter bl-għażla attiva. L-applikazzjoni tinstalla jew tneħħi l-iscreen saver inkorporat.

Fis-settings tar-reġistrazzjoni agħżel Viewport jew TV. Viewport iżomm id-dimensjonijiet u r-rata ta’ aġġornament tal-moniter, sa 60 frejm kull sekonda. TV joffri 1920 × 1080, 1440 × 1080 jew 1280 × 720 f’16:9, b’50, 25, 59.94 (60000/1001) jew 29.97 (30000/1001) frejm kull sekonda. Il-vidjo TV huwa progressiv BT.709, b’medda limitata u sottokampjunar tal-kulur 4:2:0. Il-proporzjonijiet jinżammu u l-faxex ta’ mili huma suwed. OK isalva l-għażliet għar-reġistrazzjoni li jmiss; Ikkanċella jew Esc jarmi bidliet mhux ikkonfermati. It-twieqi tar-reġistrazzjoni, Għajnuna u Dwar ma jimblukkawx twieqi oħra u jistgħu jiġu minimizzati. Tab u Shift+Tab ibiddlu l-fokus, Enter jattiva l-buttuna fil-fokus u Esc jagħlaq it-tieqa awżiljarja attiva.

## Screen saver

Uża FlyingSolids.scr bħala screen saver ta’ Windows. Is-settings tiegħu huma separati minn dawk tal-applikazzjoni. Il-previżjoni fuq skrin sħiħ tippermetti bidliet waqt l-animazzjoni. OK isalva u Ikkanċella jew Esc jarmi l-bidliet. Oħroġ mill-iscreen saver bi kwalunkwe tast jew billi ċċaqlaq il-maws.

## Rekwiżiti tas-sistema

Windows 7–11 jappoġġja l-funzjonijiet kollha. Fuq Windows Vista SP2 għandhom jiġu installati l-aġġornamenti KB971512 u KB2117917; ir-reġistrazzjoni MP4 ma taħdimx fuq Vista. Huwa meħtieġ Direct3D 11 u, għall-MP4, Media Foundation u encoder H.264. L-interface u d-dokumentazzjoni huma disponibbli f’36 lingwa.

## Kumpilazzjoni u ppakkjar

Iftaħ DispSavers.slnx f’Visual Studio u kkumpila Release | x86 b’MSVC v145 u Windows SDK. Fil-paġna Signing tal-proġett issettja ċ-ċertifikat u s-server obbligatorju tal-marka tal-ħin RFC 3161; il-valuri personali jibqgħu fil-fajl injorat .vcxproj.user. L-SCR iffirmat u bil-marka tal-ħin jiddaħħal fl-EXE, imbagħad jiġi ffirmat l-EXE. PackageRelease.ps1 joħloq l-arkivju komuni `DispSavers-<version>-win32.zip` mingħajr ma jbiddel il-binarji f’Release.

## Solidi ġeometriċi

Kubu; Piramida kwadra regolari; Frustum ta’ piramida kwadra; Piramida kwadra maqtugħa oblikwament; Piramida maqtugħa perpendikulari mal-bażi; Priżma trijangolari regolari; Priżma pentagonali regolari; Priżma eżagonali regolari; Ottaedru regolari; Bipiramida pentagonali; Konu ċirkolari rett; Frustum ta’ konu; Konu maqtugħ oblikwament; Konu maqtugħ perpendikulari mal-bażi; Ċilindru ċirkolari rett; Ċilindru ċirkolari vojt; Ċilindru vojt bi truf torojdali; Parabolojde ta’ rotazzjoni magħluq; Sfera; Emisfera; Kalotta sferika; Kalotta sferika maġġuri; Segment sferiku bejn żewġ pjani; Ellissojde triassjali; Sferojde mtawwal; Sferojde ċċattjat; Ovojde; Kapsula (spherocylinder); Diska ttondjata (spheroplatelet); Toru.

## Liċenzja

[MIT](../license.txt) — Copyright © Petr Červinka — FortSoft 2026
