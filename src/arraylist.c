#include "cds/arraylist.h"
#include "cds/operator.h"

ArrayList *init_array(u32 capacity, u8 nbyte) {
  ArrayList *array = (ArrayList*)malloc(sizeof(ArrayList));
  CDS_ERROR(array == NULL, "failed to initialize ArrayList");
  
  array->capacity = capacity;
  array->size = 0;
  array->nbyte = nbyte;
  array->elements = malloc(nbyte*capacity); 

  DSConfig config = { 
    .access = &random_access_get, 
    .replace = &random_access_set,
    .rshift = &shift_right,
    .lshift = &shift_left
  };
  array->config = config;
  return array;
}

void *get_array(ArrayList *array, u32 index) {
  return array->config.access(array, index);
}

void set_array(ArrayList *array, void *value, u32 index) {
  if (array->size <= index && value != NULL) {
    array->size = index + 1;
  }
  array->config.replace(array, value, index);
}

void push_back_array(ArrayList *array, void *value) {
  set_array(array, value, array->size); 
}

void pop_back_array(ArrayList *array) {
  set_array(array, NULL, array->size - 1);
  array->size--;
}

void insert_array(ArrayList *array, void *value, u32 index) {
  if (array->size > index) {
    array->config.rshift(array, index, array->size);
    array->size++;
  }
  set_array(array, value, index);
}

void delete_array(ArrayList *array, u32 index) {
  if (array->size > index) {
    array->config.lshift(array, index, array->size);
  }
  set_array(array, NULL, array->size); 
  array->size--;
}
