#include "vec2.h"
#include <raylib.h>
#include <iostream>
#include <cmath>

Vec2::Vec2(float a, float b) {
    x = a;
    y = b;
}

Vec2::~Vec2(){}

// ------------------ Operators ------------------
Vec2 Vec2::operator+(const Vec2 & v) const{
    return Vec2(x+v.x,y+v.y);
}

Vec2 Vec2::operator-(const Vec2 & v) const{
    return *this + (-1*v);
}

Vec2 Vec2::operator*(float c) const{
    return Vec2(c*x,c*y);
}

Vec2 Vec2::operator/(float c) const{
    return Vec2(x/c,y/c);
}


// -- smth
Vec2 Vec2::rotated(float th) const{
    float s = std::sin(th), c = std::cos(th);
    return Vec2(x*c - y*s, x*s + y*c);
}

float Vec2::angle() const{
    return std::atan(y/x);
}



std::ostream & operator << (std::ostream & o, const Vec2 & v){
    o << "(" << v.x << ", " << v.y << ")";

    return o;
}

Vec2 operator * (float c, const Vec2 & v){
    return Vec2(c*v.x,c*v.y);
}