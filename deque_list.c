#include "structs.h"
#include "deque.h"

int capacitycheck(Deque* deque){
    if(deque -> head == deque -> tail){
        if(deque -> count == deque -> size){
            return 2;
        }return 0;
    }return 1;
}


Deque* push_front_list(Deque* deque, Person* new){
    ListPerson* newNode = malloc(sizeof(ListPerson));
    newNode -> self = new;

    if(deque -> count == 0){
        newNode -> next = NULL;
        (deque -> tail) = newNode;
        (deque -> data) = newNode;
        (deque -> head) = newNode;
    }else{
        newNode -> next = ((ListPerson*)deque -> head);
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


Person* pop_front_list(Deque* deque){
    if(deque -> count > 0){
        ListPerson* res = ((ListPerson*)deque -> head);
        if(deque -> count == 1){
            deque -> head = NULL;
            deque -> tail = NULL;
            deque -> data = NULL;
        }else{
            deque -> head = ((ListPerson*)deque -> head) -> next; 
            deque -> data = deque -> head;
            res -> next = NULL;
        }deque -> count--;
        
        return res -> self;
    }return NULL;
}
Person* pop_back_list(Deque* deque){
    if(deque -> count > 0){
        ListPerson* res = ((ListPerson*)deque -> tail);
    if(deque -> count == 1){
            deque -> head = NULL;
            deque -> tail = NULL;
            deque -> data = NULL;
        }else{
            ListPerson* prev = ((ListPerson*)deque -> head);
            while(prev -> next -> next != NULL){
                prev = prev -> next;
            }free(prev -> next);
        }deque -> count--;
        
        return res -> self;    
    }return NULL;
}