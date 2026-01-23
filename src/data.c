#include "../include/data.h"
#include "../include/utils.h"
#include "../include/config.h"
#include "stdio.h"
#include "stdlib.h"

int loadData(Student_Management *management) {
    FILE *file = fopen("data/students.dat", "rb");
    if (file == NULL) {
        return 0;
    }

    int capacity, number, autoSave;

    fread(&capacity, sizeof(int), 1, file);
    fread(&number, sizeof(int), 1, file);
    
    if (fread(&autoSave, sizeof(int), 1, file) != 1) {
        autoSave = 1;
    }

    if (management->list != NULL) {
        free(management->list);
    }

    management->capacity = capacity;
    management->number = number;
    management->autoSave = autoSave;
    management->list = (Student *)malloc(capacity * sizeof(Student));

    if (management->list == NULL) {
        fprintf(stderr, "Erreur lors de l'allocation mémoire!\n");
        fclose(file);
        return 0;
    }

    // Lire les données
    fread(management->list, sizeof(Student), number, file);

    fclose(file);
    printf("\n" COLOR_GREEN);
    printCenterText("Données Chargées avec succès!\n");
    printf(COLOR_RESET "\n");

    return 1;
}

void saveData(Student_Management *management) {
    FILE *file = fopen("data/students.dat", "wb");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier!");
        return;
    }

    fwrite(&management->capacity, sizeof(int), 1, file);
    fwrite(&management->number, sizeof(int), 1, file);
    fwrite(&management->autoSave, sizeof(int), 1, file);

    fwrite(management->list, sizeof(Student), management->number, file);

    fclose(file);
    printf("\n" COLOR_GREEN);
    printCenterText("Données enregistrées avec succès!\n");
    printf(COLOR_RESET "\n");
}

int restoreData(Student_Management *management) {
    return loadData(management);
}

void autoSaveIfEnabled(Student_Management *management) {
    if (management->autoSave) {
        FILE *file = fopen("data/students.dat", "wb");
        if (file == NULL) {
            return;
        }

        fwrite(&management->capacity, sizeof(int), 1, file);
        fwrite(&management->number, sizeof(int), 1, file);
        fwrite(&management->autoSave, sizeof(int), 1, file);
        fwrite(management->list, sizeof(Student), management->number, file);

        fclose(file);
    }
}
