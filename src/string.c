#include "cds/string.h"
#include "cds/operator.h"

String *init_string(char *string, u32 size) {
  String *str = (String*)malloc(sizeof(String));
  CDS_ERROR_R(str == NULL, "failed to initialize String") 

  str->size = size+1;
  str->chs = (char*)malloc(str->size*sizeof(char));
  CDS_ERROR_R(str->chs == NULL, "failed to initialize chs")

  strcpy(str->chs, string);

  DSConfig config = { 
    .search = &string_search_char,
    .ccount = &string_count_char
  };
  str->config = config;
  return str;
}

void resize_string(String *string, u32 size) {
  string->chs = realloc(string->chs, size * sizeof(char));
  CDS_ERROR(string->chs == NULL, "failed to resize chs");
}

char **split_string(String *str, String *delim) {
  u32 count = str->config.ccount(str, delim);
  char *strdp = strdup(str->chs);
  
  char **split = (char**)malloc((count+1)*sizeof(char*));
  u32 index = 0;

  char *saveptr;
  char *token = strtok_r(strdp, delim->chs, &saveptr);

  while (token != NULL) {
    split[index++] = token;
    token = strtok_r(NULL, delim->chs, &saveptr);
  }

  return split;
}
