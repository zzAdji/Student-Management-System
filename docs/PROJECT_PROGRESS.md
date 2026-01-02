# 📊 Suivi de Progression du Projet

**Projet** : Student Management System  
**Date de début** : 22/12/2025
**Date limite** : 12/01/2026

---

## 📈 Vue d'Ensemble Globale

```
┌───────────────────────────────────────────────────────────────────────────────┐
│                           PROGRESSION GLOBALE                                 │
├───────────────────────────────────────────────────────────────────────────────┤
│  Phase 1  : Setup & Configuration      [██████████] 10/10   (100%)  ✅        │
│  Phase 2  : Structure & Base           [████████░░] 21/27   (78%)   🔄        │
│  Phase 3  : CRUD Operations            [███████░░░] 22/32   (69%)   🔄        │
│  Phase 4  : Search & Sort              [░░░░░░░░░░]  0/25   (0%)    ☐         │
│  Phase 5  : Validation & Utils         [████░░░░░░] 14/35   (40%)   🔄        │
│  Phase 6  : Interface Menu             [██████████] 49/49   (100%)  ✅        │
│  Phase 7  : Main & Persistance         [██░░░░░░░░]  5/19   (26%)   🔄        │
│  Phase 8  : Build System (Makefile)    [░░░░░░░░░░]  0/14   (0%)    ☐         │
│  Phase 9  : Tests & Débogage           [░░░░░░░░░░]  0/41   (0%)    ☐         │
│  Phase 10 : Documentation              [░░░░░░░░░░]  0/22   (0%)    ☐         │
│  Phase 11 : Intégration Finale         [░░░░░░░░░░]  0/23   (0%)    ☐         │
├───────────────────────────────────────────────────────────────────────────────┤
│  CHECKLIST FINALE                      [░░░░░░░░░░]  0/35   (0%)    ☐         │
├───────────────────────────────────────────────────────────────────────────────┤
│  TOTAL GÉNÉRAL                         [████░░░░░░] 121/332 (36%)             │
└───────────────────────────────────────────────────────────────────────────────┘
```

### 📋 Détail des Tâches par Phase

| Phase     | Description                           | Terminé | Total | Progression               |
| --------- | ------------------------------------- | ------- | ----- | ------------------------- |
| **1**     | Setup & Configuration                 | 10      | 10    | ████████████████████ 100% |
| **2**     | Structure & Base (student.h/c)        | 21      | 27    | ████████████████░░░░ 78%  |
| **3**     | CRUD Operations (operations.h/c)      | 22      | 32    | ██████████████░░░░░░ 69%  |
| **4**     | Search & Sort (search.h/c, sort.h/c)  | 0       | 25    | ░░░░░░░░░░░░░░░░░░░░ 0%   |
| **5**     | Validation & Utils (utils.h/c)        | 14      | 35    | ████████░░░░░░░░░░░░ 40%  |
| **6**     | Interface Menu (menu.h/c)             | 49      | 49    | ████████████████████ 100% |
| **7**     | Main & Persistance (main.c, data.h/c) | 5       | 19    | █████░░░░░░░░░░░░░░░ 26%  |
| **8**     | Build System (Makefile)               | 0       | 14    | ░░░░░░░░░░░░░░░░░░░░ 0%   |
| **9**     | Tests & Débogage                      | 0       | 41    | ░░░░░░░░░░░░░░░░░░░░ 0%   |
| **10**    | Documentation                         | 0       | 22    | ░░░░░░░░░░░░░░░░░░░░ 0%   |
| **11**    | Intégration Finale                    | 0       | 23    | ░░░░░░░░░░░░░░░░░░░░ 0%   |
| **Final** | Checklist de Présentation             | 0       | 35    | ░░░░░░░░░░░░░░░░░░░░ 0%   |

### 🎯 Résumé Exécutif

| Catégorie                     | Tâches Terminées | Tâches Totales | % Complété |
| ----------------------------- | ---------------- | -------------- | ---------- |
| **Configuration & Setup**     | 10               | 10             | 100%       |
| **Développement Core**        | 57               | 119            | 48%        |
| **Interface Utilisateur**     | 54               | 68             | 79%        |
| **Qualité & Tests**           | 0                | 41             | 0%         |
| **Documentation & Livraison** | 0                | 94             | 0%         |
| **TOTAL**                     | **121**          | **332**        | **36%**    |

**Légende** : ☐ À faire | 🔄 En cours | ✅ Terminé | ⏸️ En pause | ❌ Bloqué

---

## 🎯 Phase 1 : Setup & Configuration (Jours 1-2)

**Responsable** : Membre 1 (Chef de Projet)  
**Progression** : 10/10 (100%)

### 1.1 Configuration Git & GitHub

- [x] ✅ Créer compte GitHub (tous les membres)
- [x] ✅ Créer repository "gestion-etudiants"
- [x] ✅ Configurer Git localement (tous)
- [x] ✅ Cloner le repository (tous)
- [x] ✅ Créer branche `develop`
- [x] ✅ Configurer protection branches (main, develop)
- [x] ✅ Inviter tous les collaborateurs
- [x] ✅ Tous acceptent invitation

**Notes** :

```
Date début : 20/12/2025
Date fin   : 31/12/2025
```

### 1.2 Structure du Projet

