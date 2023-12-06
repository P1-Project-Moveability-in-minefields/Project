#include <stdio.h>
#include "RelationshipMethods.h"
#include "../Databehandling/userPreferences.h"
#include <stdlib.h>
#include "math.h"

// Should be corrected to refer to a doctrinal document.
#define MAXIMUM_SLOPE 70

double **processMatrix(WeightedMatrix matrix_array [], int array_length, int matrix_size){
    double **processed_matrix = CreateDynamicMatrix(matrix_size);
    double **current_matrix = NULL;
    for (int i = 0; i < array_length; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            for (int k = 0; k < matrix_size; ++k) {
                current_matrix = matrix_array[i].matrix;
                if (current_matrix[j][k] == -1){
                    processed_matrix[j][k] = -1;
                    continue;
                }
                processed_matrix[j][k] += matrix_array[i].weight * matrix_array[i].matrix[j][k];
            }
        }
    }
    return processed_matrix;
}

double** CreateDynamicMatrix(int size){
    double** matrix = (double**)calloc(size, sizeof(double*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (double*)calloc(size, sizeof(double));
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
    int success = 0;
    int matrix_dimensions = settings->additional_settings.size;

    for (int i = 0; i < matrix_dimensions; ++i) {
        for (int j = 0; j < matrix_dimensions; ++j) {
            if (Slope_Matrix[i][j] > MAXIMUM_SLOPE) {
                Mine_Matrix[i][j] = 0;
            }
        }
    }
}