//
// Created by thoma on 05/12/2023.
//

#include "ConfigureMatrices.h"
#include "RelationshipMethods.h"
#include "../Databehandling/userPreferences.h"
#include "stdbool.h"
#include <stdlib.h>
#include <stdio.h>

void create_slope_map(slopeStruct ** slopeMap, double** heightMap, userSettings *settings){
    int matrix_dimensions = settings->additionalSettings.size;

    for (int x = 0; x < matrix_dimensions; ++x) {
        for (int y = 0; y < matrix_dimensions; ++y) {
            slopeStruct slopeData;
            slopeData.altitude = heightMap[x][y];
            if (x > 0) {
                slopeData.westwardSlope = 100*(heightMap[x][y] / heightMap[x-1][y]);
                slopeData.steepestSlope = slopeData.westwardSlope;
            }
            if (x < matrix_dimensions) {
                slopeData.eastwardSlope = 100*(heightMap[x][y] / heightMap[x+1][y]);
                if (!slopeData.steepestSlope || slopeData.steepestSlope < slopeData.eastwardSlope) {
                    slopeData.steepestSlope = slopeData.eastwardSlope;
                }
            }
            if (y > 0) {
                slopeData.northwardSlope = 100*(heightMap[x][y] / heightMap[x][y+1]);
                if (!slopeData.steepestSlope || slopeData.steepestSlope < slopeData.northwardSlope) {
                    slopeData.steepestSlope = slopeData.northwardSlope;
                }
            }
            if (y < matrix_dimensions) {
                slopeData.southwardSlope = 100*(heightMap[x][y] / heightMap[x][y-1]);
                if (!slopeData.steepestSlope || slopeData.steepestSlope < slopeData.northwardSlope) {
                    slopeData.steepestSlope = slopeData.northwardSlope;
                }
            }
            slopeMap[x][y] = slopeData;
        }
    }
}

void configure_depth_map(double** waterMap, double** roadMap, userSettings *settings){
    int matrixDimensions = settings->additionalSettings.size;
    double maxWaterDepth = settings->troopSettings.maxWaterDepth;
    double *currentLocation = NULL;

    for (int i = 0; i < matrixDimensions; ++i) {
        for (int j = 0; j < matrixDimensions; ++j) {
            currentLocation = &waterMap[i][j];
            if (roadMap[i][j] != -1 && roadMap[i][j] < 1){
                *currentLocation = 0;
            } else if (*currentLocation > maxWaterDepth){
                *currentLocation = -1;
            } else if (*currentLocation) {
                *currentLocation = *currentLocation / maxWaterDepth ;
            }
        }
    }
}

void configure_mine_map(double** mineMap, userSettings *settings){
    int matrixDimensions = settings->additionalSettings.size;
    double maxMineRisk = settings->troopSettings.maxMineRisk;
    double *currentLocation = NULL;

    for (int i = 0; i < matrixDimensions; ++i) {
        for (int j = 0; j < matrixDimensions; ++j) {
            currentLocation = &mineMap[i][j];
            if (*currentLocation > maxMineRisk){
                *currentLocation = -1;
            } else if (*currentLocation){
                *currentLocation = *currentLocation / maxMineRisk;
            }
        }
    }
}

void combine_mine_maps(double** mineMap, double*** mineMaps, int mapCount, userSettings* settings) {
    // Assuming mineMap is a 2D array
    // Ensure proper memory allocation for mineMap
    for (int i = 0; i < settings->additionalSettings.size; ++i) {
        mineMap[i] = (double*)malloc(settings->additionalSettings.size * sizeof(double));
    }

    // Combine mine maps
    for (int map_number = 0; map_number < mapCount; ++map_number) {
        for (int x = 0; x < settings->additionalSettings.size; ++x) {
            for (int y = 0; y < settings->additionalSettings.size; ++y) {
                // Ensure indices are within bounds
                if (x < settings->additionalSettings.size && y < settings->additionalSettings.size) {
                    mineMap[x][y] = (mineMap[x][y] + mineMaps[map_number][x][y]) / 2;
                    if (mineMap[x][y] > 1) {
                        mineMap[x][y] = 1;
                    }
                } else {
                    // Handle index out-of-bounds error
                    // Add appropriate error handling or print statements
                    printf("Index out of bounds: x=%d, y=%d\n", x, y);
                }
            }
        }
    }
}

/*
void configure_soil_map(double** soil_map, userSettings *settings){
    int matrix_dimensions = settings->additionalSettings.size;
    double max_soil = settings->troop_settings.max_soil;
    double *current_location = NULL;

    for (int i = 0; i < matrix_dimensions; ++i) {
        for (int j = 0; j < matrix_dimensions; ++j) {
            current_location = &soil_map[i][j];
            if (*current_location > max_soil){
                *current_location = -1;
            } else if(*current_location){
                *current_location = *current_location/max_soil;
            }
        }
    }
}
*/

void configure_vegetation_map(double** vegetationMap, userSettings *settings){
    int matrixDimensions = settings->additionalSettings.size;
    double maxTerrainDifficulty = settings->troopSettings.maxTerrainDifficulty;
    double *currentLocation = NULL;

    for (int i = 0; i < matrixDimensions; ++i) {
        for (int j = 0; j < matrixDimensions; ++j) {
            currentLocation = &vegetationMap[i][j];
            if (*currentLocation > maxTerrainDifficulty){
                vegetationMap[i][j] = -1;
            } else if(*currentLocation){
                *currentLocation = *currentLocation/maxTerrainDifficulty;
            }
        }
    }
}

void configure_road_quality_map(double** roadQualityMap, userSettings *settings){
    int matrixDimensions = settings->additionalSettings.size;
    double maxRoad = settings->troopSettings.maxRoad;
    double *currentLocation = NULL;

    for (int i = 0; i < matrixDimensions; ++i) {
        for (int j = 0; j < matrixDimensions; ++j) {
            currentLocation = &roadQualityMap[i][j];
            if (*currentLocation > maxRoad){
                *currentLocation = -1;
            } else if(*currentLocation){
                *currentLocation = *currentLocation/maxRoad;
            }
        }
    }
}

weightedMatrix* configure_list_of_matrices(double*** listOfMatrices, userSettings *settings){
    configure_road_quality_map(listOfMatrices[3], settings);
    configure_depth_map(listOfMatrices[1], listOfMatrices[3], settings);
    configure_vegetation_map(listOfMatrices[2], settings);
    configure_mine_map(listOfMatrices[5], settings);

    weightedMatrix* listOfConfiguredMatrices = (weightedMatrix* )malloc(6 * sizeof(weightedMatrix ));

    if (!listOfConfiguredMatrices) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    listOfConfiguredMatrices[0] = (weightedMatrix ){mine, listOfMatrices[5], settings->priorityLevel.mineRisk};
    listOfConfiguredMatrices[1] = (weightedMatrix){soil, listOfMatrices[0], 0};
    listOfConfiguredMatrices[2] = (weightedMatrix){water, listOfMatrices[1], 0};
    listOfConfiguredMatrices[3] = (weightedMatrix){vegetation, listOfMatrices[2], 0};
    listOfConfiguredMatrices[4] = (weightedMatrix){road, listOfMatrices[3], 0};
    listOfConfiguredMatrices[5] = (weightedMatrix){steepness, listOfMatrices[4], 0};

    determine_weights(listOfConfiguredMatrices, 6, settings);

    return listOfConfiguredMatrices;
}