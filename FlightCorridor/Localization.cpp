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

/// Recording-settings captions and presets shared with the Emulators interface.
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
    L"FlightCorridor: Průlet čtyřmi proměnlivými plochami; Průlet proměnlivým trychtýřem. Každému monitoru "
    L"přiřaďte právě jednu animaci. Textura přepíná mezi texturovanými plochami a drátěným modelem. "
    L"Převalování kamery pomalu mění směr pohledu ve všech třech rozměrech. Zastavování a změny směru "
    L"přidává náhodné zpomalování, pauzy a změny směru otáčení; dopředný pohyb pokračuje. Rychlost animace "
    L"je 0–1600 %. Každý monitor má nezávislou náhodnou scénu a vykreslování podle své obnovovací "
    L"frekvence.\r\n\r\nOznačení řádků určuje, které monitory právě nastavujete; není totožné se zatržítky "
    L"zapínajícími animační výstupy. Ctrl+A označí všechny monitory, Ctrl a Shift umožňují upravit "
    L"označení. Všechny animační volby a jezdce platí pro označené monitory. Označení se pamatuje zvlášť "
    L"pro EXE a SCR. Pokud byly označené všechny monitory, označí se i nově připojené.\r\n\r\nV seznamu lze "
    L"označit více monitorů; dvojklikem na řádek monitor zapnete nebo vypnete a lze zrušit i výběr všech "
    L"monitorů. Každý monitor používá nezávislou scénu. Snímek ukládá PNG, tlačítko záznamu spouští a "
    L"ukončuje MP4. Pozastavení zastaví animaci. Aplikace také instaluje nebo odinstaluje zabalený spořič. "
    L"Nastavení se ukládá průběžně. Aplikace běží pouze v jedné instanci. Další spuštění obnoví "
    L"minimalizované ovládací okno a přenese do popředí. Mezi ovládacími prvky přecházejte klávesami Tab a "
    L"Shift+Tab; podtržené volby lze vyvolat pomocí Alt a příslušného písmene. Esc zavře aktivní nápovědu "
    L"či okno O aplikaci; v ovládacím okně ukončí aplikaci. Volba Blokovat spořič při animaci brání "
    L"spuštění spořiče Windows pouze tehdy, když je animace skutečně viditelná a není "
    L"pozastavená.\r\n\r\nSnímek a záznam zachycují první aktivní animační monitor, nikoli společnou plochu "
    L"všech monitorů. PNG používá složku Obrázky, MP4 složku Videa; při jejich neexistenci se použijí "
    L"Dokumenty. Tlačítko Nastavení záznamu vybírá Viewport nebo TV. Viewport zachovává rozměry animačního "
    L"monitoru a jeho obnovovací frekvenci, nejvýše 60 snímků za sekundu. TV nabízí rozlišení 1920 × 1080, "
    L"1440 × 1080 nebo 1280 × 720 v poměru 16:9 a frekvenci 50, 25, 59.94 (60000/1001) nebo 29.97 "
    L"(30000/1001) snímků za sekundu. Obraz zachovává poměr stran; TV používá progresivní video BT.709 s "
    L"omezeným rozsahem a vzorkováním 4:2:0. Rozlišení a snímkovou frekvenci lze vybrat pouze v režimu TV. "
    L"Okno Nastavení záznamu lze minimalizovat a neblokuje ostatní okna aplikace. OK uloží volby pro příští "
    L"záznam MP4; Storno nebo Esc nepotvrzené změny zahodí. Nahrávaný monitor nelze během záznamu odepnout; "
    L"změny ostatních monitorů záznam nezastaví. Ukončení aplikace při probíhajícím záznamu vyžaduje "
    L"potvrzení, protože současně ukončí záznam.\r\n\r\nWindows 7 až Windows 11 podporují všechny funkce "
    L"včetně snímků PNG a záznamu MP4. Pro spuštění aplikace ve Windows Vista SP2 je nutné nainstalovat "
    L"aktualizace KB971512 a KB2117917. Záznam MP4 na Vistě v současné verzi nefunguje.",
    L"FlightCorridor: Flight between four morphing surfaces; Flight through a morphing funnel. Assign "
    L"exactly one animation to each display. Texture switches between textured surfaces and wireframe. "
    L"Camera tumbling slowly changes the viewing direction in all three dimensions. Stops and reversals "
    L"adds randomized braking, pauses, and reversals of the rotation; forward flight continues. Animation "
    L"speed ranges from 0–1600%. Every display has an independent randomized scene rendered at its own "
    L"refresh rate.\r\n\r\nRow selection determines which displays you are editing; it is separate from the "
    L"checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the "
    L"selection. All animation options and sliders apply to the selected displays. The selection is "
    L"remembered separately for EXE and SCR. If all displays were selected, newly connected displays join "
    L"the selection.\r\n\r\nSelect several displays in the list; double-click a row to toggle it, or clear "
    L"the selection for all displays. Every display uses an independent scene. Snapshot saves a PNG and the "
    L"recording button starts or stops an MP4. Pause stops the animation. The application also installs or "
    L"uninstalls its embedded screen saver. Settings are saved continuously. Only one instance of the "
    L"application runs at a time. Launching it again restores its minimized control window and brings it to "
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
    L"mode. The Recording settings window can be minimized and does not block the other application "
    L"windows. OK saves choices for the next MP4 recording; Cancel or Esc discards unconfirmed changes. The "
    L"recorded display cannot be detached during recording; changes to other displays do not stop the "
    L"recording. Closing the application while recording requires confirmation because it also stops the "
    L"recording.\r\n\r\nWindows 7 through Windows 11 support all features, including PNG snapshots and MP4 "
    L"recording. To run the application on Windows Vista SP2, you must install updates KB971512 and "
    L"KB2117917. MP4 recording does not work on Vista in the current version.",
    L"FlightCorridor: Flight between four morphing surfaces; Flight through a morphing funnel. Assign "
    L"exactly one animation to each display. Texture switches between textured surfaces and wireframe. "
    L"Camera tumbling slowly changes the viewing direction in all three dimensions. Stops and reversals "
    L"adds randomised braking, pauses and reversals of the rotation; forward flight continues. Animation "
    L"speed ranges from 0–1600%. Every display has an independent randomised scene rendered at its own "
    L"refresh rate.\r\n\r\nRow selection determines which displays you are editing; it is separate from the "
    L"checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the "
    L"selection. All animation options and sliders apply to the selected displays. The selection is "
    L"remembered separately for EXE and SCR. If all displays were selected, newly connected displays join "
    L"the selection.\r\n\r\nSelect several displays; double-click a row to toggle it, or clear the "
    L"selection for all displays. Each display uses an independent scene. Snapshot saves PNG and the "
    L"recording button starts or stops MP4. Pause stops the animation. The application also installs or "
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
    L"FlightCorridor: Flight between four morphing surfaces; Flight through a morphing funnel. Assign "
    L"exactly one animation to each display. Texture switches between textured surfaces and wireframe. "
    L"Camera tumbling slowly changes the viewing direction in all three dimensions. Stops and reversals "
    L"adds randomised braking, pauses and reversals of the rotation; forward flight continues. Animation "
    L"speed ranges from 0–1600%. Every display has an independent randomised scene rendered at its own "
    L"refresh rate.\r\n\r\nRow selection determines which displays you are editing; it is separate from the "
    L"checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the "
    L"selection. All animation options and sliders apply to the selected displays. The selection is "
    L"remembered separately for EXE and SCR. If all displays were selected, newly connected displays join "
    L"the selection.\r\n\r\nSelect several displays; double-click a row to toggle it, or clear the "
    L"selection for all displays. Each display uses an independent scene. Snapshot saves PNG and the "
    L"recording button starts or stops MP4. Pause stops the animation. The application also installs or "
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
    L"FlightCorridor: Flug zwischen vier veränderlichen Flächen; Flug durch einen veränderlichen Trichter. "
    L"Weisen Sie jedem Monitor genau eine Animation zu. Textur wechselt zwischen texturierten Flächen und "
    L"Drahtgittermodell. Die taumelnde Kamera verändert die Blickrichtung langsam in allen drei "
    L"Dimensionen. Stopps und Richtungswechsel ergänzt zufälliges Abbremsen, Pausen und Wechsel der "
    L"Drehrichtung; der Vorwärtsflug läuft weiter. Die Animationsgeschwindigkeit beträgt 0–1600 %. Jeder "
    L"Monitor besitzt eine unabhängige zufällige Szene und wird mit seiner eigenen Bildwiederholrate "
    L"angesteuert.\r\n\r\nDie Zeilenauswahl bestimmt, welche Monitore Sie bearbeiten; sie ist von den "
    L"Kontrollkästchen zum Einschalten der Animationsausgabe getrennt. Strg+A wählt alle Monitore, Strg und "
    L"Umschalt ändern die Auswahl. Alle Animationsoptionen und Regler gelten für die ausgewählten Monitore. "
    L"Die Auswahl wird für EXE und SCR getrennt gespeichert. Waren alle Monitore ausgewählt, werden auch "
    L"neu angeschlossene ausgewählt.\r\n\r\nIn der Liste sind mehrere Monitore wählbar; ein Doppelklick "
    L"schaltet einen Monitor um, auch alle können abgewählt werden. Jeder Monitor besitzt eine unabhängige "
    L"Szene. Schnappschuss speichert PNG, die Aufnahmetaste startet oder beendet MP4. Pause hält die "
    L"Animation an. Die Anwendung installiert oder deinstalliert außerdem den eingebetteten "
    L"Bildschirmschoner. Einstellungen werden laufend gespeichert. Die Anwendung läuft nur in einer "
    L"Instanz. Ein erneuter Start stellt das minimierte Steuerfenster wieder her und bringt es in den "
    L"Vordergrund. Mit Tab und Umschalt+Tab wechseln Sie zwischen den Steuerelementen; mit Alt und dem "
    L"unterstrichenen Buchstaben rufen Sie einen Befehl auf. Esc schließt das aktive Hilfe- oder "
    L"Infofenster; im Steuerfenster beendet es die Anwendung. Bildschirmschoner bei Animation sperren "
    L"verhindert den Start des Windows-Bildschirmschoners nur, solange die Animation tatsächlich sichtbar "
    L"und nicht angehalten ist.\r\n\r\nSchnappschüsse und Aufnahmen erfassen den ersten aktiven "
    L"Animationsmonitor, nicht die gemeinsame Fläche aller Monitore. PNG verwendet Bilder, MP4 Videos; "
    L"fehlen diese Ordner, wird Dokumente verwendet. Die Schaltfläche Aufnahmeeinstellungen wählt Viewport "
    L"oder TV. Viewport erhält die Abmessungen und Bildwiederholfrequenz des Animationsmonitors bis "
    L"höchstens 60 Bilder pro Sekunde. TV bietet 1920 × 1080, 1440 × 1080 oder 1280 × 720 im Format 16:9 "
    L"mit 50, 25, 59.94 (60000/1001) oder 29.97 (30000/1001) Bildern pro Sekunde. Das Seitenverhältnis "
    L"bleibt erhalten; TV verwendet progressives BT.709-Video mit begrenztem Wertebereich und "
    L"4:2:0-Abtastung. Auflösung und Bildfrequenz sind nur im TV-Modus wählbar. Das Fenster "
    L"Aufnahmeeinstellungen lässt sich minimieren und blockiert die anderen Anwendungsfenster nicht. OK "
    L"speichert die Auswahl für die nächste MP4-Aufnahme; Abbrechen oder Esc verwirft unbestätigte "
    L"Änderungen. Der aufgezeichnete Monitor kann während der Aufnahme nicht abgewählt werden; Änderungen "
    L"an anderen Monitoren beenden die Aufnahme nicht. Das Beenden der Anwendung während einer Aufnahme "
    L"muss bestätigt werden, da es auch die Aufnahme beendet.\r\n\r\nWindows 7 bis Windows 11 unterstützen "
    L"alle Funktionen einschließlich PNG-Schnappschüssen und MP4-Aufnahmen. Zum Ausführen der Anwendung "
    L"unter Windows Vista SP2 müssen die Updates KB971512 und KB2117917 installiert werden. MP4-Aufnahmen "
    L"funktionieren unter Vista in der aktuellen Version nicht.",
    L"FlightCorridor: Vol entre quatre surfaces déformables; Vol dans un entonnoir déformable. Attribuez "
    L"une seule animation à chaque écran. Texture alterne entre surfaces texturées et modèle filaire. La "
    L"rotation libre de la caméra change lentement la direction du regard dans les trois dimensions. Arrêts "
    L"et changements de sens ajoute des ralentissements, pauses et inversions aléatoires de la rotation ; "
    L"le vol vers l’avant continue. La vitesse va de 0 à 1600 %. Chaque écran possède une scène aléatoire "
    L"indépendante, rendue à sa propre fréquence de rafraîchissement.\r\n\r\nLa sélection des lignes "
    L"détermine les écrans à configurer ; elle est distincte des cases qui activent les sorties "
    L"d’animation. Ctrl+A sélectionne tous les écrans ; Ctrl et Maj modifient la sélection. Toutes les "
    L"options et tous les curseurs d’animation concernent les écrans sélectionnés. La sélection est "
    L"mémorisée séparément pour EXE et SCR. Si tous les écrans étaient sélectionnés, les nouveaux le sont "
    L"également.\r\n\r\nSélectionnez plusieurs moniteurs dans la liste ; un double-clic active ou désactive "
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
    L"FlightCorridor: Vuelo entre cuatro superficies deformables; Vuelo por un embudo deformable. Asigne "
    L"una sola animación a cada pantalla. Textura alterna entre superficies texturizadas y modelo de "
    L"alambre. El giro libre de la cámara cambia lentamente la dirección de la vista en las tres "
    L"dimensiones. Paradas y cambios de sentido añade frenadas, pausas e inversiones aleatorias del giro; "
    L"el vuelo hacia delante continúa. La velocidad va del 0 al 1600 %. Cada pantalla tiene una escena "
    L"aleatoria independiente y se renderiza a su propia frecuencia de actualización.\r\n\r\nLa selección "
    L"de filas determina qué pantallas se están configurando; es independiente de las casillas que activan "
    L"las salidas de animación. Ctrl+A selecciona todas; Ctrl y Mayús modifican la selección. Todas las "
    L"opciones y los controles deslizantes de animación se aplican a las pantallas seleccionadas. La "
    L"selección se recuerda por separado para EXE y SCR. Si estaban seleccionadas todas, se incluyen "
    L"también las nuevas.\r\n\r\nSeleccione varios monitores en la lista; un doble clic alterna la "
    L"animación en un monitor y también puede desmarcarlos todos. Cada monitor usa una escena "
    L"independiente. Captura guarda un PNG y el botón de grabación inicia o detiene un MP4. Pausar detiene "
    L"la animación. La aplicación instala o desinstala además el salvapantallas incorporado. Los ajustes se "
    L"guardan continuamente. La aplicación solo permite una instancia. Al volver a iniciarla, restaura la "
    L"ventana de control minimizada y la trae al primer plano. Use Tab y Mayús+Tab para desplazarse entre "
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
    L"FlightCorridor: Volo tra quattro superfici deformabili; Volo attraverso un imbuto deformabile. "
    L"Assegnare una sola animazione a ogni schermo. Texture alterna superfici con texture e modello a "
    L"reticolo. La rotazione libera della telecamera cambia lentamente la direzione dello sguardo nelle tre "
    L"dimensioni. Arresti e inversioni aggiunge rallentamenti, pause e inversioni casuali della rotazione; "
    L"il volo in avanti continua. La velocità va da 0 a 1600%. Ogni schermo ha una scena casuale "
    L"indipendente, renderizzata alla propria frequenza di aggiornamento.\r\n\r\nLa selezione delle righe "
    L"determina quali schermi si stanno configurando ed è distinta dalle caselle che attivano le uscite di "
    L"animazione. Ctrl+A seleziona tutti gli schermi; Ctrl e Maiusc modificano la selezione. Tutte le "
    L"opzioni e i cursori dell’animazione riguardano gli schermi selezionati. La selezione viene "
    L"memorizzata separatamente per EXE e SCR. Se erano selezionati tutti gli schermi, vengono inclusi "
    L"anche quelli nuovi.\r\n\r\nNell’elenco si possono selezionare più monitor; un doppio clic attiva o "
    L"disattiva l’animazione su un monitor, ed è possibile deselezionarli tutti. Ogni monitor usa una scena "
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
    L"FlightCorridor: Voo entre quatro superfícies deformáveis; Voo através de um funil deformável. Atribua "
    L"uma única animação a cada ecrã. Textura alterna entre superfícies texturadas e modelo em arame. A "
    L"rotação livre da câmara muda lentamente a direção da vista nas três dimensões. Paragens e inversões "
    L"de sentido acrescenta desacelerações, pausas e inversões aleatórias da rotação; o voo para a frente "
    L"continua. A velocidade vai de 0 a 1600%. Cada ecrã tem uma cena aleatória independente, apresentada à "
    L"sua própria frequência de atualização.\r\n\r\nA seleção das linhas determina os ecrãs a configurar e "
    L"é independente das caixas que ativam as saídas de animação. Ctrl+A seleciona todos os ecrãs; Ctrl e "
    L"Shift alteram a seleção. Todas as opções e controlos deslizantes da animação aplicam-se aos ecrãs "
    L"selecionados. A seleção é guardada separadamente para EXE e SCR. Se todos estavam selecionados, os "
    L"novos ecrãs também são incluídos.\r\n\r\nSelecione vários monitores; um duplo clique alterna uma "
    L"linha e todos podem ser desmarcados. Cada monitor usa uma cena independente. Captura guarda PNG e o "
    L"botão de gravação inicia ou termina MP4. Pausa para a animação. A aplicação também instala ou "
    L"desinstala a proteção de ecrã incorporada. As definições são guardadas continuamente. A aplicação só "
    L"pode ter uma instância em execução. Um novo arranque restaura a janela de controlo minimizada e "
    L"coloca-a em primeiro plano. Use Tab e Shift+Tab para passar entre controlos; Alt e a letra sublinhada "
    L"ativam um comando. Esc fecha a janela ativa de Ajuda ou Acerca de; na janela de controlo, termina a "
    L"aplicação. Bloquear proteção de ecrã durante a animação impede o início da proteção de ecrã do "
    L"Windows apenas enquanto a animação está efetivamente visível e não está em pausa.\r\n\r\nAs capturas "
    L"e gravações usam o primeiro monitor de animação ativo, não uma imagem conjunta de todos os monitores. "
    L"PNG usa Imagens, MP4 Vídeos; se essas pastas não existirem, usa-se Documentos. O botão Definições de "
    L"gravação permite escolher Viewport ou TV. Viewport conserva as dimensões e a frequência de "
    L"atualização do monitor de animação, até 60 fotogramas por segundo. TV oferece 1920 × 1080, 1440 × "
    L"1080 ou 1280 × 720 no formato 16:9, a 50, 25, 59.94 (60000/1001) ou 29.97 (30000/1001) fotogramas por "
    L"segundo. A proporção da imagem é mantida; TV usa vídeo progressivo BT.709 com intervalo limitado e "
    L"amostragem 4:2:0. A resolução e a frequência só estão disponíveis no modo TV. A janela Definições de "
    L"gravação pode ser minimizada e não bloqueia as outras janelas da aplicação. OK guarda as escolhas "
    L"para a próxima gravação MP4; Cancelar ou Esc descarta as alterações não confirmadas. O monitor "
    L"gravado não pode ser desmarcado durante a gravação; as alterações aos outros monitores não a "
    L"interrompem. Fechar a aplicação durante uma gravação exige confirmação, pois também termina a "
    L"gravação.\r\n\r\nOs sistemas Windows 7 a Windows 11 suportam todas as funcionalidades, incluindo "
    L"capturas PNG e gravação MP4. Para executar a aplicação no Windows Vista SP2, é necessário instalar as "
    L"atualizações KB971512 e KB2117917. A gravação MP4 não funciona no Vista na versão atual.",
    L"FlightCorridor: Przelot między czterema zmiennymi powierzchniami; Przelot przez zmienny lejek. "
    L"Każdemu monitorowi przypisz dokładnie jedną animację. Tekstura przełącza powierzchnie z teksturą i "
    L"model szkieletowy. Swobodne obracanie kamery powoli zmienia kierunek widoku we wszystkich trzech "
    L"wymiarach. Zatrzymania i zmiany kierunku dodają losowe zwalnianie, pauzy i odwracanie obrotu; lot do "
    L"przodu trwa nadal. Prędkość wynosi 0–1600%. Każdy monitor ma niezależną losową scenę wyświetlaną z "
    L"własną częstotliwością odświeżania.\r\n\r\nZaznaczenie wierszy określa konfigurowane monitory i jest "
    L"niezależne od pól wyboru włączających wyjścia animacji. Ctrl+A zaznacza wszystkie monitory; Ctrl i "
    L"Shift zmieniają zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą zaznaczonych monitorów. "
    L"Zaznaczenie jest zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były wszystkie monitory, nowe "
    L"również zostaną zaznaczone.\r\n\r\nNa liście można zaznaczyć wiele monitorów; podwójne kliknięcie "
    L"przełącza animację na monitorze, można też odznaczyć wszystkie. Każdy monitor ma niezależną scenę. "
    L"Zrzut zapisuje PNG, a przycisk nagrywania rozpoczyna lub kończy MP4. Wstrzymaj zatrzymuje animację. "
    L"Aplikacja instaluje i odinstalowuje również wbudowany wygaszacz. Ustawienia są zapisywane na bieżąco. "
    L"Aplikacja działa tylko w jednej instancji. Kolejne uruchomienie przywraca zminimalizowane okno "
    L"sterowania i przenosi na pierwszy plan. Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt "
    L"i podkreślona litera wywołują polecenie. Esc zamyka aktywne okno Pomocy lub O programie; w oknie "
    L"sterowania kończy działanie aplikacji. Blokuj wygaszacz podczas animacji zapobiega uruchomieniu "
    L"wygaszacza Windows tylko wtedy, gdy animacja jest rzeczywiście widoczna i nie jest "
    L"wstrzymana.\r\n\r\nZrzuty i nagrania obejmują pierwszy aktywny monitor animacji, a nie wspólny obraz "
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
    L"nagranie.\r\n\r\nSystemy od Windows 7 do Windows 11 obsługują wszystkie funkcje, w tym zrzuty PNG i "
    L"nagrywanie MP4. Do uruchomienia aplikacji w systemie Windows Vista SP2 konieczne jest zainstalowanie "
    L"aktualizacji KB971512 i KB2117917. Nagrywanie MP4 nie działa w Vista w obecnej wersji.",
    L"FlightCorridor: Prelet štyrmi premenlivými plochami; Prelet premenlivým lievikom. Každému monitoru "
    L"priraďte práve jednu animáciu. Textúra prepína medzi textúrovanými plochami a drôteným modelom. "
    L"Prevaľovanie kamery pomaly mení smer pohľadu vo všetkých troch rozmeroch. Zastavovanie a zmeny smeru "
    L"pridáva náhodné spomaľovanie, prestávky a zmeny smeru otáčania; dopredný pohyb pokračuje. Rýchlosť je "
    L"0–1600 %. Každý monitor má nezávislú náhodnú scénu vykresľovanú podľa vlastnej obnovovacej "
    L"frekvencie.\r\n\r\nOznačenie riadkov určuje, ktoré monitory práve nastavujete; je nezávislé od "
    L"políčok zapínajúcich animačné výstupy. Ctrl+A označí všetky monitory, Ctrl a Shift upravujú "
    L"označenie. Všetky animačné voľby a posuvníky platia pre označené monitory. Označenie sa pamätá zvlášť "
    L"pre EXE a SCR. Ak boli označené všetky monitory, označia sa aj novopripojené.\r\n\r\nV zozname možno "
    L"označiť viac monitorov; dvojklik zapína alebo vypína animáciu na monitore a možno zrušiť aj výber "
    L"všetkých. Každý monitor používa nezávislú scénu. Snímka uloží PNG a tlačidlo záznamu spustí alebo "
    L"ukončí MP4. Pozastavenie zastaví animáciu. Aplikácia tiež nainštaluje alebo odinštaluje vložený "
    L"šetrič. Nastavenia sa ukladajú priebežne. Aplikácia beží iba v jednej inštancii. Ďalšie spustenie "
    L"obnoví minimalizované ovládacie okno a prenesie do popredia. Medzi ovládacími prvkami prechádzajte "
    L"klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a príslušného písmena. Esc zavrie "
    L"aktívne okno Pomocníka alebo O aplikácii; v ovládacom okne ukončí aplikáciu. Voľba Blokovať šetrič "
    L"pri animácii bráni spusteniu šetriča Windows iba vtedy, keď je animácia skutočne viditeľná a nie je "
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
    L"FlightCorridor: Flyvetur mellem fire formskiftende flader; Flyvetur gennem en formskiftende tragt. "
    L"Tildel præcis én animation til hver skærm. Tekstur skifter mellem teksturerede flader og trådmodel. "
    L"Frit roterende kamera ændrer langsomt synsretningen i alle tre dimensioner. Stop og retningsskift "
    L"tilføjer tilfældige opbremsninger, pauser og ændringer af rotationsretningen; flyvningen fremad "
    L"fortsætter. Hastigheden er 0–1600 %. Hver skærm har en uafhængig tilfældig scene, der gengives med "
    L"dens egen opdateringsfrekvens.\r\n\r\nMarkeringen af rækker bestemmer, hvilke skærme du indstiller, "
    L"og er adskilt fra afkrydsningsfelterne, der aktiverer animationsoutput. Ctrl+A markerer alle skærme; "
    L"Ctrl og Skift ændrer markeringen. Alle animationsvalg og skydere gælder de markerede skærme. "
    L"Markeringen huskes separat for EXE og SCR. Hvis alle skærme var markeret, medtages også nye "
    L"skærme.\r\n\r\nVælg flere skærme i listen; dobbeltklik på en række for at slå animationen til eller "
    L"fra, eller fravælg alle. Hver skærm bruger en uafhængig scene. Skærmbillede gemmer PNG, og "
    L"optageknappen starter eller stopper MP4. Pause standser animationen. Programmet installerer eller "
    L"afinstallerer også den indbyggede pauseskærm. Indstillinger gemmes løbende. Programmet kan kun køre i "
    L"én instans ad gangen. En ny start gendanner det minimerede kontrolvindue og bringer det forrest. Brug "
    L"Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det understregede bogstav aktiverer en "
    L"kommando. Esc lukker det aktive Hjælp- eller Om-vindue; i kontrolvinduet afslutter det programmet. "
    L"Blokér pauseskærm under animation forhindrer Windows-pauseskærmen i at starte, men kun når "
    L"animationen faktisk er synlig og ikke er sat på pause.\r\n\r\nSkærmbilleder og optagelser bruger den "
    L"første aktive animationsskærm, ikke et samlet billede af alle skærme. PNG bruger Billeder, MP4 "
    L"Videoer; hvis disse mapper ikke findes, bruges Dokumenter. Knappen Optagelsesindstillinger vælger "
    L"Viewport eller TV. Viewport bevarer animationsskærmens størrelse og opdateringsfrekvens, højst 60 "
    L"billeder i sekundet. TV tilbyder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9 med 50, "
    L"25, 59.94 (60000/1001) eller 29.97 (30000/1001) billeder i sekundet. Billedets proportioner bevares; "
    L"TV bruger progressiv BT.709-video med begrænset område og 4:2:0-sampling. Opløsning og billedfrekvens "
    L"kan kun vælges i TV-tilstand. Vinduet Optagelsesindstillinger kan minimeres og blokerer ikke de andre "
    L"programvinduer. OK gemmer valgene til den næste MP4-optagelse; Annuller eller Esc kasserer "
    L"ubekræftede ændringer. Den skærm, der optages, kan ikke fravælges under optagelsen; ændringer af "
    L"andre skærme stopper ikke optagelsen. Hvis programmet lukkes under en optagelse, kræves en "
    L"bekræftelse, fordi optagelsen også afsluttes.\r\n\r\nWindows 7 til Windows 11 understøtter alle "
    L"funktioner, herunder PNG-skærmbilleder og MP4-optagelse. For at køre programmet på Windows Vista SP2 "
    L"skal opdateringerne KB971512 og KB2117917 installeres. MP4-optagelse fungerer ikke på Vista i den "
    L"aktuelle version.",
    L"FlightCorridor: Lento neljän muuntuvan pinnan välissä; Lento muuntuvan suppilon läpi. Valitse "
    L"kullekin näytölle yksi animaatio. Tekstuuri vaihtaa teksturoitujen pintojen ja rautalankamallin "
    L"välillä. Kameran vapaa pyörintä muuttaa katselusuuntaa hitaasti kaikissa kolmessa ulottuvuudessa. "
    L"Pysähdykset ja suunnanvaihdot lisää satunnaisia hidastuksia, taukoja ja pyörimissuunnan vaihtoja; "
    L"lento eteenpäin jatkuu. Nopeus on 0–1600%. Jokaisella näytöllä on itsenäinen satunnainen näkymä, joka "
    L"piirretään sen omalla virkistystaajuudella.\r\n\r\nRivien valinta määrää muokattavat näytöt ja on "
    L"erillinen animaatioulostulon valintaruuduista. Ctrl+A valitsee kaikki näytöt; Ctrl ja Vaihto "
    L"muuttavat valintaa. Kaikki animaatioasetukset ja liukusäätimet koskevat valittuja näyttöjä. Valinta "
    L"muistetaan erikseen EXE- ja SCR-tiloissa. Jos kaikki näytöt olivat valittuina, myös uudet näytöt "
    L"valitaan.\r\n\r\nLuettelosta voi valita useita näyttöjä; kaksoisnapsautus vaihtaa rivin tilaa ja "
    L"kaikkien näyttöjen valinnan voi poistaa. Jokaisella näytöllä on itsenäinen näkymä. Tilannekuva "
    L"tallentaa PNG:n ja tallennuspainike käynnistää tai lopettaa MP4:n. Keskeytä pysäyttää animaation. "
    L"Sovellus asentaa tai poistaa myös sisäisen näytönsäästäjän. Asetukset tallennetaan jatkuvasti. "
    L"Sovelluksesta voi olla käynnissä vain yksi instanssi. Uusi käynnistys palauttaa pienennetyn "
    L"ohjausikkunan ja tuo sen etualalle. Siirry säätimien välillä Tab- ja Vaihto+Tab-näppäimillä; Alt ja "
    L"alleviivattu kirjain aktivoivat komennon. Esc sulkee aktiivisen Ohje- tai Tietoja-ikkunan; "
    L"ohjausikkunassa se sulkee sovelluksen. Estä näytönsäästäjä animaation aikana estää Windowsin "
    L"näytönsäästäjän käynnistymisen vain silloin, kun animaatio on todella näkyvissä eikä sitä ole "
    L"keskeytetty.\r\n\r\nTilannekuvat ja tallenteet käyttävät ensimmäistä aktiivista animaationäyttöä, "
    L"eivät kaikkien näyttöjen yhdistettyä kuvaa. PNG käyttää Kuvat-kansiota ja MP4 Videot-kansiota; jos "
    L"niitä ei ole, käytetään Tiedostot-kansiota. Tallennusasetukset-painikkeella valitaan Viewport tai TV. "
    L"Viewport säilyttää animaationäytön koon ja virkistystaajuuden, enintään 60 kuvaa sekunnissa. TV "
    L"tarjoaa tarkkuudet 1920 × 1080, 1440 × 1080 ja 1280 × 720 kuvasuhteella 16:9 sekä taajuudet 50, 25, "
    L"59.94 (60000/1001) ja 29.97 (30000/1001) kuvaa sekunnissa. Kuvasuhde säilyy; TV käyttää "
    L"progressiivista BT.709-videota rajatulla alueella ja 4:2:0-näytteistyksellä. Tarkkuus ja kuvataajuus "
    L"ovat valittavissa vain TV-tilassa. Tallennusasetukset-ikkunan voi pienentää, eikä se estä muiden "
    L"sovellusikkunoiden käyttöä. OK tallentaa valinnat seuraavaa MP4-tallennusta varten; Peruuta tai Esc "
    L"hylkää vahvistamattomat muutokset. Tallennettavan näytön valintaa ei voi poistaa tallennuksen aikana; "
    L"muiden näyttöjen muutokset eivät pysäytä tallennusta. Sovelluksen sulkeminen tallennuksen aikana "
    L"vaatii vahvistuksen, sillä myös tallennus päättyy.\r\n\r\nWindows 7–Windows 11 tukevat kaikkia "
    L"toimintoja, myös PNG-tilannekuvia ja MP4-tallennusta. Sovelluksen suorittaminen Windows Vista SP2:ssa "
    L"edellyttää päivitysten KB971512 ja KB2117917 asentamista. MP4-tallennus ei toimi Vistassa nykyisessä "
    L"versiossa.",
    L"FlightCorridor: Flug milli fjögurra breytilegra flata; Flug í gegnum breytilega trekt. Veldu "
    L"nákvæmlega eina hreyfimynd fyrir hvern skjá. Áferð skiptir milli áferðarlagðra flata og víragrindar. "
    L"Frjáls snúningur myndavélar breytir sjónstefnunni hægt í öllum þremur víddum. Stopp og stefnuskipti "
    L"bætir við tilviljanakenndri hægingu, hléum og breytingum á snúningsstefnu; flug áfram heldur áfram. "
    L"Hraðinn er 0–1600%. Hver skjár hefur sjálfstæða tilviljanakennda senu sem er teiknuð á eigin "
    L"endurnýjunartíðni.\r\n\r\nVal lína ákvarðar hvaða skjám er verið að breyta og er óháð gátreitunum sem "
    L"kveikja á hreyfimyndaúttaki. Ctrl+A velur alla skjái; Ctrl og Shift breyta valinu. Allir valkostir og "
    L"sleðar hreyfimynda gilda fyrir valda skjái. Valið er munað sérstaklega fyrir EXE og SCR. Ef allir "
    L"skjáir voru valdir bætast nýir skjáir einnig við valið.\r\n\r\nVelja má marga skjái; tvísmellur "
    L"virkjar eða slekkur á hreyfimynd á skjá og afvelja má alla skjái. Hver skjár notar sjálfstæða senu. "
    L"Skjámynd vistar PNG og upptökuhnappurinn ræsir eða stöðvar MP4. Hnappurinn Gera hlé stöðvar "
    L"hreyfimyndina. Forritið setur einnig upp eða fjarlægir innbyggðu skjáhvíluna. Stillingar vistast "
    L"jafnóðum. Aðeins eitt eintak af forritinu getur verið í gangi í einu. Ný ræsing endurheimtir "
    L"lágmarkaðan stjórngluggann og færir hann fremst. Notaðu Tab og Shift+Tab til að færa þig milli "
    L"stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc lokar virka Hjálp- eða Um-glugganum; í "
    L"stjórnglugganum lokar það forritinu. Hindra skjáhvílu meðan hreyfimynd er í gangi kemur aðeins í veg "
    L"fyrir að skjáhvíla Windows fari í gang meðan hreyfimyndin er í raun sýnileg og ekki í "
    L"pásu.\r\n\r\nSkjámyndir og upptökur nota fyrsta virka hreyfimyndaskjáinn, ekki sameinaða mynd af "
    L"öllum skjám. PNG notar Myndir, MP4 Myndbönd; ef þær möppur eru ekki til er Skjöl notuð. Hnappurinn "
    L"Upptökustillingar velur Viewport eða TV. Viewport varðveitir stærð og endurnýjunartíðni "
    L"hreyfimyndaskjásins, þó mest 60 ramma á sekúndu. TV býður upp á 1920 × 1080, 1440 × 1080 eða 1280 × "
    L"720 í hlutfallinu 16:9 með 50, 25, 59.94 (60000/1001) eða 29.97 (30000/1001) römmum á sekúndu. "
    L"Hlutföll myndarinnar haldast; TV notar stigvaxandi BT.709-myndband með takmörkuðu sviði og "
    L"4:2:0-sýnatöku. Upplausn og rammatíðni eru aðeins valanleg í TV-ham. Hægt er að lágmarka gluggann "
    L"Upptökustillingar og hann hindrar ekki notkun annarra glugga forritsins. Í lagi vistar valið fyrir "
    L"næstu MP4-upptöku; Hætta við eða Esc hendir óstaðfestum breytingum. Ekki er hægt að afvelja skjáinn "
    L"sem er tekinn upp meðan upptaka stendur yfir; breytingar á öðrum skjám stöðva ekki upptökuna. "
    L"Staðfesta þarf lokun forritsins meðan upptaka stendur yfir, því hún stöðvar líka "
    L"upptökuna.\r\n\r\nWindows 7 til Windows 11 styðja alla eiginleika, þar á meðal PNG-skjámyndir og "
    L"MP4-upptöku. Til að keyra forritið á Windows Vista SP2 þarf að setja upp uppfærslurnar KB971512 og "
    L"KB2117917. MP4-upptaka virkar ekki í Vista í núverandi útgáfu.",
    L"FlightCorridor: Flytur mellom fire formendrende flater; Flytur gjennom en formendrende trakt. "
    L"Tilordne nøyaktig én animasjon til hver skjerm. Tekstur veksler mellom teksturerte flater og "
    L"trådmodell. Fritt roterende kamera endrer synsretningen langsomt i alle tre dimensjoner. Stopp og "
    L"retningsendringer legger til tilfeldige oppbremsinger, pauser og endringer i rotasjonsretningen; "
    L"flyvningen fremover fortsetter. Hastigheten er 0–1600 %. Hver skjerm har en uavhengig tilfeldig scene "
    L"som gjengis ved dens egen oppdateringsfrekvens.\r\n\r\nMarkeringen av rader bestemmer hvilke skjermer "
    L"du redigerer, og er atskilt fra avkrysningsboksene som aktiverer animasjonsutgangen. Ctrl+A markerer "
    L"alle skjermer; Ctrl og Skift endrer markeringen. Alle animasjonsvalg og glidebrytere gjelder de "
    L"markerte skjermene. Markeringen huskes separat for EXE og SCR. Hvis alle skjermer var markert, "
    L"inkluderes også nye skjermer.\r\n\r\nVelg flere skjermer i listen; dobbeltklikk en rad for å slå "
    L"animasjonen av eller på, eller fjern valget for alle. Hver skjerm bruker en uavhengig scene. "
    L"Skjermbilde lagrer PNG, og opptaksknappen starter eller stopper MP4. Pause stanser animasjonen. "
    L"Programmet installerer eller avinstallerer også den innebygde skjermspareren. Innstillingene lagres "
    L"fortløpende. Bare én instans av programmet kan kjøre om gangen. En ny start gjenoppretter det "
    L"minimerte kontrollvinduet og bringer det fremst. Bruk Tab og Shift+Tab for å flytte mellom "
    L"kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc lukker det aktive Hjelp- "
    L"eller Om-vinduet; i kontrollvinduet avslutter det programmet. Hindre skjermsparer under animasjon "
    L"hindrer Windows-skjermspareren i å starte bare når animasjonen faktisk er synlig og ikke er satt på "
    L"pause.\r\n\r\nSkjermbilder og opptak bruker den første aktive animasjonsskjermen, ikke et samlet "
    L"bilde av alle skjermene. PNG bruker Bilder, MP4 Videoer; hvis disse mappene ikke finnes, brukes "
    L"Dokumenter. Knappen Opptaksinnstillinger velger Viewport eller TV. Viewport beholder "
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
    L"FlightCorridor: Flygtur mellan fyra formföränderliga ytor; Flygtur genom en formföränderlig tratt. "
    L"Tilldela varje skärm exakt en animering. Textur växlar mellan texturerade ytor och trådmodell. Fritt "
    L"roterande kamera ändrar långsamt blickriktningen i alla tre dimensioner. Stopp och riktningsbyten "
    L"lägger till slumpmässiga inbromsningar, pauser och byten av rotationsriktning; flygningen framåt "
    L"fortsätter. Hastigheten är 0–1600 %. Varje skärm har en oberoende slumpmässig scen som återges med "
    L"dess egen uppdateringsfrekvens.\r\n\r\nMarkeringen av rader avgör vilka skärmar du redigerar och är "
    L"skild från kryssrutorna som aktiverar animationsutgångarna. Ctrl+A markerar alla skärmar; Ctrl och "
    L"Skift ändrar markeringen. Alla animationsalternativ och reglage gäller de markerade skärmarna. "
    L"Markeringen sparas separat för EXE och SCR. Om alla skärmar var markerade inkluderas även nya "
    L"skärmar.\r\n\r\nVälj flera bildskärmar i listan; dubbelklicka en rad för att slå på eller av "
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
    L"FlightCorridor: Biçim değiştiren dört yüzey arasında uçuş; Biçim değiştiren bir huninin içinden uçuş. "
    L"Her ekrana tam bir animasyon atayın. Doku, dokulu yüzeyler ile tel kafes modeli arasında geçiş yapar. "
    L"Serbest kamera dönüşü bakış yönünü üç boyutta yavaşça değiştirir. Duraklamalar ve yön değişimleri, "
    L"dönüşe rastgele yavaşlamalar, duraklamalar ve ters yön değişimleri ekler; ileri uçuş devam eder. Hız "
    L"0–1600% aralığındadır. Her ekranın kendi yenileme hızında çizilen bağımsız rastgele bir sahnesi "
    L"vardır.\r\n\r\nSatır seçimi, hangi ekranların düzenlendiğini belirler; animasyon çıkışlarını açan "
    L"onay kutularından ayrıdır. Ctrl+A tüm ekranları seçer; Ctrl ve Shift seçimi değiştirir. Tüm animasyon "
    L"seçenekleri ve kaydırıcılar seçili ekranlara uygulanır. Seçim EXE ve SCR için ayrı saklanır. Tüm "
    L"ekranlar seçiliyse sonradan bağlanan ekranlar da seçime katılır.\r\n\r\nListede birden çok monitör "
    L"seçilebilir; satıra çift tıklamak monitördeki animasyonu açıp kapatır; tüm monitörlerin seçimi de "
    L"kaldırılabilir. Her monitör bağımsız sahne kullanır. Anlık görüntü PNG kaydeder; kayıt düğmesi MP4 "
    L"kaydını başlatır veya bitirir. Duraklat animasyonu durdurur. Uygulama gömülü ekran koruyucuyu da "
    L"kurar veya kaldırır. Ayarlar sürekli kaydedilir. Uygulamanın aynı anda yalnızca bir örneği "
    L"çalışabilir. Yeniden başlatılması, simge durumuna küçültülmüş denetim penceresini geri yükler ve ön "
    L"plana getirir. Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir komutu "
    L"etkinleştirir. Esc, etkin Yardım veya Hakkında penceresini kapatır; denetim penceresinde uygulamadan "
    L"çıkar. Animasyon sırasında ekran koruyucuyu engelle seçeneği, Windows ekran koruyucusunun yalnızca "
    L"animasyon gerçekten görünürken ve duraklatılmamışken başlamasını engeller.\r\n\r\nAnlık görüntüler ve "
    L"kayıtlar, tüm monitörlerin birleşik görüntüsünü değil, ilk etkin animasyon monitörünü kullanır. PNG "
    L"Resimler, MP4 Videolar klasörünü kullanır; bu klasörler yoksa Belgeler kullanılır. Kayıt ayarları "
    L"düğmesi Viewport veya TV seçimini açar. Viewport, animasyon monitörünün boyutlarını ve yenileme "
    L"hızını saniyede en fazla 60 kareyle korur. TV, 16:9 oranında 1920 × 1080, 1440 × 1080 veya 1280 × 720 "
    L"çözünürlük ile saniyede 50, 25, 59.94 (60000/1001) veya 29.97 (30000/1001) kare sunar. Görüntünün en "
    L"boy oranı korunur; TV, sınırlı aralıklı, 4:2:0 örneklemeli ilerlemeli BT.709 video kullanır. "
    L"Çözünürlük ve kare hızı yalnızca TV modunda seçilebilir. Kayıt ayarları penceresi simge durumuna "
    L"küçültülebilir ve uygulamanın diğer pencerelerini engellemez. Tamam, seçenekleri bir sonraki MP4 "
    L"kaydı için kaydeder; İptal veya Esc onaylanmamış değişiklikleri iptal eder. Kayıt sırasında "
    L"kaydedilen ekranın seçimi kaldırılamaz; diğer ekranlardaki değişiklikler kaydı durdurmaz. Kayıt "
    L"sırasında uygulamayı kapatmak kaydı da durduracağı için onay gerektirir.\r\n\r\nWindows 7 ile Windows "
    L"11 arasındaki sürümler, PNG anlık görüntüler ve MP4 kaydı dâhil tüm özellikleri destekler. Uygulamayı "
    L"Windows Vista SP2'de çalıştırmak için KB971512 ve KB2117917 güncellemelerini yüklemeniz gerekir. "
    L"Geçerli sürümde MP4 kaydı Vista'da çalışmaz.",
    L"Riistvarakiirendusega lend muutuvate pindade vahel. Lend nelja muutuva pinna vahel; Lend läbi muutuva "
    L"lehtri. Valige igale kuvarile täpselt üks animatsioon. Tekstuuri märkeruut vahetab tekstuuriga pinna "
    L"ja traatmudeli vahel. Kaamera vaba pöörlemine muudab vaatesuunda aeglaselt kõigis kolmes mõõtmes. "
    L"Peatumised ja suunavahetused lisab sellele juhuslikke aeglustusi, pause ja pöörlemissuuna muutusi; "
    L"edasilend jätkub. Kiirus on seatav vahemikus 0–1600%. Igal kuvaril on oma sõltumatu juhuslik stseen "
    L"ja värskendussagedusele vastav renderdus.\r\n\r\nValige loendis üks või mitu kuvaririda. Ctrl+A valib "
    L"kõik read; Ctrl ja Shift võimaldavad valikut muuta. Animatsiooni juhtnupud ja liugurid mõjutavad "
    L"ainult valitud kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle märkeruuduga väljundi "
    L"lubamine on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja jaoks eraldi meelde. Kui varem "
    L"olid valitud kõik kuvarid, kaasatakse ka lisatud kuvarid.\r\n\r\nKäivitage FlightCorridor.exe. "
    L"Sätteid salvestatakse jooksvalt ning rakendus töötab ühe eksemplarina. Kuvari märkeruut või "
    L"topeltklõps real lülitab selle animatsiooniväljundi sisse või välja. Animatsiooni saab peatada ja "
    L"jätkata. PNG-pilt ja MP4-video jäädvustavad esimese aktiivse animatsioonikuvari, mitte kõiki kuvareid "
    L"koos. Salvestatavat kuvarit ei saa salvestamise ajal välja lülitada; rakenduse sulgemine nõuab siis "
    L"kinnitust. Ekraanisäästja tõkestamine kehtib ühiselt ja ainult siis, kui vastava valikuga kuvaril on "
    L"nähtav peatamata animatsioon. Rakendus saab paigaldada ja eemaldada sisseehitatud "
    L"ekraanisäästja.\r\n\r\nSalvestussätetes valige Viewport või TV. Viewport säilitab kuvari mõõtmed ja "
    L"värskendussageduse kuni 60 kaadrit sekundis. TV pakub 1920 × 1080, 1440 × 1080 või 1280 × 720 "
    L"väljundit kuvasuhtega 16:9 ning 50, 25, 59.94 (60000/1001) või 29.97 (30000/1001) kaadrit sekundis. "
    L"TV-video on progressiivne BT.709, piiratud vahemikuga ja 4:2:0 värvialamdiskreetimisega. Pildi "
    L"kuvasuhe säilib ja täiteribad on mustad. OK rakendab valikud järgmisele salvestusele; Loobu või Esc "
    L"tühistab kinnitamata muudatused. Salvestussätted, spikker ja teave ei blokeeri teisi aknaid ning neid "
    L"saab minimeerida. Tab ja Shift+Tab liigutavad fookust, Enter vajutab fookusega nuppu ning Esc sulgeb "
    L"aktiivse lisaakna.\r\n\r\nWindows 7–11 toetab kõiki funktsioone. Windows Vista SP2 jaoks tuleb "
    L"paigaldada värskendused KB971512 ja KB2117917; MP4 salvestamine Vistas ei tööta. Vaja on Direct3D 11 "
    L"tuge ning MP4 jaoks Media Foundationi ja H.264 kodeerijat. Liides ja dokumentatsioon on saadaval 36 "
    L"keeles.",
    L"Eitilt idir dromchlaí athraitheacha le luasghéarú crua-earraí. Eitilt idir ceithre dhromchla "
    L"athraitheacha; Eitilt trí thonnadóir athraitheach. Roghnaigh beochan amháin do gach monatóir. "
    L"Athraíonn Uigeacht idir dromchla uigeachtaithe agus samhail sreangfhráma. Rothlaíonn rothlú saor an "
    L"cheamara an radharc go mall sna trí thoise. Cuireann Stadanna agus aisiompuithe coscánú, sosanna agus "
    L"athruithe treo randamacha leis an rothlú; leanann an eitilt chun tosaigh. Tá luas 0–1600% ar fáil. Tá "
    L"radharc randamach neamhspleách ag gach monatóir agus déantar rindreáil de réir a ráta athnuachana "
    L"féin.\r\n\r\nRoghnaigh ró amháin nó níos mó sa liosta monatóirí. Roghnaíonn Ctrl+A gach ró; úsáid "
    L"Ctrl agus Shift chun an roghnú a athrú. Ní athraíonn rialuithe agus sleamhnáin na beochana ach "
    L"socruithe na monatóirí roghnaithe. Ní hionann ró a roghnú agus aschur an mhonatóra a chumasú lena "
    L"bhosca seiceála. Cuimhnítear an roghnú ar leith don fheidhmchlár agus don spárálaí. Má bhí gach "
    L"monatóir roghnaithe, cuirtear monatóirí nua leis an roghnú freisin.\r\n\r\nRith FlightCorridor.exe. "
    L"Sábháiltear socruithe go leanúnach agus ní ritheann ach cóip amháin den fheidhmchlár. Cumasaíonn nó "
    L"díchumasaíonn bosca seiceála an mhonatóra nó déchliceáil ar a ró an t-aschur beochana. Is féidir an "
    L"bheochan a chur ar sos agus a atosú. Gabhann PNG agus MP4 an chéad mhonatóir beochana gníomhach, ní "
    L"na monatóirí uile le chéile. Ní féidir an monatóir atá á thaifeadadh a dhíchumasú; teastaíonn "
    L"deimhniú chun an feidhmchlár a dhúnadh agus taifeadadh ar siúl. Baineann cosc an spárálaí leis an "
    L"seisiún iomlán, ach amháin agus beochan infheicthe gan sos ar mhonatóir a bhfuil an rogha sin "
    L"cumasaithe dó. Is féidir an spárálaí leabaithe a shuiteáil nó a dhíshuiteáil ón "
    L"bhfeidhmchlár.\r\n\r\nRoghnaigh Viewport nó TV i socruithe taifeadta. Coinníonn Viewport toisí agus "
    L"ráta athnuachana an mhonatóra, suas le 60 fráma sa soicind. Tairgeann TV 1920 × 1080, 1440 × 1080 nó "
    L"1280 × 720 i gcóimheas 16:9 ag 50, 25, 59.94 (60000/1001) nó 29.97 (30000/1001) fráma sa soicind. Is "
    L"físeán forásach BT.709 é, le raon teoranta agus foshampláil datha 4:2:0. Coinnítear cóimheas an "
    L"phictiúir agus tá na barraí líonta dubh. Cuireann OK roghanna i bhfeidhm ar an gcéad taifeadadh eile; "
    L"cealaíonn Cealaigh nó Esc athruithe neamhdheimhnithe. Ní chuireann socruithe taifeadta, Cabhair ná "
    L"Maidir leis bac ar fhuinneoga eile agus is féidir iad a íoslaghdú. Bogann Tab agus Shift+Tab an "
    L"fócas; gníomhaíonn Enter an cnaipe faoi fhócas agus dúnann Esc an fhuinneog chúnta "
    L"ghníomhach.\r\n\r\nTacaíonn Windows 7–11 leis na gnéithe uile. Ar Windows Vista SP2 ní mór "
    L"nuashonruithe KB971512 agus KB2117917 a shuiteáil; ní oibríonn taifeadadh MP4 ar Vista. Teastaíonn "
    L"tacaíocht Direct3D 11, agus Media Foundation agus ionchódóir H.264 le haghaidh MP4. Tá an comhéadan "
    L"agus an doiciméadú ar fáil i 36 teanga.",
    L"Aparatine įranga spartinamas skrydis tarp kintančių paviršių. Skrydis tarp keturių kintančių "
    L"paviršių; Skrydis kintančiu piltuvu. Kiekvienam monitoriui pasirinkite vieną animaciją. Tekstūros "
    L"langelis perjungia tekstūruotą paviršių ir vielinį modelį. Laisvas kameros sukimasis lėtai keičia "
    L"žiūrėjimo kryptį visose trijose dimensijose. Sustojimai ir krypties keitimai prideda atsitiktinį "
    L"lėtėjimą, pauzes ir sukimosi krypties keitimą; skrydis pirmyn tęsiasi. Galimas 0–1600% greitis. "
    L"Kiekvienas monitorius turi nepriklausomą atsitiktinę sceną, atvaizduojamą jo atnaujinimo "
    L"dažniu.\r\n\r\nMonitorių sąraše pasirinkite vieną ar kelias eilutes. Ctrl+A pasirenka visas, o Ctrl "
    L"ir Shift leidžia keisti pasirinkimą. Animacijos valdikliai ir slankikliai keičia tik pasirinktų "
    L"monitorių nuostatas. Eilutės pasirinkimas nėra tas pats, kas animacijos išvesties įjungimas jos "
    L"žymimuoju langeliu. Pasirinkimas atskirai įsimenamas programai ir užsklandai. Jei buvo pasirinkti "
    L"visi monitoriai, į pasirinkimą įtraukiami ir naujai prijungti monitoriai.\r\n\r\nPaleiskite "
    L"FlightCorridor.exe. Nuostatos išsaugomos nuolat, veikia tik vienas programos egzempliorius. "
    L"Monitoriaus langelis arba dvigubas eilutės spustelėjimas įjungia ar išjungia animacijos išvestį. "
    L"Animaciją galima pristabdyti ir tęsti. PNG ir MP4 fiksuoja pirmą aktyvų animacijos monitorių, o ne "
    L"bendrą visų monitorių vaizdą. Įrašomo monitoriaus išjungti negalima; uždarant programą vykstant "
    L"įrašymui reikia patvirtinimo. Užsklandos blokavimas yra bendras ir galioja tik kol monitoriuje su "
    L"įjungta šia nuostata matoma nepristabdyta animacija. Programa gali įdiegti ir pašalinti į ją įtrauktą "
    L"užsklandą.\r\n\r\nĮrašymo nuostatose pasirinkite Viewport arba TV. Viewport išsaugo monitoriaus "
    L"matmenis ir dažnį iki 60 kadrų per sekundę. TV siūlo 1920 × 1080, 1440 × 1080 arba 1280 × 720 išvestį "
    L"16:9 santykiu bei 50, 25, 59.94 (60000/1001) arba 29.97 (30000/1001) kadrų per sekundę. TV vaizdas "
    L"progresinis, BT.709, riboto diapazono ir 4:2:0 spalvų diskretizavimo. Vaizdo proporcijos išlieka, "
    L"užpildymo juostos juodos. OK pritaiko nuostatas kitam įrašui, Atšaukti arba Esc atmeta nepatvirtintus "
    L"pakeitimus. Įrašymo, žinyno ir informacijos langai neblokuoja kitų langų ir gali būti sumažinti. Tab "
    L"ir Shift+Tab keičia įvesties vietą, Enter paspaudžia aktyvų mygtuką, Esc uždaro aktyvų papildomą "
    L"langą.\r\n\r\nWindows 7–11 palaiko visas funkcijas. Windows Vista SP2 būtina įdiegti naujinimus "
    L"KB971512 ir KB2117917; MP4 įrašymas Vistoje neveikia. Reikalingas Direct3D 11 palaikymas, o MP4 "
    L"įrašymui Media Foundation ir H.264 koduotuvas. Sąsaja ir dokumentacija pateikiamos 36 kalbomis.",
    L"Aparatūras paātrināts lidojums starp mainīgām virsmām. Lidojums starp četrām mainīgām virsmām; "
    L"Lidojums caur mainīgu piltuvi. Katram monitoram izvēlieties tieši vienu animāciju. Tekstūras rūtiņa "
    L"pārslēdz teksturētu virsmu un stiepļu modeli. Brīva kameras rotācija lēnām maina skatiena virzienu "
    L"visās trijās dimensijās. Apstāšanās un virziena maiņa pievieno nejaušu palēninājumu, pauzes un "
    L"rotācijas virziena maiņu; lidojums uz priekšu turpinās. Pieejams ātrums 0–1600%. Katram monitoram ir "
    L"neatkarīga nejauša aina, ko renderē tā atsvaidzināšanas frekvencē.\r\n\r\nMonitoru sarakstā atlasiet "
    L"vienu vai vairākas rindas. Ctrl+A atlasa visas, bet Ctrl un Shift ļauj mainīt atlasi. Animācijas "
    L"vadīklas un slīdņi maina tikai atlasīto monitoru iestatījumus. Rindas atlasīšana nav tas pats, kas "
    L"animācijas izvades ieslēgšana ar izvēles rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un "
    L"ekrānsaudzētājam. Ja bija atlasīti visi monitori, atlasē iekļauj arī jaunpievienotos "
    L"monitorus.\r\n\r\nPalaidiet FlightCorridor.exe. Iestatījumi tiek saglabāti nepārtraukti, un darbojas "
    L"tikai viena lietotnes instance. Monitora rūtiņa vai dubultklikšķis uz rindas ieslēdz vai izslēdz tā "
    L"animācijas izvadi. Animāciju var pauzēt un turpināt. PNG un MP4 uzņem pirmo aktīvo animācijas "
    L"monitoru, nevis visu monitoru kopējo attēlu. Ierakstāmo monitoru nevar izslēgt; aizverot lietotni "
    L"ieraksta laikā, nepieciešams apstiprinājums. Ekrānsaudzētāja bloķēšana ir kopīga un darbojas tikai "
    L"tad, kamēr monitorā ar ieslēgtu šo iespēju ir redzama nepauzēta animācija. Lietotne var instalēt vai "
    L"atinstalēt tajā iebūvēto ekrānsaudzētāju.\r\n\r\nIeraksta iestatījumos izvēlieties Viewport vai TV. "
    L"Viewport saglabā monitora izmērus un frekvenci līdz 60 kadriem sekundē. TV piedāvā 1920 × 1080, 1440 "
    L"× 1080 vai 1280 × 720 izvadi ar 16:9 malu attiecību un 50, 25, 59.94 (60000/1001) vai 29.97 "
    L"(30000/1001) kadriem sekundē. TV video ir progresīvs BT.709 ar ierobežotu diapazonu un 4:2:0 krāsu "
    L"apakšiztveršanu. Attēla proporcijas saglabājas, aizpildījuma joslas ir melnas. OK piemēro izvēles "
    L"nākamajam ierakstam, Atcelt vai Esc atmet neapstiprinātās izmaiņas. Ieraksta iestatījumu, palīdzības "
    L"un informācijas logi nebloķē citus logus un ir minimizējami. Tab un Shift+Tab pārvieto fokusu, Enter "
    L"aktivizē fokusēto pogu, Esc aizver aktīvo palīglogu.\r\n\r\nWindows 7–11 atbalsta visas funkcijas. "
    L"Windows Vista SP2 jāinstalē atjauninājumi KB971512 un KB2117917; MP4 ierakstīšana Vistā nedarbojas. "
    L"Nepieciešams Direct3D 11 atbalsts, bet MP4 vajadzīgi Media Foundation un H.264 kodētājs. Saskarne un "
    L"dokumentācija ir pieejama 36 valodās.",
    L"Hardveresen gyorsított repülés változó felületek között. Repülés négy változó felület között; Repülés "
    L"változó tölcsérben. Monitoronként pontosan egy animáció választható. A Textúra jelölőnégyzet a "
    L"textúrázott felület és a drótváz között vált. A kamera szabad forgása lassan változtatja a nézetet "
    L"mindhárom dimenzióban. A Megállások és irányváltások véletlenszerű lassításokat, szüneteket és "
    L"forgásirányváltásokat ad hozzá; az előrehaladás folytatódik. A sebesség 0–1600%. Minden monitor "
    L"önálló véletlenszerű jelenetet kap, saját frissítési gyakoriságához igazodó "
    L"megjelenítéssel.\r\n\r\nJelöljön ki egy vagy több sort a monitorok listájában. A Ctrl+A mindet "
    L"kijelöli; a Ctrl és a Shift módosítja a kijelölést. Az animáció vezérlői és csúszkái csak a kijelölt "
    L"monitorok beállításait változtatják. A sor kijelölése és az animációs kimenet jelölőnégyzetes "
    L"engedélyezése külön művelet. A kijelölést az alkalmazás és a képernyőkímélő külön megjegyzi. Ha "
    L"korábban minden monitor ki volt jelölve, az újonnan csatlakoztatott monitorok is bekerülnek a "
    L"kijelölésbe.\r\n\r\nIndítsa el a FlightCorridor.exe fájlt. A beállítások folyamatosan mentődnek, és "
    L"csak egy alkalmazáspéldány fut. A monitor jelölőnégyzete vagy a sorra történő dupla kattintás "
    L"kapcsolja az animációs kimenetet. Az animáció szüneteltethető és folytatható. A PNG és az MP4 az első "
    L"aktív animációs monitort rögzíti, nem az összes monitor egyesített képét. A rögzített monitor "
    L"felvétel közben nem kapcsolható ki; az alkalmazás bezárásához ekkor megerősítés szükséges. A "
    L"képernyőkímélő tiltása közös, és csak akkor aktív, ha egy ezt kérő monitoron látható, nem szünetelő "
    L"animáció fut. Az alkalmazás telepítheti és eltávolíthatja a beágyazott képernyőkímélőt.\r\n\r\nA "
    L"felvételi beállításoknál Viewport vagy TV választható. A Viewport megőrzi a monitor képméretét és "
    L"frissítési gyakoriságát, legfeljebb 60 képkocka/másodpercig. A TV felbontása 1920 × 1080, 1440 × 1080 "
    L"vagy 1280 × 720, képaránya 16:9; sebessége 50, 25, 59.94 (60000/1001) vagy 29.97 (30000/1001) "
    L"képkocka/másodperc. A TV videó progresszív BT.709, korlátozott tartománnyal és 4:2:0 "
    L"színmintavételezéssel. A kép arányai megmaradnak, a kitöltősávok feketék. Az OK a következő "
    L"felvételhez menti a választást; a Mégse vagy Esc elveti a nem jóváhagyott módosításokat. A felvételi "
    L"beállítások, a Súgó és a Névjegy nem blokkolja a többi ablakot és kis méretűre állítható. A Tab és "
    L"Shift+Tab mozgatja a fókuszt, az Enter aktiválja a fókuszban levő gombot, az Esc bezárja az aktív "
    L"kiegészítő ablakot.\r\n\r\nA Windows 7–11 minden funkciót támogat. Windows Vista SP2 alatt telepíteni "
    L"kell a KB971512 és KB2117917 frissítést; az MP4-felvétel Vistán nem működik. Direct3D 11 támogatás "
    L"szükséges, az MP4-hez Media Foundation és H.264-kódoló is kell. A kezelőfelület és a dokumentáció 36 "
    L"nyelven érhető el.",
    L"Titjira bejn uċuħ li jinbidlu aċċellerata bil-ħardwer. Titjira bejn erba’ uċuħ li jinbidlu; Titjira "
    L"f’lembut li jinbidel. Agħżel animazzjoni waħda biss għal kull moniter. Nisġa taqleb bejn wiċċ b’nisġa "
    L"u mudell bil-wireframe. Ir-rotazzjoni libera tal-kamera tbiddel id-direzzjoni tal-ħarsa bil-mod "
    L"fit-tliet dimensjonijiet. Waqfiet u bidliet fid-direzzjoni żżid deċelerazzjonijiet, pawżi u treġġigħ "
    L"lura tar-rotazzjoni b’mod każwali; it-titjira ’l quddiem tkompli. Il-veloċità hija 0–1600%. Kull "
    L"moniter għandu xena każwali indipendenti li tintwera bir-rata ta’ aġġornament tiegħu.\r\n\r\nAgħżel "
    L"ringiela waħda jew aktar fil-lista tal-moniters. Ctrl+A jagħżilhom kollha; Ctrl u Shift ibiddlu "
    L"l-għażla. Il-kontrolli u s-sliders tal-animazzjoni jibdlu biss is-settings tal-moniters magħżula. "
    L"L-għażla ta’ ringiela hija differenti mill-attivazzjoni tal-output permezz tal-kaxxa tal-marka. "
    L"L-għażla tinżamm separatament għall-applikazzjoni u għall-iscreen saver. Jekk il-moniters kollha "
    L"kienu magħżula, il-moniters ġodda jiddaħħlu wkoll fl-għażla.\r\n\r\nĦaddem FlightCorridor.exe. "
    L"Is-settings jiġu ssejvjati kontinwament u taħdem istanza waħda biss. Il-kaxxa tal-moniter jew klikk "
    L"doppja fuq ir-ringiela tattiva jew tiddiżattiva l-output tal-animazzjoni. Tista’ tissospendi u "
    L"tkompli l-animazzjoni. PNG u MP4 jaqbdu l-ewwel moniter tal-animazzjoni attiv, mhux immaġni magħquda "
    L"tal-moniters kollha. Il-moniter li qed jiġi rreġistrat ma jistax jiġi diżattivat; l-għeluq "
    L"tal-applikazzjoni waqt reġistrazzjoni jeħtieġ konferma. L-imblukkar tal-iscreen saver japplika "
    L"għas-sessjoni kollha u biss waqt animazzjoni viżibbli mhux sospiża fuq moniter bl-għażla attiva. "
    L"L-applikazzjoni tinstalla jew tneħħi l-iscreen saver inkorporat.\r\n\r\nFis-settings "
    L"tar-reġistrazzjoni agħżel Viewport jew TV. Viewport iżomm id-dimensjonijiet u r-rata ta’ aġġornament "
    L"tal-moniter, sa 60 frejm kull sekonda. TV joffri 1920 × 1080, 1440 × 1080 jew 1280 × 720 f’16:9, "
    L"b’50, 25, 59.94 (60000/1001) jew 29.97 (30000/1001) frejm kull sekonda. Il-vidjo TV huwa progressiv "
    L"BT.709, b’medda limitata u sottokampjunar tal-kulur 4:2:0. Il-proporzjonijiet jinżammu u l-faxex ta’ "
    L"mili huma suwed. OK isalva l-għażliet għar-reġistrazzjoni li jmiss; Ikkanċella jew Esc jarmi bidliet "
    L"mhux ikkonfermati. It-twieqi tar-reġistrazzjoni, Għajnuna u Dwar ma jimblukkawx twieqi oħra u jistgħu "
    L"jiġu minimizzati. Tab u Shift+Tab ibiddlu l-fokus, Enter jattiva l-buttuna fil-fokus u Esc jagħlaq "
    L"it-tieqa awżiljarja attiva.\r\n\r\nWindows 7–11 jappoġġja l-funzjonijiet kollha. Fuq Windows Vista "
    L"SP2 għandhom jiġu installati l-aġġornamenti KB971512 u KB2117917; ir-reġistrazzjoni MP4 ma taħdimx "
    L"fuq Vista. Huwa meħtieġ Direct3D 11 u, għall-MP4, Media Foundation u encoder H.264. L-interface u "
    L"d-dokumentazzjoni huma disponibbli f’36 lingwa.",
    L"Hardwareversnelde vlucht tussen vervormende oppervlakken. Vlucht tussen vier vervormende "
    L"oppervlakken; Vlucht door een vervormende trechter. Kies precies één animatie per beeldscherm. "
    L"Textuur schakelt tussen een getextureerd oppervlak en een draadmodel. Vrije camerarotatie verandert "
    L"de kijkrichting langzaam in alle drie dimensies. Stops en richtingswisselingen voegt willekeurige "
    L"vertragingen, pauzes en omkeringen van de rotatie toe; de voorwaartse vlucht gaat door. De snelheid "
    L"is instelbaar op 0–1600%. Elk beeldscherm heeft een onafhankelijke willekeurige scène en wordt op "
    L"zijn eigen vernieuwingsfrequentie aangestuurd.\r\n\r\nSelecteer één of meer beeldschermrijen in de "
    L"lijst. Ctrl+A selecteert alles; met Ctrl en Shift past u de selectie aan. Animatieknoppen en "
    L"schuifregelaars wijzigen alleen de instellingen van de geselecteerde beeldschermen. Een rij "
    L"selecteren is iets anders dan de animatie-uitvoer inschakelen met het selectievakje. De selectie "
    L"wordt apart onthouden voor de toepassing en de schermbeveiliging. Als alle beeldschermen waren "
    L"geselecteerd, worden nieuw aangesloten beeldschermen ook geselecteerd.\r\n\r\nStart "
    L"FlightCorridor.exe. Instellingen worden doorlopend opgeslagen en er draait slechts één exemplaar van "
    L"de toepassing. Het selectievakje of een dubbelklik op de beeldschermrij schakelt de animatie-uitvoer "
    L"in of uit. U kunt de animatie pauzeren en hervatten. PNG en MP4 leggen het eerste actieve "
    L"animatiebeeldscherm vast, niet een gecombineerd beeld van alle schermen. Het opgenomen beeldscherm "
    L"kan niet worden uitgeschakeld; afsluiten tijdens een opname vereist bevestiging. Blokkering van de "
    L"schermbeveiliging geldt voor de hele sessie, alleen zolang op een beeldscherm met die optie een "
    L"zichtbare, niet-gepauzeerde animatie draait. De toepassing kan de ingebouwde schermbeveiliging "
    L"installeren of verwijderen.\r\n\r\nKies Viewport of TV in de opname-instellingen. Viewport behoudt de "
    L"afmetingen en vernieuwingsfrequentie van het beeldscherm tot 60 frames per seconde. TV biedt 1920 × "
    L"1080, 1440 × 1080 of 1280 × 720 met beeldverhouding 16:9 en 50, 25, 59.94 (60000/1001) of 29.97 "
    L"(30000/1001) frames per seconde. TV gebruikt progressieve BT.709-video met beperkt bereik en "
    L"4:2:0-kleursubsampling. De beeldverhouding blijft behouden en opvulbalken zijn zwart. OK bewaart de "
    L"opties voor de volgende opname; Annuleren of Esc verwerpt onbevestigde wijzigingen. "
    L"Opname-instellingen, Help en Info blokkeren andere vensters niet en kunnen worden geminimaliseerd. "
    L"Tab en Shift+Tab verplaatsen de focus, Enter activeert de knop met focus en Esc sluit het actieve "
    L"hulpvenster.\r\n\r\nWindows 7–11 ondersteunt alle functies. Voor Windows Vista SP2 moet u updates "
    L"KB971512 en KB2117917 installeren; MP4-opname werkt niet op Vista. Direct3D 11-ondersteuning is "
    L"vereist; voor MP4 zijn ook Media Foundation en een H.264-encoder nodig. Interface en documentatie "
    L"zijn beschikbaar in 36 talen.",
    L"Zbor între suprafețe deformabile accelerat hardware. Zbor între patru suprafețe deformabile; Zbor "
    L"printr-o pâlnie deformabilă. Alegeți exact o animație pentru fiecare monitor. Textură comută între "
    L"suprafața texturată și modelul de sârmă. Rotirea liberă a camerei schimbă lent direcția privirii în "
    L"toate cele trei dimensiuni. Opriri și inversări de sens adaugă încetiniri, pauze și inversări ale "
    L"rotației la intervale aleatorii; zborul înainte continuă. Viteza este 0–1600%. Fiecare monitor are o "
    L"scenă aleatorie independentă, randată la propria rată de reîmprospătare.\r\n\r\nSelectați unul sau "
    L"mai multe rânduri din lista monitoarelor. Ctrl+A le selectează pe toate; Ctrl și Shift modifică "
    L"selecția. Comenzile și glisoarele animației schimbă numai setările monitoarelor selectate. Selectarea "
    L"unui rând diferă de activarea ieșirii prin caseta sa de selectare. Selecția este reținută separat "
    L"pentru aplicație și economizor. Dacă erau selectate toate monitoarele, sunt incluse și cele conectate "
    L"ulterior.\r\n\r\nRulați FlightCorridor.exe. Setările se salvează continuu și rulează o singură "
    L"instanță. Caseta monitorului sau un dublu clic pe rând activează ori dezactivează ieșirea animației. "
    L"Animația poate fi pusă în pauză și reluată. PNG și MP4 capturează primul monitor de animație activ, "
    L"nu imaginea combinată a tuturor monitoarelor. Monitorul înregistrat nu poate fi dezactivat; "
    L"închiderea aplicației în timpul înregistrării necesită confirmare. Blocarea economizorului se aplică "
    L"întregii sesiuni și numai cât timp pe un monitor cu această opțiune este vizibilă o animație care nu "
    L"este în pauză. Aplicația poate instala sau dezinstala economizorul încorporat.\r\n\r\nÎn setările de "
    L"înregistrare alegeți Viewport sau TV. Viewport păstrează dimensiunile și rata de reîmprospătare a "
    L"monitorului, până la 60 de cadre pe secundă. TV oferă 1920 × 1080, 1440 × 1080 sau 1280 × 720 în "
    L"16:9, la 50, 25, 59.94 (60000/1001) sau 29.97 (30000/1001) cadre pe secundă. Videoul TV este "
    L"progresiv BT.709, cu interval limitat și subeșantionare cromatică 4:2:0. Proporțiile imaginii se "
    L"păstrează, iar benzile de completare sunt negre. OK salvează opțiunile pentru următoarea "
    L"înregistrare; Anulare sau Esc renunță la schimbările neconfirmate. Ferestrele de înregistrare, ajutor "
    L"și informații nu blochează celelalte ferestre și pot fi minimizate. Tab și Shift+Tab mută "
    L"focalizarea, Enter activează butonul focalizat, iar Esc închide fereastra auxiliară "
    L"activă.\r\n\r\nWindows 7–11 acceptă toate funcțiile. Pentru Windows Vista SP2 trebuie instalate "
    L"actualizările KB971512 și KB2117917; înregistrarea MP4 nu funcționează pe Vista. Este necesar "
    L"Direct3D 11, iar pentru MP4 și Media Foundation și un codificator H.264. Interfața și documentația "
    L"sunt disponibile în 36 de limbi.",
    L"Πτήση ανάμεσα σε μεταβαλλόμενες επιφάνειες με επιτάχυνση υλικού. Πτήση ανάμεσα σε τέσσερις "
    L"μεταβαλλόμενες επιφάνειες; Πτήση μέσα από μεταβαλλόμενη χοάνη. Επιλέξτε ακριβώς μία κίνηση ανά οθόνη. "
    L"Η Υφή εναλλάσσει επιφάνεια με υφή και συρμάτινο μοντέλο. Η ελεύθερη περιστροφή κάμερας αλλάζει αργά "
    L"την κατεύθυνση θέασης και στις τρεις διαστάσεις. Οι Στάσεις και αντιστροφές προσθέτουν τυχαίες "
    L"επιβραδύνσεις, παύσεις και αντιστροφές περιστροφής, ενώ η πτήση προς τα εμπρός συνεχίζεται. Η "
    L"ταχύτητα είναι 0–1600%. Κάθε οθόνη διαθέτει ανεξάρτητη τυχαία σκηνή που αποδίδεται στον δικό της "
    L"ρυθμό ανανέωσης.\r\n\r\nΕπιλέξτε μία ή περισσότερες γραμμές στη λίστα οθονών. Το Ctrl+A επιλέγει "
    L"όλες, ενώ τα Ctrl και Shift αλλάζουν την επιλογή. Τα χειριστήρια και τα ρυθμιστικά της κίνησης "
    L"αλλάζουν μόνο τις ρυθμίσεις των επιλεγμένων οθονών. Η επιλογή γραμμής διαφέρει από την ενεργοποίηση "
    L"εξόδου μέσω του πλαισίου ελέγχου της. Η επιλογή αποθηκεύεται χωριστά για την εφαρμογή και την "
    L"προφύλαξη. Αν είχαν επιλεγεί όλες οι οθόνες, περιλαμβάνονται και όσες συνδεθούν "
    L"αργότερα.\r\n\r\nΕκτελέστε το FlightCorridor.exe. Οι ρυθμίσεις αποθηκεύονται συνεχώς και εκτελείται "
    L"μόνο ένα αντίγραφο της εφαρμογής. Το πλαίσιο της οθόνης ή το διπλό κλικ στη γραμμή ενεργοποιεί ή "
    L"απενεργοποιεί την έξοδο κίνησης. Η κίνηση μπορεί να παύσει και να συνεχιστεί. Τα PNG και MP4 "
    L"καταγράφουν την πρώτη ενεργή οθόνη κίνησης, όχι συνδυασμένη εικόνα όλων των οθονών. Η καταγραφόμενη "
    L"οθόνη δεν μπορεί να απενεργοποιηθεί· το κλείσιμο της εφαρμογής κατά την εγγραφή απαιτεί επιβεβαίωση. "
    L"Η αναστολή προφύλαξης ισχύει για όλη τη συνεδρία και μόνο όσο σε οθόνη με ενεργή την επιλογή υπάρχει "
    L"ορατή κίνηση χωρίς παύση. Η εφαρμογή εγκαθιστά ή καταργεί την ενσωματωμένη προφύλαξη.\r\n\r\nΣτις "
    L"ρυθμίσεις εγγραφής επιλέξτε Viewport ή TV. Το Viewport διατηρεί διαστάσεις και ρυθμό ανανέωσης οθόνης "
    L"έως 60 καρέ ανά δευτερόλεπτο. Το TV προσφέρει 1920 × 1080, 1440 × 1080 ή 1280 × 720 σε 16:9, με 50, "
    L"25, 59.94 (60000/1001) ή 29.97 (30000/1001) καρέ ανά δευτερόλεπτο. Το βίντεο TV είναι προοδευτικό "
    L"BT.709 περιορισμένου εύρους με υποδειγματοληψία χρώματος 4:2:0. Διατηρούνται οι αναλογίες εικόνας και "
    L"οι συμπληρωματικές λωρίδες είναι μαύρες. Το OK αποθηκεύει επιλογές για την επόμενη εγγραφή· Άκυρο ή "
    L"Esc απορρίπτει ανεπιβεβαίωτες αλλαγές. Οι ρυθμίσεις εγγραφής, η βοήθεια και οι πληροφορίες δεν "
    L"εμποδίζουν άλλα παράθυρα και ελαχιστοποιούνται. Tab και Shift+Tab μετακινούν την εστίαση, Enter "
    L"ενεργοποιεί το εστιασμένο κουμπί και Esc κλείνει το ενεργό βοηθητικό παράθυρο.\r\n\r\nΤα Windows 7–11 "
    L"υποστηρίζουν όλες τις λειτουργίες. Στα Windows Vista SP2 πρέπει να εγκατασταθούν οι ενημερώσεις "
    L"KB971512 και KB2117917· η εγγραφή MP4 δεν λειτουργεί στα Vista. Απαιτείται υποστήριξη Direct3D 11 "
    L"και, για MP4, Media Foundation και κωδικοποιητής H.264. Η διεπαφή και η τεκμηρίωση διατίθενται σε 36 "
    L"γλώσσες.",
    L"Hardverski ubrzan let između promjenjivih površina. Let između četiri promjenjive površine; Let kroz "
    L"promjenjivi lijevak. Za svaki monitor odaberite tačno jednu animaciju. Tekstura mijenja prikaz između "
    L"teksturirane površine i žičanog modela. Slobodno okretanje kamere polako mijenja smjer pogleda u sve "
    L"tri dimenzije. Zaustavljanja i promjene smjera dodaju nasumično usporavanje, pauze i promjene smjera "
    L"rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki monitor ima nezavisnu nasumičnu scenu "
    L"koja se prikazuje prema njegovoj frekvenciji osvježavanja.\r\n\r\nOdaberite jedan ili više redova u "
    L"listi monitora. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije "
    L"mijenjaju samo postavke odabranih monitora. Odabir reda nije isto što i uključivanje izlaza njegovom "
    L"kućicom. Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili odabrani svi "
    L"monitori, uključuju se i novopriključeni monitori.\r\n\r\nPokrenite FlightCorridor.exe. Postavke se "
    L"stalno čuvaju i radi samo jedna instanca aplikacije. Kućica monitora ili dvostruki klik na red "
    L"uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe "
    L"prvi aktivni monitor animacije, ne zajedničku sliku svih monitora. Snimani monitor ne možete "
    L"isključiti; zatvaranje aplikacije tokom snimanja zahtijeva potvrdu. Blokada čuvara ekrana vrijedi za "
    L"cijelu sesiju i samo dok je na monitoru s uključenom tom opcijom vidljiva animacija koja nije "
    L"pauzirana. Aplikacija može instalirati i deinstalirati ugrađeni čuvar ekrana.\r\n\r\nU postavkama "
    L"snimanja odaberite Viewport ili TV. Viewport zadržava dimenzije i frekvenciju monitora do 60 kadrova "
    L"u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u omjeru 16:9, s 50, 25, 59.94 "
    L"(60000/1001) ili 29.97 (30000/1001) kadrova u sekundi. TV video je progresivni BT.709 ograničenog "
    L"raspona s poduzorkovanjem boje 4:2:0. Omjer slike ostaje sačuvan, a dopunske trake su crne. OK čuva "
    L"opcije za sljedeći snimak; Otkaži ili Esc odbacuje nepotvrđene izmjene. Prozori snimanja, pomoći i "
    L"informacija ne blokiraju ostale prozore i mogu se minimizirati. Tab i Shift+Tab pomjeraju fokus, "
    L"Enter aktivira fokusirano dugme, a Esc zatvara aktivni pomoćni prozor.\r\n\r\nWindows 7–11 podržava "
    L"sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje "
    L"na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media Foundation te H.264 koder. Interfejs i "
    L"dokumentacija dostupni su na 36 jezika.",
    L"Hardverski ubrzan let između promjenjivih ploha. Let između četiriju promjenjivih ploha; Let kroz "
    L"promjenjivi lijevak. Za svaki zaslon odaberite točno jednu animaciju. Tekstura mijenja prikaz između "
    L"teksturirane plohe i žičanog modela. Slobodno okretanje kamere polako mijenja smjer pogleda u sve tri "
    L"dimenzije. Zaustavljanja i promjene smjera dodaju nasumično usporavanje, stanke i promjene smjera "
    L"rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki zaslon ima neovisnu nasumičnu scenu "
    L"koja se prikazuje prema njegovoj frekvenciji osvježavanja.\r\n\r\nOdaberite jedan ili više redaka na "
    L"popisu zaslona. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije "
    L"mijenjaju samo postavke odabranih zaslona. Odabir retka nije isto što i uključivanje izlaza njegovim "
    L"potvrdnim okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar zaslona. Ako su prethodno bili "
    L"odabrani svi zasloni, uključuju se i novopriključeni zasloni.\r\n\r\nPokrenite FlightCorridor.exe. "
    L"Postavke se neprekidno spremaju i radi samo jedna instanca aplikacije. Potvrdni okvir zaslona ili "
    L"dvostruki klik na redak uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i "
    L"nastaviti. PNG i MP4 bilježe prvi aktivni zaslon animacije, ne zajedničku sliku svih zaslona. Snimani "
    L"zaslon ne možete isključiti; zatvaranje aplikacije tijekom snimanja zahtijeva potvrdu. Blokada čuvara "
    L"zaslona vrijedi za cijelu sesiju i samo dok je na zaslonu s uključenom tom mogućnošću vidljiva "
    L"animacija koja nije pauzirana. Aplikacija može instalirati i deinstalirati ugrađeni čuvar "
    L"zaslona.\r\n\r\nU postavkama snimanja odaberite Viewport ili TV. Viewport zadržava dimenzije i "
    L"frekvenciju zaslona do 60 sličica u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u omjeru "
    L"16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) sličica u sekundi. TV video je progresivni "
    L"BT.709 ograničenog raspona s poduzorkovanjem boje 4:2:0. Omjer slike ostaje sačuvan, a dopunske trake "
    L"su crne. OK sprema mogućnosti za sljedeću snimku; Odustani ili Esc odbacuje nepotvrđene izmjene. "
    L"Prozori snimanja, pomoći i informacija ne blokiraju ostale prozore i mogu se minimizirati. Tab i "
    L"Shift+Tab pomiču fokus, Enter aktivira fokusirani gumb, a Esc zatvara aktivni pomoćni "
    L"prozor.\r\n\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja "
    L"KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media "
    L"Foundation te H.264 koder. Sučelje i dokumentacija dostupni su na 36 jezika.",
    L"Strojno pospešen let med spreminjajočimi se ploskvami. Let med štirimi spreminjajočimi se ploskvami; "
    L"Let skozi spreminjajoči se lijak. Za vsak zaslon izberite natanko eno animacijo. Tekstura preklaplja "
    L"med teksturirano ploskvijo in žičnim modelom. Prosto vrtenje kamere počasi spreminja smer pogleda v "
    L"vseh treh razsežnostih. Ustavljanja in spremembe smeri dodajo naključne upočasnitve, premore in "
    L"obrate smeri vrtenja; let naprej se nadaljuje. Hitrost je 0–1600%. Vsak zaslon ima neodvisen "
    L"naključen prizor, ki se izrisuje z njegovo hitrostjo osveževanja.\r\n\r\nNa seznamu zaslonov izberite "
    L"eno ali več vrstic. Ctrl+A izbere vse, Ctrl in Shift pa spreminjata izbor. Kontrolniki in drsniki "
    L"animacije spreminjajo samo nastavitve izbranih zaslonov. Izbira vrstice ni isto kot vklop izhoda z "
    L"njenim potrditvenim poljem. Izbor se ločeno shrani za program in ohranjevalnik. Če so bili izbrani "
    L"vsi zasloni, so vključeni tudi na novo priključeni zasloni.\r\n\r\nZaženite FlightCorridor.exe. "
    L"Nastavitve se shranjujejo sproti in deluje le en primerek programa. Polje zaslona ali dvojni klik na "
    L"vrstico vklopi ali izklopi izhod animacije. Animacijo lahko začasno ustavite in nadaljujete. PNG in "
    L"MP4 zajameta prvi aktivni zaslon animacije, ne skupne slike vseh zaslonov. Snemanega zaslona ni "
    L"mogoče izklopiti; zapiranje programa med snemanjem zahteva potrditev. Preprečevanje ohranjevalnika "
    L"velja za celotno sejo in le, dokler je na zaslonu s to možnostjo vidna neustavljena animacija. "
    L"Program lahko namesti ali odstrani vgrajeni ohranjevalnik.\r\n\r\nV nastavitvah snemanja izberite "
    L"Viewport ali TV. Viewport ohrani velikost in hitrost osveževanja zaslona do 60 sličic na sekundo. TV "
    L"ponuja 1920 × 1080, 1440 × 1080 ali 1280 × 720 v razmerju 16:9 ter 50, 25, 59.94 (60000/1001) ali "
    L"29.97 (30000/1001) sličic na sekundo. TV uporablja progresivni BT.709 z omejenim obsegom in barvnim "
    L"podvzorčenjem 4:2:0. Razmerje slike se ohrani, dopolnilni pasovi so črni. OK shrani izbiro za "
    L"naslednje snemanje; Prekliči ali Esc zavrže nepotrjene spremembe. Okna snemanja, pomoči in podatkov o "
    L"programu ne blokirajo drugih oken in jih je mogoče minimirati. Tab in Shift+Tab premikata fokus, "
    L"Enter aktivira izbrani gumb, Esc pa zapre aktivno pomožno okno.\r\n\r\nWindows 7–11 podpira vse "
    L"funkcije. Za Windows Vista SP2 morate namestiti posodobitvi KB971512 in KB2117917; snemanje MP4 v "
    L"Visti ne deluje. Potrebna je podpora Direct3D 11, za MP4 pa še Media Foundation in kodirnik H.264. "
    L"Vmesnik in dokumentacija sta na voljo v 36 jezikih.",
    L"Hardverski ubrzan let između promjenljivih površina. Let između četiri promjenljive površine; Let "
    L"kroz promjenljivi lijevak. Za svaki monitor izaberite tačno jednu animaciju. Tekstura mijenja prikaz "
    L"između teksturisane površine i žičanog modela. Slobodno okretanje kamere polako mijenja smjer pogleda "
    L"u sve tri dimenzije. Zaustavljanja i promjene smjera dodaju nasumično usporavanje, pauze i promjene "
    L"smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki monitor ima nezavisnu nasumičnu "
    L"scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja.\r\n\r\nIzaberite jedan ili više "
    L"redova u listi monitora. Ctrl+A bira sve; Ctrl i Shift mijenjaju izbor. Kontrole i klizači animacije "
    L"mijenjaju samo podešavanja izabranih monitora. Izbor reda nije isto što i uključivanje izlaza "
    L"njegovom kućicom. Izbor se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
    L"izabrani svi monitori, uključuju se i novopriključeni monitori.\r\n\r\nPokrenite FlightCorridor.exe. "
    L"Podešavanja se stalno čuvaju i radi samo jedna instanca aplikacije. Kućica monitora ili dvostruki "
    L"klik na red uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i "
    L"MP4 bilježe prvi aktivni monitor animacije, ne zajedničku sliku svih monitora. Snimani monitor ne "
    L"možete isključiti; zatvaranje aplikacije tokom snimanja zahtijeva potvrdu. Blokada čuvara ekrana važi "
    L"za cijelu sesiju i samo dok je na monitoru s uključenom tom opcijom vidljiva animacija koja nije "
    L"pauzirana. Aplikacija može instalirati i deinstalirati ugrađeni čuvar ekrana.\r\n\r\nU podešavanjima "
    L"snimanja izaberite Viewport ili TV. Viewport zadržava dimenzije i frekvenciju monitora do 60 kadrova "
    L"u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u odnosu 16:9, s 50, 25, 59.94 "
    L"(60000/1001) ili 29.97 (30000/1001) kadrova u sekundi. TV video je progresivni BT.709 ograničenog "
    L"opsega s poduzorkovanjem boje 4:2:0. Odnos slike ostaje sačuvan, a dopunske trake su crne. OK čuva "
    L"opcije za sljedeći snimak; Otkaži ili Esc odbacuje nepotvrđene izmjene. Prozori snimanja, pomoći i "
    L"informacija ne blokiraju ostale prozore i mogu se minimizovati. Tab i Shift+Tab pomjeraju fokus, "
    L"Enter aktivira fokusirano dugme, a Esc zatvara aktivni pomoćni prozor.\r\n\r\nWindows 7–11 podržava "
    L"sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje "
    L"na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media Foundation i H.264 koder. Interfejs i "
    L"dokumentacija dostupni su na 36 jezika.",
    L"Апаратна паскораны палёт паміж зменлівымі паверхнямі. Палёт паміж чатырма зменлівымі паверхнямі; "
    L"Палёт праз зменлівую варонку. Для кожнага манітора выберыце роўна адну анімацыю. Тэкстура пераключае "
    L"тэкстураваную паверхню і каркасную мадэль. Свабоднае кручэнне камеры павольна змяняе напрамак погляду "
    L"ва ўсіх трох вымярэннях. Спыненні і змены напрамку дадаюць выпадковыя запаволенні, паўзы і змены "
    L"напрамку кручэння; палёт наперад працягваецца. Хуткасць — 0–1600%. Кожны манітор мае незалежную "
    L"выпадковую сцэну з вывадам паводле ўласнай частаты абнаўлення.\r\n\r\nВыберыце адзін або некалькі "
    L"радкоў у спісе манітораў. Ctrl+A выбірае ўсе; Ctrl і Shift змяняюць выбар. Элементы кіравання і "
    L"паўзункі анімацыі змяняюць толькі налады выбраных манітораў. Выбар радка і ўключэнне вываду яго "
    L"сцяжком — розныя дзеянні. Выбар асобна захоўваецца для праграмы і застаўкі. Калі раней былі выбраны "
    L"ўсе маніторы, да выбару далучаюцца і новыя маніторы.\r\n\r\nЗапусціце FlightCorridor.exe. Налады "
    L"захоўваюцца пастаянна, працуе толькі адзін асобнік праграмы. Сцяжок манітора або падвойнае націсканне "
    L"на радок уключае ці выключае вывад анімацыі. Анімацыю можна прыпыніць і працягнуць. PNG і MP4 "
    L"захопліваюць першы актыўны манітор анімацыі, а не агульны відарыс усіх манітораў. Манітор, які "
    L"запісваецца, нельга выключыць; закрыццё праграмы падчас запісу патрабуе пацвярджэння. Блакаванне "
    L"застаўкі дзейнічае на ўсю сесію і толькі пакуль на маніторы з гэтай опцыяй бачная непрыпыненая "
    L"анімацыя. Праграма можа ўсталяваць або выдаліць убудаваную застаўку.\r\n\r\nУ наладах запісу выберыце "
    L"Viewport або TV. Viewport захоўвае памеры і частату манітора да 60 кадраў за секунду. TV прапануе "
    L"1920 × 1080, 1440 × 1080 або 1280 × 720 з суадносінамі 16:9 і частатой 50, 25, 59.94 (60000/1001) або "
    L"29.97 (30000/1001) кадраў за секунду. Відэа TV прагрэсіўнае, BT.709, з абмежаваным дыяпазонам і "
    L"субдыскрэтызацыяй колеру 4:2:0. Прапорцыі захоўваюцца, палосы запаўнення чорныя. OK захоўвае выбар "
    L"для наступнага запісу; Скасаваць або Esc адхіляе непацверджаныя змены. Вокны запісу, даведкі і "
    L"звестак пра праграму не блакуюць іншыя вокны і могуць згортвацца. Tab і Shift+Tab перамяшчаюць фокус, "
    L"Enter націскае актыўную кнопку, Esc закрывае актыўнае дапаможнае акно.\r\n\r\nWindows 7–11 "
    L"падтрымлівае ўсе функцыі. Для Windows Vista SP2 неабходна ўсталяваць абнаўленні KB971512 і KB2117917; "
    L"запіс MP4 у Vistа не працуе. Патрэбна падтрымка Direct3D 11, а для MP4 таксама Media Foundation і "
    L"кадавальнік H.264. Інтэрфейс і дакументацыя даступны на 36 мовах.",
    L"Хардуерно ускорен полет между променящи се повърхнини. Полет между четири променящи се повърхнини; "
    L"Полет през променяща се фуния. Изберете точно една анимация за всеки монитор. Текстура превключва "
    L"между текстурирана повърхнина и телен модел. Свободното въртене на камерата бавно променя посоката на "
    L"погледа в трите измерения. Спирания и обръщания на посоката добавя случайни забавяния, паузи и "
    L"обръщания на въртенето; полетът напред продължава. Скоростта е 0–1600%. Всеки монитор има независима "
    L"случайна сцена, изобразявана с неговата честота на опресняване.\r\n\r\nИзберете един или повече "
    L"редове в списъка с монитори. Ctrl+A избира всички; Ctrl и Shift променят избора. Контролите и "
    L"плъзгачите на анимацията променят само настройките на избраните монитори. Избирането на ред и "
    L"включването на изхода чрез отметката му са различни действия. Изборът се запомня отделно за "
    L"приложението и скрийнсейвъра. Ако са били избрани всички монитори, включват се и "
    L"новосвързаните.\r\n\r\nСтартирайте FlightCorridor.exe. Настройките се запазват непрекъснато и работи "
    L"само един екземпляр на приложението. Отметката на монитора или двойно щракване върху реда включва или "
    L"изключва анимационния изход. Анимацията може да се поставя на пауза и да продължава. PNG и MP4 "
    L"заснемат първия активен монитор за анимация, не общ образ от всички монитори. Записваният монитор не "
    L"може да се изключи; затварянето на приложението при запис изисква потвърждение. Блокирането на "
    L"скрийнсейвъра важи за цялата сесия и само докато на монитор с тази опция има видима анимация без "
    L"пауза. Приложението може да инсталира и деинсталира вградения скрийнсейвър.\r\n\r\nВ настройките за "
    L"запис изберете Viewport или TV. Viewport запазва размерите и честотата на монитора до 60 кадъра в "
    L"секунда. TV предлага 1920 × 1080, 1440 × 1080 или 1280 × 720 със съотношение 16:9 и 50, 25, 59.94 "
    L"(60000/1001) или 29.97 (30000/1001) кадъра в секунда. TV използва прогресивно видео BT.709 с "
    L"ограничен диапазон и цветова субдискретизация 4:2:0. Пропорциите се запазват, допълващите ленти са "
    L"черни. OK запазва избора за следващия запис; Отказ или Esc отхвърля непотвърдените промени. "
    L"Прозорците за запис, помощ и информация не блокират другите прозорци и могат да се минимизират. Tab и "
    L"Shift+Tab преместват фокуса, Enter активира фокусирания бутон, Esc затваря активния помощен "
    L"прозорец.\r\n\r\nWindows 7–11 поддържа всички функции. За Windows Vista SP2 трябва да се инсталират "
    L"актуализациите KB971512 и KB2117917; записът на MP4 не работи във Vista. Изисква се поддръжка на "
    L"Direct3D 11, а за MP4 също Media Foundation и H.264 кодер. Интерфейсът и документацията са налични на "
    L"36 езика.",
    L"Хардверски забрзан лет меѓу променливи површини. Лет меѓу четири променливи површини; Лет низ "
    L"променлива инка. За секој монитор изберете точно една анимација. Текстура менува текстурирана "
    L"површина и жичен модел. Слободното вртење на камерата полека го менува погледот во сите три димензии. "
    L"Запирања и промени на насоката додава случајни забавувања, паузи и промени на насоката на вртење; "
    L"летот напред продолжува. Брзината е 0–1600%. Секој монитор има независна случајна сцена што се "
    L"прикажува со неговата стапка на освежување.\r\n\r\nИзберете еден или повеќе редови во списокот на "
    L"монитори. Ctrl+A ги избира сите; Ctrl и Shift го менуваат изборот. Контролите и лизгачите на "
    L"анимацијата ги менуваат само поставките на избраните монитори. Избирањето ред и вклучувањето на "
    L"излезот преку неговото поле се различни дејства. Изборот се памети одделно за апликацијата и чуварот. "
    L"Ако биле избрани сите монитори, се вклучуваат и новоповрзаните монитори.\r\n\r\nСтартувајте "
    L"FlightCorridor.exe. Поставките се зачувуваат постојано и работи само еден примерок на апликацијата. "
    L"Полето на мониторот или двоен клик на редот го вклучува или исклучува анимацискиот излез. Анимацијата "
    L"може да се паузира и продолжи. PNG и MP4 го снимаат првиот активен монитор за анимација, не заедничка "
    L"слика од сите монитори. Мониторот што се снима не може да се исклучи; затворањето на апликацијата при "
    L"снимање бара потврда. Блокирањето на чуварот важи за целата сесија и само додека на монитор со таа "
    L"опција е видлива непаузирана анимација. Апликацијата може да го инсталира и деинсталира вградениот "
    L"чувар.\r\n\r\nВо поставките за снимање изберете Viewport или TV. Viewport ги зачувува димензиите и "
    L"стапката на мониторот до 60 кадри во секунда. TV нуди 1920 × 1080, 1440 × 1080 или 1280 × 720 со "
    L"однос 16:9 и 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) кадри во секунда. TV видеото е "
    L"прогресивно BT.709 со ограничен опсег и подсемплирање на боја 4:2:0. Пропорциите се задржуваат, "
    L"дополнителните ленти се црни. OK ги зачувува опциите за следното снимање; Откажи или Esc ги отфрла "
    L"непотврдените измени. Прозорците за снимање, помош и информации не ги блокираат другите прозорци и "
    L"може да се минимизираат. Tab и Shift+Tab го поместуваат фокусот, Enter го активира фокусираното "
    L"копче, Esc го затвора активниот помошен прозорец.\r\n\r\nWindows 7–11 ги поддржува сите функции. За "
    L"Windows Vista SP2 мора да се инсталираат ажурирањата KB971512 и KB2117917; MP4 снимањето на Vista не "
    L"работи. Потребна е поддршка за Direct3D 11, а за MP4 и Media Foundation и H.264 кодер. Интерфејсот и "
    L"документацијата се достапни на 36 јазици.",
    L"Хардверски убрзан лет између променљивих површи. Лет између четири променљиве површи; Лет кроз "
    L"променљиви левак. За сваки монитор изаберите тачно једну анимацију. Текстура мења приказ између "
    L"текстурисане површи и жичаног модела. Слободно окретање камере полако мења смер погледа у све три "
    L"димензије. Заустављања и промене смера додају насумично успоравање, паузе и промене смера ротације; "
    L"лет напред се наставља. Брзина је 0–1600%. Сваки монитор има независну насумичну сцену која се "
    L"приказује према његовој учестаности освежавања.\r\n\r\nИзаберите један или више редова у листи "
    L"монитора. Ctrl+A бира све; Ctrl и Shift мењају избор. Контроле и клизачи анимације мењају само "
    L"подешавања изабраних монитора. Избор реда није исто што и укључивање излаза његовим пољем за потврду. "
    L"Избор се памти одвојено за апликацију и чувар екрана. Ако су претходно били изабрани сви монитори, "
    L"укључују се и новоприкључени монитори.\r\n\r\nПокрените FlightCorridor.exe. Подешавања се стално "
    L"чувају и ради само једна инстанца апликације. Поље монитора или двоструки клик на ред укључује или "
    L"искључује анимацијски излаз. Анимацију можете паузирати и наставити. PNG и MP4 бележе први активни "
    L"монитор анимације, не заједничку слику свих монитора. Снимани монитор не можете искључити; затварање "
    L"апликације током снимања захтева потврду. Блокада чувара екрана важи за целу сесију и само док је на "
    L"монитору с укљученом том опцијом видљива анимација која није паузирана. Апликација може инсталирати и "
    L"деинсталирати уграђени чувар екрана.\r\n\r\nУ подешавањима снимања изаберите Viewport или TV. "
    L"Viewport задржава димензије и учестаност монитора до 60 кадрова у секунди. TV нуди 1920 × 1080, 1440 "
    L"× 1080 или 1280 × 720 у односу 16:9, са 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) кадрова у "
    L"секунди. TV видео је прогресивни BT.709 ограниченог опсега с подузорковањем боје 4:2:0. Однос слике "
    L"остаје сачуван, а допунске траке су црне. OK чува опције за следећи снимак; Откажи или Esc одбацује "
    L"непотврђене измене. Прозори снимања, помоћи и информација не блокирају остале прозоре и могу се "
    L"минимизовати. Tab и Shift+Tab померају фокус, Enter активира фокусирано дугме, а Esc затвара активни "
    L"помоћни прозор.\r\n\r\nWindows 7–11 подржава све функције. За Windows Vista SP2 морате инсталирати "
    L"ажурирања KB971512 и KB2117917; MP4 снимање на Висти не ради. Потребан је Direct3D 11, а за MP4 и "
    L"Media Foundation и H.264 кодер. Интерфејс и документација доступни су на 36 језика.",
    L"Апаратно прискорений політ між мінливими поверхнями. Політ між чотирма мінливими поверхнями; Політ "
    L"крізь мінливу лійку. Для кожного монітора виберіть рівно одну анімацію. Текстура перемикає "
    L"текстуровану поверхню та каркасну модель. Вільне обертання камери повільно змінює напрямок погляду в "
    L"усіх трьох вимірах. Зупинки та зміни напрямку додають випадкові уповільнення, паузи та зміни напрямку "
    L"обертання; політ уперед триває. Швидкість — 0–1600%. Кожен монітор має незалежну випадкову сцену з "
    L"виведенням відповідно до власної частоти оновлення.\r\n\r\nВиберіть один або кілька рядків у списку "
    L"моніторів. Ctrl+A вибирає всі; Ctrl і Shift змінюють вибір. Елементи керування й повзунки анімації "
    L"змінюють лише налаштування вибраних моніторів. Вибір рядка та ввімкнення виведення його прапорцем — "
    L"різні дії. Вибір зберігається окремо для програми й заставки. Якщо раніше були вибрані всі монітори, "
    L"до вибору долучаються й новопідключені.\r\n\r\nЗапустіть FlightCorridor.exe. Налаштування "
    L"зберігаються постійно, працює лише один екземпляр програми. Прапорець монітора або подвійне клацання "
    L"рядка вмикає чи вимикає виведення анімації. Анімацію можна призупинити та продовжити. PNG і MP4 "
    L"захоплюють перший активний монітор анімації, а не спільне зображення всіх моніторів. Монітор, який "
    L"записується, вимкнути не можна; закриття програми під час запису потребує підтвердження. Блокування "
    L"заставки діє для всього сеансу й лише доки на моніторі з цією опцією видима непризупинена анімація. "
    L"Програма може встановити або видалити вбудовану заставку.\r\n\r\nУ налаштуваннях запису виберіть "
    L"Viewport або TV. Viewport зберігає розміри та частоту монітора до 60 кадрів за секунду. TV пропонує "
    L"1920 × 1080, 1440 × 1080 або 1280 × 720 зі співвідношенням 16:9 і частотою 50, 25, 59.94 (60000/1001) "
    L"або 29.97 (30000/1001) кадрів за секунду. Відео TV прогресивне, BT.709, з обмеженим діапазоном і "
    L"субдискретизацією кольору 4:2:0. Пропорції зберігаються, смуги заповнення чорні. OK зберігає вибір "
    L"для наступного запису; Скасувати або Esc відхиляє непідтверджені зміни. Вікна запису, довідки та "
    L"відомостей не блокують інші вікна й можуть згортатися. Tab і Shift+Tab переміщують фокус, Enter "
    L"активує кнопку з фокусом, Esc закриває активне допоміжне вікно.\r\n\r\nWindows 7–11 підтримує всі "
    L"функції. Для Windows Vista SP2 потрібно встановити оновлення KB971512 і KB2117917; запис MP4 у Vista "
    L"не працює. Потрібна підтримка Direct3D 11, а для MP4 також Media Foundation й кодувальник H.264. "
    L"Інтерфейс і документація доступні 36 мовами.",
    L"Аппаратно ускоренный полёт между меняющимися поверхностями. Полёт между четырьмя меняющимися "
    L"поверхностями; Полёт сквозь меняющуюся воронку. Для каждого монитора выберите ровно одну анимацию. "
    L"Текстура переключает текстурированную поверхность и каркасную модель. Свободное вращение камеры "
    L"медленно меняет направление взгляда во всех трёх измерениях. Остановки и смены направления добавляют "
    L"случайные замедления, паузы и изменения направления вращения; полёт вперёд продолжается. Скорость — "
    L"0–1600%. Каждый монитор имеет независимую случайную сцену с выводом согласно собственной частоте "
    L"обновления.\r\n\r\nВыберите одну или несколько строк в списке мониторов. Ctrl+A выбирает все; Ctrl и "
    L"Shift изменяют выбор. Элементы управления и ползунки анимации изменяют только настройки выбранных "
    L"мониторов. Выбор строки и включение вывода её флажком — разные действия. Выбор сохраняется отдельно "
    L"для приложения и заставки. Если раньше были выбраны все мониторы, в выбор включаются и вновь "
    L"подключённые.\r\n\r\nЗапустите FlightCorridor.exe. Настройки сохраняются постоянно, работает только "
    L"один экземпляр приложения. Флажок монитора или двойной щелчок по строке включает либо выключает вывод "
    L"анимации. Анимацию можно приостановить и продолжить. PNG и MP4 захватывают первый активный монитор "
    L"анимации, а не общее изображение всех мониторов. Записываемый монитор нельзя отключить; закрытие "
    L"приложения во время записи требует подтверждения. Блокировка заставки действует на весь сеанс и "
    L"только пока на мониторе с этой опцией видима неприостановленная анимация. Приложение может установить "
    L"или удалить встроенную заставку.\r\n\r\nВ настройках записи выберите Viewport или TV. Viewport "
    L"сохраняет размеры и частоту монитора до 60 кадров в секунду. TV предлагает 1920 × 1080, 1440 × 1080 "
    L"или 1280 × 720 с соотношением 16:9 и частотой 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) "
    L"кадров в секунду. Видео TV прогрессивное, BT.709, с ограниченным диапазоном и субдискретизацией цвета "
    L"4:2:0. Пропорции сохраняются, полосы заполнения чёрные. OK сохраняет выбор для следующей записи; "
    L"Отмена или Esc отклоняет неподтверждённые изменения. Окна записи, справки и сведений не блокируют "
    L"другие окна и могут сворачиваться. Tab и Shift+Tab перемещают фокус, Enter активирует кнопку с "
    L"фокусом, Esc закрывает активное вспомогательное окно.\r\n\r\nWindows 7–11 поддерживает все функции. "
    L"Для Windows Vista SP2 необходимо установить обновления KB971512 и KB2117917; запись MP4 в Vista не "
    L"работает. Нужна поддержка Direct3D 11, а для MP4 также Media Foundation и кодировщик H.264. Интерфейс "
    L"и документация доступны на 36 языках."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> SCREEN_SAVER_HELP_TEXTS = {
    L"FlightCorridor: Průlet čtyřmi proměnlivými plochami; Průlet proměnlivým trychtýřem. Každému monitoru "
    L"přiřaďte právě jednu animaci. Textura přepíná mezi texturovanými plochami a drátěným modelem. "
    L"Převalování kamery pomalu mění směr pohledu ve všech třech rozměrech. Zastavování a změny směru "
    L"přidává náhodné zpomalování, pauzy a změny směru otáčení; dopředný pohyb pokračuje. Rychlost animace "
    L"je 0–1600 %. Každý monitor má nezávislou náhodnou scénu a vykreslování podle své obnovovací "
    L"frekvence.\r\n\r\nOznačení řádků určuje, které monitory právě nastavujete; není totožné se zatržítky "
    L"zapínajícími animační výstupy. Ctrl+A označí všechny monitory, Ctrl a Shift umožňují upravit "
    L"označení. Všechny animační volby a jezdce platí pro označené monitory. Označení se pamatuje zvlášť "
    L"pro EXE a SCR. Pokud byly označené všechny monitory, označí se i nově připojené.\r\n\r\nZapnout "
    L"náhled spustí celoobrazovkový náhled na všech monitorech; změny lze zkoušet za otevřeného nastavení. "
    L"OK nastavení uloží, Storno je zahodí. Celoobrazovkový spořič ukončíte klávesou Esc nebo pohybem myši. "
    L"Mezi ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a "
    L"příslušného písmene. Esc v nastavení odpovídá tlačítku Storno; v nápovědě nebo okně O aplikaci zavře "
    L"pouze toto okno.\r\n\r\nPodporovány jsou systémy Windows 7 až Windows 11. Pro spuštění aplikace ve "
    L"Windows Vista SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917.",
    L"FlightCorridor: Flight between four morphing surfaces; Flight through a morphing funnel. Assign "
    L"exactly one animation to each display. Texture switches between textured surfaces and wireframe. "
    L"Camera tumbling slowly changes the viewing direction in all three dimensions. Stops and reversals "
    L"adds randomized braking, pauses, and reversals of the rotation; forward flight continues. Animation "
    L"speed ranges from 0–1600%. Every display has an independent randomized scene rendered at its own "
    L"refresh rate.\r\n\r\nRow selection determines which displays you are editing; it is separate from the "
    L"checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the "
    L"selection. All animation options and sliders apply to the selected displays. The selection is "
    L"remembered separately for EXE and SCR. If all displays were selected, newly connected displays join "
    L"the selection.\r\n\r\nEnable preview starts a full-screen preview on every display while the settings "
    L"dialog remains open for live adjustments. OK saves the settings and Cancel discards them. Exit the "
    L"full-screen saver with Esc or mouse movement. Use Tab and Shift+Tab to move between controls; use Alt "
    L"and the underlined letter to activate a command. Esc in the settings dialog is equivalent to Cancel; "
    L"in Help or About, it closes only that window.\r\n\r\nWindows 7 through Windows 11 are supported. To "
    L"run the application on Windows Vista SP2, you must install updates KB971512 and KB2117917.",
    L"FlightCorridor: Flight between four morphing surfaces; Flight through a morphing funnel. Assign "
    L"exactly one animation to each display. Texture switches between textured surfaces and wireframe. "
    L"Camera tumbling slowly changes the viewing direction in all three dimensions. Stops and reversals "
    L"adds randomised braking, pauses and reversals of the rotation; forward flight continues. Animation "
    L"speed ranges from 0–1600%. Every display has an independent randomised scene rendered at its own "
    L"refresh rate.\r\n\r\nRow selection determines which displays you are editing; it is separate from the "
    L"checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the "
    L"selection. All animation options and sliders apply to the selected displays. The selection is "
    L"remembered separately for EXE and SCR. If all displays were selected, newly connected displays join "
    L"the selection.\r\n\r\nEnable preview starts a full-screen preview on every display and allows live "
    L"adjustments while the settings dialog remains open. OK saves the settings and Cancel discards them. "
    L"Exit the full-screen screen saver with Esc or mouse movement. Use Tab and Shift+Tab to move between "
    L"controls; use Alt and the underlined letter to activate a command. Esc in the settings dialog is "
    L"equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\nWindows 7 through Windows "
    L"11 are supported. To run the application on Windows Vista SP2, you must install updates KB971512 and "
    L"KB2117917.",
    L"FlightCorridor: Flight between four morphing surfaces; Flight through a morphing funnel. Assign "
    L"exactly one animation to each display. Texture switches between textured surfaces and wireframe. "
    L"Camera tumbling slowly changes the viewing direction in all three dimensions. Stops and reversals "
    L"adds randomised braking, pauses and reversals of the rotation; forward flight continues. Animation "
    L"speed ranges from 0–1600%. Every display has an independent randomised scene rendered at its own "
    L"refresh rate.\r\n\r\nRow selection determines which displays you are editing; it is separate from the "
    L"checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the "
    L"selection. All animation options and sliders apply to the selected displays. The selection is "
    L"remembered separately for EXE and SCR. If all displays were selected, newly connected displays join "
    L"the selection.\r\n\r\nEnable preview starts a full-screen preview on every display and allows live "
    L"adjustments while the settings dialog remains open. OK saves the settings and Cancel discards them. "
    L"Exit the full-screen screen saver with Esc or mouse movement. Use Tab and Shift+Tab to move between "
    L"controls; use Alt and the underlined letter to activate a command. Esc in the settings dialog is "
    L"equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\nWindows 7 through Windows "
    L"11 are supported. To run the application on Windows Vista SP2, you must install updates KB971512 and "
    L"KB2117917.",
    L"FlightCorridor: Flug zwischen vier veränderlichen Flächen; Flug durch einen veränderlichen Trichter. "
    L"Weisen Sie jedem Monitor genau eine Animation zu. Textur wechselt zwischen texturierten Flächen und "
    L"Drahtgittermodell. Die taumelnde Kamera verändert die Blickrichtung langsam in allen drei "
    L"Dimensionen. Stopps und Richtungswechsel ergänzt zufälliges Abbremsen, Pausen und Wechsel der "
    L"Drehrichtung; der Vorwärtsflug läuft weiter. Die Animationsgeschwindigkeit beträgt 0–1600 %. Jeder "
    L"Monitor besitzt eine unabhängige zufällige Szene und wird mit seiner eigenen Bildwiederholrate "
    L"angesteuert.\r\n\r\nDie Zeilenauswahl bestimmt, welche Monitore Sie bearbeiten; sie ist von den "
    L"Kontrollkästchen zum Einschalten der Animationsausgabe getrennt. Strg+A wählt alle Monitore, Strg und "
    L"Umschalt ändern die Auswahl. Alle Animationsoptionen und Regler gelten für die ausgewählten Monitore. "
    L"Die Auswahl wird für EXE und SCR getrennt gespeichert. Waren alle Monitore ausgewählt, werden auch "
    L"neu angeschlossene ausgewählt.\r\n\r\nVorschau einschalten startet eine Vollbildvorschau auf allen "
    L"Monitoren. Der Einstellungsdialog bleibt für Änderungen geöffnet. OK speichert, Abbrechen verwirft. "
    L"Esc oder eine Mausbewegung beendet den Vollbildschoner. Mit Tab und Umschalt+Tab wechseln Sie "
    L"zwischen den Steuerelementen; mit Alt und dem unterstrichenen Buchstaben rufen Sie einen Befehl auf. "
    L"Esc im Einstellungsdialog entspricht Abbrechen; in der Hilfe oder im Infofenster schließt es nur "
    L"dieses Fenster.\r\n\r\nUnterstützt werden Windows 7 bis Windows 11. Zum Ausführen der Anwendung unter "
    L"Windows Vista SP2 müssen die Updates KB971512 und KB2117917 installiert werden.",
    L"FlightCorridor: Vol entre quatre surfaces déformables; Vol dans un entonnoir déformable. Attribuez "
    L"une seule animation à chaque écran. Texture alterne entre surfaces texturées et modèle filaire. La "
    L"rotation libre de la caméra change lentement la direction du regard dans les trois dimensions. Arrêts "
    L"et changements de sens ajoute des ralentissements, pauses et inversions aléatoires de la rotation ; "
    L"le vol vers l’avant continue. La vitesse va de 0 à 1600 %. Chaque écran possède une scène aléatoire "
    L"indépendante, rendue à sa propre fréquence de rafraîchissement.\r\n\r\nLa sélection des lignes "
    L"détermine les écrans à configurer ; elle est distincte des cases qui activent les sorties "
    L"d’animation. Ctrl+A sélectionne tous les écrans ; Ctrl et Maj modifient la sélection. Toutes les "
    L"options et tous les curseurs d’animation concernent les écrans sélectionnés. La sélection est "
    L"mémorisée séparément pour EXE et SCR. Si tous les écrans étaient sélectionnés, les nouveaux le sont "
    L"également.\r\n\r\nActiver l’aperçu lance un aperçu plein écran sur tous les moniteurs ; la boîte de "
    L"dialogue reste ouverte pour les réglages en direct. OK enregistre les réglages, Annuler les "
    L"abandonne. Échap ou un mouvement de souris quitte le plein écran. Utilisez Tab et Maj+Tab pour passer "
    L"d’un contrôle à l’autre ; Alt et la lettre soulignée activent une commande. Échap dans les réglages "
    L"équivaut à Annuler ; dans l’aide ou À propos, cette touche ferme uniquement cette "
    L"fenêtre.\r\n\r\nWindows 7 à Windows 11 sont pris en charge. Pour exécuter l’application sous Windows "
    L"Vista SP2, il est nécessaire d’installer les mises à jour KB971512 et KB2117917.",
    L"FlightCorridor: Vuelo entre cuatro superficies deformables; Vuelo por un embudo deformable. Asigne "
    L"una sola animación a cada pantalla. Textura alterna entre superficies texturizadas y modelo de "
    L"alambre. El giro libre de la cámara cambia lentamente la dirección de la vista en las tres "
    L"dimensiones. Paradas y cambios de sentido añade frenadas, pausas e inversiones aleatorias del giro; "
    L"el vuelo hacia delante continúa. La velocidad va del 0 al 1600 %. Cada pantalla tiene una escena "
    L"aleatoria independiente y se renderiza a su propia frecuencia de actualización.\r\n\r\nLa selección "
    L"de filas determina qué pantallas se están configurando; es independiente de las casillas que activan "
    L"las salidas de animación. Ctrl+A selecciona todas; Ctrl y Mayús modifican la selección. Todas las "
    L"opciones y los controles deslizantes de animación se aplican a las pantallas seleccionadas. La "
    L"selección se recuerda por separado para EXE y SCR. Si estaban seleccionadas todas, se incluyen "
    L"también las nuevas.\r\n\r\nActivar vista previa inicia una vista previa a pantalla completa en todos "
    L"los monitores; el cuadro de configuración permanece abierto para realizar ajustes en tiempo real. "
    L"Aceptar guarda y Cancelar descarta. Esc o mover el ratón cierra el salvapantallas completo. Use Tab y "
    L"Mayús+Tab para desplazarse entre controles; Alt y la letra subrayada activan una opción. Esc en la "
    L"configuración equivale a Cancelar; en Ayuda o Acerca de, cierra únicamente esa ventana.\r\n\r\nSe "
    L"admiten Windows 7 a Windows 11. Para ejecutar la aplicación en Windows Vista SP2, es necesario "
    L"instalar las actualizaciones KB971512 y KB2117917.",
    L"FlightCorridor: Volo tra quattro superfici deformabili; Volo attraverso un imbuto deformabile. "
    L"Assegnare una sola animazione a ogni schermo. Texture alterna superfici con texture e modello a "
    L"reticolo. La rotazione libera della telecamera cambia lentamente la direzione dello sguardo nelle tre "
    L"dimensioni. Arresti e inversioni aggiunge rallentamenti, pause e inversioni casuali della rotazione; "
    L"il volo in avanti continua. La velocità va da 0 a 1600%. Ogni schermo ha una scena casuale "
    L"indipendente, renderizzata alla propria frequenza di aggiornamento.\r\n\r\nLa selezione delle righe "
    L"determina quali schermi si stanno configurando ed è distinta dalle caselle che attivano le uscite di "
    L"animazione. Ctrl+A seleziona tutti gli schermi; Ctrl e Maiusc modificano la selezione. Tutte le "
    L"opzioni e i cursori dell’animazione riguardano gli schermi selezionati. La selezione viene "
    L"memorizzata separatamente per EXE e SCR. Se erano selezionati tutti gli schermi, vengono inclusi "
    L"anche quelli nuovi.\r\n\r\nAttiva anteprima avvia un’anteprima a schermo intero su tutti i monitor; "
    L"le impostazioni rimangono aperte per le modifiche in tempo reale. OK salva e Annulla scarta. Esc o il "
    L"movimento del mouse chiude il salvaschermo a schermo intero. Usare Tab e Maiusc+Tab per passare tra i "
    L"controlli; Alt e la lettera sottolineata attivano un comando. Esc nelle impostazioni equivale ad "
    L"Annulla; nella Guida o nelle Informazioni, chiude solo quella finestra.\r\n\r\nSono supportati i "
    L"sistemi da Windows 7 a Windows 11. Per eseguire l’applicazione su Windows Vista SP2, è necessario "
    L"installare gli aggiornamenti KB971512 e KB2117917.",
    L"FlightCorridor: Voo entre quatro superfícies deformáveis; Voo através de um funil deformável. Atribua "
    L"uma única animação a cada ecrã. Textura alterna entre superfícies texturadas e modelo em arame. A "
    L"rotação livre da câmara muda lentamente a direção da vista nas três dimensões. Paragens e inversões "
    L"de sentido acrescenta desacelerações, pausas e inversões aleatórias da rotação; o voo para a frente "
    L"continua. A velocidade vai de 0 a 1600%. Cada ecrã tem uma cena aleatória independente, apresentada à "
    L"sua própria frequência de atualização.\r\n\r\nA seleção das linhas determina os ecrãs a configurar e "
    L"é independente das caixas que ativam as saídas de animação. Ctrl+A seleciona todos os ecrãs; Ctrl e "
    L"Shift alteram a seleção. Todas as opções e controlos deslizantes da animação aplicam-se aos ecrãs "
    L"selecionados. A seleção é guardada separadamente para EXE e SCR. Se todos estavam selecionados, os "
    L"novos ecrãs também são incluídos.\r\n\r\nAtivar pré-visualização inicia uma pré-visualização em ecrã "
    L"inteiro em todos os monitores e permite ajustes em tempo real. OK guarda as definições e Cancelar "
    L"descarta-as. Esc ou o movimento do rato termina a proteção em ecrã inteiro. Use Tab e Shift+Tab para "
    L"passar entre controlos; Alt e a letra sublinhada ativam um comando. Esc nas definições equivale a "
    L"Cancelar; na Ajuda ou em Acerca de, fecha apenas essa janela.\r\n\r\nSão suportados os sistemas "
    L"Windows 7 a Windows 11. Para executar a aplicação no Windows Vista SP2, é necessário instalar as "
    L"atualizações KB971512 e KB2117917.",
    L"FlightCorridor: Przelot między czterema zmiennymi powierzchniami; Przelot przez zmienny lejek. "
    L"Każdemu monitorowi przypisz dokładnie jedną animację. Tekstura przełącza powierzchnie z teksturą i "
    L"model szkieletowy. Swobodne obracanie kamery powoli zmienia kierunek widoku we wszystkich trzech "
    L"wymiarach. Zatrzymania i zmiany kierunku dodają losowe zwalnianie, pauzy i odwracanie obrotu; lot do "
    L"przodu trwa nadal. Prędkość wynosi 0–1600%. Każdy monitor ma niezależną losową scenę wyświetlaną z "
    L"własną częstotliwością odświeżania.\r\n\r\nZaznaczenie wierszy określa konfigurowane monitory i jest "
    L"niezależne od pól wyboru włączających wyjścia animacji. Ctrl+A zaznacza wszystkie monitory; Ctrl i "
    L"Shift zmieniają zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą zaznaczonych monitorów. "
    L"Zaznaczenie jest zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były wszystkie monitory, nowe "
    L"również zostaną zaznaczone.\r\n\r\nWłącz podgląd uruchamia podgląd pełnoekranowy na wszystkich "
    L"monitorach. Okno ustawień pozostaje otwarte, umożliwiając zmiany na bieżąco. OK zapisuje ustawienia, "
    L"a Anuluj je odrzuca. Esc lub ruch myszy kończy tryb pełnoekranowy. Klawisze Tab i Shift+Tab "
    L"przełączają między kontrolkami; Alt i podkreślona litera wywołują polecenie. Esc w ustawieniach "
    L"odpowiada przyciskowi Anuluj; w Pomocy lub O programie zamyka tylko to okno.\r\n\r\nObsługiwane są "
    L"systemy od Windows 7 do Windows 11. Do uruchomienia aplikacji w systemie Windows Vista SP2 konieczne "
    L"jest zainstalowanie aktualizacji KB971512 i KB2117917.",
    L"FlightCorridor: Prelet štyrmi premenlivými plochami; Prelet premenlivým lievikom. Každému monitoru "
    L"priraďte práve jednu animáciu. Textúra prepína medzi textúrovanými plochami a drôteným modelom. "
    L"Prevaľovanie kamery pomaly mení smer pohľadu vo všetkých troch rozmeroch. Zastavovanie a zmeny smeru "
    L"pridáva náhodné spomaľovanie, prestávky a zmeny smeru otáčania; dopredný pohyb pokračuje. Rýchlosť je "
    L"0–1600 %. Každý monitor má nezávislú náhodnú scénu vykresľovanú podľa vlastnej obnovovacej "
    L"frekvencie.\r\n\r\nOznačenie riadkov určuje, ktoré monitory práve nastavujete; je nezávislé od "
    L"políčok zapínajúcich animačné výstupy. Ctrl+A označí všetky monitory, Ctrl a Shift upravujú "
    L"označenie. Všetky animačné voľby a posuvníky platia pre označené monitory. Označenie sa pamätá zvlášť "
    L"pre EXE a SCR. Ak boli označené všetky monitory, označia sa aj novopripojené.\r\n\r\nZapnúť náhľad "
    L"spustí celoobrazovkový náhľad na všetkých monitoroch; nastavenia zostávajú otvorené a zmeny sa "
    L"prejavia ihneď. OK uloží nastavenia a Zrušiť ich zahodí. Celoobrazovkový šetrič ukončí Esc alebo "
    L"pohyb myši. Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby "
    L"vyvoláte pomocou Alt a príslušného písmena. Esc v nastaveniach zodpovedá tlačidlu Zrušiť; v "
    L"Pomocníkovi alebo okne O aplikácii zavrie iba toto okno.\r\n\r\nPodporované sú systémy Windows 7 až "
    L"Windows 11. Na spustenie aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať aktualizácie "
    L"KB971512 a KB2117917.",
    L"FlightCorridor: Flyvetur mellem fire formskiftende flader; Flyvetur gennem en formskiftende tragt. "
    L"Tildel præcis én animation til hver skærm. Tekstur skifter mellem teksturerede flader og trådmodel. "
    L"Frit roterende kamera ændrer langsomt synsretningen i alle tre dimensioner. Stop og retningsskift "
    L"tilføjer tilfældige opbremsninger, pauser og ændringer af rotationsretningen; flyvningen fremad "
    L"fortsætter. Hastigheden er 0–1600 %. Hver skærm har en uafhængig tilfældig scene, der gengives med "
    L"dens egen opdateringsfrekvens.\r\n\r\nMarkeringen af rækker bestemmer, hvilke skærme du indstiller, "
    L"og er adskilt fra afkrydsningsfelterne, der aktiverer animationsoutput. Ctrl+A markerer alle skærme; "
    L"Ctrl og Skift ændrer markeringen. Alle animationsvalg og skydere gælder de markerede skærme. "
    L"Markeringen huskes separat for EXE og SCR. Hvis alle skærme var markeret, medtages også nye "
    L"skærme.\r\n\r\nAktivér forhåndsvisning starter en fuldskærmsvisning på alle skærme. Indstillingerne "
    L"forbliver åbne, og ændringerne vises med det samme. OK gemmer indstillingerne, og Annuller forkaster "
    L"ændringerne. Esc eller musebevægelse afslutter fuldskærmen. Brug Tab og Skift+Tab til at flytte "
    L"mellem kontrollerne; Alt og det understregede bogstav aktiverer en kommando. Esc i indstillingerne "
    L"svarer til Annuller; i Hjælp eller Om lukker det kun dette vindue.\r\n\r\nWindows 7 til Windows 11 "
    L"understøttes. For at køre programmet på Windows Vista SP2 skal opdateringerne KB971512 og KB2117917 "
    L"installeres.",
    L"FlightCorridor: Lento neljän muuntuvan pinnan välissä; Lento muuntuvan suppilon läpi. Valitse "
    L"kullekin näytölle yksi animaatio. Tekstuuri vaihtaa teksturoitujen pintojen ja rautalankamallin "
    L"välillä. Kameran vapaa pyörintä muuttaa katselusuuntaa hitaasti kaikissa kolmessa ulottuvuudessa. "
    L"Pysähdykset ja suunnanvaihdot lisää satunnaisia hidastuksia, taukoja ja pyörimissuunnan vaihtoja; "
    L"lento eteenpäin jatkuu. Nopeus on 0–1600%. Jokaisella näytöllä on itsenäinen satunnainen näkymä, joka "
    L"piirretään sen omalla virkistystaajuudella.\r\n\r\nRivien valinta määrää muokattavat näytöt ja on "
    L"erillinen animaatioulostulon valintaruuduista. Ctrl+A valitsee kaikki näytöt; Ctrl ja Vaihto "
    L"muuttavat valintaa. Kaikki animaatioasetukset ja liukusäätimet koskevat valittuja näyttöjä. Valinta "
    L"muistetaan erikseen EXE- ja SCR-tiloissa. Jos kaikki näytöt olivat valittuina, myös uudet näytöt "
    L"valitaan.\r\n\r\nOta esikatselu käyttöön käynnistää koko näytön esikatselun kaikilla näytöillä. "
    L"Asetusikkuna pysyy avoinna, ja muutokset näkyvät heti. OK tallentaa asetukset ja Peruuta hylkää "
    L"muutokset. Esc tai hiiren liike lopettaa koko näytön säästäjän. Siirry säätimien välillä Tab- ja "
    L"Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat komennon. Esc asetuksissa vastaa "
    L"Peruuta-painiketta; Ohje- tai Tietoja-ikkunassa se sulkee vain kyseisen ikkunan.\r\n\r\nTuettuja "
    L"käyttöjärjestelmiä ovat Windows 7–Windows 11. Sovelluksen suorittaminen Windows Vista SP2:ssa "
    L"edellyttää päivitysten KB971512 ja KB2117917 asentamista.",
    L"FlightCorridor: Flug milli fjögurra breytilegra flata; Flug í gegnum breytilega trekt. Veldu "
    L"nákvæmlega eina hreyfimynd fyrir hvern skjá. Áferð skiptir milli áferðarlagðra flata og víragrindar. "
    L"Frjáls snúningur myndavélar breytir sjónstefnunni hægt í öllum þremur víddum. Stopp og stefnuskipti "
    L"bætir við tilviljanakenndri hægingu, hléum og breytingum á snúningsstefnu; flug áfram heldur áfram. "
    L"Hraðinn er 0–1600%. Hver skjár hefur sjálfstæða tilviljanakennda senu sem er teiknuð á eigin "
    L"endurnýjunartíðni.\r\n\r\nVal lína ákvarðar hvaða skjám er verið að breyta og er óháð gátreitunum sem "
    L"kveikja á hreyfimyndaúttaki. Ctrl+A velur alla skjái; Ctrl og Shift breyta valinu. Allir valkostir og "
    L"sleðar hreyfimynda gilda fyrir valda skjái. Valið er munað sérstaklega fyrir EXE og SCR. Ef allir "
    L"skjáir voru valdir bætast nýir skjáir einnig við valið.\r\n\r\nVirkja forskoðun ræsir forskoðun á "
    L"öllum skjám. Stillingaglugginn helst opinn og breytingar sjást strax. Í lagi vistar stillingar og "
    L"Hætta við hafnar breytingum. Esc eða músarhreyfing lokar skjáhvílu á öllum skjánum. Notaðu Tab og "
    L"Shift+Tab til að færa þig milli stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc í "
    L"stillingum jafngildir Hætta við; í Hjálp eða Um lokar það aðeins þeim glugga.\r\n\r\nWindows 7 til "
    L"Windows 11 eru studd. Til að keyra forritið á Windows Vista SP2 þarf að setja upp uppfærslurnar "
    L"KB971512 og KB2117917.",
    L"FlightCorridor: Flytur mellom fire formendrende flater; Flytur gjennom en formendrende trakt. "
    L"Tilordne nøyaktig én animasjon til hver skjerm. Tekstur veksler mellom teksturerte flater og "
    L"trådmodell. Fritt roterende kamera endrer synsretningen langsomt i alle tre dimensjoner. Stopp og "
    L"retningsendringer legger til tilfeldige oppbremsinger, pauser og endringer i rotasjonsretningen; "
    L"flyvningen fremover fortsetter. Hastigheten er 0–1600 %. Hver skjerm har en uavhengig tilfeldig scene "
    L"som gjengis ved dens egen oppdateringsfrekvens.\r\n\r\nMarkeringen av rader bestemmer hvilke skjermer "
    L"du redigerer, og er atskilt fra avkrysningsboksene som aktiverer animasjonsutgangen. Ctrl+A markerer "
    L"alle skjermer; Ctrl og Skift endrer markeringen. Alle animasjonsvalg og glidebrytere gjelder de "
    L"markerte skjermene. Markeringen huskes separat for EXE og SCR. Hvis alle skjermer var markert, "
    L"inkluderes også nye skjermer.\r\n\r\nSlå på forhåndsvisning starter en fullskjermsvisning på alle "
    L"skjermer. Innstillingene forblir åpne, og endringene vises fortløpende. OK lagrer innstillingene og "
    L"Avbryt forkaster dem. Esc eller musebevegelse avslutter fullskjermsvisningen. Bruk Tab og Shift+Tab "
    L"for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc i "
    L"innstillingene tilsvarer Avbryt; i Hjelp eller Om lukker det bare dette vinduet.\r\n\r\nWindows 7 til "
    L"Windows 11 støttes. For å kjøre programmet på Windows Vista SP2 må oppdateringene KB971512 og "
    L"KB2117917 installeres.",
    L"FlightCorridor: Flygtur mellan fyra formföränderliga ytor; Flygtur genom en formföränderlig tratt. "
    L"Tilldela varje skärm exakt en animering. Textur växlar mellan texturerade ytor och trådmodell. Fritt "
    L"roterande kamera ändrar långsamt blickriktningen i alla tre dimensioner. Stopp och riktningsbyten "
    L"lägger till slumpmässiga inbromsningar, pauser och byten av rotationsriktning; flygningen framåt "
    L"fortsätter. Hastigheten är 0–1600 %. Varje skärm har en oberoende slumpmässig scen som återges med "
    L"dess egen uppdateringsfrekvens.\r\n\r\nMarkeringen av rader avgör vilka skärmar du redigerar och är "
    L"skild från kryssrutorna som aktiverar animationsutgångarna. Ctrl+A markerar alla skärmar; Ctrl och "
    L"Skift ändrar markeringen. Alla animationsalternativ och reglage gäller de markerade skärmarna. "
    L"Markeringen sparas separat för EXE och SCR. Om alla skärmar var markerade inkluderas även nya "
    L"skärmar.\r\n\r\nAktivera förhandsvisning startar en helskärmsvisning på alla bildskärmar. "
    L"Inställningarna förblir öppna och ändringarna visas direkt. OK sparar inställningarna och Avbryt "
    L"förkastar ändringarna. Esc eller musrörelse avslutar helskärmsläget. Använd Tab och Skift+Tab för att "
    L"flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett kommando. Esc i "
    L"inställningarna motsvarar Avbryt; i Hjälp eller Om stänger det bara det fönstret.\r\n\r\nWindows 7 "
    L"till Windows 11 stöds. För att köra programmet på Windows Vista SP2 måste uppdateringarna KB971512 "
    L"och KB2117917 installeras.",
    L"FlightCorridor: Biçim değiştiren dört yüzey arasında uçuş; Biçim değiştiren bir huninin içinden uçuş. "
    L"Her ekrana tam bir animasyon atayın. Doku, dokulu yüzeyler ile tel kafes modeli arasında geçiş yapar. "
    L"Serbest kamera dönüşü bakış yönünü üç boyutta yavaşça değiştirir. Duraklamalar ve yön değişimleri, "
    L"dönüşe rastgele yavaşlamalar, duraklamalar ve ters yön değişimleri ekler; ileri uçuş devam eder. Hız "
    L"0–1600% aralığındadır. Her ekranın kendi yenileme hızında çizilen bağımsız rastgele bir sahnesi "
    L"vardır.\r\n\r\nSatır seçimi, hangi ekranların düzenlendiğini belirler; animasyon çıkışlarını açan "
    L"onay kutularından ayrıdır. Ctrl+A tüm ekranları seçer; Ctrl ve Shift seçimi değiştirir. Tüm animasyon "
    L"seçenekleri ve kaydırıcılar seçili ekranlara uygulanır. Seçim EXE ve SCR için ayrı saklanır. Tüm "
    L"ekranlar seçiliyse sonradan bağlanan ekranlar da seçime katılır.\r\n\r\nÖnizlemeyi etkinleştir tüm "
    L"monitörlerde tam ekran önizleme başlatır. Ayarlar penceresi açık kalır ve değişiklikler anında "
    L"görülür. Tamam ayarları kaydeder, İptal değişiklikleri iptal eder. Tam ekran koruyucudan Esc veya "
    L"fare hareketiyle çıkılır. Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf "
    L"bir komutu etkinleştirir. Ayarlarda Esc, İptal ile aynı işlevi görür; Yardım veya Hakkında "
    L"penceresinde yalnızca o pencereyi kapatır.\r\n\r\nWindows 7 ile Windows 11 arasındaki sürümler "
    L"desteklenir. Uygulamayı Windows Vista SP2'de çalıştırmak için KB971512 ve KB2117917 güncellemelerini "
    L"yüklemeniz gerekir.",
    L"Riistvarakiirendusega lend muutuvate pindade vahel. Lend nelja muutuva pinna vahel; Lend läbi muutuva "
    L"lehtri. Valige igale kuvarile täpselt üks animatsioon. Tekstuuri märkeruut vahetab tekstuuriga pinna "
    L"ja traatmudeli vahel. Kaamera vaba pöörlemine muudab vaatesuunda aeglaselt kõigis kolmes mõõtmes. "
    L"Peatumised ja suunavahetused lisab sellele juhuslikke aeglustusi, pause ja pöörlemissuuna muutusi; "
    L"edasilend jätkub. Kiirus on seatav vahemikus 0–1600%. Igal kuvaril on oma sõltumatu juhuslik stseen "
    L"ja värskendussagedusele vastav renderdus.\r\n\r\nValige loendis üks või mitu kuvaririda. Ctrl+A valib "
    L"kõik read; Ctrl ja Shift võimaldavad valikut muuta. Animatsiooni juhtnupud ja liugurid mõjutavad "
    L"ainult valitud kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle märkeruuduga väljundi "
    L"lubamine on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja jaoks eraldi meelde. Kui varem "
    L"olid valitud kõik kuvarid, kaasatakse ka lisatud kuvarid.\r\n\r\nKäivitage FlightCorridor.scr "
    L"Windowsi ekraanisäästjana. Selle sätted on rakenduse omadest eraldi. Sätete eelvaade lubab "
    L"täisekraanil animatsiooni jooksvalt muuta. OK salvestab muudatused ning Loobu või Esc tühistab need. "
    L"Täisekraanil ekraanisäästjast väljumiseks vajutage klahvi või liigutage hiirt.\r\n\r\nWindows 7–11 "
    L"toetab kõiki funktsioone. Windows Vista SP2 jaoks tuleb paigaldada värskendused KB971512 ja "
    L"KB2117917; MP4 salvestamine Vistas ei tööta. Vaja on Direct3D 11 tuge ning MP4 jaoks Media "
    L"Foundationi ja H.264 kodeerijat. Liides ja dokumentatsioon on saadaval 36 keeles.",
    L"Eitilt idir dromchlaí athraitheacha le luasghéarú crua-earraí. Eitilt idir ceithre dhromchla "
    L"athraitheacha; Eitilt trí thonnadóir athraitheach. Roghnaigh beochan amháin do gach monatóir. "
    L"Athraíonn Uigeacht idir dromchla uigeachtaithe agus samhail sreangfhráma. Rothlaíonn rothlú saor an "
    L"cheamara an radharc go mall sna trí thoise. Cuireann Stadanna agus aisiompuithe coscánú, sosanna agus "
    L"athruithe treo randamacha leis an rothlú; leanann an eitilt chun tosaigh. Tá luas 0–1600% ar fáil. Tá "
    L"radharc randamach neamhspleách ag gach monatóir agus déantar rindreáil de réir a ráta athnuachana "
    L"féin.\r\n\r\nRoghnaigh ró amháin nó níos mó sa liosta monatóirí. Roghnaíonn Ctrl+A gach ró; úsáid "
    L"Ctrl agus Shift chun an roghnú a athrú. Ní athraíonn rialuithe agus sleamhnáin na beochana ach "
    L"socruithe na monatóirí roghnaithe. Ní hionann ró a roghnú agus aschur an mhonatóra a chumasú lena "
    L"bhosca seiceála. Cuimhnítear an roghnú ar leith don fheidhmchlár agus don spárálaí. Má bhí gach "
    L"monatóir roghnaithe, cuirtear monatóirí nua leis an roghnú freisin.\r\n\r\nÚsáid FlightCorridor.scr "
    L"mar spárálaí scáileáin Windows. Tá a shocruithe ar leith ó shocruithe an fheidhmchláir. Ceadaíonn an "
    L"réamhamharc lánscáileáin athruithe beo. Sábhálann OK agus cealaíonn Cealaigh nó Esc na hathruithe. "
    L"Fág an spárálaí lánscáileáin le heochair ar bith nó le gluaiseacht na luiche.\r\n\r\nTacaíonn Windows "
    L"7–11 leis na gnéithe uile. Ar Windows Vista SP2 ní mór nuashonruithe KB971512 agus KB2117917 a "
    L"shuiteáil; ní oibríonn taifeadadh MP4 ar Vista. Teastaíonn tacaíocht Direct3D 11, agus Media "
    L"Foundation agus ionchódóir H.264 le haghaidh MP4. Tá an comhéadan agus an doiciméadú ar fáil i 36 "
    L"teanga.",
    L"Aparatine įranga spartinamas skrydis tarp kintančių paviršių. Skrydis tarp keturių kintančių "
    L"paviršių; Skrydis kintančiu piltuvu. Kiekvienam monitoriui pasirinkite vieną animaciją. Tekstūros "
    L"langelis perjungia tekstūruotą paviršių ir vielinį modelį. Laisvas kameros sukimasis lėtai keičia "
    L"žiūrėjimo kryptį visose trijose dimensijose. Sustojimai ir krypties keitimai prideda atsitiktinį "
    L"lėtėjimą, pauzes ir sukimosi krypties keitimą; skrydis pirmyn tęsiasi. Galimas 0–1600% greitis. "
    L"Kiekvienas monitorius turi nepriklausomą atsitiktinę sceną, atvaizduojamą jo atnaujinimo "
    L"dažniu.\r\n\r\nMonitorių sąraše pasirinkite vieną ar kelias eilutes. Ctrl+A pasirenka visas, o Ctrl "
    L"ir Shift leidžia keisti pasirinkimą. Animacijos valdikliai ir slankikliai keičia tik pasirinktų "
    L"monitorių nuostatas. Eilutės pasirinkimas nėra tas pats, kas animacijos išvesties įjungimas jos "
    L"žymimuoju langeliu. Pasirinkimas atskirai įsimenamas programai ir užsklandai. Jei buvo pasirinkti "
    L"visi monitoriai, į pasirinkimą įtraukiami ir naujai prijungti monitoriai.\r\n\r\nNaudokite "
    L"FlightCorridor.scr kaip Windows ekrano užsklandą. Jos nuostatos atskiros nuo programos. Viso ekrano "
    L"peržiūra leidžia jas keisti vykstant animacijai. OK išsaugo, Atšaukti arba Esc atmeta pakeitimus. "
    L"Užsklandą užbaikite klavišu arba pajudindami pelę.\r\n\r\nWindows 7–11 palaiko visas funkcijas. "
    L"Windows Vista SP2 būtina įdiegti naujinimus KB971512 ir KB2117917; MP4 įrašymas Vistoje neveikia. "
    L"Reikalingas Direct3D 11 palaikymas, o MP4 įrašymui Media Foundation ir H.264 koduotuvas. Sąsaja ir "
    L"dokumentacija pateikiamos 36 kalbomis.",
    L"Aparatūras paātrināts lidojums starp mainīgām virsmām. Lidojums starp četrām mainīgām virsmām; "
    L"Lidojums caur mainīgu piltuvi. Katram monitoram izvēlieties tieši vienu animāciju. Tekstūras rūtiņa "
    L"pārslēdz teksturētu virsmu un stiepļu modeli. Brīva kameras rotācija lēnām maina skatiena virzienu "
    L"visās trijās dimensijās. Apstāšanās un virziena maiņa pievieno nejaušu palēninājumu, pauzes un "
    L"rotācijas virziena maiņu; lidojums uz priekšu turpinās. Pieejams ātrums 0–1600%. Katram monitoram ir "
    L"neatkarīga nejauša aina, ko renderē tā atsvaidzināšanas frekvencē.\r\n\r\nMonitoru sarakstā atlasiet "
    L"vienu vai vairākas rindas. Ctrl+A atlasa visas, bet Ctrl un Shift ļauj mainīt atlasi. Animācijas "
    L"vadīklas un slīdņi maina tikai atlasīto monitoru iestatījumus. Rindas atlasīšana nav tas pats, kas "
    L"animācijas izvades ieslēgšana ar izvēles rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un "
    L"ekrānsaudzētājam. Ja bija atlasīti visi monitori, atlasē iekļauj arī jaunpievienotos "
    L"monitorus.\r\n\r\nIzmantojiet FlightCorridor.scr kā Windows ekrānsaudzētāju. Tā iestatījumi ir "
    L"atsevišķi no lietotnes. Pilnekrāna priekšskatījums ļauj tos mainīt animācijas darbības laikā. OK "
    L"saglabā, Atcelt vai Esc atmet izmaiņas. Pilnekrāna ekrānsaudzētāju aizveriet ar taustiņu vai peles "
    L"kustību.\r\n\r\nWindows 7–11 atbalsta visas funkcijas. Windows Vista SP2 jāinstalē atjauninājumi "
    L"KB971512 un KB2117917; MP4 ierakstīšana Vistā nedarbojas. Nepieciešams Direct3D 11 atbalsts, bet MP4 "
    L"vajadzīgi Media Foundation un H.264 kodētājs. Saskarne un dokumentācija ir pieejama 36 valodās.",
    L"Hardveresen gyorsított repülés változó felületek között. Repülés négy változó felület között; Repülés "
    L"változó tölcsérben. Monitoronként pontosan egy animáció választható. A Textúra jelölőnégyzet a "
    L"textúrázott felület és a drótváz között vált. A kamera szabad forgása lassan változtatja a nézetet "
    L"mindhárom dimenzióban. A Megállások és irányváltások véletlenszerű lassításokat, szüneteket és "
    L"forgásirányváltásokat ad hozzá; az előrehaladás folytatódik. A sebesség 0–1600%. Minden monitor "
    L"önálló véletlenszerű jelenetet kap, saját frissítési gyakoriságához igazodó "
    L"megjelenítéssel.\r\n\r\nJelöljön ki egy vagy több sort a monitorok listájában. A Ctrl+A mindet "
    L"kijelöli; a Ctrl és a Shift módosítja a kijelölést. Az animáció vezérlői és csúszkái csak a kijelölt "
    L"monitorok beállításait változtatják. A sor kijelölése és az animációs kimenet jelölőnégyzetes "
    L"engedélyezése külön művelet. A kijelölést az alkalmazás és a képernyőkímélő külön megjegyzi. Ha "
    L"korábban minden monitor ki volt jelölve, az újonnan csatlakoztatott monitorok is bekerülnek a "
    L"kijelölésbe.\r\n\r\nA FlightCorridor.scr Windows-képernyőkímélőként használható, az alkalmazástól "
    L"külön beállításokkal. A teljes képernyős előnézetben élőben módosíthatók a beállítások. Az OK ment, a "
    L"Mégse vagy Esc elveti a módosításokat. A teljes képernyős képernyőkímélő billentyűvel vagy "
    L"egérmozgással zárható be.\r\n\r\nA Windows 7–11 minden funkciót támogat. Windows Vista SP2 alatt "
    L"telepíteni kell a KB971512 és KB2117917 frissítést; az MP4-felvétel Vistán nem működik. Direct3D 11 "
    L"támogatás szükséges, az MP4-hez Media Foundation és H.264-kódoló is kell. A kezelőfelület és a "
    L"dokumentáció 36 nyelven érhető el.",
    L"Titjira bejn uċuħ li jinbidlu aċċellerata bil-ħardwer. Titjira bejn erba’ uċuħ li jinbidlu; Titjira "
    L"f’lembut li jinbidel. Agħżel animazzjoni waħda biss għal kull moniter. Nisġa taqleb bejn wiċċ b’nisġa "
    L"u mudell bil-wireframe. Ir-rotazzjoni libera tal-kamera tbiddel id-direzzjoni tal-ħarsa bil-mod "
    L"fit-tliet dimensjonijiet. Waqfiet u bidliet fid-direzzjoni żżid deċelerazzjonijiet, pawżi u treġġigħ "
    L"lura tar-rotazzjoni b’mod każwali; it-titjira ’l quddiem tkompli. Il-veloċità hija 0–1600%. Kull "
    L"moniter għandu xena każwali indipendenti li tintwera bir-rata ta’ aġġornament tiegħu.\r\n\r\nAgħżel "
    L"ringiela waħda jew aktar fil-lista tal-moniters. Ctrl+A jagħżilhom kollha; Ctrl u Shift ibiddlu "
    L"l-għażla. Il-kontrolli u s-sliders tal-animazzjoni jibdlu biss is-settings tal-moniters magħżula. "
    L"L-għażla ta’ ringiela hija differenti mill-attivazzjoni tal-output permezz tal-kaxxa tal-marka. "
    L"L-għażla tinżamm separatament għall-applikazzjoni u għall-iscreen saver. Jekk il-moniters kollha "
    L"kienu magħżula, il-moniters ġodda jiddaħħlu wkoll fl-għażla.\r\n\r\nUża FlightCorridor.scr bħala "
    L"screen saver ta’ Windows. Is-settings tiegħu huma separati minn dawk tal-applikazzjoni. Il-previżjoni "
    L"fuq skrin sħiħ tippermetti bidliet waqt l-animazzjoni. OK isalva u Ikkanċella jew Esc jarmi "
    L"l-bidliet. Oħroġ mill-iscreen saver bi kwalunkwe tast jew billi ċċaqlaq il-maws.\r\n\r\nWindows 7–11 "
    L"jappoġġja l-funzjonijiet kollha. Fuq Windows Vista SP2 għandhom jiġu installati l-aġġornamenti "
    L"KB971512 u KB2117917; ir-reġistrazzjoni MP4 ma taħdimx fuq Vista. Huwa meħtieġ Direct3D 11 u, "
    L"għall-MP4, Media Foundation u encoder H.264. L-interface u d-dokumentazzjoni huma disponibbli f’36 "
    L"lingwa.",
    L"Hardwareversnelde vlucht tussen vervormende oppervlakken. Vlucht tussen vier vervormende "
    L"oppervlakken; Vlucht door een vervormende trechter. Kies precies één animatie per beeldscherm. "
    L"Textuur schakelt tussen een getextureerd oppervlak en een draadmodel. Vrije camerarotatie verandert "
    L"de kijkrichting langzaam in alle drie dimensies. Stops en richtingswisselingen voegt willekeurige "
    L"vertragingen, pauzes en omkeringen van de rotatie toe; de voorwaartse vlucht gaat door. De snelheid "
    L"is instelbaar op 0–1600%. Elk beeldscherm heeft een onafhankelijke willekeurige scène en wordt op "
    L"zijn eigen vernieuwingsfrequentie aangestuurd.\r\n\r\nSelecteer één of meer beeldschermrijen in de "
    L"lijst. Ctrl+A selecteert alles; met Ctrl en Shift past u de selectie aan. Animatieknoppen en "
    L"schuifregelaars wijzigen alleen de instellingen van de geselecteerde beeldschermen. Een rij "
    L"selecteren is iets anders dan de animatie-uitvoer inschakelen met het selectievakje. De selectie "
    L"wordt apart onthouden voor de toepassing en de schermbeveiliging. Als alle beeldschermen waren "
    L"geselecteerd, worden nieuw aangesloten beeldschermen ook geselecteerd.\r\n\r\nGebruik "
    L"FlightCorridor.scr als Windows-schermbeveiliging met eigen instellingen. Het schermvullende voorbeeld "
    L"laat live aanpassingen toe. OK slaat wijzigingen op; Annuleren of Esc verwerpt ze. Sluit de "
    L"schermvullende schermbeveiliging met een toets of een muisbeweging.\r\n\r\nWindows 7–11 ondersteunt "
    L"alle functies. Voor Windows Vista SP2 moet u updates KB971512 en KB2117917 installeren; MP4-opname "
    L"werkt niet op Vista. Direct3D 11-ondersteuning is vereist; voor MP4 zijn ook Media Foundation en een "
    L"H.264-encoder nodig. Interface en documentatie zijn beschikbaar in 36 talen.",
    L"Zbor între suprafețe deformabile accelerat hardware. Zbor între patru suprafețe deformabile; Zbor "
    L"printr-o pâlnie deformabilă. Alegeți exact o animație pentru fiecare monitor. Textură comută între "
    L"suprafața texturată și modelul de sârmă. Rotirea liberă a camerei schimbă lent direcția privirii în "
    L"toate cele trei dimensiuni. Opriri și inversări de sens adaugă încetiniri, pauze și inversări ale "
    L"rotației la intervale aleatorii; zborul înainte continuă. Viteza este 0–1600%. Fiecare monitor are o "
    L"scenă aleatorie independentă, randată la propria rată de reîmprospătare.\r\n\r\nSelectați unul sau "
    L"mai multe rânduri din lista monitoarelor. Ctrl+A le selectează pe toate; Ctrl și Shift modifică "
    L"selecția. Comenzile și glisoarele animației schimbă numai setările monitoarelor selectate. Selectarea "
    L"unui rând diferă de activarea ieșirii prin caseta sa de selectare. Selecția este reținută separat "
    L"pentru aplicație și economizor. Dacă erau selectate toate monitoarele, sunt incluse și cele conectate "
    L"ulterior.\r\n\r\nFolosiți FlightCorridor.scr drept economizor de ecran Windows, cu setări separate de "
    L"aplicație. Previzualizarea pe tot ecranul permite ajustări în timp real. OK salvează modificările; "
    L"Anulare sau Esc le anulează. Ieșiți din economizor apăsând o tastă sau mișcând "
    L"mouse-ul.\r\n\r\nWindows 7–11 acceptă toate funcțiile. Pentru Windows Vista SP2 trebuie instalate "
    L"actualizările KB971512 și KB2117917; înregistrarea MP4 nu funcționează pe Vista. Este necesar "
    L"Direct3D 11, iar pentru MP4 și Media Foundation și un codificator H.264. Interfața și documentația "
    L"sunt disponibile în 36 de limbi.",
    L"Πτήση ανάμεσα σε μεταβαλλόμενες επιφάνειες με επιτάχυνση υλικού. Πτήση ανάμεσα σε τέσσερις "
    L"μεταβαλλόμενες επιφάνειες; Πτήση μέσα από μεταβαλλόμενη χοάνη. Επιλέξτε ακριβώς μία κίνηση ανά οθόνη. "
    L"Η Υφή εναλλάσσει επιφάνεια με υφή και συρμάτινο μοντέλο. Η ελεύθερη περιστροφή κάμερας αλλάζει αργά "
    L"την κατεύθυνση θέασης και στις τρεις διαστάσεις. Οι Στάσεις και αντιστροφές προσθέτουν τυχαίες "
    L"επιβραδύνσεις, παύσεις και αντιστροφές περιστροφής, ενώ η πτήση προς τα εμπρός συνεχίζεται. Η "
    L"ταχύτητα είναι 0–1600%. Κάθε οθόνη διαθέτει ανεξάρτητη τυχαία σκηνή που αποδίδεται στον δικό της "
    L"ρυθμό ανανέωσης.\r\n\r\nΕπιλέξτε μία ή περισσότερες γραμμές στη λίστα οθονών. Το Ctrl+A επιλέγει "
    L"όλες, ενώ τα Ctrl και Shift αλλάζουν την επιλογή. Τα χειριστήρια και τα ρυθμιστικά της κίνησης "
    L"αλλάζουν μόνο τις ρυθμίσεις των επιλεγμένων οθονών. Η επιλογή γραμμής διαφέρει από την ενεργοποίηση "
    L"εξόδου μέσω του πλαισίου ελέγχου της. Η επιλογή αποθηκεύεται χωριστά για την εφαρμογή και την "
    L"προφύλαξη. Αν είχαν επιλεγεί όλες οι οθόνες, περιλαμβάνονται και όσες συνδεθούν "
    L"αργότερα.\r\n\r\nΧρησιμοποιήστε το FlightCorridor.scr ως προφύλαξη οθόνης Windows με χωριστές "
    L"ρυθμίσεις από την εφαρμογή. Η προεπισκόπηση πλήρους οθόνης επιτρέπει ζωντανές αλλαγές. Το OK "
    L"αποθηκεύει και το Άκυρο ή Esc απορρίπτει τις αλλαγές. Τερματίστε την προφύλαξη με πλήκτρο ή κίνηση "
    L"του ποντικιού.\r\n\r\nΤα Windows 7–11 υποστηρίζουν όλες τις λειτουργίες. Στα Windows Vista SP2 πρέπει "
    L"να εγκατασταθούν οι ενημερώσεις KB971512 και KB2117917· η εγγραφή MP4 δεν λειτουργεί στα Vista. "
    L"Απαιτείται υποστήριξη Direct3D 11 και, για MP4, Media Foundation και κωδικοποιητής H.264. Η διεπαφή "
    L"και η τεκμηρίωση διατίθενται σε 36 γλώσσες.",
    L"Hardverski ubrzan let između promjenjivih površina. Let između četiri promjenjive površine; Let kroz "
    L"promjenjivi lijevak. Za svaki monitor odaberite tačno jednu animaciju. Tekstura mijenja prikaz između "
    L"teksturirane površine i žičanog modela. Slobodno okretanje kamere polako mijenja smjer pogleda u sve "
    L"tri dimenzije. Zaustavljanja i promjene smjera dodaju nasumično usporavanje, pauze i promjene smjera "
    L"rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki monitor ima nezavisnu nasumičnu scenu "
    L"koja se prikazuje prema njegovoj frekvenciji osvježavanja.\r\n\r\nOdaberite jedan ili više redova u "
    L"listi monitora. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije "
    L"mijenjaju samo postavke odabranih monitora. Odabir reda nije isto što i uključivanje izlaza njegovom "
    L"kućicom. Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili odabrani svi "
    L"monitori, uključuju se i novopriključeni monitori.\r\n\r\nKoristite FlightCorridor.scr kao Windows "
    L"čuvar ekrana s odvojenim postavkama. Pregled preko cijelog ekrana omogućava izmjene uživo. OK čuva, a "
    L"Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili pomjeranjem "
    L"miša.\r\n\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja "
    L"KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media "
    L"Foundation te H.264 koder. Interfejs i dokumentacija dostupni su na 36 jezika.",
    L"Hardverski ubrzan let između promjenjivih ploha. Let između četiriju promjenjivih ploha; Let kroz "
    L"promjenjivi lijevak. Za svaki zaslon odaberite točno jednu animaciju. Tekstura mijenja prikaz između "
    L"teksturirane plohe i žičanog modela. Slobodno okretanje kamere polako mijenja smjer pogleda u sve tri "
    L"dimenzije. Zaustavljanja i promjene smjera dodaju nasumično usporavanje, stanke i promjene smjera "
    L"rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki zaslon ima neovisnu nasumičnu scenu "
    L"koja se prikazuje prema njegovoj frekvenciji osvježavanja.\r\n\r\nOdaberite jedan ili više redaka na "
    L"popisu zaslona. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije "
    L"mijenjaju samo postavke odabranih zaslona. Odabir retka nije isto što i uključivanje izlaza njegovim "
    L"potvrdnim okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar zaslona. Ako su prethodno bili "
    L"odabrani svi zasloni, uključuju se i novopriključeni zasloni.\r\n\r\nKoristite FlightCorridor.scr kao "
    L"Windows čuvar zaslona s odvojenim postavkama. Pretpregled preko cijelog zaslona omogućuje izmjene "
    L"uživo. OK sprema, a Odustani ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili "
    L"pomicanjem miša.\r\n\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati "
    L"ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i "
    L"Media Foundation te H.264 koder. Sučelje i dokumentacija dostupni su na 36 jezika.",
    L"Strojno pospešen let med spreminjajočimi se ploskvami. Let med štirimi spreminjajočimi se ploskvami; "
    L"Let skozi spreminjajoči se lijak. Za vsak zaslon izberite natanko eno animacijo. Tekstura preklaplja "
    L"med teksturirano ploskvijo in žičnim modelom. Prosto vrtenje kamere počasi spreminja smer pogleda v "
    L"vseh treh razsežnostih. Ustavljanja in spremembe smeri dodajo naključne upočasnitve, premore in "
    L"obrate smeri vrtenja; let naprej se nadaljuje. Hitrost je 0–1600%. Vsak zaslon ima neodvisen "
    L"naključen prizor, ki se izrisuje z njegovo hitrostjo osveževanja.\r\n\r\nNa seznamu zaslonov izberite "
    L"eno ali več vrstic. Ctrl+A izbere vse, Ctrl in Shift pa spreminjata izbor. Kontrolniki in drsniki "
    L"animacije spreminjajo samo nastavitve izbranih zaslonov. Izbira vrstice ni isto kot vklop izhoda z "
    L"njenim potrditvenim poljem. Izbor se ločeno shrani za program in ohranjevalnik. Če so bili izbrani "
    L"vsi zasloni, so vključeni tudi na novo priključeni zasloni.\r\n\r\nUporabite FlightCorridor.scr kot "
    L"ohranjevalnik zaslona Windows z ločenimi nastavitvami. Celozaslonski predogled omogoča sprotne "
    L"spremembe. OK jih shrani, Prekliči ali Esc jih zavrže. Ohranjevalnik zapustite s tipko ali premikom "
    L"miške.\r\n\r\nWindows 7–11 podpira vse funkcije. Za Windows Vista SP2 morate namestiti posodobitvi "
    L"KB971512 in KB2117917; snemanje MP4 v Visti ne deluje. Potrebna je podpora Direct3D 11, za MP4 pa še "
    L"Media Foundation in kodirnik H.264. Vmesnik in dokumentacija sta na voljo v 36 jezikih.",
    L"Hardverski ubrzan let između promjenljivih površina. Let između četiri promjenljive površine; Let "
    L"kroz promjenljivi lijevak. Za svaki monitor izaberite tačno jednu animaciju. Tekstura mijenja prikaz "
    L"između teksturisane površine i žičanog modela. Slobodno okretanje kamere polako mijenja smjer pogleda "
    L"u sve tri dimenzije. Zaustavljanja i promjene smjera dodaju nasumično usporavanje, pauze i promjene "
    L"smjera rotacije; let naprijed se nastavlja. Brzina je 0–1600%. Svaki monitor ima nezavisnu nasumičnu "
    L"scenu koja se prikazuje prema njegovoj frekvenciji osvježavanja.\r\n\r\nIzaberite jedan ili više "
    L"redova u listi monitora. Ctrl+A bira sve; Ctrl i Shift mijenjaju izbor. Kontrole i klizači animacije "
    L"mijenjaju samo podešavanja izabranih monitora. Izbor reda nije isto što i uključivanje izlaza "
    L"njegovom kućicom. Izbor se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
    L"izabrani svi monitori, uključuju se i novopriključeni monitori.\r\n\r\nKoristite FlightCorridor.scr "
    L"kao Windows čuvar ekrana s odvojenim podešavanjima. Pregled preko cijelog ekrana omogućava izmjene "
    L"uživo. OK čuva, a Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tastera ili "
    L"pomjeranjem miša.\r\n\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati "
    L"ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i "
    L"Media Foundation i H.264 koder. Interfejs i dokumentacija dostupni su na 36 jezika.",
    L"Апаратна паскораны палёт паміж зменлівымі паверхнямі. Палёт паміж чатырма зменлівымі паверхнямі; "
    L"Палёт праз зменлівую варонку. Для кожнага манітора выберыце роўна адну анімацыю. Тэкстура пераключае "
    L"тэкстураваную паверхню і каркасную мадэль. Свабоднае кручэнне камеры павольна змяняе напрамак погляду "
    L"ва ўсіх трох вымярэннях. Спыненні і змены напрамку дадаюць выпадковыя запаволенні, паўзы і змены "
    L"напрамку кручэння; палёт наперад працягваецца. Хуткасць — 0–1600%. Кожны манітор мае незалежную "
    L"выпадковую сцэну з вывадам паводле ўласнай частаты абнаўлення.\r\n\r\nВыберыце адзін або некалькі "
    L"радкоў у спісе манітораў. Ctrl+A выбірае ўсе; Ctrl і Shift змяняюць выбар. Элементы кіравання і "
    L"паўзункі анімацыі змяняюць толькі налады выбраных манітораў. Выбар радка і ўключэнне вываду яго "
    L"сцяжком — розныя дзеянні. Выбар асобна захоўваецца для праграмы і застаўкі. Калі раней былі выбраны "
    L"ўсе маніторы, да выбару далучаюцца і новыя маніторы.\r\n\r\nВыкарыстоўвайце FlightCorridor.scr як "
    L"застаўку Windows з асобнымі наладамі. Поўнаэкранны перадпрагляд дазваляе змяняць іх падчас анімацыі. "
    L"OK захоўвае змены, Скасаваць або Esc адхіляе іх. Для выхаду з застаўкі націсніце клавішу або "
    L"паварушыце мышшу.\r\n\r\nWindows 7–11 падтрымлівае ўсе функцыі. Для Windows Vista SP2 неабходна "
    L"ўсталяваць абнаўленні KB971512 і KB2117917; запіс MP4 у Vistа не працуе. Патрэбна падтрымка Direct3D "
    L"11, а для MP4 таксама Media Foundation і кадавальнік H.264. Інтэрфейс і дакументацыя даступны на 36 "
    L"мовах.",
    L"Хардуерно ускорен полет между променящи се повърхнини. Полет между четири променящи се повърхнини; "
    L"Полет през променяща се фуния. Изберете точно една анимация за всеки монитор. Текстура превключва "
    L"между текстурирана повърхнина и телен модел. Свободното въртене на камерата бавно променя посоката на "
    L"погледа в трите измерения. Спирания и обръщания на посоката добавя случайни забавяния, паузи и "
    L"обръщания на въртенето; полетът напред продължава. Скоростта е 0–1600%. Всеки монитор има независима "
    L"случайна сцена, изобразявана с неговата честота на опресняване.\r\n\r\nИзберете един или повече "
    L"редове в списъка с монитори. Ctrl+A избира всички; Ctrl и Shift променят избора. Контролите и "
    L"плъзгачите на анимацията променят само настройките на избраните монитори. Избирането на ред и "
    L"включването на изхода чрез отметката му са различни действия. Изборът се запомня отделно за "
    L"приложението и скрийнсейвъра. Ако са били избрани всички монитори, включват се и "
    L"новосвързаните.\r\n\r\nИзползвайте FlightCorridor.scr като скрийнсейвър на Windows с отделни "
    L"настройки. Прегледът на цял екран позволява промени в реално време. OK запазва промените; Отказ или "
    L"Esc ги отхвърля. Излезте от скрийнсейвъра с клавиш или движение на мишката.\r\n\r\nWindows 7–11 "
    L"поддържа всички функции. За Windows Vista SP2 трябва да се инсталират актуализациите KB971512 и "
    L"KB2117917; записът на MP4 не работи във Vista. Изисква се поддръжка на Direct3D 11, а за MP4 също "
    L"Media Foundation и H.264 кодер. Интерфейсът и документацията са налични на 36 езика.",
    L"Хардверски забрзан лет меѓу променливи површини. Лет меѓу четири променливи површини; Лет низ "
    L"променлива инка. За секој монитор изберете точно една анимација. Текстура менува текстурирана "
    L"површина и жичен модел. Слободното вртење на камерата полека го менува погледот во сите три димензии. "
    L"Запирања и промени на насоката додава случајни забавувања, паузи и промени на насоката на вртење; "
    L"летот напред продолжува. Брзината е 0–1600%. Секој монитор има независна случајна сцена што се "
    L"прикажува со неговата стапка на освежување.\r\n\r\nИзберете еден или повеќе редови во списокот на "
    L"монитори. Ctrl+A ги избира сите; Ctrl и Shift го менуваат изборот. Контролите и лизгачите на "
    L"анимацијата ги менуваат само поставките на избраните монитори. Избирањето ред и вклучувањето на "
    L"излезот преку неговото поле се различни дејства. Изборот се памети одделно за апликацијата и чуварот. "
    L"Ако биле избрани сите монитори, се вклучуваат и новоповрзаните монитори.\r\n\r\nКористете "
    L"FlightCorridor.scr како Windows чувар на екранот со одделни поставки. Прегледот на цел екран "
    L"овозможува измени во живо. OK ги зачувува, а Откажи или Esc ги отфрла измените. Излезете од чуварот "
    L"со копче или движење на глувчето.\r\n\r\nWindows 7–11 ги поддржува сите функции. За Windows Vista SP2 "
    L"мора да се инсталираат ажурирањата KB971512 и KB2117917; MP4 снимањето на Vista не работи. Потребна е "
    L"поддршка за Direct3D 11, а за MP4 и Media Foundation и H.264 кодер. Интерфејсот и документацијата се "
    L"достапни на 36 јазици.",
    L"Хардверски убрзан лет између променљивих површи. Лет између четири променљиве површи; Лет кроз "
    L"променљиви левак. За сваки монитор изаберите тачно једну анимацију. Текстура мења приказ између "
    L"текстурисане површи и жичаног модела. Слободно окретање камере полако мења смер погледа у све три "
    L"димензије. Заустављања и промене смера додају насумично успоравање, паузе и промене смера ротације; "
    L"лет напред се наставља. Брзина је 0–1600%. Сваки монитор има независну насумичну сцену која се "
    L"приказује према његовој учестаности освежавања.\r\n\r\nИзаберите један или више редова у листи "
    L"монитора. Ctrl+A бира све; Ctrl и Shift мењају избор. Контроле и клизачи анимације мењају само "
    L"подешавања изабраних монитора. Избор реда није исто што и укључивање излаза његовим пољем за потврду. "
    L"Избор се памти одвојено за апликацију и чувар екрана. Ако су претходно били изабрани сви монитори, "
    L"укључују се и новоприкључени монитори.\r\n\r\nКористите FlightCorridor.scr као Windows чувар екрана "
    L"са одвојеним подешавањима. Преглед преко целог екрана омогућава измене уживо. OK чува, а Откажи или "
    L"Esc одбацује измене. Из чувара изађите притиском тастера или померањем миша.\r\n\r\nWindows 7–11 "
    L"подржава све функције. За Windows Vista SP2 морате инсталирати ажурирања KB971512 и KB2117917; MP4 "
    L"снимање на Висти не ради. Потребан је Direct3D 11, а за MP4 и Media Foundation и H.264 кодер. "
    L"Интерфејс и документација доступни су на 36 језика.",
    L"Апаратно прискорений політ між мінливими поверхнями. Політ між чотирма мінливими поверхнями; Політ "
    L"крізь мінливу лійку. Для кожного монітора виберіть рівно одну анімацію. Текстура перемикає "
    L"текстуровану поверхню та каркасну модель. Вільне обертання камери повільно змінює напрямок погляду в "
    L"усіх трьох вимірах. Зупинки та зміни напрямку додають випадкові уповільнення, паузи та зміни напрямку "
    L"обертання; політ уперед триває. Швидкість — 0–1600%. Кожен монітор має незалежну випадкову сцену з "
    L"виведенням відповідно до власної частоти оновлення.\r\n\r\nВиберіть один або кілька рядків у списку "
    L"моніторів. Ctrl+A вибирає всі; Ctrl і Shift змінюють вибір. Елементи керування й повзунки анімації "
    L"змінюють лише налаштування вибраних моніторів. Вибір рядка та ввімкнення виведення його прапорцем — "
    L"різні дії. Вибір зберігається окремо для програми й заставки. Якщо раніше були вибрані всі монітори, "
    L"до вибору долучаються й новопідключені.\r\n\r\nВикористовуйте FlightCorridor.scr як заставку Windows "
    L"з окремими налаштуваннями. Повноекранний попередній перегляд дозволяє змінювати їх під час анімації. "
    L"OK зберігає зміни, Скасувати або Esc відхиляє їх. Для виходу із заставки натисніть клавішу або "
    L"порухайте мишею.\r\n\r\nWindows 7–11 підтримує всі функції. Для Windows Vista SP2 потрібно встановити "
    L"оновлення KB971512 і KB2117917; запис MP4 у Vista не працює. Потрібна підтримка Direct3D 11, а для "
    L"MP4 також Media Foundation й кодувальник H.264. Інтерфейс і документація доступні 36 мовами.",
    L"Аппаратно ускоренный полёт между меняющимися поверхностями. Полёт между четырьмя меняющимися "
    L"поверхностями; Полёт сквозь меняющуюся воронку. Для каждого монитора выберите ровно одну анимацию. "
    L"Текстура переключает текстурированную поверхность и каркасную модель. Свободное вращение камеры "
    L"медленно меняет направление взгляда во всех трёх измерениях. Остановки и смены направления добавляют "
    L"случайные замедления, паузы и изменения направления вращения; полёт вперёд продолжается. Скорость — "
    L"0–1600%. Каждый монитор имеет независимую случайную сцену с выводом согласно собственной частоте "
    L"обновления.\r\n\r\nВыберите одну или несколько строк в списке мониторов. Ctrl+A выбирает все; Ctrl и "
    L"Shift изменяют выбор. Элементы управления и ползунки анимации изменяют только настройки выбранных "
    L"мониторов. Выбор строки и включение вывода её флажком — разные действия. Выбор сохраняется отдельно "
    L"для приложения и заставки. Если раньше были выбраны все мониторы, в выбор включаются и вновь "
    L"подключённые.\r\n\r\nИспользуйте FlightCorridor.scr как заставку Windows с отдельными настройками. "
    L"Полноэкранный предпросмотр позволяет изменять их во время анимации. OK сохраняет изменения, Отмена "
    L"или Esc отклоняет их. Для выхода из заставки нажмите клавишу или подвигайте мышью.\r\n\r\nWindows "
    L"7–11 поддерживает все функции. Для Windows Vista SP2 необходимо установить обновления KB971512 и "
    L"KB2117917; запись MP4 в Vista не работает. Нужна поддержка Direct3D 11, а для MP4 также Media "
    L"Foundation и кодировщик H.264. Интерфейс и документация доступны на 36 языках."
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
    L"Duraklamalar ve yön değişimleri",
    L"Peatumised ja suunavahetused",
    L"Stadanna agus aisiompuithe",
    L"Sustojimai ir krypties keitimai",
    L"Apstāšanās un virziena maiņa",
    L"Megállások és irányváltások",
    L"Waqfiet u bidliet fid-direzzjoni",
    L"Stops en richtingswisselingen",
    L"Opriri și inversări de sens",
    L"Στάσεις και αντιστροφές",
    L"Zaustavljanja i promjene smjera",
    L"Zaustavljanja i promjene smjera",
    L"Ustavljanja in spremembe smeri",
    L"Zaustavljanja i promjene smjera",
    L"Спыненні і змены напрамку",
    L"Спирания и обръщания на посоката",
    L"Запирања и промени на насоката",
    L"Заустављања и промене смера",
    L"Зупинки та зміни напрямку",
    L"Остановки и смены направления"
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
