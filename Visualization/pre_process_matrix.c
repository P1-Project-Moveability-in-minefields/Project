//
// Created by Andreas Lynnerup on 06/12/2023.
///
#include "pre_process_matrix.h"
#include "stdio.h"
#include <stdlib.h>

double** create_matrix_painting(int size, double*** listOfMatrices) {

    double** matrixPainting = malloc(size * sizeof(double**));

    for (int i = 0; i < size; ++i) {
        matrixPainting[i] = malloc(size * sizeof(double));
    }

    // For each terrain matrix, "paint" the matrix painting
    add_listOfMatrices_to_matrixPainting(size, matrixPainting, listOfMatrices);

    return matrixPainting;
}

void add_listOfMatrices_to_matrixPainting(int size, double** matrixPainting, double*** listOfMatrices){
    add_soil_to_matrix(size, matrixPainting, listOfMatrices[0]);
    add_water_to_matrix(size, matrixPainting, listOfMatrices[1]);
    add_vegetation_or_swampland_to_matrix(size, matrixPainting, listOfMatrices[2]);
    add_road_to_matrix(size, matrixPainting, listOfMatrices[3]);
    add_mine_to_matrix(size, matrixPainting, listOfMatrices[5]);
}



void add_soil_to_matrix(int size, double** matrixPainting, double** terrainMatrix){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){

            if (terrainMatrix[i][j] < 0.5) {
                matrixPainting[i][j] = 0.1;
            } else {
                matrixPainting[i][j] = 0.0;
            }

        }
    }
}

void add_water_to_matrix(int size, double** matrixPainting, double** terrainMatrix){

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){

            if (terrainMatrix[i][j] > 0.5) {
                matrixPainting[i][j] = 0.3;
            } else if (terrainMatrix[i][j] > 0.1){
                matrixPainting[i][j] = 0.2;
            }
        }
    }
}

void add_vegetation_or_swampland_to_matrix(int size, double** matrixPainting, double** terrainMatrix){
    // For each cell
    int lastCellWasSwamp = 1;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            int isVegetation = 0;
            int isWater = 0;

            double terrainCell = terrainMatrix[i][j];
            double* matrixCell = &matrixPainting[i][j];

            if (*matrixCell == 0.2 || *matrixCell == 0.3) {
                isWater = 1;
            }
            if (terrainCell > 0.3) {
                isVegetation = 1;
            }

            // If there is water and vegetation:
            if (isWater && isVegetation){ // Water has value of 0.3
                add_swamp_to_matrix(&lastCellWasSwamp, terrainCell, matrixCell);
            }

            // Else if no water and vegetation
            else if (!isWater && isVegetation) {
                add_vegetation_to_matrix(terrainCell, matrixCell);
            }

        }
    }
}

void add_swamp_to_matrix(int* lastCellWasSwamp,  double terrainCell, double* matrixCell){
    if (*lastCellWasSwamp) {
        if(terrainCell < 0.75)
        { // low veg
            *matrixCell = 0.5;
        }
        else if (terrainCell > 0.75)
        { // high veg
            *matrixCell = 0.6;
        }
        *lastCellWasSwamp = 0;
    } else {
        *matrixCell = 0.4;
        *lastCellWasSwamp = 1;
    }
}

void add_vegetation_to_matrix(double terrainCell, double* matrixCell){
    if(terrainCell < 0.75)
    { // low veg
        *matrixCell = 0.5;
    }
    else if (terrainCell > 0.75)
    { // high veg
        *matrixCell = 0.6;
    }
}

void add_road_to_matrix(int size, double** matrixPainting, double** terrainMatrix){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            // Good road
            if (terrainMatrix[i][j] < 0.3 ){
                matrixPainting[i][j] = 0.8;
            }

            // Poor road
            else if ( terrainMatrix[i][j] < 1 ) {
                matrixPainting[i][j] = 0.7;
            }



        }
    }
}
void add_mine_to_matrix(int size, double** matrixPainting, double** terrainMatrix){
    if (terrainMatrix == NULL){
        return;
    }

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {

            double value = terrainMatrix[row][col];

            if (value > 0){
                if (value < 0.6) {
                    matrixPainting[row][col] = 0.9; // Set the color for mines
                }
                else {
                    matrixPainting[row][col] = 1.0; // Set the color for mines
                }

            }

        }



    }
}

void add_optimal_route_to_matrix(int size, double** matrixPainting, int** optimalRoute, int numberOfSteps){

    for (int i = 0; i < numberOfSteps; i++) {
        int x = optimalRoute[i][0];
        int y = optimalRoute[i][1];
        matrixPainting[x][y] = 1.1;
    }

}