#include "../include/structs.h"
#include "../include/deque.h"
#include <stdlib.h>

int capacitycheck(Deque* deque){
    if(deque -> head == deque -> tail){
        if(deque -> count == deque -> size){
            return 2;
        }return 0;
    }return 1;
}


Err push_front_vector(Deque* deque, Person* new){ // data is VectorPerson*
    switch(capacitycheck(deque)){
        case 0:{
            deque -> head = &((Person*)deque -> data)[((Person*)deque -> head - 
                (Person*)deque -> data - 1) % deque -> size];
            *(Person*)deque -> head = *new;
            deque -> tail = deque -> data;
            deque -> count++;
            break;
        }case 1:{
            deque -> head = &((Person*)deque -> data)[((Person*)deque -> head - 
                (Person*)deque -> data - 1 + deque -> size) % deque -> size];
            *(Person*)deque -> head = *new;
            deque -> count++; 
            break;    
        }case 2:{
            return ERR;
        }
    }return SUCCESS;
}

Err push_back_vector(Deque* deque, Person* new){
    switch(capacitycheck(deque)){
        case 0:{
            *(Person*)deque -> tail = *new;

            deque -> tail = &((Person*)deque -> data)[((Person*)deque -> tail -
                 (Person*)deque -> data + 1) % deque -> size];
            deque -> head = deque -> data;
            deque -> count++;
            break;
        }case 1:{
            *(Person*)deque -> tail = *new;
            deque -> tail = &((Person*)deque -> data)[((Person*)deque -> tail - 
                (Person*)deque -> data + 1) % deque -> size];

            deque -> count++; 
            break;    
        }case 2:{
            return ERR;
        }
    }return SUCCESS;
}

Person* pop_front_vector(Deque* deque){
    if(capacitycheck(deque) != 0){
        Person* result = malloc(sizeof(Person));
        *result = *(Person*) deque -> head;
        deque -> head = &((Person*)deque -> data)[((Person*)deque -> head - 
                (Person*)deque -> data + 1) % deque -> size];
        deque -> count--;
        return result;
    }return NULL;
}
Person* pop_back_vector(Deque* deque){
    if(capacitycheck(deque) != 0){
        deque -> tail = &((Person*)deque -> data)[((Person*)deque -> tail - 
                (Person*)deque -> data - 1 + deque -> size) % deque -> size];
        deque -> count--;
        Person* result = malloc(sizeof(Person));
        *result = *(Person*) deque -> tail;
        return result;
    }return NULL;
}