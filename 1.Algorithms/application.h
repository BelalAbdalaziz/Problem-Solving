#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "algorithms.h"

#define PRINT_POSITION(Position, Value)                 \
    if (Position == NOT_EXIST)                          \
        printf("Value <%i> is NOT EXIST !! \n", Value); \
    else                                                \
        printf("Value <%i> is Existed at pos <%i>  :) \n", Value, (Position + 1));

#endif