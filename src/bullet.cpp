#include "bullet.h"


Bullet::Bullet(int x, int y, int s, Vec2 _dir):Entity(x,y,s){
    
    dir = _dir;

    /*
    else if(type == STRAIGHT) {
        sprScale = 4;
        sprDims = sprScale * Vec2(t_plrBullet[var].width,t_plrBullet[var].height);
        spd = 8;
        dir = _dir;
        h = Hitbox(pos[0]-hDim[0]/2, pos[1]-hDim[1]/2, hDim[0], hDim[1],-2);
    }
    */
    
}

Bullet::~Bullet(){}

void Bullet::step(){
    pos += spd * dir;
    h.moveCorner(pos - h.getDims()/2);

    const int screenHeight = GetScreenHeight();
    if(pos[1] > screenHeight+10 || pos[1] < -10) active = false;
}

bool Bullet::isActive() const{
    return active;
}

void Bullet::destroy(){
    active = false;
}
