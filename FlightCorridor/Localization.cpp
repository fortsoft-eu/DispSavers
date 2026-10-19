/**
 * This is open-source software licensed under the terms of the MIT License.
 *
 * Copyright (c) 2026 Petr Červinka - FortSoft <cervinka@fortsoft.eu>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **
 * Last modified for version 1.2.0.0
 */

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "Localization.h"
#include <windows.h>

using EffectTextArray = std::array<const wchar_t*, EFFECT_COUNT>;

/// Original corridor and funnel flight names
constexpr EffectTextArray CZECH_EFFECTS = {
    L"Průlet čtyřmi proměnlivými plochami",
    L"Průlet proměnlivým trychtýřem"
};

constexpr EffectTextArray ENGLISH_US_EFFECTS = {
    L"Flight between four morphing surfaces",
    L"Flight through a morphing funnel"
};

constexpr EffectTextArray ENGLISH_UK_EFFECTS = ENGLISH_US_EFFECTS;
constexpr EffectTextArray ENGLISH_AU_EFFECTS = ENGLISH_US_EFFECTS;
constexpr EffectTextArray GERMAN_EFFECTS = {
    L"Flug zwischen vier veränderlichen Flächen",
    L"Flug durch einen veränderlichen Trichter"
};

constexpr EffectTextArray FRENCH_EFFECTS = {
    L"Vol entre quatre surfaces déformables",
    L"Vol dans un entonnoir déformable"
};

constexpr EffectTextArray SPANISH_EFFECTS = {
    L"Vuelo entre cuatro superficies deformables",
    L"Vuelo por un embudo deformable"
};

constexpr EffectTextArray ITALIAN_EFFECTS = {
    L"Volo tra quattro superfici deformabili",
    L"Volo attraverso un imbuto deformabile"
};

constexpr EffectTextArray POLISH_EFFECTS = {
    L"Przelot między czterema zmiennymi powierzchniami",
    L"Przelot przez zmienny lejek"
};

constexpr EffectTextArray SLOVAK_EFFECTS = {
    L"Prelet štyrmi premenlivými plochami",
    L"Prelet premenlivým lievikom"
};

constexpr EffectTextArray PORTUGUESE_EFFECTS = {
    L"Voo entre quatro superfícies deformáveis",
    L"Voo através de um funil deformável"
};

constexpr EffectTextArray NORWEGIAN_EFFECTS = {
    L"Flytur mellom fire formendrende flater",
    L"Flytur gjennom en formendrende trakt"
};

constexpr EffectTextArray SWEDISH_EFFECTS = {
    L"Flygtur mellan fyra formföränderliga ytor",
    L"Flygtur genom en formföränderlig tratt"
};

constexpr EffectTextArray FINNISH_EFFECTS = {
    L"Lento neljän muuntuvan pinnan välissä",
    L"Lento muuntuvan suppilon läpi"
};

constexpr EffectTextArray DANISH_EFFECTS = {
    L"Flyvetur mellem fire formskiftende flader",
    L"Flyvetur gennem en formskiftende tragt"
};

constexpr EffectTextArray ICELANDIC_EFFECTS = {
    L"Flug milli fjögurra breytilegra flata",
    L"Flug í gegnum breytilega trekt"
};

constexpr EffectTextArray TURKISH_EFFECTS = {
    L"Biçim değiştiren dört yüzey arasında uçuş",
    L"Biçim değiştiren bir huninin içinden uçuş"
};

/// Core settings-window text records
const std::array<LocalizedText, LANGUAGE_COUNT> TEXTS = {
    LocalizedText{
        L"Čeština",
        L"FlightCorridor — ovládání",
        L"Nastavení FlightCorridor",
        L"Jazyk:",
        L"Rychlost animace: %d %%",
        L"Průlet vybraných monitorů",
        L"Vše zapnout",
        L"Vše vypnout",
        L"Monitor animace",
        L"Monitor",
        L"Rozlišení",
        L"Poloha",
        L"hlavní",
        L"OK",
        L"Storno",
        L"Spustit záznam…",
        L"Ukončit záznam",
        L"Pozastavit",
        L"Pokračovat",
        L"Nainstalovat spořič",
        L"Konec",
        L"Animace běží…",
        L"Probíhá záznam MP4…",
        L"Záznam byl uložen.",
        L"Záznam MP4 se nepodařilo spustit.",
        L"Instalace spořiče nebyla provedena.",
        L"Spořič byl nainstalován.",
        L"Direct3D renderer se nepodařilo inicializovat.",
        CZECH_EFFECTS
    },
    LocalizedText{
        L"English (US)",
        L"FlightCorridor — Controls",
        L"FlightCorridor Settings",
        L"Language:",
        L"Animation speed: %d %%",
        L"Flight for selected displays",
        L"Enable all",
        L"Disable all",
        L"Animation display",
        L"Display",
        L"Resolution",
        L"Position",
        L"primary",
        L"OK",
        L"Cancel",
        L"Start recording…",
        L"Stop recording",
        L"Pause",
        L"Resume",
        L"Install screen saver",
        L"Exit",
        L"Animation is running…",
        L"MP4 recording in progress…",
        L"Recording was saved.",
        L"Could not start MP4 recording.",
        L"The screen saver was not installed.",
        L"The screen saver was installed.",
        L"Could not initialize the Direct3D renderer.",
        ENGLISH_US_EFFECTS
    },
    LocalizedText{
        L"English (UK)",
        L"FlightCorridor — Controls",
        L"FlightCorridor Settings",
        L"Language:",
        L"Animation speed: %d %%",
        L"Flight for selected displays",
        L"Enable all",
        L"Disable all",
        L"Animation display",
        L"Display",
        L"Resolution",
        L"Position",
        L"primary",
        L"OK",
        L"Cancel",
        L"Start recording…",
        L"Stop recording",
        L"Pause",
        L"Resume",
        L"Install screen saver",
        L"Exit",
        L"Animation is running…",
        L"MP4 recording in progress…",
        L"Recording was saved.",
        L"Could not start MP4 recording.",
        L"The screen saver was not installed.",
        L"The screen saver was installed.",
        L"Could not initialise the Direct3D renderer.",
        ENGLISH_UK_EFFECTS
    },
    LocalizedText{
        L"English (Australia)",
        L"FlightCorridor — Controls",
        L"FlightCorridor Settings",
        L"Language:",
        L"Animation speed: %d %%",
        L"Flight for selected displays",
        L"Enable all",
        L"Disable all",
        L"Animation display",
        L"Display",
        L"Resolution",
        L"Position",
        L"primary",
        L"OK",
        L"Cancel",
        L"Start recording…",
        L"Stop recording",
        L"Pause",
        L"Resume",
        L"Install screen saver",
        L"Exit",
        L"Animation is running…",
        L"MP4 recording in progress…",
        L"Recording was saved.",
        L"Could not start MP4 recording.",
        L"The screen saver was not installed.",
        L"The screen saver was installed.",
        L"Could not initialise the Direct3D renderer.",
        ENGLISH_AU_EFFECTS
    },
    LocalizedText{
        L"Deutsch",
        L"FlightCorridor — Steuerung",
        L"FlightCorridor-Einstellungen",
        L"Sprache:",
        L"Animationsgeschwindigkeit: %d %%",
        L"Flug für ausgewählte Monitore",
        L"Alle aktivieren",
        L"Alle deaktivieren",
        L"Animationsmonitor",
        L"Monitor",
        L"Auflösung",
        L"Position",
        L"primär",
        L"OK",
        L"Abbrechen",
        L"Aufnahme starten…",
        L"Aufnahme beenden",
        L"Pause",
        L"Fortsetzen",
        L"Bildschirmschoner installieren",
        L"Beenden",
        L"Animation läuft…",
        L"MP4-Aufnahme läuft…",
        L"Aufnahme wurde gespeichert.",
        L"MP4-Aufnahme konnte nicht gestartet werden.",
        L"Der Bildschirmschoner wurde nicht installiert.",
        L"Der Bildschirmschoner wurde installiert.",
        L"Direct3D-Renderer konnte nicht initialisiert werden.",
        GERMAN_EFFECTS
    },
    LocalizedText{
        L"Français",
        L"FlightCorridor — Commandes",
        L"Paramètres de FlightCorridor",
        L"Langue :",
        L"Vitesse de l’animation : %d %%",
        L"Vol des moniteurs sélectionnés",
        L"Tout activer",
        L"Tout désactiver",
        L"Moniteur d’animation",
        L"Moniteur",
        L"Résolution",
        L"Position",
        L"principal",
        L"OK",
        L"Annuler",
        L"Démarrer l’enregistrement…",
        L"Arrêter l’enregistrement",
        L"Pause",
        L"Reprendre",
        L"Installer l’économiseur",
        L"Quitter",
        L"L’animation est en cours…",
        L"Enregistrement MP4 en cours…",
        L"L’enregistrement a été sauvegardé.",
        L"Impossible de démarrer l’enregistrement MP4.",
        L"L’économiseur n’a pas été installé.",
        L"L’économiseur a été installé.",
        L"Impossible d’initialiser le moteur Direct3D.",
        FRENCH_EFFECTS
    },
    LocalizedText{
        L"Español",
        L"FlightCorridor — Control",
        L"Configuración de FlightCorridor",
        L"Idioma:",
        L"Velocidad de animación: %d %%",
        L"Vuelo de los monitores seleccionados",
        L"Activar todo",
        L"Desactivar todo",
        L"Monitor de animación",
        L"Monitor",
        L"Resolución",
        L"Posición",
        L"principal",
        L"Aceptar",
        L"Cancelar",
        L"Iniciar grabación…",
        L"Detener grabación",
        L"Pausar",
        L"Continuar",
        L"Instalar salvapantallas",
        L"Salir",
        L"La animación está activa…",
        L"Grabando MP4…",
        L"La grabación se guardó.",
        L"No se pudo iniciar la grabación MP4.",
        L"No se instaló el salvapantallas.",
        L"El salvapantallas se instaló.",
        L"No se pudo inicializar Direct3D.",
        SPANISH_EFFECTS
    },
    LocalizedText{
        L"Italiano",
        L"FlightCorridor — Controlli",
        L"Impostazioni di FlightCorridor",
        L"Lingua:",
        L"Velocità animazione: %d %%",
        L"Volo per i monitor selezionati",
        L"Attiva tutto",
        L"Disattiva tutto",
        L"Monitor animazione",
        L"Monitor",
        L"Risoluzione",
        L"Posizione",
        L"principale",
        L"OK",
        L"Annulla",
        L"Avvia registrazione…",
        L"Ferma registrazione",
        L"Pausa",
        L"Riprendi",
        L"Installa salvaschermo",
        L"Esci",
        L"Animazione in esecuzione…",
        L"Registrazione MP4 in corso…",
        L"Registrazione salvata.",
        L"Impossibile avviare la registrazione MP4.",
        L"Il salvaschermo non è stato installato.",
        L"Il salvaschermo è stato installato.",
        L"Impossibile inizializzare Direct3D.",
        ITALIAN_EFFECTS
    },
    LocalizedText{
        L"Português",
        L"FlightCorridor — Controlo",
        L"Definições do FlightCorridor",
        L"Idioma:",
        L"Velocidade da animação: %d %%",
        L"Voo dos monitores selecionados",
        L"Ativar tudo",
        L"Desativar tudo",
        L"Monitor da animação",
        L"Monitor",
        L"Resolução",
        L"Posição",
        L"principal",
        L"OK",
        L"Cancelar",
        L"Iniciar gravação…",
        L"Parar gravação",
        L"Pausar",
        L"Continuar",
        L"Instalar proteção de ecrã",
        L"Sair",
        L"A animação está em execução…",
        L"Gravação MP4 em curso…",
        L"A gravação foi guardada.",
        L"Não foi possível iniciar a gravação MP4.",
        L"A proteção de ecrã não foi instalada.",
        L"A proteção de ecrã foi instalada.",
        L"Não foi possível inicializar o Direct3D.",
        PORTUGUESE_EFFECTS
    },
    LocalizedText{
        L"Polski",
        L"FlightCorridor — Sterowanie",
        L"Ustawienia FlightCorridor",
        L"Język:",
        L"Prędkość animacji: %d %%",
        L"Przelot na wybranych monitorach",
        L"Włącz wszystko",
        L"Wyłącz wszystko",
        L"Monitor animacji",
        L"Monitor",
        L"Rozdzielczość",
        L"Położenie",
        L"główny",
        L"OK",
        L"Anuluj",
        L"Rozpocznij nagrywanie…",
        L"Zatrzymaj nagrywanie",
        L"Wstrzymaj",
        L"Wznów",
        L"Zainstaluj wygaszacz",
        L"Zakończ",
        L"Animacja działa…",
        L"Trwa nagrywanie MP4…",
        L"Nagranie zapisano.",
        L"Nie udało się rozpocząć nagrywania MP4.",
        L"Wygaszacz nie został zainstalowany.",
        L"Wygaszacz został zainstalowany.",
        L"Nie udało się uruchomić renderera Direct3D.",
        POLISH_EFFECTS
    },
    LocalizedText{
        L"Slovenčina",
        L"FlightCorridor — Ovládanie",
        L"Nastavenia FlightCorridor",
        L"Jazyk:",
        L"Rýchlosť animácie: %d %%",
        L"Prelet vybraných monitorov",
        L"Všetko zapnúť",
        L"Všetko vypnúť",
        L"Monitor animácie",
        L"Monitor",
        L"Rozlíšenie",
        L"Poloha",
        L"hlavný",
        L"OK",
        L"Zrušiť",
        L"Spustiť záznam…",
        L"Ukončiť záznam",
        L"Pozastaviť",
        L"Pokračovať",
        L"Nainštalovať šetrič",
        L"Koniec",
        L"Animácia beží…",
        L"Prebieha záznam MP4…",
        L"Záznam bol uložený.",
        L"Záznam MP4 sa nepodarilo spustiť.",
        L"Šetrič nebol nainštalovaný.",
        L"Šetrič bol nainštalovaný.",
        L"Renderer Direct3D sa nepodarilo inicializovať.",
        SLOVAK_EFFECTS
    },
    LocalizedText{
        L"Dansk",
        L"FlightCorridor — Styring",
        L"Indstillinger for FlightCorridor",
        L"Sprog:",
        L"Animationshastighed: %d %%",
        L"Flyvetur for valgte skærme",
        L"Aktivér alle",
        L"Deaktivér alle",
        L"Animationsskærm",
        L"Skærm",
        L"Opløsning",
        L"Placering",
        L"primær",
        L"OK",
        L"Annuller",
        L"Start optagelse…",
        L"Stop optagelse",
        L"Pause",
        L"Fortsæt",
        L"Installer pauseskærm",
        L"Afslut",
        L"Animationen kører…",
        L"MP4-optagelse i gang…",
        L"Optagelsen blev gemt.",
        L"MP4-optagelsen kunne ikke startes.",
        L"Pauseskærmen blev ikke installeret.",
        L"Pauseskærmen blev installeret.",
        L"Direct3D kunne ikke initialiseres.",
        DANISH_EFFECTS
    },
    LocalizedText{
        L"Suomi",
        L"FlightCorridor — Ohjaus",
        L"FlightCorridor-asetukset",
        L"Kieli:",
        L"Animaation nopeus: %d %%",
        L"Valittujen näyttöjen lento",
        L"Ota kaikki käyttöön",
        L"Poista kaikki käytöstä",
        L"Animaation näyttö",
        L"Näyttö",
        L"Tarkkuus",
        L"Sijainti",
        L"ensisijainen",
        L"OK",
        L"Peruuta",
        L"Aloita tallennus…",
        L"Lopeta tallennus",
        L"Keskeytä",
        L"Jatka",
        L"Asenna näytönsäästäjä",
        L"Lopeta",
        L"Animaatio on käynnissä…",
        L"MP4-tallennus käynnissä…",
        L"Tallenne tallennettiin.",
        L"MP4-tallennusta ei voitu aloittaa.",
        L"Näytönsäästäjää ei asennettu.",
        L"Näytönsäästäjä asennettiin.",
        L"Direct3D-renderöintiä ei voitu alustaa.",
        FINNISH_EFFECTS
    },
    LocalizedText{
        L"Íslenska",
        L"FlightCorridor — Stjórnun",
        L"Stillingar FlightCorridor",
        L"Tungumál:",
        L"Hraði hreyfimyndar: %d %%",
        L"Flug fyrir valda skjái",
        L"Virkja allt",
        L"Óvirkja allt",
        L"Hreyfimyndaskjár",
        L"Skjár",
        L"Upplausn",
        L"Staðsetning",
        L"aðal",
        L"Í lagi",
        L"Hætta við",
        L"Hefja upptöku…",
        L"Stöðva upptöku",
        L"Gera hlé",
        L"Halda áfram",
        L"Setja upp skjáhvílu",
        L"Hætta",
        L"Hreyfimyndin er í gangi…",
        L"MP4-upptaka í gangi…",
        L"Upptakan var vistuð.",
        L"Ekki tókst að hefja MP4-upptöku.",
        L"Skjáhvílan var ekki sett upp.",
        L"Skjáhvílan var sett upp.",
        L"Ekki tókst að ræsa Direct3D.",
        ICELANDIC_EFFECTS
    },
    LocalizedText{
        L"Norsk",
        L"FlightCorridor — Kontroll",
        L"Innstillinger for FlightCorridor",
        L"Språk:",
        L"Animasjonshastighet: %d %%",
        L"Flytur for valgte skjermer",
        L"Slå på alle",
        L"Slå av alle",
        L"Animasjonsskjerm",
        L"Skjerm",
        L"Oppløsning",
        L"Posisjon",
        L"primær",
        L"OK",
        L"Avbryt",
        L"Start opptak…",
        L"Stopp opptak",
        L"Pause",
        L"Fortsett",
        L"Installer skjermsparer",
        L"Avslutt",
        L"Animasjonen kjører…",
        L"MP4-opptak pågår…",
        L"Opptaket ble lagret.",
        L"Kunne ikke starte MP4-opptak.",
        L"Skjermspareren ble ikke installert.",
        L"Skjermspareren ble installert.",
        L"Kunne ikke initialisere Direct3D.",
        NORWEGIAN_EFFECTS
    },
    LocalizedText{
        L"Svenska",
        L"FlightCorridor — Styrning",
        L"Inställningar för FlightCorridor",
        L"Språk:",
        L"Animationshastighet: %d %%",
        L"Flygtur för valda bildskärmar",
        L"Aktivera alla",
        L"Inaktivera alla",
        L"Animationsskärm",
        L"Bildskärm",
        L"Upplösning",
        L"Position",
        L"primär",
        L"OK",
        L"Avbryt",
        L"Starta inspelning…",
        L"Stoppa inspelning",
        L"Pausa",
        L"Fortsätt",
        L"Installera skärmsläckare",
        L"Avsluta",
        L"Animeringen körs…",
        L"MP4-inspelning pågår…",
        L"Inspelningen sparades.",
        L"Det gick inte att starta MP4-inspelningen.",
        L"Skärmsläckaren installerades inte.",
        L"Skärmsläckaren installerades.",
        L"Det gick inte att initiera Direct3D.",
        SWEDISH_EFFECTS
    },
    LocalizedText{
        L"Türkçe",
        L"FlightCorridor — Denetim",
        L"FlightCorridor Ayarları",
        L"Dil:",
        L"Animasyon hızı: %d %%",
        L"Seçili monitörlerdeki uçuş",
        L"Tümünü etkinleştir",
        L"Tümünü devre dışı bırak",
        L"Animasyon monitörü",
        L"Monitör",
        L"Çözünürlük",
        L"Konum",
        L"birincil",
        L"Tamam",
        L"İptal",
        L"Kaydı başlat…",
        L"Kaydı durdur",
        L"Duraklat",
        L"Sürdür",
        L"Ekran koruyucuyu yükle",
        L"Çıkış",
        L"Animasyon çalışıyor…",
        L"MP4 kaydı sürüyor…",
        L"Kayıt kaydedildi.",
        L"MP4 kaydı başlatılamadı.",
        L"Ekran koruyucu yüklenmedi.",
        L"Ekran koruyucu yüklendi.",
        L"Direct3D başlatılamadı.",
        TURKISH_EFFECTS
    }
};

