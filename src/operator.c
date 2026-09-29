#include "cds/operator.h"

void *random_access(DSCollection *collection, u32 index) {
  return (void*)((char*)collection->elements + index * collection->nbyte);
}
