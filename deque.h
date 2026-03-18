#ifndef DEUQE
#define DEQUE
#include "structs.h"

typedef struct Deque{
    void* head; // point to start of list or vector
    void* tail; // point to end of list or first unused adress in vector
    void* data;

    long size; // size of list or vectorqet
    long count; // size of list or size of used data(in vector); <= size
}Deque;


Deque* push_front_vector(Deque* deque, Person* new);
Deque* push_front_list(Deque* deque, Person* new);
Deque* push_front(Deque* deque, Types dequetype, Person* person); // just return the copy
Deque* push_back(Deque* deque, Types dequetype, Person* person); // just return the copy
Person* pop_front(Deque** deque, Types dequetype); // modify the structure
Person* pop_back(Deque** deque, Types dequetype); // modify the structure

#endif