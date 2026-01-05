# 🏗️ Architecture du Système de Gestion des Étudiants

## 📋 Vue d'Ensemble

Ce document décrit l'architecture technique du système, l'organisation des modules, les structures de données et les responsabilités de chaque composant.

---

## 🎯 Principes de Conception

1. **Modularité** : Séparation claire des responsabilités
2. **Réutilisabilité** : Fonctions génériques et indépendantes
3. **Maintenabilité** : Code propre et bien documenté
4. **Efficacité** : Algorithmes optimisés (recherche dichotomique, tri rapide)
5. **Robustesse** : Validation des entrées et gestion d'erreurs

---

## 📁 Structure Détaillée des Fichiers

### 1. **main.c** - Point d'Entrée

**Responsabilité** : Initialisation et boucle principale

```c
/**
 * Point d'entrée du programme
 * - Initialise la structure de gestion
 * - Charge les données existantes
 * - Lance la boucle du menu
 * - Libère la mémoire avant sortie
 */

// Flux d'exécution
1. Afficher message de bienvenue
2. Initialiser Student_Management avec initManagement()
3. Demander capacité initiale (optionnel, peut être 10 par défaut)
4. Charger données depuis fichier (si existe)
5. Boucle menu principal
6. Sauvegarder données
7. Libérer mémoire avec freeManagement()
8. Quitter
```

**Responsable** : Membre 1 (Chef de Projet)

---

### 2. **student.c / student.h** - Structure de Données et Gestion

**Responsabilité** : Définition des structures et gestion de la mémoire dynamique

#### Structures Principales

```c
/**
 * @struct Student
 * @brief Structure représentant un étudiant
 */
typedef struct {
    int day;
    int month;
    int year;
} Date;

/**
 * @struct Student
 * @brief Structure représentant un étudiant
 */
typedef struct {
    char id[20];              // Matricule unique (ex: STU2024001)
    char name[50];            // Nom de famille
    char surname[50];         // Prénom
    Date birth_date;          // Structure Date
    char gender;              // 'M' ou 'F'
    char department[50];      // Département d'études
    char option[50];          // Filière d'études
    char native_region[50];   // Région d'origine
} Student;

/**
 * @struct Student_Management
 * @brief Structure de gestion dynamique des étudiants
 */
typedef struct {
    Student *list;            // Tableau dynamique d'étudiants
    int number;               // Nombre actuel d'étudiants
    int capacity;             // Capacité maximale du tableau
} Student_Management;
```

#### Fonctions de Gestion Mémoire

```c
/**
 * Initialise la structure de gestion
 * Alloue une capacité initiale (par défaut 10)
 * @param management Pointeur vers la structure de gestion
 */
void initManagement(Student_Management *management);

/**
 * Libère toute la mémoire allouée
 * @param management Pointeur vers la structure de gestion
 */
void freeManagement(Student_Management *management);

/**
 * Redimensionne le tableau si nécessaire
 * Double la capacité quand plein
 * @param management Pointeur vers la structure de gestion
 * @return 1 si succès, 0 si échec
 */
int resizeManagement(Student_Management *management);
```

#### Fonctions de Base

```c
/**
 * Affiche un étudiant
 * @param student Étudiant à afficher
 * @param index Index pour la numérotation
 */
void viewStudent(Student student, int index);

/**
 * Affiche tous les étudiants
 * @param management Pointeur vers la structure de gestion
 */
void viewAllStudents(Student_Management *management);

/**
 * Compare deux étudiants par nom
 * Compatible avec qsort
 */
int compareStudentsByName(const void *a, const void *b);

/**
 * Compare deux étudiants par filière
 * Compatible avec qsort
 */
int compareStudentsByOption(const void *a, const void *b);

/**
 * Compare deux étudiants par matricule
 * Compatible avec qsort
 */
int compareStudentsById(const void *a, const void *b);
```

**Responsable** : Membre 2

---

### 3. **operations.c / operations.h** - CRUD

**Responsabilité** : Opérations Create, Read, Update, Delete

#### Fonctions Principales

