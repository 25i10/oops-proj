#include "objLists.h"
#include "raylib.h"

std::vector<Bullet*> allBullets;
std::vector<Destroyable*> allDestroys;
std::vector<Star*> allStars;

void playerColl(Player & p){
    for(std::size_t i = 0; i<allBullets.size(); i++){
        Bullet *f = allBullets[i];

        if(f->getType() == 0) continue;
        
        if(p.collide(f->getH())) {
            f->destroy();
            delete allBullets[i];
            allBullets.erase(allBullets.begin() + i);

            p.destroy();
        }
    }
    for(std::size_t i = 0; i<allDestroys.size(); i++){
        Destroyable *f = allDestroys[i];
        
        if(p.collide(f->getH())) {
            f->destroy();
            delete allDestroys[i];
            allDestroys.erase(allDestroys.begin() + i);

            p.destroy();
        }
    }

}



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

void bulDraw(){
    for(Bullet* i : allBullets){
        i->draw();
    }
}

void bulDestroy(){
    for(Bullet* e : allBullets){
        delete e;
    }
    allBullets.clear();
}




void starGen(){
    static bool s = true;
    const int screenWidth = GetScreenWidth();
    if( s )allStars.push_back(new Star(GetRandomValue(0,screenWidth),-10));
    s = !s;
}

void starStep(){
    for(std::size_t i = 0; i < allStars.size(); i++){
        Star *e = allStars[i];

        if(!e->isActive()) {
            delete allStars[i];
            allStars.erase(allStars.begin() + i);
            continue;
        }

        e->step();
        e->draw();

    }
}

void starDraw(){
    for(Star* i : allStars){
        i->draw();
    }
}

void starDestroy(){
    for(Star* e : allStars){
        delete e;
    }
    allStars.clear();
}





void destStep(){
    for(std::size_t i = 0; i < allDestroys.size(); i++){
        Destroyable *e = allDestroys[i];


        if(!e->isActive()) {
            delete allDestroys[i];
            allDestroys.erase(allDestroys.begin() + i);
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

void destDraw(){
    for(Destroyable* i : allDestroys){
        i->draw();
    }
}

void destDestroy(){
    for(Destroyable* e : allDestroys){
        delete e;
    }
    allDestroys.clear();
}