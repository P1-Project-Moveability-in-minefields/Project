#ifndef P1_PROJECT_DIJKSTRA_H
#define P1_PROJECT_DIJKSTRA_H

#include "priority_queue.h"

typedef struct{
    int **path;
    int path_length;
}result;

result *dijkstra(double **input, int size, const int start_pos[], const int end_pos[]);
result *backtrace_path(entry *goal, int size);

#endif //P1_PROJECT_DIJKSTRA_H
