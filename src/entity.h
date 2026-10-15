#pragma once
#include <iostream>
#include "vec2.h"

class Entity {

public:
    Entity(int=0, int=0);
    ~Entity();

    virtual void step();
    virtual void draw() const;
    

private:
    const int spd = 1;
    Vec2 pos;
    Vec2 dir;
};