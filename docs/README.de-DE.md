# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · **Deutsch** · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlyingSolids ist eine native Win32/x86-Direct3D-Anwendung und ein Windows-Bildschirmschoner für beleuchtete, dreidimensionale Volumenkörper. Die Körper bewegen und drehen sich unabhängig und prallen voneinander ab, ohne einander zu durchdringen.

Die Zeilenauswahl bestimmt, welche Monitore Sie bearbeiten; sie ist von den Kontrollkästchen zum Einschalten der Animationsausgabe getrennt. Strg+A wählt alle Monitore, Strg und Umschalt ändern die Auswahl. Alle Animationsoptionen und Regler gelten für die ausgewählten Monitore. Die Auswahl wird für EXE und SCR getrennt gespeichert. Waren alle Monitore ausgewählt, werden auch neu angeschlossene ausgewählt. Unterschiedliche Werte der ausgewählten Monitore werden durch unbestimmte Kontrollkästchen und gepunktete Optionsfelder, Reglergriffe sowie Schaltflächen „Alle aktivieren“ und „Alle deaktivieren“ angezeigt. Reglerbeschriftungen zeigen statt eines gemeinsamen Werts einen Gedankenstrich. Das Ändern einer Option oder Anklicken eines Reglers übernimmt diesen Wert für alle ausgewählten Monitore.

## Funktionen

- **Raumbeobachtung** und geradliniger **Flug durch den Raum**. Markieren Sie einen oder mehrere Monitore in der Liste. Kameramodus, Körperauswahl, Beleuchtung, Geschwindigkeiten, Größe und Anzahl der Exemplare gelten nur für die markierten Monitore. Jeder Monitor speichert seine eigenen Einstellungen.
- Hauptlicht, Aufhelllicht, Umgebungslicht und Konturlicht unabhängig steuern
- Unabhängige Szene auf jedem Monitor
- Ein bis zehn Exemplare jedes aktivierten Körpers
- Objekt- und Kamerageschwindigkeit 0–1600 %, Objektgröße 50–200 %
- Glänzende Beleuchtung, individuelle Farben und Kollisionsbehandlung
- An die Bildwiederholfrequenz jedes Monitors angepasste Darstellung
- PNG-Schnappschüsse und MP4-Aufnahme in der eigenständigen Anwendung
- Getrennte Einstellungen für Anwendung und Bildschirmschoner
- 30 Körperarten und eine Oberfläche in 36 Sprachen

## Körper

Würfel; Regelmäßige quadratische Pyramide; Quadratischer Pyramidenstumpf; Schräg abgeschnittene Quadratpyramide; Quadratpyramide, basissenkrechter Schnitt; Regelmäßiges Dreiecksprisma; Regelmäßiges Fünfeckprisma; Regelmäßiges Sechseckprisma; Regelmäßiges Oktaeder; Fünfeck-Doppelpyramide; Gerader Kreiskegel; Kegelstumpf; Schräg abgeschnittener Kreiskegel; Kreiskegel, Schnitt senkrecht zur Basis; Gerader Kreiszylinder; Hohlzylinder; Hohlzylinder mit toroidalen Enden; Geschlossener Rotationsparaboloid; Kugel; Halbkugel; Kugelabschnitt; Großer Kugelabschnitt; Kugelschicht; Dreiachsiges Ellipsoid; Verlängertes Rotationsellipsoid; Abgeplattetes Rotationsellipsoid; Ovoid; Sphärozylinder; Abgerundete Scheibe (Spheroplatelet); Torus.

## Beleuchtung

Die Kontrollkästchen `Hauptlicht`, `Aufhelllicht`, `Umgebungslicht` und `Konturlicht` unter den Reglern steuern die Beleuchtung der ausgewählten Monitore unabhängig voneinander. Umgebungslicht sorgt für eine Grundhelligkeit der Körperoberflächen, Konturlicht betont ihre Ränder. Die Beleuchtungseinstellungen werden für Anwendung und Bildschirmschoner getrennt gespeichert.

## Anwendung und Bildschirmschoner

