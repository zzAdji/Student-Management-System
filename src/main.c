#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu.h"

int main() {
    // Définit la page de code de la console sur UTF-8 
    system("chcp 65001 > nul");

    displayHeader("STUDENT MANAGEMENT SYSTEM (SMS)");

    // Message de bienvenue

    // Stats de notre bd

    // Appel à l'action

    displaySimpleFooter();
    displayMenu();
    
    return 0;
}