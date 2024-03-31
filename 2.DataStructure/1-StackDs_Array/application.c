#include "application.h"

Stack_Ds_t My_Stack;

int main()
{
    ReturnStatus_t Ret_Status = R_NOK;
    uint32_t Popped_Value = ZERO_INIT;
    uint32_t S_Size = ZERO_INIT;
    uint32_t S_Top = ZERO_INIT;

    /*Stack Initialization*/
    Ret_Status = Stack_Init(&My_Stack);

    /*Stack Push*/
    Ret_Status = Stack_Push(&My_Stack, 11);
    Ret_Status = Stack_Push(&My_Stack, 22);
    Ret_Status = Stack_Push(&My_Stack, 33);
    Ret_Status = Stack_Push(&My_Stack, 44);
    Ret_Status = Stack_Push(&My_Stack, 55);
    /*Stack Size*/
    Ret_Status = Stack_Size(&My_Stack, &S_Size);
    /*Stack Top*/
    Ret_Status = Stack_Top(&My_Stack, &S_Top);
    /*Stack Display*/
    printf("Hello Pop1\n");
    Ret_Status = Stack_Display(&My_Stack);
    printf("Hello Pop2\n");

    /*Stack pop*/
    Ret_Status = Stack_Pop(&My_Stack, &Popped_Value);
    Ret_Status = Stack_Pop(&My_Stack, &Popped_Value);
    Ret_Status = Stack_Pop(&My_Stack, &Popped_Value);
    Ret_Status = Stack_Pop(&My_Stack, &Popped_Value);
    Ret_Status = Stack_Pop(&My_Stack, &Popped_Value);
    /*Stack Size*/
    Ret_Status = Stack_Size(&My_Stack, &S_Size);
    /*Stack Top*/
    Ret_Status = Stack_Top(&My_Stack, &S_Top);
    /*Stack Display*/
    Ret_Status = Stack_Display(&My_Stack);
    return 0;
}
/*
 if (R_NOK == Ret_Status)
    {
        printf("Initialization Failed !!\n");
    }
    else
    {
        // Write your code here
        printf("Initialization Sucessful\n");
    }
*/