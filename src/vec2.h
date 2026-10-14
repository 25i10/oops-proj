#pragma once
#include <iostream>

class Vec2 {
friend std::ostream & operator << (std::ostream &, const Vec2 &);
friend Vec2 operator * (float, const Vec2 &);

public:
    Vec2(float = 0, float = 0);
    ~Vec2();

    // Operators
    Vec2 operator + (const Vec2 &) const;
    Vec2 operator - (const Vec2 &) const;
    Vec2 operator * (float) const;
    Vec2 operator / (float) const;

    

    // Functions
    Vec2 rotated(float) const;
    float angle() const;

private:
    float x;
    float y;
};