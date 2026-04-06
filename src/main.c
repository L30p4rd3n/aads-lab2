#include <stdio.h>
#include <stdlib.h>
#include "../include/structs.h"
#include "../include/deque.h"
#include "../include/prepare_deque.h"
#include "../include/ioworks.h"
#include "../include/io.h"
#include "../include/task.h"
#include "../include/interface.h"

#define DEQUE_SIZE (long)3
#define DELT " \t"

int main(){
    
    Types type = VECTOR; // TODO - move to argparse
    Deque* deque = new_deque(type, DEQUE_SIZE);

    while(1){
        VectorPerson* temp = get_deque(deque);
        if(deque -> count != 0){
            simulate_clinic(deque, temp);
            if(temp != NULL){
                free(temp -> people);
                free(temp);
            }
        }else{
            if(temp != NULL){
                free(temp -> people);
                free(temp);
            }
            break;
        }
    }
    free(deque -> data);
    free(deque);
    
    return 0;
}