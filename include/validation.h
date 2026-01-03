#ifndef VALIDATION_H
#define VALIDATION_H

#include "utils.h"
struct Student_Management;

/**
 * Valider le format du matricule
 */
int validateId(const char *id);

/**
 * Valider une date DD/MM/YYYY
 */
int validateDate(const char *date);

/**
 * Valider le sexe
 */
int validateGender(char gender);

/**
 * Valider une chaîne non vide
 */
int validateString(const char *str);

/**
 * Saisie sécurisée avec validation
 */
void inputValidString(char *dest, int size, const char *prompt);

/**
 * Saisie d'une date valide
 */
void inputValidDate(char *dest, const char *prompt);

/**
 * Vérifier si un matricule existe déjà
 */
int idExists(struct Student_Management *management, const char *id);

/**
 * Vérifier année bissextile
 */
int isLeapYear(int year);

#endif
