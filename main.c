#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "deque.h"
#include "prepare_deque.h"
#include "ioworks.h"
#include "io.h"
#include "task.h"

#define DELT " \t"

int main(){
    
    Types type = VECTOR; // TODO - move to argparse

    Deque* deque = new_deque(type);
    while(1){
        deque = get_deque(deque);
        simulate_clinic(deque);
        //probably free some leftovers
    }
    free(deque -> data);
    free(deque);
    
    return 0;
}