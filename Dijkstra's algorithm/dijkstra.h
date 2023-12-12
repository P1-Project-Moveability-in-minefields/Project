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
/// \return returns a pointer to a result struct, which contains the path and its length.
result *backtrace_path(entry *goal, int size);

/// Dynamically allocates space for a 2D-array of entries. Remember to free memory.
///
/// Parameters:
/// \param size (int) is the size of the 2D-array.
/// \return returns a pointer to the first element of the allocated 2D-array.
entry **declare_graph(int size);

/// Initializes a 2D-array of entries using data from input matrix. Priority queue is also initialized.
///
/// Parameters:
/// \param priority_queue (entry **) array of pointers to entries.
/// \param size (int) is the dimension of the 2D-array/graph.
/// \param matrix (entry **) 2D-array of entries. This is the implementation of a graph which models a minefield.
/// \param input (double **) array containing the "cost" of every node in the graph.
void initialization(int size, entry **priority_queue, entry **matrix, double **input);

/// Finds valid adjacent nodes of a node.
///
/// Parameters:
/// \param current_pos (const int *) pointer to the coordinates of the node, whose neighbors are to be found.
/// \param matrix (entry **) 2D-array of entries. This is the implementation of a graph which models a minefield.
/// \param neighbor_index (int *) pointer to variable which stores the number of valid neighboring nodes.
/// \param neighbors (entry * [4]) array containg pointers to valid neighbors.
/// \param size (int) is the dimension of the 2D-array/graph.
void find_valid_neighbors(const int *current_pos, entry **matrix, int *neighbor_index, entry *neighbors[4], int size);

/// Adds coordinates of a node to a path.
///
/// Parameters:
/// \param path_array (int **) array containing the coordinates of a path.
/// \param current_index (int) current length of path_array.
/// \param path_section (entry *) pointer to the node, whose coordinates will be added to path.
void add_to_path(int **path_array, int current_index, entry *path_section);

/// Dynamically allocates memory for an array of int[2] arrays. Remember to free memory.
///
/// Parameters:
/// \param size (int) is the size of the array being allocated.
/// \return returns pointer to the first element of the allocated array.
int **declare_path_array(int size);

/// Loops through valid adjacent nodes of a given node and updates their path_cost and position in priority queue.
///
/// Parameters:
/// \param neighbor_index (int) number of valid adjacent nodes.
/// \param current_entry (entry *) pointer to node, whose neighbors will be visited.
/// \param neighbors (entry * [4]) array containing pointers to valid neighbors.
/// \param priority_queue (entry **) array of pointers to entries.
void visit_valid_neighbors(int neighbor_index, entry *current_entry, entry *neighbors[4], entry **priority_queue);
#endif //P1_PROJECT_DIJKSTRA_H