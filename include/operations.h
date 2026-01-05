#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "student.h"
#include "../include/utils.h"
#include "../include/validation.h"

/**
 * Ajouter un nouvel étudiant
 * Redimensionne automatiquement si nécessaire
 * @param management Pointeur vers la structure de gestion
 * @param student Étudiant à ajouter
 * @return 1 si succès, 0 sinon
 */
int addStudent(Student_Management *management, Student student);

/**
 * Obtenir un étudiant par son index
 * @param management Pointeur vers la structure de gestion
 * @param index Index de l'étudiant dans la liste
 * @return Pointeur vers l'étudiant ou NULL si invalide
 */
Student* getStudentByIndex(Student_Management *management, int index);

/**
 * Rechercher un étudiant par matricule
 * @param management Pointeur vers la structure de gestion
 * @param id Matricule recherché
 * @return Index de l'étudiant trouvé ou -1 si non trouvé
 */
int findStudentById(Student_Management *management, const char *id);

/**
 * Modifie un champ spécifique d'un étudiant à un index donné
 * @param management Pointeur vers la structure de gestion des étudiants
 * @param index Index de l'étudiant à modifier dans management->list
 * @param field Champ à modifier (1=id, 2=nom, 3=prénom, 4=date, 5=genre, 6=département, 7=option, 8=région)
 * @param value Nouvelle valeur du champ (pour date: format "JJ MM AAAA")
 * @return 1 si modification réussie, 0 sinon
 */
int modifyStudent(Student_Management *management, int index, int field, const char *value);

/**
 * Supprimer un étudiant
 * Décale les éléments pour combler le vide
 * @param management Pointeur vers la structure de gestion
 * @param index Index de l'étudiant à supprimer
 * @return 1 si supprimé, 0 sinon
 */
int deleteStudent(Student_Management *management, int index);

/**
 * Supprime tous les étudiants de la base
 * @param management Pointeur vers la structure de gestion
 * @return Nombre d'étudiants supprimés
 */
int deleteAllStudents(Student_Management *management);

#endif
