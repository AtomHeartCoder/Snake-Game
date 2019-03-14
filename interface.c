#include "interface.h"

extern FOOD award_food;
extern int lose, level, map_size, award, award_score;
extern char control, direction;
int margin;

void welcome(void)
{
    lose = 0, level = 3, map_size = 30, score = 0, award = 0, margin = map_size + 5;
    control = 'w', direction = 'w';
    int opt;
    char map_choice;
    goprint(4, 4, "Welcome to the Snake by Lst");
    goprint(6, 6, "Start by number:\n\n");
    printf("1. Quick game\n2. Customized game\n3. Exit\n\n*** Please play in English Input Method ***\n");
    opt = _getch() - '0';
    switch(opt){
        case 1:
            break;
        case 2:
            printf("\nChoose level from 1 to 9 or... (Press Enter):");
            scanf("%d", &level);
            do{
                printf("\nInput map size no less than 5 (Press Enter):");
                scanf("%d", &map_size);
                margin = map_size + 5;
            }while(map_size < 5);
            getchar();
            printf("\nDo you want to create the boundary blocks? Y / N:");
            map_choice = getchar();
            getchar();
            break;
        case 3:
            exit(0);
    }
    system("cls");
    if(map_choice == 'y' || map_choice == 'Y')
        map_0(map_size);
}

void tips(void)
{
    gotoxy(margin, 5);
    printf("Level: %d", level);
    gotoxy(margin, 7);
    printf("Map size: %d * %d", map_size, map_size);
    goprint(margin, 9, "Play with \"wsad\"");
    goprint(margin, 11, "Click to pause / Press \"wsad\" to continue / Press 'p' to quit");
}

void show_score(void)
{
    if(award == 5){
        goprint(margin, 13, "Award Food:");
        goprint(margin, 14, "¨€¨€¨€¨€¨€¨€¨€¨€¨€¨€");
        award_score = 100;
        award = 0;
    }
    if(award_food.x == -1){
        gotoxy(margin, 13);
        printf("           ");
        gotoxy(margin, 14);
        printf("                    ");
    }
    gotoxy(margin, 3);
    printf("Your score: %d", score);
}

void quit(void)
{
    if(lose){
        system("color 01");
        Sleep(100);
        system("color 0F");
        goprint(map_size / 2 - 2, map_size / 2 - 3, "You lose!");
    }
    else
        goprint(map_size / 2 - 2, map_size / 2 - 3, "You quit!");
    gotoxy(map_size / 2 - 4, map_size / 2 - 1);
    printf("Your score: %5d", score);
    goprint(map_size / 2 - 6, map_size / 2 + 1, " Press Enter to continue");
    gotoxy(0, 0);
    while(getchar() != '\n') ;
    system("cls");
}

void progress_bar(void)
{
    goprint(margin + award_score / 10, 14, " ");
    if((award_score --) == 0){
        goprint(margin, 13, "           ");
        goprint(margin, 14, "                    ");
        goprint(award_food.x, award_food.y, "  ");
        award_food.x = -1, award_food.y = -1;
    }
}
