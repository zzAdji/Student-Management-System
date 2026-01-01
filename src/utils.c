#include <stdio.h>
#include <time.h>
#include "utils.h"

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pauseConsole() {
    printf("\nAppuyez sur Entrée pour continuer...");
    getchar();
}

int calculateAge(int day, int month, int year) {
    time_t t = time(NULL);
    struct tm *now = localtime(&t);

    int age = (now->tm_year + 1900) - year;

    if (month > (now->tm_mon + 1) ||
       (month == (now->tm_mon + 1) && day > now->tm_mday)) {
        age--;
    }
    return age;
}