/// Monitor-detail column captions and explicit bit-depth units.
constexpr std::array<MonitorColumnText, LANGUAGE_COUNT> MONITOR_COLUMN_TEXTS = {
    MonitorColumnText{
        L"Model monitoru",
        L"Obnovovací frekvence",
        L"Bitová hloubka",
        L"Formát barvy",
        L"Barevný prostor",
        L"%u bitů/kanál",
        L"%u bitů/pixel"
},
    MonitorColumnText{
        L"Monitor model",
        L"Refresh rate",
        L"Bit depth",
        L"Color format",
        L"Color space",
        L"%u bits/channel",
        L"%u bits/pixel"
},
    MonitorColumnText{
        L"Monitor model",
        L"Refresh rate",
        L"Bit depth",
        L"Colour format",
        L"Colour space",
        L"%u bits/channel",
        L"%u bits/pixel"
},
    MonitorColumnText{
        L"Monitor model",
        L"Refresh rate",
        L"Bit depth",
        L"Colour format",
        L"Colour space",
        L"%u bits/channel",
        L"%u bits/pixel"
},
    MonitorColumnText{
        L"Monitormodell",
        L"Bildwiederholfrequenz",
        L"Bittiefe",
        L"Farbformat",
        L"Farbraum",
        L"%u Bit/Kanal",
        L"%u Bit/Pixel"
},
    MonitorColumnText{
        L"Modèle du moniteur",
        L"Fréquence de rafraîchissement",
        L"Profondeur de bits",
        L"Format de couleur",
        L"Espace colorimétrique",
        L"%u bits/canal",
        L"%u bits/pixel"
},
    MonitorColumnText{
        L"Modelo del monitor",
        L"Frecuencia de actualización",
        L"Profundidad de bits",
        L"Formato de color",
        L"Espacio de color",
        L"%u bits/canal",
        L"%u bits/píxel"
},
    MonitorColumnText{
        L"Modello del monitor",
        L"Frequenza di aggiornamento",
        L"Profondità di bit",
        L"Formato colore",
        L"Spazio colore",
        L"%u bit/canale",
        L"%u bit/pixel"
},
    MonitorColumnText{
        L"Modelo do monitor",
        L"Taxa de atualização",
        L"Profundidade de bits",
        L"Formato de cor",
        L"Espaço de cor",
        L"%u bits/canal",
        L"%u bits/píxel"
},
    MonitorColumnText{
        L"Model monitora",
        L"Częstotliwość odświeżania",
        L"Głębia bitowa",
        L"Format koloru",
        L"Przestrzeń barw",
        L"%u bitów/kanał",
        L"%u bitów/piksel"
},
    MonitorColumnText{
        L"Model monitora",
        L"Obnovovacia frekvencia",
        L"Bitová hĺbka",
        L"Formát farby",
        L"Farebný priestor",
        L"%u bitov/kanál",
        L"%u bitov/pixel"
},
    MonitorColumnText{
        L"Skærmmodel",
        L"Opdateringsfrekvens",
        L"Bitdybde",
        L"Farveformat",
        L"Farverum",
        L"%u bit/kanal",
        L"%u bit/pixel"
},
    MonitorColumnText{
        L"Näytön malli",
        L"Virkistystaajuus",
        L"Bittisyvyys",
        L"Värimuoto",
        L"Väriavaruus",
        L"%u bittiä/kanava",
        L"%u bittiä/pikseli"
},
    MonitorColumnText{
        L"Gerð skjás",
        L"Endurnýjunartíðni",
        L"Bitadýpt",
        L"Litasnið",
        L"Litarými",
        L"%u bitar/rás",
        L"%u bitar/myndpunktur"
},
    MonitorColumnText{
        L"Skjermmodell",
        L"Oppdateringsfrekvens",
        L"Bitdybde",
        L"Fargeformat",
        L"Fargerom",
        L"%u bit/kanal",
        L"%u bit/piksel"
},
    MonitorColumnText{
        L"Skärmmodell",
        L"Uppdateringsfrekvens",
        L"Bitdjup",
        L"Färgformat",
        L"Färgrymd",
        L"%u bitar/kanal",
        L"%u bitar/pixel"
},
    MonitorColumnText{
        L"Monitör modeli",
        L"Yenileme hızı",
        L"Bit derinliği",
        L"Renk biçimi",
        L"Renk alanı",
        L"%u bit/kanal",
        L"%u bit/piksel"
}
};



