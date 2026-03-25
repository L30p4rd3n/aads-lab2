#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "deque.h"

int capacitycheck(Deque* deque);
Deque* push_front_vector(Deque* deque, Person* new);
Deque* push_front_list(Deque* deque, Person* new);
Deque* push_back_vector(Deque* deque, Person* new);
Deque* push_back_list(Deque* deque, Person* new);
Person* pop_front_vector(Deque* deque);
Person* pop_back_vector(Deque* deque);
Person* pop_front_list(Deque* deque);

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
            //
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
            //
            break;
        }
    }return NULL; 
}


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
            break;
        }
    }return deque;
}

Deque* push_back_vector(Deque* deque, Person* new){
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
            break;
        }
    }return deque;
}
Deque* push_front_list(Deque* deque, Person* new){
    ListPerson* newNode = malloc(sizeof(ListPerson));
    newNode -> self = new;

    if(deque -> count == 0){
        (deque -> tail) = newNode;
        (deque -> data) = newNode;
        (deque -> head) = newNode;
    }else{
        newNode -> next = ((ListPerson*)deque -> data) -> next;
        deque -> data = newNode;
        deque -> head = newNode;
    }deque -> count++;
    return deque;
}
Deque* push_back_list(Deque* deque, Person* new){
    ListPerson* newNode = malloc(sizeof(ListPerson));
    newNode -> self = new;
    newNode -> next = NULL;

    if(deque -> count == 0){
        (deque -> tail) = newNode;
        (deque -> data) = newNode;
        (deque -> head) = newNode;
    }else{
        ((ListPerson*)deque -> tail) -> next = newNode;
        deque -> tail = newNode;
    }deque -> count++;
    return deque;
}

Person* pop_front_vector(Deque* deque){
    if(capacitycheck(deque) != 0){
        Person* result = (Person*) deque -> head;
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
        return (Person*) deque -> tail;
    }return NULL;
}
Person* pop_front_list(Deque* deque){
    ListPerson* res = ((ListPerson*)deque -> head);
    deque -> head = ((ListPerson*)deque -> head) -> next; 
    res -> next = NULL;
    ((ListPerson*)deque -> data) -> next = deque -> head;
    deque -> count--;
    if(deque -> count == 0){
        ((ListPerson*)deque -> tail) -> next = NULL;
    }return res -> self;
}
/*  fix later - O(N)
Person* pop_back_list(Deque* deque){
    ListPerson* res = ((ListPerson*)deque -> tail);
    deque -> tail = ((ListPerson*)deque -> tail) -> next; 
    res -> next = NULL;
    ((ListPerson*)deque -> data) -> next = deque -> tail;
    deque -> count--;
    if(deque -> count == 0){
        ((ListPerson*)deque -> tail) -> next = NULL;
    }return res;
}*/
