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
 * Last modified for version 1.0.0.0
 */

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "Localization.h"
#include <windows.h>

using SolidTextArray = std::array<const wchar_t*, SOLID_COUNT>;

/// Mathematical solid names
constexpr SolidTextArray CZECH_SOLIDS = {
    L"Krychle",
    L"Pravidelný čtyřboký jehlan",
    L"Komolý čtyřboký jehlan",
    L"Čtyřboký jehlan se šikmým řezem",
    L"Čtyřboký jehlan s řezem kolmým k podstavě",
    L"Pravidelný trojboký hranol",
    L"Pravidelný pětiboký hranol",
    L"Pravidelný šestiboký hranol",
    L"Pravidelný osmistěn",
    L"Pětiboký dvojjehlan",
    L"Rotační kužel",
    L"Komolý rotační kužel",
    L"Rotační kužel se šikmým řezem",
    L"Rotační kužel s řezem kolmým k podstavě",
    L"Rotační válec",
    L"Dutý rotační válec",
    L"Rotační paraboloid uzavřený rovinou",
    L"Koule",
    L"Polokoule",
    L"Kulová úseč",
    L"Velká kulová úseč",
    L"Kulová vrstva",
    L"Trojosý elipsoid",
    L"Zploštělý rotační elipsoid",
    L"Ovoid",
    L"Kapsle (sferocylindr)",
    L"Anuloid (torus)"
};

constexpr SolidTextArray ENGLISH_US_SOLIDS = {
    L"Cube",
    L"Regular square pyramid",
    L"Square pyramidal frustum",
    L"Obliquely truncated square pyramid",
    L"Square pyramid cut perpendicular to base",
    L"Regular triangular prism",
    L"Regular pentagonal prism",
    L"Regular hexagonal prism",
    L"Regular octahedron",
    L"Pentagonal bipyramid",
    L"Right circular cone",
    L"Conical frustum",
    L"Obliquely truncated cone",
    L"Cone cut perpendicular to base",
    L"Right circular cylinder",
    L"Hollow right circular cylinder",
    L"Paraboloid of revolution closed by a plane",
    L"Sphere",
    L"Hemisphere",
    L"Spherical cap",
    L"Major spherical cap",
    L"Spherical segment (two bases)",
    L"Triaxial ellipsoid",
    L"Oblate spheroid",
    L"Ovoid",
    L"Spherocylinder",
    L"Torus"
};

constexpr SolidTextArray ENGLISH_UK_SOLIDS = ENGLISH_US_SOLIDS;
constexpr SolidTextArray ENGLISH_AU_SOLIDS = ENGLISH_US_SOLIDS;
constexpr SolidTextArray GERMAN_SOLIDS = {
    L"Würfel",
    L"Regelmäßige quadratische Pyramide",
    L"Quadratischer Pyramidenstumpf",
    L"Schräg abgeschnittene Quadratpyramide",
    L"Quadratpyramide, basissenkrechter Schnitt",
    L"Regelmäßiges Dreiecksprisma",
    L"Regelmäßiges Fünfeckprisma",
    L"Regelmäßiges Sechseckprisma",
    L"Regelmäßiges Oktaeder",
    L"Fünfeck-Doppelpyramide",
    L"Gerader Kreiskegel",
    L"Kegelstumpf",
    L"Schräg abgeschnittener Kreiskegel",
    L"Kreiskegel, Schnitt senkrecht zur Basis",
    L"Gerader Kreiszylinder",
    L"Hohlzylinder",
    L"Geschlossener Rotationsparaboloid",
    L"Kugel",
    L"Halbkugel",
    L"Kugelabschnitt",
    L"Großer Kugelabschnitt",
    L"Kugelschicht",
    L"Dreiachsiges Ellipsoid",
    L"Abgeplattetes Rotationsellipsoid",
    L"Ovoid",
    L"Sphärozylinder",
    L"Torus"
};

constexpr SolidTextArray FRENCH_SOLIDS = {
    L"Cube",
    L"Pyramide régulière à base carrée",
    L"Tronc de pyramide carrée",
    L"Pyramide carrée tronquée par plan oblique",
    L"Pyramide carrée, coupe normale à la base",
    L"Prisme droit à base triangulaire régulière",
    L"Prisme droit à base pentagonale régulière",
    L"Prisme droit à base hexagonale régulière",
    L"Octaèdre régulier",
    L"Bipyramide pentagonale",
    L"Cône de révolution",
    L"Tronc de cône",
    L"Cône tronqué par un plan oblique",
    L"Cône coupé perpendiculairement à la base",
    L"Cylindre de révolution",
    L"Cylindre creux",
    L"Paraboloïde de révolution fermé par un plan",
    L"Boule",
    L"Demi-boule",
    L"Segment sphérique",
    L"Grand segment sphérique",
    L"Segment sphérique à deux bases",
    L"Ellipsoïde triaxial",
    L"Sphéroïde aplati",
    L"Ovoïde",
    L"Sphérocylindre",
    L"Tore"
};

constexpr SolidTextArray SPANISH_SOLIDS = {
    L"Cubo",
    L"Pirámide cuadrangular regular",
    L"Tronco de pirámide cuadrangular",
    L"Pirámide cuadrangular, corte oblicuo",
    L"Pirámide cuadrada, corte normal a la base",
    L"Prisma triangular regular",
    L"Prisma pentagonal regular",
    L"Prisma hexagonal regular",
    L"Octaedro regular",
    L"Bipirámide pentagonal",
    L"Cono circular recto",
    L"Tronco de cono",
    L"Cono truncado por un plano oblicuo",
    L"Cono, corte perpendicular a la base",
    L"Cilindro circular recto",
    L"Cilindro hueco",
    L"Paraboloide de revolución cerrado por plano",
    L"Esfera",
    L"Hemisferio",
    L"Segmento esférico",
    L"Segmento esférico mayor",
    L"Segmento esférico de dos bases",
    L"Elipsoide triaxial",
    L"Esferoide oblato",
    L"Ovoide",
    L"Esferocilindro",
    L"Toro"
};

constexpr SolidTextArray ITALIAN_SOLIDS = {
    L"Cubo",
    L"Piramide regolare a base quadrata",
    L"Tronco di piramide quadrata",
    L"Piramide quadrata troncata in obliquo",
    L"Piramide quadrata, taglio normale alla base",
    L"Prisma retto a base triangolare regolare",
    L"Prisma retto a base pentagonale regolare",
    L"Prisma retto a base esagonale regolare",
    L"Ottaedro regolare",
    L"Bipiramide pentagonale",
    L"Cono circolare retto",
    L"Tronco di cono",
    L"Cono troncato da un piano obliquo",
    L"Cono tagliato perpendicolarmente alla base",
    L"Cilindro circolare retto",
    L"Cilindro cavo",
    L"Paraboloide di rotazione chiuso da un piano",
    L"Sfera",
    L"Emisfero",
    L"Segmento sferico a una base",
    L"Segmento sferico maggiore",
    L"Segmento sferico a due basi",
    L"Ellissoide triassiale",
    L"Sferoide oblato",
    L"Ovoide",
    L"Sferocilindro",
    L"Toro"
};

constexpr SolidTextArray POLISH_SOLIDS = {
    L"Sześcian",
    L"Ostrosłup prawidłowy czworokątny",
    L"Ostrosłup ścięty prawidłowy czworokątny",
    L"Ostrosłup czworokątny, cięcie ukośne",
    L"Ostrosłup, cięcie prostopadłe do podstawy",
    L"Graniastosłup prawidłowy trójkątny",
    L"Graniastosłup prawidłowy pięciokątny",
    L"Graniastosłup prawidłowy sześciokątny",
    L"Ośmiościan foremny",
    L"Dwupiramida pięciokątna",
    L"Stożek obrotowy",
    L"Stożek ścięty",
    L"Stożek ścięty płaszczyzną ukośną",
    L"Stożek, cięcie prostopadłe do podstawy",
    L"Walec obrotowy",
    L"Walec pusty",
    L"Paraboloida obrotowa zamknięta płaszczyzną",
    L"Kula",
    L"Półkula",
    L"Odcinek kuli",
    L"Duży odcinek kuli",
    L"Warstwa kulista",
    L"Elipsoida trójosiowa",
    L"Sferoida spłaszczona",
    L"Owoida",
    L"Sferocylinder",
    L"Torus"
};

constexpr SolidTextArray SLOVAK_SOLIDS = {
    L"Kocka",
    L"Pravidelný štvorboký ihlan",
    L"Komolý štvorboký ihlan",
    L"Štvorboký ihlan so šikmým rezom",
    L"Štvorboký ihlan, rez kolmý na podstavu",
    L"Pravidelný trojboký hranol",
    L"Pravidelný päťboký hranol",
    L"Pravidelný šesťboký hranol",
    L"Pravidelný osemsten",
    L"Päťboký dvojihlan",
    L"Rotačný kužeľ",
    L"Komolý rotačný kužeľ",
    L"Rotačný kužeľ so šikmým rezom",
    L"Rotačný kužeľ s rezom kolmým na podstavu",
    L"Rotačný valec",
    L"Dutý rotačný valec",
    L"Rotačný paraboloid uzavretý rovinou",
    L"Guľa",
    L"Pologuľa",
    L"Guľový odsek",
    L"Veľký guľový odsek",
    L"Guľová vrstva",
    L"Trojosový elipsoid",
    L"Sploštený rotačný elipsoid",
    L"Ovoid",
    L"Sferocylinder",
    L"Anuloid (torus)"
};

constexpr SolidTextArray PORTUGUESE_SOLIDS = {
    L"Cubo",
    L"Pirâmide quadrangular regular",
    L"Tronco de pirâmide quadrangular",
    L"Pirâmide quadrangular, corte oblíquo",
    L"Pirâmide quadrada, corte normal à base",
    L"Prisma triangular regular",
    L"Prisma pentagonal regular",
    L"Prisma hexagonal regular",
    L"Octaedro regular",
    L"Bipirâmide pentagonal",
    L"Cone circular reto",
    L"Tronco de cone",
    L"Cone truncado por um plano oblíquo",
    L"Cone, corte perpendicular à base",
    L"Cilindro circular reto",
    L"Cilindro oco",
    L"Paraboloide de revolução fechado por plano",
    L"Esfera",
    L"Hemisfério",
    L"Segmento esférico",
    L"Segmento esférico maior",
    L"Segmento esférico de duas bases",
    L"Elipsoide triaxial",
    L"Esferoide oblato",
    L"Ovoide",
    L"Esferocilindro",
    L"Toro"
};

constexpr SolidTextArray NORWEGIAN_SOLIDS = {
    L"Kube",
    L"Regelmessig firkantet pyramide",
    L"Avkortet firkantet pyramide",
    L"Firkantet pyramide skåret med skråplan",
    L"Firkantpyramide, snitt normalt på basen",
    L"Regelmessig trekantprisme",
    L"Regelmessig femkantprisme",
    L"Regelmessig sekskantprisme",
    L"Regelmessig oktaeder",
    L"Femkantet bipyramide",
    L"Rett sirkelkjegle",
    L"Avkortet kjegle",
    L"Kjegle skåret med skråplan",
    L"Kjegle med snitt normalt på grunnflaten",
    L"Rett sirkelsylinder",
    L"Hul sylinder",
    L"Rotasjonsparaboloide lukket av et plan",
    L"Kule",
    L"Halvkule",
    L"Kulesegment",
    L"Stort kulesegment",
    L"Kulelag",
    L"Treakset ellipsoide",
    L"Flattrykt sfæroide",
    L"Ovoide",
    L"Sfærosylinder",
    L"Torus"
};

constexpr SolidTextArray SWEDISH_SOLIDS = {
    L"Kub",
    L"Regelbunden fyrsidig pyramid",
    L"Stympad fyrsidig pyramid",
    L"Fyrsidig pyramid skuren med ett snett plan",
    L"Fyrsidig pyramid, snitt vinkelrätt mot basen",
    L"Regelbundet triangelprisma",
    L"Regelbundet femkantsprisma",
    L"Regelbundet sexkantsprisma",
    L"Regelbunden oktaeder",
    L"Femkantig bipyramid",
    L"Rät cirkulär kon",
    L"Stympad kon",
    L"Kon skuren med ett snett plan",
    L"Kon med snitt vinkelrätt mot basen",
    L"Rät cirkulär cylinder",
    L"Ihålig cylinder",
    L"Rotationsparaboloid sluten av ett plan",
    L"Klot",
    L"Halvklot",
    L"Klotsegment",
    L"Stort klotsegment",
    L"Klotsegment med två baser",
    L"Treaxlig ellipsoid",
    L"Oblat sfäroid",
    L"Ovoid",
    L"Sfärocylinder",
    L"Torus"
};

constexpr SolidTextArray FINNISH_SOLIDS = {
    L"Kuutio",
    L"Säännöllinen neliöpyramidi",
    L"Katkaistu neliöpyramidi",
    L"Neliöpyramidi, vino leikkaus",
    L"Pyramidi, leikkaus kohtisuoraan pohjaan",
    L"Säännöllinen kolmioprisma",
    L"Säännöllinen viisikulmainen prisma",
    L"Säännöllinen kuusikulmainen prisma",
    L"Säännöllinen oktaedri",
    L"Viisikulmainen kaksoispyramidi",
    L"Suora ympyräkartio",
    L"Katkaistu kartio",
    L"Kartio vinolla tasolla leikattuna",
    L"Kartio, pohjaan nähden kohtisuora leikkaus",
    L"Suora ympyrälieriö",
    L"Ontto lieriö",
    L"Tasolla suljettu pyörähdysparaboloidi",
    L"Pallo",
    L"Puolipallo",
    L"Pallosegmentti",
    L"Suuri pallosegmentti",
    L"Katkaistu pallosegmentti",
    L"Kolmiakselinen ellipsoidi",
    L"Litteä sferoidi",
    L"Ovoidi",
    L"Sferosylinteri",
    L"Torus"
};

