#include "queue_ds_dynamic_array.h"

/*
 * @brief  : Helper function to return queue is empty or not
 * @param : QueueObj  Pointer to queue
 * @retval : Return boolean empty or not
 */
static boolean_t Queue_IsEmpty(Queue_t *QueueObj)
{
    return (QueueObj->Queue_ElementsCount == 0);
}
/*
 * @brief  : Helper function to return queue is full or not
 * @param  : QueueObj  Pointer to queue
 * @retval : Return boolean full or not
 */
static boolean_t Queue_IsFull(Queue_t *QueueObj)
{
    return (QueueObj->Queue_ElementsCount == QueueObj->Queue_MaxSize);
}

Queue_t *Queue_Creat(uint32_t QueueMaxSize, QueueStatus_t *RetStatus)
{
    Queue_t *RetCreatedQueue = NULL;
    if (NULL == RetStatus)
    { /*Validate arguments of function*/
        *RetStatus = QUEUE_NULL_POINTER;
        RetCreatedQueue = NULL;
    }
    else
    {
        /*Creat queue object */
        RetCreatedQueue = (Queue_t *)malloc(sizeof(Queue_t));
        if (!RetCreatedQueue)
        {
            /*Validate queue is created or not*/
            *RetStatus = QUEUE_NOK;
            RetCreatedQueue = NULL;
        }
        else
        { /*Creat queue array*/
            RetCreatedQueue->Queue_Array = (void **)calloc(QueueMaxSize, sizeof(void *));
            if (!(RetCreatedQueue->Queue_Array))
            { /*Validate queue array is created or not*/
                *RetStatus = QUEUE_NOK;
                RetCreatedQueue = NULL;
            }
            else
            { /*Initialize queue elements */
                RetCreatedQueue->Queue_ElementsCount = 0;
                RetCreatedQueue->Queue_Front = -1;
                RetCreatedQueue->Queue_Rear = -1;
                RetCreatedQueue->Queue_MaxSize = QueueMaxSize;
                *RetStatus = QUEUE_CREATED;
            }
        }
    }
    return RetCreatedQueue;
}
Queue_t *Queue_Destroy(Queue_t *QueueObj, QueueStatus_t *RetStatus)
{
    Queue_t *RetDestroiedQueu = NULL;
    if ((NULL == QueueObj) || (NULL == RetStatus))
    { /*Validate arguments of function*/
        *RetStatus = QUEUE_NULL_POINTER;
        RetDestroiedQueu = QueueObj;
    }
    else
    {
        free(QueueObj->Queue_Array); /*Destroy queue array*/
        free(QueueObj);              /*Destroy queue object*/
        RetDestroiedQueu = NULL;
        *RetStatus = QUEUE_DESTROIED;
    }
    return RetDestroiedQueu;
}

QueueStatus_t Queue_Enqueue(Queue_t *QueueObj, void *EnqueuValue)
{
    QueueStatus_t RetStatus = QUEUE_NOK;
    if ((NULL == QueueObj) || (NULL == EnqueuValue))
    { /*Validate arguments of function*/
        RetStatus = QUEUE_NULL_POINTER;
    }
    else
    { /*Check queue is full*/
        if (Queue_IsFull(QueueObj))
        {
            RetStatus = QUEUE_FULL;
        }
        else
        {
            /*Increment queue rear*/
            (QueueObj->Queue_Rear)++;
            /*Check if enqueu val after last element  <Crircular Condition>*/
            if ((QueueObj->Queue_Rear) == (QueueObj->Queue_MaxSize))
            {
                (QueueObj->Queue_Rear) = 0;
            }
            else
            { /*Do Nothing*/
            }
            /*Enqueu value in rear position*/
            QueueObj->Queue_Array[QueueObj->Queue_Rear] = EnqueuValue;
            /*Check if this value is first value*/
            if (QueueObj->Queue_Rear == 0)
            {
                (QueueObj->Queue_Front) = 0;
                (QueueObj->Queue_ElementsCount) = 1;
            }
            else
            { /*Increment element counts*/
                (QueueObj->Queue_ElementsCount)++;
            }

            RetStatus = QUEUE_VAL_IS_ENQUEUE;
        }
    }
    return RetStatus;
}
void *Queue_Dequeue(Queue_t *QueueObj, QueueStatus_t *RetStatus)
{
    void *RetDequeuedVal = NULL;
    if ((NULL == QueueObj) || (NULL == RetStatus))
    { /*Validate arguments of function*/
        *RetStatus = QUEUE_NULL_POINTER;
    }
    else
    {
        if (Queue_IsEmpty(QueueObj))
        {
            *RetStatus = QUEUE_EMPTY;
        }
        else
        {
            /*Take copy from Dequeue val into front position*/
            RetDequeuedVal = QueueObj->Queue_Array[QueueObj->Queue_Front];
            /*Increment queue Front*/
            (QueueObj->Queue_Front)++;
            /*Check if Dequeu val after last element  <Crircular Condition>*/
            if ((QueueObj->Queue_Front) == (QueueObj->Queue_MaxSize))
            {
                (QueueObj->Queue_Front) = 0;
            }
            else
            { /*Do Nothing*/
            }
            /*Check if this Dequeu Last element*/
            if (QueueObj->Queue_ElementsCount == 1)
            {
                (QueueObj->Queue_Rear) = -1;
                (QueueObj->Queue_Front) = -1;
                (QueueObj->Queue_ElementsCount) = 0;
            }
            else
            { /*Increment element counts*/
                (QueueObj->Queue_ElementsCount)--;
            }

            *RetStatus = QUEUE_VAL_IS_DEQUEUE;
        }
        return RetDequeuedVal;
    }
}

