#ifndef DESTR
#define DESTR

#include "entity.h"

class Destroyable : public Entity {

public:
    Destroyable(int=0, int=0);
    ~Destroyable();

    void draw() const override;
    bool collide(const Hitbox &) const;

private:
    
};

#endif