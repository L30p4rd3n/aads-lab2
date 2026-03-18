#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "deque.h"

int main(){
    DequeList* deque = malloc(sizeof(DequeList));
    deque -> count = 0;
    deque -> size = 15;
    //Person* data = malloc(deque-> size * sizeof(Person));
    deque -> data = malloc(sizeof(ListPerson));
    
    deque -> data -> next = NULL;
    deque -> data -> self = NULL;

    deque -> head = NULL;
    deque -> tail = NULL;
    Person* test = malloc(sizeof(Person));
    test -> id = "asd";
    
    push_front_list(deque, test);
    push_front_list(deque, test);
    printf("%d\n", deque -> count);
    return 0;
}