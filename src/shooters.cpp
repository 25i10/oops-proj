#include "shooters.h"
#include "objLists.h"

Shooters::Shooters(int x, int y):Destroyable(x,-32){
    active = true;
}

Shooters::~Shooters(){}

void Shooters::step(){
    if(pos[1] < minY){
        pos += 2 * dir;
    } else {
        shotTim++;
        if(shotTim >= maxShotTim){
            shoot();
        }
    }
    h.moveCorner(pos - h.getDims()/2);
}

void Shooters::shoot(){
    shotTim = GetRandomValue(-1,1);
}

void Shooters::destroy(){

    Destroyable::destroy();
}


void Shooters::draw() const{
    Entity::draw();
}
