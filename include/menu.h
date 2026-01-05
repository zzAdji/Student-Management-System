#ifndef MENU_H
#define MENU_H

#include "student.h"

/**
 * Affiche le menu principal de l'application.
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void displayMenu(Student_Management *management);

/**
 * Affiche le menu de modification des informations d'un étudiant.
 * @param management Pointeur vers la structure de gestion des étudiants
 * @param index Index de l'étudiant à modifier
 */
void displayModifyStudentMenu(Student_Management *management, int index);

/**
 * Affiche le menu de sélection des actions sur la liste des étudiants.
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void displayOnListMenu(Student_Management *management);

/**
 * Affiche le menu des paramètres.
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void displaySettings(Student_Management *management);

/**
 * Affiche les statistisques de notre bd.
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void displayStats(Student_Management *management);

/**
 * Récupère le choix de l'utilisateur sur l'entrée standard.
 * @return Le choix de l'utilisateur (entier), ou -1 en cas d'erreur.
 */
int getUserChoice();

/**
 * Traite le choix de l'utilisateur depuis le menu principal.
 * @param choice Le choix effectué par l'utilisateur.
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void processChoice(int choice, Student_Management *management);

/**
 * Traite le choix de l'utilisateur depuis le menu de modification.
 * @param choice Le choix effectué par l'utilisateur.
 * @param management Pointeur vers la structure de gestion des étudiants
 * @param index Index de l'étudiant à modifier
 */
void processModifyStudentChoice(int choice, Student_Management *management, int index);

/**
 * Traite le choix de l'utilisateur depuis le menu d'actions sur la liste.
 * @param choice Le choix effectué par l'utilisateur.
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void processOnListChoice(int choice, Student_Management *management);

/**
 * Traite le choix de l'utilisateur depuis le menu de suppression.
 * @param choice Le choix effectué par l'utilisateur.
 * @param management Pointeur vers la structure de gestion des étudiants
 * @param index Index de l'étudiant à supprimer
 */
void processDeleteChoice(int choice, Student_Management *management, int index);

/**
 * Traite le choix de l'utilisateur depuis le menu de confirmation de sortie.
 * @param choice Le choix effectué par l'utilisateur.
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void processExitChoice(int choice, Student_Management *management);

/**
 * Affiche le menu de recherche d'un étudiant par ID/Matricule.
 * TODO: Implémenter la recherche linéaire avec linearSearch()
 * @param management Pointeur vers la structure de gestion des étudiants
 * @return Index de l'étudiant trouvé ou -1 si non trouvé
 */
int displaySearchStudentMenu(Student_Management *management);

/**
 * Affiche les informations détaillées d'un étudiant trouvé.
 * @param management Pointeur vers la structure de gestion des étudiants
 * @param index Index de l'étudiant à afficher
 */
void displayStudentFound(Student_Management *management, int index);

/**
 * Affiche le formulaire d'inscription d'un nouvel étudiant.
 * TODO: Implémenter les validations des champs
 * @param management Pointeur vers la structure de gestion des étudiants
 * @return 1 si l'étudiant a été ajouté avec succès, 0 sinon
 */
int displayRegisterStudentForm(Student_Management *management);

/**
 * Affiche le menu de suppression d'un étudiant.
 * @param management Pointeur vers la structure de gestion des étudiants
 * @param index Index de l'étudiant à supprimer
 */
void displayDeleteStudentMenu(Student_Management *management, int index);

/**
 * Affiche la liste de tous les étudiants sous forme de tableau.
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void displayStudentList(Student_Management *management);

/**
 * Affiche le menu de calcul de l'âge d'un étudiant.
 * TODO: Implémenter calculateAge() pour le calcul réel
 * @param management Pointeur vers la structure de gestion des étudiants
 * @param index Index de l'étudiant
 */
void displayCalculateAgeMenu(Student_Management *management, int index);

/**
 * Affiche le menu de tri de la liste des étudiants.
 * TODO: Implémenter les fonctions de tri avec qsort()
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void displaySortMenu(Student_Management *management);

/**
 * Traite le choix de tri de l'utilisateur.
 * TODO: Implémenter les tris par nom, option et matricule
 * @param choice Le choix effectué par l'utilisateur.
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void processSortChoice(int choice, Student_Management *management);

/**
 * Affiche le menu de recherche dichotomique.
 * TODO: Implémenter binarySearch() après tri par matricule
 * @param management Pointeur vers la structure de gestion des étudiants
 * @return Index de l'étudiant trouvé ou -1 si non trouvé
 */
int displayBinarySearchMenu(Student_Management *management);

/**
 * Affiche le dialogue de confirmation de sortie.
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void displayExitConfirmationMenu(Student_Management *management);

#endif