#include "bigshot.h"
#include "objLists.h"

Texture2D t_shooter3;

BigShot::BigShot(int x):Shooters(x,-32){
    sprDims = sprScale * Vec2(t_shooter3.width,t_shooter3.height);
    minY = 64;
    shotTim = 60;
    maxShotTim = 120;

    //Hardcoded hitbox
    Vec2 hDim(50,25);
    h = Hitbox(pos[0]-hDim[0]/2, pos[1]-hDim[1]/2, hDim[0], hDim[1],0,-10);
}

BigShot::~BigShot(){}



void BigShot::shoot(){
    Vec2 bulPos = pos + Vec2(0,12);
    spawnBullet(bulPos,dir,2);
    
    Shooters::shoot();
}



void BigShot::draw() const{    
    DrawTexturePro(t_shooter3,(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0],pos[1],sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},90+dir.angle()*180/PI,WHITE);
    Entity::draw();
}
