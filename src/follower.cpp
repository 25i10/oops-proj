#include "follower.h"
#include "objLists.h"

Texture2D t_shooter2;

Follower::Follower(int x):Shooters(x,-32){
    sprDims = sprScale * Vec2(t_shooter2.width,t_shooter2.height);
    minY = 64;
    maxShotTim = 60;

    //Hardcoded hitbox
    Vec2 hDim(50,25);
    h = Hitbox(pos[0]-hDim[0]/2, pos[1]-hDim[1]/2, hDim[0], hDim[1],0,-10);
}

Follower::~Follower(){}



void Follower::shoot(){
    Vec2 bulPos = 20*(dir+Vec2(0.3,0)) + pos;
    allBullets.push_back(new Bullet(bulPos[0],bulPos[1],1,dir));
    
    Shooters::shoot();
}

void Follower::turnToPoint(Vec2 _p){
    if(pos[1] >= 64) dir = (_p - pos).norm();
}



void Follower::draw() const{    
    DrawTexturePro(t_shooter2,(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0],pos[1],sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},90+dir.angle()*180/PI,WHITE);
    Entity::draw();
}
