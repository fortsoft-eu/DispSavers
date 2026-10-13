# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · **Svenska** · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids är ett inbyggt Win32/x86 Direct3D-program och en skärmsläckare för Windows som visar belysta, solida tredimensionella geometriska kroppar. Kropparna rör sig och roterar oberoende och kolliderar utan att tränga igenom varandra.

## Funktioner

- **Rymdobservation** och rak **Flygning genom rymden**
- Oberoende styrning av huvudljus, upplättningsljus, omgivningsljus och konturljus
- Oberoende scen på varje vald bildskärm
- En till tio kopior av varje aktiverad kropp
- Objekt- och kamerahastighet 0–1600 %, storlek 50–200 %
- Glansig belysning, egna färger och kollisionshantering
- Återgivning anpassad till varje bildskärms uppdateringsfrekvens
- PNG-skärmbilder och MP4-inspelning i det fristående programmet
- Separata inställningar för program och skärmsläckare
- 30 kroppstyper och gränssnitt på 17 språk

## Geometriska kroppar

Utbudet omfattar polyedrar, regelbundna prismor, pyramider och plansnitt, koner och cylindrar och deras plansnitt, en rotationsparaboloid sluten av ett plan, klotbaserade kroppar, ellipsoider, ovoid, sfärocylinder och torus. Gränssnittet använder etablerad svensk geometrisk terminologi.

## Belysning

Kryssrutorna `Huvudljus`, `Upplättningsljus`, `Omgivningsljus` och `Konturljus` under reglagen styr belysningen i hela scenen oberoende av varandra. Omgivningsljus ger grundbelysning på ytorna och konturljus framhäver kanterna. Som standard är huvudljus, omgivningsljus och konturljus på och upplättningsljus av. Inställningarna sparas separat för programmet och skärmsläckaren.

## Program och skärmsläckare

`FlyingSolids.exe` behåller ett styrfönster medan animeringen körs. Flera bildskärmar kan väljas, en rad växlas med dubbelklick och alla kan kopplas bort. EXE-filen kan installera och avinstallera den inbyggda skärmsläckaren. Programmet kan bara köras i en instans åt gången. En ny start återställer det minimerade kontrollfönstret och för det längst fram. Använd Tab och Skift+Tab för att flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett kommando. Esc stänger det aktiva Hjälp- eller Om-fönstret; i kontrollfönstret avslutar det programmet. Skärmbilder och inspelningar använder den första aktiva animeringsskärmen, inte en sammanslagen bild av alla skärmar. PNG använder Bilder, MP4 Videor; om dessa mappar saknas används Dokument. Knappen Inspelningsinställningar väljer Viewport eller TV. Viewport behåller animeringsskärmens storlek och uppdateringsfrekvens, upp till 60 bilder per sekund. TV erbjuder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9, med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) bilder per sekund. Bildens proportioner bevaras; TV använder progressiv BT.709-video med begränsat omfång och 4:2:0-sampling. Upplösning och bildfrekvens kan bara väljas i TV-läge. Fönstret Inspelningsinställningar kan minimeras och blockerar inte de andra programfönstren. OK sparar valen för nästa MP4-inspelning; Avbryt eller Esc ignorerar obekräftade ändringar. Den inspelade skärmen kan inte väljas bort under inspelningen; ändringar av andra skärmar stoppar inte inspelningen. Att avsluta programmet under en inspelning kräver bekräftelse eftersom det också avslutar inspelningen. Blockera skärmsläckare under animering hindrar Windows-skärmsläckaren från att starta endast när animeringen faktiskt är synlig och inte är pausad. `FlyingSolids.scr` har egna inställningar utan inspelning. Helskärmsläget kör en oberoende scen på varje bildskärm. Aktivera förhandsvisning i inställningarna startar en separat helskärmsvisning på alla skärmar. Den använder de aktuella inställningarna, tillåter ändringar under visningen och kan stoppas igen. Valfri tangent, en musrörelse eller ett musklick avslutar skärmsläckaren i helskärm. Esc i inställningarna motsvarar Avbryt; i Hjälp eller Om stänger det bara det fönstret.

## Inställningar

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Systemkrav

Windows 7 till Windows 11 stöder alla funktioner, inklusive PNG-skärmbilder och MP4-inspelning. För att köra programmet på Windows Vista SP2 måste uppdateringarna KB971512 och KB2117917 installeras. MP4-inspelning fungerar inte på Vista i den aktuella versionen. Visningen kräver Direct3D 11, inte bara en äldre DirectX-körningsmiljö. MP4-inspelning kräver tillgängliga Media Foundation-komponenter och en H.264-kodare.

## Bygge

Öppna `DispSavers.slnx` i Visual Studio med MSVC v145 och Windows SDK. Välj `Release | x86` och bygg om lösningen för att skapa `Release\FlyingSolids.exe` och `Release\FlyingSolids.scr`. Ingen x64-konfiguration finns. Signering är aktiverad som standard för både Release och Debug. Ange namnet eller tumavtrycket för ett giltigt kodsigneringscertifikat med privat nyckel i den aktuella användarens `Personal (My)`-arkiv på sidan `Signing` i egenskaperna för projektet `FlyingSolids`. Inställningarna gäller EXE och SCR och sparas i `FlyingSolids.vcxproj.user`, som ignoreras av Git. SignTool hittas automatiskt i PATH eller Windows SDK. Om du använder SimplySign, logga in i SimplySign Desktop före bygget. Först signeras SCR och får en obligatorisk RFC 3161 SHA-256-tidsstämpel från den konfigurerade tidsstämpelservern; därefter bäddas det in i EXE, som också signeras och tidsstämplas. Ange URL-adressen till RFC 3161-tidsstämpelservern i fältet `Timestamp server`. Fel vid signering, tidsstämpling eller verifiering stoppar bygget; filer med giltiga tidsstämplade signaturer signeras inte igen.

Paketera dessa byggresultat genom att köra `PackageRelease.ps1` utan signeringsparametrar. Skriptet använder tillfälliga kopior, ändrar inte filer i `Release` och verifierar endast befintliga giltiga signaturer. Det skapar ett enda arkiv, `DispSavers-<version>-win32.zip`, med `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr` och `FlyingSolids\license.txt`. Den tidigare ZIP-filen tas bort vid körningens början; ett verifieringsfel förhindrar att ett nytt arkiv skapas.

## Licens

FlyingSolids tillhandahålls under [MIT-licensen](../license.txt). Copyright © Petr Červinka — FortSoft 2026
