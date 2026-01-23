#ifndef CONFIG_H
#define CONFIG_H

// Codes de réinitialisation
#define COLOR_RESET   "\033[0m"

// Couleurs de texte simples
#define COLOR_BLACK   "\033[0;30m"
#define COLOR_RED     "\033[0;31m"
#define COLOR_GREEN   "\033[0;32m"
#define COLOR_YELLOW  "\033[0;33m"
#define COLOR_BLUE    "\033[0;34m"
#define COLOR_MAGENTA "\033[0;35m"
#define COLOR_CYAN    "\033[0;36m"
#define COLOR_WHITE   "\033[0;37m"

// Couleurs de texte en gras
#define COLOR_BOLD_BLACK   "\033[1;30m"
#define COLOR_BOLD_RED     "\033[1;31m"
#define COLOR_BOLD_GREEN   "\033[1;32m"
#define COLOR_BOLD_YELLOW  "\033[1;33m"
#define COLOR_BOLD_BLUE    "\033[1;34m"
#define COLOR_BOLD_MAGENTA "\033[1;35m"
#define COLOR_BOLD_CYAN    "\033[1;36m"
#define COLOR_BOLD_WHITE   "\033[1;37m"

// Tailles maximales oiur les champs de l'étudiant
#define MAX_MATRICULE_LEN 20
#define MAX_NOM_LEN 50
#define MAX_PRENOM_LEN 50
#define MAX_DATE_NAISSANCE_LEN 11
#define MAX_SEXE_LEN 2
#define MAX_DEPARTEMENT_LEN 50
#define MAX_FILIERE_LEN 50
#define MAX_REGION_LEN 50

// taille pour les buffers d'entree temporaires
#define INITIAL_DB_CAPACITY 0
#define DB_GROWTH_FACTOR 2

// Nombre maximum d'options par département
#define MAX_OPTIONS_PER_DEPT 10
#define NUM_DEPARTMENTS 5

// Largeurs de colonnes pour l'affichage en tableau
#define ID_WIDTH 15
#define NAME_WIDTH 12
#define SURNAME_WIDTH 12
#define OPTION_WIDTH 15

#endif
