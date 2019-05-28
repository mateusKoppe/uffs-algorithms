#include "node.h"
#ifndef  _STACK
#define _STACK

typedef struct {
  node *top;
} stack;

void stack_init(stack *list);
int stack_push(stack *list, int key);
int stack_pop(stack *list);
void stack_print(stack *list);
void stack_free(stack *list);

#endif
