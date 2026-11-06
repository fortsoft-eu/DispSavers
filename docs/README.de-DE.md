# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · **Deutsch** · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Hardwarebeschleunigte Animation dreidimensionaler Volumenkörper.

Markieren Sie einen oder mehrere Monitore in der Liste. Kameramodus, Körperauswahl, Beleuchtung, Geschwindigkeiten, Größe und Anzahl der Exemplare gelten nur für die markierten Monitore. Jeder Monitor speichert seine eigenen Einstellungen. FlyingSolids zeigt beleuchtete dreidimensionale Volumenkörper. Die Regler bestimmen Objekt- und Kamerageschwindigkeit von 0–1600 %, ein bis zehn Exemplare je Körper und eine Größe von 50–200 %. Wählen Sie Raumbeobachtung oder Flug durch den Raum in gerader Linie und aktivieren Sie die gewünschten Körper. Die Kontrollkästchen Hauptlicht, Aufhelllicht, Umgebungslicht und Konturlicht unter den Reglern steuern die Beleuchtung der ausgewählten Monitore unabhängig voneinander. Umgebungslicht sorgt für eine Grundhelligkeit der Körperoberflächen, Konturlicht betont ihre Ränder. Die Beleuchtungseinstellungen werden für Anwendung und Bildschirmschoner getrennt gespeichert.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Hardwarebeschleunigter Flug durch einen veränderlichen Korridor und Trichter.

FlightCorridor: Flug zwischen vier veränderlichen Flächen; Flug durch einen veränderlichen Trichter. Weisen Sie jedem Monitor genau eine Animation zu. Textur wechselt zwischen texturierten Flächen und Drahtgittermodell. Die freie Kameradrehung verändert die Blickrichtung langsam in allen drei Dimensionen. Die Option „Pausen und Umkehr“ ergänzt zufälliges Abbremsen, Pausen und Wechsel der Drehrichtung; der Vorwärtsflug läuft weiter. Die Animationsgeschwindigkeit beträgt 0–1600 %. Jeder Monitor besitzt eine unabhängige zufällige Szene und wird mit seiner eigenen Bildwiederholrate angesteuert. Hauptlicht, Aufhelllicht, Umgebungslicht und Konturlicht lassen sich für die ausgewählten Monitore unabhängig schalten. Die Beleuchtung gilt nur für texturierte Flächen.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Hardwarebeschleunigter Flug über wellenförmige und veränderliche Flächen.

SpaceFlight: Unendliche wellenförmige Fläche; Fernflug — veränderliche Fläche; Flug durch gravitativ gekrümmten Raum. Weisen Sie jedem Monitor genau eine Animation zu. Textur wechselt zwischen texturierten Flächen und Drahtgittermodell. Die freie Kameradrehung verändert die Blickrichtung langsam in allen drei Dimensionen. Die Option „Pausen und Umkehr“ ergänzt zufälliges Abbremsen, Pausen und Wechsel der Drehrichtung; der Vorwärtsflug läuft weiter. Die Animationsgeschwindigkeit beträgt 0–1600 %. Jeder Monitor besitzt eine unabhängige zufällige Szene und wird mit seiner eigenen Bildwiederholrate angesteuert. Hauptlicht, Aufhelllicht, Umgebungslicht und Konturlicht lassen sich für die ausgewählten Monitore unabhängig schalten. Die Beleuchtung gilt nur für texturierte Flächen. Die beiden Animationen mit Flächen bieten Ebene, Wellen oder Trichter. Im Trichter bewegt sich die Kamera auf einer absteigenden Spirale nach innen. Der Flug durch gravitativ gekrümmten Raum zeigt ein dreidimensionales Drahtgitter. Textur, Flächenform und Beleuchtung gelten nur für die beiden Animationen mit Flächen.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Conways Spiel des Lebens auf einer gemeinsamen Fläche mehrerer Bildschirme.

### Regeln

Conways Spiel des Lebens verwendet B3/S23. Eine tote Zelle wird bei genau drei lebenden Nachbarn geboren; eine lebende überlebt bei zwei oder drei. Die acht Nachbarn schließen Diagonalen ein. Alle Zellen ändern sich gleichzeitig. Gegenüberliegende Ränder sind verbunden: links mit rechts, oben mit unten.

### Bildschirme und gemeinsame welt

Die Kontrollkästchen in EXE aktivieren Bildschirme; Einstellungen gelten für die gemeinsame Welt. Ein einziger aktiver Bildschirm enthält die gesamte Welt. Bei einer Teilauswahl entfallen vollständig leere Zeilen und Spalten: Nach Abschalten des mittleren schließen der linke und rechte Bildschirm aneinander an. Nicht entfernbare innere Lücken bleiben Teil der Simulation. Alle ausgewählten Bildschirme sowie SCR bewahren das umschließende Desktop-Rechteck einschließlich unsichtbarer Lücken. Jeder Bildschirm zeigt seinen Ausschnitt derselben Simulation.

