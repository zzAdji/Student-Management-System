#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"search.h"


int binarySearch(Gestion_des_Etudiants* tableau, char matricule, int nombre){

      
   
int borne1 = 0;//borne inferieur
int borne2 = nombre-1;//borne superieure
int indexmatriculechercher = 0;// indice du matricule chercher
int milieu = 0;// milieu intervalle initialiser
   while(borne1 <= borne2){
    milieu = (borne1+borne2)/2;

    if (strcmp(tableau[milieu].matricule ,matricule) == 0 ){
        indexmatriculechercher = milieu;
        return  indexmatriculechercher ;// retour de l'indice

        break;// fin
    }
    else if (strcmp(tableau[milieu].matricule ,matricule) < 0 ){

        borne1 = milieu + 1 ;//changement de borne inferieur

    }
      else{
        borne2 = milieu-1;//change de borne superieure

      }

             
   }

   return -1;
}

int linearSearch(Gestion_des_Etudiants* 
tableau, char* matricule, int 
nombre){

     

  for (int i = 0; i < nombre; i++)
  {
      if(strcmp(tableau[i].matricule,matricule) == 0){


          return i;
          break;
      }

  }
  


              return -1;


}














int isSorted(Gestion_des_Etudiants* tableau, int nombre){



    int numb = 0;
      for (int i = 0 ;i < nombre-1; i++)
      {
            
                 if(strcmp(tableau[i].matricule,tableau[i+1].matricule)>0){
                       numb = numb +1;
                          

                 }
                 else if (strcmp(tableau[i].matricule,tableau[i+1].matricule)  = < =0){
                    numb = numb -1;
 }

      if ((numb == nombre+1)|| (numb*(-1) == nombre) )
      {
        return 1 ; /* code */
      }
      else{
        return 0 ;
      }
      

}



}
int smartSearch(Gestion_des_Etudiants* tableau,char* matricule, int nombre){
int index = 0;

      if(isSorted(tableau,  nombre)) {

       index =     binarySearch(tableau,matricule , nombre);
      }
    else{
        index = linearSearch(tableau,matricule , nombre);
    }
    return index;


}
