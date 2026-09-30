#ifndef CDS_ARRAYLIST_H
#define CDS_ARRAYLIST_H

#include "cds/struct.h"

/**
 ArrayList contains the following exptected
 members:

 * elements - an array of values
 * size     - current occupied space
 * capacity - current max space
 * nbyte    - byte count of a single value
 * config   - to handle callbacks against different 
              variety of function
*/

typedef DSCollection ArrayList;

// function defined below will
// serve as possible interface for config
// (i.e. sorting, searching, ...)
ArrayList *init_array(u32 capacity, u8 nbyte);
#define free_array(array) free_cstruct(array)

void *get_array(ArrayList *array, u32 index);
void set_array(ArrayList *array, void *value, u32 index);

void push_back_array(ArrayList *array, void *value);
void pop_back_array(ArrayList *array);

void insert_array(ArrayList *array, void *value, u32 index);
void delete_array(ArrayList *array, u32 index);

#endif
