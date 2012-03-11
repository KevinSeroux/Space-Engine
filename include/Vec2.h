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
    //GET
    float getX();
    float getY();
    
    float operator[](unsigned char a);
 protected:
    float _x;
    float _y;
};

#endif
