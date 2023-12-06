//
// Created by thoma on 05/12/2023.
//

#include "../Databehandling/userPreferences.h"

#ifndef P1_PROJECT_CONFIGUREMATRICES_H
#define P1_PROJECT_CONFIGUREMATRICES_H

typedef struct{
    double** matrix;
    double weight;
} WeightedMatrix;

void ConfigureSlopeMap(int** slopeMap, userSettings *settings);
void ConfigureWaterMap(int** waterMap, userSettings *settings);
void ConfigureMineMap(int** mineMap, userSettings *settings);
void ConfigureSoilMap(int** soilMap, userSettings *settings);
void ConfigureVegitationMap(int** vegitationMap, userSettings *settings);
void ConfigureRoadQualityMap(int** roadQualityMap, userSettings *settings);


#endif //P1_PROJECT_CONFIGUREMATRICES_H
