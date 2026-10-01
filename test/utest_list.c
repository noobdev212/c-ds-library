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

  resize_list(list, 2);
  count = list->config.count(list);
  printf("2nd return case: %u\n", count);
  assert(count == 3);

  delete_list(list, 1, 2);
  count = list->config.count(list);
  printf("3rd return case: %u\n", count);
  assert(count == 1);

  push_back_list(list, &test_value_2);
  ret = get_list(list, count-1);
  printf("4th return case: %d\n", *(int*)ret);
  assert(*(int*)ret == 3 AND count == 1);

  pop_back_list(list);
  count = list->config.count(list);
  ret = get_list(list, 0);
  printf("5th return case: %u\n", count);
  assert(ret == NULL AND count == 1);

  LinkedList *node_dummy = init_list(&test_value_2, 1, NODE_SINGLE);
  list = insert_list(node_dummy, list, 0);
  count = list->config.count(list);
  ret = get_list(list, 0);
  printf("6th return case: %u\n", count);
  assert(*(int*)ret == 3 AND count == 2);

  LinkedList *node_dummy_2 = init_list(&test_value_1, 1, NODE_SINGLE);
  list = insert_list(node_dummy_2, list, 1);
  count = list->config.count(list);
  ret = get_list(list, 2);
  ret_1 = get_list(list, 0);
  printf("7th return case: %u\n", count);
  assert(*(int*)ret == 1 AND *(int*)ret_1 == 3 AND count == 3);

  

  free_list(list);
  assert(list == NULL);
  /////// End of Testing ///////
  
  printf("%ls\n", message);
}
