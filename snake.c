#include "snake.h"

extern int award_score, map_size;
extern FOOD food, award_food;
SNAKE *snake_head = NULL, *snake_tail = NULL, *temp, front;
char control = 'w', direction = 'w';
int lose = 0, score = 0, level = 3;

void snake_create(void)                                    /* Make the snake at the beginning */
{
    SNAKE *p = NULL;
    snake_head = (SNAKE *)malloc(sizeof(SNAKE));
    snake_head->x = map_size / 2;
    snake_head->y = map_size / 2;
    snake_head->next = (SNAKE *)malloc(sizeof(SNAKE));
    p = snake_head->next;
    p->x = snake_head->x;
    p->y = snake_head->y + 1;
    p->next = (SNAKE *)malloc(sizeof(SNAKE));
    snake_tail = p->next;
    snake_tail->x = snake_head->x;
    snake_tail->y = snake_head->y + 2;
    snake_tail->next = NULL;
    for(p = snake_head; p != NULL; p = p->next)
        goprint(p->x, p->y, "¡ö");
}

void snake_control(void)
{
    while(!lose){
        Sleep(600 / level);
        if(award_food.x != -1)
            progress_bar();
        if(_kbhit()){
			control = _getch();
			if(control == 'p' || control == 'P')
                break;
			if(control == 'w' || control == 's' || control == 'a' || control == 'd' || control == 'W' || control == 'S' || control == 'A' || control == 'D'){
                if((direction == 'w' || direction == 'w') && (control == 's' || control == 'S')) ;
                else if((direction == 's' || direction == 'S') && (control == 'w' || control == 'W')) ;
                else if((direction == 'a' || direction == 'A') && (control == 'd' || control == 'D')) ;
                else if((direction == 'd' || direction == 'D') && (control == 'a' || control == 'A')) ;
                else direction = control;
			}
        }
        snake_move();
    }
    goprint(snake_head->x, snake_head->y, "¡Á");
}

void snake_move(void)
{
    SNAKE *p1;
    BLOCK *p2;
    switch(direction){
            case 'w':
                front.x = snake_head->x;
                front.y = snake_head->y - 1;
                break;
            case 's':
                front.x = snake_head->x;
                front.y = snake_head->y + 1;
                break;
            case 'a':
                front.x = snake_head->x - 1;
                front.y = snake_head->y;
                break;
            case 'd':
                front.x = snake_head->x + 1;
                front.y = snake_head->y;
                break;
            case 'W':
                front.x = snake_head->x;
                front.y = snake_head->y - 1;
                break;
            case 'S':
                front.x = snake_head->x;
                front.y = snake_head->y + 1;
                break;
            case 'A':
                front.x = snake_head->x - 1;
                front.y = snake_head->y;
                break;
            case 'D':
                front.x = snake_head->x + 1;
                front.y = snake_head->y;
                break;
    }
    if(front.x == map_size)                                /* Here we allow the snake to penetrate the boundary */
        front.x = 0;
    if(front.x == -1)
        front.x = map_size - 1;
    if(front.y == map_size)
        front.y = 0;
    if(front.y == -1)
        front.y = map_size - 1;
    for(p1 = snake_head, p2 = block_head; p1 != snake_tail || p2 != NULL;){
        if(p1 != snake_tail){
            if(front.x == p1->x && front.y == p1->y){
                lose = 1;
                return;
            }
            if(p1->next == snake_tail)
                temp = p1;
            p1 = p1->next;
        }
        if(p2 != NULL){
            if(front.x == p2->x && front.y == p2->y){
                lose = 1;
                return;
            }
            p2 = p2->next;
        }
    }
    if((front.x == food.x && front.y == food.y) || (front.x == award_food.x && front.y == award_food.y)){
        temp = (SNAKE *)malloc(sizeof(SNAKE));
        *temp = front;
        temp->next = snake_head;
        snake_head = temp;
        goprint(snake_head->x, snake_head->y, "¡ö");
        if(front.x == award_food.x){
            score += award_score / 2 * level;
            award_food.x = -1, award_food.y = -1, award_score = 100;
            show_score();
        }
        else{
            award ++;
            score += level;
            food_create();
        }
        return;
    }
    goprint(snake_tail->x, snake_tail->y, "  ");
    snake_tail->next = snake_head;
    snake_head = snake_tail;
    snake_tail = temp;
    snake_tail->next = NULL;
    snake_head->x = front.x;
    snake_head->y = front.y;
    goprint(snake_head->x, snake_head->y, "¡ö");
}

void snake_free(void)
{
    SNAKE *p1, *p2;
    for(p1 = snake_head, p2 = p1; p1 != NULL; p2 = p1){
        p1 = p1->next;
        free(p2);
    }
}