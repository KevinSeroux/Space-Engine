#include "Vertex.h"

Vertex::Vertex(Vec3 *coord, Vec3 *normalCoord, Vec2 *textureCoord)
{
    _coord = coord;
    _normalCoord = normalCoord;
    _textureCoord = textureCoord;
}

//SET

void Vertex::setCoord(Vec3 *coord)
{
    _coord = coord;
}

void Vertex::setNormal(Vec3 *normalCoord)
{
    _normalCoord = normalCoord;
}

void Vertex::setTexturePoint(Vec2 *textureCoord)
{
    _textureCoord = textureCoord;
}

//GET

Vec3* Vertex::getCoord()
{
    return _coord;
}

Vec3* Vertex::getNormal()
{
    return _normalCoord;
}

Vec2* Vertex::getTexturePoint()
{
    return _textureCoord;
}
