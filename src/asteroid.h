#ifndef ASTEROID
#define ASTEROID

#include "destroyable.h"
#include <raylib.h>

extern Texture2D t_asteroid;
class Asteroid : public Destroyable {

public:

    Asteroid(int=0, int=0);
    ~Asteroid();

    void step() override;
    void draw() const override;
    void destroy() override;    

private:
    int spdRot;
};

#endif