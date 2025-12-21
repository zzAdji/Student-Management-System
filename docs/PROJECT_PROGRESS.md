# 📊 Suivi de Progression du Projet

**Projet** : Student Management System  
**Date de début** : 22/12/2025
**Date limite** : 12/01/2026

---

## 📈 Vue d'Ensemble Globale

```
┌─────────────────────────────────────────────────────────────┐
│  PROGRESSION GLOBALE                                        │
├─────────────────────────────────────────────────────────────┤
│  Setup & Config        [████████  ] 8/10  (80%)           │
│  Structure & Base      [          ] 0/15  (0%)            │
│  CRUD Operations       [          ] 0/12  (0%)            │
│  Search & Sort         [          ] 0/10  (0%)            │
│  Validation & Utils    [          ] 0/12  (0%)            │
│  Interface (Menu)      [          ] 0/8   (0%)            │
│  Tests & Debug         [          ] 0/10  (0%)            │
│  Documentation         [          ] 0/8   (0%)            │
│  Integration           [          ] 0/5   (0%)            │
├─────────────────────────────────────────────────────────────┤
│  TOTAL                 [█         ] 8/90  (9%)            │
└─────────────────────────────────────────────────────────────┘
```

**Légende** : ☐ À faire | 🔄 En cours | ✅ Terminé | ⏸️ En pause | ❌ Bloqué

---

## 🎯 Phase 1 : Setup & Configuration (Jours 1-2)

**Responsable** : Membre 1 (Chef de Projet)  
**Progression** : 8/10 (80%)

### 1.1 Configuration Git & GitHub

- [ ] ✅ Créer compte GitHub (tous les membres)
- [ ] ✅ Créer repository "gestion-etudiants"
- [ ] ✅ Configurer Git localement (tous)
- [ ] ✅ Cloner le repository (tous)
- [ ] ✅ Créer branche `develop`
- [ ] ✅ Configurer protection branches (main, develop)
- [ ] 🔄 Inviter tous les collaborateurs
- [ ] 🔄 Tous acceptent invitation

**Notes** :

```
Date début : 20/12/2025
Date fin   : __/12/2025
```

### 1.2 Structure du Projet

- [ ] ✅ Créer dossiers (src, include, build, bin, data, docs, tests)
- [ ] ✅ Créer fichiers .gitkeep

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

**Progression** : 0/12 (0%)

#### 2.2.1 Header student.h

- [ ] ☐ Créer `include/student.h`
- [ ] ☐ Définir structure `Date`
- [ ] ☐ Définir structure `Student`
  - [ ] ☐ Tous les champs avec bons types
  - [ ] ☐ Commentaires documentation
- [ ] ☐ Définir structure `Student_Management`
  - [ ] ☐ Pointeur list
  - [ ] ☐ Champs number et capacity
- [ ] ☐ Prototypes gestion mémoire
  - [ ] ☐ `initManagement()`
  - [ ] ☐ `freeManagement()`
  - [ ] ☐ `resizeManagement()`
- [ ] ☐ Prototypes affichage
  - [ ] ☐ `viewStudent()`
  - [ ] ☐ `viewAllStudents()`
  - [ ] ☐ `displayTableHeader()`
- [ ] ☐ Prototypes comparaison
  - [ ] ☐ `compareStudentsByName()`
  - [ ] ☐ `compareStudentsById()`
  - [ ] ☐ `compareStudentsByOption()`
- [ ] ☐ Prototypes utilitaires
  - [ ] ☐ `copyStudent()`
  - [ ] ☐ `initStudent()`

#### 2.2.2 Implémentation student.c

- [ ] ☐ Créer `src/student.c`
- [ ] ☐ Implémenter `initManagement()`
  - [ ] ☐ Allocation mémoire initiale
  - [ ] ☐ Initialisation champs
  - [ ] ☐ Gestion erreurs
- [ ] ☐ Implémenter `freeManagement()`
  - [ ] ☐ Libération mémoire
  - [ ] ☐ Réinitialisation pointeurs
- [ ] ☐ Implémenter `resizeManagement()`
  - [ ] ☐ Calcul nouvelle capacité
  - [ ] ☐ Realloc
  - [ ] ☐ Gestion erreurs
