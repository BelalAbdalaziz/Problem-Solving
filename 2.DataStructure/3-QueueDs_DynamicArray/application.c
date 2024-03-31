#include "application.h"

Queue_t *NewQueueAdd = NULL;
Queue_t *DestroiedQueueAdd = NULL;
QueueStatus_t RetQueueStatus = QUEUE_NOK;
uint32_t Max_Size_Elements = 0;
void *Dequeue_Value = NULL;

uint32_t Enqueu_Value_1 = 11;
uint32_t Enqueu_Value_2 = 22;
uint8_t Enqueu_Value_3 = 'B';
uint32_t Enqueu_Value_4 = 44;
uint32_t Enqueu_Value_5 = 0x55;
uint32_t Enqueu_Value_6 = 66;

int main()
{
    printf("Enter Max Size Of Queue Elements \n");
    scanf("%i", &Max_Size_Elements); // Enter 6
    /*Creat queue object*/
    NewQueueAdd = Queue_Creat(Max_Size_Elements, &RetQueueStatus);
    Queue_PrintStatus(RetQueueStatus);

    /*Test other functions*/

    // Enqueu 1
    RetQueueStatus = Queue_Enqueue(NewQueueAdd, &Enqueu_Value_1);
    printf("<%i>", *((uint32_t *)NewQueueAdd->Queue_Array[NewQueueAdd->Queue_Rear]));
    Queue_PrintStatus(RetQueueStatus);
    // Enqueu 2
    RetQueueStatus = Queue_Enqueue(NewQueueAdd, &Enqueu_Value_2);
    printf("<%i>", *((uint32_t *)NewQueueAdd->Queue_Array[NewQueueAdd->Queue_Rear]));
    Queue_PrintStatus(RetQueueStatus);
    // Enqueu 3
    RetQueueStatus = Queue_Enqueue(NewQueueAdd, &Enqueu_Value_3);
    printf("<%c>", *((uint8_t *)NewQueueAdd->Queue_Array[NewQueueAdd->Queue_Rear]));
    Queue_PrintStatus(RetQueueStatus);
    // Enqueu 4
    RetQueueStatus = Queue_Enqueue(NewQueueAdd, &Enqueu_Value_4);
    printf("<%i>", *((uint32_t *)NewQueueAdd->Queue_Array[NewQueueAdd->Queue_Rear]));
    Queue_PrintStatus(RetQueueStatus);
    // Enqueu 5
    RetQueueStatus = Queue_Enqueue(NewQueueAdd, &Enqueu_Value_5);
    printf("<0x%X>", *((uint32_t *)NewQueueAdd->Queue_Array[NewQueueAdd->Queue_Rear]));
    Queue_PrintStatus(RetQueueStatus);
    // Enqueu 6
    RetQueueStatus = Queue_Enqueue(NewQueueAdd, &Enqueu_Value_6);
    printf("<%i>", *((uint32_t *)NewQueueAdd->Queue_Array[NewQueueAdd->Queue_Rear]));
    Queue_PrintStatus(RetQueueStatus);

    // Front
    Dequeue_Value = Queue_Front(NewQueueAdd, &RetQueueStatus);
    printf("<%i>", *((uint32_t *)Dequeue_Value));
    Queue_PrintStatus(RetQueueStatus);
    // Rear
    Dequeue_Value = Queue_Rear(NewQueueAdd, &RetQueueStatus);
    printf("<%i>", *((uint32_t *)Dequeue_Value));
    Queue_PrintStatus(RetQueueStatus);

    // Dequeue 1
    Dequeue_Value = Queue_Dequeue(NewQueueAdd, &RetQueueStatus);
    if (!Dequeue_Value)
    {
        Queue_PrintStatus(RetQueueStatus);
    }
    else
    {
        printf("<%i>", *((uint32_t *)Dequeue_Value));
        Queue_PrintStatus(RetQueueStatus);
    }
    // Dequeue 2
    Dequeue_Value = Queue_Dequeue(NewQueueAdd, &RetQueueStatus);
    if (!Dequeue_Value)
    {
        Queue_PrintStatus(RetQueueStatus);
    }
    else
    {
        printf("<%i>", *((uint32_t *)Dequeue_Value));
        Queue_PrintStatus(RetQueueStatus);
    }
    // Dequeue 3
    Dequeue_Value = Queue_Dequeue(NewQueueAdd, &RetQueueStatus);
    if (!Dequeue_Value)
    {
        Queue_PrintStatus(RetQueueStatus);
    }
    else
    {
        printf("<%c>", *((uint8_t *)Dequeue_Value));
        Queue_PrintStatus(RetQueueStatus);
    }
    // Dequeue 4
    Dequeue_Value = Queue_Dequeue(NewQueueAdd, &RetQueueStatus);
    if (!Dequeue_Value)
    {
        Queue_PrintStatus(RetQueueStatus);
    }
    else
    {
        printf("<%i>", *((uint32_t *)Dequeue_Value));
        Queue_PrintStatus(RetQueueStatus);
    }
    // Dequeue 5
    Dequeue_Value = Queue_Dequeue(NewQueueAdd, &RetQueueStatus);
    if (!Dequeue_Value)
    {
        Queue_PrintStatus(RetQueueStatus);
    }
    else
    {
        printf("<0x%X>", *((uint32_t *)Dequeue_Value));
        Queue_PrintStatus(RetQueueStatus);
    }
    // Dequeue 6
    Dequeue_Value = Queue_Dequeue(NewQueueAdd, &RetQueueStatus);
    if (!Dequeue_Value)
    {
        Queue_PrintStatus(RetQueueStatus);
    }
    else
    {
        printf("<%i>", *((uint32_t *)Dequeue_Value));
        Queue_PrintStatus(RetQueueStatus);
    }
    /*Destroy queue object*/
    DestroiedQueueAdd = Queue_Destroy(NewQueueAdd, &RetQueueStatus);
    Queue_PrintStatus(RetQueueStatus);

    return 0;
}