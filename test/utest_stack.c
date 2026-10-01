#include "cds/stack.h"
#include "global.h"

#define CDS_UNIT_TEST

int main() {
  CDS_UTEST_SETUP

  /////// Testing Content ///////

  Stack *nstack = init_stack(NULL);
  assert(nstack->size == 0);

  Stack *stack = init_stack(&test_value_1);
  assert(nstack->size == 1);

  /////// End of Testing ///////
  
  printf("%ls\n", message);

}
