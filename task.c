#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
#include "structs.h"

void all_data(Deque* deque){
    if(deque -> count > 0){
        if(deque -> type == VECTOR){
            for(size_t i = 0; i < deque -> count; i++){
                Person* curr_item = &((Person*)deque -> data)[((Person*)deque -> head -
                    (Person*)deque -> data + i + deque -> size) % deque -> size];
                printf(" %s ", curr_item -> id);
            }
        }else{
            ListPerson* curr = ((ListPerson*)deque -> data);
            while(curr != NULL){
                if(curr -> self != NULL){
                    printf(" %s ", curr -> self -> id);
                }curr = curr -> next;
            }
        }
    }printf("\n");
}

void simulate_clinic(Deque* deque){
    Person* in_use = pop_front(deque);
    int is_using = 0;
    size_t time = 1, tt = 1, wrote = 0; // time when a guy was actually taken

    while(deque -> count > 0){
        if(is_using && time < in_use -> ts + tt){ // someone inside
            time++;
            wrote = 0;
        }else if(is_using && time == in_use -> ts + tt){ // just freed
            is_using = 0;
            in_use = pop_front(deque);
            tt = time;
            if(!wrote){
                printf("\n%zu\n%s  ", time, in_use -> id);
                all_data(deque);
                wrote = 1;
            }
        }else if(!is_using && time >= in_use -> ta){ // new fella got taken
            if(!wrote){
                printf("\n%zu\n%s  ", time, in_use -> id);
                all_data(deque);
                wrote = 1;
            }is_using = 1;
            tt = time;
        }else if(!is_using && time < in_use -> ta){ // no one is there
            wrote = 0;
            time++;
        }
    }
}