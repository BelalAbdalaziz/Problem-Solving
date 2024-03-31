#include "linkedlist_ds.h"

static boolean_t List_IsEmpty(Node_t *Head)
{
    return (NULL == Head);
}
LinkedListStatus_t List_InsertAtBegin(Node_t **Head, void *Data)
{
    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    Node_t *TempNode = NULL; /*To creat node in it*/
    if (NULL == Data)
    {
        RetStatus = LINKED_LIST_NULL_POINTER;
    }
    else
    {
        /*Creat Node*/
        TempNode = (Node_t *)malloc(sizeof(Node_t));
        if (NULL == TempNode)
        { /*Validate Node Creation*/
            RetStatus = LINKED_LIST_NODE_CREAT_FILED;
        }
        else
        { /*Check Empty Linked List */
            if (List_IsEmpty(*Head))
            {
                TempNode->Node_Data = Data;
                *Head = TempNode;
            }
            else
            {
                TempNode->Node_Data = Data;
                TempNode->Next_Node = *Head;
                *Head = TempNode;
            }
            RetStatus = LINKED_LIST_NODE_INSERTED;
        }
    }
    return RetStatus;
}
LinkedListStatus_t List_InsertAtEnd(Node_t **Head, void *Data)
{
    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    Node_t *TempNode = NULL;    /*To creat node by it*/
    Node_t *NodeCounter = NULL; /*For traversing to go to the end of list*/
    if (NULL == Data)
    {
        RetStatus = LINKED_LIST_NULL_POINTER;
    }
    else
    {
        /*Creat Node*/
        TempNode = (Node_t *)malloc(sizeof(Node_t));
        if (NULL == TempNode)
        { /*Validate Node Creation*/
            RetStatus = LINKED_LIST_NODE_CREAT_FILED;
        }
        else
        { /*Fill Node */
            TempNode->Node_Data = Data;
            TempNode->Next_Node = NULL;
            /*<Put Node at the End position>*/
            /*Check Empty Linked List */
            if (List_IsEmpty(*Head))
            {
                *Head = TempNode;
            }
            else
            { /*Traversing to the end of list*/
                NodeCounter = *Head;
                while (NULL != NodeCounter->Next_Node)
                {
                    NodeCounter = NodeCounter->Next_Node;
                }
                NodeCounter->Next_Node = TempNode;
            }
            RetStatus = LINKED_LIST_NODE_INSERTED;
        }
    }
    return RetStatus;
}
LinkedListStatus_t List_InsertAfterPos(Node_t **Head, uint32_t Pos, void *Data)
{
    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    Node_t *TempNode = NULL;    /*To creat node by it*/
    Node_t *NodeCounter = NULL; /*For traversing to go to the end of list*/
    uint32_t Counter = 1;       /*To use it with Pos to go to specific position */
    uint32_t ListLenght = 0;    /*To store lenght of the current linked list*/
    if (NULL == Data)
    {
        RetStatus = LINKED_LIST_NULL_POINTER;
    }
    else
    {
        /*Check entry position is out of range of Linked List */
        List_GetLength(*Head, &ListLenght);
        if (Pos > ListLenght)
        {
            RetStatus = LINKED_LIST_POS_OUT_OF_RANGE;
        }
        else if (1 == Pos)
        {
            RetStatus = List_InsertAtBegin(Head, Data);
        }
        else
        {
            /*Creat Node*/
            TempNode = (Node_t *)malloc(sizeof(Node_t));
            if (NULL == TempNode)
            { /*Validate Node Creation*/
                RetStatus = LINKED_LIST_NODE_CREAT_FILED;
            }
            else
            { /*Fill Node */
                TempNode->Node_Data = Data;
                /*<Put Node at the specific position & attatch it to the list>*/
                /*Traversing to the Specific position to insert it after*/
                NodeCounter = *Head;
                while (Counter < Pos)
                {
                    NodeCounter = NodeCounter->Next_Node;
                    Counter++;
                }
                TempNode->Next_Node = NodeCounter->Next_Node; /*Attatch to right side*/
                NodeCounter->Next_Node = TempNode;            /*Attatch to left side*/

                RetStatus = LINKED_LIST_NODE_INSERTED;
            }
        }
    }
    return RetStatus;
}

