//
// Created by Andreas Lynnerup on 06/12/2023.
///
#define NUMBEROFMATRICES 5
#include "pre_process_matrix.h"

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

}
void addVegetationToMatrix(double** matrix, double** terrainMatrix){

}
void addRoadToMatrix(int size, double** matrix, double** terrainMatrix){

}
void addMineToMatrix(int size, double** matrix, double** terrainMatrix){

}