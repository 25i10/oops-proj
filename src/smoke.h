#ifndef SMOKE
#define SMOKE

#include "raylib.h"
#include "vec2.h"
#include <vector>

extern Texture2D t_smoke;

class Smoke {
public:
    Smoke(Vec2, Vec2, int);
    ~Smoke();

    void stepDraw();
    bool isActive() const;

private:
    int lifetime;
    int life;
    Vec2 pos;
    Vec2 dir;
    int spd;
    Vec2 sprDims;
    bool active = true;
    int col;
};

class SmokeGen{
private:
    std::vector<Smoke *> l;

public:
    SmokeGen();
    ~SmokeGen();

    void smokeBurst(int, int, int=0);
    void step();
};

#endif