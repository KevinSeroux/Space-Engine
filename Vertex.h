#ifndef VERTEX_H
#define VERTEX_H

#include "Vec3.h"
#include "Vec2.h"

class Vertex
{
 public:
    Vertex(Vec3 coord, Vec3 normal);
    Vertex(Vec3 coord);
    Vertex();
    //SET
    void setCoord(Vec3 coord);
    void setNormal(Vec3 normal);
    void setTexturePoint(Vec2 texturePoint);
    //GET
    Vec3 getCoord();
    Vec3 getNormal();
    Vec2 getTexturePoint();

 private:
    Vec3 m_coord;
    Vec3 m_normal;
    Vec2 m_texturePoint;
};

#endif
