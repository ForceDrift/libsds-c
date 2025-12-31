
#ifndef __LIBDSC_LINKEDLIST_H__
#define __LIBDSC_LINKEDLIST_H__
#include <stdint.h>

typedef struct node_header {
  int32_t data;
  struct node_header *next;
} *node;

/*create and initalize the head of the linked list with null values*/
node create_linkedlist(int32_t value);

/*print out all the values at each node in the linked list*/
void print_linkedlist(node linkedlist);

/*create node with [value] at the end of the linked list*/
void linkedlist_pushback(node linkedlist, int32_t value);

/*create a node and place it in the front of the linked list*/
void linkedlist_pushfront(node *linkedlist, int32_t value);

/*remove the lastnode of the linked list*/
void linkedlist_popback(node *linkedlist);

/*remove the first node in the linked list*/
void linkedlist_popfront(node *linkedlist);

/*clear the linked list*/
void linkedlist_clear(node *linkedlist);

/*reverse the linked list iterativley*/
void linkedlist_reverse(node *linkedlist);

/*find the element in the middle of the linked list*/
node linkedlist_middle(node linkedlist);

#endif