constexpr SolidTextArray DANISH_SOLIDS = {
    L"Terning",
    L"Regulær firsidet pyramide",
    L"Afkortet firsidet pyramide",
    L"Firsidet pyramide skåret med et skråt plan",
    L"Firkantpyramide, snit vinkelret på basen",
    L"Regulært trekantet prisme",
    L"Regulært femkantet prisme",
    L"Regulært sekskantet prisme",
    L"Regulært oktaeder",
    L"Femkantet bipyramide",
    L"Ret cirkulær kegle",
    L"Afkortet kegle",
    L"Kegle skåret med et skråt plan",
    L"Kegle med snit vinkelret på grundfladen",
    L"Ret cirkulær cylinder",
    L"Hul cylinder",
    L"Rotationsparaboloide lukket af et plan",
    L"Kugle",
    L"Halvkugle",
    L"Kuglesegment",
    L"Stort kuglesegment",
    L"Kuglelag",
    L"Treakset ellipsoide",
    L"Fladtrykt sfæroide",
    L"Ovoide",
    L"Sfærocylinder",
    L"Torus"
};

constexpr SolidTextArray ICELANDIC_SOLIDS = {
    L"Teningur",
    L"Reglulegur ferstrendur pýramídi",
    L"Stýfður ferstrendur pýramídi",
    L"Ferstrendur pýramídi skorinn með skáplani",
    L"Pýramídi, skurðplan hornrétt á grunnflöt",
    L"Reglulegur þrístrendingur",
    L"Reglulegur fimmstrendingur",
    L"Reglulegur sexstrendingur",
    L"Reglulegur áttflötungur",
    L"Fimmhyrndur tvípýramídi",
    L"Rétt hringkeila",
    L"Stýfð keila",
    L"Keila skorin með skáplani",
    L"Keila, skurður hornréttur á grunnflöt",
    L"Réttur hringsívalningur",
    L"Holur sívalningur",
    L"Lokaður snúningsfleygbogaflötur",
    L"Kúla",
    L"Hálfkúla",
    L"Kúluhluti",
    L"Stór kúluhluti",
    L"Kúlulag",
    L"Þríása sporvala",
    L"Flöt snúningssporvala",
    L"Egglaga rúmhlutur",
    L"Kúluhylki",
    L"Tórus"
};

constexpr SolidTextArray TURKISH_SOLIDS = {
    L"Küp",
    L"Düzgün kare piramit",
    L"Kesik kare piramit",
    L"Eğik düzlemle kesilmiş kare piramit",
    L"Tabana dik düzlemle kesilmiş kare piramit",
    L"Düzgün üçgen prizma",
    L"Düzgün beşgen prizma",
    L"Düzgün altıgen prizma",
    L"Düzgün oktahedron",
    L"Beşgen çift piramit",
    L"Dik dairesel koni",
    L"Kesik koni",
    L"Eğik düzlemle kesilmiş koni",
    L"Tabana dik düzlemle kesilmiş koni",
    L"Dik dairesel silindir",
    L"İçi boş silindir",
    L"Düzlemle kapatılmış dönel paraboloit",
    L"Küre",
    L"Yarım küre",
    L"Küre parçası",
    L"Büyük küre parçası",
    L"Küre tabakası",
    L"Üç eksenli elipsoit",
    L"Basık sferoit",
    L"Ovoit",
    L"Sferosilindir",
    L"Torus"
};

/// Core settings-window text records
const std::array<LocalizedText, LANGUAGE_COUNT> TEXTS = {
    LocalizedText{
        L"Čeština",
        L"FlyingSolids — ovládání",
        L"Nastavení FlyingSolids",
        L"Jazyk:",
        L"Rychlost objektů: %d %%",
        L"Rychlost kamery: %d %%",
        L"Pozorování prostoru",
        L"Průlet prostorem",
        L"Hlavní světlo",
        L"Doplňkové světlo",
        L"Plné prostorové objekty",
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
        CZECH_SOLIDS
    }, LocalizedText{
        L"English (US)",
        L"FlyingSolids — Controls",
        L"FlyingSolids Settings",
        L"Language:",
        L"Object speed: %d %%",
        L"Camera speed: %d %%",
        L"Space observation",
        L"Fly through space",
        L"Main light",
        L"Fill light",
        L"Solid 3D objects",
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
        ENGLISH_US_SOLIDS
    }, LocalizedText{
        L"Deutsch",
        L"FlyingSolids — Steuerung",
        L"FlyingSolids-Einstellungen",
        L"Sprache:",
        L"Objektgeschwindigkeit: %d %%",
        L"Kamerageschwindigkeit: %d %%",
        L"Raumbeobachtung",
        L"Flug durch den Raum",
        L"Hauptlicht",
        L"Aufhelllicht",
        L"Volumenkörper",
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
        GERMAN_SOLIDS
    }, LocalizedText{
        L"Français",
        L"FlyingSolids — Commandes",
        L"Paramètres de FlyingSolids",
        L"Langue :",
        L"Vitesse des objets : %d %%",
        L"Vitesse de la caméra : %d %%",
        L"Observation de l’espace",
        L"Vol dans l’espace",
        L"Éclairage principal",
        L"Éclairage d’appoint",
        L"Objets 3D pleins",
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
        FRENCH_SOLIDS
    }, LocalizedText{
        L"Español",
        L"FlyingSolids — Control",
        L"Configuración de FlyingSolids",
        L"Idioma:",
        L"Velocidad de objetos: %d %%",
        L"Velocidad de cámara: %d %%",
        L"Observación del espacio",
        L"Vuelo por el espacio",
        L"Luz principal",
        L"Luz de relleno",
        L"Objetos 3D sólidos",
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
        SPANISH_SOLIDS
    }, LocalizedText{
        L"Italiano",
        L"FlyingSolids — Controlli",
        L"Impostazioni di FlyingSolids",
        L"Lingua:",
        L"Velocità oggetti: %d %%",
        L"Velocità della camera: %d %%",
        L"Osservazione dello spazio",
        L"Volo nello spazio",
        L"Luce principale",
        L"Luce di riempimento",
        L"Oggetti 3D solidi",
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
        ITALIAN_SOLIDS
    }, LocalizedText{
        L"Polski",
        L"FlyingSolids — Sterowanie",
        L"Ustawienia FlyingSolids",
        L"Język:",
        L"Prędkość obiektów: %d %%",
        L"Prędkość kamery: %d %%",
        L"Obserwacja przestrzeni",
        L"Przelot przez przestrzeń",
        L"Światło główne",
        L"Światło wypełniające",
        L"Pełne obiekty 3D",
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
        POLISH_SOLIDS
    }, LocalizedText{
        L"Slovenčina",
        L"FlyingSolids — Ovládanie",
        L"Nastavenia FlyingSolids",
        L"Jazyk:",
        L"Rýchlosť objektov: %d %%",
        L"Rýchlosť kamery: %d %%",
        L"Pozorovanie priestoru",
        L"Prelet priestorom",
        L"Hlavné svetlo",
        L"Doplnkové svetlo",
        L"Plné priestorové objekty",
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
        SLOVAK_SOLIDS
    }, LocalizedText{
        L"English (UK)",
        L"FlyingSolids — Controls",
        L"FlyingSolids Settings",
        L"Language:",
        L"Object speed: %d %%",
        L"Camera speed: %d %%",
        L"Space observation",
        L"Fly through space",
        L"Main light",
        L"Fill light",
        L"Solid 3D objects",
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
        ENGLISH_UK_SOLIDS
    }, LocalizedText{
        L"English (Australia)",
        L"FlyingSolids — Controls",
        L"FlyingSolids Settings",
        L"Language:",
        L"Object speed: %d %%",
        L"Camera speed: %d %%",
        L"Space observation",
        L"Fly through space",
        L"Main light",
        L"Fill light",
        L"Solid 3D objects",
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
        ENGLISH_AU_SOLIDS
    }, LocalizedText{
        L"Português",
        L"FlyingSolids — Controlo",
        L"Definições do FlyingSolids",
        L"Idioma:",
        L"Velocidade dos objetos: %d %%",
        L"Velocidade da câmara: %d %%",
        L"Observação do espaço",
        L"Voo pelo espaço",
        L"Luz principal",
        L"Luz de preenchimento",
        L"Objetos 3D sólidos",
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
        PORTUGUESE_SOLIDS
    }, LocalizedText{
        L"Norsk",
        L"FlyingSolids — Kontroll",
        L"Innstillinger for FlyingSolids",
        L"Språk:",
        L"Objekthastighet: %d %%",
        L"Kamerahastighet: %d %%",
        L"Romobservasjon",
        L"Flyging gjennom rommet",
        L"Hovedlys",
        L"Utfyllingslys",
        L"Solide 3D-objekter",
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
        NORWEGIAN_SOLIDS
    }, LocalizedText{
        L"Svenska",
        L"FlyingSolids — Styrning",
        L"Inställningar för FlyingSolids",
        L"Språk:",
        L"Objekthastighet: %d %%",
        L"Kamerahastighet: %d %%",
        L"Rymdobservation",
        L"Flygning genom rymden",
        L"Huvudljus",
        L"Upplättningsljus",
        L"Solida 3D-objekt",
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
        SWEDISH_SOLIDS
    }, LocalizedText{
        L"Suomi",
        L"FlyingSolids — Ohjaus",
        L"FlyingSolids-asetukset",
        L"Kieli:",
        L"Kohteiden nopeus: %d %%",
        L"Kameran nopeus: %d %%",
        L"Avaruuden tarkkailu",
        L"Lento avaruuden halki",
        L"Päävalo",
        L"Täytevalo",
        L"Kiinteät 3D-kohteet",
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
        FINNISH_SOLIDS
    }, LocalizedText{
        L"Dansk",
        L"FlyingSolids — Styring",
        L"Indstillinger for FlyingSolids",
        L"Sprog:",
        L"Objekthastighed: %d %%",
        L"Kamerahastighed: %d %%",
        L"Rumobservation",
        L"Flyvning gennem rummet",
        L"Hovedlys",
        L"Udfyldningslys",
        L"Solide 3D-objekter",
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
        DANISH_SOLIDS
    }, LocalizedText{
        L"Íslenska",
        L"FlyingSolids — Stjórnun",
        L"Stillingar FlyingSolids",
        L"Tungumál:",
        L"Hraði hluta: %d %%",
        L"Hraði myndavélar: %d %%",
        L"Athugun rýmis",
        L"Flug um rýmið",
        L"Aðalljós",
        L"Fylliljós",
        L"Heilir þrívíddarhlutir",
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
        ICELANDIC_SOLIDS
    }, LocalizedText{
        L"Türkçe",
        L"FlyingSolids — Denetim",
        L"FlyingSolids Ayarları",
        L"Dil:",
        L"Nesne hızı: %%%d",
        L"Kamera hızı: %%%d",
        L"Uzayı gözlemleme",
        L"Uzayda uçuş",
        L"Ana ışık",
        L"Dolgu ışığı",
        L"Katı 3B nesneler",
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
        TURKISH_SOLIDS
    }
};

/// Language selector order
constexpr std::array<AppLanguage, LANGUAGE_COUNT> DISPLAY_ORDER = {
    AppLanguage::Czech,
    AppLanguage::EnglishUs,
    AppLanguage::EnglishUk,
    AppLanguage::EnglishAu,
    AppLanguage::German,
    AppLanguage::French,
    AppLanguage::Spanish,
    AppLanguage::Italian,
    AppLanguage::Portuguese,
    AppLanguage::Polish,
    AppLanguage::Slovak,
    AppLanguage::Danish,
    AppLanguage::Finnish,
    AppLanguage::Icelandic,
    AppLanguage::Norwegian,
    AppLanguage::Swedish,
    AppLanguage::Turkish
};

