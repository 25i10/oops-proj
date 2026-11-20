#ifndef OBJ_LISTS
#define OBJ_LISTS

#include "player.h"
#include "smoke.h"

#include "straight_bullet.h"
#include "plr_bullet.h"
#include "spiralspread_bullet.h"
#include "spiral_bullet.h"

#include "asteroid.h"
#include "ast_piece.h"

#include "star.h"

#include "follower.h"
#include "basicshot.h"
#include "bigshot.h"

#include <vector>



class starController{
private:
    std::vector<Star *> allStars;
public:
    void gen();
    void step();
    void draw();
    void destroy();
};

class bulController{
private:
    std::vector<Bullet*> allBullets;
public:
    void step();
    void draw();
    void spawnBullet(Vec2 = Vec2(0,0), Vec2 = Vec2(0,0), int=0);
    void destroy();

    std::size_t getSize() const;
    Bullet * getIndex(int) const;
};

class destController{
private:
    std::vector<Destroyable*> allDestroys;
public:
    void step(Player &);
    void draw();
    void destroy();
    std::vector<Destroyable*> & getVec();
    
    bool isEmpty() const;
    std::size_t getSize() const;
    int astCount();
    int shootCount();
    void playerColl(Player &);
};


extern int score;
extern SmokeGen SM;
extern bulController BC;
extern destController DC;
#endif