# FlyingSolids

[Čeština](README.cs-CZ.md) · [English (US)](../README.md) · [Deutsch](README.de-DE.md) · **Français** · [Español](README.es-ES.md) · [Italiano](README.it-IT.md) · [Polski](README.pl-PL.md) · [Slovenčina](README.sk-SK.md) · [English (UK)](README.en-GB.md) · [English (Australia)](README.en-AU.md) · [Português](README.pt-PT.md) · [Norsk](README.nb-NO.md) · [Svenska](README.sv-SE.md) · [Suomi](README.fi-FI.md) · [Dansk](README.da-DK.md) · [Íslenska](README.is-IS.md) · [Türkçe](README.tr-TR.md)

FlyingSolids est une application native Win32/x86 utilisant Direct3D et un économiseur d’écran Windows. Il affiche des solides géométriques tridimensionnels éclairés. Les solides se déplacent et tournent indépendamment, puis rebondissent sans se traverser. Les conditions initiales et les nouvelles positions de vol proviennent du générateur cryptographique de Windows, avec une mise en mémoire tampon limitant la charge du processeur.

## Fonctionnalités

- **Observation de l’espace** et **Vol dans l’espace** en ligne droite
- Activation et désactivation indépendantes de l’éclairage principal et de l’éclairage d’appoint
- Scène indépendante sur chaque moniteur sélectionné
- Une à dix copies de chaque solide activé
- Vitesse des objets et de la caméra de 0 à 1 600 %, taille de 50 à 200 %
- Surfaces brillantes, éclairage, couleurs propres et gestion des collisions
- Rendu adapté à la fréquence de rafraîchissement de chaque écran
- Captures PNG et enregistrement MP4 dans l’application autonome
- Réglages distincts pour l’application et l’économiseur
- 27 types de solides et interface en 17 langues

## Solides

Le catalogue comprend des polyèdres, prismes réguliers, pyramides et leurs coupes planes, cônes et cylindres et leurs coupes planes, un paraboloïde de révolution fermé par un plan, des solides dérivés de la boule, des ellipsoïdes, un ovoïde, un sphérocylindre et un tore. Les libellés emploient la terminologie géométrique française consacrée.

## Éclairage

Les cases `Éclairage principal` et `Éclairage d’appoint` sous les curseurs de droite activent ou désactivent indépendamment les deux sources lumineuses pour toute la scène. Par défaut, `Éclairage principal` est activé et `Éclairage d’appoint` est désactivé. Les réglages d’éclairage sont enregistrés séparément pour l’application et l’économiseur d’écran.

## Application et économiseur

`FlyingSolids.exe` conserve une seule fenêtre de commande pendant l’animation. Plusieurs moniteurs peuvent être sélectionnés, basculés par double-clic ou tous détachés. Les PNG sont enregistrés par défaut dans **Images**, les MP4 dans **Vidéos**, avec **Documents** comme repli. L’EXE peut installer ou désinstaller l’économiseur qu’il contient.

Une seule instance de l’application peut fonctionner à la fois. Un nouveau lancement restaure la fenêtre de contrôle réduite, la redessine et la place au premier plan.

Utilisez Tab et Maj+Tab pour passer d’un contrôle à l’autre ; Alt et la lettre soulignée activent une commande. Échap ferme la fenêtre d’aide ou À propos active ; dans la fenêtre de contrôle, cette touche quitte l’application.

Les captures et les enregistrements utilisent le premier moniteur d’animation actif, et non une image combinant tous les moniteurs. PNG utilise Images, MP4 Vidéos ; Documents sert de repli si ces dossiers n’existent pas. La fréquence MP4 suit celle du moniteur, avec un maximum de 60 images par seconde.

`FlyingSolids.scr` possède sa propre boîte de dialogue sans enregistrement. Le plein écran crée une scène indépendante par moniteur.

Activer l’aperçu dans les réglages lance un aperçu plein écran distinct sur tous les moniteurs. Il utilise les réglages actuels, permet des modifications en direct et peut être arrêté. Une touche quelconque, un mouvement de souris ou un clic quitte l’économiseur plein écran.

Échap dans les réglages équivaut à Annuler ; dans l’aide ou À propos, cette touche ferme uniquement cette fenêtre.

## Stockage des réglages

```text
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\Standalone
HKEY_CURRENT_USER\Software\FortSoft\FlyingSolids\ScreenSaver
```

## Configuration requise

Windows 7 à Windows 11 prennent en charge toutes les fonctions, y compris les captures PNG et l’enregistrement MP4.

Windows Vista SP2: KB971512, KB2117917. L’enregistrement MP4 ne fonctionne pas sous Vista dans la version actuelle.

L’affichage nécessite Direct3D 11, et pas seulement un ancien environnement d’exécution DirectX. L’enregistrement MP4 nécessite les composants Media Foundation et un encodeur H.264 disponibles.

## Compilation

Ouvrez `DispSavers.slnx`, sélectionnez `Release | x86`, puis régénérez la solution avec MSVC v145 et un SDK Windows. L’EXE et le SCR sont produits. `PackageRelease.ps1` crée l’unique paquet `DispSavers-<version>-win32.zip` de la solution, avec les fichiers et `license.txt` dans le sous-dossier `FlyingSolids`. Aucune configuration x64 n’est fournie.

## Licence

FlyingSolids est distribué sous [licence MIT](../license.txt).

Copyright © Petr Červinka — FortSoft 2026
