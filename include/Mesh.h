#ifndef MESH_H
#define MESH_H

#include <vector>
#include "Triangle.h"

class Mesh
{
 public:
    Mesh(Triangle *triangles, unsigned int &numberTriangles);
    //GET
    Triangle* getTriangles();
    const unsigned int& getNumberTriangles();
 private:
    Triangle *_triangles;
    unsigned int _numberTriangles;
};

#endif
