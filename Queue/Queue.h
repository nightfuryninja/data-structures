#include "LinkedList.h"

typedef LinkedList Queue;

Queue *queue_init(void);
void queue_enqueue(Queue *queue, void *data);
void *queue_dequeue(Queue *queue);
void queue_free(Queue *queue);