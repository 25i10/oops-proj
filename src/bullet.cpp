#include "bullet.h"
#define PLAYER 0
#define STRAIGHT 1


Texture2D t_plrBullet [2];
Texture2D t_Bullet1;

Bullet::Bullet(int x, int y, int _type, Vec2 _dir):Entity(x,y,1){
    var = GetRandomValue(0,1);
    type = _type;

    Vec2 hDim(sprDims[0]-8,sprDims[1]);
    h = Hitbox(pos[0]-hDim[0]/2, pos[1]-hDim[1]/2, hDim[0], hDim[1],2);

    if(type == PLAYER) {
        sprDims = sprScale * Vec2(t_plrBullet[var].width,t_plrBullet[var].height);
        spd = 11;
        dir = Vec2(0,-1);
    } else if(type == STRAIGHT) {
        sprScale = 4;
        sprDims = sprScale * Vec2(t_plrBullet[var].width,t_plrBullet[var].height);
        spd = 8;
        dir = _dir;
        h = Hitbox(pos[0]-hDim[0]/2, pos[1]-hDim[1]/2, hDim[0], hDim[1],-2);
    }

    
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
    if(type == PLAYER) DrawTexturePro(t_plrBullet[var],(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0],pos[1],sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},-90,WHITE);
    if(type == STRAIGHT) DrawTexturePro(t_plrBullet[var],(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0],pos[1],sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},dir.angle()*180/PI,Color{200,0,0,255});
    Entity::draw();
}