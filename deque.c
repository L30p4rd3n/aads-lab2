#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
//#include "ioworks.h"
#include "deque.h"

int capacitycheck(Deque* deque){
    if(deque -> head == deque -> tail){
        if(deque -> count == deque -> size){
            return 2;
        }return 0;
    }return 1;
}

Deque* push_front_vector(Deque* deque, Person* new){ // data is VectorPerson*
    switch(capacitycheck(deque)){
        case 0:{
            *(Person*)deque -> head = *new;

            deque -> head = &((Person*)deque -> data)[((Person*)deque -> head - 
                (Person*)deque -> data - 1) % deque -> size];

            deque -> tail = &((Person*)deque -> data)[((Person*)deque -> tail -
                 (Person*)deque -> data + 1) % deque -> size];

            deque -> count++;
            break;
        }case 1:{
            *(Person*)deque -> head = *new;
            deque -> head = &((Person*)deque -> data)[((Person*)deque -> head - 
                (Person*)deque -> data - 1) % deque -> size];

            deque -> count++; 
            break;    
        }case 2:{
            break;
        }
    }return deque;
}

Deque* push_front_list(Deque* deque, Person* new){
    
    ListPerson* newNode = malloc(sizeof(ListPerson));
    newNode -> self = new;
    newNode -> next = ((ListPerson*)deque -> data) -> next;

    ((ListPerson*)deque -> data) -> next = newNode;
    deque -> head = newNode;
    if(deque -> count == 0){
        ((ListPerson*)deque -> tail) -> next = newNode;
    }
    deque -> count++;

    return deque;
}

Deque* push_back_vector(Deque* deque, Person* new){
    switch(capacitycheck(deque)){
        case 0:{
            *(Person*)deque -> tail = *new;

            deque -> head = &((Person*)deque -> data)[((Person*)deque -> head - 
                (Person*)deque -> data - 1) % deque -> size];

            deque -> tail = &((Person*)deque -> data)[((Person*)deque -> tail -
                 (Person*)deque -> data + 1) % deque -> size];

            deque -> count++;
            break;
        }case 1:{
            *(Person*)deque -> tail = *new;
            deque -> tail = &((Person*)deque -> data)[((Person*)deque -> tail - 
                (Person*)deque -> data + 1) % deque -> size];

            deque -> count++; 
            break;    
        }case 2:{
            break;
        }
    }return deque;
}

Deque* push_back_list(Deque* deque, Person* new){
    
    ListPerson* newNode = malloc(sizeof(ListPerson));
    newNode -> self = new;
    newNode -> next = ((ListPerson*)deque -> data) -> next;

    ((ListPerson*)deque -> tail) -> next = newNode;
    deque -> tail = newNode;
    if(deque -> count == 0){
        ((ListPerson*)deque -> data) -> next = newNode;
        ((ListPerson*)deque -> head) -> next = newNode;
    }
    deque -> count++;

    return deque;
}