- [ ] ☐ Implémenter `viewStudent()`
  - [ ] ☐ Affichage formaté avec bordures
- [ ] ☐ Implémenter `viewAllStudents()`
  - [ ] ☐ Gestion liste vide
  - [ ] ☐ Affichage tableau
- [ ] ☐ Implémenter `displayTableHeader()`
- [ ] ☐ Implémenter fonctions comparaison (3)
- [ ] ☐ Implémenter `copyStudent()`
- [ ] ☐ Implémenter `initStudent()`
- [ ] ☐ Tester compilation
- [ ] ☐ Tester chaque fonction
- [ ] ☐ Commit et push

**Notes** :

```
Date début : ___/___
Date fin   : ___/___
Tests      : ☐ initManagement ☐ resizeManagement ☐ viewStudent
Bugs       :
```

---

## 💾 Phase 3 : CRUD Operations (Jours 3-6)

**Responsable** : Membre 2  
**Progression** : 0/12 (0%)

### 3.1 Header operations.h

- [ ] ☐ Créer `include/operations.h`
- [ ] ☐ Prototypes CREATE
  - [ ] ☐ `addStudent()`
  - [ ] ☐ `registerStudent()`
- [ ] ☐ Prototypes READ
  - [ ] ☐ `getStudentById()`
  - [ ] ☐ `selectStudent()`
  - [ ] ☐ `getStudentInfo()`
- [ ] ☐ Prototypes UPDATE
  - [ ] ☐ `modifyStudent()`
  - [ ] ☐ `modifyStudentField()`
- [ ] ☐ Prototypes DELETE
  - [ ] ☐ `deleteStudent()`
  - [ ] ☐ `deleteAllStudents()`
  - [ ] ☐ `deleteStudentById()`

### 3.2 Implémentation operations.c

- [ ] ☐ Créer `src/operations.c`

#### CREATE

- [ ] ☐ Implémenter `addStudent()`
  - [ ] ☐ Vérifier capacité
  - [ ] ☐ Redimensionner si nécessaire
  - [ ] ☐ Ajouter étudiant
  - [ ] ☐ Incrémenter number
- [ ] ☐ Implémenter `registerStudent()`
  - [ ] ☐ Saisie interactive toutes infos
  - [ ] ☐ Validation données
  - [ ] ☐ Appel addStudent()
  - [ ] ☐ Messages succès/erreur

#### READ

- [ ] ☐ Implémenter `getStudentById()`
  - [ ] ☐ Recherche linéaire
  - [ ] ☐ Retour index ou -1
- [ ] ☐ Implémenter `selectStudent()`
  - [ ] ☐ Demander ID utilisateur
  - [ ] ☐ Appel getStudentById()
  - [ ] ☐ Affichage résultat
- [ ] ☐ Implémenter `getStudentInfo()`
  - [ ] ☐ Vérification index
  - [ ] ☐ Affichage détaillé

#### UPDATE

- [ ] ☐ Implémenter `modifyStudent()`
  - [ ] ☐ Menu modification
  - [ ] ☐ Modification champ par champ
  - [ ] ☐ Validation nouvelle valeur
  - [ ] ☐ Confirmation
- [ ] ☐ Implémenter `modifyStudentField()`
  - [ ] ☐ Switch selon champ
  - [ ] ☐ Saisie nouvelle valeur
  - [ ] ☐ Validation

#### DELETE

- [ ] ☐ Implémenter `deleteStudent()`
  - [ ] ☐ Vérification index
  - [ ] ☐ Décalage éléments
  - [ ] ☐ Décrément number
- [ ] ☐ Implémenter `deleteAllStudents()`
  - [ ] ☐ Confirmation utilisateur
  - [ ] ☐ Réinitialisation liste
- [ ] ☐ Implémenter `deleteStudentById()`
  - [ ] ☐ Recherche ID
  - [ ] ☐ Appel deleteStudent()

### 3.3 Tests

