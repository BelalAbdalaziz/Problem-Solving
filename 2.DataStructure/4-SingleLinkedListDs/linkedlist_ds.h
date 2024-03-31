#ifndef _LINKEDLIST_DS_H
#define _LINKEDLIST_DS_H

#include "std_types.h"

typedef struct Node
{
    void *Node_Data;
    struct Node *Next_Node;
} Node_t;

typedef enum
{
    LINKED_LIST_NOK,
    LINKED_LIST_OK,
    LINKED_LIST_NODE_CREAT_FILED,
    LINKED_LIST_EMPTY,
    LINKED_LIST_NODE_INSERTED,
    LINKED_LIST_NODE_DELETED,
    LINKED_LIST_DISPLAIED,
    LINKED_LIST_LENGTH_VALID,
    LINKED_LIST_NULL_POINTER,
    LINKED_LIST_POS_OUT_OF_RANGE,
} LinkedListStatus_t;

void List_PrintStatus(LinkedListStatus_t Status);

LinkedListStatus_t List_InsertAtBegin(Node_t **Head, void *Data);
LinkedListStatus_t List_InsertAtEnd(Node_t **Head, void *Data);
LinkedListStatus_t List_InsertAfterPos(Node_t **Head, uint32_t Pos, void *Data);

LinkedListStatus_t List_DeleteBegin(Node_t **Head);
LinkedListStatus_t List_DeleteEnd(Node_t **Head);
LinkedListStatus_t List_DeleteAtPos(Node_t **Head, uint32_t Pos);

LinkedListStatus_t List_Display(Node_t *Head);
LinkedListStatus_t List_GetLength(Node_t *Head, uint32_t *RetLength);

#endif /*_LINKEDLIST_DS_H*/