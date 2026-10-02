#ifndef CDS_QUEUE_H
#define CDS_QUEUE_H 

// Queue is going to be very similar to single LinkedList
// with small modification akin to DSCollection. Same situation
// with Deque with double LinkedList

#include "cds/linkedlist.h"

typedef struct {
  LinkedList *front;
  LinkedList *back;
  u32 size;
} Queue;

Queue *init_queue(void *value);

#endif
