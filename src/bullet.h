#ifndef BULLET
#define BULLET

#include "entity.h"
#include "raylib.h"

extern Texture2D t_plrBullet [2];
extern Texture2D t_Bullet1;


class Bullet : public Entity {

public:
    Bullet(int=0, int=0, int=0);
    virtual ~Bullet();

    void step() override;
    void draw() const override;
    bool isActive() const;
    int getType() const;
    void destroy();
    

private:
    bool active = true;
    int sprScale = 3;
    int type;
    int var;
};
#endif