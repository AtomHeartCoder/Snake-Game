#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

/* This module is to print blocks on the map */

#include <stdlib.h>
#include "goprint.h"

typedef struct BLOCK {
    int x;
    int y;
    struct BLOCK *next;
} BLOCK;

typedef struct BOUNDARY {
    int x;
    int y;
} BOUNDARY;

BLOCK *block_head;
BOUNDARY boundary;
int map_size;

void map_boundary(int Map_Size);
void map_0(int Map_Size);
void map_1(void);void map_2(void);void map_3(void);void block_free(void);
BLOCK *block_create();

#endif // MAP_H_INCLUDED
