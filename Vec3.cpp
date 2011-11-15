#include "Vec3.h"

Vec3::Vec3(float x, float y, float z)
{
    m_X = x;
    m_Y = y;
    m_Z = z;
}

Vec3::Vec3() {}

//SET

void Vec3::setX(float x)
{
    m_X = x;
}

void Vec3::setY(float y)
{
    m_Y = y;
}

void Vec3::setZ(float z)
{
    m_Z = z;
}

//GET

float Vec3::getX()
{
    return m_X;
}

float Vec3::getY()
{
    return m_Y;
}

float Vec3::getZ()
{
    return m_Z;
}
