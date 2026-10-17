#include "bullet.h"
#define PLAYER 0


Texture2D t_plrBullet;
Texture2D t_Bullet1;

Bullet::Bullet(int x, int y, int _type):Entity(x,y,1){
    if(_type == PLAYER) {
        type = PLAYER;
        sprDims = sprScale * Vec2(t_plrBullet.width,t_plrBullet.height);
        spd = 11;
        dir = Vec2(0,-1);

    }

    Vec2 hDim(sprDims[0]-6,sprDims[1]);
    h = Hitbox(pos[0]-hDim[0]/2, pos[1]-hDim[1]/2, hDim[0], hDim[1]);
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

int Bullet::getType() const{
    return type;
}

void Bullet::draw() const{
    if(type == PLAYER) DrawTexturePro(t_plrBullet,(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0],pos[1],sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},-90,WHITE);
    h.draw();
}