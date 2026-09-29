#include "cds/arraylist.h"
#include "cds/operator.h"

ArrayList *init_array(u32 capacity, u8 nbyte) {
  ArrayList *array = (ArrayList*)malloc(sizeof(ArrayList));
  CDS_ERROR(array == NULL, "failed to initialize ArrayList");
  
  array->capacity = capacity;
  array->size = 0;
  array->nbyte = nbyte;
  array->elements = (void*)malloc(nbyte*capacity); 

  DSConfig config = { .access = &random_access };
  array->config = config;
  return array;
}

void free_array(ArrayList *array) {
  free(array->elements);
  free(array);
  array = NULL;
}

void *get_array(ArrayList *array, u32 index) {
  return array->config.access(array, index);
}