### Anfangszustand und muster

Standard ist Zufallsrauschen mit 25 % lebenden Zellen. Die Anfangsdichte von 0–100 % gilt beim nächsten Neustart. Nur bekannte Muster verwendet 4.106 mitgelieferte Muster ohne Rauschen und deaktiviert die Dichte. Wählen Sie eine Mischung oder einen Namen; Maße sind in Zellen angegeben. Tippen sucht im Verzeichnis. Nur vollständig passende Muster erscheinen. Kleine geprüfte Muster werden in getrennten Kopien verteilt, große oder komplexe einmal mittig. Nach Verkleinern kann eine unpassende Auswahl durch eine Mischung ersetzt werden. Modus- oder Musterwechsel erzeugen eine neue Szene. Neustarts behalten die Auswahl; der Katalog funktioniert offline.

### Zellgrösse, raster und farben

Ohne Raster beträgt die Zellgröße 1–64 px. Raster anzeigen fügt innerhalb des bisherigen Abstands einen Rand von 1 px ein: Anzeige und Schieber sinken um eins, nutzbar sind 1–63. Ausschalten stellt den Wert wieder her. Der Schieber behält seinen Bereich und springt vom unzulässigen Ende zurück; das Kästchen bleibt bedienbar. Umschalten bewahrt die Szene, außer beim Einschalten bei 1 px: Dann entstehen 2 px Abstand und eine neue Szene. Änderungen an Zellgröße oder Bildschirmen beginnen ebenfalls neu. Sehr große Welten können einen höheren Mindestwert erfordern. Zell-, Hintergrund- und Rasterfarbe ändern sich unabhängig ohne Neustart. Die zufällige Farbe lebender Zellen wird bei jedem manuellen oder automatischen Szenenneustart neu gewählt. Die gespeicherte Farbe bleibt erhalten und wird beim Ausschalten dieser Option wiederhergestellt. Dasselbe Verhalten lässt sich getrennt für Hintergrund und Raster aktivieren; beide neuen Optionen sind standardmäßig aus.

### Tempo, pause und automatischer neustart

Das Tempo beträgt 0–240 Generationen/s unabhängig von der Bildwiederholrate; 0 hält die Entwicklung an. Pause und Fortsetzen bewahren die Welt. Neustart beginnt im gewählten Modus neu. Der optionale automatische Neustart erkennt statische und exakt wiederkehrende sichtbare Phasen einschließlich Oszillatoren. Verglichen werden Generationen statt Sekunden; unsichtbare Bereiche bleiben unberücksichtigt. Asynchrone Ergebnisse können den Neustart etwas verzögern. Vorgaben: 8 px Abstand, 20 Generationen/s, zufällige Farben lebender Zellen und automatischer Neustart ein. Das Raster ist standardmäßig ausgeschaltet. Die erreichte Geschwindigkeit hängt von Leistung und Zellzahl ab. Der automatische Neustart prüft die Bereiche aktivierter Bildschirme; Lücken entwickeln sich weiter, werden aber nicht verglichen.

### Werte zurücksetzen

Zurücksetzen stellt die angezeigte Zellgröße mit und ohne Raster auf 8 px (Abstand 9 bzw. 8 px), das Tempo auf 20 Generationen/s, die Dichte auf 25 % und die drei Standardfarben wieder her. Andere Einstellungen bleiben erhalten; ein nicht mehr passendes Muster wird durch die Mischung ersetzt. Nur ein geänderter Abstand oder eine geänderte Dichte im Rauschmodus erzeugt eine neue Szene.

### Eigenständige anwendung und MP4-aufnahme

EXE speichert Einstellungen laufend und nimmt den ersten aktiven Bildschirm als MP4 auf. Angeboten wird Videos, ersatzweise Dokumente. Viewport nutzt Bildschirmmaße und Bildwiederholrate bis 60 Bilder/s. TV bietet 1920 × 1080, 1440 × 1080 oder 1280 × 720 in 16:9 bei 50, 25, 59,94 (60000/1001) oder 29,97 (30000/1001) Bildern/s. Das Seitenverhältnis bleibt erhalten; TV nutzt progressives BT.709 mit begrenztem Wertebereich und 4:2:0. Das unabhängige Aufnahmefenster lässt sich minimieren. OK speichert für die nächste Aufnahme; Abbrechen oder Esc verwirft unbestätigte Änderungen. Der aufgezeichnete Bildschirm bleibt aktiviert; andere Ausgänge lassen sich ändern. Beenden während der Aufnahme erfordert Bestätigung. Bei fokussierter Animation schaltet Leertaste die Pause um, F9: Aufnahme starten; F10: Aufnahme beenden. Der Zeiger verschwindet nach 1 Sekunde Inaktivität und erscheint bei Bewegung. Tab/Shift+Tab wechselt Steuerelemente, Alt aktiviert unterstrichene Befehle. Esc schließt Hilfe/Info beziehungsweise die Anwendung im Hauptfenster. Windows-Bildschirmschoner… öffnet die Bildschirmschonereinstellungen des Systems.

