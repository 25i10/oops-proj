#include "destroyable.h"
#include <raylib.h>
#include <iostream>


Destroyable::Destroyable(int x, int y):Entity(x,y,1){}

Destroyable::~Destroyable(){}

bool Destroyable::collide(const Hitbox & e) const{
    return h.intersect(e);
}

void Destroyable::draw() const{
    DrawCircle(pos[0], pos[1], 20, WHITE);
    h.draw();
}