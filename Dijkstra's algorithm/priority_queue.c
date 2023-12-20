#include "priority_queue.h"

void add_to_queue(entry *queue[], entry *key, int index){
    queue[index] = key;
    key->priority_status = index;
}

void decrease_entry(entry *queue[], int child_index){
    int parent_index = (child_index-1)/2;
    while (queue[child_index]->current_cost < queue[parent_index]->current_cost){
        swap_entries(&queue[child_index], &queue[parent_index]); //function does not swap priority_status

        //Update indicies
        child_index = parent_index;
        parent_index = (child_index-1)/2;
    }
}

entry *extract_min(entry *queue[], int *queue_size){
    entry *entry_to_return = queue[0];
    entry_to_return -> priority_status = -1; // -1 signifies that the entry is no longer in the queue
    queue[0] = queue[*queue_size-1]; // last element becomes first element
    queue[0] -> priority_status = 0; // status for the currently new first element is updated.
    *queue_size -= 1;

    int index = 0;
    int left_index = left_child_index(index, queue, queue_size); // -1 is returned if left_child does not exist or if left_child is correctly located
    int right_index = right_child_index(index, queue, queue_size); // -1 is returned if right_child does not exist or if right_child is correctly located

    while (left_index != -1 || right_index != -1){
        int min_index;

        if (left_index != -1 && right_index != -1) {
            min_index = (queue[left_index]->current_cost < queue[right_index]->current_cost) ? left_index : right_index;
        } else if (left_index != -1){
            min_index = left_index;
        } else{
            min_index = right_index;
        }
        swap_entries(&queue[index], &queue[min_index]);
        index = min_index;

        left_index = left_child_index(index, queue, queue_size);
        right_index = right_child_index(index, queue, queue_size);
    }

    return entry_to_return;
}

void swap_entries(entry **e1, entry **e2){
    entry *temp = *e1;
    *e1 = *e2;
    *e2 = temp;

    int temp_int;
    temp_int = (*e1)->priority_status;
    (*e1)->priority_status = (*e2)->priority_status;
    (*e2)->priority_status = temp_int;
}

int left_child_index(int index, entry **queue, const int *queue_size){
    int child_index = 2*index+1;
    if(child_index < *queue_size){
        if(queue[index]->current_cost > queue[child_index]->current_cost){
            return child_index;
        }
    }
    return -1;
}

int right_child_index(int index, entry **queue, const int *queue_size){
    int child_index = 2*(index+1);
    if(child_index < *queue_size){
        if(queue[index]->current_cost > queue[child_index]->current_cost){
            return child_index;
        }
    }
    return -1;
}