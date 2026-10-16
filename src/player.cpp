#include "player.h"
#include <raylib.h>
#include <iostream>

Texture2D t;


Player::Player(int x, int y):Entity(x,y,8){
    t = LoadTexture("res/plr.png");
    sprDims = sprScale * Vec2(t.width,t.height);

    //Hardcoded hitbox
    Vec2 hDim(50,40);
    h = Hitbox(pos[0]-hDim[0]/2, pos[1]-hDim[1]/2, hDim[0], hDim[1],0,10);

    //std::cout << h.getDims();
}

Player::~Player(){
    UnloadTexture(t);
}

void Player::step(){
    dir = Vec2(IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT),IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)).norm();
    pos += spd/(1 + IsKeyDown(KEY_X)) * dir;
    
    h.moveCorner(pos - h.getDims()/2 + h.getOffset());

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    if(pos[0]+32 > screenWidth) pos[0] = screenWidth-32;
    if(pos[0]-32 < 0) pos[0] = 32;

    if(pos[1]+32 > screenHeight) pos[1] = screenHeight-32;
    if(pos[1]-32 < 0) pos[1] = 32;

    

}

bool Player::collide(const Hitbox & e) const{
    return h.intersect(e);
}

void Player::draw() const{
    DrawTextureEx(t,Vector2{pos[0] - sprDims[0]/2,pos[1]-sprDims[1]/2},0,sprScale,WHITE);
    h.draw();
}