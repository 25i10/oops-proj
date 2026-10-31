#include "plr_bullet.h"


Texture2D t_plrBullet [2];

PlrBullet::PlrBullet(int x, int y, Vec2 _dir):Bullet(x,y,10,_dir){
    var = GetRandomValue(0,1);

    sprDims = sprScale * Vec2(t_plrBullet[var].width,t_plrBullet[var].height);
    Vec2 hDim(sprDims[0]-8,sprDims[1]);
    h = Hitbox(pos[0]-hDim[0]/2, pos[1]-hDim[1]/2, hDim[0], hDim[1],2);
}

PlrBullet::~PlrBullet(){}




void PlrBullet::draw() const{
    DrawTexturePro(t_plrBullet[var],(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0],pos[1],sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},-90,WHITE);
    Entity::draw();
}