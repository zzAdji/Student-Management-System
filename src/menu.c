#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "../include/utils.h"
#include "../include/validation.h"
#include "../include/menu.h"
#include "../include/config.h"
#include "../include/utils.h"
#include "../include/student.h"
#include "../include/operations.h"
#include "../include/validation.h"
#include "../include/sort.h"
#include "../include/search.h"
#include "../include/data.h"


int getUserChoice() {
    int choice;    
    int result = scanf("%d", &choice);
    clearBuffer();

    if (result != 1) {
        return -1; 
    }
    return choice;
}

void displayStart(Student_Management *managment) {
    printCenterText("Aucune données existante. Initialisation...");
    displayHeader("INITIALISATION DU SYSTEME");

    printCenterText("Combien d'étudiants avez vous pour l'instant ?");
    displayChoiceFooter();
    int newCapacity = getUserChoice();
    
    if (newCapacity < 1) {
        newCapacity = 10;
    }
    
    Student *newList = (Student *)realloc(managment->list, sizeof(Student) * newCapacity);
    if (newList != NULL) {
        managment->list = newList;
        managment->capacity = newCapacity;
    } else {
        managment->list = (Student *)malloc(sizeof(Student) * 10);
        managment->capacity = 10;
    }
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
    printSpaces(margin); printf("  " COLOR_YELLOW "3." COLOR_RESET " Rechercher (par matricule)\n");
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
    
    // Matricule (avec vérification d'unicité)
    do {
        inputValidString(
            newStudent.id,
            sizeof(newStudent.id),
            "Matricule (ex: 23ENSPM0443)    : ",
            validateId,
            "Le format de ce matricule est mauvais! Veillez réessayer!"
        );
        if (findStudentById(management, newStudent.id) != -1) {
            displayError("MATRICULE EXISTANT", "Ce matricule existe déjà. Veuillez en saisir un autre !");
            printf("\n");
        } else {
            break;
        }
    } while (1);

    // Nom
    
    inputValidString(
        newStudent.name, 
        sizeof(newStudent.name),
        "Nom                            : ", 
        validateString, 
        "Le nom est invalide! Veillez réessayer!"
    );

    // Prénom
    inputValidString(
        newStudent.surname, 
        sizeof(newStudent.surname),
        "Prénom                         : ", 
        validateString, 
        "Le prénom est invalide! Veillez réessayer!"
    );

    // Date de naissance
    char buffer[100];
    inputValidDate(
        buffer, 
        "Date de naissance (JJ/MM/AAAA) : "
    );
    int n = sscanf(buffer, "%d/%d/%d",
         &newStudent.birth_date.day,
         &newStudent.birth_date.month, 
         &newStudent.birth_date.year);
         if(n != 3){
            n = sscanf(buffer, "%d-%d-%d",
         &newStudent.birth_date.day,
         &newStudent.birth_date.month, 
         &newStudent.birth_date.year);
         }
         if(n != 3){
            n = sscanf(buffer, "%d %d %d",
         &newStudent.birth_date.day,
         &newStudent.birth_date.month, 
         &newStudent.birth_date.year);
         }
         if(n != 3 ){
            printf("Format invalide\n");
         }

    // Genre
    inputValidString(
        buffer,
        sizeof(buffer),
        "Genre (M/F)                    : ", 
        validateGender, 
        "Le genre doit etre M ou F! Veillez réessayer!"
    );
    newStudent.gender = toupper(buffer[0]);

    displayPredefinedDepartments();

    // Département
    inputValidString(
        newStudent.department,
        sizeof(newStudent.department),
        "Département                    : ", 
        validateString, 
        "Le département est invalide! Veillez réessayer!"
    );

    const DepartmentInfo *dept = findDepartmentByCode(newStudent.department);
    
    if (dept != NULL) {
    
        strncpy(newStudent.department, dept->code, sizeof(newStudent.department) - 1);
        newStudent.department[sizeof(newStudent.department) - 1] = '\0';
        
        if (!selectOptionFromDepartment(dept, newStudent.option, sizeof(newStudent.option))) {
            displayError("ERREUR", "Impossible de sélectionner une option.");
            displaySimpleFooter();
            return 0;
        }
    } else {        
        // Option/Filière
        inputValidString(
            newStudent.option, 
            sizeof(newStudent.option),
            "Option                         : ", 
            validateString, 
            "L'option est invalide! Veillez réessayer!"
        );
    }

    // Région d'origine
    inputValidString(
        newStudent.native_region,
        sizeof(newStudent.native_region),
        "Région d'origine               : ", 
        validateString, 
        "La région d'origine est invalide! Veillez réessayer!"
    );

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
    printSpaces(margin); printf("  Âge                : %d\n", calculateAge(s->birth_date));
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

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 50) / 2;
    if (margin < 0) margin = 0;
    
    switch (choice) {
        case 1: // Matricule
            printSpaces(margin); printf("Actuel matricule : %s\n", s->id);
            inputValidString(
                s->id,
                sizeof(s->id),
                "Nouveau matricule (ex: 23ENSPM0443): ", 
                validateId, 
                "Le format de ce matricule est mauvais! Veillez réessayer!"
            );
            result = modifyStudent(management, index, 1, s->id);
            if (result) {
                displaySuccess("MODIFIÉ", "Matricule mis à jour avec succès !");
            } else {
                displayError("ERREUR", "Impossible de modifier le matricule.");
            }
            displaySimpleFooter();
            displayModifyStudentMenu(management, index);
            break;
            
        case 2: // Nom
            printSpaces(margin); printf("Actuel nom : %s\n", s->name);
            inputValidString(
                s->name,
                sizeof(s->name),
                "Nouveau nom: ", 
                validateString, 
                "Le nom doit contenir au moins 2 caractères! Veillez réessayer!"
            );
            result = modifyStudent(management, index, 2, s->name);
            if (result) {
                displaySuccess("MODIFIÉ", "Nom mis à jour avec succès !");
            } else {
                displayError("ERREUR", "Impossible de modifier le nom.");
            }
            displaySimpleFooter();
            displayModifyStudentMenu(management, index);
            break;
            
        case 3: // Prénom
            printSpaces(margin); printf("Actuel prénom : %s\n", s->surname);
            inputValidString(
                s->surname,
                sizeof(s->surname),
                "Nouveau prénom: ", 
                validateString, 
                "Le prénom doit contenir au moins 2 caractères! Veillez réessayer!"
            );
            result = modifyStudent(management, index, 3, s->surname);
            if (result) {
                displaySuccess("MODIFIÉ", "Prénom mis à jour avec succès !");
            } else {
                displayError("ERREUR", "Impossible de modifier le prénom.");
            }
            displaySimpleFooter();
            displayModifyStudentMenu(management, index);
            break;
            
        case 4: // Date de naissance
            printSpaces(margin); printf("Actuelle date de naissance : %02d/%02d/%04d\n", s->birth_date.day, s->birth_date.month, s->birth_date.year);
            inputValidDate(
                buffer,
                "Nouvelle date (JJ MM AAAA): "
            );
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
            printSpaces(margin); printf("Actuel genre : %c\n", s->gender);
            inputValidString(
                buffer,
                sizeof(buffer),
                "Nouveau genre (M/F): ", 
                validateGender, 
                "Le genre doit être M ou F! Veillez réessayer!"
            );
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
            printSpaces(margin); printf("Actuel département : %s\n", s->department);
            inputValidString(
                s->department,
                sizeof(s->department),
                "Nouveau département: ", 
                validateString, 
                "Le département doit contenir au moins 2 caractères! Veillez réessayer!"
            );
            result = modifyStudent(management, index, 6, s->department);
            if (result) {
                displaySuccess("MODIFIÉ", "Département mis à jour avec succès !");
            } else {
                displayError("ERREUR", "Impossible de modifier le département.");
            }
            displaySimpleFooter();
            displayModifyStudentMenu(management, index);
            break;
            
        case 7: // Option
            printSpaces(margin); printf("Actuelle option : %s\n", s->option);
            inputValidString(
                s->option,
                sizeof(s->option),
                "Nouvelle option: ", 
                validateString, 
                "L'option doit contenir au moins 2 caractères! Veillez réessayer!"
            );
            result = modifyStudent(management, index, 7, s->option);
            if (result) {
                displaySuccess("MODIFIÉ", "Option mise à jour avec succès !");
            } else {
                displayError("ERREUR", "Impossible de modifier l'option.");
            }
            displaySimpleFooter();
            displayModifyStudentMenu(management, index);
            break;
            
        case 8: // Région d'origine
            printSpaces(margin); printf("Actuelle région d'origine : %s\n", s->native_region);
            inputValidString(
                s->native_region,
                sizeof(s->native_region),
                "Nouvelle région: ",  
                validateString, 
                "La région doit contenir au moins 2 caractères! Veillez réessayer!"
            );
            result = modifyStudent(management, index, 8, s->native_region);
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
            sortAlphabetically(management);
            displaySuccess("TRI EFFECTUÉ", "Liste triée par nom (A-Z).");
            displaySimpleFooter();
            displayStudentList(management);
            break;
        case 2:
            sortByOption(management);
            displaySuccess("TRI EFFECTUÉ", "Liste triée par option/filière.");
            displaySimpleFooter();
            displayStudentList(management);
            break;
        case 3:
            sortById(management);
            displaySuccess("TRI EFFECTUÉ", "Liste triée par matricule.");
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
    displayHeader("RECHERCHE PAR NOM / PRÉNOM");
    
    if (management->number == 0) {
        displayWarning("LISTE VIDE", "Aucun étudiant enregistré.");
        displaySimpleFooter();
        return -1;
    }
    
    int termWidth = getTerminalWidth();
    int margin = (termWidth - 60) / 2;
    if (margin < 0) margin = 0;

    displayInfo("La liste sera triée par nom pour optimiser la recherche.");
    
    printf("\n");
    printSpaces(margin); printf("Entrer votre recherche (nom, prénom ou les deux) :\n");
    printSpaces(margin); printf("________________________________________\r");
    printSpaces(margin);
    
    char query[100];
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = '\0';
    
    // Vérifier que la query n'est pas vide
    if (query[0] == '\0') {
        printf("\n");
        displayError("ERREUR", "Veuillez entrer au moins une lettre pour rechercher.");
        displaySimpleFooter();
        return -1;
    }
    
    SearchResults *results = searchByName(management, query);
    
    if (results == NULL) {
        displayError("ERREUR", "Erreur lors de la recherche.");
        displaySimpleFooter();
        return -1;
    }
    
    if (results->count == 0) {
        printf("\n");
        displayError("NON TROUVÉ", "Aucun étudiant correspondant à votre recherche.");
        freeSearchResults(results);
        displaySimpleFooter();
        return -1;
    }
    
    if (results->count == 1) {
        int index = results->indices[0];
        displaySuccess("TROUVÉ", "1 résultat correspondant.");
        freeSearchResults(results);
        return index;
    }
    
    int selectedIndex = displaySearchResultsList(management, results);
    freeSearchResults(results);
    return selectedIndex;
}