```c
/**
 * Ajouter un nouvel étudiant
 * Redimensionne automatiquement si nécessaire
 * @param management Pointeur vers la structure de gestion
 * @param student Étudiant à ajouter
 * @return 1 si succès, 0 sinon
 */
int addStudent(Student_Management *management, Student student);

/**
 * Obtenir un étudiant par matricule
 * @param management Pointeur vers la structure de gestion
 * @param id Matricule recherché
 * @return Étudiant trouvé ou étudiant vide si non trouvé
 */
Student getStudent(Student_Management *management, const char *id);

/**
 * Sélectionner un étudiant interactivement
 * Demande le matricule à l'utilisateur
 * @param management Pointeur vers la structure de gestion
 * @return Index de l'étudiant ou -1 si non trouvé
 */
int selectStudent(Student_Management *management);

/**
 * Modifier les informations d'un étudiant
 * Utilise des pointeurs pour modification directe
 * @param management Pointeur vers la structure de gestion
 * @param index Index de l'étudiant à modifier
 * @return 1 si succès, 0 sinon
 */
int modifyStudent(Student_Management *management, int index);

/**
 * Supprimer un étudiant
 * Décale les éléments pour combler le vide
 * @param management Pointeur vers la structure de gestion
 * @param index Index de l'étudiant à supprimer
 * @return 1 si supprimé, 0 sinon
 */
int deleteStudent(Student_Management *management, int index);

/**
 * Supprimer tous les étudiants
 * Réinitialise la liste
 * @param management Pointeur vers la structure de gestion
 */
void deleteAllStudents(Student_Management *management);

/**
 * Obtenir les informations d'un étudiant
 * Affiche toutes les informations détaillées
 * @param management Pointeur vers la structure de gestion
 * @param index Index de l'étudiant
 * @return 1 si trouvé, 0 sinon
 */
int verifyStudent(Student_Management *management, int index);
```

**Responsable** : Membre 2

---

### 4. **search.c / search.h** - Algorithmes de Recherche

**Responsabilité** : Recherche linéaire et dichotomique

#### Fonctions

```c
/**
 * Recherche linéaire par matricule
 * Complexité: O(n)
 * @param management Pointeur vers la structure de gestion
 * @param id Matricule recherché
 * @return Index si trouvé, -1 sinon
 */
int linearSearch(Student_Management *management, const char *id);

/**
 * Recherche dichotomique (binaire)
 * Prérequis: Liste DOIT être triée par matricule
 * Complexité: O(log n)
 * @param management Pointeur vers la structure de gestion
 * @param id Matricule recherché
 * @return Index si trouvé, -1 sinon
 */
int binarySearch(Student_Management *management, const char *id);

/**
 * Vérifier si la liste est triée par matricule
 * Nécessaire avant recherche dichotomique
 * @param management Pointeur vers la structure de gestion
 * @return 1 si trié, 0 sinon
 */
int isSorted(Student_Management *management);

/**
 * Recherche intelligente
 * Choisit automatiquement entre linéaire et dichotomique
 * @param management Pointeur vers la structure de gestion
 * @param id Matricule recherché
 * @return Index si trouvé, -1 sinon
 */
int smartSearch(Student_Management *management, const char *id);
```

**Responsable** : Membre 3

---

### 5. **sort.c / sort.h** - Algorithmes de Tri

**Responsabilité** : Tri alphabétique et par filière

#### Fonctions

```c
/**
 * Tri par ordre alphabétique (par nom)
 * Utilise qsort de stdlib.h
 * @param management Pointeur vers la structure de gestion
 */
void sortAlphabetically(Student_Management *management);

/**
 * Tri par filière
 * Tri stable pour garder l'ordre alphabétique interne
 * @param management Pointeur vers la structure de gestion
 */
void sortByOption(Student_Management *management);

/**
 * Tri par matricule (pour recherche dichotomique)
 * @param management Pointeur vers la structure de gestion
 */
void sortById(Student_Management *management);
```

**Implémentation Suggérée**

```c
void sortAlphabetically(Student_Management *management) {
    qsort(management->list, management->number,
          sizeof(Student), compareStudentsByName);
}
```

**Responsable** : Membre 3

---

### 6. **utils.c / utils.h** - Utilitaires

**Responsabilité** : Fonctions auxiliaires et calculs

#### Fonctions

