#include <stdio.h>
#include <stdlib.h>

#include "c_vector.h"
#include "c_vector.h"

int main() 
{
	c_vector vec;

	size_t g;

	cvec_init(&vec, sizeof(int));
	printf("%d", cvec_capacity(&vec));

	return 0;
}