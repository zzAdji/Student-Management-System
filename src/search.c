#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/search.h"

int binarySearch(Student_Management *management, char *id){
  int nombre = management->number;
  int borne1 = 0;                 
  int borne2 = nombre - 1;        
  int index_matricule_chercher = 0; 
  int milieu = 0;               
  while (borne1 <= borne2)
  {
    milieu = (borne1 + borne2) / 2;

    if (strcmp(management->list[milieu].id, id) == 0) {
      index_matricule_chercher = milieu;
      return index_matricule_chercher; 
    } else if (strcmp(management->list[milieu].id, id) < 0) {
      borne1 = milieu + 1; 
    } else {
      borne2 = milieu - 1; 
    }
  }

  return -1;
}

int linearSearch(Student_Management *management, char *id)
{
  for (int i = 0; i < management->number; i++)
  {
    if (strcmp(management->list[i].id, id) == 0)
    {

      return i;
    }
  }

  return -1;
}

int isSorted(Student_Management *management)
{
  for (int i = 0; i < management->number - 1; i++)
  {
    if (strcmp(management->list[i].id, management->list[i + 1].id) > 0)
    {
      return 0;
    }
  }
  return 1;
}

int smartSearch(Student_Management *management, char *id)
{
  int index;

  if (isSorted(management))
  {

    index = binarySearch(management, id);
  }
  else
  {
    index = linearSearch(management, id);
  }
  return index;
}

static void toUpperCase(char *dest, const char *src, size_t size) {
    size_t i;
    for (i = 0; i < size - 1 && src[i]; i++) {
        if (src[i] >= 'a' && src[i] <= 'z') {
            dest[i] = src[i] - 32;
        } else {
            dest[i] = src[i];
        }
    }
    dest[i] = '\0';
}

static int strcmpIgnoreCase(const char *s1, const char *s2) {
    char upper1[100], upper2[100];
    toUpperCase(upper1, s1, sizeof(upper1));
    toUpperCase(upper2, s2, sizeof(upper2));
    return strcmp(upper1, upper2);
}

int isSortedByName(Student_Management *management) {
    for (int i = 0; i < management->number - 1; i++) {
        if (strcmpIgnoreCase(management->list[i].name, management->list[i + 1].name) > 0) {
            return 0;
        }
    }
    return 1;
}

