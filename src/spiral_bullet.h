#ifndef SPIRAL_BULLET
#define SPIRAL_BULLET

#include "bullet.h"
#include "raylib.h"

extern Texture2D t_spiralBullet;

class SpiralBullet : public Bullet {

public:
    SpiralBullet(int=0, int=0, Vec2=Vec2(0,0));
    ~SpiralBullet();

    void step() override;
    void draw() const override;
    

private:
    int sprScale = 4;
    float turn = 0.01;
};
#endif