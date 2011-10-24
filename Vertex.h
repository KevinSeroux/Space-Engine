#ifndef VERTEX_H
#define VERTEX_H

class Vertex
{
 public:
    Vertex(const float& x, const float& y, const float& z);
    float GetX();
    float GetY();
    float GetZ();
 private:
    float m_X;
    float m_Y;
    float m_Z;
};

#endif
