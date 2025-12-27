#include "vector.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _vector_ensure_capacity(vector vec) {

  if (vec->length <= vec->capacity) {
    size_t mem_cap = vec->capacity * 2;
    // create a new block that is bigger
    int32_t *data_add = realloc(vec->data, mem_cap * vec->element_size);

    vec->data = data_add;
    vec->capacity = mem_cap;
  }
}

vector create_vector(size_t element_size) {

  vector vec = (vector)malloc(sizeof(struct vector_header));

  vec->length = 0, vec->capacity = 0;
  vec->element_size = element_size;
  vec->data = NULL;
  return vec;
}

void vector_append(vector vec, int32_t value) {
  _vector_ensure_capacity(vec);

  vec->data[vec->length] = value;
  vec->length += 1;
}

void vector_set(vector vec, int32_t value, int32_t pos) {
  // find memory adress of the index and copy value into that adress
  _vector_ensure_capacity(vec);
  memcpy(vec->data, &value, vec->element_size);
};

int32_t vector_get(vector vec, int32_t pos) {

  char *target = (char *)vec->data + (pos * vec->element_size);
  return *(int32_t *)target;
}

// void vector_pushback(vector vec, int32_t value) {
//
//   _vector_ensure_capacity(vec);
//   // create a new block that is one bigger
//   size_t total_size = sizeof(vec) + vec->element_size;
//   // find total elemnts
//   char *data_add = realloc(vec->data, total_size);
//   vec->data = (void *)data_add;
//
//   vec->data[vec->length] = value;
//   vec->length += 1;
// };

void vector_remove(vector vec, int32_t pos) {

  char *remove_address = (char *)vec->data + (pos * vec->element_size);
  char *item_after = remove_address + (vec->element_size);
  memmove(remove_address, item_after,
          (vec->length - pos - 1) * vec->element_size);

  vec->length -= 1;
}

void vector_insert(vector vec, int32_t pos, int32_t value) {

  _vector_ensure_capacity(vec);
  char *remove_address = (char *)vec->data + (pos + 1 * vec->element_size);

  char *item_after = remove_address + (vec->element_size);
  memmove(item_after, remove_address,
          (vec->length - pos + 1) * vec->element_size);
  vec->length += 1;

  memcpy(remove_address - 1, (void *)&value, vec->element_size);
}

void vector_free(vector vec) {
  if (vec == NULL)
    return;
  if (vec->data != NULL)
    free(vec->data);
  free(vec);
}

void vector_shrink(vector vec) {
  if (vec->length < vec->capacity) {
    size_t realloc_size = (vec->length * vec->element_size);
    char *fixed_data = realloc(vec->data, realloc_size);
    vec->data = (void *)fixed_data;
  }
}
