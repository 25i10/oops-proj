#ifndef OBJ_LISTS
#define OBJ_LISTS

#include "player.h"
#include "straight_bullet.h"
#include "plr_bullet.h"
#include "asteroid.h"
#include "ast_piece.h"
#include "star.h"
#include "follower.h"
#include "basicshot.h"
#include <vector>

void playerColl(Player &);

extern std::vector<Star *> allStars;
void starGen();
void starStep();
void starDraw();
void starDestroy();
extern std::vector<Bullet*> allBullets;
void bulStep();
void bulDraw();
void spawnBullet(Vec2 = Vec2(0,0), Vec2 = Vec2(0,0), int=0);
void bulDestroy();
extern std::vector<Destroyable*> allDestroys;
void destStep(Player &);
void destDraw();
void destDestroy();
int astCount();
int shootCount();



#endif