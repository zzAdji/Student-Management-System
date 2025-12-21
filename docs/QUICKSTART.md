# 🚀 Guide de Démarrage Rapide

Ce guide vous permettra de commencer à travailler sur le projet en moins de 10 minutes.

## ⚡ Démarrage Rapide (5 minutes)

### 1. Cloner le Projet

```bash
git clone https://github.com/votre-equipe/gestion-etudiants.git
cd gestion-etudiants
```

### 2. Vérifier la Structure

```bash
ls -la
# Vous devriez voir : src/, include/, Makefile, README.md, etc.
```

### 3. Compiler

```bash
make
```

### 4. Exécuter

```bash
make run
# ou
./bin/sms
```

## 👤 Configuration Initiale Git

```bash
# Configurer votre identité (si pas déjà fait)
git config --global user.name "Votre Nom"
git config --global user.email "votre.email@example.com"

# Vérifier les branches
git branch -a
```

## 🔧 Première Tâche

### Étape 1 : Créer Votre Branche

```bash
# Aller sur develop
git checkout develop

# Créer votre branche
git checkout -b feature/votre-nom-prenom
```

### Étape 2 : Choisir Votre Module

Selon votre rôle :

- **Membre 1** : `menu.c` et `main.c`
- **Membre 2** : `etudiant.c` et `operations.c`
- **Membre 3** : `recherche.c` et `tri.c`
- **Membre 4** : `utils.c` et `validation.c`
- **Membre 5** : Documentation et tests
- **Membre 6** : Makefile et intégration

### Étape 3 : Créer Vos Fichiers

**Exemple pour Membre 2** :

```bash
# Créer le fichier header
touch include/etudiant.h

# Créer le fichier source
touch src/etudiant.c

# Copier les templates depuis les artifacts fournis
# (voir etudiant.h et etudiant.c dans les artifacts)
```

### Étape 4 : Développer

1. Ouvrez vos fichiers dans votre éditeur favori
2. Implémentez vos fonctions
3. Testez régulièrement avec `make && make run`

### Étape 5 : Commiter

```bash
# Vérifier vos modifications
git status

# Ajouter vos fichiers
git add src/etudiant.c include/etudiant.h

# Commiter avec un message clair
git commit -m "feat(etudiant): ajout structure et fonctions de base"

# Pousser
git push -u origin feature/votre-nom-prenom
```

### Étape 6 : Créer une Pull Request

1. Aller sur GitHub
2. Cliquer sur "Pull Requests"
3. Cliquer sur "New Pull Request"
4. Sélectionner `develop` comme base
5. Sélectionner votre branche comme compare
6. Remplir la description
7. Créer la PR

## 📋 Checklist Quotidienne

### Début de Journée

```bash
# 1. Mettre à jour develop
git checkout develop
git pull origin develop

# 2. Retourner sur votre branche
git checkout feature/votre-branche

# 3. Intégrer les nouveautés de develop
git merge develop
```

### Pendant le Travail

```bash
# Compiler fréquemment
make

# Si erreurs
make clean
make

# Tester
make run
```

### Fin de Journée

```bash
# 1. Sauvegarder votre travail
git add .
git commit -m "feat: description de ce que vous avez fait"

# 2. Pousser
git push

# 3. Vérifier sur GitHub que tout est OK
```

## 🎯 Objectifs par Module

### Module 1 : Menu Principal (Membre 1)

**Fichiers** : `main.c`, `menu.c`, `menu.h`

**Tâches** :

1. Créer la boucle principale
2. Afficher le menu avec design
3. Gérer les choix utilisateur
4. Appeler les fonctions appropriées

**Template main.c** :

```c
#include "menu.h"
#include "etudiant.h"

int main(void) {
    int nombre_etudiants;
    int choix;

    // Demander nombre d'étudiants
    printf("Nombre d'étudiants : ");
    scanf("%d", &nombre_etudiants);

    // Allouer mémoire
    Gestion_des_Etudians *tableau =
        malloc(nombre_etudiants * sizeof(Gestion_des_Etudians));

    if (tableau == NULL) {
        fprintf(stderr, "Erreur allocation mémoire\n");
        return 1;
    }

    int nombre_actuel = 0;

    // Boucle principale
    do {
        afficher_menu();
        choix = obtenir_choix();
        traiter_choix(choix, tableau, &nombre_actuel, nombre_etudiants);
    } while (choix != 0);

    // Libérer mémoire
    free(tableau);

    return 0;
}
```

