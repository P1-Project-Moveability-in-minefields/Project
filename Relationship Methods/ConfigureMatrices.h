//
// Created by thoma on 05/12/2023.
//

#include "../Databehandling/userPreferences.h"

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

MatrixInfo ConfigureSlopeMap(MatrixInfo slopeMap, userSettings settings);
MatrixInfo ConfigureWaterMap(MatrixInfo waterMap, userSettings settings);
MatrixInfo ConfigureMineMap(MatrixInfo mineMap, userSettings settings);
MatrixInfo ConfigureSoilMap(MatrixInfo soilMap, userSettings settings);
MatrixInfo ConfigureVegitationMap(MatrixInfo vegitationMap, userSettings settings);
MatrixInfo ConfigureRoadMap(MatrixInfo roadMap, userSettings settings);


#endif //P1_PROJECT_CONFIGUREMATRICES_H
