#ifndef __LIBSC_BINARY_SEARCH_TREE_H__
#define __LIBSC_BINARY_SEARCH_TREE_H__

#include <stdint.h>
#include <stdlib.h>
typedef struct tree_node_header {
  int32_t data;
  struct tree_node_header *right;
  struct tree_node_header *left;

} *tree_node;

tree_node create_bst_node(int32_t value);

void bst_insert(int32_t key, tree_node head);

void bst_print(tree_node head, int32_t nodes);

void print_queue();

#endif // !__LIBSC_BINARY_SEARCH_TREE_H__
