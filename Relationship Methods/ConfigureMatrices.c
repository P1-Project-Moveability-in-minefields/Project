//
// Created by thoma on 05/12/2023.
//

#include "ConfigureMatrices.h"
#include "../Databehandling/userPreferences.h"
#include "math.h"
#include <stdio.h>


int** ConfigureSlopeMapRelationships(MatrixInfo slopeMap, userSettings settings){
    for (int i = 0; i < slopeMap.rows; ++i) {
        for (int j = 0; j < slopeMap.cols; ++j) {
            
        }
    }
    return overallMatrix;
}

int** ProcessWaterMapRelationships(int** overallMatrix, WeightedMatrix waterMap, userSettings settings){
    if (waterMap.matrixInfo.matrix == NULL){ // Check for bad data
        return overallMatrix;
    }
    if (overallMatrix == NULL){ // Check for bad data
        overallMatrix = CreateDynamicMatrix(waterMap.matrixInfo.rows, waterMap.matrixInfo.cols);
    }

    for (int i = 0; i < waterMap.matrixInfo.rows; ++i) {
        for (int j = 0; j < waterMap.matrixInfo.cols; ++j) {
            if (waterMap.matrixInfo.matrix[i][j] > 0) { // Is there water here?
                int cost = waterMap.weight * waterMap.matrixInfo.matrix[i][j]; // Calculate cost
                if (settings.isWaterPassable) {
                    overallMatrix[i][j] += cost; // The more water the worse it is.
                } else {
                    overallMatrix[i][j] += 100 * cost; // If we can't cross water then we don't want to so 100 times worse.
                }
            }
            else{
                // No water no change
            }
        }
    }
    return overallMatrix;
}

