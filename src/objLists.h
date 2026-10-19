#ifndef OBJ_LISTS
#define OBJ_LISTS

#include "player.h"
#include "bullet.h"
#include "asteroid.h"
#include "ast_piece.h"
#include "star.h"
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
void bulDestroy();
extern std::vector<Destroyable*> allDestroys;
void destStep();
void destDraw();
void destDestroy();



#endif