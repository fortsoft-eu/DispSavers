# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · [Français](README.fr-FR.md) · [Español](README.es-ES.md) · **Italiano** · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Animazione con accelerazione hardware di oggetti 3D solidi.

Selezionare uno o più monitor nell’elenco. La modalità della telecamera, gli oggetti, le luci, le velocità, le dimensioni e il numero di copie si applicano solo ai monitor selezionati. Ogni monitor conserva le proprie impostazioni. FlyingSolids mostra solidi 3D illuminati. I cursori regolano la velocità di oggetti e camera tra 0 e 1600 %, da una a dieci copie e la dimensione tra 50 e 200 %. Scegliere Osservazione dello spazio o il Volo nello spazio rettilineo e attivare i solidi desiderati. Le caselle Luce principale, Luce di riempimento, Luce ambientale e Illuminazione dei contorni sotto i cursori controllano indipendentemente l’illuminazione dei monitor selezionati. La luce ambientale fornisce un’illuminazione di base alle superfici, mentre quella dei contorni ne evidenzia i bordi. Le impostazioni vengono salvate separatamente per l’applicazione e il salvaschermo.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Volo con accelerazione hardware attraverso un corridoio e un imbuto deformabili.

FlightCorridor: Volo tra quattro superfici deformabili; Volo attraverso un imbuto deformabile. Assegnare una sola animazione a ogni schermo. Texture alterna superfici con texture e modello a reticolo. La rotazione libera della telecamera cambia lentamente la direzione dello sguardo nelle tre dimensioni. L’opzione «Pause e inversioni» aggiunge rallentamenti, pause e inversioni casuali della rotazione; il volo in avanti continua. La velocità va da 0 a 1600%. Ogni schermo ha una scena casuale indipendente, renderizzata alla propria frequenza di aggiornamento. La luce principale, la luce di riempimento, la luce ambientale e l’illuminazione dei contorni si attivano separatamente per gli schermi selezionati. L’illuminazione si applica solo alle superfici con texture.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Volo con accelerazione hardware sopra superfici ondulanti e deformabili.

SpaceFlight: Superficie ondulante infinita; Volo a lunga distanza — superficie deformabile; Volo nello spazio deformato dalla gravità. Assegnare una sola animazione a ogni schermo. Texture alterna superfici con texture e modello a reticolo. La rotazione libera della telecamera cambia lentamente la direzione dello sguardo nelle tre dimensioni. L’opzione «Pause e inversioni» aggiunge rallentamenti, pause e inversioni casuali della rotazione; il volo in avanti continua. La velocità va da 0 a 1600%. Ogni schermo ha una scena casuale indipendente, renderizzata alla propria frequenza di aggiornamento. La luce principale, la luce di riempimento, la luce ambientale e l’illuminazione dei contorni si attivano separatamente per gli schermi selezionati. L’illuminazione si applica solo alle superfici con texture. Le due animazioni di superfici offrono Piano, Ondulazione o Imbuto. L’imbuto attira la telecamera verso l’interno lungo una spirale discendente. Il volo nello spazio deformato dalla gravità mostra un reticolo tridimensionale a fil di ferro. Le opzioni di texture, forma della superficie e illuminazione si applicano solo alle due animazioni di superfici.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Il gioco della vita di Conway in un mondo condiviso tra gli schermi.

### Regole

Il gioco della vita di Conway segue B3/S23. Una cella morta nasce con esattamente tre vicine vive; una viva sopravvive con due o tre. Le otto vicine includono le diagonali. Tutte cambiano simultaneamente. I bordi opposti si collegano: sinistra con destra, alto con basso.

### Schermi e mondo condiviso

Le caselle in EXE attivano gli schermi; le impostazioni valgono per il mondo condiviso. Un solo schermo attivo contiene l'intero mondo. Scegliendo parte degli schermi, righe e colonne completamente vuote vengono eliminate: sinistro e destro si uniscono disattivando quello centrale. I vuoti interni non eliminabili restano nella simulazione. Tutti gli schermi selezionati, oppure SCR, mantengono il rettangolo del desktop con gli spazi invisibili. Ogni schermo mostra la propria regione della stessa simulazione.

