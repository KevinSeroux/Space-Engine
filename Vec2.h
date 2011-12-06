#ifndef VEC2_H
#define VEC2_H

class Vec2
{
 public:
    Vec2();
    Vec2(float x, float y);
    //SET
    void setX(float x);
    void setY(float y);
    void setXY(float x, float y);
    //GET
    float getX();
    float getY();
    bool isNull();
 protected:
    float _x;
    float _y;
};

#endif
