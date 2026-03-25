#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "deque.h"
#include "deque_list.h"
#include "deque_vector.h"

Deque* new_deque(Types type){
    Deque* deque = malloc(sizeof(Deque));
    deque -> count = 0;
    deque -> size = 0;
    deque -> type = type;
    switch (type){
        case VECTOR:{
            deque -> data = calloc(0, sizeof(Person));
            deque -> head = NULL;
            deque -> tail = NULL;
        }case LIST:{
            deque -> data = calloc(1, sizeof(ListPerson));
            ((ListPerson*) deque -> data) -> self = NULL;
            ((ListPerson*) deque -> data) -> next = NULL;
            deque -> head = NULL;
            deque -> tail = NULL;
        }
    }return deque;
}


Deque* push_front(Deque* deque, Person* person){
    switch (deque -> type){
        case VECTOR:{
            deque = push_front_vector(deque, person);
            break;
        }case LIST:{
            deque = push_front_list(deque, person);
            break;
        }
    }return deque;
}

Deque* push_back(Deque* deque, Person* person){
    switch (deque -> type){
        case VECTOR:{
            deque = push_back_vector(deque, person);
            break;
        }case LIST:{
            deque = push_back_list(deque, person);
            break;
        }
    }return deque;
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
