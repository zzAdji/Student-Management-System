#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "../include/utils.h"
#include "../include/config.h"
#include "../include/student.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Récupère la largeur visible réelle d'une chaîne (sans ANSI, traitant UTF-8)
int getVisibleLength(const char* str) {
    int len = 0;
    int i = 0;
    int inAnsi = 0;
    
    while (str[i] != '\0') {
        if (str[i] == '\033') {
            inAnsi = 1;
        } else if (inAnsi && str[i] == 'm') {
            inAnsi = 0;
        } else if (!inAnsi) {
            unsigned char c = (unsigned char)str[i];
            // Si c'est un octet de début UTF-8 ou ASCII
            if ((c & 0xC0) != 0x80) { 
               len++;
            }
        }
        i++;
    }
    return len;
}

int getTerminalWidth() {
    #ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    #else
        struct winsize w;
        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
            return 80; // Fallback par défaut
        }
        return w.ws_col;
    #endif
}

// Affiche x espaces
void printSpaces(int count) {
    for (int i = 0; i < count; i++) printf(" ");
}

void printCenterText(char *text) {
    int termWidth = getTerminalWidth();
    int margin = (termWidth - getVisibleLength(text)) / 2;
    if (margin < 0) margin = 0;

    printSpaces(margin); printf("%s\n", text);
}

// Affiche un en-tête centré avec un cadre
void displayHeaderStyled(char *title, const char *borderColor, const char *titleColor) {
    int titleVisLen = getVisibleLength(title);
    
    // Largeur minimale du cadre intérieur
    int minInnerWidth = 53;
    int innerWidth = (titleVisLen > minInnerWidth) ? (titleVisLen + 4) : minInnerWidth;
    
    // Calcul du centrage horizontal du bloc complet
    int termWidth = getTerminalWidth();
    int boxWidth = innerWidth + 2; // +2 pour les bordures verticales
    int leftMargin = (termWidth - boxWidth) / 2;
    if (leftMargin < 0) leftMargin = 0;

    // Calcul du padding interne pour centrer le titre DANS le cadre
    int totalPadding = innerWidth - titleVisLen;
    int leftPadding = totalPadding / 2;
    int rightPadding = totalPadding - leftPadding;

    // Ligne supérieure
    printf("\n");
    printSpaces(leftMargin);
    printf("%s╔", borderColor);
    for (int i = 0; i < innerWidth; i++) printf("═");
    printf("╗%s\n", COLOR_RESET);

    // Ligne centrale avec titre
    printSpaces(leftMargin);
    printf("%s║%s%*s%s%s%s%*s%s║%s\n", 
            borderColor, 
            COLOR_RESET, 
            leftPadding, "", 
            titleColor, title, COLOR_RESET, 
            rightPadding, "", 
            borderColor, 
            COLOR_RESET);

    // Ligne inférieure
    printSpaces(leftMargin);
    printf("%s╚", borderColor);
    for (int i = 0; i < innerWidth; i++) printf("═");
    printf("╝\n\n%s", COLOR_RESET);
}

void displayHeader(char *title) {
    displayHeaderStyled(title, COLOR_CYAN, COLOR_BOLD_CYAN);
}

// Affiche un message de succès
void displaySuccess(char *subtitle, char *message) {
    char title[256];
    snprintf(title, sizeof(title), "\u2705 %s", subtitle);
    displayHeaderStyled(title, COLOR_GREEN, COLOR_BOLD_GREEN);
    
    int termWidth = getTerminalWidth();
    int msgLen = getVisibleLength(message);
    int msgMargin = (termWidth - msgLen) / 2;
    if (msgMargin < 0) msgMargin = 0;
    
    printSpaces(msgMargin);
    printf(COLOR_GREEN "%s" COLOR_RESET "\n", message);
}

// Affiche un message d'erreur
void displayError(char *subtitle, char *message) {
    char title[256];
    snprintf(title, sizeof(title), "\u274C %s", subtitle);
    displayHeaderStyled(title, COLOR_RED, COLOR_BOLD_RED);

    int termWidth = getTerminalWidth();
    int msgLen = getVisibleLength(message);
    int msgMargin = (termWidth - msgLen) / 2;
    if (msgMargin < 0) msgMargin = 0;

    printSpaces(msgMargin);
    printf(COLOR_RED "%s" COLOR_RESET "\n", message);
}

// Affiche un message d'information
void displayInfo(char *info) {
    int termWidth = getTerminalWidth();
    int infoLen = getVisibleLength(info) + 4;
    int margin = (termWidth - infoLen) / 2;
    if (margin < 0) margin = 0;
    
    printSpaces(margin);
    printf("\u2139\uFE0F  %s\n", info);

    int sepWidth = 52; 
    int sepMargin = (termWidth - sepWidth) / 2;
    if (sepMargin < 0) sepMargin = 0;
    
    printf(COLOR_CYAN "\n");
    printSpaces(sepMargin);
    printf("────────────────────────────────────────────────────\n\n" COLOR_RESET);
}

// Affiche un message d'avertissement
void displayWarning(char *subtitle, char *message) {
    char title[256];
    snprintf(title, sizeof(title), "\u26A0\uFE0F  %s", subtitle);
    displayHeaderStyled(title, COLOR_YELLOW, COLOR_BOLD_YELLOW);
    
    int termWidth = getTerminalWidth();
    int msgLen = getVisibleLength(message);
    int msgMargin = (termWidth - msgLen) / 2;
    if (msgMargin < 0) msgMargin = 0;

    printSpaces(msgMargin);
    printf(COLOR_YELLOW "%s" COLOR_RESET "\n", message);
}

// Affiche un pied de page demandant d'appuyer sur Entrée
void displaySimpleFooter(){
    int termWidth = getTerminalWidth();
    int sepWidth = 52;
    int sepMargin = (termWidth - sepWidth) / 2;
    if (sepMargin < 0) sepMargin = 0;

    printf("\n");
    printf(COLOR_CYAN);
    printSpaces(sepMargin);
    printf("────────────────────────────────────────────────────" COLOR_RESET "\n");
    
    printf("\n");
    char *msg = "Appuyez sur Entrée pour continuer...";
    int msgMargin = (termWidth - getVisibleLength(msg)) / 2;
    if (msgMargin < 0) msgMargin = 0;
    
    printSpaces(msgMargin);
    printf("%s", msg);
    getchar();
    printf("\n");
}

// Affiche l'invite pour le choix de l'utilisateur
void displayChoiceFooter() {
    int termWidth = getTerminalWidth();
    int sepWidth = 52;
    int sepMargin = (termWidth - sepWidth) / 2;
    if (sepMargin < 0) sepMargin = 0;

    printf("\n");
    printf(COLOR_CYAN);
    printSpaces(sepMargin);
    printf("────────────────────────────────────────────────────" COLOR_RESET "\n");
    printf("\n");
    
    char *msg = "Votre choix: ";
    int msgLen = getVisibleLength(msg);
    int msgMargin = (termWidth - msgLen - 5) / 2; 
    if (msgMargin < 0) msgMargin = 0;
    
    printSpaces(msgMargin);
    printf("%s", msg);
}

void displayPath(char *path) {
    int pathMargin = 10;
    
    printf("\n\n");
    printSpaces(pathMargin);
    printf("%s\n\n", path);
}

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

    sprintf(buffer, "Date actuelle : %02d/%02d/%04d",
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
