//
// Created by Andreas Lynnerup on 11/12/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "matrix_manipulations.h"
#include "../Bitmap/bmp_import.h"

void rotate90Clockwise(double** matrix, int numRows, int numCols) {
    // Transpose the matrix
    for (int i = 0; i < numRows; ++i) {
        for (int j = i + 1; j < numCols; ++j) {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Reverse the order of rows
    for (int i = 0; i < numRows / 2; ++i) {
        for (int j = 0; j < numCols; ++j) {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[numRows - 1 - i][j];
            matrix[numRows - 1 - i][j] = temp;
        }
    }
}

void flipHorizontally(double** matrix, int numRows, int numCols) {
    // Reverse the order of columns
    for (int j = 0; j < numCols / 2; ++j) {
        for (int i = 0; i < numRows; ++i) {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[i][numCols - 1 - j];
            matrix[i][numCols - 1 - j] = temp;
        }
    }
}

double*** generateListOfMockMatrices(int size, int numberOfMatrices) {

    // Create an array of matrix file paths
    char* bmpPaths[] = {
            "../Mock_Values/BMP's/soil.bmp",
            "../Mock_Values/BMP's/water_levels.bmp",
            "../Mock_Values/BMP's/vegetation.bmp",
            "../Mock_Values/BMP's/roads_and_infrastructure.bmp",
            "../Mock_Values/BMP's/steepness.bmp",
            "../Mock_Values/BMP's/mines.bmp"
    };

    // Allocate memory for the list of matrices
    double*** listOfMatrices = (double***)malloc(numberOfMatrices * sizeof(double**));

    if (!listOfMatrices) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    // Loop through each BMP path, import the BMP, rotate it, and add it to the list
    for (int i = 0; i < numberOfMatrices; ++i) {
        // Allocate memory for the matrix
        listOfMatrices[i] = (double**)malloc(size * sizeof(double*));

        if (!listOfMatrices[i]) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < size; ++j) {
            listOfMatrices[i][j] = (double*)malloc(size * sizeof(double));

            if (!listOfMatrices[i][j]) {
                perror("Memory allocation error");
                exit(EXIT_FAILURE);
            }
        }

        // Import the BMP and rotate it
        double** matrix = import_bmp(bmpPaths[i]);
        rotate90Clockwise(matrix, size, size);

        // Copy the rotated matrix to the list
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                listOfMatrices[i][j][k] = matrix[j][k];
            }
        }

        // Free the memory allocated for the imported matrix
        for (int j = 0; j < size; ++j) {
            free(matrix[j]);
        }
        free(matrix);
    }

    return listOfMatrices;
}


/*
 *
 *     double** soil_array = import_bmp("../Mock_Values/BMP's/soil.bmp");
    rotate90Clockwise(soil_array, 100, 100);

    double** water_array = import_bmp("../Mock_Values/BMP's/water_levels.bmp");
    rotate90Clockwise(water_array, 100, 100);

    double** vegetation_array = import_bmp("../Mock_Values/BMP's/vegetation.bmp");
    rotate90Clockwise(vegetation_array, 100, 100);

    double** road_array = import_bmp("../Mock_Values/BMP's/roads_and_infrastructure.bmp");
    rotate90Clockwise(road_array, 100, 100);

    double** steepness_array = import_bmp("../Mock_Values/BMP's/steepness.bmp");
    rotate90Clockwise(steepness_array, 100, 100);

    double** mine_array = import_bmp("../Mock_Values/BMP's/mines.bmp");
    rotate90Clockwise(mine_array, 100, 100);
 *
 * */