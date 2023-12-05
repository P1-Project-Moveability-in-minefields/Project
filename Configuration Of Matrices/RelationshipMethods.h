
#include "../Databehandling/userPreferences.h"

#ifndef P1_PROJECT_RELATIONSHIPMETHODS_H
#define P1_PROJECT_RELATIONSHIPMETHODS_H

#define ROWS 3
#define COLS 3

void processMatrix(int matrix[ROWS][COLS]);

int** CreateDynamicMatrix(int rows, int cols);
void printMatrix(int matrix[ROWS][COLS]);


#endif
