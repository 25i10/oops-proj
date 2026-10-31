#include "bullet.h"


Bullet::Bullet(int x, int y, int s, Vec2 _dir):Entity(x,y,s){
    
    dir = _dir;
    
}

Bullet::~Bullet(){}

void Bullet::step(){
    pos += spd * dir;
    h.moveCorner(pos - h.getDims()/2);

    const int screenHeight = GetScreenHeight();
    const int screenWidth = GetScreenWidth();
    if(pos[1] > screenHeight+10 || pos[1] < -10) active = false;
    if(pos[0] > screenWidth+10 || pos[0] < -10) active = false;
}

bool Bullet::isActive() const{
    return active;
}

void Bullet::destroy(){
    active = false;
}
