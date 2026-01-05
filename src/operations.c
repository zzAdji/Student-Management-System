#include <string.h>
#include <stdlib.h>
#include "../include/operations.h"
#include <string.h>

/* ===== CREATE ===== */
/**
 * Ajouter un nouvel étudiant
 * Redimensionne automatiquement si nécessaire
 * @param management Pointeur vers la structure de gestion
 * @param student Étudiant à ajouter
 * @return 1 si succès, 0 sinon
 */
int addStudent(Student_Management *management, Student student) {
    if (management == NULL) {
        return 0;
    }

    if (management->number >= management->capacity) {
        if (resizeManagement(management) == 0) {
            return 0;
        }
    }

    management->list[management->number] = student;
    management->number++;

    return 1;
}

/* ===== READ ===== */
/**
 * Obtenir un étudiant par son index
 * @param management Pointeur vers la structure de gestion
 * @param index Index de l'étudiant dans la liste
 * @return Pointeur vers l'étudiant ou NULL si invalide
 */
Student* getStudentByIndex(Student_Management *management, int index) {
    if (management == NULL || management->list == NULL) {
        return NULL;
    }
    
    if (index < 0 || index >= management->number) {
        return NULL;
    }
    
    return &management->list[index];
}

/**
 * Rechercher un étudiant par matricule
 * @param management Pointeur vers la structure de gestion
 * @param id Matricule recherché
 * @return Index de l'étudiant trouvé ou -1 si non trouvé
 */
int findStudentById(Student_Management *management, const char *id) {
    if (management == NULL || management->list == NULL || id == NULL) {
        return -1;
    }
    
    if (management->number == 0) {
        return -1;
    }
    
    for (int i = 0; i < management->number; i++) {
        if (strcmp(management->list[i].id, id) == 0) {
            return i;
        }
    }
    
    return -1;
}

/* ===== UPDATE ===== */
/**
 * Modifie un champ spécifique d'un étudiant à un index donné
 * @param management Pointeur vers la structure de gestion des étudiants
 * @param index Index de l'étudiant à modifier dans management->list
 * @param field Champ à modifier (1=id, 2=nom, 3=prénom, 4=date, 5=genre, 6=département, 7=option, 8=région)
 * @param value Nouvelle valeur du champ (pour date: format "JJ MM AAAA")
 * @return 1 si modification réussie, 0 sinon
 */
int modifyStudent(Student_Management *management, int index, int field, const char *value) {
    if (management == NULL || management->list == NULL) {
        return 0;
    }
    
    if (index < 0 || index >= management->number) {
        return 0;
    }
    
    if (value == NULL) {
        return 0;
    }
    
    Student *s = &management->list[index];
    
    switch (field) {
        case 1: // Matricule
            strncpy(s->id, value, sizeof(s->id) - 1);
            s->id[sizeof(s->id) - 1] = '\0';
            break;
            
        case 2: // Nom
            strncpy(s->name, value, sizeof(s->name) - 1);
            s->name[sizeof(s->name) - 1] = '\0';
            break;
            
        case 3: // Prénom
            strncpy(s->surname, value, sizeof(s->surname) - 1);
            s->surname[sizeof(s->surname) - 1] = '\0';
            break;
            
        case 4: // Date de naissance (format "JJ MM AAAA")
            if (sscanf(value, "%d %d %d", &s->birth_date.day, &s->birth_date.month, &s->birth_date.year) != 3) {
                return 0;
            }
            break;
            
        case 5: // Genre
            if (value[0] == 'M' || value[0] == 'm') {
                s->gender = 'M';
            } else if (value[0] == 'F' || value[0] == 'f') {
                s->gender = 'F';
            } else {
                return 0;
            }
            break;
            
        case 6: // Département
            strncpy(s->department, value, sizeof(s->department) - 1);
            s->department[sizeof(s->department) - 1] = '\0';
            break;
            
        case 7: // Option/Filière
            strncpy(s->option, value, sizeof(s->option) - 1);
            s->option[sizeof(s->option) - 1] = '\0';
            break;
            
        case 8: // Région d'origine
            strncpy(s->native_region, value, sizeof(s->native_region) - 1);
            s->native_region[sizeof(s->native_region) - 1] = '\0';
            break;
            
        default:
            return 0;
    }
    
    return 1;
}

/* ===== DELETE ===== */
/**
 * Supprimer un étudiant
 * Décale les éléments pour combler le vide
 * @param management Pointeur vers la structure de gestion
 * @param index Index de l'étudiant à supprimer
 * @return 1 si supprimé, 0 sinon
 */
int deleteStudent(Student_Management *management, int index) {
    if (management == NULL || management->list == NULL) {
        return 0;
    }
    
    if (management->number == 0) {
        return 0;
    }
    
    if (index < 0 || index >= management->number) {
        return 0;
    }
    
    // Décaler tous les étudiants après l'index vers la gauche
    for (int i = index; i < management->number - 1; i++) {
        management->list[i] = management->list[i + 1];
    }
    
    management->number--;
    
    // Optimisation mémoire si nécessaire
    if (management->number > 0 && 
        management->number < management->capacity / 2 && 
        management->capacity > 10) {
        
        int new_capacity = management->capacity / 2;
        Student *new_list = (Student*)realloc(management->list, new_capacity * sizeof(Student));
        
        if (new_list != NULL) {
            management->list = new_list;
            management->capacity = new_capacity;
        }
    }
    
    return 1;
}

/**
 * Supprime tous les étudiants de la base
 * @param management Pointeur vers la structure de gestion
 * @return Nombre d'étudiants supprimés
 */
int deleteAllStudents(Student_Management *management) {
    if (management == NULL || management->list == NULL) {
        return 0;
    }
    
    if (management->number == 0) {
        return 0;
    }
    
    int total_students = management->number;
    
    // Libérer la mémoire de l'ancienne liste
    free(management->list);
    
    // Réinitialiser la structure
    management->number = 0;
    management->capacity = 10;
    
    // Allouer une nouvelle liste vide
    management->list = (Student*)malloc(management->capacity * sizeof(Student));
    
    if (management->list == NULL) {
        management->capacity = 0;
        return total_students;
    }
    
    return total_students;
}
