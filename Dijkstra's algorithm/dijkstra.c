#include "dijkstra.h"
#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

result *dijkstra(int **input, int size, const int start_pos[], const int end_pos[]){
    int queue_size = size*size;
    entry matrix[size][size];
    entry *priority_queue[queue_size];
    entry *root_entry = &matrix[start_pos[0]][start_pos[1]];
    entry *goal = &matrix[end_pos[0]][end_pos[1]];

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

    root_entry->current_cost = root_entry->weight;

    decrease_entry(priority_queue, start_pos[0]*size+start_pos[1]);

    while (goal->priority_status != -1){
        entry *current_entry = extract_min(priority_queue, &queue_size);
        int *current_pos = current_entry->pos;
        entry *neighbors[4];

        int neighbor_index = 0;

        if(current_pos[1]-1 >= 0 && matrix[current_pos[0]][current_pos[1]-1].priority_status != -1){
            neighbors[neighbor_index] = &matrix[current_pos[0]][current_pos[1]-1]; // left
            neighbor_index++;
        }
        if(current_pos[0]-1 >= 0 && matrix[current_pos[0]-1][current_pos[1]].priority_status != -1){
            neighbors[neighbor_index] = &matrix[current_pos[0]-1][current_pos[1]]; // up
            neighbor_index++;
        }
        if(current_pos[1]+1 < size && matrix[current_pos[0]][current_pos[1]+1].priority_status != -1){
            neighbors[neighbor_index] = &matrix[current_pos[0]][current_pos[1]+1]; // right
            neighbor_index++;
        }
        if(current_pos[0]+1 < size && matrix[current_pos[0]+1][current_pos[1]].priority_status != -1){
            neighbors[neighbor_index] = &matrix[current_pos[0]+1][current_pos[1]]; // down
            neighbor_index++;
        }

        for (int i = 0; i < neighbor_index; i++){
            int path_cost = current_entry->current_cost + neighbors[i]->weight;
            if(path_cost < neighbors[i]->current_cost){
                neighbors[i]->current_cost = path_cost;
                neighbors[i]->previous = current_entry;
                decrease_entry(priority_queue, neighbors[i]->priority_status);
            }

        }
    }
    return backtrace_path(goal, size);
}

result *backtrace_path(entry *path_section, int size) {
    int **path_array = (int **) malloc(sizeof(int *) * (size * size));

    for (int i = 0; i < size * size; ++i) {
        path_array[i] = (int *) malloc(2 * sizeof(int));
    }

    int current_index = 0;
    while (path_section->previous != NULL) {
        path_array[current_index][0] = path_section->pos[0];
        path_array[current_index][1] = path_section->pos[1];
        path_section = path_section->previous;
        current_index++;
    }
    path_array[current_index][0] = path_section->pos[0];
    path_array[current_index][1] = path_section->pos[1];
    current_index++;
    realloc(path_array, sizeof(path_array[0]) * (current_index));

    result *shortest_path = (result *)malloc(sizeof(result));
    shortest_path->path = path_array;
    shortest_path->path_length = current_index;

    return shortest_path;
}
