#ifndef DESTR
#define DESTR

#include "entity.h"

class Destroyable : public Entity {

public:
    Destroyable(int=0, int=0);
    virtual ~Destroyable();

    bool collide(const Hitbox &) const;
    bool isActive() const;
    virtual void destroy();

protected:
    int sprScale = 2;
    bool active = false;
};
#endif