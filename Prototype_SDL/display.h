#ifndef DISPLAY_INCLUDED
#define DISPLAY_INCLUDED

    #include "Block.h"
    SDL_Surface* displayLoop(SDL_Surface* screen, const int xC, const int yC ,const int zC, int*** mapTable, int xSize, int ySize, SDL_Rect position, SDL_Rect mainPosition, SDL_Surface* map[], SDL_Surface** PaperCraft, int score, Block glass);//Boucle d'affichage

#endif // DISPLAY_INCLUDED
