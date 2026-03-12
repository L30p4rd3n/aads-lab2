#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "ioworks.h"

int capacitycheck(Deque* deque){
    return(deque -> head == deque -> tail) + (deque -> count == deque -> size); // dolbanet? ne doljno
}

// дек - надстройка над void* people - вектором или списком
Deque* push_front(Deque* deque, Types dequetype, Person* new, void* people){ 
    switch(dequetype){
        case VECTOR:{ // so void* is VectorPeople*[0]
            switch(capacitycheck(deque)){
                case 0:{
                    *(deque -> head) = *new;
                    deque -> head = &people[(deque -> head - (VectorPerson*)people - 1) % deque -> size];
                    deque -> count++;
                    break;
                }
                case 1:{
                    *(deque -> head) = *new;
                    deque -> head = &people[(deque -> head - (VectorPerson*)people - 1) % deque -> size];
                    deque -> tail = &people[(deque -> tail - (VectorPerson*)people + 1) % deque -> size];
                    deque -> count++;
                    break;
                }case 2:{
                    // invoke some sort of message (deque is full)
                    break;
                }
            }
            break;
        }
        case LIST: { // so void* is ListPeople*, start* of it
            break; // pass for now
        }

    }
    return deque;
}
Deque* push_back(Deque* deque, Types dequetype, Person* person){

}
