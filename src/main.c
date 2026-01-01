#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu.h"
#include "../include/utils.h"

int main() {
    // Définit la page de code de la console sur UTF-8
    system("chcp 65001 > nul");

    // Initialisation de la gestion des étudiants
    Student_Management management;
    initManagement(&management, 10);

    displayHeader("STUDENT MANAGEMENT SYSTEM (SMS)");

    // Message de bienvenue
    displayInfo("Bienvenue dans le système de gestion des étudiants !");

    // Stats de notre bd
    //printf("Capacité actuelle : %d/%d étudiants", management.number, management.capacity);

    // Appel à l'action
    displaySimpleFooter();
    displayMenu(&management);

    // Libération de la gestion des étudiants
    freeManagement(&management);

    // Réinitialise la page de code de la console sur la page par défaut
    system("chcp 437 > nul");

    return 0;
}