### Module 2 : Structure Étudiant (Membre 2)

**Fichiers** : `etudiant.c`, `etudiant.h`, `operations.c`, `operations.h`

**Tâches** :

1. Définir la structure `Gestion_des_Etudians`
2. Implémenter `enregistrer_etudiant()`
3. Implémenter `modifier_etudiant()`
4. Implémenter `supprimer_etudiant()`
5. Implémenter `afficher_tous_etudiants()`

**Points Clés** :

- Utiliser des pointeurs pour modification
- Valider les entrées utilisateur
- Gérer les erreurs d'allocation

### Module 3 : Recherche et Tri (Membre 3)

**Fichiers** : `recherche.c`, `recherche.h`, `tri.c`, `tri.h`

**Tâches** :

1. Recherche linéaire par matricule
2. Recherche dichotomique
3. Tri alphabétique (utiliser `qsort`)
4. Tri par filière

**Algorithme Recherche Dichotomique** :

```c
int recherche_dichotomique(const Gestion_des_Etudians *tableau,
                           int nombre,
                           const char *matricule) {
    int gauche = 0;
    int droite = nombre - 1;

    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;
        int cmp = strcmp(tableau[milieu].matricule, matricule);

        if (cmp == 0) {
            return milieu;  // Trouvé
        } else if (cmp < 0) {
            gauche = milieu + 1;
        } else {
            droite = milieu - 1;
        }
    }

    return -1;  // Non trouvé
}
```

### Module 4 : Utilitaires (Membre 4)

**Fichiers** : `utils.c`, `utils.h`, `validation.c`, `validation.h`

**Tâches** :

1. Calculer âge étudiant
2. Valider dates
3. Valider matricule
4. Fonctions auxiliaires

**Calcul Âge** :

```c
int calculer_age(Date date_naissance) {
    // Obtenir date actuelle
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    int annee_actuelle = tm_info->tm_year + 1900;
    int mois_actuel = tm_info->tm_mon + 1;
    int jour_actuel = tm_info->tm_mday;

    // Calculer âge
    int age = annee_actuelle - date_naissance.annee;

    // Ajuster si anniversaire pas encore passé
    if (mois_actuel < date_naissance.mois ||
        (mois_actuel == date_naissance.mois &&
         jour_actuel < date_naissance.jour)) {
        age--;
    }

    return age;
}
```

## 🐛 Résolution de Problèmes Courants

### Erreur de Compilation

```bash
# Nettoyer et recompiler
make clean
make

# Vérifier les includes
# Dans chaque .c, inclure les .h nécessaires
```

### Erreur de Link

```bash
# Vérifier que toutes les fonctions sont implémentées
# Vérifier le Makefile (tous les .c doivent être listés)
```

### Segmentation Fault

```bash
# Compiler avec debug
make debug

# Utiliser gdb (si disponible)
gdb ./bin/sms

# Dans gdb
run
# Quand il crash :
backtrace
```

### Conflits Git

```bash
# Voir les fichiers en conflit
git status

# Ouvrir le fichier, chercher les marqueurs :
# <<<<<<< HEAD
# =======
# >>>>>>> develop

# Résoudre manuellement, puis :
git add fichier_resolu.c
git commit -m "fix: résolution conflit"
git push
```

## 💡 Astuces

### Tester Rapidement

```bash
# Créer un script de test
echo "#!/bin/bash
make clean
make
echo '5' | ./bin/sms" > test.sh

chmod +x test.sh
./test.sh
```

### Affichage Propre

```c
// Effacer l'écran
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
```

### Debug avec Printf

```c
#ifdef DEBUG
    printf("[DEBUG] Variable x = %d\n", x);
#endif
```

## 🆘 Besoin d'Aide ?

1. Vérifier la documentation (README.md, ARCHITECTURE.md)
2. Demander dans le groupe
