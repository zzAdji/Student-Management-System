#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/student.h"

// Tri Par ordre alphabetique;

void sortAlphabetically(Student_Management *management)
{
   for (int i = 1; i < management->number; i++)
   {

      Student stud = management->list[i];

      int j = i - 1; // intialistion du compteur des cases suivantes;

      while ((j >= 0) && (strcmp(stud.name, management->list[j].name) < 0))
      {
         management->list[j + 1] = management->list[j]; // Remplacement de la casesuivante par la precedente;

         j--;
      }

      management->list[j + 1] = stud; // positionnement de la case dans le rang;
   }
}
/**
 * Tri par filière
 *
 * @param management Pointeur vers la structure de gestion
 */
void sortByOption(Student_Management *management)
{
   int nombre = 0;

   nombre = management->number;

   for (int i = 1; i < nombre; i++)
   {

      Student stud = management->list[i];

      int j = i - 1; // intialistion du compteur des cases suivantes;

      while ((j >= 0) && (strcmp(stud.option, management->list[j].option) < 0))
      {
         management->list[j + 1] = management->list[j]; // Remplacement de la casesuivante par la precedente;

         j--;
      }

      management->list[j + 1] = stud; // positionnement de la case dans le rang;

      /* code */
   }
};

/**
 * Tri par matricule (pour recherche dichotomique)
 * @param management Pointeur vers la structure de gestion
 */
void sortById(Student_Management *management)
{

   int nombre = 0;

   nombre = management->number;

   for (int i = 1; i < nombre; i++)
   {

      Student stud = management->list[i];

      int j = i - 1; // intialistion du compteur des cases suivantes;

      while ((j >= 0) && (strcmp(stud.id, management->list[j].id) < 0))
      {
         management->list[j + 1] = management->list[j]; // Remplacement de la casesuivante par la precedente;

         j--;
      }

      management->list[j + 1] = stud; // positionnement de la case dans le rang;

      /* code */
   }
};
