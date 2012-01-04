#ifndef VEC3_H
#define VEC3_H

class Vec3
{
 public:
    Vec3();
    Vec3(float &x, float &y, float &z);
    //SET
    void setX(float &x);
    void setY(float &y);
    void setZ(float &z);
    //GET
    float& getX();
    float& getY();
    float& getZ();
 private:
    float _x;
    float _y;
    float _z;
};

#endif
