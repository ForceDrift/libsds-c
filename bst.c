#include "bst.h"
#include "stdbool.h"
#include "vector.h"
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue_bst_header {
  size_t length;
  size_t capacity;
  tree_node *data;

} *queue_bst;

void _queue_ensure_capacity(queue_bst queue) {

  if (queue->length <= queue->capacity) {
    size_t mem_cap = queue->capacity * 2;
    // create a new block that is bigger
    queue_bst *data_add = realloc(queue->data, mem_cap * sizeof(tree_node));

    queue->data = (void *)data_add;
    queue->capacity = mem_cap;
  }
}
queue_bst create_queue_bst() {
  queue_bst init_queue = malloc(sizeof(struct queue_bst_header));
  init_queue->data = NULL;
  init_queue->length = 0, init_queue->capacity = 4;
  return init_queue;
}

void queue_bst_enqueue(queue_bst queue, tree_node value) {
  _queue_ensure_capacity(queue);
  queue->data[queue->length] = value;
  queue->length += 1;
}

void queue_bst_dequeue(queue_bst queue) {
  // arr of tree nodes
  tree_node *arr = queue->data;
  if (queue->length > 1) {
    memmove(arr, arr + 1, (queue->length - 1) * sizeof(tree_node));
  }
  queue->length -= 1;
  if (queue->length > 0) {
    tree_node *shrink = realloc(queue->data, queue->length * sizeof(tree_node));
    queue->data = shrink;
    queue->capacity = queue->length;
  } else {
    free(queue->data);
    queue->data = NULL;
  }
}

tree_node create_bst_node(int32_t value) {

  tree_node init_node = (tree_node)malloc(sizeof(struct tree_node_header));
  init_node->right = NULL;
  init_node->left = NULL;
  init_node->data = value;
  return init_node;
}

void bst_insert(int32_t key, tree_node head) {
  tree_node curr = head;
  while (true) {
    // if key is less than curr data
    if (key < curr->data) {
      if (curr->left != NULL) {
        curr = curr->left;

      } else {
        curr->left = create_bst_node(key);
        return;
      }
    } else {
      if (curr->right != NULL) {
        curr = curr->right;
      } else {
        curr->right = create_bst_node(key);
        return;
      }
    }
  }
}

void print_spaces(int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf(" ");
  }
}

void bst_print(tree_node head, int32_t amt_nodes) {

  // bruh tree queue implementation for bfs
  queue_bst queue = create_queue_bst();
  queue_bst_enqueue(queue, head);

  // todo: fix spacing later using recursion or smth
  int32_t layers = log2((int)amt_nodes);
  const int32_t offset = 2;

  while ((int)queue->length > 0) {

    int level_size = (int)queue->length;
    for (int i = 0; i < level_size; ++i) {
      tree_node node = queue->data[0];
      queue_bst_dequeue(queue);
      print_spaces(layers + offset);

      printf("%d  ", node->data);
      if (node->left != NULL) {
        queue_bst_enqueue(queue, node->left);
      }

      if (node->right != NULL) {
        queue_bst_enqueue(queue, node->right);
      }
    }
    printf("\n");

    layers -= offset;
  }

  free(queue->data);
  free(queue);
};

//  create inital node in a memory
