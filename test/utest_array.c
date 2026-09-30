#include "cds/arraylist.h"
#include <stdio.h>
#include <assert.h>
#include <locale.h>

#define AND &&
#define OR ||

int main() {
#ifdef NDEBUG
  // notify assert is toggled off
  printf("ArrayList: NDEBUG is currently undefined\n");
  #undef NDEBUG
#endif

  setlocale(LC_ALL, "");
  wchar_t message[] = L"ArrayList: Successful Test Case \u263A";
  int test_value_1 = 1;
  int test_value_2 = 3;
  void *ret, *ret_1; // to be used for return values

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
  assert(*(int*)ret == 3 AND *(int*)ret_1 == 1);

  free_array(array);
  assert(array == NULL);

  /////// End of Testing ///////
  
  printf("%ls\n", message);
}
