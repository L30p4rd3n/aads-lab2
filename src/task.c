#include <stdio.h>
#include <stdlib.h>
#include "../include/deque.h"
#include "../include/structs.h"
#include "../include/interface.h"

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
            Person* in_use = pop_front(deque);
            tt = time;
            if(!wrote){
                printf("\n%zu\n%s  ", time, in_use -> id);
                all_data(deque);
                free(in_use -> id);
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
    if(in_use -> id != NULL){
        free(in_use -> id);
    }
}