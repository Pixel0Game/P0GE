#include <iostream>
#include <string>
#include "readMap.h"
#include <SDL.h>
#include <SDL_image.h>
#include "display.h"

using namespace std;

int main ( int argc, char** argv )
{
    ///Initialisation de la SDL
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "Unable to init SDL:" << SDL_GetError();
        return 1;
    }

    // Contrôle de la SDL à la fin du programme.
    atexit(SDL_Quit);

    ///Création de la surface screen
    SDL_Surface* screen = SDL_SetVideoMode(640, 480, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        cout << "Unable to set 640x480 video:" << SDL_GetError();
        return 1;
    }

    SDL_Surface* titleScreen = IMG_Load("graph/Titlescreen.jpeg");
    SDL_Rect title;
        title.x =0;
        title.y =0;
    SDL_BlitSurface(titleScreen, 0, screen, &title);
    SDL_Flip(screen);

    /// Création du tableau map
    //*

    int *xIn(0);
    int *yIn(0);
    int x(0),y(0);
    int *xSizeIn(0);
    int *ySizeIn(0);
    int xSize(0), ySize(0);
    string *dataIn(0);
    string data(" ");

    xIn = &x;
    yIn = &y;
    xSizeIn = &xSize;
    ySizeIn = &ySize;
    dataIn = &data;
    readMap(xIn, yIn, dataIn, xSizeIn, ySizeIn);
    int planeX(0);
    int planeY(0);

    int const xC = x;
    int const yC = y;
    int i(0);
    int mapTable[xC][yC];
    for(x=0; x<xC; x++)
    {
        for(y=0; y<yC; y++)
        {
            if (data[i] == 'o')
            {
                planeX = x;
                planeY = y;
                mapTable[x][y] = ('d');
            }
            else
            {
                mapTable[x][y]= (data[i]);
            }
            i++;

        }
    }

    ///Fonction d'affichage.
    displayLoop(screen, planeX, planeY, xC, yC, &mapTable[0][0], xSize, ySize);

    //Tout les voyants sont au vert !
    printf("Exited cleanly\n");
    return 0;
}
