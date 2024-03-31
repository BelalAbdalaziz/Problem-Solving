#include "appliction.h"

Node_t *Head1;

uint32_t Data1 = 11;
uint32_t Data2 = 22;
uint32_t Data3 = 33;
uint32_t Data4 = 44;
uint32_t Data5 = 55;
uint32_t RetLenght = 0;

LinkedListStatus_t RetStatus = LINKED_LIST_NOK;

int main()
{
    List_PrintStatus(List_InsertAtBegin(&Head1, &Data1));
    List_PrintStatus(List_InsertAtBegin(&Head1, &Data2));
    List_PrintStatus(List_InsertAtBegin(&Head1, &Data3));

    List_PrintStatus(List_Display(Head1));

    List_PrintStatus(List_InsertAtEnd(&Head1, &Data4));

    List_PrintStatus(List_Display(Head1));

    List_PrintStatus(List_InsertAfterPos(&Head1, 2, &Data5));
    List_PrintStatus(List_Display(Head1));

    // List_PrintStatus(List_DeleteBegin(&Head1));
    List_PrintStatus(List_DeleteAtPos(&Head1, 1));
    List_PrintStatus(List_Display(Head1));

    // List_PrintStatus(List_DeleteEnd(&Head1));
    List_PrintStatus(List_DeleteAtPos(&Head1, 4));
    List_PrintStatus(List_Display(Head1));

    List_PrintStatus(List_GetLength(Head1, &RetLenght));
    printf("List Lenght <%i> \n", RetLenght);
}
