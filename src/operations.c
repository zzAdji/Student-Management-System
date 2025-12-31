#include "../include/operations.h"

/* ===== CREATE ===== */
/**
 * Ajouter un nouvel étudiant
 * Redimensionne automatiquement si nécessaire
 * @param management Pointeur vers la structure de gestion
 * @param student Étudiant à ajouter
 * @return 1 si succès, 0 sinon
 */
int addStudent(Student_Management *management, Student student) {
    if (management == NULL) {
        return 0; // FAILURE
    }

    if (management->number >= management->capacity) {
        if (resizeManagement(management) == 0) {
            return 0;
        }
    }

    management->list[management->number] = student;
    management->number++;

    return 1; // SUCCESS
}

/* ===== READ ===== */
/**
 * Obtenir un étudiant par matricule
 * @param management Pointeur vers la structure de gestion
 * @param id Matricule recherché
 * @return Étudiant trouvé ou étudiant vide si non trouvé
 */
Student getStudent(Student_Management *management, const char *id) {
    // Créer un étudiant vide à retourner en cas d'erreur
    Student empty_student;
    memset(&empty_student, 0, sizeof(Student)); // Initialiser tous les champs à 0/vide
    strcpy(empty_student.id, "");  // ID vide pour indiquer qu'aucun étudiant n'a été trouvé
    
    // Vérifications de sécurité
    if (management == NULL) {
        printf("❌ Erreur : Pointeur de gestion invalide !\n");
        return empty_student;
    }
    
    if (management->list == NULL) {
        printf("❌ Erreur : Liste d'étudiants invalide !\n");
        return empty_student;
    }
    
    if (id == NULL) {
        printf("❌ Erreur : Matricule invalide !\n");
        return empty_student;
    }
    
    if (management->number == 0) {
        printf("ℹ️  Aucun étudiant dans la base.\n");
        return empty_student;
    }
    
    // Rechercher l'étudiant dans la liste
    for (int i = 0; i < management->number; i++) {
        if (strcmp(management->list[i].id, id) == 0) {
            // Étudiant trouvé - le retourner
            return management->list[i];
        }
    }
    
    // Étudiant non trouvé
    printf("❌ Aucun étudiant trouvé avec le matricule '%s'\n", id);
    return empty_student;
}

/**
 * Obtenir les informations d'un étudiant
 * Affiche toutes les informations détaillées
 * @param management Pointeur vers la structure de gestion
 * @param index Index de l'étudiant
 * @return 1 si trouvé, 0 sinon
 */
int getStudentInfo(Student_Management *management, int index) {
    // 1. Vérifier que le pointeur est valide
    if (management == NULL) {
        return 0;
    }

    // 2. Vérifier que l’index est dans les limites
    if (index < 0 || index >= management->number) {
        return 0;
    }

    // 3. Récupérer l’étudiant
    Student s = management->list[index];

    // 4. Afficher les informations
    printf("===== Informations de l'étudiant =====\n");
    printf("ID            : %s\n", s.id);
    printf("Nom           : %s\n", s.name);
    printf("Prénom        : %s\n", s.surname);
    printf("Date naissance: %02d/%02d/%04d\n",
           s.birth_date.day,
           s.birth_date.month,
           s.birth_date.year);
    printf("Sexe          : %c\n", s.gender);
    printf("Département   : %s\n", s.department);
    printf("Filière       : %s\n", s.option);
    printf("Région origine: %s\n", s.native_region);
    printf("=====================================\n");

    return 1; // Étudiant trouvé et affiché
}

/* ===== SELECT ===== */
/**
 * Sélectionner un étudiant interactivement
 * Demande le matricule à l'utilisateur
 * @param management Pointeur vers la structure de gestion
 * @return Index de l'étudiant ou -1 si non trouvé
 */
