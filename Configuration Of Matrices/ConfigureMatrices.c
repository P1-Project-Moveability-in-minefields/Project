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
void ConfigureSlopeMapRelationships(MatrixInfo slopeMap, userSettings settings){
    for (int i = 0; i < slopeMap.rows; ++i) {
        for (int j = 0; j < slopeMap.cols; ++j) {
            if (/*slopeMap.matrix[i][j] > settings.acceptableSlope*/ true){
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
void ProcessWaterMapRelationships(MatrixInfo waterMap, userSettings settings){

    for (int i = 0; i < waterMap.rows; ++i) {
        for (int j = 0; j < waterMap.cols; ++j) {
            if (/*waterMap.matrix[i][j] > settings.acceptableWater*/ true){
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
void ConfigureMineMap(MatrixInfo mineMap, userSettings settings){

    for (int i = 0; i < mineMap.rows; ++i) {
        for (int j = 0; j < mineMap.cols; ++j) {
            if (/*mineMap.matrix[i][j] > settings.acceptableMine*/ true){
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
void ConfigureVegitationMap(MatrixInfo vegitationMap, userSettings settings){

    for (int i = 0; i < vegitationMap.rows; ++i) {
        for (int j = 0; j < vegitationMap.cols; ++j) {
            if (/*vegitationMap.matrix[i][j] > settings.acceptableVegitation*/ true){
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
void ConfigureRoadQualityMap(MatrixInfo roadQualityMap, userSettings settings){

    for (int i = 0; i < roadMap.rows; ++i) {
        for (int j = 0; j < roadMap.cols; ++j) {
            if (/*roadMap.matrix[i][j] > settings.acceptableRoad*/ true){
                roadMap.matrix[i][j] = -1;
            }
        }
    }
}
