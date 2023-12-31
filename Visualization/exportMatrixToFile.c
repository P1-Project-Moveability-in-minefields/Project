//
// Created by Andreas Lynnerup on 27/11/2023.
///
#include <stdio.h>
#include "stdlib.h"

#include "exportMatrixToFile.h"

void export_matrix_to_file(int rows, int cols, double** matrix) {

    FILE *file = fopen("../OutputMatrices/outputMatrix.txt", "w");

    if (file == NULL) {
        printf("Error opening file for writing. Aborting...\n");
        exit(0);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fprintf(file, "%lf ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);

}


