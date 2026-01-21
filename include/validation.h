#ifndef VALIDATION_H
#define VALIDATION_H

#include "utils.h"
#include "../include/student.h"

/**
 * Valider le format du matricule
 */
int validateId(const char *id);

/**
 * Valider une date DD/MM/YYYY
 */
int validateDate(const char *date);

/**
 * Valider le sexe (chaine de caractères)
 */
int validateGender(const char *genderStr);

/**
 * Valider une chaîne non vide
 */
int validateString(const char *str);

/**
 * Saisie sécurisée avec validation
 */
void inputValidString(char *dest, size_t size, const char *prompt, int (*validate)(const char *), char *error_message);

/**
 * Saisie d'une date valide
 */
void inputValidDate(char *dest, const char *prompt);

/**
 * Vérifier année bissextile
 */
int isLeapYear(int year);

#endif