int displaySearchResultsList(Student_Management *management, SearchResults *results) {
    clearScreen();
    displayPath("sms > menu > recherche > résultats");
    
    char header[100];
    sprintf(header, "RÉSULTATS DE RECHERCHE (%d trouvé(s))", results->count);
    displayHeader(header);
    
    int termWidth = getTerminalWidth();
    int margin = (termWidth - 60) / 2;
    if (margin < 0) margin = 0;
    
    displayInfo("Les résultats sont triés par pertinence (meilleurs en premier).");
    printf("\n");
    
    for (int i = 0; i < results->count; i++) {
        int idx = results->indices[i];
        Student *s = &management->list[idx];
        
        printSpaces(margin);
        printf(COLOR_YELLOW "%2d." COLOR_RESET " ", i + 1);
        printf(COLOR_CYAN "%s %s" COLOR_RESET, s->name, s->surname);
        printf(" - Matricule: %s - %s\n", s->id, s->option);
    }
    
    printf("\n");
    printSpaces(margin); printf(COLOR_RED "  0. ❌ Annuler" COLOR_RESET "\n");
    
    displayChoiceFooter();
    int choice = getUserChoice();
    
    if (choice == 0) {
        return -1;
    }
    
    if (choice < 1 || choice > results->count) {
        displayError("Choix invalide", "Veuillez sélectionner un numéro valide.");
        displaySimpleFooter();
        return displaySearchResultsList(management, results);
    }
    
    return results->indices[choice - 1];
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
    printSpaces(margin); printf("│ No  │   Matricule     │     Nom      │    Prénom    │ Naissance  │     Option      │\n");
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
    
    char date[11];
    getCurrentDate(date);

    displayInfo(date);

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
    printf(COLOR_GREEN);
    printSpaces(margin); printf("Âge : %d ans\n", calculateAge(s->birth_date));
    printf(COLOR_RESET);

    displaySimpleFooter();
}

