#ifndef CDS_STACK_H
#define CDS_STACK_H

// Stack is going to be very similar to single LinkedList
// with small modification akin to DSCollection

#include "cds/linkedlist.h"

typedef struct {
  LinkedList *top;
  u32 size;
} stack;

stack *init_stack(void *value);
#define free_stack(stack) \
  free_list(stack->top) \
  free(stack); \
  stack = null;

void  push_stack(stack *stack, void *value); // creates new node
void  *pop_stack(stack *stack);

#define peek_stack(stack, type) *(type*)stack->top->value

#endif
