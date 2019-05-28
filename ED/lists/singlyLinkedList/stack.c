#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stack_init(stack *s){
  s->top = NULL;
}

int stack_push(stack *s, int key){
  node *p = malloc(sizeof(node));
  if(!p) return 0;
  p->key = key;
  p->next = s->top;
  s->top = p;
  return 1;
}

int stack_pop(stack *s){
  int key;
  node *p = s->top;
  if (!p) return -1;
  key = p->key;
  s->top = p->next;
  free(p);
  return key;
}

void stack_free(stack *s){
  while (s->top != NULL) stack_pop(s);
}
