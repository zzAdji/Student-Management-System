#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/search.h"


int binarySearch(Student_Management *management,  char* id){
      

      
int nombre = management->number;   
int borne1 = 0;//borne inferieur
int borne2 = nombre-1;//borne superieure
int indexmatriculechercher = 0;// indice du matricule chercher
int milieu = 0;// milieu intervalle initialiser
   while(borne1 <= borne2){
    milieu = (borne1+borne2)/2;

    if (strcmp(management->list[milieu].id ,id) == 0 ){
        indexmatriculechercher = milieu;
        return  indexmatriculechercher ;// retour de l'indice

    }
    else if (strcmp(management->list[milieu].id ,id) < 0 ){

        borne1 = milieu + 1 ;//changement de borne inferieur

    }
      else{
        borne2 = milieu-1;//change de borne superieure

      }

             
   }

   return -1;
}

int linearSearch(Student_Management *management, char *id){
      

     
  int nombre = 0;
  nombre = management->number;    
  for (int i = 0; i < nombre; i++)
  {
      if(strcmp(management->list[i].id,id) == 0){


          return i;
          
      }

  }
  


              return -1;


}














int isSorted(Student_Management* management){

      int nombre = 0;
      nombre = management->number;

    int numb = 0;
      for (int i = 0 ;i < nombre-1; i++)
      {
            
                 if(strcmp(management->list[i].id,management->list[i+1].id)>0){
                       
                    return 0;
                          

                 }
                

    
        return 1 ;
      
      

}



}
int smartSearch(Student_Management* management,char* id){
int index = 0;
      int nombre = 0;
      nombre = management->number;

      if(isSorted(management)) {

       index = binarySearch(management,id);
      }
    else{
        index = linearSearch(management,id)   ;}
    return index;


}
