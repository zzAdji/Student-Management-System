#include <stdio.h>
#include<stdlib.h>
#include"search.h"

int search(Gestion_des_Etudiants* tableau, int matricule, int nombre){

      
   
int borne1 = 0;//borne inferieur
int borne2 = nombre-1;//borne superieure
int indexmatriculechercher = 0;// indice du matricule chercher
int milieu = 0;// milieu intervalle initialiser
   while(borne1 <= borne2){
    milieu = (borne1+borne2)/2;

    if (tableau[milieu].matricule == matricule ){
        indexmatriculechercher = milieu;
        return  indexmatriculechercher ;// retour de l'indice

        break;// fin
    }
    else if (tableau[milieu].matricule < matricule){

        borne1 = milieu + 1 ;//changement de borne inferieur

    }
      else{
        borne2 = milieu-1;//change de borne superieure

      }


   }

}