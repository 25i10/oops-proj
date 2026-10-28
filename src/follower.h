#ifndef FOLLOW_SHOT
#define FOLLOW_SHOT

#include "shooters.h"
#include "raylib.h"

extern Texture2D t_shooter2;
class Follower : public Shooters {

public:
    friend class Player;

    Follower(int=0);
    ~Follower();

    //void step() override;
    void turnToPoint(Vec2 = Vec2(0,0));
    void shoot() override;
    void draw() const override;

private:
};

#endif