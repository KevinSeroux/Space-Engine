#include "Vertex.h"

Vertex::Vertex() {}

Vertex::Vertex(Vec3 &vertexCoords, Vec3 &normalCoords, Vec2 &textureCoords)
{
    _vertexCoords = vertexCoords;
    _textureCoords = textureCoords;
    _normalCoords = normalCoords;
}

Vertex::Vertex(Vec3 &vertexCoords, Vec3 &normalCoords)
{
    _vertexCoords = vertexCoords;
    _normalCoords = normalCoords;
}

Vertex::Vertex(Vec3 &vertexCoords)
{
    _vertexCoords = vertexCoords;
}

//SET

void Vertex::setVertexCoords(Vec3 &vertexCoords)
{
    _vertexCoords = vertexCoords;
}

void Vertex::setTextureCoords(Vec2 &textureCoords)
{
  _textureCoords = textureCoords;
}

void Vertex::setNormalCoords(Vec3 &normalCoords)
{
    _normalCoords = normalCoords;
}

//GET

Vec3& Vertex::getVertexCoords()
{
    return _vertexCoords;
}

Vec2& Vertex::getTextureCoords()
{
  return _textureCoords;
}

Vec3& Vertex::getNormalCoords()
{
    return _normalCoords;
}
