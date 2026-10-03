#include "cds/operator.h"

void *random_access_get(DSCollection *collection, u32 index) {
  return (char*)collection->elements + index * collection->nbyte;
}

void random_access_set(DSCollection *collection, void *value, u32 index) {
  void *dest = collection->config.access(collection, index);
  memcpy(dest, value, collection->nbyte);
}

void shift_right(DSCollection *collection, u32 start_index, u32 end_index) {
  for (u32 i = end_index; i >= start_index; i--) {
    void *src = collection->config.access(collection, i);
    void *dest = collection->config.access(collection, i+1);
    memcpy(dest, src, collection->nbyte);
  }
}

void shift_left(DSCollection *collection, u32 start_index, u32 end_index) {
  for (u32 i = start_index; i < end_index; i++) {
    void *src = collection->config.access(collection, i+1);
    void *dest = collection->config.access(collection, i);
    memcpy(dest, src, collection->nbyte);
  }
}
