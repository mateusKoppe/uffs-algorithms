#include <stdlib.h>
#include <stdio.h>
#include "./list.h"

void list_construct (list *l_list) {
  l_list->size = 0;
  l_list->head = NULL;
}

list_node* list_get_node (list *l_list, int value) {
  if (!l_list->head) return NULL;
  list_node *fetch = l_list->head;
  while (fetch) {
    if (fetch->value == value) {
      return fetch;
    }
    fetch = fetch->next;
  }
  return fetch;
}

list_node* list_get_last_node (list *l_list) {
  if (!l_list->head) return NULL;
  list_node *fetch = l_list->head;
  while(fetch->next) {
    fetch = fetch->next;
  }
  return fetch;
}

list_node* list_insert (list *l_list, int value) {
  list_node *new_node = malloc(sizeof(list_node));
  new_node->value = value;
  
  if (l_list->head) {
    list_node *last_node = list_get_last_node(l_list);
    last_node->next = new_node;
    new_node->prev = last_node;
  } else {
    l_list->head = new_node;
  }
  l_list->size++;
  return new_node;
}

void list_print (list *l_list) {
  if (!l_list->head) {
    printf("The list is empty.\n");
    return;
  }

  printf("List:\n");
  list_node *fetch = l_list->head;
  while (fetch) {
    printf("- %d\n", fetch->value);
    fetch = fetch->next;
  }
}

void list_remove (list *l_list, int value) {
  list_node *node = list_get_node(l_list, value);
  if (!node) return;
  if (node->prev) {
    node->prev->next = node->next;
  }
  if (node->next) {
    node->next->prev = node->prev;
  }
  l_list->size--;
  free(node);
}

void list_free (list *l_list) {
  if (!l_list->head) return;
  list_node *fetch_node = l_list->head;
  list_node *next_node = fetch_node->next;
  while (fetch_node) {
    next_node = fetch_node->next;
    free(fetch_node);
    fetch_node = next_node;
  }
}