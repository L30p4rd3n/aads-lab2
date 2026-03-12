#ifndef INPUT
#define INPUT
#include <stdio.h>
#include "structs.h"

typedef enum Types {
    INT,
    FLOAT,
    LONG,
    DOUBLE,
    CHAR,
    STRING,
    SIZE_T
}Types;
int input(void* ptr, Types types);

#endif