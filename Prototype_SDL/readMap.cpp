#include <iostream>
#include <fstream>
#include <string>
#include "readMap.h"

void readMap(int *xMaxOutput, int* yMaxOutput, int* zMaxOutput, string* dataOutput, int* xSizeOutput, int* ySizeOutput)
{
    ifstream flux("files/map_01.map");



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
