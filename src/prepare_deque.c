#include <stdio.h>
#include <stdlib.h>
#include "../include/structs.h"
#include "../include/deque.h"
#include "../include/ioworks.h"
#include "../include/interface.h"

#define DELT " \t"

int peopleComparator(Person* person_1, Person* person_2){
    return person_1 -> ta - person_2 -> ta;
}

VectorPerson* sort_people(VectorPerson* people){
    qsort(people -> people, people -> count, sizeof(Person), (__compar_fn_t)peopleComparator);
    return people;
}

VectorPerson* get_deque(Deque* deque){
    VectorPerson* people = parse_line(DELT);
    VectorPerson* unused = malloc(sizeof(VectorPerson));
    unused -> count = 0;
    unused -> size = 0;
    unused -> people = malloc(0);
    if(people == NULL){
        free(unused -> people);
        free(unused);
        return NULL;
    }
    people = sort_people(people);
    if(deque -> type == VECTOR){
        deque -> head = deque -> data;
        deque -> tail = deque -> data;
    }
    for(size_t i = 0; i < people -> count; i++){
        Err err = 0;

        Person* to_add = malloc(sizeof(Person));
        to_add -> priority = people->people[i].priority;
        to_add -> id = mestrdup(people -> people[i].id);
        to_add -> ta = people -> people[i].ta;
        to_add -> ts = people -> people[i].ts;

        if(people->people[i].priority){
            err = push_front(deque, to_add);
        }else{
            err = push_back(deque, to_add);
        }
        if(err){
            unused -> size++;
            unused -> count++;
            unused -> people = realloc(unused -> people, unused -> count * sizeof(Person));
            unused -> people[unused -> count - 1] = *to_add;
        }
        if(deque -> type == VECTOR){
            free(to_add);
        }
        error_check(err);
    }
    for(long i = 0; i < people -> count; i++){
        free((void*)people -> people[i].id);
    }free(people -> people);
    free(people);
    
    return unused;
}