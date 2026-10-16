#include "player.h"
#include <raylib.h>
#include <iostream>

Texture2D t;


Player::Player(int x, int y):Entity(x,y,8){
    t = LoadTexture("res/plr.png");
}

Player::~Player(){
    UnloadTexture(t);
}

void Player::step(){
    dir = Vec2(IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT),IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)).norm();
    pos += spd/(1 + IsKeyDown(KEY_X)) * dir;

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    if(pos[0]+32 > screenWidth) pos[0] = screenWidth-32;
    if(pos[0]-32 < 0) pos[0] = 32;

    if(pos[1]+32 > screenHeight) pos[1] = screenHeight-32;
    if(pos[1]-32 < 0) pos[1] = 32;

}

void Player::draw() const{
    DrawTextureEx(t,Vector2{pos[0]-32,pos[1]-32},0,2,WHITE);
}