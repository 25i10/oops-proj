#include "objLists.h"

#include <raylib.h>

std::vector<Bullet*> allBullets;
std::vector<Asteroid*> allAsteroids;

void bulStep(){
    for(std::size_t i = 0; i < allBullets.size(); i++){
        Bullet *e = allBullets[i];

        if(!e->isActive()) {
            delete allBullets[i];
            allBullets.erase(allBullets.begin() + i);
            continue;
        }

        e->step();
        e->draw();

    }
}

void bulDestroy(){
    for(Bullet* e : allBullets){
        delete e;
    }
    allBullets.clear();
}



void astStep(){
    for(std::size_t i = 0; i < allAsteroids.size(); i++){
        Asteroid *e = allAsteroids[i];


        if(!e->isActive()) {
            delete allAsteroids[i];
            allAsteroids.erase(allAsteroids.begin() + i);
            continue;
        }


        e->step();
        e->draw();

        for(std::size_t j = 0; j<allBullets.size(); j++){
            Bullet *f = allBullets[j];

            if(f->getType() != 0) continue;

            if(e->collide(f->getH())) {
                f->destroy();
                delete allBullets[j];
                allBullets.erase(allBullets.begin() + j);

                e->destroy();
            }
        }
    }
}

void astDestroy(){
    for(Asteroid* e : allAsteroids){
        delete e;
    }
    allAsteroids.clear();
}