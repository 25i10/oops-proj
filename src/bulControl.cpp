#include "bulControl.h"
#include <raylib.h>

std::vector<Bullet*> allBullets;

void bulMove(){
    for(std::size_t i = 0; i < allBullets.size(); i++){
        Bullet *e = allBullets[i];

        e->step();
        e->draw();

        if(!e->isActive()) {
            delete allBullets[i];
            allBullets.erase(allBullets.begin() + i);
        }
    }
}

void bulDestroy(){
    for(Bullet* e : allBullets){
        delete e;
    }
    allBullets.clear();
}
