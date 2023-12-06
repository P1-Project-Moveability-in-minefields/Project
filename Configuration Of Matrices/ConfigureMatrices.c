//
// Created by thoma on 05/12/2023.
//

#include "ConfigureMatrices.h"
#include "../Databehandling/userPreferences.h"
#include "stdbool.h"

/// Checks for impassable slopes
///
/// Parameters:
/// slopeMap (struct) is a matrix pointer and dimension values.
/// settings (struct) is only used for the passable value in question with the map.
void ConfigureSlopeMapRelationships(int** slopeMap, userSettings *settings){
    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (slopeMap[i][j] > settings->troop_settings.max_slope){
                slopeMap[i][j] = -1;
            }
        }
    }
}

/// Checks for impassable water depth
///
/// Parameters:
/// waterMap (struct) is a matrix pointer and dimension values.
/// settings (struct) is only used for the passable value in question with the map.
void ProcessWaterMapRelationships(int** waterMap, userSettings *settings){

    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (waterMap[i][j] > settings->troop_settings.max_water_depth){
             waterMap[i][j] = -1;
            }
        }
    }
}

/// Checks for inacceptable mine chances
///
/// Parameters:
/// mineMap (struct) is a matrix pointer and dimension values.
/// settings (struct) is only used for the acceptable value in question with the map.
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

/// Checks for acceptable amount of vegitation
///
/// Parameters:
/// vegetationMap (struct) is a matrix pointer and dimension values.
/// settings (struct) is only used for the acceptable value in question with the map.
void ConfigureVegetationMap(int** vegetationMap, userSettings *settings){

    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (vegetationMap[i][j] > settings->troop_settings.max_terrain_difficulty){
                vegetationMap[i][j] = -1;
            }
        }
    }
}

/// Checks for acceptable road quality
///
/// Parameters:
/// roadQualityMap (struct) is a matrix pointer and dimension values.
/// settings (struct) is only used for the acceptable value in question with the map.
void ConfigureRoadQualityMap(int** roadQualityMap, userSettings *settings){

    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (roadQualityMap[i][j] > settings->troop_settings.max_road){
                roadQualityMap[i][j] = -1;
            }
        }
    }
}

