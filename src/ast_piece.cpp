#include "ast_piece.h"

Texture2D t_astPiece [4];

AstPiece::AstPiece(int x, int y, int f, Vec2 _d):Destroyable(x,y){
    dir = _d;
    frame = f;
    sprDims = sprScale * Vec2(t_astPiece[frame].width,t_astPiece[frame].height);

    active = true;
    spd = GetRandomValue(4,6)/2;

    //Hardcoded hitbox
    Vec2 hDim(28,30);
    h = Hitbox(pos[0]-hDim[0]/2, pos[1]-hDim[1]/2, hDim[0], hDim[1]);
}

AstPiece::~AstPiece(){
    //std::cout << "Destructor called";
}

void AstPiece::step(){
    pos += spd * dir;    
    
    h.moveCorner(pos - h.getDims()/2);

    const int screenHeight = GetScreenHeight();
    const int screenWidth = GetScreenWidth();
    if(pos[1] > screenHeight+30 || pos[1] < -30 || pos[0] < -30 || pos[0] > screenWidth+30) active = false;
}



void AstPiece::draw() const{    
    //DrawTexturePro(t_AstPiece,(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0],pos[1],sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},GetTime()*spdRot*50*PI,WHITE);
    DrawTexturePro(t_astPiece[frame],(Rectangle){0,0,sprDims[0]/sprScale,sprDims[1]/sprScale},(Rectangle){pos[0],pos[1],sprDims[0],sprDims[1]},Vector2{sprDims[0]/sprScale,sprDims[1]/sprScale},0,WHITE);
    Entity::draw();
}
