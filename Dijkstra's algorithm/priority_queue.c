#include "priority_queue.h"

void add_to_queue(entry *queue[], entry *key, int index){
    queue[index] = key;
    key->priority_status = index;
}

void decrease_entry(entry *queue[], int child_index){
    int parent_index = child_index/2;
    while (queue[child_index]->current_cost < queue[parent_index]->current_cost){
        swap_entries(&queue[child_index], &queue[parent_index]); //function does not swap priority_status

        //Update indicies
        child_index = parent_index;
        parent_index = child_index/2;
    }
}

entry *extract_min(entry *queue[], int *queue_size){
    entry *entry_to_return = queue[0];
    entry_to_return -> priority_status = -1;
    queue[0] = queue[*queue_size-1];
    queue[0] -> priority_status = 0;
    *queue_size -= 1;

    int index = 0, valid_left_child = 0, valid_right_child = 0, greater_than_right_child, greater_than_left_child;
    entry **left_child, **right_child;

    if(2*index+1 < *queue_size){
        left_child = &queue[2*index+1];
        greater_than_left_child = queue[index]->current_cost > (*left_child)->current_cost;
        valid_left_child = 1;
    }
    if(2*(index+1) < *queue_size){
        right_child = &queue[2*(index+1)];
        greater_than_right_child = queue[index]->current_cost > (*right_child)->current_cost;
        valid_right_child = 1;
    }

    while (greater_than_left_child || greater_than_right_child){
        if(valid_left_child && queue[index]->current_cost > (*left_child)->current_cost){
            swap_entries(&queue[index], &(*left_child));
            index = 2*index+1;
            valid_left_child = 0;
        } else if(valid_right_child && queue[index]->current_cost > (*right_child)->current_cost){
            swap_entries(&queue[index], &(*right_child));
            index = 2*(index+1);
            valid_right_child = 0;
        } else return entry_to_return;

        if(2*index+1 < *queue_size){
            left_child = &queue[2*index+1];
            greater_than_left_child = queue[index]->current_cost > (*left_child)->current_cost;
            valid_left_child = 1;
        }
        if(2*(index+1) < *queue_size){
            right_child = &queue[2*(index+1)];
            greater_than_right_child = queue[index]->current_cost > (*right_child)->current_cost;
            valid_right_child = 1;
        }

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

