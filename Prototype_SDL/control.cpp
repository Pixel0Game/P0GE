#include <iostream>
#include <SDL.h>
#include "control.h"


void sKeyDown(SDL_Rect* greenposition)
{
    greenposition->y++;
}

void zKeyDown(SDL_Rect* greenposition)
{
    greenposition->y--;
}

void qKeyDown(SDL_Rect* greenposition)
{
    greenposition->x--;
}

void dKeyDown(SDL_Rect* greenposition)
{
    greenposition->x++;
}
