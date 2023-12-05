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

void ConfigureSlopeMap(MatrixInfo slopeMap, userSettings settings);
void ConfigureWaterMap(MatrixInfo waterMap, userSettings settings);
void ConfigureMineMap(MatrixInfo mineMap, userSettings settings);
void ConfigureSoilMap(MatrixInfo soilMap, userSettings settings);
void ConfigureVegitationMap(MatrixInfo vegitationMap, userSettings settings);
void ConfigureRoadQualityMap(MatrixInfo roadQualityMap, userSettings settings);


#endif //P1_PROJECT_CONFIGUREMATRICES_H
