#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu.h"
#include "../include/colors.h"
#include "../include/utils.h"

void displayMenu() {
    clearScreen();
    displayPath("sms > menu");
    displayHeader("MENU PRINCIPAL");

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    printSpaces(margin); printf("  " COLOR_YELLOW "1." COLOR_RESET " Inscrire un étudiant\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "2." COLOR_RESET " Modifier les informations\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "3." COLOR_RESET " Rechercher (par id)\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "4." COLOR_RESET " Supprimer un étudiant\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "5." COLOR_RESET " Trier la liste\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "6." COLOR_RESET " Recherche dichotomique\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "7." COLOR_RESET " Calculer l'âge de l'étudiant\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "8." COLOR_RESET " Afficher tous les étudiants\n\n");
    printSpaces(margin); printf("  " COLOR_CYAN "9." COLOR_RESET " Paramètres\n");
    printSpaces(margin); printf("  " COLOR_RED    "0. \U0001F6AA Quitter" COLOR_RESET "\n");

    displayChoiceFooter();
    processChoice(getUserChoice());
}

// Affiche le menu pour modifier les informations d'un étudiant
void displayModifyStudentMenu(){
    clearScreen();
    displayPath("sms > menu > modification");
    displayHeader("MODIFIER INFORMATION ETUDIANT");

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    // TODO: En attente de la fonction de récupération d'un étudiant par matricule
    displayInfo("Étudiant actuel : [23ENSPM0443] - [Dupont] [Jean]");

    printSpaces(margin); printf("Quel champ souhaitez-vous modifier ?\n\n");

    printSpaces(margin); printf("  " COLOR_YELLOW "1." COLOR_RESET " Matricule\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "2." COLOR_RESET " Nom\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "3." COLOR_RESET " Prénom\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "4." COLOR_RESET " Date de naissance\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "5." COLOR_RESET " Genre\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "6." COLOR_RESET " Département\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "7." COLOR_RESET " Option\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "8." COLOR_RESET " Région d'origine\n\n");
    printSpaces(margin); printf("  " COLOR_CYAN  "9." COLOR_RESET " Enregistrer et retourner\n");
    printSpaces(margin); printf("  " COLOR_RED    "0. ❌ Annuler" COLOR_RESET "\n");

    displayChoiceFooter();
    processModifyStudentChoice(getUserChoice());
}

// Affiche le formulaire pour inscrire un nouvel étudiant
void displayRegisterStudentForm(){
    clearScreen();
    displayPath("sms > menu > inscription");
    displayHeader("INSCRIRE UN NOUVEL ÉTUDIANT");
    
    int termWidth = getTerminalWidth();
    int margin = (termWidth - 50) / 2;
    if (margin < 0) margin = 0;

    printSpaces(margin + 5); printf("Entrez les informations de l'étudiant :\n\n");
    
    char buffer[100];

    printSpaces(margin); printf("Matricule (ex: 23ENSPM0443)    : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    printSpaces(margin); printf("Nom                            : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    printSpaces(margin); printf("Prénom                         : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    printSpaces(margin); printf("Date de naissance (JJ/MM/AAAA) : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    printSpaces(margin); printf("Genre (M/F)                    : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    printSpaces(margin); printf("Département                    : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    printSpaces(margin); printf("Option                         : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    printSpaces(margin); printf("Région d'origine               : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    // TODO: Appel à la fonction métier registerStudent() ici
    // en attente de l'implémentation du stockage dynamique
    
    displaySimpleFooter();
}

void displayOnListMenu(){
    displayHeader("ACTION SUR LA LISTE");

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    printSpaces(margin); printf("Quel action souhaitez-vous effectuer ?\n\n");

    printSpaces(margin); printf("  " COLOR_YELLOW "1." COLOR_RESET " Sélectionner\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "2." COLOR_RESET " Trier\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "3." COLOR_RESET " Tout supprimer\n\n");
    printSpaces(margin); printf("  " COLOR_CYAN  "4." COLOR_RESET " Enregistrer et retourner\n");
    printSpaces(margin); printf("  " COLOR_RED    "0. ❌ Annuler" COLOR_RESET "\n");

    displayChoiceFooter();
    processOnListChoice(getUserChoice());
}

// Affiche le résultat quand un étudiant est trouvé
void displayStudentFound() {
    clearScreen();
    displayPath("sms > menu > recherche > résultat");
    displaySuccess("ETUDIANT TROUVÉ", "Informations de l'étudiant :");

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    printf("\n");

    // TODO: Remplacer ces données par les champs réels de la structure Student
    printSpaces(margin); printf("  Matricule          : 23ENSPM0443\n");
    printSpaces(margin); printf("  Nom                : Dupont\n");
    printSpaces(margin); printf("  Prénom             : Jean\n");
    printSpaces(margin); printf("  Date de naissance  : 15/06/2000\n");
    printSpaces(margin); printf("  Age                : 24 ans\n");
    printSpaces(margin); printf("  Genre              : M\n");
    printSpaces(margin); printf("  Département        : Génie Informatique\n");
    printSpaces(margin); printf("  Option             : Génie Logiciel\n");
    printSpaces(margin); printf("  Région d'origine   : Centre\n");

    displaySimpleFooter();
}

// Affiche le menu de recherche d'un étudiant
void displaySearchStudentMenu(){
    clearScreen();
    displayPath("sms > menu > recherche");
    displayHeader("RECHERCHE ETUDIANT");
    
    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    printSpaces(margin); printf("Entrer le matricule de l'étudiant :\n");
    printSpaces(margin); printf("___________\r");
    printSpaces(margin); 
    
    char id[50];
    scanf("%49s", id);
    while (getchar() != '\n');
    
    // TODO: Intégrer la fonction linearSearch() ici
    printf("\nRecherche de l'étudiant %s en cours...\n", id);
}

// Affiche le menu de suppression d'un étudiant avec confirmation
void displayDeleteStudentMenu(){
    clearScreen();
    displayPath("sms > menu > suppression");
    displayWarning("SUPPRESSION ETUDIANT", "Êtes-vous sûr de vouloir supprimer cet étudiant?");

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    // TODO: Données à récupérer dynamiquement
    printSpaces(margin); printf("\n");
    printSpaces(margin); printf("  Matricule : [23ENSPM0443]\n");
    printSpaces(margin); printf("  Nom       : [Dupont]\n");
    printSpaces(margin); printf("  Prénom    : [Jean]\n");
    
    printSpaces(margin); printf("\n\n");
    printSpaces(margin); printf("  " COLOR_RED   "1. Oui, supprimer" COLOR_RESET "\n");
    printSpaces(margin); printf("  " COLOR_GREEN "0. ❌ Non, annuler" COLOR_RESET "\n");

    displayChoiceFooter();
    processDeleteChoice(getUserChoice());
}

// Affiche le dialogue de confirmation de sortie
void displayExitConfirmationMenu(){
    clearScreen();    
    displayPath("sms > sortie");
    displayWarning("CONFIRMATION", "Voulez-vous vraiment quitter l'application ?");
    
    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    printf("\n");
    printSpaces(margin); printf("  " COLOR_RED   "1. Oui, quitter" COLOR_RESET "\n");
    printSpaces(margin); printf("  " COLOR_GREEN "0. ❌ Non, retourner au menu" COLOR_RESET "\n");

    displayChoiceFooter();
    processExitChoice(getUserChoice());
}

void displaySettings() {
    clearScreen();    
    displayPath("sms > paramètres");

    displaySimpleFooter();
}

// Affiche la liste de tous les étudiants sous forme de tableau
void displayStudentList() {
    clearScreen();
    displayPath("sms > menu > liste d'étudiants");
    displayHeader("LISTE DES ÉTUDIANTS (15 étudiants)"); // TODO: Afficher le compteur réel count
    displayInfo("Trié par ordre alphabétique");

    int termWidth = getTerminalWidth();
    int tableWidth = 86; // Largeur approximative du tableau
    int margin = (termWidth - tableWidth) / 2;
    if (margin < 0) margin = 0;

    // TODO: Parcourir le tableau dynamique d'étudiants (ViewAllStudents)
    printSpaces(margin); printf("┌─────┬─────────────────┬──────────────┬──────────────┬────────────┬─────────────────┐\n");
    printSpaces(margin); printf("│ No  │       ID        │     Nom      │    Prénom    │ Naissance  │     Option      │\n");
    printSpaces(margin); printf("├─────┼─────────────────┼──────────────┼──────────────┼────────────┼─────────────────┤\n");
    printSpaces(margin); printf("│ 1   │ STU2024001      │ Dupont       │ Jean         │ 15/06/2000 │ Génie Logiciel  │\n");
    printSpaces(margin); printf("│ 2   │ STU2024002      │ Martin       │ Marie        │ 23/09/1999 │ Data Science    │\n");
    printSpaces(margin); printf("│ 3   │ STU2024003      │ Bernard      │ Paul         │ 10/03/2001 │ Réseaux         │\n");
    printSpaces(margin); printf("│ ... │ ...             │ ...          │ ...          │ ...        │ ...             │\n");
    printSpaces(margin); printf("└─────┴─────────────────┴──────────────┴──────────────┴────────────┴─────────────────┘\n");
    printf("\n");

    displayOnListMenu();
}

// Affiche le menu pour calculer l'âge d'un étudiant
void displayCalculateAgeMenu() {
    clearScreen();
    displayPath("sms > menu > âge");
    displayHeader("CALCULER L'ÂGE DE L'ÉTUDIANT");
    
    displayInfo("Date actuelle : 22/12/2024");

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    // TODO: Utiliser la fonction calculateAge() de utils.h
    printSpaces(margin); printf("Étudiant : Jean Dupont\n");
    printSpaces(margin); printf("Matricule : 23ENSPM0443\n");
    printSpaces(margin); printf("Date de naissance : 15/06/2000\n\n");

    printSpaces(margin); printf("Âge : 24 ans, 6 mois, 7 jours\n");

    displaySimpleFooter();
}

// Lit un choix entier de l'utilisateur, vide le tampon en cas d'entrée invalide
int getUserChoice() {
    int choice;    
    int result = scanf("%d", &choice);

    while (getchar() != '\n'); 
    
    if (result != 1) {
        return -1; 
    }
    return choice;
}

void processModifyStudentChoice(int choice) {
    switch (choice) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            // TODO: Appeler modifyStudent() pour appliquer les changements
            displayMenu();
            break;
        case 0:
            displayMenu();
            break;
        default:
            displayError("Choix invalide", "Veuillez entrer un choix valide.");
            displayChoiceFooter();
            processModifyStudentChoice(getUserChoice());
            break;
    }
}

void processOnListChoice(int choice) {
    switch (choice) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            displayMenu();
            break;
        default:
            displayError("Choix invalide", "Veuillez entrer un choix valide.");
            displayChoiceFooter();
            processOnListChoice(getUserChoice());
            break;
    }
}

void processDeleteChoice(int choice){
    switch (choice) {
        case 1:
            // TODO: Appeler deleteStudent() pour supprimer l'étudiant
            break;
        case 0:
            displayMenu();
            break;
        default:
            displayError("Choix invalide", "Veuillez entrer un choix valide.");
            displayChoiceFooter();
            processDeleteChoice(getUserChoice());
            break;
    }
}

void processExitChoice(int choice){
    switch (choice) {
        case 1:
            // TODO: Libérer la mémoire et quitter proprement l'application
            exit(0); 
            break;
        case 0:
            displayMenu();
            break;
        default:
            displayError("Choix invalide", "Veuillez entrer un choix valide.");
            displayChoiceFooter();
            processExitChoice(getUserChoice());
            break;
    }
}

// Sélecteur principal pour traiter les choix de l'utilisateur depuis le menu principal
void processChoice(int choice) {
    switch (choice) {
        case 1:
            displayRegisterStudentForm();
            displayMenu();
            break;
        case 2:
            displaySearchStudentMenu();
            displayModifyStudentMenu();
            break;
        case 3:
            displaySearchStudentMenu();
            displayStudentFound();
            displayMenu();
            break;
        case 4:
            displaySearchStudentMenu();
            displayDeleteStudentMenu();
            break;
        case 5:
            // TODO: Appeler sortAlphabetically() puis displayStudentList()
            displayStudentList();
            displayMenu();
            break;
        case 6:
            // TODO: Appeler binarySearch() après tri
            displaySearchStudentMenu();
            displayStudentFound();
            displayMenu();
            break;
        case 7:
            displaySearchStudentMenu();
            displayCalculateAgeMenu();
            displayMenu();
            break;
        case 8:
            displayStudentList();
            displayMenu();
            break;
        case 9:
            displaySettings();
            displayMenu();
            break;
        case 0:
            displayExitConfirmationMenu();
            break;
        default:
            displayError("Choix invalide", "Veuillez entrer un choix valide.");
            displayChoiceFooter();
            processChoice(getUserChoice());
            break;
    }
}
