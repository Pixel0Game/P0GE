#include <SDL.h>
#include <SDL_image.h>
#include "display.h"
#include "control.h"



void displayLoop(SDL_Surface* screen, int x, int y, int const xC, int const yC, int* mapTable, int xSize, int ySize)
{
    SDL_Surface* blue = IMG_Load("graph/Colors/blue.png");
    SDL_Surface* red = IMG_Load("graph/Colors/red.png");
    SDL_Surface* green = IMG_Load("graph/Colors/green.png");
    SDL_Surface* luc = IMG_Load("graph/Map/Angle_UL_Black.png");
    SDL_Surface* ruc = IMG_Load("graph/Map/Angle_UR_Black.png");
    SDL_Surface* ldc = IMG_Load("graph/Map/Angle_DL_Black.png");
    SDL_Surface* rdc = IMG_Load("graph/Map/Angle_DR_Black.png");
    SDL_Surface* lb = IMG_Load("graph/Map/L_Black.png");
    SDL_Surface* rb = IMG_Load("graph/Map/R_Black.png");
    SDL_Surface* ub = IMG_Load("graph/Map/U_Black.png");
    SDL_Surface* db = IMG_Load("graph/Map/D_Black.png");
    SDL_Surface* cypher = IMG_Load("graph/Map/White.png");
    SDL_Surface* uP = IMG_Load("graph/Papercraft/up.png");
    SDL_Surface* dP = IMG_Load("graph/Papercraft/down.png");
    SDL_Surface* rP = IMG_Load("graph/Papercraft/right.png");
    SDL_Surface* lP = IMG_Load("graph/Papercraft/left.png");
    SDL_Surface** Papercraft = &uP;

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
                                    case 0:
                                        SDL_BlitSurface(red, 0, screen, &position);
                                        break;
                                    case 1:
                                        SDL_BlitSurface(blue, 0, screen, &position);
                                        break;
                                    case 'z':
                                        SDL_BlitSurface(luc, 0, screen, &position);
                                        break;
                                    case 'e':
                                        SDL_BlitSurface(ub, 0, screen, &position);
                                        break;
                                    case 'r':
                                        SDL_BlitSurface(ruc, 0, screen, &position);
                                        break;
                                    case 's':
                                        SDL_BlitSurface(lb, 0, screen, &position);
                                        break;
                                    case 'd':
                                        SDL_BlitSurface(cypher, 0, screen, &position);
                                        break;
                                    case 'f':
                                        SDL_BlitSurface(rb, 0, screen, &position);
                                        break;
                                    case 'x':
                                        SDL_BlitSurface(ldc, 0, screen, &position);
                                        break;
                                    case 'c':
                                        SDL_BlitSurface(db, 0, screen, &position);
                                        break;
                                    case 'v':
                                        SDL_BlitSurface(rdc, 0, screen, &position);
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

    SDL_FreeSurface(red);
    SDL_FreeSurface(blue);
    SDL_FreeSurface(green);
}
