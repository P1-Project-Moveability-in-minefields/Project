
#include "../Databehandling/userPreferences.h"
#include "ConfigureMatrices.h"

#ifndef P1_PROJECT_RELATIONSHIPMETHODS_H
#define P1_PROJECT_RELATIONSHIPMETHODS_H

#define ROWS 3
#define COLS 3

void processMatrix(WeightedMatrix matrix_array []);

int** CreateDynamicMatrix(int size);
void printMatrix(int matrix[ROWS][COLS]);


#endif