LinkedListStatus_t List_DeleteBegin(Node_t **Head)
{
    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    Node_t *TempNode = *Head; /*Use it to free deleted node */
    if (List_IsEmpty(*Head))
    {
        RetStatus = LINKED_LIST_EMPTY;
    }
    else
    {
        *Head = TempNode->Next_Node;
        free(TempNode);
        RetStatus = LINKED_LIST_NODE_DELETED;
    }
    return RetStatus;
}
LinkedListStatus_t List_DeleteEnd(Node_t **Head)
{
    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    Node_t *NodeCounter = *Head; /*Use it for travesing */
    Node_t *TempNode = NULL;     /*Use it to free deleted node */
    if (List_IsEmpty(*Head))
    {
        RetStatus = LINKED_LIST_EMPTY;
    }
    else
    { /*Linked List Travsersing till <before last node> to delete last node */
        while (NULL != (NodeCounter->Next_Node->Next_Node))
        {
            NodeCounter = NodeCounter->Next_Node;
        } /*Now Node Counter Before last node */
        TempNode = NodeCounter->Next_Node;
        NodeCounter->Next_Node = NULL;
        free(TempNode);
        RetStatus = LINKED_LIST_NODE_DELETED;
    }
    return RetStatus;
}
LinkedListStatus_t List_DeleteAtPos(Node_t **Head, uint32_t Pos)
{
    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    Node_t *NodeCounter = *Head;     /*Use it for traversing */
    uint32_t Counter = 1;            /*Use it for traversing till needed pos   */
    Node_t *TempNode = NULL;         /*Use it to free deleted node */
    uint32_t ListLenght = ZERO_INIT; /*Use it to check pos>length */

    List_GetLength(*Head, &ListLenght);
    if (List_IsEmpty(*Head))
    { /*Validate empty list*/
        RetStatus = LINKED_LIST_EMPTY;
    }
    else if ((Pos > ListLenght) || (Pos < 1))
    { /*Validate position is out of range */
        RetStatus = LINKED_LIST_POS_OUT_OF_RANGE;
    }
    else if (1 == Pos)
    { /*Check if delete begin*/
        RetStatus = List_DeleteBegin(Head);
    }
    else if (ListLenght == Pos)
    {
        RetStatus = List_DeleteEnd(Head);
    }
    else
    {
        while (Counter < (Pos - 1))
        {
            NodeCounter = NodeCounter->Next_Node;
            Counter++;
        } /*Now Node Counter Before Needed Pos  */

        TempNode = NodeCounter->Next_Node; /*Temp node = needed node to delete*/
        NodeCounter->Next_Node = TempNode->Next_Node;
        free(TempNode);
        RetStatus = LINKED_LIST_NODE_DELETED;
    }
    return RetStatus;
}

LinkedListStatus_t List_Display(Node_t *Head)
{
    Node_t *NodeCounter = Head;
    printf("Node Values : \n");

    if (NULL == NodeCounter)
    { /*Validate empty list*/
        printf("List is empty !! \n");
    }
    else
    { /*Traversing in list */
        while (NULL != NodeCounter)
        {
            printf("(%i) -> ", *((uint32_t *)NodeCounter->Node_Data));
            NodeCounter = NodeCounter->Next_Node;
        }
        if (NULL == NodeCounter)
        { /*At the end*/
            printf("NULL");
        }
        printf("\n");
    }
    return LINKED_LIST_DISPLAIED;
}
LinkedListStatus_t List_GetLength(Node_t *Head, uint32_t *RetLength)
{
    Node_t *NodeCounter = Head;
    uint32_t Counter = 0;
    while (NULL != NodeCounter)
    {
        NodeCounter = NodeCounter->Next_Node;
        Counter++;
    }
    *RetLength = Counter;
    return LINKED_LIST_LENGTH_VALID;
}

void List_PrintStatus(LinkedListStatus_t Status)
{
    switch (Status)
    {
    case LINKED_LIST_NOK:
        printf("Linked list not ok !! \n");
        break;
    case LINKED_LIST_OK:
        printf("Linked list is ok :) \n");
        break;
    case LINKED_LIST_NODE_CREAT_FILED:
        printf("Creat node at the linked list is failed  !! \n");
        break;
    case LINKED_LIST_EMPTY:
        printf("Linked list is empty !! \n");
        break;
    case LINKED_LIST_NODE_INSERTED:
        printf("Creat node at the linked list is Sucessed :) \n");
        break;
    case LINKED_LIST_NODE_DELETED:
        printf("Delete node from the linked list is Sucessed :) \n");
        break;
    case LINKED_LIST_DISPLAIED:
        printf("Display all Nodes in linked list is Sucessed :) \n");
        break;
    case LINKED_LIST_LENGTH_VALID:
        printf("The linked list length is valid : \n");
        break;
    case LINKED_LIST_NULL_POINTER:
        printf("The linked list arguments is null pointer !! \n");
        break;
    case LINKED_LIST_POS_OUT_OF_RANGE:
        printf(" Position is out of range of the linked list !!\n");
        break;
    default:
        printf("Error Status \n");
        break;
    }
}