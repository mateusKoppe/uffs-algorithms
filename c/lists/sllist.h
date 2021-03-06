#include "node.h"
#ifndef _SLLIST
#define _SLLIST

typedef struct {
  node *head;
} sllist;

void sllist_init (sllist *list);

int sllist_insert(sllist *list, int key);

void sllist_erase(sllist *list, int key);

void sllist_free(sllist *list);

void sllist_print(sllist *list);
#endif
