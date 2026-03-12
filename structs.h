#ifndef STRUCTS
#define STRUCTS

#include <stdio.h>
// нравится столько комментов?
// а меня вот на них щас пропирает прям :)

// DataStructure
typedef struct Person{
    int priority;
    const char* id;
    long ta;
    long ts;
}Person;

// Possible deque types
typedef enum Types{
    VECTOR,
    LIST
}Types;


// each node: ptr to self data, ptr to next
// using one-sided non-cyclic list(but cyclic is possible)
// GOD DO I LOVE CYCLIC LISTS 
typedef struct ListPerson{
    Person* self;
    Person* next;
}ListPerson;

// just a vector of Person(people)
typedef struct VectorPerson{
    Person* people; // :sob:
    long size;
    long count;
}VectorPerson;

typedef struct Deque{
    Person* head; // point to start of list or vector
    Person* tail; // point to end of list or first unused adress in vector
    long size; // size of list or vector
    long count; // size of list or size of used data(in vector); <= size
}Deque;

Deque* push_front(Deque* deque, Types dequetype, Person* person); // just return the copy
Deque* push_back(Deque* deque, Types dequetype, Person* person); // just return the copy
Person* pop_front(Deque** deque, Types dequetype); // modify the structure
Person* pop_back(Deque** deque, Types dequetype); // modify the structure

#endif