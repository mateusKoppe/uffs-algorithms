#include <stdio.h>
#include "sllist.h"
#include "stack.h"

int main(void) {
  char option;
  int i;
  sllist list;
  sllist_init(&list);
  stack s;
  stack_init(&s);
  printf("[i] List Insert\n");
  printf("[e] List Erase\n");
  printf("[p] List Print\n");
  printf("[u] Stack pUsh\n");
  printf("[o] Stack pOp\n");
  while (scanf(" %c", &option) != EOF) {
    switch(option) {
      case 'i':
        scanf(" %d", &i);
        sllist_insert(&list, i);
        printf("Item added in list: %d\n", i);
        break;
      case 'e':
        scanf(" %d", &i);
        sllist_erase(&list, i);
        printf("Item erased in list: %d\n", i);
        break;
      case 'p':
        sllist_print(&list);
        break;
      case 'u':
        scanf(" %d", &i);
        stack_push(&s, i);
        printf("Item added in stack: %d\n", i);
        break;
      case 'o':
        i = stack_pop(&s);
        printf("Item deleted in stack: %d\n", i);
        break;
    }
  }
  sllist_free(&list);
  stack_free(&s);
  return 0;
}
