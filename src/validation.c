#include "../include/validation.h"
#include "../include/utils.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// TODO : Adapter la fonction pour valider les matricules de type XXENSPM0XXX et tout autre matricule de l'UMA. 
int validateId(const char *id) {
    if (!id || strlen(id) < 5) return 0;

    /*for (int i = 0; id[i]; i++) {
        if (!isalnum((unsigned char)id[i]))
            return 0;
    }*/
    return 1;
}

// TODO : Adapter la fonction pour valider les dates au format JJ/MM/AAAA et JJ-MM-AAAA en plus de JJ MM AAAA
int validateDate(const char *date) {
    int d, m, y;
    if (sscanf(date, "%d/%d/%d", &d, &m, &y) != 3) {
        if (sscanf(date, "%d %d %d", &d, &m, &y) != 3) {
             if (sscanf(date, "%d-%d-%d", &d, &m, &y) != 3) return 0;
        }
    }

    if (y < 1900 || m < 1 || m > 12 || d < 1)
        return 0;

    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeapYear(y))
        daysInMonth[1] = 29;

    return d <= daysInMonth[m - 1];
}

int validateGender(const char *genderStr) {
    if (!genderStr || strlen(genderStr) != 1) return 0;
    char gender = (char)toupper(genderStr[0]);
    return gender == 'M' || gender == 'F';
}

int validateString(const char *str) {
    if (!str) return 0;

    for (int i = 0; str[i]; i++) {
        if (!isspace((unsigned char)str[i]))
            return 1;
    }
    return 0;
}

void inputValidString(char *dest, size_t size, const char *prompt, int (*validate)(const char *), char *error_message) {
    int valid = 0;
    int termWidth = getTerminalWidth();
    int margin = (termWidth - 50) / 2;
    if (margin < 0) margin = 0;

    do {
        printSpaces(margin);
        printf("%s", prompt);
        if (fgets(dest, size, stdin) == NULL) {
            continue;
        }
        dest[strcspn(dest, "\n")] = '\0';
        
        valid = validate(dest);
        if (!valid) {
            displayError("Erreur de format", error_message);
            printf("\n");
        }
    } while (!valid);

    stringToUpper(dest);
}

void inputValidDate(char *dest, const char *prompt) {
    int termWidth = getTerminalWidth();
    int margin = (termWidth - 50) / 2;
    if (margin < 0) margin = 0;
    int valid = 0;

    do {
        printSpaces(margin);
        printf("%s", prompt);
        fgets(dest, 20, stdin);
        dest[strcspn(dest, "\n")] = '\0';
        
        valid = validateDate(dest);
        if (!valid) {
            displayError("Erreur de date", "Format invalide (JJ/MM/AAAA) ou date inexistante.");
            printf("\n");

        }
    } while (!valid);
}

// TODO : Implémenter la vérification de l'existance d'un matricule
int idExists(Student_Management *management, const char *id) {
    (void)management;
    (void)id;
    return 0;
}
