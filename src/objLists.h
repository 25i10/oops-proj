#ifndef OBJ_LISTS
#define OBJ_LISTS

#include "bullet.h"
#include "asteroid.h"
#include <vector>

extern std::vector<Bullet*> allBullets;
extern std::vector<Asteroid*> allAsteroids;
void bulStep();
void bulDestroy();
void astStep();
void astDestroy();



#endif