- [ ] ☐ Test addStudent() - capacité normale
- [ ] ☐ Test addStudent() - redimensionnement
- [ ] ☐ Test registerStudent() - saisie complète
- [ ] ☐ Test modifyStudent() - tous champs
- [ ] ☐ Test deleteStudent() - début, milieu, fin
- [ ] ☐ Test deleteAllStudents()
- [ ] ☐ Commit et push

**Notes** :

```
Date début : ___/___
Date fin   : ___/___
Bugs       :
```

---

## 🔍 Phase 4 : Search & Sort (Jours 4-7)

**Responsable** : Membre 3  
**Progression** : 0/10 (0%)

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
**Progression** : 0/12 (0%)

### 5.1 Utilitaires (utils.c/h)

#### Header

- [ ] ☐ Créer `include/utils.h`
- [ ] ☐ Prototypes manipulation date
  - [ ] ☐ `calculateAge()`
  - [ ] ☐ `getCurrentDate()`
- [ ] ☐ Prototypes système
  - [ ] ☐ `clearBuffer()`
  - [ ] ☐ `systemPause()`
  - [ ] ☐ `clearScreen()`
- [ ] ☐ Prototypes string
  - [ ] ☐ `stringToUpper()`
  - [ ] ☐ `stringToLower()`
  - [ ] ☐ `safeCopy()`
- [ ] ☐ Prototype `generateId()`

#### Implémentation

- [ ] ☐ Créer `src/utils.c`
- [ ] ☐ Implémenter `calculateAge()`
  - [ ] ☐ Parser date DD/MM/YYYY
  - [ ] ☐ Obtenir date actuelle
  - [ ] ☐ Calcul âge
  - [ ] ☐ Ajustement anniversaire
- [ ] ☐ Implémenter `getCurrentDate()`
  - [ ] ☐ time() et localtime()
  - [ ] ☐ Format DD/MM/YYYY
- [ ] ☐ Implémenter `clearBuffer()`
- [ ] ☐ Implémenter `systemPause()`
  - [ ] ☐ Version Windows
  - [ ] ☐ Version Linux/Mac
- [ ] ☐ Implémenter `clearScreen()`
  - [ ] ☐ Version Windows
  - [ ] ☐ Version Linux/Mac
- [ ] ☐ Implémenter `stringToUpper()`
- [ ] ☐ Implémenter `stringToLower()`
- [ ] ☐ Implémenter `safeCopy()`
  - [ ] ☐ strncpy sécurisé
  - [ ] ☐ Terminaison '\0'
- [ ] ☐ Implémenter `generateId()`
  - [ ] ☐ Format STU + année + numéro
- [ ] ☐ Tests utils
- [ ] ☐ Commit et push

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
Date début : ___/___
Date fin   : ___/___
Tests validation : ☐ Date ☐ ID ☐ Genre
```

---

## 🎨 Phase 6 : Interface Menu (Jours 3-6)

**Responsable** : Membre 1  
**Progression** : 0/8 (0%)

### 6.1 Header menu.h

- [ ] ☐ Créer `include/menu.h`
- [ ] ☐ Prototype `displayMenu()`
- [ ] ☐ Prototype `getUserChoice()`
- [ ] ☐ Prototype `processChoice()`
- [ ] ☐ Prototypes affichage messages
  - [ ] ☐ `displayHeader()`
  - [ ] ☐ `displaySuccess()`
  - [ ] ☐ `displayError()`
  - [ ] ☐ `displayInfo()`

### 6.2 Implémentation menu.c

- [ ] ☐ Créer `src/menu.c`
- [ ] ☐ Implémenter `displayMenu()`
  - [ ] ☐ Design avec bordures ASCII
  - [ ] ☐ 9 options + Quitter
  - [ ] ☐ Emojis/icônes
- [ ] ☐ Implémenter `getUserChoice()`
  - [ ] ☐ Saisie choix
  - [ ] ☐ Validation (0-9)
  - [ ] ☐ Boucle jusqu'à valide
- [ ] ☐ Implémenter `processChoice()`
  - [ ] ☐ Switch case 0-9
  - [ ] ☐ Case 1: registerStudent()
  - [ ] ☐ Case 2: modifyStudent() avec sous-menu
  - [ ] ☐ Case 3: linearSearch()
  - [ ] ☐ Case 4: deleteStudent() avec confirmation
  - [ ] ☐ Case 5: sortAlphabetically()
  - [ ] ☐ Case 6: binarySearch()
  - [ ] ☐ Case 7: calculateAge()
  - [ ] ☐ Case 8: sortByOption()
  - [ ] ☐ Case 9: viewAllStudents()
  - [ ] ☐ Case 0: Exit avec confirmation
  - [ ] ☐ Default: message erreur
- [ ] ☐ Implémenter fonctions affichage
  - [ ] ☐ `displayHeader()`
  - [ ] ☐ `displaySuccess()`
  - [ ] ☐ `displayError()`
  - [ ] ☐ `displayInfo()`
- [ ] ☐ Implémenter sous-menus
  - [ ] ☐ Menu modification (8 champs)
  - [ ] ☐ Menu confirmation suppression
  - [ ] ☐ Menu confirmation quitter
  - [ ] ☐ Menu sélection étudiant
- [ ] ☐ Tests menu
  - [ ] ☐ Test chaque option
  - [ ] ☐ Test choix invalides
  - [ ] ☐ Test navigation sous-menus
- [ ] ☐ Commit et push

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

- [ ] ☐ Implémenter ce design

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

- [ ] ☐ Implémenter ce sous-menu

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

- [ ] ☐ Implémenter ce sous-menu

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

- [ ] ☐ Implémenter ce formulaire

#### Menu Recherche

```
╔════════════════════════════════════════════════════╗
║              SEARCH STUDENT                        ║
╚════════════════════════════════════════════════════╝

