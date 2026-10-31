#include "spiralspread_bullet.h"
#include "objLists.h"

Texture2D t_spBullet;

Spiralspread_bullet::Spiralspread_bullet(int x, int y, Vec2 _dir):Bullet(x,y,4,_dir){
    sprDims = sprScale * Vec2(t_spBullet.width,t_spBullet.height);
    Vec2 hDim(sprDims[0],sprDims[1]);
    h = Hitbox(pos[0]-hDim[0]/2, pos[1]-hDim[1]/2, hDim[0], hDim[1]);
}

Spiralspread_bullet::~Spiralspread_bullet(){}

void Spiralspread_bullet::step(){
    Bullet::step();

    if(pos[1] >= 270 && active) desAction();
}

void Spiralspread_bullet::desAction(){
    Bullet::destroy();

    //float a = GetRandomValue(-4,4)/10.0;
    float a = 0;

    spawnBullet(pos,Vec2(0,1).rotated(a),3);
    spawnBullet(pos,Vec2(0,-1).rotated(a),3);
    spawnBullet(pos,Vec2(1,0).rotated(a),3);
    spawnBullet(pos,Vec2(-1,0).rotated(a),3);
    spawnBullet(pos,Vec2(1,1).norm().rotated(a),3);
    spawnBullet(pos,Vec2(1,-1).norm().rotated(a),3);
    spawnBullet(pos,Vec2(-1,-1).norm().rotated(a),3);
    spawnBullet(pos,Vec2(-1,1).norm().rotated(a),3);

    a = PI/8;

    spawnBullet(pos,Vec2(0,1).rotated(a),3);
    spawnBullet(pos,Vec2(0,-1).rotated(a),3);
    spawnBullet(pos,Vec2(1,0).rotated(a),3);
    spawnBullet(pos,Vec2(-1,0).rotated(a),3);
    spawnBullet(pos,Vec2(1,1).norm().rotated(a),3);
    spawnBullet(pos,Vec2(1,-1).norm().rotated(a),3);
    spawnBullet(pos,Vec2(-1,-1).norm().rotated(a),3);
    spawnBullet(pos,Vec2(-1,1).norm().rotated(a),3);
}

void Spiralspread_bullet::draw() const{
    DrawTexturePro(t_spBullet,(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0]-8,pos[1]-8,sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},0,WHITE);
    Entity::draw();
}