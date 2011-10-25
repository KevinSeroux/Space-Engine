#ifndef VERTEX_H
#define VERTEX_H

#include <string>

class Vertex
{
 public:
    Vertex(const float x, const float y, const float z);
    Vertex();
    float GetX();
    float GetY();
    float GetZ();
    std::string GetXYZ();
 private:
    float m_X;
    float m_Y;
    float m_Z;
};

#endif
