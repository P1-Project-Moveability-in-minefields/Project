//
// Created by thoma on 05/12/2023.
//

#include "ConfigureMatrices.h"
#include "../Databehandling/userPreferences.h"
#include "math.h"
#include <stdio.h>
#include "stdbool.h"


MatrixInfo ConfigureSlopeMapRelationships(MatrixInfo slopeMap, userSettings settings){
    for (int i = 0; i < slopeMap.rows; ++i) {
        for (int j = 0; j < slopeMap.cols; ++j) {
            if (/*slopeMap.matrix[i][j] > settings.acceptableSlope*/ true){
                slopeMap.matrix[i][j] = -1;
            }
        }
    }
    return slopeMap;
}

MatrixInfo ProcessWaterMapRelationships(MatrixInfo waterMap, userSettings settings){

    for (int i = 0; i < waterMap.rows; ++i) {
        for (int j = 0; j < waterMap.cols; ++j) {
            if (/*waterMap.matrix[i][j] > settings.acceptableWater*/ true){
             waterMap.matrix[i][j] = -1;
            }
        }
    }
    return waterMap;
}

MatrixInfo ConfigureMineMap(MatrixInfo mineMap, userSettings settings){

    for (int i = 0; i < mineMap.rows; ++i) {
        for (int j = 0; j < mineMap.cols; ++j) {
            if (/*mineMap.matrix[i][j] > settings.acceptableMine*/ true){
                mineMap.matrix[i][j] = -1;
            }
        }
    }
    return mineMap;

}

MatrixInfo ConfigureSoilMap(MatrixInfo soilMap, userSettings settings){

    for (int i = 0; i < soilMap.rows; ++i) {
        for (int j = 0; j < soilMap.cols; ++j) {
            if (/*soilMap.matrix[i][j] > settings.acceptableSoil*/ true){
                soilMap.matrix[i][j] = -1;
            }
        }
    }
    return soilMap;

}

MatrixInfo ConfigureVegitationMap(MatrixInfo vegitationMap, userSettings settings){

    for (int i = 0; i < vegitationMap.rows; ++i) {
        for (int j = 0; j < vegitationMap.cols; ++j) {
            if (/*vegitationMap.matrix[i][j] > settings.acceptableVegitation*/ true){
                vegitationMap.matrix[i][j] = -1;
            }
        }
    }
    return vegitationMap;

}

MatrixInfo ConfigureRoadMap(MatrixInfo roadMap, userSettings settings){

    for (int i = 0; i < roadMap.rows; ++i) {
        for (int j = 0; j < roadMap.cols; ++j) {
            if (/*roadMap.matrix[i][j] > settings.acceptableRoad*/ true){
                roadMap.matrix[i][j] = -1;
            }
        }
    }
    return roadMap;

}
