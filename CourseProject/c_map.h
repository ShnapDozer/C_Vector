#ifndef CMAP_H_
#define CMAP_H_

#include<stdbool.h> 

typedef struct {
	void* key;
	void* value;

	bool black;

	node_map* Left;
	node_map* Right;
} node_map;

typedef struct {
	node_map* Head;
	node_map* Null;

	int size;
} c_map;




#endif /* CMAP_H_ */
