#ifndef BIG_SHOT
#define BIG_SHOT

#include "shooters.h"
#include "raylib.h"

extern Texture2D t_shooter3;
class BigShot : public Shooters {

public:
    friend class Player;

    BigShot(int=0);
    ~BigShot();

    //void step() override;
    void shoot() override;
    void draw() const override;

private:
};

#endif