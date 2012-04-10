#include <iostream>
#include <string>
#include "readMap.h"
#include <SDL.h>
#include <SDL_image.h>
#include "display.h"
#include "event.h"

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

    ///Initialisation des variable de la map.
    int* zIn(NULL);
    int z(0);
    int *xIn(NULL);
    int *yIn(NULL);
    int x(0),y(0);
    int *xSizeIn(0);
    int *ySizeIn(0);
    int xSize(0), ySize(0);
    string *dataIn(0);
    string data(" ");

    xIn = &x;
    yIn = &y;
    zIn = &z;
    xSizeIn = &xSize;
    ySizeIn = &ySize;
    dataIn = &data;
    readMap(xIn, yIn, zIn, dataIn, xSizeIn, ySizeIn);
    int planeX(0);
    int planeY(0);

    const int xC = x;
    const int yC = y;
    const int zC = z;
    int i(0);
    int*** mapTable; mapTable = new int**[xC];
    for (x=0; x<xC; x++)
    {
        mapTable[x] = new int*[yC];
        for (y=0; y<yC; y++)
        {
            mapTable[x][y] = new int[zC];
        }
    }
    for(x=0; x<xC; x++)
    {
        for(y=0; y<yC; y++)
        {
            for(z=0; z<zC; z++)
            {
                if (data[i] == 'o')
                {
                    planeX = x;
                    planeY = y;
                    mapTable[x][y][z] = ('d');
                }
                else
                {
                    mapTable[x][y][z]= (data[i]);
                }
                i++;

            }
        }
    }

    ///Fonction d'affichage.
    mainLoop(screen, planeX, planeY, xC, yC, zC, mapTable, xSize, ySize);

    SDL_FreeSurface(screen);
    //Tout les voyants sont au vert !
    printf("Exited cleanly\n");
    return 0;
}
