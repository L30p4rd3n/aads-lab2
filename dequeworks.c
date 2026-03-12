#include <stdio.h>
#include <stdlib.h>
#include "ioworks.h"
#include "structs.h"

int peopleComparator(Person* person_1, Person* person_2){
    return person_1 -> ta - person_2 -> ta;
}

VectorPerson* sort_people(VectorPerson* people){
    qsort(people -> people, people -> count, sizeof(Person), peopleComparator);
    return people;
}

Deque* sorted_to_deque(Deque* deque, VectorPerson* people, Types type){
    for(size_t i = 0; i < people -> count; i++){
        if(people -> people[i].priority){
            push_front(deque, type, &(people -> people[i]));
        }else{
            push_back(deque, type, &(people -> people[i]));
        }
    }return deque;
}