#include "cds/string.h"
#include "global.h"

#define CDS_UNIT_TEST

int main() {
  CDS_UTEST_SETUP

  /////// Testing Content ///////
  
  String *str = init_string("tes,t,", 6);
  printf("1st string case: %s\n", str->chs);
  assert(str->chs == "test");

  resize_string(str, str->size + 4);
  assert(str->size == str->size + 4);

  String *str2 = init_string("test", 4);
  concat_string(str, str2);
  printf("2nd string case: %s\n", str->chs);
  assert(str->chs == "testtest");
  
  iret = cmp_string(str, str2);
  printf("3rd string case: %d\n", iret);
  assert(iret > 0);

  String *delim = init_string(",", 1);
  char **split = split_string(str, delim);
  printf("4th string case: %s\n", split[1]);

  free_string(str);
  assert(str == NULL);

  /////// End of Testing ///////
  
  printf("%ls\n", message);
}
