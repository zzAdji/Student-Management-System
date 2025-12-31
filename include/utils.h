#ifndef UTILS_H
#define UTILS_H

/**
 * Efface l'écran du terminal.
 * Utilise "cls" sous Windows et "clear" sous Linux/macOS.
 */
void clearScreen();

/**
 * Récupère la largeur visible réelle d'une chaîne (sans codes ANSI).
 * @param str La chaîne de caractères.
 * @return La longueur visible.
 */
int getVisibleLength(const char* str);

/**
 * Récupère la largeur actuelle du terminal.
 * @return La largeur en colonnes.
 */
int getTerminalWidth();

/**
 * Affiche un nombre donné d'espaces.
 * @param count Nombre d'espaces à afficher.
 */
void printSpaces(int count);

/**
 * Affiche un en-tête stylisé avec un titre centré et des couleurs paramétrables.
 * @param title Le titre à afficher.
 * @param borderColor Code couleur ANSI pour la bordure.
 * @param titleColor Code couleur ANSI pour le titre.
 */
void displayHeaderStyled(char *title, const char *borderColor, const char *titleColor);

/**
 * Affiche un en-tête standard (Cyan).
 * @param title Le titre à afficher.
 */
void displayHeader(char *title);

/**
 * Affiche un message de succès.
 * @param subtitle Sous-titre.
 * @param message Message détaillé.
 */
void displaySuccess(char *subtitle, char *message);

/**
 * Affiche un message d'erreur.
 * @param subtitle Sous-titre (ex: type d'erreur).
 * @param message Message détaillé.
 */
void displayError(char *subtitle, char *message);

/**
 * Affiche un message d'avertissement.
 * @param subtitle Sous-titre.
 * @param message Message détaillé.
 */
void displayWarning(char *subtitle, char *message);

/**
 * Affiche un message d'information.
 * @param info Le message d'information.
 */
void displayInfo(char *info);

/**
 * Affiche un pied de page demandant d'appuyer sur Entrée pour continuer.
 */
void displaySimpleFooter();

/**
 * Affiche un pied de page demandant de faire un choix.
 */
void displayChoiceFooter();

#endif
