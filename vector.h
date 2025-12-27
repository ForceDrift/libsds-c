#ifndef __LIBDSC_VECTOR_H__
#define __LIBDSC_VECTOR_H__

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

struct vector_header {
  // size variables
  size_t length;
  size_t capacity;

  // data variables
  int32_t *data;
};

typedef struct vector_header *vector;

vector create_vector();

void vector_append(vector vec, int32_t value);

void vector_set(vector vec, int32_t value, int32_t pos);

int32_t vector_get(vector vec, int32_t pos);

void vector_pushback(vector vec, int32_t value);

void vector_remove(vector vec, int32_t pos);

void vector_insert(vector vec, int32_t pos, int32_t value);
#endif // __LIBDSC_VECTOR_H__
