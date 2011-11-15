#ifndef VEC3_H
#define VEC3_H

#include <iostream>

class Vec3
{
 public:
    Vec3(float x, float y, float z);
    Vec3();
    void setX(float x);
    void setY(float y);
    void setZ(float z);

    float getX();
    float getY();
    float getZ();
 private:
    float m_X;
    float m_Y;
    float m_Z;
};

#endif
