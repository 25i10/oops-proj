#include "smoke.h"
#include <iostream>

Texture2D t_smoke;

Smoke::Smoke(Vec2 p, Vec2 d, int c):dir(d[0],d[1]),col(c){
    spd = GetRandomValue(4,6);
    lifetime = GetRandomValue(8,14);
    life = lifetime;

    pos = p - spd*dir;

    sprDims = 3 * Vec2(t_smoke.width,t_smoke.height);
}

Smoke::~Smoke(){
    //std::cout << "DEAD";
}

bool Smoke::isActive() const{
    return active;
}

void Smoke::stepDraw(){
    if(life > 0){
        pos += spd * dir;
        Color drawCol;
        switch (col)
        {
        case 1:
            drawCol = {120,120,120, (unsigned char) (255 * (life*1.0)/lifetime)};
            break;
        
        default:
            drawCol = {255,255,255, (unsigned char) (255 * (life*1.0)/lifetime)};
            break;
        }
        
        DrawTextureEx(t_smoke,Vector2{pos[0] - sprDims[0]/2,pos[1]-sprDims[1]/2},0,3,drawCol);
        life--;
    } else {
        active = false;
    }
}

SmokeGen::SmokeGen(){}

void SmokeGen::smokeBurst(int x, int y, int c){
    Vec2 pos(x,y);

    float a = 0;

    l.push_back(new Smoke(pos,Vec2(0,1).rotated(a),c));
    l.push_back(new Smoke(pos,Vec2(0,-1).rotated(a),c));
    l.push_back(new Smoke(pos,Vec2(1,0).rotated(a),c));
    l.push_back(new Smoke(pos,Vec2(-1,0).rotated(a),c));
    l.push_back(new Smoke(pos,Vec2(1,1).norm().rotated(a),c));
    l.push_back(new Smoke(pos,Vec2(1,-1).norm().rotated(a),c));
    l.push_back(new Smoke(pos,Vec2(-1,-1).norm().rotated(a),c));
    l.push_back(new Smoke(pos,Vec2(-1,1).norm().rotated(a),c));

    
    a = PI/8;

    l.push_back(new Smoke(pos,Vec2(0,1).rotated(a),c));
    l.push_back(new Smoke(pos,Vec2(0,-1).rotated(a),c));
    l.push_back(new Smoke(pos,Vec2(1,0).rotated(a),c));
    l.push_back(new Smoke(pos,Vec2(-1,0).rotated(a),c));
    l.push_back(new Smoke(pos,Vec2(1,1).norm().rotated(a),c));
    l.push_back(new Smoke(pos,Vec2(1,-1).norm().rotated(a),c));
    l.push_back(new Smoke(pos,Vec2(-1,-1).norm().rotated(a),c));
    l.push_back(new Smoke(pos,Vec2(-1,1).norm().rotated(a),c));
    
}

SmokeGen::~SmokeGen(){
    for(Smoke *i : l){
        delete i;
        i = nullptr;
    }
    l.clear();
}

void SmokeGen::step(){
    for(std::size_t i = 0; i < l.size(); i++){
        Smoke *e = l[i];

        if(!e->isActive()) {
            delete l[i];
            l.erase(l.begin() + i);
            if(i >= l.size()) i = l.size()-1;
            if (l.size() == 0) {
                e = nullptr;
                break;
            }
            e = l[i];
        }
        
        e->stepDraw();
        e=nullptr;
    }
}