#include "entity.h"
#include <raylib.h>

Entity::Entity(int x, int y, int s){
    pos[0] = x;
    pos[1] = y;
    dir = Vec2(1,0);
    spd = s;
}

Entity::~Entity(){}

void Entity::step(){
    pos += spd * dir;

    /*
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    
    if ((pos[0] >= screenWidth) || (pos[0] <= 0)) {
        dir[0] *= -1;
        pos -= 0.1*dir;
    }
    
    if ((pos[1] >= screenHeight) || (pos[1] <= 0)) {
        dir[1] *= -1;
        pos -= 0.1*dir;
    }
    */
}


void Entity::draw() const{
    DrawCircle(pos[0], pos[1], 20, WHITE);
}
