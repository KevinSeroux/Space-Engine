#include "Vertex.h"

Vertex::Vertex(float x, float y, float z)
{
    m_X = x;
    m_Y = y;
    m_Z = z;
}

Vertex::Vertex() {}

float Vertex::GetX()
{
    return m_X;
}

float Vertex::GetY()
{
    return m_Y;
}

float Vertex::GetZ()
{
    return m_Z;
}

std::string Vertex::GetXYZ()
{
    std::string tmp;
    tmp += m_X;
    tmp += ';';
    tmp += m_Y;
    tmp += ';';
    tmp += m_Z;
    return tmp;
}