/// Supplementary settings-window text
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> COPY_COUNT_TEXTS = {
    L"Počet kopií každého objektu: %d",
    L"Copies of each object: %d",
    L"Kopien je Objekt: %d",
    L"Copies de chaque objet : %d",
    L"Copias de cada objeto: %d",
    L"Copie di ogni oggetto: %d",
    L"Liczba kopii każdego obiektu: %d",
    L"Počet kópií každého objektu: %d",
    L"Copies of each object: %d",
    L"Copies of each object: %d",
    L"Cópias de cada objeto: %d",
    L"Kopier av hvert objekt: %d",
    L"Kopior av varje objekt: %d",
    L"Kunkin kohteen kopioita: %d",
    L"Kopier af hvert objekt: %d",
    L"Afrit af hverjum hlut: %d",
    L"Her nesnenin kopya sayısı: %d"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> OBJECT_SIZE_TEXTS = {
    L"Velikost objektů: %d %%",
    L"Object size: %d %%",
    L"Objektgröße: %d %%",
    L"Taille des objets : %d %%",
    L"Tamaño de objetos: %d %%",
    L"Dimensione oggetti: %d %%",
    L"Rozmiar obiektów: %d %%",
    L"Veľkosť objektov: %d %%",
    L"Object size: %d %%",
    L"Object size: %d %%",
    L"Tamanho dos objetos: %d %%",
    L"Objektstørrelse: %d %%",
    L"Objektstorlek: %d %%",
    L"Kohteiden koko: %d %%",
    L"Objektstørrelse: %d %%",
    L"Stærð hluta: %d %%",
    L"Nesne boyutu: %%%d"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> ENABLE_PREVIEW_TEXTS = {
    L"Zapnout náhled",
    L"Enable preview",
    L"Vorschau einschalten",
    L"Activer l’aperçu",
    L"Activar vista previa",
    L"Attiva anteprima",
    L"Włącz podgląd",
    L"Zapnúť náhľad",
    L"Enable preview",
    L"Enable preview",
    L"Ativar pré-visualização",
    L"Slå på forhåndsvisning",
    L"Aktivera förhandsvisning",
    L"Ota esikatselu käyttöön",
    L"Aktivér forhåndsvisning",
    L"Virkja forskoðun",
    L"Önizlemeyi aç"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> DISABLE_PREVIEW_TEXTS = {
    L"Vypnout náhled",
    L"Disable preview",
    L"Vorschau ausschalten",
    L"Désactiver l’aperçu",
    L"Desactivar vista previa",
    L"Disattiva anteprima",
    L"Wyłącz podgląd",
    L"Vypnúť náhľad",
    L"Disable preview",
    L"Disable preview",
    L"Desativar pré-visualização",
    L"Slå av forhåndsvisning",
    L"Inaktivera förhandsvisning",
    L"Poista esikatselu käytöstä",
    L"Deaktivér forhåndsvisning",
    L"Slökkva á forskoðun",
    L"Önizlemeyi kapat"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> READY_STATUS_TEXTS = {
    L"Připraven.",
    L"Ready.",
    L"Bereit.",
    L"Prêt.",
    L"Listo.",
    L"Pronto.",
    L"Gotowy.",
    L"Pripravený.",
    L"Ready.",
    L"Ready.",
    L"Pronto.",
    L"Klar.",
    L"Redo.",
    L"Valmis.",
    L"Klar.",
    L"Tilbúið.",
    L"Hazır."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> PAUSED_STATUS_TEXTS = {
    L"Animace je pozastavena.",
    L"Animation is paused.",
    L"Animation ist angehalten.",
    L"L’animation est en pause.",
    L"La animación está en pausa.",
    L"L’animazione è in pausa.",
    L"Animacja jest wstrzymana.",
    L"Animácia je pozastavená.",
    L"Animation is paused.",
    L"Animation is paused.",
    L"A animação está em pausa.",
    L"Animasjonen er satt på pause.",
    L"Animeringen är pausad.",
    L"Animaatio on keskeytetty.",
    L"Animationen er sat på pause.",
    L"Hlé hefur verið gert á hreyfimyndinni.",
    L"Animasyon duraklatıldı."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> HELP_BUTTON_TEXTS = {
    L"Nápověda",
    L"Help",
    L"Hilfe",
    L"Aide",
    L"Ayuda",
    L"Guida",
    L"Pomoc",
    L"Pomoc",
    L"Help",
    L"Help",
    L"Ajuda",
    L"Hjelp",
    L"Hjälp",
    L"Ohje",
    L"Hjælp",
    L"Hjálp",
    L"Yardım"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> ABOUT_BUTTON_TEXTS = {
    L"O aplikaci",
    L"About",
    L"Info",
    L"À propos",
    L"Acerca de",
    L"Informazioni",
    L"O programie",
    L"O aplikácii",
    L"About",
    L"About",
    L"Acerca de",
    L"Om",
    L"Om",
    L"Tietoja",
    L"Om",
    L"Um",
    L"Hakkında"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> ABOUT_PLATFORM_LABELS = {
    L"Cílová platforma:",
    L"Target platform:",
    L"Zielplattform:",
    L"Plateforme cible :",
    L"Plataforma de destino:",
    L"Piattaforma di destinazione:",
    L"Platforma docelowa:",
    L"Cieľová platforma:",
    L"Target platform:",
    L"Target platform:",
    L"Plataforma de destino:",
    L"Målplattform:",
    L"Målplattform:",
    L"Kohdealusta:",
    L"Målplatform:",
    L"Markvettvangur:",
    L"Hedef platform:"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> ABOUT_WEBSITE_LABELS = {
    L"Web:",
    L"Website:",
    L"Website:",
    L"Site web :",
    L"Sitio web:",
    L"Sito web:",
    L"Witryna:",
    L"Web:",
    L"Website:",
    L"Website:",
    L"Site:",
    L"Nettsted:",
    L"Webbplats:",
    L"Verkkosivusto:",
    L"Websted:",
    L"Vefsvæði:",
    L"Web sitesi:"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> OPEN_IN_BROWSER_TEXTS = {
    L"&Otevřít ve výchozím prohlížeči",
    L"&Open in default browser",
    L"Im Standardbrowser &öffnen",
    L"&Ouvrir dans le navigateur par défaut",
    L"&Abrir en el navegador predeterminado",
    L"&Apri nel browser predefinito",
    L"&Otwórz w domyślnej przeglądarce",
    L"&Otvoriť v predvolenom prehliadači",
    L"&Open in default browser",
    L"&Open in default browser",
    L"&Abrir no navegador predefinido",
    L"&Åpne i standardnettleseren",
    L"&Öppna i standardwebbläsaren",
    L"&Avaa oletusselaimessa",
    L"&Åbn i standardbrowseren",
    L"&Opna í sjálfgefnum vafra",
    L"Varsayılan tarayıcıda &aç"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> COPY_URL_TEXTS = {
    L"Kopírovat &adresu",
    L"Copy &URL",
    L"&URL kopieren",
    L"Copier l’&URL",
    L"Copiar &URL",
    L"Copia &URL",
    L"Kopiuj &adres URL",
    L"Kopírovať &adresu",
    L"Copy &URL",
    L"Copy &URL",
    L"Copiar &URL",
    L"Kopier &URL",
    L"Kopiera &URL",
    L"Kopioi &URL",
    L"Kopiér &URL",
    L"Afrita &vefslóð",
    L"&URL'yi kopyala"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> COPY_INFORMATION_TEXTS = {
    L"Kopírovat &informace",
    L"Copy &information",
    L"&Informationen kopieren",
    L"Copier les &informations",
    L"Copiar &información",
    L"Copia &informazioni",
    L"Kopiuj &informacje",
    L"Kopírovať &informácie",
    L"Copy &information",
    L"Copy &information",
    L"Copiar &informações",
    L"Kopier &informasjon",
    L"Kopiera &information",
    L"Kopioi &tiedot",
    L"Kopiér &oplysninger",
    L"Afrita &upplýsingar",
    L"&Bilgileri kopyala"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> CLOSE_BUTTON_TEXTS = {
    L"Zavřít",
    L"Close",
    L"Schließen",
    L"Fermer",
    L"Cerrar",
    L"Chiudi",
    L"Zamknij",
    L"Zavrieť",
    L"Close",
    L"Close",
    L"Fechar",
    L"Lukk",
    L"Stäng",
    L"Sulje",
    L"Luk",
    L"Loka",
    L"Kapat"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> SNAPSHOT_BUTTON_TEXTS = {
    L"Snímek…",
    L"Snapshot…",
    L"Schnappschuss…",
    L"Capture…",
    L"Captura…",
    L"Istantanea…",
    L"Zrzut…",
    L"Snímka…",
    L"Snapshot…",
    L"Snapshot…",
    L"Captura…",
    L"Skjermbilde…",
    L"Skärmbild…",
    L"Tilannekuva…",
    L"Skærmbillede…",
    L"Skjámynd…",
    L"Anlık görüntü…"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> SNAPSHOT_SAVED_TEXTS = {
    L"Snímek byl uložen.",
    L"Snapshot was saved.",
    L"Schnappschuss wurde gespeichert.",
    L"La capture a été enregistrée.",
    L"La captura se guardó.",
    L"L’istantanea è stata salvata.",
    L"Zrzut został zapisany.",
    L"Snímka bola uložená.",
    L"Snapshot was saved.",
    L"Snapshot was saved.",
    L"A captura foi guardada.",
    L"Skjermbildet ble lagret.",
    L"Skärmbilden sparades.",
    L"Tilannekuva tallennettiin.",
    L"Skærmbilledet blev gemt.",
    L"Skjámyndin var vistuð.",
    L"Anlık görüntü kaydedildi."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> SNAPSHOT_FAILED_TEXTS = {
    L"Snímek se nepodařilo uložit.",
    L"Could not save the snapshot.",
    L"Der Schnappschuss konnte nicht gespeichert werden.",
    L"Impossible d’enregistrer la capture.",
    L"No se pudo guardar la captura.",
    L"Impossibile salvare l’istantanea.",
    L"Nie udało się zapisać zrzutu.",
    L"Snímku sa nepodarilo uložiť.",
    L"Could not save the snapshot.",
    L"Could not save the snapshot.",
    L"Não foi possível guardar a captura.",
    L"Kunne ikke lagre skjermbildet.",
    L"Det gick inte att spara skärmbilden.",
    L"Tilannekuvaa ei voitu tallentaa.",
    L"Skærmbilledet kunne ikke gemmes.",
    L"Ekki tókst að vista skjámyndina.",
    L"Anlık görüntü kaydedilemedi."
};

/// Screen-saver installation text
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALL_SCREEN_SAVER_TEXTS = {
    L"Odinstalovat spořič",
    L"Uninstall screen saver",
    L"Bildschirmschoner deinstallieren",
    L"Désinstaller l’économiseur",
    L"Desinstalar salvapantallas",
    L"Disinstalla salvaschermo",
    L"Odinstaluj wygaszacz",
    L"Odinštalovať šetrič",
    L"Uninstall screen saver",
    L"Uninstall screen saver",
    L"Desinstalar proteção de ecrã",
    L"Avinstaller skjermsparer",
    L"Avinstallera skärmsläckare",
    L"Poista näytönsäästäjä",
    L"Afinstaller pauseskærm",
    L"Fjarlægja skjáhvílu",
    L"Ekran koruyucuyu kaldır"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALLATION_SUCCEEDED_TEXTS = {
    L"Spořič byl odinstalován.",
    L"The screen saver was uninstalled.",
    L"Der Bildschirmschoner wurde deinstalliert.",
    L"L’économiseur a été désinstallé.",
    L"El salvapantallas se desinstaló.",
    L"Il salvaschermo è stato disinstallato.",
    L"Wygaszacz został odinstalowany.",
    L"Šetrič bol odinštalovaný.",
    L"The screen saver was uninstalled.",
    L"The screen saver was uninstalled.",
    L"A proteção de ecrã foi desinstalada.",
    L"Skjermspareren ble avinstallert.",
    L"Skärmsläckaren avinstallerades.",
    L"Näytönsäästäjä poistettiin.",
    L"Pauseskærmen blev afinstalleret.",
    L"Skjáhvílan var fjarlægð.",
    L"Ekran koruyucu kaldırıldı."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALLATION_FAILED_TEXTS = {
    L"Odinstalace se nezdařila. Pokud je spořič nebo jeho náhled spuštěný, zavřete jej a odinstalaci zopakujte.",
    L"The screen saver could not be uninstalled. If the screen saver or its preview is running, close it and try again.",
    L"Der Bildschirmschoner konnte nicht deinstalliert werden. Falls der Bildschirmschoner oder seine Vorschau läuft, schließen Sie ihn und "
    L"versuchen Sie es erneut.",
    L"Impossible de désinstaller l’économiseur. S’il est en cours d’exécution ou si son aperçu est ouvert, fermez-le puis réessayez.",
    L"No se pudo desinstalar el salvapantallas. Si el salvapantallas o su vista previa están en ejecución, ciérrelos e inténtelo de nuevo.",
    L"Impossibile disinstallare il salvaschermo. Se il salvaschermo o la relativa anteprima sono in esecuzione, chiuderli e riprovare.",
    L"Nie udało się odinstalować wygaszacza. Jeśli wygaszacz lub jego podgląd jest uruchomiony, zamknij go i spróbuj ponownie.",
    L"Šetrič sa nepodarilo odinštalovať. Ak je šetrič alebo jeho náhľad spustený, zatvorte ho a skúste to znova.",
    L"The screen saver could not be uninstalled. If the screen saver or its preview is running, close it and try again.",
    L"The screen saver could not be uninstalled. If the screen saver or its preview is running, close it and try again.",
    L"Não foi possível desinstalar a proteção de ecrã. Se a proteção ou a pré-visualização estiver em execução, feche-a e tente novamente.",
    L"Skjermspareren kunne ikke avinstalleres. Hvis skjermspareren eller forhåndsvisningen kjører, lukk den og prøv på nytt.",
    L"Skärmsläckaren kunde inte avinstalleras. Om skärmsläckaren eller förhandsvisningen körs, stäng den och försök igen.",
    L"Näytönsäästäjän poistaminen epäonnistui. Jos näytönsäästäjä tai sen esikatselu on käynnissä, sulje se ja yritä uudelleen.",
    L"Pauseskærmen kunne ikke afinstalleres. Hvis pauseskærmen eller forhåndsvisningen kører, skal du lukke den og prøve igen.",
    L"Ekki tókst að fjarlægja skjáhvíluna. Ef skjáhvílan eða forskoðun hennar er í gangi skaltu loka henni og reyna aftur.",
    L"Ekran koruyucu kaldırılamadı. Ekran koruyucu veya önizlemesi çalışıyorsa kapatıp yeniden deneyin."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALLATION_BLOCKED_BY_SETTINGS_TEXTS = {
    L"Odinstalace se nezdařila, protože je otevřené nastavení FlyingSolids. Zavřete je a odinstalaci zopakujte.",
    L"Uninstallation failed because FlyingSolids settings are open. Close the settings window and try again.",
    L"Die Deinstallation ist fehlgeschlagen, weil die FlyingSolids-Einstellungen geöffnet sind. Schließen Sie das Fenster und versuchen Sie es "
    L"erneut.",
    L"La désinstallation a échoué car les paramètres de FlyingSolids sont ouverts. Fermez cette fenêtre puis réessayez.",
    L"La desinstalación falló porque la configuración de FlyingSolids está abierta. Cierre esa ventana e inténtelo de nuevo.",
    L"La disinstallazione non è riuscita perché le impostazioni di FlyingSolids sono aperte. Chiudere la finestra e riprovare.",
    L"Odinstalowanie nie powiodło się, ponieważ ustawienia FlyingSolids są otwarte. Zamknij okno i spróbuj ponownie.",
    L"Odinštalovanie zlyhalo, pretože sú otvorené nastavenia FlyingSolids. Zatvorte ich a skúste to znova.",
    L"Uninstallation failed because FlyingSolids settings are open. Close the settings window and try again.",
    L"Uninstallation failed because FlyingSolids settings are open. Close the settings window and try again.",
    L"A desinstalação falhou porque as definições do FlyingSolids estão abertas. Feche a janela e tente novamente.",
    L"Avinstalleringen mislyktes fordi innstillingene for FlyingSolids er åpne. Lukk vinduet og prøv på nytt.",
    L"Avinstallationen misslyckades eftersom inställningarna för FlyingSolids är öppna. Stäng fönstret och försök igen.",
    L"Asennuksen poisto epäonnistui, koska FlyingSolids-asetukset ovat avoinna. Sulje ikkuna ja yritä uudelleen.",
    L"Afinstallationen mislykkedes, fordi indstillingerne for FlyingSolids er åbne. Luk vinduet, og prøv igen.",
    L"Fjarlæging mistókst vegna þess að stillingar FlyingSolids eru opnar. Lokaðu glugganum og reyndu aftur.",
    L"FlyingSolids ayarları açık olduğu için kaldırma başarısız oldu. Ayarlar penceresini kapatıp yeniden deneyin."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW_TEXTS = {
    L"Odinstalace se nezdařila, protože běží systémový náhled. Zavřete okno Nastavení spořiče obrazovky a odinstalaci zopakujte.",
    L"Uninstallation failed because the system preview is running. Close the Screen Saver Settings window and try again.",
    L"Die Deinstallation ist fehlgeschlagen, weil die Systemvorschau läuft. Schließen Sie das Fenster Bildschirmschonereinstellungen und "
    L"versuchen Sie es erneut.",
    L"La désinstallation a échoué car l’aperçu système est actif. Fermez la fenêtre Paramètres de l’économiseur d’écran puis réessayez.",
    L"La desinstalación falló porque se está ejecutando la vista previa del sistema. Cierre Configuración del protector de pantalla e "
    L"inténtelo de nuevo.",
    L"La disinstallazione non è riuscita perché è attiva l’anteprima di sistema. Chiudere Impostazioni salvaschermo e riprovare.",
    L"Odinstalowanie nie powiodło się, ponieważ działa podgląd systemowy. Zamknij okno Ustawienia wygaszacza ekranu i spróbuj ponownie.",
    L"Odinštalovanie zlyhalo, pretože beží systémový náhľad. Zatvorte okno Nastavenie šetriča obrazovky a skúste to znova.",
    L"Uninstallation failed because the system preview is running. Close the Screen Saver Settings window and try again.",
    L"Uninstallation failed because the system preview is running. Close the Screen Saver Settings window and try again.",
    L"A desinstalação falhou porque a pré-visualização do sistema está em execução. Feche as Definições da proteção de ecrã e tente novamente.",
    L"Avinstalleringen mislyktes fordi systemforhåndsvisningen kjører. Lukk vinduet Skjermsparerinnstillinger og prøv på nytt.",
    L"Avinstallationen misslyckades eftersom systemförhandsvisningen körs. Stäng fönstret Inställningar för skärmsläckare och försök igen.",
    L"Asennuksen poisto epäonnistui, koska järjestelmän esikatselu on käynnissä. Sulje Näytönsäästäjän asetukset ja yritä uudelleen.",
    L"Afinstallationen mislykkedes, fordi systemforhåndsvisningen kører. Luk vinduet Pauseskærmsindstillinger, og prøv igen.",
    L"Fjarlæging mistókst vegna þess að kerfisforskoðun er í gangi. Lokaðu stillingaglugga skjáhvílu og reyndu aftur.",
    L"Sistem önizlemesi çalıştığı için kaldırma başarısız oldu. Ekran Koruyucu Ayarları penceresini kapatıp yeniden deneyin."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER_TEXTS = {
    L"Odinstalace se nezdařila, protože je spuštěný spořič nebo celoobrazovkový náhled. Ukončete jej klávesou Esc nebo pohybem myši a "
    L"odinstalaci zopakujte.",
    L"Uninstallation failed because the screen saver or full-screen preview is running. Exit it with Esc or by moving the mouse, then try "
    L"again.",
    L"Die Deinstallation ist fehlgeschlagen, weil der Bildschirmschoner oder die Vollbildvorschau läuft. Beenden Sie ihn mit Esc oder durch "
    L"Bewegen der Maus und versuchen Sie es erneut.",
    L"La désinstallation a échoué car l’économiseur ou l’aperçu plein écran est actif. Quittez-le avec Échap ou en déplaçant la souris, puis "
    L"réessayez.",
    L"La desinstalación falló porque está activo el salvapantallas o la vista previa a pantalla completa. Salga con Esc o moviendo el ratón e "
    L"inténtelo de nuevo.",
    L"La disinstallazione non è riuscita perché è attivo il salvaschermo o l’anteprima a schermo intero. Uscire con Esc o muovendo il mouse e "
    L"riprovare.",
    L"Odinstalowanie nie powiodło się, ponieważ działa wygaszacz lub podgląd pełnoekranowy. Zakończ go klawiszem Esc albo ruchem myszy i "
    L"spróbuj ponownie.",
    L"Odinštalovanie zlyhalo, pretože beží šetrič alebo celoobrazovkový náhľad. Ukončite ho klávesom Esc alebo pohybom myši a skúste to znova.",
    L"Uninstallation failed because the screen saver or full-screen preview is running. Exit it with Esc or by moving the mouse, then try "
    L"again.",
    L"Uninstallation failed because the screen saver or full-screen preview is running. Exit it with Esc or by moving the mouse, then try "
    L"again.",
    L"A desinstalação falhou porque a proteção ou a pré-visualização em ecrã inteiro está em execução. Saia com Esc ou movendo o rato e tente "
    L"novamente.",
    L"Avinstalleringen mislyktes fordi skjermspareren eller fullskjermvisningen kjører. Avslutt med Esc eller ved å bevege musen, og prøv på "
    L"nytt.",
    L"Avinstallationen misslyckades eftersom skärmsläckaren eller helskärmsförhandsvisningen körs. Avsluta med Esc eller genom att röra musen "
    L"och försök igen.",
    L"Asennuksen poisto epäonnistui, koska näytönsäästäjä tai koko näytön esikatselu on käynnissä. Lopeta Esc-näppäimellä tai liikuttamalla "
    L"hiirtä ja yritä uudelleen.",
    L"Afinstallationen mislykkedes, fordi pauseskærmen eller forhåndsvisningen i fuld skærm kører. Afslut med Esc eller ved at bevæge musen, "
    L"og prøv igen.",
    L"Fjarlæging mistókst vegna þess að skjáhvílan eða forskoðun á öllum skjánum er í gangi. Lokaðu með Esc eða með því að hreyfa músina og "
    L"reyndu aftur.",
    L"Ekran koruyucu veya tam ekran önizleme çalıştığı için kaldırma başarısız oldu. Esc ile ya da fareyi hareket ettirerek çıkıp yeniden "
    L"deneyin."
};

/// Help and About text
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> APPLICATION_HELP_TEXTS = {
    L"FlyingSolids zobrazuje osvětlená plná prostorová tělesa. Jezdci nastavují rychlost objektů a kamery v rozsahu 0–1600 %, jednu až deset "
    L"kopií každého tělesa a velikost 50–200 %. Vyberte Pozorování prostoru nebo přímý Průlet prostorem a zaškrtněte požadované druhy "
    L"těles.\r\n\r\nZatržítka Hlavní světlo a Doplňkové světlo pod pravými jezdci nezávisle zapínají a vypínají obě světla pro celou scénu. "
    L"Výchozí stav: Hlavní světlo zapnuté, Doplňkové světlo vypnuté. Nastavení světel se ukládá zvlášť pro aplikaci a spořič "
    L"obrazovky.\r\n\r\nV seznamu lze označit více monitorů; dvojklikem na řádek monitor zapnete nebo vypnete a lze zrušit i výběr všech "
    L"monitorů. Každý monitor používá nezávislou scénu.\r\n\r\nSnímek ukládá PNG, tlačítko záznamu spouští a ukončuje MP4. Pozastavení zastaví "
    L"animaci. Aplikace také instaluje nebo odinstaluje zabalený spořič. Nastavení se ukládá průběžně.\r\n\r\nAplikace běží pouze v jedné "
    L"instanci. Další spuštění obnoví minimalizované ovládací okno, překreslí je a přenese do popředí.\r\n\r\nMezi ovládacími prvky "
    L"přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a příslušného písmene. Esc zavře aktivní nápovědu či okno "
    L"O aplikaci; v ovládacím okně ukončí aplikaci.\r\n\r\nSnímek a záznam zachycují první aktivní animační monitor, nikoli společnou plochu "
    L"všech monitorů. PNG používá složku Obrázky, MP4 složku Videa; při jejich neexistenci se použijí Dokumenty. Záznam MP4 odpovídá "
    L"obnovovací frekvenci monitoru, nejvýše však 60 snímkům za sekundu.\r\n\r\nWindows 7 až Windows 11 podporují všechny funkce včetně snímků "
    L"PNG a záznamu MP4. Windows Vista SP2: KB971512, KB2117917. Záznam MP4 na Vistě v současné verzi nefunguje.",
    L"FlyingSolids displays illuminated solid 3D objects. The sliders set object and camera speed from 0–1600%, one to ten copies of each "
    L"object, and size from 50–200%. Choose Space observation or the straight Fly through space mode and enable the required object "
    L"types.\r\n\r\nThe Main light and Fill light checkboxes below the right-hand sliders independently enable or disable the two lights for "
    L"the entire scene. By default, Main light is on and Fill light is off. Light settings are stored separately for the application and "
    L"screen saver.\r\n\r\nSelect several displays in the list; double-click a row to toggle it, or clear the selection for all displays. "
    L"Every display uses an independent scene.\r\n\r\nSnapshot saves a PNG and the recording button starts or stops an MP4. Pause stops the "
    L"animation. The application also installs or uninstalls its embedded screen saver. Settings are saved continuously.\r\n\r\nOnly one "
    L"instance of the application runs at a time. Launching it again restores its minimized control window, redraws it, and brings it to the "
    L"foreground.\r\n\r\nUse Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a command. Esc closes "
    L"the active Help or About window; in the control window, it exits the application.\r\n\r\nSnapshots and recordings capture the first "
    L"active animation display, not a combined image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if "
    L"those folders do not exist. MP4 recording follows the display refresh rate, up to 60 frames per second.\r\n\r\nWindows 7 through Windows "
    L"11 support all features, including PNG snapshots and MP4 recording. Windows Vista SP2: KB971512, KB2117917. MP4 recording does not work "
    L"on Vista in the current version.",
    L"FlyingSolids zeigt beleuchtete dreidimensionale Volumenkörper. Die Regler bestimmen Objekt- und Kamerageschwindigkeit von 0–1600 %, ein "
    L"bis zehn Exemplare je Körper und eine Größe von 50–200 %. Wählen Sie Raumbeobachtung oder Flug durch den Raum in gerader Linie und "
    L"aktivieren Sie die gewünschten Körper.\r\n\r\nDie Kontrollkästchen Hauptlicht und Aufhelllicht unter den rechten Reglern schalten die "
    L"beiden Lichtquellen für die gesamte Szene unabhängig ein oder aus. Standardmäßig ist Hauptlicht eingeschaltet und Aufhelllicht "
    L"ausgeschaltet. Die Lichteinstellungen werden für Anwendung und Bildschirmschoner getrennt gespeichert.\r\n\r\nIn der Liste sind mehrere "
    L"Monitore wählbar; ein Doppelklick schaltet einen Monitor um, auch alle können abgewählt werden. Jeder Monitor besitzt eine unabhängige "
    L"Szene.\r\n\r\nSchnappschuss speichert PNG, die Aufnahmetaste startet oder beendet MP4. Pause hält die Animation an. Die Anwendung "
    L"installiert oder deinstalliert außerdem den eingebetteten Bildschirmschoner. Einstellungen werden laufend gespeichert.\r\n\r\nDie "
    L"Anwendung läuft nur in einer Instanz. Ein erneuter Start stellt das minimierte Steuerfenster wieder her, zeichnet es neu und bringt es "
    L"in den Vordergrund.\r\n\r\nMit Tab und Umschalt+Tab wechseln Sie zwischen den Steuerelementen; mit Alt und dem unterstrichenen "
    L"Buchstaben rufen Sie einen Befehl auf. Esc schließt das aktive Hilfe- oder Infofenster; im Steuerfenster beendet es die "
    L"Anwendung.\r\n\r\nSchnappschüsse und Aufnahmen erfassen den ersten aktiven Animationsmonitor, nicht die gemeinsame Fläche aller "
    L"Monitore. PNG verwendet Bilder, MP4 Videos; fehlen diese Ordner, wird Dokumente verwendet. MP4 folgt der Bildwiederholfrequenz des "
    L"Monitors, höchstens jedoch 60 Bildern pro Sekunde.\r\n\r\nWindows 7 bis Windows 11 unterstützen alle Funktionen einschließlich "
    L"PNG-Schnappschüssen und MP4-Aufnahmen. Windows Vista SP2: KB971512, KB2117917. MP4-Aufnahmen funktionieren unter Vista in der aktuellen "
    L"Version nicht.",
    L"FlyingSolids affiche des solides 3D éclairés. Les curseurs règlent la vitesse des objets et de la caméra de 0 à 1 600 %, une à dix "
    L"copies de chaque solide et une taille de 50 à 200 %. Choisissez Observation de l’espace ou le Vol dans l’espace rectiligne, puis activez "
    L"les solides voulus.\r\n\r\nLes cases Éclairage principal et Éclairage d’appoint sous les curseurs de droite activent ou désactivent "
    L"indépendamment les deux sources lumineuses pour toute la scène. Par défaut, Éclairage principal est activé et Éclairage d’appoint est "
    L"désactivé. Les réglages d’éclairage sont enregistrés séparément pour l’application et l’économiseur d’écran.\r\n\r\nSélectionnez "
    L"plusieurs moniteurs dans la liste ; un double-clic active ou désactive un moniteur, et vous pouvez tous les désélectionner. Chaque "
    L"moniteur utilise une scène indépendante.\r\n\r\nCapture enregistre un PNG et le bouton d’enregistrement démarre ou arrête un MP4. Pause "
    L"arrête l’animation. L’application installe ou désinstalle aussi son économiseur intégré. Les réglages sont enregistrés en "
    L"continu.\r\n\r\nUne seule instance de l’application peut fonctionner à la fois. Un nouveau lancement restaure la fenêtre de contrôle "
    L"réduite, la redessine et la place au premier plan.\r\n\r\nUtilisez Tab et Maj+Tab pour passer d’un contrôle à l’autre ; Alt et la lettre "
    L"soulignée activent une commande. Échap ferme la fenêtre d’aide ou À propos active ; dans la fenêtre de contrôle, cette touche quitte "
    L"l’application.\r\n\r\nLes captures et les enregistrements utilisent le premier moniteur d’animation actif, et non une image combinant "
    L"tous les moniteurs. PNG utilise Images, MP4 Vidéos ; Documents sert de repli si ces dossiers n’existent pas. La fréquence MP4 suit celle "
    L"du moniteur, avec un maximum de 60 images par seconde.\r\n\r\nWindows 7 à Windows 11 prennent en charge toutes les fonctions, y compris "
    L"les captures PNG et l’enregistrement MP4. Windows Vista SP2: KB971512, KB2117917. L’enregistrement MP4 ne fonctionne pas sous Vista dans "
    L"la version actuelle.",
    L"FlyingSolids muestra sólidos 3D iluminados. Los controles ajustan la velocidad de objetos y cámara entre 0 y 1600 %, de una a diez "
    L"copias y el tamaño entre 50 y 200 %. Elija Observación del espacio o el Vuelo por el espacio en línea recta y active los sólidos "
    L"deseados.\r\n\r\nLas casillas Luz principal y Luz de relleno bajo los controles deslizantes de la derecha activan o desactivan las dos "
    L"luces de forma independiente para toda la escena. De forma predeterminada, Luz principal está activada y Luz de relleno está "
    L"desactivada. Los ajustes de iluminación se guardan por separado para la aplicación y el salvapantallas.\r\n\r\nSeleccione varios "
    L"monitores en la lista; un doble clic alterna la animación en un monitor y también puede desmarcarlos todos. Cada monitor usa una escena "
    L"independiente.\r\n\r\nCaptura guarda un PNG y el botón de grabación inicia o detiene un MP4. Pausar detiene la animación. La aplicación "
    L"instala o desinstala además el salvapantallas incorporado. Los ajustes se guardan continuamente.\r\n\r\nLa aplicación solo permite una "
    L"instancia. Al volver a iniciarla, restaura la ventana de control minimizada, la redibuja y la trae al primer plano.\r\n\r\nUse Tab y "
    L"Mayús+Tab para desplazarse entre controles; Alt y la letra subrayada activan una opción. Esc cierra la ventana activa de Ayuda o Acerca "
    L"de; en la ventana de control, sale de la aplicación.\r\n\r\nLas capturas y grabaciones usan el primer monitor de animación activo, no "
    L"una imagen conjunta de todos los monitores. PNG usa Imágenes y MP4 Vídeos; si no existen esas carpetas, se usa Documentos. La grabación "
    L"MP4 sigue la frecuencia del monitor, con un máximo de 60 fotogramas por segundo.\r\n\r\nWindows 7 a Windows 11 admiten todas las "
    L"funciones, incluidas las capturas PNG y la grabación MP4. Windows Vista SP2: KB971512, KB2117917. La grabación MP4 no funciona en Vista "
    L"en la versión actual.",
    L"FlyingSolids mostra solidi 3D illuminati. I cursori regolano la velocità di oggetti e camera tra 0 e 1600 %, da una a dieci copie e la "
    L"dimensione tra 50 e 200 %. Scegliere Osservazione dello spazio o il Volo nello spazio rettilineo e attivare i solidi "
    L"desiderati.\r\n\r\nLe caselle Luce principale e Luce di riempimento sotto i cursori di destra attivano o disattivano le due luci in modo "
    L"indipendente per l’intera scena. Per impostazione predefinita, Luce principale è attiva e Luce di riempimento è disattivata. Le "
    L"impostazioni di illuminazione vengono salvate separatamente per l’applicazione e il salvaschermo.\r\n\r\nNell’elenco si possono "
    L"selezionare più monitor; un doppio clic attiva o disattiva l’animazione su un monitor, ed è possibile deselezionarli tutti. Ogni monitor "
    L"usa una scena indipendente.\r\n\r\nIstantanea salva un PNG e il pulsante di registrazione avvia o arresta un MP4. Pausa ferma "
    L"l’animazione. L’applicazione installa o disinstalla anche il salvaschermo incorporato. Le impostazioni vengono salvate "
    L"continuamente.\r\n\r\nL’applicazione può essere eseguita in una sola istanza. Un nuovo avvio ripristina la finestra di controllo ridotta "
    L"a icona, la ridisegna e la porta in primo piano.\r\n\r\nUsare Tab e Maiusc+Tab per passare tra i controlli; Alt e la lettera "
    L"sottolineata attivano un comando. Esc chiude la finestra attiva di Guida o Informazioni; nella finestra di controllo, termina "
    L"l’applicazione.\r\n\r\nIstantanee e registrazioni usano il primo monitor di animazione attivo, non un’immagine combinata di tutti i "
    L"monitor. PNG usa Immagini, MP4 Video; se tali cartelle non esistono, viene usata Documenti. La registrazione MP4 segue la frequenza del "
    L"monitor, fino a un massimo di 60 fotogrammi al secondo.\r\n\r\nI sistemi da Windows 7 a Windows 11 supportano tutte le funzioni, "
    L"comprese le istantanee PNG e la registrazione MP4. Windows Vista SP2: KB971512, KB2117917. La registrazione MP4 non funziona in Vista "
    L"nella versione attuale.",
    L"FlyingSolids wyświetla oświetlone pełne bryły 3D. Suwaki ustawiają prędkość obiektów i kamery od 0 do 1600%, od jednej do dziesięciu "
    L"kopii i rozmiar od 50 do 200%. Wybierz Obserwację przestrzeni lub prostoliniowy Przelot przez przestrzeń i włącz potrzebne "
    L"bryły.\r\n\r\nPola wyboru Światło główne i Światło wypełniające pod prawymi suwakami niezależnie włączają lub wyłączają oba światła dla "
    L"całej sceny. Domyślnie Światło główne jest włączone, a Światło wypełniające wyłączone. Ustawienia oświetlenia są zapisywane osobno dla "
    L"aplikacji i wygaszacza ekranu.\r\n\r\nNa liście można zaznaczyć wiele monitorów; podwójne kliknięcie przełącza animację na monitorze, "
    L"można też odznaczyć wszystkie. Każdy monitor ma niezależną scenę.\r\n\r\nZrzut zapisuje PNG, a przycisk nagrywania rozpoczyna lub kończy "
    L"MP4. Wstrzymaj zatrzymuje animację. Aplikacja instaluje i odinstalowuje również wbudowany wygaszacz. Ustawienia są zapisywane na "
    L"bieżąco.\r\n\r\nAplikacja działa tylko w jednej instancji. Kolejne uruchomienie przywraca zminimalizowane okno sterowania, odświeża je i "
    L"przenosi na pierwszy plan.\r\n\r\nKlawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera wywołują polecenie. "
    L"Esc zamyka aktywne okno Pomocy lub O programie; w oknie sterowania kończy działanie aplikacji.\r\n\r\nZrzuty i nagrania obejmują "
    L"pierwszy aktywny monitor animacji, a nie wspólny obraz wszystkich monitorów. PNG używa folderu Obrazy, MP4 folderu Wideo; jeśli ich nie "
    L"ma, używane są Dokumenty. Nagranie MP4 odpowiada częstotliwości monitora, najwyżej jednak 60 klatkom na sekundę.\r\n\r\nSystemy od "
    L"Windows 7 do Windows 11 obsługują wszystkie funkcje, w tym zrzuty PNG i nagrywanie MP4. Windows Vista SP2: KB971512, KB2117917. "
    L"Nagrywanie MP4 nie działa w Vista w obecnej wersji.",
    L"FlyingSolids zobrazuje osvetlené plné 3D telesá. Jazdce nastavujú rýchlosť objektov a kamery 0–1600 %, jednu až desať kópií a veľkosť "
    L"50–200 %. Vyberte Pozorovanie priestoru alebo priamy Prelet priestorom a zapnite požadované telesá.\r\n\r\nZačiarkavacie políčka Hlavné "
    L"svetlo a Doplnkové svetlo pod pravými jazdcami nezávisle zapínajú alebo vypínajú obe svetlá pre celú scénu. Predvolene je Hlavné svetlo "
    L"zapnuté a Doplnkové svetlo vypnuté. Nastavenia svetiel sa ukladajú zvlášť pre aplikáciu a šetrič obrazovky.\r\n\r\nV zozname možno "
    L"označiť viac monitorov; dvojklik zapína alebo vypína animáciu na monitore a možno zrušiť aj výber všetkých. Každý monitor používa "
    L"nezávislú scénu.\r\n\r\nSnímka uloží PNG a tlačidlo záznamu spustí alebo ukončí MP4. Pozastavenie zastaví animáciu. Aplikácia tiež "
    L"nainštaluje alebo odinštaluje vložený šetrič. Nastavenia sa ukladajú priebežne.\r\n\r\nAplikácia beží iba v jednej inštancii. Ďalšie "
    L"spustenie obnoví minimalizované ovládacie okno, prekreslí ho a prenesie do popredia.\r\n\r\nMedzi ovládacími prvkami prechádzajte "
    L"klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a príslušného písmena. Esc zavrie aktívne okno Pomocníka alebo O "
    L"aplikácii; v ovládacom okne ukončí aplikáciu.\r\n\r\nSnímky a záznamy zachytávajú prvý aktívny animačný monitor, nie spoločnú plochu "
    L"všetkých monitorov. PNG používa Obrázky, MP4 Videá; ak tieto priečinky neexistujú, použijú sa Dokumenty. Záznam MP4 zodpovedá "
    L"obnovovacej frekvencii monitora, najviac však 60 snímkam za sekundu.\r\n\r\nWindows 7 až Windows 11 podporujú všetky funkcie vrátane "
    L"snímok PNG a záznamu MP4. Windows Vista SP2: KB971512, KB2117917. Záznam MP4 na Viste v súčasnej verzii nefunguje.",
    L"FlyingSolids displays illuminated solid 3D objects. The sliders set object and camera speed from 0–1600%, one to ten copies and size "
    L"from 50–200%. Choose Space observation or the straight Fly through space mode and enable the required objects.\r\n\r\nThe Main light and "
    L"Fill light checkboxes below the right-hand sliders independently enable or disable the two lights for the entire scene. By default, Main "
    L"light is on and Fill light is off. Light settings are stored separately for the application and screen saver.\r\n\r\nSelect several "
    L"displays; double-click a row to toggle it, or clear the selection for all displays. Each display uses an independent "
    L"scene.\r\n\r\nSnapshot saves PNG and the recording button starts or stops MP4. Pause stops the animation. The application also installs "
    L"or uninstalls its embedded screen saver. Settings are saved continuously.\r\n\r\nOnly one instance of the application runs at a time. "
    L"Launching it again restores its minimised control window, redraws it and brings it to the foreground.\r\n\r\nUse Tab and Shift+Tab to "
    L"move between controls; use Alt and the underlined letter to activate a command. Esc closes the active Help or About window; in the "
    L"control window, it exits the application.\r\n\r\nSnapshots and recordings capture the first active animation display, not a combined "
    L"image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if those folders do not exist. MP4 "
    L"recording follows the display refresh rate, up to 60 frames per second.\r\n\r\nWindows 7 through Windows 11 support all features, "
    L"including PNG snapshots and MP4 recording. Windows Vista SP2: KB971512, KB2117917. MP4 recording does not work on Vista in the current "
    L"version.",
    L"FlyingSolids displays illuminated solid 3D objects. The sliders set object and camera speed from 0–1600%, one to ten copies and size "
    L"from 50–200%. Choose Space observation or the straight Fly through space mode and enable the required objects.\r\n\r\nThe Main light and "
    L"Fill light checkboxes below the right-hand sliders independently enable or disable the two lights for the entire scene. By default, Main "
    L"light is on and Fill light is off. Light settings are stored separately for the application and screen saver.\r\n\r\nSelect several "
    L"displays; double-click a row to toggle it, or clear the selection for all displays. Each display uses an independent "
    L"scene.\r\n\r\nSnapshot saves PNG and the recording button starts or stops MP4. Pause stops the animation. The application also installs "
    L"or uninstalls its embedded screen saver. Settings are saved continuously.\r\n\r\nOnly one instance of the application runs at a time. "
    L"Launching it again restores its minimised control window, redraws it and brings it to the foreground.\r\n\r\nUse Tab and Shift+Tab to "
    L"move between controls; use Alt and the underlined letter to activate a command. Esc closes the active Help or About window; in the "
    L"control window, it exits the application.\r\n\r\nSnapshots and recordings capture the first active animation display, not a combined "
    L"image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if those folders do not exist. MP4 "
    L"recording follows the display refresh rate, up to 60 frames per second.\r\n\r\nWindows 7 through Windows 11 support all features, "
    L"including PNG snapshots and MP4 recording. Windows Vista SP2: KB971512, KB2117917. MP4 recording does not work on Vista in the current "
    L"version.",
    L"O FlyingSolids mostra sólidos 3D iluminados. Os controlos regulam a velocidade dos objetos e da câmara entre 0 e 1600%, uma a dez cópias "
    L"e o tamanho entre 50 e 200%. Escolha Observação do espaço ou o Voo pelo espaço em linha reta e ative os sólidos pretendidos.\r\n\r\nAs "
    L"caixas Luz principal e Luz de preenchimento sob os controlos deslizantes da direita ativam ou desativam as duas luzes de forma "
    L"independente em toda a cena. Por predefinição, Luz principal está ligada e Luz de preenchimento está desligada. As definições de "
    L"iluminação são guardadas separadamente para a aplicação e a proteção de ecrã.\r\n\r\nSelecione vários monitores; um duplo clique alterna "
    L"uma linha e todos podem ser desmarcados. Cada monitor usa uma cena independente.\r\n\r\nCaptura guarda PNG e o botão de gravação inicia "
    L"ou termina MP4. Pausa para a animação. A aplicação também instala ou desinstala a proteção de ecrã incorporada. As definições são "
    L"guardadas continuamente.\r\n\r\nA aplicação só pode ter uma instância em execução. Um novo arranque restaura a janela de controlo "
    L"minimizada, redesenha-a e coloca-a em primeiro plano.\r\n\r\nUse Tab e Shift+Tab para passar entre controlos; Alt e a letra sublinhada "
    L"ativam um comando. Esc fecha a janela ativa de Ajuda ou Acerca de; na janela de controlo, termina a aplicação.\r\n\r\nAs capturas e "
    L"gravações usam o primeiro monitor de animação ativo, não uma imagem conjunta de todos os monitores. PNG usa Imagens, MP4 Vídeos; se "
    L"essas pastas não existirem, usa-se Documentos. A gravação MP4 segue a frequência do monitor, até um máximo de 60 fotogramas por "
    L"segundo.\r\n\r\nOs sistemas Windows 7 a Windows 11 suportam todas as funcionalidades, incluindo capturas PNG e gravação MP4. Windows "
    L"Vista SP2: KB971512, KB2117917. A gravação MP4 não funciona no Vista na versão atual.",
    L"FlyingSolids viser belyste solide 3D-legemer. Glidebryterne angir objekt- og kamerahastighet fra 0–1600 %, én til ti kopier og størrelse "
    L"fra 50–200 %. Velg Romobservasjon eller Flyging gjennom rommet i rett linje og aktiver ønskede legemer.\r\n\r\nAvmerkingsboksene "
    L"Hovedlys og Utfyllingslys under glidebryterne til høyre slår de to lysene av eller på uavhengig av hverandre for hele scenen. Som "
    L"standard er Hovedlys på og Utfyllingslys av. Lysinnstillingene lagres separat for programmet og skjermspareren.\r\n\r\nVelg flere "
    L"skjermer i listen; dobbeltklikk en rad for å slå animasjonen av eller på, eller fjern valget for alle. Hver skjerm bruker en uavhengig "
    L"scene.\r\n\r\nSkjermbilde lagrer PNG, og opptaksknappen starter eller stopper MP4. Pause stanser animasjonen. Programmet installerer "
    L"eller avinstallerer også den innebygde skjermspareren. Innstillingene lagres fortløpende.\r\n\r\nBare én instans av programmet kan kjøre "
    L"om gangen. En ny start gjenoppretter det minimerte kontrollvinduet, tegner det på nytt og bringer det fremst.\r\n\r\nBruk Tab og "
    L"Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc lukker det aktive Hjelp- eller "
    L"Om-vinduet; i kontrollvinduet avslutter det programmet.\r\n\r\nSkjermbilder og opptak bruker den første aktive animasjonsskjermen, ikke "
    L"et samlet bilde av alle skjermene. PNG bruker Bilder, MP4 Videoer; hvis disse mappene ikke finnes, brukes Dokumenter. MP4-opptak følger "
    L"skjermens oppdateringsfrekvens, opptil 60 bilder per sekund.\r\n\r\nWindows 7 til Windows 11 støtter alle funksjoner, inkludert "
    L"PNG-skjermbilder og MP4-opptak. Windows Vista SP2: KB971512, KB2117917. MP4-opptak fungerer ikke på Vista i den gjeldende versjonen.",
    L"FlyingSolids visar belysta solida 3D-kroppar. Reglagen ställer in objekt- och kamerahastighet 0–1600 %, en till tio kopior och storlek "
    L"50–200 %. Välj Rymdobservation eller Flygning genom rymden i rak linje och aktivera önskade kroppar.\r\n\r\nKryssrutorna Huvudljus och "
    L"Upplättningsljus under reglagen till höger slår på eller av de två ljusen oberoende av varandra för hela scenen. Som standard är "
    L"Huvudljus på och Upplättningsljus av. Ljusinställningarna sparas separat för programmet och skärmsläckaren.\r\n\r\nVälj flera "
    L"bildskärmar i listan; dubbelklicka en rad för att slå på eller av animeringen, eller avmarkera alla. Varje bildskärm använder en "
    L"oberoende scen.\r\n\r\nSkärmbild sparar PNG och inspelningsknappen startar eller stoppar MP4. Paus stannar animeringen. Programmet "
    L"installerar eller avinstallerar även den inbyggda skärmsläckaren. Inställningarna sparas fortlöpande.\r\n\r\nProgrammet kan bara köras i "
    L"en instans åt gången. En ny start återställer det minimerade kontrollfönstret, ritar om det och för det längst fram.\r\n\r\nAnvänd Tab "
    L"och Skift+Tab för att flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett kommando. Esc stänger det aktiva "
    L"Hjälp- eller Om-fönstret; i kontrollfönstret avslutar det programmet.\r\n\r\nSkärmbilder och inspelningar använder den första aktiva "
    L"animeringsskärmen, inte en sammanslagen bild av alla skärmar. PNG använder Bilder, MP4 Videor; om dessa mappar saknas används Dokument. "
    L"MP4-inspelning följer skärmens uppdateringsfrekvens, upp till 60 bilder per sekund.\r\n\r\nWindows 7 till Windows 11 stöder alla "
    L"funktioner, inklusive PNG-skärmbilder och MP4-inspelning. Windows Vista SP2: KB971512, KB2117917. MP4-inspelning fungerar inte på Vista "
    L"i den aktuella versionen.",
    L"FlyingSolids näyttää valaistuja kiinteitä 3D-kappaleita. Liukusäätimillä asetetaan kohteiden ja kameran nopeus 0–1600 %, yhdestä "
    L"kymmeneen kopiota ja koko 50–200 %. Valitse Avaruuden tarkkailu tai Lento avaruuden halki suoraan eteenpäin ja ota halutut kappaleet "
    L"käyttöön.\r\n\r\nOikeanpuoleisten liukusäätimien alla olevat Päävalo- ja Täytevalo-valintaruudut kytkevät koko näkymän kaksi valoa "
    L"päälle tai pois toisistaan riippumatta. Oletuksena Päävalo on päällä ja Täytevalo pois päältä. Valaistusasetukset tallennetaan erikseen "
    L"sovellukselle ja näytönsäästäjälle.\r\n\r\nLuettelosta voi valita useita näyttöjä; kaksoisnapsautus vaihtaa rivin tilaa ja kaikkien "
    L"näyttöjen valinnan voi poistaa. Jokaisella näytöllä on itsenäinen näkymä.\r\n\r\nTilannekuva tallentaa PNG:n ja tallennuspainike "
    L"käynnistää tai lopettaa MP4:n. Keskeytä pysäyttää animaation. Sovellus asentaa tai poistaa myös sisäisen näytönsäästäjän. Asetukset "
    L"tallennetaan jatkuvasti.\r\n\r\nSovelluksesta voi olla käynnissä vain yksi instanssi. Uusi käynnistys palauttaa pienennetyn "
    L"ohjausikkunan, piirtää sen uudelleen ja tuo sen etualalle.\r\n\r\nSiirry säätimien välillä Tab- ja Vaihto+Tab-näppäimillä; Alt ja "
    L"alleviivattu kirjain aktivoivat komennon. Esc sulkee aktiivisen Ohje- tai Tietoja-ikkunan; ohjausikkunassa se sulkee "
    L"sovelluksen.\r\n\r\nTilannekuvat ja tallenteet käyttävät ensimmäistä aktiivista animaationäyttöä, eivät kaikkien näyttöjen yhdistettyä "
    L"kuvaa. PNG käyttää Kuvat-kansiota ja MP4 Videot-kansiota; jos niitä ei ole, käytetään Tiedostot-kansiota. MP4-tallennus seuraa näytön "
    L"virkistystaajuutta, enintään 60 kuvaa sekunnissa.\r\n\r\nWindows 7–Windows 11 tukevat kaikkia toimintoja, myös PNG-tilannekuvia ja "
    L"MP4-tallennusta. Windows Vista SP2: KB971512, KB2117917. MP4-tallennus ei toimi Vistassa nykyisessä versiossa.",
    L"FlyingSolids viser belyste solide 3D-legemer. Skyderne indstiller objekt- og kamerahastighed 0–1600 %, en til ti kopier og størrelse "
    L"50–200 %. Vælg Rumobservation eller Flyvning gennem rummet i en lige linje og aktivér de ønskede legemer.\r\n\r\nAfkrydsningsfelterne "
    L"Hovedlys og Udfyldningslys under skyderne til højre slår de to lys til eller fra uafhængigt af hinanden for hele scenen. Som standard er "
    L"Hovedlys slået til og Udfyldningslys slået fra. Lysindstillingerne gemmes separat for programmet og pauseskærmen.\r\n\r\nVælg flere "
    L"skærme i listen; dobbeltklik på en række for at slå animationen til eller fra, eller fravælg alle. Hver skærm bruger en uafhængig "
    L"scene.\r\n\r\nSkærmbillede gemmer PNG, og optageknappen starter eller stopper MP4. Pause standser animationen. Programmet installerer "
    L"eller afinstallerer også den indbyggede pauseskærm. Indstillinger gemmes løbende.\r\n\r\nProgrammet kan kun køre i én instans ad gangen. "
    L"En ny start gendanner det minimerede kontrolvindue, tegner det igen og bringer det forrest.\r\n\r\nBrug Tab og Skift+Tab til at flytte "
    L"mellem kontrollerne; Alt og det understregede bogstav aktiverer en kommando. Esc lukker det aktive Hjælp- eller Om-vindue; i "
    L"kontrolvinduet afslutter det programmet.\r\n\r\nSkærmbilleder og optagelser bruger den første aktive animationsskærm, ikke et samlet "
    L"billede af alle skærme. PNG bruger Billeder, MP4 Videoer; hvis disse mapper ikke findes, bruges Dokumenter. MP4-optagelse følger "
    L"skærmens opdateringsfrekvens, dog højst 60 billeder i sekundet.\r\n\r\nWindows 7 til Windows 11 understøtter alle funktioner, herunder "
    L"PNG-skærmbilleder og MP4-optagelse. Windows Vista SP2: KB971512, KB2117917. MP4-optagelse fungerer ikke på Vista i den aktuelle version.",
    L"FlyingSolids sýnir upplýsta heila þrívíddarhluti. Rennistikur stilla hraða hluta og myndavélar á 0–1600%, eitt til tíu eintök og stærð á "
    L"50–200%. Veldu Athugun rýmis eða Flug um rýmið í beinni línu og virkjaðu þá hluti sem óskað er eftir.\r\n\r\nGátreitirnir Aðalljós og "
    L"Fylliljós undir rennistikunum hægra megin kveikja eða slökkva á ljósunum tveimur óháð hvort öðru fyrir alla senuna. Sjálfgefið er kveikt "
    L"á Aðalljós og slökkt á Fylliljós. Ljósastillingar eru vistaðar sérstaklega fyrir forritið og skjáhvíluna.\r\n\r\nVelja má marga skjái; "
    L"tvísmellur virkjar eða slekkur á hreyfimynd á skjá og afvelja má alla skjái. Hver skjár notar sjálfstæða senu.\r\n\r\nSkjámynd vistar "
    L"PNG og upptökuhnappurinn ræsir eða stöðvar MP4. Hnappurinn Gera hlé stöðvar hreyfimyndina. Forritið setur einnig upp eða fjarlægir "
    L"innbyggðu skjáhvíluna. Stillingar vistast jafnóðum.\r\n\r\nAðeins eitt eintak af forritinu getur verið í gangi í einu. Ný ræsing "
    L"endurheimtir lágmarkaðan stjórngluggann, endurteiknar hann og færir hann fremst.\r\n\r\nNotaðu Tab og Shift+Tab til að færa þig milli "
    L"stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc lokar virka Hjálp- eða Um-glugganum; í stjórnglugganum lokar það "
    L"forritinu.\r\n\r\nSkjámyndir og upptökur nota fyrsta virka hreyfimyndaskjáinn, ekki sameinaða mynd af öllum skjám. PNG notar Myndir, MP4 "
    L"Myndbönd; ef þær möppur eru ekki til er Skjöl notuð. MP4-upptaka fylgir endurnýjunartíðni skjásins, þó mest 60 römmum á "
    L"sekúndu.\r\n\r\nWindows 7 til Windows 11 styðja alla eiginleika, þar á meðal PNG-skjámyndir og MP4-upptöku. Windows Vista SP2: KB971512, "
    L"KB2117917. MP4-upptaka virkar ekki í Vista í núverandi útgáfu.",
    L"FlyingSolids aydınlatılmış katı 3B cisimler gösterir. Kaydırıcılar nesne ve kamera hızını %0–1600, kopya sayısını bir ile on ve boyutu "
    L"%50–200 arasında ayarlar. Uzayı gözlemleme veya doğrusal Uzayda uçuş kipini seçip istenen cisimleri etkinleştirin.\r\n\r\nSağdaki "
    L"kaydırıcıların altındaki Ana ışık ve Dolgu ışığı onay kutuları, tüm sahne için iki ışığı birbirinden bağımsız olarak açar veya kapatır. "
    L"Varsayılan olarak Ana ışık açık, Dolgu ışığı kapalıdır. Aydınlatma ayarları uygulama ve ekran koruyucu için ayrı ayrı "
    L"kaydedilir.\r\n\r\nListede birden çok monitör seçilebilir; satıra çift tıklamak monitördeki animasyonu açıp kapatır; tüm monitörlerin "
    L"seçimi de kaldırılabilir. Her monitör bağımsız sahne kullanır.\r\n\r\nAnlık görüntü PNG kaydeder; kayıt düğmesi MP4 kaydını başlatır "
    L"veya bitirir. Duraklat animasyonu durdurur. Uygulama gömülü ekran koruyucuyu da kurar veya kaldırır. Ayarlar sürekli "
    L"kaydedilir.\r\n\r\nUygulamanın aynı anda yalnızca bir örneği çalışabilir. Yeniden başlatılması, simge durumuna küçültülmüş denetim "
    L"penceresini geri yükler, yeniden çizer ve ön plana getirir.\r\n\r\nDenetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı "
    L"çizili harf bir komutu etkinleştirir. Esc, etkin Yardım veya Hakkında penceresini kapatır; denetim penceresinde uygulamadan "
    L"çıkar.\r\n\r\nAnlık görüntüler ve kayıtlar, tüm monitörlerin birleşik görüntüsünü değil, ilk etkin animasyon monitörünü kullanır. PNG "
    L"Resimler, MP4 Videolar klasörünü kullanır; bu klasörler yoksa Belgeler kullanılır. MP4 kaydı monitörün yenileme hızını izler, ancak "
    L"saniyede en fazla 60 karedir.\r\n\r\nWindows 7 ile Windows 11 arasındaki sürümler, PNG anlık görüntüler ve MP4 kaydı dâhil tüm "
    L"özellikleri destekler. Windows Vista SP2: KB971512, KB2117917. Geçerli sürümde MP4 kaydı Vista'da çalışmaz."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> SCREEN_SAVER_HELP_TEXTS = {
    L"Vyberte Pozorování prostoru nebo přímý Průlet prostorem. Jezdci nastavují rychlost objektů a kamery 0–1600 %, jednu až deset kopií "
    L"každého zapnutého tělesa a velikost 50–200 %.\r\n\r\nZatržítka Hlavní světlo a Doplňkové světlo pod pravými jezdci nezávisle zapínají a "
    L"vypínají obě světla pro celou scénu. Výchozí stav: Hlavní světlo zapnuté, Doplňkové světlo vypnuté. Nastavení světel se ukládá zvlášť "
    L"pro aplikaci a spořič obrazovky.\r\n\r\nZapněte požadované druhy těles. Zapnout náhled spustí celoobrazovkový náhled na všech "
    L"monitorech; změny lze zkoušet za otevřeného nastavení. OK nastavení uloží, Storno je zahodí. Celoobrazovkový spořič ukončíte klávesou "
    L"Esc nebo pohybem myši.\r\n\r\nMezi ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a "
    L"příslušného písmene. Esc v nastavení odpovídá tlačítku Storno; v nápovědě nebo okně O aplikaci zavře pouze toto okno.\r\n\r\nPodporovány "
    L"jsou systémy Windows 7 až Windows 11. Windows Vista SP2: KB971512, KB2117917.",
    L"Choose Space observation or the straight Fly through space mode. The sliders set object and camera speed from 0–1600%, one to ten copies "
    L"of each enabled object, and size from 50–200%.\r\n\r\nThe Main light and Fill light checkboxes below the right-hand sliders "
    L"independently enable or disable the two lights for the entire scene. By default, Main light is on and Fill light is off. Light settings "
    L"are stored separately for the application and screen saver.\r\n\r\nEnable the required object types. Enable preview starts a full-screen "
    L"preview on every display while the settings dialog remains open for live adjustments. OK saves the settings and Cancel discards them. "
    L"Exit the full-screen saver with Esc or mouse movement.\r\n\r\nUse Tab and Shift+Tab to move between controls; use Alt and the underlined "
    L"letter to activate a command. Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes only that "
    L"window.\r\n\r\nWindows 7 through Windows 11 are supported. Windows Vista SP2: KB971512, KB2117917.",
    L"Wählen Sie Raumbeobachtung oder Flug durch den Raum in gerader Linie. Die Regler bestimmen Objekt- und Kamerageschwindigkeit von 0–1600 "
    L"%, ein bis zehn Exemplare je aktivem Körper und 50–200 % Größe.\r\n\r\nDie Kontrollkästchen Hauptlicht und Aufhelllicht unter den "
    L"rechten Reglern schalten die beiden Lichtquellen für die gesamte Szene unabhängig ein oder aus. Standardmäßig ist Hauptlicht "
    L"eingeschaltet und Aufhelllicht ausgeschaltet. Die Lichteinstellungen werden für Anwendung und Bildschirmschoner getrennt "
    L"gespeichert.\r\n\r\nAktivieren Sie die gewünschten Körper. Vorschau einschalten startet eine Vollbildvorschau auf allen Monitoren. Der "
    L"Einstellungsdialog bleibt für Änderungen geöffnet. OK speichert, Abbrechen verwirft. Esc oder eine Mausbewegung beendet den "
    L"Vollbildschoner.\r\n\r\nMit Tab und Umschalt+Tab wechseln Sie zwischen den Steuerelementen; mit Alt und dem unterstrichenen Buchstaben "
    L"rufen Sie einen Befehl auf. Esc im Einstellungsdialog entspricht Abbrechen; in der Hilfe oder im Infofenster schließt es nur dieses "
    L"Fenster.\r\n\r\nUnterstützt werden Windows 7 bis Windows 11. Windows Vista SP2: KB971512, KB2117917.",
    L"Choisissez Observation de l’espace ou le Vol dans l’espace rectiligne. Les curseurs règlent la vitesse des objets et de la caméra de 0 à "
    L"1 600 %, une à dix copies et une taille de 50 à 200 %.\r\n\r\nLes cases Éclairage principal et Éclairage d’appoint sous les curseurs de "
    L"droite activent ou désactivent indépendamment les deux sources lumineuses pour toute la scène. Par défaut, Éclairage principal est "
    L"activé et Éclairage d’appoint est désactivé. Les réglages d’éclairage sont enregistrés séparément pour l’application et l’économiseur "
    L"d’écran.\r\n\r\nActivez les solides voulus. Activer l’aperçu lance un aperçu plein écran sur tous les moniteurs ; la boîte de dialogue "
    L"reste ouverte pour les réglages en direct. OK enregistre les réglages, Annuler les abandonne. Échap ou un mouvement de souris quitte le "
    L"plein écran.\r\n\r\nUtilisez Tab et Maj+Tab pour passer d’un contrôle à l’autre ; Alt et la lettre soulignée activent une commande. "
    L"Échap dans les réglages équivaut à Annuler ; dans l’aide ou À propos, cette touche ferme uniquement cette fenêtre.\r\n\r\nWindows 7 à "
    L"Windows 11 sont pris en charge. Windows Vista SP2: KB971512, KB2117917.",
    L"Elija Observación del espacio o Vuelo por el espacio en línea recta. Los controles ajustan la velocidad de objetos y cámara del 0 al "
    L"1600 %, de una a diez copias y el tamaño del 50 al 200 %.\r\n\r\nLas casillas Luz principal y Luz de relleno bajo los controles "
    L"deslizantes de la derecha activan o desactivan las dos luces de forma independiente para toda la escena. De forma predeterminada, Luz "
    L"principal está activada y Luz de relleno está desactivada. Los ajustes de iluminación se guardan por separado para la aplicación y el "
    L"salvapantallas.\r\n\r\nActive los sólidos deseados. Activar vista previa inicia una vista previa a pantalla completa en todos los "
    L"monitores; el cuadro de configuración permanece abierto para realizar ajustes en tiempo real. Aceptar guarda y Cancelar descarta. Esc o "
    L"mover el ratón cierra el salvapantallas completo.\r\n\r\nUse Tab y Mayús+Tab para desplazarse entre controles; Alt y la letra subrayada "
    L"activan una opción. Esc en la configuración equivale a Cancelar; en Ayuda o Acerca de, cierra únicamente esa ventana.\r\n\r\nSe admiten "
    L"Windows 7 a Windows 11. Windows Vista SP2: KB971512, KB2117917.",
    L"Scegliere Osservazione dello spazio o Volo nello spazio rettilineo. I cursori regolano la velocità di oggetti e camera da 0 a 1600 %, da "
    L"una a dieci copie e la dimensione da 50 a 200 %.\r\n\r\nLe caselle Luce principale e Luce di riempimento sotto i cursori di destra "
    L"attivano o disattivano le due luci in modo indipendente per l’intera scena. Per impostazione predefinita, Luce principale è attiva e "
    L"Luce di riempimento è disattivata. Le impostazioni di illuminazione vengono salvate separatamente per l’applicazione e il "
    L"salvaschermo.\r\n\r\nAttivare i solidi desiderati. Attiva anteprima avvia un’anteprima a schermo intero su tutti i monitor; le "
    L"impostazioni rimangono aperte per le modifiche in tempo reale. OK salva e Annulla scarta. Esc o il movimento del mouse chiude il "
    L"salvaschermo a schermo intero.\r\n\r\nUsare Tab e Maiusc+Tab per passare tra i controlli; Alt e la lettera sottolineata attivano un "
    L"comando. Esc nelle impostazioni equivale ad Annulla; nella Guida o nelle Informazioni, chiude solo quella finestra.\r\n\r\nSono "
    L"supportati i sistemi da Windows 7 a Windows 11. Windows Vista SP2: KB971512, KB2117917.",
    L"Wybierz Obserwację przestrzeni albo prostoliniowy Przelot przez przestrzeń. Suwaki ustawiają prędkość obiektów i kamery 0–1600%, od "
    L"jednej do dziesięciu kopii i rozmiar 50–200%.\r\n\r\nPola wyboru Światło główne i Światło wypełniające pod prawymi suwakami niezależnie "
    L"włączają lub wyłączają oba światła dla całej sceny. Domyślnie Światło główne jest włączone, a Światło wypełniające wyłączone. Ustawienia "
    L"oświetlenia są zapisywane osobno dla aplikacji i wygaszacza ekranu.\r\n\r\nWłącz potrzebne bryły. Włącz podgląd uruchamia podgląd "
    L"pełnoekranowy na wszystkich monitorach. Okno ustawień pozostaje otwarte, umożliwiając zmiany na bieżąco. OK zapisuje ustawienia, a "
    L"Anuluj je odrzuca. Esc lub ruch myszy kończy tryb pełnoekranowy.\r\n\r\nKlawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i "
    L"podkreślona litera wywołują polecenie. Esc w ustawieniach odpowiada przyciskowi Anuluj; w Pomocy lub O programie zamyka tylko to "
    L"okno.\r\n\r\nObsługiwane są systemy od Windows 7 do Windows 11. Windows Vista SP2: KB971512, KB2117917.",
    L"Vyberte Pozorovanie priestoru alebo priamy Prelet priestorom. Jazdce nastavujú rýchlosť objektov a kamery 0–1600 %, jednu až desať kópií "
    L"a veľkosť 50–200 %.\r\n\r\nZačiarkavacie políčka Hlavné svetlo a Doplnkové svetlo pod pravými jazdcami nezávisle zapínajú alebo vypínajú "
    L"obe svetlá pre celú scénu. Predvolene je Hlavné svetlo zapnuté a Doplnkové svetlo vypnuté. Nastavenia svetiel sa ukladajú zvlášť pre "
    L"aplikáciu a šetrič obrazovky.\r\n\r\nZapnite požadované telesá. Zapnúť náhľad spustí celoobrazovkový náhľad na všetkých monitoroch; "
    L"nastavenia zostávajú otvorené a zmeny sa prejavia ihneď. OK uloží nastavenia a Zrušiť ich zahodí. Celoobrazovkový šetrič ukončí Esc "
    L"alebo pohyb myši.\r\n\r\nMedzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a "
    L"príslušného písmena. Esc v nastaveniach zodpovedá tlačidlu Zrušiť; v Pomocníkovi alebo okne O aplikácii zavrie iba toto "
    L"okno.\r\n\r\nPodporované sú systémy Windows 7 až Windows 11. Windows Vista SP2: KB971512, KB2117917.",
    L"Choose Space observation or the straight Fly through space mode. Set object and camera speed from 0–1600%, one to ten copies and size "
    L"from 50–200%, then enable the required objects.\r\n\r\nThe Main light and Fill light checkboxes below the right-hand sliders "
    L"independently enable or disable the two lights for the entire scene. By default, Main light is on and Fill light is off. Light settings "
    L"are stored separately for the application and screen saver.\r\n\r\nEnable preview starts a full-screen preview on every display while "
    L"the settings dialog remains open for live adjustments. OK saves the settings and Cancel discards them. Exit the full-screen screen saver "
    L"with Esc or mouse movement.\r\n\r\nUse Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a "
    L"command. Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\nWindows 7 through "
    L"Windows 11 are supported. Windows Vista SP2: KB971512, KB2117917.",
    L"Choose Space observation or the straight Fly through space mode. Set object and camera speed from 0–1600%, one to ten copies and size "
    L"from 50–200%, then enable the required objects.\r\n\r\nThe Main light and Fill light checkboxes below the right-hand sliders "
    L"independently enable or disable the two lights for the entire scene. By default, Main light is on and Fill light is off. Light settings "
    L"are stored separately for the application and screen saver.\r\n\r\nEnable preview starts a full-screen preview on every display while "
    L"the settings dialog remains open for live adjustments. OK saves the settings and Cancel discards them. Exit the full-screen screen saver "
    L"with Esc or mouse movement.\r\n\r\nUse Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a "
    L"command. Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\nWindows 7 through "
    L"Windows 11 are supported. Windows Vista SP2: KB971512, KB2117917.",
    L"Escolha Observação do espaço ou Voo pelo espaço em linha reta. Regule a velocidade dos objetos e da câmara de 0 a 1600%, uma a dez "
    L"cópias e o tamanho de 50 a 200%, e ative os sólidos.\r\n\r\nAs caixas Luz principal e Luz de preenchimento sob os controlos deslizantes "
    L"da direita ativam ou desativam as duas luzes de forma independente em toda a cena. Por predefinição, Luz principal está ligada e Luz de "
    L"preenchimento está desligada. As definições de iluminação são guardadas separadamente para a aplicação e a proteção de "
    L"ecrã.\r\n\r\nAtivar pré-visualização inicia uma pré-visualização em ecrã inteiro em todos os monitores; o diálogo permanece aberto para "
    L"ajustar as definições em tempo real. OK guarda as definições e Cancelar descarta-as. Esc ou o movimento do rato termina a proteção em "
    L"ecrã inteiro.\r\n\r\nUse Tab e Shift+Tab para passar entre controlos; Alt e a letra sublinhada ativam um comando. Esc nas definições "
    L"equivale a Cancelar; na Ajuda ou em Acerca de, fecha apenas essa janela.\r\n\r\nSão suportados os sistemas Windows 7 a Windows 11. "
    L"Windows Vista SP2: KB971512, KB2117917.",
    L"Velg Romobservasjon eller Flyging gjennom rommet i rett linje. Angi objekt- og kamerahastighet 0–1600 %, én til ti kopier og størrelse "
    L"50–200 %, og aktiver ønskede legemer.\r\n\r\nAvmerkingsboksene Hovedlys og Utfyllingslys under glidebryterne til høyre slår de to lysene "
    L"av eller på uavhengig av hverandre for hele scenen. Som standard er Hovedlys på og Utfyllingslys av. Lysinnstillingene lagres separat "
    L"for programmet og skjermspareren.\r\n\r\nSlå på forhåndsvisning starter en forhåndsvisning i fullskjerm på alle skjermer. Innstillingene "
    L"forblir åpne, og endringene vises fortløpende. OK lagrer innstillingene og Avbryt forkaster dem. Esc eller musebevegelse avslutter "
    L"fullskjermsvisningen.\r\n\r\nBruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en "
    L"kommando. Esc i innstillingene tilsvarer Avbryt; i Hjelp eller Om lukker det bare dette vinduet.\r\n\r\nWindows 7 til Windows 11 "
    L"støttes. Windows Vista SP2: KB971512, KB2117917.",
    L"Välj Rymdobservation eller Flygning genom rymden i rak linje. Ställ in objekt- och kamerahastighet 0–1600 %, en till tio kopior och "
    L"storlek 50–200 %, och aktivera önskade kroppar.\r\n\r\nKryssrutorna Huvudljus och Upplättningsljus under reglagen till höger slår på "
    L"eller av de två ljusen oberoende av varandra för hela scenen. Som standard är Huvudljus på och Upplättningsljus av. Ljusinställningarna "
    L"sparas separat för programmet och skärmsläckaren.\r\n\r\nAktivera förhandsvisning startar en förhandsvisning i helskärm på alla "
    L"bildskärmar. Inställningarna förblir öppna och ändringarna visas direkt. OK sparar inställningarna och Avbryt förkastar ändringarna. Esc "
    L"eller musrörelse avslutar helskärmsläget.\r\n\r\nAnvänd Tab och Skift+Tab för att flytta mellan kontrollerna; Alt och den understrukna "
    L"bokstaven aktiverar ett kommando. Esc i inställningarna motsvarar Avbryt; i Hjälp eller Om stänger det bara det fönstret.\r\n\r\nWindows "
    L"7 till Windows 11 stöds. Windows Vista SP2: KB971512, KB2117917.",
    L"Valitse Avaruuden tarkkailu tai Lento avaruuden halki suoraan eteenpäin. Aseta kohteiden ja kameran nopeus 0–1600 %, yhdestä kymmeneen "
    L"kopiota ja koko 50–200 %, ja ota halutut kappaleet käyttöön.\r\n\r\nOikeanpuoleisten liukusäätimien alla olevat Päävalo- ja "
    L"Täytevalo-valintaruudut kytkevät koko näkymän kaksi valoa päälle tai pois toisistaan riippumatta. Oletuksena Päävalo on päällä ja "
    L"Täytevalo pois päältä. Valaistusasetukset tallennetaan erikseen sovellukselle ja näytönsäästäjälle.\r\n\r\nOta esikatselu käyttöön "
    L"käynnistää koko näytön esikatselun kaikilla näytöillä. Asetusikkuna pysyy avoinna, ja muutokset näkyvät heti. OK tallentaa asetukset ja "
    L"Peruuta hylkää muutokset. Esc tai hiiren liike lopettaa koko näytön säästäjän.\r\n\r\nSiirry säätimien välillä Tab- ja "
    L"Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat komennon. Esc asetuksissa vastaa Peruuta-painiketta; Ohje- tai "
    L"Tietoja-ikkunassa se sulkee vain kyseisen ikkunan.\r\n\r\nTuettuja käyttöjärjestelmiä ovat Windows 7–Windows 11. Windows Vista SP2: "
    L"KB971512, KB2117917.",
    L"Vælg Rumobservation eller Flyvning gennem rummet i en lige linje. Indstil objekt- og kamerahastighed 0–1600 %, en til ti kopier og "
    L"størrelse 50–200 %, og aktivér de ønskede legemer.\r\n\r\nAfkrydsningsfelterne Hovedlys og Udfyldningslys under skyderne til højre slår "
    L"de to lys til eller fra uafhængigt af hinanden for hele scenen. Som standard er Hovedlys slået til og Udfyldningslys slået fra. "
    L"Lysindstillingerne gemmes separat for programmet og pauseskærmen.\r\n\r\nAktivér forhåndsvisning starter en forhåndsvisning i fuld skærm "
    L"på alle skærme. Indstillingerne forbliver åbne, og ændringerne vises med det samme. OK gemmer indstillingerne, og Annuller forkaster "
    L"ændringerne. Esc eller musebevægelse afslutter fuldskærmen.\r\n\r\nBrug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det "
    L"understregede bogstav aktiverer en kommando. Esc i indstillingerne svarer til Annuller; i Hjælp eller Om lukker det kun dette "
    L"vindue.\r\n\r\nWindows 7 til Windows 11 understøttes. Windows Vista SP2: KB971512, KB2117917.",
    L"Veldu Athugun rýmis eða Flug um rýmið í beinni línu. Stilltu hraða hluta og myndavélar á 0–1600%, eitt til tíu eintök og stærð á 50–200% "
    L"og virkjaðu óskaða hluti.\r\n\r\nGátreitirnir Aðalljós og Fylliljós undir rennistikunum hægra megin kveikja eða slökkva á ljósunum "
    L"tveimur óháð hvort öðru fyrir alla senuna. Sjálfgefið er kveikt á Aðalljós og slökkt á Fylliljós. Ljósastillingar eru vistaðar "
    L"sérstaklega fyrir forritið og skjáhvíluna.\r\n\r\nVirkja forskoðun ræsir forskoðun á öllum skjánum á hverjum skjá. Stillingaglugginn "
    L"helst opinn og breytingar sjást strax. Í lagi vistar stillingar og Hætta við hafnar breytingum. Esc eða músarhreyfing lokar skjáhvílu á "
    L"öllum skjánum.\r\n\r\nNotaðu Tab og Shift+Tab til að færa þig milli stýrieininga; Alt og undirstrikaður stafur virkja skipun. Esc í "
    L"stillingum jafngildir Hætta við; í Hjálp eða Um lokar það aðeins þeim glugga.\r\n\r\nWindows 7 til Windows 11 eru studd. Windows Vista "
    L"SP2: KB971512, KB2117917.",
    L"Uzayı gözlemleme veya doğrusal Uzayda uçuş kipini seçin. Nesne ve kamera hızını %0–1600, kopya sayısını bir ile on ve boyutu %50–200 "
    L"arasında ayarlayıp istenen cisimleri etkinleştirin.\r\n\r\nSağdaki kaydırıcıların altındaki Ana ışık ve Dolgu ışığı onay kutuları, tüm "
    L"sahne için iki ışığı birbirinden bağımsız olarak açar veya kapatır. Varsayılan olarak Ana ışık açık, Dolgu ışığı kapalıdır. Aydınlatma "
    L"ayarları uygulama ve ekran koruyucu için ayrı ayrı kaydedilir.\r\n\r\nÖnizlemeyi aç, tüm monitörlerde tam ekran önizleme başlatır. "
    L"Ayarlar penceresi açık kalır ve değişiklikler anında görülür. Tamam ayarları kaydeder, İptal değişiklikleri iptal eder. Tam ekran "
    L"koruyucudan Esc veya fare hareketiyle çıkılır.\r\n\r\nDenetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir "
    L"komutu etkinleştirir. Ayarlarda Esc, İptal ile aynı işlevi görür; Yardım veya Hakkında penceresinde yalnızca o pencereyi "
    L"kapatır.\r\n\r\nWindows 7 ile Windows 11 arasındaki sürümler desteklenir. Windows Vista SP2: KB971512, KB2117917."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> ABOUT_DESCRIPTION_TEXTS = {
    L"Hardwarově akcelerovaná animace plných prostorových objektů.",
    L"Hardware-accelerated animation of solid 3D objects.",
    L"Hardwarebeschleunigte Animation dreidimensionaler Volumenkörper.",
    L"Animation accélérée par le matériel d’objets 3D pleins.",
    L"Animación acelerada por hardware de objetos 3D sólidos.",
    L"Animazione con accelerazione hardware di oggetti 3D solidi.",
    L"Sprzętowo przyspieszana animacja pełnych obiektów 3D.",
    L"Hardvérovo akcelerovaná animácia plných 3D objektov.",
    L"Hardware-accelerated animation of solid 3D objects.",
    L"Hardware-accelerated animation of solid 3D objects.",
    L"Animação acelerada por hardware de objetos 3D sólidos.",
    L"Maskinvareakselerert animasjon av solide 3D-objekter.",
    L"Maskinvaruaccelererad animering av solida 3D-objekt.",
    L"Laitteistokiihdytetty kiinteiden 3D-kohteiden animaatio.",
    L"Hardwareaccelereret animation af solide 3D-objekter.",
    L"Vélbúnaðarhröðuð hreyfimynd heilla þrívíddarhluta.",
    L"Katı 3B nesnelerin donanım hızlandırmalı animasyonu."
};

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
    for (std::size_t index = 0; index < DISPLAY_ORDER.size(); index++) {
        if (DISPLAY_ORDER[index] == language) {
            return static_cast<int>(index);
        }
    }
    return 1;
}

/// Resolves a combo-box index to a supported language.
AppLanguage LanguageAtIndex(int index) {
    if (index >= 0 && index < static_cast<int>(DISPLAY_ORDER.size())) {
        return DISPLAY_ORDER[index];
    }
    return AppLanguage::EnglishUs;
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

/// Returns the localized copy-count slider caption.
const wchar_t* CopyCountText(AppLanguage language) {
    return COPY_COUNT_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized object-size slider caption.
const wchar_t* ObjectSizeText(AppLanguage language) {
    return OBJECT_SIZE_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
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
