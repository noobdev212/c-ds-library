#include "cds/queue.h"

Queue *init_queue(void *value) {
  Queue *queue = (Queue*)malloc(sizeof(Queue));
  if (value != NULL) {
    queue->front = init_dlist(value);
    queue->back = queue->front;
    queue->back->next = NULL;
    queue->back->prev = NULL;
    queue->size = 1;
  }
  else {
    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0;
  }

  return queue;
}

void push_back_queue(Queue *queue, void *value) {
  LinkedList *node = init_dlist(value);
  node->next = queue->back;
  queue->back->prev = node;
  node->prev = NULL;
  queue->back = node;
  queue->size++;
}
