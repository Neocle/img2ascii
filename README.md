# img2ascii

Un convertisseur d'images PGM en ASCII art écrit en C++.

## Description

Ce programme convertit des images au format PGM puis en ASCII art en utilisant une palette de caractères personnalisable. L'image peut être redimensionnée pour s'adapter à des contraintes de largeur et hauteur maximales tout en préservant son ratio d'aspect.

## Fonctionnalités

- Conversion d'images en ASCII art
- Palettes de caractères personnalisées (UTF-8)
- Redimensionnement avec préservation du ratio d'aspect
- Sortie vers la console ou vers un fichier texte

## Compilation

Simplement: 
```bash
make
```

## Utilisation

```bash
img2ascii [options]
```

### Options

- `--input fichier` : Spécifie le fichier image PGM à convertir. Si non spécifié, le fichier sera demandé via la console.

- `--output fichier` : Spécifie le fichier texte de sortie. Si non spécifié, l'ASCII art est affiché dans la console.

- `--palette fichier` : Spécifie un fichier contenant la palette ASCII. Chaque ligne du fichier contient un caractère UTF-8, du plus sombre au plus clair. Si non spécifié, le fichier sera demandé via la console. Des palettes sont disponibles par défaut (classic / classicDouble / utf8 / utf8Double)

- `--width nombre` : Spécifie la largeur maximale de l'ASCII art en caractères. Si non spécifié, aucune limite n'est fixée.

- `--height nombre` : Spécifie la hauteur maximale de l'ASCII art en lignes. Si non spécifié, aucune limite n'est fixée.

- `--help` : Affiche l'aide.

### Exemples

Conversion simple avec affichage console :
```bash
img2ascii --input image.png --palette classic
```

Conversion avec sortie vers un fichier et fichier de palette :
```bash
img2ascii --input image.jpg --palette palette.txt --output resultat.txt
```

Conversion avec redimensionnement et image pgm :
```bash
img2ascii --input image.pgm --palette palette.txt --width 80 --height 40
```

## Format de fichier palette

Le fichier palette doit contenir un caractère par ligne, du plus sombre au plus clair. Exemple :

```
W
w
l
i
:
,
.
 
```

La dernière ligne doit être un espace pour représenter les zones les plus claires de l'image.

## Remarques

- La taille de l'ASCII art est bornée par la taille de l'image en entrée
- Le ratio d'aspect de l'image originale est toujours préservé
- Les valeurs `--width` et `--height` sont des maximums, pas des tailles exactes
- Le programme utilise un algorithme d'échantillonnage par moyenne pour réduire la taille des images

## Architecture du code

Le projet est organisé en plusieurs classes :

- **ImageConverter** : Conversion des images d'entrées (JPG/PNG) en image PGM (Nuance de gris).
- **Arguments** : Gestion et parsing des arguments en ligne de commande
- **Image** : Chargement et manipulation des images PGM
- **Palette** : Gestion de la palette de caractères ASCII
- **AsciiArt** : Génération et affichage de l'ASCII art

## Format PGM supporté

Le programme supporte les fichiers PGM au format binaire (P5) avec les caractéristiques suivantes :
- En-tête avec format P5
- Dimensions de l'image
- Valeur maximale des pixels (typiquement 255)
- Données binaires des pixels en niveaux de gris

## Auteurs

- [ALIROL Loïs](https://github.com/Neocle)
- [ROMÉAS Victor](https://github.com/Neimeyos)

## Licence

Ce projet est sous licence **GNU General Public License version 3 (GPL-3.0)**.  
Voir le fichier [LICENSE](LICENSE) pour les détails.
