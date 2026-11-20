#include "raylib.h"
#include <iostream>
#include <vector>

#include "player.h"
#include "objLists.h"


const int screenWidth = 800;
const int screenHeight = 900;
int highScore, timer, wave=0;

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

void waveControl(int &w, int &t){
    static bool waveLatch = false;
    int p = 0;
    switch (w){
        case 0:
        waveLatch = false;
        if (t >= 40){
            t = 0;
            w = 1;
        }
        break;
        
        case 1:
        if (t == 1)DC.getVec().push_back(new Asteroid(100+64*GetRandomValue(0,9),-40));
        if (t == 140){
            DC.getVec().push_back(new Asteroid(100+64*GetRandomValue(5,9),-40));
            DC.getVec().push_back(new Asteroid(100+64*GetRandomValue(0,4),-40));
            t++;
            waveLatch = true;
        }
        if(DC.isEmpty() && t == 141) waveLatch = false;
        if (t == 200){
            t = 0;
            w = 2;
        }
        break;

        case 2:
        if (t==1){
            DC.getVec().push_back(new Asteroid(100+64*GetRandomValue(0,9),-40));
            DC.getVec().push_back(new Asteroid(100+64*GetRandomValue(0,9),-50));
            DC.getVec().push_back(new Asteroid(100+64*GetRandomValue(0,9),-50));
        }
        if (t == 200){
            DC.getVec().push_back(new Asteroid(100+64*GetRandomValue(0,9),-40));
            DC.getVec().push_back(new Asteroid(100+64*GetRandomValue(0,9),-50));
            DC.getVec().push_back(new Asteroid(100+64*GetRandomValue(0,9),-45));
            DC.getVec().push_back(new Asteroid(100+64*GetRandomValue(0,9),-50));
            DC.getVec().push_back(new Asteroid(100+64*GetRandomValue(0,9),-55));
            t++;
            waveLatch = true;
        }
        if(DC.getSize() < 4 && t == 201) waveLatch = false;
        if (t == 220){
            for(int i = 1; i<9; i++) DC.getVec().push_back(new Asteroid(100+64*i,-55));
            t++;
            waveLatch = true;
        }
        if(DC.isEmpty() && t==221) waveLatch = false;
        if (t ==320){
            t = 0;
            w = 3;
        }
        
        break;

        case 3:
        if(t == 1){
            for(int i = 0; i<6; i++) DC.getVec().push_back(new Asteroid(100+64*i,-55));
            t++;
            waveLatch = true;
        }
        if(DC.getSize() < 5 && t==2) waveLatch = false;
        
        p = 30;
        if(t == p){
            for(int i = 5; i<10; i++) DC.getVec().push_back(new Asteroid(100+64*i,-55));
            t++;
            waveLatch = true;
        }
        if(DC.getSize() < 5 && t==p+1) waveLatch = false;

        p += 30;
        if(t == p){
            for(int i = 3; i<7; i++) DC.getVec().push_back(new Asteroid(100+64*i,-55));
            t++;
            waveLatch = true;
        }
        if(DC.getSize() < 4 && t==p+1) waveLatch = false;
        
        p += 30;
        if(t == p){
            for(int i = 3; i<10; i++) DC.getVec().push_back(new Asteroid(100+64*i,-55));
            t++;
            waveLatch = true;
        }
        if(DC.getSize() < 4 && t==p+1) waveLatch = false;
        
        p += 30;
        if(t == p){
            for(int i = 2; i<8; i++) DC.getVec().push_back(new Asteroid(100+64*i,-55));
            t++;
            waveLatch = true;
        }
        if(DC.getSize() < 4 && t==p+1) waveLatch = false;
        
        p += 50;
        if(t == p){
            for(int i = 0; i<10; i++) DC.getVec().push_back(new Asteroid(100+64*i,-55));
            t++;
            waveLatch = true;
        }
        if(DC.isEmpty() && t==p+1) waveLatch = false;

        p += 40;
        if(t == p){
            t = 0;
            w = 4;
        }

        break;

        case 4:
        p = 1;
        if(t == p){
            int x = GetRandomValue(0,4);
            int y = GetRandomValue(5,9);
            for(int i = 0; i<10; i++) {
                if (i == x || i==y) continue;
                DC.getVec().push_back(new Asteroid(100+64*i,-55));
            }
        }

        p += 200;
        if(t == p){
            int x = GetRandomValue(0,4);
            int y = GetRandomValue(5,9);
            for(int i = 0; i<10; i++) {
                if (i == x || i==y) continue;
                DC.getVec().push_back(new Asteroid(100+64*i,-55));
            }
        }

        p += 200;
        if(t == p){
            int x = GetRandomValue(0,4);
            int y = GetRandomValue(5,9);
            for(int i = 0; i<10; i++) {
                if (i == x || i==y) continue;
                DC.getVec().push_back(new Asteroid(100+64*i,-55));
            }
        }

        p += 200;
        if(t == p){
            int x = GetRandomValue(0,4);
            int y = GetRandomValue(5,9);
            for(int i = 0; i<10; i++) {
                if (i == x || i==y) continue;
                DC.getVec().push_back(new Asteroid(100+64*i,-55));
            }
        }

        p += 200;
        if(t == p){
            int x = GetRandomValue(0,4);
            int y = GetRandomValue(5,9);
            for(int i = 0; i<10; i++) {
                if (i == x || i==y) continue;
                DC.getVec().push_back(new Asteroid(100+64*i,-55));
            }
            t++;
            waveLatch = true;
        }
        if(DC.isEmpty() && t==p+1) waveLatch = false;
        
        p += 80;
        if(t == p){
            t = 0;
            w = 5;
        }
        break;

        default:
        break;
    }

    if (!waveLatch) t++;
}


