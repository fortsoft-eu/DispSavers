# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · **Français** · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids est une application native Win32/x86 utilisant Direct3D et un économiseur d’écran Windows. Il affiche des solides géométriques tridimensionnels éclairés. Les solides se déplacent et tournent indépendamment, puis rebondissent sans se traverser.

## Fonctionnalités

- **Observation de l’espace** et **Vol dans l’espace** en ligne droite. Sélectionnez un ou plusieurs écrans dans la liste. Le mode de caméra, les objets, l’éclairage, les vitesses, la taille et le nombre de copies ne s’appliquent qu’aux écrans sélectionnés. Chaque écran mémorise ses propres réglages.
- Contrôle indépendant des éclairages principal, d’appoint, ambiant et des contours
- Scène indépendante sur chaque moniteur sélectionné
- Une à dix copies de chaque solide activé
- Vitesse des objets et de la caméra de 0 à 1 600 %, taille de 50 à 200 %
- Surfaces brillantes, éclairage, couleurs propres et gestion des collisions
- Rendu adapté à la fréquence de rafraîchissement de chaque écran
- Captures PNG et enregistrement MP4 dans l’application autonome
- Réglages distincts pour l’application et l’économiseur
- 30 types de solides et interface en 17 langues

## Solides

Le catalogue comprend des polyèdres, prismes réguliers, pyramides et leurs coupes planes, cônes et cylindres et leurs coupes planes, un paraboloïde de révolution fermé par un plan, des solides dérivés de la boule, des ellipsoïdes, un ovoïde, un sphérocylindre et un tore. Les libellés emploient la terminologie géométrique française consacrée.

## Éclairage

Les cases `Éclairage principal`, `Éclairage d’appoint`, `Éclairage ambiant` et `Éclairage des contours` sous les curseurs contrôlent indépendamment l’éclairage de toute la scène. L’éclairage ambiant fournit une luminosité de base aux surfaces, et l’éclairage des contours souligne leurs bords. Par défaut, les éclairages principal, ambiant et des contours sont activés, et l’éclairage d’appoint est désactivé. Les réglages sont enregistrés séparément pour l’application et l’économiseur d’écran.

## Application et économiseur

`FlyingSolids.exe` conserve une seule fenêtre de commande pendant l’animation. Plusieurs moniteurs peuvent être sélectionnés, basculés par double-clic ou tous détachés. L’EXE peut installer ou désinstaller l’économiseur qu’il contient. Une seule instance de l’application peut fonctionner à la fois. Un nouveau lancement restaure la fenêtre de contrôle réduite et la place au premier plan. Utilisez Tab et Maj+Tab pour passer d’un contrôle à l’autre ; Alt et la lettre soulignée activent une commande. Échap ferme la fenêtre d’aide ou À propos active ; dans la fenêtre de contrôle, cette touche quitte l’application. Les captures et les enregistrements utilisent le premier moniteur d’animation actif, et non une image combinant tous les moniteurs. PNG utilise Images, MP4 Vidéos ; Documents sert de repli si ces dossiers n’existent pas. Le bouton Réglages vidéo permet de choisir Viewport ou TV. Viewport conserve les dimensions et la fréquence de rafraîchissement du moniteur d’animation, jusqu’à 60 images par seconde. TV propose 1920 × 1080, 1440 × 1080 ou 1280 × 720 au format 16:9, à 50, 25, 59.94 (60000/1001) ou 29.97 (30000/1001) images par seconde. Le rapport d’aspect est conservé ; TV utilise une vidéo progressive BT.709 à plage limitée et sous-échantillonnage 4:2:0. La résolution et la fréquence d’images ne sont disponibles qu’en mode TV. La fenêtre Réglages vidéo peut être réduite et ne bloque pas les autres fenêtres de l’application. OK enregistre les choix pour le prochain enregistrement MP4 ; Annuler ou Échap abandonne les modifications non confirmées. Le moniteur enregistré ne peut pas être désélectionné pendant l’enregistrement ; les changements concernant les autres moniteurs ne l’arrêtent pas. Fermer l’application pendant un enregistrement nécessite une confirmation, car cela arrête aussi l’enregistrement. Bloquer l’écran de veille pendant l’animation empêche le lancement de l’économiseur d’écran Windows uniquement lorsque l’animation est réellement visible et n’est pas en pause. `FlyingSolids.scr` possède sa propre boîte de dialogue sans enregistrement. Le plein écran crée une scène indépendante par moniteur. Activer l’aperçu dans les réglages lance un aperçu plein écran distinct sur tous les moniteurs. Il utilise les réglages actuels, permet des modifications en direct et peut être arrêté. Une touche quelconque, un mouvement de souris ou un clic quitte l’économiseur plein écran. Échap dans les réglages équivaut à Annuler ; dans l’aide ou À propos, cette touche ferme uniquement cette fenêtre.

