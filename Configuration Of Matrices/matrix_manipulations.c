//
// Created by Andreas Lynnerup on 11/12/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "matrix_manipulations.h"
#include "../Bitmap/bmp_import.h"

void rotate_90_clockwise(double** matrix, int numRows, int numCols) {
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

double*** generate_list_of_matrices(int size, int numberOfMatrices) {

    char* bmpPaths[] = {
            "../Mock_Values/BMP's/soil.bmp",
            "../Mock_Values/BMP's/water_levels.bmp",
            "../Mock_Values/BMP's/vegetation.bmp",
            "../Mock_Values/BMP's/roads_and_infrastructure.bmp",
            "../Mock_Values/BMP's/steepness.bmp",
            "../Mock_Values/BMP's/mines.bmp"
    };

    /* char* bmpPaths[] = {
            "../Mock_Values/BMP's/soil2b.bmp",
            "../Mock_Values/BMP's/water2b.bmp",
            "../Mock_Values/BMP's/vegetation3b.bmp",
            "../Mock_Values/BMP's/roads3b.bmp",
            "../Mock_Values/BMP's/steepness2b.bmp",
            "../Mock_Values/BMP's/mines2b.bmp"
    }; */




    double*** listOfMatrices = (double***)malloc(numberOfMatrices * sizeof(double**));

    if (!listOfMatrices) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    // Loop through each BMP path, import the BMP, rotate it, and add it to the list

    for (int i = 0; i < numberOfMatrices; ++i) {

        // Import the BMP and rotate it
        double** matrix = import_bmp(bmpPaths[i]);
        rotate_90_clockwise(matrix, size, size);

        listOfMatrices[i] = matrix;
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