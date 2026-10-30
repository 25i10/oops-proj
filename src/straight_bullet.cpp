#include "straight_bullet.h"


Texture2D t_strBullet [2];

StraightBullet::StraightBullet(int x, int y, Vec2 _dir):Bullet(x,y,8,_dir){
    var = GetRandomValue(0,1);

    sprDims = sprScale * Vec2(t_strBullet[var].width,t_strBullet[var].height);
    Vec2 hDim(sprDims[0]-8,sprDims[1]);
    h = Hitbox(pos[0]-hDim[0]/2, pos[1]-hDim[1]/2, hDim[0], hDim[1],-2);
}

StraightBullet::~StraightBullet(){}


void StraightBullet::destroy(){
    active = false;
}


void StraightBullet::draw() const{
    DrawTexturePro(t_strBullet[var],(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0],pos[1],sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},dir.angle()*180/PI,Color{200,0,0,255});
    Entity::draw();
}