### Schnappschuss und bildschirmschonerverwaltung in EXE

Schnappschuss speichert den aufgenommenen, sonst den ersten aktiven Bildschirm als BMP/GIF/JPEG/PNG/TIFF/WebP in seiner Auflösung ohne Szenenneustart. Vorgeschlagen wird Bilder, ersatzweise Dokumente. Das Sperren des Bildschirmschoners während der Animation verhindert dessen Start, solange die Animation sichtbar und nicht pausiert ist. Tempo null ist keine Pause. Die Installation aus EXE entpackt den mitgelieferten SCR und wählt ihn als Windows-Bildschirmschoner aus. Installation und Deinstallation können Administratorrechte erfordern; die Statusleiste zeigt den Vorgang bis zum Abschluss an. Bei blockierter Entfernung den laufenden Schoner, seine Einstellungen und die Windows-Vorschau schließen.

### Windows-bildschirmschoner

GameOfLife.scr nutzt alle Bildschirme mit getrennten Einstellungen von EXE. Vorschau aktivieren startet die Vollbildanimation bei geöffneten Einstellungen. Die kleine Windows-Vorschau verkleinert die ganze Welt. OK speichert; Abbrechen oder Esc verwirft Änderungen. Mausbewegung oder eine Taste beendet den Vollbildschoner. MP4-Aufnahme steht in EXE bereit.

### Fensterpositionen und zustand

Beim Schließen werden die Positionen von Haupt- und Infofenster getrennt gespeichert; bei der Hilfe auch Größe und normaler oder maximierter Zustand vor einer Minimierung. Dies ist unabhängig vom Bestätigen der Anwendungseinstellungen. Das Beenden der Anwendung schließt auch Hilfe und Info.

### Darstellung und musterlizenzen

Entwicklung und Vergleiche sichtbarer Zustände laufen über Direct3D-11-Shader auf der GPU; bei fehlgeschlagener Hardwareinitialisierung steht Softwaredarstellung bereit. Jeder Bildschirm nutzt den bewährten Framepacer bei seiner Bildwiederholrate. MP4 benötigt Media Foundation und einen H.264-Encoder. Muster stammen aus LifeWiki (GFDL 1.2 oder neuer) und Alan Hensels gemeinfreien Sammlungen. Der Programmcode steht unter MIT; Hinweise und Lizenzen des Katalogs gelten gesondert.

