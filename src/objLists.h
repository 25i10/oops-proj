#ifndef OBJ_LISTS
#define OBJ_LISTS

#include "bullet.h"
#include "asteroid.h"
#include "ast_piece.h"
#include "star.h"
#include <vector>

extern std::vector<Star *> allStars;
void starGen();
void starStep();
void starDestroy();
extern std::vector<Bullet*> allBullets;
void bulStep();
void bulDestroy();
extern std::vector<Destroyable*> allDestroys;
void destStep();
void destDestroy();



#endif