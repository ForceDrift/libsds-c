#include "linkedlist.h"
#include "stdint.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

node create_linkedlist(int32_t value) {
  node first_node = malloc(sizeof(struct node_header));
  if (first_node == NULL)
    return NULL;
  first_node->data = value;
  first_node->next = NULL;
  return first_node;
}

void linkedlist_pushback(node linkedlist, int32_t value) {

  node new_node = malloc(sizeof(struct node_header));
  new_node->data = value;
  new_node->next = NULL;

  while (linkedlist->next != NULL) {
    linkedlist = linkedlist->next;
  }

  linkedlist->next = new_node;
}

void print_linkedlist(node linkedlist) {
  while (linkedlist != NULL) {
    printf("%d", linkedlist->data);
    linkedlist = linkedlist->next;
  }
}

void linkedlist_pushfront(node *linkedlist, int32_t value) {
  node new_node = malloc(sizeof(struct node_header));

  new_node->data = value;

  new_node->next = linkedlist;
  linkedlist = new_node;
}
