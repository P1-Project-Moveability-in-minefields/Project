//
// Created by thoma on 05/12/2023.
//

#include "ConfigureMatrices.h"
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

void ConfigureDepthMap(double** waterMap, userSettings *settings){
    int matrix_dimensions = settings->additional_settings.size;
    double max_water_depth = settings->troop_settings.max_water_depth;

    for (int i = 0; i < matrix_dimensions; ++i) {
        for (int j = 0; j < matrix_dimensions; ++j) {
            double* current_location = &waterMap[i][j];
            *current_location = 1.0 - *current_location;
            if (*current_location > max_water_depth){
                *current_location = -1;
            }
            else if (*current_location) {
                *current_location = *current_location / max_water_depth ;
            }
            else {
                *current_location = 0;
            }
        }
    }
}

void ConfigureMineMap(double** mineMap, userSettings *settings){

    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (mineMap[i][j] > settings->troop_settings.max_mine_risk){
                mineMap[i][j] = -1;
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
void ConfigureSoilMap(MatrixInfo soilMap, userSettings settings){

    for (int i = 0; i < soilMap.rows; ++i) {
        for (int j = 0; j < soilMap.cols; ++j) {
            if (soilMap[i][j] > settings.acceptableSoil true){
                soilMap[i][j] = -1;
            }
        }
    }
}
*/

void ConfigureVegetationMap(double** vegetationMap, userSettings *settings){

    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (vegetationMap[j][i] > settings->troop_settings.max_terrain_difficulty){
                vegetationMap[j][i] = -1;
            }
        }
    }
}

void ConfigureRoadQualityMap(double** roadQualityMap, userSettings *settings){

    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (roadQualityMap[j][i] < settings->troop_settings.max_road){
                roadQualityMap[j][i] = -1;
            }
            if (roadQualityMap[j][i] != -1) {
                roadQualityMap[j][i] = 1 - roadQualityMap[j][i];
            }
        }
    }
}

