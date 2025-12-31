#include "bst.h"
#include "linkedlist.h"
#include "vector.h"
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  // vector vec = init_vector(int);
  // vector_append(vec, 5);
  // vector_append(vec, 10);
  // // vector_set(vec, 20, 0);
  // // int32_t num = vector_get(vec, 0);
  // vector_remove(vec, 0);
  //
  // for (int i = 0; i < vec->length; ++i) {
  //   printf("%d ", vec->data[i]);
  // }

  // node init = create_linkedlist(10);
  // linkedlist_pushback(init, 75);
  // linkedlist_pushback(init, 75);
  // printf("%d", linkedlist_middle(init)->data);
  //
  //
  // print_linkedlist(init);
  // //

  tree_node root = create_bst_node(50);

  // 2. Insert sample nodes to build the tree structure
  // Standard BST: Left is smaller, Right is larger
  bst_insert(30, root);
  bst_insert(70, root);
  bst_insert(20, root);
  bst_insert(40, root);
  bst_insert(60, root);
  bst_insert(80, root);
  bst_insert(15, root);
  bst_insert(25, root);
  bst_print(root, 12);

  return 0;
}