```c
/**
 * Calculer l'âge à partir de la date de naissance
 * Prend en compte l'année, mois et jour actuels
 * @param birth_date Date de naissance (structure Date)
 * @return Âge en années
 */
int calculateAge(Date birth_date);

/**
 * Obtenir la date actuelle du système
 * @param buffer Buffer pour stocker la date (format DD/MM/YYYY)
 */
void getCurrentDate(char *buffer);

/**
 * Nettoyer le buffer d'entrée
 * Évite les problèmes avec scanf/fgets
 */
void clearBuffer(void);

/**
 * Pause système multiplateforme
 * Windows: system("pause")
 * Linux/Mac: getchar()
 */
void systemPause(void);

/**
 * Effacer l'écran multiplateforme
 */
void clearScreen(void);

/**
 * Convertir une chaîne en majuscules
 * @param str Chaîne à convertir
 */
void stringToUpper(char *str);

/**
 * Convertir une chaîne en minuscules
 * @param str Chaîne à convertir
 */
void stringToLower(char *str);

/**
 * Générer un matricule automatique
 * Format: STU + année + numéro séquentiel
 * @param id Buffer pour stocker le matricule
 * @param number Numéro séquentiel
 */
void generateId(char *id, int number);

/**
 * Copier une chaîne de manière sécurisée
 * @param dest Destination
 * @param src Source
 * @param size Taille maximale
 */
void safeCopy(char *dest, const char *src, int size);
```

**Implémentation Calcul Âge**

```c
int calculateAge(Date birth_date) {
    // Plus besoin de sscanf car on a déjà les entiers
    int day = birth_date.day;
    int month = birth_date.month;
    int year = birth_date.year;

    time_t t = time(NULL);
    struct tm *today = localtime(&t);

    int age = (today->tm_year + 1900) - year;

    // Ajuster si anniversaire pas encore passé
    if ((today->tm_mon + 1) < month ||
        ((today->tm_mon + 1) == month && today->tm_mday < day)) {
        age--;
    }

    return age;
}
```

**Responsable** : Membre 4

---

### 7. **validation.c / validation.h** - Validation des Données

**Responsabilité** : Validation et sécurisation des entrées

#### Fonctions

```c
/**
 * Valider le format du matricule
 * Format attendu: lettres + chiffres (ex: STU2024001)
 * @param id Chaîne à valider
 * @return 1 si valide, 0 sinon
 */
int validateId(const char *id);

/**
 * Valider une date
 * Vérifie jours valides pour chaque mois, années bissextiles
 * @param date Chaîne date format DD/MM/YYYY
 * @return 1 si valide, 0 sinon
 */
int validateDate(const char *date);

/**
 * Valider le sexe
 * Accepte seulement 'M' ou 'F' (case-insensitive)
 * @param gender Caractère à valider
 * @return 1 si valide, 0 sinon
 */
int validateGender(char gender);

/**
 * Valider une chaîne non vide
 * Vérifie qu'elle contient au moins un caractère non-espace
 * @param str Chaîne à valider
 * @return 1 si valide, 0 sinon
 */
int validateString(const char *str);

/**
 * Saisir une chaîne avec validation
 * Redemande jusqu'à obtenir une entrée valide
 * @param dest Buffer destination
 * @param size Taille maximale
 * @param prompt Message à afficher
 */
void inputValidString(char *dest, int size, const char *prompt);

/**
 * Saisir une date avec validation
 * @param dest Buffer destination
 * @param prompt Message à afficher
 */
void inputValidDate(char *dest, const char *prompt);

/**
 * Vérifier si un matricule existe déjà
 * @param management Pointeur vers la structure de gestion
 * @param id Matricule à vérifier
 * @return 1 si existe, 0 sinon
 */
int idExists(Student_Management *management, const char *id);

/**
 * Vérifier si l'année est bissextile
 * @param year Année à vérifier
 * @return 1 si bissextile, 0 sinon
 */
int isLeapYear(int year);
```

**Responsable** : Membre 4

---

### 8. **menu.c / menu.h** - Interface Utilisateur

**Responsabilité** : Affichage du menu et gestion des choix

#### Fonctions

