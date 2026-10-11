# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · **Deutsch** · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids ist eine native Win32/x86-Direct3D-Anwendung und ein Windows-Bildschirmschoner für beleuchtete, räumliche Vollkörper. Die Körper bewegen und drehen sich unabhängig und prallen voneinander ab, ohne einander zu durchdringen. Anfangszustände und neu eingesetzte Flugpositionen stammen aus dem kryptografischen Zufallszahlengenerator von Windows; eine Pufferung hält die CPU-Belastung gering.

## Funktionen

- **Raumbeobachtung** und geradliniger **Flug durch den Raum**
- Hauptlicht und Aufhelllicht unabhängig ein- und ausschalten
- Unabhängige Szene auf jedem gewählten Monitor
- Ein bis zehn Exemplare jedes aktivierten Körpers
- Objekt- und Kamerageschwindigkeit 0–1600 %, Objektgröße 50–200 %
- Glänzende Beleuchtung, individuelle Farben und Kollisionsbehandlung
- An die Bildwiederholfrequenz jedes Monitors angepasste Darstellung
- PNG-Schnappschüsse und MP4-Aufnahme in der eigenständigen Anwendung
- Getrennte Einstellungen für Anwendung und Bildschirmschoner
- 27 Körperarten und eine Oberfläche in 17 Sprachen

## Körper

Der Katalog umfasst Polyeder, regelmäßige Prismen, Pyramiden und ebene Schnitte, Kegel und Zylinder und deren ebene Schnitte, einen durch eine Ebene geschlossenen Rotationsparaboloid, von der Kugel abgeleitete Körper, Ellipsoide, Ovoid, Sphärozylinder und Torus. Das Programm verwendet die fachüblichen deutschen geometrischen Bezeichnungen.

## Beleuchtung

Die Kontrollkästchen `Hauptlicht` und `Aufhelllicht` unter den rechten Reglern schalten die beiden Lichtquellen für die gesamte Szene unabhängig ein oder aus. Standardmäßig ist `Hauptlicht` eingeschaltet und `Aufhelllicht` ausgeschaltet. Die Lichteinstellungen werden für Anwendung und Bildschirmschoner getrennt gespeichert.

## Anwendung und Bildschirmschoner

`FlyingSolids.exe` behält während der Animation ein einziges Steuerfenster bei. Mehrere Monitore können gewählt, per Doppelklick umgeschaltet oder vollständig abgewählt werden. PNG-Dateien werden standardmäßig unter **Bilder**, MP4-Dateien unter **Videos** gespeichert; ersatzweise wird **Dokumente** verwendet. Die EXE kann den eingebetteten Bildschirmschoner installieren und deinstallieren.

Die Anwendung läuft nur in einer Instanz. Ein erneuter Start stellt das minimierte Steuerfenster wieder her, zeichnet es neu und bringt es in den Vordergrund.

Mit Tab und Umschalt+Tab wechseln Sie zwischen den Steuerelementen; mit Alt und dem unterstrichenen Buchstaben rufen Sie einen Befehl auf. Esc schließt das aktive Hilfe- oder Infofenster; im Steuerfenster beendet es die Anwendung.

Schnappschüsse und Aufnahmen erfassen den ersten aktiven Animationsmonitor, nicht die gemeinsame Fläche aller Monitore. PNG verwendet Bilder, MP4 Videos; fehlen diese Ordner, wird Dokumente verwendet. MP4 folgt der Bildwiederholfrequenz des Monitors, höchstens jedoch 60 Bildern pro Sekunde.

`FlyingSolids.scr` besitzt einen eigenen Einstellungsdialog ohne Aufnahmefunktion. Im Vollbild läuft auf jedem Monitor eine unabhängige Szene.

Vorschau einschalten im Einstellungsdialog startet eine separate Vollbildvorschau auf allen Monitoren. Sie verwendet die aktuellen Einstellungen, erlaubt Änderungen während der Wiedergabe und lässt sich wieder ausschalten. Eine beliebige Taste, eine Mausbewegung oder ein Mausklick beendet den Vollbildschoner.

Esc im Einstellungsdialog entspricht Abbrechen; in der Hilfe oder im Infofenster schließt es nur dieses Fenster.

## Einstellungen

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Systemanforderungen

Windows 7 bis Windows 11 unterstützen alle Funktionen einschließlich PNG-Schnappschüssen und MP4-Aufnahmen.

Windows Vista SP2: KB971512, KB2117917. MP4-Aufnahmen funktionieren unter Vista in der aktuellen Version nicht.

Die Darstellung erfordert Direct3D 11, nicht nur eine ältere DirectX-Laufzeitumgebung. MP4-Aufnahmen benötigen verfügbare Media-Foundation-Komponenten und einen H.264-Encoder.

## Erstellen und Paketieren

`DispSavers.slnx` in Visual Studio öffnen, `Release | x86` wählen und die Projektmappe mit MSVC v145 und Windows SDK neu erstellen. Dabei entstehen EXE und SCR. `PackageRelease.ps1` erstellt das gemeinsame Archiv `DispSavers-<version>-win32.zip`, in dem die Dateien und `license.txt` im Unterordner `FlyingSolids` liegen. Eine x64-Konfiguration ist nicht vorhanden.

## Lizenz

FlyingSolids steht unter der [MIT-Lizenz](../license.txt).

Copyright © Petr Červinka — FortSoft 2026
