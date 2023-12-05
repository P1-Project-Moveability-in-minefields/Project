//
// Created by thoma on 05/12/2023.
//

#include "ConfigureMatrices.h"


int** ConfigureSlopeMapRelationships(WeightedMatrix heightMap, userSettings settings){
    for (int i = 0; i < heightMap.matrixInfo.rows; ++i) {
        for (int j = 0; j < heightMap.matrixInfo.cols; ++j) {
            if (settings.prioritizeCover){
                // Check neighbors and calculate cost
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int ni = i + x;
                        int nj = j + y;

                        // Check if the neighbor is within bounds
                        if (ni >= 0 && ni < heightMap.matrixInfo.rows && nj >= 0 && nj < heightMap.matrixInfo.cols) {
                            // Calculate the cost based on the elevation difference
                            overallMatrix[i][j] += heightMap.weight * ( abs(heightMap.matrixInfo.matrix[i][j] - heightMap.matrixInfo.matrix[ni][nj]) );
                        }
                    }
                }
            }
            else {
                // Don't know what to do if cover isn't prioritized, approach here is that lower height is better.
                overallMatrix[i][j] += heightMap.weight * heightMap.matrixInfo.matrix[i][j];
            }
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

