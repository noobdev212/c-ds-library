#include "cds/string.h"
#include "global.h"

#define CDS_UNIT_TEST

int main() {
  CDS_UTEST_SETUP

  /////// Testing Content ///////
  
  String *str = init_string("test", 5);
  printf("1st string case: %s\n", str->chs);
  assert(str->chs == "test");

  /////// End of Testing ///////
  
  printf("%ls\n", message);
}
