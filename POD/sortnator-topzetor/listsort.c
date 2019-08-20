#include <stdio.h>
#include "./list.h"

void listsort_swap_next_node (list *l_list, list_node *n) {
  list_node *next_node = n->next;
  next_node->prev = n->prev;
  n->prev = next_node;
  n->next = next_node->next;
  if (next_node->next) {
    next_node->next->prev = n;
  }
  next_node->next = n;
  if (next_node->prev) {
    next_node->prev->next = next_node;
  }
  if (n == l_list->head) {
    l_list->head = n->prev;
  }
}

/* WARNING: NOT TESTED FUNCTION */
void listsort_swap (list *l_list, list_node *n1, list_node *n2) {
  list_node *temp_prev = n1->prev, *temp_next = n1->next;
  
  if (l_list->head == n1) {
    l_list->head = n2;
  }
  if (l_list->head == n2) {
    l_list->head = n1;
  }

  if (n1->prev) {
    n1->prev->next = n2;
  }
  if (n1->next) {
    n1->next->prev = n2;
  }
  if (n2->next) {
    n2->next->prev = n1;
  }
  if (n2->prev) {
    n2->prev->next = n1;
  }

  n1->prev = n2->prev;
  n1->next = n2->next;
  n2->prev = temp_prev;
  n2->next = temp_next;
}

void listsort_bubble_sort (list *l_list) {
  if (!l_list->head) return;
  list_node *i_node = l_list->head;
  int swapped = 0;
  int loop_count = 0;

  do {
    swapped = 0;

    i_node = list_get_last_node(l_list);
    for (int i = 0; i_node && i < loop_count; i++) {
      i_node = i_node->prev;
    }

    list_node *j_node = l_list->head;
    while (j_node && j_node != i_node) {
      if (!j_node->next) break;
      if (j_node->value > j_node->next->value) {
        swapped = 1;
        listsort_swap_next_node(l_list, j_node);
      } else {
        j_node = j_node->next;
      }
    }
    
    loop_count++;
  } while (swapped && loop_count < l_list->size);
}

void listsort_insert_sort (list *l_list) {
  if (!l_list->head) return;
}