void *Queue_Front(Queue_t *QueueObj, QueueStatus_t *RetStatus)
{
    void *RetFrontVal = NULL;
    if ((NULL == QueueObj) || (NULL == RetStatus))
    { /*Validate arguments of function*/
        *RetStatus = QUEUE_NULL_POINTER;
    }
    else
    {
        if (Queue_IsEmpty(QueueObj))
        {
            *RetStatus = QUEUE_EMPTY;
        }
        else
        {
            /*Take copy from Dequeue val into front position*/
            RetFrontVal = QueueObj->Queue_Array[QueueObj->Queue_Front];
            *RetStatus = QUEUE_FRONT_VALID;
        }
    }
    return RetFrontVal;
}
void *Queue_Rear(Queue_t *QueueObj, QueueStatus_t *RetStatus)
{
    void *RetRearVal = NULL;
    if ((NULL == QueueObj) || (NULL == RetStatus))
    { /*Validate arguments of function*/
        *RetStatus = QUEUE_NULL_POINTER;
    }
    else
    {
        if (Queue_IsEmpty(QueueObj))
        {
            *RetStatus = QUEUE_EMPTY;
        }
        else
        {
            /*Take copy from Dequeue val into front position*/
            RetRearVal = QueueObj->Queue_Array[QueueObj->Queue_Rear];
            *RetStatus = QUEUE_REAR_VALID;
        }
    }
    return RetRearVal;
}

void Queue_PrintStatus(QueueStatus_t Status)
{
    switch (Status)
    {
    case QUEUE_EMPTY:
        printf("Queue is EMPTY !! \n");
        break;
    case QUEUE_FULL:
        printf("Queue is FULL !! \n");
        break;
    case QUEUE_NOK:
        printf("Queue is NOT OK !! \n");
        break;
    case QUEUE_NULL_POINTER:
        printf("Queue is NULL POINTER !! \n");
        break;
    case QUEUE_OK:
        printf("Queue is OK :) \n");
        break;
    case QUEUE_CREATED:
        printf("############################################# \n");
        printf(" Queue is Created :) \n");
        printf("############################################# \n");
        break;
    case QUEUE_DESTROIED:
        printf("############################################# \n");
        printf(" Queue is Destroied :) \n");
        printf("############################################# \n");
        break;
    case QUEUE_VAL_IS_ENQUEUE:
        printf(" This value is enqueue to the stack  :) \n");
        break;
    case QUEUE_VAL_IS_DEQUEUE:
        printf(" This value is dequeue from the stack  :) \n");
        break;
    case QUEUE_FRONT_VALID:
        printf(" This value is front of the queue  :) \n");
        break;
    case QUEUE_REAR_VALID:
        printf(" This value is rear of the queue  :) \n");
        break;
    case QUEUE_COUNTED:
        printf(" Number of counts of the queue  :) \n");
        break;
    default:
        printf("Error Status !! \n");
        break;
    }
}
