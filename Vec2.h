#ifndef VEC2_H
#define VEC2_H

class Vec2
{
 public:
    Vec2(float x, float y);
    Vec2();
    void setX(float x);
    void setY(float y);
    float getX();
    float getY();
 private:
    float m_X;
    float m_Y;
};

#endif
