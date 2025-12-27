#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>

/* ===== Structure Date ===== */
typedef struct {
    int day;
    int month;
    int year;
} Date;

/* ===== Structure Student ===== */
typedef struct {
    int id;
    char name[50];
    char lastname[50];
    Date birthDate;
} Student;

/* ===== Structure Student Management ===== */
typedef struct {
    Student *students;
    int size;
    int capacity;
} Student_Management;

/* ===== Gestion mémoire ===== */
void initManagement(Student_Management *mng, int capacity);
void freeManagement(Student_Management *mng);
void resizeManagement(Student_Management *mng);

/* ===== Affichage ===== */
void viewStudent(Student s);
void viewAllStudents(Student_Management *mng);

/* ===== Comparaison ===== */
int compareStudentById(Student s, int id);

#endif
