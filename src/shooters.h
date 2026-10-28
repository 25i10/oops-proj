#ifndef SHOOTERS
#define SHOOTERS

#include "destroyable.h"
#include "raylib.h"
#include "player.h"

class Shooters : public Destroyable {

public:
    friend class Player;

    Shooters(int=0, int=0);
    ~Shooters();

    void step() override;
    virtual void shoot();
    void draw() const override;
    void destroy() override;

protected:
    int maxShotTim;
    int minY;
    int shotTim = 0;
    //bool ready = false;
};

#endif