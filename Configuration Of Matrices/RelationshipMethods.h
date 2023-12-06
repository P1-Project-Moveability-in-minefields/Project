
#include "../Databehandling/userPreferences.h"
#include "ConfigureMatrices.h"

#ifndef P1_PROJECT_RELATIONSHIPMETHODS_H
#define P1_PROJECT_RELATIONSHIPMETHODS_H

#define ROWS 3
#define COLS 3

void processMatrix(int matrix[ROWS][COLS]);

int** CreateDynamicMatrix(int rows, int cols);
void printMatrix(int matrix[ROWS][COLS]);

/// Adjusts the likelihood of the Mine_Matrix based on the Slope_Matrix
///
/// \param Mine_Matrix Pointer to the primary matrix containing mine probability
/// \param Slope_Matrix Pointer to the primary matrix containing slope degrees
/// \param settings Pointer to the primary setting struct
/// \return 1 on a success, 0 on failure, adjusts errno as necessary.
int Relate_MineSlope(int** Mine_Matrix, int** Slope_Matrix, userSettings* settings);



#endif
