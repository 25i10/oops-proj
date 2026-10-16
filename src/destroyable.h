#ifndef DESTR
#define DESTR

#include "entity.h"

class Destroyable : public Entity {

public:
    Destroyable(int=0, int=0);
    virtual ~Destroyable();

    bool collide(const Hitbox &) const;
    bool isActive() const;

protected:
    bool active = false;
};
#endif