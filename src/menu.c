#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu.h"

void displayMenu() {
    // Définit la page de code de la console sur UTF-8 pour un affichage correct des emojis et caractères de bordure
    system("chcp 65001 > nul");

    displayHeader("STUDENT MANAGEMENT SYSTEM (SMS)");

    printf("  1. Inscrire un étudiant\n");
    printf("  2. Modifier les informations\n");
    printf("  3. Rechercher (par id)\n");
    printf("  4. Supprimer un étudiant\n");
    printf("  5. Trier par ordre alphabétique\n");
    printf("  6. Recherche dichotomique\n");
    printf("  7. Calculer l'âge de l'étudiant\n");
    printf("  8. Trier par option\n");
    printf("  9. Afficher tous les étudiants\n");
    printf("  0. \U0001F6AA Quitter\n");

    displayChoiceFooter();
    processChoice(getUserChoice());
}

// Affiche le menu pour modifier les informations d'un étudiant
void displayModifyStudentMenu(){
    displayHeader("MODIFIER INFORMATION ETUDIANT");

    // TODO: En attente de la fonction de récupération d'un étudiant par matricule
    printf("\nÉtudiant actuel : [23ENSPM0443] - [Dupont] [Jean]\n");

    printf("\nQuel champ souhaitez-vous modifier ?\n\n");

    printf("  1. Matricule\n");
    printf("  2. Nom\n");
    printf("  3. Prénom\n");
    printf("  4. Date de naissance\n");
    printf("  5. Genre\n");
    printf("  6. Département\n");
    printf("  7. Option\n");
    printf("  8. Région d'origine\n");
    printf("  9. ✅ Enregistrer et retourner\n");
    printf("  0. ❌ Annuler\n");

    displayChoiceFooter();
    processModifyStudentChoice(getUserChoice());
}

