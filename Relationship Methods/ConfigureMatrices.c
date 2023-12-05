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
            if (/*waterMap.matrix[i][j] > settings.acceptableWaterlevel*/ true){
             waterMap.matrix[i][j] = -1;
            }
        }
    }
    return waterMap;
}

