#ifndef CVECTOR_H_
#define CVECTOR_H_

#define C_VEC_STANDART_CAP 4

typedef struct {
	void* data;
	int element_size;

	int size;
	int capacity;
} c_vector;

void cvec_init(c_vector* vec, int dataSize);
void cvec_copy(c_vector* vecONE, c_vector* vecTWO);

int cvec_size(c_vector* vec);
int cvec_capacity(c_vector* vec);

void cvec_resize(c_vector* vec, int newCap);
void cvec_clear(c_vector* vec);

void cvec_set(c_vector* vec, int index, void* data);
void cvec_get(c_vector* vec, int index);

void cvec_push_back(c_vector* vec, void* data);
void cvec_delete(c_vector* vec, int index);

#endif /* CVECTOR_H_ */