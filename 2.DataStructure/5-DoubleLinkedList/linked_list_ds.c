#include "linked_list_ds.h"

boolean_t List_IsEmpty(Node_t *Head)
{
    return (NULL == Head);
}

LinkedListStatus_t List_InsertAtBegin(Node_t **Head, void *Data)
{
    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    Node_t *NewNode = NULL;

    if (NULL == Data)
    {
        RetStatus = LINKED_LIST_NULL_POINTER;
    }
    else
    {
        NewNode = (Node_t *)malloc(sizeof(Node_t));
        if (NULL == NewNode)
        { /*Validate new node is created*/
            RetStatus = LINKED_LIST_NODE_CREAT_FILED;
        }
        else
        {
            NewNode->Node_Data = Data; /*Fill Node Data*/
            /*Attach Node to the list*/
            if (List_IsEmpty(*Head))
            { /*Check List is empty */
                *Head = NewNode;
                NewNode->Prev_Node = NULL;
                NewNode->Next_Node = NULL;
            }
            else
            { /*Not empty list*/

                NewNode->Next_Node = *Head;   /*Right Link*/
                NewNode->Prev_Node = NULL;    /*left link*/
                (*Head)->Prev_Node = NewNode; /*Old 1st Node Attach to new 1st node*/
                *Head = NewNode;              /*Head point to new node*/
            }
            RetStatus = LINKED_LIST_NODE_INSERTED;
        }
    }
    return RetStatus;
}
LinkedListStatus_t List_InsertAtEnd(Node_t **Head, void *Data)
{
    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    Node_t *NewNode = NULL;      /*Use it to creat node */
    Node_t *NodeCounter = *Head; /*Use it for traversing till the end of list*/

    if (NULL == Data)
    {
        RetStatus = LINKED_LIST_NULL_POINTER;
    }
    else
    {

        if (List_IsEmpty(*Head))
        { /*Check empty list*/
            RetStatus = List_InsertAtBegin(Head, Data);
        }
        else
        { /*Creat Node*/
            NewNode = (Node_t *)malloc(sizeof(Node_t));

            if (NULL == NewNode)
            { /*Validate Node is created or not*/
                RetStatus = LINKED_LIST_NODE_CREAT_FILED;
            }
            else
            {
                /*Fill Data to node*/
                NewNode->Node_Data = Data;
                /*Traversing till end of list*/
                while (NULL != NodeCounter->Next_Node)
                {
                    NodeCounter = NodeCounter->Next_Node;
                } /*Now NodeCounter is last node of list*/

                NewNode->Next_Node = NULL;        /*Right Link*/
                NewNode->Prev_Node = NodeCounter; /*Left Link*/
                NodeCounter->Next_Node = NewNode; /*Attach Old last node to new last node*/

                RetStatus = LINKED_LIST_NODE_INSERTED;
            }
        }
    }
    return RetStatus;
}
LinkedListStatus_t List_InsertAfterPos(Node_t **Head, uint32_t Pos, void *Data)
{
    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    uint32_t RetLength = 0;
    uint32_t Counter = 1;          /* use it to traversing till Pos*/
    Node_t *NodeCounter_1 = *Head; /*Use it for travesing till Pos => NodeCounter_1 -> NewNode -> NodeCounter_2*/
    Node_t *NodeCounter_2 = NULL;  /*Use it to save Info  after NewNode node*/
    Node_t *NewNode = NULL;        /*Use it to creat node */

    if (NULL == Data)
    {
        RetStatus = LINKED_LIST_NULL_POINTER;
    }
    else
    { /*Creat New Node*/
        NewNode = (Node_t *)malloc(sizeof(Node_t));
        if (NULL == NewNode)
        {
            RetStatus = LINKED_LIST_NODE_CREAT_FILED;
        }
        else
        { /*Fill data to node */
            NewNode->Node_Data = Data;
            /*Insert at  after pos <1>*/
            if (1 == Pos)
            {
                NodeCounter_1 = *Head;              /*Node Before*/
                NodeCounter_2 = (*Head)->Next_Node; /*Node After*/
                NewNode->Next_Node = NodeCounter_2; /*Right link*/
                NewNode->Prev_Node = NodeCounter_1; /*Left link*/
                NodeCounter_1->Next_Node = NewNode; /*Attach to the list*/
                NodeCounter_2->Prev_Node = NewNode; /*Attach to the list*/

                RetStatus = LINKED_LIST_NODE_INSERTED;
            }
            else
            {
                /*Traversing Till Pos */
                while (Counter < Pos)
                {
                    NodeCounter_1 = NodeCounter_1->Next_Node;
                    Counter++;
                } /*Now NodeCounter_1 at specific pos */
                /*check if Pos is Last Node*/
                if (NULL == NodeCounter_1->Next_Node)
                {
                    NewNode->Next_Node = NULL;          /*Right Link*/
                    NewNode->Prev_Node = NodeCounter_1; /*Left Link*/
                    NodeCounter_1->Next_Node = NewNode; /*Attach to the list*/
                }
                else
                { /*Pos between 2 Nodes in the list*/

                    NodeCounter_2 = NodeCounter_1->Next_Node; /*Node After*/
                    NewNode->Next_Node = NodeCounter_2;       /*Right link*/
                    NewNode->Prev_Node = NodeCounter_1;       /*Left link*/
                    NodeCounter_1->Next_Node = NewNode;       /*Attach to the list from left*/
                    NodeCounter_2->Prev_Node = NewNode;       /*Attach to the list from right*/
                }
                RetStatus = LINKED_LIST_NODE_INSERTED;
            }
        }

        RetStatus = LINKED_LIST_OK;
    }
    return RetStatus;
}
LinkedListStatus_t List_InsertBeforePos(Node_t **Head, uint32_t Pos, void *Data)
{
    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    Node_t *NodeCounter_1 = *Head;
    Node_t *NodeCounter_2 = NULL;
    Node_t *NewNode = NULL;
    uint32_t Counter = 1;
    if (NULL == Data)
    {
        RetStatus = LINKED_LIST_NULL_POINTER;
    }
    else
    {
        NewNode = (Node_t *)malloc(sizeof(Node_t));
        if (NULL == NewNode)
        {
            RetStatus = LINKED_LIST_NODE_CREAT_FILED;
        }
        else
        { /*Fill data to new node*/
            NewNode->Node_Data = Data;
            /*Attach NewNode to the list*/
            if (1 == Pos)
            { /*Before Pos 1 is Begining of the list*/

                NewNode->Next_Node = *Head;   /*Right link*/
                NewNode->Prev_Node = NULL;    /*Left link*/
                (*Head)->Prev_Node = NewNode; /*Attatch NewNode to the list from right*/
                *Head = NewNode;              /*Attatch NewNode to the list from left*/
            }
            else
            {
                /*Traversing Till Node Before specific node*/
                while (Counter < (Pos - 1))
                {
                    NodeCounter_1 = NodeCounter_1->Next_Node;
                    Counter++;
                } /*NodeCounter_1 is Node Before NewNode*/

                NodeCounter_2 = NodeCounter_1->Next_Node; /* NodeCounter_2 is Node After NewNode*/
                NewNode->Next_Node = NodeCounter_2;       /*Right link*/
                NewNode->Prev_Node = NodeCounter_1;       /*Left link*/
                NodeCounter_1->Next_Node = NewNode;       /*Attach to the list from left */
                NodeCounter_2->Prev_Node = NewNode;       /*Attach to the list from right */
            }
            RetStatus = LINKED_LIST_NODE_INSERTED;
        }
    }
    return RetStatus;
}

