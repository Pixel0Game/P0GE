#include <SDL.h>
#include <SDL_image.h>
#include "display.h"
#include "control.h"



void displayLoop(SDL_Surface* screen, int x, int y, int const xC, int const yC, int* mapTable, int xSize, int ySize)
{
    ///Chargement des images
        SDL_Surface* map [15] = {NULL};
        map[0] = IMG_Load("graph/Map/Angle_UL_Black.png");
        map[1] = IMG_Load("graph/Map/Angle_UR_Black.png");
        map[2] = IMG_Load("graph/Map/Angle_DL_Black.png");
        map[3] = IMG_Load("graph/Map/Angle_DR_Black.png");
        map[4] = IMG_Load("graph/Map/L_Black.png");
        map[5] = IMG_Load("graph/Map/R_Black.png");
        map[6] = IMG_Load("graph/Map/U_Black.png");
        map[7] = IMG_Load("graph/Map/D_Black.png");
        map[8] = IMG_Load("graph/Map/White.png");
        SDL_Surface* uP = IMG_Load("graph/Papercraft/up.png");
        SDL_Surface* dP = IMG_Load("graph/Papercraft/down.png");
        SDL_Surface* rP = IMG_Load("graph/Papercraft/right.png");
        SDL_Surface* lP = IMG_Load("graph/Papercraft/left.png");
        SDL_Surface** Papercraft = &uP;
    ///Fin du chargement.

    SDL_Rect position;
        position.x = (0);
        position.y = (0);
    SDL_Rect greenposition;
        greenposition.x = x;
        greenposition.y = y;

    bool done(false);
    bool movement(false);
    SDL_EnableKeyRepeat(100, 100);

    while (!done)
    {
        //Attente d'un événement
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type) //Verification du type
            {
                case SDL_QUIT: //Fenêtre fermé (croix rouge)
                    done = true;
                    break;

                // check for keypresses
                case SDL_KEYDOWN:

                    if (event.key.keysym.sym == SDLK_ESCAPE)
                            done = true;
                    if (event.key.keysym.sym == SDLK_KP2)
                        if (mapTable[greenposition.x*yC+(greenposition.y+1)] == 'd')
                            {sKeyDown(&greenposition);
                            Papercraft = &dP;}
                    if (event.key.keysym.sym == SDLK_KP8)
                        if (mapTable[greenposition.x*yC+(greenposition.y-1)] == 'd')
                            {zKeyDown(&greenposition);
                            Papercraft =&uP;}
                    if (event.key.keysym.sym == SDLK_KP4)
                        if (mapTable[(greenposition.x-1)*yC+(greenposition.y)] == 'd')
                            {qKeyDown(&greenposition);
                            Papercraft =&lP;}
                    if (event.key.keysym.sym == SDLK_KP6)
                        if (mapTable[(greenposition.x+1)*yC+(greenposition.y)] == 'd')
                            {dKeyDown(&greenposition);
                            Papercraft=&rP;}

                    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
                    for(x=0; x<xC; x++)
                    {
                        for(y=0; y<yC; y++)
                        {
                            position.x = (x*xSize);
                            position.y = (y*ySize);
                            switch (mapTable[x*yC+y])
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
                                }
                        }
                    }
                    position.x= greenposition.x*xSize;
                    position.y= greenposition.y*ySize;
                    SDL_BlitSurface(*Papercraft, 0, screen, &position);
                    break;

            }
            SDL_Flip(screen);

        }

    }
        //! Free Map for TODO
        for (x=0;x<15;x++)
        {
            SDL_FreeSurface(map[x]);
        }
        SDL_FreeSurface(uP);
        SDL_FreeSurface(dP);
        SDL_FreeSurface(rP);
        SDL_FreeSurface(lP);
}
