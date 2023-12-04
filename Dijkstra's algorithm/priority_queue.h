#ifndef P1_PROJECT_PRIORITY_QUEUE_H
#define P1_PROJECT_PRIORITY_QUEUE_H

struct entry;

typedef struct{
    int pos[2];
    double weight;
    double current_cost;
    struct entry *previous;
    int priority_status;
}entry;

void add_to_queue(entry *queue[], entry *element, int index);
void decrease_entry(entry *queue[], int child_index);
void swap_entries(entry **e1, entry **e2);
entry *extract_min(entry *queue[], int *queue_size);

#endif //P1_PROJECT_PRIORITY_QUEUE_H