constexpr std::array<const wchar_t*, LANGUAGE_COUNT> ENABLE_PREVIEW_TEXTS = {
    L"Zapnout náhled",
    L"Enable preview",
    L"Enable preview",
    L"Enable preview",
    L"Vorschau einschalten",
    L"Activer l’aperçu",
    L"Activar vista previa",
    L"Attiva anteprima",
    L"Ativar pré-visualização",
    L"Włącz podgląd",
    L"Zapnúť náhľad",
    L"Aktivér forhåndsvisning",
    L"Ota esikatselu käyttöön",
    L"Virkja forskoðun",
    L"Slå på forhåndsvisning",
    L"Aktivera förhandsvisning",
    L"Önizlemeyi aç"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> DISABLE_PREVIEW_TEXTS = {
    L"Vypnout náhled",
    L"Disable preview",
    L"Disable preview",
    L"Disable preview",
    L"Vorschau ausschalten",
    L"Désactiver l’aperçu",
    L"Desactivar vista previa",
    L"Disattiva anteprima",
    L"Desativar pré-visualização",
    L"Wyłącz podgląd",
    L"Vypnúť náhľad",
    L"Deaktivér forhåndsvisning",
    L"Poista esikatselu käytöstä",
    L"Slökkva á forskoðun",
    L"Slå av forhåndsvisning",
    L"Inaktivera förhandsvisning",
    L"Önizlemeyi kapat"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> PREVENT_SCREEN_SAVER_TEXTS = {
    L"Blokovat spořič při animaci",
    L"Prevent screen saver during animation",
    L"Prevent screen saver during animation",
    L"Prevent screen saver during animation",
    L"Bildschirmschoner bei Animation sperren",
    L"Bloquer l’écran de veille pendant l’animation",
    L"Bloquear salvapantallas durante la animación",
    L"Blocca salvaschermo durante l’animazione",
    L"Bloquear proteção de ecrã durante a animação",
    L"Blokuj wygaszacz podczas animacji",
    L"Blokovať šetrič pri animácii",
    L"Blokér pauseskærm under animation",
    L"Estä näytönsäästäjä animaation aikana",
    L"Hindra skjáhvílu meðan hreyfimynd er í gangi",
    L"Hindre skjermsparer under animasjon",
    L"Blockera skärmsläckare under animering",
    L"Animasyon sırasında ekran koruyucuyu engelle"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> READY_STATUS_TEXTS = {
    L"Připraven.",
    L"Ready.",
    L"Ready.",
    L"Ready.",
    L"Bereit.",
    L"Prêt.",
    L"Listo.",
    L"Pronto.",
    L"Pronto.",
    L"Gotowy.",
    L"Pripravený.",
    L"Klar.",
    L"Valmis.",
    L"Tilbúið.",
    L"Klar.",
    L"Redo.",
    L"Hazır."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> PAUSED_STATUS_TEXTS = {
    L"Animace je pozastavena.",
    L"Animation is paused.",
    L"Animation is paused.",
    L"Animation is paused.",
    L"Animation ist angehalten.",
    L"L’animation est en pause.",
    L"La animación está en pausa.",
    L"L’animazione è in pausa.",
    L"A animação está em pausa.",
    L"Animacja jest wstrzymana.",
    L"Animácia je pozastavená.",
    L"Animationen er sat på pause.",
    L"Animaatio on keskeytetty.",
    L"Hlé hefur verið gert á hreyfimyndinni.",
    L"Animasjonen er satt på pause.",
    L"Animeringen är pausad.",
    L"Animasyon duraklatıldı."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> HELP_BUTTON_TEXTS = {
    L"Nápověda",
    L"Help",
    L"Help",
    L"Help",
    L"Hilfe",
    L"Aide",
    L"Ayuda",
    L"Guida",
    L"Ajuda",
    L"Pomoc",
    L"Pomoc",
    L"Hjælp",
    L"Ohje",
    L"Hjálp",
    L"Hjelp",
    L"Hjälp",
    L"Yardım"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> ABOUT_BUTTON_TEXTS = {
    L"O aplikaci",
    L"About",
    L"About",
    L"About",
    L"Info",
    L"À propos",
    L"Acerca de",
    L"Informazioni",
    L"Acerca de",
    L"O programie",
    L"O aplikácii",
    L"Om",
    L"Tietoja",
    L"Um",
    L"Om",
    L"Om",
    L"Hakkında"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> ABOUT_VERSION_LABELS = {
    L"Verze:",
    L"Version:",
    L"Version:",
    L"Version:",
    L"Version:",
    L"Version :",
    L"Versión:",
    L"Versione:",
    L"Versão:",
    L"Wersja:",
    L"Verzia:",
    L"Version:",
    L"Versio:",
    L"Útgáfa:",
    L"Versjon:",
    L"Version:",
    L"Sürüm:"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> ABOUT_PLATFORM_LABELS = {
    L"Cílová platforma:",
    L"Target platform:",
    L"Target platform:",
    L"Target platform:",
    L"Zielplattform:",
    L"Plateforme cible :",
    L"Plataforma de destino:",
    L"Piattaforma di destinazione:",
    L"Plataforma de destino:",
    L"Platforma docelowa:",
    L"Cieľová platforma:",
    L"Målplatform:",
    L"Kohdealusta:",
    L"Markvettvangur:",
    L"Målplattform:",
    L"Målplattform:",
    L"Hedef platform:"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> ABOUT_WEBSITE_LABELS = {
    L"Web:",
    L"Website:",
    L"Website:",
    L"Website:",
    L"Website:",
    L"Site web :",
    L"Sitio web:",
    L"Sito web:",
    L"Site:",
    L"Witryna:",
    L"Web:",
    L"Websted:",
    L"Verkkosivusto:",
    L"Vefsvæði:",
    L"Nettsted:",
    L"Webbplats:",
    L"Web sitesi:"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> OPEN_IN_BROWSER_TEXTS = {
    L"&Otevřít ve výchozím prohlížeči",
    L"&Open in default browser",
    L"&Open in default browser",
    L"&Open in default browser",
    L"Im Standardbrowser &öffnen",
    L"&Ouvrir dans le navigateur par défaut",
    L"&Abrir en el navegador predeterminado",
    L"&Apri nel browser predefinito",
    L"&Abrir no navegador predefinido",
    L"&Otwórz w domyślnej przeglądarce",
    L"&Otvoriť v predvolenom prehliadači",
    L"&Åbn i standardbrowseren",
    L"&Avaa oletusselaimessa",
    L"&Opna í sjálfgefnum vafra",
    L"&Åpne i standardnettleseren",
    L"&Öppna i standardwebbläsaren",
    L"Varsayılan tarayıcıda &aç"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> COPY_URL_TEXTS = {
    L"Kopírovat &adresu",
    L"Copy &URL",
    L"Copy &URL",
    L"Copy &URL",
    L"&URL kopieren",
    L"Copier l’&URL",
    L"Copiar &URL",
    L"Copia &URL",
    L"Copiar &URL",
    L"Kopiuj &adres URL",
    L"Kopírovať &adresu",
    L"Kopiér &URL",
    L"Kopioi &URL",
    L"Afrita &vefslóð",
    L"Kopier &URL",
    L"Kopiera &URL",
    L"&URL'yi kopyala"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> COPY_INFORMATION_TEXTS = {
    L"Kopírovat &informace",
    L"Copy &information",
    L"Copy &information",
    L"Copy &information",
    L"&Informationen kopieren",
    L"Copier les &informations",
    L"Copiar &información",
    L"Copia &informazioni",
    L"Copiar &informações",
    L"Kopiuj &informacje",
    L"Kopírovať &informácie",
    L"Kopiér &oplysninger",
    L"Kopioi &tiedot",
    L"Afrita &upplýsingar",
    L"Kopier &informasjon",
    L"Kopiera &information",
    L"&Bilgileri kopyala"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> CLOSE_BUTTON_TEXTS = {
    L"Zavřít",
    L"Close",
    L"Close",
    L"Close",
    L"Schließen",
    L"Fermer",
    L"Cerrar",
    L"Chiudi",
    L"Fechar",
    L"Zamknij",
    L"Zavrieť",
    L"Luk",
    L"Sulje",
    L"Loka",
    L"Lukk",
    L"Stäng",
    L"Kapat"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> SNAPSHOT_BUTTON_TEXTS = {
    L"Snímek…",
    L"Snapshot…",
    L"Snapshot…",
    L"Snapshot…",
    L"Schnappschuss…",
    L"Capture…",
    L"Captura…",
    L"Istantanea…",
    L"Captura…",
    L"Zrzut…",
    L"Snímka…",
    L"Skærmbillede…",
    L"Tilannekuva…",
    L"Skjámynd…",
    L"Skjermbilde…",
    L"Skärmbild…",
    L"Anlık görüntü…"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> SNAPSHOT_SAVED_TEXTS = {
    L"Snímek byl uložen.",
    L"Snapshot was saved.",
    L"Snapshot was saved.",
    L"Snapshot was saved.",
    L"Schnappschuss wurde gespeichert.",
    L"La capture a été enregistrée.",
    L"La captura se guardó.",
    L"L’istantanea è stata salvata.",
    L"A captura foi guardada.",
    L"Zrzut został zapisany.",
    L"Snímka bola uložená.",
    L"Skærmbilledet blev gemt.",
    L"Tilannekuva tallennettiin.",
    L"Skjámyndin var vistuð.",
    L"Skjermbildet ble lagret.",
    L"Skärmbilden sparades.",
    L"Anlık görüntü kaydedildi."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> SNAPSHOT_FAILED_TEXTS = {
    L"Snímek se nepodařilo uložit.",
    L"Could not save the snapshot.",
    L"Could not save the snapshot.",
    L"Could not save the snapshot.",
    L"Der Schnappschuss konnte nicht gespeichert werden.",
    L"Impossible d’enregistrer la capture.",
    L"No se pudo guardar la captura.",
    L"Impossibile salvare l’istantanea.",
    L"Não foi possível guardar a captura.",
    L"Nie udało się zapisać zrzutu.",
    L"Snímku sa nepodarilo uložiť.",
    L"Skærmbilledet kunne ikke gemmes.",
    L"Tilannekuvaa ei voitu tallentaa.",
    L"Ekki tókst að vista skjámyndina.",
    L"Kunne ikke lagre skjermbildet.",
    L"Det gick inte att spara skärmbilden.",
    L"Anlık görüntü kaydedilemedi."
};

/// Screen-saver installation text
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALL_SCREEN_SAVER_TEXTS = {
    L"Odinstalovat spořič",
    L"Uninstall screen saver",
    L"Uninstall screen saver",
    L"Uninstall screen saver",
    L"Bildschirmschoner deinstallieren",
    L"Désinstaller l’économiseur",
    L"Desinstalar salvapantallas",
    L"Disinstalla salvaschermo",
    L"Desinstalar proteção de ecrã",
    L"Odinstaluj wygaszacz",
    L"Odinštalovať šetrič",
    L"Afinstaller pauseskærm",
    L"Poista näytönsäästäjä",
    L"Fjarlægja skjáhvílu",
    L"Avinstaller skjermsparer",
    L"Avinstallera skärmsläckare",
    L"Ekran koruyucuyu kaldır"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALLATION_SUCCEEDED_TEXTS = {
    L"Spořič byl odinstalován.",
    L"The screen saver was uninstalled.",
    L"The screen saver was uninstalled.",
    L"The screen saver was uninstalled.",
    L"Der Bildschirmschoner wurde deinstalliert.",
    L"L’économiseur a été désinstallé.",
    L"El salvapantallas se desinstaló.",
    L"Il salvaschermo è stato disinstallato.",
    L"A proteção de ecrã foi desinstalada.",
    L"Wygaszacz został odinstalowany.",
    L"Šetrič bol odinštalovaný.",
    L"Pauseskærmen blev afinstalleret.",
    L"Näytönsäästäjä poistettiin.",
    L"Skjáhvílan var fjarlægð.",
    L"Skjermspareren ble avinstallert.",
    L"Skärmsläckaren avinstallerades.",
    L"Ekran koruyucu kaldırıldı."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALLATION_FAILED_TEXTS = {
    L"Odinstalace se nezdařila. Pokud je spořič nebo jeho náhled spuštěný, zavřete jej a odinstalaci "
    L"zopakujte.",
    L"The screen saver could not be uninstalled. If the screen saver or its preview is running, close "
    L"it and "
    L"try again.",
    L"The screen saver could not be uninstalled. If the screen saver or its preview is running, close "
    L"it and "
    L"try again.",
    L"The screen saver could not be uninstalled. If the screen saver or its preview is running, close "
    L"it and "
    L"try again.",
    L"Der Bildschirmschoner konnte nicht deinstalliert werden. Falls der Bildschirmschoner oder seine "
    L"Vorschau läuft, schließen Sie ihn und versuchen Sie es erneut.",
    L"Impossible de désinstaller l’économiseur. S’il est en cours d’exécution ou si son aperçu est ouvert, "
    L"fermez-le puis réessayez.",
    L"No se pudo desinstalar el salvapantallas. Si el salvapantallas o su vista previa están en ejecución, "
    L"ciérrelos e inténtelo de nuevo.",
    L"Impossibile disinstallare il salvaschermo. Se il salvaschermo o la relativa anteprima sono in "
    L"esecuzione, chiuderli e riprovare.",
    L"Não foi possível desinstalar a proteção de ecrã. Se a proteção ou a pré-visualização estiver em "
    L"execução, feche-a e tente novamente.",
    L"Nie udało się odinstalować wygaszacza. Jeśli wygaszacz lub jego podgląd jest uruchomiony, zamknij "
    L"go i "
    L"spróbuj ponownie.",
    L"Šetrič sa nepodarilo odinštalovať. Ak je šetrič alebo jeho náhľad spustený, zatvorte ho a skúste to "
    L"znova.",
    L"Pauseskærmen kunne ikke afinstalleres. Hvis pauseskærmen eller forhåndsvisningen kører, skal du lukke "
    L"den og prøve igen.",
    L"Näytönsäästäjän poistaminen epäonnistui. Jos näytönsäästäjä tai sen esikatselu on käynnissä, sulje se "
    L"ja yritä uudelleen.",
    L"Ekki tókst að fjarlægja skjáhvíluna. Ef skjáhvílan eða forskoðun hennar er í gangi skaltu loka henni "
    L"og reyna aftur.",
    L"Skjermspareren kunne ikke avinstalleres. Hvis skjermspareren eller forhåndsvisningen kjører, lukk den "
    L"og prøv på nytt.",
    L"Skärmsläckaren kunde inte avinstalleras. Om skärmsläckaren eller förhandsvisningen körs, stäng "
    L"den och "
    L"försök igen.",
    L"Ekran koruyucu kaldırılamadı. Ekran koruyucu veya önizlemesi çalışıyorsa kapatıp yeniden deneyin."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALLATION_BLOCKED_BY_SETTINGS_TEXTS = {
    L"Odinstalace se nezdařila, protože je otevřené nastavení FlightCorridor. Zavřete je a odinstalaci "
    L"zopakujte.",
    L"Uninstallation failed because FlightCorridor settings are open. Close the settings window and try "
    L"again.",
    L"Uninstallation failed because FlightCorridor settings are open. Close the settings window and try "
    L"again.",
    L"Uninstallation failed because FlightCorridor settings are open. Close the settings window and try "
    L"again.",
    L"Die Deinstallation ist fehlgeschlagen, weil die FlightCorridor-Einstellungen geöffnet sind. Schließen "
    L"Sie das Fenster und versuchen Sie es erneut.",
    L"La désinstallation a échoué car les paramètres de FlightCorridor sont ouverts. Fermez cette "
    L"fenêtre puis "
    L"réessayez.",
    L"La desinstalación falló porque la configuración de FlightCorridor está abierta. Cierre esa ventana e "
    L"inténtelo de nuevo.",
    L"La disinstallazione non è riuscita perché le impostazioni di FlightCorridor sono aperte. Chiudere la "
    L"finestra e riprovare.",
    L"A desinstalação falhou porque as definições do FlightCorridor estão abertas. Feche a janela e tente "
    L"novamente.",
    L"Odinstalowanie nie powiodło się, ponieważ ustawienia FlightCorridor są otwarte. Zamknij okno i "
    L"spróbuj "
    L"ponownie.",
    L"Odinštalovanie zlyhalo, pretože sú otvorené nastavenia FlightCorridor. Zatvorte ich a skúste to "
    L"znova.",
    L"Afinstallationen mislykkedes, fordi indstillingerne for FlightCorridor er åbne. Luk vinduet, og prøv "
    L"igen.",
    L"Asennuksen poisto epäonnistui, koska FlightCorridor-asetukset ovat avoinna. Sulje ikkuna ja yritä "
    L"uudelleen.",
    L"Fjarlæging mistókst vegna þess að stillingar FlightCorridor eru opnar. Lokaðu glugganum og reyndu "
    L"aftur.",
    L"Avinstalleringen mislyktes fordi innstillingene for FlightCorridor er åpne. Lukk vinduet og prøv på "
    L"nytt.",
    L"Avinstallationen misslyckades eftersom inställningarna för FlightCorridor är öppna. Stäng "
    L"fönstret och "
    L"försök igen.",
    L"FlightCorridor ayarları açık olduğu için kaldırma başarısız oldu. Ayarlar penceresini kapatıp yeniden "
    L"deneyin."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW_TEXTS = {
    L"Odinstalace se nezdařila, protože běží systémový náhled. Zavřete okno Nastavení spořiče obrazovky a "
    L"odinstalaci zopakujte.",
    L"Uninstallation failed because the system preview is running. Close the Screen Saver Settings window "
    L"and try again.",
    L"Uninstallation failed because the system preview is running. Close the Screen Saver Settings window "
    L"and try again.",
    L"Uninstallation failed because the system preview is running. Close the Screen Saver Settings window "
    L"and try again.",
    L"Die Deinstallation ist fehlgeschlagen, weil die Systemvorschau läuft. Schließen Sie das Fenster "
    L"Bildschirmschonereinstellungen und versuchen Sie es erneut.",
    L"La désinstallation a échoué car l’aperçu système est actif. Fermez la fenêtre Paramètres de "
    L"l’économiseur d’écran puis réessayez.",
    L"La desinstalación falló porque se está ejecutando la vista previa del sistema. Cierre Configuración "
    L"del protector de pantalla e inténtelo de nuevo.",
    L"La disinstallazione non è riuscita perché è attiva l’anteprima di sistema. Chiudere Impostazioni "
    L"salvaschermo e riprovare.",
    L"A desinstalação falhou porque a pré-visualização do sistema está em execução. Feche as Definições da "
    L"proteção de ecrã e tente novamente.",
    L"Odinstalowanie nie powiodło się, ponieważ działa podgląd systemowy. Zamknij okno Ustawienia "
    L"wygaszacza "
    L"ekranu i spróbuj ponownie.",
    L"Odinštalovanie zlyhalo, pretože beží systémový náhľad. Zatvorte okno Nastavenie šetriča obrazovky a "
    L"skúste to znova.",
    L"Afinstallationen mislykkedes, fordi systemforhåndsvisningen kører. Luk vinduet "
    L"Pauseskærmsindstillinger, og prøv igen.",
    L"Asennuksen poisto epäonnistui, koska järjestelmän esikatselu on käynnissä. Sulje Näytönsäästäjän "
    L"asetukset ja yritä uudelleen.",
    L"Fjarlæging mistókst vegna þess að kerfisforskoðun er í gangi. Lokaðu stillingaglugga skjáhvílu og "
    L"reyndu aftur.",
    L"Avinstalleringen mislyktes fordi systemforhåndsvisningen kjører. Lukk vinduet "
    L"Skjermsparerinnstillinger og prøv på nytt.",
    L"Avinstallationen misslyckades eftersom systemförhandsvisningen körs. Stäng fönstret Inställningar för "
    L"skärmsläckare och försök igen.",
    L"Sistem önizlemesi çalıştığı için kaldırma başarısız oldu. Ekran Koruyucu Ayarları penceresini kapatıp "
    L"yeniden deneyin."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER_TEXTS = {
    L"Odinstalace se nezdařila, protože je spuštěný spořič nebo celoobrazovkový náhled. Ukončete jej "
    L"klávesou Esc nebo pohybem myši a odinstalaci zopakujte.",
    L"Uninstallation failed because the screen saver or full-screen preview is running. Exit it with Esc or "
    L"by moving the mouse, then try again.",
    L"Uninstallation failed because the screen saver or full-screen preview is running. Exit it with Esc or "
    L"by moving the mouse, then try again.",
    L"Uninstallation failed because the screen saver or full-screen preview is running. Exit it with Esc or "
    L"by moving the mouse, then try again.",
    L"Die Deinstallation ist fehlgeschlagen, weil der Bildschirmschoner oder die Vollbildvorschau läuft. "
    L"Beenden Sie ihn mit Esc oder durch Bewegen der Maus und versuchen Sie es erneut.",
    L"La désinstallation a échoué car l’économiseur ou l’aperçu plein écran est actif. Quittez-le avec "
    L"Échap "
    L"ou en déplaçant la souris, puis réessayez.",
    L"La desinstalación falló porque está activo el salvapantallas o la vista previa a pantalla completa. "
    L"Salga con Esc o moviendo el ratón e inténtelo de nuevo.",
    L"La disinstallazione non è riuscita perché è attivo il salvaschermo o l’anteprima a schermo intero. "
    L"Uscire con Esc o muovendo il mouse e riprovare.",
    L"A desinstalação falhou porque a proteção ou a pré-visualização em ecrã inteiro está em execução. Saia "
    L"com Esc ou movendo o rato e tente novamente.",
    L"Odinstalowanie nie powiodło się, ponieważ działa wygaszacz lub podgląd pełnoekranowy. Zakończ go "
    L"klawiszem Esc albo ruchem myszy i spróbuj ponownie.",
    L"Odinštalovanie zlyhalo, pretože beží šetrič alebo celoobrazovkový náhľad. Ukončite ho klávesom Esc "
    L"alebo pohybom myši a skúste to znova.",
    L"Afinstallationen mislykkedes, fordi pauseskærmen eller forhåndsvisningen i fuld skærm kører. Afslut "
    L"med Esc eller ved at bevæge musen, og prøv igen.",
    L"Asennuksen poisto epäonnistui, koska näytönsäästäjä tai koko näytön esikatselu on käynnissä. Lopeta "
    L"Esc-näppäimellä tai liikuttamalla hiirtä ja yritä uudelleen.",
    L"Fjarlæging mistókst vegna þess að skjáhvílan eða forskoðun á öllum skjánum er í gangi. Lokaðu með Esc "
    L"eða með því að hreyfa músina og reyndu aftur.",
    L"Avinstalleringen mislyktes fordi skjermspareren eller fullskjermvisningen kjører. Avslutt med Esc "
    L"eller ved å bevege musen, og prøv på nytt.",
    L"Avinstallationen misslyckades eftersom skärmsläckaren eller helskärmsförhandsvisningen körs. Avsluta "
    L"med Esc eller genom att röra musen och försök igen.",
    L"Ekran koruyucu veya tam ekran önizleme çalıştığı için kaldırma başarısız oldu. Esc ile ya da fareyi "
    L"hareket ettirerek çıkıp yeniden deneyin."
};

/// Warnings shown before closing an application that is currently recording.
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> RECORDING_CLOSE_WARNING_TEXTS = {
    L"Ukončení aplikace ukončí právě probíhající záznam.",
    L"Closing the application will stop the recording currently in progress.",
    L"Closing the application will stop the recording currently in progress.",
    L"Closing the application will stop the recording currently in progress.",
    L"Beim Beenden der Anwendung wird die laufende Aufnahme beendet.",
    L"La fermeture de l’application arrêtera l’enregistrement en cours.",
    L"Al cerrar la aplicación se detendrá la grabación en curso.",
    L"La chiusura dell’applicazione interromperà la registrazione in corso.",
    L"Fechar a aplicação irá terminar a gravação em curso.",
    L"Zamknięcie aplikacji zakończy trwające nagrywanie.",
    L"Ukončenie aplikácie ukončí práve prebiehajúci záznam.",
    L"Hvis du lukker programmet, stoppes den igangværende optagelse.",
    L"Sovelluksen sulkeminen lopettaa käynnissä olevan tallennuksen.",
    L"Ef forritinu er lokað stöðvast upptakan sem er í gangi.",
    L"Hvis du avslutter programmet, avsluttes opptaket som pågår.",
    L"Om du avslutar programmet stoppas den pågående inspelningen.",
    L"Uygulamayı kapatmak devam eden kaydı durduracaktır."
};

/// Recording-settings captions and presets shared with the Emulators interface.
constexpr std::array<RecordingText, LANGUAGE_COUNT> RECORDING_TEXTS = {
    RecordingText{
        L"Nastavení záznamu",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Rozlišení:",
        L"Snímková frekvence:",
        L"Změny se použijí při příštím záznamu MP4."
},
    RecordingText{
        L"Recording settings",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Resolution:",
        L"Frame rate:",
        L"Changes apply to the next MP4 recording."
},
    RecordingText{
        L"Recording settings",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Resolution:",
        L"Frame rate:",
        L"Changes apply to the next MP4 recording."
},
    RecordingText{
        L"Recording settings",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Resolution:",
        L"Frame rate:",
        L"Changes apply to the next MP4 recording."
},
    RecordingText{
        L"Aufnahmeeinstellungen",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Auflösung:",
        L"Bildfrequenz:",
        L"Änderungen gelten für die nächste MP4-Aufnahme."
},
    RecordingText{
        L"Réglages vidéo",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Résolution :",
        L"Fréquence d’images :",
        L"Les modifications s’appliquent au prochain enregistrement MP4."
},
    RecordingText{
        L"Ajustes de grabación",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Resolución:",
        L"Frecuencia de imagen:",
        L"Los cambios se aplican a la próxima grabación MP4."
},
    RecordingText{
        L"Impostazioni video",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Risoluzione:",
        L"Frequenza fotogrammi:",
        L"Le modifiche si applicano alla prossima registrazione MP4."
},
    RecordingText{
        L"Definições de gravação",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Resolução:",
        L"Frequência de imagens:",
        L"As alterações aplicam-se à próxima gravação MP4."
},
    RecordingText{
        L"Ustawienia nagrywania",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Rozdzielczość:",
        L"Liczba klatek/s:",
        L"Zmiany dotyczą następnego nagrania MP4."
},
    RecordingText{
        L"Nastavenie záznamu",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Rozlíšenie:",
        L"Snímková frekvencia:",
        L"Zmeny sa použijú pri nasledujúcom zázname MP4."
},
    RecordingText{
        L"Optagelsesindstillinger",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Opløsning:",
        L"Billedfrekvens:",
        L"Ændringerne gælder næste MP4-optagelse."
},
    RecordingText{
        L"Tallennusasetukset",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Tarkkuus:",
        L"Kuvataajuus:",
        L"Muutokset koskevat seuraavaa MP4-tallennusta."
},
    RecordingText{
        L"Upptökustillingar",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Upplausn:",
        L"Rammatíðni:",
        L"Breytingarnar gilda fyrir næstu MP4-upptöku."
},
    RecordingText{
        L"Opptaksinnstillinger",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Oppløsning:",
        L"Bildefrekvens:",
        L"Endringene gjelder neste MP4-opptak."
},
    RecordingText{
        L"Inspelningsinställningar",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Upplösning:",
        L"Bildfrekvens:",
        L"Ändringarna gäller nästa MP4-inspelning."
},
    RecordingText{
        L"Kayıt ayarları",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Çözünürlük:",
        L"Kare hızı:",
        L"Değişiklikler bir sonraki MP4 kaydına uygulanır."
}
};

constexpr std::array<const wchar_t*, 3> RECORDING_RESOLUTION_TEXTS = {
    L"1920 × 1080 (16:9)",
    L"1440 × 1080 (16:9)",
    L"1280 × 720 (16:9)"
};

constexpr std::array<const wchar_t*, 4> RECORDING_RATE_TEXTS = {
    L"50 Hz",
    L"25 Hz",
    L"59.94 Hz (60000/1001)",
    L"29.97 Hz (30000/1001)"
};

/// Help and About text
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> APPLICATION_HELP_TEXTS = {
    L"FlightCorridor nabízí Průlet čtyřmi proměnlivými plochami a Průlet proměnlivým trychtýřem. "
    L"Každému monitoru přiřadíte právě jeden průlet: označte jeho řádek v seznamu a zvolte příslušný "
    L"přepínač. Ve výchozím stavu je na všech monitorech zvolena první animace. Výchozí je zobrazení "
    L"s texturou; zrušením volby Textura přepnete vybrané monitory na drátěný model. Při označení "
    L"více řádků se volba použije pro všechny označené monitory. Jezdec nastavuje rychlost animace v "
    L"rozsahu 0–1600 %. EXE výchozím spuštěním zapne pouze primární animační monitor, spořič všechny "
    L"monitory. Každý monitor se vykresluje podle vlastní obnovovací frekvence. Nastavení se ukládá "
    L"zvlášť pro aplikaci a spořič obrazovky. Volba Převalování kamery zapne na označených monitorech "
    L"plynulé otáčení pohledu do všech směrů; ve výchozím stavu je vypnutá. Volba Zastavování a změny "
    L"směru přidá v náhodných intervalech plynulé brzdění převalování kamery, krátké zastavení a "
    L"rozběh opačným směrem. Je dostupná při zapnutém převalování a ve výchozím stavu je vypnutá; "
    L"samotný průlet pokračuje.\r\n\r\nV seznamu lze označit více monitorů; dvojklikem na řádek monitor "
    L"zapnete nebo vypnete a lze zrušit i výběr všech monitorů. Každý monitor používá nezávislou "
    L"scénu. Snímek ukládá PNG, tlačítko záznamu spouští a ukončuje MP4. Pozastavení zastaví animaci. "
    L"Aplikace také instaluje nebo odinstaluje zabalený spořič. Nastavení se ukládá průběžně. Aplikace běží "
    L"pouze v jedné instanci. Další spuštění obnoví minimalizované ovládací okno a přenese do popředí. Mezi "
    L"ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a "
    L"příslušného písmene. Esc zavře aktivní nápovědu či okno O aplikaci; v ovládacím okně ukončí aplikaci. "
    L"Volba Blokovat spořič při animaci brání spuštění spořiče Windows pouze tehdy, když je animace "
    L"skutečně viditelná a není pozastavená.\r\n\r\nSnímek a záznam zachycují první aktivní animační "
    L"monitor, nikoli společnou plochu všech monitorů. PNG používá složku Obrázky, MP4 složku Videa; při "
    L"jejich neexistenci se použijí Dokumenty. Tlačítko Nastavení záznamu vybírá Viewport nebo TV. Viewport "
    L"zachovává rozměry animačního monitoru a jeho obnovovací frekvenci, nejvýše 60 snímků za sekundu. TV "
    L"nabízí rozlišení 1920 × 1080, 1440 × 1080 nebo 1280 × 720 v poměru 16:9 a frekvenci 50, 25, 59.94 "
    L"(60000/1001) nebo 29.97 (30000/1001) snímků za sekundu. Obraz zachovává poměr stran; TV používá "
    L"progresivní video BT.709 s omezeným rozsahem a vzorkováním 4:2:0. Rozlišení a snímkovou frekvenci lze "
    L"vybrat pouze v režimu TV. Okno Nastavení záznamu lze minimalizovat a neblokuje ostatní okna aplikace. "
    L"OK uloží volby pro příští záznam MP4; Storno nebo Esc nepotvrzené změny zahodí. Nahrávaný monitor "
    L"nelze během záznamu odepnout; změny ostatních monitorů záznam nezastaví. Ukončení aplikace při "
    L"probíhajícím záznamu vyžaduje potvrzení, protože současně ukončí záznam.\r\n\r\nWindows 7 až Windows "
    L"11 podporují všechny funkce včetně snímků PNG a záznamu MP4. Pro spuštění aplikace ve Windows Vista "
    L"SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917. Záznam MP4 na Vistě v současné verzi "
    L"nefunguje.",
    L"FlightCorridor offers Flight between four morphing surfaces and Flight through a morphing funnel. "
    L"Assign exactly one flight to each display: select its row in the list and choose the corresponding "
    L"radio button. The first animation is selected on every display by default. Textured rendering is the "
    L"default; clear Texture to switch the selected displays to wireframe. With several rows selected, the "
    L"choice applies to every selected display. The slider sets animation speed from 0–1600%. On default "
    L"startup, EXE enables only the primary animation display; the screen saver enables all displays. Each "
    L"display renders at its own refresh rate. Settings are stored separately for the application and "
    L"screen saver. Camera tumbling enables smooth rotation of the view in all directions on the selected "
    L"displays; it is off by default. Stops and reversals adds gradual braking, brief pauses and reversal "
    L"of camera tumbling at random intervals. It is available when Camera tumbling is enabled and is off by "
    L"default; forward flight continues.\r\n\r\nSelect several displays in the list; double-click a row to "
    L"toggle it, or clear the selection for all displays. Every display uses an independent scene. Snapshot "
    L"saves a PNG and the recording button starts or stops an MP4. Pause stops the animation. The "
    L"application also installs or uninstalls its embedded screen saver. Settings are saved continuously. "
    L"Only one instance of the application runs at a time. Launching it again restores its minimized "
    L"control window and brings it to the foreground. Use Tab and Shift+Tab to move between controls; use "
    L"Alt and the underlined letter to activate a command. Esc closes the active Help or About window; in "
    L"the control window, it exits the application. Prevent screen saver during animation blocks the "
    L"Windows screen saver only while the animation is actually visible and not paused.\r\n\r\nSnapshots "
    L"and recordings capture the first active animation display, not a combined image of all displays. PNG "
    L"uses Pictures and MP4 uses Videos, with Documents as the fallback if those folders do not exist. The "
    L"Recording settings button selects Viewport or TV. Viewport preserves the animation display’s "
    L"dimensions and refresh rate, up to 60 frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × "
    L"720 output in 16:9, with 50, 25, 59.94 (60000/1001) or 29.97 (30000/1001) frames per second. The "
    L"image keeps its aspect ratio; TV uses progressive BT.709 limited-range 4:2:0 video. Resolution and "
    L"frame rate are available only in TV mode. The Recording settings window can be minimized and does not "
    L"block the other application windows. OK saves choices for the next MP4 recording; Cancel or Esc "
    L"discards unconfirmed changes. The recorded display cannot be detached during recording; changes to "
    L"other displays do not stop the recording. Closing the application while recording requires "
    L"confirmation because it also stops the recording.\r\n\r\nWindows 7 through Windows 11 support all "
    L"features, including PNG snapshots and MP4 recording. To run the application on Windows Vista SP2, you "
    L"must install updates KB971512 and KB2117917. MP4 recording does not work on Vista in the current "
    L"version.",
    L"FlightCorridor offers Flight between four morphing surfaces and Flight through a morphing funnel. "
    L"Assign exactly one flight to each display: select its row in the list and choose the corresponding "
    L"radio button. The first animation is selected on every display by default. Textured rendering is the "
    L"default; clear Texture to switch the selected displays to wireframe. With several rows selected, the "
    L"choice applies to every selected display. The slider sets animation speed from 0–1600%. On default "
    L"startup, EXE enables only the primary animation display; the screen saver enables all displays. Each "
    L"display renders at its own refresh rate. Settings are stored separately for the application and "
    L"screen saver. Camera tumbling enables smooth rotation of the view in all directions on the selected "
    L"displays; it is off by default. Stops and reversals adds gradual braking, brief pauses and reversal "
    L"of camera tumbling at random intervals. It is available when Camera tumbling is enabled and is off by "
    L"default; forward flight continues.\r\n\r\nSelect several displays; double-click a row to toggle it, or "
    L"clear the selection for all displays. Each display uses an independent scene. Snapshot saves PNG and "
    L"the recording button starts or stops MP4. Pause stops the animation. The application also installs or "
    L"uninstalls its embedded screen saver. Settings are saved continuously. Only one instance of the "
    L"application runs at a time. Launching it again restores its minimised control window and brings it to "
    L"the foreground. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to "
    L"activate a command. Esc closes the active Help or About window; in the control window, it exits the "
    L"application. Prevent screen saver during animation blocks the Windows screen saver only while the "
    L"animation is actually visible and not paused.\r\n\r\nSnapshots and recordings capture the first "
    L"active animation display, not a combined image of all displays. PNG uses Pictures and MP4 uses "
    L"Videos, with Documents as the fallback if those folders do not exist. The Recording settings button "
    L"selects Viewport or TV. Viewport preserves the animation display’s dimensions and refresh rate, up to "
    L"60 frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, "
    L"59.94 (60000/1001) or 29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV uses "
    L"progressive BT.709 limited-range 4:2:0 video. Resolution and frame rate are available only in TV "
    L"mode. The Recording settings window can be minimised and does not block the other application "
    L"windows. OK saves choices for the next MP4 recording; Cancel or Esc discards unconfirmed changes. The "
    L"recorded display cannot be detached during recording; changes to other displays do not stop the "
    L"recording. Closing the application while recording requires confirmation because it also stops the "
    L"recording.\r\n\r\nWindows 7 through Windows 11 support all features, including PNG snapshots and MP4 "
    L"recording. To run the application on Windows Vista SP2, you must install updates KB971512 and "
    L"KB2117917. MP4 recording does not work on Vista in the current version.",
    L"FlightCorridor offers Flight between four morphing surfaces and Flight through a morphing funnel. "
    L"Assign exactly one flight to each display: select its row in the list and choose the corresponding "
    L"radio button. The first animation is selected on every display by default. Textured rendering is the "
    L"default; clear Texture to switch the selected displays to wireframe. With several rows selected, the "
    L"choice applies to every selected display. The slider sets animation speed from 0–1600%. On default "
    L"startup, EXE enables only the primary animation display; the screen saver enables all displays. Each "
    L"display renders at its own refresh rate. Settings are stored separately for the application and "
    L"screen saver. Camera tumbling enables smooth rotation of the view in all directions on the selected "
    L"displays; it is off by default. Stops and reversals adds gradual braking, brief pauses and reversal "
    L"of camera tumbling at random intervals. It is available when Camera tumbling is enabled and is off by "
    L"default; forward flight continues.\r\n\r\nSelect several displays; double-click a row to toggle it, or "
    L"clear the selection for all displays. Each display uses an independent scene. Snapshot saves PNG and "
    L"the recording button starts or stops MP4. Pause stops the animation. The application also installs or "
    L"uninstalls its embedded screen saver. Settings are saved continuously. Only one instance of the "
    L"application runs at a time. Launching it again restores its minimised control window and brings it to "
    L"the foreground. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to "
    L"activate a command. Esc closes the active Help or About window; in the control window, it exits the "
    L"application. Prevent screen saver during animation blocks the Windows screen saver only while the "
    L"animation is actually visible and not paused.\r\n\r\nSnapshots and recordings capture the first "
    L"active animation display, not a combined image of all displays. PNG uses Pictures and MP4 uses "
    L"Videos, with Documents as the fallback if those folders do not exist. The Recording settings button "
    L"selects Viewport or TV. Viewport preserves the animation display’s dimensions and refresh rate, up to "
    L"60 frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, "
    L"59.94 (60000/1001) or 29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV uses "
    L"progressive BT.709 limited-range 4:2:0 video. Resolution and frame rate are available only in TV "
    L"mode. The Recording settings window can be minimised and does not block the other application "
    L"windows. OK saves choices for the next MP4 recording; Cancel or Esc discards unconfirmed changes. The "
    L"recorded display cannot be detached during recording; changes to other displays do not stop the "
    L"recording. Closing the application while recording requires confirmation because it also stops the "
    L"recording.\r\n\r\nWindows 7 through Windows 11 support all features, including PNG snapshots and MP4 "
    L"recording. To run the application on Windows Vista SP2, you must install updates KB971512 and "
    L"KB2117917. MP4 recording does not work on Vista in the current version.",
    L"FlightCorridor bietet Flug zwischen vier veränderlichen Flächen und Flug durch einen veränderlichen "
    L"Trichter. Weisen Sie jedem Monitor genau einen Flug zu: Markieren Sie seine Zeile und wählen Sie "
    L"den entsprechenden Optionsschalter. Standardmäßig ist auf allen Monitoren die erste Animation "
    L"ausgewählt. Die Textur ist standardmäßig aktiviert; deaktivieren Sie Textur, um die ausgewählten "
    L"Monitore auf Drahtgittermodelle umzuschalten. Bei mehreren markierten Zeilen gilt die Auswahl "
    L"für alle markierten Monitore. Der Regler bestimmt die Animationsgeschwindigkeit von 0–1600 %. "
    L"Beim Standardstart aktiviert EXE nur den primären Animationsmonitor, der Bildschirmschoner alle "
    L"Monitore. Jeder Monitor wird mit seiner eigenen Bildwiederholfrequenz gerendert. Die Einstellungen "
    L"werden für Anwendung und Bildschirmschoner getrennt gespeichert. Taumelnde Kamera aktiviert auf "
    L"den markierten Monitoren eine gleichmäßige Drehung des Blicks in alle Richtungen; standardmäßig "
    L"ist die Option deaktiviert. Stopps und Richtungswechsel bremst die Kameradrehung in zufälligen "
    L"Abständen sanft ab, hält sie kurz an und setzt sie in umgekehrter Richtung fort. Die Option ist "
    L"bei aktivierter taumelnder Kamera verfügbar und standardmäßig deaktiviert; der Vorwärtsflug "
    L"geht weiter.\r\n\r\nIn der Liste sind mehrere Monitore wählbar; ein Doppelklick schaltet einen "
    L"Monitor um, auch alle können abgewählt werden. Jeder Monitor besitzt eine unabhängige Szene. "
    L"Schnappschuss speichert PNG, die Aufnahmetaste startet oder beendet MP4. Pause hält die Animation an. "
    L"Die Anwendung installiert oder deinstalliert außerdem den eingebetteten Bildschirmschoner. "
    L"Einstellungen werden laufend gespeichert. Die Anwendung läuft nur in einer Instanz. Ein erneuter "
    L"Start stellt das minimierte Steuerfenster wieder her und bringt es in den Vordergrund. Mit Tab und "
    L"Umschalt+Tab wechseln Sie zwischen den Steuerelementen; mit Alt und dem unterstrichenen Buchstaben "
    L"rufen Sie einen Befehl auf. Esc schließt das aktive Hilfe- oder Infofenster; im Steuerfenster beendet "
    L"es die Anwendung. Bildschirmschoner bei Animation sperren verhindert den Start des "
    L"Windows-Bildschirmschoners nur, solange die Animation tatsächlich sichtbar und nicht angehalten "
    L"ist.\r\n\r\nSchnappschüsse und Aufnahmen erfassen den ersten aktiven Animationsmonitor, nicht die "
    L"gemeinsame Fläche aller Monitore. PNG verwendet Bilder, MP4 Videos; fehlen diese Ordner, wird "
    L"Dokumente verwendet. Die Schaltfläche Aufnahmeeinstellungen wählt Viewport oder TV. Viewport erhält "
    L"die Abmessungen und Bildwiederholfrequenz des Animationsmonitors bis höchstens 60 Bilder pro Sekunde. "
    L"TV bietet 1920 × 1080, 1440 × 1080 oder 1280 × 720 im Format 16:9 mit 50, 25, 59.94 (60000/1001) oder "
    L"29.97 (30000/1001) Bildern pro Sekunde. Das Seitenverhältnis bleibt erhalten; TV verwendet "
    L"progressives BT.709-Video mit begrenztem Wertebereich und 4:2:0-Abtastung. Auflösung und Bildfrequenz "
    L"sind nur im TV-Modus wählbar. Das Fenster Aufnahmeeinstellungen lässt sich minimieren und blockiert "
    L"die anderen Anwendungsfenster nicht. OK speichert die Auswahl für die nächste MP4-Aufnahme; Abbrechen "
    L"oder Esc verwirft unbestätigte Änderungen. Der aufgezeichnete Monitor kann während der Aufnahme nicht "
    L"abgewählt werden; Änderungen an anderen Monitoren beenden die Aufnahme nicht. Das Beenden der "
    L"Anwendung während einer Aufnahme muss bestätigt werden, da es auch die Aufnahme "
    L"beendet.\r\n\r\nWindows 7 bis Windows 11 unterstützen alle Funktionen einschließlich "
    L"PNG-Schnappschüssen und MP4-Aufnahmen. Zum Ausführen der Anwendung unter Windows Vista SP2 müssen die "
    L"Updates KB971512 und KB2117917 installiert werden. MP4-Aufnahmen funktionieren unter Vista in der "
    L"aktuellen Version nicht.",
    L"FlightCorridor propose Vol entre quatre surfaces déformables et Vol dans un entonnoir déformable. "
    L"Attribuez un seul vol à chaque moniteur : sélectionnez sa ligne, puis le bouton radio correspondant. "
    L"Par défaut, la première animation est sélectionnée sur tous les moniteurs. La texture est activée "
    L"par défaut ; décochez Texture pour afficher les moniteurs sélectionnés en mode filaire. Si "
    L"plusieurs lignes sont sélectionnées, le choix s’applique à tous ces moniteurs. Le curseur règle la "
    L"vitesse de l’animation de 0 à 1 600 %. Au démarrage par défaut, EXE active uniquement le moniteur "
    L"d’animation principal, tandis que l’économiseur active tous les moniteurs. Chaque moniteur est "
    L"rendu à sa propre fréquence de rafraîchissement. Les réglages sont enregistrés séparément pour "
    L"l’application et l’économiseur d’écran. Rotation libre de la caméra active une rotation fluide du "
    L"regard dans toutes les directions sur les moniteurs sélectionnés ; cette option est désactivée "
    L"par défaut. Arrêts et changements de sens ralentit progressivement la rotation de la caméra à "
    L"intervalles aléatoires, la suspend brièvement, puis la relance en sens inverse. Cette option est "
    L"disponible lorsque la rotation libre de la caméra est activée et est désactivée par défaut ; le vol "
    L"continue.\r\n\r\nSélectionnez plusieurs moniteurs dans la liste ; un double-clic active ou désactive "
    L"un moniteur, et vous pouvez tous les désélectionner. Chaque moniteur utilise une scène indépendante. "
    L"Capture enregistre un PNG et le bouton d’enregistrement démarre ou arrête un MP4. Pause arrête "
    L"l’animation. L’application installe ou désinstalle aussi son économiseur intégré. Les réglages sont "
    L"enregistrés en continu. Une seule instance de l’application peut fonctionner à la fois. Un nouveau "
    L"lancement restaure la fenêtre de contrôle réduite et la place au premier plan. Utilisez Tab et "
    L"Maj+Tab pour passer d’un contrôle à l’autre ; Alt et la lettre soulignée activent une commande. Échap "
    L"ferme la fenêtre d’aide ou À propos active ; dans la fenêtre de contrôle, cette touche quitte "
    L"l’application. Bloquer l’écran de veille pendant l’animation empêche le lancement de l’économiseur "
    L"d’écran Windows uniquement lorsque l’animation est réellement visible et n’est pas en "
    L"pause.\r\n\r\nLes captures et les enregistrements utilisent le premier moniteur d’animation actif, et "
    L"non une image combinant tous les moniteurs. PNG utilise Images, MP4 Vidéos ; Documents sert de repli "
    L"si ces dossiers n’existent pas. Le bouton Réglages vidéo permet de choisir Viewport ou TV. Viewport "
    L"conserve les dimensions et la fréquence de rafraîchissement du moniteur d’animation, jusqu’à 60 "
    L"images par seconde. TV propose 1920 × 1080, 1440 × 1080 ou 1280 × 720 au format 16:9, à 50, 25, 59.94 "
    L"(60000/1001) ou 29.97 (30000/1001) images par seconde. Le rapport d’aspect est conservé ; TV utilise "
    L"une vidéo progressive BT.709 à plage limitée et sous-échantillonnage 4:2:0. La résolution et la "
    L"fréquence d’images ne sont disponibles qu’en mode TV. La fenêtre Réglages vidéo peut être réduite et "
    L"ne bloque pas les autres fenêtres de l’application. OK enregistre les choix pour le prochain "
    L"enregistrement MP4 ; Annuler ou Échap abandonne les modifications non confirmées. Le moniteur "
    L"enregistré ne peut pas être désélectionné pendant l’enregistrement ; les changements concernant les "
    L"autres moniteurs ne l’arrêtent pas. Fermer l’application pendant un enregistrement nécessite une "
    L"confirmation, car cela arrête aussi l’enregistrement.\r\n\r\nWindows 7 à Windows 11 prennent en "
    L"charge toutes les fonctions, y compris les captures PNG et l’enregistrement MP4. Pour exécuter "
    L"l’application sous Windows Vista SP2, il est nécessaire d’installer les mises à jour KB971512 et "
    L"KB2117917. L’enregistrement MP4 ne fonctionne pas sous Vista dans la version actuelle.",
    L"FlightCorridor ofrece Vuelo entre cuatro superficies deformables y Vuelo por un embudo deformable. "
    L"Asigne exactamente un vuelo a cada monitor: seleccione su fila y el botón de opción correspondiente. "
    L"La primera animación está seleccionada de forma predeterminada en todos los monitores. La textura "
    L"está activada de forma predeterminada; desmarque Textura para mostrar los monitores seleccionados "
    L"en modo de alambre. Si selecciona varias filas, la opción se aplica a todos esos monitores. El "
    L"deslizador ajusta la velocidad de animación entre 0 y 1600 %. En el inicio predeterminado, EXE "
    L"activa solo el monitor de animación principal; el protector activa todos los monitores. Cada "
    L"monitor se dibuja a su propia frecuencia de actualización. Los ajustes se guardan por separado "
    L"para la aplicación y el protector de pantalla. Giro libre de la cámara activa una rotación "
    L"suave de la vista en todas las direcciones en los monitores seleccionados; está desactivado de "
    L"forma predeterminada. Paradas y cambios de sentido frena gradualmente el giro de la cámara a "
    L"intervalos aleatorios, lo detiene brevemente y lo reanuda en sentido contrario. La opción está "
    L"disponible con el giro libre de la cámara activado y está desactivada por defecto; el vuelo "
    L"continúa.\r\n\r\nSeleccione varios monitores en la lista; un doble clic alterna la animación en "
    L"un monitor y también puede desmarcarlos todos. Cada monitor usa una escena independiente. Captura "
    L"guarda un PNG y el botón de grabación inicia o detiene un MP4. Pausar detiene la animación. La "
    L"aplicación instala o desinstala además el salvapantallas incorporado. Los ajustes se guardan "
    L"continuamente. La aplicación solo permite una instancia. Al volver a iniciarla, restaura la ventana "
    L"de control minimizada y la trae al primer plano. Use Tab y Mayús+Tab para desplazarse entre "
    L"controles; Alt y la letra subrayada activan una opción. Esc cierra la ventana activa de Ayuda o "
    L"Acerca de; en la ventana de control, sale de la aplicación. Bloquear salvapantallas durante la "
    L"animación impide que se inicie el salvapantallas de Windows solo mientras la animación está realmente "
    L"visible y no está en pausa.\r\n\r\nLas capturas y grabaciones usan el primer monitor de animación "
    L"activo, no una imagen conjunta de todos los monitores. PNG usa Imágenes y MP4 Vídeos; si no existen "
    L"esas carpetas, se usa Documentos. El botón Ajustes de grabación permite elegir Viewport o TV. "
    L"Viewport conserva las dimensiones y la frecuencia de actualización del monitor de animación, hasta 60 "
    L"fotogramas por segundo. TV ofrece 1920 × 1080, 1440 × 1080 o 1280 × 720 en formato 16:9, a 50, 25, "
    L"59.94 (60000/1001) o 29.97 (30000/1001) fotogramas por segundo. Se conserva la relación de aspecto; "
    L"TV usa vídeo progresivo BT.709 de rango limitado y submuestreo 4:2:0. La resolución y la frecuencia "
    L"solo están disponibles en modo TV. La ventana Ajustes de grabación se puede minimizar y no bloquea "
    L"las demás ventanas de la aplicación. Aceptar guarda las opciones para la próxima grabación MP4; "
    L"Cancelar o Esc descarta los cambios sin confirmar. El monitor grabado no se puede desmarcar durante "
    L"la grabación; cambiar otros monitores no la detiene. Cerrar la aplicación durante una grabación "
    L"requiere confirmación porque también detiene la grabación.\r\n\r\nWindows 7 a Windows 11 admiten "
    L"todas las funciones, incluidas las capturas PNG y la grabación MP4. Para ejecutar la aplicación en "
    L"Windows Vista SP2, es necesario instalar las actualizaciones KB971512 y KB2117917. La grabación MP4 "
    L"no funciona en Vista en la versión actual.",
    L"FlightCorridor offre Volo tra quattro superfici deformabili e Volo attraverso un imbuto "
    L"deformabile. Assegnare un solo volo a ogni monitor: selezionare la sua riga e il pulsante di "
    L"opzione corrispondente. La prima animazione è selezionata per impostazione predefinita su tutti "
    L"i monitor. La texture è attiva per impostazione predefinita; deselezionare Texture per mostrare "
    L"i monitor selezionati a reticolo. Se sono selezionate più righe, la scelta vale per tutti quei "
    L"monitor. Il cursore imposta la velocità dell’animazione da 0 a 1600 %. All’avvio predefinito, EXE "
    L"attiva solo il monitor di animazione principale, mentre il salvaschermo attiva tutti i monitor. "
    L"Ogni monitor viene disegnato alla propria frequenza di aggiornamento. Le impostazioni sono salvate "
    L"separatamente per l’applicazione e il salvaschermo. Rotazione libera della telecamera attiva "
    L"una rotazione fluida della vista in tutte le direzioni sui monitor selezionati; è disattivata "
    L"per impostazione predefinita. Arresti e inversioni rallenta gradualmente la rotazione della "
    L"telecamera a intervalli casuali, la ferma brevemente e la riavvia in senso opposto. L’opzione è "
    L"disponibile con la rotazione libera attiva ed è disattivata per impostazione predefinita; il volo "
    L"continua.\r\n\r\nNell’elenco si possono selezionare più monitor; un doppio clic attiva o disattiva "
    L"l’animazione su un monitor, ed è possibile deselezionarli tutti. Ogni monitor usa una scena "
    L"indipendente. Istantanea salva un PNG e il pulsante di registrazione avvia o arresta un MP4. Pausa "
    L"ferma l’animazione. L’applicazione installa o disinstalla anche il salvaschermo incorporato. Le "
    L"impostazioni vengono salvate continuamente. L’applicazione può essere eseguita in una sola istanza. "
    L"Un nuovo avvio ripristina la finestra di controllo ridotta a icona e la porta in primo piano. Usare "
    L"Tab e Maiusc+Tab per passare tra i controlli; Alt e la lettera sottolineata attivano un comando. Esc "
    L"chiude la finestra attiva di Guida o Informazioni; nella finestra di controllo, termina "
    L"l’applicazione. Blocca salvaschermo durante l’animazione impedisce l’avvio del salvaschermo di "
    L"Windows solo quando l’animazione è realmente visibile e non è in pausa.\r\n\r\nIstantanee e "
    L"registrazioni usano il primo monitor di animazione attivo, non un’immagine combinata di tutti i "
    L"monitor. PNG usa Immagini, MP4 Video; se tali cartelle non esistono, viene usata Documenti. Il "
    L"pulsante Impostazioni video permette di scegliere Viewport o TV. Viewport mantiene le dimensioni e la "
    L"frequenza di aggiornamento del monitor di animazione, fino a 60 fotogrammi al secondo. TV offre 1920 "
    L"× 1080, 1440 × 1080 o 1280 × 720 in formato 16:9, a 50, 25, 59.94 (60000/1001) o 29.97 (30000/1001) "
    L"fotogrammi al secondo. Le proporzioni sono mantenute; TV usa video progressivo BT.709 con intervallo "
    L"limitato e campionamento 4:2:0. Risoluzione e frequenza sono disponibili solo in modalità TV. La "
    L"finestra Impostazioni video può essere ridotta a icona e non blocca le altre finestre "
    L"dell’applicazione. OK salva le opzioni per la prossima registrazione MP4; Annulla o Esc scarta le "
    L"modifiche non confermate. Il monitor registrato non può essere deselezionato durante la "
    L"registrazione; le modifiche agli altri monitor non la interrompono. Chiudere l’applicazione durante "
    L"una registrazione richiede conferma, perché interrompe anche la registrazione.\r\n\r\nI sistemi da "
    L"Windows 7 a Windows 11 supportano tutte le funzioni, comprese le istantanee PNG e la registrazione "
    L"MP4. Per eseguire l’applicazione su Windows Vista SP2, è necessario installare gli aggiornamenti "
    L"KB971512 e KB2117917. La registrazione MP4 non funziona in Vista nella versione attuale.",
    L"O FlightCorridor oferece Voo entre quatro superfícies deformáveis e Voo através de um funil "
    L"deformável. Atribua um único voo a cada monitor: selecione a respetiva linha e o botão de opção "
    L"correspondente. Por predefinição, a primeira animação está selecionada em todos os monitores. A "
    L"textura está ativa por predefinição; desmarque Textura para mostrar os monitores selecionados em "
    L"modelo de arame. Com várias linhas selecionadas, a escolha aplica-se a todos esses monitores. O "
    L"controlo deslizante define a velocidade da animação entre 0 e 1600 %. No arranque predefinido, "
    L"EXE ativa apenas o monitor de animação principal, enquanto a proteção de ecrã ativa todos os "
    L"monitores. Cada monitor é desenhado à sua própria frequência de atualização. As definições são "
    L"guardadas separadamente para a aplicação e a proteção de ecrã. Rotação livre da câmara ativa "
    L"uma rotação suave da vista em todas as direções nos monitores selecionados; está desativada "
    L"por predefinição. Paragens e inversões de sentido abranda gradualmente a rotação da câmara "
    L"em intervalos aleatórios, interrompe-a brevemente e retoma-a no sentido oposto. A opção está "
    L"disponível com a rotação livre da câmara ativa e está desativada por predefinição; o voo "
    L"continua.\r\n\r\nSelecione vários monitores; um duplo clique alterna uma linha e todos podem ser "
    L"desmarcados. Cada monitor usa uma cena independente. Captura guarda PNG e o botão de gravação inicia "
    L"ou termina MP4. Pausa para a animação. A aplicação também instala ou desinstala a proteção de ecrã "
    L"incorporada. As definições são guardadas continuamente. A aplicação só pode ter uma instância em "
    L"execução. Um novo arranque restaura a janela de controlo minimizada e coloca-a em primeiro plano. Use "
    L"Tab e Shift+Tab para passar entre controlos; Alt e a letra sublinhada ativam um comando. Esc fecha a "
    L"janela ativa de Ajuda ou Acerca de; na janela de controlo, termina a aplicação. Bloquear proteção de "
    L"ecrã durante a animação impede o início da proteção de ecrã do Windows apenas enquanto a animação "
    L"está efetivamente visível e não está em pausa.\r\n\r\nAs capturas e gravações usam o primeiro monitor "
    L"de animação ativo, não uma imagem conjunta de todos os monitores. PNG usa Imagens, MP4 Vídeos; se "
    L"essas pastas não existirem, usa-se Documentos. O botão Definições de gravação permite escolher "
    L"Viewport ou TV. Viewport conserva as dimensões e a frequência de atualização do monitor de animação, "
    L"até 60 fotogramas por segundo. TV oferece 1920 × 1080, 1440 × 1080 ou 1280 × 720 no formato 16:9, a "
    L"50, 25, 59.94 (60000/1001) ou 29.97 (30000/1001) fotogramas por segundo. A proporção da imagem é "
    L"mantida; TV usa vídeo progressivo BT.709 com intervalo limitado e amostragem 4:2:0. A resolução e a "
    L"frequência só estão disponíveis no modo TV. A janela Definições de gravação pode ser minimizada e não "
    L"bloqueia as outras janelas da aplicação. OK guarda as escolhas para a próxima gravação MP4; Cancelar "
    L"ou Esc descarta as alterações não confirmadas. O monitor gravado não pode ser desmarcado durante a "
    L"gravação; as alterações aos outros monitores não a interrompem. Fechar a aplicação durante uma "
    L"gravação exige confirmação, pois também termina a gravação.\r\n\r\nOs sistemas Windows 7 a Windows 11 "
    L"suportam todas as funcionalidades, incluindo capturas PNG e gravação MP4. Para executar a aplicação "
    L"no Windows Vista SP2, é necessário instalar as atualizações KB971512 e KB2117917. A gravação MP4 não "
    L"funciona no Vista na versão atual.",
    L"FlightCorridor oferuje Przelot między czterema zmiennymi powierzchniami i Przelot przez zmienny "
    L"lejek. Każdemu monitorowi przypisz dokładnie jeden przelot: zaznacz jego wiersz i odpowiedni przycisk "
    L"opcji. Domyślnie na wszystkich monitorach wybrana jest pierwsza animacja. Tekstura jest domyślnie "
    L"włączona; wyłącz Tekstura, aby wybrane monitory wyświetlały model siatkowy. Przy zaznaczeniu kilku "
    L"wierszy wybór dotyczy wszystkich tych monitorów. Suwak ustawia prędkość animacji w zakresie 0–1600 "
    L"%. Przy domyślnym uruchomieniu EXE włącza tylko główny monitor animacji, a wygaszacz wszystkie "
    L"monitory. Każdy monitor jest renderowany z własną częstotliwością odświeżania. Ustawienia są "
    L"zapisywane osobno dla aplikacji i wygaszacza ekranu. Swobodne obracanie kamery włącza płynne "
    L"obracanie widoku we wszystkich kierunkach na zaznaczonych monitorach; domyślnie jest wyłączone. "
    L"Zatrzymania i zmiany kierunku stopniowo wyhamowuje obrót kamery w losowych odstępach, na krótko "
    L"go zatrzymuje, a następnie wznawia w przeciwnym kierunku. Opcja jest dostępna przy włączonym "
    L"swobodnym obracaniu kamery i domyślnie jest wyłączona; lot trwa nadal.\r\n\r\nNa liście można "
    L"zaznaczyć wiele monitorów; podwójne kliknięcie przełącza animację na monitorze, można też odznaczyć "
    L"wszystkie. Każdy monitor ma niezależną scenę. Zrzut zapisuje PNG, a przycisk nagrywania rozpoczyna "
    L"lub kończy MP4. Wstrzymaj zatrzymuje animację. Aplikacja instaluje i odinstalowuje również wbudowany "
    L"wygaszacz. Ustawienia są zapisywane na bieżąco. Aplikacja działa tylko w jednej instancji. Kolejne "
    L"uruchomienie przywraca zminimalizowane okno sterowania i przenosi na pierwszy plan. Klawisze Tab i "
    L"Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera wywołują polecenie. Esc zamyka "
    L"aktywne okno Pomocy lub O programie; w oknie sterowania kończy działanie aplikacji. Blokuj wygaszacz "
    L"podczas animacji zapobiega uruchomieniu wygaszacza Windows tylko wtedy, gdy animacja jest "
    L"rzeczywiście widoczna i nie jest wstrzymana.\r\n\r\nZrzuty i nagrania obejmują pierwszy aktywny "
    L"monitor animacji, a nie wspólny obraz wszystkich monitorów. PNG używa folderu Obrazy, MP4 folderu "
    L"Wideo; jeśli ich nie ma, używane są Dokumenty. Przycisk Ustawienia nagrywania pozwala wybrać Viewport "
    L"lub TV. Viewport zachowuje rozmiar i częstotliwość odświeżania monitora animacji, do 60 klatek na "
    L"sekundę. TV oferuje 1920 × 1080, 1440 × 1080 lub 1280 × 720 w formacie 16:9, z 50, 25, 59.94 "
    L"(60000/1001) lub 29.97 (30000/1001) klatkami na sekundę. Proporcje obrazu są zachowane; TV używa "
    L"progresywnego obrazu BT.709 z ograniczonym zakresem i próbkowaniem 4:2:0. Rozdzielczość i liczba "
    L"klatek są dostępne tylko w trybie TV. Okno Ustawienia nagrywania można zminimalizować i nie blokuje "
    L"ono innych okien aplikacji. OK zapisuje wybór dla następnego nagrania MP4; Anuluj lub Esc odrzuca "
    L"niepotwierdzone zmiany. Podczas nagrywania nie można odznaczyć nagrywanego monitora; zmiany "
    L"pozostałych monitorów nie przerywają nagrania. Zamknięcie aplikacji podczas nagrywania wymaga "
    L"potwierdzenia, ponieważ kończy również nagranie.\r\n\r\nSystemy od Windows 7 do Windows 11 obsługują "
    L"wszystkie funkcje, w tym zrzuty PNG i nagrywanie MP4. Do uruchomienia aplikacji w systemie Windows "
    L"Vista SP2 konieczne jest zainstalowanie aktualizacji KB971512 i KB2117917. Nagrywanie MP4 nie działa "
    L"w Vista w obecnej wersji.",
    L"FlightCorridor ponúka Prelet štyrmi premenlivými plochami a Prelet premenlivým lievikom. Každému "
    L"monitoru priradíte práve jeden prelet: označte jeho riadok v zozname a zvoľte príslušný prepínač. "
    L"V predvolenom stave je na všetkých monitoroch zvolená prvá animácia. Predvolené je zobrazenie "
    L"s textúrou; zrušením voľby Textúra prepnete vybrané monitory na drôtový model. Pri označení "
    L"viacerých riadkov sa voľba použije pre všetky označené monitory. Jazdec nastavuje rýchlosť "
    L"animácie v rozsahu 0–1600 %. EXE predvoleným spustením zapne iba primárny animačný monitor, "
    L"šetrič všetky monitory. Každý monitor sa vykresľuje podľa vlastnej obnovovacej frekvencie. "
    L"Nastavenia sa ukladajú zvlášť pre aplikáciu a šetrič obrazovky. Voľba Prevaľovanie kamery zapne "
    L"na označených monitoroch plynulé otáčanie pohľadu do všetkých smerov; predvolene je vypnutá. "
    L"Voľba Zastavovanie a zmeny smeru pridá v náhodných intervaloch plynulé brzdenie prevaľovania "
    L"kamery, krátke zastavenie a rozbeh opačným smerom. Je dostupná pri zapnutom prevaľovaní a "
    L"predvolene je vypnutá; samotný prelet pokračuje.\r\n\r\nV zozname možno označiť viac monitorov; "
    L"dvojklik zapína alebo vypína animáciu na monitore a možno zrušiť aj výber všetkých. Každý "
    L"monitor používa nezávislú scénu. Snímka uloží PNG a tlačidlo záznamu spustí alebo ukončí MP4. "
    L"Pozastavenie zastaví animáciu. Aplikácia tiež nainštaluje alebo odinštaluje vložený šetrič. "
    L"Nastavenia sa ukladajú priebežne. Aplikácia beží iba v jednej inštancii. Ďalšie spustenie obnoví "
    L"minimalizované ovládacie okno a prenesie do popredia. Medzi ovládacími prvkami prechádzajte klávesmi "
    L"Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a príslušného písmena. Esc zavrie aktívne "
    L"okno Pomocníka alebo O aplikácii; v ovládacom okne ukončí aplikáciu. Voľba Blokovať šetrič pri "
    L"animácii bráni spusteniu šetriča Windows iba vtedy, keď je animácia skutočne viditeľná a nie je "
    L"pozastavená.\r\n\r\nSnímky a záznamy zachytávajú prvý aktívny animačný monitor, nie spoločnú plochu "
    L"všetkých monitorov. PNG používa Obrázky, MP4 Videá; ak tieto priečinky neexistujú, použijú sa "
    L"Dokumenty. Tlačidlo Nastavenie záznamu vyberá Viewport alebo TV. Viewport zachováva rozmery "
    L"animačného monitora a jeho obnovovaciu frekvenciu, najviac 60 snímok za sekundu. TV ponúka rozlíšenie "
    L"1920 × 1080, 1440 × 1080 alebo 1280 × 720 v pomere 16:9 a frekvenciu 50, 25, 59.94 (60000/1001) alebo "
    L"29.97 (30000/1001) snímok za sekundu. Obraz zachováva pomer strán; TV používa progresívne video "
    L"BT.709 s obmedzeným rozsahom a vzorkovaním 4:2:0. Rozlíšenie a snímkovú frekvenciu možno vybrať iba v "
    L"režime TV. Okno Nastavenie záznamu možno minimalizovať a neblokuje ostatné okná aplikácie. OK uloží "
    L"voľby pre nasledujúci záznam MP4; Zrušiť alebo Esc zahodí nepotvrdené zmeny. Nahrávaný monitor "
    L"nemožno počas záznamu odpojiť; zmeny ostatných monitorov záznam nezastavia. Ukončenie aplikácie počas "
    L"záznamu vyžaduje potvrdenie, pretože ukončí aj záznam.\r\n\r\nWindows 7 až Windows 11 podporujú "
    L"všetky funkcie vrátane snímok PNG a záznamu MP4. Na spustenie aplikácie v systéme Windows Vista SP2 "
    L"je potrebné nainštalovať aktualizácie KB971512 a KB2117917. Záznam MP4 na Viste v súčasnej verzii "
    L"nefunguje.",
    L"FlightCorridor tilbyder Flyvetur mellem fire formskiftende flader og Flyvetur gennem en formskiftende "
    L"tragt. Tildel præcis én flyvetur til hver skærm: vælg dens række og den tilsvarende alternativknap. "
    L"Den første animation er valgt på alle skærme som standard. Tekstur er slået til som standard; "
    L"fjern markeringen ved Tekstur for at vise de valgte skærme som trådmodeller. Når flere rækker er "
    L"valgt, gælder valget alle disse skærme. Skyderen indstiller animationshastigheden fra 0 til 1600 "
    L"%. Ved standardstart aktiverer EXE kun den primære animationsskærm, mens pauseskærmen aktiverer "
    L"alle skærme. Hver skærm gengives med sin egen opdateringsfrekvens. Indstillingerne gemmes separat "
    L"for programmet og pauseskærmen. Frit roterende kamera giver jævn rotation af visningen i alle "
    L"retninger på de valgte skærme; indstillingen er som standard slået fra. Stop og retningsskift "
    L"bremser kamerarotationen jævnt med tilfældige mellemrum, stopper den kort og starter den igen i "
    L"modsat retning. Valget er tilgængeligt, når frit roterende kamera er aktiveret, og er slået fra "
    L"som standard; flyvningen fortsætter.\r\n\r\nVælg flere skærme i listen; dobbeltklik på en række "
    L"for at slå animationen til eller fra, eller fravælg alle. Hver skærm bruger en uafhængig scene. "
    L"Skærmbillede gemmer PNG, og optageknappen starter eller stopper MP4. Pause standser animationen. "
    L"Programmet installerer eller afinstallerer også den indbyggede pauseskærm. Indstillinger gemmes "
    L"løbende. Programmet kan kun køre i én instans ad gangen. En ny start gendanner det minimerede "
    L"kontrolvindue og bringer det forrest. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og "
    L"det understregede bogstav aktiverer en kommando. Esc lukker det aktive Hjælp- eller Om-vindue; i "
    L"kontrolvinduet afslutter det programmet. Blokér pauseskærm under animation forhindrer "
    L"Windows-pauseskærmen i at starte, men kun når animationen faktisk er synlig og ikke er sat på "
    L"pause.\r\n\r\nSkærmbilleder og optagelser bruger den første aktive animationsskærm, ikke et samlet "
    L"billede af alle skærme. PNG bruger Billeder, MP4 Videoer; hvis disse mapper ikke findes, bruges "
    L"Dokumenter. Knappen Optagelsesindstillinger vælger Viewport eller TV. Viewport bevarer "
    L"animationsskærmens størrelse og opdateringsfrekvens, højst 60 billeder i sekundet. TV tilbyder 1920 × "
    L"1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9 med 50, 25, 59.94 (60000/1001) eller 29.97 "
    L"(30000/1001) billeder i sekundet. Billedets proportioner bevares; TV bruger progressiv BT.709-video "
    L"med begrænset område og 4:2:0-sampling. Opløsning og billedfrekvens kan kun vælges i TV-tilstand. "
    L"Vinduet Optagelsesindstillinger kan minimeres og blokerer ikke de andre programvinduer. OK gemmer "
    L"valgene til den næste MP4-optagelse; Annuller eller Esc kasserer ubekræftede ændringer. Den skærm, "
    L"der optages, kan ikke fravælges under optagelsen; ændringer af andre skærme stopper ikke optagelsen. "
    L"Hvis programmet lukkes under en optagelse, kræves en bekræftelse, fordi optagelsen også "
    L"afsluttes.\r\n\r\nWindows 7 til Windows 11 understøtter alle funktioner, herunder PNG-skærmbilleder "
    L"og MP4-optagelse. For at køre programmet på Windows Vista SP2 skal opdateringerne KB971512 og "
    L"KB2117917 installeres. MP4-optagelse fungerer ikke på Vista i den aktuelle version.",
    L"FlightCorridor tarjoaa Lento neljän muuntuvan pinnan välissä ja Lento muuntuvan suppilon läpi "
    L"-animaatiot. Määritä kullekin näytölle täsmälleen yksi lento: valitse näytön rivi ja vastaava "
    L"valintanappi. Ensimmäinen animaatio on oletusarvoisesti valittuna kaikilla näytöillä. Tekstuuri "
    L"on oletusarvoisesti käytössä; poista Tekstuuri-valinta, jos haluat näyttää valitut näytöt "
    L"rautalankamallina. Jos valitset useita rivejä, valinta koskee kaikkia näitä näyttöjä. Liukusäädin "
    L"asettaa animaation nopeuden välille 0–1600 %. Oletuskäynnistyksessä EXE ottaa käyttöön vain "
    L"ensisijaisen animaationäytön, näytönsäästäjä kaikki näytöt. Jokainen näyttö piirretään omalla "
    L"virkistystaajuudellaan. Asetukset tallennetaan erikseen sovellukselle ja näytönsäästäjälle. "
    L"Kameran vapaa pyörintä kääntää näkymää pehmeästi kaikkiin suuntiin valituilla näytöillä; toiminto "
    L"on oletusarvoisesti pois käytöstä. Pysähdykset ja suunnanvaihdot hidastaa kameran pyörintää "
    L"tasaisesti satunnaisin väliajoin, pysäyttää sen hetkeksi ja käynnistää sen vastakkaiseen "
    L"suuntaan. Valinta on käytettävissä kameran vapaan pyörinnän ollessa käytössä ja on oletuksena "
    L"pois käytöstä; lento jatkuu.\r\n\r\nLuettelosta voi valita useita näyttöjä; kaksoisnapsautus "
    L"vaihtaa rivin tilaa ja kaikkien näyttöjen valinnan voi poistaa. Jokaisella näytöllä on itsenäinen "
    L"näkymä. Tilannekuva tallentaa PNG:n ja tallennuspainike käynnistää tai lopettaa MP4:n. Keskeytä "
    L"pysäyttää animaation. Sovellus asentaa tai poistaa myös sisäisen näytönsäästäjän. Asetukset "
    L"tallennetaan jatkuvasti. Sovelluksesta voi olla käynnissä vain yksi instanssi. Uusi käynnistys "
    L"palauttaa pienennetyn ohjausikkunan ja tuo sen etualalle. Siirry säätimien välillä Tab- ja "
    L"Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat komennon. Esc sulkee aktiivisen Ohje- "
    L"tai Tietoja-ikkunan; ohjausikkunassa se sulkee sovelluksen. Estä näytönsäästäjä animaation aikana "
    L"estää Windowsin näytönsäästäjän käynnistymisen vain silloin, kun animaatio on todella näkyvissä eikä "
    L"sitä ole keskeytetty.\r\n\r\nTilannekuvat ja tallenteet käyttävät ensimmäistä aktiivista "
    L"animaationäyttöä, eivät kaikkien näyttöjen yhdistettyä kuvaa. PNG käyttää Kuvat-kansiota ja MP4 "
    L"Videot-kansiota; jos niitä ei ole, käytetään Tiedostot-kansiota. Tallennusasetukset-painikkeella "
    L"valitaan Viewport tai TV. Viewport säilyttää animaationäytön koon ja virkistystaajuuden, enintään 60 "
    L"kuvaa sekunnissa. TV tarjoaa tarkkuudet 1920 × 1080, 1440 × 1080 ja 1280 × 720 kuvasuhteella 16:9 "
    L"sekä taajuudet 50, 25, 59.94 (60000/1001) ja 29.97 (30000/1001) kuvaa sekunnissa. Kuvasuhde säilyy; "
    L"TV käyttää progressiivista BT.709-videota rajatulla alueella ja 4:2:0-näytteistyksellä. Tarkkuus ja "
    L"kuvataajuus ovat valittavissa vain TV-tilassa. Tallennusasetukset-ikkunan voi pienentää, eikä se estä "
    L"muiden sovellusikkunoiden käyttöä. OK tallentaa valinnat seuraavaa MP4-tallennusta varten; Peruuta "
    L"tai Esc hylkää vahvistamattomat muutokset. Tallennettavan näytön valintaa ei voi poistaa tallennuksen "
    L"aikana; muiden näyttöjen muutokset eivät pysäytä tallennusta. Sovelluksen sulkeminen tallennuksen "
    L"aikana vaatii vahvistuksen, sillä myös tallennus päättyy.\r\n\r\nWindows 7–Windows 11 tukevat kaikkia "
    L"toimintoja, myös PNG-tilannekuvia ja MP4-tallennusta. Sovelluksen suorittaminen Windows Vista SP2:ssa "
    L"edellyttää päivitysten KB971512 ja KB2117917 asentamista. MP4-tallennus ei toimi Vistassa nykyisessä "
    L"versiossa.",
    L"FlightCorridor býður upp á Flug milli fjögurra breytilegra flata og Flug í gegnum breytilega "
    L"trekt. Veldu nákvæmlega eitt flug fyrir hvern skjá: veldu röð skjásins og viðeigandi valhnapp. "
    L"Fyrsta hreyfimyndin er sjálfgefið valin á öllum skjám. Áferð er sjálfgefið virk; taktu hakið úr "
    L"Áferð til að sýna valda skjái sem víralíkön. Þegar margar raðir eru valdar gildir valið fyrir "
    L"alla þá skjái. Sleðinn stillir hraða hreyfimyndarinnar frá 0 til 1600 %. Við sjálfgefna ræsingu "
    L"virkjar EXE aðeins aðalhreyfimyndaskjáinn en skjávarinn alla skjái. Hver skjár er teiknaður á "
    L"sínum eigin endurnýjunarhraða. Stillingar eru vistaðar sérstaklega fyrir forritið og skjávarann. "
    L"Frjáls snúningur myndavélar snýr sjónarhorninu mjúklega í allar áttir á völdum skjám; sjálfgefið "
    L"er slökkt á þessum valkosti. Stopp og stefnuskipti hægir mjúklega á snúningi myndavélarinnar "
    L"með slembnu millibili, stöðvar hann stuttlega og byrjar aftur í gagnstæða átt. Valkosturinn er "
    L"tiltækur þegar frjáls snúningur myndavélar er virkur og er sjálfgefið óvirkur; flugið heldur "
    L"áfram.\r\n\r\nVelja má marga skjái; tvísmellur virkjar eða slekkur á hreyfimynd á skjá og afvelja "
    L"má alla skjái. Hver skjár notar sjálfstæða senu. Skjámynd vistar PNG og upptökuhnappurinn ræsir eða "
    L"stöðvar MP4. Hnappurinn Gera hlé stöðvar hreyfimyndina. Forritið setur einnig upp eða fjarlægir "
    L"innbyggðu skjáhvíluna. Stillingar vistast jafnóðum. Aðeins eitt eintak af forritinu getur verið í "
    L"gangi í einu. Ný ræsing endurheimtir lágmarkaðan stjórngluggann og færir hann fremst. Notaðu Tab og "
    L"Shift+Tab til að færa þig milli stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc lokar "
    L"virka Hjálp- eða Um-glugganum; í stjórnglugganum lokar það forritinu. Hindra skjáhvílu meðan "
    L"hreyfimynd er í gangi kemur aðeins í veg fyrir að skjáhvíla Windows fari í gang meðan hreyfimyndin er "
    L"í raun sýnileg og ekki í pásu.\r\n\r\nSkjámyndir og upptökur nota fyrsta virka hreyfimyndaskjáinn, "
    L"ekki sameinaða mynd af öllum skjám. PNG notar Myndir, MP4 Myndbönd; ef þær möppur eru ekki til er "
    L"Skjöl notuð. Hnappurinn Upptökustillingar velur Viewport eða TV. Viewport varðveitir stærð og "
    L"endurnýjunartíðni hreyfimyndaskjásins, þó mest 60 ramma á sekúndu. TV býður upp á 1920 × 1080, 1440 × "
    L"1080 eða 1280 × 720 í hlutfallinu 16:9 með 50, 25, 59.94 (60000/1001) eða 29.97 (30000/1001) römmum á "
    L"sekúndu. Hlutföll myndarinnar haldast; TV notar stigvaxandi BT.709-myndband með takmörkuðu sviði og "
    L"4:2:0-sýnatöku. Upplausn og rammatíðni eru aðeins valanleg í TV-ham. Hægt er að lágmarka gluggann "
    L"Upptökustillingar og hann hindrar ekki notkun annarra glugga forritsins. Í lagi vistar valið fyrir "
    L"næstu MP4-upptöku; Hætta við eða Esc hendir óstaðfestum breytingum. Ekki er hægt að afvelja skjáinn "
    L"sem er tekinn upp meðan upptaka stendur yfir; breytingar á öðrum skjám stöðva ekki upptökuna. "
    L"Staðfesta þarf lokun forritsins meðan upptaka stendur yfir, því hún stöðvar líka "
    L"upptökuna.\r\n\r\nWindows 7 til Windows 11 styðja alla eiginleika, þar á meðal PNG-skjámyndir og "
    L"MP4-upptöku. Til að keyra forritið á Windows Vista SP2 þarf að setja upp uppfærslurnar KB971512 og "
    L"KB2117917. MP4-upptaka virkar ekki í Vista í núverandi útgáfu.",
    L"FlightCorridor tilbyr Flytur mellom fire formendrende flater og Flytur gjennom en formendrende "
    L"trakt. Tilordne nøyaktig én flytur til hver skjerm: velg raden og den tilsvarende alternativknappen. "
    L"Den første animasjonen er valgt på alle skjermer som standard. Tekstur er aktivert som standard; "
    L"fjern avmerkingen for Tekstur for å vise de valgte skjermene som trådmodeller. Når flere rader er "
    L"valgt, gjelder valget alle disse skjermene. Glidebryteren angir animasjonshastigheten fra 0 til "
    L"1600 %. Ved standard oppstart aktiverer EXE bare den primære animasjonsskjermen; skjermspareren "
    L"aktiverer alle skjermene. Hver skjerm gjengis med sin egen oppdateringsfrekvens. Innstillingene "
    L"lagres separat for programmet og skjermspareren. Fritt roterende kamera gir jevn rotasjon av "
    L"visningen i alle retninger på de valgte skjermene; alternativet er av som standard. Stopp og "
    L"retningsendringer bremser kamerarotasjonen gradvis med tilfeldige mellomrom, stopper den kort "
    L"og starter den igjen i motsatt retning. Valget er tilgjengelig når fritt roterende kamera er "
    L"aktivert, og er av som standard; flygingen fortsetter.\r\n\r\nVelg flere skjermer i listen; "
    L"dobbeltklikk en rad for å slå animasjonen av eller på, eller fjern valget for alle. Hver skjerm "
    L"bruker en uavhengig scene. Skjermbilde lagrer PNG, og opptaksknappen starter eller stopper MP4. Pause "
    L"stanser animasjonen. Programmet installerer eller avinstallerer også den innebygde skjermspareren. "
    L"Innstillingene lagres fortløpende. Bare én instans av programmet kan kjøre om gangen. En ny start "
    L"gjenoppretter det minimerte kontrollvinduet og bringer det fremst. Bruk Tab og Shift+Tab for å flytte "
    L"mellom kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc lukker det aktive "
    L"Hjelp- eller Om-vinduet; i kontrollvinduet avslutter det programmet. Hindre skjermsparer under "
    L"animasjon hindrer Windows-skjermspareren i å starte bare når animasjonen faktisk er synlig og ikke er "
    L"satt på pause.\r\n\r\nSkjermbilder og opptak bruker den første aktive animasjonsskjermen, ikke et "
    L"samlet bilde av alle skjermene. PNG bruker Bilder, MP4 Videoer; hvis disse mappene ikke finnes, "
    L"brukes Dokumenter. Knappen Opptaksinnstillinger velger Viewport eller TV. Viewport beholder "
    L"animasjonsskjermens størrelse og oppdateringsfrekvens, opptil 60 bilder per sekund. TV tilbyr 1920 × "
    L"1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9, med 50, 25, 59.94 (60000/1001) eller 29.97 "
    L"(30000/1001) bilder per sekund. Bildets proporsjoner beholdes; TV bruker progressiv BT.709-video med "
    L"begrenset område og 4:2:0-sampling. Oppløsning og bildefrekvens er bare tilgjengelige i TV-modus. "
    L"Vinduet Opptaksinnstillinger kan minimeres og blokkerer ikke de andre programvinduene. OK lagrer "
    L"valgene for neste MP4-opptak; Avbryt eller Esc forkaster ubekreftede endringer. Skjermen som tas opp, "
    L"kan ikke velges bort under opptaket; endringer på andre skjermer stopper ikke opptaket. Å avslutte "
    L"programmet under et opptak krever bekreftelse, fordi det også avslutter opptaket.\r\n\r\nWindows 7 "
    L"til Windows 11 støtter alle funksjoner, inkludert PNG-skjermbilder og MP4-opptak. For å kjøre "
    L"programmet på Windows Vista SP2 må oppdateringene KB971512 og KB2117917 installeres. MP4-opptak "
    L"fungerer ikke på Vista i den gjeldende versjonen.",
    L"FlightCorridor erbjuder Flygtur mellan fyra formföränderliga ytor och Flygtur genom en "
    L"formföränderlig tratt. Tilldela exakt en flygtur till varje bildskärm: välj dess rad och "
    L"motsvarande alternativknapp. Den första animationen är vald på alla bildskärmar som standard. "
    L"Textur är aktiverad som standard; avmarkera Textur för att visa de valda bildskärmarna som "
    L"trådmodeller. När flera rader är markerade gäller valet alla dessa bildskärmar. Reglaget ställer "
    L"in animationshastigheten från 0 till 1600 %. Vid standardstart aktiverar EXE endast den primära "
    L"animationsskärmen, medan skärmsläckaren aktiverar alla bildskärmar. Varje bildskärm återges med "
    L"sin egen uppdateringsfrekvens. Inställningarna sparas separat för programmet och skärmsläckaren. "
    L"Fritt roterande kamera ger mjuk rotation av vyn i alla riktningar på de markerade skärmarna; "
    L"alternativet är av som standard. Stopp och riktningsbyten bromsar kamerarotationen mjukt med "
    L"slumpmässiga mellanrum, stoppar den kort och startar den igen åt motsatt håll. Alternativet är "
    L"tillgängligt när fritt roterande kamera är aktiverat och är avstängt som standard; flygningen "
    L"fortsätter.\r\n\r\nVälj flera bildskärmar i listan; dubbelklicka en rad för att slå på eller av "
    L"animeringen, eller avmarkera alla. Varje bildskärm använder en oberoende scen. Skärmbild sparar PNG "
    L"och inspelningsknappen startar eller stoppar MP4. Paus stannar animeringen. Programmet installerar "
    L"eller avinstallerar även den inbyggda skärmsläckaren. Inställningarna sparas fortlöpande. Programmet "
    L"kan bara köras i en instans åt gången. En ny start återställer det minimerade kontrollfönstret och "
    L"för det längst fram. Använd Tab och Skift+Tab för att flytta mellan kontrollerna; Alt och den "
    L"understrukna bokstaven aktiverar ett kommando. Esc stänger det aktiva Hjälp- eller Om-fönstret; i "
    L"kontrollfönstret avslutar det programmet. Blockera skärmsläckare under animering hindrar "
    L"Windows-skärmsläckaren från att starta endast när animeringen faktiskt är synlig och inte är "
    L"pausad.\r\n\r\nSkärmbilder och inspelningar använder den första aktiva animeringsskärmen, inte en "
    L"sammanslagen bild av alla skärmar. PNG använder Bilder, MP4 Videor; om dessa mappar saknas används "
    L"Dokument. Knappen Inspelningsinställningar väljer Viewport eller TV. Viewport behåller "
    L"animeringsskärmens storlek och uppdateringsfrekvens, upp till 60 bilder per sekund. TV erbjuder 1920 "
    L"× 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9, med 50, 25, 59.94 (60000/1001) eller 29.97 "
    L"(30000/1001) bilder per sekund. Bildens proportioner bevaras; TV använder progressiv BT.709-video med "
    L"begränsat omfång och 4:2:0-sampling. Upplösning och bildfrekvens kan bara väljas i TV-läge. Fönstret "
    L"Inspelningsinställningar kan minimeras och blockerar inte de andra programfönstren. OK sparar valen "
    L"för nästa MP4-inspelning; Avbryt eller Esc ignorerar obekräftade ändringar. Den inspelade skärmen kan "
    L"inte väljas bort under inspelningen; ändringar av andra skärmar stoppar inte inspelningen. Att "
    L"avsluta programmet under en inspelning kräver bekräftelse eftersom det också avslutar "
    L"inspelningen.\r\n\r\nWindows 7 till Windows 11 stöder alla funktioner, inklusive PNG-skärmbilder och "
    L"MP4-inspelning. För att köra programmet på Windows Vista SP2 måste uppdateringarna KB971512 och "
    L"KB2117917 installeras. MP4-inspelning fungerar inte på Vista i den aktuella versionen.",
    L"FlightCorridor, Biçim değiştiren dört yüzey arasında uçuş ve Biçim değiştiren bir huninin içinden "
    L"uçuş seçeneklerini sunar. Her monitöre tam olarak bir uçuş atayın: monitörün satırını ve ilgili "
    L"seçenek düğmesini seçin. Varsayılan olarak tüm monitörlerde ilk animasyon seçilidir. Doku varsayılan "
    L"olarak açıktır; seçili monitörleri tel kafes modeliyle göstermek için Doku seçeneğini kapatın. "
    L"Birden fazla satır seçilirse seçim tüm bu monitörlere uygulanır. Kaydırıcı animasyon hızını "
    L"%0–1600 arasında ayarlar. Varsayılan başlangıçta EXE yalnızca birincil animasyon monitörünü, "
    L"ekran koruyucu tüm monitörleri etkinleştirir. Her monitör kendi yenileme hızında çizilir. Ayarlar "
    L"uygulama ve ekran koruyucu için ayrı ayrı kaydedilir. Serbest kamera dönüşü, seçili ekranlarda "
    L"görünümü tüm yönlerde akıcı biçimde döndürür; varsayılan olarak kapalıdır. Duraklamalar ve yön "
    L"değişimleri kamera dönüşünü rastgele aralıklarla yavaşlatır, kısa süreliğine durdurur ve ters yönde "
    L"yeniden başlatır. Bu seçenek serbest kamera dönüşü etkin olduğunda kullanılabilir ve varsayılan "
    L"olarak kapalıdır; ileri uçuş devam eder.\r\n\r\nListede birden çok monitör seçilebilir; satıra "
    L"çift tıklamak monitördeki animasyonu açıp kapatır; tüm monitörlerin seçimi de kaldırılabilir. "
    L"Her monitör bağımsız sahne kullanır. Anlık görüntü PNG kaydeder; kayıt düğmesi MP4 kaydını başlatır "
    L"veya bitirir. Duraklat animasyonu durdurur. Uygulama gömülü ekran koruyucuyu da kurar veya kaldırır. "
    L"Ayarlar sürekli kaydedilir. Uygulamanın aynı anda yalnızca bir örneği çalışabilir. Yeniden "
    L"başlatılması, simge durumuna küçültülmüş denetim penceresini geri yükler ve ön plana getirir. "
    L"Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir komutu etkinleştirir. "
    L"Esc, etkin Yardım veya Hakkında penceresini kapatır; denetim penceresinde uygulamadan çıkar. "
    L"Animasyon sırasında ekran koruyucuyu engelle seçeneği, Windows ekran koruyucusunun yalnızca animasyon "
    L"gerçekten görünürken ve duraklatılmamışken başlamasını engeller.\r\n\r\nAnlık görüntüler ve kayıtlar, "
    L"tüm monitörlerin birleşik görüntüsünü değil, ilk etkin animasyon monitörünü kullanır. PNG Resimler, "
    L"MP4 Videolar klasörünü kullanır; bu klasörler yoksa Belgeler kullanılır. Kayıt ayarları düğmesi "
    L"Viewport veya TV seçimini açar. Viewport, animasyon monitörünün boyutlarını ve yenileme hızını "
    L"saniyede en fazla 60 kareyle korur. TV, 16:9 oranında 1920 × 1080, 1440 × 1080 veya 1280 × 720 "
    L"çözünürlük ile saniyede 50, 25, 59.94 (60000/1001) veya 29.97 (30000/1001) kare sunar. Görüntünün en "
    L"boy oranı korunur; TV, sınırlı aralıklı, 4:2:0 örneklemeli ilerlemeli BT.709 video kullanır. "
    L"Çözünürlük ve kare hızı yalnızca TV modunda seçilebilir. Kayıt ayarları penceresi simge durumuna "
    L"küçültülebilir ve uygulamanın diğer pencerelerini engellemez. Tamam, seçenekleri bir sonraki MP4 "
    L"kaydı için kaydeder; İptal veya Esc onaylanmamış değişiklikleri iptal eder. Kayıt sırasında "
    L"kaydedilen ekranın seçimi kaldırılamaz; diğer ekranlardaki değişiklikler kaydı durdurmaz. Kayıt "
    L"sırasında uygulamayı kapatmak kaydı da durduracağı için onay gerektirir.\r\n\r\nWindows 7 ile Windows "
    L"11 arasındaki sürümler, PNG anlık görüntüler ve MP4 kaydı dâhil tüm özellikleri destekler. Uygulamayı "
    L"Windows Vista SP2'de çalıştırmak için KB971512 ve KB2117917 güncellemelerini yüklemeniz gerekir. "
    L"Geçerli sürümde MP4 kaydı Vista'da çalışmaz."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> SCREEN_SAVER_HELP_TEXTS = {
    L"FlightCorridor nabízí Průlet čtyřmi proměnlivými plochami a Průlet proměnlivým trychtýřem. "
    L"Každému monitoru přiřadíte právě jeden průlet: označte jeho řádek v seznamu a zvolte příslušný "
    L"přepínač. Ve výchozím stavu je na všech monitorech zvolena první animace. Výchozí je zobrazení "
    L"s texturou; zrušením volby Textura přepnete vybrané monitory na drátěný model. Při označení "
    L"více řádků se volba použije pro všechny označené monitory. Jezdec nastavuje rychlost animace v "
    L"rozsahu 0–1600 %. EXE výchozím spuštěním zapne pouze primární animační monitor, spořič všechny "
    L"monitory. Každý monitor se vykresluje podle vlastní obnovovací frekvence. Nastavení se ukládá "
    L"zvlášť pro aplikaci a spořič obrazovky. Volba Převalování kamery zapne na označených monitorech "
    L"plynulé otáčení pohledu do všech směrů; ve výchozím stavu je vypnutá. Volba Zastavování a změny "
    L"směru přidá v náhodných intervalech plynulé brzdění převalování kamery, krátké zastavení a "
    L"rozběh opačným směrem. Je dostupná při zapnutém převalování a ve výchozím stavu je vypnutá; "
    L"samotný průlet pokračuje.\r\n\r\nZapnout náhled spustí celoobrazovkový náhled na všech "
    L"monitorech; změny lze zkoušet za otevřeného nastavení. OK nastavení uloží, Storno je zahodí. "
    L"Celoobrazovkový spořič ukončíte klávesou Esc nebo pohybem myši. Mezi ovládacími prvky přecházejte "
    L"klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a příslušného písmene. Esc v "
    L"nastavení odpovídá tlačítku Storno; v nápovědě nebo okně O aplikaci zavře pouze toto "
    L"okno.\r\n\r\nPodporovány jsou systémy Windows 7 až Windows 11. Pro spuštění aplikace ve Windows Vista "
    L"SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917.",
    L"FlightCorridor offers Flight between four morphing surfaces and Flight through a morphing funnel. "
    L"Assign exactly one flight to each display: select its row in the list and choose the corresponding "
    L"radio button. The first animation is selected on every display by default. Textured rendering is the "
    L"default; clear Texture to switch the selected displays to wireframe. With several rows selected, the "
    L"choice applies to every selected display. The slider sets animation speed from 0–1600%. On default "
    L"startup, EXE enables only the primary animation display; the screen saver enables all displays. Each "
    L"display renders at its own refresh rate. Settings are stored separately for the application and "
    L"screen saver. Camera tumbling enables smooth rotation of the view in all directions on the selected "
    L"displays; it is off by default. Stops and reversals adds gradual braking, brief pauses and reversal "
    L"of camera tumbling at random intervals. It is available when Camera tumbling is enabled and is off "
    L"by default; forward flight continues.\r\n\r\nEnable preview starts a full-screen preview on every "
    L"display while the settings dialog remains open for live adjustments. OK saves the settings and Cancel "
    L"discards them. Exit the full-screen saver with Esc or mouse movement. Use Tab and Shift+Tab to move "
    L"between controls; use Alt and the underlined letter to activate a command. Esc in the settings dialog "
    L"is equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\nWindows 7 through "
    L"Windows 11 are supported. To run the application on Windows Vista SP2, you must install updates "
    L"KB971512 and KB2117917.",
    L"FlightCorridor offers Flight between four morphing surfaces and Flight through a morphing funnel. "
    L"Assign exactly one flight to each display: select its row in the list and choose the corresponding "
    L"radio button. The first animation is selected on every display by default. Textured rendering is the "
    L"default; clear Texture to switch the selected displays to wireframe. With several rows selected, the "
    L"choice applies to every selected display. The slider sets animation speed from 0–1600%. On default "
    L"startup, EXE enables only the primary animation display; the screen saver enables all displays. Each "
    L"display renders at its own refresh rate. Settings are stored separately for the application and "
    L"screen saver. Camera tumbling enables smooth rotation of the view in all directions on the selected "
    L"displays; it is off by default. Stops and reversals adds gradual braking, brief pauses and reversal "
    L"of camera tumbling at random intervals. It is available when Camera tumbling is enabled and is off by "
    L"default; forward flight continues.\r\n\r\nEnable preview starts a full-screen preview on every display "
    L"and allows live adjustments while the settings dialog remains open. OK saves the settings and Cancel "
    L"discards them. Exit the full-screen screen saver with Esc or mouse movement. Use Tab and Shift+Tab to "
    L"move between controls; use Alt and the underlined letter to activate a command. Esc in the settings "
    L"dialog is equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\nWindows 7 "
    L"through Windows 11 are supported. To run the application on Windows Vista SP2, you must install "
    L"updates KB971512 and KB2117917.",
    L"FlightCorridor offers Flight between four morphing surfaces and Flight through a morphing funnel. "
    L"Assign exactly one flight to each display: select its row in the list and choose the corresponding "
    L"radio button. The first animation is selected on every display by default. Textured rendering is the "
    L"default; clear Texture to switch the selected displays to wireframe. With several rows selected, the "
    L"choice applies to every selected display. The slider sets animation speed from 0–1600%. On default "
    L"startup, EXE enables only the primary animation display; the screen saver enables all displays. Each "
    L"display renders at its own refresh rate. Settings are stored separately for the application and "
    L"screen saver. Camera tumbling enables smooth rotation of the view in all directions on the selected "
    L"displays; it is off by default. Stops and reversals adds gradual braking, brief pauses and reversal "
    L"of camera tumbling at random intervals. It is available when Camera tumbling is enabled and is off by "
    L"default; forward flight continues.\r\n\r\nEnable preview starts a full-screen preview on every display "
    L"and allows live adjustments while the settings dialog remains open. OK saves the settings and Cancel "
    L"discards them. Exit the full-screen screen saver with Esc or mouse movement. Use Tab and Shift+Tab to "
    L"move between controls; use Alt and the underlined letter to activate a command. Esc in the settings "
    L"dialog is equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\nWindows 7 "
    L"through Windows 11 are supported. To run the application on Windows Vista SP2, you must install "
    L"updates KB971512 and KB2117917.",
    L"FlightCorridor bietet Flug zwischen vier veränderlichen Flächen und Flug durch einen veränderlichen "
    L"Trichter. Weisen Sie jedem Monitor genau einen Flug zu: Markieren Sie seine Zeile und wählen Sie "
    L"den entsprechenden Optionsschalter. Standardmäßig ist auf allen Monitoren die erste Animation "
    L"ausgewählt. Die Textur ist standardmäßig aktiviert; deaktivieren Sie Textur, um die ausgewählten "
    L"Monitore auf Drahtgittermodelle umzuschalten. Bei mehreren markierten Zeilen gilt die Auswahl "
    L"für alle markierten Monitore. Der Regler bestimmt die Animationsgeschwindigkeit von 0–1600 %. "
    L"Beim Standardstart aktiviert EXE nur den primären Animationsmonitor, der Bildschirmschoner alle "
    L"Monitore. Jeder Monitor wird mit seiner eigenen Bildwiederholfrequenz gerendert. Die Einstellungen "
    L"werden für Anwendung und Bildschirmschoner getrennt gespeichert. Taumelnde Kamera aktiviert auf "
    L"den markierten Monitoren eine gleichmäßige Drehung des Blicks in alle Richtungen; standardmäßig "
    L"ist die Option deaktiviert. Stopps und Richtungswechsel bremst die Kameradrehung in zufälligen "
    L"Abständen sanft ab, hält sie kurz an und setzt sie in umgekehrter Richtung fort. Die Option ist "
    L"bei aktivierter taumelnder Kamera verfügbar und standardmäßig deaktiviert; der Vorwärtsflug "
    L"geht weiter.\r\n\r\nVorschau einschalten startet eine Vollbildvorschau auf allen Monitoren. Der "
    L"Einstellungsdialog bleibt für Änderungen geöffnet. OK speichert, Abbrechen verwirft. Esc oder eine "
    L"Mausbewegung beendet den Vollbildschoner. Mit Tab und Umschalt+Tab wechseln Sie zwischen den "
    L"Steuerelementen; mit Alt und dem unterstrichenen Buchstaben rufen Sie einen Befehl auf. Esc im "
    L"Einstellungsdialog entspricht Abbrechen; in der Hilfe oder im Infofenster schließt es nur dieses "
    L"Fenster.\r\n\r\nUnterstützt werden Windows 7 bis Windows 11. Zum Ausführen der Anwendung unter "
    L"Windows Vista SP2 müssen die Updates KB971512 und KB2117917 installiert werden.",
    L"FlightCorridor propose Vol entre quatre surfaces déformables et Vol dans un entonnoir déformable. "
    L"Attribuez un seul vol à chaque moniteur : sélectionnez sa ligne, puis le bouton radio correspondant. "
    L"Par défaut, la première animation est sélectionnée sur tous les moniteurs. La texture est activée "
    L"par défaut ; décochez Texture pour afficher les moniteurs sélectionnés en mode filaire. Si "
    L"plusieurs lignes sont sélectionnées, le choix s’applique à tous ces moniteurs. Le curseur règle la "
    L"vitesse de l’animation de 0 à 1 600 %. Au démarrage par défaut, EXE active uniquement le moniteur "
    L"d’animation principal, tandis que l’économiseur active tous les moniteurs. Chaque moniteur est "
    L"rendu à sa propre fréquence de rafraîchissement. Les réglages sont enregistrés séparément pour "
    L"l’application et l’économiseur d’écran. Rotation libre de la caméra active une rotation fluide du "
    L"regard dans toutes les directions sur les moniteurs sélectionnés ; cette option est désactivée "
    L"par défaut. Arrêts et changements de sens ralentit progressivement la rotation de la caméra à "
    L"intervalles aléatoires, la suspend brièvement, puis la relance en sens inverse. Cette option est "
    L"disponible lorsque la rotation libre de la caméra est activée et est désactivée par défaut ; le vol "
    L"continue.\r\n\r\nActiver l’aperçu lance un aperçu plein écran sur tous les moniteurs ; la boîte "
    L"de dialogue reste ouverte pour les réglages en direct. OK enregistre les réglages, Annuler les "
    L"abandonne. Échap ou un mouvement de souris quitte le plein écran. Utilisez Tab et Maj+Tab pour passer "
    L"d’un contrôle à l’autre ; Alt et la lettre soulignée activent une commande. Échap dans les réglages "
    L"équivaut à Annuler ; dans l’aide ou À propos, cette touche ferme uniquement cette "
    L"fenêtre.\r\n\r\nWindows 7 à Windows 11 sont pris en charge. Pour exécuter l’application sous Windows "
    L"Vista SP2, il est nécessaire d’installer les mises à jour KB971512 et KB2117917.",
    L"FlightCorridor ofrece Vuelo entre cuatro superficies deformables y Vuelo por un embudo deformable. "
    L"Asigne exactamente un vuelo a cada monitor: seleccione su fila y el botón de opción correspondiente. "
    L"La primera animación está seleccionada de forma predeterminada en todos los monitores. La textura "
    L"está activada de forma predeterminada; desmarque Textura para mostrar los monitores seleccionados "
    L"en modo de alambre. Si selecciona varias filas, la opción se aplica a todos esos monitores. El "
    L"deslizador ajusta la velocidad de animación entre 0 y 1600 %. En el inicio predeterminado, EXE "
    L"activa solo el monitor de animación principal; el protector activa todos los monitores. Cada "
    L"monitor se dibuja a su propia frecuencia de actualización. Los ajustes se guardan por separado "
    L"para la aplicación y el protector de pantalla. Giro libre de la cámara activa una rotación "
    L"suave de la vista en todas las direcciones en los monitores seleccionados; está desactivado de "
    L"forma predeterminada. Paradas y cambios de sentido frena gradualmente el giro de la cámara a "
    L"intervalos aleatorios, lo detiene brevemente y lo reanuda en sentido contrario. La opción está "
    L"disponible con el giro libre de la cámara activado y está desactivada por defecto; el vuelo "
    L"continúa.\r\n\r\nActivar vista previa inicia una vista previa a pantalla completa en todos los "
    L"monitores; el cuadro de configuración permanece abierto para realizar ajustes en tiempo real. Aceptar "
    L"guarda y Cancelar descarta. Esc o mover el ratón cierra el salvapantallas completo. Use Tab y "
    L"Mayús+Tab para desplazarse entre controles; Alt y la letra subrayada activan una opción. Esc en la "
    L"configuración equivale a Cancelar; en Ayuda o Acerca de, cierra únicamente esa ventana.\r\n\r\nSe "
    L"admiten Windows 7 a Windows 11. Para ejecutar la aplicación en Windows Vista SP2, es necesario "
    L"instalar las actualizaciones KB971512 y KB2117917.",
    L"FlightCorridor offre Volo tra quattro superfici deformabili e Volo attraverso un imbuto "
    L"deformabile. Assegnare un solo volo a ogni monitor: selezionare la sua riga e il pulsante di "
    L"opzione corrispondente. La prima animazione è selezionata per impostazione predefinita su tutti "
    L"i monitor. La texture è attiva per impostazione predefinita; deselezionare Texture per mostrare "
    L"i monitor selezionati a reticolo. Se sono selezionate più righe, la scelta vale per tutti quei "
    L"monitor. Il cursore imposta la velocità dell’animazione da 0 a 1600 %. All’avvio predefinito, EXE "
    L"attiva solo il monitor di animazione principale, mentre il salvaschermo attiva tutti i monitor. "
    L"Ogni monitor viene disegnato alla propria frequenza di aggiornamento. Le impostazioni sono salvate "
    L"separatamente per l’applicazione e il salvaschermo. Rotazione libera della telecamera attiva "
    L"una rotazione fluida della vista in tutte le direzioni sui monitor selezionati; è disattivata "
    L"per impostazione predefinita. Arresti e inversioni rallenta gradualmente la rotazione della "
    L"telecamera a intervalli casuali, la ferma brevemente e la riavvia in senso opposto. L’opzione "
    L"è disponibile con la rotazione libera attiva ed è disattivata per impostazione predefinita; il "
    L"volo continua.\r\n\r\nAttiva anteprima avvia un’anteprima a schermo intero su tutti i monitor; le "
    L"impostazioni rimangono aperte per le modifiche in tempo reale. OK salva e Annulla scarta. Esc o il "
    L"movimento del mouse chiude il salvaschermo a schermo intero. Usare Tab e Maiusc+Tab per passare tra i "
    L"controlli; Alt e la lettera sottolineata attivano un comando. Esc nelle impostazioni equivale ad "
    L"Annulla; nella Guida o nelle Informazioni, chiude solo quella finestra.\r\n\r\nSono supportati i "
    L"sistemi da Windows 7 a Windows 11. Per eseguire l’applicazione su Windows Vista SP2, è necessario "
    L"installare gli aggiornamenti KB971512 e KB2117917.",
    L"O FlightCorridor oferece Voo entre quatro superfícies deformáveis e Voo através de um funil "
    L"deformável. Atribua um único voo a cada monitor: selecione a respetiva linha e o botão de opção "
    L"correspondente. Por predefinição, a primeira animação está selecionada em todos os monitores. A "
    L"textura está ativa por predefinição; desmarque Textura para mostrar os monitores selecionados em "
    L"modelo de arame. Com várias linhas selecionadas, a escolha aplica-se a todos esses monitores. O "
    L"controlo deslizante define a velocidade da animação entre 0 e 1600 %. No arranque predefinido, "
    L"EXE ativa apenas o monitor de animação principal, enquanto a proteção de ecrã ativa todos os "
    L"monitores. Cada monitor é desenhado à sua própria frequência de atualização. As definições são "
    L"guardadas separadamente para a aplicação e a proteção de ecrã. Rotação livre da câmara ativa "
    L"uma rotação suave da vista em todas as direções nos monitores selecionados; está desativada "
    L"por predefinição. Paragens e inversões de sentido abranda gradualmente a rotação da câmara "
    L"em intervalos aleatórios, interrompe-a brevemente e retoma-a no sentido oposto. A opção está "
    L"disponível com a rotação livre da câmara ativa e está desativada por predefinição; o voo "
    L"continua.\r\n\r\nAtivar pré-visualização inicia uma pré-visualização em ecrã inteiro em todos os "
    L"monitores e permite ajustes em tempo real. OK guarda as definições e Cancelar descarta-as. Esc ou o "
    L"movimento do rato termina a proteção em ecrã inteiro. Use Tab e Shift+Tab para passar entre "
    L"controlos; Alt e a letra sublinhada ativam um comando. Esc nas definições equivale a Cancelar; na "
    L"Ajuda ou em Acerca de, fecha apenas essa janela.\r\n\r\nSão suportados os sistemas Windows 7 a "
    L"Windows 11. Para executar a aplicação no Windows Vista SP2, é necessário instalar as atualizações "
    L"KB971512 e KB2117917.",
    L"FlightCorridor oferuje Przelot między czterema zmiennymi powierzchniami i Przelot przez zmienny "
    L"lejek. Każdemu monitorowi przypisz dokładnie jeden przelot: zaznacz jego wiersz i odpowiedni "
    L"przycisk opcji. Domyślnie na wszystkich monitorach wybrana jest pierwsza animacja. Tekstura "
    L"jest domyślnie włączona; wyłącz Tekstura, aby wybrane monitory wyświetlały model siatkowy. Przy "
    L"zaznaczeniu kilku wierszy wybór dotyczy wszystkich tych monitorów. Suwak ustawia prędkość animacji "
    L"w zakresie 0–1600 %. Przy domyślnym uruchomieniu EXE włącza tylko główny monitor animacji, a "
    L"wygaszacz wszystkie monitory. Każdy monitor jest renderowany z własną częstotliwością odświeżania. "
    L"Ustawienia są zapisywane osobno dla aplikacji i wygaszacza ekranu. Swobodne obracanie kamery "
    L"włącza płynne obracanie widoku we wszystkich kierunkach na zaznaczonych monitorach; domyślnie jest "
    L"wyłączone. Zatrzymania i zmiany kierunku stopniowo wyhamowuje obrót kamery w losowych odstępach, "
    L"na krótko go zatrzymuje, a następnie wznawia w przeciwnym kierunku. Opcja jest dostępna przy "
    L"włączonym swobodnym obracaniu kamery i domyślnie jest wyłączona; lot trwa nadal.\r\n\r\nWłącz "
    L"podgląd uruchamia podgląd pełnoekranowy na wszystkich monitorach. Okno ustawień pozostaje otwarte, "
    L"umożliwiając zmiany na bieżąco. OK zapisuje ustawienia, a Anuluj je odrzuca. Esc lub ruch myszy "
    L"kończy tryb pełnoekranowy. Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona "
    L"litera wywołują polecenie. Esc w ustawieniach odpowiada przyciskowi Anuluj; w Pomocy lub O programie "
    L"zamyka tylko to okno.\r\n\r\nObsługiwane są systemy od Windows 7 do Windows 11. Do uruchomienia "
    L"aplikacji w systemie Windows Vista SP2 konieczne jest zainstalowanie aktualizacji KB971512 i "
    L"KB2117917.",
    L"FlightCorridor ponúka Prelet štyrmi premenlivými plochami a Prelet premenlivým lievikom. "
    L"Každému monitoru priradíte práve jeden prelet: označte jeho riadok v zozname a zvoľte príslušný "
    L"prepínač. V predvolenom stave je na všetkých monitoroch zvolená prvá animácia. Predvolené je "
    L"zobrazenie s textúrou; zrušením voľby Textúra prepnete vybrané monitory na drôtový model. Pri "
    L"označení viacerých riadkov sa voľba použije pre všetky označené monitory. Jazdec nastavuje "
    L"rýchlosť animácie v rozsahu 0–1600 %. EXE predvoleným spustením zapne iba primárny animačný "
    L"monitor, šetrič všetky monitory. Každý monitor sa vykresľuje podľa vlastnej obnovovacej "
    L"frekvencie. Nastavenia sa ukladajú zvlášť pre aplikáciu a šetrič obrazovky. Voľba Prevaľovanie "
    L"kamery zapne na označených monitoroch plynulé otáčanie pohľadu do všetkých smerov; predvolene "
    L"je vypnutá. Voľba Zastavovanie a zmeny smeru pridá v náhodných intervaloch plynulé brzdenie "
    L"prevaľovania kamery, krátke zastavenie a rozbeh opačným smerom. Je dostupná pri zapnutom "
    L"prevaľovaní a predvolene je vypnutá; samotný prelet pokračuje.\r\n\r\nZapnúť náhľad spustí "
    L"celoobrazovkový náhľad na všetkých monitoroch; nastavenia zostávajú otvorené a zmeny sa prejavia "
    L"ihneď. OK uloží nastavenia a Zrušiť ich zahodí. Celoobrazovkový šetrič ukončí Esc alebo pohyb myši. "
    L"Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou "
    L"Alt a príslušného písmena. Esc v nastaveniach zodpovedá tlačidlu Zrušiť; v Pomocníkovi alebo okne O "
    L"aplikácii zavrie iba toto okno.\r\n\r\nPodporované sú systémy Windows 7 až Windows 11. Na spustenie "
    L"aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať aktualizácie KB971512 a KB2117917.",
    L"FlightCorridor tilbyder Flyvetur mellem fire formskiftende flader og Flyvetur gennem en formskiftende "
    L"tragt. Tildel præcis én flyvetur til hver skærm: vælg dens række og den tilsvarende alternativknap. "
    L"Den første animation er valgt på alle skærme som standard. Tekstur er slået til som standard; "
    L"fjern markeringen ved Tekstur for at vise de valgte skærme som trådmodeller. Når flere rækker "
    L"er valgt, gælder valget alle disse skærme. Skyderen indstiller animationshastigheden fra 0 til "
    L"1600 %. Ved standardstart aktiverer EXE kun den primære animationsskærm, mens pauseskærmen "
    L"aktiverer alle skærme. Hver skærm gengives med sin egen opdateringsfrekvens. Indstillingerne "
    L"gemmes separat for programmet og pauseskærmen. Frit roterende kamera giver jævn rotation af "
    L"visningen i alle retninger på de valgte skærme; indstillingen er som standard slået fra. Stop "
    L"og retningsskift bremser kamerarotationen jævnt med tilfældige mellemrum, stopper den kort og "
    L"starter den igen i modsat retning. Valget er tilgængeligt, når frit roterende kamera er aktiveret, "
    L"og er slået fra som standard; flyvningen fortsætter.\r\n\r\nAktivér forhåndsvisning starter en "
    L"fuldskærmsvisning på alle skærme. Indstillingerne forbliver åbne, og ændringerne vises med det samme. "
    L"OK gemmer indstillingerne, og Annuller forkaster ændringerne. Esc eller musebevægelse afslutter "
    L"fuldskærmen. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det understregede "
    L"bogstav aktiverer en kommando. Esc i indstillingerne svarer til Annuller; i Hjælp eller Om lukker det "
    L"kun dette vindue.\r\n\r\nWindows 7 til Windows 11 understøttes. For at køre programmet på Windows "
    L"Vista SP2 skal opdateringerne KB971512 og KB2117917 installeres.",
    L"FlightCorridor tarjoaa Lento neljän muuntuvan pinnan välissä ja Lento muuntuvan suppilon läpi "
    L"-animaatiot. Määritä kullekin näytölle täsmälleen yksi lento: valitse näytön rivi ja vastaava "
    L"valintanappi. Ensimmäinen animaatio on oletusarvoisesti valittuna kaikilla näytöillä. Tekstuuri "
    L"on oletusarvoisesti käytössä; poista Tekstuuri-valinta, jos haluat näyttää valitut näytöt "
    L"rautalankamallina. Jos valitset useita rivejä, valinta koskee kaikkia näitä näyttöjä. Liukusäädin "
    L"asettaa animaation nopeuden välille 0–1600 %. Oletuskäynnistyksessä EXE ottaa käyttöön vain "
    L"ensisijaisen animaationäytön, näytönsäästäjä kaikki näytöt. Jokainen näyttö piirretään omalla "
    L"virkistystaajuudellaan. Asetukset tallennetaan erikseen sovellukselle ja näytönsäästäjälle. "
    L"Kameran vapaa pyörintä kääntää näkymää pehmeästi kaikkiin suuntiin valituilla näytöillä; toiminto "
    L"on oletusarvoisesti pois käytöstä. Pysähdykset ja suunnanvaihdot hidastaa kameran pyörintää "
    L"tasaisesti satunnaisin väliajoin, pysäyttää sen hetkeksi ja käynnistää sen vastakkaiseen "
    L"suuntaan. Valinta on käytettävissä kameran vapaan pyörinnän ollessa käytössä ja on oletuksena "
    L"pois käytöstä; lento jatkuu.\r\n\r\nOta esikatselu käyttöön käynnistää koko näytön esikatselun "
    L"kaikilla näytöillä. Asetusikkuna pysyy avoinna, ja muutokset näkyvät heti. OK tallentaa asetukset ja "
    L"Peruuta hylkää muutokset. Esc tai hiiren liike lopettaa koko näytön säästäjän. Siirry säätimien "
    L"välillä Tab- ja Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat komennon. Esc "
    L"asetuksissa vastaa Peruuta-painiketta; Ohje- tai Tietoja-ikkunassa se sulkee vain kyseisen "
    L"ikkunan.\r\n\r\nTuettuja käyttöjärjestelmiä ovat Windows 7–Windows 11. Sovelluksen suorittaminen "
    L"Windows Vista SP2:ssa edellyttää päivitysten KB971512 ja KB2117917 asentamista.",
    L"FlightCorridor býður upp á Flug milli fjögurra breytilegra flata og Flug í gegnum breytilega "
    L"trekt. Veldu nákvæmlega eitt flug fyrir hvern skjá: veldu röð skjásins og viðeigandi valhnapp. "
    L"Fyrsta hreyfimyndin er sjálfgefið valin á öllum skjám. Áferð er sjálfgefið virk; taktu hakið úr "
    L"Áferð til að sýna valda skjái sem víralíkön. Þegar margar raðir eru valdar gildir valið fyrir "
    L"alla þá skjái. Sleðinn stillir hraða hreyfimyndarinnar frá 0 til 1600 %. Við sjálfgefna ræsingu "
    L"virkjar EXE aðeins aðalhreyfimyndaskjáinn en skjávarinn alla skjái. Hver skjár er teiknaður á "
    L"sínum eigin endurnýjunarhraða. Stillingar eru vistaðar sérstaklega fyrir forritið og skjávarann. "
    L"Frjáls snúningur myndavélar snýr sjónarhorninu mjúklega í allar áttir á völdum skjám; sjálfgefið "
    L"er slökkt á þessum valkosti. Stopp og stefnuskipti hægir mjúklega á snúningi myndavélarinnar "
    L"með slembnu millibili, stöðvar hann stuttlega og byrjar aftur í gagnstæða átt. Valkosturinn er "
    L"tiltækur þegar frjáls snúningur myndavélar er virkur og er sjálfgefið óvirkur; flugið heldur "
    L"áfram.\r\n\r\nVirkja forskoðun ræsir forskoðun á öllum skjám. Stillingaglugginn helst opinn "
    L"og breytingar sjást strax. Í lagi vistar stillingar og Hætta við hafnar breytingum. Esc eða "
    L"músarhreyfing lokar skjáhvílu á öllum skjánum. Notaðu Tab og Shift+Tab til að færa þig milli "
    L"stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc í stillingum jafngildir Hætta við; í "
    L"Hjálp eða Um lokar það aðeins þeim glugga.\r\n\r\nWindows 7 til Windows 11 eru studd. Til að keyra "
    L"forritið á Windows Vista SP2 þarf að setja upp uppfærslurnar KB971512 og KB2117917.",
    L"FlightCorridor tilbyr Flytur mellom fire formendrende flater og Flytur gjennom en formendrende "
    L"trakt. Tilordne nøyaktig én flytur til hver skjerm: velg raden og den tilsvarende alternativknappen. "
    L"Den første animasjonen er valgt på alle skjermer som standard. Tekstur er aktivert som standard; "
    L"fjern avmerkingen for Tekstur for å vise de valgte skjermene som trådmodeller. Når flere rader er "
    L"valgt, gjelder valget alle disse skjermene. Glidebryteren angir animasjonshastigheten fra 0 til "
    L"1600 %. Ved standard oppstart aktiverer EXE bare den primære animasjonsskjermen; skjermspareren "
    L"aktiverer alle skjermene. Hver skjerm gjengis med sin egen oppdateringsfrekvens. Innstillingene "
    L"lagres separat for programmet og skjermspareren. Fritt roterende kamera gir jevn rotasjon av "
    L"visningen i alle retninger på de valgte skjermene; alternativet er av som standard. Stopp og "
    L"retningsendringer bremser kamerarotasjonen gradvis med tilfeldige mellomrom, stopper den kort "
    L"og starter den igjen i motsatt retning. Valget er tilgjengelig når fritt roterende kamera er "
    L"aktivert, og er av som standard; flygingen fortsetter.\r\n\r\nSlå på forhåndsvisning starter en "
    L"fullskjermsvisning på alle skjermer. Innstillingene forblir åpne, og endringene vises fortløpende. OK "
    L"lagrer innstillingene og Avbryt forkaster dem. Esc eller musebevegelse avslutter "
    L"fullskjermsvisningen. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede "
    L"bokstaven aktiverer en kommando. Esc i innstillingene tilsvarer Avbryt; i Hjelp eller Om lukker det "
    L"bare dette vinduet.\r\n\r\nWindows 7 til Windows 11 støttes. For å kjøre programmet på Windows Vista "
    L"SP2 må oppdateringene KB971512 og KB2117917 installeres.",
    L"FlightCorridor erbjuder Flygtur mellan fyra formföränderliga ytor och Flygtur genom en "
    L"formföränderlig tratt. Tilldela exakt en flygtur till varje bildskärm: välj dess rad och "
    L"motsvarande alternativknapp. Den första animationen är vald på alla bildskärmar som standard. "
    L"Textur är aktiverad som standard; avmarkera Textur för att visa de valda bildskärmarna som "
    L"trådmodeller. När flera rader är markerade gäller valet alla dessa bildskärmar. Reglaget ställer "
    L"in animationshastigheten från 0 till 1600 %. Vid standardstart aktiverar EXE endast den primära "
    L"animationsskärmen, medan skärmsläckaren aktiverar alla bildskärmar. Varje bildskärm återges med "
    L"sin egen uppdateringsfrekvens. Inställningarna sparas separat för programmet och skärmsläckaren. "
    L"Fritt roterande kamera ger mjuk rotation av vyn i alla riktningar på de markerade skärmarna; "
    L"alternativet är av som standard. Stopp och riktningsbyten bromsar kamerarotationen mjukt med "
    L"slumpmässiga mellanrum, stoppar den kort och startar den igen åt motsatt håll. Alternativet är "
    L"tillgängligt när fritt roterande kamera är aktiverat och är avstängt som standard; flygningen "
    L"fortsätter.\r\n\r\nAktivera förhandsvisning startar en helskärmsvisning på alla bildskärmar. "
    L"Inställningarna förblir öppna och ändringarna visas direkt. OK sparar inställningarna och Avbryt "
    L"förkastar ändringarna. Esc eller musrörelse avslutar helskärmsläget. Använd Tab och Skift+Tab för att "
    L"flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett kommando. Esc i "
    L"inställningarna motsvarar Avbryt; i Hjälp eller Om stänger det bara det fönstret.\r\n\r\nWindows 7 "
    L"till Windows 11 stöds. För att köra programmet på Windows Vista SP2 måste uppdateringarna KB971512 "
    L"och KB2117917 installeras.",
    L"FlightCorridor, Biçim değiştiren dört yüzey arasında uçuş ve Biçim değiştiren bir huninin içinden "
    L"uçuş seçeneklerini sunar. Her monitöre tam olarak bir uçuş atayın: monitörün satırını ve ilgili "
    L"seçenek düğmesini seçin. Varsayılan olarak tüm monitörlerde ilk animasyon seçilidir. Doku varsayılan "
    L"olarak açıktır; seçili monitörleri tel kafes modeliyle göstermek için Doku seçeneğini kapatın. "
    L"Birden fazla satır seçilirse seçim tüm bu monitörlere uygulanır. Kaydırıcı animasyon hızını "
    L"%0–1600 arasında ayarlar. Varsayılan başlangıçta EXE yalnızca birincil animasyon monitörünü, "
    L"ekran koruyucu tüm monitörleri etkinleştirir. Her monitör kendi yenileme hızında çizilir. Ayarlar "
    L"uygulama ve ekran koruyucu için ayrı ayrı kaydedilir. Serbest kamera dönüşü, seçili ekranlarda "
    L"görünümü tüm yönlerde akıcı biçimde döndürür; varsayılan olarak kapalıdır. Duraklamalar ve yön "
    L"değişimleri kamera dönüşünü rastgele aralıklarla yavaşlatır, kısa süreliğine durdurur ve ters "
    L"yönde yeniden başlatır. Bu seçenek serbest kamera dönüşü etkin olduğunda kullanılabilir ve "
    L"varsayılan olarak kapalıdır; ileri uçuş devam eder.\r\n\r\nÖnizlemeyi etkinleştir tüm monitörlerde "
    L"tam ekran önizleme başlatır. Ayarlar penceresi açık kalır ve değişiklikler anında görülür. Tamam "
    L"ayarları kaydeder, İptal değişiklikleri iptal eder. Tam ekran koruyucudan Esc veya fare hareketiyle "
    L"çıkılır. Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir komutu "
    L"etkinleştirir. Ayarlarda Esc, İptal ile aynı işlevi görür; Yardım veya Hakkında penceresinde yalnızca "
    L"o pencereyi kapatır.\r\n\r\nWindows 7 ile Windows 11 arasındaki sürümler desteklenir. Uygulamayı "
    L"Windows Vista SP2'de çalıştırmak için KB971512 ve KB2117917 güncellemelerini yüklemeniz gerekir."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> ABOUT_DESCRIPTION_TEXTS = {
    L"Hardwarově akcelerovaný průlet proměnlivým koridorem a trychtýřem.",
    L"Hardware-accelerated flight through a morphing corridor and funnel.",
    L"Hardware-accelerated flight through a morphing corridor and funnel.",
    L"Hardware-accelerated flight through a morphing corridor and funnel.",
    L"Hardwarebeschleunigter Flug durch einen veränderlichen Korridor und Trichter.",
    L"Vol accéléré par le matériel dans un couloir et un entonnoir déformables.",
    L"Vuelo acelerado por hardware por un corredor y un embudo deformables.",
    L"Volo con accelerazione hardware attraverso un corridoio e un imbuto deformabili.",
    L"Voo acelerado por hardware através de um corredor e de um funil deformáveis.",
    L"Sprzętowo przyspieszany przelot przez zmienny korytarz i lejek.",
    L"Hardvérovo akcelerovaný prelet premenlivým koridorom a lievikom.",
    L"Hardwareaccelereret flyvetur gennem en formskiftende korridor og tragt.",
    L"Laitteistokiihdytetty lento muuntuvan käytävän ja suppilon läpi.",
    L"Vélbúnaðarhraðað flug um breytilegan gang og trekt.",
    L"Maskinvareakselerert flytur gjennom en formendrende korridor og trakt.",
    L"Maskinvaruaccelererad flygtur genom en formföränderlig korridor och tratt.",
    L"Biçim değiştiren bir koridor ve hunide donanım hızlandırmalı uçuş."
};

/// Returns localized recording-settings captions for a validated language.
const RecordingText& RecordingSettingsText(AppLanguage language) {
    return RECORDING_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the close warning for a validated application language.
const wchar_t* RecordingCloseWarningText(AppLanguage language) {
    return RECORDING_CLOSE_WARNING_TEXTS[
        static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns a TV resolution caption at the supplied preset index.
const wchar_t* RecordingResolutionText(unsigned index) {
    return RECORDING_RESOLUTION_TEXTS[index];
}

/// Returns an exact TV frame-rate caption at the supplied preset index.
const wchar_t* RecordingRateText(unsigned index) {
    return RECORDING_RATE_TEXTS[index];
}

/// Returns the core text record for a validated application language.
const LocalizedText& Text(AppLanguage language) {
    return TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Maps invalid persisted language values to US English.
AppLanguage NormalizeLanguage(int language) {
    if (language >= 0 && language < static_cast<int>(AppLanguage::Count)) {
        return static_cast<AppLanguage>(language);
    }
    return AppLanguage::EnglishUs;
}

/// Resolves a language to its combo-box display index.
int LanguageIndex(AppLanguage language) {
    return static_cast<int>(NormalizeLanguage(static_cast<int>(language)));
}

/// Resolves a combo-box index to a supported language.
AppLanguage LanguageAtIndex(int index) {
    return NormalizeLanguage(index);
}

/// Maps the current user's Windows UI language to the nearest supported language.
AppLanguage DetectSystemLanguage() {
    const LANGID language = GetUserDefaultUILanguage();
    switch (PRIMARYLANGID(language)) {
        case LANG_CZECH:
            return AppLanguage::Czech;
        case LANG_ENGLISH:
            if (SUBLANGID(language) == SUBLANG_ENGLISH_UK) {
                return AppLanguage::EnglishUk;
            }
            if (SUBLANGID(language) == SUBLANG_ENGLISH_AUS) {
                return AppLanguage::EnglishAu;
            }
            return AppLanguage::EnglishUs;
        case LANG_GERMAN:
            return AppLanguage::German;
        case LANG_FRENCH:
            return AppLanguage::French;
        case LANG_SPANISH:
            return AppLanguage::Spanish;
        case LANG_ITALIAN:
            return AppLanguage::Italian;
        case LANG_POLISH:
            return AppLanguage::Polish;
        case LANG_SLOVAK:
            return AppLanguage::Slovak;
        case LANG_PORTUGUESE:
            return AppLanguage::Portuguese;
        case LANG_NORWEGIAN:
            return AppLanguage::Norwegian;
        case LANG_SWEDISH:
            return AppLanguage::Swedish;
        case LANG_FINNISH:
            return AppLanguage::Finnish;
        case LANG_DANISH:
            return AppLanguage::Danish;
        case LANG_ICELANDIC:
            return AppLanguage::Icelandic;
        case LANG_TURKISH:
            return AppLanguage::Turkish;
        default:
            return AppLanguage::EnglishUs;
    }
}


/// Website tooltip copied from the corresponding CalClock language entries.
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> ABOUT_VISIT_TOOLTIP_TEXTS = {
    L"Navštívit web",
    L"Visit website",
    L"Visit website",
    L"Visit website",
    L"Website besuchen",
    L"Visiter le site web",
    L"Visitar el sitio web",
    L"Visita il sito web",
    L"Visitar o site",
    L"Odwiedź witrynę",
    L"Navštíviť web",
    L"Besøg webstedet",
    L"Käy verkkosivustolla",
    L"Heimsækja vefsvæði",
    L"Besøk nettstedet",
    L"Besök webbplatsen",
    L"Web sitesini ziyaret et"
};

/// Returns the localized About website tooltip.
const wchar_t* AboutVisitTooltipText(AppLanguage language) {
    return ABOUT_VISIT_TOOLTIP_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized command that starts settings preview.
const wchar_t* EnablePreviewText(AppLanguage language) {
    return ENABLE_PREVIEW_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized command that stops settings preview.
const wchar_t* DisablePreviewText(AppLanguage language) {
    return DISABLE_PREVIEW_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized paused-state status text.
const wchar_t* PausedStatusText(AppLanguage language) {
    return PAUSED_STATUS_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns localized monitor-detail column captions and bit-depth formats.
const MonitorColumnText& MonitorColumnsText(AppLanguage language) {
    return MONITOR_COLUMN_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized option that inhibits the screen saver during visible animation.
const wchar_t* PreventScreenSaverText(AppLanguage language) {
    return PREVENT_SCREEN_SAVER_TEXTS[
        static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized ready status when no animation is rendering.
const wchar_t* ReadyStatusText(AppLanguage language) {
    return READY_STATUS_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized Help button caption.
const wchar_t* HelpButtonText(AppLanguage language) {
    return HELP_BUTTON_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized About button caption.
const wchar_t* AboutButtonText(AppLanguage language) {
    return ABOUT_BUTTON_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized Close button caption.
const wchar_t* CloseButtonText(AppLanguage language) {
    return CLOSE_BUTTON_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized snapshot button caption.
const wchar_t* SnapshotButtonText(AppLanguage language) {
    return SNAPSHOT_BUTTON_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized successful-snapshot status text.
const wchar_t* SnapshotSavedText(AppLanguage language) {
    return SNAPSHOT_SAVED_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized failed-snapshot status text.
const wchar_t* SnapshotFailedText(AppLanguage language) {
    return SNAPSHOT_FAILED_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized uninstall command caption.
const wchar_t* UninstallScreenSaverText(AppLanguage language) {
    return UNINSTALL_SCREEN_SAVER_TEXTS[
        static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized successful-uninstallation status text.
const wchar_t* UninstallationSucceededText(AppLanguage language) {
    return UNINSTALLATION_SUCCEEDED_TEXTS[
        static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the generic localized uninstallation failure text.
const wchar_t* UninstallationFailedText(AppLanguage language) {
    return UNINSTALLATION_FAILED_TEXTS[
        static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the recovery instruction for an open saver settings window.
const wchar_t* UninstallationBlockedBySettingsText(AppLanguage language) {
    return UNINSTALLATION_BLOCKED_BY_SETTINGS_TEXTS[static_cast<std::size_t>(NormalizeLanguage(
        static_cast<int>(language)))];
}

/// Returns the recovery instruction for an open Windows preview.
const wchar_t* UninstallationBlockedBySystemPreviewText(AppLanguage language) {
    return UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW_TEXTS[static_cast<std::size_t>(NormalizeLanguage(
        static_cast<int>(language)))];
}

/// Returns the recovery instruction for an active full-screen saver.
const wchar_t* UninstallationBlockedByRunningSaverText(AppLanguage language) {
    return UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER_TEXTS[static_cast<std::size_t>(NormalizeLanguage(
        static_cast<int>(language)))];
}

/// Returns Help text appropriate to standalone or screen-saver settings.
const wchar_t* HelpBodyText(AppLanguage language, bool appMode) {
    const std::size_t index = static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)));
    return appMode ? APPLICATION_HELP_TEXTS[index] : SCREEN_SAVER_HELP_TEXTS[index];
}

/// Returns the localized one-line product description.
const wchar_t* AboutDescriptionText(AppLanguage language) {
    return ABOUT_DESCRIPTION_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized product-version label.
const wchar_t* AboutVersionLabel(AppLanguage language) {
    return ABOUT_VERSION_LABELS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized target-platform label.
const wchar_t* AboutPlatformLabel(AppLanguage language) {
    return ABOUT_PLATFORM_LABELS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized website label.
const wchar_t* AboutWebsiteLabel(AppLanguage language) {
    return ABOUT_WEBSITE_LABELS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized command that opens the product website.
const wchar_t* OpenInBrowserText(AppLanguage language) {
    return OPEN_IN_BROWSER_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized copy-URL command.
const wchar_t* CopyUrlText(AppLanguage language) {
    return COPY_URL_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized copy-product-information command.
const wchar_t* CopyInformationText(AppLanguage language) {
    return COPY_INFORMATION_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Per-monitor switch between the original textured surfaces and wireframe rendering.
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> FILLED_SURFACE_TEXTS = {
    L"Textura",
    L"Texture",
    L"Texture",
    L"Texture",
    L"Textur",
    L"Texture",
    L"Textura",
    L"Texture",
    L"Textura",
    L"Tekstura",
    L"Textúra",
    L"Tekstur",
    L"Tekstuuri",
    L"Áferð",
    L"Tekstur",
    L"Textur",
    L"Doku"
};

/// Returns the selected monitors' texture option in the selected language.
const wchar_t* FilledSurfaceText(AppLanguage language) {
    return FILLED_SURFACE_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Per-monitor switch for continuous camera rotation in all three dimensions.
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> CAMERA_TUMBLING_TEXTS = {
    L"Převalování kamery",
    L"Camera tumbling",
    L"Camera tumbling",
    L"Camera tumbling",
    L"Taumelnde Kamera",
    L"Rotation libre de la caméra",
    L"Giro libre de la cámara",
    L"Rotazione libera della telecamera",
    L"Rotação livre da câmara",
    L"Swobodne obracanie kamery",
    L"Prevaľovanie kamery",
    L"Frit roterende kamera",
    L"Kameran vapaa pyörintä",
    L"Frjáls snúningur myndavélar",
    L"Fritt roterende kamera",
    L"Fritt roterande kamera",
    L"Serbest kamera dönüşü"
};

/// Returns the selected monitors' camera-tumbling option in the selected language.
const wchar_t* CameraTumblingText(AppLanguage language) {
    return CAMERA_TUMBLING_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Per-monitor switch for gradual stops and reversals of camera tumbling.
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> CAMERA_REVERSALS_TEXTS = {
    L"Zastavování a změny směru",
    L"Stops and reversals",
    L"Stops and reversals",
    L"Stops and reversals",
    L"Stopps und Richtungswechsel",
    L"Arrêts et changements de sens",
    L"Paradas y cambios de sentido",
    L"Arresti e inversioni",
    L"Paragens e inversões de sentido",
    L"Zatrzymania i zmiany kierunku",
    L"Zastavovanie a zmeny smeru",
    L"Stop og retningsskift",
    L"Pysähdykset ja suunnanvaihdot",
    L"Stopp og stefnuskipti",
    L"Stopp og retningsendringer",
    L"Stopp och riktningsbyten",
    L"Duraklamalar ve yön değişimleri"
};

/// Returns the selected monitors’ optional camera stops and reversals caption.
const wchar_t* CameraReversalsText(AppLanguage language) {
    return CAMERA_REVERSALS_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}
