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

void ConfigureSlopeMap(WeightedMatrix slopeMap, userSettings *settings);
void ConfigureWaterMap(WeightedMatrix waterMap, userSettings *settings);
void ConfigureMineMap(WeightedMatrix mineMap, userSettings *settings);
void ConfigureSoilMap(WeightedMatrix soilMap, userSettings *settings);
void ConfigureVegetationMap(WeightedMatrix vegitationMap, userSettings *settings);
void ConfigureRoadQualityMap(WeightedMatrix roadQualityMap, userSettings *settings);


#endif //P1_PROJECT_CONFIGUREMATRICES_H
