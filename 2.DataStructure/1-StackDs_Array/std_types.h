#ifndef _STD_TYPES_H
#define _STD_TYPES_H

#include <stdio.h>

typedef enum ReturnStatus
{
    R_NOK,
    R_OK
} ReturnStatus_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;

#endif //_STD_TYPES_H