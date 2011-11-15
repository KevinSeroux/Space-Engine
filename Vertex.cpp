#include "Vertex.h"

Vertex::Vertex() {}

Vertex::Vertex(Vec3 coord, Vec3 normal)
{
    m_coord = coord;
    m_normal = normal;
}

//SET

void Vertex::setCoord(Vec3 coord)
{
    m_coord = coord;
}

void Vertex::setNormal(Vec3 normal)
{
    m_normal = normal;
}

void Vertex::setTexturePoint(Vec2 texturePoint)
{
    m_texturePoint = texturePoint;
}

//GET

Vec3 Vertex::getCoord()
{
    return m_coord;
}

Vec3 Vertex::getNormal()
{
    return m_normal;
}

Vec2 Vertex::getTexturePoint()
{
    return m_texturePoint;
}
