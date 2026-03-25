#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "io.h"

#define nil NULL

char* mestrdup(char* str){ // free later
    char* ans = calloc(strlen(str) + 1, 1);
    if(ans == NULL){
        return NULL;
    }
    size_t i = 0;
    for(; i < strlen(str); i++){
        ans[i] = str[i];
    }ans[i] = '\0';
    return ans;
}
// only parsing the current input(into a Person) piece
// then in another func, continiously call this + strtok(until it is NULL)
Person* parse_input(char* ctx, char* delt){
    //structure: ctx[0] is *? no => just parse from 0, otherwise parse from 1
    Person* person = malloc(sizeof(Person));
    char* working_str_set1;
    if(ctx[0] == '*'){
        //priority
        person -> priority = 1;
        working_str_set1 = mestrdup(ctx+1);
    }else{
        person -> priority = 0;
        working_str_set1 = mestrdup(ctx);
    }
    char* piece = strtok(working_str_set1, delt);
    int datafield = 0; // 0 str, 1-2 long

    while(piece != nil){
        long err = 0;
        char* end;
        if(datafield == 0){
            person -> id = mestrdup(piece);
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
        }datafield++;
        piece = strtok(NULL, delt);
    }

    free(working_str_set1);
    free(piece);
    return person;
}


char* mestrtok(char* str, const char* del){ // slams it till it gets to delim or \0 lmao
    static char* beg = NULL;
    char* start;
    if(str != NULL){
        beg = str;
    }
    if(beg == NULL || *beg == '\0'){
        return NULL;
    }
    
    int delt = 1;
    while(*beg != '\0'){
        delt = 0;
        for(int i = 0; i < strlen(del); i++){
            if(*beg == del[i]){
                delt = 1;
                break;
            }
        }if(!delt){
            break;
        }beg++;
    }
    if(*beg == '\0'){
        beg = NULL;
        return NULL;
    }start = beg;
    while(*beg != '\0'){
        for(int i = 0; i < strlen(del); i++){
            if(*beg == del[i]){
                delt = 1;
                break;
            }
        }if(delt){
            break;
        }beg++;
    }
    if(*beg != '\0'){
        *beg = '\0';
        beg++;
    }else beg = NULL;
    return start;
}


VectorPerson* parse_line(char* delt){ // [de]que pro
    VectorPerson* people = malloc(sizeof(VectorPerson));
    people -> count = 0;
    people -> size = 0;
    people -> people = malloc(people -> size * sizeof(Person));

    char* line = NULL;
    int err = input(&line, STRING);
    if(err == -1){
        free(people -> people);
        free(people);
        return 0;
    }

    char* working_str_set = mestrdup(line);
    char* word = mestrtok(working_str_set, delt);
    while(word != nil){
        Person* person = parse_input(word, "/"); // add __compar_fn_t for qsort
        if(people -> count + 1 > people -> size){
            people->people = realloc(people->people, (people -> size + 1) * sizeof(Person));
            people -> size++;
        }people -> people[people -> count] = *person;
        people -> count++;
        word = mestrtok(nil, delt);
    }
    free(working_str_set);
    return people;
}
