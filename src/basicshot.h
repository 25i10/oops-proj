#ifndef BASIC_SHOT
#define BASIC_SHOT

#include "shooters.h"
#include "raylib.h"

extern Texture2D t_shooter1;
class BasicShot : public Shooters {

public:
    friend class Player;

    BasicShot(int=0);
    ~BasicShot();

    //void step() override;
    void shoot() override;
    void draw() const override;

private:
};

#endif