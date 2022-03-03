#include "c_vector.h"

void cvec_init(c_vector* vec, int dataSize)
{
	vec->size = 0;
	vec->capacity = C_VEC_STANDART_CAP;
	vec->element_size = dataSize;

	vec->data = malloc(vec->element_size * vec->capacity);
}

void cvec_copy(c_vector* vecIN, c_vector* vecOUT)
{
	if (vecIN->capacity >= vecOUT->size)
		memcpy(vecIN->data, vecOUT->data, vecOUT->element_size * vecOUT->size);
	else {
		cvec_resize(vecIN, vecOUT->size * 2);
		memcpy(vecIN->data, vecOUT->data, vecOUT->element_size * vecOUT->size);
	}
	vecIN->size = vecOUT->size;
}

int cvec_size(c_vector* vec)
{
	return vec->size;
}

int cvec_capacity(c_vector* vec)
{
	return vec->capacity;
}

void cvec_resize(c_vector* vec, int newCap)
{
	vec->capacity = newCap;

	void* t = malloc(vec->element_size * vec->capacity);
	memcpy(t, vec->data, vec->element_size * vec->size);

	free(vec->data);
	vec->data = t;
}

void cvec_push_back(c_vector* vec, void* data)
{ 
	void* place = vec->data + (vec->size * vec->element_size);
	memcpy(place, data, vec->element_size);

	++vec->size;
}

