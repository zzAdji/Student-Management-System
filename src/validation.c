#include "../include/validation.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int validateId(const char *id) {
    if (!id || strlen(id) < 5) return 0;

    for (int i = 0; id[i]; i++) {
        if (!isalnum((unsigned char)id[i]))
            return 0;
    }
    return 1;
}

int validateDate(const char *date) {
    int d, m, y;
    if (sscanf(date, "%d/%d/%d", &d, &m, &y) != 3)
        return 0;

    if (y < 1900 || m < 1 || m > 12 || d < 1)
        return 0;

    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeapYear(y))
        daysInMonth[1] = 29;

    return d <= daysInMonth[m - 1];
}

int validateGender(char gender) {
    gender = (char)toupper(gender);
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

void inputValidString(char *dest, int size, const char *prompt) {
    do {
        printf("%s", prompt);
        fgets(dest, size, stdin);
        dest[strcspn(dest, "\n")] = '\0';
    } while (!validateString(dest));
}

void inputValidDate(char *dest, const char *prompt) {
    do {
        printf("%s", prompt);
        fgets(dest, 20, stdin);
        dest[strcspn(dest, "\n")] = '\0';
    } while (!validateDate(dest));
}

/* Cette fonction sera pleinement fonctionnelle quand Student_Management sera connu */
int idExists(struct Student_Management *management, const char *id) {
    (void)management;
    (void)id;
    return 0; // placeholder volontaire
}
