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









#endif