[Musterquellen, Lizenzen und Importdetails](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### MONITORE

Die Zeilenauswahl bestimmt, welche Monitore Sie bearbeiten; sie ist von den Kontrollkästchen zum Einschalten der Animationsausgabe getrennt. Strg+A wählt alle Monitore, Strg und Umschalt ändern die Auswahl. Alle Animationsoptionen und Regler gelten für die ausgewählten Monitore. Die Auswahl wird für EXE und SCR getrennt gespeichert. Waren alle Monitore ausgewählt, werden auch neu angeschlossene ausgewählt. Unterschiedliche Werte der ausgewählten Monitore werden durch unbestimmte Kontrollkästchen und gepunktete Optionsfelder, Reglergriffe sowie Schaltflächen „Alle aktivieren“ und „Alle deaktivieren“ angezeigt. Reglerbeschriftungen zeigen statt eines gemeinsamen Werts einen Gedankenstrich. Das Ändern einer Option oder Anklicken eines Reglers übernimmt diesen Wert für alle ausgewählten Monitore.

### BEDIENUNG

Die Animationsausgabe schalten Sie mit den Kontrollkästchen der Monitore oder per Doppelklick auf deren Zeilen ein oder aus. Jeder Monitor besitzt eine unabhängige Szene. Schnappschuss speichert BMP/GIF/JPEG/PNG/TIFF/WebP, die Aufnahmetaste startet oder beendet MP4. Pause hält die Animation an. Die Anwendung installiert oder deinstalliert außerdem den eingebetteten Bildschirmschoner. Einstellungen werden laufend gespeichert. Die Anwendung läuft nur in einer Instanz. Ein erneuter Start stellt das minimierte Steuerfenster wieder her und bringt es in den Vordergrund. Mit Tab und Umschalt+Tab wechseln Sie zwischen den Steuerelementen; mit Alt und dem unterstrichenen Buchstaben rufen Sie einen Befehl auf. Esc schließt das aktive Hilfe- oder Infofenster; im Steuerfenster beendet es die Anwendung. Pause und Bildschirmschonersperre gelten für die gesamte Anwendung, unabhängig von der Monitorauswahl. Bei eingeschalteter Sperre wird der Windows-Bildschirmschoner nur verhindert, solange auf mindestens einem Monitor eine sichtbare, nicht angehaltene Animation läuft.

### BILDSCHIRMFOTOS UND AUFNAHME

Schnappschüsse und Aufnahmen erfassen den ersten aktiven Animationsmonitor, nicht die gemeinsame Fläche aller Monitore. BMP/GIF/JPEG/PNG/TIFF/WebP verwendet Bilder, MP4 Videos; fehlen diese Ordner, wird Dokumente verwendet. Die Schaltfläche Aufnahmeeinstellungen wählt Viewport oder TV. Viewport erhält die Abmessungen und Bildwiederholfrequenz des Animationsmonitors bis höchstens 60 Bilder pro Sekunde. TV bietet 1920 × 1080, 1440 × 1080 oder 1280 × 720 im Format 16:9 mit 50, 25, 59.94 (60000/1001) oder 29.97 (30000/1001) Bildern pro Sekunde. Das Seitenverhältnis bleibt erhalten; TV verwendet progressives BT.709-Video mit begrenztem Wertebereich und 4:2:0-Abtastung. Auflösung und Bildfrequenz sind nur im TV-Modus wählbar. Das Fenster Aufnahmeeinstellungen lässt sich minimieren und blockiert die anderen Anwendungsfenster nicht. OK speichert die Auswahl für die nächste MP4-Aufnahme; Abbrechen oder Esc verwirft unbestätigte Änderungen. Die Animationsausgabe des aufgezeichneten Monitors kann während der Aufnahme nicht ausgeschaltet werden; Änderungen an anderen Monitoren beenden die Aufnahme nicht. Das Beenden der Anwendung während einer Aufnahme muss bestätigt werden, da es auch die Aufnahme beendet.

### VORSCHAU UND BEDIENUNG

Vorschau einschalten startet eine Vollbildvorschau auf allen Monitoren. Der Einstellungsdialog bleibt für Änderungen geöffnet. OK speichert, Abbrechen verwirft. Esc oder eine Mausbewegung beendet den Vollbildschoner. Mit Tab und Umschalt+Tab wechseln Sie zwischen den Steuerelementen; mit Alt und dem unterstrichenen Buchstaben rufen Sie einen Befehl auf. Esc im Einstellungsdialog entspricht Abbrechen; in der Hilfe oder im Infofenster schließt es nur dieses Fenster.

### Systemanforderungen

Windows 7 bis Windows 11 unterstützen alle Funktionen einschließlich BMP/GIF/JPEG/PNG/TIFF/WebP-Schnappschüssen und MP4-Aufnahmen. Zum Ausführen der Anwendung unter Windows Vista SP2 müssen die Updates KB971512 und KB2117917 installiert werden. MP4-Aufnahmen funktionieren unter Vista in der aktuellen Version nicht. Die Darstellung erfordert Direct3D 11, nicht nur eine ältere DirectX-Laufzeitumgebung. MP4-Aufnahmen benötigen verfügbare Media-Foundation-Komponenten und einen H.264-Encoder. Die eigenständige Anwendung kann über Wine auch unter Linux ausgeführt werden; die Integration als Bildschirmschoner ist nur unter Windows verfügbar.

## Erstellen und Paketieren

Öffnen Sie `DispSavers.slnx` in Visual Studio mit MSVC v145 und Windows SDK. Wählen Sie `Release | x86` und erstellen Sie die Projektmappe neu; dabei entstehen `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\GameOfLife.exe`, `Release\GameOfLife.scr`, `Release\SpaceFlight.exe` und `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr`. Eine x64-Konfiguration ist nicht vorhanden.

Verpacken Sie diese Build-Ergebnisse mit `PackageRelease.ps1` ohne Signaturparameter. Das Skript verwendet temporäre Kopien, verändert keine Dateien in `Release` und überprüft vorhandene gültige Signaturen lediglich. Es erstellt das einzige Archiv `DispSavers-<version>-win32.zip` mit `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `GameOfLife\GameOfLife.exe`, `GameOfLife\GameOfLife.scr`, `GameOfLife\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` und `SpaceFlight\license.txt`. Die vorherige ZIP-Datei wird zu Beginn entfernt; ein Überprüfungsfehler verhindert die Erstellung eines neuen Archivs.

## Lizenz

DispSavers steht unter der [MIT-Lizenz](../license.txt). Copyright © Petr Červinka — FortSoft 2026
