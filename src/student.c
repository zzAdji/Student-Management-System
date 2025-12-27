#include "../include/student.h"

/* ===== Initialisation ===== */
void initManagement(Student_Management *mng, int capacity) {
    mng->students = malloc(sizeof(Student) * capacity);
    mng->size = 0;
    mng->capacity = capacity;
}

/* ===== Libération mémoire ===== */
void freeManagement(Student_Management *mng) {
    free(mng->students);
    mng->students = NULL;
    mng->size = 0;
    mng->capacity = 0;
}

/* ===== Redimensionnement ===== */
void resizeManagement(Student_Management *mng) {
    mng->capacity *= 2;
    mng->students = realloc(mng->students,
                             sizeof(Student) * mng->capacity);
}

/* ===== Affichage d’un étudiant ===== */
void viewStudent(Student s) {
    printf("ID: %d\n", s.id);
    printf("Nom: %s %s\n", s.name, s.lastname);
    printf("Date de naissance: %02d/%02d/%04d\n",
           s.birthDate.day, s.birthDate.month, s.birthDate.year);
}

/* ===== Affichage de tous les étudiants ===== */
void viewAllStudents(Student_Management *mng) {
    for (int i = 0; i < mng->size; i++) {
        viewStudent(mng->students[i]);
        printf("----------------------\n");
    }
}

/* ===== Comparaison par ID ===== */
int compareStudentById(Student s, int id) {
    return s.id == id;
}
