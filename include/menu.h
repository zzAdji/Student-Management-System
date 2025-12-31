#ifndef MENU_H
#define MENU_H

/**
 * Affiche le menu principal de l'application.
 */
void displayMenu();

/**
 * Affiche le menu de modification des informations d'un étudiant.
 */
void displayModifyStudentMenu();

/**
 * Affiche le menu de sélection des actions sur la liste des étudiants.
 */
void displayOnListMenu();

/**
 * Affiche le menu des paramètres.
 */
void displaySettings();

/**
 * Récupère le choix de l'utilisateur sur l'entrée standard.
 * Gère les entrées invalides en vidant le tampon.
 * @return Le choix de l'utilisateur (entier), ou -1 en cas d'erreur.
 */
int getUserChoice();

/**
 * Traite le choix de l'utilisateur depuis le menu principal.
 * @param choice Le choix effectué par l'utilisateur.
 */
void processChoice(int choice);

/**
 * Traite le choix de l'utilisateur depuis le menu de modification.
 * @param choice Le choix effectué par l'utilisateur.
 */
void processModifyStudentChoice(int choice);

/**
 * Traite le choix de l'utilisateur depuis le menu de sélection des actions sur la liste des étudiants.
 * @param choice Le choix effectué par l'utilisateur.
 */
void processOnListChoice(int choice);

/**
 * Traite le choix de l'utilisateur depuis le menu de suppression.
 * @param choice Le choix effectué par l'utilisateur.
 */
void processDeleteChoice(int choice);

/**
 * Traite le choix de l'utilisateur depuis le menu de confirmation de sortie.
 * @param choice Le choix effectué par l'utilisateur.
 */
void processExitChoice(int choice);

/**
 * Affiche le menu de recherche d'un étudiant par ID/Matricule.
 */
void displaySearchStudentMenu();

/**
 * Affiche les informations détaillées d'un étudiant trouvé.
 */
void displayStudentFound();

/**
 * Affiche le formulaire d'inscription d'un nouvel étudiant.
 */
void displayRegisterStudentForm();

/**
 * Affiche le menu de suppression d'un étudiant.
 */
void displayDeleteStudentMenu();

/**
 * Affiche la liste de tous les étudiants sous forme de tableau.
 */
void displayStudentList();

/**
 * Affiche le menu de calcul de l'âge d'un étudiant.
 */
void displayCalculateAgeMenu();

#endif