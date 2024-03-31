#include <stdio.h>
#include <stdlib.h>

#define BIT_MASK 0b00000111 /*Read 3 BIts*/
#define READ_BIT(VALUE, POS) ((VALUE >> POS) & BIT_MASK)

typedef signed int sint32_t;
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

