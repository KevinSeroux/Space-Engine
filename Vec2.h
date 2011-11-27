#ifndef VEC2_H
#define VEC2_H

class Vec2
{
 public:
    Vec2(float x, float y);
    void setX(float x);
    void setY(float y);
    void setXY(float x, float y);
    float getX();
    float getY();
 protected:
    float _x;
    float _y;
};

#endif
