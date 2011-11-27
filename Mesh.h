#ifndef MESH_H
#define MESH_H

#include <vector>
#include "Triangle.h"
#include "Drawer.h"

class Mesh
{
 public:
    //SET
    void addTriangle(Triangle *triangle);
    //GET
    std::vector<Triangle*>* getTriangles();
 private:
    std::vector<Triangle*> *_triangles;
};

#endif
