#include "Vec3.h"

Vec3::Vec3()
{
    _x = 0;
    _y = 0;
    _z = 0;
}

Vec3::Vec3(float x = 0, float y = 0, float z = 0) : Vec2(x,y), _z(z) {}

//SET

void Vec3::setZ(float z)
{
    _z = z;
}

void Vec3::setXZ(float x, float z)
{
    _x = x;
    _z = z;
}

void Vec3::setYZ(float y, float z)
{
    _y = y;
    _z = z;
}

void Vec3::setXYZ(float x, float y, float z)
{
    _x = x;
    _y = y;
    _z = z;
}

//GET

float Vec3::getZ()
{
    return _z;
}

bool Vec3::isNull()
{
    if(_x == 0 || _y == 0 || _z == 0)
	return true;
    else
	return false;
}
