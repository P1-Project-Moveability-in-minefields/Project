#include <stdio.h>
#include "RelationshipMethods.h"
#include "../Databehandling/userPreferences.h"
#include <stdlib.h>
#include "math.h"

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

void determine_weights(WeightedMatrix matrix_array [], int array_length, userSettings *settings){
    double base_weight = (double)1/array_length;

    for (int i = 0; i < array_length; ++i) {
        if(matrix_array->type == mine) {
            switch (settings->priority_level.mine_risk) {
                case High:
                    matrix_array->weight = base_weight;
                case Medium:
                    matrix_array->weight = 1.5 * base_weight;
                case Low:
                    matrix_array->weight = 1.75 * base_weight;
            }
            base_weight = (1-matrix_array->weight)/(array_length-1);
            continue;
        }
        matrix_array->weight = base_weight;
    }
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


