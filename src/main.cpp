#include <raylib.h>
#include <iostream>
#include <vector>

#include "player.h"
#include "asteroid.h"
#include "objLists.h"


const int screenWidth = 800;
const int screenHeight = 800;


int main() 
{
    Vec2 v(1,2), v2(4,3), v3(1,0);
    std::cout << v << v2 << std::endl;
    std::cout << 0.5*v2 << std::endl;
    std::cout << v + v2 << v-v2 <<std::endl;
    std::cout << v3 << v3.rotated(PI/4) << v3.rotated(PI/4).angle() << std::endl;
    std::cout << v2[0] << " " << v2[1] << std::endl;
    

    InitWindow(screenWidth, screenHeight, "a!");

    t_asteroid = LoadTexture("res/rock.png");
    t_player = LoadTexture("res/plr.png");
    t_plrBullet = LoadTexture("res/plr_bul.png");
    t_Bullet1 = LoadTexture("res/bul1.png");

    SetTargetFPS(60);

    
    Player p(100,700);

    
    
    allAsteroids.push_back(new Asteroid(100,100));
    allAsteroids.push_back(new Asteroid(200,100));

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        

        if(IsKeyPressed(KEY_L)) allAsteroids.push_back(new Asteroid(100,100));


        bulStep();
        astStep();

        p.step();
        p.draw();

        EndDrawing();
    }


    bulDestroy();
    astDestroy();

    UnloadTexture(t_asteroid);
    UnloadTexture(t_player);
    UnloadTexture(t_plrBullet);
    UnloadTexture(t_Bullet1);

    CloseWindow();


    return 0;
}