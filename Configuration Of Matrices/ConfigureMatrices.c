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
void ConfigureSlopeMapRelationships(WeightedMatrix slopeMap, userSettings *settings){
    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (slopeMap.matrix[i][j] > settings->troop_settings.max_slope){
                slopeMap.matrix[i][j] = -1;
            }
        }
    }
}

/// Checks for impassable water depth
///
/// Parameters:
/// waterMap (struct) is a matrix pointer and dimension values.
/// settings (struct) is only used for the passable value in question with the map.
void ProcessWaterMapRelationships(WeightedMatrix waterMap, userSettings *settings){

    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (waterMap.matrix[i][j] > settings->troop_settings.max_water_depth){
             waterMap.matrix[i][j] = -1;
            }
        }
    }
}

/// Checks for inacceptable mine chances
///
/// Parameters:
/// mineMap (struct) is a matrix pointer and dimension values.
/// settings (struct) is only used for the acceptable value in question with the map.
void ConfigureMineMap(WeightedMatrix mineMap, userSettings *settings){

    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (mineMap.matrix[i][j] > settings->troop_settings.max_mine_risk){
                mineMap.matrix[i][j] = -1;
            }
        }
    }
}

/*
void ConfigureSoilMap(MatrixInfo soilMap, userSettings settings){

    for (int i = 0; i < soilMap.rows; ++i) {
        for (int j = 0; j < soilMap.cols; ++j) {
            if (soilMap.matrix[i][j] > settings.acceptableSoil true){
                soilMap.matrix[i][j] = -1;
            }
        }
    }
}
*/

/// Checks for acceptable amount of vegitation
///
/// Parameters:
/// vegitationMap (struct) is a matrix pointer and dimension values.
/// settings (struct) is only used for the acceptable value in question with the map.
void ConfigureVegitationMap(WeightedMatrix vegitationMap, userSettings *settings){

    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (vegitationMap.matrix[i][j] > settings->troop_settings.max_terrain_difficulty){
                vegitationMap.matrix[i][j] = -1;
            }
        }
    }
}

/// Checks for acceptable road quality
///
/// Parameters:
/// roadQualityMap (struct) is a matrix pointer and dimension values.
/// settings (struct) is only used for the acceptable value in question with the map.
void ConfigureRoadQualityMap(WeightedMatrix roadQualityMap, userSettings *settings){

    for (int i = 0; i < settings->additional_settings.size; ++i) {
        for (int j = 0; j < settings->additional_settings.size; ++j) {
            if (roadQualityMap.matrix[i][j] > settings->troop_settings.max_road){
                roadQualityMap.matrix[i][j] = -1;
            }
        }
    }
}