- [x] ✅ Créer dossiers (src, include, build, bin, data, docs, tests)
- [x] ✅ Créer fichiers .gitkeep

**Notes** :

```
Date création : 20/12/2025
```

---

## 🏗️ Phase 2 : Structure & Base (Jours 2-4)

### 2.1 Configuration (Membre 6)

**Progression** : 0/3 (0%)

- [ ] ☐ Créer `include/config.h` avec toutes les constantes
  - [ ] ☐ Définir MAX_ID, MAX_NAME, etc.
  - [ ] ☐ Définir INITIAL_CAPACITY, RESIZE_FACTOR
  - [ ] ☐ Définir chemins fichiers
- [ ] ☐ Tester compilation config.h
- [ ] ☐ Push vers GitHub

**Notes** :

```
Date début : ___/___
Date fin   : ___/___
Commit ID  :
```

### 2.2 Structure Student (Membre 2)

**Progression** : 21/24 (88%)

#### 2.2.1 Header student.h

- [x] ✅ Créer `include/student.h`
- [x] ✅ Définir structure `Date`
- [x] ✅ Définir structure `Student`
  - [x] ✅ Tous les champs avec bons types
  - [x] ✅ Commentaires documentation
- [x] ✅ Définir structure `Student_Management`
  - [x] ✅ Pointeur list
  - [x] ✅ Champs number et capacity
- [x] ✅ Prototypes gestion mémoire
  - [x] ✅ `initManagement()`
  - [x] ✅ `freeManagement()`
  - [x] ✅ `resizeManagement()`
- [x] ✅ Prototypes affichage
  - [x] ✅ `viewStudent()`
  - [x] ✅ `viewAllStudents()`
  - [ ] ☐ `displayTableHeader()`
- [x] ✅ Prototypes comparaison
  - [x] ✅ `compareStudentsByName()`
  - [x] ✅ `compareStudentsById()`
  - [x] ✅ `compareStudentsByOption()`
- [ ] ☐ Prototypes utilitaires
  - [ ] ☐ `copyStudent()`
  - [ ] ☐ `initStudent()`

#### 2.2.2 Implémentation student.c

- [x] ✅ Créer `src/student.c`
- [x] ✅ Implémenter `initManagement()`
  - [x] ✅ Allocation mémoire initiale
  - [x] ✅ Initialisation champs
  - [x] ✅ Gestion erreurs
- [x] ✅ Implémenter `freeManagement()`
  - [x] ✅ Libération mémoire
  - [x] ✅ Réinitialisation pointeurs
- [x] ✅ Implémenter `resizeManagement()`
  - [x] ✅ Calcul nouvelle capacité
  - [x] ✅ Realloc
  - [x] ✅ Gestion erreurs
- [x] ✅ Implémenter `viewStudent()`
  - [x] ✅ Affichage formaté avec bordures
- [x] ✅ Implémenter `viewAllStudents()`
  - [x] ✅ Gestion liste vide
  - [x] ✅ Affichage tableau
- [ ] ☐ Implémenter `displayTableHeader()`
- [x] ✅ Implémenter fonctions comparaison (3)
- [ ] ☐ Implémenter `copyStudent()`
- [ ] ☐ Implémenter `initStudent()`
- [x] ✅ Tester compilation
- [ ] ☐ Tester chaque fonction
- [x] ✅ Commit et push

**Notes** :

```
Date début : 01/01/2026
Date fin   : 01/01/2026
Tests      : ✅ initManagement ✅ resizeManagement ✅ viewStudent
Bugs       : Aucun
```

---

## 💾 Phase 3 : CRUD Operations (Jours 3-6)

**Responsable** : Membre 2  
**Progression** : 22/32 (69%)

### 3.1 Header operations.h

- [x] ✅ Créer `include/operations.h`
- [x] ✅ Prototypes CREATE
  - [x] ✅ `addStudent()`
  - [ ] ☐ `registerStudent()` (géré dans menu.c)
- [x] ✅ Prototypes READ
  - [x] ✅ `getStudentByIndex()` (remplacé getStudentById)
  - [x] ✅ `findStudentById()` (recherche par matricule)
  - [ ] ☐ `selectStudent()` (supprimé, géré dans menu.c)
- [x] ✅ Prototypes UPDATE
  - [x] ✅ `modifyStudent(field, value)` (nouvelle signature)
  - [ ] ☐ `modifyStudentField()` (intégré dans modifyStudent)
- [x] ✅ Prototypes DELETE
  - [x] ✅ `deleteStudent()`
  - [x] ✅ `deleteAllStudents()`
  - [ ] ☐ `deleteStudentById()` (utiliser findStudentById + deleteStudent)

### 3.2 Implémentation operations.c

- [x] ✅ Créer `src/operations.c`

#### CREATE

- [x] ✅ Implémenter `addStudent()`
  - [x] ✅ Vérifier capacité
  - [x] ✅ Redimensionner si nécessaire
  - [x] ✅ Ajouter étudiant
  - [x] ✅ Incrémenter number
- [ ] ☐ Implémenter `registerStudent()` (géré dans menu.c)
  - [ ] ☐ Saisie interactive toutes infos
  - [ ] ☐ Validation données
  - [x] ✅ Appel addStudent()
  - [x] ✅ Messages succès/erreur (dans menu.c)

#### READ

