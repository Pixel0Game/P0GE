#include <iostream>
#include <fstream>
#include <string>
#include "readMap.h"

void readMap(int *xMaxOutput, int* yMaxOutput, int* zMaxOutput, string* dataOutput, int* xSizeOutput, int* ySizeOutput)
{
    ifstream flux("files/map_03/map_03.map");

    if (flux)
    {
        flux >> *xMaxOutput;
        flux >> *yMaxOutput;
        flux >> *zMaxOutput;
        flux >> *xSizeOutput;
        flux >> *ySizeOutput;
        flux >> *dataOutput;
    }
    else
    {
        cout << "Erreur à l'ouverture du fichier.";
    }
}


void readObject(SDL_Surface** sprite, int* x, int* y, int* z, bool* solid, char* id)
{
    ifstream flux("files/map_03/map_03.obj");
    string text;
    int done(0);

    if (flux)
    {
        while(done == 5)
        {
            flux>>text;
            if (text == "id:")
            {
                flux>>text;
                if (text.c_str() == id)
                {
                    flux>>text;
                    if (text == "x:")
                    {
                        flux>>*x;
                        done++;
                    }
                    if (text == "y:")
                    {
                        flux>>*y;
                        done++;
                    }
                    if (text == "z:")
                    {
                        flux>>*z;
                        done++;
                    }
                    if (text == "solid:")
                    {
                        flux>>text;
                        if(text == "1")
                        {*solid =true;}
                        else
                        {*solid =false;}
                        done++;
                    }
                    if (text == "sprite:")
                    {
                        flux>>text;
                        const char* adr = text.c_str();
                        *sprite=IMG_Load(adr);
                        done++;
                    }
                }
            }
        }
    }
}
