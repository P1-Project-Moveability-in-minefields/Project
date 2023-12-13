
#include "../Databehandling/userPreferences.h"
#include "ConfigureMatrices.h"

#ifndef P1_PROJECT_RELATIONSHIPMETHODS_H
#define P1_PROJECT_RELATIONSHIPMETHODS_H

#define ROWS 3
#define COLS 3

double **processMatrix(weighted_matrix matrix_array [], int array_size, int matrix_size);

double** CreateDynamicMatrix(int size);
void printMatrix(int matrix[ROWS][COLS]);

/// Adjusts the likelihood of the Mine_Matrix based on the Slope_Matrix
///
/// \param Mine_Matrix Pointer to the primary matrix containing mine probability
/// \param Slope_Matrix Pointer to the primary matrix containing slope degrees
/// \param settings Pointer to the primary setting struct
/// \return 1 on a success, 0 on failure, adjusts errno as necessary.
int Relate_MineSlope(int** Mine_Matrix, int** Slope_Matrix, userSettings* settings);
void determine_weights(weighted_matrix matrix_array [], int array_length, userSettings *settings);

#endif
