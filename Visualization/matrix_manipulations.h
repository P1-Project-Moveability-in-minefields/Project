//
// Created by Andreas Lynnerup on 11/12/2023.
//

#ifndef P1_PROJECT_MATRIX_MANIPULATIONS_H
#define P1_PROJECT_MATRIX_MANIPULATIONS_H

/// Rotates a matrix 90 degrees clockwise as if it was laying on the table.
/// \param matrix (double**), the matrix to rotate.
/// \param numRows (int), the dimensions (rows) of the matrix.
/// \param numCols (int), the dimensions (colmumns) of the matrix.
void rotate90Clockwise(double** matrix, int numRows, int numCols);

/// Flips a matrix horizontally, meaning around the x-axis.
/// \param matrix (double**), the matrix to flip.
/// \param numRows (int), the dimensions (rows) of the matrix.
/// \param numCols (int), the dimensions (colmumns) of the matrix.
void flipHorizontally(double** matrix, int numRows, int numCols);

/// Imports a number of matrices based on hardcoded paths.
/// \param size (int), the size of the matrices that will be imported.
/// \param numberOfMatrices (int), the amount of matrices to import.
/// \return (double***), returns an array with all the matrices that has been imported.
double*** generateListOfMockMatrices(int size, int numberOfMatrices);

#endif //P1_PROJECT_MATRIX_MANIPULATIONS_H
