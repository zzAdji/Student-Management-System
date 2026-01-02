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
 * @brief Modifie un champ spécifique d'un étudiant à un index donné
 * @param mng Pointeur vers la structure de gestion des étudiants
 * @param index Index de l'étudiant à modifier dans mng->list
 */
void modifyStudent(Student_Management *mng, int index);

/**
 * Supprimer un étudiant
 * Décale les éléments pour combler le vide
 * @param management Pointeur vers la structure de gestion
 * @param index Index de l'étudiant à supprimer
 * @return 1 si supprimé, 0 sinon
 */
int deleteStudent(Student_Management *management, int index);

/**
 * @brief Supprime tous les étudiants de la base
 * @param management Pointeur vers la structure de gestion
 * @return Nombre d'étudiants supprimés
 */
int deleteAllStudents(Student_Management *management);

/**
 * Obtenir les informations d'un étudiant
 * Affiche toutes les informations détaillées
 * @param management Pointeur vers la structure de gestion
 * @param index Index de l'étudiant
 * @return 1 si trouvé, 0 sinon
 */
int getStudentInfo(Student_Management *management, int index);

#endif
