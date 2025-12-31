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

        while((strcmp(stud.nom,tableau[j].nom))&&(j>=0)){


         tableau[j+1] = tableau[j];//Remplacement de la case suivante par la precedente;

         j--;

        }
       
          tableau[j+1] = stud;// positionnement de la case dans le rang;
       
       
       
       
       
       
        /* code */
     }
     







}