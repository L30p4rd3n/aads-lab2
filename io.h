#ifndef INPUT
#define INPUT
#include <stdio.h>
#include "structs.h"

typedef enum inTypes {
    INT,
    FLOAT,
    LONG,
    DOUBLE,
    CHAR,
    STRING,
    SIZE_T
}inTypes;
int input(void* ptr, inTypes types);

#endif