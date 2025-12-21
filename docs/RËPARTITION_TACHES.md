# 👥 Répartition des Tâches - Gestion des Étudiants

## 📊 Vue d'Ensemble

**Base de référence** : `docs/PROJECT_PROGRESS.md`
**Durée estimée** : 2-3 semaines
**Équipe** : 6 personnes
**Méthode** : Développement modulaire avec intégration continue

---

## 🎯 Membre 1 - Chef de Projet & Interface

**Responsabilités** :

- Setup & Configuration (avec l'équipe)
- Interface Menu (`src/menu.c`, `include/menu.h`)
- Point d'entrée & Logique principale (`src/main.c`)
- Persistance des données (`src/data.c` - optionnel)

### Tâches Détaillées

#### Phase 1 : Setup & Configuration

- [ ] Créer le repository GitHub
- [ ] Initialiser la structure du projet (dossiers src, include, etc.)
- [ ] Configuration des branches `main` et `develop`
- [ ] Inviter les collaborateurs

#### Phase 6 : Interface Menu

- [ ] Créer `include/menu.h` et `src/menu.c`
- [ ] Implémenter `displayMenu()`
- [ ] Implémenter `getUserChoice()`
- [ ] Implémenter `processChoice()` (Routing vers les autres modules)
- [ ] Implémenter les fonctions d'affichage (`displayHeader`, `displaySuccess`, `displayError`)
- [ ] Gestion des sous-menus

#### Phase 7 : Main & Persistance

- [ ] Créer `src/main.c`
  - [ ] Initialisation (`initManagement`)
  - [ ] Boucle principale
  - [ ] Nettoyage mémoire (`freeManagement`)
- [ ] Persistance (Optionnel mais recommandé)
  - [ ] `saveData()` : Sauvegarde binaire
  - [ ] `loadData()` : Chargement au démarrage

---

## 👨‍💻 Membre 2 - Structure & CRUD

**Responsabilités** :

- Structure Étudiant (`src/student.c`, `include/student.h`)
- Opérations fondamentales (`src/operations.c`, `include/operations.h`)

### Tâches Détaillées

#### Phase 2 : Structure Student

- [ ] Créer `include/student.h`
  - [ ] Structure `Date`
  - [ ] Structure `Student`
  - [ ] Structure `Student_Management`
- [ ] Créer `src/student.c`
  - [ ] Gestion mémoire : `initManagement()`, `freeManagement()`, `resizeManagement()`
  - [ ] Affichage de base : `viewStudent()`, `viewAllStudents()`
  - [ ] Fonctions de comparaison de base

#### Phase 3 : CRUD Operations

- [ ] Créer `include/operations.h` et `src/operations.c`
- [ ] **Create** : `addStudent()`, `registerStudent()`
- [ ] **Read** : `getStudentById()`, `selectStudent()`, `getStudentInfo()`
- [ ] **Update** : `modifyStudent()`, `modifyStudentField()`
- [ ] **Delete** : `deleteStudent()`, `deleteStudentById()`, `deleteAllStudents()`

---

## 🔍 Membre 3 - Recherche & Tri

**Responsabilités** :

- Algorithmes de recherche (`src/search.c`, `include/search.h`)
- Algorithmes de tri (`src/sort.c`, `include/sort.h`)

### Tâches Détaillées

#### Phase 4 : Search & Sort

- [ ] **Recherche** (`src/search.c`)
  - [ ] `linearSearch()` : Recherche séquentielle
  - [ ] `binarySearch()` : Recherche dichotomique (nécessite liste triée)
  - [ ] `isSorted()` : Vérification de l'ordre
  - [ ] `smartSearch()` : Choix automatique de l'algo
- [ ] **Tri** (`src/sort.c`)
  - [ ] `sortAlphabetically()` : Tri par nom
  - [ ] `sortByOption()` : Tri par filière
  - [ ] `sortById()` : Tri par matricule (pour la recherche binaire)

---

## 🛠️ Membre 4 - Utilitaires & Validation

**Responsabilités** :

- Fonctions utilitaires (`src/utils.c`, `include/utils.h`)
- Validation des données (`src/validation.c`, `include/validation.h`)

### Tâches Détaillées

#### Phase 5 : Validation & Utils

- [ ] **Utilitaires** (`src/utils.c`)
  - [ ] `calculateAge()` : Calcul depuis date naissance
  - [ ] `getCurrentDate()`
  - [ ] `clearBuffer()`, `systemPause()`, `clearScreen()`
  - [ ] `stringToUpper()`, `safeCopy()`
  - [ ] `generateId()` : Génération automatique ID
- [ ] **Validation** (`src/validation.c`)
  - [ ] `validateId()`, `validateDate()`, `validateGender()`
  - [ ] `validateString()`
  - [ ] `inputValidString()`, `inputValidDate()`
  - [ ] `idExists()`

---

## 🧪 Membre 5 - Tests & Débogage

**Responsabilités** :

- Stratégie de tests
- Exécution des tests fonctionnels
- Débogage et identification des failles

### Tâches Détaillées

#### Phase 9 : Tests & Debug

- [ ] **Planification des tests**
  - [ ] Identifier les cas limites (tableaux vides/pleins, entrées invalides)
  - [ ] Identifier les scénarios critiques
- [ ] **Tests Fonctionnels**
  - [ ] Tester chaque option du menu
  - [ ] Tester la robustesse des saisies (Validation)
  - [ ] Tester les redimensionnements mémoire (CRUD)
  - [ ] Tester les tris et recherches
- [ ] **Rapport de Bugs Minimal**
  - [ ] Noter les bugs critiques et les remonter aux développeurs concernés
  - [ ] Vérifier les corrections

---

## 🔧 Membre 6 - Build & Config

**Responsabilités** :

- Configuration globale (`include/config.h`)
- Système de build (`Makefile`)
- Support Intégration

### Tâches Détaillées

#### Phase 2.1 : Configuration

- [ ] Créer `include/config.h`
  - [ ] Définir les constantes (MAX_ID, MAX_NAME, etc.)
  - [ ] Définir les paramètres (INITIAL_CAPACITY, RESIZE_FACTOR)

#### Phase 8 : Build System

- [ ] Créer `Makefile` robuste
  - [ ] Variables (CC, CFLAGS, SRC, OBJ)
  - [ ] Règles : `all`, `clean`, `fclean`, `re`
  - [ ] Règle `run` pour exécuter
  - [ ] Règle `debug` (avec gdb/valgrind flags)
- [ ] Support à l'intégration continue
  - [ ] Vérifier que le projet compile sur les machines des membres

---

## 📅 Planning Global Simplifié

1. **Jours 1-2** : Setup (M1), Config (M6), Structures Base (M2)
2. **Jours 2-4** : Core Utils (M4), Search Headers (M3), Makefile (M6)
3. **Jours 3-6** : CRUD Logic (M2), Menu Interface (M1), Sort Logic (M3)
4. **Jours 6-8** : Intégration Main (M1), Persistance (M1), Tests & Debug (M5)
5. **Jours 8-10** : Finalisation, Polish, Fixes (Tous)
