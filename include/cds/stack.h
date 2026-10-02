#ifndef CDS_STACK_H
#define CDS_STACK_H

// Stack is going to be very similar to single LinkedList
// with small modification akin to DSCollection

#include "cds/linkedlist.h"

typedef struct {
  LinkedList *top;
  u32 size;
} Stack;

Stack *init_stack(void *value);
#define free_stack(stack) \
  free_list(stack->top) \
  free(stack); \
  stack = null;

void  push_stack(Stack *stack, void *value); // creates new node
void  *pop_stack(Stack *stack);

#define peek_stack(stack, type) *(type*)stack->top->value

#endif
