#ifndef BULLET
#define BULLET

#include "entity.h"
#include "raylib.h"

class Bullet : public Entity {

public:
    Bullet(int=0, int=0, int=0, Vec2=Vec2(0,0));
    virtual ~Bullet();

    void step() override;
    //void draw() const override;
    bool isActive() const;
    void destroy();
    

protected:
    bool active = true;
};
#endif