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
 * Affiche un texte centré.
 * @param text Le texte à centrer.
 */
void printCenterText(char *text);

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

/**
 * Affiche un chemin de navigation.
 * @param path Le chemin à afficher.
 */
void displayPath(char *path);

/**
 * Calculer l'âge à partir de la date de naissance
 */
int calculateAge(Date birth_date);

/**
 * Obtenir la date actuelle (DD/MM/YYYY)
 */
void getCurrentDate(char *buffer);

/**
 * Nettoyer le buffer d'entrée
 */
void clearBuffer(void);

/**
 * Pause système multiplateforme
 */
void systemPause(void);

/**
 * Convertir une chaîne en majuscules
 */
void stringToUpper(char *str);

/**
 * Convertir une chaîne en minuscules
 */
void stringToLower(char *str);

/**
 * Générer un matricule automatique
 */
void generateId(char *id, int number);

/**
 * Copier une chaîne de manière sécurisée
 */
void safeCopy(char *dest, const char *src, int size);

#endif
