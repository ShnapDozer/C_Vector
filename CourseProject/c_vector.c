#include "c_vector.h"

#include<stdbool.h>  

//Private:

bool _isFull(c_vector* vec) 
{
	return vec->capacity == vec->size;
}

void _copyFor(c_vector* vec, int index)
{
	for (int i = index; (i + 1) < vec->size; ++i)
	{
		void* current = (char*)vec->data + (i * vec->element_size);
		void* next = (char*)vec->data + ((i + 1) * vec->element_size);
		memcpy(current, next, vec->element_size);
	}
}

void _doubleCap(c_vector* vec) { cvec_resize(vec, vec->capacity * 2); }

//Public:

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

void cvec_clear(c_vector* vec)
{
	free(vec->data);
	vec->size = 0;
	vec->capacity = 0;
}

void cvec_set(c_vector* vec, int index, void* data)
{
	void* place = (char*)vec->data + (index * vec->element_size);
	memcpy(place, data, vec->element_size);
}

void* cvec_get(c_vector* vec, int index)
{
	return (char*)vec->data + (index * vec->element_size);
}

void cvec_push_back(c_vector* vec, void* data)
{
	if (_isFull(vec))
		_doubleCap(vec);

	void* place = (char*)vec->data + (vec->size * vec->element_size);
	memcpy(place, data, vec->element_size);

	++vec->size;
}

void* cvec_pop_back(c_vector* vec)
{
	return cvec_get(vec, --vec->size);
}

void cvec_del_el(c_vector* vec, int index)
{
	if (index == (vec->size - 1))
		cvec_pop_back(vec);
	else {
		_copyFor(vec, index);
		--vec->size;
	}
}
