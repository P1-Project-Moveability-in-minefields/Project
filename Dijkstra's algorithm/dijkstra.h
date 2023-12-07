#ifndef P1_PROJECT_DIJKSTRA_H
#define P1_PROJECT_DIJKSTRA_H

#include "priority_queue.h"

typedef struct{
    int **path; // array containing coordinates of path segments
    int path_length; // number of nodes in path
}result;

/// Finds the optimal path based on user_settings and a weighted sum of the input data
///
/// Parameters:
/// \param input (double **) is a 2D-array containing the "cost" of every grid_cell of a geographical area.
/// \param size (int) is the dimension of the 2D-array.
/// \param start_pos (int [2]) array containing the coordinates of the starting position
/// \param end_pos (int [2]) array containing the coordinates of the starting position
/// \return a pointer to a result struct, which contains the path and its length. If no path was found NULL is returned
result *dijkstra(double **input, int size, const int start_pos[], const int end_pos[]);

/// Backtracks the path found by dijktra()
///
/// Parameters:
/// \param goal (entry *) is the end node. Every node stores the previous node in the path.
/// \param size (int) is the dimension of the 2D-array, that represents the graph.
/// \return returns a pointer to a result struct, which contains the path and its length
result *backtrace_path(entry *goal, int size);

entry **declare_graph(int size);

void initialization(int size, entry **priority_queue, entry **matrix, double **input);

void find_valid_neighbors(const int *current_pos, entry **matrix, int *neighbor_index, entry *neighbors[4], int size);

void add_to_path(int **path_array, int current_index, entry *path_section);

int **declare_path_array(int size);

void visit_valid_neighbors(int neighbor_index, entry *current_entry, entry *neighbors[4], entry **priority_queue);
#endif //P1_PROJECT_DIJKSTRA_H