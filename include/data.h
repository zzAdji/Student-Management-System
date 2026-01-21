#ifndef DATA_H
#define DATA_H

#include "student.h"

int loadData(Student_Management *management);
void saveData(Student_Management *management);

/** Restaure les données depuis le fichier (reload) */
int restoreData(Student_Management *management);

/** Sauvegarde automatiquement si autoSave est activé */
void autoSaveIfEnabled(Student_Management *management);

#endif