void displaySettings(Student_Management *management) {
    clearScreen();    
    displayPath("sms > paramètres");
    displayHeader("PARAMÈTRES");

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 50) / 2;
    if (margin < 0) margin = 0;

    char info[100];
    sprintf(info, "Capacité actuelle : %d étudiants max", management->capacity);
    displayInfo(info);
    
    sprintf(info, "Étudiants enregistrés : %d", management->number);
    displayInfo(info);

    sprintf(info, "Auto-sauvegarde : %s", management->autoSave ? "✅ Activée" : "❌ Désactivée");
    displayInfo(info);

    printf("\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "1." COLOR_RESET " Restaurer les données\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "2." COLOR_RESET " Sauvegarder maintenant\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "3." COLOR_RESET " %s l'auto-sauvegarde\n", management->autoSave ? "Désactiver" : "Activer");
    printSpaces(margin); printf("  " COLOR_YELLOW "4." COLOR_RESET " Modifier la capacité\n");
    printSpaces(margin); printf("  " COLOR_YELLOW "5." COLOR_RESET " Statistiques détaillées\n\n");
    printSpaces(margin); printf("  " COLOR_RED    "0. ❌ Retour au menu" COLOR_RESET "\n");

    displayChoiceFooter();
    processSettingsChoice(getUserChoice(), management);
}