- [x] ✅ Implémenter `getStudentByIndex()`
  - [x] ✅ Vérification index
  - [x] ✅ Retour pointeur ou NULL
- [x] ✅ Implémenter `findStudentById()`
  - [x] ✅ Recherche linéaire
  - [x] ✅ Retour index ou -1
- [ ] ☐ Implémenter `selectStudent()` (supprimé, affichage dans menu.c)
  - [ ] ☐ Demander ID utilisateur (dans menu.c)
  - [x] ✅ Appel findStudentById()
  - [x] ✅ Affichage résultat (dans menu.c)

#### UPDATE

- [x] ✅ Implémenter `modifyStudent(management, index, field, value)`
  - [x] ✅ Switch selon champ (1-8)
  - [x] ✅ Modification directe du champ
  - [x] ✅ Validation genre (M/F)
  - [x] ✅ Parsing date (format "JJ MM AAAA")
- [ ] ☐ Implémenter `modifyStudentField()` (intégré dans modifyStudent)

#### DELETE

- [x] ✅ Implémenter `deleteStudent()`
  - [x] ✅ Vérification index
  - [x] ✅ Décalage éléments
  - [x] ✅ Décrément number
  - [x] ✅ Optimisation mémoire (realloc si <50%)
- [x] ✅ Implémenter `deleteAllStudents()`
  - [x] ✅ Libération mémoire
  - [x] ✅ Réinitialisation liste
- [ ] ☐ Implémenter `deleteStudentById()`
  - [ ] ☐ Recherche ID
  - [ ] ☐ Appel deleteStudent()

### 3.3 Tests

- [x] ✅ Test addStudent() - capacité normale
- [ ] ☐ Test addStudent() - redimensionnement
- [x] ✅ Test registerStudent() - saisie complète (via menu)
- [x] ✅ Test modifyStudent() - tous champs
- [ ] ☐ Test deleteStudent() - début, milieu, fin
- [ ] ☐ Test deleteAllStudents()
- [x] ✅ Commit et push

**Notes** :

```
Date début : 01/01/2026
Date fin   : 01/01/2026
Refactoring: Séparation logique (operations.c) / affichage (menu.c)
Bugs       : Aucun - compilation OK
```

---

## 🔍 Phase 4 : Search & Sort (Jours 4-7)

**Responsable** : Membre 3  
**Progression** : 0/25 (0%)

### 4.1 Recherche (search.c/h)

#### Header

- [ ] ☐ Créer `include/search.h`
- [ ] ☐ Prototype `linearSearch()`
- [ ] ☐ Prototype `binarySearch()`
- [ ] ☐ Prototype `isSorted()`
- [ ] ☐ Prototype `smartSearch()`

#### Implémentation

- [ ] ☐ Créer `src/search.c`
- [ ] ☐ Implémenter `linearSearch()`
  - [ ] ☐ Parcours tableau
  - [ ] ☐ Comparaison ID
  - [ ] ☐ Retour index ou -1
- [ ] ☐ Implémenter `binarySearch()`
  - [ ] ☐ Algorithme dichotomique
  - [ ] ☐ Calcul milieu
  - [ ] ☐ Comparaisons
- [ ] ☐ Implémenter `isSorted()`
  - [ ] ☐ Vérification ordre
- [ ] ☐ Implémenter `smartSearch()`
  - [ ] ☐ Test si trié
  - [ ] ☐ Choix algo approprié
- [ ] ☐ Tests recherches
  - [ ] ☐ Test linéaire - trouvé
  - [ ] ☐ Test linéaire - non trouvé
  - [ ] ☐ Test binaire - liste triée
  - [ ] ☐ Test binaire - non trouvé
- [ ] ☐ Commit et push

### 4.2 Tri (sort.c/h)

#### Header

- [ ] ☐ Créer `include/sort.h`
- [ ] ☐ Prototype `sortAlphabetically()`
- [ ] ☐ Prototype `sortByOption()`
- [ ] ☐ Prototype `sortById()`

#### Implémentation

- [ ] ☐ Créer `src/sort.c`
- [ ] ☐ Implémenter `sortAlphabetically()`
  - [ ] ☐ Appel qsort avec compareStudentsByName
  - [ ] ☐ Message confirmation
- [ ] ☐ Implémenter `sortByOption()`
  - [ ] ☐ Appel qsort avec compareStudentsByOption
  - [ ] ☐ Message confirmation
- [ ] ☐ Implémenter `sortById()`
  - [ ] ☐ Appel qsort avec compareStudentsById
  - [ ] ☐ Message confirmation
- [ ] ☐ Tests tri
  - [ ] ☐ Test tri alphabétique
  - [ ] ☐ Test tri par option
  - [ ] ☐ Test tri par ID
  - [ ] ☐ Vérifier ordre après tri
- [ ] ☐ Commit et push

**Notes** :

```
Date début : ___/___
Date fin   : ___/___
Performance : Linéaire ___ms | Binaire ___ms (pour 1000 étudiants)
```

---

## ✅ Phase 5 : Validation & Utils (Jours 4-7)

**Responsable** : Membre 4  
**Progression** : 14/35 (40%)

### 5.1 Utilitaires (utils.c/h)

#### Header

- [x] ✅ Créer `include/utils.h`
- [ ] ☐ Prototypes manipulation date
  - [ ] ☐ `calculateAge()` (TODO dans menu.c)
  - [ ] ☐ `getCurrentDate()`
