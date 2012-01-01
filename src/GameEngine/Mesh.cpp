#include "Mesh.h"

Mesh::Mesh(Triangle *triangles, unsigned int &numberTriangles)
{
    _triangles = triangles;
    _numberTriangles = numberTriangles;
}

//GET

Triangle* Mesh::getTriangles()
{
    return _triangles;
}

const unsigned int& Mesh::getNumberTriangles()
{
    return _numberTriangles;
}
