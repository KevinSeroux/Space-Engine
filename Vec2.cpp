#include "Vec2.h"

Vec2::Vec2()
{
    _x = 0;
    _y = 0;
}

Vec2::Vec2(float x = 0, float y = 0)
{
    _x = x;
    _y = y;
}

//SET

void Vec2::setX(float x)
{
    _x = x;
}

void Vec2::setY(float y)
{
    _y = y;
}

void Vec2::setXY(float x, float y)
{
    _x = x;
    _y = y;
}

//GET

float Vec2::getX()
{
    return _x;
}

float Vec2::getY()
{
    return _y;
}

bool Vec2::isNull()
{
    if(_x == 0 || _y == 0)
	return true;
    else
	return false;
}
