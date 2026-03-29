#include <stdio.h>
#include <stdlib.h>
#include "../include/structs.h"
#include "../include/deque.h"
#include "../include/prepare_deque.h"
#include "../include/ioworks.h"
#include "../include/io.h"
#include "../include/task.h"

#define DELT " \t"

int main(){
    
    Types type = VECTOR; // TODO - move to argparse

    Deque* deque = new_deque(type);
    while(1){
        Deque* temp = get_deque(deque);
        if(temp != NULL){
            deque = temp;
            simulate_clinic(deque);
        }else{
            break;
        }
    }
    free(deque -> data);
    free(deque);
    
    return 0;
}