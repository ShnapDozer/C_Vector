#ifndef CMAP_H_
#define CMAP_H_

#include <stdio.h> 
#include<stdbool.h> 

typedef struct node_map node_map;
struct node_map {
	char* key;
	void* value;

	bool black;

	node_map* Parent;
	node_map* Left;
	node_map* Right;
};

typedef struct {
	node_map* Head;
	node_map* Null;

	int size;
	size_t data_size;
	size_t node_size;
} c_map;

void  cmap_init(c_map* map, size_t sizeEl);
void  cmap_copy(c_map* mapONE, c_map* mapTWO);

int   cmap_size(c_map* map);
bool  cmap_empty(c_map* map);

void  cmap_clear(c_map* map);
void  cmap_insert(c_map* map, node_map* node);
void  cmap_del_N(c_map* map, char* key);

void* cmap_at(c_map* map, char* key);
void  cmap_set(c_map* map, char* key, void* data);
int   cmap_count(c_map* map, char* key);


#endif /* CMAP_H_ */
