#include "player.h"
#include "objLists.h"

Texture2D t_player;
Texture2D t_heart;

Player::Player(int x, int y):Entity(x,y,8),initPos(x,y){
    sprDims = sprScale * Vec2(t_player.width,t_player.height);
    shot = false;

    //Hardcoded hitbox
    Vec2 hDim(50,40);
    h = Hitbox(pos[0]-hDim[0]/2, pos[1]-hDim[1]/2, hDim[0], hDim[1],0,10);

    
}

Player::~Player(){}

void Player::reset(){
    pos = initPos;
    health = 3;
    active = true;
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

    h.moveCorner(pos - h.getDims()/2);
    

    if(IsKeyDown(KEY_SPACE)){
        shotTim++;
        if(shotTim >= 12){
            shotTim = 0;
            BC.spawnBullet(pos,Vec2(0,-1),0);
        }
    }

    if(IsKeyPressed(KEY_SPACE)) {
        shotTim = 0;
        BC.spawnBullet(pos,Vec2(0,-1),0);
    }

    if(iTime > 0){
        if(iTime % 3 ==0) visible = !visible;
        iTime--;
        if(iTime == 0) visible = true;
    }
}

void Player::hurt(){
    if(health != 0){
        iTime = 80;
        health--;
    }
    else destroy();
}

bool Player::iFrame() const{
    return iTime>0;
}

void Player::destroy(){
    active = false;
}

bool Player::isActive() const{
    return active;
}

Vec2 Player::getPos() const {
    return pos;
}


bool Player::collide(const Hitbox & e) const{
    return h.intersect(e);
}

void Player::draw() const{
    if(visible) DrawTextureEx(t_player,Vector2{pos[0] - sprDims[0]/2,pos[1]-sprDims[1]/2},0,sprScale,WHITE);

    if(health >= 1) DrawTextureEx(t_heart,Vector2{800-64,900-64},0,1,WHITE);
    if(health >= 2) DrawTextureEx(t_heart,Vector2{800-96,900-64},0,1,WHITE);
    if(health >= 3) DrawTextureEx(t_heart,Vector2{800-128,900-64},0,1,WHITE);

    Entity::draw();
}