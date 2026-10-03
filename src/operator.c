#include "cds/operator.h"
#include "cds/string.h"

void *random_access_get(void *collection, u32 index) {
  DSCollection *container = (DSCollection*)collection;
  return (char*)container->elements + index * container->nbyte;
}

void random_access_set(void *collection, void *value, u32 index) {
  DSCollection *container = (DSCollection*)collection;
  void *dest = container->config.access(collection, index);
  if (value == NULL) {
    memset(dest, 0, container->nbyte);
  }
  else {
    memcpy(dest, value, container->nbyte);
  }
}

void shift_right(void *collection, u32 start_index, u32 end_index) {
  DSCollection *container = (DSCollection*)collection;
  // made dumb mistake with using u32 :D
  for (int i = (int)end_index; i >= (int)start_index; i--) {
    void *src = container->config.access(collection, (u32)i);
    void *dest = container->config.access(collection, (u32)i+1);
    memcpy(dest, src, container->nbyte);
  }
}

void shift_left(void *collection, u32 start_index, u32 end_index) {
  DSCollection *container = (DSCollection*)collection;
  for (u32 i = start_index; i < end_index; i++) {
    void *src = container->config.access(collection, i+1);
    void *dest = container->config.access(collection, i);
    memcpy(dest, src, container->nbyte);
  }
}

void *sequence_access_get(void *node, u32 index) {
  DSNode *curr = (DSNode*)node;

  while(curr != NULL && index > 0) {
    curr = (DSNode*)curr->next;
    index--;
  }

  return curr ? curr->value : NULL;
}

void sequence_access_set(void *node, void *value, u32 index) {
  DSNode *curr = (DSNode*)node;

  while(curr != NULL && index > 0) {
    curr = (DSNode*)curr->next;
    index--;
  }

  if (curr != NULL) {
    curr->value = value;
  }
}

void *sequence_tail_get(void *node) {
  DSNode *prev = NULL;
  DSNode *curr = (DSNode*)node;

  while (curr != NULL) {
    prev = curr;
    curr = (DSNode*)curr->next;
  }

  return prev;
}

u32 sequence_count(void *node) {
  DSNode *curr = (DSNode*)node;

  u32 count = 0;
  while (curr != NULL) {
    curr = (DSNode*)curr->next;
    count++;
  }

  return count;
}

void *sequence_traverse(void *node, u32 index) {
  DSNode *curr = (DSNode*)node;

  while(curr != NULL && index-- > 0) {
    curr = (DSNode*)curr->next;
  }
  return curr;
}

void *double_head_get(void *node) {
  DSNode *curr = (DSNode*)node;
  DSNode *prev = NULL;
 
  while (curr != NULL) {
    prev = curr;
    curr = (DSNode*)curr->prev;
  }

  return prev;
}

i64 string_search_char(void* string, void* ch, u32 index, u32 count) {
  String *str = (String*)string;
  char c = *(char*)ch;

  i64 ind = -1;
  for (u32 i = index; i < str->size; i++) {
    if (count <= 0) {
      ind = i;
      break;
    }
    else if (str->chs[i] == c){
      count--;
    }
  }

  return ind;
}

u32 string_count_char(void *string, void *delimeter) {
  char *str = strdup(((String*)string)->chs);
  char *delim = ((String*)delimeter)->chs;

  u32 count = 0;
  char *saveptr;
  char *token = strtok_r(str, delim, &saveptr);

  while (token != NULL) {
    count++;
    token = strtok_r(NULL, delim, &saveptr);
  }

  free(str);

  return count;
}
