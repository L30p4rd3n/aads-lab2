#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
#include "structs.h"

void all_data(Deque* deque){
    if(deque -> count > 0){
        if(deque -> type == VECTOR){
            for(size_t i = 0; i < deque -> count; i++){
                Person* curr_item = &((Person*)deque -> data)[((Person*)deque -> head -
                    (Person*)deque -> data + i) % deque -> size];
                printf(" %s ", curr_item -> id);
            }
        }else{
            ListPerson* curr = ((ListPerson*)deque -> data);
            while(curr -> next != NULL){
                if(curr -> self != NULL){
                    printf(" %s ", curr -> self->id);
                }
            }
        }
    }printf("\n");
}

void simulate_clinic(Deque* deque){
    Person* in_use = pop_front(deque);
    int is_using = 0;
    size_t time = 1, tt = 1; // time when a guy was actually taken

    while(deque -> count > 0){
        if(is_using && time < in_use -> ts + tt){ // someone inside
            time++;
        }else if(is_using && time == in_use -> ts + tt){ // just freed
            is_using = 0;
            in_use = pop_front(deque);
            tt = time;
            printf("\n%zu\n", time);
            all_data(deque);
        }else if(!is_using && time >= in_use -> ta){ // new fella got taken
            is_using = 1;
            tt = time;
        }else if(!is_using && time < in_use -> ta){ // no one is there
            time++;
        }
    }
}