#ifndef STAR
#define STAR

#include <raylib.h>
#include "vec2.h"

extern Texture2D t_star [7];
class Star{

public:

    Star(int=0, int=0);
    ~Star();

    void step();
    void draw() const;
    bool isActive() const;
    

private:
    int spdRot;
    int frame;
    Vec2 pos;
    Vec2 dir;
    Vec2 sprDims;
    int sprScale = 1;
    int spd;
    bool active;
};

#endif