# SpaceFlight

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · **Svenska** · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

SpaceFlight erbjuder „Oändlig böljande yta“ och „Långdistansflygtur — formföränderlig yta“. Tilldela exakt en flygtur till varje bildskärm: välj dess rad och motsvarande alternativknapp. Den första animationen är vald på alla bildskärmar som standard. Textur är aktiverad som standard; avmarkera Textur för att visa de valda bildskärmarna som trådmodeller. När flera rader är markerade gäller valet alla dessa bildskärmar. Reglaget ställer in animationshastigheten från 0 till 1600 %. Vid standardstart aktiverar EXE endast den primära animationsskärmen, medan skärmsläckaren aktiverar alla bildskärmar. Varje bildskärm återges med sin egen uppdateringsfrekvens. Inställningarna sparas separat för programmet och skärmsläckaren. Fritt roterande kamera ger mjuk rotation av vyn i alla riktningar på de markerade skärmarna; alternativet är av som standard. Stopp och riktningsbyten bromsar kamerarotationen mjukt med slumpmässiga mellanrum, stoppar den kort och startar den igen åt motsatt håll. Alternativet är tillgängligt när fritt roterande kamera är aktiverat och är avstängt som standard; flygningen fortsätter.

## Program

`SpaceFlight.exe`

Välj flera bildskärmar i listan; dubbelklicka en rad för att slå på eller av animeringen, eller avmarkera alla. Varje bildskärm använder en oberoende scen. Skärmbild sparar PNG och inspelningsknappen startar eller stoppar MP4. Paus stannar animeringen. Programmet installerar eller avinstallerar även den inbyggda skärmsläckaren. Inställningarna sparas fortlöpande. Programmet kan bara köras i en instans åt gången. En ny start återställer det minimerade kontrollfönstret och för det längst fram. Använd Tab och Skift+Tab för att flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett kommando. Esc stänger det aktiva Hjälp- eller Om-fönstret; i kontrollfönstret avslutar det programmet. Blockera skärmsläckare under animering hindrar Windows-skärmsläckaren från att starta endast när animeringen faktiskt är synlig och inte är pausad.

Skärmbilder och inspelningar använder den första aktiva animeringsskärmen, inte en sammanslagen bild av alla skärmar. PNG använder Bilder, MP4 Videor; om dessa mappar saknas används Dokument. Knappen Inspelningsinställningar väljer Viewport eller TV. Viewport behåller animeringsskärmens storlek och uppdateringsfrekvens, upp till 60 bilder per sekund. TV erbjuder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9, med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) bilder per sekund. Bildens proportioner bevaras; TV använder progressiv BT.709-video med begränsat omfång och 4:2:0-sampling. Upplösning och bildfrekvens kan bara väljas i TV-läge. Fönstret Inspelningsinställningar kan minimeras och blockerar inte de andra programfönstren. OK sparar valen för nästa MP4-inspelning; Avbryt eller Esc ignorerar obekräftade ändringar. Den inspelade skärmen kan inte väljas bort under inspelningen; ändringar av andra skärmar stoppar inte inspelningen. Att avsluta programmet under en inspelning kräver bekräftelse eftersom det också avslutar inspelningen.

Windows 7 till Windows 11 stöder alla funktioner, inklusive PNG-skärmbilder och MP4-inspelning. För att köra programmet på Windows Vista SP2 måste uppdateringarna KB971512 och KB2117917 installeras. MP4-inspelning fungerar inte på Vista i den aktuella versionen.

## Skärmsläckare

`SpaceFlight.scr`

Aktivera förhandsvisning startar en helskärmsvisning på alla bildskärmar. Inställningarna förblir öppna och ändringarna visas direkt. OK sparar inställningarna och Avbryt förkastar ändringarna. Esc eller musrörelse avslutar helskärmsläget. Använd Tab och Skift+Tab för att flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett kommando. Esc i inställningarna motsvarar Avbryt; i Hjälp eller Om stänger det bara det fönstret.

Windows 7 till Windows 11 stöds. För att köra programmet på Windows Vista SP2 måste uppdateringarna KB971512 och KB2117917 installeras.

## Bygga

Öppna `DispSavers.slnx` i Visual Studio med MSVC v145 och Windows SDK. Välj `Release | x86` och bygg om lösningen för att skapa `Release\SpaceFlight.exe` och `Release\SpaceFlight.scr`. Ingen x64-konfiguration finns. Signering är aktiverad som standard för både Release och Debug. Ange namnet eller tumavtrycket för ett giltigt kodsigneringscertifikat med privat nyckel i den aktuella användarens `Personal (My)`-arkiv på sidan `Signing` i egenskaperna för projektet `SpaceFlight`. Inställningarna gäller EXE och SCR och sparas i `SpaceFlight.vcxproj.user`, som ignoreras av Git. SignTool hittas automatiskt i PATH eller Windows SDK. Om du använder SimplySign, logga in i SimplySign Desktop före bygget. Först signeras SCR och får en obligatorisk RFC 3161 SHA-256-tidsstämpel från den konfigurerade tidsstämpelservern; därefter bäddas det in i EXE, som också signeras och tidsstämplas. Ange URL-adressen till RFC 3161-tidsstämpelservern i fältet `Timestamp server`. Fel vid signering, tidsstämpling eller verifiering stoppar bygget; filer med giltiga tidsstämplade signaturer signeras inte igen.

[MIT License](license.txt) — Copyright © Petr Červinka — FortSoft 2026
