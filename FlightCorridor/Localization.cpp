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

constexpr EffectTextArray ESTONIAN_EFFECTS = {
    L"Lend nelja muutuva pinna vahel",
    L"Lend läbi muutuva lehtri"
};

constexpr EffectTextArray IRISH_EFFECTS = {
    L"Eitilt idir ceithre dhromchla athraitheacha",
    L"Eitilt trí thonnadóir athraitheach"
};

constexpr EffectTextArray LITHUANIAN_EFFECTS = {
    L"Skrydis tarp keturių kintančių paviršių",
    L"Skrydis kintančiu piltuvu"
};

constexpr EffectTextArray LATVIAN_EFFECTS = {
    L"Lidojums starp četrām mainīgām virsmām",
    L"Lidojums caur mainīgu piltuvi"
};

constexpr EffectTextArray HUNGARIAN_EFFECTS = {
    L"Repülés négy változó felület között",
    L"Repülés változó tölcsérben"
};

constexpr EffectTextArray MALTESE_EFFECTS = {
    L"Titjira bejn erba’ uċuħ li jinbidlu",
    L"Titjira f’lembut li jinbidel"
};

constexpr EffectTextArray DUTCH_EFFECTS = {
    L"Vlucht tussen vier vervormende oppervlakken",
    L"Vlucht door een vervormende trechter"
};

constexpr EffectTextArray ROMANIAN_EFFECTS = {
    L"Zbor între patru suprafețe deformabile",
    L"Zbor printr-o pâlnie deformabilă"
};

constexpr EffectTextArray GREEK_EFFECTS = {
    L"Πτήση ανάμεσα σε τέσσερις μεταβαλλόμενες επιφάνειες",
    L"Πτήση μέσα από μεταβαλλόμενη χοάνη"
};

constexpr EffectTextArray BOSNIAN_EFFECTS = {
    L"Let između četiri promjenjive površine",
    L"Let kroz promjenjivi lijevak"
};

constexpr EffectTextArray CROATIAN_EFFECTS = {
    L"Let između četiriju promjenjivih ploha",
    L"Let kroz promjenjivi lijevak"
};

constexpr EffectTextArray SLOVENIAN_EFFECTS = {
    L"Let med štirimi spreminjajočimi se ploskvami",
    L"Let skozi spreminjajoči se lijak"
};

constexpr EffectTextArray MONTENEGRIN_EFFECTS = {
    L"Let između četiri promjenljive površine",
    L"Let kroz promjenljivi lijevak"
};

constexpr EffectTextArray BELARUSIAN_EFFECTS = {
    L"Палёт паміж чатырма зменлівымі паверхнямі",
    L"Палёт праз зменлівую варонку"
};

constexpr EffectTextArray BULGARIAN_EFFECTS = {
    L"Полет между четири променящи се повърхнини",
    L"Полет през променяща се фуния"
};

constexpr EffectTextArray MACEDONIAN_EFFECTS = {
    L"Лет меѓу четири променливи површини",
    L"Лет низ променлива инка"
};

constexpr EffectTextArray SERBIAN_EFFECTS = {
    L"Лет између четири променљиве површи",
    L"Лет кроз променљиви левак"
};

constexpr EffectTextArray UKRAINIAN_EFFECTS = {
    L"Політ між чотирма мінливими поверхнями",
    L"Політ крізь мінливу лійку"
};

