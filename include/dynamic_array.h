#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include "data_structures.h"

Vector create_vector(uint32_t capacity);
void resize_vector(Vector *vec);
void add_back(Vector *vec, int element);
void pop_back(Vector *vec);

#endif
