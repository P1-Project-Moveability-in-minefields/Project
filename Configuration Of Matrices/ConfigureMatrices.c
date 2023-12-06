//
// Created by thoma on 05/12/2023.
//

#include "ConfigureMatrices.h"
#include "../Databehandling/userPreferences.h"
#include "stdbool.h"

int CreateSlopeMap(slope_struct** slopeMap,int** heightMap, userSettings *settings){
    int matrix_dimensions = settings->additional_settings.size;

    for (int x = 0; x < matrix_dimensions; ++x) {
        for (int y = 0; y < matrix_dimensions; ++y) {
            slope_struct slope_data;
            slope_data.altitude = heightMap[x][y];
            if (x > 0) {
                slope_data.westward_slope = 100*(heightMap[x][y] / heightMap[x-1][y]);
            }
            if (x < matrix_dimensions) {
                slope_data.eastward_slope = 100*(heightMap[x][y] / heightMap[x+1][y]);
            }
            if (y > 0) {
                slope_data.northward_slope = 100*(heightMap[x][y] / heightMap[x][y+1]);
            }
            if (y < matrix_dimensions) {
                slope_data.southward_slope = 100*(heightMap[x][y] / heightMap[x][y-1]);
            }
            slopeMap[x][y] = slope_data;
        }
    }

    return 1;
}

void ProcessWaterMapRelationships(int** waterMap, userSettings *settings){

    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (waterMap[i][j] > settings->troop_settings.max_water_depth){
             waterMap[i][j] = -1;
            }
        }
    }
}

void ConfigureMineMap(int** mineMap, userSettings *settings){

    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (mineMap[i][j] > settings->troop_settings.max_mine_risk){
                mineMap[i][j] = -1;
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

void ConfigureVegetationMap(int** vegetationMap, userSettings *settings){

    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (vegetationMap[i][j] > settings->troop_settings.max_terrain_difficulty){
                vegetationMap[i][j] = -1;
            }
        }
    }
}

void ConfigureRoadQualityMap(int** roadQualityMap, userSettings *settings){

    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (roadQualityMap[i][j] > settings->troop_settings.max_road){
                roadQualityMap[i][j] = -1;
            }
        }
    }
}

