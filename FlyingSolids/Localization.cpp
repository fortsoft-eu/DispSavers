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
    L"Válec",
    L"Dutý válec",
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

constexpr SolidTextArray ESTONIAN_SOLIDS = {
    L"Kuup",
    L"Korrapärane nelinurkne püramiid",
    L"Nelinurkne tüvipüramiid",
    L"Kaldlõikega nelinurkne püramiid",
    L"Põhjaga ristlõigatud püramiid",
    L"Korrapärane kolmnurkne prisma",
    L"Korrapärane viisnurkne prisma",
    L"Korrapärane kuusnurkne prisma",
    L"Korrapärane oktaeeder",
    L"Viisnurkne kaksikpüramiid",
    L"Pöördkoonus",
    L"Tüvikoonus",
    L"Kaldlõikega koonus",
    L"Põhjaga ristlõigatud koonus",
    L"Pöördsilinder",
    L"Õõnes pöördsilinder",
    L"Toroidsete otstega õõnessilinder",
    L"Tasandiga suletud pöördparaboloid",
    L"Kera",
    L"Poolkera",
    L"Kerasegment",
    L"Suur kerasegment",
    L"Kerakiht",
    L"Kolmeteljeline ellipsoid",
    L"Piklik pöördellipsoid",
    L"Lapik pöördellipsoid",
    L"Munakeha",
    L"Sferosilinder",
    L"Ümardatud ketas (spheroplatelet)",
    L"Toor"
};

constexpr SolidTextArray IRISH_SOLIDS = {
    L"Ciúb",
    L"Pirimid chearnach rialta",
    L"Teascán pirimide cearnaí",
    L"Pirimid chearnach le gearradh claon",
    L"Pirimid gearrtha ingearach leis an mbonn",
    L"Príosma triantánach rialta",
    L"Príosma peinteagánach rialta",
    L"Príosma heicseagánach rialta",
    L"Ochtaihéadrán rialta",
    L"Dépirimid pheinteagánach",
    L"Cón ciorclach díreach",
    L"Teascán cóin",
    L"Cón le gearradh claon",
    L"Cón gearrtha ingearach leis an mbonn",
    L"Sorcóir ciorclach díreach",
    L"Sorcóir ciorclach toll",
    L"Sorcóir toll le foircinn tórasacha",
    L"Parabalóideach rothlach dúnta",
    L"Sféar",
    L"Leathsféar",
    L"Caipín sféarúil",
    L"Caipín sféarúil mór",
    L"Teascán sféarúil idir dhá phlána",
    L"Éileapsóideach trí-aiseach",
    L"Sféaróideach fadaithe",
    L"Sféaróideach leacaithe",
    L"Ubhchruthán",
    L"Capsúl (spherocylinder)",
    L"Diosca slánaithe (spheroplatelet)",
    L"Tóras"
};

constexpr SolidTextArray LITHUANIAN_SOLIDS = {
    L"Kubas",
    L"Taisyklingoji keturkampė piramidė",
    L"Nupjautinė keturkampė piramidė",
    L"Įstrižai nupjauta keturkampė piramidė",
    L"Statmenai pagrindui nupjauta piramidė",
    L"Taisyklingoji trikampė prizmė",
    L"Taisyklingoji penkiakampė prizmė",
    L"Taisyklingoji šešiakampė prizmė",
    L"Taisyklingasis oktaedras",
    L"Penkiakampė bipiramidė",
    L"Statusis apskritasis kūgis",
    L"Nupjautinis kūgis",
    L"Įstrižai nupjautas kūgis",
    L"Statmenai pagrindui nupjautas kūgis",
    L"Statusis apskritasis ritinys",
    L"Tuščiaviduris ritinys",
    L"Ritinys su toroidiniais galais",
    L"Plokštuma uždaras sukimosi paraboloidas",
    L"Rutulys",
    L"Pusrutulis",
    L"Rutulio nuopjova",
    L"Didžioji rutulio nuopjova",
    L"Rutulio sluoksnis",
    L"Triašis elipsoidas",
    L"Ištęstas sukimosi elipsoidas",
    L"Suplotas sukimosi elipsoidas",
    L"Ovoidas",
    L"Sferocilindras",
    L"Suapvalintas diskas (spheroplatelet)",
    L"Toras"
};

constexpr SolidTextArray LATVIAN_SOLIDS = {
    L"Kubs",
    L"Regulāra četrstūra piramīda",
    L"Nošķelta četrstūra piramīda",
    L"Slīpi nošķelta četrstūra piramīda",
    L"Piramīda ar pamatnei perpendikulāru griezumu",
    L"Regulāra trijstūra prizma",
    L"Regulāra piecstūra prizma",
    L"Regulāra sešstūra prizma",
    L"Regulārs oktaedrs",
    L"Piecstūra bipiramīda",
    L"Taisns riņķa konuss",
    L"Nošķelts konuss",
    L"Slīpi nošķelts konuss",
    L"Konuss ar pamatnei perpendikulāru griezumu",
    L"Taisns riņķa cilindrs",
    L"Dobs cilindrs",
    L"Dobs cilindrs ar toroidāliem galiem",
    L"Ar plakni noslēgts rotācijas paraboloīds",
    L"Lode",
    L"Puslode",
    L"Lodes segments",
    L"Lielais lodes segments",
    L"Lodes slānis",
    L"Trīsasu elipsoīds",
    L"Izstiepts rotācijas elipsoīds",
    L"Saspiests rotācijas elipsoīds",
    L"Ovoīds",
    L"Sferocilindrs",
    L"Noapaļots disks (spheroplatelet)",
    L"Tors"
};

constexpr SolidTextArray HUNGARIAN_SOLIDS = {
    L"Kocka",
    L"Szabályos négyzet alapú gúla",
    L"Négyzet alapú csonkagúla",
    L"Ferdén metszett négyzet alapú gúla",
    L"Alapra merőlegesen metszett gúla",
    L"Szabályos háromszög alapú hasáb",
    L"Szabályos ötszög alapú hasáb",
    L"Szabályos hatszög alapú hasáb",
    L"Szabályos oktaéder",
    L"Ötszög alapú kettős gúla",
    L"Egyenes körkúp",
    L"Csonkakúp",
    L"Ferdén metszett kúp",
    L"Alapra merőlegesen metszett kúp",
    L"Egyenes körhenger",
    L"Üreges körhenger",
    L"Üreges henger tóruszos végekkel",
    L"Síkkal lezárt forgási paraboloid",
    L"Gömb",
    L"Félgömb",
    L"Gömbsüveg",
    L"Nagy gömbsüveg",
    L"Gömbszelet",
    L"Háromtengelyű ellipszoid",
    L"Nyújtott forgási ellipszoid",
    L"Lapított forgási ellipszoid",
    L"Ovoid",
    L"Szferocilinder",
    L"Lekerekített korong (spheroplatelet)",
    L"Tórusz"
};

constexpr SolidTextArray MALTESE_SOLIDS = {
    L"Kubu",
    L"Piramida kwadra regolari",
    L"Frustum ta’ piramida kwadra",
    L"Piramida kwadra maqtugħa oblikwament",
    L"Piramida maqtugħa perpendikulari mal-bażi",
    L"Priżma trijangolari regolari",
    L"Priżma pentagonali regolari",
    L"Priżma eżagonali regolari",
    L"Ottaedru regolari",
    L"Bipiramida pentagonali",
    L"Konu ċirkolari rett",
    L"Frustum ta’ konu",
    L"Konu maqtugħ oblikwament",
    L"Konu maqtugħ perpendikulari mal-bażi",
    L"Ċilindru ċirkolari rett",
    L"Ċilindru ċirkolari vojt",
    L"Ċilindru vojt bi truf torojdali",
    L"Parabolojde ta’ rotazzjoni magħluq",
    L"Sfera",
    L"Emisfera",
    L"Kalotta sferika",
    L"Kalotta sferika maġġuri",
    L"Segment sferiku bejn żewġ pjani",
    L"Ellissojde triassjali",
    L"Sferojde mtawwal",
    L"Sferojde ċċattjat",
    L"Ovojde",
    L"Kapsula (spherocylinder)",
    L"Diska ttondjata (spheroplatelet)",
    L"Toru"
};

constexpr SolidTextArray DUTCH_SOLIDS = {
    L"Kubus",
    L"Regelmatige vierzijdige piramide",
    L"Afgeknotte vierzijdige piramide",
    L"Schuin afgesneden vierzijdige piramide",
    L"Piramide loodrecht op grondvlak gesneden",
    L"Regelmatig driehoekig prisma",
    L"Regelmatig vijfhoekig prisma",
    L"Regelmatig zeshoekig prisma",
    L"Regelmatige octaëder",
    L"Vijfhoekige bipiramide",
    L"Rechte cirkelkegel",
    L"Afgeknotte kegel",
    L"Schuin afgesneden kegel",
    L"Kegel loodrecht op grondvlak gesneden",
    L"Rechte cirkelcilinder",
    L"Holle cirkelcilinder",
    L"Holle cilinder met torusvormige uiteinden",
    L"Gesloten omwentelingsparaboloïde",
    L"Bol",
    L"Halve bol",
    L"Bolkap",
    L"Grote bolkap",
    L"Bolschijf",
    L"Drieassige ellipsoïde",
    L"Prolate sferoïde",
    L"Oblate sferoïde",
    L"Ovoïde",
    L"Sferocilinder",
    L"Afgeronde schijf (spheroplatelet)",
    L"Torus"
};

constexpr SolidTextArray ROMANIAN_SOLIDS = {
    L"Cub",
    L"Piramidă patrulateră regulată",
    L"Trunchi de piramidă patrulateră",
    L"Piramidă patrulateră secționată oblic",
    L"Piramidă secționată perpendicular pe bază",
    L"Prismă triunghiulară regulată",
    L"Prismă pentagonală regulată",
    L"Prismă hexagonală regulată",
    L"Octaedru regulat",
    L"Bipiramidă pentagonală",
    L"Con circular drept",
    L"Trunchi de con",
    L"Con secționat oblic",
    L"Con secționat perpendicular pe bază",
    L"Cilindru circular drept",
    L"Cilindru circular gol",
    L"Cilindru gol cu capete toroidale",
    L"Paraboloid de rotație închis cu un plan",
    L"Sferă",
    L"Emisferă",
    L"Calotă sferică",
    L"Calotă sferică mare",
    L"Segment sferic cu două baze",
    L"Elipsoid triaxial",
    L"Elipsoid de rotație alungit",
    L"Elipsoid de rotație turtit",
    L"Ovoid",
    L"Sferocilindru",
    L"Disc rotunjit (spheroplatelet)",
    L"Tor"
};

constexpr SolidTextArray GREEK_SOLIDS = {
    L"Κύβος",
    L"Κανονική τετραγωνική πυραμίδα",
    L"Κόλουρη τετραγωνική πυραμίδα",
    L"Τετραγωνική πυραμίδα με λοξή τομή",
    L"Πυραμίδα με τομή κάθετη στη βάση",
    L"Κανονικό τριγωνικό πρίσμα",
    L"Κανονικό πενταγωνικό πρίσμα",
    L"Κανονικό εξαγωνικό πρίσμα",
    L"Κανονικό οκτάεδρο",
    L"Πενταγωνική διπυραμίδα",
    L"Ορθός κυκλικός κώνος",
    L"Κόλουρος κώνος",
    L"Κώνος με λοξή τομή",
    L"Κώνος με τομή κάθετη στη βάση",
    L"Ορθός κυκλικός κύλινδρος",
    L"Κοίλος κυκλικός κύλινδρος",
    L"Κοίλος κύλινδρος με τοροειδή άκρα",
    L"Κλειστό παραβολοειδές εκ περιστροφής",
    L"Σφαίρα",
    L"Ημισφαίριο",
    L"Σφαιρικός θόλος",
    L"Μεγάλος σφαιρικός θόλος",
    L"Σφαιρικό τμήμα δύο βάσεων",
    L"Τριαξονικό ελλειψοειδές",
    L"Επίμηκες σφαιροειδές",
    L"Πεπλατυσμένο σφαιροειδές",
    L"Ωοειδές",
    L"Σφαιροκύλινδρος",
    L"Στρογγυλεμένος δίσκος (spheroplatelet)",
    L"Τόρος"
};

constexpr SolidTextArray BOSNIAN_SOLIDS = {
    L"Kocka",
    L"Pravilna četverostrana piramida",
    L"Zarubljena četverostrana piramida",
    L"Četverostrana piramida s kosim presjekom",
    L"Piramida s presjekom okomitim na bazu",
    L"Pravilna trostrana prizma",
    L"Pravilna peterostrana prizma",
    L"Pravilna šesterostrana prizma",
    L"Pravilni oktaedar",
    L"Peterostrana bipiramida",
    L"Pravi kružni stožac",
    L"Zarubljeni stožac",
    L"Stožac s kosim presjekom",
    L"Stožac s presjekom okomitim na bazu",
    L"Pravi kružni valjak",
    L"Šuplji kružni valjak",
    L"Šuplji valjak s torusnim krajevima",
    L"Rotacijski paraboloid zatvoren ravninom",
    L"Kugla",
    L"Polukugla",
    L"Kuglin odsječak",
    L"Veliki kuglin odsječak",
    L"Kuglin sloj",
    L"Troosni elipsoid",
    L"Izduženi rotacijski elipsoid",
    L"Spljošteni rotacijski elipsoid",
    L"Ovoid",
    L"Sferocilindar",
    L"Zaobljeni disk (spheroplatelet)",
    L"Torus"
};

constexpr SolidTextArray CROATIAN_SOLIDS = {
    L"Kocka",
    L"Pravilna četverostrana piramida",
    L"Krnje tijelo četverostrane piramide",
    L"Četverostrana piramida s kosim presjekom",
    L"Piramida s presjekom okomitim na bazu",
    L"Pravilna trostrana prizma",
    L"Pravilna peterostrana prizma",
    L"Pravilna šesterostrana prizma",
    L"Pravilni oktaedar",
    L"Peterostrana bipiramida",
    L"Uspravni kružni stožac",
    L"Krnji stožac",
    L"Stožac s kosim presjekom",
    L"Stožac s presjekom okomitim na bazu",
    L"Uspravni kružni valjak",
    L"Šuplji kružni valjak",
    L"Šuplji valjak s torusnim krajevima",
    L"Rotacijski paraboloid zatvoren ravninom",
    L"Kugla",
    L"Polukugla",
    L"Kuglin odsječak",
    L"Veliki kuglin odsječak",
    L"Kuglin sloj",
    L"Troosni elipsoid",
    L"Izduženi rotacijski elipsoid",
    L"Spljošteni rotacijski elipsoid",
    L"Ovoid",
    L"Sferocilindar",
    L"Zaobljeni disk (spheroplatelet)",
    L"Torus"
};

constexpr SolidTextArray SLOVENIAN_SOLIDS = {
    L"Kocka",
    L"Pravilna štiristrana piramida",
    L"Prisekana štiristrana piramida",
    L"Poševno prirezana štiristrana piramida",
    L"Piramida s prerezom pravokotno na osnovo",
    L"Pravilna tristrana prizma",
    L"Pravilna petstrana prizma",
    L"Pravilna šeststrana prizma",
    L"Pravilni oktaeder",
    L"Petstrana bipiramida",
    L"Pokončni krožni stožec",
    L"Prisekani stožec",
    L"Poševno prirezani stožec",
    L"Stožec s prerezom pravokotno na osnovo",
    L"Pokončni krožni valj",
    L"Votel krožni valj",
    L"Votel valj s toroidnima koncema",
    L"Rotacijski paraboloid, zaprt z ravnino",
    L"Krogla",
    L"Polkrogla",
    L"Krogelni odsek",
    L"Veliki krogelni odsek",
    L"Krogelna plast",
    L"Triosni elipsoid",
    L"Podolgovati rotacijski elipsoid",
    L"Sploščeni rotacijski elipsoid",
    L"Ovoid",
    L"Sferocilinder",
    L"Zaobljena ploščica (spheroplatelet)",
    L"Torus"
};

constexpr SolidTextArray MONTENEGRIN_SOLIDS = {
    L"Kocka",
    L"Pravilna četvorostrana piramida",
    L"Zarubljena četvorostrana piramida",
    L"Četvorostrana piramida s kosim presjekom",
    L"Piramida s presjekom normalnim na osnovu",
    L"Pravilna trostrana prizma",
    L"Pravilna petostrana prizma",
    L"Pravilna šestostrana prizma",
    L"Pravilni oktaedar",
    L"Petostrana bipiramida",
    L"Prava kružna kupa",
    L"Zarubljena kupa",
    L"Kupa s kosim presjekom",
    L"Kupa s presjekom normalnim na osnovu",
    L"Pravi kružni valjak",
    L"Šuplji kružni valjak",
    L"Šuplji valjak s torusnim krajevima",
    L"Rotacioni paraboloid zatvoren ravni",
    L"Lopta",
    L"Polulopta",
    L"Loptin odsječak",
    L"Veliki loptin odsječak",
    L"Loptin sloj",
    L"Troosni elipsoid",
    L"Izduženi rotacioni elipsoid",
    L"Spljošteni rotacioni elipsoid",
    L"Ovoid",
    L"Sferocilindar",
    L"Zaobljeni disk (spheroplatelet)",
    L"Torus"
};

constexpr SolidTextArray BELARUSIAN_SOLIDS = {
    L"Куб",
    L"Правільная чатырохвугольная піраміда",
    L"Усечаная чатырохвугольная піраміда",
    L"Чатырохвугольная піраміда з косым зрэзам",
    L"Піраміда са зрэзам, перпендыкулярным аснове",
    L"Правільная трохвугольная прызма",
    L"Правільная пяцівугольная прызма",
    L"Правільная шасцівугольная прызма",
    L"Правільны актаэдр",
    L"Пяцівугольная біпіраміда",
    L"Прамы кругавы конус",
    L"Усечаны конус",
    L"Конус з косым зрэзам",
    L"Конус са зрэзам, перпендыкулярным аснове",
    L"Прамы кругавы цыліндр",
    L"Полы кругавы цыліндр",
    L"Полы цыліндр з тараідальнымі канцамі",
    L"Парабалоід вярчэння, замкнёны плоскасцю",
    L"Шар",
    L"Паўшар",
    L"Шаравы сегмент",
    L"Вялікі шаравы сегмент",
    L"Шаравы слой",
    L"Трохвосевы эліпсоід",
    L"Выцягнуты эліпсоід вярчэння",
    L"Сплюшчаны эліпсоід вярчэння",
    L"Авоід",
    L"Сферацыліндр",
    L"Скруглены дыск (spheroplatelet)",
    L"Тор"
};

constexpr SolidTextArray BULGARIAN_SOLIDS = {
    L"Куб",
    L"Правилна четириъгълна пирамида",
    L"Пресечена четириъгълна пирамида",
    L"Четириъгълна пирамида с наклонен срез",
    L"Пирамида със срез, перпендикулярен на основата",
    L"Правилна триъгълна призма",
    L"Правилна петоъгълна призма",
    L"Правилна шестоъгълна призма",
    L"Правилен октаедър",
    L"Петоъгълна бипирамида",
    L"Прав кръгов конус",
    L"Пресечен конус",
    L"Конус с наклонен срез",
    L"Конус със срез, перпендикулярен на основата",
    L"Прав кръгов цилиндър",
    L"Кух кръгов цилиндър",
    L"Кух цилиндър с тороидални краища",
    L"Ротационен параболоид, затворен с равнина",
    L"Кълбо",
    L"Полукълбо",
    L"Кълбов отрез",
    L"Голям кълбов отрез",
    L"Кълбов слой",
    L"Триосен елипсоид",
    L"Удължен ротационен елипсоид",
    L"Сплеснат ротационен елипсоид",
    L"Овоид",
    L"Сфероцилиндър",
    L"Заоблен диск (spheroplatelet)",
    L"Тор"
};

constexpr SolidTextArray MACEDONIAN_SOLIDS = {
    L"Коцка",
    L"Правилна четириаголна пирамида",
    L"Потсечена четириаголна пирамида",
    L"Четириаголна пирамида со кос пресек",
    L"Пирамида со пресек нормален на основата",
    L"Правилна триаголна призма",
    L"Правилна петаголна призма",
    L"Правилна шестаголна призма",
    L"Правилен октаедар",
    L"Петаголна бипирамида",
    L"Прав кружен конус",
    L"Потсечен конус",
    L"Конус со кос пресек",
    L"Конус со пресек нормален на основата",
    L"Прав кружен цилиндар",
    L"Шуплив кружен цилиндар",
    L"Шуплив цилиндар со тороидни краеви",
    L"Ротационен параболоид затворен со рамнина",
    L"Топка",
    L"Полутопка",
    L"Топкин отсечок",
    L"Голем топкин отсечок",
    L"Топкин слој",
    L"Триосен елипсоид",
    L"Издолжен ротационен елипсоид",
    L"Сплескан ротационен елипсоид",
    L"Овоид",
    L"Сфероцилиндар",
    L"Заоблен диск (spheroplatelet)",
    L"Тор"
};

constexpr SolidTextArray SERBIAN_SOLIDS = {
    L"Коцка",
    L"Правилна четворострана пирамида",
    L"Зарубљена четворострана пирамида",
    L"Четворострана пирамида с косим пресеком",
    L"Пирамида с пресеком нормалним на основу",
    L"Правилна тространа призма",
    L"Правилна петострана призма",
    L"Правилна шестострана призма",
    L"Правилни октаедар",
    L"Петострана бипирамида",
    L"Права кружна купа",
    L"Зарубљена купа",
    L"Купа с косим пресеком",
    L"Купа с пресеком нормалним на основу",
    L"Прави кружни ваљак",
    L"Шупљи кружни ваљак",
    L"Шупљи ваљак с торусним крајевима",
    L"Ротациони параболоид затворен равни",
    L"Лопта",
    L"Полулопта",
    L"Лоптин одсечак",
    L"Велики лоптин одсечак",
    L"Лоптин слој",
    L"Троосни елипсоид",
    L"Издужени ротациони елипсоид",
    L"Спљоштени ротациони елипсоид",
    L"Овоид",
    L"Сфероцилиндар",
    L"Заобљени диск (spheroplatelet)",
    L"Торус"
};

constexpr SolidTextArray UKRAINIAN_SOLIDS = {
    L"Куб",
    L"Правильна чотирикутна піраміда",
    L"Зрізана чотирикутна піраміда",
    L"Чотирикутна піраміда з похилим зрізом",
    L"Піраміда зі зрізом, перпендикулярним основі",
    L"Правильна трикутна призма",
    L"Правильна п’ятикутна призма",
    L"Правильна шестикутна призма",
    L"Правильний октаедр",
    L"П’ятикутна біпіраміда",
    L"Прямий круговий конус",
    L"Зрізаний конус",
    L"Конус із похилим зрізом",
    L"Конус зі зрізом, перпендикулярним основі",
    L"Прямий круговий циліндр",
    L"Порожнистий круговий циліндр",
    L"Порожнистий циліндр із тороїдними торцями",
    L"Параболоїд обертання, замкнений площиною",
    L"Куля",
    L"Півкуля",
    L"Кульовий сегмент",
    L"Великий кульовий сегмент",
    L"Кульовий шар",
    L"Тривісний еліпсоїд",
    L"Витягнутий еліпсоїд обертання",
    L"Сплюснутий еліпсоїд обертання",
    L"Овоїд",
    L"Сфероциліндр",
    L"Заокруглений диск (spheroplatelet)",
    L"Тор"
};

