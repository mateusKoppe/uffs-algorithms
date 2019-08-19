#include "./list.h"

void listsort_bubble_sort (list *l_list) {
  /* not done yeat */
  if (!l_list->head) return;
  list_node *i_node = list_get_last_node(l_list);
  while (i_node) {
    list_node *j_node = l_list->head;
    while (j_node && j_node != i_node) {
      if (j_node->value > j_node->next->value) {
        list_node *next_node = j_node->next;
        j_node->prev = next_node;
        next_node->prev = j_node->prev;
        j_node->next = next_node->next;
        next_node->next = j_node;
        j_node->prev = next_node;
      } else {
        j_node = j_node->next;
      }
      printf("yeap\n");
    }
    i_node = i_node->prev;
  } 
}

void listsort_insert_sort (list *l_list) {
  if (!l_list->head) return;
}