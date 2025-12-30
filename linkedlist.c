#include "linkedlist.h"
#include "stdint.h"
#include "vector.h"
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
    printf("%d ", linkedlist->data);
    linkedlist = linkedlist->next;
  }
}

void linkedlist_pushfront(node *linkedlist, int32_t value) {
  // double ptr to change the adress
  node new_node = malloc(sizeof(struct node_header));

  new_node->data = value;

  new_node->next = *linkedlist;
  *linkedlist = new_node;
}

void linkedlist_popback(node *linkedlist) {
  node curr = *linkedlist;
  while (curr->next->next != NULL) {
    curr = curr->next;
  }
  free(curr->next);
  curr->next = NULL;
}

void linkedlist_popfront(node *linkedlist) {
  // set the new head as the next node and free
  if (linkedlist == NULL || *linkedlist == NULL) {
    return;
  }

  node curr = *linkedlist;
  *linkedlist = curr->next;
  free(curr);
}

void linkedlist_reverse(node *linkedlist) {

  node prev = NULL;
  node curr = *linkedlist;
  node next = NULL;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *linkedlist = prev;
}

void linkedlist_clear(node *linkedlist) {
  node curr = *linkedlist;
  node next;
  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }
  *linkedlist = NULL;
}

node linkedlist_middle(node linkedlist) {
  node fast_curr = linkedlist;
  node slow_curr = linkedlist;
  if (linkedlist->next->next != NULL) {

    while (fast_curr->next != NULL) {
      fast_curr = fast_curr->next->next;
      slow_curr = slow_curr->next;
    }

  } else {
    return NULL;
  }
  return slow_curr;
}