## Stockage des réglages

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Configuration requise

Windows 7 à Windows 11 prennent en charge toutes les fonctions, y compris les captures PNG et l’enregistrement MP4. Pour exécuter l’application sous Windows Vista SP2, il est nécessaire d’installer les mises à jour KB971512 et KB2117917. L’enregistrement MP4 ne fonctionne pas sous Vista dans la version actuelle. L’affichage nécessite Direct3D 11, et pas seulement un ancien environnement d’exécution DirectX. L’enregistrement MP4 nécessite les composants Media Foundation et un encodeur H.264 disponibles.

## Compilation

Ouvrez `DispSavers.slnx` dans Visual Studio avec MSVC v145 et un SDK Windows. Sélectionnez `Release | x86` et régénérez la solution pour produire `Release\FlyingSolids.exe` et `Release\FlyingSolids.scr`. Aucune configuration x64 n’est fournie. La signature est activée par défaut pour Release et Debug. Dans les propriétés du projet `FlyingSolids`, page `Signing`, indiquez le nom ou l’empreinte d’un certificat de signature de code valide avec une clé privée dans le magasin `Personal (My)` de l’utilisateur actuel. Ces réglages communs à l’EXE et au SCR sont enregistrés dans `FlyingSolids.vcxproj.user`, ignoré par Git. SignTool est trouvé automatiquement dans PATH ou le SDK Windows. Si vous utilisez SimplySign, connectez-vous à SimplySign Desktop avant la compilation. La compilation signe d’abord le SCR et lui ajoute un horodatage RFC 3161 SHA-256 obligatoire via le serveur d’horodatage configuré, puis l’intègre dans l’EXE, qui est également signé et horodaté. Indiquez l’URL du serveur d’horodatage RFC 3161 dans le champ `Timestamp server`. Tout échec de signature, d’horodatage ou de vérification interrompt la compilation ; les fichiers dont la signature horodatée est déjà valide ne sont pas signés à nouveau.

Exécutez `PackageRelease.ps1` sans paramètres de signature pour empaqueter ces fichiers compilés. Le script utilise des copies temporaires, ne modifie pas les fichiers dans `Release` et vérifie simplement les signatures valides existantes. Il crée l’unique archive `DispSavers-<version>-win32.zip`, contenant `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` et `SpaceFlight\license.txt`. L’ancienne archive ZIP est supprimée au début de l’exécution ; un échec de vérification empêche la création d’une nouvelle archive.

## Licence

FlyingSolids est distribué sous [licence MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026


## FlightCorridor

FlightCorridor propose Vol entre quatre surfaces déformables et Vol dans un entonnoir déformable. Attribuez un seul vol à chaque moniteur : sélectionnez sa ligne, puis le bouton radio correspondant. Par défaut, la première animation est sélectionnée sur tous les moniteurs.

`Release\FlightCorridor.exe` · `Release\FlightCorridor.scr` · [FlightCorridor](../FlightCorridor/README.fr-FR.md)

## SpaceFlight

SpaceFlight propose „Surface ondulante infinie“ et „Vol longue distance — surface déformable“. Attribuez un seul vol à chaque moniteur : sélectionnez sa ligne, puis le bouton radio correspondant. Par défaut, la première animation est sélectionnée sur tous les moniteurs.

`Release\SpaceFlight.exe` · `Release\SpaceFlight.scr` · [SpaceFlight](../SpaceFlight/README.fr-FR.md)
