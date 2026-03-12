#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "io.h"

#define nil NULL

// only parsing the current input(into a Person) piece
// then in another func, continiously call this + strtok(until it is NULL)
Person* parse_input(char* ctx, char* delt){
    //structure: ctx[0] is *? no => just parse from 0, otherwise parse from 1
    Person* person = malloc(sizeof(Person));
    char* working_str_set;
    if(ctx[0] == '*'){
        //priority
        person -> priority = 1;
        working_str_set = strdup(ctx+1);
    }else{
        person -> priority = 0;
        working_str_set = strdup(ctx);
    }

    char* piece = strtok(working_str_set, delt);
    int datafield = 0; // 0 str, 1-2 long

    while(piece != nil){
        long err = 0;
        char* end;
        if(datafield == 0){
            person -> id = strdup(piece);
        }else if(datafield == 1){
            person -> ta = strtol(piece, &end, 10);
            if(end == piece){
                person -> ta = -1; // МФЦ be like:
            }
        }else{
            person -> ts = strtol(piece, &end, 10);
            if(end == piece){
                person -> ts = 0; // пришел и был отправлен обратно...
            }
        }
        piece = strtok(NULL, delt);
    }

    free(working_str_set);
    //free(piece);
    return person;
}

VectorPerson* parse_line(VectorPerson* people, char* delt){ // [de]que pro
    char* line;
    int err = input(line, STRING);

    char* working_str_set = strdup(line);
    char* word = strtok(working_str_set, delt);
    while(word != nil){
        Person* person = parse_input(word, delt); // add __compar_fn_t for qsort
        if(people -> count + 1 > people -> size){
            people = realloc(people, (people -> size + 1) * sizeof(Person));
            people -> size++;
        }people -> people[people -> count] = *person;
        people -> count++;
    }
    return people;
}
