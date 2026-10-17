#include "bullet.h"

Texture2D t_plrBullet;
Texture2D t_Bullet1;

Bullet::Bullet(int x, int y, int s, bool _plr):Entity(x,y,s){
    if(_plr) {
        sprDims = sprScale * Vec2(t_plrBullet.width,t_plrBullet.height);
        dir = Vec2(0,-1);
    }
}

Bullet::~Bullet(){}

void Bullet::step(){
    pos += spd * dir;
}

bool Bullet::isActive() const{
    return active;
}

void Bullet::draw() const{
    DrawCircle(pos[0], pos[1], 10, WHITE);
    h.draw();
}