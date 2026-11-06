# DispSavers

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Deutsch](README.de-DE.md) · **Français** · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Português](README.pt-PT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [Dansk](README.da-DK.md) · [Suomi](README.fi-FI.md) · [Íslenska](README.is-IS.md) · [Norsk (bokmål)](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Türkçe](README.tr-TR.md) · [Eesti](README.et-EE.md) · [Gaeilge](README.ga-IE.md) · [Lietuvių](README.lt-LT.md) · [Latviešu](README.lv-LV.md) · [Magyar](README.hu-HU.md) · [Malti](README.mt-MT.md) · [Nederlands](README.nl-NL.md) · [Română](README.ro-RO.md) · [Ελληνικά](README.el-GR.md) · [Bosanski](README.bs-Latn-BA.md) · [Hrvatski](README.hr-HR.md) · [Slovenščina](README.sl-SI.md) · [Crnogorski](README.cnr-Latn-ME.md) · [Беларуская](README.be-BY.md) · [Български](README.bg-BG.md) · [Македонски](README.mk-MK.md) · [Српски](README.sr-Cyrl-RS.md) · [Українська](README.uk-UA.md) · [Русский](README.ru-RU.md)

## FlyingSolids

Animation accélérée par le matériel d’objets 3D pleins.

Sélectionnez un ou plusieurs écrans dans la liste. Le mode de caméra, les objets, l’éclairage, les vitesses, la taille et le nombre de copies ne s’appliquent qu’aux écrans sélectionnés. Chaque écran mémorise ses propres réglages. FlyingSolids affiche des solides 3D éclairés. Les curseurs règlent la vitesse des objets et de la caméra de 0 à 1 600 %, une à dix copies de chaque solide et une taille de 50 à 200 %. Choisissez Observation de l’espace ou le Vol dans l’espace rectiligne, puis activez les solides voulus. Les cases Éclairage principal, Éclairage d’appoint, Éclairage ambiant et Éclairage des contours sous les curseurs contrôlent indépendamment l’éclairage des écrans sélectionnés. L’éclairage ambiant fournit une luminosité de base aux surfaces, et l’éclairage des contours souligne leurs bords. Les réglages sont enregistrés séparément pour l’application et l’économiseur d’écran.

`FlyingSolids.exe` · `FlyingSolids.scr`

## FlightCorridor

Vol accéléré par le matériel dans un couloir et un entonnoir déformables.

FlightCorridor: Vol entre quatre surfaces déformables; Vol dans un entonnoir déformable. Attribuez une seule animation à chaque écran. Texture alterne entre surfaces texturées et modèle filaire. La rotation libre de la caméra change lentement la direction du regard dans les trois dimensions. L’option « Pauses et inversions » ajoute des ralentissements, pauses et inversions aléatoires de la rotation ; le vol vers l’avant continue. La vitesse va de 0 à 1600 %. Chaque écran possède une scène aléatoire indépendante, rendue à sa propre fréquence de rafraîchissement. La lumière principale, la lumière d’appoint, l’éclairage ambiant et l’éclairage des contours se règlent indépendamment pour les écrans sélectionnés. L’éclairage ne concerne que les surfaces texturées.

`FlightCorridor.exe` · `FlightCorridor.scr`

## SpaceFlight

Vol accéléré par le matériel au-dessus de surfaces ondulantes et déformables.

SpaceFlight: Surface ondulante infinie; Vol longue distance — surface déformable; Vol dans un espace déformé par la gravitation. Attribuez une seule animation à chaque écran. Texture alterne entre surfaces texturées et modèle filaire. La rotation libre de la caméra change lentement la direction du regard dans les trois dimensions. L’option « Pauses et inversions » ajoute des ralentissements, pauses et inversions aléatoires de la rotation ; le vol vers l’avant continue. La vitesse va de 0 à 1600 %. Chaque écran possède une scène aléatoire indépendante, rendue à sa propre fréquence de rafraîchissement. La lumière principale, la lumière d’appoint, l’éclairage ambiant et l’éclairage des contours se règlent indépendamment pour les écrans sélectionnés. L’éclairage ne concerne que les surfaces texturées. Les deux animations de surfaces proposent Plan, Ondulations ou Entonnoir. L’entonnoir attire la caméra vers l’intérieur suivant une spirale descendante. Le vol dans un espace déformé par la gravitation affiche une grille filaire tridimensionnelle. Les options de texture, de forme de surface et d’éclairage ne concernent que les deux animations de surfaces.

`SpaceFlight.exe` · `SpaceFlight.scr`

## GameOfLife

Le jeu de la vie de Conway dans un monde commun à plusieurs écrans.

### Règles

Le jeu de la vie de Conway suit B3/S23. Une cellule morte naît avec exactement trois voisines vivantes ; une cellule vivante survit avec deux ou trois. Les huit voisines incluent les diagonales. Toutes évoluent simultanément. Les bords opposés se rejoignent : gauche et droite, haut et bas.

### Écrans et monde commun

Les cases de EXE activent les écrans ; les réglages concernent le monde commun. Un seul écran actif contient le monde entier. Avec une partie des écrans, les lignes et colonnes entièrement vides sont retirées : les écrans gauche et droit se rejoignent si celui du milieu est désactivé. Les trous intérieurs impossibles à supprimer restent simulés. Tous les écrans sélectionnés, ou SCR, conservent le rectangle du bureau avec ses espaces invisibles. Chaque écran montre sa région de la même simulation.

### État initial et motifs

Le départ par défaut est un bruit aléatoire à 25 % de cellules vivantes. La densité initiale, de 0–100 %, agit au prochain redémarrage. Motifs connus uniquement utilise 4 106 motifs intégrés sans bruit et désactive la densité. Choisissez un mélange ou un motif nommé ; les dimensions sont en cellules. Saisissez un nom pour chercher. Tous les motifs du catalogue sont toujours disponibles. Les petits motifs vérifiés sont répartis en copies séparées, les grands ou complexes une fois au centre. Un motif trop grand est centré et tronqué ; changer la taille du monde ou des cellules conserve le choix. Changer de mode ou de motif recrée la scène. Les redémarrages conservent le choix ; le catalogue fonctionne hors ligne.

### Cellules, grille et couleurs

Sans grille, la taille est de 1–64 px. Afficher la grille ajoute un bord de 1 px dans l'espacement existant : la valeur affichée et le curseur diminuent de un, avec 1–63 utilisables. Désactiver rétablit la valeur. Le curseur conserve toute sa plage et revient depuis l'extrémité indisponible ; la case reste active. La scène est conservée, sauf en activant à 1 px : l'espacement passe à 2 px et une nouvelle scène commence. Changer la taille ou les écrans recrée aussi la scène. Un très grand monde peut imposer un minimum supérieur. Les couleurs des cellules, du fond et de la grille changent séparément sans redémarrage. La couleur aléatoire des cellules vivantes change à chaque redémarrage manuel ou automatique de la scène. Votre couleur enregistrée reste intacte et revient lorsque cette option est désactivée. Le même comportement peut être activé séparément pour le fond et la grille ; ces deux nouvelles options sont désactivées par défaut.

### Vitesse, pause et redémarrage automatique

La vitesse est de 0–240 générations/s indépendamment du rafraîchissement ; 0 arrête l'évolution. Pause et Reprendre conservent le monde. Recommencer réinitialise le mode choisi. Le redémarrage automatique facultatif détecte les phases visibles fixes ou exactement répétitives, dont les oscillateurs. Il compare les générations, pas les secondes ; les zones invisibles sont exclues. Les résultats asynchrones peuvent retarder légèrement le redémarrage. Valeurs par défaut : espacement 8 px, 20 générations/s, couleur aléatoire des cellules vivantes et redémarrage automatique activés. La grille est désactivée par défaut. La vitesse atteinte dépend des performances et du nombre de cellules. Le redémarrage automatique compare les régions des écrans activés ; les espaces entre eux continuent d’évoluer mais sont exclus des comparaisons.

### Réinitialiser les valeurs

La réinitialisation rétablit une taille affichée de 8 px avec ou sans grille (espacement de 9 ou 8 px), 20 générations/s, une densité de 25 % et les trois couleurs par défaut. Les autres choix, y compris le motif sélectionné, sont conservés. Une nouvelle scène apparaît seulement si l’espacement change ou si la densité change en mode bruit.

### Application autonome et enregistrement MP4

EXE enregistre les réglages en continu et le premier écran actif en MP4. Le dossier proposé est Vidéos, sinon Documents. Viewport utilise les dimensions et la fréquence de l'écran jusqu'à 60 images/s. TV propose 1920 × 1080, 1440 × 1080 ou 1280 × 720 en 16:9 à 50, 25, 59,94 (60000/1001) ou 29,97 (30000/1001) images/s. Les proportions sont conservées ; TV utilise BT.709 progressif à plage limitée en 4:2:0. La fenêtre indépendante des réglages peut être réduite. OK valide pour le prochain enregistrement ; Annuler ou Esc abandonne les modifications non validées. L'écran enregistré ne peut être désactivé ; les autres sorties peuvent changer. Quitter pendant l'enregistrement demande confirmation. Avec l'animation active, Espace bascule la pause, F9 : Démarrer l’enregistrement ; F10 : Arrêter l’enregistrement. Le pointeur disparaît après 1 seconde d'inactivité et réapparaît en bougeant. Tab/Shift+Tab parcourt les commandes ; Alt active les lettres soulignées. Esc ferme Aide/À propos, ou quitte depuis la fenêtre principale. Écran de veille Windows… ouvre les paramètres système de l’écran de veille.

### Capture et gestion de l’écran de veille dans EXE

La capture sauvegarde en BMP/GIF/JPEG/PNG/TIFF/WebP l’écran en cours d’enregistrement, sinon le premier écran actif, à sa résolution et sans redémarrer la scène. Le dossier proposé est Images, sinon Documents. Bloquer l’écran de veille pendant l’animation empêche son lancement tant que l’animation est visible et non suspendue. Une vitesse nulle n’est pas une pause. L’installation depuis EXE extrait le SCR intégré et le sélectionne comme écran de veille Windows. Installation et désinstallation peuvent nécessiter l’accord d’un administrateur ; la barre d’état indique l’opération jusqu’à sa fin. Si la suppression est bloquée, fermez l’écran de veille en cours, ses réglages et l’aperçu Windows.

### Écran de veille Windows

GameOfLife.scr utilise tous les écrans avec des réglages distincts de EXE. Activer l'aperçu lance l'animation plein écran en gardant les réglages ouverts. Le petit aperçu Windows réduit le monde entier. OK enregistre ; Annuler ou Esc abandonne les changements. Un mouvement de souris ou une touche quitte l'écran de veille plein écran. L'enregistrement MP4 est disponible dans EXE.

### Position et état des fenêtres

La fermeture enregistre séparément la position de la fenêtre principale et d’À propos ; l’aide conserve aussi sa taille et son état normal ou agrandi avant une éventuelle réduction. Cela ne dépend pas de la validation des réglages de l’application. Quitter l’application ferme aussi l’aide et À propos.

### Rendu et licences des motifs

L'évolution et les comparaisons visibles utilisent les shaders Direct3D 11 sur GPU ; un rendu logiciel est disponible si l'initialisation matérielle échoue. Chaque écran utilise le même régulateur de trames éprouvé à sa fréquence. MP4 nécessite Media Foundation et un encodeur H.264. Les motifs proviennent de LifeWiki (GFDL 1.2 ou ultérieure) et des collections du domaine public d'Alan Hensel. Le code est sous licence MIT ; les mentions et licences du catalogue sont distinctes.

[Sources des motifs, licences et détails d'importation](../GameOfLife/LifePatternsLicense.txt)

`GameOfLife.exe` · `GameOfLife.scr`

## FlyingSolids · FlightCorridor · SpaceFlight

### ÉCRANS

La sélection des lignes détermine les écrans à configurer ; elle est distincte des cases qui activent les sorties d’animation. Ctrl+A sélectionne tous les écrans ; Ctrl et Maj modifient la sélection. Toutes les options et tous les curseurs d’animation concernent les écrans sélectionnés. La sélection est mémorisée séparément pour EXE et SCR. Si tous les écrans étaient sélectionnés, les nouveaux le sont également. Des valeurs différentes entre les écrans sélectionnés sont indiquées par des cases à cocher indéterminées et des pointillés sur les boutons radio, les poignées des curseurs et les boutons « Tout activer » et « Tout désactiver ». Les libellés des curseurs affichent un tiret au lieu d’une valeur commune. Modifier une option ou cliquer sur un curseur applique cette valeur à tous les écrans sélectionnés.

### COMMANDES

Activez ou désactivez les sorties d’animation avec les cases des écrans ou en double-cliquant sur leurs lignes. Chaque moniteur utilise une scène indépendante. Capture enregistre un BMP/GIF/JPEG/PNG/TIFF/WebP et le bouton d’enregistrement démarre ou arrête un MP4. Pause arrête l’animation. L’application installe ou désinstalle aussi son économiseur intégré. Les réglages sont enregistrés en continu. Une seule instance de l’application peut fonctionner à la fois. Un nouveau lancement restaure la fenêtre de contrôle réduite et la place au premier plan. Utilisez Tab et Maj+Tab pour passer d’un contrôle à l’autre ; Alt et la lettre soulignée activent une commande. Échap ferme la fenêtre d’aide ou À propos active ; dans la fenêtre de contrôle, cette touche quitte l’application. La pause et le blocage de l’écran de veille s’appliquent à toute l’application, indépendamment des écrans sélectionnés. Lorsque le blocage est activé, l’écran de veille Windows est empêché uniquement tant qu’une animation visible et non suspendue s’affiche sur au moins un écran.

### CAPTURES ET ENREGISTREMENT

Les captures et les enregistrements utilisent le premier moniteur d’animation actif, et non une image combinant tous les moniteurs. BMP/GIF/JPEG/PNG/TIFF/WebP utilise Images, MP4 Vidéos ; Documents sert de repli si ces dossiers n’existent pas. Le bouton Réglages vidéo permet de choisir Viewport ou TV. Viewport conserve les dimensions et la fréquence de rafraîchissement du moniteur d’animation, jusqu’à 60 images par seconde. TV propose 1920 × 1080, 1440 × 1080 ou 1280 × 720 au format 16:9, à 50, 25, 59.94 (60000/1001) ou 29.97 (30000/1001) images par seconde. Le rapport d’aspect est conservé ; TV utilise une vidéo progressive BT.709 à plage limitée et sous-échantillonnage 4:2:0. La résolution et la fréquence d’images ne sont disponibles qu’en mode TV. La fenêtre Réglages vidéo peut être réduite et ne bloque pas les autres fenêtres de l’application. OK enregistre les choix pour le prochain enregistrement MP4 ; Annuler ou Échap abandonne les modifications non confirmées. La sortie d’animation du moniteur enregistré ne peut pas être désactivée pendant l’enregistrement ; les changements concernant les autres moniteurs ne l’arrêtent pas. Fermer l’application pendant un enregistrement nécessite une confirmation, car cela arrête aussi l’enregistrement.

### APERÇU ET COMMANDES

Activer l’aperçu lance un aperçu plein écran sur tous les moniteurs ; la boîte de dialogue reste ouverte pour les réglages en direct. OK enregistre les réglages, Annuler les abandonne. Échap ou un mouvement de souris quitte le plein écran. Utilisez Tab et Maj+Tab pour passer d’un contrôle à l’autre ; Alt et la lettre soulignée activent une commande. Échap dans les réglages équivaut à Annuler ; dans l’aide ou À propos, cette touche ferme uniquement cette fenêtre.

### Configuration requise

Windows 7 à Windows 11 prennent en charge toutes les fonctions, y compris les captures BMP/GIF/JPEG/PNG/TIFF/WebP et l’enregistrement MP4. Pour exécuter l’application sous Windows Vista SP2, il est nécessaire d’installer les mises à jour KB971512 et KB2117917. L’enregistrement MP4 ne fonctionne pas sous Vista dans la version actuelle. L’affichage nécessite Direct3D 11, et pas seulement un ancien environnement d’exécution DirectX. L’enregistrement MP4 nécessite les composants Media Foundation et un encodeur H.264 disponibles. L’application autonome peut également fonctionner sous Linux avec Wine ; l’intégration comme économiseur d’écran est disponible uniquement sous Windows.

## Compilation

Ouvrez `DispSavers.slnx` dans Visual Studio avec MSVC v145 et un SDK Windows. Sélectionnez `Release | x86` et régénérez la solution pour produire `Release\FlyingSolids.exe`, `Release\FlightCorridor.exe`, `Release\GameOfLife.exe`, `Release\GameOfLife.scr`, `Release\SpaceFlight.exe` et `Release\FlyingSolids.scr`, `Release\FlightCorridor.scr`, `Release\SpaceFlight.scr`. Aucune configuration x64 n’est fournie.

Exécutez `PackageRelease.ps1` sans paramètres de signature pour empaqueter ces fichiers compilés. Le script utilise des copies temporaires, ne modifie pas les fichiers dans `Release` et vérifie simplement les signatures valides existantes. Il crée l’unique archive `DispSavers-<version>-win32.zip`, contenant `FlyingSolids\FlyingSolids.exe`, `FlyingSolids\FlyingSolids.scr`, `FlyingSolids\license.txt`, `FlightCorridor\FlightCorridor.exe`, `FlightCorridor\FlightCorridor.scr`, `FlightCorridor\license.txt`, `GameOfLife\GameOfLife.exe`, `GameOfLife\GameOfLife.scr`, `GameOfLife\license.txt`, `SpaceFlight\SpaceFlight.exe`, `SpaceFlight\SpaceFlight.scr` et `SpaceFlight\license.txt`. L’ancienne archive ZIP est supprimée au début de l’exécution ; un échec de vérification empêche la création d’une nouvelle archive.

## Licence

DispSavers est distribué sous [licence MIT](../license.txt). Copyright © Petr Červinka — FortSoft 2026
