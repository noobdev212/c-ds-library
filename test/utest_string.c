#include "cds/string.h"
#include "global.h"

#define CDS_UNIT_TEST

int main() {
  CDS_UTEST_SETUP

  /////// Testing Content ///////
  
  String *str = init_string("test", 4);
  printf("1st string case: %s\n", str->chs);
  assert(str->chs == "test");

  resize_string(str, str->size + 4);
  assert(str->size == str->size + 4);

  free_string(str);
  assert(str == NULL);

  /////// End of Testing ///////
  
  printf("%ls\n", message);
}
