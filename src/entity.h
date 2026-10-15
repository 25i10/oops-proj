#ifndef ENTITY
#define ENTITY

#include "vec2.h"

class Entity {

public:
    Entity(int=0, int=0, int=1);
    virtual ~Entity();

    virtual void step();
    virtual void draw() const;
    

protected:
    int spd;
    Vec2 pos;
    Vec2 dir;
};
#endif