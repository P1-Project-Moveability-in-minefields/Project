#include <stdio.h>
#include "Dijkstra's algorithm/dijkstra.h"
#include "Databehandling/userPreferences.h"
#include "Configuration Of Matrices/RelationshipMethods.h"
#include "Configuration Of Matrices/ConfigureMatrices.h"
#include "Visualization/exportMatrixToFile.h"
#include "Bitmap/bmp_import.h"
#include <stdlib.h>
#include <time.h>
#include "Visualization/pre_process_matrix.h"
#include "Configuration Of Matrices/matrix_manipulations.h"

int main() {

    // Initialize user settings
    userSettings userSettings = obtain_user_settings();
    int size = userSettings.additionalSettings.size;

    // Generate list of mock matrices
    // [0] = soil
    // [1] = water
    // [2] = vegetation
    // [3] = roads
    // [4] = steepness
    // [5] = mines
    double*** listOfMatrices = generate_list_of_matrices(100, 6);

    // Create matrix painting based off of mock matrices (Save the current version of terrain matrices before configuration)
    double** matrixPainting = create_matrix_painting(size, listOfMatrices);

    //Configure list of mock matrices
    weightedMatrix * listOfConfiguredMatrices = configure_list_of_matrices(listOfMatrices, &userSettings);

    // Process the matrix and combine them into final matrix.
    double** processedMatrix = process_matrix(listOfConfiguredMatrices, 6, size);

    // Run Dijkstra algorithm.
    int startPos[2] = {70, 95};
    int endPos[2] = {20, 2};
    result* optimalRoute = dijkstra(processedMatrix, size, startPos, endPos);

    if (optimalRoute == NULL){
        perror("No route can be found. Aborting...");
        exit(EXIT_FAILURE);
    }

    // Add the optimal route to the matrix painting, to be visualized.
    add_optimal_route_to_matrix(size, matrixPainting, optimalRoute->path, optimalRoute->path_length);

    // Export matrix painting for visualization in python.
    export_matrix_to_file(size, size, matrixPainting);

    return 0;
}









