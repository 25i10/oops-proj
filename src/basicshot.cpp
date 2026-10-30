#include "basicshot.h"
#include "objLists.h"

Texture2D t_shooter1;

BasicShot::BasicShot(int x):Shooters(x,-32){
    sprDims = sprScale * Vec2(t_shooter1.width,t_shooter1.height);
    minY = 64;
    maxShotTim = 60;

    //Hardcoded hitbox
    Vec2 hDim(50,25);
    h = Hitbox(pos[0]-hDim[0]/2, pos[1]-hDim[1]/2, hDim[0], hDim[1],0,-10);
}

BasicShot::~BasicShot(){}



void BasicShot::shoot(){
    Vec2 bulPos = 20*(dir+Vec2(0.3,0)) + pos;
    spawnBullet(bulPos,dir,1);
    
    Shooters::shoot();
}



void BasicShot::draw() const{    
    DrawTexturePro(t_shooter1,(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0],pos[1],sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},90+dir.angle()*180/PI,WHITE);
    Entity::draw();
}
