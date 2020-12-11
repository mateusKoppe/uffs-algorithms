#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void queue_init (queue *q){
  q->start = NULL;
  q->end = NULL;
}

void queue_enqueue(queue *q, int key){
  node *actual_node = malloc(sizeof(node));
  actual_node->next = q->start;
  q->start = actual_node;
  if (!q->end) q->end = actual_node;
}
