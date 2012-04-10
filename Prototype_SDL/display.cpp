#include <SDL.h>
#include <SDL_image.h>
#include "display.h"

SDL_Surface* displayLoop(SDL_Surface* screen, const int xC, const int yC, const int zC, int*** mapTable, int xSize, int ySize, SDL_Rect position, SDL_Rect mainPosition, SDL_Surface* map[], SDL_Surface** Papercraft)
{
    int x(0);
    int y(0);
    int z(0);
    //Effacement de l'écran
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));


    //Affichage de la map
    for(z=0; z<zC; z++)
    {
        for(x=0; x<xC; x++)
        {
            for(y=0; y<yC; y++)
            {
                position.x = (x*xSize);
                position.y = (y*ySize);
                switch (mapTable[x][y][z])
                {
                    case 'z':
                        SDL_BlitSurface(map [0], 0, screen, &position);
                        break;
                    case 'e':
                        SDL_BlitSurface(map[6], 0, screen, &position);
                        break;
                    case 'r':
                        SDL_BlitSurface(map[1], 0, screen, &position);
                        break;
                    case 's':
                        SDL_BlitSurface(map[4], 0, screen, &position);
                        break;
                    case 'd':
                        SDL_BlitSurface(map[8], 0, screen, &position);
                        break;
                    case 'f':
                        SDL_BlitSurface(map[5], 0, screen, &position);
                        break;
                    case 'x':
                        SDL_BlitSurface(map[2], 0, screen, &position);
                        break;
                    case 'c':
                        SDL_BlitSurface(map[7], 0, screen, &position);
                        break;
                    case 'v':
                        SDL_BlitSurface(map[3], 0, screen, &position);
                        break;
                    case '0':
                        break;
                }
            }
        }
        if (z == 0)
        {
            position.x= mainPosition.x*xSize;
            position.y= mainPosition.y*ySize;
            SDL_BlitSurface(*Papercraft, 0, screen, &position);
        }
    }
    return screen;
}
