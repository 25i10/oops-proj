#include "raylib.h"
#include <iostream>
#include <vector>

#include "player.h"
#include "objLists.h"


const int screenWidth = 800;
const int screenHeight = 900;
int highScore = 0;

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

    t_smoke = LoadTexture("res/smoke.png");
    t_asteroid = LoadTexture("res/rock.png");
    t_player = LoadTexture("res/plr.png");

    t_shooter1 = LoadTexture("res/shooters/1.png");
    t_shooter2 = LoadTexture("res/shooters/2.png");
    t_shooter3 = LoadTexture("res/shooters/3.png");

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
    
    
    t_strBullet[0] = t_plrBullet[0];
    t_strBullet[1] = t_plrBullet[1];
    t_spBullet = LoadTexture("res/bullets/enemy/spreader.png");
    t_spiralBullet = t_plrBullet[0];
    
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
                
                
                for(int i = 0; i<5; i++){
                    allDestroys.push_back(new BigShot(100+64*2*i));
                }
            }
            dispTextFromOrigin("Press SPACE to play",screenWidth/2,screenHeight/2,40,WHITE);

            break;



            case gameState::GAME:
            starGen();
            starStep();

            bulStep();
            destStep(p);

            p.step();
            p.draw();
            playerColl(p);
            if(!p.isActive()) gs = gameState::LOSE;

            sm.step();
            if(IsKeyPressed(KEY_L)) {
                sm.smokeBurst(100,100);
                for(int i = 0; i<5; i++){
                    allDestroys.push_back(new Asteroid(100+64*2*i));
                }
            }

            DrawText(TextFormat("Score : %i",score),0,0,20,WHITE);
            //DrawText(TextFormat("AST COUNT : %i, %i",astCount(),shootCount()),0,0,20,WHITE);

            break;



            case gameState::LOSE:
            starDraw();
            bulDraw();
            destDraw();
            p.draw();
            highScore = std::max(highScore,score);

            dispTextFromOrigin("YOU LOST",screenWidth/2,screenHeight/2 - 40,40,WHITE);
            dispTextFromOrigin("Press SPACE to try again",screenWidth/2,screenHeight/2+5,20,WHITE);
            dispTextFromOrigin(TextFormat("Score : %i",score),screenWidth/2,screenHeight/2+30,20,WHITE);
            dispTextFromOrigin(TextFormat("High Score : %i",highScore),screenWidth/2,screenHeight/2+55,20,WHITE);
            if(IsKeyPressed(KEY_SPACE)){
                score = 0;

                gs = gameState::GAME;
                bulDestroy();
                destDestroy();

                for(int i = 0; i<5; i++){
                    allDestroys.push_back(new BigShot(100+64*2*i));
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
    UnloadTexture(t_shooter1);
    UnloadTexture(t_shooter2);
    UnloadTexture(t_shooter3);
    
    UnloadTexture(t_spBullet);
    UnloadTexture(t_spiralBullet);
    UnloadTexture(t_smoke);
    for(Texture2D t : t_plrBullet) UnloadTexture(t);
    for(Texture2D t : t_strBullet) UnloadTexture(t);
    for(Texture2D t : t_star) UnloadTexture(t);
    for(Texture2D t : t_astPiece) UnloadTexture(t);

    CloseWindow();


    return 0;
}