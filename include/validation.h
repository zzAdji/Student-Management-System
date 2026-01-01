#ifndef VALIDATION_H
#define VALIDATION_H

/* Validation du nom (lettres et espaces) */
int isValidName(const char *name);

/* Validation de la date */
int isValidDate(int day, int month, int year);

/* Validation du matricule */
int isValidMatricule(const char *matricule);

#endif
