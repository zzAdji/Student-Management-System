#include "../include/operations.h"

/* ===== CREATE ===== */
void addStudent(Student_Management *mng, Student s) {
    if (mng->size >= mng->capacity) {
        resizeManagement(mng);
    }
    mng->students[mng->size++] = s;
}

void registerStudent(Student_Management *mng) {
    Student s;
    s.id = mng->size + 1;

    printf("Nom: ");
    scanf("%s", s.name);

    printf("Prénom: ");
    scanf("%s", s.lastname);

    printf("Date de naissance (jj mm aaaa): ");
    scanf("%d %d %d",
          &s.birthDate.day,
          &s.birthDate.month,
          &s.birthDate.year);

    addStudent(mng, s);
}

/* ===== READ ===== */
Student* getStudentById(Student_Management *mng, int id) {
    for (int i = 0; i < mng->size; i++) {
        if (mng->students[i].id == id) {
            return &mng->students[i];
        }
    }
    return NULL;
}

void selectStudent(Student_Management *mng, int id) {
    Student *s = getStudentById(mng, id);
    if (s) viewStudent(*s);
    else printf("Étudiant non trouvé\n");
}

void getStudentInfo(Student_Management *mng, int id) {
    selectStudent(mng, id);
}

/* ===== UPDATE ===== */
void modifyStudentField(Student *s) {
    printf("Nouveau nom: ");
    scanf("%s", s->name);
}

void modifyStudent(Student_Management *mng, int id) {
    Student *s = getStudentById(mng, id);
    if (s) modifyStudentField(s);
}

/* ===== DELETE ===== */
void deleteStudentById(Student_Management *mng, int id) {
    for (int i = 0; i < mng->size; i++) {
        if (mng->students[i].id == id) {
            for (int j = i; j < mng->size - 1; j++) {
                mng->students[j] = mng->students[j + 1];
            }
            mng->size--;
            return;
        }
    }
}

void deleteAllStudents(Student_Management *mng) {
    mng->size = 0;
}
