#include "Vertex.h"

Vertex::Vertex() {}

Vertex::Vertex(Vec3 &coord, Vec3 &normalCoord)
{
    _coord = coord;
    _normalCoord = normalCoord;
}

//SET

void Vertex::setCoord(Vec3 &coord)
{
    _coord = coord;
}

void Vertex::setNormal(Vec3 &normalCoord)
{
    _normalCoord = normalCoord;
}

//GET

Vec3& Vertex::getCoord()
{
    return _coord;
}

Vec3& Vertex::getNormal()
{
    return _normalCoord;
}
