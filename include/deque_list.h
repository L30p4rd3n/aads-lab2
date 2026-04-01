#ifndef DLIST
#define DLIST
#include "structs.h"
#include "deque.h"


Err push_front_list(Deque* deque, Person* new);
Err push_back_list(Deque* deque, Person* new);
Person* pop_front_list(Deque* deque);
Person* pop_back_list(Deque* deque);
#endif