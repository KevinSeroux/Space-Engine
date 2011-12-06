#ifndef VEC3_H
#define VEC3_H

#include "Vec2.h"

class Vec3 : public Vec2
{
 public:
    Vec3();
    Vec3(float x, float y, float z);
    //SET
    void setZ(float z);
    void setXZ(float x, float y);
    void setYZ(float y, float z);
    void setXYZ(float x, float y, float z);
    //GET
    float getZ();
    bool isNull();
 private:
    float _z;
};

#endif