int selectStudent(Student_Management *management) {
    // Vérifications de sécurité
    if (management == NULL) {
        printf("❌ Erreur : Pointeur de gestion invalide !\n");
        return -1;
    }
    
    if (management->list == NULL) {
        printf("❌ Erreur : Liste d'étudiants invalide !\n");
        return -1;
    }
    
    if (management->number == 0) {
        printf("❌ Erreur : Aucun étudiant dans la base !\n");
        return -1;
    }
    
    // Demander le matricule à l'utilisateur
    char id[20];
    printf("\n=== SÉLECTION D'UN ÉTUDIANT ===\n");
    printf("Entrez le matricule de l'étudiant: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0'; // Enlever le '\n'
    
    // Rechercher l'étudiant dans la liste
    for (int i = 0; i < management->number; i++) {
        if (strcmp(management->list[i].id, id) == 0) {
            // Étudiant trouvé - Afficher ses informations
            printf("\n✅ Étudiant trouvé à l'index %d :\n", i);
            printf("========================================\n");
            printf("Matricule       : %s\n", management->list[i].id);
            printf("Nom             : %s\n", management->list[i].name);
            printf("Prénom          : %s\n", management->list[i].surname);
            printf("Date naissance  : %02d/%02d/%d\n", 
                   management->list[i].birth_date.day,
                   management->list[i].birth_date.month,
                   management->list[i].birth_date.year);
            printf("Genre           : %c\n", management->list[i].gender);
            printf("Département     : %s\n", management->list[i].department);
            printf("Filière         : %s\n", management->list[i].option);
            printf("Région          : %s\n", management->list[i].native_region);
            printf("========================================\n");
            
            return i; // Retourner l'index
        }
    }
    
    // Étudiant non trouvé
    printf("\n❌ Aucun étudiant trouvé avec le matricule '%s'\n", id);
    return -1;
}

/* ===== UPDATE ===== */
/**
 * @brief Modifie un champ spécifique d'un étudiant à un index donné
 * @param mng Pointeur vers la structure de gestion des étudiants
 * @param index Index de l'étudiant à modifier dans mng->list
 */
void modifyStudent(Student_Management *mng, int index) {
    // Vérification de la validité des paramètres
    if (mng == NULL) {
        printf("❌ Erreur : Pointeur de gestion invalide !\n");
        return;
    }
    
    if (mng->list == NULL) {
        printf("❌ Erreur : Liste d'étudiants invalide !\n");
        return;
    }
    
    if (index < 0 || index >= mng->number) {
        printf("❌ Erreur : Index invalide ! (doit être entre 0 et %d)\n", mng->number - 1);
        printf("   Nombre d'étudiants actuellement : %d\n", mng->number);
        return;
    }
    
    // Pointeur vers l'étudiant à modifier dans mng->list
    Student *s = &mng->list[index];
    
    int choice;
    
    // AFFICHAGE DES INFORMATIONS ACTUELLES
    printf("\n========================================\n");
    printf("   ÉTUDIANT À MODIFIER (Index: %d)\n", index);
    printf("========================================\n");
    printf("Matricule       : %s\n", s->id);
    printf("Nom             : %s\n", s->name);
    printf("Prénom          : %s\n", s->surname);
    printf("Date naissance  : %02d/%02d/%d\n", s->birth_date.day, s->birth_date.month, s->birth_date.year);
    printf("Genre           : %c\n", s->gender);
    printf("Département     : %s\n", s->department);
    printf("Filière         : %s\n", s->option);
    printf("Région          : %s\n", s->native_region);
    printf("========================================\n");
    
    // AFFICHAGE DU MENU
    printf("\n=== MODIFICATION D'UN ÉTUDIANT ===\n");
    printf("1. Matricule (ID)\n");
    printf("2. Nom de famille\n");
    printf("3. Prénom\n");
    printf("4. Date de naissance\n");
    printf("5. Genre (M/F)\n");
    printf("6. Département d'études\n");
    printf("7. Filière d'études\n");
    printf("8. Région d'origine\n");
    printf("0. Annuler\n");
    printf("===================================\n");
    printf("Votre choix: ");
    char choice_str[10];
    fgets(choice_str, sizeof(choice_str), stdin);
    choice_str[strcspn(choice_str, "\n")] = '\0';
    int choice = atoi(choice_str);
    getchar(); // Consommer le '\n' restant
    
    // TRAITEMENT DU CHOIX
    switch (choice) {
        case 1: // Matricule
            printf("\nMatricule actuel: %s\n", s->id);
            printf("Nouveau matricule: ");
            fgets(s->id, sizeof(s->id), stdin);
            s->id[strcspn(s->id, "\n")] = '\0';
            printf("✅ Matricule modifié avec succès !\n");
            break;
            
        case 2: // Nom de famille
            printf("\nNom actuel: %s\n", s->name);
            printf("Nouveau nom de famille: ");
            fgets(s->name, sizeof(s->name), stdin);
            s->name[strcspn(s->name, "\n")] = '\0';
            printf("✅ Nom modifié avec succès !\n");
            break;
            
        case 3: // Prénom
            printf("\nPrénom actuel: %s\n", s->surname);
            printf("Nouveau prénom: ");
            fgets(s->surname, sizeof(s->surname), stdin);
            s->surname[strcspn(s->surname, "\n")] = '\0';
            printf("✅ Prénom modifié avec succès !\n");
            break;
            
        case 4: // Date de naissance
             printf("\nDate actuelle: %02d/%02d/%d\n", s->birth_date.day, s->birth_date.month, s->birth_date.year);
            int valid = 0;
            while (!valid) {
                char date_str[20];
                printf("Nouvelle date de naissance (jj mm aaaa): ");
                fgets(date_str, sizeof(date_str), stdin);
                date_str[strcspn(date_str, "\n")] = '\0';
                if (sscanf(date_str, "%d %d %d", &s->birth_date.day, &s->birth_date.month, &s->birth_date.year) == 3) {
                    if (s->birth_date.day >= 1 && s->birth_date.day <= 31 &&
                        s->birth_date.month >= 1 && s->birth_date.month <= 12 &&
                        s->birth_date.year >= 1900 && s->birth_date.year <= 2024) {
                        valid = 1;
                    } else {
                        printf("❌ Date invalide ! Réessayez.\n");
                    }
                 } else {
                    printf("❌ Format invalide ! Réessayez.\n");
                }
            }
            break;
            
        case 5: // Genre
            printf("\nGenre actuel: %c\n", s->gender);
            valid = 0;
            while (!valid) {
                char gender_str[10];
                printf("Nouveau genre (M/F): ");
                fgets(gender_str, sizeof(gender_str), stdin);
                gender_str[strcspn(gender_str, "\n")] = '\0';
                if (gender_str[0] == 'm' || gender_str[0] == 'M') {
                    s->gender = 'M';
                    valid = 1;
                } else if (gender_str[0] == 'f' || gender_str[0] == 'F') {
                    s->gender = 'F';
                    valid = 1;
                } else {
                    printf("❌ Genre invalide ! Entrez M ou F.\n");
                }
            }
            break;
            
        case 6: // Département
            printf("\nDépartement actuel: %s\n", s->department);
            printf("Nouveau département: ");
            fgets(s->department, sizeof(s->department), stdin);
            s->department[strcspn(s->department, "\n")] = '\0';
            printf("✅ Département modifié avec succès !\n");
            break;
            
        case 7: // Filière
            printf("\nFilière actuelle: %s\n", s->option);
            printf("Nouvelle filière: ");
            fgets(s->option, sizeof(s->option), stdin);
            s->option[strcspn(s->option, "\n")] = '\0';
            printf("✅ Filière modifiée avec succès !\n");
            break;
            
        case 8: // Région d'origine
            printf("\nRégion actuelle: %s\n", s->native_region);
            printf("Nouvelle région d'origine: ");
            fgets(s->native_region, sizeof(s->native_region), stdin);
            s->native_region[strcspn(s->native_region, "\n")] = '\0';
            printf("✅ Région modifiée avec succès !\n");
            break;
            
        case 0: // Annuler
            printf("❌ Modification annulée.\n");
            break;
            
        default:
            printf("❌ Choix invalide !\n");
            break;
    }
    
    // Affichage de confirmation
    if (choice >= 1 && choice <= 8) {
        printf("\n📊 Statistiques: %d/%d étudiants dans la base\n", mng->number, mng->capacity);
    }
}

/* ===== DELETE ===== */
/**
 * Supprimer un étudiant
 * Décale les éléments pour combler le vide
 * @param management Pointeur vers la structure de gestion
 * @param index Index de l'étudiant à supprimer
 * @return 1 si supprimé, 0 sinon
 */

int deleteStudent(Student_Management *management, int index) {
    // Vérifications de sécurité
    if (management == NULL) {
        printf("❌ Erreur : Pointeur de gestion invalide !\n");
        return 0;
    }
    
    if (management->list == NULL) {
        printf("❌ Erreur : Liste d'étudiants invalide !\n");
        return 0;
    }
    
    if (management->number == 0) {
        printf("❌ Erreur : Aucun étudiant à supprimer !\n");
        return 0;
    }
    
    if (index < 0 || index >= management->number) {
        printf("❌ Erreur : Index invalide ! (doit être entre 0 et %d)\n", management->number - 1);
        return 0;
    }
    
    // Afficher l'étudiant qui va être supprimé
    printf("\n🗑️  Suppression de l'étudiant :\n");
    printf("   Matricule : %s\n", management->list[index].id);
    printf("   Nom       : %s %s\n", management->list[index].name, management->list[index].surname);
    
    // ÉTAPE 1 : Décaler tous les étudiants après l'index vers la gauche
    // Exemple : 1-2-3-4-5 (supprimer index 2)
    //        -> 1-2-4-4-5 (copier index 3 vers 2)
    //        -> 1-2-4-5-5 (copier index 4 vers 3)
    for (int i = index; i < management->number - 1; i++) {
        management->list[i] = management->list[i + 1];
    }
    
    // ÉTAPE 2 : Diminuer le nombre d'étudiants
    management->number--;
    
    // ÉTAPE 3 : Réduire la capacité si nécessaire (optimisation mémoire)
    // On réduit seulement si le nombre d'étudiants est très inférieur à la capacité
    // Par exemple, si on utilise moins de 50% de la capacité et qu'on a au moins 10 places
    if (management->number > 0 && 
        management->number < management->capacity / 2 && 
        management->capacity > 10) {
        
        int new_capacity = management->capacity / 2;
        
        // Réallouer avec la nouvelle capacité réduite
        Student *new_list = (Student*)realloc(management->list, new_capacity * sizeof(Student));
        
        if (new_list != NULL) {
            management->list = new_list;
            management->capacity = new_capacity;
            printf("💾 Mémoire optimisée : capacité réduite à %d\n", new_capacity);
        }
        // Si realloc échoue, on garde l'ancienne liste (pas grave, juste moins optimal)
    }
    
    printf("✅ Étudiant supprimé avec succès !\n");
    printf("📊 Nombre d'étudiants restants : %d/%d\n", management->number, management->capacity);
    
    return 1;
}


/**
 * @brief Supprime tous les étudiants de la base
 * @param management Pointeur vers la structure de gestion
 * @return Nombre d'étudiants supprimés
 */
int deleteAllStudents(Student_Management *management) {
    // Vérifications de sécurité
    if (management == NULL) {
        printf("❌ Erreur : Pointeur de gestion invalide !\n");
        return 0;
    }
    
    if (management->list == NULL) {
        printf("❌ Erreur : Liste d'étudiants invalide !\n");
        return 0;
    }
    
    if (management->number == 0) {
        printf("ℹ️  La base est déjà vide.\n");
        return 0;
    }
    
    // Sauvegarder le nombre d'étudiants avant suppression
    int total_students = management->number;
    
    // Confirmation de suppression
    printf("\n⚠️  ⚠️  ⚠️  ATTENTION ⚠️  ⚠️  ⚠️\n");
    printf("Vous allez supprimer TOUS les %d étudiants de la base !\n", total_students);
    printf("Cette action est IRRÉVERSIBLE !\n");
    printf("=========================================\n");
    printf("Confirmer la suppression ? (tapez 'OUI' en majuscules): ");
    
    char confirm[10];
    fgets(confirm, sizeof(confirm), stdin);
    confirm[strcspn(confirm, "\n")] = '\0';
    
    if (strcmp(confirm, "OUI") != 0) {
        printf("❌ Suppression annulée.\n");
        return 0;
    }
    
    // Afficher les étudiants qui vont être supprimés (optionnel)
    printf("\n🗑️  Suppression en cours...\n");
    for (int i = 0; i < management->number; i++) {
        printf("  ➤ %s %s (ID: %s)\n", 
               management->list[i].name, 
               management->list[i].surname,
               management->list[i].id);
    }
    
    // Libérer la mémoire de l'ancienne liste
    free(management->list);
    
    // Réinitialiser la structure
    management->number = 0;
    management->capacity = 10; // Capacité initiale par défaut
    
    // Allouer une nouvelle liste vide
    management->list = (Student*)malloc(management->capacity * sizeof(Student));
    
    if (management->list == NULL) {
        printf("❌ Erreur critique : Échec de réallocation mémoire !\n");
        management->capacity = 0;
        management->number = 0;
        return total_students;
    }
    
    // Affichage du résumé
    printf("\n✅ Suppression terminée avec succès !\n");
    printf("📊 %d étudiant(s) supprimé(s)\n", total_students);
    printf("📊 Base de données réinitialisée (capacité: %d)\n", management->capacity);
    printf("📊 Mémoire libérée et réallouée\n");
    
    return total_students;
}
