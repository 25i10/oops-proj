#include "destroyable.h"
#include <raylib.h>

Destroyable::Destroyable(int x, int y):Entity(x,y,1){
    dir = Vec2(0,1);
}

Destroyable::~Destroyable(){}

bool Destroyable::collide(const Hitbox & e) const{
    return h.intersect(e);
}

void Destroyable::destroy(){
    active = false;
}

bool Destroyable::isActive() const{
    return active;
}