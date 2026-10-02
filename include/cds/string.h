#ifndef CDS_STRING_H
#define CDS_STRING_H

#include "struct.h"

typedef struct {
  char *chs;
  u32  size; 
} String;

String *init_string(char *string, u32 size);

#endif
