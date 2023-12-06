
#include "../Databehandling/userPreferences.h"
#include "ConfigureMatrices.h"

#ifndef P1_PROJECT_RELATIONSHIPMETHODS_H
#define P1_PROJECT_RELATIONSHIPMETHODS_H

#define ROWS 3
#define COLS 3

double **processMatrix(WeightedMatrix matrix_array [], int array_size, int matrix_size);

double** CreateDynamicMatrix(int size);
void printMatrix(int matrix[ROWS][COLS]);


#endif
