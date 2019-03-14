#include <stdio.h>
#include "goprint.h"
#include "map.h"
#include "snake.h"
#include "food.h"
#include "interface.h"

int main()
{
    while(1)
    {
        welcome();
        tips();
        map_boundary(map_size);
        snake_create();
        food_create();
        _getch();
        snake_control();
        snake_free();
        if(block_head != NULL)
            block_free();
        quit();
    }
    return 0;
}
