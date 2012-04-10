#include <SDL.h>
#include <SDL_image.h>
#include "display.h"
#include "control.h"

void mainLoop(SDL_Surface* screen, int x, int y, const int xC, const int yC, const int zC, int*** mapTable, int xSize, int ySize)
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
    ///Fin.

    ///Initialisation des positions.
        SDL_Rect position;
            position.x = (0);
            position.y = (0);
        SDL_Rect mainPosition;
            mainPosition.x = x;
            mainPosition.y = y;
    ///Fin.

    bool done(false);
    bool start(false);
    SDL_EnableKeyRepeat(100, 100);

    ///Boucle principale.
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
                case SDL_KEYDOWN://Vérification du clavier 'touche pressé'

                    if (event.key.keysym.sym == SDLK_ESCAPE)
                            {done = true;}
                    if (event.key.keysym.sym == SDLK_KP2)
                        if (mapTable[mainPosition.x][mainPosition.y+1][0] == 'd')
                            {sKeyDown(&mainPosition);
                            Papercraft = &dP;}
                    if (event.key.keysym.sym == SDLK_KP8)
                        if (mapTable[mainPosition.x][mainPosition.y-1][0] == 'd')
                            {zKeyDown(&mainPosition);
                            Papercraft =&uP;}
                    if (event.key.keysym.sym == SDLK_KP4)
                        if (mapTable[mainPosition.x-1][mainPosition.y][0] == 'd')
                            {qKeyDown(&mainPosition);
                            Papercraft =&lP;}
                    if (event.key.keysym.sym == SDLK_KP6)
                        if (mapTable[mainPosition.x+1][mainPosition.y][0] == 'd')
                            {dKeyDown(&mainPosition);
                            Papercraft=&rP;}
                        start = true;
                break;

            }

            if (start)//Ne pas actualiser l'écran tant qu'une touche n'a pas été pressée.
            {
                screen = displayLoop(screen, xC, yC, zC, mapTable, xSize, ySize, position, mainPosition, &map[0], Papercraft);
                SDL_Flip(screen);
            }


        }

    }
    ///Fin de la boucle.

    ///Libération de la mémoire.
    for (x=0;x<15;x++)
    {
        SDL_FreeSurface(map[x]);
    }
    SDL_FreeSurface(uP);
    SDL_FreeSurface(dP);
    SDL_FreeSurface(rP);
    SDL_FreeSurface(lP);
}