### Stato iniziale e configurazioni

L'avvio predefinito è rumore casuale con il 25 % di celle vive. La densità iniziale 0–100 % si applica al prossimo riavvio. Solo configurazioni note usa 4.106 configurazioni incluse senza rumore e disattiva la densità. Scegliere una miscela o un nome; le dimensioni sono in celle. Digitare per cercare. Sono elencate solo configurazioni che entrano interamente. Quelle piccole verificate si ripetono in copie separate, quelle grandi o complesse una volta al centro. Ridurre il mondo può sostituire una scelta troppo grande con una miscela. Cambiare modalità o configurazione crea una nuova scena. I riavvii conservano la scelta; il catalogo funziona offline.

### Celle, griglia e colori

Senza griglia la dimensione è 1–64 px. Mostra griglia aggiunge un bordo di 1 px nella spaziatura esistente: valore e cursore diminuiscono di uno, con 1–63 utilizzabili. Disattivandola il valore torna. Il cursore mantiene l'intervallo e torna indietro dall'estremo non disponibile; la casella resta attiva. La scena rimane, salvo attivazione a 1 px: la spaziatura diventa 2 px e la scena riparte. Anche cambiare dimensione o schermi crea una nuova scena. Mondi molto grandi possono richiedere un minimo superiore. I colori di celle, sfondo e griglia cambiano separatamente senza riavvio. Il colore casuale delle celle vive cambia a ogni riavvio manuale o automatico della scena. Il colore salvato rimane invariato e viene ripristinato disattivando questa opzione. Lo stesso comportamento può essere attivato separatamente per sfondo e griglia; entrambe le nuove opzioni sono inizialmente disattivate.

### Velocità, pausa e riavvio automatico

La velocità è 0–240 generazioni/s, indipendente dal refresh; 0 arresta l'evoluzione. Pausa e Riprendi conservano il mondo. Riavvia ricomincia nella modalità scelta. Il riavvio automatico facoltativo riconosce fasi visibili statiche o identiche che si ripetono, inclusi gli oscillatori. Confronta generazioni, non secondi; esclude le zone invisibili. I risultati asincroni possono ritardare leggermente il riavvio. Valori iniziali: spaziatura 8 px, 20 generazioni/s, colore casuale delle celle vive e riavvio automatico attivati. La griglia è disattivata per impostazione predefinita. La velocità raggiunta dipende dalle prestazioni e dal numero di celle. Il riavvio automatico confronta le regioni degli schermi attivi; gli spazi intermedi continuano a evolvere ma sono esclusi dal confronto.

### Ripristina valori

Il ripristino imposta la dimensione visualizzata a 8 px con o senza griglia (spaziatura di 9 o 8 px), la velocità a 20 generazioni/s, la densità al 25 % e i tre colori predefiniti. Le altre scelte sono conservate; una configurazione che non entra più viene sostituita dalla miscela. Una nuova scena viene creata solo se cambia la spaziatura o se cambia la densità in modalità rumore.

### Applicazione autonoma e registrazione MP4

EXE salva continuamente le impostazioni e registra il primo schermo attivo in MP4. Propone Video, altrimenti Documenti. Viewport usa dimensioni e refresh dello schermo fino a 60 fotogrammi/s. TV offre 1920 × 1080, 1440 × 1080 o 1280 × 720 in 16:9 a 50, 25, 59,94 (60000/1001) o 29,97 (30000/1001) fotogrammi/s. Le proporzioni restano invariate; TV usa BT.709 progressivo a intervallo limitato e 4:2:0. La finestra indipendente delle impostazioni può essere ridotta a icona. OK salva per la prossima registrazione; Annulla o Esc scarta le modifiche pendenti. Lo schermo registrato non può essere disattivato; le altre uscite possono cambiare. Uscire durante la registrazione richiede conferma. Con l'animazione attiva, Spazio alterna la pausa, F9: Avvia registrazione; F10: Ferma registrazione. Il puntatore scompare dopo 1 secondo inattivo e ritorna muovendolo. Tab/Shift+Tab passa tra i controlli; Alt attiva i comandi sottolineati. Esc chiude Guida/Informazioni, oppure esce dalla finestra principale. Salvaschermo di Windows… apre le impostazioni del salvaschermo del sistema.

