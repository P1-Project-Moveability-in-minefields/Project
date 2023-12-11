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
#include "Visualization/matrix_manipulations.h"

int main() {
    setbuf(stdout,0);

    // Initialize user settings
    userSettings userSettings = obtain_user_settings();
    int size = userSettings.additional_settings.size;

    // Generate list of mock matrices
    double*** list_of_matrices = generateListOfMockMatrices(100, 6);

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            printf("%lf ", list_of_matrices[2][i][j]);
        }
        printf("\n");
    }

    // Create matrix painting based off of mock matrices (Save the current version of terrain matrices before configuration)
    double** matrix_painting = createMatrixPainting(size, list_of_matrices);

    //Configure list of mock matrices
    WeightedMatrix* list_of_configured_matrices = ConfigureListOfMatrices(list_of_matrices, &userSettings);

    // Process the matrix and combine them into final matrix.
    double** processedMatrix = processMatrix(list_of_configured_matrices, 6, size);

    int start_pos[2] = {0, 0};
    int end_pos[2] = {99, 0};

    result* optimal_route = dijkstra(processedMatrix, size, start_pos, end_pos);

    if (optimal_route == NULL){
        perror("No route can be found. Aborting...");
        exit(EXIT_FAILURE);
    }

    // Add the optimal route to the matrix painting, to be visualized.
    addOptimalRouteToMatrix(size, matrix_painting, optimal_route->path, optimal_route->path_length);

    // Export matrix painting for visualization in python.
    exportMatrixToFile(size, size, matrix_painting);

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










