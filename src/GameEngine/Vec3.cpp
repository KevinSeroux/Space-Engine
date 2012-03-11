#include "Vec3.h"

Vec3::Vec3() : _x(0.0f), _y(0.0f), _z(0.0f) {}

Vec3::Vec3(const float x, const float y, const float z) : _x(x), _y(y), _z(z) {}

//SET

void Vec3::setX(float x)
{
    _x = x;
}

void Vec3::setY(float y)
{
    _y = y;
}

void Vec3::setZ(float z)
{
    _z = z;
}

//GET

float Vec3::getX()
{
    return _x;
}

float Vec3::getY()
{
    return _y;
}

float Vec3::getZ()
{
    return _z;
}

float Vec3::operator[](unsigned char a)
{
  if(a == '0')
    return _x;
  else if(a == '1')
    return _y;
  else if(a == '2')
    return _z;
}
