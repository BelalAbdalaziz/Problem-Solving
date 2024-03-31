#include "application.h"

Node_t *Head_1 = NULL;
LinkedListStatus_t Status = LINKED_LIST_NOK;
uint32_t RetLenght = 0;

uint32_t Data1 = 11;
uint32_t Data2 = 22;
uint32_t Data3 = 33;
uint32_t Data4 = 44;
uint32_t Data5 = 55;
uint32_t Data6 = 66;
uint32_t Data7 = 77;
uint32_t Data8 = 88;

int main()
{
    List_PrintStatus(List_InsertAtBegin(&Head_1, &Data1));
    List_PrintStatus(List_InsertAtBegin(&Head_1, &Data2));
    List_PrintStatus(List_InsertAtBegin(&Head_1, &Data3));

    List_PrintStatus(List_DisplayForward(Head_1));

    List_PrintStatus(List_InsertAtEnd(&Head_1, &Data4));
    List_PrintStatus(List_InsertAtEnd(&Head_1, &Data5));

    List_PrintStatus(List_DisplayForward(Head_1));
    List_PrintStatus(List_GetLength(Head_1, &RetLenght));
    printf("<%i>\n", RetLenght);
    printf("-----------------------------\n");
    List_PrintStatus(List_InsertAfterPos(&Head_1, 1, &Data6));
    printf("-----------------------------\n");
    List_PrintStatus(List_InsertAfterPos(&Head_1, 6, &Data7));
    printf("-----------------------------\n");
    List_PrintStatus(List_InsertAfterPos(&Head_1, 3, &Data7));

    List_PrintStatus(List_DisplayForward(Head_1));

    printf("-----------------------------\n");
    List_PrintStatus(List_InsertBeforePos(&Head_1, 1, &Data3));
    printf("-----------------------------\n");
    List_PrintStatus(List_InsertBeforePos(&Head_1, 9, &Data3));
    printf("-----------------------------\n");
    List_PrintStatus(List_InsertBeforePos(&Head_1, 6, &Data3));

    List_PrintStatus(List_DisplayForward(Head_1));

    List_PrintStatus(List_DeleteBegin(&Head_1));
    List_PrintStatus(List_DeleteBegin(&Head_1));
    List_PrintStatus(List_DeleteBegin(&Head_1));

    List_PrintStatus(List_DisplayForward(Head_1));

    List_PrintStatus(List_DeleteEnd(Head_1));
    List_PrintStatus(List_DeleteEnd(Head_1));

    List_PrintStatus(List_DisplayForward(Head_1));

    List_PrintStatus(List_DeleteAtPos(&Head_1, 1));
    List_PrintStatus(List_DeleteAtPos(&Head_1, 5));
    List_PrintStatus(List_DeleteAtPos(&Head_1, 3));

    List_PrintStatus(List_DisplayForward(Head_1));
}