#include "objLists.h"
#include "raylib.h"
#include <iostream>

int score;
SmokeGen SM;
bulController BC;
destController DC;


void destController::playerColl(Player & p){
    if(p.iFrame()) return;
    for(std::size_t i = 0; i<BC.getSize(); i++){
        Bullet *f = BC.getIndex(i);

        if(PlrBullet* s = dynamic_cast<PlrBullet *>(f)){
            s = nullptr;
            continue;
        } else s = nullptr;
        
        if(p.collide(f->getH())) {
            f->destroy();

            p.hurt();
        }
    }
    for(std::size_t i = 0; i<DC.getSize(); i++){
        Destroyable *f = DC.getVec()[i];
        
        if(p.collide(f->getH())) {
            f->destroy();

            p.hurt();
        }
    }

}



void bulController::step(){
    for(std::size_t i = 0; i < BC.getSize(); i++){
        Bullet *e = allBullets[i];

        if(Spiralspread_bullet* k = dynamic_cast<Spiralspread_bullet *>(e)){
            for(std::size_t j = 0; j<BC.getSize(); j++){
                Bullet *f = BC.getIndex(j);

                if(PlrBullet* s = dynamic_cast<PlrBullet *>(f)) s = nullptr;
                else {
                    s = nullptr;
                    continue;
                }

                if(e->getH().intersect(f->getH())) {
                    f->destroy();
                    e->destroy();
                    break;
                }
                f = nullptr;
            }
            k = nullptr;
        }

        if(!e->isActive()) {
            delete allBullets[i];
            allBullets.erase(allBullets.begin() + i);
            if(i >= BC.getSize()) i = BC.getSize()-1;
            if (BC.getSize() == 0) {
                e = nullptr;
                break;
            }
            e = allBullets[i];
        }

        e->step();
        e->draw();

        e=nullptr;
    }
}

void bulController::draw(){
    for(Bullet* i : allBullets){
        i->draw();
    }
}

void bulController::destroy(){
    for(Bullet* e : allBullets){
        delete e;
    }
    allBullets.clear();
}

std::size_t bulController::getSize() const{
    return allBullets.size();
}

Bullet* bulController::getIndex(int i) const{
    return allBullets[i];
}

void bulController::spawnBullet(Vec2 pos, Vec2 dir, int type){
    switch(type){
        case 0:
        allBullets.push_back(new PlrBullet(pos[0],pos[1]-28,dir));
        break;

        case 1:
        allBullets.push_back(new StraightBullet(pos[0],pos[1],dir));
        break;

        case 2:
        allBullets.push_back(new Spiralspread_bullet(pos[0],pos[1],dir));
        break;

        case 3:
        allBullets.push_back(new SpiralBullet(pos[0],pos[1],dir));
        break;

        default:
        break;
    }
}



void starController::gen(){
    static bool s = true;
    const int screenWidth = GetScreenWidth();
    if( s )allStars.push_back(new Star(GetRandomValue(0,screenWidth),-10));
    s = !s;
}

void starController::step(){
    for(std::size_t i = 0; i < allStars.size(); i++){
        Star *e = allStars[i];

        if(!e->isActive()) {
            delete allStars[i];
            allStars.erase(allStars.begin() + i);
            continue;
        }

        e->step();
        e->draw();

        e=nullptr;
    }
}

void starController::draw(){
    for(Star* i : allStars){
        i->draw();
    }
}

void starController::destroy(){
    for(Star* e : allStars){
        delete e;
    }
    allStars.clear();
}





void destController::step(Player & p){
    for(std::size_t i = 0; i < allDestroys.size(); i++){
        Destroyable *e = allDestroys[i];

        if(Follower* s = dynamic_cast<Follower *>(e)){
            s->turnToPoint(p.getPos());
        }


        if(!e->isActive()) {
            delete allDestroys[i];
            allDestroys.erase(allDestroys.begin() + i);
            if(i >= allDestroys.size()) i = allDestroys.size()-1;
            if (allDestroys.size() == 0) {
                e = nullptr;
                break;
            }
            e = allDestroys[i];
        }

        e->step();
        e->draw();

        for(std::size_t j = 0; j<BC.getSize(); j++){
            Bullet *f = BC.getIndex(j);

            if(PlrBullet* s = dynamic_cast<PlrBullet *>(f)) s = nullptr;
            else {
                s = nullptr;
                continue;
            }

            if(f->isActive() && e->collide(f->getH())) {
                f->destroy();

                e->hurt();
                break;
            }
            f = nullptr;
        }

        e=nullptr;
    }
}

int destController::astCount(){
    int a = 0;
    for(Destroyable *d : allDestroys){
        if(Asteroid* s = dynamic_cast<Asteroid *>(d)){
            a++;
            s = nullptr;
        } else s = nullptr;

        if(AstPiece* s = dynamic_cast<AstPiece *>(d)){
            a++;
            s = nullptr;
        } else s = nullptr;

        d=nullptr;
    }

    return a;
}

int destController::shootCount(){
    int a = 0;
    for(Destroyable *d : allDestroys){
        if(Shooters* s = dynamic_cast<Shooters *>(d)){
            a++;
            s = nullptr;
        } else s = nullptr;
    }
    return a;
}

std::size_t destController::getSize() const{
    return allDestroys.size();
}

bool destController::isEmpty() const{
    return allDestroys.empty();
}

std::vector<Destroyable*> & destController::getVec(){
    return allDestroys;
}

void destController::draw(){
    for(Destroyable* i : allDestroys){
        i->draw();
    }
}

void destController::destroy(){
    for(Destroyable* e : allDestroys){
        delete e;
    }
    allDestroys.clear();
}