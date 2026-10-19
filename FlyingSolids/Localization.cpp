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
    L"V seznamu označte jeden nebo více monitorů. Režim kamery, výběr těles, světla, rychlosti, velikost a "
    L"počet kopií se nastavují jen pro označené monitory a každý monitor si pamatuje vlastní nastavení. "
    L"FlyingSolids zobrazuje osvětlená plná prostorová tělesa. Jezdci nastavují rychlost objektů a kamery v "
    L"rozsahu 0–1600 %, jednu až deset kopií každého tělesa a velikost 50–200 %. Vyberte Pozorování "
    L"prostoru nebo přímý Průlet prostorem a zaškrtněte požadované druhy těles. Zatržítka Hlavní světlo, "
    L"Doplňkové světlo, Základní jas a Přisvětlení obrysů pod jezdci nezávisle ovládají osvětlení celé "
    L"scény. Základní jas přisvětluje povrch těles, přisvětlení obrysů zvýrazňuje jejich okraje. Nastavení "
    L"osvětlení se ukládá zvlášť pro aplikaci a spořič obrazovky.\r\n\r\nOznačení řádků určuje, které "
    L"monitory právě nastavujete; není totožné se zatržítky zapínajícími animační výstupy. Ctrl+A označí "
    L"všechny monitory, Ctrl a Shift umožňují upravit označení. Všechny animační volby a jezdce platí pro "
    L"označené monitory. Označení se pamatuje zvlášť pro EXE a SCR. Pokud byly označené všechny monitory, "
    L"označí se i nově připojené.\r\n\r\nV seznamu lze označit více monitorů; dvojklikem na řádek monitor "
    L"zapnete nebo vypnete a lze zrušit i výběr všech monitorů. Každý monitor používá nezávislou scénu. "
    L"Snímek ukládá PNG, tlačítko záznamu spouští a ukončuje MP4. Pozastavení zastaví animaci. Aplikace "
    L"také instaluje nebo odinstaluje zabalený spořič. Nastavení se ukládá průběžně. Aplikace běží pouze v "
    L"jedné instanci. Další spuštění obnoví minimalizované ovládací okno a přenese do popředí. Mezi "
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
    L"Select one or more displays in the list. Camera mode, object selection, lighting, speeds, size and "
    L"copy count apply only to the selected displays, and each display remembers its own settings. "
    L"FlyingSolids displays illuminated solid 3D objects. The sliders set object and camera speed from "
    L"0–1600%, one to ten copies of each object, and size from 50–200%. Choose Space observation or the "
    L"straight Fly through space mode and enable the required object types. The Main light, Fill light, "
    L"Ambient light, and Rim light checkboxes below the sliders independently control lighting for the "
    L"whole scene. Ambient light provides base illumination of object surfaces; rim light highlights their "
    L"edges. Lighting settings are stored separately for the application and screen saver.\r\n\r\nRow "
    L"selection determines which displays you are editing; it is separate from the checkboxes that enable "
    L"animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation "
    L"options and sliders apply to the selected displays. The selection is remembered separately for EXE "
    L"and SCR. If all displays were selected, newly connected displays join the selection.\r\n\r\nSelect "
    L"several displays in the list; double-click a row to toggle it, or clear the selection for all "
    L"displays. Every display uses an independent scene. Snapshot saves a PNG and the recording button "
    L"starts or stops an MP4. Pause stops the animation. The application also installs or uninstalls its "
    L"embedded screen saver. Settings are saved continuously. Only one instance of the application runs at "
    L"a time. Launching it again restores its minimized control window and brings it to the foreground. Use "
    L"Tab and Shift+Tab to move between controls; use Alt and the underlined letter to activate a command. "
    L"Esc closes the active Help or About window; in the control window, it exits the application. Prevent "
    L"screen saver during animation blocks the Windows screen saver only while the animation is actually "
    L"visible and not paused.\r\n\r\nSnapshots and recordings capture the first active animation display, "
    L"not a combined image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the "
    L"fallback if those folders do not exist. The Recording settings button selects Viewport or TV. "
    L"Viewport preserves the animation display’s dimensions and refresh rate, up to 60 frames per second. "
    L"TV offers 1920 × 1080, 1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 (60000/1001) or "
    L"29.97 (30000/1001) frames per second. The image keeps its aspect ratio; TV uses progressive BT.709 "
    L"limited-range 4:2:0 video. Resolution and frame rate are available only in TV mode. The Recording "
    L"settings window can be minimized and does not block the other application windows. OK saves choices "
    L"for the next MP4 recording; Cancel or Esc discards unconfirmed changes. The recorded display cannot "
    L"be detached during recording; changes to other displays do not stop the recording. Closing the "
    L"application while recording requires confirmation because it also stops the recording.\r\n\r\nWindows "
    L"7 through Windows 11 support all features, including PNG snapshots and MP4 recording. To run the "
    L"application on Windows Vista SP2, you must install updates KB971512 and KB2117917. MP4 recording does "
    L"not work on Vista in the current version.",
    L"Select one or more displays in the list. Camera mode, object selection, lighting, speeds, size and "
    L"copy count apply only to the selected displays, and each display remembers its own settings. "
    L"FlyingSolids displays illuminated solid 3D objects. The sliders set object and camera speed from "
    L"0–1600%, one to ten copies and size from 50–200%. Choose Space observation or the straight Fly "
    L"through space mode and enable the required objects. The Main light, Fill light, Ambient light, and "
    L"Rim light checkboxes below the sliders independently control lighting for the whole scene. Ambient "
    L"light provides base illumination of object surfaces; rim light highlights their edges. Lighting "
    L"settings are stored separately for the application and screen saver.\r\n\r\nRow selection determines "
    L"which displays you are editing; it is separate from the checkboxes that enable animation outputs. "
    L"Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation options and sliders "
    L"apply to the selected displays. The selection is remembered separately for EXE and SCR. If all "
    L"displays were selected, newly connected displays join the selection.\r\n\r\nSelect several displays; "
    L"double-click a row to toggle it, or clear the selection for all displays. Each display uses an "
    L"independent scene. Snapshot saves PNG and the recording button starts or stops MP4. Pause stops the "
    L"animation. The application also installs or uninstalls its embedded screen saver. Settings are saved "
    L"continuously. Only one instance of the application runs at a time. Launching it again restores its "
    L"minimised control window and brings it to the foreground. Use Tab and Shift+Tab to move between "
    L"controls; use Alt and the underlined letter to activate a command. Esc closes the active Help or "
    L"About window; in the control window, it exits the application. Prevent screen saver during animation "
    L"blocks the Windows screen saver only while the animation is actually visible and not "
    L"paused.\r\n\r\nSnapshots and recordings capture the first active animation display, not a combined "
    L"image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if those "
    L"folders do not exist. The Recording settings button selects Viewport or TV. Viewport preserves the "
    L"animation display’s dimensions and refresh rate, up to 60 frames per second. TV offers 1920 × 1080, "
    L"1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 (60000/1001) or 29.97 (30000/1001) "
    L"frames per second. The image keeps its aspect ratio; TV uses progressive BT.709 limited-range 4:2:0 "
    L"video. Resolution and frame rate are available only in TV mode. The Recording settings window can be "
    L"minimised and does not block the other application windows. OK saves choices for the next MP4 "
    L"recording; Cancel or Esc discards unconfirmed changes. The recorded display cannot be detached during "
    L"recording; changes to other displays do not stop the recording. Closing the application while "
    L"recording requires confirmation because it also stops the recording.\r\n\r\nWindows 7 through Windows "
    L"11 support all features, including PNG snapshots and MP4 recording. To run the application on Windows "
    L"Vista SP2, you must install updates KB971512 and KB2117917. MP4 recording does not work on Vista in "
    L"the current version.",
    L"Select one or more displays in the list. Camera mode, object selection, lighting, speeds, size and "
    L"copy count apply only to the selected displays, and each display remembers its own settings. "
    L"FlyingSolids displays illuminated solid 3D objects. The sliders set object and camera speed from "
    L"0–1600%, one to ten copies and size from 50–200%. Choose Space observation or the straight Fly "
    L"through space mode and enable the required objects. The Main light, Fill light, Ambient light, and "
    L"Rim light checkboxes below the sliders independently control lighting for the whole scene. Ambient "
    L"light provides base illumination of object surfaces; rim light highlights their edges. Lighting "
    L"settings are stored separately for the application and screen saver.\r\n\r\nRow selection determines "
    L"which displays you are editing; it is separate from the checkboxes that enable animation outputs. "
    L"Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation options and sliders "
    L"apply to the selected displays. The selection is remembered separately for EXE and SCR. If all "
    L"displays were selected, newly connected displays join the selection.\r\n\r\nSelect several displays; "
    L"double-click a row to toggle it, or clear the selection for all displays. Each display uses an "
    L"independent scene. Snapshot saves PNG and the recording button starts or stops MP4. Pause stops the "
    L"animation. The application also installs or uninstalls its embedded screen saver. Settings are saved "
    L"continuously. Only one instance of the application runs at a time. Launching it again restores its "
    L"minimised control window and brings it to the foreground. Use Tab and Shift+Tab to move between "
    L"controls; use Alt and the underlined letter to activate a command. Esc closes the active Help or "
    L"About window; in the control window, it exits the application. Prevent screen saver during animation "
    L"blocks the Windows screen saver only while the animation is actually visible and not "
    L"paused.\r\n\r\nSnapshots and recordings capture the first active animation display, not a combined "
    L"image of all displays. PNG uses Pictures and MP4 uses Videos, with Documents as the fallback if those "
    L"folders do not exist. The Recording settings button selects Viewport or TV. Viewport preserves the "
    L"animation display’s dimensions and refresh rate, up to 60 frames per second. TV offers 1920 × 1080, "
    L"1440 × 1080 or 1280 × 720 output in 16:9, with 50, 25, 59.94 (60000/1001) or 29.97 (30000/1001) "
    L"frames per second. The image keeps its aspect ratio; TV uses progressive BT.709 limited-range 4:2:0 "
    L"video. Resolution and frame rate are available only in TV mode. The Recording settings window can be "
    L"minimised and does not block the other application windows. OK saves choices for the next MP4 "
    L"recording; Cancel or Esc discards unconfirmed changes. The recorded display cannot be detached during "
    L"recording; changes to other displays do not stop the recording. Closing the application while "
    L"recording requires confirmation because it also stops the recording.\r\n\r\nWindows 7 through Windows "
    L"11 support all features, including PNG snapshots and MP4 recording. To run the application on Windows "
    L"Vista SP2, you must install updates KB971512 and KB2117917. MP4 recording does not work on Vista in "
    L"the current version.",
    L"Markieren Sie einen oder mehrere Monitore in der Liste. Kameramodus, Körperauswahl, Beleuchtung, "
    L"Geschwindigkeiten, Größe und Anzahl der Exemplare gelten nur für die markierten Monitore. Jeder "
    L"Monitor speichert seine eigenen Einstellungen. FlyingSolids zeigt beleuchtete dreidimensionale "
    L"Volumenkörper. Die Regler bestimmen Objekt- und Kamerageschwindigkeit von 0–1600 %, ein bis zehn "
    L"Exemplare je Körper und eine Größe von 50–200 %. Wählen Sie Raumbeobachtung oder Flug durch den Raum "
    L"in gerader Linie und aktivieren Sie die gewünschten Körper. Die Kontrollkästchen Hauptlicht, "
    L"Aufhelllicht, Umgebungslicht und Konturlicht unter den Reglern steuern die Beleuchtung der gesamten "
    L"Szene unabhängig voneinander. Umgebungslicht sorgt für eine Grundhelligkeit der Körperoberflächen, "
    L"Konturlicht betont ihre Ränder. Die Beleuchtungseinstellungen werden für Anwendung und "
    L"Bildschirmschoner getrennt gespeichert.\r\n\r\nDie Zeilenauswahl bestimmt, welche Monitore Sie "
    L"bearbeiten; sie ist von den Kontrollkästchen zum Einschalten der Animationsausgabe getrennt. Strg+A "
    L"wählt alle Monitore, Strg und Umschalt ändern die Auswahl. Alle Animationsoptionen und Regler gelten "
    L"für die ausgewählten Monitore. Die Auswahl wird für EXE und SCR getrennt gespeichert. Waren alle "
    L"Monitore ausgewählt, werden auch neu angeschlossene ausgewählt.\r\n\r\nIn der Liste sind mehrere "
    L"Monitore wählbar; ein Doppelklick schaltet einen Monitor um, auch alle können abgewählt werden. Jeder "
    L"Monitor besitzt eine unabhängige Szene. Schnappschuss speichert PNG, die Aufnahmetaste startet oder "
    L"beendet MP4. Pause hält die Animation an. Die Anwendung installiert oder deinstalliert außerdem den "
    L"eingebetteten Bildschirmschoner. Einstellungen werden laufend gespeichert. Die Anwendung läuft nur in "
    L"einer Instanz. Ein erneuter Start stellt das minimierte Steuerfenster wieder her und bringt es in den "
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
    L"Sélectionnez un ou plusieurs écrans dans la liste. Le mode de caméra, les objets, l’éclairage, les "
    L"vitesses, la taille et le nombre de copies ne s’appliquent qu’aux écrans sélectionnés. Chaque écran "
    L"mémorise ses propres réglages. FlyingSolids affiche des solides 3D éclairés. Les curseurs règlent la "
    L"vitesse des objets et de la caméra de 0 à 1 600 %, une à dix copies de chaque solide et une taille de "
    L"50 à 200 %. Choisissez Observation de l’espace ou le Vol dans l’espace rectiligne, puis activez les "
    L"solides voulus. Les cases Éclairage principal, Éclairage d’appoint, Éclairage ambiant et Éclairage "
    L"des contours sous les curseurs contrôlent indépendamment l’éclairage de toute la scène. L’éclairage "
    L"ambiant fournit une luminosité de base aux surfaces, et l’éclairage des contours souligne leurs "
    L"bords. Les réglages sont enregistrés séparément pour l’application et l’économiseur "
    L"d’écran.\r\n\r\nLa sélection des lignes détermine les écrans à configurer ; elle est distincte des "
    L"cases qui activent les sorties d’animation. Ctrl+A sélectionne tous les écrans ; Ctrl et Maj "
    L"modifient la sélection. Toutes les options et tous les curseurs d’animation concernent les écrans "
    L"sélectionnés. La sélection est mémorisée séparément pour EXE et SCR. Si tous les écrans étaient "
    L"sélectionnés, les nouveaux le sont également.\r\n\r\nSélectionnez plusieurs moniteurs dans la liste ; "
    L"un double-clic active ou désactive un moniteur, et vous pouvez tous les désélectionner. Chaque "
    L"moniteur utilise une scène indépendante. Capture enregistre un PNG et le bouton d’enregistrement "
    L"démarre ou arrête un MP4. Pause arrête l’animation. L’application installe ou désinstalle aussi son "
    L"économiseur intégré. Les réglages sont enregistrés en continu. Une seule instance de l’application "
    L"peut fonctionner à la fois. Un nouveau lancement restaure la fenêtre de contrôle réduite et la place "
    L"au premier plan. Utilisez Tab et Maj+Tab pour passer d’un contrôle à l’autre ; Alt et la lettre "
    L"soulignée activent une commande. Échap ferme la fenêtre d’aide ou À propos active ; dans la fenêtre "
    L"de contrôle, cette touche quitte l’application. Bloquer l’écran de veille pendant l’animation empêche "
    L"le lancement de l’économiseur d’écran Windows uniquement lorsque l’animation est réellement visible "
    L"et n’est pas en pause.\r\n\r\nLes captures et les enregistrements utilisent le premier moniteur "
    L"d’animation actif, et non une image combinant tous les moniteurs. PNG utilise Images, MP4 Vidéos ; "
    L"Documents sert de repli si ces dossiers n’existent pas. Le bouton Réglages vidéo permet de choisir "
    L"Viewport ou TV. Viewport conserve les dimensions et la fréquence de rafraîchissement du moniteur "
    L"d’animation, jusqu’à 60 images par seconde. TV propose 1920 × 1080, 1440 × 1080 ou 1280 × 720 au "
    L"format 16:9, à 50, 25, 59.94 (60000/1001) ou 29.97 (30000/1001) images par seconde. Le rapport "
    L"d’aspect est conservé ; TV utilise une vidéo progressive BT.709 à plage limitée et "
    L"sous-échantillonnage 4:2:0. La résolution et la fréquence d’images ne sont disponibles qu’en mode TV. "
    L"La fenêtre Réglages vidéo peut être réduite et ne bloque pas les autres fenêtres de l’application. OK "
    L"enregistre les choix pour le prochain enregistrement MP4 ; Annuler ou Échap abandonne les "
    L"modifications non confirmées. Le moniteur enregistré ne peut pas être désélectionné pendant "
    L"l’enregistrement ; les changements concernant les autres moniteurs ne l’arrêtent pas. Fermer "
    L"l’application pendant un enregistrement nécessite une confirmation, car cela arrête aussi "
    L"l’enregistrement.\r\n\r\nWindows 7 à Windows 11 prennent en charge toutes les fonctions, y compris "
    L"les captures PNG et l’enregistrement MP4. Pour exécuter l’application sous Windows Vista SP2, il est "
    L"nécessaire d’installer les mises à jour KB971512 et KB2117917. L’enregistrement MP4 ne fonctionne pas "
    L"sous Vista dans la version actuelle.",
    L"Seleccione una o varias pantallas en la lista. El modo de cámara, los objetos, la iluminación, las "
    L"velocidades, el tamaño y el número de copias se aplican solo a las pantallas seleccionadas. Cada "
    L"pantalla guarda sus propios ajustes. FlyingSolids muestra sólidos 3D iluminados. Los controles "
    L"ajustan la velocidad de objetos y cámara entre 0 y 1600 %, de una a diez copias y el tamaño entre 50 "
    L"y 200 %. Elija Observación del espacio o el Vuelo por el espacio en línea recta y active los sólidos "
    L"deseados. Las casillas Luz principal, Luz de relleno, Luz ambiental e Iluminación de contornos bajo "
    L"los controles deslizantes controlan de forma independiente la iluminación de toda la escena. La luz "
    L"ambiental aporta iluminación básica a las superficies y la iluminación de contornos resalta sus "
    L"bordes. De forma predeterminada, las luces principal, ambiental y de contornos están activadas, y la "
    L"luz de relleno está desactivada. Los ajustes se guardan por separado para la aplicación y el "
    L"salvapantallas.\r\n\r\nLa selección de filas determina qué pantallas se están configurando; es "
    L"independiente de las casillas que activan las salidas de animación. Ctrl+A selecciona todas; Ctrl y "
    L"Mayús modifican la selección. Todas las opciones y los controles deslizantes de animación se aplican "
    L"a las pantallas seleccionadas. La selección se recuerda por separado para EXE y SCR. Si estaban "
    L"seleccionadas todas, se incluyen también las nuevas.\r\n\r\nSeleccione varios monitores en la lista; "
    L"un doble clic alterna la animación en un monitor y también puede desmarcarlos todos. Cada monitor usa "
    L"una escena independiente. Captura guarda un PNG y el botón de grabación inicia o detiene un MP4. "
    L"Pausar detiene la animación. La aplicación instala o desinstala además el salvapantallas incorporado. "
    L"Los ajustes se guardan continuamente. La aplicación solo permite una instancia. Al volver a "
    L"iniciarla, restaura la ventana de control minimizada y la trae al primer plano. Use Tab y Mayús+Tab "
    L"para desplazarse entre controles; Alt y la letra subrayada activan una opción. Esc cierra la ventana "
    L"activa de Ayuda o Acerca de; en la ventana de control, sale de la aplicación. Bloquear salvapantallas "
    L"durante la animación impide que se inicie el salvapantallas de Windows solo mientras la animación "
    L"está realmente visible y no está en pausa.\r\n\r\nLas capturas y grabaciones usan el primer monitor "
    L"de animación activo, no una imagen conjunta de todos los monitores. PNG usa Imágenes y MP4 Vídeos; si "
    L"no existen esas carpetas, se usa Documentos. El botón Ajustes de grabación permite elegir Viewport o "
    L"TV. Viewport conserva las dimensiones y la frecuencia de actualización del monitor de animación, "
    L"hasta 60 fotogramas por segundo. TV ofrece 1920 × 1080, 1440 × 1080 o 1280 × 720 en formato 16:9, a "
    L"50, 25, 59.94 (60000/1001) o 29.97 (30000/1001) fotogramas por segundo. Se conserva la relación de "
    L"aspecto; TV usa vídeo progresivo BT.709 de rango limitado y submuestreo 4:2:0. La resolución y la "
    L"frecuencia solo están disponibles en modo TV. La ventana Ajustes de grabación se puede minimizar y no "
    L"bloquea las demás ventanas de la aplicación. Aceptar guarda las opciones para la próxima grabación "
    L"MP4; Cancelar o Esc descarta los cambios sin confirmar. El monitor grabado no se puede desmarcar "
    L"durante la grabación; cambiar otros monitores no la detiene. Cerrar la aplicación durante una "
    L"grabación requiere confirmación porque también detiene la grabación.\r\n\r\nWindows 7 a Windows 11 "
    L"admiten todas las funciones, incluidas las capturas PNG y la grabación MP4. Para ejecutar la "
    L"aplicación en Windows Vista SP2, es necesario instalar las actualizaciones KB971512 y KB2117917. La "
    L"grabación MP4 no funciona en Vista en la versión actual.",
    L"Selezionare uno o più monitor nell’elenco. La modalità della telecamera, gli oggetti, le luci, le "
    L"velocità, le dimensioni e il numero di copie si applicano solo ai monitor selezionati. Ogni monitor "
    L"conserva le proprie impostazioni. FlyingSolids mostra solidi 3D illuminati. I cursori regolano la "
    L"velocità di oggetti e camera tra 0 e 1600 %, da una a dieci copie e la dimensione tra 50 e 200 %. "
    L"Scegliere Osservazione dello spazio o il Volo nello spazio rettilineo e attivare i solidi desiderati. "
    L"Le caselle Luce principale, Luce di riempimento, Luce ambientale e Illuminazione dei contorni sotto i "
    L"cursori controllano indipendentemente l’illuminazione dell’intera scena. La luce ambientale fornisce "
    L"un’illuminazione di base alle superfici, mentre quella dei contorni ne evidenzia i bordi. Le "
    L"impostazioni vengono salvate separatamente per l’applicazione e il salvaschermo.\r\n\r\nLa selezione "
    L"delle righe determina quali schermi si stanno configurando ed è distinta dalle caselle che attivano "
    L"le uscite di animazione. Ctrl+A seleziona tutti gli schermi; Ctrl e Maiusc modificano la selezione. "
    L"Tutte le opzioni e i cursori dell’animazione riguardano gli schermi selezionati. La selezione viene "
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
    L"Selecione um ou mais monitores na lista. O modo de câmara, os objetos, a iluminação, as velocidades, "
    L"o tamanho e o número de cópias aplicam-se apenas aos monitores selecionados. Cada monitor guarda as "
    L"suas próprias definições. O FlyingSolids mostra sólidos 3D iluminados. Os controlos regulam a "
    L"velocidade dos objetos e da câmara entre 0 e 1600%, uma a dez cópias e o tamanho entre 50 e 200%. "
    L"Escolha Observação do espaço ou o Voo pelo espaço em linha reta e ative os sólidos pretendidos. As "
    L"caixas Luz principal, Luz de preenchimento, Luz ambiente e Iluminação dos contornos sob os controlos "
    L"deslizantes controlam a iluminação de toda a cena de forma independente. A luz ambiente fornece "
    L"iluminação de base às superfícies e a iluminação dos contornos realça os seus limites. Por "
    L"predefinição, as luzes principal, ambiente e dos contornos estão ligadas e a luz de preenchimento "
    L"está desligada. As definições são guardadas separadamente para a aplicação e a proteção de "
    L"ecrã.\r\n\r\nA seleção das linhas determina os ecrãs a configurar e é independente das caixas que "
    L"ativam as saídas de animação. Ctrl+A seleciona todos os ecrãs; Ctrl e Shift alteram a seleção. Todas "
    L"as opções e controlos deslizantes da animação aplicam-se aos ecrãs selecionados. A seleção é guardada "
    L"separadamente para EXE e SCR. Se todos estavam selecionados, os novos ecrãs também são "
    L"incluídos.\r\n\r\nSelecione vários monitores; um duplo clique alterna uma linha e todos podem ser "
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
    L"Zaznacz jeden lub więcej monitorów na liście. Tryb kamery, wybór brył, oświetlenie, prędkości, "
    L"rozmiar i liczba kopii dotyczą tylko zaznaczonych monitorów. Każdy monitor zapamiętuje własne "
    L"ustawienia. FlyingSolids wyświetla oświetlone pełne bryły 3D. Suwaki ustawiają prędkość obiektów i "
    L"kamery od 0 do 1600%, od jednej do dziesięciu kopii i rozmiar od 50 do 200%. Wybierz Obserwację "
    L"przestrzeni lub prostoliniowy Przelot przez przestrzeń i włącz potrzebne bryły. Pola wyboru Światło "
    L"główne, Światło wypełniające, Światło otoczenia i Oświetlenie konturów pod suwakami niezależnie "
    L"sterują oświetleniem całej sceny. Światło otoczenia zapewnia podstawową jasność powierzchni, a "
    L"oświetlenie konturów podkreśla krawędzie. Ustawienia są zapisywane osobno dla aplikacji i wygaszacza "
    L"ekranu.\r\n\r\nZaznaczenie wierszy określa konfigurowane monitory i jest niezależne od pól wyboru "
    L"włączających wyjścia animacji. Ctrl+A zaznacza wszystkie monitory; Ctrl i Shift zmieniają "
    L"zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą zaznaczonych monitorów. Zaznaczenie jest "
    L"zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były wszystkie monitory, nowe również zostaną "
    L"zaznaczone.\r\n\r\nNa liście można zaznaczyć wiele monitorów; podwójne kliknięcie przełącza animację "
    L"na monitorze, można też odznaczyć wszystkie. Każdy monitor ma niezależną scenę. Zrzut zapisuje PNG, a "
    L"przycisk nagrywania rozpoczyna lub kończy MP4. Wstrzymaj zatrzymuje animację. Aplikacja instaluje i "
    L"odinstalowuje również wbudowany wygaszacz. Ustawienia są zapisywane na bieżąco. Aplikacja działa "
    L"tylko w jednej instancji. Kolejne uruchomienie przywraca zminimalizowane okno sterowania i przenosi "
    L"na pierwszy plan. Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera "
    L"wywołują polecenie. Esc zamyka aktywne okno Pomocy lub O programie; w oknie sterowania kończy "
    L"działanie aplikacji. Blokuj wygaszacz podczas animacji zapobiega uruchomieniu wygaszacza Windows "
    L"tylko wtedy, gdy animacja jest rzeczywiście widoczna i nie jest wstrzymana.\r\n\r\nZrzuty i nagrania "
    L"obejmują pierwszy aktywny monitor animacji, a nie wspólny obraz wszystkich monitorów. PNG używa "
    L"folderu Obrazy, MP4 folderu Wideo; jeśli ich nie ma, używane są Dokumenty. Przycisk Ustawienia "
    L"nagrywania pozwala wybrać Viewport lub TV. Viewport zachowuje rozmiar i częstotliwość odświeżania "
    L"monitora animacji, do 60 klatek na sekundę. TV oferuje 1920 × 1080, 1440 × 1080 lub 1280 × 720 w "
    L"formacie 16:9, z 50, 25, 59.94 (60000/1001) lub 29.97 (30000/1001) klatkami na sekundę. Proporcje "
    L"obrazu są zachowane; TV używa progresywnego obrazu BT.709 z ograniczonym zakresem i próbkowaniem "
    L"4:2:0. Rozdzielczość i liczba klatek są dostępne tylko w trybie TV. Okno Ustawienia nagrywania można "
    L"zminimalizować i nie blokuje ono innych okien aplikacji. OK zapisuje wybór dla następnego nagrania "
    L"MP4; Anuluj lub Esc odrzuca niepotwierdzone zmiany. Podczas nagrywania nie można odznaczyć "
    L"nagrywanego monitora; zmiany pozostałych monitorów nie przerywają nagrania. Zamknięcie aplikacji "
    L"podczas nagrywania wymaga potwierdzenia, ponieważ kończy również nagranie.\r\n\r\nSystemy od Windows "
    L"7 do Windows 11 obsługują wszystkie funkcje, w tym zrzuty PNG i nagrywanie MP4. Do uruchomienia "
    L"aplikacji w systemie Windows Vista SP2 konieczne jest zainstalowanie aktualizacji KB971512 i "
    L"KB2117917. Nagrywanie MP4 nie działa w Vista w obecnej wersji.",
    L"V zozname označte jeden alebo viac monitorov. Režim kamery, výber telies, svetlá, rýchlosti, veľkosť "
    L"a počet kópií sa nastavujú len pre označené monitory a každý monitor si pamätá vlastné nastavenia. "
    L"FlyingSolids zobrazuje osvetlené plné 3D telesá. Jazdce nastavujú rýchlosť objektov a kamery 0–1600 "
    L"%, jednu až desať kópií a veľkosť 50–200 %. Vyberte Pozorovanie priestoru alebo priamy Prelet "
    L"priestorom a zapnite požadované telesá. Začiarkavacie políčka Hlavné svetlo, Doplnkové svetlo, "
    L"Základný jas a Prisvetlenie obrysov pod jazdcami nezávisle ovládajú osvetlenie celej scény. Základný "
    L"jas prisvetľuje povrchy telies a prisvetlenie obrysov zvýrazňuje ich okraje. Nastavenia osvetlenia sa "
    L"ukladajú zvlášť pre aplikáciu a šetrič obrazovky.\r\n\r\nOznačenie riadkov určuje, ktoré monitory "
    L"práve nastavujete; je nezávislé od políčok zapínajúcich animačné výstupy. Ctrl+A označí všetky "
    L"monitory, Ctrl a Shift upravujú označenie. Všetky animačné voľby a posuvníky platia pre označené "
    L"monitory. Označenie sa pamätá zvlášť pre EXE a SCR. Ak boli označené všetky monitory, označia sa aj "
    L"novopripojené.\r\n\r\nV zozname možno označiť viac monitorov; dvojklik zapína alebo vypína animáciu "
    L"na monitore a možno zrušiť aj výber všetkých. Každý monitor používa nezávislú scénu. Snímka uloží PNG "
    L"a tlačidlo záznamu spustí alebo ukončí MP4. Pozastavenie zastaví animáciu. Aplikácia tiež nainštaluje "
    L"alebo odinštaluje vložený šetrič. Nastavenia sa ukladajú priebežne. Aplikácia beží iba v jednej "
    L"inštancii. Ďalšie spustenie obnoví minimalizované ovládacie okno a prenesie do popredia. Medzi "
    L"ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou Alt a "
    L"príslušného písmena. Esc zavrie aktívne okno Pomocníka alebo O aplikácii; v ovládacom okne ukončí "
    L"aplikáciu. Voľba Blokovať šetrič pri animácii bráni spusteniu šetriča Windows iba vtedy, keď je "
    L"animácia skutočne viditeľná a nie je pozastavená.\r\n\r\nSnímky a záznamy zachytávajú prvý aktívny "
    L"animačný monitor, nie spoločnú plochu všetkých monitorov. PNG používa Obrázky, MP4 Videá; ak tieto "
    L"priečinky neexistujú, použijú sa Dokumenty. Tlačidlo Nastavenie záznamu vyberá Viewport alebo TV. "
    L"Viewport zachováva rozmery animačného monitora a jeho obnovovaciu frekvenciu, najviac 60 snímok za "
    L"sekundu. TV ponúka rozlíšenie 1920 × 1080, 1440 × 1080 alebo 1280 × 720 v pomere 16:9 a frekvenciu "
    L"50, 25, 59.94 (60000/1001) alebo 29.97 (30000/1001) snímok za sekundu. Obraz zachováva pomer strán; "
    L"TV používa progresívne video BT.709 s obmedzeným rozsahom a vzorkovaním 4:2:0. Rozlíšenie a snímkovú "
    L"frekvenciu možno vybrať iba v režime TV. Okno Nastavenie záznamu možno minimalizovať a neblokuje "
    L"ostatné okná aplikácie. OK uloží voľby pre nasledujúci záznam MP4; Zrušiť alebo Esc zahodí "
    L"nepotvrdené zmeny. Nahrávaný monitor nemožno počas záznamu odpojiť; zmeny ostatných monitorov záznam "
    L"nezastavia. Ukončenie aplikácie počas záznamu vyžaduje potvrdenie, pretože ukončí aj "
    L"záznam.\r\n\r\nWindows 7 až Windows 11 podporujú všetky funkcie vrátane snímok PNG a záznamu MP4. Na "
    L"spustenie aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať aktualizácie KB971512 a "
    L"KB2117917. Záznam MP4 na Viste v súčasnej verzii nefunguje.",
    L"Vælg en eller flere skærme på listen. Kameratilstand, objekter, belysning, hastigheder, størrelse og "
    L"antal kopier gælder kun de valgte skærme. Hver skærm husker sine egne indstillinger. FlyingSolids "
    L"viser belyste solide 3D-legemer. Skyderne indstiller objekt- og kamerahastighed 0–1600 %, en til ti "
    L"kopier og størrelse 50–200 %. Vælg Rumobservation eller Flyvning gennem rummet i en lige linje og "
    L"aktivér de ønskede legemer. Afkrydsningsfelterne Hovedlys, Udfyldningslys, Omgivende lys og Konturlys "
    L"under skyderne styrer belysningen af hele scenen uafhængigt af hinanden. Omgivende lys giver "
    L"overfladerne en grundbelysning, og konturlys fremhæver kanterne. Som standard er hovedlys, omgivende "
    L"lys og konturlys slået til og udfyldningslys slået fra. Indstillingerne gemmes separat for programmet "
    L"og pauseskærmen.\r\n\r\nMarkeringen af rækker bestemmer, hvilke skærme du indstiller, og er adskilt "
    L"fra afkrydsningsfelterne, der aktiverer animationsoutput. Ctrl+A markerer alle skærme; Ctrl og Skift "
    L"ændrer markeringen. Alle animationsvalg og skydere gælder de markerede skærme. Markeringen huskes "
    L"separat for EXE og SCR. Hvis alle skærme var markeret, medtages også nye skærme.\r\n\r\nVælg flere "
    L"skærme i listen; dobbeltklik på en række for at slå animationen til eller fra, eller fravælg alle. "
    L"Hver skærm bruger en uafhængig scene. Skærmbillede gemmer PNG, og optageknappen starter eller stopper "
    L"MP4. Pause standser animationen. Programmet installerer eller afinstallerer også den indbyggede "
    L"pauseskærm. Indstillinger gemmes løbende. Programmet kan kun køre i én instans ad gangen. En ny start "
    L"gendanner det minimerede kontrolvindue og bringer det forrest. Brug Tab og Skift+Tab til at flytte "
    L"mellem kontrollerne; Alt og det understregede bogstav aktiverer en kommando. Esc lukker det aktive "
    L"Hjælp- eller Om-vindue; i kontrolvinduet afslutter det programmet. Blokér pauseskærm under animation "
    L"forhindrer Windows-pauseskærmen i at starte, men kun når animationen faktisk er synlig og ikke er sat "
    L"på pause.\r\n\r\nSkærmbilleder og optagelser bruger den første aktive animationsskærm, ikke et samlet "
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
    L"Valitse luettelosta yksi tai useampi näyttö. Kameratila, kappaleet, valaistus, nopeudet, koko ja "
    L"kopioiden määrä koskevat vain valittuja näyttöjä. Jokainen näyttö muistaa omat asetuksensa. "
    L"FlyingSolids näyttää valaistuja kiinteitä 3D-kappaleita. Liukusäätimillä asetetaan kohteiden ja "
    L"kameran nopeus 0–1600 %, yhdestä kymmeneen kopiota ja koko 50–200 %. Valitse Avaruuden tarkkailu tai "
    L"Lento avaruuden halki suoraan eteenpäin ja ota halutut kappaleet käyttöön. Liukusäätimien alla olevat "
    L"Päävalo-, Täytevalo-, Ympäristövalo- ja Reunavalo-valintaruudut ohjaavat koko näkymän valaistusta "
    L"toisistaan riippumatta. Ympäristövalo antaa pinnoille perusvalaistuksen ja reunavalo korostaa "
    L"reunoja. Oletuksena päävalo, ympäristövalo ja reunavalo ovat päällä ja täytevalo pois päältä. "
    L"Asetukset tallennetaan erikseen sovellukselle ja näytönsäästäjälle.\r\n\r\nRivien valinta määrää "
    L"muokattavat näytöt ja on erillinen animaatioulostulon valintaruuduista. Ctrl+A valitsee kaikki "
    L"näytöt; Ctrl ja Vaihto muuttavat valintaa. Kaikki animaatioasetukset ja liukusäätimet koskevat "
    L"valittuja näyttöjä. Valinta muistetaan erikseen EXE- ja SCR-tiloissa. Jos kaikki näytöt olivat "
    L"valittuina, myös uudet näytöt valitaan.\r\n\r\nLuettelosta voi valita useita näyttöjä; "
    L"kaksoisnapsautus vaihtaa rivin tilaa ja kaikkien näyttöjen valinnan voi poistaa. Jokaisella näytöllä "
    L"on itsenäinen näkymä. Tilannekuva tallentaa PNG:n ja tallennuspainike käynnistää tai lopettaa MP4:n. "
    L"Keskeytä pysäyttää animaation. Sovellus asentaa tai poistaa myös sisäisen näytönsäästäjän. Asetukset "
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
    L"Veldu einn eða fleiri skjái á listanum. Myndavélarhamur, hlutir, lýsing, hraði, stærð og fjöldi "
    L"eintaka eiga aðeins við um valda skjái. Hver skjár geymir sínar eigin stillingar. FlyingSolids sýnir "
    L"upplýsta heila þrívíddarhluti. Rennistikur stilla hraða hluta og myndavélar á 0–1600%, eitt til tíu "
    L"eintök og stærð á 50–200%. Veldu Athugun rýmis eða Flug um rýmið í beinni línu og virkjaðu þá hluti "
    L"sem óskað er eftir. Gátreitirnir Aðalljós, Fylliljós, Umhverfislýsing og Útlínulýsing undir "
    L"rennistikunum stýra lýsingu allrar senunnar óháð hver öðrum. Umhverfislýsing gefur yfirborðunum "
    L"grunnbirtu og útlínulýsing dregur fram jaðrana. Stillingarnar eru vistaðar sérstaklega fyrir forritið "
    L"og skjáhvíluna.\r\n\r\nVal lína ákvarðar hvaða skjám er verið að breyta og er óháð gátreitunum sem "
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
    L"Velg én eller flere skjermer i listen. Kameramodus, objekter, belysning, hastigheter, størrelse og "
    L"antall kopier gjelder bare de valgte skjermene. Hver skjerm husker sine egne innstillinger. "
    L"FlyingSolids viser belyste solide 3D-legemer. Glidebryterne angir objekt- og kamerahastighet fra "
    L"0–1600 %, én til ti kopier og størrelse fra 50–200 %. Velg Romobservasjon eller Flyging gjennom "
    L"rommet i rett linje og aktiver ønskede legemer. Avmerkingsboksene Hovedlys, Utfyllingslys, "
    L"Omgivelseslys og Konturlys under glidebryterne styrer belysningen i hele scenen uavhengig av "
    L"hverandre. Omgivelseslys gir grunnbelysning på overflatene, og konturlys fremhever kantene. Som "
    L"standard er hovedlys, omgivelseslys og konturlys på, og utfyllingslys av. Innstillingene lagres "
    L"separat for programmet og skjermspareren.\r\n\r\nMarkeringen av rader bestemmer hvilke skjermer du "
    L"redigerer, og er atskilt fra avkrysningsboksene som aktiverer animasjonsutgangen. Ctrl+A markerer "
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
    L"Markera en eller flera skärmar i listan. Kameraläge, objekt, belysning, hastigheter, storlek och "
    L"antal kopior gäller bara de markerade skärmarna. Varje skärm sparar sina egna inställningar. "
    L"FlyingSolids visar belysta solida 3D-kroppar. Reglagen ställer in objekt- och kamerahastighet 0–1600 "
    L"%, en till tio kopior och storlek 50–200 %. Välj Rymdobservation eller Flygning genom rymden i rak "
    L"linje och aktivera önskade kroppar. Kryssrutorna Huvudljus, Upplättningsljus, Omgivningsljus och "
    L"Konturljus under reglagen styr belysningen i hela scenen oberoende av varandra. Omgivningsljus ger "
    L"grundbelysning på ytorna och konturljus framhäver kanterna. Som standard är huvudljus, omgivningsljus "
    L"och konturljus på och upplättningsljus av. Inställningarna sparas separat för programmet och "
    L"skärmsläckaren.\r\n\r\nMarkeringen av rader avgör vilka skärmar du redigerar och är skild från "
    L"kryssrutorna som aktiverar animationsutgångarna. Ctrl+A markerar alla skärmar; Ctrl och Skift ändrar "
    L"markeringen. Alla animationsalternativ och reglage gäller de markerade skärmarna. Markeringen sparas "
    L"separat för EXE och SCR. Om alla skärmar var markerade inkluderas även nya skärmar.\r\n\r\nVälj flera "
    L"bildskärmar i listan; dubbelklicka en rad för att slå på eller av animeringen, eller avmarkera alla. "
    L"Varje bildskärm använder en oberoende scen. Skärmbild sparar PNG och inspelningsknappen startar eller "
    L"stoppar MP4. Paus stannar animeringen. Programmet installerar eller avinstallerar även den inbyggda "
    L"skärmsläckaren. Inställningarna sparas fortlöpande. Programmet kan bara köras i en instans åt gången. "
    L"En ny start återställer det minimerade kontrollfönstret och för det längst fram. Använd Tab och "
    L"Skift+Tab för att flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett "
    L"kommando. Esc stänger det aktiva Hjälp- eller Om-fönstret; i kontrollfönstret avslutar det "
    L"programmet. Blockera skärmsläckare under animering hindrar Windows-skärmsläckaren från att starta "
    L"endast när animeringen faktiskt är synlig och inte är pausad.\r\n\r\nSkärmbilder och inspelningar "
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
    L"bekräftelse eftersom det också avslutar inspelningen.\r\n\r\nWindows 7 till Windows 11 stöder alla "
    L"funktioner, inklusive PNG-skärmbilder och MP4-inspelning. För att köra programmet på Windows Vista "
    L"SP2 måste uppdateringarna KB971512 och KB2117917 installeras. MP4-inspelning fungerar inte på Vista i "
    L"den aktuella versionen.",
    L"Listeden bir veya daha fazla ekran seçin. Kamera modu, nesneler, aydınlatma, hızlar, boyut ve kopya "
    L"sayısı yalnızca seçili ekranlara uygulanır. Her ekran kendi ayarlarını hatırlar. FlyingSolids "
    L"aydınlatılmış katı 3B cisimler gösterir. Kaydırıcılar nesne ve kamera hızını %0–1600, kopya sayısını "
    L"bir ile on ve boyutu %50–200 arasında ayarlar. Uzayı gözlemleme veya doğrusal Uzayda uçuş kipini "
    L"seçip istenen cisimleri etkinleştirin. Kaydırıcıların altındaki Ana ışık, Dolgu ışığı, Ortam ışığı ve "
    L"Kenar aydınlatması onay kutuları tüm sahnenin aydınlatmasını birbirinden bağımsız olarak kontrol "
    L"eder. Ortam ışığı yüzeylere temel aydınlatma sağlar, kenar aydınlatması ise kenarları vurgular. "
    L"Ayarlar uygulama ve ekran koruyucu için ayrı ayrı kaydedilir.\r\n\r\nSatır seçimi, hangi ekranların "
    L"düzenlendiğini belirler; animasyon çıkışlarını açan onay kutularından ayrıdır. Ctrl+A tüm ekranları "
    L"seçer; Ctrl ve Shift seçimi değiştirir. Tüm animasyon seçenekleri ve kaydırıcılar seçili ekranlara "
    L"uygulanır. Seçim EXE ve SCR için ayrı saklanır. Tüm ekranlar seçiliyse sonradan bağlanan ekranlar da "
    L"seçime katılır.\r\n\r\nListede birden çok monitör seçilebilir; satıra çift tıklamak monitördeki "
    L"animasyonu açıp kapatır; tüm monitörlerin seçimi de kaldırılabilir. Her monitör bağımsız sahne "
    L"kullanır. Anlık görüntü PNG kaydeder; kayıt düğmesi MP4 kaydını başlatır veya bitirir. Duraklat "
    L"animasyonu durdurur. Uygulama gömülü ekran koruyucuyu da kurar veya kaldırır. Ayarlar sürekli "
    L"kaydedilir. Uygulamanın aynı anda yalnızca bir örneği çalışabilir. Yeniden başlatılması, simge "
    L"durumuna küçültülmüş denetim penceresini geri yükler ve ön plana getirir. Denetimler arasında Tab ve "
    L"Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir komutu etkinleştirir. Esc, etkin Yardım veya "
    L"Hakkında penceresini kapatır; denetim penceresinde uygulamadan çıkar. Animasyon sırasında ekran "
    L"koruyucuyu engelle seçeneği, Windows ekran koruyucusunun yalnızca animasyon gerçekten görünürken ve "
    L"duraklatılmamışken başlamasını engeller.\r\n\r\nAnlık görüntüler ve kayıtlar, tüm monitörlerin "
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
    L"kaydı da durduracağı için onay gerektirir.\r\n\r\nWindows 7 ile Windows 11 arasındaki sürümler, PNG "
    L"anlık görüntüler ve MP4 kaydı dâhil tüm özellikleri destekler. Uygulamayı Windows Vista SP2'de "
    L"çalıştırmak için KB971512 ve KB2117917 güncellemelerini yüklemeniz gerekir. Geçerli sürümde MP4 kaydı "
    L"Vista'da çalışmaz.",
    L"FlyingSolids kuvab liikuvaid, pöörlevaid ja põrkuvaid ruumilisi kehi. Valige ruumi vaatlemine või "
    L"lend läbi ruumi ning soovitud kehad. Iga kuvari jaoks saab eraldi määrata objektide ja kaamera "
    L"kiiruse 0–1600%, objektide suuruse 50–200% ning iga keha koopiate arvu 1–10. Põhi-, täite-, ümbritsev "
    L"ja kontuurivalgus on sõltumatult lülitatavad.\r\n\r\nValige loendis üks või mitu kuvaririda. Ctrl+A "
    L"valib kõik read; Ctrl ja Shift võimaldavad valikut muuta. Animatsiooni juhtnupud ja liugurid "
    L"mõjutavad ainult valitud kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle märkeruuduga "
    L"väljundi lubamine on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja jaoks eraldi meelde. "
    L"Kui varem olid valitud kõik kuvarid, kaasatakse ka lisatud kuvarid.\r\n\r\nKäivitage "
    L"FlyingSolids.exe. Sätteid salvestatakse jooksvalt ning rakendus töötab ühe eksemplarina. Kuvari "
    L"märkeruut või topeltklõps real lülitab selle animatsiooniväljundi sisse või välja. Animatsiooni saab "
    L"peatada ja jätkata. PNG-pilt ja MP4-video jäädvustavad esimese aktiivse animatsioonikuvari, mitte "
    L"kõiki kuvareid koos. Salvestatavat kuvarit ei saa salvestamise ajal välja lülitada; rakenduse "
    L"sulgemine nõuab siis kinnitust. Ekraanisäästja tõkestamine kehtib ühiselt ja ainult siis, kui vastava "
    L"valikuga kuvaril on nähtav peatamata animatsioon. Rakendus saab paigaldada ja eemaldada sisseehitatud "
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
    L"Taispeánann FlyingSolids coirp sholadacha a ghluaiseann, a rothlaíonn agus a imbhuaileann. Roghnaigh "
    L"breathnú ar an spás nó eitilt tríd agus na coirp atá uait. Tá luas na réad agus an cheamara 0–1600%, "
    L"méid na réad 50–200% agus 1–10 gcóip de gach corp inchoigeartaithe go neamhspleách do gach monatóir. "
    L"Is féidir an príomhsholas, an solas líonta, an solas comhthimpeallach agus an solas imill a athrú ar "
    L"leith.\r\n\r\nRoghnaigh ró amháin nó níos mó sa liosta monatóirí. Roghnaíonn Ctrl+A gach ró; úsáid "
    L"Ctrl agus Shift chun an roghnú a athrú. Ní athraíonn rialuithe agus sleamhnáin na beochana ach "
    L"socruithe na monatóirí roghnaithe. Ní hionann ró a roghnú agus aschur an mhonatóra a chumasú lena "
    L"bhosca seiceála. Cuimhnítear an roghnú ar leith don fheidhmchlár agus don spárálaí. Má bhí gach "
    L"monatóir roghnaithe, cuirtear monatóirí nua leis an roghnú freisin.\r\n\r\nRith FlyingSolids.exe. "
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
    L"FlyingSolids rodo judančius, besisukančius ir susiduriančius erdvinius kūnus. Pasirinkite erdvės "
    L"stebėjimą arba skrydį erdve ir norimus kūnus. Kiekvienam monitoriui atskirai galima nustatyti objektų "
    L"bei kameros greitį 0–1600%, objektų dydį 50–200% ir 1–10 kiekvieno kūno kopijų. Pagrindinė, "
    L"užpildanti, aplinkos ir kontūrinė šviesa įjungiamos nepriklausomai.\r\n\r\nMonitorių sąraše "
    L"pasirinkite vieną ar kelias eilutes. Ctrl+A pasirenka visas, o Ctrl ir Shift leidžia keisti "
    L"pasirinkimą. Animacijos valdikliai ir slankikliai keičia tik pasirinktų monitorių nuostatas. Eilutės "
    L"pasirinkimas nėra tas pats, kas animacijos išvesties įjungimas jos žymimuoju langeliu. Pasirinkimas "
    L"atskirai įsimenamas programai ir užsklandai. Jei buvo pasirinkti visi monitoriai, į pasirinkimą "
    L"įtraukiami ir naujai prijungti monitoriai.\r\n\r\nPaleiskite FlyingSolids.exe. Nuostatos išsaugomos "
    L"nuolat, veikia tik vienas programos egzempliorius. Monitoriaus langelis arba dvigubas eilutės "
    L"spustelėjimas įjungia ar išjungia animacijos išvestį. Animaciją galima pristabdyti ir tęsti. PNG ir "
    L"MP4 fiksuoja pirmą aktyvų animacijos monitorių, o ne bendrą visų monitorių vaizdą. Įrašomo "
    L"monitoriaus išjungti negalima; uždarant programą vykstant įrašymui reikia patvirtinimo. Užsklandos "
    L"blokavimas yra bendras ir galioja tik kol monitoriuje su įjungta šia nuostata matoma nepristabdyta "
    L"animacija. Programa gali įdiegti ir pašalinti į ją įtrauktą užsklandą.\r\n\r\nĮrašymo nuostatose "
    L"pasirinkite Viewport arba TV. Viewport išsaugo monitoriaus matmenis ir dažnį iki 60 kadrų per "
    L"sekundę. TV siūlo 1920 × 1080, 1440 × 1080 arba 1280 × 720 išvestį 16:9 santykiu bei 50, 25, 59.94 "
    L"(60000/1001) arba 29.97 (30000/1001) kadrų per sekundę. TV vaizdas progresinis, BT.709, riboto "
    L"diapazono ir 4:2:0 spalvų diskretizavimo. Vaizdo proporcijos išlieka, užpildymo juostos juodos. OK "
    L"pritaiko nuostatas kitam įrašui, Atšaukti arba Esc atmeta nepatvirtintus pakeitimus. Įrašymo, žinyno "
    L"ir informacijos langai neblokuoja kitų langų ir gali būti sumažinti. Tab ir Shift+Tab keičia įvesties "
    L"vietą, Enter paspaudžia aktyvų mygtuką, Esc uždaro aktyvų papildomą langą.\r\n\r\nWindows 7–11 "
    L"palaiko visas funkcijas. Windows Vista SP2 būtina įdiegti naujinimus KB971512 ir KB2117917; MP4 "
    L"įrašymas Vistoje neveikia. Reikalingas Direct3D 11 palaikymas, o MP4 įrašymui Media Foundation ir "
    L"H.264 koduotuvas. Sąsaja ir dokumentacija pateikiamos 36 kalbomis.",
    L"FlyingSolids rāda kustīgus, rotējošus un savstarpēji sadurošus telpiskus ķermeņus. Izvēlieties telpas "
    L"novērošanu vai lidojumu telpā un vajadzīgos ķermeņus. Katram monitoram atsevišķi var iestatīt objektu "
    L"un kameras ātrumu 0–1600%, objektu izmēru 50–200% un 1–10 katra ķermeņa kopijas. Galveno, papildu, "
    L"apkārtējo un kontūru gaismu var pārslēgt neatkarīgi.\r\n\r\nMonitoru sarakstā atlasiet vienu vai "
    L"vairākas rindas. Ctrl+A atlasa visas, bet Ctrl un Shift ļauj mainīt atlasi. Animācijas vadīklas un "
    L"slīdņi maina tikai atlasīto monitoru iestatījumus. Rindas atlasīšana nav tas pats, kas animācijas "
    L"izvades ieslēgšana ar izvēles rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un ekrānsaudzētājam. "
    L"Ja bija atlasīti visi monitori, atlasē iekļauj arī jaunpievienotos monitorus.\r\n\r\nPalaidiet "
    L"FlyingSolids.exe. Iestatījumi tiek saglabāti nepārtraukti, un darbojas tikai viena lietotnes "
    L"instance. Monitora rūtiņa vai dubultklikšķis uz rindas ieslēdz vai izslēdz tā animācijas izvadi. "
    L"Animāciju var pauzēt un turpināt. PNG un MP4 uzņem pirmo aktīvo animācijas monitoru, nevis visu "
    L"monitoru kopējo attēlu. Ierakstāmo monitoru nevar izslēgt; aizverot lietotni ieraksta laikā, "
    L"nepieciešams apstiprinājums. Ekrānsaudzētāja bloķēšana ir kopīga un darbojas tikai tad, kamēr "
    L"monitorā ar ieslēgtu šo iespēju ir redzama nepauzēta animācija. Lietotne var instalēt vai atinstalēt "
    L"tajā iebūvēto ekrānsaudzētāju.\r\n\r\nIeraksta iestatījumos izvēlieties Viewport vai TV. Viewport "
    L"saglabā monitora izmērus un frekvenci līdz 60 kadriem sekundē. TV piedāvā 1920 × 1080, 1440 × 1080 "
    L"vai 1280 × 720 izvadi ar 16:9 malu attiecību un 50, 25, 59.94 (60000/1001) vai 29.97 (30000/1001) "
    L"kadriem sekundē. TV video ir progresīvs BT.709 ar ierobežotu diapazonu un 4:2:0 krāsu "
    L"apakšiztveršanu. Attēla proporcijas saglabājas, aizpildījuma joslas ir melnas. OK piemēro izvēles "
    L"nākamajam ierakstam, Atcelt vai Esc atmet neapstiprinātās izmaiņas. Ieraksta iestatījumu, palīdzības "
    L"un informācijas logi nebloķē citus logus un ir minimizējami. Tab un Shift+Tab pārvieto fokusu, Enter "
    L"aktivizē fokusēto pogu, Esc aizver aktīvo palīglogu.\r\n\r\nWindows 7–11 atbalsta visas funkcijas. "
    L"Windows Vista SP2 jāinstalē atjauninājumi KB971512 un KB2117917; MP4 ierakstīšana Vistā nedarbojas. "
    L"Nepieciešams Direct3D 11 atbalsts, bet MP4 vajadzīgi Media Foundation un H.264 kodētājs. Saskarne un "
    L"dokumentācija ir pieejama 36 valodās.",
    L"A FlyingSolids mozgó, forgó és ütköző térbeli testeket jelenít meg. Válassza a tér megfigyelését vagy "
    L"a térben repülést, és kapcsolja be a kívánt testeket. Monitoronként állítható az objektumok és a "
    L"kamera sebessége 0–1600%, az objektumok mérete 50–200%, valamint testenként 1–10 példány. A főfény, "
    L"derítőfény, környezeti fény és peremfény egymástól függetlenül kapcsolható.\r\n\r\nJelöljön ki egy "
    L"vagy több sort a monitorok listájában. A Ctrl+A mindet kijelöli; a Ctrl és a Shift módosítja a "
    L"kijelölést. Az animáció vezérlői és csúszkái csak a kijelölt monitorok beállításait változtatják. A "
    L"sor kijelölése és az animációs kimenet jelölőnégyzetes engedélyezése külön művelet. A kijelölést az "
    L"alkalmazás és a képernyőkímélő külön megjegyzi. Ha korábban minden monitor ki volt jelölve, az "
    L"újonnan csatlakoztatott monitorok is bekerülnek a kijelölésbe.\r\n\r\nIndítsa el a FlyingSolids.exe "
    L"fájlt. A beállítások folyamatosan mentődnek, és csak egy alkalmazáspéldány fut. A monitor "
    L"jelölőnégyzete vagy a sorra történő dupla kattintás kapcsolja az animációs kimenetet. Az animáció "
    L"szüneteltethető és folytatható. A PNG és az MP4 az első aktív animációs monitort rögzíti, nem az "
    L"összes monitor egyesített képét. A rögzített monitor felvétel közben nem kapcsolható ki; az "
    L"alkalmazás bezárásához ekkor megerősítés szükséges. A képernyőkímélő tiltása közös, és csak akkor "
    L"aktív, ha egy ezt kérő monitoron látható, nem szünetelő animáció fut. Az alkalmazás telepítheti és "
    L"eltávolíthatja a beágyazott képernyőkímélőt.\r\n\r\nA felvételi beállításoknál Viewport vagy TV "
    L"választható. A Viewport megőrzi a monitor képméretét és frissítési gyakoriságát, legfeljebb 60 "
    L"képkocka/másodpercig. A TV felbontása 1920 × 1080, 1440 × 1080 vagy 1280 × 720, képaránya 16:9; "
    L"sebessége 50, 25, 59.94 (60000/1001) vagy 29.97 (30000/1001) képkocka/másodperc. A TV videó "
    L"progresszív BT.709, korlátozott tartománnyal és 4:2:0 színmintavételezéssel. A kép arányai "
    L"megmaradnak, a kitöltősávok feketék. Az OK a következő felvételhez menti a választást; a Mégse vagy "
    L"Esc elveti a nem jóváhagyott módosításokat. A felvételi beállítások, a Súgó és a Névjegy nem "
    L"blokkolja a többi ablakot és kis méretűre állítható. A Tab és Shift+Tab mozgatja a fókuszt, az Enter "
    L"aktiválja a fókuszban levő gombot, az Esc bezárja az aktív kiegészítő ablakot.\r\n\r\nA Windows 7–11 "
    L"minden funkciót támogat. Windows Vista SP2 alatt telepíteni kell a KB971512 és KB2117917 frissítést; "
    L"az MP4-felvétel Vistán nem működik. Direct3D 11 támogatás szükséges, az MP4-hez Media Foundation és "
    L"H.264-kódoló is kell. A kezelőfelület és a dokumentáció 36 nyelven érhető el.",
    L"FlyingSolids juri solidi tridimensjonali li jiċċaqalqu, iduru u jaħbtu ma’ xulxin. Agħżel "
    L"osservazzjoni tal-ispazju jew titjira fl-ispazju u attiva l-forom mixtieqa. Għal kull moniter tista’ "
    L"tissettja separatament il-veloċità tal-oġġetti u l-kamera minn 0–1600%, id-daqs minn 50–200% u 1–10 "
    L"kopji ta’ kull solidu. Id-dawl ewlieni, id-dawl ta’ mili, id-dawl ambjentali u d-dawl tal-kontorn "
    L"jinxtegħlu separatament.\r\n\r\nAgħżel ringiela waħda jew aktar fil-lista tal-moniters. Ctrl+A "
    L"jagħżilhom kollha; Ctrl u Shift ibiddlu l-għażla. Il-kontrolli u s-sliders tal-animazzjoni jibdlu "
    L"biss is-settings tal-moniters magħżula. L-għażla ta’ ringiela hija differenti mill-attivazzjoni "
    L"tal-output permezz tal-kaxxa tal-marka. L-għażla tinżamm separatament għall-applikazzjoni u "
    L"għall-iscreen saver. Jekk il-moniters kollha kienu magħżula, il-moniters ġodda jiddaħħlu wkoll "
    L"fl-għażla.\r\n\r\nĦaddem FlyingSolids.exe. Is-settings jiġu ssejvjati kontinwament u taħdem istanza "
    L"waħda biss. Il-kaxxa tal-moniter jew klikk doppja fuq ir-ringiela tattiva jew tiddiżattiva l-output "
    L"tal-animazzjoni. Tista’ tissospendi u tkompli l-animazzjoni. PNG u MP4 jaqbdu l-ewwel moniter "
    L"tal-animazzjoni attiv, mhux immaġni magħquda tal-moniters kollha. Il-moniter li qed jiġi rreġistrat "
    L"ma jistax jiġi diżattivat; l-għeluq tal-applikazzjoni waqt reġistrazzjoni jeħtieġ konferma. "
    L"L-imblukkar tal-iscreen saver japplika għas-sessjoni kollha u biss waqt animazzjoni viżibbli mhux "
    L"sospiża fuq moniter bl-għażla attiva. L-applikazzjoni tinstalla jew tneħħi l-iscreen saver "
    L"inkorporat.\r\n\r\nFis-settings tar-reġistrazzjoni agħżel Viewport jew TV. Viewport iżomm "
    L"id-dimensjonijiet u r-rata ta’ aġġornament tal-moniter, sa 60 frejm kull sekonda. TV joffri 1920 × "
    L"1080, 1440 × 1080 jew 1280 × 720 f’16:9, b’50, 25, 59.94 (60000/1001) jew 29.97 (30000/1001) frejm "
    L"kull sekonda. Il-vidjo TV huwa progressiv BT.709, b’medda limitata u sottokampjunar tal-kulur 4:2:0. "
    L"Il-proporzjonijiet jinżammu u l-faxex ta’ mili huma suwed. OK isalva l-għażliet għar-reġistrazzjoni "
    L"li jmiss; Ikkanċella jew Esc jarmi bidliet mhux ikkonfermati. It-twieqi tar-reġistrazzjoni, Għajnuna "
    L"u Dwar ma jimblukkawx twieqi oħra u jistgħu jiġu minimizzati. Tab u Shift+Tab ibiddlu l-fokus, Enter "
    L"jattiva l-buttuna fil-fokus u Esc jagħlaq it-tieqa awżiljarja attiva.\r\n\r\nWindows 7–11 jappoġġja "
    L"l-funzjonijiet kollha. Fuq Windows Vista SP2 għandhom jiġu installati l-aġġornamenti KB971512 u "
    L"KB2117917; ir-reġistrazzjoni MP4 ma taħdimx fuq Vista. Huwa meħtieġ Direct3D 11 u, għall-MP4, Media "
    L"Foundation u encoder H.264. L-interface u d-dokumentazzjoni huma disponibbli f’36 lingwa.",
    L"FlyingSolids toont bewegende, draaiende en botsende driedimensionale lichamen. Kies ruimte observeren "
    L"of door de ruimte vliegen en schakel de gewenste lichamen in. Stel per beeldscherm de object- en "
    L"camerasnelheid in op 0–1600%, de objectgrootte op 50–200% en het aantal kopieën op 1–10 per lichaam. "
    L"Hoofdlicht, invullicht, omgevingslicht en randlicht zijn onafhankelijk schakelbaar.\r\n\r\nSelecteer "
    L"één of meer beeldschermrijen in de lijst. Ctrl+A selecteert alles; met Ctrl en Shift past u de "
    L"selectie aan. Animatieknoppen en schuifregelaars wijzigen alleen de instellingen van de geselecteerde "
    L"beeldschermen. Een rij selecteren is iets anders dan de animatie-uitvoer inschakelen met het "
    L"selectievakje. De selectie wordt apart onthouden voor de toepassing en de schermbeveiliging. Als alle "
    L"beeldschermen waren geselecteerd, worden nieuw aangesloten beeldschermen ook "
    L"geselecteerd.\r\n\r\nStart FlyingSolids.exe. Instellingen worden doorlopend opgeslagen en er draait "
    L"slechts één exemplaar van de toepassing. Het selectievakje of een dubbelklik op de beeldschermrij "
    L"schakelt de animatie-uitvoer in of uit. U kunt de animatie pauzeren en hervatten. PNG en MP4 leggen "
    L"het eerste actieve animatiebeeldscherm vast, niet een gecombineerd beeld van alle schermen. Het "
    L"opgenomen beeldscherm kan niet worden uitgeschakeld; afsluiten tijdens een opname vereist "
    L"bevestiging. Blokkering van de schermbeveiliging geldt voor de hele sessie, alleen zolang op een "
    L"beeldscherm met die optie een zichtbare, niet-gepauzeerde animatie draait. De toepassing kan de "
    L"ingebouwde schermbeveiliging installeren of verwijderen.\r\n\r\nKies Viewport of TV in de "
    L"opname-instellingen. Viewport behoudt de afmetingen en vernieuwingsfrequentie van het beeldscherm tot "
    L"60 frames per seconde. TV biedt 1920 × 1080, 1440 × 1080 of 1280 × 720 met beeldverhouding 16:9 en "
    L"50, 25, 59.94 (60000/1001) of 29.97 (30000/1001) frames per seconde. TV gebruikt progressieve "
    L"BT.709-video met beperkt bereik en 4:2:0-kleursubsampling. De beeldverhouding blijft behouden en "
    L"opvulbalken zijn zwart. OK bewaart de opties voor de volgende opname; Annuleren of Esc verwerpt "
    L"onbevestigde wijzigingen. Opname-instellingen, Help en Info blokkeren andere vensters niet en kunnen "
    L"worden geminimaliseerd. Tab en Shift+Tab verplaatsen de focus, Enter activeert de knop met focus en "
    L"Esc sluit het actieve hulpvenster.\r\n\r\nWindows 7–11 ondersteunt alle functies. Voor Windows Vista "
    L"SP2 moet u updates KB971512 en KB2117917 installeren; MP4-opname werkt niet op Vista. Direct3D "
    L"11-ondersteuning is vereist; voor MP4 zijn ook Media Foundation en een H.264-encoder nodig. Interface "
    L"en documentatie zijn beschikbaar in 36 talen.",
    L"FlyingSolids afișează corpuri tridimensionale care se deplasează, se rotesc și se ciocnesc. Alegeți "
    L"observarea spațiului sau zborul prin spațiu și activați corpurile dorite. Pentru fiecare monitor "
    L"puteți seta separat viteza obiectelor și a camerei între 0–1600%, dimensiunea între 50–200% și 1–10 "
    L"copii ale fiecărui corp. Lumina principală, de umplere, ambiantă și de contur se controlează "
    L"independent.\r\n\r\nSelectați unul sau mai multe rânduri din lista monitoarelor. Ctrl+A le selectează "
    L"pe toate; Ctrl și Shift modifică selecția. Comenzile și glisoarele animației schimbă numai setările "
    L"monitoarelor selectate. Selectarea unui rând diferă de activarea ieșirii prin caseta sa de selectare. "
    L"Selecția este reținută separat pentru aplicație și economizor. Dacă erau selectate toate monitoarele, "
    L"sunt incluse și cele conectate ulterior.\r\n\r\nRulați FlyingSolids.exe. Setările se salvează "
    L"continuu și rulează o singură instanță. Caseta monitorului sau un dublu clic pe rând activează ori "
    L"dezactivează ieșirea animației. Animația poate fi pusă în pauză și reluată. PNG și MP4 capturează "
    L"primul monitor de animație activ, nu imaginea combinată a tuturor monitoarelor. Monitorul înregistrat "
    L"nu poate fi dezactivat; închiderea aplicației în timpul înregistrării necesită confirmare. Blocarea "
    L"economizorului se aplică întregii sesiuni și numai cât timp pe un monitor cu această opțiune este "
    L"vizibilă o animație care nu este în pauză. Aplicația poate instala sau dezinstala economizorul "
    L"încorporat.\r\n\r\nÎn setările de înregistrare alegeți Viewport sau TV. Viewport păstrează "
    L"dimensiunile și rata de reîmprospătare a monitorului, până la 60 de cadre pe secundă. TV oferă 1920 × "
    L"1080, 1440 × 1080 sau 1280 × 720 în 16:9, la 50, 25, 59.94 (60000/1001) sau 29.97 (30000/1001) cadre "
    L"pe secundă. Videoul TV este progresiv BT.709, cu interval limitat și subeșantionare cromatică 4:2:0. "
    L"Proporțiile imaginii se păstrează, iar benzile de completare sunt negre. OK salvează opțiunile pentru "
    L"următoarea înregistrare; Anulare sau Esc renunță la schimbările neconfirmate. Ferestrele de "
    L"înregistrare, ajutor și informații nu blochează celelalte ferestre și pot fi minimizate. Tab și "
    L"Shift+Tab mută focalizarea, Enter activează butonul focalizat, iar Esc închide fereastra auxiliară "
    L"activă.\r\n\r\nWindows 7–11 acceptă toate funcțiile. Pentru Windows Vista SP2 trebuie instalate "
    L"actualizările KB971512 și KB2117917; înregistrarea MP4 nu funcționează pe Vista. Este necesar "
    L"Direct3D 11, iar pentru MP4 și Media Foundation și un codificator H.264. Interfața și documentația "
    L"sunt disponibile în 36 de limbi.",
    L"Το FlyingSolids εμφανίζει τρισδιάστατα στερεά που κινούνται, περιστρέφονται και συγκρούονται. "
    L"Επιλέξτε παρατήρηση χώρου ή πτήση στον χώρο και ενεργοποιήστε τα επιθυμητά στερεά. Ανά οθόνη "
    L"ρυθμίζονται ανεξάρτητα η ταχύτητα αντικειμένων και κάμερας 0–1600%, το μέγεθος 50–200% και 1–10 "
    L"αντίγραφα κάθε στερεού. Ο κύριος φωτισμός, ο φωτισμός πλήρωσης, ο περιβάλλων φωτισμός και ο φωτισμός "
    L"περιγράμματος ελέγχονται ανεξάρτητα.\r\n\r\nΕπιλέξτε μία ή περισσότερες γραμμές στη λίστα οθονών. Το "
    L"Ctrl+A επιλέγει όλες, ενώ τα Ctrl και Shift αλλάζουν την επιλογή. Τα χειριστήρια και τα ρυθμιστικά "
    L"της κίνησης αλλάζουν μόνο τις ρυθμίσεις των επιλεγμένων οθονών. Η επιλογή γραμμής διαφέρει από την "
    L"ενεργοποίηση εξόδου μέσω του πλαισίου ελέγχου της. Η επιλογή αποθηκεύεται χωριστά για την εφαρμογή "
    L"και την προφύλαξη. Αν είχαν επιλεγεί όλες οι οθόνες, περιλαμβάνονται και όσες συνδεθούν "
    L"αργότερα.\r\n\r\nΕκτελέστε το FlyingSolids.exe. Οι ρυθμίσεις αποθηκεύονται συνεχώς και εκτελείται "
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
    L"FlyingSolids prikazuje prostorna tijela koja se kreću, okreću i sudaraju. Odaberite posmatranje "
    L"prostora ili let kroz prostor te željena tijela. Za svaki monitor zasebno se podešavaju brzina "
    L"objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija svakog tijela. Glavno, dopunsko, "
    L"ambijentalno i konturno svjetlo uključuju se nezavisno.\r\n\r\nOdaberite jedan ili više redova u "
    L"listi monitora. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije "
    L"mijenjaju samo postavke odabranih monitora. Odabir reda nije isto što i uključivanje izlaza njegovom "
    L"kućicom. Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili odabrani svi "
    L"monitori, uključuju se i novopriključeni monitori.\r\n\r\nPokrenite FlyingSolids.exe. Postavke se "
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
    L"FlyingSolids prikazuje prostorna tijela koja se kreću, okreću i sudaraju. Odaberite promatranje "
    L"prostora ili let kroz prostor te željena tijela. Za svaki zaslon zasebno se podešavaju brzina "
    L"objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija svakog tijela. Glavno, dopunsko, "
    L"ambijentalno i konturno svjetlo uključuju se neovisno.\r\n\r\nOdaberite jedan ili više redaka na "
    L"popisu zaslona. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije "
    L"mijenjaju samo postavke odabranih zaslona. Odabir retka nije isto što i uključivanje izlaza njegovim "
    L"potvrdnim okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar zaslona. Ako su prethodno bili "
    L"odabrani svi zasloni, uključuju se i novopriključeni zasloni.\r\n\r\nPokrenite FlyingSolids.exe. "
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
    L"FlyingSolids prikazuje prostorska telesa, ki se premikajo, vrtijo in trkajo. Izberite opazovanje "
    L"prostora ali let skozi prostor in želena telesa. Za vsak zaslon so ločeno nastavljivi hitrost "
    L"predmetov in kamere 0–1600%, velikost 50–200% ter 1–10 kopij vsakega telesa. Glavna, dopolnilna, "
    L"okoljska in obrobna svetloba se vklapljajo neodvisno.\r\n\r\nNa seznamu zaslonov izberite eno ali več "
    L"vrstic. Ctrl+A izbere vse, Ctrl in Shift pa spreminjata izbor. Kontrolniki in drsniki animacije "
    L"spreminjajo samo nastavitve izbranih zaslonov. Izbira vrstice ni isto kot vklop izhoda z njenim "
    L"potrditvenim poljem. Izbor se ločeno shrani za program in ohranjevalnik. Če so bili izbrani vsi "
    L"zasloni, so vključeni tudi na novo priključeni zasloni.\r\n\r\nZaženite FlyingSolids.exe. Nastavitve "
    L"se shranjujejo sproti in deluje le en primerek programa. Polje zaslona ali dvojni klik na vrstico "
    L"vklopi ali izklopi izhod animacije. Animacijo lahko začasno ustavite in nadaljujete. PNG in MP4 "
    L"zajameta prvi aktivni zaslon animacije, ne skupne slike vseh zaslonov. Snemanega zaslona ni mogoče "
    L"izklopiti; zapiranje programa med snemanjem zahteva potrditev. Preprečevanje ohranjevalnika velja za "
    L"celotno sejo in le, dokler je na zaslonu s to možnostjo vidna neustavljena animacija. Program lahko "
    L"namesti ali odstrani vgrajeni ohranjevalnik.\r\n\r\nV nastavitvah snemanja izberite Viewport ali TV. "
    L"Viewport ohrani velikost in hitrost osveževanja zaslona do 60 sličic na sekundo. TV ponuja 1920 × "
    L"1080, 1440 × 1080 ali 1280 × 720 v razmerju 16:9 ter 50, 25, 59.94 (60000/1001) ali 29.97 "
    L"(30000/1001) sličic na sekundo. TV uporablja progresivni BT.709 z omejenim obsegom in barvnim "
    L"podvzorčenjem 4:2:0. Razmerje slike se ohrani, dopolnilni pasovi so črni. OK shrani izbiro za "
    L"naslednje snemanje; Prekliči ali Esc zavrže nepotrjene spremembe. Okna snemanja, pomoči in podatkov o "
    L"programu ne blokirajo drugih oken in jih je mogoče minimirati. Tab in Shift+Tab premikata fokus, "
    L"Enter aktivira izbrani gumb, Esc pa zapre aktivno pomožno okno.\r\n\r\nWindows 7–11 podpira vse "
    L"funkcije. Za Windows Vista SP2 morate namestiti posodobitvi KB971512 in KB2117917; snemanje MP4 v "
    L"Visti ne deluje. Potrebna je podpora Direct3D 11, za MP4 pa še Media Foundation in kodirnik H.264. "
    L"Vmesnik in dokumentacija sta na voljo v 36 jezikih.",
    L"FlyingSolids prikazuje prostorna tijela koja se kreću, okreću i sudaraju. Izaberite posmatranje "
    L"prostora ili let kroz prostor te željena tijela. Za svaki monitor zasebno se podešavaju brzina "
    L"objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija svakog tijela. Glavno, dopunsko, "
    L"ambijentalno i konturno svjetlo uključuju se nezavisno.\r\n\r\nIzaberite jedan ili više redova u "
    L"listi monitora. Ctrl+A bira sve; Ctrl i Shift mijenjaju izbor. Kontrole i klizači animacije mijenjaju "
    L"samo podešavanja izabranih monitora. Izbor reda nije isto što i uključivanje izlaza njegovom kućicom. "
    L"Izbor se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili izabrani svi monitori, "
    L"uključuju se i novopriključeni monitori.\r\n\r\nPokrenite FlyingSolids.exe. Podešavanja se stalno "
    L"čuvaju i radi samo jedna instanca aplikacije. Kućica monitora ili dvostruki klik na red uključuje ili "
    L"isključuje animacijski izlaz. Animaciju možete pauzirati i nastaviti. PNG i MP4 bilježe prvi aktivni "
    L"monitor animacije, ne zajedničku sliku svih monitora. Snimani monitor ne možete isključiti; "
    L"zatvaranje aplikacije tokom snimanja zahtijeva potvrdu. Blokada čuvara ekrana važi za cijelu sesiju i "
    L"samo dok je na monitoru s uključenom tom opcijom vidljiva animacija koja nije pauzirana. Aplikacija "
    L"može instalirati i deinstalirati ugrađeni čuvar ekrana.\r\n\r\nU podešavanjima snimanja izaberite "
    L"Viewport ili TV. Viewport zadržava dimenzije i frekvenciju monitora do 60 kadrova u sekundi. TV nudi "
    L"1920 × 1080, 1440 × 1080 ili 1280 × 720 u odnosu 16:9, s 50, 25, 59.94 (60000/1001) ili 29.97 "
    L"(30000/1001) kadrova u sekundi. TV video je progresivni BT.709 ograničenog opsega s poduzorkovanjem "
    L"boje 4:2:0. Odnos slike ostaje sačuvan, a dopunske trake su crne. OK čuva opcije za sljedeći snimak; "
    L"Otkaži ili Esc odbacuje nepotvrđene izmjene. Prozori snimanja, pomoći i informacija ne blokiraju "
    L"ostale prozore i mogu se minimizovati. Tab i Shift+Tab pomjeraju fokus, Enter aktivira fokusirano "
    L"dugme, a Esc zatvara aktivni pomoćni prozor.\r\n\r\nWindows 7–11 podržava sve funkcije. Za Windows "
    L"Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban "
    L"je Direct3D 11, a za MP4 i Media Foundation i H.264 koder. Interfejs i dokumentacija dostupni su na "
    L"36 jezika.",
    L"FlyingSolids паказвае аб’ёмныя целы, якія рухаюцца, круцяцца і сутыкаюцца. Выберыце назіранне за "
    L"прасторай або палёт праз яе і патрэбныя целы. Для кожнага манітора асобна задаюцца хуткасці аб’ектаў "
    L"і камеры 0–1600%, памер 50–200% і 1–10 копій кожнага цела. Асноўнае, запаўняльнае, фонавае і "
    L"контурнае святло ўключаюцца незалежна.\r\n\r\nВыберыце адзін або некалькі радкоў у спісе манітораў. "
    L"Ctrl+A выбірае ўсе; Ctrl і Shift змяняюць выбар. Элементы кіравання і паўзункі анімацыі змяняюць "
    L"толькі налады выбраных манітораў. Выбар радка і ўключэнне вываду яго сцяжком — розныя дзеянні. Выбар "
    L"асобна захоўваецца для праграмы і застаўкі. Калі раней былі выбраны ўсе маніторы, да выбару "
    L"далучаюцца і новыя маніторы.\r\n\r\nЗапусціце FlyingSolids.exe. Налады захоўваюцца пастаянна, працуе "
    L"толькі адзін асобнік праграмы. Сцяжок манітора або падвойнае націсканне на радок уключае ці выключае "
    L"вывад анімацыі. Анімацыю можна прыпыніць і працягнуць. PNG і MP4 захопліваюць першы актыўны манітор "
    L"анімацыі, а не агульны відарыс усіх манітораў. Манітор, які запісваецца, нельга выключыць; закрыццё "
    L"праграмы падчас запісу патрабуе пацвярджэння. Блакаванне застаўкі дзейнічае на ўсю сесію і толькі "
    L"пакуль на маніторы з гэтай опцыяй бачная непрыпыненая анімацыя. Праграма можа ўсталяваць або выдаліць "
    L"убудаваную застаўку.\r\n\r\nУ наладах запісу выберыце Viewport або TV. Viewport захоўвае памеры і "
    L"частату манітора да 60 кадраў за секунду. TV прапануе 1920 × 1080, 1440 × 1080 або 1280 × 720 з "
    L"суадносінамі 16:9 і частатой 50, 25, 59.94 (60000/1001) або 29.97 (30000/1001) кадраў за секунду. "
    L"Відэа TV прагрэсіўнае, BT.709, з абмежаваным дыяпазонам і субдыскрэтызацыяй колеру 4:2:0. Прапорцыі "
    L"захоўваюцца, палосы запаўнення чорныя. OK захоўвае выбар для наступнага запісу; Скасаваць або Esc "
    L"адхіляе непацверджаныя змены. Вокны запісу, даведкі і звестак пра праграму не блакуюць іншыя вокны і "
    L"могуць згортвацца. Tab і Shift+Tab перамяшчаюць фокус, Enter націскае актыўную кнопку, Esc закрывае "
    L"актыўнае дапаможнае акно.\r\n\r\nWindows 7–11 падтрымлівае ўсе функцыі. Для Windows Vista SP2 "
    L"неабходна ўсталяваць абнаўленні KB971512 і KB2117917; запіс MP4 у Vistа не працуе. Патрэбна падтрымка "
    L"Direct3D 11, а для MP4 таксама Media Foundation і кадавальнік H.264. Інтэрфейс і дакументацыя "
    L"даступны на 36 мовах.",
    L"FlyingSolids показва обемни тела, които се движат, въртят и сблъскват. Изберете наблюдение на "
    L"пространството или полет през него и желаните тела. За всеки монитор отделно се задават скорост на "
    L"обектите и камерата 0–1600%, размер 50–200% и 1–10 копия на всяко тяло. Основната, запълващата, "
    L"околната и контурната светлина се включват независимо.\r\n\r\nИзберете един или повече редове в "
    L"списъка с монитори. Ctrl+A избира всички; Ctrl и Shift променят избора. Контролите и плъзгачите на "
    L"анимацията променят само настройките на избраните монитори. Избирането на ред и включването на изхода "
    L"чрез отметката му са различни действия. Изборът се запомня отделно за приложението и скрийнсейвъра. "
    L"Ако са били избрани всички монитори, включват се и новосвързаните.\r\n\r\nСтартирайте "
    L"FlyingSolids.exe. Настройките се запазват непрекъснато и работи само един екземпляр на приложението. "
    L"Отметката на монитора или двойно щракване върху реда включва или изключва анимационния изход. "
    L"Анимацията може да се поставя на пауза и да продължава. PNG и MP4 заснемат първия активен монитор за "
    L"анимация, не общ образ от всички монитори. Записваният монитор не може да се изключи; затварянето на "
    L"приложението при запис изисква потвърждение. Блокирането на скрийнсейвъра важи за цялата сесия и само "
    L"докато на монитор с тази опция има видима анимация без пауза. Приложението може да инсталира и "
    L"деинсталира вградения скрийнсейвър.\r\n\r\nВ настройките за запис изберете Viewport или TV. Viewport "
    L"запазва размерите и честотата на монитора до 60 кадъра в секунда. TV предлага 1920 × 1080, 1440 × "
    L"1080 или 1280 × 720 със съотношение 16:9 и 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) кадъра в "
    L"секунда. TV използва прогресивно видео BT.709 с ограничен диапазон и цветова субдискретизация 4:2:0. "
    L"Пропорциите се запазват, допълващите ленти са черни. OK запазва избора за следващия запис; Отказ или "
    L"Esc отхвърля непотвърдените промени. Прозорците за запис, помощ и информация не блокират другите "
    L"прозорци и могат да се минимизират. Tab и Shift+Tab преместват фокуса, Enter активира фокусирания "
    L"бутон, Esc затваря активния помощен прозорец.\r\n\r\nWindows 7–11 поддържа всички функции. За Windows "
    L"Vista SP2 трябва да се инсталират актуализациите KB971512 и KB2117917; записът на MP4 не работи във "
    L"Vista. Изисква се поддръжка на Direct3D 11, а за MP4 също Media Foundation и H.264 кодер. Интерфейсът "
    L"и документацията са налични на 36 езика.",
    L"FlyingSolids прикажува просторни тела што се движат, вртат и судираат. Изберете набљудување на "
    L"просторот или лет низ него и саканите тела. За секој монитор одделно се поставуваат брзината на "
    L"објектите и камерата 0–1600%, големината 50–200% и 1–10 копии од секое тело. Главното, "
    L"дополнителното, амбиенталното и контурното светло се вклучуваат независно.\r\n\r\nИзберете еден или "
    L"повеќе редови во списокот на монитори. Ctrl+A ги избира сите; Ctrl и Shift го менуваат изборот. "
    L"Контролите и лизгачите на анимацијата ги менуваат само поставките на избраните монитори. Избирањето "
    L"ред и вклучувањето на излезот преку неговото поле се различни дејства. Изборот се памети одделно за "
    L"апликацијата и чуварот. Ако биле избрани сите монитори, се вклучуваат и новоповрзаните "
    L"монитори.\r\n\r\nСтартувајте FlyingSolids.exe. Поставките се зачувуваат постојано и работи само еден "
    L"примерок на апликацијата. Полето на мониторот или двоен клик на редот го вклучува или исклучува "
    L"анимацискиот излез. Анимацијата може да се паузира и продолжи. PNG и MP4 го снимаат првиот активен "
    L"монитор за анимација, не заедничка слика од сите монитори. Мониторот што се снима не може да се "
    L"исклучи; затворањето на апликацијата при снимање бара потврда. Блокирањето на чуварот важи за целата "
    L"сесија и само додека на монитор со таа опција е видлива непаузирана анимација. Апликацијата може да "
    L"го инсталира и деинсталира вградениот чувар.\r\n\r\nВо поставките за снимање изберете Viewport или "
    L"TV. Viewport ги зачувува димензиите и стапката на мониторот до 60 кадри во секунда. TV нуди 1920 × "
    L"1080, 1440 × 1080 или 1280 × 720 со однос 16:9 и 50, 25, 59.94 (60000/1001) или 29.97 (30000/1001) "
    L"кадри во секунда. TV видеото е прогресивно BT.709 со ограничен опсег и подсемплирање на боја 4:2:0. "
    L"Пропорциите се задржуваат, дополнителните ленти се црни. OK ги зачувува опциите за следното снимање; "
    L"Откажи или Esc ги отфрла непотврдените измени. Прозорците за снимање, помош и информации не ги "
    L"блокираат другите прозорци и може да се минимизираат. Tab и Shift+Tab го поместуваат фокусот, Enter "
    L"го активира фокусираното копче, Esc го затвора активниот помошен прозорец.\r\n\r\nWindows 7–11 ги "
    L"поддржува сите функции. За Windows Vista SP2 мора да се инсталираат ажурирањата KB971512 и KB2117917; "
    L"MP4 снимањето на Vista не работи. Потребна е поддршка за Direct3D 11, а за MP4 и Media Foundation и "
    L"H.264 кодер. Интерфејсот и документацијата се достапни на 36 јазици.",
    L"FlyingSolids приказује просторна тела која се крећу, окрећу и сударају. Изаберите посматрање простора "
    L"или лет кроз простор и жељена тела. За сваки монитор посебно се подешавају брзина објеката и камере "
    L"0–1600%, величина 50–200% и 1–10 копија сваког тела. Главно, допунско, амбијентално и контурно светло "
    L"укључују се независно.\r\n\r\nИзаберите један или више редова у листи монитора. Ctrl+A бира све; Ctrl "
    L"и Shift мењају избор. Контроле и клизачи анимације мењају само подешавања изабраних монитора. Избор "
    L"реда није исто што и укључивање излаза његовим пољем за потврду. Избор се памти одвојено за "
    L"апликацију и чувар екрана. Ако су претходно били изабрани сви монитори, укључују се и новоприкључени "
    L"монитори.\r\n\r\nПокрените FlyingSolids.exe. Подешавања се стално чувају и ради само једна инстанца "
    L"апликације. Поље монитора или двоструки клик на ред укључује или искључује анимацијски излаз. "
    L"Анимацију можете паузирати и наставити. PNG и MP4 бележе први активни монитор анимације, не "
    L"заједничку слику свих монитора. Снимани монитор не можете искључити; затварање апликације током "
    L"снимања захтева потврду. Блокада чувара екрана важи за целу сесију и само док је на монитору с "
    L"укљученом том опцијом видљива анимација која није паузирана. Апликација може инсталирати и "
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
    L"FlyingSolids показує об’ємні тіла, які рухаються, обертаються й стикаються. Виберіть спостереження за "
    L"простором або політ крізь нього та потрібні тіла. Для кожного монітора окремо задаються швидкості "
    L"об’єктів і камери 0–1600%, розмір 50–200% та 1–10 копій кожного тіла. Основне, заповнювальне, фонове "
    L"й контурне світло вмикаються незалежно.\r\n\r\nВиберіть один або кілька рядків у списку моніторів. "
    L"Ctrl+A вибирає всі; Ctrl і Shift змінюють вибір. Елементи керування й повзунки анімації змінюють лише "
    L"налаштування вибраних моніторів. Вибір рядка та ввімкнення виведення його прапорцем — різні дії. "
    L"Вибір зберігається окремо для програми й заставки. Якщо раніше були вибрані всі монітори, до вибору "
    L"долучаються й новопідключені.\r\n\r\nЗапустіть FlyingSolids.exe. Налаштування зберігаються постійно, "
    L"працює лише один екземпляр програми. Прапорець монітора або подвійне клацання рядка вмикає чи вимикає "
    L"виведення анімації. Анімацію можна призупинити та продовжити. PNG і MP4 захоплюють перший активний "
    L"монітор анімації, а не спільне зображення всіх моніторів. Монітор, який записується, вимкнути не "
    L"можна; закриття програми під час запису потребує підтвердження. Блокування заставки діє для всього "
    L"сеансу й лише доки на моніторі з цією опцією видима непризупинена анімація. Програма може встановити "
    L"або видалити вбудовану заставку.\r\n\r\nУ налаштуваннях запису виберіть Viewport або TV. Viewport "
    L"зберігає розміри та частоту монітора до 60 кадрів за секунду. TV пропонує 1920 × 1080, 1440 × 1080 "
    L"або 1280 × 720 зі співвідношенням 16:9 і частотою 50, 25, 59.94 (60000/1001) або 29.97 (30000/1001) "
    L"кадрів за секунду. Відео TV прогресивне, BT.709, з обмеженим діапазоном і субдискретизацією кольору "
    L"4:2:0. Пропорції зберігаються, смуги заповнення чорні. OK зберігає вибір для наступного запису; "
    L"Скасувати або Esc відхиляє непідтверджені зміни. Вікна запису, довідки та відомостей не блокують інші "
    L"вікна й можуть згортатися. Tab і Shift+Tab переміщують фокус, Enter активує кнопку з фокусом, Esc "
    L"закриває активне допоміжне вікно.\r\n\r\nWindows 7–11 підтримує всі функції. Для Windows Vista SP2 "
    L"потрібно встановити оновлення KB971512 і KB2117917; запис MP4 у Vista не працює. Потрібна підтримка "
    L"Direct3D 11, а для MP4 також Media Foundation й кодувальник H.264. Інтерфейс і документація доступні "
    L"36 мовами.",
    L"FlyingSolids показывает объёмные тела, которые движутся, вращаются и сталкиваются. Выберите "
    L"наблюдение за пространством или полёт сквозь него и нужные тела. Для каждого монитора отдельно "
    L"задаются скорости объектов и камеры 0–1600%, размер 50–200% и 1–10 копий каждого тела. Основной, "
    L"заполняющий, фоновый и контурный свет включаются независимо.\r\n\r\nВыберите одну или несколько строк "
    L"в списке мониторов. Ctrl+A выбирает все; Ctrl и Shift изменяют выбор. Элементы управления и ползунки "
    L"анимации изменяют только настройки выбранных мониторов. Выбор строки и включение вывода её флажком — "
    L"разные действия. Выбор сохраняется отдельно для приложения и заставки. Если раньше были выбраны все "
    L"мониторы, в выбор включаются и вновь подключённые.\r\n\r\nЗапустите FlyingSolids.exe. Настройки "
    L"сохраняются постоянно, работает только один экземпляр приложения. Флажок монитора или двойной щелчок "
    L"по строке включает либо выключает вывод анимации. Анимацию можно приостановить и продолжить. PNG и "
    L"MP4 захватывают первый активный монитор анимации, а не общее изображение всех мониторов. Записываемый "
    L"монитор нельзя отключить; закрытие приложения во время записи требует подтверждения. Блокировка "
    L"заставки действует на весь сеанс и только пока на мониторе с этой опцией видима неприостановленная "
    L"анимация. Приложение может установить или удалить встроенную заставку.\r\n\r\nВ настройках записи "
    L"выберите Viewport или TV. Viewport сохраняет размеры и частоту монитора до 60 кадров в секунду. TV "
    L"предлагает 1920 × 1080, 1440 × 1080 или 1280 × 720 с соотношением 16:9 и частотой 50, 25, 59.94 "
    L"(60000/1001) или 29.97 (30000/1001) кадров в секунду. Видео TV прогрессивное, BT.709, с ограниченным "
    L"диапазоном и субдискретизацией цвета 4:2:0. Пропорции сохраняются, полосы заполнения чёрные. OK "
    L"сохраняет выбор для следующей записи; Отмена или Esc отклоняет неподтверждённые изменения. Окна "
    L"записи, справки и сведений не блокируют другие окна и могут сворачиваться. Tab и Shift+Tab перемещают "
    L"фокус, Enter активирует кнопку с фокусом, Esc закрывает активное вспомогательное окно.\r\n\r\nWindows "
    L"7–11 поддерживает все функции. Для Windows Vista SP2 необходимо установить обновления KB971512 и "
    L"KB2117917; запись MP4 в Vista не работает. Нужна поддержка Direct3D 11, а для MP4 также Media "
    L"Foundation и кодировщик H.264. Интерфейс и документация доступны на 36 языках."
};

