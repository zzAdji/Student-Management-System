#include <stdio.h>
#include "../include/student.h"
#include "../include/operations.h"

int main(void) {

    printf("===== TEST STRUCTURE & CRUD =====\n\n");

    /* ===== 1. Initialisation ===== */
    Student_Management manager;
    initManagement(&manager, 2);

    printf("Gestion initialisée (capacité = %d)\n\n", manager.capacity);

    /* ===== 2. Création manuelle d’étudiants ===== */
    Student s1 = {1, "Dupont", "Jean", {12, 5, 2000}};
    Student s2 = {2, "Martin", "Alice", {3, 10, 1999}};
    Student s3 = {3, "Ngoma", "Paul", {25, 8, 2001}};

    /* ===== 3. Ajout ===== */
    addStudent(&manager, s1);
    addStudent(&manager, s2);
    addStudent(&manager, s3);  // force resize

    printf("Étudiants ajoutés.\n\n");

    /* ===== 4. Affichage global ===== */
    printf("=== Liste des étudiants ===\n");
    viewAllStudents(&manager);

    /* ===== 5. Recherche par ID ===== */
    printf("\n=== Recherche ID = 2 ===\n");
    selectStudent(&manager, 2);

    printf("\n=== Recherche ID = 10 (inexistant) ===\n");
    selectStudent(&manager, 10);

    /* ===== 6. Modification ===== */
    printf("\n=== Modification étudiant ID = 1 ===\n");
    modifyStudent(&manager, 1);
    selectStudent(&manager, 1);

    /* ===== 7. Suppression ===== */
    printf("\n=== Suppression étudiant ID = 2 ===\n");
    deleteStudentById(&manager, 2);
    viewAllStudents(&manager);

    /* ===== 8. Suppression totale ===== */
    printf("\n=== Suppression de tous les étudiants ===\n");
    deleteAllStudents(&manager);
    viewAllStudents(&manager);

    /* ===== 9. Libération mémoire ===== */
    freeManagement(&manager);
    printf("\nMémoire libérée. Fin des tests.\n");

    return 0;
}
