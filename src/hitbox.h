#ifndef HITBOX
#define HITBOX

#include "vec2.h"

class Hitbox {

public:
    Hitbox(int=0, int=0, int=0, int=0, int=0, int=0);
    virtual ~Hitbox();

    void draw() const;
    void moveCorner(Vec2);
    Vec2 getCorner() const;
    Vec2 getDims() const;

    bool intersect(const Hitbox &) const;

//private:
    Vec2 corner;
    Vec2 dims;
    Vec2 offset;
};
#endif