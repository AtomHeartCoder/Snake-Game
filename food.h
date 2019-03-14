#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED

/* This module offer the function of creating food and print the food */

#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "snake.h"
#include "interface.h"

typedef struct FOOD {
    int x;
    int y;
} FOOD;

FOOD food, award_food;
int award, award_score;

void food_create(void);

#endif // FOOD_H_INCLUDED