Enter student ID to search: _______________________

Searching...
```

- [ ] ☐ Implémenter ce menu

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

- [ ] ☐ Implémenter cet affichage

#### Affichage Résultat Recherche - Non Trouvé

```
╔════════════════════════════════════════════════════╗
║              ❌ STUDENT NOT FOUND                  ║
╚════════════════════════════════════════════════════╝

No student with ID: STU2024999

────────────────────────────────────────────────────
Press Enter to continue...
```

- [ ] ☐ Implémenter cet affichage

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

- [ ] ☐ Implémenter cet affichage

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

- [ ] ☐ Implémenter ce menu

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

- [ ] ☐ Implémenter ces messages

**Notes** :

```
Date début : ___/___
Date fin   : ___/___
Design     : ☐ Bordures ☐ Couleurs ☐ Emojis
```

---

## 🚀 Phase 7 : Main & Persistance (Jours 6-8)

**Responsable** : Membre 1  
**Progression** : 0/7 (0%)

### 7.1 Fichier main.c

- [ ] ☐ Créer `src/main.c`
- [ ] ☐ Includes nécessaires
- [ ] ☐ Message bienvenue
- [ ] ☐ Initialisation
  - [ ] ☐ Déclarer Student_Management
  - [ ] ☐ Appel initManagement()
- [ ] ☐ Chargement données
  - [ ] ☐ Appel loadData()
  - [ ] ☐ Message si succès/échec
- [ ] ☐ Boucle principale
  - [ ] ☐ While choice != 0
  - [ ] ☐ displayMenu()
  - [ ] ☐ getUserChoice()
  - [ ] ☐ processChoice()
- [ ] ☐ Sortie propre
  - [ ] ☐ Sauvegarde saveData()
  - [ ] ☐ Libération freeManagement()
  - [ ] ☐ Message au revoir
- [ ] ☐ Compilation test
- [ ] ☐ Exécution test
- [ ] ☐ Commit et push

### 7.2 Persistance (data.c/h - optionnel)

- [ ] ☐ Créer `include/data.h`
- [ ] ☐ Prototype `saveData()`
- [ ] ☐ Prototype `loadData()`
- [ ] ☐ Créer `src/data.c`
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
Date début : ___/___
Date fin   : ___/___
Fichier data : data/students.dat (___Ko)
```

---

## 🔧 Phase 8 : Build System (Jours 2-8)

**Responsable** : Membre 6  
**Progression** : 0/5 (0%)

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
**Progression** : 0/10 (0%)

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
**Progression** : 0/8 (0%)

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
**Progression** : 0/5 (0%)

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
_Dernière mise à jour : 21/12/2025_
