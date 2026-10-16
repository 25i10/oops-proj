#ifndef ASTEROID
#define ASTEROID

#include "destroyable.h"

class Asteroid : public Destroyable {

public:

    Asteroid(int=0, int=0);
    ~Asteroid();

    void step() override;
    void draw() const override;
    

private:
    int sprScale = 2;
    int spdRot;
};

#endif