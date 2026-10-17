#ifndef PLAYER
#define PLAYER

#include "entity.h"
#include <raylib.h>

extern Texture2D t_player;
class Player : public Entity {

public:
    Player(int=0, int=0);
    ~Player();

    void step() override;
    void draw() const override;
    bool collide(const Hitbox &) const;
    Vec2 getPos() const;

private:
    bool shot;
};

#endif