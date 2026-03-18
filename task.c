#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
#include "structs.h"

void simulate_clinic(Deque* deque){
    Person* in_use = pop_front(deque);
    int is_using = 0;
    size_t time = 1, tt = 1; // time when a guy was actually taken
    while(deque -> count > 0){
        if(is_using && time < in_use -> ts + tt){ // someone inside
            time++;
        }else if(is_using && time == in_use -> ts + tt){ // just freed
            //invoke()
            is_using = 0;
            in_use = pop_front(deque);
        }else if(!is_using && time >= in_use -> ta){ // new fella got taken
            is_using = 1;
            tt = time;
        }else if(!is_using && time < in_use -> ta){ // no one is there
            time++;
        }
    }
}