#include <stdio.h>
#include <stdlib.h>
#include "../include/structs.h"
#include "../include/deque.h"
#include "../include/deque_list.h"
#include "../include/deque_vector.h"

Deque* new_deque(Types type, long size){
    Deque* deque = malloc(sizeof(Deque));
    deque -> count = 0;
    deque -> size = size;
    deque -> type = type;
    switch (type){
        case VECTOR:{
            deque -> data = calloc(size, sizeof(Person));
            deque -> head = NULL;
            deque -> tail = NULL;
            break;
        }case LIST:{
            deque -> data = NULL;
            deque -> head = NULL;
            deque -> tail = NULL;
            break;
        }
    }return deque;
}
Err push_front(Deque* deque, Person* person){
    Err res;
    switch (deque -> type){
        case VECTOR:{
            res = push_front_vector(deque, person);
            break;
        }case LIST:{
            res = push_front_list(deque, person);
            break;
        }
    }return res;
}

Err push_back(Deque* deque, Person* person){
    Err res;
    switch (deque -> type){
        case VECTOR:{
            res = push_back_vector(deque, person);
            break;
        }case LIST:{
            res = push_back_list(deque, person);
            break;
        }
    }return res;
}

Person* pop_front(Deque* deque){
    switch (deque -> type){
        case VECTOR:{
            return pop_front_vector(deque);
            break;
        }case LIST:{
            return pop_front_list(deque);
        }
    }return NULL; 
}
Person* pop_back(Deque* deque){
    switch (deque -> type){
        case VECTOR:{
            return pop_back_vector(deque);
            break;
        }case LIST:{
            break;
        }
    }return NULL; 
}
