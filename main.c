#include "vector.h"
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  vector vec = init_vector(int);
  vector_append(vec, 5);
  vector_append(vec, 10);
  // vector_set(vec, 20, 0);
  // int32_t num = vector_get(vec, 0);
  vector_remove(vec, 0);

  for (int i = 0; i < vec->length; ++i) {
    printf("%d ", vec->data[i]);
  }

  return 0;
}
