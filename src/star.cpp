#include "star.h"

Texture2D t_star [7];

Star::Star(int x, int y):pos(x,y),dir(0,1){
    frame = GetRandomValue(0,6);

    sprDims = sprScale * Vec2(t_star[frame].width,t_star[frame].height);

    active = true;
    spd = GetRandomValue(12,15);
}

Star::~Star(){}

void Star::step(){
    pos += spd * dir;    

    const int screenHeight = GetScreenHeight();
    if(pos[1] > screenHeight+10) active = false;
}

bool Star::isActive() const{
    return active;
}


void Star::draw() const{    
    DrawTexturePro(t_star[frame],(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0],pos[1],sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},0,WHITE);
    //DrawCircle(pos[0], pos[1], frame/7, WHITE);
}
