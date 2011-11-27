#include "Mesh.h"

void Mesh::addTriangle(Triangle *triangle)
{
    _triangles->push_back(triangle);
}

std::vector<Triangle*>* Mesh::getTriangles()
{
    return _triangles;
}
