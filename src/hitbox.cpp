#include "hitbox.h"
#include <raylib.h>

Hitbox::Hitbox(int x, int y, int w, int h, int ox, int oy):corner(x,y),dims(w,h),offset(ox,oy){}

Hitbox::~Hitbox(){}


bool Hitbox::intersect(const Hitbox & h) const{
    return (
        corner[0] < h.corner[0] + h.dims[0] && corner[0] + dims[0] > h.corner[0] &&
        corner[1] < h.corner[1] + h.dims[1] && corner[1] + dims[1] > h.corner[1]
    );
}


void Hitbox::moveCorner(Vec2 p){
    corner = p;
}

void Hitbox::draw() const{
    DrawRectangleV(Vector2{corner[0],corner[1]},Vector2{dims[0],dims[1]},(Color){0,0,140,128});
}

Vec2 Hitbox::getCorner() const{
    return corner;
}

Vec2 Hitbox::getDims() const{
    return dims;
}

Vec2 Hitbox::getOffset() const{
    return offset;
}