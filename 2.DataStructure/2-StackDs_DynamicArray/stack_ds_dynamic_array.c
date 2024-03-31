#include "stack_ds_dynamic_array.h"

#define INT "%i"

/*
 * @brief  : Hellper function to return boolean full or not
 * @param  : StackObj  Pointer to the stack
 * @retval : Return status of the stack
 */
static uint8_t Stack_IsFull(StackDynamic_t *StackObj)
{
    return (StackObj->Stack_MaxSize == StackObj->Stack_Count);
}
/*
 * @brief  : Hellper function to return boolean empty or not
 * @param  : StackObj  Pointer to the stack
 * @retval : Return status of the stack
 */
static uint8_t Stack_IsEmpty(StackDynamic_t *StackObj)
{
    return (StackObj->Stack_Count == ZERO);
}
StackDynamic_t *Stack_Creat(uint32_t StackMaxSize, StackStatus_t *RetStatus)
{
    StackDynamic_t *RetStackPtr = NULL;
    if (NULL == RetStatus)
    {
        *RetStatus = STACK_NULL_POINTER;
        RetStackPtr = NULL;
    }
    else
    {

        RetStackPtr = (StackDynamic_t *)malloc(sizeof(StackDynamic_t)); /*Creat object from the stack*/
        if (!RetStackPtr)
        {
            *RetStatus = STACK_NOK; /*Validate stack object creation*/
            RetStackPtr = NULL;
        }
        else
        {
            /*Initialize The Stack Object*/
            RetStackPtr->Stack_Count = ZERO;
            RetStackPtr->Stack_MaxSize = StackMaxSize;
            RetStackPtr->Stack_Top = EMPTY_VAL;
            RetStackPtr->Stack_Array = (void **)calloc(StackMaxSize, sizeof(void *)); /*Creat array of void pinters to store any data type */
            if (!(RetStackPtr->Stack_Array))
            {
                free(RetStackPtr);
                RetStackPtr = NULL;
                *RetStatus = STACK_NOK; /*Validate array of the stack object creation*/
            }
            else
            {
                *RetStatus = STACK_IS_CREATED;
            }
        }
    }
    return RetStackPtr;
}

StackDynamic_t *Stack_Destroy(StackDynamic_t *StackObj, StackStatus_t *RetStatus)
{
    StackDynamic_t *RetStackPtr = NULL;
    if ((NULL == RetStatus) || (NULL == StackObj))
    {
        *RetStatus = STACK_NULL_POINTER;
    }
    else
    {
        free(StackObj->Stack_Array);
        free(StackObj);
        *RetStatus = STACK_IS_DESTROIED;
    }
    return RetStackPtr;
}

StackStatus_t Stack_Push(StackDynamic_t *StackObj, void *PushValue)
{
    StackStatus_t RetStatus = STACK_EMPTY;
    if ((NULL == PushValue) || (NULL == StackObj))
    {
        RetStatus = STACK_NULL_POINTER;
    }
    else
    {
        if (Stack_IsFull(StackObj))
        {
            RetStatus = STACK_FULL;
        }
        else
        {
            (StackObj->Stack_Top)++;
            StackObj->Stack_Array[StackObj->Stack_Top] = PushValue;
            (StackObj->Stack_Count)++;
            RetStatus = STACK_VAL_IS_PUSHED;
        }
    }
    return (RetStatus);
}

void *Stack_pop(StackDynamic_t *StackObj, StackStatus_t *RetStatus)
{
    void *RetPoppedValue = NULL;
    if ((NULL == RetStatus) || (NULL == StackObj))
    {
        *RetStatus = STACK_NULL_POINTER;
        RetPoppedValue = NULL;
    }
    else
    {
        if (Stack_IsEmpty(StackObj))
        {
            *RetStatus = STACK_EMPTY;
            RetPoppedValue = NULL;
        }
        else
        {
            RetPoppedValue = StackObj->Stack_Array[StackObj->Stack_Top];
            (StackObj->Stack_Top)--;
            (StackObj->Stack_Count)--;
            *RetStatus = STACK_VAL_IS_POPPED;
        }
    }
    return (RetPoppedValue);
}

void *Stack_Top(StackDynamic_t *StackObj, StackStatus_t *RetStatus)
{
    void *RetTopValue = NULL;
    if ((NULL == RetStatus) || (NULL == StackObj))
    {
        *RetStatus = STACK_NULL_POINTER;
        RetTopValue = NULL;
    }
    else
    {
        if (Stack_IsEmpty(StackObj))
        {
            *RetStatus = STACK_EMPTY;
            RetTopValue = NULL;
        }
        else
        {
            RetTopValue = StackObj->Stack_Array[StackObj->Stack_Top];
            *RetStatus = STACK_TOP_IS_VALID;
        }
    }
    return (RetTopValue);
}

StackStatus_t Stack_Count(StackDynamic_t *StackObj, uint32_t *RetStackCount)
{
    StackStatus_t RetStatus = STACK_EMPTY;
    if ((NULL == RetStackCount) || (NULL == StackObj))
    {
        RetStatus = STACK_NULL_POINTER;
    }
    else
    {
        *RetStackCount = StackObj->Stack_Count;
        RetStatus = STACK_IS_Counted;
    }
    return (RetStatus);
}
StackStatus_t Stack_Display(StackDynamic_t *StackObj)
{
    StackStatus_t RetStatus = STACK_EMPTY;
    uint32_t Counter = 0;
    if (NULL == StackObj)
    {
        RetStatus = STACK_NULL_POINTER;
    }
    else if (Stack_IsEmpty(StackObj))
    {
        RetStatus = STACK_EMPTY;
    }
    else
    {
        printf("Stack Data: \n");
        printf("(Stack_Count)= %i\n", (StackObj->Stack_Count) - 1);
        // for (Counter = 3; Counter >= 0; Counter--)
        // {
        // printf("%i\t", *(uint32_t *)StackObj->Stack_Array[Counter]);
        // printf("Counter= %i\n", Counter);
        // }
        RetStatus = STACK_IS_DESPLAIED;
    }
    return (RetStatus);
}

void Stack_PrintStatus(StackStatus_t Status)
{
    switch (Status)
    {
    case STACK_EMPTY:
        printf("Stack is EMPTY !! \n");
        break;
    case STACK_FULL:
        printf("Stack is FULL !! \n");
        break;
    case STACK_NOK:
        printf("Stack is NOT OK !! \n");
        break;
    case STACK_NULL_POINTER:
        printf("Stack is NULL POINTER !! \n");
        break;
    case STACK_OK:
        printf("Stack is OK :) \n");
        break;
    case STACK_IS_CREATED:
        printf("############################################# \n");
        printf(" Stack is Created :) \n");
        printf("############################################# \n");
        break;
    case STACK_IS_DESTROIED:
        printf("############################################# \n");
        printf(" Stack is Destroied :) \n");
        printf("############################################# \n");
        break;
    case STACK_VAL_IS_PUSHED:
        printf(" This value is pushed to the stack  :) \n");
        break;
    case STACK_VAL_IS_POPPED:
        printf(" This value is popped from the stack  :) \n");
        break;
    case STACK_TOP_IS_VALID:
        printf(" This value is Top of the stack  :) \n");
        break;
    case STACK_IS_Counted:
        printf(" Number of counts of the stack  :) \n");
        break;
    case STACK_IS_DESPLAIED:
        printf(" Stack is displayed sucessfully  :) \n");
        break;
    default:
        printf("Error Status !! \n");
        break;
    }
}
