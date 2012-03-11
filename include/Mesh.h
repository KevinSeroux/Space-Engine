#ifndef MESH_H
#define MESH_H

#include <vector>
#include "Triangle.h"

class Mesh
{
 public:
  Mesh();
    Mesh(Triangle *triangles, unsigned int &countTriangles);
  ~Mesh();
    void addTriangle(Triangle& triangle);
    //GET
    Triangle* getTriangles();
    const float* getVertices();
    const unsigned int& getCountTriangles();
 private:
    Triangle *_triangles;
    unsigned int _countTriangles;
    float *_vertices;
};

#endif
