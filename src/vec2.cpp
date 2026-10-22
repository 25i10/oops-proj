#include "vec2.h"
#include "raylib.h"
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

Vec2 & Vec2::operator=(const Vec2 & v){
    x = v.x;
    y = v.y;

    return *this;
}

Vec2 & Vec2::operator+=(const Vec2 & v){
    x += v.x;
    y += v.y;

    return *this;
}

Vec2 & Vec2::operator-=(const Vec2 & v){
    return *this += (-1*v);
}

Vec2 & Vec2::operator*=(float c){
    x *= c;
    y *= c;

    return *this;
}

Vec2 & Vec2::operator/=(float c){
    return *this *= (1/c);
}

float & Vec2::operator[](int i) {
    if(i) return y;
    else return x;
}

const float Vec2::operator[] (int i) const{
    if(i) return y;
    else return x;
}


// ------------------ Functions ------------------
Vec2 Vec2::rotated(float th) const{
    float s = std::sin(-th), c = std::cos(-th);     //-theta because screen works as IVth quadrant as base
    return Vec2(x*c - y*s, x*s + y*c);
}

float Vec2::angle() const{
    return std::atan2(-y,x);
}

float Vec2::magn() const{
    return std::sqrt(x*x + y*y);
}

Vec2 Vec2::norm() const{
    float c = this->magn();
    if(c) return *this / c;
    else return *this;
}



std::ostream & operator << (std::ostream & o, const Vec2 & v){
    o << "(" << v.x << ", " << v.y << ")";

    return o;
}

Vec2 operator * (float c, const Vec2 & v){
    return Vec2(c*v.x,c*v.y);
}