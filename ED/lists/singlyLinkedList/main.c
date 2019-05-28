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
  while (scanf(" %c", &option) != EOF) {
    switch(option) {
      case 'i':
        scanf(" %d", &i);
        sllist_insert(&list, i);
        break;
      case 'e':
        scanf(" %d", &i);
        sllist_erase(&list, i);
        break;
      case 'p':
        sllist_print(&list);
        break;
      case 'u':
        scanf(" %d", &i);
        stack_push(&s, i);
        break;
      case 'o':
        i = stack_pop(&s);
        printf("Item deleted: %d\n", i);
        break;
    }
  }
  sllist_free(&list);
  stack_free(&s);
  return 0;
}
