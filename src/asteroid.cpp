#include "asteroid.h"
#include <raylib.h>
#include <iostream>

Texture2D aster;


Asteroid::Asteroid(int x, int y):Destroyable(x,y){
    aster = LoadTexture("res/rock.png");
    sprDims = sprScale * Vec2(aster.width,aster.height);
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
    
    
    h.moveCorner(pos - h.getDims()/2 + h.getOffset());

    const int screenHeight = GetScreenHeight();
    if(pos[1] > screenHeight+128) active = false;
}



void Asteroid::draw() const{    
    DrawTexturePro(aster,(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0],pos[1],sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},GetTime()*spdRot*50*PI,WHITE);

    //DrawTextureEx(aster,Vector2{pos[0] - sprDims[0]/2,pos[1]-sprDims[1]/2},0,sprScale,WHITE);
    h.draw();
}
