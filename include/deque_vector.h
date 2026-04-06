#ifndef DVEC
#define DVEC
#include "structs.h"
#include "deque.h"


Err push_front_vector(Deque* deque, Person* new);
Err push_back_vector(Deque* deque, Person* new);
Person* pop_front_vector(Deque* deque);
Person* pop_back_vector(Deque* deque);
#endif