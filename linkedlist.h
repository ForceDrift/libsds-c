
#ifndef __LIBDSC_LINKEDLIST_H__
#define __LIBDSC_LINKEDLIST_H__
#include <stdint.h>

typedef struct node_header {
  int32_t data;
  struct node_header *next;
} *node;

node create_linkedlist(int32_t value);

void print_linkedlist(node linkedlist);
void linkedlist_pushback(node linkedlist, int32_t value);
void linkedlist_pushfront(node *linkedlist, int32_t value);

#endif
