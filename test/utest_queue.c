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

  push_back_queue(queue, &test_value_2);
  printf("1st return case: %d\n", *(int*)queue->back->value);
  printf("2nd return case: %d\n", *(int*)queue->front->value);
  assert(queue->size == 2 
      AND *(int*)queue->back == 3 
      AND *(int*)queue->front->value == 1);

  ret = pop_front_queue(queue);
  printf("3rd return case: %d\n", *(int*)ret);
  assert(*(int*)ret == 1);

  iret = front_queue(queue, int); 
  printf("4th return case: %d\n", iret);
  assert(iret == 3);

  iret = back_queue(queue, int); 
  printf("5th return case: %d\n", iret);
  assert(iret == 3);

  assert(is_empty_queue(queue) == false);
  
  free_queue(queue);
  assert(queue == NULL);

  /////// End of Testing ///////
  
  printf("%ls\n", message);
}
