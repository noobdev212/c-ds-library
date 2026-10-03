#include "cds/stack.h"
#include "global.h"

#define CDS_UNIT_TEST

int main() {
  CDS_UTEST_SETUP

  /////// Testing Content ///////

  Stack *nstack = init_stack(NULL);
  assert(nstack->size == 0);

  Stack *stack = init_stack(&test_value_1);
  assert(stack->size == 1);

  int dummy = peek_stack(stack, int);
  assert(dummy == 1);

  push_stack(stack, &test_value_2);
  printf("1st return case: %d\n", *(int*)stack->top->value);
  assert(*(int*)stack->top->value == 3 AND stack->size == 2);

  void *value = pop_stack(stack);
  printf("2nd return case: %d\n", *(int*)value);
  assert(*(int*)value == 3 AND stack->size == 1); 

  free_stack(stack);
  assert(stack == NULL);

  /////// End of Testing ///////
  
  printf("%ls\n", message);

}
