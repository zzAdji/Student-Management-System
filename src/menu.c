#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu.h"
#include "../include/colors.h"
#include "../include/utils.h"
#include "../include/student.h"
#include "../include/operations.h"

int getUserChoice() {
    int choice;    
    int result = scanf("%d", &choice);
    while (getchar() != '\n'); 
    if (result != 1) {
        return -1; 
    }
    return choice;
}

void displayMenu(Student_Management *management) {
    clearScreen();
    displayPath("sms > menu");
    displayHeader("MENU PRINCIPAL");

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    char info[100];
    sprintf(info, "Étudiants enregistrés : %d", management->number);
    displayInfo(info);
    printf("\n");

    printSpaces(margin); printf("  " COLOR_YELLOW "1." COLOR_RESET " Inscrire un étudiant\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "2." COLOR_RESET " Modifier les informations\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "3." COLOR_RESET " Rechercher (par id)\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "4." COLOR_RESET " Supprimer un étudiant\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "5." COLOR_RESET " Trier la liste\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "6." COLOR_RESET " Recherche dichotomique\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "7." COLOR_RESET " Calculer l'âge de l'étudiant\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "8." COLOR_RESET " Afficher tous les étudiants\n\n");
    printSpaces(margin); printf("  " COLOR_CYAN   "9." COLOR_RESET " Paramètres\n");
    printSpaces(margin); printf("  " COLOR_RED    "0. \U0001F6AA Quitter" COLOR_RESET "\n");

    displayChoiceFooter();
    processChoice(getUserChoice(), management);
}

int displayRegisterStudentForm(Student_Management *management) {
    clearScreen();
    displayPath("sms > menu > inscription");
    displayHeader("INSCRIRE UN NOUVEL ÉTUDIANT");
    
    int termWidth = getTerminalWidth();
    int margin = (termWidth - 50) / 2;
    if (margin < 0) margin = 0;

    printSpaces(margin + 5); printf("Entrez les informations de l'étudiant :\n\n");
    
    Student newStudent;
    
    // Matricule
    printSpaces(margin); printf("Matricule (ex: 23ENSPM0443)    : ");
    fgets(newStudent.id, sizeof(newStudent.id), stdin);
    newStudent.id[strcspn(newStudent.id, "\n")] = '\0';

    // Nom
    printSpaces(margin); printf("Nom                            : ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    // Prénom
    printSpaces(margin); printf("Prénom                         : ");
    fgets(newStudent.surname, sizeof(newStudent.surname), stdin);
    newStudent.surname[strcspn(newStudent.surname, "\n")] = '\0';

    // Date de naissance
    // TODO: Implémenter la validation de la date de naissance
    char buffer[100];
    printSpaces(margin); printf("Date de naissance (JJ MM AAAA) : ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d %d %d", &newStudent.birth_date.day, &newStudent.birth_date.month, &newStudent.birth_date.year);

    // Genre
    // TODO: Implémenter la validation du genre (M/F)
    printSpaces(margin); printf("Genre (M/F)                    : ");
    fgets(buffer, sizeof(buffer), stdin);
    newStudent.gender = buffer[0];

    // Département
    printSpaces(margin); printf("Département                    : ");
    fgets(newStudent.department, sizeof(newStudent.department), stdin);
    newStudent.department[strcspn(newStudent.department, "\n")] = '\0';

    // Option/Filière
    printSpaces(margin); printf("Option                         : ");
    fgets(newStudent.option, sizeof(newStudent.option), stdin);
    newStudent.option[strcspn(newStudent.option, "\n")] = '\0';

    // Région d'origine
    printSpaces(margin); printf("Région d'origine               : ");
    fgets(newStudent.native_region, sizeof(newStudent.native_region), stdin);
    newStudent.native_region[strcspn(newStudent.native_region, "\n")] = '\0';

    int result = addStudent(management, newStudent);
    
    printf("\n");
    if (result) {
        displaySuccess("INSCRIPTION RÉUSSIE", "L'étudiant a été ajouté avec succès !");
        char stats[100];
        sprintf(stats, "Total étudiants : %d/%d", management->number, management->capacity);
        displayInfo(stats);
    } else {
        displayError("ERREUR", "Impossible d'ajouter l'étudiant.");
    }
    
    displaySimpleFooter();
    return result;
}

int displaySearchStudentMenu(Student_Management *management) {
    clearScreen();
    displayPath("sms > menu > recherche");
    displayHeader("RECHERCHE ETUDIANT");
    
    if (management->number == 0) {
        displayWarning("LISTE VIDE", "Aucun étudiant enregistré dans la base.");
        displaySimpleFooter();
        return -1;
    }
    
    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    printSpaces(margin); printf("Entrer le matricule de l'étudiant :\n");
    printSpaces(margin); printf("___________________\r");
    printSpaces(margin); 
    
    char id[20];
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    
    // Recherche de l'étudiant par matricule
    int index = findStudentById(management, id);
    
    if (index >= 0) {
        return index;
    }
    
    printf("\n");
    displayError("NON TROUVÉ", "Aucun étudiant avec ce matricule.");
    displaySimpleFooter();
    return -1;
}

void displayStudentFound(Student_Management *management, int index) {
    if (index < 0 || index >= management->number) {
        displayError("ERREUR", "Index d'étudiant invalide.");
        return;
    }
    
    clearScreen();
    displayPath("sms > menu > recherche > résultat");
    displaySuccess("ETUDIANT TROUVÉ", "Informations de l'étudiant :");

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    Student *s = getStudentByIndex(management, index);
    if (s == NULL) {
        displayError("ERREUR", "Impossible d'afficher les informations de l'étudiant.");
        return;
    }

    printf("\n");
    printSpaces(margin); printf("  Matricule          : %s\n", s->id);
    printSpaces(margin); printf("  Nom                : %s\n", s->name);
    printSpaces(margin); printf("  Prénom             : %s\n", s->surname);
    printSpaces(margin); printf("  Date de naissance  : %02d/%02d/%04d\n", s->birth_date.day, s->birth_date.month, s->birth_date.year);
    // TODO: Implémenter calculateAge() et afficher l'âge réel
    printSpaces(margin); printf("  Âge                : 24 ans, 6 mois, 7 jours\n"); // Mock data
    printSpaces(margin); printf("  Genre              : %c\n", s->gender);
    printSpaces(margin); printf("  Département        : %s\n", s->department);
    printSpaces(margin); printf("  Option             : %s\n", s->option);
    printSpaces(margin); printf("  Région d'origine   : %s\n", s->native_region);

    displaySimpleFooter();
}

void displayModifyStudentMenu(Student_Management *management, int index) {
    if (index < 0 || index >= management->number) {
        displayError("ERREUR", "Index d'étudiant invalide.");
        displaySimpleFooter();
        return;
    }
    
    clearScreen();
    displayPath("sms > menu > modification");
    displayHeader("MODIFIER INFORMATION ETUDIANT");

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    Student *s = getStudentByIndex(management, index);
    if (s == NULL) {
        displayError("ERREUR", "Impossible de récupérer l'étudiant.");
        displaySimpleFooter();
        return;
    }
    
    char info[150];
    sprintf(info, "Étudiant actuel : [%s] - [%s] [%s]", s->id, s->name, s->surname);
    displayInfo(info);

    printf("\n");
    printSpaces(margin); printf("Quel champ souhaitez-vous modifier ?\n\n");

    printSpaces(margin); printf("  " COLOR_YELLOW "1." COLOR_RESET " Matricule\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "2." COLOR_RESET " Nom\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "3." COLOR_RESET " Prénom\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "4." COLOR_RESET " Date de naissance\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "5." COLOR_RESET " Genre\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "6." COLOR_RESET " Département\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "7." COLOR_RESET " Option\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "8." COLOR_RESET " Région d'origine\n\n");
    printSpaces(margin); printf("  " COLOR_RED    "0. ❌ Retour" COLOR_RESET "\n");

    displayChoiceFooter();
    processModifyStudentChoice(getUserChoice(), management, index);
}

void processModifyStudentChoice(int choice, Student_Management *management, int index) {
    if (index < 0 || index >= management->number) {
        displayMenu(management);
        return;
    }
    
    Student *s = getStudentByIndex(management, index);
    if (s == NULL) {
        displayMenu(management);
        return;
    }
    char buffer[100];
    int result = 0;
    
    switch (choice) {
        case 1: // Matricule
            printf("\nMatricule actuel: %s\n", s->id);
            printf("Nouveau matricule: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            result = modifyStudent(management, index, 1, buffer);
            if (result) {
                displaySuccess("MODIFIÉ", "Matricule mis à jour avec succès !");
            } else {
                displayError("ERREUR", "Impossible de modifier le matricule.");
            }
            displaySimpleFooter();
            displayModifyStudentMenu(management, index);
            break;
            
        case 2: // Nom
            printf("\nNom actuel: %s\n", s->name);
            printf("Nouveau nom: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            result = modifyStudent(management, index, 2, buffer);
            if (result) {
                displaySuccess("MODIFIÉ", "Nom mis à jour avec succès !");
            } else {
                displayError("ERREUR", "Impossible de modifier le nom.");
            }
            displaySimpleFooter();
            displayModifyStudentMenu(management, index);
            break;
            
        case 3: // Prénom
            printf("\nPrénom actuel: %s\n", s->surname);
            printf("Nouveau prénom: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            result = modifyStudent(management, index, 3, buffer);
            if (result) {
                displaySuccess("MODIFIÉ", "Prénom mis à jour avec succès !");
            } else {
                displayError("ERREUR", "Impossible de modifier le prénom.");
            }
            displaySimpleFooter();
            displayModifyStudentMenu(management, index);
            break;
            
        case 4: // Date de naissance
            printf("\nDate actuelle: %02d/%02d/%d\n", s->birth_date.day, s->birth_date.month, s->birth_date.year);
            printf("Nouvelle date (JJ MM AAAA): ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            result = modifyStudent(management, index, 4, buffer);
            if (result) {
                displaySuccess("MODIFIÉ", "Date de naissance mise à jour !");
            } else {
                displayError("ERREUR", "Format de date invalide. Utilisez: JJ MM AAAA");
            }
            displaySimpleFooter();
            displayModifyStudentMenu(management, index);
            break;
            
        case 5: // Genre
            printf("\nGenre actuel: %c\n", s->gender);
            printf("Nouveau genre (M/F): ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            result = modifyStudent(management, index, 5, buffer);
            if (result) {
                displaySuccess("MODIFIÉ", "Genre mis à jour avec succès !");
            } else {
                displayError("ERREUR", "Genre invalide. Entrez M ou F.");
            }
            displaySimpleFooter();
            displayModifyStudentMenu(management, index);
            break;
            
        case 6: // Département
            printf("\nDépartement actuel: %s\n", s->department);
            printf("Nouveau département: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            result = modifyStudent(management, index, 6, buffer);
            if (result) {
                displaySuccess("MODIFIÉ", "Département mis à jour avec succès !");
            } else {
                displayError("ERREUR", "Impossible de modifier le département.");
            }
            displaySimpleFooter();
            displayModifyStudentMenu(management, index);
            break;
            
        case 7: // Option
            printf("\nOption actuelle: %s\n", s->option);
            printf("Nouvelle option: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            result = modifyStudent(management, index, 7, buffer);
            if (result) {
                displaySuccess("MODIFIÉ", "Option mise à jour avec succès !");
            } else {
                displayError("ERREUR", "Impossible de modifier l'option.");
            }
            displaySimpleFooter();
            displayModifyStudentMenu(management, index);
            break;
            
        case 8: // Région d'origine
            printf("\nRégion actuelle: %s\n", s->native_region);
            printf("Nouvelle région: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            result = modifyStudent(management, index, 8, buffer);
            if (result) {
                displaySuccess("MODIFIÉ", "Région mise à jour avec succès !");
            } else {
                displayError("ERREUR", "Impossible de modifier la région.");
            }
            displaySimpleFooter();
            displayModifyStudentMenu(management, index);
            break;
            
        case 0: // Retour
            displayMenu(management);
            break;
            
        default:
            displayError("Choix invalide", "Veuillez entrer un choix valide.");
            displayChoiceFooter();
            processModifyStudentChoice(getUserChoice(), management, index);
            break;
    }
}

void displayDeleteStudentMenu(Student_Management *management, int index) {
    if (index < 0 || index >= management->number) {
        displayError("ERREUR", "Index d'étudiant invalide.");
        displaySimpleFooter();
        displayMenu(management);
        return;
    }
    
    clearScreen();
    displayPath("sms > menu > suppression");
    displayWarning("SUPPRESSION ETUDIANT", "Êtes-vous sûr de vouloir supprimer cet étudiant?");

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    Student *s = getStudentByIndex(management, index);
    if (s == NULL) {
        displayError("ERREUR", "Impossible de récupérer l'étudiant.");
        displaySimpleFooter();
        displayMenu(management);
        return;
    }
    
    printf("\n");
    printSpaces(margin); printf("  Matricule : [%s]\n", s->id);
    printSpaces(margin); printf("  Nom       : [%s]\n", s->name);
    printSpaces(margin); printf("  Prénom    : [%s]\n", s->surname);
    
    printf("\n\n");
    printSpaces(margin); printf("  " COLOR_RED   "1. Oui, supprimer" COLOR_RESET "\n");
    printSpaces(margin); printf("  " COLOR_GREEN "0. ❌ Non, annuler" COLOR_RESET "\n");

    displayChoiceFooter();
    processDeleteChoice(getUserChoice(), management, index);
}

void processDeleteChoice(int choice, Student_Management *management, int index) {
    switch (choice) {
        case 1:
            if (deleteStudent(management, index)) {
                displaySuccess("SUPPRIMÉ", "L'étudiant a été supprimé avec succès.");
            } else {
                displayError("ERREUR", "Impossible de supprimer l'étudiant.");
            }
            displaySimpleFooter();
            displayMenu(management);
            break;
        case 0:
            displayMenu(management);
            break;
        default:
            displayError("Choix invalide", "Veuillez entrer un choix valide.");
            displayChoiceFooter();
            processDeleteChoice(getUserChoice(), management, index);
            break;
    }
}

void displaySortMenu(Student_Management *management) {
    clearScreen();
    displayPath("sms > menu > tri");
    displayHeader("TRIER LA LISTE DES ÉTUDIANTS");

    if (management->number == 0) {
        displayWarning("LISTE VIDE", "Aucun étudiant à trier.");
        displaySimpleFooter();
        displayMenu(management);
        return;
    }

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    char info[100];
    sprintf(info, "%d étudiant(s) dans la liste", management->number);
    displayInfo(info);
    
    printf("\n");
    printSpaces(margin); printf("Choisissez le critère de tri :\n\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "1." COLOR_RESET " Trier par nom (A-Z)\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "2." COLOR_RESET " Trier par option/filière\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "3." COLOR_RESET " Trier par matricule\n\n");
    printSpaces(margin); printf("  " COLOR_RED    "0. ❌ Retour" COLOR_RESET "\n");

    displayChoiceFooter();
    processSortChoice(getUserChoice(), management);
}

void processSortChoice(int choice, Student_Management *management) {
    switch (choice) {
        case 1:
            // TODO: Implémenter le tri par nom avec qsort() et compareStudentsByName()
            displaySuccess("TRI EFFECTUÉ", "Liste triée par nom (A-Z). [Mock]");
            displaySimpleFooter();
            displayStudentList(management);
            break;
        case 2:
            // TODO: Implémenter le tri par option avec qsort() et compareStudentsByOption()
            displaySuccess("TRI EFFECTUÉ", "Liste triée par option/filière. [Mock]");
            displaySimpleFooter();
            displayStudentList(management);
            break;
        case 3:
            // TODO: Implémenter le tri par matricule avec qsort() et compareStudentsById()
            displaySuccess("TRI EFFECTUÉ", "Liste triée par matricule. [Mock]");
            displaySimpleFooter();
            displayStudentList(management);
            break;
        case 0:
            displayMenu(management);
            break;
        default:
            displayError("Choix invalide", "Veuillez entrer un choix valide.");
            displayChoiceFooter();
            processSortChoice(getUserChoice(), management);
            break;
    }
}

int displayBinarySearchMenu(Student_Management *management) {
    clearScreen();
    displayPath("sms > menu > recherche dichotomique");
    displayHeader("RECHERCHE DICHOTOMIQUE");
    
    if (management->number == 0) {
        displayWarning("LISTE VIDE", "Aucun étudiant enregistré.");
        displaySimpleFooter();
        return -1;
    }
    
    // TODO: Implémenter le tri par matricule avant la recherche dichotomique
    displayInfo("Tri de la liste par matricule... [Mock]");
    displaySuccess("TRIÉ", "Liste triée par matricule. [Mock]");
    
    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    printf("\n");
    printSpaces(margin); printf("Entrer le matricule à rechercher :\n");
    printSpaces(margin); printf("___________________\r");
    printSpaces(margin);
    
    char id[20];
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    
    // TODO: Implémenter la recherche dichotomique avec binarySearch()
    // Mock: Retourne l'index 0 si la liste n'est pas vide
    if (management->number > 0) {
        return 0; // Mock data
    }
    
    printf("\n");
    displayError("NON TROUVÉ", "Aucun étudiant avec ce matricule (recherche dichotomique).");
    displaySimpleFooter();
    return -1;
}

void displayStudentList(Student_Management *management) {
    clearScreen();
    displayPath("sms > menu > liste d'étudiants");
    
    char header[100];
    sprintf(header, "LISTE DES ÉTUDIANTS (%d étudiants)", management->number);
    displayHeader(header);

    if (management->number == 0) {
        displayWarning("LISTE VIDE", "Aucun étudiant enregistré dans la base.");
        displaySimpleFooter();
        displayMenu(management);
        return;
    }

    int termWidth = getTerminalWidth();
    int tableWidth = 86;
    int margin = (termWidth - tableWidth) / 2;
    if (margin < 0) margin = 0;

    printSpaces(margin); printf("┌─────┬─────────────────┬──────────────┬──────────────┬────────────┬─────────────────┐\n");
    printSpaces(margin); printf("│ No  │       ID        │     Nom      │    Prénom    │ Naissance  │     Option      │\n");
    printSpaces(margin); printf("├─────┼─────────────────┼──────────────┼──────────────┼────────────┼─────────────────┤\n");
    
    viewAllStudents(management);
    
    printSpaces(margin); printf("└─────┴─────────────────┴──────────────┴──────────────┴────────────┴─────────────────┘\n");
    printf("\n");

    displayOnListMenu(management);
}

void displayOnListMenu(Student_Management *management) {
    displayHeader("ACTION SUR LA LISTE");

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    printSpaces(margin); printf("Quelle action souhaitez-vous effectuer ?\n\n");

    printSpaces(margin); printf("  " COLOR_YELLOW "1." COLOR_RESET " Sélectionner un étudiant\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "2." COLOR_RESET " Trier la liste\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "3." COLOR_RESET " Tout supprimer\n\n");
    printSpaces(margin); printf("  " COLOR_RED    "0. ❌ Retour au menu" COLOR_RESET "\n");

    displayChoiceFooter();
    processOnListChoice(getUserChoice(), management);
}

void processOnListChoice(int choice, Student_Management *management) {
    int index;
    switch (choice) {
        case 1:
            index = displaySearchStudentMenu(management);
            if (index >= 0) {
                displayStudentFound(management, index);
            }
            displayMenu(management);
            break;
        case 2:
            displaySortMenu(management);
            break;
        case 3:
            deleteAllStudents(management);
            displaySimpleFooter();
            displayMenu(management);
            break;
        case 0:
            displayMenu(management);
            break;
        default:
            displayError("Choix invalide", "Veuillez entrer un choix valide.");
            displayChoiceFooter();
            processOnListChoice(getUserChoice(), management);
            break;
    }
}

void displayCalculateAgeMenu(Student_Management *management, int index) {
    if (index < 0 || index >= management->number) {
        displayError("ERREUR", "Index d'étudiant invalide.");
        displaySimpleFooter();
        return;
    }
    
    clearScreen();
    displayPath("sms > menu > âge");
    displayHeader("CALCULER L'ÂGE DE L'ÉTUDIANT");
    
    // TODO: Implémenter la récupération de la date actuelle
    displayInfo("Date actuelle : 01/01/2026"); // Mock data

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    Student *s = getStudentByIndex(management, index);
    if (s == NULL) {
        displayError("ERREUR", "Impossible de récupérer l'étudiant.");
        displaySimpleFooter();
        return;
    }

    printf("\n");
    printSpaces(margin); printf("Étudiant : %s %s\n", s->surname, s->name);
    printSpaces(margin); printf("Matricule : %s\n", s->id);
    printSpaces(margin); printf("Date de naissance : %02d/%02d/%04d\n\n", s->birth_date.day, s->birth_date.month, s->birth_date.year);

    // TODO: Implémenter calculateAge() pour calculer l'âge réel
    printSpaces(margin); printf(COLOR_GREEN "Âge : 24 ans, 6 mois, 7 jours" COLOR_RESET "\n"); // Mock data

    displaySimpleFooter();
}

void displaySettings(Student_Management *management) {
    clearScreen();    
    displayPath("sms > paramètres");
    displayHeader("PARAMÈTRES");
    
    int termWidth = getTerminalWidth();
    int margin = (termWidth - 40) / 2;
    if (margin < 0) margin = 0;

    char info[100];
    sprintf(info, "Capacité actuelle : %d étudiants max", management->capacity);
    displayInfo(info);
    
    sprintf(info, "Étudiants enregistrés : %d", management->number);
    displayInfo(info);

    displaySimpleFooter();
}

void displayExitConfirmationMenu(Student_Management *management) {
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
    processExitChoice(getUserChoice(), management);
}

void processExitChoice(int choice, Student_Management *management) {
    switch (choice) {
        case 1:
            freeManagement(management);
            printf("\n✅ Mémoire libérée. Au revoir !\n");
            exit(0); 
            break;
        case 0:
            displayMenu(management);
            break;
        default:
            displayError("Choix invalide", "Veuillez entrer un choix valide.");
            displayChoiceFooter();
            processExitChoice(getUserChoice(), management);
            break;
    }
}

void processChoice(int choice, Student_Management *management) {
    int index;
    
    switch (choice) {
        case 1:
            displayRegisterStudentForm(management);
            displayMenu(management);
            break;
            
        case 2:
            index = displaySearchStudentMenu(management);
            if (index >= 0) {
                displayModifyStudentMenu(management, index);
            } else {
                displayMenu(management);
            }
            break;
            
        case 3:
            index = displaySearchStudentMenu(management);
            if (index >= 0) {
                displayStudentFound(management, index);
            }
            displayMenu(management);
            break;
            
        case 4:
            index = displaySearchStudentMenu(management);
            if (index >= 0) {
                displayDeleteStudentMenu(management, index);
            } else {
                displayMenu(management);
            }
            break;
            
        case 5:
            displaySortMenu(management);
            break;
            
        case 6:
            index = displayBinarySearchMenu(management);
            if (index >= 0) {
                displayStudentFound(management, index);
            }
            displayMenu(management);
            break;
            
        case 7:
            index = displaySearchStudentMenu(management);
            if (index >= 0) {
                displayCalculateAgeMenu(management, index);
            }
            displayMenu(management);
            break;
            
        case 8:
            displayStudentList(management);
            break;
            
        case 9:
            displaySettings(management);
            displayMenu(management);
            break;
            
        case 0:
            displayExitConfirmationMenu(management);
            break;
            
        default:
            displayError("Choix invalide", "Veuillez entrer un choix valide.");
            displayChoiceFooter();
            processChoice(getUserChoice(), management);
            break;
    }
}
