
#include "../Databehandling/userPreferences.h"
#include "ConfigureMatrices.h"

#ifndef P1_PROJECT_RELATIONSHIPMETHODS_H
#define P1_PROJECT_RELATIONSHIPMETHODS_H

#define ROWS 3
#define COLS 3

double **process_matrix(weightedMatrix matrixArray [], int arraySize, int matrixSize);

double** create_dynamic_matrix(int size);

void print_matrix(int matrix[ROWS][COLS]);

/// Adjusts the likelihood of the Mine_Matrix based on the Slope_Matrix
///
/// \param mineMatrix Pointer to the primary matrix containing mine probability
/// \param slopeMatrix Pointer to the primary matrix containing slope degrees
/// \param settings Pointer to the primary setting struct
/// \return 1 on a success, 0 on failure, adjusts errno as necessary.
int relate_mineslope(int** mineMatrix, int** slopeMatrix, userSettings* settings);

void determine_weights(weightedMatrix matrixArray [], int arrayLength, userSettings *settings);

#endif
