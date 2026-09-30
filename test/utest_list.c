#include "cds/linkedlist.h"
#include "global.h"

#define CDS_UNIT_TEST

int main() {
  CDS_UTEST_SETUP

  /////// Testing Content ///////
  
  LinkedList *list = init_list(NULL, 1, NODE_SINGLE);
  assert(list != NULL);
  
  set_list(list, &test_value_1, 0); 
  ret = get_list(list, 0);
  printf("1st return case: %d\n", *(int*)ret);
  assert(*(int*)ret == 1);
  /////// End of Testing ///////
  
  printf("%ls\n", message);
}
