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
 * Affiche un en-tête stylisé avec un titre.
 * Ajuste automatiquement l'alignement selon la longueur du titre et les emojis.
 * @param title Le titre à afficher dans l'en-tête.
 */
void displayHeader(char *title);

/**
 * Affiche un message de succès avec un en-tête formaté.
 * @param subtitle Le sous-titre de l'en-tête (ex: nom de l'opération).
 * @param message Le message de succès détaillé.
 */
void displaySuccess(char *subtitle, char *message);

/**
 * Affiche un message d'erreur avec un en-tête formaté.
 * @param subtitle Le sous-titre de l'en-tête (ex: type d'erreur).
 * @param message Le message d'erreur détaillé.
 */
void displayError(char *subtitle, char *message);

/**
 * Affiche un message d'information avec un en-tête formaté.
 * @param subtitle Le sous-titre de l'en-tête (ex: sujet de l'info).
 * @param message Le message d'information détaillé.
 */
void displayInfo(char *subtitle, char *message);

/**
 * Affiche un message d'avertissement avec un en-tête formaté.
 * @param subtitle Le sous-titre de l'en-tête (ex: sujet de l'alerte).
 * @param message Le message d'avertissement détaillé.
 */
void displayWarning(char *subtitle, char *message);


/**
 * Affiche le pied de page demandant le choix de l'utilisateur.
 */
void displayChoiceFooter();

/**
 * Affiche un pied de page simple demandant d'appuyer sur Entrée.
 */
void displaySimpleFooter();

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