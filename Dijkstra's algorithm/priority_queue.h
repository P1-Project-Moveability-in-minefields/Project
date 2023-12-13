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

/// Adds a node to a priority queue
/// \param queue (entry *) the priority queue in to which the node will be added
/// \param element (entry *) the node that will be added to queue
/// \param index (int) placement in queue where node will be added
void add_to_queue(entry *queue[], entry *element, int index);

/// Updates placement of node in a priority queue
/// \param queue (entry *) priority queue of pointers to nodes
/// \param child_index (int) the index of the node whose placement in queue is updated
void decrease_entry(entry *queue[], int child_index);

/// Swaps the placement of two nodes in a priority queue
/// \param e1 (entry **) pointer to a node in queue
/// \param e2 (entry **) pointer to another node in queue
void swap_entries(entry **e1, entry **e2);

/// Extracts and returns first node from a priority queue. The last node in the queue becomes the first node. The queue is updated.
/// \param queue (entry **) priority queue of pointers to nodes.
/// \param queue_size (int *) pointer to variable containing the size of the priority queue.
/// \return returns a pointer to the first node in the priority queue.
entry *extract_min(entry *queue[], int *queue_size);

/// \param index (int) index of a node in a binary heap
/// \param queue (entry **) priority queue implemented as a binary heap
/// \param queue_size (const int *) size of queue
/// \return returns the index of right_child if such exists and is higher prioritized than its parent. Otherwise -1 is returned
int right_child_index(int index, entry **queue, const int *queue_size);

/// \param index (int) index of a node in a priority queue
/// \param queue (entry **) priority queue implemented as a binary heap
/// \param queue_size (const int *) size of queue
/// \return returns the index of left_child if such exists and is higher prioritized than its parent. Otherwise -1 is returned
int left_child_index(int index, entry **queue, const int *queue_size);

#endif //P1_PROJECT_PRIORITY_QUEUE_H
