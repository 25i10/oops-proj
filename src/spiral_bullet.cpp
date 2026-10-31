#include "spiral_bullet.h"


Texture2D t_spiralBullet;

SpiralBullet::SpiralBullet(int x, int y, Vec2 _dir):Bullet(x,y,5,_dir){
    dir = _dir.rotated(GetRandomValue(-1,1)/100.0);

    sprDims = sprScale * Vec2(t_spiralBullet.width,t_spiralBullet.height);
    Vec2 hDim(sprDims[0]-8,sprDims[1]-8);
    h = Hitbox(pos[0]-hDim[0]/2, pos[1]-hDim[1]/2, hDim[0], hDim[1],-2);
}

SpiralBullet::~SpiralBullet(){}

void SpiralBullet::step(){
    Bullet::step();

    dir = dir.rotated(turn);
    turn *= 0.99;
}


void SpiralBullet::draw() const{
    DrawTexturePro(t_spiralBullet,(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0],pos[1],sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},dir.angle()*180/PI,Color{200,0,0,255});
    Entity::draw();
}