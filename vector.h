#ifndef __LIBDSC_VECTOR_H__
#define __LIBDSC_VECTOR_H__

#define init_vector(type) create_vector(sizeof(type))

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

struct vector_header {
  size_t length;
  size_t capacity;
  size_t element_size;

  int32_t *data;
};

typedef struct vector_header *vector;

/*create a vector object*/
vector create_vector(size_t element_size);

/*insert an element at the end of the vector */
void vector_append(vector vec, int32_t value);

/*set the value at a certain index*/
void vector_set(vector vec, int32_t value, int32_t pos);

/*get the value at a index [pos]*/
int32_t vector_get(vector vec, int32_t pos);

/*remove  value as index [pos] */
void vector_remove(vector vec, int32_t pos);

/*insert [value] at index [pos]*/
void vector_insert(vector vec, int32_t pos, int32_t value);

/*free memory from vector*/
void vector_free(vector vec);

/*shrink vector after any removal i.e remove one element from vec(100) shrink to
 * so memery is from vec[99]*/
void vector_shrink(vector vec);

#endif // __LIBDSC_VECTOR_H__
