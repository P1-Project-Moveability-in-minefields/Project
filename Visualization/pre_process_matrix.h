//
// Created by Andreas Lynnerup on 06/12/2023.
//

#ifndef P1_PROJECT_PRE_PROCESS_MATRIX_H
#define P1_PROJECT_PRE_PROCESS_MATRIX_H

///
/// Generates a matrix where each cell corresponds to a color in a seperate python script.
/// \param size
/// \param list_of_matrices
/// \return matrix of type double with values between 0 and 1.1, each corresponding to a specific color.
/// \remarks Must receive a list of all matrices to be expected. An incomplete list_of_matrices will not work as intended
/// \example { \n {0.2, 0.3, 0.2, 0.4, 0.4}, \n {0.2, 0.2, 0.2, 0.6, 0.8} \n {1.0, 0.7, 0.9, 1.1, 1.1} \n }
double** createMatrixPainting(int size,
                              double*** list_of_matrices);

/// For each step in the optimal route, paints this step into the matrix painting
/// \param size
/// \param matrix
/// \param optimal_route
/// \param number_of_steps
void addOptimalRouteToMatrix(int size, double** matrix, int** optimal_route, int number_of_steps);

/// Paints each cell in the matrixPainting either 0.0 or 0.1.
/// \param size
/// \param matrix
/// \param terrainMatrix
void addSoilToMatrix(int size, double** matrix, double** terrainMatrix);

/// Paints each cell in the matrixPainting either 0.2 or 0.3
/// \param size
/// \param matrix
/// \param terrainMatrix
void addWaterToMatrix(int size, double** matrix, double** terrainMatrix);

/// Paints each cell int he matrixPainting either 0.4, 0.5 for swampy areas, or 0.6
/// \param size
/// \param matrix
/// \param terrainMatrix
void addVegetationToMatrix(int size, double** matrix, double** terrainMatrix);

/// Paints each cell in the matrixPainting either 0.7 or 0.8
/// \param size
/// \param matrix
/// \param terrainMatrix
void addRoadToMatrix(int size, double** matrix, double** terrainMatrix);

/// Paints each cell in the matrixPainting either 0.9 or 1
/// \param size
/// \param matrix
/// \param terrainMatrix
void addMineToMatrix(int size, double** matrix, double** terrainMatrix);


#endif //P1_PROJECT_PRE_PROCESS_MATRIX_H
