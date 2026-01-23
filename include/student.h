#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
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
    char id[MAX_MATRICULE_LEN];              // Matricule unique
    char name[MAX_NOM_LEN];            // Nom de famille
    char surname[MAX_PRENOM_LEN];         // Prénom
    Date birth_date;          // Structure Date
    char gender;              // 'M' ou 'F'
    char department[MAX_DEPARTEMENT_LEN];      // Département d'études
    char option[MAX_FILIERE_LEN];          // Filière d'études
    char native_region[MAX_REGION_LEN];   // Région d'origine
} Student;

/**
 * @struct Student_Management
 * @brief Structure de gestion dynamique des étudiants
 */
typedef struct {
    Student *list;            // Tableau dynamique d'étudiants
    int number;               // Nombre actuel d'étudiants
    int capacity;             // Capacité maximale du tableau
    int autoSave;             // 1 = auto-save activé, 0 = désactivé
} Student_Management;

/**
 * @struct DepartmentInfo
 * @brief Structure contenant les informations d'un département et ses options
 */
typedef struct {
    const char *code;           // Code court du département (ex: "INFOTEL")
    const char *displayName;    // Nom d'affichage complet
    const char *options[MAX_OPTIONS_PER_DEPT]; // Options/filières disponibles
    int optionCount;            // Nombre d'options disponibles
} DepartmentInfo;

/**
 * Tableau des départements prédéfinis avec leurs options
 * Accessible globalement via extern dans les fichiers .c
 */
extern const DepartmentInfo PREDEFINED_DEPARTMENTS[NUM_DEPARTMENTS];

/**
 * Recherche un département par son code
 * @param code Code du département à rechercher
 * @return Pointeur vers le département trouvé ou NULL si non trouvé
 */
const DepartmentInfo* findDepartmentByCode(const char *code);

/**
 * Affiche les options d'un département et retourne le choix de l'utilisateur
 * @param dept Pointeur vers le département
 * @param selectedOption Buffer pour stocker l'option sélectionnée
 * @param bufferSize Taille du buffer
 * @return 1 si succès, 0 si échec
 */
int selectOptionFromDepartment(const DepartmentInfo *dept, char *selectedOption, size_t bufferSize);

/**
 * Affiche la liste des départements prédéfinis
 */
void displayPredefinedDepartments(void);

/* ===== Gestion mémoire ===== */
/**
 * Initialise la structure de gestion
 * Alloue une capacité initiale (par défaut 10)
 * @param management Pointeur vers la structure de gestion
 */
void initManagement(Student_Management *management, int capacity);

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

#endif
