//
// Created by Andreas Lynnerup on 06/12/2023.
///
#define NUMBEROFMATRICES 5
#include "pre_process_matrix.h"
#include "stdio.h"

double** createMatrixPainting(int rows, int cols,
                              double** soilMatrix[rows][cols],
                              double** waterMatrix[rows][cols],
                              double** vegetationMatrix[rows][cols],
                              double** roadMatrix[rows][cols],
                              double** mineMatrix[rows][cols],
                              int** optimal_route){

    double** matrixPainting[rows][cols];

    addSoilToMatrix(matrixPainting, soilMatrix);
    addWaterToMatrix(matrixPainting);
    addVegetationToMatrix(matrixPainting);
    addRoadToMatrix(matrixPainting);
    addMineToMatrix(matrixPainting);


}


void addSoilToMatrix(double** matrixPainting, double** terrainMatrix){

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
                    matrix[row][col] = 0.4;
                }
                else {
                    matrix[row][col] = 0.3;
                }
            }
        }
    }
}
void addVegetationToMatrix(double** matrix, double** terrainMatrix){

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
                    matrix[row][col] = 1;
                }
                else {
                    matrix[row][col] = 0.9;
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
                matrix[row][col] = 0.95;
            }
        }
    }
}