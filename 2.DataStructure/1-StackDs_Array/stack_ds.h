#ifndef _STACK_DS_H
#define _STACK_DS_H

#include "std_types.h"

#define STACK_MAX_SIZE 5
#define ZERO_INIT 0
#define ZERO 0
#define EMPTY_VAL -1
#define DEBUG_MODE

typedef struct stack_Ds
{
    sint32_t Top;
    uint32_t Data[STACK_MAX_SIZE];
} Stack_Ds_t;

typedef enum StackStatus
{
    STACK_EMPTY,
    STACK_FULL,
    STACK_NOTFULL
} StackStatus_t;

/*
 * @brief  : Initialize the stack top
 * @param  : My_Stack  Pointer to the stack
 * @retval : Return status of the stack
 */
ReturnStatus_t Stack_Init(Stack_Ds_t *My_Stack);
/*
 * @brief  : Push value to the stack
 * @param  : My_Stack  Pointer to the stack
 * @param  : Value  push this value to the stack
 * @retval : Return status of the stack
 */
ReturnStatus_t Stack_Push(Stack_Ds_t *My_Stack, uint32_t Value);

/*
 * @brief  : Pop value to the stack
 * @param  : My_Stack  Pointer to the stack
 * @param  : Value  pop this value from the stack
 * @retval : Return status of the stack
 */
ReturnStatus_t Stack_Pop(Stack_Ds_t *My_Stack, uint32_t *Ret_Value);

/*
 * @brief  : Top value of the stack
 * @param  : My_Stack  Pointer to the stack
 * @param  : Ret_Top  top value of the stack
 * @retval : Return status of the stack
 */
ReturnStatus_t Stack_Top(Stack_Ds_t *My_Stack, uint32_t *Ret_Top);
/*
 * @brief  : Size of the stack
 * @param  : My_Stack  Pointer to the stack
 * @param  : Ret_Size  Size value of the stack
 * @retval : Return status of the stack
 */
ReturnStatus_t Stack_Size(Stack_Ds_t *My_Stack, uint32_t *Ret_Size);
/*
 * @brief  : Display elements of the stack
 * @param  : My_Stack  Pointer to the stack
 * @retval : Return status of the stack
 */
ReturnStatus_t Stack_Display(Stack_Ds_t *My_Stack);

#endif //_STACK_DS_H