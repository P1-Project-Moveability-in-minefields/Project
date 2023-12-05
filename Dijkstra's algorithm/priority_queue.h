#ifndef P1_PROJECT_PRIORITY_QUEUE_H
#define P1_PROJECT_PRIORITY_QUEUE_H

struct entry;

typedef struct{
    int pos[2]; // position in matrix
    double weight; // wight of edges directed to node
    double current_cost; // cost of currently cheapest path to node
    struct entry *previous; // Every node keeps track of the previous node in the path. This makes it possible to backtrack the final path
    int priority_status; // Keeps track of previous
}entry;

/*!
 * @function    add_to_queue
 * @describtion adds a node to a priority queue
 * @param queue the priority queue in to which the node will be added
 * @param element the node node that will
 * @param index
 */
void add_to_queue(entry *queue[], entry *element, int index);


void decrease_entry(entry *queue[], int child_index);
void swap_entries(entry **e1, entry **e2);
entry *extract_min(entry *queue[], int *queue_size);
int right_child_index(int index, entry **queue, const int *queue_size);
int left_child_index(int index, entry **queue, const int *queue_size);

#endif //P1_PROJECT_PRIORITY_QUEUE_H
