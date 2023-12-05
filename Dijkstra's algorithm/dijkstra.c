#include "dijkstra.h"
#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

result *dijkstra(double **input, int size, const int start_pos[], const int end_pos[]){
    entry matrix[size][size]; // Declaration of graph

    int queue_size = size*size;
    entry *priority_queue[queue_size]; // Declaration of priority queue

    entry *root_entry = &matrix[start_pos[0]][start_pos[1]];
    entry *goal = &matrix[end_pos[0]][end_pos[1]];

    //Initialization of graph and priority queue
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j].pos[0] = i;
            matrix[i][j].pos[1] = j;
            matrix[i][j].weight = input[i][j];
            matrix[i][j].current_cost = INFINITY;
            matrix[i][j].previous = NULL;

            add_to_queue(priority_queue, &matrix[i][j], i*size+j);
        }
    }

    // The starting node is initialized separately, as it differs from the rest
    root_entry->current_cost = root_entry->weight;
    decrease_entry(priority_queue, start_pos[0]*size+start_pos[1]);

    // Loop keeps running until the end node is explored
    while (goal->priority_status != -1){ // Priority status of -1 indicates that node is no longer in queue
        entry *current_entry = extract_min(priority_queue, &queue_size); // current entry = node with highest priority in queue

        int *current_pos = current_entry->pos;
        entry *neighbors[4];

        int neighbor_index = 0; // keeps track of number of valid neighbors

        if(current_pos[1]-1 >= 0 && matrix[current_pos[0]][current_pos[1]-1].priority_status != -1){ // Checks if neighbor is valid and has not been explored
            neighbors[neighbor_index] = &matrix[current_pos[0]][current_pos[1]-1]; // left neighbor
            neighbor_index++;
        }
        if(current_pos[0]-1 >= 0 && matrix[current_pos[0]-1][current_pos[1]].priority_status != -1){
            neighbors[neighbor_index] = &matrix[current_pos[0]-1][current_pos[1]]; // up neighbor
            neighbor_index++;
        }
        if(current_pos[1]+1 < size && matrix[current_pos[0]][current_pos[1]+1].priority_status != -1){
            neighbors[neighbor_index] = &matrix[current_pos[0]][current_pos[1]+1]; // right neighbor
            neighbor_index++;
        }
        if(current_pos[0]+1 < size && matrix[current_pos[0]+1][current_pos[1]].priority_status != -1){
            neighbors[neighbor_index] = &matrix[current_pos[0]+1][current_pos[1]]; // down neighbor
            neighbor_index++;
        }

        // Loops through every neighbor
        for (int i = 0; i < neighbor_index; i++){
            double path_cost = current_entry->current_cost + neighbors[i]->weight;
            if(path_cost < neighbors[i]->current_cost){ // Checks if a better alternative path has been found
                neighbors[i]->current_cost = path_cost;
                neighbors[i]->previous = current_entry;
                decrease_entry(priority_queue, neighbors[i]->priority_status); // Updates placement of neighbor in priority queue
            }
        }
    }

    return backtrace_path(goal, size); // path is backtracked and returned
}

result *backtrace_path(entry *path_section, int size) {
    // Declaration of array of coordinates. Will be used to store path
    int **path_array = (int **) malloc(sizeof(int *) * (size * size)); // (size * size) provides the upper bound of number of nodes in optimal path.

    // Declaration of array of length 2 in which coordinates will be stored
    for (int i = 0; i < size * size; ++i) {
        path_array[i] = (int *) malloc(2 * sizeof(int));
    }

    int current_index = 0; // Keeps track of number of nodes in path (path length)

    while (path_section->previous != NULL) { // Loop keeps iterating until staring node has been reached
        path_array[current_index][0] = path_section->pos[0];
        path_array[current_index][1] = path_section->pos[1];
        path_section = path_section->previous;
        current_index++;
    }

    // Add starting node to path
    path_array[current_index][0] = path_section->pos[0];
    path_array[current_index][1] = path_section->pos[1];
    current_index++;

    // Excess storage is cut off, now that we know the "path length",
    realloc(path_array, sizeof(path_array[0]) * (current_index));

    // Declare and initialize result struct
    result *shortest_path = (result *)malloc(sizeof(result));
    shortest_path->path = path_array;
    shortest_path->path_length = current_index;

    return shortest_path;
}
