#ifndef ENTITY
#define ENTITY

#include "vec2.h"
#include "hitbox.h"

class Entity {

public:
    Entity(int=0, int=0, int=1);
    virtual ~Entity();

    virtual void step();
    virtual void draw() const;
    Hitbox getH() const;
    

protected:
    int spd;
    Vec2 pos;
    Vec2 dir;
    Vec2 sprDims;
    int sprScale = 2;
    Hitbox h;
};
#endif