#include "Vertex.h"

Vertex::Vertex(const float& x, const float& y, const float& z)
{
    m_X = x;
    m_Y = y;
    m_Z = z;
}

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
