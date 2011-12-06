#include "Mesh.h"

Mesh::Mesh(const int& numberTriangles, Triangle *triangles)
{
    _triangles = triangles;
    _numberTriangles = numberTriangles;
}

Mesh::Mesh(std::vector<Triangle*> triangles)
{
    unsigned int i(0);
    while(i < triangles.size()-1)
    {
	_triangles[i] = triangles[i];
	i++;
    }
    _numberTriangles = i;
}

//SET

void Mesh::setTriangle(const int& index, Triangle *triangle)
{
    _triangles[index] = triangle;
}

//GET

Triangle* Mesh::getTriangles()
{
    return _triangles;
}

int Mesh::getNumberTriangles()
{
    return _numberTriangles;
}
