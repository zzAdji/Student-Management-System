#ifndef SEARCH
#define SEARCH


int binarySearch(Gestion_des_Etudiants* tableau , char matricule,
int nombre);// prototype de la fonction de tri;

int linearSearch
(Gestion_des_Etudiants* tableau, char* matricule, int nombre);


int isSorted(Gestion_des_Etudiants* tableau, int nombre);


int smartSearch(Gestion_des_Etudiants* tableau,char* matricule, int nombre);


#endif