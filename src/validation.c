#include <string.h>
#include <ctype.h>
#include "validation.h"

int isValidName(const char *name) {
    if (strlen(name) < 2) return 0;

    for (int i = 0; name[i]; i++) {
        if (!isalpha(name[i]) && name[i] != ' ')
            return 0;
    }
    return 1;
}

int isValidDate(int day, int month, int year) {
    if (year < 1900 || year > 2100) return 0;
    if (month < 1 || month > 12) return 0;
    if (day < 1 || day > 31) return 0;

    return 1;
}

int isValidMatricule(const char *matricule) {
    if (strlen(matricule) < 4) return 0;

    for (int i = 0; matricule[i]; i++) {
        if (!isalnum(matricule[i]))
            return 0;
    }
    return 1;
}