LinkedListStatus_t List_DeleteBegin(Node_t **Head)
{
    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    Node_t *TempNode = *Head;
    /*Validate empty list*/
    if (List_IsEmpty(*Head))
    {
        RetStatus = LINKED_LIST_EMPTY;
    }
    else
    {
        *Head = TempNode->Next_Node;           /*Head attach to the new 1st node*/
        TempNode->Next_Node->Prev_Node = NULL; /*Left link of new 1st node*/
        free(TempNode);
        TempNode = NULL;

        RetStatus = LINKED_LIST_NODE_DELETED;
    }
    return RetStatus;
}
LinkedListStatus_t List_DeleteEnd(Node_t *Head)
{
    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    Node_t *NodeCounter_1 = Head; /*Use it for traversing till before end*/
    if (List_IsEmpty(Head))
    {
        RetStatus = LINKED_LIST_EMPTY;
    }
    else
    {
        /*Traversing till the end of list*/
        while (NULL != NodeCounter_1->Next_Node)
        {
            NodeCounter_1 = NodeCounter_1->Next_Node;
        } /*Now NodeCounter_1 is last Node*/
        NodeCounter_1->Prev_Node->Next_Node = NULL;
        free(NodeCounter_1);
        NodeCounter_1 = NULL;

        RetStatus = LINKED_LIST_NODE_DELETED;
    }

    return RetStatus;
}
LinkedListStatus_t List_DeleteAtPos(Node_t **Head, uint32_t Pos)
{
    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    Node_t *NodeCounter_1 = *Head;
    Node_t *NodeCounter_2 = NULL;
    Node_t *TempNode = NULL;
    uint32_t Counter = 1;
    uint32_t ListLengh = 0;
    List_GetLength(*Head, &ListLengh);
    if (List_IsEmpty(*Head))
    {
        RetStatus = LINKED_LIST_EMPTY;
    }
    else if (1 == Pos)
    {
        RetStatus = List_DeleteBegin(Head);
    }
    else if (ListLengh == Pos)
    {
        RetStatus = List_DeleteEnd(*Head);
    }
    else
    { /*Traversing till before specific Node*/
        while (Counter < (Pos - 1))
        {
            NodeCounter_1 = NodeCounter_1->Next_Node;
            Counter++;
        } /*NodeCounter_1 is Node Before nedded node*/

        TempNode = NodeCounter_1->Next_Node;      /*this Node Want to delete */
        NodeCounter_2 = TempNode->Next_Node;      /*NodeCounter_2 is Node After nedded node*/
        NodeCounter_1->Next_Node = NodeCounter_2; /*Right link of prev deleted node*/
        NodeCounter_2->Prev_Node = NodeCounter_1; /*Left link of Next deleted node*/
        free(TempNode);
        TempNode = NULL;

        RetStatus = LINKED_LIST_NODE_DELETED;
    }

    return RetStatus;
}

