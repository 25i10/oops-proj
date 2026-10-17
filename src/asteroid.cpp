#include "asteroid.h"

Texture2D t_asteroid;

Asteroid::Asteroid(int x, int y):Destroyable(x,y){
    sprDims = sprScale * Vec2(t_asteroid.width,t_asteroid.height);
    spdRot = GetRandomValue(1,6);

    active = true;
    spd = GetRandomValue(2,4);

    //Hardcoded hitbox
    Vec2 hDim(50,50);
    h = Hitbox(pos[0]-hDim[0]/2, pos[1]-hDim[1]/2, hDim[0], hDim[1]);
}

Asteroid::~Asteroid(){
    //std::cout << "Destructor called";
}

void Asteroid::step(){
    pos += spd * dir;    
    
    h.moveCorner(pos - h.getDims()/2);

    const int screenHeight = GetScreenHeight();
    if(pos[1] > screenHeight+128) active = false;
}



void Asteroid::draw() const{    
    DrawTexturePro(t_asteroid,(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0],pos[1],sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},GetTime()*spdRot*50*PI,WHITE);
    Entity::draw();
}
