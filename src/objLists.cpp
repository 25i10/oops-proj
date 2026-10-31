#include "objLists.h"
#include "raylib.h"
#include <iostream>

std::vector<Bullet*> allBullets;
std::vector<Destroyable*> allDestroys;
std::vector<Star*> allStars;

void playerColl(Player & p){
    for(std::size_t i = 0; i<allBullets.size(); i++){
        Bullet *f = allBullets[i];

        if(PlrBullet* s = dynamic_cast<PlrBullet *>(f)){
            s = nullptr;
            continue;
        } else s = nullptr;
        
        if(p.collide(f->getH())) {
            f->destroy();

            p.destroy();
        }
    }
    for(std::size_t i = 0; i<allDestroys.size(); i++){
        Destroyable *f = allDestroys[i];
        
        if(p.collide(f->getH())) {
            f->destroy();

            p.destroy();
        }
    }

}



void bulStep(){
    for(std::size_t i = 0; i < allBullets.size(); i++){
        Bullet *e = allBullets[i];

        if(Spiralspread_bullet* k = dynamic_cast<Spiralspread_bullet *>(e)){
            for(std::size_t j = 0; j<allBullets.size(); j++){
                Bullet *f = allBullets[j];

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
            if(i >= allBullets.size()) i = allBullets.size()-1;
            if (allBullets.size() == 0) {
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

void spawnBullet(Vec2 pos, Vec2 dir, int type){
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

        e=nullptr;
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





void destStep(Player & p){
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

        for(std::size_t j = 0; j<allBullets.size(); j++){
            Bullet *f = allBullets[j];

            if(PlrBullet* s = dynamic_cast<PlrBullet *>(f)) s = nullptr;
            else {
                s = nullptr;
                continue;
            }

            if(e->collide(f->getH())) {
                f->destroy();
                /*
                delete allBullets[j];
                allBullets.erase(allBullets.begin() + j);
                if(i >= allBullets.size()) i = allBullets.size()-1;
                if (allBullets.size() == 0) {
                    f = nullptr;
                    break;
                }
                */

                e->destroy();
                break;
            }
            f = nullptr;
        }

        e=nullptr;
    }
}

int astCount(){
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

int shootCount(){
    int a = 0;
    for(Destroyable *d : allDestroys){
        if(Shooters* s = dynamic_cast<Shooters *>(d)){
            a++;
            s = nullptr;
        } else s = nullptr;
    }
    return a;
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