cmake_minimum_required(VERSION 3.26)
project(P1_Project C)

set(CMAKE_C_STANDARD 11)

add_executable(P1_Project main.c
        "Dijkstra's algorithm/dijkstra.c"
        "Dijkstra's algorithm/dijkstra.h"
        "Dijkstra's algorithm/priority_queue.c"
        "Dijkstra's algorithm/priority_queue.h"
        "Databehandling/userPreferences.c"
        "Databehandling/userPreferences.h"
        "Configuration Of Matrices/RelationshipMethods.c"
        "Configuration Of Matrices/RelationshipMethods.h"
        "Configuration Of Matrices/ConfigureMatrices.c"
        "Configuration Of Matrices/ConfigureMatrices.h"
        Visualization/exportMatrixToFile.c
        Visualization/pre_process_matrix.c
        Bitmap/bmp_import.c
        Bitmap/bmp_import.h
        Visualization/matrix_manipulations.h
        Visualization/matrix_manipulations.c)

target_link_libraries(P1_Project m)
