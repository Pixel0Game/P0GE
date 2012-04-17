#ifndef PNJ_H_INCLUDED
#define PNJ_H_INCLUDED

    #include <SDL.h>
    #include <string>
    using namespace std;

class Character
{
    public:

    Character(int x, int y, SDL_Surface* spr,string name);
    ~Character();
    int getPosX() const;
    int getPosY() const;
    SDL_Surface* getSprite() const;
    bool testProx(int x, int y);
    void talkTo();

    private:

    int xPos;
    int yPos;
    SDL_Surface* sprite;
    string Name;
};

#endif // PNJ_H_INCLUDED
