# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · **Italiano** · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

FlyingSolids è un’applicazione nativa Win32/x86 basata su Direct3D e un salvaschermo Windows che visualizza solidi geometrici tridimensionali illuminati. I solidi si muovono e ruotano indipendentemente e rimbalzano senza compenetrarsi.

La selezione delle righe determina quali schermi si stanno configurando ed è distinta dalle caselle che attivano le uscite di animazione. Ctrl+A seleziona tutti gli schermi; Ctrl e Maiusc modificano la selezione. Tutte le opzioni e i cursori dell’animazione riguardano gli schermi selezionati. La selezione viene memorizzata separatamente per EXE e SCR. Se erano selezionati tutti gli schermi, vengono inclusi anche quelli nuovi.

## Funzioni

- **Osservazione dello spazio** e **Volo nello spazio** rettilineo. Selezionare uno o più monitor nell’elenco. La modalità della telecamera, gli oggetti, le luci, le velocità, le dimensioni e il numero di copie si applicano solo ai monitor selezionati. Ogni monitor conserva le proprie impostazioni.
- Controllo indipendente delle luci principale, di riempimento, ambientale e dei contorni
- Scena indipendente su ogni monitor selezionato
- Da una a dieci copie di ciascun solido attivo
- Velocità di oggetti e fotocamera 0–1600 %, dimensione 50–200 %
- Superfici lucide, illuminazione, colori distinti e collisioni
- Rendering adattato alla frequenza di aggiornamento di ogni monitor
- Istantanee PNG e registrazione MP4 nell’applicazione autonoma
- Impostazioni separate per applicazione e salvaschermo
- 30 tipi di solidi e interfaccia in 36 lingue

## Solidi

Cubo; Piramide regolare a base quadrata; Tronco di piramide quadrata; Piramide quadrata troncata in obliquo; Piramide quadrata, taglio normale alla base; Prisma retto a base triangolare regolare; Prisma retto a base pentagonale regolare; Prisma retto a base esagonale regolare; Ottaedro regolare; Bipiramide pentagonale; Cono circolare retto; Tronco di cono; Cono troncato da un piano obliquo; Cono tagliato perpendicolarmente alla base; Cilindro circolare retto; Cilindro cavo; Cilindro cavo con estremità toroidali; Paraboloide di rotazione chiuso da un piano; Sfera; Emisfero; Segmento sferico a una base; Segmento sferico maggiore; Segmento sferico a due basi; Ellissoide triassiale; Sferoide prolato; Sferoide oblato; Ovoide; Sferocilindro; Disco arrotondato (spheroplatelet); Toro.

## Illuminazione

Le caselle `Luce principale`, `Luce di riempimento`, `Luce ambientale` e `Illuminazione dei contorni` sotto i cursori controllano indipendentemente l’illuminazione dell’intera scena. La luce ambientale fornisce un’illuminazione di base alle superfici, mentre quella dei contorni ne evidenzia i bordi. Le impostazioni vengono salvate separatamente per l’applicazione e il salvaschermo.

## Applicazione e salvaschermo

