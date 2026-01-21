#ifndef MENU_H
#define MENU_H

#include "student.h"
#include "search.h"

void displayStart(Student_Management *managment);

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
 * @param management Pointeur vers la structure de gestion des étudiants
 * @param index Index de l'étudiant
 */
void displayCalculateAgeMenu(Student_Management *management, int index);

/**
 * Affiche le menu de tri de la liste des étudiants.
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void displaySortMenu(Student_Management *management);

/**
 * Traite le choix de tri de l'utilisateur.
 * @param choice Le choix effectué par l'utilisateur.
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void processSortChoice(int choice, Student_Management *management);

/**
 * Affiche le menu de recherche dichotomique.
 * @param management Pointeur vers la structure de gestion des étudiants
 * @return Index de l'étudiant trouvé ou -1 si non trouvé
 */
int displayBinarySearchMenu(Student_Management *management);

/**
 * Affiche le dialogue de confirmation de sortie.
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void displayExitConfirmationMenu(Student_Management *management);

/**
 * Traite le choix de l'utilisateur depuis le menu des paramètres.
 * @param choice Le choix effectué par l'utilisateur.
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void processSettingsChoice(int choice, Student_Management *management);

/**
 * Affiche les statistiques détaillées (distribution genre, département, âge moyen).
 * @param management Pointeur vers la structure de gestion des étudiants
 */
void displayDetailedStats(Student_Management *management);

/**
 * Affiche la liste des résultats de recherche et permet la sélection.
 * @param management Pointeur vers la structure de gestion des étudiants
 * @param results Pointeur vers les résultats de recherche
 * @return Index de l'étudiant sélectionné ou -1 si annulé
 */
int displaySearchResultsList(Student_Management *management, SearchResults *results);

#endif