#include <raylib.h>
#include <iostream>

#include "player.h"


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
    SetTargetFPS(60);

    
    Player p(100,700);
    Entity e(100,100);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        e.step();
        e.draw();
        
        p.step();
        p.draw();


        EndDrawing();
    }

    CloseWindow();


    return 0;
}