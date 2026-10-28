#ifndef PLAYER
#define PLAYER

#include "entity.h"
#include "raylib.h"

extern Texture2D t_player;
class Player : public Entity {

public:
    Player(int=0, int=0);
    ~Player();

    void step() override;
    void draw() const override;
    bool collide(const Hitbox &) const;
    void destroy();
    void reset();
    bool isActive() const;
    Vec2 getPos() const;

private:
    bool shot;
    int shotTim = 0;
    Vec2 initPos;
    bool active = true;
};

#endif