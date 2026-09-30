#ifndef CDS_STRUCT_H
#define CDS_STRUCT_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;


#define CDS_ERROR(condition, desc) \
  if (condition) { \
    fprintf(stderr, "CDS Error: %s (Code %d): %s", desc, errno, strerror(errno)); \
  }

#define CDS_ERROR_R(condition, desc) \
  if (condition) { \
    fprintf(stderr, "CDS Error: %s (Code %d): %s", desc, errno, strerror(errno)); \
    return NULL; \
  }
  
typedef struct {
  // the first paramter is a placeholder for
  // DSCollection or any alternatives to that
  void (*replace)(void*, void*, u32);
  void *(*access)(void*, u32);
  void (*rshift)(void*, u32, u32);
  void (*lshift)(void*, u32, u32);
} DSConfig;

/**
 * elements - an array of values
 * size     - current occupied space
 * capacity - current max space
 * nbyte    - byte count of a single value
 * config   - handle callbacks from a different 
 *            variety of function
*/
typedef struct {
  void *elements;
  u32    size;
  u32    capacity;
  u8     nbyte;
  DSConfig config;
} DSCollection;

// free structure for collection
#define free_cstruct(collection) \
  free(collection->elements); \
  free(collection); \
  collection = NULL;

#endif
