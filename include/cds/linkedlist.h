#ifndef CDS_LINKEDLIST_H
#define CDS_LINKEDLIST_H

#include "cds/struct.h"

/**
 Linked List contains the following exptected
 members:

 * value    - void pointer
 * next     - single or many Node options
 * prev     - previous node
 * count    - how many elements does next provide
 * config   - to handle callbacks against different 
              variety of function
 * type     - single, or double linked list, graph
*/

typedef DSNode LinkedList;

LinkedList *init_list(void *value, u32 count, NodeType type);

#define init_slist(value) init_list(value, 1, NODE_SINGLE) // singly linked list
#define init_dlist(value) init_list(value, 2, NODE_DOUBLE) // doubly linked list

void *get_list(LinkedList *list, u32 index);
void set_list(LinkedList *list, void *value, u32 index);

// adds a new node
void resize_list(LinkedList *list, u32 size);


#endif
