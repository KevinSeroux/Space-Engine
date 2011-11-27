#ifndef VERTEX_H
#define VERTEX_H

#include "Vec3.h"
#include "Vec2.h"

class Vertex
{
 public:
    Vertex(Vec3 *coord, Vec3 *normalCoord, Vec2 *textureCoord);
    //SET
    void setCoord(Vec3 *coord);
    void setNormal(Vec3 *normal);
    void setTexturePoint(Vec2 *texturePoint);
    //GET
    Vec3* getCoord();
    Vec3* getNormal();
    Vec2* getTexturePoint();

 private:
    Vec3 *_coord;
    Vec3 *_normalCoord;
    Vec2 *_textureCoord;
};

#endif
