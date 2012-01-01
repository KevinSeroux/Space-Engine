#include "Vec2.h"

Vec2::Vec2() : _x(0.0f), _y(0.0f) {}

Vec2::Vec2(float &x, float &y) : _x(x), _y(y) {}

//SET

void Vec2::setX(float &x)
{
    _x = x;
}

void Vec2::setY(float &y)
{
    _y = y;
}

//GET

float& Vec2::getX()
{
    return _x;
}

float& Vec2::getY()
{
    return _y;
}
