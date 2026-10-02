#include "cds/queue.h"

Queue *init_queue(void *value) {
  Queue *queue = (Queue*)malloc(sizeof(Queue));
  if (value != NULL) {
    queue->front = init_slist(value);
    queue->back = queue->front;
    queue->size = 1;
  }
  else {
    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0;
  }

  return queue;
}
