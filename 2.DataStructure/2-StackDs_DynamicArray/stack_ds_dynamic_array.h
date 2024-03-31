#ifndef _STACK_DS_H
#define _STACK_DS_H

#include "std_types.h"

#define ZERO_INIT 0
#define ZERO 0
#define EMPTY_VAL -1
#define DESTROIED NULL
#define DEBUG_MODE

typedef struct stack_Ds
{
    void **Stack_Array;
    sint32_t Stack_Top;
    uint32_t Stack_Count;
    uint32_t Stack_MaxSize;

} StackDynamic_t;

typedef enum StackStatus
{
    STACK_EMPTY,
    STACK_FULL,
    STACK_NULL_POINTER,
    STACK_NOK,
    STACK_OK,
    STACK_IS_CREATED,
    STACK_IS_DESTROIED,
    STACK_VAL_IS_PUSHED,
    STACK_VAL_IS_POPPED,
    STACK_TOP_IS_VALID,
    STACK_IS_Counted,
    STACK_IS_DESPLAIED,

} StackStatus_t;

/*
 * @brief  : Creat the stack Array
 * @param  : StackSize  Wanted Size of the stack
 * @param  : RetStatus  Pointer to return status of the stack by ref
 * @retval : Return Address of the new stack is created
 */
StackDynamic_t *Stack_Creat(uint32_t StackMaxSize, StackStatus_t *RetStatus);

/*
 * @brief  : Destroy the stack Array
 * @param  : StackObj  Pointer to the stack want to destroy it
 * @param  : RetStatus  Pointer to return status of the stack by ref
 * @retval : Return DESTROIED of the stack
 */
StackDynamic_t *Stack_Destroy(StackDynamic_t *StackObj, StackStatus_t *RetStatus);

/*
 * @brief  : Push value to the stack Array
 * @param  : StackObj  Pointer to the stack
 * @param  : PushValue  Void pointer to push any type of values to the stack
 * @retval : Return status of the stack
 */
StackStatus_t Stack_Push(StackDynamic_t *StackObj, void *PushValue);

/*
 * @brief  : Pop value from the stack
 * @param  : StackObj  Pointer to the stack
 * @param  : RetStatus  Return status of the stack
 * @retval : Void pointer to popped any type of values from the stack
 */
void *Stack_pop(StackDynamic_t *StackObj, StackStatus_t *RetStatus);

/*
 * @brief  : Top value of the stack
 * @param  : StackObj  Pointer to the stack
 * @param  : RetTopValue  Void pointer to return any type of top values from the stack
 * @retval : Return status of the stack
 */
void *Stack_Top(StackDynamic_t *StackObj, StackStatus_t *RetStatus);

/*
 * @brief  : Determine stack Size
 * @param  : StackObj  Pointer to the stack
 * @param  : RetStackSize  pointer to return stack size by ref
 * @retval : Return status of the stack
 */
StackStatus_t Stack_Count(StackDynamic_t *StackObj, uint32_t *RetStackCount);
/*
 * @brief  : Display the stack Array
 * @param  : StackObj  Pointer to the stack
 * @retval : Return status of the stack
 */
StackStatus_t Stack_Display(StackDynamic_t *StackObj);

void Stack_PrintStatus(StackStatus_t Status);

#endif //_STACK_DS_H