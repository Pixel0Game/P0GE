#include <SDL.h>
#include <SDL_image.h>
#include <SDL/SDL_TTF.h>
#include "display.h"
#include "Block.h"

SDL_Surface* displayLoop(SDL_Surface* screen, const int xC, const int yC, const int zC, int*** mapTable, int xSize, int ySize, SDL_Rect position, SDL_Rect mainPosition, SDL_Surface* map[], SDL_Surface** Papercraft, int score, Block glass)
{
    TTF_Init();
    char scoretext[10] ="";
    sprintf(scoretext, "Score: %d", score);
    SDL_Color couleurNoire = {0, 0, 0};
    TTF_Font *police = TTF_OpenFont("arial.ttf", 65);
    SDL_Surface* texte = TTF_RenderText_Blended(police, scoretext , couleurNoire);

    int x(0);
    int y(0);
    int z(0);
    //Effacement de l'écran
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_SetColorKey(map[2], SDL_SRCCOLORKEY, SDL_MapRGB(map[2]->format, 255,255, 255));
    SDL_SetAlpha(map[2],SDL_SRCALPHA, 128);


    //Affichage de la map
    for(z=0; z<zC; z++)
    {
        for(y=0; y<yC; y++)
        {
            for(x=0; x<xC; x++)
            {
                position.x = (x*xSize);
                position.y = (y*ySize);
                switch (mapTable[x][y][z])
                {
                    case 'w':
                        SDL_BlitSurface(map[0], 0, screen, &position);
                        break;
                    case 'c':
                        SDL_BlitSurface(map[1], 0, screen, &position);
                        break;
                    case 'g':
                        SDL_BlitSurface(glass.getSprite(), 0, screen, &position);
                        break;
                    case '0':
                        break;
                }
            }
        }
        position.x=400;
        position.y=10;
        SDL_BlitSurface(texte, 0, screen, &position);
        if (z == 0)
        {
            position.x= mainPosition.x*xSize;
            position.y= mainPosition.y*ySize;
            SDL_BlitSurface(*Papercraft, 0, screen, &position);
        }
    }
    TTF_Quit();
    return screen;
}
