#include "goprint.h"

void gotoxy(int x, int y)                                  /* Go to the coordinate */
{
    COORD pos = {2 * x, y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}

void goprint(int x, int y, const char *c)                  /* Print the char */
{
    gotoxy(x, y);
    printf("%s", c);
}
