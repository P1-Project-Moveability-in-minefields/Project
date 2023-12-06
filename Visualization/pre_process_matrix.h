//
// Created by Andreas Lynnerup on 06/12/2023.
///

#ifndef P1_PROJECT_PRE_PROCESS_MATRIX_H
#define P1_PROJECT_PRE_PROCESS_MATRIX_H

void addSoilToMatrix(int size, double** matrixPainting, double** terrainMatrix);
void addWaterToMatrix(double** matrix, double** terrainMatrix);
void addVegetationToMatrix(int size, double** matrixPainting, double** terrainMatrix);
void addRoadToMatrix(double** matrix, double** terrainMatrix);
void addMineToMatrix(double** matrix, double** terrainMatrix);

#endif //P1_PROJECT_PRE_PROCESS_MATRIX_H
