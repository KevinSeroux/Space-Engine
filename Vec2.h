#ifndef VEC2_H
#define VEC2_H

class Vec2
{
 public:
    Vec2(float x, float y);
    Vec2();
    void SetX(float x);
    void SetY(float y);
    float GetX();
    float GetY();
 private:
    float m_X;
    float m_Y;
};

#endif
