#ifndef VERTEX_H
#define VERTEX_H

#include "Vec3.h"
#include "Vec2.h"

class Vertex
{
 public:
    Vertex();
    Vertex(Vec3 &vertexCoords, Vec3 &normalCoords, Vec2 &textureCoords);
    Vertex(Vec3 &vertexCoords, Vec3 &normalCoords);
    Vertex(Vec3 &vertexCoords);
    //SET
    void setVertexCoords(Vec3 &vertexCoords);
    void setTextureCoords(Vec2 &textureCoords);
    void setNormalCoords(Vec3 &normalCoords);
    //GET
    Vec3& getVertexCoords();
    Vec2& getTextureCoords();
    Vec3& getNormalCoords();

 private:
    Vec3 _vertexCoords;
    Vec2 _textureCoords;
    Vec3 _normalCoords;
};

#endif
