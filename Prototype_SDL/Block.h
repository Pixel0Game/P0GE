#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include <SDL.h>


class Block
{
    public:

    Block(int x, int y, int z, bool sol, SDL_Surface* spr);
    ~Block();
    int getSizeX() const;
    int getSizeY() const;
    int getSizeZ() const;
    bool getSolid() const;
    SDL_Surface* getSprite() const;

    private:

    int sizeX;
    int sizeY;
    int sizeZ;
    bool solid;
    SDL_Surface* sprite;
};

#endif // BLOCK_H_INCLUDED
