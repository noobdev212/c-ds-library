#include "cds/stack.h"

Stack *init_stack(void *value) {
  Stack *stack = (Stack*)malloc(sizeof(Stack));
  if (value != NULL) {
    stack->top = init_slist(value);
    stack->size = 1;
  }
  else {
    stack->top = NULL;
    stack->size = 0;
  }

  return stack;
}

void push_stack(Stack *stack, void *value) {
  LinkedList *node = init_slist(value);
  LinkedList *curr = stack->top;
  node->next = curr;
  stack->top = node;
}
