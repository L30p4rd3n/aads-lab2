#ifndef DEQUE
#define DEQUE
#include "structs.h"

typedef struct Deque{
    void* head; // point to start of list or vector
    void* tail; // point to end of list or first unused adress in vector
    void* data;

    long size; // size of list or vectorqet
    long count; // size of list or size of used data(in vector); <= size
    Types type;
}Deque;

//deque creation
Deque* new_deque(Types type, long size);

//deque I/O
Err push_front(Deque* deque, Person* person); // just return the copy
Err push_back(Deque* deque, Person* person); // just return the copy
Person* pop_front(Deque* deque); // modify the structure
Person* pop_back(Deque* deque); // modify the structure

#endif