- [x] ✅ Prototypes système
  - [ ] ☐ `clearBuffer()`
  - [x] ✅ `displaySimpleFooter()` (pause avec Enter)
  - [x] ✅ `clearScreen()`
- [ ] ☐ Prototypes string
  - [ ] ☐ `stringToUpper()`
  - [ ] ☐ `stringToLower()`
  - [ ] ☐ `safeCopy()`
- [ ] ☐ Prototype `generateId()`
- [x] ✅ Prototypes affichage stylisé
  - [x] ✅ `displayHeader()`
  - [x] ✅ `displayHeaderStyled()`
  - [x] ✅ `displaySuccess()`
  - [x] ✅ `displayError()`
  - [x] ✅ `displayWarning()`
  - [x] ✅ `displayInfo()`
  - [x] ✅ `displayPath()`
  - [x] ✅ `displayChoiceFooter()`
- [x] ✅ Prototypes terminal
  - [x] ✅ `getTerminalWidth()`
  - [x] ✅ `getVisibleLength()`
  - [x] ✅ `printSpaces()`

#### Implémentation

- [x] ✅ Créer `src/utils.c`
- [ ] ☐ Implémenter `calculateAge()` (TODO)
  - [ ] ☐ Parser date DD/MM/YYYY
  - [ ] ☐ Obtenir date actuelle
  - [ ] ☐ Calcul âge
  - [ ] ☐ Ajustement anniversaire
- [ ] ☐ Implémenter `getCurrentDate()`
  - [ ] ☐ time() et localtime()
  - [ ] ☐ Format DD/MM/YYYY
- [ ] ☐ Implémenter `clearBuffer()`
- [x] ✅ Implémenter `displaySimpleFooter()`
  - [x] ✅ Version Windows
  - [ ] ☐ Version Linux/Mac
- [x] ✅ Implémenter `clearScreen()`
  - [x] ✅ Version Windows (cls)
  - [ ] ☐ Version Linux/Mac (clear)
- [ ] ☐ Implémenter `stringToUpper()`
- [ ] ☐ Implémenter `stringToLower()`
- [ ] ☐ Implémenter `safeCopy()`
  - [ ] ☐ strncpy sécurisé
  - [ ] ☐ Terminaison '\0'
- [ ] ☐ Implémenter `generateId()`
  - [ ] ☐ Format STU + année + numéro
- [x] ✅ Implémenter fonctions d'affichage stylisé (8 fonctions)
- [x] ✅ Tests utils
- [x] ✅ Commit et push

### 5.2 Validation (validation.c/h)

#### Header

- [ ] ☐ Créer `include/validation.h`
- [ ] ☐ Prototypes validation
  - [ ] ☐ `validateId()`
  - [ ] ☐ `validateDate()`
  - [ ] ☐ `validateGender()`
  - [ ] ☐ `validateString()`
- [ ] ☐ Prototypes saisie
  - [ ] ☐ `inputValidString()`
  - [ ] ☐ `inputValidDate()`
- [ ] ☐ Prototypes vérification
  - [ ] ☐ `idExists()`
  - [ ] ☐ `isLeapYear()`

#### Implémentation

- [ ] ☐ Créer `src/validation.c`
- [ ] ☐ Implémenter `validateId()`
  - [ ] ☐ Vérifier format
  - [ ] ☐ Vérifier longueur
- [ ] ☐ Implémenter `validateDate()`
  - [ ] ☐ Parser DD/MM/YYYY
  - [ ] ☐ Vérifier jours selon mois
  - [ ] ☐ Vérifier années bissextiles
  - [ ] ☐ Vérifier cohérence (pas futur)
- [ ] ☐ Implémenter `validateGender()`
  - [ ] ☐ Accepter M/F case-insensitive
  - [ ] ☐ Conversion majuscule
- [ ] ☐ Implémenter `validateString()`
  - [ ] ☐ Vérifier non vide
  - [ ] ☐ Trim espaces
- [ ] ☐ Implémenter `inputValidString()`
  - [ ] ☐ Boucle validation
  - [ ] ☐ Messages erreur
- [ ] ☐ Implémenter `inputValidDate()`
  - [ ] ☐ Boucle validation
  - [ ] ☐ Messages erreur
- [ ] ☐ Implémenter `idExists()`
- [ ] ☐ Implémenter `isLeapYear()`
- [ ] ☐ Tests validation
  - [ ] ☐ Dates valides/invalides
  - [ ] ☐ IDs valides/invalides
  - [ ] ☐ Années bissextiles
- [ ] ☐ Commit et push

**Notes** :

```
Date début : 21/12/2025
Date fin   : 01/01/2026
Tests validation : ☐ Date ☐ ID ☐ Genre
Fonctions affichage : ✅ Toutes implémentées
```

---

## 🎨 Phase 6 : Interface Menu (Jours 3-6)

**Responsable** : Membre 1  
**Progression** : 49/49 (100%)

### 6.1 Header menu.h

- [x] ✅ Créer `include/menu.h`
- [x] ✅ Prototype `displayMenu()`
- [x] ✅ Prototype `getUserChoice()`
- [x] ✅ Prototype `processChoice()`
- [x] ✅ Prototypes affichage messages
  - [x] ✅ `displayHeader()`
  - [x] ✅ `displaySuccess()`
  - [x] ✅ `displayError()`
  - [x] ✅ `displayInfo()`