constexpr EffectTextArray RUSSIAN_EFFECTS = {
    L"Полёт между четырьмя меняющимися поверхностями",
    L"Полёт сквозь меняющуюся воронку"
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
    }, LocalizedText{
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
    }, LocalizedText{
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
    }, LocalizedText{
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
    }, LocalizedText{
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
    }, LocalizedText{
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
    }, LocalizedText{
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
    }, LocalizedText{
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
    }, LocalizedText{
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
    }, LocalizedText{
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
    }, LocalizedText{
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
    }, LocalizedText{
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
    }, LocalizedText{
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
    }, LocalizedText{
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
    }, LocalizedText{
        L"Norsk (bokmål)",
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
    }, LocalizedText{
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
    }, LocalizedText{
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
    }, LocalizedText{
        L"Eesti",
        L"FlightCorridor — juhtimine",
        L"FlightCorridor sätted",
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
        L"FlightCorridor — rialuithe",
        L"Socruithe FlightCorridor",
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
        L"FlightCorridor — valdymas",
        L"FlightCorridor nuostatos",
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
        L"FlightCorridor — vadība",
        L"FlightCorridor iestatījumi",
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
        L"FlightCorridor — vezérlés",
        L"FlightCorridor beállításai",
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
        L"FlightCorridor — kontrolli",
        L"Settings ta’ FlightCorridor",
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
        L"FlightCorridor — bediening",
        L"Instellingen van FlightCorridor",
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
        L"FlightCorridor — comenzi",
        L"Setări FlightCorridor",
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
        L"FlightCorridor — χειρισμός",
        L"Ρυθμίσεις FlightCorridor",
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
        L"FlightCorridor — kontrole",
        L"Postavke programa FlightCorridor",
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
        L"FlightCorridor — upravljanje",
        L"Postavke programa FlightCorridor",
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
        L"FlightCorridor — upravljanje",
        L"Nastavitve FlightCorridor",
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
        L"FlightCorridor — kontrole",
        L"Podešavanja programa FlightCorridor",
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
        L"FlightCorridor — кіраванне",
        L"Налады FlightCorridor",
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
        L"FlightCorridor — управление",
        L"Настройки на FlightCorridor",
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
        L"FlightCorridor — контроли",
        L"Поставки за FlightCorridor",
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
        L"FlightCorridor — контроле",
        L"Подешавања програма FlightCorridor",
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
        L"FlightCorridor — керування",
        L"Налаштування FlightCorridor",
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
        L"FlightCorridor — управление",
        L"Настройки FlightCorridor",
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
    L"La désinstallation a échoué car les paramètres de FlightCorridor sont ouverts. Fermez cette fenêtre "
    L"puis réessayez.",
    L"La desinstalación falló porque la configuración de FlightCorridor está abierta. Cierre esa ventana e "
    L"inténtelo de nuevo.",
    L"La disinstallazione non è riuscita perché le impostazioni di FlightCorridor sono aperte. Chiudere la "
    L"finestra e riprovare.",
    L"A desinstalação falhou porque as definições do FlightCorridor estão abertas. Feche a janela e tente "
    L"novamente.",
    L"Odinstalowanie nie powiodło się, ponieważ ustawienia FlightCorridor są otwarte. Zamknij okno i "
    L"spróbuj ponownie.",
    L"Odinštalovanie zlyhalo, pretože sú otvorené nastavenia FlightCorridor. Zatvorte ich a skúste to znova.",
    L"Afinstallationen mislykkedes, fordi indstillingerne for FlightCorridor er åbne. Luk vinduet, og prøv "
    L"igen.",
    L"Asennuksen poisto epäonnistui, koska FlightCorridor-asetukset ovat avoinna. Sulje ikkuna ja yritä "
    L"uudelleen.",
    L"Fjarlæging mistókst vegna þess að stillingar FlightCorridor eru opnar. Lokaðu glugganum og reyndu "
    L"aftur.",
    L"Avinstalleringen mislyktes fordi innstillingene for FlightCorridor er åpne. Lukk vinduet og prøv på "
    L"nytt.",
    L"Avinstallationen misslyckades eftersom inställningarna för FlightCorridor är öppna. Stäng fönstret "
    L"och försök igen.",
    L"FlightCorridor ayarları açık olduğu için kaldırma başarısız oldu. Ayarlar penceresini kapatıp yeniden "
    L"deneyin.",
    L"Sulgege FlightCorridor sätete aken ja proovige eemaldamist uuesti.",
    L"Dún fuinneog socruithe FlightCorridor agus bain triail eile as an díshuiteáil.",
    L"Uždarykite FlightCorridor nuostatų langą ir bandykite pašalinti dar kartą.",
    L"Aizveriet FlightCorridor iestatījumu logu un atkārtojiet atinstalēšanu.",
    L"Zárja be a FlightCorridor beállítási ablakát, majd próbálja újra az eltávolítást.",
    L"Agħlaq it-tieqa tas-settings ta’ FlightCorridor u erġa’ pprova tneħħih.",
    L"Sluit de instellingen van FlightCorridor en probeer het verwijderen opnieuw.",
    L"Închideți fereastra de setări FlightCorridor și încercați din nou dezinstalarea.",
    L"Κλείστε το παράθυρο ρυθμίσεων του FlightCorridor και δοκιμάστε ξανά την κατάργηση.",
    L"Zatvorite postavke programa FlightCorridor pa ponovite deinstalaciju.",
    L"Zatvorite postavke programa FlightCorridor pa ponovite deinstalaciju.",
    L"Zaprite nastavitve FlightCorridor in znova poskusite odstranitev.",
    L"Zatvorite podešavanja programa FlightCorridor pa ponovite deinstalaciju.",
    L"Закрыйце налады FlightCorridor ды паўтарыце выдаленне.",
    L"Затворете настройките на FlightCorridor и опитайте деинсталирането отново.",
    L"Затворете ги поставките за FlightCorridor и обидете се повторно да деинсталирате.",
    L"Затворите подешавања програма FlightCorridor па поновите деинсталацију.",
    L"Закрийте налаштування FlightCorridor та повторіть видалення.",
    L"Закройте настройки FlightCorridor и повторите удаление."
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
    L"ANIMACE A NASTAVENÍ\r\nFlightCorridor: Průlet čtyřmi proměnlivými plochami; Průlet proměnlivým "
    L"trychtýřem. Každému monitoru přiřaďte právě jednu animaci. Textura přepíná mezi texturovanými "
    L"plochami a drátěným modelem. Volná rotace kamery pomalu mění směr pohledu ve všech třech rozměrech. "
    L"Volba „Pauzy a obraty“ přidává náhodné zpomalování, pauzy a změny směru otáčení; dopředný pohyb "
    L"pokračuje. Rychlost animace je 0–1600 %. Každý monitor má nezávislou náhodnou scénu a vykreslování "
    L"podle své obnovovací frekvence. Hlavní světlo, doplňkové světlo, základní jas a přisvětlení obrysů "
    L"lze pro označené monitory zapínat nezávisle. Osvětlení se používá jen u texturovaných "
    L"ploch.\r\n\r\nMONITORY\r\nOznačení řádků určuje, které monitory právě nastavujete; není totožné se "
    L"zatržítky zapínajícími animační výstupy. Ctrl+A označí všechny monitory, Ctrl a Shift umožňují "
    L"upravit označení. Všechny animační volby a jezdce platí pro označené monitory. Označení se pamatuje "
    L"zvlášť pro EXE a SCR. Pokud byly označené všechny monitory, označí se i nově připojené. Různé hodnoty "
    L"na označených monitorech ukazuje neurčitý stav zatržítek a tečkování přepínačů, úchytů jezdců a "
    L"tlačítek pro zapnutí či vypnutí všech voleb. Popisek jezdce místo společné hodnoty zobrazuje pomlčku. "
    L"Změna volby nebo kliknutí na jezdec sjednotí příslušnou hodnotu na označených "
    L"monitorech.\r\n\r\nOVLÁDÁNÍ\r\nAnimační výstupy zapnete nebo vypnete zatržítky u monitorů nebo "
    L"dvojklikem na jejich řádky. Každý monitor používá nezávislou scénu. Snímek ukládá PNG, tlačítko "
    L"záznamu spouští a ukončuje MP4. Pozastavení zastaví animaci. Aplikace také instaluje nebo odinstaluje "
    L"zabalený spořič. Nastavení se ukládá průběžně. Aplikace běží pouze v jedné instanci. Další spuštění "
    L"obnoví minimalizované ovládací okno a přenese do popředí. Mezi ovládacími prvky přecházejte klávesami "
    L"Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a příslušného písmene. Esc zavře aktivní "
    L"nápovědu či okno O aplikaci; v ovládacím okně ukončí aplikaci. Pozastavení a blokování spořiče platí "
    L"pro celou aplikaci bez ohledu na označené monitory. Je-li blokování zapnuté, brání spuštění spořiče "
    L"Windows pouze tehdy, když je alespoň na jednom monitoru viditelná nepozastavená "
    L"animace.\r\n\r\nSNÍMKY A ZÁZNAM\r\nSnímek a záznam zachycují první aktivní animační monitor, nikoli "
    L"společnou plochu všech monitorů. PNG používá složku Obrázky, MP4 složku Videa; při jejich neexistenci "
    L"se použijí Dokumenty. Tlačítko Nastavení záznamu vybírá Viewport nebo TV. Viewport zachovává rozměry "
    L"animačního monitoru a jeho obnovovací frekvenci, nejvýše 60 snímků za sekundu. TV nabízí rozlišení "
    L"1920 × 1080, 1440 × 1080 nebo 1280 × 720 v poměru 16:9 a frekvenci 50, 25, 59.94 (60000/1001) nebo "
    L"29.97 (30000/1001) snímků za sekundu. Obraz zachovává poměr stran; TV používá progresivní video "
    L"BT.709 s omezeným rozsahem a vzorkováním 4:2:0. Rozlišení a snímkovou frekvenci lze vybrat pouze v "
    L"režimu TV. Okno Nastavení záznamu lze minimalizovat a neblokuje ostatní okna aplikace. OK uloží volby "
    L"pro příští záznam MP4; Storno nebo Esc nepotvrzené změny zahodí. Nahrávaný monitor nelze během "
    L"záznamu odepnout; změny ostatních monitorů záznam nezastaví. Ukončení aplikace při probíhajícím "
    L"záznamu vyžaduje potvrzení, protože současně ukončí záznam.\r\n\r\nSYSTÉMOVÉ POŽADAVKY\r\nWindows 7 "
    L"až Windows 11 podporují všechny funkce včetně snímků PNG a záznamu MP4. Pro spuštění aplikace ve "
    L"Windows Vista SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917. Záznam MP4 na Vistě v "
    L"současné verzi nefunguje. Vykreslování vyžaduje Direct3D 11, nikoli jen starší DirectX runtime. "
    L"Záznam MP4 vyžaduje dostupné součásti Media Foundation a kodér H.264.",
    L"ANIMATION AND SETTINGS\r\nFlightCorridor: Flight between four morphing surfaces; Flight through a "
    L"morphing funnel. Assign exactly one animation to each display. Texture switches between textured "
    L"surfaces and wireframe. Free camera rotation slowly changes the viewing direction in all three "
    L"dimensions. The Pauses and reversals option adds randomized braking, pauses, and reversals of the "
    L"rotation; forward flight continues. Animation speed ranges from 0–1600%. Every display has an "
    L"independent randomized scene rendered at its own refresh rate. Main light, fill light, ambient light, "
    L"and rim light can be switched independently for the selected displays. Lighting applies only to "
    L"textured surfaces.\r\n\r\nDISPLAYS\r\nRow selection determines which displays you are editing; it is "
    L"separate from the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and "
    L"Shift adjust the selection. All animation options and sliders apply to the selected displays. The "
    L"selection is remembered separately for EXE and SCR. If all displays were selected, newly connected "
    L"displays join the selection. Different values across selected displays are indicated by indeterminate "
    L"checkboxes and dotted radio buttons, slider thumbs, and buttons for enabling or disabling all "
    L"options. Slider labels show a dash instead of a shared value. Changing an option or clicking a slider "
    L"applies that value to all selected displays.\r\n\r\nCONTROLS\r\nEnable or disable animation outputs "
    L"using the display checkboxes or by double-clicking their rows. Every display uses an independent "
    L"scene. Snapshot saves a PNG and the recording button starts or stops an MP4. Pause stops the "
    L"animation. The application also installs or uninstalls its embedded screen saver. Settings are saved "
    L"continuously. Only one instance of the application runs at a time. Launching it again restores its "
    L"minimized control window and brings it to the foreground. Use Tab and Shift+Tab to move between "
    L"controls; use Alt and the underlined letter to activate a command. Esc closes the active Help or "
    L"About window; in the control window, it exits the application. Pause and screen-saver blocking apply "
    L"to the whole application, regardless of display selection. When blocking is enabled, the Windows "
    L"screen saver is prevented only while unpaused animation is visible on at least one "
    L"display.\r\n\r\nSNAPSHOTS AND RECORDING\r\nSnapshots and recordings capture the first active "
    L"animation display, not a combined image of all displays. PNG uses Pictures and MP4 uses Videos, with "
    L"Documents as the fallback if those folders do not exist. The Recording settings button selects "
    L"Viewport or TV. Viewport preserves the animation display’s dimensions and refresh rate, up to 60 "
    L"frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, "
    L"59.94 (60000/1001) or 29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV uses "
    L"progressive BT.709 limited-range 4:2:0 video. Resolution and frame rate are available only in TV "
    L"mode. The Recording settings window can be minimized and does not block the other application "
    L"windows. OK saves choices for the next MP4 recording; Cancel or Esc discards unconfirmed changes. The "
    L"recorded display cannot be detached during recording; changes to other displays do not stop the "
    L"recording. Closing the application while recording requires confirmation because it also stops the "
    L"recording.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows 7 through Windows 11 support all features, including "
    L"PNG snapshots and MP4 recording. To run the application on Windows Vista SP2, you must install "
    L"updates KB971512 and KB2117917. MP4 recording does not work on Vista in the current version. "
    L"Rendering requires Direct3D 11, not just an older DirectX runtime. MP4 recording requires available "
    L"Media Foundation components and an H.264 encoder.",
    L"ANIMATION AND SETTINGS\r\nFlightCorridor: Flight between four morphing surfaces; Flight through a "
    L"morphing funnel. Assign exactly one animation to each display. Texture switches between textured "
    L"surfaces and wireframe. Free camera rotation slowly changes the viewing direction in all three "
    L"dimensions. The Pauses and reversals option adds randomised braking, pauses and reversals of the "
    L"rotation; forward flight continues. Animation speed ranges from 0–1600%. Every display has an "
    L"independent randomised scene rendered at its own refresh rate. Main light, fill light, ambient light "
    L"and rim light can be switched independently for the selected displays. Lighting applies only to "
    L"textured surfaces.\r\n\r\nDISPLAYS\r\nRow selection determines which displays you are editing; it is "
    L"separate from the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and "
    L"Shift adjust the selection. All animation options and sliders apply to the selected displays. The "
    L"selection is remembered separately for EXE and SCR. If all displays were selected, newly connected "
    L"displays join the selection. Different values across selected displays are indicated by indeterminate "
    L"checkboxes and dotted radio buttons, slider thumbs and buttons for enabling or disabling all options. "
    L"Slider labels show a dash instead of a shared value. Changing an option or clicking a slider applies "
    L"that value to all selected displays.\r\n\r\nCONTROLS\r\nEnable or disable animation outputs using the "
    L"display checkboxes or by double-clicking their rows. Each display uses an independent scene. Snapshot "
    L"saves PNG and the recording button starts or stops MP4. Pause stops the animation. The application "
    L"also installs or uninstalls its embedded screen saver. Settings are saved continuously. Only one "
    L"instance of the application runs at a time. Launching it again restores its minimised control window "
    L"and brings it to the foreground. Use Tab and Shift+Tab to move between controls; use Alt and the "
    L"underlined letter to activate a command. Esc closes the active Help or About window; in the control "
    L"window, it exits the application. Pause and screen-saver blocking apply to the whole application, "
    L"regardless of display selection. When blocking is enabled, the Windows screen saver is prevented only "
    L"while unpaused animation is visible on at least one display.\r\n\r\nSNAPSHOTS AND "
    L"RECORDING\r\nSnapshots and recordings capture the first active animation display, not a combined "
    L"image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if those "
    L"folders do not exist. The Recording settings button selects Viewport or TV. Viewport preserves the "
    L"animation display’s dimensions and refresh rate, up to 60 frames per second. TV offers 1920 × 1080, "
    L"1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 (60000/1001) or 29.97 (30000/1001) "
    L"frames per second. The image keeps its aspect ratio; TV uses progressive BT.709 limited-range 4:2:0 "
    L"video. Resolution and frame rate are available only in TV mode. The Recording settings window can be "
    L"minimised and does not block the other application windows. OK saves choices for the next MP4 "
    L"recording; Cancel or Esc discards unconfirmed changes. The recorded display cannot be detached during "
    L"recording; changes to other displays do not stop the recording. Closing the application while "
    L"recording requires confirmation because it also stops the recording.\r\n\r\nSYSTEM "
    L"REQUIREMENTS\r\nWindows 7 through Windows 11 support all features, including PNG snapshots and MP4 "
    L"recording. To run the application on Windows Vista SP2, you must install updates KB971512 and "
    L"KB2117917. MP4 recording does not work on Vista in the current version. Rendering requires Direct3D "
    L"11, not just an older DirectX runtime. MP4 recording requires available Media Foundation components "
    L"and an H.264 encoder.",
    L"ANIMATION AND SETTINGS\r\nFlightCorridor: Flight between four morphing surfaces; Flight through a "
    L"morphing funnel. Assign exactly one animation to each display. Texture switches between textured "
    L"surfaces and wireframe. Free camera rotation slowly changes the viewing direction in all three "
    L"dimensions. The Pauses and reversals option adds randomised braking, pauses and reversals of the "
    L"rotation; forward flight continues. Animation speed ranges from 0–1600%. Every display has an "
    L"independent randomised scene rendered at its own refresh rate. Main light, fill light, ambient light "
    L"and rim light can be switched independently for the selected displays. Lighting applies only to "
    L"textured surfaces.\r\n\r\nDISPLAYS\r\nRow selection determines which displays you are editing; it is "
    L"separate from the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and "
    L"Shift adjust the selection. All animation options and sliders apply to the selected displays. The "
    L"selection is remembered separately for EXE and SCR. If all displays were selected, newly connected "
    L"displays join the selection. Different values across selected displays are indicated by indeterminate "
    L"checkboxes and dotted radio buttons, slider thumbs and buttons for enabling or disabling all options. "
    L"Slider labels show a dash instead of a shared value. Changing an option or clicking a slider applies "
    L"that value to all selected displays.\r\n\r\nCONTROLS\r\nEnable or disable animation outputs using the "
    L"display checkboxes or by double-clicking their rows. Each display uses an independent scene. Snapshot "
    L"saves PNG and the recording button starts or stops MP4. Pause stops the animation. The application "
    L"also installs or uninstalls its embedded screen saver. Settings are saved continuously. Only one "
    L"instance of the application runs at a time. Launching it again restores its minimised control window "
    L"and brings it to the foreground. Use Tab and Shift+Tab to move between controls; use Alt and the "
    L"underlined letter to activate a command. Esc closes the active Help or About window; in the control "
    L"window, it exits the application. Pause and screen-saver blocking apply to the whole application, "
    L"regardless of display selection. When blocking is enabled, the Windows screen saver is prevented only "
    L"while unpaused animation is visible on at least one display.\r\n\r\nSNAPSHOTS AND "
    L"RECORDING\r\nSnapshots and recordings capture the first active animation display, not a combined "
    L"image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if those "
    L"folders do not exist. The Recording settings button selects Viewport or TV. Viewport preserves the "
    L"animation display’s dimensions and refresh rate, up to 60 frames per second. TV offers 1920 × 1080, "
    L"1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 (60000/1001) or 29.97 (30000/1001) "
    L"frames per second. The image keeps its aspect ratio; TV uses progressive BT.709 limited-range 4:2:0 "
    L"video. Resolution and frame rate are available only in TV mode. The Recording settings window can be "
    L"minimised and does not block the other application windows. OK saves choices for the next MP4 "
    L"recording; Cancel or Esc discards unconfirmed changes. The recorded display cannot be detached during "
    L"recording; changes to other displays do not stop the recording. Closing the application while "
    L"recording requires confirmation because it also stops the recording.\r\n\r\nSYSTEM "
    L"REQUIREMENTS\r\nWindows 7 through Windows 11 support all features, including PNG snapshots and MP4 "
    L"recording. To run the application on Windows Vista SP2, you must install updates KB971512 and "
    L"KB2117917. MP4 recording does not work on Vista in the current version. Rendering requires Direct3D "
    L"11, not just an older DirectX runtime. MP4 recording requires available Media Foundation components "
    L"and an H.264 encoder.",
    L"ANIMATION UND EINSTELLUNGEN\r\nFlightCorridor: Flug zwischen vier veränderlichen Flächen; Flug durch "
    L"einen veränderlichen Trichter. Weisen Sie jedem Monitor genau eine Animation zu. Textur wechselt "
    L"zwischen texturierten Flächen und Drahtgittermodell. Die freie Kameradrehung verändert die "
    L"Blickrichtung langsam in allen drei Dimensionen. Die Option „Pausen und Umkehr“ ergänzt zufälliges "
    L"Abbremsen, Pausen und Wechsel der Drehrichtung; der Vorwärtsflug läuft weiter. Die "
    L"Animationsgeschwindigkeit beträgt 0–1600 %. Jeder Monitor besitzt eine unabhängige zufällige Szene "
    L"und wird mit seiner eigenen Bildwiederholrate angesteuert. Hauptlicht, Fülllicht, Umgebungslicht und "
    L"Konturlicht lassen sich für die ausgewählten Monitore unabhängig schalten. Die Beleuchtung gilt nur "
    L"für texturierte Flächen.\r\n\r\nMONITORE\r\nDie Zeilenauswahl bestimmt, welche Monitore Sie "
    L"bearbeiten; sie ist von den Kontrollkästchen zum Einschalten der Animationsausgabe getrennt. Strg+A "
    L"wählt alle Monitore, Strg und Umschalt ändern die Auswahl. Alle Animationsoptionen und Regler gelten "
    L"für die ausgewählten Monitore. Die Auswahl wird für EXE und SCR getrennt gespeichert. Waren alle "
    L"Monitore ausgewählt, werden auch neu angeschlossene ausgewählt. Unterschiedliche Werte der "
    L"ausgewählten Monitore werden durch unbestimmte Kontrollkästchen und gepunktete Optionsfelder, "
    L"Reglergriffe sowie Schaltflächen zum Ein- oder Ausschalten aller Optionen angezeigt. "
    L"Reglerbeschriftungen zeigen statt eines gemeinsamen Werts einen Gedankenstrich. Das Ändern einer "
    L"Option oder Anklicken eines Reglers übernimmt diesen Wert für alle ausgewählten "
    L"Monitore.\r\n\r\nBEDIENUNG\r\nDie Animationsausgabe schalten Sie mit den Kontrollkästchen der "
    L"Monitore oder per Doppelklick auf deren Zeilen ein oder aus. Jeder Monitor besitzt eine unabhängige "
    L"Szene. Schnappschuss speichert PNG, die Aufnahmetaste startet oder beendet MP4. Pause hält die "
    L"Animation an. Die Anwendung installiert oder deinstalliert außerdem den eingebetteten "
    L"Bildschirmschoner. Einstellungen werden laufend gespeichert. Die Anwendung läuft nur in einer "
    L"Instanz. Ein erneuter Start stellt das minimierte Steuerfenster wieder her und bringt es in den "
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
    L"ANIMATION ET PARAMÈTRES\r\nFlightCorridor: Vol entre quatre surfaces déformables; Vol dans un "
    L"entonnoir déformable. Attribuez une seule animation à chaque écran. Texture alterne entre surfaces "
    L"texturées et modèle filaire. La rotation libre de la caméra change lentement la direction du regard "
    L"dans les trois dimensions. L’option « Pauses et inversions » ajoute des ralentissements, pauses et "
    L"inversions aléatoires de la rotation ; le vol vers l’avant continue. La vitesse va de 0 à 1600 %. "
    L"Chaque écran possède une scène aléatoire indépendante, rendue à sa propre fréquence de "
    L"rafraîchissement. La lumière principale, la lumière d’appoint, l’éclairage ambiant et l’éclairage des "
    L"contours se règlent indépendamment pour les écrans sélectionnés. L’éclairage ne concerne que les "
    L"surfaces texturées.\r\n\r\nÉCRANS\r\nLa sélection des lignes détermine les écrans à configurer ; elle "
    L"est distincte des cases qui activent les sorties d’animation. Ctrl+A sélectionne tous les écrans ; "
    L"Ctrl et Maj modifient la sélection. Toutes les options et tous les curseurs d’animation concernent "
    L"les écrans sélectionnés. La sélection est mémorisée séparément pour EXE et SCR. Si tous les écrans "
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
    L"ANIMACIÓN Y AJUSTES\r\nFlightCorridor: Vuelo entre cuatro superficies deformables; Vuelo por un "
    L"embudo deformable. Asigne una sola animación a cada pantalla. Textura alterna entre superficies "
    L"texturizadas y modelo de alambre. El giro libre de la cámara cambia lentamente la dirección de la "
    L"vista en las tres dimensiones. La opción «Pausas e inversiones» añade frenadas, pausas e inversiones "
    L"aleatorias del giro; el vuelo hacia delante continúa. La velocidad va del 0 al 1600 %. Cada pantalla "
    L"tiene una escena aleatoria independiente y se renderiza a su propia frecuencia de actualización. La "
    L"luz principal, la luz de relleno, la luz ambiental y la iluminación de contornos se activan por "
    L"separado para las pantallas seleccionadas. La iluminación solo se aplica a las superficies "
    L"texturizadas.\r\n\r\nMONITORES\r\nLa selección de filas determina qué pantallas se están "
    L"configurando; es independiente de las casillas que activan las salidas de animación. Ctrl+A "
    L"selecciona todas; Ctrl y Mayús modifican la selección. Todas las opciones y los controles deslizantes "
    L"de animación se aplican a las pantallas seleccionadas. La selección se recuerda por separado para EXE "
    L"y SCR. Si estaban seleccionadas todas, se incluyen también las nuevas. Los valores distintos entre "
    L"las pantallas seleccionadas se indican mediante casillas indeterminadas y un punteado en los botones "
    L"de opción, los tiradores de los controles deslizantes y los botones para activar o desactivar todas "
    L"las opciones. Las etiquetas de los controles deslizantes muestran una raya en lugar de un valor "
    L"común. Cambiar una opción o hacer clic en un control deslizante aplica ese valor a todas las "
    L"pantallas seleccionadas.\r\n\r\nCONTROLES\r\nActive o desactive las salidas de animación mediante las "
    L"casillas de las pantallas o haciendo doble clic en sus filas. Cada monitor usa una escena "
    L"independiente. Captura guarda un PNG y el botón de grabación inicia o detiene un MP4. Pausar detiene "
    L"la animación. La aplicación instala o desinstala además el salvapantallas incorporado. Los ajustes se "
    L"guardan continuamente. La aplicación solo permite una instancia. Al volver a iniciarla, restaura la "
    L"ventana de control minimizada y la trae al primer plano. Use Tab y Mayús+Tab para desplazarse entre "
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
    L"ANIMAZIONE E IMPOSTAZIONI\r\nFlightCorridor: Volo tra quattro superfici deformabili; Volo attraverso "
    L"un imbuto deformabile. Assegnare una sola animazione a ogni schermo. Texture alterna superfici con "
    L"texture e modello a reticolo. La rotazione libera della telecamera cambia lentamente la direzione "
    L"dello sguardo nelle tre dimensioni. L’opzione «Pause e inversioni» aggiunge rallentamenti, pause e "
    L"inversioni casuali della rotazione; il volo in avanti continua. La velocità va da 0 a 1600%. Ogni "
    L"schermo ha una scena casuale indipendente, renderizzata alla propria frequenza di aggiornamento. La "
    L"luce principale, la luce di riempimento, la luce ambientale e l’illuminazione dei contorni si "
    L"attivano separatamente per gli schermi selezionati. L’illuminazione si applica solo alle superfici "
    L"con texture.\r\n\r\nMONITOR\r\nLa selezione delle righe determina quali schermi si stanno "
    L"configurando ed è distinta dalle caselle che attivano le uscite di animazione. Ctrl+A seleziona tutti "
    L"gli schermi; Ctrl e Maiusc modificano la selezione. Tutte le opzioni e i cursori dell’animazione "
    L"riguardano gli schermi selezionati. La selezione viene memorizzata separatamente per EXE e SCR. Se "
    L"erano selezionati tutti gli schermi, vengono inclusi anche quelli nuovi. Valori diversi tra gli "
    L"schermi selezionati sono indicati da caselle di controllo indeterminate e da una trama a punti sui "
    L"pulsanti di opzione, sulle maniglie dei cursori e sui pulsanti per attivare o disattivare tutte le "
    L"opzioni. Le etichette dei cursori mostrano un trattino al posto di un valore comune. Modificare "
    L"un’opzione o fare clic su un cursore applica quel valore a tutti gli schermi "
    L"selezionati.\r\n\r\nCOMANDI\r\nAttivate o disattivate le uscite di animazione con le caselle degli "
    L"schermi o facendo doppio clic sulle rispettive righe. Ogni monitor usa una scena indipendente. "
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
    L"ANIMAÇÃO E DEFINIÇÕES\r\nFlightCorridor: Voo entre quatro superfícies deformáveis; Voo através de um "
    L"funil deformável. Atribua uma única animação a cada ecrã. Textura alterna entre superfícies "
    L"texturadas e modelo em arame. A rotação livre da câmara muda lentamente a direção da vista nas três "
    L"dimensões. A opção «Pausas e inversões» acrescenta desacelerações, pausas e inversões aleatórias da "
    L"rotação; o voo para a frente continua. A velocidade vai de 0 a 1600%. Cada ecrã tem uma cena "
    L"aleatória independente, apresentada à sua própria frequência de atualização. A luz principal, a luz "
    L"de preenchimento, a luz ambiente e a iluminação dos contornos podem ser ativadas separadamente nos "
    L"monitores selecionados. A iluminação aplica-se apenas às superfícies com "
    L"textura.\r\n\r\nMONITORES\r\nA seleção das linhas determina os ecrãs a configurar e é independente "
    L"das caixas que ativam as saídas de animação. Ctrl+A seleciona todos os ecrãs; Ctrl e Shift alteram a "
    L"seleção. Todas as opções e controlos deslizantes da animação aplicam-se aos ecrãs selecionados. A "
    L"seleção é guardada separadamente para EXE e SCR. Se todos estavam selecionados, os novos ecrãs também "
    L"são incluídos. Valores diferentes entre os ecrãs selecionados são indicados por caixas de verificação "
    L"indeterminadas e por um padrão pontilhado nos botões de opção, nas pegas dos controlos deslizantes e "
    L"nos botões para ativar ou desativar todas as opções. As etiquetas dos controlos deslizantes "
    L"apresentam um travessão em vez de um valor comum. Alterar uma opção ou clicar num controlo deslizante "
    L"aplica esse valor a todos os ecrãs selecionados.\r\n\r\nCONTROLOS\r\nAtive ou desative as saídas de "
    L"animação através das caixas dos ecrãs ou com um duplo clique nas respetivas linhas. Cada monitor usa "
    L"uma cena independente. Captura guarda PNG e o botão de gravação inicia ou termina MP4. Pausa para a "
    L"animação. A aplicação também instala ou desinstala a proteção de ecrã incorporada. As definições são "
    L"guardadas continuamente. A aplicação só pode ter uma instância em execução. Um novo arranque restaura "
    L"a janela de controlo minimizada e coloca-a em primeiro plano. Use Tab e Shift+Tab para passar entre "
    L"controlos; Alt e a letra sublinhada ativam um comando. Esc fecha a janela ativa de Ajuda ou Acerca "
    L"de; na janela de controlo, termina a aplicação. A pausa e o bloqueio da proteção de ecrã aplicam-se a "
    L"toda a aplicação, independentemente dos ecrãs selecionados. Com o bloqueio ativo, a proteção de ecrã "
    L"do Windows só é impedida enquanto existir animação visível e não pausada em pelo menos um "
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
    L"ANIMACJA I USTAWIENIA\r\nFlightCorridor: Przelot między czterema zmiennymi powierzchniami; Przelot "
    L"przez zmienny lejek. Każdemu monitorowi przypisz dokładnie jedną animację. Tekstura przełącza "
    L"powierzchnie z teksturą i model szkieletowy. Swobodne obracanie kamery powoli zmienia kierunek widoku "
    L"we wszystkich trzech wymiarach. Przerwy i nawroty dodają losowe zwalnianie, pauzy i odwracanie "
    L"obrotu; lot do przodu trwa nadal. Prędkość wynosi 0–1600%. Każdy monitor ma niezależną losową scenę "
    L"wyświetlaną z własną częstotliwością odświeżania. Światło główne, światło wypełniające, światło "
    L"otoczenia i oświetlenie konturów można przełączać niezależnie dla zaznaczonych monitorów. Oświetlenie "
    L"dotyczy tylko powierzchni z teksturą.\r\n\r\nMONITORY\r\nZaznaczenie wierszy określa konfigurowane "
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
    L"ANIMÁCIA A NASTAVENIA\r\nFlightCorridor: Prelet štyrmi premenlivými plochami; Prelet premenlivým "
    L"lievikom. Každému monitoru priraďte práve jednu animáciu. Textúra prepína medzi textúrovanými "
    L"plochami a drôteným modelom. Voľná rotácia kamery pomaly mení smer pohľadu vo všetkých troch "
    L"rozmeroch. Voľba „Pauzy a obraty“ pridáva náhodné spomaľovanie, prestávky a zmeny smeru otáčania; "
    L"dopredný pohyb pokračuje. Rýchlosť je 0–1600 %. Každý monitor má nezávislú náhodnú scénu vykresľovanú "
    L"podľa vlastnej obnovovacej frekvencie. Hlavné svetlo, doplnkové svetlo, základný jas a prisvetlenie "
    L"obrysov možno pre označené monitory zapínať nezávisle. Osvetlenie sa používa len pri textúrovaných "
    L"plochách.\r\n\r\nMONITORY\r\nOznačenie riadkov určuje, ktoré monitory práve nastavujete; je nezávislé "
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
    L"ANIMATION OG INDSTILLINGER\r\nFlightCorridor: Flyvetur mellem fire formskiftende flader; Flyvetur "
    L"gennem en formskiftende tragt. Tildel præcis én animation til hver skærm. Tekstur skifter mellem "
    L"teksturerede flader og trådmodel. Frit roterende kamera ændrer langsomt synsretningen i alle tre "
    L"dimensioner. Pauser og vendinger tilføjer tilfældige opbremsninger, pauser og ændringer af "
    L"rotationsretningen; flyvningen fremad fortsætter. Hastigheden er 0–1600 %. Hver skærm har en "
    L"uafhængig tilfældig scene, der gengives med dens egen opdateringsfrekvens. Hovedlys, udfyldningslys, "
    L"omgivende lys og konturlys kan slås til og fra uafhængigt for de valgte skærme. Belysningen gælder "
    L"kun teksturerede overflader.\r\n\r\nSKÆRME\r\nMarkeringen af rækker bestemmer, hvilke skærme du "
    L"indstiller, og er adskilt fra afkrydsningsfelterne, der aktiverer animationsoutput. Ctrl+A markerer "
    L"alle skærme; Ctrl og Skift ændrer markeringen. Alle animationsvalg og skydere gælder de markerede "
    L"skærme. Markeringen huskes separat for EXE og SCR. Hvis alle skærme var markeret, medtages også nye "
    L"skærme. Forskellige værdier på de markerede skærme vises med ubestemte afkrydsningsfelter og "
    L"prikmønstre på alternativknapper, skydergreb og knapper til at slå alle valg til eller fra. Skydernes "
    L"etiketter viser en tankestreg i stedet for en fælles værdi. Ændring af et valg eller klik på en "
    L"skyder anvender denne værdi på alle markerede skærme.\r\n\r\nBETJENING\r\nSlå animationsoutput til "
    L"eller fra med skærmenes afkrydsningsfelter eller ved at dobbeltklikke på deres rækker. Hver skærm "
    L"bruger en uafhængig scene. Skærmbillede gemmer PNG, og optageknappen starter eller stopper MP4. Pause "
    L"standser animationen. Programmet installerer eller afinstallerer også den indbyggede pauseskærm. "
    L"Indstillinger gemmes løbende. Programmet kan kun køre i én instans ad gangen. En ny start gendanner "
    L"det minimerede kontrolvindue og bringer det forrest. Brug Tab og Skift+Tab til at flytte mellem "
    L"kontrollerne; Alt og det understregede bogstav aktiverer en kommando. Esc lukker det aktive Hjælp- "
    L"eller Om-vindue; i kontrolvinduet afslutter det programmet. Pause og blokering af pauseskærmen gælder "
    L"hele programmet uanset skærmmarkeringen. Når blokering er slået til, forhindres Windows-pauseskærmen "
    L"kun, mens der vises en synlig animation, som ikke er sat på pause, på mindst én "
    L"skærm.\r\n\r\nSKÆRMBILLEDER OG OPTAGELSE\r\nSkærmbilleder og optagelser bruger den første aktive "
    L"animationsskærm, ikke et samlet billede af alle skærme. PNG bruger Billeder, MP4 Videoer; hvis disse "
    L"mapper ikke findes, bruges Dokumenter. Knappen Optagelsesindstillinger vælger Viewport eller TV. "
    L"Viewport bevarer animationsskærmens størrelse og opdateringsfrekvens, højst 60 billeder i sekundet. "
    L"TV tilbyder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9 med 50, 25, 59.94 (60000/1001) "
    L"eller 29.97 (30000/1001) billeder i sekundet. Billedets proportioner bevares; TV bruger progressiv "
    L"BT.709-video med begrænset område og 4:2:0-sampling. Opløsning og billedfrekvens kan kun vælges i "
    L"TV-tilstand. Vinduet Optagelsesindstillinger kan minimeres og blokerer ikke de andre programvinduer. "
    L"OK gemmer valgene til den næste MP4-optagelse; Annuller eller Esc kasserer ubekræftede ændringer. Den "
    L"skærm, der optages, kan ikke fravælges under optagelsen; ændringer af andre skærme stopper ikke "
    L"optagelsen. Hvis programmet lukkes under en optagelse, kræves en bekræftelse, fordi optagelsen også "
    L"afsluttes.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 understøtter alle funktioner, herunder "
    L"PNG-skærmbilleder og MP4-optagelse. For at køre programmet på Windows Vista SP2 skal opdateringerne "
    L"KB971512 og KB2117917 installeres. MP4-optagelse fungerer ikke på Vista i den aktuelle version. "
    L"Visningen kræver Direct3D 11, ikke kun et ældre DirectX-kørselsmiljø. MP4-optagelse kræver "
    L"tilgængelige Media Foundation-komponenter og en H.264-koder.",
    L"ANIMAATIO JA ASETUKSET\r\nFlightCorridor: Lento neljän muuntuvan pinnan välissä; Lento muuntuvan "
    L"suppilon läpi. Valitse kullekin näytölle yksi animaatio. Tekstuuri vaihtaa teksturoitujen pintojen ja "
    L"rautalankamallin välillä. Kameran vapaa pyörintä muuttaa katselusuuntaa hitaasti kaikissa kolmessa "
    L"ulottuvuudessa. Tauot ja suunnanvaihdot lisäävät satunnaisia hidastuksia, taukoja ja pyörimissuunnan "
    L"vaihtoja; lento eteenpäin jatkuu. Nopeus on 0–1600%. Jokaisella näytöllä on itsenäinen satunnainen "
    L"näkymä, joka piirretään sen omalla virkistystaajuudella. Päävalo, täytevalo, ympäristövalo ja "
    L"reunavalo voidaan kytkeä erikseen valituille näytöille. Valaistus koskee vain teksturoituja "
    L"pintoja.\r\n\r\nNÄYTÖT\r\nRivien valinta määrää muokattavat näytöt ja on erillinen animaatioulostulon "
    L"valintaruuduista. Ctrl+A valitsee kaikki näytöt; Ctrl ja Vaihto muuttavat valintaa. Kaikki "
    L"animaatioasetukset ja liukusäätimet koskevat valittuja näyttöjä. Valinta muistetaan erikseen EXE- ja "
    L"SCR-tiloissa. Jos kaikki näytöt olivat valittuina, myös uudet näytöt valitaan. Valittujen näyttöjen "
    L"eri arvot ilmaistaan valintaruutujen määrittämättömällä tilalla sekä valintanappien, liukusäätimien "
    L"kahvojen ja kaikkien asetusten kytkentäpainikkeiden pistekuviolla. Liukusäätimen selitteessä näkyy "
    L"viiva yhteisen arvon sijasta. Asetuksen muuttaminen tai liukusäätimen napsauttaminen asettaa kyseisen "
    L"arvon kaikille valituille näytöille.\r\n\r\nKÄYTTÖ\r\nAnimaatioulostulot voi ottaa käyttöön tai "
    L"poistaa käytöstä näyttöjen valintaruuduilla tai kaksoisnapsauttamalla niiden rivejä. Jokaisella "
    L"näytöllä on itsenäinen näkymä. Tilannekuva tallentaa PNG:n ja tallennuspainike käynnistää tai "
    L"lopettaa MP4:n. Keskeytä pysäyttää animaation. Sovellus asentaa tai poistaa myös sisäisen "
    L"näytönsäästäjän. Asetukset tallennetaan jatkuvasti. Sovelluksesta voi olla käynnissä vain yksi "
    L"instanssi. Uusi käynnistys palauttaa pienennetyn ohjausikkunan ja tuo sen etualalle. Siirry säätimien "
    L"välillä Tab- ja Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat komennon. Esc sulkee "
    L"aktiivisen Ohje- tai Tietoja-ikkunan; ohjausikkunassa se sulkee sovelluksen. Keskeytys ja "
    L"näytönsäästäjän esto koskevat koko sovellusta näytön valinnasta riippumatta. Kun esto on käytössä, "
    L"Windowsin näytönsäästäjä estetään vain, kun vähintään yhdessä näytössä näkyy animaatio, jota ei ole "
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
    L"HREYFIMYND OG STILLINGAR\r\nFlightCorridor: Flug milli fjögurra breytilegra flata; Flug í gegnum "
    L"breytilega trekt. Veldu nákvæmlega eina hreyfimynd fyrir hvern skjá. Áferð skiptir milli "
    L"áferðarlagðra flata og víragrindar. Frjáls snúningur myndavélar breytir sjónstefnunni hægt í öllum "
    L"þremur víddum. Valkosturinn „Hlé og stefnuskipti“ bætir við tilviljanakenndri hægingu, hléum og "
    L"breytingum á snúningsstefnu; flug áfram heldur áfram. Hraðinn er 0–1600%. Hver skjár hefur sjálfstæða "
    L"tilviljanakennda senu sem er teiknuð á eigin endurnýjunartíðni. Aðalljós, fylliljós, umhverfislýsing "
    L"og útlínulýsing eru stillt óháð hvert öðru fyrir valda skjái. Lýsingin á aðeins við um "
    L"áferðarfleti.\r\n\r\nSKJÁIR\r\nVal lína ákvarðar hvaða skjám er verið að breyta og er óháð "
    L"gátreitunum sem kveikja á hreyfimyndaúttaki. Ctrl+A velur alla skjái; Ctrl og Shift breyta valinu. "
    L"Allir valkostir og sleðar hreyfimynda gilda fyrir valda skjái. Valið er munað sérstaklega fyrir EXE "
    L"og SCR. Ef allir skjáir voru valdir bætast nýir skjáir einnig við valið. Mismunandi gildi á völdum "
    L"skjám eru sýnd með óákveðnu ástandi gátreita og punktamynstri á valhnöppum, handföngum sleða og "
    L"hnöppum sem kveikja eða slökkva á öllum valkostum. Merking sleða sýnir strik í stað sameiginlegs "
    L"gildis. Að breyta valkosti eða smella á sleða setur það gildi á alla valda "
    L"skjái.\r\n\r\nNOTKUN\r\nKveiktu eða slökktu á hreyfimyndaúttaki með gátreitum skjáanna eða með því að "
    L"tvísmella á línur þeirra. Hver skjár notar sjálfstæða senu. Skjámynd vistar PNG og upptökuhnappurinn "
    L"ræsir eða stöðvar MP4. Hnappurinn Gera hlé stöðvar hreyfimyndina. Forritið setur einnig upp eða "
    L"fjarlægir innbyggðu skjáhvíluna. Stillingar vistast jafnóðum. Aðeins eitt eintak af forritinu getur "
    L"verið í gangi í einu. Ný ræsing endurheimtir lágmarkaðan stjórngluggann og færir hann fremst. Notaðu "
    L"Tab og Shift+Tab til að færa þig milli stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc "
    L"lokar virka Hjálp- eða Um-glugganum; í stjórnglugganum lokar það forritinu. Pása og hindrun skjáhvílu "
    L"gilda fyrir allt forritið, óháð völdum skjám. Þegar hindrun er virk er skjáhvíla Windows aðeins "
    L"hindruð meðan sýnileg hreyfimynd sem er ekki í pásu er á að minnsta kosti einum "
    L"skjá.\r\n\r\nSKJÁMYNDIR OG UPPTAKA\r\nSkjámyndir og upptökur nota fyrsta virka hreyfimyndaskjáinn, "
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
    L"upptökuna.\r\n\r\nKERFISKRÖFUR\r\nWindows 7 til Windows 11 styðja alla eiginleika, þar á meðal "
    L"PNG-skjámyndir og MP4-upptöku. Til að keyra forritið á Windows Vista SP2 þarf að setja upp "
    L"uppfærslurnar KB971512 og KB2117917. MP4-upptaka virkar ekki í Vista í núverandi útgáfu. Birting "
    L"krefst Direct3D 11, ekki aðeins eldri DirectX-keyrsluumhverfis. MP4-upptaka krefst tiltækra Media "
    L"Foundation-íhluta og H.264-kóðara.",
    L"ANIMASJON OG INNSTILLINGER\r\nFlightCorridor: Flytur mellom fire formendrende flater; Flytur gjennom "
    L"en formendrende trakt. Tilordne nøyaktig én animasjon til hver skjerm. Tekstur veksler mellom "
    L"teksturerte flater og trådmodell. Fritt roterende kamera endrer synsretningen langsomt i alle tre "
    L"dimensjoner. Pauser og vendinger legger til tilfeldige oppbremsinger, pauser og endringer i "
    L"rotasjonsretningen; flyvningen fremover fortsetter. Hastigheten er 0–1600 %. Hver skjerm har en "
    L"uavhengig tilfeldig scene som gjengis ved dens egen oppdateringsfrekvens. Hovedlys, utfyllingslys, "
    L"omgivelseslys og konturlys kan slås av og på uavhengig for de valgte skjermene. Belysningen gjelder "
    L"bare teksturerte flater.\r\n\r\nSKJERMER\r\nMarkeringen av rader bestemmer hvilke skjermer du "
    L"redigerer, og er atskilt fra avkrysningsboksene som aktiverer animasjonsutgangen. Ctrl+A markerer "
    L"alle skjermer; Ctrl og Skift endrer markeringen. Alle animasjonsvalg og glidebrytere gjelder de "
    L"markerte skjermene. Markeringen huskes separat for EXE og SCR. Hvis alle skjermer var markert, "
    L"inkluderes også nye skjermer. Ulike verdier på de markerte skjermene vises med ubestemte "
    L"avkrysningsbokser og prikkmønster på alternativknapper, glidebryterhåndtak og knapper for å slå alle "
    L"valg av eller på. Glidebryteretiketter viser en tankestrek i stedet for en felles verdi. Endring av "
    L"et valg eller klikk på en glidebryter bruker denne verdien på alle markerte "
    L"skjermer.\r\n\r\nBETJENING\r\nSlå animasjonsutgangene av eller på med skjermenes avkrysningsbokser "
    L"eller ved å dobbeltklikke på radene deres. Hver skjerm bruker en uavhengig scene. Skjermbilde lagrer "
    L"PNG, og opptaksknappen starter eller stopper MP4. Pause stanser animasjonen. Programmet installerer "
    L"eller avinstallerer også den innebygde skjermspareren. Innstillingene lagres fortløpende. Bare én "
    L"instans av programmet kan kjøre om gangen. En ny start gjenoppretter det minimerte kontrollvinduet og "
    L"bringer det fremst. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede "
    L"bokstaven aktiverer en kommando. Esc lukker det aktive Hjelp- eller Om-vinduet; i kontrollvinduet "
    L"avslutter det programmet. Pause og blokkering av skjermspareren gjelder hele programmet uavhengig av "
    L"skjermmarkeringen. Når blokkering er slått på, hindres Windows-skjermspareren bare mens en synlig "
    L"animasjon som ikke er satt på pause, vises på minst én skjerm.\r\n\r\nSKJERMBILDER OG "
    L"OPPTAK\r\nSkjermbilder og opptak bruker den første aktive animasjonsskjermen, ikke et samlet bilde av "
    L"alle skjermene. PNG bruker Bilder, MP4 Videoer; hvis disse mappene ikke finnes, brukes Dokumenter. "
    L"Knappen Opptaksinnstillinger velger Viewport eller TV. Viewport beholder animasjonsskjermens "
    L"størrelse og oppdateringsfrekvens, opptil 60 bilder per sekund. TV tilbyr 1920 × 1080, 1440 × 1080 "
    L"eller 1280 × 720 i formatet 16:9, med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) bilder per "
    L"sekund. Bildets proporsjoner beholdes; TV bruker progressiv BT.709-video med begrenset område og "
    L"4:2:0-sampling. Oppløsning og bildefrekvens er bare tilgjengelige i TV-modus. Vinduet "
    L"Opptaksinnstillinger kan minimeres og blokkerer ikke de andre programvinduene. OK lagrer valgene for "
    L"neste MP4-opptak; Avbryt eller Esc forkaster ubekreftede endringer. Skjermen som tas opp, kan ikke "
    L"velges bort under opptaket; endringer på andre skjermer stopper ikke opptaket. Å avslutte programmet "
    L"under et opptak krever bekreftelse, fordi det også avslutter opptaket.\r\n\r\nSYSTEMKRAV\r\nWindows 7 "
    L"til Windows 11 støtter alle funksjoner, inkludert PNG-skjermbilder og MP4-opptak. For å kjøre "
    L"programmet på Windows Vista SP2 må oppdateringene KB971512 og KB2117917 installeres. MP4-opptak "
    L"fungerer ikke på Vista i den gjeldende versjonen. Visningen krever Direct3D 11, ikke bare en eldre "
    L"DirectX-kjøretid. MP4-opptak krever tilgjengelige Media Foundation-komponenter og en H.264-koder.",
    L"ANIMERING OCH INSTÄLLNINGAR\r\nFlightCorridor: Flygtur mellan fyra formföränderliga ytor; Flygtur "
    L"genom en formföränderlig tratt. Tilldela varje skärm exakt en animering. Textur växlar mellan "
    L"texturerade ytor och trådmodell. Fritt roterande kamera ändrar långsamt blickriktningen i alla tre "
    L"dimensioner. Pauser och vändningar lägger till slumpmässiga inbromsningar, pauser och byten av "
    L"rotationsriktning; flygningen framåt fortsätter. Hastigheten är 0–1600 %. Varje skärm har en "
    L"oberoende slumpmässig scen som återges med dess egen uppdateringsfrekvens. Huvudljus, fyllnadsljus, "
    L"omgivningsljus och konturljus kan slås på och av oberoende för de valda skärmarna. Belysningen gäller "
    L"bara texturerade ytor.\r\n\r\nBILDSKÄRMAR\r\nMarkeringen av rader avgör vilka skärmar du redigerar "
    L"och är skild från kryssrutorna som aktiverar animationsutgångarna. Ctrl+A markerar alla skärmar; Ctrl "
    L"och Skift ändrar markeringen. Alla animationsalternativ och reglage gäller de markerade skärmarna. "
    L"Markeringen sparas separat för EXE och SCR. Om alla skärmar var markerade inkluderas även nya "
    L"skärmar. Olika värden på de markerade skärmarna visas med obestämda kryssrutor och punktmönster på "
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
    L"ANİMASYON VE AYARLAR\r\nFlightCorridor: Biçim değiştiren dört yüzey arasında uçuş; Biçim değiştiren "
    L"bir huninin içinden uçuş. Her ekrana tam bir animasyon atayın. Doku, dokulu yüzeyler ile tel kafes "
    L"modeli arasında geçiş yapar. Serbest kamera dönüşü bakış yönünü üç boyutta yavaşça değiştirir. "
    L"Duraklama ve ters dönüş, dönüşe rastgele yavaşlamalar, duraklamalar ve ters yön değişimleri ekler; "
    L"ileri uçuş devam eder. Hız 0–1600% aralığındadır. Her ekranın kendi yenileme hızında çizilen bağımsız "
    L"rastgele bir sahnesi vardır. Ana ışık, dolgu ışığı, ortam ışığı ve kenar aydınlatması seçili ekranlar "
    L"için ayrı ayrı açılıp kapatılabilir. Aydınlatma yalnızca dokulu yüzeylere "
    L"uygulanır.\r\n\r\nEKRANLAR\r\nSatır seçimi, hangi ekranların düzenlendiğini belirler; animasyon "
    L"çıkışlarını açan onay kutularından ayrıdır. Ctrl+A tüm ekranları seçer; Ctrl ve Shift seçimi "
    L"değiştirir. Tüm animasyon seçenekleri ve kaydırıcılar seçili ekranlara uygulanır. Seçim EXE ve SCR "
    L"için ayrı saklanır. Tüm ekranlar seçiliyse sonradan bağlanan ekranlar da seçime katılır. Seçili "
    L"ekranlardaki farklı değerler, belirsiz durumdaki onay kutuları ve seçenek düğmelerinde, kaydırıcı "
    L"tutamaçlarında ve tüm seçenekleri açıp kapatan düğmelerde noktalı desenle gösterilir. Kaydırıcı "
    L"etiketleri ortak bir değer yerine çizgi gösterir. Bir seçeneği değiştirmek veya kaydırıcıya tıklamak "
    L"bu değeri tüm seçili ekranlara uygular.\r\n\r\nKULLANIM\r\nAnimasyon çıkışlarını ekran onay "
    L"kutularıyla veya satırlarına çift tıklayarak açıp kapatabilirsiniz. Her monitör bağımsız sahne "
    L"kullanır. Anlık görüntü PNG kaydeder; kayıt düğmesi MP4 kaydını başlatır veya bitirir. Duraklat "
    L"animasyonu durdurur. Uygulama gömülü ekran koruyucuyu da kurar veya kaldırır. Ayarlar sürekli "
    L"kaydedilir. Uygulamanın aynı anda yalnızca bir örneği çalışabilir. Yeniden başlatılması, simge "
    L"durumuna küçültülmüş denetim penceresini geri yükler ve ön plana getirir. Denetimler arasında Tab ve "
    L"Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir komutu etkinleştirir. Esc, etkin Yardım veya "
    L"Hakkında penceresini kapatır; denetim penceresinde uygulamadan çıkar. Duraklatma ve ekran koruyucuyu "
    L"engelleme, ekran seçiminden bağımsız olarak uygulamanın tamamına uygulanır. Engelleme açıkken Windows "
    L"ekran koruyucusu yalnızca en az bir ekranda görünür ve duraklatılmamış animasyon varken "
    L"engellenir.\r\n\r\nEKRAN GÖRÜNTÜLERİ VE KAYIT\r\nAnlık görüntüler ve kayıtlar, tüm monitörlerin "
    L"birleşik görüntüsünü değil, ilk etkin animasyon monitörünü kullanır. PNG Resimler, MP4 Videolar "
    L"klasörünü kullanır; bu klasörler yoksa Belgeler kullanılır. Kayıt ayarları düğmesi Viewport veya TV "
    L"seçimini açar. Viewport, animasyon monitörünün boyutlarını ve yenileme hızını saniyede en fazla 60 "
    L"kareyle korur. TV, 16:9 oranında 1920 × 1080, 1440 × 1080 veya 1280 × 720 çözünürlük ile saniyede 50, "
    L"25, 59.94 (60000/1001) veya 29.97 (30000/1001) kare sunar. Görüntünün en boy oranı korunur; TV, "
    L"sınırlı aralıklı, 4:2:0 örneklemeli ilerlemeli BT.709 video kullanır. Çözünürlük ve kare hızı "
    L"yalnızca TV modunda seçilebilir. Kayıt ayarları penceresi simge durumuna küçültülebilir ve "
    L"uygulamanın diğer pencerelerini engellemez. Tamam, seçenekleri bir sonraki MP4 kaydı için kaydeder; "
    L"İptal veya Esc onaylanmamış değişiklikleri iptal eder. Kayıt sırasında kaydedilen ekranın seçimi "
    L"kaldırılamaz; diğer ekranlardaki değişiklikler kaydı durdurmaz. Kayıt sırasında uygulamayı kapatmak "
    L"kaydı da durduracağı için onay gerektirir.\r\n\r\nSİSTEM GEREKSİNİMLERİ\r\nWindows 7 ile Windows 11 "
    L"arasındaki sürümler, PNG anlık görüntüler ve MP4 kaydı dâhil tüm özellikleri destekler. Uygulamayı "
    L"Windows Vista SP2'de çalıştırmak için KB971512 ve KB2117917 güncellemelerini yüklemeniz gerekir. "
    L"Geçerli sürümde MP4 kaydı Vista'da çalışmaz. Görüntüleme, yalnızca eski bir DirectX çalışma zamanı "
    L"değil, Direct3D 11 gerektirir. MP4 kaydı, kullanılabilir Media Foundation bileşenleri ve bir H.264 "
    L"kodlayıcı gerektirir.",
    L"ANIMATSIOON JA SÄTTED\r\nRiistvarakiirendusega lend muutuvate pindade vahel. Lend nelja muutuva pinna "
    L"vahel; Lend läbi muutuva lehtri. Valige igale kuvarile täpselt üks animatsioon. Tekstuuri märkeruut "
    L"vahetab tekstuuriga pinna ja traatmudeli vahel. Kaamera vaba pöörlemine muudab vaatesuunda aeglaselt "
    L"kõigis kolmes mõõtmes. Pausid ja pöördumised lisavad sellele juhuslikke aeglustusi, pause ja "
    L"pöörlemissuuna muutusi; edasilend jätkub. Kiirus on seatav vahemikus 0–1600%. Igal kuvaril on oma "
    L"sõltumatu juhuslik stseen ja värskendussagedusele vastav renderdus. Põhivalgust, täitevalgust, "
    L"ümbritsevat valgust ja kontuurivalgust saab valitud kuvaritel eraldi sisse ja välja lülitada. "
    L"Valgustus kehtib ainult tekstuuriga pindadele.\r\n\r\nKUVARID\r\nValige loendis üks või mitu "
    L"kuvaririda. Ctrl+A valib kõik read; Ctrl ja Shift võimaldavad valikut muuta. Animatsiooni juhtnupud "
    L"ja liugurid mõjutavad ainult valitud kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle "
    L"märkeruuduga väljundi lubamine on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja jaoks "
    L"eraldi meelde. Kui varem olid valitud kõik kuvarid, kaasatakse ka lisatud kuvarid. Valitud kuvarite "
    L"erinevaid väärtusi näitavad märkeruutude määramata olek ning raadionuppude, liugurite käepidemete ja "
    L"kõigi valikute lülitusnuppude punktimuster. Liuguri sildil on ühise väärtuse asemel kriips. Valiku "
    L"muutmine või liuguril klõpsamine määrab selle väärtuse kõigile valitud "
    L"kuvaritele.\r\n\r\nKASUTAMINE\r\nKäivitage FlightCorridor.exe. Sätteid salvestatakse jooksvalt ning "
    L"rakendus töötab ühe eksemplarina. Kuvari märkeruut või topeltklõps real lülitab selle "
    L"animatsiooniväljundi sisse või välja. Animatsiooni saab peatada ja jätkata. PNG-pilt ja MP4-video "
    L"jäädvustavad esimese aktiivse animatsioonikuvari, mitte kõiki kuvareid koos. Salvestatavat kuvarit ei "
    L"saa salvestamise ajal välja lülitada; rakenduse sulgemine nõuab siis kinnitust. Peatamine ja "
    L"ekraanisäästja tõkestamine kehtivad kogu rakendusele, sõltumata kuvarite valikust. Kui tõkestamine on "
    L"sisse lülitatud, takistatakse Windowsi ekraanisäästjat ainult seni, kuni vähemalt ühel kuvaril on "
    L"nähtav peatamata animatsioon. Rakendus saab paigaldada ja eemaldada sisseehitatud "
    L"ekraanisäästja.\r\n\r\nKUVATÕMMISED JA SALVESTAMINE\r\nSalvestussätetes valige Viewport või TV. "
    L"Viewport säilitab kuvari mõõtmed ja värskendussageduse kuni 60 kaadrit sekundis. TV pakub 1920 × "
    L"1080, 1440 × 1080 või 1280 × 720 väljundit kuvasuhtega 16:9 ning 50, 25, 59.94 (60000/1001) või 29.97 "
    L"(30000/1001) kaadrit sekundis. TV-video on progressiivne BT.709, piiratud vahemikuga ja 4:2:0 "
    L"värvialamdiskreetimisega. Pildi kuvasuhe säilib ja täiteribad on mustad. OK rakendab valikud "
    L"järgmisele salvestusele; Loobu või Esc tühistab kinnitamata muudatused. Salvestussätted, spikker ja "
    L"teave ei blokeeri teisi aknaid ning neid saab minimeerida. Tab ja Shift+Tab liigutavad fookust, Enter "
    L"vajutab fookusega nuppu ning Esc sulgeb aktiivse lisaakna.\r\n\r\nSÜSTEEMINÕUDED\r\nWindows 7–11 "
    L"toetab kõiki funktsioone. Windows Vista SP2 jaoks tuleb paigaldada värskendused KB971512 ja "
    L"KB2117917; MP4 salvestamine Vistas ei tööta. Vaja on Direct3D 11 tuge ning MP4 jaoks Media "
    L"Foundationi ja H.264 kodeerijat. Liides ja dokumentatsioon on saadaval 36 keeles.",
    L"BEOCHAN AGUS SOCRUITHE\r\nEitilt idir dromchlaí athraitheacha le luasghéarú crua-earraí. Eitilt idir "
    L"ceithre dhromchla athraitheacha; Eitilt trí thonnadóir athraitheach. Roghnaigh beochan amháin do gach "
    L"monatóir. Athraíonn Uigeacht idir dromchla uigeachtaithe agus samhail sreangfhráma. Rothlaíonn rothlú "
    L"saor an cheamara an radharc go mall sna trí thoise. Cuireann Sosanna agus aisiompuithe coscánú, "
    L"sosanna agus athruithe treo randamacha leis an rothlú; leanann an eitilt chun tosaigh. Tá luas "
    L"0–1600% ar fáil. Tá radharc randamach neamhspleách ag gach monatóir agus déantar rindreáil de réir a "
    L"ráta athnuachana féin. Is féidir an príomhsholas, an solas líonta, an solas comhthimpeallach agus an "
    L"solas imill a athrú go neamhspleách do na taispeántais roghnaithe. Ní bhaineann an soilsiú ach le "
    L"dromchlaí uigeachtaithe.\r\n\r\nTAISPEÁNTAIS\r\nRoghnaigh ró amháin nó níos mó sa liosta monatóirí. "
    L"Roghnaíonn Ctrl+A gach ró; úsáid Ctrl agus Shift chun an roghnú a athrú. Ní athraíonn rialuithe agus "
    L"sleamhnáin na beochana ach socruithe na monatóirí roghnaithe. Ní hionann ró a roghnú agus aschur an "
    L"mhonatóra a chumasú lena bhosca seiceála. Cuimhnítear an roghnú ar leith don fheidhmchlár agus don "
    L"spárálaí. Má bhí gach monatóir roghnaithe, cuirtear monatóirí nua leis an roghnú freisin. Léirítear "
    L"luachanna éagsúla ar na monatóirí roghnaithe le boscaí seiceála i staid neamhchinnte agus le patrún "
    L"poncanna ar chnaipí raidió, ar ghreimíní sleamhnán agus ar na cnaipí a chumasaíonn nó a "
    L"dhíchumasaíonn gach rogha. Taispeántar dais ar lipéad an tsleamhnáin in ionad luach coiteann. Nuair a "
    L"athraítear rogha nó a chliceáiltear sleamhnán, cuirtear an luach sin i bhfeidhm ar gach monatóir "
    L"roghnaithe.\r\n\r\nRIALÚ\r\nRith FlightCorridor.exe. Sábháiltear socruithe go leanúnach agus ní "
    L"ritheann ach cóip amháin den fheidhmchlár. Cumasaíonn nó díchumasaíonn bosca seiceála an mhonatóra nó "
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
    L"ANIMACIJA IR NUOSTATOS\r\nAparatine įranga spartinamas skrydis tarp kintančių paviršių. Skrydis tarp "
    L"keturių kintančių paviršių; Skrydis kintančiu piltuvu. Kiekvienam monitoriui pasirinkite vieną "
    L"animaciją. Tekstūros langelis perjungia tekstūruotą paviršių ir vielinį modelį. Laisvas kameros "
    L"sukimasis lėtai keičia žiūrėjimo kryptį visose trijose dimensijose. Pauzės ir apsisukimai prideda "
    L"atsitiktinį lėtėjimą, pauzes ir sukimosi krypties keitimą; skrydis pirmyn tęsiasi. Galimas 0–1600% "
    L"greitis. Kiekvienas monitorius turi nepriklausomą atsitiktinę sceną, atvaizduojamą jo atnaujinimo "
    L"dažniu. Pagrindinę, užpildančią, aplinkos ir kontūrinę šviesą galima atskirai įjungti pasirinktiems "
    L"ekranams. Apšvietimas taikomas tik tekstūruotiems paviršiams.\r\n\r\nMONITORIAI\r\nMonitorių sąraše "
    L"pasirinkite vieną ar kelias eilutes. Ctrl+A pasirenka visas, o Ctrl ir Shift leidžia keisti "
    L"pasirinkimą. Animacijos valdikliai ir slankikliai keičia tik pasirinktų monitorių nuostatas. Eilutės "
    L"pasirinkimas nėra tas pats, kas animacijos išvesties įjungimas jos žymimuoju langeliu. Pasirinkimas "
    L"atskirai įsimenamas programai ir užsklandai. Jei buvo pasirinkti visi monitoriai, į pasirinkimą "
    L"įtraukiami ir naujai prijungti monitoriai. Skirtingas pasirinktų monitorių reikšmes rodo neapibrėžta "
    L"žymimųjų langelių būsena ir taškinis raštas ant parinkčių mygtukų, slankiklių rankenėlių bei visų "
    L"parinkčių įjungimo ir išjungimo mygtukų. Slankiklių užrašuose vietoj bendros reikšmės rodomas "
    L"brūkšnys. Pakeitus parinktį arba spustelėjus slankiklį, ta reikšmė pritaikoma visiems pasirinktiems "
    L"monitoriams.\r\n\r\nVALDYMAS\r\nPaleiskite FlightCorridor.exe. Nuostatos išsaugomos nuolat, veikia "
    L"tik vienas programos egzempliorius. Monitoriaus langelis arba dvigubas eilutės spustelėjimas įjungia "
    L"ar išjungia animacijos išvestį. Animaciją galima pristabdyti ir tęsti. PNG ir MP4 fiksuoja pirmą "
    L"aktyvų animacijos monitorių, o ne bendrą visų monitorių vaizdą. Įrašomo monitoriaus išjungti "
    L"negalima; uždarant programą vykstant įrašymui reikia patvirtinimo. Pristabdymas ir užsklandos "
    L"blokavimas taikomi visai programai, nepriklausomai nuo monitorių pasirinkimo. Įjungus blokavimą, "
    L"Windows užsklanda neleidžiama tik kol bent viename monitoriuje matoma nepristabdyta animacija. "
    L"Programa gali įdiegti ir pašalinti į ją įtrauktą užsklandą.\r\n\r\nEKRANO KOPIJOS IR "
    L"ĮRAŠYMAS\r\nĮrašymo nuostatose pasirinkite Viewport arba TV. Viewport išsaugo monitoriaus matmenis ir "
    L"dažnį iki 60 kadrų per sekundę. TV siūlo 1920 × 1080, 1440 × 1080 arba 1280 × 720 išvestį 16:9 "
    L"santykiu bei 50, 25, 59.94 (60000/1001) arba 29.97 (30000/1001) kadrų per sekundę. TV vaizdas "
    L"progresinis, BT.709, riboto diapazono ir 4:2:0 spalvų diskretizavimo. Vaizdo proporcijos išlieka, "
    L"užpildymo juostos juodos. OK pritaiko nuostatas kitam įrašui, Atšaukti arba Esc atmeta nepatvirtintus "
    L"pakeitimus. Įrašymo, žinyno ir informacijos langai neblokuoja kitų langų ir gali būti sumažinti. Tab "
    L"ir Shift+Tab keičia įvesties vietą, Enter paspaudžia aktyvų mygtuką, Esc uždaro aktyvų papildomą "
    L"langą.\r\n\r\nSISTEMOS REIKALAVIMAI\r\nWindows 7–11 palaiko visas funkcijas. Windows Vista SP2 būtina "
    L"įdiegti naujinimus KB971512 ir KB2117917; MP4 įrašymas Vistoje neveikia. Reikalingas Direct3D 11 "
    L"palaikymas, o MP4 įrašymui Media Foundation ir H.264 koduotuvas. Sąsaja ir dokumentacija pateikiamos "
    L"36 kalbomis.",
    L"ANIMĀCIJA UN IESTATĪJUMI\r\nAparatūras paātrināts lidojums starp mainīgām virsmām. Lidojums starp "
    L"četrām mainīgām virsmām; Lidojums caur mainīgu piltuvi. Katram monitoram izvēlieties tieši vienu "
    L"animāciju. Tekstūras rūtiņa pārslēdz teksturētu virsmu un stiepļu modeli. Brīva kameras rotācija "
    L"lēnām maina skatiena virzienu visās trijās dimensijās. Pauzes un virzienmaiņa pievieno nejaušu "
    L"palēninājumu, pauzes un rotācijas virziena maiņu; lidojums uz priekšu turpinās. Pieejams ātrums "
    L"0–1600%. Katram monitoram ir neatkarīga nejauša aina, ko renderē tā atsvaidzināšanas frekvencē. "
    L"Pamata, aizpildošo, apkārtējo un kontūru gaismu atlasītajiem monitoriem var ieslēgt neatkarīgi. "
    L"Apgaismojums attiecas tikai uz teksturētām virsmām.\r\n\r\nMONITORI\r\nMonitoru sarakstā atlasiet "
    L"vienu vai vairākas rindas. Ctrl+A atlasa visas, bet Ctrl un Shift ļauj mainīt atlasi. Animācijas "
    L"vadīklas un slīdņi maina tikai atlasīto monitoru iestatījumus. Rindas atlasīšana nav tas pats, kas "
    L"animācijas izvades ieslēgšana ar izvēles rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un "
    L"ekrānsaudzētājam. Ja bija atlasīti visi monitori, atlasē iekļauj arī jaunpievienotos monitorus. "
    L"Atšķirīgas vērtības atlasītajos monitoros norāda nenoteikts izvēles rūtiņu stāvoklis un punktots "
    L"raksts uz radiopogām, slīdņu rokturiem un visu iespēju ieslēgšanas vai izslēgšanas pogām. Slīdņu "
    L"etiķetēs kopīgas vērtības vietā redzama domuzīme. Mainot iespēju vai noklikšķinot uz slīdņa, šī "
    L"vērtība tiek piemērota visiem atlasītajiem monitoriem.\r\n\r\nLIETOŠANA\r\nPalaidiet "
    L"FlightCorridor.exe. Iestatījumi tiek saglabāti nepārtraukti, un darbojas tikai viena lietotnes "
    L"instance. Monitora rūtiņa vai dubultklikšķis uz rindas ieslēdz vai izslēdz tā animācijas izvadi. "
    L"Animāciju var pauzēt un turpināt. PNG un MP4 uzņem pirmo aktīvo animācijas monitoru, nevis visu "
    L"monitoru kopējo attēlu. Ierakstāmo monitoru nevar izslēgt; aizverot lietotni ieraksta laikā, "
    L"nepieciešams apstiprinājums. Pauze un ekrānsaudzētāja bloķēšana attiecas uz visu lietotni neatkarīgi "
    L"no monitoru atlases. Ja bloķēšana ir ieslēgta, Windows ekrānsaudzētājs tiek bloķēts tikai tik ilgi, "
    L"kamēr vismaz vienā monitorā ir redzama nepauzēta animācija. Lietotne var instalēt vai atinstalēt tajā "
    L"iebūvēto ekrānsaudzētāju.\r\n\r\nEKRĀNUZŅĒMUMI UN IERAKSTĪŠANA\r\nIeraksta iestatījumos izvēlieties "
    L"Viewport vai TV. Viewport saglabā monitora izmērus un frekvenci līdz 60 kadriem sekundē. TV piedāvā "
    L"1920 × 1080, 1440 × 1080 vai 1280 × 720 izvadi ar 16:9 malu attiecību un 50, 25, 59.94 (60000/1001) "
    L"vai 29.97 (30000/1001) kadriem sekundē. TV video ir progresīvs BT.709 ar ierobežotu diapazonu un "
    L"4:2:0 krāsu apakšiztveršanu. Attēla proporcijas saglabājas, aizpildījuma joslas ir melnas. OK piemēro "
    L"izvēles nākamajam ierakstam, Atcelt vai Esc atmet neapstiprinātās izmaiņas. Ieraksta iestatījumu, "
    L"palīdzības un informācijas logi nebloķē citus logus un ir minimizējami. Tab un Shift+Tab pārvieto "
    L"fokusu, Enter aktivizē fokusēto pogu, Esc aizver aktīvo palīglogu.\r\n\r\nSISTĒMAS "
    L"PRASĪBAS\r\nWindows 7–11 atbalsta visas funkcijas. Windows Vista SP2 jāinstalē atjauninājumi KB971512 "
    L"un KB2117917; MP4 ierakstīšana Vistā nedarbojas. Nepieciešams Direct3D 11 atbalsts, bet MP4 vajadzīgi "
    L"Media Foundation un H.264 kodētājs. Saskarne un dokumentācija ir pieejama 36 valodās.",
    L"ANIMÁCIÓ ÉS BEÁLLÍTÁSOK\r\nHardveresen gyorsított repülés változó felületek között. Repülés négy "
    L"változó felület között; Repülés változó tölcsérben. Monitoronként pontosan egy animáció választható. "
    L"A Textúra jelölőnégyzet a textúrázott felület és a drótváz között vált. A kamera szabad forgása "
    L"lassan változtatja a nézetet mindhárom dimenzióban. A Szünetek és irányváltás véletlenszerű "
    L"lassításokat, szüneteket és forgásirányváltásokat ad hozzá; az előrehaladás folytatódik. A sebesség "
    L"0–1600%. Minden monitor önálló véletlenszerű jelenetet kap, saját frissítési gyakoriságához igazodó "
    L"megjelenítéssel. A főfény, a derítőfény, a környezeti fény és a peremfény külön kapcsolható a "
    L"kijelölt monitorokon. A világítás csak a textúrázott felületekre "
    L"vonatkozik.\r\n\r\nMONITOROK\r\nJelöljön ki egy vagy több sort a monitorok listájában. A Ctrl+A "
    L"mindet kijelöli; a Ctrl és a Shift módosítja a kijelölést. Az animáció vezérlői és csúszkái csak a "
    L"kijelölt monitorok beállításait változtatják. A sor kijelölése és az animációs kimenet "
    L"jelölőnégyzetes engedélyezése külön művelet. A kijelölést az alkalmazás és a képernyőkímélő külön "
    L"megjegyzi. Ha korábban minden monitor ki volt jelölve, az újonnan csatlakoztatott monitorok is "
    L"bekerülnek a kijelölésbe. A kijelölt monitorok eltérő értékeit a jelölőnégyzetek határozatlan "
    L"állapota, valamint a választógombok, a csúszkafogantyúk és az összes beállítást be- vagy kikapcsoló "
    L"gombok pontozása jelzi. A csúszkák felirata közös érték helyett gondolatjelet mutat. Egy beállítás "
    L"módosítása vagy a csúszkára kattintás az adott értéket minden kijelölt monitorra "
    L"alkalmazza.\r\n\r\nKEZELÉS\r\nIndítsa el a FlightCorridor.exe fájlt. A beállítások folyamatosan "
    L"mentődnek, és csak egy alkalmazáspéldány fut. A monitor jelölőnégyzete vagy a sorra történő dupla "
    L"kattintás kapcsolja az animációs kimenetet. Az animáció szüneteltethető és folytatható. A PNG és az "
    L"MP4 az első aktív animációs monitort rögzíti, nem az összes monitor egyesített képét. A rögzített "
    L"monitor felvétel közben nem kapcsolható ki; az alkalmazás bezárásához ekkor megerősítés szükséges. A "
    L"szüneteltetés és a képernyőkímélő tiltása a teljes alkalmazásra vonatkozik, a monitorok kijelölésétől "
    L"függetlenül. Bekapcsolt tiltás esetén a Windows képernyőkímélője csak addig nem indul el, amíg "
    L"legalább egy monitoron látható, nem szünetelő animáció fut. Az alkalmazás telepítheti és "
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
    L"ANIMAZZJONI U SETTINGS\r\nTitjira bejn uċuħ li jinbidlu aċċellerata bil-ħardwer. Titjira bejn erba’ "
    L"uċuħ li jinbidlu; Titjira f’lembut li jinbidel. Agħżel animazzjoni waħda biss għal kull moniter. "
    L"Nisġa taqleb bejn wiċċ b’nisġa u mudell bil-wireframe. Ir-rotazzjoni libera tal-kamera tbiddel "
    L"id-direzzjoni tal-ħarsa bil-mod fit-tliet dimensjonijiet. L-għażla Pawżi u bidliet fid-direzzjoni "
    L"żżid deċelerazzjonijiet, pawżi u treġġigħ lura tar-rotazzjoni b’mod każwali; it-titjira ’l quddiem "
    L"tkompli. Il-veloċità hija 0–1600%. Kull moniter għandu xena każwali indipendenti li tintwera bir-rata "
    L"ta’ aġġornament tiegħu. Id-dawl prinċipali, id-dawl ta’ mili, id-dawl ambjentali u d-dawl tal-kontorn "
    L"jistgħu jinxtegħlu separatament għall-iskrins magħżula. Id-dawl japplika biss għall-uċuħ "
    L"bit-tessut.\r\n\r\nSKRINS\r\nAgħżel ringiela waħda jew aktar fil-lista tal-moniters. Ctrl+A "
    L"jagħżilhom kollha; Ctrl u Shift ibiddlu l-għażla. Il-kontrolli u s-sliders tal-animazzjoni jibdlu "
    L"biss is-settings tal-moniters magħżula. L-għażla ta’ ringiela hija differenti mill-attivazzjoni "
    L"tal-output permezz tal-kaxxa tal-marka. L-għażla tinżamm separatament għall-applikazzjoni u "
    L"għall-iscreen saver. Jekk il-moniters kollha kienu magħżula, il-moniters ġodda jiddaħħlu wkoll "
    L"fl-għażla. Valuri differenti fuq il-moniters magħżula jintwerew bi stat indeterminat tal-kaxxi "
    L"tal-marka u b’disinn bit-tikek fuq il-buttuni tar-radju, il-manki tas-sliders u l-buttuni li jattivaw "
    L"jew jiddiżattivaw l-għażliet kollha. It-tikketti tas-sliders juru sing minflok valur komuni. Meta "
    L"tibdel għażla jew tikklikkja slider, dak il-valur jiġi applikat għall-moniters magħżula "
    L"kollha.\r\n\r\nKONTROLLI\r\nĦaddem FlightCorridor.exe. Is-settings jiġu ssejvjati kontinwament u "
    L"taħdem istanza waħda biss. Il-kaxxa tal-moniter jew klikk doppja fuq ir-ringiela tattiva jew "
    L"tiddiżattiva l-output tal-animazzjoni. Tista’ tissospendi u tkompli l-animazzjoni. PNG u MP4 jaqbdu "
    L"l-ewwel moniter tal-animazzjoni attiv, mhux immaġni magħquda tal-moniters kollha. Il-moniter li qed "
    L"jiġi rreġistrat ma jistax jiġi diżattivat; l-għeluq tal-applikazzjoni waqt reġistrazzjoni jeħtieġ "
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
    L"ANIMATIE EN INSTELLINGEN\r\nHardwareversnelde vlucht tussen vervormende oppervlakken. Vlucht tussen "
    L"vier vervormende oppervlakken; Vlucht door een vervormende trechter. Kies precies één animatie per "
    L"beeldscherm. Textuur schakelt tussen een getextureerd oppervlak en een draadmodel. Vrije "
    L"camerarotatie verandert de kijkrichting langzaam in alle drie dimensies. De optie Pauzes en omkeren "
    L"voegt willekeurige vertragingen, pauzes en omkeringen van de rotatie toe; de voorwaartse vlucht gaat "
    L"door. De snelheid is instelbaar op 0–1600%. Elk beeldscherm heeft een onafhankelijke willekeurige "
    L"scène en wordt op zijn eigen vernieuwingsfrequentie aangestuurd. Hoofdlicht, invullicht, "
    L"omgevingslicht en randlicht kunnen onafhankelijk worden geschakeld voor de geselecteerde "
    L"beeldschermen. De verlichting geldt alleen voor oppervlakken met "
    L"textuur.\r\n\r\nBEELDSCHERMEN\r\nSelecteer één of meer beeldschermrijen in de lijst. Ctrl+A "
    L"selecteert alles; met Ctrl en Shift past u de selectie aan. Animatieknoppen en schuifregelaars "
    L"wijzigen alleen de instellingen van de geselecteerde beeldschermen. Een rij selecteren is iets anders "
    L"dan de animatie-uitvoer inschakelen met het selectievakje. De selectie wordt apart onthouden voor de "
    L"toepassing en de schermbeveiliging. Als alle beeldschermen waren geselecteerd, worden nieuw "
    L"aangesloten beeldschermen ook geselecteerd. Verschillende waarden op geselecteerde beeldschermen "
    L"worden aangegeven door selectievakjes in onbepaalde toestand en een stippelpatroon op keuzerondjes, "
    L"schuifknoppen en knoppen om alle opties in of uit te schakelen. De labels van schuifregelaars tonen "
    L"een streepje in plaats van een gemeenschappelijke waarde. Een optie wijzigen of op een schuifregelaar "
    L"klikken past die waarde toe op alle geselecteerde beeldschermen.\r\n\r\nBEDIENING\r\nStart "
    L"FlightCorridor.exe. Instellingen worden doorlopend opgeslagen en er draait slechts één exemplaar van "
    L"de toepassing. Het selectievakje of een dubbelklik op de beeldschermrij schakelt de animatie-uitvoer "
    L"in of uit. U kunt de animatie pauzeren en hervatten. PNG en MP4 leggen het eerste actieve "
    L"animatiebeeldscherm vast, niet een gecombineerd beeld van alle schermen. Het opgenomen beeldscherm "
    L"kan niet worden uitgeschakeld; afsluiten tijdens een opname vereist bevestiging. Pauzeren en het "
    L"blokkeren van de schermbeveiliging gelden voor de hele toepassing, ongeacht de beeldschermselectie. "
    L"Als blokkering is ingeschakeld, wordt de Windows-schermbeveiliging alleen tegengehouden zolang op "
    L"minstens één beeldscherm een zichtbare, niet-gepauzeerde animatie draait. De toepassing kan de "
    L"ingebouwde schermbeveiliging installeren of verwijderen.\r\n\r\nSCHERMAFBEELDINGEN EN OPNAMEN\r\nKies "
    L"Viewport of TV in de opname-instellingen. Viewport behoudt de afmetingen en vernieuwingsfrequentie "
    L"van het beeldscherm tot 60 frames per seconde. TV biedt 1920 × 1080, 1440 × 1080 of 1280 × 720 met "
    L"beeldverhouding 16:9 en 50, 25, 59.94 (60000/1001) of 29.97 (30000/1001) frames per seconde. TV "
    L"gebruikt progressieve BT.709-video met beperkt bereik en 4:2:0-kleursubsampling. De beeldverhouding "
    L"blijft behouden en opvulbalken zijn zwart. OK bewaart de opties voor de volgende opname; Annuleren of "
    L"Esc verwerpt onbevestigde wijzigingen. Opname-instellingen, Help en Info blokkeren andere vensters "
    L"niet en kunnen worden geminimaliseerd. Tab en Shift+Tab verplaatsen de focus, Enter activeert de knop "
    L"met focus en Esc sluit het actieve hulpvenster.\r\n\r\nSYSTEEMVEREISTEN\r\nWindows 7–11 ondersteunt "
    L"alle functies. Voor Windows Vista SP2 moet u updates KB971512 en KB2117917 installeren; MP4-opname "
    L"werkt niet op Vista. Direct3D 11-ondersteuning is vereist; voor MP4 zijn ook Media Foundation en een "
    L"H.264-encoder nodig. Interface en documentatie zijn beschikbaar in 36 talen.",
    L"ANIMAȚIE ȘI SETĂRI\r\nZbor între suprafețe deformabile accelerat hardware. Zbor între patru suprafețe "
    L"deformabile; Zbor printr-o pâlnie deformabilă. Alegeți exact o animație pentru fiecare monitor. "
    L"Textură comută între suprafața texturată și modelul de sârmă. Rotirea liberă a camerei schimbă lent "
    L"direcția privirii în toate cele trei dimensiuni. Pauze și inversări adaugă încetiniri, pauze și "
    L"inversări ale rotației la intervale aleatorii; zborul înainte continuă. Viteza este 0–1600%. Fiecare "
    L"monitor are o scenă aleatorie independentă, randată la propria rată de reîmprospătare. Lumina "
    L"principală, lumina de umplere, lumina ambiantă și lumina de contur pot fi comutate separat pentru "
    L"ecranele selectate. Iluminarea se aplică doar suprafețelor texturate.\r\n\r\nMONITOARE\r\nSelectați "
    L"unul sau mai multe rânduri din lista monitoarelor. Ctrl+A le selectează pe toate; Ctrl și Shift "
    L"modifică selecția. Comenzile și glisoarele animației schimbă numai setările monitoarelor selectate. "
    L"Selectarea unui rând diferă de activarea ieșirii prin caseta sa de selectare. Selecția este reținută "
    L"separat pentru aplicație și economizor. Dacă erau selectate toate monitoarele, sunt incluse și cele "
    L"conectate ulterior. Valorile diferite de pe monitoarele selectate sunt indicate prin starea "
    L"nedeterminată a casetelor de selectare și un model punctat pe butoanele radio, mânerele glisoarelor "
    L"și butoanele de activare sau dezactivare a tuturor opțiunilor. Etichetele glisoarelor afișează o "
    L"liniuță în locul unei valori comune. Modificarea unei opțiuni sau clicul pe un glisor aplică acea "
    L"valoare tuturor monitoarelor selectate.\r\n\r\nCOMENZI\r\nRulați FlightCorridor.exe. Setările se "
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
    L"ΚΙΝΗΣΗ ΚΑΙ ΡΥΘΜΙΣΕΙΣ\r\nΠτήση ανάμεσα σε μεταβαλλόμενες επιφάνειες με επιτάχυνση υλικού. Πτήση "
    L"ανάμεσα σε τέσσερις μεταβαλλόμενες επιφάνειες; Πτήση μέσα από μεταβαλλόμενη χοάνη. Επιλέξτε ακριβώς "
    L"μία κίνηση ανά οθόνη. Η Υφή εναλλάσσει επιφάνεια με υφή και συρμάτινο μοντέλο. Η ελεύθερη περιστροφή "
    L"κάμερας αλλάζει αργά την κατεύθυνση θέασης και στις τρεις διαστάσεις. Οι Παύσεις και αντιστροφές "
    L"προσθέτουν τυχαίες επιβραδύνσεις, παύσεις και αντιστροφές περιστροφής, ενώ η πτήση προς τα εμπρός "
    L"συνεχίζεται. Η ταχύτητα είναι 0–1600%. Κάθε οθόνη διαθέτει ανεξάρτητη τυχαία σκηνή που αποδίδεται "
    L"στον δικό της ρυθμό ανανέωσης. Ο κύριος φωτισμός, ο φωτισμός πλήρωσης, ο περιβάλλων φωτισμός και ο "
    L"φωτισμός περιγράμματος ρυθμίζονται ανεξάρτητα για τις επιλεγμένες οθόνες. Ο φωτισμός εφαρμόζεται μόνο "
    L"σε επιφάνειες με υφή.\r\n\r\nΟΘΟΝΕΣ\r\nΕπιλέξτε μία ή περισσότερες γραμμές στη λίστα οθονών. Το "
    L"Ctrl+A επιλέγει όλες, ενώ τα Ctrl και Shift αλλάζουν την επιλογή. Τα χειριστήρια και τα ρυθμιστικά "
    L"της κίνησης αλλάζουν μόνο τις ρυθμίσεις των επιλεγμένων οθονών. Η επιλογή γραμμής διαφέρει από την "
    L"ενεργοποίηση εξόδου μέσω του πλαισίου ελέγχου της. Η επιλογή αποθηκεύεται χωριστά για την εφαρμογή "
    L"και την προφύλαξη. Αν είχαν επιλεγεί όλες οι οθόνες, περιλαμβάνονται και όσες συνδεθούν αργότερα. Οι "
    L"διαφορετικές τιμές στις επιλεγμένες οθόνες υποδεικνύονται με απροσδιόριστη κατάσταση των πλαισίων "
    L"ελέγχου και μοτίβο κουκκίδων στα κουμπιά επιλογής, στις λαβές των ρυθμιστικών και στα κουμπιά "
    L"ενεργοποίησης ή απενεργοποίησης όλων των επιλογών. Οι ετικέτες των ρυθμιστικών δείχνουν παύλα αντί "
    L"για κοινή τιμή. Η αλλαγή επιλογής ή το κλικ σε ρυθμιστικό εφαρμόζει την τιμή σε όλες τις επιλεγμένες "
    L"οθόνες.\r\n\r\nΧΕΙΡΙΣΜΟΣ\r\nΕκτελέστε το FlightCorridor.exe. Οι ρυθμίσεις αποθηκεύονται συνεχώς και "
    L"εκτελείται μόνο ένα αντίγραφο της εφαρμογής. Το πλαίσιο της οθόνης ή το διπλό κλικ στη γραμμή "
    L"ενεργοποιεί ή απενεργοποιεί την έξοδο κίνησης. Η κίνηση μπορεί να παύσει και να συνεχιστεί. Τα PNG "
    L"και MP4 καταγράφουν την πρώτη ενεργή οθόνη κίνησης, όχι συνδυασμένη εικόνα όλων των οθονών. Η "
    L"καταγραφόμενη οθόνη δεν μπορεί να απενεργοποιηθεί· το κλείσιμο της εφαρμογής κατά την εγγραφή απαιτεί "
    L"επιβεβαίωση. Η παύση και η αναστολή προφύλαξης οθόνης ισχύουν για όλη την εφαρμογή, ανεξάρτητα από "
    L"την επιλογή οθονών. Όταν η αναστολή είναι ενεργή, η προφύλαξη των Windows εμποδίζεται μόνο όσο "
    L"υπάρχει ορατή κίνηση χωρίς παύση σε τουλάχιστον μία οθόνη. Η εφαρμογή εγκαθιστά ή καταργεί την "
    L"ενσωματωμένη προφύλαξη.\r\n\r\nΣΤΙΓΜΙΟΤΥΠΑ ΚΑΙ ΕΓΓΡΑΦΗ\r\nΣτις ρυθμίσεις εγγραφής επιλέξτε Viewport ή "
    L"TV. Το Viewport διατηρεί διαστάσεις και ρυθμό ανανέωσης οθόνης έως 60 καρέ ανά δευτερόλεπτο. Το TV "
    L"προσφέρει 1920 × 1080, 1440 × 1080 ή 1280 × 720 σε 16:9, με 50, 25, 59.94 (60000/1001) ή 29.97 "
    L"(30000/1001) καρέ ανά δευτερόλεπτο. Το βίντεο TV είναι προοδευτικό BT.709 περιορισμένου εύρους με "
    L"υποδειγματοληψία χρώματος 4:2:0. Διατηρούνται οι αναλογίες εικόνας και οι συμπληρωματικές λωρίδες "
    L"είναι μαύρες. Το OK αποθηκεύει επιλογές για την επόμενη εγγραφή· Άκυρο ή Esc απορρίπτει "
    L"ανεπιβεβαίωτες αλλαγές. Οι ρυθμίσεις εγγραφής, η βοήθεια και οι πληροφορίες δεν εμποδίζουν άλλα "
    L"παράθυρα και ελαχιστοποιούνται. Tab και Shift+Tab μετακινούν την εστίαση, Enter ενεργοποιεί το "
    L"εστιασμένο κουμπί και Esc κλείνει το ενεργό βοηθητικό παράθυρο.\r\n\r\nΑΠΑΙΤΗΣΕΙΣ ΣΥΣΤΗΜΑΤΟΣ\r\nΤα "
    L"Windows 7–11 υποστηρίζουν όλες τις λειτουργίες. Στα Windows Vista SP2 πρέπει να εγκατασταθούν οι "
    L"ενημερώσεις KB971512 και KB2117917· η εγγραφή MP4 δεν λειτουργεί στα Vista. Απαιτείται υποστήριξη "
    L"Direct3D 11 και, για MP4, Media Foundation και κωδικοποιητής H.264. Η διεπαφή και η τεκμηρίωση "
    L"διατίθενται σε 36 γλώσσες.",
    L"ANIMACIJA I POSTAVKE\r\nHardverski ubrzan let između promjenjivih površina. Let između četiri "
    L"promjenjive površine; Let kroz promjenjivi lijevak. Za svaki monitor odaberite tačno jednu animaciju. "
    L"Tekstura mijenja prikaz između teksturirane površine i žičanog modela. Slobodno okretanje kamere "
    L"polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, pauze "
    L"i promjene smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki monitor ima nezavisnu "
    L"nasumičnu scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko "
    L"svjetlo, ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. "
    L"Osvjetljenje se primjenjuje samo na teksturirane površine.\r\n\r\nMONITORI\r\nOdaberite jedan ili "
    L"više redova u listi monitora. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači "
    L"animacije mijenjaju samo postavke odabranih monitora. Odabir reda nije isto što i uključivanje izlaza "
    L"njegovom kućicom. Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
    L"odabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na odabranim "
    L"monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, ručkama "
    L"klizača i dugmadima za uključivanje ili isključivanje svih opcija. Oznake klizača prikazuju crticu "
    L"umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost na sve "
    L"odabrane monitore.\r\n\r\nUPRAVLJANJE\r\nPokrenite FlightCorridor.exe. Postavke se stalno čuvaju i "
    L"radi samo jedna instanca aplikacije. Kućica monitora ili dvostruki klik na red uključuje ili "
    L"isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe prvi aktivni "
    L"monitor animacije, ne zajedničku sliku svih monitora. Snimani monitor ne možete isključiti; "
    L"zatvaranje aplikacije tokom snimanja zahtijeva potvrdu. Pauza i blokada čuvara ekrana vrijede za "
    L"cijelu aplikaciju, bez obzira na odabir monitora. Kada je blokada uključena, čuvar ekrana Windowsa se "
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
    L"ANIMACIJA I POSTAVKE\r\nHardverski ubrzan let između promjenjivih ploha. Let između četiriju "
    L"promjenjivih ploha; Let kroz promjenjivi lijevak. Za svaki zaslon odaberite točno jednu animaciju. "
    L"Tekstura mijenja prikaz između teksturirane plohe i žičanog modela. Slobodno okretanje kamere polako "
    L"mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, stanke i "
    L"promjene smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki zaslon ima neovisnu "
    L"nasumičnu scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko "
    L"svjetlo, ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. "
    L"Osvjetljenje se primjenjuje samo na teksturirane površine.\r\n\r\nMONITORI\r\nOdaberite jedan ili "
    L"više redaka na popisu zaslona. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači "
    L"animacije mijenjaju samo postavke odabranih zaslona. Odabir retka nije isto što i uključivanje izlaza "
    L"njegovim potvrdnim okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar zaslona. Ako su prethodno "
    L"bili odabrani svi zasloni, uključuju se i novopriključeni zasloni. Različite vrijednosti na odabranim "
    L"zaslonima prikazuju se neodređenim stanjem potvrdnih okvira i točkastim uzorkom na izbornim gumbima, "
    L"ručkama klizača i gumbima za uključivanje ili isključivanje svih mogućnosti. Oznake klizača prikazuju "
    L"crticu umjesto zajedničke vrijednosti. Promjena mogućnosti ili klik na klizač primjenjuje tu "
    L"vrijednost na sve odabrane zaslone.\r\n\r\nUPRAVLJANJE\r\nPokrenite FlightCorridor.exe. Postavke se "
    L"neprekidno spremaju i radi samo jedna instanca aplikacije. Potvrdni okvir zaslona ili dvostruki klik "
    L"na redak uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i "
    L"MP4 bilježe prvi aktivni zaslon animacije, ne zajedničku sliku svih zaslona. Snimani zaslon ne možete "
    L"isključiti; zatvaranje aplikacije tijekom snimanja zahtijeva potvrdu. Pauza i blokada čuvara zaslona "
    L"vrijede za cijelu aplikaciju, bez obzira na odabir zaslona. Kada je blokada uključena, čuvar zaslona "
    L"sustava Windows sprječava se samo dok je na barem jednom zaslonu vidljiva animacija koja nije "
    L"pauzirana. Aplikacija može instalirati i deinstalirati ugrađeni čuvar zaslona.\r\n\r\nSNIMKE ZASLONA "
    L"I SNIMANJE\r\nU postavkama snimanja odaberite Viewport ili TV. Viewport zadržava dimenzije i "
    L"frekvenciju zaslona do 60 sličica u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u omjeru "
    L"16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) sličica u sekundi. TV video je progresivni "
    L"BT.709 ograničenog raspona s poduzorkovanjem boje 4:2:0. Omjer slike ostaje sačuvan, a dopunske trake "
    L"su crne. OK sprema mogućnosti za sljedeću snimku; Odustani ili Esc odbacuje nepotvrđene izmjene. "
    L"Prozori snimanja, pomoći i informacija ne blokiraju ostale prozore i mogu se minimizirati. Tab i "
    L"Shift+Tab pomiču fokus, Enter aktivira fokusirani gumb, a Esc zatvara aktivni pomoćni "
    L"prozor.\r\n\r\nZAHTJEVI SUSTAVA\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate "
    L"instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, "
    L"a za MP4 i Media Foundation te H.264 koder. Sučelje i dokumentacija dostupni su na 36 jezika.",
    L"ANIMACIJA IN NASTAVITVE\r\nStrojno pospešen let med spreminjajočimi se ploskvami. Let med štirimi "
    L"spreminjajočimi se ploskvami; Let skozi spreminjajoči se lijak. Za vsak zaslon izberite natanko eno "
    L"animacijo. Tekstura preklaplja med teksturirano ploskvijo in žičnim modelom. Prosto vrtenje kamere "
    L"počasi spreminja smer pogleda v vseh treh razsežnostih. Premori in obrati dodajo naključne "
    L"upočasnitve, premore in obrate smeri vrtenja; let naprej se nadaljuje. Hitrost je 0–1600%. Vsak "
    L"zaslon ima neodvisen naključen prizor, ki se izrisuje z njegovo hitrostjo osveževanja. Glavno "
    L"svetlobo, dopolnilno svetlobo, okoljsko svetlobo in obrobno svetlobo je mogoče neodvisno vklapljati "
    L"za izbrane zaslone. Osvetlitev velja samo za teksturirane površine.\r\n\r\nZASLONI\r\nNa seznamu "
    L"zaslonov izberite eno ali več vrstic. Ctrl+A izbere vse, Ctrl in Shift pa spreminjata izbor. "
    L"Kontrolniki in drsniki animacije spreminjajo samo nastavitve izbranih zaslonov. Izbira vrstice ni "
    L"isto kot vklop izhoda z njenim potrditvenim poljem. Izbor se ločeno shrani za program in "
    L"ohranjevalnik. Če so bili izbrani vsi zasloni, so vključeni tudi na novo priključeni zasloni. "
    L"Različne vrednosti na izbranih zaslonih označujeta nedoločeno stanje potrditvenih polj in pikčast "
    L"vzorec na izbirnih gumbih, ročicah drsnikov ter gumbih za vklop ali izklop vseh možnosti. Oznake "
    L"drsnikov namesto skupne vrednosti prikazujejo pomišljaj. Sprememba možnosti ali klik na drsnik "
    L"uveljavi to vrednost na vseh izbranih zaslonih.\r\n\r\nUPRAVLJANJE\r\nZaženite FlightCorridor.exe. "
    L"Nastavitve se shranjujejo sproti in deluje le en primerek programa. Polje zaslona ali dvojni klik na "
    L"vrstico vklopi ali izklopi izhod animacije. Animacijo lahko začasno ustavite in nadaljujete. PNG in "
    L"MP4 zajameta prvi aktivni zaslon animacije, ne skupne slike vseh zaslonov. Snemanega zaslona ni "
    L"mogoče izklopiti; zapiranje programa med snemanjem zahteva potrditev. Premor in preprečevanje "
    L"ohranjevalnika veljata za celoten program, ne glede na izbor zaslonov. Ko je preprečevanje vključeno, "
    L"se ohranjevalnik Windows prepreči le, dokler je na vsaj enem zaslonu vidna animacija, ki ni "
    L"ustavljena. Program lahko namesti ali odstrani vgrajeni ohranjevalnik.\r\n\r\nPOSNETKI ZASLONA IN "
    L"SNEMANJE\r\nV nastavitvah snemanja izberite Viewport ali TV. Viewport ohrani velikost in hitrost "
    L"osveževanja zaslona do 60 sličic na sekundo. TV ponuja 1920 × 1080, 1440 × 1080 ali 1280 × 720 v "
    L"razmerju 16:9 ter 50, 25, 59.94 (60000/1001) ali 29.97 (30000/1001) sličic na sekundo. TV uporablja "
    L"progresivni BT.709 z omejenim obsegom in barvnim podvzorčenjem 4:2:0. Razmerje slike se ohrani, "
    L"dopolnilni pasovi so črni. OK shrani izbiro za naslednje snemanje; Prekliči ali Esc zavrže nepotrjene "
    L"spremembe. Okna snemanja, pomoči in podatkov o programu ne blokirajo drugih oken in jih je mogoče "
    L"minimirati. Tab in Shift+Tab premikata fokus, Enter aktivira izbrani gumb, Esc pa zapre aktivno "
    L"pomožno okno.\r\n\r\nSISTEMSKE ZAHTEVE\r\nWindows 7–11 podpira vse funkcije. Za Windows Vista SP2 "
    L"morate namestiti posodobitvi KB971512 in KB2117917; snemanje MP4 v Visti ne deluje. Potrebna je "
    L"podpora Direct3D 11, za MP4 pa še Media Foundation in kodirnik H.264. Vmesnik in dokumentacija sta na "
    L"voljo v 36 jezikih.",
    L"ANIMACIJA I PODEŠAVANJA\r\nHardverski ubrzan let između promjenljivih površina. Let između četiri "
    L"promjenljive površine; Let kroz promjenljivi lijevak. Za svaki monitor izaberite tačno jednu "
    L"animaciju. Tekstura mijenja prikaz između teksturisane površine i žičanog modela. Slobodno okretanje "
    L"kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, "
    L"pauze i promjene smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki monitor ima "
    L"nezavisnu nasumičnu scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, "
    L"dopunsko svjetlo, ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane "
    L"monitore. Osvjetljenje se primjenjuje samo na teksturirane površine.\r\n\r\nMONITORI\r\nIzaberite "
    L"jedan ili više redova u listi monitora. Ctrl+A bira sve; Ctrl i Shift mijenjaju izbor. Kontrole i "
    L"klizači animacije mijenjaju samo podešavanja izabranih monitora. Izbor reda nije isto što i "
    L"uključivanje izlaza njegovom kućicom. Izbor se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su "
    L"prethodno bili izabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti "
    L"na izabranim monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima "
    L"izbora, ručkama klizača i dugmadima za uključivanje ili isključivanje svih opcija. Oznake klizača "
    L"prikazuju crticu umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu "
    L"vrijednost na sve izabrane monitore.\r\n\r\nUPRAVLJANJE\r\nPokrenite FlightCorridor.exe. Podešavanja "
    L"se stalno čuvaju i radi samo jedna instanca aplikacije. Kućica monitora ili dvostruki klik na red "
    L"uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe "
    L"prvi aktivni monitor animacije, ne zajedničku sliku svih monitora. Snimani monitor ne možete "
    L"isključiti; zatvaranje aplikacije tokom snimanja zahtijeva potvrdu. Pauza i blokada čuvara ekrana "
    L"važe za cijelu aplikaciju, bez obzira na izbor monitora. Kada je blokada uključena, čuvar ekrana "
    L"Windowsa se sprječava samo dok je na barem jednom monitoru vidljiva animacija koja nije pauzirana. "
    L"Aplikacija može instalirati i deinstalirati ugrađeni čuvar ekrana.\r\n\r\nSNIMCI EKRANA I "
    L"SNIMANJE\r\nU podešavanjima snimanja izaberite Viewport ili TV. Viewport zadržava dimenzije i "
    L"frekvenciju monitora do 60 kadrova u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u "
    L"odnosu 16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) kadrova u sekundi. TV video je "
    L"progresivni BT.709 ograničenog opsega s poduzorkovanjem boje 4:2:0. Odnos slike ostaje sačuvan, a "
    L"dopunske trake su crne. OK čuva opcije za sljedeći snimak; Otkaži ili Esc odbacuje nepotvrđene "
    L"izmjene. Prozori snimanja, pomoći i informacija ne blokiraju ostale prozore i mogu se minimizovati. "
    L"Tab i Shift+Tab pomjeraju fokus, Enter aktivira fokusirano dugme, a Esc zatvara aktivni pomoćni "
    L"prozor.\r\n\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate "
    L"instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, "
    L"a za MP4 i Media Foundation i H.264 koder. Interfejs i dokumentacija dostupni su na 36 jezika.",
    L"АНІМАЦЫЯ І НАЛАДЫ\r\nАпаратна паскораны палёт паміж зменлівымі паверхнямі. Палёт паміж чатырма "
    L"зменлівымі паверхнямі; Палёт праз зменлівую варонку. Для кожнага манітора выберыце роўна адну "
    L"анімацыю. Тэкстура пераключае тэкстураваную паверхню і каркасную мадэль. Свабоднае кручэнне камеры "
    L"павольна змяняе напрамак погляду ва ўсіх трох вымярэннях. Паўзы і развароты дадаюць выпадковыя "
    L"запаволенні, паўзы і змены напрамку кручэння; палёт наперад працягваецца. Хуткасць — 0–1600%. Кожны "
    L"манітор мае незалежную выпадковую сцэну з вывадам паводле ўласнай частаты абнаўлення. Асноўнае, "
    L"запаўняльнае, фонавае і контурнае святло можна пераключаць незалежна для выбраных манітораў. "
    L"Асвятленне дзейнічае толькі на тэкстураваных паверхнях.\r\n\r\nМАНІТОРЫ\r\nВыберыце адзін або "
    L"некалькі радкоў у спісе манітораў. Ctrl+A выбірае ўсе; Ctrl і Shift змяняюць выбар. Элементы "
    L"кіравання і паўзункі анімацыі змяняюць толькі налады выбраных манітораў. Выбар радка і ўключэнне "
    L"вываду яго сцяжком — розныя дзеянні. Выбар асобна захоўваецца для праграмы і застаўкі. Калі раней "
    L"былі выбраны ўсе маніторы, да выбару далучаюцца і новыя маніторы. Розныя значэнні на выбраных "
    L"маніторах пазначаюцца нявызначаным станам сцяжкоў і кропкавым узорам на пераключальніках, ручках "
    L"паўзункоў і кнопках уключэння або выключэння ўсіх параметраў. У подпісах паўзункоў замест агульнага "
    L"значэння паказваецца працяжнік. Змена параметра або націск на паўзунок ужывае гэта значэнне да ўсіх "
    L"выбраных манітораў.\r\n\r\nКІРАВАННЕ\r\nЗапусціце FlightCorridor.exe. Налады захоўваюцца пастаянна, "
    L"працуе толькі адзін асобнік праграмы. Сцяжок манітора або падвойнае націсканне на радок уключае ці "
    L"выключае вывад анімацыі. Анімацыю можна прыпыніць і працягнуць. PNG і MP4 захопліваюць першы актыўны "
    L"манітор анімацыі, а не агульны відарыс усіх манітораў. Манітор, які запісваецца, нельга выключыць; "
    L"закрыццё праграмы падчас запісу патрабуе пацвярджэння. Прыпыненне і блакаванне застаўкі дзейнічаюць "
    L"на ўсю праграму незалежна ад выбару манітораў. Калі блакаванне ўключана, застаўка Windows не "
    L"запускаецца толькі пакуль хаця б на адным маніторы бачная непрыпыненая анімацыя. Праграма можа "
    L"ўсталяваць або выдаліць убудаваную застаўку.\r\n\r\nЗДЫМКІ ЭКРАНА І ЗАПІС\r\nУ наладах запісу "
    L"выберыце Viewport або TV. Viewport захоўвае памеры і частату манітора да 60 кадраў за секунду. TV "
    L"прапануе 1920 × 1080, 1440 × 1080 або 1280 × 720 з суадносінамі 16:9 і частатой 50, 25, 59.94 "
    L"(60000/1001) або 29.97 (30000/1001) кадраў за секунду. Відэа TV прагрэсіўнае, BT.709, з абмежаваным "
    L"дыяпазонам і субдыскрэтызацыяй колеру 4:2:0. Прапорцыі захоўваюцца, палосы запаўнення чорныя. OK "
    L"захоўвае выбар для наступнага запісу; Скасаваць або Esc адхіляе непацверджаныя змены. Вокны запісу, "
    L"даведкі і звестак пра праграму не блакуюць іншыя вокны і могуць згортвацца. Tab і Shift+Tab "
    L"перамяшчаюць фокус, Enter націскае актыўную кнопку, Esc закрывае актыўнае дапаможнае "
    L"акно.\r\n\r\nСІСТЭМНЫЯ ПАТРАБАВАННІ\r\nWindows 7–11 падтрымлівае ўсе функцыі. Для Windows Vista SP2 "
    L"неабходна ўсталяваць абнаўленні KB971512 і KB2117917; запіс MP4 у Vistа не працуе. Патрэбна падтрымка "
    L"Direct3D 11, а для MP4 таксама Media Foundation і кадавальнік H.264. Інтэрфейс і дакументацыя "
    L"даступны на 36 мовах.",
    L"АНИМАЦИЯ И НАСТРОЙКИ\r\nХардуерно ускорен полет между променящи се повърхнини. Полет между четири "
    L"променящи се повърхнини; Полет през променяща се фуния. Изберете точно една анимация за всеки "
    L"монитор. Текстура превключва между текстурирана повърхнина и телен модел. Свободното въртене на "
    L"камерата бавно променя посоката на погледа в трите измерения. Опцията „Паузи и обръщания“ добавя "
    L"случайни забавяния, паузи и обръщания на въртенето; полетът напред продължава. Скоростта е 0–1600%. "
    L"Всеки монитор има независима случайна сцена, изобразявана с неговата честота на опресняване. "
    L"Основната, запълващата, околната и контурната светлина се включват независимо за избраните монитори. "
    L"Осветлението се прилага само към текстурираните повърхности.\r\n\r\nМОНИТОРИ\r\nИзберете един или "
    L"повече редове в списъка с монитори. Ctrl+A избира всички; Ctrl и Shift променят избора. Контролите и "
    L"плъзгачите на анимацията променят само настройките на избраните монитори. Избирането на ред и "
    L"включването на изхода чрез отметката му са различни действия. Изборът се запомня отделно за "
    L"приложението и скрийнсейвъра. Ако са били избрани всички монитори, включват се и новосвързаните. "
    L"Различните стойности на избраните монитори се показват с неопределено състояние на отметките и точков "
    L"шаблон върху радиобутоните, дръжките на плъзгачите и бутоните за включване или изключване на всички "
    L"опции. Надписите на плъзгачите показват тире вместо обща стойност. Промяна на опция или щракване "
    L"върху плъзгач прилага стойността към всички избрани монитори.\r\n\r\nУПРАВЛЕНИЕ\r\nСтартирайте "
    L"FlightCorridor.exe. Настройките се запазват непрекъснато и работи само един екземпляр на "
    L"приложението. Отметката на монитора или двойно щракване върху реда включва или изключва анимационния "
    L"изход. Анимацията може да се поставя на пауза и да продължава. PNG и MP4 заснемат първия активен "
    L"монитор за анимация, не общ образ от всички монитори. Записваният монитор не може да се изключи; "
    L"затварянето на приложението при запис изисква потвърждение. Паузата и блокирането на скрийнсейвъра "
    L"важат за цялото приложение независимо от избора на монитори. Когато блокирането е включено, "
    L"скрийнсейвърът на Windows се предотвратява само докато на поне един монитор има видима анимация без "
    L"пауза. Приложението може да инсталира и деинсталира вградения скрийнсейвър.\r\n\r\nЕКРАННИ СНИМКИ И "
    L"ЗАПИС\r\nВ настройките за запис изберете Viewport или TV. Viewport запазва размерите и честотата на "
    L"монитора до 60 кадъра в секунда. TV предлага 1920 × 1080, 1440 × 1080 или 1280 × 720 със съотношение "
    L"16:9 и 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) кадъра в секунда. TV използва прогресивно "
    L"видео BT.709 с ограничен диапазон и цветова субдискретизация 4:2:0. Пропорциите се запазват, "
    L"допълващите ленти са черни. OK запазва избора за следващия запис; Отказ или Esc отхвърля "
    L"непотвърдените промени. Прозорците за запис, помощ и информация не блокират другите прозорци и могат "
    L"да се минимизират. Tab и Shift+Tab преместват фокуса, Enter активира фокусирания бутон, Esc затваря "
    L"активния помощен прозорец.\r\n\r\nСИСТЕМНИ ИЗИСКВАНИЯ\r\nWindows 7–11 поддържа всички функции. За "
    L"Windows Vista SP2 трябва да се инсталират актуализациите KB971512 и KB2117917; записът на MP4 не "
    L"работи във Vista. Изисква се поддръжка на Direct3D 11, а за MP4 също Media Foundation и H.264 кодер. "
    L"Интерфейсът и документацията са налични на 36 езика.",
    L"АНИМАЦИЈА И ПОСТАВКИ\r\nХардверски забрзан лет меѓу променливи површини. Лет меѓу четири променливи "
    L"површини; Лет низ променлива инка. За секој монитор изберете точно една анимација. Текстура менува "
    L"текстурирана површина и жичен модел. Слободното вртење на камерата полека го менува погледот во сите "
    L"три димензии. Опцијата „Паузи и пресврти“ додава случајни забавувања, паузи и промени на насоката на "
    L"вртење; летот напред продолжува. Брзината е 0–1600%. Секој монитор има независна случајна сцена што "
    L"се прикажува со неговата стапка на освежување. Главното, дополнителното, амбиенталното и контурното "
    L"светло може да се вклучуваат одделно за избраните монитори. Осветлувањето важи само за текстурираните "
    L"површини.\r\n\r\nМОНИТОРИ\r\nИзберете еден или повеќе редови во списокот на монитори. Ctrl+A ги "
    L"избира сите; Ctrl и Shift го менуваат изборот. Контролите и лизгачите на анимацијата ги менуваат само "
    L"поставките на избраните монитори. Избирањето ред и вклучувањето на излезот преку неговото поле се "
    L"различни дејства. Изборот се памети одделно за апликацијата и чуварот. Ако биле избрани сите "
    L"монитори, се вклучуваат и новоповрзаните монитори. Различните вредности на избраните монитори се "
    L"прикажуваат со неопределена состојба на полињата за избор и точкест образец на радио-копчињата, "
    L"рачките на лизгачите и копчињата за вклучување или исклучување на сите опции. Ознаките на лизгачите "
    L"прикажуваат црта наместо заедничка вредност. Менувањето опција или кликнувањето на лизгач ја "
    L"применува вредноста на сите избрани монитори.\r\n\r\nУПРАВУВАЊЕ\r\nСтартувајте FlightCorridor.exe. "
    L"Поставките се зачувуваат постојано и работи само еден примерок на апликацијата. Полето на мониторот "
    L"или двоен клик на редот го вклучува или исклучува анимацискиот излез. Анимацијата може да се паузира "
    L"и продолжи. PNG и MP4 го снимаат првиот активен монитор за анимација, не заедничка слика од сите "
    L"монитори. Мониторот што се снима не може да се исклучи; затворањето на апликацијата при снимање бара "
    L"потврда. Паузата и блокирањето на чуварот важат за целата апликација без оглед на изборот на "
    L"монитори. Кога блокирањето е вклучено, чуварот на Windows се спречува само додека на барем еден "
    L"монитор е видлива непаузирана анимација. Апликацијата може да го инсталира и деинсталира вградениот "
    L"чувар.\r\n\r\nСНИМКИ ОД ЕКРАН И СНИМАЊЕ\r\nВо поставките за снимање изберете Viewport или TV. "
    L"Viewport ги зачувува димензиите и стапката на мониторот до 60 кадри во секунда. TV нуди 1920 × 1080, "
    L"1440 × 1080 или 1280 × 720 со однос 16:9 и 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) кадри во "
    L"секунда. TV видеото е прогресивно BT.709 со ограничен опсег и подсемплирање на боја 4:2:0. "
    L"Пропорциите се задржуваат, дополнителните ленти се црни. OK ги зачувува опциите за следното снимање; "
    L"Откажи или Esc ги отфрла непотврдените измени. Прозорците за снимање, помош и информации не ги "
    L"блокираат другите прозорци и може да се минимизираат. Tab и Shift+Tab го поместуваат фокусот, Enter "
    L"го активира фокусираното копче, Esc го затвора активниот помошен прозорец.\r\n\r\nСИСТЕМСКИ "
    L"БАРАЊА\r\nWindows 7–11 ги поддржува сите функции. За Windows Vista SP2 мора да се инсталираат "
    L"ажурирањата KB971512 и KB2117917; MP4 снимањето на Vista не работи. Потребна е поддршка за Direct3D "
    L"11, а за MP4 и Media Foundation и H.264 кодер. Интерфејсот и документацијата се достапни на 36 јазици.",
    L"АНИМАЦИЈА И ПОДЕШАВАЊА\r\nХардверски убрзан лет између променљивих површи. Лет између четири "
    L"променљиве површи; Лет кроз променљиви левак. За сваки монитор изаберите тачно једну анимацију. "
    L"Текстура мења приказ између текстурисане површи и жичаног модела. Слободно окретање камере полако "
    L"мења смер погледа у све три димензије. Паузе и обрти додају насумично успоравање, паузе и промене "
    L"смера ротације; лет напред се наставља. Брзина је 0–1600%. Сваки монитор има независну насумичну "
    L"сцену која се приказује према његовој учестаности освежавања. Главно, допунско, амбијентално и "
    L"контурно светло могу се засебно укључивати за изабране мониторе. Осветљење важи само за текстуриране "
    L"површине.\r\n\r\nМОНИТОРИ\r\nИзаберите један или више редова у листи монитора. Ctrl+A бира све; Ctrl "
    L"и Shift мењају избор. Контроле и клизачи анимације мењају само подешавања изабраних монитора. Избор "
    L"реда није исто што и укључивање излаза његовим пољем за потврду. Избор се памти одвојено за "
    L"апликацију и чувар екрана. Ако су претходно били изабрани сви монитори, укључују се и новоприкључени "
    L"монитори. Различите вредности на изабраним мониторима приказују се неодређеним стањем поља за потврду "
    L"и тачкастим узорком на дугмадима избора, ручкама клизача и дугмадима за укључивање или искључивање "
    L"свих опција. Ознаке клизача приказују црту уместо заједничке вредности. Промена опције или клик на "
    L"клизач примењује ту вредност на све изабране мониторе.\r\n\r\nУПРАВЉАЊЕ\r\nПокрените "
    L"FlightCorridor.exe. Подешавања се стално чувају и ради само једна инстанца апликације. Поље монитора "
    L"или двоструки клик на ред укључује или искључује анимацијски излаз. Анимацију можете паузирати и "
    L"наставити. PNG и MP4 бележе први активни монитор анимације, не заједничку слику свих монитора. "
    L"Снимани монитор не можете искључити; затварање апликације током снимања захтева потврду. Пауза и "
    L"блокада чувара екрана важе за целу апликацију, без обзира на избор монитора. Када је блокада "
    L"укључена, чувар екрана система Windows спречава се само док је на бар једном монитору видљива "
    L"анимација која није паузирана. Апликација може инсталирати и деинсталирати уграђени чувар "
    L"екрана.\r\n\r\nСНИМЦИ ЕКРАНА И СНИМАЊЕ\r\nУ подешавањима снимања изаберите Viewport или TV. Viewport "
    L"задржава димензије и учестаност монитора до 60 кадрова у секунди. TV нуди 1920 × 1080, 1440 × 1080 "
    L"или 1280 × 720 у односу 16:9, са 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) кадрова у секунди. "
    L"TV видео је прогресивни BT.709 ограниченог опсега с подузорковањем боје 4:2:0. Однос слике остаје "
    L"сачуван, а допунске траке су црне. OK чува опције за следећи снимак; Откажи или Esc одбацује "
    L"непотврђене измене. Прозори снимања, помоћи и информација не блокирају остале прозоре и могу се "
    L"минимизовати. Tab и Shift+Tab померају фокус, Enter активира фокусирано дугме, а Esc затвара активни "
    L"помоћни прозор.\r\n\r\nСИСТЕМСКИ ЗАХТЕВИ\r\nWindows 7–11 подржава све функције. За Windows Vista SP2 "
    L"морате инсталирати ажурирања KB971512 и KB2117917; MP4 снимање на Висти не ради. Потребан је Direct3D "
    L"11, а за MP4 и Media Foundation и H.264 кодер. Интерфејс и документација доступни су на 36 језика.",
    L"АНІМАЦІЯ ТА НАЛАШТУВАННЯ\r\nАпаратно прискорений політ між мінливими поверхнями. Політ між чотирма "
    L"мінливими поверхнями; Політ крізь мінливу лійку. Для кожного монітора виберіть рівно одну анімацію. "
    L"Текстура перемикає текстуровану поверхню та каркасну модель. Вільне обертання камери повільно змінює "
    L"напрямок погляду в усіх трьох вимірах. Паузи та зміни напрямку додають випадкові уповільнення, паузи "
    L"та зміни напрямку обертання; політ уперед триває. Швидкість — 0–1600%. Кожен монітор має незалежну "
    L"випадкову сцену з виведенням відповідно до власної частоти оновлення. Основне, заповнювальне, фонове "
    L"та контурне світло можна незалежно перемикати для вибраних моніторів. Освітлення діє лише на "
    L"текстурованих поверхнях.\r\n\r\nМОНІТОРИ\r\nВиберіть один або кілька рядків у списку моніторів. "
    L"Ctrl+A вибирає всі; Ctrl і Shift змінюють вибір. Елементи керування й повзунки анімації змінюють лише "
    L"налаштування вибраних моніторів. Вибір рядка та ввімкнення виведення його прапорцем — різні дії. "
    L"Вибір зберігається окремо для програми й заставки. Якщо раніше були вибрані всі монітори, до вибору "
    L"долучаються й новопідключені. Різні значення на вибраних моніторах позначаються невизначеним станом "
    L"прапорців і крапковим візерунком на перемикачах, ручках повзунків і кнопках увімкнення або вимкнення "
    L"всіх параметрів. Підписи повзунків показують тире замість спільного значення. Зміна параметра або "
    L"натискання на повзунок застосовує це значення до всіх вибраних "
    L"моніторів.\r\n\r\nКЕРУВАННЯ\r\nЗапустіть FlightCorridor.exe. Налаштування зберігаються постійно, "
    L"працює лише один екземпляр програми. Прапорець монітора або подвійне клацання рядка вмикає чи вимикає "
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
    L"АНИМАЦИЯ И НАСТРОЙКИ\r\nАппаратно ускоренный полёт между меняющимися поверхностями. Полёт между "
    L"четырьмя меняющимися поверхностями; Полёт сквозь меняющуюся воронку. Для каждого монитора выберите "
    L"ровно одну анимацию. Текстура переключает текстурированную поверхность и каркасную модель. Свободное "
    L"вращение камеры медленно меняет направление взгляда во всех трёх измерениях. Паузы и смены "
    L"направления добавляют случайные замедления, паузы и изменения направления вращения; полёт вперёд "
    L"продолжается. Скорость — 0–1600%. Каждый монитор имеет независимую случайную сцену с выводом согласно "
    L"собственной частоте обновления. Основной, заполняющий, фоновый и контурный свет можно независимо "
    L"переключать для выбранных мониторов. Освещение применяется только к текстурированным "
    L"поверхностям.\r\n\r\nМОНИТОРЫ\r\nВыберите одну или несколько строк в списке мониторов. Ctrl+A "
    L"выбирает все; Ctrl и Shift изменяют выбор. Элементы управления и ползунки анимации изменяют только "
    L"настройки выбранных мониторов. Выбор строки и включение вывода её флажком — разные действия. Выбор "
    L"сохраняется отдельно для приложения и заставки. Если раньше были выбраны все мониторы, в выбор "
    L"включаются и вновь подключённые. Разные значения на выбранных мониторах обозначаются неопределённым "
    L"состоянием флажков и точечным узором на переключателях, ручках ползунков и кнопках включения или "
    L"выключения всех параметров. Подписи ползунков показывают тире вместо общего значения. Изменение "
    L"параметра или нажатие на ползунок применяет это значение ко всем выбранным "
    L"мониторам.\r\n\r\nУПРАВЛЕНИЕ\r\nЗапустите FlightCorridor.exe. Настройки сохраняются постоянно, "
    L"работает только один экземпляр приложения. Флажок монитора или двойной щелчок по строке включает либо "
    L"выключает вывод анимации. Анимацию можно приостановить и продолжить. PNG и MP4 захватывают первый "
    L"активный монитор анимации, а не общее изображение всех мониторов. Записываемый монитор нельзя "
    L"отключить; закрытие приложения во время записи требует подтверждения. Пауза и блокировка заставки "
    L"действуют для всего приложения независимо от выбора мониторов. Если блокировка включена, заставка "
    L"Windows не запускается только пока хотя бы на одном мониторе видима неприостановленная анимация. "
    L"Приложение может установить или удалить встроенную заставку.\r\n\r\nСНИМКИ ЭКРАНА И ЗАПИСЬ\r\nВ "
    L"настройках записи выберите Viewport или TV. Viewport сохраняет размеры и частоту монитора до 60 "
    L"кадров в секунду. TV предлагает 1920 × 1080, 1440 × 1080 или 1280 × 720 с соотношением 16:9 и "
    L"частотой 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) кадров в секунду. Видео TV прогрессивное, "
    L"BT.709, с ограниченным диапазоном и субдискретизацией цвета 4:2:0. Пропорции сохраняются, полосы "
    L"заполнения чёрные. OK сохраняет выбор для следующей записи; Отмена или Esc отклоняет неподтверждённые "
    L"изменения. Окна записи, справки и сведений не блокируют другие окна и могут сворачиваться. Tab и "
    L"Shift+Tab перемещают фокус, Enter активирует кнопку с фокусом, Esc закрывает активное вспомогательное "
    L"окно.\r\n\r\nСИСТЕМНЫЕ ТРЕБОВАНИЯ\r\nWindows 7–11 поддерживает все функции. Для Windows Vista SP2 "
    L"необходимо установить обновления KB971512 и KB2117917; запись MP4 в Vista не работает. Нужна "
    L"поддержка Direct3D 11, а для MP4 также Media Foundation и кодировщик H.264. Интерфейс и документация "
    L"доступны на 36 языках."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> SCREEN_SAVER_HELP_TEXTS = {
    L"ANIMACE A NASTAVENÍ\r\nFlightCorridor: Průlet čtyřmi proměnlivými plochami; Průlet proměnlivým "
    L"trychtýřem. Každému monitoru přiřaďte právě jednu animaci. Textura přepíná mezi texturovanými "
    L"plochami a drátěným modelem. Volná rotace kamery pomalu mění směr pohledu ve všech třech rozměrech. "
    L"Volba „Pauzy a obraty“ přidává náhodné zpomalování, pauzy a změny směru otáčení; dopředný pohyb "
    L"pokračuje. Rychlost animace je 0–1600 %. Každý monitor má nezávislou náhodnou scénu a vykreslování "
    L"podle své obnovovací frekvence. Hlavní světlo, doplňkové světlo, základní jas a přisvětlení obrysů "
    L"lze pro označené monitory zapínat nezávisle. Osvětlení se používá jen u texturovaných "
    L"ploch.\r\n\r\nMONITORY\r\nOznačení řádků určuje, které monitory právě nastavujete; není totožné se "
    L"zatržítky zapínajícími animační výstupy. Ctrl+A označí všechny monitory, Ctrl a Shift umožňují "
    L"upravit označení. Všechny animační volby a jezdce platí pro označené monitory. Označení se pamatuje "
    L"zvlášť pro EXE a SCR. Pokud byly označené všechny monitory, označí se i nově připojené. Různé hodnoty "
    L"na označených monitorech ukazuje neurčitý stav zatržítek a tečkování přepínačů, úchytů jezdců a "
    L"tlačítek pro zapnutí či vypnutí všech voleb. Popisek jezdce místo společné hodnoty zobrazuje pomlčku. "
    L"Změna volby nebo kliknutí na jezdec sjednotí příslušnou hodnotu na označených "
    L"monitorech.\r\n\r\nNÁHLED A OVLÁDÁNÍ\r\nZapnout náhled spustí celoobrazovkový náhled na všech "
    L"monitorech; změny lze zkoušet za otevřeného nastavení. OK nastavení uloží, Storno je zahodí. "
    L"Celoobrazovkový spořič ukončíte klávesou Esc nebo pohybem myši. Mezi ovládacími prvky přecházejte "
    L"klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a příslušného písmene. Esc v "
    L"nastavení odpovídá tlačítku Storno; v nápovědě nebo okně O aplikaci zavře pouze toto "
    L"okno.\r\n\r\nSYSTÉMOVÉ POŽADAVKY\r\nPodporovány jsou systémy Windows 7 až Windows 11. Pro spuštění "
    L"aplikace ve Windows Vista SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917. Vykreslování "
    L"vyžaduje Direct3D 11, nikoli jen starší DirectX runtime.",
    L"ANIMATION AND SETTINGS\r\nFlightCorridor: Flight between four morphing surfaces; Flight through a "
    L"morphing funnel. Assign exactly one animation to each display. Texture switches between textured "
    L"surfaces and wireframe. Free camera rotation slowly changes the viewing direction in all three "
    L"dimensions. The Pauses and reversals option adds randomized braking, pauses, and reversals of the "
    L"rotation; forward flight continues. Animation speed ranges from 0–1600%. Every display has an "
    L"independent randomized scene rendered at its own refresh rate. Main light, fill light, ambient light, "
    L"and rim light can be switched independently for the selected displays. Lighting applies only to "
    L"textured surfaces.\r\n\r\nDISPLAYS\r\nRow selection determines which displays you are editing; it is "
    L"separate from the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and "
    L"Shift adjust the selection. All animation options and sliders apply to the selected displays. The "
    L"selection is remembered separately for EXE and SCR. If all displays were selected, newly connected "
    L"displays join the selection. Different values across selected displays are indicated by indeterminate "
    L"checkboxes and dotted radio buttons, slider thumbs, and buttons for enabling or disabling all "
    L"options. Slider labels show a dash instead of a shared value. Changing an option or clicking a slider "
    L"applies that value to all selected displays.\r\n\r\nPREVIEW AND CONTROLS\r\nEnable preview starts a "
    L"full-screen preview on every display while the settings dialog remains open for live adjustments. OK "
    L"saves the settings and Cancel discards them. Exit the full-screen saver with Esc or mouse movement. "
    L"Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a "
    L"command. Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes only that "
    L"window.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows 7 through Windows 11 are supported. To run the "
    L"application on Windows Vista SP2, you must install updates KB971512 and KB2117917. Rendering requires "
    L"Direct3D 11, not just an older DirectX runtime.",
    L"ANIMATION AND SETTINGS\r\nFlightCorridor: Flight between four morphing surfaces; Flight through a "
    L"morphing funnel. Assign exactly one animation to each display. Texture switches between textured "
    L"surfaces and wireframe. Free camera rotation slowly changes the viewing direction in all three "
    L"dimensions. The Pauses and reversals option adds randomised braking, pauses and reversals of the "
    L"rotation; forward flight continues. Animation speed ranges from 0–1600%. Every display has an "
    L"independent randomised scene rendered at its own refresh rate. Main light, fill light, ambient light "
    L"and rim light can be switched independently for the selected displays. Lighting applies only to "
    L"textured surfaces.\r\n\r\nDISPLAYS\r\nRow selection determines which displays you are editing; it is "
    L"separate from the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and "
    L"Shift adjust the selection. All animation options and sliders apply to the selected displays. The "
    L"selection is remembered separately for EXE and SCR. If all displays were selected, newly connected "
    L"displays join the selection. Different values across selected displays are indicated by indeterminate "
    L"checkboxes and dotted radio buttons, slider thumbs and buttons for enabling or disabling all options. "
    L"Slider labels show a dash instead of a shared value. Changing an option or clicking a slider applies "
    L"that value to all selected displays.\r\n\r\nPREVIEW AND CONTROLS\r\nEnable preview starts a "
    L"full-screen preview on every display and allows live adjustments while the settings dialog remains "
    L"open. OK saves the settings and Cancel discards them. Exit the full-screen screen saver with Esc or "
    L"mouse movement. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to "
    L"activate a command. Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes "
    L"only that window.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows 7 through Windows 11 are supported. To run "
    L"the application on Windows Vista SP2, you must install updates KB971512 and KB2117917. Rendering "
    L"requires Direct3D 11, not just an older DirectX runtime.",
    L"ANIMATION AND SETTINGS\r\nFlightCorridor: Flight between four morphing surfaces; Flight through a "
    L"morphing funnel. Assign exactly one animation to each display. Texture switches between textured "
    L"surfaces and wireframe. Free camera rotation slowly changes the viewing direction in all three "
    L"dimensions. The Pauses and reversals option adds randomised braking, pauses and reversals of the "
    L"rotation; forward flight continues. Animation speed ranges from 0–1600%. Every display has an "
    L"independent randomised scene rendered at its own refresh rate. Main light, fill light, ambient light "
    L"and rim light can be switched independently for the selected displays. Lighting applies only to "
    L"textured surfaces.\r\n\r\nDISPLAYS\r\nRow selection determines which displays you are editing; it is "
    L"separate from the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and "
    L"Shift adjust the selection. All animation options and sliders apply to the selected displays. The "
    L"selection is remembered separately for EXE and SCR. If all displays were selected, newly connected "
    L"displays join the selection. Different values across selected displays are indicated by indeterminate "
    L"checkboxes and dotted radio buttons, slider thumbs and buttons for enabling or disabling all options. "
    L"Slider labels show a dash instead of a shared value. Changing an option or clicking a slider applies "
    L"that value to all selected displays.\r\n\r\nPREVIEW AND CONTROLS\r\nEnable preview starts a "
    L"full-screen preview on every display and allows live adjustments while the settings dialog remains "
    L"open. OK saves the settings and Cancel discards them. Exit the full-screen screen saver with Esc or "
    L"mouse movement. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to "
    L"activate a command. Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes "
    L"only that window.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows 7 through Windows 11 are supported. To run "
    L"the application on Windows Vista SP2, you must install updates KB971512 and KB2117917. Rendering "
    L"requires Direct3D 11, not just an older DirectX runtime.",
    L"ANIMATION UND EINSTELLUNGEN\r\nFlightCorridor: Flug zwischen vier veränderlichen Flächen; Flug durch "
    L"einen veränderlichen Trichter. Weisen Sie jedem Monitor genau eine Animation zu. Textur wechselt "
    L"zwischen texturierten Flächen und Drahtgittermodell. Die freie Kameradrehung verändert die "
    L"Blickrichtung langsam in allen drei Dimensionen. Die Option „Pausen und Umkehr“ ergänzt zufälliges "
    L"Abbremsen, Pausen und Wechsel der Drehrichtung; der Vorwärtsflug läuft weiter. Die "
    L"Animationsgeschwindigkeit beträgt 0–1600 %. Jeder Monitor besitzt eine unabhängige zufällige Szene "
    L"und wird mit seiner eigenen Bildwiederholrate angesteuert. Hauptlicht, Fülllicht, Umgebungslicht und "
    L"Konturlicht lassen sich für die ausgewählten Monitore unabhängig schalten. Die Beleuchtung gilt nur "
    L"für texturierte Flächen.\r\n\r\nMONITORE\r\nDie Zeilenauswahl bestimmt, welche Monitore Sie "
    L"bearbeiten; sie ist von den Kontrollkästchen zum Einschalten der Animationsausgabe getrennt. Strg+A "
    L"wählt alle Monitore, Strg und Umschalt ändern die Auswahl. Alle Animationsoptionen und Regler gelten "
    L"für die ausgewählten Monitore. Die Auswahl wird für EXE und SCR getrennt gespeichert. Waren alle "
    L"Monitore ausgewählt, werden auch neu angeschlossene ausgewählt. Unterschiedliche Werte der "
    L"ausgewählten Monitore werden durch unbestimmte Kontrollkästchen und gepunktete Optionsfelder, "
    L"Reglergriffe sowie Schaltflächen zum Ein- oder Ausschalten aller Optionen angezeigt. "
    L"Reglerbeschriftungen zeigen statt eines gemeinsamen Werts einen Gedankenstrich. Das Ändern einer "
    L"Option oder Anklicken eines Reglers übernimmt diesen Wert für alle ausgewählten "
    L"Monitore.\r\n\r\nVORSCHAU UND BEDIENUNG\r\nVorschau einschalten startet eine Vollbildvorschau auf "
    L"allen Monitoren. Der Einstellungsdialog bleibt für Änderungen geöffnet. OK speichert, Abbrechen "
    L"verwirft. Esc oder eine Mausbewegung beendet den Vollbildschoner. Mit Tab und Umschalt+Tab wechseln "
    L"Sie zwischen den Steuerelementen; mit Alt und dem unterstrichenen Buchstaben rufen Sie einen Befehl "
    L"auf. Esc im Einstellungsdialog entspricht Abbrechen; in der Hilfe oder im Infofenster schließt es nur "
    L"dieses Fenster.\r\n\r\nSYSTEMANFORDERUNGEN\r\nUnterstützt werden Windows 7 bis Windows 11. Zum "
    L"Ausführen der Anwendung unter Windows Vista SP2 müssen die Updates KB971512 und KB2117917 installiert "
    L"werden. Die Darstellung erfordert Direct3D 11, nicht nur eine ältere DirectX-Laufzeitumgebung.",
    L"ANIMATION ET PARAMÈTRES\r\nFlightCorridor: Vol entre quatre surfaces déformables; Vol dans un "
    L"entonnoir déformable. Attribuez une seule animation à chaque écran. Texture alterne entre surfaces "
    L"texturées et modèle filaire. La rotation libre de la caméra change lentement la direction du regard "
    L"dans les trois dimensions. L’option « Pauses et inversions » ajoute des ralentissements, pauses et "
    L"inversions aléatoires de la rotation ; le vol vers l’avant continue. La vitesse va de 0 à 1600 %. "
    L"Chaque écran possède une scène aléatoire indépendante, rendue à sa propre fréquence de "
    L"rafraîchissement. La lumière principale, la lumière d’appoint, l’éclairage ambiant et l’éclairage des "
    L"contours se règlent indépendamment pour les écrans sélectionnés. L’éclairage ne concerne que les "
    L"surfaces texturées.\r\n\r\nÉCRANS\r\nLa sélection des lignes détermine les écrans à configurer ; elle "
    L"est distincte des cases qui activent les sorties d’animation. Ctrl+A sélectionne tous les écrans ; "
    L"Ctrl et Maj modifient la sélection. Toutes les options et tous les curseurs d’animation concernent "
    L"les écrans sélectionnés. La sélection est mémorisée séparément pour EXE et SCR. Si tous les écrans "
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
    L"ANIMACIÓN Y AJUSTES\r\nFlightCorridor: Vuelo entre cuatro superficies deformables; Vuelo por un "
    L"embudo deformable. Asigne una sola animación a cada pantalla. Textura alterna entre superficies "
    L"texturizadas y modelo de alambre. El giro libre de la cámara cambia lentamente la dirección de la "
    L"vista en las tres dimensiones. La opción «Pausas e inversiones» añade frenadas, pausas e inversiones "
    L"aleatorias del giro; el vuelo hacia delante continúa. La velocidad va del 0 al 1600 %. Cada pantalla "
    L"tiene una escena aleatoria independiente y se renderiza a su propia frecuencia de actualización. La "
    L"luz principal, la luz de relleno, la luz ambiental y la iluminación de contornos se activan por "
    L"separado para las pantallas seleccionadas. La iluminación solo se aplica a las superficies "
    L"texturizadas.\r\n\r\nMONITORES\r\nLa selección de filas determina qué pantallas se están "
    L"configurando; es independiente de las casillas que activan las salidas de animación. Ctrl+A "
    L"selecciona todas; Ctrl y Mayús modifican la selección. Todas las opciones y los controles deslizantes "
    L"de animación se aplican a las pantallas seleccionadas. La selección se recuerda por separado para EXE "
    L"y SCR. Si estaban seleccionadas todas, se incluyen también las nuevas. Los valores distintos entre "
    L"las pantallas seleccionadas se indican mediante casillas indeterminadas y un punteado en los botones "
    L"de opción, los tiradores de los controles deslizantes y los botones para activar o desactivar todas "
    L"las opciones. Las etiquetas de los controles deslizantes muestran una raya en lugar de un valor "
    L"común. Cambiar una opción o hacer clic en un control deslizante aplica ese valor a todas las "
    L"pantallas seleccionadas.\r\n\r\nVISTA PREVIA Y CONTROLES\r\nActivar vista previa inicia una vista "
    L"previa a pantalla completa en todos los monitores; el cuadro de configuración permanece abierto para "
    L"realizar ajustes en tiempo real. Aceptar guarda y Cancelar descarta. Esc o mover el ratón cierra el "
    L"salvapantallas completo. Use Tab y Mayús+Tab para desplazarse entre controles; Alt y la letra "
    L"subrayada activan una opción. Esc en la configuración equivale a Cancelar; en Ayuda o Acerca de, "
    L"cierra únicamente esa ventana.\r\n\r\nREQUISITOS DEL SISTEMA\r\nSe admiten Windows 7 a Windows 11. "
    L"Para ejecutar la aplicación en Windows Vista SP2, es necesario instalar las actualizaciones KB971512 "
    L"y KB2117917. La representación requiere Direct3D 11, no solo un entorno de ejecución antiguo de "
    L"DirectX.",
    L"ANIMAZIONE E IMPOSTAZIONI\r\nFlightCorridor: Volo tra quattro superfici deformabili; Volo attraverso "
    L"un imbuto deformabile. Assegnare una sola animazione a ogni schermo. Texture alterna superfici con "
    L"texture e modello a reticolo. La rotazione libera della telecamera cambia lentamente la direzione "
    L"dello sguardo nelle tre dimensioni. L’opzione «Pause e inversioni» aggiunge rallentamenti, pause e "
    L"inversioni casuali della rotazione; il volo in avanti continua. La velocità va da 0 a 1600%. Ogni "
    L"schermo ha una scena casuale indipendente, renderizzata alla propria frequenza di aggiornamento. La "
    L"luce principale, la luce di riempimento, la luce ambientale e l’illuminazione dei contorni si "
    L"attivano separatamente per gli schermi selezionati. L’illuminazione si applica solo alle superfici "
    L"con texture.\r\n\r\nMONITOR\r\nLa selezione delle righe determina quali schermi si stanno "
    L"configurando ed è distinta dalle caselle che attivano le uscite di animazione. Ctrl+A seleziona tutti "
    L"gli schermi; Ctrl e Maiusc modificano la selezione. Tutte le opzioni e i cursori dell’animazione "
    L"riguardano gli schermi selezionati. La selezione viene memorizzata separatamente per EXE e SCR. Se "
    L"erano selezionati tutti gli schermi, vengono inclusi anche quelli nuovi. Valori diversi tra gli "
    L"schermi selezionati sono indicati da caselle di controllo indeterminate e da una trama a punti sui "
    L"pulsanti di opzione, sulle maniglie dei cursori e sui pulsanti per attivare o disattivare tutte le "
    L"opzioni. Le etichette dei cursori mostrano un trattino al posto di un valore comune. Modificare "
    L"un’opzione o fare clic su un cursore applica quel valore a tutti gli schermi "
    L"selezionati.\r\n\r\nANTEPRIMA E COMANDI\r\nAttiva anteprima avvia un’anteprima a schermo intero su "
    L"tutti i monitor; le impostazioni rimangono aperte per le modifiche in tempo reale. OK salva e Annulla "
    L"scarta. Esc o il movimento del mouse chiude il salvaschermo a schermo intero. Usare Tab e Maiusc+Tab "
    L"per passare tra i controlli; Alt e la lettera sottolineata attivano un comando. Esc nelle "
    L"impostazioni equivale ad Annulla; nella Guida o nelle Informazioni, chiude solo quella "
    L"finestra.\r\n\r\nREQUISITI DI SISTEMA\r\nSono supportati i sistemi da Windows 7 a Windows 11. Per "
    L"eseguire l’applicazione su Windows Vista SP2, è necessario installare gli aggiornamenti KB971512 e "
    L"KB2117917. La visualizzazione richiede Direct3D 11, non soltanto un vecchio runtime DirectX.",
    L"ANIMAÇÃO E DEFINIÇÕES\r\nFlightCorridor: Voo entre quatro superfícies deformáveis; Voo através de um "
    L"funil deformável. Atribua uma única animação a cada ecrã. Textura alterna entre superfícies "
    L"texturadas e modelo em arame. A rotação livre da câmara muda lentamente a direção da vista nas três "
    L"dimensões. A opção «Pausas e inversões» acrescenta desacelerações, pausas e inversões aleatórias da "
    L"rotação; o voo para a frente continua. A velocidade vai de 0 a 1600%. Cada ecrã tem uma cena "
    L"aleatória independente, apresentada à sua própria frequência de atualização. A luz principal, a luz "
    L"de preenchimento, a luz ambiente e a iluminação dos contornos podem ser ativadas separadamente nos "
    L"monitores selecionados. A iluminação aplica-se apenas às superfícies com "
    L"textura.\r\n\r\nMONITORES\r\nA seleção das linhas determina os ecrãs a configurar e é independente "
    L"das caixas que ativam as saídas de animação. Ctrl+A seleciona todos os ecrãs; Ctrl e Shift alteram a "
    L"seleção. Todas as opções e controlos deslizantes da animação aplicam-se aos ecrãs selecionados. A "
    L"seleção é guardada separadamente para EXE e SCR. Se todos estavam selecionados, os novos ecrãs também "
    L"são incluídos. Valores diferentes entre os ecrãs selecionados são indicados por caixas de verificação "
    L"indeterminadas e por um padrão pontilhado nos botões de opção, nas pegas dos controlos deslizantes e "
    L"nos botões para ativar ou desativar todas as opções. As etiquetas dos controlos deslizantes "
    L"apresentam um travessão em vez de um valor comum. Alterar uma opção ou clicar num controlo deslizante "
    L"aplica esse valor a todos os ecrãs selecionados.\r\n\r\nPRÉ-VISUALIZAÇÃO E CONTROLOS\r\nAtivar "
    L"pré-visualização inicia uma pré-visualização em ecrã inteiro em todos os monitores e permite ajustes "
    L"em tempo real. OK guarda as definições e Cancelar descarta-as. Esc ou o movimento do rato termina a "
    L"proteção em ecrã inteiro. Use Tab e Shift+Tab para passar entre controlos; Alt e a letra sublinhada "
    L"ativam um comando. Esc nas definições equivale a Cancelar; na Ajuda ou em Acerca de, fecha apenas "
    L"essa janela.\r\n\r\nREQUISITOS DO SISTEMA\r\nSão suportados os sistemas Windows 7 a Windows 11. Para "
    L"executar a aplicação no Windows Vista SP2, é necessário instalar as atualizações KB971512 e "
    L"KB2117917. A apresentação requer Direct3D 11, não apenas um runtime DirectX mais antigo.",
    L"ANIMACJA I USTAWIENIA\r\nFlightCorridor: Przelot między czterema zmiennymi powierzchniami; Przelot "
    L"przez zmienny lejek. Każdemu monitorowi przypisz dokładnie jedną animację. Tekstura przełącza "
    L"powierzchnie z teksturą i model szkieletowy. Swobodne obracanie kamery powoli zmienia kierunek widoku "
    L"we wszystkich trzech wymiarach. Przerwy i nawroty dodają losowe zwalnianie, pauzy i odwracanie "
    L"obrotu; lot do przodu trwa nadal. Prędkość wynosi 0–1600%. Każdy monitor ma niezależną losową scenę "
    L"wyświetlaną z własną częstotliwością odświeżania. Światło główne, światło wypełniające, światło "
    L"otoczenia i oświetlenie konturów można przełączać niezależnie dla zaznaczonych monitorów. Oświetlenie "
    L"dotyczy tylko powierzchni z teksturą.\r\n\r\nMONITORY\r\nZaznaczenie wierszy określa konfigurowane "
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
    L"ANIMÁCIA A NASTAVENIA\r\nFlightCorridor: Prelet štyrmi premenlivými plochami; Prelet premenlivým "
    L"lievikom. Každému monitoru priraďte práve jednu animáciu. Textúra prepína medzi textúrovanými "
    L"plochami a drôteným modelom. Voľná rotácia kamery pomaly mení smer pohľadu vo všetkých troch "
    L"rozmeroch. Voľba „Pauzy a obraty“ pridáva náhodné spomaľovanie, prestávky a zmeny smeru otáčania; "
    L"dopredný pohyb pokračuje. Rýchlosť je 0–1600 %. Každý monitor má nezávislú náhodnú scénu vykresľovanú "
    L"podľa vlastnej obnovovacej frekvencie. Hlavné svetlo, doplnkové svetlo, základný jas a prisvetlenie "
    L"obrysov možno pre označené monitory zapínať nezávisle. Osvetlenie sa používa len pri textúrovaných "
    L"plochách.\r\n\r\nMONITORY\r\nOznačenie riadkov určuje, ktoré monitory práve nastavujete; je nezávislé "
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
    L"ANIMATION OG INDSTILLINGER\r\nFlightCorridor: Flyvetur mellem fire formskiftende flader; Flyvetur "
    L"gennem en formskiftende tragt. Tildel præcis én animation til hver skærm. Tekstur skifter mellem "
    L"teksturerede flader og trådmodel. Frit roterende kamera ændrer langsomt synsretningen i alle tre "
    L"dimensioner. Pauser og vendinger tilføjer tilfældige opbremsninger, pauser og ændringer af "
    L"rotationsretningen; flyvningen fremad fortsætter. Hastigheden er 0–1600 %. Hver skærm har en "
    L"uafhængig tilfældig scene, der gengives med dens egen opdateringsfrekvens. Hovedlys, udfyldningslys, "
    L"omgivende lys og konturlys kan slås til og fra uafhængigt for de valgte skærme. Belysningen gælder "
    L"kun teksturerede overflader.\r\n\r\nSKÆRME\r\nMarkeringen af rækker bestemmer, hvilke skærme du "
    L"indstiller, og er adskilt fra afkrydsningsfelterne, der aktiverer animationsoutput. Ctrl+A markerer "
    L"alle skærme; Ctrl og Skift ændrer markeringen. Alle animationsvalg og skydere gælder de markerede "
    L"skærme. Markeringen huskes separat for EXE og SCR. Hvis alle skærme var markeret, medtages også nye "
    L"skærme. Forskellige værdier på de markerede skærme vises med ubestemte afkrydsningsfelter og "
    L"prikmønstre på alternativknapper, skydergreb og knapper til at slå alle valg til eller fra. Skydernes "
    L"etiketter viser en tankestreg i stedet for en fælles værdi. Ændring af et valg eller klik på en "
    L"skyder anvender denne værdi på alle markerede skærme.\r\n\r\nFORHÅNDSVISNING OG BETJENING\r\nAktivér "
    L"forhåndsvisning starter en fuldskærmsvisning på alle skærme. Indstillingerne forbliver åbne, og "
    L"ændringerne vises med det samme. OK gemmer indstillingerne, og Annuller forkaster ændringerne. Esc "
    L"eller musebevægelse afslutter fuldskærmen. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; "
    L"Alt og det understregede bogstav aktiverer en kommando. Esc i indstillingerne svarer til Annuller; i "
    L"Hjælp eller Om lukker det kun dette vindue.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 "
    L"understøttes. For at køre programmet på Windows Vista SP2 skal opdateringerne KB971512 og KB2117917 "
    L"installeres. Visningen kræver Direct3D 11, ikke kun et ældre DirectX-kørselsmiljø.",
    L"ANIMAATIO JA ASETUKSET\r\nFlightCorridor: Lento neljän muuntuvan pinnan välissä; Lento muuntuvan "
    L"suppilon läpi. Valitse kullekin näytölle yksi animaatio. Tekstuuri vaihtaa teksturoitujen pintojen ja "
    L"rautalankamallin välillä. Kameran vapaa pyörintä muuttaa katselusuuntaa hitaasti kaikissa kolmessa "
    L"ulottuvuudessa. Tauot ja suunnanvaihdot lisäävät satunnaisia hidastuksia, taukoja ja pyörimissuunnan "
    L"vaihtoja; lento eteenpäin jatkuu. Nopeus on 0–1600%. Jokaisella näytöllä on itsenäinen satunnainen "
    L"näkymä, joka piirretään sen omalla virkistystaajuudella. Päävalo, täytevalo, ympäristövalo ja "
    L"reunavalo voidaan kytkeä erikseen valituille näytöille. Valaistus koskee vain teksturoituja "
    L"pintoja.\r\n\r\nNÄYTÖT\r\nRivien valinta määrää muokattavat näytöt ja on erillinen animaatioulostulon "
    L"valintaruuduista. Ctrl+A valitsee kaikki näytöt; Ctrl ja Vaihto muuttavat valintaa. Kaikki "
    L"animaatioasetukset ja liukusäätimet koskevat valittuja näyttöjä. Valinta muistetaan erikseen EXE- ja "
    L"SCR-tiloissa. Jos kaikki näytöt olivat valittuina, myös uudet näytöt valitaan. Valittujen näyttöjen "
    L"eri arvot ilmaistaan valintaruutujen määrittämättömällä tilalla sekä valintanappien, liukusäätimien "
    L"kahvojen ja kaikkien asetusten kytkentäpainikkeiden pistekuviolla. Liukusäätimen selitteessä näkyy "
    L"viiva yhteisen arvon sijasta. Asetuksen muuttaminen tai liukusäätimen napsauttaminen asettaa kyseisen "
    L"arvon kaikille valituille näytöille.\r\n\r\nESIKATSELU JA KÄYTTÖ\r\nOta esikatselu käyttöön "
    L"käynnistää koko näytön esikatselun kaikilla näytöillä. Asetusikkuna pysyy avoinna, ja muutokset "
    L"näkyvät heti. OK tallentaa asetukset ja Peruuta hylkää muutokset. Esc tai hiiren liike lopettaa koko "
    L"näytön säästäjän. Siirry säätimien välillä Tab- ja Vaihto+Tab-näppäimillä; Alt ja alleviivattu "
    L"kirjain aktivoivat komennon. Esc asetuksissa vastaa Peruuta-painiketta; Ohje- tai Tietoja-ikkunassa "
    L"se sulkee vain kyseisen ikkunan.\r\n\r\nJÄRJESTELMÄVAATIMUKSET\r\nTuettuja käyttöjärjestelmiä ovat "
    L"Windows 7–Windows 11. Sovelluksen suorittaminen Windows Vista SP2:ssa edellyttää päivitysten KB971512 "
    L"ja KB2117917 asentamista. Näyttäminen vaatii Direct3D 11:n, ei pelkästään vanhempaa "
    L"DirectX-ajoympäristöä.",
    L"HREYFIMYND OG STILLINGAR\r\nFlightCorridor: Flug milli fjögurra breytilegra flata; Flug í gegnum "
    L"breytilega trekt. Veldu nákvæmlega eina hreyfimynd fyrir hvern skjá. Áferð skiptir milli "
    L"áferðarlagðra flata og víragrindar. Frjáls snúningur myndavélar breytir sjónstefnunni hægt í öllum "
    L"þremur víddum. Valkosturinn „Hlé og stefnuskipti“ bætir við tilviljanakenndri hægingu, hléum og "
    L"breytingum á snúningsstefnu; flug áfram heldur áfram. Hraðinn er 0–1600%. Hver skjár hefur sjálfstæða "
    L"tilviljanakennda senu sem er teiknuð á eigin endurnýjunartíðni. Aðalljós, fylliljós, umhverfislýsing "
    L"og útlínulýsing eru stillt óháð hvert öðru fyrir valda skjái. Lýsingin á aðeins við um "
    L"áferðarfleti.\r\n\r\nSKJÁIR\r\nVal lína ákvarðar hvaða skjám er verið að breyta og er óháð "
    L"gátreitunum sem kveikja á hreyfimyndaúttaki. Ctrl+A velur alla skjái; Ctrl og Shift breyta valinu. "
    L"Allir valkostir og sleðar hreyfimynda gilda fyrir valda skjái. Valið er munað sérstaklega fyrir EXE "
    L"og SCR. Ef allir skjáir voru valdir bætast nýir skjáir einnig við valið. Mismunandi gildi á völdum "
    L"skjám eru sýnd með óákveðnu ástandi gátreita og punktamynstri á valhnöppum, handföngum sleða og "
    L"hnöppum sem kveikja eða slökkva á öllum valkostum. Merking sleða sýnir strik í stað sameiginlegs "
    L"gildis. Að breyta valkosti eða smella á sleða setur það gildi á alla valda skjái.\r\n\r\nFORSKOÐUN OG "
    L"NOTKUN\r\nVirkja forskoðun ræsir forskoðun á öllum skjám. Stillingaglugginn helst opinn og breytingar "
    L"sjást strax. Í lagi vistar stillingar og Hætta við hafnar breytingum. Esc eða músarhreyfing lokar "
    L"skjáhvílu á öllum skjánum. Notaðu Tab og Shift+Tab til að færa þig milli stýrieininga; Alt og "
    L"undirstrikaður stafur virkja skipun. Esc í stillingum jafngildir Hætta við; í Hjálp eða Um lokar það "
    L"aðeins þeim glugga.\r\n\r\nKERFISKRÖFUR\r\nWindows 7 til Windows 11 eru studd. Til að keyra forritið "
    L"á Windows Vista SP2 þarf að setja upp uppfærslurnar KB971512 og KB2117917. Birting krefst Direct3D "
    L"11, ekki aðeins eldri DirectX-keyrsluumhverfis.",
    L"ANIMASJON OG INNSTILLINGER\r\nFlightCorridor: Flytur mellom fire formendrende flater; Flytur gjennom "
    L"en formendrende trakt. Tilordne nøyaktig én animasjon til hver skjerm. Tekstur veksler mellom "
    L"teksturerte flater og trådmodell. Fritt roterende kamera endrer synsretningen langsomt i alle tre "
    L"dimensjoner. Pauser og vendinger legger til tilfeldige oppbremsinger, pauser og endringer i "
    L"rotasjonsretningen; flyvningen fremover fortsetter. Hastigheten er 0–1600 %. Hver skjerm har en "
    L"uavhengig tilfeldig scene som gjengis ved dens egen oppdateringsfrekvens. Hovedlys, utfyllingslys, "
    L"omgivelseslys og konturlys kan slås av og på uavhengig for de valgte skjermene. Belysningen gjelder "
    L"bare teksturerte flater.\r\n\r\nSKJERMER\r\nMarkeringen av rader bestemmer hvilke skjermer du "
    L"redigerer, og er atskilt fra avkrysningsboksene som aktiverer animasjonsutgangen. Ctrl+A markerer "
    L"alle skjermer; Ctrl og Skift endrer markeringen. Alle animasjonsvalg og glidebrytere gjelder de "
    L"markerte skjermene. Markeringen huskes separat for EXE og SCR. Hvis alle skjermer var markert, "
    L"inkluderes også nye skjermer. Ulike verdier på de markerte skjermene vises med ubestemte "
    L"avkrysningsbokser og prikkmønster på alternativknapper, glidebryterhåndtak og knapper for å slå alle "
    L"valg av eller på. Glidebryteretiketter viser en tankestrek i stedet for en felles verdi. Endring av "
    L"et valg eller klikk på en glidebryter bruker denne verdien på alle markerte "
    L"skjermer.\r\n\r\nFORHÅNDSVISNING OG BETJENING\r\nSlå på forhåndsvisning starter en fullskjermsvisning "
    L"på alle skjermer. Innstillingene forblir åpne, og endringene vises fortløpende. OK lagrer "
    L"innstillingene og Avbryt forkaster dem. Esc eller musebevegelse avslutter fullskjermsvisningen. Bruk "
    L"Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en "
    L"kommando. Esc i innstillingene tilsvarer Avbryt; i Hjelp eller Om lukker det bare dette "
    L"vinduet.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 støttes. For å kjøre programmet på Windows "
    L"Vista SP2 må oppdateringene KB971512 og KB2117917 installeres. Visningen krever Direct3D 11, ikke "
    L"bare en eldre DirectX-kjøretid.",
    L"ANIMERING OCH INSTÄLLNINGAR\r\nFlightCorridor: Flygtur mellan fyra formföränderliga ytor; Flygtur "
    L"genom en formföränderlig tratt. Tilldela varje skärm exakt en animering. Textur växlar mellan "
    L"texturerade ytor och trådmodell. Fritt roterande kamera ändrar långsamt blickriktningen i alla tre "
    L"dimensioner. Pauser och vändningar lägger till slumpmässiga inbromsningar, pauser och byten av "
    L"rotationsriktning; flygningen framåt fortsätter. Hastigheten är 0–1600 %. Varje skärm har en "
    L"oberoende slumpmässig scen som återges med dess egen uppdateringsfrekvens. Huvudljus, fyllnadsljus, "
    L"omgivningsljus och konturljus kan slås på och av oberoende för de valda skärmarna. Belysningen gäller "
    L"bara texturerade ytor.\r\n\r\nBILDSKÄRMAR\r\nMarkeringen av rader avgör vilka skärmar du redigerar "
    L"och är skild från kryssrutorna som aktiverar animationsutgångarna. Ctrl+A markerar alla skärmar; Ctrl "
    L"och Skift ändrar markeringen. Alla animationsalternativ och reglage gäller de markerade skärmarna. "
    L"Markeringen sparas separat för EXE och SCR. Om alla skärmar var markerade inkluderas även nya "
    L"skärmar. Olika värden på de markerade skärmarna visas med obestämda kryssrutor och punktmönster på "
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
    L"ANİMASYON VE AYARLAR\r\nFlightCorridor: Biçim değiştiren dört yüzey arasında uçuş; Biçim değiştiren "
    L"bir huninin içinden uçuş. Her ekrana tam bir animasyon atayın. Doku, dokulu yüzeyler ile tel kafes "
    L"modeli arasında geçiş yapar. Serbest kamera dönüşü bakış yönünü üç boyutta yavaşça değiştirir. "
    L"Duraklama ve ters dönüş, dönüşe rastgele yavaşlamalar, duraklamalar ve ters yön değişimleri ekler; "
    L"ileri uçuş devam eder. Hız 0–1600% aralığındadır. Her ekranın kendi yenileme hızında çizilen bağımsız "
    L"rastgele bir sahnesi vardır. Ana ışık, dolgu ışığı, ortam ışığı ve kenar aydınlatması seçili ekranlar "
    L"için ayrı ayrı açılıp kapatılabilir. Aydınlatma yalnızca dokulu yüzeylere "
    L"uygulanır.\r\n\r\nEKRANLAR\r\nSatır seçimi, hangi ekranların düzenlendiğini belirler; animasyon "
    L"çıkışlarını açan onay kutularından ayrıdır. Ctrl+A tüm ekranları seçer; Ctrl ve Shift seçimi "
    L"değiştirir. Tüm animasyon seçenekleri ve kaydırıcılar seçili ekranlara uygulanır. Seçim EXE ve SCR "
    L"için ayrı saklanır. Tüm ekranlar seçiliyse sonradan bağlanan ekranlar da seçime katılır. Seçili "
    L"ekranlardaki farklı değerler, belirsiz durumdaki onay kutuları ve seçenek düğmelerinde, kaydırıcı "
    L"tutamaçlarında ve tüm seçenekleri açıp kapatan düğmelerde noktalı desenle gösterilir. Kaydırıcı "
    L"etiketleri ortak bir değer yerine çizgi gösterir. Bir seçeneği değiştirmek veya kaydırıcıya tıklamak "
    L"bu değeri tüm seçili ekranlara uygular.\r\n\r\nÖNİZLEME VE KULLANIM\r\nÖnizlemeyi etkinleştir tüm "
    L"monitörlerde tam ekran önizleme başlatır. Ayarlar penceresi açık kalır ve değişiklikler anında "
    L"görülür. Tamam ayarları kaydeder, İptal değişiklikleri iptal eder. Tam ekran koruyucudan Esc veya "
    L"fare hareketiyle çıkılır. Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf "
    L"bir komutu etkinleştirir. Ayarlarda Esc, İptal ile aynı işlevi görür; Yardım veya Hakkında "
    L"penceresinde yalnızca o pencereyi kapatır.\r\n\r\nSİSTEM GEREKSİNİMLERİ\r\nWindows 7 ile Windows 11 "
    L"arasındaki sürümler desteklenir. Uygulamayı Windows Vista SP2'de çalıştırmak için KB971512 ve "
    L"KB2117917 güncellemelerini yüklemeniz gerekir. Görüntüleme, yalnızca eski bir DirectX çalışma zamanı "
    L"değil, Direct3D 11 gerektirir.",
    L"ANIMATSIOON JA SÄTTED\r\nRiistvarakiirendusega lend muutuvate pindade vahel. Lend nelja muutuva pinna "
    L"vahel; Lend läbi muutuva lehtri. Valige igale kuvarile täpselt üks animatsioon. Tekstuuri märkeruut "
    L"vahetab tekstuuriga pinna ja traatmudeli vahel. Kaamera vaba pöörlemine muudab vaatesuunda aeglaselt "
    L"kõigis kolmes mõõtmes. Pausid ja pöördumised lisavad sellele juhuslikke aeglustusi, pause ja "
    L"pöörlemissuuna muutusi; edasilend jätkub. Kiirus on seatav vahemikus 0–1600%. Igal kuvaril on oma "
    L"sõltumatu juhuslik stseen ja värskendussagedusele vastav renderdus. Põhivalgust, täitevalgust, "
    L"ümbritsevat valgust ja kontuurivalgust saab valitud kuvaritel eraldi sisse ja välja lülitada. "
    L"Valgustus kehtib ainult tekstuuriga pindadele.\r\n\r\nKUVARID\r\nValige loendis üks või mitu "
    L"kuvaririda. Ctrl+A valib kõik read; Ctrl ja Shift võimaldavad valikut muuta. Animatsiooni juhtnupud "
    L"ja liugurid mõjutavad ainult valitud kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle "
    L"märkeruuduga väljundi lubamine on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja jaoks "
    L"eraldi meelde. Kui varem olid valitud kõik kuvarid, kaasatakse ka lisatud kuvarid. Valitud kuvarite "
    L"erinevaid väärtusi näitavad märkeruutude määramata olek ning raadionuppude, liugurite käepidemete ja "
    L"kõigi valikute lülitusnuppude punktimuster. Liuguri sildil on ühise väärtuse asemel kriips. Valiku "
    L"muutmine või liuguril klõpsamine määrab selle väärtuse kõigile valitud kuvaritele.\r\n\r\nEELVAADE JA "
    L"KASUTAMINE\r\nKäivitage FlightCorridor.scr Windowsi ekraanisäästjana. Selle sätted on rakenduse "
    L"omadest eraldi. Sätete eelvaade lubab täisekraanil animatsiooni jooksvalt muuta. OK salvestab "
    L"muudatused ning Loobu või Esc tühistab need. Täisekraanil ekraanisäästjast väljumiseks vajutage "
    L"klahvi või liigutage hiirt.\r\n\r\nSÜSTEEMINÕUDED\r\nWindows 7–11 toetab kõiki funktsioone. Windows "
    L"Vista SP2 jaoks tuleb paigaldada värskendused KB971512 ja KB2117917. Vaja on Direct3D 11 tuge.",
    L"BEOCHAN AGUS SOCRUITHE\r\nEitilt idir dromchlaí athraitheacha le luasghéarú crua-earraí. Eitilt idir "
    L"ceithre dhromchla athraitheacha; Eitilt trí thonnadóir athraitheach. Roghnaigh beochan amháin do gach "
    L"monatóir. Athraíonn Uigeacht idir dromchla uigeachtaithe agus samhail sreangfhráma. Rothlaíonn rothlú "
    L"saor an cheamara an radharc go mall sna trí thoise. Cuireann Sosanna agus aisiompuithe coscánú, "
    L"sosanna agus athruithe treo randamacha leis an rothlú; leanann an eitilt chun tosaigh. Tá luas "
    L"0–1600% ar fáil. Tá radharc randamach neamhspleách ag gach monatóir agus déantar rindreáil de réir a "
    L"ráta athnuachana féin. Is féidir an príomhsholas, an solas líonta, an solas comhthimpeallach agus an "
    L"solas imill a athrú go neamhspleách do na taispeántais roghnaithe. Ní bhaineann an soilsiú ach le "
    L"dromchlaí uigeachtaithe.\r\n\r\nTAISPEÁNTAIS\r\nRoghnaigh ró amháin nó níos mó sa liosta monatóirí. "
    L"Roghnaíonn Ctrl+A gach ró; úsáid Ctrl agus Shift chun an roghnú a athrú. Ní athraíonn rialuithe agus "
    L"sleamhnáin na beochana ach socruithe na monatóirí roghnaithe. Ní hionann ró a roghnú agus aschur an "
    L"mhonatóra a chumasú lena bhosca seiceála. Cuimhnítear an roghnú ar leith don fheidhmchlár agus don "
    L"spárálaí. Má bhí gach monatóir roghnaithe, cuirtear monatóirí nua leis an roghnú freisin. Léirítear "
    L"luachanna éagsúla ar na monatóirí roghnaithe le boscaí seiceála i staid neamhchinnte agus le patrún "
    L"poncanna ar chnaipí raidió, ar ghreimíní sleamhnán agus ar na cnaipí a chumasaíonn nó a "
    L"dhíchumasaíonn gach rogha. Taispeántar dais ar lipéad an tsleamhnáin in ionad luach coiteann. Nuair a "
    L"athraítear rogha nó a chliceáiltear sleamhnán, cuirtear an luach sin i bhfeidhm ar gach monatóir "
    L"roghnaithe.\r\n\r\nRÉAMHAMHARC AGUS RIALÚ\r\nÚsáid FlightCorridor.scr mar spárálaí scáileáin Windows. "
    L"Tá a shocruithe ar leith ó shocruithe an fheidhmchláir. Ceadaíonn an réamhamharc lánscáileáin "
    L"athruithe beo. Sábhálann OK agus cealaíonn Cealaigh nó Esc na hathruithe. Fág an spárálaí "
    L"lánscáileáin le heochair ar bith nó le gluaiseacht na luiche.\r\n\r\nRIACHTANAIS CHÓRAIS\r\nTacaíonn "
    L"Windows 7–11 leis na gnéithe uile. Ar Windows Vista SP2 ní mór nuashonruithe KB971512 agus KB2117917. "
    L"Teastaíonn tacaíocht Direct3D 11.",
    L"ANIMACIJA IR NUOSTATOS\r\nAparatine įranga spartinamas skrydis tarp kintančių paviršių. Skrydis tarp "
    L"keturių kintančių paviršių; Skrydis kintančiu piltuvu. Kiekvienam monitoriui pasirinkite vieną "
    L"animaciją. Tekstūros langelis perjungia tekstūruotą paviršių ir vielinį modelį. Laisvas kameros "
    L"sukimasis lėtai keičia žiūrėjimo kryptį visose trijose dimensijose. Pauzės ir apsisukimai prideda "
    L"atsitiktinį lėtėjimą, pauzes ir sukimosi krypties keitimą; skrydis pirmyn tęsiasi. Galimas 0–1600% "
    L"greitis. Kiekvienas monitorius turi nepriklausomą atsitiktinę sceną, atvaizduojamą jo atnaujinimo "
    L"dažniu. Pagrindinę, užpildančią, aplinkos ir kontūrinę šviesą galima atskirai įjungti pasirinktiems "
    L"ekranams. Apšvietimas taikomas tik tekstūruotiems paviršiams.\r\n\r\nMONITORIAI\r\nMonitorių sąraše "
    L"pasirinkite vieną ar kelias eilutes. Ctrl+A pasirenka visas, o Ctrl ir Shift leidžia keisti "
    L"pasirinkimą. Animacijos valdikliai ir slankikliai keičia tik pasirinktų monitorių nuostatas. Eilutės "
    L"pasirinkimas nėra tas pats, kas animacijos išvesties įjungimas jos žymimuoju langeliu. Pasirinkimas "
    L"atskirai įsimenamas programai ir užsklandai. Jei buvo pasirinkti visi monitoriai, į pasirinkimą "
    L"įtraukiami ir naujai prijungti monitoriai. Skirtingas pasirinktų monitorių reikšmes rodo neapibrėžta "
    L"žymimųjų langelių būsena ir taškinis raštas ant parinkčių mygtukų, slankiklių rankenėlių bei visų "
    L"parinkčių įjungimo ir išjungimo mygtukų. Slankiklių užrašuose vietoj bendros reikšmės rodomas "
    L"brūkšnys. Pakeitus parinktį arba spustelėjus slankiklį, ta reikšmė pritaikoma visiems pasirinktiems "
    L"monitoriams.\r\n\r\nPERŽIŪRA IR VALDYMAS\r\nNaudokite FlightCorridor.scr kaip Windows ekrano "
    L"užsklandą. Jos nuostatos atskiros nuo programos. Viso ekrano peržiūra leidžia jas keisti vykstant "
    L"animacijai. OK išsaugo, Atšaukti arba Esc atmeta pakeitimus. Užsklandą užbaikite klavišu arba "
    L"pajudindami pelę.\r\n\r\nSISTEMOS REIKALAVIMAI\r\nWindows 7–11 palaiko visas funkcijas. Windows Vista "
    L"SP2 būtina įdiegti naujinimus KB971512 ir KB2117917. Reikalingas Direct3D 11 palaikymas.",
    L"ANIMĀCIJA UN IESTATĪJUMI\r\nAparatūras paātrināts lidojums starp mainīgām virsmām. Lidojums starp "
    L"četrām mainīgām virsmām; Lidojums caur mainīgu piltuvi. Katram monitoram izvēlieties tieši vienu "
    L"animāciju. Tekstūras rūtiņa pārslēdz teksturētu virsmu un stiepļu modeli. Brīva kameras rotācija "
    L"lēnām maina skatiena virzienu visās trijās dimensijās. Pauzes un virzienmaiņa pievieno nejaušu "
    L"palēninājumu, pauzes un rotācijas virziena maiņu; lidojums uz priekšu turpinās. Pieejams ātrums "
    L"0–1600%. Katram monitoram ir neatkarīga nejauša aina, ko renderē tā atsvaidzināšanas frekvencē. "
    L"Pamata, aizpildošo, apkārtējo un kontūru gaismu atlasītajiem monitoriem var ieslēgt neatkarīgi. "
    L"Apgaismojums attiecas tikai uz teksturētām virsmām.\r\n\r\nMONITORI\r\nMonitoru sarakstā atlasiet "
    L"vienu vai vairākas rindas. Ctrl+A atlasa visas, bet Ctrl un Shift ļauj mainīt atlasi. Animācijas "
    L"vadīklas un slīdņi maina tikai atlasīto monitoru iestatījumus. Rindas atlasīšana nav tas pats, kas "
    L"animācijas izvades ieslēgšana ar izvēles rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un "
    L"ekrānsaudzētājam. Ja bija atlasīti visi monitori, atlasē iekļauj arī jaunpievienotos monitorus. "
    L"Atšķirīgas vērtības atlasītajos monitoros norāda nenoteikts izvēles rūtiņu stāvoklis un punktots "
    L"raksts uz radiopogām, slīdņu rokturiem un visu iespēju ieslēgšanas vai izslēgšanas pogām. Slīdņu "
    L"etiķetēs kopīgas vērtības vietā redzama domuzīme. Mainot iespēju vai noklikšķinot uz slīdņa, šī "
    L"vērtība tiek piemērota visiem atlasītajiem monitoriem.\r\n\r\nPRIEKŠSKATĪJUMS UN "
    L"LIETOŠANA\r\nIzmantojiet FlightCorridor.scr kā Windows ekrānsaudzētāju. Tā iestatījumi ir atsevišķi "
    L"no lietotnes. Pilnekrāna priekšskatījums ļauj tos mainīt animācijas darbības laikā. OK saglabā, "
    L"Atcelt vai Esc atmet izmaiņas. Pilnekrāna ekrānsaudzētāju aizveriet ar taustiņu vai peles "
    L"kustību.\r\n\r\nSISTĒMAS PRASĪBAS\r\nWindows 7–11 atbalsta visas funkcijas. Windows Vista SP2 "
    L"jāinstalē atjauninājumi KB971512 un KB2117917. Nepieciešams Direct3D 11 atbalsts.",
    L"ANIMÁCIÓ ÉS BEÁLLÍTÁSOK\r\nHardveresen gyorsított repülés változó felületek között. Repülés négy "
    L"változó felület között; Repülés változó tölcsérben. Monitoronként pontosan egy animáció választható. "
    L"A Textúra jelölőnégyzet a textúrázott felület és a drótváz között vált. A kamera szabad forgása "
    L"lassan változtatja a nézetet mindhárom dimenzióban. A Szünetek és irányváltás véletlenszerű "
    L"lassításokat, szüneteket és forgásirányváltásokat ad hozzá; az előrehaladás folytatódik. A sebesség "
    L"0–1600%. Minden monitor önálló véletlenszerű jelenetet kap, saját frissítési gyakoriságához igazodó "
    L"megjelenítéssel. A főfény, a derítőfény, a környezeti fény és a peremfény külön kapcsolható a "
    L"kijelölt monitorokon. A világítás csak a textúrázott felületekre "
    L"vonatkozik.\r\n\r\nMONITOROK\r\nJelöljön ki egy vagy több sort a monitorok listájában. A Ctrl+A "
    L"mindet kijelöli; a Ctrl és a Shift módosítja a kijelölést. Az animáció vezérlői és csúszkái csak a "
    L"kijelölt monitorok beállításait változtatják. A sor kijelölése és az animációs kimenet "
    L"jelölőnégyzetes engedélyezése külön művelet. A kijelölést az alkalmazás és a képernyőkímélő külön "
    L"megjegyzi. Ha korábban minden monitor ki volt jelölve, az újonnan csatlakoztatott monitorok is "
    L"bekerülnek a kijelölésbe. A kijelölt monitorok eltérő értékeit a jelölőnégyzetek határozatlan "
    L"állapota, valamint a választógombok, a csúszkafogantyúk és az összes beállítást be- vagy kikapcsoló "
    L"gombok pontozása jelzi. A csúszkák felirata közös érték helyett gondolatjelet mutat. Egy beállítás "
    L"módosítása vagy a csúszkára kattintás az adott értéket minden kijelölt monitorra "
    L"alkalmazza.\r\n\r\nELŐNÉZET ÉS KEZELÉS\r\nA FlightCorridor.scr Windows-képernyőkímélőként "
    L"használható, az alkalmazástól külön beállításokkal. A teljes képernyős előnézetben élőben "
    L"módosíthatók a beállítások. Az OK ment, a Mégse vagy Esc elveti a módosításokat. A teljes képernyős "
    L"képernyőkímélő billentyűvel vagy egérmozgással zárható be.\r\n\r\nRENDSZERKÖVETELMÉNYEK\r\nA Windows "
    L"7–11 minden funkciót támogat. Windows Vista SP2 alatt telepíteni kell a KB971512 és KB2117917. "
    L"Direct3D 11 támogatás szükséges.",
    L"ANIMAZZJONI U SETTINGS\r\nTitjira bejn uċuħ li jinbidlu aċċellerata bil-ħardwer. Titjira bejn erba’ "
    L"uċuħ li jinbidlu; Titjira f’lembut li jinbidel. Agħżel animazzjoni waħda biss għal kull moniter. "
    L"Nisġa taqleb bejn wiċċ b’nisġa u mudell bil-wireframe. Ir-rotazzjoni libera tal-kamera tbiddel "
    L"id-direzzjoni tal-ħarsa bil-mod fit-tliet dimensjonijiet. L-għażla Pawżi u bidliet fid-direzzjoni "
    L"żżid deċelerazzjonijiet, pawżi u treġġigħ lura tar-rotazzjoni b’mod każwali; it-titjira ’l quddiem "
    L"tkompli. Il-veloċità hija 0–1600%. Kull moniter għandu xena każwali indipendenti li tintwera bir-rata "
    L"ta’ aġġornament tiegħu. Id-dawl prinċipali, id-dawl ta’ mili, id-dawl ambjentali u d-dawl tal-kontorn "
    L"jistgħu jinxtegħlu separatament għall-iskrins magħżula. Id-dawl japplika biss għall-uċuħ "
    L"bit-tessut.\r\n\r\nSKRINS\r\nAgħżel ringiela waħda jew aktar fil-lista tal-moniters. Ctrl+A "
    L"jagħżilhom kollha; Ctrl u Shift ibiddlu l-għażla. Il-kontrolli u s-sliders tal-animazzjoni jibdlu "
    L"biss is-settings tal-moniters magħżula. L-għażla ta’ ringiela hija differenti mill-attivazzjoni "
    L"tal-output permezz tal-kaxxa tal-marka. L-għażla tinżamm separatament għall-applikazzjoni u "
    L"għall-iscreen saver. Jekk il-moniters kollha kienu magħżula, il-moniters ġodda jiddaħħlu wkoll "
    L"fl-għażla. Valuri differenti fuq il-moniters magħżula jintwerew bi stat indeterminat tal-kaxxi "
    L"tal-marka u b’disinn bit-tikek fuq il-buttuni tar-radju, il-manki tas-sliders u l-buttuni li jattivaw "
    L"jew jiddiżattivaw l-għażliet kollha. It-tikketti tas-sliders juru sing minflok valur komuni. Meta "
    L"tibdel għażla jew tikklikkja slider, dak il-valur jiġi applikat għall-moniters magħżula "
    L"kollha.\r\n\r\nPREVIŻJONI U KONTROLLI\r\nUża FlightCorridor.scr bħala screen saver ta’ Windows. "
    L"Is-settings tiegħu huma separati minn dawk tal-applikazzjoni. Il-previżjoni fuq skrin sħiħ "
    L"tippermetti bidliet waqt l-animazzjoni. OK isalva u Ikkanċella jew Esc jarmi l-bidliet. Oħroġ "
    L"mill-iscreen saver bi kwalunkwe tast jew billi ċċaqlaq il-maws.\r\n\r\nREKWIŻITI "
    L"TAS-SISTEMA\r\nWindows 7–11 jappoġġja l-funzjonijiet kollha. Fuq Windows Vista SP2 għandhom jiġu "
    L"installati l-aġġornamenti KB971512 u KB2117917. Huwa meħtieġ Direct3D 11.",
    L"ANIMATIE EN INSTELLINGEN\r\nHardwareversnelde vlucht tussen vervormende oppervlakken. Vlucht tussen "
    L"vier vervormende oppervlakken; Vlucht door een vervormende trechter. Kies precies één animatie per "
    L"beeldscherm. Textuur schakelt tussen een getextureerd oppervlak en een draadmodel. Vrije "
    L"camerarotatie verandert de kijkrichting langzaam in alle drie dimensies. De optie Pauzes en omkeren "
    L"voegt willekeurige vertragingen, pauzes en omkeringen van de rotatie toe; de voorwaartse vlucht gaat "
    L"door. De snelheid is instelbaar op 0–1600%. Elk beeldscherm heeft een onafhankelijke willekeurige "
    L"scène en wordt op zijn eigen vernieuwingsfrequentie aangestuurd. Hoofdlicht, invullicht, "
    L"omgevingslicht en randlicht kunnen onafhankelijk worden geschakeld voor de geselecteerde "
    L"beeldschermen. De verlichting geldt alleen voor oppervlakken met "
    L"textuur.\r\n\r\nBEELDSCHERMEN\r\nSelecteer één of meer beeldschermrijen in de lijst. Ctrl+A "
    L"selecteert alles; met Ctrl en Shift past u de selectie aan. Animatieknoppen en schuifregelaars "
    L"wijzigen alleen de instellingen van de geselecteerde beeldschermen. Een rij selecteren is iets anders "
    L"dan de animatie-uitvoer inschakelen met het selectievakje. De selectie wordt apart onthouden voor de "
    L"toepassing en de schermbeveiliging. Als alle beeldschermen waren geselecteerd, worden nieuw "
    L"aangesloten beeldschermen ook geselecteerd. Verschillende waarden op geselecteerde beeldschermen "
    L"worden aangegeven door selectievakjes in onbepaalde toestand en een stippelpatroon op keuzerondjes, "
    L"schuifknoppen en knoppen om alle opties in of uit te schakelen. De labels van schuifregelaars tonen "
    L"een streepje in plaats van een gemeenschappelijke waarde. Een optie wijzigen of op een schuifregelaar "
    L"klikken past die waarde toe op alle geselecteerde beeldschermen.\r\n\r\nVOORBEELD EN "
    L"BEDIENING\r\nGebruik FlightCorridor.scr als Windows-schermbeveiliging met eigen instellingen. Het "
    L"schermvullende voorbeeld laat live aanpassingen toe. OK slaat wijzigingen op; Annuleren of Esc "
    L"verwerpt ze. Sluit de schermvullende schermbeveiliging met een toets of een "
    L"muisbeweging.\r\n\r\nSYSTEEMVEREISTEN\r\nWindows 7–11 ondersteunt alle functies. Voor Windows Vista "
    L"SP2 moet u updates KB971512 en KB2117917. Direct3D 11-ondersteuning is vereist.",
    L"ANIMAȚIE ȘI SETĂRI\r\nZbor între suprafețe deformabile accelerat hardware. Zbor între patru suprafețe "
    L"deformabile; Zbor printr-o pâlnie deformabilă. Alegeți exact o animație pentru fiecare monitor. "
    L"Textură comută între suprafața texturată și modelul de sârmă. Rotirea liberă a camerei schimbă lent "
    L"direcția privirii în toate cele trei dimensiuni. Pauze și inversări adaugă încetiniri, pauze și "
    L"inversări ale rotației la intervale aleatorii; zborul înainte continuă. Viteza este 0–1600%. Fiecare "
    L"monitor are o scenă aleatorie independentă, randată la propria rată de reîmprospătare. Lumina "
    L"principală, lumina de umplere, lumina ambiantă și lumina de contur pot fi comutate separat pentru "
    L"ecranele selectate. Iluminarea se aplică doar suprafețelor texturate.\r\n\r\nMONITOARE\r\nSelectați "
    L"unul sau mai multe rânduri din lista monitoarelor. Ctrl+A le selectează pe toate; Ctrl și Shift "
    L"modifică selecția. Comenzile și glisoarele animației schimbă numai setările monitoarelor selectate. "
    L"Selectarea unui rând diferă de activarea ieșirii prin caseta sa de selectare. Selecția este reținută "
    L"separat pentru aplicație și economizor. Dacă erau selectate toate monitoarele, sunt incluse și cele "
    L"conectate ulterior. Valorile diferite de pe monitoarele selectate sunt indicate prin starea "
    L"nedeterminată a casetelor de selectare și un model punctat pe butoanele radio, mânerele glisoarelor "
    L"și butoanele de activare sau dezactivare a tuturor opțiunilor. Etichetele glisoarelor afișează o "
    L"liniuță în locul unei valori comune. Modificarea unei opțiuni sau clicul pe un glisor aplică acea "
    L"valoare tuturor monitoarelor selectate.\r\n\r\nPREVIZUALIZARE ȘI COMENZI\r\nFolosiți "
    L"FlightCorridor.scr drept economizor de ecran Windows, cu setări separate de aplicație. "
    L"Previzualizarea pe tot ecranul permite ajustări în timp real. OK salvează modificările; Anulare sau "
    L"Esc le anulează. Ieșiți din economizor apăsând o tastă sau mișcând mouse-ul.\r\n\r\nCERINȚE DE "
    L"SISTEM\r\nWindows 7–11 acceptă toate funcțiile. Pentru Windows Vista SP2 trebuie instalate "
    L"actualizările KB971512 și KB2117917. Este necesar Direct3D 11.",
    L"ΚΙΝΗΣΗ ΚΑΙ ΡΥΘΜΙΣΕΙΣ\r\nΠτήση ανάμεσα σε μεταβαλλόμενες επιφάνειες με επιτάχυνση υλικού. Πτήση "
    L"ανάμεσα σε τέσσερις μεταβαλλόμενες επιφάνειες; Πτήση μέσα από μεταβαλλόμενη χοάνη. Επιλέξτε ακριβώς "
    L"μία κίνηση ανά οθόνη. Η Υφή εναλλάσσει επιφάνεια με υφή και συρμάτινο μοντέλο. Η ελεύθερη περιστροφή "
    L"κάμερας αλλάζει αργά την κατεύθυνση θέασης και στις τρεις διαστάσεις. Οι Παύσεις και αντιστροφές "
    L"προσθέτουν τυχαίες επιβραδύνσεις, παύσεις και αντιστροφές περιστροφής, ενώ η πτήση προς τα εμπρός "
    L"συνεχίζεται. Η ταχύτητα είναι 0–1600%. Κάθε οθόνη διαθέτει ανεξάρτητη τυχαία σκηνή που αποδίδεται "
    L"στον δικό της ρυθμό ανανέωσης. Ο κύριος φωτισμός, ο φωτισμός πλήρωσης, ο περιβάλλων φωτισμός και ο "
    L"φωτισμός περιγράμματος ρυθμίζονται ανεξάρτητα για τις επιλεγμένες οθόνες. Ο φωτισμός εφαρμόζεται μόνο "
    L"σε επιφάνειες με υφή.\r\n\r\nΟΘΟΝΕΣ\r\nΕπιλέξτε μία ή περισσότερες γραμμές στη λίστα οθονών. Το "
    L"Ctrl+A επιλέγει όλες, ενώ τα Ctrl και Shift αλλάζουν την επιλογή. Τα χειριστήρια και τα ρυθμιστικά "
    L"της κίνησης αλλάζουν μόνο τις ρυθμίσεις των επιλεγμένων οθονών. Η επιλογή γραμμής διαφέρει από την "
    L"ενεργοποίηση εξόδου μέσω του πλαισίου ελέγχου της. Η επιλογή αποθηκεύεται χωριστά για την εφαρμογή "
    L"και την προφύλαξη. Αν είχαν επιλεγεί όλες οι οθόνες, περιλαμβάνονται και όσες συνδεθούν αργότερα. Οι "
    L"διαφορετικές τιμές στις επιλεγμένες οθόνες υποδεικνύονται με απροσδιόριστη κατάσταση των πλαισίων "
    L"ελέγχου και μοτίβο κουκκίδων στα κουμπιά επιλογής, στις λαβές των ρυθμιστικών και στα κουμπιά "
    L"ενεργοποίησης ή απενεργοποίησης όλων των επιλογών. Οι ετικέτες των ρυθμιστικών δείχνουν παύλα αντί "
    L"για κοινή τιμή. Η αλλαγή επιλογής ή το κλικ σε ρυθμιστικό εφαρμόζει την τιμή σε όλες τις επιλεγμένες "
    L"οθόνες.\r\n\r\nΠΡΟΕΠΙΣΚΟΠΗΣΗ ΚΑΙ ΧΕΙΡΙΣΜΟΣ\r\nΧρησιμοποιήστε το FlightCorridor.scr ως προφύλαξη "
    L"οθόνης Windows με χωριστές ρυθμίσεις από την εφαρμογή. Η προεπισκόπηση πλήρους οθόνης επιτρέπει "
    L"ζωντανές αλλαγές. Το OK αποθηκεύει και το Άκυρο ή Esc απορρίπτει τις αλλαγές. Τερματίστε την "
    L"προφύλαξη με πλήκτρο ή κίνηση του ποντικιού.\r\n\r\nΑΠΑΙΤΗΣΕΙΣ ΣΥΣΤΗΜΑΤΟΣ\r\nΤα Windows 7–11 "
    L"υποστηρίζουν όλες τις λειτουργίες. Στα Windows Vista SP2 πρέπει να εγκατασταθούν οι ενημερώσεις "
    L"KB971512 και KB2117917. Απαιτείται υποστήριξη Direct3D 11.",
    L"ANIMACIJA I POSTAVKE\r\nHardverski ubrzan let između promjenjivih površina. Let između četiri "
    L"promjenjive površine; Let kroz promjenjivi lijevak. Za svaki monitor odaberite tačno jednu animaciju. "
    L"Tekstura mijenja prikaz između teksturirane površine i žičanog modela. Slobodno okretanje kamere "
    L"polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, pauze "
    L"i promjene smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki monitor ima nezavisnu "
    L"nasumičnu scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko "
    L"svjetlo, ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. "
    L"Osvjetljenje se primjenjuje samo na teksturirane površine.\r\n\r\nMONITORI\r\nOdaberite jedan ili "
    L"više redova u listi monitora. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači "
    L"animacije mijenjaju samo postavke odabranih monitora. Odabir reda nije isto što i uključivanje izlaza "
    L"njegovom kućicom. Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
    L"odabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na odabranim "
    L"monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, ručkama "
    L"klizača i dugmadima za uključivanje ili isključivanje svih opcija. Oznake klizača prikazuju crticu "
    L"umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost na sve "
    L"odabrane monitore.\r\n\r\nPREGLED I UPRAVLJANJE\r\nKoristite FlightCorridor.scr kao Windows čuvar "
    L"ekrana s odvojenim postavkama. Pregled preko cijelog ekrana omogućava izmjene uživo. OK čuva, a "
    L"Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili pomjeranjem "
    L"miša.\r\n\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate "
    L"instalirati ažuriranja KB971512 i KB2117917. Potreban je Direct3D 11.",
    L"ANIMACIJA I POSTAVKE\r\nHardverski ubrzan let između promjenjivih ploha. Let između četiriju "
    L"promjenjivih ploha; Let kroz promjenjivi lijevak. Za svaki zaslon odaberite točno jednu animaciju. "
    L"Tekstura mijenja prikaz između teksturirane plohe i žičanog modela. Slobodno okretanje kamere polako "
    L"mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, stanke i "
    L"promjene smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki zaslon ima neovisnu "
    L"nasumičnu scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, dopunsko "
    L"svjetlo, ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane monitore. "
    L"Osvjetljenje se primjenjuje samo na teksturirane površine.\r\n\r\nMONITORI\r\nOdaberite jedan ili "
    L"više redaka na popisu zaslona. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači "
    L"animacije mijenjaju samo postavke odabranih zaslona. Odabir retka nije isto što i uključivanje izlaza "
    L"njegovim potvrdnim okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar zaslona. Ako su prethodno "
    L"bili odabrani svi zasloni, uključuju se i novopriključeni zasloni. Različite vrijednosti na odabranim "
    L"zaslonima prikazuju se neodređenim stanjem potvrdnih okvira i točkastim uzorkom na izbornim gumbima, "
    L"ručkama klizača i gumbima za uključivanje ili isključivanje svih mogućnosti. Oznake klizača prikazuju "
    L"crticu umjesto zajedničke vrijednosti. Promjena mogućnosti ili klik na klizač primjenjuje tu "
    L"vrijednost na sve odabrane zaslone.\r\n\r\nPRETPREGLED I UPRAVLJANJE\r\nKoristite FlightCorridor.scr "
    L"kao Windows čuvar zaslona s odvojenim postavkama. Pretpregled preko cijelog zaslona omogućuje izmjene "
    L"uživo. OK sprema, a Odustani ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili "
    L"pomicanjem miša.\r\n\r\nZAHTJEVI SUSTAVA\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 "
    L"morate instalirati ažuriranja KB971512 i KB2117917. Potreban je Direct3D 11.",
    L"ANIMACIJA IN NASTAVITVE\r\nStrojno pospešen let med spreminjajočimi se ploskvami. Let med štirimi "
    L"spreminjajočimi se ploskvami; Let skozi spreminjajoči se lijak. Za vsak zaslon izberite natanko eno "
    L"animacijo. Tekstura preklaplja med teksturirano ploskvijo in žičnim modelom. Prosto vrtenje kamere "
    L"počasi spreminja smer pogleda v vseh treh razsežnostih. Premori in obrati dodajo naključne "
    L"upočasnitve, premore in obrate smeri vrtenja; let naprej se nadaljuje. Hitrost je 0–1600%. Vsak "
    L"zaslon ima neodvisen naključen prizor, ki se izrisuje z njegovo hitrostjo osveževanja. Glavno "
    L"svetlobo, dopolnilno svetlobo, okoljsko svetlobo in obrobno svetlobo je mogoče neodvisno vklapljati "
    L"za izbrane zaslone. Osvetlitev velja samo za teksturirane površine.\r\n\r\nZASLONI\r\nNa seznamu "
    L"zaslonov izberite eno ali več vrstic. Ctrl+A izbere vse, Ctrl in Shift pa spreminjata izbor. "
    L"Kontrolniki in drsniki animacije spreminjajo samo nastavitve izbranih zaslonov. Izbira vrstice ni "
    L"isto kot vklop izhoda z njenim potrditvenim poljem. Izbor se ločeno shrani za program in "
    L"ohranjevalnik. Če so bili izbrani vsi zasloni, so vključeni tudi na novo priključeni zasloni. "
    L"Različne vrednosti na izbranih zaslonih označujeta nedoločeno stanje potrditvenih polj in pikčast "
    L"vzorec na izbirnih gumbih, ročicah drsnikov ter gumbih za vklop ali izklop vseh možnosti. Oznake "
    L"drsnikov namesto skupne vrednosti prikazujejo pomišljaj. Sprememba možnosti ali klik na drsnik "
    L"uveljavi to vrednost na vseh izbranih zaslonih.\r\n\r\nPREDOGLED IN UPRAVLJANJE\r\nUporabite "
    L"FlightCorridor.scr kot ohranjevalnik zaslona Windows z ločenimi nastavitvami. Celozaslonski predogled "
    L"omogoča sprotne spremembe. OK jih shrani, Prekliči ali Esc jih zavrže. Ohranjevalnik zapustite s "
    L"tipko ali premikom miške.\r\n\r\nSISTEMSKE ZAHTEVE\r\nWindows 7–11 podpira vse funkcije. Za Windows "
    L"Vista SP2 morate namestiti posodobitvi KB971512 in KB2117917. Potrebna je podpora Direct3D 11.",
    L"ANIMACIJA I PODEŠAVANJA\r\nHardverski ubrzan let između promjenljivih površina. Let između četiri "
    L"promjenljive površine; Let kroz promjenljivi lijevak. Za svaki monitor izaberite tačno jednu "
    L"animaciju. Tekstura mijenja prikaz između teksturisane površine i žičanog modela. Slobodno okretanje "
    L"kamere polako mijenja smjer pogleda u sve tri dimenzije. Pauze i obrati dodaju nasumično usporavanje, "
    L"pauze i promjene smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki monitor ima "
    L"nezavisnu nasumičnu scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja. Glavno svjetlo, "
    L"dopunsko svjetlo, ambijentalno svjetlo i konturno svjetlo mogu se zasebno uključivati za odabrane "
    L"monitore. Osvjetljenje se primjenjuje samo na teksturirane površine.\r\n\r\nMONITORI\r\nIzaberite "
    L"jedan ili više redova u listi monitora. Ctrl+A bira sve; Ctrl i Shift mijenjaju izbor. Kontrole i "
    L"klizači animacije mijenjaju samo podešavanja izabranih monitora. Izbor reda nije isto što i "
    L"uključivanje izlaza njegovom kućicom. Izbor se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su "
    L"prethodno bili izabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti "
    L"na izabranim monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima "
    L"izbora, ručkama klizača i dugmadima za uključivanje ili isključivanje svih opcija. Oznake klizača "
    L"prikazuju crticu umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu "
    L"vrijednost na sve izabrane monitore.\r\n\r\nPREGLED I UPRAVLJANJE\r\nKoristite FlightCorridor.scr kao "
    L"Windows čuvar ekrana s odvojenim podešavanjima. Pregled preko cijelog ekrana omogućava izmjene uživo. "
    L"OK čuva, a Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tastera ili pomjeranjem "
    L"miša.\r\n\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate "
    L"instalirati ažuriranja KB971512 i KB2117917. Potreban je Direct3D 11.",
    L"АНІМАЦЫЯ І НАЛАДЫ\r\nАпаратна паскораны палёт паміж зменлівымі паверхнямі. Палёт паміж чатырма "
    L"зменлівымі паверхнямі; Палёт праз зменлівую варонку. Для кожнага манітора выберыце роўна адну "
    L"анімацыю. Тэкстура пераключае тэкстураваную паверхню і каркасную мадэль. Свабоднае кручэнне камеры "
    L"павольна змяняе напрамак погляду ва ўсіх трох вымярэннях. Паўзы і развароты дадаюць выпадковыя "
    L"запаволенні, паўзы і змены напрамку кручэння; палёт наперад працягваецца. Хуткасць — 0–1600%. Кожны "
    L"манітор мае незалежную выпадковую сцэну з вывадам паводле ўласнай частаты абнаўлення. Асноўнае, "
    L"запаўняльнае, фонавае і контурнае святло можна пераключаць незалежна для выбраных манітораў. "
    L"Асвятленне дзейнічае толькі на тэкстураваных паверхнях.\r\n\r\nМАНІТОРЫ\r\nВыберыце адзін або "
    L"некалькі радкоў у спісе манітораў. Ctrl+A выбірае ўсе; Ctrl і Shift змяняюць выбар. Элементы "
    L"кіравання і паўзункі анімацыі змяняюць толькі налады выбраных манітораў. Выбар радка і ўключэнне "
    L"вываду яго сцяжком — розныя дзеянні. Выбар асобна захоўваецца для праграмы і застаўкі. Калі раней "
    L"былі выбраны ўсе маніторы, да выбару далучаюцца і новыя маніторы. Розныя значэнні на выбраных "
    L"маніторах пазначаюцца нявызначаным станам сцяжкоў і кропкавым узорам на пераключальніках, ручках "
    L"паўзункоў і кнопках уключэння або выключэння ўсіх параметраў. У подпісах паўзункоў замест агульнага "
    L"значэння паказваецца працяжнік. Змена параметра або націск на паўзунок ужывае гэта значэнне да ўсіх "
    L"выбраных манітораў.\r\n\r\nПЕРАДПРАГЛЯД І КІРАВАННЕ\r\nВыкарыстоўвайце FlightCorridor.scr як застаўку "
    L"Windows з асобнымі наладамі. Поўнаэкранны перадпрагляд дазваляе змяняць іх падчас анімацыі. OK "
    L"захоўвае змены, Скасаваць або Esc адхіляе іх. Для выхаду з застаўкі націсніце клавішу або паварушыце "
    L"мышшу.\r\n\r\nСІСТЭМНЫЯ ПАТРАБАВАННІ\r\nWindows 7–11 падтрымлівае ўсе функцыі. Для Windows Vista SP2 "
    L"неабходна ўсталяваць абнаўленні KB971512 і KB2117917. Патрэбна падтрымка Direct3D 11.",
    L"АНИМАЦИЯ И НАСТРОЙКИ\r\nХардуерно ускорен полет между променящи се повърхнини. Полет между четири "
    L"променящи се повърхнини; Полет през променяща се фуния. Изберете точно една анимация за всеки "
    L"монитор. Текстура превключва между текстурирана повърхнина и телен модел. Свободното въртене на "
    L"камерата бавно променя посоката на погледа в трите измерения. Опцията „Паузи и обръщания“ добавя "
    L"случайни забавяния, паузи и обръщания на въртенето; полетът напред продължава. Скоростта е 0–1600%. "
    L"Всеки монитор има независима случайна сцена, изобразявана с неговата честота на опресняване. "
    L"Основната, запълващата, околната и контурната светлина се включват независимо за избраните монитори. "
    L"Осветлението се прилага само към текстурираните повърхности.\r\n\r\nМОНИТОРИ\r\nИзберете един или "
    L"повече редове в списъка с монитори. Ctrl+A избира всички; Ctrl и Shift променят избора. Контролите и "
    L"плъзгачите на анимацията променят само настройките на избраните монитори. Избирането на ред и "
    L"включването на изхода чрез отметката му са различни действия. Изборът се запомня отделно за "
    L"приложението и скрийнсейвъра. Ако са били избрани всички монитори, включват се и новосвързаните. "
    L"Различните стойности на избраните монитори се показват с неопределено състояние на отметките и точков "
    L"шаблон върху радиобутоните, дръжките на плъзгачите и бутоните за включване или изключване на всички "
    L"опции. Надписите на плъзгачите показват тире вместо обща стойност. Промяна на опция или щракване "
    L"върху плъзгач прилага стойността към всички избрани монитори.\r\n\r\nПРЕГЛЕД И "
    L"УПРАВЛЕНИЕ\r\nИзползвайте FlightCorridor.scr като скрийнсейвър на Windows с отделни настройки. "
    L"Прегледът на цял екран позволява промени в реално време. OK запазва промените; Отказ или Esc ги "
    L"отхвърля. Излезте от скрийнсейвъра с клавиш или движение на мишката.\r\n\r\nСИСТЕМНИ "
    L"ИЗИСКВАНИЯ\r\nWindows 7–11 поддържа всички функции. За Windows Vista SP2 трябва да се инсталират "
    L"актуализациите KB971512 и KB2117917. Изисква се поддръжка на Direct3D 11.",
    L"АНИМАЦИЈА И ПОСТАВКИ\r\nХардверски забрзан лет меѓу променливи површини. Лет меѓу четири променливи "
    L"површини; Лет низ променлива инка. За секој монитор изберете точно една анимација. Текстура менува "
    L"текстурирана површина и жичен модел. Слободното вртење на камерата полека го менува погледот во сите "
    L"три димензии. Опцијата „Паузи и пресврти“ додава случајни забавувања, паузи и промени на насоката на "
    L"вртење; летот напред продолжува. Брзината е 0–1600%. Секој монитор има независна случајна сцена што "
    L"се прикажува со неговата стапка на освежување. Главното, дополнителното, амбиенталното и контурното "
    L"светло може да се вклучуваат одделно за избраните монитори. Осветлувањето важи само за текстурираните "
    L"површини.\r\n\r\nМОНИТОРИ\r\nИзберете еден или повеќе редови во списокот на монитори. Ctrl+A ги "
    L"избира сите; Ctrl и Shift го менуваат изборот. Контролите и лизгачите на анимацијата ги менуваат само "
    L"поставките на избраните монитори. Избирањето ред и вклучувањето на излезот преку неговото поле се "
    L"различни дејства. Изборот се памети одделно за апликацијата и чуварот. Ако биле избрани сите "
    L"монитори, се вклучуваат и новоповрзаните монитори. Различните вредности на избраните монитори се "
    L"прикажуваат со неопределена состојба на полињата за избор и точкест образец на радио-копчињата, "
    L"рачките на лизгачите и копчињата за вклучување или исклучување на сите опции. Ознаките на лизгачите "
    L"прикажуваат црта наместо заедничка вредност. Менувањето опција или кликнувањето на лизгач ја "
    L"применува вредноста на сите избрани монитори.\r\n\r\nПРЕГЛЕД И УПРАВУВАЊЕ\r\nКористете "
    L"FlightCorridor.scr како Windows чувар на екранот со одделни поставки. Прегледот на цел екран "
    L"овозможува измени во живо. OK ги зачувува, а Откажи или Esc ги отфрла измените. Излезете од чуварот "
    L"со копче или движење на глувчето.\r\n\r\nСИСТЕМСКИ БАРАЊА\r\nWindows 7–11 ги поддржува сите функции. "
    L"За Windows Vista SP2 мора да се инсталираат ажурирањата KB971512 и KB2117917. Потребна е поддршка за "
    L"Direct3D 11.",
    L"АНИМАЦИЈА И ПОДЕШАВАЊА\r\nХардверски убрзан лет између променљивих површи. Лет између четири "
    L"променљиве површи; Лет кроз променљиви левак. За сваки монитор изаберите тачно једну анимацију. "
    L"Текстура мења приказ између текстурисане површи и жичаног модела. Слободно окретање камере полако "
    L"мења смер погледа у све три димензије. Паузе и обрти додају насумично успоравање, паузе и промене "
    L"смера ротације; лет напред се наставља. Брзина је 0–1600%. Сваки монитор има независну насумичну "
    L"сцену која се приказује према његовој учестаности освежавања. Главно, допунско, амбијентално и "
    L"контурно светло могу се засебно укључивати за изабране мониторе. Осветљење важи само за текстуриране "
    L"површине.\r\n\r\nМОНИТОРИ\r\nИзаберите један или више редова у листи монитора. Ctrl+A бира све; Ctrl "
    L"и Shift мењају избор. Контроле и клизачи анимације мењају само подешавања изабраних монитора. Избор "
    L"реда није исто што и укључивање излаза његовим пољем за потврду. Избор се памти одвојено за "
    L"апликацију и чувар екрана. Ако су претходно били изабрани сви монитори, укључују се и новоприкључени "
    L"монитори. Различите вредности на изабраним мониторима приказују се неодређеним стањем поља за потврду "
    L"и тачкастим узорком на дугмадима избора, ручкама клизача и дугмадима за укључивање или искључивање "
    L"свих опција. Ознаке клизача приказују црту уместо заједничке вредности. Промена опције или клик на "
    L"клизач примењује ту вредност на све изабране мониторе.\r\n\r\nПРЕГЛЕД И УПРАВЉАЊЕ\r\nКористите "
    L"FlightCorridor.scr као Windows чувар екрана са одвојеним подешавањима. Преглед преко целог екрана "
    L"омогућава измене уживо. OK чува, а Откажи или Esc одбацује измене. Из чувара изађите притиском "
    L"тастера или померањем миша.\r\n\r\nСИСТЕМСКИ ЗАХТЕВИ\r\nWindows 7–11 подржава све функције. За "
    L"Windows Vista SP2 морате инсталирати ажурирања KB971512 и KB2117917. Потребан је Direct3D 11.",
    L"АНІМАЦІЯ ТА НАЛАШТУВАННЯ\r\nАпаратно прискорений політ між мінливими поверхнями. Політ між чотирма "
    L"мінливими поверхнями; Політ крізь мінливу лійку. Для кожного монітора виберіть рівно одну анімацію. "
    L"Текстура перемикає текстуровану поверхню та каркасну модель. Вільне обертання камери повільно змінює "
    L"напрямок погляду в усіх трьох вимірах. Паузи та зміни напрямку додають випадкові уповільнення, паузи "
    L"та зміни напрямку обертання; політ уперед триває. Швидкість — 0–1600%. Кожен монітор має незалежну "
    L"випадкову сцену з виведенням відповідно до власної частоти оновлення. Основне, заповнювальне, фонове "
    L"та контурне світло можна незалежно перемикати для вибраних моніторів. Освітлення діє лише на "
    L"текстурованих поверхнях.\r\n\r\nМОНІТОРИ\r\nВиберіть один або кілька рядків у списку моніторів. "
    L"Ctrl+A вибирає всі; Ctrl і Shift змінюють вибір. Елементи керування й повзунки анімації змінюють лише "
    L"налаштування вибраних моніторів. Вибір рядка та ввімкнення виведення його прапорцем — різні дії. "
    L"Вибір зберігається окремо для програми й заставки. Якщо раніше були вибрані всі монітори, до вибору "
    L"долучаються й новопідключені. Різні значення на вибраних моніторах позначаються невизначеним станом "
    L"прапорців і крапковим візерунком на перемикачах, ручках повзунків і кнопках увімкнення або вимкнення "
    L"всіх параметрів. Підписи повзунків показують тире замість спільного значення. Зміна параметра або "
    L"натискання на повзунок застосовує це значення до всіх вибраних моніторів.\r\n\r\nПОПЕРЕДНІЙ ПЕРЕГЛЯД "
    L"І КЕРУВАННЯ\r\nВикористовуйте FlightCorridor.scr як заставку Windows з окремими налаштуваннями. "
    L"Повноекранний попередній перегляд дозволяє змінювати їх під час анімації. OK зберігає зміни, "
    L"Скасувати або Esc відхиляє їх. Для виходу із заставки натисніть клавішу або порухайте "
    L"мишею.\r\n\r\nСИСТЕМНІ ВИМОГИ\r\nWindows 7–11 підтримує всі функції. Для Windows Vista SP2 потрібно "
    L"встановити оновлення KB971512 і KB2117917. Потрібна підтримка Direct3D 11.",
    L"АНИМАЦИЯ И НАСТРОЙКИ\r\nАппаратно ускоренный полёт между меняющимися поверхностями. Полёт между "
    L"четырьмя меняющимися поверхностями; Полёт сквозь меняющуюся воронку. Для каждого монитора выберите "
    L"ровно одну анимацию. Текстура переключает текстурированную поверхность и каркасную модель. Свободное "
    L"вращение камеры медленно меняет направление взгляда во всех трёх измерениях. Паузы и смены "
    L"направления добавляют случайные замедления, паузы и изменения направления вращения; полёт вперёд "
    L"продолжается. Скорость — 0–1600%. Каждый монитор имеет независимую случайную сцену с выводом согласно "
    L"собственной частоте обновления. Основной, заполняющий, фоновый и контурный свет можно независимо "
    L"переключать для выбранных мониторов. Освещение применяется только к текстурированным "
    L"поверхностям.\r\n\r\nМОНИТОРЫ\r\nВыберите одну или несколько строк в списке мониторов. Ctrl+A "
    L"выбирает все; Ctrl и Shift изменяют выбор. Элементы управления и ползунки анимации изменяют только "
    L"настройки выбранных мониторов. Выбор строки и включение вывода её флажком — разные действия. Выбор "
    L"сохраняется отдельно для приложения и заставки. Если раньше были выбраны все мониторы, в выбор "
    L"включаются и вновь подключённые. Разные значения на выбранных мониторах обозначаются неопределённым "
    L"состоянием флажков и точечным узором на переключателях, ручках ползунков и кнопках включения или "
    L"выключения всех параметров. Подписи ползунков показывают тире вместо общего значения. Изменение "
    L"параметра или нажатие на ползунок применяет это значение ко всем выбранным "
    L"мониторам.\r\n\r\nПРЕДПРОСМОТР И УПРАВЛЕНИЕ\r\nИспользуйте FlightCorridor.scr как заставку Windows с "
    L"отдельными настройками. Полноэкранный предпросмотр позволяет изменять их во время анимации. OK "
    L"сохраняет изменения, Отмена или Esc отклоняет их. Для выхода из заставки нажмите клавишу или "
    L"подвигайте мышью.\r\n\r\nСИСТЕМНЫЕ ТРЕБОВАНИЯ\r\nWindows 7–11 поддерживает все функции. Для Windows "
    L"Vista SP2 необходимо установить обновления KB971512 и KB2117917. Нужна поддержка Direct3D 11."
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
    L"Biçim değiştiren bir koridor ve hunide donanım hızlandırmalı uçuş.",
    L"Riistvarakiirendusega lend muutuvate pindade vahel.",
    L"Eitilt idir dromchlaí athraitheacha le luasghéarú crua-earraí.",
    L"Aparatine įranga spartinamas skrydis tarp kintančių paviršių.",
    L"Aparatūras paātrināts lidojums starp mainīgām virsmām.",
    L"Hardveresen gyorsított repülés változó felületek között.",
    L"Titjira bejn uċuħ li jinbidlu aċċellerata bil-ħardwer.",
    L"Hardwareversnelde vlucht tussen vervormende oppervlakken.",
    L"Zbor între suprafețe deformabile accelerat hardware.",
    L"Πτήση ανάμεσα σε μεταβαλλόμενες επιφάνειες με επιτάχυνση υλικού.",
    L"Hardverski ubrzan let između promjenjivih površina.",
    L"Hardverski ubrzan let između promjenjivih ploha.",
    L"Strojno pospešen let med spreminjajočimi se ploskvami.",
    L"Hardverski ubrzan let između promjenljivih površina.",
    L"Апаратна паскораны палёт паміж зменлівымі паверхнямі.",
    L"Хардуерно ускорен полет между променящи се повърхнини.",
    L"Хардверски забрзан лет меѓу променливи површини.",
    L"Хардверски убрзан лет између променљивих површи.",
    L"Апаратно прискорений політ між мінливими поверхнями.",
    L"Аппаратно ускоренный полёт между меняющимися поверхностями."
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
    return RECORDING_CLOSE_WARNING_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
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
    return PREVENT_SCREEN_SAVER_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
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
    return UNINSTALL_SCREEN_SAVER_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized successful-uninstallation status text.
const wchar_t* UninstallationSucceededText(AppLanguage language) {
    return UNINSTALLATION_SUCCEEDED_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the generic localized uninstallation failure text.
const wchar_t* UninstallationFailedText(AppLanguage language) {
    return UNINSTALLATION_FAILED_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
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

/// Returns the localized ambient-light checkbox caption.
const wchar_t* AmbientLightText(AppLanguage language) {
    return AMBIENT_LIGHT_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized rim-light checkbox caption.
const wchar_t* RimLightText(AppLanguage language) {
    return RIM_LIGHT_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the selected monitors' texture option in the selected language.
const wchar_t* FilledSurfaceText(AppLanguage language) {
    return FILLED_SURFACE_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the selected monitors' camera-tumbling option in the selected language.
const wchar_t* CameraTumblingText(AppLanguage language) {
    return CAMERA_TUMBLING_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the selected monitors’ optional camera stops and reversals caption.
const wchar_t* CameraReversalsText(AppLanguage language) {
    return CAMERA_REVERSALS_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}
