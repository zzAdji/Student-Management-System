# 🎓 Système de Gestion des Étudiants

## 📋 Table des Matières

- [Description](#-description)
- [Fonctionnalités](#-fonctionnalités)
- [Architecture du Projet](#-architecture-du-projet)
- [Installation](#-installation)
- [Utilisation](#-utilisation)
- [Workflow Git](#-workflow-git)
- [Équipe](#-équipe)
- [Conventions de Code](#-conventions-de-code)
- [Contribuer](#-contribuer)

## 📖 Description

Application console en C pour la gestion complète des données étudiantes. Ce système permet d'enregistrer, modifier, rechercher, supprimer et organiser les informations des étudiants de manière efficace et professionnelle.

### Données Gérées

- **Matricule** : Identifiant unique de l'étudiant
- **Nom** : Nom de famille
- **Prénom** : Prénom de l'étudiant
- **Date de naissance** : Format JJ/MM/AAAA
- **Sexe** : M (Masculin) / F (Féminin)
- **Département** : Département d'études
- **Filière** : Option/Spécialisation
- **Région d'origine** : Région de provenance

## ✨ Fonctionnalités

### Menu Principal

1. **Enregistrer** - Ajouter un nouvel étudiant
2. **Modifier** - Mettre à jour les informations d'un étudiant existant
3. **Rechercher (Matricule)** - Recherche linéaire par matricule
4. **Supprimer** - Retirer un étudiant de la base
5. **Trier par ordre alphabétique** - Tri croissant par nom
6. **Recherche dichotomique** - Recherche binaire optimisée (liste triée requise)
7. **Calculer l'âge** - Calcul automatique de l'âge à partir de la date de naissance
8. **Trier par filière** - Organisation par filière d'études
9. **Afficher la liste** - Vue d'ensemble formatée de tous les étudiants

## 📁 Architecture du Projet

```
Student-Management-System/
│
├── src/                          # Code source
│   ├── main.c                    # Point d'entrée de l'application
│   ├── student.c                # Gestion de la structure Etudiant
│   ├── menu.c                    # Interface utilisateur (menu)
│   ├── operations.c              # CRUD (Create, Read, Update, Delete)
│   ├── search.c               # Fonctions de recherche
│   ├── sort.c                     # Algorithmes de tri
│   ├── utils.c                   # Fonctions utilitaires
│   └── validation.c              # Validation des entrées
│
├── include/                      # Fichiers d'en-tête
│   ├── student.h                # Définition structure et prototypes
│   ├── menu.h                    # Prototypes menu
│   ├── operations.h              # Prototypes CRUD
│   ├── search.h               # Prototypes recherche
│   ├── sort.h                     # Prototypes tri
│   ├── utils.h                   # Prototypes utilitaires
│   ├── validation.h              # Prototypes validation
│   └── config.h                  # Constantes et configurations
│
├── data/                         # Données persistantes
│   └── students.dat             # Fichier de sauvegarde (binaire)
│
├── docs/                         # Documentation
│   ├── ARCHITECTURE.md           # Documentation architecture
│   ├── API.md                    # Documentation des fonctions
│   └── WORKFLOW.md               # Guide du workflow Git
│
├── tests/                        # Tests (optionnel)
│   └── test_operations.c
│
├── build/                        # Fichiers compilés (gitignore)
│   └── .gitkeep
│
├── .gitignore                    # Fichiers à ignorer par Git
├── Makefile                      # Automatisation de la compilation
├── README.md                     # Ce fichier
└── LICENSE                       # Licence du projet

```

## 🚀 Installation

### Prérequis

- Compilateur GCC (MinGW pour Windows)
- Make (optionnel mais recommandé)
- Git

### Compilation

#### Méthode 1 : Avec Make (recommandé)

```bash
# Cloner le dépôt
git clone https://github.com/zzAdji/Student-Management-System.git
cd Student-Management-System

# Compiler
make

# Exécuter
./bin/sms
```

#### Méthode 2 : Compilation manuelle

```bash
# Windows
gcc src/*.c -Iinclude -o sms.exe

# Linux/Mac
gcc src/*.c -Iinclude -o sms
```

## 💻 Utilisation

### Démarrage

```bash
./sms
```

### Premier Lancement

Au premier démarrage, le programme vous demandera :
```
Combien d'étudiants souhaitez-vous enregistrer ? 
```

### Navigation dans le Menu

```
╔════════════════════════════════════════════════════╗
║     SYSTÈME DE GESTION DES ÉTUDIANTS              ║
╚════════════════════════════════════════════════════╝

1. Enregistrer un étudiant
2. Modifier les informations
3. Rechercher (par matricule)
4. Supprimer un étudiant
5. Trier par ordre alphabétique
6. Recherche dichotomique
7. Calculer l'âge d'un étudiant
8. Trier par filière
9. Afficher tous les étudiants
0. Quitter

Votre choix : 
```

## 🔄 Workflow Git

### Branches

- `main` : Branche principale stable
- `develop` : Branche de développement
- `feature/nom-fonctionnalite` : Nouvelles fonctionnalités
- `fix/nom-bug` : Corrections de bugs

### Process de Développement

1. **Récupérer les dernières modifications**
   ```bash
   git checkout develop
   git pull origin develop
   ```

2. **Créer une branche pour votre tâche**
   ```bash
   git checkout -b feature/nom-de-votre-fonctionnalite
   ```

3. **Développer et commiter régulièrement**
   ```bash
   git add .
   git commit -m "feat: description claire de la modification"
   ```

4. **Pousser votre branche**
   ```bash
   git push origin feature/nom-de-votre-fonctionnalite
   ```

5. **Créer une Pull Request** sur GitHub vers `develop`

### Convention de Commit

Format : `type(scope): description`

Types :
- `feat`: Nouvelle fonctionnalité
- `fix`: Correction de bug
- `docs`: Documentation
- `style`: Formatage
- `refactor`: Refactorisation
- `test`: Tests
- `chore`: Tâches de maintenance

Exemples :
```bash
git commit -m "feat(recherche): ajout recherche dichotomique"
git commit -m "fix(tri): correction tri alphabétique"
git commit -m "docs(readme): mise à jour installation"
```

## 👥 Équipe

| Nom | Rôle | Responsabilités |
|-----|------|----------------|
| Membre 1 | Chef de Projet | Coordination, menu.c, main.c |
| Membre 2 | Développeur | student.c, operations.c |
| Membre 3 | Développeur | search.c, sort.c |
| Membre 4 | Développeur | utils.c, validation.c |
| Membre 5 | Testeur/Doc | Tests, documentation |
| Membre 6 | Intégration | Makefile, intégration globale |

## 📝 Conventions de Code

### Style de Code

- **Indentation** : 4 espaces (pas de tabulations)
- **Accolades** : Style K&R
- **Nommage** :
  - Variables : `snake_case` (ex: `student_count`)
  - Fonctions : `snakecase` (ex: `calculateAge`)
  - Constantes : `UPPER_CASE` (ex: `MAX_STUDENTS`)
  - Structures : `Pascal_Case` (ex: `Student_Management`)

### Exemple de Code

```c
// Bon exemple
int calculateAge(Date birth_date) {
    // Code ici
    return age;
}

// Commentaires clairs et concis
typedef struct {
    char id[20];
    char name[50];
    char surname[50];
    // ... autres champs
} Student;
```

### Documentation des Fonctions

```c
/**
 * @brief Calcule l'âge d'un étudiant à partir de sa date de naissance
 * 
 * @param birth_date Structure Date contenant JJ/MM/AAAA
 * @return int Âge en années
 */
int calculateAge(Date birth_date);
```

## 🤝 Contribuer

1. Créez une branche pour votre fonctionnalité
2. Committez vos changements avec des messages clairs
3. Poussez vers votre branche
4. Ouvrez une Pull Request avec description détaillée
5. Attendez la revue de code d'au moins un membre
6. Intégrez les feedbacks
7. Merge après approbation

### Checklist avant Pull Request

- [ ] Le code compile sans erreurs ni warnings
- [ ] Les fonctions sont documentées
- [ ] Le code respecte les conventions
- [ ] Les modifications sont testées
- [ ] Le README est mis à jour si nécessaire

---

**Dernière mise à jour** : 20 Décembre 2025  