### Istantanea e gestione del salvaschermo in EXE

L’istantanea salva in BMP/GIF/JPEG/PNG/TIFF/WebP lo schermo in registrazione, altrimenti il primo attivo, alla sua risoluzione senza riavviare la scena. La cartella proposta è Immagini, altrimenti Documenti. Bloccare il salvaschermo durante l’animazione ne impedisce l’avvio finché l’animazione è visibile e non in pausa. Velocità zero non significa pausa. L’installazione da EXE estrae il file SCR incluso e lo seleziona come salvaschermo Windows. Installazione e disinstallazione possono richiedere l’approvazione dell’amministratore; la barra di stato mostra l’operazione fino al termine. Se la rimozione è bloccata, chiudere il salvaschermo in esecuzione, le sue impostazioni e l’anteprima Windows.

### Salvaschermo Windows

GameOfLife.scr usa tutti gli schermi con impostazioni separate da EXE. Attiva anteprima avvia l'animazione a schermo intero mantenendo aperte le impostazioni. La piccola anteprima Windows riduce l'intero mondo. OK salva; Annulla o Esc scarta le modifiche. Muovere il mouse o premere un tasto termina il salvaschermo intero. La registrazione MP4 è disponibile in EXE.

### Posizione e stato delle finestre

Alla chiusura vengono salvate separatamente le posizioni della finestra principale e di Informazioni; per la Guida anche dimensioni e stato normale o ingrandito precedente alla riduzione a icona. Ciò è indipendente dalla conferma delle impostazioni. Uscire dall’applicazione chiude anche Guida e Informazioni.

### Rendering e licenze delle configurazioni

Evoluzione e confronti visibili usano shader Direct3D 11 sulla GPU; è disponibile un renderer software se l'inizializzazione hardware fallisce. Ogni schermo usa il regolatore di fotogrammi collaudato al proprio refresh. MP4 richiede Media Foundation e un codificatore H.264. Le configurazioni provengono da LifeWiki (GFDL 1.2 o successiva) e dalle raccolte di pubblico dominio di Alan Hensel. Il codice è MIT; avvisi e licenze del catalogo sono separati.

