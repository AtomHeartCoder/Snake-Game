#ifndef GOPRINT_H_INCLUDED
#define GOPRINT_H_INCLUDED

/* This module offer the function of printing at any coordinate */

#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y);
void goprint(int x, int y, const char *c);

#endif // GOPRINT_H_INCLUDED
