#include "cds/string.h"

String *init_string(char *string, u32 size) {
  String *str = (String*)malloc(sizeof(String));
  CDS_ERROR_R(str == NULL, "failed to initialize String") 

  str->size = size+1;
  str->chs = (char*)malloc(str->size*sizeof(char));
  CDS_ERROR_R(str->chs == NULL, "failed to initialize chs")

  strcpy(str->chs, string);
  return str;
}

void resize_string(String *string, u32 size) {
  string->chs = realloc(string->chs, size * sizeof(char));
  CDS_ERROR(string->chs == NULL, "failed to resize chs");
}
