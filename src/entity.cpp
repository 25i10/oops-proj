#include "entity.h"
#include "raylib.h"

Entity::Entity(int x, int y, int s):pos(x,y){
    dir = Vec2(1,0);
    spd = s;
}

Entity::~Entity(){}

void Entity::step(){
    pos += spd * dir;
}

Hitbox Entity::getH() const{return h;}

void Entity::draw() const{
    //DrawCircle(pos[0], pos[1], 20, WHITE);
    //h.draw();
}