void processSettingsChoice(int choice, Student_Management *management) {
    int termWidth = getTerminalWidth();
    int margin = (termWidth - 50) / 2;
    if (margin < 0) margin = 0;
    
    switch (choice) {
        case 1: // Restaurer les données
            printf("\n");
            if (restoreData(management)) {
                displaySuccess("RESTAURÉ", "Les données ont été restaurées depuis le fichier.");
            } else {
                displayError("ERREUR", "Impossible de restaurer les données.");
            }
            displaySimpleFooter();
            displaySettings(management);
            break;
            
        case 2: // Sauvegarder maintenant
            saveData(management);
            displaySuccess("SAUVEGARDÉ", "Les données ont été enregistrées.");
            displaySimpleFooter();
            displaySettings(management);
            break;
            
        case 3: // Toggle auto-save
            management->autoSave = !management->autoSave;
            if (management->autoSave) {
                displaySuccess("ACTIVÉ", "L'auto-sauvegarde est maintenant activée.");
            } else {
                displayWarning("DÉSACTIVÉ", "L'auto-sauvegarde est maintenant désactivée.");
            }
            autoSaveIfEnabled(management);
            displaySimpleFooter();
            displaySettings(management);
            break;
            
        case 4: { // Modifier la capacité
            printf("\n");
            printSpaces(margin); printf("Capacité actuelle : %d\n", management->capacity);
            printSpaces(margin); printf("Nouvelle capacité (min %d) : ", management->number > 10 ? management->number : 10);
            
            int newCapacity = getUserChoice();
            if (newCapacity < management->number) {
                displayError("ERREUR", "La capacité ne peut pas être inférieure au nombre d'étudiants actuels.");
            } else if (newCapacity < 10) {
                displayError("ERREUR", "La capacité minimale est 10.");
            } else {
                Student *newList = (Student *)realloc(management->list, newCapacity * sizeof(Student));
                if (newList != NULL) {
                    management->list = newList;
                    management->capacity = newCapacity;
                    displaySuccess("MODIFIÉ", "La capacité a été mise à jour.");
                    autoSaveIfEnabled(management);
                } else {
                    displayError("ERREUR", "Impossible de redimensionner la liste.");
                }
            }
            displaySimpleFooter();
            displaySettings(management);
            break;
        }
            
        case 5: // Statistiques détaillées
            displayDetailedStats(management);
            displaySettings(management);
            break;
            
        case 0: // Retour
            displayMenu(management);
            break;
            
        default:
            displayError("Choix invalide", "Veuillez entrer un choix valide.");
            displayChoiceFooter();
            processSettingsChoice(getUserChoice(), management);
            break;
    }
}

