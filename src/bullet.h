#ifndef BULLET
#define BULLET

#include "entity.h"
#include <raylib.h>

extern Texture2D t_plrBullet;
extern Texture2D t_Bullet1;

class Bullet : public Entity {

public:
    Bullet(int=0, int=0, int=1, bool=false);
    virtual ~Bullet();

    void step() override;
    void draw() const override;
    bool isActive() const;
    

private:
    bool active = true;
};
#endif