// Affiche le formulaire pour inscrire un nouvel étudiant
void displayRegisterStudentForm(){
    displayHeader("INSCRIRE UN NOUVEL ÉTUDIANT");
    printf("Entrez les informations de l'étudiant :\n\n");
    
    char buffer[100];

    printf("Matricule (ex: 23ENSPM0443)    : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    printf("Nom                            : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    printf("Prénom                         : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    printf("Date de naissance (JJ/MM/AAAA) : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    printf("Genre (M/F)                    : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    printf("Département                    : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    printf("Option                         : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    printf("Région d'origine               : ");
    scanf("%99s", buffer);
    while (getchar() != '\n');

    // TODO: Appel à la fonction métier registerStudent() ici
    // en attente de l'implémentation du stockage dynamique
    
    displaySimpleFooter();
}

// Affiche le résultat quand un étudiant est trouvé
void displayStudentFound() {
    char title[256];
    snprintf(title, sizeof(title), "\u2705 ETUDIANT TROUVÉ");
    displayHeader(title);

    // TODO: Remplacer ces données par les champs réels de la structure Student
    printf("  Matricule          : 23ENSPM0443\n");
    printf("  Nom                : Dupont\n");
    printf("  Prénom             : Jean\n");
    printf("  Date de naissance  : 15/06/2000\n");
    printf("  Age                : 24 ans\n");
    printf("  Genre              : M\n");
    printf("  Département        : Génie Informatique\n");
    printf("  Option             : Génie Logiciel\n");
    printf("  Région d'origine   : Centre\n");

    displaySimpleFooter();
}

// Affiche le menu de recherche d'un étudiant
void displaySearchStudentMenu(){
    displayHeader("RECHERCHE ETUDIANT");
    printf("Entrer le matricule de l'étudiant :\n");
    printf("___________\r");
    
    char id[50];
    scanf("%49s", id);
    while (getchar() != '\n');
    
    // TODO: Intégrer la fonction linearSearch() ici
    printf("\nRecherche de l'étudiant %s en cours...\n", id);
}

// Affiche le menu de suppression d'un étudiant avec confirmation
void displayDeleteStudentMenu(){
    displayWarning("SUPPRESSION ETUDIANT", "Êtes-vous sûr de vouloir supprimer cet étudiant?");

    // TODO: Données à récupérer dynamiquement
    printf("\n  Matricule : [23ENSPM0443]");
    printf("\n  Nom       : [Dupont]");
    printf("\n  Prénom    : [Jean]");
    
    printf("\n\n");
    printf("  1. Oui, supprimer\n");
    printf("  0. ❌ Non, annuler\n");

    displayChoiceFooter();
    processDeleteChoice(getUserChoice());
}

// Affiche le dialogue de confirmation de sortie
void displayExitConfirmationMenu(){
    displayInfo("CONFIRMATION QUITTER", "Voulez-vous vraiment quitter l'application ?");
    printf("\n");
    printf("  1. Oui, quitter\n");
    printf("  0. ❌ Non, retourner au menu\n");

    displayChoiceFooter();
    processExitChoice(getUserChoice());
}

// Affiche la liste de tous les étudiants sous forme de tableau
void displayStudentList() {
    displayHeader("LISTE DES ÉTUDIANTS (15 étudiants)");

    // TODO: Parcourir le tableau dynamique d'étudiants (ViewAllStudents)
    printf("┌─────┬─────────────────┬──────────────┬──────────────┬────────────┬─────────────────┐\n");
    printf("│ No  │       ID        │     Nom      │    Prénom    │ Naissance  │     Option      │\n");
    printf("├─────┼─────────────────┼──────────────┼──────────────┼────────────┼─────────────────┤\n");
    printf("│ 1   │ STU2024001      │ Dupont       │ Jean         │ 15/06/2000 │ Génie Logiciel  │\n");
    printf("│ 2   │ STU2024002      │ Martin       │ Marie        │ 23/09/1999 │ Data Science    │\n");
    printf("│ 3   │ STU2024003      │ Bernard      │ Paul         │ 10/03/2001 │ Réseaux         │\n");
    printf("│ ... │ ...             │ ...          │ ...          │ ...        │ ...             │\n");
    printf("└─────┴─────────────────┴──────────────┴──────────────┴────────────┴─────────────────┘\n");

    printf("\nTotal: 15 étudiant(s)\n"); // TODO: Afficher le compteur réel count

    displaySimpleFooter();
}

// Affiche le menu pour calculer l'âge d'un étudiant
void displayCalculateAgeMenu() {
    displayHeader("CALCULER L'ÂGE DE L'ÉTUDIANT");

    printf("Matricule de l'étudiant : 23ENSPM0443\n");

    printf("\n────────────────────────────────────────────────────\n\n");

    // TODO: Utiliser la fonction calculateAge() de utils.h
    printf("Étudiant : Jean Dupont\n");
    printf("Date de naissance : 15/06/2000\n");
    printf("Date actuelle : 22/12/2024\n\n");

    printf("Âge : 24 ans, 6 mois, 7 jours\n");

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

void processModifyStudentChoice(int choice){
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
            // TODO: Appeler sortByOption() puis displayStudentList()
            displayStudentList();
            displayMenu();
            break;
        case 9:
            displayStudentList();
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

// Affiche un en-tête centré avec un cadre
void displayHeader(char *title) {
    int titleLen = (int)strlen(title);
    
    // Calcul du padding supplémentaire nécessaire pour les caractères UTF-8
    int extraPadding = 0;
    for (int i = 0; i < titleLen; i++) {
        unsigned char c = (unsigned char)title[i];
        
        if (i + 2 < titleLen && c == 0xEF && (unsigned char)title[i+1] == 0xB8 && (unsigned char)title[i+2] == 0x8F) {
            extraPadding += 4; 
            i += 2;
            continue;
        }

        if (c >= 0xF0) {
            extraPadding += 2; 
            i += 3;
        } else if (c >= 0xE0) {
             extraPadding += 1;
             i += 2;
        } else if (c >= 0xC0) {
            extraPadding += 1;
            i += 1;
        }
    }

    int innerWidth = (titleLen > 53) ? (titleLen - extraPadding + 4) : 53;
    // On s'assure que innerWidth reste cohérent avec le calcul original si pas d'emojis longs
    if (innerWidth < 53) innerWidth = 53;

    int totalPadding = innerWidth - (titleLen - extraPadding);
    int leftPadding = totalPadding / 2;
    int rightPadding = totalPadding - leftPadding;

    printf("\n╔");
    for (int i = 0; i < innerWidth; i++) printf("═");
    printf("╗\n");

    printf("║%*s%s%*s║\n", leftPadding, "", title, rightPadding, "");

    printf("╚");
    for (int i = 0; i < innerWidth; i++) printf("═");
    printf("╝\n\n");
}

// Affiche un message de succès
void displaySuccess(char *subtitle, char *message) {
    char title[256];
    snprintf(title, sizeof(title), "\u2705 SUCCESS : %s", subtitle);
    displayHeader(title);
    printf("%s\n", message);
}

// Affiche un message d'erreur
void displayError(char *subtitle, char *message) {
    char title[256];
    snprintf(title, sizeof(title), "\u274C ERROR : %s", subtitle);
    displayHeader(title);
    printf("%s\n", message);
}

// Affiche un message d'information
void displayInfo(char *subtitle, char *message) {
    char title[256];
    snprintf(title, sizeof(title), "\u2139\uFE0F  INFO : %s", subtitle);
    displayHeader(title);
    printf("%s\n", message);
}

// Affiche un message d'avertissement
void displayWarning(char *subtitle, char *message) {
    char title[256];
    snprintf(title, sizeof(title), "\u26A0\uFE0F  WARNING : %s", subtitle);
    displayHeader(title);
    printf("%s\n", message);
}

// Affiche un pied de page demandant d'appuyer sur Entrée
void displaySimpleFooter(){
    printf("\n");
    printf("────────────────────────────────────────────────────\n");
    printf("\n");
    printf("Appuyez sur Entrée pour continuer...");
    getchar();
    printf("\n");
}

// Affiche l'invite pour le choix de l'utilisateur
void displayChoiceFooter() {
    printf("\n");
    printf("────────────────────────────────────────────────────\n");
    printf("\n");
    printf("Votre choix: ");
}
