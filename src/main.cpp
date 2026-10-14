#include <raylib.h>
#include <iostream>
#include "vec2.h"


const int screenWidth = 800;
const int screenHeight = 600;

int main() 
{
    Vec2 v(1,2), v2(4,3), v3(1,0);
    std::cout << v << v2 << std::endl;

    std::cout << 0.5*v2 << std::endl;

    std::cout << v + v2 << v-v2 <<std::endl;

    std::cout << v3 << v3.rotated(PI/4) << v3.rotated(PI/4).angle() << std::endl;

    
    
/*
    InitWindow(screenWidth, screenHeight, "a!");
    SetTargetFPS(60);

    


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(SKYBLUE);


        


        EndDrawing();
    }

    CloseWindow();
*/
    return 0;
}