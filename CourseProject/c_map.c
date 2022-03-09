#include "c_map.h"
#include <stdio.h>

//Nod size is considered without key size!!!!

//Private:
size_t _keySize(char* key) 
{
	return (strlen(key) + 1) * sizeof(char);
}
size_t _nodeSize(c_map* map)
{
	return (sizeof(bool) + 3 * sizeof(node_map*) + map->data_size);
}

node_map* _initNode(c_map* map, char* key, void* data)
{
	node_map* t = malloc(map->node_size + _keySize(key));

	memcpy(t->key, key, _keySize(key));
	memcpy(t->value, data, map->data_size);

	t->black = false;
	t->Left = map->Null;
	t->Right = map->Null;

	return t;
}

node_map* _findPlace(c_map* map, char* key)
{
	//return place for incert node
}

void _placeNode(c_map* map, node_map* node)
{
	//place node in BR-tree
}

void _destoryNode(node_map* node)
{
	if (node == NULL)
		return;
	_destoryNode(node->Left);
	_destoryNode(node->Right);
	free(node);
	node = NULL;
}

void _cursorLeft(node_map* cur)
{
	while (cur->Left != NULL)
		cur = cur->Left;
}

void _cursorRight(node_map* cur)
{
	while (cur->Right != NULL)
		cur = cur->Right;
}


//Public:
void cmap_init(c_map* map, size_t sizeEl)
{
	map->size = 0;
	map->data_size = sizeEl;
	map->node_size = _nodeSize(map);

	map->Head = NULL;
	map->Null = NULL;
}

void cmap_copy(c_map* mapONE, c_map* mapTWO)
{
	cmap_clear(mapONE);

	mapONE->Head = malloc(mapTWO->node_size);
	memcpy(mapONE->Head, mapTWO->Head, mapTWO->node_size);

	mapONE->Null = mapTWO->Null;
	mapONE->size = mapTWO->size;
	mapONE->data_size = mapTWO->data_size;
	mapONE->node_size = mapTWO->node_size;
}

int cmap_size(c_map* map)
{
	return map->size;
}

bool cmap_empty(c_map* map)
{
	return map->size == 0;
}

void cmap_clear(c_map* map)
{
	_destoryNode(map->Head);
}

void cmap_insert(c_map* map, node_map* node)
{
	_placeNode(map, node);
}
