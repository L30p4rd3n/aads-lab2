#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "deque.h"
#include "ioworks.h"

#define DELT " \t"

int peopleComparator(Person* person_1, Person* person_2){
    return person_1 -> ta - person_2 -> ta;
}

VectorPerson* sort_people(VectorPerson* people){
    qsort(people -> people, people -> count, sizeof(Person), peopleComparator);
    return people;
}

Deque* get_deque(Deque* deque){

    VectorPerson* people = parse_line(DELT);
    if(people == NULL){
        return NULL;
    }
    people = sort_people(people);
    deque -> size = people -> size;
    if(deque -> type == VECTOR){
        deque -> data = realloc(deque -> data, deque -> size * sizeof(Person));
        deque -> head = deque -> data;
        deque -> tail = deque -> data;
    }
    for(size_t i = 0; i < people -> count; i++){
        if(people -> people[i].priority){
            push_front(deque, &(people -> people[i]));
        }else{
            push_back(deque, &(people -> people[i]));
        }
    }
    return deque;
}