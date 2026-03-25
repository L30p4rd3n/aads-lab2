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
    
    Types type = LIST; // TODO - move to argparse

    Deque* deque = new_deque(type);
    while(1){
        Deque* temp = get_deque(deque);
        if(temp != NULL){
            deque = temp;
            simulate_clinic(deque);
        }else{
            break;
        }
        //probably free some leftovers
    }
    free(deque -> data);
    free(deque);
    
    return 0;
}