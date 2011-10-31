#include "Vec2.h"

Vec2::Vec2(float x, float y)
{
    m_X = x;
    m_Y = y;
}

Vec2::Vec2() {}

//SET

void Vec2::SetX(float x)
{
    m_X = x;
}

void Vec2::SetY(float y)
{
    m_Y = y;
}

//GET

float Vec2::GetX()
{
    return m_X;
}

float Vec2::GetY()
{
    return m_Y;
}
