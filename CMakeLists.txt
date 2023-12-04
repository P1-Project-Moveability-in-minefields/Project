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
        "Relationship Methods/RelationshipMethods.c"
        "Relationship Methods/RelationshipMethods.h")
