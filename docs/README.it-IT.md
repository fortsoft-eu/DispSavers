# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · **Italiano** · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids è un’applicazione nativa Win32/x86 basata su Direct3D e un salvaschermo Windows che visualizza solidi geometrici tridimensionali illuminati. I solidi si muovono e ruotano indipendentemente e rimbalzano senza compenetrarsi. Le condizioni iniziali e le nuove posizioni durante il volo provengono dal generatore crittografico di Windows e sono memorizzate a blocchi per contenere l’uso della CPU.

## Funzioni

- **Osservazione dello spazio** e **Volo nello spazio** rettilineo
- Attivazione indipendente della luce principale e della luce di riempimento
- Scena indipendente su ogni monitor selezionato
- Da una a dieci copie di ciascun solido attivo
- Velocità di oggetti e fotocamera 0–1600 %, dimensione 50–200 %
- Superfici lucide, illuminazione, colori distinti e collisioni
- Rendering adattato alla frequenza di aggiornamento di ogni monitor
- Istantanee PNG e registrazione MP4 nell’applicazione autonoma
- Impostazioni separate per applicazione e salvaschermo
- 30 tipi di solidi e interfaccia in 17 lingue

## Solidi

Il catalogo comprende poliedri, prismi regolari, piramidi e relativi tagli piani, coni e cilindri e relativi tagli piani, un paraboloide di rotazione chiuso da un piano, solidi derivati dalla sfera, ellissoidi, un ovoide, uno sferocilindro e un toro. L’interfaccia usa la terminologia geometrica italiana consolidata.

- Uno sferoide prolato ha un semiasse più lungo e due semiassi più corti di uguale lunghezza.
- Un disco arrotondato (spheroplatelet) ha due facce circolari piane e un bordo arrotondato continuo; il suo diametro è leggermente maggiore di quello del segmento sferico a due basi e il suo spessore è la metà.
- Un cilindro cavo con estremità toroidali ha superfici cilindriche esterna e interna unite da semitori, che formano semicirconferenze esatte in una sezione assiale.

## Illuminazione

Le caselle `Luce principale` e `Luce di riempimento` sotto i cursori di destra attivano o disattivano le due luci in modo indipendente per l’intera scena. Per impostazione predefinita, `Luce principale` è attiva e `Luce di riempimento` è disattivata. Le impostazioni di illuminazione vengono salvate separatamente per l’applicazione e il salvaschermo.

## Applicazione e salvaschermo

`FlyingSolids.exe` mantiene un’unica finestra di controllo mentre l’animazione è attiva. Si possono selezionare più monitor, commutarne uno con doppio clic o scollegarli tutti. I PNG vengono salvati per impostazione predefinita in **Immagini**, gli MP4 in **Video**, con **Documenti** come alternativa. L’EXE può installare o disinstallare il salvaschermo incorporato.

L’applicazione può essere eseguita in una sola istanza. Un nuovo avvio ripristina la finestra di controllo ridotta a icona, la ridisegna e la porta in primo piano.

Usare Tab e Maiusc+Tab per passare tra i controlli; Alt e la lettera sottolineata attivano un comando. Esc chiude la finestra attiva di Guida o Informazioni; nella finestra di controllo, termina l’applicazione.

Istantanee e registrazioni usano il primo monitor di animazione attivo, non un’immagine combinata di tutti i monitor. PNG usa Immagini, MP4 Video; se tali cartelle non esistono, viene usata Documenti. La registrazione MP4 segue la frequenza del monitor, fino a un massimo di 60 fotogrammi al secondo.

`FlyingSolids.scr` ha una propria finestra di impostazioni senza registrazione. A schermo intero crea una scena indipendente per ogni monitor.

Attiva anteprima nelle impostazioni avvia un’anteprima separata a schermo intero su tutti i monitor. Usa le impostazioni attuali, permette modifiche in tempo reale e può essere arrestata. Un tasto qualsiasi, un movimento del mouse o un clic chiude il salvaschermo a schermo intero.

Esc nelle impostazioni equivale ad Annulla; nella Guida o nelle Informazioni, chiude solo quella finestra.

## Archiviazione delle impostazioni

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Requisiti di sistema

I sistemi da Windows 7 a Windows 11 supportano tutte le funzioni, comprese le istantanee PNG e la registrazione MP4.

Per eseguire l’applicazione su Windows Vista SP2, è necessario installare gli aggiornamenti KB971512 e KB2117917. La registrazione MP4 non funziona in Vista nella versione attuale.

La visualizzazione richiede Direct3D 11, non soltanto un vecchio runtime DirectX. La registrazione MP4 richiede componenti Media Foundation e un codificatore H.264 disponibili.

## Compilazione

Aprire `DispSavers.slnx`, selezionare `Release | x86` e ricompilare la soluzione con MSVC v145 e Windows SDK. Vengono creati EXE e SCR. `PackageRelease.ps1` crea l’unico pacchetto `DispSavers-<version>-win32.zip` della soluzione, con i file e `license.txt` nella sottocartella `FlyingSolids`. Non è prevista una configurazione x64.

## Licenza

FlyingSolids è disponibile con [licenza MIT](../license.txt).

Copyright © Petr Červinka — FortSoft 2026
