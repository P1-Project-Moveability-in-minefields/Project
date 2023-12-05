//
// Created by thoma on 05/12/2023.
//

#ifndef P1_PROJECT_CONFIGUREMATRICES_H
#define P1_PROJECT_CONFIGUREMATRICES_H


typedef struct {
    double** matrix;
    int rows;
    int cols;
} MatrixInfo;

typedef struct{
    MatrixInfo matrixInfo;
    double weight;
} WeightedMatrix;

int** ConfigureSlopeMapRelationships(MatrixInfo heightMap, userSettings settings);
int** ConfigureWaterMapRelationships(MatrixInfo waterMap, userSettings settings);

#endif //P1_PROJECT_CONFIGUREMATRICES_H