### 6.2 Implémentation menu.c

- [x] ✅ Créer `src/menu.c`
- [x] ✅ Implémenter `displayMenu()`
  - [x] ✅ Design avec bordures ASCII
  - [x] ✅ 9 options + Quitter
  - [x] ✅ Emojis/icônes
- [x] ✅ Implémenter `getUserChoice()`
  - [x] ✅ Saisie choix
  - [x] ✅ Validation (0-9)
  - [x] ✅ Boucle jusqu'à valide
- [x] ✅ Implémenter `processChoice()`
  - [x] ✅ Switch case 0-9
  - [x] ✅ Case 1: registerStudent()
  - [x] ✅ Case 2: modifyStudent() avec sous-menu
  - [x] ✅ Case 3: linearSearch()
  - [x] ✅ Case 4: deleteStudent() avec confirmation
  - [x] ✅ Case 5: sortAlphabetically()
  - [x] ✅ Case 6: binarySearch()
  - [x] ✅ Case 7: calculateAge()
  - [x] ✅ Case 8: sortByOption()
  - [x] ✅ Case 9: viewAllStudents()
  - [x] ✅ Case 0: Exit avec confirmation
  - [x] ✅ Default: message erreur
- [x] ✅ Implémenter fonctions affichage
  - [x] ✅ `displayHeader()`
  - [x] ✅ `displaySuccess()`
  - [x] ✅ `displayError()`
  - [x] ✅ `displayInfo()`
- [x] ✅ Implémenter sous-menus
  - [x] ✅ Menu modification (8 champs)
  - [x] ✅ Menu confirmation suppression
  - [x] ✅ Menu confirmation quitter
  - [x] ✅ Menu sélection étudiant
- [x] ✅ Tests menu
  - [x] ✅ Test chaque option
  - [x] ✅ Test choix invalides
  - [x] ✅ Test navigation sous-menus
- [x] ✅ Commit et push

### 6.3 Design des Menus

#### Menu Principal

```
╔════════════════════════════════════════════════════╗
║        STUDENT MANAGEMENT SYSTEM                  ║
╚════════════════════════════════════════════════════╝

  1. Register a student
  2. Modify information
  3. Search (by ID)
  4. Delete a student
  5. Sort alphabetically
  6. Binary search
  7. Calculate student age
  8. Sort by option
  9. Display all students
  0. 🚪 Exit

────────────────────────────────────────────────────
Your choice: _
```

- [x] ✅ Implémenter ce design

#### Menu Modification

```
╔════════════════════════════════════════════════════╗
║           MODIFY STUDENT INFORMATION              ║
╚════════════════════════════════════════════════════╝

Current student: [ID] - [Name] [Surname]

Which field do you want to modify?

  1. ID
  2. Name
  3. Surname
  4. Birth Date
  5. Gender
  6. Department
  7. Option
  8. Native Region
  9. ✅ Save and return
  0. ❌ Cancel

────────────────────────────────────────────────────
Your choice: _
```

- [x] ✅ Implémenter ce sous-menu

#### Menu Confirmation Suppression

```
╔════════════════════════════════════════════════════╗
║              ⚠️  CONFIRMATION                      ║
╚════════════════════════════════════════════════════╝

Are you sure you want to delete this student?

  ID      : [STU2024001]
  Name    : [Dupont]
  Surname : [Jean]

  1. ✅ Yes, delete
  0. ❌ No, cancel

────────────────────────────────────────────────────
Your choice: _
```

- [x] ✅ Implémenter ce sous-menu

#### Menu Saisie Étudiant

```
╔════════════════════════════════════════════════════╗
║            REGISTER NEW STUDENT                    ║
╚════════════════════════════════════════════════════╝

Enter student information:

ID (e.g., STU2024001)      : _______________________
Name                        : _______________________
Surname                     : _______________________
Birth Date (DD/MM/YYYY)     : __/__/____
Gender (M/F)                : _
Department                  : _______________________
Option                      : _______________________
Native Region               : _______________________

Press Enter to continue...
```

- [x] ✅ Implémenter ce formulaire

#### Menu Recherche

```
╔════════════════════════════════════════════════════╗
║              SEARCH STUDENT                        ║
╚════════════════════════════════════════════════════╝

Enter student ID to search: _______________________

Searching...
```

- [x] ✅ Implémenter ce menu

#### Affichage Résultat Recherche - Trouvé

```
╔════════════════════════════════════════════════════╗
║              ✅ STUDENT FOUND                      ║
╚════════════════════════════════════════════════════╝

ID              : STU2024001
Name            : Dupont
Surname         : Jean
Birth Date      : 15/06/2000
Age             : 24 years
Gender          : M
Department      : Computer Science
Option          : Software Engineering
Native Region   : Île-de-France

────────────────────────────────────────────────────
Press Enter to continue...
```

- [x] ✅ Implémenter cet affichage

#### Affichage Résultat Recherche - Non Trouvé

```
╔════════════════════════════════════════════════════╗
║              ❌ STUDENT NOT FOUND                  ║
╚════════════════════════════════════════════════════╝

No student with ID: STU2024999

────────────────────────────────────────────────────
Press Enter to continue...
```

