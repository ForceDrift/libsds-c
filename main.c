#include "vector.h"
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  vector vec = create_vector();
  vector_append(vec, 5);
  vector_append(vec, 10);
  // vector_set(vec, 20, 0);
  // int32_t num = vector_get(vec, 0);
  vector_pushback(vec, 67);
  vector_remove(vec, 0);
  vector_insert(vec, 1, 2);

  for (int i = 0; i < vec->length; ++i) {
    printf("%d ", vec->data[i]);
  }

  return 0;
}
