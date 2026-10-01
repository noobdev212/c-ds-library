#include "cds/linkedlist.h"
#include "cds/operator.h"

LinkedList *init_list(void *value, u32 count, NodeType type) {
  LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
  CDS_ERROR_R(list == NULL, "failed to initialize LinkedList");

  DSConfig config;  
  switch(type) {
    case NODE_SINGLE:
      config = (DSConfig){
        .access = &sequence_access_get,
        .replace = &sequence_access_set,
        .back = &sequence_tail_get,
        .count = &sequence_count,
        .traverse = &sequence_traverse
      };
      break;
    case NODE_DOUBLE:
      config = (DSConfig){
        .access = &sequence_access_get,
        .replace = &sequence_access_set,
        .back = &sequence_tail_get,
        .count = &sequence_count,
        .traverse = &sequence_traverse
      };
      break;
    default:
      fprintf(stderr, "CDS Error: node type is not valid\n");
      free(list);
      return NULL;
  }

  list->value = value;
  list->config = config;
  list->count = count;
  list->type = type;
  return list;
}

void *get_list(LinkedList *list, u32 index) {
  return list->config.access(list, index);
}

void set_list(LinkedList *list, void *value, u32 index) {
  list->config.replace(list, value, index);
}

void resize_list(LinkedList *list, u32 size) {
  LinkedList *tail = (LinkedList*)list->config.back(list); 

  for (u32 i = 0; i < size; i++) {
    tail->next = init_list(NULL, list->count, list->type); 
    tail = tail->next;
  }
}

void delete_list(LinkedList *list, u32 index, u32 size) {
  LinkedList *curr; 
  LinkedList *prev;

  if (index > 0) {
    curr = list->config.traverse(list, index-1);
    prev = curr;
    curr = (LinkedList*)curr->next;
    prev->next = NULL;
  }
  else {
    curr = list;
  }

  for (u32 i = 0; curr != NULL && i < size; i++) {
    prev = curr;
    curr = (LinkedList*)curr->next;
    free(prev);
    prev = NULL;
  }
}


