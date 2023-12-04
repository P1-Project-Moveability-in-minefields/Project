#include <stdio.h>
#include "RelationshipMethods.h"
#include "../Databehandling/userPreferences.h"
#include "malloc.h"
#include "math.h"

int** ProcessHeightMapRelationships(int** overallMatrix, WeightedMatrix heightMap, userSettings settings){
    if (heightMap.matrixInfo.matrix == NULL){ // Check for bad data
        return overallMatrix;
    }
    if (overallMatrix == NULL){ // Check for bad data
        overallMatrix = CreateDynamicMatrix(heightMap.matrixInfo.rows, heightMap.matrixInfo.cols);
    }

    for (int i = 0; i < heightMap.matrixInfo.rows; ++i) {
        for (int j = 0; j < heightMap.matrixInfo.cols; ++j) {
            if (settings.prioritizeCover){
                // Check neighbors and calculate cost
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int ni = i + x;
                        int nj = j + y;

                        // Check if the neighbor is within bounds
                        if (ni >= 0 && ni < heightMap.matrixInfo.rows && nj >= 0 && nj < heightMap.matrixInfo.cols) {
                            // Calculate the cost based on the elevation difference
                            overallMatrix[i][j] += heightMap.weight * ( abs(heightMap.matrixInfo.matrix[i][j] - heightMap.matrixInfo.matrix[ni][nj]) );
                        }
                    }
                }
            }
            else {
                // Don't know what to do if cover isn't prioritized, approach here is that lower height is better.
                overallMatrix[i][j] += heightMap.weight * heightMap.matrixInfo.matrix[i][j];
            }
        }
    }
    return overallMatrix;
}

int** ProcessWaterMapRelationships(int** overallMatrix, WeightedMatrix waterMap, userSettings settings){
    if (waterMap.matrixInfo.matrix == NULL){ // Check for bad data
        return overallMatrix;
    }
    if (overallMatrix == NULL){ // Check for bad data
        overallMatrix = CreateDynamicMatrix(waterMap.matrixInfo.rows, waterMap.matrixInfo.cols);
    }

    for (int i = 0; i < waterMap.matrixInfo.rows; ++i) {
        for (int j = 0; j < waterMap.matrixInfo.cols; ++j) {
            if (waterMap.matrixInfo.matrix[i][j] > 0) { // Is there water here?
                int cost = waterMap.weight * waterMap.matrixInfo.matrix[i][j]; // Calculate cost
                if (settings.isWaterPassable) {
                    overallMatrix[i][j] += cost; // The more water the worse it is.
                } else {
                    overallMatrix[i][j] += 100 * cost; // If we can't cross water then we don't want to so 100 times worse.
                }
            }
            else{
                // No water no change
            }
        }
    }
    return overallMatrix;
}


void processMatrix(int matrix[ROWS][COLS]) {
    // Tjek om tilknyttet data er tilstede (f.eks. vanddybde)
    int waterDepth;

    printf("Indtast vanddybden: ");
    scanf("%d", &waterDepth);

    if (waterDepth > 0) {
        // Aktiver en for-loop, hvis water depth > 0
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                // Check hver celledybde og påvirk data om nødvendigt
                if (matrix[i][j] <= waterDepth) {
                    matrix[i][j] = 0;  // Opdater eller overskriv cellens værdi til 0
                } else {
                    matrix[i][j] = 1;  // Opdater eller overskriv cellens værdi til 1
                }
            }
        }
    }
}

int** CreateDynamicMatrix(int rows, int cols){
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;  // Initialize to zero or other default value
        }
    }
    return matrix;
}

//  Til at udskrive matricen
void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


