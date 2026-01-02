#include <string.h>
#include <stdlib.h>
#include "../include/student.h"

/* ===== Initialisation ===== */
void initManagement(Student_Management *mng, int capacity) {
    mng->list = (Student *)malloc(sizeof(Student) * capacity);
    
    if (mng->list == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    mng->number = 0;
    mng->capacity = capacity;
}

/* ===== Libération mémoire ===== */
void freeManagement(Student_Management *mng) {
    free(mng->list);
    mng->list = NULL;
    mng->number = 0;
    mng->capacity = 0;
}

/* ===== Redimensionnement ===== */
int resizeManagement(Student_Management *mng) {
    int newCapacity = mng->capacity * 2;
    Student *newList = (Student *)realloc(mng->list,
                                          sizeof(Student) * newCapacity);
    
    if (newList == NULL) {
        fprintf(stderr, "Error: Memory reallocation failed\n");
        return 0; // FAILURE
    }
    
    mng->list = newList;
    mng->capacity = newCapacity;
    printf("Info: Capacity increased to %d\n", newCapacity);
    return 1; // SUCCESS
}

/* ===== Affichage d’un étudiant ===== */
void viewStudent(Student student, int index) {
    printf("Étudiant #%d\n", index);
    printf("ID: %d\n", student.id);
    printf("Nom: %s %s\n", student.name, student.surname);
    printf("Date de naissance: %02d/%02d/%04d\n",
           student.birth_date.day,
           student.birth_date.month,
           student.birth_date.year);
}

/* ===== Affichage de tous les étudiants ===== */

void viewAllStudents(Student_Management *mng) {
    for (int i = 0; i < mng->number; i++) {
        viewStudent(mng->list[i], i);
        printf("----------------------\n");
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