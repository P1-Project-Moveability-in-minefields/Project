//
// Created by Andreas Lynnerup on 06/12/2023.
///
#define NUMBEROFMATRICES 5
#include "pre_process_matrix.h"
#include "stdio.h"

double** createMatrixPainting(int size,
                              double** soilMatrix[size],
                              double** waterMatrix[size],
                              double** vegetationMatrix[size],
                              double** roadMatrix[size],
                              double** mineMatrix[size],
                              int** optimal_route){

    double** matrix[size];

    addSoilToMatrix(size, matrix[size], soilMatrix[size]);
    addWaterToMatrix(matrix, waterMatrix);
    addVegetationToMatrix(size, matrix[size], vegetationMatrix[size]);
    addRoadToMatrix(matrix);
    addMineToMatrix(matrix);


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
    if (terrainMatrix == NULL)
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            double value = terrainMatrix[row][col];
            if (value > 0){
                if (value > 0.5){

                }
                else {

                }
            }
        }
    }
}
void addVegetationToMatrix(int size, double** matrix, double** terrainMatrix){
    // For each cell
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){




            if ((terrainMatrix[i][j] != 0) && (matrix[i][j] == 0.4)) {
                matrix[i][j] = 0.5;
            }

            if ((terrainMatrix[i][j] != 0) && (matrix[i][j] != 0.4)) {
                if ()

            }



        }
    }
}
void addRoadToMatrix(int size, double** matrix, double** terrainMatrix){

}
void addMineToMatrix(int size, double** matrix, double** terrainMatrix){

}