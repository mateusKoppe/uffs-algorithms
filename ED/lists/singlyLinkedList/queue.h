#include "node.h"
#ifndef _QUEUE
#define _QUEUE

typedef struct {
  node *start, *end;
} queue;

void queue_init (queue *q);
int queue_enqueue(queue *q, int key);
void queue_dequeue(queue *q);
void queue_free(queue *q);

#endif
