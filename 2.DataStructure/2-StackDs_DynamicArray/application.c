#include "application.h"

StackDynamic_t *New_Stack1 = NULL;
StackDynamic_t *Destroy_Stack1 = NULL;
StackStatus_t Stack1_Status = STACK_EMPTY;
uint32_t Stack_Counter = 0;
void *Popped_Val = NULL;

uint8_t Var1 = 11;
uint8_t Var2 = 22;
uint8_t Var3 = 33;
uint32_t Var4 = 0x03;
char Var5 = 'B';
int main()
{
    uint32_t StackOneElements = 3;
    /*Take input from user (number of  elements) */
    printf("Enter number of Stack 1 elements \n");
    scanf("%i", &StackOneElements);
    fflush(stdin);
    /**********************************************************************/
    /********************** Creat the New Stack ***************************/
    /**********************************************************************/
    New_Stack1 = Stack_Creat(StackOneElements, &Stack1_Status);
    Stack_PrintStatus(Stack1_Status);
    /**********************************************************************/
    /******************* Push Values To the Stack *************************/
    /**********************************************************************/
    Stack1_Status = Stack_Push(New_Stack1, &Var1);
    if (STACK_VAL_IS_PUSHED == Stack1_Status)
    {
        printf("(%i) ", *((uint8_t *)New_Stack1->Stack_Array[New_Stack1->Stack_Top]));
    }
    Stack1_Status = Stack_Push(New_Stack1, &Var2);
    if (STACK_VAL_IS_PUSHED == Stack1_Status)
    {
        printf("(%i) ", *((uint8_t *)New_Stack1->Stack_Array[New_Stack1->Stack_Top]));
    }
    Stack1_Status = Stack_Push(New_Stack1, &Var3);
    if (STACK_VAL_IS_PUSHED == Stack1_Status)
    {
        printf("(%i) ", *((uint8_t *)New_Stack1->Stack_Array[New_Stack1->Stack_Top]));
    }
    Stack_PrintStatus(Stack1_Status);
    /**********************************************************************/
    Stack1_Status = Stack_Push(New_Stack1, &Var4);
    if (STACK_VAL_IS_PUSHED == Stack1_Status)
    {
        printf("(0x%X) ", *((uint32_t *)New_Stack1->Stack_Array[New_Stack1->Stack_Top]));
    }
    Stack_PrintStatus(Stack1_Status);
    /**********************************************************************/

    Stack1_Status = Stack_Push(New_Stack1, &Var5);
    if (STACK_VAL_IS_PUSHED == Stack1_Status)
    {
        printf("(%c) ", *((char *)New_Stack1->Stack_Array[New_Stack1->Stack_Top]));
    }
    Stack_PrintStatus(Stack1_Status);
    /**********************************************************************/
    /************************ Stack Display ,Count ************************/
    /**********************************************************************/
    // Stack1_Status = Stack_Display(New_Stack1);
    // Stack_PrintStatus(Stack1_Status);

    Stack1_Status = Stack_Count(New_Stack1, &Stack_Counter);
    if (STACK_IS_Counted == Stack1_Status)
    {
        printf("(%i) ", Stack_Counter);
    }
    Stack_PrintStatus(Stack1_Status);

    /**********************************************************************/
    /******************* Pop Values From the Stack ************************/
    /**********************************************************************/
    Popped_Val = Stack_pop(New_Stack1, &Stack1_Status);
    if (STACK_VAL_IS_POPPED == Stack1_Status)
    {
        printf("(%i) ", *((uint8_t *)Popped_Val));
    }
    Stack_PrintStatus(Stack1_Status);
    /**********************************************************************/
    Popped_Val = Stack_pop(New_Stack1, &Stack1_Status);
    if (STACK_VAL_IS_POPPED == Stack1_Status)
    {
        printf("(%i) ", *((uint8_t *)Popped_Val));
    }
    Stack_PrintStatus(Stack1_Status);
    /**********************************************************************/
    Popped_Val = Stack_pop(New_Stack1, &Stack1_Status);
    if (STACK_VAL_IS_POPPED == Stack1_Status)
    {
        printf("(%i) ", *((uint8_t *)Popped_Val));
    }
    Stack_PrintStatus(Stack1_Status);
    /**********************************************************************/
    Popped_Val = Stack_pop(New_Stack1, &Stack1_Status);
    if (STACK_VAL_IS_POPPED == Stack1_Status)
    {
        printf("(%i) ", *((uint8_t *)Popped_Val));
    }
    Stack_PrintStatus(Stack1_Status);
    /**********************************************************************/
    /********************** Destroy the Stack *****************************/
    /**********************************************************************/
    New_Stack1 = Stack_Destroy(New_Stack1, &Stack1_Status);
    Stack_PrintStatus(Stack1_Status);
}
