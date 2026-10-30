#ifndef STRAIGHT_BULLET
#define STRAIGHT_BULLET

#include "bullet.h"
#include "raylib.h"

extern Texture2D t_strBullet [2];


class StraightBullet : public Bullet {

public:
    StraightBullet(int=0, int=0, Vec2=Vec2(0,0));
    ~StraightBullet();

    //void step() override;
    void draw() const override;
    void destroy();
    

private:
    int sprScale = 4;
    int var;
};
#endif