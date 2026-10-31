#ifndef PLR_BULLET
#define PLR_BULLET

#include "bullet.h"
#include "raylib.h"

extern Texture2D t_plrBullet [2];


class PlrBullet : public Bullet {

public:
    PlrBullet(int=0, int=0, Vec2=Vec2(0,0));
    ~PlrBullet();

    //void step() override;
    void draw() const override;
    

private:
    int sprScale = 3;
    int var;
};
#endif