#include <stdio.h>
#include "sllist.h"

int main(void) {
  char option;
  int i;
  sllist list;
  sllist_init(&list);
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
    }
  }
  sllist_free(&list);
  return 0;
}
