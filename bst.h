#ifndef __LIBSC_BINARY_SEARCH_TREE_H__
#define __LIBSC_BINARY_SEARCH_TREE_H__

#include <stdint.h>
#include <stdlib.h>
typedef struct tree_node_header {
  int32_t data;
  struct tree_node_header *right;
  struct tree_node_header *left;

} *tree_node;

/* create a node in the binary search tree with [value]*/
tree_node create_bst_node(int32_t value);

/* insert a value into the binary tree starting from [head] */
void bst_insert(int32_t key, tree_node head);

/* print binary search tree using dfs */
void bst_print(tree_node head, int32_t nodes);

#endif // !__LIBSC_BINARY_SEARCH_TREE_H__
