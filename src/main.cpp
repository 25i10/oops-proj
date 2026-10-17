#include <raylib.h>
#include <iostream>
#include <vector>

#include "player.h"
#include "objLists.h"


const int screenWidth = 800;
const int screenHeight = 900;


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

    t_astPiece[0] = LoadTexture("res/rock_pieces/1.png");
    t_astPiece[1] = LoadTexture("res/rock_pieces/2.png");
    t_astPiece[2] = LoadTexture("res/rock_pieces/3.png");
    t_astPiece[3] = LoadTexture("res/rock_pieces/4.png");

    t_star[0] = LoadTexture("res/stars/1.png");
    t_star[1] = LoadTexture("res/stars/2.png");
    t_star[2] = LoadTexture("res/stars/3.png");
    t_star[3] = LoadTexture("res/stars/4.png");
    t_star[4] = LoadTexture("res/stars/5.png");
    t_star[5] = LoadTexture("res/stars/6.png");
    t_star[6] = LoadTexture("res/stars/7.png");

    t_plrBullet[0] = LoadTexture("res/bullets/player/1.png");
    t_plrBullet[1] = LoadTexture("res/bullets/player/2.png");
    
    t_Bullet1 = LoadTexture("res/bul1.png");

    SetTargetFPS(60);

    
    Player p(100,700);
    
    allDestroys.push_back(new Asteroid(100,100));
    allDestroys.push_back(new Asteroid(200,100));



    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        starGen();
        starStep();

        if(IsKeyPressed(KEY_L)) allDestroys.push_back(new Asteroid(100,100));

        bulStep();
        destStep();

        p.step();
        p.draw();

        EndDrawing();
    }


    bulDestroy();
    destDestroy();
    starDestroy();

    UnloadTexture(t_asteroid);
    UnloadTexture(t_player);
    UnloadTexture(t_Bullet1);
    for(Texture2D t : t_plrBullet) UnloadTexture(t);
    for(Texture2D t : t_star) UnloadTexture(t);
    for(Texture2D t : t_astPiece) UnloadTexture(t);

    CloseWindow();


    return 0;
}