- [x] ✅ Implémenter cet affichage

#### Tableau Liste Étudiants

```
╔════════════════════════════════════════════════════╗
║        STUDENT LIST (15 students)                  ║
╚════════════════════════════════════════════════════╝

┌─────┬─────────────────┬──────────────┬──────────────┬────────────┬─────────────────┐
│ No  │       ID        │     Name     │    Surname   │ Birth Date │     Option      │
├─────┼─────────────────┼──────────────┼──────────────┼────────────┼─────────────────┤
│ 1   │ STU2024001      │ Dupont       │ Jean         │ 15/06/2000 │ Software Eng.   │
│ 2   │ STU2024002      │ Martin       │ Marie        │ 23/09/1999 │ Data Science    │
│ 3   │ STU2024003      │ Bernard      │ Paul         │ 10/03/2001 │ Networks        │
│ ... │ ...             │ ...          │ ...          │ ...        │ ...             │
└─────┴─────────────────┴──────────────┴──────────────┴────────────┴─────────────────┘

Total: 15 student(s)

────────────────────────────────────────────────────
Press Enter to continue...
```

- [x] ✅ Implémenter cet affichage

#### Menu Calcul Âge

```
╔════════════════════════════════════════════════════╗
║           CALCULATE STUDENT AGE                    ║
╚════════════════════════════════════════════════════╝

Enter student ID: _______________________

────────────────────────────────────────────────────

Student: Jean Dupont
Birth Date: 15/06/2000
Current Date: 22/12/2024

Age: 24 years, 6 months, 7 days

────────────────────────────────────────────────────
Press Enter to continue...
```

- [x] ✅ Implémenter ce menu

#### Messages de Succès/Erreur

```
╔════════════════════════════════════════════════════╗
║              ✅ SUCCESS                            ║
╚════════════════════════════════════════════════════╝
Student successfully registered!
```

```
╔════════════════════════════════════════════════════╗
║              ❌ ERROR                              ║
╚════════════════════════════════════════════════════╝
Invalid input. Please try again.
```

```
╔════════════════════════════════════════════════════╗
║              ℹ️  INFORMATION                       ║
╚════════════════════════════════════════════════════╝
List sorted alphabetically.
```

- [x] ✅ Implémenter ces messages

**Notes** :

```
Date début : 21/12/2025
Date fin   : 22/12/2025
```

---

## 🚀 Phase 7 : Main & Persistance (Jours 6-8)

**Responsable** : Membre 1  
**Progression** : 4/19 (14%)

### 7.1 Fichier main.c

- [x] ✅ Créer `src/main.c`
- [x] ✅ Includes nécessaires
- [x] ✅ Message bienvenue
- [x] ✅ Initialisation
  - [x] ✅ Déclarer Student_Management
  - [x] ✅ Appel initManagement()
- [ ] ☐ Chargement données
  - [ ] ☐ Appel loadData()
  - [ ] ☐ Message si succès/échec
- [x] ✅ Boucle principale
  - [x] ✅ While choice != 0
  - [x] ✅ displayMenu()
  - [x] ✅ getUserChoice()
  - [x] ✅ processChoice()
- [ ] ☐ Sortie propre
  - [ ] ☐ Sauvegarde saveData()
  - [x] ✅ Libération freeManagement()
  - [x] ✅ Message au revoir
- [ ] ☐ Compilation test
- [ ] ☐ Exécution test
- [ ] ☐ Commit et push

### 7.2 Persistance (data.c/h - optionnel)

- [x] ✅ Créer `include/data.h`
- [ ] ☐ Prototype `saveData()`
- [ ] ☐ Prototype `loadData()`
- [x] ✅ Créer `src/data.c`
- [ ] ☐ Implémenter `saveData()`
  - [ ] ☐ Ouvrir fichier binaire
  - [ ] ☐ Écrire capacity et number
  - [ ] ☐ Écrire tableau étudiants
  - [ ] ☐ Fermer fichier
  - [ ] ☐ Gestion erreurs
- [ ] ☐ Implémenter `loadData()`
  - [ ] ☐ Ouvrir fichier
  - [ ] ☐ Lire capacity et number
  - [ ] ☐ Allocation mémoire
  - [ ] ☐ Lire données
  - [ ] ☐ Fermer fichier
  - [ ] ☐ Gestion erreurs
- [ ] ☐ Tests persistance
  - [ ] ☐ Sauvegarder 5 étudiants
  - [ ] ☐ Fermer programme
  - [ ] ☐ Rouvrir, vérifier chargement
- [ ] ☐ Commit et push

**Notes** :

```
Date début : 31/12/2025
Date fin   : __/01/2026
Fichier data : data/students.dat (___Ko)
```

---

## 🔧 Phase 8 : Build System (Jours 2-8)

**Responsable** : Membre 6  
**Progression** : 0/14 (0%)

### 8.1 Makefile

