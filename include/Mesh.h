#ifndef MESH_H
#define MESH_H

#include <vector>
#include "Triangle.h"

class Mesh
{
 public:
    Mesh(Triangle triangles[], unsigned int &countTriangles);
    Mesh(std::vector<Triangle>& triangles);
    ~Mesh();
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
