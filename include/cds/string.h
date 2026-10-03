#ifndef CDS_STRING_H
#define CDS_STRING_H

#include "struct.h"

typedef struct {
  char *chs;
  u32  size; 
  DSConfig config;
} String;

String  *init_string(char *string, u32 size);
#define free_string(string) \
  free(string->chs); \
  free(string); \
  string = NULL;

void    resize_string(String *string, u32 size);
#define concat_string(dest, src) \
  resize_string(dest, dest->size + src->size - 1); \
  strcat(dest->chs, src->chs);

#define cmp_string(lstr, rstr) strcmp(lstr->chs, rstr->chs)
char **split_string(String *str, String *delim);

#endif
