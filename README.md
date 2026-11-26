# Windows Console RPG

![C++20](https://img.shields.io/badge/C%2B%2B-20-00599C?logo=cplusplus&logoColor=white)
![Plateforme](https://img.shields.io/badge/Plateforme-Windows-0078D6?logo=windows&logoColor=white)
![Licence](https://img.shields.io/badge/Licence-Apache%202.0-green)

Un jeu de rôle (RPG) textuel au tour par tour développé en **C++20** pour la console Windows. Choisissez votre classe, explorez des régions générées aléatoirement, développez votre puissance au fil des combats et triomphez de l'**Empereur Orc** pour sauver le royaume.

---

## Fonctionnalités

- **3 classes jouables** aux mécaniques distinctes : **Guerrier** (Rage), **Mage** (Mana) et **Nécromancien** (Vol de vie).
- **Exploration aléatoire** à travers plusieurs biomes et rencontres (embuscades, entraînement, soins, boss final).
- **Combats au tour par tour** avec choix de cible, parade réduisant les dégâts subis de moitié et possibilité de fuite.
- **Système de progression** : gain d'expérience (XP), montée de niveau et augmentation de la puissance (+5 % par niveau).
- **Économie en pièces de cuivre** : récompenses de combat et achat de soins auprès d'un mage curatif au village.
- **Affichage console coloré** (codes ANSI) et saisies clavier réactives via `_getch()`.

---

## Classes jouables

Chaque héros démarre au **niveau 1** avec **0 XP** et **100 pièces de cuivre**.

| Classe | PV max | Puissance | Ressource / Passif | Mécanique spéciale |
| :--- | :---: | :---: | :--- | :--- |
| **Guerrier** (`Warrior`) | 120 | 12 | Rage (départ : 0) | Gagne `+12` de rage par attaque et `+8` par parade. À `100` de rage, déclenche un énorme coup d'épée (`Puissance + 8`). |
| **Mage** (`Mage`) | 80 | 15 | Mana (départ : 100) | Lance une **Boule de feu** (`-50` mana). Sous `16` de mana, frappe au bâton (`Puissance - 8`) et régénère `+7` de mana. |
| **Nécromancien** (`Necromancer`) | 88 | 9 | Vol de vie | Chaque attaque inflige sa puissance et restaure **30 %** des dégâts en PV (plafonné aux PV max). |

---

## Bestiaire

| Ennemi | PV | Puissance | Zone d'apparition | Particularité |
| :--- | :---: | :---: | :--- | :--- |
| **Gobelin** (`Goblin`) | 50 | 6 | Plaines sauvages | Attaque en groupe de 1 à 3 individus. |
| **Orc** (`Orc`) | 120 | 13 | Montagnes | Accumule de la rage (`+12` attaque / `+8` parade) pour un coup de massue renforcé (`+8`). |
| **Empereur Orc** (`EmperorOrc`) *(Boss)* | 532 | 28 | Temple Ancien | Boss final. Accumule de la rage (`+15` attaque / `+10` parade) pour un giga coup de massue (`+18`). |

---

## Exploration et événements

À chaque déplacement, un événement est tiré aléatoirement selon les probabilités suivantes :

| Lieu | Probabilité | Événements possibles |
| :--- | :---: | :--- |
| **Montagnes** | 10 % | Combat contre un **Orc Sauvage** (1 chance sur 3) ou zone calme. |
| **Plaines sauvages** | 30 % | Embuscade par **1 à 3 Gobelins** (1 chance sur 3) ou zone calme. |
| **Village** | 30 % | **Villageois** proposant un entraînement (`0` à `36` XP), **Mage curatif** soignant de `1` à `30` PV pour **8 pièces de cuivre**, ou rien. |
| **Temple Ancien** | 5 % | Combat final contre l'**Empereur Orc**. |
| **Chemin abandonné** | 25 % | Aucun événement. |

### Récompenses et progression

- **Victoire (hors boss)** : `+30 XP` et `+3 pièces de cuivre` par ennemi vaincu.
- **Montée de niveau** : premier palier à `100 XP`, multiplié par `1,5` à chaque nouveau niveau ; la puissance du héros augmente de **+5 %** par niveau.
- **Victoire contre l'Empereur Orc** : vous sauvez le royaume et terminez la partie.

---

## Commandes

> **Note :** Les commandes en jeu sont lues directement au clavier (touches en **minuscules**, disposition AZERTY pour les déplacements).

| Phase | Touche | Action |
| :--- | :---: | :--- |
| **Menu principal** | `p` | Lancer une nouvelle partie |
| | `c` | Afficher les crédits |
| | `q` | Quitter le jeu |
| **Exploration** | `z` / `q` / `s` / `d` | Se déplacer (Haut / Gauche / Bas / Droite) |
| **Combat** | `a` | Attaquer (puis choisir l'index de la cible de `0` à `n - 1`) |
| | `d` | Défendre / Parer (divise par 2 les dégâts de la prochaine attaque reçue) |
| | `f` | Fuir le combat |
| **Fin de partie** | `r` | Recommencer une partie |
| | `q` | Quitter le jeu |

---

## Installation et compilation

### Prérequis

- **Système d'exploitation** : Windows 10 ou 11 (dépend de `<conio.h>` et des commandes console Windows)
- **Compilateur / IDE** : Visual Studio avec la charge de travail *Développement Desktop en C++* (standard **C++20**, SDK Windows 10.0)

### 1. Cloner le dépôt

```bash
git clone https://github.com/Logan-FORNIER/Windows-Console-RPG.git
cd Windows-Console-RPG
```

### 2. Compiler avec Visual Studio

1. Ouvrez la solution `ConsoleRPG.slnx` dans Visual Studio (ou `ConsoleRPG/ConsoleRPG.vcxproj`).
2. Sélectionnez la configuration souhaitée (`Debug` ou `Release`) ainsi que la plateforme (`x64` ou `x86`).
3. Compilez et lancez le jeu (`Ctrl + F5` ou `F5`).

> Si vous utilisez une version antérieure de Visual Studio (par exemple Visual Studio 2022), ouvrez les propriétés du projet `ConsoleRPG` et adaptez l'**Ensemble d'outils de la plateforme** (configuré sur `v145` par défaut, ex. vers `v143`).

### 3. Compiler en ligne de commande (MSBuild)

Depuis une invite de commandes développeur Visual Studio (*Developer Command Prompt*) :

```bash
msbuild ConsoleRPG/ConsoleRPG.vcxproj /p:Configuration=Release /p:Platform=x64
```

L'exécutable généré se trouvera dans `ConsoleRPG\x64\Release\ConsoleRPG.exe` (ou `x64\Release\ConsoleRPG.exe` si compilé depuis la solution Visual Studio).

---

## Architecture du projet

Le projet repose sur une architecture orientée objet en C++20 :

- **Polymorphisme** : classe abstraite `Character` déclinée en héros (`Warrior`, `Mage`, `Necromancer`) et ennemis (`Goblin`, `Orc`, `EmperorOrc`).
- **Gestion mémoire moderne** : gestion des entités par pointeurs intelligents (`std::unique_ptr`) dans `HeroesManager` et `EnnemyManager`.
- **Machine à états** : boucle principale gérée dans `Game` via `GameState` (`Menu`, `Exploration`, `Combat`, `Victory`, `Defeat`, `Quit`).
- **Sécurisation des entrées** : validation des saisies numériques dans `InputManager::NumberSecurity`.

```text
Windows-Console-RPG/
├── ConsoleRPG.slnx              # Solution Visual Studio
├── README.md
└── ConsoleRPG/
    ├── ConsoleRPG.vcxproj       # Configuration du projet MSVC (C++20)
    ├── LICENSE                  # Licence Apache 2.0
    ├── main.cpp                 # Point d'entrée
    ├── Game.h / Game.cpp        # Boucle de jeu, machine à états, événements
    ├── Character.h / .cpp       # Classe de base abstraite des entités
    ├── Warrior.h / .cpp         # Classe jouable : Guerrier
    ├── Mage.h / .cpp            # Classe jouable : Mage
    ├── Necromancer.h / .cpp     # Classe jouable : Nécromancien
    ├── Goblin.h / .cpp          # Ennemi : Gobelin
    ├── Orc.h / .cpp             # Ennemi : Orc
    ├── EmperorOrc.h / .cpp      # Boss final : Empereur Orc
    ├── HeroesManager.h / .cpp   # Gestionnaire des héros
    ├── EnnemyManager.h / .cpp   # Gestionnaire des ennemis
    └── InputManager.h / .cpp    # Gestion et validation des entrées clavier
```

---

## Auteur

Développé par **Logan FORNIER** (**EL_IKO**).

## Licence

Ce projet est distribué sous licence **Apache 2.0**. Voir le fichier [LICENSE](ConsoleRPG/LICENSE) pour plus d'informations.
