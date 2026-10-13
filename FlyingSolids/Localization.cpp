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
 * Last modified for version 1.1.0.0
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
    L"Dutý válec s toroidálními čely",
    L"Rotační paraboloid uzavřený rovinou",
    L"Koule",
    L"Polokoule",
    L"Kulová úseč",
    L"Velká kulová úseč",
    L"Kulová vrstva",
    L"Trojosý elipsoid",
    L"Protáhlý rotační elipsoid",
    L"Zploštělý rotační elipsoid",
    L"Ovoid",
    L"Kapsle (sferocylindr)",
    L"Zaoblený disk (spheroplatelet)",
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
    L"Hollow cylinder with toroidal ends",
    L"Paraboloid of revolution closed by a plane",
    L"Sphere",
    L"Hemisphere",
    L"Spherical cap",
    L"Major spherical cap",
    L"Spherical segment (two bases)",
    L"Triaxial ellipsoid",
    L"Prolate spheroid",
    L"Oblate spheroid",
    L"Ovoid",
    L"Spherocylinder",
    L"Rounded disc (spheroplatelet)",
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
    L"Hohlzylinder mit toroidalen Enden",
    L"Geschlossener Rotationsparaboloid",
    L"Kugel",
    L"Halbkugel",
    L"Kugelabschnitt",
    L"Großer Kugelabschnitt",
    L"Kugelschicht",
    L"Dreiachsiges Ellipsoid",
    L"Verlängertes Rotationsellipsoid",
    L"Abgeplattetes Rotationsellipsoid",
    L"Ovoid",
    L"Sphärozylinder",
    L"Abgerundete Scheibe (Spheroplatelet)",
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
    L"Cylindre creux à extrémités toriques",
    L"Paraboloïde de révolution fermé par un plan",
    L"Boule",
    L"Demi-boule",
    L"Segment sphérique",
    L"Grand segment sphérique",
    L"Segment sphérique à deux bases",
    L"Ellipsoïde triaxial",
    L"Sphéroïde allongé",
    L"Sphéroïde aplati",
    L"Ovoïde",
    L"Sphérocylindre",
    L"Disque arrondi (spheroplatelet)",
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
    L"Cilindro hueco con extremos toroidales",
    L"Paraboloide de revolución cerrado por plano",
    L"Esfera",
    L"Hemisferio",
    L"Segmento esférico",
    L"Segmento esférico mayor",
    L"Segmento esférico de dos bases",
    L"Elipsoide triaxial",
    L"Esferoide prolato",
    L"Esferoide oblato",
    L"Ovoide",
    L"Esferocilindro",
    L"Disco redondeado (spheroplatelet)",
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
    L"Cilindro cavo con estremità toroidali",
    L"Paraboloide di rotazione chiuso da un piano",
    L"Sfera",
    L"Emisfero",
    L"Segmento sferico a una base",
    L"Segmento sferico maggiore",
    L"Segmento sferico a due basi",
    L"Ellissoide triassiale",
    L"Sferoide prolato",
    L"Sferoide oblato",
    L"Ovoide",
    L"Sferocilindro",
    L"Disco arrotondato (spheroplatelet)",
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
    L"Walec pusty z toroidalnymi końcami",
    L"Paraboloida obrotowa zamknięta płaszczyzną",
    L"Kula",
    L"Półkula",
    L"Odcinek kuli",
    L"Duży odcinek kuli",
    L"Warstwa kulista",
    L"Elipsoida trójosiowa",
    L"Sferoida wydłużona",
    L"Sferoida spłaszczona",
    L"Owoida",
    L"Sferocylinder",
    L"Zaokrąglony dysk (spheroplatelet)",
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
    L"Dutý valec s toroidálnymi čelami",
    L"Rotačný paraboloid uzavretý rovinou",
    L"Guľa",
    L"Pologuľa",
    L"Guľový odsek",
    L"Veľký guľový odsek",
    L"Guľová vrstva",
    L"Trojosový elipsoid",
    L"Predĺžený rotačný elipsoid",
    L"Sploštený rotačný elipsoid",
    L"Ovoid",
    L"Sferocylinder",
    L"Zaoblený disk (spheroplatelet)",
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
    L"Cilindro oco com extremidades toroidais",
    L"Paraboloide de revolução fechado por plano",
    L"Esfera",
    L"Hemisfério",
    L"Segmento esférico",
    L"Segmento esférico maior",
    L"Segmento esférico de duas bases",
    L"Elipsoide triaxial",
    L"Esferoide prolato",
    L"Esferoide oblato",
    L"Ovoide",
    L"Esferocilindro",
    L"Disco arredondado (spheroplatelet)",
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
    L"Hul sylinder med toroidale ender",
    L"Rotasjonsparaboloide lukket av et plan",
    L"Kule",
    L"Halvkule",
    L"Kulesegment",
    L"Stort kulesegment",
    L"Kulelag",
    L"Treakset ellipsoide",
    L"Prolat sfæroide",
    L"Flattrykt sfæroide",
    L"Ovoide",
    L"Sfærosylinder",
    L"Avrundet skive (spheroplatelet)",
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
    L"Ihålig cylinder med toroidala ändar",
    L"Rotationsparaboloid sluten av ett plan",
    L"Klot",
    L"Halvklot",
    L"Klotsegment",
    L"Stort klotsegment",
    L"Klotsegment med två baser",
    L"Treaxlig ellipsoid",
    L"Prolat sfäroid",
    L"Oblat sfäroid",
    L"Ovoid",
    L"Sfärocylinder",
    L"Avrundad skiva (spheroplatelet)",
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
    L"Ontto lieriö, toroidiset päädyt",
    L"Tasolla suljettu pyörähdysparaboloidi",
    L"Pallo",
    L"Puolipallo",
    L"Pallosegmentti",
    L"Suuri pallosegmentti",
    L"Katkaistu pallosegmentti",
    L"Kolmiakselinen ellipsoidi",
    L"Prolaatti sferoidi",
    L"Litteä sferoidi",
    L"Ovoidi",
    L"Sferosylinteri",
    L"Pyöristetty kiekko (spheroplatelet)",
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
    L"Hul cylinder med toroidale ender",
    L"Rotationsparaboloide lukket af et plan",
    L"Kugle",
    L"Halvkugle",
    L"Kuglesegment",
    L"Stort kuglesegment",
    L"Kuglelag",
    L"Treakset ellipsoide",
    L"Prolat sfæroide",
    L"Fladtrykt sfæroide",
    L"Ovoide",
    L"Sfærocylinder",
    L"Afrundet skive (spheroplatelet)",
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
    L"Holur sívalningur með tórusendum",
    L"Lokaður snúningsfleygbogaflötur",
    L"Kúla",
    L"Hálfkúla",
    L"Kúluhluti",
    L"Stór kúluhluti",
    L"Kúlulag",
    L"Þríása sporvala",
    L"Ílöng snúningssporvala",
    L"Flöt snúningssporvala",
    L"Egglaga rúmhlutur",
    L"Kúluhylki",
    L"Rúnaður diskur (spheroplatelet)",
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
    L"Toroidal uçlu içi boş silindir",
    L"Düzlemle kapatılmış dönel paraboloit",
    L"Küre",
    L"Yarım küre",
    L"Küre parçası",
    L"Büyük küre parçası",
    L"Küre tabakası",
    L"Üç eksenli elipsoit",
    L"Prolat sferoit",
    L"Basık sferoit",
    L"Ovoit",
    L"Sferosilindir",
    L"Yuvarlatılmış disk (spheroplatelet)",
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
        L"Modelo do monitor",
        L"Taxa de atualização",
        L"Profundidade de bits",
        L"Formato de cor",
        L"Espaço de cor",
        L"%u bits/canal",
        L"%u bits/píxel"
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
        L"Näytön malli",
        L"Virkistystaajuus",
        L"Bittisyvyys",
        L"Värimuoto",
        L"Väriavaruus",
        L"%u bittiä/kanava",
        L"%u bittiä/pikseli"
    }, MonitorColumnText{
        L"Skærmmodel",
        L"Opdateringsfrekvens",
        L"Bitdybde",
        L"Farveformat",
        L"Farverum",
        L"%u bit/kanal",
        L"%u bit/pixel"
    }, MonitorColumnText{
        L"Gerð skjás",
        L"Endurnýjunartíðni",
        L"Bitadýpt",
        L"Litasnið",
        L"Litarými",
        L"%u bitar/rás",
        L"%u bitar/myndpunktur"
    }, MonitorColumnText{
        L"Monitör modeli",
        L"Yenileme hızı",
        L"Bit derinliği",
        L"Renk biçimi",
        L"Renk alanı",
        L"%u bit/kanal",
        L"%u bit/piksel"
    }
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

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> PREVENT_SCREEN_SAVER_TEXTS = {
    L"Blokovat spořič při animaci",
    L"Prevent screen saver during animation",
    L"Bildschirmschoner bei Animation sperren",
    L"Bloquer l’écran de veille pendant l’animation",
    L"Bloquear salvapantallas durante la animación",
    L"Blocca salvaschermo durante l’animazione",
    L"Blokuj wygaszacz podczas animacji",
    L"Blokovať šetrič pri animácii",
    L"Prevent screen saver during animation",
    L"Prevent screen saver during animation",
    L"Bloquear proteção de ecrã durante a animação",
    L"Hindre skjermsparer under animasjon",
    L"Blockera skärmsläckare under animering",
    L"Estä näytönsäästäjä animaation aikana",
    L"Blokér pauseskærm under animation",
    L"Hindra skjáhvílu meðan hreyfimynd er í gangi",
    L"Animasyon sırasında ekran koruyucuyu engelle"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> AMBIENT_LIGHT_TEXTS = {
    L"Základní jas",
    L"Ambient light",
    L"Umgebungslicht",
    L"Éclairage ambiant",
    L"Luz ambiental",
    L"Luce ambientale",
    L"Światło otoczenia",
    L"Základný jas",
    L"Ambient light",
    L"Ambient light",
    L"Luz ambiente",
    L"Omgivelseslys",
    L"Omgivningsljus",
    L"Ympäristövalo",
    L"Omgivende lys",
    L"Umhverfislýsing",
    L"Ortam ışığı"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> RIM_LIGHT_TEXTS = {
    L"Přisvětlení obrysů",
    L"Rim light",
    L"Konturlicht",
    L"Éclairage des contours",
    L"Iluminación de contornos",
    L"Illuminazione dei contorni",
    L"Oświetlenie konturów",
    L"Prisvetlenie obrysov",
    L"Rim light",
    L"Rim light",
    L"Iluminação dos contornos",
    L"Konturlys",
    L"Konturljus",
    L"Reunavalo",
    L"Konturlys",
    L"Útlínulýsing",
    L"Kenar aydınlatması"
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

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> ABOUT_VERSION_LABELS = {
    L"Verze:",
    L"Version:",
    L"Version:",
    L"Version :",
    L"Versión:",
    L"Versione:",
    L"Wersja:",
    L"Verzia:",
    L"Version:",
    L"Version:",
    L"Versão:",
    L"Versjon:",
    L"Version:",
    L"Versio:",
    L"Version:",
    L"Útgáfa:",
    L"Sürüm:"
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
    L"Odinstalace se nezdařila. Pokud je spořič nebo jeho náhled spuštěný, zavřete jej a odinstalaci "
    L"zopakujte.",
    L"The screen saver could not be uninstalled. If the screen saver or its preview is running, close it and "
    L"try again.",
    L"Der Bildschirmschoner konnte nicht deinstalliert werden. Falls der Bildschirmschoner oder seine "
    L"Vorschau läuft, schließen Sie ihn und versuchen Sie es erneut.",
    L"Impossible de désinstaller l’économiseur. S’il est en cours d’exécution ou si son aperçu est ouvert, "
    L"fermez-le puis réessayez.",
    L"No se pudo desinstalar el salvapantallas. Si el salvapantallas o su vista previa están en ejecución, "
    L"ciérrelos e inténtelo de nuevo.",
    L"Impossibile disinstallare il salvaschermo. Se il salvaschermo o la relativa anteprima sono in "
    L"esecuzione, chiuderli e riprovare.",
    L"Nie udało się odinstalować wygaszacza. Jeśli wygaszacz lub jego podgląd jest uruchomiony, zamknij go i "
    L"spróbuj ponownie.",
    L"Šetrič sa nepodarilo odinštalovať. Ak je šetrič alebo jeho náhľad spustený, zatvorte ho a skúste to "
    L"znova.",
    L"The screen saver could not be uninstalled. If the screen saver or its preview is running, close it and "
    L"try again.",
    L"The screen saver could not be uninstalled. If the screen saver or its preview is running, close it and "
    L"try again.",
    L"Não foi possível desinstalar a proteção de ecrã. Se a proteção ou a pré-visualização estiver em "
    L"execução, feche-a e tente novamente.",
    L"Skjermspareren kunne ikke avinstalleres. Hvis skjermspareren eller forhåndsvisningen kjører, lukk den "
    L"og prøv på nytt.",
    L"Skärmsläckaren kunde inte avinstalleras. Om skärmsläckaren eller förhandsvisningen körs, stäng den och "
    L"försök igen.",
    L"Näytönsäästäjän poistaminen epäonnistui. Jos näytönsäästäjä tai sen esikatselu on käynnissä, sulje se "
    L"ja yritä uudelleen.",
    L"Pauseskærmen kunne ikke afinstalleres. Hvis pauseskærmen eller forhåndsvisningen kører, skal du lukke "
    L"den og prøve igen.",
    L"Ekki tókst að fjarlægja skjáhvíluna. Ef skjáhvílan eða forskoðun hennar er í gangi skaltu loka henni "
    L"og reyna aftur.",
    L"Ekran koruyucu kaldırılamadı. Ekran koruyucu veya önizlemesi çalışıyorsa kapatıp yeniden deneyin."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALLATION_BLOCKED_BY_SETTINGS_TEXTS = {
    L"Odinstalace se nezdařila, protože je otevřené nastavení FlyingSolids. Zavřete je a odinstalaci "
    L"zopakujte.",
    L"Uninstallation failed because FlyingSolids settings are open. Close the settings window and try again.",
    L"Die Deinstallation ist fehlgeschlagen, weil die FlyingSolids-Einstellungen geöffnet sind. Schließen "
    L"Sie das Fenster und versuchen Sie es erneut.",
    L"La désinstallation a échoué car les paramètres de FlyingSolids sont ouverts. Fermez cette fenêtre puis "
    L"réessayez.",
    L"La desinstalación falló porque la configuración de FlyingSolids está abierta. Cierre esa ventana e "
    L"inténtelo de nuevo.",
    L"La disinstallazione non è riuscita perché le impostazioni di FlyingSolids sono aperte. Chiudere la "
    L"finestra e riprovare.",
    L"Odinstalowanie nie powiodło się, ponieważ ustawienia FlyingSolids są otwarte. Zamknij okno i spróbuj "
    L"ponownie.",
    L"Odinštalovanie zlyhalo, pretože sú otvorené nastavenia FlyingSolids. Zatvorte ich a skúste to znova.",
    L"Uninstallation failed because FlyingSolids settings are open. Close the settings window and try again.",
    L"Uninstallation failed because FlyingSolids settings are open. Close the settings window and try again.",
    L"A desinstalação falhou porque as definições do FlyingSolids estão abertas. Feche a janela e tente "
    L"novamente.",
    L"Avinstalleringen mislyktes fordi innstillingene for FlyingSolids er åpne. Lukk vinduet og prøv på "
    L"nytt.",
    L"Avinstallationen misslyckades eftersom inställningarna för FlyingSolids är öppna. Stäng fönstret och "
    L"försök igen.",
    L"Asennuksen poisto epäonnistui, koska FlyingSolids-asetukset ovat avoinna. Sulje ikkuna ja yritä "
    L"uudelleen.",
    L"Afinstallationen mislykkedes, fordi indstillingerne for FlyingSolids er åbne. Luk vinduet, og prøv "
    L"igen.",
    L"Fjarlæging mistókst vegna þess að stillingar FlyingSolids eru opnar. Lokaðu glugganum og reyndu aftur.",
    L"FlyingSolids ayarları açık olduğu için kaldırma başarısız oldu. Ayarlar penceresini kapatıp yeniden "
    L"deneyin."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALLATION_BLOCKED_BY_SYSTEM_PREVIEW_TEXTS = {
    L"Odinstalace se nezdařila, protože běží systémový náhled. Zavřete okno Nastavení spořiče obrazovky a "
    L"odinstalaci zopakujte.",
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
    L"Odinstalowanie nie powiodło się, ponieważ działa podgląd systemowy. Zamknij okno Ustawienia wygaszacza "
    L"ekranu i spróbuj ponownie.",
    L"Odinštalovanie zlyhalo, pretože beží systémový náhľad. Zatvorte okno Nastavenie šetriča obrazovky a "
    L"skúste to znova.",
    L"Uninstallation failed because the system preview is running. Close the Screen Saver Settings window "
    L"and try again.",
    L"Uninstallation failed because the system preview is running. Close the Screen Saver Settings window "
    L"and try again.",
    L"A desinstalação falhou porque a pré-visualização do sistema está em execução. Feche as Definições da "
    L"proteção de ecrã e tente novamente.",
    L"Avinstalleringen mislyktes fordi systemforhåndsvisningen kjører. Lukk vinduet "
    L"Skjermsparerinnstillinger og prøv på nytt.",
    L"Avinstallationen misslyckades eftersom systemförhandsvisningen körs. Stäng fönstret Inställningar för "
    L"skärmsläckare och försök igen.",
    L"Asennuksen poisto epäonnistui, koska järjestelmän esikatselu on käynnissä. Sulje Näytönsäästäjän "
    L"asetukset ja yritä uudelleen.",
    L"Afinstallationen mislykkedes, fordi systemforhåndsvisningen kører. Luk vinduet "
    L"Pauseskærmsindstillinger, og prøv igen.",
    L"Fjarlæging mistókst vegna þess að kerfisforskoðun er í gangi. Lokaðu stillingaglugga skjáhvílu og "
    L"reyndu aftur.",
    L"Sistem önizlemesi çalıştığı için kaldırma başarısız oldu. Ekran Koruyucu Ayarları penceresini kapatıp "
    L"yeniden deneyin."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> UNINSTALLATION_BLOCKED_BY_RUNNING_SAVER_TEXTS = {
    L"Odinstalace se nezdařila, protože je spuštěný spořič nebo celoobrazovkový náhled. Ukončete jej "
    L"klávesou Esc nebo pohybem myši a odinstalaci zopakujte.",
    L"Uninstallation failed because the screen saver or full-screen preview is running. Exit it with Esc or "
    L"by moving the mouse, then try again.",
    L"Die Deinstallation ist fehlgeschlagen, weil der Bildschirmschoner oder die Vollbildvorschau läuft. "
    L"Beenden Sie ihn mit Esc oder durch Bewegen der Maus und versuchen Sie es erneut.",
    L"La désinstallation a échoué car l’économiseur ou l’aperçu plein écran est actif. Quittez-le avec Échap "
    L"ou en déplaçant la souris, puis réessayez.",
    L"La desinstalación falló porque está activo el salvapantallas o la vista previa a pantalla completa. "
    L"Salga con Esc o moviendo el ratón e inténtelo de nuevo.",
    L"La disinstallazione non è riuscita perché è attivo il salvaschermo o l’anteprima a schermo intero. "
    L"Uscire con Esc o muovendo il mouse e riprovare.",
    L"Odinstalowanie nie powiodło się, ponieważ działa wygaszacz lub podgląd pełnoekranowy. Zakończ go "
    L"klawiszem Esc albo ruchem myszy i spróbuj ponownie.",
    L"Odinštalovanie zlyhalo, pretože beží šetrič alebo celoobrazovkový náhľad. Ukončite ho klávesom Esc "
    L"alebo pohybom myši a skúste to znova.",
    L"Uninstallation failed because the screen saver or full-screen preview is running. Exit it with Esc or "
    L"by moving the mouse, then try again.",
    L"Uninstallation failed because the screen saver or full-screen preview is running. Exit it with Esc or "
    L"by moving the mouse, then try again.",
    L"A desinstalação falhou porque a proteção ou a pré-visualização em ecrã inteiro está em execução. Saia "
    L"com Esc ou movendo o rato e tente novamente.",
    L"Avinstalleringen mislyktes fordi skjermspareren eller fullskjermvisningen kjører. Avslutt med Esc "
    L"eller ved å bevege musen, og prøv på nytt.",
    L"Avinstallationen misslyckades eftersom skärmsläckaren eller helskärmsförhandsvisningen körs. Avsluta "
    L"med Esc eller genom att röra musen och försök igen.",
    L"Asennuksen poisto epäonnistui, koska näytönsäästäjä tai koko näytön esikatselu on käynnissä. Lopeta "
    L"Esc-näppäimellä tai liikuttamalla hiirtä ja yritä uudelleen.",
    L"Afinstallationen mislykkedes, fordi pauseskærmen eller forhåndsvisningen i fuld skærm kører. Afslut "
    L"med Esc eller ved at bevæge musen, og prøv igen.",
    L"Fjarlæging mistókst vegna þess að skjáhvílan eða forskoðun á öllum skjánum er í gangi. Lokaðu með Esc "
    L"eða með því að hreyfa músina og reyndu aftur.",
    L"Ekran koruyucu veya tam ekran önizleme çalıştığı için kaldırma başarısız oldu. Esc ile ya da fareyi "
    L"hareket ettirerek çıkıp yeniden deneyin."
};

/// Warnings shown before closing an application that is currently recording.
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> RECORDING_CLOSE_WARNING_TEXTS = {
    L"Ukončení aplikace ukončí právě probíhající záznam.",
    L"Closing the application will stop the recording currently in progress.",
    L"Beim Beenden der Anwendung wird die laufende Aufnahme beendet.",
    L"La fermeture de l’application arrêtera l’enregistrement en cours.",
    L"Al cerrar la aplicación se detendrá la grabación en curso.",
    L"La chiusura dell’applicazione interromperà la registrazione in corso.",
    L"Zamknięcie aplikacji zakończy trwające nagrywanie.",
    L"Ukončenie aplikácie ukončí práve prebiehajúci záznam.",
    L"Closing the application will stop the recording currently in progress.",
    L"Closing the application will stop the recording currently in progress.",
    L"Fechar a aplicação irá terminar a gravação em curso.",
    L"Hvis du avslutter programmet, avsluttes opptaket som pågår.",
    L"Om du avslutar programmet stoppas den pågående inspelningen.",
    L"Sovelluksen sulkeminen lopettaa käynnissä olevan tallennuksen.",
    L"Hvis du lukker programmet, stoppes den igangværende optagelse.",
    L"Ef forritinu er lokað stöðvast upptakan sem er í gangi.",
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
        L"Definições de gravação",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Resolução:",
        L"Frequência de imagens:",
        L"As alterações aplicam-se à próxima gravação MP4."
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
        L"Tallennusasetukset",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Tarkkuus:",
        L"Kuvataajuus:",
        L"Muutokset koskevat seuraavaa MP4-tallennusta."
    }, RecordingText{
        L"Optagelsesindstillinger",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Opløsning:",
        L"Billedfrekvens:",
        L"Ændringerne gælder næste MP4-optagelse."
    }, RecordingText{
        L"Upptökustillingar",
        L"Viewport",
        L"TV (BT.709, 4:2:0)",
        L"Upplausn:",
        L"Rammatíðni:",
        L"Breytingarnar gilda fyrir næstu MP4-upptöku."
    }, RecordingText{
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
    L"FlyingSolids zobrazuje osvětlená plná prostorová tělesa. Jezdci nastavují rychlost objektů a kamery v "
    L"rozsahu 0–1600 %, jednu až deset kopií každého tělesa a velikost 50–200 %. Vyberte Pozorování prostoru "
    L"nebo přímý Průlet prostorem a zaškrtněte požadované druhy těles. Zatržítka Hlavní světlo, Doplňkové "
    L"světlo, Základní jas a Přisvětlení obrysů pod jezdci nezávisle ovládají osvětlení celé scény. Základní "
    L"jas přisvětluje povrch těles, přisvětlení obrysů zvýrazňuje jejich okraje. Výchozí stav: hlavní "
    L"světlo, základní jas a přisvětlení obrysů zapnuté, doplňkové světlo vypnuté. Nastavení osvětlení se "
    L"ukládá zvlášť pro aplikaci a spořič obrazovky.\r\n\r\nV seznamu lze označit více monitorů; dvojklikem "
    L"na řádek monitor zapnete nebo vypnete a lze zrušit i výběr všech monitorů. Každý monitor používá "
    L"nezávislou scénu. Snímek ukládá PNG, tlačítko záznamu spouští a ukončuje MP4. Pozastavení zastaví "
    L"animaci. Aplikace také instaluje nebo odinstaluje zabalený spořič. Nastavení se ukládá průběžně. "
    L"Aplikace běží pouze v jedné instanci. Další spuštění obnoví minimalizované ovládací okno a přenese do "
    L"popředí. Mezi ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat "
    L"pomocí Alt a příslušného písmene. Esc zavře aktivní nápovědu či okno O aplikaci; v ovládacím okně "
    L"ukončí aplikaci. Volba Blokovat spořič při animaci brání spuštění spořiče Windows pouze tehdy, když je "
    L"animace skutečně viditelná a není pozastavená.\r\n\r\nSnímek a záznam zachycují první aktivní animační "
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
    L"FlyingSolids displays illuminated solid 3D objects. The sliders set object and camera speed from "
    L"0–1600%, one to ten copies of each object, and size from 50–200%. Choose Space observation or the "
    L"straight Fly through space mode and enable the required object types. The Main light, Fill light, "
    L"Ambient light, and Rim light checkboxes below the sliders independently control lighting for the whole "
    L"scene. Ambient light provides base illumination of object surfaces; rim light highlights their edges. "
    L"By default, main, ambient, and rim light are on, and fill light is off. Lighting settings are stored "
    L"separately for the application and screen saver.\r\n\r\nSelect several displays in the list; "
    L"double-click a row to toggle it, or clear the selection for all displays. Every display uses an "
    L"independent scene. Snapshot saves a PNG and the recording button starts or stops an MP4. Pause stops "
    L"the animation. The application also installs or uninstalls its embedded screen saver. Settings are "
    L"saved continuously. Only one instance of the application runs at a time. Launching it again restores "
    L"its minimized control window and brings it to the foreground. Use Tab and Shift+Tab to move between "
    L"controls; use Alt and the underlined letter to activate a command. Esc closes the active Help or About "
    L"window; in the control window, it exits the application. Prevent screen saver during animation blocks "
    L"the Windows screen saver only while the animation is actually visible and not paused.\r\n\r\nSnapshots "
    L"and recordings capture the first active animation display, not a combined image of all displays. PNG "
    L"uses Pictures and MP4 uses Videos, with Documents as the fallback if those folders do not exist. The "
    L"Recording settings button selects Viewport or TV. Viewport preserves the animation display’s "
    L"dimensions and refresh rate, up to 60 frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × "
    L"720 output in 16:9, with 50, 25, 59.94 (60000/1001) or 29.97 (30000/1001) frames per second. The image "
    L"keeps its aspect ratio; TV uses progressive BT.709 limited-range 4:2:0 video. Resolution and frame "
    L"rate are available only in TV mode. The Recording settings window can be minimized and does not block "
    L"the other application windows. OK saves choices for the next MP4 recording; Cancel or Esc discards "
    L"unconfirmed changes. The recorded display cannot be detached during recording; changes to other "
    L"displays do not stop the recording. Closing the application while recording requires confirmation "
    L"because it also stops the recording.\r\n\r\nWindows 7 through Windows 11 support all features, "
    L"including PNG snapshots and MP4 recording. To run the application on Windows Vista SP2, you must "
    L"install updates KB971512 and KB2117917. MP4 recording does not work on Vista in the current version.",
    L"FlyingSolids zeigt beleuchtete dreidimensionale Volumenkörper. Die Regler bestimmen Objekt- und "
    L"Kamerageschwindigkeit von 0–1600 %, ein bis zehn Exemplare je Körper und eine Größe von 50–200 %. "
    L"Wählen Sie Raumbeobachtung oder Flug durch den Raum in gerader Linie und aktivieren Sie die "
    L"gewünschten Körper. Die Kontrollkästchen Hauptlicht, Aufhelllicht, Umgebungslicht und Konturlicht "
    L"unter den Reglern steuern die Beleuchtung der gesamten Szene unabhängig voneinander. Umgebungslicht "
    L"sorgt für eine Grundhelligkeit der Körperoberflächen, Konturlicht betont ihre Ränder. Standardmäßig "
    L"sind Hauptlicht, Umgebungslicht und Konturlicht eingeschaltet und Aufhelllicht ausgeschaltet. Die "
    L"Beleuchtungseinstellungen werden für Anwendung und Bildschirmschoner getrennt gespeichert.\r\n\r\nIn "
    L"der Liste sind mehrere Monitore wählbar; ein Doppelklick schaltet einen Monitor um, auch alle können "
    L"abgewählt werden. Jeder Monitor besitzt eine unabhängige Szene. Schnappschuss speichert PNG, die "
    L"Aufnahmetaste startet oder beendet MP4. Pause hält die Animation an. Die Anwendung installiert oder "
    L"deinstalliert außerdem den eingebetteten Bildschirmschoner. Einstellungen werden laufend gespeichert. "
    L"Die Anwendung läuft nur in einer Instanz. Ein erneuter Start stellt das minimierte Steuerfenster "
    L"wieder her und bringt es in den Vordergrund. Mit Tab und Umschalt+Tab wechseln Sie zwischen den "
    L"Steuerelementen; mit Alt und dem unterstrichenen Buchstaben rufen Sie einen Befehl auf. Esc schließt "
    L"das aktive Hilfe- oder Infofenster; im Steuerfenster beendet es die Anwendung. Bildschirmschoner bei "
    L"Animation sperren verhindert den Start des Windows-Bildschirmschoners nur, solange die Animation "
    L"tatsächlich sichtbar und nicht angehalten ist.\r\n\r\nSchnappschüsse und Aufnahmen erfassen den ersten "
    L"aktiven Animationsmonitor, nicht die gemeinsame Fläche aller Monitore. PNG verwendet Bilder, MP4 "
    L"Videos; fehlen diese Ordner, wird Dokumente verwendet. Die Schaltfläche Aufnahmeeinstellungen wählt "
    L"Viewport oder TV. Viewport erhält die Abmessungen und Bildwiederholfrequenz des Animationsmonitors bis "
    L"höchstens 60 Bilder pro Sekunde. TV bietet 1920 × 1080, 1440 × 1080 oder 1280 × 720 im Format 16:9 mit "
    L"50, 25, 59.94 (60000/1001) oder 29.97 (30000/1001) Bildern pro Sekunde. Das Seitenverhältnis bleibt "
    L"erhalten; TV verwendet progressives BT.709-Video mit begrenztem Wertebereich und 4:2:0-Abtastung. "
    L"Auflösung und Bildfrequenz sind nur im TV-Modus wählbar. Das Fenster Aufnahmeeinstellungen lässt sich "
    L"minimieren und blockiert die anderen Anwendungsfenster nicht. OK speichert die Auswahl für die nächste "
    L"MP4-Aufnahme; Abbrechen oder Esc verwirft unbestätigte Änderungen. Der aufgezeichnete Monitor kann "
    L"während der Aufnahme nicht abgewählt werden; Änderungen an anderen Monitoren beenden die Aufnahme "
    L"nicht. Das Beenden der Anwendung während einer Aufnahme muss bestätigt werden, da es auch die Aufnahme "
    L"beendet.\r\n\r\nWindows 7 bis Windows 11 unterstützen alle Funktionen einschließlich "
    L"PNG-Schnappschüssen und MP4-Aufnahmen. Zum Ausführen der Anwendung unter Windows Vista SP2 müssen die "
    L"Updates KB971512 und KB2117917 installiert werden. MP4-Aufnahmen funktionieren unter Vista in der "
    L"aktuellen Version nicht.",
    L"FlyingSolids affiche des solides 3D éclairés. Les curseurs règlent la vitesse des objets et de la "
    L"caméra de 0 à 1 600 %, une à dix copies de chaque solide et une taille de 50 à 200 %. Choisissez "
    L"Observation de l’espace ou le Vol dans l’espace rectiligne, puis activez les solides voulus. Les cases "
    L"Éclairage principal, Éclairage d’appoint, Éclairage ambiant et Éclairage des contours sous les "
    L"curseurs contrôlent indépendamment l’éclairage de toute la scène. L’éclairage ambiant fournit une "
    L"luminosité de base aux surfaces, et l’éclairage des contours souligne leurs bords. Par défaut, les "
    L"éclairages principal, ambiant et des contours sont activés, et l’éclairage d’appoint est désactivé. "
    L"Les réglages sont enregistrés séparément pour l’application et l’économiseur "
    L"d’écran.\r\n\r\nSélectionnez plusieurs moniteurs dans la liste ; un double-clic active ou désactive un "
    L"moniteur, et vous pouvez tous les désélectionner. Chaque moniteur utilise une scène indépendante. "
    L"Capture enregistre un PNG et le bouton d’enregistrement démarre ou arrête un MP4. Pause arrête "
    L"l’animation. L’application installe ou désinstalle aussi son économiseur intégré. Les réglages sont "
    L"enregistrés en continu. Une seule instance de l’application peut fonctionner à la fois. Un nouveau "
    L"lancement restaure la fenêtre de contrôle réduite et la place au premier plan. Utilisez Tab et Maj+Tab "
    L"pour passer d’un contrôle à l’autre ; Alt et la lettre soulignée activent une commande. Échap ferme la "
    L"fenêtre d’aide ou À propos active ; dans la fenêtre de contrôle, cette touche quitte l’application. "
    L"Bloquer l’écran de veille pendant l’animation empêche le lancement de l’économiseur d’écran Windows "
    L"uniquement lorsque l’animation est réellement visible et n’est pas en pause.\r\n\r\nLes captures et "
    L"les enregistrements utilisent le premier moniteur d’animation actif, et non une image combinant tous "
    L"les moniteurs. PNG utilise Images, MP4 Vidéos ; Documents sert de repli si ces dossiers n’existent "
    L"pas. Le bouton Réglages vidéo permet de choisir Viewport ou TV. Viewport conserve les dimensions et la "
    L"fréquence de rafraîchissement du moniteur d’animation, jusqu’à 60 images par seconde. TV propose 1920 "
    L"× 1080, 1440 × 1080 ou 1280 × 720 au format 16:9, à 50, 25, 59.94 (60000/1001) ou 29.97 (30000/1001) "
    L"images par seconde. Le rapport d’aspect est conservé ; TV utilise une vidéo progressive BT.709 à plage "
    L"limitée et sous-échantillonnage 4:2:0. La résolution et la fréquence d’images ne sont disponibles "
    L"qu’en mode TV. La fenêtre Réglages vidéo peut être réduite et ne bloque pas les autres fenêtres de "
    L"l’application. OK enregistre les choix pour le prochain enregistrement MP4 ; Annuler ou Échap "
    L"abandonne les modifications non confirmées. Le moniteur enregistré ne peut pas être désélectionné "
    L"pendant l’enregistrement ; les changements concernant les autres moniteurs ne l’arrêtent pas. Fermer "
    L"l’application pendant un enregistrement nécessite une confirmation, car cela arrête aussi "
    L"l’enregistrement.\r\n\r\nWindows 7 à Windows 11 prennent en charge toutes les fonctions, y compris les "
    L"captures PNG et l’enregistrement MP4. Pour exécuter l’application sous Windows Vista SP2, il est "
    L"nécessaire d’installer les mises à jour KB971512 et KB2117917. L’enregistrement MP4 ne fonctionne pas "
    L"sous Vista dans la version actuelle.",
    L"FlyingSolids muestra sólidos 3D iluminados. Los controles ajustan la velocidad de objetos y cámara "
    L"entre 0 y 1600 %, de una a diez copias y el tamaño entre 50 y 200 %. Elija Observación del espacio o "
    L"el Vuelo por el espacio en línea recta y active los sólidos deseados. Las casillas Luz principal, Luz "
    L"de relleno, Luz ambiental e Iluminación de contornos bajo los controles deslizantes controlan de forma "
    L"independiente la iluminación de toda la escena. La luz ambiental aporta iluminación básica a las "
    L"superficies y la iluminación de contornos resalta sus bordes. De forma predeterminada, las luces "
    L"principal, ambiental y de contornos están activadas, y la luz de relleno está desactivada. Los ajustes "
    L"se guardan por separado para la aplicación y el salvapantallas.\r\n\r\nSeleccione varios monitores en "
    L"la lista; un doble clic alterna la animación en un monitor y también puede desmarcarlos todos. Cada "
    L"monitor usa una escena independiente. Captura guarda un PNG y el botón de grabación inicia o detiene "
    L"un MP4. Pausar detiene la animación. La aplicación instala o desinstala además el salvapantallas "
    L"incorporado. Los ajustes se guardan continuamente. La aplicación solo permite una instancia. Al volver "
    L"a iniciarla, restaura la ventana de control minimizada y la trae al primer plano. Use Tab y Mayús+Tab "
    L"para desplazarse entre controles; Alt y la letra subrayada activan una opción. Esc cierra la ventana "
    L"activa de Ayuda o Acerca de; en la ventana de control, sale de la aplicación. Bloquear salvapantallas "
    L"durante la animación impide que se inicie el salvapantallas de Windows solo mientras la animación está "
    L"realmente visible y no está en pausa.\r\n\r\nLas capturas y grabaciones usan el primer monitor de "
    L"animación activo, no una imagen conjunta de todos los monitores. PNG usa Imágenes y MP4 Vídeos; si no "
    L"existen esas carpetas, se usa Documentos. El botón Ajustes de grabación permite elegir Viewport o TV. "
    L"Viewport conserva las dimensiones y la frecuencia de actualización del monitor de animación, hasta 60 "
    L"fotogramas por segundo. TV ofrece 1920 × 1080, 1440 × 1080 o 1280 × 720 en formato 16:9, a 50, 25, "
    L"59.94 (60000/1001) o 29.97 (30000/1001) fotogramas por segundo. Se conserva la relación de aspecto; TV "
    L"usa vídeo progresivo BT.709 de rango limitado y submuestreo 4:2:0. La resolución y la frecuencia solo "
    L"están disponibles en modo TV. La ventana Ajustes de grabación se puede minimizar y no bloquea las "
    L"demás ventanas de la aplicación. Aceptar guarda las opciones para la próxima grabación MP4; Cancelar o "
    L"Esc descarta los cambios sin confirmar. El monitor grabado no se puede desmarcar durante la grabación; "
    L"cambiar otros monitores no la detiene. Cerrar la aplicación durante una grabación requiere "
    L"confirmación porque también detiene la grabación.\r\n\r\nWindows 7 a Windows 11 admiten todas las "
    L"funciones, incluidas las capturas PNG y la grabación MP4. Para ejecutar la aplicación en Windows Vista "
    L"SP2, es necesario instalar las actualizaciones KB971512 y KB2117917. La grabación MP4 no funciona en "
    L"Vista en la versión actual.",
    L"FlyingSolids mostra solidi 3D illuminati. I cursori regolano la velocità di oggetti e camera tra 0 e "
    L"1600 %, da una a dieci copie e la dimensione tra 50 e 200 %. Scegliere Osservazione dello spazio o il "
    L"Volo nello spazio rettilineo e attivare i solidi desiderati. Le caselle Luce principale, Luce di "
    L"riempimento, Luce ambientale e Illuminazione dei contorni sotto i cursori controllano "
    L"indipendentemente l’illuminazione dell’intera scena. La luce ambientale fornisce un’illuminazione di "
    L"base alle superfici, mentre quella dei contorni ne evidenzia i bordi. Per impostazione predefinita, le "
    L"luci principale, ambientale e dei contorni sono attive e la luce di riempimento è disattivata. Le "
    L"impostazioni vengono salvate separatamente per l’applicazione e il salvaschermo.\r\n\r\nNell’elenco si "
    L"possono selezionare più monitor; un doppio clic attiva o disattiva l’animazione su un monitor, ed è "
    L"possibile deselezionarli tutti. Ogni monitor usa una scena indipendente. Istantanea salva un PNG e il "
    L"pulsante di registrazione avvia o arresta un MP4. Pausa ferma l’animazione. L’applicazione installa o "
    L"disinstalla anche il salvaschermo incorporato. Le impostazioni vengono salvate continuamente. "
    L"L’applicazione può essere eseguita in una sola istanza. Un nuovo avvio ripristina la finestra di "
    L"controllo ridotta a icona e la porta in primo piano. Usare Tab e Maiusc+Tab per passare tra i "
    L"controlli; Alt e la lettera sottolineata attivano un comando. Esc chiude la finestra attiva di Guida o "
    L"Informazioni; nella finestra di controllo, termina l’applicazione. Blocca salvaschermo durante "
    L"l’animazione impedisce l’avvio del salvaschermo di Windows solo quando l’animazione è realmente "
    L"visibile e non è in pausa.\r\n\r\nIstantanee e registrazioni usano il primo monitor di animazione "
    L"attivo, non un’immagine combinata di tutti i monitor. PNG usa Immagini, MP4 Video; se tali cartelle "
    L"non esistono, viene usata Documenti. Il pulsante Impostazioni video permette di scegliere Viewport o "
    L"TV. Viewport mantiene le dimensioni e la frequenza di aggiornamento del monitor di animazione, fino a "
    L"60 fotogrammi al secondo. TV offre 1920 × 1080, 1440 × 1080 o 1280 × 720 in formato 16:9, a 50, 25, "
    L"59.94 (60000/1001) o 29.97 (30000/1001) fotogrammi al secondo. Le proporzioni sono mantenute; TV usa "
    L"video progressivo BT.709 con intervallo limitato e campionamento 4:2:0. Risoluzione e frequenza sono "
    L"disponibili solo in modalità TV. La finestra Impostazioni video può essere ridotta a icona e non "
    L"blocca le altre finestre dell’applicazione. OK salva le opzioni per la prossima registrazione MP4; "
    L"Annulla o Esc scarta le modifiche non confermate. Il monitor registrato non può essere deselezionato "
    L"durante la registrazione; le modifiche agli altri monitor non la interrompono. Chiudere l’applicazione "
    L"durante una registrazione richiede conferma, perché interrompe anche la registrazione.\r\n\r\nI "
    L"sistemi da Windows 7 a Windows 11 supportano tutte le funzioni, comprese le istantanee PNG e la "
    L"registrazione MP4. Per eseguire l’applicazione su Windows Vista SP2, è necessario installare gli "
    L"aggiornamenti KB971512 e KB2117917. La registrazione MP4 non funziona in Vista nella versione attuale.",
    L"FlyingSolids wyświetla oświetlone pełne bryły 3D. Suwaki ustawiają prędkość obiektów i kamery od 0 do "
    L"1600%, od jednej do dziesięciu kopii i rozmiar od 50 do 200%. Wybierz Obserwację przestrzeni lub "
    L"prostoliniowy Przelot przez przestrzeń i włącz potrzebne bryły. Pola wyboru Światło główne, Światło "
    L"wypełniające, Światło otoczenia i Oświetlenie konturów pod suwakami niezależnie sterują oświetleniem "
    L"całej sceny. Światło otoczenia zapewnia podstawową jasność powierzchni, a oświetlenie konturów "
    L"podkreśla krawędzie. Domyślnie światło główne, światło otoczenia i oświetlenie konturów są włączone, a "
    L"światło wypełniające jest wyłączone. Ustawienia są zapisywane osobno dla aplikacji i wygaszacza "
    L"ekranu.\r\n\r\nNa liście można zaznaczyć wiele monitorów; podwójne kliknięcie przełącza animację na "
    L"monitorze, można też odznaczyć wszystkie. Każdy monitor ma niezależną scenę. Zrzut zapisuje PNG, a "
    L"przycisk nagrywania rozpoczyna lub kończy MP4. Wstrzymaj zatrzymuje animację. Aplikacja instaluje i "
    L"odinstalowuje również wbudowany wygaszacz. Ustawienia są zapisywane na bieżąco. Aplikacja działa tylko "
    L"w jednej instancji. Kolejne uruchomienie przywraca zminimalizowane okno sterowania i przenosi na "
    L"pierwszy plan. Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera "
    L"wywołują polecenie. Esc zamyka aktywne okno Pomocy lub O programie; w oknie sterowania kończy "
    L"działanie aplikacji. Blokuj wygaszacz podczas animacji zapobiega uruchomieniu wygaszacza Windows tylko "
    L"wtedy, gdy animacja jest rzeczywiście widoczna i nie jest wstrzymana.\r\n\r\nZrzuty i nagrania "
    L"obejmują pierwszy aktywny monitor animacji, a nie wspólny obraz wszystkich monitorów. PNG używa "
    L"folderu Obrazy, MP4 folderu Wideo; jeśli ich nie ma, używane są Dokumenty. Przycisk Ustawienia "
    L"nagrywania pozwala wybrać Viewport lub TV. Viewport zachowuje rozmiar i częstotliwość odświeżania "
    L"monitora animacji, do 60 klatek na sekundę. TV oferuje 1920 × 1080, 1440 × 1080 lub 1280 × 720 w "
    L"formacie 16:9, z 50, 25, 59.94 (60000/1001) lub 29.97 (30000/1001) klatkami na sekundę. Proporcje "
    L"obrazu są zachowane; TV używa progresywnego obrazu BT.709 z ograniczonym zakresem i próbkowaniem "
    L"4:2:0. Rozdzielczość i liczba klatek są dostępne tylko w trybie TV. Okno Ustawienia nagrywania można "
    L"zminimalizować i nie blokuje ono innych okien aplikacji. OK zapisuje wybór dla następnego nagrania "
    L"MP4; Anuluj lub Esc odrzuca niepotwierdzone zmiany. Podczas nagrywania nie można odznaczyć nagrywanego "
    L"monitora; zmiany pozostałych monitorów nie przerywają nagrania. Zamknięcie aplikacji podczas "
    L"nagrywania wymaga potwierdzenia, ponieważ kończy również nagranie.\r\n\r\nSystemy od Windows 7 do "
    L"Windows 11 obsługują wszystkie funkcje, w tym zrzuty PNG i nagrywanie MP4. Do uruchomienia aplikacji w "
    L"systemie Windows Vista SP2 konieczne jest zainstalowanie aktualizacji KB971512 i KB2117917. Nagrywanie "
    L"MP4 nie działa w Vista w obecnej wersji.",
    L"FlyingSolids zobrazuje osvetlené plné 3D telesá. Jazdce nastavujú rýchlosť objektov a kamery 0–1600 %, "
    L"jednu až desať kópií a veľkosť 50–200 %. Vyberte Pozorovanie priestoru alebo priamy Prelet priestorom "
    L"a zapnite požadované telesá. Začiarkavacie políčka Hlavné svetlo, Doplnkové svetlo, Základný jas a "
    L"Prisvetlenie obrysov pod jazdcami nezávisle ovládajú osvetlenie celej scény. Základný jas prisvetľuje "
    L"povrchy telies a prisvetlenie obrysov zvýrazňuje ich okraje. Predvolene sú hlavné svetlo, základný jas "
    L"a prisvetlenie obrysov zapnuté a doplnkové svetlo vypnuté. Nastavenia osvetlenia sa ukladajú zvlášť "
    L"pre aplikáciu a šetrič obrazovky.\r\n\r\nV zozname možno označiť viac monitorov; dvojklik zapína alebo "
    L"vypína animáciu na monitore a možno zrušiť aj výber všetkých. Každý monitor používa nezávislú scénu. "
    L"Snímka uloží PNG a tlačidlo záznamu spustí alebo ukončí MP4. Pozastavenie zastaví animáciu. Aplikácia "
    L"tiež nainštaluje alebo odinštaluje vložený šetrič. Nastavenia sa ukladajú priebežne. Aplikácia beží "
    L"iba v jednej inštancii. Ďalšie spustenie obnoví minimalizované ovládacie okno a prenesie do popredia. "
    L"Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou "
    L"Alt a príslušného písmena. Esc zavrie aktívne okno Pomocníka alebo O aplikácii; v ovládacom okne "
    L"ukončí aplikáciu. Voľba Blokovať šetrič pri animácii bráni spusteniu šetriča Windows iba vtedy, keď je "
    L"animácia skutočne viditeľná a nie je pozastavená.\r\n\r\nSnímky a záznamy zachytávajú prvý aktívny "
    L"animačný monitor, nie spoločnú plochu všetkých monitorov. PNG používa Obrázky, MP4 Videá; ak tieto "
    L"priečinky neexistujú, použijú sa Dokumenty. Tlačidlo Nastavenie záznamu vyberá Viewport alebo TV. "
    L"Viewport zachováva rozmery animačného monitora a jeho obnovovaciu frekvenciu, najviac 60 snímok za "
    L"sekundu. TV ponúka rozlíšenie 1920 × 1080, 1440 × 1080 alebo 1280 × 720 v pomere 16:9 a frekvenciu 50, "
    L"25, 59.94 (60000/1001) alebo 29.97 (30000/1001) snímok za sekundu. Obraz zachováva pomer strán; TV "
    L"používa progresívne video BT.709 s obmedzeným rozsahom a vzorkovaním 4:2:0. Rozlíšenie a snímkovú "
    L"frekvenciu možno vybrať iba v režime TV. Okno Nastavenie záznamu možno minimalizovať a neblokuje "
    L"ostatné okná aplikácie. OK uloží voľby pre nasledujúci záznam MP4; Zrušiť alebo Esc zahodí nepotvrdené "
    L"zmeny. Nahrávaný monitor nemožno počas záznamu odpojiť; zmeny ostatných monitorov záznam nezastavia. "
    L"Ukončenie aplikácie počas záznamu vyžaduje potvrdenie, pretože ukončí aj záznam.\r\n\r\nWindows 7 až "
    L"Windows 11 podporujú všetky funkcie vrátane snímok PNG a záznamu MP4. Na spustenie aplikácie v systéme "
    L"Windows Vista SP2 je potrebné nainštalovať aktualizácie KB971512 a KB2117917. Záznam MP4 na Viste v "
    L"súčasnej verzii nefunguje.",
    L"FlyingSolids displays illuminated solid 3D objects. The sliders set object and camera speed from "
    L"0–1600%, one to ten copies and size from 50–200%. Choose Space observation or the straight Fly through "
    L"space mode and enable the required objects. The Main light, Fill light, Ambient light, and Rim light "
    L"checkboxes below the sliders independently control lighting for the whole scene. Ambient light "
    L"provides base illumination of object surfaces; rim light highlights their edges. By default, main, "
    L"ambient, and rim light are on, and fill light is off. Lighting settings are stored separately for the "
    L"application and screen saver.\r\n\r\nSelect several displays; double-click a row to toggle it, or "
    L"clear the selection for all displays. Each display uses an independent scene. Snapshot saves PNG and "
    L"the recording button starts or stops MP4. Pause stops the animation. The application also installs or "
    L"uninstalls its embedded screen saver. Settings are saved continuously. Only one instance of the "
    L"application runs at a time. Launching it again restores its minimised control window and brings it to "
    L"the foreground. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to "
    L"activate a command. Esc closes the active Help or About window; in the control window, it exits the "
    L"application. Prevent screen saver during animation blocks the Windows screen saver only while the "
    L"animation is actually visible and not paused.\r\n\r\nSnapshots and recordings capture the first active "
    L"animation display, not a combined image of all displays. PNG uses Pictures and MP4 uses Videos, with "
    L"Documents as the fallback if those folders do not exist. The Recording settings button selects "
    L"Viewport or TV. Viewport preserves the animation display’s dimensions and refresh rate, up to 60 "
    L"frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 "
    L"(60000/1001) or 29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV uses "
    L"progressive BT.709 limited-range 4:2:0 video. Resolution and frame rate are available only in TV mode. "
    L"The Recording settings window can be minimised and does not block the other application windows. OK "
    L"saves choices for the next MP4 recording; Cancel or Esc discards unconfirmed changes. The recorded "
    L"display cannot be detached during recording; changes to other displays do not stop the recording. "
    L"Closing the application while recording requires confirmation because it also stops the "
    L"recording.\r\n\r\nWindows 7 through Windows 11 support all features, including PNG snapshots and MP4 "
    L"recording. To run the application on Windows Vista SP2, you must install updates KB971512 and "
    L"KB2117917. MP4 recording does not work on Vista in the current version.",
    L"FlyingSolids displays illuminated solid 3D objects. The sliders set object and camera speed from "
    L"0–1600%, one to ten copies and size from 50–200%. Choose Space observation or the straight Fly through "
    L"space mode and enable the required objects. The Main light, Fill light, Ambient light, and Rim light "
    L"checkboxes below the sliders independently control lighting for the whole scene. Ambient light "
    L"provides base illumination of object surfaces; rim light highlights their edges. By default, main, "
    L"ambient, and rim light are on, and fill light is off. Lighting settings are stored separately for the "
    L"application and screen saver.\r\n\r\nSelect several displays; double-click a row to toggle it, or "
    L"clear the selection for all displays. Each display uses an independent scene. Snapshot saves PNG and "
    L"the recording button starts or stops MP4. Pause stops the animation. The application also installs or "
    L"uninstalls its embedded screen saver. Settings are saved continuously. Only one instance of the "
    L"application runs at a time. Launching it again restores its minimised control window and brings it to "
    L"the foreground. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to "
    L"activate a command. Esc closes the active Help or About window; in the control window, it exits the "
    L"application. Prevent screen saver during animation blocks the Windows screen saver only while the "
    L"animation is actually visible and not paused.\r\n\r\nSnapshots and recordings capture the first active "
    L"animation display, not a combined image of all displays. PNG uses Pictures and MP4 uses Videos, with "
    L"Documents as the fallback if those folders do not exist. The Recording settings button selects "
    L"Viewport or TV. Viewport preserves the animation display’s dimensions and refresh rate, up to 60 "
    L"frames per second. TV offers 1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 "
    L"(60000/1001) or 29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV uses "
    L"progressive BT.709 limited-range 4:2:0 video. Resolution and frame rate are available only in TV mode. "
    L"The Recording settings window can be minimised and does not block the other application windows. OK "
    L"saves choices for the next MP4 recording; Cancel or Esc discards unconfirmed changes. The recorded "
    L"display cannot be detached during recording; changes to other displays do not stop the recording. "
    L"Closing the application while recording requires confirmation because it also stops the "
    L"recording.\r\n\r\nWindows 7 through Windows 11 support all features, including PNG snapshots and MP4 "
    L"recording. To run the application on Windows Vista SP2, you must install updates KB971512 and "
    L"KB2117917. MP4 recording does not work on Vista in the current version.",
    L"O FlyingSolids mostra sólidos 3D iluminados. Os controlos regulam a velocidade dos objetos e da câmara "
    L"entre 0 e 1600%, uma a dez cópias e o tamanho entre 50 e 200%. Escolha Observação do espaço ou o Voo "
    L"pelo espaço em linha reta e ative os sólidos pretendidos. As caixas Luz principal, Luz de "
    L"preenchimento, Luz ambiente e Iluminação dos contornos sob os controlos deslizantes controlam a "
    L"iluminação de toda a cena de forma independente. A luz ambiente fornece iluminação de base às "
    L"superfícies e a iluminação dos contornos realça os seus limites. Por predefinição, as luzes principal, "
    L"ambiente e dos contornos estão ligadas e a luz de preenchimento está desligada. As definições são "
    L"guardadas separadamente para a aplicação e a proteção de ecrã.\r\n\r\nSelecione vários monitores; um "
    L"duplo clique alterna uma linha e todos podem ser desmarcados. Cada monitor usa uma cena independente. "
    L"Captura guarda PNG e o botão de gravação inicia ou termina MP4. Pausa para a animação. A aplicação "
    L"também instala ou desinstala a proteção de ecrã incorporada. As definições são guardadas "
    L"continuamente. A aplicação só pode ter uma instância em execução. Um novo arranque restaura a janela "
    L"de controlo minimizada e coloca-a em primeiro plano. Use Tab e Shift+Tab para passar entre controlos; "
    L"Alt e a letra sublinhada ativam um comando. Esc fecha a janela ativa de Ajuda ou Acerca de; na janela "
    L"de controlo, termina a aplicação. Bloquear proteção de ecrã durante a animação impede o início da "
    L"proteção de ecrã do Windows apenas enquanto a animação está efetivamente visível e não está em "
    L"pausa.\r\n\r\nAs capturas e gravações usam o primeiro monitor de animação ativo, não uma imagem "
    L"conjunta de todos os monitores. PNG usa Imagens, MP4 Vídeos; se essas pastas não existirem, usa-se "
    L"Documentos. O botão Definições de gravação permite escolher Viewport ou TV. Viewport conserva as "
    L"dimensões e a frequência de atualização do monitor de animação, até 60 fotogramas por segundo. TV "
    L"oferece 1920 × 1080, 1440 × 1080 ou 1280 × 720 no formato 16:9, a 50, 25, 59.94 (60000/1001) ou 29.97 "
    L"(30000/1001) fotogramas por segundo. A proporção da imagem é mantida; TV usa vídeo progressivo BT.709 "
    L"com intervalo limitado e amostragem 4:2:0. A resolução e a frequência só estão disponíveis no modo TV. "
    L"A janela Definições de gravação pode ser minimizada e não bloqueia as outras janelas da aplicação. OK "
    L"guarda as escolhas para a próxima gravação MP4; Cancelar ou Esc descarta as alterações não "
    L"confirmadas. O monitor gravado não pode ser desmarcado durante a gravação; as alterações aos outros "
    L"monitores não a interrompem. Fechar a aplicação durante uma gravação exige confirmação, pois também "
    L"termina a gravação.\r\n\r\nOs sistemas Windows 7 a Windows 11 suportam todas as funcionalidades, "
    L"incluindo capturas PNG e gravação MP4. Para executar a aplicação no Windows Vista SP2, é necessário "
    L"instalar as atualizações KB971512 e KB2117917. A gravação MP4 não funciona no Vista na versão atual.",
    L"FlyingSolids viser belyste solide 3D-legemer. Glidebryterne angir objekt- og kamerahastighet fra "
    L"0–1600 %, én til ti kopier og størrelse fra 50–200 %. Velg Romobservasjon eller Flyging gjennom rommet "
    L"i rett linje og aktiver ønskede legemer. Avmerkingsboksene Hovedlys, Utfyllingslys, Omgivelseslys og "
    L"Konturlys under glidebryterne styrer belysningen i hele scenen uavhengig av hverandre. Omgivelseslys "
    L"gir grunnbelysning på overflatene, og konturlys fremhever kantene. Som standard er hovedlys, "
    L"omgivelseslys og konturlys på, og utfyllingslys av. Innstillingene lagres separat for programmet og "
    L"skjermspareren.\r\n\r\nVelg flere skjermer i listen; dobbeltklikk en rad for å slå animasjonen av "
    L"eller på, eller fjern valget for alle. Hver skjerm bruker en uavhengig scene. Skjermbilde lagrer PNG, "
    L"og opptaksknappen starter eller stopper MP4. Pause stanser animasjonen. Programmet installerer eller "
    L"avinstallerer også den innebygde skjermspareren. Innstillingene lagres fortløpende. Bare én instans av "
    L"programmet kan kjøre om gangen. En ny start gjenoppretter det minimerte kontrollvinduet og bringer det "
    L"fremst. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede bokstaven "
    L"aktiverer en kommando. Esc lukker det aktive Hjelp- eller Om-vinduet; i kontrollvinduet avslutter det "
    L"programmet. Hindre skjermsparer under animasjon hindrer Windows-skjermspareren i å starte bare når "
    L"animasjonen faktisk er synlig og ikke er satt på pause.\r\n\r\nSkjermbilder og opptak bruker den "
    L"første aktive animasjonsskjermen, ikke et samlet bilde av alle skjermene. PNG bruker Bilder, MP4 "
    L"Videoer; hvis disse mappene ikke finnes, brukes Dokumenter. Knappen Opptaksinnstillinger velger "
    L"Viewport eller TV. Viewport beholder animasjonsskjermens størrelse og oppdateringsfrekvens, opptil 60 "
    L"bilder per sekund. TV tilbyr 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9, med 50, 25, "
    L"59.94 (60000/1001) eller 29.97 (30000/1001) bilder per sekund. Bildets proporsjoner beholdes; TV "
    L"bruker progressiv BT.709-video med begrenset område og 4:2:0-sampling. Oppløsning og bildefrekvens er "
    L"bare tilgjengelige i TV-modus. Vinduet Opptaksinnstillinger kan minimeres og blokkerer ikke de andre "
    L"programvinduene. OK lagrer valgene for neste MP4-opptak; Avbryt eller Esc forkaster ubekreftede "
    L"endringer. Skjermen som tas opp, kan ikke velges bort under opptaket; endringer på andre skjermer "
    L"stopper ikke opptaket. Å avslutte programmet under et opptak krever bekreftelse, fordi det også "
    L"avslutter opptaket.\r\n\r\nWindows 7 til Windows 11 støtter alle funksjoner, inkludert "
    L"PNG-skjermbilder og MP4-opptak. For å kjøre programmet på Windows Vista SP2 må oppdateringene KB971512 "
    L"og KB2117917 installeres. MP4-opptak fungerer ikke på Vista i den gjeldende versjonen.",
    L"FlyingSolids visar belysta solida 3D-kroppar. Reglagen ställer in objekt- och kamerahastighet 0–1600 "
    L"%, en till tio kopior och storlek 50–200 %. Välj Rymdobservation eller Flygning genom rymden i rak "
    L"linje och aktivera önskade kroppar. Kryssrutorna Huvudljus, Upplättningsljus, Omgivningsljus och "
    L"Konturljus under reglagen styr belysningen i hela scenen oberoende av varandra. Omgivningsljus ger "
    L"grundbelysning på ytorna och konturljus framhäver kanterna. Som standard är huvudljus, omgivningsljus "
    L"och konturljus på och upplättningsljus av. Inställningarna sparas separat för programmet och "
    L"skärmsläckaren.\r\n\r\nVälj flera bildskärmar i listan; dubbelklicka en rad för att slå på eller av "
    L"animeringen, eller avmarkera alla. Varje bildskärm använder en oberoende scen. Skärmbild sparar PNG "
    L"och inspelningsknappen startar eller stoppar MP4. Paus stannar animeringen. Programmet installerar "
    L"eller avinstallerar även den inbyggda skärmsläckaren. Inställningarna sparas fortlöpande. Programmet "
    L"kan bara köras i en instans åt gången. En ny start återställer det minimerade kontrollfönstret och för "
    L"det längst fram. Använd Tab och Skift+Tab för att flytta mellan kontrollerna; Alt och den understrukna "
    L"bokstaven aktiverar ett kommando. Esc stänger det aktiva Hjälp- eller Om-fönstret; i kontrollfönstret "
    L"avslutar det programmet. Blockera skärmsläckare under animering hindrar Windows-skärmsläckaren från "
    L"att starta endast när animeringen faktiskt är synlig och inte är pausad.\r\n\r\nSkärmbilder och "
    L"inspelningar använder den första aktiva animeringsskärmen, inte en sammanslagen bild av alla skärmar. "
    L"PNG använder Bilder, MP4 Videor; om dessa mappar saknas används Dokument. Knappen "
    L"Inspelningsinställningar väljer Viewport eller TV. Viewport behåller animeringsskärmens storlek och "
    L"uppdateringsfrekvens, upp till 60 bilder per sekund. TV erbjuder 1920 × 1080, 1440 × 1080 eller 1280 × "
    L"720 i formatet 16:9, med 50, 25, 59.94 (60000/1001) eller 29.97 (30000/1001) bilder per sekund. "
    L"Bildens proportioner bevaras; TV använder progressiv BT.709-video med begränsat omfång och "
    L"4:2:0-sampling. Upplösning och bildfrekvens kan bara väljas i TV-läge. Fönstret "
    L"Inspelningsinställningar kan minimeras och blockerar inte de andra programfönstren. OK sparar valen "
    L"för nästa MP4-inspelning; Avbryt eller Esc ignorerar obekräftade ändringar. Den inspelade skärmen kan "
    L"inte väljas bort under inspelningen; ändringar av andra skärmar stoppar inte inspelningen. Att avsluta "
    L"programmet under en inspelning kräver bekräftelse eftersom det också avslutar "
    L"inspelningen.\r\n\r\nWindows 7 till Windows 11 stöder alla funktioner, inklusive PNG-skärmbilder och "
    L"MP4-inspelning. För att köra programmet på Windows Vista SP2 måste uppdateringarna KB971512 och "
    L"KB2117917 installeras. MP4-inspelning fungerar inte på Vista i den aktuella versionen.",
    L"FlyingSolids näyttää valaistuja kiinteitä 3D-kappaleita. Liukusäätimillä asetetaan kohteiden ja "
    L"kameran nopeus 0–1600 %, yhdestä kymmeneen kopiota ja koko 50–200 %. Valitse Avaruuden tarkkailu tai "
    L"Lento avaruuden halki suoraan eteenpäin ja ota halutut kappaleet käyttöön. Liukusäätimien alla olevat "
    L"Päävalo-, Täytevalo-, Ympäristövalo- ja Reunavalo-valintaruudut ohjaavat koko näkymän valaistusta "
    L"toisistaan riippumatta. Ympäristövalo antaa pinnoille perusvalaistuksen ja reunavalo korostaa reunoja. "
    L"Oletuksena päävalo, ympäristövalo ja reunavalo ovat päällä ja täytevalo pois päältä. Asetukset "
    L"tallennetaan erikseen sovellukselle ja näytönsäästäjälle.\r\n\r\nLuettelosta voi valita useita "
    L"näyttöjä; kaksoisnapsautus vaihtaa rivin tilaa ja kaikkien näyttöjen valinnan voi poistaa. Jokaisella "
    L"näytöllä on itsenäinen näkymä. Tilannekuva tallentaa PNG:n ja tallennuspainike käynnistää tai lopettaa "
    L"MP4:n. Keskeytä pysäyttää animaation. Sovellus asentaa tai poistaa myös sisäisen näytönsäästäjän. "
    L"Asetukset tallennetaan jatkuvasti. Sovelluksesta voi olla käynnissä vain yksi instanssi. Uusi "
    L"käynnistys palauttaa pienennetyn ohjausikkunan ja tuo sen etualalle. Siirry säätimien välillä Tab- ja "
    L"Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat komennon. Esc sulkee aktiivisen Ohje- "
    L"tai Tietoja-ikkunan; ohjausikkunassa se sulkee sovelluksen. Estä näytönsäästäjä animaation aikana "
    L"estää Windowsin näytönsäästäjän käynnistymisen vain silloin, kun animaatio on todella näkyvissä eikä "
    L"sitä ole keskeytetty.\r\n\r\nTilannekuvat ja tallenteet käyttävät ensimmäistä aktiivista "
    L"animaationäyttöä, eivät kaikkien näyttöjen yhdistettyä kuvaa. PNG käyttää Kuvat-kansiota ja MP4 "
    L"Videot-kansiota; jos niitä ei ole, käytetään Tiedostot-kansiota. Tallennusasetukset-painikkeella "
    L"valitaan Viewport tai TV. Viewport säilyttää animaationäytön koon ja virkistystaajuuden, enintään 60 "
    L"kuvaa sekunnissa. TV tarjoaa tarkkuudet 1920 × 1080, 1440 × 1080 ja 1280 × 720 kuvasuhteella 16:9 sekä "
    L"taajuudet 50, 25, 59.94 (60000/1001) ja 29.97 (30000/1001) kuvaa sekunnissa. Kuvasuhde säilyy; TV "
    L"käyttää progressiivista BT.709-videota rajatulla alueella ja 4:2:0-näytteistyksellä. Tarkkuus ja "
    L"kuvataajuus ovat valittavissa vain TV-tilassa. Tallennusasetukset-ikkunan voi pienentää, eikä se estä "
    L"muiden sovellusikkunoiden käyttöä. OK tallentaa valinnat seuraavaa MP4-tallennusta varten; Peruuta tai "
    L"Esc hylkää vahvistamattomat muutokset. Tallennettavan näytön valintaa ei voi poistaa tallennuksen "
    L"aikana; muiden näyttöjen muutokset eivät pysäytä tallennusta. Sovelluksen sulkeminen tallennuksen "
    L"aikana vaatii vahvistuksen, sillä myös tallennus päättyy.\r\n\r\nWindows 7–Windows 11 tukevat kaikkia "
    L"toimintoja, myös PNG-tilannekuvia ja MP4-tallennusta. Sovelluksen suorittaminen Windows Vista SP2:ssa "
    L"edellyttää päivitysten KB971512 ja KB2117917 asentamista. MP4-tallennus ei toimi Vistassa nykyisessä "
    L"versiossa.",
    L"FlyingSolids viser belyste solide 3D-legemer. Skyderne indstiller objekt- og kamerahastighed 0–1600 %, "
    L"en til ti kopier og størrelse 50–200 %. Vælg Rumobservation eller Flyvning gennem rummet i en lige "
    L"linje og aktivér de ønskede legemer. Afkrydsningsfelterne Hovedlys, Udfyldningslys, Omgivende lys og "
    L"Konturlys under skyderne styrer belysningen af hele scenen uafhængigt af hinanden. Omgivende lys giver "
    L"overfladerne en grundbelysning, og konturlys fremhæver kanterne. Som standard er hovedlys, omgivende "
    L"lys og konturlys slået til og udfyldningslys slået fra. Indstillingerne gemmes separat for programmet "
    L"og pauseskærmen.\r\n\r\nVælg flere skærme i listen; dobbeltklik på en række for at slå animationen til "
    L"eller fra, eller fravælg alle. Hver skærm bruger en uafhængig scene. Skærmbillede gemmer PNG, og "
    L"optageknappen starter eller stopper MP4. Pause standser animationen. Programmet installerer eller "
    L"afinstallerer også den indbyggede pauseskærm. Indstillinger gemmes løbende. Programmet kan kun køre i "
    L"én instans ad gangen. En ny start gendanner det minimerede kontrolvindue og bringer det forrest. Brug "
    L"Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det understregede bogstav aktiverer en "
    L"kommando. Esc lukker det aktive Hjælp- eller Om-vindue; i kontrolvinduet afslutter det programmet. "
    L"Blokér pauseskærm under animation forhindrer Windows-pauseskærmen i at starte, men kun når animationen "
    L"faktisk er synlig og ikke er sat på pause.\r\n\r\nSkærmbilleder og optagelser bruger den første aktive "
    L"animationsskærm, ikke et samlet billede af alle skærme. PNG bruger Billeder, MP4 Videoer; hvis disse "
    L"mapper ikke findes, bruges Dokumenter. Knappen Optagelsesindstillinger vælger Viewport eller TV. "
    L"Viewport bevarer animationsskærmens størrelse og opdateringsfrekvens, højst 60 billeder i sekundet. TV "
    L"tilbyder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9 med 50, 25, 59.94 (60000/1001) "
    L"eller 29.97 (30000/1001) billeder i sekundet. Billedets proportioner bevares; TV bruger progressiv "
    L"BT.709-video med begrænset område og 4:2:0-sampling. Opløsning og billedfrekvens kan kun vælges i "
    L"TV-tilstand. Vinduet Optagelsesindstillinger kan minimeres og blokerer ikke de andre programvinduer. "
    L"OK gemmer valgene til den næste MP4-optagelse; Annuller eller Esc kasserer ubekræftede ændringer. Den "
    L"skærm, der optages, kan ikke fravælges under optagelsen; ændringer af andre skærme stopper ikke "
    L"optagelsen. Hvis programmet lukkes under en optagelse, kræves en bekræftelse, fordi optagelsen også "
    L"afsluttes.\r\n\r\nWindows 7 til Windows 11 understøtter alle funktioner, herunder PNG-skærmbilleder og "
    L"MP4-optagelse. For at køre programmet på Windows Vista SP2 skal opdateringerne KB971512 og KB2117917 "
    L"installeres. MP4-optagelse fungerer ikke på Vista i den aktuelle version.",
    L"FlyingSolids sýnir upplýsta heila þrívíddarhluti. Rennistikur stilla hraða hluta og myndavélar á "
    L"0–1600%, eitt til tíu eintök og stærð á 50–200%. Veldu Athugun rýmis eða Flug um rýmið í beinni línu "
    L"og virkjaðu þá hluti sem óskað er eftir. Gátreitirnir Aðalljós, Fylliljós, Umhverfislýsing og "
    L"Útlínulýsing undir rennistikunum stýra lýsingu allrar senunnar óháð hver öðrum. Umhverfislýsing gefur "
    L"yfirborðunum grunnbirtu og útlínulýsing dregur fram jaðrana. Sjálfgefið er kveikt á aðalljósi, "
    L"umhverfislýsingu og útlínulýsingu en slökkt á fylliljósi. Stillingarnar eru vistaðar sérstaklega fyrir "
    L"forritið og skjáhvíluna.\r\n\r\nVelja má marga skjái; tvísmellur virkjar eða slekkur á hreyfimynd á "
    L"skjá og afvelja má alla skjái. Hver skjár notar sjálfstæða senu. Skjámynd vistar PNG og "
    L"upptökuhnappurinn ræsir eða stöðvar MP4. Hnappurinn Gera hlé stöðvar hreyfimyndina. Forritið setur "
    L"einnig upp eða fjarlægir innbyggðu skjáhvíluna. Stillingar vistast jafnóðum. Aðeins eitt eintak af "
    L"forritinu getur verið í gangi í einu. Ný ræsing endurheimtir lágmarkaðan stjórngluggann og færir hann "
    L"fremst. Notaðu Tab og Shift+Tab til að færa þig milli stýrieininga; Alt og undirstrikaður stafur "
    L"virkja skipun. Esc lokar virka Hjálp- eða Um-glugganum; í stjórnglugganum lokar það forritinu. Hindra "
    L"skjáhvílu meðan hreyfimynd er í gangi kemur aðeins í veg fyrir að skjáhvíla Windows fari í gang meðan "
    L"hreyfimyndin er í raun sýnileg og ekki í pásu.\r\n\r\nSkjámyndir og upptökur nota fyrsta virka "
    L"hreyfimyndaskjáinn, ekki sameinaða mynd af öllum skjám. PNG notar Myndir, MP4 Myndbönd; ef þær möppur "
    L"eru ekki til er Skjöl notuð. Hnappurinn Upptökustillingar velur Viewport eða TV. Viewport varðveitir "
    L"stærð og endurnýjunartíðni hreyfimyndaskjásins, þó mest 60 ramma á sekúndu. TV býður upp á 1920 × "
    L"1080, 1440 × 1080 eða 1280 × 720 í hlutfallinu 16:9 með 50, 25, 59.94 (60000/1001) eða 29.97 "
    L"(30000/1001) römmum á sekúndu. Hlutföll myndarinnar haldast; TV notar stigvaxandi BT.709-myndband með "
    L"takmörkuðu sviði og 4:2:0-sýnatöku. Upplausn og rammatíðni eru aðeins valanleg í TV-ham. Hægt er að "
    L"lágmarka gluggann Upptökustillingar og hann hindrar ekki notkun annarra glugga forritsins. Í lagi "
    L"vistar valið fyrir næstu MP4-upptöku; Hætta við eða Esc hendir óstaðfestum breytingum. Ekki er hægt að "
    L"afvelja skjáinn sem er tekinn upp meðan upptaka stendur yfir; breytingar á öðrum skjám stöðva ekki "
    L"upptökuna. Staðfesta þarf lokun forritsins meðan upptaka stendur yfir, því hún stöðvar líka "
    L"upptökuna.\r\n\r\nWindows 7 til Windows 11 styðja alla eiginleika, þar á meðal PNG-skjámyndir og "
    L"MP4-upptöku. Til að keyra forritið á Windows Vista SP2 þarf að setja upp uppfærslurnar KB971512 og "
    L"KB2117917. MP4-upptaka virkar ekki í Vista í núverandi útgáfu.",
    L"FlyingSolids aydınlatılmış katı 3B cisimler gösterir. Kaydırıcılar nesne ve kamera hızını %0–1600, "
    L"kopya sayısını bir ile on ve boyutu %50–200 arasında ayarlar. Uzayı gözlemleme veya doğrusal Uzayda "
    L"uçuş kipini seçip istenen cisimleri etkinleştirin. Kaydırıcıların altındaki Ana ışık, Dolgu ışığı, "
    L"Ortam ışığı ve Kenar aydınlatması onay kutuları tüm sahnenin aydınlatmasını birbirinden bağımsız "
    L"olarak kontrol eder. Ortam ışığı yüzeylere temel aydınlatma sağlar, kenar aydınlatması ise kenarları "
    L"vurgular. Varsayılan olarak ana ışık, ortam ışığı ve kenar aydınlatması açık, dolgu ışığı kapalıdır. "
    L"Ayarlar uygulama ve ekran koruyucu için ayrı ayrı kaydedilir.\r\n\r\nListede birden çok monitör "
    L"seçilebilir; satıra çift tıklamak monitördeki animasyonu açıp kapatır; tüm monitörlerin seçimi de "
    L"kaldırılabilir. Her monitör bağımsız sahne kullanır. Anlık görüntü PNG kaydeder; kayıt düğmesi MP4 "
    L"kaydını başlatır veya bitirir. Duraklat animasyonu durdurur. Uygulama gömülü ekran koruyucuyu da kurar "
    L"veya kaldırır. Ayarlar sürekli kaydedilir. Uygulamanın aynı anda yalnızca bir örneği çalışabilir. "
    L"Yeniden başlatılması, simge durumuna küçültülmüş denetim penceresini geri yükler ve ön plana getirir. "
    L"Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir komutu etkinleştirir. "
    L"Esc, etkin Yardım veya Hakkında penceresini kapatır; denetim penceresinde uygulamadan çıkar. Animasyon "
    L"sırasında ekran koruyucuyu engelle seçeneği, Windows ekran koruyucusunun yalnızca animasyon gerçekten "
    L"görünürken ve duraklatılmamışken başlamasını engeller.\r\n\r\nAnlık görüntüler ve kayıtlar, tüm "
    L"monitörlerin birleşik görüntüsünü değil, ilk etkin animasyon monitörünü kullanır. PNG Resimler, MP4 "
    L"Videolar klasörünü kullanır; bu klasörler yoksa Belgeler kullanılır. Kayıt ayarları düğmesi Viewport "
    L"veya TV seçimini açar. Viewport, animasyon monitörünün boyutlarını ve yenileme hızını saniyede en "
    L"fazla 60 kareyle korur. TV, 16:9 oranında 1920 × 1080, 1440 × 1080 veya 1280 × 720 çözünürlük ile "
    L"saniyede 50, 25, 59.94 (60000/1001) veya 29.97 (30000/1001) kare sunar. Görüntünün en boy oranı "
    L"korunur; TV, sınırlı aralıklı, 4:2:0 örneklemeli ilerlemeli BT.709 video kullanır. Çözünürlük ve kare "
    L"hızı yalnızca TV modunda seçilebilir. Kayıt ayarları penceresi simge durumuna küçültülebilir ve "
    L"uygulamanın diğer pencerelerini engellemez. Tamam, seçenekleri bir sonraki MP4 kaydı için kaydeder; "
    L"İptal veya Esc onaylanmamış değişiklikleri iptal eder. Kayıt sırasında kaydedilen ekranın seçimi "
    L"kaldırılamaz; diğer ekranlardaki değişiklikler kaydı durdurmaz. Kayıt sırasında uygulamayı kapatmak "
    L"kaydı da durduracağı için onay gerektirir.\r\n\r\nWindows 7 ile Windows 11 arasındaki sürümler, PNG "
    L"anlık görüntüler ve MP4 kaydı dâhil tüm özellikleri destekler. Uygulamayı Windows Vista SP2'de "
    L"çalıştırmak için KB971512 ve KB2117917 güncellemelerini yüklemeniz gerekir. Geçerli sürümde MP4 kaydı "
    L"Vista'da çalışmaz."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> SCREEN_SAVER_HELP_TEXTS = {
    L"Vyberte Pozorování prostoru nebo přímý Průlet prostorem. Jezdci nastavují rychlost objektů a kamery "
    L"0–1600 %, jednu až deset kopií každého zapnutého tělesa a velikost 50–200 %. Zatržítka Hlavní světlo, "
    L"Doplňkové světlo, Základní jas a Přisvětlení obrysů pod jezdci nezávisle ovládají osvětlení celé "
    L"scény. Základní jas přisvětluje povrch těles, přisvětlení obrysů zvýrazňuje jejich okraje. Výchozí "
    L"stav: hlavní světlo, základní jas a přisvětlení obrysů zapnuté, doplňkové světlo vypnuté. Nastavení "
    L"osvětlení se ukládá zvlášť pro aplikaci a spořič obrazovky.\r\n\r\nZapněte požadované druhy těles. "
    L"Zapnout náhled spustí celoobrazovkový náhled na všech monitorech; změny lze zkoušet za otevřeného "
    L"nastavení. OK nastavení uloží, Storno je zahodí. Celoobrazovkový spořič ukončíte klávesou Esc nebo "
    L"pohybem myši. Mezi ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat "
    L"pomocí Alt a příslušného písmene. Esc v nastavení odpovídá tlačítku Storno; v nápovědě nebo okně O "
    L"aplikaci zavře pouze toto okno.\r\n\r\nPodporovány jsou systémy Windows 7 až Windows 11. Pro spuštění "
    L"aplikace ve Windows Vista SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917.",
    L"Choose Space observation or the straight Fly through space mode. The sliders set object and camera "
    L"speed from 0–1600%, one to ten copies of each enabled object, and size from 50–200%. The Main light, "
    L"Fill light, Ambient light, and Rim light checkboxes below the sliders independently control lighting "
    L"for the whole scene. Ambient light provides base illumination of object surfaces; rim light highlights "
    L"their edges. By default, main, ambient, and rim light are on, and fill light is off. Lighting settings "
    L"are stored separately for the application and screen saver.\r\n\r\nEnable the required object types. "
    L"Enable preview starts a full-screen preview on every display while the settings dialog remains open "
    L"for live adjustments. OK saves the settings and Cancel discards them. Exit the full-screen saver with "
    L"Esc or mouse movement. Use Tab and Shift+Tab to move between controls; use Alt and the underlined "
    L"letter to activate a command. Esc in the settings dialog is equivalent to Cancel; in Help or About, it "
    L"closes only that window.\r\n\r\nWindows 7 through Windows 11 are supported. To run the application on "
    L"Windows Vista SP2, you must install updates KB971512 and KB2117917.",
    L"Wählen Sie Raumbeobachtung oder Flug durch den Raum in gerader Linie. Die Regler bestimmen Objekt- und "
    L"Kamerageschwindigkeit von 0–1600 %, ein bis zehn Exemplare je aktivem Körper und 50–200 % Größe. Die "
    L"Kontrollkästchen Hauptlicht, Aufhelllicht, Umgebungslicht und Konturlicht unter den Reglern steuern "
    L"die Beleuchtung der gesamten Szene unabhängig voneinander. Umgebungslicht sorgt für eine "
    L"Grundhelligkeit der Körperoberflächen, Konturlicht betont ihre Ränder. Standardmäßig sind Hauptlicht, "
    L"Umgebungslicht und Konturlicht eingeschaltet und Aufhelllicht ausgeschaltet. Die "
    L"Beleuchtungseinstellungen werden für Anwendung und Bildschirmschoner getrennt "
    L"gespeichert.\r\n\r\nAktivieren Sie die gewünschten Körper. Vorschau einschalten startet eine "
    L"Vollbildvorschau auf allen Monitoren. Der Einstellungsdialog bleibt für Änderungen geöffnet. OK "
    L"speichert, Abbrechen verwirft. Esc oder eine Mausbewegung beendet den Vollbildschoner. Mit Tab und "
    L"Umschalt+Tab wechseln Sie zwischen den Steuerelementen; mit Alt und dem unterstrichenen Buchstaben "
    L"rufen Sie einen Befehl auf. Esc im Einstellungsdialog entspricht Abbrechen; in der Hilfe oder im "
    L"Infofenster schließt es nur dieses Fenster.\r\n\r\nUnterstützt werden Windows 7 bis Windows 11. Zum "
    L"Ausführen der Anwendung unter Windows Vista SP2 müssen die Updates KB971512 und KB2117917 installiert "
    L"werden.",
    L"Choisissez Observation de l’espace ou le Vol dans l’espace rectiligne. Les curseurs règlent la vitesse "
    L"des objets et de la caméra de 0 à 1 600 %, une à dix copies et une taille de 50 à 200 %. Les cases "
    L"Éclairage principal, Éclairage d’appoint, Éclairage ambiant et Éclairage des contours sous les "
    L"curseurs contrôlent indépendamment l’éclairage de toute la scène. L’éclairage ambiant fournit une "
    L"luminosité de base aux surfaces, et l’éclairage des contours souligne leurs bords. Par défaut, les "
    L"éclairages principal, ambiant et des contours sont activés, et l’éclairage d’appoint est désactivé. "
    L"Les réglages sont enregistrés séparément pour l’application et l’économiseur d’écran.\r\n\r\nActivez "
    L"les solides voulus. Activer l’aperçu lance un aperçu plein écran sur tous les moniteurs ; la boîte de "
    L"dialogue reste ouverte pour les réglages en direct. OK enregistre les réglages, Annuler les abandonne. "
    L"Échap ou un mouvement de souris quitte le plein écran. Utilisez Tab et Maj+Tab pour passer d’un "
    L"contrôle à l’autre ; Alt et la lettre soulignée activent une commande. Échap dans les réglages "
    L"équivaut à Annuler ; dans l’aide ou À propos, cette touche ferme uniquement cette "
    L"fenêtre.\r\n\r\nWindows 7 à Windows 11 sont pris en charge. Pour exécuter l’application sous Windows "
    L"Vista SP2, il est nécessaire d’installer les mises à jour KB971512 et KB2117917.",
    L"Elija Observación del espacio o Vuelo por el espacio en línea recta. Los controles ajustan la "
    L"velocidad de objetos y cámara del 0 al 1600 %, de una a diez copias y el tamaño del 50 al 200 %. Las "
    L"casillas Luz principal, Luz de relleno, Luz ambiental e Iluminación de contornos bajo los controles "
    L"deslizantes controlan de forma independiente la iluminación de toda la escena. La luz ambiental aporta "
    L"iluminación básica a las superficies y la iluminación de contornos resalta sus bordes. De forma "
    L"predeterminada, las luces principal, ambiental y de contornos están activadas, y la luz de relleno "
    L"está desactivada. Los ajustes se guardan por separado para la aplicación y el "
    L"salvapantallas.\r\n\r\nActive los sólidos deseados. Activar vista previa inicia una vista previa a "
    L"pantalla completa en todos los monitores; el cuadro de configuración permanece abierto para realizar "
    L"ajustes en tiempo real. Aceptar guarda y Cancelar descarta. Esc o mover el ratón cierra el "
    L"salvapantallas completo. Use Tab y Mayús+Tab para desplazarse entre controles; Alt y la letra "
    L"subrayada activan una opción. Esc en la configuración equivale a Cancelar; en Ayuda o Acerca de, "
    L"cierra únicamente esa ventana.\r\n\r\nSe admiten Windows 7 a Windows 11. Para ejecutar la aplicación "
    L"en Windows Vista SP2, es necesario instalar las actualizaciones KB971512 y KB2117917.",
    L"Scegliere Osservazione dello spazio o Volo nello spazio rettilineo. I cursori regolano la velocità di "
    L"oggetti e camera da 0 a 1600 %, da una a dieci copie e la dimensione da 50 a 200 %. Le caselle Luce "
    L"principale, Luce di riempimento, Luce ambientale e Illuminazione dei contorni sotto i cursori "
    L"controllano indipendentemente l’illuminazione dell’intera scena. La luce ambientale fornisce "
    L"un’illuminazione di base alle superfici, mentre quella dei contorni ne evidenzia i bordi. Per "
    L"impostazione predefinita, le luci principale, ambientale e dei contorni sono attive e la luce di "
    L"riempimento è disattivata. Le impostazioni vengono salvate separatamente per l’applicazione e il "
    L"salvaschermo.\r\n\r\nAttivare i solidi desiderati. Attiva anteprima avvia un’anteprima a schermo "
    L"intero su tutti i monitor; le impostazioni rimangono aperte per le modifiche in tempo reale. OK salva "
    L"e Annulla scarta. Esc o il movimento del mouse chiude il salvaschermo a schermo intero. Usare Tab e "
    L"Maiusc+Tab per passare tra i controlli; Alt e la lettera sottolineata attivano un comando. Esc nelle "
    L"impostazioni equivale ad Annulla; nella Guida o nelle Informazioni, chiude solo quella "
    L"finestra.\r\n\r\nSono supportati i sistemi da Windows 7 a Windows 11. Per eseguire l’applicazione su "
    L"Windows Vista SP2, è necessario installare gli aggiornamenti KB971512 e KB2117917.",
    L"Wybierz Obserwację przestrzeni albo prostoliniowy Przelot przez przestrzeń. Suwaki ustawiają prędkość "
    L"obiektów i kamery 0–1600%, od jednej do dziesięciu kopii i rozmiar 50–200%. Pola wyboru Światło "
    L"główne, Światło wypełniające, Światło otoczenia i Oświetlenie konturów pod suwakami niezależnie "
    L"sterują oświetleniem całej sceny. Światło otoczenia zapewnia podstawową jasność powierzchni, a "
    L"oświetlenie konturów podkreśla krawędzie. Domyślnie światło główne, światło otoczenia i oświetlenie "
    L"konturów są włączone, a światło wypełniające jest wyłączone. Ustawienia są zapisywane osobno dla "
    L"aplikacji i wygaszacza ekranu.\r\n\r\nWłącz potrzebne bryły. Włącz podgląd uruchamia podgląd "
    L"pełnoekranowy na wszystkich monitorach. Okno ustawień pozostaje otwarte, umożliwiając zmiany na "
    L"bieżąco. OK zapisuje ustawienia, a Anuluj je odrzuca. Esc lub ruch myszy kończy tryb pełnoekranowy. "
    L"Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera wywołują polecenie. "
    L"Esc w ustawieniach odpowiada przyciskowi Anuluj; w Pomocy lub O programie zamyka tylko to "
    L"okno.\r\n\r\nObsługiwane są systemy od Windows 7 do Windows 11. Do uruchomienia aplikacji w systemie "
    L"Windows Vista SP2 konieczne jest zainstalowanie aktualizacji KB971512 i KB2117917.",
    L"Vyberte Pozorovanie priestoru alebo priamy Prelet priestorom. Jazdce nastavujú rýchlosť objektov a "
    L"kamery 0–1600 %, jednu až desať kópií a veľkosť 50–200 %. Začiarkavacie políčka Hlavné svetlo, "
    L"Doplnkové svetlo, Základný jas a Prisvetlenie obrysov pod jazdcami nezávisle ovládajú osvetlenie celej "
    L"scény. Základný jas prisvetľuje povrchy telies a prisvetlenie obrysov zvýrazňuje ich okraje. "
    L"Predvolene sú hlavné svetlo, základný jas a prisvetlenie obrysov zapnuté a doplnkové svetlo vypnuté. "
    L"Nastavenia osvetlenia sa ukladajú zvlášť pre aplikáciu a šetrič obrazovky.\r\n\r\nZapnite požadované "
    L"telesá. Zapnúť náhľad spustí celoobrazovkový náhľad na všetkých monitoroch; nastavenia zostávajú "
    L"otvorené a zmeny sa prejavia ihneď. OK uloží nastavenia a Zrušiť ich zahodí. Celoobrazovkový šetrič "
    L"ukončí Esc alebo pohyb myši. Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; "
    L"podčiarknuté voľby vyvoláte pomocou Alt a príslušného písmena. Esc v nastaveniach zodpovedá tlačidlu "
    L"Zrušiť; v Pomocníkovi alebo okne O aplikácii zavrie iba toto okno.\r\n\r\nPodporované sú systémy "
    L"Windows 7 až Windows 11. Na spustenie aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať "
    L"aktualizácie KB971512 a KB2117917.",
    L"Choose Space observation or the straight Fly through space mode. Set object and camera speed from "
    L"0–1600%, one to ten copies and size from 50–200%, then enable the required objects. The Main light, "
    L"Fill light, Ambient light, and Rim light checkboxes below the sliders independently control lighting "
    L"for the whole scene. Ambient light provides base illumination of object surfaces; rim light highlights "
    L"their edges. By default, main, ambient, and rim light are on, and fill light is off. Lighting settings "
    L"are stored separately for the application and screen saver.\r\n\r\nEnable preview starts a full-screen "
    L"preview on every display while the settings dialog remains open for live adjustments. OK saves the "
    L"settings and Cancel discards them. Exit the full-screen screen saver with Esc or mouse movement. Use "
    L"Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a command. "
    L"Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes only that "
    L"window.\r\n\r\nWindows 7 through Windows 11 are supported. To run the application on Windows Vista "
    L"SP2, you must install updates KB971512 and KB2117917.",
    L"Choose Space observation or the straight Fly through space mode. Set object and camera speed from "
    L"0–1600%, one to ten copies and size from 50–200%, then enable the required objects. The Main light, "
    L"Fill light, Ambient light, and Rim light checkboxes below the sliders independently control lighting "
    L"for the whole scene. Ambient light provides base illumination of object surfaces; rim light highlights "
    L"their edges. By default, main, ambient, and rim light are on, and fill light is off. Lighting settings "
    L"are stored separately for the application and screen saver.\r\n\r\nEnable preview starts a full-screen "
    L"preview on every display while the settings dialog remains open for live adjustments. OK saves the "
    L"settings and Cancel discards them. Exit the full-screen screen saver with Esc or mouse movement. Use "
    L"Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a command. "
    L"Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes only that "
    L"window.\r\n\r\nWindows 7 through Windows 11 are supported. To run the application on Windows Vista "
    L"SP2, you must install updates KB971512 and KB2117917.",
    L"Escolha Observação do espaço ou Voo pelo espaço em linha reta. Regule a velocidade dos objetos e da "
    L"câmara de 0 a 1600%, uma a dez cópias e o tamanho de 50 a 200%, e ative os sólidos. As caixas Luz "
    L"principal, Luz de preenchimento, Luz ambiente e Iluminação dos contornos sob os controlos deslizantes "
    L"controlam a iluminação de toda a cena de forma independente. A luz ambiente fornece iluminação de base "
    L"às superfícies e a iluminação dos contornos realça os seus limites. Por predefinição, as luzes "
    L"principal, ambiente e dos contornos estão ligadas e a luz de preenchimento está desligada. As "
    L"definições são guardadas separadamente para a aplicação e a proteção de ecrã.\r\n\r\nAtivar "
    L"pré-visualização inicia uma pré-visualização em ecrã inteiro em todos os monitores; o diálogo "
    L"permanece aberto para ajustar as definições em tempo real. OK guarda as definições e Cancelar "
    L"descarta-as. Esc ou o movimento do rato termina a proteção em ecrã inteiro. Use Tab e Shift+Tab para "
    L"passar entre controlos; Alt e a letra sublinhada ativam um comando. Esc nas definições equivale a "
    L"Cancelar; na Ajuda ou em Acerca de, fecha apenas essa janela.\r\n\r\nSão suportados os sistemas "
    L"Windows 7 a Windows 11. Para executar a aplicação no Windows Vista SP2, é necessário instalar as "
    L"atualizações KB971512 e KB2117917.",
    L"Velg Romobservasjon eller Flyging gjennom rommet i rett linje. Angi objekt- og kamerahastighet 0–1600 "
    L"%, én til ti kopier og størrelse 50–200 %, og aktiver ønskede legemer. Avmerkingsboksene Hovedlys, "
    L"Utfyllingslys, Omgivelseslys og Konturlys under glidebryterne styrer belysningen i hele scenen "
    L"uavhengig av hverandre. Omgivelseslys gir grunnbelysning på overflatene, og konturlys fremhever "
    L"kantene. Som standard er hovedlys, omgivelseslys og konturlys på, og utfyllingslys av. Innstillingene "
    L"lagres separat for programmet og skjermspareren.\r\n\r\nSlå på forhåndsvisning starter en "
    L"forhåndsvisning i fullskjerm på alle skjermer. Innstillingene forblir åpne, og endringene vises "
    L"fortløpende. OK lagrer innstillingene og Avbryt forkaster dem. Esc eller musebevegelse avslutter "
    L"fullskjermsvisningen. Bruk Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede "
    L"bokstaven aktiverer en kommando. Esc i innstillingene tilsvarer Avbryt; i Hjelp eller Om lukker det "
    L"bare dette vinduet.\r\n\r\nWindows 7 til Windows 11 støttes. For å kjøre programmet på Windows Vista "
    L"SP2 må oppdateringene KB971512 og KB2117917 installeres.",
    L"Välj Rymdobservation eller Flygning genom rymden i rak linje. Ställ in objekt- och kamerahastighet "
    L"0–1600 %, en till tio kopior och storlek 50–200 %, och aktivera önskade kroppar. Kryssrutorna "
    L"Huvudljus, Upplättningsljus, Omgivningsljus och Konturljus under reglagen styr belysningen i hela "
    L"scenen oberoende av varandra. Omgivningsljus ger grundbelysning på ytorna och konturljus framhäver "
    L"kanterna. Som standard är huvudljus, omgivningsljus och konturljus på och upplättningsljus av. "
    L"Inställningarna sparas separat för programmet och skärmsläckaren.\r\n\r\nAktivera förhandsvisning "
    L"startar en förhandsvisning i helskärm på alla bildskärmar. Inställningarna förblir öppna och "
    L"ändringarna visas direkt. OK sparar inställningarna och Avbryt förkastar ändringarna. Esc eller "
    L"musrörelse avslutar helskärmsläget. Använd Tab och Skift+Tab för att flytta mellan kontrollerna; Alt "
    L"och den understrukna bokstaven aktiverar ett kommando. Esc i inställningarna motsvarar Avbryt; i Hjälp "
    L"eller Om stänger det bara det fönstret.\r\n\r\nWindows 7 till Windows 11 stöds. För att köra "
    L"programmet på Windows Vista SP2 måste uppdateringarna KB971512 och KB2117917 installeras.",
    L"Valitse Avaruuden tarkkailu tai Lento avaruuden halki suoraan eteenpäin. Aseta kohteiden ja kameran "
    L"nopeus 0–1600 %, yhdestä kymmeneen kopiota ja koko 50–200 %, ja ota halutut kappaleet käyttöön. "
    L"Liukusäätimien alla olevat Päävalo-, Täytevalo-, Ympäristövalo- ja Reunavalo-valintaruudut ohjaavat "
    L"koko näkymän valaistusta toisistaan riippumatta. Ympäristövalo antaa pinnoille perusvalaistuksen ja "
    L"reunavalo korostaa reunoja. Oletuksena päävalo, ympäristövalo ja reunavalo ovat päällä ja täytevalo "
    L"pois päältä. Asetukset tallennetaan erikseen sovellukselle ja näytönsäästäjälle.\r\n\r\nOta esikatselu "
    L"käyttöön käynnistää koko näytön esikatselun kaikilla näytöillä. Asetusikkuna pysyy avoinna, ja "
    L"muutokset näkyvät heti. OK tallentaa asetukset ja Peruuta hylkää muutokset. Esc tai hiiren liike "
    L"lopettaa koko näytön säästäjän. Siirry säätimien välillä Tab- ja Vaihto+Tab-näppäimillä; Alt ja "
    L"alleviivattu kirjain aktivoivat komennon. Esc asetuksissa vastaa Peruuta-painiketta; Ohje- tai "
    L"Tietoja-ikkunassa se sulkee vain kyseisen ikkunan.\r\n\r\nTuettuja käyttöjärjestelmiä ovat Windows "
    L"7–Windows 11. Sovelluksen suorittaminen Windows Vista SP2:ssa edellyttää päivitysten KB971512 ja "
    L"KB2117917 asentamista.",
    L"Vælg Rumobservation eller Flyvning gennem rummet i en lige linje. Indstil objekt- og kamerahastighed "
    L"0–1600 %, en til ti kopier og størrelse 50–200 %, og aktivér de ønskede legemer. Afkrydsningsfelterne "
    L"Hovedlys, Udfyldningslys, Omgivende lys og Konturlys under skyderne styrer belysningen af hele scenen "
    L"uafhængigt af hinanden. Omgivende lys giver overfladerne en grundbelysning, og konturlys fremhæver "
    L"kanterne. Som standard er hovedlys, omgivende lys og konturlys slået til og udfyldningslys slået fra. "
    L"Indstillingerne gemmes separat for programmet og pauseskærmen.\r\n\r\nAktivér forhåndsvisning starter "
    L"en forhåndsvisning i fuld skærm på alle skærme. Indstillingerne forbliver åbne, og ændringerne vises "
    L"med det samme. OK gemmer indstillingerne, og Annuller forkaster ændringerne. Esc eller musebevægelse "
    L"afslutter fuldskærmen. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det "
    L"understregede bogstav aktiverer en kommando. Esc i indstillingerne svarer til Annuller; i Hjælp eller "
    L"Om lukker det kun dette vindue.\r\n\r\nWindows 7 til Windows 11 understøttes. For at køre programmet "
    L"på Windows Vista SP2 skal opdateringerne KB971512 og KB2117917 installeres.",
    L"Veldu Athugun rýmis eða Flug um rýmið í beinni línu. Stilltu hraða hluta og myndavélar á 0–1600%, eitt "
    L"til tíu eintök og stærð á 50–200% og virkjaðu óskaða hluti. Gátreitirnir Aðalljós, Fylliljós, "
    L"Umhverfislýsing og Útlínulýsing undir rennistikunum stýra lýsingu allrar senunnar óháð hver öðrum. "
    L"Umhverfislýsing gefur yfirborðunum grunnbirtu og útlínulýsing dregur fram jaðrana. Sjálfgefið er "
    L"kveikt á aðalljósi, umhverfislýsingu og útlínulýsingu en slökkt á fylliljósi. Stillingarnar eru "
    L"vistaðar sérstaklega fyrir forritið og skjáhvíluna.\r\n\r\nVirkja forskoðun ræsir forskoðun á öllum "
    L"skjánum á hverjum skjá. Stillingaglugginn helst opinn og breytingar sjást strax. Í lagi vistar "
    L"stillingar og Hætta við hafnar breytingum. Esc eða músarhreyfing lokar skjáhvílu á öllum skjánum. "
    L"Notaðu Tab og Shift+Tab til að færa þig milli stýrieininga; Alt og undirstrikaður stafur virkja "
    L"skipun. Esc í stillingum jafngildir Hætta við; í Hjálp eða Um lokar það aðeins þeim "
    L"glugga.\r\n\r\nWindows 7 til Windows 11 eru studd. Til að keyra forritið á Windows Vista SP2 þarf að "
    L"setja upp uppfærslurnar KB971512 og KB2117917.",
    L"Uzayı gözlemleme veya doğrusal Uzayda uçuş kipini seçin. Nesne ve kamera hızını %0–1600, kopya "
    L"sayısını bir ile on ve boyutu %50–200 arasında ayarlayıp istenen cisimleri etkinleştirin. "
    L"Kaydırıcıların altındaki Ana ışık, Dolgu ışığı, Ortam ışığı ve Kenar aydınlatması onay kutuları tüm "
    L"sahnenin aydınlatmasını birbirinden bağımsız olarak kontrol eder. Ortam ışığı yüzeylere temel "
    L"aydınlatma sağlar, kenar aydınlatması ise kenarları vurgular. Varsayılan olarak ana ışık, ortam ışığı "
    L"ve kenar aydınlatması açık, dolgu ışığı kapalıdır. Ayarlar uygulama ve ekran koruyucu için ayrı ayrı "
    L"kaydedilir.\r\n\r\nÖnizlemeyi aç, tüm monitörlerde tam ekran önizleme başlatır. Ayarlar penceresi açık "
    L"kalır ve değişiklikler anında görülür. Tamam ayarları kaydeder, İptal değişiklikleri iptal eder. Tam "
    L"ekran koruyucudan Esc veya fare hareketiyle çıkılır. Denetimler arasında Tab ve Shift+Tab ile "
    L"ilerleyin; Alt ve altı çizili harf bir komutu etkinleştirir. Ayarlarda Esc, İptal ile aynı işlevi "
    L"görür; Yardım veya Hakkında penceresinde yalnızca o pencereyi kapatır.\r\n\r\nWindows 7 ile Windows 11 "
    L"arasındaki sürümler desteklenir. Uygulamayı Windows Vista SP2'de çalıştırmak için KB971512 ve "
    L"KB2117917 güncellemelerini yüklemeniz gerekir."
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

/// Returns localized monitor-detail column captions and bit-depth formats.
const MonitorColumnText& MonitorColumnsText(AppLanguage language) {
    return MONITOR_COLUMN_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized option that inhibits the screen saver during visible animation.
const wchar_t* PreventScreenSaverText(AppLanguage language) {
    return PREVENT_SCREEN_SAVER_TEXTS[
        static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized ambient-light checkbox caption.
const wchar_t* AmbientLightText(AppLanguage language) {
    return AMBIENT_LIGHT_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}

/// Returns the localized rim-light checkbox caption.
const wchar_t* RimLightText(AppLanguage language) {
    return RIM_LIGHT_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
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
