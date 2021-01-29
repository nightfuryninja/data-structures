#include "Queue.h"
#include <stdio.h>

Queue *queue_init(void)
{
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL)
    {
        fprintf(stderr, "Cannot allocate memory for queue.\n");
    }
    return queue;
}

void *queue_peek(Queue *queue)
{
    void *data;
    if (queue == NULL)
    {
        fprintf(stderr, "Cannot enqueue null queue.\n");
        return NULL;
    }

    if (queue->head == NULL)
    {
        fprintf(stderr, "Cannot peek empty queue.\n");
        return NULL;
    }
    
    return queue -> head -> data;
}

void queue_enqueue(Queue *queue, void *data)
{
    if (queue == NULL)
    {
        fprintf(stderr, "Cannot enqueue null queue.\n");
        return;
    }

    linked_list_append(queue, data);
}

void *queue_dequeue(Queue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "Cannot dequeue null queue.\n");
        return NULL;
    }

    if (queue->head == NULL)
    {
        fprintf(stderr, "Cannot dequeue empty queue.\n");
        return NULL;
    }

    return linked_list_remove_head(queue);
}

void queue_free(Queue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "Cannot free null queue.\n");
        return;
    }
    linked_list_free_list(queue);
}