#include "../include/deque.h"

void all_data(Deque* deque){
    if(deque -> count > 0){
        if(deque -> type == VECTOR){
            for(size_t i = 0; i < deque -> count; i++){
                Person* curr_item = &((Person*)deque -> data)[((Person*)deque -> head -
                    (Person*)deque -> data + i + deque -> size) % deque -> size];
                printf(" %s ", curr_item -> id);
            }
        }else{
            ListPerson* curr = ((ListPerson*)deque -> data);
            while(curr != NULL){
                if(curr -> self != NULL){
                    printf(" %s ", curr -> self -> id);
                }curr = curr -> next;
            }
        }
    }printf("\n");
}

void greet(){
    printf("Please enter the entries.\nEntries format: a/1/20 b/1/15 c/2/10 *d/5/8 *e/6/5 f/6/9\n");
}