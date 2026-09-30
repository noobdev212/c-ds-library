#include "cds/arraylist.h"
#include "global.h"

#define CDS_UNIT_TEST

int main() {
  CDS_UTEST_SETUP

  /////// Testing Content ///////
  
  ArrayList *array = init_array(10, sizeof(int));
  assert(array != NULL);
  
  push_back_array(array, &test_value_1);
  ret = get_array(array, 0);
  printf("1st return case: %d\n", *(int*)ret);
  assert(*(int*)ret == 1);

  pop_back_array(array);
  ret = get_array(array, 0);
  printf("2nd return case: %d\n", *(int*)ret);
  assert(array->size == 0 AND *(int*)ret == 0);

  push_back_array(array, &test_value_1);
  ret = get_array(array, 0);
  insert_array(array, &test_value_2, 0);
  ret = get_array(array, 0);
  printf("3rd return case: %d\n", *(int*)ret);
  ret_1 = get_array(array, 1);
  printf("4th return case: %d\n", *(int*)ret_1);
  assert(*(int*)ret == 3 AND *(int*)ret_1 == 1 AND array->size == 2);

  delete_array(array, 0);
  ret = get_array(array, 0);
  printf("5th return case: %d\n", *(int*)ret);
  assert(*(int*)ret == 1 AND array->size == 1);

  free_array(array);
  assert(array == NULL);

  /////// End of Testing ///////
  
  printf("%ls\n", message);
}
