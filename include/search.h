#ifndef SEARCH
#define SEARCH
#include"student.h"
/// @brief 
/// @param  management Pointeur vers la structure de gestion
/// @param nombre number of student
int binarySearch(Student_Management* management , char* id);// prototype de la fonction de tri;


/// @brief 
/// @param  management Pointeur vers la structure de gestion
/// @param nombre number of student

int linearSearch(Student_Management* management, char* id);

/// @brief 
/// @param  management Pointeur vers la structure de gestion
/// @param nombre number of student
int isSorted(Student_Management* management);

/// @brief 
/// @param  management Pointeur vers la structure de gestion
/// @param nombre number of student
int smartSearch(Student_Management* management,char* id);

/**
 * @struct SearchResults
 * @brief Structure pour stocker les résultats de recherche avec scores
 */
typedef struct {
    int *indices;       // Tableau des indices des étudiants trouvés
    int *scores;        // Score de précision pour chaque résultat
    int count;          // Nombre de résultats
    int capacity;       // Capacité du tableau
} SearchResults;

/* ===== Recherche par Nom (pour recherche dichotomique) ===== */

/**
 * Vérifie si la liste est triée par nom (ordre alphabétique)
 * @param management Pointeur vers la structure de gestion
 * @return 1 si triée, 0 sinon
 */
int isSortedByName(Student_Management *management);

/**
 * Recherche linéaire par nom
 * @param management Pointeur vers la structure de gestion
 * @param name Nom à rechercher
 * @return Index du premier étudiant trouvé ou -1
 */
int linearSearchByName(Student_Management *management, const char *name);

/**
 * Recherche dichotomique par nom (liste doit être triée par nom)
 * @param management Pointeur vers la structure de gestion
 * @param name Nom à rechercher
 * @return Index d'un étudiant trouvé ou -1
 */
int binarySearchByName(Student_Management *management, const char *name);

/**
 * Recherche intelligente par nom (choisit entre dichotomie et linéaire)
 * @param management Pointeur vers la structure de gestion
 * @param name Nom à rechercher
 * @return Index du premier étudiant trouvé ou -1
 */
int smartSearchByName(Student_Management *management, const char *name);

/**
 * Recherche des étudiants par nom/prénom avec score de précision
 * @param management Pointeur vers la structure de gestion
 * @param query Texte à rechercher (dans nom ET prénom)
 * @return Pointeur vers SearchResults trié par score décroissant
 */
SearchResults* searchByName(Student_Management *management, const char *query);

/**
 * Libère la mémoire allouée pour les résultats de recherche
 * @param results Pointeur vers les résultats à libérer
 */
void freeSearchResults(SearchResults *results);

#endif
