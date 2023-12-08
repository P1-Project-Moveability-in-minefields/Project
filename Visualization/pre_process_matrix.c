//
// Created by Andreas Lynnerup on 06/12/2023.
///
#define NUMBEROFMATRICES 5
#include "pre_process_matrix.h"
#include "stdio.h"
#include <stdlib.h>

double** createMatrixPainting(int size,
                              double** soilMatrix,
                              double** waterMatrix,
                              double** vegetationMatrix,
                              double** roadMatrix,
                              double** mineMatrix,
                              int** optimal_route,
                              int number_of_steps) {

    double** matrix = malloc(size * sizeof(double*));
    for (int i = 0; i < size; ++i) {
        matrix[i] = malloc(size * sizeof(double));
    }

    // Assuming these functions are correctly implemented to copy values
    addSoilToMatrix(size, matrix, soilMatrix);
    addWaterToMatrix(size, matrix, waterMatrix);
    addVegetationToMatrix(size, matrix, vegetationMatrix);
    addRoadToMatrix(size, matrix, roadMatrix);
    addMineToMatrix(size, matrix, mineMatrix);
    addOptimalRouteToMatrix(size, matrix, optimal_route, number_of_steps);

    return matrix;
}


void addSoilToMatrix(int size, double** matrix, double** terrainMatrix){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){

            if (terrainMatrix[i][j] > 0.5) {
                matrix[i][j] = 0.2;
            } else {
                matrix[i][j] = 0.1;
            }

        }
    }
}
void addWaterToMatrix(int size, double** matrix, double** terrainMatrix){
    if (terrainMatrix == NULL){
        return;
    }

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            double value = terrainMatrix[row][col];
            if (value > 0){
                if (value > 0.5){
                    matrix[row][col] = 0.4; // Set to the color of deep water
                }
                else {
                    matrix[row][col] = 0.3; // Set to the color of shallow water
                }
            }
        }
    }
}
void addVegetationToMatrix(int size, double** matrix, double** terrainMatrix){
    // For each cell
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){


            // If there is water and vegetation:
            if (matrix[i][j] != 0) {
                if (terrainMatrix[i][j] != 0) {
                    matrix[i][j] = 0.5;
                }
            }

            // Else if no water and low vegetation
            else if (terrainMatrix[i][j] < 0.5) {
                matrix[i][j] = 0.6;
            }

            // Else if no water and high vegetation
            else if (terrainMatrix[i][j] > 0.5) {
                matrix[i][j] = 0.7;
            }

        }
    }
}
void addRoadToMatrix(int size, double** matrix, double** terrainMatrix){
    if (terrainMatrix == NULL){
        return;
    }

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            double value = terrainMatrix[row][col];
            if (value > 0){
                if (value > 0.5){
                    matrix[row][col] = 1; // Set the color to dark road
                }
                else {
                    matrix[row][col] = 0.9; // Set the color to light road
                }
            }
        }
    }
}
void addMineToMatrix(int size, double** matrix, double** terrainMatrix){
    if (terrainMatrix == NULL){
        return;
    }

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            double value = terrainMatrix[row][col];
            if (value > 0){
                matrix[row][col] = 0.95; // Set the color for mines
            }
        }
    }
}

void addOptimalRouteToMatrix(int size, double** matrix, int** optimal_route, int number_of_steps){

    for (int i = 0; i < number_of_steps; i++) {
        int x = optimal_route[i][0];
        int y = optimal_route[i][1];
        matrix[x][y] = 1;
    }

}