constexpr std::array<const wchar_t*, LANGUAGE_COUNT> SCREEN_SAVER_HELP_TEXTS = {
    L"V seznamu označte jeden nebo více monitorů. Režim kamery, výběr těles, světla, rychlosti, velikost a "
    L"počet kopií se nastavují jen pro označené monitory a každý monitor si pamatuje vlastní nastavení. "
    L"Vyberte Pozorování prostoru nebo přímý Průlet prostorem. Jezdci nastavují rychlost objektů a kamery "
    L"0–1600 %, jednu až deset kopií každého zapnutého tělesa a velikost 50–200 %. Zatržítka Hlavní světlo, "
    L"Doplňkové světlo, Základní jas a Přisvětlení obrysů pod jezdci nezávisle ovládají osvětlení celé "
    L"scény. Základní jas přisvětluje povrch těles, přisvětlení obrysů zvýrazňuje jejich okraje. Nastavení "
    L"osvětlení se ukládá zvlášť pro aplikaci a spořič obrazovky.\r\n\r\nOznačení řádků určuje, které "
    L"monitory právě nastavujete; není totožné se zatržítky zapínajícími animační výstupy. Ctrl+A označí "
    L"všechny monitory, Ctrl a Shift umožňují upravit označení. Všechny animační volby a jezdce platí pro "
    L"označené monitory. Označení se pamatuje zvlášť pro EXE a SCR. Pokud byly označené všechny monitory, "
    L"označí se i nově připojené.\r\n\r\nZapněte požadované druhy těles. Zapnout náhled spustí "
    L"celoobrazovkový náhled na všech monitorech; změny lze zkoušet za otevřeného nastavení. OK nastavení "
    L"uloží, Storno je zahodí. Celoobrazovkový spořič ukončíte klávesou Esc nebo pohybem myši. Mezi "
    L"ovládacími prvky přecházejte klávesami Tab a Shift+Tab; podtržené volby lze vyvolat pomocí Alt a "
    L"příslušného písmene. Esc v nastavení odpovídá tlačítku Storno; v nápovědě nebo okně O aplikaci zavře "
    L"pouze toto okno.\r\n\r\nPodporovány jsou systémy Windows 7 až Windows 11. Pro spuštění aplikace ve "
    L"Windows Vista SP2 je nutné nainstalovat aktualizace KB971512 a KB2117917.",
    L"Select one or more displays in the list. Camera mode, object selection, lighting, speeds, size and "
    L"copy count apply only to the selected displays, and each display remembers its own settings. Choose "
    L"Space observation or the straight Fly through space mode. The sliders set object and camera speed "
    L"from 0–1600%, one to ten copies of each enabled object, and size from 50–200%. The Main light, Fill "
    L"light, Ambient light, and Rim light checkboxes below the sliders independently control lighting for "
    L"the whole scene. Ambient light provides base illumination of object surfaces; rim light highlights "
    L"their edges. Lighting settings are stored separately for the application and screen saver.\r\n\r\nRow "
    L"selection determines which displays you are editing; it is separate from the checkboxes that enable "
    L"animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation "
    L"options and sliders apply to the selected displays. The selection is remembered separately for EXE "
    L"and SCR. If all displays were selected, newly connected displays join the selection.\r\n\r\nEnable "
    L"the required object types. Enable preview starts a full-screen preview on every display while the "
    L"settings dialog remains open for live adjustments. OK saves the settings and Cancel discards them. "
    L"Exit the full-screen saver with Esc or mouse movement. Use Tab and Shift+Tab to move between "
    L"controls; use Alt and the underlined letter to activate a command. Esc in the settings dialog is "
    L"equivalent to Cancel; in Help or About, it closes only that window.\r\n\r\nWindows 7 through Windows "
    L"11 are supported. To run the application on Windows Vista SP2, you must install updates KB971512 and "
    L"KB2117917.",
    L"Select one or more displays in the list. Camera mode, object selection, lighting, speeds, size and "
    L"copy count apply only to the selected displays, and each display remembers its own settings. Choose "
    L"Space observation or the straight Fly through space mode. Set object and camera speed from 0–1600%, "
    L"one to ten copies and size from 50–200%, then enable the required objects. The Main light, Fill "
    L"light, Ambient light, and Rim light checkboxes below the sliders independently control lighting for "
    L"the whole scene. Ambient light provides base illumination of object surfaces; rim light highlights "
    L"their edges. Lighting settings are stored separately for the application and screen saver.\r\n\r\nRow "
    L"selection determines which displays you are editing; it is separate from the checkboxes that enable "
    L"animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation "
    L"options and sliders apply to the selected displays. The selection is remembered separately for EXE "
    L"and SCR. If all displays were selected, newly connected displays join the selection.\r\n\r\nEnable "
    L"preview starts a full-screen preview on every display while the settings dialog remains open for live "
    L"adjustments. OK saves the settings and Cancel discards them. Exit the full-screen screen saver with "
    L"Esc or mouse movement. Use Tab and Shift+Tab to move between controls; use Alt and the underlined "
    L"letter to activate a command. Esc in the settings dialog is equivalent to Cancel; in Help or About, "
    L"it closes only that window.\r\n\r\nWindows 7 through Windows 11 are supported. To run the application "
    L"on Windows Vista SP2, you must install updates KB971512 and KB2117917.",
    L"Select one or more displays in the list. Camera mode, object selection, lighting, speeds, size and "
    L"copy count apply only to the selected displays, and each display remembers its own settings. Choose "
    L"Space observation or the straight Fly through space mode. Set object and camera speed from 0–1600%, "
    L"one to ten copies and size from 50–200%, then enable the required objects. The Main light, Fill "
    L"light, Ambient light, and Rim light checkboxes below the sliders independently control lighting for "
    L"the whole scene. Ambient light provides base illumination of object surfaces; rim light highlights "
    L"their edges. Lighting settings are stored separately for the application and screen saver.\r\n\r\nRow "
    L"selection determines which displays you are editing; it is separate from the checkboxes that enable "
    L"animation outputs. Ctrl+A selects every display; Ctrl and Shift adjust the selection. All animation "
    L"options and sliders apply to the selected displays. The selection is remembered separately for EXE "
    L"and SCR. If all displays were selected, newly connected displays join the selection.\r\n\r\nEnable "
    L"preview starts a full-screen preview on every display while the settings dialog remains open for live "
    L"adjustments. OK saves the settings and Cancel discards them. Exit the full-screen screen saver with "
    L"Esc or mouse movement. Use Tab and Shift+Tab to move between controls; use Alt and the underlined "
    L"letter to activate a command. Esc in the settings dialog is equivalent to Cancel; in Help or About, "
    L"it closes only that window.\r\n\r\nWindows 7 through Windows 11 are supported. To run the application "
    L"on Windows Vista SP2, you must install updates KB971512 and KB2117917.",
    L"Markieren Sie einen oder mehrere Monitore in der Liste. Kameramodus, Körperauswahl, Beleuchtung, "
    L"Geschwindigkeiten, Größe und Anzahl der Exemplare gelten nur für die markierten Monitore. Jeder "
    L"Monitor speichert seine eigenen Einstellungen. Wählen Sie Raumbeobachtung oder Flug durch den Raum in "
    L"gerader Linie. Die Regler bestimmen Objekt- und Kamerageschwindigkeit von 0–1600 %, ein bis zehn "
    L"Exemplare je aktivem Körper und 50–200 % Größe. Die Kontrollkästchen Hauptlicht, Aufhelllicht, "
    L"Umgebungslicht und Konturlicht unter den Reglern steuern die Beleuchtung der gesamten Szene "
    L"unabhängig voneinander. Umgebungslicht sorgt für eine Grundhelligkeit der Körperoberflächen, "
    L"Konturlicht betont ihre Ränder. Die Beleuchtungseinstellungen werden für Anwendung und "
    L"Bildschirmschoner getrennt gespeichert.\r\n\r\nDie Zeilenauswahl bestimmt, welche Monitore Sie "
    L"bearbeiten; sie ist von den Kontrollkästchen zum Einschalten der Animationsausgabe getrennt. Strg+A "
    L"wählt alle Monitore, Strg und Umschalt ändern die Auswahl. Alle Animationsoptionen und Regler gelten "
    L"für die ausgewählten Monitore. Die Auswahl wird für EXE und SCR getrennt gespeichert. Waren alle "
    L"Monitore ausgewählt, werden auch neu angeschlossene ausgewählt.\r\n\r\nAktivieren Sie die gewünschten "
    L"Körper. Vorschau einschalten startet eine Vollbildvorschau auf allen Monitoren. Der "
    L"Einstellungsdialog bleibt für Änderungen geöffnet. OK speichert, Abbrechen verwirft. Esc oder eine "
    L"Mausbewegung beendet den Vollbildschoner. Mit Tab und Umschalt+Tab wechseln Sie zwischen den "
    L"Steuerelementen; mit Alt und dem unterstrichenen Buchstaben rufen Sie einen Befehl auf. Esc im "
    L"Einstellungsdialog entspricht Abbrechen; in der Hilfe oder im Infofenster schließt es nur dieses "
    L"Fenster.\r\n\r\nUnterstützt werden Windows 7 bis Windows 11. Zum Ausführen der Anwendung unter "
    L"Windows Vista SP2 müssen die Updates KB971512 und KB2117917 installiert werden.",
    L"Sélectionnez un ou plusieurs écrans dans la liste. Le mode de caméra, les objets, l’éclairage, les "
    L"vitesses, la taille et le nombre de copies ne s’appliquent qu’aux écrans sélectionnés. Chaque écran "
    L"mémorise ses propres réglages. Choisissez Observation de l’espace ou le Vol dans l’espace rectiligne. "
    L"Les curseurs règlent la vitesse des objets et de la caméra de 0 à 1 600 %, une à dix copies et une "
    L"taille de 50 à 200 %. Les cases Éclairage principal, Éclairage d’appoint, Éclairage ambiant et "
    L"Éclairage des contours sous les curseurs contrôlent indépendamment l’éclairage de toute la scène. "
    L"L’éclairage ambiant fournit une luminosité de base aux surfaces, et l’éclairage des contours souligne "
    L"leurs bords. Les réglages sont enregistrés séparément pour l’application et l’économiseur "
    L"d’écran.\r\n\r\nLa sélection des lignes détermine les écrans à configurer ; elle est distincte des "
    L"cases qui activent les sorties d’animation. Ctrl+A sélectionne tous les écrans ; Ctrl et Maj "
    L"modifient la sélection. Toutes les options et tous les curseurs d’animation concernent les écrans "
    L"sélectionnés. La sélection est mémorisée séparément pour EXE et SCR. Si tous les écrans étaient "
    L"sélectionnés, les nouveaux le sont également.\r\n\r\nActivez les solides voulus. Activer l’aperçu "
    L"lance un aperçu plein écran sur tous les moniteurs ; la boîte de dialogue reste ouverte pour les "
    L"réglages en direct. OK enregistre les réglages, Annuler les abandonne. Échap ou un mouvement de "
    L"souris quitte le plein écran. Utilisez Tab et Maj+Tab pour passer d’un contrôle à l’autre ; Alt et la "
    L"lettre soulignée activent une commande. Échap dans les réglages équivaut à Annuler ; dans l’aide ou À "
    L"propos, cette touche ferme uniquement cette fenêtre.\r\n\r\nWindows 7 à Windows 11 sont pris en "
    L"charge. Pour exécuter l’application sous Windows Vista SP2, il est nécessaire d’installer les mises à "
    L"jour KB971512 et KB2117917.",
    L"Seleccione una o varias pantallas en la lista. El modo de cámara, los objetos, la iluminación, las "
    L"velocidades, el tamaño y el número de copias se aplican solo a las pantallas seleccionadas. Cada "
    L"pantalla guarda sus propios ajustes. Elija Observación del espacio o Vuelo por el espacio en línea "
    L"recta. Los controles ajustan la velocidad de objetos y cámara del 0 al 1600 %, de una a diez copias y "
    L"el tamaño del 50 al 200 %. Las casillas Luz principal, Luz de relleno, Luz ambiental e Iluminación de "
    L"contornos bajo los controles deslizantes controlan de forma independiente la iluminación de toda la "
    L"escena. La luz ambiental aporta iluminación básica a las superficies y la iluminación de contornos "
    L"resalta sus bordes. De forma predeterminada, las luces principal, ambiental y de contornos están "
    L"activadas, y la luz de relleno está desactivada. Los ajustes se guardan por separado para la "
    L"aplicación y el salvapantallas.\r\n\r\nLa selección de filas determina qué pantallas se están "
    L"configurando; es independiente de las casillas que activan las salidas de animación. Ctrl+A "
    L"selecciona todas; Ctrl y Mayús modifican la selección. Todas las opciones y los controles deslizantes "
    L"de animación se aplican a las pantallas seleccionadas. La selección se recuerda por separado para EXE "
    L"y SCR. Si estaban seleccionadas todas, se incluyen también las nuevas.\r\n\r\nActive los sólidos "
    L"deseados. Activar vista previa inicia una vista previa a pantalla completa en todos los monitores; el "
    L"cuadro de configuración permanece abierto para realizar ajustes en tiempo real. Aceptar guarda y "
    L"Cancelar descarta. Esc o mover el ratón cierra el salvapantallas completo. Use Tab y Mayús+Tab para "
    L"desplazarse entre controles; Alt y la letra subrayada activan una opción. Esc en la configuración "
    L"equivale a Cancelar; en Ayuda o Acerca de, cierra únicamente esa ventana.\r\n\r\nSe admiten Windows 7 "
    L"a Windows 11. Para ejecutar la aplicación en Windows Vista SP2, es necesario instalar las "
    L"actualizaciones KB971512 y KB2117917.",
    L"Selezionare uno o più monitor nell’elenco. La modalità della telecamera, gli oggetti, le luci, le "
    L"velocità, le dimensioni e il numero di copie si applicano solo ai monitor selezionati. Ogni monitor "
    L"conserva le proprie impostazioni. Scegliere Osservazione dello spazio o Volo nello spazio rettilineo. "
    L"I cursori regolano la velocità di oggetti e camera da 0 a 1600 %, da una a dieci copie e la "
    L"dimensione da 50 a 200 %. Le caselle Luce principale, Luce di riempimento, Luce ambientale e "
    L"Illuminazione dei contorni sotto i cursori controllano indipendentemente l’illuminazione dell’intera "
    L"scena. La luce ambientale fornisce un’illuminazione di base alle superfici, mentre quella dei "
    L"contorni ne evidenzia i bordi. Le impostazioni vengono salvate separatamente per l’applicazione e il "
    L"salvaschermo.\r\n\r\nLa selezione delle righe determina quali schermi si stanno configurando ed è "
    L"distinta dalle caselle che attivano le uscite di animazione. Ctrl+A seleziona tutti gli schermi; Ctrl "
    L"e Maiusc modificano la selezione. Tutte le opzioni e i cursori dell’animazione riguardano gli schermi "
    L"selezionati. La selezione viene memorizzata separatamente per EXE e SCR. Se erano selezionati tutti "
    L"gli schermi, vengono inclusi anche quelli nuovi.\r\n\r\nAttivare i solidi desiderati. Attiva "
    L"anteprima avvia un’anteprima a schermo intero su tutti i monitor; le impostazioni rimangono aperte "
    L"per le modifiche in tempo reale. OK salva e Annulla scarta. Esc o il movimento del mouse chiude il "
    L"salvaschermo a schermo intero. Usare Tab e Maiusc+Tab per passare tra i controlli; Alt e la lettera "
    L"sottolineata attivano un comando. Esc nelle impostazioni equivale ad Annulla; nella Guida o nelle "
    L"Informazioni, chiude solo quella finestra.\r\n\r\nSono supportati i sistemi da Windows 7 a Windows "
    L"11. Per eseguire l’applicazione su Windows Vista SP2, è necessario installare gli aggiornamenti "
    L"KB971512 e KB2117917.",
    L"Selecione um ou mais monitores na lista. O modo de câmara, os objetos, a iluminação, as velocidades, "
    L"o tamanho e o número de cópias aplicam-se apenas aos monitores selecionados. Cada monitor guarda as "
    L"suas próprias definições. Escolha Observação do espaço ou Voo pelo espaço em linha reta. Regule a "
    L"velocidade dos objetos e da câmara de 0 a 1600%, uma a dez cópias e o tamanho de 50 a 200%, e ative "
    L"os sólidos. As caixas Luz principal, Luz de preenchimento, Luz ambiente e Iluminação dos contornos "
    L"sob os controlos deslizantes controlam a iluminação de toda a cena de forma independente. A luz "
    L"ambiente fornece iluminação de base às superfícies e a iluminação dos contornos realça os seus "
    L"limites. Por predefinição, as luzes principal, ambiente e dos contornos estão ligadas e a luz de "
    L"preenchimento está desligada. As definições são guardadas separadamente para a aplicação e a proteção "
    L"de ecrã.\r\n\r\nA seleção das linhas determina os ecrãs a configurar e é independente das caixas que "
    L"ativam as saídas de animação. Ctrl+A seleciona todos os ecrãs; Ctrl e Shift alteram a seleção. Todas "
    L"as opções e controlos deslizantes da animação aplicam-se aos ecrãs selecionados. A seleção é guardada "
    L"separadamente para EXE e SCR. Se todos estavam selecionados, os novos ecrãs também são "
    L"incluídos.\r\n\r\nAtivar pré-visualização inicia uma pré-visualização em ecrã inteiro em todos os "
    L"monitores; o diálogo permanece aberto para ajustar as definições em tempo real. OK guarda as "
    L"definições e Cancelar descarta-as. Esc ou o movimento do rato termina a proteção em ecrã inteiro. Use "
    L"Tab e Shift+Tab para passar entre controlos; Alt e a letra sublinhada ativam um comando. Esc nas "
    L"definições equivale a Cancelar; na Ajuda ou em Acerca de, fecha apenas essa janela.\r\n\r\nSão "
    L"suportados os sistemas Windows 7 a Windows 11. Para executar a aplicação no Windows Vista SP2, é "
    L"necessário instalar as atualizações KB971512 e KB2117917.",
    L"Zaznacz jeden lub więcej monitorów na liście. Tryb kamery, wybór brył, oświetlenie, prędkości, "
    L"rozmiar i liczba kopii dotyczą tylko zaznaczonych monitorów. Każdy monitor zapamiętuje własne "
    L"ustawienia. Wybierz Obserwację przestrzeni albo prostoliniowy Przelot przez przestrzeń. Suwaki "
    L"ustawiają prędkość obiektów i kamery 0–1600%, od jednej do dziesięciu kopii i rozmiar 50–200%. Pola "
    L"wyboru Światło główne, Światło wypełniające, Światło otoczenia i Oświetlenie konturów pod suwakami "
    L"niezależnie sterują oświetleniem całej sceny. Światło otoczenia zapewnia podstawową jasność "
    L"powierzchni, a oświetlenie konturów podkreśla krawędzie. Ustawienia są zapisywane osobno dla "
    L"aplikacji i wygaszacza ekranu.\r\n\r\nZaznaczenie wierszy określa konfigurowane monitory i jest "
    L"niezależne od pól wyboru włączających wyjścia animacji. Ctrl+A zaznacza wszystkie monitory; Ctrl i "
    L"Shift zmieniają zaznaczenie. Wszystkie opcje i suwaki animacji dotyczą zaznaczonych monitorów. "
    L"Zaznaczenie jest zapamiętywane osobno dla EXE i SCR. Jeśli zaznaczone były wszystkie monitory, nowe "
    L"również zostaną zaznaczone.\r\n\r\nWłącz potrzebne bryły. Włącz podgląd uruchamia podgląd "
    L"pełnoekranowy na wszystkich monitorach. Okno ustawień pozostaje otwarte, umożliwiając zmiany na "
    L"bieżąco. OK zapisuje ustawienia, a Anuluj je odrzuca. Esc lub ruch myszy kończy tryb pełnoekranowy. "
    L"Klawisze Tab i Shift+Tab przełączają między kontrolkami; Alt i podkreślona litera wywołują polecenie. "
    L"Esc w ustawieniach odpowiada przyciskowi Anuluj; w Pomocy lub O programie zamyka tylko to "
    L"okno.\r\n\r\nObsługiwane są systemy od Windows 7 do Windows 11. Do uruchomienia aplikacji w systemie "
    L"Windows Vista SP2 konieczne jest zainstalowanie aktualizacji KB971512 i KB2117917.",
    L"V zozname označte jeden alebo viac monitorov. Režim kamery, výber telies, svetlá, rýchlosti, veľkosť "
    L"a počet kópií sa nastavujú len pre označené monitory a každý monitor si pamätá vlastné nastavenia. "
    L"Vyberte Pozorovanie priestoru alebo priamy Prelet priestorom. Jazdce nastavujú rýchlosť objektov a "
    L"kamery 0–1600 %, jednu až desať kópií a veľkosť 50–200 %. Začiarkavacie políčka Hlavné svetlo, "
    L"Doplnkové svetlo, Základný jas a Prisvetlenie obrysov pod jazdcami nezávisle ovládajú osvetlenie "
    L"celej scény. Základný jas prisvetľuje povrchy telies a prisvetlenie obrysov zvýrazňuje ich okraje. "
    L"Nastavenia osvetlenia sa ukladajú zvlášť pre aplikáciu a šetrič obrazovky.\r\n\r\nOznačenie riadkov "
    L"určuje, ktoré monitory práve nastavujete; je nezávislé od políčok zapínajúcich animačné výstupy. "
    L"Ctrl+A označí všetky monitory, Ctrl a Shift upravujú označenie. Všetky animačné voľby a posuvníky "
    L"platia pre označené monitory. Označenie sa pamätá zvlášť pre EXE a SCR. Ak boli označené všetky "
    L"monitory, označia sa aj novopripojené.\r\n\r\nZapnite požadované telesá. Zapnúť náhľad spustí "
    L"celoobrazovkový náhľad na všetkých monitoroch; nastavenia zostávajú otvorené a zmeny sa prejavia "
    L"ihneď. OK uloží nastavenia a Zrušiť ich zahodí. Celoobrazovkový šetrič ukončí Esc alebo pohyb myši. "
    L"Medzi ovládacími prvkami prechádzajte klávesmi Tab a Shift+Tab; podčiarknuté voľby vyvoláte pomocou "
    L"Alt a príslušného písmena. Esc v nastaveniach zodpovedá tlačidlu Zrušiť; v Pomocníkovi alebo okne O "
    L"aplikácii zavrie iba toto okno.\r\n\r\nPodporované sú systémy Windows 7 až Windows 11. Na spustenie "
    L"aplikácie v systéme Windows Vista SP2 je potrebné nainštalovať aktualizácie KB971512 a KB2117917.",
    L"Vælg en eller flere skærme på listen. Kameratilstand, objekter, belysning, hastigheder, størrelse og "
    L"antal kopier gælder kun de valgte skærme. Hver skærm husker sine egne indstillinger. Vælg "
    L"Rumobservation eller Flyvning gennem rummet i en lige linje. Indstil objekt- og kamerahastighed "
    L"0–1600 %, en til ti kopier og størrelse 50–200 %, og aktivér de ønskede legemer. Afkrydsningsfelterne "
    L"Hovedlys, Udfyldningslys, Omgivende lys og Konturlys under skyderne styrer belysningen af hele scenen "
    L"uafhængigt af hinanden. Omgivende lys giver overfladerne en grundbelysning, og konturlys fremhæver "
    L"kanterne. Som standard er hovedlys, omgivende lys og konturlys slået til og udfyldningslys slået fra. "
    L"Indstillingerne gemmes separat for programmet og pauseskærmen.\r\n\r\nMarkeringen af rækker "
    L"bestemmer, hvilke skærme du indstiller, og er adskilt fra afkrydsningsfelterne, der aktiverer "
    L"animationsoutput. Ctrl+A markerer alle skærme; Ctrl og Skift ændrer markeringen. Alle animationsvalg "
    L"og skydere gælder de markerede skærme. Markeringen huskes separat for EXE og SCR. Hvis alle skærme "
    L"var markeret, medtages også nye skærme.\r\n\r\nAktivér forhåndsvisning starter en forhåndsvisning i "
    L"fuld skærm på alle skærme. Indstillingerne forbliver åbne, og ændringerne vises med det samme. OK "
    L"gemmer indstillingerne, og Annuller forkaster ændringerne. Esc eller musebevægelse afslutter "
    L"fuldskærmen. Brug Tab og Skift+Tab til at flytte mellem kontrollerne; Alt og det understregede "
    L"bogstav aktiverer en kommando. Esc i indstillingerne svarer til Annuller; i Hjælp eller Om lukker det "
    L"kun dette vindue.\r\n\r\nWindows 7 til Windows 11 understøttes. For at køre programmet på Windows "
    L"Vista SP2 skal opdateringerne KB971512 og KB2117917 installeres.",
    L"Valitse luettelosta yksi tai useampi näyttö. Kameratila, kappaleet, valaistus, nopeudet, koko ja "
    L"kopioiden määrä koskevat vain valittuja näyttöjä. Jokainen näyttö muistaa omat asetuksensa. Valitse "
    L"Avaruuden tarkkailu tai Lento avaruuden halki suoraan eteenpäin. Aseta kohteiden ja kameran nopeus "
    L"0–1600 %, yhdestä kymmeneen kopiota ja koko 50–200 %, ja ota halutut kappaleet käyttöön. "
    L"Liukusäätimien alla olevat Päävalo-, Täytevalo-, Ympäristövalo- ja Reunavalo-valintaruudut ohjaavat "
    L"koko näkymän valaistusta toisistaan riippumatta. Ympäristövalo antaa pinnoille perusvalaistuksen ja "
    L"reunavalo korostaa reunoja. Oletuksena päävalo, ympäristövalo ja reunavalo ovat päällä ja täytevalo "
    L"pois päältä. Asetukset tallennetaan erikseen sovellukselle ja näytönsäästäjälle.\r\n\r\nRivien "
    L"valinta määrää muokattavat näytöt ja on erillinen animaatioulostulon valintaruuduista. Ctrl+A "
    L"valitsee kaikki näytöt; Ctrl ja Vaihto muuttavat valintaa. Kaikki animaatioasetukset ja liukusäätimet "
    L"koskevat valittuja näyttöjä. Valinta muistetaan erikseen EXE- ja SCR-tiloissa. Jos kaikki näytöt "
    L"olivat valittuina, myös uudet näytöt valitaan.\r\n\r\nOta esikatselu käyttöön käynnistää koko näytön "
    L"esikatselun kaikilla näytöillä. Asetusikkuna pysyy avoinna, ja muutokset näkyvät heti. OK tallentaa "
    L"asetukset ja Peruuta hylkää muutokset. Esc tai hiiren liike lopettaa koko näytön säästäjän. Siirry "
    L"säätimien välillä Tab- ja Vaihto+Tab-näppäimillä; Alt ja alleviivattu kirjain aktivoivat komennon. "
    L"Esc asetuksissa vastaa Peruuta-painiketta; Ohje- tai Tietoja-ikkunassa se sulkee vain kyseisen "
    L"ikkunan.\r\n\r\nTuettuja käyttöjärjestelmiä ovat Windows 7–Windows 11. Sovelluksen suorittaminen "
    L"Windows Vista SP2:ssa edellyttää päivitysten KB971512 ja KB2117917 asentamista.",
    L"Veldu einn eða fleiri skjái á listanum. Myndavélarhamur, hlutir, lýsing, hraði, stærð og fjöldi "
    L"eintaka eiga aðeins við um valda skjái. Hver skjár geymir sínar eigin stillingar. Veldu Athugun rýmis "
    L"eða Flug um rýmið í beinni línu. Stilltu hraða hluta og myndavélar á 0–1600%, eitt til tíu eintök og "
    L"stærð á 50–200% og virkjaðu óskaða hluti. Gátreitirnir Aðalljós, Fylliljós, Umhverfislýsing og "
    L"Útlínulýsing undir rennistikunum stýra lýsingu allrar senunnar óháð hver öðrum. Umhverfislýsing gefur "
    L"yfirborðunum grunnbirtu og útlínulýsing dregur fram jaðrana. Stillingarnar eru vistaðar sérstaklega "
    L"fyrir forritið og skjáhvíluna.\r\n\r\nVal lína ákvarðar hvaða skjám er verið að breyta og er óháð "
    L"gátreitunum sem kveikja á hreyfimyndaúttaki. Ctrl+A velur alla skjái; Ctrl og Shift breyta valinu. "
    L"Allir valkostir og sleðar hreyfimynda gilda fyrir valda skjái. Valið er munað sérstaklega fyrir EXE "
    L"og SCR. Ef allir skjáir voru valdir bætast nýir skjáir einnig við valið.\r\n\r\nVirkja forskoðun "
    L"ræsir forskoðun á öllum skjánum á hverjum skjá. Stillingaglugginn helst opinn og breytingar sjást "
    L"strax. Í lagi vistar stillingar og Hætta við hafnar breytingum. Esc eða músarhreyfing lokar skjáhvílu "
    L"á öllum skjánum. Notaðu Tab og Shift+Tab til að færa þig milli stýrieininga; Alt og undirstrikaður "
    L"stafur virkja skipun. Esc í stillingum jafngildir Hætta við; í Hjálp eða Um lokar það aðeins þeim "
    L"glugga.\r\n\r\nWindows 7 til Windows 11 eru studd. Til að keyra forritið á Windows Vista SP2 þarf að "
    L"setja upp uppfærslurnar KB971512 og KB2117917.",
    L"Velg én eller flere skjermer i listen. Kameramodus, objekter, belysning, hastigheter, størrelse og "
    L"antall kopier gjelder bare de valgte skjermene. Hver skjerm husker sine egne innstillinger. Velg "
    L"Romobservasjon eller Flyging gjennom rommet i rett linje. Angi objekt- og kamerahastighet 0–1600 %, "
    L"én til ti kopier og størrelse 50–200 %, og aktiver ønskede legemer. Avmerkingsboksene Hovedlys, "
    L"Utfyllingslys, Omgivelseslys og Konturlys under glidebryterne styrer belysningen i hele scenen "
    L"uavhengig av hverandre. Omgivelseslys gir grunnbelysning på overflatene, og konturlys fremhever "
    L"kantene. Som standard er hovedlys, omgivelseslys og konturlys på, og utfyllingslys av. Innstillingene "
    L"lagres separat for programmet og skjermspareren.\r\n\r\nMarkeringen av rader bestemmer hvilke "
    L"skjermer du redigerer, og er atskilt fra avkrysningsboksene som aktiverer animasjonsutgangen. Ctrl+A "
    L"markerer alle skjermer; Ctrl og Skift endrer markeringen. Alle animasjonsvalg og glidebrytere gjelder "
    L"de markerte skjermene. Markeringen huskes separat for EXE og SCR. Hvis alle skjermer var markert, "
    L"inkluderes også nye skjermer.\r\n\r\nSlå på forhåndsvisning starter en forhåndsvisning i fullskjerm "
    L"på alle skjermer. Innstillingene forblir åpne, og endringene vises fortløpende. OK lagrer "
    L"innstillingene og Avbryt forkaster dem. Esc eller musebevegelse avslutter fullskjermsvisningen. Bruk "
    L"Tab og Shift+Tab for å flytte mellom kontrollene; Alt og den understrekede bokstaven aktiverer en "
    L"kommando. Esc i innstillingene tilsvarer Avbryt; i Hjelp eller Om lukker det bare dette "
    L"vinduet.\r\n\r\nWindows 7 til Windows 11 støttes. For å kjøre programmet på Windows Vista SP2 må "
    L"oppdateringene KB971512 og KB2117917 installeres.",
    L"Markera en eller flera skärmar i listan. Kameraläge, objekt, belysning, hastigheter, storlek och "
    L"antal kopior gäller bara de markerade skärmarna. Varje skärm sparar sina egna inställningar. Välj "
    L"Rymdobservation eller Flygning genom rymden i rak linje. Ställ in objekt- och kamerahastighet 0–1600 "
    L"%, en till tio kopior och storlek 50–200 %, och aktivera önskade kroppar. Kryssrutorna Huvudljus, "
    L"Upplättningsljus, Omgivningsljus och Konturljus under reglagen styr belysningen i hela scenen "
    L"oberoende av varandra. Omgivningsljus ger grundbelysning på ytorna och konturljus framhäver kanterna. "
    L"Som standard är huvudljus, omgivningsljus och konturljus på och upplättningsljus av. Inställningarna "
    L"sparas separat för programmet och skärmsläckaren.\r\n\r\nMarkeringen av rader avgör vilka skärmar du "
    L"redigerar och är skild från kryssrutorna som aktiverar animationsutgångarna. Ctrl+A markerar alla "
    L"skärmar; Ctrl och Skift ändrar markeringen. Alla animationsalternativ och reglage gäller de markerade "
    L"skärmarna. Markeringen sparas separat för EXE och SCR. Om alla skärmar var markerade inkluderas även "
    L"nya skärmar.\r\n\r\nAktivera förhandsvisning startar en förhandsvisning i helskärm på alla "
    L"bildskärmar. Inställningarna förblir öppna och ändringarna visas direkt. OK sparar inställningarna "
    L"och Avbryt förkastar ändringarna. Esc eller musrörelse avslutar helskärmsläget. Använd Tab och "
    L"Skift+Tab för att flytta mellan kontrollerna; Alt och den understrukna bokstaven aktiverar ett "
    L"kommando. Esc i inställningarna motsvarar Avbryt; i Hjälp eller Om stänger det bara det "
    L"fönstret.\r\n\r\nWindows 7 till Windows 11 stöds. För att köra programmet på Windows Vista SP2 måste "
    L"uppdateringarna KB971512 och KB2117917 installeras.",
    L"Listeden bir veya daha fazla ekran seçin. Kamera modu, nesneler, aydınlatma, hızlar, boyut ve kopya "
    L"sayısı yalnızca seçili ekranlara uygulanır. Her ekran kendi ayarlarını hatırlar. Uzayı gözlemleme "
    L"veya doğrusal Uzayda uçuş kipini seçin. Nesne ve kamera hızını %0–1600, kopya sayısını bir ile on ve "
    L"boyutu %50–200 arasında ayarlayıp istenen cisimleri etkinleştirin. Kaydırıcıların altındaki Ana ışık, "
    L"Dolgu ışığı, Ortam ışığı ve Kenar aydınlatması onay kutuları tüm sahnenin aydınlatmasını birbirinden "
    L"bağımsız olarak kontrol eder. Ortam ışığı yüzeylere temel aydınlatma sağlar, kenar aydınlatması ise "
    L"kenarları vurgular. Ayarlar uygulama ve ekran koruyucu için ayrı ayrı kaydedilir.\r\n\r\nSatır "
    L"seçimi, hangi ekranların düzenlendiğini belirler; animasyon çıkışlarını açan onay kutularından "
    L"ayrıdır. Ctrl+A tüm ekranları seçer; Ctrl ve Shift seçimi değiştirir. Tüm animasyon seçenekleri ve "
    L"kaydırıcılar seçili ekranlara uygulanır. Seçim EXE ve SCR için ayrı saklanır. Tüm ekranlar seçiliyse "
    L"sonradan bağlanan ekranlar da seçime katılır.\r\n\r\nÖnizlemeyi aç, tüm monitörlerde tam ekran "
    L"önizleme başlatır. Ayarlar penceresi açık kalır ve değişiklikler anında görülür. Tamam ayarları "
    L"kaydeder, İptal değişiklikleri iptal eder. Tam ekran koruyucudan Esc veya fare hareketiyle çıkılır. "
    L"Denetimler arasında Tab ve Shift+Tab ile ilerleyin; Alt ve altı çizili harf bir komutu etkinleştirir. "
    L"Ayarlarda Esc, İptal ile aynı işlevi görür; Yardım veya Hakkında penceresinde yalnızca o pencereyi "
    L"kapatır.\r\n\r\nWindows 7 ile Windows 11 arasındaki sürümler desteklenir. Uygulamayı Windows Vista "
    L"SP2'de çalıştırmak için KB971512 ve KB2117917 güncellemelerini yüklemeniz gerekir.",
    L"FlyingSolids kuvab liikuvaid, pöörlevaid ja põrkuvaid ruumilisi kehi. Valige ruumi vaatlemine või "
    L"lend läbi ruumi ning soovitud kehad. Iga kuvari jaoks saab eraldi määrata objektide ja kaamera "
    L"kiiruse 0–1600%, objektide suuruse 50–200% ning iga keha koopiate arvu 1–10. Põhi-, täite-, ümbritsev "
    L"ja kontuurivalgus on sõltumatult lülitatavad.\r\n\r\nValige loendis üks või mitu kuvaririda. Ctrl+A "
    L"valib kõik read; Ctrl ja Shift võimaldavad valikut muuta. Animatsiooni juhtnupud ja liugurid "
    L"mõjutavad ainult valitud kuvarite sätteid, mitte kogu rakendust. Rea valimine ja selle märkeruuduga "
    L"väljundi lubamine on eri toimingud. Valik jäetakse rakenduse ja ekraanisäästja jaoks eraldi meelde. "
    L"Kui varem olid valitud kõik kuvarid, kaasatakse ka lisatud kuvarid.\r\n\r\nKäivitage FlyingSolids.scr "
    L"Windowsi ekraanisäästjana. Selle sätted on rakenduse omadest eraldi. Sätete eelvaade lubab "
    L"täisekraanil animatsiooni jooksvalt muuta. OK salvestab muudatused ning Loobu või Esc tühistab need. "
    L"Täisekraanil ekraanisäästjast väljumiseks vajutage klahvi või liigutage hiirt.\r\n\r\nWindows 7–11 "
    L"toetab kõiki funktsioone. Windows Vista SP2 jaoks tuleb paigaldada värskendused KB971512 ja "
    L"KB2117917; MP4 salvestamine Vistas ei tööta. Vaja on Direct3D 11 tuge ning MP4 jaoks Media "
    L"Foundationi ja H.264 kodeerijat. Liides ja dokumentatsioon on saadaval 36 keeles.",
    L"Taispeánann FlyingSolids coirp sholadacha a ghluaiseann, a rothlaíonn agus a imbhuaileann. Roghnaigh "
    L"breathnú ar an spás nó eitilt tríd agus na coirp atá uait. Tá luas na réad agus an cheamara 0–1600%, "
    L"méid na réad 50–200% agus 1–10 gcóip de gach corp inchoigeartaithe go neamhspleách do gach monatóir. "
    L"Is féidir an príomhsholas, an solas líonta, an solas comhthimpeallach agus an solas imill a athrú ar "
    L"leith.\r\n\r\nRoghnaigh ró amháin nó níos mó sa liosta monatóirí. Roghnaíonn Ctrl+A gach ró; úsáid "
    L"Ctrl agus Shift chun an roghnú a athrú. Ní athraíonn rialuithe agus sleamhnáin na beochana ach "
    L"socruithe na monatóirí roghnaithe. Ní hionann ró a roghnú agus aschur an mhonatóra a chumasú lena "
    L"bhosca seiceála. Cuimhnítear an roghnú ar leith don fheidhmchlár agus don spárálaí. Má bhí gach "
    L"monatóir roghnaithe, cuirtear monatóirí nua leis an roghnú freisin.\r\n\r\nÚsáid FlyingSolids.scr mar "
    L"spárálaí scáileáin Windows. Tá a shocruithe ar leith ó shocruithe an fheidhmchláir. Ceadaíonn an "
    L"réamhamharc lánscáileáin athruithe beo. Sábhálann OK agus cealaíonn Cealaigh nó Esc na hathruithe. "
    L"Fág an spárálaí lánscáileáin le heochair ar bith nó le gluaiseacht na luiche.\r\n\r\nTacaíonn Windows "
    L"7–11 leis na gnéithe uile. Ar Windows Vista SP2 ní mór nuashonruithe KB971512 agus KB2117917 a "
    L"shuiteáil; ní oibríonn taifeadadh MP4 ar Vista. Teastaíonn tacaíocht Direct3D 11, agus Media "
    L"Foundation agus ionchódóir H.264 le haghaidh MP4. Tá an comhéadan agus an doiciméadú ar fáil i 36 "
    L"teanga.",
    L"FlyingSolids rodo judančius, besisukančius ir susiduriančius erdvinius kūnus. Pasirinkite erdvės "
    L"stebėjimą arba skrydį erdve ir norimus kūnus. Kiekvienam monitoriui atskirai galima nustatyti objektų "
    L"bei kameros greitį 0–1600%, objektų dydį 50–200% ir 1–10 kiekvieno kūno kopijų. Pagrindinė, "
    L"užpildanti, aplinkos ir kontūrinė šviesa įjungiamos nepriklausomai.\r\n\r\nMonitorių sąraše "
    L"pasirinkite vieną ar kelias eilutes. Ctrl+A pasirenka visas, o Ctrl ir Shift leidžia keisti "
    L"pasirinkimą. Animacijos valdikliai ir slankikliai keičia tik pasirinktų monitorių nuostatas. Eilutės "
    L"pasirinkimas nėra tas pats, kas animacijos išvesties įjungimas jos žymimuoju langeliu. Pasirinkimas "
    L"atskirai įsimenamas programai ir užsklandai. Jei buvo pasirinkti visi monitoriai, į pasirinkimą "
    L"įtraukiami ir naujai prijungti monitoriai.\r\n\r\nNaudokite FlyingSolids.scr kaip Windows ekrano "
    L"užsklandą. Jos nuostatos atskiros nuo programos. Viso ekrano peržiūra leidžia jas keisti vykstant "
    L"animacijai. OK išsaugo, Atšaukti arba Esc atmeta pakeitimus. Užsklandą užbaikite klavišu arba "
    L"pajudindami pelę.\r\n\r\nWindows 7–11 palaiko visas funkcijas. Windows Vista SP2 būtina įdiegti "
    L"naujinimus KB971512 ir KB2117917; MP4 įrašymas Vistoje neveikia. Reikalingas Direct3D 11 palaikymas, "
    L"o MP4 įrašymui Media Foundation ir H.264 koduotuvas. Sąsaja ir dokumentacija pateikiamos 36 kalbomis.",
    L"FlyingSolids rāda kustīgus, rotējošus un savstarpēji sadurošus telpiskus ķermeņus. Izvēlieties telpas "
    L"novērošanu vai lidojumu telpā un vajadzīgos ķermeņus. Katram monitoram atsevišķi var iestatīt objektu "
    L"un kameras ātrumu 0–1600%, objektu izmēru 50–200% un 1–10 katra ķermeņa kopijas. Galveno, papildu, "
    L"apkārtējo un kontūru gaismu var pārslēgt neatkarīgi.\r\n\r\nMonitoru sarakstā atlasiet vienu vai "
    L"vairākas rindas. Ctrl+A atlasa visas, bet Ctrl un Shift ļauj mainīt atlasi. Animācijas vadīklas un "
    L"slīdņi maina tikai atlasīto monitoru iestatījumus. Rindas atlasīšana nav tas pats, kas animācijas "
    L"izvades ieslēgšana ar izvēles rūtiņu. Atlase tiek atsevišķi atcerēta lietotnei un ekrānsaudzētājam. "
    L"Ja bija atlasīti visi monitori, atlasē iekļauj arī jaunpievienotos monitorus.\r\n\r\nIzmantojiet "
    L"FlyingSolids.scr kā Windows ekrānsaudzētāju. Tā iestatījumi ir atsevišķi no lietotnes. Pilnekrāna "
    L"priekšskatījums ļauj tos mainīt animācijas darbības laikā. OK saglabā, Atcelt vai Esc atmet izmaiņas. "
    L"Pilnekrāna ekrānsaudzētāju aizveriet ar taustiņu vai peles kustību.\r\n\r\nWindows 7–11 atbalsta "
    L"visas funkcijas. Windows Vista SP2 jāinstalē atjauninājumi KB971512 un KB2117917; MP4 ierakstīšana "
    L"Vistā nedarbojas. Nepieciešams Direct3D 11 atbalsts, bet MP4 vajadzīgi Media Foundation un H.264 "
    L"kodētājs. Saskarne un dokumentācija ir pieejama 36 valodās.",
    L"A FlyingSolids mozgó, forgó és ütköző térbeli testeket jelenít meg. Válassza a tér megfigyelését vagy "
    L"a térben repülést, és kapcsolja be a kívánt testeket. Monitoronként állítható az objektumok és a "
    L"kamera sebessége 0–1600%, az objektumok mérete 50–200%, valamint testenként 1–10 példány. A főfény, "
    L"derítőfény, környezeti fény és peremfény egymástól függetlenül kapcsolható.\r\n\r\nJelöljön ki egy "
    L"vagy több sort a monitorok listájában. A Ctrl+A mindet kijelöli; a Ctrl és a Shift módosítja a "
    L"kijelölést. Az animáció vezérlői és csúszkái csak a kijelölt monitorok beállításait változtatják. A "
    L"sor kijelölése és az animációs kimenet jelölőnégyzetes engedélyezése külön művelet. A kijelölést az "
    L"alkalmazás és a képernyőkímélő külön megjegyzi. Ha korábban minden monitor ki volt jelölve, az "
    L"újonnan csatlakoztatott monitorok is bekerülnek a kijelölésbe.\r\n\r\nA FlyingSolids.scr "
    L"Windows-képernyőkímélőként használható, az alkalmazástól külön beállításokkal. A teljes képernyős "
    L"előnézetben élőben módosíthatók a beállítások. Az OK ment, a Mégse vagy Esc elveti a módosításokat. A "
    L"teljes képernyős képernyőkímélő billentyűvel vagy egérmozgással zárható be.\r\n\r\nA Windows 7–11 "
    L"minden funkciót támogat. Windows Vista SP2 alatt telepíteni kell a KB971512 és KB2117917 frissítést; "
    L"az MP4-felvétel Vistán nem működik. Direct3D 11 támogatás szükséges, az MP4-hez Media Foundation és "
    L"H.264-kódoló is kell. A kezelőfelület és a dokumentáció 36 nyelven érhető el.",
    L"FlyingSolids juri solidi tridimensjonali li jiċċaqalqu, iduru u jaħbtu ma’ xulxin. Agħżel "
    L"osservazzjoni tal-ispazju jew titjira fl-ispazju u attiva l-forom mixtieqa. Għal kull moniter tista’ "
    L"tissettja separatament il-veloċità tal-oġġetti u l-kamera minn 0–1600%, id-daqs minn 50–200% u 1–10 "
    L"kopji ta’ kull solidu. Id-dawl ewlieni, id-dawl ta’ mili, id-dawl ambjentali u d-dawl tal-kontorn "
    L"jinxtegħlu separatament.\r\n\r\nAgħżel ringiela waħda jew aktar fil-lista tal-moniters. Ctrl+A "
    L"jagħżilhom kollha; Ctrl u Shift ibiddlu l-għażla. Il-kontrolli u s-sliders tal-animazzjoni jibdlu "
    L"biss is-settings tal-moniters magħżula. L-għażla ta’ ringiela hija differenti mill-attivazzjoni "
    L"tal-output permezz tal-kaxxa tal-marka. L-għażla tinżamm separatament għall-applikazzjoni u "
    L"għall-iscreen saver. Jekk il-moniters kollha kienu magħżula, il-moniters ġodda jiddaħħlu wkoll "
    L"fl-għażla.\r\n\r\nUża FlyingSolids.scr bħala screen saver ta’ Windows. Is-settings tiegħu huma "
    L"separati minn dawk tal-applikazzjoni. Il-previżjoni fuq skrin sħiħ tippermetti bidliet waqt "
    L"l-animazzjoni. OK isalva u Ikkanċella jew Esc jarmi l-bidliet. Oħroġ mill-iscreen saver bi kwalunkwe "
    L"tast jew billi ċċaqlaq il-maws.\r\n\r\nWindows 7–11 jappoġġja l-funzjonijiet kollha. Fuq Windows "
    L"Vista SP2 għandhom jiġu installati l-aġġornamenti KB971512 u KB2117917; ir-reġistrazzjoni MP4 ma "
    L"taħdimx fuq Vista. Huwa meħtieġ Direct3D 11 u, għall-MP4, Media Foundation u encoder H.264. "
    L"L-interface u d-dokumentazzjoni huma disponibbli f’36 lingwa.",
    L"FlyingSolids toont bewegende, draaiende en botsende driedimensionale lichamen. Kies ruimte observeren "
    L"of door de ruimte vliegen en schakel de gewenste lichamen in. Stel per beeldscherm de object- en "
    L"camerasnelheid in op 0–1600%, de objectgrootte op 50–200% en het aantal kopieën op 1–10 per lichaam. "
    L"Hoofdlicht, invullicht, omgevingslicht en randlicht zijn onafhankelijk schakelbaar.\r\n\r\nSelecteer "
    L"één of meer beeldschermrijen in de lijst. Ctrl+A selecteert alles; met Ctrl en Shift past u de "
    L"selectie aan. Animatieknoppen en schuifregelaars wijzigen alleen de instellingen van de geselecteerde "
    L"beeldschermen. Een rij selecteren is iets anders dan de animatie-uitvoer inschakelen met het "
    L"selectievakje. De selectie wordt apart onthouden voor de toepassing en de schermbeveiliging. Als alle "
    L"beeldschermen waren geselecteerd, worden nieuw aangesloten beeldschermen ook "
    L"geselecteerd.\r\n\r\nGebruik FlyingSolids.scr als Windows-schermbeveiliging met eigen instellingen. "
    L"Het schermvullende voorbeeld laat live aanpassingen toe. OK slaat wijzigingen op; Annuleren of Esc "
    L"verwerpt ze. Sluit de schermvullende schermbeveiliging met een toets of een "
    L"muisbeweging.\r\n\r\nWindows 7–11 ondersteunt alle functies. Voor Windows Vista SP2 moet u updates "
    L"KB971512 en KB2117917 installeren; MP4-opname werkt niet op Vista. Direct3D 11-ondersteuning is "
    L"vereist; voor MP4 zijn ook Media Foundation en een H.264-encoder nodig. Interface en documentatie "
    L"zijn beschikbaar in 36 talen.",
    L"FlyingSolids afișează corpuri tridimensionale care se deplasează, se rotesc și se ciocnesc. Alegeți "
    L"observarea spațiului sau zborul prin spațiu și activați corpurile dorite. Pentru fiecare monitor "
    L"puteți seta separat viteza obiectelor și a camerei între 0–1600%, dimensiunea între 50–200% și 1–10 "
    L"copii ale fiecărui corp. Lumina principală, de umplere, ambiantă și de contur se controlează "
    L"independent.\r\n\r\nSelectați unul sau mai multe rânduri din lista monitoarelor. Ctrl+A le selectează "
    L"pe toate; Ctrl și Shift modifică selecția. Comenzile și glisoarele animației schimbă numai setările "
    L"monitoarelor selectate. Selectarea unui rând diferă de activarea ieșirii prin caseta sa de selectare. "
    L"Selecția este reținută separat pentru aplicație și economizor. Dacă erau selectate toate monitoarele, "
    L"sunt incluse și cele conectate ulterior.\r\n\r\nFolosiți FlyingSolids.scr drept economizor de ecran "
    L"Windows, cu setări separate de aplicație. Previzualizarea pe tot ecranul permite ajustări în timp "
    L"real. OK salvează modificările; Anulare sau Esc le anulează. Ieșiți din economizor apăsând o tastă "
    L"sau mișcând mouse-ul.\r\n\r\nWindows 7–11 acceptă toate funcțiile. Pentru Windows Vista SP2 trebuie "
    L"instalate actualizările KB971512 și KB2117917; înregistrarea MP4 nu funcționează pe Vista. Este "
    L"necesar Direct3D 11, iar pentru MP4 și Media Foundation și un codificator H.264. Interfața și "
    L"documentația sunt disponibile în 36 de limbi.",
    L"Το FlyingSolids εμφανίζει τρισδιάστατα στερεά που κινούνται, περιστρέφονται και συγκρούονται. "
    L"Επιλέξτε παρατήρηση χώρου ή πτήση στον χώρο και ενεργοποιήστε τα επιθυμητά στερεά. Ανά οθόνη "
    L"ρυθμίζονται ανεξάρτητα η ταχύτητα αντικειμένων και κάμερας 0–1600%, το μέγεθος 50–200% και 1–10 "
    L"αντίγραφα κάθε στερεού. Ο κύριος φωτισμός, ο φωτισμός πλήρωσης, ο περιβάλλων φωτισμός και ο φωτισμός "
    L"περιγράμματος ελέγχονται ανεξάρτητα.\r\n\r\nΕπιλέξτε μία ή περισσότερες γραμμές στη λίστα οθονών. Το "
    L"Ctrl+A επιλέγει όλες, ενώ τα Ctrl και Shift αλλάζουν την επιλογή. Τα χειριστήρια και τα ρυθμιστικά "
    L"της κίνησης αλλάζουν μόνο τις ρυθμίσεις των επιλεγμένων οθονών. Η επιλογή γραμμής διαφέρει από την "
    L"ενεργοποίηση εξόδου μέσω του πλαισίου ελέγχου της. Η επιλογή αποθηκεύεται χωριστά για την εφαρμογή "
    L"και την προφύλαξη. Αν είχαν επιλεγεί όλες οι οθόνες, περιλαμβάνονται και όσες συνδεθούν "
    L"αργότερα.\r\n\r\nΧρησιμοποιήστε το FlyingSolids.scr ως προφύλαξη οθόνης Windows με χωριστές ρυθμίσεις "
    L"από την εφαρμογή. Η προεπισκόπηση πλήρους οθόνης επιτρέπει ζωντανές αλλαγές. Το OK αποθηκεύει και το "
    L"Άκυρο ή Esc απορρίπτει τις αλλαγές. Τερματίστε την προφύλαξη με πλήκτρο ή κίνηση του "
    L"ποντικιού.\r\n\r\nΤα Windows 7–11 υποστηρίζουν όλες τις λειτουργίες. Στα Windows Vista SP2 πρέπει να "
    L"εγκατασταθούν οι ενημερώσεις KB971512 και KB2117917· η εγγραφή MP4 δεν λειτουργεί στα Vista. "
    L"Απαιτείται υποστήριξη Direct3D 11 και, για MP4, Media Foundation και κωδικοποιητής H.264. Η διεπαφή "
    L"και η τεκμηρίωση διατίθενται σε 36 γλώσσες.",
    L"FlyingSolids prikazuje prostorna tijela koja se kreću, okreću i sudaraju. Odaberite posmatranje "
    L"prostora ili let kroz prostor te željena tijela. Za svaki monitor zasebno se podešavaju brzina "
    L"objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija svakog tijela. Glavno, dopunsko, "
    L"ambijentalno i konturno svjetlo uključuju se nezavisno.\r\n\r\nOdaberite jedan ili više redova u "
    L"listi monitora. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije "
    L"mijenjaju samo postavke odabranih monitora. Odabir reda nije isto što i uključivanje izlaza njegovom "
    L"kućicom. Odabir se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili odabrani svi "
    L"monitori, uključuju se i novopriključeni monitori.\r\n\r\nKoristite FlyingSolids.scr kao Windows "
    L"čuvar ekrana s odvojenim postavkama. Pregled preko cijelog ekrana omogućava izmjene uživo. OK čuva, a "
    L"Otkaži ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili pomjeranjem "
    L"miša.\r\n\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja "
    L"KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media "
    L"Foundation te H.264 koder. Interfejs i dokumentacija dostupni su na 36 jezika.",
    L"FlyingSolids prikazuje prostorna tijela koja se kreću, okreću i sudaraju. Odaberite promatranje "
    L"prostora ili let kroz prostor te željena tijela. Za svaki zaslon zasebno se podešavaju brzina "
    L"objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija svakog tijela. Glavno, dopunsko, "
    L"ambijentalno i konturno svjetlo uključuju se neovisno.\r\n\r\nOdaberite jedan ili više redaka na "
    L"popisu zaslona. Ctrl+A odabire sve; Ctrl i Shift mijenjaju odabir. Kontrole i klizači animacije "
    L"mijenjaju samo postavke odabranih zaslona. Odabir retka nije isto što i uključivanje izlaza njegovim "
    L"potvrdnim okvirom. Odabir se pamti odvojeno za aplikaciju i čuvar zaslona. Ako su prethodno bili "
    L"odabrani svi zasloni, uključuju se i novopriključeni zasloni.\r\n\r\nKoristite FlyingSolids.scr kao "
    L"Windows čuvar zaslona s odvojenim postavkama. Pretpregled preko cijelog zaslona omogućuje izmjene "
    L"uživo. OK sprema, a Odustani ili Esc odbacuje izmjene. Iz čuvara izađite pritiskom tipke ili "
    L"pomicanjem miša.\r\n\r\nWindows 7–11 podržava sve funkcije. Za Windows Vista SP2 morate instalirati "
    L"ažuriranja KB971512 i KB2117917; MP4 snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i "
    L"Media Foundation te H.264 koder. Sučelje i dokumentacija dostupni su na 36 jezika.",
    L"FlyingSolids prikazuje prostorska telesa, ki se premikajo, vrtijo in trkajo. Izberite opazovanje "
    L"prostora ali let skozi prostor in želena telesa. Za vsak zaslon so ločeno nastavljivi hitrost "
    L"predmetov in kamere 0–1600%, velikost 50–200% ter 1–10 kopij vsakega telesa. Glavna, dopolnilna, "
    L"okoljska in obrobna svetloba se vklapljajo neodvisno.\r\n\r\nNa seznamu zaslonov izberite eno ali več "
    L"vrstic. Ctrl+A izbere vse, Ctrl in Shift pa spreminjata izbor. Kontrolniki in drsniki animacije "
    L"spreminjajo samo nastavitve izbranih zaslonov. Izbira vrstice ni isto kot vklop izhoda z njenim "
    L"potrditvenim poljem. Izbor se ločeno shrani za program in ohranjevalnik. Če so bili izbrani vsi "
    L"zasloni, so vključeni tudi na novo priključeni zasloni.\r\n\r\nUporabite FlyingSolids.scr kot "
    L"ohranjevalnik zaslona Windows z ločenimi nastavitvami. Celozaslonski predogled omogoča sprotne "
    L"spremembe. OK jih shrani, Prekliči ali Esc jih zavrže. Ohranjevalnik zapustite s tipko ali premikom "
    L"miške.\r\n\r\nWindows 7–11 podpira vse funkcije. Za Windows Vista SP2 morate namestiti posodobitvi "
    L"KB971512 in KB2117917; snemanje MP4 v Visti ne deluje. Potrebna je podpora Direct3D 11, za MP4 pa še "
    L"Media Foundation in kodirnik H.264. Vmesnik in dokumentacija sta na voljo v 36 jezikih.",
    L"FlyingSolids prikazuje prostorna tijela koja se kreću, okreću i sudaraju. Izaberite posmatranje "
    L"prostora ili let kroz prostor te željena tijela. Za svaki monitor zasebno se podešavaju brzina "
    L"objekata i kamere 0–1600%, veličina 50–200% i 1–10 kopija svakog tijela. Glavno, dopunsko, "
    L"ambijentalno i konturno svjetlo uključuju se nezavisno.\r\n\r\nIzaberite jedan ili više redova u "
    L"listi monitora. Ctrl+A bira sve; Ctrl i Shift mijenjaju izbor. Kontrole i klizači animacije mijenjaju "
    L"samo podešavanja izabranih monitora. Izbor reda nije isto što i uključivanje izlaza njegovom kućicom. "
    L"Izbor se pamti odvojeno za aplikaciju i čuvar ekrana. Ako su prethodno bili izabrani svi monitori, "
    L"uključuju se i novopriključeni monitori.\r\n\r\nKoristite FlyingSolids.scr kao Windows čuvar ekrana s "
    L"odvojenim podešavanjima. Pregled preko cijelog ekrana omogućava izmjene uživo. OK čuva, a Otkaži ili "
    L"Esc odbacuje izmjene. Iz čuvara izađite pritiskom tastera ili pomjeranjem miša.\r\n\r\nWindows 7–11 "
    L"podržava sve funkcije. Za Windows Vista SP2 morate instalirati ažuriranja KB971512 i KB2117917; MP4 "
    L"snimanje na Visti ne radi. Potreban je Direct3D 11, a za MP4 i Media Foundation i H.264 koder. "
    L"Interfejs i dokumentacija dostupni su na 36 jezika.",
    L"FlyingSolids паказвае аб’ёмныя целы, якія рухаюцца, круцяцца і сутыкаюцца. Выберыце назіранне за "
    L"прасторай або палёт праз яе і патрэбныя целы. Для кожнага манітора асобна задаюцца хуткасці аб’ектаў "
    L"і камеры 0–1600%, памер 50–200% і 1–10 копій кожнага цела. Асноўнае, запаўняльнае, фонавае і "
    L"контурнае святло ўключаюцца незалежна.\r\n\r\nВыберыце адзін або некалькі радкоў у спісе манітораў. "
    L"Ctrl+A выбірае ўсе; Ctrl і Shift змяняюць выбар. Элементы кіравання і паўзункі анімацыі змяняюць "
    L"толькі налады выбраных манітораў. Выбар радка і ўключэнне вываду яго сцяжком — розныя дзеянні. Выбар "
    L"асобна захоўваецца для праграмы і застаўкі. Калі раней былі выбраны ўсе маніторы, да выбару "
    L"далучаюцца і новыя маніторы.\r\n\r\nВыкарыстоўвайце FlyingSolids.scr як застаўку Windows з асобнымі "
    L"наладамі. Поўнаэкранны перадпрагляд дазваляе змяняць іх падчас анімацыі. OK захоўвае змены, Скасаваць "
    L"або Esc адхіляе іх. Для выхаду з застаўкі націсніце клавішу або паварушыце мышшу.\r\n\r\nWindows 7–11 "
    L"падтрымлівае ўсе функцыі. Для Windows Vista SP2 неабходна ўсталяваць абнаўленні KB971512 і KB2117917; "
    L"запіс MP4 у Vistа не працуе. Патрэбна падтрымка Direct3D 11, а для MP4 таксама Media Foundation і "
    L"кадавальнік H.264. Інтэрфейс і дакументацыя даступны на 36 мовах.",
    L"FlyingSolids показва обемни тела, които се движат, въртят и сблъскват. Изберете наблюдение на "
    L"пространството или полет през него и желаните тела. За всеки монитор отделно се задават скорост на "
    L"обектите и камерата 0–1600%, размер 50–200% и 1–10 копия на всяко тяло. Основната, запълващата, "
    L"околната и контурната светлина се включват независимо.\r\n\r\nИзберете един или повече редове в "
    L"списъка с монитори. Ctrl+A избира всички; Ctrl и Shift променят избора. Контролите и плъзгачите на "
    L"анимацията променят само настройките на избраните монитори. Избирането на ред и включването на изхода "
    L"чрез отметката му са различни действия. Изборът се запомня отделно за приложението и скрийнсейвъра. "
    L"Ако са били избрани всички монитори, включват се и новосвързаните.\r\n\r\nИзползвайте "
    L"FlyingSolids.scr като скрийнсейвър на Windows с отделни настройки. Прегледът на цял екран позволява "
    L"промени в реално време. OK запазва промените; Отказ или Esc ги отхвърля. Излезте от скрийнсейвъра с "
    L"клавиш или движение на мишката.\r\n\r\nWindows 7–11 поддържа всички функции. За Windows Vista SP2 "
    L"трябва да се инсталират актуализациите KB971512 и KB2117917; записът на MP4 не работи във Vista. "
    L"Изисква се поддръжка на Direct3D 11, а за MP4 също Media Foundation и H.264 кодер. Интерфейсът и "
    L"документацията са налични на 36 езика.",
    L"FlyingSolids прикажува просторни тела што се движат, вртат и судираат. Изберете набљудување на "
    L"просторот или лет низ него и саканите тела. За секој монитор одделно се поставуваат брзината на "
    L"објектите и камерата 0–1600%, големината 50–200% и 1–10 копии од секое тело. Главното, "
    L"дополнителното, амбиенталното и контурното светло се вклучуваат независно.\r\n\r\nИзберете еден или "
    L"повеќе редови во списокот на монитори. Ctrl+A ги избира сите; Ctrl и Shift го менуваат изборот. "
    L"Контролите и лизгачите на анимацијата ги менуваат само поставките на избраните монитори. Избирањето "
    L"ред и вклучувањето на излезот преку неговото поле се различни дејства. Изборот се памети одделно за "
    L"апликацијата и чуварот. Ако биле избрани сите монитори, се вклучуваат и новоповрзаните "
    L"монитори.\r\n\r\nКористете FlyingSolids.scr како Windows чувар на екранот со одделни поставки. "
    L"Прегледот на цел екран овозможува измени во живо. OK ги зачувува, а Откажи или Esc ги отфрла "
    L"измените. Излезете од чуварот со копче или движење на глувчето.\r\n\r\nWindows 7–11 ги поддржува сите "
    L"функции. За Windows Vista SP2 мора да се инсталираат ажурирањата KB971512 и KB2117917; MP4 снимањето "
    L"на Vista не работи. Потребна е поддршка за Direct3D 11, а за MP4 и Media Foundation и H.264 кодер. "
    L"Интерфејсот и документацијата се достапни на 36 јазици.",
    L"FlyingSolids приказује просторна тела која се крећу, окрећу и сударају. Изаберите посматрање простора "
    L"или лет кроз простор и жељена тела. За сваки монитор посебно се подешавају брзина објеката и камере "
    L"0–1600%, величина 50–200% и 1–10 копија сваког тела. Главно, допунско, амбијентално и контурно светло "
    L"укључују се независно.\r\n\r\nИзаберите један или више редова у листи монитора. Ctrl+A бира све; Ctrl "
    L"и Shift мењају избор. Контроле и клизачи анимације мењају само подешавања изабраних монитора. Избор "
    L"реда није исто што и укључивање излаза његовим пољем за потврду. Избор се памти одвојено за "
    L"апликацију и чувар екрана. Ако су претходно били изабрани сви монитори, укључују се и новоприкључени "
    L"монитори.\r\n\r\nКористите FlyingSolids.scr као Windows чувар екрана са одвојеним подешавањима. "
    L"Преглед преко целог екрана омогућава измене уживо. OK чува, а Откажи или Esc одбацује измене. Из "
    L"чувара изађите притиском тастера или померањем миша.\r\n\r\nWindows 7–11 подржава све функције. За "
    L"Windows Vista SP2 морате инсталирати ажурирања KB971512 и KB2117917; MP4 снимање на Висти не ради. "
    L"Потребан је Direct3D 11, а за MP4 и Media Foundation и H.264 кодер. Интерфејс и документација "
    L"доступни су на 36 језика.",
    L"FlyingSolids показує об’ємні тіла, які рухаються, обертаються й стикаються. Виберіть спостереження за "
    L"простором або політ крізь нього та потрібні тіла. Для кожного монітора окремо задаються швидкості "
    L"об’єктів і камери 0–1600%, розмір 50–200% та 1–10 копій кожного тіла. Основне, заповнювальне, фонове "
    L"й контурне світло вмикаються незалежно.\r\n\r\nВиберіть один або кілька рядків у списку моніторів. "
    L"Ctrl+A вибирає всі; Ctrl і Shift змінюють вибір. Елементи керування й повзунки анімації змінюють лише "
    L"налаштування вибраних моніторів. Вибір рядка та ввімкнення виведення його прапорцем — різні дії. "
    L"Вибір зберігається окремо для програми й заставки. Якщо раніше були вибрані всі монітори, до вибору "
    L"долучаються й новопідключені.\r\n\r\nВикористовуйте FlyingSolids.scr як заставку Windows з окремими "
    L"налаштуваннями. Повноекранний попередній перегляд дозволяє змінювати їх під час анімації. OK зберігає "
    L"зміни, Скасувати або Esc відхиляє їх. Для виходу із заставки натисніть клавішу або порухайте "
    L"мишею.\r\n\r\nWindows 7–11 підтримує всі функції. Для Windows Vista SP2 потрібно встановити оновлення "
    L"KB971512 і KB2117917; запис MP4 у Vista не працює. Потрібна підтримка Direct3D 11, а для MP4 також "
    L"Media Foundation й кодувальник H.264. Інтерфейс і документація доступні 36 мовами.",
    L"FlyingSolids показывает объёмные тела, которые движутся, вращаются и сталкиваются. Выберите "
    L"наблюдение за пространством или полёт сквозь него и нужные тела. Для каждого монитора отдельно "
    L"задаются скорости объектов и камеры 0–1600%, размер 50–200% и 1–10 копий каждого тела. Основной, "
    L"заполняющий, фоновый и контурный свет включаются независимо.\r\n\r\nВыберите одну или несколько строк "
    L"в списке мониторов. Ctrl+A выбирает все; Ctrl и Shift изменяют выбор. Элементы управления и ползунки "
    L"анимации изменяют только настройки выбранных мониторов. Выбор строки и включение вывода её флажком — "
    L"разные действия. Выбор сохраняется отдельно для приложения и заставки. Если раньше были выбраны все "
    L"мониторы, в выбор включаются и вновь подключённые.\r\n\r\nИспользуйте FlyingSolids.scr как заставку "
    L"Windows с отдельными настройками. Полноэкранный предпросмотр позволяет изменять их во время анимации. "
    L"OK сохраняет изменения, Отмена или Esc отклоняет их. Для выхода из заставки нажмите клавишу или "
    L"подвигайте мышью.\r\n\r\nWindows 7–11 поддерживает все функции. Для Windows Vista SP2 необходимо "
    L"установить обновления KB971512 и KB2117917; запись MP4 в Vista не работает. Нужна поддержка Direct3D "
    L"11, а для MP4 также Media Foundation и кодировщик H.264. Интерфейс и документация доступны на 36 "
    L"языках."
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

/// Returns the localized About website tooltip.
const wchar_t* AboutVisitTooltipText(AppLanguage language) {
    return ABOUT_VISIT_TOOLTIP_TEXTS[static_cast<std::size_t>(NormalizeLanguage(static_cast<int>(language)))];
}
