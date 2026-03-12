#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "io.h"

#define FIXSIZE 100

// readline taken without changes from c_lab4: @L30p4rd3n/c_lab4
// TODO - add enlarge() function to re-use in the mereadline
char* mereadline(const char* prompt){ 
    char* string = calloc(FIXSIZE, 1);
    char* temp_string = calloc(FIXSIZE, 1);
    if(string == NULL || temp_string == NULL){
        return NULL;
    }
    size_t size = FIXSIZE;
    unsigned long position = 0;
    printf("%s", prompt);
    int ws_flag = 0;
    int stder = 0;
    while((stder = scanf("%99[^\n]", temp_string)) == 1){ 
        for(unsigned long i = 0; i < mestrlen(temp_string); i++){
            if(temp_string[i] == ' '){
                if(!ws_flag && position > 0){
                    if(position + 1 >= size){
                        char* temp = realloc(string, size + FIXSIZE);
                        if(temp == NULL){
                            free(string);
                            free(temp_string);
                            return NULL;
                        }string = temp;
                        size += FIXSIZE;
                    }
                    string[position] = temp_string[i];
                    position++;
                    ws_flag = 1;
                }else continue;
            }else{
                if(position + 1 >= size){
                    char* temp = realloc(string, size + FIXSIZE);
                        if(temp == NULL){
                            free(string);
                            free(temp_string);
                            return NULL;
                        }string = temp;
                    size += FIXSIZE;
                }string[position] = temp_string[i];
                position++;
                ws_flag = 0;
            }
        }
        if (mestrlen(temp_string) < 99){
                break;
        }
    }

    if(stder == -1){
        free(string);
        free(temp_string);
        return NULL;
    }

    string[position] = '\0';
    scanf("%*c");
    free(temp_string);
    return string;
}

int input(void* to, Types type){
    int x = -2;
    char c;
    while(x != 0){
        switch(type){
            case INT:{ // cat but kinda sad
                int v = 0;
                x = scanf("%d%c", &v, &c);
                if(x == -1){
                    return -1;
                }else if(x == 2 && (c == 10 || c == 32)){
                    *(int*)to = v;
                    return 0;
                }break;
            }case FLOAT:{
                float v = 0;
                x = scanf("%f%c", &v, &c);
                if(x == -1){
                    return -1;
                }else if(x == 2 && (c == 10 || c == 32)){
                    *(float*)to = v;
                    return 0;
                }break;
            }case DOUBLE:{
                double v = 0;
                x = scanf("%lf%c", &v, &c);
                if(x == -1){
                    return -1;
                }else if(x == 2 && (c == 10 || c == 32)){
                    *(double*)to = v;
                    return 0;
                }break;
            }case LONG:{
                long v = 0;
                x = scanf("%ld%c", &v, &c);
                if(x == -1){
                    return -1;
                }else if(x == 2 && (c == 10 || c == 32)){
                    *(long*)to = v;
                    return 0;
                }break;
            }case SIZE_T:{
                size_t v = 0;
                x = scanf("%zu%c", &v, &c);
                if(x == -1){
                    return -1;
                }else if(x == 2 && (c == 10 || c == 32)){
                    *(size_t*)to = v;
                    return 0;
                }break;
            }case STRING:{
                char* input = mereadline("");
                if(input != NULL){
                    *(char*)to = input;
                    return 0;
                }return -1; // either a strung or EOF, no third
            }

            if(scanf("%c", &c) != -1){
                scanf("%*s");
                x = -2;
                printf("Wrong value entered, please, try again.\n");
            }else{
                return -1;
            }
        }

    }
}
