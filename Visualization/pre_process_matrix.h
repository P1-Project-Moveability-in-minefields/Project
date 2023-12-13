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
double** create_matrix_painting(int size,
                              double*** list_of_matrices);

/// For each step in the optimal route, paints this step into the matrix painting
/// \param size
/// \param matrix
/// \param optimal_route
/// \param number_of_steps
void add_optimal_route_to_matrix(int size, double** matrix, int** optimal_route, int number_of_steps);

/// Paints each cell in the matrixPainting either 0.0 or 0.1.
/// \param size
/// \param matrix
/// \param terrainMatrix
void add_soil_to_matrix(int size, double** matrix, double** terrainMatrix);

/// Paints each cell in the matrixPainting either 0.2 or 0.3
/// \param size
/// \param matrix
/// \param terrainMatrix
void add_water_to_matrix(int size, double** matrix, double** terrainMatrix);

/// Determines whether to add vegetation or to add swamplands.
/// \param size
/// \param matrix
/// \param terrainMatrix
void add_vegetation_or_swampland_to_matrix(int size, double** matrix, double** terrainMatrix);

/// Paints each cell in the matrixPainting either 0.5 or 0.6 for swampy areas
/// \param lastCellWasSwamp (int*), reference to whether the last cell was determined to be a swampland.
/// \param terrainCell (double), the value of the current terrain map cell.
/// \param matrixCell (double*), reference to the matrix cell that needs to be painted.
void add_swamp_to_matrix(int* lastCellWasSwamp,  double terrainCell, double* matrixCell);

/// Paints each cell in the matrixPainting either 0.5 for low vegetation or 0.6 for high
/// \param terrainCell (double), the value of the current terrain map cell.
/// \param matrixCell (double*), reference to the matrix cell that needs to be painted.
void add_vegetation_to_matrix(double terrainCell, double* matrixCell);

/// Paints each cell in the matrixPainting either 0.7 or 0.8
/// \param size
/// \param matrix
/// \param terrainMatrix
void add_road_to_matrix(int size, double** matrix, double** terrainMatrix);

/// Paints each cell in the matrixPainting either 0.9 or 1
/// \param size
/// \param matrix
/// \param terrainMatrix
void add_mine_to_matrix(int size, double** matrix, double** terrainMatrix);


#endif //P1_PROJECT_PRE_PROCESS_MATRIX_H
