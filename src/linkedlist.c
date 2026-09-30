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
        .replace = &sequence_access_set
      };
      break;
    case NODE_DOUBLE:
      config = (DSConfig){
        .access = &sequence_access_get,
        .replace = &sequence_access_set
      };
      break;
    case NODE_GRAPH:
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
