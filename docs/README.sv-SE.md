# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · **Svenska** · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids är ett inbyggt Win32/x86 Direct3D-program och en skärmsläckare för Windows som visar belysta, solida tredimensionella geometriska kroppar. Kropparna rör sig och roterar oberoende och kolliderar utan att tränga igenom varandra. Startvillkor och nya flygpositioner kommer från Windows kryptografiska generator och buffras för låg processorbelastning.

## Funktioner

- **Rymdobservation** och rak **Flygning genom rymden**
- Huvudljus och upplättningsljus kan slås på och av oberoende av varandra
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

- En prolat sfäroid har en längre halvaxel och två lika långa kortare halvaxlar.
- En avrundad skiva (spheroplatelet) har två plana cirkelytor och en jämnt avrundad kant; diametern är något större än hos klotsegmentet med två baser och tjockleken är hälften så stor.
- En ihålig cylinder med toroidala ändar har yttre och inre cylinderytor förenade med halva torusar, som bildar exakta halvcirklar i ett axiellt snitt.

## Belysning

Kryssrutorna `Huvudljus` och `Upplättningsljus` under reglagen till höger slår på eller av de två ljusen oberoende av varandra för hela scenen. Som standard är `Huvudljus` på och `Upplättningsljus` av. Ljusinställningarna sparas separat för programmet och skärmsläckaren.

## Program och skärmsläckare

`FlyingSolids.exe` behåller ett styrfönster medan animeringen körs. Flera bildskärmar kan väljas, en rad växlas med dubbelklick och alla kan kopplas bort. PNG sparas normalt i **Bilder**, MP4 i **Videor**, med **Dokument** som reserv. EXE-filen kan installera och avinstallera den inbyggda skärmsläckaren.

Programmet kan bara köras i en instans åt gången. En ny start återställer det minimerade kontrollfönstret, ritar om det och för det längst fram.

Använd Tab och Skift+Tab för att flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett kommando. Esc stänger det aktiva Hjälp- eller Om-fönstret; i kontrollfönstret avslutar det programmet.

Skärmbilder och inspelningar använder den första aktiva animeringsskärmen, inte en sammanslagen bild av alla skärmar. PNG använder Bilder, MP4 Videor; om dessa mappar saknas används Dokument. MP4-inspelning följer skärmens uppdateringsfrekvens, upp till 60 bilder per sekund.

`FlyingSolids.scr` har egna inställningar utan inspelning. Helskärmsläget kör en oberoende scen på varje bildskärm.

Aktivera förhandsvisning i inställningarna startar en separat helskärmsvisning på alla skärmar. Den använder de aktuella inställningarna, tillåter ändringar under visningen och kan stoppas igen. Valfri tangent, en musrörelse eller ett musklick avslutar skärmsläckaren i helskärm.

Esc i inställningarna motsvarar Avbryt; i Hjälp eller Om stänger det bara det fönstret.

## Inställningar

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Systemkrav

Windows 7 till Windows 11 stöder alla funktioner, inklusive PNG-skärmbilder och MP4-inspelning.

För att köra programmet på Windows Vista SP2 måste uppdateringarna KB971512 och KB2117917 installeras. MP4-inspelning fungerar inte på Vista i den aktuella versionen.

Visningen kräver Direct3D 11, inte bara en äldre DirectX-körningsmiljö. MP4-inspelning kräver tillgängliga Media Foundation-komponenter och en H.264-kodare.

## Bygge

Öppna `DispSavers.slnx`, välj `Release | x86` och bygg om lösningen med MSVC v145 och Windows SDK. EXE och SCR skapas tillsammans. `PackageRelease.ps1` skapar lösningens enda paket `DispSavers-<version>-win32.zip`, där filerna och `license.txt` ligger i underkatalogen `FlyingSolids`. Ingen x64-konfiguration finns.

## Licens

FlyingSolids tillhandahålls under [MIT-licensen](../license.txt).

Copyright © Petr Červinka — FortSoft 2026
