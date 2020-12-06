#include <stdlib.h>
#include <stdio.h>
#include "./dedqueue.h"

void dedqueue_init (dedqueue *queue) {
  queue->head = NULL;
  queue->tail = NULL;
}

int dedqueue_insert_first(dedqueue *queue, int value) {
  node* new_node = (node*) malloc(sizeof(node));
  new_node->value = value;

  if (queue->head == NULL && queue->tail == NULL) {
    queue->head = new_node;
    queue->tail = new_node;
    return 1;
  }

  node* prev_head = queue->head;
  new_node->next = prev_head;
  prev_head->prev = new_node;
  queue->head = new_node;
  return 1;
}

int dedqueue_insert_last(dedqueue *queue, int value) {
  node* new_node = (node*) malloc(sizeof(node));
  new_node->value = value;

  if (queue->head == NULL && queue->tail == NULL) {
    queue->head = new_node;
    queue->tail = new_node;
    return 1;
  }

  node* prev_tail = queue->tail;
  new_node->prev = prev_tail;
  prev_tail->next = new_node;
  queue->tail = new_node;
  return 1;
}

void dedqueue_delete_first(dedqueue *queue) {
  if (queue->head == NULL && queue->tail == NULL) return;

  if (queue->tail == queue->head) {
    free(queue->head);
    queue->tail = NULL;
    queue->head = NULL;
    return;
  }


  node* node_removing = queue->head;
  queue->head = node_removing->next;
  queue->head->prev = NULL;

  free(node_removing);
}

void dedqueue_delete_last(dedqueue *queue) {
  if (queue->head == NULL && queue->tail == NULL) return;

  if (queue->tail == queue->head) {
    free(queue->head);
    queue->tail = NULL;
    queue->head = NULL;
    return;
  }


  node* node_removing = queue->tail;
  queue->tail = node_removing->prev;
  queue->tail->next = NULL;

  free(node_removing);
}

void dedqueue_free(dedqueue *queue) {
  node* actual_node = queue->head;
  while (actual_node != NULL) {
    node* next_node = actual_node->next;
    free(actual_node);
    actual_node = next_node;
  }
  queue->head = NULL;
  queue->tail = NULL;
}

int dedqueue_length(dedqueue *queue) {
  int length = 0;
  node* actual_node = queue->head;
  while (actual_node != NULL) {
    length++;
    actual_node = actual_node->next;
  }
  return length;
}

void dedqueue_print(dedqueue *queue) {
  node* actual_node = queue->head;
  while (actual_node != NULL) {
    printf("%d\n", actual_node->value);
    actual_node = actual_node->next;
  }
}