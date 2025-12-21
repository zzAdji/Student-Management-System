# FAQ

Ici se trouvent les différentes questions que les membres se sont posées ainsi que les réponses obtenues.

## [Question 1]

> Comment on va s'assurer que les codes compiles si on ne fait que écrire des fonctions et pas de main?

Voici comment on s'assure que tout fonctionne sans le "vrai" main final :

1. La Compilation vs L'Exécution
   En C, il y a une différence entre "Compiler" et "Créer l'exécutable".

Compiler (gcc -c) : On peut demander au compilateur de juste vérifier la syntaxe d'un fichier (ex: student.c) et de le traduire en langage machine (fichier .o), sans avoir besoin de main. Si ça compile, ça veut dire qu'il n'y a pas d'erreurs de syntaxe.
Lier (Linking) : C'est seulement à la fin qu'on rassemble tous ces morceaux avec le fichier qui contient le main pour créer le programme final. 2. Le "Secret" : Les Tests Unitaires (Les "Petits Mains")
Même si nous n'avons pas encore le main.c final de l'application, le Membre 5 (Testeur) et les développeurs vont créer des fichiers de tests.

Ce sont en réalité des mini-programmes avec leur propre main temporaire juste pour tester une fonction précise.

Exemple concret : Imagine que tu viens d'écrire la fonction calculateAge dans utils.c. Pour vérifier si elle marche, tu crées un petit fichier test_age.c :

```c
#include "utils.h"
#include <stdio.h>

int main() {
    // Ce main ne sert QUE à tester ta fonction
    Date birthDate = {15, 06, 2000};
    int age = calculateAge(birthDate);

    if (age == 24) {
        printf("✅ Ça marche !\n");
    } else {
        printf("❌ Erreur : J'attendais 24, j'ai eu %d\n", age);
    }

    return 0;
}
```

En résumé
L'équipe Build (Membre 6) configure le Makefile pour compiler chaque fichier individuellement pour vérifier qu'il n'y a pas d'erreurs de code.
L'équipe Test (Membre 5) écrit des petits main temporaires pour vérifier que chaque brique fonctionne isolément.
À la fin, quand tout est solide, on "branche" tout sur le Vrai Main (Membre 1).
C'est comme construire une voiture : on teste le moteur sur un banc d'essai (test unitaire) avant de le mettre dans la carrosserie (intégration finale).

## [Question 2]

> Comment va se passer le travail avec les git et tout ça?

Voici une explication simple de comment vous allez travailler en équipe avec Git, basée sur votre fichier
WORKFLOW.md
.

Visualise le projet comme un arbre :

1. 🌳 L'Arbre des Branches
   Il y a deux branches principales (les troncs) :

main : C'est la version "propre", finale et livrable du projet. On n'y touche presque jamais directement. C'est le produit fini.
develop : C'est le chantier principal. C'est ici que tout le monde rassemble son travail. C'est la version "bêta" qui évolue tous les jours. 2. 👷‍♂️ Ta Routine Quotidienne (Le Workflow)
Chaque fois que tu veux travailler (ajouter une fonction, corriger un bug), tu ne travailles JAMAIS directement sur main ou develop. Tu dois suivre ces étapes :

Étape 1 : Créer ta bulle de travail Tu pars de develop (pour avoir les dernières mises à jour des autres) et tu crées ta propre branche temporaire.

Exemple : feature/ajout-recherche
Commande : git checkout -b feature/ajout-recherche
Étape 2 : Travailler et Sauvegarder Tu codes, tu compiles, tu testes. Quand ça marche, tu "valides" ton travail (commit).

Tu fais des petits paquets logiques.
Commande : git commit -m "feat: ajout recherche dichotomique"
Étape 3 : Envoyer ton travail Tu envoies ta branche sur GitHub.

Commande : git push
Étape 4 : Proposer ton travail (Pull Request) Sur GitHub, tu dis : "Hé l'équipe, j'ai fini la recherche, pouvez-vous vérifier ?" C'est ce qu'on appelle une Pull Request (PR).

Tes collègues relisent ton code.
Si tout est bon, on fusionne ("merge") ta branche dans develop.
Ta fonctionnalité fait maintenant partie du projet commun ! 3. 🛡️ La Règle d'Or
Avant de commencer quoi que ce soit le matin : Mets-toi à jour ! Tes collègues ont peut-être travaillé pendant la nuit.

Va sur develop : git checkout develop
Récupère tout : git pull origin develop
Et seulement là, commence ta nouvelle branche.

## [Question 3]

> Donc si je comprend bien, à part la phase de build et de tests & debug, tout le monde peut travailler en même temps ?

**OUI, c'est exactement ça !**

C'est là toute la puissance de travailler avec des fichiers séparés (`student.c`, `menu.c`, `search.c`, etc.).

Cependant, il existe **une petite condition** pour que ça marche bien : les **dépendances**.

### L'ordre idéal pour éviter de se bloquer :

1.  **D'abord la Structure (Membre 2)** :
    Tout le monde a besoin de savoir à quoi ressemble un `Student` ou une `Date`.
    _Si le Membre 2 définit le fichier `student.h` rapidement (juste les structures), tout le monde peut commencer à travailler immédiatement._

2.  **Ensuite, tout le monde code en même temps** :
    - **Membre 1** code son Menu (il a juste besoin de savoir que `Student` existe, pas besoin que les fonctions de recherche soient finies).
    - **Membre 3** code ses Tris (il trie des `Student`).
    - **Membre 4** code ses Validations (il valide des dates et des noms).

### Analogie du Restaurant 🍳

- **Membre 2 (Structure)** : C'est celui qui décide du menu et des ingrédients (La fiche technique). Tant qu'on n'a pas ça, personne ne peut cuisiner.
- Une fois la fiche technique faite :
  - Le **Saucier** (Membre 3) fait ses sauces.
  - Le **Pâtissier** (Membre 4) fait ses gâteaux.
  - Le **Chef de salle** (Membre 1) prépare les tables.
  - Tout le monde travaille **en parallèle**.
- **Membre 5 (Goûteur)** : Il goûte les plats au fur et à mesure qu'ils sortent.
- **Membre 6 (Plonge/Maintenance)** : Il s'assure que tout le monde a des casseroles propres (Makefile) qui marchent.
