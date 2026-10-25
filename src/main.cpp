#include "raylib.h"
#include <iostream>
#include <vector>

#include "player.h"
#include "objLists.h"


const int screenWidth = 800;
const int screenHeight = 900;

enum class gameState{
    START,
    GAME,
    LOSE
};

void dispTextFromOrigin(const char* text, int x, int y, int fSize, Color b){
    int tWidth = MeasureText(text,fSize);
    int _x = x - tWidth/2;
    int _y = y - fSize/2;
    DrawText(text,_x,_y,fSize,b);
}


int main() 
{
    InitWindow(screenWidth, screenHeight, "Asteroids");

    gameState gs = gameState::START;

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

    
    
    Player p(300,700);



    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        switch(gs){
            case  gameState::START:
            starGen();
            starStep();

            if(IsKeyPressed(KEY_SPACE)){
                gs = gameState::GAME;
                
                for(int i = 0; i<10; i++){
                    allDestroys.push_back(new Asteroid(100+64*i,-32));
                }
            }
            dispTextFromOrigin("Press SPACE to play",screenWidth/2,screenHeight/2,40,WHITE);

            break;



            case gameState::GAME:
            starGen();
            starStep();


            if(allDestroys.size() <= 3){
                for(int i = 0; i<10; i++){
                    allDestroys.push_back(new Asteroid(100+64*i,-32));
                }
            }

            bulStep();
            destStep();

            p.step();
            p.draw();
            playerColl(p);
            if(!p.isActive()) gs = gameState::LOSE;

            DrawText(TextFormat("FPS : %i",GetFPS()),0,0,20,WHITE);

            break;



            case gameState::LOSE:
            starDraw();
            bulDraw();
            destDraw();
            p.draw();

            dispTextFromOrigin("YOU LOST",screenWidth/2,screenHeight/2,40,WHITE);
            dispTextFromOrigin("Press SPACE to try again",screenWidth/2,screenHeight/2+45,20,WHITE);
            if(IsKeyPressed(KEY_SPACE)){
                gs = gameState::GAME;
                bulDestroy();
                destDestroy();

                for(int i = 0; i<10; i++){
                    allDestroys.push_back(new Asteroid(100+64*i,-32));
                }

                p.reset();
            }

            

            break;
        }

        

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