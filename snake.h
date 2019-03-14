#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

/* This module is to create the snake body and control the movement of the snake */

#include <stdlib.h>
#include <conio.h>
#include "goprint.h"
#include "map.h"
#include "food.h"
#include "interface.h"

typedef struct SNAKE {
    int x;
    int y;
    struct SNAKE *next;
} SNAKE;

SNAKE *snake_head, *snake_tail;
int score, level;

void snake_create(void);
void snake_control(void);
void snake_move(void);
void snake_free(void);

#endif // SNAKE_H_INCLUDED