- [ ] ☐ Créer Makefile
- [ ] ☐ Variables (CC, CFLAGS, LDFLAGS)
- [ ] ☐ Répertoires (SRC_DIR, INC_DIR, etc.)
- [ ] ☐ Règle `all`
- [ ] ☐ Règle création exécutable
- [ ] ☐ Règle compilation objets
- [ ] ☐ Règle `clean`
- [ ] ☐ Règle `fclean`
- [ ] ☐ Règle `re`
- [ ] ☐ Règle `run`
- [ ] ☐ Règle `debug`
- [ ] ☐ Règle `help`
- [ ] ☐ Tests Makefile
  - [ ] ☐ `make` compile sans erreur
  - [ ] ☐ `make clean` fonctionne
  - [ ] ☐ `make re` recompile
  - [ ] ☐ `make run` exécute
- [ ] ☐ Commit et push

**Notes** :

```
Date création : ___/___
Compilateur   : gcc version _____
Flags         : -Wall -Wextra -Werror
```

---

## 🧪 Phase 9 : Tests & Débogage (Jours 8-10)

**Responsable** : Membre 5  
**Progression** : 0/41 (0%)

### 9.1 Plan de Tests

- [ ] ☐ Créer `docs/TEST_PLAN.md`
- [ ] ☐ Lister tous les scénarios
  - [ ] ☐ Cas normaux
  - [ ] ☐ Cas limites
  - [ ] ☐ Cas d'erreur

### 9.2 Tests Fonctionnels

#### Option 1 : Enregistrer

- [ ] ☐ Ajouter 1 étudiant - valide
- [ ] ☐ Ajouter avec données invalides
- [ ] ☐ Ajouter plus que capacité initiale
- [ ] ☐ Vérifier redimensionnement

#### Option 2 : Modifier

- [ ] ☐ Modifier étudiant existant
- [ ] ☐ Modifier ID inexistant
- [ ] ☐ Modifier chaque champ
- [ ] ☐ Valider nouvelles données

#### Option 3 : Recherche (linéaire)

- [ ] ☐ Rechercher ID existant
- [ ] ☐ Rechercher ID inexistant
- [ ] ☐ Recherche liste vide

#### Option 4 : Supprimer

- [ ] ☐ Supprimer premier étudiant
- [ ] ☐ Supprimer dernier étudiant
- [ ] ☐ Supprimer du milieu
- [ ] ☐ Supprimer inexistant
- [ ] ☐ Supprimer jusqu'à vide

#### Option 5 : Tri alphabétique

- [ ] ☐ Trier 10 étudiants
- [ ] ☐ Vérifier ordre
- [ ] ☐ Trier liste déjà triée
- [ ] ☐ Trier liste vide

#### Option 6 : Recherche dichotomique

- [ ] ☐ Recherche sur liste triée
- [ ] ☐ Recherche sur liste non triée
- [ ] ☐ Trouver élément existant
- [ ] ☐ Élément inexistant

#### Option 7 : Calculer âge

- [ ] ☐ Date naissance valide
- [ ] ☐ Anniversaire déjà passé
- [ ] ☐ Anniversaire pas encore passé
- [ ] ☐ Année bissextile

#### Option 8 : Tri par option

- [ ] ☐ Plusieurs options différentes
- [ ] ☐ Vérifier ordre
- [ ] ☐ Ordre secondaire par nom

#### Option 9 : Afficher liste

- [ ] ☐ Afficher liste vide
- [ ] ☐ Afficher 1 étudiant
- [ ] ☐ Afficher 100 étudiants
- [ ] ☐ Vérifier formatage

### 9.3 Tests Mémoire

- [ ] ☐ Valgrind - pas de fuites
- [ ] ☐ Tester allocation/libération
- [ ] ☐ Tester redimensionnements multiples

### 9.4 Rapport de Tests

- [ ] ☐ Créer `docs/TEST_REPORT.md`
- [ ] ☐ Documenter résultats
- [ ] ☐ Lister bugs trouvés
- [ ] ☐ Créer issues GitHub pour bugs

**Notes** :

```
Date début tests : ___/___
Date fin tests   : ___/___
Bugs trouvés     : ___
Bugs résolus     : ___
```

---

## 📚 Phase 10 : Documentation (Jours 8-10)

**Responsable** : Membre 5  
**Progression** : 0/22 (0%)

### 10.1 Documentation Utilisateur

- [ ] ☐ Créer `docs/USER_GUIDE.md`
- [ ] ☐ Introduction
- [ ] ☐ Installation
- [ ] ☐ Premier lancement
- [ ] ☐ Guide de chaque fonctionnalité
  - [ ] ☐ Avec captures d'écran/exemples
- [ ] ☐ FAQ
- [ ] ☐ Dépannage

### 10.2 Documentation Technique

- [ ] ☐ Vérifier `ARCHITECTURE.md` à jour
- [ ] ☐ Créer `docs/API.md`
  - [ ] ☐ Documentation chaque fonction
  - [ ] ☐ Exemples d'utilisation
- [ ] ☐ Diagrammes (optionnel)
  - [ ] ☐ Diagramme de flux
  - [ ] ☐ Diagramme de structure

### 10.3 Commentaires Code

- [ ] ☐ Vérifier commentaires student.c/h
- [ ] ☐ Vérifier commentaires operations.c/h
- [ ] ☐ Vérifier commentaires search.c/h
- [ ] ☐ Vérifier commentaires sort.c/h
- [ ] ☐ Vérifier commentaires utils.c/h
- [ ] ☐ Vérifier commentaires validation.c/h
- [ ] ☐ Vérifier commentaires menu.c/h
- [ ] ☐ Vérifier commentaires main.c

