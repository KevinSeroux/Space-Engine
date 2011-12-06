#ifndef MESH_H
#define MESH_H

#include <vector>
#include "Triangle.h"

class Mesh
{
 public:
    Mesh(const int& numberTriangles, Triangle *triangles);
    Mesh(std::vector<Triangle*> triangles);
    //SET
    void setTriangle(const int& index, Triangle *triangle);
    //GET
    Triangle* getTriangles();
    int getNumberTriangles();
 private:
    Triangle *_triangles;
    int _numberTriangles;
};

#endif
