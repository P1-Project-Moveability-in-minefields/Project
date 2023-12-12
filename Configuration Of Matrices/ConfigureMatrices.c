//
// Created by thoma on 05/12/2023.
//

#include "ConfigureMatrices.h"
#include "RelationshipMethods.h"
#include "../Databehandling/userPreferences.h"
#include "stdbool.h"
#include <stdlib.h>
#include <stdio.h>

void CreateSlopeMap(slope_struct** slopeMap,double** heightMap, userSettings *settings){
    int matrix_dimensions = settings->additional_settings.size;

    for (int x = 0; x < matrix_dimensions; ++x) {
        for (int y = 0; y < matrix_dimensions; ++y) {
            slope_struct slope_data;
            slope_data.altitude = heightMap[x][y];
            if (x > 0) {
                slope_data.westward_slope = 100*(heightMap[x][y] / heightMap[x-1][y]);
                slope_data.steepest_slope = slope_data.westward_slope;
            }
            if (x < matrix_dimensions) {
                slope_data.eastward_slope = 100*(heightMap[x][y] / heightMap[x+1][y]);
                if (!slope_data.steepest_slope || slope_data.steepest_slope < slope_data.eastward_slope) {
                    slope_data.steepest_slope = slope_data.eastward_slope;
                }
            }
            if (y > 0) {
                slope_data.northward_slope = 100*(heightMap[x][y] / heightMap[x][y+1]);
                if (!slope_data.steepest_slope || slope_data.steepest_slope < slope_data.northward_slope) {
                    slope_data.steepest_slope = slope_data.northward_slope;
                }
            }
            if (y < matrix_dimensions) {
                slope_data.southward_slope = 100*(heightMap[x][y] / heightMap[x][y-1]);
                if (!slope_data.steepest_slope || slope_data.steepest_slope < slope_data.northward_slope) {
                    slope_data.steepest_slope = slope_data.northward_slope;
                }
            }
            slopeMap[x][y] = slope_data;
        }
    }
}

void ConfigureDepthMap(double** waterMap, double** road_map, userSettings *settings){
    int matrix_dimensions = settings->additional_settings.size;
    double max_water_depth = settings->troop_settings.max_water_depth;
    double *current_location = NULL;

    for (int i = 0; i < matrix_dimensions; ++i) {
        for (int j = 0; j < matrix_dimensions; ++j) {
            current_location = &waterMap[i][j];
            if (road_map[i][j] != -1 && road_map[i][j] < 1){
                *current_location = 0;
            } else if (*current_location > max_water_depth){
                *current_location = -1;
            } else if (*current_location) {
                *current_location = *current_location / max_water_depth ;
            }
        }
    }
}

void ConfigureMineMap(double** mineMap, userSettings *settings){
    int matrix_dimensions = settings->additional_settings.size;
    double max_mine_risk = settings->troop_settings.max_mine_risk;
    double *current_location = NULL;

    for (int i = 0; i < matrix_dimensions; ++i) {
        for (int j = 0; j < matrix_dimensions; ++j) {
            current_location = &mineMap[i][j];
            if (*current_location > max_mine_risk){
                *current_location = -1;
            } else if (*current_location){
                *current_location = *current_location / max_mine_risk;
            }
        }
    }
}

void CombineMineMaps(double** mineMap, double*** mineMaps, int map_count, userSettings* settings) {
    // Assuming mineMap is a 2D array
    // Ensure proper memory allocation for mineMap
    for (int i = 0; i < settings->additional_settings.size; ++i) {
        mineMap[i] = (double*)malloc(settings->additional_settings.size * sizeof(double));
    }

    // Combine mine maps
    for (int map_number = 0; map_number < map_count; ++map_number) {
        for (int x = 0; x < settings->additional_settings.size; ++x) {
            for (int y = 0; y < settings->additional_settings.size; ++y) {
                // Ensure indices are within bounds
                if (x < settings->additional_settings.size && y < settings->additional_settings.size) {
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
void ConfigureSoilMap(double** soil_map, userSettings *settings){
    int matrix_dimensions = settings->additional_settings.size;
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

void ConfigureVegetationMap(double** vegetationMap, userSettings *settings){
    int matrix_dimensions = settings->additional_settings.size;
    double max_terrain_difficulty = settings->troop_settings.max_terrain_difficulty;
    double *current_location = NULL;

    for (int i = 0; i < matrix_dimensions; ++i) {
        for (int j = 0; j < matrix_dimensions; ++j) {
            current_location = &vegetationMap[i][j];
            if (*current_location > max_terrain_difficulty){
                vegetationMap[i][j] = -1;
            } else if(*current_location){
                *current_location = *current_location/max_terrain_difficulty;
            }
        }
    }
}

void ConfigureRoadQualityMap(double** roadQualityMap, userSettings *settings){
    int matrix_dimensions = settings->additional_settings.size;
    double max_road = settings->troop_settings.max_road;
    double *current_location = NULL;

    for (int i = 0; i < matrix_dimensions; ++i) {
        for (int j = 0; j < matrix_dimensions; ++j) {
            current_location = &roadQualityMap[i][j];
            if (*current_location > max_road){
                *current_location = -1;
            } else if(*current_location){
                *current_location = *current_location/max_road;
            }
        }
    }
}

WeightedMatrix* ConfigureListOfMatrices(double*** list_of_matrices, userSettings *settings){
    ConfigureRoadQualityMap(list_of_matrices[3], settings);
    ConfigureDepthMap(list_of_matrices[1], list_of_matrices[3], settings);
    ConfigureVegetationMap(list_of_matrices[2], settings);
    ConfigureMineMap(list_of_matrices[5], settings);

    WeightedMatrix* list_of_configured_matrices = (WeightedMatrix*)malloc(6 * sizeof(WeightedMatrix));

    if (!list_of_configured_matrices) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    list_of_configured_matrices[0] = (WeightedMatrix){mine, list_of_matrices[5], settings->priority_level.mine_risk};
    list_of_configured_matrices[1] = (WeightedMatrix){soil, list_of_matrices[0], 0};
    list_of_configured_matrices[2] = (WeightedMatrix){water, list_of_matrices[1], 0};
    list_of_configured_matrices[3] = (WeightedMatrix){vegetation, list_of_matrices[2], 0};
    list_of_configured_matrices[4] = (WeightedMatrix){road, list_of_matrices[3], 0};
    list_of_configured_matrices[5] = (WeightedMatrix){steepness, list_of_matrices[4], 0};

    determine_weights(list_of_configured_matrices, 6, settings);

    return list_of_configured_matrices;
}