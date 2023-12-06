//
// Created by thoma on 05/12/2023.
//

#include "ConfigureMatrices.h"
#include "../Databehandling/userPreferences.h"
#include "stdbool.h"

void ConfigureSlopeMapRelationships(int** slopeMap, userSettings *settings){
    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (slopeMap[i][j] > settings->troop_settings.max_slope){
                slopeMap[i][j] = -1;
            }
        }
    }
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

