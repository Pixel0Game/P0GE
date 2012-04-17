#include <SDL.h>
#include <SDL_image.h>
#include "display.h"
#include "control.h"
#include "Block.h"
#include "readFile.h"

void mainLoop(SDL_Surface* screen, int x, int y, const int xC, const int yC, const int zC, int*** mapTable, int xSize, int ySize)
{
    ///Chargement des images
        SDL_Surface* map [15] = {NULL};
        map[0] = IMG_Load("graph/Pac/Wall.png");
        map[1] = IMG_Load("graph/Pac/Coin.png");
            SDL_Surface* tmp = IMG_Load("graph/Pac/Glass.png");
        map[2] = SDL_DisplayFormat(tmp);
            SDL_FreeSurface(tmp);
        SDL_Surface* uP = IMG_Load("graph/Pac/Main/Up.png");
        SDL_Surface* dP = IMG_Load("graph/Pac/Main/Down.png");
        SDL_Surface* rP = IMG_Load("graph/Pac/Main/Right.png");
        SDL_Surface* lP = IMG_Load("graph/Pac/Main/Left.png");
        SDL_Surface** Papercraft = &uP;
        Block glass(1,1,1,true,map[2]);

    ///Fin.

    ///Initialisation des positions.
        SDL_Rect position;
            position.x = (0);
            position.y = (0);
        SDL_Rect mainPosition;
            mainPosition.x = x;
            mainPosition.y = y;
    ///Fin.
    int score(0);
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
                    {
                        switch (mapTable[mainPosition.x][mainPosition.y+1][0])
                        {
                            case '0':
                                sKeyDown(&mainPosition);
                                Papercraft = &dP;
                                break;
                            case 'c':
                                sKeyDown(&mainPosition);
                                Papercraft = &dP;
                                score++;
                                mapTable[mainPosition.x][mainPosition.y][0] = '0';
                                break;
                        }
                    }
                    if (event.key.keysym.sym == SDLK_KP8)
                    {
                        switch(mapTable[mainPosition.x][mainPosition.y-1][0])
                        {
                            case '0':
                                zKeyDown(&mainPosition);
                                Papercraft =&uP;
                                break;
                            case 'c':
                                zKeyDown(&mainPosition);
                                Papercraft =&uP;
                                score++;
                                mapTable[mainPosition.x][mainPosition.y][0] = '0';
                                break;
                        }
                    }
                    if (event.key.keysym.sym == SDLK_KP4)
                    {
                        switch (mapTable[mainPosition.x-1][mainPosition.y][0])
                        {
                            case '0':
                                qKeyDown(&mainPosition);
                                Papercraft =&lP;
                                break;
                            case 'c':
                                qKeyDown(&mainPosition);
                                Papercraft =&lP;
                                score++;
                                mapTable[mainPosition.x][mainPosition.y][0] = '0';
                                break;
                        }
                    }
                    if (event.key.keysym.sym == SDLK_KP6)
                    {
                        switch(mapTable[mainPosition.x+1][mainPosition.y][0])
                        {
                            case '0':
                                dKeyDown(&mainPosition);
                                Papercraft=&rP;
                                break;
                            case 'c':
                                dKeyDown(&mainPosition);
                                Papercraft=&rP;
                                score++;
                                mapTable[mainPosition.x][mainPosition.y][0] = '0';
                                break;
                        }
                    }
                        start = true;
                break;

            }

            if (start)//Ne pas actualiser l'écran tant qu'une touche n'a pas été pressée.
            {
                screen = displayLoop(screen, xC, yC, zC, mapTable, xSize, ySize, position, mainPosition, &map[0], Papercraft, score, glass);
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
