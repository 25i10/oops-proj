#ifndef PLAYER
#define PLAYER

#include "entity.h"

class Player : public Entity {

public:
    Player(int=0, int=0);
    ~Player();

    void step() override;
    void draw() const override;
    bool collide(const Hitbox &) const;

private:
    int sprScale = 2;
};

#endif