#ifndef PLAYER
#define PLAYER

#include "entity.h"
#include "raylib.h"

extern Texture2D t_player;
extern Texture2D t_heart;
class Player : public Entity {

public:
    Player(int=0, int=0);
    ~Player();

    void step() override;
    void draw() const override;
    bool collide(const Hitbox &) const;
    void destroy();
    void hurt();
    void reset();
    bool isActive() const;
    Vec2 getPos() const;
    bool iFrame() const;

private:
    bool shot;
    int shotTim = 0;
    Vec2 initPos;
    bool active = true;
    int health = 3;
    int iTime = 0;
    bool visible = true;
};

#endif