### 10.4 README Final

- [ ] ☐ Mettre à jour README.md
- [ ] ☐ Ajouter screenshots
- [ ] ☐ Ajouter exemples utilisation
- [ ] ☐ Badges (si applicable)

**Notes** :

```
Date début : ___/___
Date fin   : ___/___
Pages doc  : ___
```

---

## 🔗 Phase 11 : Intégration Finale (Jours 9-10)

**Responsable** : Membre 6  
**Progression** : 0/23 (0%)

### 11.1 Merge vers develop

- [ ] ☐ Toutes les features mergées vers develop
- [ ] ☐ Résolution conflits
- [ ] ☐ Tests intégration complète
- [ ] ☐ Compilation sans warnings
- [ ] ☐ Exécution sans bugs

### 11.2 Tests Globaux

- [ ] ☐ Scénario utilisateur complet
  - [ ] ☐ Ajouter 10 étudiants
  - [ ] ☐ Modifier 2
  - [ ] ☐ Supprimer 1
  - [ ] ☐ Trier
  - [ ] ☐ Rechercher
  - [ ] ☐ Afficher
  - [ ] ☐ Quitter
  - [ ] ☐ Relancer, vérifier persistance
- [ ] ☐ Test performance
  - [ ] ☐ 100 étudiants
  - [ ] ☐ 1000 étudiants
- [ ] ☐ Test plateformes
  - [ ] ☐ Windows
  - [ ] ☐ Linux
  - [ ] ☐ macOS (si disponible)

### 11.3 Merge vers main

- [ ] ☐ Vérifier develop stable
- [ ] ☐ Créer PR develop → main
- [ ] ☐ Review par équipe
- [ ] ☐ Approbation
- [ ] ☐ Merge vers main
- [ ] ☐ Tag version v1.0.0

### 11.4 Présentation

- [ ] ☐ Créer archive finale
- [ ] ☐ README complet
- [ ] ☐ Tous fichiers présents
- [ ] ☐ Compilation testée
- [ ] ☐ Documentation incluse

**Notes** :

```
Date merge main : ___/___
Version finale  : v1.0.0
Archive         : sms-v1.0.0.tar.gz
```

---

## 📊 Statistiques Finales

### Code

```
Total lignes de code    : _____ lignes
Fichiers source (.c)    : _____ fichiers
Fichiers header (.h)    : _____ fichiers
Taille exécutable       : _____ Ko
```

### Tests

```
Tests effectués         : _____
Tests réussis           : _____
Bugs trouvés            : _____
Bugs résolus            : _____
Code coverage           : _____%
```

### Équipe

```
Total commits           : _____
Pull requests           : _____
Code reviews            : _____
Issues créées           : _____
Issues résolues         : _____
```

---

## 🎯 Checklist Finale de Présentation

### Code

- [ ] ☐ Compile sans erreurs
- [ ] ☐ Compile sans warnings
- [ ] ☐ Pas de segmentation faults
- [ ] ☐ Pas de fuites mémoire (Valgrind)
- [ ] ☐ Toutes fonctionnalités implémentées
- [ ] ☐ Code bien commenté
- [ ] ☐ Respect conventions nommage

### Fonctionnalités

- [ ] ☐ 1. Enregistrer étudiant
- [ ] ☐ 2. Modifier étudiant
- [ ] ☐ 3. Recherche linéaire
- [ ] ☐ 4. Supprimer étudiant
- [ ] ☐ 5. Tri alphabétique
- [ ] ☐ 6. Recherche dichotomique
- [ ] ☐ 7. Calculer âge
- [ ] ☐ 8. Tri par filière
- [ ] ☐ 9. Afficher tous
- [ ] ☐ 0. Quitter

### Gestion Mémoire

- [ ] ☐ Allocation dynamique fonctionnelle
- [ ] ☐ Redimensionnement automatique
- [ ] ☐ Libération propre
- [ ] ☐ Pas de fuites mémoire

### Persistance

- [ ] ☐ Sauvegarde données
- [ ] ☐ Chargement données
- [ ] ☐ Gestion fichier manquant

### Documentation

- [ ] ☐ README complet
- [ ] ☐ ARCHITECTURE à jour
- [ ] ☐ Guide utilisateur
- [ ] ☐ Commentaires code
- [ ] ☐ API documentée

### Git & GitHub

- [ ] ☐ Historique propre
- [ ] ☐ Messages commits clairs
- [ ] ☐ Pas de fichiers inutiles
- [ ] ☐ .gitignore correct
- [ ] ☐ Branches mergées

### Tests

- [ ] ☐ Tests unitaires passent
- [ ] ☐ Tests d'intégration OK
- [ ] ☐ Tests utilisateur OK
- [ ] ☐ Rapport de tests complet

### Présentation

- [ ] ☐ Archive créée
- [ ] ☐ Compilation testée depuis zéro
- [ ] ☐ README instructions claires
- [ ] ☐ Tous fichiers inclus
- [ ] ☐ Version taggée sur Git

---

## Notes et Observations

### Défis Rencontrés

```
1.
2.
3.
```

### Solutions Trouvées

```
1.
2.
3.
```

### Améliorations Futures

```
1.
2.
3.
```

---

_Document de suivi créé le : 21/12/2025_  
_Dernière mise à jour : 31/12/2025_