LinkedListStatus_t List_DisplayForward(Node_t *Head)
{
    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    Node_t *NodeCounter = Head; /*Use it for traversing till the end of list*/
    printf("Data is : \n ");
    printf("Forward Display => ");
    /*Traversing till the end of list*/
    while (NULL != NodeCounter)
    {
        printf(" %i ->", *((uint32_t *)NodeCounter->Node_Data));
        NodeCounter = NodeCounter->Next_Node;
    }
    if (NULL == NodeCounter)
    {
        printf(" NULL\n");
    }
    RetStatus = LINKED_LIST_DISPLAIED;

    return RetStatus;
}
LinkedListStatus_t List_DisplayReverse(Node_t *Head)
{

    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    Node_t *NodeCounter = Head; /*Use it for traversing till the end of list*/
    printf("Data is : \n ");
    printf("Reverse Display => ");
    /*Traversing till the end of list*/
    while (NULL != NodeCounter->Next_Node)
    {
        NodeCounter = NodeCounter->Next_Node;
    }
    while (NULL != NodeCounter)
    {
        printf(" %i ->", *((uint32_t *)NodeCounter->Node_Data));
        NodeCounter = NodeCounter->Prev_Node;
    }
    if (NULL == NodeCounter)
    {
        printf(" NULL\n");
    }
    RetStatus = LINKED_LIST_DISPLAIED;

    return RetStatus;
}
LinkedListStatus_t List_GetLength(Node_t *Head, uint32_t *RetLength)
{
    LinkedListStatus_t RetStatus = LINKED_LIST_NOK;
    Node_t *NodeCounter = Head;
    uint32_t Counter = 1;
    if (NULL == RetLength)
    {
        RetStatus = LINKED_LIST_NULL_POINTER;
    }
    else
    {
        while (NULL != NodeCounter->Next_Node)
        {
            NodeCounter = NodeCounter->Next_Node;
            Counter++;
        }
        *RetLength = Counter;
        RetStatus = LINKED_LIST_LENGTH_VALID;
    }
    return RetStatus;
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
