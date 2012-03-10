#include "Mesh.h"

Mesh::Mesh(Triangle *triangles, unsigned int &countTriangles)
{
    _triangles = triangles;
    _countTriangles = countTriangles;
    _vertices = new float[countTriangles*3];
}

Mesh::~Mesh()
{
  delete[] _vertices;
}

//GET

Triangle* Mesh::getTriangles()
{
    return _triangles;
}

const float* Mesh::getVertices()
{
  unsigned int index(0);

  for(unsigned int i(0); i < _countTriangles; i++)
    {
      _vertices[index] = getTriangles()[i].getVertex1().getCoord().getX();
      _vertices[index+1] = getTriangles()[i].getVertex1().getCoord().getY();
      _vertices[index+2] = getTriangles()[i].getVertex1().getCoord().getZ();

      _vertices[index+3] = getTriangles()[i].getVertex2().getCoord().getX();
      _vertices[index+4] = getTriangles()[i].getVertex2().getCoord().getY();
      _vertices[index+5] = getTriangles()[i].getVertex2().getCoord().getZ();

      _vertices[index+6] = getTriangles()[i].getVertex3().getCoord().getX();
      _vertices[index+7] = getTriangles()[i].getVertex3().getCoord().getY();
      _vertices[index+8] = getTriangles()[i].getVertex3().getCoord().getZ();

      index+=9;
      }

  return _vertices;
}

const unsigned int& Mesh::getCountTriangles()
{
  return _countTriangles;
}
