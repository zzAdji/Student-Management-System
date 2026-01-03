#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sort.h"
// creation de la fonction de tri 
void  sort(Gestion_des_Etudiants* 
tableau ,int nombre ){

  
     for (int i = 1; i < nomre; i++)
     {
       
        Gestion_des_Etudiants stud  = tableau[i];
         
         
        int j = i-1;// intialistion du compteur des cases suivantes;

        while((j>=0)&&(strcmp(stud.nom,tableau[j].nom)< 0)){


         tableau[j+1] = tableau[j];//Remplacement de la case suivante par la precedente;

         j--;

        }
       
          tableau[j+1] = stud;// positionnement de la case dans le rang;
       
       
       
       
       
       
        /* code */
     }
     

    }

    // Par ordre alphabetique;

void sortAlphabetically(Student_Management *management , int nombre){



   for (int i = 1; i < nombre; i++)
   {
     
      Student_Management stud  = management[i];
       
       
      int j = i-1;// intialistion du compteur des cases 
suivantes;

      while((j>=0)&&(strcmp(stud.matricule,management[j].
matricule)< 0)){
       management[j+1] = management[j];//Remplacement de la casesuivante par la precedente;

       j--;
      }
     
        management[j+1] = stud;// positionnement de la case dans le rang;
     


     
     
     
     
     
      /* code */
   }


}



/**
 * Tri par filière
 * 
 * @param management Pointeur vers la structure de gestion
 */
void sortByOption(Student_Management *management m, int nombre)
{
  
   for (int i = 1; i < nombre; i++)
   {
     
      Student_Management stud  = management[i];
       
       
      int j = i-1;// intialistion du compteur des cases suivantes;

      while((j>=0)&&(strcmp(stud.Option,management[j].
Option)< 0)){
       management[j+1] = management[j];//Remplacement de la casesuivante par la precedente;

       j--;
      }
     
        management[j+1] = stud;// positionnement de la case dans le rang;
     


     
     
     
     
     
      /* code */
   }
};

/**
 * Tri par matricule (pour recherche dichotomique)
 * @param management Pointeur vers la structure de gestion
 */
void sortById(Student_Management *management , int nombre){
  




   for (int i = 1; i < nombre; i++)
   {
     
      Student_Management stud  = management[i];
       
       
      int j = i-1;// intialistion du compteur des cases suivantes;

      while((j>=0)&&(strcmp(stud.matricule,management[j].matricule)< 0)){
       management[j+1] = management[j];//Remplacement de la casesuivante par la precedente;

       j--;
      }
     
        management[j+1] = stud;// positionnement de la case dans le rang;
     


     
     
     
     
     
      /* code */
   }
   
    

};