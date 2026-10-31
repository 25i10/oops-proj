#ifndef SPIRALSPREAD_BULLET
#define SPIRALSPREAD_BULLET

#include "bullet.h"
#include "raylib.h"

extern Texture2D t_spBullet;


class Spiralspread_bullet : public Bullet {

public:
    Spiralspread_bullet(int=0, int=0, Vec2=Vec2(0,0));
    ~Spiralspread_bullet();

    void step() override;
    void draw() const override;
    void desAction();
    

private:
    int sprScale = 4;
};
#endif