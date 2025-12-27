#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "student.h"

/* ===== CREATE ===== */
void addStudent(Student_Management *mng, Student s);
void registerStudent(Student_Management *mng);

/* ===== READ ===== */
Student* getStudentById(Student_Management *mng, int id);
void selectStudent(Student_Management *mng, int id);
void getStudentInfo(Student_Management *mng, int id);

/* ===== UPDATE ===== */
void modifyStudent(Student_Management *mng, int id);
void modifyStudentField(Student *s);

/* ===== DELETE ===== */
void deleteStudentById(Student_Management *mng, int id);
void deleteAllStudents(Student_Management *mng);

#endif