int main() 
{
    InitWindow(screenWidth, screenHeight, "Asteroids");

    gameState gs = gameState::START;

    t_heart = LoadTexture("res/heart.png");
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
    starController starCon;
    

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        switch(gs){
            case  gameState::START:
            starCon.gen();
            starCon.step();

            if(IsKeyPressed(KEY_SPACE)){
                gs = gameState::GAME;
                
                /*
                for(int i = 0; i<5; i++){
                    DC.getVec().push_back(new BigShot(100+64*2*i));
                }
                */
            }
            dispTextFromOrigin("Press SPACE to play",screenWidth/2,screenHeight/2,40,WHITE);

            break;



            case gameState::GAME:
            waveControl(wave,timer);

            starCon.gen();
            starCon.step();

            BC.step();
            DC.step(p);

            p.step();
            p.draw();
            DC.playerColl(p);
            if(!p.isActive()) gs = gameState::LOSE;

            SM.step();
            /*
            if(IsKeyPressed(KEY_L)) {
                SM.smokeBurst(100,100);
                for(int i = 0; i<5; i++){
                    DC.getVec().push_back(new Asteroid(100+64*2*i));
                }
            }
            */
            

            DrawText(TextFormat("Score : %i",score),0,0,20,WHITE);
            DrawText(TextFormat("Wave : %i",wave),0,20,20,WHITE);
            //DrawText(TextFormat("AST COUNT : %i, %i",astCount(),shootCount()),0,0,20,WHITE);

            break;



            case gameState::LOSE:
            starCon.draw();
            BC.draw();
            DC.draw();
            p.draw();
            highScore = std::max(highScore,score);

            dispTextFromOrigin("YOU LOST",screenWidth/2,screenHeight/2 - 40,40,WHITE);
            dispTextFromOrigin("Press R to try again",screenWidth/2,screenHeight/2+5,20,WHITE);
            dispTextFromOrigin(TextFormat("Score : %i",score),screenWidth/2,screenHeight/2+30,20,WHITE);
            dispTextFromOrigin(TextFormat("High Score : %i",highScore),screenWidth/2,screenHeight/2+55,20,WHITE);
            if(IsKeyPressed(KEY_R)){
                score = 0;
                wave = 0;
                timer = -40;

                gs = gameState::GAME;
                BC.destroy();
                DC.destroy();

                p.reset();
            }            

            break;
        }

        

        EndDrawing();
    }


    BC.destroy();
    DC.destroy();
    starCon.destroy();

    UnloadTexture(t_asteroid);
    UnloadTexture(t_player);
    UnloadTexture(t_shooter1);
    UnloadTexture(t_shooter2);
    UnloadTexture(t_shooter3);
    
    UnloadTexture(t_spBullet);
    UnloadTexture(t_spiralBullet);
    UnloadTexture(t_smoke);
    UnloadTexture(t_heart);
    for(Texture2D t : t_plrBullet) UnloadTexture(t);
    for(Texture2D t : t_strBullet) UnloadTexture(t);
    for(Texture2D t : t_star) UnloadTexture(t);
    for(Texture2D t : t_astPiece) UnloadTexture(t);

    CloseWindow();


    return 0;
}