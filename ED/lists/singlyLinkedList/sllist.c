#include <stdio.h>
#include <stdlib.h> 
#include "sllist.h"

void sllist_init(sllist *list) {
  list->head = NULL;
}

int sllist_insert(sllist *list, int key) {
  node *value = malloc(sizeof(node));
  if (!value) return 0;
  value->key = key;
  value->next = list->head;
  list->head = value;
  return 1;
}

void sllist_erase(sllist *list, int key) {
  node *nod, *prevN;
  for (
    nod = list->head;
    (nod != NULL) && (nod->key != key);
    prevN = nod, nod = nod->next
  );
  if (!nod) return;
  if (nod == list->head) list->head = nod->next;
  else prevN->next = nod->next; 
  free(nod);
}

void sllist_free(sllist *list) {
  node *nod, *nextNod;
  for(nod = list->head; !nod->next; nod = nextNod) {
    nextNod = nod->next;
    free(nod);
  }
}

void sllist_print(sllist *list) {
  node* nod;
  for(nod = list->head; nod; nod = nod->next) {
    printf("%s%d", nod == list->head ? "" : " ", nod->key);
  }
  printf("\n");
}

