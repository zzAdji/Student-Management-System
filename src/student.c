#include <string.h>
#include <stdlib.h>
#include "../include/student.h"
#include <string.h>
#include "../include/utils.h"
#include "../include/config.h"

/* ===== Initialisation ===== */
void initManagement(Student_Management *management, int capacity) {
    management->list = (Student *)malloc(sizeof(Student) * capacity);
    
    if (management->list == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    management->number = 0;
    management->capacity = capacity;
    management->autoSave = 1;
}

/* ===== Libération mémoire ===== */
void freeManagement(Student_Management *management) {
    free(management->list);
    management->list = NULL;
    management->number = 0;
    management->capacity = 0;
}

/* ===== Redimensionnement ===== */
int resizeManagement(Student_Management *management) {
    int newCapacity;
    
    if (management->capacity == 0) {
        newCapacity = 10;
    } else {
        newCapacity = management->capacity * DB_GROWTH_FACTOR;
    }
    
    Student *newList = (Student *)realloc(management->list,
                                          sizeof(Student) * newCapacity);
    
    if (newList == NULL) {
        fprintf(stderr, "Error: Memory reallocation failed\n");
        return 0; // FAILURE
    }
    
    management->list = newList;
    management->capacity = newCapacity;
    return 1; // SUCCESS
}

/* ===== Affichage d'un étudiant ===== */
void viewStudent(Student student, int index) {
    
    char idFormatted[64];
    char nameFormatted[64];
    char surnameFormatted[64];
    char optionFormatted[64];
    
    formatTableCell(idFormatted, student.id, ID_WIDTH, sizeof(idFormatted));
    formatTableCell(nameFormatted, student.name, NAME_WIDTH, sizeof(nameFormatted));
    formatTableCell(surnameFormatted, student.surname, SURNAME_WIDTH, sizeof(surnameFormatted));
    formatTableCell(optionFormatted, student.option, OPTION_WIDTH, sizeof(optionFormatted));
    
    // Afficher la ligne du tableau
    printf("│ %-3d │ %s │ %s │ %s │ %02d/%02d/%04d │ %s │\n",
           index + 1,
           idFormatted,
           nameFormatted,
           surnameFormatted,
           student.birth_date.day,
           student.birth_date.month,
           student.birth_date.year,
           optionFormatted);
}

/* ===== Affichage de tous les étudiants ===== */

void viewAllStudents(Student_Management *management) {
    int termWidth = getTerminalWidth();
    int tableWidth = 86;
    int margin = (termWidth - tableWidth) / 2;
    if (margin < 0) margin = 0;

    for (int i = 0; i < management->number; i++) {
        Student s = management->list[i];
        printSpaces(margin); 
        viewStudent(s, i);
    }
}


/* ===== Comparaison par ID ===== */
/**
 * Compare deux étudiants par matricule
 * Compatible avec qsort
 */
int compareStudentsById(const void *a, const void *b) {
    const Student *s1 = (const Student *)a;
    const Student *s2 = (const Student *)b;

    return strcmp(s1->id, s2->id);
}

/* ===== Comparaison par nom ===== */
/**
 * Compare deux étudiants par nom
 * Compatible avec qsort
 * @param a Pointeur vers le premier étudiant
 * @param b Pointeur vers le second étudiant
 * @return <0 si a < b, 0 si a == b, >0 si a > b
 */
int compareStudentsByName(const void *a, const void *b) {
    const Student *stuA = (const Student *)a;
    const Student *stuB = (const Student *)b;

    // Utilise strcmp pour comparer les noms
    return strcmp(stuA->name, stuB->name);
}

/* ===== Comparaison par option===== */
/**
 * Compare deux étudiants par filière (option)
 * Compatible avec qsort
 * @param a Pointeur vers le premier étudiant
 * @param b Pointeur vers le second étudiant
 * @return <0 si a < b, 0 si a == b, >0 si a > b
 */
int compareStudentsByOption(const void *a, const void *b) {
    const Student *stuA = (const Student *)a;
    const Student *stuB = (const Student *)b;

    // Utilise strcmp pour comparer les options
    return strcmp(stuA->option, stuB->option);
}

/**
 * Tableau des départements prédéfinis avec leurs options
 * Chaque département a un code, un nom d'affichage et une liste d'options
 */
const DepartmentInfo PREDEFINED_DEPARTMENTS[NUM_DEPARTMENTS] = {
    {
        "AHN",
        "Art et Humanité Numérique",
        {"Art Numérique", "Humanité Numérique"},
        2
    },
    {
        "INFOTEL",
        "Informatique et Télécommunications",
        {"Génie Logiciel", "Réseaux et Télécommunications", "Robotique", "Data Science", "Cybersécurité"},
        5
    },
    {
        "ENREN",
        "Énergies Renouvelables",
        {"Énergie Solaire", "Énergie Éolienne", "Biomasse et Biogaz", "Hydroélectricité"},
        4
    },
    {
        "GC",
        "Génie Civil",
        {"Génie Civil"},
        1
    },
    {
        "AGEPD",
        "Agriculture, Elévage et Produits Dérivé",
        {"Productions Végétales", "Productions Animales", "Agroéconomie"},
        3
    },
};

/**
 * Recherche un département par son code (insensible à la casse)
 */
const DepartmentInfo* findDepartmentByCode(const char *code) {
    if (code == NULL) return NULL;
    
    for (int i = 0; i < NUM_DEPARTMENTS; i++) {
        if (strcasecmp(code, PREDEFINED_DEPARTMENTS[i].code) == 0) {
            return &PREDEFINED_DEPARTMENTS[i];
        }
    }
    return NULL;
}

/**
 * Affiche les options d'un département et retourne le choix de l'utilisateur
 */
int selectOptionFromDepartment(const DepartmentInfo *dept, char *selectedOption, size_t bufferSize) {
    if (dept == NULL || selectedOption == NULL || bufferSize == 0) {
        return 0;
    }

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 50) / 2;
    if (margin < 0) margin = 0;

    printf("\n");
    printSpaces(margin);
    printf(COLOR_CYAN "━━━ Options disponibles pour %s ━━━" COLOR_RESET "\n\n", dept->displayName);

    for (int i = 0; i < dept->optionCount; i++) {
        printSpaces(margin);
        printf("  " COLOR_YELLOW "%d." COLOR_RESET " %s\n", i + 1, dept->options[i]);
    }

    printf("\n");
    printSpaces(margin);
    printf("Votre choix (1-%d) : ", dept->optionCount);

    int choice;
    int result = scanf("%d", &choice);
    clearBuffer();

    if (result != 1 || choice < 1 || choice > dept->optionCount) {
        printf("\n");
        printSpaces(margin);
        printf(COLOR_RED "Choix invalide. Veuillez réessayer." COLOR_RESET "\n");
        return selectOptionFromDepartment(dept, selectedOption, bufferSize);
    }

    safeCopy(selectedOption, dept->options[choice - 1], bufferSize);

    return 1;
}

/**
 * Affiche la liste des départements prédéfinis
 */
void displayPredefinedDepartments(void) {
    int termWidth = getTerminalWidth();
    int margin = (termWidth - 50) / 2;
    if (margin < 0) margin = 0;

    printf("\n");
    printSpaces(margin);
    printf(COLOR_CYAN "━━━ Départements ━━━" COLOR_RESET "\n\n");

    for (int i = 0; i < NUM_DEPARTMENTS; i++) {
        printSpaces(margin);
        printf("  " COLOR_YELLOW "%-20s" COLOR_RESET " - %s\n", 
               PREDEFINED_DEPARTMENTS[i].code, 
               PREDEFINED_DEPARTMENTS[i].displayName);
    }

    printf("\n");
    printSpaces(margin);
    printf(COLOR_WHITE "Tapez un code ci-dessus, ou tout autre département personnalisé." COLOR_RESET "\n\n");
}
