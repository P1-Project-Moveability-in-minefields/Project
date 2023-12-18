#include <stdio.h>
#include "RelationshipMethods.h"
#include "../Databehandling/userPreferences.h"
#include <stdlib.h>
#include "math.h"
#include "../Visualization/exportMatrixToFile.h"

// Should be corrected to refer to a doctrinal document.
#define MAXIMUM_SLOPE 70

double **process_matrix(weightedMatrix matrix_array[], int array_length, int matrixSize){
    double **processedMatrix = create_dynamic_matrix(matrixSize);
    double **currentMatrix = NULL;
    for (int i = 0; i < array_length; ++i) {
        currentMatrix = matrix_array[i].matrix;
        for (int j = 0; j < matrixSize; ++j) {
            for (int k = 0; k < matrixSize; ++k) {
                if (processedMatrix[j][k] == -1){
                } else if (currentMatrix[j][k] == -1){
                    processedMatrix[j][k] = -1;
                } else processedMatrix[j][k] += matrix_array[i].weight * matrix_array[i].matrix[j][k];
            }
        }
    }
    return processedMatrix;
}

void determine_weights(weightedMatrix matrix_array [], int array_length, userSettings *settings){
    double baseWeight = (double)1/array_length;

    if(matrix_array->type == mine) {
        switch (settings->priorityLevel.mineRisk) {
            case High:
                matrix_array->weight = baseWeight;
            case Medium:
                matrix_array->weight = 1.5 * baseWeight;
            case Low:
                matrix_array->weight = 5 * baseWeight;
        }
        baseWeight = (1-matrix_array->weight)/(array_length-1);
    } else matrix_array->weight = baseWeight;

    for (int i = 1; i < array_length; ++i) {
        matrix_array[i].weight = baseWeight;
    }
}

double** create_dynamic_matrix(int size){
    double** matrix = (double**)calloc(size, sizeof(double*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (double*)calloc(size, sizeof(double));
    }
    return matrix;
}

//  Til at udskrive matricen
void print_matrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int relate_mineslope(int** mineMatrix, int** slopeMatrix, userSettings* settings){
    int success = 0;
    int matrixDimensions = settings->additionalSettings.size;

    for (int i = 0; i < matrixDimensions; ++i) {
        for (int j = 0; j < matrixDimensions; ++j) {
            if (slopeMatrix[i][j] > MAXIMUM_SLOPE) {
                mineMatrix[i][j] = 0;
            }
        }
    }

    return success;
}