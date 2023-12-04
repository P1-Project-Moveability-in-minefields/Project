
#include "../Databehandling/userPreferences.h"

#ifndef P1_PROJECT_RELATIONSHIPMETHODS_H
#define P1_PROJECT_RELATIONSHIPMETHODS_H

#define ROWS 3
#define COLS 3

typedef struct {
    int** matrix;
    int rows;
    int cols;
} MatrixInfo;

typedef struct{
    MatrixInfo matrixInfo;
    int weight;
} WeightedMatrix;

int** ProcessHeightMapRelationships(int** overallMatrix, WeightedMatrix heightMap, userSettings settings);
int** ProcessWaterMapRelationships(int** overallMatrix, WeightedMatrix waterMap, userSettings settings);

void processMatrix(int matrix[ROWS][COLS]);

int** CreateDynamicMatrix(int rows, int cols);
void printMatrix(int matrix[ROWS][COLS]);


#endif
