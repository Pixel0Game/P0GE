#include "Block.h"
using namespace std;

Block::Block(int x, int y, int z, bool sol, SDL_Surface* spr) : sizeX(x), sizeY(y), sizeZ(z), solid(sol), sprite(spr)
{

}

Block::~Block()
{

}

int Block::getSizeX() const
{
    return sizeX;
}

int Block::getSizeY() const
{
    return sizeY;
}

int Block::getSizeZ() const
{
    return sizeZ;
}

bool Block::getSolid() const
{
    return solid;
}

SDL_Surface* Block::getSprite() const
{
    return sprite;
}
