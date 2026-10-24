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
 * Last modified for version 1.2.1.0
 */

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "Localization.h"
#include <windows.h>

using EffectTextArray = std::array<const wchar_t*, EFFECT_COUNT>;
using SurfaceShapeTextArray = std::array<const wchar_t*, 3>;

/// Original infinite-surface and long-distance flight names
constexpr EffectTextArray CZECH_EFFECTS = {
    L"Nekonečná vlnící se plocha",
    L"Dálkový let — proměnlivá plocha"
};

constexpr EffectTextArray ENGLISH_US_EFFECTS = {
    L"Infinite undulating surface",
    L"Long-distance flight — morphing surface"
};

constexpr EffectTextArray ENGLISH_UK_EFFECTS = ENGLISH_US_EFFECTS;
constexpr EffectTextArray ENGLISH_AU_EFFECTS = ENGLISH_US_EFFECTS;
constexpr EffectTextArray GERMAN_EFFECTS = {
    L"Unendliche wellenförmige Fläche",
    L"Fernflug — veränderliche Fläche"
};

constexpr EffectTextArray FRENCH_EFFECTS = {
    L"Surface ondulante infinie",
    L"Vol longue distance — surface déformable"
};

constexpr EffectTextArray SPANISH_EFFECTS = {
    L"Superficie ondulante infinita",
    L"Vuelo de larga distancia — superficie deformable"
};

constexpr EffectTextArray ITALIAN_EFFECTS = {
    L"Superficie ondulante infinita",
    L"Volo a lunga distanza — superficie deformabile"
};

constexpr EffectTextArray POLISH_EFFECTS = {
    L"Nieskończona falująca powierzchnia",
    L"Lot dalekodystansowy — zmienna powierzchnia"
};

constexpr EffectTextArray SLOVAK_EFFECTS = {
    L"Nekonečná vlniaca sa plocha",
    L"Diaľkový let — premenlivá plocha"
};

constexpr EffectTextArray PORTUGUESE_EFFECTS = {
    L"Superfície ondulante infinita",
    L"Voo de longa distância — superfície deformável"
};

constexpr EffectTextArray NORWEGIAN_EFFECTS = {
    L"Uendelig bølgende flate",
    L"Langdistanseflytur — formendrende flate"
};

constexpr EffectTextArray SWEDISH_EFFECTS = {
    L"Oändlig böljande yta",
    L"Långdistansflygtur — formföränderlig yta"
};

constexpr EffectTextArray FINNISH_EFFECTS = {
    L"Ääretön aaltoileva pinta",
    L"Pitkän matkan lento — muuntuva pinta"
};

constexpr EffectTextArray DANISH_EFFECTS = {
    L"Uendelig bølgende flade",
    L"Langdistanceflyvetur — formskiftende flade"
};

constexpr EffectTextArray ICELANDIC_EFFECTS = {
    L"Óendanleg bylgjandi flötur",
    L"Langflug — breytilegur flötur"
};

constexpr EffectTextArray TURKISH_EFFECTS = {
    L"Sonsuz dalgalanan yüzey",
    L"Uzun mesafeli uçuş — biçim değiştiren yüzey"
};

constexpr EffectTextArray ESTONIAN_EFFECTS = {
    L"Lõputu lainetav pind",
    L"Kauglend — muutuv pind"
};

constexpr EffectTextArray IRISH_EFFECTS = {
    L"Dromchla tonnúil gan teorainn",
    L"Eitilt fhada — dromchla athraitheach"
};

constexpr EffectTextArray LITHUANIAN_EFFECTS = {
    L"Begalinė banguojanti plokštuma",
    L"Tolimas skrydis — kintantis paviršius"
};

constexpr EffectTextArray LATVIAN_EFFECTS = {
    L"Bezgalīga viļņojoša virsma",
    L"Tāls lidojums — mainīga virsma"
};

constexpr EffectTextArray HUNGARIAN_EFFECTS = {
    L"Végtelen hullámzó felület",
    L"Távolsági repülés — változó felület"
};

constexpr EffectTextArray MALTESE_EFFECTS = {
    L"Wiċċ infinit li jimmewweġ",
    L"Titjira fit-tul — wiċċ li jinbidel"
};

constexpr EffectTextArray DUTCH_EFFECTS = {
    L"Oneindig golvend oppervlak",
    L"Langeafstandsvlucht — veranderend oppervlak"
};

constexpr EffectTextArray ROMANIAN_EFFECTS = {
    L"Suprafață ondulată infinită",
    L"Zbor la distanță — suprafață variabilă"
};

constexpr EffectTextArray GREEK_EFFECTS = {
    L"Απέραντη κυματοειδής επιφάνεια",
    L"Μακρινή πτήση — μεταβαλλόμενη επιφάνεια"
};

constexpr EffectTextArray BOSNIAN_EFFECTS = {
    L"Beskonačna valovita površina",
    L"Daleki let — promjenjiva površina"
};

constexpr EffectTextArray CROATIAN_EFFECTS = {
    L"Beskonačna valovita ploha",
    L"Daleki let — promjenjiva ploha"
};

constexpr EffectTextArray SLOVENIAN_EFFECTS = {
    L"Neskončna valovita ploskev",
    L"Oddaljeni let — spreminjajoča se ploskev"
};

constexpr EffectTextArray MONTENEGRIN_EFFECTS = {
    L"Beskonačna talasasta površina",
    L"Daleki let — promjenljiva površina"
};

constexpr EffectTextArray BELARUSIAN_EFFECTS = {
    L"Бясконцая хвалістая паверхня",
    L"Далёкі палёт — зменлівая паверхня"
};

constexpr EffectTextArray BULGARIAN_EFFECTS = {
    L"Безкрайна вълнообразна повърхнина",
    L"Далечен полет — променяща се повърхнина"
};

constexpr EffectTextArray MACEDONIAN_EFFECTS = {
    L"Бесконечна брановидна површина",
    L"Далечен лет — променлива површина"
};

constexpr EffectTextArray SERBIAN_EFFECTS = {
    L"Бесконачна таласаста површ",
    L"Далеки лет — променљива површ"
};

constexpr EffectTextArray UKRAINIAN_EFFECTS = {
    L"Нескінченна хвиляста поверхня",
    L"Далекий політ — мінлива поверхня"
};

constexpr EffectTextArray RUSSIAN_EFFECTS = {
    L"Бесконечная волнообразная поверхность",
    L"Дальний полёт — меняющаяся поверхность"
};

/// Core settings-window text records
const std::array<LocalizedText, LANGUAGE_COUNT> TEXTS = {
    LocalizedText{
        L"Čeština",
        L"SpaceFlight — ovládání",
        L"Nastavení SpaceFlight",
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
    }, LocalizedText{
        L"English (US)",
        L"SpaceFlight — Controls",
        L"SpaceFlight Settings",
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
    }, LocalizedText{
        L"English (UK)",
        L"SpaceFlight — Controls",
        L"SpaceFlight Settings",
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
    }, LocalizedText{
        L"English (Australia)",
        L"SpaceFlight — Controls",
        L"SpaceFlight Settings",
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
    }, LocalizedText{
        L"Deutsch",
        L"SpaceFlight — Steuerung",
        L"SpaceFlight-Einstellungen",
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
    }, LocalizedText{
        L"Français",
        L"SpaceFlight — Commandes",
        L"Paramètres de SpaceFlight",
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
    }, LocalizedText{
        L"Español",
        L"SpaceFlight — Control",
        L"Configuración de SpaceFlight",
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
    }, LocalizedText{
        L"Italiano",
        L"SpaceFlight — Controlli",
        L"Impostazioni di SpaceFlight",
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
    }, LocalizedText{
        L"Português",
        L"SpaceFlight — Controlo",
        L"Definições do SpaceFlight",
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
    }, LocalizedText{
        L"Polski",
        L"SpaceFlight — Sterowanie",
        L"Ustawienia SpaceFlight",
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
    }, LocalizedText{
        L"Slovenčina",
        L"SpaceFlight — Ovládanie",
        L"Nastavenia SpaceFlight",
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
    }, LocalizedText{
        L"Dansk",
        L"SpaceFlight — Styring",
        L"Indstillinger for SpaceFlight",
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
    }, LocalizedText{
        L"Suomi",
        L"SpaceFlight — Ohjaus",
        L"SpaceFlight-asetukset",
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
    }, LocalizedText{
        L"Íslenska",
        L"SpaceFlight — Stjórnun",
        L"Stillingar SpaceFlight",
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
    }, LocalizedText{
        L"Norsk (bokmål)",
        L"SpaceFlight — Kontroll",
        L"Innstillinger for SpaceFlight",
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
    }, LocalizedText{
        L"Svenska",
        L"SpaceFlight — Styrning",
        L"Inställningar för SpaceFlight",
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
    }, LocalizedText{
        L"Türkçe",
        L"SpaceFlight — Denetim",
        L"SpaceFlight Ayarları",
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
    }, LocalizedText{
        L"Eesti",
        L"SpaceFlight — juhtimine",
        L"SpaceFlight sätted",
        L"Keel:",
        L"Animatsiooni kiirus: %d %%",
        L"Valitud kuvarite lennurežiim",
        L"Luba kõik",
        L"Keela kõik",
        L"Animatsioonikuvar",
        L"Kuvar",
        L"Eraldusvõime",
        L"Asukoht",
        L"peamine",
        L"OK",
        L"Loobu",
        L"Alusta salvestamist…",
        L"Peata salvestamine",
        L"Peata",
        L"Jätka",
        L"Paigalda ekraanisäästja",
        L"Välju",
        L"Animatsioon töötab…",
        L"MP4 salvestamine…",
        L"Salvestis on salvestatud.",
        L"MP4 salvestamist ei saanud alustada.",
        L"Ekraanisäästjat ei paigaldatud.",
        L"Ekraanisäästja on paigaldatud.",
        L"Direct3D renderdajat ei saanud käivitada.",
        ESTONIAN_EFFECTS
    }, LocalizedText{
        L"Gaeilge",
        L"SpaceFlight — rialuithe",
        L"Socruithe SpaceFlight",
        L"Teanga:",
        L"Luas na beochana: %d %%",
        L"Eitilt na monatóirí roghnaithe",
        L"Cumasaigh uile",
        L"Díchumasaigh uile",
        L"Monatóir beochana",
        L"Monatóir",
        L"Taifeach",
        L"Suíomh",
        L"príomhúil",
        L"OK",
        L"Cealaigh",
        L"Tosaigh taifeadadh…",
        L"Stop taifeadadh",
        L"Cuir ar sos",
        L"Lean ar aghaidh",
        L"Suiteáil spárálaí scáileáin",
        L"Scoir",
        L"Tá an bheochan ar siúl…",
        L"Tá taifeadadh MP4 ar siúl…",
        L"Sábháladh an taifeadadh.",
        L"Níorbh fhéidir taifeadadh MP4 a thosú.",
        L"Níor suiteáladh an spárálaí scáileáin.",
        L"Suiteáladh an spárálaí scáileáin.",
        L"Níorbh fhéidir an rindreálaí Direct3D a thúsú.",
        IRISH_EFFECTS
    }, LocalizedText{
        L"Lietuvių",
        L"SpaceFlight — valdymas",
        L"SpaceFlight nuostatos",
        L"Kalba:",
        L"Animacijos greitis: %d %%",
        L"Pasirinktų monitorių skrydis",
        L"Įjungti visus",
        L"Išjungti visus",
        L"Animacijos monitorius",
        L"Monitorius",
        L"Skiriamoji geba",
        L"Padėtis",
        L"pagrindinis",
        L"OK",
        L"Atšaukti",
        L"Pradėti įrašymą…",
        L"Baigti įrašymą",
        L"Pristabdyti",
        L"Tęsti",
        L"Įdiegti ekrano užsklandą",
        L"Išeiti",
        L"Animacija vyksta…",
        L"Vyksta MP4 įrašymas…",
        L"Įrašas išsaugotas.",
        L"Nepavyko pradėti MP4 įrašymo.",
        L"Ekrano užsklanda neįdiegta.",
        L"Ekrano užsklanda įdiegta.",
        L"Nepavyko inicijuoti Direct3D atvaizdavimo modulio.",
        LITHUANIAN_EFFECTS
    }, LocalizedText{
        L"Latviešu",
        L"SpaceFlight — vadība",
        L"SpaceFlight iestatījumi",
        L"Valoda:",
        L"Animācijas ātrums: %d %%",
        L"Atlasīto monitoru lidojums",
        L"Ieslēgt visu",
        L"Izslēgt visu",
        L"Animācijas monitors",
        L"Monitors",
        L"Izšķirtspēja",
        L"Pozīcija",
        L"galvenais",
        L"OK",
        L"Atcelt",
        L"Sākt ierakstīšanu…",
        L"Beigt ierakstīšanu",
        L"Pauzēt",
        L"Turpināt",
        L"Instalēt ekrānsaudzētāju",
        L"Iziet",
        L"Animācija darbojas…",
        L"Notiek MP4 ierakstīšana…",
        L"Ieraksts ir saglabāts.",
        L"Neizdevās sākt MP4 ierakstīšanu.",
        L"Ekrānsaudzētājs netika instalēts.",
        L"Ekrānsaudzētājs ir instalēts.",
        L"Neizdevās inicializēt Direct3D renderētāju.",
        LATVIAN_EFFECTS
    }, LocalizedText{
        L"Magyar",
        L"SpaceFlight — vezérlés",
        L"SpaceFlight beállításai",
        L"Nyelv:",
        L"Animáció sebessége: %d %%",
        L"Kijelölt monitorok repülési módja",
        L"Mind bekapcsolása",
        L"Mind kikapcsolása",
        L"Animációs monitor",
        L"Monitor",
        L"Felbontás",
        L"Pozíció",
        L"elsődleges",
        L"OK",
        L"Mégse",
        L"Felvétel indítása…",
        L"Felvétel leállítása",
        L"Szünet",
        L"Folytatás",
        L"Képernyőkímélő telepítése",
        L"Kilépés",
        L"Az animáció fut…",
        L"MP4-felvétel folyamatban…",
        L"A felvétel mentve.",
        L"Az MP4-felvétel nem indítható.",
        L"A képernyőkímélő nem lett telepítve.",
        L"A képernyőkímélő telepítve.",
        L"A Direct3D megjelenítő inicializálása sikertelen.",
        HUNGARIAN_EFFECTS
    }, LocalizedText{
        L"Malti",
        L"SpaceFlight — kontrolli",
        L"Settings ta’ SpaceFlight",
        L"Lingwa:",
        L"Veloċità tal-animazzjoni: %d %%",
        L"Titjira tal-moniters magħżula",
        L"Attiva kollox",
        L"Iddiżattiva kollox",
        L"Moniter tal-animazzjoni",
        L"Moniter",
        L"Riżoluzzjoni",
        L"Pożizzjoni",
        L"primarju",
        L"OK",
        L"Ikkanċella",
        L"Ibda r-reġistrazzjoni…",
        L"Waqqaf ir-reġistrazzjoni",
        L"Issospendi",
        L"Kompli",
        L"Installa l-iscreen saver",
        L"Oħroġ",
        L"L-animazzjoni għaddejja…",
        L"Reġistrazzjoni MP4 għaddejja…",
        L"Ir-reġistrazzjoni ġiet issejvjata.",
        L"Ma setgħetx tinbeda r-reġistrazzjoni MP4.",
        L"L-iscreen saver ma ġiex installat.",
        L"L-iscreen saver ġie installat.",
        L"Ma setax jiġi inizjalizzat ir-renderer Direct3D.",
        MALTESE_EFFECTS
    }, LocalizedText{
        L"Nederlands",
        L"SpaceFlight — bediening",
        L"Instellingen van SpaceFlight",
        L"Taal:",
        L"Animatiesnelheid: %d %%",
        L"Vlucht op geselecteerde beeldschermen",
        L"Alles inschakelen",
        L"Alles uitschakelen",
        L"Animatiebeeldscherm",
        L"Beeldscherm",
        L"Resolutie",
        L"Positie",
        L"primair",
        L"OK",
        L"Annuleren",
        L"Opname starten…",
        L"Opname stoppen",
        L"Pauzeren",
        L"Hervatten",
        L"Schermbeveiliging installeren",
        L"Afsluiten",
        L"Animatie wordt uitgevoerd…",
        L"MP4-opname wordt gemaakt…",
        L"De opname is opgeslagen.",
        L"De MP4-opname kon niet worden gestart.",
        L"De schermbeveiliging is niet geïnstalleerd.",
        L"De schermbeveiliging is geïnstalleerd.",
        L"De Direct3D-renderer kon niet worden geïnitialiseerd.",
        DUTCH_EFFECTS
    }, LocalizedText{
        L"Română",
        L"SpaceFlight — comenzi",
        L"Setări SpaceFlight",
        L"Limbă:",
        L"Viteza animației: %d %%",
        L"Zbor pe monitoarele selectate",
        L"Activare toate",
        L"Dezactivare toate",
        L"Monitor de animație",
        L"Monitor",
        L"Rezoluție",
        L"Poziție",
        L"principal",
        L"OK",
        L"Anulare",
        L"Pornire înregistrare…",
        L"Oprire înregistrare",
        L"Pauză",
        L"Reluare",
        L"Instalare economizor de ecran",
        L"Ieșire",
        L"Animația rulează…",
        L"Înregistrare MP4 în curs…",
        L"Înregistrarea a fost salvată.",
        L"Înregistrarea MP4 nu a putut fi pornită.",
        L"Economizorul de ecran nu a fost instalat.",
        L"Economizorul de ecran a fost instalat.",
        L"Modulul de randare Direct3D nu a putut fi inițializat.",
        ROMANIAN_EFFECTS
    }, LocalizedText{
        L"Ελληνικά",
        L"SpaceFlight — χειρισμός",
        L"Ρυθμίσεις SpaceFlight",
        L"Γλώσσα:",
        L"Ταχύτητα κίνησης: %d %%",
        L"Πτήση στις επιλεγμένες οθόνες",
        L"Ενεργοποίηση όλων",
        L"Απενεργοποίηση όλων",
        L"Οθόνη κίνησης",
        L"Οθόνη",
        L"Ανάλυση",
        L"Θέση",
        L"κύρια",
        L"OK",
        L"Άκυρο",
        L"Έναρξη εγγραφής…",
        L"Διακοπή εγγραφής",
        L"Παύση",
        L"Συνέχιση",
        L"Εγκατάσταση προφύλαξης οθόνης",
        L"Έξοδος",
        L"Η κίνηση εκτελείται…",
        L"Εγγραφή MP4 σε εξέλιξη…",
        L"Η εγγραφή αποθηκεύτηκε.",
        L"Δεν ήταν δυνατή η έναρξη εγγραφής MP4.",
        L"Η προφύλαξη οθόνης δεν εγκαταστάθηκε.",
        L"Η προφύλαξη οθόνης εγκαταστάθηκε.",
        L"Δεν ήταν δυνατή η αρχικοποίηση του αποδότη Direct3D.",
        GREEK_EFFECTS
    }, LocalizedText{
        L"Bosanski",
        L"SpaceFlight — kontrole",
        L"Postavke programa SpaceFlight",
        L"Jezik:",
        L"Brzina animacije: %d %%",
        L"Let na odabranim monitorima",
        L"Uključi sve",
        L"Isključi sve",
        L"Monitor animacije",
        L"Monitor",
        L"Rezolucija",
        L"Položaj",
        L"primarni",
        L"OK",
        L"Otkaži",
        L"Pokreni snimanje…",
        L"Zaustavi snimanje",
        L"Pauziraj",
        L"Nastavi",
        L"Instaliraj čuvar ekrana",
        L"Izlaz",
        L"Animacija je pokrenuta…",
        L"MP4 snimanje je u toku…",
        L"Snimak je sačuvan.",
        L"Nije moguće pokrenuti MP4 snimanje.",
        L"Čuvar ekrana nije instaliran.",
        L"Čuvar ekrana je instaliran.",
        L"Nije moguće inicijalizirati Direct3D prikazivač.",
        BOSNIAN_EFFECTS
    }, LocalizedText{
        L"Hrvatski",
        L"SpaceFlight — upravljanje",
        L"Postavke programa SpaceFlight",
        L"Jezik:",
        L"Brzina animacije: %d %%",
        L"Let na odabranim zaslonima",
        L"Uključi sve",
        L"Isključi sve",
        L"Zaslon animacije",
        L"Zaslon",
        L"Razlučivost",
        L"Položaj",
        L"primarni",
        L"OK",
        L"Odustani",
        L"Pokreni snimanje…",
        L"Zaustavi snimanje",
        L"Pauziraj",
        L"Nastavi",
        L"Instaliraj čuvar zaslona",
        L"Izlaz",
        L"Animacija je pokrenuta…",
        L"MP4 snimanje je u tijeku…",
        L"Snimka je spremljena.",
        L"Nije moguće pokrenuti MP4 snimanje.",
        L"Čuvar zaslona nije instaliran.",
        L"Čuvar zaslona je instaliran.",
        L"Nije moguće inicijalizirati Direct3D prikazivač.",
        CROATIAN_EFFECTS
    }, LocalizedText{
        L"Slovenščina",
        L"SpaceFlight — upravljanje",
        L"Nastavitve SpaceFlight",
        L"Jezik:",
        L"Hitrost animacije: %d %%",
        L"Let na izbranih zaslonih",
        L"Vklopi vse",
        L"Izklopi vse",
        L"Zaslon animacije",
        L"Zaslon",
        L"Ločljivost",
        L"Položaj",
        L"glavni",
        L"OK",
        L"Prekliči",
        L"Začni snemanje…",
        L"Ustavi snemanje",
        L"Premor",
        L"Nadaljuj",
        L"Namesti ohranjevalnik zaslona",
        L"Izhod",
        L"Animacija se izvaja…",
        L"Snemanje MP4 poteka…",
        L"Posnetek je shranjen.",
        L"Snemanja MP4 ni bilo mogoče začeti.",
        L"Ohranjevalnik zaslona ni nameščen.",
        L"Ohranjevalnik zaslona je nameščen.",
        L"Upodabljalnika Direct3D ni bilo mogoče inicializirati.",
        SLOVENIAN_EFFECTS
    }, LocalizedText{
        L"Crnogorski",
        L"SpaceFlight — kontrole",
        L"Podešavanja programa SpaceFlight",
        L"Jezik:",
        L"Brzina animacije: %d %%",
        L"Let na izabranim monitorima",
        L"Uključi sve",
        L"Isključi sve",
        L"Monitor animacije",
        L"Monitor",
        L"Rezolucija",
        L"Položaj",
        L"primarni",
        L"OK",
        L"Otkaži",
        L"Pokreni snimanje…",
        L"Zaustavi snimanje",
        L"Pauziraj",
        L"Nastavi",
        L"Instaliraj čuvar ekrana",
        L"Izlaz",
        L"Animacija je pokrenuta…",
        L"MP4 snimanje je u toku…",
        L"Snimak je sačuvan.",
        L"Nije moguće pokrenuti MP4 snimanje.",
        L"Čuvar ekrana nije instaliran.",
        L"Čuvar ekrana je instaliran.",
        L"Nije moguće inicijalizovati Direct3D prikazivač.",
        MONTENEGRIN_EFFECTS
    }, LocalizedText{
        L"Беларуская",
        L"SpaceFlight — кіраванне",
        L"Налады SpaceFlight",
        L"Мова:",
        L"Хуткасць анімацыі: %d %%",
        L"Палёт на выбраных маніторах",
        L"Уключыць усё",
        L"Выключыць усё",
        L"Манітор анімацыі",
        L"Манітор",
        L"Раздзяляльнасць",
        L"Пазіцыя",
        L"асноўны",
        L"OK",
        L"Скасаваць",
        L"Пачаць запіс…",
        L"Спыніць запіс",
        L"Прыпыніць",
        L"Працягнуць",
        L"Усталяваць застаўку",
        L"Выйсці",
        L"Анімацыя працуе…",
        L"Ідзе запіс MP4…",
        L"Запіс захаваны.",
        L"Не ўдалося пачаць запіс MP4.",
        L"Застаўка не ўсталявана.",
        L"Застаўка ўсталявана.",
        L"Не ўдалося ініцыялізаваць візуалізатар Direct3D.",
        BELARUSIAN_EFFECTS
    }, LocalizedText{
        L"Български",
        L"SpaceFlight — управление",
        L"Настройки на SpaceFlight",
        L"Език:",
        L"Скорост на анимацията: %d %%",
        L"Полет на избраните монитори",
        L"Включване на всички",
        L"Изключване на всички",
        L"Монитор за анимацията",
        L"Монитор",
        L"Разделителна способност",
        L"Позиция",
        L"основен",
        L"OK",
        L"Отказ",
        L"Начало на запис…",
        L"Спиране на записа",
        L"Пауза",
        L"Продължаване",
        L"Инсталиране на скрийнсейвъра",
        L"Изход",
        L"Анимацията се изпълнява…",
        L"Извършва се MP4 запис…",
        L"Записът е запазен.",
        L"Неуспешно стартиране на MP4 запис.",
        L"Скрийнсейвърът не е инсталиран.",
        L"Скрийнсейвърът е инсталиран.",
        L"Неуспешно инициализиране на Direct3D визуализатора.",
        BULGARIAN_EFFECTS
    }, LocalizedText{
        L"Македонски",
        L"SpaceFlight — контроли",
        L"Поставки за SpaceFlight",
        L"Јазик:",
        L"Брзина на анимацијата: %d %%",
        L"Лет на избраните монитори",
        L"Вклучи ги сите",
        L"Исклучи ги сите",
        L"Монитор за анимација",
        L"Монитор",
        L"Резолуција",
        L"Положба",
        L"примарен",
        L"OK",
        L"Откажи",
        L"Започни снимање…",
        L"Запри снимање",
        L"Паузирај",
        L"Продолжи",
        L"Инсталирај чувар на екранот",
        L"Излез",
        L"Анимацијата се извршува…",
        L"MP4 снимање е во тек…",
        L"Снимката е зачувана.",
        L"Не може да започне MP4 снимање.",
        L"Чуварот на екранот не е инсталиран.",
        L"Чуварот на екранот е инсталиран.",
        L"Не може да се иницијализира Direct3D прикажувачот.",
        MACEDONIAN_EFFECTS
    }, LocalizedText{
        L"Српски",
        L"SpaceFlight — контроле",
        L"Подешавања програма SpaceFlight",
        L"Језик:",
        L"Брзина анимације: %d %%",
        L"Лет на изабраним мониторима",
        L"Укључи све",
        L"Искључи све",
        L"Монитор анимације",
        L"Монитор",
        L"Резолуција",
        L"Положај",
        L"примарни",
        L"OK",
        L"Откажи",
        L"Покрени снимање…",
        L"Заустави снимање",
        L"Паузирај",
        L"Настави",
        L"Инсталирај чувар екрана",
        L"Излаз",
        L"Анимација је покренута…",
        L"MP4 снимање је у току…",
        L"Снимак је сачуван.",
        L"Није могуће покренути MP4 снимање.",
        L"Чувар екрана није инсталиран.",
        L"Чувар екрана је инсталиран.",
        L"Није могуће иницијализовати Direct3D приказивач.",
        SERBIAN_EFFECTS
    }, LocalizedText{
        L"Українська",
        L"SpaceFlight — керування",
        L"Налаштування SpaceFlight",
        L"Мова:",
        L"Швидкість анімації: %d %%",
        L"Політ на вибраних моніторах",
        L"Увімкнути все",
        L"Вимкнути все",
        L"Монітор анімації",
        L"Монітор",
        L"Роздільна здатність",
        L"Розташування",
        L"основний",
        L"OK",
        L"Скасувати",
        L"Почати запис…",
        L"Зупинити запис",
        L"Призупинити",
        L"Продовжити",
        L"Установити заставку",
        L"Вийти",
        L"Анімація працює…",
        L"Триває запис MP4…",
        L"Запис збережено.",
        L"Не вдалося почати запис MP4.",
        L"Заставку не встановлено.",
        L"Заставку встановлено.",
        L"Не вдалося ініціалізувати візуалізатор Direct3D.",
        UKRAINIAN_EFFECTS
    }, LocalizedText{
        L"Русский",
        L"SpaceFlight — управление",
        L"Настройки SpaceFlight",
        L"Язык:",
        L"Скорость анимации: %d %%",
        L"Полёт на выбранных мониторах",
        L"Включить всё",
        L"Выключить всё",
        L"Монитор анимации",
        L"Монитор",
        L"Разрешение",
        L"Расположение",
        L"основной",
        L"OK",
        L"Отмена",
        L"Начать запись…",
        L"Остановить запись",
        L"Приостановить",
        L"Продолжить",
        L"Установить заставку",
        L"Выход",
        L"Анимация работает…",
        L"Идёт запись MP4…",
        L"Запись сохранена.",
        L"Не удалось начать запись MP4.",
        L"Заставка не установлена.",
        L"Заставка установлена.",
        L"Не удалось инициализировать визуализатор Direct3D.",
        RUSSIAN_EFFECTS
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
    }, MonitorColumnText{
        L"Monitor model",
        L"Refresh rate",
        L"Bit depth",
        L"Color format",
        L"Color space",
        L"%u bits/channel",
        L"%u bits/pixel"
    }, MonitorColumnText{
        L"Monitor model",
        L"Refresh rate",
        L"Bit depth",
        L"Colour format",
        L"Colour space",
        L"%u bits/channel",
        L"%u bits/pixel"
    }, MonitorColumnText{
        L"Monitor model",
        L"Refresh rate",
        L"Bit depth",
        L"Colour format",
        L"Colour space",
        L"%u bits/channel",
        L"%u bits/pixel"
    }, MonitorColumnText{
        L"Monitormodell",
        L"Bildwiederholfrequenz",
        L"Bittiefe",
        L"Farbformat",
        L"Farbraum",
        L"%u Bit/Kanal",
        L"%u Bit/Pixel"
    }, MonitorColumnText{
        L"Modèle du moniteur",
        L"Fréquence de rafraîchissement",
        L"Profondeur de bits",
        L"Format de couleur",
        L"Espace colorimétrique",
        L"%u bits/canal",
        L"%u bits/pixel"
    }, MonitorColumnText{
        L"Modelo del monitor",
        L"Frecuencia de actualización",
        L"Profundidad de bits",
        L"Formato de color",
        L"Espacio de color",
        L"%u bits/canal",
        L"%u bits/píxel"
    }, MonitorColumnText{
        L"Modello del monitor",
        L"Frequenza di aggiornamento",
        L"Profondità di bit",
        L"Formato colore",
        L"Spazio colore",
        L"%u bit/canale",
        L"%u bit/pixel"
    }, MonitorColumnText{
        L"Modelo do monitor",
        L"Taxa de atualização",
        L"Profundidade de bits",
        L"Formato de cor",
        L"Espaço de cor",
        L"%u bits/canal",
        L"%u bits/píxel"
    }, MonitorColumnText{
        L"Model monitora",
        L"Częstotliwość odświeżania",
        L"Głębia bitowa",
        L"Format koloru",
        L"Przestrzeń barw",
        L"%u bitów/kanał",
        L"%u bitów/piksel"
    }, MonitorColumnText{
        L"Model monitora",
        L"Obnovovacia frekvencia",
        L"Bitová hĺbka",
        L"Formát farby",
        L"Farebný priestor",
        L"%u bitov/kanál",
        L"%u bitov/pixel"
    }, MonitorColumnText{
        L"Skærmmodel",
        L"Opdateringsfrekvens",
        L"Bitdybde",
        L"Farveformat",
        L"Farverum",
        L"%u bit/kanal",
        L"%u bit/pixel"
    }, MonitorColumnText{
        L"Näytön malli",
        L"Virkistystaajuus",
        L"Bittisyvyys",
        L"Värimuoto",
        L"Väriavaruus",
        L"%u bittiä/kanava",
        L"%u bittiä/pikseli"
    }, MonitorColumnText{
        L"Gerð skjás",
        L"Endurnýjunartíðni",
        L"Bitadýpt",
        L"Litasnið",
        L"Litarými",
        L"%u bitar/rás",
        L"%u bitar/myndpunktur"
    }, MonitorColumnText{
        L"Skjermmodell",
        L"Oppdateringsfrekvens",
        L"Bitdybde",
        L"Fargeformat",
        L"Fargerom",
        L"%u bit/kanal",
        L"%u bit/piksel"
    }, MonitorColumnText{
        L"Skärmmodell",
        L"Uppdateringsfrekvens",
        L"Bitdjup",
        L"Färgformat",
        L"Färgrymd",
        L"%u bitar/kanal",
        L"%u bitar/pixel"
    }, MonitorColumnText{
        L"Monitör modeli",
        L"Yenileme hızı",
        L"Bit derinliği",
        L"Renk biçimi",
        L"Renk alanı",
        L"%u bit/kanal",
        L"%u bit/piksel"
    }, MonitorColumnText{
        L"Kuvari mudel",
        L"Värskendussagedus",
        L"Bitisügavus",
        L"Värvivorming",
        L"Värviruum",
        L"%u bitti/kanal",
        L"%u bitti/piksel"
    }, MonitorColumnText{
        L"Samhail an mhonatóra",
        L"Ráta athnuachana",
        L"Doimhneacht ghiotán",
        L"Formáid datha",
        L"Spás datha",
        L"%u giotán/cainéal",
        L"%u giotán/picteilín"
    }, MonitorColumnText{
        L"Monitoriaus modelis",
        L"Atnaujinimo dažnis",
        L"Bitų gylis",
        L"Spalvų formatas",
        L"Spalvų erdvė",
        L"%u bitų/kanalą",
        L"%u bitų/pikselį"
    }, MonitorColumnText{
        L"Monitora modelis",
        L"Atsvaidzināšanas frekvence",
        L"Bitu dziļums",
        L"Krāsu formāts",
        L"Krāstelpa",
        L"%u biti/kanālā",
        L"%u biti/pikselī"
    }, MonitorColumnText{
        L"Monitor típusa",
        L"Frissítési gyakoriság",
        L"Bitmélység",
        L"Színformátum",
        L"Színtér",
        L"%u bit/csatorna",
        L"%u bit/képpont"
    }, MonitorColumnText{
        L"Mudell tal-moniter",
        L"Rata ta’ aġġornament",
        L"Fond tal-bits",
        L"Format tal-kulur",
        L"Spazju tal-kulur",
        L"%u bits/kanal",
        L"%u bits/pixel"
    }, MonitorColumnText{
        L"Beeldschermmodel",
        L"Vernieuwingsfrequentie",
        L"Bitdiepte",
        L"Kleurindeling",
        L"Kleurruimte",
        L"%u bits/kanaal",
        L"%u bits/pixel"
    }, MonitorColumnText{
        L"Model monitor",
        L"Rată de reîmprospătare",
        L"Adâncime de biți",
        L"Format de culoare",
        L"Spațiu de culoare",
        L"%u biți/canal",
        L"%u biți/pixel"
    }, MonitorColumnText{
        L"Μοντέλο οθόνης",
        L"Ρυθμός ανανέωσης",
        L"Βάθος bit",
        L"Μορφή χρώματος",
        L"Χρωματικός χώρος",
        L"%u bit/κανάλι",
        L"%u bit/pixel"
    }, MonitorColumnText{
        L"Model monitora",
        L"Frekvencija osvježavanja",
        L"Dubina bita",
        L"Format boje",
        L"Prostor boja",
        L"%u bita/kanal",
        L"%u bita/piksel"
    }, MonitorColumnText{
        L"Model zaslona",
        L"Frekvencija osvježavanja",
        L"Dubina bita",
        L"Oblik boje",
        L"Prostor boja",
        L"%u bita/kanal",
        L"%u bita/piksel"
    }, MonitorColumnText{
        L"Model zaslona",
        L"Hitrost osveževanja",
        L"Bitna globina",
        L"Oblika barv",
        L"Barvni prostor",
        L"%u bitov/kanal",
        L"%u bitov/slikovno piko"
    }, MonitorColumnText{
        L"Model monitora",
        L"Frekvencija osvježavanja",
        L"Dubina bita",
        L"Format boje",
        L"Prostor boja",
        L"%u bita/kanal",
        L"%u bita/piksel"
    }, MonitorColumnText{
        L"Мадэль манітора",
        L"Частата абнаўлення",
        L"Бітавая глыбіня",
        L"Фармат колеру",
        L"Каляровая прастора",
        L"%u біт/канал",
        L"%u біт/піксель"
    }, MonitorColumnText{
        L"Модел на монитора",
        L"Честота на опресняване",
        L"Битова дълбочина",
        L"Формат на цветовете",
        L"Цветово пространство",
        L"%u бита/канал",
        L"%u бита/пиксел"
    }, MonitorColumnText{
        L"Модел на мониторот",
        L"Стапка на освежување",
        L"Битна длабочина",
        L"Формат на боја",
        L"Простор на бои",
        L"%u бита/канал",
        L"%u бита/пиксел"
    }, MonitorColumnText{
        L"Модел монитора",
        L"Учестаност освежавања",
        L"Дубина бита",
        L"Формат боје",
        L"Простор боја",
        L"%u бита/канал",
        L"%u бита/пиксел"
    }, MonitorColumnText{
        L"Модель монітора",
        L"Частота оновлення",
        L"Бітова глибина",
        L"Формат кольору",
        L"Колірний простір",
        L"%u біт/канал",
        L"%u біт/піксель"
    }, MonitorColumnText{
        L"Модель монитора",
        L"Частота обновления",
        L"Глубина цвета",
        L"Формат цвета",
        L"Цветовое пространство",
        L"%u бит/канал",
        L"%u бит/пиксель"
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
    L"Önizlemeyi aç",
    L"Luba eelvaade",
    L"Cumasaigh réamhamharc",
    L"Įjungti peržiūrą",
    L"Ieslēgt priekšskatījumu",
    L"Előnézet bekapcsolása",
    L"Attiva l-previżjoni",
    L"Voorbeeld inschakelen",
    L"Activare previzualizare",
    L"Ενεργοποίηση προεπισκόπησης",
    L"Uključi pregled",
    L"Uključi pretpregled",
    L"Vklopi predogled",
    L"Uključi pregled",
    L"Уключыць перадпрагляд",
    L"Включване на прегледа",
    L"Вклучи преглед",
    L"Укључи преглед",
    L"Увімкнути попередній перегляд",
    L"Включить предпросмотр"
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
    L"Önizlemeyi kapat",
    L"Keela eelvaade",
    L"Díchumasaigh réamhamharc",
    L"Išjungti peržiūrą",
    L"Izslēgt priekšskatījumu",
    L"Előnézet kikapcsolása",
    L"Iddiżattiva l-previżjoni",
    L"Voorbeeld uitschakelen",
    L"Dezactivare previzualizare",
    L"Απενεργοποίηση προεπισκόπησης",
    L"Isključi pregled",
    L"Isključi pretpregled",
    L"Izklopi predogled",
    L"Isključi pregled",
    L"Выключыць перадпрагляд",
    L"Изключване на прегледа",
    L"Исклучи преглед",
    L"Искључи преглед",
    L"Вимкнути попередній перегляд",
    L"Выключить предпросмотр"
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
    L"Animasyon sırasında ekran koruyucuyu engelle",
    L"Tõkesta animatsiooni ajal ekraanisäästja",
    L"Cosc ar spárálaí scáileáin le linn beochana",
    L"Animacijos metu neleisti ekrano užsklandos",
    L"Animācijas laikā bloķēt ekrānsaudzētāju",
    L"Képernyőkímélő tiltása animáció közben",
    L"Imblokka l-iscreen saver waqt l-animazzjoni",
    L"Schermbeveiliging blokkeren tijdens animatie",
    L"Blocare economizor în timpul animației",
    L"Αναστολή προφύλαξης οθόνης κατά την κίνηση",
    L"Spriječi čuvar ekrana tokom animacije",
    L"Spriječi čuvar zaslona tijekom animacije",
    L"Prepreči ohranjevalnik med animacijo",
    L"Spriječi čuvar ekrana tokom animacije",
    L"Блакаваць застаўку падчас анімацыі",
    L"Блокиране на скрийнсейвъра при анимация",
    L"Блокирај го чуварот за време на анимацијата",
    L"Спречи чувар екрана током анимације",
    L"Блокувати заставку під час анімації",
    L"Блокировать заставку во время анимации"
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
    L"Hazır.",
    L"Valmis.",
    L"Réidh.",
    L"Parengta.",
    L"Gatavs.",
    L"Kész.",
    L"Lest.",
    L"Gereed.",
    L"Pregătit.",
    L"Έτοιμο.",
    L"Spreman.",
    L"Spreman.",
    L"Pripravljen.",
    L"Spreman.",
    L"Гатовы.",
    L"Готов.",
    L"Подготвен.",
    L"Спреман.",
    L"Готовий.",
    L"Готов."
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
    L"Animasyon duraklatıldı.",
    L"Animatsioon on peatatud.",
    L"Tá an bheochan ar sos.",
    L"Animacija pristabdyta.",
    L"Animācija ir pauzēta.",
    L"Az animáció szünetel.",
    L"L-animazzjoni tinsab sospiża.",
    L"Animatie is gepauzeerd.",
    L"Animația este în pauză.",
    L"Η κίνηση έχει παύσει.",
    L"Animacija je pauzirana.",
    L"Animacija je pauzirana.",
    L"Animacija je začasno ustavljena.",
    L"Animacija je pauzirana.",
    L"Анімацыя прыпынена.",
    L"Анимацията е на пауза.",
    L"Анимацијата е паузирана.",
    L"Анимација је паузирана.",
    L"Анімацію призупинено.",
    L"Анимация приостановлена."
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
    L"Yardım",
    L"Spikker",
    L"Cabhair",
    L"Žinynas",
    L"Palīdzība",
    L"Súgó",
    L"Għajnuna",
    L"Help",
    L"Ajutor",
    L"Βοήθεια",
    L"Pomoć",
    L"Pomoć",
    L"Pomoč",
    L"Pomoć",
    L"Даведка",
    L"Помощ",
    L"Помош",
    L"Помоћ",
    L"Довідка",
    L"Справка"
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
    L"Hakkında",
    L"Teave",
    L"Maidir leis",
    L"Apie",
    L"Par programmu",
    L"Névjegy",
    L"Dwar",
    L"Info",
    L"Despre",
    L"Πληροφορίες",
    L"O programu",
    L"O programu",
    L"O programu",
    L"O programu",
    L"Пра праграму",
    L"За програмата",
    L"За програмата",
    L"О програму",
    L"Про програму",
    L"О программе"
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
    L"Sürüm:",
    L"Versioon:",
    L"Leagan:",
    L"Versija:",
    L"Versija:",
    L"Verzió:",
    L"Verżjoni:",
    L"Versie:",
    L"Versiune:",
    L"Έκδοση:",
    L"Verzija:",
    L"Verzija:",
    L"Različica:",
    L"Verzija:",
    L"Версія:",
    L"Версия:",
    L"Верзија:",
    L"Верзија:",
    L"Версія:",
    L"Версия:"
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
    L"Hedef platform:",
    L"Sihtplatvorm:",
    L"Sprioc-ardán:",
    L"Tikslinė platforma:",
    L"Mērķa platforma:",
    L"Célplatform:",
    L"Pjattaforma fil-mira:",
    L"Doelplatform:",
    L"Platformă țintă:",
    L"Πλατφόρμα προορισμού:",
    L"Ciljna platforma:",
    L"Ciljna platforma:",
    L"Ciljna platforma:",
    L"Ciljna platforma:",
    L"Мэтавая платформа:",
    L"Целева платформа:",
    L"Целна платформа:",
    L"Циљна платформа:",
    L"Цільова платформа:",
    L"Целевая платформа:"
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
    L"Web sitesi:",
    L"Veebisait:",
    L"Suíomh gréasáin:",
    L"Svetainė:",
    L"Tīmekļa vietne:",
    L"Webhely:",
    L"Sit web:",
    L"Website:",
    L"Site web:",
    L"Τοποθεσία web:",
    L"Web-mjesto:",
    L"Web-mjesto:",
    L"Spletno mesto:",
    L"Veb-sajt:",
    L"Вэб-сайт:",
    L"Уебсайт:",
    L"Веб-страница:",
    L"Веб-сајт:",
    L"Вебсайт:",
    L"Веб-сайт:"
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
    L"Varsayılan tarayıcıda &aç",
    L"&Ava vaikebrauseris",
    L"&Oscail sa bhrabhsálaí réamhshocraithe",
    L"&Atidaryti numatytojoje naršyklėje",
    L"&Atvērt noklusējuma pārlūkprogrammā",
    L"&Megnyitás az alapértelmezett böngészőben",
    L"&Iftaħ fil-brawżer default",
    L"&Openen in standaardbrowser",
    L"&Deschidere în browserul implicit",
    L"&Άνοιγμα στο προεπιλεγμένο πρόγραμμα περιήγησης",
    L"&Otvori u podrazumijevanom pregledniku",
    L"&Otvori u zadanom pregledniku",
    L"&Odpri v privzetem brskalniku",
    L"&Otvori u podrazumijevanom pregledaču",
    L"&Адкрыць у прадвызначаным браўзеры",
    L"&Отвори в браузъра по подразбиране",
    L"&Отвори во стандардниот прелистувач",
    L"&Отвори у подразумеваном прегледачу",
    L"&Відкрити в типовому браузері",
    L"&Открыть в браузере по умолчанию"
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
    L"&URL'yi kopyala",
    L"Kopeeri &aadress",
    L"Cóipeáil an &seoladh",
    L"Kopijuoti &adresą",
    L"Kopēt &adresi",
    L"&Cím másolása",
    L"Ikkopja l-&indirizz",
    L"&Adres kopiëren",
    L"Copiere &adresă",
    L"Αντιγραφή &διεύθυνσης",
    L"Kopiraj &adresu",
    L"Kopiraj &adresu",
    L"Kopiraj &naslov",
    L"Kopiraj &adresu",
    L"Капіяваць &адрас",
    L"Копирай &адреса",
    L"Копирај ја &адресата",
    L"Копирај &адресу",
    L"Копіювати &адресу",
    L"Копировать &адрес"
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
    L"&Bilgileri kopyala",
    L"Kopeeri &teave",
    L"Cóipeáil an &fhaisnéis",
    L"Kopijuoti &informaciją",
    L"Kopēt &informāciju",
    L"&Információ másolása",
    L"Ikkopja l-&informazzjoni",
    L"&Informatie kopiëren",
    L"Copiere &informații",
    L"Αντιγραφή &πληροφοριών",
    L"Kopiraj &informacije",
    L"Kopiraj &informacije",
    L"Kopiraj &podatke",
    L"Kopiraj &podatke",
    L"Капіяваць &звесткі",
    L"Копирай &информацията",
    L"Копирај ги &информациите",
    L"Копирај &податке",
    L"Копіювати &відомості",
    L"Копировать &сведения"
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
    L"Kapat",
    L"Sule",
    L"Dún",
    L"Uždaryti",
    L"Aizvērt",
    L"Bezárás",
    L"Agħlaq",
    L"Sluiten",
    L"Închidere",
    L"Κλείσιμο",
    L"Zatvori",
    L"Zatvori",
    L"Zapri",
    L"Zatvori",
    L"Закрыць",
    L"Затвори",
    L"Затвори",
    L"Затвори",
    L"Закрити",
    L"Закрыть"
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
    L"Anlık görüntü…",
    L"Salvesta PNG…",
    L"Sábháil PNG…",
    L"Išsaugoti PNG…",
    L"Saglabāt PNG…",
    L"PNG mentése…",
    L"Issejvja PNG…",
    L"PNG opslaan…",
    L"Salvare PNG…",
    L"Αποθήκευση PNG…",
    L"Sačuvaj PNG…",
    L"Spremi PNG…",
    L"Shrani PNG…",
    L"Sačuvaj PNG…",
    L"Захаваць PNG…",
    L"Запис на PNG…",
    L"Зачувај PNG…",
    L"Сачувај PNG…",
    L"Зберегти PNG…",
    L"Сохранить PNG…"
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
    L"Anlık görüntü kaydedildi.",
    L"PNG-pilt on salvestatud.",
    L"Sábháladh an íomhá PNG.",
    L"PNG vaizdas išsaugotas.",
    L"PNG attēls ir saglabāts.",
    L"A PNG-kép mentve.",
    L"L-immaġni PNG ġiet issejvjata.",
    L"De PNG-afbeelding is opgeslagen.",
    L"Imaginea PNG a fost salvată.",
    L"Η εικόνα PNG αποθηκεύτηκε.",
    L"PNG slika je sačuvana.",
    L"PNG slika je spremljena.",
    L"Slika PNG je shranjena.",
    L"PNG slika je sačuvana.",
    L"Відарыс PNG захаваны.",
    L"PNG изображението е запазено.",
    L"PNG сликата е зачувана.",
    L"PNG слика је сачувана.",
    L"Зображення PNG збережено.",
    L"Изображение PNG сохранено."
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
    L"Anlık görüntü kaydedilemedi.",
    L"PNG-pilti ei saanud salvestada.",
    L"Níorbh fhéidir an íomhá PNG a shábháil.",
    L"Nepavyko išsaugoti PNG vaizdo.",
    L"Neizdevās saglabāt PNG attēlu.",
    L"A PNG-kép mentése sikertelen.",
    L"Ma setgħetx tiġi ssejvjata l-immaġni PNG.",
    L"De PNG-afbeelding kon niet worden opgeslagen.",
    L"Imaginea PNG nu a putut fi salvată.",
    L"Δεν ήταν δυνατή η αποθήκευση της εικόνας PNG.",
    L"Nije moguće sačuvati PNG sliku.",
    L"Nije moguće spremiti PNG sliku.",
    L"Slike PNG ni bilo mogoče shraniti.",
    L"Nije moguće sačuvati PNG sliku.",
    L"Не ўдалося захаваць відарыс PNG.",
    L"PNG изображението не може да се запази.",
    L"PNG сликата не може да се зачува.",
    L"Није могуће сачувати PNG слику.",
    L"Не вдалося зберегти зображення PNG.",
    L"Не удалось сохранить изображение PNG."
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
    L"Ekran koruyucuyu kaldır",
    L"Eemalda ekraanisäästja",
    L"Díshuiteáil spárálaí scáileáin",
    L"Pašalinti ekrano užsklandą",
    L"Atinstalēt ekrānsaudzētāju",
    L"Képernyőkímélő eltávolítása",
    L"Neħħi l-iscreen saver",
    L"Schermbeveiliging verwijderen",
    L"Dezinstalare economizor de ecran",
    L"Κατάργηση προφύλαξης οθόνης",
    L"Deinstaliraj čuvar ekrana",
    L"Deinstaliraj čuvar zaslona",
    L"Odstrani ohranjevalnik zaslona",
    L"Deinstaliraj čuvar ekrana",
    L"Выдаліць застаўку",
    L"Деинсталиране на скрийнсейвъра",
    L"Деинсталирај чувар на екранот",
    L"Деинсталирај чувар екрана",
    L"Видалити заставку",
    L"Удалить заставку"
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
    L"Ekran koruyucu kaldırıldı.",
    L"Ekraanisäästja on eemaldatud.",
    L"Díshuiteáladh an spárálaí scáileáin.",
    L"Ekrano užsklanda pašalinta.",
    L"Ekrānsaudzētājs ir atinstalēts.",
    L"A képernyőkímélő eltávolítva.",
    L"L-iscreen saver tneħħa.",
    L"De schermbeveiliging is verwijderd.",
    L"Economizorul de ecran a fost dezinstalat.",
    L"Η προφύλαξη οθόνης καταργήθηκε.",
    L"Čuvar ekrana je deinstaliran.",
    L"Čuvar zaslona je deinstaliran.",
    L"Ohranjevalnik zaslona je odstranjen.",
    L"Čuvar ekrana je deinstaliran.",
    L"Застаўка выдалена.",
    L"Скрийнсейвърът е деинсталиран.",
    L"Чуварот на екранот е деинсталиран.",
    L"Чувар екрана је деинсталиран.",
    L"Заставку видалено.",
    L"Заставка удалена."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALLATION_FAILED_TEXTS = {
    L"Odinstalace se nezdařila. Pokud je spořič nebo jeho náhled spuštěný, zavřete jej a odinstalaci "
    L"zopakujte.",
    L"The screen saver could not be uninstalled. If the screen saver or its preview is running, close it "
    L"and try again.",
    L"The screen saver could not be uninstalled. If the screen saver or its preview is running, close it "
    L"and try again.",
    L"The screen saver could not be uninstalled. If the screen saver or its preview is running, close it "
    L"and try again.",
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
    L"Nie udało się odinstalować wygaszacza. Jeśli wygaszacz lub jego podgląd jest uruchomiony, zamknij go "
    L"i spróbuj ponownie.",
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
    L"Skärmsläckaren kunde inte avinstalleras. Om skärmsläckaren eller förhandsvisningen körs, stäng den "
    L"och försök igen.",
    L"Ekran koruyucu kaldırılamadı. Ekran koruyucu veya önizlemesi çalışıyorsa kapatıp yeniden deneyin.",
    L"Ekraanisäästjat ei saanud eemaldada. Sulgege ekraanisäästja ja selle eelvaade ning proovige uuesti.",
    L"Níorbh fhéidir an spárálaí scáileáin a dhíshuiteáil. Dún é agus a réamhamharc agus bain triail eile "
    L"as.",
    L"Nepavyko pašalinti ekrano užsklandos. Uždarykite ją bei jos peržiūrą ir bandykite dar kartą.",
    L"Neizdevās atinstalēt ekrānsaudzētāju. Aizveriet to un tā priekšskatījumu un mēģiniet vēlreiz.",
    L"A képernyőkímélő nem távolítható el. Zárja be a képernyőkímélőt és az előnézetét, majd próbálja újra.",
    L"Ma setax jitneħħa l-iscreen saver. Agħlaq l-iscreen saver u l-previżjoni tiegħu u erġa’ pprova.",
    L"De schermbeveiliging kon niet worden verwijderd. Sluit de schermbeveiliging en het voorbeeld en "
    L"probeer het opnieuw.",
    L"Economizorul de ecran nu a putut fi dezinstalat. Închideți-l împreună cu previzualizarea și încercați "
    L"din nou.",
    L"Δεν ήταν δυνατή η κατάργηση της προφύλαξης οθόνης. Κλείστε την και την προεπισκόπησή της και "
    L"δοκιμάστε ξανά.",
    L"Nije moguće deinstalirati čuvar ekrana. Zatvorite čuvar i njegov pregled pa pokušajte ponovo.",
    L"Nije moguće deinstalirati čuvar zaslona. Zatvorite čuvar i njegov pretpregled pa pokušajte ponovno.",
    L"Ohranjevalnika zaslona ni bilo mogoče odstraniti. Zaprite ga in njegov predogled ter poskusite znova.",
    L"Nije moguće deinstalirati čuvar ekrana. Zatvorite čuvar i njegov pregled pa pokušajte ponovo.",
    L"Не ўдалося выдаліць застаўку. Закрыйце яе і перадпрагляд ды паўтарыце спробу.",
    L"Скрийнсейвърът не може да се деинсталира. Затворете го и неговия преглед и опитайте отново.",
    L"Чуварот на екранот не може да се деинсталира. Затворете го него и неговиот преглед и обидете се "
    L"повторно.",
    L"Није могуће деинсталирати чувар екрана. Затворите чувар и његов преглед па покушајте поново.",
    L"Не вдалося видалити заставку. Закрийте заставку та її попередній перегляд і спробуйте ще раз.",
    L"Не удалось удалить заставку. Закройте заставку и её предпросмотр и повторите попытку."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALLATION_BLOCKED_BY_SETTINGS_TEXTS = {
    L"Odinstalace se nezdařila, protože je otevřené nastavení SpaceFlight. Zavřete je a odinstalaci "
    L"zopakujte.",
    L"Uninstallation failed because SpaceFlight settings are open. Close the settings window and try again.",
    L"Uninstallation failed because SpaceFlight settings are open. Close the settings window and try again.",
    L"Uninstallation failed because SpaceFlight settings are open. Close the settings window and try again.",
    L"Die Deinstallation ist fehlgeschlagen, weil die SpaceFlight-Einstellungen geöffnet sind. Schließen "
    L"Sie das Fenster und versuchen Sie es erneut.",
    L"La désinstallation a échoué car les paramètres de SpaceFlight sont ouverts. Fermez cette fenêtre puis "
    L"réessayez.",
    L"La desinstalación falló porque la configuración de SpaceFlight está abierta. Cierre esa ventana e "
    L"inténtelo de nuevo.",
    L"La disinstallazione non è riuscita perché le impostazioni di SpaceFlight sono aperte. Chiudere la "
    L"finestra e riprovare.",
    L"A desinstalação falhou porque as definições do SpaceFlight estão abertas. Feche a janela e tente "
    L"novamente.",
    L"Odinstalowanie nie powiodło się, ponieważ ustawienia SpaceFlight są otwarte. Zamknij okno i spróbuj "
    L"ponownie.",
    L"Odinštalovanie zlyhalo, pretože sú otvorené nastavenia SpaceFlight. Zatvorte ich a skúste to znova.",
    L"Afinstallationen mislykkedes, fordi indstillingerne for SpaceFlight er åbne. Luk vinduet, og prøv "
    L"igen.",
    L"Asennuksen poisto epäonnistui, koska SpaceFlight-asetukset ovat avoinna. Sulje ikkuna ja yritä "
    L"uudelleen.",
    L"Fjarlæging mistókst vegna þess að stillingar SpaceFlight eru opnar. Lokaðu glugganum og reyndu aftur.",
    L"Avinstalleringen mislyktes fordi innstillingene for SpaceFlight er åpne. Lukk vinduet og prøv på nytt.",
    L"Avinstallationen misslyckades eftersom inställningarna för SpaceFlight är öppna. Stäng fönstret och "
    L"försök igen.",
    L"SpaceFlight ayarları açık olduğu için kaldırma başarısız oldu. Ayarlar penceresini kapatıp yeniden "
    L"deneyin.",
    L"Sulgege SpaceFlight sätete aken ja proovige eemaldamist uuesti.",
    L"Dún fuinneog socruithe SpaceFlight agus bain triail eile as an díshuiteáil.",
    L"Uždarykite SpaceFlight nuostatų langą ir bandykite pašalinti dar kartą.",
    L"Aizveriet SpaceFlight iestatījumu logu un atkārtojiet atinstalēšanu.",
    L"Zárja be a SpaceFlight beállítási ablakát, majd próbálja újra az eltávolítást.",
    L"Agħlaq it-tieqa tas-settings ta’ SpaceFlight u erġa’ pprova tneħħih.",
    L"Sluit de instellingen van SpaceFlight en probeer het verwijderen opnieuw.",
    L"Închideți fereastra de setări SpaceFlight și încercați din nou dezinstalarea.",
    L"Κλείστε το παράθυρο ρυθμίσεων του SpaceFlight και δοκιμάστε ξανά την κατάργηση.",
    L"Zatvorite postavke programa SpaceFlight pa ponovite deinstalaciju.",
    L"Zatvorite postavke programa SpaceFlight pa ponovite deinstalaciju.",
    L"Zaprite nastavitve SpaceFlight in znova poskusite odstranitev.",
    L"Zatvorite podešavanja programa SpaceFlight pa ponovite deinstalaciju.",
    L"Закрыйце налады SpaceFlight ды паўтарыце выдаленне.",
    L"Затворете настройките на SpaceFlight и опитайте деинсталирането отново.",
    L"Затворете ги поставките за SpaceFlight и обидете се повторно да деинсталирате.",
    L"Затворите подешавања програма SpaceFlight па поновите деинсталацију.",
    L"Закрийте налаштування SpaceFlight та повторіть видалення.",
    L"Закройте настройки SpaceFlight и повторите удаление."
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
    L"wygaszacza ekranu i spróbuj ponownie.",
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
    L"yeniden deneyin.",
    L"Sulgege Windowsi ekraanisäästja sätete aken ja proovige eemaldamist uuesti.",
    L"Dún fuinneog socruithe spárálaí scáileáin Windows agus bain triail eile as an díshuiteáil.",
    L"Uždarykite Windows ekrano užsklandos nuostatų langą ir bandykite pašalinti dar kartą.",
    L"Aizveriet Windows ekrānsaudzētāja iestatījumu logu un atkārtojiet atinstalēšanu.",
    L"Zárja be a Windows képernyőkímélő-beállításait, majd próbálja újra az eltávolítást.",
    L"Agħlaq it-tieqa tas-settings tal-iscreen saver ta’ Windows u erġa’ pprova tneħħih.",
    L"Sluit de instellingen voor schermbeveiliging van Windows en probeer het verwijderen opnieuw.",
    L"Închideți setările economizorului de ecran Windows și încercați din nou dezinstalarea.",
    L"Κλείστε τις ρυθμίσεις προφύλαξης οθόνης των Windows και δοκιμάστε ξανά την κατάργηση.",
    L"Zatvorite Windows postavke čuvara ekrana pa ponovite deinstalaciju.",
    L"Zatvorite Windows postavke čuvara zaslona pa ponovite deinstalaciju.",
    L"Zaprite nastavitve ohranjevalnika zaslona Windows in znova poskusite odstranitev.",
    L"Zatvorite Windows podešavanja čuvara ekrana pa ponovite deinstalaciju.",
    L"Закрыйце акно налад застаўкі Windows ды паўтарыце выдаленне.",
    L"Затворете настройките на скрийнсейвъра на Windows и опитайте деинсталирането отново.",
    L"Затворете ги поставките за чуварот на екранот на Windows и обидете се повторно.",
    L"Затворите Windows подешавања чувара екрана па поновите деинсталацију.",
    L"Закрийте налаштування заставки Windows та повторіть видалення.",
    L"Закройте настройки заставки Windows и повторите удаление."
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
    L"Échap ou en déplaçant la souris, puis réessayez.",
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
    L"hareket ettirerek çıkıp yeniden deneyin.",
    L"Sulgege ekraanisäästja või täisekraanieelvaade klahviga Esc või hiire liigutamisega ja proovige "
    L"eemaldamist uuesti.",
    L"Dún an spárálaí scáileáin nó an réamhamharc lánscáileáin le Esc nó trí an luch a bhogadh agus bain "
    L"triail eile as.",
    L"Užbaikite užsklandą arba viso ekrano peržiūrą klavišu Esc ar pajudindami pelę ir bandykite pašalinti "
    L"dar kartą.",
    L"Aizveriet ekrānsaudzētāju vai pilnekrāna priekšskatījumu ar Esc vai peles kustību un atkārtojiet "
    L"atinstalēšanu.",
    L"Lépjen ki a képernyőkímélőből vagy a teljes képernyős előnézetből az Esc billentyűvel vagy az egér "
    L"mozgatásával, majd próbálja újra.",
    L"Agħlaq l-iscreen saver jew il-previżjoni fuq skrin sħiħ b’Esc jew billi ċċaqlaq il-maws u erġa’ "
    L"pprova.",
    L"Sluit de schermbeveiliging of het schermvullende voorbeeld met Esc of door de muis te bewegen en "
    L"probeer het opnieuw.",
    L"Închideți economizorul sau previzualizarea pe tot ecranul cu Esc ori mișcând mouse-ul și încercați "
    L"din nou.",
    L"Κλείστε την προφύλαξη ή την προεπισκόπηση πλήρους οθόνης με Esc ή κίνηση του ποντικιού και δοκιμάστε "
    L"ξανά.",
    L"Zatvorite čuvar ili pregled preko cijelog ekrana tipkom Esc ili pomjeranjem miša pa ponovite "
    L"deinstalaciju.",
    L"Zatvorite čuvar ili pretpregled preko cijelog zaslona tipkom Esc ili pomicanjem miša pa ponovite "
    L"deinstalaciju.",
    L"Zaprite ohranjevalnik ali celozaslonski predogled s tipko Esc ali premikom miške in znova poskusite "
    L"odstranitev.",
    L"Zatvorite čuvar ili pregled preko cijelog ekrana tasterom Esc ili pomjeranjem miša pa ponovite "
    L"deinstalaciju.",
    L"Завяршыце застаўку або поўнаэкранны перадпрагляд клавішай Esc ці рухам мышы ды паўтарыце выдаленне.",
    L"Спрете скрийнсейвъра или прегледа на цял екран с Esc или движение на мишката и опитайте отново.",
    L"Затворете го чуварот или прегледот на цел екран со Esc или со движење на глувчето и обидете се "
    L"повторно.",
    L"Затворите чувар или преглед преко целог екрана тастером Esc или померањем миша па поновите "
    L"деинсталацију.",
    L"Завершіть заставку або повноекранний попередній перегляд клавішею Esc чи рухом миші та повторіть "
    L"видалення.",
    L"Завершите заставку или полноэкранный предпросмотр клавишей Esc либо движением мыши и повторите "
    L"удаление."
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
    L"Uygulamayı kapatmak devam eden kaydı durduracaktır.",
    L"Rakenduse sulgemine lõpetab käimasoleva salvestamise.",
    L"Stopfar an taifeadadh atá ar siúl má dhúntar an feidhmchlár.",
    L"Uždarius programą bus sustabdytas vykstantis įrašymas.",
    L"Aizverot lietotni, tiks pārtraukts pašreizējais ieraksts.",
    L"Az alkalmazás bezárítása leállítja a folyamatban lévő felvételt.",
    L"L-għeluq tal-applikazzjoni jwaqqaf ir-reġistrazzjoni li tkun għaddejja.",
    L"Als u de toepassing sluit, wordt de huidige opname gestopt.",
    L"Închiderea aplicației va opri înregistrarea în curs.",
    L"Το κλείσιμο της εφαρμογής θα διακόψει την εγγραφή που βρίσκεται σε εξέλιξη.",
    L"Zatvaranje aplikacije zaustavit će snimanje koje je u toku.",
    L"Zatvaranje aplikacije zaustavit će snimanje koje je u tijeku.",
    L"Zapiranje programa bo ustavilo trenutno snemanje.",
    L"Zatvaranje aplikacije zaustaviće snimanje koje je u toku.",
    L"Закрыццё праграмы спыніць бягучы запіс.",
    L"Затварянето на приложението ще спре текущия запис.",
    L"Затворањето на апликацијата ќе го запре снимањето што е во тек.",
    L"Затварање апликације зауставиће снимање које је у току.",
    L"Закриття програми зупинить поточний запис.",
    L"Закрытие приложения остановит текущую запись."
};

/// Localized recording-settings captions.
constexpr std::array<RecordingText, LANGUAGE_COUNT> RECORDING_TEXTS = {
    RecordingText{
        L"Nastavení záznamu",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Rozlišení:",
        L"Snímková frekvence:",
        L"Změny se použijí při příštím záznamu MP4."
    }, RecordingText{
        L"Recording settings",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Resolution:",
        L"Frame rate:",
        L"Changes apply to the next MP4 recording."
    }, RecordingText{
        L"Recording settings",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Resolution:",
        L"Frame rate:",
        L"Changes apply to the next MP4 recording."
    }, RecordingText{
        L"Recording settings",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Resolution:",
        L"Frame rate:",
        L"Changes apply to the next MP4 recording."
    }, RecordingText{
        L"Aufnahmeeinstellungen",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Auflösung:",
        L"Bildfrequenz:",
        L"Änderungen gelten für die nächste MP4-Aufnahme."
    }, RecordingText{
        L"Réglages vidéo",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Résolution :",
        L"Fréquence d’images :",
        L"Les modifications s’appliquent au prochain enregistrement MP4."
    }, RecordingText{
        L"Ajustes de grabación",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Resolución:",
        L"Frecuencia de imagen:",
        L"Los cambios se aplican a la próxima grabación MP4."
    }, RecordingText{
        L"Impostazioni video",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Risoluzione:",
        L"Frequenza fotogrammi:",
        L"Le modifiche si applicano alla prossima registrazione MP4."
    }, RecordingText{
        L"Definições de gravação",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Resolução:",
        L"Frequência de imagens:",
        L"As alterações aplicam-se à próxima gravação MP4."
    }, RecordingText{
        L"Ustawienia nagrywania",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Rozdzielczość:",
        L"Liczba klatek/s:",
        L"Zmiany dotyczą następnego nagrania MP4."
    }, RecordingText{
        L"Nastavenie záznamu",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Rozlíšenie:",
        L"Snímková frekvencia:",
        L"Zmeny sa použijú pri nasledujúcom zázname MP4."
    }, RecordingText{
        L"Optagelsesindstillinger",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Opløsning:",
        L"Billedfrekvens:",
        L"Ændringerne gælder næste MP4-optagelse."
    }, RecordingText{
        L"Tallennusasetukset",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Tarkkuus:",
        L"Kuvataajuus:",
        L"Muutokset koskevat seuraavaa MP4-tallennusta."
    }, RecordingText{
        L"Upptökustillingar",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Upplausn:",
        L"Rammatíðni:",
        L"Breytingarnar gilda fyrir næstu MP4-upptöku."
    }, RecordingText{
        L"Opptaksinnstillinger",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Oppløsning:",
        L"Bildefrekvens:",
        L"Endringene gjelder neste MP4-opptak."
    }, RecordingText{
        L"Inspelningsinställningar",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Upplösning:",
        L"Bildfrekvens:",
        L"Ändringarna gäller nästa MP4-inspelning."
    }, RecordingText{
        L"Kayıt ayarları",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Çözünürlük:",
        L"Kare hızı:",
        L"Değişiklikler bir sonraki MP4 kaydına uygulanır."
    }, RecordingText{
        L"Salvestussätted",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Eraldusvõime:",
        L"Kaadrisagedus:",
        L"Muudatused rakenduvad järgmisele MP4 salvestusele."
    }, RecordingText{
        L"Socruithe taifeadta",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Taifeach:",
        L"Ráta frámaí:",
        L"Cuirfear na hathruithe i bhfeidhm ar an gcéad taifeadadh MP4 eile."
    }, RecordingText{
        L"Įrašymo nuostatos",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Skiriamoji geba:",
        L"Kadrų dažnis:",
        L"Pakeitimai bus taikomi kitam MP4 įrašui."
    }, RecordingText{
        L"Ieraksta iestatījumi",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Izšķirtspēja:",
        L"Kadru ātrums:",
        L"Izmaiņas attieksies uz nākamo MP4 ierakstu."
    }, RecordingText{
        L"Felvételi beállítások",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Felbontás:",
        L"Képkockasebesség:",
        L"A módosítások a következő MP4-felvételre érvényesek."
    }, RecordingText{
        L"Settings tar-reġistrazzjoni",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Riżoluzzjoni:",
        L"Rata tal-frejms:",
        L"Il-bidliet japplikaw għar-reġistrazzjoni MP4 li jmiss."
    }, RecordingText{
        L"Opname-instellingen",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Resolutie:",
        L"Framesnelheid:",
        L"Wijzigingen gelden voor de volgende MP4-opname."
    }, RecordingText{
        L"Setări de înregistrare",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Rezoluție:",
        L"Frecvența cadrelor:",
        L"Modificările se aplică următoarei înregistrări MP4."
    }, RecordingText{
        L"Ρυθμίσεις εγγραφής",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Ανάλυση:",
        L"Ρυθμός καρέ:",
        L"Οι αλλαγές ισχύουν για την επόμενη εγγραφή MP4."
    }, RecordingText{
        L"Postavke snimanja",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Rezolucija:",
        L"Broj kadrova u sekundi:",
        L"Promjene se primjenjuju na sljedeće MP4 snimanje."
    }, RecordingText{
        L"Postavke snimanja",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Razlučivost:",
        L"Broj sličica u sekundi:",
        L"Promjene se primjenjuju na sljedeće MP4 snimanje."
    }, RecordingText{
        L"Nastavitve snemanja",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Ločljivost:",
        L"Hitrost sličic:",
        L"Spremembe veljajo za naslednje snemanje MP4."
    }, RecordingText{
        L"Podešavanja snimanja",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Rezolucija:",
        L"Broj kadrova u sekundi:",
        L"Promjene se primjenjuju na sljedeće MP4 snimanje."
    }, RecordingText{
        L"Налады запісу",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Раздзяляльнасць:",
        L"Частата кадраў:",
        L"Змены будуць ужытыя да наступнага запісу MP4."
    }, RecordingText{
        L"Настройки на записа",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Разделителна способност:",
        L"Кадрова честота:",
        L"Промените се прилагат към следващия MP4 запис."
    }, RecordingText{
        L"Поставки за снимање",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Резолуција:",
        L"Број кадри во секунда:",
        L"Промените важат за следното MP4 снимање."
    }, RecordingText{
        L"Подешавања снимања",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Резолуција:",
        L"Број кадрова у секунди:",
        L"Промене се примењују на следеће MP4 снимање."
    }, RecordingText{
        L"Налаштування запису",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Роздільна здатність:",
        L"Частота кадрів:",
        L"Зміни буде застосовано до наступного запису MP4."
    }, RecordingText{
        L"Настройки записи",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Разрешение:",
        L"Частота кадров:",
        L"Изменения применяются к следующей записи MP4."
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
    L"ANIMACE A NASTAVENÍ\r\nSpaceFlight: Nekonečná vlnící se plocha; Dálkový let — proměnlivá plocha. "
    L"Každému monitoru přiřaďte právě jednu animaci. Textura přepíná mezi texturovanými plochami a drátěným "
    L"modelem. Volná rotace kamery pomalu mění směr pohledu ve všech třech rozměrech. Volba „Pauzy a "
    L"obraty“ přidává náhodné zpomalování, pauzy a změny směru otáčení; dopředný pohyb pokračuje. Rychlost "
    L"animace je 0–1600 %. Každý monitor má nezávislou náhodnou scénu a vykreslování podle své obnovovací "
    L"frekvence. Hlavní světlo, doplňkové světlo, základní jas a přisvětlení obrysů lze pro označené "
    L"monitory zapínat nezávisle. Osvětlení se používá jen u texturovaných ploch. U obou animací lze zvolit "
    L"rovinu, zvlnění nebo trychtýř. Trychtýř vtahuje kameru dovnitř po sestupné "
    L"spirále.\r\n\r\nMONITORY\r\nOznačení řádků určuje, "
    L"které monitory právě nastavujete; není totožné se zatržítky zapínajícími animační výstupy. Ctrl+A "
    L"označí všechny monitory, Ctrl a Shift umožňují upravit označení. Všechny animační volby a jezdce "
    L"platí pro označené monitory. Označení se pamatuje zvlášť pro EXE a SCR. Pokud byly označené všechny "
    L"monitory, označí se i nově připojené. Různé hodnoty na označených monitorech ukazuje neurčitý stav "
    L"zatržítek a tečkování přepínačů, úchytů jezdců a tlačítek pro zapnutí či vypnutí všech voleb. Popisek "
    L"jezdce místo společné hodnoty zobrazuje pomlčku. Změna volby nebo kliknutí na jezdec sjednotí "
    L"příslušnou hodnotu na označených monitorech.\r\n\r\nOVLÁDÁNÍ\r\nAnimační výstupy zapnete nebo vypnete "
    L"zatržítky u monitorů nebo dvojklikem na jejich řádky. Každý monitor používá nezávislou scénu. Snímek "
    L"ukládá PNG, tlačítko záznamu spouští a ukončuje MP4. Pozastavení zastaví animaci. Aplikace také "
    L"instaluje nebo odinstaluje zabalený spořič. Nastavení se ukládá průběžně. Aplikace běží pouze v jedné "
    L"instanci. Další spuštění obnoví minimalizované ovládací okno a přenese do popředí. Mezi ovládacími "
    L"prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a příslušného "
    L"písmene. Esc zavře aktivní nápovědu či okno O aplikaci; v ovládacím okně ukončí aplikaci. Pozastavení "
    L"a blokování spořiče platí pro celou aplikaci bez ohledu na označené monitory. Je-li blokování "
    L"zapnuté, brání spuštění spořiče Windows pouze tehdy, když je alespoň na jednom monitoru viditelná "
    L"nepozastavená animace.\r\n\r\nSNÍMKY A ZÁZNAM\r\nSnímek a záznam zachycují první aktivní animační "
    L"monitor, nikoli společnou plochu všech monitorů. PNG používá složku Obrázky, MP4 složku Videa; při "
    L"jejich neexistenci se použijí Dokumenty. Tlačítko Nastavení záznamu vybírá Viewport nebo TV. Viewport "
    L"zachovává rozměry animačního monitoru a jeho obnovovací frekvenci, nejvýše 60 snímků za sekundu. TV "
    L"nabízí rozlišení 1920 × 1080, 1440 × 1080 nebo 1280 × 720 v poměru 16:9 a frekvenci 50, 25, 59.94 "
    L"(60000/1001) nebo 29.97 (30000/1001) snímků za sekundu. Obraz zachovává poměr stran; TV používá "
    L"progresivní video BT.709 s omezeným rozsahem a vzorkováním 4:2:0. Rozlišení a snímkovou frekvenci lze "
    L"vybrat pouze v režimu TV. Okno Nastavení záznamu lze minimalizovat a neblokuje ostatní okna aplikace. "
    L"OK uloží volby pro příští záznam MP4; Storno nebo Esc nepotvrzené změny zahodí. Nahrávaný monitor "
    L"nelze během záznamu odepnout; změny ostatních monitorů záznam nezastaví. Ukončení aplikace při "
    L"probíhajícím záznamu vyžaduje potvrzení, protože současně ukončí záznam.\r\n\r\nSYSTÉMOVÉ "
    L"POŽADAVKY\r\nWindows 7 až Windows 11 podporují všechny funkce včetně snímků PNG a záznamu MP4. Pro "
    L"spuštění aplikace ve Windows Vista SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917. Záznam "
    L"MP4 na Vistě v současné verzi nefunguje. Vykreslování vyžaduje Direct3D 11, nikoli jen starší DirectX "
    L"runtime. Záznam MP4 vyžaduje dostupné součásti Media Foundation a kodér H.264.",
    L"ANIMATION AND SETTINGS\r\nSpaceFlight: Infinite undulating surface; Long-distance flight — morphing "
    L"surface. Assign exactly one animation to each display. Texture switches between textured surfaces and "
    L"wireframe. Free camera rotation slowly changes the viewing direction in all three dimensions. The "
    L"Pauses and reversals option adds randomized braking, pauses, and reversals of the rotation; forward "
    L"flight continues. Animation speed ranges from 0–1600%. Every display has an independent randomized "
    L"scene rendered at its own refresh rate. Main light, fill light, ambient light, and rim light can be "
    L"switched independently for the selected displays. Lighting applies only to textured surfaces. Both "
    L"animations offer Plane, Waves, or Funnel. Funnel draws the camera inward along a descending "
    L"spiral.\r\n\r\nDISPLAYS\r\nRow "
    L"selection determines which displays you are editing; it is separate from the checkboxes that enable "
    L"animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation "
    L"options and sliders apply to the selected displays. The selection is remembered separately for EXE "
    L"and SCR. If all displays were selected, newly connected displays join the selection. Different values "
    L"across selected displays are indicated by indeterminate checkboxes and dotted radio buttons, slider "
    L"thumbs, and buttons for enabling or disabling all options. Slider labels show a dash instead of a "
    L"shared value. Changing an option or clicking a slider applies that value to all selected "
    L"displays.\r\n\r\nCONTROLS\r\nEnable or disable animation outputs using the display checkboxes or by "
    L"double-clicking their rows. Every display uses an independent scene. Snapshot saves a PNG and the "
    L"recording button starts or stops an MP4. Pause stops the animation. The application also installs or "
    L"uninstalls its embedded screen saver. Settings are saved continuously. Only one instance of the "
    L"application runs at a time. Launching it again restores its minimized control window and brings it to "
    L"the foreground. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to "
    L"activate a command. Esc closes the active Help or About window; in the control window, it exits the "
    L"application. Pause and screen-saver blocking apply to the whole application, regardless of display "
    L"selection. When blocking is enabled, the Windows screen saver is prevented only while unpaused "
    L"animation is visible on at least one display.\r\n\r\nSNAPSHOTS AND RECORDING\r\nSnapshots and "
    L"recordings capture the first active animation display, not a combined image of all displays. PNG uses "
    L"Pictures and MP4 uses Videos, with Documents as the fallback if those folders do not exist. The "
    L"Recording settings button selects Viewport or TV. Viewport preserves the animation display’s "
    L"dimensions and refresh rate, up to 60 frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × "
    L"720 output in 16:9, with 50, 25, 59.94 (60000/1001) or 29.97 (30000/1001) frames per second. The "
    L"image keeps its aspect ratio; TV uses progressive BT.709 limited-range 4:2:0 video. Resolution and "
    L"frame rate are available only in TV mode. The Recording settings window can be minimized and does not "
    L"block the other application windows. OK saves choices for the next MP4 recording; Cancel or Esc "
    L"discards unconfirmed changes. The recorded display cannot be detached during recording; changes to "
    L"other displays do not stop the recording. Closing the application while recording requires "
    L"confirmation because it also stops the recording.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows 7 through "
    L"Windows 11 support all features, including PNG snapshots and MP4 recording. To run the application on "
    L"Windows Vista SP2, you must install updates KB971512 and KB2117917. MP4 recording does not work on "
    L"Vista in the current version. Rendering requires Direct3D 11, not just an older DirectX runtime. MP4 "
    L"recording requires available Media Foundation components and an H.264 encoder.",
    L"ANIMATION AND SETTINGS\r\nSpaceFlight: Infinite undulating surface; Long-distance flight — morphing "
    L"surface. Assign exactly one animation to each display. Texture switches between textured surfaces and "
    L"wireframe. Free camera rotation slowly changes the viewing direction in all three dimensions. The "
    L"Pauses and reversals option adds randomised braking, pauses and reversals of the rotation; forward "
    L"flight continues. Animation speed ranges from 0–1600%. Every display has an independent randomised "
    L"scene rendered at its own refresh rate. Main light, fill light, ambient light and rim light can be "
    L"switched independently for the selected displays. Lighting applies only to textured surfaces. Both "
    L"animations offer Plane, Waves, or Funnel. Funnel draws the camera inward along a descending "
    L"spiral.\r\n\r\nDISPLAYS\r\nRow "
    L"selection determines which displays you are editing; it is separate from the checkboxes that enable "
    L"animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation "
    L"options and sliders apply to the selected displays. The selection is remembered separately for EXE "
    L"and SCR. If all displays were selected, newly connected displays join the selection. Different values "
    L"across selected displays are indicated by indeterminate checkboxes and dotted radio buttons, slider "
    L"thumbs and buttons for enabling or disabling all options. Slider labels show a dash instead of a "
    L"shared value. Changing an option or clicking a slider applies that value to all selected "
    L"displays.\r\n\r\nCONTROLS\r\nEnable or disable animation outputs using the display checkboxes or by "
    L"double-clicking their rows. Each display uses an independent scene. Snapshot saves PNG and the "
    L"recording button starts or stops MP4. Pause stops the animation. The application also installs or "
    L"uninstalls its embedded screen saver. Settings are saved continuously. Only one instance of the "
    L"application runs at a time. Launching it again restores its minimised control window and brings it to "
    L"the foreground. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to "
    L"activate a command. Esc closes the active Help or About window; in the control window, it exits the "
    L"application. Pause and screen-saver blocking apply to the whole application, regardless of display "
    L"selection. When blocking is enabled, the Windows screen saver is prevented only while unpaused "
    L"animation is visible on at least one display.\r\n\r\nSNAPSHOTS AND RECORDING\r\nSnapshots and "
    L"recordings capture the first active animation display, not a combined image of all displays. PNG uses "
    L"Pictures and MP4 uses Videos, with Documents as the fallback if those folders do not exist. The "
    L"Recording settings button selects Viewport or TV. Viewport preserves the animation display’s "
    L"dimensions and refresh rate, up to 60 frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × "
    L"720 output in 16:9, with 50, 25, 59.94 (60000/1001) or 29.97 (30000/1001) frames per second. The "
    L"image keeps its aspect ratio; TV uses progressive BT.709 limited-range 4:2:0 video. Resolution and "
    L"frame rate are available only in TV mode. The Recording settings window can be minimised and does not "
    L"block the other application windows. OK saves choices for the next MP4 recording; Cancel or Esc "
    L"discards unconfirmed changes. The recorded display cannot be detached during recording; changes to "
    L"other displays do not stop the recording. Closing the application while recording requires "
    L"confirmation because it also stops the recording.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows 7 through "
    L"Windows 11 support all features, including PNG snapshots and MP4 recording. To run the application on "
    L"Windows Vista SP2, you must install updates KB971512 and KB2117917. MP4 recording does not work on "
    L"Vista in the current version. Rendering requires Direct3D 11, not just an older DirectX runtime. MP4 "
    L"recording requires available Media Foundation components and an H.264 encoder.",
    L"ANIMATION AND SETTINGS\r\nSpaceFlight: Infinite undulating surface; Long-distance flight — morphing "
    L"surface. Assign exactly one animation to each display. Texture switches between textured surfaces and "
    L"wireframe. Free camera rotation slowly changes the viewing direction in all three dimensions. The "
    L"Pauses and reversals option adds randomised braking, pauses and reversals of the rotation; forward "
    L"flight continues. Animation speed ranges from 0–1600%. Every display has an independent randomised "
    L"scene rendered at its own refresh rate. Main light, fill light, ambient light and rim light can be "
    L"switched independently for the selected displays. Lighting applies only to textured surfaces. Both "
    L"animations offer Plane, Waves, or Funnel. Funnel draws the camera inward along a descending "
    L"spiral.\r\n\r\nDISPLAYS\r\nRow "
    L"selection determines which displays you are editing; it is separate from the checkboxes that enable "
    L"animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation "
    L"options and sliders apply to the selected displays. The selection is remembered separately for EXE "
    L"and SCR. If all displays were selected, newly connected displays join the selection. Different values "
    L"across selected displays are indicated by indeterminate checkboxes and dotted radio buttons, slider "
    L"thumbs and buttons for enabling or disabling all options. Slider labels show a dash instead of a "
    L"shared value. Changing an option or clicking a slider applies that value to all selected "
    L"displays.\r\n\r\nCONTROLS\r\nEnable or disable animation outputs using the display checkboxes or by "
    L"double-clicking their rows. Each display uses an independent scene. Snapshot saves PNG and the "
    L"recording button starts or stops MP4. Pause stops the animation. The application also installs or "
    L"uninstalls its embedded screen saver. Settings are saved continuously. Only one instance of the "
    L"application runs at a time. Launching it again restores its minimised control window and brings it to "
    L"the foreground. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to "
    L"activate a command. Esc closes the active Help or About window; in the control window, it exits the "
    L"application. Pause and screen-saver blocking apply to the whole application, regardless of display "
    L"selection. When blocking is enabled, the Windows screen saver is prevented only while unpaused "
    L"animation is visible on at least one display.\r\n\r\nSNAPSHOTS AND RECORDING\r\nSnapshots and "
    L"recordings capture the first active animation display, not a combined image of all displays. PNG uses "
    L"Pictures and MP4 uses Videos, with Documents as the fallback if those folders do not exist. The "
    L"Recording settings button selects Viewport or TV. Viewport preserves the animation display’s "
    L"dimensions and refresh rate, up to 60 frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × "
    L"720 output in 16:9, with 50, 25, 59.94 (60000/1001) or 29.97 (30000/1001) frames per second. The "
    L"image keeps its aspect ratio; TV uses progressive BT.709 limited-range 4:2:0 video. Resolution and "
    L"frame rate are available only in TV mode. The Recording settings window can be minimised and does not "
    L"block the other application windows. OK saves choices for the next MP4 recording; Cancel or Esc "
    L"discards unconfirmed changes. The recorded display cannot be detached during recording; changes to "
    L"other displays do not stop the recording. Closing the application while recording requires "
    L"confirmation because it also stops the recording.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows 7 through "
    L"Windows 11 support all features, including PNG snapshots and MP4 recording. To run the application on "
    L"Windows Vista SP2, you must install updates KB971512 and KB2117917. MP4 recording does not work on "
    L"Vista in the current version. Rendering requires Direct3D 11, not just an older DirectX runtime. MP4 "
    L"recording requires available Media Foundation components and an H.264 encoder.",
    L"ANIMATION UND EINSTELLUNGEN\r\nSpaceFlight: Unendliche wellenförmige Fläche; Fernflug — veränderliche "
    L"Fläche. Weisen Sie jedem Monitor genau eine Animation zu. Textur wechselt zwischen texturierten "
    L"Flächen und Drahtgittermodell. Die freie Kameradrehung verändert die Blickrichtung langsam in allen "
    L"drei Dimensionen. Die Option „Pausen und Umkehr“ ergänzt zufälliges Abbremsen, Pausen und Wechsel der "
    L"Drehrichtung; der Vorwärtsflug läuft weiter. Die Animationsgeschwindigkeit beträgt 0–1600 %. Jeder "
    L"Monitor besitzt eine unabhängige zufällige Szene und wird mit seiner eigenen Bildwiederholrate "
    L"angesteuert. Hauptlicht, Fülllicht, Umgebungslicht und Konturlicht lassen sich für die ausgewählten "
    L"Monitore unabhängig schalten. Die Beleuchtung gilt nur für texturierte Flächen. Beide Animationen "
    L"bieten Ebene, Wellen oder Trichter. Im Trichter bewegt sich die Kamera auf einer absteigenden Spirale "
    L"nach innen.\r\n\r\nMONITORE\r\nDie Zeilenauswahl bestimmt, welche Monitore Sie bearbeiten; sie ist "
    L"von "
    L"den Kontrollkästchen zum Einschalten der Animationsausgabe getrennt. Strg+A wählt alle Monitore, Strg "
    L"und Umschalt ändern die Auswahl. Alle Animationsoptionen und Regler gelten für die ausgewählten "
    L"Monitore. Die Auswahl wird für EXE und SCR getrennt gespeichert. Waren alle Monitore ausgewählt, "
    L"werden auch neu angeschlossene ausgewählt. Unterschiedliche Werte der ausgewählten Monitore werden "
    L"durch unbestimmte Kontrollkästchen und gepunktete Optionsfelder, Reglergriffe sowie Schaltflächen zum "
    L"Ein- oder Ausschalten aller Optionen angezeigt. Reglerbeschriftungen zeigen statt eines gemeinsamen "
    L"Werts einen Gedankenstrich. Das Ändern einer Option oder Anklicken eines Reglers übernimmt diesen "
    L"Wert für alle ausgewählten Monitore.\r\n\r\nBEDIENUNG\r\nDie Animationsausgabe schalten Sie mit den "
    L"Kontrollkästchen der Monitore oder per Doppelklick auf deren Zeilen ein oder aus. Jeder Monitor "
    L"besitzt eine unabhängige Szene. Schnappschuss speichert PNG, die Aufnahmetaste startet oder beendet "
    L"MP4. Pause hält die Animation an. Die Anwendung installiert oder deinstalliert außerdem den "
    L"eingebetteten Bildschirmschoner. Einstellungen werden laufend gespeichert. Die Anwendung läuft nur in "
    L"einer Instanz. Ein erneuter Start stellt das minimierte Steuerfenster wieder her und bringt es in den "
    L"Vordergrund. Mit Tab und Umschalt+Tab wechseln Sie zwischen den Steuerelementen; mit Alt und dem "
    L"unterstrichenen Buchstaben rufen Sie einen Befehl auf. Esc schließt das aktive Hilfe- oder "
    L"Infofenster; im Steuerfenster beendet es die Anwendung. Pause und Bildschirmschonersperre gelten für "
    L"die gesamte Anwendung, unabhängig von der Monitorauswahl. Bei eingeschalteter Sperre wird der "
    L"Windows-Bildschirmschoner nur verhindert, solange auf mindestens einem Monitor eine sichtbare, nicht "
    L"angehaltene Animation läuft.\r\n\r\nBILDSCHIRMFOTOS UND AUFNAHME\r\nSchnappschüsse und Aufnahmen "
    L"erfassen den ersten aktiven Animationsmonitor, nicht die gemeinsame Fläche aller Monitore. PNG "
    L"verwendet Bilder, MP4 Videos; fehlen diese Ordner, wird Dokumente verwendet. Die Schaltfläche "
    L"Aufnahmeeinstellungen wählt Viewport oder TV. Viewport erhält die Abmessungen und "
    L"Bildwiederholfrequenz des Animationsmonitors bis höchstens 60 Bilder pro Sekunde. TV bietet 1920 × "
    L"1080, 1440 × 1080 oder 1280 × 720 im Format 16:9 mit 50, 25, 59.94 (60000/1001) oder 29.97 "
    L"(30000/1001) Bildern pro Sekunde. Das Seitenverhältnis bleibt erhalten; TV verwendet progressives "
    L"BT.709-Video mit begrenztem Wertebereich und 4:2:0-Abtastung. Auflösung und Bildfrequenz sind nur im "
    L"TV-Modus wählbar. Das Fenster Aufnahmeeinstellungen lässt sich minimieren und blockiert die anderen "
    L"Anwendungsfenster nicht. OK speichert die Auswahl für die nächste MP4-Aufnahme; Abbrechen oder Esc "
    L"verwirft unbestätigte Änderungen. Der aufgezeichnete Monitor kann während der Aufnahme nicht "
    L"abgewählt werden; Änderungen an anderen Monitoren beenden die Aufnahme nicht. Das Beenden der "
    L"Anwendung während einer Aufnahme muss bestätigt werden, da es auch die Aufnahme "
    L"beendet.\r\n\r\nSYSTEMANFORDERUNGEN\r\nWindows 7 bis Windows 11 unterstützen alle Funktionen "
    L"einschließlich PNG-Schnappschüssen und MP4-Aufnahmen. Zum Ausführen der Anwendung unter Windows Vista "
    L"SP2 müssen die Updates KB971512 und KB2117917 installiert werden. MP4-Aufnahmen funktionieren unter "
    L"Vista in der aktuellen Version nicht. Die Darstellung erfordert Direct3D 11, nicht nur eine ältere "
    L"DirectX-Laufzeitumgebung. MP4-Aufnahmen benötigen verfügbare Media-Foundation-Komponenten und einen "
    L"H.264-Encoder.",
    L"ANIMATION ET PARAMÈTRES\r\nSpaceFlight: Surface ondulante infinie; Vol longue distance — surface "
    L"déformable. Attribuez une seule animation à chaque écran. Texture alterne entre surfaces texturées et "
    L"modèle filaire. La rotation libre de la caméra change lentement la direction du regard dans les trois "
    L"dimensions. L’option « Pauses et inversions » ajoute des ralentissements, pauses et inversions "
    L"aléatoires de la rotation ; le vol vers l’avant continue. La vitesse va de 0 à 1600 %. Chaque écran "
    L"possède une scène aléatoire indépendante, rendue à sa propre fréquence de rafraîchissement. La "
    L"lumière principale, la lumière d’appoint, l’éclairage ambiant et l’éclairage des contours se règlent "
    L"indépendamment pour les écrans sélectionnés. L’éclairage ne concerne que les surfaces texturées. "
    L"Les deux animations proposent Plan, Ondulations ou Entonnoir. L’entonnoir attire la caméra vers "
    L"l’intérieur suivant une spirale descendante.\r\n\r\nÉCRANS\r\nLa sélection des lignes détermine les "
    L"écrans à configurer ; elle est "
    L"distincte des cases qui activent les sorties d’animation. Ctrl+A sélectionne tous les écrans ; Ctrl "
    L"et Maj modifient la sélection. Toutes les options et tous les curseurs d’animation concernent les "
    L"écrans sélectionnés. La sélection est mémorisée séparément pour EXE et SCR. Si tous les écrans "
    L"étaient sélectionnés, les nouveaux le sont également. Des valeurs différentes entre les écrans "
    L"sélectionnés sont indiquées par des cases à cocher indéterminées et des pointillés sur les boutons "
    L"radio, les poignées des curseurs et les boutons d’activation ou de désactivation de toutes les "
    L"options. Les libellés des curseurs affichent un tiret au lieu d’une valeur commune. Modifier une "
    L"option ou cliquer sur un curseur applique cette valeur à tous les écrans "
    L"sélectionnés.\r\n\r\nCOMMANDES\r\nActivez ou désactivez les sorties d’animation avec les cases des "
    L"écrans ou en double-cliquant sur leurs lignes. Chaque moniteur utilise une scène indépendante. "
    L"Capture enregistre un PNG et le bouton d’enregistrement démarre ou arrête un MP4. Pause arrête "
    L"l’animation. L’application installe ou désinstalle aussi son économiseur intégré. Les réglages sont "
    L"enregistrés en continu. Une seule instance de l’application peut fonctionner à la fois. Un nouveau "
    L"lancement restaure la fenêtre de contrôle réduite et la place au premier plan. Utilisez Tab et "
    L"Maj+Tab pour passer d’un contrôle à l’autre ; Alt et la lettre soulignée activent une commande. Échap "
    L"ferme la fenêtre d’aide ou À propos active ; dans la fenêtre de contrôle, cette touche quitte "
    L"l’application. La pause et le blocage de l’écran de veille s’appliquent à toute l’application, "
    L"indépendamment des écrans sélectionnés. Lorsque le blocage est activé, l’écran de veille Windows est "
    L"empêché uniquement tant qu’une animation visible et non suspendue s’affiche sur au moins un "
    L"écran.\r\n\r\nCAPTURES ET ENREGISTREMENT\r\nLes captures et les enregistrements utilisent le premier "
    L"moniteur d’animation actif, et non une image combinant tous les moniteurs. PNG utilise Images, MP4 "
    L"Vidéos ; Documents sert de repli si ces dossiers n’existent pas. Le bouton Réglages vidéo permet de "
    L"choisir Viewport ou TV. Viewport conserve les dimensions et la fréquence de rafraîchissement du "
    L"moniteur d’animation, jusqu’à 60 images par seconde. TV propose 1920 × 1080, 1440 × 1080 ou 1280 × "
    L"720 au format 16:9, à 50, 25, 59.94 (60000/1001) ou 29.97 (30000/1001) images par seconde. Le rapport "
    L"d’aspect est conservé ; TV utilise une vidéo progressive BT.709 à plage limitée et "
    L"sous-échantillonnage 4:2:0. La résolution et la fréquence d’images ne sont disponibles qu’en mode TV. "
    L"La fenêtre Réglages vidéo peut être réduite et ne bloque pas les autres fenêtres de l’application. OK "
    L"enregistre les choix pour le prochain enregistrement MP4 ; Annuler ou Échap abandonne les "
    L"modifications non confirmées. Le moniteur enregistré ne peut pas être désélectionné pendant "
    L"l’enregistrement ; les changements concernant les autres moniteurs ne l’arrêtent pas. Fermer "
    L"l’application pendant un enregistrement nécessite une confirmation, car cela arrête aussi "
    L"l’enregistrement.\r\n\r\nCONFIGURATION REQUISE\r\nWindows 7 à Windows 11 prennent en charge toutes "
    L"les fonctions, y compris les captures PNG et l’enregistrement MP4. Pour exécuter l’application sous "
    L"Windows Vista SP2, il est nécessaire d’installer les mises à jour KB971512 et KB2117917. "
    L"L’enregistrement MP4 ne fonctionne pas sous Vista dans la version actuelle. L’affichage nécessite "
    L"Direct3D 11, et pas seulement un ancien environnement d’exécution DirectX. L’enregistrement MP4 "
    L"nécessite les composants Media Foundation et un encodeur H.264 disponibles.",
    L"ANIMACIÓN Y AJUSTES\r\nSpaceFlight: Superficie ondulante infinita; Vuelo de larga distancia — "
    L"superficie deformable. Asigne una sola animación a cada pantalla. Textura alterna entre superficies "
    L"texturizadas y modelo de alambre. El giro libre de la cámara cambia lentamente la dirección de la "
    L"vista en las tres dimensiones. La opción «Pausas e inversiones» añade frenadas, pausas e inversiones "
    L"aleatorias del giro; el vuelo hacia delante continúa. La velocidad va del 0 al 1600 %. Cada pantalla "
    L"tiene una escena aleatoria independiente y se renderiza a su propia frecuencia de actualización. La "
    L"luz principal, la luz de relleno, la luz ambiental y la iluminación de contornos se activan por "
    L"separado para las pantallas seleccionadas. La iluminación solo se aplica a las superficies "
    L"texturizadas. Ambas animaciones ofrecen Plano, Ondulación o Embudo. El embudo atrae la cámara hacia "
    L"el interior siguiendo una espiral descendente.\r\n\r\nMONITORES\r\nLa selección de filas determina "
    L"qué pantallas se están configurando; es "
    L"independiente de las casillas que activan las salidas de animación. Ctrl+A selecciona todas; Ctrl y "
    L"Mayús modifican la selección. Todas las opciones y los controles deslizantes de animación se aplican "
    L"a las pantallas seleccionadas. La selección se recuerda por separado para EXE y SCR. Si estaban "
    L"seleccionadas todas, se incluyen también las nuevas. Los valores distintos entre las pantallas "
    L"seleccionadas se indican mediante casillas indeterminadas y un punteado en los botones de opción, los "
    L"tiradores de los controles deslizantes y los botones para activar o desactivar todas las opciones. "
    L"Las etiquetas de los controles deslizantes muestran una raya en lugar de un valor común. Cambiar una "
    L"opción o hacer clic en un control deslizante aplica ese valor a todas las pantallas "
    L"seleccionadas.\r\n\r\nCONTROLES\r\nActive o desactive las salidas de animación mediante las casillas "
    L"de las pantallas o haciendo doble clic en sus filas. Cada monitor usa una escena independiente. "
    L"Captura guarda un PNG y el botón de grabación inicia o detiene un MP4. Pausar detiene la animación. "
    L"La aplicación instala o desinstala además el salvapantallas incorporado. Los ajustes se guardan "
    L"continuamente. La aplicación solo permite una instancia. Al volver a iniciarla, restaura la ventana "
    L"de control minimizada y la trae al primer plano. Use Tab y Mayús+Tab para desplazarse entre "
    L"controles; Alt y la letra subrayada activan una opción. Esc cierra la ventana activa de Ayuda o "
    L"Acerca de; en la ventana de control, sale de la aplicación. La pausa y el bloqueo del salvapantallas "
    L"se aplican a toda la aplicación, independientemente de las pantallas seleccionadas. Si el bloqueo "
    L"está activado, solo se impide el salvapantallas de Windows mientras haya animación visible y no "
    L"pausada en al menos una pantalla.\r\n\r\nCAPTURAS Y GRABACIÓN\r\nLas capturas y grabaciones usan el "
    L"primer monitor de animación activo, no una imagen conjunta de todos los monitores. PNG usa Imágenes y "
    L"MP4 Vídeos; si no existen esas carpetas, se usa Documentos. El botón Ajustes de grabación permite "
    L"elegir Viewport o TV. Viewport conserva las dimensiones y la frecuencia de actualización del monitor "
    L"de animación, hasta 60 fotogramas por segundo. TV ofrece 1920 × 1080, 1440 × 1080 o 1280 × 720 en "
    L"formato 16:9, a 50, 25, 59.94 (60000/1001) o 29.97 (30000/1001) fotogramas por segundo. Se conserva "
    L"la relación de aspecto; TV usa vídeo progresivo BT.709 de rango limitado y submuestreo 4:2:0. La "
    L"resolución y la frecuencia solo están disponibles en modo TV. La ventana Ajustes de grabación se "
    L"puede minimizar y no bloquea las demás ventanas de la aplicación. Aceptar guarda las opciones para la "
    L"próxima grabación MP4; Cancelar o Esc descarta los cambios sin confirmar. El monitor grabado no se "
    L"puede desmarcar durante la grabación; cambiar otros monitores no la detiene. Cerrar la aplicación "
    L"durante una grabación requiere confirmación porque también detiene la grabación.\r\n\r\nREQUISITOS "
    L"DEL SISTEMA\r\nWindows 7 a Windows 11 admiten todas las funciones, incluidas las capturas PNG y la "
    L"grabación MP4. Para ejecutar la aplicación en Windows Vista SP2, es necesario instalar las "
    L"actualizaciones KB971512 y KB2117917. La grabación MP4 no funciona en Vista en la versión actual. La "
    L"representación requiere Direct3D 11, no solo un entorno de ejecución antiguo de DirectX. La grabación "
    L"MP4 requiere componentes de Media Foundation y un codificador H.264 disponibles.",
    L"ANIMAZIONE E IMPOSTAZIONI\r\nSpaceFlight: Superficie ondulante infinita; Volo a lunga distanza — "
    L"superficie deformabile. Assegnare una sola animazione a ogni schermo. Texture alterna superfici con "
    L"texture e modello a reticolo. La rotazione libera della telecamera cambia lentamente la direzione "
    L"dello sguardo nelle tre dimensioni. L’opzione «Pause e inversioni» aggiunge rallentamenti, pause e "
    L"inversioni casuali della rotazione; il volo in avanti continua. La velocità va da 0 a 1600%. Ogni "
    L"schermo ha una scena casuale indipendente, renderizzata alla propria frequenza di aggiornamento. La "
    L"luce principale, la luce di riempimento, la luce ambientale e l’illuminazione dei contorni si "
    L"attivano separatamente per gli schermi selezionati. L’illuminazione si applica solo alle superfici "
    L"con texture. Entrambe le animazioni offrono Piano, Ondulazione o Imbuto. L’imbuto attira la "
    L"telecamera verso l’interno lungo una spirale discendente.\r\n\r\nMONITOR\r\nLa selezione delle righe "
    L"determina quali "
    L"schermi si stanno configurando ed è distinta dalle caselle che attivano le uscite di animazione. "
    L"Ctrl+A seleziona tutti gli schermi; Ctrl e Maiusc modificano la selezione. Tutte le opzioni e i "
    L"cursori dell’animazione riguardano gli schermi selezionati. La selezione viene memorizzata "
    L"separatamente per EXE e SCR. Se erano selezionati tutti gli schermi, vengono inclusi anche quelli "
    L"nuovi. Valori diversi tra gli schermi selezionati sono indicati da caselle di controllo indeterminate "
    L"e da una trama a punti sui pulsanti di opzione, sulle maniglie dei cursori e sui pulsanti per "
    L"attivare o disattivare tutte le opzioni. Le etichette dei cursori mostrano un trattino al posto di un "
    L"valore comune. Modificare un’opzione o fare clic su un cursore applica quel valore a tutti gli "
    L"schermi selezionati.\r\n\r\nCOMANDI\r\nAttivate o disattivate le uscite di animazione con le caselle "
    L"degli schermi o facendo doppio clic sulle rispettive righe. Ogni monitor usa una scena indipendente. "
    L"Istantanea salva un PNG e il pulsante di registrazione avvia o arresta un MP4. Pausa ferma "
    L"l’animazione. L’applicazione installa o disinstalla anche il salvaschermo incorporato. Le "
    L"impostazioni vengono salvate continuamente. L’applicazione può essere eseguita in una sola istanza. "
    L"Un nuovo avvio ripristina la finestra di controllo ridotta a icona e la porta in primo piano. Usare "
    L"Tab e Maiusc+Tab per passare tra i controlli; Alt e la lettera sottolineata attivano un comando. Esc "
    L"chiude la finestra attiva di Guida o Informazioni; nella finestra di controllo, termina "
    L"l’applicazione. La pausa e il blocco del salvaschermo si applicano all’intera applicazione, "
    L"indipendentemente dagli schermi selezionati. Quando il blocco è attivo, il salvaschermo di Windows "
    L"viene impedito solo finché almeno uno schermo mostra un’animazione visibile e non in "
    L"pausa.\r\n\r\nISTANTANEE E REGISTRAZIONE\r\nIstantanee e registrazioni usano il primo monitor di "
    L"animazione attivo, non un’immagine combinata di tutti i monitor. PNG usa Immagini, MP4 Video; se tali "
    L"cartelle non esistono, viene usata Documenti. Il pulsante Impostazioni video permette di scegliere "
    L"Viewport o TV. Viewport mantiene le dimensioni e la frequenza di aggiornamento del monitor di "
    L"animazione, fino a 60 fotogrammi al secondo. TV offre 1920 × 1080, 1440 × 1080 o 1280 × 720 in "
    L"formato 16:9, a 50, 25, 59.94 (60000/1001) o 29.97 (30000/1001) fotogrammi al secondo. Le proporzioni "
    L"sono mantenute; TV usa video progressivo BT.709 con intervallo limitato e campionamento 4:2:0. "
    L"Risoluzione e frequenza sono disponibili solo in modalità TV. La finestra Impostazioni video può "
    L"essere ridotta a icona e non blocca le altre finestre dell’applicazione. OK salva le opzioni per la "
    L"prossima registrazione MP4; Annulla o Esc scarta le modifiche non confermate. Il monitor registrato "
    L"non può essere deselezionato durante la registrazione; le modifiche agli altri monitor non la "
    L"interrompono. Chiudere l’applicazione durante una registrazione richiede conferma, perché interrompe "
    L"anche la registrazione.\r\n\r\nREQUISITI DI SISTEMA\r\nI sistemi da Windows 7 a Windows 11 supportano "
    L"tutte le funzioni, comprese le istantanee PNG e la registrazione MP4. Per eseguire l’applicazione su "
    L"Windows Vista SP2, è necessario installare gli aggiornamenti KB971512 e KB2117917. La registrazione "
    L"MP4 non funziona in Vista nella versione attuale. La visualizzazione richiede Direct3D 11, non "
    L"soltanto un vecchio runtime DirectX. La registrazione MP4 richiede componenti Media Foundation e un "
    L"codificatore H.264 disponibili.",
    L"ANIMAÇÃO E DEFINIÇÕES\r\nSpaceFlight: Superfície ondulante infinita; Voo de longa distância — "
    L"superfície deformável. Atribua uma única animação a cada ecrã. Textura alterna entre superfícies "
    L"texturadas e modelo em arame. A rotação livre da câmara muda lentamente a direção da vista nas três "
    L"dimensões. A opção «Pausas e inversões» acrescenta desacelerações, pausas e inversões aleatórias da "
    L"rotação; o voo para a frente continua. A velocidade vai de 0 a 1600%. Cada ecrã tem uma cena "
    L"aleatória independente, apresentada à sua própria frequência de atualização. A luz principal, a luz "
    L"de preenchimento, a luz ambiente e a iluminação dos contornos podem ser ativadas separadamente nos "
    L"monitores selecionados. A iluminação aplica-se apenas às superfícies com textura. Ambas as animações "
    L"oferecem Plano, Ondulação ou Funil. O funil atrai a câmara para o interior ao longo de uma espiral "
    L"descendente.\r\n\r\nMONITORES\r\nA "
    L"seleção das linhas determina os ecrãs a configurar e é independente das caixas que ativam as saídas "
    L"de animação. Ctrl+A seleciona todos os ecrãs; Ctrl e Shift alteram a seleção. Todas as opções e "
    L"controlos deslizantes da animação aplicam-se aos ecrãs selecionados. A seleção é guardada "
    L"separadamente para EXE e SCR. Se todos estavam selecionados, os novos ecrãs também são incluídos. "
    L"Valores diferentes entre os ecrãs selecionados são indicados por caixas de verificação indeterminadas "
    L"e por um padrão pontilhado nos botões de opção, nas pegas dos controlos deslizantes e nos botões para "
    L"ativar ou desativar todas as opções. As etiquetas dos controlos deslizantes apresentam um travessão "
    L"em vez de um valor comum. Alterar uma opção ou clicar num controlo deslizante aplica esse valor a "
    L"todos os ecrãs selecionados.\r\n\r\nCONTROLOS\r\nAtive ou desative as saídas de animação através das "
    L"caixas dos ecrãs ou com um duplo clique nas respetivas linhas. Cada monitor usa uma cena "
    L"independente. Captura guarda PNG e o botão de gravação inicia ou termina MP4. Pausa para a animação. "
    L"A aplicação também instala ou desinstala a proteção de ecrã incorporada. As definições são guardadas "
    L"continuamente. A aplicação só pode ter uma instância em execução. Um novo arranque restaura a janela "
    L"de controlo minimizada e coloca-a em primeiro plano. Use Tab e Shift+Tab para passar entre controlos; "
    L"Alt e a letra sublinhada ativam um comando. Esc fecha a janela ativa de Ajuda ou Acerca de; na janela "
    L"de controlo, termina a aplicação. A pausa e o bloqueio da proteção de ecrã aplicam-se a toda a "
    L"aplicação, independentemente dos ecrãs selecionados. Com o bloqueio ativo, a proteção de ecrã do "
    L"Windows só é impedida enquanto existir animação visível e não pausada em pelo menos um "
    L"ecrã.\r\n\r\nCAPTURAS E GRAVAÇÃO\r\nAs capturas e gravações usam o primeiro monitor de animação "
    L"ativo, não uma imagem conjunta de todos os monitores. PNG usa Imagens, MP4 Vídeos; se essas pastas "
    L"não existirem, usa-se Documentos. O botão Definições de gravação permite escolher Viewport ou TV. "
    L"Viewport conserva as dimensões e a frequência de atualização do monitor de animação, até 60 "
    L"fotogramas por segundo. TV oferece 1920 × 1080, 1440 × 1080 ou 1280 × 720 no formato 16:9, a 50, 25, "
    L"59.94 (60000/1001) ou 29.97 (30000/1001) fotogramas por segundo. A proporção da imagem é mantida; TV "
    L"usa vídeo progressivo BT.709 com intervalo limitado e amostragem 4:2:0. A resolução e a frequência só "
    L"estão disponíveis no modo TV. A janela Definições de gravação pode ser minimizada e não bloqueia as "
    L"outras janelas da aplicação. OK guarda as escolhas para a próxima gravação MP4; Cancelar ou Esc "
    L"descarta as alterações não confirmadas. O monitor gravado não pode ser desmarcado durante a gravação; "
    L"as alterações aos outros monitores não a interrompem. Fechar a aplicação durante uma gravação exige "
    L"confirmação, pois também termina a gravação.\r\n\r\nREQUISITOS DO SISTEMA\r\nOs sistemas Windows 7 a "
    L"Windows 11 suportam todas as funcionalidades, incluindo capturas PNG e gravação MP4. Para executar a "
    L"aplicação no Windows Vista SP2, é necessário instalar as atualizações KB971512 e KB2117917. A "
    L"gravação MP4 não funciona no Vista na versão atual. A apresentação requer Direct3D 11, não apenas um "
    L"runtime DirectX mais antigo. A gravação MP4 requer componentes Media Foundation e um codificador "
    L"H.264 disponíveis.",
    L"ANIMACJA I USTAWIENIA\r\nSpaceFlight: Nieskończona falująca powierzchnia; Lot dalekodystansowy — "
    L"zmienna powierzchnia. Każdemu monitorowi przypisz dokładnie jedną animację. Tekstura przełącza "
    L"powierzchnie z teksturą i model szkieletowy. Swobodne obracanie kamery powoli zmienia kierunek widoku "
    L"we wszystkich trzech wymiarach. Przerwy i nawroty dodają losowe zwalnianie, pauzy i odwracanie "
    L"obrotu; lot do przodu trwa nadal. Prędkość wynosi 0–1600%. Każdy monitor ma niezależną losową scenę "
    L"wyświetlaną z własną częstotliwością odświeżania. Światło główne, światło wypełniające, światło "
    L"otoczenia i oświetlenie konturów można przełączać niezależnie dla zaznaczonych monitorów. Oświetlenie "
    L"dotyczy tylko powierzchni z teksturą. Obie animacje oferują płaszczyznę, falowanie lub lej. Lej "
    L"wciąga kamerę do środka po opadającej spirali.\r\n\r\nMONITORY\r\nZaznaczenie wierszy określa "
    L"konfigurowane "
    L"monitory i jest niezależne od pól wyboru włączających wyjścia animacji. Ctrl+A zaznacza wszystkie "
    L"monitory; Ctrl i Shift zmieniają zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą zaznaczonych "
    L"monitorów. Zaznaczenie jest zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były wszystkie "
    L"monitory, nowe również zostaną zaznaczone. Różne wartości na zaznaczonych monitorach są sygnalizowane "
    L"nieokreślonym stanem pól wyboru i kropkowaniem przycisków opcji, uchwytów suwaków oraz przycisków "
    L"włączania i wyłączania wszystkich opcji. Etykiety suwaków pokazują kreskę zamiast wspólnej wartości. "
    L"Zmiana opcji lub kliknięcie suwaka ustawia tę wartość na wszystkich zaznaczonych "
    L"monitorach.\r\n\r\nOBSŁUGA\r\nWyjścia animacji można włączać i wyłączać polami wyboru przy monitorach "
    L"lub podwójnym kliknięciem ich wierszy. Każdy monitor ma niezależną scenę. Zrzut zapisuje PNG, a "
    L"przycisk nagrywania rozpoczyna lub kończy MP4. Wstrzymaj zatrzymuje animację. Aplikacja instaluje i "
    L"odinstalowuje również wbudowany wygaszacz. Ustawienia są zapisywane na bieżąco. Aplikacja działa "
    L"tylko w jednej instancji. Kolejne uruchomienie przywraca zminimalizowane okno sterowania i przenosi "
    L"na pierwszy plan. Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera "
    L"wywołują polecenie. Esc zamyka aktywne okno Pomocy lub O programie; w oknie sterowania kończy "
    L"działanie aplikacji. Wstrzymanie i blokowanie wygaszacza dotyczą całej aplikacji, niezależnie od "
    L"zaznaczenia monitorów. Gdy blokowanie jest włączone, wygaszacz Windows jest powstrzymywany tylko "
    L"wtedy, gdy na co najmniej jednym monitorze jest widoczna niewstrzymana animacja.\r\n\r\nZRZUTY EKRANU "
    L"I NAGRYWANIE\r\nZrzuty i nagrania obejmują pierwszy aktywny monitor animacji, a nie wspólny obraz "
    L"wszystkich monitorów. PNG używa folderu Obrazy, MP4 folderu Wideo; jeśli ich nie ma, używane są "
    L"Dokumenty. Przycisk Ustawienia nagrywania pozwala wybrać Viewport lub TV. Viewport zachowuje rozmiar "
    L"i częstotliwość odświeżania monitora animacji, do 60 klatek na sekundę. TV oferuje 1920 × 1080, 1440 "
    L"× 1080 lub 1280 × 720 w formacie 16:9, z 50, 25, 59.94 (60000/1001) lub 29.97 (30000/1001) klatkami "
    L"na sekundę. Proporcje obrazu są zachowane; TV używa progresywnego obrazu BT.709 z ograniczonym "
    L"zakresem i próbkowaniem 4:2:0. Rozdzielczość i liczba klatek są dostępne tylko w trybie TV. Okno "
    L"Ustawienia nagrywania można zminimalizować i nie blokuje ono innych okien aplikacji. OK zapisuje "
    L"wybór dla następnego nagrania MP4; Anuluj lub Esc odrzuca niepotwierdzone zmiany. Podczas nagrywania "
    L"nie można odznaczyć nagrywanego monitora; zmiany pozostałych monitorów nie przerywają nagrania. "
    L"Zamknięcie aplikacji podczas nagrywania wymaga potwierdzenia, ponieważ kończy również "
    L"nagranie.\r\n\r\nWYMAGANIA SYSTEMOWE\r\nSystemy od Windows 7 do Windows 11 obsługują wszystkie "
    L"funkcje, w tym zrzuty PNG i nagrywanie MP4. Do uruchomienia aplikacji w systemie Windows Vista SP2 "
    L"konieczne jest zainstalowanie aktualizacji KB971512 i KB2117917. Nagrywanie MP4 nie działa w Vista w "
    L"obecnej wersji. Wyświetlanie wymaga Direct3D 11, a nie tylko starszego środowiska DirectX. Nagrywanie "
    L"MP4 wymaga dostępnych składników Media Foundation i kodera H.264.",
    L"ANIMÁCIA A NASTAVENIA\r\nSpaceFlight: Nekonečná vlniaca sa plocha; Diaľkový let — premenlivá plocha. "
    L"Každému monitoru priraďte práve jednu animáciu. Textúra prepína medzi textúrovanými plochami a "
    L"drôteným modelom. Voľná rotácia kamery pomaly mení smer pohľadu vo všetkých troch rozmeroch. Voľba "
    L"„Pauzy a obraty“ pridáva náhodné spomaľovanie, prestávky a zmeny smeru otáčania; dopredný pohyb "
    L"pokračuje. Rýchlosť je 0–1600 %. Každý monitor má nezávislú náhodnú scénu vykresľovanú podľa vlastnej "
    L"obnovovacej frekvencie. Hlavné svetlo, doplnkové svetlo, základný jas a prisvetlenie obrysov možno "
    L"pre označené monitory zapínať nezávisle. Osvetlenie sa používa len pri textúrovaných plochách. "
    L"Pri oboch animáciách možno zvoliť rovinu, vlnenie alebo lievik. Lievik vťahuje kameru dovnútra po "
    L"zostupnej špirále.\r\n\r\nMONITORY\r\nOznačenie riadkov určuje, ktoré monitory práve nastavujete; je "
    L"nezávislé "
    L"od políčok zapínajúcich animačné výstupy. Ctrl+A označí všetky monitory, Ctrl a Shift upravujú "
    L"označenie. Všetky animačné voľby a posuvníky platia pre označené monitory. Označenie sa pamätá zvlášť "
    L"pre EXE a SCR. Ak boli označené všetky monitory, označia sa aj novopripojené. Rozdielne hodnoty na "
    L"označených monitoroch ukazuje neurčitý stav políčok a bodkovanie prepínačov, úchytov posuvníkov a "
    L"tlačidiel na zapnutie či vypnutie všetkých volieb. Popis posuvníka namiesto spoločnej hodnoty "
    L"zobrazuje pomlčku. Zmena voľby alebo kliknutie na posuvník zjednotí príslušnú hodnotu na označených "
    L"monitoroch.\r\n\r\nOVLÁDANIE\r\nAnimačné výstupy zapnete alebo vypnete políčkami pri monitoroch alebo "
    L"dvojklikom na ich riadky. Každý monitor používa nezávislú scénu. Snímka uloží PNG a tlačidlo záznamu "
    L"spustí alebo ukončí MP4. Pozastavenie zastaví animáciu. Aplikácia tiež nainštaluje alebo odinštaluje "
    L"vložený šetrič. Nastavenia sa ukladajú priebežne. Aplikácia beží iba v jednej inštancii. Ďalšie "
    L"spustenie obnoví minimalizované ovládacie okno a prenesie do popredia. Medzi ovládacími prvkami "
    L"prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a príslušného písmena. "
    L"Esc zavrie aktívne okno Pomocníka alebo O aplikácii; v ovládacom okne ukončí aplikáciu. Pozastavenie "
    L"a blokovanie šetriča platia pre celú aplikáciu bez ohľadu na označené monitory. Ak je blokovanie "
    L"zapnuté, bráni spusteniu šetriča Windows iba vtedy, keď je aspoň na jednom monitore viditeľná "
    L"nepozastavená animácia.\r\n\r\nSNÍMKY A ZÁZNAM\r\nSnímky a záznamy zachytávajú prvý aktívny animačný "
    L"monitor, nie spoločnú plochu všetkých monitorov. PNG používa Obrázky, MP4 Videá; ak tieto priečinky "
    L"neexistujú, použijú sa Dokumenty. Tlačidlo Nastavenie záznamu vyberá Viewport alebo TV. Viewport "
    L"zachováva rozmery animačného monitora a jeho obnovovaciu frekvenciu, najviac 60 snímok za sekundu. TV "
    L"ponúka rozlíšenie 1920 × 1080, 1440 × 1080 alebo 1280 × 720 v pomere 16:9 a frekvenciu 50, 25, 59.94 "
    L"(60000/1001) alebo 29.97 (30000/1001) snímok za sekundu. Obraz zachováva pomer strán; TV používa "
    L"progresívne video BT.709 s obmedzeným rozsahom a vzorkovaním 4:2:0. Rozlíšenie a snímkovú frekvenciu "
    L"možno vybrať iba v režime TV. Okno Nastavenie záznamu možno minimalizovať a neblokuje ostatné okná "
    L"aplikácie. OK uloží voľby pre nasledujúci záznam MP4; Zrušiť alebo Esc zahodí nepotvrdené zmeny. "
    L"Nahrávaný monitor nemožno počas záznamu odpojiť; zmeny ostatných monitorov záznam nezastavia. "
    L"Ukončenie aplikácie počas záznamu vyžaduje potvrdenie, pretože ukončí aj záznam.\r\n\r\nSYSTÉMOVÉ "
    L"POŽIADAVKY\r\nWindows 7 až Windows 11 podporujú všetky funkcie vrátane snímok PNG a záznamu MP4. Na "
    L"spustenie aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať aktualizácie KB971512 a "
    L"KB2117917. Záznam MP4 na Viste v súčasnej verzii nefunguje. Vykresľovanie vyžaduje Direct3D 11, nie "
    L"iba starší DirectX runtime. Záznam MP4 vyžaduje dostupné súčasti Media Foundation a kodér H.264.",
    L"ANIMATION OG INDSTILLINGER\r\nSpaceFlight: Uendelig bølgende flade; Langdistanceflyvetur — "
    L"formskiftende flade. Tildel præcis én animation til hver skærm. Tekstur skifter mellem teksturerede "
    L"flader og trådmodel. Frit roterende kamera ændrer langsomt synsretningen i alle tre dimensioner. "
    L"Pauser og vendinger tilføjer tilfældige opbremsninger, pauser og ændringer af rotationsretningen; "
    L"flyvningen fremad fortsætter. Hastigheden er 0–1600 %. Hver skærm har en uafhængig tilfældig scene, "
    L"der gengives med dens egen opdateringsfrekvens. Hovedlys, udfyldningslys, omgivende lys og konturlys "
    L"kan slås til og fra uafhængigt for de valgte skærme. Belysningen gælder kun teksturerede overflader. "
    L"Begge animationer tilbyder Plan, Bølger eller Tragt. Tragten trækker kameraet indad langs en "
    L"nedadgående spiral.\r\n\r\nSKÆRME\r\nMarkeringen af rækker bestemmer, hvilke skærme du indstiller, og "
    L"er "
    L"adskilt fra afkrydsningsfelterne, der aktiverer animationsoutput. Ctrl+A markerer alle skærme; Ctrl "
    L"og Skift ændrer markeringen. Alle animationsvalg og skydere gælder de markerede skærme. Markeringen "
    L"huskes separat for EXE og SCR. Hvis alle skærme var markeret, medtages også nye skærme. Forskellige "
    L"værdier på de markerede skærme vises med ubestemte afkrydsningsfelter og prikmønstre på "
    L"alternativknapper, skydergreb og knapper til at slå alle valg til eller fra. Skydernes etiketter "
    L"viser en tankestreg i stedet for en fælles værdi. Ændring af et valg eller klik på en skyder anvender "
    L"denne værdi på alle markerede skærme.\r\n\r\nBETJENING\r\nSlå animationsoutput til eller fra med "
    L"skærmenes afkrydsningsfelter eller ved at dobbeltklikke på deres rækker. Hver skærm bruger en "
    L"uafhængig scene. Skærmbillede gemmer PNG, og optageknappen starter eller stopper MP4. Pause standser "
    L"animationen. Programmet installerer eller afinstallerer også den indbyggede pauseskærm. Indstillinger "
    L"gemmes løbende. Programmet kan kun køre i én instans ad gangen. En ny start gendanner det minimerede "
    L"kontrolvindue og bringer det forrest. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og "
    L"det understregede bogstav aktiverer en kommando. Esc lukker det aktive Hjælp- eller Om-vindue; i "
    L"kontrolvinduet afslutter det programmet. Pause og blokering af pauseskærmen gælder hele programmet "
    L"uanset skærmmarkeringen. Når blokering er slået til, forhindres Windows-pauseskærmen kun, mens der "
    L"vises en synlig animation, som ikke er sat på pause, på mindst én skærm.\r\n\r\nSKÆRMBILLEDER OG "
    L"OPTAGELSE\r\nSkærmbilleder og optagelser bruger den første aktive animationsskærm, ikke et samlet "
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
    L"afsluttes.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 understøtter alle funktioner, herunder "
    L"PNG-skærmbilleder og MP4-optagelse. For at køre programmet på Windows Vista SP2 skal opdateringerne "
    L"KB971512 og KB2117917 installeres. MP4-optagelse fungerer ikke på Vista i den aktuelle version. "
    L"Visningen kræver Direct3D 11, ikke kun et ældre DirectX-kørselsmiljø. MP4-optagelse kræver "
    L"tilgængelige Media Foundation-komponenter og en H.264-koder.",
    L"ANIMAATIO JA ASETUKSET\r\nSpaceFlight: Ääretön aaltoileva pinta; Pitkän matkan lento — muuntuva "
    L"pinta. Valitse kullekin näytölle yksi animaatio. Tekstuuri vaihtaa teksturoitujen pintojen ja "
    L"rautalankamallin välillä. Kameran vapaa pyörintä muuttaa katselusuuntaa hitaasti kaikissa kolmessa "
    L"ulottuvuudessa. Tauot ja suunnanvaihdot lisäävät satunnaisia hidastuksia, taukoja ja pyörimissuunnan "
    L"vaihtoja; lento eteenpäin jatkuu. Nopeus on 0–1600%. Jokaisella näytöllä on itsenäinen satunnainen "
    L"näkymä, joka piirretään sen omalla virkistystaajuudella. Päävalo, täytevalo, ympäristövalo ja "
    L"reunavalo voidaan kytkeä erikseen valituille näytöille. Valaistus koskee vain teksturoituja pintoja. "
    L"Molemmissa animaatioissa voi valita tason, aallot tai suppilon. Suppilo vetää kameran sisään alaspäin "
    L"kiertyvää spiraalia pitkin.\r\n\r\nNÄYTÖT\r\nRivien valinta määrää muokattavat näytöt ja on erillinen "
    L"animaatioulostulon valintaruuduista. Ctrl+A valitsee kaikki näytöt; Ctrl ja Vaihto muuttavat "
    L"valintaa. Kaikki animaatioasetukset ja liukusäätimet koskevat valittuja näyttöjä. Valinta muistetaan "
    L"erikseen EXE- ja SCR-tiloissa. Jos kaikki näytöt olivat valittuina, myös uudet näytöt valitaan. "
    L"Valittujen näyttöjen eri arvot ilmaistaan valintaruutujen määrittämättömällä tilalla sekä "
    L"valintanappien, liukusäätimien kahvojen ja kaikkien asetusten kytkentäpainikkeiden pistekuviolla. "
    L"Liukusäätimen selitteessä näkyy viiva yhteisen arvon sijasta. Asetuksen muuttaminen tai liukusäätimen "
    L"napsauttaminen asettaa kyseisen arvon kaikille valituille "
    L"näytöille.\r\n\r\nKÄYTTÖ\r\nAnimaatioulostulot voi ottaa käyttöön tai poistaa käytöstä näyttöjen "
    L"valintaruuduilla tai kaksoisnapsauttamalla niiden rivejä. Jokaisella näytöllä on itsenäinen näkymä. "
    L"Tilannekuva tallentaa PNG:n ja tallennuspainike käynnistää tai lopettaa MP4:n. Keskeytä pysäyttää "
    L"animaation. Sovellus asentaa tai poistaa myös sisäisen näytönsäästäjän. Asetukset tallennetaan "
    L"jatkuvasti. Sovelluksesta voi olla käynnissä vain yksi instanssi. Uusi käynnistys palauttaa "
    L"pienennetyn ohjausikkunan ja tuo sen etualalle. Siirry säätimien välillä Tab- ja "
    L"Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat komennon. Esc sulkee aktiivisen Ohje- "
    L"tai Tietoja-ikkunan; ohjausikkunassa se sulkee sovelluksen. Keskeytys ja näytönsäästäjän esto "
    L"koskevat koko sovellusta näytön valinnasta riippumatta. Kun esto on käytössä, Windowsin "
    L"näytönsäästäjä estetään vain, kun vähintään yhdessä näytössä näkyy animaatio, jota ei ole "
    L"keskeytetty.\r\n\r\nKUVAKAAPPAUKSET JA TALLENNUS\r\nTilannekuvat ja tallenteet käyttävät ensimmäistä "
    L"aktiivista animaationäyttöä, eivät kaikkien näyttöjen yhdistettyä kuvaa. PNG käyttää Kuvat-kansiota "
    L"ja MP4 Videot-kansiota; jos niitä ei ole, käytetään Tiedostot-kansiota. "
    L"Tallennusasetukset-painikkeella valitaan Viewport tai TV. Viewport säilyttää animaationäytön koon ja "
    L"virkistystaajuuden, enintään 60 kuvaa sekunnissa. TV tarjoaa tarkkuudet 1920 × 1080, 1440 × 1080 ja "
    L"1280 × 720 kuvasuhteella 16:9 sekä taajuudet 50, 25, 59.94 (60000/1001) ja 29.97 (30000/1001) kuvaa "
    L"sekunnissa. Kuvasuhde säilyy; TV käyttää progressiivista BT.709-videota rajatulla alueella ja "
    L"4:2:0-näytteistyksellä. Tarkkuus ja kuvataajuus ovat valittavissa vain TV-tilassa. "
    L"Tallennusasetukset-ikkunan voi pienentää, eikä se estä muiden sovellusikkunoiden käyttöä. OK "
    L"tallentaa valinnat seuraavaa MP4-tallennusta varten; Peruuta tai Esc hylkää vahvistamattomat "
    L"muutokset. Tallennettavan näytön valintaa ei voi poistaa tallennuksen aikana; muiden näyttöjen "
    L"muutokset eivät pysäytä tallennusta. Sovelluksen sulkeminen tallennuksen aikana vaatii vahvistuksen, "
    L"sillä myös tallennus päättyy.\r\n\r\nJÄRJESTELMÄVAATIMUKSET\r\nWindows 7–Windows 11 tukevat kaikkia "
    L"toimintoja, myös PNG-tilannekuvia ja MP4-tallennusta. Sovelluksen suorittaminen Windows Vista SP2:ssa "
    L"edellyttää päivitysten KB971512 ja KB2117917 asentamista. MP4-tallennus ei toimi Vistassa nykyisessä "
    L"versiossa. Näyttäminen vaatii Direct3D 11:n, ei pelkästään vanhempaa DirectX-ajoympäristöä. "
    L"MP4-tallennus vaatii käytettävissä olevat Media Foundation -komponentit ja H.264-enkooderin.",
    L"HREYFIMYND OG STILLINGAR\r\nSpaceFlight: Óendanleg bylgjandi flötur; Langflug — breytilegur flötur. "
    L"Veldu nákvæmlega eina hreyfimynd fyrir hvern skjá. Áferð skiptir milli áferðarlagðra flata og "
    L"víragrindar. Frjáls snúningur myndavélar breytir sjónstefnunni hægt í öllum þremur víddum. "
    L"Valkosturinn „Hlé og stefnuskipti“ bætir við tilviljanakenndri hægingu, hléum og breytingum á "
    L"snúningsstefnu; flug áfram heldur áfram. Hraðinn er 0–1600%. Hver skjár hefur sjálfstæða "
    L"tilviljanakennda senu sem er teiknuð á eigin endurnýjunartíðni. Aðalljós, fylliljós, umhverfislýsing "
    L"og útlínulýsing eru stillt óháð hvert öðru fyrir valda skjái. Lýsingin á aðeins við um áferðarfleti. "
    L"Í báðum hreyfimyndum má velja sléttu, bylgjur eða trekt. Trektin dregur myndavélina inn eftir spíral "
    L"sem liggur niður á við.\r\n\r\nSKJÁIR\r\nVal lína ákvarðar hvaða skjám er verið að breyta og er óháð "
    L"gátreitunum "
    L"sem kveikja á hreyfimyndaúttaki. Ctrl+A velur alla skjái; Ctrl og Shift breyta valinu. Allir "
    L"valkostir og sleðar hreyfimynda gilda fyrir valda skjái. Valið er munað sérstaklega fyrir EXE og SCR. "
    L"Ef allir skjáir voru valdir bætast nýir skjáir einnig við valið. Mismunandi gildi á völdum skjám eru "
    L"sýnd með óákveðnu ástandi gátreita og punktamynstri á valhnöppum, handföngum sleða og hnöppum sem "
    L"kveikja eða slökkva á öllum valkostum. Merking sleða sýnir strik í stað sameiginlegs gildis. Að "
    L"breyta valkosti eða smella á sleða setur það gildi á alla valda skjái.\r\n\r\nNOTKUN\r\nKveiktu eða "
    L"slökktu á hreyfimyndaúttaki með gátreitum skjáanna eða með því að tvísmella á línur þeirra. Hver "
    L"skjár notar sjálfstæða senu. Skjámynd vistar PNG og upptökuhnappurinn ræsir eða stöðvar MP4. "
    L"Hnappurinn Gera hlé stöðvar hreyfimyndina. Forritið setur einnig upp eða fjarlægir innbyggðu "
    L"skjáhvíluna. Stillingar vistast jafnóðum. Aðeins eitt eintak af forritinu getur verið í gangi í einu. "
    L"Ný ræsing endurheimtir lágmarkaðan stjórngluggann og færir hann fremst. Notaðu Tab og Shift+Tab til "
    L"að færa þig milli stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc lokar virka Hjálp- "
    L"eða Um-glugganum; í stjórnglugganum lokar það forritinu. Pása og hindrun skjáhvílu gilda fyrir allt "
    L"forritið, óháð völdum skjám. Þegar hindrun er virk er skjáhvíla Windows aðeins hindruð meðan sýnileg "
    L"hreyfimynd sem er ekki í pásu er á að minnsta kosti einum skjá.\r\n\r\nSKJÁMYNDIR OG "
    L"UPPTAKA\r\nSkjámyndir og upptökur nota fyrsta virka hreyfimyndaskjáinn, ekki sameinaða mynd af öllum "
    L"skjám. PNG notar Myndir, MP4 Myndbönd; ef þær möppur eru ekki til er Skjöl notuð. Hnappurinn "
    L"Upptökustillingar velur Viewport eða TV. Viewport varðveitir stærð og endurnýjunartíðni "
    L"hreyfimyndaskjásins, þó mest 60 ramma á sekúndu. TV býður upp á 1920 × 1080, 1440 × 1080 eða 1280 × "
    L"720 í hlutfallinu 16:9 með 50, 25, 59.94 (60000/1001) eða 29.97 (30000/1001) römmum á sekúndu. "
    L"Hlutföll myndarinnar haldast; TV notar stigvaxandi BT.709-myndband með takmörkuðu sviði og "
    L"4:2:0-sýnatöku. Upplausn og rammatíðni eru aðeins valanleg í TV-ham. Hægt er að lágmarka gluggann "
    L"Upptökustillingar og hann hindrar ekki notkun annarra glugga forritsins. Í lagi vistar valið fyrir "
    L"næstu MP4-upptöku; Hætta við eða Esc hendir óstaðfestum breytingum. Ekki er hægt að afvelja skjáinn "
    L"sem er tekinn upp meðan upptaka stendur yfir; breytingar á öðrum skjám stöðva ekki upptökuna. "
    L"Staðfesta þarf lokun forritsins meðan upptaka stendur yfir, því hún stöðvar líka "
    L"upptökuna.\r\n\r\nKERFISKRÖFUR\r\nWindows 7 til Windows 11 styðja alla eiginleika, þar á meðal "
    L"PNG-skjámyndir og MP4-upptöku. Til að keyra forritið á Windows Vista SP2 þarf að setja upp "
    L"uppfærslurnar KB971512 og KB2117917. MP4-upptaka virkar ekki í Vista í núverandi útgáfu. Birting "
    L"krefst Direct3D 11, ekki aðeins eldri DirectX-keyrsluumhverfis. MP4-upptaka krefst tiltækra Media "
    L"Foundation-íhluta og H.264-kóðara.",
    L"ANIMASJON OG INNSTILLINGER\r\nSpaceFlight: Uendelig bølgende flate; Langdistanseflytur — formendrende "
    L"flate. Tilordne nøyaktig én animasjon til hver skjerm. Tekstur veksler mellom teksturerte flater og "
    L"trådmodell. Fritt roterende kamera endrer synsretningen langsomt i alle tre dimensjoner. Pauser og "
    L"vendinger legger til tilfeldige oppbremsinger, pauser og endringer i rotasjonsretningen; flyvningen "
    L"fremover fortsetter. Hastigheten er 0–1600 %. Hver skjerm har en uavhengig tilfeldig scene som "
    L"gjengis ved dens egen oppdateringsfrekvens. Hovedlys, utfyllingslys, omgivelseslys og konturlys kan "
    L"slås av og på uavhengig for de valgte skjermene. Belysningen gjelder bare teksturerte flater. Begge "
    L"animasjonene tilbyr Plan, Bølger eller Trakt. Trakten trekker kameraet innover langs en nedadgående "
    L"spiral.\r\n\r\nSKJERMER\r\nMarkeringen av rader bestemmer hvilke skjermer du redigerer, og er "
    L"atskilt fra avkrysningsboksene som aktiverer animasjonsutgangen. Ctrl+A markerer alle skjermer; Ctrl "
    L"og Skift endrer markeringen. Alle animasjonsvalg og glidebrytere gjelder de markerte skjermene. "
    L"Markeringen huskes separat for EXE og SCR. Hvis alle skjermer var markert, inkluderes også nye "
    L"skjermer. Ulike verdier på de markerte skjermene vises med ubestemte avkrysningsbokser og "
    L"prikkmønster på alternativknapper, glidebryterhåndtak og knapper for å slå alle valg av eller på. "
    L"Glidebryteretiketter viser en tankestrek i stedet for en felles verdi. Endring av et valg eller klikk "
    L"på en glidebryter bruker denne verdien på alle markerte skjermer.\r\n\r\nBETJENING\r\nSlå "
    L"animasjonsutgangene av eller på med skjermenes avkrysningsbokser eller ved å dobbeltklikke på radene "
    L"deres. Hver skjerm bruker en uavhengig scene. Skjermbilde lagrer PNG, og opptaksknappen starter eller "
    L"stopper MP4. Pause stanser animasjonen. Programmet installerer eller avinstallerer også den innebygde "
    L"skjermspareren. Innstillingene lagres fortløpende. Bare én instans av programmet kan kjøre om gangen. "
    L"En ny start gjenoppretter det minimerte kontrollvinduet og bringer det fremst. Bruk Tab og Shift+Tab "
    L"for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc lukker "
    L"det aktive Hjelp- eller Om-vinduet; i kontrollvinduet avslutter det programmet. Pause og blokkering "
    L"av skjermspareren gjelder hele programmet uavhengig av skjermmarkeringen. Når blokkering er slått på, "
    L"hindres Windows-skjermspareren bare mens en synlig animasjon som ikke er satt på pause, vises på "
    L"minst én skjerm.\r\n\r\nSKJERMBILDER OG OPPTAK\r\nSkjermbilder og opptak bruker den første aktive "
    L"animasjonsskjermen, ikke et samlet bilde av alle skjermene. PNG bruker Bilder, MP4 Videoer; hvis "
    L"disse mappene ikke finnes, brukes Dokumenter. Knappen Opptaksinnstillinger velger Viewport eller TV. "
    L"Viewport beholder animasjonsskjermens størrelse og oppdateringsfrekvens, opptil 60 bilder per sekund. "
    L"TV tilbyr 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9, med 50, 25, 59.94 (60000/1001) "
    L"eller 29.97 (30000/1001) bilder per sekund. Bildets proporsjoner beholdes; TV bruker progressiv "
    L"BT.709-video med begrenset område og 4:2:0-sampling. Oppløsning og bildefrekvens er bare "
    L"tilgjengelige i TV-modus. Vinduet Opptaksinnstillinger kan minimeres og blokkerer ikke de andre "
    L"programvinduene. OK lagrer valgene for neste MP4-opptak; Avbryt eller Esc forkaster ubekreftede "
    L"endringer. Skjermen som tas opp, kan ikke velges bort under opptaket; endringer på andre skjermer "
    L"stopper ikke opptaket. Å avslutte programmet under et opptak krever bekreftelse, fordi det også "
    L"avslutter opptaket.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 støtter alle funksjoner, inkludert "
    L"PNG-skjermbilder og MP4-opptak. For å kjøre programmet på Windows Vista SP2 må oppdateringene "
    L"KB971512 og KB2117917 installeres. MP4-opptak fungerer ikke på Vista i den gjeldende versjonen. "
    L"Visningen krever Direct3D 11, ikke bare en eldre DirectX-kjøretid. MP4-opptak krever tilgjengelige "
    L"Media Foundation-komponenter og en H.264-koder.",
    L"ANIMERING OCH INSTÄLLNINGAR\r\nSpaceFlight: Oändlig böljande yta; Långdistansflygtur — "
    L"formföränderlig yta. Tilldela varje skärm exakt en animering. Textur växlar mellan texturerade ytor "
    L"och trådmodell. Fritt roterande kamera ändrar långsamt blickriktningen i alla tre dimensioner. Pauser "
    L"och vändningar lägger till slumpmässiga inbromsningar, pauser och byten av rotationsriktning; "
    L"flygningen framåt fortsätter. Hastigheten är 0–1600 %. Varje skärm har en oberoende slumpmässig scen "
    L"som återges med dess egen uppdateringsfrekvens. Huvudljus, fyllnadsljus, omgivningsljus och "
    L"konturljus kan slås på och av oberoende för de valda skärmarna. Belysningen gäller bara texturerade "
    L"ytor. Båda animationerna erbjuder Plan, Vågor eller Tratt. Tratten drar kameran inåt längs en "
    L"nedåtgående spiral.\r\n\r\nBILDSKÄRMAR\r\nMarkeringen av rader avgör vilka skärmar du redigerar och "
    L"är skild "
    L"från kryssrutorna som aktiverar animationsutgångarna. Ctrl+A markerar alla skärmar; Ctrl och Skift "
    L"ändrar markeringen. Alla animationsalternativ och reglage gäller de markerade skärmarna. Markeringen "
    L"sparas separat för EXE och SCR. Om alla skärmar var markerade inkluderas även nya skärmar. Olika "
    L"värden på de markerade skärmarna visas med obestämda kryssrutor och punktmönster på "
    L"alternativknappar, reglagehandtag och knappar för att slå på eller av alla alternativ. Reglagens "
    L"etiketter visar ett streck i stället för ett gemensamt värde. När du ändrar ett alternativ eller "
    L"klickar på ett reglage används värdet på alla markerade skärmar.\r\n\r\nANVÄNDNING\r\nSlå på eller av "
    L"animationsutgångarna med skärmarnas kryssrutor eller genom att dubbelklicka på deras rader. Varje "
    L"bildskärm använder en oberoende scen. Skärmbild sparar PNG och inspelningsknappen startar eller "
    L"stoppar MP4. Paus stannar animeringen. Programmet installerar eller avinstallerar även den inbyggda "
    L"skärmsläckaren. Inställningarna sparas fortlöpande. Programmet kan bara köras i en instans åt gången. "
    L"En ny start återställer det minimerade kontrollfönstret och för det längst fram. Använd Tab och "
    L"Skift+Tab för att flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett "
    L"kommando. Esc stänger det aktiva Hjälp- eller Om-fönstret; i kontrollfönstret avslutar det "
    L"programmet. Paus och blockering av skärmsläckaren gäller hela programmet oavsett markerade skärmar. "
    L"När blockeringen är på hindras Windows-skärmsläckaren bara medan en synlig animering som inte är "
    L"pausad visas på minst en skärm.\r\n\r\nSKÄRMBILDER OCH INSPELNING\r\nSkärmbilder och inspelningar "
    L"använder den första aktiva animeringsskärmen, inte en sammanslagen bild av alla skärmar. PNG använder "
    L"Bilder, MP4 Videor; om dessa mappar saknas används Dokument. Knappen Inspelningsinställningar väljer "
    L"Viewport eller TV. Viewport behåller animeringsskärmens storlek och uppdateringsfrekvens, upp till 60 "
    L"bilder per sekund. TV erbjuder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9, med 50, 25, "
    L"59.94 (60000/1001) eller 29.97 (30000/1001) bilder per sekund. Bildens proportioner bevaras; TV "
    L"använder progressiv BT.709-video med begränsat omfång och 4:2:0-sampling. Upplösning och bildfrekvens "
    L"kan bara väljas i TV-läge. Fönstret Inspelningsinställningar kan minimeras och blockerar inte de "
    L"andra programfönstren. OK sparar valen för nästa MP4-inspelning; Avbryt eller Esc ignorerar "
    L"obekräftade ändringar. Den inspelade skärmen kan inte väljas bort under inspelningen; ändringar av "
    L"andra skärmar stoppar inte inspelningen. Att avsluta programmet under en inspelning kräver "
    L"bekräftelse eftersom det också avslutar inspelningen.\r\n\r\nSYSTEMKRAV\r\nWindows 7 till Windows 11 "
    L"stöder alla funktioner, inklusive PNG-skärmbilder och MP4-inspelning. För att köra programmet på "
    L"Windows Vista SP2 måste uppdateringarna KB971512 och KB2117917 installeras. MP4-inspelning fungerar "
    L"inte på Vista i den aktuella versionen. Visningen kräver Direct3D 11, inte bara en äldre "
    L"DirectX-körningsmiljö. MP4-inspelning kräver tillgängliga Media Foundation-komponenter och en "
    L"H.264-kodare.",
    L"ANİMASYON VE AYARLAR\r\nSpaceFlight: Sonsuz dalgalanan yüzey; Uzun mesafeli uçuş — biçim değiştiren "
    L"yüzey. Her ekrana tam bir animasyon atayın. Doku, dokulu yüzeyler ile tel kafes modeli arasında geçiş "
    L"yapar. Serbest kamera dönüşü bakış yönünü üç boyutta yavaşça değiştirir. Duraklama ve ters dönüş, "
    L"dönüşe rastgele yavaşlamalar, duraklamalar ve ters yön değişimleri ekler; ileri uçuş devam eder. Hız "
    L"0–1600% aralığındadır. Her ekranın kendi yenileme hızında çizilen bağımsız rastgele bir sahnesi "
    L"vardır. Ana ışık, dolgu ışığı, ortam ışığı ve kenar aydınlatması seçili ekranlar için ayrı ayrı "
    L"açılıp kapatılabilir. Aydınlatma yalnızca dokulu yüzeylere uygulanır. Her iki animasyonda Düzlem, "
    L"Dalgalanma veya Huni seçilebilir. Huni, kamerayı aşağı doğru bir sarmal boyunca içeri "
    L"çeker.\r\n\r\nEKRANLAR\r\nSatır seçimi, hangi "
    L"ekranların düzenlendiğini belirler; animasyon çıkışlarını açan onay kutularından ayrıdır. Ctrl+A tüm "
    L"ekranları seçer; Ctrl ve Shift seçimi değiştirir. Tüm animasyon seçenekleri ve kaydırıcılar seçili "
    L"ekranlara uygulanır. Seçim EXE ve SCR için ayrı saklanır. Tüm ekranlar seçiliyse sonradan bağlanan "
    L"ekranlar da seçime katılır. Seçili ekranlardaki farklı değerler, belirsiz durumdaki onay kutuları ve "
    L"seçenek düğmelerinde, kaydırıcı tutamaçlarında ve tüm seçenekleri açıp kapatan düğmelerde noktalı "
    L"desenle gösterilir. Kaydırıcı etiketleri ortak bir değer yerine çizgi gösterir. Bir seçeneği "
    L"değiştirmek veya kaydırıcıya tıklamak bu değeri tüm seçili ekranlara "
    L"uygular.\r\n\r\nKULLANIM\r\nAnimasyon çıkışlarını ekran onay kutularıyla veya satırlarına çift "
    L"tıklayarak açıp kapatabilirsiniz. Her monitör bağımsız sahne kullanır. Anlık görüntü PNG kaydeder; "
    L"kayıt düğmesi MP4 kaydını başlatır veya bitirir. Duraklat animasyonu durdurur. Uygulama gömülü ekran "
    L"koruyucuyu da kurar veya kaldırır. Ayarlar sürekli kaydedilir. Uygulamanın aynı anda yalnızca bir "
    L"örneği çalışabilir. Yeniden başlatılması, simge durumuna küçültülmüş denetim penceresini geri yükler "
    L"ve ön plana getirir. Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir "
    L"komutu etkinleştirir. Esc, etkin Yardım veya Hakkında penceresini kapatır; denetim penceresinde "
    L"uygulamadan çıkar. Duraklatma ve ekran koruyucuyu engelleme, ekran seçiminden bağımsız olarak "
    L"uygulamanın tamamına uygulanır. Engelleme açıkken Windows ekran koruyucusu yalnızca en az bir ekranda "
    L"görünür ve duraklatılmamış animasyon varken engellenir.\r\n\r\nEKRAN GÖRÜNTÜLERİ VE KAYIT\r\nAnlık "
    L"görüntüler ve kayıtlar, tüm monitörlerin birleşik görüntüsünü değil, ilk etkin animasyon monitörünü "
    L"kullanır. PNG Resimler, MP4 Videolar klasörünü kullanır; bu klasörler yoksa Belgeler kullanılır. "
    L"Kayıt ayarları düğmesi Viewport veya TV seçimini açar. Viewport, animasyon monitörünün boyutlarını ve "
    L"yenileme hızını saniyede en fazla 60 kareyle korur. TV, 16:9 oranında 1920 × 1080, 1440 × 1080 veya "
    L"1280 × 720 çözünürlük ile saniyede 50, 25, 59.94 (60000/1001) veya 29.97 (30000/1001) kare sunar. "
    L"Görüntünün en boy oranı korunur; TV, sınırlı aralıklı, 4:2:0 örneklemeli ilerlemeli BT.709 video "
    L"kullanır. Çözünürlük ve kare hızı yalnızca TV modunda seçilebilir. Kayıt ayarları penceresi simge "
    L"durumuna küçültülebilir ve uygulamanın diğer pencerelerini engellemez. Tamam, seçenekleri bir sonraki "
    L"MP4 kaydı için kaydeder; İptal veya Esc onaylanmamış değişiklikleri iptal eder. Kayıt sırasında "
    L"kaydedilen ekranın seçimi kaldırılamaz; diğer ekranlardaki değişiklikler kaydı durdurmaz. Kayıt "
    L"sırasında uygulamayı kapatmak kaydı da durduracağı için onay gerektirir.\r\n\r\nSİSTEM "
    L"GEREKSİNİMLERİ\r\nWindows 7 ile Windows 11 arasındaki sürümler, PNG anlık görüntüler ve MP4 kaydı "
    L"dâhil tüm özellikleri destekler. Uygulamayı Windows Vista SP2'de çalıştırmak için KB971512 ve "
    L"KB2117917 güncellemelerini yüklemeniz gerekir. Geçerli sürümde MP4 kaydı Vista'da çalışmaz. "
    L"Görüntüleme, yalnızca eski bir DirectX çalışma zamanı değil, Direct3D 11 gerektirir. MP4 kaydı, "
    L"kullanılabilir Media Foundation bileşenleri ve bir H.264 kodlayıcı gerektirir.",
    L"ANIMATSIOON JA SÄTTED\r\nRiistvarakiirendusega lend lainetava pinna kohal. Lõputu lainetav pind; "
    L"Kauglend — muutuv pind. Valige igale kuvarile täpselt üks animatsioon. Tekstuuri märkeruut vahetab "
    L"tekstuuriga pinna ja traatmudeli vahel. Kaamera vaba pöörlemine muudab vaatesuunda aeglaselt kõigis "
    L"kolmes mõõtmes. Pausid ja pöördumised lisavad sellele juhuslikke aeglustusi, pause ja pöörlemissuuna "
    L"muutusi; edasilend jätkub. Kiirus on seatav vahemikus 0–1600%. Igal kuvaril on oma sõltumatu juhuslik "
    L"stseen ja värskendussagedusele vastav renderdus. Põhivalgust, täitevalgust, ümbritsevat valgust ja "
    L"kontuurivalgust saab valitud kuvaritel eraldi sisse ja välja lülitada. Valgustus kehtib ainult "
    L"tekstuuriga pindadele. Mõlemas animatsioonis saab valida tasandi, lained või lehtri. Lehter tõmbab "
    L"kaamera mööda laskuvat spiraali sissepoole.\r\n\r\nKUVARID\r\nValige loendis üks või mitu kuvaririda. "
    L"Ctrl+A valib kõik "
    L"read; Ctrl ja Shift võimaldavad valikut muuta. Animatsiooni juhtnupud ja liugurid mõjutavad ainult "
    L"valitud kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle märkeruuduga väljundi lubamine "
    L"on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja jaoks eraldi meelde. Kui varem olid "
    L"valitud kõik kuvarid, kaasatakse ka lisatud kuvarid. Valitud kuvarite erinevaid väärtusi näitavad "
    L"märkeruutude määramata olek ning raadionuppude, liugurite käepidemete ja kõigi valikute "
    L"lülitusnuppude punktimuster. Liuguri sildil on ühise väärtuse asemel kriips. Valiku muutmine või "
    L"liuguril klõpsamine määrab selle väärtuse kõigile valitud kuvaritele.\r\n\r\nKASUTAMINE\r\nKäivitage "
    L"SpaceFlight.exe. Sätteid salvestatakse jooksvalt ning rakendus töötab ühe eksemplarina. Kuvari "
    L"märkeruut või topeltklõps real lülitab selle animatsiooniväljundi sisse või välja. Animatsiooni saab "
    L"peatada ja jätkata. PNG-pilt ja MP4-video jäädvustavad esimese aktiivse animatsioonikuvari, mitte "
    L"kõiki kuvareid koos. Salvestatavat kuvarit ei saa salvestamise ajal välja lülitada; rakenduse "
    L"sulgemine nõuab siis kinnitust. Peatamine ja ekraanisäästja tõkestamine kehtivad kogu rakendusele, "
    L"sõltumata kuvarite valikust. Kui tõkestamine on sisse lülitatud, takistatakse Windowsi "
    L"ekraanisäästjat ainult seni, kuni vähemalt ühel kuvaril on nähtav peatamata animatsioon. Rakendus "
    L"saab paigaldada ja eemaldada sisseehitatud ekraanisäästja.\r\n\r\nKUVATÕMMISED JA "
    L"SALVESTAMINE\r\nSalvestussätetes valige Viewport või TV. Viewport säilitab kuvari mõõtmed ja "
    L"värskendussageduse kuni 60 kaadrit sekundis. TV pakub 1920 × 1080, 1440 × 1080 või 1280 × 720 "
    L"väljundit kuvasuhtega 16:9 ning 50, 25, 59.94 (60000/1001) või 29.97 (30000/1001) kaadrit sekundis. "
    L"TV-video on progressiivne BT.709, piiratud vahemikuga ja 4:2:0 värvialamdiskreetimisega. Pildi "
    L"kuvasuhe säilib ja täiteribad on mustad. OK rakendab valikud järgmisele salvestusele; Loobu või Esc "
    L"tühistab kinnitamata muudatused. Salvestussätted, spikker ja teave ei blokeeri teisi aknaid ning neid "
    L"saab minimeerida. Tab ja Shift+Tab liigutavad fookust, Enter vajutab fookusega nuppu ning Esc sulgeb "
    L"aktiivse lisaakna.\r\n\r\nSÜSTEEMINÕUDED\r\nWindows 7–11 toetab kõiki funktsioone. Windows Vista SP2 "
    L"jaoks tuleb paigaldada värskendused KB971512 ja KB2117917; MP4 salvestamine Vistas ei tööta. Vaja on "
    L"Direct3D 11 tuge ning MP4 jaoks Media Foundationi ja H.264 kodeerijat. Liides ja dokumentatsioon on "
    L"saadaval 36 keeles.",
    L"BEOCHAN AGUS SOCRUITHE\r\nEitilt os cionn dromchla tonnúil le luasghéarú crua-earraí. Dromchla "
    L"tonnúil gan teorainn; Eitilt fhada — dromchla athraitheach. Roghnaigh beochan amháin do gach "
    L"monatóir. Athraíonn Uigeacht idir dromchla uigeachtaithe agus samhail sreangfhráma. Rothlaíonn rothlú "
    L"saor an cheamara an radharc go mall sna trí thoise. Cuireann Sosanna agus aisiompuithe coscánú, "
    L"sosanna agus athruithe treo randamacha leis an rothlú; leanann an eitilt chun tosaigh. Tá luas "
    L"0–1600% ar fáil. Tá radharc randamach neamhspleách ag gach monatóir agus déantar rindreáil de réir a "
    L"ráta athnuachana féin. Is féidir an príomhsholas, an solas líonta, an solas comhthimpeallach agus an "
    L"solas imill a athrú go neamhspleách do na taispeántais roghnaithe. Ní bhaineann an soilsiú ach le "
    L"dromchlaí uigeachtaithe. Tá Plána, Tonnta nó Tonnadóir ar fáil don dá bheochan. Tarraingíonn an "
    L"tonnadóir an ceamara isteach ar bhís a théann síos.\r\n\r\nTAISPEÁNTAIS\r\nRoghnaigh ró amháin nó "
    L"níos mó sa liosta monatóirí. "
    L"Roghnaíonn Ctrl+A gach ró; úsáid Ctrl agus Shift chun an roghnú a athrú. Ní athraíonn rialuithe agus "
    L"sleamhnáin na beochana ach socruithe na monatóirí roghnaithe. Ní hionann ró a roghnú agus aschur an "
    L"mhonatóra a chumasú lena bhosca seiceála. Cuimhnítear an roghnú ar leith don fheidhmchlár agus don "
    L"spárálaí. Má bhí gach monatóir roghnaithe, cuirtear monatóirí nua leis an roghnú freisin. Léirítear "
    L"luachanna éagsúla ar na monatóirí roghnaithe le boscaí seiceála i staid neamhchinnte agus le patrún "
    L"poncanna ar chnaipí raidió, ar ghreimíní sleamhnán agus ar na cnaipí a chumasaíonn nó a "
    L"dhíchumasaíonn gach rogha. Taispeántar dais ar lipéad an tsleamhnáin in ionad luach coiteann. Nuair a "
    L"athraítear rogha nó a chliceáiltear sleamhnán, cuirtear an luach sin i bhfeidhm ar gach monatóir "
    L"roghnaithe.\r\n\r\nRIALÚ\r\nRith SpaceFlight.exe. Sábháiltear socruithe go leanúnach agus ní ritheann "
    L"ach cóip amháin den fheidhmchlár. Cumasaíonn nó díchumasaíonn bosca seiceála an mhonatóra nó "
    L"déchliceáil ar a ró an t-aschur beochana. Is féidir an bheochan a chur ar sos agus a atosú. Gabhann "
    L"PNG agus MP4 an chéad mhonatóir beochana gníomhach, ní na monatóirí uile le chéile. Ní féidir an "
    L"monatóir atá á thaifeadadh a dhíchumasú; teastaíonn deimhniú chun an feidhmchlár a dhúnadh agus "
    L"taifeadadh ar siúl. Baineann sos agus cosc an spárálaí scáileáin leis an bhfeidhmchlár iomlán, beag "
    L"beann ar na monatóirí roghnaithe. Nuair atá an cosc cumasaithe, ní choisctear spárálaí scáileáin "
    L"Windows ach fad a bhíonn beochan infheicthe nach bhfuil ar sos ar mhonatóir amháin ar a laghad. Is "
    L"féidir an spárálaí leabaithe a shuiteáil nó a dhíshuiteáil ón bhfeidhmchlár.\r\n\r\nGABHÁLACHA "
    L"SCÁILEÁIN AGUS TAIFEADADH\r\nRoghnaigh Viewport nó TV i socruithe taifeadta. Coinníonn Viewport toisí "
    L"agus ráta athnuachana an mhonatóra, suas le 60 fráma sa soicind. Tairgeann TV 1920 × 1080, 1440 × "
    L"1080 nó 1280 × 720 i gcóimheas 16:9 ag 50, 25, 59.94 (60000/1001) nó 29.97 (30000/1001) fráma sa "
    L"soicind. Is físeán forásach BT.709 é, le raon teoranta agus foshampláil datha 4:2:0. Coinnítear "
    L"cóimheas an phictiúir agus tá na barraí líonta dubh. Cuireann OK roghanna i bhfeidhm ar an gcéad "
    L"taifeadadh eile; cealaíonn Cealaigh nó Esc athruithe neamhdheimhnithe. Ní chuireann socruithe "
    L"taifeadta, Cabhair ná Maidir leis bac ar fhuinneoga eile agus is féidir iad a íoslaghdú. Bogann Tab "
    L"agus Shift+Tab an fócas; gníomhaíonn Enter an cnaipe faoi fhócas agus dúnann Esc an fhuinneog chúnta "
    L"ghníomhach.\r\n\r\nRIACHTANAIS CHÓRAIS\r\nTacaíonn Windows 7–11 leis na gnéithe uile. Ar Windows "
    L"Vista SP2 ní mór nuashonruithe KB971512 agus KB2117917 a shuiteáil; ní oibríonn taifeadadh MP4 ar "
    L"Vista. Teastaíonn tacaíocht Direct3D 11, agus Media Foundation agus ionchódóir H.264 le haghaidh MP4. "
    L"Tá an comhéadan agus an doiciméadú ar fáil i 36 teanga.",
    L"ANIMACIJA IR NUOSTATOS\r\nAparatine įranga spartinamas skrydis virš banguojančio paviršiaus. Begalinė "
    L"banguojanti plokštuma; Tolimas skrydis — kintantis paviršius. Kiekvienam monitoriui pasirinkite vieną "
    L"animaciją. Tekstūros langelis perjungia tekstūruotą paviršių ir vielinį modelį. Laisvas kameros "
    L"sukimasis lėtai keičia žiūrėjimo kryptį visose trijose dimensijose. Pauzės ir apsisukimai prideda "
    L"atsitiktinį lėtėjimą, pauzes ir sukimosi krypties keitimą; skrydis pirmyn tęsiasi. Galimas 0–1600% "
    L"greitis. Kiekvienas monitorius turi nepriklausomą atsitiktinę sceną, atvaizduojamą jo atnaujinimo "
    L"dažniu. Pagrindinę, užpildančią, aplinkos ir kontūrinę šviesą galima atskirai įjungti pasirinktiems "
    L"ekranams. Apšvietimas taikomas tik tekstūruotiems paviršiams. Abiejose animacijose galima pasirinkti "
    L"plokštumą, bangas arba piltuvą. Piltuvas traukia kamerą į vidų žemyn besisukančia "
    L"spirale.\r\n\r\nMONITORIAI\r\nMonitorių sąraše "
    L"pasirinkite vieną ar kelias eilutes. Ctrl+A pasirenka visas, o Ctrl ir Shift leidžia keisti "
    L"pasirinkimą. Animacijos valdikliai ir slankikliai keičia tik pasirinktų monitorių nuostatas. Eilutės "
    L"pasirinkimas nėra tas pats, kas animacijos išvesties įjungimas jos žymimuoju langeliu. Pasirinkimas "
    L"atskirai įsimenamas programai ir užsklandai. Jei buvo pasirinkti visi monitoriai, į pasirinkimą "
    L"įtraukiami ir naujai prijungti monitoriai. Skirtingas pasirinktų monitorių reikšmes rodo neapibrėžta "
    L"žymimųjų langelių būsena ir taškinis raštas ant parinkčių mygtukų, slankiklių rankenėlių bei visų "
    L"parinkčių įjungimo ir išjungimo mygtukų. Slankiklių užrašuose vietoj bendros reikšmės rodomas "
    L"brūkšnys. Pakeitus parinktį arba spustelėjus slankiklį, ta reikšmė pritaikoma visiems pasirinktiems "
    L"monitoriams.\r\n\r\nVALDYMAS\r\nPaleiskite SpaceFlight.exe. Nuostatos išsaugomos nuolat, veikia tik "
    L"vienas programos egzempliorius. Monitoriaus langelis arba dvigubas eilutės spustelėjimas įjungia ar "
    L"išjungia animacijos išvestį. Animaciją galima pristabdyti ir tęsti. PNG ir MP4 fiksuoja pirmą aktyvų "
    L"animacijos monitorių, o ne bendrą visų monitorių vaizdą. Įrašomo monitoriaus išjungti negalima; "
    L"uždarant programą vykstant įrašymui reikia patvirtinimo. Pristabdymas ir užsklandos blokavimas "
    L"taikomi visai programai, nepriklausomai nuo monitorių pasirinkimo. Įjungus blokavimą, Windows "
    L"užsklanda neleidžiama tik kol bent viename monitoriuje matoma nepristabdyta animacija. Programa gali "
    L"įdiegti ir pašalinti į ją įtrauktą užsklandą.\r\n\r\nEKRANO KOPIJOS IR ĮRAŠYMAS\r\nĮrašymo nuostatose "
    L"pasirinkite Viewport arba TV. Viewport išsaugo monitoriaus matmenis ir dažnį iki 60 kadrų per "
    L"sekundę. TV siūlo 1920 × 1080, 1440 × 1080 arba 1280 × 720 išvestį 16:9 santykiu bei 50, 25, 59.94 "
    L"(60000/1001) arba 29.97 (30000/1001) kadrų per sekundę. TV vaizdas progresinis, BT.709, riboto "
    L"diapazono ir 4:2:0 spalvų diskretizavimo. Vaizdo proporcijos išlieka, užpildymo juostos juodos. OK "
    L"pritaiko nuostatas kitam įrašui, Atšaukti arba Esc atmeta nepatvirtintus pakeitimus. Įrašymo, žinyno "
    L"ir informacijos langai neblokuoja kitų langų ir gali būti sumažinti. Tab ir Shift+Tab keičia įvesties "
    L"vietą, Enter paspaudžia aktyvų mygtuką, Esc uždaro aktyvų papildomą langą.\r\n\r\nSISTEMOS "
    L"REIKALAVIMAI\r\nWindows 7–11 palaiko visas funkcijas. Windows Vista SP2 būtina įdiegti naujinimus "
    L"KB971512 ir KB2117917; MP4 įrašymas Vistoje neveikia. Reikalingas Direct3D 11 palaikymas, o MP4 "
    L"įrašymui Media Foundation ir H.264 koduotuvas. Sąsaja ir dokumentacija pateikiamos 36 kalbomis.",
    L"ANIMĀCIJA UN IESTATĪJUMI\r\nAparatūras paātrināts lidojums virs viļņojošas virsmas. Bezgalīga "
    L"viļņojoša virsma; Tāls lidojums — mainīga virsma. Katram monitoram izvēlieties tieši vienu animāciju. "
    L"Tekstūras rūtiņa pārslēdz teksturētu virsmu un stiepļu modeli. Brīva kameras rotācija lēnām maina "
    L"skatiena virzienu visās trijās dimensijās. Pauzes un virzienmaiņa pievieno nejaušu palēninājumu, "
    L"pauzes un rotācijas virziena maiņu; lidojums uz priekšu turpinās. Pieejams ātrums 0–1600%. Katram "
    L"monitoram ir neatkarīga nejauša aina, ko renderē tā atsvaidzināšanas frekvencē. Pamata, aizpildošo, "
    L"apkārtējo un kontūru gaismu atlasītajiem monitoriem var ieslēgt neatkarīgi. Apgaismojums attiecas "
    L"tikai uz teksturētām virsmām. Abās animācijās var izvēlēties plakni, viļņus vai piltuvi. Piltuve "
    L"ievelk kameru iekšup pa lejupejošu spirāli.\r\n\r\nMONITORI\r\nMonitoru sarakstā atlasiet vienu vai "
    L"vairākas rindas. Ctrl+A "
    L"atlasa visas, bet Ctrl un Shift ļauj mainīt atlasi. Animācijas vadīklas un slīdņi maina tikai "
    L"atlasīto monitoru iestatījumus. Rindas atlasīšana nav tas pats, kas animācijas izvades ieslēgšana ar "
    L"izvēles rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un ekrānsaudzētājam. Ja bija atlasīti visi "
    L"monitori, atlasē iekļauj arī jaunpievienotos monitorus. Atšķirīgas vērtības atlasītajos monitoros "
    L"norāda nenoteikts izvēles rūtiņu stāvoklis un punktots raksts uz radiopogām, slīdņu rokturiem un visu "
    L"iespēju ieslēgšanas vai izslēgšanas pogām. Slīdņu etiķetēs kopīgas vērtības vietā redzama domuzīme. "
    L"Mainot iespēju vai noklikšķinot uz slīdņa, šī vērtība tiek piemērota visiem atlasītajiem "
    L"monitoriem.\r\n\r\nLIETOŠANA\r\nPalaidiet SpaceFlight.exe. Iestatījumi tiek saglabāti nepārtraukti, "
    L"un darbojas tikai viena lietotnes instance. Monitora rūtiņa vai dubultklikšķis uz rindas ieslēdz vai "
    L"izslēdz tā animācijas izvadi. Animāciju var pauzēt un turpināt. PNG un MP4 uzņem pirmo aktīvo "
    L"animācijas monitoru, nevis visu monitoru kopējo attēlu. Ierakstāmo monitoru nevar izslēgt; aizverot "
    L"lietotni ieraksta laikā, nepieciešams apstiprinājums. Pauze un ekrānsaudzētāja bloķēšana attiecas uz "
    L"visu lietotni neatkarīgi no monitoru atlases. Ja bloķēšana ir ieslēgta, Windows ekrānsaudzētājs tiek "
    L"bloķēts tikai tik ilgi, kamēr vismaz vienā monitorā ir redzama nepauzēta animācija. Lietotne var "
    L"instalēt vai atinstalēt tajā iebūvēto ekrānsaudzētāju.\r\n\r\nEKRĀNUZŅĒMUMI UN "
    L"IERAKSTĪŠANA\r\nIeraksta iestatījumos izvēlieties Viewport vai TV. Viewport saglabā monitora izmērus "
    L"un frekvenci līdz 60 kadriem sekundē. TV piedāvā 1920 × 1080, 1440 × 1080 vai 1280 × 720 izvadi ar "
    L"16:9 malu attiecību un 50, 25, 59.94 (60000/1001) vai 29.97 (30000/1001) kadriem sekundē. TV video ir "
    L"progresīvs BT.709 ar ierobežotu diapazonu un 4:2:0 krāsu apakšiztveršanu. Attēla proporcijas "
    L"saglabājas, aizpildījuma joslas ir melnas. OK piemēro izvēles nākamajam ierakstam, Atcelt vai Esc "
    L"atmet neapstiprinātās izmaiņas. Ieraksta iestatījumu, palīdzības un informācijas logi nebloķē citus "
    L"logus un ir minimizējami. Tab un Shift+Tab pārvieto fokusu, Enter aktivizē fokusēto pogu, Esc aizver "
    L"aktīvo palīglogu.\r\n\r\nSISTĒMAS PRASĪBAS\r\nWindows 7–11 atbalsta visas funkcijas. Windows Vista "
    L"SP2 jāinstalē atjauninājumi KB971512 un KB2117917; MP4 ierakstīšana Vistā nedarbojas. Nepieciešams "
    L"Direct3D 11 atbalsts, bet MP4 vajadzīgi Media Foundation un H.264 kodētājs. Saskarne un dokumentācija "
    L"ir pieejama 36 valodās.",
    L"ANIMÁCIÓ ÉS BEÁLLÍTÁSOK\r\nHardveresen gyorsított repülés hullámzó felület felett. Végtelen hullámzó "
    L"felület; Távolsági repülés — változó felület. Monitoronként pontosan egy animáció választható. A "
    L"Textúra jelölőnégyzet a textúrázott felület és a drótváz között vált. A kamera szabad forgása lassan "
    L"változtatja a nézetet mindhárom dimenzióban. A Szünetek és irányváltás véletlenszerű lassításokat, "
    L"szüneteket és forgásirányváltásokat ad hozzá; az előrehaladás folytatódik. A sebesség 0–1600%. Minden "
    L"monitor önálló véletlenszerű jelenetet kap, saját frissítési gyakoriságához igazodó megjelenítéssel. "
    L"A főfény, a derítőfény, a környezeti fény és a peremfény külön kapcsolható a kijelölt monitorokon. A "
    L"világítás csak a textúrázott felületekre vonatkozik. Mindkét animációnál sík, hullámzás vagy tölcsér "
    L"választható. A tölcsér lefelé haladó spirál mentén húzza befelé a "
    L"kamerát.\r\n\r\nMONITOROK\r\nJelöljön ki egy vagy "
    L"több sort a monitorok listájában. A Ctrl+A mindet kijelöli; a Ctrl és a Shift módosítja a kijelölést. "
    L"Az animáció vezérlői és csúszkái csak a kijelölt monitorok beállításait változtatják. A sor "
    L"kijelölése és az animációs kimenet jelölőnégyzetes engedélyezése külön művelet. A kijelölést az "
    L"alkalmazás és a képernyőkímélő külön megjegyzi. Ha korábban minden monitor ki volt jelölve, az "
    L"újonnan csatlakoztatott monitorok is bekerülnek a kijelölésbe. A kijelölt monitorok eltérő értékeit a "
    L"jelölőnégyzetek határozatlan állapota, valamint a választógombok, a csúszkafogantyúk és az összes "
    L"beállítást be- vagy kikapcsoló gombok pontozása jelzi. A csúszkák felirata közös érték helyett "
    L"gondolatjelet mutat. Egy beállítás módosítása vagy a csúszkára kattintás az adott értéket minden "
    L"kijelölt monitorra alkalmazza.\r\n\r\nKEZELÉS\r\nIndítsa el a SpaceFlight.exe fájlt. A beállítások "
    L"folyamatosan mentődnek, és csak egy alkalmazáspéldány fut. A monitor jelölőnégyzete vagy a sorra "
    L"történő dupla kattintás kapcsolja az animációs kimenetet. Az animáció szüneteltethető és folytatható. "
    L"A PNG és az MP4 az első aktív animációs monitort rögzíti, nem az összes monitor egyesített képét. A "
    L"rögzített monitor felvétel közben nem kapcsolható ki; az alkalmazás bezárásához ekkor megerősítés "
    L"szükséges. A szüneteltetés és a képernyőkímélő tiltása a teljes alkalmazásra vonatkozik, a monitorok "
    L"kijelölésétől függetlenül. Bekapcsolt tiltás esetén a Windows képernyőkímélője csak addig nem indul "
    L"el, amíg legalább egy monitoron látható, nem szünetelő animáció fut. Az alkalmazás telepítheti és "
    L"eltávolíthatja a beágyazott képernyőkímélőt.\r\n\r\nKÉPERNYŐKÉPEK ÉS FELVÉTEL\r\nA felvételi "
    L"beállításoknál Viewport vagy TV választható. A Viewport megőrzi a monitor képméretét és frissítési "
    L"gyakoriságát, legfeljebb 60 képkocka/másodpercig. A TV felbontása 1920 × 1080, 1440 × 1080 vagy 1280 "
    L"× 720, képaránya 16:9; sebessége 50, 25, 59.94 (60000/1001) vagy 29.97 (30000/1001) "
    L"képkocka/másodperc. A TV videó progresszív BT.709, korlátozott tartománnyal és 4:2:0 "
    L"színmintavételezéssel. A kép arányai megmaradnak, a kitöltősávok feketék. Az OK a következő "
    L"felvételhez menti a választást; a Mégse vagy Esc elveti a nem jóváhagyott módosításokat. A felvételi "
    L"beállítások, a Súgó és a Névjegy nem blokkolja a többi ablakot és kis méretűre állítható. A Tab és "
    L"Shift+Tab mozgatja a fókuszt, az Enter aktiválja a fókuszban levő gombot, az Esc bezárja az aktív "
    L"kiegészítő ablakot.\r\n\r\nRENDSZERKÖVETELMÉNYEK\r\nA Windows 7–11 minden funkciót támogat. Windows "
    L"Vista SP2 alatt telepíteni kell a KB971512 és KB2117917 frissítést; az MP4-felvétel Vistán nem "
    L"működik. Direct3D 11 támogatás szükséges, az MP4-hez Media Foundation és H.264-kódoló is kell. A "
    L"kezelőfelület és a dokumentáció 36 nyelven érhető el.",
    L"ANIMAZZJONI U SETTINGS\r\nTitjira fuq wiċċ li jimmewweġ aċċellerata bil-ħardwer. Wiċċ infinit li "
    L"jimmewweġ; Titjira fit-tul — wiċċ li jinbidel. Agħżel animazzjoni waħda biss għal kull moniter. Nisġa "
    L"taqleb bejn wiċċ b’nisġa u mudell bil-wireframe. Ir-rotazzjoni libera tal-kamera tbiddel "
    L"id-direzzjoni tal-ħarsa bil-mod fit-tliet dimensjonijiet. L-għażla Pawżi u bidliet fid-direzzjoni "
    L"żżid deċelerazzjonijiet, pawżi u treġġigħ lura tar-rotazzjoni b’mod każwali; it-titjira ’l quddiem "
    L"tkompli. Il-veloċità hija 0–1600%. Kull moniter għandu xena każwali indipendenti li tintwera bir-rata "
    L"ta’ aġġornament tiegħu. Id-dawl prinċipali, id-dawl ta’ mili, id-dawl ambjentali u d-dawl tal-kontorn "
    L"jistgħu jinxtegħlu separatament għall-iskrins magħżula. Id-dawl japplika biss għall-uċuħ bit-tessut. "
    L"Iż-żewġ animazzjonijiet joffru Pjan, Mewġ jew Lembut. Il-lembut jiġbed il-kamera ’l ġewwa tul spirali "
    L"nieżla.\r\n\r\nSKRINS\r\nAgħżel ringiela waħda jew aktar fil-lista tal-moniters. Ctrl+A "
    L"jagħżilhom kollha; Ctrl u Shift ibiddlu l-għażla. Il-kontrolli u s-sliders tal-animazzjoni jibdlu "
    L"biss is-settings tal-moniters magħżula. L-għażla ta’ ringiela hija differenti mill-attivazzjoni "
    L"tal-output permezz tal-kaxxa tal-marka. L-għażla tinżamm separatament għall-applikazzjoni u "
    L"għall-iscreen saver. Jekk il-moniters kollha kienu magħżula, il-moniters ġodda jiddaħħlu wkoll "
    L"fl-għażla. Valuri differenti fuq il-moniters magħżula jintwerew bi stat indeterminat tal-kaxxi "
    L"tal-marka u b’disinn bit-tikek fuq il-buttuni tar-radju, il-manki tas-sliders u l-buttuni li jattivaw "
    L"jew jiddiżattivaw l-għażliet kollha. It-tikketti tas-sliders juru sing minflok valur komuni. Meta "
    L"tibdel għażla jew tikklikkja slider, dak il-valur jiġi applikat għall-moniters magħżula "
    L"kollha.\r\n\r\nKONTROLLI\r\nĦaddem SpaceFlight.exe. Is-settings jiġu ssejvjati kontinwament u taħdem "
    L"istanza waħda biss. Il-kaxxa tal-moniter jew klikk doppja fuq ir-ringiela tattiva jew tiddiżattiva "
    L"l-output tal-animazzjoni. Tista’ tissospendi u tkompli l-animazzjoni. PNG u MP4 jaqbdu l-ewwel "
    L"moniter tal-animazzjoni attiv, mhux immaġni magħquda tal-moniters kollha. Il-moniter li qed jiġi "
    L"rreġistrat ma jistax jiġi diżattivat; l-għeluq tal-applikazzjoni waqt reġistrazzjoni jeħtieġ "
    L"konferma. Is-sospensjoni u l-imblukkar tal-iscreen saver japplikaw għall-applikazzjoni kollha, "
    L"irrispettivament mill-moniters magħżula. Meta l-imblukkar ikun attiv, l-iscreen saver ta’ Windows "
    L"jiġi mblukkat biss waqt li jkun hemm animazzjoni viżibbli mhux sospiża fuq mill-inqas moniter wieħed. "
    L"L-applikazzjoni tinstalla jew tneħħi l-iscreen saver inkorporat.\r\n\r\nRITRATTI TAL-ISKRIN U "
    L"REĠISTRAZZJONI\r\nFis-settings tar-reġistrazzjoni agħżel Viewport jew TV. Viewport iżomm "
    L"id-dimensjonijiet u r-rata ta’ aġġornament tal-moniter, sa 60 frejm kull sekonda. TV joffri 1920 × "
    L"1080, 1440 × 1080 jew 1280 × 720 f’16:9, b’50, 25, 59.94 (60000/1001) jew 29.97 (30000/1001) frejm "
    L"kull sekonda. Il-vidjo TV huwa progressiv BT.709, b’medda limitata u sottokampjunar tal-kulur 4:2:0. "
    L"Il-proporzjonijiet jinżammu u l-faxex ta’ mili huma suwed. OK isalva l-għażliet għar-reġistrazzjoni "
    L"li jmiss; Ikkanċella jew Esc jarmi bidliet mhux ikkonfermati. It-twieqi tar-reġistrazzjoni, Għajnuna "
    L"u Dwar ma jimblukkawx twieqi oħra u jistgħu jiġu minimizzati. Tab u Shift+Tab ibiddlu l-fokus, Enter "
    L"jattiva l-buttuna fil-fokus u Esc jagħlaq it-tieqa awżiljarja attiva.\r\n\r\nREKWIŻITI "
    L"TAS-SISTEMA\r\nWindows 7–11 jappoġġja l-funzjonijiet kollha. Fuq Windows Vista SP2 għandhom jiġu "
    L"installati l-aġġornamenti KB971512 u KB2117917; ir-reġistrazzjoni MP4 ma taħdimx fuq Vista. Huwa "
    L"meħtieġ Direct3D 11 u, għall-MP4, Media Foundation u encoder H.264. L-interface u d-dokumentazzjoni "
    L"huma disponibbli f’36 lingwa.",
    L"ANIMATIE EN INSTELLINGEN\r\nHardwareversnelde vlucht boven een golvend oppervlak. Oneindig golvend "
    L"oppervlak; Langeafstandsvlucht — veranderend oppervlak. Kies precies één animatie per beeldscherm. "
    L"Textuur schakelt tussen een getextureerd oppervlak en een draadmodel. Vrije camerarotatie verandert "
    L"de kijkrichting langzaam in alle drie dimensies. De optie Pauzes en omkeren voegt willekeurige "
    L"vertragingen, pauzes en omkeringen van de rotatie toe; de voorwaartse vlucht gaat door. De snelheid "
    L"is instelbaar op 0–1600%. Elk beeldscherm heeft een onafhankelijke willekeurige scène en wordt op "
    L"zijn eigen vernieuwingsfrequentie aangestuurd. Hoofdlicht, invullicht, omgevingslicht en randlicht "
    L"kunnen onafhankelijk worden geschakeld voor de geselecteerde beeldschermen. De verlichting geldt "
    L"alleen voor oppervlakken met textuur. Beide animaties bieden Vlak, Golven of Trechter. De trechter "
    L"trekt de camera langs een dalende spiraal naar binnen.\r\n\r\nBEELDSCHERMEN\r\nSelecteer één of meer "
    L"beeldschermrijen in de lijst. Ctrl+A selecteert alles; met Ctrl en Shift past u de selectie aan. "
    L"Animatieknoppen en schuifregelaars wijzigen alleen de instellingen van de geselecteerde "
    L"beeldschermen. Een rij selecteren is iets anders dan de animatie-uitvoer inschakelen met het "
    L"selectievakje. De selectie wordt apart onthouden voor de toepassing en de schermbeveiliging. Als alle "
    L"beeldschermen waren geselecteerd, worden nieuw aangesloten beeldschermen ook geselecteerd. "
    L"Verschillende waarden op geselecteerde beeldschermen worden aangegeven door selectievakjes in "
    L"onbepaalde toestand en een stippelpatroon op keuzerondjes, schuifknoppen en knoppen om alle opties in "
    L"of uit te schakelen. De labels van schuifregelaars tonen een streepje in plaats van een "
    L"gemeenschappelijke waarde. Een optie wijzigen of op een schuifregelaar klikken past die waarde toe op "
    L"alle geselecteerde beeldschermen.\r\n\r\nBEDIENING\r\nStart SpaceFlight.exe. Instellingen worden "
    L"doorlopend opgeslagen en er draait slechts één exemplaar van de toepassing. Het selectievakje of een "
    L"dubbelklik op de beeldschermrij schakelt de animatie-uitvoer in of uit. U kunt de animatie pauzeren "
    L"en hervatten. PNG en MP4 leggen het eerste actieve animatiebeeldscherm vast, niet een gecombineerd "
    L"beeld van alle schermen. Het opgenomen beeldscherm kan niet worden uitgeschakeld; afsluiten tijdens "
    L"een opname vereist bevestiging. Pauzeren en het blokkeren van de schermbeveiliging gelden voor de "
    L"hele toepassing, ongeacht de beeldschermselectie. Als blokkering is ingeschakeld, wordt de "
    L"Windows-schermbeveiliging alleen tegengehouden zolang op minstens één beeldscherm een zichtbare, "
    L"niet-gepauzeerde animatie draait. De toepassing kan de ingebouwde schermbeveiliging installeren of "
    L"verwijderen.\r\n\r\nSCHERMAFBEELDINGEN EN OPNAMEN\r\nKies Viewport of TV in de opname-instellingen. "
    L"Viewport behoudt de afmetingen en vernieuwingsfrequentie van het beeldscherm tot 60 frames per "
    L"seconde. TV biedt 1920 × 1080, 1440 × 1080 of 1280 × 720 met beeldverhouding 16:9 en 50, 25, 59.94 "
    L"(60000/1001) of 29.97 (30000/1001) frames per seconde. TV gebruikt progressieve BT.709-video met "
    L"beperkt bereik en 4:2:0-kleursubsampling. De beeldverhouding blijft behouden en opvulbalken zijn "
    L"zwart. OK bewaart de opties voor de volgende opname; Annuleren of Esc verwerpt onbevestigde "
    L"wijzigingen. Opname-instellingen, Help en Info blokkeren andere vensters niet en kunnen worden "
    L"geminimaliseerd. Tab en Shift+Tab verplaatsen de focus, Enter activeert de knop met focus en Esc "
    L"sluit het actieve hulpvenster.\r\n\r\nSYSTEEMVEREISTEN\r\nWindows 7–11 ondersteunt alle functies. "
    L"Voor Windows Vista SP2 moet u updates KB971512 en KB2117917 installeren; MP4-opname werkt niet op "
    L"Vista. Direct3D 11-ondersteuning is vereist; voor MP4 zijn ook Media Foundation en een H.264-encoder "
    L"nodig. Interface en documentatie zijn beschikbaar in 36 talen.",
    L"ANIMAȚIE ȘI SETĂRI\r\nZbor deasupra unei suprafețe ondulate accelerat hardware. Suprafață ondulată "
    L"infinită; Zbor la distanță — suprafață variabilă. Alegeți exact o animație pentru fiecare monitor. "
    L"Textură comută între suprafața texturată și modelul de sârmă. Rotirea liberă a camerei schimbă lent "
    L"direcția privirii în toate cele trei dimensiuni. Pauze și inversări adaugă încetiniri, pauze și "
    L"inversări ale rotației la intervale aleatorii; zborul înainte continuă. Viteza este 0–1600%. Fiecare "
    L"monitor are o scenă aleatorie independentă, randată la propria rată de reîmprospătare. Lumina "
    L"principală, lumina de umplere, lumina ambiantă și lumina de contur pot fi comutate separat pentru "
    L"ecranele selectate. Iluminarea se aplică doar suprafețelor texturate. Ambele animații oferă Plan, "
    L"Ondulații sau Pâlnie. Pâlnia atrage camera spre interior de-a lungul unei spirale "
    L"descendente.\r\n\r\nMONITOARE\r\nSelectați "
    L"unul sau mai multe rânduri din lista monitoarelor. Ctrl+A le selectează pe toate; Ctrl și Shift "
    L"modifică selecția. Comenzile și glisoarele animației schimbă numai setările monitoarelor selectate. "
    L"Selectarea unui rând diferă de activarea ieșirii prin caseta sa de selectare. Selecția este reținută "
    L"separat pentru aplicație și economizor. Dacă erau selectate toate monitoarele, sunt incluse și cele "
    L"conectate ulterior. Valorile diferite de pe monitoarele selectate sunt indicate prin starea "
    L"nedeterminată a casetelor de selectare și un model punctat pe butoanele radio, mânerele glisoarelor "
    L"și butoanele de activare sau dezactivare a tuturor opțiunilor. Etichetele glisoarelor afișează o "
    L"liniuță în locul unei valori comune. Modificarea unei opțiuni sau clicul pe un glisor aplică acea "
    L"valoare tuturor monitoarelor selectate.\r\n\r\nCOMENZI\r\nRulați SpaceFlight.exe. Setările se "
    L"salvează continuu și rulează o singură instanță. Caseta monitorului sau un dublu clic pe rând "
    L"activează ori dezactivează ieșirea animației. Animația poate fi pusă în pauză și reluată. PNG și MP4 "
    L"capturează primul monitor de animație activ, nu imaginea combinată a tuturor monitoarelor. Monitorul "
    L"înregistrat nu poate fi dezactivat; închiderea aplicației în timpul înregistrării necesită "
    L"confirmare. Pauza și blocarea economizorului se aplică întregii aplicații, indiferent de selecția "
    L"monitoarelor. Când blocarea este activată, economizorul Windows este împiedicat numai cât timp pe cel "
    L"puțin un monitor este vizibilă o animație care nu este în pauză. Aplicația poate instala sau "
    L"dezinstala economizorul încorporat.\r\n\r\nCAPTURI ȘI ÎNREGISTRARE\r\nÎn setările de înregistrare "
    L"alegeți Viewport sau TV. Viewport păstrează dimensiunile și rata de reîmprospătare a monitorului, "
    L"până la 60 de cadre pe secundă. TV oferă 1920 × 1080, 1440 × 1080 sau 1280 × 720 în 16:9, la 50, 25, "
    L"59.94 (60000/1001) sau 29.97 (30000/1001) cadre pe secundă. Videoul TV este progresiv BT.709, cu "
    L"interval limitat și subeșantionare cromatică 4:2:0. Proporțiile imaginii se păstrează, iar benzile de "
    L"completare sunt negre. OK salvează opțiunile pentru următoarea înregistrare; Anulare sau Esc renunță "
    L"la schimbările neconfirmate. Ferestrele de înregistrare, ajutor și informații nu blochează celelalte "
    L"ferestre și pot fi minimizate. Tab și Shift+Tab mută focalizarea, Enter activează butonul focalizat, "
    L"iar Esc închide fereastra auxiliară activă.\r\n\r\nCERINȚE DE SISTEM\r\nWindows 7–11 acceptă toate "
    L"funcțiile. Pentru Windows Vista SP2 trebuie instalate actualizările KB971512 și KB2117917; "
    L"înregistrarea MP4 nu funcționează pe Vista. Este necesar Direct3D 11, iar pentru MP4 și Media "
    L"Foundation și un codificator H.264. Interfața și documentația sunt disponibile în 36 de limbi.",
    L"ΚΙΝΗΣΗ ΚΑΙ ΡΥΘΜΙΣΕΙΣ\r\nΠτήση πάνω από κυματοειδή επιφάνεια με επιτάχυνση υλικού. Απέραντη "
    L"κυματοειδής επιφάνεια; Μακρινή πτήση — μεταβαλλόμενη επιφάνεια. Επιλέξτε ακριβώς μία κίνηση ανά "
    L"οθόνη. Η Υφή εναλλάσσει επιφάνεια με υφή και συρμάτινο μοντέλο. Η ελεύθερη περιστροφή κάμερας αλλάζει "
    L"αργά την κατεύθυνση θέασης και στις τρεις διαστάσεις. Οι Παύσεις και αντιστροφές προσθέτουν τυχαίες "
    L"επιβραδύνσεις, παύσεις και αντιστροφές περιστροφής, ενώ η πτήση προς τα εμπρός συνεχίζεται. Η "
    L"ταχύτητα είναι 0–1600%. Κάθε οθόνη διαθέτει ανεξάρτητη τυχαία σκηνή που αποδίδεται στον δικό της "
    L"ρυθμό ανανέωσης. Ο κύριος φωτισμός, ο φωτισμός πλήρωσης, ο περιβάλλων φωτισμός και ο φωτισμός "
    L"περιγράμματος ρυθμίζονται ανεξάρτητα για τις επιλεγμένες οθόνες. Ο φωτισμός εφαρμόζεται μόνο σε "
    L"επιφάνειες με υφή. Και οι δύο κινήσεις προσφέρουν Επίπεδο, Κυματισμό ή Χοάνη. Η χοάνη τραβά την "
    L"κάμερα προς το εσωτερικό ακολουθώντας καθοδική σπείρα.\r\n\r\nΟΘΟΝΕΣ\r\nΕπιλέξτε μία ή περισσότερες "
    L"γραμμές στη "
    L"λίστα οθονών. Το Ctrl+A επιλέγει όλες, ενώ τα Ctrl και Shift αλλάζουν την επιλογή. Τα χειριστήρια και "
    L"τα ρυθμιστικά της κίνησης αλλάζουν μόνο τις ρυθμίσεις των επιλεγμένων οθονών. Η επιλογή γραμμής "
    L"διαφέρει από την ενεργοποίηση εξόδου μέσω του πλαισίου ελέγχου της. Η επιλογή αποθηκεύεται χωριστά "
    L"για την εφαρμογή και την προφύλαξη. Αν είχαν επιλεγεί όλες οι οθόνες, περιλαμβάνονται και όσες "
    L"συνδεθούν αργότερα. Οι διαφορετικές τιμές στις επιλεγμένες οθόνες υποδεικνύονται με απροσδιόριστη "
    L"κατάσταση των πλαισίων ελέγχου και μοτίβο κουκκίδων στα κουμπιά επιλογής, στις λαβές των ρυθμιστικών "
    L"και στα κουμπιά ενεργοποίησης ή απενεργοποίησης όλων των επιλογών. Οι ετικέτες των ρυθμιστικών "
    L"δείχνουν παύλα αντί για κοινή τιμή. Η αλλαγή επιλογής ή το κλικ σε ρυθμιστικό εφαρμόζει την τιμή σε "
    L"όλες τις επιλεγμένες οθόνες.\r\n\r\nΧΕΙΡΙΣΜΟΣ\r\nΕκτελέστε το SpaceFlight.exe. Οι ρυθμίσεις "
    L"αποθηκεύονται συνεχώς και εκτελείται μόνο ένα αντίγραφο της εφαρμογής. Το πλαίσιο της οθόνης ή το "
    L"διπλό κλικ στη γραμμή ενεργοποιεί ή απενεργοποιεί την έξοδο κίνησης. Η κίνηση μπορεί να παύσει και να "
    L"συνεχιστεί. Τα PNG και MP4 καταγράφουν την πρώτη ενεργή οθόνη κίνησης, όχι συνδυασμένη εικόνα όλων "
    L"των οθονών. Η καταγραφόμενη οθόνη δεν μπορεί να απενεργοποιηθεί· το κλείσιμο της εφαρμογής κατά την "
    L"εγγραφή απαιτεί επιβεβαίωση. Η παύση και η αναστολή προφύλαξης οθόνης ισχύουν για όλη την εφαρμογή, "
    L"ανεξάρτητα από την επιλογή οθονών. Όταν η αναστολή είναι ενεργή, η προφύλαξη των Windows εμποδίζεται "
    L"μόνο όσο υπάρχει ορατή κίνηση χωρίς παύση σε τουλάχιστον μία οθόνη. Η εφαρμογή εγκαθιστά ή καταργεί "
    L"την ενσωματωμένη προφύλαξη.\r\n\r\nΣΤΙΓΜΙΟΤΥΠΑ ΚΑΙ ΕΓΓΡΑΦΗ\r\nΣτις ρυθμίσεις εγγραφής επιλέξτε "
    L"Viewport ή TV. Το Viewport διατηρεί διαστάσεις και ρυθμό ανανέωσης οθόνης έως 60 καρέ ανά "
    L"δευτερόλεπτο. Το TV προσφέρει 1920 × 1080, 1440 × 1080 ή 1280 × 720 σε 16:9, με 50, 25, 59.94 "
    L"(60000/1001) ή 29.97 (30000/1001) καρέ ανά δευτερόλεπτο. Το βίντεο TV είναι προοδευτικό BT.709 "
    L"περιορισμένου εύρους με υποδειγματοληψία χρώματος 4:2:0. Διατηρούνται οι αναλογίες εικόνας και οι "
    L"συμπληρωματικές λωρίδες είναι μαύρες. Το OK αποθηκεύει επιλογές για την επόμενη εγγραφή· Άκυρο ή Esc "
    L"απορρίπτει ανεπιβεβαίωτες αλλαγές. Οι ρυθμίσεις εγγραφής, η βοήθεια και οι πληροφορίες δεν εμποδίζουν "
    L"άλλα παράθυρα και ελαχιστοποιούνται. Tab και Shift+Tab μετακινούν την εστίαση, Enter ενεργοποιεί το "
    L"εστιασμένο κουμπί και Esc κλείνει το ενεργό βοηθητικό παράθυρο.\r\n\r\nΑΠΑΙΤΗΣΕΙΣ ΣΥΣΤΗΜΑΤΟΣ\r\nΤα "
    L"Windows 7–11 υποστηρίζουν όλες τις λειτουργίες. Στα Windows Vista SP2 πρέπει να εγκατασταθούν οι "
    L"ενημερώσεις KB971512 και KB2117917· η εγγραφή MP4 δεν λειτουργεί στα Vista. Απαιτείται υποστήριξη "
    L"Direct3D 11 και, για MP4, Media Foundation και κωδικοποιητής H.264. Η διεπαφή και η τεκμηρίωση "
    L"διατίθενται σε 36 γλώσσες.",
    L"ANIMACIJA I POSTAVKE\r\nHardverski ubrzan let iznad valovite površine. Beskonačna valovita površina; "
    L"Daleki let — promjenjiva površina. Za svaki monitor odaberite tačno jednu animaciju. Tekstura mijenja "
    L"prikaz između teksturirane površine i žičanog modela. Slobodno okretanje kamere polako mijenja smjer "
    L"pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, pauze i promjene smjera "
    L"rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki monitor ima nezavisnu nasumičnu scenu "
    L"koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, "
    L"ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. "
    L"Osvjetljenje se primjenjuje samo na teksturirane površine. Obje animacije nude ravan, valove ili "
    L"lijevak. Lijevak uvlači kameru prema unutra duž silazne spirale.\r\n\r\nMONITORI\r\nOdaberite jedan "
    L"ili više "
    L"redova u listi monitora. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači "
    L"animacije mijenjaju samo postavke odabranih monitora. Odabir reda nije isto što i uključivanje izlaza "
    L"njegovom kućicom. Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
    L"odabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na odabranim "
    L"monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, ručkama "
    L"klizača i dugmadima za uključivanje ili isključivanje svih opcija. Oznake klizača prikazuju crticu "
    L"umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost na sve "
    L"odabrane monitore.\r\n\r\nUPRAVLJANJE\r\nPokrenite SpaceFlight.exe. Postavke se stalno čuvaju i radi "
    L"samo jedna instanca aplikacije. Kućica monitora ili dvostruki klik na red uključuje ili isključuje "
    L"animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe prvi aktivni monitor "
    L"animacije, ne zajedničku sliku svih monitora. Snimani monitor ne možete isključiti; zatvaranje "
    L"aplikacije tokom snimanja zahtijeva potvrdu. Pauza i blokada čuvara ekrana vrijede za cijelu "
    L"aplikaciju, bez obzira na odabir monitora. Kada je blokada uključena, čuvar ekrana Windowsa se "
    L"sprječava samo dok je na barem jednom monitoru vidljiva animacija koja nije pauzirana. Aplikacija "
    L"može instalirati i deinstalirati ugrađeni čuvar ekrana.\r\n\r\nSNIMCI EKRANA I SNIMANJE\r\nU "
    L"postavkama snimanja odaberite Viewport ili TV. Viewport zadržava dimenzije i frekvenciju monitora do "
    L"60 kadrova u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u omjeru 16:9, s 50, 25, 59.94 "
    L"(60000/1001) ili 29.97 (30000/1001) kadrova u sekundi. TV video je progresivni BT.709 ograničenog "
    L"raspona s poduzorkovanjem boje 4:2:0. Omjer slike ostaje sačuvan, a dopunske trake su crne. OK čuva "
    L"opcije za sljedeći snimak; Otkaži ili Esc odbacuje nepotvrđene izmjene. Prozori snimanja, pomoći i "
    L"informacija ne blokiraju ostale prozore i mogu se minimizirati. Tab i Shift+Tab pomjeraju fokus, "
    L"Enter aktivira fokusirano dugme, a Esc zatvara aktivni pomoćni prozor.\r\n\r\nSISTEMSKI "
    L"ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja "
    L"KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media "
    L"Foundation te H.264 koder. Interfejs i dokumentacija dostupni su na 36 jezika.",
    L"ANIMACIJA I POSTAVKE\r\nHardverski ubrzan let iznad valovite plohe. Beskonačna valovita ploha; Daleki "
    L"let — promjenjiva ploha. Za svaki zaslon odaberite točno jednu animaciju. Tekstura mijenja prikaz "
    L"između teksturirane plohe i žičanog modela. Slobodno okretanje kamere polako mijenja smjer pogleda u "
    L"sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, stanke i promjene smjera rotacije; "
    L"let naprijed se nastavlja. Brzina je 0–1600%. Svaki zaslon ima neovisnu nasumičnu scenu koja se "
    L"prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno "
    L"svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se "
    L"primjenjuje samo na teksturirane površine. Obje animacije nude ravninu, valove ili lijevak. Lijevak "
    L"uvlači kameru prema unutra duž silazne spirale.\r\n\r\nMONITORI\r\nOdaberite jedan ili više redaka na "
    L"popisu "
    L"zaslona. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije mijenjaju "
    L"samo postavke odabranih zaslona. Odabir retka nije isto što i uključivanje izlaza njegovim potvrdnim "
    L"okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar zaslona. Ako su prethodno bili odabrani svi "
    L"zasloni, uključuju se i novopriključeni zasloni. Različite vrijednosti na odabranim zaslonima "
    L"prikazuju se neodređenim stanjem potvrdnih okvira i točkastim uzorkom na izbornim gumbima, ručkama "
    L"klizača i gumbima za uključivanje ili isključivanje svih mogućnosti. Oznake klizača prikazuju crticu "
    L"umjesto zajedničke vrijednosti. Promjena mogućnosti ili klik na klizač primjenjuje tu vrijednost na "
    L"sve odabrane zaslone.\r\n\r\nUPRAVLJANJE\r\nPokrenite SpaceFlight.exe. Postavke se neprekidno "
    L"spremaju i radi samo jedna instanca aplikacije. Potvrdni okvir zaslona ili dvostruki klik na redak "
    L"uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe "
    L"prvi aktivni zaslon animacije, ne zajedničku sliku svih zaslona. Snimani zaslon ne možete isključiti; "
    L"zatvaranje aplikacije tijekom snimanja zahtijeva potvrdu. Pauza i blokada čuvara zaslona vrijede za "
    L"cijelu aplikaciju, bez obzira na odabir zaslona. Kada je blokada uključena, čuvar zaslona sustava "
    L"Windows sprječava se samo dok je na barem jednom zaslonu vidljiva animacija koja nije pauzirana. "
    L"Aplikacija može instalirati i deinstalirati ugrađeni čuvar zaslona.\r\n\r\nSNIMKE ZASLONA I "
    L"SNIMANJE\r\nU postavkama snimanja odaberite Viewport ili TV. Viewport zadržava dimenzije i "
    L"frekvenciju zaslona do 60 sličica u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u omjeru "
    L"16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) sličica u sekundi. TV video je progresivni "
    L"BT.709 ograničenog raspona s poduzorkovanjem boje 4:2:0. Omjer slike ostaje sačuvan, a dopunske trake "
    L"su crne. OK sprema mogućnosti za sljedeću snimku; Odustani ili Esc odbacuje nepotvrđene izmjene. "
    L"Prozori snimanja, pomoći i informacija ne blokiraju ostale prozore i mogu se minimizirati. Tab i "
    L"Shift+Tab pomiču fokus, Enter aktivira fokusirani gumb, a Esc zatvara aktivni pomoćni "
    L"prozor.\r\n\r\nZAHTJEVI SUSTAVA\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate "
    L"instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, "
    L"a za MP4 i Media Foundation te H.264 koder. Sučelje i dokumentacija dostupni su na 36 jezika.",
    L"ANIMACIJA IN NASTAVITVE\r\nStrojno pospešen let nad valovito ploskvijo. Neskončna valovita ploskev; "
    L"Oddaljeni let — spreminjajoča se ploskev. Za vsak zaslon izberite natanko eno animacijo. Tekstura "
    L"preklaplja med teksturirano ploskvijo in žičnim modelom. Prosto vrtenje kamere počasi spreminja smer "
    L"pogleda v vseh treh razsežnostih. Premori in obrati dodajo naključne upočasnitve, premore in obrate "
    L"smeri vrtenja; let naprej se nadaljuje. Hitrost je 0–1600%. Vsak zaslon ima neodvisen naključen "
    L"prizor, ki se izrisuje z njegovo hitrostjo osveževanja. Glavno svetlobo, dopolnilno svetlobo, "
    L"okoljsko svetlobo in obrobno svetlobo je mogoče neodvisno vklapljati za izbrane zaslone. Osvetlitev "
    L"velja samo za teksturirane površine. Pri obeh animacijah lahko izberete ravnino, valovanje ali lijak. "
    L"Lijak vleče kamero navznoter po padajoči spirali.\r\n\r\nZASLONI\r\nNa seznamu zaslonov izberite eno "
    L"ali več vrstic. Ctrl+A "
    L"izbere vse, Ctrl in Shift pa spreminjata izbor. Kontrolniki in drsniki animacije spreminjajo samo "
    L"nastavitve izbranih zaslonov. Izbira vrstice ni isto kot vklop izhoda z njenim potrditvenim poljem. "
    L"Izbor se ločeno shrani za program in ohranjevalnik. Če so bili izbrani vsi zasloni, so vključeni tudi "
    L"na novo priključeni zasloni. Različne vrednosti na izbranih zaslonih označujeta nedoločeno stanje "
    L"potrditvenih polj in pikčast vzorec na izbirnih gumbih, ročicah drsnikov ter gumbih za vklop ali "
    L"izklop vseh možnosti. Oznake drsnikov namesto skupne vrednosti prikazujejo pomišljaj. Sprememba "
    L"možnosti ali klik na drsnik uveljavi to vrednost na vseh izbranih "
    L"zaslonih.\r\n\r\nUPRAVLJANJE\r\nZaženite SpaceFlight.exe. Nastavitve se shranjujejo sproti in deluje "
    L"le en primerek programa. Polje zaslona ali dvojni klik na vrstico vklopi ali izklopi izhod animacije. "
    L"Animacijo lahko začasno ustavite in nadaljujete. PNG in MP4 zajameta prvi aktivni zaslon animacije, "
    L"ne skupne slike vseh zaslonov. Snemanega zaslona ni mogoče izklopiti; zapiranje programa med "
    L"snemanjem zahteva potrditev. Premor in preprečevanje ohranjevalnika veljata za celoten program, ne "
    L"glede na izbor zaslonov. Ko je preprečevanje vključeno, se ohranjevalnik Windows prepreči le, dokler "
    L"je na vsaj enem zaslonu vidna animacija, ki ni ustavljena. Program lahko namesti ali odstrani "
    L"vgrajeni ohranjevalnik.\r\n\r\nPOSNETKI ZASLONA IN SNEMANJE\r\nV nastavitvah snemanja izberite "
    L"Viewport ali TV. Viewport ohrani velikost in hitrost osveževanja zaslona do 60 sličic na sekundo. TV "
    L"ponuja 1920 × 1080, 1440 × 1080 ali 1280 × 720 v razmerju 16:9 ter 50, 25, 59.94 (60000/1001) ali "
    L"29.97 (30000/1001) sličic na sekundo. TV uporablja progresivni BT.709 z omejenim obsegom in barvnim "
    L"podvzorčenjem 4:2:0. Razmerje slike se ohrani, dopolnilni pasovi so črni. OK shrani izbiro za "
    L"naslednje snemanje; Prekliči ali Esc zavrže nepotrjene spremembe. Okna snemanja, pomoči in podatkov o "
    L"programu ne blokirajo drugih oken in jih je mogoče minimirati. Tab in Shift+Tab premikata fokus, "
    L"Enter aktivira izbrani gumb, Esc pa zapre aktivno pomožno okno.\r\n\r\nSISTEMSKE ZAHTEVE\r\nWindows "
    L"7–11 podpira vse funkcije. Za Windows Vista SP2 morate namestiti posodobitvi KB971512 in KB2117917; "
    L"snemanje MP4 v Visti ne deluje. Potrebna je podpora Direct3D 11, za MP4 pa še Media Foundation in "
    L"kodirnik H.264. Vmesnik in dokumentacija sta na voljo v 36 jezikih.",
    L"ANIMACIJA I PODEŠAVANJA\r\nHardverski ubrzan let iznad talasaste površine. Beskonačna talasasta "
    L"površina; Daleki let — promjenljiva površina. Za svaki monitor izaberite tačno jednu animaciju. "
    L"Tekstura mijenja prikaz između teksturisane površine i žičanog modela. Slobodno okretanje kamere "
    L"polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, pauze "
    L"i promjene smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki monitor ima nezavisnu "
    L"nasumičnu scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko "
    L"svjetlo, ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. "
    L"Osvjetljenje se primjenjuje samo na teksturirane površine. Obje animacije nude ravan, talase ili "
    L"lijevak. Lijevak uvlači kameru prema unutra duž silazne spirale.\r\n\r\nMONITORI\r\nIzaberite jedan "
    L"ili više "
    L"redova u listi monitora. Ctrl+A bira sve; Ctrl i Shift mijenjaju izbor. Kontrole i klizači animacije "
    L"mijenjaju samo podešavanja izabranih monitora. Izbor reda nije isto što i uključivanje izlaza "
    L"njegovom kućicom. Izbor se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
    L"izabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na izabranim "
    L"monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, ručkama "
    L"klizača i dugmadima za uključivanje ili isključivanje svih opcija. Oznake klizača prikazuju crticu "
    L"umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost na sve "
    L"izabrane monitore.\r\n\r\nUPRAVLJANJE\r\nPokrenite SpaceFlight.exe. Podešavanja se stalno čuvaju i "
    L"radi samo jedna instanca aplikacije. Kućica monitora ili dvostruki klik na red uključuje ili "
    L"isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe prvi aktivni "
    L"monitor animacije, ne zajedničku sliku svih monitora. Snimani monitor ne možete isključiti; "
    L"zatvaranje aplikacije tokom snimanja zahtijeva potvrdu. Pauza i blokada čuvara ekrana važe za cijelu "
    L"aplikaciju, bez obzira na izbor monitora. Kada je blokada uključena, čuvar ekrana Windowsa se "
    L"sprječava samo dok je na barem jednom monitoru vidljiva animacija koja nije pauzirana. Aplikacija "
    L"može instalirati i deinstalirati ugrađeni čuvar ekrana.\r\n\r\nSNIMCI EKRANA I SNIMANJE\r\nU "
    L"podešavanjima snimanja izaberite Viewport ili TV. Viewport zadržava dimenzije i frekvenciju monitora "
    L"do 60 kadrova u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u odnosu 16:9, s 50, 25, "
    L"59.94 (60000/1001) ili 29.97 (30000/1001) kadrova u sekundi. TV video je progresivni BT.709 "
    L"ograničenog opsega s poduzorkovanjem boje 4:2:0. Odnos slike ostaje sačuvan, a dopunske trake su "
    L"crne. OK čuva opcije za sljedeći snimak; Otkaži ili Esc odbacuje nepotvrđene izmjene. Prozori "
    L"snimanja, pomoći i informacija ne blokiraju ostale prozore i mogu se minimizovati. Tab i Shift+Tab "
    L"pomjeraju fokus, Enter aktivira fokusirano dugme, a Esc zatvara aktivni pomoćni "
    L"prozor.\r\n\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate "
    L"instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, "
    L"a za MP4 i Media Foundation i H.264 koder. Interfejs i dokumentacija dostupni su na 36 jezika.",
    L"АНІМАЦЫЯ І НАЛАДЫ\r\nАпаратна паскораны палёт над хвалістай паверхняй. Бясконцая хвалістая паверхня; "
    L"Далёкі палёт — зменлівая паверхня. Для кожнага манітора выберыце роўна адну анімацыю. Тэкстура "
    L"пераключае тэкстураваную паверхню і каркасную мадэль. Свабоднае кручэнне камеры павольна змяняе "
    L"напрамак погляду ва ўсіх трох вымярэннях. Паўзы і развароты дадаюць выпадковыя запаволенні, паўзы і "
    L"змены напрамку кручэння; палёт наперад працягваецца. Хуткасць — 0–1600%. Кожны манітор мае незалежную "
    L"выпадковую сцэну з вывадам паводле ўласнай частаты абнаўлення. Асноўнае, запаўняльнае, фонавае і "
    L"контурнае святло можна пераключаць незалежна для выбраных манітораў. Асвятленне дзейнічае толькі на "
    L"тэкстураваных паверхнях. У абедзвюх анімацыях можна выбраць плоскасць, хвалі або варонку. Варонка "
    L"зацягвае камеру ўнутр па сыходнай спіралі.\r\n\r\nМАНІТОРЫ\r\nВыберыце адзін або некалькі радкоў у "
    L"спісе манітораў. "
    L"Ctrl+A выбірае ўсе; Ctrl і Shift змяняюць выбар. Элементы кіравання і паўзункі анімацыі змяняюць "
    L"толькі налады выбраных манітораў. Выбар радка і ўключэнне вываду яго сцяжком — розныя дзеянні. Выбар "
    L"асобна захоўваецца для праграмы і застаўкі. Калі раней былі выбраны ўсе маніторы, да выбару "
    L"далучаюцца і новыя маніторы. Розныя значэнні на выбраных маніторах пазначаюцца нявызначаным станам "
    L"сцяжкоў і кропкавым узорам на пераключальніках, ручках паўзункоў і кнопках уключэння або выключэння "
    L"ўсіх параметраў. У подпісах паўзункоў замест агульнага значэння паказваецца працяжнік. Змена "
    L"параметра або націск на паўзунок ужывае гэта значэнне да ўсіх выбраных "
    L"манітораў.\r\n\r\nКІРАВАННЕ\r\nЗапусціце SpaceFlight.exe. Налады захоўваюцца пастаянна, працуе толькі "
    L"адзін асобнік праграмы. Сцяжок манітора або падвойнае націсканне на радок уключае ці выключае вывад "
    L"анімацыі. Анімацыю можна прыпыніць і працягнуць. PNG і MP4 захопліваюць першы актыўны манітор "
    L"анімацыі, а не агульны відарыс усіх манітораў. Манітор, які запісваецца, нельга выключыць; закрыццё "
    L"праграмы падчас запісу патрабуе пацвярджэння. Прыпыненне і блакаванне застаўкі дзейнічаюць на ўсю "
    L"праграму незалежна ад выбару манітораў. Калі блакаванне ўключана, застаўка Windows не запускаецца "
    L"толькі пакуль хаця б на адным маніторы бачная непрыпыненая анімацыя. Праграма можа ўсталяваць або "
    L"выдаліць убудаваную застаўку.\r\n\r\nЗДЫМКІ ЭКРАНА І ЗАПІС\r\nУ наладах запісу выберыце Viewport або "
    L"TV. Viewport захоўвае памеры і частату манітора да 60 кадраў за секунду. TV прапануе 1920 × 1080, "
    L"1440 × 1080 або 1280 × 720 з суадносінамі 16:9 і частатой 50, 25, 59.94 (60000/1001) або 29.97 "
    L"(30000/1001) кадраў за секунду. Відэа TV прагрэсіўнае, BT.709, з абмежаваным дыяпазонам і "
    L"субдыскрэтызацыяй колеру 4:2:0. Прапорцыі захоўваюцца, палосы запаўнення чорныя. OK захоўвае выбар "
    L"для наступнага запісу; Скасаваць або Esc адхіляе непацверджаныя змены. Вокны запісу, даведкі і "
    L"звестак пра праграму не блакуюць іншыя вокны і могуць згортвацца. Tab і Shift+Tab перамяшчаюць фокус, "
    L"Enter націскае актыўную кнопку, Esc закрывае актыўнае дапаможнае акно.\r\n\r\nСІСТЭМНЫЯ "
    L"ПАТРАБАВАННІ\r\nWindows 7–11 падтрымлівае ўсе функцыі. Для Windows Vista SP2 неабходна ўсталяваць "
    L"абнаўленні KB971512 і KB2117917; запіс MP4 у Vistа не працуе. Патрэбна падтрымка Direct3D 11, а для "
    L"MP4 таксама Media Foundation і кадавальнік H.264. Інтэрфейс і дакументацыя даступны на 36 мовах.",
    L"АНИМАЦИЯ И НАСТРОЙКИ\r\nХардуерно ускорен полет над вълнообразна повърхнина. Безкрайна вълнообразна "
    L"повърхнина; Далечен полет — променяща се повърхнина. Изберете точно една анимация за всеки монитор. "
    L"Текстура превключва между текстурирана повърхнина и телен модел. Свободното въртене на камерата бавно "
    L"променя посоката на погледа в трите измерения. Опцията „Паузи и обръщания“ добавя случайни забавяния, "
    L"паузи и обръщания на въртенето; полетът напред продължава. Скоростта е 0–1600%. Всеки монитор има "
    L"независима случайна сцена, изобразявана с неговата честота на опресняване. Основната, запълващата, "
    L"околната и контурната светлина се включват независимо за избраните монитори. Осветлението се прилага "
    L"само към текстурираните повърхности. И двете анимации предлагат равнина, вълни или фуния. Фунията "
    L"привлича камерата навътре по низходяща спирала.\r\n\r\nМОНИТОРИ\r\nИзберете един или повече редове в "
    L"списъка "
    L"с монитори. Ctrl+A избира всички; Ctrl и Shift променят избора. Контролите и плъзгачите на анимацията "
    L"променят само настройките на избраните монитори. Избирането на ред и включването на изхода чрез "
    L"отметката му са различни действия. Изборът се запомня отделно за приложението и скрийнсейвъра. Ако са "
    L"били избрани всички монитори, включват се и новосвързаните. Различните стойности на избраните "
    L"монитори се показват с неопределено състояние на отметките и точков шаблон върху радиобутоните, "
    L"дръжките на плъзгачите и бутоните за включване или изключване на всички опции. Надписите на "
    L"плъзгачите показват тире вместо обща стойност. Промяна на опция или щракване върху плъзгач прилага "
    L"стойността към всички избрани монитори.\r\n\r\nУПРАВЛЕНИЕ\r\nСтартирайте SpaceFlight.exe. Настройките "
    L"се запазват непрекъснато и работи само един екземпляр на приложението. Отметката на монитора или "
    L"двойно щракване върху реда включва или изключва анимационния изход. Анимацията може да се поставя на "
    L"пауза и да продължава. PNG и MP4 заснемат първия активен монитор за анимация, не общ образ от всички "
    L"монитори. Записваният монитор не може да се изключи; затварянето на приложението при запис изисква "
    L"потвърждение. Паузата и блокирането на скрийнсейвъра важат за цялото приложение независимо от избора "
    L"на монитори. Когато блокирането е включено, скрийнсейвърът на Windows се предотвратява само докато на "
    L"поне един монитор има видима анимация без пауза. Приложението може да инсталира и деинсталира "
    L"вградения скрийнсейвър.\r\n\r\nЕКРАННИ СНИМКИ И ЗАПИС\r\nВ настройките за запис изберете Viewport или "
    L"TV. Viewport запазва размерите и честотата на монитора до 60 кадъра в секунда. TV предлага 1920 × "
    L"1080, 1440 × 1080 или 1280 × 720 със съотношение 16:9 и 50, 25, 59.94 (60000/1001) или 29.97 "
    L"(30000/1001) кадъра в секунда. TV използва прогресивно видео BT.709 с ограничен диапазон и цветова "
    L"субдискретизация 4:2:0. Пропорциите се запазват, допълващите ленти са черни. OK запазва избора за "
    L"следващия запис; Отказ или Esc отхвърля непотвърдените промени. Прозорците за запис, помощ и "
    L"информация не блокират другите прозорци и могат да се минимизират. Tab и Shift+Tab преместват фокуса, "
    L"Enter активира фокусирания бутон, Esc затваря активния помощен прозорец.\r\n\r\nСИСТЕМНИ "
    L"ИЗИСКВАНИЯ\r\nWindows 7–11 поддържа всички функции. За Windows Vista SP2 трябва да се инсталират "
    L"актуализациите KB971512 и KB2117917; записът на MP4 не работи във Vista. Изисква се поддръжка на "
    L"Direct3D 11, а за MP4 също Media Foundation и H.264 кодер. Интерфейсът и документацията са налични на "
    L"36 езика.",
    L"АНИМАЦИЈА И ПОСТАВКИ\r\nХардверски забрзан лет над брановидна површина. Бесконечна брановидна "
    L"површина; Далечен лет — променлива површина. За секој монитор изберете точно една анимација. Текстура "
    L"менува текстурирана површина и жичен модел. Слободното вртење на камерата полека го менува погледот "
    L"во сите три димензии. Опцијата „Паузи и пресврти“ додава случајни забавувања, паузи и промени на "
    L"насоката на вртење; летот напред продолжува. Брзината е 0–1600%. Секој монитор има независна случајна "
    L"сцена што се прикажува со неговата стапка на освежување. Главното, дополнителното, амбиенталното и "
    L"контурното светло може да се вклучуваат одделно за избраните монитори. Осветлувањето важи само за "
    L"текстурираните површини. Двете анимации нудат рамнина, бранови или инка. Инката ја влече камерата "
    L"навнатре по надолна спирала.\r\n\r\nМОНИТОРИ\r\nИзберете еден или повеќе редови во списокот на "
    L"монитори. "
    L"Ctrl+A ги избира сите; Ctrl и Shift го менуваат изборот. Контролите и лизгачите на анимацијата ги "
    L"менуваат само поставките на избраните монитори. Избирањето ред и вклучувањето на излезот преку "
    L"неговото поле се различни дејства. Изборот се памети одделно за апликацијата и чуварот. Ако биле "
    L"избрани сите монитори, се вклучуваат и новоповрзаните монитори. Различните вредности на избраните "
    L"монитори се прикажуваат со неопределена состојба на полињата за избор и точкест образец на "
    L"радио-копчињата, рачките на лизгачите и копчињата за вклучување или исклучување на сите опции. "
    L"Ознаките на лизгачите прикажуваат црта наместо заедничка вредност. Менувањето опција или кликнувањето "
    L"на лизгач ја применува вредноста на сите избрани монитори.\r\n\r\nУПРАВУВАЊЕ\r\nСтартувајте "
    L"SpaceFlight.exe. Поставките се зачувуваат постојано и работи само еден примерок на апликацијата. "
    L"Полето на мониторот или двоен клик на редот го вклучува или исклучува анимацискиот излез. Анимацијата "
    L"може да се паузира и продолжи. PNG и MP4 го снимаат првиот активен монитор за анимација, не заедничка "
    L"слика од сите монитори. Мониторот што се снима не може да се исклучи; затворањето на апликацијата при "
    L"снимање бара потврда. Паузата и блокирањето на чуварот важат за целата апликација без оглед на "
    L"изборот на монитори. Кога блокирањето е вклучено, чуварот на Windows се спречува само додека на барем "
    L"еден монитор е видлива непаузирана анимација. Апликацијата може да го инсталира и деинсталира "
    L"вградениот чувар.\r\n\r\nСНИМКИ ОД ЕКРАН И СНИМАЊЕ\r\nВо поставките за снимање изберете Viewport или "
    L"TV. Viewport ги зачувува димензиите и стапката на мониторот до 60 кадри во секунда. TV нуди 1920 × "
    L"1080, 1440 × 1080 или 1280 × 720 со однос 16:9 и 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) "
    L"кадри во секунда. TV видеото е прогресивно BT.709 со ограничен опсег и подсемплирање на боја 4:2:0. "
    L"Пропорциите се задржуваат, дополнителните ленти се црни. OK ги зачувува опциите за следното снимање; "
    L"Откажи или Esc ги отфрла непотврдените измени. Прозорците за снимање, помош и информации не ги "
    L"блокираат другите прозорци и може да се минимизираат. Tab и Shift+Tab го поместуваат фокусот, Enter "
    L"го активира фокусираното копче, Esc го затвора активниот помошен прозорец.\r\n\r\nСИСТЕМСКИ "
    L"БАРАЊА\r\nWindows 7–11 ги поддржува сите функции. За Windows Vista SP2 мора да се инсталираат "
    L"ажурирањата KB971512 и KB2117917; MP4 снимањето на Vista не работи. Потребна е поддршка за Direct3D "
    L"11, а за MP4 и Media Foundation и H.264 кодер. Интерфејсот и документацијата се достапни на 36 јазици.",
    L"АНИМАЦИЈА И ПОДЕШАВАЊА\r\nХардверски убрзан лет изнад таласасте површи. Бесконачна таласаста површ; "
    L"Далеки лет — променљива површ. За сваки монитор изаберите тачно једну анимацију. Текстура мења приказ "
    L"између текстурисане површи и жичаног модела. Слободно окретање камере полако мења смер погледа у све "
    L"три димензије. Паузе и обрти додају насумично успоравање, паузе и промене смера ротације; лет напред "
    L"се наставља. Брзина је 0–1600%. Сваки монитор има независну насумичну сцену која се приказује према "
    L"његовој учестаности освежавања. Главно, допунско, амбијентално и контурно светло могу се засебно "
    L"укључивати за изабране мониторе. Осветљење важи само за текстуриране површине. Обе анимације нуде "
    L"раван, таласе или левак. Левак увлачи камеру ка унутрашњости дуж силазне "
    L"спирале.\r\n\r\nМОНИТОРИ\r\nИзаберите "
    L"један или више редова у листи монитора. Ctrl+A бира све; Ctrl и Shift мењају избор. Контроле и "
    L"клизачи анимације мењају само подешавања изабраних монитора. Избор реда није исто што и укључивање "
    L"излаза његовим пољем за потврду. Избор се памти одвојено за апликацију и чувар екрана. Ако су "
    L"претходно били изабрани сви монитори, укључују се и новоприкључени монитори. Различите вредности на "
    L"изабраним мониторима приказују се неодређеним стањем поља за потврду и тачкастим узорком на дугмадима "
    L"избора, ручкама клизача и дугмадима за укључивање или искључивање свих опција. Ознаке клизача "
    L"приказују црту уместо заједничке вредности. Промена опције или клик на клизач примењује ту вредност "
    L"на све изабране мониторе.\r\n\r\nУПРАВЉАЊЕ\r\nПокрените SpaceFlight.exe. Подешавања се стално чувају "
    L"и ради само једна инстанца апликације. Поље монитора или двоструки клик на ред укључује или искључује "
    L"анимацијски излаз. Анимацију можете паузирати и наставити. PNG и MP4 бележе први активни монитор "
    L"анимације, не заједничку слику свих монитора. Снимани монитор не можете искључити; затварање "
    L"апликације током снимања захтева потврду. Пауза и блокада чувара екрана важе за целу апликацију, без "
    L"обзира на избор монитора. Када је блокада укључена, чувар екрана система Windows спречава се само док "
    L"је на бар једном монитору видљива анимација која није паузирана. Апликација може инсталирати и "
    L"деинсталирати уграђени чувар екрана.\r\n\r\nСНИМЦИ ЕКРАНА И СНИМАЊЕ\r\nУ подешавањима снимања "
    L"изаберите Viewport или TV. Viewport задржава димензије и учестаност монитора до 60 кадрова у секунди. "
    L"TV нуди 1920 × 1080, 1440 × 1080 или 1280 × 720 у односу 16:9, са 50, 25, 59.94 (60000/1001) или "
    L"29.97 (30000/1001) кадрова у секунди. TV видео је прогресивни BT.709 ограниченог опсега с "
    L"подузорковањем боје 4:2:0. Однос слике остаје сачуван, а допунске траке су црне. OK чува опције за "
    L"следећи снимак; Откажи или Esc одбацује непотврђене измене. Прозори снимања, помоћи и информација не "
    L"блокирају остале прозоре и могу се минимизовати. Tab и Shift+Tab померају фокус, Enter активира "
    L"фокусирано дугме, а Esc затвара активни помоћни прозор.\r\n\r\nСИСТЕМСКИ ЗАХТЕВИ\r\nWindows 7–11 "
    L"подржава све функције. За Windows Vista SP2 морате инсталирати ажурирања KB971512 и KB2117917; MP4 "
    L"снимање на Висти не ради. Потребан је Direct3D 11, а за MP4 и Media Foundation и H.264 кодер. "
    L"Интерфејс и документација доступни су на 36 језика.",
    L"АНІМАЦІЯ ТА НАЛАШТУВАННЯ\r\nАпаратно прискорений політ над хвилястою поверхнею. Нескінченна хвиляста "
    L"поверхня; Далекий політ — мінлива поверхня. Для кожного монітора виберіть рівно одну анімацію. "
    L"Текстура перемикає текстуровану поверхню та каркасну модель. Вільне обертання камери повільно змінює "
    L"напрямок погляду в усіх трьох вимірах. Паузи та зміни напрямку додають випадкові уповільнення, паузи "
    L"та зміни напрямку обертання; політ уперед триває. Швидкість — 0–1600%. Кожен монітор має незалежну "
    L"випадкову сцену з виведенням відповідно до власної частоти оновлення. Основне, заповнювальне, фонове "
    L"та контурне світло можна незалежно перемикати для вибраних моніторів. Освітлення діє лише на "
    L"текстурованих поверхнях. В обох анімаціях можна вибрати площину, хвилі або лійку. Лійка втягує камеру "
    L"всередину низхідною спіраллю.\r\n\r\nМОНІТОРИ\r\nВиберіть один або кілька рядків у списку моніторів. "
    L"Ctrl+A "
    L"вибирає всі; Ctrl і Shift змінюють вибір. Елементи керування й повзунки анімації змінюють лише "
    L"налаштування вибраних моніторів. Вибір рядка та ввімкнення виведення його прапорцем — різні дії. "
    L"Вибір зберігається окремо для програми й заставки. Якщо раніше були вибрані всі монітори, до вибору "
    L"долучаються й новопідключені. Різні значення на вибраних моніторах позначаються невизначеним станом "
    L"прапорців і крапковим візерунком на перемикачах, ручках повзунків і кнопках увімкнення або вимкнення "
    L"всіх параметрів. Підписи повзунків показують тире замість спільного значення. Зміна параметра або "
    L"натискання на повзунок застосовує це значення до всіх вибраних "
    L"моніторів.\r\n\r\nКЕРУВАННЯ\r\nЗапустіть SpaceFlight.exe. Налаштування зберігаються постійно, працює "
    L"лише один екземпляр програми. Прапорець монітора або подвійне клацання рядка вмикає чи вимикає "
    L"виведення анімації. Анімацію можна призупинити та продовжити. PNG і MP4 захоплюють перший активний "
    L"монітор анімації, а не спільне зображення всіх моніторів. Монітор, який записується, вимкнути не "
    L"можна; закриття програми під час запису потребує підтвердження. Призупинення та блокування заставки "
    L"діють для всієї програми незалежно від вибору моніторів. Якщо блокування ввімкнено, заставка Windows "
    L"не запускається лише доки принаймні на одному моніторі видима непризупинена анімація. Програма може "
    L"встановити або видалити вбудовану заставку.\r\n\r\nЗНІМКИ ЕКРАНА ТА ЗАПИС\r\nУ налаштуваннях запису "
    L"виберіть Viewport або TV. Viewport зберігає розміри та частоту монітора до 60 кадрів за секунду. TV "
    L"пропонує 1920 × 1080, 1440 × 1080 або 1280 × 720 зі співвідношенням 16:9 і частотою 50, 25, 59.94 "
    L"(60000/1001) або 29.97 (30000/1001) кадрів за секунду. Відео TV прогресивне, BT.709, з обмеженим "
    L"діапазоном і субдискретизацією кольору 4:2:0. Пропорції зберігаються, смуги заповнення чорні. OK "
    L"зберігає вибір для наступного запису; Скасувати або Esc відхиляє непідтверджені зміни. Вікна запису, "
    L"довідки та відомостей не блокують інші вікна й можуть згортатися. Tab і Shift+Tab переміщують фокус, "
    L"Enter активує кнопку з фокусом, Esc закриває активне допоміжне вікно.\r\n\r\nСИСТЕМНІ "
    L"ВИМОГИ\r\nWindows 7–11 підтримує всі функції. Для Windows Vista SP2 потрібно встановити оновлення "
    L"KB971512 і KB2117917; запис MP4 у Vista не працює. Потрібна підтримка Direct3D 11, а для MP4 також "
    L"Media Foundation й кодувальник H.264. Інтерфейс і документація доступні 36 мовами.",
    L"АНИМАЦИЯ И НАСТРОЙКИ\r\nАппаратно ускоренный полёт над волнообразной поверхностью. Бесконечная "
    L"волнообразная поверхность; Дальний полёт — меняющаяся поверхность. Для каждого монитора выберите "
    L"ровно одну анимацию. Текстура переключает текстурированную поверхность и каркасную модель. Свободное "
    L"вращение камеры медленно меняет направление взгляда во всех трёх измерениях. Паузы и смены "
    L"направления добавляют случайные замедления, паузы и изменения направления вращения; полёт вперёд "
    L"продолжается. Скорость — 0–1600%. Каждый монитор имеет независимую случайную сцену с выводом согласно "
    L"собственной частоте обновления. Основной, заполняющий, фоновый и контурный свет можно независимо "
    L"переключать для выбранных мониторов. Освещение применяется только к текстурированным поверхностям. "
    L"В обеих анимациях можно выбрать плоскость, волны или воронку. Воронка втягивает камеру внутрь по "
    L"нисходящей спирали.\r\n\r\nМОНИТОРЫ\r\nВыберите одну или несколько строк в списке мониторов. Ctrl+A "
    L"выбирает все; "
    L"Ctrl и Shift изменяют выбор. Элементы управления и ползунки анимации изменяют только настройки "
    L"выбранных мониторов. Выбор строки и включение вывода её флажком — разные действия. Выбор сохраняется "
    L"отдельно для приложения и заставки. Если раньше были выбраны все мониторы, в выбор включаются и вновь "
    L"подключённые. Разные значения на выбранных мониторах обозначаются неопределённым состоянием флажков и "
    L"точечным узором на переключателях, ручках ползунков и кнопках включения или выключения всех "
    L"параметров. Подписи ползунков показывают тире вместо общего значения. Изменение параметра или нажатие "
    L"на ползунок применяет это значение ко всем выбранным мониторам.\r\n\r\nУПРАВЛЕНИЕ\r\nЗапустите "
    L"SpaceFlight.exe. Настройки сохраняются постоянно, работает только один экземпляр приложения. Флажок "
    L"монитора или двойной щелчок по строке включает либо выключает вывод анимации. Анимацию можно "
    L"приостановить и продолжить. PNG и MP4 захватывают первый активный монитор анимации, а не общее "
    L"изображение всех мониторов. Записываемый монитор нельзя отключить; закрытие приложения во время "
    L"записи требует подтверждения. Пауза и блокировка заставки действуют для всего приложения независимо "
    L"от выбора мониторов. Если блокировка включена, заставка Windows не запускается только пока хотя бы на "
    L"одном мониторе видима неприостановленная анимация. Приложение может установить или удалить встроенную "
    L"заставку.\r\n\r\nСНИМКИ ЭКРАНА И ЗАПИСЬ\r\nВ настройках записи выберите Viewport или TV. Viewport "
    L"сохраняет размеры и частоту монитора до 60 кадров в секунду. TV предлагает 1920 × 1080, 1440 × 1080 "
    L"или 1280 × 720 с соотношением 16:9 и частотой 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) "
    L"кадров в секунду. Видео TV прогрессивное, BT.709, с ограниченным диапазоном и субдискретизацией цвета "
    L"4:2:0. Пропорции сохраняются, полосы заполнения чёрные. OK сохраняет выбор для следующей записи; "
    L"Отмена или Esc отклоняет неподтверждённые изменения. Окна записи, справки и сведений не блокируют "
    L"другие окна и могут сворачиваться. Tab и Shift+Tab перемещают фокус, Enter активирует кнопку с "
    L"фокусом, Esc закрывает активное вспомогательное окно.\r\n\r\nСИСТЕМНЫЕ ТРЕБОВАНИЯ\r\nWindows 7–11 "
    L"поддерживает все функции. Для Windows Vista SP2 необходимо установить обновления KB971512 и "
    L"KB2117917; запись MP4 в Vista не работает. Нужна поддержка Direct3D 11, а для MP4 также Media "
    L"Foundation и кодировщик H.264. Интерфейс и документация доступны на 36 языках."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> SCREEN_SAVER_HELP_TEXTS = {
    L"ANIMACE A NASTAVENÍ\r\nSpaceFlight: Nekonečná vlnící se plocha; Dálkový let — proměnlivá plocha. "
    L"Každému monitoru přiřaďte právě jednu animaci. Textura přepíná mezi texturovanými plochami a drátěným "
    L"modelem. Volná rotace kamery pomalu mění směr pohledu ve všech třech rozměrech. Volba „Pauzy a "
    L"obraty“ přidává náhodné zpomalování, pauzy a změny směru otáčení; dopředný pohyb pokračuje. Rychlost "
    L"animace je 0–1600 %. Každý monitor má nezávislou náhodnou scénu a vykreslování podle své obnovovací "
    L"frekvence. Hlavní světlo, doplňkové světlo, základní jas a přisvětlení obrysů lze pro označené "
    L"monitory zapínat nezávisle. Osvětlení se používá jen u texturovaných ploch. U obou animací lze zvolit "
    L"rovinu, zvlnění nebo trychtýř. Trychtýř vtahuje kameru dovnitř po sestupné "
    L"spirále.\r\n\r\nMONITORY\r\nOznačení řádků určuje, "
    L"které monitory právě nastavujete; není totožné se zatržítky zapínajícími animační výstupy. Ctrl+A "
    L"označí všechny monitory, Ctrl a Shift umožňují upravit označení. Všechny animační volby a jezdce "
    L"platí pro označené monitory. Označení se pamatuje zvlášť pro EXE a SCR. Pokud byly označené všechny "
    L"monitory, označí se i nově připojené. Různé hodnoty na označených monitorech ukazuje neurčitý stav "
    L"zatržítek a tečkování přepínačů, úchytů jezdců a tlačítek pro zapnutí či vypnutí všech voleb. Popisek "
    L"jezdce místo společné hodnoty zobrazuje pomlčku. Změna volby nebo kliknutí na jezdec sjednotí "
    L"příslušnou hodnotu na označených monitorech.\r\n\r\nNÁHLED A OVLÁDÁNÍ\r\nZapnout náhled spustí "
    L"celoobrazovkový náhled na všech monitorech; změny lze zkoušet za otevřeného nastavení. OK nastavení "
    L"uloží, Storno je zahodí. Celoobrazovkový spořič ukončíte klávesou Esc nebo pohybem myši. Mezi "
    L"ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a "
    L"příslušného písmene. Esc v nastavení odpovídá tlačítku Storno; v nápovědě nebo okně O aplikaci zavře "
    L"pouze toto okno.\r\n\r\nSYSTÉMOVÉ POŽADAVKY\r\nPodporovány jsou systémy Windows 7 až Windows 11. Pro "
    L"spuštění aplikace ve Windows Vista SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917. "
    L"Vykreslování vyžaduje Direct3D 11, nikoli jen starší DirectX runtime.",
    L"ANIMATION AND SETTINGS\r\nSpaceFlight: Infinite undulating surface; Long-distance flight — morphing "
    L"surface. Assign exactly one animation to each display. Texture switches between textured surfaces and "
    L"wireframe. Free camera rotation slowly changes the viewing direction in all three dimensions. The "
    L"Pauses and reversals option adds randomized braking, pauses, and reversals of the rotation; forward "
    L"flight continues. Animation speed ranges from 0–1600%. Every display has an independent randomized "
    L"scene rendered at its own refresh rate. Main light, fill light, ambient light, and rim light can be "
    L"switched independently for the selected displays. Lighting applies only to textured surfaces. Both "
    L"animations offer Plane, Waves, or Funnel. Funnel draws the camera inward along a descending "
    L"spiral.\r\n\r\nDISPLAYS\r\nRow "
    L"selection determines which displays you are editing; it is separate from the checkboxes that enable "
    L"animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation "
    L"options and sliders apply to the selected displays. The selection is remembered separately for EXE "
    L"and SCR. If all displays were selected, newly connected displays join the selection. Different values "
    L"across selected displays are indicated by indeterminate checkboxes and dotted radio buttons, slider "
    L"thumbs, and buttons for enabling or disabling all options. Slider labels show a dash instead of a "
    L"shared value. Changing an option or clicking a slider applies that value to all selected "
    L"displays.\r\n\r\nPREVIEW AND CONTROLS\r\nEnable preview starts a full-screen preview on every display "
    L"while the settings dialog remains open for live adjustments. OK saves the settings and Cancel "
    L"discards them. Exit the full-screen saver with Esc or mouse movement. Use Tab and Shift+Tab to move "
    L"between controls; use Alt and the underlined letter to activate a command. Esc in the settings dialog "
    L"is equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\nSYSTEM "
    L"REQUIREMENTS\r\nWindows 7 through Windows 11 are supported. To run the application on Windows Vista "
    L"SP2, you must install updates KB971512 and KB2117917. Rendering requires Direct3D 11, not just an "
    L"older DirectX runtime.",
    L"ANIMATION AND SETTINGS\r\nSpaceFlight: Infinite undulating surface; Long-distance flight — morphing "
    L"surface. Assign exactly one animation to each display. Texture switches between textured surfaces and "
    L"wireframe. Free camera rotation slowly changes the viewing direction in all three dimensions. The "
    L"Pauses and reversals option adds randomised braking, pauses and reversals of the rotation; forward "
    L"flight continues. Animation speed ranges from 0–1600%. Every display has an independent randomised "
    L"scene rendered at its own refresh rate. Main light, fill light, ambient light and rim light can be "
    L"switched independently for the selected displays. Lighting applies only to textured surfaces. Both "
    L"animations offer Plane, Waves, or Funnel. Funnel draws the camera inward along a descending "
    L"spiral.\r\n\r\nDISPLAYS\r\nRow "
    L"selection determines which displays you are editing; it is separate from the checkboxes that enable "
    L"animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation "
    L"options and sliders apply to the selected displays. The selection is remembered separately for EXE "
    L"and SCR. If all displays were selected, newly connected displays join the selection. Different values "
    L"across selected displays are indicated by indeterminate checkboxes and dotted radio buttons, slider "
    L"thumbs and buttons for enabling or disabling all options. Slider labels show a dash instead of a "
    L"shared value. Changing an option or clicking a slider applies that value to all selected "
    L"displays.\r\n\r\nPREVIEW AND CONTROLS\r\nEnable preview starts a full-screen preview on every display "
    L"and allows live adjustments while the settings dialog remains open. OK saves the settings and Cancel "
    L"discards them. Exit the full-screen screen saver with Esc or mouse movement. Use Tab and Shift+Tab to "
    L"move between controls; use Alt and the underlined letter to activate a command. Esc in the settings "
    L"dialog is equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\nSYSTEM "
    L"REQUIREMENTS\r\nWindows 7 through Windows 11 are supported. To run the application on Windows Vista "
    L"SP2, you must install updates KB971512 and KB2117917. Rendering requires Direct3D 11, not just an "
    L"older DirectX runtime.",
    L"ANIMATION AND SETTINGS\r\nSpaceFlight: Infinite undulating surface; Long-distance flight — morphing "
    L"surface. Assign exactly one animation to each display. Texture switches between textured surfaces and "
    L"wireframe. Free camera rotation slowly changes the viewing direction in all three dimensions. The "
    L"Pauses and reversals option adds randomised braking, pauses and reversals of the rotation; forward "
    L"flight continues. Animation speed ranges from 0–1600%. Every display has an independent randomised "
    L"scene rendered at its own refresh rate. Main light, fill light, ambient light and rim light can be "
    L"switched independently for the selected displays. Lighting applies only to textured surfaces. Both "
    L"animations offer Plane, Waves, or Funnel. Funnel draws the camera inward along a descending "
    L"spiral.\r\n\r\nDISPLAYS\r\nRow "
    L"selection determines which displays you are editing; it is separate from the checkboxes that enable "
    L"animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation "
    L"options and sliders apply to the selected displays. The selection is remembered separately for EXE "
    L"and SCR. If all displays were selected, newly connected displays join the selection. Different values "
    L"across selected displays are indicated by indeterminate checkboxes and dotted radio buttons, slider "
    L"thumbs and buttons for enabling or disabling all options. Slider labels show a dash instead of a "
    L"shared value. Changing an option or clicking a slider applies that value to all selected "
    L"displays.\r\n\r\nPREVIEW AND CONTROLS\r\nEnable preview starts a full-screen preview on every display "
    L"and allows live adjustments while the settings dialog remains open. OK saves the settings and Cancel "
    L"discards them. Exit the full-screen screen saver with Esc or mouse movement. Use Tab and Shift+Tab to "
    L"move between controls; use Alt and the underlined letter to activate a command. Esc in the settings "
    L"dialog is equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\nSYSTEM "
    L"REQUIREMENTS\r\nWindows 7 through Windows 11 are supported. To run the application on Windows Vista "
    L"SP2, you must install updates KB971512 and KB2117917. Rendering requires Direct3D 11, not just an "
    L"older DirectX runtime.",
    L"ANIMATION UND EINSTELLUNGEN\r\nSpaceFlight: Unendliche wellenförmige Fläche; Fernflug — veränderliche "
    L"Fläche. Weisen Sie jedem Monitor genau eine Animation zu. Textur wechselt zwischen texturierten "
    L"Flächen und Drahtgittermodell. Die freie Kameradrehung verändert die Blickrichtung langsam in allen "
    L"drei Dimensionen. Die Option „Pausen und Umkehr“ ergänzt zufälliges Abbremsen, Pausen und Wechsel der "
    L"Drehrichtung; der Vorwärtsflug läuft weiter. Die Animationsgeschwindigkeit beträgt 0–1600 %. Jeder "
    L"Monitor besitzt eine unabhängige zufällige Szene und wird mit seiner eigenen Bildwiederholrate "
    L"angesteuert. Hauptlicht, Fülllicht, Umgebungslicht und Konturlicht lassen sich für die ausgewählten "
    L"Monitore unabhängig schalten. Die Beleuchtung gilt nur für texturierte Flächen. Beide Animationen "
    L"bieten Ebene, Wellen oder Trichter. Im Trichter bewegt sich die Kamera auf einer absteigenden Spirale "
    L"nach innen.\r\n\r\nMONITORE\r\nDie Zeilenauswahl bestimmt, welche Monitore Sie bearbeiten; sie ist "
    L"von "
    L"den Kontrollkästchen zum Einschalten der Animationsausgabe getrennt. Strg+A wählt alle Monitore, Strg "
    L"und Umschalt ändern die Auswahl. Alle Animationsoptionen und Regler gelten für die ausgewählten "
    L"Monitore. Die Auswahl wird für EXE und SCR getrennt gespeichert. Waren alle Monitore ausgewählt, "
    L"werden auch neu angeschlossene ausgewählt. Unterschiedliche Werte der ausgewählten Monitore werden "
    L"durch unbestimmte Kontrollkästchen und gepunktete Optionsfelder, Reglergriffe sowie Schaltflächen zum "
    L"Ein- oder Ausschalten aller Optionen angezeigt. Reglerbeschriftungen zeigen statt eines gemeinsamen "
    L"Werts einen Gedankenstrich. Das Ändern einer Option oder Anklicken eines Reglers übernimmt diesen "
    L"Wert für alle ausgewählten Monitore.\r\n\r\nVORSCHAU UND BEDIENUNG\r\nVorschau einschalten startet "
    L"eine Vollbildvorschau auf allen Monitoren. Der Einstellungsdialog bleibt für Änderungen geöffnet. OK "
    L"speichert, Abbrechen verwirft. Esc oder eine Mausbewegung beendet den Vollbildschoner. Mit Tab und "
    L"Umschalt+Tab wechseln Sie zwischen den Steuerelementen; mit Alt und dem unterstrichenen Buchstaben "
    L"rufen Sie einen Befehl auf. Esc im Einstellungsdialog entspricht Abbrechen; in der Hilfe oder im "
    L"Infofenster schließt es nur dieses Fenster.\r\n\r\nSYSTEMANFORDERUNGEN\r\nUnterstützt werden Windows "
    L"7 bis Windows 11. Zum Ausführen der Anwendung unter Windows Vista SP2 müssen die Updates KB971512 und "
    L"KB2117917 installiert werden. Die Darstellung erfordert Direct3D 11, nicht nur eine ältere "
    L"DirectX-Laufzeitumgebung.",
    L"ANIMATION ET PARAMÈTRES\r\nSpaceFlight: Surface ondulante infinie; Vol longue distance — surface "
    L"déformable. Attribuez une seule animation à chaque écran. Texture alterne entre surfaces texturées et "
    L"modèle filaire. La rotation libre de la caméra change lentement la direction du regard dans les trois "
    L"dimensions. L’option « Pauses et inversions » ajoute des ralentissements, pauses et inversions "
    L"aléatoires de la rotation ; le vol vers l’avant continue. La vitesse va de 0 à 1600 %. Chaque écran "
    L"possède une scène aléatoire indépendante, rendue à sa propre fréquence de rafraîchissement. La "
    L"lumière principale, la lumière d’appoint, l’éclairage ambiant et l’éclairage des contours se règlent "
    L"indépendamment pour les écrans sélectionnés. L’éclairage ne concerne que les surfaces texturées. "
    L"Les deux animations proposent Plan, Ondulations ou Entonnoir. L’entonnoir attire la caméra vers "
    L"l’intérieur suivant une spirale descendante.\r\n\r\nÉCRANS\r\nLa sélection des lignes détermine les "
    L"écrans à configurer ; elle est "
    L"distincte des cases qui activent les sorties d’animation. Ctrl+A sélectionne tous les écrans ; Ctrl "
    L"et Maj modifient la sélection. Toutes les options et tous les curseurs d’animation concernent les "
    L"écrans sélectionnés. La sélection est mémorisée séparément pour EXE et SCR. Si tous les écrans "
    L"étaient sélectionnés, les nouveaux le sont également. Des valeurs différentes entre les écrans "
    L"sélectionnés sont indiquées par des cases à cocher indéterminées et des pointillés sur les boutons "
    L"radio, les poignées des curseurs et les boutons d’activation ou de désactivation de toutes les "
    L"options. Les libellés des curseurs affichent un tiret au lieu d’une valeur commune. Modifier une "
    L"option ou cliquer sur un curseur applique cette valeur à tous les écrans sélectionnés.\r\n\r\nAPERÇU "
    L"ET COMMANDES\r\nActiver l’aperçu lance un aperçu plein écran sur tous les moniteurs ; la boîte de "
    L"dialogue reste ouverte pour les réglages en direct. OK enregistre les réglages, Annuler les "
    L"abandonne. Échap ou un mouvement de souris quitte le plein écran. Utilisez Tab et Maj+Tab pour passer "
    L"d’un contrôle à l’autre ; Alt et la lettre soulignée activent une commande. Échap dans les réglages "
    L"équivaut à Annuler ; dans l’aide ou À propos, cette touche ferme uniquement cette "
    L"fenêtre.\r\n\r\nCONFIGURATION REQUISE\r\nWindows 7 à Windows 11 sont pris en charge. Pour exécuter "
    L"l’application sous Windows Vista SP2, il est nécessaire d’installer les mises à jour KB971512 et "
    L"KB2117917. L’affichage nécessite Direct3D 11, et pas seulement un ancien environnement d’exécution "
    L"DirectX.",
    L"ANIMACIÓN Y AJUSTES\r\nSpaceFlight: Superficie ondulante infinita; Vuelo de larga distancia — "
    L"superficie deformable. Asigne una sola animación a cada pantalla. Textura alterna entre superficies "
    L"texturizadas y modelo de alambre. El giro libre de la cámara cambia lentamente la dirección de la "
    L"vista en las tres dimensiones. La opción «Pausas e inversiones» añade frenadas, pausas e inversiones "
    L"aleatorias del giro; el vuelo hacia delante continúa. La velocidad va del 0 al 1600 %. Cada pantalla "
    L"tiene una escena aleatoria independiente y se renderiza a su propia frecuencia de actualización. La "
    L"luz principal, la luz de relleno, la luz ambiental y la iluminación de contornos se activan por "
    L"separado para las pantallas seleccionadas. La iluminación solo se aplica a las superficies "
    L"texturizadas. Ambas animaciones ofrecen Plano, Ondulación o Embudo. El embudo atrae la cámara hacia "
    L"el interior siguiendo una espiral descendente.\r\n\r\nMONITORES\r\nLa selección de filas determina "
    L"qué pantallas se están configurando; es "
    L"independiente de las casillas que activan las salidas de animación. Ctrl+A selecciona todas; Ctrl y "
    L"Mayús modifican la selección. Todas las opciones y los controles deslizantes de animación se aplican "
    L"a las pantallas seleccionadas. La selección se recuerda por separado para EXE y SCR. Si estaban "
    L"seleccionadas todas, se incluyen también las nuevas. Los valores distintos entre las pantallas "
    L"seleccionadas se indican mediante casillas indeterminadas y un punteado en los botones de opción, los "
    L"tiradores de los controles deslizantes y los botones para activar o desactivar todas las opciones. "
    L"Las etiquetas de los controles deslizantes muestran una raya en lugar de un valor común. Cambiar una "
    L"opción o hacer clic en un control deslizante aplica ese valor a todas las pantallas "
    L"seleccionadas.\r\n\r\nVISTA PREVIA Y CONTROLES\r\nActivar vista previa inicia una vista previa a "
    L"pantalla completa en todos los monitores; el cuadro de configuración permanece abierto para realizar "
    L"ajustes en tiempo real. Aceptar guarda y Cancelar descarta. Esc o mover el ratón cierra el "
    L"salvapantallas completo. Use Tab y Mayús+Tab para desplazarse entre controles; Alt y la letra "
    L"subrayada activan una opción. Esc en la configuración equivale a Cancelar; en Ayuda o Acerca de, "
    L"cierra únicamente esa ventana.\r\n\r\nREQUISITOS DEL SISTEMA\r\nSe admiten Windows 7 a Windows 11. "
    L"Para ejecutar la aplicación en Windows Vista SP2, es necesario instalar las actualizaciones KB971512 "
    L"y KB2117917. La representación requiere Direct3D 11, no solo un entorno de ejecución antiguo de "
    L"DirectX.",
    L"ANIMAZIONE E IMPOSTAZIONI\r\nSpaceFlight: Superficie ondulante infinita; Volo a lunga distanza — "
    L"superficie deformabile. Assegnare una sola animazione a ogni schermo. Texture alterna superfici con "
    L"texture e modello a reticolo. La rotazione libera della telecamera cambia lentamente la direzione "
    L"dello sguardo nelle tre dimensioni. L’opzione «Pause e inversioni» aggiunge rallentamenti, pause e "
    L"inversioni casuali della rotazione; il volo in avanti continua. La velocità va da 0 a 1600%. Ogni "
    L"schermo ha una scena casuale indipendente, renderizzata alla propria frequenza di aggiornamento. La "
    L"luce principale, la luce di riempimento, la luce ambientale e l’illuminazione dei contorni si "
    L"attivano separatamente per gli schermi selezionati. L’illuminazione si applica solo alle superfici "
    L"con texture. Entrambe le animazioni offrono Piano, Ondulazione o Imbuto. L’imbuto attira la "
    L"telecamera verso l’interno lungo una spirale discendente.\r\n\r\nMONITOR\r\nLa selezione delle righe "
    L"determina quali "
    L"schermi si stanno configurando ed è distinta dalle caselle che attivano le uscite di animazione. "
    L"Ctrl+A seleziona tutti gli schermi; Ctrl e Maiusc modificano la selezione. Tutte le opzioni e i "
    L"cursori dell’animazione riguardano gli schermi selezionati. La selezione viene memorizzata "
    L"separatamente per EXE e SCR. Se erano selezionati tutti gli schermi, vengono inclusi anche quelli "
    L"nuovi. Valori diversi tra gli schermi selezionati sono indicati da caselle di controllo indeterminate "
    L"e da una trama a punti sui pulsanti di opzione, sulle maniglie dei cursori e sui pulsanti per "
    L"attivare o disattivare tutte le opzioni. Le etichette dei cursori mostrano un trattino al posto di un "
    L"valore comune. Modificare un’opzione o fare clic su un cursore applica quel valore a tutti gli "
    L"schermi selezionati.\r\n\r\nANTEPRIMA E COMANDI\r\nAttiva anteprima avvia un’anteprima a schermo "
    L"intero su tutti i monitor; le impostazioni rimangono aperte per le modifiche in tempo reale. OK salva "
    L"e Annulla scarta. Esc o il movimento del mouse chiude il salvaschermo a schermo intero. Usare Tab e "
    L"Maiusc+Tab per passare tra i controlli; Alt e la lettera sottolineata attivano un comando. Esc nelle "
    L"impostazioni equivale ad Annulla; nella Guida o nelle Informazioni, chiude solo quella "
    L"finestra.\r\n\r\nREQUISITI DI SISTEMA\r\nSono supportati i sistemi da Windows 7 a Windows 11. Per "
    L"eseguire l’applicazione su Windows Vista SP2, è necessario installare gli aggiornamenti KB971512 e "
    L"KB2117917. La visualizzazione richiede Direct3D 11, non soltanto un vecchio runtime DirectX.",
    L"ANIMAÇÃO E DEFINIÇÕES\r\nSpaceFlight: Superfície ondulante infinita; Voo de longa distância — "
    L"superfície deformável. Atribua uma única animação a cada ecrã. Textura alterna entre superfícies "
    L"texturadas e modelo em arame. A rotação livre da câmara muda lentamente a direção da vista nas três "
    L"dimensões. A opção «Pausas e inversões» acrescenta desacelerações, pausas e inversões aleatórias da "
    L"rotação; o voo para a frente continua. A velocidade vai de 0 a 1600%. Cada ecrã tem uma cena "
    L"aleatória independente, apresentada à sua própria frequência de atualização. A luz principal, a luz "
    L"de preenchimento, a luz ambiente e a iluminação dos contornos podem ser ativadas separadamente nos "
    L"monitores selecionados. A iluminação aplica-se apenas às superfícies com textura. Ambas as animações "
    L"oferecem Plano, Ondulação ou Funil. O funil atrai a câmara para o interior ao longo de uma espiral "
    L"descendente.\r\n\r\nMONITORES\r\nA "
    L"seleção das linhas determina os ecrãs a configurar e é independente das caixas que ativam as saídas "
    L"de animação. Ctrl+A seleciona todos os ecrãs; Ctrl e Shift alteram a seleção. Todas as opções e "
    L"controlos deslizantes da animação aplicam-se aos ecrãs selecionados. A seleção é guardada "
    L"separadamente para EXE e SCR. Se todos estavam selecionados, os novos ecrãs também são incluídos. "
    L"Valores diferentes entre os ecrãs selecionados são indicados por caixas de verificação indeterminadas "
    L"e por um padrão pontilhado nos botões de opção, nas pegas dos controlos deslizantes e nos botões para "
    L"ativar ou desativar todas as opções. As etiquetas dos controlos deslizantes apresentam um travessão "
    L"em vez de um valor comum. Alterar uma opção ou clicar num controlo deslizante aplica esse valor a "
    L"todos os ecrãs selecionados.\r\n\r\nPRÉ-VISUALIZAÇÃO E CONTROLOS\r\nAtivar pré-visualização inicia "
    L"uma pré-visualização em ecrã inteiro em todos os monitores e permite ajustes em tempo real. OK guarda "
    L"as definições e Cancelar descarta-as. Esc ou o movimento do rato termina a proteção em ecrã inteiro. "
    L"Use Tab e Shift+Tab para passar entre controlos; Alt e a letra sublinhada ativam um comando. Esc nas "
    L"definições equivale a Cancelar; na Ajuda ou em Acerca de, fecha apenas essa janela.\r\n\r\nREQUISITOS "
    L"DO SISTEMA\r\nSão suportados os sistemas Windows 7 a Windows 11. Para executar a aplicação no Windows "
    L"Vista SP2, é necessário instalar as atualizações KB971512 e KB2117917. A apresentação requer Direct3D "
    L"11, não apenas um runtime DirectX mais antigo.",
    L"ANIMACJA I USTAWIENIA\r\nSpaceFlight: Nieskończona falująca powierzchnia; Lot dalekodystansowy — "
    L"zmienna powierzchnia. Każdemu monitorowi przypisz dokładnie jedną animację. Tekstura przełącza "
    L"powierzchnie z teksturą i model szkieletowy. Swobodne obracanie kamery powoli zmienia kierunek widoku "
    L"we wszystkich trzech wymiarach. Przerwy i nawroty dodają losowe zwalnianie, pauzy i odwracanie "
    L"obrotu; lot do przodu trwa nadal. Prędkość wynosi 0–1600%. Każdy monitor ma niezależną losową scenę "
    L"wyświetlaną z własną częstotliwością odświeżania. Światło główne, światło wypełniające, światło "
    L"otoczenia i oświetlenie konturów można przełączać niezależnie dla zaznaczonych monitorów. Oświetlenie "
    L"dotyczy tylko powierzchni z teksturą. Obie animacje oferują płaszczyznę, falowanie lub lej. Lej "
    L"wciąga kamerę do środka po opadającej spirali.\r\n\r\nMONITORY\r\nZaznaczenie wierszy określa "
    L"konfigurowane "
    L"monitory i jest niezależne od pól wyboru włączających wyjścia animacji. Ctrl+A zaznacza wszystkie "
    L"monitory; Ctrl i Shift zmieniają zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą zaznaczonych "
    L"monitorów. Zaznaczenie jest zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były wszystkie "
    L"monitory, nowe również zostaną zaznaczone. Różne wartości na zaznaczonych monitorach są sygnalizowane "
    L"nieokreślonym stanem pól wyboru i kropkowaniem przycisków opcji, uchwytów suwaków oraz przycisków "
    L"włączania i wyłączania wszystkich opcji. Etykiety suwaków pokazują kreskę zamiast wspólnej wartości. "
    L"Zmiana opcji lub kliknięcie suwaka ustawia tę wartość na wszystkich zaznaczonych "
    L"monitorach.\r\n\r\nPODGLĄD I OBSŁUGA\r\nWłącz podgląd uruchamia podgląd pełnoekranowy na wszystkich "
    L"monitorach. Okno ustawień pozostaje otwarte, umożliwiając zmiany na bieżąco. OK zapisuje ustawienia, "
    L"a Anuluj je odrzuca. Esc lub ruch myszy kończy tryb pełnoekranowy. Klawisze Tab i Shift+Tab "
    L"przełączają między kontrolkami; Alt i podkreślona litera wywołują polecenie. Esc w ustawieniach "
    L"odpowiada przyciskowi Anuluj; w Pomocy lub O programie zamyka tylko to okno.\r\n\r\nWYMAGANIA "
    L"SYSTEMOWE\r\nObsługiwane są systemy od Windows 7 do Windows 11. Do uruchomienia aplikacji w systemie "
    L"Windows Vista SP2 konieczne jest zainstalowanie aktualizacji KB971512 i KB2117917. Wyświetlanie "
    L"wymaga Direct3D 11, a nie tylko starszego środowiska DirectX.",
    L"ANIMÁCIA A NASTAVENIA\r\nSpaceFlight: Nekonečná vlniaca sa plocha; Diaľkový let — premenlivá plocha. "
    L"Každému monitoru priraďte práve jednu animáciu. Textúra prepína medzi textúrovanými plochami a "
    L"drôteným modelom. Voľná rotácia kamery pomaly mení smer pohľadu vo všetkých troch rozmeroch. Voľba "
    L"„Pauzy a obraty“ pridáva náhodné spomaľovanie, prestávky a zmeny smeru otáčania; dopredný pohyb "
    L"pokračuje. Rýchlosť je 0–1600 %. Každý monitor má nezávislú náhodnú scénu vykresľovanú podľa vlastnej "
    L"obnovovacej frekvencie. Hlavné svetlo, doplnkové svetlo, základný jas a prisvetlenie obrysov možno "
    L"pre označené monitory zapínať nezávisle. Osvetlenie sa používa len pri textúrovaných plochách. "
    L"Pri oboch animáciách možno zvoliť rovinu, vlnenie alebo lievik. Lievik vťahuje kameru dovnútra po "
    L"zostupnej špirále.\r\n\r\nMONITORY\r\nOznačenie riadkov určuje, ktoré monitory práve nastavujete; je "
    L"nezávislé "
    L"od políčok zapínajúcich animačné výstupy. Ctrl+A označí všetky monitory, Ctrl a Shift upravujú "
    L"označenie. Všetky animačné voľby a posuvníky platia pre označené monitory. Označenie sa pamätá zvlášť "
    L"pre EXE a SCR. Ak boli označené všetky monitory, označia sa aj novopripojené. Rozdielne hodnoty na "
    L"označených monitoroch ukazuje neurčitý stav políčok a bodkovanie prepínačov, úchytov posuvníkov a "
    L"tlačidiel na zapnutie či vypnutie všetkých volieb. Popis posuvníka namiesto spoločnej hodnoty "
    L"zobrazuje pomlčku. Zmena voľby alebo kliknutie na posuvník zjednotí príslušnú hodnotu na označených "
    L"monitoroch.\r\n\r\nNÁHĽAD A OVLÁDANIE\r\nZapnúť náhľad spustí celoobrazovkový náhľad na všetkých "
    L"monitoroch; nastavenia zostávajú otvorené a zmeny sa prejavia ihneď. OK uloží nastavenia a Zrušiť ich "
    L"zahodí. Celoobrazovkový šetrič ukončí Esc alebo pohyb myši. Medzi ovládacími prvkami prechádzajte "
    L"klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a príslušného písmena. Esc v "
    L"nastaveniach zodpovedá tlačidlu Zrušiť; v Pomocníkovi alebo okne O aplikácii zavrie iba toto "
    L"okno.\r\n\r\nSYSTÉMOVÉ POŽIADAVKY\r\nPodporované sú systémy Windows 7 až Windows 11. Na spustenie "
    L"aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať aktualizácie KB971512 a KB2117917. "
    L"Vykresľovanie vyžaduje Direct3D 11, nie iba starší DirectX runtime.",
    L"ANIMATION OG INDSTILLINGER\r\nSpaceFlight: Uendelig bølgende flade; Langdistanceflyvetur — "
    L"formskiftende flade. Tildel præcis én animation til hver skærm. Tekstur skifter mellem teksturerede "
    L"flader og trådmodel. Frit roterende kamera ændrer langsomt synsretningen i alle tre dimensioner. "
    L"Pauser og vendinger tilføjer tilfældige opbremsninger, pauser og ændringer af rotationsretningen; "
    L"flyvningen fremad fortsætter. Hastigheden er 0–1600 %. Hver skærm har en uafhængig tilfældig scene, "
    L"der gengives med dens egen opdateringsfrekvens. Hovedlys, udfyldningslys, omgivende lys og konturlys "
    L"kan slås til og fra uafhængigt for de valgte skærme. Belysningen gælder kun teksturerede overflader. "
    L"Begge animationer tilbyder Plan, Bølger eller Tragt. Tragten trækker kameraet indad langs en "
    L"nedadgående spiral.\r\n\r\nSKÆRME\r\nMarkeringen af rækker bestemmer, hvilke skærme du indstiller, og "
    L"er "
    L"adskilt fra afkrydsningsfelterne, der aktiverer animationsoutput. Ctrl+A markerer alle skærme; Ctrl "
    L"og Skift ændrer markeringen. Alle animationsvalg og skydere gælder de markerede skærme. Markeringen "
    L"huskes separat for EXE og SCR. Hvis alle skærme var markeret, medtages også nye skærme. Forskellige "
    L"værdier på de markerede skærme vises med ubestemte afkrydsningsfelter og prikmønstre på "
    L"alternativknapper, skydergreb og knapper til at slå alle valg til eller fra. Skydernes etiketter "
    L"viser en tankestreg i stedet for en fælles værdi. Ændring af et valg eller klik på en skyder anvender "
    L"denne værdi på alle markerede skærme.\r\n\r\nFORHÅNDSVISNING OG BETJENING\r\nAktivér forhåndsvisning "
    L"starter en fuldskærmsvisning på alle skærme. Indstillingerne forbliver åbne, og ændringerne vises med "
    L"det samme. OK gemmer indstillingerne, og Annuller forkaster ændringerne. Esc eller musebevægelse "
    L"afslutter fuldskærmen. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det "
    L"understregede bogstav aktiverer en kommando. Esc i indstillingerne svarer til Annuller; i Hjælp eller "
    L"Om lukker det kun dette vindue.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 understøttes. For at "
    L"køre programmet på Windows Vista SP2 skal opdateringerne KB971512 og KB2117917 installeres. Visningen "
    L"kræver Direct3D 11, ikke kun et ældre DirectX-kørselsmiljø.",
    L"ANIMAATIO JA ASETUKSET\r\nSpaceFlight: Ääretön aaltoileva pinta; Pitkän matkan lento — muuntuva "
    L"pinta. Valitse kullekin näytölle yksi animaatio. Tekstuuri vaihtaa teksturoitujen pintojen ja "
    L"rautalankamallin välillä. Kameran vapaa pyörintä muuttaa katselusuuntaa hitaasti kaikissa kolmessa "
    L"ulottuvuudessa. Tauot ja suunnanvaihdot lisäävät satunnaisia hidastuksia, taukoja ja pyörimissuunnan "
    L"vaihtoja; lento eteenpäin jatkuu. Nopeus on 0–1600%. Jokaisella näytöllä on itsenäinen satunnainen "
    L"näkymä, joka piirretään sen omalla virkistystaajuudella. Päävalo, täytevalo, ympäristövalo ja "
    L"reunavalo voidaan kytkeä erikseen valituille näytöille. Valaistus koskee vain teksturoituja pintoja. "
    L"Molemmissa animaatioissa voi valita tason, aallot tai suppilon. Suppilo vetää kameran sisään alaspäin "
    L"kiertyvää spiraalia pitkin.\r\n\r\nNÄYTÖT\r\nRivien valinta määrää muokattavat näytöt ja on erillinen "
    L"animaatioulostulon valintaruuduista. Ctrl+A valitsee kaikki näytöt; Ctrl ja Vaihto muuttavat "
    L"valintaa. Kaikki animaatioasetukset ja liukusäätimet koskevat valittuja näyttöjä. Valinta muistetaan "
    L"erikseen EXE- ja SCR-tiloissa. Jos kaikki näytöt olivat valittuina, myös uudet näytöt valitaan. "
    L"Valittujen näyttöjen eri arvot ilmaistaan valintaruutujen määrittämättömällä tilalla sekä "
    L"valintanappien, liukusäätimien kahvojen ja kaikkien asetusten kytkentäpainikkeiden pistekuviolla. "
    L"Liukusäätimen selitteessä näkyy viiva yhteisen arvon sijasta. Asetuksen muuttaminen tai liukusäätimen "
    L"napsauttaminen asettaa kyseisen arvon kaikille valituille näytöille.\r\n\r\nESIKATSELU JA "
    L"KÄYTTÖ\r\nOta esikatselu käyttöön käynnistää koko näytön esikatselun kaikilla näytöillä. Asetusikkuna "
    L"pysyy avoinna, ja muutokset näkyvät heti. OK tallentaa asetukset ja Peruuta hylkää muutokset. Esc tai "
    L"hiiren liike lopettaa koko näytön säästäjän. Siirry säätimien välillä Tab- ja Vaihto+Tab-näppäimillä; "
    L"Alt ja alleviivattu kirjain aktivoivat komennon. Esc asetuksissa vastaa Peruuta-painiketta; Ohje- tai "
    L"Tietoja-ikkunassa se sulkee vain kyseisen ikkunan.\r\n\r\nJÄRJESTELMÄVAATIMUKSET\r\nTuettuja "
    L"käyttöjärjestelmiä ovat Windows 7–Windows 11. Sovelluksen suorittaminen Windows Vista SP2:ssa "
    L"edellyttää päivitysten KB971512 ja KB2117917 asentamista. Näyttäminen vaatii Direct3D 11:n, ei "
    L"pelkästään vanhempaa DirectX-ajoympäristöä.",
    L"HREYFIMYND OG STILLINGAR\r\nSpaceFlight: Óendanleg bylgjandi flötur; Langflug — breytilegur flötur. "
    L"Veldu nákvæmlega eina hreyfimynd fyrir hvern skjá. Áferð skiptir milli áferðarlagðra flata og "
    L"víragrindar. Frjáls snúningur myndavélar breytir sjónstefnunni hægt í öllum þremur víddum. "
    L"Valkosturinn „Hlé og stefnuskipti“ bætir við tilviljanakenndri hægingu, hléum og breytingum á "
    L"snúningsstefnu; flug áfram heldur áfram. Hraðinn er 0–1600%. Hver skjár hefur sjálfstæða "
    L"tilviljanakennda senu sem er teiknuð á eigin endurnýjunartíðni. Aðalljós, fylliljós, umhverfislýsing "
    L"og útlínulýsing eru stillt óháð hvert öðru fyrir valda skjái. Lýsingin á aðeins við um áferðarfleti. "
    L"Í báðum hreyfimyndum má velja sléttu, bylgjur eða trekt. Trektin dregur myndavélina inn eftir spíral "
    L"sem liggur niður á við.\r\n\r\nSKJÁIR\r\nVal lína ákvarðar hvaða skjám er verið að breyta og er óháð "
    L"gátreitunum "
    L"sem kveikja á hreyfimyndaúttaki. Ctrl+A velur alla skjái; Ctrl og Shift breyta valinu. Allir "
    L"valkostir og sleðar hreyfimynda gilda fyrir valda skjái. Valið er munað sérstaklega fyrir EXE og SCR. "
    L"Ef allir skjáir voru valdir bætast nýir skjáir einnig við valið. Mismunandi gildi á völdum skjám eru "
    L"sýnd með óákveðnu ástandi gátreita og punktamynstri á valhnöppum, handföngum sleða og hnöppum sem "
    L"kveikja eða slökkva á öllum valkostum. Merking sleða sýnir strik í stað sameiginlegs gildis. Að "
    L"breyta valkosti eða smella á sleða setur það gildi á alla valda skjái.\r\n\r\nFORSKOÐUN OG "
    L"NOTKUN\r\nVirkja forskoðun ræsir forskoðun á öllum skjám. Stillingaglugginn helst opinn og breytingar "
    L"sjást strax. Í lagi vistar stillingar og Hætta við hafnar breytingum. Esc eða músarhreyfing lokar "
    L"skjáhvílu á öllum skjánum. Notaðu Tab og Shift+Tab til að færa þig milli stýrieininga; Alt og "
    L"undirstrikaður stafur virkja skipun. Esc í stillingum jafngildir Hætta við; í Hjálp eða Um lokar það "
    L"aðeins þeim glugga.\r\n\r\nKERFISKRÖFUR\r\nWindows 7 til Windows 11 eru studd. Til að keyra forritið "
    L"á Windows Vista SP2 þarf að setja upp uppfærslurnar KB971512 og KB2117917. Birting krefst Direct3D "
    L"11, ekki aðeins eldri DirectX-keyrsluumhverfis.",
    L"ANIMASJON OG INNSTILLINGER\r\nSpaceFlight: Uendelig bølgende flate; Langdistanseflytur — formendrende "
    L"flate. Tilordne nøyaktig én animasjon til hver skjerm. Tekstur veksler mellom teksturerte flater og "
    L"trådmodell. Fritt roterende kamera endrer synsretningen langsomt i alle tre dimensjoner. Pauser og "
    L"vendinger legger til tilfeldige oppbremsinger, pauser og endringer i rotasjonsretningen; flyvningen "
    L"fremover fortsetter. Hastigheten er 0–1600 %. Hver skjerm har en uavhengig tilfeldig scene som "
    L"gjengis ved dens egen oppdateringsfrekvens. Hovedlys, utfyllingslys, omgivelseslys og konturlys kan "
    L"slås av og på uavhengig for de valgte skjermene. Belysningen gjelder bare teksturerte flater. Begge "
    L"animasjonene tilbyr Plan, Bølger eller Trakt. Trakten trekker kameraet innover langs en nedadgående "
    L"spiral.\r\n\r\nSKJERMER\r\nMarkeringen av rader bestemmer hvilke skjermer du redigerer, og er "
    L"atskilt fra avkrysningsboksene som aktiverer animasjonsutgangen. Ctrl+A markerer alle skjermer; Ctrl "
    L"og Skift endrer markeringen. Alle animasjonsvalg og glidebrytere gjelder de markerte skjermene. "
    L"Markeringen huskes separat for EXE og SCR. Hvis alle skjermer var markert, inkluderes også nye "
    L"skjermer. Ulike verdier på de markerte skjermene vises med ubestemte avkrysningsbokser og "
    L"prikkmønster på alternativknapper, glidebryterhåndtak og knapper for å slå alle valg av eller på. "
    L"Glidebryteretiketter viser en tankestrek i stedet for en felles verdi. Endring av et valg eller klikk "
    L"på en glidebryter bruker denne verdien på alle markerte skjermer.\r\n\r\nFORHÅNDSVISNING OG "
    L"BETJENING\r\nSlå på forhåndsvisning starter en fullskjermsvisning på alle skjermer. Innstillingene "
    L"forblir åpne, og endringene vises fortløpende. OK lagrer innstillingene og Avbryt forkaster dem. Esc "
    L"eller musebevegelse avslutter fullskjermsvisningen. Bruk Tab og Shift+Tab for å flytte mellom "
    L"kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc i innstillingene tilsvarer "
    L"Avbryt; i Hjelp eller Om lukker det bare dette vinduet.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 "
    L"støttes. For å kjøre programmet på Windows Vista SP2 må oppdateringene KB971512 og KB2117917 "
    L"installeres. Visningen krever Direct3D 11, ikke bare en eldre DirectX-kjøretid.",
    L"ANIMERING OCH INSTÄLLNINGAR\r\nSpaceFlight: Oändlig böljande yta; Långdistansflygtur — "
    L"formföränderlig yta. Tilldela varje skärm exakt en animering. Textur växlar mellan texturerade ytor "
    L"och trådmodell. Fritt roterande kamera ändrar långsamt blickriktningen i alla tre dimensioner. Pauser "
    L"och vändningar lägger till slumpmässiga inbromsningar, pauser och byten av rotationsriktning; "
    L"flygningen framåt fortsätter. Hastigheten är 0–1600 %. Varje skärm har en oberoende slumpmässig scen "
    L"som återges med dess egen uppdateringsfrekvens. Huvudljus, fyllnadsljus, omgivningsljus och "
    L"konturljus kan slås på och av oberoende för de valda skärmarna. Belysningen gäller bara texturerade "
    L"ytor. Båda animationerna erbjuder Plan, Vågor eller Tratt. Tratten drar kameran inåt längs en "
    L"nedåtgående spiral.\r\n\r\nBILDSKÄRMAR\r\nMarkeringen av rader avgör vilka skärmar du redigerar och "
    L"är skild "
    L"från kryssrutorna som aktiverar animationsutgångarna. Ctrl+A markerar alla skärmar; Ctrl och Skift "
    L"ändrar markeringen. Alla animationsalternativ och reglage gäller de markerade skärmarna. Markeringen "
    L"sparas separat för EXE och SCR. Om alla skärmar var markerade inkluderas även nya skärmar. Olika "
    L"värden på de markerade skärmarna visas med obestämda kryssrutor och punktmönster på "
    L"alternativknappar, reglagehandtag och knappar för att slå på eller av alla alternativ. Reglagens "
    L"etiketter visar ett streck i stället för ett gemensamt värde. När du ändrar ett alternativ eller "
    L"klickar på ett reglage används värdet på alla markerade skärmar.\r\n\r\nFÖRHANDSGRANSKNING OCH "
    L"ANVÄNDNING\r\nAktivera förhandsvisning startar en helskärmsvisning på alla bildskärmar. "
    L"Inställningarna förblir öppna och ändringarna visas direkt. OK sparar inställningarna och Avbryt "
    L"förkastar ändringarna. Esc eller musrörelse avslutar helskärmsläget. Använd Tab och Skift+Tab för att "
    L"flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett kommando. Esc i "
    L"inställningarna motsvarar Avbryt; i Hjälp eller Om stänger det bara det "
    L"fönstret.\r\n\r\nSYSTEMKRAV\r\nWindows 7 till Windows 11 stöds. För att köra programmet på Windows "
    L"Vista SP2 måste uppdateringarna KB971512 och KB2117917 installeras. Visningen kräver Direct3D 11, "
    L"inte bara en äldre DirectX-körningsmiljö.",
    L"ANİMASYON VE AYARLAR\r\nSpaceFlight: Sonsuz dalgalanan yüzey; Uzun mesafeli uçuş — biçim değiştiren "
    L"yüzey. Her ekrana tam bir animasyon atayın. Doku, dokulu yüzeyler ile tel kafes modeli arasında geçiş "
    L"yapar. Serbest kamera dönüşü bakış yönünü üç boyutta yavaşça değiştirir. Duraklama ve ters dönüş, "
    L"dönüşe rastgele yavaşlamalar, duraklamalar ve ters yön değişimleri ekler; ileri uçuş devam eder. Hız "
    L"0–1600% aralığındadır. Her ekranın kendi yenileme hızında çizilen bağımsız rastgele bir sahnesi "
    L"vardır. Ana ışık, dolgu ışığı, ortam ışığı ve kenar aydınlatması seçili ekranlar için ayrı ayrı "
    L"açılıp kapatılabilir. Aydınlatma yalnızca dokulu yüzeylere uygulanır. Her iki animasyonda Düzlem, "
    L"Dalgalanma veya Huni seçilebilir. Huni, kamerayı aşağı doğru bir sarmal boyunca içeri "
    L"çeker.\r\n\r\nEKRANLAR\r\nSatır seçimi, hangi "
    L"ekranların düzenlendiğini belirler; animasyon çıkışlarını açan onay kutularından ayrıdır. Ctrl+A tüm "
    L"ekranları seçer; Ctrl ve Shift seçimi değiştirir. Tüm animasyon seçenekleri ve kaydırıcılar seçili "
    L"ekranlara uygulanır. Seçim EXE ve SCR için ayrı saklanır. Tüm ekranlar seçiliyse sonradan bağlanan "
    L"ekranlar da seçime katılır. Seçili ekranlardaki farklı değerler, belirsiz durumdaki onay kutuları ve "
    L"seçenek düğmelerinde, kaydırıcı tutamaçlarında ve tüm seçenekleri açıp kapatan düğmelerde noktalı "
    L"desenle gösterilir. Kaydırıcı etiketleri ortak bir değer yerine çizgi gösterir. Bir seçeneği "
    L"değiştirmek veya kaydırıcıya tıklamak bu değeri tüm seçili ekranlara uygular.\r\n\r\nÖNİZLEME VE "
    L"KULLANIM\r\nÖnizlemeyi etkinleştir tüm monitörlerde tam ekran önizleme başlatır. Ayarlar penceresi "
    L"açık kalır ve değişiklikler anında görülür. Tamam ayarları kaydeder, İptal değişiklikleri iptal eder. "
    L"Tam ekran koruyucudan Esc veya fare hareketiyle çıkılır. Denetimler arasında Tab ve Shift+Tab ile "
    L"ilerleyin; Alt ve altı çizili harf bir komutu etkinleştirir. Ayarlarda Esc, İptal ile aynı işlevi "
    L"görür; Yardım veya Hakkında penceresinde yalnızca o pencereyi kapatır.\r\n\r\nSİSTEM "
    L"GEREKSİNİMLERİ\r\nWindows 7 ile Windows 11 arasındaki sürümler desteklenir. Uygulamayı Windows Vista "
    L"SP2'de çalıştırmak için KB971512 ve KB2117917 güncellemelerini yüklemeniz gerekir. Görüntüleme, "
    L"yalnızca eski bir DirectX çalışma zamanı değil, Direct3D 11 gerektirir.",
    L"ANIMATSIOON JA SÄTTED\r\nRiistvarakiirendusega lend lainetava pinna kohal. Lõputu lainetav pind; "
    L"Kauglend — muutuv pind. Valige igale kuvarile täpselt üks animatsioon. Tekstuuri märkeruut vahetab "
    L"tekstuuriga pinna ja traatmudeli vahel. Kaamera vaba pöörlemine muudab vaatesuunda aeglaselt kõigis "
    L"kolmes mõõtmes. Pausid ja pöördumised lisavad sellele juhuslikke aeglustusi, pause ja pöörlemissuuna "
    L"muutusi; edasilend jätkub. Kiirus on seatav vahemikus 0–1600%. Igal kuvaril on oma sõltumatu juhuslik "
    L"stseen ja värskendussagedusele vastav renderdus. Põhivalgust, täitevalgust, ümbritsevat valgust ja "
    L"kontuurivalgust saab valitud kuvaritel eraldi sisse ja välja lülitada. Valgustus kehtib ainult "
    L"tekstuuriga pindadele. Mõlemas animatsioonis saab valida tasandi, lained või lehtri. Lehter tõmbab "
    L"kaamera mööda laskuvat spiraali sissepoole.\r\n\r\nKUVARID\r\nValige loendis üks või mitu kuvaririda. "
    L"Ctrl+A valib kõik "
    L"read; Ctrl ja Shift võimaldavad valikut muuta. Animatsiooni juhtnupud ja liugurid mõjutavad ainult "
    L"valitud kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle märkeruuduga väljundi lubamine "
    L"on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja jaoks eraldi meelde. Kui varem olid "
    L"valitud kõik kuvarid, kaasatakse ka lisatud kuvarid. Valitud kuvarite erinevaid väärtusi näitavad "
    L"märkeruutude määramata olek ning raadionuppude, liugurite käepidemete ja kõigi valikute "
    L"lülitusnuppude punktimuster. Liuguri sildil on ühise väärtuse asemel kriips. Valiku muutmine või "
    L"liuguril klõpsamine määrab selle väärtuse kõigile valitud kuvaritele.\r\n\r\nEELVAADE JA "
    L"KASUTAMINE\r\nKäivitage SpaceFlight.scr Windowsi ekraanisäästjana. Selle sätted on rakenduse omadest "
    L"eraldi. Sätete eelvaade lubab täisekraanil animatsiooni jooksvalt muuta. OK salvestab muudatused ning "
    L"Loobu või Esc tühistab need. Täisekraanil ekraanisäästjast väljumiseks vajutage klahvi või liigutage "
    L"hiirt.\r\n\r\nSÜSTEEMINÕUDED\r\nWindows 7–11 toetab kõiki funktsioone. Windows Vista SP2 jaoks tuleb "
    L"paigaldada värskendused KB971512 ja KB2117917. Vaja on Direct3D 11 tuge.",
    L"BEOCHAN AGUS SOCRUITHE\r\nEitilt os cionn dromchla tonnúil le luasghéarú crua-earraí. Dromchla "
    L"tonnúil gan teorainn; Eitilt fhada — dromchla athraitheach. Roghnaigh beochan amháin do gach "
    L"monatóir. Athraíonn Uigeacht idir dromchla uigeachtaithe agus samhail sreangfhráma. Rothlaíonn rothlú "
    L"saor an cheamara an radharc go mall sna trí thoise. Cuireann Sosanna agus aisiompuithe coscánú, "
    L"sosanna agus athruithe treo randamacha leis an rothlú; leanann an eitilt chun tosaigh. Tá luas "
    L"0–1600% ar fáil. Tá radharc randamach neamhspleách ag gach monatóir agus déantar rindreáil de réir a "
    L"ráta athnuachana féin. Is féidir an príomhsholas, an solas líonta, an solas comhthimpeallach agus an "
    L"solas imill a athrú go neamhspleách do na taispeántais roghnaithe. Ní bhaineann an soilsiú ach le "
    L"dromchlaí uigeachtaithe. Tá Plána, Tonnta nó Tonnadóir ar fáil don dá bheochan. Tarraingíonn an "
    L"tonnadóir an ceamara isteach ar bhís a théann síos.\r\n\r\nTAISPEÁNTAIS\r\nRoghnaigh ró amháin nó "
    L"níos mó sa liosta monatóirí. "
    L"Roghnaíonn Ctrl+A gach ró; úsáid Ctrl agus Shift chun an roghnú a athrú. Ní athraíonn rialuithe agus "
    L"sleamhnáin na beochana ach socruithe na monatóirí roghnaithe. Ní hionann ró a roghnú agus aschur an "
    L"mhonatóra a chumasú lena bhosca seiceála. Cuimhnítear an roghnú ar leith don fheidhmchlár agus don "
    L"spárálaí. Má bhí gach monatóir roghnaithe, cuirtear monatóirí nua leis an roghnú freisin. Léirítear "
    L"luachanna éagsúla ar na monatóirí roghnaithe le boscaí seiceála i staid neamhchinnte agus le patrún "
    L"poncanna ar chnaipí raidió, ar ghreimíní sleamhnán agus ar na cnaipí a chumasaíonn nó a "
    L"dhíchumasaíonn gach rogha. Taispeántar dais ar lipéad an tsleamhnáin in ionad luach coiteann. Nuair a "
    L"athraítear rogha nó a chliceáiltear sleamhnán, cuirtear an luach sin i bhfeidhm ar gach monatóir "
    L"roghnaithe.\r\n\r\nRÉAMHAMHARC AGUS RIALÚ\r\nÚsáid SpaceFlight.scr mar spárálaí scáileáin Windows. Tá "
    L"a shocruithe ar leith ó shocruithe an fheidhmchláir. Ceadaíonn an réamhamharc lánscáileáin athruithe "
    L"beo. Sábhálann OK agus cealaíonn Cealaigh nó Esc na hathruithe. Fág an spárálaí lánscáileáin le "
    L"heochair ar bith nó le gluaiseacht na luiche.\r\n\r\nRIACHTANAIS CHÓRAIS\r\nTacaíonn Windows 7–11 "
    L"leis na gnéithe uile. Ar Windows Vista SP2 ní mór nuashonruithe KB971512 agus KB2117917. Teastaíonn "
    L"tacaíocht Direct3D 11.",
    L"ANIMACIJA IR NUOSTATOS\r\nAparatine įranga spartinamas skrydis virš banguojančio paviršiaus. Begalinė "
    L"banguojanti plokštuma; Tolimas skrydis — kintantis paviršius. Kiekvienam monitoriui pasirinkite vieną "
    L"animaciją. Tekstūros langelis perjungia tekstūruotą paviršių ir vielinį modelį. Laisvas kameros "
    L"sukimasis lėtai keičia žiūrėjimo kryptį visose trijose dimensijose. Pauzės ir apsisukimai prideda "
    L"atsitiktinį lėtėjimą, pauzes ir sukimosi krypties keitimą; skrydis pirmyn tęsiasi. Galimas 0–1600% "
    L"greitis. Kiekvienas monitorius turi nepriklausomą atsitiktinę sceną, atvaizduojamą jo atnaujinimo "
    L"dažniu. Pagrindinę, užpildančią, aplinkos ir kontūrinę šviesą galima atskirai įjungti pasirinktiems "
    L"ekranams. Apšvietimas taikomas tik tekstūruotiems paviršiams. Abiejose animacijose galima pasirinkti "
    L"plokštumą, bangas arba piltuvą. Piltuvas traukia kamerą į vidų žemyn besisukančia "
    L"spirale.\r\n\r\nMONITORIAI\r\nMonitorių sąraše "
    L"pasirinkite vieną ar kelias eilutes. Ctrl+A pasirenka visas, o Ctrl ir Shift leidžia keisti "
    L"pasirinkimą. Animacijos valdikliai ir slankikliai keičia tik pasirinktų monitorių nuostatas. Eilutės "
    L"pasirinkimas nėra tas pats, kas animacijos išvesties įjungimas jos žymimuoju langeliu. Pasirinkimas "
    L"atskirai įsimenamas programai ir užsklandai. Jei buvo pasirinkti visi monitoriai, į pasirinkimą "
    L"įtraukiami ir naujai prijungti monitoriai. Skirtingas pasirinktų monitorių reikšmes rodo neapibrėžta "
    L"žymimųjų langelių būsena ir taškinis raštas ant parinkčių mygtukų, slankiklių rankenėlių bei visų "
    L"parinkčių įjungimo ir išjungimo mygtukų. Slankiklių užrašuose vietoj bendros reikšmės rodomas "
    L"brūkšnys. Pakeitus parinktį arba spustelėjus slankiklį, ta reikšmė pritaikoma visiems pasirinktiems "
    L"monitoriams.\r\n\r\nPERŽIŪRA IR VALDYMAS\r\nNaudokite SpaceFlight.scr kaip Windows ekrano užsklandą. "
    L"Jos nuostatos atskiros nuo programos. Viso ekrano peržiūra leidžia jas keisti vykstant animacijai. OK "
    L"išsaugo, Atšaukti arba Esc atmeta pakeitimus. Užsklandą užbaikite klavišu arba pajudindami "
    L"pelę.\r\n\r\nSISTEMOS REIKALAVIMAI\r\nWindows 7–11 palaiko visas funkcijas. Windows Vista SP2 būtina "
    L"įdiegti naujinimus KB971512 ir KB2117917. Reikalingas Direct3D 11 palaikymas.",
    L"ANIMĀCIJA UN IESTATĪJUMI\r\nAparatūras paātrināts lidojums virs viļņojošas virsmas. Bezgalīga "
    L"viļņojoša virsma; Tāls lidojums — mainīga virsma. Katram monitoram izvēlieties tieši vienu animāciju. "
    L"Tekstūras rūtiņa pārslēdz teksturētu virsmu un stiepļu modeli. Brīva kameras rotācija lēnām maina "
    L"skatiena virzienu visās trijās dimensijās. Pauzes un virzienmaiņa pievieno nejaušu palēninājumu, "
    L"pauzes un rotācijas virziena maiņu; lidojums uz priekšu turpinās. Pieejams ātrums 0–1600%. Katram "
    L"monitoram ir neatkarīga nejauša aina, ko renderē tā atsvaidzināšanas frekvencē. Pamata, aizpildošo, "
    L"apkārtējo un kontūru gaismu atlasītajiem monitoriem var ieslēgt neatkarīgi. Apgaismojums attiecas "
    L"tikai uz teksturētām virsmām. Abās animācijās var izvēlēties plakni, viļņus vai piltuvi. Piltuve "
    L"ievelk kameru iekšup pa lejupejošu spirāli.\r\n\r\nMONITORI\r\nMonitoru sarakstā atlasiet vienu vai "
    L"vairākas rindas. Ctrl+A "
    L"atlasa visas, bet Ctrl un Shift ļauj mainīt atlasi. Animācijas vadīklas un slīdņi maina tikai "
    L"atlasīto monitoru iestatījumus. Rindas atlasīšana nav tas pats, kas animācijas izvades ieslēgšana ar "
    L"izvēles rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un ekrānsaudzētājam. Ja bija atlasīti visi "
    L"monitori, atlasē iekļauj arī jaunpievienotos monitorus. Atšķirīgas vērtības atlasītajos monitoros "
    L"norāda nenoteikts izvēles rūtiņu stāvoklis un punktots raksts uz radiopogām, slīdņu rokturiem un visu "
    L"iespēju ieslēgšanas vai izslēgšanas pogām. Slīdņu etiķetēs kopīgas vērtības vietā redzama domuzīme. "
    L"Mainot iespēju vai noklikšķinot uz slīdņa, šī vērtība tiek piemērota visiem atlasītajiem "
    L"monitoriem.\r\n\r\nPRIEKŠSKATĪJUMS UN LIETOŠANA\r\nIzmantojiet SpaceFlight.scr kā Windows "
    L"ekrānsaudzētāju. Tā iestatījumi ir atsevišķi no lietotnes. Pilnekrāna priekšskatījums ļauj tos mainīt "
    L"animācijas darbības laikā. OK saglabā, Atcelt vai Esc atmet izmaiņas. Pilnekrāna ekrānsaudzētāju "
    L"aizveriet ar taustiņu vai peles kustību.\r\n\r\nSISTĒMAS PRASĪBAS\r\nWindows 7–11 atbalsta visas "
    L"funkcijas. Windows Vista SP2 jāinstalē atjauninājumi KB971512 un KB2117917. Nepieciešams Direct3D 11 "
    L"atbalsts.",
    L"ANIMÁCIÓ ÉS BEÁLLÍTÁSOK\r\nHardveresen gyorsított repülés hullámzó felület felett. Végtelen hullámzó "
    L"felület; Távolsági repülés — változó felület. Monitoronként pontosan egy animáció választható. A "
    L"Textúra jelölőnégyzet a textúrázott felület és a drótváz között vált. A kamera szabad forgása lassan "
    L"változtatja a nézetet mindhárom dimenzióban. A Szünetek és irányváltás véletlenszerű lassításokat, "
    L"szüneteket és forgásirányváltásokat ad hozzá; az előrehaladás folytatódik. A sebesség 0–1600%. Minden "
    L"monitor önálló véletlenszerű jelenetet kap, saját frissítési gyakoriságához igazodó megjelenítéssel. "
    L"A főfény, a derítőfény, a környezeti fény és a peremfény külön kapcsolható a kijelölt monitorokon. A "
    L"világítás csak a textúrázott felületekre vonatkozik. Mindkét animációnál sík, hullámzás vagy tölcsér "
    L"választható. A tölcsér lefelé haladó spirál mentén húzza befelé a "
    L"kamerát.\r\n\r\nMONITOROK\r\nJelöljön ki egy vagy "
    L"több sort a monitorok listájában. A Ctrl+A mindet kijelöli; a Ctrl és a Shift módosítja a kijelölést. "
    L"Az animáció vezérlői és csúszkái csak a kijelölt monitorok beállításait változtatják. A sor "
    L"kijelölése és az animációs kimenet jelölőnégyzetes engedélyezése külön művelet. A kijelölést az "
    L"alkalmazás és a képernyőkímélő külön megjegyzi. Ha korábban minden monitor ki volt jelölve, az "
    L"újonnan csatlakoztatott monitorok is bekerülnek a kijelölésbe. A kijelölt monitorok eltérő értékeit a "
    L"jelölőnégyzetek határozatlan állapota, valamint a választógombok, a csúszkafogantyúk és az összes "
    L"beállítást be- vagy kikapcsoló gombok pontozása jelzi. A csúszkák felirata közös érték helyett "
    L"gondolatjelet mutat. Egy beállítás módosítása vagy a csúszkára kattintás az adott értéket minden "
    L"kijelölt monitorra alkalmazza.\r\n\r\nELŐNÉZET ÉS KEZELÉS\r\nA SpaceFlight.scr "
    L"Windows-képernyőkímélőként használható, az alkalmazástól külön beállításokkal. A teljes képernyős "
    L"előnézetben élőben módosíthatók a beállítások. Az OK ment, a Mégse vagy Esc elveti a módosításokat. A "
    L"teljes képernyős képernyőkímélő billentyűvel vagy egérmozgással zárható "
    L"be.\r\n\r\nRENDSZERKÖVETELMÉNYEK\r\nA Windows 7–11 minden funkciót támogat. Windows Vista SP2 alatt "
    L"telepíteni kell a KB971512 és KB2117917. Direct3D 11 támogatás szükséges.",
    L"ANIMAZZJONI U SETTINGS\r\nTitjira fuq wiċċ li jimmewweġ aċċellerata bil-ħardwer. Wiċċ infinit li "
    L"jimmewweġ; Titjira fit-tul — wiċċ li jinbidel. Agħżel animazzjoni waħda biss għal kull moniter. Nisġa "
    L"taqleb bejn wiċċ b’nisġa u mudell bil-wireframe. Ir-rotazzjoni libera tal-kamera tbiddel "
    L"id-direzzjoni tal-ħarsa bil-mod fit-tliet dimensjonijiet. L-għażla Pawżi u bidliet fid-direzzjoni "
    L"żżid deċelerazzjonijiet, pawżi u treġġigħ lura tar-rotazzjoni b’mod każwali; it-titjira ’l quddiem "
    L"tkompli. Il-veloċità hija 0–1600%. Kull moniter għandu xena każwali indipendenti li tintwera bir-rata "
    L"ta’ aġġornament tiegħu. Id-dawl prinċipali, id-dawl ta’ mili, id-dawl ambjentali u d-dawl tal-kontorn "
    L"jistgħu jinxtegħlu separatament għall-iskrins magħżula. Id-dawl japplika biss għall-uċuħ bit-tessut. "
    L"Iż-żewġ animazzjonijiet joffru Pjan, Mewġ jew Lembut. Il-lembut jiġbed il-kamera ’l ġewwa tul spirali "
    L"nieżla.\r\n\r\nSKRINS\r\nAgħżel ringiela waħda jew aktar fil-lista tal-moniters. Ctrl+A "
    L"jagħżilhom kollha; Ctrl u Shift ibiddlu l-għażla. Il-kontrolli u s-sliders tal-animazzjoni jibdlu "
    L"biss is-settings tal-moniters magħżula. L-għażla ta’ ringiela hija differenti mill-attivazzjoni "
    L"tal-output permezz tal-kaxxa tal-marka. L-għażla tinżamm separatament għall-applikazzjoni u "
    L"għall-iscreen saver. Jekk il-moniters kollha kienu magħżula, il-moniters ġodda jiddaħħlu wkoll "
    L"fl-għażla. Valuri differenti fuq il-moniters magħżula jintwerew bi stat indeterminat tal-kaxxi "
    L"tal-marka u b’disinn bit-tikek fuq il-buttuni tar-radju, il-manki tas-sliders u l-buttuni li jattivaw "
    L"jew jiddiżattivaw l-għażliet kollha. It-tikketti tas-sliders juru sing minflok valur komuni. Meta "
    L"tibdel għażla jew tikklikkja slider, dak il-valur jiġi applikat għall-moniters magħżula "
    L"kollha.\r\n\r\nPREVIŻJONI U KONTROLLI\r\nUża SpaceFlight.scr bħala screen saver ta’ Windows. "
    L"Is-settings tiegħu huma separati minn dawk tal-applikazzjoni. Il-previżjoni fuq skrin sħiħ "
    L"tippermetti bidliet waqt l-animazzjoni. OK isalva u Ikkanċella jew Esc jarmi l-bidliet. Oħroġ "
    L"mill-iscreen saver bi kwalunkwe tast jew billi ċċaqlaq il-maws.\r\n\r\nREKWIŻITI "
    L"TAS-SISTEMA\r\nWindows 7–11 jappoġġja l-funzjonijiet kollha. Fuq Windows Vista SP2 għandhom jiġu "
    L"installati l-aġġornamenti KB971512 u KB2117917. Huwa meħtieġ Direct3D 11.",
    L"ANIMATIE EN INSTELLINGEN\r\nHardwareversnelde vlucht boven een golvend oppervlak. Oneindig golvend "
    L"oppervlak; Langeafstandsvlucht — veranderend oppervlak. Kies precies één animatie per beeldscherm. "
    L"Textuur schakelt tussen een getextureerd oppervlak en een draadmodel. Vrije camerarotatie verandert "
    L"de kijkrichting langzaam in alle drie dimensies. De optie Pauzes en omkeren voegt willekeurige "
    L"vertragingen, pauzes en omkeringen van de rotatie toe; de voorwaartse vlucht gaat door. De snelheid "
    L"is instelbaar op 0–1600%. Elk beeldscherm heeft een onafhankelijke willekeurige scène en wordt op "
    L"zijn eigen vernieuwingsfrequentie aangestuurd. Hoofdlicht, invullicht, omgevingslicht en randlicht "
    L"kunnen onafhankelijk worden geschakeld voor de geselecteerde beeldschermen. De verlichting geldt "
    L"alleen voor oppervlakken met textuur. Beide animaties bieden Vlak, Golven of Trechter. De trechter "
    L"trekt de camera langs een dalende spiraal naar binnen.\r\n\r\nBEELDSCHERMEN\r\nSelecteer één of meer "
    L"beeldschermrijen in de lijst. Ctrl+A selecteert alles; met Ctrl en Shift past u de selectie aan. "
    L"Animatieknoppen en schuifregelaars wijzigen alleen de instellingen van de geselecteerde "
    L"beeldschermen. Een rij selecteren is iets anders dan de animatie-uitvoer inschakelen met het "
    L"selectievakje. De selectie wordt apart onthouden voor de toepassing en de schermbeveiliging. Als alle "
    L"beeldschermen waren geselecteerd, worden nieuw aangesloten beeldschermen ook geselecteerd. "
    L"Verschillende waarden op geselecteerde beeldschermen worden aangegeven door selectievakjes in "
    L"onbepaalde toestand en een stippelpatroon op keuzerondjes, schuifknoppen en knoppen om alle opties in "
    L"of uit te schakelen. De labels van schuifregelaars tonen een streepje in plaats van een "
    L"gemeenschappelijke waarde. Een optie wijzigen of op een schuifregelaar klikken past die waarde toe op "
    L"alle geselecteerde beeldschermen.\r\n\r\nVOORBEELD EN BEDIENING\r\nGebruik SpaceFlight.scr als "
    L"Windows-schermbeveiliging met eigen instellingen. Het schermvullende voorbeeld laat live aanpassingen "
    L"toe. OK slaat wijzigingen op; Annuleren of Esc verwerpt ze. Sluit de schermvullende schermbeveiliging "
    L"met een toets of een muisbeweging.\r\n\r\nSYSTEEMVEREISTEN\r\nWindows 7–11 ondersteunt alle functies. "
    L"Voor Windows Vista SP2 moet u updates KB971512 en KB2117917. Direct3D 11-ondersteuning is vereist.",
    L"ANIMAȚIE ȘI SETĂRI\r\nZbor deasupra unei suprafețe ondulate accelerat hardware. Suprafață ondulată "
    L"infinită; Zbor la distanță — suprafață variabilă. Alegeți exact o animație pentru fiecare monitor. "
    L"Textură comută între suprafața texturată și modelul de sârmă. Rotirea liberă a camerei schimbă lent "
    L"direcția privirii în toate cele trei dimensiuni. Pauze și inversări adaugă încetiniri, pauze și "
    L"inversări ale rotației la intervale aleatorii; zborul înainte continuă. Viteza este 0–1600%. Fiecare "
    L"monitor are o scenă aleatorie independentă, randată la propria rată de reîmprospătare. Lumina "
    L"principală, lumina de umplere, lumina ambiantă și lumina de contur pot fi comutate separat pentru "
    L"ecranele selectate. Iluminarea se aplică doar suprafețelor texturate. Ambele animații oferă Plan, "
    L"Ondulații sau Pâlnie. Pâlnia atrage camera spre interior de-a lungul unei spirale "
    L"descendente.\r\n\r\nMONITOARE\r\nSelectați "
    L"unul sau mai multe rânduri din lista monitoarelor. Ctrl+A le selectează pe toate; Ctrl și Shift "
    L"modifică selecția. Comenzile și glisoarele animației schimbă numai setările monitoarelor selectate. "
    L"Selectarea unui rând diferă de activarea ieșirii prin caseta sa de selectare. Selecția este reținută "
    L"separat pentru aplicație și economizor. Dacă erau selectate toate monitoarele, sunt incluse și cele "
    L"conectate ulterior. Valorile diferite de pe monitoarele selectate sunt indicate prin starea "
    L"nedeterminată a casetelor de selectare și un model punctat pe butoanele radio, mânerele glisoarelor "
    L"și butoanele de activare sau dezactivare a tuturor opțiunilor. Etichetele glisoarelor afișează o "
    L"liniuță în locul unei valori comune. Modificarea unei opțiuni sau clicul pe un glisor aplică acea "
    L"valoare tuturor monitoarelor selectate.\r\n\r\nPREVIZUALIZARE ȘI COMENZI\r\nFolosiți SpaceFlight.scr "
    L"drept economizor de ecran Windows, cu setări separate de aplicație. Previzualizarea pe tot ecranul "
    L"permite ajustări în timp real. OK salvează modificările; Anulare sau Esc le anulează. Ieșiți din "
    L"economizor apăsând o tastă sau mișcând mouse-ul.\r\n\r\nCERINȚE DE SISTEM\r\nWindows 7–11 acceptă "
    L"toate funcțiile. Pentru Windows Vista SP2 trebuie instalate actualizările KB971512 și KB2117917. Este "
    L"necesar Direct3D 11.",
    L"ΚΙΝΗΣΗ ΚΑΙ ΡΥΘΜΙΣΕΙΣ\r\nΠτήση πάνω από κυματοειδή επιφάνεια με επιτάχυνση υλικού. Απέραντη "
    L"κυματοειδής επιφάνεια; Μακρινή πτήση — μεταβαλλόμενη επιφάνεια. Επιλέξτε ακριβώς μία κίνηση ανά "
    L"οθόνη. Η Υφή εναλλάσσει επιφάνεια με υφή και συρμάτινο μοντέλο. Η ελεύθερη περιστροφή κάμερας αλλάζει "
    L"αργά την κατεύθυνση θέασης και στις τρεις διαστάσεις. Οι Παύσεις και αντιστροφές προσθέτουν τυχαίες "
    L"επιβραδύνσεις, παύσεις και αντιστροφές περιστροφής, ενώ η πτήση προς τα εμπρός συνεχίζεται. Η "
    L"ταχύτητα είναι 0–1600%. Κάθε οθόνη διαθέτει ανεξάρτητη τυχαία σκηνή που αποδίδεται στον δικό της "
    L"ρυθμό ανανέωσης. Ο κύριος φωτισμός, ο φωτισμός πλήρωσης, ο περιβάλλων φωτισμός και ο φωτισμός "
    L"περιγράμματος ρυθμίζονται ανεξάρτητα για τις επιλεγμένες οθόνες. Ο φωτισμός εφαρμόζεται μόνο σε "
    L"επιφάνειες με υφή. Και οι δύο κινήσεις προσφέρουν Επίπεδο, Κυματισμό ή Χοάνη. Η χοάνη τραβά την "
    L"κάμερα προς το εσωτερικό ακολουθώντας καθοδική σπείρα.\r\n\r\nΟΘΟΝΕΣ\r\nΕπιλέξτε μία ή περισσότερες "
    L"γραμμές στη "
    L"λίστα οθονών. Το Ctrl+A επιλέγει όλες, ενώ τα Ctrl και Shift αλλάζουν την επιλογή. Τα χειριστήρια και "
    L"τα ρυθμιστικά της κίνησης αλλάζουν μόνο τις ρυθμίσεις των επιλεγμένων οθονών. Η επιλογή γραμμής "
    L"διαφέρει από την ενεργοποίηση εξόδου μέσω του πλαισίου ελέγχου της. Η επιλογή αποθηκεύεται χωριστά "
    L"για την εφαρμογή και την προφύλαξη. Αν είχαν επιλεγεί όλες οι οθόνες, περιλαμβάνονται και όσες "
    L"συνδεθούν αργότερα. Οι διαφορετικές τιμές στις επιλεγμένες οθόνες υποδεικνύονται με απροσδιόριστη "
    L"κατάσταση των πλαισίων ελέγχου και μοτίβο κουκκίδων στα κουμπιά επιλογής, στις λαβές των ρυθμιστικών "
    L"και στα κουμπιά ενεργοποίησης ή απενεργοποίησης όλων των επιλογών. Οι ετικέτες των ρυθμιστικών "
    L"δείχνουν παύλα αντί για κοινή τιμή. Η αλλαγή επιλογής ή το κλικ σε ρυθμιστικό εφαρμόζει την τιμή σε "
    L"όλες τις επιλεγμένες οθόνες.\r\n\r\nΠΡΟΕΠΙΣΚΟΠΗΣΗ ΚΑΙ ΧΕΙΡΙΣΜΟΣ\r\nΧρησιμοποιήστε το SpaceFlight.scr "
    L"ως προφύλαξη οθόνης Windows με χωριστές ρυθμίσεις από την εφαρμογή. Η προεπισκόπηση πλήρους οθόνης "
    L"επιτρέπει ζωντανές αλλαγές. Το OK αποθηκεύει και το Άκυρο ή Esc απορρίπτει τις αλλαγές. Τερματίστε "
    L"την προφύλαξη με πλήκτρο ή κίνηση του ποντικιού.\r\n\r\nΑΠΑΙΤΗΣΕΙΣ ΣΥΣΤΗΜΑΤΟΣ\r\nΤα Windows 7–11 "
    L"υποστηρίζουν όλες τις λειτουργίες. Στα Windows Vista SP2 πρέπει να εγκατασταθούν οι ενημερώσεις "
    L"KB971512 και KB2117917. Απαιτείται υποστήριξη Direct3D 11.",
    L"ANIMACIJA I POSTAVKE\r\nHardverski ubrzan let iznad valovite površine. Beskonačna valovita površina; "
    L"Daleki let — promjenjiva površina. Za svaki monitor odaberite tačno jednu animaciju. Tekstura mijenja "
    L"prikaz između teksturirane površine i žičanog modela. Slobodno okretanje kamere polako mijenja smjer "
    L"pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, pauze i promjene smjera "
    L"rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki monitor ima nezavisnu nasumičnu scenu "
    L"koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, "
    L"ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. "
    L"Osvjetljenje se primjenjuje samo na teksturirane površine. Obje animacije nude ravan, valove ili "
    L"lijevak. Lijevak uvlači kameru prema unutra duž silazne spirale.\r\n\r\nMONITORI\r\nOdaberite jedan "
    L"ili više "
    L"redova u listi monitora. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači "
    L"animacije mijenjaju samo postavke odabranih monitora. Odabir reda nije isto što i uključivanje izlaza "
    L"njegovom kućicom. Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
    L"odabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na odabranim "
    L"monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, ručkama "
    L"klizača i dugmadima za uključivanje ili isključivanje svih opcija. Oznake klizača prikazuju crticu "
    L"umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost na sve "
    L"odabrane monitore.\r\n\r\nPREGLED I UPRAVLJANJE\r\nKoristite SpaceFlight.scr kao Windows čuvar ekrana "
    L"s odvojenim postavkama. Pregled preko cijelog ekrana omogućava izmjene uživo. OK čuva, a Otkaži ili "
    L"Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili pomjeranjem miša.\r\n\r\nSISTEMSKI "
    L"ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja "
    L"KB971512 i KB2117917. Potreban je Direct3D 11.",
    L"ANIMACIJA I POSTAVKE\r\nHardverski ubrzan let iznad valovite plohe. Beskonačna valovita ploha; Daleki "
    L"let — promjenjiva ploha. Za svaki zaslon odaberite točno jednu animaciju. Tekstura mijenja prikaz "
    L"između teksturirane plohe i žičanog modela. Slobodno okretanje kamere polako mijenja smjer pogleda u "
    L"sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, stanke i promjene smjera rotacije; "
    L"let naprijed se nastavlja. Brzina je 0–1600%. Svaki zaslon ima neovisnu nasumičnu scenu koja se "
    L"prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko svjetlo, ambijentalno "
    L"svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. Osvjetljenje se "
    L"primjenjuje samo na teksturirane površine. Obje animacije nude ravninu, valove ili lijevak. Lijevak "
    L"uvlači kameru prema unutra duž silazne spirale.\r\n\r\nMONITORI\r\nOdaberite jedan ili više redaka na "
    L"popisu "
    L"zaslona. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije mijenjaju "
    L"samo postavke odabranih zaslona. Odabir retka nije isto što i uključivanje izlaza njegovim potvrdnim "
    L"okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar zaslona. Ako su prethodno bili odabrani svi "
    L"zasloni, uključuju se i novopriključeni zasloni. Različite vrijednosti na odabranim zaslonima "
    L"prikazuju se neodređenim stanjem potvrdnih okvira i točkastim uzorkom na izbornim gumbima, ručkama "
    L"klizača i gumbima za uključivanje ili isključivanje svih mogućnosti. Oznake klizača prikazuju crticu "
    L"umjesto zajedničke vrijednosti. Promjena mogućnosti ili klik na klizač primjenjuje tu vrijednost na "
    L"sve odabrane zaslone.\r\n\r\nPRETPREGLED I UPRAVLJANJE\r\nKoristite SpaceFlight.scr kao Windows čuvar "
    L"zaslona s odvojenim postavkama. Pretpregled preko cijelog zaslona omogućuje izmjene uživo. OK sprema, "
    L"a Odustani ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili pomicanjem "
    L"miša.\r\n\r\nZAHTJEVI SUSTAVA\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate "
    L"instalirati ažuriranja KB971512 i KB2117917. Potreban je Direct3D 11.",
    L"ANIMACIJA IN NASTAVITVE\r\nStrojno pospešen let nad valovito ploskvijo. Neskončna valovita ploskev; "
    L"Oddaljeni let — spreminjajoča se ploskev. Za vsak zaslon izberite natanko eno animacijo. Tekstura "
    L"preklaplja med teksturirano ploskvijo in žičnim modelom. Prosto vrtenje kamere počasi spreminja smer "
    L"pogleda v vseh treh razsežnostih. Premori in obrati dodajo naključne upočasnitve, premore in obrate "
    L"smeri vrtenja; let naprej se nadaljuje. Hitrost je 0–1600%. Vsak zaslon ima neodvisen naključen "
    L"prizor, ki se izrisuje z njegovo hitrostjo osveževanja. Glavno svetlobo, dopolnilno svetlobo, "
    L"okoljsko svetlobo in obrobno svetlobo je mogoče neodvisno vklapljati za izbrane zaslone. Osvetlitev "
    L"velja samo za teksturirane površine. Pri obeh animacijah lahko izberete ravnino, valovanje ali lijak. "
    L"Lijak vleče kamero navznoter po padajoči spirali.\r\n\r\nZASLONI\r\nNa seznamu zaslonov izberite eno "
    L"ali več vrstic. Ctrl+A "
    L"izbere vse, Ctrl in Shift pa spreminjata izbor. Kontrolniki in drsniki animacije spreminjajo samo "
    L"nastavitve izbranih zaslonov. Izbira vrstice ni isto kot vklop izhoda z njenim potrditvenim poljem. "
    L"Izbor se ločeno shrani za program in ohranjevalnik. Če so bili izbrani vsi zasloni, so vključeni tudi "
    L"na novo priključeni zasloni. Različne vrednosti na izbranih zaslonih označujeta nedoločeno stanje "
    L"potrditvenih polj in pikčast vzorec na izbirnih gumbih, ročicah drsnikov ter gumbih za vklop ali "
    L"izklop vseh možnosti. Oznake drsnikov namesto skupne vrednosti prikazujejo pomišljaj. Sprememba "
    L"možnosti ali klik na drsnik uveljavi to vrednost na vseh izbranih zaslonih.\r\n\r\nPREDOGLED IN "
    L"UPRAVLJANJE\r\nUporabite SpaceFlight.scr kot ohranjevalnik zaslona Windows z ločenimi nastavitvami. "
    L"Celozaslonski predogled omogoča sprotne spremembe. OK jih shrani, Prekliči ali Esc jih zavrže. "
    L"Ohranjevalnik zapustite s tipko ali premikom miške.\r\n\r\nSISTEMSKE ZAHTEVE\r\nWindows 7–11 podpira "
    L"vse funkcije. Za Windows Vista SP2 morate namestiti posodobitvi KB971512 in KB2117917. Potrebna je "
    L"podpora Direct3D 11.",
    L"ANIMACIJA I PODEŠAVANJA\r\nHardverski ubrzan let iznad talasaste površine. Beskonačna talasasta "
    L"površina; Daleki let — promjenljiva površina. Za svaki monitor izaberite tačno jednu animaciju. "
    L"Tekstura mijenja prikaz između teksturisane površine i žičanog modela. Slobodno okretanje kamere "
    L"polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, pauze "
    L"i promjene smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki monitor ima nezavisnu "
    L"nasumičnu scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko "
    L"svjetlo, ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. "
    L"Osvjetljenje se primjenjuje samo na teksturirane površine. Obje animacije nude ravan, talase ili "
    L"lijevak. Lijevak uvlači kameru prema unutra duž silazne spirale.\r\n\r\nMONITORI\r\nIzaberite jedan "
    L"ili više "
    L"redova u listi monitora. Ctrl+A bira sve; Ctrl i Shift mijenjaju izbor. Kontrole i klizači animacije "
    L"mijenjaju samo podešavanja izabranih monitora. Izbor reda nije isto što i uključivanje izlaza "
    L"njegovom kućicom. Izbor se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
    L"izabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na izabranim "
    L"monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, ručkama "
    L"klizača i dugmadima za uključivanje ili isključivanje svih opcija. Oznake klizača prikazuju crticu "
    L"umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost na sve "
    L"izabrane monitore.\r\n\r\nPREGLED I UPRAVLJANJE\r\nKoristite SpaceFlight.scr kao Windows čuvar ekrana "
    L"s odvojenim podešavanjima. Pregled preko cijelog ekrana omogućava izmjene uživo. OK čuva, a Otkaži "
    L"ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tastera ili pomjeranjem miša.\r\n\r\nSISTEMSKI "
    L"ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja "
    L"KB971512 i KB2117917. Potreban je Direct3D 11.",
    L"АНІМАЦЫЯ І НАЛАДЫ\r\nАпаратна паскораны палёт над хвалістай паверхняй. Бясконцая хвалістая паверхня; "
    L"Далёкі палёт — зменлівая паверхня. Для кожнага манітора выберыце роўна адну анімацыю. Тэкстура "
    L"пераключае тэкстураваную паверхню і каркасную мадэль. Свабоднае кручэнне камеры павольна змяняе "
    L"напрамак погляду ва ўсіх трох вымярэннях. Паўзы і развароты дадаюць выпадковыя запаволенні, паўзы і "
    L"змены напрамку кручэння; палёт наперад працягваецца. Хуткасць — 0–1600%. Кожны манітор мае незалежную "
    L"выпадковую сцэну з вывадам паводле ўласнай частаты абнаўлення. Асноўнае, запаўняльнае, фонавае і "
    L"контурнае святло можна пераключаць незалежна для выбраных манітораў. Асвятленне дзейнічае толькі на "
    L"тэкстураваных паверхнях. У абедзвюх анімацыях можна выбраць плоскасць, хвалі або варонку. Варонка "
    L"зацягвае камеру ўнутр па сыходнай спіралі.\r\n\r\nМАНІТОРЫ\r\nВыберыце адзін або некалькі радкоў у "
    L"спісе манітораў. "
    L"Ctrl+A выбірае ўсе; Ctrl і Shift змяняюць выбар. Элементы кіравання і паўзункі анімацыі змяняюць "
    L"толькі налады выбраных манітораў. Выбар радка і ўключэнне вываду яго сцяжком — розныя дзеянні. Выбар "
    L"асобна захоўваецца для праграмы і застаўкі. Калі раней былі выбраны ўсе маніторы, да выбару "
    L"далучаюцца і новыя маніторы. Розныя значэнні на выбраных маніторах пазначаюцца нявызначаным станам "
    L"сцяжкоў і кропкавым узорам на пераключальніках, ручках паўзункоў і кнопках уключэння або выключэння "
    L"ўсіх параметраў. У подпісах паўзункоў замест агульнага значэння паказваецца працяжнік. Змена "
    L"параметра або націск на паўзунок ужывае гэта значэнне да ўсіх выбраных манітораў.\r\n\r\nПЕРАДПРАГЛЯД "
    L"І КІРАВАННЕ\r\nВыкарыстоўвайце SpaceFlight.scr як застаўку Windows з асобнымі наладамі. Поўнаэкранны "
    L"перадпрагляд дазваляе змяняць іх падчас анімацыі. OK захоўвае змены, Скасаваць або Esc адхіляе іх. "
    L"Для выхаду з застаўкі націсніце клавішу або паварушыце мышшу.\r\n\r\nСІСТЭМНЫЯ "
    L"ПАТРАБАВАННІ\r\nWindows 7–11 падтрымлівае ўсе функцыі. Для Windows Vista SP2 неабходна ўсталяваць "
    L"абнаўленні KB971512 і KB2117917. Патрэбна падтрымка Direct3D 11.",
    L"АНИМАЦИЯ И НАСТРОЙКИ\r\nХардуерно ускорен полет над вълнообразна повърхнина. Безкрайна вълнообразна "
    L"повърхнина; Далечен полет — променяща се повърхнина. Изберете точно една анимация за всеки монитор. "
    L"Текстура превключва между текстурирана повърхнина и телен модел. Свободното въртене на камерата бавно "
    L"променя посоката на погледа в трите измерения. Опцията „Паузи и обръщания“ добавя случайни забавяния, "
    L"паузи и обръщания на въртенето; полетът напред продължава. Скоростта е 0–1600%. Всеки монитор има "
    L"независима случайна сцена, изобразявана с неговата честота на опресняване. Основната, запълващата, "
    L"околната и контурната светлина се включват независимо за избраните монитори. Осветлението се прилага "
    L"само към текстурираните повърхности. И двете анимации предлагат равнина, вълни или фуния. Фунията "
    L"привлича камерата навътре по низходяща спирала.\r\n\r\nМОНИТОРИ\r\nИзберете един или повече редове в "
    L"списъка "
    L"с монитори. Ctrl+A избира всички; Ctrl и Shift променят избора. Контролите и плъзгачите на анимацията "
    L"променят само настройките на избраните монитори. Избирането на ред и включването на изхода чрез "
    L"отметката му са различни действия. Изборът се запомня отделно за приложението и скрийнсейвъра. Ако са "
    L"били избрани всички монитори, включват се и новосвързаните. Различните стойности на избраните "
    L"монитори се показват с неопределено състояние на отметките и точков шаблон върху радиобутоните, "
    L"дръжките на плъзгачите и бутоните за включване или изключване на всички опции. Надписите на "
    L"плъзгачите показват тире вместо обща стойност. Промяна на опция или щракване върху плъзгач прилага "
    L"стойността към всички избрани монитори.\r\n\r\nПРЕГЛЕД И УПРАВЛЕНИЕ\r\nИзползвайте SpaceFlight.scr "
    L"като скрийнсейвър на Windows с отделни настройки. Прегледът на цял екран позволява промени в реално "
    L"време. OK запазва промените; Отказ или Esc ги отхвърля. Излезте от скрийнсейвъра с клавиш или "
    L"движение на мишката.\r\n\r\nСИСТЕМНИ ИЗИСКВАНИЯ\r\nWindows 7–11 поддържа всички функции. За Windows "
    L"Vista SP2 трябва да се инсталират актуализациите KB971512 и KB2117917. Изисква се поддръжка на "
    L"Direct3D 11.",
    L"АНИМАЦИЈА И ПОСТАВКИ\r\nХардверски забрзан лет над брановидна површина. Бесконечна брановидна "
    L"површина; Далечен лет — променлива површина. За секој монитор изберете точно една анимација. Текстура "
    L"менува текстурирана површина и жичен модел. Слободното вртење на камерата полека го менува погледот "
    L"во сите три димензии. Опцијата „Паузи и пресврти“ додава случајни забавувања, паузи и промени на "
    L"насоката на вртење; летот напред продолжува. Брзината е 0–1600%. Секој монитор има независна случајна "
    L"сцена што се прикажува со неговата стапка на освежување. Главното, дополнителното, амбиенталното и "
    L"контурното светло може да се вклучуваат одделно за избраните монитори. Осветлувањето важи само за "
    L"текстурираните површини. Двете анимации нудат рамнина, бранови или инка. Инката ја влече камерата "
    L"навнатре по надолна спирала.\r\n\r\nМОНИТОРИ\r\nИзберете еден или повеќе редови во списокот на "
    L"монитори. "
    L"Ctrl+A ги избира сите; Ctrl и Shift го менуваат изборот. Контролите и лизгачите на анимацијата ги "
    L"менуваат само поставките на избраните монитори. Избирањето ред и вклучувањето на излезот преку "
    L"неговото поле се различни дејства. Изборот се памети одделно за апликацијата и чуварот. Ако биле "
    L"избрани сите монитори, се вклучуваат и новоповрзаните монитори. Различните вредности на избраните "
    L"монитори се прикажуваат со неопределена состојба на полињата за избор и точкест образец на "
    L"радио-копчињата, рачките на лизгачите и копчињата за вклучување или исклучување на сите опции. "
    L"Ознаките на лизгачите прикажуваат црта наместо заедничка вредност. Менувањето опција или кликнувањето "
    L"на лизгач ја применува вредноста на сите избрани монитори.\r\n\r\nПРЕГЛЕД И УПРАВУВАЊЕ\r\nКористете "
    L"SpaceFlight.scr како Windows чувар на екранот со одделни поставки. Прегледот на цел екран овозможува "
    L"измени во живо. OK ги зачувува, а Откажи или Esc ги отфрла измените. Излезете од чуварот со копче или "
    L"движење на глувчето.\r\n\r\nСИСТЕМСКИ БАРАЊА\r\nWindows 7–11 ги поддржува сите функции. За Windows "
    L"Vista SP2 мора да се инсталираат ажурирањата KB971512 и KB2117917. Потребна е поддршка за Direct3D 11.",
    L"АНИМАЦИЈА И ПОДЕШАВАЊА\r\nХардверски убрзан лет изнад таласасте површи. Бесконачна таласаста површ; "
    L"Далеки лет — променљива површ. За сваки монитор изаберите тачно једну анимацију. Текстура мења приказ "
    L"између текстурисане површи и жичаног модела. Слободно окретање камере полако мења смер погледа у све "
    L"три димензије. Паузе и обрти додају насумично успоравање, паузе и промене смера ротације; лет напред "
    L"се наставља. Брзина је 0–1600%. Сваки монитор има независну насумичну сцену која се приказује према "
    L"његовој учестаности освежавања. Главно, допунско, амбијентално и контурно светло могу се засебно "
    L"укључивати за изабране мониторе. Осветљење важи само за текстуриране површине. Обе анимације нуде "
    L"раван, таласе или левак. Левак увлачи камеру ка унутрашњости дуж силазне "
    L"спирале.\r\n\r\nМОНИТОРИ\r\nИзаберите "
    L"један или више редова у листи монитора. Ctrl+A бира све; Ctrl и Shift мењају избор. Контроле и "
    L"клизачи анимације мењају само подешавања изабраних монитора. Избор реда није исто што и укључивање "
    L"излаза његовим пољем за потврду. Избор се памти одвојено за апликацију и чувар екрана. Ако су "
    L"претходно били изабрани сви монитори, укључују се и новоприкључени монитори. Различите вредности на "
    L"изабраним мониторима приказују се неодређеним стањем поља за потврду и тачкастим узорком на дугмадима "
    L"избора, ручкама клизача и дугмадима за укључивање или искључивање свих опција. Ознаке клизача "
    L"приказују црту уместо заједничке вредности. Промена опције или клик на клизач примењује ту вредност "
    L"на све изабране мониторе.\r\n\r\nПРЕГЛЕД И УПРАВЉАЊЕ\r\nКористите SpaceFlight.scr као Windows чувар "
    L"екрана са одвојеним подешавањима. Преглед преко целог екрана омогућава измене уживо. OK чува, а "
    L"Откажи или Esc одбацује измене. Из чувара изађите притиском тастера или померањем "
    L"миша.\r\n\r\nСИСТЕМСКИ ЗАХТЕВИ\r\nWindows 7–11 подржава све функције. За Windows Vista SP2 морате "
    L"инсталирати ажурирања KB971512 и KB2117917. Потребан је Direct3D 11.",
    L"АНІМАЦІЯ ТА НАЛАШТУВАННЯ\r\nАпаратно прискорений політ над хвилястою поверхнею. Нескінченна хвиляста "
    L"поверхня; Далекий політ — мінлива поверхня. Для кожного монітора виберіть рівно одну анімацію. "
    L"Текстура перемикає текстуровану поверхню та каркасну модель. Вільне обертання камери повільно змінює "
    L"напрямок погляду в усіх трьох вимірах. Паузи та зміни напрямку додають випадкові уповільнення, паузи "
    L"та зміни напрямку обертання; політ уперед триває. Швидкість — 0–1600%. Кожен монітор має незалежну "
    L"випадкову сцену з виведенням відповідно до власної частоти оновлення. Основне, заповнювальне, фонове "
    L"та контурне світло можна незалежно перемикати для вибраних моніторів. Освітлення діє лише на "
    L"текстурованих поверхнях. В обох анімаціях можна вибрати площину, хвилі або лійку. Лійка втягує камеру "
    L"всередину низхідною спіраллю.\r\n\r\nМОНІТОРИ\r\nВиберіть один або кілька рядків у списку моніторів. "
    L"Ctrl+A "
    L"вибирає всі; Ctrl і Shift змінюють вибір. Елементи керування й повзунки анімації змінюють лише "
    L"налаштування вибраних моніторів. Вибір рядка та ввімкнення виведення його прапорцем — різні дії. "
    L"Вибір зберігається окремо для програми й заставки. Якщо раніше були вибрані всі монітори, до вибору "
    L"долучаються й новопідключені. Різні значення на вибраних моніторах позначаються невизначеним станом "
    L"прапорців і крапковим візерунком на перемикачах, ручках повзунків і кнопках увімкнення або вимкнення "
    L"всіх параметрів. Підписи повзунків показують тире замість спільного значення. Зміна параметра або "
    L"натискання на повзунок застосовує це значення до всіх вибраних моніторів.\r\n\r\nПОПЕРЕДНІЙ ПЕРЕГЛЯД "
    L"І КЕРУВАННЯ\r\nВикористовуйте SpaceFlight.scr як заставку Windows з окремими налаштуваннями. "
    L"Повноекранний попередній перегляд дозволяє змінювати їх під час анімації. OK зберігає зміни, "
    L"Скасувати або Esc відхиляє їх. Для виходу із заставки натисніть клавішу або порухайте "
    L"мишею.\r\n\r\nСИСТЕМНІ ВИМОГИ\r\nWindows 7–11 підтримує всі функції. Для Windows Vista SP2 потрібно "
    L"встановити оновлення KB971512 і KB2117917. Потрібна підтримка Direct3D 11.",
    L"АНИМАЦИЯ И НАСТРОЙКИ\r\nАппаратно ускоренный полёт над волнообразной поверхностью. Бесконечная "
    L"волнообразная поверхность; Дальний полёт — меняющаяся поверхность. Для каждого монитора выберите "
    L"ровно одну анимацию. Текстура переключает текстурированную поверхность и каркасную модель. Свободное "
    L"вращение камеры медленно меняет направление взгляда во всех трёх измерениях. Паузы и смены "
    L"направления добавляют случайные замедления, паузы и изменения направления вращения; полёт вперёд "
    L"продолжается. Скорость — 0–1600%. Каждый монитор имеет независимую случайную сцену с выводом согласно "
    L"собственной частоте обновления. Основной, заполняющий, фоновый и контурный свет можно независимо "
    L"переключать для выбранных мониторов. Освещение применяется только к текстурированным поверхностям. "
    L"В обеих анимациях можно выбрать плоскость, волны или воронку. Воронка втягивает камеру внутрь по "
    L"нисходящей спирали.\r\n\r\nМОНИТОРЫ\r\nВыберите одну или несколько строк в списке мониторов. Ctrl+A "
    L"выбирает все; "
    L"Ctrl и Shift изменяют выбор. Элементы управления и ползунки анимации изменяют только настройки "
    L"выбранных мониторов. Выбор строки и включение вывода её флажком — разные действия. Выбор сохраняется "
    L"отдельно для приложения и заставки. Если раньше были выбраны все мониторы, в выбор включаются и вновь "
    L"подключённые. Разные значения на выбранных мониторах обозначаются неопределённым состоянием флажков и "
    L"точечным узором на переключателях, ручках ползунков и кнопках включения или выключения всех "
    L"параметров. Подписи ползунков показывают тире вместо общего значения. Изменение параметра или нажатие "
    L"на ползунок применяет это значение ко всем выбранным мониторам.\r\n\r\nПРЕДПРОСМОТР И "
    L"УПРАВЛЕНИЕ\r\nИспользуйте SpaceFlight.scr как заставку Windows с отдельными настройками. "
    L"Полноэкранный предпросмотр позволяет изменять их во время анимации. OK сохраняет изменения, Отмена "
    L"или Esc отклоняет их. Для выхода из заставки нажмите клавишу или подвигайте мышью.\r\n\r\nСИСТЕМНЫЕ "
    L"ТРЕБОВАНИЯ\r\nWindows 7–11 поддерживает все функции. Для Windows Vista SP2 необходимо установить "
    L"обновления KB971512 и KB2117917. Нужна поддержка Direct3D 11."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> ABOUT_DESCRIPTION_TEXTS = {
    L"Hardwarově akcelerovaný let nad vlnícími se a proměnlivými plochami.",
    L"Hardware-accelerated flight over undulating and morphing surfaces.",
    L"Hardware-accelerated flight over undulating and morphing surfaces.",
    L"Hardware-accelerated flight over undulating and morphing surfaces.",
    L"Hardwarebeschleunigter Flug über wellenförmige und veränderliche Flächen.",
    L"Vol accéléré par le matériel au-dessus de surfaces ondulantes et déformables.",
    L"Vuelo acelerado por hardware sobre superficies ondulantes y deformables.",
    L"Volo con accelerazione hardware sopra superfici ondulanti e deformabili.",
    L"Voo acelerado por hardware sobre superfícies ondulantes e deformáveis.",
    L"Sprzętowo przyspieszany lot nad falującymi i zmiennymi powierzchniami.",
    L"Hardvérovo akcelerovaný let nad vlniacimi sa a premenlivými plochami.",
    L"Hardwareaccelereret flyvetur over bølgende og formskiftende flader.",
    L"Laitteistokiihdytetty lento aaltoilevien ja muuntuvien pintojen yllä.",
    L"Vélbúnaðarhraðað flug yfir bylgjandi og breytilega fleti.",
    L"Maskinvareakselerert flytur over bølgende og formendrende flater.",
    L"Maskinvaruaccelererad flygtur över böljande och formföränderliga ytor.",
    L"Dalgalanan ve biçim değiştiren yüzeyler üzerinde donanım hızlandırmalı uçuş.",
    L"Riistvarakiirendusega lend lainetava pinna kohal.",
    L"Eitilt os cionn dromchla tonnúil le luasghéarú crua-earraí.",
    L"Aparatine įranga spartinamas skrydis virš banguojančio paviršiaus.",
    L"Aparatūras paātrināts lidojums virs viļņojošas virsmas.",
    L"Hardveresen gyorsított repülés hullámzó felület felett.",
    L"Titjira fuq wiċċ li jimmewweġ aċċellerata bil-ħardwer.",
    L"Hardwareversnelde vlucht boven een golvend oppervlak.",
    L"Zbor deasupra unei suprafețe ondulate accelerat hardware.",
    L"Πτήση πάνω από κυματοειδή επιφάνεια με επιτάχυνση υλικού.",
    L"Hardverski ubrzan let iznad valovite površine.",
    L"Hardverski ubrzan let iznad valovite plohe.",
    L"Strojno pospešen let nad valovito ploskvijo.",
    L"Hardverski ubrzan let iznad talasaste površine.",
    L"Апаратна паскораны палёт над хвалістай паверхняй.",
    L"Хардуерно ускорен полет над вълнообразна повърхнина.",
    L"Хардверски забрзан лет над брановидна површина.",
    L"Хардверски убрзан лет изнад таласасте површи.",
    L"Апаратно прискорений політ над хвилястою поверхнею.",
    L"Аппаратно ускоренный полёт над волнообразной поверхностью."
};

/// Localized website tooltips.
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
    L"Web sitesini ziyaret et",
    L"Ava veebisait",
    L"Oscail an suíomh gréasáin",
    L"Atidaryti svetainę",
    L"Atvērt tīmekļa vietni",
    L"Webhely megnyitása",
    L"Iftaħ is-sit web",
    L"Website openen",
    L"Deschidere site web",
    L"Άνοιγμα τοποθεσίας web",
    L"Posjeti web-mjesto",
    L"Posjeti web-mjesto",
    L"Obišči spletno mesto",
    L"Otvori veb-sajt",
    L"Адкрыць вэб-сайт",
    L"Отвори уебсайта",
    L"Отвори ја веб-страницата",
    L"Отвори веб-сајт",
    L"Відкрити вебсайт",
    L"Открыть веб-сайт"
};

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
    L"Doku",
    L"Tekstuur",
    L"Uigeacht",
    L"Tekstūra",
    L"Tekstūra",
    L"Textúra",
    L"Nisġa",
    L"Textuur",
    L"Textură",
    L"Υφή",
    L"Tekstura",
    L"Tekstura",
    L"Tekstura",
    L"Tekstura",
    L"Тэкстура",
    L"Текстура",
    L"Текстура",
    L"Текстура",
    L"Текстура",
    L"Текстура"
};

/// Per-monitor surface shapes available in both flight animations.
constexpr std::array<SurfaceShapeTextArray, LANGUAGE_COUNT> SURFACE_SHAPE_TEXTS = {
    SurfaceShapeTextArray{ L"Rovina", L"Zvlnění", L"Trychtýř" },
    SurfaceShapeTextArray{ L"Plane", L"Waves", L"Funnel" },
    SurfaceShapeTextArray{ L"Plane", L"Waves", L"Funnel" },
    SurfaceShapeTextArray{ L"Plane", L"Waves", L"Funnel" },
    SurfaceShapeTextArray{ L"Ebene", L"Wellen", L"Trichter" },
    SurfaceShapeTextArray{ L"Plan", L"Ondulations", L"Entonnoir" },
    SurfaceShapeTextArray{ L"Plano", L"Ondulación", L"Embudo" },
    SurfaceShapeTextArray{ L"Piano", L"Ondulazione", L"Imbuto" },
    SurfaceShapeTextArray{ L"Plano", L"Ondulação", L"Funil" },
    SurfaceShapeTextArray{ L"Płaszczyzna", L"Falowanie", L"Lej" },
    SurfaceShapeTextArray{ L"Rovina", L"Vlnenie", L"Lievik" },
    SurfaceShapeTextArray{ L"Plan", L"Bølger", L"Tragt" },
    SurfaceShapeTextArray{ L"Taso", L"Aallot", L"Suppilo" },
    SurfaceShapeTextArray{ L"Slétta", L"Bylgjur", L"Trekt" },
    SurfaceShapeTextArray{ L"Plan", L"Bølger", L"Trakt" },
    SurfaceShapeTextArray{ L"Plan", L"Vågor", L"Tratt" },
    SurfaceShapeTextArray{ L"Düzlem", L"Dalgalanma", L"Huni" },
    SurfaceShapeTextArray{ L"Tasand", L"Lained", L"Lehter" },
    SurfaceShapeTextArray{ L"Plána", L"Tonnta", L"Tonnadóir" },
    SurfaceShapeTextArray{ L"Plokštuma", L"Bangos", L"Piltuvas" },
    SurfaceShapeTextArray{ L"Plakne", L"Viļņi", L"Piltuve" },
    SurfaceShapeTextArray{ L"Sík", L"Hullámzás", L"Tölcsér" },
    SurfaceShapeTextArray{ L"Pjan", L"Mewġ", L"Lembut" },
    SurfaceShapeTextArray{ L"Vlak", L"Golven", L"Trechter" },
    SurfaceShapeTextArray{ L"Plan", L"Ondulații", L"Pâlnie" },
    SurfaceShapeTextArray{ L"Επίπεδο", L"Κυματισμός", L"Χοάνη" },
    SurfaceShapeTextArray{ L"Ravan", L"Valovi", L"Lijevak" },
    SurfaceShapeTextArray{ L"Ravnina", L"Valovi", L"Lijevak" },
    SurfaceShapeTextArray{ L"Ravnina", L"Valovanje", L"Lijak" },
    SurfaceShapeTextArray{ L"Ravan", L"Talasi", L"Lijevak" },
    SurfaceShapeTextArray{ L"Плоскасць", L"Хвалі", L"Варонка" },
    SurfaceShapeTextArray{ L"Равнина", L"Вълни", L"Фуния" },
    SurfaceShapeTextArray{ L"Рамнина", L"Бранови", L"Инка" },
    SurfaceShapeTextArray{ L"Раван", L"Таласи", L"Левак" },
    SurfaceShapeTextArray{ L"Площина", L"Хвилі", L"Лійка" },
    SurfaceShapeTextArray{ L"Плоскость", L"Волны", L"Воронка" }
};

/// Per-monitor switch for continuous camera rotation in all three dimensions.
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> CAMERA_TUMBLING_TEXTS = {
    L"Volná rotace kamery",
    L"Free camera rotation",
    L"Free camera rotation",
    L"Free camera rotation",
    L"Freie Kameradrehung",
    L"Rotation libre de la caméra",
    L"Giro libre de la cámara",
    L"Rotazione libera della telecamera",
    L"Rotação livre da câmara",
    L"Swobodne obracanie kamery",
    L"Voľná rotácia kamery",
    L"Frit roterende kamera",
    L"Kameran vapaa pyörintä",
    L"Frjáls snúningur myndavélar",
    L"Fritt roterende kamera",
    L"Fritt roterande kamera",
    L"Serbest kamera dönüşü",
    L"Kaamera vaba pöörlemine",
    L"Rothlú saor an cheamara",
    L"Laisvas kameros sukimasis",
    L"Brīva kameras rotācija",
    L"A kamera szabad forgása",
    L"Rotazzjoni libera tal-kamera",
    L"Vrije camerarotatie",
    L"Rotirea liberă a camerei",
    L"Ελεύθερη περιστροφή κάμερας",
    L"Slobodno okretanje kamere",
    L"Slobodno okretanje kamere",
    L"Prosto vrtenje kamere",
    L"Slobodno okretanje kamere",
    L"Свабоднае кручэнне камеры",
    L"Свободно въртене на камерата",
    L"Слободно вртење на камерата",
    L"Слободно окретање камере",
    L"Вільне обертання камери",
    L"Свободное вращение камеры"
};

/// Per-monitor switch for gradual stops and reversals of camera tumbling.
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> CAMERA_REVERSALS_TEXTS = {
    L"Pauzy a obraty",
    L"Pauses and reversals",
    L"Pauses and reversals",
    L"Pauses and reversals",
    L"Pausen und Umkehr",
    L"Pauses et inversions",
    L"Pausas e inversiones",
    L"Pause e inversioni",
    L"Pausas e inversões",
    L"Przerwy i nawroty",
    L"Pauzy a obraty",
    L"Pauser og vendinger",
    L"Tauot ja suunnanvaihdot",
    L"Hlé og stefnuskipti",
    L"Pauser og vendinger",
    L"Pauser och vändningar",
    L"Duraklama ve ters dönüş",
    L"Pausid ja pöördumised",
    L"Sosanna agus aisiompuithe",
    L"Pauzės ir apsisukimai",
    L"Pauzes un virzienmaiņa",
    L"Szünetek és irányváltás",
    L"Pawżi u bidliet fid-direzzjoni",
    L"Pauzes en omkeren",
    L"Pauze și inversări",
    L"Παύσεις και αντιστροφές",
    L"Pauze i obrati",
    L"Pauze i obrati",
    L"Premori in obrati",
    L"Pauze i obrati",
    L"Паўзы і развароты",
    L"Паузи и обръщания",
    L"Паузи и пресврти",
    L"Паузе и обрти",
    L"Паузи та зміни напрямку",
    L"Паузы и смены направления"
};

/// Localized per-monitor main-light captions.
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> MAIN_LIGHT_TEXTS = {
    L"Hlavní světlo",
    L"Main light",
    L"Main light",
    L"Main light",
    L"Hauptlicht",
    L"Éclairage principal",
    L"Luz principal",
    L"Luce principale",
    L"Luz principal",
    L"Światło główne",
    L"Hlavné svetlo",
    L"Hovedlys",
    L"Päävalo",
    L"Aðalljós",
    L"Hovedlys",
    L"Huvudljus",
    L"Ana ışık",
    L"Põhivalgus",
    L"Príomhsholas",
    L"Pagrindinė šviesa",
    L"Galvenā gaisma",
    L"Főfény",
    L"Dawl ewlieni",
    L"Hoofdlicht",
    L"Lumină principală",
    L"Κύριος φωτισμός",
    L"Glavno svjetlo",
    L"Glavno svjetlo",
    L"Glavna svetloba",
    L"Glavno svjetlo",
    L"Асноўнае святло",
    L"Основна светлина",
    L"Главно светло",
    L"Главно светло",
    L"Основне світло",
    L"Основной свет"
};

/// Localized per-monitor fill-light captions.
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> FILL_LIGHT_TEXTS = {
    L"Doplňkové světlo",
    L"Fill light",
    L"Fill light",
    L"Fill light",
    L"Aufhelllicht",
    L"Éclairage d’appoint",
    L"Luz de relleno",
    L"Luce di riempimento",
    L"Luz de preenchimento",
    L"Światło wypełniające",
    L"Doplnkové svetlo",
    L"Udfyldningslys",
    L"Täytevalo",
    L"Fylliljós",
    L"Utfyllingslys",
    L"Upplättningsljus",
    L"Dolgu ışığı",
    L"Täitevalgus",
    L"Solas líonta",
    L"Užpildanti šviesa",
    L"Papildu gaisma",
    L"Derítőfény",
    L"Dawl ta’ mili",
    L"Invullicht",
    L"Lumină de umplere",
    L"Φωτισμός πλήρωσης",
    L"Dopunsko svjetlo",
    L"Dopunsko svjetlo",
    L"Dopolnilna svetloba",
    L"Dopunsko svjetlo",
    L"Запаўняльнае святло",
    L"Запълваща светлина",
    L"Дополнително светло",
    L"Допунско светло",
    L"Заповнювальне світло",
    L"Заполняющий свет"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> AMBIENT_LIGHT_TEXTS = {
    L"Základní jas",
    L"Ambient light",
    L"Ambient light",
    L"Ambient light",
    L"Umgebungslicht",
    L"Éclairage ambiant",
    L"Luz ambiental",
    L"Luce ambientale",
    L"Luz ambiente",
    L"Światło otoczenia",
    L"Základný jas",
    L"Omgivende lys",
    L"Ympäristövalo",
    L"Umhverfislýsing",
    L"Omgivelseslys",
    L"Omgivningsljus",
    L"Ortam ışığı",
    L"Ümbritsev valgus",
    L"Solas comhthimpeallach",
    L"Aplinkos šviesa",
    L"Apkārtējā gaisma",
    L"Környezeti fény",
    L"Dawl ambjentali",
    L"Omgevingslicht",
    L"Lumină ambiantă",
    L"Περιβάλλων φωτισμός",
    L"Ambijentalno svjetlo",
    L"Ambijentalno svjetlo",
    L"Okoljska svetloba",
    L"Ambijentalno svjetlo",
    L"Фонавае святло",
    L"Околна светлина",
    L"Амбиентално светло",
    L"Амбијентално светло",
    L"Фонове світло",
    L"Фоновый свет"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> RIM_LIGHT_TEXTS = {
    L"Přisvětlení obrysů",
    L"Rim light",
    L"Rim light",
    L"Rim light",
    L"Konturlicht",
    L"Éclairage des contours",
    L"Iluminación de contornos",
    L"Illuminazione dei contorni",
    L"Iluminação dos contornos",
    L"Oświetlenie konturów",
    L"Prisvetlenie obrysov",
    L"Konturlys",
    L"Reunavalo",
    L"Útlínulýsing",
    L"Konturlys",
    L"Konturljus",
    L"Kenar aydınlatması",
    L"Kontuurivalgus",
    L"Solas imill",
    L"Kontūrinė šviesa",
    L"Kontūru gaisma",
    L"Peremfény",
    L"Dawl tal-kontorn",
    L"Randlicht",
    L"Lumină de contur",
    L"Φωτισμός περιγράμματος",
    L"Konturno svjetlo",
    L"Konturno svjetlo",
    L"Obrobna svetloba",
    L"Konturno svjetlo",
    L"Контурнае святло",
    L"Контурна светлина",
    L"Контурно светло",
    L"Контурно светло",
    L"Контурне світло",
    L"Контурный свет"
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
            } else if (SUBLANGID(language) == SUBLANG_ENGLISH_AUS) {
                return AppLanguage::EnglishAu;
            } else {
                return AppLanguage::EnglishUs;
            }
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
        case LANG_CROATIAN:
            switch (SUBLANGID(language)) {
                case SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_LATIN:
                case SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_CYRILLIC:
                    return AppLanguage::Bosnian;
                case SUBLANG_SERBIAN_MONTENEGRO_LATIN:
                case SUBLANG_SERBIAN_MONTENEGRO_CYRILLIC:
                    return AppLanguage::Montenegrin;
                case SUBLANG_SERBIAN_LATIN:
                case SUBLANG_SERBIAN_CYRILLIC:
                case SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_LATIN:
                case SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_CYRILLIC:
                case SUBLANG_SERBIAN_SERBIA_LATIN:
                case SUBLANG_SERBIAN_SERBIA_CYRILLIC:
                    return AppLanguage::Serbian;
                default:
                    return AppLanguage::Croatian;
            }
        case LANG_ESTONIAN:
            return AppLanguage::Estonian;
        case LANG_IRISH:
            return AppLanguage::Irish;
        case LANG_LITHUANIAN:
            return AppLanguage::Lithuanian;
        case LANG_LATVIAN:
            return AppLanguage::Latvian;
        case LANG_HUNGARIAN:
            return AppLanguage::Hungarian;
        case LANG_MALTESE:
            return AppLanguage::Maltese;
        case LANG_DUTCH:
            return AppLanguage::Dutch;
        case LANG_ROMANIAN:
            return AppLanguage::Romanian;
        case LANG_GREEK:
            return AppLanguage::Greek;
        case LANG_SLOVENIAN:
            return AppLanguage::Slovenian;
        case LANG_BELARUSIAN:
            return AppLanguage::Belarusian;
        case LANG_BULGARIAN:
            return AppLanguage::Bulgarian;
        case LANG_MACEDONIAN:
            return AppLanguage::Macedonian;
        case LANG_UKRAINIAN:
            return AppLanguage::Ukrainian;
        case LANG_RUSSIAN:
            return AppLanguage::Russian;
        default:
            return AppLanguage::EnglishUs;
    }
}

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

/// Returns the selected monitors' main-light option in the selected language.
const wchar_t* MainLightText(AppLanguage language) {
    return MAIN_LIGHT_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the selected monitors' fill-light option in the selected language.
const wchar_t* FillLightText(AppLanguage language) {
    return FILL_LIGHT_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the selected monitors' ambient-light option in the selected language.
const wchar_t* AmbientLightText(AppLanguage language) {
    return AMBIENT_LIGHT_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the selected monitors' rim-light option in the selected language.
const wchar_t* RimLightText(AppLanguage language) {
    return RIM_LIGHT_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the selected monitors' texture option in the selected language.
const wchar_t* FilledSurfaceText(AppLanguage language) {
    return FILLED_SURFACE_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

const wchar_t* SurfaceShapeText(AppLanguage language, SurfaceShape shape) {
    const std::size_t index = static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)));
    return SURFACE_SHAPE_TEXTS[index][static_cast<std::size_t>(shape)];
}

/// Returns the selected monitors' camera-tumbling option in the selected language.
const wchar_t* CameraTumblingText(AppLanguage language) {
    return CAMERA_TUMBLING_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the selected monitors’ optional camera stops and reversals caption.
const wchar_t* CameraReversalsText(AppLanguage language) {
    return CAMERA_REVERSALS_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}
