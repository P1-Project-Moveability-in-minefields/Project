#include <stdio.h>
#include "RelationshipMethods.h"
#include "../Databehandling/userPreferences.h"
#include <stdlib.h>
#include "math.h"

// This should be adjusted to pull from a config file.
#define MAXIMUM_SLOPE 70

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

int Relate_MineSlope(int** Mine_Matrix, int** Slope_Matrix, userSettings* settings){
    for (int i = 0; i < settings->additional_settings.size; ++i) {
        if (*Slope_Matrix[i] > MAXIMUM_SLOPE) {
            *Mine_Matrix[i] = 0;
        }
    }
    return 1;
}