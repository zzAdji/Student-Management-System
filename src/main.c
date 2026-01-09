#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu.h"
#include "../include/utils.h"
#include "../include/data.h"

int main() {
    clearScreen();
    system("chcp 65001 > nul");

    // TODO : Initialisation après le load ???
    Student_Management management;
    initManagement(&management, 10);

    if (loadData(&management) == 0) {
        displayStart(&management);
        saveData(&management);
    }

    displayHeader("STUDENT MANAGEMENT SYSTEM (SMS)");
    displayInfo("Bienvenue dans votre système de gestion des étudiants !");
    displayStats(&management);
    displaySimpleFooter();
    displayMenu(&management);

    saveData(&management);
    freeManagement(&management);

    system("chcp 437 > nul");

    return 0;
}