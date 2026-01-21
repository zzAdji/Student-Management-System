#include <string.h>
#include <stdlib.h>
#include "../include/student.h"
#include <string.h>
#include "../include/utils.h"

/* ===== Initialisation ===== */
void initManagement(Student_Management *management, int capacity) {
    management->list = (Student *)malloc(sizeof(Student) * capacity);
    
    if (management->list == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    management->number = 0;
    management->capacity = capacity;
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
    int newCapacity = management->capacity * 2;
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

/* ===== Affichage d’un étudiant ===== */
void viewStudent(Student student, int index) {
    printf("│ %-3d │ %-15.15s │ %-12.12s │ %-12.12s │ %02d/%02d/%04d │ %-15.15s │\n",
               index + 1,
               student.id,
               student.name,
               student.surname,
               student.birth_date.day,
               student.birth_date.month,
               student.birth_date.year,
               student.option);
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