```c
/**
 * Afficher le menu principal
 * Design professionnel avec bordures ASCII
 */
void displayMenu(void);

/**
 * Obtenir le choix de l'utilisateur
 * Valide l'entrée (doit être entre 0 et 9)
 * @return Choix valide (0-9)
 */
int getUserChoice(void);

/**
 * Traiter le choix de l'utilisateur
 * Appelle les fonctions appropriées selon le choix
 * @param choice Choix de l'utilisateur
 * @param management Pointeur vers la structure de gestion
 */
void processChoice(int choice, Student_Management *management);

/**
 * Afficher un en-tête de section
 * @param title Titre à afficher
 */
void displayHeader(const char *title);

/**
 * Afficher un message de succès
 * @param message Message à afficher
 */
void displaySuccess(const char *message);

/**
 * Afficher un message d'erreur
 * @param message Message à afficher
 */
void displayError(const char *message);

/**
 * Afficher un message d'information
 * @param message Message à afficher
 */
void displayInfo(const char *message);
```

**Design Menu**

```c
void displayMenu(void) {
    printf("\n");
    printf("╔════════════════════════════════════════════════════╗\n");
    printf("║        STUDENT MANAGEMENT SYSTEM                  ║\n");
    printf("╚════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("  1. Register a student\n");
    printf("  2. Modify information\n");
    printf("  3. Search (by ID)\n");
    printf("  4. Delete a student\n");
    printf("  5. Sort alphabetically\n");
    printf("  6. Binary search\n");
    printf("  7. Calculate student age\n");
    printf("  8. Sort by option\n");
    printf("  9. Display all students\n");
    printf("  0. 🚪 Exit\n");
    printf("\n");
    printf("────────────────────────────────────────────────────\n");
}
```

**Responsable** : Membre 1 (Chef de Projet)

---

### 9. **config.h** - Configurations et Constantes

```c
#ifndef CONFIG_H
#define CONFIG_H

// Size limits
#define MAX_ID 20
#define MAX_NAME 50
#define MAX_SURNAME 50
#define MAX_DEPARTMENT 50
#define MAX_OPTION 50
#define MAX_REGION 50
#define MAX_DATE 11              // DD/MM/YYYY + '\0'

// Initial capacity
#define INITIAL_CAPACITY 10
#define RESIZE_FACTOR 2

// File paths
#define DATA_FILE "data/students.dat"
#define LOG_FILE "data/logs.txt"

// Messages
#define MSG_WELCOME "Welcome to the Student Management System"
#define MSG_GOODBYE "Thank you for using our system"

// Return codes
#define SUCCESS 1
#define FAILURE 0

// Gender constants
#define MALE 'M'
#define FEMALE 'F'

#endif
```

**Responsable** : Membre 6

---

## 🔄 Flux de Données

### 1. Démarrage de l'Application

```
main()
  │
  ├─> Display welcome message
  │
  ├─> Initialize Student_Management
  │   initManagement(&management)
  │   - Allocate initial capacity (10 students)
  │
  ├─> Load existing data
  │   if (loadData(&management) == FAILURE)
  │       "No previous data found, starting fresh"
  │
  └─> Start menu loop
```

### 2. Boucle Principale

```
while (choice != 0)
  │
  ├─> displayMenu()
  ├─> choice = getUserChoice()
  │
  └─> processChoice(choice, &management)
      │
      ├─> case 1: Register student
      │   ├─> Input student data
      │   ├─> Validate data
      │   └─> addStudent(&management, student)
      │       └─> Auto-resize if needed
      │
      ├─> case 2: Modify student
      │   ├─> selectStudent(&management) → index
      │   └─> modifyStudent(&management, index)
      │
      ├─> case 3: Linear search
      │   └─> linearSearch(&management, id)
      │
      ├─> case 4: Delete student
      │   ├─> selectStudent(&management) → index
      │   └─> deleteStudent(&management, index)
      │
      ├─> case 5: Sort alphabetically
      │   └─> sortAlphabetically(&management)
      │
      ├─> case 6: Binary search
      │   ├─> if (!isSorted(&management))
      │   │   └─> sortById(&management)
      │   └─> binarySearch(&management, id)
      │
      ├─> case 7: Calculate age
      │   ├─> selectStudent(&management) → index
      │   └─> calculateAge(student.birth_date)
      │
      ├─> case 8: Sort by option
      │   └─> sortByOption(&management)
      │
      └─> case 9: Display all
          └─> viewAllStudents(&management)
```

### 3. Sauvegarde et Sortie

```
Exit (choice == 0)
  │
  ├─> Save data to file
  │   saveData(&management)
  │
  ├─> Free memory
  │   freeManagement(&management)
  │
  └─> Display goodbye message
```

---

