#include "../include/utils.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int calculateAge(Date birth_date) {
    time_t t = time(NULL);
    struct tm *today = localtime(&t);

    int age = (today->tm_year + 1900) - birth_date.year;

    if ((today->tm_mon + 1) < birth_date.month ||
        ((today->tm_mon + 1) == birth_date.month && today->tm_mday < birth_date.day)) {
        age--;
    }

    return age;
}

void getCurrentDate(char *buffer) {
    time_t t = time(NULL);
    struct tm *today = localtime(&t);

    sprintf(buffer, "%02d/%02d/%04d",
            today->tm_mday,
            today->tm_mon + 1,
            today->tm_year + 1900);
}

void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void systemPause(void) {
#ifdef _WIN32
    system("pause");
#else
    printf("Appuyez sur Entrée pour continuer...");
    getchar();
#endif
}

void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void stringToUpper(char *str) {
    for (; *str; str++)
        *str = (char)toupper(*str);
}

void stringToLower(char *str) {
    for (; *str; str++)
        *str = (char)tolower(*str);
}

void generateId(char *id, int number) {
    time_t t = time(NULL);
    struct tm *today = localtime(&t);

    sprintf(id, "STU%d%03d", today->tm_year + 1900, number);
}

void safeCopy(char *dest, const char *src, int size) {
    if (size <= 0) return;
    strncpy(dest, src, size - 1);
    dest[size - 1] = '\0';
}
