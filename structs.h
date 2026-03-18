#ifndef STRUCTS
#define STRUCTS

#include <stdio.h>

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

typedef struct ListPerson{
    Person* self;
    struct ListPerson* next;
}ListPerson;

// just a vector of Person(people)
typedef struct VectorPerson{
    Person* people; // :sob:
    long size;
    long count;
}VectorPerson;

#endif