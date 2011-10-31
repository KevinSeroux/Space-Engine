#ifndef VEC3_H
#define VEC3_H

#include <iostream>

class Vec3
{
 public:
    Vec3(float x, float y, float z);
    Vec3();
    void SetX(float x);
    void SetY(float y);
    void SetZ(float z);

    float GetX();
    float GetY();
    float GetZ();
 private:
    float m_X;
    float m_Y;
    float m_Z;
};

#endif