`FlyingSolids.exe` behält während der Animation ein einziges Steuerfenster bei. Die Animationsausgabe schalten Sie mit den Kontrollkästchen der Monitore oder per Doppelklick auf deren Zeilen ein oder aus. Die EXE kann den eingebetteten Bildschirmschoner installieren und deinstallieren. Die Anwendung läuft nur in einer Instanz. Ein erneuter Start stellt das minimierte Steuerfenster wieder her und bringt es in den Vordergrund. Mit Tab und Umschalt+Tab wechseln Sie zwischen den Steuerelementen; mit Alt und dem unterstrichenen Buchstaben rufen Sie einen Befehl auf. Esc schließt das aktive Hilfe- oder Infofenster; im Steuerfenster beendet es die Anwendung. Schnappschüsse und Aufnahmen erfassen den ersten aktiven Animationsmonitor, nicht die gemeinsame Fläche aller Monitore. PNG verwendet Bilder, MP4 Videos; fehlen diese Ordner, wird Dokumente verwendet. Die Schaltfläche Aufnahmeeinstellungen wählt Viewport oder TV. Viewport erhält die Abmessungen und Bildwiederholfrequenz des Animationsmonitors bis höchstens 60 Bilder pro Sekunde. TV bietet 1920 × 1080, 1440 × 1080 oder 1280 × 720 im Format 16:9 mit 50, 25, 59.94 (60000/1001) oder 29.97 (30000/1001) Bildern pro Sekunde. Das Seitenverhältnis bleibt erhalten; TV verwendet progressives BT.709-Video mit begrenztem Wertebereich und 4:2:0-Abtastung. Auflösung und Bildfrequenz sind nur im TV-Modus wählbar. Das Fenster Aufnahmeeinstellungen lässt sich minimieren und blockiert die anderen Anwendungsfenster nicht. OK speichert die Auswahl für die nächste MP4-Aufnahme; Abbrechen oder Esc verwirft unbestätigte Änderungen. Die Animationsausgabe des aufgezeichneten Monitors kann während der Aufnahme nicht ausgeschaltet werden; Änderungen an anderen Monitoren beenden die Aufnahme nicht. Das Beenden der Anwendung während einer Aufnahme muss bestätigt werden, da es auch die Aufnahme beendet. Pause und Bildschirmschonersperre gelten für die gesamte Anwendung, unabhängig von der Monitorauswahl. Bei eingeschalteter Sperre wird der Windows-Bildschirmschoner nur verhindert, solange auf mindestens einem Monitor eine sichtbare, nicht angehaltene Animation läuft. `FlyingSolids.scr` besitzt einen eigenen Einstellungsdialog ohne Aufnahmefunktion. Im Vollbild läuft auf jedem Monitor eine unabhängige Szene. Vorschau einschalten im Einstellungsdialog startet eine separate Vollbildvorschau auf allen Monitoren. Sie verwendet die aktuellen Einstellungen, erlaubt Änderungen während der Wiedergabe und lässt sich wieder ausschalten. Eine beliebige Taste, eine Mausbewegung oder ein Mausklick beendet den Vollbildschoner. Esc im Einstellungsdialog entspricht Abbrechen; in der Hilfe oder im Infofenster schließt es nur dieses Fenster.

## Einstellungen

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Systemanforderungen

Windows 7 bis Windows 11 unterstützen alle Funktionen einschließlich PNG-Schnappschüssen und MP4-Aufnahmen. Zum Ausführen der Anwendung unter Windows Vista SP2 müssen die Updates KB971512 und KB2117917 installiert werden. MP4-Aufnahmen funktionieren unter Vista in der aktuellen Version nicht. Die Darstellung erfordert Direct3D 11, nicht nur eine ältere DirectX-Laufzeitumgebung. MP4-Aufnahmen benötigen verfügbare Media-Foundation-Komponenten und einen H.264-Encoder. Die eigenständige Anwendung kann über Wine auch unter Linux ausgeführt werden; die Integration als Bildschirmschoner ist nur unter Windows verfügbar.

## Erstellen und Paketieren

Öffnen Sie `DispSavers.slnx` in Visual Studio mit MSVC v145 und Windows SDK. Wählen Sie `Release | x86` und erstellen Sie die Projektmappe neu; dabei entstehen `Release\FlyingSolids.exe` und `Release\FlyingSolids.scr`. Eine x64-Konfiguration ist nicht vorhanden. Geben Sie in den Eigenschaften des Projekts `FlyingSolids` auf der Seite `Signing` den Namen oder Fingerabdruck eines gültigen Codesignaturzertifikats mit privatem Schlüssel im Zertifikatspeicher `Personal (My)` des aktuellen Benutzers ein. Die Einstellungen gelten für EXE und SCR und werden in der von Git ignorierten Datei `FlyingSolids.vcxproj.user` gespeichert. SignTool wird automatisch über PATH oder im Windows SDK gefunden. Melden Sie sich bei Verwendung von SimplySign vor dem Erstellen in SimplySign Desktop an. Zuerst wird SCR signiert und mit einem obligatorischen RFC-3161-SHA-256-Zeitstempel vom konfigurierten Zeitstempelserver versehen. Danach wird es in EXE eingebettet, die ebenfalls signiert und mit einem Zeitstempel versehen wird. Geben Sie im Feld `Timestamp server` die URL eines RFC-3161-Zeitstempelservers ein. Fehler beim Signieren, Zeitstempeln oder Überprüfen brechen den Build ab; bereits gültig signierte Dateien mit Zeitstempel werden nicht erneut signiert.

Verpacken Sie diese Build-Ergebnisse mit `PackageRelease.ps1` ohne Signaturparameter. Das Skript verwendet temporäre Kopien, verändert keine Dateien in `Release` und überprüft vorhandene gültige Signaturen lediglich. Es erstellt das einzige Archiv `DispSavers-<version>-win32.zip` mit `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` und `SpaceFlight\license.txt`. Die vorherige ZIP-Datei wird zu Beginn entfernt; ein Überprüfungsfehler verhindert die Erstellung eines neuen Archivs.

## Lizenz

FlyingSolids steht unter der [MIT-Lizenz](../license.txt). Copyright © Petr Červinka — FortSoft 2026

## FlightCorridor

FlightCorridor bietet Flug zwischen vier veränderlichen Flächen und Flug durch einen veränderlichen Trichter. Weisen Sie jedem Monitor genau einen Flug zu: Markieren Sie seine Zeile und wählen Sie den entsprechenden Optionsschalter.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](../FlightCorridor/README.de-DE.md)

## SpaceFlight

SpaceFlight: Unendliche wellenförmige Fläche; Fernflug — veränderliche Fläche; Flug durch gravitativ gekrümmten Raum. Weisen Sie jedem Monitor genau einen Flug zu: Markieren Sie seine Zeile und wählen Sie den entsprechenden Optionsschalter.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](../SpaceFlight/README.de-DE.md)
