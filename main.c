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
#include "Visualization/pre_process_matrix.h"
#include "Visualization/matrix_manipulations.h"

int main() {
    setbuf(stdout,0);

    // Initialize user settings
    userSettings userSettings = obtain_user_settings();
    int size = userSettings.additional_settings.size;

    // Generate list of mock matrices
    // [0] = soil
    // [1] = water
    // [2] = vegetation
    // [3] = roads
    // [4] = steepness
    // [5] = mines
    double*** list_of_matrices = generateListOfMockMatrices(100, 6);

    // Create matrix painting based off of mock matrices (Save the current version of terrain matrices before configuration)
    double** matrix_painting = createMatrixPainting(size, list_of_matrices);

    //Configure list of mock matrices
    WeightedMatrix* list_of_configured_matrices = ConfigureListOfMatrices(list_of_matrices, &userSettings);

    // Process the matrix and combine them into final matrix.
    double** processedMatrix = processMatrix(list_of_configured_matrices, 6, size);

    // Run Dijkstra algorithm.
    int start_pos[2] = {99, 30};
    int end_pos[2] = {5, 60};
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