[Fonti delle configurazioni, licenze e dettagli di importazione](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### MONITOR

La selezione delle righe determina quali schermi si stanno configurando ed è distinta dalle caselle che attivano le uscite di animazione. Ctrl+A seleziona tutti gli schermi; Ctrl e Maiusc modificano la selezione. Tutte le opzioni e i cursori dell’animazione riguardano gli schermi selezionati. La selezione viene memorizzata separatamente per EXE e SCR. Se erano selezionati tutti gli schermi, vengono inclusi anche quelli nuovi. Valori diversi tra gli schermi selezionati sono indicati da caselle di controllo indeterminate e da una trama a punti sui pulsanti di opzione, sulle maniglie dei cursori e sui pulsanti «Attiva tutto» e «Disattiva tutto». Le etichette dei cursori mostrano un trattino al posto di un valore comune. Modificare un’opzione o fare clic su un cursore applica quel valore a tutti gli schermi selezionati.

### COMANDI

Attivare o disattivare le uscite di animazione con le caselle degli schermi o facendo doppio clic sulle rispettive righe. Ogni monitor usa una scena indipendente. Istantanea salva un BMP/GIF/JPEG/PNG/TIFF/WebP e il pulsante di registrazione avvia o arresta un MP4. Pausa ferma l’animazione. L’applicazione installa o disinstalla anche il salvaschermo incorporato. Le impostazioni vengono salvate continuamente. L’applicazione può essere eseguita in una sola istanza. Un nuovo avvio ripristina la finestra di controllo ridotta a icona e la porta in primo piano. Usare Tab e Maiusc+Tab per passare tra i controlli; Alt e la lettera sottolineata attivano un comando. Esc chiude la finestra attiva di Guida o Informazioni; nella finestra di controllo, termina l’applicazione. La pausa e il blocco del salvaschermo si applicano all’intera applicazione, indipendentemente dagli schermi selezionati. Quando il blocco è attivo, il salvaschermo di Windows viene impedito solo finché almeno uno schermo mostra un’animazione visibile e non in pausa.

### ISTANTANEE E REGISTRAZIONE

Istantanee e registrazioni usano il primo monitor di animazione attivo, non un’immagine combinata di tutti i monitor. BMP/GIF/JPEG/PNG/TIFF/WebP usa Immagini, MP4 Video; se tali cartelle non esistono, viene usata Documenti. Il pulsante Impostazioni video permette di scegliere Viewport o TV. Viewport mantiene le dimensioni e la frequenza di aggiornamento del monitor di animazione, fino a 60 fotogrammi al secondo. TV offre 1920 × 1080, 1440 × 1080 o 1280 × 720 in formato 16:9, a 50, 25, 59.94 (60000/1001) o 29.97 (30000/1001) fotogrammi al secondo. Le proporzioni sono mantenute; TV usa video progressivo BT.709 con intervallo limitato e campionamento 4:2:0. Risoluzione e frequenza sono disponibili solo in modalità TV. La finestra Impostazioni video può essere ridotta a icona e non blocca le altre finestre dell’applicazione. OK salva le opzioni per la prossima registrazione MP4; Annulla o Esc scarta le modifiche non confermate. L’uscita di animazione del monitor registrato non può essere disattivata durante la registrazione; le modifiche agli altri monitor non la interrompono. Chiudere l’applicazione durante una registrazione richiede conferma, perché interrompe anche la registrazione.

### ANTEPRIMA E COMANDI

Attiva anteprima avvia un’anteprima a schermo intero su tutti i monitor; le impostazioni rimangono aperte per le modifiche in tempo reale. OK salva e Annulla scarta. Esc o il movimento del mouse chiude il salvaschermo a schermo intero. Usare Tab e Maiusc+Tab per passare tra i controlli; Alt e la lettera sottolineata attivano un comando. Esc nelle impostazioni equivale ad Annulla; nella Guida o nelle Informazioni, chiude solo quella finestra.

### Requisiti di sistema

I sistemi da Windows 7 a Windows 11 supportano tutte le funzioni, comprese le istantanee BMP/GIF/JPEG/PNG/TIFF/WebP e la registrazione MP4. Per eseguire l’applicazione su Windows Vista SP2, è necessario installare gli aggiornamenti KB971512 e KB2117917. La registrazione MP4 non funziona in Vista nella versione attuale. La visualizzazione richiede Direct3D 11, non soltanto un vecchio runtime DirectX. La registrazione MP4 richiede componenti Media Foundation e un codificatore H.264 disponibili. L’applicazione autonoma può essere eseguita anche su Linux tramite Wine; l’integrazione come salvaschermo è disponibile solo su Windows.

## Compilazione

Aprire `DispSavers.slnx` in Visual Studio con MSVC v145 e Windows SDK. Selezionare `Release | x86` e ricompilare la soluzione per creare `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\GameOfLife.exe`, `Release\GameOfLife.scr`, `Release\SpaceFlight.exe` e `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr`. Non è prevista una configurazione x64.

Eseguire `PackageRelease.ps1` senza parametri di firma per creare il pacchetto dei file compilati. Lo script usa copie temporanee, non modifica i file in `Release` e verifica soltanto le firme valide esistenti. Crea l’unico archivio `DispSavers-<version>-win32.zip`, contenente `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `GameOfLife\GameOfLife.exe`, `GameOfLife\GameOfLife.scr`, `GameOfLife\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` e `SpaceFlight\license.txt`. Il vecchio ZIP viene eliminato all’inizio dell’esecuzione; un errore di verifica impedisce la creazione di un nuovo archivio.

## Licenza

DispSavers è disponibile con [licenza MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026
