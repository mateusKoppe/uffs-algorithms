#ifndef _DEDQUEUE
#define _DEDQUEUE

typedef struct _node {
  int value;
  struct _node *next;
  struct _node *prev;
} node;

typedef struct {
  node *head;
  node *tail;
} dedqueue;

void dedqueue_init (dedqueue *queue);

int dedqueue_insert_first(dedqueue *queue, int value);

int dedqueue_insert_last(dedqueue *queue, int value);

void dedqueue_delete_first(dedqueue *queue);

void dedqueue_delete_last(dedqueue *queue);

void dedqueue_free(dedqueue *queue);

int dedqueue_length(dedqueue *queue);

void dedqueue_print(dedqueue *queue);
#endif