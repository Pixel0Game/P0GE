#ifndef READMAP_INCLUDED
#define READMAP_INCLUDED

    #include <SDL.h>
    #include <SDL_image.h>
    #include <string>

    using namespace std;
    void readMap(int* xMaxOutput, int* yMaxOutput, int* zMaxOutput, string* dataOutput, int* xSizeOutput, int* ySizeOutput);//Lit le fichier Map
    void readObject(SDL_Surface** sprite, int* x, int* y, int* z, bool* solid, char* id);


#endif // READMAP_INCLUDED
