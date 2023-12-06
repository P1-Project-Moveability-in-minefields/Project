//
// Created by Andreas Lynnerup on 27/11/2023.
///
#include <stdio.h>
#include "stdlib.h"

#include "Visualization.h"

void exportMatrixToFile(int rows, int cols, double matrix[rows][cols]) {

    FILE *file = fopen("../OutputMatrices/outputmatrix.txt", "w");

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