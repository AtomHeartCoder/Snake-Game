#include "map.h"

BOUNDARY boundary = {0, 0};
BLOCK *block_head = NULL;
int map_size = 50;

void map_boundary(int Map_Size)                             /* Print the boundary of the map */
{
    int i;
    boundary.x = Map_Size;
    boundary.y = Map_Size;
    for(i = 0; i < Map_Size; i ++)
        goprint(Map_Size, i, "©ª");
    for(i = 0; i < Map_Size; i ++)
        goprint(i, Map_Size, "©¨");
    goprint(Map_Size, Map_Size, "©¼");
}

void map_0(int Map_Size)                      /* Print the outer blocks */
{
    int i;
    BLOCK *p = NULL;
    block_head = (BLOCK *)malloc(sizeof(BLOCK));
    for(i = 0, p = block_head; i < Map_Size; i ++){
        goprint(i, 0, "¨€");
        p->x = i, p->y = 0;
        p->next = (BLOCK *)malloc(sizeof(BLOCK));
        p = p->next;
        goprint(i, Map_Size - 1, "¨€");
        p->x = i, p->y = Map_Size - 1;
        p->next = (BLOCK *)malloc(sizeof(BLOCK));
        p = p->next;
    }
    for(i = 1; i < Map_Size - 1; i ++){
        goprint(0, i, "¨€");
        p->x = 0, p->y = i;
        p->next = (BLOCK *)malloc(sizeof(BLOCK));
        p = p->next;
        goprint(Map_Size - 1, i, "¨€");
        p->x = Map_Size - 1, p->y = i;
        if(i == Map_Size - 2){
            p->next = NULL;
            break;
        }
        p->next = (BLOCK *)malloc(sizeof(BLOCK));
        p = p->next;
    }
    for(p = block_head; p != NULL; p = p->next);
}

void block_free(void)
{
    BLOCK *p1, *p2;
    for(p1 = block_head, p2 = p1; p1 != NULL; p2 = p1){
        p1 = p1->next;
        free(p2);
    }
    block_head = NULL;
}
