#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>

class Vertex
{
 public:
    Vertex(float x, float y, float z);
    Vertex();
    float GetX();
    float GetY();
    float GetZ();
    void Print();
 private:
    float m_X;
    float m_Y;
    float m_Z;
};

#endif
