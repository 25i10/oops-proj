#include "asteroid.h"
#include "ast_piece.h"
#include "objLists.h"

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

Asteroid::~Asteroid(){}

void Asteroid::step(){
    pos += spd * dir;    
    
    h.moveCorner(pos - h.getDims()/2);

    const int screenHeight = GetScreenHeight();
    if(pos[1] > screenHeight){
        dir *= -1;    
        destroy();
    }
}

void Asteroid::destroy(){
    allDestroys.push_back(new AstPiece(pos[0],pos[1],0,dir.rotated( GetRandomValue(10,30)/100.0 )));
    allDestroys.push_back(new AstPiece(pos[0],pos[1],1,dir.rotated(-GetRandomValue(10,30)/100.0)));
    allDestroys.push_back(new AstPiece(pos[0],pos[1],2,dir.rotated(-GetRandomValue(70,100)/100.0)));
    allDestroys.push_back(new AstPiece(pos[0],pos[1],3,dir.rotated(GetRandomValue(70,100)/100.0)));

    Destroyable::destroy();
}


void Asteroid::draw() const{    
    DrawTexturePro(t_asteroid,(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0],pos[1],sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},GetTime()*spdRot*50*PI,WHITE);
    Entity::draw();
}