## 💾 Gestion de la Mémoire

### Allocation Dynamique avec Redimensionnement

```c
// Dans student.c

/**
 * Initialise la structure de gestion avec capacité initiale
 */
void initManagement(Student_Management *management) {
    management->capacity = INITIAL_CAPACITY;
    management->number = 0;
    management->list = (Student *)malloc(management->capacity * sizeof(Student));

    if (management->list == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * Redimensionne le tableau si nécessaire
 * Double la capacité quand il est plein
 */
int resizeManagement(Student_Management *management) {
    int newCapacity = management->capacity * RESIZE_FACTOR;

    Student *newList = (Student *)realloc(management->list,
                                          newCapacity * sizeof(Student));

    if (newList == NULL) {
        fprintf(stderr, "Error: Memory reallocation failed\n");
        return FAILURE;
    }

    management->list = newList;
    management->capacity = newCapacity;

    printf("Info: Capacity increased to %d\n", newCapacity);
    return SUCCESS;
}

/**
 * Libère toute la mémoire allouée
 */
void freeManagement(Student_Management *management) {
    if (management->list != NULL) {
        free(management->list);
        management->list = NULL;
    }
    management->number = 0;
    management->capacity = 0;
}
```

### Utilisation dans main.c

```c
int main(void) {
    Student_Management management;

    // Initialisation
    initManagement(&management);

    // ... utilisation du programme ...

    // Libération avant sortie
    freeManagement(&management);

    return 0;
}
```

### Ajout avec Redimensionnement Automatique

```c
// Dans operations.c
int addStudent(Student_Management *management, Student student) {
    // Vérifier si redimensionnement nécessaire
    if (management->number >= management->capacity) {
        if (resizeManagement(management) == FAILURE) {
            return FAILURE;
        }
    }

    // Ajouter l'étudiant
    management->list[management->number] = student;
    management->number++;

    return SUCCESS;
}
```

### Gestion des Chaînes

```c
// Utilisation de strncpy pour éviter débordement
void safeCopy(char *dest, const char *src, int size) {
    strncpy(dest, src, size - 1);
    dest[size - 1] = '\0';  // Terminer explicitement
}

// Utilisation
safeCopy(student.name, inputName, MAX_NAME);
```

---

## 📂 Persistance des Données

### Format de Fichier

Le fichier `data/students.dat` est un fichier binaire.

```c
// Sauvegarde
void saveData(Student_Management *management) {
    FILE *file = fopen(DATA_FILE, "wb");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    // Écrire la capacité et le nombre d'étudiants
    fwrite(&management->capacity, sizeof(int), 1, file);
    fwrite(&management->number, sizeof(int), 1, file);

    // Écrire les données des étudiants
    fwrite(management->list, sizeof(Student), management->number, file);

    fclose(file);
    printf("Data saved successfully!\n");
}

// Chargement
int loadData(Student_Management *management) {
    FILE *file = fopen(DATA_FILE, "rb");
    if (file == NULL) {
        return FAILURE;  // Fichier n'existe pas (première exécution)
    }

    int capacity, number;

    // Lire la capacité et le nombre
    fread(&capacity, sizeof(int), 1, file);
    fread(&number, sizeof(int), 1, file);

    // Libérer l'ancien tableau si nécessaire
    if (management->list != NULL) {
        free(management->list);
    }

    // Allouer nouvelle mémoire
    management->capacity = capacity;
    management->number = number;
    management->list = (Student *)malloc(capacity * sizeof(Student));

    if (management->list == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        fclose(file);
        return FAILURE;
    }

    // Lire les données
    fread(management->list, sizeof(Student), number, file);

    fclose(file);
    printf("Data loaded successfully! (%d students)\n", number);
    return SUCCESS;
}
```

---

## 🧪 Stratégie de Test

### Tests Unitaires Suggérés

