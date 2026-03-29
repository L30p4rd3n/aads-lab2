#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/structs.h"
#include "../include/io.h"
#include "../include/interface.h"

#define nil NULL

char* mestrdup(char* str){ // free later
    char* ans = malloc(strlen(str) + 1);
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

    int datafield = 0;
    long* idx = malloc(3 * sizeof(long));
    for(long i = 0; i < strlen(working_str_set1); i++){
        if(working_str_set1[i] == '/'){
            idx[datafield] = i;
            datafield++;
            if(datafield >= 3){
                break;
            }
        }
    }

    char* id = malloc(idx[0] + 1);
    strncpy(id, working_str_set1, idx[0]);
    id[idx[0]] = '\0';
    person -> id = id;

    char* endptr;
    person -> ta = strtol(working_str_set1 + idx[0] + 1, &endptr, 10);
    if(*endptr != '/') {
        free(id);
        free(working_str_set1);
        free(person);
        free(idx);
        return NULL;
    }
    
    person -> ts = strtol(endptr + 1, &endptr, 10);
    if(*endptr != '\0') {
        free(id);
        free(working_str_set1);
        free(person);
        free(idx);
        return NULL;
    }
    free(idx);
    free(working_str_set1);
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
    greet();
    VectorPerson* people = malloc(sizeof(VectorPerson));
    people -> count = 0;
    people -> size = 0;
    people -> people = malloc(people -> size * sizeof(Person));

    char* line = NULL;
    int err = input(&line, STRING);
    if(err == -1){
        free(people -> people);
        free(people);
        return NULL;
    }

    char* working_str_set = mestrdup(line);
    char* word = mestrtok(working_str_set, delt);
    while(word != nil){
        Person* person = parse_input(word, "/"); // add __compar_fn_t for qsort
        if(people -> count + 1 > people -> size){
            people->people = realloc(people->people, (people -> size + 1) * sizeof(Person));
            people -> size++;
        }people -> people[people -> count] = *person;
        free(person);
        people -> count++;
        word = mestrtok(nil, delt);
    }
    free(working_str_set);
    free(line);
    return people;
}
