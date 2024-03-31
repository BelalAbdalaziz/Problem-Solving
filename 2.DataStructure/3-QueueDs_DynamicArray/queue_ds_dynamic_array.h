#ifndef _QUEUE_DS_DYNAMIC_ARRAY_H
#define _QUEUE_DS_DYNAMIC_ARRAY_H

#include "std_types.h"

typedef struct
{
    void **Queue_Array;
    uint32_t Queue_ElementsCount;
    uint32_t Queue_MaxSize;
    sint32_t Queue_Front;
    sint32_t Queue_Rear;
} Queue_t;

typedef enum
{
    QUEUE_NOK,
    QUEUE_OK,
    QUEUE_NULL_POINTER,
    QUEUE_EMPTY,
    QUEUE_FULL,
    QUEUE_CREATED,
    QUEUE_DESTROIED,
    QUEUE_VAL_IS_ENQUEUE,
    QUEUE_VAL_IS_DEQUEUE,
    QUEUE_FRONT_VALID,
    QUEUE_REAR_VALID,
    QUEUE_COUNTED,
} QueueStatus_t;

/*
 * @brief  : Creat the queue object and queue array
 * @param  : QueueMaxSize  Wanted Size of the queue array
 * @param  : RetStatus  Pointer to return status of the queue by ref
 * @retval : Return Address of the new queue object is created
 */
Queue_t *Queue_Creat(uint32_t QueueMaxSize, QueueStatus_t *RetStatus);
/*
 * @brief  : Destroy the queue object and queue array
 * @param  : QueueObj  pointer to queue
 * @param  : RetStatus  Pointer to return status of the queue by ref
 * @retval : Return Address of the  queue object is destroyed   < if destroied return NULL >
 */
Queue_t *Queue_Destroy(Queue_t *QueueObj, QueueStatus_t *RetStatus);
/*
 * @brief  : Enqueue value to the queue Array
 * @param  : QueueObj  Pointer to the queue
 * @param  : EnqueuValue  Void pointer to enqueue any type of values to the queue
 * @retval : Return status of the queue
 */

QueueStatus_t Queue_Enqueue(Queue_t *QueueObj, void *EnqueuValue);
/*
 * @brief  : Dequeue value from the queue
 * @param  : QueueObj  Pointer to the queue
 * @param  : RetStatus  Pointer to return status of the queue by ref
 * @retval : Void pointer to dequeue any type of values from the queue
 */
void *Queue_Dequeue(Queue_t *QueueObj, QueueStatus_t *RetStatus);
/*
 * @brief  : Front value of the queue
 * @param  : QueueObj  Pointer to the queue
 * @param  : RetStatus  Pointer to return status of the queue by ref
 * @retval : Void pointer to front value of the queue
 */
void *Queue_Front(Queue_t *QueueObj, QueueStatus_t *RetStatus);
/*
 * @brief  : Rear value of the queue
 * @param  : QueueObj  Pointer to the queue
 * @param  : RetStatus  Pointer to return status of the queue by ref
 * @retval : Void pointer to front value of the queue
 */
void *Queue_Rear(Queue_t *QueueObj, QueueStatus_t *RetStatus);
/*
 * @brief  : Print status of the queue
 * @param  : Status of the queue
 * @retval : Void
 */
void Queue_PrintStatus(QueueStatus_t Status);

#endif /* _QUEUE_DS_DYNAMIC_ARRAY_H*/