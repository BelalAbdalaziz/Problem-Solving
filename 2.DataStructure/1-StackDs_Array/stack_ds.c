#include "stack_ds.h"

/*
 * @brief  : Helper function to show is stack empty
 * @param  : My_Stack  Pointer to the stack
 * @retval : Return status of the stack
 */
static StackStatus_t Is_StackEmpty(Stack_Ds_t *My_Stack)
{
    StackStatus_t RetState = STACK_EMPTY;
    if ((NULL == My_Stack) || (EMPTY_VAL == My_Stack->Top))
    {
        RetState = STACK_EMPTY;
    }
    else
    {
        RetState = STACK_NOTFULL;
    }

    return RetState;
}
/*
 * @brief  : Helper function to show is stack Full
 * @param  : My_Stack  Pointer to the stack
 * @retval : Return status of the stack
 */
static StackStatus_t Is_StackFull(Stack_Ds_t *My_Stack)
{
    StackStatus_t RetState = STACK_EMPTY;
    if ((NULL == My_Stack) || (STACK_MAX_SIZE == My_Stack->Top))
    {
        RetState = STACK_FULL;
    }
    else
    {
        RetState = STACK_NOTFULL;
    }

    return RetState;
}
/*
 * @brief  : Initialize the stack top
 * @param  : My_Stack  Pointer to the stack
 * @retval : Return status of the stack
 */
ReturnStatus_t Stack_Init(Stack_Ds_t *My_Stack)
{
    ReturnStatus_t RetState = R_NOK;
    if (NULL == My_Stack)
    {
#ifdef DEBUG_MODE
        printf("Stack Top Initialization Faield !!\n");
#endif
        RetState = R_NOK;
    }
    else
    {
#ifdef DEBUG_MODE
        printf("Stack Top Initialization Sucsessed :) \n");
#endif
        My_Stack->Top = -1;
        RetState = R_OK;
    }

    return RetState;
}
/*
 * @brief  : Push value to the stack
 * @param  : My_Stack  Pointer to the stack
 * @param  : Value  push this value to the stack
 * @retval : Return status of the stack
 */
ReturnStatus_t Stack_Push(Stack_Ds_t *My_Stack, uint32_t Value)
{
    ReturnStatus_t RetState = R_NOK;
    if ((NULL == My_Stack) || (STACK_FULL == Is_StackFull(My_Stack)))
    {
        RetState = R_NOK;
#ifdef DEBUG_MODE
        printf("Stack Push (%i) Faield !!\n", Value);
#endif
    }
    else
    {
        My_Stack->Top++;
        My_Stack->Data[My_Stack->Top] = Value;

        RetState = R_OK;
#ifdef DEBUG_MODE
        printf("Stack Push (%i) Sucsessed :) \n", Value);
#endif
    }

    return RetState;
}

/*
 * @brief  : Pop value to the stack
 * @param  : My_Stack  Pointer to the stack
 * @param  : Value  pop this value from the stack
 * @retval : Return status of the stack
 */
ReturnStatus_t Stack_Pop(Stack_Ds_t *My_Stack, uint32_t *Ret_Value)
{
    ReturnStatus_t RetState = R_NOK;
    if ((NULL == My_Stack) || (NULL == Ret_Value) || (STACK_EMPTY == Is_StackEmpty(My_Stack)))
    {
        RetState = R_NOK;
#ifdef DEBUG_MODE
        printf("Stack Pop  Failed !!\n");
#endif
    }
    else
    {
        *Ret_Value = My_Stack->Data[My_Stack->Top];
        My_Stack->Top--;
        RetState = R_OK;
#ifdef DEBUG_MODE
        printf("Stack Pop (%i) Sucsessed :) \n", *Ret_Value);
#endif
    }
    return RetState;
}

/*
 * @brief  : Top value of the stack
 * @param  : My_Stack  Pointer to the stack
 * @param  : Ret_Top  top value of the stack
 * @retval : Return status of the stack
 */
ReturnStatus_t Stack_Top(Stack_Ds_t *My_Stack, uint32_t *Ret_Top)
{
    ReturnStatus_t RetState = R_NOK;
    if ((NULL == My_Stack) || (NULL == Ret_Top) || (STACK_EMPTY == Is_StackEmpty(My_Stack)))
    {
        RetState = R_NOK;
#ifdef DEBUG_MODE
        printf("Stack Top  Failed !!\n");
#endif
    }
    else
    {
        *Ret_Top = My_Stack->Data[My_Stack->Top];
        RetState = R_OK;
#ifdef DEBUG_MODE
        printf("Stack Top (%i) Sucsessed :) \n", *Ret_Top);
#endif
    }
    return RetState;
}
/*
 * @brief  : Size of the stack
 * @param  : My_Stack  Pointer to the stack
 * @param  : Ret_Size  Size value of the stack
 * @retval : Return status of the stack
 */
ReturnStatus_t Stack_Size(Stack_Ds_t *My_Stack, uint32_t *Ret_Size)
{
    ReturnStatus_t RetState = R_NOK;
    if ((NULL == My_Stack) || (NULL == Ret_Size))
    {
        RetState = R_NOK;
#ifdef DEBUG_MODE
        printf("Stack Size  Failed !!\n");
#endif
    }
    else
    {
        *Ret_Size = My_Stack->Top + 1;
        RetState = R_OK;
#ifdef DEBUG_MODE
        printf("Stack Size (%i) Sucsessed :) \n", *Ret_Size);
#endif
    }
    return RetState;
}
/*
 * @brief  : Display elements of the stack
 * @param  : My_Stack  Pointer to the stack
 * @retval : Return status of the stack
 */
ReturnStatus_t Stack_Display(Stack_Ds_t *My_Stack)
{
    ReturnStatus_t RetState = R_NOK;
    sint32_t Counter = 0;
    if (NULL == My_Stack)
    {
        RetState = R_NOK;
#ifdef DEBUG_MODE
        printf("Stack Display Failed !!\n");
#endif
    }
    else if (STACK_EMPTY == Is_StackEmpty(My_Stack))
    {
        RetState = R_NOK;
#ifdef DEBUG_MODE
        printf("Stack Empty . Display Failed !!\n");
#endif
    }

    else
    {
        printf("Stack Data : \n");
        for (Counter = My_Stack->Top; Counter >= 0; Counter--)
        {
            printf("%i \t", My_Stack->Data[Counter]);
        }
        printf("\n");

        RetState = R_OK;
#ifdef DEBUG_MODE
        printf("Stack Display  Sucsessed :) \n");
#endif
    }
    return RetState;
}