`FlyingSolids.exe` mantiene un’unica finestra di controllo mentre l’animazione è attiva. Si possono selezionare più monitor, commutarne uno con doppio clic o scollegarli tutti. L’EXE può installare o disinstallare il salvaschermo incorporato. L’applicazione può essere eseguita in una sola istanza. Un nuovo avvio ripristina la finestra di controllo ridotta a icona e la porta in primo piano. Usare Tab e Maiusc+Tab per passare tra i controlli; Alt e la lettera sottolineata attivano un comando. Esc chiude la finestra attiva di Guida o Informazioni; nella finestra di controllo, termina l’applicazione. Istantanee e registrazioni usano il primo monitor di animazione attivo, non un’immagine combinata di tutti i monitor. PNG usa Immagini, MP4 Video; se tali cartelle non esistono, viene usata Documenti. Il pulsante Impostazioni video permette di scegliere Viewport o TV. Viewport mantiene le dimensioni e la frequenza di aggiornamento del monitor di animazione, fino a 60 fotogrammi al secondo. TV offre 1920 × 1080, 1440 × 1080 o 1280 × 720 in formato 16:9, a 50, 25, 59.94 (60000/1001) o 29.97 (30000/1001) fotogrammi al secondo. Le proporzioni sono mantenute; TV usa video progressivo BT.709 con intervallo limitato e campionamento 4:2:0. Risoluzione e frequenza sono disponibili solo in modalità TV. La finestra Impostazioni video può essere ridotta a icona e non blocca le altre finestre dell’applicazione. OK salva le opzioni per la prossima registrazione MP4; Annulla o Esc scarta le modifiche non confermate. Il monitor registrato non può essere deselezionato durante la registrazione; le modifiche agli altri monitor non la interrompono. Chiudere l’applicazione durante una registrazione richiede conferma, perché interrompe anche la registrazione. Blocca salvaschermo durante l’animazione impedisce l’avvio del salvaschermo di Windows solo quando l’animazione è realmente visibile e non è in pausa. `FlyingSolids.scr` ha una propria finestra di impostazioni senza registrazione. A schermo intero crea una scena indipendente per ogni monitor. Attiva anteprima nelle impostazioni avvia un’anteprima separata a schermo intero su tutti i monitor. Usa le impostazioni attuali, permette modifiche in tempo reale e può essere arrestata. Un tasto qualsiasi, un movimento del mouse o un clic chiude il salvaschermo a schermo intero. Esc nelle impostazioni equivale ad Annulla; nella Guida o nelle Informazioni, chiude solo quella finestra.

## Archiviazione delle impostazioni

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Requisiti di sistema

I sistemi da Windows 7 a Windows 11 supportano tutte le funzioni, comprese le istantanee PNG e la registrazione MP4. Per eseguire l’applicazione su Windows Vista SP2, è necessario installare gli aggiornamenti KB971512 e KB2117917. La registrazione MP4 non funziona in Vista nella versione attuale. La visualizzazione richiede Direct3D 11, non soltanto un vecchio runtime DirectX. La registrazione MP4 richiede componenti Media Foundation e un codificatore H.264 disponibili.

## Compilazione

Aprire `DispSavers.slnx` in Visual Studio con MSVC v145 e Windows SDK. Selezionare `Release | x86` e ricompilare la soluzione per creare `Release\FlyingSolids.exe` e `Release\FlyingSolids.scr`. Non è prevista una configurazione x64. Nelle proprietà del progetto `FlyingSolids`, pagina `Signing`, specificare il nome o l’impronta di un certificato valido per la firma del codice con chiave privata nell’archivio `Personal (My)` dell’utente corrente. Le impostazioni valgono per EXE e SCR e vengono salvate in `FlyingSolids.vcxproj.user`, ignorato da Git. SignTool viene cercato automaticamente in PATH o in Windows SDK. Se si usa SimplySign, accedere a SimplySign Desktop prima della compilazione. Viene prima firmato il SCR, con una marca temporale RFC 3161 SHA-256 obbligatoria dal server di marcatura temporale configurato, quindi viene incorporato nell’EXE, anch’esso firmato e marcato temporalmente. Specificare l’URL del server di marcatura temporale RFC 3161 nel campo `Timestamp server`. Errori di firma, marcatura temporale o verifica interrompono la compilazione; i file con una firma valida e una marca temporale non vengono firmati di nuovo.

Eseguire `PackageRelease.ps1` senza parametri di firma per creare il pacchetto dei file compilati. Lo script usa copie temporanee, non modifica i file in `Release` e verifica soltanto le firme valide esistenti. Crea l’unico archivio `DispSavers-<version>-win32.zip`, contenente `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` e `SpaceFlight\license.txt`. Il vecchio ZIP viene eliminato all’inizio dell’esecuzione; un errore di verifica impedisce la creazione di un nuovo archivio.

## Licenza

FlyingSolids è disponibile con [licenza MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026

## FlightCorridor

FlightCorridor offre Volo tra quattro superfici deformabili e Volo attraverso un imbuto deformabile. Assegnare un solo volo a ogni monitor: selezionare la sua riga e il pulsante di opzione corrispondente.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](../FlightCorridor/README.it-IT.md)

## SpaceFlight

SpaceFlight offre „Superficie ondulante infinita“ e „Volo a lunga distanza — superficie deformabile“. Assegnare un solo volo a ogni monitor: selezionare la sua riga e il pulsante di opzione corrispondente.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](../SpaceFlight/README.it-IT.md)
