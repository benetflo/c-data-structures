#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

/*
	VECTOR IMPLEMENTATION

	FUNCTIONS:

	create_vector
	resize_vector
	add_back
*/

typedef struct{
	uint32_t capacity;
	uint32_t elements;
	int* array;
}Vector;

Vector create_vector(uint32_t capacity){
	Vector v;
	v.capacity = capacity;
	v.elements = 0;
	v.array = malloc((sizeof(int)) * capacity);
	if(v.array == NULL){
		Vector c;
		printf("Failed allocating memory\n");
		return c;
	}
	return v;
}

void resize_vector(Vector *vec){
	Vector new_vec;
	new_vec.capacity = (vec->capacity) * 2;
	vec->capacity = new_vec.capacity;
	new_vec.array = malloc((sizeof(int)) * new_vec.capacity);

	for(int i = 0; i < (vec->elements); i++){
		new_vec.array[i] = vec->array[i];
	}

	int* old_array = vec->array;
	vec->array = new_vec.array;
	free(old_array);
}

void add_back(Vector *vec, uint32_t element){
	if(vec->elements == vec->capacity){
		resize_vector(vec);
	}
	vec->array[vec->elements] = element;
	vec->elements++;
}

