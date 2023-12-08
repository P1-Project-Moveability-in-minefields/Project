#include <stdio.h>
#include "Dijkstra's algorithm/dijkstra.h"
#include "Databehandling/userPreferences.h"
#include "Configuration Of Matrices/RelationshipMethods.h"
#include "Configuration Of Matrices/ConfigureMatrices.h"
#include "Visualization/exportMatrixToFile.h"
#include "Bitmap/bmp_import.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
#include "Visualization/pre_process_matrix.h"


void rotate90Clockwise(double** matrix, int numRows, int numCols) {
    // Transpose the matrix
    for (int i = 0; i < numRows; ++i) {
        for (int j = i + 1; j < numCols; ++j) {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Reverse the order of rows
    for (int i = 0; i < numRows / 2; ++i) {
        for (int j = 0; j < numCols; ++j) {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[numRows - 1 - i][j];
            matrix[numRows - 1 - i][j] = temp;
        }
    }
}
void flipHorizontally(double** matrix, int numRows, int numCols) {
    // Reverse the order of columns
    for (int j = 0; j < numCols / 2; ++j) {
        for (int i = 0; i < numRows; ++i) {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[i][numCols - 1 - j];
            matrix[i][numCols - 1 - j] = temp;
        }
    }
}


int main() {

    // Import bitmap funktion
    // Configure matrices
    // Combine matrices
    // Insert into Djikstras
    // Create matrix to be painted
    // Export matrix painting to txt
    userSettings userSettings = obtain_user_settings();

    double** soil_array = import_bmp("./Mock_Values/BMP's/soil.bmp");
    rotate90Clockwise(soil_array, 100, 100);

    double** water_array = import_bmp("./Mock_Values/BMP's/water_levels.bmp");
    rotate90Clockwise(water_array, 100, 100);

    double** vegetation_array = import_bmp("./Mock_Values/BMP's/vegetation.bmp");
    rotate90Clockwise(vegetation_array, 100, 100);
    for (int y = 0; y < 100; y++){
        for (int x = 0; x < 100; x++){
            printf("%lf ", vegetation_array[y][x]);
        }
        printf("\n");
    }
    double** road_array = import_bmp("./Mock_Values/BMP's/roads_and_infrastructure.bmp");
    rotate90Clockwise(road_array, 100, 100);

    double** steepness_array = import_bmp("./Mock_Values/BMP's/steepness.bmp");
    rotate90Clockwise(steepness_array, 100, 100);

    double** mine_array = import_bmp("./Mock_Values/BMP's/mines.bmp");
    rotate90Clockwise(mine_array, 100, 100);


    ConfigureDepthMap(water_array, &userSettings);
    ConfigureVegetationMap(vegetation_array, &userSettings);

    exportMatrixToFile(100, 100, vegetation_array);

    ConfigureRoadQualityMap(road_array, &userSettings);
    ConfigureMineMap(mine_array, &userSettings);
    WeightedMatrix configuredWaterMatrix = {water, water_array, 0};
    WeightedMatrix configuredSoilMatrix = {soil, soil_array, 0};
    WeightedMatrix configuredVegetationMatrix = {vegetation, vegetation_array, 0};
    WeightedMatrix configuredRoadMatrix = {road, road_array, 0};
    WeightedMatrix configuredSteepnessMatrix = {steepness, steepness_array, 0};
    WeightedMatrix configuredMineMatrix = {water, mine_array, userSettings.priority_level.mine_risk};

    WeightedMatrix listOfConfiguredMatrix[6] = {configuredSoilMatrix, configuredWaterMatrix, configuredVegetationMatrix, configuredRoadMatrix, configuredSteepnessMatrix, configuredMineMatrix};


    double** processedMatrix = processMatrix(listOfConfiguredMatrix, 6, 100);
    int start_pos[2] = {99, 1};
    int end_pos[2] = {1, 99};
    


    result* optimal_route = dijkstra(processedMatrix, 100, start_pos, end_pos);

    double** matrixPainting = createMatrixPainting(100, soil_array, water_array, vegetation_array, road_array, mine_array, optimal_route->path, optimal_route->path_length);


    return 0;
}


/*
 *
 *    rotate90Clockwise(soil_array, 100, 100);
    rotate90Clockwise(soil_array, 100, 100);
    rotate90Clockwise(soil_array, 100, 100);
    printf("Reached 2");

    double** water_array = import_bmp("/Users/lynneruup/CLionProjects/p1-project/Mock_Values/BMP's/water_levels.bmp");
    printf("Reached 3");

    ConfigureDepthMap(water_array, &usersettings);
    printf("Reached 4");

    rotate90Clockwise(water_array, 100, 100);
    rotate90Clockwise(water_array, 100, 100);
    rotate90Clockwise(water_array, 100, 100);
    double** vegetation_array = import_bmp("/Users/lynneruup/CLionProjects/p1-project/Mock_Values/BMP's/vegetation.bmp");
    printf("Reached 5");

    ConfigureDepthMap(vegetation_array, &usersettings);
    printf("Reached 6");

    rotate90Clockwise(vegetation_array, 100, 100);
    rotate90Clockwise(vegetation_array, 100, 100);
    rotate90Clockwise(vegetation_array, 100, 100);
    double** road_array = import_bmp("/Users/lynneruup/CLionProjects/p1-project/Mock_Values/BMP's/roads_and_infrastructure.bmp");
    printf("Reached 7");

    ConfigureDepthMap(road_array, &usersettings);
    printf("Reached 8");

    rotate90Clockwise(road_array, 100, 100);
    rotate90Clockwise(road_array, 100, 100);
    rotate90Clockwise(road_array, 100, 100);
    double** mine_array = import_bmp("/Users/lynneruup/CLionProjects/p1-project/Mock_Values/BMP's/mines.bmp");
    printf("Reached 9");
    rotate90Clockwise(mine_array, 100, 100);
    rotate90Clockwise(mine_array, 100, 100);
    rotate90Clockwise(mine_array, 100, 100);
    double** steepness_array = import_bmp("/Users/lynneruup/CLionProjects/p1-project/Mock_Values/BMP's/steepness.bmp");
    printf("Reached 10");
    rotate90Clockwise(steepness_array, 100, 100);
    rotate90Clockwise(steepness_array, 100, 100);
    rotate90Clockwise(steepness_array, 100, 100);

    double*** matricesList = (double***)malloc(5 * sizeof(double**));
    printf("Reached 11");

// Allocate memory for each matrix in the array
    for (int i = 0; i < 5; ++i) {
        matricesList[i] = (double**)malloc(100 * sizeof(double*));
        if (matricesList[i] == NULL) {
            fprintf(stderr, "Failed to allocate memory for matricesList[%d]\n", i);
            // Handle error and return
        }

        for (int j = 0; j < 100; ++j) {
            matricesList[i][j] = (double*)malloc(100 * sizeof(double));
            if (matricesList[i][j] == NULL) {
                fprintf(stderr, "Failed to allocate memory for matricesList[%d][%d]\n", i, j);
                // Handle error and return
            }
        }
    }

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            matricesList[0][i][j] = soil_array[i][j];
            printf("Reached 14: i=%d, j=%d\n", i, j);
            matricesList[1][i][j] = water_array[i][j];
            printf("Reached 15: i=%d, j=%d\n", i, j);
            matricesList[2][i][j] = vegetation_array[i][j];
            matricesList[3][i][j] = road_array[i][j];
            matricesList[4][i][j] = mine_array[i][j];
        }
        printf("Reached 11: i=%d\n", i);
    }
    printf("Reached 12: i=%d\n", 33);


    double** finishedMatrix = (double**)malloc(100 * sizeof(double*));
    printf("Reached 12: i=%d\n", 33);

    for (int i = 0; i < 100; ++i) {
        finishedMatrix[i] = (double*)malloc(100 * sizeof(double));
        printf("Reached 10: i=%d\n", 12);
    }
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            finishedMatrix[i][j] = 0.0;
            printf("Reached 9: i=%d\n", 123);

        }
        printf("Reached 11: i=%d\n", 123);
    }
    printf("Reached 10: i=%d\n", 1222);


    CombineMineMaps(finishedMatrix, matricesList, 5, &usersettings);
    printf("Reached 18");

    int start_row = 99;
    int start_col = 0;
    int end_row = 99;
    int end_col = 1;

    int start_index = start_row * 100 + start_col;
    int end_index = end_row * 100 + end_col;
    int start[2] = {99,1};
    int end[2] = {1, 99};

    result* optimal_route = dijkstra(finishedMatrix, 100, start, end);
    printf("Reached 19");

    createMatrixPainting(100, soil_array, water_array, vegetation_array, road_array, mine_array, optimal_route->path, optimal_route->path_length);
    printf("Reached 20");

    exportMatrixToFile(100, 100, soil_array);
    printf("Reached 21");

    // Import matrix painting in python and visualize.


    for (int i = 0; i < 100; ++i) {
        free(finishedMatrix[i]);
    }
    free(finishedMatrix);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 100; ++j) {
            free(matricesList[i][j]);
        }
        free(matricesList[i]);
    }
    free(matricesList);

 */