int linearSearchByName(Student_Management *management, const char *name) {
    for (int i = 0; i < management->number; i++) {
        if (strcmpIgnoreCase(management->list[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int binarySearchByName(Student_Management *management, const char *name) {
    int borne1 = 0;
    int borne2 = management->number - 1;
    
    while (borne1 <= borne2) {
        int milieu = (borne1 + borne2) / 2;
        int cmp = strcmpIgnoreCase(management->list[milieu].name, name);
        
        if (cmp == 0) {
            return milieu; // Trouvé
        } else if (cmp < 0) {
            borne1 = milieu + 1;
        } else {
            borne2 = milieu - 1;
        }
    }
    return -1;
}

int smartSearchByName(Student_Management *management, const char *name) {
    if (isSortedByName(management)) {
        return binarySearchByName(management, name);
    } else {
        return linearSearchByName(management, name);
    }
}

static int calculateMatchScore(const char *text, const char *query) {
    if (query[0] == '\0') return 0;
    
    char textUpper[100], queryUpper[100];
    toUpperCase(textUpper, text, sizeof(textUpper));
    toUpperCase(queryUpper, query, sizeof(queryUpper));
    
    int score = 0;
    
    if (strstr(textUpper, queryUpper) == textUpper) {
        score += 100;
    }
    else if (strstr(textUpper, queryUpper) != NULL) {
        score += 50;
    }
    
    int queryLen = strlen(queryUpper);
    int matchCount = 0;
    char *found = strstr(textUpper, queryUpper);
    if (found != NULL) {
        matchCount = queryLen;
    } else {
        // Compter les lettres correspondantes même si pas consécutives
        for (int i = 0; queryUpper[i]; i++) {
            if (strchr(textUpper, queryUpper[i]) != NULL) {
                matchCount++;
            }
        }
    }
    score += matchCount * 10;
    
    if (strcmpIgnoreCase(text, query) == 0) {
        score += 200;
    }
    
    return score;
}

static int *g_scores_for_sort;
static int compareByScore(const void *a, const void *b) {
    int idxA = *(const int *)a;
    int idxB = *(const int *)b;
    return g_scores_for_sort[idxB] - g_scores_for_sort[idxA];
}

SearchResults* searchByName(Student_Management *management, const char *query) {
    SearchResults *results = (SearchResults *)malloc(sizeof(SearchResults));
    if (results == NULL) return NULL;
    
    results->capacity = 10;
    results->count = 0;
    results->indices = (int *)malloc(results->capacity * sizeof(int));
    results->scores = (int *)malloc(results->capacity * sizeof(int));
    if (results->indices == NULL || results->scores == NULL) {
        free(results->indices);
        free(results->scores);
        free(results);
        return NULL;
    }
    
    if (query[0] == '\0') {
        return results; 
    }
    
    extern void sortAlphabetically(Student_Management *management);
    if (!isSortedByName(management)) {
        sortAlphabetically(management);
    }
    
    char firstWord[50];
    strncpy(firstWord, query, sizeof(firstWord) - 1);
    firstWord[sizeof(firstWord) - 1] = '\0';
    char *space = strchr(firstWord, ' ');
    if (space) *space = '\0';
    
    // Essayer binarySearchByName pour trouver rapidement un point de départ
    int binaryResult = binarySearchByName(management, firstWord);
    
    if (binaryResult < 0) {
        binaryResult = linearSearchByName(management, firstWord);
    }
    
    for (int i = 0; i < management->number; i++) {
        char fullName[150];
        sprintf(fullName, "%s %s", management->list[i].name, management->list[i].surname);
        
        int scoreFullName = calculateMatchScore(fullName, query);
        int scoreName = calculateMatchScore(management->list[i].name, query);
        int scoreSurname = calculateMatchScore(management->list[i].surname, query);
        
        // Prendre le meilleur score
        int bestScore = scoreFullName;
        if (scoreName > bestScore) bestScore = scoreName;
        if (scoreSurname > bestScore) bestScore = scoreSurname;
        
        if (i == binaryResult) {
            bestScore += 50; // Bonus dichotomie
        }
        
        if (bestScore > 0) {
            // Redimensionner si nécessaire
            if (results->count >= results->capacity) {
                results->capacity *= 2;
                int *newIndices = (int *)realloc(results->indices, results->capacity * sizeof(int));
                int *newScores = (int *)realloc(results->scores, results->capacity * sizeof(int));
                if (newIndices == NULL || newScores == NULL) {
                    freeSearchResults(results);
                    return NULL;
                }
                results->indices = newIndices;
                results->scores = newScores;
            }
            results->indices[results->count] = i;
            results->scores[results->count] = bestScore;
            results->count++;
        }
    }
    
    if (results->count > 1) {
        int *sortedOrder = (int *)malloc(results->count * sizeof(int));
        if (sortedOrder != NULL) {
            for (int i = 0; i < results->count; i++) {
                sortedOrder[i] = i;
            }
            g_scores_for_sort = results->scores;
            qsort(sortedOrder, results->count, sizeof(int), compareByScore);
            
            int *newIndices = (int *)malloc(results->count * sizeof(int));
            int *newScores = (int *)malloc(results->count * sizeof(int));
            if (newIndices != NULL && newScores != NULL) {
                for (int i = 0; i < results->count; i++) {
                    newIndices[i] = results->indices[sortedOrder[i]];
                    newScores[i] = results->scores[sortedOrder[i]];
                }
                free(results->indices);
                free(results->scores);
                results->indices = newIndices;
                results->scores = newScores;
            } else {
                free(newIndices);
                free(newScores);
            }
            free(sortedOrder);
        }
    }
    
    return results;
}

void freeSearchResults(SearchResults *results) {
    if (results != NULL) {
        if (results->indices != NULL) {
            free(results->indices);
        }
        if (results->scores != NULL) {
            free(results->scores);
        }
        free(results);
    }
}