```c
// tests/test_operations.c

void testCalculateAge() {
    char birth_date[] = "15/06/2000";
    int age = calculateAge(birth_date);
    assert(age >= 24);  // En 2024
}

void testValidateDate() {
    // Année bissextile
    assert(validateDate("29/02/2024") == 1);

    // Non bissextile
    assert(validateDate("29/02/2023") == 0);

    // Date invalide
    assert(validateDate("32/01/2024") == 0);
}

void testBinarySearch() {
    Student_Management management;
    initManagement(&management);

    // Ajouter des étudiants et trier
    // ...
    sortById(&management);

    // Rechercher élément existant
    int index = binarySearch(&management, "STU2024001");
    assert(index != -1);

    // Rechercher élément inexistant
    index = binarySearch(&management, "STU9999999");
    assert(index == -1);

    freeManagement(&management);
}

void testResize() {
    Student_Management management;
    initManagement(&management);

    int initialCapacity = management.capacity;

    // Ajouter plus que la capacité initiale
    for (int i = 0; i < initialCapacity + 5; i++) {
        Student s;
        sprintf(s.id, "STU%04d", i);
        addStudent(&management, s);
    }

    // Vérifier que la capacité a augmenté
    assert(management.capacity > initialCapacity);

    freeManagement(&management);
}
```

---

## ⚡ Optimisations

### 1. Recherche Dichotomique

Nécessite un tri préalable, mais **beaucoup plus rapide** pour grandes données.

- Recherche linéaire : O(n) - 1000 étudiants = 1000 comparaisons max
- Recherche dichotomique : O(log n) - 1000 étudiants = 10 comparaisons max

### 2. Tri avec qsort

Utiliser `qsort()` de `stdlib.h` (implémentation optimisée).

### 3. Réallocation Dynamique (Bonus)

Si besoin d'ajouter plus d'étudiants que prévu :

```c
tableau = realloc(tableau, nouvelle_taille * sizeof(Gestion_des_Etudians));
```

---

## 🔒 Gestion des Erreurs

### Principes

1.  **Vérifier tous les retours de fonctions critiques**

    - malloc, fopen, scanf, etc.

2.  **Messages d'erreur clairs**

    ```c
    if (fichier == NULL) {
        fprintf(stderr, "Erreur: Impossible d'ouvrir %s\n", nom_fichier);
        perror("Détails");
    }
    ```

3.  **Codes de retour cohérents**
    - 1 (SUCCES) pour succès
    - 0 (ECHEC) pour échec

---

## 📚 Références et Ressources

### Algorithmes

- **Recherche dichotomique** : https://fr.wikipedia.org/wiki/Recherche_dichotomique
- **qsort** : https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm

### Bonnes Pratiques C

- Toujours initialiser les variables
- Vérifier les retours de malloc
- Libérer toute mémoire allouée
- Utiliser const pour paramètres non modifiés

---

## 👥 Répartition des Responsabilités

| Module           | Fichiers                    | Responsable | Priorité |
| :--------------- | :-------------------------- | :---------- | :------- |
| Main & Menu      | main.c, menu.c/h            | Membre 1    | Haute    |
| Structure & CRUD | student.c/h, operations.c/h | Membre 2    | Haute    |
| Search           | search.c/h                  | Membre 3    | Moyenne  |
| Sort             | sort.c/h                    | Membre 3    | Moyenne  |
| Utils            | utils.c/h                   | Membre 4    | Moyenne  |
| Validation       | validation.c/h              | Membre 4    | Haute    |
| Tests & Debug    | tests/                      | Membre 5    | Haute    |
| Build & Config   | Makefile, config.h          | Membre 6    | Moyenne  |
| Integration      | -                           | Membre 6    | Continue |

---

## 📝 Conventions de Nommage

### Style de Code

- **Indentation** : 4 espaces (pas de tabulations)
- **Accolades** : Style K&R
- **Nommage** :
  - Variables : `snake_case` (ex: `number_of_students`, `current_index`)
  - Fonctions : `camelCase` (ex: `addStudent`, `calculateAge`)
  - Constantes : `UPPER_CASE` (ex: `MAX_STUDENTS`, `INITIAL_CAPACITY`)
  - Structures : `PascalCase` (ex: `Student`, `Student_Management`)
  - Types : `PascalCase` avec suffixe (ex: `Student_Management`)

### Exemple de Code

```c
// Bon exemple
int calculateAge(const char *birth_date) {
    int day, month, year;
    sscanf(birth_date, "%d/%d/%d", &day, &month, &year);
    // Code ici
    return age;
}

// Structure avec commentaires clairs
typedef struct {
    char id[MAX_ID];              // Unique identifier
    char name[MAX_NAME];          // Family name
    char surname[MAX_SURNAME];    // First name
    // ... autres champs
} Student;
```
