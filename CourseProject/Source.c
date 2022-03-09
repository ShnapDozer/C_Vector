#include <stdio.h>
#include <stdlib.h>

#include "c_map.h"
#include "c_vector.h"

int main()
{
	c_vector vec;
	cvec_init(&vec, sizeof(int));

	for (int i = 0; i < 100; ++i)
		cvec_push_back(&vec, &i);

	printf(" 0 - %d, C - %d, S - %d, POP - %d \n",
		*(int*)cvec_get(&vec, 0), 
		cvec_capacity(&vec),
		cvec_size(&vec),
		*(int*)cvec_pop_back(&vec)
	);

	for (int i = 0; i < 100; ++i)
		printf("%d\t", *(int*)cvec_get(&vec, i));

	c_map map;
	cmap_init(&map, sizeof(int));

	return 0;
}