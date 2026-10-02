#include "cds/queue.h"
#include "global.h"

#define CDS_UNIT_TEST

int main() {
  CDS_UTEST_SETUP

  /////// Testing Content ///////

  Queue *nqueue = init_queue(NULL);
  assert(nqueue->size == 0);

  Queue *queue = init_queue(&test_value_1);
  assert(queue->size == 1);
  
  /////// End of Testing ///////
  
  printf("%ls\n", message);
}
