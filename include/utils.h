#ifndef UTILS_H
#define UTILS_H
#include <time.h>
#include "student.h"
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
 * Effacer l'écran multiplateforme
 */
void clearScreen(void);

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