void displayDetailedStats(Student_Management *management) {
    clearScreen();
    displayPath("sms > paramètres > statistiques");
    displayHeader("STATISTIQUES DÉTAILLÉES");

    int termWidth = getTerminalWidth();
    int margin = (termWidth - 50) / 2;
    if (margin < 0) margin = 0;

    if (management->number == 0) {
        displayWarning("AUCUNE DONNÉE", "Aucun étudiant enregistré pour afficher les statistiques.");
        displaySimpleFooter();
        return;
    }

    // Statistiques de base
    char info[100];
    sprintf(info, "Total étudiants : %d / %d", management->number, management->capacity);
    displayInfo(info);

    // Distribution par genre
    int maleCount = 0, femaleCount = 0;
    int totalAge = 0;
    
    for (int i = 0; i < management->number; i++) {
        if (management->list[i].gender == 'M') {
            maleCount++;
        } else if (management->list[i].gender == 'F') {
            femaleCount++;
        }
        totalAge += calculateAge(management->list[i].birth_date);
    }

    printf("\n");
    printSpaces(margin); printf(COLOR_CYAN "━━━ Distribution par Genre ━━━" COLOR_RESET "\n\n");
    printSpaces(margin); printf("  Hommes   : %d (%.1f%%)\n", maleCount, (float)maleCount / management->number * 100);
    printSpaces(margin); printf("  Femmes   : %d (%.1f%%)\n", femaleCount, (float)femaleCount / management->number * 100);

    // Moyenne d'âge
    printf("\n");
    printSpaces(margin); printf(COLOR_CYAN "━━━ Âge Moyen ━━━" COLOR_RESET "\n\n");
    printSpaces(margin); printf("  Âge moyen : %.1f ans\n", (float)totalAge / management->number);

    // Taux d'occupation
    printf("\n");
    printSpaces(margin); printf(COLOR_CYAN "━━━ Capacité ━━━" COLOR_RESET "\n\n");
    float occupancy = (float)management->number / management->capacity * 100;
    printSpaces(margin); printf("  Taux d'occupation : %.1f%%\n", occupancy);
    printSpaces(margin); printf("  Places restantes  : %d\n", management->capacity - management->number);

    displaySimpleFooter();
}

void displayStats(Student_Management *management) {
    printf("" COLOR_CYAN);
    printCenterText("STATISTIQUES");
    printf(COLOR_RESET "\n");

    char stat[100];
    sprintf(stat, "%d étudiants inscrits", management->number);
    printCenterText(stat);
    printf("\n");
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
            return;
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
