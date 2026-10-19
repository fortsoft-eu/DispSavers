# SpaceFlight

[Čeština](README.cs-CZ.md) · [English (US)](README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · **Svenska** · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

SpaceFlight: Oändlig böljande yta; Långdistansflygtur — formföränderlig yta. Tilldela varje skärm exakt en animering. Textur växlar mellan texturerade ytor och trådmodell. Fritt roterande kamera ändrar långsamt blickriktningen i alla tre dimensioner. Stopp och riktningsbyten lägger till slumpmässiga inbromsningar, pauser och byten av rotationsriktning; flygningen framåt fortsätter. Hastigheten är 0–1600 %. Varje skärm har en oberoende slumpmässig scen som återges med dess egen uppdateringsfrekvens.

Markeringen av rader avgör vilka skärmar du redigerar och är skild från kryssrutorna som aktiverar animationsutgångarna. Ctrl+A markerar alla skärmar; Ctrl och Skift ändrar markeringen. Alla animationsalternativ och reglage gäller de markerade skärmarna. Markeringen sparas separat för EXE och SCR. Om alla skärmar var markerade inkluderas även nya skärmar.

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

Öppna `DispSavers.slnx` i Visual Studio med MSVC v145 och Windows SDK. Välj `Release | x86` och bygg om lösningen för att skapa `Release\SpaceFlight.exe` och `Release\SpaceFlight.scr`. Ingen x64-konfiguration finns. Ange namnet eller tumavtrycket för ett giltigt kodsigneringscertifikat med privat nyckel i den aktuella användarens `Personal (My)`-arkiv på sidan `Signing` i egenskaperna för projektet `SpaceFlight`. Inställningarna gäller EXE och SCR och sparas i `SpaceFlight.vcxproj.user`, som ignoreras av Git. SignTool hittas automatiskt i PATH eller Windows SDK. Om du använder SimplySign, logga in i SimplySign Desktop före bygget. Först signeras SCR och får en obligatorisk RFC 3161 SHA-256-tidsstämpel från den konfigurerade tidsstämpelservern; därefter bäddas det in i EXE, som också signeras och tidsstämplas. Ange URL-adressen till RFC 3161-tidsstämpelservern i fältet `Timestamp server`. Fel vid signering, tidsstämpling eller verifiering stoppar bygget; filer med giltiga tidsstämplade signaturer signeras inte igen.

[MIT License](license.txt) — Copyright © Petr Červinka — FortSoft 2026
