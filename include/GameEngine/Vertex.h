#ifndef VERTEX_H
#define VERTEX_H

#include "Vec3.h"
#include "Vec2.h"

class Vertex
{
 public:
    Vertex();
    Vertex(Vec3 &coord, Vec3 &normalCoord);
    //SET
    void setCoord(Vec3 &coord);
    void setNormal(Vec3 &normal);
    //GET
    Vec3& getCoord();
    Vec3& getNormal();

 private:
    Vec3 _coord;
    Vec3 _normalCoord;
};

#endif
