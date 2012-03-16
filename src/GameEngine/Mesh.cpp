#include "Mesh.h"

Mesh::Mesh(Triangle triangles[], unsigned int &countTriangles)
{
  _countTriangles = countTriangles;
  _triangles = new Triangle[countTriangles];
  for(unsigned int i(0); i < countTriangles; i++)
    {
      _triangles[i] = triangles[i];
    }
}

Mesh::Mesh(std::vector<Triangle>& triangles)
{
  _countTriangles = triangles.size();
  _triangles = new Triangle[_countTriangles];
  for(unsigned int i(0); i < _countTriangles; i++)
    {
      _triangles[i] = triangles[i];
    }
}

Mesh::~Mesh()
{
  delete[] _triangles;
  delete[] _vertices;
}

//GET

Triangle* Mesh::getTriangles()
{
    return _triangles;
}

const float* Mesh::getVertices()
{
  _vertices = new float[_countTriangles*3];
  unsigned int index(0);

  for(unsigned int i(0); i < _countTriangles; i++)
    {
      _vertices[index] = getTriangles()[i].getVertex1().getVertexCoords().getX();
      _vertices[index+1] = getTriangles()[i].getVertex1().getVertexCoords().getY();
      _vertices[index+2] = getTriangles()[i].getVertex1().getVertexCoords().getZ();

      _vertices[index+3] = getTriangles()[i].getVertex2().getVertexCoords().getX();
      _vertices[index+4] = getTriangles()[i].getVertex2().getVertexCoords().getY();
      _vertices[index+5] = getTriangles()[i].getVertex2().getVertexCoords().getZ();

      _vertices[index+6] = getTriangles()[i].getVertex3().getVertexCoords().getX();
      _vertices[index+7] = getTriangles()[i].getVertex3().getVertexCoords().getY();
      _vertices[index+8] = getTriangles()[i].getVertex3().getVertexCoords().getZ();

      index+=9;
    }

  return _vertices;
}

const unsigned int& Mesh::getCountTriangles()
{
  return _countTriangles;
}
