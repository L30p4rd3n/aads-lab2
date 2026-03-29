#ifndef DVEC
#define DVEC
#include "structs.h"
#include "deque.h"


Deque* push_front_vector(Deque* deque, Person* new);
Deque* push_back_vector(Deque* deque, Person* new);
Person* pop_front_vector(Deque* deque);
Person* pop_back_vector(Deque* deque);
#endif