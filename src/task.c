#include <stdio.h>
#include <stdlib.h>
#include "../include/deque.h"
#include "../include/structs.h"
#include "../include/interface.h"

Err push_late(Deque* deque, VectorPerson* late, long* idx){
    Err err = SUCCESS;
    if(late -> count > 0 && *idx < late -> count && *idx >= 0){
        if(late -> people[*idx].priority && *idx < late -> count){
            err = push_front(deque, &late -> people[*idx]);
        }else{
            err = push_back(deque, &late -> people[*idx]);
        }
        if(err == SUCCESS){
            (*idx)++;
        }
        error_check(err);
    }else{
        err = ERR;
    }
    return err;
}

void simulate_clinic(Deque* deque, VectorPerson* late){
    Person* in_use = pop_front(deque);
    long idx = 0;       
    int is_using = 0;
    size_t time_global = 1, time_taken = 1, wrote = 0;
    push_late(deque, late, &idx);
    
    while(deque -> count > 0 || idx < late -> count){
        if(is_using && time_global < in_use -> ts + time_taken){ // someone inside
            time_global = in_use -> ts + time_taken;
            wrote = 0;
        }else if(is_using && time_global == in_use -> ts + time_taken){ // one has finished, add next
            is_using = 0;
            free((void*)in_use->id);
            free(in_use);
            if(deque -> count > 0){
                in_use = pop_front(deque);
                time_taken = time_global;
                if(!wrote){
                    printf("\n%zu\n%s  ", time_global, in_use->id);
                    all_data(deque);
                    wrote = 1;
                }if(idx < late -> count){
                    push_late(deque, late, &idx);
                }
            }else{
                in_use = NULL;
            }
        }else if(!is_using && in_use && time_global >= in_use -> ta){ // one has finished, align time for next
            if(!wrote){
                printf("\n%zu\n%s  ", time_global, in_use -> id);
                all_data(deque);
                wrote = 1;
            }
            is_using = 1;
            time_taken = time_global;
        } 
        else if(!is_using && (!in_use || time_global < in_use -> ta)){ // no one is there yet
            wrote = 0;
            time_global = in_use -> ta;
            if(!in_use && deque -> count == 0 && idx < late -> count){
                push_late(deque, late, &idx);
                if(deque -> count > 0){
                    in_use = pop_front(deque);
                }
            }
        }
    }if(in_use) {
        free((void*)in_use -> id);
        free(in_use);
    }
}