constexpr SolidTextArray RUSSIAN_SOLIDS = {
    L"Куб",
    L"Правильная четырёхугольная пирамида",
    L"Усечённая четырёхугольная пирамида",
    L"Четырёхугольная пирамида с косым срезом",
    L"Пирамида со срезом, перпендикулярным основанию",
    L"Правильная треугольная призма",
    L"Правильная пятиугольная призма",
    L"Правильная шестиугольная призма",
    L"Правильный октаэдр",
    L"Пятиугольная бипирамида",
    L"Прямой круговой конус",
    L"Усечённый конус",
    L"Конус с косым срезом",
    L"Конус со срезом, перпендикулярным основанию",
    L"Прямой круговой цилиндр",
    L"Полый круговой цилиндр",
    L"Полый цилиндр с тороидальными торцами",
    L"Параболоид вращения, замкнутый плоскостью",
    L"Шар",
    L"Полушар",
    L"Шаровой сегмент",
    L"Большой шаровой сегмент",
    L"Шаровой слой",
    L"Трёхосный эллипсоид",
    L"Вытянутый эллипсоид вращения",
    L"Сплюснутый эллипсоид вращения",
    L"Овоид",
    L"Сфероцилиндр",
    L"Скруглённый диск (spheroplatelet)",
    L"Тор"
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
        L"Norsk (bokmål)",
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
    }, LocalizedText{
        L"Eesti",
        L"FlyingSolids — juhtimine",
        L"FlyingSolids sätted",
        L"Keel:",
        L"Objektide kiirus: %d %%",
        L"Kaamera kiirus: %d %%",
        L"Ruumi vaatlemine",
        L"Lend läbi ruumi",
        L"Põhivalgus",
        L"Täitevalgus",
        L"Ruumilised kehad",
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
        ESTONIAN_SOLIDS
    }, LocalizedText{
        L"Gaeilge",
        L"FlyingSolids — rialuithe",
        L"Socruithe FlyingSolids",
        L"Teanga:",
        L"Luas na réad: %d %%",
        L"Luas an cheamara: %d %%",
        L"Breathnú ar an spás",
        L"Eitilt tríd an spás",
        L"Príomhsholas",
        L"Solas líonta",
        L"Réada soladacha 3T",
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
        IRISH_SOLIDS
    }, LocalizedText{
        L"Lietuvių",
        L"FlyingSolids — valdymas",
        L"FlyingSolids nuostatos",
        L"Kalba:",
        L"Objektų greitis: %d %%",
        L"Kameros greitis: %d %%",
        L"Erdvės stebėjimas",
        L"Skrydis erdve",
        L"Pagrindinė šviesa",
        L"Užpildanti šviesa",
        L"Erdviniai kūnai",
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
        LITHUANIAN_SOLIDS
    }, LocalizedText{
        L"Latviešu",
        L"FlyingSolids — vadība",
        L"FlyingSolids iestatījumi",
        L"Valoda:",
        L"Objektu ātrums: %d %%",
        L"Kameras ātrums: %d %%",
        L"Telpas novērošana",
        L"Lidojums telpā",
        L"Galvenā gaisma",
        L"Papildu gaisma",
        L"Telpiski ķermeņi",
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
        LATVIAN_SOLIDS
    }, LocalizedText{
        L"Magyar",
        L"FlyingSolids — vezérlés",
        L"FlyingSolids beállításai",
        L"Nyelv:",
        L"Objektumok sebessége: %d %%",
        L"Kamera sebessége: %d %%",
        L"A tér megfigyelése",
        L"Repülés a térben",
        L"Főfény",
        L"Derítőfény",
        L"Térbeli testek",
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
        HUNGARIAN_SOLIDS
    }, LocalizedText{
        L"Malti",
        L"FlyingSolids — kontrolli",
        L"Settings ta’ FlyingSolids",
        L"Lingwa:",
        L"Veloċità tal-oġġetti: %d %%",
        L"Veloċità tal-kamera: %d %%",
        L"Osservazzjoni tal-ispazju",
        L"Titjira fl-ispazju",
        L"Dawl ewlieni",
        L"Dawl ta’ mili",
        L"Oġġetti solidi 3D",
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
        MALTESE_SOLIDS
    }, LocalizedText{
        L"Nederlands",
        L"FlyingSolids — bediening",
        L"Instellingen van FlyingSolids",
        L"Taal:",
        L"Objectsnelheid: %d %%",
        L"Camerasnelheid: %d %%",
        L"Ruimte observeren",
        L"Door de ruimte vliegen",
        L"Hoofdlicht",
        L"Invullicht",
        L"Massieve 3D-objecten",
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
        DUTCH_SOLIDS
    }, LocalizedText{
        L"Română",
        L"FlyingSolids — comenzi",
        L"Setări FlyingSolids",
        L"Limbă:",
        L"Viteza obiectelor: %d %%",
        L"Viteza camerei: %d %%",
        L"Observarea spațiului",
        L"Zbor prin spațiu",
        L"Lumină principală",
        L"Lumină de umplere",
        L"Corpuri tridimensionale",
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
        ROMANIAN_SOLIDS
    }, LocalizedText{
        L"Ελληνικά",
        L"FlyingSolids — χειρισμός",
        L"Ρυθμίσεις FlyingSolids",
        L"Γλώσσα:",
        L"Ταχύτητα αντικειμένων: %d %%",
        L"Ταχύτητα κάμερας: %d %%",
        L"Παρατήρηση χώρου",
        L"Πτήση στον χώρο",
        L"Κύριος φωτισμός",
        L"Φωτισμός πλήρωσης",
        L"Τρισδιάστατα στερεά",
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
        GREEK_SOLIDS
    }, LocalizedText{
        L"Bosanski",
        L"FlyingSolids — kontrole",
        L"Postavke programa FlyingSolids",
        L"Jezik:",
        L"Brzina objekata: %d %%",
        L"Brzina kamere: %d %%",
        L"Posmatranje prostora",
        L"Let kroz prostor",
        L"Glavno svjetlo",
        L"Dopunsko svjetlo",
        L"Prostorna tijela",
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
        BOSNIAN_SOLIDS
    }, LocalizedText{
        L"Hrvatski",
        L"FlyingSolids — upravljanje",
        L"Postavke programa FlyingSolids",
        L"Jezik:",
        L"Brzina objekata: %d %%",
        L"Brzina kamere: %d %%",
        L"Promatranje prostora",
        L"Let kroz prostor",
        L"Glavno svjetlo",
        L"Dopunsko svjetlo",
        L"Prostorna tijela",
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
        CROATIAN_SOLIDS
    }, LocalizedText{
        L"Slovenščina",
        L"FlyingSolids — upravljanje",
        L"Nastavitve FlyingSolids",
        L"Jezik:",
        L"Hitrost predmetov: %d %%",
        L"Hitrost kamere: %d %%",
        L"Opazovanje prostora",
        L"Let skozi prostor",
        L"Glavna svetloba",
        L"Dopolnilna svetloba",
        L"Prostorska telesa",
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
        SLOVENIAN_SOLIDS
    }, LocalizedText{
        L"Crnogorski",
        L"FlyingSolids — kontrole",
        L"Podešavanja programa FlyingSolids",
        L"Jezik:",
        L"Brzina objekata: %d %%",
        L"Brzina kamere: %d %%",
        L"Posmatranje prostora",
        L"Let kroz prostor",
        L"Glavno svjetlo",
        L"Dopunsko svjetlo",
        L"Prostorna tijela",
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
        MONTENEGRIN_SOLIDS
    }, LocalizedText{
        L"Беларуская",
        L"FlyingSolids — кіраванне",
        L"Налады FlyingSolids",
        L"Мова:",
        L"Хуткасць аб’ектаў: %d %%",
        L"Хуткасць камеры: %d %%",
        L"Назіранне за прасторай",
        L"Палёт праз прастору",
        L"Асноўнае святло",
        L"Запаўняльнае святло",
        L"Аб’ёмныя целы",
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
        BELARUSIAN_SOLIDS
    }, LocalizedText{
        L"Български",
        L"FlyingSolids — управление",
        L"Настройки на FlyingSolids",
        L"Език:",
        L"Скорост на обектите: %d %%",
        L"Скорост на камерата: %d %%",
        L"Наблюдение на пространството",
        L"Полет през пространството",
        L"Основна светлина",
        L"Запълваща светлина",
        L"Обемни тела",
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
        BULGARIAN_SOLIDS
    }, LocalizedText{
        L"Македонски",
        L"FlyingSolids — контроли",
        L"Поставки за FlyingSolids",
        L"Јазик:",
        L"Брзина на објектите: %d %%",
        L"Брзина на камерата: %d %%",
        L"Набљудување на просторот",
        L"Лет низ просторот",
        L"Главно светло",
        L"Дополнително светло",
        L"Просторни тела",
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
        MACEDONIAN_SOLIDS
    }, LocalizedText{
        L"Српски",
        L"FlyingSolids — контроле",
        L"Подешавања програма FlyingSolids",
        L"Језик:",
        L"Брзина објеката: %d %%",
        L"Брзина камере: %d %%",
        L"Посматрање простора",
        L"Лет кроз простор",
        L"Главно светло",
        L"Допунско светло",
        L"Просторна тела",
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
        SERBIAN_SOLIDS
    }, LocalizedText{
        L"Українська",
        L"FlyingSolids — керування",
        L"Налаштування FlyingSolids",
        L"Мова:",
        L"Швидкість об’єктів: %d %%",
        L"Швидкість камери: %d %%",
        L"Спостереження за простором",
        L"Політ крізь простір",
        L"Основне світло",
        L"Заповнювальне світло",
        L"Об’ємні тіла",
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
        UKRAINIAN_SOLIDS
    }, LocalizedText{
        L"Русский",
        L"FlyingSolids — управление",
        L"Настройки FlyingSolids",
        L"Язык:",
        L"Скорость объектов: %d %%",
        L"Скорость камеры: %d %%",
        L"Наблюдение за пространством",
        L"Полёт сквозь пространство",
        L"Основной свет",
        L"Заполняющий свет",
        L"Объёмные тела",
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
        RUSSIAN_SOLIDS
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

/// Supplementary settings-window text
constexpr std::array<const wchar_t*, LANGUAGE_COUNT> COPY_COUNT_TEXTS = {
    L"Počet kopií každého objektu: %d",
    L"Copies of each object: %d",
    L"Copies of each object: %d",
    L"Copies of each object: %d",
    L"Kopien je Objekt: %d",
    L"Copies de chaque objet : %d",
    L"Copias de cada objeto: %d",
    L"Copie di ogni oggetto: %d",
    L"Cópias de cada objeto: %d",
    L"Liczba kopii każdego obiektu: %d",
    L"Počet kópií každého objektu: %d",
    L"Kopier af hvert objekt: %d",
    L"Kunkin kohteen kopioita: %d",
    L"Afrit af hverjum hlut: %d",
    L"Kopier av hvert objekt: %d",
    L"Kopior av varje objekt: %d",
    L"Her nesnenin kopya sayısı: %d",
    L"Iga objekti koopiaid: %d",
    L"Cóipeanna de gach réad: %d",
    L"Kiekvieno objekto kopijų: %d",
    L"Katra objekta kopijas: %d",
    L"Az egyes objektumok példányai: %d",
    L"Kopji ta’ kull oġġett: %d",
    L"Kopieën van elk object: %d",
    L"Copii ale fiecărui obiect: %d",
    L"Αντίγραφα κάθε αντικειμένου: %d",
    L"Kopije svakog objekta: %d",
    L"Kopije svakog objekta: %d",
    L"Kopije posameznega predmeta: %d",
    L"Kopije svakog objekta: %d",
    L"Копій кожнага аб’екта: %d",
    L"Копия на всеки обект: %d",
    L"Копии од секој објект: %d",
    L"Копије сваког објекта: %d",
    L"Копій кожного об’єкта: %d",
    L"Копий каждого объекта: %d"
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> OBJECT_SIZE_TEXTS = {
    L"Velikost objektů: %d %%",
    L"Object size: %d %%",
    L"Object size: %d %%",
    L"Object size: %d %%",
    L"Objektgröße: %d %%",
    L"Taille des objets : %d %%",
    L"Tamaño de objetos: %d %%",
    L"Dimensione oggetti: %d %%",
    L"Tamanho dos objetos: %d %%",
    L"Rozmiar obiektów: %d %%",
    L"Veľkosť objektov: %d %%",
    L"Objektstørrelse: %d %%",
    L"Kohteiden koko: %d %%",
    L"Stærð hluta: %d %%",
    L"Objektstørrelse: %d %%",
    L"Objektstorlek: %d %%",
    L"Nesne boyutu: %%%d",
    L"Objektide suurus: %d %%",
    L"Méid na réad: %d %%",
    L"Objektų dydis: %d %%",
    L"Objektu izmērs: %d %%",
    L"Objektumok mérete: %d %%",
    L"Daqs tal-oġġetti: %d %%",
    L"Objectgrootte: %d %%",
    L"Dimensiunea obiectelor: %d %%",
    L"Μέγεθος αντικειμένων: %d %%",
    L"Veličina objekata: %d %%",
    L"Veličina objekata: %d %%",
    L"Velikost predmetov: %d %%",
    L"Veličina objekata: %d %%",
    L"Памер аб’ектаў: %d %%",
    L"Размер на обектите: %d %%",
    L"Големина на објектите: %d %%",
    L"Величина објеката: %d %%",
    L"Розмір об’єктів: %d %%",
    L"Размер объектов: %d %%"
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
    L"Odinstalace se nezdařila, protože je otevřené nastavení FlyingSolids. Zavřete je a odinstalaci "
    L"zopakujte.",
    L"Uninstallation failed because FlyingSolids settings are open. Close the settings window and try again.",
    L"Uninstallation failed because FlyingSolids settings are open. Close the settings window and try again.",
    L"Uninstallation failed because FlyingSolids settings are open. Close the settings window and try again.",
    L"Die Deinstallation ist fehlgeschlagen, weil die FlyingSolids-Einstellungen geöffnet sind. Schließen "
    L"Sie das Fenster und versuchen Sie es erneut.",
    L"La désinstallation a échoué car les paramètres de FlyingSolids sont ouverts. Fermez cette fenêtre "
    L"puis réessayez.",
    L"La desinstalación falló porque la configuración de FlyingSolids está abierta. Cierre esa ventana e "
    L"inténtelo de nuevo.",
    L"La disinstallazione non è riuscita perché le impostazioni di FlyingSolids sono aperte. Chiudere la "
    L"finestra e riprovare.",
    L"A desinstalação falhou porque as definições do FlyingSolids estão abertas. Feche a janela e tente "
    L"novamente.",
    L"Odinstalowanie nie powiodło się, ponieważ ustawienia FlyingSolids są otwarte. Zamknij okno i spróbuj "
    L"ponownie.",
    L"Odinštalovanie zlyhalo, pretože sú otvorené nastavenia FlyingSolids. Zatvorte ich a skúste to znova.",
    L"Afinstallationen mislykkedes, fordi indstillingerne for FlyingSolids er åbne. Luk vinduet, og prøv "
    L"igen.",
    L"Asennuksen poisto epäonnistui, koska FlyingSolids-asetukset ovat avoinna. Sulje ikkuna ja yritä "
    L"uudelleen.",
    L"Fjarlæging mistókst vegna þess að stillingar FlyingSolids eru opnar. Lokaðu glugganum og reyndu aftur.",
    L"Avinstalleringen mislyktes fordi innstillingene for FlyingSolids er åpne. Lukk vinduet og prøv på "
    L"nytt.",
    L"Avinstallationen misslyckades eftersom inställningarna för FlyingSolids är öppna. Stäng fönstret och "
    L"försök igen.",
    L"FlyingSolids ayarları açık olduğu için kaldırma başarısız oldu. Ayarlar penceresini kapatıp yeniden "
    L"deneyin.",
    L"Sulgege FlyingSolids sätete aken ja proovige eemaldamist uuesti.",
    L"Dún fuinneog socruithe FlyingSolids agus bain triail eile as an díshuiteáil.",
    L"Uždarykite FlyingSolids nuostatų langą ir bandykite pašalinti dar kartą.",
    L"Aizveriet FlyingSolids iestatījumu logu un atkārtojiet atinstalēšanu.",
    L"Zárja be a FlyingSolids beállítási ablakát, majd próbálja újra az eltávolítást.",
    L"Agħlaq it-tieqa tas-settings ta’ FlyingSolids u erġa’ pprova tneħħih.",
    L"Sluit de instellingen van FlyingSolids en probeer het verwijderen opnieuw.",
    L"Închideți fereastra de setări FlyingSolids și încercați din nou dezinstalarea.",
    L"Κλείστε το παράθυρο ρυθμίσεων του FlyingSolids και δοκιμάστε ξανά την κατάργηση.",
    L"Zatvorite postavke programa FlyingSolids pa ponovite deinstalaciju.",
    L"Zatvorite postavke programa FlyingSolids pa ponovite deinstalaciju.",
    L"Zaprite nastavitve FlyingSolids in znova poskusite odstranitev.",
    L"Zatvorite podešavanja programa FlyingSolids pa ponovite deinstalaciju.",
    L"Закрыйце налады FlyingSolids ды паўтарыце выдаленне.",
    L"Затворете настройките на FlyingSolids и опитайте деинсталирането отново.",
    L"Затворете ги поставките за FlyingSolids и обидете се повторно да деинсталирате.",
    L"Затворите подешавања програма FlyingSolids па поновите деинсталацију.",
    L"Закрийте налаштування FlyingSolids та повторіть видалення.",
    L"Закройте настройки FlyingSolids и повторите удаление."
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
    L"ANIMACE A NASTAVENÍ\r\nV seznamu označte jeden nebo více monitorů. Režim kamery, výběr těles, světla, "
    L"rychlosti, velikost a počet kopií se nastavují jen pro označené monitory a každý monitor si pamatuje "
    L"vlastní nastavení. FlyingSolids zobrazuje osvětlená plná prostorová tělesa. Jezdci nastavují rychlost "
    L"objektů a kamery v rozsahu 0–1600 %, jednu až deset kopií každého tělesa a velikost 50–200 %. Vyberte "
    L"Pozorování prostoru nebo přímý Průlet prostorem a zaškrtněte požadované druhy těles. Zatržítka Hlavní "
    L"světlo, Doplňkové světlo, Základní jas a Přisvětlení obrysů pod jezdci nezávisle ovládají osvětlení "
    L"celé scény. Základní jas přisvětluje povrch těles, přisvětlení obrysů zvýrazňuje jejich okraje. "
    L"Nastavení osvětlení se ukládá zvlášť pro aplikaci a spořič obrazovky.\r\n\r\nMONITORY\r\nOznačení "
    L"řádků určuje, které monitory právě nastavujete; není totožné se zatržítky zapínajícími animační "
    L"výstupy. Ctrl+A označí všechny monitory, Ctrl a Shift umožňují upravit označení. Všechny animační "
    L"volby a jezdce platí pro označené monitory. Označení se pamatuje zvlášť pro EXE a SCR. Pokud byly "
    L"označené všechny monitory, označí se i nově připojené. Různé hodnoty na označených monitorech ukazuje "
    L"neurčitý stav zatržítek a tečkování přepínačů, úchytů jezdců a tlačítek pro zapnutí či vypnutí všech "
    L"voleb. Popisek jezdce místo společné hodnoty zobrazuje pomlčku. Změna volby nebo kliknutí na jezdec "
    L"sjednotí příslušnou hodnotu na označených monitorech.\r\n\r\nOVLÁDÁNÍ\r\nAnimační výstupy zapnete "
    L"nebo vypnete zatržítky u monitorů nebo dvojklikem na jejich řádky. Každý monitor používá nezávislou "
    L"scénu. Snímek ukládá PNG, tlačítko záznamu spouští a ukončuje MP4. Pozastavení zastaví animaci. "
    L"Aplikace také instaluje nebo odinstaluje zabalený spořič. Nastavení se ukládá průběžně. Aplikace běží "
    L"pouze v jedné instanci. Další spuštění obnoví minimalizované ovládací okno a přenese do popředí. Mezi "
    L"ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a "
    L"příslušného písmene. Esc zavře aktivní nápovědu či okno O aplikaci; v ovládacím okně ukončí aplikaci. "
    L"Pozastavení a blokování spořiče platí pro celou aplikaci bez ohledu na označené monitory. Je-li "
    L"blokování zapnuté, brání spuštění spořiče Windows pouze tehdy, když je alespoň na jednom monitoru "
    L"viditelná nepozastavená animace.\r\n\r\nSNÍMKY A ZÁZNAM\r\nSnímek a záznam zachycují první aktivní "
    L"animační monitor, nikoli společnou plochu všech monitorů. PNG používá složku Obrázky, MP4 složku "
    L"Videa; při jejich neexistenci se použijí Dokumenty. Tlačítko Nastavení záznamu vybírá Viewport nebo "
    L"TV. Viewport zachovává rozměry animačního monitoru a jeho obnovovací frekvenci, nejvýše 60 snímků za "
    L"sekundu. TV nabízí rozlišení 1920 × 1080, 1440 × 1080 nebo 1280 × 720 v poměru 16:9 a frekvenci 50, "
    L"25, 59.94 (60000/1001) nebo 29.97 (30000/1001) snímků za sekundu. Obraz zachovává poměr stran; TV "
    L"používá progresivní video BT.709 s omezeným rozsahem a vzorkováním 4:2:0. Rozlišení a snímkovou "
    L"frekvenci lze vybrat pouze v režimu TV. Okno Nastavení záznamu lze minimalizovat a neblokuje ostatní "
    L"okna aplikace. OK uloží volby pro příští záznam MP4; Storno nebo Esc nepotvrzené změny zahodí. "
    L"Nahrávaný monitor nelze během záznamu odepnout; změny ostatních monitorů záznam nezastaví. Ukončení "
    L"aplikace při probíhajícím záznamu vyžaduje potvrzení, protože současně ukončí "
    L"záznam.\r\n\r\nSYSTÉMOVÉ POŽADAVKY\r\nWindows 7 až Windows 11 podporují všechny funkce včetně snímků "
    L"PNG a záznamu MP4. Pro spuštění aplikace ve Windows Vista SP2 je nutné nainstalovat aktualizace "
    L"KB971512 a KB2117917. Záznam MP4 na Vistě v současné verzi nefunguje. Vykreslování vyžaduje Direct3D "
    L"11, nikoli jen starší DirectX runtime. Záznam MP4 vyžaduje dostupné součásti Media Foundation a kodér "
    L"H.264.",
    L"ANIMATION AND SETTINGS\r\nSelect one or more displays in the list. Camera mode, object selection, "
    L"lighting, speeds, size and copy count apply only to the selected displays, and each display remembers "
    L"its own settings. FlyingSolids displays illuminated solid 3D objects. The sliders set object and "
    L"camera speed from 0–1600%, one to ten copies of each object, and size from 50–200%. Choose Space "
    L"observation or the straight Fly through space mode and enable the required object types. The Main "
    L"light, Fill light, Ambient light, and Rim light checkboxes below the sliders independently control "
    L"lighting for the whole scene. Ambient light provides base illumination of object surfaces; rim light "
    L"highlights their edges. Lighting settings are stored separately for the application and screen "
    L"saver.\r\n\r\nDISPLAYS\r\nRow selection determines which displays you are editing; it is separate "
    L"from the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and Shift "
    L"adjust the selection. All animation options and sliders apply to the selected displays. The selection "
    L"is remembered separately for EXE and SCR. If all displays were selected, newly connected displays "
    L"join the selection. Different values across selected displays are indicated by indeterminate "
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
    L"ANIMATION AND SETTINGS\r\nSelect one or more displays in the list. Camera mode, object selection, "
    L"lighting, speeds, size and copy count apply only to the selected displays, and each display remembers "
    L"its own settings. FlyingSolids displays illuminated solid 3D objects. The sliders set object and "
    L"camera speed from 0–1600%, one to ten copies and size from 50–200%. Choose Space observation or the "
    L"straight Fly through space mode and enable the required objects. The Main light, Fill light, Ambient "
    L"light, and Rim light checkboxes below the sliders independently control lighting for the whole scene. "
    L"Ambient light provides base illumination of object surfaces; rim light highlights their edges. "
    L"Lighting settings are stored separately for the application and screen saver.\r\n\r\nDISPLAYS\r\nRow "
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
    L"ANIMATION AND SETTINGS\r\nSelect one or more displays in the list. Camera mode, object selection, "
    L"lighting, speeds, size and copy count apply only to the selected displays, and each display remembers "
    L"its own settings. FlyingSolids displays illuminated solid 3D objects. The sliders set object and "
    L"camera speed from 0–1600%, one to ten copies and size from 50–200%. Choose Space observation or the "
    L"straight Fly through space mode and enable the required objects. The Main light, Fill light, Ambient "
    L"light, and Rim light checkboxes below the sliders independently control lighting for the whole scene. "
    L"Ambient light provides base illumination of object surfaces; rim light highlights their edges. "
    L"Lighting settings are stored separately for the application and screen saver.\r\n\r\nDISPLAYS\r\nRow "
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
    L"ANIMATION UND EINSTELLUNGEN\r\nMarkieren Sie einen oder mehrere Monitore in der Liste. Kameramodus, "
    L"Körperauswahl, Beleuchtung, Geschwindigkeiten, Größe und Anzahl der Exemplare gelten nur für die "
    L"markierten Monitore. Jeder Monitor speichert seine eigenen Einstellungen. FlyingSolids zeigt "
    L"beleuchtete dreidimensionale Volumenkörper. Die Regler bestimmen Objekt- und Kamerageschwindigkeit "
    L"von 0–1600 %, ein bis zehn Exemplare je Körper und eine Größe von 50–200 %. Wählen Sie "
    L"Raumbeobachtung oder Flug durch den Raum in gerader Linie und aktivieren Sie die gewünschten Körper. "
    L"Die Kontrollkästchen Hauptlicht, Aufhelllicht, Umgebungslicht und Konturlicht unter den Reglern "
    L"steuern die Beleuchtung der gesamten Szene unabhängig voneinander. Umgebungslicht sorgt für eine "
    L"Grundhelligkeit der Körperoberflächen, Konturlicht betont ihre Ränder. Die Beleuchtungseinstellungen "
    L"werden für Anwendung und Bildschirmschoner getrennt gespeichert.\r\n\r\nMONITORE\r\nDie Zeilenauswahl "
    L"bestimmt, welche Monitore Sie bearbeiten; sie ist von den Kontrollkästchen zum Einschalten der "
    L"Animationsausgabe getrennt. Strg+A wählt alle Monitore, Strg und Umschalt ändern die Auswahl. Alle "
    L"Animationsoptionen und Regler gelten für die ausgewählten Monitore. Die Auswahl wird für EXE und SCR "
    L"getrennt gespeichert. Waren alle Monitore ausgewählt, werden auch neu angeschlossene ausgewählt. "
    L"Unterschiedliche Werte der ausgewählten Monitore werden durch unbestimmte Kontrollkästchen und "
    L"gepunktete Optionsfelder, Reglergriffe sowie Schaltflächen zum Ein- oder Ausschalten aller Optionen "
    L"angezeigt. Reglerbeschriftungen zeigen statt eines gemeinsamen Werts einen Gedankenstrich. Das Ändern "
    L"einer Option oder Anklicken eines Reglers übernimmt diesen Wert für alle ausgewählten "
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
    L"ANIMATION ET PARAMÈTRES\r\nSélectionnez un ou plusieurs écrans dans la liste. Le mode de caméra, les "
    L"objets, l’éclairage, les vitesses, la taille et le nombre de copies ne s’appliquent qu’aux écrans "
    L"sélectionnés. Chaque écran mémorise ses propres réglages. FlyingSolids affiche des solides 3D "
    L"éclairés. Les curseurs règlent la vitesse des objets et de la caméra de 0 à 1 600 %, une à dix copies "
    L"de chaque solide et une taille de 50 à 200 %. Choisissez Observation de l’espace ou le Vol dans "
    L"l’espace rectiligne, puis activez les solides voulus. Les cases Éclairage principal, Éclairage "
    L"d’appoint, Éclairage ambiant et Éclairage des contours sous les curseurs contrôlent indépendamment "
    L"l’éclairage de toute la scène. L’éclairage ambiant fournit une luminosité de base aux surfaces, et "
    L"l’éclairage des contours souligne leurs bords. Les réglages sont enregistrés séparément pour "
    L"l’application et l’économiseur d’écran.\r\n\r\nÉCRANS\r\nLa sélection des lignes détermine les écrans "
    L"à configurer ; elle est distincte des cases qui activent les sorties d’animation. Ctrl+A sélectionne "
    L"tous les écrans ; Ctrl et Maj modifient la sélection. Toutes les options et tous les curseurs "
    L"d’animation concernent les écrans sélectionnés. La sélection est mémorisée séparément pour EXE et "
    L"SCR. Si tous les écrans étaient sélectionnés, les nouveaux le sont également. Des valeurs différentes "
    L"entre les écrans sélectionnés sont indiquées par des cases à cocher indéterminées et des pointillés "
    L"sur les boutons radio, les poignées des curseurs et les boutons d’activation ou de désactivation de "
    L"toutes les options. Les libellés des curseurs affichent un tiret au lieu d’une valeur commune. "
    L"Modifier une option ou cliquer sur un curseur applique cette valeur à tous les écrans "
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
    L"ANIMACIÓN Y AJUSTES\r\nSeleccione una o varias pantallas en la lista. El modo de cámara, los objetos, "
    L"la iluminación, las velocidades, el tamaño y el número de copias se aplican solo a las pantallas "
    L"seleccionadas. Cada pantalla guarda sus propios ajustes. FlyingSolids muestra sólidos 3D iluminados. "
    L"Los controles ajustan la velocidad de objetos y cámara entre 0 y 1600 %, de una a diez copias y el "
    L"tamaño entre 50 y 200 %. Elija Observación del espacio o el Vuelo por el espacio en línea recta y "
    L"active los sólidos deseados. Las casillas Luz principal, Luz de relleno, Luz ambiental e Iluminación "
    L"de contornos bajo los controles deslizantes controlan de forma independiente la iluminación de toda "
    L"la escena. La luz ambiental aporta iluminación básica a las superficies y la iluminación de contornos "
    L"resalta sus bordes. De forma predeterminada, las luces principal, ambiental y de contornos están "
    L"activadas, y la luz de relleno está desactivada. Los ajustes se guardan por separado para la "
    L"aplicación y el salvapantallas.\r\n\r\nMONITORES\r\nLa selección de filas determina qué pantallas se "
    L"están configurando; es independiente de las casillas que activan las salidas de animación. Ctrl+A "
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
    L"ANIMAZIONE E IMPOSTAZIONI\r\nSelezionare uno o più monitor nell’elenco. La modalità della telecamera, "
    L"gli oggetti, le luci, le velocità, le dimensioni e il numero di copie si applicano solo ai monitor "
    L"selezionati. Ogni monitor conserva le proprie impostazioni. FlyingSolids mostra solidi 3D illuminati. "
    L"I cursori regolano la velocità di oggetti e camera tra 0 e 1600 %, da una a dieci copie e la "
    L"dimensione tra 50 e 200 %. Scegliere Osservazione dello spazio o il Volo nello spazio rettilineo e "
    L"attivare i solidi desiderati. Le caselle Luce principale, Luce di riempimento, Luce ambientale e "
    L"Illuminazione dei contorni sotto i cursori controllano indipendentemente l’illuminazione dell’intera "
    L"scena. La luce ambientale fornisce un’illuminazione di base alle superfici, mentre quella dei "
    L"contorni ne evidenzia i bordi. Le impostazioni vengono salvate separatamente per l’applicazione e il "
    L"salvaschermo.\r\n\r\nMONITOR\r\nLa selezione delle righe determina quali schermi si stanno "
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
    L"ANIMAÇÃO E DEFINIÇÕES\r\nSelecione um ou mais monitores na lista. O modo de câmara, os objetos, a "
    L"iluminação, as velocidades, o tamanho e o número de cópias aplicam-se apenas aos monitores "
    L"selecionados. Cada monitor guarda as suas próprias definições. O FlyingSolids mostra sólidos 3D "
    L"iluminados. Os controlos regulam a velocidade dos objetos e da câmara entre 0 e 1600%, uma a dez "
    L"cópias e o tamanho entre 50 e 200%. Escolha Observação do espaço ou o Voo pelo espaço em linha reta e "
    L"ative os sólidos pretendidos. As caixas Luz principal, Luz de preenchimento, Luz ambiente e "
    L"Iluminação dos contornos sob os controlos deslizantes controlam a iluminação de toda a cena de forma "
    L"independente. A luz ambiente fornece iluminação de base às superfícies e a iluminação dos contornos "
    L"realça os seus limites. Por predefinição, as luzes principal, ambiente e dos contornos estão ligadas "
    L"e a luz de preenchimento está desligada. As definições são guardadas separadamente para a aplicação e "
    L"a proteção de ecrã.\r\n\r\nMONITORES\r\nA seleção das linhas determina os ecrãs a configurar e é "
    L"independente das caixas que ativam as saídas de animação. Ctrl+A seleciona todos os ecrãs; Ctrl e "
    L"Shift alteram a seleção. Todas as opções e controlos deslizantes da animação aplicam-se aos ecrãs "
    L"selecionados. A seleção é guardada separadamente para EXE e SCR. Se todos estavam selecionados, os "
    L"novos ecrãs também são incluídos. Valores diferentes entre os ecrãs selecionados são indicados por "
    L"caixas de verificação indeterminadas e por um padrão pontilhado nos botões de opção, nas pegas dos "
    L"controlos deslizantes e nos botões para ativar ou desativar todas as opções. As etiquetas dos "
    L"controlos deslizantes apresentam um travessão em vez de um valor comum. Alterar uma opção ou clicar "
    L"num controlo deslizante aplica esse valor a todos os ecrãs selecionados.\r\n\r\nCONTROLOS\r\nAtive ou "
    L"desative as saídas de animação através das caixas dos ecrãs ou com um duplo clique nas respetivas "
    L"linhas. Cada monitor usa uma cena independente. Captura guarda PNG e o botão de gravação inicia ou "
    L"termina MP4. Pausa para a animação. A aplicação também instala ou desinstala a proteção de ecrã "
    L"incorporada. As definições são guardadas continuamente. A aplicação só pode ter uma instância em "
    L"execução. Um novo arranque restaura a janela de controlo minimizada e coloca-a em primeiro plano. Use "
    L"Tab e Shift+Tab para passar entre controlos; Alt e a letra sublinhada ativam um comando. Esc fecha a "
    L"janela ativa de Ajuda ou Acerca de; na janela de controlo, termina a aplicação. A pausa e o bloqueio "
    L"da proteção de ecrã aplicam-se a toda a aplicação, independentemente dos ecrãs selecionados. Com o "
    L"bloqueio ativo, a proteção de ecrã do Windows só é impedida enquanto existir animação visível e não "
    L"pausada em pelo menos um ecrã.\r\n\r\nCAPTURAS E GRAVAÇÃO\r\nAs capturas e gravações usam o primeiro "
    L"monitor de animação ativo, não uma imagem conjunta de todos os monitores. PNG usa Imagens, MP4 "
    L"Vídeos; se essas pastas não existirem, usa-se Documentos. O botão Definições de gravação permite "
    L"escolher Viewport ou TV. Viewport conserva as dimensões e a frequência de atualização do monitor de "
    L"animação, até 60 fotogramas por segundo. TV oferece 1920 × 1080, 1440 × 1080 ou 1280 × 720 no formato "
    L"16:9, a 50, 25, 59.94 (60000/1001) ou 29.97 (30000/1001) fotogramas por segundo. A proporção da "
    L"imagem é mantida; TV usa vídeo progressivo BT.709 com intervalo limitado e amostragem 4:2:0. A "
    L"resolução e a frequência só estão disponíveis no modo TV. A janela Definições de gravação pode ser "
    L"minimizada e não bloqueia as outras janelas da aplicação. OK guarda as escolhas para a próxima "
    L"gravação MP4; Cancelar ou Esc descarta as alterações não confirmadas. O monitor gravado não pode ser "
    L"desmarcado durante a gravação; as alterações aos outros monitores não a interrompem. Fechar a "
    L"aplicação durante uma gravação exige confirmação, pois também termina a gravação.\r\n\r\nREQUISITOS "
    L"DO SISTEMA\r\nOs sistemas Windows 7 a Windows 11 suportam todas as funcionalidades, incluindo "
    L"capturas PNG e gravação MP4. Para executar a aplicação no Windows Vista SP2, é necessário instalar as "
    L"atualizações KB971512 e KB2117917. A gravação MP4 não funciona no Vista na versão atual. A "
    L"apresentação requer Direct3D 11, não apenas um runtime DirectX mais antigo. A gravação MP4 requer "
    L"componentes Media Foundation e um codificador H.264 disponíveis.",
    L"ANIMACJA I USTAWIENIA\r\nZaznacz jeden lub więcej monitorów na liście. Tryb kamery, wybór brył, "
    L"oświetlenie, prędkości, rozmiar i liczba kopii dotyczą tylko zaznaczonych monitorów. Każdy monitor "
    L"zapamiętuje własne ustawienia. FlyingSolids wyświetla oświetlone pełne bryły 3D. Suwaki ustawiają "
    L"prędkość obiektów i kamery od 0 do 1600%, od jednej do dziesięciu kopii i rozmiar od 50 do 200%. "
    L"Wybierz Obserwację przestrzeni lub prostoliniowy Przelot przez przestrzeń i włącz potrzebne bryły. "
    L"Pola wyboru Światło główne, Światło wypełniające, Światło otoczenia i Oświetlenie konturów pod "
    L"suwakami niezależnie sterują oświetleniem całej sceny. Światło otoczenia zapewnia podstawową jasność "
    L"powierzchni, a oświetlenie konturów podkreśla krawędzie. Ustawienia są zapisywane osobno dla "
    L"aplikacji i wygaszacza ekranu.\r\n\r\nMONITORY\r\nZaznaczenie wierszy określa konfigurowane monitory "
    L"i jest niezależne od pól wyboru włączających wyjścia animacji. Ctrl+A zaznacza wszystkie monitory; "
    L"Ctrl i Shift zmieniają zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą zaznaczonych monitorów. "
    L"Zaznaczenie jest zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były wszystkie monitory, nowe "
    L"również zostaną zaznaczone. Różne wartości na zaznaczonych monitorach są sygnalizowane nieokreślonym "
    L"stanem pól wyboru i kropkowaniem przycisków opcji, uchwytów suwaków oraz przycisków włączania i "
    L"wyłączania wszystkich opcji. Etykiety suwaków pokazują kreskę zamiast wspólnej wartości. Zmiana opcji "
    L"lub kliknięcie suwaka ustawia tę wartość na wszystkich zaznaczonych "
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
    L"ANIMÁCIA A NASTAVENIA\r\nV zozname označte jeden alebo viac monitorov. Režim kamery, výber telies, "
    L"svetlá, rýchlosti, veľkosť a počet kópií sa nastavujú len pre označené monitory a každý monitor si "
    L"pamätá vlastné nastavenia. FlyingSolids zobrazuje osvetlené plné 3D telesá. Jazdce nastavujú rýchlosť "
    L"objektov a kamery 0–1600 %, jednu až desať kópií a veľkosť 50–200 %. Vyberte Pozorovanie priestoru "
    L"alebo priamy Prelet priestorom a zapnite požadované telesá. Začiarkavacie políčka Hlavné svetlo, "
    L"Doplnkové svetlo, Základný jas a Prisvetlenie obrysov pod jazdcami nezávisle ovládajú osvetlenie "
    L"celej scény. Základný jas prisvetľuje povrchy telies a prisvetlenie obrysov zvýrazňuje ich okraje. "
    L"Nastavenia osvetlenia sa ukladajú zvlášť pre aplikáciu a šetrič "
    L"obrazovky.\r\n\r\nMONITORY\r\nOznačenie riadkov určuje, ktoré monitory práve nastavujete; je "
    L"nezávislé od políčok zapínajúcich animačné výstupy. Ctrl+A označí všetky monitory, Ctrl a Shift "
    L"upravujú označenie. Všetky animačné voľby a posuvníky platia pre označené monitory. Označenie sa "
    L"pamätá zvlášť pre EXE a SCR. Ak boli označené všetky monitory, označia sa aj novopripojené. Rozdielne "
    L"hodnoty na označených monitoroch ukazuje neurčitý stav políčok a bodkovanie prepínačov, úchytov "
    L"posuvníkov a tlačidiel na zapnutie či vypnutie všetkých volieb. Popis posuvníka namiesto spoločnej "
    L"hodnoty zobrazuje pomlčku. Zmena voľby alebo kliknutie na posuvník zjednotí príslušnú hodnotu na "
    L"označených monitoroch.\r\n\r\nOVLÁDANIE\r\nAnimačné výstupy zapnete alebo vypnete políčkami pri "
    L"monitoroch alebo dvojklikom na ich riadky. Každý monitor používa nezávislú scénu. Snímka uloží PNG a "
    L"tlačidlo záznamu spustí alebo ukončí MP4. Pozastavenie zastaví animáciu. Aplikácia tiež nainštaluje "
    L"alebo odinštaluje vložený šetrič. Nastavenia sa ukladajú priebežne. Aplikácia beží iba v jednej "
    L"inštancii. Ďalšie spustenie obnoví minimalizované ovládacie okno a prenesie do popredia. Medzi "
    L"ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a "
    L"príslušného písmena. Esc zavrie aktívne okno Pomocníka alebo O aplikácii; v ovládacom okne ukončí "
    L"aplikáciu. Pozastavenie a blokovanie šetriča platia pre celú aplikáciu bez ohľadu na označené "
    L"monitory. Ak je blokovanie zapnuté, bráni spusteniu šetriča Windows iba vtedy, keď je aspoň na jednom "
    L"monitore viditeľná nepozastavená animácia.\r\n\r\nSNÍMKY A ZÁZNAM\r\nSnímky a záznamy zachytávajú "
    L"prvý aktívny animačný monitor, nie spoločnú plochu všetkých monitorov. PNG používa Obrázky, MP4 "
    L"Videá; ak tieto priečinky neexistujú, použijú sa Dokumenty. Tlačidlo Nastavenie záznamu vyberá "
    L"Viewport alebo TV. Viewport zachováva rozmery animačného monitora a jeho obnovovaciu frekvenciu, "
    L"najviac 60 snímok za sekundu. TV ponúka rozlíšenie 1920 × 1080, 1440 × 1080 alebo 1280 × 720 v pomere "
    L"16:9 a frekvenciu 50, 25, 59.94 (60000/1001) alebo 29.97 (30000/1001) snímok za sekundu. Obraz "
    L"zachováva pomer strán; TV používa progresívne video BT.709 s obmedzeným rozsahom a vzorkovaním 4:2:0. "
    L"Rozlíšenie a snímkovú frekvenciu možno vybrať iba v režime TV. Okno Nastavenie záznamu možno "
    L"minimalizovať a neblokuje ostatné okná aplikácie. OK uloží voľby pre nasledujúci záznam MP4; Zrušiť "
    L"alebo Esc zahodí nepotvrdené zmeny. Nahrávaný monitor nemožno počas záznamu odpojiť; zmeny ostatných "
    L"monitorov záznam nezastavia. Ukončenie aplikácie počas záznamu vyžaduje potvrdenie, pretože ukončí aj "
    L"záznam.\r\n\r\nSYSTÉMOVÉ POŽIADAVKY\r\nWindows 7 až Windows 11 podporujú všetky funkcie vrátane "
    L"snímok PNG a záznamu MP4. Na spustenie aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať "
    L"aktualizácie KB971512 a KB2117917. Záznam MP4 na Viste v súčasnej verzii nefunguje. Vykresľovanie "
    L"vyžaduje Direct3D 11, nie iba starší DirectX runtime. Záznam MP4 vyžaduje dostupné súčasti Media "
    L"Foundation a kodér H.264.",
    L"ANIMATION OG INDSTILLINGER\r\nVælg en eller flere skærme på listen. Kameratilstand, objekter, "
    L"belysning, hastigheder, størrelse og antal kopier gælder kun de valgte skærme. Hver skærm husker sine "
    L"egne indstillinger. FlyingSolids viser belyste solide 3D-legemer. Skyderne indstiller objekt- og "
    L"kamerahastighed 0–1600 %, en til ti kopier og størrelse 50–200 %. Vælg Rumobservation eller Flyvning "
    L"gennem rummet i en lige linje og aktivér de ønskede legemer. Afkrydsningsfelterne Hovedlys, "
    L"Udfyldningslys, Omgivende lys og Konturlys under skyderne styrer belysningen af hele scenen "
    L"uafhængigt af hinanden. Omgivende lys giver overfladerne en grundbelysning, og konturlys fremhæver "
    L"kanterne. Som standard er hovedlys, omgivende lys og konturlys slået til og udfyldningslys slået fra. "
    L"Indstillingerne gemmes separat for programmet og pauseskærmen.\r\n\r\nSKÆRME\r\nMarkeringen af rækker "
    L"bestemmer, hvilke skærme du indstiller, og er adskilt fra afkrydsningsfelterne, der aktiverer "
    L"animationsoutput. Ctrl+A markerer alle skærme; Ctrl og Skift ændrer markeringen. Alle animationsvalg "
    L"og skydere gælder de markerede skærme. Markeringen huskes separat for EXE og SCR. Hvis alle skærme "
    L"var markeret, medtages også nye skærme. Forskellige værdier på de markerede skærme vises med "
    L"ubestemte afkrydsningsfelter og prikmønstre på alternativknapper, skydergreb og knapper til at slå "
    L"alle valg til eller fra. Skydernes etiketter viser en tankestreg i stedet for en fælles værdi. "
    L"Ændring af et valg eller klik på en skyder anvender denne værdi på alle markerede "
    L"skærme.\r\n\r\nBETJENING\r\nSlå animationsoutput til eller fra med skærmenes afkrydsningsfelter eller "
    L"ved at dobbeltklikke på deres rækker. Hver skærm bruger en uafhængig scene. Skærmbillede gemmer PNG, "
    L"og optageknappen starter eller stopper MP4. Pause standser animationen. Programmet installerer eller "
    L"afinstallerer også den indbyggede pauseskærm. Indstillinger gemmes løbende. Programmet kan kun køre i "
    L"én instans ad gangen. En ny start gendanner det minimerede kontrolvindue og bringer det forrest. Brug "
    L"Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det understregede bogstav aktiverer en "
    L"kommando. Esc lukker det aktive Hjælp- eller Om-vindue; i kontrolvinduet afslutter det programmet. "
    L"Pause og blokering af pauseskærmen gælder hele programmet uanset skærmmarkeringen. Når blokering er "
    L"slået til, forhindres Windows-pauseskærmen kun, mens der vises en synlig animation, som ikke er sat "
    L"på pause, på mindst én skærm.\r\n\r\nSKÆRMBILLEDER OG OPTAGELSE\r\nSkærmbilleder og optagelser bruger "
    L"den første aktive animationsskærm, ikke et samlet billede af alle skærme. PNG bruger Billeder, MP4 "
    L"Videoer; hvis disse mapper ikke findes, bruges Dokumenter. Knappen Optagelsesindstillinger vælger "
    L"Viewport eller TV. Viewport bevarer animationsskærmens størrelse og opdateringsfrekvens, højst 60 "
    L"billeder i sekundet. TV tilbyder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9 med 50, "
    L"25, 59.94 (60000/1001) eller 29.97 (30000/1001) billeder i sekundet. Billedets proportioner bevares; "
    L"TV bruger progressiv BT.709-video med begrænset område og 4:2:0-sampling. Opløsning og billedfrekvens "
    L"kan kun vælges i TV-tilstand. Vinduet Optagelsesindstillinger kan minimeres og blokerer ikke de andre "
    L"programvinduer. OK gemmer valgene til den næste MP4-optagelse; Annuller eller Esc kasserer "
    L"ubekræftede ændringer. Den skærm, der optages, kan ikke fravælges under optagelsen; ændringer af "
    L"andre skærme stopper ikke optagelsen. Hvis programmet lukkes under en optagelse, kræves en "
    L"bekræftelse, fordi optagelsen også afsluttes.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 "
    L"understøtter alle funktioner, herunder PNG-skærmbilleder og MP4-optagelse. For at køre programmet på "
    L"Windows Vista SP2 skal opdateringerne KB971512 og KB2117917 installeres. MP4-optagelse fungerer ikke "
    L"på Vista i den aktuelle version. Visningen kræver Direct3D 11, ikke kun et ældre "
    L"DirectX-kørselsmiljø. MP4-optagelse kræver tilgængelige Media Foundation-komponenter og en "
    L"H.264-koder.",
    L"ANIMAATIO JA ASETUKSET\r\nValitse luettelosta yksi tai useampi näyttö. Kameratila, kappaleet, "
    L"valaistus, nopeudet, koko ja kopioiden määrä koskevat vain valittuja näyttöjä. Jokainen näyttö "
    L"muistaa omat asetuksensa. FlyingSolids näyttää valaistuja kiinteitä 3D-kappaleita. Liukusäätimillä "
    L"asetetaan kohteiden ja kameran nopeus 0–1600 %, yhdestä kymmeneen kopiota ja koko 50–200 %. Valitse "
    L"Avaruuden tarkkailu tai Lento avaruuden halki suoraan eteenpäin ja ota halutut kappaleet käyttöön. "
    L"Liukusäätimien alla olevat Päävalo-, Täytevalo-, Ympäristövalo- ja Reunavalo-valintaruudut ohjaavat "
    L"koko näkymän valaistusta toisistaan riippumatta. Ympäristövalo antaa pinnoille perusvalaistuksen ja "
    L"reunavalo korostaa reunoja. Oletuksena päävalo, ympäristövalo ja reunavalo ovat päällä ja täytevalo "
    L"pois päältä. Asetukset tallennetaan erikseen sovellukselle ja "
    L"näytönsäästäjälle.\r\n\r\nNÄYTÖT\r\nRivien valinta määrää muokattavat näytöt ja on erillinen "
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
    L"HREYFIMYND OG STILLINGAR\r\nVeldu einn eða fleiri skjái á listanum. Myndavélarhamur, hlutir, lýsing, "
    L"hraði, stærð og fjöldi eintaka eiga aðeins við um valda skjái. Hver skjár geymir sínar eigin "
    L"stillingar. FlyingSolids sýnir upplýsta heila þrívíddarhluti. Rennistikur stilla hraða hluta og "
    L"myndavélar á 0–1600%, eitt til tíu eintök og stærð á 50–200%. Veldu Athugun rýmis eða Flug um rýmið í "
    L"beinni línu og virkjaðu þá hluti sem óskað er eftir. Gátreitirnir Aðalljós, Fylliljós, "
    L"Umhverfislýsing og Útlínulýsing undir rennistikunum stýra lýsingu allrar senunnar óháð hver öðrum. "
    L"Umhverfislýsing gefur yfirborðunum grunnbirtu og útlínulýsing dregur fram jaðrana. Stillingarnar eru "
    L"vistaðar sérstaklega fyrir forritið og skjáhvíluna.\r\n\r\nSKJÁIR\r\nVal lína ákvarðar hvaða skjám er "
    L"verið að breyta og er óháð gátreitunum sem kveikja á hreyfimyndaúttaki. Ctrl+A velur alla skjái; Ctrl "
    L"og Shift breyta valinu. Allir valkostir og sleðar hreyfimynda gilda fyrir valda skjái. Valið er munað "
    L"sérstaklega fyrir EXE og SCR. Ef allir skjáir voru valdir bætast nýir skjáir einnig við valið. "
    L"Mismunandi gildi á völdum skjám eru sýnd með óákveðnu ástandi gátreita og punktamynstri á valhnöppum, "
    L"handföngum sleða og hnöppum sem kveikja eða slökkva á öllum valkostum. Merking sleða sýnir strik í "
    L"stað sameiginlegs gildis. Að breyta valkosti eða smella á sleða setur það gildi á alla valda "
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
    L"ANIMASJON OG INNSTILLINGER\r\nVelg én eller flere skjermer i listen. Kameramodus, objekter, "
    L"belysning, hastigheter, størrelse og antall kopier gjelder bare de valgte skjermene. Hver skjerm "
    L"husker sine egne innstillinger. FlyingSolids viser belyste solide 3D-legemer. Glidebryterne angir "
    L"objekt- og kamerahastighet fra 0–1600 %, én til ti kopier og størrelse fra 50–200 %. Velg "
    L"Romobservasjon eller Flyging gjennom rommet i rett linje og aktiver ønskede legemer. "
    L"Avmerkingsboksene Hovedlys, Utfyllingslys, Omgivelseslys og Konturlys under glidebryterne styrer "
    L"belysningen i hele scenen uavhengig av hverandre. Omgivelseslys gir grunnbelysning på overflatene, og "
    L"konturlys fremhever kantene. Som standard er hovedlys, omgivelseslys og konturlys på, og "
    L"utfyllingslys av. Innstillingene lagres separat for programmet og "
    L"skjermspareren.\r\n\r\nSKJERMER\r\nMarkeringen av rader bestemmer hvilke skjermer du redigerer, og er "
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
    L"ANIMERING OCH INSTÄLLNINGAR\r\nMarkera en eller flera skärmar i listan. Kameraläge, objekt, "
    L"belysning, hastigheter, storlek och antal kopior gäller bara de markerade skärmarna. Varje skärm "
    L"sparar sina egna inställningar. FlyingSolids visar belysta solida 3D-kroppar. Reglagen ställer in "
    L"objekt- och kamerahastighet 0–1600 %, en till tio kopior och storlek 50–200 %. Välj Rymdobservation "
    L"eller Flygning genom rymden i rak linje och aktivera önskade kroppar. Kryssrutorna Huvudljus, "
    L"Upplättningsljus, Omgivningsljus och Konturljus under reglagen styr belysningen i hela scenen "
    L"oberoende av varandra. Omgivningsljus ger grundbelysning på ytorna och konturljus framhäver kanterna. "
    L"Som standard är huvudljus, omgivningsljus och konturljus på och upplättningsljus av. Inställningarna "
    L"sparas separat för programmet och skärmsläckaren.\r\n\r\nBILDSKÄRMAR\r\nMarkeringen av rader avgör "
    L"vilka skärmar du redigerar och är skild från kryssrutorna som aktiverar animationsutgångarna. Ctrl+A "
    L"markerar alla skärmar; Ctrl och Skift ändrar markeringen. Alla animationsalternativ och reglage "
    L"gäller de markerade skärmarna. Markeringen sparas separat för EXE och SCR. Om alla skärmar var "
    L"markerade inkluderas även nya skärmar. Olika värden på de markerade skärmarna visas med obestämda "
    L"kryssrutor och punktmönster på alternativknappar, reglagehandtag och knappar för att slå på eller av "
    L"alla alternativ. Reglagens etiketter visar ett streck i stället för ett gemensamt värde. När du "
    L"ändrar ett alternativ eller klickar på ett reglage används värdet på alla markerade "
    L"skärmar.\r\n\r\nANVÄNDNING\r\nSlå på eller av animationsutgångarna med skärmarnas kryssrutor eller "
    L"genom att dubbelklicka på deras rader. Varje bildskärm använder en oberoende scen. Skärmbild sparar "
    L"PNG och inspelningsknappen startar eller stoppar MP4. Paus stannar animeringen. Programmet "
    L"installerar eller avinstallerar även den inbyggda skärmsläckaren. Inställningarna sparas fortlöpande. "
    L"Programmet kan bara köras i en instans åt gången. En ny start återställer det minimerade "
    L"kontrollfönstret och för det längst fram. Använd Tab och Skift+Tab för att flytta mellan "
    L"kontrollerna; Alt och den understrukna bokstaven aktiverar ett kommando. Esc stänger det aktiva "
    L"Hjälp- eller Om-fönstret; i kontrollfönstret avslutar det programmet. Paus och blockering av "
    L"skärmsläckaren gäller hela programmet oavsett markerade skärmar. När blockeringen är på hindras "
    L"Windows-skärmsläckaren bara medan en synlig animering som inte är pausad visas på minst en "
    L"skärm.\r\n\r\nSKÄRMBILDER OCH INSPELNING\r\nSkärmbilder och inspelningar använder den första aktiva "
    L"animeringsskärmen, inte en sammanslagen bild av alla skärmar. PNG använder Bilder, MP4 Videor; om "
    L"dessa mappar saknas används Dokument. Knappen Inspelningsinställningar väljer Viewport eller TV. "
    L"Viewport behåller animeringsskärmens storlek och uppdateringsfrekvens, upp till 60 bilder per sekund. "
    L"TV erbjuder 1920 × 1080, 1440 × 1080 eller 1280 × 720 i formatet 16:9, med 50, 25, 59.94 (60000/1001) "
    L"eller 29.97 (30000/1001) bilder per sekund. Bildens proportioner bevaras; TV använder progressiv "
    L"BT.709-video med begränsat omfång och 4:2:0-sampling. Upplösning och bildfrekvens kan bara väljas i "
    L"TV-läge. Fönstret Inspelningsinställningar kan minimeras och blockerar inte de andra programfönstren. "
    L"OK sparar valen för nästa MP4-inspelning; Avbryt eller Esc ignorerar obekräftade ändringar. Den "
    L"inspelade skärmen kan inte väljas bort under inspelningen; ändringar av andra skärmar stoppar inte "
    L"inspelningen. Att avsluta programmet under en inspelning kräver bekräftelse eftersom det också "
    L"avslutar inspelningen.\r\n\r\nSYSTEMKRAV\r\nWindows 7 till Windows 11 stöder alla funktioner, "
    L"inklusive PNG-skärmbilder och MP4-inspelning. För att köra programmet på Windows Vista SP2 måste "
    L"uppdateringarna KB971512 och KB2117917 installeras. MP4-inspelning fungerar inte på Vista i den "
    L"aktuella versionen. Visningen kräver Direct3D 11, inte bara en äldre DirectX-körningsmiljö. "
    L"MP4-inspelning kräver tillgängliga Media Foundation-komponenter och en H.264-kodare.",
    L"ANİMASYON VE AYARLAR\r\nListeden bir veya daha fazla ekran seçin. Kamera modu, nesneler, aydınlatma, "
    L"hızlar, boyut ve kopya sayısı yalnızca seçili ekranlara uygulanır. Her ekran kendi ayarlarını "
    L"hatırlar. FlyingSolids aydınlatılmış katı 3B cisimler gösterir. Kaydırıcılar nesne ve kamera hızını "
    L"%0–1600, kopya sayısını bir ile on ve boyutu %50–200 arasında ayarlar. Uzayı gözlemleme veya doğrusal "
    L"Uzayda uçuş kipini seçip istenen cisimleri etkinleştirin. Kaydırıcıların altındaki Ana ışık, Dolgu "
    L"ışığı, Ortam ışığı ve Kenar aydınlatması onay kutuları tüm sahnenin aydınlatmasını birbirinden "
    L"bağımsız olarak kontrol eder. Ortam ışığı yüzeylere temel aydınlatma sağlar, kenar aydınlatması ise "
    L"kenarları vurgular. Ayarlar uygulama ve ekran koruyucu için ayrı ayrı "
    L"kaydedilir.\r\n\r\nEKRANLAR\r\nSatır seçimi, hangi ekranların düzenlendiğini belirler; animasyon "
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
    L"ANIMATSIOON JA SÄTTED\r\nFlyingSolids kuvab liikuvaid, pöörlevaid ja põrkuvaid ruumilisi kehi. Valige "
    L"ruumi vaatlemine või lend läbi ruumi ning soovitud kehad. Iga kuvari jaoks saab eraldi määrata "
    L"objektide ja kaamera kiiruse 0–1600%, objektide suuruse 50–200% ning iga keha koopiate arvu 1–10. "
    L"Põhi-, täite-, ümbritsev ja kontuurivalgus on sõltumatult lülitatavad.\r\n\r\nKUVARID\r\nValige "
    L"loendis üks või mitu kuvaririda. Ctrl+A valib kõik read; Ctrl ja Shift võimaldavad valikut muuta. "
    L"Animatsiooni juhtnupud ja liugurid mõjutavad ainult valitud kuvarite sätteid, mitte kogu rakendust. "
    L"Rea valimine ja selle märkeruuduga väljundi lubamine on eri toimingud. Valik jäetakse rakenduse ja "
    L"ekraanisäästja jaoks eraldi meelde. Kui varem olid valitud kõik kuvarid, kaasatakse ka lisatud "
    L"kuvarid. Valitud kuvarite erinevaid väärtusi näitavad märkeruutude määramata olek ning raadionuppude, "
    L"liugurite käepidemete ja kõigi valikute lülitusnuppude punktimuster. Liuguri sildil on ühise väärtuse "
    L"asemel kriips. Valiku muutmine või liuguril klõpsamine määrab selle väärtuse kõigile valitud "
    L"kuvaritele.\r\n\r\nKASUTAMINE\r\nKäivitage FlyingSolids.exe. Sätteid salvestatakse jooksvalt ning "
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
    L"BEOCHAN AGUS SOCRUITHE\r\nTaispeánann FlyingSolids coirp sholadacha a ghluaiseann, a rothlaíonn agus "
    L"a imbhuaileann. Roghnaigh breathnú ar an spás nó eitilt tríd agus na coirp atá uait. Tá luas na réad "
    L"agus an cheamara 0–1600%, méid na réad 50–200% agus 1–10 gcóip de gach corp inchoigeartaithe go "
    L"neamhspleách do gach monatóir. Is féidir an príomhsholas, an solas líonta, an solas comhthimpeallach "
    L"agus an solas imill a athrú ar leith.\r\n\r\nTAISPEÁNTAIS\r\nRoghnaigh ró amháin nó níos mó sa liosta "
    L"monatóirí. Roghnaíonn Ctrl+A gach ró; úsáid Ctrl agus Shift chun an roghnú a athrú. Ní athraíonn "
    L"rialuithe agus sleamhnáin na beochana ach socruithe na monatóirí roghnaithe. Ní hionann ró a roghnú "
    L"agus aschur an mhonatóra a chumasú lena bhosca seiceála. Cuimhnítear an roghnú ar leith don "
    L"fheidhmchlár agus don spárálaí. Má bhí gach monatóir roghnaithe, cuirtear monatóirí nua leis an "
    L"roghnú freisin. Léirítear luachanna éagsúla ar na monatóirí roghnaithe le boscaí seiceála i staid "
    L"neamhchinnte agus le patrún poncanna ar chnaipí raidió, ar ghreimíní sleamhnán agus ar na cnaipí a "
    L"chumasaíonn nó a dhíchumasaíonn gach rogha. Taispeántar dais ar lipéad an tsleamhnáin in ionad luach "
    L"coiteann. Nuair a athraítear rogha nó a chliceáiltear sleamhnán, cuirtear an luach sin i bhfeidhm ar "
    L"gach monatóir roghnaithe.\r\n\r\nRIALÚ\r\nRith FlyingSolids.exe. Sábháiltear socruithe go leanúnach "
    L"agus ní ritheann ach cóip amháin den fheidhmchlár. Cumasaíonn nó díchumasaíonn bosca seiceála an "
    L"mhonatóra nó déchliceáil ar a ró an t-aschur beochana. Is féidir an bheochan a chur ar sos agus a "
    L"atosú. Gabhann PNG agus MP4 an chéad mhonatóir beochana gníomhach, ní na monatóirí uile le chéile. Ní "
    L"féidir an monatóir atá á thaifeadadh a dhíchumasú; teastaíonn deimhniú chun an feidhmchlár a dhúnadh "
    L"agus taifeadadh ar siúl. Baineann sos agus cosc an spárálaí scáileáin leis an bhfeidhmchlár iomlán, "
    L"beag beann ar na monatóirí roghnaithe. Nuair atá an cosc cumasaithe, ní choisctear spárálaí scáileáin "
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
    L"ANIMACIJA IR NUOSTATOS\r\nFlyingSolids rodo judančius, besisukančius ir susiduriančius erdvinius "
    L"kūnus. Pasirinkite erdvės stebėjimą arba skrydį erdve ir norimus kūnus. Kiekvienam monitoriui "
    L"atskirai galima nustatyti objektų bei kameros greitį 0–1600%, objektų dydį 50–200% ir 1–10 kiekvieno "
    L"kūno kopijų. Pagrindinė, užpildanti, aplinkos ir kontūrinė šviesa įjungiamos "
    L"nepriklausomai.\r\n\r\nMONITORIAI\r\nMonitorių sąraše pasirinkite vieną ar kelias eilutes. Ctrl+A "
    L"pasirenka visas, o Ctrl ir Shift leidžia keisti pasirinkimą. Animacijos valdikliai ir slankikliai "
    L"keičia tik pasirinktų monitorių nuostatas. Eilutės pasirinkimas nėra tas pats, kas animacijos "
    L"išvesties įjungimas jos žymimuoju langeliu. Pasirinkimas atskirai įsimenamas programai ir užsklandai. "
    L"Jei buvo pasirinkti visi monitoriai, į pasirinkimą įtraukiami ir naujai prijungti monitoriai. "
    L"Skirtingas pasirinktų monitorių reikšmes rodo neapibrėžta žymimųjų langelių būsena ir taškinis raštas "
    L"ant parinkčių mygtukų, slankiklių rankenėlių bei visų parinkčių įjungimo ir išjungimo mygtukų. "
    L"Slankiklių užrašuose vietoj bendros reikšmės rodomas brūkšnys. Pakeitus parinktį arba spustelėjus "
    L"slankiklį, ta reikšmė pritaikoma visiems pasirinktiems monitoriams.\r\n\r\nVALDYMAS\r\nPaleiskite "
    L"FlyingSolids.exe. Nuostatos išsaugomos nuolat, veikia tik vienas programos egzempliorius. Monitoriaus "
    L"langelis arba dvigubas eilutės spustelėjimas įjungia ar išjungia animacijos išvestį. Animaciją galima "
    L"pristabdyti ir tęsti. PNG ir MP4 fiksuoja pirmą aktyvų animacijos monitorių, o ne bendrą visų "
    L"monitorių vaizdą. Įrašomo monitoriaus išjungti negalima; uždarant programą vykstant įrašymui reikia "
    L"patvirtinimo. Pristabdymas ir užsklandos blokavimas taikomi visai programai, nepriklausomai nuo "
    L"monitorių pasirinkimo. Įjungus blokavimą, Windows užsklanda neleidžiama tik kol bent viename "
    L"monitoriuje matoma nepristabdyta animacija. Programa gali įdiegti ir pašalinti į ją įtrauktą "
    L"užsklandą.\r\n\r\nEKRANO KOPIJOS IR ĮRAŠYMAS\r\nĮrašymo nuostatose pasirinkite Viewport arba TV. "
    L"Viewport išsaugo monitoriaus matmenis ir dažnį iki 60 kadrų per sekundę. TV siūlo 1920 × 1080, 1440 × "
    L"1080 arba 1280 × 720 išvestį 16:9 santykiu bei 50, 25, 59.94 (60000/1001) arba 29.97 (30000/1001) "
    L"kadrų per sekundę. TV vaizdas progresinis, BT.709, riboto diapazono ir 4:2:0 spalvų diskretizavimo. "
    L"Vaizdo proporcijos išlieka, užpildymo juostos juodos. OK pritaiko nuostatas kitam įrašui, Atšaukti "
    L"arba Esc atmeta nepatvirtintus pakeitimus. Įrašymo, žinyno ir informacijos langai neblokuoja kitų "
    L"langų ir gali būti sumažinti. Tab ir Shift+Tab keičia įvesties vietą, Enter paspaudžia aktyvų "
    L"mygtuką, Esc uždaro aktyvų papildomą langą.\r\n\r\nSISTEMOS REIKALAVIMAI\r\nWindows 7–11 palaiko "
    L"visas funkcijas. Windows Vista SP2 būtina įdiegti naujinimus KB971512 ir KB2117917; MP4 įrašymas "
    L"Vistoje neveikia. Reikalingas Direct3D 11 palaikymas, o MP4 įrašymui Media Foundation ir H.264 "
    L"koduotuvas. Sąsaja ir dokumentacija pateikiamos 36 kalbomis.",
    L"ANIMĀCIJA UN IESTATĪJUMI\r\nFlyingSolids rāda kustīgus, rotējošus un savstarpēji sadurošus telpiskus "
    L"ķermeņus. Izvēlieties telpas novērošanu vai lidojumu telpā un vajadzīgos ķermeņus. Katram monitoram "
    L"atsevišķi var iestatīt objektu un kameras ātrumu 0–1600%, objektu izmēru 50–200% un 1–10 katra "
    L"ķermeņa kopijas. Galveno, papildu, apkārtējo un kontūru gaismu var pārslēgt "
    L"neatkarīgi.\r\n\r\nMONITORI\r\nMonitoru sarakstā atlasiet vienu vai vairākas rindas. Ctrl+A atlasa "
    L"visas, bet Ctrl un Shift ļauj mainīt atlasi. Animācijas vadīklas un slīdņi maina tikai atlasīto "
    L"monitoru iestatījumus. Rindas atlasīšana nav tas pats, kas animācijas izvades ieslēgšana ar izvēles "
    L"rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un ekrānsaudzētājam. Ja bija atlasīti visi monitori, "
    L"atlasē iekļauj arī jaunpievienotos monitorus. Atšķirīgas vērtības atlasītajos monitoros norāda "
    L"nenoteikts izvēles rūtiņu stāvoklis un punktots raksts uz radiopogām, slīdņu rokturiem un visu "
    L"iespēju ieslēgšanas vai izslēgšanas pogām. Slīdņu etiķetēs kopīgas vērtības vietā redzama domuzīme. "
    L"Mainot iespēju vai noklikšķinot uz slīdņa, šī vērtība tiek piemērota visiem atlasītajiem "
    L"monitoriem.\r\n\r\nLIETOŠANA\r\nPalaidiet FlyingSolids.exe. Iestatījumi tiek saglabāti nepārtraukti, "
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
    L"ANIMÁCIÓ ÉS BEÁLLÍTÁSOK\r\nA FlyingSolids mozgó, forgó és ütköző térbeli testeket jelenít meg. "
    L"Válassza a tér megfigyelését vagy a térben repülést, és kapcsolja be a kívánt testeket. Monitoronként "
    L"állítható az objektumok és a kamera sebessége 0–1600%, az objektumok mérete 50–200%, valamint "
    L"testenként 1–10 példány. A főfény, derítőfény, környezeti fény és peremfény egymástól függetlenül "
    L"kapcsolható.\r\n\r\nMONITOROK\r\nJelöljön ki egy vagy több sort a monitorok listájában. A Ctrl+A "
    L"mindet kijelöli; a Ctrl és a Shift módosítja a kijelölést. Az animáció vezérlői és csúszkái csak a "
    L"kijelölt monitorok beállításait változtatják. A sor kijelölése és az animációs kimenet "
    L"jelölőnégyzetes engedélyezése külön művelet. A kijelölést az alkalmazás és a képernyőkímélő külön "
    L"megjegyzi. Ha korábban minden monitor ki volt jelölve, az újonnan csatlakoztatott monitorok is "
    L"bekerülnek a kijelölésbe. A kijelölt monitorok eltérő értékeit a jelölőnégyzetek határozatlan "
    L"állapota, valamint a választógombok, a csúszkafogantyúk és az összes beállítást be- vagy kikapcsoló "
    L"gombok pontozása jelzi. A csúszkák felirata közös érték helyett gondolatjelet mutat. Egy beállítás "
    L"módosítása vagy a csúszkára kattintás az adott értéket minden kijelölt monitorra "
    L"alkalmazza.\r\n\r\nKEZELÉS\r\nIndítsa el a FlyingSolids.exe fájlt. A beállítások folyamatosan "
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
    L"ANIMAZZJONI U SETTINGS\r\nFlyingSolids juri solidi tridimensjonali li jiċċaqalqu, iduru u jaħbtu ma’ "
    L"xulxin. Agħżel osservazzjoni tal-ispazju jew titjira fl-ispazju u attiva l-forom mixtieqa. Għal kull "
    L"moniter tista’ tissettja separatament il-veloċità tal-oġġetti u l-kamera minn 0–1600%, id-daqs minn "
    L"50–200% u 1–10 kopji ta’ kull solidu. Id-dawl ewlieni, id-dawl ta’ mili, id-dawl ambjentali u d-dawl "
    L"tal-kontorn jinxtegħlu separatament.\r\n\r\nSKRINS\r\nAgħżel ringiela waħda jew aktar fil-lista "
    L"tal-moniters. Ctrl+A jagħżilhom kollha; Ctrl u Shift ibiddlu l-għażla. Il-kontrolli u s-sliders "
    L"tal-animazzjoni jibdlu biss is-settings tal-moniters magħżula. L-għażla ta’ ringiela hija differenti "
    L"mill-attivazzjoni tal-output permezz tal-kaxxa tal-marka. L-għażla tinżamm separatament "
    L"għall-applikazzjoni u għall-iscreen saver. Jekk il-moniters kollha kienu magħżula, il-moniters ġodda "
    L"jiddaħħlu wkoll fl-għażla. Valuri differenti fuq il-moniters magħżula jintwerew bi stat indeterminat "
    L"tal-kaxxi tal-marka u b’disinn bit-tikek fuq il-buttuni tar-radju, il-manki tas-sliders u l-buttuni "
    L"li jattivaw jew jiddiżattivaw l-għażliet kollha. It-tikketti tas-sliders juru sing minflok valur "
    L"komuni. Meta tibdel għażla jew tikklikkja slider, dak il-valur jiġi applikat għall-moniters magħżula "
    L"kollha.\r\n\r\nKONTROLLI\r\nĦaddem FlyingSolids.exe. Is-settings jiġu ssejvjati kontinwament u taħdem "
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
    L"ANIMATIE EN INSTELLINGEN\r\nFlyingSolids toont bewegende, draaiende en botsende driedimensionale "
    L"lichamen. Kies ruimte observeren of door de ruimte vliegen en schakel de gewenste lichamen in. Stel "
    L"per beeldscherm de object- en camerasnelheid in op 0–1600%, de objectgrootte op 50–200% en het aantal "
    L"kopieën op 1–10 per lichaam. Hoofdlicht, invullicht, omgevingslicht en randlicht zijn onafhankelijk "
    L"schakelbaar.\r\n\r\nBEELDSCHERMEN\r\nSelecteer één of meer beeldschermrijen in de lijst. Ctrl+A "
    L"selecteert alles; met Ctrl en Shift past u de selectie aan. Animatieknoppen en schuifregelaars "
    L"wijzigen alleen de instellingen van de geselecteerde beeldschermen. Een rij selecteren is iets anders "
    L"dan de animatie-uitvoer inschakelen met het selectievakje. De selectie wordt apart onthouden voor de "
    L"toepassing en de schermbeveiliging. Als alle beeldschermen waren geselecteerd, worden nieuw "
    L"aangesloten beeldschermen ook geselecteerd. Verschillende waarden op geselecteerde beeldschermen "
    L"worden aangegeven door selectievakjes in onbepaalde toestand en een stippelpatroon op keuzerondjes, "
    L"schuifknoppen en knoppen om alle opties in of uit te schakelen. De labels van schuifregelaars tonen "
    L"een streepje in plaats van een gemeenschappelijke waarde. Een optie wijzigen of op een schuifregelaar "
    L"klikken past die waarde toe op alle geselecteerde beeldschermen.\r\n\r\nBEDIENING\r\nStart "
    L"FlyingSolids.exe. Instellingen worden doorlopend opgeslagen en er draait slechts één exemplaar van de "
    L"toepassing. Het selectievakje of een dubbelklik op de beeldschermrij schakelt de animatie-uitvoer in "
    L"of uit. U kunt de animatie pauzeren en hervatten. PNG en MP4 leggen het eerste actieve "
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
    L"ANIMAȚIE ȘI SETĂRI\r\nFlyingSolids afișează corpuri tridimensionale care se deplasează, se rotesc și "
    L"se ciocnesc. Alegeți observarea spațiului sau zborul prin spațiu și activați corpurile dorite. Pentru "
    L"fiecare monitor puteți seta separat viteza obiectelor și a camerei între 0–1600%, dimensiunea între "
    L"50–200% și 1–10 copii ale fiecărui corp. Lumina principală, de umplere, ambiantă și de contur se "
    L"controlează independent.\r\n\r\nMONITOARE\r\nSelectați unul sau mai multe rânduri din lista "
    L"monitoarelor. Ctrl+A le selectează pe toate; Ctrl și Shift modifică selecția. Comenzile și glisoarele "
    L"animației schimbă numai setările monitoarelor selectate. Selectarea unui rând diferă de activarea "
    L"ieșirii prin caseta sa de selectare. Selecția este reținută separat pentru aplicație și economizor. "
    L"Dacă erau selectate toate monitoarele, sunt incluse și cele conectate ulterior. Valorile diferite de "
    L"pe monitoarele selectate sunt indicate prin starea nedeterminată a casetelor de selectare și un model "
    L"punctat pe butoanele radio, mânerele glisoarelor și butoanele de activare sau dezactivare a tuturor "
    L"opțiunilor. Etichetele glisoarelor afișează o liniuță în locul unei valori comune. Modificarea unei "
    L"opțiuni sau clicul pe un glisor aplică acea valoare tuturor monitoarelor "
    L"selectate.\r\n\r\nCOMENZI\r\nRulați FlyingSolids.exe. Setările se salvează continuu și rulează o "
    L"singură instanță. Caseta monitorului sau un dublu clic pe rând activează ori dezactivează ieșirea "
    L"animației. Animația poate fi pusă în pauză și reluată. PNG și MP4 capturează primul monitor de "
    L"animație activ, nu imaginea combinată a tuturor monitoarelor. Monitorul înregistrat nu poate fi "
    L"dezactivat; închiderea aplicației în timpul înregistrării necesită confirmare. Pauza și blocarea "
    L"economizorului se aplică întregii aplicații, indiferent de selecția monitoarelor. Când blocarea este "
    L"activată, economizorul Windows este împiedicat numai cât timp pe cel puțin un monitor este vizibilă o "
    L"animație care nu este în pauză. Aplicația poate instala sau dezinstala economizorul "
    L"încorporat.\r\n\r\nCAPTURI ȘI ÎNREGISTRARE\r\nÎn setările de înregistrare alegeți Viewport sau TV. "
    L"Viewport păstrează dimensiunile și rata de reîmprospătare a monitorului, până la 60 de cadre pe "
    L"secundă. TV oferă 1920 × 1080, 1440 × 1080 sau 1280 × 720 în 16:9, la 50, 25, 59.94 (60000/1001) sau "
    L"29.97 (30000/1001) cadre pe secundă. Videoul TV este progresiv BT.709, cu interval limitat și "
    L"subeșantionare cromatică 4:2:0. Proporțiile imaginii se păstrează, iar benzile de completare sunt "
    L"negre. OK salvează opțiunile pentru următoarea înregistrare; Anulare sau Esc renunță la schimbările "
    L"neconfirmate. Ferestrele de înregistrare, ajutor și informații nu blochează celelalte ferestre și pot "
    L"fi minimizate. Tab și Shift+Tab mută focalizarea, Enter activează butonul focalizat, iar Esc închide "
    L"fereastra auxiliară activă.\r\n\r\nCERINȚE DE SISTEM\r\nWindows 7–11 acceptă toate funcțiile. Pentru "
    L"Windows Vista SP2 trebuie instalate actualizările KB971512 și KB2117917; înregistrarea MP4 nu "
    L"funcționează pe Vista. Este necesar Direct3D 11, iar pentru MP4 și Media Foundation și un codificator "
    L"H.264. Interfața și documentația sunt disponibile în 36 de limbi.",
    L"ΚΙΝΗΣΗ ΚΑΙ ΡΥΘΜΙΣΕΙΣ\r\nΤο FlyingSolids εμφανίζει τρισδιάστατα στερεά που κινούνται, περιστρέφονται "
    L"και συγκρούονται. Επιλέξτε παρατήρηση χώρου ή πτήση στον χώρο και ενεργοποιήστε τα επιθυμητά στερεά. "
    L"Ανά οθόνη ρυθμίζονται ανεξάρτητα η ταχύτητα αντικειμένων και κάμερας 0–1600%, το μέγεθος 50–200% και "
    L"1–10 αντίγραφα κάθε στερεού. Ο κύριος φωτισμός, ο φωτισμός πλήρωσης, ο περιβάλλων φωτισμός και ο "
    L"φωτισμός περιγράμματος ελέγχονται ανεξάρτητα.\r\n\r\nΟΘΟΝΕΣ\r\nΕπιλέξτε μία ή περισσότερες γραμμές "
    L"στη λίστα οθονών. Το Ctrl+A επιλέγει όλες, ενώ τα Ctrl και Shift αλλάζουν την επιλογή. Τα χειριστήρια "
    L"και τα ρυθμιστικά της κίνησης αλλάζουν μόνο τις ρυθμίσεις των επιλεγμένων οθονών. Η επιλογή γραμμής "
    L"διαφέρει από την ενεργοποίηση εξόδου μέσω του πλαισίου ελέγχου της. Η επιλογή αποθηκεύεται χωριστά "
    L"για την εφαρμογή και την προφύλαξη. Αν είχαν επιλεγεί όλες οι οθόνες, περιλαμβάνονται και όσες "
    L"συνδεθούν αργότερα. Οι διαφορετικές τιμές στις επιλεγμένες οθόνες υποδεικνύονται με απροσδιόριστη "
    L"κατάσταση των πλαισίων ελέγχου και μοτίβο κουκκίδων στα κουμπιά επιλογής, στις λαβές των ρυθμιστικών "
    L"και στα κουμπιά ενεργοποίησης ή απενεργοποίησης όλων των επιλογών. Οι ετικέτες των ρυθμιστικών "
    L"δείχνουν παύλα αντί για κοινή τιμή. Η αλλαγή επιλογής ή το κλικ σε ρυθμιστικό εφαρμόζει την τιμή σε "
    L"όλες τις επιλεγμένες οθόνες.\r\n\r\nΧΕΙΡΙΣΜΟΣ\r\nΕκτελέστε το FlyingSolids.exe. Οι ρυθμίσεις "
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
    L"ANIMACIJA I POSTAVKE\r\nFlyingSolids prikazuje prostorna tijela koja se kreću, okreću i sudaraju. "
    L"Odaberite posmatranje prostora ili let kroz prostor te željena tijela. Za svaki monitor zasebno se "
    L"podešavaju brzina objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija svakog tijela. Glavno, "
    L"dopunsko, ambijentalno i konturno svjetlo uključuju se nezavisno.\r\n\r\nMONITORI\r\nOdaberite jedan "
    L"ili više redova u listi monitora. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i "
    L"klizači animacije mijenjaju samo postavke odabranih monitora. Odabir reda nije isto što i "
    L"uključivanje izlaza njegovom kućicom. Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su "
    L"prethodno bili odabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti "
    L"na odabranim monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima "
    L"izbora, ručkama klizača i dugmadima za uključivanje ili isključivanje svih opcija. Oznake klizača "
    L"prikazuju crticu umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu "
    L"vrijednost na sve odabrane monitore.\r\n\r\nUPRAVLJANJE\r\nPokrenite FlyingSolids.exe. Postavke se "
    L"stalno čuvaju i radi samo jedna instanca aplikacije. Kućica monitora ili dvostruki klik na red "
    L"uključuje ili isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe "
    L"prvi aktivni monitor animacije, ne zajedničku sliku svih monitora. Snimani monitor ne možete "
    L"isključiti; zatvaranje aplikacije tokom snimanja zahtijeva potvrdu. Pauza i blokada čuvara ekrana "
    L"vrijede za cijelu aplikaciju, bez obzira na odabir monitora. Kada je blokada uključena, čuvar ekrana "
    L"Windowsa se sprječava samo dok je na barem jednom monitoru vidljiva animacija koja nije pauzirana. "
    L"Aplikacija može instalirati i deinstalirati ugrađeni čuvar ekrana.\r\n\r\nSNIMCI EKRANA I "
    L"SNIMANJE\r\nU postavkama snimanja odaberite Viewport ili TV. Viewport zadržava dimenzije i "
    L"frekvenciju monitora do 60 kadrova u sekundi. TV nudi 1920 × 1080, 1440 × 1080 ili 1280 × 720 u "
    L"omjeru 16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) kadrova u sekundi. TV video je "
    L"progresivni BT.709 ograničenog raspona s poduzorkovanjem boje 4:2:0. Omjer slike ostaje sačuvan, a "
    L"dopunske trake su crne. OK čuva opcije za sljedeći snimak; Otkaži ili Esc odbacuje nepotvrđene "
    L"izmjene. Prozori snimanja, pomoći i informacija ne blokiraju ostale prozore i mogu se minimizirati. "
    L"Tab i Shift+Tab pomjeraju fokus, Enter aktivira fokusirano dugme, a Esc zatvara aktivni pomoćni "
    L"prozor.\r\n\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate "
    L"instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, "
    L"a za MP4 i Media Foundation te H.264 koder. Interfejs i dokumentacija dostupni su na 36 jezika.",
    L"ANIMACIJA I POSTAVKE\r\nFlyingSolids prikazuje prostorna tijela koja se kreću, okreću i sudaraju. "
    L"Odaberite promatranje prostora ili let kroz prostor te željena tijela. Za svaki zaslon zasebno se "
    L"podešavaju brzina objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija svakog tijela. Glavno, "
    L"dopunsko, ambijentalno i konturno svjetlo uključuju se neovisno.\r\n\r\nMONITORI\r\nOdaberite jedan "
    L"ili više redaka na popisu zaslona. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i "
    L"klizači animacije mijenjaju samo postavke odabranih zaslona. Odabir retka nije isto što i "
    L"uključivanje izlaza njegovim potvrdnim okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar "
    L"zaslona. Ako su prethodno bili odabrani svi zasloni, uključuju se i novopriključeni zasloni. "
    L"Različite vrijednosti na odabranim zaslonima prikazuju se neodređenim stanjem potvrdnih okvira i "
    L"točkastim uzorkom na izbornim gumbima, ručkama klizača i gumbima za uključivanje ili isključivanje "
    L"svih mogućnosti. Oznake klizača prikazuju crticu umjesto zajedničke vrijednosti. Promjena mogućnosti "
    L"ili klik na klizač primjenjuje tu vrijednost na sve odabrane zaslone.\r\n\r\nUPRAVLJANJE\r\nPokrenite "
    L"FlyingSolids.exe. Postavke se neprekidno spremaju i radi samo jedna instanca aplikacije. Potvrdni "
    L"okvir zaslona ili dvostruki klik na redak uključuje ili isključuje animacijski izlaz. Animaciju "
    L"možete pauzirati i nastaviti. PNG i MP4 bilježe prvi aktivni zaslon animacije, ne zajedničku sliku "
    L"svih zaslona. Snimani zaslon ne možete isključiti; zatvaranje aplikacije tijekom snimanja zahtijeva "
    L"potvrdu. Pauza i blokada čuvara zaslona vrijede za cijelu aplikaciju, bez obzira na odabir zaslona. "
    L"Kada je blokada uključena, čuvar zaslona sustava Windows sprječava se samo dok je na barem jednom "
    L"zaslonu vidljiva animacija koja nije pauzirana. Aplikacija može instalirati i deinstalirati ugrađeni "
    L"čuvar zaslona.\r\n\r\nSNIMKE ZASLONA I SNIMANJE\r\nU postavkama snimanja odaberite Viewport ili TV. "
    L"Viewport zadržava dimenzije i frekvenciju zaslona do 60 sličica u sekundi. TV nudi 1920 × 1080, 1440 "
    L"× 1080 ili 1280 × 720 u omjeru 16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 (30000/1001) sličica u "
    L"sekundi. TV video je progresivni BT.709 ograničenog raspona s poduzorkovanjem boje 4:2:0. Omjer slike "
    L"ostaje sačuvan, a dopunske trake su crne. OK sprema mogućnosti za sljedeću snimku; Odustani ili Esc "
    L"odbacuje nepotvrđene izmjene. Prozori snimanja, pomoći i informacija ne blokiraju ostale prozore i "
    L"mogu se minimizirati. Tab i Shift+Tab pomiču fokus, Enter aktivira fokusirani gumb, a Esc zatvara "
    L"aktivni pomoćni prozor.\r\n\r\nZAHTJEVI SUSTAVA\r\nWindows 7–11 podržava sve funkcije. Za Windows "
    L"Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban "
    L"je Direct3D 11, a za MP4 i Media Foundation te H.264 koder. Sučelje i dokumentacija dostupni su na 36 "
    L"jezika.",
    L"ANIMACIJA IN NASTAVITVE\r\nFlyingSolids prikazuje prostorska telesa, ki se premikajo, vrtijo in "
    L"trkajo. Izberite opazovanje prostora ali let skozi prostor in želena telesa. Za vsak zaslon so ločeno "
    L"nastavljivi hitrost predmetov in kamere 0–1600%, velikost 50–200% ter 1–10 kopij vsakega telesa. "
    L"Glavna, dopolnilna, okoljska in obrobna svetloba se vklapljajo neodvisno.\r\n\r\nZASLONI\r\nNa "
    L"seznamu zaslonov izberite eno ali več vrstic. Ctrl+A izbere vse, Ctrl in Shift pa spreminjata izbor. "
    L"Kontrolniki in drsniki animacije spreminjajo samo nastavitve izbranih zaslonov. Izbira vrstice ni "
    L"isto kot vklop izhoda z njenim potrditvenim poljem. Izbor se ločeno shrani za program in "
    L"ohranjevalnik. Če so bili izbrani vsi zasloni, so vključeni tudi na novo priključeni zasloni. "
    L"Različne vrednosti na izbranih zaslonih označujeta nedoločeno stanje potrditvenih polj in pikčast "
    L"vzorec na izbirnih gumbih, ročicah drsnikov ter gumbih za vklop ali izklop vseh možnosti. Oznake "
    L"drsnikov namesto skupne vrednosti prikazujejo pomišljaj. Sprememba možnosti ali klik na drsnik "
    L"uveljavi to vrednost na vseh izbranih zaslonih.\r\n\r\nUPRAVLJANJE\r\nZaženite FlyingSolids.exe. "
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
    L"ANIMACIJA I PODEŠAVANJA\r\nFlyingSolids prikazuje prostorna tijela koja se kreću, okreću i sudaraju. "
    L"Izaberite posmatranje prostora ili let kroz prostor te željena tijela. Za svaki monitor zasebno se "
    L"podešavaju brzina objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija svakog tijela. Glavno, "
    L"dopunsko, ambijentalno i konturno svjetlo uključuju se nezavisno.\r\n\r\nMONITORI\r\nIzaberite jedan "
    L"ili više redova u listi monitora. Ctrl+A bira sve; Ctrl i Shift mijenjaju izbor. Kontrole i klizači "
    L"animacije mijenjaju samo podešavanja izabranih monitora. Izbor reda nije isto što i uključivanje "
    L"izlaza njegovom kućicom. Izbor se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
    L"izabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na izabranim "
    L"monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, ručkama "
    L"klizača i dugmadima za uključivanje ili isključivanje svih opcija. Oznake klizača prikazuju crticu "
    L"umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost na sve "
    L"izabrane monitore.\r\n\r\nUPRAVLJANJE\r\nPokrenite FlyingSolids.exe. Podešavanja se stalno čuvaju i "
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
    L"АНІМАЦЫЯ І НАЛАДЫ\r\nFlyingSolids паказвае аб’ёмныя целы, якія рухаюцца, круцяцца і сутыкаюцца. "
    L"Выберыце назіранне за прасторай або палёт праз яе і патрэбныя целы. Для кожнага манітора асобна "
    L"задаюцца хуткасці аб’ектаў і камеры 0–1600%, памер 50–200% і 1–10 копій кожнага цела. Асноўнае, "
    L"запаўняльнае, фонавае і контурнае святло ўключаюцца незалежна.\r\n\r\nМАНІТОРЫ\r\nВыберыце адзін або "
    L"некалькі радкоў у спісе манітораў. Ctrl+A выбірае ўсе; Ctrl і Shift змяняюць выбар. Элементы "
    L"кіравання і паўзункі анімацыі змяняюць толькі налады выбраных манітораў. Выбар радка і ўключэнне "
    L"вываду яго сцяжком — розныя дзеянні. Выбар асобна захоўваецца для праграмы і застаўкі. Калі раней "
    L"былі выбраны ўсе маніторы, да выбару далучаюцца і новыя маніторы. Розныя значэнні на выбраных "
    L"маніторах пазначаюцца нявызначаным станам сцяжкоў і кропкавым узорам на пераключальніках, ручках "
    L"паўзункоў і кнопках уключэння або выключэння ўсіх параметраў. У подпісах паўзункоў замест агульнага "
    L"значэння паказваецца працяжнік. Змена параметра або націск на паўзунок ужывае гэта значэнне да ўсіх "
    L"выбраных манітораў.\r\n\r\nКІРАВАННЕ\r\nЗапусціце FlyingSolids.exe. Налады захоўваюцца пастаянна, "
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
    L"АНИМАЦИЯ И НАСТРОЙКИ\r\nFlyingSolids показва обемни тела, които се движат, въртят и сблъскват. "
    L"Изберете наблюдение на пространството или полет през него и желаните тела. За всеки монитор отделно "
    L"се задават скорост на обектите и камерата 0–1600%, размер 50–200% и 1–10 копия на всяко тяло. "
    L"Основната, запълващата, околната и контурната светлина се включват "
    L"независимо.\r\n\r\nМОНИТОРИ\r\nИзберете един или повече редове в списъка с монитори. Ctrl+A избира "
    L"всички; Ctrl и Shift променят избора. Контролите и плъзгачите на анимацията променят само настройките "
    L"на избраните монитори. Избирането на ред и включването на изхода чрез отметката му са различни "
    L"действия. Изборът се запомня отделно за приложението и скрийнсейвъра. Ако са били избрани всички "
    L"монитори, включват се и новосвързаните. Различните стойности на избраните монитори се показват с "
    L"неопределено състояние на отметките и точков шаблон върху радиобутоните, дръжките на плъзгачите и "
    L"бутоните за включване или изключване на всички опции. Надписите на плъзгачите показват тире вместо "
    L"обща стойност. Промяна на опция или щракване върху плъзгач прилага стойността към всички избрани "
    L"монитори.\r\n\r\nУПРАВЛЕНИЕ\r\nСтартирайте FlyingSolids.exe. Настройките се запазват непрекъснато и "
    L"работи само един екземпляр на приложението. Отметката на монитора или двойно щракване върху реда "
    L"включва или изключва анимационния изход. Анимацията може да се поставя на пауза и да продължава. PNG "
    L"и MP4 заснемат първия активен монитор за анимация, не общ образ от всички монитори. Записваният "
    L"монитор не може да се изключи; затварянето на приложението при запис изисква потвърждение. Паузата и "
    L"блокирането на скрийнсейвъра важат за цялото приложение независимо от избора на монитори. Когато "
    L"блокирането е включено, скрийнсейвърът на Windows се предотвратява само докато на поне един монитор "
    L"има видима анимация без пауза. Приложението може да инсталира и деинсталира вградения "
    L"скрийнсейвър.\r\n\r\nЕКРАННИ СНИМКИ И ЗАПИС\r\nВ настройките за запис изберете Viewport или TV. "
    L"Viewport запазва размерите и честотата на монитора до 60 кадъра в секунда. TV предлага 1920 × 1080, "
    L"1440 × 1080 или 1280 × 720 със съотношение 16:9 и 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) "
    L"кадъра в секунда. TV използва прогресивно видео BT.709 с ограничен диапазон и цветова "
    L"субдискретизация 4:2:0. Пропорциите се запазват, допълващите ленти са черни. OK запазва избора за "
    L"следващия запис; Отказ или Esc отхвърля непотвърдените промени. Прозорците за запис, помощ и "
    L"информация не блокират другите прозорци и могат да се минимизират. Tab и Shift+Tab преместват фокуса, "
    L"Enter активира фокусирания бутон, Esc затваря активния помощен прозорец.\r\n\r\nСИСТЕМНИ "
    L"ИЗИСКВАНИЯ\r\nWindows 7–11 поддържа всички функции. За Windows Vista SP2 трябва да се инсталират "
    L"актуализациите KB971512 и KB2117917; записът на MP4 не работи във Vista. Изисква се поддръжка на "
    L"Direct3D 11, а за MP4 също Media Foundation и H.264 кодер. Интерфейсът и документацията са налични на "
    L"36 езика.",
    L"АНИМАЦИЈА И ПОСТАВКИ\r\nFlyingSolids прикажува просторни тела што се движат, вртат и судираат. "
    L"Изберете набљудување на просторот или лет низ него и саканите тела. За секој монитор одделно се "
    L"поставуваат брзината на објектите и камерата 0–1600%, големината 50–200% и 1–10 копии од секое тело. "
    L"Главното, дополнителното, амбиенталното и контурното светло се вклучуваат "
    L"независно.\r\n\r\nМОНИТОРИ\r\nИзберете еден или повеќе редови во списокот на монитори. Ctrl+A ги "
    L"избира сите; Ctrl и Shift го менуваат изборот. Контролите и лизгачите на анимацијата ги менуваат само "
    L"поставките на избраните монитори. Избирањето ред и вклучувањето на излезот преку неговото поле се "
    L"различни дејства. Изборот се памети одделно за апликацијата и чуварот. Ако биле избрани сите "
    L"монитори, се вклучуваат и новоповрзаните монитори. Различните вредности на избраните монитори се "
    L"прикажуваат со неопределена состојба на полињата за избор и точкест образец на радио-копчињата, "
    L"рачките на лизгачите и копчињата за вклучување или исклучување на сите опции. Ознаките на лизгачите "
    L"прикажуваат црта наместо заедничка вредност. Менувањето опција или кликнувањето на лизгач ја "
    L"применува вредноста на сите избрани монитори.\r\n\r\nУПРАВУВАЊЕ\r\nСтартувајте FlyingSolids.exe. "
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
    L"АНИМАЦИЈА И ПОДЕШАВАЊА\r\nFlyingSolids приказује просторна тела која се крећу, окрећу и сударају. "
    L"Изаберите посматрање простора или лет кроз простор и жељена тела. За сваки монитор посебно се "
    L"подешавају брзина објеката и камере 0–1600%, величина 50–200% и 1–10 копија сваког тела. Главно, "
    L"допунско, амбијентално и контурно светло укључују се независно.\r\n\r\nМОНИТОРИ\r\nИзаберите један "
    L"или више редова у листи монитора. Ctrl+A бира све; Ctrl и Shift мењају избор. Контроле и клизачи "
    L"анимације мењају само подешавања изабраних монитора. Избор реда није исто што и укључивање излаза "
    L"његовим пољем за потврду. Избор се памти одвојено за апликацију и чувар екрана. Ако су претходно били "
    L"изабрани сви монитори, укључују се и новоприкључени монитори. Различите вредности на изабраним "
    L"мониторима приказују се неодређеним стањем поља за потврду и тачкастим узорком на дугмадима избора, "
    L"ручкама клизача и дугмадима за укључивање или искључивање свих опција. Ознаке клизача приказују црту "
    L"уместо заједничке вредности. Промена опције или клик на клизач примењује ту вредност на све изабране "
    L"мониторе.\r\n\r\nУПРАВЉАЊЕ\r\nПокрените FlyingSolids.exe. Подешавања се стално чувају и ради само "
    L"једна инстанца апликације. Поље монитора или двоструки клик на ред укључује или искључује анимацијски "
    L"излаз. Анимацију можете паузирати и наставити. PNG и MP4 бележе први активни монитор анимације, не "
    L"заједничку слику свих монитора. Снимани монитор не можете искључити; затварање апликације током "
    L"снимања захтева потврду. Пауза и блокада чувара екрана важе за целу апликацију, без обзира на избор "
    L"монитора. Када је блокада укључена, чувар екрана система Windows спречава се само док је на бар "
    L"једном монитору видљива анимација која није паузирана. Апликација може инсталирати и деинсталирати "
    L"уграђени чувар екрана.\r\n\r\nСНИМЦИ ЕКРАНА И СНИМАЊЕ\r\nУ подешавањима снимања изаберите Viewport "
    L"или TV. Viewport задржава димензије и учестаност монитора до 60 кадрова у секунди. TV нуди 1920 × "
    L"1080, 1440 × 1080 или 1280 × 720 у односу 16:9, са 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) "
    L"кадрова у секунди. TV видео је прогресивни BT.709 ограниченог опсега с подузорковањем боје 4:2:0. "
    L"Однос слике остаје сачуван, а допунске траке су црне. OK чува опције за следећи снимак; Откажи или "
    L"Esc одбацује непотврђене измене. Прозори снимања, помоћи и информација не блокирају остале прозоре и "
    L"могу се минимизовати. Tab и Shift+Tab померају фокус, Enter активира фокусирано дугме, а Esc затвара "
    L"активни помоћни прозор.\r\n\r\nСИСТЕМСКИ ЗАХТЕВИ\r\nWindows 7–11 подржава све функције. За Windows "
    L"Vista SP2 морате инсталирати ажурирања KB971512 и KB2117917; MP4 снимање на Висти не ради. Потребан "
    L"је Direct3D 11, а за MP4 и Media Foundation и H.264 кодер. Интерфејс и документација доступни су на "
    L"36 језика.",
    L"АНІМАЦІЯ ТА НАЛАШТУВАННЯ\r\nFlyingSolids показує об’ємні тіла, які рухаються, обертаються й "
    L"стикаються. Виберіть спостереження за простором або політ крізь нього та потрібні тіла. Для кожного "
    L"монітора окремо задаються швидкості об’єктів і камери 0–1600%, розмір 50–200% та 1–10 копій кожного "
    L"тіла. Основне, заповнювальне, фонове й контурне світло вмикаються "
    L"незалежно.\r\n\r\nМОНІТОРИ\r\nВиберіть один або кілька рядків у списку моніторів. Ctrl+A вибирає всі; "
    L"Ctrl і Shift змінюють вибір. Елементи керування й повзунки анімації змінюють лише налаштування "
    L"вибраних моніторів. Вибір рядка та ввімкнення виведення його прапорцем — різні дії. Вибір "
    L"зберігається окремо для програми й заставки. Якщо раніше були вибрані всі монітори, до вибору "
    L"долучаються й новопідключені. Різні значення на вибраних моніторах позначаються невизначеним станом "
    L"прапорців і крапковим візерунком на перемикачах, ручках повзунків і кнопках увімкнення або вимкнення "
    L"всіх параметрів. Підписи повзунків показують тире замість спільного значення. Зміна параметра або "
    L"натискання на повзунок застосовує це значення до всіх вибраних "
    L"моніторів.\r\n\r\nКЕРУВАННЯ\r\nЗапустіть FlyingSolids.exe. Налаштування зберігаються постійно, працює "
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
    L"АНИМАЦИЯ И НАСТРОЙКИ\r\nFlyingSolids показывает объёмные тела, которые движутся, вращаются и "
    L"сталкиваются. Выберите наблюдение за пространством или полёт сквозь него и нужные тела. Для каждого "
    L"монитора отдельно задаются скорости объектов и камеры 0–1600%, размер 50–200% и 1–10 копий каждого "
    L"тела. Основной, заполняющий, фоновый и контурный свет включаются "
    L"независимо.\r\n\r\nМОНИТОРЫ\r\nВыберите одну или несколько строк в списке мониторов. Ctrl+A выбирает "
    L"все; Ctrl и Shift изменяют выбор. Элементы управления и ползунки анимации изменяют только настройки "
    L"выбранных мониторов. Выбор строки и включение вывода её флажком — разные действия. Выбор сохраняется "
    L"отдельно для приложения и заставки. Если раньше были выбраны все мониторы, в выбор включаются и вновь "
    L"подключённые. Разные значения на выбранных мониторах обозначаются неопределённым состоянием флажков и "
    L"точечным узором на переключателях, ручках ползунков и кнопках включения или выключения всех "
    L"параметров. Подписи ползунков показывают тире вместо общего значения. Изменение параметра или нажатие "
    L"на ползунок применяет это значение ко всем выбранным мониторам.\r\n\r\nУПРАВЛЕНИЕ\r\nЗапустите "
    L"FlyingSolids.exe. Настройки сохраняются постоянно, работает только один экземпляр приложения. Флажок "
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
    L"ANIMACE A NASTAVENÍ\r\nV seznamu označte jeden nebo více monitorů. Režim kamery, výběr těles, světla, "
    L"rychlosti, velikost a počet kopií se nastavují jen pro označené monitory a každý monitor si pamatuje "
    L"vlastní nastavení. Vyberte Pozorování prostoru nebo přímý Průlet prostorem. Jezdci nastavují rychlost "
    L"objektů a kamery 0–1600 %, jednu až deset kopií každého zapnutého tělesa a velikost 50–200 %. "
    L"Zatržítka Hlavní světlo, Doplňkové světlo, Základní jas a Přisvětlení obrysů pod jezdci nezávisle "
    L"ovládají osvětlení celé scény. Základní jas přisvětluje povrch těles, přisvětlení obrysů zvýrazňuje "
    L"jejich okraje. Nastavení osvětlení se ukládá zvlášť pro aplikaci a spořič "
    L"obrazovky.\r\n\r\nMONITORY\r\nOznačení řádků určuje, které monitory právě nastavujete; není totožné "
    L"se zatržítky zapínajícími animační výstupy. Ctrl+A označí všechny monitory, Ctrl a Shift umožňují "
    L"upravit označení. Všechny animační volby a jezdce platí pro označené monitory. Označení se pamatuje "
    L"zvlášť pro EXE a SCR. Pokud byly označené všechny monitory, označí se i nově připojené. Různé hodnoty "
    L"na označených monitorech ukazuje neurčitý stav zatržítek a tečkování přepínačů, úchytů jezdců a "
    L"tlačítek pro zapnutí či vypnutí všech voleb. Popisek jezdce místo společné hodnoty zobrazuje pomlčku. "
    L"Změna volby nebo kliknutí na jezdec sjednotí příslušnou hodnotu na označených "
    L"monitorech.\r\n\r\nNÁHLED A OVLÁDÁNÍ\r\nZapněte požadované druhy těles. Zapnout náhled spustí "
    L"celoobrazovkový náhled na všech monitorech; změny lze zkoušet za otevřeného nastavení. OK nastavení "
    L"uloží, Storno je zahodí. Celoobrazovkový spořič ukončíte klávesou Esc nebo pohybem myši. Mezi "
    L"ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a "
    L"příslušného písmene. Esc v nastavení odpovídá tlačítku Storno; v nápovědě nebo okně O aplikaci zavře "
    L"pouze toto okno.\r\n\r\nSYSTÉMOVÉ POŽADAVKY\r\nPodporovány jsou systémy Windows 7 až Windows 11. Pro "
    L"spuštění aplikace ve Windows Vista SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917. "
    L"Vykreslování vyžaduje Direct3D 11, nikoli jen starší DirectX runtime.",
    L"ANIMATION AND SETTINGS\r\nSelect one or more displays in the list. Camera mode, object selection, "
    L"lighting, speeds, size and copy count apply only to the selected displays, and each display remembers "
    L"its own settings. Choose Space observation or the straight Fly through space mode. The sliders set "
    L"object and camera speed from 0–1600%, one to ten copies of each enabled object, and size from "
    L"50–200%. The Main light, Fill light, Ambient light, and Rim light checkboxes below the sliders "
    L"independently control lighting for the whole scene. Ambient light provides base illumination of "
    L"object surfaces; rim light highlights their edges. Lighting settings are stored separately for the "
    L"application and screen saver.\r\n\r\nDISPLAYS\r\nRow selection determines which displays you are "
    L"editing; it is separate from the checkboxes that enable animation outputs. Ctrl+A selects every "
    L"display; Ctrl and Shift adjust the selection. All animation options and sliders apply to the selected "
    L"displays. The selection is remembered separately for EXE and SCR. If all displays were selected, "
    L"newly connected displays join the selection. Different values across selected displays are indicated "
    L"by indeterminate checkboxes and dotted radio buttons, slider thumbs, and buttons for enabling or "
    L"disabling all options. Slider labels show a dash instead of a shared value. Changing an option or "
    L"clicking a slider applies that value to all selected displays.\r\n\r\nPREVIEW AND CONTROLS\r\nEnable "
    L"the required object types. Enable preview starts a full-screen preview on every display while the "
    L"settings dialog remains open for live adjustments. OK saves the settings and Cancel discards them. "
    L"Exit the full-screen saver with Esc or mouse movement. Use Tab and Shift+Tab to move between "
    L"controls; use Alt and the underlined letter to activate a command. Esc in the settings dialog is "
    L"equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\nSYSTEM "
    L"REQUIREMENTS\r\nWindows 7 through Windows 11 are supported. To run the application on Windows Vista "
    L"SP2, you must install updates KB971512 and KB2117917. Rendering requires Direct3D 11, not just an "
    L"older DirectX runtime.",
    L"ANIMATION AND SETTINGS\r\nSelect one or more displays in the list. Camera mode, object selection, "
    L"lighting, speeds, size and copy count apply only to the selected displays, and each display remembers "
    L"its own settings. Choose Space observation or the straight Fly through space mode. Set object and "
    L"camera speed from 0–1600%, one to ten copies and size from 50–200%, then enable the required objects. "
    L"The Main light, Fill light, Ambient light, and Rim light checkboxes below the sliders independently "
    L"control lighting for the whole scene. Ambient light provides base illumination of object surfaces; "
    L"rim light highlights their edges. Lighting settings are stored separately for the application and "
    L"screen saver.\r\n\r\nDISPLAYS\r\nRow selection determines which displays you are editing; it is "
    L"separate from the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and "
    L"Shift adjust the selection. All animation options and sliders apply to the selected displays. The "
    L"selection is remembered separately for EXE and SCR. If all displays were selected, newly connected "
    L"displays join the selection. Different values across selected displays are indicated by indeterminate "
    L"checkboxes and dotted radio buttons, slider thumbs and buttons for enabling or disabling all options. "
    L"Slider labels show a dash instead of a shared value. Changing an option or clicking a slider applies "
    L"that value to all selected displays.\r\n\r\nPREVIEW AND CONTROLS\r\nEnable preview starts a "
    L"full-screen preview on every display while the settings dialog remains open for live adjustments. OK "
    L"saves the settings and Cancel discards them. Exit the full-screen screen saver with Esc or mouse "
    L"movement. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to "
    L"activate a command. Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes "
    L"only that window.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows 7 through Windows 11 are supported. To run "
    L"the application on Windows Vista SP2, you must install updates KB971512 and KB2117917. Rendering "
    L"requires Direct3D 11, not just an older DirectX runtime.",
    L"ANIMATION AND SETTINGS\r\nSelect one or more displays in the list. Camera mode, object selection, "
    L"lighting, speeds, size and copy count apply only to the selected displays, and each display remembers "
    L"its own settings. Choose Space observation or the straight Fly through space mode. Set object and "
    L"camera speed from 0–1600%, one to ten copies and size from 50–200%, then enable the required objects. "
    L"The Main light, Fill light, Ambient light, and Rim light checkboxes below the sliders independently "
    L"control lighting for the whole scene. Ambient light provides base illumination of object surfaces; "
    L"rim light highlights their edges. Lighting settings are stored separately for the application and "
    L"screen saver.\r\n\r\nDISPLAYS\r\nRow selection determines which displays you are editing; it is "
    L"separate from the checkboxes that enable animation outputs. Ctrl+A selects every display; Ctrl and "
    L"Shift adjust the selection. All animation options and sliders apply to the selected displays. The "
    L"selection is remembered separately for EXE and SCR. If all displays were selected, newly connected "
    L"displays join the selection. Different values across selected displays are indicated by indeterminate "
    L"checkboxes and dotted radio buttons, slider thumbs and buttons for enabling or disabling all options. "
    L"Slider labels show a dash instead of a shared value. Changing an option or clicking a slider applies "
    L"that value to all selected displays.\r\n\r\nPREVIEW AND CONTROLS\r\nEnable preview starts a "
    L"full-screen preview on every display while the settings dialog remains open for live adjustments. OK "
    L"saves the settings and Cancel discards them. Exit the full-screen screen saver with Esc or mouse "
    L"movement. Use Tab and Shift+Tab to move between controls; use Alt and the underlined letter to "
    L"activate a command. Esc in the settings dialog is equivalent to Cancel; in Help or About, it closes "
    L"only that window.\r\n\r\nSYSTEM REQUIREMENTS\r\nWindows 7 through Windows 11 are supported. To run "
    L"the application on Windows Vista SP2, you must install updates KB971512 and KB2117917. Rendering "
    L"requires Direct3D 11, not just an older DirectX runtime.",
    L"ANIMATION UND EINSTELLUNGEN\r\nMarkieren Sie einen oder mehrere Monitore in der Liste. Kameramodus, "
    L"Körperauswahl, Beleuchtung, Geschwindigkeiten, Größe und Anzahl der Exemplare gelten nur für die "
    L"markierten Monitore. Jeder Monitor speichert seine eigenen Einstellungen. Wählen Sie Raumbeobachtung "
    L"oder Flug durch den Raum in gerader Linie. Die Regler bestimmen Objekt- und Kamerageschwindigkeit von "
    L"0–1600 %, ein bis zehn Exemplare je aktivem Körper und 50–200 % Größe. Die Kontrollkästchen "
    L"Hauptlicht, Aufhelllicht, Umgebungslicht und Konturlicht unter den Reglern steuern die Beleuchtung "
    L"der gesamten Szene unabhängig voneinander. Umgebungslicht sorgt für eine Grundhelligkeit der "
    L"Körperoberflächen, Konturlicht betont ihre Ränder. Die Beleuchtungseinstellungen werden für Anwendung "
    L"und Bildschirmschoner getrennt gespeichert.\r\n\r\nMONITORE\r\nDie Zeilenauswahl bestimmt, welche "
    L"Monitore Sie bearbeiten; sie ist von den Kontrollkästchen zum Einschalten der Animationsausgabe "
    L"getrennt. Strg+A wählt alle Monitore, Strg und Umschalt ändern die Auswahl. Alle Animationsoptionen "
    L"und Regler gelten für die ausgewählten Monitore. Die Auswahl wird für EXE und SCR getrennt "
    L"gespeichert. Waren alle Monitore ausgewählt, werden auch neu angeschlossene ausgewählt. "
    L"Unterschiedliche Werte der ausgewählten Monitore werden durch unbestimmte Kontrollkästchen und "
    L"gepunktete Optionsfelder, Reglergriffe sowie Schaltflächen zum Ein- oder Ausschalten aller Optionen "
    L"angezeigt. Reglerbeschriftungen zeigen statt eines gemeinsamen Werts einen Gedankenstrich. Das Ändern "
    L"einer Option oder Anklicken eines Reglers übernimmt diesen Wert für alle ausgewählten "
    L"Monitore.\r\n\r\nVORSCHAU UND BEDIENUNG\r\nAktivieren Sie die gewünschten Körper. Vorschau "
    L"einschalten startet eine Vollbildvorschau auf allen Monitoren. Der Einstellungsdialog bleibt für "
    L"Änderungen geöffnet. OK speichert, Abbrechen verwirft. Esc oder eine Mausbewegung beendet den "
    L"Vollbildschoner. Mit Tab und Umschalt+Tab wechseln Sie zwischen den Steuerelementen; mit Alt und dem "
    L"unterstrichenen Buchstaben rufen Sie einen Befehl auf. Esc im Einstellungsdialog entspricht "
    L"Abbrechen; in der Hilfe oder im Infofenster schließt es nur dieses "
    L"Fenster.\r\n\r\nSYSTEMANFORDERUNGEN\r\nUnterstützt werden Windows 7 bis Windows 11. Zum Ausführen der "
    L"Anwendung unter Windows Vista SP2 müssen die Updates KB971512 und KB2117917 installiert werden. Die "
    L"Darstellung erfordert Direct3D 11, nicht nur eine ältere DirectX-Laufzeitumgebung.",
    L"ANIMATION ET PARAMÈTRES\r\nSélectionnez un ou plusieurs écrans dans la liste. Le mode de caméra, les "
    L"objets, l’éclairage, les vitesses, la taille et le nombre de copies ne s’appliquent qu’aux écrans "
    L"sélectionnés. Chaque écran mémorise ses propres réglages. Choisissez Observation de l’espace ou le "
    L"Vol dans l’espace rectiligne. Les curseurs règlent la vitesse des objets et de la caméra de 0 à 1 600 "
    L"%, une à dix copies et une taille de 50 à 200 %. Les cases Éclairage principal, Éclairage d’appoint, "
    L"Éclairage ambiant et Éclairage des contours sous les curseurs contrôlent indépendamment l’éclairage "
    L"de toute la scène. L’éclairage ambiant fournit une luminosité de base aux surfaces, et l’éclairage "
    L"des contours souligne leurs bords. Les réglages sont enregistrés séparément pour l’application et "
    L"l’économiseur d’écran.\r\n\r\nÉCRANS\r\nLa sélection des lignes détermine les écrans à configurer ; "
    L"elle est distincte des cases qui activent les sorties d’animation. Ctrl+A sélectionne tous les écrans "
    L"; Ctrl et Maj modifient la sélection. Toutes les options et tous les curseurs d’animation concernent "
    L"les écrans sélectionnés. La sélection est mémorisée séparément pour EXE et SCR. Si tous les écrans "
    L"étaient sélectionnés, les nouveaux le sont également. Des valeurs différentes entre les écrans "
    L"sélectionnés sont indiquées par des cases à cocher indéterminées et des pointillés sur les boutons "
    L"radio, les poignées des curseurs et les boutons d’activation ou de désactivation de toutes les "
    L"options. Les libellés des curseurs affichent un tiret au lieu d’une valeur commune. Modifier une "
    L"option ou cliquer sur un curseur applique cette valeur à tous les écrans sélectionnés.\r\n\r\nAPERÇU "
    L"ET COMMANDES\r\nActivez les solides voulus. Activer l’aperçu lance un aperçu plein écran sur tous les "
    L"moniteurs ; la boîte de dialogue reste ouverte pour les réglages en direct. OK enregistre les "
    L"réglages, Annuler les abandonne. Échap ou un mouvement de souris quitte le plein écran. Utilisez Tab "
    L"et Maj+Tab pour passer d’un contrôle à l’autre ; Alt et la lettre soulignée activent une commande. "
    L"Échap dans les réglages équivaut à Annuler ; dans l’aide ou À propos, cette touche ferme uniquement "
    L"cette fenêtre.\r\n\r\nCONFIGURATION REQUISE\r\nWindows 7 à Windows 11 sont pris en charge. Pour "
    L"exécuter l’application sous Windows Vista SP2, il est nécessaire d’installer les mises à jour "
    L"KB971512 et KB2117917. L’affichage nécessite Direct3D 11, et pas seulement un ancien environnement "
    L"d’exécution DirectX.",
    L"ANIMACIÓN Y AJUSTES\r\nSeleccione una o varias pantallas en la lista. El modo de cámara, los objetos, "
    L"la iluminación, las velocidades, el tamaño y el número de copias se aplican solo a las pantallas "
    L"seleccionadas. Cada pantalla guarda sus propios ajustes. Elija Observación del espacio o Vuelo por el "
    L"espacio en línea recta. Los controles ajustan la velocidad de objetos y cámara del 0 al 1600 %, de "
    L"una a diez copias y el tamaño del 50 al 200 %. Las casillas Luz principal, Luz de relleno, Luz "
    L"ambiental e Iluminación de contornos bajo los controles deslizantes controlan de forma independiente "
    L"la iluminación de toda la escena. La luz ambiental aporta iluminación básica a las superficies y la "
    L"iluminación de contornos resalta sus bordes. De forma predeterminada, las luces principal, ambiental "
    L"y de contornos están activadas, y la luz de relleno está desactivada. Los ajustes se guardan por "
    L"separado para la aplicación y el salvapantallas.\r\n\r\nMONITORES\r\nLa selección de filas determina "
    L"qué pantallas se están configurando; es independiente de las casillas que activan las salidas de "
    L"animación. Ctrl+A selecciona todas; Ctrl y Mayús modifican la selección. Todas las opciones y los "
    L"controles deslizantes de animación se aplican a las pantallas seleccionadas. La selección se recuerda "
    L"por separado para EXE y SCR. Si estaban seleccionadas todas, se incluyen también las nuevas. Los "
    L"valores distintos entre las pantallas seleccionadas se indican mediante casillas indeterminadas y un "
    L"punteado en los botones de opción, los tiradores de los controles deslizantes y los botones para "
    L"activar o desactivar todas las opciones. Las etiquetas de los controles deslizantes muestran una raya "
    L"en lugar de un valor común. Cambiar una opción o hacer clic en un control deslizante aplica ese valor "
    L"a todas las pantallas seleccionadas.\r\n\r\nVISTA PREVIA Y CONTROLES\r\nActive los sólidos deseados. "
    L"Activar vista previa inicia una vista previa a pantalla completa en todos los monitores; el cuadro de "
    L"configuración permanece abierto para realizar ajustes en tiempo real. Aceptar guarda y Cancelar "
    L"descarta. Esc o mover el ratón cierra el salvapantallas completo. Use Tab y Mayús+Tab para "
    L"desplazarse entre controles; Alt y la letra subrayada activan una opción. Esc en la configuración "
    L"equivale a Cancelar; en Ayuda o Acerca de, cierra únicamente esa ventana.\r\n\r\nREQUISITOS DEL "
    L"SISTEMA\r\nSe admiten Windows 7 a Windows 11. Para ejecutar la aplicación en Windows Vista SP2, es "
    L"necesario instalar las actualizaciones KB971512 y KB2117917. La representación requiere Direct3D 11, "
    L"no solo un entorno de ejecución antiguo de DirectX.",
    L"ANIMAZIONE E IMPOSTAZIONI\r\nSelezionare uno o più monitor nell’elenco. La modalità della telecamera, "
    L"gli oggetti, le luci, le velocità, le dimensioni e il numero di copie si applicano solo ai monitor "
    L"selezionati. Ogni monitor conserva le proprie impostazioni. Scegliere Osservazione dello spazio o "
    L"Volo nello spazio rettilineo. I cursori regolano la velocità di oggetti e camera da 0 a 1600 %, da "
    L"una a dieci copie e la dimensione da 50 a 200 %. Le caselle Luce principale, Luce di riempimento, "
    L"Luce ambientale e Illuminazione dei contorni sotto i cursori controllano indipendentemente "
    L"l’illuminazione dell’intera scena. La luce ambientale fornisce un’illuminazione di base alle "
    L"superfici, mentre quella dei contorni ne evidenzia i bordi. Le impostazioni vengono salvate "
    L"separatamente per l’applicazione e il salvaschermo.\r\n\r\nMONITOR\r\nLa selezione delle righe "
    L"determina quali schermi si stanno configurando ed è distinta dalle caselle che attivano le uscite di "
    L"animazione. Ctrl+A seleziona tutti gli schermi; Ctrl e Maiusc modificano la selezione. Tutte le "
    L"opzioni e i cursori dell’animazione riguardano gli schermi selezionati. La selezione viene "
    L"memorizzata separatamente per EXE e SCR. Se erano selezionati tutti gli schermi, vengono inclusi "
    L"anche quelli nuovi. Valori diversi tra gli schermi selezionati sono indicati da caselle di controllo "
    L"indeterminate e da una trama a punti sui pulsanti di opzione, sulle maniglie dei cursori e sui "
    L"pulsanti per attivare o disattivare tutte le opzioni. Le etichette dei cursori mostrano un trattino "
    L"al posto di un valore comune. Modificare un’opzione o fare clic su un cursore applica quel valore a "
    L"tutti gli schermi selezionati.\r\n\r\nANTEPRIMA E COMANDI\r\nAttivare i solidi desiderati. Attiva "
    L"anteprima avvia un’anteprima a schermo intero su tutti i monitor; le impostazioni rimangono aperte "
    L"per le modifiche in tempo reale. OK salva e Annulla scarta. Esc o il movimento del mouse chiude il "
    L"salvaschermo a schermo intero. Usare Tab e Maiusc+Tab per passare tra i controlli; Alt e la lettera "
    L"sottolineata attivano un comando. Esc nelle impostazioni equivale ad Annulla; nella Guida o nelle "
    L"Informazioni, chiude solo quella finestra.\r\n\r\nREQUISITI DI SISTEMA\r\nSono supportati i sistemi "
    L"da Windows 7 a Windows 11. Per eseguire l’applicazione su Windows Vista SP2, è necessario installare "
    L"gli aggiornamenti KB971512 e KB2117917. La visualizzazione richiede Direct3D 11, non soltanto un "
    L"vecchio runtime DirectX.",
    L"ANIMAÇÃO E DEFINIÇÕES\r\nSelecione um ou mais monitores na lista. O modo de câmara, os objetos, a "
    L"iluminação, as velocidades, o tamanho e o número de cópias aplicam-se apenas aos monitores "
    L"selecionados. Cada monitor guarda as suas próprias definições. Escolha Observação do espaço ou Voo "
    L"pelo espaço em linha reta. Regule a velocidade dos objetos e da câmara de 0 a 1600%, uma a dez cópias "
    L"e o tamanho de 50 a 200%, e ative os sólidos. As caixas Luz principal, Luz de preenchimento, Luz "
    L"ambiente e Iluminação dos contornos sob os controlos deslizantes controlam a iluminação de toda a "
    L"cena de forma independente. A luz ambiente fornece iluminação de base às superfícies e a iluminação "
    L"dos contornos realça os seus limites. Por predefinição, as luzes principal, ambiente e dos contornos "
    L"estão ligadas e a luz de preenchimento está desligada. As definições são guardadas separadamente para "
    L"a aplicação e a proteção de ecrã.\r\n\r\nMONITORES\r\nA seleção das linhas determina os ecrãs a "
    L"configurar e é independente das caixas que ativam as saídas de animação. Ctrl+A seleciona todos os "
    L"ecrãs; Ctrl e Shift alteram a seleção. Todas as opções e controlos deslizantes da animação aplicam-se "
    L"aos ecrãs selecionados. A seleção é guardada separadamente para EXE e SCR. Se todos estavam "
    L"selecionados, os novos ecrãs também são incluídos. Valores diferentes entre os ecrãs selecionados são "
    L"indicados por caixas de verificação indeterminadas e por um padrão pontilhado nos botões de opção, "
    L"nas pegas dos controlos deslizantes e nos botões para ativar ou desativar todas as opções. As "
    L"etiquetas dos controlos deslizantes apresentam um travessão em vez de um valor comum. Alterar uma "
    L"opção ou clicar num controlo deslizante aplica esse valor a todos os ecrãs "
    L"selecionados.\r\n\r\nPRÉ-VISUALIZAÇÃO E CONTROLOS\r\nAtivar pré-visualização inicia uma "
    L"pré-visualização em ecrã inteiro em todos os monitores; o diálogo permanece aberto para ajustar as "
    L"definições em tempo real. OK guarda as definições e Cancelar descarta-as. Esc ou o movimento do rato "
    L"termina a proteção em ecrã inteiro. Use Tab e Shift+Tab para passar entre controlos; Alt e a letra "
    L"sublinhada ativam um comando. Esc nas definições equivale a Cancelar; na Ajuda ou em Acerca de, fecha "
    L"apenas essa janela.\r\n\r\nREQUISITOS DO SISTEMA\r\nSão suportados os sistemas Windows 7 a Windows "
    L"11. Para executar a aplicação no Windows Vista SP2, é necessário instalar as atualizações KB971512 e "
    L"KB2117917. A apresentação requer Direct3D 11, não apenas um runtime DirectX mais antigo.",
    L"ANIMACJA I USTAWIENIA\r\nZaznacz jeden lub więcej monitorów na liście. Tryb kamery, wybór brył, "
    L"oświetlenie, prędkości, rozmiar i liczba kopii dotyczą tylko zaznaczonych monitorów. Każdy monitor "
    L"zapamiętuje własne ustawienia. Wybierz Obserwację przestrzeni albo prostoliniowy Przelot przez "
    L"przestrzeń. Suwaki ustawiają prędkość obiektów i kamery 0–1600%, od jednej do dziesięciu kopii i "
    L"rozmiar 50–200%. Pola wyboru Światło główne, Światło wypełniające, Światło otoczenia i Oświetlenie "
    L"konturów pod suwakami niezależnie sterują oświetleniem całej sceny. Światło otoczenia zapewnia "
    L"podstawową jasność powierzchni, a oświetlenie konturów podkreśla krawędzie. Ustawienia są zapisywane "
    L"osobno dla aplikacji i wygaszacza ekranu.\r\n\r\nMONITORY\r\nZaznaczenie wierszy określa "
    L"konfigurowane monitory i jest niezależne od pól wyboru włączających wyjścia animacji. Ctrl+A zaznacza "
    L"wszystkie monitory; Ctrl i Shift zmieniają zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą "
    L"zaznaczonych monitorów. Zaznaczenie jest zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były "
    L"wszystkie monitory, nowe również zostaną zaznaczone. Różne wartości na zaznaczonych monitorach są "
    L"sygnalizowane nieokreślonym stanem pól wyboru i kropkowaniem przycisków opcji, uchwytów suwaków oraz "
    L"przycisków włączania i wyłączania wszystkich opcji. Etykiety suwaków pokazują kreskę zamiast wspólnej "
    L"wartości. Zmiana opcji lub kliknięcie suwaka ustawia tę wartość na wszystkich zaznaczonych "
    L"monitorach.\r\n\r\nPODGLĄD I OBSŁUGA\r\nWłącz potrzebne bryły. Włącz podgląd uruchamia podgląd "
    L"pełnoekranowy na wszystkich monitorach. Okno ustawień pozostaje otwarte, umożliwiając zmiany na "
    L"bieżąco. OK zapisuje ustawienia, a Anuluj je odrzuca. Esc lub ruch myszy kończy tryb pełnoekranowy. "
    L"Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera wywołują polecenie. "
    L"Esc w ustawieniach odpowiada przyciskowi Anuluj; w Pomocy lub O programie zamyka tylko to "
    L"okno.\r\n\r\nWYMAGANIA SYSTEMOWE\r\nObsługiwane są systemy od Windows 7 do Windows 11. Do "
    L"uruchomienia aplikacji w systemie Windows Vista SP2 konieczne jest zainstalowanie aktualizacji "
    L"KB971512 i KB2117917. Wyświetlanie wymaga Direct3D 11, a nie tylko starszego środowiska DirectX.",
    L"ANIMÁCIA A NASTAVENIA\r\nV zozname označte jeden alebo viac monitorov. Režim kamery, výber telies, "
    L"svetlá, rýchlosti, veľkosť a počet kópií sa nastavujú len pre označené monitory a každý monitor si "
    L"pamätá vlastné nastavenia. Vyberte Pozorovanie priestoru alebo priamy Prelet priestorom. Jazdce "
    L"nastavujú rýchlosť objektov a kamery 0–1600 %, jednu až desať kópií a veľkosť 50–200 %. Začiarkavacie "
    L"políčka Hlavné svetlo, Doplnkové svetlo, Základný jas a Prisvetlenie obrysov pod jazdcami nezávisle "
    L"ovládajú osvetlenie celej scény. Základný jas prisvetľuje povrchy telies a prisvetlenie obrysov "
    L"zvýrazňuje ich okraje. Nastavenia osvetlenia sa ukladajú zvlášť pre aplikáciu a šetrič "
    L"obrazovky.\r\n\r\nMONITORY\r\nOznačenie riadkov určuje, ktoré monitory práve nastavujete; je "
    L"nezávislé od políčok zapínajúcich animačné výstupy. Ctrl+A označí všetky monitory, Ctrl a Shift "
    L"upravujú označenie. Všetky animačné voľby a posuvníky platia pre označené monitory. Označenie sa "
    L"pamätá zvlášť pre EXE a SCR. Ak boli označené všetky monitory, označia sa aj novopripojené. Rozdielne "
    L"hodnoty na označených monitoroch ukazuje neurčitý stav políčok a bodkovanie prepínačov, úchytov "
    L"posuvníkov a tlačidiel na zapnutie či vypnutie všetkých volieb. Popis posuvníka namiesto spoločnej "
    L"hodnoty zobrazuje pomlčku. Zmena voľby alebo kliknutie na posuvník zjednotí príslušnú hodnotu na "
    L"označených monitoroch.\r\n\r\nNÁHĽAD A OVLÁDANIE\r\nZapnite požadované telesá. Zapnúť náhľad spustí "
    L"celoobrazovkový náhľad na všetkých monitoroch; nastavenia zostávajú otvorené a zmeny sa prejavia "
    L"ihneď. OK uloží nastavenia a Zrušiť ich zahodí. Celoobrazovkový šetrič ukončí Esc alebo pohyb myši. "
    L"Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou "
    L"Alt a príslušného písmena. Esc v nastaveniach zodpovedá tlačidlu Zrušiť; v Pomocníkovi alebo okne O "
    L"aplikácii zavrie iba toto okno.\r\n\r\nSYSTÉMOVÉ POŽIADAVKY\r\nPodporované sú systémy Windows 7 až "
    L"Windows 11. Na spustenie aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať aktualizácie "
    L"KB971512 a KB2117917. Vykresľovanie vyžaduje Direct3D 11, nie iba starší DirectX runtime.",
    L"ANIMATION OG INDSTILLINGER\r\nVælg en eller flere skærme på listen. Kameratilstand, objekter, "
    L"belysning, hastigheder, størrelse og antal kopier gælder kun de valgte skærme. Hver skærm husker sine "
    L"egne indstillinger. Vælg Rumobservation eller Flyvning gennem rummet i en lige linje. Indstil objekt- "
    L"og kamerahastighed 0–1600 %, en til ti kopier og størrelse 50–200 %, og aktivér de ønskede legemer. "
    L"Afkrydsningsfelterne Hovedlys, Udfyldningslys, Omgivende lys og Konturlys under skyderne styrer "
    L"belysningen af hele scenen uafhængigt af hinanden. Omgivende lys giver overfladerne en "
    L"grundbelysning, og konturlys fremhæver kanterne. Som standard er hovedlys, omgivende lys og konturlys "
    L"slået til og udfyldningslys slået fra. Indstillingerne gemmes separat for programmet og "
    L"pauseskærmen.\r\n\r\nSKÆRME\r\nMarkeringen af rækker bestemmer, hvilke skærme du indstiller, og er "
    L"adskilt fra afkrydsningsfelterne, der aktiverer animationsoutput. Ctrl+A markerer alle skærme; Ctrl "
    L"og Skift ændrer markeringen. Alle animationsvalg og skydere gælder de markerede skærme. Markeringen "
    L"huskes separat for EXE og SCR. Hvis alle skærme var markeret, medtages også nye skærme. Forskellige "
    L"værdier på de markerede skærme vises med ubestemte afkrydsningsfelter og prikmønstre på "
    L"alternativknapper, skydergreb og knapper til at slå alle valg til eller fra. Skydernes etiketter "
    L"viser en tankestreg i stedet for en fælles værdi. Ændring af et valg eller klik på en skyder anvender "
    L"denne værdi på alle markerede skærme.\r\n\r\nFORHÅNDSVISNING OG BETJENING\r\nAktivér forhåndsvisning "
    L"starter en forhåndsvisning i fuld skærm på alle skærme. Indstillingerne forbliver åbne, og "
    L"ændringerne vises med det samme. OK gemmer indstillingerne, og Annuller forkaster ændringerne. Esc "
    L"eller musebevægelse afslutter fuldskærmen. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; "
    L"Alt og det understregede bogstav aktiverer en kommando. Esc i indstillingerne svarer til Annuller; i "
    L"Hjælp eller Om lukker det kun dette vindue.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 "
    L"understøttes. For at køre programmet på Windows Vista SP2 skal opdateringerne KB971512 og KB2117917 "
    L"installeres. Visningen kræver Direct3D 11, ikke kun et ældre DirectX-kørselsmiljø.",
    L"ANIMAATIO JA ASETUKSET\r\nValitse luettelosta yksi tai useampi näyttö. Kameratila, kappaleet, "
    L"valaistus, nopeudet, koko ja kopioiden määrä koskevat vain valittuja näyttöjä. Jokainen näyttö "
    L"muistaa omat asetuksensa. Valitse Avaruuden tarkkailu tai Lento avaruuden halki suoraan eteenpäin. "
    L"Aseta kohteiden ja kameran nopeus 0–1600 %, yhdestä kymmeneen kopiota ja koko 50–200 %, ja ota "
    L"halutut kappaleet käyttöön. Liukusäätimien alla olevat Päävalo-, Täytevalo-, Ympäristövalo- ja "
    L"Reunavalo-valintaruudut ohjaavat koko näkymän valaistusta toisistaan riippumatta. Ympäristövalo antaa "
    L"pinnoille perusvalaistuksen ja reunavalo korostaa reunoja. Oletuksena päävalo, ympäristövalo ja "
    L"reunavalo ovat päällä ja täytevalo pois päältä. Asetukset tallennetaan erikseen sovellukselle ja "
    L"näytönsäästäjälle.\r\n\r\nNÄYTÖT\r\nRivien valinta määrää muokattavat näytöt ja on erillinen "
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
    L"HREYFIMYND OG STILLINGAR\r\nVeldu einn eða fleiri skjái á listanum. Myndavélarhamur, hlutir, lýsing, "
    L"hraði, stærð og fjöldi eintaka eiga aðeins við um valda skjái. Hver skjár geymir sínar eigin "
    L"stillingar. Veldu Athugun rýmis eða Flug um rýmið í beinni línu. Stilltu hraða hluta og myndavélar á "
    L"0–1600%, eitt til tíu eintök og stærð á 50–200% og virkjaðu óskaða hluti. Gátreitirnir Aðalljós, "
    L"Fylliljós, Umhverfislýsing og Útlínulýsing undir rennistikunum stýra lýsingu allrar senunnar óháð "
    L"hver öðrum. Umhverfislýsing gefur yfirborðunum grunnbirtu og útlínulýsing dregur fram jaðrana. "
    L"Stillingarnar eru vistaðar sérstaklega fyrir forritið og skjáhvíluna.\r\n\r\nSKJÁIR\r\nVal lína "
    L"ákvarðar hvaða skjám er verið að breyta og er óháð gátreitunum sem kveikja á hreyfimyndaúttaki. "
    L"Ctrl+A velur alla skjái; Ctrl og Shift breyta valinu. Allir valkostir og sleðar hreyfimynda gilda "
    L"fyrir valda skjái. Valið er munað sérstaklega fyrir EXE og SCR. Ef allir skjáir voru valdir bætast "
    L"nýir skjáir einnig við valið. Mismunandi gildi á völdum skjám eru sýnd með óákveðnu ástandi gátreita "
    L"og punktamynstri á valhnöppum, handföngum sleða og hnöppum sem kveikja eða slökkva á öllum valkostum. "
    L"Merking sleða sýnir strik í stað sameiginlegs gildis. Að breyta valkosti eða smella á sleða setur það "
    L"gildi á alla valda skjái.\r\n\r\nFORSKOÐUN OG NOTKUN\r\nVirkja forskoðun ræsir forskoðun á öllum "
    L"skjánum á hverjum skjá. Stillingaglugginn helst opinn og breytingar sjást strax. Í lagi vistar "
    L"stillingar og Hætta við hafnar breytingum. Esc eða músarhreyfing lokar skjáhvílu á öllum skjánum. "
    L"Notaðu Tab og Shift+Tab til að færa þig milli stýrieininga; Alt og undirstrikaður stafur virkja "
    L"skipun. Esc í stillingum jafngildir Hætta við; í Hjálp eða Um lokar það aðeins þeim "
    L"glugga.\r\n\r\nKERFISKRÖFUR\r\nWindows 7 til Windows 11 eru studd. Til að keyra forritið á Windows "
    L"Vista SP2 þarf að setja upp uppfærslurnar KB971512 og KB2117917. Birting krefst Direct3D 11, ekki "
    L"aðeins eldri DirectX-keyrsluumhverfis.",
    L"ANIMASJON OG INNSTILLINGER\r\nVelg én eller flere skjermer i listen. Kameramodus, objekter, "
    L"belysning, hastigheter, størrelse og antall kopier gjelder bare de valgte skjermene. Hver skjerm "
    L"husker sine egne innstillinger. Velg Romobservasjon eller Flyging gjennom rommet i rett linje. Angi "
    L"objekt- og kamerahastighet 0–1600 %, én til ti kopier og størrelse 50–200 %, og aktiver ønskede "
    L"legemer. Avmerkingsboksene Hovedlys, Utfyllingslys, Omgivelseslys og Konturlys under glidebryterne "
    L"styrer belysningen i hele scenen uavhengig av hverandre. Omgivelseslys gir grunnbelysning på "
    L"overflatene, og konturlys fremhever kantene. Som standard er hovedlys, omgivelseslys og konturlys på, "
    L"og utfyllingslys av. Innstillingene lagres separat for programmet og "
    L"skjermspareren.\r\n\r\nSKJERMER\r\nMarkeringen av rader bestemmer hvilke skjermer du redigerer, og er "
    L"atskilt fra avkrysningsboksene som aktiverer animasjonsutgangen. Ctrl+A markerer alle skjermer; Ctrl "
    L"og Skift endrer markeringen. Alle animasjonsvalg og glidebrytere gjelder de markerte skjermene. "
    L"Markeringen huskes separat for EXE og SCR. Hvis alle skjermer var markert, inkluderes også nye "
    L"skjermer. Ulike verdier på de markerte skjermene vises med ubestemte avkrysningsbokser og "
    L"prikkmønster på alternativknapper, glidebryterhåndtak og knapper for å slå alle valg av eller på. "
    L"Glidebryteretiketter viser en tankestrek i stedet for en felles verdi. Endring av et valg eller klikk "
    L"på en glidebryter bruker denne verdien på alle markerte skjermer.\r\n\r\nFORHÅNDSVISNING OG "
    L"BETJENING\r\nSlå på forhåndsvisning starter en forhåndsvisning i fullskjerm på alle skjermer. "
    L"Innstillingene forblir åpne, og endringene vises fortløpende. OK lagrer innstillingene og Avbryt "
    L"forkaster dem. Esc eller musebevegelse avslutter fullskjermsvisningen. Bruk Tab og Shift+Tab for å "
    L"flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en kommando. Esc i "
    L"innstillingene tilsvarer Avbryt; i Hjelp eller Om lukker det bare dette "
    L"vinduet.\r\n\r\nSYSTEMKRAV\r\nWindows 7 til Windows 11 støttes. For å kjøre programmet på Windows "
    L"Vista SP2 må oppdateringene KB971512 og KB2117917 installeres. Visningen krever Direct3D 11, ikke "
    L"bare en eldre DirectX-kjøretid.",
    L"ANIMERING OCH INSTÄLLNINGAR\r\nMarkera en eller flera skärmar i listan. Kameraläge, objekt, "
    L"belysning, hastigheter, storlek och antal kopior gäller bara de markerade skärmarna. Varje skärm "
    L"sparar sina egna inställningar. Välj Rymdobservation eller Flygning genom rymden i rak linje. Ställ "
    L"in objekt- och kamerahastighet 0–1600 %, en till tio kopior och storlek 50–200 %, och aktivera "
    L"önskade kroppar. Kryssrutorna Huvudljus, Upplättningsljus, Omgivningsljus och Konturljus under "
    L"reglagen styr belysningen i hela scenen oberoende av varandra. Omgivningsljus ger grundbelysning på "
    L"ytorna och konturljus framhäver kanterna. Som standard är huvudljus, omgivningsljus och konturljus på "
    L"och upplättningsljus av. Inställningarna sparas separat för programmet och "
    L"skärmsläckaren.\r\n\r\nBILDSKÄRMAR\r\nMarkeringen av rader avgör vilka skärmar du redigerar och är "
    L"skild från kryssrutorna som aktiverar animationsutgångarna. Ctrl+A markerar alla skärmar; Ctrl och "
    L"Skift ändrar markeringen. Alla animationsalternativ och reglage gäller de markerade skärmarna. "
    L"Markeringen sparas separat för EXE och SCR. Om alla skärmar var markerade inkluderas även nya "
    L"skärmar. Olika värden på de markerade skärmarna visas med obestämda kryssrutor och punktmönster på "
    L"alternativknappar, reglagehandtag och knappar för att slå på eller av alla alternativ. Reglagens "
    L"etiketter visar ett streck i stället för ett gemensamt värde. När du ändrar ett alternativ eller "
    L"klickar på ett reglage används värdet på alla markerade skärmar.\r\n\r\nFÖRHANDSGRANSKNING OCH "
    L"ANVÄNDNING\r\nAktivera förhandsvisning startar en förhandsvisning i helskärm på alla bildskärmar. "
    L"Inställningarna förblir öppna och ändringarna visas direkt. OK sparar inställningarna och Avbryt "
    L"förkastar ändringarna. Esc eller musrörelse avslutar helskärmsläget. Använd Tab och Skift+Tab för att "
    L"flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett kommando. Esc i "
    L"inställningarna motsvarar Avbryt; i Hjälp eller Om stänger det bara det "
    L"fönstret.\r\n\r\nSYSTEMKRAV\r\nWindows 7 till Windows 11 stöds. För att köra programmet på Windows "
    L"Vista SP2 måste uppdateringarna KB971512 och KB2117917 installeras. Visningen kräver Direct3D 11, "
    L"inte bara en äldre DirectX-körningsmiljö.",
    L"ANİMASYON VE AYARLAR\r\nListeden bir veya daha fazla ekran seçin. Kamera modu, nesneler, aydınlatma, "
    L"hızlar, boyut ve kopya sayısı yalnızca seçili ekranlara uygulanır. Her ekran kendi ayarlarını "
    L"hatırlar. Uzayı gözlemleme veya doğrusal Uzayda uçuş kipini seçin. Nesne ve kamera hızını %0–1600, "
    L"kopya sayısını bir ile on ve boyutu %50–200 arasında ayarlayıp istenen cisimleri etkinleştirin. "
    L"Kaydırıcıların altındaki Ana ışık, Dolgu ışığı, Ortam ışığı ve Kenar aydınlatması onay kutuları tüm "
    L"sahnenin aydınlatmasını birbirinden bağımsız olarak kontrol eder. Ortam ışığı yüzeylere temel "
    L"aydınlatma sağlar, kenar aydınlatması ise kenarları vurgular. Ayarlar uygulama ve ekran koruyucu için "
    L"ayrı ayrı kaydedilir.\r\n\r\nEKRANLAR\r\nSatır seçimi, hangi ekranların düzenlendiğini belirler; "
    L"animasyon çıkışlarını açan onay kutularından ayrıdır. Ctrl+A tüm ekranları seçer; Ctrl ve Shift "
    L"seçimi değiştirir. Tüm animasyon seçenekleri ve kaydırıcılar seçili ekranlara uygulanır. Seçim EXE ve "
    L"SCR için ayrı saklanır. Tüm ekranlar seçiliyse sonradan bağlanan ekranlar da seçime katılır. Seçili "
    L"ekranlardaki farklı değerler, belirsiz durumdaki onay kutuları ve seçenek düğmelerinde, kaydırıcı "
    L"tutamaçlarında ve tüm seçenekleri açıp kapatan düğmelerde noktalı desenle gösterilir. Kaydırıcı "
    L"etiketleri ortak bir değer yerine çizgi gösterir. Bir seçeneği değiştirmek veya kaydırıcıya tıklamak "
    L"bu değeri tüm seçili ekranlara uygular.\r\n\r\nÖNİZLEME VE KULLANIM\r\nÖnizlemeyi aç, tüm "
    L"monitörlerde tam ekran önizleme başlatır. Ayarlar penceresi açık kalır ve değişiklikler anında "
    L"görülür. Tamam ayarları kaydeder, İptal değişiklikleri iptal eder. Tam ekran koruyucudan Esc veya "
    L"fare hareketiyle çıkılır. Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf "
    L"bir komutu etkinleştirir. Ayarlarda Esc, İptal ile aynı işlevi görür; Yardım veya Hakkında "
    L"penceresinde yalnızca o pencereyi kapatır.\r\n\r\nSİSTEM GEREKSİNİMLERİ\r\nWindows 7 ile Windows 11 "
    L"arasındaki sürümler desteklenir. Uygulamayı Windows Vista SP2'de çalıştırmak için KB971512 ve "
    L"KB2117917 güncellemelerini yüklemeniz gerekir. Görüntüleme, yalnızca eski bir DirectX çalışma zamanı "
    L"değil, Direct3D 11 gerektirir.",
    L"ANIMATSIOON JA SÄTTED\r\nFlyingSolids kuvab liikuvaid, pöörlevaid ja põrkuvaid ruumilisi kehi. Valige "
    L"ruumi vaatlemine või lend läbi ruumi ning soovitud kehad. Iga kuvari jaoks saab eraldi määrata "
    L"objektide ja kaamera kiiruse 0–1600%, objektide suuruse 50–200% ning iga keha koopiate arvu 1–10. "
    L"Põhi-, täite-, ümbritsev ja kontuurivalgus on sõltumatult lülitatavad.\r\n\r\nKUVARID\r\nValige "
    L"loendis üks või mitu kuvaririda. Ctrl+A valib kõik read; Ctrl ja Shift võimaldavad valikut muuta. "
    L"Animatsiooni juhtnupud ja liugurid mõjutavad ainult valitud kuvarite sätteid, mitte kogu rakendust. "
    L"Rea valimine ja selle märkeruuduga väljundi lubamine on eri toimingud. Valik jäetakse rakenduse ja "
    L"ekraanisäästja jaoks eraldi meelde. Kui varem olid valitud kõik kuvarid, kaasatakse ka lisatud "
    L"kuvarid. Valitud kuvarite erinevaid väärtusi näitavad märkeruutude määramata olek ning raadionuppude, "
    L"liugurite käepidemete ja kõigi valikute lülitusnuppude punktimuster. Liuguri sildil on ühise väärtuse "
    L"asemel kriips. Valiku muutmine või liuguril klõpsamine määrab selle väärtuse kõigile valitud "
    L"kuvaritele.\r\n\r\nEELVAADE JA KASUTAMINE\r\nKäivitage FlyingSolids.scr Windowsi ekraanisäästjana. "
    L"Selle sätted on rakenduse omadest eraldi. Sätete eelvaade lubab täisekraanil animatsiooni jooksvalt "
    L"muuta. OK salvestab muudatused ning Loobu või Esc tühistab need. Täisekraanil ekraanisäästjast "
    L"väljumiseks vajutage klahvi või liigutage hiirt.\r\n\r\nSÜSTEEMINÕUDED\r\nWindows 7–11 toetab kõiki "
    L"funktsioone. Windows Vista SP2 jaoks tuleb paigaldada värskendused KB971512 ja KB2117917. Vaja on "
    L"Direct3D 11 tuge.",
    L"BEOCHAN AGUS SOCRUITHE\r\nTaispeánann FlyingSolids coirp sholadacha a ghluaiseann, a rothlaíonn agus "
    L"a imbhuaileann. Roghnaigh breathnú ar an spás nó eitilt tríd agus na coirp atá uait. Tá luas na réad "
    L"agus an cheamara 0–1600%, méid na réad 50–200% agus 1–10 gcóip de gach corp inchoigeartaithe go "
    L"neamhspleách do gach monatóir. Is féidir an príomhsholas, an solas líonta, an solas comhthimpeallach "
    L"agus an solas imill a athrú ar leith.\r\n\r\nTAISPEÁNTAIS\r\nRoghnaigh ró amháin nó níos mó sa liosta "
    L"monatóirí. Roghnaíonn Ctrl+A gach ró; úsáid Ctrl agus Shift chun an roghnú a athrú. Ní athraíonn "
    L"rialuithe agus sleamhnáin na beochana ach socruithe na monatóirí roghnaithe. Ní hionann ró a roghnú "
    L"agus aschur an mhonatóra a chumasú lena bhosca seiceála. Cuimhnítear an roghnú ar leith don "
    L"fheidhmchlár agus don spárálaí. Má bhí gach monatóir roghnaithe, cuirtear monatóirí nua leis an "
    L"roghnú freisin. Léirítear luachanna éagsúla ar na monatóirí roghnaithe le boscaí seiceála i staid "
    L"neamhchinnte agus le patrún poncanna ar chnaipí raidió, ar ghreimíní sleamhnán agus ar na cnaipí a "
    L"chumasaíonn nó a dhíchumasaíonn gach rogha. Taispeántar dais ar lipéad an tsleamhnáin in ionad luach "
    L"coiteann. Nuair a athraítear rogha nó a chliceáiltear sleamhnán, cuirtear an luach sin i bhfeidhm ar "
    L"gach monatóir roghnaithe.\r\n\r\nRÉAMHAMHARC AGUS RIALÚ\r\nÚsáid FlyingSolids.scr mar spárálaí "
    L"scáileáin Windows. Tá a shocruithe ar leith ó shocruithe an fheidhmchláir. Ceadaíonn an réamhamharc "
    L"lánscáileáin athruithe beo. Sábhálann OK agus cealaíonn Cealaigh nó Esc na hathruithe. Fág an "
    L"spárálaí lánscáileáin le heochair ar bith nó le gluaiseacht na luiche.\r\n\r\nRIACHTANAIS "
    L"CHÓRAIS\r\nTacaíonn Windows 7–11 leis na gnéithe uile. Ar Windows Vista SP2 ní mór nuashonruithe "
    L"KB971512 agus KB2117917. Teastaíonn tacaíocht Direct3D 11.",
    L"ANIMACIJA IR NUOSTATOS\r\nFlyingSolids rodo judančius, besisukančius ir susiduriančius erdvinius "
    L"kūnus. Pasirinkite erdvės stebėjimą arba skrydį erdve ir norimus kūnus. Kiekvienam monitoriui "
    L"atskirai galima nustatyti objektų bei kameros greitį 0–1600%, objektų dydį 50–200% ir 1–10 kiekvieno "
    L"kūno kopijų. Pagrindinė, užpildanti, aplinkos ir kontūrinė šviesa įjungiamos "
    L"nepriklausomai.\r\n\r\nMONITORIAI\r\nMonitorių sąraše pasirinkite vieną ar kelias eilutes. Ctrl+A "
    L"pasirenka visas, o Ctrl ir Shift leidžia keisti pasirinkimą. Animacijos valdikliai ir slankikliai "
    L"keičia tik pasirinktų monitorių nuostatas. Eilutės pasirinkimas nėra tas pats, kas animacijos "
    L"išvesties įjungimas jos žymimuoju langeliu. Pasirinkimas atskirai įsimenamas programai ir užsklandai. "
    L"Jei buvo pasirinkti visi monitoriai, į pasirinkimą įtraukiami ir naujai prijungti monitoriai. "
    L"Skirtingas pasirinktų monitorių reikšmes rodo neapibrėžta žymimųjų langelių būsena ir taškinis raštas "
    L"ant parinkčių mygtukų, slankiklių rankenėlių bei visų parinkčių įjungimo ir išjungimo mygtukų. "
    L"Slankiklių užrašuose vietoj bendros reikšmės rodomas brūkšnys. Pakeitus parinktį arba spustelėjus "
    L"slankiklį, ta reikšmė pritaikoma visiems pasirinktiems monitoriams.\r\n\r\nPERŽIŪRA IR "
    L"VALDYMAS\r\nNaudokite FlyingSolids.scr kaip Windows ekrano užsklandą. Jos nuostatos atskiros nuo "
    L"programos. Viso ekrano peržiūra leidžia jas keisti vykstant animacijai. OK išsaugo, Atšaukti arba Esc "
    L"atmeta pakeitimus. Užsklandą užbaikite klavišu arba pajudindami pelę.\r\n\r\nSISTEMOS "
    L"REIKALAVIMAI\r\nWindows 7–11 palaiko visas funkcijas. Windows Vista SP2 būtina įdiegti naujinimus "
    L"KB971512 ir KB2117917. Reikalingas Direct3D 11 palaikymas.",
    L"ANIMĀCIJA UN IESTATĪJUMI\r\nFlyingSolids rāda kustīgus, rotējošus un savstarpēji sadurošus telpiskus "
    L"ķermeņus. Izvēlieties telpas novērošanu vai lidojumu telpā un vajadzīgos ķermeņus. Katram monitoram "
    L"atsevišķi var iestatīt objektu un kameras ātrumu 0–1600%, objektu izmēru 50–200% un 1–10 katra "
    L"ķermeņa kopijas. Galveno, papildu, apkārtējo un kontūru gaismu var pārslēgt "
    L"neatkarīgi.\r\n\r\nMONITORI\r\nMonitoru sarakstā atlasiet vienu vai vairākas rindas. Ctrl+A atlasa "
    L"visas, bet Ctrl un Shift ļauj mainīt atlasi. Animācijas vadīklas un slīdņi maina tikai atlasīto "
    L"monitoru iestatījumus. Rindas atlasīšana nav tas pats, kas animācijas izvades ieslēgšana ar izvēles "
    L"rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un ekrānsaudzētājam. Ja bija atlasīti visi monitori, "
    L"atlasē iekļauj arī jaunpievienotos monitorus. Atšķirīgas vērtības atlasītajos monitoros norāda "
    L"nenoteikts izvēles rūtiņu stāvoklis un punktots raksts uz radiopogām, slīdņu rokturiem un visu "
    L"iespēju ieslēgšanas vai izslēgšanas pogām. Slīdņu etiķetēs kopīgas vērtības vietā redzama domuzīme. "
    L"Mainot iespēju vai noklikšķinot uz slīdņa, šī vērtība tiek piemērota visiem atlasītajiem "
    L"monitoriem.\r\n\r\nPRIEKŠSKATĪJUMS UN LIETOŠANA\r\nIzmantojiet FlyingSolids.scr kā Windows "
    L"ekrānsaudzētāju. Tā iestatījumi ir atsevišķi no lietotnes. Pilnekrāna priekšskatījums ļauj tos mainīt "
    L"animācijas darbības laikā. OK saglabā, Atcelt vai Esc atmet izmaiņas. Pilnekrāna ekrānsaudzētāju "
    L"aizveriet ar taustiņu vai peles kustību.\r\n\r\nSISTĒMAS PRASĪBAS\r\nWindows 7–11 atbalsta visas "
    L"funkcijas. Windows Vista SP2 jāinstalē atjauninājumi KB971512 un KB2117917. Nepieciešams Direct3D 11 "
    L"atbalsts.",
    L"ANIMÁCIÓ ÉS BEÁLLÍTÁSOK\r\nA FlyingSolids mozgó, forgó és ütköző térbeli testeket jelenít meg. "
    L"Válassza a tér megfigyelését vagy a térben repülést, és kapcsolja be a kívánt testeket. Monitoronként "
    L"állítható az objektumok és a kamera sebessége 0–1600%, az objektumok mérete 50–200%, valamint "
    L"testenként 1–10 példány. A főfény, derítőfény, környezeti fény és peremfény egymástól függetlenül "
    L"kapcsolható.\r\n\r\nMONITOROK\r\nJelöljön ki egy vagy több sort a monitorok listájában. A Ctrl+A "
    L"mindet kijelöli; a Ctrl és a Shift módosítja a kijelölést. Az animáció vezérlői és csúszkái csak a "
    L"kijelölt monitorok beállításait változtatják. A sor kijelölése és az animációs kimenet "
    L"jelölőnégyzetes engedélyezése külön művelet. A kijelölést az alkalmazás és a képernyőkímélő külön "
    L"megjegyzi. Ha korábban minden monitor ki volt jelölve, az újonnan csatlakoztatott monitorok is "
    L"bekerülnek a kijelölésbe. A kijelölt monitorok eltérő értékeit a jelölőnégyzetek határozatlan "
    L"állapota, valamint a választógombok, a csúszkafogantyúk és az összes beállítást be- vagy kikapcsoló "
    L"gombok pontozása jelzi. A csúszkák felirata közös érték helyett gondolatjelet mutat. Egy beállítás "
    L"módosítása vagy a csúszkára kattintás az adott értéket minden kijelölt monitorra "
    L"alkalmazza.\r\n\r\nELŐNÉZET ÉS KEZELÉS\r\nA FlyingSolids.scr Windows-képernyőkímélőként használható, "
    L"az alkalmazástól külön beállításokkal. A teljes képernyős előnézetben élőben módosíthatók a "
    L"beállítások. Az OK ment, a Mégse vagy Esc elveti a módosításokat. A teljes képernyős képernyőkímélő "
    L"billentyűvel vagy egérmozgással zárható be.\r\n\r\nRENDSZERKÖVETELMÉNYEK\r\nA Windows 7–11 minden "
    L"funkciót támogat. Windows Vista SP2 alatt telepíteni kell a KB971512 és KB2117917. Direct3D 11 "
    L"támogatás szükséges.",
    L"ANIMAZZJONI U SETTINGS\r\nFlyingSolids juri solidi tridimensjonali li jiċċaqalqu, iduru u jaħbtu ma’ "
    L"xulxin. Agħżel osservazzjoni tal-ispazju jew titjira fl-ispazju u attiva l-forom mixtieqa. Għal kull "
    L"moniter tista’ tissettja separatament il-veloċità tal-oġġetti u l-kamera minn 0–1600%, id-daqs minn "
    L"50–200% u 1–10 kopji ta’ kull solidu. Id-dawl ewlieni, id-dawl ta’ mili, id-dawl ambjentali u d-dawl "
    L"tal-kontorn jinxtegħlu separatament.\r\n\r\nSKRINS\r\nAgħżel ringiela waħda jew aktar fil-lista "
    L"tal-moniters. Ctrl+A jagħżilhom kollha; Ctrl u Shift ibiddlu l-għażla. Il-kontrolli u s-sliders "
    L"tal-animazzjoni jibdlu biss is-settings tal-moniters magħżula. L-għażla ta’ ringiela hija differenti "
    L"mill-attivazzjoni tal-output permezz tal-kaxxa tal-marka. L-għażla tinżamm separatament "
    L"għall-applikazzjoni u għall-iscreen saver. Jekk il-moniters kollha kienu magħżula, il-moniters ġodda "
    L"jiddaħħlu wkoll fl-għażla. Valuri differenti fuq il-moniters magħżula jintwerew bi stat indeterminat "
    L"tal-kaxxi tal-marka u b’disinn bit-tikek fuq il-buttuni tar-radju, il-manki tas-sliders u l-buttuni "
    L"li jattivaw jew jiddiżattivaw l-għażliet kollha. It-tikketti tas-sliders juru sing minflok valur "
    L"komuni. Meta tibdel għażla jew tikklikkja slider, dak il-valur jiġi applikat għall-moniters magħżula "
    L"kollha.\r\n\r\nPREVIŻJONI U KONTROLLI\r\nUża FlyingSolids.scr bħala screen saver ta’ Windows. "
    L"Is-settings tiegħu huma separati minn dawk tal-applikazzjoni. Il-previżjoni fuq skrin sħiħ "
    L"tippermetti bidliet waqt l-animazzjoni. OK isalva u Ikkanċella jew Esc jarmi l-bidliet. Oħroġ "
    L"mill-iscreen saver bi kwalunkwe tast jew billi ċċaqlaq il-maws.\r\n\r\nREKWIŻITI "
    L"TAS-SISTEMA\r\nWindows 7–11 jappoġġja l-funzjonijiet kollha. Fuq Windows Vista SP2 għandhom jiġu "
    L"installati l-aġġornamenti KB971512 u KB2117917. Huwa meħtieġ Direct3D 11.",
    L"ANIMATIE EN INSTELLINGEN\r\nFlyingSolids toont bewegende, draaiende en botsende driedimensionale "
    L"lichamen. Kies ruimte observeren of door de ruimte vliegen en schakel de gewenste lichamen in. Stel "
    L"per beeldscherm de object- en camerasnelheid in op 0–1600%, de objectgrootte op 50–200% en het aantal "
    L"kopieën op 1–10 per lichaam. Hoofdlicht, invullicht, omgevingslicht en randlicht zijn onafhankelijk "
    L"schakelbaar.\r\n\r\nBEELDSCHERMEN\r\nSelecteer één of meer beeldschermrijen in de lijst. Ctrl+A "
    L"selecteert alles; met Ctrl en Shift past u de selectie aan. Animatieknoppen en schuifregelaars "
    L"wijzigen alleen de instellingen van de geselecteerde beeldschermen. Een rij selecteren is iets anders "
    L"dan de animatie-uitvoer inschakelen met het selectievakje. De selectie wordt apart onthouden voor de "
    L"toepassing en de schermbeveiliging. Als alle beeldschermen waren geselecteerd, worden nieuw "
    L"aangesloten beeldschermen ook geselecteerd. Verschillende waarden op geselecteerde beeldschermen "
    L"worden aangegeven door selectievakjes in onbepaalde toestand en een stippelpatroon op keuzerondjes, "
    L"schuifknoppen en knoppen om alle opties in of uit te schakelen. De labels van schuifregelaars tonen "
    L"een streepje in plaats van een gemeenschappelijke waarde. Een optie wijzigen of op een schuifregelaar "
    L"klikken past die waarde toe op alle geselecteerde beeldschermen.\r\n\r\nVOORBEELD EN "
    L"BEDIENING\r\nGebruik FlyingSolids.scr als Windows-schermbeveiliging met eigen instellingen. Het "
    L"schermvullende voorbeeld laat live aanpassingen toe. OK slaat wijzigingen op; Annuleren of Esc "
    L"verwerpt ze. Sluit de schermvullende schermbeveiliging met een toets of een "
    L"muisbeweging.\r\n\r\nSYSTEEMVEREISTEN\r\nWindows 7–11 ondersteunt alle functies. Voor Windows Vista "
    L"SP2 moet u updates KB971512 en KB2117917. Direct3D 11-ondersteuning is vereist.",
    L"ANIMAȚIE ȘI SETĂRI\r\nFlyingSolids afișează corpuri tridimensionale care se deplasează, se rotesc și "
    L"se ciocnesc. Alegeți observarea spațiului sau zborul prin spațiu și activați corpurile dorite. Pentru "
    L"fiecare monitor puteți seta separat viteza obiectelor și a camerei între 0–1600%, dimensiunea între "
    L"50–200% și 1–10 copii ale fiecărui corp. Lumina principală, de umplere, ambiantă și de contur se "
    L"controlează independent.\r\n\r\nMONITOARE\r\nSelectați unul sau mai multe rânduri din lista "
    L"monitoarelor. Ctrl+A le selectează pe toate; Ctrl și Shift modifică selecția. Comenzile și glisoarele "
    L"animației schimbă numai setările monitoarelor selectate. Selectarea unui rând diferă de activarea "
    L"ieșirii prin caseta sa de selectare. Selecția este reținută separat pentru aplicație și economizor. "
    L"Dacă erau selectate toate monitoarele, sunt incluse și cele conectate ulterior. Valorile diferite de "
    L"pe monitoarele selectate sunt indicate prin starea nedeterminată a casetelor de selectare și un model "
    L"punctat pe butoanele radio, mânerele glisoarelor și butoanele de activare sau dezactivare a tuturor "
    L"opțiunilor. Etichetele glisoarelor afișează o liniuță în locul unei valori comune. Modificarea unei "
    L"opțiuni sau clicul pe un glisor aplică acea valoare tuturor monitoarelor "
    L"selectate.\r\n\r\nPREVIZUALIZARE ȘI COMENZI\r\nFolosiți FlyingSolids.scr drept economizor de ecran "
    L"Windows, cu setări separate de aplicație. Previzualizarea pe tot ecranul permite ajustări în timp "
    L"real. OK salvează modificările; Anulare sau Esc le anulează. Ieșiți din economizor apăsând o tastă "
    L"sau mișcând mouse-ul.\r\n\r\nCERINȚE DE SISTEM\r\nWindows 7–11 acceptă toate funcțiile. Pentru "
    L"Windows Vista SP2 trebuie instalate actualizările KB971512 și KB2117917. Este necesar Direct3D 11.",
    L"ΚΙΝΗΣΗ ΚΑΙ ΡΥΘΜΙΣΕΙΣ\r\nΤο FlyingSolids εμφανίζει τρισδιάστατα στερεά που κινούνται, περιστρέφονται "
    L"και συγκρούονται. Επιλέξτε παρατήρηση χώρου ή πτήση στον χώρο και ενεργοποιήστε τα επιθυμητά στερεά. "
    L"Ανά οθόνη ρυθμίζονται ανεξάρτητα η ταχύτητα αντικειμένων και κάμερας 0–1600%, το μέγεθος 50–200% και "
    L"1–10 αντίγραφα κάθε στερεού. Ο κύριος φωτισμός, ο φωτισμός πλήρωσης, ο περιβάλλων φωτισμός και ο "
    L"φωτισμός περιγράμματος ελέγχονται ανεξάρτητα.\r\n\r\nΟΘΟΝΕΣ\r\nΕπιλέξτε μία ή περισσότερες γραμμές "
    L"στη λίστα οθονών. Το Ctrl+A επιλέγει όλες, ενώ τα Ctrl και Shift αλλάζουν την επιλογή. Τα χειριστήρια "
    L"και τα ρυθμιστικά της κίνησης αλλάζουν μόνο τις ρυθμίσεις των επιλεγμένων οθονών. Η επιλογή γραμμής "
    L"διαφέρει από την ενεργοποίηση εξόδου μέσω του πλαισίου ελέγχου της. Η επιλογή αποθηκεύεται χωριστά "
    L"για την εφαρμογή και την προφύλαξη. Αν είχαν επιλεγεί όλες οι οθόνες, περιλαμβάνονται και όσες "
    L"συνδεθούν αργότερα. Οι διαφορετικές τιμές στις επιλεγμένες οθόνες υποδεικνύονται με απροσδιόριστη "
    L"κατάσταση των πλαισίων ελέγχου και μοτίβο κουκκίδων στα κουμπιά επιλογής, στις λαβές των ρυθμιστικών "
    L"και στα κουμπιά ενεργοποίησης ή απενεργοποίησης όλων των επιλογών. Οι ετικέτες των ρυθμιστικών "
    L"δείχνουν παύλα αντί για κοινή τιμή. Η αλλαγή επιλογής ή το κλικ σε ρυθμιστικό εφαρμόζει την τιμή σε "
    L"όλες τις επιλεγμένες οθόνες.\r\n\r\nΠΡΟΕΠΙΣΚΟΠΗΣΗ ΚΑΙ ΧΕΙΡΙΣΜΟΣ\r\nΧρησιμοποιήστε το FlyingSolids.scr "
    L"ως προφύλαξη οθόνης Windows με χωριστές ρυθμίσεις από την εφαρμογή. Η προεπισκόπηση πλήρους οθόνης "
    L"επιτρέπει ζωντανές αλλαγές. Το OK αποθηκεύει και το Άκυρο ή Esc απορρίπτει τις αλλαγές. Τερματίστε "
    L"την προφύλαξη με πλήκτρο ή κίνηση του ποντικιού.\r\n\r\nΑΠΑΙΤΗΣΕΙΣ ΣΥΣΤΗΜΑΤΟΣ\r\nΤα Windows 7–11 "
    L"υποστηρίζουν όλες τις λειτουργίες. Στα Windows Vista SP2 πρέπει να εγκατασταθούν οι ενημερώσεις "
    L"KB971512 και KB2117917. Απαιτείται υποστήριξη Direct3D 11.",
    L"ANIMACIJA I POSTAVKE\r\nFlyingSolids prikazuje prostorna tijela koja se kreću, okreću i sudaraju. "
    L"Odaberite posmatranje prostora ili let kroz prostor te željena tijela. Za svaki monitor zasebno se "
    L"podešavaju brzina objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija svakog tijela. Glavno, "
    L"dopunsko, ambijentalno i konturno svjetlo uključuju se nezavisno.\r\n\r\nMONITORI\r\nOdaberite jedan "
    L"ili više redova u listi monitora. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i "
    L"klizači animacije mijenjaju samo postavke odabranih monitora. Odabir reda nije isto što i "
    L"uključivanje izlaza njegovom kućicom. Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su "
    L"prethodno bili odabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti "
    L"na odabranim monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima "
    L"izbora, ručkama klizača i dugmadima za uključivanje ili isključivanje svih opcija. Oznake klizača "
    L"prikazuju crticu umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu "
    L"vrijednost na sve odabrane monitore.\r\n\r\nPREGLED I UPRAVLJANJE\r\nKoristite FlyingSolids.scr kao "
    L"Windows čuvar ekrana s odvojenim postavkama. Pregled preko cijelog ekrana omogućava izmjene uživo. OK "
    L"čuva, a Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili pomjeranjem "
    L"miša.\r\n\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate "
    L"instalirati ažuriranja KB971512 i KB2117917. Potreban je Direct3D 11.",
    L"ANIMACIJA I POSTAVKE\r\nFlyingSolids prikazuje prostorna tijela koja se kreću, okreću i sudaraju. "
    L"Odaberite promatranje prostora ili let kroz prostor te željena tijela. Za svaki zaslon zasebno se "
    L"podešavaju brzina objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija svakog tijela. Glavno, "
    L"dopunsko, ambijentalno i konturno svjetlo uključuju se neovisno.\r\n\r\nMONITORI\r\nOdaberite jedan "
    L"ili više redaka na popisu zaslona. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i "
    L"klizači animacije mijenjaju samo postavke odabranih zaslona. Odabir retka nije isto što i "
    L"uključivanje izlaza njegovim potvrdnim okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar "
    L"zaslona. Ako su prethodno bili odabrani svi zasloni, uključuju se i novopriključeni zasloni. "
    L"Različite vrijednosti na odabranim zaslonima prikazuju se neodređenim stanjem potvrdnih okvira i "
    L"točkastim uzorkom na izbornim gumbima, ručkama klizača i gumbima za uključivanje ili isključivanje "
    L"svih mogućnosti. Oznake klizača prikazuju crticu umjesto zajedničke vrijednosti. Promjena mogućnosti "
    L"ili klik na klizač primjenjuje tu vrijednost na sve odabrane zaslone.\r\n\r\nPRETPREGLED I "
    L"UPRAVLJANJE\r\nKoristite FlyingSolids.scr kao Windows čuvar zaslona s odvojenim postavkama. "
    L"Pretpregled preko cijelog zaslona omogućuje izmjene uživo. OK sprema, a Odustani ili Esc odbacuje "
    L"izmjene. Iz čuvara izađite pritiskom tipke ili pomicanjem miša.\r\n\r\nZAHTJEVI SUSTAVA\r\nWindows "
    L"7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917. "
    L"Potreban je Direct3D 11.",
    L"ANIMACIJA IN NASTAVITVE\r\nFlyingSolids prikazuje prostorska telesa, ki se premikajo, vrtijo in "
    L"trkajo. Izberite opazovanje prostora ali let skozi prostor in želena telesa. Za vsak zaslon so ločeno "
    L"nastavljivi hitrost predmetov in kamere 0–1600%, velikost 50–200% ter 1–10 kopij vsakega telesa. "
    L"Glavna, dopolnilna, okoljska in obrobna svetloba se vklapljajo neodvisno.\r\n\r\nZASLONI\r\nNa "
    L"seznamu zaslonov izberite eno ali več vrstic. Ctrl+A izbere vse, Ctrl in Shift pa spreminjata izbor. "
    L"Kontrolniki in drsniki animacije spreminjajo samo nastavitve izbranih zaslonov. Izbira vrstice ni "
    L"isto kot vklop izhoda z njenim potrditvenim poljem. Izbor se ločeno shrani za program in "
    L"ohranjevalnik. Če so bili izbrani vsi zasloni, so vključeni tudi na novo priključeni zasloni. "
    L"Različne vrednosti na izbranih zaslonih označujeta nedoločeno stanje potrditvenih polj in pikčast "
    L"vzorec na izbirnih gumbih, ročicah drsnikov ter gumbih za vklop ali izklop vseh možnosti. Oznake "
    L"drsnikov namesto skupne vrednosti prikazujejo pomišljaj. Sprememba možnosti ali klik na drsnik "
    L"uveljavi to vrednost na vseh izbranih zaslonih.\r\n\r\nPREDOGLED IN UPRAVLJANJE\r\nUporabite "
    L"FlyingSolids.scr kot ohranjevalnik zaslona Windows z ločenimi nastavitvami. Celozaslonski predogled "
    L"omogoča sprotne spremembe. OK jih shrani, Prekliči ali Esc jih zavrže. Ohranjevalnik zapustite s "
    L"tipko ali premikom miške.\r\n\r\nSISTEMSKE ZAHTEVE\r\nWindows 7–11 podpira vse funkcije. Za Windows "
    L"Vista SP2 morate namestiti posodobitvi KB971512 in KB2117917. Potrebna je podpora Direct3D 11.",
    L"ANIMACIJA I PODEŠAVANJA\r\nFlyingSolids prikazuje prostorna tijela koja se kreću, okreću i sudaraju. "
    L"Izaberite posmatranje prostora ili let kroz prostor te željena tijela. Za svaki monitor zasebno se "
    L"podešavaju brzina objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija svakog tijela. Glavno, "
    L"dopunsko, ambijentalno i konturno svjetlo uključuju se nezavisno.\r\n\r\nMONITORI\r\nIzaberite jedan "
    L"ili više redova u listi monitora. Ctrl+A bira sve; Ctrl i Shift mijenjaju izbor. Kontrole i klizači "
    L"animacije mijenjaju samo podešavanja izabranih monitora. Izbor reda nije isto što i uključivanje "
    L"izlaza njegovom kućicom. Izbor se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili "
    L"izabrani svi monitori, uključuju se i novopriključeni monitori. Različite vrijednosti na izabranim "
    L"monitorima prikazuju se neodređenim stanjem kućica i tačkastim uzorkom na dugmadima izbora, ručkama "
    L"klizača i dugmadima za uključivanje ili isključivanje svih opcija. Oznake klizača prikazuju crticu "
    L"umjesto zajedničke vrijednosti. Promjena opcije ili klik na klizač primjenjuje tu vrijednost na sve "
    L"izabrane monitore.\r\n\r\nPREGLED I UPRAVLJANJE\r\nKoristite FlyingSolids.scr kao Windows čuvar "
    L"ekrana s odvojenim podešavanjima. Pregled preko cijelog ekrana omogućava izmjene uživo. OK čuva, a "
    L"Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tastera ili pomjeranjem "
    L"miša.\r\n\r\nSISTEMSKI ZAHTJEVI\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate "
    L"instalirati ažuriranja KB971512 i KB2117917. Potreban je Direct3D 11.",
    L"АНІМАЦЫЯ І НАЛАДЫ\r\nFlyingSolids паказвае аб’ёмныя целы, якія рухаюцца, круцяцца і сутыкаюцца. "
    L"Выберыце назіранне за прасторай або палёт праз яе і патрэбныя целы. Для кожнага манітора асобна "
    L"задаюцца хуткасці аб’ектаў і камеры 0–1600%, памер 50–200% і 1–10 копій кожнага цела. Асноўнае, "
    L"запаўняльнае, фонавае і контурнае святло ўключаюцца незалежна.\r\n\r\nМАНІТОРЫ\r\nВыберыце адзін або "
    L"некалькі радкоў у спісе манітораў. Ctrl+A выбірае ўсе; Ctrl і Shift змяняюць выбар. Элементы "
    L"кіравання і паўзункі анімацыі змяняюць толькі налады выбраных манітораў. Выбар радка і ўключэнне "
    L"вываду яго сцяжком — розныя дзеянні. Выбар асобна захоўваецца для праграмы і застаўкі. Калі раней "
    L"былі выбраны ўсе маніторы, да выбару далучаюцца і новыя маніторы. Розныя значэнні на выбраных "
    L"маніторах пазначаюцца нявызначаным станам сцяжкоў і кропкавым узорам на пераключальніках, ручках "
    L"паўзункоў і кнопках уключэння або выключэння ўсіх параметраў. У подпісах паўзункоў замест агульнага "
    L"значэння паказваецца працяжнік. Змена параметра або націск на паўзунок ужывае гэта значэнне да ўсіх "
    L"выбраных манітораў.\r\n\r\nПЕРАДПРАГЛЯД І КІРАВАННЕ\r\nВыкарыстоўвайце FlyingSolids.scr як застаўку "
    L"Windows з асобнымі наладамі. Поўнаэкранны перадпрагляд дазваляе змяняць іх падчас анімацыі. OK "
    L"захоўвае змены, Скасаваць або Esc адхіляе іх. Для выхаду з застаўкі націсніце клавішу або паварушыце "
    L"мышшу.\r\n\r\nСІСТЭМНЫЯ ПАТРАБАВАННІ\r\nWindows 7–11 падтрымлівае ўсе функцыі. Для Windows Vista SP2 "
    L"неабходна ўсталяваць абнаўленні KB971512 і KB2117917. Патрэбна падтрымка Direct3D 11.",
    L"АНИМАЦИЯ И НАСТРОЙКИ\r\nFlyingSolids показва обемни тела, които се движат, въртят и сблъскват. "
    L"Изберете наблюдение на пространството или полет през него и желаните тела. За всеки монитор отделно "
    L"се задават скорост на обектите и камерата 0–1600%, размер 50–200% и 1–10 копия на всяко тяло. "
    L"Основната, запълващата, околната и контурната светлина се включват "
    L"независимо.\r\n\r\nМОНИТОРИ\r\nИзберете един или повече редове в списъка с монитори. Ctrl+A избира "
    L"всички; Ctrl и Shift променят избора. Контролите и плъзгачите на анимацията променят само настройките "
    L"на избраните монитори. Избирането на ред и включването на изхода чрез отметката му са различни "
    L"действия. Изборът се запомня отделно за приложението и скрийнсейвъра. Ако са били избрани всички "
    L"монитори, включват се и новосвързаните. Различните стойности на избраните монитори се показват с "
    L"неопределено състояние на отметките и точков шаблон върху радиобутоните, дръжките на плъзгачите и "
    L"бутоните за включване или изключване на всички опции. Надписите на плъзгачите показват тире вместо "
    L"обща стойност. Промяна на опция или щракване върху плъзгач прилага стойността към всички избрани "
    L"монитори.\r\n\r\nПРЕГЛЕД И УПРАВЛЕНИЕ\r\nИзползвайте FlyingSolids.scr като скрийнсейвър на Windows с "
    L"отделни настройки. Прегледът на цял екран позволява промени в реално време. OK запазва промените; "
    L"Отказ или Esc ги отхвърля. Излезте от скрийнсейвъра с клавиш или движение на мишката.\r\n\r\nСИСТЕМНИ "
    L"ИЗИСКВАНИЯ\r\nWindows 7–11 поддържа всички функции. За Windows Vista SP2 трябва да се инсталират "
    L"актуализациите KB971512 и KB2117917. Изисква се поддръжка на Direct3D 11.",
    L"АНИМАЦИЈА И ПОСТАВКИ\r\nFlyingSolids прикажува просторни тела што се движат, вртат и судираат. "
    L"Изберете набљудување на просторот или лет низ него и саканите тела. За секој монитор одделно се "
    L"поставуваат брзината на објектите и камерата 0–1600%, големината 50–200% и 1–10 копии од секое тело. "
    L"Главното, дополнителното, амбиенталното и контурното светло се вклучуваат "
    L"независно.\r\n\r\nМОНИТОРИ\r\nИзберете еден или повеќе редови во списокот на монитори. Ctrl+A ги "
    L"избира сите; Ctrl и Shift го менуваат изборот. Контролите и лизгачите на анимацијата ги менуваат само "
    L"поставките на избраните монитори. Избирањето ред и вклучувањето на излезот преку неговото поле се "
    L"различни дејства. Изборот се памети одделно за апликацијата и чуварот. Ако биле избрани сите "
    L"монитори, се вклучуваат и новоповрзаните монитори. Различните вредности на избраните монитори се "
    L"прикажуваат со неопределена состојба на полињата за избор и точкест образец на радио-копчињата, "
    L"рачките на лизгачите и копчињата за вклучување или исклучување на сите опции. Ознаките на лизгачите "
    L"прикажуваат црта наместо заедничка вредност. Менувањето опција или кликнувањето на лизгач ја "
    L"применува вредноста на сите избрани монитори.\r\n\r\nПРЕГЛЕД И УПРАВУВАЊЕ\r\nКористете "
    L"FlyingSolids.scr како Windows чувар на екранот со одделни поставки. Прегледот на цел екран овозможува "
    L"измени во живо. OK ги зачувува, а Откажи или Esc ги отфрла измените. Излезете од чуварот со копче или "
    L"движење на глувчето.\r\n\r\nСИСТЕМСКИ БАРАЊА\r\nWindows 7–11 ги поддржува сите функции. За Windows "
    L"Vista SP2 мора да се инсталираат ажурирањата KB971512 и KB2117917. Потребна е поддршка за Direct3D 11.",
    L"АНИМАЦИЈА И ПОДЕШАВАЊА\r\nFlyingSolids приказује просторна тела која се крећу, окрећу и сударају. "
    L"Изаберите посматрање простора или лет кроз простор и жељена тела. За сваки монитор посебно се "
    L"подешавају брзина објеката и камере 0–1600%, величина 50–200% и 1–10 копија сваког тела. Главно, "
    L"допунско, амбијентално и контурно светло укључују се независно.\r\n\r\nМОНИТОРИ\r\nИзаберите један "
    L"или више редова у листи монитора. Ctrl+A бира све; Ctrl и Shift мењају избор. Контроле и клизачи "
    L"анимације мењају само подешавања изабраних монитора. Избор реда није исто што и укључивање излаза "
    L"његовим пољем за потврду. Избор се памти одвојено за апликацију и чувар екрана. Ако су претходно били "
    L"изабрани сви монитори, укључују се и новоприкључени монитори. Различите вредности на изабраним "
    L"мониторима приказују се неодређеним стањем поља за потврду и тачкастим узорком на дугмадима избора, "
    L"ручкама клизача и дугмадима за укључивање или искључивање свих опција. Ознаке клизача приказују црту "
    L"уместо заједничке вредности. Промена опције или клик на клизач примењује ту вредност на све изабране "
    L"мониторе.\r\n\r\nПРЕГЛЕД И УПРАВЉАЊЕ\r\nКористите FlyingSolids.scr као Windows чувар екрана са "
    L"одвојеним подешавањима. Преглед преко целог екрана омогућава измене уживо. OK чува, а Откажи или Esc "
    L"одбацује измене. Из чувара изађите притиском тастера или померањем миша.\r\n\r\nСИСТЕМСКИ "
    L"ЗАХТЕВИ\r\nWindows 7–11 подржава све функције. За Windows Vista SP2 морате инсталирати ажурирања "
    L"KB971512 и KB2117917. Потребан је Direct3D 11.",
    L"АНІМАЦІЯ ТА НАЛАШТУВАННЯ\r\nFlyingSolids показує об’ємні тіла, які рухаються, обертаються й "
    L"стикаються. Виберіть спостереження за простором або політ крізь нього та потрібні тіла. Для кожного "
    L"монітора окремо задаються швидкості об’єктів і камери 0–1600%, розмір 50–200% та 1–10 копій кожного "
    L"тіла. Основне, заповнювальне, фонове й контурне світло вмикаються "
    L"незалежно.\r\n\r\nМОНІТОРИ\r\nВиберіть один або кілька рядків у списку моніторів. Ctrl+A вибирає всі; "
    L"Ctrl і Shift змінюють вибір. Елементи керування й повзунки анімації змінюють лише налаштування "
    L"вибраних моніторів. Вибір рядка та ввімкнення виведення його прапорцем — різні дії. Вибір "
    L"зберігається окремо для програми й заставки. Якщо раніше були вибрані всі монітори, до вибору "
    L"долучаються й новопідключені. Різні значення на вибраних моніторах позначаються невизначеним станом "
    L"прапорців і крапковим візерунком на перемикачах, ручках повзунків і кнопках увімкнення або вимкнення "
    L"всіх параметрів. Підписи повзунків показують тире замість спільного значення. Зміна параметра або "
    L"натискання на повзунок застосовує це значення до всіх вибраних моніторів.\r\n\r\nПОПЕРЕДНІЙ ПЕРЕГЛЯД "
    L"І КЕРУВАННЯ\r\nВикористовуйте FlyingSolids.scr як заставку Windows з окремими налаштуваннями. "
    L"Повноекранний попередній перегляд дозволяє змінювати їх під час анімації. OK зберігає зміни, "
    L"Скасувати або Esc відхиляє їх. Для виходу із заставки натисніть клавішу або порухайте "
    L"мишею.\r\n\r\nСИСТЕМНІ ВИМОГИ\r\nWindows 7–11 підтримує всі функції. Для Windows Vista SP2 потрібно "
    L"встановити оновлення KB971512 і KB2117917. Потрібна підтримка Direct3D 11.",
    L"АНИМАЦИЯ И НАСТРОЙКИ\r\nFlyingSolids показывает объёмные тела, которые движутся, вращаются и "
    L"сталкиваются. Выберите наблюдение за пространством или полёт сквозь него и нужные тела. Для каждого "
    L"монитора отдельно задаются скорости объектов и камеры 0–1600%, размер 50–200% и 1–10 копий каждого "
    L"тела. Основной, заполняющий, фоновый и контурный свет включаются "
    L"независимо.\r\n\r\nМОНИТОРЫ\r\nВыберите одну или несколько строк в списке мониторов. Ctrl+A выбирает "
    L"все; Ctrl и Shift изменяют выбор. Элементы управления и ползунки анимации изменяют только настройки "
    L"выбранных мониторов. Выбор строки и включение вывода её флажком — разные действия. Выбор сохраняется "
    L"отдельно для приложения и заставки. Если раньше были выбраны все мониторы, в выбор включаются и вновь "
    L"подключённые. Разные значения на выбранных мониторах обозначаются неопределённым состоянием флажков и "
    L"точечным узором на переключателях, ручках ползунков и кнопках включения или выключения всех "
    L"параметров. Подписи ползунков показывают тире вместо общего значения. Изменение параметра или нажатие "
    L"на ползунок применяет это значение ко всем выбранным мониторам.\r\n\r\nПРЕДПРОСМОТР И "
    L"УПРАВЛЕНИЕ\r\nИспользуйте FlyingSolids.scr как заставку Windows с отдельными настройками. "
    L"Полноэкранный предпросмотр позволяет изменять их во время анимации. OK сохраняет изменения, Отмена "
    L"или Esc отклоняет их. Для выхода из заставки нажмите клавишу или подвигайте мышью.\r\n\r\nСИСТЕМНЫЕ "
    L"ТРЕБОВАНИЯ\r\nWindows 7–11 поддерживает все функции. Для Windows Vista SP2 необходимо установить "
    L"обновления KB971512 и KB2117917. Нужна поддержка Direct3D 11."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> ABOUT_DESCRIPTION_TEXTS = {
    L"Hardwarově akcelerovaná animace plných prostorových objektů.",
    L"Hardware-accelerated animation of solid 3D objects.",
    L"Hardware-accelerated animation of solid 3D objects.",
    L"Hardware-accelerated animation of solid 3D objects.",
    L"Hardwarebeschleunigte Animation dreidimensionaler Volumenkörper.",
    L"Animation accélérée par le matériel d’objets 3D pleins.",
    L"Animación acelerada por hardware de objetos 3D sólidos.",
    L"Animazione con accelerazione hardware di oggetti 3D solidi.",
    L"Animação acelerada por hardware de objetos 3D sólidos.",
    L"Sprzętowo przyspieszana animacja pełnych obiektów 3D.",
    L"Hardvérovo akcelerovaná animácia plných 3D objektov.",
    L"Hardwareaccelereret animation af solide 3D-objekter.",
    L"Laitteistokiihdytetty kiinteiden 3D-kohteiden animaatio.",
    L"Vélbúnaðarhröðuð hreyfimynd heilla þrívíddarhluta.",
    L"Maskinvareakselerert animasjon av solide 3D-objekter.",
    L"Maskinvaruaccelererad animering av solida 3D-objekt.",
    L"Katı 3B nesnelerin donanım hızlandırmalı animasyonu.",
    L"Riistvarakiirendusega ruumiliste kehade animatsioon.",
    L"Beochan réad soladach 3T le luasghéarú crua-earraí.",
    L"Aparatine įranga spartinama erdvinių kūnų animacija.",
    L"Aparatūras paātrināta telpisku ķermeņu animācija.",
    L"Térbeli testek hardveresen gyorsított animációja.",
    L"Animazzjoni ta’ oġġetti solidi 3D aċċellerata bil-ħardwer.",
    L"Hardwareversnelde animatie van massieve 3D-objecten.",
    L"Animație de corpuri tridimensionale accelerată hardware.",
    L"Κίνηση τρισδιάστατων στερεών με επιτάχυνση υλικού.",
    L"Hardverski ubrzana animacija prostornih tijela.",
    L"Hardverski ubrzana animacija prostornih tijela.",
    L"Strojno pospešena animacija prostorskih teles.",
    L"Hardverski ubrzana animacija prostornih tijela.",
    L"Апаратна паскораная анімацыя аб’ёмных целаў.",
    L"Хардуерно ускорена анимация на обемни тела.",
    L"Хардверски забрзана анимација на просторни тела.",
    L"Хардверски убрзана анимација просторних тела.",
    L"Апаратно прискорена анімація об’ємних тіл.",
    L"Аппаратно ускоренная анимация объёмных тел."
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
    return PREVENT_SCREEN_SAVER_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
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

/// Returns the localized About website tooltip.
const wchar_t* AboutVisitTooltipText(AppLanguage language) {
    return ABOUT_VISIT_TOOLTIP_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}
